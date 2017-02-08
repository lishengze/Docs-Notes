// FibPubApiManager.h: interface for the CFibPubApiManager class.
//
// 20110119 江鹏   NT-0121：front不用重启换号
///20120416 江鹏   NT-0139 加快响应时间：xtp协议订阅和发布支持多线程
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIBPUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_)
#define AFX_FIBPUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FibPublishApi.h"
#include "SelectReactor.h"

class CFibPubApiManager  
{
public:
	CFibPubApiManager(CReactor *pReactor, DWORD nNodeID);
	CFibPubApiManager(CReactorManager *pReactorManager, DWORD nNodeID);
	virtual ~CFibPubApiManager();
	CFibPublishApi *GetFibPublishApi(char *pszAddress);

	/**设置参数
	* 启用发布请求功能
	* 发布请求功能是在发布前请请求订阅者把订阅者当前接收的数据个数发过来
	* @param handler 事件处理器
	* @param nClock 发布请求中的时间id
	*/
	virtual void SetParams(CEventHandler* handler, DWORD nClock);

private:
	CReactor *m_pReactor;
	CReactorManager *m_pReactorManager;
	DWORD m_nNodeID;
	typedef map<const char *, CFibPublishApi *, ltstr> CFibPublishApiMap;
	CFibPublishApiMap m_mapFibPublishApi;

	// 事件处理器
	CEventHandler* m_Handler;

	// 发布者的时间id
	DWORD m_nClock;
};

#endif // !defined(AFX_FIBPUBAPIMANAGER_H__31E0B14D_F679_4359_B470_1AC132227416__INCLUDED_)
