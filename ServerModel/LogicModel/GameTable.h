#ifndef _GAMETABLE_H_
#define _GAMETABLE_H_
#include "../Model/Mplayer.h"
#include "../Model/Mtable.h"
class GameTable: public Mtable
{
public:
	enum
	{
		T_EMPTY,
		T_WATING,
		T_RACING,
	};
public:
	//GameTable(UInt8 tableId, PlayerMananger* playerManager) {}
	GameTable(UInt8 tableId) {}
	virtual ~GameTable() {}
public:
	virtual void onTimer() {}
	virtual void onGameStart() {}
	virtual void onGameEnd() {}
	virtual void onUserForceLeave(Mplayer *p) {}
	virtual void onUserDisconnection(Mplayer *p) {}
	virtual void onUserverReconnection(Mplayer *p) {}
	virtual void onUserJoinTable(Mplayer *p) {}
	virtual void onUserLeaveTable(Mplayer *p) {}
	virtual bool canJoinGame(Mplayer *p) { return true; }
public:
	virtual int getGameType() { return 0;}
	virtual int getCurPlayerNum() { return 0;}
	virtual Mplayer* getTablePlayer(int nChairId) { return NULL; }
	virtual void setTimer() {}
	virtual void removeTimer() {}
	virtual void ChangePlayerMoney(Mplayer *p, int nMoney) {}
	virtual void setBaseSore(int nBaseCore) {}
};
#endif