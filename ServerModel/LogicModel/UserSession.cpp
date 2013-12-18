#include "Config.h"
#include "UserSession.h"
#include "GameRoom.h"
UserSession::UserSession():_mpTable(NULL), _roomID(0), _sessionId(0), _gatewayId(0), _remoteAddr(0)
{
}

UserSession::~UserSession()
{

}