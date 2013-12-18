#include "Config.h"
#include "Player.h"
#include "Server.h"
namespace Object
{
bool Player::updateKey(UInt32 key)
{
	if(key < 2) return false;
	if(_key == 0) { _key = key; return true; }
	UInt32 nkey = ((((_key - 2) * 33721) % 65537) % 251) + 2;
	if(key != nkey) return false;
	_key = key;
	return true;
}

void Player::disconnect()
{
	_server->disconnect();
}

void Player::process()
{

}

}