#ifndef _HANDLER_H_
#define _HANDLER_H_

namespace Packet
{
	namespace Object
	{
		class Player;
	}

	class Handler;
	struct HandlerMsgHeader
	{
		Handler *handler;
		UInt32 size;
	};

	struct HandlerMsgPlayer
	{
		HandlerMsgHeader hdr;
		union
		{
			Object::Player *player;
			struct  
			{
				UInt32 playerId;
				UInt16 op;
			} gateway;
		};
	};

	struct HandlerMsgInit
	{
		HandlerMsgHeader hdr; 
		UInt32 sessionId;
		UInt32 remoteAddr;
	};

	class Handler
	{
	public:
		inline Handler() {}
		Handler( UInt16 op, UInt8 type );
		virtual void handle(HandlerMsgHeader *) = 0;
	};

	template<class T, class DT, UInt16 HOP, UInt8 TF=1>
	class HandlerT: public Handler
	{
	public:
		HandlerT<T, DT, HOP, TF>():Handler(HOP, TF) {}
	protected:
		virtual void handle(HandlerMsgHeader *hdr)
		{
			DT pktObj;
			if (pktObj.unpack((UInt8*)hdr + static_cast<T *>(this)->getDataBufferSize(), hdr->size) )
			{
				static_cast<T *>(this)->process(pktObj, hdr);
			}
		}
	};

}

#define HANDLER_CLASS_PLAYER(n, o) \
namespace Packet{ \
class Handler##n : public HandlerT<Handler##n, CLS##n##_##o, o> \
{ \
public: \
	inline size_t getDataBufferSize() { return sizeof(HandlerMsgInit); } \
	inline void process( CLS##n##_##o, HandlerMsgHeader *hdr) \
    { \
	   Object::Player  *player = ((HandlerMsgPlayer*)hdr)->player; \
       if (player == NULL) \
       {\
		   return; \
       } \

#define HANDLER_CLASS_INIT(n, o) \
namespace Packet { \
	class Handler##n: public HandlerT<Handler##n, CLS##n##_##o, o, 2> \
	{ \
	public: \
		inline size_t getDataBufferSize() { return sizeof(HandlerMsgInit); } \
		inline void process(CLS##n##_##o& pkt, HandlerMsgHeader * hdr) \
		{ \
			HandlerMsgInit * msgInit__ = (HandlerMsgInit *)hdr; \
			UInt32 sessionId = msgInit__->sessionId; \
			UInt32 gatewayId = msgInit__->fromGateway; \
			UInt32 remoteAddr = msgInit__->remoteAddr; \

#define MSG_QUERY_ARGS(at, av)

#define HANDLER_END(n) \
		} \
	}; \
	static Handler##n __static_initializer_##n; \
}

#endif // _HANDLER_H_
