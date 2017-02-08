/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CFPPSubscriber.cpp
///@brief	ʵ���˶���������fibproxy�Ự�����࣬ʵ��FTD����XTP����ת��
///@history
///20080624	����		�������ļ�
///20080624	����		�޶�ע��
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

///�Ž����ֵ�string��Ӧǰ��ID��ϵ��MAP:
map<string, list<int> > g_DataCenterMap;

///������¼����ϯ���Աͳ��
map<CParticipantIDType, list<CUserIDType> > g_BeijingMap;

///�ֵ��¼����ϯ���Աͳ��
map<CParticipantIDType, list<CUserIDType> > g_PudianMap;

///�Ž���¼����ϯ���Աͳ��
map<CParticipantIDType, list<CUserIDType> > g_ZhangjinagMap;

///����ͳ��ǰ�õ�ĳЭ���µ�¼��ϯ����MAP
///��һ��intΪFRONTID
///�ڶ���intΪĳЭ���µ���ϯ��¼��
map<int, map<CProtocolInfoType, int> >	g_FrontUserIDMap;

///��ϯ��Э����Ϣ��Ӧ��ϵMAP:
map<CUserIDType, CProtocolInfoType> g_UserProtocolMap;

///ǰ�ñ����Ȳ���ͳ����Ӧ��MAP��
map<int, CFTDRspQryFrontStatField>	g_FrontStatMap;

///���ڰ�IPͳ�Ƶ�¼��
extern map<string, ipLinkInfo>	g_ipLinkInfo;

///��IP�й�ͳ�������Ϣ
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

//key ��Ա��
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

	// �����û���¼ͳ����Ϣ
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

		///����
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

	///�������100������
	BufferLast100Packages();

	//printf("�����ļ� �� %s ������%d \n" , __FILE__, __LINE__);
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

					///20101210��ʼ�����ָ�Ϊ�������ļ���ȡ
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

					/// �����˽���2.0ϵͳ�����ı������
					/// 2.0 PD��11
					/// 2.0 ZJ��12
					/// 2.0 BJ��13
					int nDataCenterID = sfield.DataCenterID.getValue() % 10;

					///�������л���
					if (nDataCenterID != g_DataCenterFlag)
					{
						g_DataCenterFlag = nDataCenterID;

						int frontNum = 0;

						///����g_DataCenterMap:
											///2009-05-11ȷ��������ǰ�ñ��:
						///����g_FrontUserIDMap:
											///���µ�������ȫ����գ�
						{
							g_FrontUserIDMap.clear();
						}

						///����g_FrontStatMap:
											///���µ�������ȫ����գ�
						{
							g_FrontStatMap.clear();
						}

						///����g_PudianMap:
											///��ǰ��������գ�
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

						///֪ͨǰ�û������˽���ϵͳ�����л���
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RtnDataCenterChgTopic,
									FTDC_CHAIN_LAST,
									FTD_VERSION);

							CFTDRtnDataCenterChgField tfield;
							memset(&tfield, 0, sizeof(tfield));

							///д�����֣�
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
		
	//	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
	// NS-1400���ϵͳ7*24����ģʽ�»�Աϯλ��ͳ���쳣
