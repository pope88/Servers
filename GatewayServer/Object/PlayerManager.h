#ifndef _PLAYERMANAGER_H_
#define _PLAYERMANAGER_H_
#include "Player.h"
namespace Object
{
	class PlayerManager
	{
	public:
		inline PlayerManager(): _playersSid(256), _players(256) {}
		virtual ~PlayerManager(){}
	public:
		Player *operator[](UInt32 fd);
		inline bool empty() { return _players.empty(); }
		bool addPlayer(Player *player);
		void delPlayer(Player *player);
		
		template<class CB>
		void foreach(CB cb)
		{
			for (std::unordered_set<Player*>::iterator it; it != _players.end(); ++it)
			{
				if (!cb(*it))
				{
					return;
				}
			}
		}
	private:
		std::unordered_map<UInt32, Player*> _playersSid;
		std::unordered_set<Player*> _players;
	};
	extern PlayerManager playerManager;
}


#endif