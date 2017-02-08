/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	FrontServer.cpp
///@brief	实现了前置监听监控客户端连接使用的类
///@history
///20080510	周建军		创建该文件
///20080623	周建军		修订注释
#include "utility.h"
#include "FrontServer.h"
#include "CListSession.h"
#include "databaseData.h"
#include "UFCopy.h"
#include "CQueryAgent.h"
#include "CSlogAgent.h"
#include "CountConnector.h"
#include "CSynConnector.h"
#include "FlowConnector.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "CPerformanceAnalyze.h"
using namespace std;

extern CDateType NowDate;
extern map<int, int> g_SubcriberMap;

extern CTypeObjectIDType g_DataCenter;
extern CDataCenterManage *g_pDataCenterManage;
extern CListSessionArray *g_pListSessionArray;
list<CFTDCSession *> g_mListAllSession;
extern CMemoryDB *pMemoryDB;
extern char g_mCfgPath[200];
extern CFTDCSession *g_CountConnector;

CFTDRspQryTradepeakField TradepeakField1;
CFTDRspQryTradepeakField TradepeakField2;

extern CXMLDoc	*pXMLDoc;

//extern CXMLNode *pXMLRootNode;
extern char *g_mXMLPath;

extern char *g_Today;

volatile int g_OrderQryCount;

extern int	thePeakBase;

///交易前置报单负载统计：
map<int, CFTDRspQryFrontStatField>	g_FrontStatMap;

//处理描述信息表
map<string, CFTDRspQryEventDescriptionField> g_EventDealDsec;

//////////////////////////////////////////////////////////////////////////
//add by feng.q 会员席位报单统计
//key 会员:席位
//value:所有报单的统计
map<string, CFTDRspQryParticTradeOrderStatesField>	g_mpPartiOrderCnt;

//////////////////////////////////////////////////////////////////////////
list<EventSubInfo>	g_EventSubList;

extern string g_VersionPath;
extern int	g_FrontRange;

///网络设备连接
map<CTypeObjectIDType, list<CTypeObjectIDType> > g_NetLinkMap;

///会员链路异常状态
map<CNetObjectIDType, CAttrValueType> g_partyLinkStatus;

///任务执行次数及时间
map<int, map<int, CFTDRspQryNetMonitorTaskStatusResultField> >	g_taskOperTimes;

map<int, list<TradeLogStrInfo> > g_mapTradeLogStr;

// add by cao.ning 网络性能处理对象
extern CPerformanceAnalyzer* g_pPerformanceAnalyzer;

///所有登录本前置机的用户信息：
typedef struct
{
	CUserIDType UserID;
	CIPAddressType	IPAddress;
} MonitorOnlineUser;

map<CFTDCSession *, MonitorOnlineUser>	map_MonitorOnlineUser;

///用于保存历史峰值情况的链表：
list<CFTDRtnHistoryTradePeakField>	list_HistoryTradePeak;

extern list<CFTDRtnTradeUserLoginInfoField> g_TradeUserLoginList;

#define MACREQ2SYN(x)															\
	{																			\
		CFTDReqQry##x##Field qryfield;											\
		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)				\
		{																		\
			return 0;															\
		}																		\
																		        \
		TRID  rid;																\
		rid.SessionID = pSession->GetSessionID();								\
		rid.RequestId = pFTDCPackage->GetRequestId();							\
		int nRid = m_Rid++;														\
		m_vRid[nRid] = rid;														\
		CFTDReqQry##x##Field field;												\
		CopyReqQry##x##Entity(&field, &qryfield);								\
		m_pkgSend.PreparePackage(												\
				FTD_TID_ReqQry##x##Topic,										\
				FTDC_CHAIN_LAST,												\
				FTD_VERSION);													\
		FTDC_ADD_FIELD(&m_pkgSend, &field);										\
		m_pkgSend.SetRequestId(nRid);											\
		if (m_pSynConnector->GetQuerySession())									\
		{																		\
			m_pSynConnector->GetQuerySession()->SendRequestPackage(&m_pkgSend); \
		}																		\
	}																			
																			 
void DivString(map<string, vector<string> > &theMap, const char *ch)
{
	string	str = ch;
	int index1 = 0;
	int index2 = 0;
	while (1)
	{
		index2 = str.find(OPTIONSTR, index1);
		if (index2 == -1)
		{
			break;
		}

		string	tmp = str.substr(index1, index2 - index1);
		vector<string>	listTmp;
		int idx1 = 0;
		int idx2 = 0;

		idx2 = tmp.find(DIVIDESTR, idx1);
		if (idx2 == -1)
		{
			break;
		}

		string	key = tmp.substr(idx1, idx2 - idx1);
		idx1 = idx2 + sizeof(DIVIDESTR) - 1;

		while (1)
		{
			idx2 = tmp.find(DIVIDESTR, idx1);
			if (idx2 == -1)
			{
				break;
			}

			listTmp.push_back(tmp.substr(idx1, idx2 - idx1));
			idx1 = idx2 + sizeof(DIVIDESTR) - 1;
		}

		listTmp.push_back(tmp.substr(idx1, tmp.size() - idx1));

		theMap[key] = listTmp;
		index1 = index2 + sizeof(OPTIONSTR) - 1;
	}

	string	tmp = str.substr(index1, str.size() - index1);
	vector<string>	listTmp;
	int idx1 = 0;
	int idx2 = 0;

	idx2 = tmp.find(DIVIDESTR, idx1);
	if (idx2 == -1)
	{
		return;
	}

	string	key = tmp.substr(idx1, idx2 - idx1);
	idx1 = idx2 + sizeof(DIVIDESTR) - 1;

	while (1)
	{
		idx2 = tmp.find(DIVIDESTR, idx1);
		if (idx2 == -1)
		{
			break;
		}

		listTmp.push_back(tmp.substr(idx1, idx2 - idx1));
		idx1 = idx2 + sizeof(DIVIDESTR) - 1;
	}

	listTmp.push_back(tmp.substr(idx1, tmp.size() - idx1));
	if (listTmp.size() > 0)
	{
		theMap[key] = listTmp;
	}
}

CFrontServer::CFrontServer(
	CReactor *pReactor,
	CQueryAgent *pQueryAgent,
	CSlogAgent *pSlogAgent,	
	CCountConnector *pCountConnector,
	CSynConnector *pSynConnector,
	CFlowConnector	*pFlowConnector) :
	CAgentSessionFactory(pReactor, 40)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pQueryAgent = pQueryAgent;
	m_pSlogAgent = pSlogAgent;
	m_pCountConnector = pCountConnector;
	m_pSynConnector = pSynConnector;
	m_pFlowConnector = pFlowConnector;
	m_Rid = 0;

	int objectid = g_StringIdMap.getStringId("ParticTradeOrderStates");
	g_SubcriberMap[objectid] = 16;

	m_dwLocaPingReqID = -1;
}

CSession *CFrontServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	return pSession;
}

void CFrontServer::OnSessionConnected(CSession *pSession)
{
	time_t	timep;
	time(&timep);
	CSessionFactory::OnSessionConnected(pSession);
	printf(
		"\t %s CFrontServer::OnSessionConnected: %0x\n",
		ctime(&timep),
		(CFTDCSession *)pSession);
	fflush(stdout);

	// by zhoujianjun for warning wrong connect
	//	g_mListAllSession.push_back((CFTDCSession *)pSession);
	//g_mMapSession.AddNewSessionFlow((CFTDCSession *)pSession);
	//	ClientInit((CFTDCSession *)pSession);
	//	string str =pSession->GetChannel()->GetRemoteName();
	//	cout<<str<<endl;
}

void CFrontServer::OnSessionDisconnected(CSession *pSession, int nReason)	// 子类重载处理连接断开事件
{
	time_t	timep;
	time(&timep);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
	printf(
		"\t %s CFrontServer::OnSessionDisconnected CFTDCSession remove %0x\n",
		ctime(&timep),
		(CFTDCSession *)pSession);
	fflush(stdout);

	//	cout<<"reason:----------------------------------------------------"<<nReason<<endl;
	//	ofstream out("output" ,ios_base::app);
	//	out<<pSession<<":CFrontServer::OnSessionDisconnected"<<"            "<<"nReason:"<<nReason<<endl;
	g_pListSessionArray->DelFTDSession((CFTDCSession *)pSession);
	g_mListAllSession.remove((CFTDCSession *)pSession);
	if (g_pPerformanceAnalyzer)
		g_pPerformanceAnalyzer->RemoveClientSession(((CFTDCSession *)pSession)->GetSessionID());

	map<int, list<TradeLogStrInfo> >::iterator	itMap = g_mapTradeLogStr.begin();
	for (; itMap != g_mapTradeLogStr.end(); itMap++)
	{
		list<TradeLogStrInfo>::iterator itList = itMap->second.begin();
		for (; itList != itMap->second.end(); itList++)
		{
			if (itList->pSession == pSession)
			{
				itMap->second.erase(itList);
				break;
			}
		}
	}

	map_MonitorOnlineUser.erase((CFTDCSession *)pSession);

	list<EventSubInfo>::iterator it = g_EventSubList.begin();
	while (it != g_EventSubList.end())
	{
		list<EventSubInfo>::iterator itTmp = it;
		itTmp++;

		list<CFTDCSession *> &theList = (*it).Receiver;
		list<CFTDCSession *>::iterator	itList = theList.begin();
		while (itList != theList.end())
		{
			list<CFTDCSession *>::iterator	itListTmp = itList;
			itListTmp++;
			if (*itList == pSession)
			{
				theList.erase(itList);
			}

			itList = itListTmp;
		}

		if (theList.size() == 0)
		{
			g_EventSubList.erase(it);
		}

		it = itTmp;
	}
}

int CFrontServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	printf("\tCFrontServer::receive package TID %x\n", pFTDCPackage->GetTID());
	pFTDCPackage->OutputHeader(g_pClnPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pClnPackOutput);
