#include "Config.h"
#include "Server.h"

namespace Object
{
	bool Server::addPlayer(Player *player)
	{
		return _manager.addPlayer(player);
	}


}