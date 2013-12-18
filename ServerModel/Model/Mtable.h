#ifndef _MTABLE_H_
#define _MTABLE_H_
#include "Mplayer.h"
class Mtable
{
public:
	Mtable() {}
	virtual ~Mtable() {}
public:
	virtual void onTimer() = 0;
	virtual void onGameStart() = 0;
	virtual void onGameEnd() = 0;
	virtual void onUserForceLeave(Mplayer *p) = 0;
	virtual void onUserDisconnection(Mplayer *p) = 0;
	virtual void onUserverReconnection(Mplayer *p) = 0;
	virtual void onUserJoinTable(Mplayer *p) = 0;
	virtual void onUserLeaveTable(Mplayer *p) = 0;
	virtual bool canJoinGame(Mplayer *p) = 0;
public:
	virtual int getGameType() = 0;
	virtual int getCurPlayerNum() = 0;
	virtual Mplayer* getTablePlayer(int nChairId) = 0;
	virtual void setTimer() = 0;
	virtual void removeTimer() = 0;
	virtual void ChangePlayerMoney(Mplayer *p, int nMoney) = 0;
	virtual void setBaseSore(int nBaseCore) = 0;
};

#endif