#endif
	// 保存当前处理的包和会话
	pCurHandlePackage = pFTDCPackage;
	pCurHandleSession = pSession;

	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqQryClient:
			OnReqQryClientLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTopCpuInfoTopic:
			OnReqQryTopCpuInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTopMemInfoTopic:
			OnReqQryTopMemInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTopProcessInfoTopic:
			OnReqQryTopProcessInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryFileSystemInfoTopic:
			OnReqQryFileSystemInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetworkInfoTopic:
			OnReqQryNetworkInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHostEnvTopic:
			OnReqQryHostEnvTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryClientLoginTopic:
			OnReqQryClientLoginTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryMonitorObjectTopic:
			OnReqQryMonitorObjectTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryObjectRationalTopic:
			OnReqQryObjectRationalTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySubscriberTopic:
			OnReqQrySubcriberTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryOidRelationTopic:
			OnReqQryOidRelationTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryObjectAttrTopic:
			OnReqQryObjectAttrTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySyslogInfoTopic:
			OnReqQrySyslogInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryUserInfoTopic:
			OnReqQryUserInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryOnlineUserInfoTopic:
			OnReqQryOnlineUserInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningEventTopic:
			OnReqQryWarningEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHistoryObjectAttrTopic:
			OnReqQryHistoryObjectAttrTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryFrontInfoTopic:
			OnReqQryFrontInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeLogTopic:
			OnReqQryTradeLogTopic(pFTDCPackage, pSession);
			break;

		///管理平台部分：
		case FTD_TID_ReqQryInvalidateOrderTopic:
			MANAGEPLATFORMPRSPQRY(InvalidateOrder);
			break;
		case FTD_TID_ReqQryOrderStatusTopic:
			MANAGEPLATFORMPRSPQRY(OrderStatus);
			break;
		case FTD_TID_ReqQryBargainOrderTopic:
			MANAGEPLATFORMPRSPQRY(BargainOrder);
			break;
		case FTD_TID_ReqQryInstPropertyTopic:
			MANAGEPLATFORMPINITRSPQRY(InstProperty);
			break;
		case FTD_TID_ReqQryMarginRateTopic:
			MANAGEPLATFORMPINITRSPQRY(MarginRate);
			break;
		case FTD_TID_ReqQryPriceLimitTopic:
			MANAGEPLATFORMPINITRSPQRY(PriceLimit);
			break;
		case FTD_TID_ReqQryPartPosiLimitTopic:
			//		MANAGEPLATFORMPINITRSPQRY(PartPosiLimit);
			OnReqQryPartPosiLimitTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryClientPosiLimitTopic:
			//		MANAGEPLATFORMPINITRSPQRY(ClientPosiLimit);
			OnReqQryClientPosiLimitTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySpecialPosiLimitTopic:
			//		MANAGEPLATFORMPINITRSPQRY(SpecialPosiLimit);
			OnReqQrySpecialPosiLimitTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTransactionChgTopic:
			MANAGEPLATFORMPRSPQRY(TransactionChg);
			break;
		case FTD_TID_ReqQryClientChgTopic:
			MANAGEPLATFORMPRSPQRY(ClientChg);
			break;
		case FTD_TID_ReqQryParticipantChgTopic:
			MANAGEPLATFORMPRSPQRY(ParticipantChg);
			break;
		case FTD_TID_ReqQryPartClientChgTopic:
			MANAGEPLATFORMPRSPQRY(PartClientChg);
			break;
		case FTD_TID_ReqQryPosiLimitChgTopic:
			MANAGEPLATFORMPRSPQRY(PosiLimitChg);
			break;
		case FTD_TID_ReqQryClientPosiLimitChgTopic:
			MANAGEPLATFORMPRSPQRY(ClientPosiLimitChg);
			break;
		case FTD_TID_ReqQrySpecPosiLimitChgTopic:
			MANAGEPLATFORMPRSPQRY(SpecPosiLimitChg);
			break;
		case FTD_TID_ReqQryHedgeDetailChgTopic:
			MANAGEPLATFORMPRSPQRY(HedgeDetailChg);
			break;
		case FTD_TID_ReqQryMarginRateChgTopic:
			MANAGEPLATFORMPRSPQRY(MarginRateChg);
			break;
		case FTD_TID_ReqQryUserIpChgTopic:
			MANAGEPLATFORMPRSPQRY(UserIpChg);
			break;

		///系统管理部分：
		case FTD_TID_ReqQrySysUserLoginTopic:
			//		SYSMANAGERREQ(SysUserLogin);
			OnReqQrySysUserLoginTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysUserLogoutTopic:
			//		SYSMANAGERREQ(SysUserLogout);
			OnReqQrySysUserLogoutTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySysUserPasswordUpdateTopic:
			SYSMANAGERREQ(SysUserPasswordUpdate);
			break;
		case FTD_TID_ReqQrySysUserRegisterTopic:
			SYSMANAGERREQ(SysUserRegister);
			break;
		case FTD_TID_ReqQrySysUserDeleteTopic:
			SYSMANAGERREQ(SysUserDelete);
			break;
		case FTD_TID_ReqQryParticipantInitTopic:
			OnReqQryParticipantInitTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryUserInitTopic:
			OnReqQryUserInitTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningEventUpdateTopic:
			OnReqQryWarningEventUpdateTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySyslogEventUpdateTopic:
			OnReqQrySyslogEventUpdateTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeUserLoginInfoTopic:
			OnReqQryTradeUserLoginInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryPartTradeTopic:
			OnPartTradeTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradepeakTopic:
			OnReqQryTradepeakTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryDiskIOTopic:
			OnReqQryStatInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryStatInfoTopic:
			SYSMANAGERREQ(StatInfo);
			break;
		case FTD_TID_ReqQryRouterInfoTopic:
			OnReqQryRouterInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTradeOrderRttCutLineTopic:
			{
				CFTDReqQryTradeOrderRttCutLineField qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
				{
					return 0;
				}

				m_pkgSend.PreparePackage(
						FTD_TID_RspQryTradeOrderRttCutLineTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

				CFTDRspQryTradeOrderRttCutLineField tfield;

				memset(&tfield, 0, sizeof(tfield));
				tfield.OrderRttCutLine = m_pSlogAgent->getRtnCutLine().OrderRttCutLine;

				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);

				m_pkgSend.PreparePackage(
						FTD_TID_RspQryTradeOrderRttCutLineTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());

				CFTDRspInfoField rspInfoField;
				memset(&rspInfoField, 0, sizeof(rspInfoField));
				rspInfoField.ErrorID = 0;
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			break;
		case FTD_TID_ReqQryHistoryCpuInfoTopic:
			SYSMANAGERREQ(HistoryCpuInfo);
			break;
		case FTD_TID_ReqQryHistoryMemInfoTopic:
			SYSMANAGERREQ(HistoryMemInfo);
			break;
		case FTD_TID_ReqQryHistoryNetworkInfoTopic:
			SYSMANAGERREQ(HistoryNetworkInfo);
			break;
		case FTD_TID_ReqQryMonitorOnlineUser:
			OnReqQryMonitorOnlineUser(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryFrontStat:
			OnReqQryFrontStat(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryHistoryTradePeakTopic:
			OnReqQryHistoryTradePeakTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySyslogEventSubcriberTopic:
			OnReqQrySyslogEventSubcriberTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQrySyslogEventTopic:
			OnReqQrySyslogEventTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryTomcatInfoTopic:
			OnReqQryTomcatInfoTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryDBQueryTopic:
			OnReqQryDBQueryTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryGetFileTopic:
			OnReqQryGetFileTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWarningQueryTopic:
			OnReqQryWarningQueryTopic(pFTDCPackage, pSession);
			break;

		// Added by Henchi, 20100610
		case FTD_TID_ReqQryWarningActiveChange:
			OnReqQryWarningActiveChange(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetTimePolicyTopic:
			SYNCFGREQ(NetTimePolicy);
			break;
		case FTD_TID_ReqQryTradeUserLoginStatTopic:
			OnReqQryTradeUserLoginStatTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryWebVisitTopic:
			{
				CFTDReqQryWebVisitField qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
				{
					return 0;
				}
				if (m_pQueryAgent->GetQuerySession())
				{
					CFTDReqQryWebVisitField field;
					CopyReqQryWebVisitEntity(&field, &qryfield);
			
					SendReqPackageOnAgentSession(field, m_pQueryAgent->GetQuerySession()
						, FTD_TID_ReqQryWebVisitTopic, false);
				}
			}

			break;
		case FTD_TID_ReqQryNetCfgFileTopic:
			{
				CFTDReqQryNetCfgFileField qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
				{
					return 0;
				}			
				
				if (m_pCountConnector->GetCountSession())
				{
					CFTDReqQryNetCfgFileField field;
					CopyReqQryNetCfgFileEntity(&field, &qryfield);
					SendReqPackageOnAgentSession(field, m_pCountConnector->GetCountSession()
					, FTD_TID_ReqQryNetCfgFileTopic, false);
				}
			}

			break;
		case FTD_TID_ReqQryRealTimeNetObjectAttrTopic:
			MACREQ2SYN(RealTimeNetObjectAttr);
			break;
		case FTD_TID_ReqQryNetDeviceLinkedTopic:
			{
				CFTDReqQryNetDeviceLinkedField	qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
				{
					return 0;
				}

				CFTDReqQryNetDeviceLinkedField	field;
				CopyReqQryNetDeviceLinkedEntity(&field, &qryfield);
				m_pkgSend.PreparePackage(
						FTD_TID_ReqQryNetDeviceLinkedTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &field);
				m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
				if (qryfield.OperationType == 0)				///网络请求
				{
					if (m_pSynConnector->GetQuerySession())
					{
						m_pSynConnector->GetQuerySession()->SendRequestPackage(
								&m_pkgSend);
					}
				}
				else if (qryfield.OperationType == 1)			///日志或流水请求并订阅
				{
					if (qryfield.SysNetSubAreaID < 100)
					{
						if (m_pSlogAgent->GetSlogSession())
						{
							m_pSlogAgent->GetSlogSession()->SendRequestPackage(
									&m_pkgSend);
						}
					}
					else
					{
						if (m_pFlowConnector->GetFlowSession())
						{
							m_pFlowConnector->GetFlowSession()->SendRequestPackage(
									&m_pkgSend);
						}
					}

					TradeLogStrInfo theInfo;
					theInfo.rId = pFTDCPackage->GetRequestId();
					theInfo.pSession = pSession;

					map<int, list<TradeLogStrInfo> >::iterator	it =
						g_mapTradeLogStr.find(qryfield.SysNetSubAreaID);
					if (it != g_mapTradeLogStr.end())
					{
						list<TradeLogStrInfo>::iterator itList = it->second.begin();
						for (; itList != it->second.end(); itList++)
						{
							if (itList->pSession == pSession)
							{
								break;
							}
						}

						if (itList == it->second.end())
						{
							it->second.push_back(theInfo);
						}
					}
					else
					{
						list<TradeLogStrInfo> theList;
						theList.push_back(theInfo);
						g_mapTradeLogStr[qryfield.SysNetSubAreaID] = theList;
					}
				}
				else if (qryfield.OperationType == -1)			///取消订阅
				{
					int rId;
					map<int, list<TradeLogStrInfo> >::iterator	it =
						g_mapTradeLogStr.find(qryfield.SysNetSubAreaID);
					if (it != g_mapTradeLogStr.end())
					{
						list<TradeLogStrInfo>::iterator itList = it->second.begin();
						for (; itList != it->second.end(); itList++)
						{
							if (itList->pSession == pSession)
							{
								rId = itList->rId;
								it->second.erase(itList);
								break;
							}
						}
					}

					///靠last来取消订阅
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryTradeLogTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetRequestId(rId);

					CFTDRspInfoField rspInfoField;
					memset(&rspInfoField, 0, sizeof(rspInfoField));
					FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
					pSession->SendRequestPackage(&m_pkgSend);
				}
			}

			break;
		case FTD_TID_ReqQryNetDeviceRequestTopic:
			MACREQ2SYN(NetDeviceRequest);
			break;
		case FTD_TID_ReqQryNetDeviceDetectTopic:
			MACREQ2SYN(NetDeviceDetect);
			break;
		case FTD_TID_ReqQryNetDeviceChgTopic:
			MACREQ2SYN(NetDeviceChg);
			break;
		case FTD_TID_ReqQryNetGatherTaskTopic:
			MACREQ2SYN(NetGatherTask);
			break;
		case FTD_TID_ReqQryNetInterfaceTopic:
			MACREQ2SYN(NetInterface);
			break;
		case FTD_TID_ReqQryNetModuleTopic:
			MACREQ2SYN(NetModule);
			break;
		case FTD_TID_ReqQryNetMonitorDeviceGroupTopic:
			MACREQ2SYN(NetMonitorDeviceGroup);
			break;
		case FTD_TID_ReqQryNetMonitorTaskInfoTopic:
			MACREQ2SYN(NetMonitorTaskInfo);
			break;
		case FTD_TID_ReqQryFileGeneralOperTopic:
			//MACREQ2SYN(FileGeneralOper);
			{
				CFTDReqQryFileGeneralOperField	qryfield;
				if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
				{
					return 0;
				}
				CFTDReqQryFileGeneralOperField	field;
				CopyReqQryFileGeneralOperEntity(&field, &qryfield);
				memcpy(
					(void *)(field.FileContent.getValue()),
					(void *)(qryfield.FileContent.getValue()),
					sizeof(field.FileContent));
				m_pkgSend.PreparePackage(
						FTD_TID_ReqQryFileGeneralOperTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &field);
				m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
				if (m_pSynConnector->GetQuerySession())
				{
					m_pSynConnector->GetQuerySession()->SendRequestPackage(
							&m_pkgSend);
				}
			}

			break;
		case FTD_TID_ReqQryNetMonitorAttrScopeTopic:
			MACREQ2SYN(NetMonitorAttrScope);
			break;
		case FTD_TID_ReqQryNetMonitorTaskResultTopic:
			OnReqQryNetMonitorTaskResultTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetMonitorTaskStatusResultTopic:
			OnReqQryNetMonitorTaskStatusResultTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetBaseLineResultTopic:
			SYSMANAGERREQ(NetBaseLineResult);
			break;
		case FTD_TID_ReqQryNetBaseLineTopic:
			MACREQ2SYN(NetBaseLine);
			break;
		case FTD_TID_ReqQryNetMonitorDeviceTaskTopic:
			MACREQ2SYN(NetMonitorDeviceTask);
			break;
		case FTD_TID_ReqQryTradeFrontOrderRttStatTopic:
			OnReqQryTradeFrontOrderRttStatTopic(pFTDCPackage, pSession);
			break;

		//	case FTD_TID_ReqQryNetDeviceLinkTopic:
		//		{
		//			CFTDReqQryNetDeviceLinkField qryfield;
		//			if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield)<= 0)
		//			{
		//				return 0;
		//			}
		//			/*map<CTypeObjectIDType ,list<CTypeObjectIDType> >::iterator itMap =g_NetLinkMap.find(qryfield.ObjectID);
		//			if(itMap !=g_NetLinkMap.end())
		//			{
		//				list<CTypeObjectIDType>::iterator itList =itMap->second.begin();
		//				for( ;itList !=itMap->second.end() ;itList ++)
		//				{
		//					m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//					m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//					CFTDRspQryNetDeviceLinkField tfield;
		//					tfield.ObjectID =itMap->first;
		//					tfield.LinkID =*itList;
		//					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//					pSession->SendRequestPackage(&m_pkgSend);
		//				}
		//			}*/
		/////////////////////////////////////
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Router";
		//				tfield.ObjectPortID ="1";
		//				tfield.LinkID ="BeiJing.OA.app.Z-BIZ1-9-5F-1";
		//				tfield.LinkPortID ="1";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Router";
		//				tfield.ObjectPortID ="2";
		//				tfield.LinkID ="BeiJing.OA.app.Z-A1-4F-TEST-2";
		//				tfield.LinkPortID ="1";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Router";
		//				tfield.ObjectPortID ="3";
		//				tfield.LinkID ="BeiJing.OA.app.Z-A1-4F-TEST-1";
		//				tfield.LinkPortID ="1";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Router";
		//				tfield.ObjectPortID ="4";
		//				tfield.LinkID ="BeiJing.OA.app.Z-BUS1-9-5F-2";
		//				tfield.LinkPortID ="1";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Z-BIZ1-9-5F-1";
		//				tfield.ObjectPortID ="2";
		//				tfield.LinkID ="BeiJing.OA.app.Z-BUS1-9-5F-2";
		//				tfield.LinkPortID ="2";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Z-BIZ1-9-5F-1";
		//				tfield.ObjectPortID ="3";
		//				tfield.LinkID ="BeiJing.OA.app.Z-A1-4F-TEST-1";
		//				tfield.LinkPortID ="3";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Z-BIZ1-9-5F-1";
		//				tfield.ObjectPortID ="4";
		//				tfield.LinkID ="BeiJing.OA.app.Z-A1-4F-TEST-2";
		//				tfield.LinkPortID ="4";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Z-A1-4F-TEST-2";
		//				tfield.ObjectPortID ="5";
		//				tfield.LinkID ="BeiJing.OA.app.Z-A1-4F-TEST-1";
		//				tfield.LinkPortID ="5";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Z-A1-4F-TEST-2";
		//				tfield.ObjectPortID ="6";
		//				tfield.LinkID ="BeiJing.OA.app.Z-BUS1-9-5F-2";
		//				tfield.LinkPortID ="6";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//			{
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspQryNetDeviceLinkField tfield;
		//				tfield.ObjectID ="BeiJing.OA.app.Z-BUS1-9-5F-2";
		//				tfield.ObjectPortID ="7";
		//				tfield.LinkID ="BeiJing.OA.app.Z-A1-4F-TEST-1";
		//				tfield.LinkPortID ="7";
		//				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//
		//			m_pkgSend.PreparePackage(FTD_TID_RspQryNetDeviceLinkTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		//			m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//			CFTDRspInfoField rspInfoField;
		//			memset(&rspInfoField ,0 ,sizeof(rspInfoField));
		//			rspInfoField.ErrorID =0;
		//			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		//			pSession->SendRequestPackage(&m_pkgSend);
		//		}
		//		break;
		case FTD_TID_ReqQryGeneralOperateTopic:
			OnReqQryGeneralOperateTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetRoomTopic:						//告警短信开关
			OnReqQryNetRoomTopic(pFTDCPackage, pSession);
		case FTD_TID_ReqQryParticTradeOrderStatesTopic:
			OnReqQryParticTradeOrderStatesTopic(pFTDCPackage, pSession);

			//MANAGEPLATFORMPINITRSPQRY(ParticTradeOrderStates);
			break;

		//todo:test
		//case FTD_TID_ReqQryGeneralOperateTopic:
		//	{
		//		CFTDReqQryGeneralOperateField qryfield;
		//		if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield)<= 0)
		//		{
		//			return 0;
		//		}
		//		///判断操作表：
		//		if(qryfield.GeneralOperateTable =="WarningEventTable")
		//		{
		//			///判断操作类型：
		//			if(qryfield.GeneralOperateType ==GOT_query)
		//			{
		//				///分割查询条件：
		//				map<string ,vector<string> > theMap;
		//				DivString(theMap ,qryfield.GeneralOperateOption.getValue());
		//				///查询条件为空，则返回全部
		//				if(theMap.size() ==0)
		//				{
		//					CSysWarningEvent *sfield =pMemoryDB->m_SysWarningEventFactory->startFindByAll();
		//					while(sfield)
		//					{
		//						///打包发出
		//						CFTDRspQryWarningEventField theField;
		//						CopySysWarningEventEntity(&theField ,sfield);
		//						CFTDRspQryGeneralOperateField tfield;
		//						memset(&tfield ,0 ,sizeof(tfield));
		//						tfield.GeneralOperateType =GOT_add;
		//						tfield.GeneralOperateTable =qryfield.GeneralOperateTable;
		//						string strTmp;
		//						for(int idx =0 ;idx <CFTDRspQryWarningEventField::m_Describe.GetMemberCount() ;idx ++)
		//						{
		//							char *str =NULL;
		//							///整型的话
		//							if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(idx)->nType ==FT_DWORD)
		//							{
		//								str =(char *)malloc(20);
		//								DWORD tmp;
		//								memcpy(&tmp ,(const char *)&theField +theField.m_Describe.GetMemberDesc(idx)->nStructOffset ,sizeof(DWORD));
		//								sprintf(str, "%d", tmp);
		//							}
		//							///字符串的话
		//							else if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(idx)->nType ==FT_BYTE)
		//							{
		//								int length =theField.m_Describe.GetMemberDesc(idx)->nSize;
		//								str =(char *)malloc(length);
		//								memcpy(str ,(const char *)&theField +theField.m_Describe.GetMemberDesc(idx)->nStructOffset ,length);
		//							}
		//							strTmp +=str; strTmp +=DIVIDESTR;
		//						}
		//						tfield.GeneralOperateSet =strTmp.data();
		//						m_pkgSend.PreparePackage(FTD_TID_RspQryGeneralOperateTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//						m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//						pSession->SendRequestPackage(&m_pkgSend);
		//						sfield =pMemoryDB->m_SysWarningEventFactory->findNextByAll();
		//					}
		//					pMemoryDB->m_SysWarningEventFactory->endFindByAll();
		//				}
		//				///进行查询
		//				else
		//				{
		//					CSysWarningEvent *sfield =pMemoryDB->m_SysWarningEventFactory->startFindByAll();
		//					while(sfield)
		//					{
		//						int index =0;
		//						CFTDRspQryWarningEventField theField;
		//						for( ;index <CFTDRspQryWarningEventField::m_Describe.GetMemberCount() ;index ++)
		//						{
		//							CopySysWarningEventEntity(&theField ,sfield);
		//							map<string ,vector<string> >::iterator itMap =theMap.find(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(index)->szName);
		//							if(itMap !=theMap.end())
		//							{
		//								///查询单个
		//								if((itMap->second).size() ==1)
		//								{
		//									///整型的话
		//									if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(index)->nType ==FT_DWORD)
		//									{
		//										DWORD tmp;
		//										memcpy(&tmp ,(const char *)&theField +theField.m_Describe.GetMemberDesc(index)->nStructOffset ,sizeof(DWORD));
		//										if(tmp !=atoi((itMap->second)[0].data()))
		//										{
		//											break;
		//										}
		//									}
		//									///字串的话
		//									else if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(index)->nType ==FT_BYTE)
		//									{
		//										int length =theField.m_Describe.GetMemberDesc(index)->nSize;
		//										char *tmp =(char *)malloc(length);
		//										memcpy(tmp ,(const char *)&theField +theField.m_Describe.GetMemberDesc(index)->nStructOffset ,length);
		//										if((itMap->second)[0] !=tmp)
		//										{
		//											/*sfield =pMemoryDB->m_SysWarningEventFactory->findNextByAll();
		//											continue;*/
		//											break;
		//										}
		//									}
		//								}
		//								///区间查询
		//								else if((itMap->second).size() ==2)
		//								{
		//									///整型的话
		//									if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(index)->nType ==FT_DWORD)
		//									{
		//										DWORD tmp;
		//										memcpy(&tmp ,(const char *)&theField +theField.m_Describe.GetMemberDesc(index)->nStructOffset ,sizeof(DWORD));
		//										if(tmp <atoi((itMap->second)[0].data()) ||tmp >atoi((itMap->second)[1].data()))
		//										{
		//											break;
		//										}
		//									}
		//									///字串的话
		//									else if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(index)->nType ==FT_BYTE)
		//									{
		//										int length =theField.m_Describe.GetMemberDesc(index)->nSize;
		//										char *tmp =(char *)malloc(length);
		//										memcpy(tmp ,(const char *)&theField +theField.m_Describe.GetMemberDesc(index)->nStructOffset ,length);
		//										if((itMap->second)[0] >tmp ||(itMap->second)[1] <tmp)
		//										{
		//											break;
		//										}
		//									}
		//								}
		//							}
		//						}
		//						if(index ==CFTDRspQryWarningEventField::m_Describe.GetMemberCount())
		//						{
		//							///打包发出
		//							CFTDRspQryGeneralOperateField tfield;
		//							memset(&tfield ,0 ,sizeof(tfield));
		//							tfield.GeneralOperateType =GOT_add;
		//							tfield.GeneralOperateTable =qryfield.GeneralOperateTable;
		//							string strTmp;
		//							for(int idx =0 ;idx <CFTDRspQryWarningEventField::m_Describe.GetMemberCount() ;idx ++)
		//							{
		//								char *str =NULL;
		//								///整型的话
		//								if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(idx)->nType ==FT_DWORD)
		//								{
		//									str =(char *)malloc(20);
		//									DWORD tmp;
		//									memcpy(&tmp ,(const char *)&theField +theField.m_Describe.GetMemberDesc(idx)->nStructOffset ,sizeof(DWORD));
		//									sprintf(str, "%d", tmp);
		//								}
		//								///字符串的话
		//								else if(CFTDRspQryWarningEventField::m_Describe.GetMemberDesc(idx)->nType ==FT_BYTE)
		//								{
		//									int length =theField.m_Describe.GetMemberDesc(idx)->nSize;
		//									str =(char *)malloc(length);
		//									memcpy(str ,(const char *)&theField +theField.m_Describe.GetMemberDesc(idx)->nStructOffset ,length);
		//								}
		//								strTmp +=str; strTmp +=DIVIDESTR;
		//							}
		//							tfield.GeneralOperateSet =strTmp.data();
		//							m_pkgSend.PreparePackage(FTD_TID_RspQryGeneralOperateTopic,FTDC_CHAIN_CONTINUE,FTD_VERSION);
		//							m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//							pSession->SendRequestPackage(&m_pkgSend);
		//						}
		//						sfield =pMemoryDB->m_SysWarningEventFactory->findNextByAll();
		//					}
		//					pMemoryDB->m_SysWarningEventFactory->endFindByAll();
		//				}
		//				
		//				m_pkgSend.PreparePackage(FTD_TID_RspQryGeneralOperateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		//				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
		//				CFTDRspInfoField rspInfoField;
		//				memset(&rspInfoField ,0 ,sizeof(rspInfoField));
		//				rspInfoField.ErrorID =0;
		//				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		//				pSession->SendRequestPackage(&m_pkgSend);
		//			}
		//		}
		//	}
		//	break;
		case FTD_TID_ReqQryNetLocalPingResultInfoTopic:
			OnReqQryLocalPingTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryNetRomotePingResultInfoTopic:
			OnReqQryRemotePingTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryEventDescriptionTopic:
		{
			CFTDReqQryEventDescriptionField qryfield;											
			if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)				
			{																		
				return 0;															
			}																		

			if(qryfield.EventDesID != "")
			{
				//查询处理描述信息
				map<string, CFTDRspQryEventDescriptionField>::iterator d_it = g_EventDealDsec.find(qryfield.EventDesID.getValue());
				if(d_it != g_EventDealDsec.end())
				{
					//本地已缓存，直接返回
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryEventDescriptionTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);
					m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
					
					FTDC_ADD_FIELD(&m_pkgSend, &d_it->second);
					pSession->SendRequestPackage(&m_pkgSend);

					//发送结束的空包
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryEventDescriptionTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					m_pkgSend.SetChain(pFTDCPackage->GetChain());	
					m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());
					
					pSession->SendRequestPackage(&m_pkgSend);					

					return 0;
				}

				//否则向config查询数据
			}
			CFTDReqQryEventDescriptionField field;									
			CopyReqQryEventDescriptionEntity(&field, &qryfield);					
			m_pkgSend.PreparePackage(												
					FTD_TID_ReqQryEventDescriptionTopic,							
					FTDC_CHAIN_LAST,												
					FTD_VERSION);													
			FTDC_ADD_FIELD(&m_pkgSend, &field);										
			m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());											
			if (m_pSynConnector->GetQuerySession())									
			{																		
				m_pSynConnector->GetQuerySession()->SendRequestPackage(&m_pkgSend); 
			}	
		}
		break;
		case FTD_TID_ReqQryPerformanceTopTopic:
			OnReqQryPerformanceTopTopic(pFTDCPackage, pSession);
			break;
		case FTD_TID_ReqQryInstrumentStatusTopic:
			{																		   
				CFTDReqQryInstrumentStatusField qryfield;										   
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield);						   
				CSysInstrumentStatus *pfield = pMemoryDB->m_SysInstrumentStatusFactory->startFindBytheAll();										   
				while (pfield)														   
				{																	   																   
					m_pkgSend.PreparePackage(										   
						FTD_TID_RspQryInstrumentStatusTopic,								   
						FTDC_CHAIN_CONTINUE,									   
						FTD_VERSION);											   
					m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());			   
					CFTDRspQryInstrumentStatusField field;										   
					CopySysInstrumentStatusEntity(&field, pfield);								   
					FTDC_ADD_FIELD(&m_pkgSend, &field);								   
					pSession->SendRequestPackage(&m_pkgSend);						   
					pfield = pMemoryDB->m_SysInstrumentStatusFactory->findNextBytheAll();	   
				}																	   
				
				pMemoryDB->m_SysInstrumentStatusFactory->endFindBytheAll();				   
				m_pkgSend.PreparePackage(											   
				FTD_TID_RspQryInstrumentStatusTopic,									   
				FTDC_CHAIN_LAST,											   
				FTD_VERSION);												   
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());				   
				CFTDRspInfoField rspInfoField;										   
				memset(&rspInfoField, 0, sizeof(rspInfoField));						   
				rspInfoField.ErrorID = 0;											   
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);							   
				pSession->SendRequestPackage(&m_pkgSend);							   
			}
			break;
		case FTD_TID_ReqQryCurrTradingSegmentAttrTopic:
			{																		   
				CFTDReqQryCurrTradingSegmentAttrField qryfield;										   
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield);						   
				CSysCurrTradingSegmentAttr *pfield = pMemoryDB->m_SysCurrTradingSegmentAttrFactory->startFindBytheAll();										   
				while (pfield)														   
				{																	   																   
					m_pkgSend.PreparePackage(										   
						FTD_TID_RspQryCurrTradingSegmentAttrTopic,								   
						FTDC_CHAIN_CONTINUE,									   
						FTD_VERSION);											   
					m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());			   
					CFTDRspQryCurrTradingSegmentAttrField field;										   
					CopySysCurrTradingSegmentAttrEntity(&field, pfield);								   
					FTDC_ADD_FIELD(&m_pkgSend, &field);								   
					pSession->SendRequestPackage(&m_pkgSend);						   
					pfield = pMemoryDB->m_SysCurrTradingSegmentAttrFactory->findNextBytheAll();	   
				}																	   

				pMemoryDB->m_SysCurrTradingSegmentAttrFactory->endFindBytheAll();				   
				m_pkgSend.PreparePackage(											   
					FTD_TID_RspQryCurrTradingSegmentAttrTopic,									   
					FTDC_CHAIN_LAST,											   
					FTD_VERSION);												   
				m_pkgSend.SetRequestId(pFTDCPackage->GetRequestId());				   
				CFTDRspInfoField rspInfoField;										   
				memset(&rspInfoField, 0, sizeof(rspInfoField));						   
				rspInfoField.ErrorID = 0;											   
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);							   
				pSession->SendRequestPackage(&m_pkgSend);							   
			}
			break;
		default:
			OnDefaultProcess(pFTDCPackage, pSession);
			break;
	}

	return 0;
}

