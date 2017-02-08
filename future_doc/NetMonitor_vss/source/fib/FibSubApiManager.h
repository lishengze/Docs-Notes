// FibSubApiManager.h: interface for the CFibSubApiManager class.
//
///20120416 江鹏   NT-0139 加快响应时间：xtp协议订阅和发布支持多线程
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIBSUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_)
#define AFX_FIBSUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FibSubscribeApi.h"
#include "SelectReactor.h"

class CFibSubApiManager  
{
public:
	CFibSubApiManager(CReactor *pReactor, DWORD nNodeID);
	CFibSubApiManager(CReactorManager *pReactorManager, DWORD nNodeID);
	virtual ~CFibSubApiManager();
	CFibSubscribeApi *GetFibSubscribeApi(char *pszAddress);
private:
	CReactor *m_pReactor;
	CReactorManager *m_pReactorManager;
	DWORD m_nNodeID;
	typedef map<const char *, CFibSubscribeApi *, ltstr> CFibSubscribeApiMap;
	CFibSubscribeApiMap m_mapFibSubscribeApi;
};

#endif // !defined(AFX_FIBSUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_)
