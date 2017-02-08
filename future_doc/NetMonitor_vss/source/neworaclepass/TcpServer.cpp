// TcpServer.cpp: implementation of the CTcpServer class.
//
// 2006.10.11	赵鸿昊	为支持SSL，增加方法CreateChannel,修改方法Accept 
//////////////////////////////////////////////////////////////////////

#include "platform.h"
#include "SocketInit.h"
#include "TcpServer.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTcpServer::CTcpServer(CServiceName *pName, CFileLogger *fpLog, int nCreateChannel) 
{
	m_pDBUser = NULL;
	m_bReloadFile = false;
	m_fpLog = fpLog;
	m_fpLog->output("Create Service %s...\n", pName->GetLocation());

	struct sockaddr_in me;
	CSocketInit socketinit;

	m_nID=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_nID<0) {
		m_fpLog->output(0, "    Can not create socket for tcp CServer\n");
	}
	int on=1;
	setsockopt(m_nID, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	memset(&me,0,sizeof(me));
	me.sin_family = AF_INET;
	me.sin_port = htons(pName->GetPort());
	if (bind(m_nID, (struct sockaddr *)&me, sizeof(me)) < 0)
	{
		m_fpLog->output(0, "    Can not bind port for tcp CServer\n");
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
			m_fpLog->output(0, "    Can not set FIONBIO for socket\n");
			closesocket(m_nID);
			return;
		}
		break;
	}
	if (listen(m_nID,50)<0)
	{
		m_fpLog->output(0, "    Server can not listen\n");
	}
	else
	{
		m_fpLog->output(0, "    Service %s is listening.\n", pName->GetLocation());
	}
	if (nCreateChannel==0) {
		m_pChannel = NULL;
	}
	else {
		m_pChannel = new CChannel[CHANNEL_MAX];
		for (int i=0; i<CHANNEL_MAX; i++) {
			m_pChannel[i].m_nID = -1;
		}
	}
}

CTcpServer::~CTcpServer()
{
	closesocket(m_nID);
}

int CTcpServer::Accept(int wait)
{
	int newId;
	struct sockaddr_in it;
	name_len_t nameLen=sizeof(it);
	newId = ::accept(m_nID, (struct sockaddr *)&it, &nameLen);
	if (newId < 0)
	{
		return -1;
	}
	return CreateChannel(newId);
}

int CTcpServer::GetId(void)
{
	return m_nID;
}

int CTcpServer::CreateChannel(int id)
{
	if (m_bReloadFile) {
		m_pDBUser->LoadFile();
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
			printf("Can not set FIONBIO for socket");
			closesocket(id);
			return 1;
		}
		break;
	}

	CChannel *p=NULL;
	for (int i=0; i<CHANNEL_MAX; i++) {
		if (m_pChannel[i].m_nID==-1) {
			p = m_pChannel+i;
			break;
		}
	}
	if (p==NULL) {
		char szSend[128];
		m_pDBUser->GetRsp(21, szSend);	//NoResource
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

int CTcpServer::ReadChannel(int i)
{
	char szSend[512];
	CChannel *p = m_pChannel+i;
	int nRet = recv(p->m_nID, p->buffer+p->nLen, sizeof(p->buffer)-p->nLen, 0);
	if (nRet<=0) {
		CloseChannel(i);
		return 1;
	}
	else {
		p->nLen += nRet;
	}

	if (strchr(p->buffer, '[')==NULL || strchr(p->buffer, ']')==NULL) {
		if (p->nLen>=500) {
			m_pDBUser->GetRsp(23, szSend); //ParseError
			send(p->m_nID, szSend, strlen(szSend) + 1, 0);
			CloseChannel(i);
		}
		return 0;
	}
	char szCmd[128], szEnv[128], szDBName[128], szUserName[128];
	nRet = sscanf(p->buffer, "[%s%s%s%s ]", szCmd, szEnv, szDBName, szUserName);
	if (nRet < 4) {
		return 0;
	}
	szCmd[4]=0, CDBUser::UpperCase(szCmd);
	szEnv[15]=0, CDBUser::UpperCase(szEnv);
	szDBName[15]=0, CDBUser::UpperCase(szDBName);
	szUserName[31] = 0, CDBUser::UpperCase(szUserName);
	if (strcmp(szCmd, "GET")!=0) {
		m_pDBUser->GetRsp(22, szSend);	//InvalidCmd
		send(p->m_nID, szSend, strlen(szSend) + 1, 0);
		return 0;
	}
	nRet = m_pDBUser->GetRsp(szEnv, szDBName, szUserName, szSend, p->nIP);
	send(p->m_nID, szSend, strlen(szSend) + 1, 0);
	CloseChannel(i);

	if (nRet==0) {
		m_fpLog->output("%s:%s %s %s %s OK.\n", 
			p->addr, szCmd, szEnv, szDBName, szUserName);
	}
	else {
		m_fpLog->output("%s:%s %s %s %s Error.\n", 
			p->addr, szCmd, szEnv, szDBName, szUserName);
	}
	return 0;
}

int CTcpServer::CloseChannel(int i)
{
	CChannel *p = m_pChannel+i;
	closesocket(p->m_nID);
	p->m_nID = -1;
	return 0;
}

char *CTcpServer::GetRemoteName(int id)
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
