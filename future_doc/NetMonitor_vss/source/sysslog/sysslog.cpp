#include "public.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "CSlogServer.h"
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

const char	*INI_FILE_NAME = "sysslog.ini";	// ini�����ļ���
const char	*APP_NAME = "sysslog";				// Ӧ������

///=== 20110907 by zhou.jj
int g_newSlogFlag[COUNT_NEW_SLOG_FLAG];

/// 20110907 by zhou.jj
char pCounterLocation[200] = "";				// �¼�������������ӵ�ַ"tcp://127.0.0.1:9400"
char pSlogLocation[200] = "";					// ��ѯ�����������˿�"tcp://127.0.0.1:9600"
char g_mFlowPath[200] = "";						// ���ļ�Ŀ¼"./flow/"
char g_mCfgPath[200] = "";						// ϵͳxml�����ļ�Ŀ¼"../../config"
char g_mStartTime[9];							// ͳ������д�����ݿ⿪ʼʱ��
char g_mEndTime[9];								// ͳ������д��
char g_mWarningPath[100] = "";					// �澯����ļ�·��
char g_mSystemNum[20] = "";						// �澯�����ϵͳ����
int g_nWarningInterval = 600;					// �澯���������ʱ�䣨�룩
int g_nCommonInterval = 3600;					// ͨ�ø澯��ָ������
int g_nTimeZoneSec = 0;							//��������ʱ��
int g_nOrderNo = 0;								//�¼����
int g_nStartID = 0;								//Ӧ���������

//�޸� @ 20120920
//���ļ��ֳ�9����ÿ3Сʱ�л�
//9�����ļ�����1�����Ķ������洴��
CStatusSubscriber *g_pStatusSubcriber;			// ״̬��ʶ��ָ��

//CCachedFileFlow		*g_pFlow = NULL; 				// ���ļ�ָ��
CLogger *g_pLoggerOutput = NULL;				// ���ݰ����������ָ��
CSlogQuery	*g_pSlogQuery = NULL;				// Slog��ѯ����ʵ��ָ��
CFileOperation	*g_fileOperation = NULL;		// д�ļ������ָ��
COrderRttAnalysis *g_OrderRttAnalysis = NULL;	// ��Ӧ�ٶȷ��������ָ��
CSlogReactor *g_pReactor = NULL;				// ȫ��reactor����ָ�룬ֻ��һ�ι���
CJudgeRun *g_pJudgeRun = NULL;					// ȫ��ʱ����жϴ������ֻ��һ�ι���
#ifdef PACKAGE_OUTPUT
CLogger *g_pPackOutput = NULL;					// ���ݰ�������ļ�
#endif
extern bool UseNetCompressLog;					// ����ѹ����Ϣ�������
bool g_bAnalysisRTT = true;
char g_szTimeBuffer[10];
char g_szDateBuffer[10];              //�Ӵ˱�����Ϊ����rtt�и�ֵ��mondate
CPackageFilter	g_PackageFilter;
map<string, int> g_mapSlogFileName;
map<CPeakKey, CFTDRtnHistoryTradePeakField> g_mapTradePeak; // ָ����ʷ���ֵmap
list<CAttrTeam *> g_listAttrTeam;					// ��ʷָ�������list
list<string> g_listExcludedSystem;					// �¼���Ϣ�ų���ϵͳ���б�
map<string, long> g_mapAttrValue;					// ��ʷָ��ֵMap ��:'TRADE.PuDian.app.tkernel:TradeSize' - 25564
CStringIdMap g_mStringIdMap;
CDataCenterManage *g_pDataCenterManage = NULL;		// �������Ĺ�����

unsigned long long g_nMallocSize = 0;                          //�洢���ڴ��С

//////////////////////////////////////////////////////////////////////////

//2012.10.23 feng.q
//��Ա������ʷͳ�ƿ��,��λ��
unsigned int g_nOrderTimeWid = 300;


//modify at 20121130, �ڽ��ܵ�slog��ˮ֮����������
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
	printf("%s sysslog Start Running !!!\n", ctime(&timep));

	struct timeb nTimeb;
	ftime(&nTimeb);
	g_nTimeZoneSec = nTimeb.timezone * 60;

	///=== 20110907 by zhou.jj
