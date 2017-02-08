/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CManagerServer.cpp
///@brief	定义了SNMP管理端连接处理的类
///@history
///20110618	李志伟		创建该文件
#include "CManagerServer.h"
#include "databaseData.h"
#include "UFCopy.h"
#include "CFrontServer.h"
#include "FTDDataHelper.h"
#include "PrjCommon.h"
#include "SessionProxy.h"
#include <CommonFTDMsg.h>
#include "ConfigInfo.h"
#include <algorithm>
#include <ScopedLock.h>

// 全局的内存数据库
extern CMemoryDB *pMemoryDB;

// 全局的索引生成器，为新增记录提供索引服务
extern map<string, int> g_idMaker;
extern map<int, taskStatus> g_taskStatus;
extern CFileLogger	*g_recvPkgLogger;	// 数据包输出到文件
extern CBufferLogger *g_bufferLogger;

// 从内存数据库中获取信息，并发送给当前连接
#define SEND_CONFIG(tag)																					   \
	do																										   \
	{																										   \
		m_pkgSend.PrepareResponse(																			   \
				pFTDCPackage,																				   \
				FTD_RSP_ID(tag),																			   \
				FTDC_CHAIN_CONTINUE,																		   \
				FTD_VERSION);																				   \
		FTD_RSP(tag) rspField;																				   \
		ITERATE_MEMORYDB_BYALL_BEGIN(tag)																	   \
		{																									   \
			COPY_FTD_ENTITY(tag, &rspField, pField);														   \
			rspField.OperationType = 1;																		   \
			AddRspWithField < FTD_RSP(tag) > (&m_pkgSend, &rspField, pSession, pFTDCPackage, FTD_RSP_ID(tag)); \
		}																									   \
																										\
		ITERATE_MEMORYDB_BYALL_END(tag) LogPkg(																   \
				&m_pkgSend,																					   \
				g_bufferLogger,																				   \
				g_traceLog);																				   \
		pSession->SendRequestPackage(&m_pkgSend);															   \
		CCommonFTDRsp::Instance()->SendSuccRsp(																   \
				pSession,																					   \
				&m_pkgSend,																					   \
				pFTDCPackage,																				   \
				FTD_RSP_ID(tag));																			   \
	} while (0)

// 从内存数据库中获取与数据中心匹配的信息，并发送给当前连接
#define SEND_CONFIG_DC_SPEC(tag, dc)											   \
	do																			   \
	{																			   \
		m_pkgSend.PrepareResponse(												   \
				pFTDCPackage,													   \
				FTD_RSP_ID(tag),												   \
				FTDC_CHAIN_CONTINUE,											   \
				FTD_VERSION);													   \
		FTD_RSP(tag) rspField;													   \
		ITERATE_MEMORYDB_BYALL_BEGIN(tag)										   \
		{																		   \
			if (pField->DataCenter == dc)										   \
			{																	   \
				COPY_FTD_ENTITY(tag, &rspField, pField);						   \
				rspField.OperationType = 1;										   \
				AddRspWithField < FTD_RSP(tag) >								   \
					(															   \
						&m_pkgSend, &rspField, pSession, pFTDCPackage, FTD_RSP_ID( \
								tag)											   \
					);															   \
			}																	   \
		}																		   \
																			\
		ITERATE_MEMORYDB_BYALL_END(tag) LogPkg(									   \
				&m_pkgSend,														   \
				g_bufferLogger,													   \
				g_traceLog);													   \
		pSession->SendRequestPackage(&m_pkgSend);								   \
		CCommonFTDRsp::Instance()->SendSuccRsp(									   \
				pSession,														   \
				&m_pkgSend,														   \
				pFTDCPackage,													   \
				FTD_RSP_ID(tag));												   \
	} while (0)

// 从内存数据库中获取与数据中心匹配的信息，并发送给当前连接
#define SEND_CONFIG_DC_SPEC_BY_KEY(tag, dc, key)								   \
	do																			   \
	{																			   \
		m_pkgSend.PrepareResponse(												   \
				pFTDCPackage,													   \
				FTD_RSP_ID(tag),												   \
				FTDC_CHAIN_CONTINUE,											   \
				FTD_VERSION);													   \
		FTD_RSP(tag) rspField;													   \
		ITERATE_MEMORYDB_BYALL_BEGIN(tag)										   \
		{																		   \
			if (GetCenterFromOID((const char *)pField->key) == dc)				   \
			{																	   \
				COPY_FTD_ENTITY(tag, &rspField, pField);						   \
				rspField.OperationType = 1;										   \
				AddRspWithField < FTD_RSP(tag) >								   \
					(															   \
						&m_pkgSend, &rspField, pSession, pFTDCPackage, FTD_RSP_ID( \
								tag)											   \
					);															   \
			}																	   \
		}																		   \
																			\
		ITERATE_MEMORYDB_BYALL_END(tag) LogPkg(									   \
				&m_pkgSend,														   \
				g_bufferLogger,													   \
				g_traceLog);													   \
		pSession->SendRequestPackage(&m_pkgSend);								   \
		CCommonFTDRsp::Instance()->SendSuccRsp(									   \
				pSession,														   \
				&m_pkgSend,														   \
				pFTDCPackage,													   \
				FTD_RSP_ID(tag));												   \
	} while (0)
