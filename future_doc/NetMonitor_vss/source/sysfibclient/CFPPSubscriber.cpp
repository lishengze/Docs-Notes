/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CFPPSubscriber.cpp
///@brief	实现了定义了面向fibproxy会话订阅类，实现FTD包向XTP包的转化
///@history
///20080624	郭鹏		创建该文件
///20080624	郭鹏		修订注释
/////////////////////////////////////////////////////////////////////////
#include "CFPPSubscriber.h"
#include "CDate.h"
#include <iostream>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

extern CCachedFlow	*m_TRFlow;
extern CStringIdMap g_mStringIDMap;
extern CIPAnalysis	*pIpAnalysis;
CCurrentTimeField m_curTime;

///张江与浦电string对应前置ID关系的MAP:
map<string, list<int> > g_DataCenterMap;

///北京登录的座席与会员统计
map<CParticipantIDType, list<CUserIDType> > g_BeijingMap;

///浦电登录的座席与会员统计
map<CParticipantIDType, list<CUserIDType> > g_PudianMap;

///张江登录的座席与会员统计
map<CParticipantIDType, list<CUserIDType> > g_ZhangjinagMap;

///用于统计前置的某协议下登录座席数的MAP
///第一个int为FRONTID
///第二个int为某协议下的座席登录数
map<int, map<CProtocolInfoType, int> >	g_FrontUserIDMap;

///座席与协议信息对应关系MAP:
map<CUserIDType, CProtocolInfoType> g_UserProtocolMap;

///前置报单等操作统计相应的MAP：
map<int, CFTDRspQryFrontStatField>	g_FrontStatMap;

///用于按IP统计登录数
extern map<string, ipLinkInfo>	g_ipLinkInfo;

///按IP托管统计相关信息
extern map<string, ipLinkInfo>	g_ipLinkInfoTuoGuan;
extern map<CParticipantIDType, list<userIpInfo> > theOtherIpInfo;
extern map<CParticipantIDType, list<userIpInfo> > theOtherIpInfoMax;
extern int	theOtherOrderCount;

extern int	g_DataCenterFlag;
extern string datacenterPudian;
extern string datacenterZhangJ;
extern string datacenterBeijing;
extern string  g_tradetime;
extern string  g_tradedate;

extern list<CFTDCSession *> frontList;

extern CLogger	*g_pLoggerOutput;

list<trsInfo> tsList;
list<trsInfo> trList;

struct theInstrument
{
	int cout;
	CFTDRtnInstPropertyField field;
};

map<CInstrumentIDType, theInstrument> g_InstMap;

map<CAccountIDType, CPartRoleAccountField>	g_AccountMap;

//////////////////////////////////////////////////////////////////////////
//feng.q
map<string, list<string> >	g_OrderTraceLife;

//key 会员号
map<string, CMemberTradeOrderRecTrace>	g_PartiTradeOrdPl;

void ClearStatInfo(void)
{
	time_t	timep;
	time(&timep);
	printf("[%s]Clean all stat info START\n", ctime(&timep));
	g_BeijingMap.clear();
	g_PudianMap.clear();
	g_ZhangjinagMap.clear();
	g_FrontUserIDMap.clear();
	g_UserProtocolMap.clear();
	g_FrontStatMap.clear();

	map<string, ipLinkInfo>::iterator m_it = g_ipLinkInfo.begin();
	for (; m_it != g_ipLinkInfo.end(); m_it++)
	{
		m_it->second.linkNumber.clear();
		m_it->second.maxlinkNumber.clear();
	}

	m_it = g_ipLinkInfoTuoGuan.begin();
	for (; m_it != g_ipLinkInfoTuoGuan.end(); m_it++)
	{
		m_it->second.linkNumber.clear();
		m_it->second.maxlinkNumber.clear();
	}

	theOtherIpInfo.clear();
	theOtherIpInfoMax.clear();
	theOtherOrderCount = 0;

	m_TRFlow->Truncate(0);

	// 清理用户登录统计信息
	LoginWarningCalculate::reset();
	UPLoginRecord::resetAllRecords();
	
	time(&timep);
	printf("[%s] Clean all stat info End\n", ctime(&timep));
}

//
CFPPSubscriber::CFPPSubscriber(WORD wSequenceSeries)
{
	m_pFlow = NULL;
	m_wSequenceSeries = wSequenceSeries;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1024);
	m_nCount = 0;
	m_curTime.CurrDate = "";
	m_curTime.CurrTime = "";

	//	strcpy((char *)(m_curTime.CurrDate.getValue()) ,"00000000");
	//	strcpy((char *)(m_curTime.CurrTime.getValue()) ,"00:00:00");
	//	ReLoad();
}

CFPPSubscriber::~CFPPSubscriber(void)
{
	delete m_pFlow;
}

void CFPPSubscriber::CreateFlow(const char *pszFlowPath)
{
	if (m_pFlow != NULL)
	{
		delete m_pFlow;
	}

	m_pFlow = new CFileFlow((int)m_wSequenceSeries, pszFlowPath, true);
}

void CFPPSubscriber::SetCommPhaseNo(WORD wCommPhaseNo)
{
	m_pFlow->SetCommPhaseNo(wCommPhaseNo);
}

WORD CFPPSubscriber::GetSequenceSeries(void)
{
	return m_wSequenceSeries;
}

DWORD CFPPSubscriber::GetReceivedCount(void)
{
	return m_pFlow->GetCount();
}

int g_orderid = 0;

void CFPPSubscriber::BufferLast100Packages()
{
	if (m_pkgXTP.GetTid() != TID_NtfTimeSync)
	{
		int nPackLen = 0;
		((CBufferLogger *)g_pLoggerOutput)->reset();
		m_pkgXTP.OutputHeader(g_pLoggerOutput);
		XTP_DEBUG_BODY(m_pkgXTP.GetTid(), &m_pkgXTP, g_pLoggerOutput);

		string strTmp = (char *)((CBufferLogger *)g_pLoggerOutput)->getValue(nPackLen);

		int roolTimes = strTmp.length() / 3900 + 1;
		CFTDRspQryTradeLogField theField;
		vector<CFTDRspQryTradeLogField> theVec;
		for (int index = 0; index < roolTimes; index++)
		{
			string	strSub = strTmp.substr(
				index * 3900,
				index * 3900 + 3900);
			memset(&theField, 0, sizeof(theField));
			theField.TradeLogStr = strSub.c_str();
			if (index == roolTimes - 1)
			{
				theField.bFlag = 0;
			}
			else
			{
				theField.bFlag = 1;
			}

			theVec.push_back(theField);
		}

		trsInfo theInfo;
		theInfo.field = theVec;
		theInfo.time = m_curTime.CurrTime.getValue();
		if (m_wSequenceSeries == 4097)
		{
			trList.push_back(theInfo);
			if (trList.size() > 100)
			{
				trList.pop_front();
			}
		}
		else
		{
			tsList.push_back(theInfo);
			if (tsList.size() > 100)
			{
				tsList.pop_front();
			}
		}

		///推送
		m_pkgSend.PreparePackage(
			FTD_TID_RspQryTradeLogTopic,
			FTDC_CHAIN_CONTINUE,
			FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &theField);

		CFTDRspInfoField rspInfoField;
		memset(&rspInfoField, 0, sizeof(rspInfoField));
		if (m_wSequenceSeries == 4097)
		{
			rspInfoField.ErrorID = 4097;
		}
		else
		{
			rspInfoField.ErrorID = 4099;
		}

		strcpy(
			(char *)rspInfoField.ErrorMsg.getValue(),
			m_curTime.CurrTime.getValue());
		FTDC_ADD_FIELD(&m_pkgSend, &rspInfoField);

		list<CFTDCSession *>::iterator	it = frontList.begin();
		for (; it != frontList.end(); it++)
		{
			(*it)->SendRequestPackage(&m_pkgSend);
			m_pkgSend.Pop(FTDCHLEN);
		}
	}
}

void CFPPSubscriber::HandleMessage(CFTDCPackage *pMessage)
{
	m_pFlow->Append(
			pMessage->Address() + sizeof(TFieldHeader),
			pMessage->Length() - sizeof(TFieldHeader));
	pMessage->Pop(sizeof(TFieldHeader));
	m_pkgXTP.BufAddRef(pMessage);
	m_pkgXTP.ValidPackage();

	///缓存最后100个报文
	BufferLast100Packages();

	//printf("运行文件 ： %s 行数：%d \n" , __FILE__, __LINE__);
	switch (m_pkgXTP.GetTid())
	{
		case TID_NtfTimeSync:
			OnNtfTimeSync(&m_pkgXTP);
			break;
		case TID_RspOrderInsert:
			OnRspOrderInsert(&m_pkgXTP);
			break;
		case TID_RspOrderAction:
			OnRspOrderAction(&m_pkgXTP);
			break;
		case TID_NtfOrder:
			OnNtfOrder(&m_pkgXTP);
			break;
		case TID_NtfTrade:
			OnNtfTrade(&m_pkgXTP);
			break;
		case TID_InitCurrInstrumentProperty:
			OnInitCurrInstrumentProperty(&m_pkgXTP);
			break;
		case TID_InitInstrument:
			OnInitInstrument(&m_pkgXTP);
			break;
		case TID_InitCurrMarginRateDetail:
			OnInitCurrMarginRateDetail(&m_pkgXTP);
			break;
		case TID_InitCurrPriceBanding:
			OnInitCurrPriceBanding(&m_pkgXTP);
			break;
		case TID_InitCurrPartPosiLimitDetail:
			OnInitCurrPartPosiLimitDetail(&m_pkgXTP);
			break;
		case TID_InitCurrClientPosiLimitDetail:
			OnInitCurrClientPosiLimitDetail(&m_pkgXTP);
			break;
		case TID_InitCurrSpecialPosiLimitDetail:
			OnInitCurrSpecialPosiLimitDetail(&m_pkgXTP);
			break;
		case TID_InitPartRoleAccount:
			OnInitPartRoleAccount(&m_pkgXTP);
			break;
		case TID_DbAccountDeposit:
			OnDbAccountDeposit(&m_pkgXTP);
			break;
		case TID_DbInsClient:
		case TID_DbUpdClient:
			//	case TID_DbDelClient:
			OnClientChg(&m_pkgXTP);
			break;
		case TID_DbInsPartClient:
		case TID_DbDelPartClient:
			OnPartClientChg(&m_pkgXTP);
			break;
		case TID_DbInsCurrPartPosiLimitDetail:
		case TID_DbUpdCurrPartPosiLimitDetail:
		case TID_DbDelCurrPartPosiLimitDetail:
			OnPosiLimitChg(&m_pkgXTP);
			break;
		case TID_DbInsCurrClientPosiLimitDetail:
		case TID_DbUpdCurrClientPosiLimitDetail:
		case TID_DbDelCurrClientPosiLimitDetail:
			OnClientPosiLimitChg(&m_pkgXTP);
			break;
		case TID_DbInsCurrSpecialPosiLimitDetail:
		case TID_DbUpdCurrSpecialPosiLimitDetail:
		case TID_DbDelCurrSpecialPosiLimitDetail:
			OnSpecPosiLimitChg(&m_pkgXTP);
			break;
		case TID_DbInsHedgeDetail:
			OnDbInsHedgeDetail(&m_pkgXTP);
			break;

		case TID_DbInsCurrMarginRateDetail:
		case TID_DbUpdCurrMarginRateDetail:
		case TID_DbDelCurrMarginRateDetail:
			OnMarginRateChg(&m_pkgXTP);
			break;
		case TID_DbInsCurrPriceBanding:
		case TID_DbUpdCurrPriceBanding:
		case TID_DbDelCurrPriceBanding:
			OnCurrPriceBandingChg(&m_pkgXTP);
			break;
		case TID_DbInsUserIP:
		case TID_DbDelUserIP:
			OnUserIpChg(&m_pkgXTP);
			break;
		case TID_InitParticipant:
			//MANAGERINIT(Participant);
			OnInitParticipant(&m_pkgXTP);
			break;
		case TID_InitUser:
			MANAGERINIT(User);
			break;
		case TID_InitClient:
				break;
		case TID_DbInsUser:
		case TID_DbUpdUser:
			//	case TID_DbDelUser:
			OnDbUser(&m_pkgXTP);
			break;
		case TID_RspUserLogin:
			OnUserLogin(&m_pkgXTP);
			break;

		case TID_NtfDelUserSession:
			OnDelUserSession(&m_pkgXTP);
			break;
		case TID_InitPartPosition:
			OnInitPartPosition(&m_pkgXTP);
			break;
		case TID_NtfDataCenterDesc:
			{
				CDataCenterDescField sfield;
				CNamedFieldIterator itor = (&m_pkgXTP)->GetNamedFieldIterator(
						&CDataCenterDescField::m_Describe);
				while (!itor.IsEnd())
				{
					itor.Retrieve(&sfield);

					///20101210初始化部分改为从配置文件读取
					cout <<
						"Receive datacenter change info: " <<
						"[" <<
						m_curTime.CurrDate.getValue() <<
						" " <<
						m_curTime.CurrTime.getValue() <<
						"] [" <<
						sfield.DataCenterID <<
						"]" <<
						endl;

					/// 修正了交易2.0系统中中心编号问题
					/// 2.0 PD：11
					/// 2.0 ZJ：12
					/// 2.0 BJ：13
					int nDataCenterID = sfield.DataCenterID.getValue() % 10;

					///发生了切换：
					if (nDataCenterID != g_DataCenterFlag)
					{
						g_DataCenterFlag = nDataCenterID;

						int frontNum = 0;

						///修正g_DataCenterMap:
											///2009-05-11确定不交换前置编号:
						///修正g_FrontUserIDMap:
											///当下的做法是全部清空：
						{
							g_FrontUserIDMap.clear();
						}

						///修正g_FrontStatMap:
											///当下的做法是全部清空：
						{
							g_FrontStatMap.clear();
						}

						///修正g_PudianMap:
											///当前做法是清空：
						{
							g_UserProtocolMap.clear();
							g_PudianMap.clear();
							g_ZhangjinagMap.clear();
							g_BeijingMap.clear();

							map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.
								begin();
							for (; it != g_ipLinkInfo.end(); it++)
							{
								it->second.linkNumber.clear();
							}

							it = g_ipLinkInfoTuoGuan.begin();
							for (; it != g_ipLinkInfoTuoGuan.end(); it++)
							{
								it->second.linkNumber.clear();
							}

							theOtherIpInfo.clear();

							theOtherOrderCount = 0;
						}

						///通知前置机发生了交易系统主备切换：
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RtnDataCenterChgTopic,
									FTDC_CHAIN_LAST,
									FTD_VERSION);

							CFTDRtnDataCenterChgField tfield;
							memset(&tfield, 0, sizeof(tfield));

							///写死部分：
							if (g_DataCenterFlag == 1)
							{
								strcpy(
									(char *)(tfield.DataCenterID.getValue()),
									datacenterPudian.data());
							}
							else if (g_DataCenterFlag == 2)
							{
								strcpy(
									(char *)(tfield.DataCenterID.getValue()),
									datacenterZhangJ.data());
							}
							else
							{
								strcpy(
									(char *)(tfield.DataCenterID.getValue()),
									datacenterBeijing.data());
							}

							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
							m_pkgSend.MakePackage();
							m_TRFlow->Append(
									m_pkgSend.Address(),
									m_pkgSend.Length());
						}
					}

					itor.Next();
				}
			}

			break;
		case TID_NtfInstrumentStatusUpdate:
			OnInstrumentStatusUpdate(&m_pkgXTP);
			break;
		case TID_InitCurrTradingSegmentAttr:
			OnInitCurrTradingSegmentAttr(&m_pkgXTP);
			break;
		default:
			break;
	}

	m_pkgXTP.BufRelease();
}

