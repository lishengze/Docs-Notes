/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	EventCounterServer.cpp
///@brief	ʵ�����¼���������������ɼ��������Ӵ������
///@history
///20080510	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20111011	�̺״�	NM-0134	�����������ֲ��ּ�����ݲ�����BUG����������ֵ����ʱ���ж�
#include <cctype>
#include "EventCounterServer.h"
#include "CExprAnalysis.h"
#include "databaseData.h"
#include "CRegexConfig.h"
#include "PrjCommon.h"
#include "inputStream.h"
#include "CExprNode.h"
#include "inputToken.h"
#include "CExprParser.h"
#include "md5Handler.h"
#include "CMsgGenerator.h"
#include "CCalendar.h"
#include <boost/regex.hpp>

using namespace boost;

#ifdef LINUX
#include <dirent.h>
#endif

////Added by Henchi, 20121211
////�Ƿ���Query���Ͷ���ָ��ԭʼ�����ɺ����

//#define OBJATTR_TO_ORACLE
#define CLEARMEMDB(x)														 \
{																		 \
	C##x *sfield = pMemoryDB->m_##x##Factory->startFindBytheAll();		 \
	while (sfield)														 \
{																	 \
	C##x *tfield = pMemoryDB->m_##x##Factory->findNextBytheAll();	 \
	if (sfield->MonDate < beginDate									 \
	||	(sfield->MonDate == beginDate && sfield->MonTime < theTime)) \
{																 \
	pMemoryDB->m_##x##Factory->remove(sfield);					 \
}																 \
	\
	sfield = tfield;												 \
}																	 \
}

enum TASK_STATUS
{
	//����ִ�н��
	TASK_SUCCESS								= 0,	//ָ��ִ�гɹ�
	TASK_CONNECT_FAIL,			//����������ʧ��
	TASK_USERNAME_ERROR,		//�û�������
	TASK_USERPASSWD_ERROR,		//�û��������
	TASK_USERCOMMAND_FAIL,		//�û�����ִ��ʧ��
	TASK_ADMINPASSWD_ERROR,		//����Ա�������
	TASK_ADMINCOMMAND_ERROR,	//����Ա����ִ��ʧ��
	TASK_OTHER_ERROR,			//��������

	//�����ļ����ݽ��
	TASK_CFGBACKUP_SUCCESS,		//���ñ��ݳɹ�
	TASK_CFGBACKUP_FAIL,		//���ñ���ʧ��

	//�����ļ��ȶԽ��
	TASK_CONFIG_MATCH,			//�����ļ��ȶ�һ��
	TASK_CONFIG_DISMATCH,		//�����ļ��ȶԲ�һ��

	//�������쳣
	TASK_RESULT_ERROR							= 12,

	//����״̬֪ͨ����manager����
	TASK_WAIT_EXEC								= 21,	//����״̬:�ȴ�ִ��
	TASK_CANCEL_EXEC,						//����״̬:ȡ��ִ��
	TASK_DOING_EXEC,						//����״̬:����ִ��
	TASK_DONE_EXEC,							//����״̬:���ִ��

	//����״̬�ı䣬�ɿͻ��˷���
	TASK_STOP_EXEC,							//��ֹ����
	TASK_DELAY_EXEC,						//�Ƴ�����
	TASK_PAUSE_EXEC,						//ȡ������:��ִͣ��	
	TASK_ACTIVATE_EXEC,						//��������:�ָ�ִ��

	//����״̬�ı���
	TASK_STATUS_CHANGE_SUCCESS,				//״̬�ı�ɹ�
	TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND, //���񲻴���
	TASK_STATUS_CHANGE_FAIL_TASK_STATUS_ERROR,		//����״̬����
};

// ��Ҫ���ⲿȫ�ֱ���
extern CDataCenter	*g_pDataCenter;
extern CExprAnalysis *g_mExprAnalysis;

// �漰��������ʽ�̵߳�ȫ�ֱ���
CEventProcess g_cEventProcess;						///ȫ�ָ澯���´������
extern CListWarningEventField *g_pListEvent;		// ��������δд�뵽���ĸ澯�¼�
extern map<string, string>	g_mapEventLevel;
extern map<string, string>	g_mapEventFullName;
extern map<string, string>	g_mapEventDesc;

extern char g_mHostFilterStr[100];					//������Ҫ���˵Ķ���ID�ִ��������config������cpuusage��memusage����'.config_'
extern int	g_mConfigControlEvent;

extern map<string, CObjectAttrKey>	g_mapEventDelayTime;

extern CExprParser<CValue>	g_mEventParser;
extern CContext *g_pContext;
extern const char *INI_FILE_NAME;

CContext *g_pTaskContext = NULL;
extern CEventCounterServer	*g_counterServer;

extern CMsgGenerator g_MsgGenerator;

extern vector<string> g_mNoTradingDays;
extern map<string, int> g_mNoNightTradingDays;  //û��ҹ�̵Ľ����� 

int g_nTradingSectionStatFlag;

//��ص������ļ����б�key:objectid
map<string, vector<ConfigFileInfo> > g_mapConfigFileList;

CWarningEventManager g_warningEventManager;

extern string g_chglevelfilename;

int CEventCounterServer:: m_mTradeDay = 0;			// ��ǰ�Ľ�����

//key:objectid, value:eventname
map<string, map<string, int> >	g_eventID2NameList;

//key:eventnum, value:warningeventlist
map<int, list<CFTDRtnWarningEventField> > g_listWarningEvent;

//����״̬��Ϣ��key:devicename.portname
map<string, LinkStatusInfo> g_mapLinkStatusInfo;

map<int, int> g_mapEventNumLevel;

//�¼��ĵ�ǰ������
map<int, string> g_mapEventProcessFlag;

CCalendar g_calender;	//���������	

// add by cao.ning
// ϵͳ�ڲ���������
extern CSysInternalTopology* g_SysInternalTopology;

#ifdef PACKAGE_OUTPUT
extern CLogger	*g_pPackOutput;						// ���ݰ�������ļ�
#endif
#undef SESSIONLOG_TOFILE_DEBUG
#define MESSAGEPUSHFLOW				pFTDCPackage->Push(FTDCHLEN); \
	m_cFrontServer.m_pCurrFrontFlow->Append(					  \
	pFTDCPackage->Address(),							  \
	pFTDCPackage->Length());

#define MESSAGEPUSHQUERYFLOW		pFTDCPackage->Push(FTDCHLEN); \
	m_cFrontServer.m_pCurrOracleFlow->Append(					  \
	pFTDCPackage->Address(),							  \
	pFTDCPackage->Length());

#define MESSAGEPUSHSLOGFLOW		pFTDCPackage->Push(FTDCHLEN); \
	m_cFrontServer.m_pCurrSlogFlow->Append(					  \
	pFTDCPackage->Address(),							  \
	pFTDCPackage->Length());

#define MESSAGEPUSHFRONTQUERYFLOW	pFTDCPackage->Push(FTDCHLEN); \
	m_cFrontServer.m_pCurrFrontFlow->Append(					  \
	pFTDCPackage->Address(),							  \
	pFTDCPackage->Length());							  \
	m_cFrontServer.m_pCurrOracleFlow->Append(					  \
	pFTDCPackage->Address(),							  \
	pFTDCPackage->Length());

#define MESSAGEPUSHFLOWCHGK			pFTDCPackage->Push(FTDCHLEN); \
	m_cFrontServer.m_pCurrOracleFlow->Append(					  \
	pFTDCPackage->Address(),							  \
	pFTDCPackage->Length());							  \
	pFTDCPackage->Pop(FTDCHLEN);

inline void CheckObjectIDFileName(
	const char *objid,
	const char	*NewName,
	string	&lastFileName,
	string	&currFileName)
{
	if ( strncmp(NewName, objid, strlen( objid ) )==0 
		&& ( strlen(NewName)-strlen(objid) >= 20 ) )  // objid_20130224_051000.txt,objid_20130224_051000(0).txt 
	{
		if (lastFileName.compare(NewName) < 0
			&&	currFileName.compare(NewName) > 0)
		{
			lastFileName = NewName;
		}
	}
}

CEventTimmer::CEventTimmer(
	CReactor *pReactor,
	CEventCounterServer *pEventCounterServer) :
CEventHandler(pReactor)
{
	m_pEventCounterServer = pEventCounterServer;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_nLastChangeTime = time((time_t *)NULL);
	m_nInterval = 3600 * 3;
}

void CEventTimmer::OnTimer(int nIDEvent)
{
	//κ��modified, 20120327
	g_pListEvent->ReadValue(m_pEventCounterServer);

	m_pEventCounterServer->m_pThreadMdber->m_mStatusStat.m_cListTradePeak.
		ReadValue(
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow,
		m_pEventCounterServer->m_cFrontServer.m_pCurrOracleFlow);
	m_pEventCounterServer->m_pThreadMdber->m_mStatusStat.
		m_cListHistoryObjectAttr.ReadValue(
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow,
		m_pEventCounterServer->m_cFrontServer.m_pCurrOracleFlow);
	m_pEventCounterServer->m_center.clear();

	if (nIDEvent == 1)
	{
		//
		time_t	nNow = time((time_t *)NULL);
		if (nNow - m_nLastChangeTime >= 3 * 3600)	//��Ҫ�л�
		{
			m_nLastChangeTime = nNow;

			m_pEventCounterServer->m_cFrontServer.m_nFlowPosition = (m_pEventCounterServer->m_cFrontServer.m_nFlowPosition + 1) % MAX_EVENTFLOWNUM;

			printf(
				"OnTimer::now %d �滻���µ������ %u \n",
				(int)nNow,
				m_pEventCounterServer->m_cFrontServer.m_nFlowPosition);
			fflush(stdout);

			// ������ͬʱҪ����������
			m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow = 
				m_pEventCounterServer->m_cFrontServer.m_pFrontFlowArray[
				m_pEventCounterServer->m_cFrontServer.m_nFlowPosition];
			m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Truncate(0);
			
			// ������ͬʱҪ����������
			m_pEventCounterServer->m_cFrontServer.m_pCurrOracleFlow =
				m_pEventCounterServer->m_cFrontServer.m_pOracleFlowArray[
				m_pEventCounterServer->m_cFrontServer.m_nFlowPosition];
			m_pEventCounterServer->m_cFrontServer.m_pCurrOracleFlow->Truncate(0);
			
			// ������ͬʱҪ����������
			m_pEventCounterServer->m_cFrontServer.m_pCurrSlogFlow =
				m_pEventCounterServer->m_cFrontServer.m_pSlogFlowArray[
				m_pEventCounterServer->m_cFrontServer.m_nFlowPosition];
			m_pEventCounterServer->m_cFrontServer.m_pCurrSlogFlow->Truncate(0);
			
			// ������Ϣ�������������ӣ�֪ͨ�������¿�ʼ��ȡ
			CFTDReqQryTradeDayChangeField fieldChange;
			memset(&fieldChange, 0, sizeof(CFTDReqQryTradeDayChangeField));
			
			fieldChange.ChangeType = TRUNCATEFLOW;
			fieldChange.OldDate = m_pEventCounterServer->m_cFrontServer.m_nFlowPosition;
			fieldChange.NewDate = m_pEventCounterServer->m_cFrontServer.m_nFlowPosition;
			
			m_pkgSend.PreparePackage(FTD_TID_ReqQryTradeDayChangeTopic,FTDC_CHAIN_LAST,FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldChange);
			
			m_pEventCounterServer->m_cFrontServer.SendPackageAllSession(
			&m_pkgSend);
		}

		/*
		// �ж��Ƿ�ô����������л�����
		struct tm *p = localtime(&nNow);
		if (((1900+p->tm_year)*10000+(1+p->tm_mon)*100+p->tm_mday) > m_pEventCounterServer->m_mTradeDay) // �����������л�
		{
		// ������Ϣ���������ӵ�Session
		m_pkgSend.PreparePackage(FTD_TID_ReqQryTradeDayChangeTopic, FTDC_CHAIN_LAST, FTD_VERSION);

		CFTDReqQryTradeDayChangeField fieldChange;
		fieldChange.ChangeType = CHANGETRADEDAY;
		sprintf((char *)fieldChange.OldDate.getValue(),"%8d",m_pEventCounterServer->m_mTradeDay);
		printf("OnTimer old g_mTradeDay [%d]\n",m_pEventCounterServer->m_mTradeDay);
		m_pEventCounterServer->m_mTradeDay = (1900+p->tm_year)*10000+(1+p->tm_mon)*100+p->tm_mday;
		printf("OnTimer new g_mTradeDay [%d]\n",m_pEventCounterServer->m_mTradeDay);
		fflush(stdout);
		sprintf((char *)fieldChange.NewDate.getValue(),"%8d",m_pEventCounterServer->m_mTradeDay);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldChange);

		// ���͵�ǰ�á���ѯ������
		m_pEventCounterServer->m_cFrontServer.SendPackageAllSession(&m_pkgSend);
		// ���͵����ӵĲɼ�����sysfibclient��
		m_pEventCounterServer->SendPackageAllSession(&m_pkgSend);

		//�л������պ���־�¼���̽�롢�ɼ���������ĸ澯�¼�������¿�ʼ
		//m_mSyslogEventId = 1 ;
		//g_mEventId = 1 ;
		}
		// �������л���������
		*/
	}
	else if (nIDEvent == 2)
	{
		g_warningEventManager.onTimer();

		//���¼���regex�����ļ�
		CRegexConfigManager::Instance()->ReloadConfig();

		//���¼���ip�б�
		m_pEventCounterServer->loadXmlConfig();
	}

	//���͸澯�¼���config
	if (g_mExprAnalysis)
	{
		CFTDRtnWarningEventField warningevent;
		while (g_mExprAnalysis->GetWarningEvent(warningevent))
		{
			if (m_pEventCounterServer->m_cConfigConnector.GetSession())
			{
				m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

				FTDC_ADD_FIELD(&m_pkgSend, &warningevent);

				m_pEventCounterServer->m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
			}
			else
			{
				printf("config session NULL, send warningevent fail!\n");
			}
		}
	}
	else
	{
		printf("g_mExprAnalysis NULL\n");
	}

	//���͸澯update�¼���config
	CFTDReqQryWarningEventUpdateField warningeventupdate;
	while
		(
		m_pEventCounterServer->m_cFrontServer.GetWarningEvent(
		warningeventupdate)
		)
	{
		if (m_pEventCounterServer->m_cConfigConnector.GetSession())
		{
			m_pkgSend.PreparePackage(
				FTD_TID_ReqQryWarningEventUpdateTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

			FTDC_ADD_FIELD(&m_pkgSend, &warningeventupdate);

			m_pEventCounterServer->m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			printf("config session NULL, send warningeventupdate fail!\n");
		}
	}

	//���͸澯active change�¼���config
	CFTDReqQryWarningActiveChangeField	warningeventactivechange;
	while
		(
		m_pEventCounterServer->m_cFrontServer.GetWarningEventActiveChange(
		warningeventactivechange)
		)
	{
		if (m_pEventCounterServer->m_cConfigConnector.GetSession())
		{
			m_pkgSend.PreparePackage(
				FTD_TID_ReqQryWarningActiveChange,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

			FTDC_ADD_FIELD(&m_pkgSend, &warningeventactivechange);

			m_pEventCounterServer->m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			printf(
				"config session NULL, send warningeventactivechange fail!\n");
		}
	}

	//���͸澯���ص�config
	CFTDReqQryNetRoomField	reqnetroom;
	while (m_pEventCounterServer->m_cFrontServer.GetReqNetRoom(reqnetroom))
	{
		if (m_pEventCounterServer->m_cConfigConnector.GetSession())
		{
			m_pkgSend.PreparePackage(
				FTD_TID_ReqQryNetRoomTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

			FTDC_ADD_FIELD(&m_pkgSend, &reqnetroom);

			m_pEventCounterServer->m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			printf("config session NULL, send netroom fail!\n");
		}
	}

	//���͸澯��front
	CFTDRtnWarningEventField warningevent;
	while(m_pEventCounterServer->m_cConfigConnector.GetWarningEvent(warningevent))
	{
		//���»�Ա��·״̬
		m_pEventCounterServer->UpdateLinkStatusByWarningEvent(warningevent);

		string	delay_key = warningevent.ObjectID.getValue();
		delay_key += ";;";
		delay_key += warningevent.EventName.getValue();

		map<string, CObjectAttrKey>::iterator map_it = g_mapEventDelayTime.find(
			delay_key);
		if (map_it != g_mapEventDelayTime.end())
		{
			///�����ǰ�¼�������ʱ����ӳٵ�����ʱ�����ɾ��map�еĸýڵ�
			if (strcmp(
				warningevent.MonDate.getValue(),
				map_it->second.m_nObjectID.c_str()) > 0
				||	(
				strcmp(
				warningevent.MonDate.getValue(),
				map_it->second.m_nObjectID.c_str()) == 0 && strcmp(
				warningevent.MonTime.getValue(),
				map_it->second.m_nAttrID.c_str()) > 0
				))
			{
				g_mapEventDelayTime.erase(map_it);
			}
			else	///��ǰ�¼�������ʱ�����ӳٵ�����ʱ�䷶Χ�ڣ��Զ�����ø澯�����ñ��ΪY
			{
				if(warningevent.ProcessFlag == "=" 
					&& map_it->second.m_sProcessFlag.compare("Y") == 0)
				{
					//�¼���ԭ����
					g_mapEventDelayTime.erase(map_it);
				}
				else
				{
					warningevent.ProcessFlag = map_it->second.m_sProcessFlag.c_str();
					warningevent.EventDealDes = map_it->second.m_sEventDes.c_str();
				}
			}
		}

		//���¸澯����
		m_pEventCounterServer->UpdateWarningCount(warningevent);

		if(warningevent.ProcessFlag == "N")
		{
			//send mms
			string	membername;
			m_pEventCounterServer->m_cConfigConnector.GetPartyLinkMemberName(
				warningevent,
				membername);

			string	devname;
			m_pEventCounterServer->m_cConfigConnector.GetDeviceName(
				warningevent.ObjectID.getValue(),
				devname);

			int warningcount = m_pEventCounterServer->GetWarningCount(warningevent);

			g_MsgGenerator.AddEvent(
				warningevent,
				warningcount,
				(char *)devname.c_str(),
				(char *)membername.c_str());
		}

		m_pkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &warningevent);

		m_pkgSend.MakePackage();
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
		m_pEventCounterServer->m_cFrontServer.m_pCurrOracleFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
	}

	//���͸澯active change��front
	CFTDRtnWarningActiveChangeField warningeventac;
	while
		(
		m_pEventCounterServer->m_cConfigConnector.
		GetWarningEventActiveChange(warningeventac)
		)
	{
		m_pkgSend.PreparePackage(
			FTD_TID_RtnWarningActiveChange,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &warningeventac);
		m_pkgSend.MakePackage();
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
	}

	//���͸澯���ص�front
	CFTDRtnNetRoomField netroom;
	while (m_pEventCounterServer->m_cConfigConnector.GetRtnNetRoom(netroom))
	{
		m_pkgSend.PreparePackage(
			FTD_TID_RtnNetRoomTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &netroom);
		m_pkgSend.MakePackage();
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
	}

	//����syslog��front
	CFTDRtnSyslogEventField syslogevent;
	while
		(
		m_pEventCounterServer->m_cConfigConnector.GetSyslogEvent(
		syslogevent)
		)
	{
		//ϯλ��·����
		m_pEventCounterServer->SeatLinkAnalysis(syslogevent);

		//���»�Ա��·״̬
		m_pEventCounterServer->UpdateLinkStatusBySyslogEvent(syslogevent);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnSyslogEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &syslogevent);
		m_pkgSend.MakePackage();
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
		m_pEventCounterServer->m_cFrontServer.m_pCurrOracleFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
	}

	//������·״̬��Ϣ��front��query
	CFTDRtnNetPartyLinkStatusInfoField	statusinfo;
	while
		(
		m_pEventCounterServer->m_cConfigConnector.GetPartyLinkStatusInfo(
		statusinfo)
		)
	{
		m_pkgSend.PreparePackage(
			FTD_TID_RtnNetPartyLinkStatusInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &statusinfo);
		m_pkgSend.MakePackage();
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
		m_pEventCounterServer->m_cFrontServer.m_pCurrOracleFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
	}

	//���������ض�������front
	CFTDRtnNetAreaField netmonitorobjecttree;
	m_pkgSend.PreparePackage(
		FTD_TID_RtnNetAreaTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	while
		(
		m_pEventCounterServer->m_cConfigConnector.GetNetMonitorObjectTree(
		netmonitorobjecttree)
		)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnNetAreaField) > FTDC_PACKAGE_MAX_SIZE)
		{
			m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
			m_pkgSend.MakePackage();
			m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Append(
				m_pkgSend.Address(),
				m_pkgSend.Length());

			m_pkgSend.PreparePackage(
				FTD_TID_RtnNetAreaTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &netmonitorobjecttree);
	}

	if (m_pkgSend.Length() >= sizeof(CFTDRtnNetAreaField))
	{
		m_pkgSend.MakePackage();
		m_pEventCounterServer->m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
	}

	return;
}

void CWarningEventManager::add_warning_event(
	CFTDRtnWarningEventField &eventfield)
{
	m_lockData.Lock();

	string	key = eventfield.ObjectID.getValue();
	key += ";;";
	key += eventfield.EventName.getValue();

	map<string, map<int, CFTDRtnWarningEventField> >::iterator	f_it =
		warning_event_list.find(key);
	if (f_it != warning_event_list.end())
	{
		f_it->second[eventfield.EvendID.getValue()] = eventfield;
	}
	else
	{
		map<int, CFTDRtnWarningEventField>	f_map;
		f_map[eventfield.EvendID.getValue()] = eventfield;
		warning_event_list[key] = f_map;
	}

	m_lockData.UnLock();
}

vector<CFTDRtnWarningEventField> CWarningEventManager::fuzzy_get_warning_event(
	string	objectid,
	string	eventname,
	bool erasemark)
{
	m_lockData.Lock();

	vector<CFTDRtnWarningEventField> result;

	string	key = objectid;
	key += ";;";
	key += eventname;

	map<string, map<int, CFTDRtnWarningEventField> >::iterator	f_it =
		warning_event_list.find(key);
	if (f_it != warning_event_list.end())
	{
		map<int, CFTDRtnWarningEventField>::iterator s_i = f_it->second.begin();
		for (; s_i != f_it->second.end(); ++s_i)
		{
			result.push_back(s_i->second);
		}

		if (erasemark)
		{
			//�Ѿ�����ɾ�����¼�		
			f_it->second.clear();
			warning_event_list.erase(f_it);
		}
	}

	m_lockData.UnLock();

	return result;
}

vector<CFTDRtnWarningEventField> CWarningEventManager::exact_get_warning_event(
	string	objectid,
	string	eventname,
	int eventid,
	bool erasemark)
{
	m_lockData.Lock();

	vector<CFTDRtnWarningEventField> result;

	string	key = objectid;
	key += ";;";
	key += eventname;

	map<string, map<int, CFTDRtnWarningEventField> >::iterator	f_it =
		warning_event_list.find(key);
	if (f_it != warning_event_list.end())
	{
		map<int, CFTDRtnWarningEventField>::iterator s_it = f_it->second.find(
			eventid);
		if (s_it != f_it->second.end())
		{
			result.push_back(s_it->second);

			if (erasemark)
			{
				//�Ѿ�����ɾ�����¼�
				f_it->second.erase(s_it);
			}
		}
	}

	m_lockData.UnLock();

	return result;
}

//����һ���յ���ԭʼ�¼�
void CWarningEventManager::add_raw_warning_event(
	CFTDRtnWarningEventField &eventfield)
{
	string	key = eventfield.ObjectID.getValue();
	key += ";;";
	key += eventfield.EventName.getValue();
	key += ";;";
	key += eventfield.OccurDate.getValue();
	key += ";;";
	key += eventfield.OccurTime.getValue();

	raw_warning_event_list[key] = 1;

	raw_warning_event_queue.push(key);
}

void CWarningEventManager::add_raw_syslog_event(
	CFTDRtnSyslogEventField &syslogfield)
{
	string	key = syslogfield.ObjectID.getValue();
	key += ";;";
	key += syslogfield.EventName.getValue();
	key += ";;";
	key += syslogfield.OccurDate.getValue();
	key += ";;";
	key += syslogfield.OccurTime.getValue();

	map<string, vector<string> >::iterator	f_it = raw_syslog_event_list.find(
		key);
	if (f_it != raw_syslog_event_list.end())
	{
		f_it->second.push_back(syslogfield.EventDes.getValue());

		raw_syslog_event_queue.push(key);
	}
	else
	{
		vector<string>	f_vec;
		f_vec.push_back(syslogfield.EventDes.getValue());
		raw_syslog_event_list[key] = f_vec;

		raw_syslog_event_queue.push(key);
	}
}

//������ڵ�raw_event
void CWarningEventManager::onTimer(void)
{
	int max_list_size = 100000;

	if (raw_warning_event_list.size() > max_list_size)
	{
		int count = raw_warning_event_list.size() - max_list_size;
		for (int i = 0; i < count; ++i)
		{
			string	key = raw_warning_event_queue.front();
			map<string, int>::iterator	it = raw_warning_event_list.find(key);
			if (it != raw_warning_event_list.end())
			{
				raw_warning_event_list.erase(it);
			}

			raw_warning_event_queue.pop();
		}
	}

	if (raw_syslog_event_list.size() > max_list_size)
	{
		int count = raw_syslog_event_list.size() - max_list_size;
		for (int i = 0; i < count; ++i)
		{
			string	key = raw_syslog_event_queue.front();
			map<string, vector<string> >::iterator	it = raw_syslog_event_list.
				find(key);
			if (it != raw_syslog_event_list.end())
			{
				it->second.clear();
				raw_syslog_event_list.erase(it);
			}

			raw_syslog_event_queue.pop();
		}
	}
}

//�ж��Ƿ��ظ�����
bool CWarningEventManager::is_duplicate_warning_event(
	CFTDRtnWarningEventField &eventfield)
{
	string	key = eventfield.ObjectID.getValue();
	key += ";;";
	key += eventfield.EventName.getValue();
	key += ";;";
	key += eventfield.OccurDate.getValue();
	key += ";;";
	key += eventfield.OccurTime.getValue();

	map<string, int>::iterator	it = raw_warning_event_list.find(key);
	if (it != raw_warning_event_list.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CWarningEventManager::is_duplicate_syslog_event(
	CFTDRtnSyslogEventField &syslogfield)
{
	string	key = syslogfield.ObjectID.getValue();
	key += ";;";
	key += syslogfield.EventName.getValue();
	key += ";;";
	key += syslogfield.OccurDate.getValue();
	key += ";;";
	key += syslogfield.OccurTime.getValue();

	map<string, vector<string> >::iterator	it = raw_syslog_event_list.find(
		key);
	if (it != raw_syslog_event_list.end())
	{
		//�鿴EventDes�Ƿ�һ��
		for (int i = 0; i < it->second.size(); ++i)
		{
			if (strcmp(
				syslogfield.EventDes.getValue(),
				it->second[i].c_str()) == 0)
			{
				return true;
			}
		}

		return false;
	}
	else
	{
		return false;
	}
}

//
// ����ɼ��������ʵ��

//
CEventCounterServer::CEventCounterServer(
	CReactor *pReactor,
	char *pSaveFile,
	char *pEventCfgPath,
	char *pXmlFileName,
	char *pFlowPath) :
CAgentSessionFactory(pReactor, 100),
	m_eventTimer(pReactor, this),
	m_threadFiler(pSaveFile, 100),
	m_cProbeServer(pReactor),
	m_cFrontServer(pReactor, &m_mSyslogEventId, pFlowPath),
	m_cConfigConnector(pReactor)
	//	m_PerHourMessagethread(this)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pkgPbeSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pSaveFile = pSaveFile;
	m_eventTimer.SetTimer(1, 1000);

	m_eventTimer.SetTimer(2, 60 * 1000);	// 1����

	//m_eventTimer.SetTimer(3, 20*1000);	// 20��
	m_mapApp[string(APPATTRCPUUSAGE)] = 1;
	m_mapApp[string(APPATTRMEMORYUSAGE)] = 1;

	/// ��������ļ��Ա�ʱ���Ե��ִ���Ϣ
	m_oFileDiff.AddRegExp("Current configuration : * *");		
	m_oFileDiff.AddRegExp("ntp clock-period *");

	//m_mapApp[string(APPATTRCURRENTTIME)] = 1;
	//m_mapApp[string(APPATTRORDERSIZE)] = 1;
	//m_mapApp[string(APPATTRTRADESIZE)] = 1;
	//m_mapApp[string(APPATTRUSERSESSIONSIZE)] = 1;
	//m_mapApp[string(APPATTRTOTALVOLUME)] = 1;
	//m_mapApp[string(APPATTRTOTALAMOUNT)] = 1;
	//m_mapApp[string(APPATTRHANDLEORDERACTIONTOTAL)] = 1;
	CXMLDoc *pXMLDoc = NULL;
	CXMLNode *pXMLRoot = NULL;
	XMLNodeType NodeType = XMLTag;

	map<string, T_strmap>::iterator clomnIt;
	if (pXMLDoc == NULL)
	{
		pXMLDoc = new CXMLDoc();
		try
		{
			pXMLDoc->read(pEventCfgPath);
			pXMLRoot = pXMLDoc->getRootNode();

			/* To be written on exit */
			CXMLNode *pServiceNode = pXMLRoot->findNode(
				NodeType,
				"MultiColumnToEvents",
				NULL,
				NULL);
			if (pServiceNode != NULL)
			{
				CXMLNodeList *pNodeList = pServiceNode->getNodeList();
				for (int i = 0; i < (int)pNodeList->size(); i++)
				{
					CXMLNode *pNodeCur = (*pNodeList)[i];
					clomnIt = m_mapRtnDBQueryClomn.find(
						pNodeCur->findProperty("name"));
					if (clomnIt != m_mapRtnDBQueryClomn.end())
					{
						clomnIt->second.insert(
							make_pair(
							pNodeCur->findProperty("KeyType"),
							pNodeCur->findProperty("Attend")));
					}
					else
					{
						map<string, string> mapOb;
						mapOb[pNodeCur->findProperty(
							"KeyType")] = pNodeCur->findProperty("Attend");
						m_mapRtnDBQueryClomn[pNodeCur->findProperty(
							"name")] = mapOb;
					}

					//printf("\t%s ",pNodeCur->findProperty("name"));
					//printf("\t%s ",pNodeCur->findProperty("KeyType"));
					//printf("\t%s \n",pNodeCur->findProperty("Attend"));
				}

				printf(
					"CEventCounterServer::CEventCounterServer ���������Ķ�̬��ת��Ϊ�¼����ж���: \n");
				for (clomnIt = m_mapRtnDBQueryClomn.begin();
					clomnIt != m_mapRtnDBQueryClomn.end();
					clomnIt++)
				{
					printf("\t������: %s\n", clomnIt->first.c_str());
					for (map<string, string>::iterator valueIt = clomnIt->
						second.begin();
						valueIt != clomnIt->second.end();
					valueIt++)
					{
						printf(
							"\t\t%s\t%s\n",
							valueIt->first.c_str(),
							valueIt->second.c_str());
					}
				}
			}
		}
		catch(CParseError * e)
		{
			delete e;
			delete pXMLDoc;
			pXMLDoc = NULL;
			printf(
				"\tCEventCounterServer::CEventCounterServer XML Event File %s explain failed\n",
				pEventCfgPath);
			fflush(stdout);
			exit(0);
		}

		m_sXMLFileName = pXmlFileName;

		g_nTradingSectionStatFlag = 0;
		loadXmlConfig();
		g_calender.Init();	// ���ݽ�������Ϣ��ʼ����������
	}

	initBuffer();
	m_pThreadMdber = new CMdbThread(
		m_pNodeBuffer,
		m_pEventBuffer,
		pEventCfgPath);
	m_pThreadMdber->Create();
	m_threadFiler.Create();

	// �����ã������ע�͵�CPerHourMessage����
	//if (g_MsgGenerator.EnablePerHourMsg())
	//{
	//	m_PerHourMessagethread.Create();
	//}

	SetOutputPath(TMP_DIRNAME);

	//���ر����ļ��嵥
	LoadConfigFileList();

	g_pTaskContext = new CContext((char *)INI_FILE_NAME);

	//================test code================
#if 0
	//IsTradingDay
	test_trading("IsTradingDay()");
	test_trading("IsContinuousDay()");

	//IsTradingPeriod
	test_trading("IsTradingPeriod(\"20140210 10:03:45\")");
	test_trading("IsTradingPeriod()");

	//IsDayTradingPeriod
	test_trading("IsDayTradingPeriod(1234567890)");

	//IsNightTradingPeriod
	test_trading("IsNightTradingPeriod(\"20141008 21:35:46\")");	
	test_trading("HasNightTradingPeriod(\"20141008\")");	
#endif
}

CSession *CEventCounterServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);
	return pSession;
}


// @@ Agent & Manager �Ự����
void CEventCounterServer::OnSessionConnected(CSession *pSession)
{
	CAgentSessionFactory::OnSessionConnected(pSession);

	//printf("%s %s", pSession->GetChannel()->GetRemoteCommonName(),pSession->GetChannel()->GetRemoteName());
	// Added by Henchi, 20100108
	/// ���ͽ�������Ϣ���ɼ�����̽��
	m_pkgSend.PreparePackage(
		FTD_TID_ReqQryTradeDayChangeTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	CFTDReqQryTradeDayChangeField fieldChange;
	fieldChange.ChangeType = CHANGETRADEDAY;
	printf(
		"OnSessionConnected TradeDay [%d] session [%0x]\n",
		m_mTradeDay,
		(CFTDCSession *)pSession);

	sprintf((char *)fieldChange.OldDate.getValue(), "%8d", m_mTradeDay);
	sprintf((char *)fieldChange.NewDate.getValue(), "%8d", m_mTradeDay);
	FTDC_ADD_FIELD(&m_pkgSend, &fieldChange);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);

	time_t	timep;
	time(&timep);
	printf(
		"\t%s CEventCounterServer::OnSessionConnected: %0x Connected, CommonName [%s] RemoteName [%s] ==\n",
		ctime(&timep),
		(CFTDCSession *)pSession,
		pSession->GetChannel()->GetRemoteCommonName(),
		pSession->GetChannel()->GetRemoteName());
	fflush(stdout);

	// add by cao.ning
	// ��ȡ�²��ϵͳ�ڲ����ӹ�ϵ��Ϣ
	if (g_SysInternalTopology)
	{
		g_SysInternalTopology->OnSessionConnected(pSession);
	}

	//CEventSubscriber * pSubscriber = g_mapSubscriber[(CFTDCSession *)pSession];
	//if(pSubscriber!=NULL)
	//{
	//	delete pSubscriber;
	//}
}

