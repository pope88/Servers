#ifndef _ROOMMANAGER_H_
#define _ROOMMANAGER_H_
#include "GameRoom.h"

class RoomManager
{
public:
	RoomManager();
	~RoomManager();
private:
	std::vector<PlayerManager*> _vecPlayers;
	std::vector<GameRoom*> _vecTableManager;

};
#endif