void CFPPSubscriber::OnNtfTimeSync(CXTPPackage *pMessage)
{
//	cout<<"-----------------OnNtfTimeSync--------------:"<<endl;
	CCurrentTimeField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrentTimeField::m_Describe);
	if (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		
	//	printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
	// NS-1400监控系统7*24运行模式下会员席位数统计异常
#if 0
		if ((sfield.CurrTime>="07:00:00"&&sfield.CurrTime<="08:00:00") || (sfield.CurrTime>="19:00:00"&&sfield.CurrTime<="20:00:00"))
		{
			string curdate = sfield.CurrDate.getValue();
			string curtime = sfield.CurrTime.getValue();
			string curdatetime = curdate+curtime;

			printf("运行文件 ： %s 行数：%d \n", __FILE__, __LINE__);
			printf("\t%s\n", curdatetime.c_str());

			if (find(m_vecTimeClear.begin(), m_vecTimeClear.end(), curdatetime)==m_vecTimeClear.end())
			{
				m_vecTimeClear.push_back(curdatetime);

				time_t	timep;
				time(&timep);
				printf("clear history data by time at timeclock %s", curdatetime.c_str());

				g_BeijingMap.clear();
				g_PudianMap.clear();
				g_ZhangjinagMap.clear();
				g_FrontUserIDMap.clear();
				g_UserProtocolMap.clear();
				g_FrontStatMap.clear();

				map<string, ipLinkInfo>::iterator m_it = g_ipLinkInfo.begin();
				for (; m_it != g_ipLinkInfo.end(); m_it++)
				{
					m_it->second.linkNumber.clear();
					m_it->second.maxlinkNumber.clear();
				}

				m_it = g_ipLinkInfoTuoGuan.begin();
				for (; m_it != g_ipLinkInfoTuoGuan.end(); m_it++)
				{
					m_it->second.linkNumber.clear();
					m_it->second.maxlinkNumber.clear();
				}

				theOtherIpInfo.clear();
				theOtherIpInfoMax.clear();
				theOtherOrderCount = 0;

				//清除proxy流水
				//CSubscriberMap::iterator m_Iter;
				//for (m_Iter = m_mapSubscriber.begin();
				//	m_Iter != m_mapSubscriber.end();
				//	m_Iter++)
				//{
				//	if (m_Iter->second->m_pFlow)
				//	{
				//		m_Iter->second->m_pFlow->Truncate(0);
				//	}
				//}
			}
		}
#endif
		/// Mod by Henchi, 20130527
		/// 为支持夜市交易节跨天的情况，取消原有自然日跨天时的资源重置
#if 0
		if (m_curTime.CurrDate != sfield.CurrDate)
		{
			g_FrontUserIDMap.clear();
			g_FrontStatMap.clear();
			g_UserProtocolMap.clear();
			g_PudianMap.clear();
			g_ZhangjinagMap.clear();
			g_BeijingMap.clear();

			map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.begin();
			for (; it != g_ipLinkInfo.end(); it++)
			{
				it->second.linkNumber.clear();

				//it->second.maxlinkNumber.clear();
			}

			it = g_ipLinkInfoTuoGuan.begin();
			for (; it != g_ipLinkInfoTuoGuan.end(); it++)
			{
				it->second.linkNumber.clear();

				//it->second.maxlinkNumber.clear();
			}

			theOtherIpInfo.clear();

			//theOtherIpInfoMax.clear();

						//////////////////////////////////////////////////////////////////////////
			//add by feng.q 20130130
			g_PartiTradeOrdPl.clear();

			//////////////////////////////////////////////////////////////////////////
			theOtherOrderCount = 0;
		}
#endif

		m_curTime.CurrDate = sfield.CurrDate;
		m_curTime.CurrTime = sfield.CurrTime;

		g_tradedate = sfield.CurrDate;
		g_tradetime = sfield.CurrTime;
		//		cout<<sfield.CurrTime.getValue()<<endl;
	}
}

void CFPPSubscriber::OnInstrumentStatusUpdate(CXTPPackage *pMessage)
{
	CInstrumentStatusField infoField;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&infoField);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnInstrumentStatusTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		CFTDRtnInstrumentStatusField tfield;
		memset(&tfield, 0, sizeof(tfield));

		tfield.SettlementGroupID = infoField.SettlementGroupID;
		tfield.InstrumentID = infoField.InstrumentID;
		tfield.InstrumentStatus = infoField.InstrumentStatus;
		tfield.TradingSegmentSN = infoField.TradingSegmentSN;
		tfield.EnterTime = infoField.EnterTime;
		tfield.EnterReason = infoField.EnterReason;
		tfield.EnterDate = infoField.EnterDate;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnInitCurrTradingSegmentAttr(CXTPPackage *pMessage)
{
	CCurrTradingSegmentAttrField infoField;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CCurrTradingSegmentAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&infoField);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnCurrTradingSegmentAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		CFTDRtnCurrTradingSegmentAttrField tfield;
		memset(&tfield, 0, sizeof(tfield));

		tfield.SettlementGroupID = infoField.SettlementGroupID;
		tfield.TradingSegmentSN = infoField.TradingSegmentSN;
		tfield.TradingSegmentName = infoField.TradingSegmentName;
		tfield.StartTime = infoField.StartTime;
		tfield.InstrumentStatus = infoField.InstrumentStatus;
		tfield.InstrumentID = infoField.InstrumentID;
		tfield.AdvanceDays = infoField.AdvanceDays;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}
