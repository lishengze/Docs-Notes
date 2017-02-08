// SessionFactory.h: interface for the CSessionFactory class.
//
// 20070921 赵鸿昊 调整了结构，Listener不再由单独的线程驱动，改为读写线程驱动；
//                 Connecter只在连接部分由单独的线程驱动。
//                 增加了对连接模式的设定，可以指定对多个服务器是采用
//                 随机连接还是按注册顺序连接
// 20070924 赵鸿昊 支持nameserver
///20080727 赵鸿昊 NT-0048:
///                1.CSessionConnecter、RegisterListener、RegisterConnecter
///                  参数改为const, 降低对传入参数的要求。
///                2.注册地址时增加标记参数，在连接成功时会返回，以区分通过
///                  不同地址创建的连接
///20100318 武玉波 NT-0097 为类CConnecterManager增加方法GetSize，用来获取连接列表的大小
///20100512 赵鸿昊 NT-0103 客户端断线后重连优化：暂不重连刚刚中断过的服务器
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SESSIONFACTORY_H__375DDDE4_5E34_446C_884F_B81EE4789A15__INCLUDED_)
#define AFX_SESSIONFACTORY_H__375DDDE4_5E34_446C_884F_B81EE4789A15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SelectReactor.h"
#include "ListenCtrl.h"
#include "Session.h"
#include "NetworkFactory.h"
#include "HashMap.h"

const int UM_LISTEN_RESULT			= 0x40901 + SM_USER;
const int UM_CONNECT_RESULT			= 0x40902 + SM_USER;
const int UM_TRY_CONNECT			= 0x40903 + SM_USER;
const int UM_CONNECT_LOOP			= 0x40904 + SM_USER;

const int TIMER_ID_CONNECT = 1;

class CSessionConnecter
{
public:
	CSessionConnecter(const char *location, DWORD dwMark);
	bool CheckChannel(CChannel *pChannel);
	void OnConnected(CChannel *pChannel);
	CChannel *GetChannel();
	CChannel *Connect();
	CServiceName *GetServiceName();
	DWORD GetMark();
	void SetTempUnavailable(bool bTempUnavailable);
private:
	CServiceName m_ServiceName;
	CChannel *m_pChannel;
	CEventHandler *m_pSessionFactory;
	DWORD m_dwMark;
	bool m_bTempUnavailable;
};

class CConnecterManager : public CEventHandler
{
public:
	CConnecterManager(CReactor *pReactor, CEventHandler *pSessionFactory);
	~CConnecterManager();
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);
	void AppendConnecter(CSessionConnecter *pConnecter);
	void Clear();
	int Connect(bool bRandom);
	int ConnectNext();
	void OnConnected(CChannel *pChannel);
	void OnDiscconnected(CChannel *pChannel);
	void CancelConnect();
	bool IsConnecting();
	int GetSize();
private:
	void RandomConnecters();
private:
	vector<CSessionConnecter *> m_connecters;
	CEventHandler *m_pSessionFactory;
	int m_nConnecterPos;
	string m_strTempUnavailableLocation;
};

class CSessionListener : public CListenCtrl
{
public:
	CSessionListener(CReactor *pReactor, CEventHandler *pSessionFactory, CServerBase *pServer,
		DWORD dwMark);
	int OnConnected(CChannel *pChannel);
private:
	CEventHandler *m_pSessionFactory;
	DWORD m_dwMark;
};

class CSessionFactory : public CEventHandler, public CSessionCallback
{
public:
	CSessionFactory(CReactor *pReactor, int nMaxSession);
	virtual ~CSessionFactory();
	virtual void Start();
	void Stop();
	void DisconnectAll(int nReason);
	virtual void OnTimer(int nIDEvent);
	virtual int HandleEvent(int nEventID, DWORD dwParam, void *pParam);
	void RegisterConnecter(const char *location, DWORD dwMark = 0);
	void RegisterListener(const char *location, DWORD dwMark = 1);
	void EnableConnecter(bool bEnable);
	void EnableListener(bool bEnable);
	void SetConnectMode(bool bRandomConnect);
	inline bool IsConnecterEnable();
	inline bool IsListenerEnable();
	CSession *GetSession(DWORD nSessionID);
protected:
	virtual CSession *CreateSession(CChannel *pChannel, DWORD dwMark) = 0;
	virtual void OnSessionConnected(CSession *pSession);
	virtual void OnSessionDisconnected(CSession *pSession, int nReason);
	virtual void OnSessionWarning(CSession *pSession, int nReason, int nParam);	

	void OnChannelCreated(CChannel *pChannel, DWORD dwMark);
protected:
	CSelectReactor m_reactorConnect;
	vector<CSessionListener *> m_listeners;
	CConnecterManager *m_pConnecterManager;
	int m_nMaxSession;
	
	bool m_bRandomConnect;
	bool m_bConnecterEnable;
	bool m_bListenerEnable;

	typedef CHashMap<DWORD, CSession *, HashInt> CSessionMap;
	CSessionMap m_mapSession;	

	int m_nConnecterSize;
};

inline bool CSessionFactory::IsConnecterEnable()
{
	return m_bConnecterEnable;
}

inline bool CSessionFactory::IsListenerEnable()
{
	return m_bListenerEnable;
}

#endif // !defined(AFX_SESSIONFACTORY_H__375DDDE4_5E34_446C_884F_B81EE4789A15__INCLUDED_)
