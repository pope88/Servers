#ifndef _PLAYER_H_
#define _PLAYER_H_

extern "C"
{
#include <async_serv/net_if.h>
}

class Server;
namespace Object
{
	class Player
	{
	public:
		inline Player(Server *server, fdsession_t *pfds):_server(server), _pfdS(pfds), _key(0), _online(false) {}
		~Player() {}
		inline Server* server() { return _server; }
		inline void setPFDS(fdsession_t *pfds) { _pfdS = pfds; }
		inline UInt32 id() { return _pfdS->id; }
		inline UInt32 fd() { return _pfdS->fd; }
		inline UInt32 addr() { return _pfdS->remote_ip; }
		inline bool online() { return _online; }
		inline void setOnline( bool o) { _online = 0; }

	public:
		bool updateKey(UInt32 key);
		void disconnect();
		void process();
	private:
		Server *_server;
		fdsession_t* _pfdS;
		UInt32 _key;
		bool _online; 
	};
}
#endif