void CFPPSubscriber::OnRspOrderInsert(CXTPPackage *pMessage)
{
	CRspInfoField infofield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CRspInfoField::m_Describe);
	if (itor.IsEnd())
	{
		return;
	}
	else
	{
		itor.Retrieve(&infofield);

		///对交易系统前置做统计：
		map<int, CFTDRspQryFrontStatField>::iterator itFront = g_FrontStatMap.
			find(pMessage->GetFrontID());

		///如果找不到，则创建该前置ID对应关联数据:
		if (itFront == g_FrontStatMap.end())
		{
			CFTDRspQryFrontStatField theField;
			memset(&theField, 0, sizeof(theField));
			theField.FrontID = pMessage->GetFrontID();
			g_FrontStatMap[pMessage->GetFrontID()] = theField;
			itFront = g_FrontStatMap.find(pMessage->GetFrontID());
		}

		/*
		CInputOrderField sfield;
		CNamedFieldIterator itor= pFTDCPackage->GetNamedFieldIterator(&CInputOrderField::m_Describe);
		while (!itor.IsEnd())
		{
			itor.Retrieve(&sfield);
			if(sfield.Direction =='0')
			{
				(*itFront).second.PositiveOrder +=1;
				(*itFront).second.TotalPositiveOrder +=sfield.VolumeTotalOriginal;
			}
			else
			{
				(*itFront).second.NegativeOrder +=1;
				(*itFront).second.TotalNegativeOrder +=sfield.VolumeTotalOriginal;
			}
			itor.Next();
		}
*/
		///如果是正确报单：
		if (!infofield.ErrorID)
		{
			CInputOrderField sfield;
			itor = pMessage->GetNamedFieldIterator(
					&CInputOrderField::m_Describe);

			m_pkgSend.PreparePackage(
					FTD_TID_RspQryPartTradeTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRspQryPartTradeField tfield;
			int iTmp = FTDC_PACKAGE_MAX_SIZE / (sizeof(tfield));
			int iCount = 0;
			bool sendFlag = false;

			while (!itor.IsEnd())
			{
				itor.Retrieve(&sfield);

				//g_OrderTraceLife[sfield.OrderSysID.getValue()].push_back("OnRspOrderInsert ok") ;
				//记录报单
				{
					// 					string strParti = sfield.ParticipantID.getValue();
					// 					string strMem = sfield.UserID.getValue();
					// 					string strTime = m_curTime.CurrTime.getValue();
					//  					CMemberTradeOrderRecTrace &membTrd = g_PartiTradeOrdPl[strParti];
					//  					CSeatOrderTrdCslTrace &seatTrd = membTrd.RecordNewOrderInput(strMem);
					// 					seatTrd.AddOrder(1, strTime, sfield.VolumeTotalOriginal.getValue());
				}

				///按ip统计
				bool flag = false;
				map<string, ipLinkInfo>::iterator itLinkInfo = g_ipLinkInfo.
					begin();
				for (; itLinkInfo != g_ipLinkInfo.end(); itLinkInfo++)
				{
					map<CParticipantIDType, list<userIpInfo> >::iterator itPu =
						itLinkInfo->second.linkNumber.begin();
					for (; itPu != itLinkInfo->second.linkNumber.end(); itPu++)
					{
						list<userIpInfo>::iterator	itUser = itPu->second.begin();
						for (; itUser != itPu->second.end(); itUser++)
						{
							if (itUser->id == sfield.UserID)
							{
								flag = true;
								break;
							}
						}

						if (flag)
						{
							break;
						}
					}

					if (flag)
					{
						itLinkInfo->second.orderCount += 1;
						break;
					}
				}

				if (!flag)
				{
					theOtherOrderCount += 1;
				}

				///按托管ip统计
				{
					bool flag = false;
					map<string, ipLinkInfo>::iterator itLinkInfo =
						g_ipLinkInfoTuoGuan.begin();
					for (;
						 itLinkInfo != g_ipLinkInfoTuoGuan.end();
						 itLinkInfo++)
					{
						map<CParticipantIDType, list<userIpInfo> >::iterator
							itPu = itLinkInfo->second.linkNumber.begin();
						for (;
							 itPu != itLinkInfo->second.linkNumber.end();
							 itPu++)
						{
							list<userIpInfo>::iterator	itUser = itPu->second.
								begin();
							for (; itUser != itPu->second.end(); itUser++)
							{
								if (itUser->id == sfield.UserID)
								{
									flag = true;
									break;
								}
							}

							if (flag)
							{
								break;
							}
						}

						if (flag)
						{
							itLinkInfo->second.orderCount += 1;
							break;
						}
					}
				}

				memset(&tfield, 0, sizeof(tfield));

				tfield.ParticipantID = sfield.ParticipantID;
				tfield.InstrumentID = sfield.InstrumentID;
				if (sfield.Direction == '0')
				{
					tfield.TotalPositiveOrder = sfield.VolumeTotalOriginal;

					///对交易前置进行统计
					(*itFront).second.PositiveOrder += 1;
					(*itFront).second.TotalPositiveOrder += sfield.VolumeTotalOriginal;
				}
				else
				{
					tfield.TotalNegativeOrder = sfield.VolumeTotalOriginal;

					///对交易前置进行统计
					(*itFront).second.NegativeOrder += 1;
					(*itFront).second.TotalNegativeOrder += sfield.VolumeTotalOriginal;
				}

				iCount++;
				if (iCount % iTmp == 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					m_pkgSend.MakePackage();
					m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
					m_pkgSend.PreparePackage(
							FTD_TID_RspQryPartTradeTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					sendFlag = false;
				}
				else
				{
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					sendFlag = true;
				}

				itor.Next();
			}

			if (sendFlag)
			{
				m_pkgSend.MakePackage();
				m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
			}
		}

		///如果是错误报单:
		else
		{
			CInputOrderField sfield;
			itor = pMessage->GetNamedFieldIterator(
					&CInputOrderField::m_Describe);

			m_pkgSend.PreparePackage(
					FTD_TID_RtnInvalidateOrderTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRtnInvalidateOrderField tfield;
			int iTmp = FTDC_PACKAGE_MAX_SIZE / (sizeof(tfield));
			int iCount = 0;
			bool sendFlag = false;

			while (!itor.IsEnd())
			{
				itor.Retrieve(&sfield);

				///按ip统计
				bool flag = false;
				map<string, ipLinkInfo>::iterator itLinkInfo = g_ipLinkInfo.
					begin();
				for (; itLinkInfo != g_ipLinkInfo.end(); itLinkInfo++)
				{
					map<CParticipantIDType, list<userIpInfo> >::iterator itPu =
						itLinkInfo->second.linkNumber.begin();
					for (; itPu != itLinkInfo->second.linkNumber.end(); itPu++)
					{
						list<userIpInfo>::iterator	itUser = itPu->second.begin();
						for (; itUser != itPu->second.end(); itUser++)
						{
							if (itUser->id == sfield.UserID)
							{
								flag = true;
								break;
							}
						}

						if (flag)
						{
							break;
						}
					}

					if (flag)
					{
						itLinkInfo->second.orderCount += 1;
						break;
					}
				}

				if (!flag)
				{
					theOtherOrderCount += 1;
				}

				///按托管ip统计
				{
					bool flag = false;
					map<string, ipLinkInfo>::iterator itLinkInfo =
						g_ipLinkInfoTuoGuan.begin();
					for (;
						 itLinkInfo != g_ipLinkInfoTuoGuan.end();
						 itLinkInfo++)
					{
						map<CParticipantIDType, list<userIpInfo> >::iterator
							itPu = itLinkInfo->second.linkNumber.begin();
						for (;
							 itPu != itLinkInfo->second.linkNumber.end();
							 itPu++)
						{
							list<userIpInfo>::iterator	itUser = itPu->second.
								begin();
							for (; itUser != itPu->second.end(); itUser++)
							{
								if (itUser->id == sfield.UserID)
								{
									flag = true;
									break;
								}
							}

							if (flag)
							{
								break;
							}
						}

						if (flag)
						{
							itLinkInfo->second.orderCount += 1;
							break;
						}
					}
				}

				memset(&tfield, 0, sizeof(tfield));

				tfield.ClientID = sfield.ClientID;
				tfield.CombHedgeFlag = sfield.CombHedgeFlag;
				tfield.CombOffsetFlag = sfield.CombOffsetFlag;
				tfield.Direction = sfield.Direction;
				tfield.ErrorMsg = infofield.ErrorMsg;
				tfield.ActionDate = m_curTime.CurrDate;
				tfield.ActionTime = m_curTime.CurrTime;
				tfield.InstrumentID = sfield.InstrumentID;
				tfield.LimitPrice = sfield.LimitPrice;
				tfield.OrderLocalID = sfield.OrderLocalID;
				tfield.OrderSysID = sfield.OrderSysID;
				tfield.ParticipantID = sfield.ParticipantID;
				tfield.UserID = sfield.UserID;
				tfield.VolumeTotalOriginal = sfield.VolumeTotalOriginal;
				tfield.TimeCondition = sfield.TimeCondition;
				tfield.VolumeCondition = sfield.VolumeCondition;
				tfield.MinVolume = sfield.MinVolume;

				///对交易前置进行统计
				if (sfield.Direction == '0')
				{
					(*itFront).second.PositiveOrder += 1;
					(*itFront).second.TotalPositiveOrder += sfield.VolumeTotalOriginal;
				}
				else
				{
					(*itFront).second.NegativeOrder += 1;
					(*itFront).second.TotalNegativeOrder += sfield.VolumeTotalOriginal;
				}

				iCount++;
				if (iCount % iTmp == 0)
				{
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					m_pkgSend.MakePackage();
					m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
					m_pkgSend.PreparePackage(
							FTD_TID_RtnInvalidateOrderTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					sendFlag = false;
				}
				else
				{
					FTDC_ADD_FIELD(&m_pkgSend, &tfield);
					sendFlag = true;
				}

				itor.Next();
			}

			if (sendFlag)
			{
				m_pkgSend.MakePackage();
				m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
			}
		}
	}
}

void CFPPSubscriber::OnRspOrderAction(CXTPPackage *pMessage)
{
	//	newTradepeakField1.ActionOrder +=1;
	//	newTradepeakField2.ActionOrder +=1;
		///对交易系统前置做统计：
	map<int, CFTDRspQryFrontStatField>::iterator itFront = g_FrontStatMap.find(
			pMessage->GetFrontID());

	///如果找不到，则创建该前置ID对应关联数据:
	if (itFront == g_FrontStatMap.end())
	{
		CFTDRspQryFrontStatField theField;
		memset(&theField, 0, sizeof(theField));
		theField.FrontID = pMessage->GetFrontID();
		g_FrontStatMap[pMessage->GetFrontID()] = theField;
		itFront = g_FrontStatMap.find(pMessage->GetFrontID());
	}

	COrderActionField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&COrderActionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		///对交易前置进行统计
		(*itFront).second.OrderAction += 1;

		//		(*itFront).second.TotalOrderAction +=sfield.VolumeChange;
		itor.Next();
	}
}

string	strLastTm;
void CFPPSubscriber::OnNtfOrder(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnNtfOrder--------------:"<<endl;
	COrderField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&COrderField::m_Describe);
	CFTDRtnOrderStatusField tfield;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		// 		char strTmpTrace[32];
		// 		sprintf(strTmpTrace, "OnNtfOrder status:%c", sfield.OrderStatus.getValue());
		// 		list<string> &orderlist = g_OrderTraceLife[sfield.OrderSysID.getValue()];
		// 		orderlist.push_back(strTmpTrace);
		if (sfield.OrderStatus == '5')
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryPartTradeTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRspQryPartTradeField tfield;
			memset(&tfield, 0, sizeof(tfield));

			tfield.ParticipantID = sfield.ParticipantID;
			tfield.InstrumentID = sfield.InstrumentID;
			if (sfield.Direction == '0')
			{
				tfield.TotalPositiveOrder = 0 - sfield.VolumeTotalOriginal;
			}
			else
			{
				tfield.TotalNegativeOrder = 0 - sfield.VolumeTotalOriginal;
			}

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RtnOrderStatusTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.OrderSysID = sfield.OrderSysID;
		tfield.OrderLocalID = sfield.OrderLocalID;
		tfield.InsertDate = sfield.InsertDate;
		tfield.InsertTime = sfield.InsertTime;
		tfield.OrderStatus = sfield.OrderStatus;
		tfield.ParticipantID = sfield.ParticipantID;
		tfield.UserID = sfield.UserID;
		tfield.ClientID = sfield.ClientID;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.Direction = sfield.Direction;
		tfield.CombOffsetFlag = sfield.CombOffsetFlag;
		tfield.CombHedgeFlag = sfield.CombHedgeFlag;
		tfield.LimitPrice = sfield.LimitPrice;
		tfield.VolumeTotalOriginal = sfield.VolumeTotalOriginal;
		tfield.TimeCondition = sfield.TimeCondition;
		tfield.VolumeCondition = sfield.VolumeCondition;
		tfield.MinVolume = sfield.MinVolume;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		//统计报单
		if (g_OrderTraceLife.find(
				sfield.OrderSysID.getValue()) == g_OrderTraceLife.end())
		{
			g_OrderTraceLife[sfield.OrderSysID.getValue()].push_back(
					"OnRspOrderInsert ok");

			string	strParti = sfield.ParticipantID.getValue();
			string	strMem = sfield.UserID.getValue();
			string	strTime = sfield.InsertTime.getValue();

			if (g_PartiTradeOrdPl.find(strParti) == g_PartiTradeOrdPl.end())
			{
				g_PartiTradeOrdPl[strParti].strPartiNo = strParti;
			}

			CMemberTradeOrderRecTrace &membTrd = g_PartiTradeOrdPl[strParti];
			CSeatOrderTrdCslTrace &seatTrd = membTrd.RecordNewOrderInput(
					strMem,
					pMessage->GetFrontID());
			seatTrd.AddOrder(1, strTime, sfield.VolumeTotalOriginal.getValue());
		}

		if (sfield.OrderStatus == '5')
		{
			string	strParti = sfield.ParticipantID.getValue();
			string	strMem = sfield.UserID.getValue();
			string	strTime = sfield.CancelTime.getValue();

			CMemberTradeOrderRecTrace &membTrd = g_PartiTradeOrdPl[strParti];
			CSeatOrderTrdCslTrace &seatTrd = membTrd.RecordNewOrderInput(
					strMem);
			seatTrd.AddOrder(2, strTime, sfield.VolumeTotal.getValue());
		}

		itor.Next();
	}
}

void CFPPSubscriber::OnNtfTrade(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnNtfTrade--------------:"<<endl;
	CTradeField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		// 		char strTmpTrace[32];
		// 		sprintf(strTmpTrace, "OnNtfTrade");
		// 		g_OrderTraceLife[sfield.OrderSysID.getValue()].push_back(strTmpTrace) ;
		{
			string	strParti = sfield.ParticipantID.getValue();
			string	strMem = sfield.UserID.getValue();
			string	strTime = sfield.TradeTime.getValue();

			CMemberTradeOrderRecTrace &membTrd = g_PartiTradeOrdPl[strParti];
			CSeatOrderTrdCslTrace &seatTrd = membTrd.RecordNewOrderInput(
					strMem);
			seatTrd.AddOrder(
					3,
					strTime,
					sfield.Volume.getValue(),
					sfield.Price.getValue());
		}

		///按ip统计被取消
		///处理成交总量和持仓总量：
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryPartTradeTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRspQryPartTradeField tfield;
			memset(&tfield, 0, sizeof(tfield));

			tfield.ParticipantID = sfield.ParticipantID;
			tfield.InstrumentID = sfield.InstrumentID;
			if (sfield.Direction == '0')
			{
				tfield.TotalPositiveTrade = sfield.Volume;
				if (sfield.OffsetFlag == '0')
				{
					tfield.TotalPositivePosi = sfield.Volume;
				}

				//				else if(sfield.OffsetFlag =='1')
				else
				{
					tfield.TotalNegativePosi = 0 - sfield.Volume;
				}
			}
			else
			{
				tfield.TotalNegativeTrade = sfield.Volume;
				if (sfield.OffsetFlag == '0')
				{
					tfield.TotalNegativePosi = sfield.Volume;
				}

				//				else if(sfield.OffsetFlag =='1')
				else
				{
					tfield.TotalPositivePosi = 0 - sfield.Volume;
				}
			}

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RtnBargainOrderTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnBargainOrderField tfield;
		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = sfield.TradeTime;
		tfield.TradeID = sfield.TradeID;
		tfield.OrderSysID = sfield.OrderSysID;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.Price = sfield.Price;
		tfield.Volume = sfield.Volume;
		tfield.ParticipantID = sfield.ParticipantID;
		tfield.UserID = sfield.UserID;
		tfield.ClientID = sfield.ClientID;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnInitCurrInstrumentProperty(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnInitCurrInstrumentProperty--------------:"<<endl;
	CCurrInstrumentPropertyField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrInstrumentPropertyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		map<CInstrumentIDType, theInstrument>::iterator it = g_InstMap.find(
				sfield.InstrumentID);
		if (it == g_InstMap.end())
		{
			theInstrument instrument;
			memset(&instrument, 0, sizeof(instrument));
			instrument.cout = 1;
			g_InstMap[sfield.InstrumentID] = instrument;
			it = g_InstMap.find(sfield.InstrumentID);
		}
		else
		{
			(it->second.cout)++;
		}

		it->second.field.ActionDate = m_curTime.CurrDate;
		it->second.field.ActionTime = m_curTime.CurrTime;
		it->second.field.InstrumentID = sfield.InstrumentID;
		it->second.field.SettlementGroupID = sfield.SettlementGroupID;
		it->second.field.OpenDate = sfield.OpenDate;
		it->second.field.ExpireDate = sfield.ExpireDate;
		it->second.field.StartDelivDate = sfield.StartDelivDate;
		it->second.field.EndDelivDate = sfield.EndDelivDate;
		it->second.field.BasisPrice = sfield.BasisPrice;
		it->second.field.MaxMarketOrderVolume = sfield.MaxMarketOrderVolume;
		it->second.field.MinMarketOrderVolume = sfield.MinMarketOrderVolume;
		it->second.field.MaxLimitOrderVolume = sfield.MaxLimitOrderVolume;
		it->second.field.MinLimitOrderVolume = sfield.MinLimitOrderVolume;
		it->second.field.PriceTick = sfield.PriceTick;
		it->second.field.AllowDelivPersonOpen = sfield.AllowDelivPersonOpen;
		it->second.field.InstLifePhase = sfield.InstLifePhase;

		if (it->second.cout == 2)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnInstPropertyTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(it->second.field));
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		itor.Next();
	}
}