#define SEND_ERROR_RSP_TO_SNMP(tag, session, req, rsp, field, msg) \
	do															   \
	{															   \
		static CFTDRspInfoField errorInfo;						   \
		errorInfo.ErrorID = -1;									   \
		errorInfo.ErrorMsg = msg;								   \
		BUILD_LAST_PKG_BY_FIELD(RSP, tag, req, rsp, field);		   \
		FTDC_ADD_FIELD(rsp, &errorInfo);						   \
		session->SendRequestPackage(rsp);						   \
	} while (0)

CManagerServer::SessionMgr::SessionMgr(CReactor * pReactor)
{
	assert(pReactor && "SessionMgr need a valid CReactor!\n");

	m_sessions[DC_BeiJing].m_timer = new SessionTimmer(pReactor, DC_BeiJing, this);
	m_sessions[DC_PuDian].m_timer = new SessionTimmer(pReactor, DC_PuDian, this);
	m_sessions[DC_ZhangJiang].m_timer = new SessionTimmer(pReactor, DC_ZhangJiang, this);
}

int timeout;
static CFTDCPackage pkg;

void CManagerServer::SessionMgr::AddSession(
	char datacenter,
	const string &id,
	CFTDCSession *session)
{
	assert(
		datacenter == DC_BeiJing
		||	datacenter == DC_PuDian
		||	datacenter == DC_ZhangJiang);

	static bool initFlag = false;
	if (!initFlag)
	{
		pkg.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		timeout = ConfigInfo::Instance().GetSnmpTimeout();	// 以秒为单位的超时时间
		initFlag = true;
	}

	LOG_DEBUG(
		"SNMP_Mgr:\tSession from data center (%c) id(%s) connected.\n",
		datacenter,
		id.c_str());

	ScopeLock<CMutex> lock(m_lock);

	SessionData &data = m_sessions[datacenter];
	if (data.m_sessionSet.size() > 0
	&&	data.m_sessionSet.begin()->m_serverType == CDeployConfig::ST_Master)
	{
		// 当前中心有master session，故新来的session均为slavery
		SessionInfo info(datacenter, id, session, CDeployConfig::ST_Slavery);
		m_sessions[datacenter].m_sessionSet.push_back(info);

		LOG_DEBUG(
			"session from data center (%c) id(%s) is a slavery.\n",
			datacenter,
			id.c_str());

		pkg.PreparePackage(
				FTD_TID_RspServerTypeTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRspServerTypeField field;
		field.IsMaster = 0;
		FTDC_ADD_FIELD(&pkg, &field);
		LogPkg(&pkg, g_bufferLogger, g_traceLog);
		session->SendRequestPackage(&pkg);
	}
	else
	{
		if (m_sessions[datacenter].m_timer->Idle())
		{
			LOG_DEBUG(
				"don't know session from data center (%c) id(%s), start TT_WAIT_MASTER timer.\n",
				datacenter,
				id.c_str());
			m_sessions[datacenter].m_timer->SetTimer(TT_WAIT_MASTER, timeout);
		}

		SessionInfo info(datacenter, id, session);
		m_sessions[datacenter].m_sessionSet.push_back(info);
	}
}

void CManagerServer::SessionMgr::RemoveSession(CFTDCSession *session)
{
	ScopeLock<CMutex> lock(m_lock);

	for (SessionMap::iterator i = m_sessions.begin();
		 i != m_sessions.end();
		 i++)
	{
		SessionData &data = i->second;
		for (SessionSet::iterator j = data.m_sessionSet.begin();
			 j != data.m_sessionSet.end();
			 j++)
		{
			if (session == j->m_session)
			{
				// A master session is disconnected. We need wait a while to make sure we could change master session.
				if (j->m_serverType == CDeployConfig::ST_Master)
				{
					assert(
						j == data.m_sessionSet.begin()
						&&	"master session should be the first node of SessionSet!");

					data.m_losedMaster = new SessionInfo(
							j->m_dc,
							j->m_id,
							j->m_session,
							j->m_serverType);

					if (data.m_timer->Idle())
					{
						LOG_DEBUG(
							"SNMP_Mgr:\t Master session from data center (%c) id(%s) disconnected, start TT_WAIT_MASTER timer.\n",
							j->m_dc,
							j->m_id.c_str());
						data.m_timer->SetTimer(TT_WAIT_MASTER, timeout);
					}
				}
				else
				{
					LOG_DEBUG(
						"SNMP_Mgr:\t Master session from data center (%c) id(%s) disconnected, It's a slavery.\n",
						j->m_dc,
						j->m_id.c_str());
				}

				data.m_sessionSet.erase(j);
				return;
			}
		}
	}
}

void CManagerServer::SessionMgr::NotifyAllSessions(CFTDCPackage *pkg)
{
	ScopeLock<CMutex> lock(m_lock);

	for (SessionMap::iterator i = m_sessions.begin();
		 i != m_sessions.end();
		 i++)
	{
		for (SessionSet::iterator j = i->second.m_sessionSet.begin();
			 j != i->second.m_sessionSet.end();
			 j++)
		{
			j->m_session->SendRequestPackage(pkg);
			pkg->Pop(FTDCHLEN);
		}
	}

	LogPkg(pkg, g_bufferLogger, g_traceLog);
}

void CManagerServer::SessionMgr::NotifySessions(char dataCenter, CFTDCPackage *pkg)
{
	ScopeLock<CMutex> lock(m_lock);

	SessionMap::iterator iterFindDataCenter = m_sessions.find(dataCenter);
	if (iterFindDataCenter!=m_sessions.end())
	{
		for (SessionSet::iterator j = iterFindDataCenter->second.m_sessionSet.begin();
			j != iterFindDataCenter->second.m_sessionSet.end();
			j++)
		{
			j->m_session->SendRequestPackage(pkg);
			pkg->Pop(FTDCHLEN);
		}
	}

	LogPkg(pkg, g_bufferLogger, g_traceLog);
}

void CManagerServer::SessionMgr::NotifySessions(
	CFTDCPackage *pkg,
	CDataCenterFlagType dc)
{
	ScopeLock<CMutex> lock(m_lock);

	SessionMap::iterator it = m_sessions.find(dc.getValue());
	if (it == m_sessions.end())
	{
		LOG_WARNING("Invalid data center (%c)\n", dc.getValue());
		return;
	}

	for (SessionSet::iterator j = it->second.m_sessionSet.begin();
		 j != it->second.m_sessionSet.end();
		 j++)
	{
		j->m_session->SendRequestPackage(pkg);
		pkg->Pop(FTDCHLEN);
	}

	LogPkg(pkg, g_bufferLogger, g_traceLog);
}

bool CManagerServer::SessionMgr::RequestSnmp(CFTDCPackage *pkg, char datacenter)
{
	m_lock.Lock();

	bool rtn = true;

	SessionSet	&s = m_sessions[datacenter].m_sessionSet;

	if (s.size() > 0 && s.begin()->m_serverType != CDeployConfig::ST_Master)
	{
		// 当前还未决定Master Session。有Timmer在决定Master Session。
		m_lock.UnLock();
		SLEEP_SECONDS(1);

		// 重新迭代SessionSet，因为SessionSet可能被修改
		rtn = RequestSnmp(pkg, datacenter);
	}
	else if (s.size() > 0)
	{
		// 有主Master连接情况。
		for (SessionSet::iterator j = s.begin(); j != s.end(); j++)
		{
			j->m_session->SendRequestPackage(pkg);
			pkg->Pop(FTDCHLEN);
		}

		LogPkg(pkg, g_bufferLogger, g_traceLog);

		m_lock.UnLock();
	}
	else
	{
		// 当前数据中心没有snmp连接
		rtn = false;

		m_lock.UnLock();
	}

	return rtn;
}

void CManagerServer::SessionMgr::SessionTimmer::SetTimer(
	int nIDEvent,
	int nElapse)
{
	// CEventHandler::SetTimer声明@param nElapse 定时周期(秒)，但实际上是用毫秒做单位；
	// 而我们的SessionTimmer::SetTimer中nElapse以秒为单位，故有下面的换算。
	CEventHandler::SetTimer(nIDEvent, nElapse * 1000);
	m_started = true;

	if (nIDEvent == TT_WAIT_MASTER)
	{
		SetTimer(TT_CHECK_MASTER, 1);
	}
}

void CManagerServer::SessionMgr::SessionTimmer::KillTimer(int nIDEvent)
{
	CEventHandler::KillTimer(nIDEvent);
	m_started = false;
}

void CManagerServer::SessionMgr::SessionTimmer::OnTimer(int nIDEvent)
{
	switch (nIDEvent)
	{
		case TT_WAIT_MASTER:	// TT_WAIT_MASTER是决定MASTER连接的总的超时时间
			{
				SessionData &data = m_mgr->m_sessions[m_dc];
				const SessionSet &s = data.m_sessionSet;

				if (s.size() > 0)
				{
					selectMaster();
					cleanUnknow();
				}
				else
				{
					LOG_DEBUG("TT_WAIT_MASTER: Empty session set\n");
				}

				KillTimer(TT_WAIT_MASTER);
				KillTimer(TT_CHECK_MASTER);
			}

			break;
		case TT_CHECK_MASTER:	//
			{
				SessionData &data = m_mgr->m_sessions[m_dc];
				const SessionSet &s = data.m_sessionSet;

				bool hasMaster = false;
				if (s.size() > 0 && checkMaster())
				{
					cleanUnknow();
					KillTimer(TT_CHECK_MASTER);
					KillTimer(TT_WAIT_MASTER);
				}
			}

			break;
		default:
			assert(false && "Invalid timer type!");
			break;
	}
}

// selectMaster返回false，则表明该中心目前没有session连接
bool CManagerServer::SessionMgr::SessionTimmer::selectMaster(void)
{
	SessionData &data = m_mgr->m_sessions[m_dc];

	// 从队列中取出应该为Master的连接，选择策略如下（优先级依次降低）：
	// 1、先前一个断开的Master连接，在超时时间内又连接上，其仍应该为Master连接。
	// 2、如果DeployConfig中推荐的该中心snmp主连接存在，其为Master连接。
	// 3、最早连接上的为Master连接
	bool hasMaster = false;

	do
	{
		// 1
		hasMaster = losedMasterBack(data);

		if (hasMaster)
		{
			break;
		}

		// 2
		hasMaster = hasDefaultMaster(data);

		if (hasMaster)
		{
			break;
		}

		// 3
		hasMaster = theFirstSession(data);
	} while (0);

	if (hasMaster)
	{
		synDataToNewMasterSession(data);
		notifyMasterSession(data);

		LOG_DEBUG(
			"TT_WAIT_MASTER: We select a Master dc(%c) id(%s)\n",
			data.m_sessionSet.begin()->m_dc,
			data.m_sessionSet.begin()->m_id.c_str());
	}

	if (data.m_losedMaster)
	{
		delete data.m_losedMaster;
		data.m_losedMaster = NULL;
	}

	return hasMaster;
}

bool CManagerServer::SessionMgr::SessionTimmer::checkMaster(void)
{
	SessionData &data = m_mgr->m_sessions[m_dc];
	SessionSet	&s = data.m_sessionSet;

	// 定时检查Master连接，检查策略如下（优先级依次降低）：
	// 1、先前一个断开的Master连接，在超时时间内又连接上，其仍应该为Master连接。
	// 2、如果DeployConfig中推荐的该中心snmp主连接存在，其为Master连接。
	bool hasMaster = false;

	if (data.m_losedMaster)
	{
		hasMaster = losedMasterBack(data);

		if (hasMaster)
		{
			LOG_DEBUG(
				"TT_WAIT_MASTER: Master come back dc(%c) id(%s)\n",
				data.m_sessionSet.begin()->m_dc,
				data.m_sessionSet.begin()->m_id.c_str());
		}
	}
	else
	{
		hasMaster = hasDefaultMaster(data);

		if (hasMaster)
		{
			LOG_DEBUG(
				"TT_WAIT_MASTER: Using default Master dc(%c) id(%s)\n",
				data.m_sessionSet.begin()->m_dc,
				data.m_sessionSet.begin()->m_id.c_str());
		}
	}

	if (hasMaster)
	{
		synDataToNewMasterSession(data);
		notifyMasterSession(data);

		if (data.m_losedMaster)
		{
			delete data.m_losedMaster;
			data.m_losedMaster = NULL;
		}
	}

	return hasMaster;
}

bool CManagerServer::SessionMgr::SessionTimmer::losedMasterBack(
	SessionData &data)
{
	bool hasMaster = false;

	SessionSet	&s = data.m_sessionSet;

	if (data.m_losedMaster)
	{
		char dc = data.m_losedMaster->m_dc;
		string id = data.m_losedMaster->m_id;

		for (SessionSet::iterator it = s.begin(); it != s.end(); it++)
		{
			if (it->m_dc == dc && it->m_id == id)
			{
				SessionInfo info = *it;
				info.m_serverType = CDeployConfig::ST_Master;

				s.erase(it);
				s.push_front(info);

				hasMaster = true;
				break;
			}
		}
	}

	return hasMaster;
}

bool CManagerServer::SessionMgr::SessionTimmer::hasDefaultMaster(
	SessionData &data)
{
	bool hasMaster = false;

	SessionSet	&s = data.m_sessionSet;

	for (SessionSet::iterator it = s.begin(); it != s.end(); it++)
	{
		if (ConfigInfo::Instance().GetSnmpCfgInfo(
				it->m_id).m_serverType == CDeployConfig::ST_Master)
		{
			SessionInfo info = *it;
			info.m_serverType = CDeployConfig::ST_Master;

			s.erase(it);
			s.push_front(info);

			hasMaster = true;
			break;
		}
	}

	return hasMaster;
}

bool CManagerServer::SessionMgr::SessionTimmer::theFirstSession(
	SessionData &data)
{
	bool hasMaster = false;

	SessionSet	&s = data.m_sessionSet;
	if (s.size() > 0)
	{
		s.begin()->m_serverType = CDeployConfig::ST_Master;

		hasMaster = true;
	}

	return hasMaster;
}


void CManagerServer::SessionMgr::SessionTimmer::synDataToNewMasterSession(SessionData &data)
{
	SessionSet	&s = data.m_sessionSet;
	
	map<int, taskStatus>::iterator	it = g_taskStatus.begin();
	for (; it != g_taskStatus.end(); it++)
	{
		{
			pkg.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskResultTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
	
			CFTDRspQryNetMonitorTaskResultField tfield;
			tfield.Task_ID = it->first;
			tfield.OperateTime = it->second.times;
			FTDC_ADD_FIELD(&pkg, &tfield);
	
			LogPkg(&pkg, g_bufferLogger, g_traceLog);
			s.begin()->m_session->SendRequestPackage(&pkg);
		}
	
		if (it->second.status != -1)
		{
			pkg.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskInfoTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
	
			CFTDRspQryNetMonitorTaskInfoField tfield;
			tfield.OperationType = 2;
			tfield.ID = it->first;
			tfield.TaskStatus = it->second.status;
			tfield.ValidFlag = it->second.delay;
			FTDC_ADD_FIELD(&pkg, &tfield);
	
			LogPkg(&pkg, g_bufferLogger, g_traceLog);
			s.begin()->m_session->SendRequestPackage(&pkg);
		}
	}

}



void CManagerServer::SessionMgr::SessionTimmer::notifyMasterSession(
	SessionData &data)
{
	SessionSet	&s = data.m_sessionSet;

	pkg.PreparePackage(
			FTD_TID_RspServerTypeTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRspServerTypeField field;
	field.IsMaster = 1;
	FTDC_ADD_FIELD(&pkg, &field);

	LogPkg(&pkg, g_bufferLogger, g_traceLog);
	s.begin()->m_session->SendRequestPackage(&pkg);
}

void CManagerServer::SessionMgr::SessionTimmer::cleanUnknow(void)
{
	SessionSet	&s = m_mgr->m_sessions[m_dc].m_sessionSet;

	// 队列头为正在工作的Master连接，后续其它还未决定角色的连接全为Slavery连接
	for (SessionSet::iterator it = s.begin(); it != s.end(); it++)
	{
		if (it->m_serverType == CDeployConfig::ST_Invalid)
		{
			it->m_serverType = CDeployConfig::ST_Slavery;

			// notify snmp
			pkg.PreparePackage(
					FTD_TID_RspServerTypeTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRspServerTypeField field;
			field.IsMaster = 0;
			FTDC_ADD_FIELD(&pkg, &field);
			LogPkg(&pkg, g_bufferLogger, g_traceLog);
			it->m_session->SendRequestPackage(&pkg);
		}
	}
}

CManagerServer::CManagerServer(CReactor *pReactor) :
	CSessionFactory(pReactor, 10),
	m_sessionMgr(pReactor)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_dbHandler.SetOperateMaster("CManagerServer",NULL);
}

bool CManagerServer::Init(void)
{
	LOG_INFO("CManagerServer connect DB:\t");
	return m_dbHandler.Open(
			ConfigInfo::Instance().DBIp(),
			ConfigInfo::Instance().DBPort(),
			ConfigInfo::Instance().DBName(),
			ConfigInfo::Instance().DBUser(),
			ConfigInfo::Instance().DBPwd());
}

CSession *CManagerServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CManagerServer::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);

	LOG_INFO(
		"%s CManagerServer::OnSessionConnected: %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		CurrentTime(),
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());
}

