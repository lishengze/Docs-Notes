// UdpServer.cpp: implementation of the CUdpServer class.
//
///20120409  江鹏   NT-0139 加快响应时间：udp绑定ip
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "SocketInit.h"
#include "UdpServer.h"
#include "UdpChannel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUdpServer::CUdpServer(CServiceName *pName)
:CServerBase(pName), m_ServiceName(pName->GetLocation())
{
	m_bConnected = false;
	
	m_nID = socket(AF_INET, SOCK_DGRAM, 0); //建立UDP套接字

	/* set reuse and non block for this socket */
	int on=1;
	setsockopt(m_nID, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	//设置广播属性, add by wang.xiping 20071008
	setsockopt(m_nID, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
#ifdef HP_UX
	setsockopt(m_nID, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
#endif
	
	// 得到实际地址
	char localAddress[64];
	bool success = GetLocalAddress(m_nID, pName->GetHost(), localAddress);
	
#ifdef WINDOWS
	if (!success)
	{
		REPORT_EVENT(LOG_INFO, "UdpServer", "can't get local address: %s", pName->GetHost());
		strcpy(localAddress, "0.0.0.0");
	}
#else
	strcpy(localAddress, pName->GetHost());
#endif

	struct sockaddr_in servaddr; //IPv4套接口地址定义
	memset(&servaddr, 0, sizeof(servaddr)); //地址结构清零
	servaddr.sin_family = AF_INET; //IPv4协议
	servaddr.sin_addr.s_addr = inet_addr(localAddress);//指定地址
	servaddr.sin_port = htons(m_ServiceName.GetPort()); //端口
	
	//分配协议地址,绑定端口
	if (bind(m_nID, (sockaddr *) &servaddr, sizeof(servaddr)) != 0)
	{
		RAISE_RUNTIME_ERROR("bind fail");
	}
}

CUdpServer::~CUdpServer()
{

}

CChannel *CUdpServer::Accept(int wait)
{
	if (m_bConnected)
	{
		return NULL;
	}
	m_bConnected = true;
	return new CUdpChannel(m_nID, m_ServiceName.GetHost(), m_ServiceName.GetPort()+1);
}

int CUdpServer::GetId(void)
{
	if (!m_bConnected)
		return -1;
	else
		return 0;
}
