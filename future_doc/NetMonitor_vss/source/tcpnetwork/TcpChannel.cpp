// TcpChannel.cpp: implementation of the CTcpChannel class.
//
// 20091214 赵鸿昊  NT-0092:禁用 Nagle 算法,降低报文传输的延时
///20120726 江鹏    对于不安全函数进行了对应安全版本的封装：localtime、inet_ntoa
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "SocketInit.h"
#include "TcpChannel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTcpChannel::CTcpChannel(int id) : CChannel(CT_STREAM, id)
{
	for (;;)
	{
#ifdef UNIX
		int on=1;
		if (ioctlsocket(id, FIONBIO, (char *)&on) < 0)
#endif

#ifdef WIN32
		unsigned long on_windows=1;
		if (ioctlsocket(id, FIONBIO, &on_windows) < 0)
#endif


#ifdef VOS
		int off=0;
		if (ioctlsocket(id, FIONBIO, (char *)&off) <0)
#endif
		{
			if (GET_LAST_SOCK_ERROR() == EINTR)
				continue;
			RAISE_RUNTIME_ERROR("Can not set FIONBIO\n");
		}
		else
			break;
	}

	int on = 1;   
	setsockopt(id, IPPROTO_TCP, TCP_NODELAY, (char*)&on, sizeof(on));
	
	m_dwInAddr = 0;
	
	struct sockaddr name;
	SOCKADDRLEN nameLen=sizeof(name);
	if (getpeername(GetId(),&name,&nameLen)==0)
	{
		memcpy(&m_dwInAddr, &(((struct sockaddr_in *)&name)->sin_addr),sizeof(DWORD));
	}
}

CTcpChannel::~CTcpChannel()
{
}

int CTcpChannel::ReadImp(int number, char *buffer)
{
	int nCount = ::recv(GetId(),buffer,number,0);
	if (nCount == 0)
		return -1;

	if (nCount == -1)
	{
		int nErrno = GET_LAST_SOCK_ERROR();
		if (nErrno == EWOULDBLOCK || nErrno == 0)		//20060224 IA64 add 0
			return 0;
		else
			return -1;
	}
	return nCount;
}

int CTcpChannel::WriteImp(int number, char *buffer)
{
	int nCount = ::send(GetId(),buffer,number,0);

	if (nCount == 0)
	{
#if !defined(HP_UX) && !defined(AIX)
		return -1;
#endif			
	}

	if (nCount == -1)
	{
		int nErrno = GET_LAST_SOCK_ERROR();

#ifdef AIX
		if (nErrno == EWOULDBLOCK || nErrno == 2 || nErrno==0)
#elif defined(HP_UX)
		if (nErrno == EWOULDBLOCK || nErrno==16 || nErrno==0 || nErrno==2 || nErrno==251)
#else
	    if (nErrno == EWOULDBLOCK)
#endif			
			return 0;
		else
		{
			NET_EXCEPTION_LOG1("GET_LAST_SOCK_ERROR()=%d\n", nErrno);
			return -1;
		}
	}
	return nCount;
}

bool CTcpChannel::AvailableImp(void)
{
	return true;
}

bool CTcpChannel::DisconnectImp(void)
{
	closesocket(GetId());
	return false;
}

bool CTcpChannel::CheckConnectionImp(void)
{
	return true;
}

char *CTcpChannel::GetRemoteName(void)
{
	struct in_addr addr;
	memcpy(&addr, &m_dwInAddr, sizeof(DWORD));
	InetNtoA(addr, m_RemoteName);

	return m_RemoteName;
}

