// PublishStub.cpp: implementation of the CPublishStub class.
//
// 20070905 赵鸿昊 增加了CancelPublish方法
// 20110119 江鹏   NT-0121：front不用重启换号
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "PublishStub.h"
#include "NetworkFactory.h"

const int FIB_IMPL_HEADER_RESERVED = 200;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPublishStub::CPublishStub(CReactor *pReactor, DWORD nNodeID, char *pszAddress)
{
	m_Handler = NULL;
	m_nClock = 0;
	m_nNodeID = nNodeID;
	strcpy(m_szAddress, pszAddress);
	
	CServiceName serviceName(pszAddress);
	CServerBase *pServer = CNetworkFactory::GetInstance()->CreateServer(&serviceName);
	
	CChannel *pChannel = pServer->Accept(0);		//只对UDP有效
	m_pSession = new CXTPPubSession(pReactor, pChannel, this);
	
	pReactor->RegisterIO(m_pSession);
	delete pServer;
}

CPublishStub::~CPublishStub()
{
	delete m_pSession;
}

const char *CPublishStub::GetAddress()
{
	return m_szAddress;
}

void CPublishStub::RegisterFlow(CReadOnlyFlow *pFlow, DWORD nSubjectID)
{
	if (GetFlow(nSubjectID) != NULL) 
	{
		return ;
	}
	m_mapFlow.Insert(nSubjectID, pFlow);
}

void CPublishStub::CancelPublish(DWORD nSubjectID)
{
	m_pSession->UnPublish(nSubjectID);
}

CReadOnlyFlow *CPublishStub::GetFlow(DWORD nSubjectID)
{
	CReadOnlyFlow **pFind = m_mapFlow.Find(nSubjectID);
	if (pFind == NULL) 
	{
		return NULL;
	}
	return *pFind;
}

CXTPPackage *CPublishStub::CreateMessage()
{
	return m_pSession->CreatePackage();
}

void CPublishStub::Release()
{
	delete this;
}

void CPublishStub::SetParams(CEventHandler* handler, DWORD nClock)
{
	m_Handler = handler;
	m_nClock = nClock;

	m_pSession->SetParams(m_Handler, m_nNodeID, m_nClock);
}

CFibPublishApi *CFibPublishApi::CreatePublishApi(CReactor *pReactor, DWORD nNodeID, char *pszAddress)
{
	return new CPublishStub(pReactor, nNodeID, pszAddress);
}

