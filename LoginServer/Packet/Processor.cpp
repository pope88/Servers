#include "Config.h"
#include "Processor.h"
//#include "PlayerManager.h"
#include "../Object/Server.h"
#include "Handler.h"

extern "C"
{
	#include <libtaomee/log.h>
}

namespace Packet
{

Processor _processor;

void decryptPacket(UInt32 key, UInt16& op, UInt32 size, UInt8 * buf)
{

}

Processor::Processor()
{

}

int Processor::parseInit(void *buffer, fdsession_t *fdsession)
{
	return 0;
}

int parsePlayer(void *buffer, Object::Player *player)
{
	return 0;
}

int Processor::parseServer(void *buffer, int len, int fd)
{
	return 0;
}

int Processor::getPakcetLen(int fd, const void* availData, int availLen, int isParent)
{
	if (availLen < 6)
	{
		return 0;
	}

#pragma pack(push, 1)
	struct PktHdr
	{
		UInt32 size;
		UInt16 op;
	}ATTR_PACKED();
#pragma pack(pop)

	if (isParent > 0)
	{
		const PktHdr *hdr = reinterpret_cast<const PktHdr*>(availData); 
		UInt32 sz = hdr->size & 0x00FFFFFF;
		//UInt32 key = hdr->size >> 24;

		if (static_cast<int>(sz) + 6 > availLen)
		{
			return -1;
		}
		return availLen;
	}
	else
	{

	}
	return 0;

}
int Processor::process(void *buffer, fdsession_t *fdsession)
{
	DEBUG_LOG("fdsession_t---fd--%u", fdsession->fd);
	DEBUG_LOG("fdsession_t---id--%u", fdsession->id);
	DEBUG_LOG("fdsession_t---remoteip--%u", fdsession->remote_ip);
	DEBUG_LOG("fdsession_t---port--%u", fdsession->remote_port);
#pragma pack(push, 1)
	struct PktHdr
	{
		UInt32 size;
		UInt16 op;
	}ATTR_PACKED();
#pragma pack(pop)
	PktHdr *hdr = reinterpret_cast<PktHdr*>(buffer); 
	UInt32 sz = hdr->size & 0x00FFFFFF;
	UInt32 key = hdr->size >> 24;

	DEBUG_LOG("hdr->size---hdr->size--%u", hdr->size);
	DEBUG_LOG("sz---sz--%u", sz);
	DEBUG_LOG("key---key--%u", key);

	HandlerMsgInit *msg = (HandlerMsgInit*)malloc(sz + sizeof(HandlerMsgInit));
	DEBUG_LOG("xxxxx--xxx--%u", 98);
	if (msg == NULL)
	{
		return -1;
	}
	msg->hdr.size = sz;
	msg->sessionId = fdsession->fd;
	msg->remoteAddr = fdsession->remote_ip;

	UInt8 *buf = ((UInt8*)msg) + sizeof(HandlerMsgInit);
	memcpy(buf, (UInt8*)buffer+sizeof(PktHdr), sz);
	UInt16 op = hdr->op;
	decryptPacket(key, op, sz, buf);
	DEBUG_LOG("xxxxx--xxx--%u", 111);
	DEBUG_LOG("op--xxx--%u", op);
	
	DEBUG_LOG("xxxxx--xxx--%u", 113);
	if (op > _initHandlers.size())
	{
	    DEBUG_LOG("xxxxx--xxx--%u", 117);
		free(msg);
		return -1;
	}
	Handler *hdl = _initHandlers[op];
	if (hdl == NULL)
	{
		DEBUG_LOG("xxxxx--xxx--%u", 123);
		free(msg);
		return -1;
	}
	
	msg->hdr.handler = hdl;
	DEBUG_LOG("xxxxx--xxx--%u", 129);
	((HandlerMsgHeader*)msg)->handler->handle((HandlerMsgHeader*)msg);
	DEBUG_LOG("xxxxx--xxx--%u", 131);
	free(msg);
	return 0;
}

}