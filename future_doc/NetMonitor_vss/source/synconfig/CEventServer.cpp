/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CEventServer.cpp
///@brief	实现了监听eventcounter端连接处理的类
///@history
///20110818	李志伟		创建该文件
#include "CEventServer.h"
#include "databaseData.h"
#include "UFCopy.h"
#include "CFrontServer.h"
#include "FTDDataHelper.h"
#include "PrjCommon.h"
#include "SessionProxy.h"
#include <CommonFTDMsg.h>
#include "ConfigInfo.h"

// 全局的内存数据库
extern CMemoryDB *pMemoryDB;

map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> > g_eventMap;
int g_eventId = 0;
int g_eventNum = 0;
map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> > g_syslogMap;
int g_syslogId = 0;
int g_syslogNum = 0;
map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> > g_GenLogMap;
int g_GenLogId = 0;
int g_GenLogNum = 0;

map<int, list<CFTDRtnWarningEventField> > g_allEventField;

#ifdef PACKAGE_OUTPUT
extern CFileLogger	*g_recvPkgLogger;	// 数据包输出到文件
extern CBufferLogger *g_bufferLogger;
#endif

//////////////////////////////////////////////////////////////////////////
//add by feng.q
extern int	g_nCntOfdevicetask;

//////////////////////////////////////////////////////////////////////////
#define SEND_CONFIG_TO_EVENT(tag)																			   \
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

	CEventServer::CEventServer(CReactor * pReactor) :
	CSessionFactory(pReactor, 10)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);

	//m_pEventSession = NULL;
}

void CEventServer::NotifyAllSessions(CFTDCPackage *reqPkg)
{
	ScopeLock<CMutex> lock(m_lock);

	for (SessionSet::iterator it = m_sessions.begin();
		 it != m_sessions.end();
		 it++)
	{
		(*it)->SendRequestPackage(reqPkg);
		reqPkg->Pop(FTDCHLEN);
	}

	LogPkg(reqPkg, g_bufferLogger, g_traceLog);
}

CSession *CEventServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CEventServer::OnSessionConnected(CSession *pSession)
{
	CSessionFactory::OnSessionConnected(pSession);
	LOG_INFO(
		"%s CEventServer::OnSessionConnected: %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		CurrentTime(),
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());

	ScopeLock<CMutex> lock(m_lock);
	m_sessions.push_back((CFTDCSession *)pSession);
}

void CEventServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionDisconnected(pSession, nReason);				// 子类调用父类处理连接断开事件
	LOG_INFO(
		"\t CEventServer::OnSessionDisconnected: %0x %s",
		(CFTDCSession *)pSession,
		CurrentTime());

	ScopeLock<CMutex> lock(m_lock);

	SessionSet::iterator it = find(
			m_sessions.begin(),
			m_sessions.end(),
			(CFTDCSession *)pSession);
	if (it != m_sessions.end())
	{
		m_sessions.erase(it);
	}
}

int CEventServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	LogPkg(pFTDCPackage, g_bufferLogger, g_recvPkgLogger);
#endif
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnWarningEventTopic:
			OnRtnWarningEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnSyslogEventTopic:
			OnRtnSyslogEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningActiveChange:
			{
				CFTDReqQryWarningActiveChangeField sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDReqQryWarningActiveChangeField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					m_pkgSend.PreparePackage(
							FTD_TID_ReqQryWarningActiveChange,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &sfield);
					SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);

					itor.Next();
				}
			}

			break;
		case FTD_TID_ReqQryNetRoomTopic:
			{
				CFTDReqQryNetRoomField sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDReqQryNetRoomField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					m_pkgSend.PreparePackage(
							FTD_TID_ReqQryNetRoomTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &sfield);
					SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);

					itor.Next();
				}
			}

			break;
		case FTD_TID_ReqQryWarningEventUpdateTopic:
			{
				CFTDReqQryWarningEventUpdateField sfield;
				CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
						&CFTDReqQryWarningEventUpdateField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					m_pkgSend.PreparePackage(
							FTD_TID_ReqQryWarningEventUpdateTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &sfield);
					SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);

					map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> >::iterator
						itOid = g_eventMap.find(sfield.ObjectID);
					if (itOid != g_eventMap.end())
					{
						map<CTypeObjectIDType, eventNod>::iterator	itEventName =
							itOid->second.find(sfield.EventName);
						if (itEventName != itOid->second.end())
						{
							itEventName->second.processFlag = sfield.ProcessFlag;
						}
					}

					itor.Next();
				}
			}

		default:
			break;
	}

	return 0;
}

