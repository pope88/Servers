#ifndef _USERSESSION_H_
#define _USERSESSION_H_
#include "../Model/Mplayer.h"
#include "../Model/MSession.h"
#include "GameTable.h"
class GameRoom;
class UserSession :public MSession, public Mplayer
{
public:
	enum LOGIN_STATUS
	{
		LOAD_FAILD = (1 << 0),
		LOAD_INFO = (1 << 1),
		//		LOAD_PAY = (1 << 2),
		LOAD_GAME = (1 << 3),
		LOAD_NOLOGIN = (1 << 4),	//�ʺű�����
		LOAD_FROZEN = (1 << 5),		//��Ϸ�ұ�����
		LOAD_NOSIGN = (1 << 6),		//û�б���
		LOAD_VERIFYFAILD = (1 << 7),//�������
		LOAD_SUCCESS = (LOAD_INFO | LOAD_GAME),
	};
public:
	enum USER_STATUS
	{
		US_UNCONNECTED,		///< 0	δ����
		US_CONNECTED,		///< 1	���ӳɹ�
		US_LOBBY,			///< 2	��¼�ɹ�
		US_TABLE,			///< 3	��ҽ��뷿��
		US_VISITOR,			///< 4	�Թ۽��뷿��
		US_READY,			///< 5	����
		US_RACING,			///< 6	������
		US_BROKEN,			///< 7	������
	};
public:
	UserSession();
	~UserSession();
public:
	//session
	virtual void onConnnection() {}
	virtual void setConnection() {}
	virtual void onDisConnect() {}
	virtual void onDisConnection() {}
	virtual void onRecv(const UInt8 *pData, int nLen) {}
	virtual void release() {}
	virtual void onRecvFrom(struct sockaddr* remoteaddr, const UInt8 *pData, int nLen) {}

	//mplayer
	virtual int getTableId() { return 0; }
	virtual int getChairId() { return 0; }
	virtual int getGameMoney() { return 0; }
	virtual bool saveGameScore(int score) { return true; }
	virtual bool SaveGameMoney(int money) { return true; }
	virtual bool canWatch() { return true; }

	//db

	//base control
	const int getPid() { return 0; }
	void setTableInfo(GameTable pTable, int chiarid) {}
	inline int getStatus() { return 0; }
	void setStaus(int status) {}
	inline int getRoomId() { return 0; }

	int changeMoney(int money) { return 0; }
	inline int getLimitScore() { return 0; }

	//logic 
	bool onStartGame() { return true; }
	GameRoom* getTableManager() { return NULL; }
	void onHeartBit() {}
	void getNetDelay() {}
	const std::string& getPlayerIp() { 	static std::string empty; return empty; }
	const GameTable* getTheTable() { return NULL; }
	void setPlayerStatus(UInt16 status) {}

	//net

private:
	GameTable *_mpTable;
	UInt8 _roomID;
	UInt32 _sessionId;
	UInt32 _gatewayId;
	UInt32 _remoteAddr;
};
#endif