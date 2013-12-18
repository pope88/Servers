#ifndef  _PROCESSOR_H_
#define  _PROCESSOR_H_

#include "PlayerManager.h"
extern "C"
{
	#include <async_serv/net_if.h>
}

namespace Object
{
	class Player;
}


namespace Packet
{
	enum 
	{
		/* version no*/
		ver = 1,
		/*SERVER and CLIENT proto max len */
		maxProtoLen = 32 * 1024,
	};

	class Handler;
	class Processor
	{
	public:
		Processor();
	
	public:
		int parseInit(void *buffer, fdsession_t *fdsession);
		int parsePlayer(void *buffer, Object::Player *player);
		int parseServer(void *buffer, int len, int fd);
		int getPakcetLen(int fd, const void* availData, int availLen, int isParent);

		
		//int doProcessConn(const UInt8 *buffer, UInt16 op, UInt32 sz, fdsession_t *fdsession);
		int doProcessInit(fdsession_t *fdsession, UInt16 op, UInt32 sz, const UInt8 *buf);
		int doProcessPlayer();
		int doProcessServer();
	private:
		std::vector<Handler *> _initHandlers;
		std::vector<Handler *> _playerHandlers;
	private:
		Object::PlayerManager _serverMan; 
	};
	extern Processor _processor;
}
#endif
