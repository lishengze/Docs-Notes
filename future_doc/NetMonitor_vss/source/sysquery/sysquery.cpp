#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CQueryServer.h"
#include "CounterConnector.h"
#include "CStatusSubscriber.h"
#include "slogparser.h"
#include "Config.h"
#include "CConfig.h"
#include "CFilelogService.h"
#include "xmlcfg.h" // Added by Henchi 20080718
#include "CDumpSession.h"
#include "version.h"
#include "CDeployConfig.h"
#include "SessionProxy.h"

const char	*INI_FILE_NAME = "sysquery.ini";	// ini配置文件名
const char	*XML_FILE_NAME = "sysquery.xml";	// xml配置文件名	
const char	*APP_NAME = "sysquery";				// 应用名称

///=== 20110907 by zhou.jj
int g_newSlogFlag[40];

/// 20110907 by zhou.jj
char pCounterLocation[200] = "";				// 事件计算服务器连接地址"tcp://127.0.0.1:9400"
char pQueryLocation[200] = "";					// 查询服务器侦听端口"tcp://127.0.0.1:9600"
char g_mFlowPath[200] = "";						// 流文件目录"./flow/"
char g_mCfgPath[200] = "";						// 系统xml配置文件目录"../../config"
char g_mStartTime[9];							// 统计数据写入数据库开始时间
char g_mEndTime[9];								// 统计数据写入
char g_mWarningPath[100] = "";					// 告警输出文件路径
char g_mSystemNum[20] = "";						// 告警输出的系统号码
int g_nWarningInterval = 600;					// 告警输出的流控时间（秒）
int g_nCommonInterval = 3600;					// 通用告警及指标的输出
int g_nTimeZoneSec = 0;							//换算成秒的时差
int g_nOrderNo = 0;								//事件序号
int g_nStartID = 0;								//应用启动编号

//修改 @ 20120920
//流文件分成9个，每3小时切换
//9个流文件放在1个订阅对象里面创建
CStatusSubscriber *g_pStatusSubcriber;			// 状态标识器指针

//CCachedFileFlow		*g_pFlow = NULL; 				// 流文件指针
CLogger *g_pLoggerOutput = NULL;				// 数据包输出缓冲区指针
CSlogQuery	*g_pSlogQuery = NULL;				// Slog查询服务实例指针
CFileOperation	*g_fileOperation = NULL;		// 写文件类对象指针
COrderRttAnalysis *g_OrderRttAnalysis = NULL;	// 响应速度分析类对象指针
CSlogReactor *g_pReactor = NULL;				// 全局reactor对象指针，只能一次构造
CJudgeRun *g_pJudgeRun = NULL;					// 全局时间段判断处理对象，只能一次构造
#ifdef PACKAGE_OUTPUT
CLogger *g_pPackOutput = NULL;					// 数据包输出到文件
#endif
extern bool UseNetCompressLog;					// 报文压缩信息输出开关
bool g_bAnalysisRTT = true;
char g_szTimeBuffer[10];
CPackageFilter	g_PackageFilter;
map<string, int> g_mapSlogFileName;
map<CPeakKey, CFTDRtnHistoryTradePeakField> g_mapTradePeak; // 指标历史最大值map
list<CAttrTeam *> g_listAttrTeam;					// 历史指标组对象list
list<string> g_listExcludedSystem;					// 事件消息排除的系统名列表
map<string, long> g_mapAttrValue;					// 历史指标值Map 如:'TRADE.PuDian.app.tkernel:TradeSize' - 25564
CStringIdMap g_mStringIdMap;
CDataCenterManage *g_pDataCenterManage = NULL;		// 数据中心管理器

//20080714 add wu.yb
string	g_strDbIp;									// 数据库连接IP
string	g_strDbPort;								// 数据库连接PORT
string	g_strDbName;								// 数据库名
string	g_strDbUser;								// 数据库登陆用户
string	g_strDbPwd;									// 数据库登陆密码
////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

//2012.10.23 feng.q
//会员报单历史统计宽度,单位秒
unsigned int g_nOrderTimeWid = 300;

//add by feng.q
//启动参数， 控制数据库修改, 0：可以修改， 1： 跳过修改即不修改
int g_nStartParaWrtDB = 0;

//modify at 20121130, 在接受到slog流水之后立即解析
bool g_bDecSlogDirect = true;
CDirectlySlogDecode *g_CSlogDec;

//////////////////////////////////////////////////////////////////////////
map<string, CTimeValue> mapWarningTime;

