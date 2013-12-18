#ifndef _PLAYERMANAGER_H_
#define _PLAYERMANAGER_H_
#include "UserSession.h"
class PlayerManager
{
public:
	PlayerManager() {}
	~PlayerManager() {}
	bool insertPlayer(UserSession* player) { return true; }
	bool removePlayer(UserSession *player) { return true; }
	UserSession* findPlayer(UInt32 pid) { return NULL; }
	//void broadcastRoom(Packet::Builder& builder, UserSession *pExceptPlayer = NULL);
	UInt32 getPlayerNum() { return _roomPlayers.size(); }
private:
	UInt32 _roomId;
	std::unordered_map<UInt32, UserSession*> _roomPlayers; 
};
#endif