void CEventCounterServer::OnSessionDisconnected(CSession *pSession, int nReason)	// �������ش������ӶϿ��¼�
{
	time_t	timep;
	time(&timep);
	printf(
		"\t%s CEventCounterServer::OnSessionDisconnected: %0x\n",
		ctime(&timep),
		(CFTDCSession *)pSession);
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// ������ø��ദ�����ӶϿ��¼�
	m_cFrontServer.m_mObjectIdSession.delSession((CFTDCSession *)pSession);

	// add by cao.ning
	// ���²�ڵ��ֱ����·�Ͽ�
	// ɾ���ûỰ��Ӧ����·
	if (g_SysInternalTopology)
	{
		g_SysInternalTopology->OnSessionDisconnected(pSession);
	}
}

void CEventCounterServer::OnRtnWarningEventTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnWarningEventField fieldInfo;
	int nEventSeries;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		if (fieldInfo.EventName == "LINK_UPDOWN"
			||	fieldInfo.EventName == "LINK_SP_UPDOWN"
			||	fieldInfo.EventName == "LINEPROTO_UPDOWN"
			||	fieldInfo.EventName == "LINEPROTO_SP_UPDOWN")
		{
			//�����¼�����
			string	modifylevel = modifyWarningEventLevel(
				fieldInfo.IPAddress.getValue(),
				fieldInfo.WarningLevel.getValue());
			fieldInfo.WarningLevel = modifylevel.c_str();
		}

		if (g_warningEventManager.is_duplicate_warning_event(fieldInfo))
		{
			itor.Next();
			continue;
		}

		g_warningEventManager.add_raw_warning_event(fieldInfo);

		/// Mod by Henchi, 20110413
		/// ����澯״̬������m_cDropEventIdList���棬����g_pDataCenter����
		if (g_pDataCenter->IsObjectEventOff(
			(char *)fieldInfo.ObjectID.getValue()))
		{
			printf(
				"--- Notice: ObjectID [%s] Warnning Event [%s] drop!\n",
				fieldInfo.ObjectID.getValue(),
				fieldInfo.EventName.getValue());

			/// Ϊ����δ֪���أ��˴�����֮ǰreturn����������continue;
			return;
		}

#if 0
		///20100609 by zhou.jj ���Ӹ澯���ˣ�֧�ֿͻ��˵�ȡ���澯����
		///Ĭ��Ϊһ�����ݰ���������и澯������ͬһ������ID������������ڲ�ͬ�Ķ���澯����һ��������Ҫ�޸�����Ĵ���
		for (list<string>::iterator itList = m_cFrontServer.
			m_cDropEventIdList.begin();
			itList != m_cFrontServer.m_cDropEventIdList.end();
		itList++)
		{
			if (strstr(
				fieldInfo.ObjectID.getValue(),
				(*itList).c_str()) != NULL)
			{
				return;
			}
		}

#endif

		/// Added by Henchi, 20120228
		/// ����¼�������Ϣ��
		if (strlen(fieldInfo.WarningLevel.getValue()) == 0
			&&	g_mapEventLevel.find(
			fieldInfo.EventName.getValue()) != g_mapEventLevel.end())
		{
			fieldInfo.WarningLevel = g_mapEventLevel[fieldInfo.EventName.getValue()].c_str();
		}

		/// ����¼�ȫ����Ϣ
		if (strlen(fieldInfo.FullEventName.getValue()) == 0
			&&	g_mapEventFullName.find(
			fieldInfo.EventName.getValue()) != g_mapEventFullName.end())
		{
			fieldInfo.FullEventName = g_mapEventFullName[fieldInfo.EventName.getValue()].c_str();
		}

		/// ����¼�������Ϣ
		if (strlen(fieldInfo.EventDes.getValue()) == 0
			&&	g_mapEventDesc.find(
			string(fieldInfo.EventName.getValue())) != g_mapEventDesc.end())
		{
			fieldInfo.EventDes = g_mapEventDesc[string(
				fieldInfo.EventName.getValue())].c_str();
		}

		/// ������IP��Ϣ
		if (strlen(fieldInfo.IPAddress.getValue()) == 0)
		{
			fieldInfo.IPAddress = g_pDataCenter->getAddressByObjectID(
				(char *)fieldInfo.ObjectID.getValue()).c_str();
		}

		if (!g_mConfigControlEvent)
		{
			fieldInfo.EvendID = m_mWarningEventId++;
			g_cEventProcess.getEventDesc(
				(const char *)fieldInfo.ObjectID,
				(const char *)fieldInfo.EventName,
				nEventSeries);
			fieldInfo.EventNum = nEventSeries;

			string	delay_key = fieldInfo.ObjectID.getValue();
			delay_key += ";;";
			delay_key += fieldInfo.EventName.getValue();

			map<string, CObjectAttrKey>::iterator it = g_mapEventDelayTime.find(
				delay_key);
			if (it != g_mapEventDelayTime.end())
			{
				///�����ǰ�¼�������ʱ����ӳٵ�����ʱ�����ɾ��map�еĸýڵ�
				if (strcmp(
					fieldInfo.MonDate.getValue(),
					it->second.m_nObjectID.c_str()) > 0
					||	(
					strcmp(
					fieldInfo.MonDate.getValue(),
					it->second.m_nObjectID.c_str()) == 0 && strcmp(
					fieldInfo.MonTime.getValue(),
					it->second.m_nAttrID.c_str()) > 0
					))
				{
					g_mapEventDelayTime.erase(it);
				}
				else			///��ǰ�¼�������ʱ�����ӳٵ�����ʱ�䷶Χ�ڣ��Զ�����ø澯�����ñ��ΪY
				{
					if(fieldInfo.ProcessFlag == "=" 
						&& it->second.m_sProcessFlag.compare("Y") == 0)
					{
						//�¼���ԭ����
						g_mapEventDelayTime.erase(it);
					}
					else
					{
						fieldInfo.ProcessFlag = it->second.m_sProcessFlag.c_str();
						fieldInfo.EventDealDes = it->second.m_sEventDes.c_str();
					}
				}
			}

			m_pkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			m_pkgSend.MakePackage();
			m_cFrontServer.m_pCurrFrontFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
			m_cFrontServer.m_pCurrOracleFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
			m_pkgSend.ValidPackage();
			m_cProbeServer.SendPackageAllSession(&m_pkgSend);

			//���»�Ա��·״̬
			UpdateLinkStatusByWarningEvent(fieldInfo);

			//���¸澯����
			UpdateWarningCount(fieldInfo);

			map<int, string>::iterator p_it = g_mapEventProcessFlag.find(fieldInfo.EventNum.getValue());
			if(p_it != g_mapEventProcessFlag.end())
			{
				//���¼����ڴ����·������¼�Ҳ��Ϊ������
				if(p_it->second.compare("=")== 0 && fieldInfo.ProcessFlag == "N")
				{
					fieldInfo.ProcessFlag = p_it->second.c_str();
				}
				else
				{
					p_it->second = fieldInfo.ProcessFlag.getValue();
				}
			}
			else
			{
				g_mapEventProcessFlag[fieldInfo.EventNum.getValue()] = fieldInfo.ProcessFlag.getValue();
			}

			//κ��add������δ����ĸ澯�¼�
			g_warningEventManager.add_warning_event(fieldInfo);

			if(fieldInfo.ProcessFlag == "N")
			{
				//send mms
				string	membername;
				m_cConfigConnector.GetPartyLinkMemberName(fieldInfo, membername);

				string	devname;
				m_cConfigConnector.GetDeviceName(
					fieldInfo.ObjectID.getValue(),
					devname);

				int warningcount = GetWarningCount(fieldInfo);

				g_MsgGenerator.AddEvent(
					fieldInfo,
					warningcount,
					(char *)devname.c_str(),
					(char *)membername.c_str());
			}

			if ((
				strcmp(fieldInfo.ProcessFlag.getValue(), "N") == 0
				||	strcmp(fieldInfo.ProcessFlag.getValue(), "=") == 0
				)
				&&	(
				strcmp(fieldInfo.EventName.getValue(), "LINK_UPDOWN") == 0
				||	strcmp(
				fieldInfo.EventName.getValue(),
				"LINK_SP_UPDOWN") == 0
				||	strcmp(
				fieldInfo.EventName.getValue(),
				"LINEPROTO_UPDOWN") == 0
				||	strcmp(
				fieldInfo.EventName.getValue(),
				"LINEPROTO_SP_UPDOWN") == 0
				))
			{
				//updown�¼�������·״̬ͳ����Ϣ
				string	wholeid = fieldInfo.ObjectID.getValue();
				size_t	pos = wholeid.rfind(".");
				if (pos != string::npos)
				{
					string	portid = wholeid.substr(pos + 1);

					m_pkgPbeSend.PreparePackage(
						FTD_TID_RtnNetPartyLinkStatusInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);

					CFTDRtnNetPartyLinkStatusInfoField	partylinkstatus;
					memset(&partylinkstatus, 0, sizeof(partylinkstatus));

					partylinkstatus.Interface = portid.c_str();
					partylinkstatus.IPADDR = fieldInfo.IPAddress.getValue();
					partylinkstatus.MonDate = fieldInfo.OccurDate;
					partylinkstatus.MonTime = fieldInfo.OccurTime;

					string	partylink_key = fieldInfo.IPAddress.getValue();
					partylink_key += "_";
					partylink_key += portid;

					MAP_PARTYLINK_INFO_IT p_it = m_cConfigConnector.m_partylinkinfo.
						find(partylink_key);
					if (p_it != m_cConfigConnector.m_partylinkinfo.end())
					{
						partylinkstatus.SEAT_NO = p_it->second.SEAT_NO;
						partylinkstatus.status = "down";

						FTDC_ADD_FIELD(&m_pkgPbeSend, &partylinkstatus);
						m_pkgPbeSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgPbeSend.Address(),
							m_pkgPbeSend.Length());
						m_cFrontServer.m_pCurrOracleFlow->Append(
							m_pkgPbeSend.Address(),
							m_pkgPbeSend.Length());
					}
					else
					{
						printf(
							"no partylink info for ip:%s, port:%s in %s\n",
							fieldInfo.IPAddress.getValue(),
							portid.c_str(),
							__FUNCTION__);
					}
				}
				else
				{
					printf("Invalid objectid for updown event, no \".\"!\n");
				}
			}
		}
		else
		{
			m_pkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

			//��field������ת�Ƶ�configͳһ����	
			if (m_cConfigConnector.GetSession())
			{
				m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
			}
			else
			{
				printf("config session NULL, send warningevent fail!\n");
			}
		}

		itor.Next();
	}
}

void CEventCounterServer::OnRtnSyslogEventTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnSyslogEventField fieldInfo;
	int nEventSeries;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnSyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		if (g_warningEventManager.is_duplicate_syslog_event(fieldInfo))
		{
			itor.Next();
			continue;
		}

		g_warningEventManager.add_raw_syslog_event(fieldInfo);

		if (fieldInfo.ProcessFlag == "C" || fieldInfo.ProcessFlag == "L")
		{
			//ʵʱ����ʵʱϵͳר�ã�eventidƫ��һ������ֵ
			fieldInfo.EvendID = 1000000 + m_mSyslogEventId++;
		}
		else
		{
			fieldInfo.EvendID = m_mSyslogEventId++;
		}

		g_cEventProcess.getEventDesc(
			(const char *)fieldInfo.ObjectID,
			(const char *)fieldInfo.EventName,
			nEventSeries);
		fieldInfo.EventNum = nEventSeries;

		m_pkgSend.PreparePackage(FTD_TID_RtnSyslogEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

		if (g_mConfigControlEvent && fieldInfo.ProcessFlag != "C" &&	fieldInfo.ProcessFlag != "L")
		{
			if (m_cConfigConnector.GetSession())
			{
				m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
			}
			else
			{
				printf("config session NULL, send syslogevent fail!\n");
			}
		}
		else
		{
			m_pkgSend.MakePackage();
			m_cFrontServer.m_pCurrFrontFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());

			//ϯλ��·����
			SeatLinkAnalysis(fieldInfo);

			//������·״̬��
			UpdateLinkStatusBySyslogEvent(fieldInfo);

			if (strcmp(fieldInfo.ProcessFlag.getValue(), "N") == 0
				&&	(
				strcmp(
				fieldInfo.EventName.getValue(),
				"LINEPROTO_UPDOWN") == 0
				||	strcmp(
				fieldInfo.EventName.getValue(),
				"LINEPROTO_SP_UPDOWN") == 0
				))
			{
				//updown�¼�������·״̬ͳ����Ϣ
				string	wholeid = fieldInfo.ObjectID.getValue();
				size_t	pos = wholeid.rfind(".");
				if (pos != string::npos)
				{
					string	portid = wholeid.substr(pos + 1);

					m_pkgPbeSend.PreparePackage(
						FTD_TID_RtnNetPartyLinkStatusInfoTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);

					CFTDRtnNetPartyLinkStatusInfoField	partylinkstatus;
					memset(&partylinkstatus, 0, sizeof(partylinkstatus));

					partylinkstatus.Interface = portid.c_str();
					partylinkstatus.IPADDR = fieldInfo.IPAddress.getValue();
					partylinkstatus.MonDate = fieldInfo.OccurDate;
					partylinkstatus.MonTime = fieldInfo.OccurTime;

					string	partylink_key = fieldInfo.IPAddress.getValue();
					partylink_key += "_";
					partylink_key += portid;

					MAP_PARTYLINK_INFO_IT p_it = m_cConfigConnector.m_partylinkinfo.
						find(partylink_key);
					if (p_it != m_cConfigConnector.m_partylinkinfo.end())
					{
						partylinkstatus.SEAT_NO = p_it->second.SEAT_NO;
						partylinkstatus.status = "up";

						FTDC_ADD_FIELD(&m_pkgPbeSend, &partylinkstatus);
						m_pkgPbeSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgPbeSend.Address(),
							m_pkgPbeSend.Length());
						m_cFrontServer.m_pCurrOracleFlow->Append(
							m_pkgPbeSend.Address(),
							m_pkgPbeSend.Length());
					}
					else
					{
						printf(
							"no partylink info for ip:%s, port:%s in %s\n",
							fieldInfo.IPAddress.getValue(),
							portid.c_str(),
							__FUNCTION__);
					}
				}
				else
				{
					printf("Invalid objectid for updown event, no \".\"!\n");
				}
			}
		}

		itor.Next();
		m_pEventBuffer->writeNode(&fieldInfo);
	}

}

void CEventCounterServer::UpdateLinkStatusByWarningEvent(
	CFTDRtnWarningEventField &fieldInfo)
{
	bool needSend = false;

	map<string, LinkStatusInfo>::iterator l_it = g_mapLinkStatusInfo.find(
		fieldInfo.ObjectID.getValue());
	if (l_it == g_mapLinkStatusInfo.end())
	{
		LinkStatusInfo	statusinfo;

		g_mapLinkStatusInfo[fieldInfo.ObjectID.getValue()] = statusinfo;

		l_it = g_mapLinkStatusInfo.find(fieldInfo.ObjectID.getValue());
	}

	map<int, int>::iterator iterEventLevel(
		g_mapEventNumLevel.find(fieldInfo.EventNum.getValue()));

	string	eventdesc = fieldInfo.EventDes.getValue();

	if (fieldInfo.ProcessFlag == "Y" || fieldInfo.ProcessFlag == "=")
	{
		if (iterEventLevel != g_mapEventNumLevel.end())
		{
			if (fieldInfo.EventName == "LINK_UPDOWN"
				||	fieldInfo.EventName == "LINKADMIN_UPDOWN")
			{
				l_it->second.m_nPortLinkStatus = 0;
				needSend = true;
			}
			else if (fieldInfo.EventName == "LINEPROTO_UPDOWN")
			{
				l_it->second.m_nPortProtoStatus = 0;
				needSend = true;
			}
			else
			{
				//TODO
			}

			g_mapEventNumLevel.erase(iterEventLevel);
		}

		// ʵ��up����
		if (string::npos != eventdesc.find("up"))
		{
			if (fieldInfo.EventName == "LINK_UPDOWN"
				||	fieldInfo.EventName == "LINKADMIN_UPDOWN")
			{
				l_it->second.m_nPortLinkStatusReal = 0;
				needSend = true;
			}
			else if (fieldInfo.EventName == "LINEPROTO_UPDOWN")
			{
				l_it->second.m_nPortProtoStatusReal = 0;
				needSend = true;
			}
			else
			{
				//TODO
			}
		}
	}
	else
	{
		if (iterEventLevel == g_mapEventNumLevel.end())
		{
			if (fieldInfo.EventName == "LINK_UPDOWN")
			{
				l_it->second.m_nPortLinkStatus = 1;
				needSend = true;
			}
			else if (fieldInfo.EventName == "LINKADMIN_UPDOWN")
			{
				l_it->second.m_nPortLinkStatus = 2;
				needSend = true;
			}
			else if (fieldInfo.EventName == "LINEPROTO_UPDOWN")
			{
				l_it->second.m_nPortProtoStatus = 1;
				needSend = true;
			}
			else
			{
				//TODO
			}

			g_mapEventNumLevel[fieldInfo.EventNum.getValue()] = 1;
		}

		// ʵ��down��
		if (string::npos != eventdesc.find("down"))
		{
			if (fieldInfo.EventName == "LINK_UPDOWN")
			{
				l_it->second.m_nPortLinkStatusReal = 1;
				needSend = true;
			}
			else if (fieldInfo.EventName == "LINKADMIN_UPDOWN")
			{
				l_it->second.m_nPortLinkStatusReal = 2;
				needSend = true;
			}
			else if (fieldInfo.EventName == "LINEPROTO_UPDOWN")
			{
				l_it->second.m_nPortProtoStatusReal = 1;
				needSend = true;
			}
			else
			{
				//TODO
			}
		}
	}

	if (needSend)
	{
		SendLinkStatus(
			fieldInfo.ObjectID.getValue(),
			fieldInfo.IPAddress.getValue());
	}
}

void CEventCounterServer::UpdateLinkStatusBySyslogEvent(
	CFTDRtnSyslogEventField &fieldInfo)
{
	bool needSend = false;

	map<string, LinkStatusInfo>::iterator l_it = g_mapLinkStatusInfo.find(
		fieldInfo.ObjectID.getValue());
	if (l_it == g_mapLinkStatusInfo.end())
	{
		LinkStatusInfo	statusinfo;

		g_mapLinkStatusInfo[fieldInfo.ObjectID.getValue()] = statusinfo;

		l_it = g_mapLinkStatusInfo.find(fieldInfo.ObjectID.getValue());
	}

	map<int, int>::iterator iterEventLevel(
		g_mapEventNumLevel.find(fieldInfo.EventNum.getValue()));

	string	eventdesc = fieldInfo.EventDes.getValue();

	if (string::npos != eventdesc.find("down"))
	{
		if (fieldInfo.EventName == "LINK_UPDOWN")
		{
			l_it->second.m_nPortLinkStatusReal = 1;
			needSend = true;
		}
		else if (fieldInfo.EventName == "LINKADMIN_UPDOWN")
		{
			l_it->second.m_nPortLinkStatusReal = 2;
			needSend = true;
		}
		else if (fieldInfo.EventName == "LINEPROTO_UPDOWN")
		{
			l_it->second.m_nPortProtoStatusReal = 1;
			needSend = true;
		}
		else
		{
			//TODO
		}
	}
	else if (string::npos != eventdesc.find("up"))
	{
		if (fieldInfo.EventName == "LINK_UPDOWN"
			||	fieldInfo.EventName == "LINKADMIN_UPDOWN")
		{
			l_it->second.m_nPortLinkStatusReal = 0;
			needSend = true;
		}
		else if (fieldInfo.EventName == "LINEPROTO_UPDOWN")
		{
			l_it->second.m_nPortProtoStatusReal = 0;
			needSend = true;
		}
		else
		{
			//TODO
		}
	}

	if (needSend)
	{
		SendLinkStatus(
			fieldInfo.ObjectID.getValue(),
			fieldInfo.IPAddress.getValue());
	}
}

char CEventCounterServer::GenerateMaskValue(int nMaskValue)
{
	char byteValue = 0;

	if (nMaskValue >= 0 && nMaskValue <= 8)
	{
		for (int nNumberIndex = nMaskValue, nIndex = 7;
			nNumberIndex > 0;
			--nNumberIndex, --nIndex)
		{
			byteValue += (char)pow(2.0, nIndex);
		}
	}

	return byteValue;
}

int CEventCounterServer::SplitString(
	const string &strSrc,
	const string &strDelimiter,
	vector<string>	&strArrayRes)
{
	string	strOrigin = strSrc;

	int nSubString = 0;
	size_t	nDelimitPos = -1;

	strArrayRes.clear();

	while (string::npos != (nDelimitPos = strOrigin.find(strDelimiter)))
	{
		string	strSubString(strOrigin.substr(0, nDelimitPos));
		strArrayRes.push_back(strSubString);

		strOrigin = strOrigin.substr(
			nDelimitPos + strDelimiter.length(),
			strOrigin.length() - nDelimitPos - strDelimiter.length());
		++nSubString;
	}

	if (strDelimiter.compare(";") == 0)
	{
		return nSubString;
	}

	strArrayRes.push_back(strOrigin);

	return ++nSubString;
}

bool CEventCounterServer::IsBelongIPRange(
	const string &strIPRange,
	const string &strIPAddrSample)
{
	if (strIPRange.length() == 0 || strIPAddrSample.length() == 0)
	{
		return false;
	}

	size_t	nFindPos = strIPRange.find("/");
	if (string::npos != nFindPos)
	{
		string	strIPAddr = strIPRange.substr(0, nFindPos);
		string	strMask = strIPRange.substr(nFindPos + 1);

		int nMaskValue = atoi(strMask.c_str());
		nMaskValue = nMaskValue > 32 ? 32 : nMaskValue;

		char byteMaskCode[4] = { 0, 0, 0, 0 };
		int nFullNumberOne = nMaskValue / 8;
		int nPartNumberOne = nMaskValue % 8;

		int nIndex = 0;
		for (; nIndex != nFullNumberOne; ++nIndex)
		{
			byteMaskCode[nIndex] = 255;
		}

		if (nIndex <= 2)
		{
			byteMaskCode[nIndex] = GenerateMaskValue(nPartNumberOne);
		}

		vector<string>	strIPArray;
		SplitString(strIPAddr, ".", strIPArray);

		if (strIPArray.size() != 4)
		{
			printf(
				"strIPAddr:%s split size:%d not equal 4 in %s\n",
				strIPAddr.c_str(),
				strIPArray.size(),
				__FUNCTION__);
			return false;
		}

		char byteIPAddress[4] =
		{
			atoi(strIPArray[0].c_str()),
			atoi(strIPArray[1].c_str()),
			atoi(strIPArray[2].c_str()),
			atoi(strIPArray[3].c_str())
		};

		SplitString(strIPAddrSample, ".", strIPArray);
		if (strIPArray.size() != 4)
		{
			printf(
				"strIPAddrSample:%s split size:%d not equal 4 in %s\n",
				strIPAddrSample.c_str(),
				strIPArray.size(),
				__FUNCTION__);
			return false;
		}

		char byteIPAddrSampe[4] =
		{
			atoi(strIPArray[0].c_str()),
			atoi(strIPArray[1].c_str()),
			atoi(strIPArray[2].c_str()),
			atoi(strIPArray[3].c_str())
		};

		// �����������Ҫ�����ʼ��IP��ַ��Ȼ��������ҪУ���IP�����������㿴�Ƿ������ʼ��IP��ַ
		char byteStartIPAddr[4];
		byteStartIPAddr[0] = byteIPAddress[0] & byteMaskCode[0];
		byteStartIPAddr[1] = byteIPAddress[1] & byteMaskCode[1];
		byteStartIPAddr[2] = byteIPAddress[2] & byteMaskCode[2];
		byteStartIPAddr[3] = byteIPAddress[3] & byteMaskCode[3];

		char byteSampleResult[4];
		byteSampleResult[0] = byteIPAddrSampe[0] & byteMaskCode[0];
		byteSampleResult[1] = byteIPAddrSampe[1] & byteMaskCode[1];
		byteSampleResult[2] = byteIPAddrSampe[2] & byteMaskCode[2];
		byteSampleResult[3] = byteIPAddrSampe[3] & byteMaskCode[3];

		if (byteStartIPAddr[0] == byteSampleResult[0]
		&&	byteStartIPAddr[1] == byteSampleResult[1]
		&&	byteStartIPAddr[2] == byteSampleResult[2]
		&&	byteStartIPAddr[3] == byteSampleResult[3])
		{
			return true;
		}
	}

	return false;
}

void CEventCounterServer::SeatLinkAnalysis(CFTDRtnSyslogEventField &fieldInfo)
{
	if (fieldInfo.EventName != "Connect"
		&& fieldInfo.EventName != "MdLogin"
		&& fieldInfo.EventName != "MdLogout"
		&& fieldInfo.EventName != "MdProxySubscribe"
		)
	{
		return;
	}

	string	objectid = fieldInfo.ObjectID.getValue();
	char str1[100];
	char datacenter[16];
	char str3[16];
	char str4[16];
	int frontnum;
	int iRtn = sscanf(
		objectid.c_str(),
		"%[^.].%[^.].%[^.].%[^.].%d\n",
		str1,
		datacenter,
		str3,
		str4,
		&frontnum);
	if (iRtn == 5)
	{
		// Added by Henchi, 20150911
		/// TRADE2��TRADE����
		if (strcmp(str1, "TRADE") != 0 && strcmp(str1, "TRADE2") != 0 )
		{
			return;
		}

		if (strcmp(datacenter, "PuDian") != 0
			&&	strcmp(datacenter, "ZhangJ") != 0
			&&	strcmp(datacenter, "BeiJing") != 0)
		{
			return;
		}

		if (strcmp(str3, "app") != 0)
		{
			return;
		}

		if(fieldInfo.EventName == "Connect")
		{
			if (strcmp(str4, "front") != 0)
			{
				return;
			}

			if (frontnum < 1 || frontnum > 28)
			{
				return;
			}
		}
		else if(fieldInfo.EventName == "MdLogin"
			|| fieldInfo.EventName == "MdLogout")
		{
			if (strcmp(str4, "mdkernel") != 0)
			{
				return;
			}
		}

		string	eventdesc = fieldInfo.EventDes.getValue();
		string	ipstr;
		int type = 0;

		if(fieldInfo.EventName == "Connect")
		{	
			if (eventdesc.find("Disconnect") != string::npos)
			{
				type = 1;
			}
			else if (eventdesc.find("Connect") != string::npos)
			{
				type = 0;
			}
			else
			{
				return;
			}

			size_t	pos = eventdesc.find("IP=");
			if (pos != string::npos)
			{
				ipstr = eventdesc.substr(pos + strlen("IP="));
			}

			CFTDRtnNetPartyLinkStatusInfoField	tfield;
			memset(&tfield, 0, sizeof(tfield));

			MAP_PARTYLINK_INFO_IT p_it = m_cConfigConnector.m_partylinkinfo.begin();
			for (; p_it != m_cConfigConnector.m_partylinkinfo.end(); ++p_it)
			{
				if (IsBelongIPRange(p_it->second.IP_LAN.getValue(), ipstr))
				{
					tfield.Interface = p_it->second.Interface;
					tfield.SEAT_NO = p_it->second.MEMBER_NO;

					break;
				}
			}

			tfield.MonDate = fieldInfo.MonDate;
			tfield.MonTime = fieldInfo.MonTime;
			tfield.IPADDR = ipstr.c_str();

			char strBuf[100] = { 0 };

			SNPRINTF(strBuf, 100, "Link:%d", type);

			tfield.status = strBuf;

			m_pkgSend.PreparePackage(
				FTD_TID_RtnNetPartyLinkStatusInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);

			m_pkgSend.MakePackage();
			m_cFrontServer.m_pCurrFrontFlow->Append(
				m_pkgSend.Address(),
				m_pkgSend.Length());

		}
		else if(fieldInfo.EventName == "MdLogin"
			|| fieldInfo.EventName == "MdLogout")
		{
			char result[100];
			char ipstr[50];
			char hqname[50];
			int frontnum;
			char otherinfo[1024];
			int iRtn = sscanf(
				eventdesc.c_str(),
				"%[^ ] %[^ ] %[^,],front=%d,%s\n",
				result,
				ipstr,
				hqname,
				&frontnum,
				otherinfo);
			if (iRtn == 5)
			{
				// add by cao.ning 
				// ��������ϯλ��¼��ͳ��
				char mdkernelID[128];
				memset(mdkernelID, 0, 128);
				if (strcmp(datacenter, "PuDian") == 0) sprintf(mdkernelID, "mdkernel%d.pd", frontnum);
				else if (strcmp(datacenter, "ZhangJ") == 0) sprintf(mdkernelID, "mdkernel%d.zj", frontnum);
				else sprintf(mdkernelID, "mdkernel%d.bj", frontnum);
				
				MdLoginRecord::MdLoginState _loginState = (strcmp(result, "Success") == 0) ? 
															MdLoginRecord::Success : MdLoginRecord::Failure;
				MdLoginWarningCalculate::HandleMdLogin(
					fieldInfo.OccurDate,
					fieldInfo.OccurTime,
					_loginState,
					mdkernelID,
					hqname);

				if(strcmp(result, "Success") !=0 )
				{
					printf("result %s not Success in eventdes %s in %s\n"
						, result, eventdesc.c_str(), __FUNCTION__);
					return;
				}
/*
				if(strncmp(hqname,"HQ", 2) != 0)
				{
					printf("hqname %s not start by HQ in eventdes %s in %s\n"
						, hqname, eventdesc.c_str(), __FUNCTION__);

					return;
				}
*/				
			}
			else
			{
				//printf("eventdes %s invalid in %s for mdkernel!\n", eventdesc.c_str(), __FUNCTION__);
				return;
			}

			if(fieldInfo.EventName == "MdLogin")
			{
				type = 10;
			}
			else
			{
				type = 11;
			}

			CFTDRtnTradeUserLoginInfoField tfield;
			memset(&tfield, 0, sizeof(tfield));

			tfield.ObjectID = fieldInfo.ObjectID;
			tfield.FrontID = frontnum;
			tfield.DataCenter = datacenter;
			tfield.IPAddress = ipstr;
			tfield.UserID = hqname;
			tfield.ActionDate = fieldInfo.MonDate;
			tfield.ActionTime = fieldInfo.MonTime;
			tfield.ActionFlag = type;	

			m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeUserLoginInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);

			m_pkgSend.MakePackage();
			m_cFrontServer.m_pCurrFrontFlow->Append(
				m_pkgSend.Address(),
				m_pkgSend.Length());			
		}
		else if (fieldInfo.EventName == "MdProxySubscribe")
		{
			char szUserName[100] = {0};
			int iRtn = sscanf(eventdesc.c_str(), "User=%[^,]", szUserName);
			if (iRtn != 1)
			{
				printf("MdProxySubscribe from[%s] eventdesc[%s] error.\n", 
					objectid.c_str(), eventdesc.c_str());
				return;
			}
			if (szUserName[0] < '0' || szUserName[0] > '9')
			{
				printf("MdProxySubscribe from[%s] eventdesc[%s]. Not a valid event.\n", 
					objectid.c_str(), eventdesc.c_str());
				return;
			}
			CFTDRtnTradeUserLoginInfoField tfield;
			memset(&tfield, 0, sizeof(tfield));

			tfield.ObjectID = fieldInfo.ObjectID;
			tfield.UserID = szUserName;
			tfield.ActionDate = fieldInfo.MonDate;
			tfield.ActionTime = fieldInfo.MonTime;
			tfield.ActionFlag = 12;	// 3 for MdProxySubscribe

			m_pkgSend.PreparePackage(
				FTD_TID_RtnTradeUserLoginInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);

			m_pkgSend.MakePackage();
			m_cFrontServer.m_pCurrFrontFlow->Append(
				m_pkgSend.Address(),
				m_pkgSend.Length());
		}
	}
}

