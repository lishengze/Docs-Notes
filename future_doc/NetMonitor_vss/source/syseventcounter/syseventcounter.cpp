/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	syseventcounter.cpp
///@brief	�¼����������������main������ʵ��
///@history
///20080508	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
///20080908 ����		���Syslog.log���
///20090430 �̺״�		��ӳ���������ʶ��У��
///20120202 κ��		ʵʱ��ʵʱ��������ϵͳ����
/////////////////////////////////////////////////////////////////////////
#include "public.h"
#include "Config.h"
#include "CConfig.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "EventCounterServer.h"
#include "EventFrontServer.h"
#include "CStatusAnalysis.h"
#include "CExprAnalysis.h"
#include "xmlcfg.h"
#include "version.h"
#include "CFilelogService.h"
#include "ProbeServer.h"
#include "CDeployConfig.h"
#include "CRegexConfig.h"
#include "CMsgGenerator.h"
#include "PrjCommon.h"
#include "inputStream.h"
#include "CExprNode.h"
#include "inputToken.h"
#include "CExprParser.h"

int g_iTimeZoneOffset;				// ��ǰϵͳʱ�����׼ʱ��ƫ����������8��Ϊ28800��
int g_mMonitorTime = 3;				// Active�������
char pCounterLocation[200];			// = "tcp://127.0.0.1:9300";
char pFrontLocation[200];			// = "tcp://127.0.0.1:9400";
char pConfigLocation[200];			//���÷������ĵ�ַ
char pProbeLocation[200];			// ��Ϊ̽���ַ
char g_mEventCfgPath[200];			//�����¼������ļ�
char g_mCfgPath[200];				//���������ļ�·��
char g_mFlowPath[200];				//�������ļ��洢·��
char g_mSavePacketNumFile[200];		//���������ļ��洢·����
int g_warningeventdelaytime;		//�澯�ӳ�ʱ��

/// Added by Henchi, 20121113
CMsgGenerator g_MsgGenerator;

//κ��add,20120130
int g_mConfigControlEvent = 0;		//�¼��Ƿ���configͳһ����Ĭ��Ϊ��
char g_mHostFilterStr[100];			//������Ҫ���˵Ķ���ID�ִ��������config������cpuusage��memusage����'.config_'
int g_mKLineStatPeriod = 60;		//K��ͳ������
int g_mEventProcessFuzzyMatch = 0;	//�¼������Ƿ�ͨ��objectid��eventnameģ��ƥ�䣬��Ļ�ͨ��eventid��ȷƥ��
const char	*INI_FILE_NAME = "syseventcounter.ini";
const char	*XML_FILE_NAME = "syseventcounter.xml";
const char	*APP_NAME = "syseventcounter";
const char	*REGEX_FILE_NAME = "syseventcounter.regex";

map<int, string> g_mapSnmpConector; // ����snmpmanager����������
#ifdef PACKAGE_OUTPUT
CLogger *g_pPackOutput = NULL;		// ���ݰ�������ļ�
CLogger *g_pPackOutput_config = NULL;
#endif
extern bool UseNetCompressLog;		// ����ѹ����Ϣ�������
CExprAnalysis *g_mExprAnalysis = NULL;
CDataCenter *g_pDataCenter = NULL;
CFTDCPackage g_mPkgSend;
CListWarningEventField	*g_pListEvent = NULL;					// ��������δд�뵽���ĸ澯�¼�
extern CExprParser<CValue>	g_mEventParser;
extern CContext *g_pContext;

CEventCounterServer *g_counterServer = NULL;

// add by cao.ning
// ϵͳ�ڲ���������
CSysInternalTopology* g_SysInternalTopology = NULL;

