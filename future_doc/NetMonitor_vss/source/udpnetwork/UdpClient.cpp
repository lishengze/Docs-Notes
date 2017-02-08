// UdpClient.cpp: implementation of the CUdpClient class.
//
///20120409  ����   NT-0139 �ӿ���Ӧʱ�䣺udp��ip
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
	struct sockaddr_in servaddr; //IPv4�׽ӿڵ�ַ����
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0); //����UDP�׽���
	/* set reuse and non block for this socket */
	int on=1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
	//���ù㲥����, add by wang.xiping 20071008
	setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, (char *)&on, sizeof(on));
#ifdef HP_UX
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
#endif

	// �õ�ʵ�ʵ�ַ
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

	memset(&servaddr, 0, sizeof(servaddr)); //��ַ�ṹ����
	servaddr.sin_family = AF_INET; //IPv4Э��
	servaddr.sin_addr.s_addr = inet_addr(localAddress);//ָ����ַ
	servaddr.sin_port = htons(pName->GetPort()+1); //�˿�

	//����Э���ַ,�󶨶˿�
	if (bind(sockfd, (sockaddr *) &servaddr, sizeof(servaddr)) != 0)
	{
		RAISE_RUNTIME_ERROR("bind fail\n");
	}

	CChannel *pChannel = new CUdpChannel(sockfd, pName->GetHost(), pName->GetPort());

	return pChannel;
}