void CFPPSubscriber::OnInitInstrument(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnInitInstrument--------------:"<<endl;
	CInstrumentField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CInstrumentField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		map<CInstrumentIDType, theInstrument>::iterator it = g_InstMap.find(
				sfield.InstrumentID);
		if (it == g_InstMap.end())
		{
			theInstrument instrument;
			memset(&instrument, 0, sizeof(instrument));
			instrument.cout = 1;
			g_InstMap[sfield.InstrumentID] = instrument;
			it = g_InstMap.find(sfield.InstrumentID);
		}
		else
		{
			(it->second.cout)++;
		}

		it->second.field.InstrumentID = sfield.InstrumentID;
		it->second.field.UnderlyingInstrID = sfield.UnderlyingInstrID;
		it->second.field.ProductClass = sfield.ProductClass;
		it->second.field.PositionType = sfield.PositionType;
		it->second.field.VolumeMultiple = sfield.VolumeMultiple;
		it->second.field.UnderlyingMultiple = sfield.UnderlyingMultiple;
		if (it->second.cout == 2)
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnInstPropertyTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &(it->second.field));
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		itor.Next();
	}
}

void CFPPSubscriber::OnInitCurrMarginRateDetail(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnInitCurrMarginRateDetail--------------:"<<endl;
	CCurrMarginRateDetailField	sfield;
	CFTDRtnMarginRateField	tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrMarginRateDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnMarginRateTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.TradingRole = sfield.TradingRole;
		tfield.HedgeFlag = sfield.HedgeFlag;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongMarginRatio = sfield.LongMarginRatio;
		tfield.ShortMarginRatio = sfield.ShortMarginRatio;
		tfield.ParticipantID = sfield.ParticipantID;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnInitCurrPriceBanding(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnInitCurrPriceBanding--------------:"<<endl;
	CCurrPriceBandingField	sfield;
	CFTDRtnPriceLimitField	tfield;

	//	g_LimtMap[sfield.InstrumentID] =sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrPriceBandingField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnPriceLimitTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ValueMode = sfield.ValueMode;
		tfield.RoundingMode = sfield.RoundingMode;
		tfield.UpperLimitPrice = sfield.UpperValue;
		tfield.LowerLimitPrice = sfield.LowerValue;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnInitCurrPartPosiLimitDetail(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnInitCurrPartPosiLimitDetail--------------:"<<endl;
	CCurrPartPosiLimitDetailField sfield;
	CFTDRtnPartPosiLimitField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrPartPosiLimitDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		//		map<CInstrumentIDType ,CCurrPriceBandingField>::iterator it =g_LimtMap.find(sfield.InstrumentID);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnPartPosiLimitTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ParticipantID = sfield.ParticipantID;
		tfield.TradingRole = sfield.TradingRole;
		tfield.StartTotalPosition = sfield.StartTotalPosition;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongPosLimit = sfield.LongPosLimit;
		tfield.ShortPosLimit = sfield.ShortPosLimit;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnInitCurrClientPosiLimitDetail(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnInitCurrClientPosiLimitDetail--------------:"<<endl;
	CCurrClientPosiLimitDetailField sfield;
	CFTDRtnClientPosiLimitField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrClientPosiLimitDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnClientPosiLimitTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ClientType = sfield.ClientType;
		tfield.StartTotalPosition = sfield.StartTotalPosition;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongPosLimit = sfield.LongPosLimit;
		tfield.ShortPosLimit = sfield.ShortPosLimit;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnInitCurrSpecialPosiLimitDetail(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnInitCurrSpecialPosiLimitDetail--------------:"<<endl;
	CCurrSpecialPosiLimitDetailField sfield;
	CFTDRtnSpecialPosiLimitField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrSpecialPosiLimitDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSpecialPosiLimitTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ClientID = sfield.ClientID;
		tfield.StartTotalPosition = sfield.StartTotalPosition;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongPosLimit = sfield.LongPosLimit;
		tfield.ShortPosLimit = sfield.ShortPosLimit;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnInitPartRoleAccount(CXTPPackage *pMessage)
{
	CPartRoleAccountField sfield;
	CPartRoleAccountField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CPartRoleAccountField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		CopyPartRoleAccountEntity(&tfield, &sfield);
		g_AccountMap[tfield.AccountID] = tfield;
		itor.Next();
	}
}

void CFPPSubscriber::OnDbAccountDeposit(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnDbAccountDeposit--------------:"<<endl;
	CDbmtAccountDepositField sfield;
	CFTDRtnTransactionChgField	tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtAccountDepositField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTransactionChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.Amount = sfield.Deposit;
		tfield.ParticipantAccount = sfield.Account;

		map<CAccountIDType, CPartRoleAccountField>::iterator it = g_AccountMap.
			find(tfield.ParticipantAccount);
		if (it != g_AccountMap.end())
		{
			tfield.ParticipantID = it->second.ParticipantID;
		}

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnClientChg(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnClientChg--------------:"<<endl;
	CDbmtClientField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtClientField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnClientChgTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRtnClientChgField tfield;
			memset(&tfield, 0, sizeof(tfield));
			switch (pMessage->GetTid())
			{
				case TID_DbInsClient:
					tfield.OperationType = 0;
					break;
				case TID_DbUpdClient:
					tfield.OperationType = 1;
					break;

				//			case TID_DbDelClient:
				//				tfield.OperationType =2;
				//				break;
				default:
					break;
			}

			tfield.ActionDate = m_curTime.CurrDate;
			tfield.ActionTime = m_curTime.CurrTime;
			tfield.ClientID = sfield.ClientID;
			tfield.ClientName = sfield.ClientName;
			tfield.ClientType = sfield.ClientType;
			tfield.IsActive = sfield.IsActive;
			tfield.IdentifiedCardType = sfield.IdentifiedCardType;
			tfield.IdentifiedCardNo = sfield.IdentifiedCardNo;

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		//{
		//	m_pkgSend.PreparePackage(
		//			FTD_TID_RtnClientInitTopic,
		//			FTDC_CHAIN_LAST,
		//			FTD_VERSION);

		//	CFTDRtnClientInitField	tfield;
		//	memset(&tfield, 0, sizeof(tfield));
		//	switch (pMessage->GetTid())
		//	{
		//		case TID_DbInsClient:
		//			tfield.OperationType = 0;
		//			break;
		//		case TID_DbUpdClient:
		//			tfield.OperationType = 1;
		//			break;

		//		//			case TID_DbDelClient:
		//		//				tfield.OperationType =2;
		//		//				break;
		//		default:
		//			break;
		//	}

		//	CopyClientEntity(&tfield, &sfield);
		//	FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		//	m_pkgSend.MakePackage();
		//	m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		//}

		itor.Next();
	}
}

void CFPPSubscriber::OnPartClientChg(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnPartClientChg--------------:"<<endl;
	CDbmtPartClientField sfield;
	CFTDRtnPartClientChgField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtPartClientField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnPartClientChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));
		switch (pMessage->GetTid())
		{
			case TID_DbInsPartClient:
				tfield.OperationType = 0;
				break;
			case TID_DbDelPartClient:
				tfield.OperationType = 2;
				break;
			default:
				break;
		}

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.ClientID = sfield.ClientID;
		tfield.ParticipantID = sfield.ParticipantID;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnPosiLimitChg(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnPosiLimitChg--------------:"<<endl;
	CDbmtCurrPartPosiLimitDetailField sfield;
	CFTDRtnPosiLimitChgField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtCurrPartPosiLimitDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnPosiLimitChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));
		switch (pMessage->GetTid())
		{
			case TID_DbInsCurrPartPosiLimitDetail:
				tfield.OperationType = 0;
				break;
			case TID_DbUpdCurrPartPosiLimitDetail:
				tfield.OperationType = 1;
				break;
			case TID_DbDelCurrPartPosiLimitDetail:
				tfield.OperationType = 2;
				break;
			default:
				break;
		}

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ParticipantID = sfield.ParticipantID;
		tfield.TradingRole = sfield.TradingRole;
		tfield.StartTotalPosition = sfield.StartTotalPosition;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongPosLimit = sfield.LongPosLimit;
		tfield.ShortPosLimit = sfield.ShortPosLimit;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnClientPosiLimitChg(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnClientPosiLimitChg--------------:"<<endl;
	CDbmtCurrClientPosiLimitDetailField sfield;
	CFTDRtnClientPosiLimitChgField	tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtCurrClientPosiLimitDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnClientPosiLimitChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));
		switch (pMessage->GetTid())
		{
			case TID_DbInsCurrClientPosiLimitDetail:
				tfield.OperationType = 0;
				break;
			case TID_DbUpdCurrClientPosiLimitDetail:
				tfield.OperationType = 1;
				break;
			case TID_DbDelCurrClientPosiLimitDetail:
				tfield.OperationType = 2;
				break;
			default:
				break;
		}

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ClientType = sfield.ClientType;
		tfield.StartTotalPosition = sfield.StartTotalPosition;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongPosLimit = sfield.LongPosLimit;
		tfield.ShortPosLimit = sfield.ShortPosLimit;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnSpecPosiLimitChg(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnSpecPosiLimitChg--------------:"<<endl;
	CDbmtCurrSpecialPosiLimitDetailField sfield;
	CFTDRtnSpecPosiLimitChgField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtCurrSpecialPosiLimitDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSpecPosiLimitChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));
		switch (pMessage->GetTid())
		{
			case TID_DbInsCurrSpecialPosiLimitDetail:
				tfield.OperationType = 0;
				break;
			case TID_DbUpdCurrSpecialPosiLimitDetail:
				tfield.OperationType = 1;
				break;
			case TID_DbDelCurrSpecialPosiLimitDetail:
				tfield.OperationType = 2;
				break;
			default:
				break;
		}

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ClientID = sfield.ClientID;
		tfield.StartTotalPosition = sfield.StartTotalPosition;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongPosLimit = sfield.LongPosLimit;
		tfield.ShortPosLimit = sfield.ShortPosLimit;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnDbInsHedgeDetail(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnDbInsHedgeDetail--------------:"<<endl;
	CDbmtHedgeDetailField sfield;
	CFTDRtnHedgeDetailChgField	tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtHedgeDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnHedgeDetailChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.ParticipantID = sfield.ParticipantID;
		tfield.ClientID = sfield.ClientID;
		tfield.OperatorID = sfield.OperatorID;
		tfield.Time = sfield.Time;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.PosiDirection = sfield.PosiDirection;
		tfield.TradingVolume = sfield.TradingVolume;
		tfield.HedgeQuota = sfield.HedgeQuota;
		tfield.OperationType = 0;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnDbParticipant(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnDbParticipant--------------:"<<endl;
	CParticipantField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CParticipantField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnParticipantChgTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDRtnParticipantChgField	tfield;
			memset(&tfield, 0, sizeof(tfield));

			//			switch(pMessage->GetTid())
			//			{
			//			case TID_DbInsParticipant:
			//				tfield.OperationType =0;
			//				break;
			//			case TID_DbUpdParticipant:
			//				tfield.OperationType =1;
			//				break;
			//			case TID_DbDelParticipant:
			//				tfield.OperationType =2;
			//				break;
			//			default:
			//				break;
			//			}
			tfield.ActionDate = m_curTime.CurrDate;
			tfield.ActionTime = m_curTime.CurrTime;
			tfield.ParticipantID = sfield.ParticipantID;
			tfield.ParticipantName = sfield.ParticipantName;
			tfield.ParticipantAbbr = sfield.ParticipantAbbr;
			tfield.MemberType = sfield.MemberType;
			tfield.IsActive = sfield.IsActive;

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		/*
		{
			m_pkgSend.PreparePackage(FTD_TID_RtnParticipantInitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
			CFTDRtnParticipantInitField tfield;
			memset(&tfield ,0 ,sizeof(tfield));
			switch(pMessage->GetTid())
			{
			case TID_DbInsParticipant:
				tfield.OperationType =0;
				break;
			case TID_DbUpdParticipant:
				tfield.OperationType =1;
				break;
			case TID_DbDelParticipant:
				tfield.OperationType =2;
				break;
			default:
				break;
			}
			CopyParticipantEntity(&tfield ,&sfield);

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
		}
*/
		itor.Next();
	}
}