void readEventConfig(void)
{
	char cfgFielName[200];
	sprintf(cfgFielName, "%s%s", g_mCfgPath, "SystemConfig.xml");

	CXMLDoc *m_pXMLDoc = NULL;
	CXMLNode *m_pXMLRoot = NULL;
	XMLNodeType NodeType = XMLTag;
	m_pXMLDoc = new CXMLDoc();
	m_pXMLDoc->read(cfgFielName);
	m_pXMLRoot = m_pXMLDoc->getRootNode();

	/* To be written on exit */
	CXMLNode *pServiceNode = m_pXMLRoot->findNode(
			NodeType,
			"Events",
			NULL,
			NULL);
	CXMLNodeList *pNodeList = pServiceNode->getNodeList();
	if (pNodeList != NULL)
	{
		CXMLNode *pNode = (*pNodeList)[0];
		for (int i = 0; i < (int)pNodeList->size(); i++)
		{
			CXMLNode *pNodeCur = (*pNodeList)[i];

			//printf("\nThe next expr %d:\n",i+1);
			g_nOrderNo++;
			mapWarningTime[string(
					pNodeCur->findProperty(XML_EVENT_NAME))] = CTimeValue(
					0,
					g_nOrderNo,
					pNodeCur->findProperty("MSG_SubjectId"),
					pNodeCur->findProperty("Comment"));
		}
	}

	delete m_pXMLDoc;
	return;
}

void readAttrConfig(void)
{
	XMLNodeType NodeType = XMLTag;
	CXMLDoc *pXMLDoc = new CXMLDoc();
	pXMLDoc->read((char *)XML_FILE_NAME);

	CXMLNode *pXMLRoot = pXMLDoc->getRootNode();

	if (NULL == pXMLRoot)
	{
		printf("cann't init AttrConfig from %s", (char *)XML_FILE_NAME);
		return;
	}

	CXMLNode *pServiceNode = pXMLRoot->findNode(
			NodeType,
			"AttrConfig",
			NULL,
			NULL);
	CXMLNodeList *pNodeList = pServiceNode->getNodeList();
	if (NULL != pNodeList)
	{
		for (int i = 0; i < (int)pNodeList->size(); i++)
		{
			CXMLNode *pNodeCur = (*pNodeList)[i];
			char *pName = pNodeCur->findProperty("name");
			char *pSeps = pNodeCur->findProperty("seps");
			char *pSubjectId = pNodeCur->findProperty("MSG_SubjectId");
			char *pComment = pNodeCur->findProperty("Comment");
			if (NULL != pName
			&&	NULL != pSeps
			&&	NULL != pSubjectId
			&&	NULL != pComment)
			{
				CAttrTeam *pAttrTeam = new CAttrTeam(pName, pComment, pSeps);
				pAttrTeam->LoadSubject(pSubjectId);

				CXMLNodeList *pAttrNodeList = pNodeCur->getNodeList();
				if (NULL != pAttrNodeList)
				{
					for (int j = 0; j < (int)pAttrNodeList->size(); j++)
					{
						CXMLNode *pAttrNode = (*pAttrNodeList)[j];
						char *pObjectId = pAttrNode->findProperty("ObjectId");
						char *pAttrType = pAttrNode->findProperty("Attr");
						char *pAttrComment = pAttrNode->findProperty("Comment");
						if (NULL != pObjectId
						&&	NULL != pAttrType
						&&	NULL != pAttrComment)
						{
							char szBuf[256] = "";
							sprintf(szBuf, "%s:%s", pObjectId, pAttrType);
							pAttrTeam->AddAttrItem(
									new CAttrItem(
											szBuf,
											pAttrType,
											pAttrComment));
							g_mapAttrValue[szBuf] = 0;
						}
					}
				}

				g_nOrderNo++;
				mapWarningTime[pName] = CTimeValue(
						0,
						g_nOrderNo,
						pSubjectId,
						pComment);
				g_listAttrTeam.push_back(pAttrTeam);
			}
		}
	}

	return;
}

void LoadExcludedSystem(char *pszSystem)
{
	char *p = strtok(pszSystem, ", ");
	while (NULL != p)
	{
		if (strlen(p) > 0)
		{
			g_listExcludedSystem.push_back(p);
		}

		p = strtok(NULL, ", ");
	}
}