int CEventCounterServer::GetPortStatus(LinkStatusInfo &statusinfo)
{
	if (statusinfo.m_nPortLinkStatus < 0 || statusinfo.m_nPortLinkStatus > 2)
	{
		return 0;
	}

	if (statusinfo.m_nPortProtoStatus < 0 || statusinfo.m_nPortProtoStatus > 1)
	{
		return 0;
	}

	if (0 == statusinfo.m_nPortLinkStatus && 0 == statusinfo.m_nPortProtoStatus)
	{
		return 0;
	}
	else if (2 == statusinfo.m_nPortLinkStatus)
	{
		return 3;
	}
	else if (0 == statusinfo.m_nPortLinkStatus
		&&	 1 == statusinfo.m_nPortProtoStatus)
	{
		return 1;
	}
	else if (1 == statusinfo.m_nPortLinkStatus
		&&	 1 == statusinfo.m_nPortProtoStatus)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int CEventCounterServer::GetPortRealStatus(LinkStatusInfo &statusinfo)
{
	if (statusinfo.m_nPortLinkStatus < 0
		||	statusinfo.m_nPortLinkStatusReal > 2)
	{
		return 0;
	}

	if (statusinfo.m_nPortProtoStatus < 0
		||	statusinfo.m_nPortProtoStatusReal > 1)
	{
		return 0;
	}

	if (0 == statusinfo.m_nPortLinkStatusReal
		&&	0 == statusinfo.m_nPortProtoStatusReal)
	{
		return 0;
	}
	else if (2 == statusinfo.m_nPortLinkStatusReal)
	{
		return 3;
	}
	else if (0 == statusinfo.m_nPortLinkStatusReal
		&&	 1 == statusinfo.m_nPortProtoStatusReal)
	{
		return 1;
	}
	else if (1 == statusinfo.m_nPortLinkStatusReal
		&&	 1 == statusinfo.m_nPortProtoStatusReal)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void CEventCounterServer::SendLinkStatus(string objectid, string ipaddr)
{
	map<string, LinkStatusInfo>::iterator l_it = g_mapLinkStatusInfo.find(
		objectid);
	if (l_it == g_mapLinkStatusInfo.end())
	{
		LinkStatusInfo	statusinfo;

		g_mapLinkStatusInfo[objectid] = statusinfo;

		l_it = g_mapLinkStatusInfo.find(objectid);
	}

	time_t	timep;

	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);

	char curtime[10];
	char curdate[10];

	strftime(curtime, 10, "%H:%M:%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	CFTDRtnNetPartyLinkStatusInfoField	tfield;
	memset(&tfield, 0, sizeof(tfield));

	string	interfaceid = objectid;
	size_t	pos = interfaceid.rfind(".");
	if (pos != string::npos)
	{
		interfaceid = interfaceid.substr(pos + 1);
	}

	tfield.Interface = interfaceid.c_str();
	tfield.MonDate = curdate;
	tfield.MonTime = curtime;
	tfield.IPADDR = ipaddr.c_str();

	char strBuf[100] = { 0 };
	SNPRINTF(
		strBuf,
		100,
		"%d_%d",
		GetPortRealStatus(l_it->second),
		GetPortStatus(l_it->second));

	tfield.status = strBuf;

	m_pkgSend.PreparePackage(
		FTD_TID_RtnNetPartyLinkStatusInfoTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &tfield);

	m_pkgSend.MakePackage();
	m_cFrontServer.m_pCurrFrontFlow->Append(
		m_pkgSend.Address(),
		m_pkgSend.Length());
}

string CEventCounterServer::getTradingSection(char *pTime)
{
	long lTime = TIME_TO_LONG(pTime);
	for (int i = 0; i < m_TradeSectionsVec.size(); i++)
	{
		TradeSectionInfo &TradeSection = m_TradeSectionsVec[i];
		if (TradeSection.left_time < TradeSection.right_time)
		{
			/// ����ʱ��
			if (TradeSection.left_time <= lTime
				&&	lTime < TradeSection.right_time)
			{
				return TradeSection.name;
			}
		}
		else
		{
			/// ����ʱ��
			if (TradeSection.left_time <= lTime
				||	lTime < TradeSection.right_time)
			{
				return TradeSection.name;
			}
		}
	}

	return "";
}

void CEventCounterServer::OnRtnObjectAttrTopic(CFTDCPackage *pFTDCPackage)
{
	string	mObjectId;

	string	mAttrId;
	CFTDRtnObjectAttrField	fieldInfo;
	bool bFlag = false;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnObjectAttrField::m_Describe);
	m_pkgSend.PreparePackage(
		FTD_TID_RtnObjectAttrTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);
	m_pkgPbeSend.PreparePackage(
		FTD_TID_RtnObjectAttrTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		if (fieldInfo.ValueType == UNKNOWN_ATTR)
		{
			fieldInfo.ValueType = g_pDataCenter->getAttrType(
				fieldInfo.AttrType.getValue(),
				fieldInfo.AttrValue.getValue());
		}
		m_pNodeBuffer->writeNode(&fieldInfo);

		mObjectId = fieldInfo.ObjectID.getValue();
		mAttrId = fieldInfo.AttrType.getValue();

		double	monitorValue = atof(fieldInfo.AttrValue.getValue());

		// Added by Henchi, 20120815
		// �ж��Ƿ���Ҫ�������ݰ����׽�ͳ�Ʒ�ֵ
		if (g_nTradingSectionStatFlag == 1
			&&	m_StatObjectAttrMap.find(
			CObjectAttrKey(
			fieldInfo.ObjectID.getValue(),
			fieldInfo.AttrType.getValue())) != m_StatObjectAttrMap.end())
		{
			string	SectionName = getTradingSection(
				(char *)fieldInfo.MonTime.getValue());
			if (strcmp(SectionName.c_str(), "") != 0)
			{
				char szTmp[512];
				sprintf(
					szTmp,
					"%s_%s_%s",
					fieldInfo.ObjectID.getValue(),
					fieldInfo.AttrType.getValue(),
					SectionName.c_str());

				map<string, string>::iterator map_it = m_TradeSectionPeaks.find(
					szTmp);
				if (map_it == m_TradeSectionPeaks.end()
					||	(
					map_it != m_TradeSectionPeaks.end()
					&&	atof(fieldInfo.AttrValue.getValue()) > atof(
					map_it->second.c_str())
					))
				{
					m_TradeSectionPeaks[szTmp] = fieldInfo.AttrValue.getValue();

					CFTDRtnObjectAttrField	newFiledInfo;
					memcpy(
						(void *) &newFiledInfo,
						(void *) &fieldInfo,
						sizeof(newFiledInfo));
					sprintf(
						(char *)newFiledInfo.AttrType.getValue(),
						"%s_%s",
						fieldInfo.AttrType.getValue(),
						SectionName.c_str());

					if (m_pkgSend.Length() +
						sizeof
						(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
					{
						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
						m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					}

					FTDC_ADD_FIELD(&m_pkgSend, &newFiledInfo);	/// ��ǰ�����ͷ�ֵͳ����Ϣ
				}
			}
		}

		// �ж��Ƿ���Ҫ����������Ϊ̽��������� map<CObjectAttrKey, int> g_mapProbeConfig
		if (m_mapProbeConfig.find(
			CObjectAttrKey(
			fieldInfo.ObjectID.getValue(),
			fieldInfo.AttrType.getValue())) != m_mapProbeConfig.end())
		{
			FTDC_ADD_FIELD(&m_pkgPbeSend, &fieldInfo);
			bFlag = true;
		}

		if (m_pkgSend.Length() +
			sizeof(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
		{
			m_pkgSend.MakePackage();
			m_cFrontServer.m_pCurrFrontFlow->Append(
				m_pkgSend.Address(),
				m_pkgSend.Length());

			/// Mod by Henchi, 20121211
			/// �ر���Query���Ͷ���ָ��ṹ
#ifdef OBJATTR_TO_ORACLE
			m_cFrontServer.m_pCurrOracleFlow->Append(
				m_pkgSend.Address(),
				m_pkgSend.Length());
#endif
			m_pkgSend.PreparePackage(
				FTD_TID_RtnObjectAttrTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

		if (m_mapApp.find(fieldInfo.AttrType.getValue()) != m_mapApp.end()
			&&	(strstr((char *)fieldInfo.ObjectID.getValue(), APP_TMDB) == NULL
			))	// �����������ļ���Ϣ
		{
			char *p = (char *)strstr(
				fieldInfo.ObjectID.getValue(),
				DOTDATACENTERAPPDOT);	// zhou.jj 20090302
			if (p != NULL)
			{
				*(p + 4) = '\0';
				p = p + 5;

				map<CObjectAttrKey, CObjectAttrValue>::iterator attrIt =
					m_mapLastItem.find(
					CObjectAttrKey(
					fieldInfo.ObjectID.getValue(),
					mAttrId));
				int monitorTime = getTimeFromStr(
					(char *)fieldInfo.MonDate.getValue(),
					(char *)fieldInfo.MonTime.getValue());
				if (attrIt == m_mapLastItem.end())
				{
					if (m_pkgSend.Length() +
						sizeof
						(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
					{
						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
#ifdef OBJATTR_TO_ORACLE
						m_cFrontServer.m_pCurrOracleFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
#endif
						m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					}

					FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
					m_mapLastItem[CObjectAttrKey(
						fieldInfo.ObjectID.getValue(),
						mAttrId)] = CObjectAttrValue(monitorTime, monitorValue);
					FTDC_ADD_FIELD(&m_pkgPbeSend, &fieldInfo);

					strcat(
						(char *)fieldInfo.AttrType.getValue(),
						APPATTRCENTERINFO);
					fieldInfo.ValueType = STRING_ATTR;
					fieldInfo.AttrValue = p;
					FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
					FTDC_ADD_FIELD(&m_pkgPbeSend, &fieldInfo);

					bFlag = true;
				}
				else if ((attrIt->second.m_nTime < monitorTime)
					||	 (attrIt->second.m_nValue < monitorValue))
				{
					if (m_pkgSend.Length() +
						sizeof
						(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
					{
						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
#ifdef OBJATTR_TO_ORACLE
						m_cFrontServer.m_pCurrOracleFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
#endif
						m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
					}

					FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
					attrIt->second.m_nTime = monitorTime;
					attrIt->second.m_nValue = monitorValue;
					FTDC_ADD_FIELD(&m_pkgPbeSend, &fieldInfo);

					strcat(
						(char *)fieldInfo.AttrType.getValue(),
						APPATTRCENTERINFO);
					fieldInfo.ValueType = STRING_ATTR;
					fieldInfo.AttrValue = p;
					FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
					FTDC_ADD_FIELD(&m_pkgPbeSend, &fieldInfo);

					bFlag = true;
				}
			}
		}
		else if ((strcmp(fieldInfo.AttrType.getValue(), APPATTRACTIVE) == 0)
			&&	 (monitorValue != 0))		// ��������������Acitve״̬,       zhou.jj 20090302
		{
			char *p = (char *)strchr(fieldInfo.ObjectID.getValue(), '.');
			if (p != NULL)
			{
				p++;
				p = strchr(p, '.');
				if (p != NULL)
				{
					p++;
					p = strchr(p, '.');
					if (p != NULL)
					{
						*p = '\0';

						int monitorTime = getTimeFromStr(
							(char *)fieldInfo.MonDate.getValue(),
							(char *)fieldInfo.MonTime.getValue());
						if (m_center[string(
							fieldInfo.ObjectID.getValue())] < monitorTime)
						{
							m_center[string(
								fieldInfo.ObjectID.getValue())] = monitorTime;
							if (m_pkgSend.Length() + sizeof
								(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
							{
								m_pkgSend.MakePackage();
								m_cFrontServer.m_pCurrFrontFlow->Append(
									m_pkgSend.Address(),
									m_pkgSend.Length());
#ifdef OBJATTR_TO_ORACLE
								m_cFrontServer.m_pCurrOracleFlow->Append(
									m_pkgSend.Address(),
									m_pkgSend.Length());
#endif
								m_pkgSend.PreparePackage(
									FTD_TID_RtnObjectAttrTopic,
									FTDC_CHAIN_LAST,
									FTD_VERSION);
							}

							FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

							FTDC_ADD_FIELD(&m_pkgPbeSend, &fieldInfo);
							bFlag = true;
						}
					}
				}
			}
		}

		itor.Next();
		if (itor.IsEnd())
		{
			break;
		}
	}

	m_pkgSend.MakePackage();
	m_cFrontServer.m_pCurrFrontFlow->Append(
		m_pkgSend.Address(),
		m_pkgSend.Length());
#ifdef OBJATTR_TO_ORACLE
	m_cFrontServer.m_pCurrOracleFlow->Append(
		m_pkgSend.Address(),
		m_pkgSend.Length());
#endif
	if (bFlag)
	{
		m_pkgSend.ValidPackage();
		m_cProbeServer.SendPackageAllSession(&m_pkgSend);
	}
}

void CEventCounterServer::OnRtnNetMonitorTaskInfoTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetMonitorTaskInfoField	fieldInfo;

	m_pkgSend.PreparePackage(
		FTD_TID_RtnNetMonitorTaskInfoTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnNetMonitorTaskInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
		itor.Next();
	}

	m_pkgSend.MakePackage();
	m_cFrontServer.m_pCurrFrontFlow->Append(
		m_pkgSend.Address(),
		m_pkgSend.Length());
}

void CEventCounterServer::OnRtnNetMonitorTaskResultTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetMonitorTaskResultField fieldInfo;
	memset(&fieldInfo, 0, sizeof(fieldInfo));

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnNetMonitorTaskResultField::m_Describe);
	m_pkgSend.PreparePackage(
		FTD_TID_RtnNetMonitorTaskResultTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	char key[1024] = { 0 };
	int taskflag = -1;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		taskflag = fieldInfo.Flag.getValue();

		if (fieldInfo.Flag == TASK_SUCCESS)
		{
			//������������һ������ȫ�������ٴ���
			SNPRINTF(
				key,
				1024,
				"%s_%d_%d_%s_%s",
				fieldInfo.ObjectID.getValue(),
				fieldInfo.Task_ID.getValue(),
				fieldInfo.OperateTime.getValue(),
				fieldInfo.MonDate.getValue(),
				fieldInfo.MonTime.getValue());

			map<string, vector<CFTDRtnNetMonitorTaskResultField> >::iterator
				t_it = m_mapTaskResult.find(key);
			if (t_it != m_mapTaskResult.end())
			{
				t_it->second.push_back(fieldInfo);
			}
			else
			{
				vector<CFTDRtnNetMonitorTaskResultField> taskresult;

				taskresult.push_back(fieldInfo);
				m_mapTaskResult[key] = taskresult;
			}
		}
		else
		{
			//����״ֱ̬��͸����front
			if (m_pkgSend.Length() + sizeof
				(CFTDRtnNetMonitorTaskResultField) >= FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.MakePackage();
				m_cFrontServer.m_pCurrFrontFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());
				m_pkgSend.PreparePackage(
					FTD_TID_RtnNetMonitorTaskResultTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
		}

		itor.Next();
	}

	m_pkgSend.MakePackage();
	m_cFrontServer.m_pCurrFrontFlow->Append(
		m_pkgSend.Address(),
		m_pkgSend.Length());

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && taskflag == TASK_SUCCESS)
	{
		//�����û������������һ������instructionchain�ֶ�
		string	cmdstr;
		string	username = fieldInfo.InstructChain.getValue();
		size_t	pos = username.rfind("@");
		if (pos != string::npos)
		{
			cmdstr = username.substr(0, pos);
			username = username.substr(pos + 1);
		}
		else
		{
			cmdstr = username;
			username = "";
		}

		CFTDRtnNetMonitorTaskResultField resultField;
		memset(&resultField, 0, sizeof(resultField));

		resultField.OperationType = 1011;

		//һ������Ľ��ȫ������
		map<string, vector<CFTDRtnNetMonitorTaskResultField> >::iterator t_it =
			m_mapTaskResult.find(key);
		if (t_it != m_mapTaskResult.end())
		{
			if (t_it->second.size() > 0)
			{
				string	result;

				resultField.Flag = t_it->second[0].Flag;
				resultField.InstructChain = cmdstr.c_str();
				resultField.MonDate = t_it->second[0].MonDate;
				resultField.MonTime = t_it->second[0].MonTime;
				resultField.ObjectID = t_it->second[0].ObjectID;
				resultField.OperateTime = t_it->second[0].OperateTime;
				resultField.OperationType = t_it->second[0].OperationType;
				resultField.Task_ID = t_it->second[0].Task_ID;

				for (int i = 0; i < t_it->second.size(); ++i)
				{
					//��ԭ�����ԭ��
					result += t_it->second[i].ResultChain.getValue();
				}

				string	newresult;


				RegularParse(resultField, result, newresult);

				//֪ͨǰ�ú�query
				if (newresult.length() == 0)
				{
					resultField.OperationType = 0;

					if (username.length() > 0)
					{
						string	str = cmdstr;
						str += "@";
						str += username;

						resultField.InstructChain = str.c_str();
					}

					resultField.ResultChain = "*@*";

					m_pkgSend.PreparePackage(
						FTD_TID_RtnNetMonitorTaskResultTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
					FTDC_ADD_FIELD(&m_pkgSend, &resultField);
					m_pkgSend.MakePackage();
					m_cFrontServer.m_pCurrFrontFlow->Append(
						m_pkgSend.Address(),
						m_pkgSend.Length());
					m_cFrontServer.m_pCurrOracleFlow->Append(
						m_pkgSend.Address(),
						m_pkgSend.Length());
				}
				else if (newresult.compare("*@*") == 0)
				{
					result += newresult;

					for (int i = 0, deta = 0; i < result.length(); i += deta)
					{
						deta = min(
							result.length() - i,
							sizeof(resultField.ResultChain) - 10);

						if (deta == (result.length() - i))
						{
							resultField.OperationType = 0;

							if (username.length() > 0)
							{
								string	str = cmdstr;
								str += "@";
								str += username;

								resultField.InstructChain = str.c_str();
							}
						}

						resultField.ResultChain = (result.substr(i, deta)).c_str();

						m_pkgSend.PreparePackage(
							FTD_TID_RtnNetMonitorTaskResultTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &resultField);
						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
						m_cFrontServer.m_pCurrOracleFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
					}
				}
				else
				{
					for (int i = 0, deta = 0; i < newresult.length(); i += deta)
					{
						deta = min(
							newresult.length() - i,
							sizeof(resultField.ResultChain) - 10);

						if (deta == (newresult.length() - i))
						{
							resultField.OperationType = 0;

							if (username.length() > 0)
							{
								string	str = cmdstr;
								str += "@";
								str += username;

								resultField.InstructChain = str.c_str();
							}
						}

						resultField.ResultChain = (newresult.substr(i, deta)).c_str();

						m_pkgSend.PreparePackage(
							FTD_TID_RtnNetMonitorTaskResultTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &resultField);
						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
						m_cFrontServer.m_pCurrOracleFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
					}
				}
			}
			else
			{
				printf(
					"impossible, m_mapTaskResult->second has no data for key:%s\n",
					key);
			}

			//����������������
			m_mapTaskResult.erase(t_it);
		}
		else
		{
			printf(
				"impossible, can't find info by key:%s from m_mapTaskResult\n",
				key);
		}
	}
}

/// key: hostid
/// value: montime
map<string, int> g_mHostMemInfo;
map<string, CFTDRtnObjectAttrField> g_mMemInfo;

#define PUSHINFOTOPACK	CFTDRtnObjectAttrField fieldInfo;			  \
	fieldInfo.MonDate = rtnItor->second.MonDate;					  \
	fieldInfo.MonTime = rtnItor->second.MonTime;					  \
	fieldInfo.ObjectID = rtnItor->second.ObjectID;					  \
	fieldInfo.ValueType = STRING_ATTR;								  \
	fieldInfo.AttrValue = sHostName.c_str();						  \
	fieldInfo.AttrType = rtnItor->second.AttrType;					  \
	strcat((char *)fieldInfo.AttrType.getValue(), APPATTRCENTERINFO); \
	FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);

void CEventCounterServer::OnRtnTopMemInfoTopic(CFTDCPackage *pFTDCPackage)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDRtnTopMemInfoField	fieldMemInfo;

	// ���������������� APPATTRCPUUSAGE ָ��,�� PuDian.os.CPUUsage
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnTopMemInfoField::m_Describe);
	float rate;
	bool bFirstFlag = true;
	map<string, CFTDRtnObjectAttrField>::iterator rtnItor;
	string	sHostName;

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldMemInfo);
		if (fieldMemInfo.TOTALREAL.getValue() +
			fieldMemInfo.FREE.getValue() == 0)
		{
			rate = 0.0;
		}
		else
		{
			//// Mod by Henchi, 20110113
			//// �����㷨������HP_UX����
			//rate = ((float)fieldMemInfo.ACTIVEREAL.getValue()/(fieldMemInfo.TOTALREAL.getValue()+fieldMemInfo.FREE.getValue()))*100.0;
			//// �����㷨������LINUX����
			//// ��ǰ�㷨��BUF��Cache�ڴ������ǿ��п����ڴ�
			rate =
				(
				(float)
				(
				fieldMemInfo.TOTALREAL.getValue() -
				fieldMemInfo.FREE.getValue()
				) /
				(fieldMemInfo.TOTALREAL.getValue())
				) *
				100.0;
		}

		if (bFirstFlag)
		{
			bFirstFlag = false;

			char *p = (char *)fieldMemInfo.HostName.getValue();
			if ((g_mHostFilterStr[0] != '\0')
				&&	(
				NULL != strstr(
				(char *)fieldMemInfo.HostName.getValue(),
				g_mHostFilterStr)
				))
			{
				MESSAGEPUSHFLOWCHGK;
				return;
			}

			char *q = strstr(p, ".os.");
			sHostName = q + 4;

			char mCenter[64];
			if (q != NULL)
			{
				memset(mCenter, 0, 64);
				strncpy(mCenter, p, q - p + 3);
				rtnItor = g_mMemInfo.find(mCenter);
				if (rtnItor == g_mMemInfo.end())
				{
					CFTDRtnObjectAttrField	temp;
					temp.ObjectID = mCenter;
					temp.AttrType = APPATTRMEMORYUSAGE;
					temp.MonDate = fieldMemInfo.MonDate;
					temp.MonTime = fieldMemInfo.MonTime;
					temp.ValueType = FLOAT_ATTR;
					sprintf((char *)temp.AttrValue.getValue(), "%2.4f", rate);
					g_mMemInfo.insert(make_pair(mCenter, temp));
					rtnItor = g_mMemInfo.find(mCenter);
				}
				else
				{
					if ((fieldMemInfo.MonDate == rtnItor->second.MonDate)
						&&	(fieldMemInfo.MonTime == rtnItor->second.MonTime)
						&&	(rate > atof(rtnItor->second.AttrValue.getValue())))
					{
						sprintf(
							(char *)rtnItor->second.AttrValue.getValue(),
							"%2.4f",
							rate);
						m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
						PUSHINFOTOPACK;

						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
						m_pkgSend.ValidPackage();
						m_cProbeServer.SendPackageAllSession(&m_pkgSend);
					}
					else if (fieldMemInfo.MonDate > rtnItor->second.MonDate
						||	 fieldMemInfo.MonTime > rtnItor->second.MonTime)
					{
						rtnItor->second.MonTime = fieldMemInfo.MonTime;
						rtnItor->second.MonDate = fieldMemInfo.MonDate;
						sprintf(
							(char *)rtnItor->second.AttrValue.getValue(),
							"%2.4f",
							rate);
						m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
						PUSHINFOTOPACK;

						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
						m_pkgSend.ValidPackage();
						m_cProbeServer.SendPackageAllSession(&m_pkgSend);
					}
				}
			}
		}
		else
		{	//����Ҫ������������
			if ((fieldMemInfo.MonDate == rtnItor->second.MonDate)
				&&	(fieldMemInfo.MonTime == rtnItor->second.MonTime)
				&&	(rate > atof(rtnItor->second.AttrValue.getValue())))
			{
				sprintf(
					(char *)rtnItor->second.AttrValue.getValue(),
					"%2.4f",
					rate);
				m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
				PUSHINFOTOPACK;

				m_pkgSend.MakePackage();
				m_cFrontServer.m_pCurrFrontFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());
				m_pkgSend.ValidPackage();
				m_cProbeServer.SendPackageAllSession(&m_pkgSend);
			}
			else if (fieldMemInfo.MonDate > rtnItor->second.MonDate
				||	 fieldMemInfo.MonTime > rtnItor->second.MonTime)
			{
				rtnItor->second.MonTime = fieldMemInfo.MonTime;
				rtnItor->second.MonDate = fieldMemInfo.MonDate;
				sprintf(
					(char *)rtnItor->second.AttrValue.getValue(),
					"%2.4f",
					rate);
				m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
				PUSHINFOTOPACK;

				m_pkgSend.MakePackage();
				m_cFrontServer.m_pCurrFrontFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());
				m_pkgSend.ValidPackage();
				m_cProbeServer.SendPackageAllSession(&m_pkgSend);
			}
		}

		itor.Next();
		if (itor.IsEnd())
		{
			/// Mod by Henchi 20111011
			/// ������������nowtime��С��lasttime���������������ʱ��ֵ
			map<string, int>::iterator	it = g_mHostMemInfo.find(
				string((const char *)fieldMemInfo.HostName));
			if (it == g_mHostMemInfo.end())
			{
				MESSAGEPUSHFLOWCHGK;

				int iDatetime = getTimeFromStr(
					(char *)fieldMemInfo.MonDate.getValue(),
					(char *)fieldMemInfo.MonTime.getValue());
				g_mHostMemInfo[string(
					(const char *)fieldMemInfo.HostName)] = iDatetime;
			}
			else
			{
				//			printf("Network [%s] [%s]\n",(const char *)it->first.c_str(),(const char *)it->second.c_str());
				int lastTime = it->second;
				int nowTime = getTimeFromStr(
					(char *)fieldMemInfo.MonDate.getValue(),
					(char *)fieldMemInfo.MonTime.getValue());
				if (nowTime - lastTime >= m_mOsInterval)
				{
					MESSAGEPUSHFLOWCHGK;
					it->second = nowTime;
				}
			}

			break;
		}
	}
}

/// key: hostid
/// value: montime
map<string, int> g_mHostCpuInfo;
map<string, CFTDRtnObjectAttrField> g_mCPUInfo;

void CEventCounterServer::OnRtnTopCpuInfoTopic(CFTDCPackage *pFTDCPackage)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	// ���������������� APPATTRCPUUSAGE ָ��,�� PuDian.os.CPUUsage
	CFTDRtnTopCpuInfoField	fieldCPUInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnTopCpuInfoField::m_Describe);
	bool bFirstFlag = true;
	map<string, CFTDRtnObjectAttrField>::iterator rtnItor;
	string	sHostName;
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldCPUInfo);
		if ((g_mHostFilterStr[0] != '\0')
			&&	(
			NULL != strstr(
			(char *)fieldCPUInfo.HostName.getValue(),
			g_mHostFilterStr)
			))
		{
			MESSAGEPUSHFLOWCHGK;
			return;
		}

		if (bFirstFlag)
		{
			bFirstFlag = false;

			char *p = (char *)fieldCPUInfo.HostName.getValue();
			char *q = strstr(p, ".os.");
			sHostName = q + 4;

			char mCenter[64];
			if (q != NULL)
			{
				memset(mCenter, 0, 64);
				strncpy(mCenter, p, q - p + 3);
				rtnItor = g_mCPUInfo.find(mCenter);
				if (rtnItor == g_mCPUInfo.end())
				{
					CFTDRtnObjectAttrField	temp;
					temp.ObjectID = mCenter;
					temp.AttrType = APPATTRCPUUSAGE;
					temp.MonDate = fieldCPUInfo.MonDate;
					temp.MonTime = fieldCPUInfo.MonTime;
					temp.ValueType = FLOAT_ATTR;
					sprintf(
						(char *)temp.AttrValue.getValue(),
						"%2.4f",
						fieldCPUInfo.USER.getValue());
					g_mCPUInfo.insert(make_pair(mCenter, temp));
					rtnItor = g_mCPUInfo.find(mCenter);
				}
				else
				{
					if ((fieldCPUInfo.MonDate == rtnItor->second.MonDate)
						&&	(fieldCPUInfo.MonTime == rtnItor->second.MonTime)
						&&	(
						fieldCPUInfo.USER.getValue() > atof(
						rtnItor->second.AttrValue.getValue())
						))
					{
						sprintf(
							(char *)rtnItor->second.AttrValue.getValue(),
							"%2.4f",
							fieldCPUInfo.USER.getValue());
						m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
						PUSHINFOTOPACK;

						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
						m_pkgSend.ValidPackage();
						m_cProbeServer.SendPackageAllSession(&m_pkgSend);
					}
					else if (fieldCPUInfo.MonDate > rtnItor->second.MonDate
						||	 fieldCPUInfo.MonTime > rtnItor->second.MonTime)
					{
						rtnItor->second.MonTime = fieldCPUInfo.MonTime;
						rtnItor->second.MonDate = fieldCPUInfo.MonDate;
						sprintf(
							(char *)rtnItor->second.AttrValue.getValue(),
							"%2.4f",
							fieldCPUInfo.USER.getValue());
						m_pkgSend.PreparePackage(
							FTD_TID_RtnObjectAttrTopic,
							FTDC_CHAIN_LAST,
							FTD_VERSION);
						FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
						PUSHINFOTOPACK;

						m_pkgSend.MakePackage();
						m_cFrontServer.m_pCurrFrontFlow->Append(
							m_pkgSend.Address(),
							m_pkgSend.Length());
						m_pkgSend.ValidPackage();
						m_cProbeServer.SendPackageAllSession(&m_pkgSend);
					}
				}
			}
		}
		else
		{	//����Ҫ������������
			if ((fieldCPUInfo.MonDate == rtnItor->second.MonDate)
				&&	(fieldCPUInfo.MonTime == rtnItor->second.MonTime)
				&&	(
				fieldCPUInfo.USER.getValue() > atof(
				rtnItor->second.AttrValue.getValue())
				))
			{
				sprintf(
					(char *)rtnItor->second.AttrValue.getValue(),
					"%2.4f",
					fieldCPUInfo.USER.getValue());
				m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
				PUSHINFOTOPACK;
				m_pkgSend.MakePackage();
				m_cFrontServer.m_pCurrFrontFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());
				m_pkgSend.ValidPackage();
				m_cProbeServer.SendPackageAllSession(&m_pkgSend);
			}
			else if (fieldCPUInfo.MonDate > rtnItor->second.MonDate
				||	 fieldCPUInfo.MonTime > rtnItor->second.MonTime)
			{
				rtnItor->second.MonDate = fieldCPUInfo.MonDate;
				rtnItor->second.MonTime = fieldCPUInfo.MonTime;
				sprintf(
					(char *)rtnItor->second.AttrValue.getValue(),
					"%2.4f",
					fieldCPUInfo.USER.getValue());
				m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &(rtnItor->second));
				PUSHINFOTOPACK;
				m_pkgSend.MakePackage();
				m_cFrontServer.m_pCurrFrontFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());
				m_pkgSend.ValidPackage();
				m_cProbeServer.SendPackageAllSession(&m_pkgSend);
			}
		}

		itor.Next();
		if (itor.IsEnd())
		{
			/// Mod by Henchi 20111011
			/// ������������nowtime��С��lasttime���������������ʱ��ֵ
			map<string, int>::iterator	it = g_mHostCpuInfo.find(
				string((const char *)fieldCPUInfo.HostName));
			if (it == g_mHostCpuInfo.end())
			{
				MESSAGEPUSHFLOWCHGK;

				int iDatetime = getTimeFromStr(
					(char *)fieldCPUInfo.MonDate.getValue(),
					(char *)fieldCPUInfo.MonTime.getValue());
				g_mHostCpuInfo[string(
					(const char *)fieldCPUInfo.HostName)] = iDatetime;
			}
			else
			{
				//			printf("Network [%s] [%s]\n",(const char *)it->first.c_str(),(const char *)it->second.c_str());
				int lastTime = it->second;
				int nowTime = getTimeFromStr(
					(char *)fieldCPUInfo.MonDate.getValue(),
					(char *)fieldCPUInfo.MonTime.getValue());
				if (nowTime - lastTime >= m_mOsInterval)
				{
					MESSAGEPUSHFLOWCHGK;
					it->second = nowTime;
				}
			}

			break;
		}
	}
}

// DBSEPARATORSTRING

// DBSEPARATORRECORD
void seprateString(char *pSrc, vector<string> &strList)
{
	char *pBegin = pSrc;

	char *pEnd;
	while ((pEnd = strstr(pBegin, DBSEPARATORSTRING)) != NULL)
	{
		*pEnd = '\0';
		strList.push_back(pBegin);
		pBegin = pEnd + 3;
	}

	strList.push_back(pBegin);
	return;
}

typedef vector<string>	T_strvector;
void CEventCounterServer::OnRtnDBQueryTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnDBQueryField fieldDBQueryInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldDBQueryInfo))
	{
		// Added by Henchi, 20091228
		if (strstr(
			fieldDBQueryInfo.ObjectID.getValue(),
			DOTDATACENTERAPACHEDOT) != NULL)
		{
			OnRtnDBQueryAccessLog(pFTDCPackage);
			return;
		}

		map<string, T_strmap>::const_iterator clmIt = m_mapRtnDBQueryClomn.find(
			(const char *)fieldDBQueryInfo.AttrType);
		if (clmIt == m_mapRtnDBQueryClomn.end())
		{
			return;
		}

		char resultBuffer[FTDC_PACKAGE_MAX_SIZE];
		strcpy(resultBuffer, (const char *)fieldDBQueryInfo.DBQueryResult);

		char *pLineBegin = resultBuffer;

		char *pLineEnd;
		vector<string>	strList;
		vector<T_strvector> listVector;
		string	evtDes;
		while ((pLineEnd = strstr(pLineBegin, DBSEPARATORRECORD)) != NULL)
		{
			*pLineEnd = '\0';
			strList.clear();
			seprateString(pLineBegin, strList);
			listVector.push_back(strList);
			pLineBegin = pLineEnd + 2;
		}

		if (*pLineBegin != '\0')
		{
			strList.clear();
			seprateString(pLineBegin, strList);
			listVector.push_back(strList);
		}

		if (listVector.size() <= 1) ///������������ֱ�ӷ���
		{
			return;
		}

		CFTDRtnSyslogEventField fieldInfo;
		fieldInfo.MonDate = fieldDBQueryInfo.MonDate;
		fieldInfo.MonTime = fieldDBQueryInfo.MonTime;
		fieldInfo.OccurTime = fieldDBQueryInfo.MonTime;
		fieldInfo.EventName = fieldDBQueryInfo.AttrType;
		fieldInfo.ObjectID = fieldDBQueryInfo.ObjectID;
		fieldInfo.ProcessFlag = "L";
		fieldInfo.WarningLevel = "Info";

		int nEventSeries;
		g_cEventProcess.getEventDesc(
			(const char *)fieldInfo.ObjectID,
			(const char *)fieldInfo.EventName,
			nEventSeries);
		fieldInfo.EventNum = nEventSeries;
		for (map<string, string>::const_iterator strIt = clmIt->second.begin()
			;
			strIt != clmIt->second.end();
		strIt++)
		{
			int keyPos = -1;

			int atdPos = -1;
			for (int i = 0; i < listVector[0].size(); i++)
			{
				//printf("%s\n", listVector[0][i].c_str());
				if (listVector[0][i] == strIt->first)
				{
					keyPos = i;
				}

				if (listVector[0][i] == strIt->second)
				{
					atdPos = i;
				}
			}

			for (int i = 1; i < listVector.size(); i++)
			{
				//printf("%d %s %s\n",i, listVector[i][keyPos].c_str(), listVector[i][atdPos].c_str());
				if (listVector[0].size() != listVector[i].size())
				{
					continue;
				}

				evtDes = strIt->first;
				evtDes.append("='");
				evtDes.append(listVector[i][keyPos]);
				evtDes.append("','");
				evtDes.append(listVector[i][atdPos]);
				evtDes.append("'");

				//printf("[%s]\n", evtDes.c_str());
				fieldInfo.EvendID = m_mSyslogEventId++;
				fieldInfo.EventDes = evtDes.c_str();
				m_pEventBuffer->writeNode(&fieldInfo);
			}
		}
	}

	return;
}