void CManagerServer::OnSessionDisconnected(CSession *pSession, int nReason) // 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	LOG_INFO(
		"CManagerServer::OnSessionDisconnected: %0x %s",
		(CFTDCSession *)pSession,
		CurrentTime());

	// 删除失效连接
	m_sessionMgr.RemoveSession((CFTDCSession *)pSession);
}

int CManagerServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	LogPkg(pFTDCPackage, g_bufferLogger, g_recvPkgLogger);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqConfigLoginTopic:
			OnReqSnmpLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceTopic:
			OnRspQryNetDeviceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceLinkedTopic:
			OnRspQryNetDeviceLinkedTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetInterfaceTopic:
			OnRspQryNetInterfaceTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetModuleTopic:
			OnRspQryNetModuleTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetDeviceDetectTopic:
			OnRspQryNetDeviceDetectTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RspQryNetMonitorTaskInfoTopic:
			OnRspQryNetMonitorTaskInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskInfoTopic:
			OnRtnNetMonitorTaskInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnNetMonitorTaskResultTopic:
			OnRtnNetMonitorTaskResultTopic(pFTDCPackage, pSession);
			break;
		default:
			break;
	}

	return 0;
}

static int s_party_link_status_info_count = 0;

static void initPartyLinkStatusInfoCount(SACommand &records, void *data)
{
	s_party_link_status_info_count = records.Field(1).asLong();
}