bool globalInit(void)
{
	// Added by Henchi 20080718
	time_t	timep;
	time(&timep);
	printf("%s sysquery Start Running !!!\n", ctime(&timep));

	struct timeb nTimeb;
	ftime(&nTimeb);
	g_nTimeZoneSec = nTimeb.timezone * 60;

	///=== 20110907 by zhou.jj
#if 1
	{
		int i = 0;
		for (i = 0; i < 40; i++)
		{
			g_newSlogFlag[i] = 0;
		}

		GetConfigString(
			INI_FILE_NAME,
			"NewSLOGFront",
			g_mCfgPath,
			sizeof(g_mCfgPath));

		char *p = g_mCfgPath;
		while (p != NULL)
		{
			i = atoi(p);
			if (i < 40 && i > 0)
			{
				g_newSlogFlag[i] = 1;
			}

			p = strchr(p, ',');
			if (p != NULL)
			{
				p++;
			}
		}
	}

#endif

	/// 20110907 by zhou.jj
	char traceLogPath[200];							//系统运行日志路径
	GetConfigString(
		INI_FILE_NAME,
		"TraceLogPath",
		traceLogPath,
		sizeof(traceLogPath));
	GetConfigString(
		INI_FILE_NAME,
		"ConfigPath",
		g_mCfgPath,
		sizeof(g_mCfgPath));
	GetConfigString(
		INI_FILE_NAME,
		"FlowPath",
		g_mFlowPath,
		sizeof(g_mFlowPath));
	g_nWarningInterval = GetConfigInt(INI_FILE_NAME, "WarningInterval");
	g_nCommonInterval = GetConfigInt(INI_FILE_NAME, "CommonInterval");
	GetConfigString(
		INI_FILE_NAME,
		"WarningPath",
		g_mWarningPath,
		sizeof(g_mWarningPath));
	GetConfigString(
		INI_FILE_NAME,
		"SystemNum",
		g_mSystemNum,
		sizeof(g_mSystemNum));

	char szBuf[1024];
	GetConfigString(INI_FILE_NAME, "ExcludedSystem", szBuf, sizeof(szBuf));
	LoadExcludedSystem(szBuf);
	readEventConfig();
	readAttrConfig();

#ifdef PACKAGE_OUTPUT
	g_pPackOutput = new CFileLogger();

	char FilePath[100];
	sprintf(FilePath, "%s%s", g_mFlowPath, "querypackage.log");
	if (!((CFileLogger *)g_pPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		exit(0);
	}

#endif
	g_traceLog = new CFileLogger();
	if (!g_traceLog->Open(traceLogPath))
	{
		printf(
			"create trace log file failed! path detail (%s)\n",
			traceLogPath);
		fflush(stdout);
		exit(-1);
	}

	memset(pCounterLocation, 0x00, sizeof(pCounterLocation));
	memset(pQueryLocation, 0x00, sizeof(pQueryLocation));
	try
	{
		CDeployConfig::DBCfgInfo DBInfo;
		CDeployConfig DeployConfig;
		bool bRtn = DeployConfig.Parse(g_mCfgPath);

		if (bRtn == false)
		{
			printf(
				"Error While load DeployConfig info:\n%s\n",
				DeployConfig.Error().c_str());
			exit(0);
		}

		char szTmp[16] = "";
		sprintf(szTmp, "%d", g_nStartID);

		CDeployConfig::SysqueryCfgInfo	CfgInfo = DeployConfig.
			GetSysqueryCfgInfo(szTmp);

		string	strListener = CfgInfo.ServerAddr(XML_VAL_SERVICE_FRONT);
		string	strEventLocation = CfgInfo.ServerAddr(
				XML_TAG_SERVICES_EVENTCOUNTER);

		if (strListener.empty() || strEventLocation.empty())
		{
			printf(
				"Config info is incomplete! Check front address and event counter address.\n");
			exit(0);
		}

		strcpy(pQueryLocation, strListener.c_str());
		printf("Success to get Listener Address[%s]\n", pQueryLocation);

		strcpy(pCounterLocation, strEventLocation.c_str());
		printf("Success to get EventCounter Address[%s]\n", pCounterLocation);

		DBInfo = DeployConfig.GetDBCfgInfo(CfgInfo.m_dc);
		g_strDbPort = DBInfo.m_port;
		g_strDbName = DBInfo.m_dbname;
		g_strDbIp = DBInfo.m_ip;
		g_strDbUser = DBInfo.m_username;
		g_strDbPwd = DBInfo.m_pwd;

		printf(
			"DBConnect:%s %s %s %s %s\n",
			g_strDbIp.c_str(),
			g_strDbPort.c_str(),
			g_strDbName.c_str(),
			g_strDbUser.c_str(),
			g_strDbPwd.c_str());
	}

	catch(CRuntimeError * e)
	{
		printf(
			"Error While load DeployConfig info:\nLINE[%d]:%s\n",
			e->GetLineNo(),
			e->GetMsg());
		exit(0);
	}

	g_fileOperation = new CFileOperation();			// 初始化写文件类对象指针
	g_pSlogQuery = new CSlogQuery();				// 初始化查询实例指针
	g_pLoggerOutput = new CBufferLogger();			// SLog解析用
	g_OrderRttAnalysis = new COrderRttAnalysis();	// 响应速度分析类对象指针
	
		//////////////////////////////////////////////////////////////////////////

	//add by feng.q 20121130
	g_CSlogDec = new CDirectlySlogDecode();

	//////////////////////////////////////////////////////////////////////////
	//修改 @ 20120920
	//流文件的创建放在对象里面
	//	g_pFlow = new CCachedFileFlow("queryFlow",g_mFlowPath,true,1000,32*1024); // 必须在g_pStatusSubcriber之前初始化
	char temp[256];
	GetConfigString(INI_FILE_NAME, "Seps", temp, sizeof(temp));
	g_pJudgeRun = new CJudgeRun(temp);

	g_pStatusSubcriber = new CStatusSubscriber();

	char timeBuffer[20];
	GetConfigString(INI_FILE_NAME, "EndTime", timeBuffer, sizeof(timeBuffer));
	g_PackageFilter.SetEndTime(timeBuffer);
	GetConfigString(INI_FILE_NAME, "StartTime", timeBuffer, sizeof(timeBuffer));
	g_PackageFilter.SetStartTime(timeBuffer);
	
	g_pDataCenterManage = new CDataCenterManage();
	g_pDataCenterManage->XMLInit(g_mCfgPath);
	return true;
}

int main(int argc, char *argv[])
{
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);

	//	signal(SIGINT, SIG_IGN);
#endif
	showVersion(argc, argv);
	g_nStartID = getStartId(argc, argv);			// Mod by henchi, 20090430
	UseBizStatusLog = UseBizOperationLog = UseBizExceptionLog = false;
	UseNetStatusLog = UseNetConnectLog = UseNetIOLog = UseNetPackageLog = false, UseNetCompressLog = UseProcessLog = false;

	globalInit();

	if (argc == 3)
	{
		if (strcmp(argv[2], "0") == 0 || strcmp(argv[2], "off") == 0)
		{
			g_nStartParaWrtDB = 1;
		}
		else if (strcmp(argv[2], "1") == 0 || strcmp(argv[2], "on") == 0)
		{
			g_nStartParaWrtDB = 0;
		}
		else
		{
			//error
			printf("\nUsage:%s [启动标识] [数据库修改开关]\n\n", argv[0]);
			fflush(stdout);
			exit(0);
		}
	}

	//g_nStartParaWrtDB = 1;
		///载入配置并开始输出Syslog:
	SysReactor	reactor;
	CConfig *pConfig = new CConfig(INI_FILE_NAME);
	char *syslogFileName = pConfig->getConfig("SyslogPath");
	CMonitorIndex::init(
			CFilelogService::CreateInstance(argc, argv, syslogFileName),
			pConfig);

	string	strCutLine;
	string	strDate;
	{
		char *p = pConfig->getConfig("RttCutLine");

		int i = 0;
		if (p != NULL)
		{
			char *p2 = strchr(p, '@');
			if (p2 != NULL)
			{
				strDate = (p2 + 1);
				*p2 = '\0';
			}

			strCutLine = p;
		}

		if (false == CDate::IsValid(strDate.data()))
		{
			strDate = "20120910";
		}
	}

	delete pConfig;

	// 关闭报文压缩输出信息
	UseNetCompressLog = false;

	g_pStatusSubcriber->InitDBParam(
			strDate.data(),
			"sysquery.ini",
			strCutLine.data());

	time_t	t;
	try
	{
		g_pReactor = new CSlogReactor();

		CQueryServer frontServer(g_pReactor);

		CCountConnector countConnector(g_pReactor);

		SessionProxy::Instance().Init(&frontServer);

		frontServer.RegisterListener(pQueryLocation);
		countConnector.RegisterConnecter(pCounterLocation);
		reactor.Create();
		g_pReactor->Create();

		frontServer.Start();
		countConnector.Start();
		g_pReactor->Join();
		reactor.Join();

		return 0;
	}
	catch(...)
	{
		time(&t);
		printf("\nTime:%sFailed, quit.\n", ctime(&t));
		exit(-1);
	}
}