/// key: hostid
/// value: montime
map<string, int> g_mHostNetworkInfo;
void CEventCounterServer::OnRtnNetworkInfoTopic(CFTDCPackage *pFTDCPackage)
{
	bool bUpFlag = true;
	CFTDRtnNetworkInfoField fieldNetworkInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldNetworkInfo);
		if (!strcmp(fieldNetworkInfo.LANSTATUS.getValue(), LANSTATUSDOWN))
		{
			CWriteableMonitorEntity theMonitorEntity;
			char sOsId[65];
			char *pCurr;
			strcpy(sOsId, fieldNetworkInfo.HostName.getValue());
			pCurr = strrchr(sOsId, '.');
			if (pCurr != NULL)
			{
				*pCurr = '\0';
			}

			//while ((pCurr=strchr(sOsId, '-'))!=NULL)
			//{
			//	*pCurr = '_';
			//}
			CFTDRtnObjectAttrField	fieldAttr;
			fieldAttr.ObjectID = sOsId;
			fieldAttr.AttrType = "LANSTATUS";
			fieldAttr.MonDate = fieldNetworkInfo.MonDate;
			fieldAttr.MonTime = fieldNetworkInfo.MonTime;
			fieldAttr.ValueType = STRING_ATTR;
			fieldAttr.AttrValue = LANSTATUSDOWN;
			m_pNodeBuffer->writeNode(&fieldAttr);
			bUpFlag = false;
		}

		itor.Next();
		if (itor.IsEnd())
		{
			if (bUpFlag)
			{
				CWriteableMonitorEntity theMonitorEntity;
				char sOsId[65];
				char *pCurr;
				strcpy(sOsId, fieldNetworkInfo.HostName.getValue());
				pCurr = strrchr(sOsId, '.');
				if (pCurr != NULL)
				{
					*pCurr = '\0';
				}

				CFTDRtnObjectAttrField	fieldAttr;
				fieldAttr.ObjectID = sOsId;
				fieldAttr.AttrType = "LANSTATUS";
				fieldAttr.MonDate = fieldNetworkInfo.MonDate;
				fieldAttr.MonTime = fieldNetworkInfo.MonTime;
				fieldAttr.ValueType = STRING_ATTR;
				fieldAttr.AttrValue = fieldNetworkInfo.LANSTATUS;
				m_pNodeBuffer->writeNode(&fieldAttr);
			}

			/// Mod by Henchi 20111011
			/// ������������nowtime��С��lasttime���������������ʱ��ֵ
			map<string, int>::iterator	it = g_mHostNetworkInfo.find(
				string((const char *)fieldNetworkInfo.HostName));
			if (it == g_mHostNetworkInfo.end())
			{
				MESSAGEPUSHFLOWCHGK;

				int iDatetime = getTimeFromStr(
					(char *)fieldNetworkInfo.MonDate.getValue(),
					(char *)fieldNetworkInfo.MonTime.getValue());
				g_mHostNetworkInfo[string(
					(const char *)fieldNetworkInfo.HostName)] = iDatetime;
			}
			else
			{
				//			printf("Network [%s] [%s]\n",(const char *)it->first.c_str(),(const char *)it->second.c_str());
				int lastTime = it->second;
				int nowTime = getTimeFromStr(
					(char *)fieldNetworkInfo.MonDate.getValue(),
					(char *)fieldNetworkInfo.MonTime.getValue());
				if (nowTime - lastTime >= m_mOsInterval)
				{
					MESSAGEPUSHFLOWCHGK;
					it->second = nowTime;
				}
			}

			break;
		}
	}
}

void CEventCounterServer::OnRtnSyslogInfoTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDSysFileAccessInfoField	fieldAccessInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldAccessInfo))
	{
		if ((int)fieldAccessInfo.FileTime.getValue() > 0)
		{
			m_threadFiler.WriteKeyValue(
				(char *)fieldAccessInfo.ObjectID.getValue(),
				(long)fieldAccessInfo.FileSize.getValue(),
				(int)fieldAccessInfo.FileTime.getValue(),
				false);
		}
	}

	CFTDRtnSyslogInfoField	fieldSyslogInfo;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldSyslogInfo))
	{
		char *p = (char *)fieldSyslogInfo.ObjectID.getValue();

		/* 20090604 comment by zhou.jj
		if (strcmp(p+strlen(fieldSyslogInfo.ObjectID.getValue())-strlen(HOSTATTRAPPLOG), HOSTATTRAPPLOG)==0)
		{
		OnRtnSyslogInfoApplog(pFTDCPackage);
		return;
		} else
		*/
		if (strcmp(
			p + strlen(fieldSyslogInfo.ObjectID.getValue()) - strlen(
			HOSTATTRSYSLOG),
			HOSTATTRSYSLOG) == 0)
		{
			OnRtnSyslogInfoSyslog(pFTDCPackage);
			return;
		}
		else if (strcmp(
			p + strlen(fieldSyslogInfo.ObjectID.getValue()) - strlen(
			HOSTATTRKEYFILE),
			HOSTATTRKEYFILE) == 0)
		{
			OnRtnSyslogInfoKeyfile(pFTDCPackage);
			return;
		}
		else if (strcmp(
			p + strlen(fieldSyslogInfo.ObjectID.getValue()) - strlen(
			HOSTATTRSESSIONLOG),
			HOSTATTRSESSIONLOG) == 0)
		{
			OnRtnSyslogInfoSessionlog(pFTDCPackage);
			return;
		}
		else
		{
			printf(
				"\t CEventSubscriber::OnRtnSyslogInfoTopic Recv unknown Package! %s\n",
				p);
		}
	}
}

#ifdef SESSIONLOG_TOFILE_DEBUG
int g_FileSize = 0;
FILE *g_testfp = NULL;
#endif
void CEventCounterServer::OnRtnSyslogInfoSessionlog(CFTDCPackage *pFTDCPackage)
{
#ifdef SESSIONLOG_TOFILE_DEBUG
	int i = 0;
	CFTDRtnSyslogInfoField	fieldSyslogInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnSyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		i++;
		itor.Retrieve(&fieldSyslogInfo);

		//printf("CAgentConnector::OnRtnSyslogInfoApplog:fieldSyslogInfo.FileContent [==%s==]\n",p);
		if (g_testfp == NULL)
		{
			g_testfp = fopen("d:\\eventrecv.log", "wb");
		}

		int tt = fwrite(
			(char *)fieldSyslogInfo.FileContent.getValue(),
			1,
			(const int)fieldSyslogInfo.ContLen,
			g_testfp);
		fflush(g_testfp);
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}	// while (!itor.IsEnd()) end
#endif
	MESSAGEPUSHSLOGFLOW;
}

void CEventCounterServer::OnRtnSyslogInfoSyslog(CFTDCPackage *pFTDCPackage)
{
	MESSAGEPUSHFLOW;
}

void CEventCounterServer::OnRtnSyslogInfoKeyfile(CFTDCPackage *pFTDCPackage)
{
	MESSAGEPUSHFLOW;
}

void CEventCounterServer::OnRtnDBQueryAccessLog(CFTDCPackage *pFTDCPackage)
{
	MESSAGEPUSHQUERYFLOW;
}

void CEventCounterServer::OnRtnNetLocalPingResultTaskTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetLocalPingResultInfoField	field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&(CFTDRtnNetLocalPingResultInfoField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnNetLocalPingResultInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		m_pkgSend.MakePackage();

		m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
		m_cFrontServer.m_pCurrOracleFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());

		itor.Next();
	}
}

void CEventCounterServer::OnRtnNetRemotePingResultTaskTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetRomotePingResultInfoField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&(CFTDRtnNetRomotePingResultInfoField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		m_pkgSend.PreparePackage(
			FTD_TID_RtnNetRomotePingResultInfoTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		FTDC_ADD_FIELD(&m_pkgSend, &field);
		m_pkgSend.MakePackage();

		m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
		m_cFrontServer.m_pCurrOracleFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());

		itor.Next();
	}
}

//�����¼���������
void CEventCounterServer::UpdateWarningCount(CFTDRtnWarningEventField &event)
{
	if (event.ProcessFlag != "N")
	{
		return;
	}

	map<string, map<string, int> >::iterator e_it = g_eventID2NameList.find(
		event.ObjectID.getValue());
	if (e_it != g_eventID2NameList.end())
	{
		//��ͬobjectid
		map<string, int>::iterator	n_it = e_it->second.find(
			event.EventName.getValue());
		if (n_it != e_it->second.end())
		{
			//��ͬ�¼���
			map<int, list<CFTDRtnWarningEventField> >::iterator it =
				g_listWarningEvent.find(event.EventNum);
			if (it != g_listWarningEvent.end())
			{
				//��ͬeventnum
				it->second.push_back(event);
			}
		}
		else
		{
			//��ͬ�¼���
			e_it->second[event.EventName.getValue()] = 1;

			list<CFTDRtnWarningEventField>	theList;
			theList.push_back(event);
			g_listWarningEvent[event.EventNum] = theList;
		}
	}
	else
	{
		//��ͬobjectid
		map<string, int> namemap;
		namemap[event.EventName.getValue()] = 1;

		g_eventID2NameList[event.ObjectID.getValue()] = namemap;

		list<CFTDRtnWarningEventField>	theList;
		theList.push_back(event);
		g_listWarningEvent[event.EventNum] = theList;
	}
}

//��ȡ�¼���������
int CEventCounterServer::GetWarningCount(CFTDRtnWarningEventField &event)
{
	int eventOccurNumber = 0;

	map<int, list<CFTDRtnWarningEventField> >::iterator itEvent =
		g_listWarningEvent.find(event.EventNum);
	if (itEvent != g_listWarningEvent.end())
	{
		CDateType theDate;
			time_t	timep;
			time(&timep);

			struct tm tm_time;
			LocalTime(&timep, &tm_time);
			sprintf(
				(char *)theDate.getValue(),
				"%04d%02d%02d",
				tm_time.tm_year + 1900,
				tm_time.tm_mon + 1,
				tm_time.tm_mday);

		list<CFTDRtnWarningEventField>::iterator itList = itEvent->second.begin();
		for (; itList != itEvent->second.end(); itList++)
		{
			if (itList->OccurDate == theDate)
			{
				eventOccurNumber++;
			}
		}
	}

	return eventOccurNumber;
}

void CEventCounterServer::OnRspQryNetMonitorTaskResultTopic(
	CFTDCPackage *pFTDCPackage)
{
	CFTDRspQryNetMonitorTaskResultField field;

	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&(CFTDRspQryNetMonitorTaskResultField::m_Describe));

	while (!itor.IsEnd())
	{
		itor.Retrieve(&field);

		string	key = field.ObjectID.getValue();
		key += "_";
		key += field.MonDate.getValue();
		key += "_";
		key += field.MonTime.getValue();

		map<string, string>::iterator it = m_mapConfigContent.find(key);
		if (it != m_mapConfigContent.end())
		{
			it->second += field.ResultChain.getValue();
		}
		else
		{
			m_mapConfigContent[key] = field.ResultChain.getValue();
		}

		itor.Next();
	}

	if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST)
	{
		string	key = field.ObjectID.getValue();
		key += "_";
		key += field.MonDate.getValue();
		key += "_";
		key += field.MonTime.getValue();

		map<string, string>::iterator it = m_mapConfigContent.find(key);
		if (it != m_mapConfigContent.end())
		{
			//�����һ���ļ����ݽ��бȽ�
			//��س��ļ�,��ǵĲ�һ�����ļ�  20130222 by Lee
			int ret = CheckFileVersion(
				field.ObjectID.getValue(),
				it->second,
				field.MonDate.getValue(),
				field.MonTime.getValue());

			CFTDRtnNetMonitorTaskResultField fieldInfo;
			memset(&fieldInfo, 0, sizeof(fieldInfo));

			fieldInfo.ObjectID = field.ObjectID.getValue();
			fieldInfo.Task_ID = field.Task_ID.getValue();
			fieldInfo.OperateTime = field.Flag.getValue();// ��¼ִ�д��� field.OperateTime.getValue();
			fieldInfo.InstructChain = "RunningConfig";
			fieldInfo.MonDate = field.MonDate.getValue();
			fieldInfo.MonTime = field.MonTime.getValue();
			fieldInfo.Flag = (ret==0) ? TASK_CONFIG_MATCH:TASK_CONFIG_DISMATCH;

			m_pkgSend.PreparePackage(
				FTD_TID_RtnNetMonitorTaskResultTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);

			if (m_pkgSend.Length() + sizeof
				(CFTDRtnNetMonitorTaskResultField) >= FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.MakePackage();
				m_cFrontServer.m_pCurrFrontFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());
				m_pkgSend.PreparePackage(
					FTD_TID_RtnNetMonitorTaskResultTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &fieldInfo);
			m_pkgSend.MakePackage();
			m_cFrontServer.m_pCurrFrontFlow->Append(
				m_pkgSend.Address(),
				m_pkgSend.Length());

			printf("debug send running config result: object=[%s],taskid=[%d],times=[%d], \
				   InstructChain=[%s],MonDate=[%s],MonTime=[%s],Flag=[%d]\n",
				   fieldInfo.ObjectID.getValue(),
				   fieldInfo.Task_ID.getValue(),
				   fieldInfo.OperateTime.getValue(),
				   fieldInfo.InstructChain.getValue(),
				   fieldInfo.MonDate.getValue(),
				   fieldInfo.MonTime.getValue(),
				   fieldInfo.Flag.getValue());

			//1����س���ʱ�ļ�
			//2�������ļ��ȶ�
			//3�������б�ǵ��ļ�
			//LogConfigInfo(
			//	field.ObjectID.getValue(),
			//	it->second,
			//	field.Flag.getValue(),
			//	field.MonDate.getValue(),
			//	field.MonTime.getValue());

			m_mapConfigContent.erase(it);
		}
		else
		{
			printf("can't find cached file by key:%s\n", key.c_str());
		}
	}
}

void CEventCounterServer::OnRtnBaseLineTaskTopic(CFTDCPackage *pFTDCPackage)
{
	CFTDRtnNetBaseLineTaskField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnNetBaseLineTaskField::m_Describe);

	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);

		/*		
		///test code start
		fieldInfo.OperationType = TASK_SUCCESS;
		fieldInfo.BaseLineIDList = "1";
		fieldInfo.DeviceIDList = "2";
		fieldInfo.GenDate = "20120606";
		fieldInfo.GenTime = "12:00:06";
		fieldInfo.GenUser = "admin";
		///test code end
		*/
		NET_DEVICE_MAP_ITERATOR d_it = m_cConfigConnector.GetDeviceMap().find(
			atoi(fieldInfo.DeviceIDList.getValue()));

		string	devobjid;
		string	devname;
		string	ipaddr;

		if (d_it != m_cConfigConnector.GetDeviceMap().end())
		{
			devobjid = d_it->second.ObjectID.getValue();
			devname = d_it->second.NAME.getValue();
			ipaddr = d_it->second.IPADDR.getValue();
		}

		vector<string>	baselineids;

		CConfigConnector::splitStringBySeprator(
			fieldInfo.BaseLineIDList.getValue(),
			";",
			baselineids);

		for (int i = 0; i < baselineids.size(); ++i)
		{
			string	baselinename;
			NET_BASELINE_MAP_ITERATOR b_i = m_cConfigConnector.GetBaseLineMap()
				.find(atoi(baselineids[i].c_str()));
			if (b_i != m_cConfigConnector.GetBaseLineMap().end())
			{
				baselinename = b_i->second.name;
			}

			if (TASK_SUCCESS == fieldInfo.OperationType.getValue())
			{
				string	strFile = m_sFilePath;

				if (d_it == m_cConfigConnector.GetDeviceMap().end())
				{
					printf(
						"can't find device by id:%d in %s\n",
						atoi(fieldInfo.DeviceIDList.getValue()),
						__FUNCTION__);

					itor.Next();
					if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST
						&&	itor.IsEnd())
					{
						break;
					}
					else
					{
						continue;
					}
				}

				strFile += devobjid;

#ifdef WIN32
				strFile += "\\";
#else
				strFile += "/";
#endif

				//�����豸���µ������ļ�
				map<string, vector<ConfigFileInfo> >::iterator	it =
					g_mapConfigFileList.find(devobjid);
				if (it != g_mapConfigFileList.end())
				{
					string	filecontent;

					//����beforeָ����ʱ��֮ǰ���ļ���Ϣ
					int delta_before = -999999999;
					string	filename_before;

					time_t	curtime = time(NULL);

					for (int j = 0; j < it->second.size(); ++j)
					{
						struct tm m_mTime;
						m_mTime.tm_mday = atoi(it->second[j].filedate.c_str()) % 100;
						m_mTime.tm_mon =
							(
							atoi(it->second[j].filedate.c_str()) %
							10000
							) /
							100 -
							1;
						m_mTime.tm_year =
							(atoi(it->second[j].filedate.c_str())) /
							10000 -
							1900;

						string	montime = it->second[j].filetime;

						m_mTime.tm_sec = atoi(montime.substr(4, 2).c_str());
						m_mTime.tm_min = atoi(montime.substr(2, 2).c_str());
						m_mTime.tm_hour = atoi(montime.substr(0, 2).c_str());

						time_t	filetime = mktime(&m_mTime);

						int diff = filetime - curtime;
						if (diff <= 0)
						{
							//�뵱ǰʱ��������ļ�
							if (diff > delta_before)
							{
								delta_before = diff;

								filename_before = it->second[j].filename;
							}
						}
					}

					if (filename_before.length() == 0)
					{
						printf(
							"impossible, no config file before now for objectid:%s\n",
							devobjid.c_str());
					}
					else
					{
						string	beforeFilePath = strFile;
						beforeFilePath += filename_before;

						filecontent = GetFileContent(beforeFilePath);

						//���һ�����Ϣ
						if (b_i == m_cConfigConnector.GetBaseLineMap().end())
						{
							printf(
								"can't find baseline info by id:%d\n",
								atoi(baselineids[i].c_str()));
						}
						else
						{
							//���бȶ�
							string	rtncontent = BaseLineComare(
								b_i->second.data,
								filecontent);

							/*	///test code start
							FILE *fp = fopen("c:\\rtnresult.txt", "wb");
							fwrite(rtncontent.c_str(), 1, rtncontent.length(), fp);
							fclose(fp);
							///test code end
							*/
							//�����д��query	
							CFTDRtnNetBaseLineResultField resultField;
							memset(&resultField, 0, sizeof(resultField));

							resultField.ID = fieldInfo.ID;
							resultField.BaseLineName = baselinename.c_str();

							resultField.DeviceObjID = devname.c_str();
							resultField.DeviceIP = ipaddr.c_str();
							resultField.GenDate = fieldInfo.GenDate.getValue();
							resultField.GenTime = fieldInfo.GenTime.getValue();
							resultField.GenUser = fieldInfo.GenUser.getValue();
							resultField.Flag = 0;

							for (int k = 0, deta = 0;
								k < rtncontent.length();
								k += deta)
							{
								deta = min(
									rtncontent.length() - k,
									sizeof(resultField.Result) - 1);

								if (deta == rtncontent.length() - k)
								{
									//���һ����
									if (k == 0)
									{
										resultField.Flag = 2;
									}
									else
									{
										resultField.Flag = 1;
									}
								}

								resultField.Result = (rtncontent.substr(k, deta)).c_str();

								m_pkgSend.PreparePackage(FTD_TID_RtnNetBaseLineResultTopic
									,FTDC_CHAIN_LAST,FTD_VERSION);
								FTDC_ADD_FIELD(&m_pkgSend, &resultField);

								m_pkgSend.MakePackage();
								m_cFrontServer.m_pCurrOracleFlow->Append(
									m_pkgSend.Address(),
									m_pkgSend.Length());
							}
						}
					}
				}
				else
				{
					printf(
						"impossible, no config file for objectid:%s\n",
						devobjid.c_str());
				}
			}
			else
			{
				//�����д��query	
				CFTDRtnNetBaseLineResultField resultField;
				memset(&resultField, 0, sizeof(resultField));

				resultField.ID = fieldInfo.ID;
				resultField.BaseLineName = baselinename.c_str();

				resultField.DeviceObjID = devname.c_str();
				resultField.DeviceIP = ipaddr.c_str();

				resultField.GenDate = fieldInfo.GenDate.getValue();
				resultField.GenTime = fieldInfo.GenTime.getValue();
				resultField.GenUser = fieldInfo.GenUser.getValue();
				resultField.Flag = 2;

				switch (fieldInfo.OperationType.getValue())
				{
				case TASK_CONNECT_FAIL:
					resultField.Result = "Task Exec Fail:Connect Fail";
					break;
				case TASK_USERNAME_ERROR:
					resultField.Result = "Task Exec Fail:UserName Error";
					break;
				case TASK_USERPASSWD_ERROR:
					resultField.Result = "Task Exec Fail:UserPasswd Error";
					break;
				case TASK_USERCOMMAND_FAIL:
					resultField.Result = "Task Exec Fail:UserCommand Fail";
					break;
				case TASK_ADMINPASSWD_ERROR:
					resultField.Result = "Task Exec Fail:AdminPasswd Error";
					break;
				case TASK_ADMINCOMMAND_ERROR:
					resultField.Result = "Task Exec Fail:AdminCommand Error";
					break;
				default:
					resultField.Result = "Task Exec Fail:Other Error";
					break;
				}

				m_pkgSend.PreparePackage(FTD_TID_RtnNetBaseLineResultTopic
					,FTDC_CHAIN_LAST,FTD_VERSION);
				FTDC_ADD_FIELD(&m_pkgSend, &resultField);

				m_pkgSend.MakePackage();
				m_cFrontServer.m_pCurrOracleFlow->Append(
					m_pkgSend.Address(),
					m_pkgSend.Length());
			}
		}

		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}
}

string CEventCounterServer::BaseLineComare(
	string	basecontent,
	string	curcontent)
{
	string	rtncontent;

	vector<string>	blocks;

	//���зָ���
	CConfigConnector::splitStringBySeprator(basecontent, "\r\n", blocks);
	for (int i = 0; i < blocks.size(); ++i)
	{
		if (blocks[i].size() == 0)
		{
			continue;
		}

		if (blocks[i][0] == '-')
		{
			//-��ʾ���б���û��
			if (curcontent.find(blocks[i]) != string::npos)
			{
				rtncontent += "[-]\r\n";
				rtncontent += blocks[i];
				continue;
			}
		}
		else
		{
			string	oriblock = blocks[i];

			//�滻ͨ���
			size_t	pos = blocks[i].find("$*");
			while (pos != string::npos)
			{
				blocks[i].replace(pos, 2, "[^ \t]+");

				pos = blocks[i].find("$*");
			}

			int j = 0;
			if (blocks[i][j] == '+')
			{
				//����+
				++j;
			}

			string	regexstr = "^.*";
			regexstr += blocks[i].substr(j);
			regexstr += ".*$";

			if (CRegexConfigManager::Instance()->RegexSearch(
				regexstr,
				curcontent) != 0)
			{
				if (blocks[i].find("[^ \t]+") != string::npos
					||	blocks[i].find("|") != string::npos
					||	blocks[i].find(")") != string::npos)
				{
					rtncontent += "[=]\r\n";
				}
				else
				{
					rtncontent += "[+]\r\n";
				}

				rtncontent += oriblock;
				rtncontent += "\r\n\r\n";
				continue;
			}
		}
	}

	return rtncontent;
}

///�����ʽ�еı����滻Ϊ��Ӧ��ֵ
string CEventCounterServer::ReplaceAttrByValue(
	vector<AttrNodeInfo> &attr_value,
	string	expr)
{
	string	expr_new = expr;

	for (int i = 0; i < attr_value.size(); ++i)
	{
		//�������еı����滻�ɾ����ֵ,�ַ���ͳһ�ɴ�д��ʽ
		string	upperresult = attr_value[i].value;
		transform(
			attr_value[i].value.begin(),
			attr_value[i].value.end(),
			upperresult.begin(),
			::toupper);

		if (upperresult.length() > 100)
		{
			//�ַ���̫��������MD5ֵ������
			char nowDigest[MD5_DIGEST_LEN * 2 + 1];
			GenMD5(
				(char *)upperresult.c_str(),
				upperresult.length(),
				nowDigest);

			upperresult = "\"";
			upperresult += nowDigest;
			upperresult += "\"";
		}

		ReplayString(expr_new, attr_value[i].key, upperresult, expr_new);
	}

	return expr_new;
}

int CEventCounterServer::LogConfigInfo(
	string	objectid,
	string	buffer,
	int version,
	string	filedate,
	string	filetime)
{
	//ȥ��":"
	char newtime[10] = { 0 };
	int i;
	int j;
	for (i = 0, j = 0; i < filetime.size() && j < 10; ++i)
	{
		if (filetime[i] != ':')
		{
			newtime[j++] = filetime[i];
		}
	}

	string	szFileName = objectid;
	szFileName += "_";
	szFileName += filedate;
	szFileName += "_";
	szFileName += newtime;

	//�����ļ��б仯�������
	if (version != 10)	//CFG_DIS_MATCH
	{
		szFileName += "(0)";
	}

	szFileName += ".txt";

	string	szFilePath = m_sFilePath + objectid;

	//����Ŀ¼
	CreatePath(szFilePath.c_str());

	szFilePath += "/";
	szFilePath += szFileName;

	FILE *m_fOutput = fopen(szFilePath.c_str(), "w");
	if (!m_fOutput)
	{
		printf(
			"open file %s fail in  CEventCounterServer::LogConfigInfo, errno=%d, reason=%s\n",
			szFilePath.c_str(),
			errno,
			strerror(errno));
		return -1;
	}

	fprintf(m_fOutput, "%s", buffer.c_str());
	fflush(m_fOutput);

	fclose(m_fOutput);

	ConfigFileInfo	fileinfo;

	fileinfo.filename = szFileName;
	fileinfo.filedate = filedate;
	fileinfo.filetime = newtime;

	map<string, vector<ConfigFileInfo> >::iterator	it = g_mapConfigFileList.
		find(objectid);
	if (it == g_mapConfigFileList.end())
	{
		vector<ConfigFileInfo>	configvec;
		configvec.push_back(fileinfo);

		g_mapConfigFileList[objectid] = configvec;
	}
	else
	{
		it->second.push_back(fileinfo);
	}

	return 0;
}

void CEventCounterServer::LoadConfigFileList(void)
{
#ifdef WIN32
	char szFind[MAX_PATH];
	WIN32_FIND_DATA FindFileData;
	char szFile[MAX_PATH];

	strcpy(szFind, m_sFilePath.c_str());
	strcat(szFind, "\\*.*");

	HANDLE	hFind = FindFirstFile(szFind, &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		printf(
			"Invalid file handle for dir:%s. Error is %u ",
			m_sFilePath.c_str(),
			GetLastError());
		return;
	}

	while (TRUE)
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			//������Ŀ¼�µ�����Ŀ¼
			if (strcmp(FindFileData.cFileName, ".") != 0
				&&	strcmp(FindFileData.cFileName, "..") != 0)
			{
				//������Ŀ¼�µ������ļ�
				string	subdir = m_sFilePath;
				subdir += "/";
				subdir += FindFileData.cFileName;
				subdir += "\\*.*";

				WIN32_FIND_DATA FindSubFileData;
				HANDLE	hSubFind = FindFirstFile(
					subdir.c_str(),
					&FindSubFileData);
				if (INVALID_HANDLE_VALUE == hSubFind)
				{
					printf(
						"Invalid file handle for dir:%s. Error is %u \n",
						subdir.c_str(),
						GetLastError());
					continue;
				}

				while (TRUE)
				{
					if (FindSubFileData.dwFileAttributes &
						FILE_ATTRIBUTE_ARCHIVE)
					{
						string	objectid = FindFileData.cFileName;
						string	datetime = FindSubFileData.cFileName;

						size_t	pos_time = datetime.rfind("_");
						if (pos_time == string::npos)
						{
							printf(
								"invalid file name:%s in %s\n",
								FindSubFileData.cFileName,
								__FUNCTION__);
							continue;
						}

						size_t	pos_dot = datetime.rfind(".");
						if (pos_dot == string::npos)
						{
							printf(
								"invalid file name:%s in %s\n",
								FindSubFileData.cFileName,
								__FUNCTION__);
							continue;
						}

						//�ļ������б仯
						if (datetime[pos_dot - 1] == ')')
						{
							pos_dot -= strlen("(0)");
						}

						string	time = datetime.substr(
							pos_time + 1,
							pos_dot - pos_time - 1);
						size_t	pos_date = datetime.substr(0, pos_time).rfind(
							"_");
						if (pos_date == string::npos)
						{
							printf(
								"invalid file name:%s in %s\n",
								FindSubFileData.cFileName,
								__FUNCTION__);
							continue;
						}

						string	date = datetime.substr(0, pos_time).substr(
							pos_date + 1);

						ConfigFileInfo	fileinfo;
						fileinfo.filename = FindSubFileData.cFileName;

						fileinfo.filedate = date;
						fileinfo.filetime = time;

						map<string, vector<ConfigFileInfo> >::iterator	it =
							g_mapConfigFileList.find(objectid);
						if (it == g_mapConfigFileList.end())
						{
							vector<ConfigFileInfo>	configvec;
							configvec.push_back(fileinfo);

							g_mapConfigFileList[objectid] = configvec;
						}
						else
						{
							it->second.push_back(fileinfo);
						}
					}

					if (!FindNextFile(hSubFind, &FindSubFileData))	//Ѱ����һ���ļ�
					{
						break;
					}
				}

				FindClose(hSubFind);				//�رվ��
			}
		}

		if (!FindNextFile(hFind, &FindFileData))	//Ѱ����һ���ļ�
		{
			break;
		}
	}

	FindClose(hFind);					//�رվ��
#else
	DIR *pDir = opendir(m_sFilePath.c_str());
	if (pDir == NULL)
	{
		printf("Failed to open dir %s\n", m_sFilePath.c_str());
		return false;
	}

	struct dirent *pstDirent;

	while (pDir != NULL && (pstDirent = readdir(pDir)))
	{
		if ((strcmp(pstDirent->d_name, ".") == 0)
			||	(strcmp(pstDirent->d_name, "..") == 0))
		{
			continue;
		}

		string	subdir = m_sFilePath;
		subdir += pstDirent->d_name;

		DIR *pSubDir = opendir(subdir.c_str());
		if (NULL == pSubDir)
		{
			printf("Failed to open subdir %s\n", subdir.c_str());
			continue;
		}

		struct dirent *pstSubDirent;

		while (pSubDir != NULL && (pstSubDirent = readdir(pSubDir)))
		{
			if ((strcmp(pstSubDirent->d_name, ".") == 0)
				||	(strcmp(pstSubDirent->d_name, "..") == 0))
			{
				continue;
			}

			string	objectid = pstDirent->d_name;
			string	datetime = pstSubDirent->d_name;

			size_t	pos_time = datetime.rfind("_");
			if (pos_time == string::npos)
			{
				printf(
					"invalid file name:%s in %s\n",
					pstSubDirent->d_name,
					__FUNCTION__);
				continue;
			}

			size_t	pos_dot = datetime.rfind(".");
			if (pos_dot == string::npos)
			{
				printf(
					"invalid file name:%s in %s\n",
					pstSubDirent->d_name,
					__FUNCTION__);
				continue;
			}

			//�ļ������б仯
			if (datetime[pos_dot - 1] == ')')
			{
				pos_dot -= strlen("(0)");
			}

			string	time = datetime.substr(
				pos_time + 1,
				pos_dot - pos_time - 1);

			size_t	pos_date = datetime.substr(0, pos_time).rfind("_");
			if (pos_date == string::npos)
			{
				printf(
					"invalid file name:%s in %s\n",
					pstSubDirent->d_name,
					__FUNCTION__);
				continue;
			}

			string	date = datetime.substr(0, pos_time).substr(pos_date + 1);

			ConfigFileInfo	fileinfo;
			fileinfo.filename = pstSubDirent->d_name;

			fileinfo.filedate = date;
			fileinfo.filetime = time;

			map<string, vector<ConfigFileInfo> >::iterator	it =
				g_mapConfigFileList.find(objectid);
			if (it == g_mapConfigFileList.end())
			{
				vector<ConfigFileInfo>	configvec;
				configvec.push_back(fileinfo);

				g_mapConfigFileList[objectid] = configvec;
			}
			else
			{
				it->second.push_back(fileinfo);
			}
		}

		if (pSubDir != NULL)
		{
			closedir(pSubDir);
		}
	}

	if (pDir != NULL)
	{
		closedir(pDir);
	}

#endif
}

void CEventCounterServer::SetOutputPath(const char *path)
{
	if (!path)
	{
		printf("path NULL in %s\n", __FUNCTION__);
		return;
	}

	int iLen = strlen(path);
	if (iLen > 0)
	{
		m_sFilePath = path;
#ifdef WIN32
		if (*(path + iLen - 1) != '\\')
		{
			m_sFilePath.append(1, '\\');
		}

#else
		if (*(path + iLen - 1) != '/')
		{
			m_sFilePath.append(1, '/');
		}

#endif
	}
	else
	{
#ifdef WIN32
		m_sFilePath = ".\\";
#else
		m_sFilePath = "./";
#endif
	}
}

void CEventCounterServer::CreatePath(const char *path)
{
	if (!path)
	{
		printf("path NULL in %s\n", __FUNCTION__);
		return;
	}

	char szPath[512];
	strncpy(szPath, path, sizeof(szPath));

	int iLen = strlen(szPath);

#ifdef WIN32
	for (int i = 0; i < iLen; i++)
	{
		if (szPath[i] == '\\')
		{
			szPath[i] = '\0';
			CreateDirectory(szPath, NULL);
			szPath[i] = '/';
		}
	}

	CreateDirectory(szPath, NULL);
#else
	for (int i = 0; i < iLen; i++)
	{
		if (szPath[i] == '/')
		{
			szPath[i] = '\0';

			//�жϴ�Ŀ¼�Ƿ����,�������򴴽�
			if (access(szPath, F_OK) != 0)
			{
				mkdir(szPath, 0750);
			}

			szPath[i] = '/';
		}
	}

	if (iLen > 0 && access(szPath, F_OK) != 0)
	{
		mkdir(szPath, 0750);
	}

#endif
}

int CEventCounterServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PACKAGE_OUTPUT
	pFTDCPackage->OutputHeader(g_pPackOutput);
	FTDC_DEBUG_BODY(pFTDCPackage->GetTID(), pFTDCPackage, g_pPackOutput);
#endif
#ifdef PRINT_DEBUG
	printf(
		"\tCEventCounterServer::HandlePackage:receive package %0x\n",
		pFTDCPackage->GetTID());
