#include "PacketsCtoLS.h"

namespace game {
namespace net {
namespace data {
namespace CtoLS {

unsigned char * CLSUserLogout_0xFFFF::packBuffer(unsigned char * buf)
{
  return buf;
}

bool CLSUserLogout_0xFFFF::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  return true;
}

size_t CLSUserLogout_0xFFFF::size() const
{
  return 0;
}

unsigned char * CLSGatewayConnect_0xFFF0::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _sessionId);
  return buf;
}

bool CLSGatewayConnect_0xFFF0::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _sessionId)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t CLSGatewayConnect_0xFFF0::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_sessionId);
}

CLSBackendCommand_0xE000::~CLSBackendCommand_0xE000()
{
  for(::ssu::RepeatedObject<std::string *>::iterator iter = _players.begin(); iter != _players.end(); ++ iter) { delete *iter; }
  for(::ssu::RepeatedObject<std::string *>::iterator iter = _commands.begin(); iter != _commands.end(); ++ iter) { delete *iter; }
}

unsigned char * CLSBackendCommand_0xE000::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packRepeatedTag(buf, 1, _players, ::ssu::Utils::packStringPtrTag);
  buf = ::ssu::Utils::packRepeatedTag(buf, 2, _commands, ::ssu::Utils::packStringPtrTag);
  return buf;
}

bool CLSBackendCommand_0xE000::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 2 || !::ssu::Utils::unpackRepeated(buf, leftSize, _players, ::ssu::Utils::unpackStringPtr)) return false;
      break;
    case 2:
      if(type_ != 2 || !::ssu::Utils::unpackRepeated(buf, leftSize, _commands, ::ssu::Utils::unpackStringPtr)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t CLSBackendCommand_0xE000::size() const
{
  return 1 * _players.size() + ::ssu::Utils::sizeRepeated(_players, ::ssu::Utils::sizeStringPtr) + 1 * _commands.size() + ::ssu::Utils::sizeRepeated(_commands, ::ssu::Utils::sizeStringPtr);
}

}
}
}
}
