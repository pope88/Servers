#include "Config.h"
#include "GameTimer.h"

UInt8 GameTimer::TimerMax = 10;

GameTimer::GameTimer()
{
	_timers.resize(TimerMax);
}

//void GameTimer::addPresetTimer( int typeId, void * key, UInt32 firstInterval )
//{
//	addPresetTimer(Data::timerData[typeId], key, firstInterval);
//}

bool GameTimer::addTimer(int typeId, void *key, UInt32 interval, bool once, UInt32 param , UInt8 wd)
{
	if (_timers[typeId].find(key) != _timers[typeId].end())
		return false;
	TimerInfo &td = _timers[typeId][key];
	td.typeId = typeId;
	td.key = key;
	td.param = param;
	td.wd = wd;
	if (once)
	{
		td.data = add(interval, &td, 1);
	}
	else
	{
		td.data = add(interval, &td);
	}

	if (td.data == NULL)
	{
		_timers[typeId].erase(key);
		return false;
	}
	return true;
}

bool GameTimer::addTimerWithFirst( int typeId, void * key, UInt32 interval, UInt32 firstInterval, UInt32 param, UInt8 wd )
{
	if(_timers[typeId].find(key) != _timers[typeId].end())
		return false;
	TimerInfo& td = _timers[typeId][key];
	td.typeId = typeId;
	td.key = key;
	td.param = param;
	td.data = add(interval, firstInterval, &td);
	td.wd = wd;
	if(td.data == NULL)
	{
		_timers[typeId].erase(key);
		return false;
	}
	return true;
}

void GameTimer::removeTimer(int typeId, void *key)
{
	std::unordered_map<void*, TimerInfo>::iterator it = _timers[typeId].find(key);
	if (it == _timers[typeId].end())
	{
		return;
	}
	remove(it->second.data);
	_timers[typeId].erase(it);
}

void GameTimer::onTickCheck()
{
	process();
}
