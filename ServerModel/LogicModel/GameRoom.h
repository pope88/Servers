#ifndef _TABLEMANAGER_H_
#define _TABLEMANAGER_H_
#include "GameTable.h"
#include "PlayerManager.h"
class GameTable;
class GameRoom
{
public:
	GameRoom(UInt8) {}
	~GameRoom() {}
	GameTable* findTable(UInt32 tid) { return NULL; }
	GameTable* searchTable(UInt8 &nChair, const std::string &strIp) { return NULL; }
	void breakAllGame() {}
	GameTable* findEmptyTable(UInt32 &nChair) { return NULL; }
	GameTable* findWaitingTable(UInt32 &nChair) { return NULL; }
private:
	UInt8  _roomId;
	UInt32 _maxTableNum;
	std::vector<GameTable*> _arrGameTable;
};
#endif