void CEventServer::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	LOG_INFO(
		"CEventServer::OnReqUserLogin:user=%s password=%s \n",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);

	///向事件服务器发送配置表
	SEND_CONFIG_TO_EVENT(NetArea);
	SEND_CONFIG_TO_EVENT(NetSubArea);
	SEND_CONFIG_TO_EVENT(NetSubAreaIP);
	SEND_CONFIG_TO_EVENT(NetDeviceType);
	SEND_CONFIG_TO_EVENT(NetOID);
	SEND_CONFIG_TO_EVENT(NetDeviceCategory);
	SEND_CONFIG_TO_EVENT(NetManufactory);
	SEND_CONFIG_TO_EVENT(NetCommunity);
	SEND_CONFIG_TO_EVENT(NetGeneralOID);
	SEND_CONFIG_TO_EVENT(NetMonitorType);
	SEND_CONFIG_TO_EVENT(NetMonitorAttrType);
	SEND_CONFIG_TO_EVENT(NetEventExpr);
	SEND_CONFIG_TO_EVENT(NetEventLevel);
	SEND_CONFIG_TO_EVENT(NetDevice);
	SEND_CONFIG_TO_EVENT(NetDeviceLinked);
	SEND_CONFIG_TO_EVENT(NetInterface);
	SEND_CONFIG_TO_EVENT(NetModule);
	SEND_CONFIG_TO_EVENT(NetGatherTask);
	SEND_CONFIG_TO_EVENT(NetMonitorCommandType);
	SEND_CONFIG_TO_EVENT(NetMonitorActionGroup);
	SEND_CONFIG_TO_EVENT(NetMonitorDeviceGroup);
	SEND_CONFIG_TO_EVENT(NetMonitorTaskObjectSet);
	SEND_CONFIG_TO_EVENT(NetTimePolicy);
	SEND_CONFIG_TO_EVENT(NetMonitorActionAttr);
	SEND_CONFIG_TO_EVENT(NetMonitorTaskInfo);
	SEND_CONFIG_TO_EVENT(NetMonitorTaskInstAttrs);
	SEND_CONFIG_TO_EVENT(NetPartyLinkInfo);
	SEND_CONFIG_TO_EVENT(NetBaseLine);

	//SEND_CONFIG_TO_EVENT(NetMonitorDeviceTask);
	//单独发送一条记录
	{
		int nDeviceCnt = 0;
		CFTDRspQryNetMonitorDeviceTaskField rspField;
		CSysNetMonitorDeviceTask *pField = pMemoryDB->
			m_SysNetMonitorDeviceTaskFactory->startFindByAll();
		while (pField)
		{
			m_pkgSend.PrepareResponse(
					pFTDCPackage,
					FTD_TID_RspQryNetMonitorDeviceTaskTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			memset(&rspField, 0, sizeof(rspField));

			CopySysNetMonitorDeviceTaskEntity(&rspField, pField);
			FTDC_ADD_FIELD(&m_pkgSend, &rspField);

			LogPkg(&m_pkgSend, g_bufferLogger, g_traceLog);
			pSession->SendRequestPackage(&m_pkgSend);
			nDeviceCnt++;
			pField = pMemoryDB->m_SysNetMonitorDeviceTaskFactory->findNextByAll();
		}

		CCommonFTDRsp::Instance()->SendSuccRsp(
				pSession,
				&m_pkgSend,
				pFTDCPackage,
				FTD_TID_RspQryNetMonitorDeviceTaskTopic);

		LOG_INFO(
			"Feng.q Cnt in Db is %d, Cnt i send is %d\n",
			g_nCntOfdevicetask,
			nDeviceCnt);
	}

	CCommonFTDRsp::Instance()->SendSuccRsp(
			pSession,
			&m_pkgSend,
			pFTDCPackage,
			FTD_TID_RspUserLogin);
}

