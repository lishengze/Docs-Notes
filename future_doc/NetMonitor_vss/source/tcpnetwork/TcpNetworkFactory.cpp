// TcpNetworkFactory.cpp: implementation of the CTcpNetworkFactory class.
//
// 2006.10.11	�Ժ��	������TCP_NETWORK_NAME����CPP�У�
//						��ֹ��ΰ���������ظ����� 
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "TcpNetworkFactory.h"
#include "TcpClient.h"
#include "TcpServer.h"

const char *TCP_NETWORK_NAME = "tcp";

CTcpNetworkFactory CTcpNetworkFactory::m_instance;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTcpNetworkFactory::CTcpNetworkFactory()
{
	RegisterFactory();
}

CTcpNetworkFactory::~CTcpNetworkFactory()
{

}

CServerBase *CTcpNetworkFactory::CreateServer(CServiceName *pName)
{
	if (strcmp(pName->GetChannel(), TCP_NETWORK_NAME) == 0)
	{
		return new CTcpServer(pName);
	}
	return CNetworkFactory::CreateServer(pName);
}
	
CClientBase *CTcpNetworkFactory::CreateClient(CServiceName *pName)
{
	if (strcmp(pName->GetChannel(), TCP_NETWORK_NAME) == 0)
	{
		return new CTcpClient();
	}
	return CNetworkFactory::CreateClient(pName);
}