void CFrontServer::OnReqQryClientLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryClientLoginField	fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);
	printf(
		"\tCFrontServer::OnReqUserLogin:user=%s password=%s\n",
		(const char *)fieldLogin.UserName,
		(const char *)fieldLogin.PassWord);
	fflush(stdout);

	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			FTD_TID_RspQryClient,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "成功";
	fieldRspInfo.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
	pSession->SendRequestPackage(&m_pkgSend);

	printf(
		"\tCFrontServer::OnReqUserLogin CFTDCSession push_back %0x\n",
		(CFTDCSession *)pSession);
	fflush(stdout);
}

void CFrontServer::OnDefaultProcess(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	printf("CFrontServer::OnDefaultProcess:\n");
	m_pkgSend.PrepareResponse(
			pFTDCPackage,
			pFTDCPackage->GetTID(),
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRspInfoField fieldRspInfo;
	fieldRspInfo.ErrorMsg = "";
	fieldRspInfo.ErrorID = ERR_EXCEPTREQ;
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryOidRelationTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryOidRelationField	ftdQryField;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &ftdQryField) <= 0)
	{
		return;
	}

	string	p = (char *)ftdQryField.ObjectID.getValue();
	list<string> *pList;
	list<string>::iterator	listIt;
	CFTDRspQryOidRelationField	field;
#ifdef PRINT_DEBUG
	printf(
		"OnReqQryOidRelationTopic:ObjectID %s\n",
		ftdQryField.ObjectID.getValue());
