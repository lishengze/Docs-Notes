// UdpClient.cpp: implementation of the CUdpClient class.
//
///20120409  江鹏   NT-0139 加快响应时间：udp绑定ip
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "UdpClient.h"
#include "SocketInit.h"
#include "UdpChannel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUdpClient::CUdpClient()
{

}

CUdpClient::~CUdpClient()
{

}

CChannel *CUdpClient::Connect(CServiceName *pName)
{
	struct sockaddr_in servaddr; //IPv4套接口地址定义
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //建立UDP套接字
	/* set reuse and non block for this socket */
	int on=1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	//设置广播属性, add by wang.xiping 20071008
	setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
#ifdef HP_UX
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
#endif

	// 得到实际地址
	char localAddress[64];
	bool success = GetLocalAddress(sockfd, pName->GetHost(), localAddress);

#ifdef WINDOWS		
	if (!success)
	{
		REPORT_EVENT(LOG_INFO, "UdpClient", "can't get local address: %s", pName->GetHost());
		strcpy(localAddress, "0.0.0.0");
	}
#else
	strcpy(localAddress, pName->GetHost());
#endif

	memset(&servaddr, 0, sizeof(servaddr)); //地址结构清零
	servaddr.sin_family = AF_INET; //IPv4协议
	servaddr.sin_addr.s_addr = inet_addr(localAddress);//指定地址
	servaddr.sin_port = htons(pName->GetPort()+1); //端口

	//分配协议地址,绑定端口
	if (bind(sockfd, (sockaddr *) &servaddr, sizeof(servaddr)) != 0)
	{
		RAISE_RUNTIME_ERROR("bind fail\n");
	}

	CChannel *pChannel = new CUdpChannel(sockfd, pName->GetHost(), pName->GetPort());

	return pChannel;
}
