/////////////////////////////////////////////////////////////////////////
///@system ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file SessionProxy.cpp
///@brief �Ự�����࣬ΪCFrontServer��CManagerServer�໥���������ṩ����
///@history
///20110728	��־ΰ   �������ļ�
/////////////////////////////////////////////////////////////////////////
#include "SessionProxy.h"
#include "CommonFTDMsg.h"
#include <PrjCommon.h>

extern CBufferLogger *g_bufferLogger;

SessionProxy SessionProxy:: m_obj;

void SessionProxy::RequestSnmp(
	CFTDCPackage *reqPkg,
	CFTDCSession *reqSession,
	CFTDCPackage *rspPkg,
	char datacenter)
{
	assert(reqPkg && reqPkg);

	ScopeLock<CMutex> lock(m_mutex);

	// ��¼���ݰ���ID�ͷ�������session��ID
	TRID rid;
	rid.SessionID = reqSession->GetSessionID();
	rid.RequestId = reqPkg->GetRequestId();

	m_index++;
	rspPkg->SetRequestId(m_index);

	if (!m_snmpMgr->RequestSnmp(rspPkg, datacenter))
	{
		// ����snmpʧ��
		CCommonFTDRsp::Instance()->SendLastErroRsp(
				reqSession,
				rspPkg,
				reqPkg,
				reqPkg->GetTID(),
				"Request snmp failed!");
		m_index--;
	}
	else
	{
		m_vRid[m_index] = rid;
	}
}

void SessionProxy::RespondFront(int rspID, CFTDCPackage *rspPkg, bool lastRsp)
{
	assert(rspPkg);
	ScopeLock<CMutex> lock(m_mutex);

	// ������Ӧ����ID�������������ID��Ϣ
	SessionPkgSet::iterator it = m_vRid.find(rspID);
	if (it == m_vRid.end())
	{
		LOG_WARNING("Cann't find session by response ID(%d)\n", rspID);
		return;
	}

	TRID rid = it->second;
	rspPkg->SetRequestId(rid.RequestId);
	if (m_frontMgr->GetSession(rid.SessionID))
	{
		LogPkg(rspPkg, g_bufferLogger, g_traceLog);
		((CFTDCSession *) (m_frontMgr->GetSession(rid.SessionID)))->SendRequestPackage(rspPkg);
	}

	if (lastRsp)
	{
		m_vRid.erase(it);
	}
}
