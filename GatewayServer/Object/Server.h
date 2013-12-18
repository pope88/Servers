#ifndef _SERVER_H_
#define _SERVER_H_

namespace Object
{
	class Server
	{
	public:
		Server();
		~Server();
		bool addPlayer(Player *);
		void pendPacket();
	public:
		void disconnect() {}
	private:
		PlayerManager _manager;
	};

}

#endif