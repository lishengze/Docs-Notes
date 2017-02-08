// TcpServer.cpp: implementation of the CTcpMServer class.
//
// 2006.10.11	赵鸿昊	为支持SSL，增加方法CreateChannel,修改方法Accept 
//////////////////////////////////////////////////////////////////////

#include "platform.h"
#include "SocketInit.h"
#include "TcpMServer.h"
#include "Mutex.h"

extern int g_nTouchCount;
extern int g_nWorkFlag; // 0:待命状态; 1:采集状态; 2:落地状态;
extern CMutex g_mWorkFlagMutex; 

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTcpMServer::CTcpMServer(CServiceName *pName, int nCreateChannel) 
{
	m_bReloadFile = false;
	m_nTouchCount = 0;

	struct sockaddr_in me;
	CSocketInit socketinit;

	m_nID=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_nID<0) {
		REPORT_EVENT(LOG_CRITICAL,"socket","Can not create socket for tcp CServer");
	}
	int on=1;
	setsockopt(m_nID, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	memset(&me,0,sizeof(me));
	me.sin_family = AF_INET;
	me.sin_port = htons(pName->GetPort());
	if (bind(m_nID, (struct sockaddr *)&me, sizeof(me)) != 0)
	{
		char szTmp[200];
		sprintf(szTmp, "Can not bind port [tcp:%d]", pName->GetPort());
		REPORT_EVENT(LOG_CRITICAL,"socket",szTmp);
		printf("Error: %s, exit!\n", szTmp);
		fflush(stdout);
		exit(1);
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
			REPORT_EVENT(LOG_CRITICAL,"socket","Can not set FIONBIO for socket");
			closesocket(m_nID);
			return;
		}
		break;
	}
	if (listen(m_nID,50)<0)
	{
		REPORT_EVENT(LOG_CRITICAL,"socket","Server can not listen");
	}
	else
	{
		REPORT_EVENT(LOG_CRITICAL,"socket","Service %s is listening.\n", pName->GetLocation());
	}
	if (nCreateChannel==0) {
		m_pChannel = NULL;
	}
	else {
		m_pChannel = new CMChannel[CHANNEL_MAX];
		for (int i=0; i<CHANNEL_MAX; i++) {
			m_pChannel[i].m_nID = -1;
		}
	}
}

CTcpMServer::~CTcpMServer()
{
	closesocket(m_nID);
}

void CTcpMServer::Join()
{
	fd_set active, read;
	int nMaxFD, nRet;

	while (1) {
		FD_ZERO(&active);
		FD_SET(GetId(), &active);

		if (nMaxFD< GetId()) {
			nMaxFD = GetId();
		}

		nMaxFD++;

		read = active;
		struct timeval timeout;
		timeout.tv_sec=5;
		timeout.tv_usec=0;
		nRet = select(nMaxFD, &read, NULL, NULL, &timeout);
		if (nRet<=0) {
#ifdef WINDOWS
			Sleep(30);
#else
			usleep(1000);
#endif
			CMonitorIndex::handleOne();
			continue;
		}
		if (FD_ISSET(GetId(), &read)) {
			Accept(10);
		}
		time_t tNow=time(NULL);
		CMonitorIndex::handleOne();
	}
}

int CTcpMServer::Accept(int wait)
{
	int newId;
	struct sockaddr_in it;
	name_len_t nameLen=sizeof(it);
	char *pName;
	newId = ::accept(m_nID, (struct sockaddr *)&it, &nameLen);
	if (newId < 0)
	{
		return -1;
	}
	else
	{
		m_nTouchCount ++;		
		pName = GetRemoteAddress(newId);
#ifdef PRINT_DEBUG		
		printf("get Connection from [%s]\nSet WorkFlag=[%d], TouchCount=%d\n\n"
			, pName, g_nWorkFlag, g_nTouchCount);
#endif		
		fflush(stdout);
	}
	return CreateChannel(newId);
}

int CTcpMServer::GetId(void)
{
	return m_nID;
}

int CTcpMServer::CreateChannel(int id)
{
	if (m_bReloadFile) {

		closesocket(id);
		return 0;
	}
	if (m_pChannel==NULL) {
		closesocket(id);
		return 0;
	}

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
			REPORT_EVENT(LOG_CRITICAL,"socket","Can not set FIONBIO for socket");
			closesocket(id);
			return 1;
		}
		break;
	}

	CMChannel *p=NULL;
	for (int i=0; i<CHANNEL_MAX; i++) {
		if (m_pChannel[i].m_nID==-1) {
			p = m_pChannel+i;
			break;
		}
	}
	if (p==NULL) {
		char szSend[128];

		send(id, szSend, strlen(szSend) + 1, 0);
		closesocket(id);
		return 2;
	}
	p->m_nID = id;
	memset((void *)p->buffer, 0, sizeof(p->buffer));
	p->addr[0] = 0;
	p->nLen = 0;
	p->tLogin = time(NULL)+CHANNEL_TIMEOUT;

	name_len_t nameLen;

	struct sockaddr name;
	struct sockaddr_in *p_name;
	nameLen=sizeof(name);
	if (getpeername(id, &name, &nameLen)==0) {
		p_name=(struct sockaddr_in *)(&name);
		strcpy(p->addr, inet_ntoa(p_name->sin_addr));
		p->nIP =(unsigned int) p_name->sin_addr.s_addr;
	}
	return 0;
}

int CTcpMServer::ReadChannel(int i)
{
	char szSend[512];
	CMChannel *p = m_pChannel+i;
	int nRet = recv(p->m_nID, p->buffer+p->nLen, sizeof(p->buffer)-p->nLen, 0);
	if (nRet<=0) {
		CloseChannel(i);
		return 1;
	}
	else {
		p->nLen += nRet;
	}

	return 0;
}

int CTcpMServer::CloseChannel(int i)
{
	CMChannel *p = m_pChannel+i;
	closesocket(p->m_nID);
	p->m_nID = -1;
	return 0;
}

char *CTcpMServer::GetRemoteName(int id)
{
	name_len_t nameLen;

	struct sockaddr name;
	struct sockaddr_in *p_name;
	nameLen=sizeof(name);
	if (getpeername( id ,&name,&nameLen)!=0)
	{
		return "";
	}
	p_name=(struct sockaddr_in *)(&name);
	return inet_ntoa(p_name->sin_addr);
}

char *CTcpMServer::GetRemoteAddress(int id)
{
	name_len_t nameLen;
	const char szAddress[32] = "";

	struct sockaddr name;
	struct sockaddr_in *p_name;
	nameLen=sizeof(name);
	if (getpeername( id ,&name,&nameLen)!=0)
	{
		return "";
	}
	p_name=(struct sockaddr_in *)(&name);
	memset((void *)szAddress, 0x00, sizeof(szAddress));
	sprintf((char *)szAddress, "tcp://%s:%d", inet_ntoa(p_name->sin_addr), p_name->sin_port);
	return (char *)szAddress;
}
