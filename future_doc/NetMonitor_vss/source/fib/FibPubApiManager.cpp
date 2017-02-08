// FibPubApiManager.cpp: implementation of the CFibPubApiManager class.
//
// 20110119 江鹏   NT-0121：front不用重启换号
///20120416 江鹏   NT-0139 加快响应时间：xtp协议订阅和发布支持多线程
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "FibPubApiManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFibPubApiManager::CFibPubApiManager(CReactor *pReactor, DWORD nNodeID)
{
	m_pReactor = pReactor;
	m_pReactorManager = NULL;
	m_nNodeID = nNodeID;

	m_Handler = NULL;
	m_nClock = 0;
}

CFibPubApiManager::CFibPubApiManager(CReactorManager *pReactorManager, DWORD nNodeID)
{
	m_pReactor = NULL;
	m_pReactorManager = pReactorManager;
	m_nNodeID = nNodeID;

	m_Handler = NULL;
	m_nClock = 0;
}

CFibPubApiManager::~CFibPubApiManager()
{
	CFibPublishApiMap::iterator i = m_mapFibPublishApi.begin();
	for(; i!=m_mapFibPublishApi.end(); i++)
	{
		((*i).second)->Release();
	}
}

CFibPublishApi *CFibPubApiManager::GetFibPublishApi(char *pszAddress)
{
	CFibPublishApi *pFibPublishApi = NULL;
	CFibPublishApiMap::iterator i = m_mapFibPublishApi.find(pszAddress);
	if (i != m_mapFibPublishApi.end())
	{
		pFibPublishApi = (*i).second; 
	}
	else
	{
		if (m_pReactor != NULL)
		{
			pFibPublishApi = CFibPublishApi::CreatePublishApi(m_pReactor,m_nNodeID, pszAddress);
		}
		else
		{
			pFibPublishApi = CFibPublishApi::CreatePublishApi(m_pReactorManager->CreateReactor(),m_nNodeID, pszAddress);
		}

		pFibPublishApi->SetParams(m_Handler, m_nClock);
		m_mapFibPublishApi[pFibPublishApi->GetAddress()] = pFibPublishApi;
	}

	return pFibPublishApi;
}

void CFibPubApiManager::SetParams(CEventHandler* handler, DWORD nClock)
{
	m_Handler = handler;
	m_nClock = nClock;
}