#endif
	pList = g_pDataCenterManage->getAttrFromAppId(p);

	m_pkgSend.PrepareResponse(
			pPackage,
			FTD_TID_RspQryOidRelationTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	if (pList)
	{
		for (listIt = pList->begin(); listIt != pList->end(); listIt++)
		{
			field.ObjectID = ftdQryField.ObjectID;
			field.HoldObjectID = (*listIt).c_str();

#ifndef PRINT_DEBUG
			printf(
				"\t objectid:%s  HoldObjectID:%s\n",
				(const char *)field.ObjectID,
				(const char *)field.HoldObjectID);
#endif
			if (m_pkgSend.Length() + sizeof(field) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				pSession->SendRequestPackage(&m_pkgSend);
				m_pkgSend.PrepareResponse(
						pPackage,
						FTD_TID_RspQryOidRelationTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &field);
			}
			else
			{
				FTDC_ADD_FIELD(&m_pkgSend, &field);
			}
		}
	}
	else	// 查询的是未知进程的监控指标, 错误！返回错误信息到客户端
	{
		ADDERRORINFOFIELD;
	}

#ifndef PRINT_DEBUG
	printf("\t packet size %d %c\n", m_pkgSend.Length(), m_pkgSend.GetChain());
#endif
	pSession->SendRequestPackage(&m_pkgSend);
}

///最近一次次峰值计算时间下限:
CTimeType lastTime = "";

//string strOid ="PuDian.app.tmdb";
int getiTime(CTimeType tTime)
{
	string	sTime = tTime.getValue();
	return ((sTime[0] - '0') * 10 + (sTime[1] - '0')) * 3600 +
		((sTime[3] - '0') * 10 + (sTime[4] - '0')) * 60 +
			((sTime[6] - '0') * 10 + (sTime[7] - '0'));
}

CTimeType getsTime(int iTime)
{
	int iHour = iTime / 3600;
	int iMinute = (iTime % 3600) / 60;
	int iSecond = (iTime % 3600) % 60;
	char theTime[10] = "";
	sprintf(theTime, "%02d:%02d:%02d", iHour, iMinute, iSecond);

	string	stmp = theTime;
	CTimeType ttmp;
	strcpy((char *)(ttmp.getValue()), stmp.data());
	return ttmp;
}

