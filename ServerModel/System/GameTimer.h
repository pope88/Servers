#ifndef _GAMETIMER_H_
#define _GAMETIMER_H_
#include "../System/Timer.h"

class GameTimer: protected System::Timer
{
private:
	struct TimerInfo 
	{
		int typeId;
		UInt32 param;
		void *key;
		void *data;
		UInt8 wd;
	};
public:
	inline GameTimer();
	void init();
	void onTickCheck();
	//void addPresetTimer(int typeId, void *key, UInt32 firstInterval);
private:
	bool addTimer(int, void *, UInt32, bool = false, UInt32 = 0, UInt8 wd = 0);
	bool addTimerWithFirst( int typeId, void * key, UInt32 interval, UInt32 firstInterval, UInt32 param, UInt8 wd );
	void removeTimer(int typeId, void *key);
private:
	std::vector<std::unordered_map<void*, TimerInfo> > _timers;
	static UInt8 TimerMax;
};
#endif