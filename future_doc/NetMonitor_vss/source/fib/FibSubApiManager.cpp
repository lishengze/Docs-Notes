// FibSubApiManager.cpp: implementation of the CFibSubApiManager class.
//
///20120416 江鹏   NT-0139 加快响应时间：xtp协议订阅和发布支持多线程
//////////////////////////////////////////////////////////////////////
#include "public.h"
#include "FibSubApiManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFibSubApiManager::CFibSubApiManager(CReactor *pReactor, DWORD nNodeID)
{
	m_pReactor = pReactor;
	m_pReactorManager = NULL;
	m_nNodeID = nNodeID;
}

CFibSubApiManager::CFibSubApiManager(CReactorManager *pReactorManager, DWORD nNodeID)
{
	m_pReactor = NULL;
	m_pReactorManager = pReactorManager;
	m_nNodeID = nNodeID;
}

CFibSubApiManager::~CFibSubApiManager()
{
	CFibSubscribeApiMap::iterator i = m_mapFibSubscribeApi.begin();
	for(; i!=m_mapFibSubscribeApi.end(); i++)
	{
		((*i).second)->Release();
	}
}

CFibSubscribeApi *CFibSubApiManager::GetFibSubscribeApi(char *pszAddress)
{
	CFibSubscribeApi *pFibSubscribeApi = NULL;
	CFibSubscribeApiMap::iterator i = m_mapFibSubscribeApi.find(pszAddress);
	if (i != m_mapFibSubscribeApi.end())
	{
		pFibSubscribeApi = (*i).second; 
	}
	else
	{
		if (m_pReactor != NULL)
		{
			pFibSubscribeApi = CFibSubscribeApi::CreateSubscribeApi(m_pReactor,m_nNodeID, pszAddress);
		}
		else
		{
			pFibSubscribeApi = CFibSubscribeApi::CreateSubscribeApi(m_pReactorManager->CreateReactor(),m_nNodeID, pszAddress);
		}

		m_mapFibSubscribeApi[pFibSubscribeApi->GetAddress()] = pFibSubscribeApi;
	}

	return pFibSubscribeApi;
}