#endif
	switch (pFTDCPackage->GetTID())
	{
		//ϵͳ�ڲ�������ϵ
		// ���²�ڵ������ֻ���յ�rsp��rtn����
	case FTD_TID_RspQrySysInternalTopologyTopic:
		if (g_SysInternalTopology)
			g_SysInternalTopology->OnRspQrySysInternalTopologyTopic(pFTDCPackage, pSession);
		break;
	case FTD_TID_RtnSysInternalTopologyTopic:
		if (g_SysInternalTopology)
			g_SysInternalTopology->OnRtnSysInternalTopologyTopic(pFTDCPackage, pSession);
		break;

	case FTD_TID_RtnNetMonitorTaskResultTopic:
		OnRtnNetMonitorTaskResultTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnObjectAttrTopic:
		OnRtnObjectAttrTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnWarningEventTopic:
		OnRtnWarningEventTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnSyslogEventTopic:
		OnRtnSyslogEventTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnSyslogInfoTopic:
		OnRtnSyslogInfoTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnTopMemInfoTopic:
		OnRtnTopMemInfoTopic(pFTDCPackage);
		MESSAGEPUSHFLOW;
		break;
	case FTD_TID_RtnTopCpuInfoTopic:
		OnRtnTopCpuInfoTopic(pFTDCPackage);
		MESSAGEPUSHFLOW;
		break;
	case FTD_TID_RtnNetworkInfoTopic:
		OnRtnNetworkInfoTopic(pFTDCPackage);
		MESSAGEPUSHFLOW;
		break;

		/// Added by Henchi, 20121220
		/// ��3�����ݰ�ֱ��ת����FRONT��QUERY
	case FTD_TID_RtnDiskIOTopic:
	case FTD_TID_RtnStatInfoTopic:
	case FTD_TID_RtnRouterInfoTopic:
#if 0
	case FTD_TID_RtnTopProcessInfoTopic:
#endif
		MESSAGEPUSHFRONTQUERYFLOW;
		break;
	case FTD_TID_RtnDBQueryTopic:	//����̬����ֵ������Ҫ�������ת��Ϊ�¼�
		OnRtnDBQueryTopic(pFTDCPackage);
		MESSAGEPUSHFLOW;
		break;
	case FTD_TID_ReqQryTradeDayChangeTopic:
		OnReqQryTradeDayChange(pFTDCPackage, pSession);
		break;
	case FTD_TID_ReqQryHostConfigTopic:
		OnReqQryHostConfig(pFTDCPackage, pSession);
		break;
	case FTD_TID_ReqUserLogin:
		OnReqUserLogin(pFTDCPackage, pSession);
		break;
	case FTD_TID_RspUserLogin:
		OnRspUserLogin(pFTDCPackage, pSession);
		break;
	case FTD_TID_ReqOrderInsert:
		OnReqOrderInsert(pFTDCPackage, pSession);
		OnDefaultProcess(pFTDCPackage, pSession);
		break;
	case FTD_TID_RtnUpdateSysConfigTopic:				//��Ҫ���������������������Ĺ�ϵ�������
		OnRtnUpdateSysConfig(pFTDCPackage, pSession);
		break;
	case FTD_TID_RspQryCPUUsageTopic:					/// ת����ѯ��̽������ô��� zhou.jj 20090616
		{
			int nRid = pFTDCPackage->GetRequestId();
			CTRID rid;
			if (m_cFrontServer.m_mFrontToEventReq.getRequestId(
				rid,
				nRid,
				pFTDCPackage->GetChain()) == false)
			{
				return 0;
			}

			m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
			memcpy(
				(char *)m_pkgSend.GetFTDCHeader(),
				pFTDCPackage->GetFTDCHeader(),
				sizeof(TFTDCHeader));
			m_pkgSend.SetRequestId(rid.RequestId);
			m_pkgSend.SetChain(pFTDCPackage->GetChain());

			CFTDCSession *tmpSession = (CFTDCSession *)m_cFrontServer.GetSession(
				rid.SessionID);
			if (tmpSession != NULL)
			{
				tmpSession->SendRequestPackage(&m_pkgSend);
			}

			break;
		}

	case FTD_TID_RspQryDBQueryTopic:					/// ת�����ݿ�SP��ѯ��ǰ��, zhou.jj 20090706
	case FTD_TID_RspQryWebAppInfoTopic:					/// ת��Tomcat��ѯӦ��ǰ�� Henchi 20090622
	case FTD_TID_RspQryServletInfoTopic:
	case FTD_TID_RspQryFileInfoTopic:
	case FTD_TID_RspQrySessionInfoTopic:
	case FTD_TID_RspQryJDBCInfoTopic:
	case FTD_TID_RspQryThreadInfoTopic:
	case FTD_TID_RspQryVMInfoTopic:
	case FTD_TID_RspQryPropertyInfoTopic:
	case FTD_TID_RspQryFileContentInfoTopic:
	case FTD_TID_RspQryConnectionInfoTopic:
	case FTD_TID_RspQryGeneralFieldTopic:
		{
			int nRid = pFTDCPackage->GetRequestId();
			CTRID rid;
			if (m_cFrontServer.m_mFrontToEventReq.getRequestId(
				rid,
				nRid,
				pFTDCPackage->GetChain()) == false)
			{
				return 0;
			}

			m_pkgSend.DupPackage((CPackage *)pFTDCPackage);
			memcpy(
				(char *)m_pkgSend.GetFTDCHeader(),
				pFTDCPackage->GetFTDCHeader(),
				sizeof(TFTDCHeader));
			m_pkgSend.SetRequestId(rid.RequestId);
			m_pkgSend.SetChain(pFTDCPackage->GetChain());

			CFTDCSession *tmpSession = (CFTDCSession *)m_cFrontServer.GetSession(
				rid.SessionID);
			if (tmpSession != NULL)
			{
				tmpSession->SendRequestPackage(&m_pkgSend);
			}

			break;
		}

	case FTD_TID_RspQryNetMonitorTaskResultTopic:
		OnRspQryNetMonitorTaskResultTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnNetMonitorTaskInfoTopic:
		OnRtnNetMonitorTaskInfoTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnNetBaseLineTaskTopic:
		OnRtnBaseLineTaskTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnNetLocalPingResultInfoTopic:
		OnRtnNetLocalPingResultTaskTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnNetRomotePingResultInfoTopic:
		OnRtnNetRemotePingResultTaskTopic(pFTDCPackage);
		break;
	case FTD_TID_RtnParticTradeOrderStatesTopic:
		MESSAGEPUSHQUERYFLOW;
		break;
	default:
		OnDefaultProcess(pFTDCPackage, pSession);
		MESSAGEPUSHFLOW;
		break;
	}

	return 0;
}

void CEventCounterServer::OnRtnObjectAttrTopic(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnObjectAttrField	fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		printf("[%s][%s][%s][%s][%d][%s]\n",
			fieldInfo.ObjectID.getValue(),
			fieldInfo.AttrType.getValue(),
			fieldInfo.MonDate.getValue(),
			fieldInfo.MonTime.getValue(),
			fieldInfo.ValueType.getValue(),
			fieldInfo.AttrValue.getValue());
		string _str = fieldInfo.AttrType.getValue();
		if (_str.find("Session") != string::npos)
		{
			printf("###############################################\n");
			printf("##### [%s][%s][%s][%s][%d][%s] #####\n",
				fieldInfo.ObjectID.getValue(),
				fieldInfo.AttrType.getValue(),
				fieldInfo.MonDate.getValue(),
				fieldInfo.MonTime.getValue(),
				fieldInfo.ValueType.getValue(),
				fieldInfo.AttrValue.getValue());
			printf("###############################################\n");
		}

		fflush(stdout);

		m_pNodeBuffer->writeNode(&fieldInfo);
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}
}

void CEventCounterServer::OnRtnUpdateSysConfig(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDRtnUpdateSysConfigField fieldInfo;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
		&CFTDRtnUpdateSysConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldInfo);
		if (strcmp(
			fieldInfo.UpdateType.getValue(),
			UPDATESYSCONFIG_HOSTIDAPPID) == 0)				//ҵ��ID������IDӰ���ϵ
		{
			m_cFrontServer.m_mObjectIdSession.addObjectIdSession(
				fieldInfo.NewValue.getValue(),
				pSession);								//ҵ��ID
			if (strstr(
				fieldInfo.NewValue.getValue(),
				DOTDATACENTERTOMCATDOT) == NULL)
			{
				m_cFrontServer.m_mObjectIdSession.addObjectIdSession(
					fieldInfo.OldValue.getValue(),
					pSession);
			}
		}
		else if (strcmp(
			fieldInfo.UpdateType.getValue(),
			UPDATESYSCONFIG_HOSTNAME) == 0)			//���������
		{
			m_cFrontServer.m_mObjectIdSession.addObjectIdSession(
				fieldInfo.NewValue.getValue(),
				pSession);
		}

		itor.Next();
	}
}

void CEventCounterServer::OnReqOrderInsert(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf("\tCEventCounterServer::OnReqOrderInsert FTD_TID_ReqOrderInsert\n");

	CFTDInputOrderField fieldOrder;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldOrder);
	printf(
		"\t\tParticipantID %s ClientID %s UserID %s\n",
		(const char *)fieldOrder.ParticipantID,
		(const char *)fieldOrder.ClientID,
		(const char *)fieldOrder.UserID);
}

void CEventCounterServer::OnReqQryHostConfig(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf(
		"CAgentConnector::OnReqQryHostConfig:GetLocationName : %s\n",
		GetLocationName());

	CFTDReqQryHostConfigField fieldConfigInfo;

	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldConfigInfo))
	{
		printf(
			"\tCAgentConnector::OnReqQryHostConfig fieldConfigInfo.CfgType = %s,%s\n",
			(const char *)fieldConfigInfo.CfgType,
			(const char *)fieldConfigInfo.CfgAttend);
		fflush(stdout);
	}

	list<SWriteFilePos> mlPos;
	m_threadFiler.ReadKeyValue(
		(char *)fieldConfigInfo.CfgAttend.getValue(),
		mlPos);

	CFTDRspQryHostConfigField fieldRspInfo;
	memset(&fieldRspInfo, 0, sizeof(fieldRspInfo));

	fieldRspInfo.CfgType = fieldConfigInfo.CfgType;			// ������������
	fieldRspInfo.CfgName = fieldConfigInfo.CfgName;			// ����̽�����
	fieldRspInfo.CfgAttend = fieldConfigInfo.CfgAttend;		// ����̽�����ӵ�ַ
	list<SWriteFilePos>::iterator it;

	m_pkgSend.PrepareResponse(pFTDCPackage,FTD_TID_RspQryHostConfig,FTDC_CHAIN_LAST,FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);

	for (it = mlPos.begin(); it != mlPos.end(); it++)
	{
		//fieldRspInfo.CfgName = it->m_key.c_str();		//�����ļ���
		//fieldRspInfo.CfgHostName = it->m_pos.c_str();	//�����ļ�ƫ����
		//fieldRspInfo.CfgLocation = it->m_time.c_str();	//�����ļ���ȡ��ʱ��
		/// Mod by Henchi, 20110324
		/// �������ݱ������λ��,ȷ���洢�ռ�
		fieldRspInfo.CfgLocation = it->m_key.c_str();		//�����ļ���
		fieldRspInfo.CfgHostName = it->m_pos.c_str();		//�����ļ�ƫ����
		fieldRspInfo.CfgDataCenter = it->m_time.c_str();	//�����ļ���ȡ��ʱ��
		if (m_pkgSend.Length() + sizeof(fieldRspInfo) > FTDC_PACKAGE_MAX_SIZE)
		{
			m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
			pSession->SendRequestPackage(&m_pkgSend);
			printf("-----Send a pakeage!-----\n");
			m_pkgSend.PrepareResponse(
				pFTDCPackage,
				FTD_TID_RspQryHostConfig,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
		}
		else
		{
			FTDC_ADD_FIELD(&m_pkgSend, &fieldRspInfo);
		}
	}

	pSession->SendRequestPackage(&m_pkgSend);

	return;
}

void CEventCounterServer::OnDefaultProcess(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
}

void CEventCounterServer::OnRspUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
#endif

	CFTDRspInfoField rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pFTDCPackage, &rspInfoField))
	{
		printf(
			"\tCEventCounterServer::OnRspUserLogin.ErrorMsg = %s\n",
			(const char *)rspInfoField.ErrorMsg);
	}
}

#if 0
CResultSubscriber *pSUB = new CResultSubscriber();
#endif
void CEventCounterServer::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	memset(&fieldLogin, 0x00, sizeof(fieldLogin));
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	/// Added by Henchi, 20140620
	/// ���¼�������fibclient��������ʱ���ɶԷ���¼��������֪ͨ��������Ϣ

	if (!strcmp(fieldLogin.UserID.getValue(), "fibclient"))
	{
		int TradingDay = atoi(fieldLogin.TradingDay.getValue());
		if (m_mTradeDay < TradingDay)
			TradingDayChange(TradingDay);
		/// ����¼���������ɽ������л�����
		return;
	}


#ifdef PRINT_DEBUG
	printf("�����ļ� �� %s ������%d \n", __FILE__, __LINE__);
	printf(
		"\tCounterConnector::OnReqUserLogin:user=%s password=%s \n",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password);
#endif
#if 0
	{
		m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		fieldLogin.UserID = "event";
		fieldLogin.Password = "eventpd";
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

		CFTDDisseminationField	fieldDissemination;
		fieldDissemination.SequenceSeries = pSUB->GetSequenceSeries();	// GetSequenceSeries();
		fieldDissemination.SequenceNo = pSUB->GetReceivedCount();		// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->RegisterSubscriber(pSUB);

		//flowIt->second->m_pSubcriber[i]->SetSession(pSession);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
		return;
	}

#endif

	char *p = strchr((char *)fieldLogin.Password.getValue(), ',');
	if (p == NULL)
	{
		printf(
			"\tCounterConnector::OnReqUserLogin:user=%s password=%s wrong\n",
			(const char *)fieldLogin.UserID,
			(const char *)fieldLogin.Password);
		return;
	}

	int nStartId = atoi(p + 1);
	*p = '\0';
	if ((p = (char *)strstr(fieldLogin.Password.getValue(), "127.0.0.1")) != NULL)
	{
		char buf[64];
		sprintf(
			buf,
			"%s%s",
			pSession->GetChannel()->GetRemoteName(),
			p + strlen("127.0.0.1"));
		strcpy(p, buf);
	}

	//fieldLogin.Password = "tcp://172.1.128.125:19980";
	map<string, CFlowManager *>::iterator flowIt = m_mapSnmpFlow.find(
		fieldLogin.Password.getValue());
	if ((flowIt == m_mapSnmpFlow.end()) || (flowIt->second == NULL))
	{
		printf(
			"�¼�������������ļ��в����ڸ�snmpmanager��Ӧ��������Ϣ�������ļ��汾��һ�£��������ã�\n");
		return;
	}

	if (!flowIt->second->check(
		nStartId,
		(char *)fieldLogin.Password.getValue()))
	{
		printf(
			"snmpmanager���͵��������¼�������������ò�һ�£��������ã�\n");
		return;
	}

	m_pkgSend.PreparePackage(
		FTD_TID_ReqUserLogin,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	fieldLogin.UserID = "event";
	fieldLogin.Password = "eventpd";
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

	CFTDDisseminationField	fieldDissemination;
	for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
	{
		//printf("\t Flow %d count %d\n", flowIt->second->m_pSubcriber[i]->GetSequenceSeries(), flowIt->second->m_pSubcriber[i]->GetReceivedCount());
		fflush(stdout);
		fieldDissemination.SequenceSeries = flowIt->second->m_pSubcriber[i]->GetSequenceSeries();		// GetSequenceSeries();
		fieldDissemination.SequenceNo = flowIt->second->m_pSubcriber[i]->GetReceivedCount();			// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->RegisterSubscriber(
			flowIt->second->m_pSubcriber[i]);
		flowIt->second->m_pSubcriber[i]->SetSession(pSession);
	}

	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
}

void CEventCounterServer::OnReqQryTradeDayChange(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqQryTradeDayChangeField fieldChange;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldChange);

	//��������
	if (strcmp(fieldChange.ChangeType.getValue(), TRUNCATEFLOW) == 0)
	{
		// ���ö�Ӧ�ñ�ŵ���������0
		printf("������Ϊ %s ��������\n", (const char *)fieldChange.OldDate);
		fflush(stdout);

		int nSeq = atoi((const char *)fieldChange.OldDate);
		if (nSeq >= MAX_EVENTFLOWNUM)
		{
			return;
		}

		map<string, CFlowManager *>::iterator flowIt;
		for (flowIt = m_mapSnmpFlow.begin();
			flowIt != m_mapSnmpFlow.end();
			flowIt++)
		{
			if (pSession == flowIt->second->m_pSubcriber[0]->m_pSession)
			{
				break;
			}
		}

		if (flowIt == m_mapSnmpFlow.end())
		{
			return;
		}

		flowIt->second->m_pSubcriber[nSeq]->m_pFlow->Truncate(nSeq);

		m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

		CFTDReqUserLoginField fieldLogin;
		memset(&fieldLogin, 0, sizeof(fieldLogin));
		fieldLogin.UserID = "event";
		fieldLogin.Password = "eventpd";
		FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);

		CFTDDisseminationField	fieldDissemination;
		fieldDissemination.SequenceSeries = flowIt->second->m_pSubcriber[nSeq]->GetSequenceSeries();	// GetSequenceSeries();
		fieldDissemination.SequenceNo = flowIt->second->m_pSubcriber[nSeq]->GetReceivedCount();			// GetReceivedCount();
		FTDC_ADD_FIELD(&m_pkgSend, &fieldDissemination);
		((CFTDCSession *)pSession)->RegisterSubscriber(
			flowIt->second->m_pSubcriber[nSeq]);
		((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
	}
	else if (strcmp(fieldChange.ChangeType.getValue(), CHANGETRADEDAY) == 0)
	{
		int TradingDay = atoi(fieldChange.NewDate.getValue());
		if (m_mTradeDay < TradingDay)
			TradingDayChange(TradingDay);
	}
}

void CEventCounterServer::TradingDayChange(int TradingDay)
{
	printf("%s old TradeDay [%d]\n", __FUNCTION__, m_mTradeDay);
	printf("%s new TradeDay [%d]\n", __FUNCTION__, TradingDay);

	//�������л�
	// ������Ϣ���������ӵ�Session
	m_pkgSend.PreparePackage(
		FTD_TID_ReqQryTradeDayChangeTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);

	CFTDReqQryTradeDayChangeField fieldChange;
	memset(&fieldChange, 0, sizeof(fieldChange));
	fieldChange.ChangeType = CHANGETRADEDAY;
	sprintf((char *)fieldChange.OldDate.getValue(), "%8d", m_mTradeDay);
	sprintf((char *)fieldChange.NewDate.getValue(), "%8d", TradingDay);

	FTDC_ADD_FIELD(&m_pkgSend, &fieldChange);
	//���½�����
	m_mTradeDay = TradingDay;

	// ���͵�ǰ�á���ѯ������
	m_cFrontServer.SendPackageAllSession(&m_pkgSend);

	// ���͵����ӵĲɼ�����sysfibclient��
	SendPackageAllSession(&m_pkgSend);

	//����ڴ����ݿ�
	//ClearMemeryDatabase();

	// ���������½ͳ����Ϣ
	MdLoginRecord::resetAllRecords();
	MdLoginWarningCalculate::reset();
}

void CEventCounterServer::ClearMemeryDatabase(void)
{
	/*
	CTimeType theTime;
	CDateType beginDate;

	time_t timep;
	time(&timep);
	timep -=g_FrontRange*3600;
	struct tm *pGm = localtime(&timep);

	sprintf((char *)(theTime.getValue()),"%02d:%02d:%02d", pGm->tm_hour, pGm->tm_min, pGm->tm_sec);
	sprintf((char *)(beginDate.getValue()),"%d%02d%02d" ,pGm->tm_year+1900 ,pGm->tm_mon+1 ,pGm->tm_mday);

	cout<<"�ڴ����ݿ�����---"<<endl;

	///����澯��ϸ��
	CSysWarningQuery *oldFieldQuery =pMemoryDB->m_SysWarningQueryFactory->startFindByTime(beginDate ,theTime);
	while(oldFieldQuery)
	{
	CSysWarningQuery *tmpField =pMemoryDB->m_SysWarningQueryFactory->findNextByTime();
	pMemoryDB->m_SysWarningQueryFactory->remove(oldFieldQuery);
	oldFieldQuery =tmpField;
	}
	pMemoryDB->m_SysWarningQueryFactory->endFindByTime();
	///������־:
	CSyslogEvent *oldFieldlog =pMemoryDB->m_SyslogEventFactory->startFindByTime(beginDate ,theTime);
	while (oldFieldlog)
	{
	CSyslogEvent *tmpField =pMemoryDB->m_SyslogEventFactory->findNextByTime();
	pMemoryDB->m_SyslogEventFactory->remove(oldFieldlog);
	oldFieldlog =tmpField;
	}
	pMemoryDB->m_SyslogEventFactory->endFindByTime();

	//	CLEARMEMDB(SysMdbObjectAttr);
	//	CLEARMEMDB(SysMdbSyslogInfo);
	//	CLEARMEMDB(SysUserInfo);
	//	CLEARMEMDB(SysOnlineUserInfo);
	//	CLEARMEMDB(SysWarningEvent);
	//	CLEARMEMDB(SysMdbTopCpuInfo);
	//	CLEARMEMDB(SysMdbTopMemInfo);
	//	CLEARMEMDB(SysMdbTopProcessInfo);
	//	CLEARMEMDB(SysMdbFileSystemInfo);
	//	CLEARMEMDB(SysMdbNetworkInfo);
	//	CLEARMEMDB(SyslogEvent);
	CLEARMEMDB(RspQryHostEnvCommon);
	CLEARMEMDB(RspQryHostEnvLan);
	CLEARMEMDB(RspQryHostEnvStorage);
	CLEARMEMDB(RspQryHostEnvIO);
	CLEARMEMDB(RspQryHostEnvFS);
	CLEARMEMDB(RspQryHostEnvSwap);
	CLEARMEMDB(RspQryHostEnvLanCfg);
	//	CLEARMEMDB(SysMdbWebAppInfo);
	//	CLEARMEMDB(SysMdbMemPoolInfo);
	//	CLEARMEMDB(SysMdbConnectorInfo);

	timep +=g_FrontRange*3600;
	time_t timep1;
	time(&timep1);
	cout<<"�ڴ����ݿ��������---��ʱ��"<<timep1-timep<<endl;
	*/
}

int CEventCounterServer::ParseShowIPInterfaceResult(
	int taskid,
	vector<AttrNodeInfo> attrlist,
	string	objectid,
	string	deviceip)
{
	/*
	if(deviceip.compare("172.1.33.43") == 0)
	{
	int a = 1;
	}
	*/
	string	interface_id;

	/*
	if(deviceip.compare("172.1.33.43") == 0)
	{
	int a = 1;
	}
	*/
	string	status;

	/*
	if(deviceip.compare("172.1.33.43") == 0)
	{
	int a = 1;
	}
	*/
	string	protocol;

	for (int i = 0; i < attrlist.size(); ++i)
	{
		if (attrlist[i].key.compare("ifs") == 0)
		{
			interface_id = attrlist[i].value.substr(
				1,
				attrlist[i].value.size() - 2);
			break;
		}
	}

	if (interface_id.length() == 0)
	{
		return -1;
	}

	//���˿��е�'.'�滻��'_'
	char *p = NULL;
	while ((p = strchr((char *)interface_id.c_str(), '.')) != NULL)
	{
		*p = '_';
	}

	for (int i = 0; i < attrlist.size(); ++i)
	{
		if (attrlist[i].key.compare("status") == 0)
		{
			status = attrlist[i].value;
			break;
		}
	}

	if (status.length() == 0)
	{
		return -1;
	}

	for (int i = 0; i < attrlist.size(); ++i)
	{
		if (attrlist[i].key.compare("pro") == 0)
		{
			protocol = attrlist[i].value;
			break;
		}
	}

	if (protocol.length() == 0)
	{
		return -1;
	}

	time_t	timep;

	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);

	char curtime[10];
	char curdate[10];

	strftime(curtime, 10, "%H:%M:%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	string	attrvalue;					//��bian.xbЭͬͳһ  0��up-up��1��up-down��2��down-down��3��admindown-down

	// 20120821,Lee
	string	eventname = "";
	string	fulleventname = "";
	string	eventlevel;
	string	eventinfo;

	CFTDRtnNetPartyLinkStatusInfoField	partylinkstatus;
	memset(&partylinkstatus, 0, sizeof(partylinkstatus));

	partylinkstatus.Interface = interface_id.c_str();
	partylinkstatus.IPADDR = deviceip.c_str();
	partylinkstatus.MonDate = curdate;
	partylinkstatus.MonTime = curtime;

	string	partylink_key = deviceip;
	partylink_key += "_";
	partylink_key += interface_id;

	MAP_PARTYLINK_INFO_IT p_it = m_cConfigConnector.m_partylinkinfo.find(
		partylink_key);
	if (p_it != m_cConfigConnector.m_partylinkinfo.end())
	{
		partylinkstatus.SEAT_NO = p_it->second.SEAT_NO;
	}
	else
	{
		printf(
			"no partylink info for ip:%s, port:%s in %s\n",
			deviceip.c_str(),
			interface_id.c_str(),
			__FUNCTION__);
	}

	string	total_id = objectid;
	total_id += ".";
	total_id += interface_id;

	//������·״̬��
	map<string, LinkStatusInfo>::iterator l_it = g_mapLinkStatusInfo.find(
		total_id);
	if (l_it == g_mapLinkStatusInfo.end())
	{
		LinkStatusInfo	statusinfo;

		g_mapLinkStatusInfo[total_id] = statusinfo;

		l_it = g_mapLinkStatusInfo.find(total_id);
	}

	partylinkstatus.status = "down";

	if (status.compare("\"up\"") == 0)
	{
		l_it->second.m_nPortLinkStatus = 0;

		//	
		if (protocol.compare("\"up\"") == 0)
		{
			l_it->second.m_nPortProtoStatus = 0;

			attrvalue = "0";
			partylinkstatus.status = "up";
		}
		else if (protocol.compare("\"down\"") == 0)
		{
			l_it->second.m_nPortProtoStatus = 1;
			attrvalue = "1";
		}
		else
		{
			SendLinkStatus(total_id, deviceip.c_str());
			printf(
				"invalid protocol:%s for show ip interface brief\n",
				protocol.c_str());
			return -1;
		}

		SendLinkStatus(total_id, deviceip.c_str());
	}
	else if (status.compare("\"down\"") == 0)
	{
		if (p_it != m_cConfigConnector.m_partylinkinfo.end()
			&&	compare(p_it->second.LINE_STATUS.getValue(), "�˹��ر���") != 0
			&&  compare(p_it->second.LINE_STATUS.getValue(), "������") != 0)
		{
			l_it->second.m_nPortLinkStatus = 1;

			SendLinkStatus(total_id, deviceip.c_str());

			attrvalue = "2";

			eventname = "LINK_UPDOWN";
			fulleventname = "��·״̬�л�";
			eventlevel = "Level2";

			eventinfo = "Interface ";
			eventinfo += interface_id;
			eventinfo += ", polling state down";
		}
	}
	else if (status.compare("\"administratively down\"") == 0)
	{
		l_it->second.m_nPortLinkStatus = 3;

		SendLinkStatus(total_id, deviceip.c_str());

		attrvalue = "3";

		/*admin�������澯20120803	
		eventname = "LINKADMIN_UPDOWN";
		fulleventname = "��·״̬�л�";
		eventlevel = "Level2";

		eventinfo = "Interface ";
		eventinfo += interface_id;
		/// Mod by Henchi, 20111227
		/// �¼��������administratively��ʶ����������
		eventinfo += ", changed state to administratively down";
		*/
	}
	else
	{
		printf(
			"invalid status:%s for show ip interface brief\n",
			status.c_str());
		return -1;
	}

	if (attrvalue.length() > 0)
	{
		string	pl_status = partylinkstatus.status.getValue();
		pl_status.append(":");
		pl_status.append(attrvalue.c_str());
		partylinkstatus.status = pl_status.c_str();
	}

	if (p_it != m_cConfigConnector.m_partylinkinfo.end())
	{
		//��Ա��·��ʶ
		l_it->second.linktype = 1;

		//����·ͳ����Ϣ����front��query

		m_pkgSend.PreparePackage(FTD_TID_RtnNetPartyLinkStatusInfoTopic,FTDC_CHAIN_LAST,FTD_VERSION);		
		FTDC_ADD_FIELD(&m_pkgSend, &partylinkstatus);

		m_pkgSend.MakePackage();
		m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
		m_cFrontServer.m_pCurrOracleFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
	}

	CFTDRtnObjectAttrField	fieldinfo;

	memset(&fieldinfo, 0, sizeof(CFTDRtnObjectAttrField));

	//generate attr value
	fieldinfo.ObjectID = total_id.c_str();
	fieldinfo.MonDate = curdate;
	fieldinfo.MonTime = curtime;
	fieldinfo.AttrType = "interfaceStatus";

	fieldinfo.ValueType = INT_ATTR;
	fieldinfo.AttrValue = attrvalue.c_str();

	m_pkgSend.PreparePackage(
		FTD_TID_RtnObjectAttrTopic,
		FTDC_CHAIN_LAST,
		FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &fieldinfo);

	m_pkgSend.MakePackage();
	m_cFrontServer.m_pCurrFrontFlow->Append(
		m_pkgSend.Address(),
		m_pkgSend.Length());
	m_cFrontServer.m_pCurrOracleFlow->Append(
		m_pkgSend.Address(),
		m_pkgSend.Length());

	printf(
		"$$$$$$$$$$$$$generate 11111 attrname:%s, attrvalue:%s, total_id:%s\n",
		fieldinfo.AttrType.getValue(),
		fieldinfo.AttrValue.getValue(),
		total_id.c_str());

	//generate warning event according to "status"
	if (eventname.length() > 0)
	{
		CFTDRtnWarningEventField warninglogEvent;

		memset(&warninglogEvent, 0, sizeof(CFTDRtnWarningEventField));

		warninglogEvent.ObjectID = total_id.c_str();
		warninglogEvent.MonDate = curdate;
		warninglogEvent.MonTime = curtime;

		warninglogEvent.OccurDate = curdate;
		warninglogEvent.OccurTime = curtime;

		warninglogEvent.EventName = eventname.c_str();
		warninglogEvent.FullEventName = fulleventname.c_str();

		warninglogEvent.EventType = "1";

		//�����¼�����
		string	modifylevel = modifyWarningEventLevel(deviceip, eventlevel);
		warninglogEvent.WarningLevel = modifylevel.c_str();
		warninglogEvent.EventDes = eventinfo.c_str();

		/// Mod by Henchi, 20111227
		/// �¼������ʶ����Ϊ"I"����ʾ��ʼ״̬�¼��(I���configδ����)
		warninglogEvent.ProcessFlag = "N";
		warninglogEvent.IPAddress = deviceip.c_str();

		SendWarningEvent(warninglogEvent);
	}

	//generate warning event according to "proto"
	if (status.compare("\"administratively down\"") != 0
		&&	protocol.compare("\"down\"") == 0
		&&	p_it != m_cConfigConnector.m_partylinkinfo.end()
		&&	compare(p_it->second.LINE_STATUS.getValue(), "�˹��ر���") != 0
		&&  compare(p_it->second.LINE_STATUS.getValue(), "������") != 0)
	{
		eventname = "LINEPROTO_UPDOWN";
		fulleventname = "��·Э��״̬�л�";
		eventlevel = "Level3";

		eventinfo = "Line protocol on Interface ";
		eventinfo += interface_id;
		eventinfo += ", polling state down";

		CFTDRtnWarningEventField warninglogEvent;

		memset(&warninglogEvent, 0, sizeof(CFTDRtnWarningEventField));

		warninglogEvent.ObjectID = total_id.c_str();
		warninglogEvent.MonDate = curdate;
		warninglogEvent.MonTime = curtime;

		warninglogEvent.OccurDate = curdate;
		warninglogEvent.OccurTime = curtime;

		warninglogEvent.EventName = eventname.c_str();
		warninglogEvent.FullEventName = fulleventname.c_str();

		warninglogEvent.EventType = "1";

		//�����¼�����
		string	modifylevel = modifyWarningEventLevel(deviceip, eventlevel);
		warninglogEvent.WarningLevel = modifylevel.c_str();
		warninglogEvent.EventDes = eventinfo.c_str();

		/// Mod by Henchi, 20111227
		/// �¼������ʶ����Ϊ"I"����ʾ��ʼ״̬�¼�(I���configδ����)
		warninglogEvent.ProcessFlag = "N";
		warninglogEvent.IPAddress = deviceip.c_str();

		SendWarningEvent(warninglogEvent);
	}

	return 0;
}

void CEventCounterServer::SendWarningEvent(
	CFTDRtnWarningEventField warningevent)
{
	if (!g_mConfigControlEvent)
	{
		warningevent.EvendID = m_mWarningEventId++;

		int nEventSeries;
		g_cEventProcess.getEventDesc(
			(const char *)warningevent.ObjectID,
			(const char *)warningevent.EventName,
			nEventSeries);
		warningevent.EventNum = nEventSeries;

		string	delay_key = warningevent.ObjectID.getValue();
		delay_key += ";;";
		delay_key += warningevent.EventName.getValue();

		map<string, CObjectAttrKey>::iterator it = g_mapEventDelayTime.find(
			delay_key);
		if (it != g_mapEventDelayTime.end())
		{
			///�����ǰ�¼�������ʱ����ӳٵ�����ʱ�����ɾ��map�еĸýڵ�
			if (strcmp(
				warningevent.MonDate.getValue(),
				it->second.m_nObjectID.c_str()) > 0
				||	(
				strcmp(
				warningevent.MonDate.getValue(),
				it->second.m_nObjectID.c_str()) == 0 && strcmp(
				warningevent.MonTime.getValue(),
				it->second.m_nAttrID.c_str()) > 0
				))
			{
				g_mapEventDelayTime.erase(it);
			}
			else						///��ǰ�¼�������ʱ�����ӳٵ�����ʱ�䷶Χ�ڣ��Զ�����ø澯�����ñ��ΪY
			{
				if(warningevent.ProcessFlag == "=" 
					&& it->second.m_sProcessFlag.compare("Y") == 0)
				{
					//�¼���ԭ����
					g_mapEventDelayTime.erase(it);
				}
				else
				{
					warningevent.ProcessFlag = it->second.m_sProcessFlag.c_str();
					warningevent.EventDealDes = it->second.m_sEventDes.c_str();
				}
			}
		}

		//���¸澯����
		UpdateWarningCount(warningevent);

		if(warningevent.ProcessFlag == "N")
		{
			//send mms
			string	membername;
			m_cConfigConnector.GetPartyLinkMemberName(warningevent, membername);

			string	devname;
			m_cConfigConnector.GetDeviceName(
				warningevent.ObjectID.getValue(),
				devname);

			int warningcount = GetWarningCount(warningevent);

			g_MsgGenerator.AddEvent(
				warningevent,
				warningcount,
				(char *)devname.c_str(),
				(char *)membername.c_str());
		}

		map<int, string>::iterator p_it = g_mapEventProcessFlag.find(warningevent.EventNum.getValue());
		if(p_it != g_mapEventProcessFlag.end())
		{
			//���¼����ڴ����·������¼�Ҳ��Ϊ������
			if(p_it->second.compare("=")== 0 && warningevent.ProcessFlag == "N")
			{
				warningevent.ProcessFlag = p_it->second.c_str();
			}
			else
			{
				p_it->second = warningevent.ProcessFlag.getValue();
			}
		}
		else
		{
			g_mapEventProcessFlag[warningevent.EventNum.getValue()] = warningevent.ProcessFlag.getValue();
		}

		//κ��add������δ����ĸ澯�¼�
		g_warningEventManager.add_warning_event(warningevent);
	}

	m_pkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &warningevent);

	if (!g_mConfigControlEvent)
	{
		m_pkgSend.MakePackage();
		m_cFrontServer.m_pCurrFrontFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
		m_cFrontServer.m_pCurrOracleFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
		m_pkgSend.ValidPackage();
		m_cProbeServer.SendPackageAllSession(&m_pkgSend);
	}
	else
	{
		//��field������ת�Ƶ�configͳһ����	
		if (m_cConfigConnector.GetSession())
		{
			m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			printf("config session NULL, send warningevent fail!\n");
		}
	}
}