void CFPPSubscriber::OnDbUser(CXTPPackage *pMessage)
{
	CDbmtUserField	sfield;
	CFTDRtnUserInitField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtUserField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RtnUserInitTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			memset(&tfield, 0, sizeof(tfield));
			switch (pMessage->GetTid())
			{
				case TID_DbInsUser:
					tfield.OperationType = 0;
					break;
				case TID_DbUpdUser:
					tfield.OperationType = 1;
					break;

				//			case TID_DbDelUser:
				//				tfield.OperationType =2;
				//				break;
				default:
					break;
			}

			CopyUserEntity(&tfield, &sfield);
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		itor.Next();
	}
}

void CFPPSubscriber::OnMarginRateChg(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnMarginRateChg--------------:"<<endl;
	CDbmtCurrMarginRateDetailField	sfield;
	CFTDRtnMarginRateChgField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtCurrMarginRateDetailField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnMarginRateChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));
		switch (pMessage->GetTid())
		{
			case TID_DbInsCurrMarginRateDetail:
				tfield.OperationType = 0;
				break;
			case TID_DbUpdCurrMarginRateDetail:
				tfield.OperationType = 1;
				break;
			case TID_DbDelCurrMarginRateDetail:
				tfield.OperationType = 2;
				break;
			default:
				break;
		}

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.ParticipantID = sfield.ParticipantID;
		tfield.TradingRole = sfield.TradingRole;
		tfield.HedgeFlag = sfield.HedgeFlag;
		tfield.ValueMode = sfield.ValueMode;
		tfield.LongMarginRatio = sfield.LongMarginRatio;
		tfield.ShortMarginRatio = sfield.ShortMarginRatio;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnUserIpChg(CXTPPackage *pMessage)
{
	//	cout<<"-----------------OnUserIpChg--------------:"<<endl;
	CDbmtUserIPField sfield;
	CFTDRtnUserIpChgField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CDbmtUserIPField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnUserIpChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));
		switch (pMessage->GetTid())
		{
			case TID_DbInsUserIP:
				tfield.OperationType = 0;
				break;
			case TID_DbDelUserIP:
				tfield.OperationType = 2;
				break;
			default:
				break;
		}

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.UserID = sfield.UserID;
		tfield.IPAddress = sfield.IPAddress;
		tfield.IPMask = sfield.IPMask;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

list<CUserIDType> userId_List;

