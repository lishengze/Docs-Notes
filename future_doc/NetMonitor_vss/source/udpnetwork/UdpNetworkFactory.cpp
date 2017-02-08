// UdpNetworkFactory.cpp: implementation of the CUdpNetworkFactory class.
//
// 2006.10.11	�Ժ��	������UDP_NETWORK_NAME����CPP�У�
//						��ֹ��ΰ���������ظ����� 
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "UdpNetworkFactory.h"
#include "UdpClient.h"
#include "UdpServer.h"

const char *UDP_NETWORK_NAME = "udp";

CUdpNetworkFactory CUdpNetworkFactory::m_instance;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUdpNetworkFactory::CUdpNetworkFactory()
{
	RegisterFactory();
}

CUdpNetworkFactory::~CUdpNetworkFactory()
{

}

CServerBase *CUdpNetworkFactory::CreateServer(CServiceName *pName)
{
	if (strcmp(pName->GetChannel(), UDP_NETWORK_NAME) == 0)
	{
		return new CUdpServer(pName);
	}
	return CNetworkFactory::CreateServer(pName);
}
	
CClientBase *CUdpNetworkFactory::CreateClient(CServiceName *pName)
{
	if (strcmp(pName->GetChannel(), UDP_NETWORK_NAME) == 0)
	{
		return new CUdpClient();
	}
	return CNetworkFactory::CreateClient(pName);
}


