/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	sysfront.cpp
///@brief	监控前置的main主函数实现
///@history
///20080508	周建军		创建该文件
///20080623	周建军		修订注释
///20080703 晏鹤春		添加读取XML配置信息相关处理
///20090430	晏鹤春		修改程序启动标识的校验
/////////////////////////////////////////////////////////////////////////
#include "public.h"
#include "utility.h"
#include "Config.h"
#include "xmlcfg.h"
#include "CDeployConfig.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "FrontServer.h"
#include "CountConnector.h"
#include "FlowConnector.h"
#include "CSynConnector.h"
#include "databaseData.h"
#include "CStatusSubscriber.h"
#include "CResultSubscriber.h"
#include "CQueryAgent.h"
#include "CSlogAgent.h"
#include "version.h"
#include "CFilelogService.h"
#include <iostream>
#include "CPerformanceAnalyze.h"
using namespace std;

volatile int g_Count = 0;
extern CListSessionArray *g_pListSessionArray;
extern CConfig	*currentConfig;
extern list<CFTDCSession *> g_mListAllSession;
extern CTypeObjectIDType g_DataCenter;
int g_FrontRange = 0;

///用于确定峰值统计基线
string	g_peakBaseOid;

list<CFTDRspQryFrontInfoField>	g_testList;

/*
class CMyTimmer : public CEventHandler
{
public:
	CMyTimmer(CReactor *pReactor)
		:CEventHandler(pReactor)
	{
		m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
		SetTimer(1, 1000);
	}

	virtual void OnTimer(int nIDEvent)
	{
		{
			time_t timep;
			time(&timep);
			struct tm *pGm = localtime(&timep);
			sprintf(theTime,"%02d:%02d:%02d", pGm->tm_hour, pGm->tm_min, pGm->tm_sec);
		}

		switch(nIDEvent)
		{
		case 1:
			{
				m_pkgSend.PreparePackage(FTD_TID_RtnSysTimeSyncTopic, FTDC_CHAIN_LAST, FTD_VERSION);
				CFTDRtnSysTimeSyncField tfield;
				memset(&tfield ,0 ,sizeof(tfield));
				strcpy((char *)(tfield.MonTime.getValue()) ,theTime);
				FTDC_ADD_FIELD(&m_pkgSend, &tfield);

				list<CFTDCSession *>::iterator it;
				for(it=g_mListAllSession.begin();it!=g_mListAllSession.end();it++)
				{
					(*it)->SendRequestPackage(&m_pkgSend);
					m_pkgSend.Pop(FTDCHLEN);
				}
			}
		}
	}
private:
	///发送数据包使用的缓冲区
	CFTDCPackage m_pkgSend;
};
*/
const char	*INI_FILE_NAME = "sysfront.ini";
char g_mCfgPath[200] = "";
char g_mFlowPath[200] = "";
char *g_mXMLPath = "./sysfront.xml";
char pCounterLocation[200] = "";
char pFrontLocation[200] = "";
char pFlowLocation[200] = "";
char pQueryLocation[200] = "";
char pSynLocation[200] = "";
char *g_Today = NULL;
char pListSessionSize[10] = "";
CMemoryDB *pMemoryDB;
CStatusSubscriber *g_pStatusSubcriber[MAX_EVENTFLOWNUM];
CResultSubscriber *g_pResultSubcriber = NULL;
CDataCenterManage *g_pDataCenterManage = NULL;
CStringIdMap g_StringIdMap;
CXMLDoc *pXMLDoc = NULL;

// 网络性能处理对象
CPerformanceAnalyzer* g_pPerformanceAnalyzer = NULL;

//CXMLNode *pXMLRootNode =NULL;
CTimeType theTime;
CDateType theDate;
CTimeType NowTime;
CDateType NowDate;
string	g_VersionPath;

CFTDRtnSysTimeSyncField g_sysTimeSyncField;