void CManagerServer::OnReqSnmpLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqConfigLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	// TODO
	// authorize fieldLogin.Authorization
	char dataCenter = fieldLogin.DataCenter;
	if (dataCenter != DC_BeiJing
	&&	dataCenter != DC_PuDian
	&&	dataCenter != DC_ZhangJiang)
	{
		LOG_WARNING(
			"Invalid dataCenter flag %c. valied flag are BeiJing(%c), PuDian(%c), ZhangJiang(%c)\n",
			dataCenter,
			DC_BeiJing,
			DC_PuDian,
			DC_ZhangJiang);

		CCommonFTDRsp::Instance()->SendLastErroRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspConfigLoginTopic,
				"Invalid dataCenter flag");
		return;
	}

	bool sendConfig = fieldLogin.HasConfig ? false : true;

	if (sendConfig)
	{
		SEND_CONFIG(NetArea);
		SEND_CONFIG(NetSubArea);
		SEND_CONFIG(NetSubAreaIP);
		SEND_CONFIG(NetDeviceType);
		SEND_CONFIG(NetOID);
		SEND_CONFIG(NetDeviceCategory);
		SEND_CONFIG(NetManufactory);
		SEND_CONFIG(NetCommunity);
		SEND_CONFIG(NetGeneralOID);
		SEND_CONFIG(NetMonitorType);
		SEND_CONFIG_DC_SPEC_BY_KEY(NetDevice, dataCenter, ObjectID);
		SEND_CONFIG_DC_SPEC_BY_KEY(NetDeviceLinked, dataCenter, NetObjectID);
		SEND_CONFIG_DC_SPEC_BY_KEY(NetInterface, dataCenter, ObjectID);
		SEND_CONFIG_DC_SPEC_BY_KEY(NetModule, dataCenter, ObjectID);
		SEND_CONFIG(NetTimePolicy);
		SEND_CONFIG_DC_SPEC_BY_KEY(NetGatherTask, dataCenter, ObjectID);
		SEND_CONFIG(NetMonitorCommandType);
		SEND_CONFIG(NetMonitorActionGroup);
		SEND_CONFIG(NetMonitorDeviceGroup);
		SEND_CONFIG_DC_SPEC(NetMonitorTaskObjectSet, dataCenter);
		SEND_CONFIG(NetMonitorActionAttr);
		SEND_CONFIG(NetMonitorTaskInfo);
		SEND_CONFIG(NetMonitorDeviceTask);
		SEND_CONFIG(NetPartyLinkInfo);
		SEND_CONFIG(NetMonitorTaskInstAttrs);
		SEND_CONFIG(NetBaseLineTask);

		// 发送会员链路状态信息
		string sql = "select count(*) from t_SysNetPartyLinkStatusInfo";
		m_dbHandler.SearchRecord(sql, initPartyLinkStatusInfoCount);

		CFTDRspQryNetPartyLinkStatusInfoField dummyRspField;
		dummyRspField.OperationType = s_party_link_status_info_count;

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryNetPartyLinkStatusInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &dummyRspField);
		pSession->SendRequestPackage(&m_pkgSend);

		///发送任务状态信息
		map<int, taskStatus>::iterator	it = g_taskStatus.begin();
		for (; it != g_taskStatus.end(); it++)
		{
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);

				CFTDRspQryNetMonitorTaskResultField tfield;
				tfield.Task_ID = it->first;
				tfield.OperateTime = it->second.times;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);

				LogPkg(&m_pkgSend, g_bufferLogger, g_traceLog);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			if (it->second.status != -1)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskInfoTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);

				CFTDRspQryNetMonitorTaskInfoField tfield;
				tfield.OperationType = 2;
				tfield.ID = it->first;
				tfield.TaskStatus = it->second.status;
				tfield.ValidFlag = it->second.delay;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);

				LogPkg(&m_pkgSend, g_bufferLogger, g_traceLog);
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}

	char id[6];
	SNPRINTF(id, 6, "%d", fieldLogin.ID.getValue());

	m_sessionMgr.AddSession(dataCenter, id, pSession);

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspConfigLoginTopic);
}