int getiTime(CTimeType tTime)
{
	string sTime = tTime.getValue();
	return ((sTime[0] - '0') * 10 + (sTime[1] - '0')) * 3600 +
		((sTime[3] - '0') * 10 + (sTime[4] - '0')) * 60 +
			((sTime[6] - '0') * 10 + (sTime[7] - '0'));
}

void CEventServer::OnRtnWarningEventTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	LogPkg(pFTDCPackage, g_bufferLogger, g_traceLog);

	CFTDRtnWarningEventField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		if (sfield.ProcessFlag == "N")
		{
			map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> >::iterator
				it = g_eventMap.find(sfield.ObjectID);
			if (it != g_eventMap.end())
			{
				map<CTypeObjectIDType, eventNod>::iterator	itNod = it->second.
					find(sfield.EventName);
				if (itNod != it->second.end())
				{
					int iTime = getiTime(sfield.OccurTime);

					//////////////////////////////////////////////////////////////////////////
					//change by feng.q 20121221 end of the world
					//增加日期的判断
					if (sfield.OccurDate == itNod->second.strDate.data()	//must the same day
					&&	iTime - itNod->second.iTime <= EVENT_MIN_CYCLE)		//the event occur again in 5 seconds
					{
						itor.Next();
						continue;
					}
					else
					{
						sfield.EvendID = ++g_eventId;
						sfield.EventNum = itNod->second.eventNum;
						itNod->second.iTime = iTime;

						map<int, list<CFTDRtnWarningEventField> >::iterator it =
							g_allEventField.find(sfield.EventNum);
						if (it != g_allEventField.end())
						{
							it->second.push_back(sfield);
						}

						if (itNod->second.processFlag == "=")
						{
							sfield.ProcessFlag = "=";
						}
					}

					//////////////////////////////////////////////////////////////////////////
					
					
										/// Mod by Henchi, 20120503
					// 					if(iTime -itNod->second.iTime >EVENT_MIN_CYCLE || (iTime < itNod->second.iTime))
					// 					{
					// 						sfield.EvendID =++g_eventId;
					// 						sfield.EventNum =itNod->second.eventNum;
					// 						itNod->second.iTime =iTime;
					//
					// 						map<int ,list<CFTDRtnWarningEventField> >::iterator it =g_allEventField.find(sfield.EventNum);
					// 						if(it !=g_allEventField.end())
					// 							it->second.push_back(sfield);
					//
					// 						if(itNod->second.processFlag =="=")
					// 							sfield.ProcessFlag ="=";
					// 					}
					// 					else
					// 					{
					// 						itor.Next();
					// 						continue;
					// 					}
				}
				else
				{
					eventNod theNode;
					sfield.EvendID = theNode.eventId = ++g_eventId;
					sfield.EventNum = theNode.eventNum = ++g_eventNum;
					theNode.iTime = getiTime(sfield.OccurTime);

					//////////////////////////////////////////////////////////////////////////
					//andd by feng.q
					theNode.strDate = sfield.OccurDate.getValue();

					//////////////////////////////////////////////////////////////////////////
					it->second[sfield.EventName] = theNode;

					list<CFTDRtnWarningEventField> theList;
					theList.push_back(sfield);
					g_allEventField[sfield.EventNum] = theList;
				}
			}
			else
			{
				eventNod theNode;
				sfield.EvendID = theNode.eventId = ++g_eventId;
				sfield.EventNum = theNode.eventNum = ++g_eventNum;
				theNode.iTime = getiTime(sfield.OccurTime);

				//////////////////////////////////////////////////////////////////////////
				//andd by feng.q
				theNode.strDate = sfield.OccurDate.getValue();

				//////////////////////////////////////////////////////////////////////////
				map<CTypeObjectIDType, eventNod> theMap;
				theMap[sfield.EventName] = theNode;
				g_eventMap[sfield.ObjectID] = theMap;

				list<CFTDRtnWarningEventField> theList;
				theList.push_back(sfield);
				g_allEventField[sfield.EventNum] = theList;
			}

			m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &sfield);
			SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);

			///准备发送短信:sfield即为所需event结构
			string strDevice;
			string strMember;
			int eventOccurNumber = 0;

			//CNetObjectIDType theOid =sfield.ObjectID;
			string strTmp = sfield.ObjectID.getValue();
			CNetObjectIDType theOid = strTmp.data();
			CSysNetDevice *pDevice = pMemoryDB->m_SysNetDeviceFactory->
				findByObjectID(theOid);
			if (pDevice)
			{
				strDevice = pDevice->NAME;
			}
			else
			{
				strTmp = strTmp.substr(0, strTmp.find_last_of("."));
				theOid = strTmp.data();
				pDevice = pMemoryDB->m_SysNetDeviceFactory->findByObjectID(
						theOid);
				if (pDevice)
				{
					strDevice = pDevice->NAME;
				}
			}

			CSysNetPartyLinkInfo *pPartyLinkInfo = pMemoryDB->
				m_SysNetPartyLinkInfoFactory->startFindByAll();
			while (pPartyLinkInfo)
			{
				string strPort = sfield.ObjectID.getValue();
				strPort = strPort.substr(
						strPort.find_last_of(".") + 1,
						strPort.length());

				string Port = pPartyLinkInfo->Interface.getValue();

				if (pPartyLinkInfo->IPADDR == sfield.IPAddress
				&&	strPort == Port)
				{
					strMember = pPartyLinkInfo->MEMBER_NAME;
					break;
				}

				pPartyLinkInfo = pMemoryDB->m_SysNetPartyLinkInfoFactory->findNextByAll();
			}

			pMemoryDB->m_SysNetPartyLinkInfoFactory->endFindByAll();

			map<int, list<CFTDRtnWarningEventField> >::iterator itEvent =
				g_allEventField.find(sfield.EventNum);
			if (itEvent != g_allEventField.end())
			{
				CDateType theDate;
				time_t timep;
				time(&timep);
		
				struct tm tm_time;
				LocalTime(&timep, &tm_time);
				sprintf(
					(char *)(theDate.getValue()),
					"%d%02d%02d",
					tm_time.tm_year + 1900,
					tm_time.tm_mon + 1,
					tm_time.tm_mday);
					
				list<CFTDRtnWarningEventField>::iterator itList = itEvent->
					second.begin();
				for (; itList != itEvent->second.end(); itList++)
				{
					if (itList->OccurDate == theDate)
					{
						eventOccurNumber++;
					}
				}
			}

			///发送短信:
			m_MsgGenerator.AddNetDeviceEventMsg(
					sfield,
					strDevice,
					strMember,
					eventOccurNumber);
		}
		else if (sfield.ProcessFlag == "A")
		{
			int eventNum = -1;
			map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> >::iterator
				itMap = g_eventMap.find(sfield.ObjectID);
			if (itMap != g_eventMap.end())
			{
				map<CTypeObjectIDType, eventNod>::iterator	itNod = itMap->
					second.find(sfield.EventName);
				if (itNod != itMap->second.end())
				{
					/// Mod by Henchi, 20120503
					if (itNod->second.processFlag == "=")
					{
						/// 当前事件为处理中状态，不作自动处理
						LOG_DEBUG(
							"Filter pkg: ProcessFlag is 'A', can't find event by eventName[%s.%s] or event's ProcessFlag is '=' \n",
							sfield.ObjectID.getValue(),
							sfield.EventName.getValue());
						itor.Next();
						continue;
					}
					else
					{
						eventNum = itNod->second.eventNum;
					}
				}
			}

			map<int, list<CFTDRtnWarningEventField> >::iterator it =
				g_allEventField.find(eventNum);
			if (it != g_allEventField.end())
			{
				CFTDRtnWarningEventField tfield;
				list<CFTDRtnWarningEventField>::iterator itList = it->second.
					begin();
				for (; itList != it->second.end(); itList++)
				{
					CopySysWarningEventEntity(&tfield, &(*itList));
					tfield.ProcessFlag = "=";
					tfield.EventDealDes = sfield.EventDealDes;
					m_pkgSend.PreparePackage(
							FTD_TID_RtnWarningEventTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
				}

				it->second.clear();
			}
		}

		itor.Next();
	}
}

