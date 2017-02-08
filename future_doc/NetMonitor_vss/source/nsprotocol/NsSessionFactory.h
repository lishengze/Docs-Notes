// NsSessionFactory.h: interface for the CNsSessionFactory class.
//
///20080727 赵鸿昊 NT-0048 : 配合CSessionFactory的修改，注册地址时增加标记参数，
///                在连接成功时会返回，以区分通过不同地址创建的连接
///20080318 武玉波 NT-0097：在不提供front地址的时候，跳过延时
///					直接使用NameServer获取Front，建立连接
///20100512 赵鸿昊 NT-0103 客户端断线后重连优化：将NT-0097所做的延时判断逻辑移入
///                CSessionFactory
///20110509 江鹏   NT-0131 UserAPI功能完善
///20121010 孙尧宇 NT-0131 UserAPI功能完善，避免fens挂死的方法不再使用超时重连，而使用NsSession定时Disconnect，以免同时发起两个fens连接
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NSSESSIONFACTORY_H__B6E230B2_75D9_4E73_ABBF_2E6DB4EC6FDA__INCLUDED_)
#define AFX_NSSESSIONFACTORY_H__B6E230B2_75D9_4E73_ABBF_2E6DB4EC6FDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "SessionFactory.h"
#include "NsSession.h"

class CNsSessionFactory : public CSessionFactory, public CNsSessionCallback 
{
public:
	CNsSessionFactory(CReactor *pReactor, int nMaxSession);
	virtual ~CNsSessionFactory();
	void RegisterNameServer(char *location, DWORD dwMark=0);
	virtual int HandlePackage(CNsPackage *pNsPackage, CNsSession *pSession);
	virtual void OnTimer(int nIDEvent);
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);
	void NsDisconnect(CChannel *pChannel);

protected:
	CConnecterManager *m_pNsConnecterManager;
	CNsSession *m_pNsSession;
	bool m_bInQueryNs;
};

#endif // !defined(AFX_NSSESSIONFACTORY_H__B6E230B2_75D9_4E73_ABBF_2E6DB4EC6FDA__INCLUDED_)