void CFrontServer::OnReqQryTradepeakTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradepeakField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	char tmp[100] = "";
	sprintf(tmp, "%s.%s", g_DataCenter.getValue(), "app.tkernel.1");

	//sprintf(tmp ,"%s.%s" ,"TRADE.PuDian" ,"app.tkernel.1");
	string	strOid = tmp;
	int objectid_OrderInsert = g_StringIdMap.getStringId(
			(strOid + "." + APPATTRHANDLEORDERINSERTTOTAL).data());
	int objectid_ErrorOrder = g_StringIdMap.getStringId(
			(strOid + "." + APPATTRHANDLEORDERINSERTERRORTOTAL).data());
	int objectid_TradeSize = g_StringIdMap.getStringId(
			(strOid + "." + APPATTRTRADESIZE).data());
	int objectid_OrderAction = g_StringIdMap.getStringId(
			(strOid + "." + APPATTRHANDLEORDERACTIONTOTAL).data());

	if (objectid_OrderInsert < 0
	||	objectid_ErrorOrder < 0
	||	objectid_TradeSize < 0
	||	objectid_OrderAction < 0)
	{
		return;
	}

	CDateType theDate;
	time_t	timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		(char *)(theDate.getValue()),
		"%d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);

	//	int attrtype =g_StringIdMap.getStringId(APPATTRHANDLEORDERINSERTTOTAL);
		///峰值计算：
	int timeFib2Front = 1;
	if (qryfield.TradepeakFlag == '1')
	{
		timeFib2Front = TIME_FIB2FRONT2;
	}
	else if (qryfield.TradepeakFlag == '2')
	{
		timeFib2Front = TIME_FIB2FRONT1;
	}
	else if (qryfield.TradepeakFlag == '3')
	{
		timeFib2Front = TIME_FIB2FRONT3;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTradepeakTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspQryTradepeakField tfield;
	memset(&tfield, 0, sizeof(tfield));
	tfield.TradepeakFlag = qryfield.TradepeakFlag;

	///从最新的时间向前推算
	CSysMdbObjectAttr *pObjectAttr = pMemoryDB->m_SysMdbObjectAttrFactory->
		startFindByDsc(objectid_OrderInsert);

	///如果根本没有，则返回相关信息并退出
	if (pObjectAttr == NULL)
	{
		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = -5;
		rspInfoField.ErrorMsg = "haven't data";
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
		return;
	}

	///如果没有区间长度的数据，也退出
	else
	{
		int ilowTime = getiTime(pObjectAttr->MonTime) - timeFib2Front;
		if (ilowTime < thePeakBase)
		{
			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = -5;
			rspInfoField.ErrorMsg = "haven't data";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}
	}

	///如果有最新报单插入总量信息则暂定此时间为峰值
		///峰值时间的含义为峰值时间段的最后一个时间点
	CTimeType peakTime = pObjectAttr->MonTime;
	pMemoryDB->m_SysMdbObjectAttrFactory->endFindByDsc();

	CTimeType highTime = peakTime;
	CTimeType lowTime = getsTime(getiTime(highTime) - timeFib2Front);
	int OrderInsertPeak = 0;
	CTimeType thePeakBaseTime = getsTime(thePeakBase);
	CSysMdbObjectAttr *pObjectAttrLow = pMemoryDB->m_SysMdbObjectAttrFactory->
		findByOne(objectid_OrderInsert, theDate, lowTime);
	CSysMdbObjectAttr *pObjectAttrHigh = pMemoryDB->m_SysMdbObjectAttrFactory->
		findByOne(objectid_OrderInsert, theDate, highTime);

	///找到第一段可用区间
	while (1)
	{
		///如果从最新值的时间步长前有值（即当前步长尾值），则计其差值为暂定峰值
		if (pObjectAttrLow != NULL && pObjectAttrHigh != NULL)
		{
			OrderInsertPeak = atoi(pObjectAttrHigh->AttrValue.getValue()) - atoi(
					pObjectAttrLow->AttrValue.getValue());
			break;
		}

		///如果有一个为空，则继续向前找直到找到第一段可用区间
		else
		{
			highTime = getsTime(getiTime(highTime) - 1);
			lowTime = getsTime(getiTime(lowTime) - 1);
			if (lowTime < thePeakBaseTime)
			{
				CFTDRspInfoField rspInfoField;
				memset(&rspInfoField, 0, sizeof(rspInfoField));
				rspInfoField.ErrorID = -5;
				rspInfoField.ErrorMsg = "haven't data";
				FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
				pSession->SendRequestPackage(&m_pkgSend);
				return;
			}

			pObjectAttrLow = pMemoryDB->m_SysMdbObjectAttrFactory->findByOne(
					objectid_OrderInsert,
					theDate,
					lowTime);
			pObjectAttrHigh = pMemoryDB->m_SysMdbObjectAttrFactory->findByOne(
					objectid_OrderInsert,
					theDate,
					highTime);
		}
	}

	///以一秒为步长向前推算，如果步长内的报单插入大于暂定峰值则取代之，直到basetime，退出循环
	while (1)
	{
		///找到下一段可用区间
		while (1)
		{
			highTime = getsTime(getiTime(highTime) - 1);
			lowTime = getsTime(getiTime(lowTime) - 1);
			pObjectAttrLow = pMemoryDB->m_SysMdbObjectAttrFactory->findByOne(
					objectid_OrderInsert,
					theDate,
					lowTime);
			pObjectAttrHigh = pMemoryDB->m_SysMdbObjectAttrFactory->findByOne(
					objectid_OrderInsert,
					theDate,
					highTime);
			if (pObjectAttrLow != NULL && pObjectAttrHigh != NULL)
			{
				break;
			}

			if (lowTime <= thePeakBaseTime)
			{
				break;
			}

			///如果从最新值的时间步长前有值（即当前步长尾值），则计其差值为暂定峰值
						///如果有一个为空，则继续向前找直到找到第一段可用区间
		}

		if (pObjectAttrLow != NULL && pObjectAttrHigh != NULL)
		{
			int tmp = atoi(pObjectAttrHigh->AttrValue.getValue()) - atoi(
					pObjectAttrLow->AttrValue.getValue());
			if (tmp > OrderInsertPeak)
			{
				OrderInsertPeak = tmp;
				peakTime = highTime;
			}
		}

		if (lowTime <= thePeakBaseTime)
		{
			break;
		}
	}

	///得到峰值区间上下限
	lowTime = getsTime(getiTime(peakTime) - timeFib2Front);
	tfield.PeakTime = peakTime;
	tfield.InsertOrder = OrderInsertPeak;

	///计算错单峰值：
	{
		CSysMdbObjectAttrFactory *pFactory = pMemoryDB->
			m_SysMdbObjectAttrFactory;
		CSysMdbObjectAttr *pHighAttr = pFactory->findByOne(
				objectid_ErrorOrder,
				theDate,
				peakTime);
		CSysMdbObjectAttr *pLowAttr = pFactory->findByOne(
				objectid_ErrorOrder,
				theDate,
				lowTime);
		if (pLowAttr != NULL && pHighAttr != NULL)
		{
			tfield.InvalidOrder = atoi(pHighAttr->AttrValue.getValue()) - atoi(
					pLowAttr->AttrValue.getValue());
		}
		else if (pHighAttr != NULL && pLowAttr == NULL)
		{
			tfield.InvalidOrder = atoi(pHighAttr->AttrValue.getValue());
		}
		else
		{
			tfield.InvalidOrder = 0;
		}
	}

	///计算报单操作峰值：
	{
		CSysMdbObjectAttrFactory *pFactory = pMemoryDB->
			m_SysMdbObjectAttrFactory;
		CSysMdbObjectAttr *pHighAttr = pFactory->findByOne(
				objectid_OrderAction,
				theDate,
				peakTime);
		CSysMdbObjectAttr *pLowAttr = pFactory->findByOne(
				objectid_OrderAction,
				theDate,
				lowTime);
		if (pLowAttr != NULL && pHighAttr != NULL)
		{
			tfield.ActionOrder = atoi(pHighAttr->AttrValue.getValue()) - atoi(
					pLowAttr->AttrValue.getValue());
		}
		else if (pHighAttr != NULL && pLowAttr == NULL)
		{
			tfield.ActionOrder = atoi(pHighAttr->AttrValue.getValue());
		}
		else
		{
			tfield.ActionOrder = 0;
		}
	}

	///计算报单成交峰值：
	{
		CSysMdbObjectAttrFactory *pFactory = pMemoryDB->
			m_SysMdbObjectAttrFactory;
		CSysMdbObjectAttr *pHighAttr = pFactory->findByOne(
				objectid_TradeSize,
				theDate,
				peakTime);
		CSysMdbObjectAttr *pLowAttr = pFactory->findByOne(
				objectid_TradeSize,
				theDate,
				lowTime);
		if (pLowAttr != NULL && pHighAttr != NULL)
		{
			tfield.TradeCount = atoi(pHighAttr->AttrValue.getValue()) - atoi(
					pLowAttr->AttrValue.getValue());
		}
		else if (pHighAttr != NULL && pLowAttr == NULL)
		{
			tfield.TradeCount = atoi(pHighAttr->AttrValue.getValue());
		}
		else
		{
			tfield.TradeCount = 0;
		}
	}

	tfield.TotalBusiness = tfield.InsertOrder + tfield.ActionOrder;
	tfield.TotalCount = tfield.TradeCount + tfield.TotalBusiness;
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
	pSession->SendRequestPackage(&m_pkgSend);

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTradepeakTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryWarningEventUpdateTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryWarningEventUpdateField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryWarningEventUpdateTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDReqQryWarningEventUpdateField tfield;
	CopySysWarningEventEntity(&tfield, &qryfield);
	tfield.ActiveDate = qryfield.ActiveDate;
	tfield.ActiveTime = qryfield.ActiveTime;
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
	if (g_CountConnector)
	{
		g_CountConnector->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryWarningActiveChange(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	// 直接转发给事件服务器
	CFTDReqQryWarningActiveChangeField	field;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &field) <= 0)
	{
		return;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryWarningActiveChange,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());
	FTDC_ADD_FIELD(&m_pkgSend, &field);
	if (g_CountConnector)
	{
		g_CountConnector->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQrySyslogEventUpdateTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQrySyslogEventUpdateField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_ReqQrySyslogEventUpdateTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDReqQrySyslogEventUpdateField tfield;
	CopySysWarningEventEntity(&tfield, &qryfield);
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
	if (g_CountConnector)
	{
		g_CountConnector->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnSysUserLoginTopic(
	CUserIDType UserID,
	int rID,
	CFTDCSession *pSession)
{
	if (pXMLDoc == NULL)
	{
		return;
	}

	CXMLNode *pXMLRootNode = new CXMLNode();
	pXMLRootNode = pXMLDoc->getRootNode();
	if (pXMLRootNode == NULL)
	{
		return;
	}

	CXMLNodeList *pNodeList = pXMLRootNode->getNodeList();
	if (!pNodeList)
	{
		return;
	}

	CXMLNodeList::iterator	it;
	for (it = pNodeList->begin(); it != pNodeList->end(); it++)
	{
		if (strcmp((*it)->findProperty("UserID"), UserID.getValue()) == 0)
		{
			break;
		}
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQrySysUserLoginTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(rID);

	CFTDRspQrySysUserLoginField tfield;
	memset(&tfield, 0, sizeof(tfield));
	strcpy((char *)(tfield.UserID.getValue()), (*it)->findProperty("UserID"));
	tfield.Privilege = atoi((*it)->findProperty("Privilege"));

	CDateType theDate;
	time_t	timep;
	time(&timep);
	
	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		(char *)(theDate.getValue()),
		"%d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);
	strcpy((char *)(tfield.TradingDay.getValue()), theDate.getValue());

	char theTime[10] = "";
	sprintf(
		(char *)(theTime),
		"%02d:%02d:%02d",
		tm_time.tm_hour,
		tm_time.tm_min,
		tm_time.tm_sec);
	strcpy((char *)(tfield.LoginTime.getValue()), theTime);

	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
	pSession->SendRequestPackage(&m_pkgSend);

	///发送时钟同步信息：
	m_pkgSend.PreparePackage(
			FTD_TID_RtnSysTimeSyncTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnSysTimeSyncField timeField;
	memset(&timeField, 0, sizeof(timeField));
	timeField.MonDate = theDate;
	strcpy((char *)(timeField.MonTime.getValue()), theTime);
	FTDC_ADD_FIELD(&m_pkgSend, &timeField);
	pSession->SendRequestPackage(&m_pkgSend);

	///发送主数据中心信息：
	m_pkgSend.PreparePackage(
			FTD_TID_RtnDataCenterChgTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	CFTDRtnDataCenterChgField datacenterField;
	memset(&datacenterField, 0, sizeof(datacenterField));
	datacenterField.DataCenterID = g_DataCenter;
	FTDC_ADD_FIELD(&m_pkgSend, &datacenterField);
	pSession->SendRequestPackage(&m_pkgSend);

	///加入全局登录队列
	g_mListAllSession.push_back((CFTDCSession *)pSession);

	MonitorOnlineUser theMonitorOnlineUser;
	strcpy(
		(char *)(theMonitorOnlineUser.IPAddress.getValue()),
		(const char *)(pSession->GetChannel()->GetRemoteName()));
	theMonitorOnlineUser.UserID = UserID;
	map_MonitorOnlineUser[pSession] = theMonitorOnlineUser;

	OnClientInit((CFTDCSession *)pSession);

	///发送所有用户信息：
	{
		CXMLNode *pXMLRootNode = new CXMLNode();
		pXMLRootNode = pXMLDoc->getRootNode();

		CXMLNodeList *pNodeList = pXMLRootNode->getNodeList();
		CXMLNodeList::iterator	itInit;
		for (itInit = pNodeList->begin(); itInit != pNodeList->end(); itInit++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSysUser,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRtnSysUserField tfield;
			memset(&tfield, 0, sizeof(tfield));

			strcpy(
				(char *)(tfield.UserID.getValue()),
				(*itInit)->findProperty("UserID"));
			strcpy(
				(char *)(tfield.UserName.getValue()),
				(*itInit)->findProperty("UserName"));
			strcpy(
				(char *)(tfield.UserInfo.getValue()),
				(*itInit)->findProperty("UserInfo"));
			strcpy(
				(char *)(tfield.Password.getValue()),
				(*itInit)->findProperty("Password"));
			tfield.Privilege = atoi((*itInit)->findProperty("Privilege"));
			strcpy(
				(char *)(tfield.EMail.getValue()),
				(*itInit)->findProperty("EMail"));
			tfield.EMailFlag = atoi((*itInit)->findProperty("EMailFlag"));
			strcpy(
				(char *)(tfield.HomePhone.getValue()),
				(*itInit)->findProperty("HomePhone"));
			tfield.HomePhoneFlag = atoi(
					(*itInit)->findProperty("HomePhoneFlag"));
			strcpy(
				(char *)(tfield.MobilePhone.getValue()),
				(*itInit)->findProperty("MobilePhone"));
			tfield.MobilePhoneFlag = atoi(
					(*itInit)->findProperty("MobilePhoneFlag"));

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
}

void CFrontServer::OnReqQrySysUserLoginTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQrySysUserLoginField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	///验证密码
	bool passwd_flag = true;	//密码正确标识符，默认为true
	if (pXMLDoc == NULL)
	{
		return;
	}

	CXMLNode *pXMLRootNode = new CXMLNode();
	pXMLRootNode = pXMLDoc->getRootNode();
	if (pXMLRootNode == NULL)
	{
		return;
	}

	CXMLNodeList *pNodeList = pXMLRootNode->getNodeList();
	if (!pNodeList)
	{
		return;
	}

	CXMLNodeList::iterator	it;
	for (it = pNodeList->begin(); it != pNodeList->end(); it++)
	{
		if (strcmp(
				(*it)->findProperty("UserID"),
			qryfield.UserID.getValue()) == 0)
		{
			CDesEncryptAlgorithm DesEncrypt;
			DesEncrypt.SetPassword("monitor");
            char* cs=new char[257];
			char* yuanwen=new char[257];
			cs=(char*)qryfield.Password.getValue();
			if (DesEncrypt.IsEnOrDe(cs))
			{		
				DesEncrypt.Decrypt(cs,yuanwen);
                qryfield.Password.setValue(yuanwen);
			}
			else
			{
				yuanwen=cs;
			}

			if (strcmp(
					(*it)->findProperty("Password"),
				yuanwen) == 0)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_ReqQrySysUserLoginTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &qryfield);
				m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());

				if (m_pSynConnector->GetQuerySession())
				{
					m_pSynConnector->GetQuerySession()->SendRequestPackage(
							&m_pkgSend);
				}

				passwd_flag = true;
				break;
			}
			else
			{
				passwd_flag = false;
				continue;
			}
		}
	}

	if (it == pNodeList->end())
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQrySysUserLoginTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		if (!passwd_flag)
		{
			rspInfoField.ErrorID = ERR_PSWWRONG;
			rspInfoField.ErrorMsg = "PassWord Error";
		}
		else
		{
			rspInfoField.ErrorID = ERR_USERWRONG;
			rspInfoField.ErrorMsg = "Can't Find User";
		}

		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQrySysUserLogoutTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQrySysUserLogoutField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQrySysUserLogoutTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDReqQrySysUserLogoutField tfield;
	memset(&tfield, 0, sizeof(tfield));
	tfield.UserID = qryfield.UserID;
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
	pSession->SendRequestPackage(&m_pkgSend);

	g_pListSessionArray->DelFTDSession((CFTDCSession *)pSession);
	g_mListAllSession.remove((CFTDCSession *)pSession);
	if (g_pPerformanceAnalyzer)
		g_pPerformanceAnalyzer->RemoveClientSession(((CFTDCSession *)pSession)->GetSessionID());
	map_MonitorOnlineUser.erase(pSession);

	//	pSession->Disconnect(0);
}

void CFrontServer::OnClientInit(CFTDCSession *pSession)
{
	{
		list<CFTDRtnWarningEventField>	theList;
		CSysWarningEvent *sfield = pMemoryDB->m_SysWarningEventFactory->
			startFindByAll();
		while (sfield)
		{
			if (sfield->WarningLevel == "info")
			{
				sfield = pMemoryDB->m_SysWarningEventFactory->findNextByAll();
				continue;
			}

			CFTDRtnWarningEventField tfield;
			CopySysWarningEventEntity(&tfield, sfield);
			theList.push_front(tfield);
			sfield = pMemoryDB->m_SysWarningEventFactory->findNextByAll();
		}

		pMemoryDB->m_SysWarningEventFactory->endFindByAll();
		if (pSession)
		{
			list<CFTDRtnWarningEventField>::iterator it = theList.begin();
			for (; it != theList.end(); it++)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RtnWarningEventTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(*it));
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}

	{
		list<CFTDRtnSyslogEventField> theList;
		CSyslogEvent *sfield = pMemoryDB->m_SyslogEventFactory->
			startFindBytheAll();
		while (sfield)
		{
			if (sfield->WarningLevel == "info")
			{
				sfield = pMemoryDB->m_SyslogEventFactory->findNextByAll();
				continue;
			}

			if (sfield->ProcessFlag == "N" || sfield->ProcessFlag == "G")
			{
				CFTDRtnSyslogEventField tfield;
				CopySysWarningEventEntity(&tfield, sfield);
				theList.push_front(tfield);
			}

			sfield = pMemoryDB->m_SyslogEventFactory->findNextBytheAll();
		}

		pMemoryDB->m_SyslogEventFactory->endFindBytheAll();
		if (pSession)
		{
			list<CFTDRtnSyslogEventField>::iterator it = theList.begin();
			for (; it != theList.end(); it++)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RtnSyslogEventTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(*it));
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}

	///初始化会员链路状态:
	{
		list<CFTDRtnNetPartyLinkStatusInfoField> theList;
		CSysMdbNetPartyLinkStatusInfo	*sfield = pMemoryDB->
			m_SysMdbNetPartyLinkStatusInfoFactory->startFindByAll();
		while (sfield)
		{
			CFTDRtnNetPartyLinkStatusInfoField	tfield;
			CopySysNetPartyLinkStatusInfoEntity(&tfield, sfield);
			theList.push_front(tfield);
			sfield = pMemoryDB->m_SysMdbNetPartyLinkStatusInfoFactory->findNextByAll();
		}

		pMemoryDB->m_SysMdbNetPartyLinkStatusInfoFactory->endFindByAll();
		if (pSession)
		{
			list<CFTDRtnNetPartyLinkStatusInfoField>::iterator	it = theList.
				begin();
			for (; it != theList.end(); it++)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RtnNetPartyLinkStatusInfoTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(*it));
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}

	list<CFTDRtnTradeUserLoginInfoField>::iterator	it = g_TradeUserLoginList.
		begin();
	for (; it != g_TradeUserLoginList.end(); it++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeUserLoginInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &(*it));
		if (pSession)
		{
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	
	list<CFTDRtnClientInfoField> theList;
	CSysClientInit* sfield = pMemoryDB->m_SysClientInitFactory->startFindByAll();
	while(sfield)
	{
		CFTDRtnClientInfoField tfield;
		CopySysClientInitEntity(&tfield, sfield);
		theList.push_back(tfield);
		sfield = pMemoryDB->m_SysClientInitFactory->findNextByAll();
	}
	pMemoryDB->m_SysClientInitFactory->endFindByAll();
	if (pSession)
	{
		list<CFTDRtnClientInfoField>::iterator	it = theList.begin();
		for (; it != theList.end(); it++)
		{
			m_pkgSend.PreparePackage(
				FTD_TID_RtnClientInfoTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(*it));
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
}

void CFrontServer::OnReqQryPartPosiLimitTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryPartPosiLimitField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	CSysPartPosiLimit *pfield = pMemoryDB->m_SysPartPosiLimitFactory->
		startFindByAll();
	while (pfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryPartPosiLimitTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryPartPosiLimitField field;
		memset(&field, 0, sizeof(field));
		CopySysPartPosiLimitEntity(&field, pfield);

		CSysPriceLimit	*pPriceLimitField = pMemoryDB->m_SysPriceLimitFactory->
			findByOne(pfield->InstrumentID);
		if (pPriceLimitField)
		{
			field.LowerLimitPrice = pPriceLimitField->LowerLimitPrice;
			field.UpperLimitPrice = pPriceLimitField->UpperLimitPrice;
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		pSession->SendRequestPackage(&m_pkgSend);
		pfield = pMemoryDB->m_SysPartPosiLimitFactory->findNextByAll();
	}

	pMemoryDB->m_SysPartPosiLimitFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryPartPosiLimitTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryClientPosiLimitTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryClientPosiLimitField	qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	CSysClientPosiLimit *pfield = pMemoryDB->m_SysClientPosiLimitFactory->
		startFindByAll();
	while (pfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryClientPosiLimitTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryClientPosiLimitField	field;
		memset(&field, 0, sizeof(field));
		CopySysClientPosiLimitEntity(&field, pfield);

		CSysPriceLimit	*pPriceLimitField = pMemoryDB->m_SysPriceLimitFactory->
			findByOne(pfield->InstrumentID);
		if (pPriceLimitField)
		{
			field.LowerLimitPrice = pPriceLimitField->LowerLimitPrice;
			field.UpperLimitPrice = pPriceLimitField->UpperLimitPrice;
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		pSession->SendRequestPackage(&m_pkgSend);
		pfield = pMemoryDB->m_SysClientPosiLimitFactory->findNextByAll();
	}

	pMemoryDB->m_SysClientPosiLimitFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryClientPosiLimitTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQrySpecialPosiLimitTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQrySpecialPosiLimitField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	CSysSpecialPosiLimit *pfield = pMemoryDB->m_SysSpecialPosiLimitFactory->
		startFindByAll();
	while (pfield)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQrySpecialPosiLimitTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQrySpecialPosiLimitField field;
		memset(&field, 0, sizeof(field));
		CopySysSpecialPosiLimitEntity(&field, pfield);

		CSysPriceLimit	*pPriceLimitField = pMemoryDB->m_SysPriceLimitFactory->
			findByOne(pfield->InstrumentID);
		if (pPriceLimitField)
		{
			field.LowerLimitPrice = pPriceLimitField->LowerLimitPrice;
			field.UpperLimitPrice = pPriceLimitField->UpperLimitPrice;
		}

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		pSession->SendRequestPackage(&m_pkgSend);
		pfield = pMemoryDB->m_SysSpecialPosiLimitFactory->findNextByAll();
	}

	pMemoryDB->m_SysSpecialPosiLimitFactory->endFindByAll();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQrySpecialPosiLimitTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryMonitorOnlineUser(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	map<CFTDCSession *, MonitorOnlineUser>::iterator it;
	for (it = map_MonitorOnlineUser.begin();
		 it != map_MonitorOnlineUser.end();
		 it++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryMonitorOnlineUser,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryMonitorOnlineUserField field;
		memset(&field, 0, sizeof(field));

		field.IPAddress = (*it).second.IPAddress;
		field.UserID = (*it).second.UserID;

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryMonitorOnlineUser,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryFrontStat(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	map<int, CFTDRspQryFrontStatField>::iterator itFront;
	for (itFront = g_FrontStatMap.begin();
		 itFront != g_FrontStatMap.end();
		 itFront++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryFrontStat,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryFrontStatField sfield;
		CopyRspQryFrontStatEntity(&sfield, &((*itFront).second));
		FTDC_ADD_FIELD(&m_pkgSend, &sfield);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryFrontStat,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryHistoryTradePeakTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	list<CFTDRtnHistoryTradePeakField>::iterator it = list_HistoryTradePeak.
		begin();
	for (; it != list_HistoryTradePeak.end(); it++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryHistoryTradePeakTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspQryHistoryTradePeakField tfield;
		CopyRspQryHistoryTradePeakEntity(&tfield, &(*it));
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryHistoryTradePeakTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQrySyslogEventSubcriberTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQrySyslogEventSubcriberField ftdQryField;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &ftdQryField) <= 0)
	{
		return;
	}

	cout <<
		"订阅事件:" <<
		ftdQryField.ObjectID <<
		"--" <<
		ftdQryField.EventName <<
		"--" <<
		ftdQryField.WarningLevel <<
		"--" <<
		ftdQryField.ObjectNum <<
		"--" <<
		ftdQryField.KeepAlive <<
		endl;

	if (ftdQryField.KeepAlive)
	{
		list<string> theListFilter;
		list<string> theListAnti;
		if (strcmp(ftdQryField.filter.getValue(), ""))
		{
			string	str1 = ftdQryField.filter.getValue();
			int index1 = 0;
			int index2 = str1.find(";");
			if (index2 <= 0)
			{
				theListFilter.push_back(str1.substr(index1, str1.size()));
			}

			while (index2 > 0)
			{
				theListFilter.push_back(str1.substr(index1, index2 - index1));
				index1 = index2 + 1;
				index2 = str1.find(";", index1);
				if (index2 <= 0)
				{
					theListFilter.push_back(str1.substr(index1, str1.size()));
				}
			}
		}

		if (strcmp(ftdQryField.antifilter.getValue(), ""))
		{
			string	str1 = ftdQryField.antifilter.getValue();
			list<string> theList;
			int index1 = 0;
			int index2 = str1.find(";");
			if (index2 <= 0)
			{
				theListAnti.push_back(str1.substr(index1, str1.size()));
			}

			while (index2 > 0)
			{
				theListAnti.push_back(str1.substr(index1, index2 - index1));
				index1 = index2 + 1;
				index2 = str1.find(";", index1);
				if (index2 <= 0)
				{
					theListAnti.push_back(str1.substr(index1, str1.size()));
				}
			}
		}

		list<CFTDRtnSyslogEventField> listField;
		int num = 0;
		CSyslogEvent *sfield = pMemoryDB->m_SyslogEventFactory->
			startFindBytheAll();
		while (sfield)
		{
			if ((
					sfield->ObjectID == ftdQryField.ObjectID
			||	ftdQryField.ObjectID == ""
			)
			&&	(
					sfield->EventName == ftdQryField.EventName
			||	ftdQryField.EventName == ""
			)
			&&	(
					sfield->ProcessFlag == ftdQryField.ProcessFlag
			||	ftdQryField.ProcessFlag == ""
			)
			&&	(
					sfield->WarningLevel == ftdQryField.WarningLevel
			||	ftdQryField.WarningLevel == ""
			))
			{
				if (strcmp(ftdQryField.filter.getValue(), ""))
				{
					string	str = sfield->EventDes.getValue();
					list<string>::iterator	itList = theListFilter.begin();
					for (; itList != theListFilter.end(); itList++)
					{
						int iv = str.find(*itList);
						if (iv < 0)
						{
							break;
						}
					}

					if (itList != theListFilter.end())
					{
						sfield = pMemoryDB->m_SyslogEventFactory->findNextBytheAll();
						continue;
					}
				}

				if (strcmp(ftdQryField.antifilter.getValue(), ""))
				{
					string	str = sfield->EventDes.getValue();
					list<string>::iterator	itList = theListAnti.begin();
					for (; itList != theListAnti.end(); itList++)
					{
						int iv = str.find(*itList);
						if (iv > 0)
						{
							break;
						}
					}

					if (itList != theListAnti.end())
					{
						sfield = pMemoryDB->m_SyslogEventFactory->findNextBytheAll();
						continue;
					}
				}

				if (ftdQryField.ObjectNum >= 0)
				{
					if (num == ftdQryField.ObjectNum)
					{
						break;
					}

					num++;
				}
				else
				{
					if (sfield->MonDate < ftdQryField.MonDate
					||	(
							sfield->MonDate == ftdQryField.MonDate
					&&	sfield->MonTime < ftdQryField.MonTime
					))
					{
						break;
					}
				}

				CFTDRtnSyslogEventField tfield;
				CopySysWarningEventEntity(&tfield, sfield);
				listField.push_front(tfield);
			}

			sfield = pMemoryDB->m_SyslogEventFactory->findNextBytheAll();
		}

		pMemoryDB->m_SyslogEventFactory->endFindBytheAll();

		list<CFTDRtnSyslogEventField>::iterator it = listField.begin();
		for (; it != listField.end(); it++)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(*it));
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}

	///解决订阅问题：
	{
		list<EventSubInfo>::iterator it = g_EventSubList.begin();
		for (; it != g_EventSubList.end(); it++)
		{
			if (((*it).EventName == ftdQryField.EventName)
			&&	((*it).ObjectID == ftdQryField.ObjectID)
			&&	((*it).ProcessFlag == ftdQryField.ProcessFlag)
			&&	((*it).WarningLevel == ftdQryField.WarningLevel)
			&&	((*it).filter == ftdQryField.filter)
			&&	((*it).antifilter == ftdQryField.antifilter))
			{
				break;
			}
		}

		if (it == g_EventSubList.end())
		{
			if (ftdQryField.KeepAlive)
			{
				EventSubInfo info;
				info.EventName = ftdQryField.EventName;
				info.ObjectID = ftdQryField.ObjectID;
				info.WarningLevel = ftdQryField.WarningLevel;
				info.antifilter = ftdQryField.antifilter;
				info.filter = ftdQryField.filter;
				info.ProcessFlag = ftdQryField.ProcessFlag;

				list<CFTDCSession *> theList;
				theList.push_back(pSession);
				info.Receiver = theList;
				g_EventSubList.push_back(info);
			}
		}
		else
		{
			if (ftdQryField.KeepAlive)
			{
				(*it).Receiver.push_back(pSession);
			}
			else
			{
				list<CFTDCSession *>::iterator	itList = (*it).Receiver.begin();
				while (itList != (*it).Receiver.end())
				{
					list<CFTDCSession *>::iterator	itListTmp = itList;
					itListTmp++;
					if ((*itList) == pSession)
					{
						(*it).Receiver.erase(itList);
					}

					itList = itListTmp;
				}

				if ((*it).Receiver.size() == 0)
				{
					g_EventSubList.erase(it);
				}
			}
		}
	}
}

void CFrontServer::OnReqQrySyslogEventTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQrySyslogEventField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}
	string str_ip_address = qryfield.IPAddress.getValue();
	int find_pos = str_ip_address.find("IP=");
	if (find_pos==string::npos)
	{
		CSyslogEvent *sfield = NULL;

		if(qryfield.EventType.getValue() == 0)
		{
			sfield = pMemoryDB->m_SyslogEventFactory->startFindByTime(
				qryfield.EndDate,
				qryfield.EndTime);
		}
		else
		{
			sfield = pMemoryDB->m_SyslogEventFactory->startFindByAll();
		}
		
		int count = 0;
		while (sfield)
		{
			if(qryfield.EventType.getValue() == 0)
			{
				//普通查询
				if ((sfield->MonDate < qryfield.StartDate)
				||	(
						sfield->MonDate == qryfield.StartDate
				&&	sfield->OccurTime < qryfield.StartTime
				))
				{
					break;
				}

				if ((
						(sfield->ObjectID == qryfield.ObjectID)
				||	(qryfield.ObjectID == "")
				)
				&&	(
						(sfield->EventName == qryfield.EventName)
				||	(qryfield.EventName == "")
				)
				&&	(
						(sfield->WarningLevel == qryfield.WarningLevel)
				||	(qryfield.WarningLevel == "")
				))
				{
					m_pkgSend.PreparePackage(
							FTD_TID_RspQrySyslogEventTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);
					m_pkgSend.SetRequestId(pPackage->GetRequestId());

					CFTDRspQrySyslogEventField	tfield;

					CopySysWarningEventEntity(&tfield, sfield);

					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					pSession->SendRequestPackage(&m_pkgSend);

					//一次最多发2000条
					if (++count > 2000)
					{
						break;
					}
				}
			}
			else
			{
				//一次最多查2000条
				if (++count > 2000)
				{
					break;
				}

				int resultcount = 0;
				bool needsend = false;
					
				//精确查询
				if(qryfield.IPAddress == sfield->IPAddress)
				{
					//IP比对
					if(qryfield.ObjectID != "")
					{
						//还要进行objectid比对
						if(qryfield.ObjectID == sfield->ObjectID)
						{
							//满足条件								
							needsend = true;								
						}
					}
					else
					{
						//满足条件						
						needsend = true;											
					}

					if(needsend)
					{
						m_pkgSend.PreparePackage(
								FTD_TID_RspQrySyslogEventTopic,
								FTDC_CHAIN_CONTINUE,
								FTD_VERSION);
						m_pkgSend.SetRequestId(pPackage->GetRequestId());

						CFTDRspQrySyslogEventField	tfield;

						CopySysWarningEventEntity(&tfield, sfield);

						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						pSession->SendRequestPackage(&m_pkgSend);

						if (++resultcount > 200)
						{
							break;
						}							
					}
				}
			}

			if(qryfield.EventType.getValue() == 0)
			{
				sfield = pMemoryDB->m_SyslogEventFactory->findNextByTime();
			}
			else
			{
				sfield = pMemoryDB->m_SyslogEventFactory->findNextByAll();
			}
		}
		
		if(qryfield.EventType.getValue() == 0)
		{
			pMemoryDB->m_SyslogEventFactory->endFindByTime();
		}
		else
		{
			pMemoryDB->m_SyslogEventFactory->endFindByAll();
		}
	}
	else
	{
		str_ip_address = str_ip_address.substr(find_pos+3, str_ip_address.length()-find_pos-3);
		bool bCheckDateTime(true);
		if (qryfield.StartDate=="" && qryfield.StartTime=="" && qryfield.EndDate=="" && qryfield.EndTime=="")	bCheckDateTime = false;

		if (str_ip_address == "")
		{
			if (!bCheckDateTime)
			{
				CSyslogEvent *sfield = pMemoryDB->m_SyslogEventFactory->startFindByAll();
				int count = 0;
				vector<string> vecIPCollection;
				while (sfield)
				{
					if ((
						(sfield->ObjectID == qryfield.ObjectID)
						||	(qryfield.ObjectID == "")
						)
						&&	(
						(sfield->EventName == qryfield.EventName)
						||	(qryfield.EventName == "")
						)
						&&	(
						(sfield->WarningLevel == qryfield.WarningLevel)
						||	(qryfield.WarningLevel == "")
						))
					{
						CFTDRspQrySyslogEventField	tfield;
						CopySysWarningEventEntity(&tfield, sfield);
						string strIPAddr=tfield.IPAddress.getValue();
						string str_event_des=(tfield.EventDes.getValue());
						size_t pos = str_event_des.find("IP=");
						if (pos!=string::npos)
						{
							strIPAddr = str_event_des.substr(pos+3, str_event_des.length()-pos-3);
						}
						else
						{
							sfield = pMemoryDB->m_SyslogEventFactory->findNextByAll();
							continue;
						}

						//if (find(vecIPCollection.begin(),vecIPCollection.end(), strIPAddr)==vecIPCollection.end())
						//{
						//	m_pkgSend.PreparePackage(
						//		FTD_TID_RspQrySyslogEventTopic,
						//		FTDC_CHAIN_CONTINUE,
						//		FTD_VERSION);
						//	m_pkgSend.SetRequestId(pPackage->GetRequestId());

						//	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						//	pSession->SendRequestPackage(&m_pkgSend);

						//	vecIPCollection.push_back(strIPAddr);
						//}

						map<string, map<string, CFTDRspQrySyslogEventField> >::iterator iterFindIP(m_mapIPSyslogDetail.find(strIPAddr));
						if (iterFindIP==m_mapIPSyslogDetail.end())
						{
							string strDate=(tfield.MonDate.getValue());
							string strTime=(tfield.OccurTime.getValue());
							string strDateTime=(strDate+strTime);
							map<string, CFTDRspQrySyslogEventField> mapSyslogEvent;
							mapSyslogEvent.insert(make_pair(strDateTime, tfield));
							m_mapIPSyslogDetail.insert(make_pair(strIPAddr, mapSyslogEvent));		
						}
						else
						{
							string strDate=(tfield.MonDate.getValue());
							string strTime=(tfield.OccurTime.getValue());
							string strDateTime=(strDate+strTime);
							map<string, CFTDRspQrySyslogEventField>::iterator iterFindDateTime(iterFindIP->second.find(strDateTime));
							if (iterFindDateTime==iterFindIP->second.end())
							{
								//map<string, CFTDRspQrySyslogEventField> mapSyslogEvent;
								//mapSyslogEvent.insert(make_pair(strDateTime, tfield));
								//m_mapIPSyslogDetail.insert(make_pair(strIPAddr, mapSyslogEvent));	
								iterFindIP->second.insert(make_pair(strDateTime, tfield));
							}
						}

					}

					sfield = pMemoryDB->m_SyslogEventFactory->findNextByAll();
				}
				pMemoryDB->m_SyslogEventFactory->endFindByAll();

				map<string, map<string, CFTDRspQrySyslogEventField> >::iterator iterStepElement;
				for (iterStepElement=m_mapIPSyslogDetail.begin(); iterStepElement!=m_mapIPSyslogDetail.end(); ++iterStepElement)
				{
					map<string, CFTDRspQrySyslogEventField>	mapSpecialElement;
					map<string, CFTDRspQrySyslogEventField>::reverse_iterator r_iter(iterStepElement->second.rbegin());
					for (r_iter=iterStepElement->second.rbegin(); r_iter!=iterStepElement->second.rend(); ++r_iter)
					{
						string str_obj = r_iter->second.ObjectID.getValue();
						size_t pos1 = str_obj.find("app.");
						if (pos1==string::npos)	continue;
						string str_attr = str_obj.substr(pos1+4,str_obj.length()-pos1-4);
						pos1 = str_attr.find(".");
						if (pos1!=string::npos)
						{
							str_attr = str_attr.substr(0,pos1);
						}
						map<string, CFTDRspQrySyslogEventField>::iterator iterFindElement(mapSpecialElement.find(str_attr));
						if (iterFindElement == mapSpecialElement.end())
						{
							r_iter->second.EventCount = 1;
							mapSpecialElement.insert(make_pair(str_attr, r_iter->second));
						}
						else
						{
							iterFindElement->second.EventCount = iterFindElement->second.EventCount+1;
						}
					}
					for (map<string, CFTDRspQrySyslogEventField>::iterator iterElement=mapSpecialElement.begin(); iterElement!=mapSpecialElement.end(); ++iterElement)
					{
						CFTDRspQrySyslogEventField	tfield=iterElement->second;

						m_pkgSend.PreparePackage(
							FTD_TID_RspQrySyslogEventTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);
						m_pkgSend.SetRequestId(pPackage->GetRequestId());

						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						pSession->SendRequestPackage(&m_pkgSend);
					}
				}
			}
			else
			{
				CSyslogEvent *sfield = pMemoryDB->m_SyslogEventFactory->startFindByTime(
					qryfield.EndDate,
					qryfield.EndTime);
				int count = 0;
				map<string, map<string, CFTDRspQrySyslogEventField> > mapIPCollection;
				while (sfield)
				{
					if ((sfield->MonDate < qryfield.StartDate)
						||	(
						sfield->MonDate == qryfield.StartDate
						&&	sfield->OccurTime < qryfield.StartTime
						))
					{
						break;
					}

					if ((
						(sfield->ObjectID == qryfield.ObjectID)
						||	(qryfield.ObjectID == "")
						)
						&&	(
						(sfield->EventName == qryfield.EventName)
						||	(qryfield.EventName == "")
						)
						&&	(
						(sfield->WarningLevel == qryfield.WarningLevel)
						||	(qryfield.WarningLevel == "")
						))
					{
						CFTDRspQrySyslogEventField	tfield;
						CopySysWarningEventEntity(&tfield, sfield);
						string strIPAddr=(tfield.IPAddress.getValue());
						string str_event_des=(tfield.EventDes.getValue());
						size_t pos = str_event_des.find("IP=");
						if (pos!=string::npos)
						{
							strIPAddr = str_event_des.substr(pos+3, str_event_des.length()-pos-3);
						}
						else
						{
							sfield = pMemoryDB->m_SyslogEventFactory->findNextByTime();
							continue;
						}

						string strDate=(tfield.MonDate.getValue());
						string strTime=(tfield.OccurTime.getValue());
						string strDateTime=(strDate+strTime);
						map<string, map<string, CFTDRspQrySyslogEventField> >::iterator iterGetIP(mapIPCollection.find(strIPAddr));
						if (iterGetIP==mapIPCollection.end())
						{
							tfield.EventCount = 1;
							map<string, CFTDRspQrySyslogEventField> mapSyslogEvent;
							mapSyslogEvent.insert(make_pair(strDateTime, tfield));
							mapIPCollection.insert(make_pair(strIPAddr, mapSyslogEvent));	
						}
						else
						{
							map<string, CFTDRspQrySyslogEventField>::iterator iterFindDateTime(iterGetIP->second.find(strDateTime));
							if (iterFindDateTime==iterGetIP->second.end())
							{
								iterGetIP->second.insert(make_pair(strDateTime, tfield));		
							}
						}

						map<string, map<string, CFTDRspQrySyslogEventField> >::iterator iterFindIP(m_mapIPSyslogDetail.find(strIPAddr));
						if (iterFindIP==m_mapIPSyslogDetail.end())
						{
							map<string, CFTDRspQrySyslogEventField> mapSyslogEvent;
							mapSyslogEvent.insert(make_pair(strDateTime, tfield));
							m_mapIPSyslogDetail.insert(make_pair(strIPAddr, mapSyslogEvent));		
						}
						else
						{
							int nCount = iterFindIP->second.size();
							map<string, CFTDRspQrySyslogEventField>::iterator iterFindDateTime(iterFindIP->second.find(strDateTime));
							if (iterFindDateTime==iterFindIP->second.end())
							{
								//map<string, CFTDRspQrySyslogEventField> mapSyslogEvent;
								//mapSyslogEvent.insert(make_pair());
								iterFindIP->second.insert(make_pair(strDateTime, tfield));
								//m_mapIPSyslogDetail.insert(make_pair(strIPAddr, mapSyslogEvent));		
							}
						}

					}

					sfield = pMemoryDB->m_SyslogEventFactory->findNextByTime();
				}
				pMemoryDB->m_SyslogEventFactory->endFindByTime();

				int nCount = m_mapIPSyslogDetail.size();
				map<string, map<string, CFTDRspQrySyslogEventField> >::iterator iterStepElement;
				for (iterStepElement=mapIPCollection.begin(); iterStepElement!=mapIPCollection.end(); ++iterStepElement)
				{
					map<string, CFTDRspQrySyslogEventField>	mapSpecialElement;
					map<string, CFTDRspQrySyslogEventField>::reverse_iterator r_iter(iterStepElement->second.rbegin());
					for (r_iter=iterStepElement->second.rbegin(); r_iter!=iterStepElement->second.rend(); ++r_iter)
					{
						string str_obj = r_iter->second.ObjectID.getValue();
						size_t pos1 = str_obj.find("app.");
						if (pos1==string::npos)	continue;
						string str_attr = str_obj.substr(pos1+4,str_obj.length()-pos1-4);
						pos1 = str_attr.find(".");
						if (pos1!=string::npos)
						{
							str_attr = str_attr.substr(0,pos1);
						}
						map<string, CFTDRspQrySyslogEventField>::iterator iterFindElement(mapSpecialElement.find(str_attr));
						if (iterFindElement == mapSpecialElement.end())
						{
							r_iter->second.EventCount = 1;
							mapSpecialElement.insert(make_pair(str_attr, r_iter->second));
						}
						else
						{
							iterFindElement->second.EventCount = iterFindElement->second.EventCount+1;
						}
					}
					for (map<string, CFTDRspQrySyslogEventField>::iterator iterElement=mapSpecialElement.begin(); iterElement!=mapSpecialElement.end(); ++iterElement)
					{
						CFTDRspQrySyslogEventField	tfield=iterElement->second;

						m_pkgSend.PreparePackage(
							FTD_TID_RspQrySyslogEventTopic,
							FTDC_CHAIN_CONTINUE,
							FTD_VERSION);
						m_pkgSend.SetRequestId(pPackage->GetRequestId());

						FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						pSession->SendRequestPackage(&m_pkgSend);
					}
				}
				mapIPCollection.clear();
			}

		}
		else
		{
			string strIPAddr=str_ip_address;
			map<string, map<string, CFTDRspQrySyslogEventField> >::iterator iterFindIP(m_mapIPSyslogDetail.find(strIPAddr));
			if (iterFindIP!=m_mapIPSyslogDetail.end())
			{
				int nCount = iterFindIP->second.size();
				map<string, CFTDRspQrySyslogEventField>::iterator iterElement;
				for (iterElement=iterFindIP->second.begin(); iterElement!=iterFindIP->second.end(); ++iterElement)
				{
					CFTDRspQrySyslogEventField	tfield=iterElement->second;
					if (bCheckDateTime)
					{
						if (tfield.MonDate<qryfield.StartDate 
							|| (tfield.MonDate==qryfield.StartDate && tfield.OccurTime<qryfield.StartTime)
							|| tfield.MonDate>qryfield.EndDate
							|| (tfield.MonDate==qryfield.EndDate && tfield.OccurTime>qryfield.EndTime))
						{
							continue;
						}
					}
					string strObjSample(qryfield.ObjectID.getValue());
					string strObjNow(tfield.ObjectID.getValue());
					if (strObjNow.find(strObjSample)==string::npos)	continue;

					m_pkgSend.PreparePackage(
						FTD_TID_RspQrySyslogEventTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
					m_pkgSend.SetRequestId(pPackage->GetRequestId());

					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					pSession->SendRequestPackage(&m_pkgSend);
				}
			}
		}	
	}

	/*
	CTimeType theTime;
	CDateType beginDate;
	time_t timep;
	time(&timep);
	timep -=g_FrontRange*3600;
	struct tm *pGm = localtime(&timep);
	sprintf((char *)(theTime.getValue()),"%02d:%02d:%02d", pGm->tm_hour, pGm->tm_min, pGm->tm_sec);
	sprintf((char *)(beginDate.getValue()),"%d%02d%02d" ,pGm->tm_year+1900 ,pGm->tm_mon+1 ,pGm->tm_mday);

	if(qryfield.StartDate <beginDate)
	{
		TRID rid;
		rid.SessionID =pSession->GetSessionID();
		rid.RequestId =pPackage->GetRequestId();
		int nRid =m_Rid++;
		m_vRid[nRid] =rid;

		m_pkgSend.PreparePackage(FTD_TID_ReqQrySyslogEventTopic, FTDC_CHAIN_LAST, FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &qryfield);
		m_pkgSend.SetRequestId(nRid);

#ifdef PACKAGE_OUTPUT
		m_pkgSend.OutputHeader(g_pFwdPackOutput);
		FTDC_DEBUG_BODY(m_pkgSend.GetTID(), &m_pkgSend, g_pFwdPackOutput);
#endif

		if(m_pQueryAgent->GetQuerySession())
		{
			m_pQueryAgent->GetQuerySession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			m_pkgSend.PreparePackage(FTD_TID_RspQryWarningEventTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());
			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField ,0 ,sizeof(rspInfoField));
			rspInfoField.ErrorID =ERR_QRYACCWRONG;
			rspInfoField.ErrorMsg ="QueryConnectError";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
	else if(strcmp(qryfield.StartDate.getValue(), beginDate.getValue()) >0)
	{
		return;
	}
*/
	//	else
	{
		//CSyslogEvent *sfield = pMemoryDB->m_SyslogEventFactory->startFindByTime(
		//		qryfield.EndDate,
		//		qryfield.EndTime);
		//int count = 0;
		//while (sfield)
		//{
		//	if ((sfield->MonDate < qryfield.StartDate)
		//	||	(
		//			sfield->MonDate == qryfield.StartDate
		//	&&	sfield->OccurTime < qryfield.StartTime
		//	))
		//	{
		//		break;
		//	}

		//	if ((
		//			(sfield->ObjectID == qryfield.ObjectID)
		//	||	(qryfield.ObjectID == "")
		//	)
		//	&&	(
		//			(sfield->EventName == qryfield.EventName)
		//	||	(qryfield.EventName == "")
		//	)
		//	&&	(
		//			(sfield->WarningLevel == qryfield.WarningLevel)
		//	||	(qryfield.WarningLevel == "")
		//	))
		//	{
		//		m_pkgSend.PreparePackage(
		//				FTD_TID_RspQrySyslogEventTopic,
		//				FTDC_CHAIN_CONTINUE,
		//				FTD_VERSION);
		//		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		//		CFTDRspQrySyslogEventField	tfield;

		//		CopySysWarningEventEntity(&tfield, sfield);

		//		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//		pSession->SendRequestPackage(&m_pkgSend);

		//		//一次最多发2000条
		//		if (++count > 2000)
		//		{
		//			break;
		//		}
		//	}

		//	sfield = pMemoryDB->m_SyslogEventFactory->findNextByTime();
		//}

		//pMemoryDB->m_SyslogEventFactory->endFindByTime();
		m_pkgSend.PreparePackage(
				FTD_TID_RspQrySyslogEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = 0;
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryTomcatInfoTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTomcatInfoField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryTomcatInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &qryfield);
	m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());

#ifdef PACKAGE_OUTPUT
	m_pkgSend.OutputHeader(g_pFwdPackOutput);
	FTDC_DEBUG_BODY(m_pkgSend.GetTID(), &m_pkgSend, g_pFwdPackOutput);
#endif
	if (m_pCountConnector->GetCountSession())
	{
		m_pCountConnector->GetCountSession()->SendRequestPackage(&m_pkgSend);
	}
	else
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryFrontInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = ERR_QRYACCWRONG;
		rspInfoField.ErrorMsg = "CountConnectError";
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryDBQueryTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryDBQueryField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryDBQueryTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &qryfield);
	m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());

#ifdef PACKAGE_OUTPUT
	m_pkgSend.OutputHeader(g_pFwdPackOutput);
	FTDC_DEBUG_BODY(m_pkgSend.GetTID(), &m_pkgSend, g_pFwdPackOutput);
#endif
	if (m_pCountConnector->GetCountSession())
	{
		m_pCountConnector->GetCountSession()->SendRequestPackage(&m_pkgSend);
	}
	else
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryFrontInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = ERR_QRYACCWRONG;
		rspInfoField.ErrorMsg = "CountConnectError";
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryGetFileTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryGetFileField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.FileName != "NetMonitor_Setup.EXE"
	&&	qryfield.FileName != "TradeMonitor_Setup.EXE"
	&&	qryfield.FileName != "BusinessMonitor_Setup.EXE"
	&&	qryfield.FileName != "GlobalMonitor_Setup.EXE")
	{
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryGetFileTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &qryfield);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());

		if (m_pCountConnector->GetCountSession())
		{
			m_pCountConnector->GetCountSession()->SendRequestPackage(
					&m_pkgSend);
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_QRYACCWRONG;
			rspInfoField.ErrorMsg = "CountConnectError";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		return;
	}
	else
	{
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryGetFileTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &qryfield);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());

		if (m_pSynConnector->GetQuerySession())
		{
			m_pSynConnector->GetQuerySession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryGetFileTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_QRYACCWRONG;
			rspInfoField.ErrorMsg = "CountConnectError";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		return;
	}
}

void CFrontServer::OnReqQryWarningQueryTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryWarningQueryField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	CSysWarningQuery *pEvent = pMemoryDB->m_SysWarningQueryFactory->
		findByEvendID(qryfield.EvendID);
	if (pEvent)
	{
		CFTDRspQryWarningQueryField tfield;
		CopySysWarningQueryEntity(&tfield, pEvent);
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryWarningQueryTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);
	}
	else
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryFrontInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = ERR_QRYACCWRONG;
		rspInfoField.ErrorMsg = "CountConnectError";
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryGeneralOperateTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryGeneralOperateField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &qryfield) <= 0)
	{
		return;
	}

	CFTDReqQryGeneralOperateField field;
	CopyReqQryGeneralOperateEntity(&field, &qryfield);
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryGeneralOperateTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &field);
	m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
	if (m_pSynConnector->GetQuerySession())
	{
		m_pSynConnector->GetQuerySession()->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryNetMonitorTaskResultTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorTaskResultField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	// 转给syseventcounter
	if (qryfield.OperationType == 10)
	{
		CFTDReqQryNetMonitorTaskResultField field;
		CopyReqQryNetMonitorTaskResultEntity(&field, &qryfield);
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryNetMonitorTaskResultTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &field);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
		if (m_pCountConnector->GetCountSession())
		{
			m_pCountConnector->GetCountSession()->SendRequestPackage(
					&m_pkgSend);
			return;
		}

		return;
	}

	// 历史结果查询，转给sysquery
	if (qryfield.MonDate < NowDate 
		|| qryfield.Task_ID==-1 ) //li.sc 与客户端约定taskid=-1 为历史查询，单独请求处理.
	{
		CFTDReqQryNetMonitorTaskResultField field;
		CopyReqQryNetMonitorTaskResultEntity(&field, &qryfield);
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryNetMonitorTaskResultTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &field);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
		if (m_pQueryAgent->GetQuerySession())
		{
			m_pQueryAgent->GetQuerySession()->SendRequestPackage(&m_pkgSend);
			return;
		}

		return;
	}

	if (qryfield.Task_ID != 0)
	{
		if (qryfield.ObjectID == "" && qryfield.OperateTime == 0)
		{
			CSysNetMonitorTaskResult *sfield = pMemoryDB->
				m_SysNetMonitorTaskResultFactory->startFindByTask_ID(
						NowDate,
						qryfield.Task_ID);
			while (sfield)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());

				CFTDRspQryNetMonitorTaskResultField tfield;
				CopySysNetMonitorTaskResultEntity(&tfield, sfield);
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);

				sfield = pMemoryDB->m_SysNetMonitorTaskResultFactory->findNextByTask_ID();
			}

			pMemoryDB->m_SysNetMonitorTaskResultFactory->endFindByTask_ID();
		}
		else
		{
			CSysNetMonitorTaskResult *sfield = pMemoryDB->
				m_SysNetMonitorTaskResultFactory->startFindByIDTaskTime(
						NowDate,
						qryfield.Task_ID,
						qryfield.ObjectID,
						qryfield.OperateTime);
			while (sfield)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());

				CFTDRspQryNetMonitorTaskResultField tfield;
				CopySysNetMonitorTaskResultEntity(&tfield, sfield);
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);

				sfield = pMemoryDB->m_SysNetMonitorTaskResultFactory->findNextByIDTaskTime();
			}

			pMemoryDB->m_SysNetMonitorTaskResultFactory->endFindByIDTaskTime();
		}
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryNetMonitorTaskResultTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryNetMonitorTaskStatusResultTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetMonitorTaskStatusResultField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.OperationType == 1)
	{
		{
			CSysNetMonitorTaskResult *sfield = pMemoryDB->
				m_SysNetMonitorTaskResultFactory->startFindByAll();
			while (sfield)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());

				CFTDRspQryNetMonitorTaskStatusResultField tfield;
				CopySysNetMonitorTaskStatusResultEntity(&tfield, sfield);
				tfield.OperationType = 2;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);

				sfield = pMemoryDB->m_SysNetMonitorTaskResultFactory->findNextByAll();
			}

			pMemoryDB->m_SysNetMonitorTaskResultFactory->endFindByAll();
		}
	}
	else if (qryfield.OperationType == 10)
	{								   
		CFTDReqQryNetMonitorTaskStatusResultField field;
		CopyReqQryNetMonitorTaskStatusResultEntity(&field, &qryfield);
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryNetMonitorTaskStatusResultTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &field);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
		if (m_pSynConnector->GetQuerySession())
		{
			m_pSynConnector->GetQuerySession()->SendRequestPackage(&m_pkgSend);
			return;
		}
	}
	else if (qryfield.OperationType == 11)
	{
		if (qryfield.MonDate < NowDate)
		{
			CFTDReqQryNetMonitorTaskStatusResultField field;
			CopyReqQryNetMonitorTaskStatusResultEntity(&field, &qryfield);
			m_pkgSend.PreparePackage(
					FTD_TID_ReqQryNetMonitorTaskStatusResultTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
			if (m_pQueryAgent->GetQuerySession())
			{
				m_pSynConnector->GetQuerySession()->SendRequestPackage(
						&m_pkgSend);
				return;
			}
		}

		CSysNetMonitorTaskResult *sfield = pMemoryDB->
			m_SysNetMonitorTaskResultFactory->startFindByOnlyDate(NowDate);
		while (sfield)
		{
			//if(sfield->Flag >0 &&sfield->Flag <21 &&sfield->Flag !=8 &&sfield->Flag !=10)
			if (sfield->Flag != 21
			&&	(
					qryfield.Task_ID == 0
			||	sfield->Task_ID == qryfield.Task_ID
			))
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());

				CFTDRspQryNetMonitorTaskStatusResultField tfield;
				CopySysNetMonitorTaskStatusResultEntity(&tfield, sfield);
				tfield.OperationType = qryfield.OperationType;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);
			}

			sfield = pMemoryDB->m_SysNetMonitorTaskResultFactory->findNextByOnlyDate();
		}

		pMemoryDB->m_SysNetMonitorTaskResultFactory->endFindByOnlyDate();
	}
	else if (qryfield.OperationType == 12)
	{
		if (qryfield.MonDate < NowDate)
		{
			CFTDReqQryNetMonitorTaskStatusResultField field;
			CopyReqQryNetMonitorTaskStatusResultEntity(&field, &qryfield);
			m_pkgSend.PreparePackage(
					FTD_TID_ReqQryNetMonitorTaskStatusResultTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
			if (m_pQueryAgent->GetQuerySession())
			{
				m_pSynConnector->GetQuerySession()->SendRequestPackage(
						&m_pkgSend);
				return;
			}
		}

		map<int, map<int, CFTDRspQryNetMonitorTaskStatusResultField> >::iterator
			it = g_taskOperTimes.find(qryfield.Task_ID);
		if (it != g_taskOperTimes.end())
		{
			map<int, CFTDRspQryNetMonitorTaskStatusResultField>::iterator
				itVec = it->second.begin();
			for (; itVec != it->second.end(); itVec++)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());

				CFTDRspQryNetMonitorTaskStatusResultField tfield;
				CopySysNetMonitorTaskStatusResultEntity(
					&tfield,
					&(itVec->second));
				tfield.OperationType = qryfield.OperationType;
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryNetMonitorTaskStatusResultTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryTradeUserLoginStatTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeUserLoginStatField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}
	CFTDReqQryTradeUserLoginStatField field;
	CopyReqQryTradeUserLoginStatEntity(&field, &qryfield);
	m_pkgSend.PreparePackage(
			FTD_TID_ReqQryTradeUserLoginStatTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &field);
	m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
	if (m_pFlowConnector->GetFlowSession())
	{
		m_pFlowConnector->GetFlowSession()->SendRequestPackage(&m_pkgSend);
	}
	else
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTradeUserLoginStatTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = ERR_QRYACCWRONG;
		rspInfoField.ErrorMsg = "FlowConnectError";
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pSession->SendRequestPackage(&m_pkgSend);
	}
}