void CManagerServer::OnRspQryNetDeviceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetDeviceField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRspQryNetDeviceField, field)
	{
		CSysNetDevice *pfield = pMemoryDB->m_SysNetDeviceFactory->findByObjectID(
				field.ObjectID);
		if (pfield)
		{
			//continue;
			field.ID = pfield->ID;
			bool dbResult;
			UPDATE_OBJ_TO_DB(NetDevice, field, "ID", m_dbHandler, dbResult);
			if (dbResult)
			{
				UPDATAE_RECORD_FROM_MEMORYDB(NetDevice,pfield, field);
				
				CCommonFTDRsp::Instance()->SendSuccRsp(
					pSession,
					&m_pkgSend,
					pFTDCPackage,
					FTD_RSP_ID(NetDevice));

				field.OperationType = OT_UPDATE;
				BUILD_CONTINUE_PKG_BY_FIELD(
					RTN,
					NetDevice,
					pFTDCPackage,
					&m_pkgSend,
					field);

				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
		}
		else
		{

			field.ID = g_idMaker[FTD_SysName(NetDevice)]++;

			bool dbResult;
			INSERT_OBJ_TO_DB(NetDevice, field, m_dbHandler, dbResult);
			if (dbResult)
			{
				INSERT_RECORD_INTO_MEMORYDB(NetDevice, field);

				CCommonFTDRsp::Instance()->SendSuccRsp(
					pSession,
					&m_pkgSend,
					pFTDCPackage,
					FTD_RSP_ID(NetDevice));

				field.OperationType = OT_ADD;
				BUILD_CONTINUE_PKG_BY_FIELD(
					RTN,
					NetDevice,
					pFTDCPackage,
					&m_pkgSend,
					field);

				//SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				// modify by bian.xb 2014.04.14
				// notifysnmp to take a parameter of datacenter
				SessionProxy::Instance().NotifySnmp(GetCenterFromOID((const char *)field.ObjectID), &m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
			else
			{
				// 写入数据库出错，将出错信息发给snmp
				SEND_ERROR_RSP_TO_SNMP(
					NetDevice,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					field,
					"Insert DB failed");
			}
		}
	}
}

void CManagerServer::OnRspQryNetDeviceLinkedTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetDeviceLinkedField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRspQryNetDeviceLinkedField, field)
	{
		bool exist = false;

		ITERATE_MEMORYDB_BYKEY_BEGIN(
			NetDeviceLinked,
			NetObjectID,
			field,
			NetObjectID)
		{
			if (pField->LinkNetObjectID == field.LinkNetObjectID)
			{
				exist = true;
				break;
			}
		}

		ITERATE_MEMORYDB_BYKEY_END(NetDeviceLinked, NetObjectID) if (exist)
		{
			continue;
		}

		ITERATE_MEMORYDB_BYKEY_BEGIN(
			NetDeviceLinked,
			LinkNetObjectID,
			field,
			LinkNetObjectID)
		{
			if (pField->LinkNetObjectID == field.LinkNetObjectID)
			{
				exist = true;
				break;
			}
		}

		ITERATE_MEMORYDB_BYKEY_END(NetDeviceLinked, LinkNetObjectID) if (exist)
		{
			continue;
		}

		field.ID = g_idMaker[FTD_SysName(NetDeviceLinked)]++;

		bool dbResult;
		INSERT_OBJ_TO_DB(NetDeviceLinked, field, m_dbHandler, dbResult);
		if (dbResult)
		{
			INSERT_RECORD_INTO_MEMORYDB(NetDeviceLinked, field);

			field.OperationType = OT_ADD;
			BUILD_CONTINUE_PKG_BY_FIELD(
				RTN,
				NetDeviceLinked,
				pFTDCPackage,
				&m_pkgSend,
				field);

			SessionProxy::Instance().NotifySnmp(&m_pkgSend);
			SessionProxy::Instance().NotifyFront(&m_pkgSend);
			SessionProxy::Instance().NotifySync(&m_pkgSend);
		}
		else
		{
			SEND_ERROR_RSP_TO_SNMP(
				NetDeviceLinked,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				field,
				"Insert DB failed");
		}
	}
}

void CManagerServer::OnRspQryNetInterfaceTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetInterfaceField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRspQryNetInterfaceField, field)
	{
		CSysNetInterface *pfield = pMemoryDB->m_SysNetInterfaceFactory->
			findByObjectID(field.ObjectID);
		if (pfield)
		{
			//continue;
			field.ID = pfield->ID;
			CSysNetDevice *pdfield = pMemoryDB->m_SysNetDeviceFactory->
			findByObjectID(field.DeviceObjectID);
			if (pdfield)
			{
				field.DeviceID = pdfield->ID;
			}
			bool dbResult;
			UPDATE_OBJ_TO_DB(NetInterface, field, "ID", m_dbHandler, dbResult);
			if (dbResult)
			{
				UPDATAE_RECORD_FROM_MEMORYDB(NetInterface,pfield, field);

				CCommonFTDRsp::Instance()->SendSuccRsp(
					pSession,
					&m_pkgSend,
					pFTDCPackage,
					FTD_RSP_ID(NetInterface));

				field.OperationType = OT_UPDATE;
				BUILD_CONTINUE_PKG_BY_FIELD(
					RTN,
					NetInterface,
					pFTDCPackage,
					&m_pkgSend,
					field);

				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
		}
		else
		{
			CSysNetDevice *pdfield = pMemoryDB->m_SysNetDeviceFactory->
			findByObjectID(field.DeviceObjectID);
			if (pdfield)
			{
				field.DeviceID = pdfield->ID;
			}

			field.ID = g_idMaker[FTD_SysName(NetInterface)]++;

			bool dbResult;
			INSERT_OBJ_TO_DB(NetInterface, field, m_dbHandler, dbResult);

			if (dbResult)
			{
				INSERT_RECORD_INTO_MEMORYDB(NetInterface, field);

				field.OperationType = OT_ADD;
				BUILD_CONTINUE_PKG_BY_FIELD(
					RTN,
					NetInterface,
					pFTDCPackage,
					&m_pkgSend,
					field);

				//SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifySnmp(GetCenterFromOID((const char *)field.ObjectID), &m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
			else
			{
				SEND_ERROR_RSP_TO_SNMP(
					NetInterface,
					pSession,
					pFTDCPackage,
					&m_pkgSend,
					field,
					"Insert DB failed");
			}
		}
	}
}

void CManagerServer::OnRspQryNetModuleTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRspQryNetModuleField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRspQryNetModuleField, field)
	{
		CSysNetModule *pfield = pMemoryDB->m_SysNetModuleFactory->findByObjectID(
				field.ObjectID);
		if (pfield)
		{
			//continue;
			field.ID = pfield->ID;
			bool dbResult;
			UPDATE_OBJ_TO_DB(NetModule, field, "ID", m_dbHandler, dbResult);
			if (dbResult)
			{
				UPDATAE_RECORD_FROM_MEMORYDB(NetModule,pfield, field);

				CCommonFTDRsp::Instance()->SendSuccRsp(
					pSession,
					&m_pkgSend,
					pFTDCPackage,
					FTD_RSP_ID(NetModule));

				field.OperationType = OT_UPDATE;
				BUILD_CONTINUE_PKG_BY_FIELD(
					RTN,
					NetModule,
					pFTDCPackage,
					&m_pkgSend,
					field);

				SessionProxy::Instance().NotifySnmp(&m_pkgSend);
				SessionProxy::Instance().NotifyFront(&m_pkgSend);
				SessionProxy::Instance().NotifySync(&m_pkgSend);
			}
		}

		CSysNetDevice *pdfield = pMemoryDB->m_SysNetDeviceFactory->
			findByObjectID(field.DeviceObjectID);
		if (pdfield)
		{
			field.DeviceID = pdfield->ID;
		}

		field.ID = g_idMaker[FTD_SysName(NetModule)]++;

		bool dbResult;
		INSERT_OBJ_TO_DB(NetModule, field, m_dbHandler, dbResult);
		if (dbResult)
		{
			INSERT_RECORD_INTO_MEMORYDB(NetModule, field);

			field.OperationType = OT_ADD;
			BUILD_CONTINUE_PKG_BY_FIELD(
				RTN,
				NetModule,
				pFTDCPackage,
				&m_pkgSend,
				field);

			//SessionProxy::Instance().NotifySnmp(&m_pkgSend);
			SessionProxy::Instance().NotifySnmp(GetCenterFromOID((const char *)field.ObjectID), &m_pkgSend);
			SessionProxy::Instance().NotifyFront(&m_pkgSend);
			SessionProxy::Instance().NotifySync(&m_pkgSend);
		}
		else
		{
			SEND_ERROR_RSP_TO_SNMP(
				NetModule,
				pSession,
				pFTDCPackage,
				&m_pkgSend,
				field,
				"Insert DB failed");
		}

		///生成相应的采集任务
		{
			CSysNetDevice *pDeviceField = pMemoryDB->m_SysNetDeviceFactory->
				findByOne(field.DeviceID);
			if (pDeviceField)
			{
				CSysNetMonitorAttrType	*pAttrField = pMemoryDB->
					m_SysNetMonitorAttrTypeFactory->startFindByAll();
				while (pAttrField)
				{
					if (pAttrField->MonitorType_ID == field.
							MonitorType_ID
					&&	pDeviceField->MANUFACTORY_ID == pAttrField->
							MANUFACTORY_ID)
					{
						CFTDRtnNetGatherTaskField tfield;
						memset(&tfield, 0, sizeof(tfield));
						tfield.ID = g_idMaker[FTD_SysName(NetGatherTask)]++;
						tfield.AttrType = pAttrField->AttrType;
						tfield.ObjectID = field.ObjectID;
						tfield.PolicyTypeID = 10;
						tfield.TypeFlag = 2;
						tfield.OperationType = OT_ADD;

						bool dbResult;
						INSERT_OBJ_TO_DB(
							NetGatherTask,
							tfield,
							m_dbHandler,
							dbResult);
						if (dbResult)
						{
							INSERT_RECORD_INTO_MEMORYDB(NetGatherTask, tfield);

							m_pkgSend.PreparePackage(
									FTD_TID_RtnNetGatherTaskTopic,
									FTDC_CHAIN_LAST,
									FTD_VERSION);
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);

							SessionProxy::Instance().NotifySnmp(
									&m_pkgSend,
									GetCenterFromOID(tfield.ObjectID.getValue()));
							SessionProxy::Instance().NotifySync(&m_pkgSend);
						}
					}

					pAttrField = pMemoryDB->m_SysNetMonitorAttrTypeFactory->findNextByAll();
				}

				pMemoryDB->m_SysNetMonitorAttrTypeFactory->endFindByAll();
			}
		}
	}
}

