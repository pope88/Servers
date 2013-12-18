/************************************************************************/
// login server frame                                                              
/************************************************************************/
extern "C"
{
//#include <libtaomee/log.h>
//#include <libtaomee/conf_parser/config.h>
//#include <libtaomee/timer.h>
#include <async_serv/net_if.h>
#include <async_serv/dll.h>
}

#include "Packet/Processor.h"

/**
*Asever need this interface
*/
extern "C" int init_service(int isparent)
{
	return 0;
}

/**
*Asever need this interface
*/
extern "C" int fini_service(int isparent)
{
	return 0;
}

/**
*Asever need this interface
*/
extern "C" void proc_events()
{
	
}

/**
*Asever needed
*/
extern "C" int get_pkg_len(int fd, const void *avail_data, int avail_len, int isparent)
{
	return Packet::_processor.getPakcetLen(fd, avail_data, avail_len, isparent);
}

/**
*Asever needed
*/
extern "C" int proc_pkg_from_client(void* data, int len, fdsession_t* fdsess)
{
	return Packet::_processor.parseConn(data, fdsess);
}

/**
*Asever needed
*/
extern "C" void proc_pkg_from_serv(int fd, void* data, int len)
{
}

/**
*Asever needed
*/
extern "C" void on_client_conn_closed(int fd)
{
}

/**
*Asever needed
*/
extern "C" void on_fd_closed(int fd)
{

}