void CFPPSubscriber::OnUserLogin(CXTPPackage *pMessage)
{
	CRspInfoField infofield;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &infofield) <= 0)
	{
		return;
	}

	if (infofield.ErrorID != 0)
	{
		return;
	}

	CUserLoginField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CUserLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		// 用户登录频率告警计算
		LoginWarningCalculate::HandleUserLoginField(sfield, pMessage->GetFrontID());

		///new--:
				///先到userId_List里去寻找，如果是要与某登出中和的登录信息，则中和并不再做任何处理：
		list<CUserIDType>::iterator userId_List_It = find(
				userId_List.begin(),
				userId_List.end(),
				sfield.UserID);
		if (userId_List_It != userId_List.end())
		{
			userId_List.erase(userId_List_It);
			itor.Next();
			continue;
		}

		///座席不能重登录，且即便重登录了，数组的赋值方式扔保证该座席的链接协议信息一定:
		g_UserProtocolMap[sfield.UserID] = sfield.ProtocolInfo;

		///统计前置在所有协议下的座席登录数:
				///最终填充g_FrontUserIDMap
		{
			///找到FRONTID:
			map<int, map<CProtocolInfoType, int> >::iterator itFront =
				g_FrontUserIDMap.find(pMessage->GetFrontID());

			///找到FRONTID则继续向下搜索:
			if (itFront != g_FrontUserIDMap.end())
			{
				///找到所含MAP的协议主键:
				map<CProtocolInfoType, int>::iterator itProtocol = itFront->
					second.find(sfield.ProtocolInfo);

				///找到则加1:
				if (itProtocol != itFront->second.end())
				{
					itProtocol->second += 1;
				}

				///找不到则创建此协议主键并让登录数设为1:
				else
				{
					itFront->second[sfield.ProtocolInfo] = 1;
				}
			}

			///找不到FRONTID则创建新元素:
			else
			{
				map<CProtocolInfoType, int> tmp;
				tmp[sfield.ProtocolInfo] = 1;
				g_FrontUserIDMap[pMessage->GetFrontID()] = tmp;
			}
		}

		///统计某数据中心下登录的会员及其所用座席:
				///最终填充g_PudianMap,g_ZhangjinagMap:
		{
			///pudian数据中心所对应的前置
			string	str_Pudian = datacenterPudian + "." + DATACENTERAPP;
			map<string, list<int> >::iterator it = g_DataCenterMap.find(
					str_Pudian);
			if (it != g_DataCenterMap.end())
			{
				list<int>::iterator listIt;

				///查找此前置是否是pudian数据中心的
				listIt = find(
						it->second.begin(),
						it->second.end(),
						pMessage->GetFrontID());

				///如果找到，则插入g_PudianMap
				if (listIt != it->second.end())
				{
					map<CParticipantIDType, list<CUserIDType> >::iterator
						pudianIt = g_PudianMap.find(sfield.ParticipantID);
					if (pudianIt != g_PudianMap.end())
					{
						pudianIt->second.push_back(sfield.UserID);
					}
					else
					{
						list<CUserIDType> userList;
						userList.push_back(sfield.UserID);
						g_PudianMap[sfield.ParticipantID] = userList;
					}
				}
			}

			string	str_ZhangJ = datacenterZhangJ + "." + DATACENTERAPP;
			it = g_DataCenterMap.find(str_ZhangJ);
			if (it != g_DataCenterMap.end())
			{
				list<int>::iterator listIt;

				///查找此前置是否是zhangjiang数据中心的
				listIt = find(
						it->second.begin(),
						it->second.end(),
						pMessage->GetFrontID());

				///如果找到，则插入g_ZhangjinagMap
				if (listIt != it->second.end())
				{
					map<CParticipantIDType, list<CUserIDType> >::iterator
						pudianIt = g_ZhangjinagMap.find(sfield.ParticipantID);
					if (pudianIt != g_ZhangjinagMap.end())
					{
						pudianIt->second.push_back(sfield.UserID);
					}
					else
					{
						list<CUserIDType> userList;
						userList.push_back(sfield.UserID);
						g_ZhangjinagMap[sfield.ParticipantID] = userList;
					}
				}
			}

			string	str_Beijing = datacenterBeijing + "." + DATACENTERAPP;
			it = g_DataCenterMap.find(str_Beijing);
			if (it != g_DataCenterMap.end())
			{
				list<int>::iterator listIt;

				///查找此前置是否是beijing数据中心的
				listIt = find(
						it->second.begin(),
						it->second.end(),
						pMessage->GetFrontID());

				///如果找到，则插入g_BeijingMap
				if (listIt != it->second.end())
				{
					map<CParticipantIDType, list<CUserIDType> >::iterator
						pudianIt = g_BeijingMap.find(sfield.ParticipantID);
					if (pudianIt != g_BeijingMap.end())
					{
						pudianIt->second.push_back(sfield.UserID);
					}
					else
					{
						list<CUserIDType> userList;
						userList.push_back(sfield.UserID);
						g_BeijingMap[sfield.ParticipantID] = userList;
					}
				}
			}
		}

		///按IP地址统计登录信息
		bool flag = false;
		map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.begin();
		string	ipAddr = sfield.IPAddress.getValue();
		for (; it != g_ipLinkInfo.end(); it++)
		{
			list<pair<string, string> >::iterator itList = it->second.ipScope.
				begin();
			for (; itList != it->second.ipScope.end(); itList++)
			{
				if (ntohl(inet_addr(ipAddr.data())) >= ntohl(
						inet_addr(itList->first.data()))
			&&	ntohl(inet_addr(ipAddr.data())) <= ntohl(
						inet_addr(itList->second.data())))
				{
					map<CParticipantIDType, list<userIpInfo> >::iterator itMap =
						it->second.linkNumber.find(sfield.ParticipantID);
					if (itMap != it->second.linkNumber.end())
					{
						userIpInfo	theUserIpInfo;
						theUserIpInfo.id = sfield.UserID;
						theUserIpInfo.ip = sfield.IPAddress;
						itMap->second.push_back(theUserIpInfo);
					}
					else
					{
						list<userIpInfo> userList;
						userIpInfo	theUserIpInfo;
						theUserIpInfo.id = sfield.UserID;
						theUserIpInfo.ip = sfield.IPAddress;
						userList.push_back(theUserIpInfo);
						it->second.linkNumber[sfield.ParticipantID] = userList;
					}

					///处理max登录信息
					itMap = it->second.maxlinkNumber.find(sfield.ParticipantID);
					if (itMap != it->second.maxlinkNumber.end())
					{
						bool listFlag = true;
						list<userIpInfo>::iterator	itList = itMap->second.begin();
						for (; itList != itMap->second.end(); itList++)
						{
							if (itList->id == sfield.UserID)
							{
								listFlag = false;
								break;
							}
						}

						if (listFlag)
						{
							userIpInfo	theUserIpInfo;
							theUserIpInfo.id = sfield.UserID;
							theUserIpInfo.ip = sfield.IPAddress;
							itMap->second.push_back(theUserIpInfo);
						}
					}
					else
					{
						list<userIpInfo> userList;
						userIpInfo	theUserIpInfo;
						theUserIpInfo.id = sfield.UserID;
						theUserIpInfo.ip = sfield.IPAddress;
						userList.push_back(theUserIpInfo);
						it->second.maxlinkNumber[sfield.ParticipantID] = userList;
					}

					flag = true;
					break;
				}
			}

			if (itList != it->second.ipScope.end())
			{
				break;
			}
		}

		if (!flag)
		{
			map<CParticipantIDType, list<userIpInfo> >::iterator itMap =
				theOtherIpInfo.find(sfield.ParticipantID);
			if (itMap != theOtherIpInfo.end())
			{
				userIpInfo	theUserIpInfo;
				theUserIpInfo.id = sfield.UserID;
				theUserIpInfo.ip = sfield.IPAddress;
				itMap->second.push_back(theUserIpInfo);
			}
			else
			{
				list<userIpInfo> userList;
				userIpInfo	theUserIpInfo;
				theUserIpInfo.id = sfield.UserID;
				theUserIpInfo.ip = sfield.IPAddress;
				userList.push_back(theUserIpInfo);
				theOtherIpInfo[sfield.ParticipantID] = userList;
			}

			///处理max登录信息
			itMap = theOtherIpInfoMax.find(sfield.ParticipantID);
			if (itMap != theOtherIpInfoMax.end())
			{
				bool listFlag = true;
				list<userIpInfo>::iterator	itList = itMap->second.begin();
				for (; itList != itMap->second.end(); itList++)
				{
					if (itList->id == sfield.UserID)
					{
						listFlag = false;
						break;
					}
				}

				if (listFlag)
				{
					userIpInfo	theUserIpInfo;
					theUserIpInfo.id = sfield.UserID;
					theUserIpInfo.ip = sfield.IPAddress;
					itMap->second.push_back(theUserIpInfo);
				}
			}
			else
			{
				list<userIpInfo> userList;
				userIpInfo	theUserIpInfo;
				theUserIpInfo.id = sfield.UserID;
				theUserIpInfo.ip = sfield.IPAddress;
				userList.push_back(theUserIpInfo);
				theOtherIpInfoMax[sfield.ParticipantID] = userList;
			}
		}

		///按托管IP地址统计登录信息
		{
			bool flag = false;
			map<string, ipLinkInfo>::iterator it = g_ipLinkInfoTuoGuan.begin();
			string	ipAddr = sfield.IPAddress.getValue();
			for (; it != g_ipLinkInfoTuoGuan.end(); it++)
			{
				list<pair<string, string> >::iterator itList = it->second.
					ipScope.begin();
				for (; itList != it->second.ipScope.end(); itList++)
				{
					if (ntohl(inet_addr(ipAddr.data())) >= ntohl(
							inet_addr(itList->first.data()))
				&&	ntohl(inet_addr(ipAddr.data())) <= ntohl(
							inet_addr(itList->second.data())))
					{
						map<CParticipantIDType, list<userIpInfo> >::iterator
							itMap = it->second.linkNumber.find(
									sfield.ParticipantID);
						if (itMap != it->second.linkNumber.end())
						{
							userIpInfo	theUserIpInfo;
							theUserIpInfo.id = sfield.UserID;
							theUserIpInfo.ip = sfield.IPAddress;
							itMap->second.push_back(theUserIpInfo);
						}
						else
						{
							list<userIpInfo> userList;
							userIpInfo	theUserIpInfo;
							theUserIpInfo.id = sfield.UserID;
							theUserIpInfo.ip = sfield.IPAddress;
							userList.push_back(theUserIpInfo);
							it->second.linkNumber[sfield.ParticipantID] = userList;
						}

						///处理max登录信息
						itMap = it->second.maxlinkNumber.find(
								sfield.ParticipantID);
						if (itMap != it->second.maxlinkNumber.end())
						{
							bool listFlag = true;
							list<userIpInfo>::iterator	itList = itMap->second.
								begin();
							for (; itList != itMap->second.end(); itList++)
							{
								if (itList->id == sfield.UserID)
								{
									listFlag = false;
									break;
								}
							}

							if (listFlag)
							{
								userIpInfo	theUserIpInfo;
								theUserIpInfo.id = sfield.UserID;
								theUserIpInfo.ip = sfield.IPAddress;
								itMap->second.push_back(theUserIpInfo);
							}
						}
						else
						{
							list<userIpInfo> userList;
							userIpInfo	theUserIpInfo;
							theUserIpInfo.id = sfield.UserID;
							theUserIpInfo.ip = sfield.IPAddress;
							userList.push_back(theUserIpInfo);
							it->second.maxlinkNumber[sfield.ParticipantID] = userList;
						}

						flag = true;
						break;
					}
				}

				if (itList != it->second.ipScope.end())
				{
					break;
				}
			}
		}

		///用RSP打包表示座席登入：
		m_pkgSend.PreparePackage(
				FTD_TID_RspQryTradeUserLoginInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRspQryTradeUserLoginInfoField tfield;
		memset(&tfield, 0, sizeof(tfield));

		tfield.UserID = sfield.UserID;
		tfield.ParticipantID = sfield.ParticipantID;

		tfield.IPAddress = sfield.IPAddress;
		tfield.ProtocolInfo = sfield.ProtocolInfo;
		tfield.ActionDate = sfield.ActionDay;
		tfield.ActionTime = sfield.LoginTime;
		tfield.ActionFlag = 0;

		int i = pIpAnalysis->getIpTypeID((char *)(sfield.IPAddress.getValue()));
		tfield.AccessType = g_mStringIDMap.getString(i);
		tfield.UserType = g_mStringIDMap.getString(i);
		tfield.FrontID = pMessage->GetFrontID();

		if (g_DataCenterFlag == 1)
		{
			strcpy((char *)(tfield.DataCenter.getValue()), DATACENTERPUDIAN);
		}
		else if (g_DataCenterFlag == 2)
		{
			strcpy((char *)(tfield.DataCenter.getValue()), DATACENTERZHANGJ);
		}
		else
		{
			strcpy((char *)(tfield.DataCenter.getValue()), DATACENTERBEIJING);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.SetRequestId(pMessage->GetFrontID());
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnUserLogout(CXTPPackage *pMessage)
{
	CRspInfoField infofield;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &infofield) <= 0)
	{
		return;
	}

	//	if(infofield.ErrorID !=0)
	//		return;
	CUserLogoutField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CUserLogoutField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		///g_FrontUserIDMap中某前置的某协议信息的登录计数-1:
		{
			///找到保存过的座席对应协议信息
			CProtocolInfoType tmpProtocolInfoType;
			map<CUserIDType, CProtocolInfoType>::iterator itProtocolInfo =
				g_UserProtocolMap.find(sfield.UserID);

			///new--:
						///如果找到说明该USER登录过：
						///则将登录时候的协议信息填充进来，并删除已登录的USER-PROTOCOL信息：
			if (itProtocolInfo != g_UserProtocolMap.end())
			{
				tmpProtocolInfoType = itProtocolInfo->second;
				g_UserProtocolMap.erase(itProtocolInfo);
			}

			///new--:
						///如果找不到，说明先得到了登出报文，则必然会再得到一个登录报文
						///记下该USER，并因中和作用可省略其他一切操作，跳出本次循环:
			else
			{
				userId_List.push_back(sfield.UserID);
				itor.Next();
				continue;
			}

			///到g_FrontUserIDMap里找到前置
			map<int, map<CProtocolInfoType, int> >::iterator itFront =
				g_FrontUserIDMap.find(pMessage->GetFrontID());
			if (itFront != g_FrontUserIDMap.end())
			{
				///找到刚找到的协议信息，并让该协议信息下的登录计数-1;
				map<CProtocolInfoType, int>::iterator itProtocol = itFront->
					second.find(tmpProtocolInfoType);
				if (itProtocol != itFront->second.end())
				{
					itProtocol->second -= 1;
				}
			}
		}

		///在g_PudianMap或g_ZhangjinagMap中寻找会员并进一步寻找座席，删除座席，如果该会员下没有座席登录，则删除该会员
				///注意，一个会员可通过不同座席登录不同的数据中心
		{
			map<CParticipantIDType, list<CUserIDType> >::iterator it =
				g_PudianMap.find(sfield.ParticipantID);
			if (it != g_PudianMap.end())
			{
				it->second.remove(sfield.UserID);
				if (it->second.size() == 0)
				{
					g_PudianMap.erase(sfield.ParticipantID);
				}
			}

			///因为虽然在g_PudianMap找到该会员，但该会员可能是通过其他座席登录该数据中心，故下面的一定要执行
			//			else
			{
				it = g_ZhangjinagMap.find(sfield.ParticipantID);
				if (it != g_ZhangjinagMap.end())
				{
					it->second.remove(sfield.UserID);
					if (it->second.size() == 0)
					{
						g_ZhangjinagMap.erase(sfield.ParticipantID);
					}
				}
			}
		}

		///用RTN打包，表示座席登出
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeUserLoginInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnTradeUserLoginInfoField	tfield;
		memset(&tfield, 0, sizeof(tfield));

		tfield.ParticipantID = sfield.ParticipantID;
		tfield.UserID = sfield.UserID;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);

		///把FRONTID作为REQUESTID传给前置机
		m_pkgSend.SetRequestId(pMessage->GetFrontID());
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::OnDelUserSession(CXTPPackage *pMessage)
{
	CUserSessionField sfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CUserSessionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);

		///g_FrontUserIDMap中某前置的某协议信息的登录计数-1:
		{
			///到g_FrontUserIDMap里找到前置
			map<int, map<CProtocolInfoType, int> >::iterator itFront =
				g_FrontUserIDMap.find(sfield.FrontID);
			if (itFront != g_FrontUserIDMap.end())
			{
				///找到刚找到的协议信息，并让该协议信息下的登录计数-1;
				map<CProtocolInfoType, int>::iterator itProtocol = itFront->
					second.find(sfield.ProtocolInfo);
				if (itProtocol != itFront->second.end())
				{
					itProtocol->second -= 1;
				}
			}
		}

		///在g_PudianMap或g_ZhangjinagMap中寻找会员并进一步寻找座席，删除座席，如果该会员下没有座席登录，则删除该会员
				///注意，一个会员可通过不同座席登录不同的数据中心
		{
			map<CParticipantIDType, list<CUserIDType> >::iterator it =
				g_PudianMap.find(sfield.ParticipantID);
			if (it != g_PudianMap.end())
			{
				it->second.remove(sfield.UserID);
				if (it->second.size() == 0)
				{
					g_PudianMap.erase(sfield.ParticipantID);
				}
			}

			///因为虽然在g_PudianMap找到该会员，但该会员可能是通过其他座席登录该数据中心，故下面的一定要执行
			it = g_ZhangjinagMap.find(sfield.ParticipantID);
			if (it != g_ZhangjinagMap.end())
			{
				it->second.remove(sfield.UserID);
				if (it->second.size() == 0)
				{
					g_ZhangjinagMap.erase(sfield.ParticipantID);
				}
			}

			it = g_BeijingMap.find(sfield.ParticipantID);
			if (it != g_BeijingMap.end())
			{
				it->second.remove(sfield.UserID);
				if (it->second.size() == 0)
				{
					g_BeijingMap.erase(sfield.ParticipantID);
				}
			}
		}

		///处理ip登录统计信息
		bool flag = false;
		map<string, ipLinkInfo>::iterator it = g_ipLinkInfo.begin();
		for (; it != g_ipLinkInfo.end(); it++)
		{
			list<pair<string, string> >::iterator itScope = it->second.ipScope.
				begin();
			for (; itScope != it->second.ipScope.end(); itScope++)
			{
				string	strIp = sfield.IPAddress.getValue();
				if (ntohl(inet_addr(strIp.data())) >= ntohl(
						inet_addr(itScope->first.data()))
			&&	ntohl(inet_addr(strIp.data())) <= ntohl(
						inet_addr(itScope->second.data())))
				{
					flag = true;
					break;
				}
			}

			if (flag)
			{
				break;
			}
		}

		///如果找到则列入ip统计范畴
		if (flag)
		{
			map<CParticipantIDType, list<userIpInfo> >::iterator itMap = it->
				second.linkNumber.find(sfield.ParticipantID);
			if (itMap != it->second.linkNumber.end())
			{
				list<userIpInfo>::iterator	itList = itMap->second.begin();
				for (; itList != itMap->second.end(); itList++)
				{
					if (itList->id == sfield.UserID)
					{
						break;
					}
				}

				if (itList != itMap->second.end())
				{
					itMap->second.erase(itList);
					if (itMap->second.size() == 0)
					{
						it->second.linkNumber.erase(itMap);
					}

					//break;
				}
			}
		}

		///否则列入other范畴
		else
		{
			map<CParticipantIDType, list<userIpInfo> >::iterator itMap =
				theOtherIpInfo.find(sfield.ParticipantID);
			if (itMap != theOtherIpInfo.end())
			{
				list<userIpInfo>::iterator	itList = itMap->second.begin();
				for (; itList != itMap->second.begin(); itList++)
				{
					if (itList->id == sfield.UserID)
					{
						break;
					}
				}

				if (itList != itMap->second.end())
				{
					itMap->second.erase(itList);
					if (itMap->second.size() == 0)
					{
						theOtherIpInfo.erase(itMap);
					}

					//break;
				}
			}
		}

		///处理托管ip登录统计信息
		{
			bool flag = false;
			map<string, ipLinkInfo>::iterator it = g_ipLinkInfoTuoGuan.begin();
			for (; it != g_ipLinkInfoTuoGuan.end(); it++)
			{
				list<pair<string, string> >::iterator itScope = it->second.
					ipScope.begin();
				for (; itScope != it->second.ipScope.end(); itScope++)
				{
					string	strIp = sfield.IPAddress.getValue();
					if (ntohl(inet_addr(strIp.data())) >= ntohl(
							inet_addr(itScope->first.data()))
				&&	ntohl(inet_addr(strIp.data())) <= ntohl(
							inet_addr(itScope->second.data())))
					{
						flag = true;
						break;
					}
				}

				if (flag)
				{
					break;
				}
			}

			///如果找到则列入托管ip统计范畴
			if (flag)
			{
				bool flag = false;
				map<CParticipantIDType, list<userIpInfo> >::iterator itMap =
					it->second.linkNumber.find(sfield.ParticipantID);
				if (itMap != it->second.linkNumber.end())
				{
					list<userIpInfo>::iterator	itList = itMap->second.begin();
					for (; itList != itMap->second.end(); itList++)
					{
						if (itList->id == sfield.UserID)
						{
							break;
						}
					}

					if (itList != itMap->second.end())
					{
						itMap->second.erase(itList);
						if (itMap->second.size() == 0)
						{
							it->second.linkNumber.erase(itMap);
						}

						//break;
					}
				}
			}
		}

		///用RTN打包，表示座席登出
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeUserLoginInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnTradeUserLoginInfoField	tfield;
		memset(&tfield, 0, sizeof(tfield));

		tfield.ParticipantID = sfield.ParticipantID;
		tfield.UserID = sfield.UserID;
		tfield.FrontID = sfield.FrontID;
		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.ActionFlag = 1;
		tfield.ProtocolInfo = sfield.ProtocolInfo;
		tfield.IPAddress = sfield.IPAddress;

		int i = pIpAnalysis->getIpTypeID((char *)(sfield.IPAddress.getValue()));
		tfield.AccessType = g_mStringIDMap.getString(i);
		tfield.UserType = g_mStringIDMap.getString(i);

		if (g_DataCenterFlag == 1)
		{
			strcpy((char *)(tfield.DataCenter.getValue()), DATACENTERPUDIAN);
		}
		else if (g_DataCenterFlag == 2)
		{
			strcpy((char *)(tfield.DataCenter.getValue()), DATACENTERZHANGJ);
		}
		else
		{
			strcpy((char *)(tfield.DataCenter.getValue()), DATACENTERBEIJING);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);

		///把FRONTID作为REQUESTID传给前置机
		m_pkgSend.SetRequestId(sfield.FrontID);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

