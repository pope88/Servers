#include "PacketsLStoC.h"

namespace game {
namespace net {
namespace data {
namespace LStoC {

unsigned char * LSCCUserDataChangeUp_0xFFF1::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _level);
  buf = ::ssu::Utils::packUInt32Tag(buf, 2, _oldLevel);
  return buf;
}

bool LSCCUserDataChangeUp_0xFFF1::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _level)) return false;
      break;
    case 2:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _oldLevel)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCCUserDataChangeUp_0xFFF1::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_level) + 1 + ::ssu::Utils::sizeUInt32(_oldLevel);
}

unsigned char * LSCCPackChange_0xFFF2::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _topType);
  return buf;
}

bool LSCCPackChange_0xFFF2::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _topType)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCCPackChange_0xFFF2::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_topType);
}

unsigned char * LSCCHeroEqChange_0xFFF3::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _uuid);
  return buf;
}

bool LSCCHeroEqChange_0xFFF3::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _uuid)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCCHeroEqChange_0xFFF3::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_uuid);
}

unsigned char * LSCCTeamChange_0xFFF4::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _uuid);
  buf = ::ssu::Utils::packUInt32Tag(buf, 2, _type);
  return buf;
}

bool LSCCTeamChange_0xFFF4::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _uuid)) return false;
      break;
    case 2:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _type)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCCTeamChange_0xFFF4::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_uuid) + 1 + ::ssu::Utils::sizeUInt32(_type);
}

unsigned char * LSCCHeroPanelOpen_0xFFF5::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packBoolTag(buf, 1, _status);
  return buf;
}

bool LSCCHeroPanelOpen_0xFFF5::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackBool(buf, leftSize, _status)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCCHeroPanelOpen_0xFFF5::size() const
{
  return 1 + ::ssu::Utils::sizeBool(_status);
}

unsigned char * LSCCHeroLevelUp_0xFFF6::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _heroId);
  buf = ::ssu::Utils::packUInt32Tag(buf, 2, _level);
  buf = ::ssu::Utils::packUInt32Tag(buf, 3, _oldLevel);
  return buf;
}

bool LSCCHeroLevelUp_0xFFF6::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _heroId)) return false;
      break;
    case 2:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _level)) return false;
      break;
    case 3:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _oldLevel)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCCHeroLevelUp_0xFFF6::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_heroId) + 1 + ::ssu::Utils::sizeUInt32(_level) + 1 + ::ssu::Utils::sizeUInt32(_oldLevel);
}

unsigned char * LSCCVIPLevelChange_0xFFF7::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _level);
  buf = ::ssu::Utils::packUInt32Tag(buf, 2, _oldLevel);
  return buf;
}

bool LSCCVIPLevelChange_0xFFF7::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _level)) return false;
      break;
    case 2:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _oldLevel)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCCVIPLevelChange_0xFFF7::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_level) + 1 + ::ssu::Utils::sizeUInt32(_oldLevel);
}

unsigned char * LSCSendItemToChat_0xFFF8::packBuffer(unsigned char * buf)
{
  buf = ::ssu::Utils::packUInt32Tag(buf, 1, _id);
  buf = ::ssu::Utils::packStringTag(buf, 2, _name);
  buf = ::ssu::Utils::packUInt32Tag(buf, 3, _color);
  return buf;
}

bool LSCSendItemToChat_0xFFF8::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  unsigned int tag_; unsigned char type_;
  while(leftSize > 0)
  {
    if(!::ssu::Utils::unpackTag(buf, leftSize, tag_, type_)) return false;
    switch(tag_)
    {
    case 1:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _id)) return false;
      break;
    case 2:
      if(type_ != 2 || !::ssu::Utils::unpackString(buf, leftSize, _name)) return false;
      break;
    case 3:
      if(type_ != 0 || !::ssu::Utils::unpackUInt32(buf, leftSize, _color)) return false;
      break;
    default: break;
    }
  }
  return true;
}

size_t LSCSendItemToChat_0xFFF8::size() const
{
  return 1 + ::ssu::Utils::sizeUInt32(_id) + 1 + ::ssu::Utils::sizeString(_name) + 1 + ::ssu::Utils::sizeUInt32(_color);
}

unsigned char * LSCCSendDemonToMassage_0xFFF9::packBuffer(unsigned char * buf)
{
  return buf;
}

bool LSCCSendDemonToMassage_0xFFF9::unpackBuffer(const unsigned char *& buf, size_t& leftSize)
{
  return true;
}

size_t LSCCSendDemonToMassage_0xFFF9::size() const
{
  return 0;
}

}
}
}
}
