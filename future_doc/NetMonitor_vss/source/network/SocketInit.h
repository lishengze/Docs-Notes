// SocketInit.h: interface for the CSocketInit class.
//
// 20120409 ����   NT-0139 �ӿ���Ӧʱ�䣺����ͨ���㲥��ַ�õ������ַ�ĺ���
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

//�ڷ�Windowsϵͳ������ʹ��close���ر�һ��socket������Windows�£�����ʹ��closesocket
//�������ͳһ��closesocket
#ifdef UNIX
#define closesocket close
#endif

#ifdef VOS
#define closesocket net_close
#endif

//�ڷ�Windowsϵͳ������ʹ��ioctl������һ��socket������Windows�£�����ʹ��ioctlsocket
//�������ͳһ��ioctlsocket
#ifdef UNIX
#define ioctlsocket ioctl
#endif

#ifdef VOS
#define ioctlsocket net_ioctl
#endif

//��Windows�£����е�socket�Ĵ����ȫ����WSA��ʼ�����ǽ���Ҫ����Щͳһ��Unix�ı�׼
#ifdef WIN32
#define EWOULDBLOCK WSAEWOULDBLOCK
#endif

//��VOS�£����е�socket�Ĵ����ȫ����e$��ʼ�����ǽ���Ҫ����Щͳһ��Unix�ı�׼

#ifdef VOS
#define EINTR e$tcp_interrupted_operation
#define EWOULDBLOCK e$caller_must_wait
#endif


//��Windows�£�ʹ��h_error����ȡ�����socket���󣬶�������ϵͳ�£�ֱ��ʹ��errno��
//����ͬ���GET_LAST_SOCK_ERROR()
#ifdef WIN32
#define GET_LAST_SOCK_ERROR() h_errno
#else
#define GET_LAST_SOCK_ERROR() errno
#endif

//�ڴ���sockaddrʱ��ʹ�õı�ʾ���ȵ����Ͳ�ͬ gyd 20020605 �� UNIX��ΪLINUX
#if defined(LINUX)// || defined(HP_UX)
#define SOCKADDRLEN	socklen_t
//#define SOCKADDRLEN	unsigned
#else
#define SOCKADDRLEN	int
#endif

/**
��Socket�ĳ�ʼ��
*/class CSocketInit  
{
public:
	CSocketInit();
	virtual ~CSocketInit();
};

//ͨ������㲥��ַ�õ�������ַ
extern bool GetLocalAddress(int sock, const char* network, char* local);

#endif // !defined(AFX_SOCKETINIT_H__E7EE3B7E_1EEE_4E63_90CA_A773FF566013__INCLUDED_)