void CEventServer::OnRtnSyslogEventTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnSyslogEventField sfield;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDRtnSyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		if (sfield.ProcessFlag == "N")
		{
			map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> >::iterator
				it = g_syslogMap.find(sfield.ObjectID);
			if (it != g_syslogMap.end())
			{
				map<CTypeObjectIDType, eventNod>::iterator	itNod = it->second.
					find(sfield.EventName);
				if (itNod != it->second.end())
				{
					int iTime = getiTime(sfield.OccurTime);

					/// Mod by Henchi, 20120503
					if (iTime - itNod->second.iTime > EVENT_MIN_CYCLE
					||	(iTime < itNod->second.iTime))
					{
						sfield.EvendID = ++g_syslogId;
						sfield.EventNum = itNod->second.eventNum;
						itNod->second.iTime = iTime;
					}
					else
					{
						itor.Next();
						continue;
					}
				}
				else
				{
					eventNod theNode;
					sfield.EvendID = theNode.eventId = ++g_syslogId;
					sfield.EventNum = theNode.eventNum = ++g_syslogNum;
					theNode.iTime = getiTime(sfield.OccurTime);
					it->second[sfield.EventName] = theNode;
				}
			}
			else
			{
				eventNod theNode;
				sfield.EvendID = theNode.eventId = ++g_syslogId;
				sfield.EventNum = theNode.eventNum = ++g_syslogNum;
				theNode.iTime = getiTime(sfield.OccurTime);

				map<CTypeObjectIDType, eventNod> theMap;
				theMap[sfield.EventName] = theNode;
				g_syslogMap[sfield.ObjectID] = theMap;
			}

			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &sfield);
			SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
		}
		else if (sfield.ProcessFlag == "G")
		{
			map<CNetAttrTypeType, map<CTypeObjectIDType, eventNod> >::iterator
				it = g_GenLogMap.find(sfield.ObjectID);
			if (it != g_GenLogMap.end())
			{
				map<CTypeObjectIDType, eventNod>::iterator	itNod = it->second.
					find(sfield.EventName);
				if (itNod != it->second.end())
				{
					int iTime = getiTime(sfield.OccurTime);

					/// Mod by Henchi, 20120503
					if (iTime - itNod->second.iTime > EVENT_MIN_CYCLE
					||	(iTime < itNod->second.iTime))
					{
						sfield.EvendID = ++g_GenLogId;
						sfield.EventNum = itNod->second.eventNum;
						itNod->second.iTime = iTime;
					}
					else
					{
						itor.Next();
						continue;
					}
				}
				else
				{
					eventNod theNode;
					sfield.EvendID = theNode.eventId = ++g_GenLogId;
					sfield.EventNum = theNode.eventNum = ++g_GenLogNum;
					theNode.iTime = getiTime(sfield.OccurTime);
					it->second[sfield.EventName] = theNode;
				}
			}
			else
			{
				eventNod theNode;
				sfield.EvendID = theNode.eventId = ++g_GenLogId;
				sfield.EventNum = theNode.eventNum = ++g_GenLogNum;
				theNode.iTime = getiTime(sfield.OccurTime);

				map<CTypeObjectIDType, eventNod> theMap;
				theMap[sfield.EventName] = theNode;
				g_GenLogMap[sfield.ObjectID] = theMap;
			}

			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &sfield);
			SessionProxy::Instance().NotifyEventCounter(&m_pkgSend);
		}

		itor.Next();
	}
}
