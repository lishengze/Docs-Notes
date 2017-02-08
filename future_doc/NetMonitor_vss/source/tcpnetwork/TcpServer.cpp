// TcpServer.cpp: implementation of the CTcpServer class.
//
// 2006.10.11	�Ժ��	Ϊ֧��SSL�����ӷ���CreateChannel,�޸ķ���Accept 
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "SocketInit.h"
#include "TcpServer.h"
#include "TcpChannel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTcpServer::CTcpServer(CServiceName *pName) : CServerBase(pName)
{
	struct sockaddr_in me;

	m_nID=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_nID<0)
	{
#ifdef UNIX
		printf("CTcpServer::CTcpServer socket Error[%d]: %s\n", errno, strerror(errno));
#endif
		RAISE_RUNTIME_ERROR("Can not create socket for tcp CServer");
	}
	int on=1;
	setsockopt(m_nID, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	memset(&me,0,sizeof(me));
	me.sin_family = AF_INET;
	me.sin_port = htons(pName->GetPort());
	if (bind(m_nID, (struct sockaddr *)&me, sizeof(me)) < 0)
	{
#ifdef UNIX
                printf("CTcpServer::CTcpServer bind Error[%d]: %s\n", errno, strerror(errno));
#endif
		RAISE_RUNTIME_ERROR("Can not bind port for tcp CServer");
	}
	for (;;)
	{
#ifdef UNIX
		on=1;
		if (ioctlsocket(m_nID, FIONBIO, (char *)&on) < 0)
#endif

#ifdef WIN32
		unsigned long on_windows=1;
		if (ioctlsocket(m_nID, FIONBIO, &on_windows) < 0)
#endif


#ifdef VOS
		int off=0;
		if (ioctlsocket(m_nID, FIONBIO, (char *)&off) <0)
#endif
		{
			if (GET_LAST_SOCK_ERROR() == EINTR)
				continue;
			RAISE_RUNTIME_ERROR("Can not set FIONBIO for socket");
			closesocket(m_nID);
			return;
		}
		break;
	}
	if (listen(m_nID,5)<0)
	{
		RAISE_RUNTIME_ERROR("Server can not listen");
	}
}

CTcpServer::~CTcpServer()
{
	closesocket(m_nID);
}

CChannel *CTcpServer::Accept(int wait)
{
	int newId;
	struct sockaddr_in it;
	SOCKADDRLEN nameLen=sizeof(it);
	newId = ::accept(m_nID, (struct sockaddr *)&it, &nameLen);
	if (newId < 0)
	{
		return NULL;
	}
	return CreateChannel(newId);
}

int CTcpServer::GetId(void)
{
	return m_nID;
}

CChannel *CTcpServer::CreateChannel(int id)
{
	return new CTcpChannel(id);
}