#if 0
		if ((sfield.CurrTime>="07:00:00"&&sfield.CurrTime<="08:00:00") || (sfield.CurrTime>="19:00:00"&&sfield.CurrTime<="20:00:00"))
		{
			string curdate = sfield.CurrDate.getValue();
			string curtime = sfield.CurrTime.getValue();
			string curdatetime = curdate+curtime;

			printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
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

				//���proxy��ˮ
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
		/// Ϊ֧��ҹ�н��׽ڿ���������ȡ��ԭ����Ȼ�տ���ʱ����Դ����
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

		///�Խ���ϵͳǰ����ͳ�ƣ�
		map<int, CFTDRspQryFrontStatField>::iterator itFront = g_FrontStatMap.
			find(pMessage->GetFrontID());

		///����Ҳ������򴴽���ǰ��ID��Ӧ��������:
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
		///�������ȷ������
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
				//��¼����
				{
					// 					string strParti = sfield.ParticipantID.getValue();
					// 					string strMem = sfield.UserID.getValue();
					// 					string strTime = m_curTime.CurrTime.getValue();
					//  					CMemberTradeOrderRecTrace &membTrd = g_PartiTradeOrdPl[strParti];
					//  					CSeatOrderTrdCslTrace &seatTrd = membTrd.RecordNewOrderInput(strMem);
					// 					seatTrd.AddOrder(1, strTime, sfield.VolumeTotalOriginal.getValue());
				}

				///��ipͳ��
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

				///���й�ipͳ��
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

					///�Խ���ǰ�ý���ͳ��
					(*itFront).second.PositiveOrder += 1;
					(*itFront).second.TotalPositiveOrder += sfield.VolumeTotalOriginal;
				}
				else
				{
					tfield.TotalNegativeOrder = sfield.VolumeTotalOriginal;

					///�Խ���ǰ�ý���ͳ��
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

		///����Ǵ��󱨵�:
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

				///��ipͳ��
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

				///���й�ipͳ��
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

				///�Խ���ǰ�ý���ͳ��
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
		///�Խ���ϵͳǰ����ͳ�ƣ�
	map<int, CFTDRspQryFrontStatField>::iterator itFront = g_FrontStatMap.find(
			pMessage->GetFrontID());

	///����Ҳ������򴴽���ǰ��ID��Ӧ��������:
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

		///�Խ���ǰ�ý���ͳ��
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

		//ͳ�Ʊ���
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

		///��ipͳ�Ʊ�ȡ��
		///����ɽ������ͳֲ�������
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

		// �û���¼Ƶ�ʸ澯����
		LoginWarningCalculate::HandleUserLoginField(sfield, pMessage->GetFrontID());

		///new--:
				///�ȵ�userId_List��ȥѰ�ң������Ҫ��ĳ�ǳ��к͵ĵ�¼��Ϣ�����кͲ��������κδ���
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

		///��ϯ�����ص�¼���Ҽ����ص�¼�ˣ�����ĸ�ֵ��ʽ�ӱ�֤����ϯ������Э����Ϣһ��:
		g_UserProtocolMap[sfield.UserID] = sfield.ProtocolInfo;

		///ͳ��ǰ��������Э���µ���ϯ��¼��:
				///�������g_FrontUserIDMap
		{
			///�ҵ�FRONTID:
			map<int, map<CProtocolInfoType, int> >::iterator itFront =
				g_FrontUserIDMap.find(pMessage->GetFrontID());

			///�ҵ�FRONTID�������������:
			if (itFront != g_FrontUserIDMap.end())
			{
				///�ҵ�����MAP��Э������:
				map<CProtocolInfoType, int>::iterator itProtocol = itFront->
					second.find(sfield.ProtocolInfo);

				///�ҵ����1:
				if (itProtocol != itFront->second.end())
				{
					itProtocol->second += 1;
				}

				///�Ҳ����򴴽���Э���������õ�¼����Ϊ1:
				else
				{
					itFront->second[sfield.ProtocolInfo] = 1;
				}
			}

			///�Ҳ���FRONTID�򴴽���Ԫ��:
			else
			{
				map<CProtocolInfoType, int> tmp;
				tmp[sfield.ProtocolInfo] = 1;
				g_FrontUserIDMap[pMessage->GetFrontID()] = tmp;
			}
		}

		///ͳ��ĳ���������µ�¼�Ļ�Ա����������ϯ:
				///�������g_PudianMap,g_ZhangjinagMap:
		{
			///pudian������������Ӧ��ǰ��
			string	str_Pudian = datacenterPudian + "." + DATACENTERAPP;
			map<string, list<int> >::iterator it = g_DataCenterMap.find(
					str_Pudian);
			if (it != g_DataCenterMap.end())
			{
				list<int>::iterator listIt;

				///���Ҵ�ǰ���Ƿ���pudian�������ĵ�
				listIt = find(
						it->second.begin(),
						it->second.end(),
						pMessage->GetFrontID());

				///����ҵ��������g_PudianMap
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

				///���Ҵ�ǰ���Ƿ���zhangjiang�������ĵ�
				listIt = find(
						it->second.begin(),
						it->second.end(),
						pMessage->GetFrontID());

				///����ҵ��������g_ZhangjinagMap
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

				///���Ҵ�ǰ���Ƿ���beijing�������ĵ�
				listIt = find(
						it->second.begin(),
						it->second.end(),
						pMessage->GetFrontID());

				///����ҵ��������g_BeijingMap
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

		///��IP��ַͳ�Ƶ�¼��Ϣ
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

					///����max��¼��Ϣ
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

			///����max��¼��Ϣ
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

		///���й�IP��ַͳ�Ƶ�¼��Ϣ
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

						///����max��¼��Ϣ
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

		///��RSP�����ʾ��ϯ���룺
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

		///g_FrontUserIDMap��ĳǰ�õ�ĳЭ����Ϣ�ĵ�¼����-1:
		{
			///�ҵ����������ϯ��ӦЭ����Ϣ
			CProtocolInfoType tmpProtocolInfoType;
			map<CUserIDType, CProtocolInfoType>::iterator itProtocolInfo =
				g_UserProtocolMap.find(sfield.UserID);

			///new--:
						///����ҵ�˵����USER��¼����
						///�򽫵�¼ʱ���Э����Ϣ����������ɾ���ѵ�¼��USER-PROTOCOL��Ϣ��
			if (itProtocolInfo != g_UserProtocolMap.end())
			{
				tmpProtocolInfoType = itProtocolInfo->second;
				g_UserProtocolMap.erase(itProtocolInfo);
			}

			///new--:
						///����Ҳ�����˵���ȵõ��˵ǳ����ģ����Ȼ���ٵõ�һ����¼����
						///���¸�USER�������к����ÿ�ʡ������һ�в�������������ѭ��:
			else
			{
				userId_List.push_back(sfield.UserID);
				itor.Next();
				continue;
			}

			///��g_FrontUserIDMap���ҵ�ǰ��
			map<int, map<CProtocolInfoType, int> >::iterator itFront =
				g_FrontUserIDMap.find(pMessage->GetFrontID());
			if (itFront != g_FrontUserIDMap.end())
			{
				///�ҵ����ҵ���Э����Ϣ�����ø�Э����Ϣ�µĵ�¼����-1;
				map<CProtocolInfoType, int>::iterator itProtocol = itFront->
					second.find(tmpProtocolInfoType);
				if (itProtocol != itFront->second.end())
				{
					itProtocol->second -= 1;
				}
			}
		}

		///��g_PudianMap��g_ZhangjinagMap��Ѱ�һ�Ա����һ��Ѱ����ϯ��ɾ����ϯ������û�Ա��û����ϯ��¼����ɾ���û�Ա
				///ע�⣬һ����Ա��ͨ����ͬ��ϯ��¼��ͬ����������
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

			///��Ϊ��Ȼ��g_PudianMap�ҵ��û�Ա�����û�Ա������ͨ��������ϯ��¼���������ģ��������һ��Ҫִ��
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

		///��RTN�������ʾ��ϯ�ǳ�
		m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeUserLoginInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

		CFTDRtnTradeUserLoginInfoField	tfield;
		memset(&tfield, 0, sizeof(tfield));

		tfield.ParticipantID = sfield.ParticipantID;
		tfield.UserID = sfield.UserID;

		FTDC_ADD_FIELD(&m_pkgSend, &tfield);

		///��FRONTID��ΪREQUESTID����ǰ�û�
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

		///g_FrontUserIDMap��ĳǰ�õ�ĳЭ����Ϣ�ĵ�¼����-1:
		{
			///��g_FrontUserIDMap���ҵ�ǰ��
			map<int, map<CProtocolInfoType, int> >::iterator itFront =
				g_FrontUserIDMap.find(sfield.FrontID);
			if (itFront != g_FrontUserIDMap.end())
			{
				///�ҵ����ҵ���Э����Ϣ�����ø�Э����Ϣ�µĵ�¼����-1;
				map<CProtocolInfoType, int>::iterator itProtocol = itFront->
					second.find(sfield.ProtocolInfo);
				if (itProtocol != itFront->second.end())
				{
					itProtocol->second -= 1;
				}
			}
		}

		///��g_PudianMap��g_ZhangjinagMap��Ѱ�һ�Ա����һ��Ѱ����ϯ��ɾ����ϯ������û�Ա��û����ϯ��¼����ɾ���û�Ա
				///ע�⣬һ����Ա��ͨ����ͬ��ϯ��¼��ͬ����������
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

			///��Ϊ��Ȼ��g_PudianMap�ҵ��û�Ա�����û�Ա������ͨ��������ϯ��¼���������ģ��������һ��Ҫִ��
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

		///����ip��¼ͳ����Ϣ
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

		///����ҵ�������ipͳ�Ʒ���
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

		///��������other����
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

		///�����й�ip��¼ͳ����Ϣ
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

			///����ҵ��������й�ipͳ�Ʒ���
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

		///��RTN�������ʾ��ϯ�ǳ�
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

		///��FRONTID��ΪREQUESTID����ǰ�û�
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

//��Ա��ʼ��
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

	//�µ�
	if (nType == 1)
	{
		sField.OrderCount += nCnt;

		if (nCnt > sField.OrderCntMax)
		{
			sField.OrderCntMax = nCnt;
		}
	}

	//����
	else if (nType == 2)
	{
		sField.CancleCount += nCnt;

		if (nCnt > sField.CancleCntMax)
		{
			sField.CancleCntMax = nCnt;
		}
	}

	//�ɽ�
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

//ÿ���ɶ�ʱ������һ��
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
* ����ʵ�����ڻ�Ա�û���¼�澯����
************************************************************************/

// �������л�Ա�û���ͳ����Ϣ
map<UPLoginRecordID, UPLoginRecord*> UPLoginRecord::m_AllRecords;

/* �������еļ������ */
vector<LoginWarningCalculate*> LoginWarningCalculate::m_AllCalculate;

/* ������ڷ������ݵİ� */
CFTDCPackage LoginWarningCalculate::m_pkgSend;
/* ������ڷ���ʱ��������� */
/* ���淢��Syslog�¼�ʱʹ�õ�ObjectID����ȡ�������ļ� */
/* ���ޣ���Ĭ��ΪTRADE.PuDian.app.tkernel.1 */
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

// �����_endMomentʱ����ǰ_timeLength���ڵĵ�½����
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

	// ��¼��ϸ
	// key��ǰ��ID��value����¼����
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

	// ���յ�¼��������
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
	// ��ʼ�����ݰ�
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 1024);

	// �ļ����
	struct stat statbuf;
	if (stat(_fileName, &statbuf) != 0)
	{
		fprintf(stderr, "Can not open file [%s] with errno[%d]%s.\n",
			_fileName, errno, strerror(errno));
		return false;
	}

	// ɾ��������Ϣ�����У�
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
	// ��ǰʱ�䣬�������ʹ�ã�����ͳһ��ʱ��ֵ
	time_t tNow = time(NULL);

	// ��������ڼ������ֱ���˳�
	if (m_AllCalculate.empty()) return;

	UPLoginRecordID idParticipant(_loginField.ParticipantID.getValue());
	UPLoginRecordID idUser(_loginField.UserID.getValue());
	if (idParticipant.empty() || idUser.empty())
	{
		printf("CUserLoginField With Empty UserID or ParticipantID\n");
	}

	// ��ȡ���û��ĵ�¼��¼
	UPLoginRecord* pParticipantRecord = UPLoginRecord::fetchRecord(idParticipant, Participant);
	// ��ȡ��ϯλ�ĵ�¼��¼
	UPLoginRecord* pUserRecord = UPLoginRecord::fetchRecord(idUser, User);

	// �û���¼ʱ������ˮ�е�ʱ��Ϊ׼
	time_t tLoginTime = convertToTime(_loginField.ActionDay, _loginField.LoginTime);
	if (tLoginTime == -1) tLoginTime = tNow;	// ���ʱ��ת����������ʹ�ñ���ʱ�����

	// ��¼ʱ��ֵ
	pParticipantRecord->record(tLoginTime, _frontID);
	pUserRecord->record(tLoginTime, _frontID);

	// �������еĸ澯������󣬼��㵱ǰ��¼��Ϣ�Ƿ���ϸ澯��ֵ
	for (vector<LoginWarningCalculate*>::iterator itObject = m_AllCalculate.begin();
		itObject != m_AllCalculate.end(); ++itObject)
	{
		LoginWarningCalculate* pWarningCalculate = *itObject;

		// �жϸø澯�Ƿ��ϯλ��Ч
		if (pWarningCalculate->m_UserEnable)
		{
			pWarningCalculate->HandleRecord(pUserRecord, tLoginTime, tNow);
		}
		// �жϸø澯�Ƿ���û���Ч
		if (pWarningCalculate->m_ParticipantEnable)
		{
			pWarningCalculate->HandleRecord(pParticipantRecord, tLoginTime, tNow);
		}
	}
}

//���ӵ�eventcounter
extern list<CFTDCSession *> sessionList;
void LoginWarningCalculate::HandleRecord(UPLoginRecord* _Record, time_t _BasisTime, time_t _LocalTime)
{
	// ��ȡ�û�������м�״̬
	RecordState& PState = getRecordState(_Record->getRecordID());
	// ֻ�д���Ӧ���澯��ʱ���֮�ڣ��Ž��м���
	if (_LocalTime - PState.LastWarningTime >= m_WarningGap)
	{
		// ��ȡ��¼�У��Ի�׼ʱ��Ϊ��㣬��ǰm_Interval���ڵĵ�¼����
		int nLoginCount = _Record->loginCount(_BasisTime, m_Interval);
		// ��¼����������ֵ���澯
		if (nLoginCount >= m_Threshold)
		{
			// ��д������
			struct tm tm_Now;
			LocalTime(&_LocalTime, &tm_Now);
			strftime((char*)m_SyslogEventField.MonTime.getValue(), 10, "%H:%M:%S", &tm_Now);
			strftime((char*)m_SyslogEventField.MonDate.getValue(), 10, "%Y%m%d", &tm_Now);

			m_SyslogEventField.OccurDate = m_SyslogEventField.MonDate.getValue();
			m_SyslogEventField.OccurTime = m_SyslogEventField.MonTime.getValue();

			m_SyslogEventField.EventName = m_EventName.c_str();

			// �����澯����
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
			// �������ݰ�
			m_pkgSend.PreparePackage(FTD_TID_RtnSyslogEventTopic,
				FTDC_CHAIN_LAST, FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &m_SyslogEventField);
			for (list < CFTDCSession * >::iterator itEventSession = sessionList.begin();
				itEventSession != sessionList.end(); itEventSession++)
			{
				(*itEventSession)->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
			}

			// ����״̬ʱ��
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