#ifdef PACKAGE_OUTPUT
CLogger *g_pClnPackOutput = NULL;	// 数据包输出到文件
CLogger *g_pQryPackOutput = NULL;
CLogger *g_pEntPackOutput = NULL;
CLogger *g_pFibPackOutput = NULL;
CLogger *g_pFwdPackOutput = NULL;
CLogger *g_pConPackOutput = NULL;
#endif
extern bool UseNetCompressLog;		// 报文压缩信息输出开关
bool globalInit(void)
{
	g_Today = new char[10];

	time_t timep;
	time(&timep);
	struct tm tm_time;
	LocalTime(&timep, &tm_time);

	sprintf(
		(char *)(NowTime.getValue()),
		"%02d:%02d:%02d",
		tm_time.tm_hour,
		tm_time.tm_min,
		tm_time.tm_sec);
	sprintf(
		(char *)(NowDate.getValue()),
		"%d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);
	sprintf(
		g_Today,
		"%04d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);
	

	printf("%s sysfront Start Running !!!\n", ctime(&timep));
	fflush(stdout);

	CConfig *pConfig;
	pConfig = new CConfig(INI_FILE_NAME);
	currentConfig = pConfig;
	pMemoryDB = new CMemoryDB();
	pMemoryDB->init(pConfig);

	/// Added by Henchi, 20120626
	char szObjectAttrSize[32];
	GetConfigString(
		INI_FILE_NAME,
		"ObjectAttrSize",
		szObjectAttrSize,
		sizeof(szObjectAttrSize));

	int iObjectAttrSize = atoi(szObjectAttrSize) > 100000 ? atoi(
			szObjectAttrSize) : 100000;
	g_pListSessionArray = new CListSessionArray(iObjectAttrSize);

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

	//	GetConfigString(INI_FILE_NAME, "ListSessionSize",   pListSessionSize,  sizeof(pListSessionSize));
	//	if(pListSessionSize)
	//		g_pListSessionArray->SetListSize(atoi(pListSessionSize));
	//	else
	//		return false;
	//	GetConfigString(INI_FILE_NAME, "XMLPath",   g_mXMLPath,  sizeof(g_mXMLPath));
	{
		string	str = g_mXMLPath;
		if (access((char *)str.data(), 0) == 0)
		{
			pXMLDoc = new CXMLDoc();
			pXMLDoc->read(g_mXMLPath);

			//			CXMLNode *pXMLRootNode =new CXMLNode();
			//			pXMLRootNode= pXMLDoc->getRootNode();
		}
	}

	///获得主数据中心名：
		///初始化为空，当FIBCLIENT收到流初始化信息的时候给予FRONT初始化主数据中心名:
	g_DataCenter = "";

	char tmp[100] = "";
	sprintf(tmp, "%s.%s", "app.tkernel.1", APPATTRHANDLEORDERINSERTTOTAL);
	g_peakBaseOid = tmp;

	g_sysTimeSyncField.MonDate = "";
	g_sysTimeSyncField.MonTime = "";

	/*
	{
		CConfig cfg(INI_FILE_NAME);
		char *pszConfigPath = cfg.getConfig("ConfigPath");
		CXMLConfig *pXMLCfg = new CXMLConfig(pszConfigPath);
		list<string> tmpList;
		int tmp =0;
		pXMLCfg->GetAppList(&tmp ,tmpList, "PuDian", "front");
		if(tmp ==1)
			strcpy((char *)(g_DataCenter.getValue()) ,DATACENTERPUDIAN);
		else
			strcpy((char *)(g_DataCenter.getValue()) ,DATACENTERZHANGJ);
	}
*/
#ifdef PACKAGE_OUTPUT
	g_pClnPackOutput = new CFileLogger();
	g_pQryPackOutput = new CFileLogger();
	g_pEntPackOutput = new CFileLogger();
	g_pFibPackOutput = new CFileLogger();
	g_pFwdPackOutput = new CFileLogger();
	g_pConPackOutput = new CFileLogger();

	char FilePath[100];
	sprintf(FilePath, "%s%s", g_mFlowPath, "frontcln.log");
	if (!((CFileLogger *)g_pClnPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

	sprintf(FilePath, "%s%s", g_mFlowPath, "frontqry.log");
	if (!((CFileLogger *)g_pQryPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

	sprintf(FilePath, "%s%s", g_mFlowPath, "frontent.log");
	if (!((CFileLogger *)g_pEntPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

	sprintf(FilePath, "%s%s", g_mFlowPath, "frontfib.log");
	if (!((CFileLogger *)g_pFibPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		exit(0);
	}

	sprintf(FilePath, "%s%s", g_mFlowPath, "frontfwd.log");
	if (!((CFileLogger *)g_pFwdPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		exit(0);
	}

	sprintf(FilePath, "%s%s", g_mFlowPath, "frontcon.log");
	if (!((CFileLogger *)g_pConPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		exit(0);
	}

#endif
	g_pDataCenterManage = new CDataCenterManage();
	g_pDataCenterManage->XMLInit(g_mCfgPath);
	for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
	{
		g_pStatusSubcriber[i] = new CStatusSubscriber(i + 1);
	}

	//g_pStatusSubcriber = new CStatusSubscriber();
	g_pResultSubcriber = new CResultSubscriber();

	// add by cao.ning
	// 从front.ini中读取是否启用网络性能分析功能
	int iNetPerformanceAnalyzer = atoi(currentConfig->getConfig("NetPerformanceAnalyzer"));
	if (iNetPerformanceAnalyzer)
	{
		g_pPerformanceAnalyzer = new CPerformanceAnalyzer();
	}

	return true;
}

class FrontReactor :
	public CSelectReactor,
	public CEventHandler
{
	/* */
	public:
		FrontReactor(void) :
		CEventHandler(this)
		{
			m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
			SetTimer(0, 1000);
			SetTimer(1, 5000);
		}

		virtual void OnTimer(int nIDEvent)
		{
			switch (nIDEvent)
			{
				case 0:
					CMonitorIndex::handleOne();
					break;
				case 1:
					{
						time_t	timep;
						time(&timep);

						struct tm tm_time;
						LocalTime(&timep, &tm_time);
						sprintf(
							(char *)(NowTime.getValue()),
							"%02d:%02d:%02d",
							tm_time.tm_hour,
							tm_time.tm_min,
							tm_time.tm_sec);
						sprintf(
							(char *)(NowDate.getValue()),
							"%d%02d%02d",
							tm_time.tm_year + 1900,
							tm_time.tm_mon + 1,
							tm_time.tm_mday);
						timep -= g_FrontRange * 3600;

						LocalTime(&timep, &tm_time);
						sprintf(
							(char *)(theTime.getValue()),
							"%02d:%02d:%02d",
							tm_time.tm_hour,
							tm_time.tm_min,
							tm_time.tm_sec);
						sprintf(
							(char *)(theDate.getValue()),
							"%d%02d%02d",
							tm_time.tm_year + 1900,
							tm_time.tm_mon + 1,
							tm_time.tm_mday);

						if (g_sysTimeSyncField.MonDate == ""
						||	g_sysTimeSyncField.MonTime == "")
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RtnSysTimeSyncTopic,
									FTDC_CHAIN_LAST,
									FTD_VERSION);

							CFTDRtnSysTimeSyncField tfield;
							memset(&tfield, 0, sizeof(tfield));
							tfield.MonDate = NowDate;
							tfield.MonTime = NowTime;
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						}
						else
						{
							m_pkgSend.PreparePackage(
									FTD_TID_RtnSysTimeSyncTopic,
									FTDC_CHAIN_LAST,
									FTD_VERSION);

							CFTDRtnSysTimeSyncField tfield;
							memset(&tfield, 0, sizeof(tfield));
							tfield.MonDate = g_sysTimeSyncField.MonDate;
							tfield.MonTime = g_sysTimeSyncField.MonTime;
							FTDC_ADD_FIELD(&m_pkgSend, &tfield);
						}

						list<CFTDCSession *>::iterator	it;
						for (it = g_mListAllSession.begin();
							 it != g_mListAllSession.end();
							 it++)
						{
							(*it)->SendRequestPackage(&m_pkgSend);
							m_pkgSend.Pop(FTDCHLEN);
						}
					}

					break;
				default:
					break;
			}
		}

	/* */
	private:
		///发送数据包使用的缓冲区
		CFTDCPackage m_pkgSend;
};

int main(int argc, char *argv[])
{
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);

	//	signal(SIGINT, SIG_IGN);
#endif

	/*CFTDRspQryFrontInfoField thefield;
	int iCount =0;
	for(int id =1 ;id <30 ;id ++)
	{
		for(int level =0 ;level <5 ;level ++)
		{
			time_t timep;
			time(&timep);
			struct tm *pGm = localtime(&timep);
			sprintf((char *)(NowTime.getValue()),"%02d:%02d:%02d", pGm->tm_hour, pGm->tm_min, pGm->tm_sec);
			sprintf((char *)(NowDate.getValue()),"%d%02d%02d" ,pGm->tm_year+1900 ,pGm->tm_mon+1 ,pGm->tm_mday);

			thefield.MonDate =NowDate;
			thefield.MonTime =NowTime;
			char value[65];
			sprintf(value,"Trade.Pudian.front.%d", id);
			strcpy((char *)thefield.FrontId.getValue() ,value);
			thefield.RspCondition =level;
			thefield.ReqCount =iCount ++;
			thefield.ReqRate =iCount/100.00;
			g_testList.push_back(thefield);

			SLEEP(100);
		}
	}*/
	//	int a =cal_crc("PuDian.app.mdkernel.1.HandleLoginErrorTotal", strlen("PuDian.app.mdkernel.1.HandleLoginErrorTotal"))%65536;
	//	int b =cal_crc("PuDian.os.AC-01.cpu.0", strlen("PuDian.os.AC-01.cpu.0"))%65536;
	showVersion(argc, argv);

	int iFrontID = getStartId(argc, argv);	// Mod by henchi, 20090430
	globalInit();

	// 关闭报文压缩输出信息
	UseNetCompressLog = false; 
	string	strSlogServerLocation;

	try
	{
		CDeployConfig DeployConfig;
		bool bRtn = DeployConfig.Parse(g_mCfgPath);

		if (bRtn == false)
		{
			printf(
				"Error While load DeployConfig info:\n%s\n",
				DeployConfig.Error().c_str());
			exit(0);
		}
		else
		{
			char szTmp[16] = "";
			sprintf(szTmp, "%d", iFrontID);

			CDeployConfig::SysfrontCfgInfo	CfgInfo = DeployConfig.
				GetSysfrontCfgInfo(szTmp);
			string	strListener = CfgInfo.ServerAddr(XML_VAL_SERVICE_CLIENT);
			if (strListener.empty())
			{
				printf("Failed to get Listener Address\n");
				exit(0);
			}
			else
			{
				strcpy(pFrontLocation, strListener.c_str());
				printf("Success to get Listener Address[%s]\n", pFrontLocation);
			}

			string	strSynconfigLocation = CfgInfo.ServerAddr(
					XML_VAL_SERVICE_CONFIG);
			if (strSynconfigLocation.empty())
			{
				printf("Failed to get Synconfig Address\n");
				exit(0);
			}
			else
			{
				strcpy(pSynLocation, strSynconfigLocation.c_str());
				printf("Success to get Synconfig Address[%s]\n", pSynLocation);
			}

			string	strEventLocation = CfgInfo.ServerAddr(
					XML_VAL_SERVICE_EVENTCOUNTER);
			if (strEventLocation.empty())
			{
				printf("Failed to get EventCounter Address\n");
				exit(0);
			}
			else
			{
				strcpy(pCounterLocation, strEventLocation.c_str());
				printf(
					"Success to get EventCounter Address[%s]\n",
					pCounterLocation);
			}

			string	strSysqueyrLocation = CfgInfo.ServerAddr(
					XML_VAL_SERVICE_QUERY);
			if (strSysqueyrLocation.empty())
			{
				printf("Failed to get Sysquery Address\n");
				exit(0);
			}
			else
			{
				strcpy(pQueryLocation, strSysqueyrLocation.c_str());
				printf("Success to get Sysquery Address[%s]\n", pQueryLocation);
			}
			
			strSlogServerLocation = CfgInfo.ServerAddr(
					XML_VAL_SERVICE_SLOG);
			if (strSlogServerLocation.empty())
			{
				printf("Failed to get slog Address\n");
				exit(0);
			}
			else
			{
				printf("Success to get SlogServer Address[%s]\n", strSlogServerLocation.c_str());
			}

			string	strFibclientLocation = CfgInfo.ServerAddr(
					XML_VAL_SERVICE_FIBCLIENT);
			if (strFibclientLocation.empty())
			{
				printf("Failed to get Sysfibclient Address\n");
			}
			else
			{
				strcpy(pFlowLocation, strFibclientLocation.c_str());
				printf(
					"Success to get Sysfibclient Address[%s]\n",
					pFlowLocation);
			}
		}
	}

	catch(CRuntimeError * e)
	{
		printf(
			"Error While load DeployConfig info:\nLINE[%d]:%s\n",
			e->GetLineNo(),
			e->GetMsg());
		exit(0);
	}

	time_t	t;
	try
	{
		//		CSelectReactor reactor;
		FrontReactor reactor;
		CConfig *pConfig = new CConfig(INI_FILE_NAME);
		char *syslogFileName = pConfig->getConfig("SyslogPath");
		g_FrontRange = atoi(pConfig->getConfig("FrontRange"));
		g_VersionPath = pConfig->getConfig("FilePackagePath");
		CMonitorIndex::init(
				CFilelogService::CreateInstance(argc, argv, syslogFileName),
				pConfig);
		delete pConfig;

		//		CMyTimmer theTimer(&reactor);
		CQueryAgent queryAgent(&reactor);
		CSlogAgent slogAgent(&reactor);
		CCountConnector countConnector(&reactor);
		CSynConnector synConnector(&reactor);
		CFlowConnector	flowConnector(&reactor);
		CFrontServer frontServer(
						&reactor,
						&queryAgent,
						&slogAgent,
						&countConnector,
						&synConnector,
						&flowConnector);
		queryAgent.SetFrontServer(&frontServer);
		slogAgent.SetFrontServer(&frontServer);
		countConnector.SetFrontServer(&frontServer);
		synConnector.SetFrontServer(&frontServer);
		flowConnector.SetFrontServer(&frontServer);

		if (g_pPerformanceAnalyzer)
		{
			g_pPerformanceAnalyzer->SetFrontServer(&frontServer);
		}

		queryAgent.RegisterConnecter(pQueryLocation);
		slogAgent.RegisterConnecter(strSlogServerLocation.c_str());
		frontServer.RegisterListener(pFrontLocation);
		countConnector.RegisterConnecter(pCounterLocation);
		if (strcmp(pFlowLocation, "") != 0)
		{
			flowConnector.RegisterConnecter(pFlowLocation);
		}

		synConnector.RegisterConnecter(pSynLocation);

		reactor.Create();

		queryAgent.Start();
		slogAgent.Start();
		frontServer.Start();
		countConnector.Start();
		if (strcmp(pFlowLocation, "") != 0)
		{
			flowConnector.Start();
		}

		synConnector.Start();

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
