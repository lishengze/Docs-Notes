// SocketInit.h: interface for the CSocketInit class.
//
// 20120409 江鹏   NT-0139 加快响应时间：增加通过广播地址得到网络地址的函数
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKETINIT_H__E7EE3B7E_1EEE_4E63_90CA_A773FF566013__INCLUDED_)
#define AFX_SOCKETINIT_H__E7EE3B7E_1EEE_4E63_90CA_A773FF566013__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#include <winsock.h>
#else
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#endif

//在非Windows系统，我们使用close来关闭一个socket，而在Windows下，我们使用closesocket
//这里，我们统一成closesocket
#ifdef UNIX
#define closesocket close
#endif

#ifdef VOS
#define closesocket net_close
#endif

//在非Windows系统，我们使用ioctl来设置一个socket，而在Windows下，我们使用ioctlsocket
//这里，我们统一成ioctlsocket
#ifdef UNIX
#define ioctlsocket ioctl
#endif

#ifdef VOS
#define ioctlsocket net_ioctl
#endif

//在Windows下，所有的socket的错误号全部以WSA开始，我们将需要的那些统一成Unix的标准
#ifdef WIN32
#define EWOULDBLOCK WSAEWOULDBLOCK
#endif

//在VOS下，所有的socket的错误号全部以e$开始，我们将需要的那些统一成Unix的标准

#ifdef VOS
#define EINTR e$tcp_interrupted_operation
#define EWOULDBLOCK e$caller_must_wait
#endif


//在Windows下，使用h_error来获取最近的socket错误，而在其他系统下，直接使用errno。
//我们同意成GET_LAST_SOCK_ERROR()
#ifdef WIN32
#define GET_LAST_SOCK_ERROR() h_errno
#else
#define GET_LAST_SOCK_ERROR() errno
#endif

//在传送sockaddr时，使用的表示长度的类型不同 gyd 20020605 将 UNIX变为LINUX
#if defined(LINUX)// || defined(HP_UX)
#define SOCKADDRLEN	socklen_t
//#define SOCKADDRLEN	unsigned
#else
#define SOCKADDRLEN	int
#endif

/**
对Socket的初始化
*/class CSocketInit  
{
public:
	CSocketInit();
	virtual ~CSocketInit();
};

//通过网络广播地址得到网卡地址
extern bool GetLocalAddress(int sock, const char* network, char* local);

#endif // !defined(AFX_SOCKETINIT_H__E7EE3B7E_1EEE_4E63_90CA_A773FF566013__INCLUDED_)
