// XTPPubSession.h: interface for the CXTPPubSession class.
//
// 20110119 江鹏   NT-0121：front不用重启换号
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPPUBSESSION_H__10E4F6D6_8AC4_421B_9589_B9EB7A021ECE__INCLUDED_)
#define AFX_XTPPUBSESSION_H__10E4F6D6_8AC4_421B_9589_B9EB7A021ECE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Flow.h"
#include "XTPSession.h"
#include "SCPProtocol.h"
#include "Subscriber.h"

class CXTPFlowManager  
{
public:
	virtual CReadOnlyFlow *GetFlow(DWORD nSubjectID) = 0;
};

class CXTPPubSession : public CXTPSession
{
public:
	CXTPPubSession(CReactor *pReactor, CChannel *pChannel, CXTPFlowManager *pFlowManager);
	virtual ~CXTPPubSession();
	CSCPPackage *PrepareControlPackage(WORD stid);
	void SendControlPackage(CSCPPackage *pPackage);
	
	void RegisterSubscriber(CSubscriber *pSubscriber, DWORD dwSubscriberID);
	void UnRegisterSubscriber(CSubscriber *pSubscriber);
	virtual void SendNak(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID, DWORD nSeqNo);
	virtual void SendAck(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID, DWORD nSeqNo);
	virtual void SendHeartBeat(DWORD nSubjectID, WORD nCommPhaseNo, DWORD nSeqNo);
	virtual void SetParams(CEventHandler* handler, DWORD nNodeID, DWORD nClock);

protected:
	virtual int HandlePackage(CPackage *pPackage, CProtocol *pProtocol);
	void OnSubscribeReq(CSCPPackage *pSCPPackage);
	void OnUnSubscribeReq(CSCPPackage *pSCPPackage);
	void OnHeartBeat(CSCPPackage *pSCPPackage);
	void OnAck(CSCPPackage *pSCPPackage);
	void OnPublishReq(CSCPPackage *pSCPPackage);
	void OnPublishRsp(CSCPPackage *pSCPPackage);
	void SendSubscribeReq(DWORD nSubjectID, WORD nCommPhaseNo, DWORD dwSubscriberID, DWORD nStartID);
	void SendUnSubscribeReq(DWORD nSubjectID);
	void SendPublishReq(DWORD nSubjectID, WORD nCommPhaseNo);
	void SendPublishRsp(DWORD nNodeID, DWORD nClock, DWORD nSubjectID, WORD nCommPhaseNo, DWORD nSeqNo);

private:
	CXTPFlowManager *m_pFlowManager;
	CSCPProtocol *m_pControlProtocol;
	CSCPPackage m_controlPackage;

	// 是否已初始化
	bool m_IsInit;

	// 节点id
	DWORD m_nNodeID;

	// 发布者的时间id
	DWORD m_nClock;

	// 事件处理器
	CEventHandler* m_Handler;

	// 订阅者
	map<DWORD, CSubscriber*> m_SubscriberMap;
};
#endif // !defined(AFX_XTPPUBSESSION_H__10E4F6D6_8AC4_421B_9589_B9EB7A021ECE__INCLUDED_)