void globalEnvInit(char *startSeq)
{
	time_t	timep;
	time(&timep);
	g_iTimeZoneOffset = getTimeZoneOffset();

	printf("syseventcounter Start Running !!! %s", ctime(&timep));
	printf("TimeZone offset [%d]\n", g_iTimeZoneOffset);
	fflush(stdout);

	char buff[20];
	GetConfigString(INI_FILE_NAME, "IntervalNum", buff, sizeof(buff));
	if (atoi(buff) >= 3)
	{
		g_mMonitorTime = atoi(buff);
	}

	memset(g_mHostFilterStr, 0, sizeof(g_mHostFilterStr));
	GetConfigString(
		INI_FILE_NAME,
		"HostFilterString",
		g_mHostFilterStr,
		sizeof(g_mHostFilterStr));
	GetConfigString(
		INI_FILE_NAME,
		"ConfigPath",
		g_mCfgPath,
		sizeof(g_mCfgPath));
	GetConfigString(INI_FILE_NAME, "FlowPath", g_mFlowPath, sizeof(g_mCfgPath));
	sprintf(g_mSavePacketNumFile, "%s%s", g_mFlowPath, "readpos.txt");
	sprintf(g_mEventCfgPath, "%s%s", g_mCfgPath, "SystemConfig.xml");

	memset(buff, 0, sizeof(buff));
	GetConfigString(INI_FILE_NAME, "ConfigControlEvent", buff, sizeof(buff));
	g_mConfigControlEvent = atoi(buff);

	memset(buff, 0, sizeof(buff));
	GetConfigString(INI_FILE_NAME, "KLineStatPeriod", buff, sizeof(buff));
	g_mKLineStatPeriod = atoi(buff);

	if (g_mKLineStatPeriod == 0)
	{
		//Ĭ�ϵ�ͳ������Ϊ1����
		g_mKLineStatPeriod = 60;
	}

	memset(buff, 0, sizeof(buff));
	GetConfigString(INI_FILE_NAME, "WarningEventDelayTime", buff, sizeof(buff));
	g_warningeventdelaytime = atoi(buff);

	if (g_warningeventdelaytime == 0)
	{
		//Ĭ�ϵ��ӳ�ʱ��Ϊ5����
		g_warningeventdelaytime = 300;
	}

	memset(buff, 0, sizeof(buff));
	GetConfigString(
		INI_FILE_NAME,
		"EventProcessFuzzyMatch",
		buff,
		sizeof(buff));
	g_mEventProcessFuzzyMatch = atoi(buff);

#ifdef PACKAGE_OUTPUT
	g_pPackOutput = new CFileLogger();
	g_pPackOutput_config = new CFileLogger();

	char FilePath[100];
	sprintf(FilePath, "%s%s", g_mFlowPath, "eventpackage_manager.log");
	if (!((CFileLogger *)g_pPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

	memset(FilePath, 0, 100);
	sprintf(FilePath, "%s%s", g_mFlowPath, "eventpackage_config.log");
	if (!((CFileLogger *)g_pPackOutput_config)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

#endif
	memset(pCounterLocation, 0, sizeof(pCounterLocation));
	memset(pFrontLocation, 0, sizeof(pFrontLocation));
	memset(pConfigLocation, 0, sizeof(pConfigLocation));
	memset(pProbeLocation, 0, sizeof(pProbeLocation));

	CDeployConfig *pXMLCfg = new CDeployConfig();
	if (pXMLCfg != NULL)
	{
		pXMLCfg->Parse(g_mCfgPath);

		CDeployConfig::SysEventCounterCfgInfo cfg = pXMLCfg->
			GetSysEventCounterCfgInfo(startSeq);

		strcpy(pCounterLocation, cfg.ServerAddr("sysagent").c_str());
		strcpy(pFrontLocation, cfg.ServerAddr("sysfront").c_str());
		strcpy(pConfigLocation, cfg.ServerAddr("synconfig").c_str());
		strcpy(pProbeLocation, cfg.ServerAddr("probeserver").c_str());

		vector<CDeployConfig::ServerAddrInfo> managers = cfg.ServerAddrArray(
				"snmpmanager");

		for (int i = 0; i < managers.size(); ++i)
		{
			g_mapSnmpConector[atoi(
					managers[i].m_id.c_str())] = managers[i].m_addr;
		}

		delete pXMLCfg;
		pXMLCfg = NULL;
	}

	g_mPkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);	//����ȫ�ְ��Ŀռ�
	g_pDataCenter = new CDataCenter();
	g_pDataCenter->init(g_mCfgPath);
	g_pDataCenter->print();
	g_pListEvent = new CListWarningEventField();				// ��������δд�뵽���ĸ澯�¼�
	g_mExprAnalysis = new CExprAnalysis(g_mEventCfgPath);
}

int test_expr(void)
{
	CContext *g_ppContext = new CContext((char *)INI_FILE_NAME);

	g_ppContext->setNow(time(NULL));

	//����ָ�������
	CInputStreamPtr m_pStream = new CStringInputStream(
			"5>1 && 3<6 && nowbetween(\"08:00:00\", \"17:00:00\")");

	CExprNode<CValue> *m_pExpr = g_mEventParser.parse(m_pStream);

	CValue	&result = m_pExpr->eval(*g_ppContext);
	if (result.getDIntValue() <= 0)
	{
		printf("expr not pass!\n");
	}

	//m_pStream->decRef();
	delete g_ppContext;

	return 0;
}

int test_main(void);

int main(int argc, char *argv[])
{
	//return test_main();
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);

	//	signal(SIGINT, SIG_IGN);
#endif
	showVersion(argc, argv);
#ifndef WIN32
	getStartId(argc, argv); // Mod by henchi, 20090430
#endif
	globalEnvInit(argv[1]);

	//Ĭ��Ϊ��
	g_MsgGenerator.setNetworkEventFlag(true);
	g_MsgGenerator.setBusinessEventFlag(true);
	g_MsgGenerator.setAttrFlag(true);

	if (argc >= 3)
	{
		if (strcmp(argv[2], "0") == 0 || strcmp(argv[2], "off") == 0)
		{
			g_MsgGenerator.setBusinessEventFlag(false);
		}
	}

	if (argc >= 4)
	{
		if (strcmp(argv[3], "0") == 0 || strcmp(argv[3], "off") == 0)
		{
			g_MsgGenerator.setNetworkEventFlag(false);
		}
	}

	if (argc >= 5)
	{
		if (strcmp(argv[4], "0") == 0 || strcmp(argv[4], "off") == 0)
		{
			g_MsgGenerator.setAttrFlag(false);
		}
	}

	// �رձ���ѹ�������Ϣ
	UseNetCompressLog = false;

	///�������ò���ʼ���Syslog:
	SysReactor	reactor;
	CConfig *pConfig = new CConfig(INI_FILE_NAME);
	char *syslogFileName = pConfig->getConfig("SyslogPath");
	CMonitorIndex::init(
			CFilelogService::CreateInstance(argc, argv, syslogFileName),
			pConfig);

	char *enableInternalTopology = pConfig->getConfig("SysInternalTopology");
	if (enableInternalTopology && atoi(enableInternalTopology) == 1)
	{
		// add by cao.ning
		int iStartID = getStartId(argc, argv);
		g_SysInternalTopology = new CSysInternalTopology("eventcounter", iStartID);
	}

	delete pConfig;

	//����������ȡָ����Ϣ�������ļ�
	if (CRegexConfigManager::Instance()->LoadConfig(REGEX_FILE_NAME) != 0)
	{
		printf("LoadConfig faile for %s\n", REGEX_FILE_NAME);
		return 0;
	}

	CRegexConfigManager::Instance()->DumpConfig();

	// added by cao.ning
	// ��ȡ����ϯλ��½ͳ������
	MdLoginWarningCalculate::loadCalculateObjectFromXml(XML_FILE_NAME);

	/// Added by Henchi, 20121113
		/// ���Ӷ��Ŵ����̶߳���
	g_MsgGenerator.Init((char *)XML_FILE_NAME);
	g_MsgGenerator.Create();

	g_counterServer = new CEventCounterServer(
			&reactor,
			g_mSavePacketNumFile,
			g_mEventCfgPath,
			(char *)XML_FILE_NAME,
			g_mFlowPath);

	//counterServer.m_cConfigConnector.test_task();
	//return CFrontConnector::OnReqQryGetFileTopic();
	g_counterServer->RegisterAllConector(g_mapSnmpConector, pConfigLocation);
	g_counterServer->RegisterAllListener(
			pCounterLocation,
			pFrontLocation,
			pProbeLocation);
	reactor.Create();
	g_counterServer->StartAll();
	reactor.Join();

	delete g_counterServer;

	return 0;
}

#if 0
void test(void)
{
	CMemoryDB *p_mExprDB = NULL;

	if (p_mExprDB == NULL)
	{
		CConfig *pConfig = new CConfig(g_mEventCfgPath);

		///MDB��INI���봦:
		currentConfig = pConfig;
		p_mExprDB = new CMemoryDB();
		p_mExprDB->init(pConfig);
	}

	CWriteableEventEntity theEventEntity;
	for (int i = 0; i < 5; i++)
	{
		theEventEntity.EventName = i;
		theEventEntity.MonitorTime = 10 + i;
		theEventEntity.MonitorObject = 100 + i;
		p_mExprDB->m_EventEntityFactory->add(&theEventEntity);
		theEventEntity.MonitorTime = 10 + i + 1;
		p_mExprDB->m_EventEntityFactory->add(&theEventEntity);
		theEventEntity.MonitorTime = 10 + i + 2;
		p_mExprDB->m_EventEntityFactory->add(&theEventEntity);
	}

	CEventEntity *pEventEntity;
	pEventEntity = p_mExprDB->m_EventEntityFactory->startFindByKey(1, 14);
	while (pEventEntity)
	{
		//monitorTime = pMonitorEntity->MonitorTime;
		printf(
			"%d %d %d \n",
			pEventEntity->EventName,
			pEventEntity->MonitorTime,
			pEventEntity->MonitorObject);
		pEventEntity = p_mExprDB->m_EventEntityFactory->findNextByKey();
	}

	p_mExprDB->m_EventEntityFactory->endFindByKey();

#if 0
	multimap<int, int>	mmap;
	mmap.insert(make_pair(0, 1));
	mmap.insert(make_pair(0, 2));
	mmap.insert(make_pair(1, 3));
	mmap.insert(make_pair(1, 4));
	mmap.insert(make_pair(2, 1));
	mmap.insert(make_pair(2, 2));
	mmap.insert(make_pair(3, 3));
	mmap.insert(make_pair(3, 4));

	multimap<int, int>::iterator mit = mmap.lower_bound(5);
	while (mit != mmap.upper_bound(5))
	{
		printf("key:%d value:%d\n", mit->first, mit->second);
		++mit;
	}

#endif
}

#endif
