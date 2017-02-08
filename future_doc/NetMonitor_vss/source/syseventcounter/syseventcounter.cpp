/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	syseventcounter.cpp
///@brief	事件计算分析服务器的main主函数实现
///@history
///20080508	周建军		创建该文件
///20080623	周建军		修订注释
///20080908 郭鹏		添加Syslog.log输出
///20090430 晏鹤春		添加程序启动标识的校验
///20120202 魏诚		实时非实时和网络监控系统整合
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

int g_iTimeZoneOffset;				// 当前系统时区与标准时区偏移秒数（东8区为28800）
int g_mMonitorTime = 3;				// Active间隔次数
char pCounterLocation[200];			// = "tcp://127.0.0.1:9300";
char pFrontLocation[200];			// = "tcp://127.0.0.1:9400";
char pConfigLocation[200];			//配置服务器的地址
char pProbeLocation[200];			// 作为探针地址
char g_mEventCfgPath[200];			//保存事件定义文件
char g_mCfgPath[200];				//保存配置文件路径
char g_mFlowPath[200];				//保存流文件存储路径
char g_mSavePacketNumFile[200];		//保存索引文件存储路径名
int g_warningeventdelaytime;		//告警延迟时间

/// Added by Henchi, 20121113
CMsgGenerator g_MsgGenerator;

//魏诚add,20120130
int g_mConfigControlEvent = 0;		//事件是否由config统一管理，默认为否
char g_mHostFilterStr[100];			//保存需要过滤的对象ID字串，如过滤config主机的cpuusage、memusage，如'.config_'
int g_mKLineStatPeriod = 60;		//K线统计周期
int g_mEventProcessFuzzyMatch = 0;	//事件处理是否通过objectid和eventname模糊匹配，否的话通过eventid精确匹配
const char	*INI_FILE_NAME = "syseventcounter.ini";
const char	*XML_FILE_NAME = "syseventcounter.xml";
const char	*APP_NAME = "syseventcounter";
const char	*REGEX_FILE_NAME = "syseventcounter.regex";

map<int, string> g_mapSnmpConector; // 保存snmpmanager连接配置项
#ifdef PACKAGE_OUTPUT
CLogger *g_pPackOutput = NULL;		// 数据包输出到文件
CLogger *g_pPackOutput_config = NULL;
#endif
extern bool UseNetCompressLog;		// 报文压缩信息输出开关
CExprAnalysis *g_mExprAnalysis = NULL;
CDataCenter *g_pDataCenter = NULL;
CFTDCPackage g_mPkgSend;
CListWarningEventField	*g_pListEvent = NULL;					// 保存所有未写入到流的告警事件
extern CExprParser<CValue>	g_mEventParser;
extern CContext *g_pContext;

CEventCounterServer *g_counterServer = NULL;

// add by cao.ning
// 系统内部连接拓扑
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
		//默认的统计周期为1分钟
		g_mKLineStatPeriod = 60;
	}

	memset(buff, 0, sizeof(buff));
	GetConfigString(INI_FILE_NAME, "WarningEventDelayTime", buff, sizeof(buff));
	g_warningeventdelaytime = atoi(buff);

	if (g_warningeventdelaytime == 0)
	{
		//默认的延迟时间为5分钟
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

	g_mPkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);	//构造全局包的空间
	g_pDataCenter = new CDataCenter();
	g_pDataCenter->init(g_mCfgPath);
	g_pDataCenter->print();
	g_pListEvent = new CListWarningEventField();				// 保存所有未写入到流的告警事件
	g_mExprAnalysis = new CExprAnalysis(g_mEventCfgPath);
}

int test_expr(void)
{
	CContext *g_ppContext = new CContext((char *)INI_FILE_NAME);

	g_ppContext->setNow(time(NULL));

	//分析指标合理性
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

	//默认为开
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

	// 关闭报文压缩输出信息
	UseNetCompressLog = false;

	///载入配置并开始输出Syslog:
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

	//加载正则提取指标信息的配置文件
	if (CRegexConfigManager::Instance()->LoadConfig(REGEX_FILE_NAME) != 0)
	{
		printf("LoadConfig faile for %s\n", REGEX_FILE_NAME);
		return 0;
	}

	CRegexConfigManager::Instance()->DumpConfig();

	// added by cao.ning
	// 读取行情席位登陆统计配置
	MdLoginWarningCalculate::loadCalculateObjectFromXml(XML_FILE_NAME);

	/// Added by Henchi, 20121113
		/// 增加短信处理线程对象
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

		///MDB对INI导入处:
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
