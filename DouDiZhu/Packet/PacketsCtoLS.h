#ifndef _SSU_PACKETSCTOLS_H_
#define _SSU_PACKETSCTOLS_H_

#include "SsuObject.h"

namespace game {
namespace net {
namespace data {
namespace CtoLS {

class CLSUserLogout_0xFFFF: public ::ssu::Object
{
public:
  virtual ~CLSUserLogout_0xFFFF() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;


};

class CLSGatewayConnect_0xFFF0: public ::ssu::Object
{
public:
  inline CLSGatewayConnect_0xFFF0(): _sessionId(0) { }

  virtual ~CLSGatewayConnect_0xFFF0() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int sessionId() const { return _sessionId; }
  inline void setSessionId(unsigned int val__) { _sessionId = val__; }

protected:
  unsigned int _sessionId;

};

class CLSBackendCommand_0xE000: public ::ssu::Object
{
public:
  virtual ~CLSBackendCommand_0xE000();
public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline const std::string& players(size_t index__) const { return *_players[index__]; }
  inline std::string * newPlayers() { return new(std::nothrow) std::string; }
  inline void addPlayers(const std::string& val__) { std::string * val2__ = new(std::nothrow) std::string(val__); if(val2__ == NULL) return; _players.add(val2__); }
  inline void addPlayers(const char * val__) { std::string * val2__ = new(std::nothrow) std::string(val__); if(val2__ == NULL) return; _players.add(val2__); }
  inline void addPlayers(const char * val__, size_t size__) { std::string * val2__ = new(std::nothrow) std::string(val__, size__); if(val2__ == NULL) return; _players.add(val2__); }
  inline void setPlayers(size_t index__, const std::string& val__) { _players[index__]->assign(val__); }
  inline void setPlayers(size_t index__, const char * val__) { _players[index__]->assign(val__); }
  inline void setPlayers(size_t index__, const char * val__, size_t size__) { _players[index__]->assign(val__, size__); }
  inline std::string& mutablePlayers(size_t index__) const { return *_players[index__]; }
  inline ::ssu::RepeatedObject<std::string *>& mutablePlayers() { return _players; }
  inline size_t playersSize() const { return _players.size(); }
  inline void clearPlayers() { for(::ssu::RepeatedObject<std::string *>::iterator iter = _players.begin(); iter != _players.end(); ++ iter) { delete *iter; } _players.clear(); }
  inline void reservePlayers(size_t size__) { if(_players.size() < size__) _players.reserve(size__); }

  inline const std::string& commands(size_t index__) const { return *_commands[index__]; }
  inline std::string * newCommands() { return new(std::nothrow) std::string; }
  inline void addCommands(const std::string& val__) { std::string * val2__ = new(std::nothrow) std::string(val__); if(val2__ == NULL) return; _commands.add(val2__); }
  inline void addCommands(const char * val__) { std::string * val2__ = new(std::nothrow) std::string(val__); if(val2__ == NULL) return; _commands.add(val2__); }
  inline void addCommands(const char * val__, size_t size__) { std::string * val2__ = new(std::nothrow) std::string(val__, size__); if(val2__ == NULL) return; _commands.add(val2__); }
  inline void setCommands(size_t index__, const std::string& val__) { _commands[index__]->assign(val__); }
  inline void setCommands(size_t index__, const char * val__) { _commands[index__]->assign(val__); }
  inline void setCommands(size_t index__, const char * val__, size_t size__) { _commands[index__]->assign(val__, size__); }
  inline std::string& mutableCommands(size_t index__) const { return *_commands[index__]; }
  inline ::ssu::RepeatedObject<std::string *>& mutableCommands() { return _commands; }
  inline size_t commandsSize() const { return _commands.size(); }
  inline void clearCommands() { for(::ssu::RepeatedObject<std::string *>::iterator iter = _commands.begin(); iter != _commands.end(); ++ iter) { delete *iter; } _commands.clear(); }
  inline void reserveCommands(size_t size__) { if(_commands.size() < size__) _commands.reserve(size__); }

protected:
  ::ssu::RepeatedObject<std::string *> _players;
  ::ssu::RepeatedObject<std::string *> _commands;

};

}
}
}
}

#endif // _SSU_PACKETSCTOLS_H_