string CEventCounterServer::GetFileContent(string &filePath)
{
	string	content;

	FILE *pf = fopen(filePath.data(), "rb");
	if (pf)
	{
		fseek(pf, 0, SEEK_SET);

		while (true)
		{
			char buffer[1024] = { 0 };

			int len = fread((void *)buffer, 1, sizeof(buffer) - 1, pf);
			if (len > 0 && SEEK_END != ftell(pf))
			{
				buffer[len] = '\0';
				content += buffer;
			}
			else
			{
				break;
			}
		}

		fclose(pf);
	}
	else
	{
		printf("file %s open fail in %s\n", filePath.c_str(), __FUNCTION__);
	}

	return content;
}

int CEventCounterServer::RegularParse(
	CFTDRtnNetMonitorTaskResultField &resultField,
	string	&oldresult,
	string	&newresult)
{
	newresult = "";

	int manufactory_id;
	string	deviceip;
	string	deviceserial;

	int ret = m_cConfigConnector.GetDeviceManufacoryIdAndIP(
		resultField.ObjectID.getValue(),
		manufactory_id,
		deviceip,
		deviceserial);
	if (ret == -1)
	{
		printf(
			"can't find manufactor_id by objectid:%s in %s\n",
			resultField.ObjectID.getValue(),
			__FUNCTION__);
		return -1;
	}
	//��� juniper srx�豸Ҫȥ������{primary:node0}֮����ַ���
	if (manufactory_id == 4 
		&& (strcmp(deviceserial.c_str(),"SRX") == 0) )
	{
		remove_postfix_forSRX(oldresult);
	}
	//��� juniper srx�豸��envinfo��envfanѲ������
	if( strcmp(resultField.InstructChain.getValue(), "EnvInfo") == 0
			&&	manufactory_id == 4 && strcmp(deviceserial.c_str(), "SRX") == 0 )
	{
		Split_Data_Column(oldresult,newresult,"Measurement");
		oldresult = newresult;
		newresult = "";
	}
	else if( strcmp(resultField.InstructChain.getValue(), "EnvFan") == 0
			&&	manufactory_id == 4 )
	{
		Split_Data_Column(oldresult,newresult,"RPM     Measurement");
		oldresult = newresult;
		newresult = "";
	}
	else if( strcmp(resultField.InstructChain.getValue(), "SRXUptime") == 0
			&& manufactory_id == 4 )
	{
		GetSRXUptimeFromStr(oldresult, newresult);
		oldresult = newresult;
		newresult = "";
	}
	//cisco neux 3548ϵ�еĵ�Դ״̬Ѳ�����ݴ���
	else if(strcmp(resultField.InstructChain.getValue(), "NexusPower") == 0
		&& strcmp(deviceserial.c_str(), "3548") == 0
		&& manufactory_id == 1 )
	{
	}
	//cisco 7kϵ�еĵ�Դ״̬Ѳ�����ݴ���
	else if( strcmp(resultField.InstructChain.getValue(), "NexusPower") == 0
			&&  strcmp(deviceserial.c_str(), "NXOS") == 0
			&&	manufactory_id == 1)
	{
		Combinate_Data_Power_NUXUS(oldresult,newresult);
		oldresult = newresult;
		newresult = "";
	}
	//cisco 7kϵ�е��¶�״̬Ѳ�����ݴ���
	else if( strcmp(resultField.InstructChain.getValue(), "NexusTemp") == 0
			&&  strcmp(deviceserial.c_str(), "NXOS") == 0
			&&	manufactory_id == 1)
	{
		Combinate_Data_Env_NUXUS(oldresult,newresult);
		oldresult = newresult;
		newresult = "";
	}
	//cisco 7kϵ�����ٶ���Ѳ�����ݴ���
	else if( strcmp(resultField.InstructChain.getValue(), "RateLimiter") == 0 )
	{
		GetDropCounterFromStr(oldresult,newresult);
		oldresult = newresult;
		newresult = "";
	}
        else if ( (strcmp(resultField.InstructChain.getValue(),"NexusTemp") == 0)
                 && manufactory_id == 1
                 && (strcmp(deviceserial.c_str(),"3548") == 0))
        {
            GetNexusTemp_3548FromStr(oldresult,newresult);
            oldresult = newresult;
            newresult = "";
        }	
	else if( ((strcmp(resultField.InstructChain.getValue(),"SrxFpc0Status") == 0)
		      ||(strcmp(resultField.InstructChain.getValue(),"SrxFpc1Status") == 0))
		&& manufactory_id == 4
		&& (strcmp(deviceserial.c_str(),"SRX") == 0))
	{
		GetSrxFpcStatus_SRXFromStr(oldresult,newresult);
		oldresult = newresult;
		newresult = "";
	}

	return RegularParseResult(
		resultField,
		oldresult,
		newresult,
		manufactory_id,
		deviceip,
		deviceserial);
}

int CEventCounterServer::RegularParse(
	CFTDRspQryNetMonitorTaskResultField &resultField,
	string	&oldresult,
	string	&newresult)
{
	newresult = "";

	int manufactory_id;
	string	deviceip;
	string	deviceserial;

	int ret = m_cConfigConnector.GetDeviceManufacoryIdAndIP(
		resultField.ObjectID.getValue(),
		manufactory_id,
		deviceip,
		deviceserial);
	if (ret == -1)
	{
		printf(
			"can't find manufactor_id by objectid:%s in %s\n",
			resultField.ObjectID.getValue(),
			__FUNCTION__);
		return -1;
	}

	char commandkey[1024] = { 0 };
	SNPRINTF(
		commandkey,
		1024,
		"%s_%d",
		resultField.InstructChain.getValue(),
		manufactory_id);

	//������ȡָ��
	vector<vector<AttrNodeInfo> > attr_value_list = CRegexConfigManager::
		Instance()->ParseCommandResult(commandkey, oldresult, false);

	//����ָ��������ʽ:attr1=val1;attr2=val2...;regular	
	for (int i = 0; i < attr_value_list.size(); ++i)
	{
		if (i != 0)
		{
			//����ָ��֮���������ַ��ָ�
			newresult += "**$$**";
		}

		for (int j = 0; j < attr_value_list[i].size(); ++j)
		{
			newresult += attr_value_list[i][j].key;
			newresult += "=";
			newresult += attr_value_list[i][j].value;
			newresult += "**##**";		//�ָ���
		}
	}

	return 0;
}

int CEventCounterServer::RegularParseResult(
	CFTDRtnNetMonitorTaskResultField &resultField,
	string	&oldresult,
	string	&newresult,
	int manufactory_id,
	string	deviceip,
	string	deviceserial)
{
	if (strcmp(
		resultField.InstructChain.getValue(),
		"Ping") == 0)
	{
		//�ݲ�����
		resultField.Flag = TASK_SUCCESS;
		return 0;
	}

	if (strcmp(resultField.InstructChain.getValue(), "EnvInfo") == 0
		&&	manufactory_id == 1
		&&	(
		deviceserial.compare("3825") == 0
		||	deviceserial.compare("3945") == 0
		||	deviceserial.compare("5350") == 0
		||	deviceserial.compare("7304") == 0
		))
	{
		resultField.Flag = TASK_RESULT_ERROR;

		if (deviceserial.compare("3825") == 0
			&&	ParseEnv_3825(oldresult, newresult) == 0)
		{
			resultField.Flag = TASK_SUCCESS;
		}
		else if (deviceserial.compare("3945") == 0
			&&	 ParseEnv_3945(oldresult, newresult) == 0)
		{
			resultField.Flag = TASK_SUCCESS;
		}
		else if (deviceserial.compare("5350") == 0
			&&	 ParseEnv_5350(oldresult, newresult) == 0)
		{
			resultField.Flag = TASK_SUCCESS;
		}
		else if (deviceserial.compare("7304") == 0
			&&	 ParseEnv_7304(oldresult, newresult) == 0)
		{
			resultField.Flag = TASK_SUCCESS;
		}

		return 0;
	}
	else if( strcmp(resultField.InstructChain.getValue(), "REUsage") == 0 
		&& manufactory_id == 4)
	{
		resultField.Flag = TASK_RESULT_ERROR;
		if(ParseREUsage_SRX(oldresult, newresult)==0)
		{
			resultField.Flag = TASK_SUCCESS;
		}
		return 0;
	}
	else if( strcmp(resultField.InstructChain.getValue(), "FpcStatus") == 0 
		&& manufactory_id == 4)
	{
		if(ParseFPC_SRX(oldresult, newresult)==0)
		{
			resultField.Flag = TASK_SUCCESS;
		}
		return 0;
	}
	else if( manufactory_id == 4
		    && (strcmp(resultField.InstructChain.getValue(),"SrxPerfSession") == 0)
		    && (deviceserial.compare("SRX") == 0)
			)
	{
		resultField.Flag = TASK_RESULT_ERROR;
		int threadhold =0;
		if ( ParsePerfSession_SRX(resultField,oldresult,manufactory_id,deviceserial,threadhold) == 0 )
		{
			resultField.Flag = TASK_SUCCESS;
		}
		newresult = oldresult;
		char buf[1024]={0};
		sprintf(buf,"*@*ÿ��SPUÿ�벻����%d",threadhold);
		newresult.append(buf);
		return 0;
	}
	else if( strcmp(resultField.InstructChain.getValue(), "NexusNtpStatus") == 0 )
	{
		if( oldresult.length()>0 )
		{			
			resultField.Flag = TASK_SUCCESS;
		}
		newresult = oldresult;
		newresult +="*@*����ǿռ���ʾ����";
		
		return 0;
	}
	else if( manufactory_id == 1
                 &&deviceserial.compare("NXOS") == 0
		 &&(strcmp(resultField.InstructChain.getValue(), "NexusInterfaceDrop") == 0 
		    || strcmp(resultField.InstructChain.getValue(), "VOQBufferDrop") == 0
		    || strcmp(resultField.InstructChain.getValue(), "NexusInterfaceError") == 0)
		)
	{
            resultField.Flag = TASK_RESULT_ERROR;
	    if( oldresult.empty() )
	    {
	        resultField.Flag = TASK_SUCCESS;
	    }
		newresult = oldresult;
		newresult +="*@*���Ϊ�ռ���ʾ����";
		return 0;
	}
	else
	{
		//���ASRƽ̨״̬����oldresultֵ���޳�����time�е����� 2014.6.9 by Li.sc
		if(strcmp(resultField.InstructChain.getValue(), "AsrPlatformDiag") == 0
		&&	deviceserial.find("ASR") != string::npos )
		{
			size_t pos,pos_front,pos_back;
			
			while( (pos = oldresult.find("time") ) != string::npos )
			{
				pos_front = oldresult.rfind( CHANGELINE_FLAG, pos );
				pos_back = oldresult.find( CHANGELINE_FLAG, pos );
				oldresult.replace( pos_front+strlen( CHANGELINE_FLAG ), pos_back-pos_front, "");
			}
		}

		return parse_other_result(resultField,manufactory_id, deviceip,deviceserial, oldresult, newresult);
	}
}

int CEventCounterServer::parse_other_result(CFTDRtnNetMonitorTaskResultField &resultField
	, int manufactory_id, string deviceip, string deviceserial, string	&oldresult, string	&newresult)
{
	char commandkey[1024] = { 0 };
    char commandkey2[1024] = { 0 };
	
	SNPRINTF(commandkey,1024,"%s_%s_%d",resultField.InstructChain.getValue(),deviceserial.c_str(),manufactory_id);
	SNPRINTF(commandkey2,1024,"%s_%d",resultField.InstructChain.getValue(),manufactory_id);

	//������ȡָ��
	vector<vector<AttrNodeInfo> > attr_value_list = CRegexConfigManager::
		Instance()->ParseCommandResult(commandkey, oldresult,true,commandkey2);

	//�ع����������ָ���б�
	pre_process_attrlist(resultField, attr_value_list,oldresult, manufactory_id);

	//����ָ��������ʽ:attr1=val1;attr2=val2...;regular	
	for (int i = 0; i < attr_value_list.size(); ++i)
	{
		if (i != 0)
		{
			//����ָ��֮���������ַ��ָ�
			newresult += "**$$**";
		}

		if (strcmp(resultField.InstructChain.getValue(),"MEMUsageInfo") == 0)
		{
			process_memory_task(manufactory_id, attr_value_list,i,newresult);
		}
		else if( strcmp(resultField.InstructChain.getValue(), "ConSessions") == 0
			&& manufactory_id == 4 )
		{
			newresult += attr_value_list[0][0].key;
			newresult += "=";
			newresult += attr_value_list[0][0].value;
			newresult += ";";	//�ָ���
			newresult += "Unicast-sessions";
			newresult += "=";
			int count = ParseConSessions_SRX(attr_value_list[0][0].value);
			if(  count <= 4000 )
			{
				resultField.Flag = TASK_SUCCESS;
			}
			char count_buff[16] = "\0";
			sprintf(count_buff,"%d", count);
			newresult += count_buff;
			//ָ��͹���ķָ���*@*
			newresult += "*@*Unicast-sessions<=4000";

			return 0;
		}
		else
		{
			for (int j = 0; j < attr_value_list[i].size(); ++j)
			{
				newresult += attr_value_list[i][j].key;
				newresult += "=";
				newresult += attr_value_list[i][j].value;
				newresult += ";";	//�ָ���
			}
		}

		//��������show ip interface brif����,����ָ����¼�
		if (strcmp(resultField.InstructChain.getValue(), "IfsInfo") == 0)
		{
			g_counterServer->ParseShowIPInterfaceResult(resultField.Task_ID.getValue(),attr_value_list[i]
			,resultField.ObjectID.getValue(),deviceip);
		}
	}

	//��ָ��������RunningConfig����
	if (attr_value_list.size() == 0)
	{
		newresult += oldresult;
		newresult += ";";

		if (strcmp(resultField.InstructChain.getValue(),"RunningConfig") != 0
			&&	strcmp(resultField.InstructChain.getValue(),"RouteStatic") != 0)
		{
			printf("no attr got for cmd:%s in %s\n",resultField.InstructChain.getValue(),__FUNCTION__);
			resultField.Flag = TASK_RESULT_ERROR;
		}
	}

	//ָ��͹���ķָ���*@*
	if (newresult.size() > 0 && newresult[newresult.size() - 1] == ';')
	{
		newresult[newresult.size() - 1] = '*';
		newresult += "@*";
	}

	char regular_key[1024];

	//��ָ��ָ����в���Ĭ�ϵĹ���
	MAP_INSTR_INFO	map_instr_info = g_counterServer->m_cConfigConnector.GetTaskInstrInfo();
	//���Ȳ��Ҵ����ͺŵı��ʽ
	SNPRINTF(regular_key,1024,"%s_%d_%s",resultField.InstructChain.getValue(),manufactory_id,deviceserial.c_str());
	MAP_INSTRINFO_IT i_it = map_instr_info.find(regular_key);

	//���û�У��ٲ��Ҳ����ͺű��ʽ
	if( i_it == map_instr_info.end() )
	{
		memset(regular_key, 0, 1024);
		SNPRINTF(regular_key,1024,"%s_%d_",resultField.InstructChain.getValue(),manufactory_id);
		 i_it = map_instr_info.find(regular_key);
	}

	if (i_it != map_instr_info.end())
	{
		string	oriregular = i_it->second.defaultregular;

		//���ҹ������
		SNPRINTF(regular_key,1024,"%d_%s_%s",manufactory_id,resultField.ObjectID.getValue(),resultField.InstructChain.getValue());

		MAP_TASK_REGULAR_PARAM	map_task_regular_params = g_counterServer->
			m_cConfigConnector.GetTaskRegularParamList();
		MAP_TASK_REGULAR_PARAM_IT t_it = map_task_regular_params.find(
			regular_key);
		if (t_it == map_task_regular_params.end())
		{
			//������Գ���id���õ�regular
			SNPRINTF(regular_key,1024,"%d__%s_%s",manufactory_id,resultField.InstructChain.getValue(),deviceserial.c_str());
			t_it = map_task_regular_params.find(regular_key);
		}

		vector<map<int, string> > regularparams;

		if (t_it != map_task_regular_params.end())
		{
			regularparams = t_it->second;
		}
		else
		{
			//��ָ��ָ����в���Ĭ�ϵĹ��������
			regularparams = i_it->second.defaultparams;
		}

		bool regularpass = false;	//�������ֻҪ����һ����pass
		string	regularstr;

		if (regularparams.size() > 0)
		{
			//�������еı�����ʵ���滻
			for (int j = 0; j < regularparams.size(); ++j)
			{
				string	cmdregular = oriregular;

				//�ڿͻ���չʾ��ԭʼ����(����MD5�����)
				string	displayregular = oriregular;

				map<int, string>::iterator	r_i = regularparams[j].begin();
				for (; r_i != regularparams[j].end(); ++r_i)
				{
					char key[1024];
					SNPRINTF(key, 1024, "$%d", r_i->first + 1); //�����±��1��ʼ����������0
					string	keystr = key;

					//����ͳһ�ɴ�д��ʽ
					string	upperresult = r_i->second;
					transform(r_i->second.begin(),r_i->second.end(),upperresult.begin(),::toupper);

					ReplayString(displayregular,keystr,upperresult,	displayregular);

					if (upperresult.length() > 100)
					{
						//�ַ���̫��������MD5ֵ������
						char nowDigest[MD5_DIGEST_LEN * 2 + 1];
						GenMD5((char *)upperresult.c_str(),upperresult.length(),nowDigest);

						upperresult = "\"";
						upperresult += nowDigest;
						upperresult += "\"";

						ReplayString(cmdregular,keystr,upperresult,cmdregular);
					}
					else
					{
						cmdregular = displayregular;
					}
				}

				regularstr += displayregular;

				if (strcmp(resultField.InstructChain.getValue(),"Vlan") == 0
					||	strcmp(resultField.InstructChain.getValue(),"IfsInfo") == 0
					||	strcmp(resultField.InstructChain.getValue(),"Spantree") == 0
					||	strcmp(resultField.InstructChain.getValue(),"CDPInfo") == 0
					||	strcmp(resultField.InstructChain.getValue(),"BgpSum") == 0
					||	strcmp(resultField.InstructChain.getValue(),"RouteStatic") == 0
					||	strcmp(resultField.InstructChain.getValue(),"OSPFNeighor") == 0
					||	strcmp(resultField.InstructChain.getValue(),"RouteInfo") == 0
					||	(strcmp(resultField.InstructChain.getValue(),"IfsState") == 0 && manufactory_id == 3
					)
					|| strcmp(resultField.InstructChain.getValue(),"InterfaceLostPkg") == 0
					/*|| (strcmp(resultField.InstructChain.getValue(),"Session") == 0 && manufactory_id == 1)*/)
				{
					//����ֵ�Ƚϣ�������֮��û��˳��������ϵ
					if (SubMatchInAttrList(
						regularparams,
						i_it->second.attrlist,
						attr_value_list) == 0)
					{
						regularpass = true;
					}
				}
				//�޸�QFPPacket��ֵ�ж� 2014.6.10 li.sc
				else if( strcmp(resultField.InstructChain.getValue(),"QFPPacket") == 0 && manufactory_id == 1 )
				{
					if( strstr(oldresult.c_str(),"taildrop")==NULL || strstr(oldresult.c_str(),"TAILDROP")==NULL )
					{
						regularpass = true;
					}
					else
						regularpass = false; 
					break;
				}
				else if( strcmp(resultField.InstructChain.getValue(),"HAState") == 0 && manufactory_id == 3 )
				{
					regularpass = ProcessF5HAState(regularparams, attr_value_list);
					break;
				}
				else if (strcmp(resultField.InstructChain.getValue(),"RunTime") == 0)
				{

					if (!ProcessRunTime(regularparams, attr_value_list))
					{
						regularpass = false;
						break;
					}
					else
					{
						regularpass = true;
					}
				}
				else if (strcmp(resultField.InstructChain.getValue(),"SoftwareStatus") == 0)
				{

					if (!ProcessSoftewareStatus(oldresult))
					{
						regularpass = false;
						break;
					}
					else
					{
						regularpass = true;
					}
				}
				else if ( (strcmp(resultField.InstructChain.getValue(),"LACPPDUSRPacket") == 0)
					     && manufactory_id == 4 )
				{
                    if ( !ProcessLACPPDUSRPacketStatus(attr_value_list,regularparams[j]) )
					{
						regularpass = false;
						break;
					}
					else
					{
						regularpass = true;
					}                    				    
				}
				else if ( ((strcmp(resultField.InstructChain.getValue(),"SrxFpc0Status") == 0)
					||(strcmp(resultField.InstructChain.getValue(),"SrxFpc1Status") == 0))
					&& manufactory_id == 4
					&& (strcmp(deviceserial.c_str(),"SRX") == 0))
				{
					if( !ProcessSrxFpcStatus(resultField,oldresult,manufactory_id,deviceserial))
					{
						regularpass = false;
						break;
					}
					else
					{
						regularpass = true;
					}
				}
				else
				{
					if (cmdregular.size() > 0)
					{
						//����һ������ѭ������
						bool grouppass = true;
						if ( attr_value_list.empty() )
						{
							grouppass = false;
						}

						for (int i = 0; i < attr_value_list.size(); ++i)
						{
							string	real_regular = ReplaceAttrByValue(
								attr_value_list[i],
								cmdregular);

							if (strcmp(resultField.InstructChain.getValue(),"PlatformState") == 0)
							{
								if(platform_state_parse(attr_value_list, i, grouppass, regularpass) == -1)
								{
									break;
								}
							}
							else if (strcmp(resultField.InstructChain.getValue(),"SoftwareStatus") == 0)
							{
								string	oriresult = attr_value_list[0][0].
									value;

								int loadstart = oriresult.find(
									"15-Min\r\n");
								int loadend = oriresult.find("Memory");
								if (loadstart != -1
									&&	loadend != -1
									&&	loadend >= loadstart)
								{
								}
								else
								{
									printf(
										"SoftwareStatus parse error, loadstart:%d, loadend:%d\n",
										loadstart,
										loadend);
								}

								int memorystart = oriresult.find("Committed (Pct)");
								int memoryend = oriresult.find("CPU");

								int cpustart = oriresult.find("IOwait");
								int cpuend = oriresult.length() - 1;
							}
							else
							{
								if(expr_caculate(real_regular, grouppass) == -1)
								{
									break;
								}
							}
						}

						if (grouppass)
						{
							regularpass = true;
							break;
						}
					}
				}
			}

			//���������ο��Ĺ��˹���		
			newresult += regularstr;

			if (!regularpass)
			{
				resultField.Flag = TASK_RESULT_ERROR;

				if (strcmp(resultField.InstructChain.getValue(),"SoftwareStatus") == 0)
					printf("@@@set Flag TASK_RESULT_ERROR\n");
			}
			else
			{
				resultField.Flag = TASK_SUCCESS;

				if (strcmp(resultField.InstructChain.getValue(),"SoftwareStatus") == 0)
					printf("@@@set Flag TASK_SUCCESS\n");

			}
		}
		else
		{
			printf(
				"device %s no regularparams instruction:%s serial:%s in %s\n",resultField.ObjectID.getValue(),
				resultField.InstructChain.getValue(),
				deviceserial.c_str(),
				__FUNCTION__);	
		}	
	}
	else
	{
		for(i_it = map_instr_info.begin();i_it != map_instr_info.end(); i_it++)
		{
			printf("all keys ares: [%s].\n",i_it->first.c_str());
		}
		printf(
			"no regular for instruction:%s serial:%s in %s\n",
			resultField.InstructChain.getValue(),
			deviceserial.c_str(),
			__FUNCTION__);
	}



	return 0;
}

void CEventCounterServer::process_memory_task(int manufactory_id,vector<vector<AttrNodeInfo> >& attr_value_list,int i,string	&newresult)
{
	float memavail = 0.0;
	float freenum = 0;
	float totalnum = 0;

	if (manufactory_id == 1)
	{
		for (int j = 0; j < attr_value_list[i].size(); ++j)
		{
			if (attr_value_list[i][j].key.compare(
				"memoryPoolFree") == 0)
			{
				freenum = atof(attr_value_list[i][j].value.c_str());
			}
			else if (attr_value_list[i][j].key.compare(
				"memoryPoolTotal") == 0)
			{
				totalnum = atof(
					attr_value_list[i][j].value.c_str());
			}
		}
	}
	else if (manufactory_id == 4)
	{
		for (int j = 0; j < attr_value_list[i].size(); ++j)
		{
			if (attr_value_list[i][j].key.compare("left") == 0)
			{
				freenum = atof(attr_value_list[i][j].value.c_str());
			}
		}

		for (int j = 0; j < attr_value_list[i].size(); ++j)
		{
			if (attr_value_list[i][j].key.compare("allocated") == 0)
			{
				totalnum = freenum + atof(
					attr_value_list[i][j].value.c_str());
			}
		}
	}
	else if (manufactory_id == 3)
	{
		for (int j = 0; j < attr_value_list[i].size(); ++j)
		{
			if (attr_value_list[i][j].key.compare("total") == 0)
			{
				//ͳһת��ΪMB 2013-01-25 by Lee
				int unit = 0;
				if (attr_value_list[i][j].value.find(
					"KB") != string::npos)
				{
					unit = -1;
				}
				else if (attr_value_list[i][j].value.find(
					"GB") != string::npos)
				{
					unit = 1;
				}

				//ȥ���ַ�����β������
				string	digitstr = attr_value_list[i][j].value.
					substr(
					1,
					attr_value_list[i][j].value.length() - 2);
				if (unit == 1)
				{
					totalnum = 1024 * atof(digitstr.c_str());
				}
				else if (unit == -1)
				{
					totalnum = atof(digitstr.c_str()) / 1024;
				}
				else if( unit == 0 )
				{
					totalnum = atof( digitstr.c_str() );
				}

				char buf[100] = { 0 };
				SNPRINTF(buf, 100, "%d", totalnum);
				attr_value_list[i][j].value = buf;
			}
			else if (attr_value_list[i][j].key.compare("used") == 0)
			{
				int unit = 0;
				if (attr_value_list[i][j].value.find(
					"KB") != string::npos)
				{
					unit = -1;
				}
				else if (attr_value_list[i][j].value.find(
					"GB") != string::npos)
				{
					unit = 1;
				}

				string	digitstr = attr_value_list[i][j].value.
					substr(
					1,
					attr_value_list[i][j].value.length() - 2);
				int used = atoi(digitstr.c_str());
				if (unit == 1)
				{
					used = 1024 * atof(digitstr.c_str());
				}
				else if (unit == -1)
				{
					used = atof(digitstr.c_str()) / 1024;
				}

				char buf[100] = { 0 };
				SNPRINTF(buf, 100, "%d", used);
				attr_value_list[i][j].value = buf;

				freenum = totalnum - used;
			}
		}
	}

	if (totalnum > 0)
	{
		memavail = 100 * (float)freenum / totalnum;
	}

	newresult += "MEMAvailable=";

	char tmp[100] = { 0 };
	SNPRINTF(tmp, 100, "%d;", (int)memavail);
	newresult += tmp;
}

void CEventCounterServer::pre_process_attrlist(CFTDRtnNetMonitorTaskResultField &resultField
	, vector<vector<AttrNodeInfo> >& attr_value_list, string & oldresult, int manufactory_id)
{
	//ֻ��ȡ��̬·����Ϣ
	if (strcmp(resultField.InstructChain.getValue(), "RouteStatic") == 0)
	{
		vector<vector<AttrNodeInfo> > routestatic_attrlist;

		for (int i = 0; i < attr_value_list.size(); ++i)
		{
			vector<AttrNodeInfo> inner_list;

			bool is_static_route = true;
			for (int j = 0; j < attr_value_list[i].size(); ++j)
			{
				if (attr_value_list[i][j].key.compare(
					"routetype") == 0
					&&	attr_value_list[i][j].value.compare(
					0,
					strlen("\"S"),
					"\"S") != 0)
				{
					//ֻ������̬·����Ϣ
					is_static_route = false;
					break;
				}

				if (attr_value_list[i][j].key.compare("routestatic") == 0)
				{
					inner_list.push_back(attr_value_list[i][j]);
				}
			}

			if (is_static_route)
			{
				routestatic_attrlist.push_back(inner_list);
			}
		}

		attr_value_list.swap(routestatic_attrlist);
	}
	else if (strcmp(resultField.InstructChain.getValue(), "VSInfo") == 0
		&&	 manufactory_id == 3)
	{
		attr_value_list.clear();

		vector<AttrNodeInfo> nodelist;

		string	valuestr = "\"";	//ָ������������Ч�еļ���
		string	str = oldresult;
		char *p = strtok((char *)str.c_str(), "\n");
		while (p)
		{
			//trimleft
			int len = strlen(p);
			for (int i = 0; i < len; ++i)
			{
				if (*p == ' ' || *p == '\t')
				{
					p++;
				}
			}

			if (strncmp(p, "VIRTUAL", strlen("VIRTUAL")) == 0
				||	(strncmp(p, "+->", strlen("+->")) == 0
				&& strstr(p, "CLIENT_ACCEPTED") == NULL ) )
			{
				if (valuestr.compare("\"") != 0)
				{
					valuestr += "\r\n";
				}

				valuestr += p;
			}

			p = strtok(NULL, "\n");
		}

		valuestr += "\"";

		AttrNodeInfo attrnode;

		attrnode.key = "vsinfo";
		attrnode.value = valuestr;

		nodelist.push_back(attrnode);
		attr_value_list.push_back(nodelist);
	}
}