void CManagerServer::OnRspQryNetDeviceDetectTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//TODO 是否要和 OnRspQryNetMonitorTaskInfoTopic 是一致的处理流程
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryNetDeviceDetectTopic,
			pFTDCPackage->GetChain(),
			FTD_VERSION);

	CFTDRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField) > 0)
	{
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	}

	CFTDRspQryNetDeviceDetectField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRspQryNetDeviceDetectField, field)
	{
		CFTDRspQryNetDeviceDetectField tfield;
		CopyRspQryNetDeviceDetectEntity(&tfield, &field);
		assert(FTDC_ADD_FIELD(&m_pkgSend, &tfield) != -1);
	}

	bool lastRsp = (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST) ? true : false;
	SessionProxy::Instance().RespondFront(
			pFTDCPackage->GetRequestId(),
			&m_pkgSend,
			lastRsp);
}

void CManagerServer::OnRspQryNetMonitorTaskInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	m_pkgSend.PreparePackage(
			FTD_TID_RtnNetMonitorTaskInfoTopic,
			pFTDCPackage->GetChain(),
			FTD_VERSION);

	bool lastRsp = (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST) ? true : false;
	SessionProxy::Instance().RespondFront(
			pFTDCPackage->GetRequestId(),
			&m_pkgSend,
			lastRsp);

	m_pkgSend.PreparePackage(
			FTD_TID_RtnNetMonitorTaskInfoTopic,
			pFTDCPackage->GetChain(),
			FTD_VERSION);

	CFTDRspQryNetMonitorTaskInfoField field;
	FOREACH_FIELD(pFTDCPackage, CFTDRspQryNetMonitorTaskInfoField, field)
	{
		CFTDRtnNetMonitorTaskInfoField tfield;
		CopyRtnNetMonitorTaskInfoEntity(&tfield, &field);
		assert(FTDC_ADD_FIELD(&m_pkgSend, &tfield) != -1);

		/*if(tfield.ValidFlag ==29)
		{
			map<int ,taskStatus>::iterator it =g_taskStatus.find(tfield.ID);
			if(it !=g_taskStatus.end())
			{
				it->second.status =tfield.TaskStatus;
				it->second.delay =tfield.OutputPolicy_ID;
			}
			else
			{
				taskStatus ts;
				ts.status =tfield.TaskStatus;
				ts.delay =tfield.OutputPolicy_ID;
				g_taskStatus[tfield.ID] =ts;
			}
		}*/
	}

	SessionProxy::Instance().NotifySnmp(&m_pkgSend);
	SessionProxy::Instance().NotifyFront(&m_pkgSend);
	SessionProxy::Instance().NotifySync(&m_pkgSend);
}