void CFPPSubscriber::ReLoad(void)
{
	CFlowReader srFlowReader;
	srFlowReader.AttachFlow(m_TRFlow, 0);

	CFTDCPackage *pFTDCPackage = new CFTDCPackage;
	pFTDCPackage->ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	for (;;)
	{
		pFTDCPackage->Allocate(FTDC_PACKAGE_MAX_SIZE + FTDCHLEN);
		if (!srFlowReader.GetNext(pFTDCPackage))
		{
			break;
		}

		switch (pFTDCPackage->GetTID())
		{
			case FTD_TID_RspQryTradeUserLoginInfoTopic:
				{
					CFTDRspQryTradeUserLoginInfoField sfield;
					CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
							&CFTDRspQryTradeUserLoginInfoField::m_Describe);
					while (!itor.IsEnd())
					{
						itor.Retrieve(&sfield);
						g_UserProtocolMap[sfield.UserID] = sfield.ProtocolInfo;
						{
							map<int, map<CProtocolInfoType, int> >::iterator
								itFront = g_FrontUserIDMap.find(
										pFTDCPackage->GetRequestId());
							if (itFront != g_FrontUserIDMap.end())
							{
								map<CProtocolInfoType, int>::iterator itProtocol =
									itFront->second.find(sfield.ProtocolInfo);
								if (itProtocol != itFront->second.end())
								{
									itProtocol->second += 1;
								}
								else
								{
									itFront->second[sfield.ProtocolInfo] = 1;
								}
							}
							else
							{
								map<CProtocolInfoType, int> tmp;
								tmp[sfield.ProtocolInfo] = 1;
								g_FrontUserIDMap[pFTDCPackage->GetRequestId()] = tmp;
							}
						}

						map<string, list<int> >::iterator it = g_DataCenterMap.begin();
						list<int>::iterator listIt;
						listIt = find(
								it->second.begin(),
								it->second.end(),
								sfield.FrontID);
						if (listIt != it->second.end())
						{
							map<CParticipantIDType, list<CUserIDType> >::iterator
								pudianIt = g_PudianMap.find(sfield.ParticipantID);
							if (pudianIt != g_PudianMap.end())
							{
								pudianIt->second.push_back(sfield.UserID);
							}
							else
							{
								list<CUserIDType> userList;
								userList.push_back(sfield.UserID);
								g_PudianMap[sfield.ParticipantID] = userList;
							}
						}
						else
						{
							it++;
							listIt = find(
									it->second.begin(),
									it->second.end(),
									sfield.FrontID);
							if (listIt != it->second.end())
							{
								map<CParticipantIDType, list<CUserIDType> >::iterator
									pudianIt = g_ZhangjinagMap.find(
											sfield.ParticipantID);
								if (pudianIt != g_ZhangjinagMap.end())
								{
									pudianIt->second.push_back(sfield.UserID);
								}
								else
								{
									list<CUserIDType> userList;
									userList.push_back(sfield.UserID);
									g_ZhangjinagMap[sfield.ParticipantID] = userList;
								}
							}
						}

						itor.Next();
					}
				}

				break;
			case FTD_TID_RtnTradeUserLoginInfoTopic:
				{
					CFTDRtnTradeUserLoginInfoField	sfield;
					CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
							&CFTDRtnTradeUserLoginInfoField::m_Describe);
					while (!itor.IsEnd())
					{
						itor.Retrieve(&sfield);
						{
							CProtocolInfoType tmpProtocolInfoType;
							map<CUserIDType, CProtocolInfoType>::iterator
								itProtocolInfo = g_UserProtocolMap.find(
										sfield.UserID);
							if (itProtocolInfo != g_UserProtocolMap.end())
							{
								tmpProtocolInfoType = itProtocolInfo->second;
							}

							map<int, map<CProtocolInfoType, int> >::iterator
								itFront = g_FrontUserIDMap.find(
										pFTDCPackage->GetRequestId());
							if (itFront != g_FrontUserIDMap.end())
							{
								map<CProtocolInfoType, int>::iterator itProtocol =
									itFront->second.find(tmpProtocolInfoType);
								if (itProtocol != itFront->second.end())
								{
									itProtocol->second -= 1;
								}
							}
						}

						map<CParticipantIDType, list<CUserIDType> >::iterator it =
							g_PudianMap.find(sfield.ParticipantID);
						if (it != g_PudianMap.end())
						{
							it->second.remove(sfield.UserID);
							if (it->second.size() == 0)
							{
								g_PudianMap.erase(sfield.ParticipantID);
							}
						}

						//					else
						{
							it = g_ZhangjinagMap.find(sfield.ParticipantID);
							if (it != g_ZhangjinagMap.end())
							{
								it->second.remove(sfield.UserID);
								if (it->second.size() == 0)
								{
									g_ZhangjinagMap.erase(sfield.ParticipantID);
								}
							}
						}

						itor.Next();
					}
				}

				break;
			default:
				break;
		}
	}
}