void CFrontServer::OnReqQryNetRoomTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryNetRoomField	qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	if (qryfield.ID >= -4 && qryfield.ID <= -1)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryNetRoomTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &qryfield);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());

		if (m_pCountConnector->GetCountSession())
		{
			m_pCountConnector->GetCountSession()->SendRequestPackage(
					&m_pkgSend);
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetRoomTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_QRYACCWRONG;
			rspInfoField.ErrorMsg = "CountConnectError";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
		}
	}
}

void CFrontServer::OnReqQryParticTradeOrderStatesTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryParticTradeOrderStatesField qryfield;
	if (FTDC_GET_SINGLE_FIELD(pPackage, &qryfield) <= 0)
	{
		return;
	}

	//向数据库请求历史
	if (qryfield.ParticipantID == "yesterday" && qryfield.UserID == "yesterday")
	{
		CFTDReqQryParticTradeOrderStatesField field;
		CopyReqQryParticTradeOrderStatesEntity(&field, &qryfield);
		field.ParticipantID = "";
		field.UserID = "";
		m_pkgSend.PreparePackage(
				FTD_TID_ReqQryParticTradeOrderStatesTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &field);
		m_pkgSend.SetRequestId(UpdateCurHandlePackageRID());
		if (m_pQueryAgent->GetQuerySession())
		{
			m_pQueryAgent->GetQuerySession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryParticTradeOrderStatesTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_QRYACCWRONG;
			rspInfoField.ErrorMsg = "QueryConnectError";
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
		}

		return;
	}

	//查询某个席位
	if (qryfield.ParticipantID != "" && qryfield.UserID != "")
	{
		CSysParticTradeOrderStates	*pfield = pMemoryDB->
			m_SysParticTradeOrderStatesFactory->startFindByUserID(
					qryfield.ParticipantID,
					qryfield.UserID,
					qryfield.MonDate,
					qryfield.MonStartTime);
		int nCount = 0;
		while (pfield)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryParticTradeOrderStatesTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspQryParticTradeOrderStatesField field;
			CopySysParticTradeOrderStatesEntity(&field, pfield);
			FTDC_ADD_FIELD(&m_pkgSend, &field);
			pSession->SendRequestPackage(&m_pkgSend);
			nCount++;
			pfield = pMemoryDB->m_SysParticTradeOrderStatesFactory->findNextByUserID();
		}

		pMemoryDB->m_SysParticTradeOrderStatesFactory->endFindByUserID();
	}
	else
	{
		//请求当日交易数据统计信息
		if (qryfield.ParticipantID == "count")
		{
			map<string, CFTDRspQryParticTradeOrderStatesField>::iterator m_Iter;

			for (m_Iter = g_mpPartiOrderCnt.begin();
				 m_Iter != g_mpPartiOrderCnt.end();
				 m_Iter++)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryParticTradeOrderStatesTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());

				CFTDRspQryParticTradeOrderStatesField &field = m_Iter->second;

				FTDC_ADD_FIELD(&m_pkgSend, &field);
				pSession->SendRequestPackage(&m_pkgSend);
			}
		}

		//请求所有详细交易记录
		else
		{
			CSysParticTradeOrderStates	*pfield = pMemoryDB->
				m_SysParticTradeOrderStatesFactory->startFindByAll();
			while (pfield)
			{
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryParticTradeOrderStatesTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
				m_pkgSend.SetRequestId(pPackage->GetRequestId());

				CFTDRspQryParticTradeOrderStatesField field;
				CopySysParticTradeOrderStatesEntity(&field, pfield);
				FTDC_ADD_FIELD(&m_pkgSend, &field);
				pSession->SendRequestPackage(&m_pkgSend);
				pfield = pMemoryDB->m_SysParticTradeOrderStatesFactory->findNextByAll();
			}

			pMemoryDB->m_SysParticTradeOrderStatesFactory->endFindByAll();
		}
	}

	m_pkgSend.PreparePackage(
			FTD_TID_RspQryParticTradeOrderStatesTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

void CFrontServer::OnReqQryTradeFrontOrderRttStatTopic(
	CFTDCPackage *pPackage,
	CFTDCSession *pSession)
{
	int g_OrderQryCount = 1;

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	CFTDReqQryTradeFrontOrderRttStatField qryfield;
	FTDC_GET_SINGLE_FIELD(pPackage, &qryfield);

	// 历史结果查询，转给sysquery
	if (qryfield.MonDate < NowDate)
	{
		CFTDCSession * pSlogSession = m_pSlogAgent->GetSlogSession();
		if (pSlogSession)
		{		
			CFTDReqQryTradeFrontOrderRttStatField field;
			CopyReqQryTradeFrontOrderRttStatEntity(&field, &qryfield); 
			SendReqPackageOnAgentSession(field, pSlogSession
				, FTD_TID_ReqQryTradeFrontOrderRttStatTopic, false);
		}
		else
		{
			OnSessionResponse(FTD_TID_RspQryTradeFrontOrderRttStatTopic, ERR_QRYACCWRONG, "SlogConnectError");
		}
	}

	int HostName = g_StringIdMap.getStringId(qryfield.ObjectID.getValue());
	CSysMdbTradeFrontOrderRttStat *sfield = pMemoryDB->
		m_SysMdbTradeFrontOrderRttStatFactory->startFindByDsc(HostName);
	while (sfield)
	{
		CFTDRspQryTradeFrontOrderRttStatField tfield;

		tfield.ObjectID = qryfield.ObjectID;
		tfield.MonTime = sfield->MonTime;
		tfield.MonDate = sfield->MonDate;
		tfield.OrderCount = sfield->OrderCount;
		tfield.OrderRttSum = sfield->OrderRttSum;
		tfield.OrderMaxRtt = sfield->OrderMaxRtt;
		tfield.OrderMinRtt = sfield->OrderMinRtt;
		tfield.OrderRttSqu = sfield->OrderRttSqu;
		tfield.OrderRttCutDistrib = sfield->OrderRttCutDistrib;

		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTradeFrontOrderRttStatTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pPackage->GetRequestId());

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		pSession->SendRequestPackage(&m_pkgSend);

		sfield = pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->findNextByDsc();

#ifdef CPUMEMNETLIMET
		if (++g_OrderQryCount > MAXQRYRETURNNUM)
		{
			pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->endFindByDsc();
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryTradeFrontOrderRttStatTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			m_pkgSend.SetRequestId(pPackage->GetRequestId());

			CFTDRspInfoField rspInfoField;
			memset(&rspInfoField, 0, sizeof(rspInfoField));
			rspInfoField.ErrorID = ERR_REACHMAXRECORDNUM;
			FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
			pSession->SendRequestPackage(&m_pkgSend);
			return;
		}

#endif
	}

	pMemoryDB->m_SysMdbTradeFrontOrderRttStatFactory->endFindByDsc();
	m_pkgSend.PreparePackage(
			FTD_TID_RspQryTradeFrontOrderRttStatTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	m_pkgSend.SetRequestId(pPackage->GetRequestId());

	CFTDRspInfoField rspInfoField;
	memset(&rspInfoField, 0, sizeof(rspInfoField));
	rspInfoField.ErrorID = 0;
	FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
	pSession->SendRequestPackage(&m_pkgSend);
}

//根据当前处理的包更新Rid数组。
int CFrontServer::UpdateCurHandlePackageRID()
{	
	TRID rid;
	rid.RequestId = pCurHandlePackage->GetRequestId();
	rid.SessionID = pCurHandleSession->GetSessionID();

	int ridNum = m_Rid++;
	m_vRid[ridNum] = rid;
	//printf("UptRID: rid %d, requestID: %d \n", ridNum, rid.RequestId);
	return ridNum;
}

void CFrontServer::OnSessionResponse(DWORD tid, int errID, ::std::string errMsg)
{
	if(NULL != pCurHandlePackage && NULL != pCurHandleSession)
	{			
	    m_pkgSend.PreparePackage(
				tid,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		m_pkgSend.SetRequestId(pCurHandlePackage->GetRequestId());

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		rspInfoField.ErrorID = errID;
		
		if(!errMsg.empty())
		{
			rspInfoField.ErrorMsg = errMsg.c_str();
		}

		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);
		pCurHandleSession->SendRequestPackage(&m_pkgSend);
	}
}