void CManagerServer::OnRtnNetMonitorTaskInfoTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnNetMonitorTaskInfoField tfield;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetMonitorTaskInfoField, tfield)
	{
		map<int, taskStatus>::iterator	it = g_taskStatus.find(tfield.ID);
		if (it != g_taskStatus.end())
		{
			it->second.status = tfield.TaskStatus;
			it->second.delay = tfield.ValidFlag;
		}
		else
		{
			taskStatus ts;
			ts.status = tfield.TaskStatus;
			ts.delay = tfield.ValidFlag;
			ts.times = 0;
			g_taskStatus[tfield.ID] = ts;
		}
	}

	SessionProxy::Instance().NotifySnmp(pFTDCPackage);
	SessionProxy::Instance().NotifyFront(pFTDCPackage);
}

void CManagerServer::OnRtnNetMonitorTaskResultTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	char datacenter;
	CFTDRtnNetMonitorTaskResultField tfield;
	FOREACH_FIELD(pFTDCPackage, CFTDRtnNetMonitorTaskResultField, tfield)
	{
		map<int, taskStatus>::iterator	it = g_taskStatus.find(tfield.Task_ID);
		if (it != g_taskStatus.end())
		{
			it->second.times = tfield.OperateTime;
		}
		else
		{
			taskStatus ts;
			ts.status = -1;
			ts.delay = -1;
			ts.times = tfield.OperateTime;
			g_taskStatus[tfield.Task_ID] = ts;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RtnNetMonitorTaskInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnNetMonitorTaskInfoField field;
		memset(&field, 0, sizeof(field));

		field.ID = tfield.Task_ID;
		if (it != g_taskStatus.end())
		{
			field.TaskStatus = it->second.status;
			field.OutputPolicy_ID = it->second.delay;
			field.ManagerGroup_ID = it->second.times;
		}
		else
		{
			field.TaskStatus = -1;
			field.OutputPolicy_ID = -1;
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);

		SessionProxy::Instance().NotifySnmp(&m_pkgSend);
		SessionProxy::Instance().NotifyFront(&m_pkgSend);
	}
}