void CFPPSubscriber::OnInitPartPosition(CXTPPackage *pMessage)
{
	CPartPositionField	sfield;
	CFTDRspQryPartTradeField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CPartPositionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		{
			m_pkgSend.PreparePackage(
					FTD_TID_RspQryPartTradeTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			memset(&tfield, 0, sizeof(tfield));

			tfield.ParticipantID = sfield.ParticipantID;
			tfield.InstrumentID = sfield.InstrumentID;
			if (sfield.PosiDirection == '2')
			{
				tfield.TotalPositivePosi = sfield.YdPosition;
			}
			else if (sfield.PosiDirection == '3')
			{
				tfield.TotalNegativePosi = sfield.YdPosition;
			}

			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		itor.Next();
	}
}

void CFPPSubscriber::OnCurrPriceBandingChg(CXTPPackage *pMessage)
{
	CCurrPriceBandingField	sfield;
	CFTDRtnPriceLimitChgField tfield;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(
			&CCurrPriceBandingField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnPriceLimitChgTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		memset(&tfield, 0, sizeof(tfield));
		switch (pMessage->GetTid())
		{
			case TID_DbInsCurrPriceBanding:
				tfield.OperationType = 0;
				break;
			case TID_DbUpdCurrPriceBanding:
				tfield.OperationType = 1;
				break;
			case TID_DbDelCurrPriceBanding:
				tfield.OperationType = 2;
				break;
			default:
				break;
		}

		tfield.ActionDate = m_curTime.CurrDate;
		tfield.ActionTime = m_curTime.CurrTime;
		tfield.InstrumentID = sfield.InstrumentID;
		tfield.LowerLimitPrice = sfield.LowerValue;
		tfield.RoundingMode = sfield.RoundingMode;
		tfield.UpperLimitPrice = sfield.UpperValue;
		tfield.ValueMode = sfield.ValueMode;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

		itor.Next();
	}
}

//会员初始化
void CFPPSubscriber::OnInitParticipant(CXTPPackage *pMessage)
{
	CParticipantField sfield;
	CNamedFieldIterator itor = m_pkgXTP.GetNamedFieldIterator(
			&CParticipantField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&sfield);
		m_pkgSend.PreparePackage(
				FTD_TID_RtnParticipantInitTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnParticipantInitField tfield;
		tfield.OperationType = 0;
		CopyParticipantEntity(&tfield, &sfield);
		FTDC_ADD_FIELD(&m_pkgSend, &tfield);
		m_pkgSend.MakePackage();
		m_TRFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		itor.Next();
	}
}

void CSeatOrderTrdCslTrace::AddOrder(
	int nType,
	string	strTime,
	int nCnt,
	double	nPrice)
{
	if (mpTraceOrdInput.find(strTime) == mpTraceOrdInput.end())
	{
		CFTDRtnParticTradeOrderStatesField	&sField = mpTraceOrdInput[strTime];
		memset(&sField, 0, sizeof(sField));
		sField.ParticipantID = strPartyNo.data();
		sField.UserID = strUserNo.data();
		sField.FrontID = nFrontID;
		sField.MonDate = m_curTime.CurrDate;

		// 		time_t timep;
		// 		time(&timep);
		//
		// 		struct tm *pGm = localtime(&timep);
		//
		// 		sprintf((char *)(sField.MonDate.getValue()),"%d%02d%02d" ,pGm->tm_year+1900 ,pGm->tm_mon+1 ,pGm->tm_mday);
		sField.MonTime = strTime.data();
	}

	CFTDRtnParticTradeOrderStatesField	&sField = mpTraceOrdInput[strTime];

	//下单
	if (nType == 1)
	{
		sField.OrderCount += nCnt;

		if (nCnt > sField.OrderCntMax)
		{
			sField.OrderCntMax = nCnt;
		}
	}

	//撤单
	else if (nType == 2)
	{
		sField.CancleCount += nCnt;

		if (nCnt > sField.CancleCntMax)
		{
			sField.CancleCntMax = nCnt;
		}
	}

	//成交
	else if (nType == 3)
	{
		sField.TradeCount += nCnt;
		sField.TradeMoney += nPrice;

		if (nCnt > sField.TradeCntMax)
		{
			sField.TradeCntMax = nCnt;
		}

		if (nPrice > sField.TradeMoneyMax)
		{
			sField.TradeMoneyMax = nPrice;
		}
	}
	else
	{
	}
}

//每秒由定时器调用一次
void CMemberTradeOrderRecTrace::HasPacksNeedSend(
	list<CFTDRtnParticTradeOrderStatesField> &lstPktRdy)
{
	map<string, CSeatOrderTrdCslTrace>::iterator m_Iter;
	for (m_Iter = mpSeatTrade.begin(); m_Iter != mpSeatTrade.end(); m_Iter++)
	{
		CSeatOrderTrdCslTrace &seatTrd = m_Iter->second;

		map<string, CFTDRtnParticTradeOrderStatesField>::iterator m_Iter2;
		for (m_Iter2 = seatTrd.mpTraceOrdInput.begin();
			 m_Iter2 != seatTrd.mpTraceOrdInput.end();
			 m_Iter2++)
		{
			lstPktRdy.push_back(m_Iter2->second);
		}

		seatTrd.mpTraceOrdInput.clear();
	}
}


/************************************************************************
* 以下实现用于会员用户登录告警功能
************************************************************************/

// 保存所有会员用户的统计信息
map<UPLoginRecordID, UPLoginRecord*> UPLoginRecord::m_AllRecords;

/* 保存所有的计算对象 */
vector<LoginWarningCalculate*> LoginWarningCalculate::m_AllCalculate;

/* 存放用于发送数据的包 */
CFTDCPackage LoginWarningCalculate::m_pkgSend;
/* 存放用于发送时间的数据域 */
/* 保存发送Syslog事件时使用的ObjectID，读取自配置文件 */
/* 若无，则默认为TRADE.PuDian.app.tkernel.1 */
CFTDRtnSyslogEventField LoginWarningCalculate::m_SyslogEventField;

UPLoginRecord* UPLoginRecord::fetchRecord(const UPLoginRecordID& _id, LoginRecordType _type)
{
	UPLoginRecord* pRecord = NULL;
	map<UPLoginRecordID, UPLoginRecord*>::iterator it
		= m_AllRecords.find(_id);
	if (it == m_AllRecords.end())
	{
		pRecord = new UPLoginRecord(_id, _type);
		m_AllRecords.insert(make_pair(_id, pRecord));
	}
	else
		pRecord = it->second;
	return pRecord;
}

void UPLoginRecord::removeRecord(const UPLoginRecordID& _id)
{
	map<UPLoginRecordID, UPLoginRecord*>::iterator it
		= m_AllRecords.find(_id);
	if (it != m_AllRecords.end())
	{
		delete it->second;
		m_AllRecords.erase(it);
	}
}

void UPLoginRecord::resetAllRecords()
{
	for (map<UPLoginRecordID, UPLoginRecord*>::iterator it = m_AllRecords.begin();
		it != m_AllRecords.end(); ++it)
	{
		it->second->resetRecord();
	}
}

// 计算从_endMoment时刻向前_timeLength秒内的登陆次数
int UPLoginRecord::loginCount(time_t _endMoment, int _timeLength) const
{
	if (m_LoginRecords.empty()) return 0;

	int nCount = 0;
	time_t tStartMoment = _endMoment - _timeLength;
	for (vector<LoginInfo>::const_reverse_iterator itRecord = m_LoginRecords.rbegin();
		itRecord != m_LoginRecords.rend(); ++itRecord)
	{
		if (itRecord->LoginTime >= tStartMoment && itRecord->LoginTime <= _endMoment)
			++nCount;
		else if (itRecord->LoginTime < tStartMoment)
			break;
	}
	return nCount;
}

typedef int FRONT_ID;
static int detailCompare(const pair<FRONT_ID, int>& _v1, const pair<FRONT_ID, int>& _v2)
{
	return _v1.second > _v2.second;
}

std::string UPLoginRecord::loginDetail(
	time_t _endMoment /*= 0*/,
	int _timeLength /*= 0*/,
	int _outputLen /*= 2*/) const
{
	if (_outputLen <= 0) return "";

	// 登录明细
	// key：前置ID，value：登录次数
	map<FRONT_ID, int> _loginDetail;

	time_t tStartMoment = (_endMoment <= 0 || _timeLength <= 0) ? 0 : _endMoment - _timeLength;
	_endMoment = (tStartMoment == 0) ? LLONG_MAX : _endMoment;

	for (vector<LoginInfo>::const_iterator itRecord = m_LoginRecords.begin();
		itRecord != m_LoginRecords.end(); ++itRecord)
	{
		if (itRecord->LoginTime >= tStartMoment && itRecord->LoginTime <= _endMoment)
		{
			map<FRONT_ID, int>::iterator itDetail = _loginDetail.find(itRecord->FrontID);
			if (itDetail == _loginDetail.end())
				_loginDetail.insert(make_pair(itRecord->FrontID, 1));
			else
				itDetail->second++;
		}
	}

	// 按照登录次数排序
	vector< pair<FRONT_ID, int> > _orderedDetail(_loginDetail.begin(), _loginDetail.end());
	sort(_orderedDetail.begin(), _orderedDetail.end(), detailCompare);

	string strLoginDetail;
	char buffer[128];
	for (int i = 0; i < _outputLen && i < _orderedDetail.size(); ++i)
	{
		memset(buffer, 0, 128);
		sprintf(buffer, "front%d[%d] ", _orderedDetail[i].first, _orderedDetail[i].second);
		strLoginDetail.append(buffer);
	}
	strLoginDetail.append("...");
	return strLoginDetail;
}


bool LoginWarningCalculate::loadCalculateObjectFromXml(const char* _fileName)
{
	// 初始化数据包
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1024);

	// 文件检查
	struct stat statbuf;
	if (stat(_fileName, &statbuf) != 0)
	{
		fprintf(stderr, "Can not open file [%s] with errno[%d]%s.\n",
			_fileName, errno, strerror(errno));
		return false;
	}

	// 删除已有信息（若有）
	for (vector<LoginWarningCalculate*>::iterator
		itObject = m_AllCalculate.begin();
		itObject != m_AllCalculate.end();
		++itObject)
	{
		delete *itObject;
	}
	m_AllCalculate.clear();

	try
	{
		CXMLDoc CfgXmlDoc;
		CfgXmlDoc.read(const_cast<char*>(_fileName));
		CXMLNode *pSystemCfgRoot = CfgXmlDoc.getRootNode();

		// start load MemberLoginWarningEvents
		{
			// MemberLoginWarningEvents Tag
			CXMLNode* pLoginWarningTag = pSystemCfgRoot->findNode(XMLTag, "MemberLoginWarningEvents");
			if (pLoginWarningTag == NULL) throw "Can not find MemberLoginWarningEvents Tag";

			char* szObjectID = pLoginWarningTag->findProperty("objectid");
			memset(&m_SyslogEventField, 0, sizeof(m_SyslogEventField));
			m_SyslogEventField.ObjectID = (szObjectID == NULL) ? "TRADE.PuDian.app.tkernel.1" : szObjectID;

			CXMLNodeList *pNodeList = pLoginWarningTag->getNodeList();
			if (pNodeList == NULL || pNodeList->empty()) throw "Node list of LoginWarningEvents Tag is Null";

			for (CXMLNodeList::iterator itNode = pNodeList->begin();
				itNode != pNodeList->end();
				++itNode)
			{
				CXMLNode* pLoginWarningNode = *itNode;

				// get all properties of this node
				char* szEventName = pLoginWarningNode->findProperty("eventname");
				if (szEventName == NULL) throw "eventname of LoginWarningEvent is Null";

				char* szInterval = pLoginWarningNode->findProperty("interval");
				if (szInterval == NULL) throw "interval of LoginWarningEvent is Null";
				int nInterval = atoi(szInterval);

				char* szThreshold = pLoginWarningNode->findProperty("threshold");
				if (szThreshold == NULL) throw "threshold of LoginWarningEvent is Null";
				int nThreshold = atoi(szThreshold);

				char* szWarningGap = pLoginWarningNode->findProperty("warninggap");
				if (szWarningGap == NULL) throw "warninggap of LoginWarningEvent is Null";
				int nWarningGap = atoi(szWarningGap);

				char* szUserEnable = pLoginWarningNode->findProperty("user");
				bool bUserEnable = (szWarningGap != NULL) ? !!atoi(szUserEnable) : true;

				char* szParticipantEnable = pLoginWarningNode->findProperty("participant");
				bool bPartycipantEnable = (szParticipantEnable != NULL) ? !!atoi(szParticipantEnable) : true;

				if (nInterval <= 0 || nThreshold <= 0 || nWarningGap <= 0)
					printf("Args of LoginWarningEvent[%s] is error!\n", szEventName);
				else
				{
					// add this warning calculate object
					LoginWarningCalculate* pLoginWarningObject =
						new LoginWarningCalculate(szEventName, nInterval, nThreshold,
								nWarningGap, bUserEnable, bPartycipantEnable);
					m_AllCalculate.push_back(pLoginWarningObject);

					printf("[MemberLoginWarningEvents] EventName[%s] Interval[%s] Threshold[%s], WarningGap[%s] UserEnable[%s] ParticipantEnable[%s]\n",
						szEventName, szInterval, szThreshold, szWarningGap, (bUserEnable) ? "YES" : "NO", (bPartycipantEnable) ? "YES" : "NO");
				}
				
			}
		} // end load MemberLoginWarningEvents info
	}
	catch (CRuntimeError * e)
	{
		printf("[MemberLoginWarningEvents] Error when load %s info:\nLINE[%d]:%s\n",
			_fileName, e->GetLineNo(), e->GetMsg());
		return false;
	}
	catch (const char* e)
	{
		printf("[MemberLoginWarningEvents] %s\n", e);
		return false;
	}

	return true;
}

void LoginWarningCalculate::HandleUserLoginField(const CUserLoginField& _loginField, int _frontID)
{
	// 当前时间，后续多次使用，采用统一的时刻值
	time_t tNow = time(NULL);

	// 如果不存在计算对象，直接退出
	if (m_AllCalculate.empty()) return;

	UPLoginRecordID idParticipant(_loginField.ParticipantID.getValue());
	UPLoginRecordID idUser(_loginField.UserID.getValue());
	if (idParticipant.empty() || idUser.empty())
	{
		printf("CUserLoginField With Empty UserID or ParticipantID\n");
	}

	// 获取该用户的登录记录
	UPLoginRecord* pParticipantRecord = UPLoginRecord::fetchRecord(idParticipant, Participant);
	// 获取该席位的登录记录
	UPLoginRecord* pUserRecord = UPLoginRecord::fetchRecord(idUser, User);

	// 用户登录时间以流水中的时间为准
	time_t tLoginTime = convertToTime(_loginField.ActionDay, _loginField.LoginTime);
	if (tLoginTime == -1) tLoginTime = tNow;	// 如果时间转换发生错误，使用本地时间代替

	// 记录时间值
	pParticipantRecord->record(tLoginTime, _frontID);
	pUserRecord->record(tLoginTime, _frontID);

	// 遍历所有的告警计算对象，计算当前登录信息是否符合告警阈值
	for (vector<LoginWarningCalculate*>::iterator itObject = m_AllCalculate.begin();
		itObject != m_AllCalculate.end(); ++itObject)
	{
		LoginWarningCalculate* pWarningCalculate = *itObject;

		// 判断该告警是否对席位有效
		if (pWarningCalculate->m_UserEnable)
		{
			pWarningCalculate->HandleRecord(pUserRecord, tLoginTime, tNow);
		}
		// 判断该告警是否对用户有效
		if (pWarningCalculate->m_ParticipantEnable)
		{
			pWarningCalculate->HandleRecord(pParticipantRecord, tLoginTime, tNow);
		}
	}
}

//连接的eventcounter
extern list<CFTDCSession *> sessionList;
void LoginWarningCalculate::HandleRecord(UPLoginRecord* _Record, time_t _BasisTime, time_t _LocalTime)
{
	// 获取用户对象的中间状态
	RecordState& PState = getRecordState(_Record->getRecordID());
	// 只有处于应当告警的时间段之内，才进行计算
	if (_LocalTime - PState.LastWarningTime >= m_WarningGap)
	{
		// 获取记录中，以基准时刻为起点，向前m_Interval秒内的登录次数
		int nLoginCount = _Record->loginCount(_BasisTime, m_Interval);
		// 登录次数超过阈值，告警
		if (nLoginCount >= m_Threshold)
		{
			// 填写数据域
			struct tm tm_Now;
			LocalTime(&_LocalTime, &tm_Now);
			strftime((char*)m_SyslogEventField.MonTime.getValue(), 10, "%H:%M:%S", &tm_Now);
			strftime((char*)m_SyslogEventField.MonDate.getValue(), 10, "%Y%m%d", &tm_Now);

			m_SyslogEventField.OccurDate = m_SyslogEventField.MonDate.getValue();
			m_SyslogEventField.OccurTime = m_SyslogEventField.MonTime.getValue();

			m_SyslogEventField.EventName = m_EventName.c_str();

			// 产生告警描述
			if (_Record->getRecordType() == User)
			{
				sprintf((char*)m_SyslogEventField.EventDes.getValue(),
					"User=%s, interval=%d, IntCount=%d, TotalCount=%d, Detail=\"%s\"",
					_Record->getRecordID().c_str(),
					m_Interval, nLoginCount,
					_Record->loginTotalCount(),
					_Record->loginDetail(_BasisTime, m_Interval).c_str());
			}
			else
			{
				sprintf((char*)m_SyslogEventField.EventDes.getValue(),
					"Participant=%s, interval=%d, IntCount=%d, TotalCount=%d, Detail=\"%s\"",
					_Record->getRecordID().c_str(),
					m_Interval, nLoginCount,
					_Record->loginTotalCount(),
					_Record->loginDetail(_BasisTime, m_Interval).c_str());
			}
#if 1
			printf("[MemberLoginWarningEvents] %s\n", m_SyslogEventField.EventDes.getValue());
#endif
			// 发送数据包
			m_pkgSend.PreparePackage(FTD_TID_RtnSyslogEventTopic,
				FTDC_CHAIN_LAST, FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &m_SyslogEventField);
			for (list < CFTDCSession * >::iterator itEventSession = sessionList.begin();
				itEventSession != sessionList.end(); itEventSession++)
			{
				(*itEventSession)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}

			// 更新状态时间
			PState.LastWarningTime = _LocalTime;
		}
	}
}

LoginWarningCalculate::RecordState& 
LoginWarningCalculate::getRecordState(const UPLoginRecordID& _RecordID)
{
	map<UPLoginRecordID, RecordState>::iterator
		it = m_AllRecordState.find(_RecordID);
	if (it == m_AllRecordState.end())
	{
		RecordState _pstat;
		m_AllRecordState.insert(make_pair(_RecordID, _pstat));
		it = m_AllRecordState.find(_RecordID);
	}
	return it->second;
}