int CEventCounterServer::platform_state_parse(vector<vector<AttrNodeInfo> >& attr_value_list, int i, bool& grouppass, bool& regularpass)
{
	bool hasType = false;

	for (int j = 0; j < attr_value_list[i].size();++j)
	{
		if (attr_value_list[i][j].key.compare("type") == 0)
		{
			hasType = true;

			bool hasState = false;
			for (int k = 0; k < attr_value_list[i].size(); ++k)
			{
				if (attr_value_list[i][k].key.compare("state") == 0)
				{
					hasState = true;

					string	typeupper =	attr_value_list[i][j].value;
					transform(attr_value_list[i][j].value.begin(),
						attr_value_list[i][j].value.end(),
						typeupper.begin(),
						::toupper);

					string	stateupper = attr_value_list[i][k].value;
					transform(
						attr_value_list[i][k].value.begin(),
						attr_value_list[i][k].value.end(),
						stateupper.begin(),
						::toupper);

					if (typeupper.compare("\"NPEG100 (ACTIVE)\"") == 0
						||	typeupper.compare("\"NPEG100 (STANDBY)\"") == 0)
					{
						if (stateupper.compare("\"UP\"") != 0)
						{
							regularpass = false;
							grouppass = false;
							break;
						}
						else
						{
							regularpass = true;
						}
					}
					else if (typeupper.compare("\"1PA CARRIER CARD\"") == 0)
					{
						if (stateupper.compare("\"ACTIVE\"") != 0)
						{
							regularpass = false;
							grouppass = false;
							break;
						}
						else
						{
							regularpass = true;
						}
					}
					else
					{
						regularpass = true;
					}

					break;
				}
			}

			if (!hasState)
			{
				printf(
					"no state attr found for PlatformState in %s\n",
					__FUNCTION__);
				regularpass = true;
			}
		}
	}

	if (!hasType)
	{
		printf(
			"no type attr found for PlatformState in %s\n",
			__FUNCTION__);
		regularpass = true;
	}

	if (!regularpass)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int CEventCounterServer::expr_caculate(string real_regular, bool & grouppass)
{
	try
	{
		printf("real:%s\n",real_regular.c_str());

		//����ָ�������
		CInputStreamPtr m_pStream = new
			CStringInputStream(
			real_regular.c_str());

		CExprNode<CValue> *m_pExpr =
			g_mEventParser.parse(m_pStream);

		if (g_pTaskContext)
		{
			//����������ʱ��
			g_pTaskContext->updateNow(
				time(NULL));

			CValue	&result = m_pExpr->eval(
				*g_pTaskContext);
			if (result.getDIntValue() <= 0)
			{
				grouppass = false;
				return -1;
			}
		}
		else
		{
			printf(
				"impossible, g_pTaskContext NULL!\n");
		}

		//m_pStream->decRef();
	}

	catch(...)
	{
		grouppass = false;
		return -1;
	}

	return 0;
}

bool CEventCounterServer::ProcessF5HAState(
	vector<map<int, string> > &regularparams, 
	vector<vector<AttrNodeInfo> > &attr_value_list)
{
	if (regularparams.size() != attr_value_list.size())
	{
		//�����ָ�������ƥ��
		return false;
	}

	map<int,string>::iterator it = regularparams[0].begin();
	int index = 0;
	for(; it != regularparams[0].end(); it++,index++ )
	{
		string refer = it->second;
		//ָ�괮
		string data = attr_value_list[0][index].value;

		if( index == 0 ) //��һ������ 
		{
			if( STRCMP(data.c_str(),refer.c_str()) != 0 )
			{
				return false;
			}
		}
		else if( index == 1 ) //�ڶ�������
		{
			int diff = data.length()-refer.length();
			if( diff>0 )
			{
				return true;
			}
			else if( diff == 0 )
			{
				return STRCMP(data.c_str(),refer.c_str());
			}
			else
			{
				return false;
			}
		}
	}
}

bool CEventCounterServer::ProcessRunTime(
	vector<map<int, string> > &regularparams,
	vector<vector<AttrNodeInfo> > &attr_value_list)
{
	if (regularparams.size() != attr_value_list.size())
	{
		//�����ָ�������ƥ��
		return false;
	}

	map<int, string>::iterator	r_i = regularparams[0].begin();
	if (r_i != regularparams[0].end())
	{
		//����ԭʼ��
		string	reg_str = r_i->second;

		if (attr_value_list[0].size() < 1)
		{
			//û�о����ָ��ֵ
			return false;
		}

		int reg_mins;

		int reg_hours;

		int reg_days;

		int reg_weeks = 0;

		reg_mins = CEventCounterServer::getTimeValueFromStr(reg_str, "minutes");
		reg_hours = CEventCounterServer::getTimeValueFromStr(reg_str, "hour");
		reg_days = CEventCounterServer::getTimeValueFromStr(reg_str, "day");
		reg_weeks = CEventCounterServer::getTimeValueFromStr(reg_str, "week");

		int reg_time = reg_weeks *
			7 *
			24 *
			60 +
			reg_days *
			24 *
			60 +
			reg_hours *
			60 +
			reg_mins;

		//ָ�괮
		string	attr_str = attr_value_list[0][0].value;

		if (attr_str.find("year") != string::npos)
		{
			//����ʱ�䳬��һ�꣬����
			return false;
		}

		int attr_mins;

		int attr_hours;

		int attr_days;

		int attr_weeks = 0;

		attr_mins = CEventCounterServer::getTimeValueFromStr(
			attr_str,
			"minutes");
		attr_hours = CEventCounterServer::getTimeValueFromStr(
			attr_str,
			"hour");
		attr_days = CEventCounterServer::getTimeValueFromStr(attr_str, "day");
		attr_weeks = CEventCounterServer::getTimeValueFromStr(
			attr_str,
			"week");

		int attr_time = attr_weeks *
			7 *
			24 *
			60 +
			attr_days *
			24 *
			60 +
			attr_hours *
			60 +
			attr_mins;

		if (attr_time > reg_time)
		{
			//ָ��ʱ�����ڹ���ʱ��Ϊ����
			return true;
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool CEventCounterServer::ProcessLACPPDUSRPacketStatus(vector<vector<AttrNodeInfo> >& attr_value_list,map<int, string>& regularparams)
{
	bool rst = false;
    if( attr_value_list.empty() || regularparams.empty() || regularparams.size() != 3 )
		return rst;
    string netif = regularparams[0];
	long r_packets = atof(regularparams[1].c_str());
	long s_packets = atof(regularparams[2].c_str());
	for( vector<vector<AttrNodeInfo> >::iterator v_beg= attr_value_list.begin(),v_end=attr_value_list.end(); v_beg != v_end; ++v_beg)
	{
	    if( v_beg->empty() || v_beg->size() != 3 )
			continue;
		if( (*v_beg)[0].value != netif )
		    continue;
		else
		{
			long tmp_r = atof((*v_beg)[1].value.c_str());
			long tmp_s = atof((*v_beg)[2].value.c_str());

			if ( tmp_r  > (r_packets-floor(r_packets*0.002)) &&
				 tmp_r  < (r_packets+ceil(r_packets*0.002)) &&
				 tmp_s  > (s_packets-floor(s_packets*0.002)) &&
				 tmp_s  < (s_packets+ceil(s_packets*0.002)) )
			{
				//ÿ���˿��շ�����������𲻳���ǧ��֮��
				//PASS
				rst = true;
			}
			else
			{
				rst = false;
			}
		    break;
		}
	}
	return rst;
}

bool CEventCounterServer::ProcessSrxFpcStatus(CFTDRtnNetMonitorTaskResultField &resultField,string result,int manufactory_id,string deviceserial)
{
	bool rst = true;
	char regular_key[1024];

	int ThreadHoldArrar[2]={60,60};

	//��ָ��ָ����в���Ĭ�ϵĹ���
	MAP_INSTR_INFO	map_instr_info = g_counterServer->m_cConfigConnector.GetTaskInstrInfo();
	//���Ȳ��Ҵ����ͺŵı��ʽ
	SNPRINTF(regular_key,1024,"%s_%d_%s",resultField.InstructChain.getValue(),manufactory_id,deviceserial.c_str());
	MAP_INSTRINFO_IT i_it = map_instr_info.find(regular_key);

	//���û�У��ٲ��Ҳ����ͺű��ʽ
	if( i_it == map_instr_info.end() )
	{
		memset(regular_key, 0, 1024);
		SNPRINTF(regular_key,1024,"%s_%d_",resultField.InstructChain.getValue(),manufactory_id);
		i_it = map_instr_info.find(regular_key);
	}
	if (i_it != map_instr_info.end())
	{
		if ( !i_it->second.defaultparams.empty())
		{
			if( i_it->second.defaultparams[0].size() == 2 )
			{
				ThreadHoldArrar[0] = atoi(i_it->second.defaultparams[0][0].c_str());//CPU threardhold
				ThreadHoldArrar[1] = atoi(i_it->second.defaultparams[0][1].c_str());//Memory threadhold
			}
		}
	}
	string expressArray[2]={"\\s+CPU\\D+(\\d+)(.*$)","\\s+Memory\\D+(\\d+)(.*$)"};
	string tmpstr;
	for ( int i=0; i<2; i++ )
	{
		try
		{
			tmpstr = result;
			regex expression(expressArray[i]);
			smatch  what;
			while ( regex_search( tmpstr,what,expression) )
			{
				if ( what.size() != 3 )
				{
					break;
				}
				if( atoi(what[1].str().c_str()) > ThreadHoldArrar[i] )
				{
					printf("ProcessSrxFpcStatus[%s][%s]>[%d],return fail!\n",i == 0 ? "CPU" : "Memory",what[1].str().c_str(),ThreadHoldArrar[i]);
					rst = false;
					return rst;
				}
				tmpstr = what[2];
				if ( tmpstr.empty())
				{
					break;
				}
			}
		}catch(...)
		{
			rst = false;
			printf("\nProcessSrxFpcStatus regex express[%s],rst[%s] error!\n",expressArray[i].c_str(),tmpstr.c_str());
		}
	}

	return rst;
}

void CEventCounterServer::remove_postfix_forSRX(string& oldresult)
{
	try
	{
		regex expression("^(.*)\\n[^\\n]+\\n$");
		cmatch  what;
		if (regex_match(oldresult.c_str(), what, expression))
		{
			if ( what.size() == 2 )
			{
				oldresult=what[1];
			}
		}
	}catch(...)
	{
		printf("remove_postfix_forSRX regex error!\n");
	}
}

bool CEventCounterServer::ProcessSoftewareStatus(string oldresult)
{
	//��ȡLoad Average����
	size_t	pos_load = oldresult.find("15-Min\r\n");

	//��ȡMemory����
	size_t	pos_mem = oldresult.find("\r\nMemory (kB)\r\n");

	//��ȡCPU����
	size_t	pos_cpu = oldresult.find("\r\nCPU Utilization\r\n");

	if (pos_load == string::npos
		||	pos_mem == string::npos
		||	pos_cpu == string::npos)
	{
		return false;
	}

	pos_load += strlen("15-Min\r\n");

	bool load_pass = true;
	string	load_str = oldresult.substr(pos_load, pos_mem - pos_load);
	while (load_str.length() > 0)
	{
		//���з���
		size_t	pos = load_str.find("\r\n");
		if (pos == string::npos)
		{
			if (load_str.find(" Healthy ") == string::npos)
			{
				load_pass = false;
				break;
			}
		}

		string	cur_str = load_str.substr(0, pos);
		if (cur_str.find(" Healthy ") == string::npos)
		{
			load_pass = false;
			break;
		}

		load_str = load_str.substr(pos + strlen("\r\n"));
	}

	if (!load_pass)
	{
		return false;
	}

	pos_mem = oldresult.find("Committed (Pct)\r\n", pos_mem);
	if (pos_mem == string::npos)
	{
		return false;
	}

	pos_mem += strlen("Committed (Pct)\r\n");

	bool mem_pass = true;
	string	mem_str = oldresult.substr(pos_mem, pos_cpu - pos_mem);
	while (mem_str.length() > 0)
	{
		//���з���
		size_t	pos = mem_str.find("\r\n");
		if (pos == string::npos)
		{

			if (mem_str.find(" Healthy ") == string::npos)
			{
				mem_pass = false;
				break;
			}
		}

		string	cur_str = mem_str.substr(0, pos);
		if (cur_str.find(" Healthy ") == string::npos)
		{
			mem_pass = false;
			break;
		}

		mem_str = mem_str.substr(pos + strlen("\r\n"));
	}

	if (!mem_pass)
	{
		return false;
	}

	pos_cpu = oldresult.find("IOwait\r\n", pos_cpu);
	if (pos_cpu == string::npos)
	{
		return false;
	}

	pos_cpu += strlen("IOwait\r\n");

	bool cpu_pass = true;
	string	cpu_str = oldresult.substr(pos_cpu);
	char *cpubuf = new char[cpu_str.length() + 1];
	memset(cpubuf, 0, cpu_str.length() + 1);
	memcpy(cpubuf, cpu_str.c_str(), cpu_str.length());

	char *p = strtok(cpubuf, "\r\n");
	while (p)
	{
		vector<string>	result;
		CConfigConnector::splitStringBySeprator(p, " ", result);

		//ɾ�����ڿո���ȡ�Ŀ�����
		vector<string>::iterator iter = result.begin();
		while (iter != result.end())
		{
			if (iter->size() == 0)
			{
				iter = result.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		//�������ĸ�ֵΪidle
		if (result.size() >= 4)
		{
			float idle = atof(result[result.size() - 4].c_str());
			if (idle <= 80)
			{
				cpu_pass = false;
				break;
			}
		}

		p = strtok(NULL, "\r\n");
	}

	delete[] cpubuf;

	if (!cpu_pass)
	{
		return false;
	}

	return true;
}

int CEventCounterServer::getTimeValueFromStr(
	string	&valuestring,
	const char	*typestring)
{
	int timevalue = 0;

	size_t	pos_end = valuestring.rfind(typestring);
	if (pos_end != string::npos)
	{
		size_t	pos_start = valuestring.rfind(",", pos_end);
		if (pos_start == string::npos)
		{
			pos_start = 0; //�ַ���ǰ��������ţ��ʸ�ֵΪ0
		}

		string	str = valuestring.substr(
			pos_start + 1,
			pos_end - pos_start - 1);
		timevalue = atoi(str.c_str());
	}

	return timevalue;
}

int CEventCounterServer::SubMatchInResult(
	vector<map<int, string> > &regularparams,
	string	result)
{
	//�����ؽ�����в��
	vector<string>	rows;
	CConfigConnector::splitStringBySeprator(result, "\r\n", rows);

	//���Ҹ����������Ƿ�����������ƥ��
	for (int j = 0; j < regularparams.size(); ++j)
	{
		bool bOneRowMatch = false;
		for (int i = 0; i < rows.size(); ++i)
		{
			bOneRowMatch = true;

			map<int, string>::iterator	r_i = regularparams[j].begin();
			while (r_i != regularparams[j].end())
			{
				size_t	pos = rows[i].find(r_i->second);
				if (pos == string::npos)
				{
					bOneRowMatch = false;
					break;
				}
				else
				{
					//�ų����Ӽ��������һ��Ҫ����ƥ��
					if (pos == 0)
					{
						if (isalnum(rows[i][pos + r_i->second.size()]))
						{
							bOneRowMatch = false;
							break;
						}
					}
					else
					{
						if (isalnum(rows[i][pos - 1])
							||	isalnum(rows[i][pos + r_i->second.size()]))
						{
							bOneRowMatch = false;
							break;
						}
					}

					++r_i;
				}
			}

			if (bOneRowMatch)
			{
				break;
			}
		}

		if (!bOneRowMatch)
		{
			return -1;
		}
	}

	return 0;
}

int CEventCounterServer::ParseEnv_3825(string result, string &newresult)
{
	//���г���Fan��temperature��Voltage���ж���Normal״̬
	vector<string>	rows;
	CConfigConnector::splitStringBySeprator(result, "\r\n", rows);

	bool isValid = true;

	for (int i = 0; i < rows.size(); ++i)
	{
		size_t	pos = rows[i].find("Fan");
		if (pos == string::npos)
		{
			pos = rows[i].find("temperature");
			if (pos == string::npos)
			{
				pos = rows[i].find("Voltage");
			}
		}

		if (pos != string::npos)
		{
			pos = rows[i].find("Normal");
			if (pos == string::npos)
			{
				if (rows[i].find("warning") == string::npos)
				{
					isValid = false;
					rows[i] += "(���в�ƥ�䣬����warning)";
				}
			}
		}

		newresult += rows[i];
	}

	newresult += ";";
	newresult += "*@*���г���Fan��temperature��Voltage���ж���Normal״̬";

	return isValid ? 0 : 1;
}

int CEventCounterServer::ParseEnv_3945(string result, string &newresult)
{
	//SYSTEM POWER SUPPLY STATUS��Output Status: Normal��SYSTEM FAN STATUS��Fan xx is OK��SYSTEM TEMPERATURE STATUS��temperature Normal
	vector<string>	rows;
	CConfigConnector::splitStringBySeprator(result, "\r\n", rows);

	bool isValid = true;

	for (int i = 0; i < rows.size(); ++i)
	{
		size_t	pos = rows[i].find("Output Status");
		if (pos != string::npos)
		{
			pos = rows[i].find("Normal");
			if (pos == string::npos)
			{
				isValid = false;
				rows[i] += "(���в�ƥ��, Output Status����Normal)";
			}

			newresult += rows[i];
			continue;
		}

		pos = rows[i].find("Fan");
		if (pos != string::npos)
		{
			pos = rows[i].find("OK");
			if (pos == string::npos)
			{
				isValid = false;
				rows[i] += "(���в�ƥ�䣬Fan����OK)";
			}

			newresult += rows[i];
			continue;
		}

		pos = rows[i].find("temperature");
		if (pos != string::npos)
		{
			pos = rows[i].find("Normal");
			if (pos == string::npos)
			{
				isValid = false;
				rows[i] += "(���в�ƥ��,temperature����Normal)";
			}

			newresult += rows[i];
			continue;
		}

		newresult += rows[i];
	}

	newresult += ";";
	newresult += "*@*SYSTEM POWER SUPPLY STATUS��Output Status: Normal��SYSTEM FAN STATUS��Fan xx is OK��SYSTEM TEMPERATURE STATUS��temperature Normal";

	return isValid ? 0 : 1;
}

int CEventCounterServer::ParseEnv_5350(string result, string &newresult)
{
	//����Temperature is in normal state��Voltage is in 0 state��Power Supply������status��Ϊnormal
	size_t	pos = result.find("Temperature is in normal state");
	if (pos == string::npos)
	{
		newresult = result;
		newresult += "(û�ҵ�Temperature is in normal state)";
		return -1;
	}

	pos = result.find("Voltage is in 0 state");
	if (pos == string::npos)
	{
		newresult = result;
		newresult += "(û�ҵ�Voltage is in 0 state)";
		return -1;
	}

	bool isValid = true;

	pos = result.find("Power Supply");
	if (pos != string::npos)
	{
		vector<string>	rows;
		CConfigConnector::splitStringBySeprator(
			result.substr(pos),
			"\r\n",
			rows);

		for (int i = 0; i < rows.size(); ++i)
		{
			pos = rows[i].find("status");
			if (pos != string::npos)
			{
				pos = rows[i].find("normal");
				if (pos == string::npos)
				{
					isValid = false;
					rows[i] += "(���в�ƥ��, status����normal)";
				}
			}

			newresult += rows[i];
		}
	}
	else
	{
		newresult = result;
	}

	newresult += ";";
	newresult += "*@*����Temperature is in normal state��Voltage is in 0 state��Power Supply������status��Ϊnormal";

	return isValid ? 0 : 1;
}

int CEventCounterServer::ParseEnv_7304(string result, string &newresult)
{
	//�¶���Ŀ��ΪAll measured readings are normal ��Fan xx is on
	vector<string>	rows;
	CConfigConnector::splitStringBySeprator(result, "\r\n", rows);

	bool isValid = true;

	for (int i = 0; i < rows.size(); ++i)
	{
		size_t	pos = rows[i].find("All measured readings");
		if (pos != string::npos)
		{
			pos = rows[i].find("normal");
			if (pos == string::npos)
			{
				isValid = false;
				rows[i] += "(���в�ƥ��, All measured readings����normal)";
			}
		}

		pos = rows[i].find("Fan");
		if (pos != string::npos)
		{
			pos = rows[i].find("on");
			if (pos == string::npos)
			{
				isValid = false;
				rows[i] += "(���в�ƥ��, Fan����on)";
			}
		}

		newresult += rows[i];
	}

	newresult += ";";
	newresult += "*@*�¶���Ŀ��ΪAll measured readings are normal ��Fan xx is on";

	return isValid ? 0 : 1;
}


int CEventCounterServer::ParseConSessions_SRX(string result)
{
	string key = "Unicast-sessions: ";
	long count = 0;
	char *delim=NULL;
	char *q=NULL;
	if(result.find("\r\n")!=string::npos)
	{
		delim = "\r\n";
	}
	else
	{
		delim = "\n";
	}

	char *p = strtok((char *)result.c_str(),delim);
	if( NULL != p )
	{
		//��1�в�����
		while( ( p = strtok(NULL,delim) ) != NULL )
		{
			if( (q = strstr(p, key.c_str())) != NULL )
			{
				q = q + key.length();				
				count += atoi( trim(q) );
			}
		}
	}

	return count;
}

int CEventCounterServer::ParseREUsage_SRX(string result, string &newresult)
{
	char *delim=NULL;	
	int length = 0;
	size_t index = 0;
	string data="";

	newresult = result;
	newresult += "*@*";
	newresult += "node0��node1�ϵ�·������current state��Ϊmaster��memory utilС��30��cpu idle����70��load averageС��20��uptime���ڷ�ֵ";

	try
	{
		cmatch	what;
		regex expression("^.*?Current state[ ]*([^ \r\n]*)[ \r\n]*?.*?Memory utilization[ ]*([0-9]*)[ \r\n]*.*?Idle[ ]*([0-9]*)[ \r\n]*.*?Load averages:[^\r\n]*[ \r\n]*([^ \r\n]*[^\r\n]*).*$");
	
		if(result.find("\r\n")!=string::npos)
		{
			delim = "\r\n\r\n";
		}
		else
		{
			delim = "\n\n";
		}

		while( length<result.length() )
		{
			data = "";
			index = result.find(delim, length);
			if( index != string::npos )
			{
				data = result.substr(length,index-length);
			}
			else
			{
				data = result.substr(length);
				length +=result.length(); //ȷ��whileѭ������
			}
			length += (data.length()+strlen(delim));

			if (regex_match(data.c_str(), what, expression))
			{
				for (int i = 1; i < what.size(); i++)
				{
					string	value = trim((char *)what[i].str().c_str());
					switch(i)
					{
						case 1:
							if(value.compare("Master")!=0)
							{
								printf("current state is:%s,not match Master\n",value.c_str());
								return -1;
							}
							break;
						case 2:
							if( atoi(value.c_str())>=30 )
							{
								printf("warning:mem utilization is:%s,not match < 30\n",value.c_str());
								return -1;
							}
							break;
						case 3:
							if( atoi(value.c_str())<=70 )
							{
								printf("warning:cpu idle is:%s,not match > 70\n",value.c_str());
								return -1;
							}
							break;
						case 4:
							float f1,f5,f15;
							sscanf(value.c_str(),"%f %f %f\n",&f1,&f5,&f15);
							if( f1>20 || f5>20 || f15>20 )
							{
								printf("warning:load  is:%f, %f, %f,not match < 20\n",f1,f5,f15);
								return -1;
							}
							break;
						default:
							break;
					}
				}
	
			}
			else
			{
				printf("Error Input.\n");
				newresult += "Error Input";
				return -1;
			}
		}
	}catch(...)
	{
		printf("ParseREUsage_SRX regex exception!\n");
		return -1;
	}
	return 0;
}

int CEventCounterServer::ParsePerfSession_SRX(CFTDRtnNetMonitorTaskResultField &resultField,string result,int manufactory_id,string deviceserial,int& threadhold)
{
	int rst = 0;

	threadhold = 0;
	char regular_key[1024];

	//��ָ��ָ����в���Ĭ�ϵĹ���
	MAP_INSTR_INFO	map_instr_info = g_counterServer->m_cConfigConnector.GetTaskInstrInfo();
	//���Ȳ��Ҵ����ͺŵı��ʽ
	SNPRINTF(regular_key,1024,"%s_%d_%s",resultField.InstructChain.getValue(),manufactory_id,deviceserial.c_str());
	MAP_INSTRINFO_IT i_it = map_instr_info.find(regular_key);

	//���û�У��ٲ��Ҳ����ͺű��ʽ
	if( i_it == map_instr_info.end() )
	{
		memset(regular_key, 0, 1024);
		SNPRINTF(regular_key,1024,"%s_%d_",resultField.InstructChain.getValue(),manufactory_id);
		i_it = map_instr_info.find(regular_key);
	}
	bool setthreadhold = false;

	if (i_it != map_instr_info.end())
	{
		if ( !i_it->second.defaultparams.empty())
		{
			if( !i_it->second.defaultparams[0].empty() )
			{
				setthreadhold = true;
				threadhold = atoi(i_it->second.defaultparams[0][0].c_str());
			}
		}
	}
	if ( !setthreadhold )
	{
		threadhold = 200;
	}
	try
	{
		regex expression("\\s*\\d+:\\s*(\\d+)\\s*\\d+:\\s*(\\d+)\\s*\\d+:\\s*(\\d+)\\s*\\d+:\\s*(\\d+)\\s*\\d+:\\s*(\\d+)\\s*\\d+:\\s*(\\d+)\\s*(.*$)");
		smatch  what;
		while ( regex_search(result,what,expression) )
		{
			if ( what.size() != 8 )
			{
				break;
			}
			for ( int beg=1,end=what.size()-1; beg < end; ++beg)
			{
				if ( atoi(what[beg].str().c_str()) > threadhold)
				{
					printf("ParsePerfSession_SRX [%s>%d] ,return fail!\n",what[beg].str().c_str(),threadhold);
					rst = -1;
					return rst;
				}
			}
			result=what[7];
			if ( result.empty())
			{
				break;
			}
		}
	}catch (...)
	{
		rst = -1;
		printf("\nParsePerfSession_SRX regex error, rst[%s]!\n",result.c_str());
	}

	return rst;
}

int CEventCounterServer::ParseFPC_SRX(string result, string &newresult)
{
	char *delim=NULL;	
	int length = 0;
	size_t index = 0;
	string data="";

	newresult = result;
	newresult += "*@*";
	newresult += "�¶Ȳ��˳���75���϶ȣ�cpuʹ���ʺ��ڴ�ʹ���ʲ��˳���90%";


	cmatch	what;
	regex expression("^.*Buffer[ \r\n]*(.*)$"); //data
	regex exp_sub("^[ ]*[0-9]+[ ]*[^ ]*[ ]+([0-9]*)[ ]*([0-9]*)[ ]*[0-9]+[ ]+[0-9]+[ ]+([0-9]+)[ ]+([0-9]+)[ \r\n]*(.*)$"); //state
	
	if(result.find("\r\n")!=string::npos)
	{
		delim = "\r\n\r\n";
	}
	else
	{
		delim = "\n\n";
	}

	while( length<result.length() )
	{
		index = result.find(delim, length);
		if( index != string::npos )
		{
			data = result.substr(length,index-length);
		}
		else
		{
			data = result.substr(length);
			length +=result.length(); //ȷ��whileѭ������
		}
		length += (data.length()+strlen(delim));

		if (regex_match(data.c_str(), what, expression))
		{
			string temp = trim((char *)what[1].str().c_str());
			while( temp.length()> 0 )
			{
				if (regex_match(temp.c_str(), what, exp_sub))
				{
					for (int i = 1; i < what.size(); i++)
					{
						string	value = trim((char *)what[i].str().c_str());
						switch(i)
						{
							case 1:
								if( atoi(value.c_str())>75 )
								{
									printf("temp is:%s,not match <=75\n",value.c_str());
									return -1;
								}
								break;
							case 2:
							case 3:
							case 4:
								if( atoi(value.c_str())>90 )
								{
									printf("warning:cpu/mem utilization is:%s,not match <= 90\n",value.c_str());
									return -1;
								}
								break;
							case 5:
								temp = value;
								break;
							default:
								break;
						}
					}
				}
				else
				{
					printf("Error Input.\n");
					newresult += "Error Input";
					return -1;
				}
			}

		}
		else
		{
			printf("Error Input.\n");
			newresult += "Error Input";
			return -1;
		}
		data = "";
	}
	return 0;
}

int CEventCounterServer::SubMatchInAttrList(
	vector<map<int, string> > &regularparams,
	vector<string>	attrlist,
	vector<vector<AttrNodeInfo> > &valuelist)
{
	//���Ҹ����������Ƿ�����������ƥ��
	for (int j = 0; j < regularparams.size(); ++j)
	{
		bool bOneRowMatch = false;
		for (int i = 0; i < valuelist.size(); ++i)
		{
			bOneRowMatch = true;

			map<int, string>::iterator	r_i = regularparams[j].begin();

			while (r_i != regularparams[j].end())
			{
				if (attrlist.size() < r_i->first + 1)
				{
					printf(
						"attrlist size:%d != regularparams size:%d in %s\n",
						attrlist.size(),
						r_i->first,
						__FUNCTION__);
					return -1;
				}

				bool hasRowInfo = false;

				for (int j = 0; j < valuelist[i].size(); ++j)
				{
					if (valuelist[i][j].key.compare(attrlist[r_i->first]) == 0)
					{
						if (r_i->second.compare(valuelist[i][j].value) != 0)
						{
							bOneRowMatch = false;
						}
						else
						{
							++r_i;
						}

						hasRowInfo = true;
						break;
					}
				}

				if (!hasRowInfo)
				{
					bOneRowMatch = false;
					break;
				}
				else if (!bOneRowMatch)
				{
					break;
				}
			}

			if (bOneRowMatch)
			{
				break;
			}
		}

		if (!bOneRowMatch)
		{
			return -1;
		}
	}

	return 0;
}

void CEventCounterServer::ReplayString(
	string	&ori,
	string	&srcContent,
	string	&dstContent,
	string	&result)
{
	result = ori;

	//�������еı����滻�ɾ����ֵ
	string	expr_bak;
	while (result.compare(expr_bak) != 0)
	{
		expr_bak = result;

		int pos = result.find(srcContent);
		if (pos == string::npos)
		{
			break;
		}

		//�ų����Ӽ��������һ��Ҫ����ƥ��
		//eg:��"ab"�滻"abc"
		if (pos == 0)
		{
			if (isalnum(result[pos + srcContent.size()]))
			{
				continue;
			}
		}
		else
		{
			if (isalnum(result[pos - 1])
				||	((pos + srcContent.size() < result.size()) && isalnum(result[pos + srcContent.size()])))
			{
				continue;
			}
		}

		result.replace(result.find(srcContent), srcContent.size(), dstContent);
	}
}

bool CEventCounterServer::test_trading(string inputstr)
{
	try
	{
		//����ָ�������
		CInputStreamPtr m_pStream=new CStringInputStream(inputstr.c_str());

		CExprNode<CValue> *m_pExpr=g_mEventParser.parse(m_pStream);

		if(g_pTaskContext)
		{
			//����������ʱ��
			g_pTaskContext->updateNow(time(NULL));

			CValue& result=m_pExpr->eval(*g_pTaskContext);
			if (result.getDIntValue() <= 0) 
			{
				return false;
			}		
			else
			{
				return true;
			}
		}
		else
		{
			printf("impossible, g_pTaskContext NULL!\n");
			return false;
		}
	}
	catch(...)
	{
		printf("Exception throws in %s\n", __FUNCTION__);
		return false;
	}	
}

bool checkSubString(const char *pObjectId, list<string> &listDropId)
{
	for (list<string>::iterator itList = listDropId.begin();
		itList != listDropId.end();
		itList++)
	{
		if (strstr(pObjectId, (*itList).c_str()) != NULL)
		{
			return true;
		}
	}

	return false;
}

///�����ݶ��ж����¼�д�뵽ǰ�õ����Ͳ�ѯ��
///@param	frontFlow	ǰ�ö��ĵ�������
///@param	queryFlow	��ѯ���������ĵ�������
///@param	listSession	��Ҫֱ�ӷ��͵�FTDSession�б�
///@param	nEventId	ȫ�ָ澯�¼������ĵ������
///@param	mapEventDeplayTime	�澯�¼����ӳ�����ʱ��map
void CListWarningEventField::ReadValue(CEventCounterServer * &eventcounter)
{
	if (m_lockData.TryLock())
	{
		list<CWarnInfo>::iterator it = m_listEvent.begin();
		for (it; it != m_listEvent.end(); ++it)
		{
			/// Mod by Henchi, 20110413
			/// ����澯״̬������m_cDropEventIdList���棬����g_pDataCenter����
			if (g_pDataCenter->IsObjectEventOff(
				(char *)it->m_warningField.ObjectID.getValue()))
			{
				printf(
					"--- Notice: ObjectID [%s] Warnning Event [%s] drop!\n",
					it->m_warningField.ObjectID.getValue(),
					it->m_warningField.EventName.getValue());
				continue;
			}

#if 0
			if (checkSubString(
				it->m_warningField.ObjectID.getValue(),
				listDropId))
			{
				continue;
			}

#endif
			/// Added by Henchi, 20120228
			/// ���Ӷ���IP��Ϣ
			if (strlen(it->m_warningField.IPAddress.getValue()) == 0)
			{
				it->m_warningField.IPAddress = g_pDataCenter->
					getAddressByObjectID(
					(char *)(it->m_warningField.ObjectID.getValue())).c_str();
			}

			if (!g_mConfigControlEvent)
			{
				it->m_warningField.EvendID = eventcounter->m_mWarningEventId++;

				map<int, string>::iterator p_it = g_mapEventProcessFlag.find(it->m_warningField.EventNum.getValue());
				if(p_it != g_mapEventProcessFlag.end())
				{
					//���¼����ڴ����·������¼�Ҳ��Ϊ������
					if(p_it->second.compare("=")== 0 && it->m_warningField.ProcessFlag == "N")
					{
						it->m_warningField.ProcessFlag = p_it->second.c_str();
					}
					else
					{
						p_it->second = it->m_warningField.ProcessFlag.getValue();
					}
				}
				else
				{
					g_mapEventProcessFlag[it->m_warningField.EventNum.getValue()] = it->m_warningField.ProcessFlag.getValue();
				}

				//��ӵ�δ����ĸ澯�¼���
				g_warningEventManager.add_warning_event(it->m_warningField);
			}

			//else ת��configͳһ����
			//���¸澯����
			eventcounter->UpdateWarningCount(it->m_warningField);

			string	delay_key = it->m_warningField.ObjectID.getValue();
			delay_key += ";;";
			delay_key += it->m_warningField.EventName.getValue();

			map<string, CObjectAttrKey>::iterator map_it = g_mapEventDelayTime.
				find(delay_key);
			if (map_it != g_mapEventDelayTime.end())
			{
				///�����ǰ�¼�������ʱ����ӳٵ�����ʱ�����ɾ��map�еĸýڵ�
				if (strcmp(
					it->m_warningField.MonDate.getValue(),
					map_it->second.m_nObjectID.c_str()) > 0
					||	(
					strcmp(
					it->m_warningField.MonDate.getValue(),
					map_it->second.m_nObjectID.c_str()) == 0 && strcmp(
					it->m_warningField.MonTime.getValue(),
					map_it->second.m_nAttrID.c_str()) > 0
					))
				{
					g_mapEventDelayTime.erase(map_it);
				}
				else	///��ǰ�¼�������ʱ�����ӳٵ�����ʱ�䷶Χ�ڣ��Զ�����ø澯�����ñ��ΪY
				{
					char szDealDes[64];
					sprintf(
						szDealDes,
						"[%s %s][system]�����¼����ڸ澯�ӳ�ʱ��(�Զ�����)",
						it->m_warningField.MonDate.getValue(),
						it->m_warningField.MonTime.getValue());

					if(it->m_warningField.ProcessFlag == "=" 
						&& map_it->second.m_sProcessFlag.compare("Y") == 0)
					{
						//�¼���ԭ����
						g_mapEventDelayTime.erase(map_it);
					}
					else
					{
						it->m_warningField.ProcessFlag = map_it->second.m_sProcessFlag.c_str();
						it->m_warningField.EventDealDes = map_it->second.m_sEventDes.c_str();
					}
				}
			}

			if(it->m_warningField.ProcessFlag == "N")
			{
				//send mms
				string	membername;
				eventcounter->m_cConfigConnector.GetPartyLinkMemberName(
					it->m_warningField,
					membername);

				string	devname;
				eventcounter->m_cConfigConnector.GetDeviceName(
					it->m_warningField.ObjectID.getValue(),
					devname);

				int warningcount = eventcounter->GetWarningCount(
					it->m_warningField);

				g_MsgGenerator.AddEvent(
					it->m_warningField,
					warningcount,
					(char *)devname.c_str(),
					(char *)membername.c_str());
			}

			m_pkgSend.PreparePackage(FTD_TID_RtnWarningEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &((*it).m_warningField));

			m_pkgSend.MakePackage();
			eventcounter->m_cFrontServer.m_pCurrFrontFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
			eventcounter->m_cFrontServer.m_pCurrOracleFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());

			m_pkgSend.ValidPackage();
			eventcounter->m_cProbeServer.SendPackageAllSession(&m_pkgSend);

			m_pkgSend.PreparePackage(FTD_TID_RtnWarningQueryTopic,FTDC_CHAIN_LAST,FTD_VERSION);
			it->m_warningInfo.EvendID = it->m_warningField.EvendID;
			FTDC_ADD_FIELD(&m_pkgSend, &((*it).m_warningInfo));

			m_pkgSend.MakePackage();
			eventcounter->m_cFrontServer.m_pCurrFrontFlow->Append(m_pkgSend.Address(),m_pkgSend.Length());
		}

		m_listEvent.clear();
		m_lockData.UnLock();
	}
}

void CEventCounterServer::loadXmlConfig(void)
{
	if (m_sXMLFileName.length() == 0)
	{
		return;
	}

	m_mapProbeConfig.clear();
	m_chgWarnLevelIPList.clear();

	XMLNodeType NodeType = XMLTag;
	CXMLDoc *pXMLDoc = new CXMLDoc();
	pXMLDoc->read((char *)m_sXMLFileName.c_str());

	CXMLNode *pXMLRoot = pXMLDoc->getRootNode();

	CXMLNode *pServiceNode = pXMLRoot->findNode(
		NodeType,
		"AttrConfig",
		NULL,
		NULL);
	CXMLNodeList *pNodeList = pServiceNode->getNodeList();
	if (pNodeList != NULL)
	{
		CXMLNode *pNode = (*pNodeList)[0];
		for (int i = 0; i < (int)pNodeList->size(); i++)
		{
			CXMLNode *pNodeCur = (*pNodeList)[i];

			//printf("\t%s \n",pNodeCur->findProperty("ObjectId"));
			//printf("\t%s \n",pNodeCur->findProperty("Attr"));
			m_mapProbeConfig[CObjectAttrKey(
				pNodeCur->findProperty("ObjectId"),
				pNodeCur->findProperty("Attr"))] = 1;
		}
	}

	//��ȡ��Ҫ�����澯�����ip�б�
	CXMLNode *pIPListNode = pXMLRoot->findNode(NodeType, "IPList", NULL, NULL);
	if (pIPListNode)
	{
		pNodeList = pIPListNode->getNodeList();
		if (pNodeList != NULL)
		{
			CXMLNode *pNode = (*pNodeList)[0];
			for (int i = 0; i < (int)pNodeList->size(); i++)
			{
				CXMLNode *pNodeCur = (*pNodeList)[i];
				m_chgWarnLevelIPList[trim(pNodeCur->findProperty("IP"))] = 1;
			}
		}
	}
	else
	{
		printf("no IPLIST config info from file:%s\n", m_sXMLFileName.c_str());
	}

	CXMLNode *pTradingSetionStatNode = pXMLRoot->findNode(
		NodeType,
		"TradingSetionStat",
		NULL,
		NULL);
	if (pTradingSetionStatNode)
	{
		/// ���ö������ʼ��һ��
		if (g_nTradingSectionStatFlag == 0)
		{
			/// ��ʼ�����׽���Ϣ
			CXMLNode *pTradingSetionsNode = pTradingSetionStatNode->findNode(
				NodeType,
				"TradingSetions",
				NULL,
				NULL);
			if (pTradingSetionsNode != NULL)
			{
				CXMLNodeList *pTheNodeList = pTradingSetionsNode->getNodeList();
				if (pTheNodeList != NULL)
				{
					m_TradeSectionsVec.clear();
					for (int i = 0; i < (int)pTheNodeList->size(); i++)
					{
						TradeSectionInfo TradeSection;
						CXMLNode *pTheNode = (*pTheNodeList)[i];
						TradeSection.name = trim(
							pTheNode->findProperty("name"));
						TradeSection.comment = trim(
							pTheNode->findProperty("comment"));
						TradeSection.left = trim(
							pTheNode->findProperty("left"));
						TradeSection.left_drift = trim(
							pTheNode->findProperty("left_drift"));
						TradeSection.right = trim(
							pTheNode->findProperty("right"));
						TradeSection.right_drift = trim(
							pTheNode->findProperty("right_drift"));
						TradeSection.left_time = TIME_TO_LONG(
							(char *)TradeSection.left.c_str()) + atoi(TradeSection.left_drift.c_str());
						TradeSection.right_time = TIME_TO_LONG(
							(char *)TradeSection.right.c_str()) + atoi(TradeSection.right_drift.c_str());
						m_TradeSectionsVec.push_back(TradeSection);
					}
				}
			}

			/// ��ʼ������ָ����Ϣ
			CXMLNode *pObjectAttrNode = pTradingSetionStatNode->findNode(
				NodeType,
				"ObjectAttr",
				NULL,
				NULL);
			if (pObjectAttrNode != NULL)
			{
				CXMLNodeList *pTheNodeList = pObjectAttrNode->getNodeList();
				if (pTheNodeList != NULL)
				{
					m_StatObjectAttrMap.clear();
					for (int i = 0; i < (int)pTheNodeList->size(); i++)
					{
						CXMLNode *pTheNode = (*pTheNodeList)[i];
						CObjectAttrKey	ObjectAttr(
							trim(pTheNode->findProperty("ObjectId")),
							trim(pTheNode->findProperty("Attr")));
						m_StatObjectAttrMap[ObjectAttr] = 1;
					}
				}
			}

			if (m_TradeSectionsVec.size() > 0 && m_StatObjectAttrMap.size() > 0)
			{
				g_nTradingSectionStatFlag = 1;
			}
		}
	}
	else
	{
		printf(
			"no TradingSetionStat config info from file:%s\n",
			m_sXMLFileName.c_str());
	}

	map<string, int>::iterator	i_it = m_chgWarnLevelIPList.begin();
	for (; i_it != m_chgWarnLevelIPList.end(); ++i_it)
	{
		printf("chgWarnLevelIP:%s\n", i_it->first.c_str());
	}

	//�ǽ������б�
	CXMLNode *pNoTradingDaysNode = pXMLRoot->findNode(NodeType, "NoTradingDays", NULL,  NULL);
	if(pNoTradingDaysNode)
	{
		pNodeList = pNoTradingDaysNode->getNodeList();
		if (pNodeList!=NULL)
		{
			CXMLNode *pNode = (*pNodeList)[0];
			for (int i = 0; i < (int)pNodeList->size(); i++)
			{
				CXMLNode *pNodeCur = (*pNodeList)[i];
				if(pNodeCur->findProperty("day"))
				{
					g_calender.AddHoliday(pNodeCur->findProperty("day"));
				}
				else
				{
					printf("invalid notradingday config, day property empty!\n");
				}
			}
		}
	}
}

string CEventCounterServer::modifyWarningEventLevel(string ip, string orilevel)
{
	string	newlevel;

	map<string, int>::iterator	l_i = m_chgWarnLevelIPList.find(ip);
	if (l_i != m_chgWarnLevelIPList.end())
	{
		int eventlevel = atoi(orilevel.substr(orilevel.length() - 1).c_str());
		if (eventlevel < 4)
		{
			eventlevel++;
		}

		char levelbuf[100] = { 0 };
		sprintf(
			levelbuf,
			"%s%d",
			orilevel.substr(0, orilevel.length() - 1).c_str(),
			eventlevel);

		newlevel = levelbuf;
	}
	else
	{
		newlevel = orilevel;
	}

	return newlevel;
}

int CEventCounterServer::CheckFileVersion(
	string	objectid,
	string	buffer,
	string	filedate,
	string	filetime)
{
	int ret = -1;  //�ļ��ȽϽ����ʶ��0��ʾһ�£���������.
	//ȥ��":"
	char newtime[10] = { 0 };
	int i;
	int j;
	for (i = 0, j = 0; i < filetime.size() && j < 10; ++i)
	{
		if (filetime[i] != ':')
		{
			newtime[j++] = filetime[i];
		}
	}

	string	szFileName = objectid;
	szFileName += "_";
	szFileName += filedate;
	szFileName += "_";
	szFileName += newtime;

	szFileName += ".txt";

	string	szFilePath = m_sFilePath + objectid;

	//����Ŀ¼
	CreatePath(szFilePath.c_str());

#ifdef WIN32
	szFilePath +="\\";
#else
	szFilePath += "/";
#endif

	string lastFileName;

	//����·�������ļ�����ȡ����ļ�����
	if( !GetLastFileName(objectid, szFilePath, szFileName, lastFileName) )
	{
		printf("Failed to GetLastFileName with path [%s] and filename [%s].\n", szFilePath.c_str(),szFileName.c_str());
	}

	szFilePath += szFileName;

	FILE *m_fOutput = fopen(szFilePath.c_str(), "w");
	if (!m_fOutput)
	{
		printf(
			"open file %s fail in  CEventCounterServer::LogConfigInfo, errno=%d, reason=%s\n",
			szFilePath.c_str(),
			errno,
			strerror(errno));
		return -1;
	}

	fprintf(m_fOutput, "%s", buffer.c_str());
	fflush(m_fOutput);
	fclose(m_fOutput);

	//�Ƚ��ļ��汾�Ƿ�仯
	if( lastFileName.length() > 0 )
	{
		//ȫ·������
		m_oFileDiff.SetFiles( szFilePath.c_str(), lastFileName.c_str() );
		ret = m_oFileDiff.Compare();

	}
	int manufactory_id;
	string	deviceip;
	string	deviceserial;

	m_cConfigConnector.GetDeviceManufacoryIdAndIP(
		objectid,
		manufactory_id,
		deviceip,
		deviceserial);

	CFTDRtnSyslogEventField syslogEvent;
	memset(&syslogEvent, 0x00, sizeof(syslogEvent));
	syslogEvent.ObjectID = objectid.c_str();
	syslogEvent.MonDate = filedate.c_str();
	syslogEvent.MonTime = filetime.c_str();
	syslogEvent.OccurDate = filedate.c_str();
	syslogEvent.OccurTime = filetime.c_str();
	/// �¼������ʶ����Ϊ"G"����ʾϵͳ���ɵ���־�¼�
	syslogEvent.ProcessFlag = "G";
	syslogEvent.WarningLevel = "Level4";
	syslogEvent.EventDealDes = "";
	syslogEvent.IPAddress = deviceip.c_str();

	if( ret != 0)
	{
		////�����ļ��б仯������� 
		//CFG_DIS_MATCH
		string tmpFileName = szFilePath;
		tmpFileName.insert(tmpFileName.find(".txt"), "(0)");

		rename(szFilePath.c_str(),tmpFileName.c_str());

		szFileName.insert(szFileName.find(".txt"), "(0)");

		syslogEvent.EventName = EVENT_CHKVER_CHANGE;
		syslogEvent.FullEventName = "�豸���÷����仯";
		syslogEvent.EventDes = "Comment='Device running-config has changed.'";


		CFTDRtnWarningEventField warningEvent;
		memset(&warningEvent, 0x00, sizeof(warningEvent));
		warningEvent.ObjectID = objectid.c_str();
		warningEvent.MonDate = filedate.c_str();
		warningEvent.MonTime = filetime.c_str();
		warningEvent.OccurDate = filedate.c_str();
		warningEvent.OccurTime = filetime.c_str();
		warningEvent.EventName = EVENT_CHKVER_CHANGE;
		warningEvent.FullEventName = "�豸���÷����仯";
		warningEvent.ProcessFlag = "N";
		warningEvent.WarningLevel = "Level4";
		warningEvent.EventDes = "Comment='Device running-config has changed.'";
		warningEvent.EventDealDes = "";
		warningEvent.IPAddress = deviceip.c_str();

		SendWarningEvent(warningEvent);

	}
	else
	{
		//�����ļ�һ��
		syslogEvent.EventName = EVENT_CHKVER_NOCHG;
		syslogEvent.FullEventName = "�豸�����ޱ仯";
		syslogEvent.EventDes = "Comment='Device running-config have not changed.'";

	}

	g_warningEventManager.add_raw_syslog_event(syslogEvent);
	syslogEvent.EvendID = m_mSyslogEventId++;

	int nEventSeries;
	g_cEventProcess.getEventDesc(
		(const char *)syslogEvent.ObjectID,
		(const char *)syslogEvent.EventName,
		nEventSeries);
	syslogEvent.EventNum = nEventSeries;

	m_pkgSend.PreparePackage(FTD_TID_RtnSyslogEventTopic,FTDC_CHAIN_LAST,FTD_VERSION);
	FTDC_ADD_FIELD(&m_pkgSend, &syslogEvent);

	m_pEventBuffer->writeNode(&syslogEvent);

	if (g_mConfigControlEvent
		&&	syslogEvent.ProcessFlag != "C"
		&&	syslogEvent.ProcessFlag != "L")
	{
		if (m_cConfigConnector.GetSession())
		{
			m_cConfigConnector.GetSession()->SendRequestPackage(&m_pkgSend);
		}
		else
		{
			printf("config session NULL, send syslogevent fail!\n");
		}
	}
	else
	{
		m_pkgSend.MakePackage();
		m_cFrontServer.m_pCurrFrontFlow->Append(
			m_pkgSend.Address(),
			m_pkgSend.Length());
	}

	ConfigFileInfo	fileinfo;

	fileinfo.filename = szFileName;
	fileinfo.filedate = filedate;
	fileinfo.filetime = newtime;

	map<string, vector<ConfigFileInfo> >::iterator	it = g_mapConfigFileList.
		find(objectid);
	if (it == g_mapConfigFileList.end())
	{
		vector<ConfigFileInfo>	configvec;
		configvec.push_back(fileinfo);

		g_mapConfigFileList[objectid] = configvec;
	}
	else
	{
		it->second.push_back(fileinfo);
	}

	return ret;
}

bool CEventCounterServer::GetLastFileName(
	string objectid,
	string filePath,
	string filename,
	string& lastfilename)
{
	lastfilename = "";

#ifdef WIN32
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	char DirSpec[MAX_PATH + 1];// ָ��·��
	DWORD dwError;

	strncpy (DirSpec, filePath.c_str(), strlen(filePath.c_str()) + 1);
	strncat (DirSpec, "\*", 3);

	hFind = FindFirstFile(DirSpec, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf ("Invalid file handle. Error is %u ", GetLastError());
		return false;
	}
	else
	{
		if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY )
		{
			CheckObjectIDFileName(objectid.c_str(), FindFileData.cFileName, lastfilename, filename);
		}
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
			{
				CheckObjectIDFileName(objectid.c_str(), FindFileData.cFileName, lastfilename, filename);
			}
		}
		FindClose(hFind);
	}
#else
	DIR *pDir = opendir(filePath.c_str());
	if (pDir == NULL)
	{
		printf("Failed to open dir %s\n", filePath.c_str());
		return false;
	}
	struct dirent *pstDirent;
	while (pDir != NULL && (pstDirent = readdir(pDir)))
	{
		if ((strcmp(pstDirent->d_name,".")==0)
			||(strcmp(pstDirent->d_name,"..")==0))
			continue;

		CheckObjectIDFileName(objectid.c_str(),pstDirent->d_name, lastfilename, filename);
	}
	if (pDir != NULL) closedir(pDir);

#endif

	if (lastfilename.length() > 0)
	{
		lastfilename = filePath + lastfilename;
		return true;
	}
	else
		return false;
}


void CEventCounterServer::Split_Data_Column(const string &in, string &out, const string &key)
{
	int index=-1;
	int dif = 0;
	char *delim=NULL;
	char *p = NULL;

	if(in.find("\r\n")!=string::npos)
	{
		delim = "\r\n";
	}
	else
	{
		delim = "\n";
	}

	index = in.find(key.c_str());
	if( index != string::npos )
	{
		dif = in.rfind(delim, index);
		dif = index - dif - strlen(delim);
	}
	else
	{
		printf("error: there is no key [%] sub-string.\n",key.c_str());
		return;
	}

	p = strtok((char *)in.c_str(),delim);
	if( NULL != p )
	{
		out +=p;
		out +=delim;
		while( ( p = strtok(NULL,delim) ) != NULL )
		{
			if( strlen(p)>dif )
			{
				*(p+dif)='\0';
				out += trim(p);
				out +=delim;
			}
			else
			{
				out += trim(p);
				out +=delim;
			}
		}
	}
}
void CEventCounterServer::Combinate_Data_Env_NUXUS(string &result, string &newresult)
{
	string key_b = "MajorThresh";
	string key_e = "Status";

	char *delim;
	int	  diff = 0;
	size_t index_b,index_e;

	if(result.find("\r\n")!=string::npos)
	{
		delim = "\r\n";
	}
	else
	{
		delim = "\n";
	}

	index_b = result.find(key_b.c_str());
	index_e = result.find(key_e.c_str());
	
	if(index_b == string::npos || index_e == string::npos || index_e<=index_b )
	{
		return ;
	}
	else
	{
		diff = index_e - index_b -1;
		index_b = index_b - (result.rfind(delim, index_b) + strlen(delim) );
	}

	char *p = strtok((char *)result.c_str(),delim);
	if( NULL != p )
	{
		newresult +=p;
		newresult +=delim;
		while( ( p = strtok(NULL,delim) ) != NULL )
		{
			string temp = string(p);
			if( temp.length() > index_b )
			{
				temp.replace(index_b, diff, "");
				newresult +=temp;
				newresult +=delim;
			}
			else
			{
				newresult +=p;
				newresult +=delim;
			}
		}
	}

	return ;
}

void CEventCounterServer::Combinate_Data_Power_NUXUS(string &result, string &newresult)
{
	char *delim;

	if(result.find("\r\n")!=string::npos)
	{
		delim = "\r\n";
	}
	else
	{
		delim = "\n";
	}
	string substring = delim;
	substring += delim;
	result = result.substr(0,result.find(substring));

	char *p = strtok((char *)result.c_str(),delim);
	if( NULL != p )
	{
		newresult +=p;
		newresult +=delim;
		while( ( p = strtok(NULL,delim) ) != NULL )
		{
			string temp = string(p);
			if( temp.length() > 29 )
			{
				temp.replace(29, 14, "");
				newresult +=temp;
				newresult +=delim;
			}
			else
			{
				newresult +=p;
				newresult +=delim;
			}
		}
	}
	return ;
}

int CEventCounterServer::GetSrxFpcStatus_SRXFromStr(string olddata, string &newdata)
{
	newdata="";
	string exparray[]={"\\s+Current.*\\d+[\\r\\n]+","\\s+Max.*\\d+[\\r\\n]+","\\s*Total.*\\d+[\\r\\n]+","IPv.*\\d+[\\r\\n]+"};

	for ( int i=0; i< sizeof(exparray)/sizeof(string); i++)
	{
		try
		{
			regex expression(exparray[i]);
			olddata=regex_replace(olddata,expression,"\\r\\n",match_any);
		}catch(...)
		{
			printf("\nGetSrxFpcStatus_SRXFromStr regex express[%s] error!\n",exparray[i].c_str());
		}
	}
	newdata=olddata;
	return 0;
}

int CEventCounterServer::GetNexusTemp_3548FromStr(const string &olddata, string &newdata)
{
    char linebuf[1024]={0};
    SNPRINTF(linebuf,1024,"%s\r\n%s\r\n%s\r\n%s\r\n","Monitor Temperature","------------------","Sensor  Status","------------------");
    string oldstr = olddata;
    newdata = linebuf;

    cmatch  what;
    try
    {
        regex expression("^.*Monitor Temperature.*\\(Celsius\\).*[\\s]-+[\\s](.*)[\\s]-+.*$");

        if (regex_match(olddata.c_str(), what, expression))
        {
            oldstr = what[1].str();
        }
        else
        {
            //do nothing
            return -1;
        }
    }catch(...)
    {
        printf("GetNexusTemp_3548FromStr express 1 error!\n");
        return -1;
    }
    string sensor;
    string status;
    try
    {
        regex expression1("\\s*(\\S+)\\s+\\d+\\s+\\d+\\s+\\d+\\s+(\\S+)[ ]*[\\s]+(.*)");
        do
        {
            if ( regex_match(oldstr.c_str(), what, expression1) )
            {
                sensor = what[1].str();
                status = what[2].str();
                oldstr = what[3].str();
                SNPRINTF(linebuf,1024,"%s    %s\r\n",sensor.c_str(),status.c_str());
                newdata.append(linebuf);
            }
            else
            {
                break;
            }
        } while (true);
    }catch(...)
    {
        printf("GetNexusTemp_3548FromStr express2 error,rst[%s]!\n",oldstr.c_str());
        return -1;
    }
    newdata.append("-----------------");
    return 0;
}


int CEventCounterServer::GetDropCounterFromStr(const string &olddata, string &newdata)
{
	char *delim=NULL;
	char buff[128] = "\0";
	bool flag = false;
	if(olddata.find("\r\n")!=string::npos)
	{
		delim = "\r\n";
	}
	else
	{
		delim = "\n";
	}
	char *p = strtok( (char *)olddata.c_str(),delim);
	if( NULL != p )
	{
		newdata +=p;
		newdata +=delim;
		while( ( p = strtok(NULL,delim) ) != NULL )
		{
			if( strstr(p, "Port group")!=NULL )
			{
				flag = false;
			}
			else if( strstr(p, "R-L Class")!=NULL )
			{
				flag = true;
			}
			if( flag )
			{
				memset(buff, 0, 128);
				strncpy(buff, p, 20);
				if(strlen(p)>=50)
				{
					strncpy(buff+20, p+50, 15);
				}
				newdata +=buff;
				newdata +=delim;
			}
			else
			{
				newdata +=p;
				newdata +=delim;
			}

		}
	}
	//printf("new data is: \n%s\n",newdata.c_str());
	printf("parse the RateLimiter actions end.\n");

	return 0;
}

int CEventCounterServer::GetSRXUptimeFromStr(const string &olddata, string &newdata)
{
	char *delim=NULL;
	if(olddata.find("\r\n")!=string::npos)
	{
		delim = "\r\n";
	}
	else
	{
		delim = "\n";
	}

	bool flag = false;
	char *p = strtok( (char *)olddata.c_str(),delim);
	if( NULL != p )
	{
		if( strstr(p,"node")!= NULL )
		{
			newdata +=p;
			newdata +=delim;
		}
		while( ( p = strtok(NULL,delim) ) != NULL )
		{
			if( strstr(p, "---------")!=NULL 
				||strstr(p, "node")!= NULL )
			{
				newdata +=p;
				newdata +=delim;
			}
			else if ( strstr(p, "System booted:")!= NULL 
				|| strstr(p, "Protocols started:")!= NULL)
			{
				char *cp = strchr(p,'(');
				if( NULL != cp )
				{
					*cp = '\0';
				}
				newdata +=p;
				newdata +=delim;
			}
		}
	}
	//printf("new data is: \n%s\n",newdata.c_str());
	printf("parse the SRXUptime actions end.\n");

	return 0;
}

/************************************************************************
* ����ʵ�����������¼�澯����
************************************************************************/

// �������������ͳ����Ϣ
map<MdLoginRecordID, MdLoginRecord*> MdLoginRecord::m_AllRecords;

/* �������еļ������ */
vector<MdLoginWarningCalculate*> MdLoginWarningCalculate::m_AllCalculate;

/* ������ڷ������ݵİ� */
CFTDCPackage MdLoginWarningCalculate::m_pkgSend;
/* ������ڷ���ʱ��������� */
/* ���淢��Syslog�¼�ʱʹ�õ�ObjectID����ȡ�������ļ� */
/* ���ޣ���Ĭ��ΪTRADE.PuDian.app.tkernel.1 */
CFTDRtnSyslogEventField MdLoginWarningCalculate::m_SyslogEventField;

MdLoginRecord* MdLoginRecord::fetchRecord(const MdLoginRecordID& _id)
{
	MdLoginRecord* pRecord = NULL;
	map<MdLoginRecordID, MdLoginRecord*>::iterator 
		it = m_AllRecords.find(_id);
	if (it == m_AllRecords.end())
	{
		pRecord = new MdLoginRecord(_id);
		m_AllRecords.insert(make_pair(_id, pRecord));
	}
	else
		pRecord = it->second;
	return pRecord;
}

void MdLoginRecord::removeRecord(const MdLoginRecordID& _id)
{
	map<MdLoginRecordID, MdLoginRecord*>::iterator 
		it = m_AllRecords.find(_id);
	if (it != m_AllRecords.end())
	{
		delete it->second;
		m_AllRecords.erase(it);
	}
}

void MdLoginRecord::resetAllRecords()
{
	for (map<MdLoginRecordID, MdLoginRecord*>::iterator
		it = m_AllRecords.begin();
		it != m_AllRecords.end(); ++it)
	{
		it->second->resetRecord();
	}
}

int MdLoginRecord::loginCount(
	time_t _endMoment /* 0 */,
	int _timeLength /* 0 */,
	MdLoginState _state /*= AllState*/) const
{
	if (m_LoginRecords.empty()) return 0;

	int nCount = 0;
	// ���endMoment��timeLengthΪ0����ʾ��ȡ���еĵ�¼����
	// ����ʼʱ������Ϊ0����ֹʱ������Ϊlong long���ֵ
	time_t tStartMoment = (_endMoment <= 0 || _timeLength <= 0) ? 0 : _endMoment - _timeLength;
	_endMoment = (tStartMoment == 0) ? LLONG_MAX : _endMoment;

	for (vector<LoginInfo>::const_reverse_iterator itRecord = m_LoginRecords.rbegin();
		itRecord != m_LoginRecords.rend(); ++itRecord)
	{
		if (itRecord->LoginTime >= tStartMoment 	&& itRecord->LoginTime <= _endMoment
			&& (_state == AllState || itRecord->LoginState == _state))
			++nCount;
	}
	return nCount;
}

static int detailCompare(const pair<string, int>& _v1, const pair<string, int>& _v2)
{
	return _v1.second > _v2.second;
}

std::string MdLoginRecord::loginDetail(
	time_t _endMoment /*= 0*/, 
	int _timeLength /*= 0*/, 
	int _outputLen /*= 2*/,
	MdLoginState _state /*= AllState*/) const
{
	if (_outputLen <= 0) return "";

	// �����¼ϸ�ڣ�map<mdkernel����¼����>
	map<string, int> _LoginDetail;
	time_t tStartMoment = (_endMoment <= 0 || _timeLength <= 0) ? 0 : _endMoment - _timeLength;
	_endMoment = (tStartMoment == 0) ? LLONG_MAX : _endMoment;

	for (vector<LoginInfo>::const_iterator it = m_LoginRecords.begin();
		it != m_LoginRecords.end(); ++it)
	{
		if (it->LoginTime >= tStartMoment 	&& it->LoginTime <= _endMoment
			&& (_state == AllState || it->LoginState == _state))
		{
			map<string, int>::iterator itDetail = _LoginDetail.find(it->MdkernelID);
			if (itDetail == _LoginDetail.end())
				_LoginDetail.insert(make_pair(it->MdkernelID, 1));
			else
				itDetail->second++;
		}
	}

	// ���յ�¼��������
	vector< pair<string, int> > _orderedDetail(_LoginDetail.begin(), _LoginDetail.end());		// �����¼
	sort(_orderedDetail.begin(), _orderedDetail.end(), detailCompare);

	string strLoginDetail;
	char buffer[128];
	for (int i = 0; i < _outputLen && i < _orderedDetail.size(); ++i)
	{
		memset(buffer, 0, 128);
		sprintf(buffer, "%s[%d] ", _orderedDetail[i].first.c_str(), _orderedDetail[i].second);
		strLoginDetail.append(buffer);
	}
	strLoginDetail.append("...");
	return strLoginDetail;
}

// Interval=%d, IntSucc=%d, IntFail=%d, IntAll=%d, TotalSucc=%d, TotalFail=%d, TotalAll=%d
std::string MdLoginRecord::loginCountDetail(
	time_t _endMoment /* 0 */,
	int _timeLength /* 0 */)
{
	int nIntSucc = 0, nIntFail = 0, nTotalSucc = 0, nTotalFail = 0;
	// ���endMoment��timeLengthΪ0����ʾ��ȡ���еĵ�¼����
	// ����ʼʱ������Ϊ0����ֹʱ������Ϊlong long���ֵ
	time_t tStartMoment = (_endMoment <= 0 || _timeLength <= 0) ? 0 : _endMoment - _timeLength;
	_endMoment = (tStartMoment == 0) ? LLONG_MAX : _endMoment;

	for (vector<LoginInfo>::const_iterator it = m_LoginRecords.begin();
		it != m_LoginRecords.end(); ++it)
	{
		if (it->LoginTime >= tStartMoment && it->LoginTime <= _endMoment)
			(it->LoginState == Success) ? ++nIntSucc : ++nIntFail;
		(it->LoginState == Success) ? ++nTotalSucc : ++nTotalFail;
	}

	char buff[128];
	memset(buff, 0, 128);
	sprintf(buff, "Interval=%d, Succ_Fail_All=[%d/%d/%d], Total=[%d/%d/%d]",
		_timeLength, nIntSucc, nIntFail, nIntSucc + nIntFail, nTotalSucc, nTotalFail, nTotalSucc + nTotalFail);
	return buff;
}

bool MdLoginWarningCalculate::loadCalculateObjectFromXml(const char* _fileName)
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
	for (vector<MdLoginWarningCalculate*>::iterator
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
			CXMLNode* pLoginWarningTag = pSystemCfgRoot->findNode(XMLTag, "MdLoginWarningEvents");
			if (pLoginWarningTag == NULL) throw "Can not find MdLoginWarningEvents Tag";

			char* szObjectID = pLoginWarningTag->findProperty("objectid");
			memset(&m_SyslogEventField, 0, sizeof(m_SyslogEventField));
			m_SyslogEventField.ObjectID = (szObjectID == NULL) ? "TRADE.PuDian.app.tkernel.1" : szObjectID;

			CXMLNodeList *pNodeList = pLoginWarningTag->getNodeList();
			if (pNodeList == NULL || pNodeList->empty()) throw "Node list of LoginWarningEvents Tag is Null";

			for (CXMLNodeList::iterator itNode = pNodeList->begin();
				itNode != pNodeList->end(); 	++itNode)
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

				char* szState = pLoginWarningNode->findProperty("state");
				MdLoginRecord::MdLoginState eState;
				if (strcmp(szState, "Success") == 0)
					eState = MdLoginRecord::Success;
				else if (strcmp(szState, "Failure") == 0)
					eState = MdLoginRecord::Failure;
				else if (strcmp(szState, "All") == 0)
					eState = MdLoginRecord::AllState;
				else
					throw "Unknow state of LoginWarningEvent.";

				if (nInterval <= 0 || nThreshold <= 0 || nWarningGap <= 0)
					printf("Args of LoginWarningEvent[%s] is error!\n", szEventName);
				else
				{
					// add this warning calculate object
					MdLoginWarningCalculate* pLoginWarningObject =
						new MdLoginWarningCalculate(szEventName, nInterval, 
								nThreshold,	nWarningGap, eState);
					m_AllCalculate.push_back(pLoginWarningObject);
				}

			}
		} // end load MemberLoginWarningEvents info
	}
	catch (CRuntimeError * e)
	{
		printf("Error when load %s info:\nLINE[%d]:%s\n",
			_fileName, e->GetLineNo(), e->GetMsg());
		return false;
	}
	catch (const char* e)
	{
		printf("%s\n", e);
		return false;
	}

	return true;
}

