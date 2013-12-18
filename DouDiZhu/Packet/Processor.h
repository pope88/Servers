#ifndef  _PROCESSOR_H_
#define  _PROCESSOR_H_

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
		int process(void *buffer, fdsession_t *fdsession);
	private:
		std::vector<Handler *> _initHandlers;
		std::vector<Handler *> _playerHandlers;
	};
	extern Processor _processor;
}
#endif