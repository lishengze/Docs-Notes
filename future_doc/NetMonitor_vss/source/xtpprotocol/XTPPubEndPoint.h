// XTPPubEndPoint.h: interface for the CXTPPubEndPoint class.
//
// 2006.10.20 赵鸿昊 增加发送状态日志
// 20120409   江鹏   NT-0139 加快响应时间：xtp协议修改为微秒级调度
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPPUBENDPOINT_H__93E840F9_7AEE_406D_A53E_283C938D4713__INCLUDED_)
#define AFX_XTPPUBENDPOINT_H__93E840F9_7AEE_406D_A53E_283C938D4713__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Protocol.h"
#include "PublishPort.h"
#include "HashMap.h"

class CXTPPubHelper
{
public:
	virtual void SendHeartBeat(DWORD nSubjectID, WORD nCommPhaseNo, DWORD nSeqNo){};
};

class CXTPPubEndPoint 
{
public:
	CXTPPubEndPoint(CReadOnlyFlow *pFlow, DWORD nSubjectID,
		CProtocol *pSendProtocol, CXTPPubHelper *pControlHelper);
	virtual ~CXTPPubEndPoint();
	void Publish(QWORD nCurrClock);
	void OnNak(DWORD dwSubscriberID, int nStartID, DWORD dwNakTime);
	void OnAck(DWORD dwSubscriberID, int nStartID, DWORD dwAckTime);
	void OnTimer(DWORD nCurrClock);
	inline DWORD GetSubjectID();
private:
	void CreatePublishPort(DWORD dwSubscriberID, int nStartID, DWORD dwNakTime);
	void RemovePublishPort(CPublishPort *pPublishPort);
private:
	DWORD m_nSubjectID;
	vector<CPublishPort *> m_PublishPorts;
	CReadOnlyFlow *m_pFlow;
	DWORD m_nSendHeartbeatClock;
	DWORD m_nLogClock;
	QWORD m_nLastSendClock;
	CProtocol *m_pSendProtocol; 
	CXTPPubHelper *m_pControlHelper;
	CXTPPackage m_SendPackage;
};

inline DWORD CXTPPubEndPoint::GetSubjectID()
{
	return m_nSubjectID;
}

#endif // !defined(AFX_XTPPUBENDPOINT_H__93E840F9_7AEE_406D_A53E_283C938D4713__INCLUDED_)