void MdLoginWarningCalculate::HandleMdLogin(
	const CDateType& _loginDate, /* �����¼������ */ 
	const CTimeType& _loginTime, /* �����¼��ʱ�� */ 
	MdLoginRecord::MdLoginState _loginState, /* �����¼��״̬ */ 
	const char* _mdkernelID, /* ���鱾�ε�¼��mdkernel */
	MdLoginRecordID _recordID)
{
	// ��������ڼ������ֱ���˳�
	if (m_AllCalculate.empty()) return;

	// ��ǰʱ�䣬�������ʹ�ã�����ͳһ��ʱ��ֵ
	time_t tNow = time(NULL);
		
	// ��ȡ����Ӧ�������¼
	MdLoginRecord* pRecord = MdLoginRecord::fetchRecord(_recordID);

	// ����¼ʱ��ת��Ϊtime_t��ʽ
	time_t tLoginTime = convertToTime(_loginDate, _loginTime);
	if (tLoginTime == -1) tLoginTime = tNow;		// ���ʱ��ת����������ʹ�ñ���ʱ�����

	// ��¼ʱ��ֵ
	pRecord->record(tLoginTime, _loginState, _mdkernelID);

	// �������еĸ澯������󣬼��㵱ǰ��¼��Ϣ�Ƿ���ϸ澯��ֵ
	for (vector<MdLoginWarningCalculate*>::iterator itObject = m_AllCalculate.begin();
		itObject != m_AllCalculate.end(); ++itObject)
	{
		MdLoginWarningCalculate* pWarningCalculate = *itObject;

		// �жϸø澯�Ƿ�Ըõ�¼��Ч
		if (pWarningCalculate->m_TargetState == MdLoginRecord::AllState
			|| (pWarningCalculate->m_TargetState == _loginState))
		{
			pWarningCalculate->HandleRecord(pRecord, tLoginTime, tNow);
		}
	}
}


void MdLoginWarningCalculate::HandleRecord(MdLoginRecord* _Record, time_t _BasisTime, time_t _LocalTime)
{
	// ��ȡϯλ������м�״̬
	RecordState& PState = getRecordState(_Record->getRecordID());
	// ֻ�д���Ӧ���澯��ʱ���֮�ڣ��Ž��м���
	if (_LocalTime - PState.LastWarningTime >= m_WarningGap)
	{
		// ��ȡ��¼�У��Ի�׼ʱ��Ϊ��㣬��ǰm_Interval����ָ��״̬�ĵ�¼����
		int nLoginCount = _Record->loginCount(_BasisTime, m_Interval, m_TargetState);
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

			sprintf((char*)m_SyslogEventField.EventDes.getValue(),
				"ID=%s, %s, Detail=\"%s\"",
				_Record->getRecordID().c_str(),
				_Record->loginCountDetail(_BasisTime, m_Interval).c_str(),		// Interval=%d, IntSucc=%d, IntFail=%d, IntAll=%d, TotalSucc=%d, TotalFail=%d, TotalAll=%d
				_Record->loginDetail(_BasisTime, m_Interval).c_str());
#if 0
			printf("[LoginWarningEvent] %s\n", m_SyslogEventField.EventDes.getValue());
#endif
			// ת��RtnSyslog��������
			m_pkgSend.PreparePackage(FTD_TID_RtnSyslogEventTopic,
				FTDC_CHAIN_LAST, FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &m_SyslogEventField);
			g_counterServer->HandlePackage(&m_pkgSend, NULL);

			// ����״̬ʱ��
			PState.LastWarningTime = _LocalTime;
		}
	}
}

MdLoginWarningCalculate::RecordState& 
MdLoginWarningCalculate::getRecordState(const MdLoginRecordID& _RecordID)
{
	map<MdLoginRecordID, RecordState>::iterator
		it = m_AllRecordState.find(_RecordID);
	if (it == m_AllRecordState.end())
	{
		RecordState _pstat;
		m_AllRecordState.insert(make_pair(_RecordID, _pstat));
		it = m_AllRecordState.find(_RecordID);
	}
	return it->second;
}
