/////////////////////////////////////////////////////////////////////////
///@system 网络监控系统
///@company 上海期货信息技术有限公司
///@file SessionProxy.cpp
///@brief 会话代理类，为CFrontServer和CManagerServer相互发送数据提供代理。
///@history
///20110728	李志伟   创建该文件
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

	// 记录数据包的ID和发送请求session的ID
	TRID rid;
	rid.SessionID = reqSession->GetSessionID();
	rid.RequestId = reqPkg->GetRequestId();

	m_index++;
	rspPkg->SetRequestId(m_index);

	if (!m_snmpMgr->RequestSnmp(rspPkg, datacenter))
	{
		// 请求snmp失败
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

	// 依据响应包的ID，查找请求包的ID信息
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