#if 1
	{
		int i = 0;
		for (i = 0; i < COUNT_NEW_SLOG_FLAG; i++)
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
			if (i < COUNT_NEW_SLOG_FLAG && i > 0)
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
	char traceLogPath[200];							//ϵͳ������־·��
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
	g_nMallocSize = GetConfigInt(INI_FILE_NAME, "MallocSize");
	if (g_nMallocSize == 0)
	{
		g_nMallocSize = 10240;
	}
	g_nMallocSize *= 1024 * 1024;

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
	memset(pSlogLocation, 0x00, sizeof(pSlogLocation));
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

		CDeployConfig::SysslogCfgInfo	CfgInfo = DeployConfig.GetSysslogCfgInfo(szTmp);

		string	strListener = CfgInfo.ServerAddr(XML_VAL_SERVICE_FRONT);
		string	strEventLocation = CfgInfo.ServerAddr(
				XML_TAG_SERVICES_EVENTCOUNTER);

		if (strListener.empty() || strEventLocation.empty())
		{
			printf(
				"Config info is incomplete! Check front address and event counter address.\n");
			exit(0);
		}

		strcpy(pSlogLocation, strListener.c_str());
		printf("Success to get Listener Address[%s]\n", pSlogLocation);

		strcpy(pCounterLocation, strEventLocation.c_str());
		printf("Success to get EventCounter Address[%s]\n", pCounterLocation);
	}

	catch(CRuntimeError * e)
	{
		printf(
			"Error While load DeployConfig info:\nLINE[%d]:%s\n",
			e->GetLineNo(),
			e->GetMsg());
		exit(0);
	}

	g_fileOperation = new CFileOperation();			// ��ʼ��д�ļ������ָ��
	g_pSlogQuery = new CSlogQuery();				// ��ʼ����ѯʵ��ָ��
	g_pLoggerOutput = new CBufferLogger();			// SLog������
	g_OrderRttAnalysis = new COrderRttAnalysis();	// ��Ӧ�ٶȷ��������ָ��
	
		//////////////////////////////////////////////////////////////////////////

	//add by feng.q 20121130
	g_CSlogDec = new CDirectlySlogDecode();

	//////////////////////////////////////////////////////////////////////////
	//�޸� @ 20120920
	//���ļ��Ĵ������ڶ�������
	//	g_pFlow = new CCachedFileFlow("queryFlow",g_mFlowPath,true,1000,32*1024); // ������g_pStatusSubcriber֮ǰ��ʼ��
	char temp[256];
	GetConfigString(INI_FILE_NAME, "Seps", temp, sizeof(temp));
	g_pJudgeRun = new CJudgeRun(temp);

	g_pStatusSubcriber = new CStatusSubscriber();

	char timeBuffer[256];	
	GetConfigString(INI_FILE_NAME, "TimeInternals", timeBuffer, sizeof(timeBuffer));
	g_PackageFilter.ResolveTimeIntervals(timeBuffer);

	g_pDataCenterManage = new CDataCenterManage();
	g_pDataCenterManage->XMLInit(g_mCfgPath);
	return true;
}
unsigned int g_nRttCutLine[8];

void InitializeRttCutLine(CConfig *pConfig)
{
	assert(pConfig != NULL);
	//����cutline �� date
	char *p = pConfig->getConfig("RttCutLine");
	//��ʼ��ʱ��ֲ��и���
	for (int i = 0; i < 8; i++)
	{
		g_nRttCutLine[i] = (unsigned int) -1;
	}

	int i = 0;
	if (p != NULL)
	{
		char *p2 = strchr(p, '@');
		if (p2 != NULL)
		{
			*p2 = '\0';
		}

		int i = 0;
		while (p != NULL && i < 8)
		{
			g_nRttCutLine[i] = atoi(p);
			p = strchr(p, ',');
			if (p != NULL)
			{
				p++;
				i++;
			}
		}
	}
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

	if (argc != 2)
	{
		//error
		printf("\nUsage:%s [������ʶ] \n\n", argv[0]);
		fflush(stdout);
		exit(0);
	}

	///�������ò���ʼ���Syslog:
	SysReactor	reactor;
	CConfig *pConfig = new CConfig(INI_FILE_NAME);
	char *syslogFileName = pConfig->getConfig("SyslogPath");
	CMonitorIndex::init(
			CFilelogService::CreateInstance(argc, argv, syslogFileName),
			pConfig);
	//�������
	InitializeRttCutLine(pConfig);

	delete pConfig;

	// �رձ���ѹ�������Ϣ
	UseNetCompressLog = false;
	g_pReactor = new CSlogReactor();
	g_pStatusSubcriber->InitFlow();
	g_pStatusSubcriber->InitTradeOrderCutLine();

	time_t	t;
	try
	{
		CSlogServer frontServer(g_pReactor);

		CCountConnector countConnector(g_pReactor);

		SessionProxy::Instance().Init(&frontServer);

		frontServer.RegisterListener(pSlogLocation);
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