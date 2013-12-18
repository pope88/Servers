#ifndef _SSU_PACKETSLSTOC_H_
#define _SSU_PACKETSLSTOC_H_

#include "SsuObject.h"

namespace game {
namespace net {
namespace data {
namespace LStoC {

class LSCCUserDataChangeUp_0xFFF1: public ::ssu::Object
{
public:
  inline LSCCUserDataChangeUp_0xFFF1(): _level(0), _oldLevel(0) { }

  virtual ~LSCCUserDataChangeUp_0xFFF1() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int level() const { return _level; }
  inline void setLevel(unsigned int val__) { _level = val__; }

  inline unsigned int oldLevel() const { return _oldLevel; }
  inline void setOldLevel(unsigned int val__) { _oldLevel = val__; }

protected:
  unsigned int _level;
  unsigned int _oldLevel;

};

class LSCCPackChange_0xFFF2: public ::ssu::Object
{
public:
  inline LSCCPackChange_0xFFF2(): _topType(0) { }

  virtual ~LSCCPackChange_0xFFF2() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int topType() const { return _topType; }
  inline void setTopType(unsigned int val__) { _topType = val__; }

protected:
  unsigned int _topType;

};

class LSCCHeroEqChange_0xFFF3: public ::ssu::Object
{
public:
  inline LSCCHeroEqChange_0xFFF3(): _uuid(0) { }

  virtual ~LSCCHeroEqChange_0xFFF3() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int uuid() const { return _uuid; }
  inline void setUuid(unsigned int val__) { _uuid = val__; }

protected:
  unsigned int _uuid;

};

class LSCCTeamChange_0xFFF4: public ::ssu::Object
{
public:
  inline LSCCTeamChange_0xFFF4(): _uuid(0), _type(0) { }

  virtual ~LSCCTeamChange_0xFFF4() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int uuid() const { return _uuid; }
  inline void setUuid(unsigned int val__) { _uuid = val__; }

  inline unsigned int type() const { return _type; }
  inline void setType(unsigned int val__) { _type = val__; }

protected:
  unsigned int _uuid;
  unsigned int _type;

};

class LSCCHeroPanelOpen_0xFFF5: public ::ssu::Object
{
public:
  inline LSCCHeroPanelOpen_0xFFF5(): _status(false) { }

  virtual ~LSCCHeroPanelOpen_0xFFF5() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline bool status() const { return _status; }
  inline void setStatus(bool val__) { _status = val__; }

protected:
  bool _status;

};

class LSCCHeroLevelUp_0xFFF6: public ::ssu::Object
{
public:
  inline LSCCHeroLevelUp_0xFFF6(): _heroId(0), _level(0), _oldLevel(0) { }

  virtual ~LSCCHeroLevelUp_0xFFF6() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int heroId() const { return _heroId; }
  inline void setHeroId(unsigned int val__) { _heroId = val__; }

  inline unsigned int level() const { return _level; }
  inline void setLevel(unsigned int val__) { _level = val__; }

  inline unsigned int oldLevel() const { return _oldLevel; }
  inline void setOldLevel(unsigned int val__) { _oldLevel = val__; }

protected:
  unsigned int _heroId;
  unsigned int _level;
  unsigned int _oldLevel;

};

class LSCCVIPLevelChange_0xFFF7: public ::ssu::Object
{
public:
  inline LSCCVIPLevelChange_0xFFF7(): _level(0), _oldLevel(0) { }

  virtual ~LSCCVIPLevelChange_0xFFF7() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int level() const { return _level; }
  inline void setLevel(unsigned int val__) { _level = val__; }

  inline unsigned int oldLevel() const { return _oldLevel; }
  inline void setOldLevel(unsigned int val__) { _oldLevel = val__; }

protected:
  unsigned int _level;
  unsigned int _oldLevel;

};

class LSCSendItemToChat_0xFFF8: public ::ssu::Object
{
public:
  inline LSCSendItemToChat_0xFFF8(): _id(0), _color(0) { }

  virtual ~LSCSendItemToChat_0xFFF8() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;

public:
  inline unsigned int id() const { return _id; }
  inline void setId(unsigned int val__) { _id = val__; }

  inline const std::string& name() const { return _name; }
  inline void setName(const std::string& val__) { _name = val__; }
  inline std::string& mutableName() { return _name; }

  inline unsigned int color() const { return _color; }
  inline void setColor(unsigned int val__) { _color = val__; }

protected:
  unsigned int _id;
  std::string _name;
  unsigned int _color;

};

class LSCCSendDemonToMassage_0xFFF9: public ::ssu::Object
{
public:
  virtual ~LSCCSendDemonToMassage_0xFFF9() { }

public:
  virtual unsigned char * packBuffer(unsigned char * buf);
  virtual bool unpackBuffer(const unsigned char *& buf, size_t& leftSize);
  virtual size_t size() const;


};

}
}
}
}

#endif // _SSU_PACKETSLSTOC_H_
