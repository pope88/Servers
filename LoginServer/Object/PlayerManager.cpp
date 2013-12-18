#include "Config.h"
#include "PlayerManager.h"
namespace Object
{
PlayerManager playerManager;
<<<<<<< HEAD
void PlayerManager::addPlayer(Player *player)
{
=======
>>>>>>> origin/master

Player* PlayerManager::operator[](UInt32 fd)
{
	std::unordered_map<UInt32, Player*>::iterator it = _playersSid.find(fd);
	if (it == _playersSid.end())
	{
		return NULL;
	}
	else
	{
		return it->second;
	}
}

<<<<<<< HEAD
void PlayerManager::delPlayer(Player *player)
=======
bool PlayerManager::addPlayer(Player *player)
>>>>>>> origin/master
{
	if (player == NULL)
	{
		return false;
	}
	Player *& pl = _playersSid[player->fd()];
	if (pl != NULL)
	{
		pl->disconnect();
		_players.erase(pl);
		delete pl;
	}
	pl = player;
	_players.insert(pl);
	return true;
}

void PlayerManager::delPlayer(Player *player)
{
	if (player == NULL)
	{
		return;
	}
	_players.erase(player);
	_playersSid.erase(player->fd());
}



}