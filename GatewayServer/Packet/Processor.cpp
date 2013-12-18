#include "Config.h"
#include "Processor.h"
//#include "PlayerManager.h"
#include "../Object/Server.h"
#include "Handler.h"

extern "C"
{
	#include <libtaomee/log.h>
}

namespace Packet
{

Processor _processor;

void decryptPacket(UInt32 key, UInt16& op, UInt32 size, UInt8 * buf)
{

}

Processor::Processor()
{

}


int parsePlayer(void *buffer, Object::Player *player)
{
	return 0;
}

int Processor::parseServer(void *buffer, int len, int fd)
{
	return 0;
}

int Processor::getPakcetLen(int fd, const void* availData, int availLen, int isParent)
{
	if (availLen < 6)
	{
		return 0;
	}

	UInt32 len = 0;
#pragma pack(push, 1)
	struct PktHdr
	{
		UInt32 size;
		UInt16 op;
	}ATTR_PACKED();
#pragma pack(pop)

	if (isParent > 0)
	{
		const PktHdr *hdr = reinterpret_cast<const PktHdr*>(availData); 
		len = hdr->size & 0x00FFFFFF;
		//UInt32 key = hdr->size >> 24;

		if (static_cast<int>(len) + 6 > availLen || static_cast<int>(len) + 6 > maxProtoLen)
		{
			return -1;
		}
	}
	else
	{
		const PktHdr *hdr = reinterpret_cast<const PktHdr*>(availData); 
		len = hdr->size & 0x00FFFFFF;
		//UInt32 key = hdr->size >> 24;

		if (static_cast<int>(len) + 6 > availLen || static_cast<int>(len) + 6 > maxProtoLen)
		{
			return -1;
		}
	}
	return len;

}
int Processor::parseInit(void *buffer, fdsession_t *fdsession)
{
	DEBUG_LOG("fdsession_t---fd--%u", fdsession->fd);
	DEBUG_LOG("fdsession_t---id--%u", fdsession->id);
	DEBUG_LOG("fdsession_t---remoteip--%u", fdsession->remote_ip);
	DEBUG_LOG("fdsession_t---port--%u", fdsession->remote_port);
#pragma pack(push, 1)
	struct PktHdr
	{
		UInt32 size;
		UInt16 op;
	}ATTR_PACKED();
#pragma pack(pop)
	PktHdr *hdr = reinterpret_cast<PktHdr*>(buffer); 
	UInt32 sz = hdr->size & 0x00FFFFFF;
	UInt32 key = hdr->size >> 24;

	UInt8 *buf = new(std::nothrow) UInt8[sz];
	if (buf == NULL)
	{
		return -1;
	}
	else
	{
		memcpy(buf, (UInt8*)buffer, sz);
		UInt16 op = hdr->op;
		//decryptPacket(key, op, sz, buf);
		doProcessInit(fdsession, op, sz, buf);
		delete[] buf;
	}
	return 0;
}

int doProcessInit(fdsession_t *fdsession, UInt16 op, UInt32 sz, const UInt8 *buf)
{
	switch (op)
	{
	case : 2
		   {
			   Packet::CSUserLogin_0x02 pkt;
			   const UInt8 * bufExt = buf;
			   size_t szExt = size;
			   if(!pkt.unpackBuffer(bufExt, szExt))
			   {
				   _tcp->disconnect(sid);
				   return;
			   }

			   size_t pos = pkt.id().find_last_of('@');
			   if (pos == std::string::npos)
			   {
				   sv = (*_serverMan)["soushentest_s1"];
			   }
			   else 
			   {
				   sv = (*_serverMan)[pkt.id().substr(pos+1)];
			   }
			   
			   if (sv == NULL)
			   {
				   close_client_conn(fdsession->fd);
				   return 1;
			   }
			   Object::Player *player = new(std::nothrow) Object::Player(sv, sid);
			   if (player == NULL)
			   {
				   close_client_conn(fdsession->fd);
				   return 1;
			   }
			   player->setPFDS(fdsession);
			   sv->addPlayer(player);
			   sv->pendPacket(sid, op | 0x8000, buf, size);
			   
		   }
		   break;

	}
	return 0;
}

}