/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	sysagent.cpp
///@brief	采集代理的main主函数实现
///@history
///20080508	周建军		创建该文件
///20080623	周建军		修订注释
/////////////////////////////////////////////////////////////////////////
#include "version.h"
#include "public.h"
#include "Config.h"
#include "CConfig.h"
#include "CFilelogService.h"
#include "CachedFileFlow.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "xmlcfg.h"
#include "AgentConnector.h"
#include "CounterConnector.h"
#include "CEventProcess.h"
#include "AgentServer.h"

// 20080908 add by wu.yb
#include "OraclePassClient.h"
#include <CDeployConfig.h>
#include <PrjCommon.h>

const char	*INI_FILE_NAME = "sysagent.ini";
const char	*APP_NAME = "sysagent";

bool g_bProxyFlag = false;
int g_mAgentId = 0;
CEventProcess *pEventProcess = NULL;
CIPAnalysis *pIpAnalysis = NULL;
char g_mTradeDay[9];
char pCounterLocation[200];
char pProxyLocation[200];
char g_mCfgPath[200];					//保存配置文件路径
CObjectIdSession g_mObjectIdSession;	//保存当前所有的ObjectID及所属的session信息
COraclePassClient g_mOraclePassClient;	//用于保存当前所有BNS服务器IP及端口信息
map<string, CRequstDBConnectInfo> g_mapDBConnectInfo;	//用于保存数据库连接名与其连接信息结构的映射
map<string, map<string, CDBConnectString> > g_OraclePass;
map<string, int> mapMonth;

///从探针向事件分析服务器发送请求的整合RID列表
CManageReqIDSession g_cProbeToEventReq;

///从事件分析服务器向探针发送请求的整合RID列表
CManageReqIDSession g_cEventToProbeReq;

#ifdef PACKAGE_OUTPUT
char g_mFlowPath[200];						//保存流文件存储路径
CLogger *g_pPackOutput = NULL;				// 数据包输出到文件
#endif
extern bool UseNetCompressLog;				// 报文压缩信息输出开关

// add by cao.ning
// 系统内部连接拓扑
CSysInternalTopology* g_SysInternalTopology = NULL;

void globalEnvInit(void)
{
	time_t	timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	sprintf(
		g_mTradeDay,
		"%04d%02d%02d",
		tm_time.tm_year + 1900,
		tm_time.tm_mon + 1,
		tm_time.tm_mday);
	printf("%s sysagent Start Running !!!\n", ctime(&timep));
	fflush(stdout);

	mapMonth[string("Jan")] = 1;
	mapMonth[string("Feb")] = 2;
	mapMonth[string("Mar")] = 3;
	mapMonth[string("Apr")] = 4;
	mapMonth[string("May")] = 5;
	mapMonth[string("Jun")] = 6;
	mapMonth[string("Jul")] = 7;
	mapMonth[string("Aug")] = 8;
	mapMonth[string("Sep")] = 9;
	mapMonth[string("Oct")] = 10;
	mapMonth[string("Nov")] = 11;
	mapMonth[string("Dec")] = 12;

	GetConfigString(
		INI_FILE_NAME,
		"ConfigPath",
		g_mCfgPath,
		sizeof(g_mCfgPath));
	GetConfigString(INI_FILE_NAME, "WorkType", pProxyLocation, 200);
	if (atoi(pProxyLocation) == 1)
	{
		g_bProxyFlag = true;
		GetConfigString(INI_FILE_NAME, "ProxyLocation", pProxyLocation, 200);
	}
	else
	{
		g_bProxyFlag = false;
	}

	if (!g_bProxyFlag)
	{
		pIpAnalysis = new CIPAnalysis(g_mCfgPath);
		pEventProcess = new CEventProcess;
	}

#ifdef PACKAGE_OUTPUT
	GetConfigString(INI_FILE_NAME, "FlowPath", g_mFlowPath, sizeof(g_mCfgPath));
	g_pPackOutput = new CFileLogger();

	char FilePath[100];
	sprintf(FilePath, "%s%s", g_mFlowPath, "agentpackage.log");
	if (!((CFileLogger *)g_pPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

#endif
}

void initDBConnectInfo(
	list<CBNSInfo>	&listBNS,
	list<CDBConnectString>	&listDBConnect)
{
	for (list<CBNSInfo>::iterator it = listBNS.begin();
		 it != listBNS.end();
		 it++)
	{
		g_mOraclePassClient.InsertBNSInfo(it->m_sServerIP, it->m_nPort);
	}

	for (list<CDBConnectString>::iterator iter = listDBConnect.begin();
		 iter != listDBConnect.end();
		 iter++)
	{
		CRequstDBConnectInfo connectInfo = CRequstDBConnectInfo((*iter));

		// Mod by Henchi, 20100401
				/// 调整BNS验证时机，仅当配置信息不足时，发送BNS验证；否则直接采用配置项
		if (!connectInfo.m_ConnectInfo.IsValid())
		{
			g_mOraclePassClient.GetOracleAccountInfo(
					connectInfo.m_RequestInfo,
					connectInfo.m_ConnectInfo);
		}

		/// 当配置项有效，或已通过BNS成功获取检验结果时，将连接信息存入全局Map
		if (connectInfo.m_ConnectInfo.IsValid())
		{
			g_mapDBConnectInfo.insert(
					make_pair(
						(string) (iter->m_sAlias),
						(CRequstDBConnectInfo) (connectInfo)));
		}
	}
}

CCounterConnector *g_pCounterConn = NULL;
CAgentServer *g_pAgentServer = NULL;
CAgentConnector *g_pConnector[MAXPROBECONFIGNUM];
SysReactor	g_cReactor;

int main(int argc, char *argv[])
{
	showVersion(argc, argv);
	g_mAgentId = getStartId(argc, argv);	// Mod by henchi, 20090430
	globalEnvInit();

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
		g_SysInternalTopology = new CSysInternalTopology(APP_NAME, g_mAgentId);
	}

	delete pConfig;

	// 关闭报文压缩输出信息
	UseNetCompressLog = false;

	int i = 0;
	for (i = 0; i < MAXPROBECONFIGNUM; i++)
	{
		g_pConnector[i] = NULL;
	}

	memset(pCounterLocation, 0x00, sizeof(pCounterLocation));

	if (g_bProxyFlag)						///传输型采集代理
	{
		g_pAgentServer = new CAgentServer(&g_cReactor);
		g_pAgentServer->RegisterListener(pProxyLocation);
	}
	else
	{
		CXMLConfig	*pXMLCfg = new CXMLConfig(g_mCfgPath);
		if (pXMLCfg != NULL)
		{
			try
			{
				CDeployConfig cfg;

				cfg.Parse(g_mCfgPath);

				char id[6];
				SNPRINTF(id, 6, "%d", g_mAgentId);

				CDeployConfig::SysAgentCfgInfo	info = cfg.GetSysAgentCfgInfo(
						(std::string) id);

				g_pCounterConn = new CCounterConnector(
						&g_cReactor,
						pEventProcess);
				g_pCounterConn->RegisterConnecter(
						(char *)info.ServerAddr("syseventcounter").c_str());
			}

			catch(CRuntimeError * e)
			{
				printf("%s\n", e->GetMsg());
				fflush(stdout);
				exit(-1);
			}

			// Added by Henchi, 20100329	初始化BNS列表
			list<CBNSInfo>	listBNS;
			list<CDBConnectString>	listDBConnect;

			//// Mod by Henchi, 20100527
						//// BNS配置项不再是必要条件
			if (pXMLCfg->GetDBConnectStringList(listDBConnect))
			{
				pXMLCfg->GetBNSList(listBNS);
				initDBConnectInfo(listBNS, listDBConnect);
			}

			i = 0;

			list<CServerInfo> listInfo;
			char buf[64];
			sprintf(buf, "%d", g_mAgentId);
			if (pXMLCfg->GetAgentConnListByName(buf, listInfo))
			{
				list<CServerInfo>::iterator iter;
				for (i = 0, iter = listInfo.begin();
					 i < MAXPROBECONFIGNUM && iter != listInfo.end();
					 iter++)
				{
					while (g_pConnector[i] != NULL)
					{
						i++;
						if (i >= MAXPROBECONFIGNUM)
						{
							printf("连接超过最大限制,退出!!\n");
							exit(0);
						}
					}

					if (iter->m_sType.compare("sysagent") == 0)
					{
						g_pConnector[i] = new CAgentConnector(
								&g_cReactor,
								false,
								i,
								(char *)(iter->m_sName.c_str()),
								(char *)(iter->m_sLocation.c_str()),
								pEventProcess);
					}
					else
					{
						g_pConnector[i] = new CAgentConnector(
								&g_cReactor,
								true,
								i,
								(char *)(iter->m_sName.c_str()),
								(char *)(iter->m_sLocation.c_str()),
								pEventProcess);
					}

					g_pConnector[i]->RegisterConnecter(
							(char *)(iter->m_sLocation.c_str()));
					i++;
				}
			}

			///2008.09.22 增加一次性全局初始化OraclePass函数
			//InitOraclePass(probeList, pXMLCfg);
			//pXMLCfg->DropAgentProbeCfgList(probeList);
			delete pXMLCfg;
			pXMLCfg = NULL;
		}
	}

	g_cReactor.Create();
	for (i = 0; i < MAXPROBECONFIGNUM; i++)
	{
		if (g_pConnector[i])
		{
			g_pConnector[i]->Start();
		}
	}

	if (g_pAgentServer)
	{
		g_pAgentServer->Start();
	}
	else if (g_pCounterConn)
	{
		g_pCounterConn->Start();
	}

	g_cReactor.Join();
	return 0;
}

/*
list<CXMLConfig::CProbeConfig *> probeList;
list<CXMLConfig::CProbeConfig *>::iterator iter;
if (pXMLCfg->GetAgentProbeCfgList(probeList, pProxyLocation, g_mAgentId))
{
int iLen;
for(i = 0, iter = probeList.begin(); i<MAXPROBECONFIGNUM && iter!=probeList.end(); iter++)
{
iLen = (*iter)->GetLocation() ? strlen((*iter)->GetLocation()) : 0;
if (iLen > 0 && iLen <= MAXLOCATIONLEN)
{
while (g_pConnector[i] != NULL)
{
i++;
if(i>=MAXPROBECONFIGNUM) {
printf("连接超过最大限制,退出!!\n");
exit(0);
}
}
g_pConnector[i] = new CAgentConnector(&reactor,true,i,(*iter)->GetProbeName(), (*iter)->GetLocation(),pEventProcess);
g_pConnector[i]->RegisterConnecter((*iter)->GetLocation());
i++;
}
}
}
list<CAgentConfig> agentList;
list<CAgentConfig>::iterator agentIt;
if (pXMLCfg->GetAgentCfgList(agentList, g_mAgentId))
{
for (agentIt = agentList.begin(); i<MAXPROBECONFIGNUM && agentIt != agentList.end(); agentIt ++)
{
printf("	AgentName:%s	Address:%s\n", (*agentIt).GetAgentName().c_str(), (*agentIt).GetAddress().c_str());
fflush(stdout);
if (agentIt->GetAddress().length()>0)
{
while (g_pConnector[i] != NULL)
{
i++;
if(i>=MAXPROBECONFIGNUM) {
printf("连接超过最大限制,  退出!!!!\n");
exit(0);
}
}
g_pConnector[i] = new CAgentConnector(&reactor,false,i, (char *)agentIt->m_sAgentName.c_str(), (char *)agentIt->m_sAddress.c_str(),pEventProcess);
g_pConnector[i]->RegisterConnecter((char *)agentIt->GetAddress().c_str());
i++;
}
}
}
*/
/*
CRequestInfo *GetOraclePassConf()
{
// 在OraclePass的访问中，需要5个参数，但是我们这里user, dbname在其他的配置文件中，是多个
// 就不再ini文件中进行配置
char szServerIP[128],szEnv[16];
//char szDBName[32],szDBUser[32];
int iPort;

///读取配置文件，获取oraclePass的服务器的配置信息
iPort = GetConfigInt(INI_FILE_NAME, "OrclPassPort");
GetConfigString(INI_FILE_NAME, "OrclPassServerIP",	szServerIP, sizeof(szServerIP));
GetConfigString(INI_FILE_NAME, "OrclPassEnv",		szEnv,		sizeof(szEnv));

//GetConfigString(INI_FILE_NAME, "OrclPassDBName",	szDBName,	sizeof(szDBName));
//GetConfigString(INI_FILE_NAME, "OrclPassDBUser",	szDBUser,	sizeof(szDBUser));

CRequestInfo *dbReqInfo = new CRequestInfo;
dbReqInfo->iPort = iPort;
dbReqInfo->szEnv = szEnv;
dbReqInfo->szServerIP = szServerIP;

//dbReqInfo->szDBName = szDBName;
//dbReqInfo->szDBUser = szDBUser;

return dbReqInfo;
}
//在应用的最外层，对OraclePass涉及的数据进行一次性初始化
//以后使用的时候，直接使用经OraclePass调整好的数据
void InitOraclePass(list<CXMLConfig::CProbeConfig *> &probeList, CXMLConfig *pXMLCfg)
{
///std::map<string, map<string, CDBConnectString> > g_OraclePass;

list<CXMLConfig::CProbeConfig *>::iterator iter;

int iLen;
bool oraConnFail=false;

bool haveChanged=false;

CRequestInfo *dbReqInfo = GetOraclePassConf();
COraclePassClient ora;

for(iter = probeList.begin(); iter!=probeList.end(); iter++)
{
iLen = (*iter)->GetLocation() ? strlen((*iter)->GetLocation()) : 0;
if (iLen > 0 && iLen <= MAXLOCATIONLEN)
{
map<string, CDBConnectString> &orclMap = (*iter)->GetDatabaseMap();
map<string, CDBConnectString>::iterator orclMapIt;

//如果OraclePass 是还没有连接过，或者是连接是成功的
for(orclMapIt = orclMap.begin(); !oraConnFail && orclMapIt != orclMap.end(); orclMapIt++)
{
CDBConnectString reserve = orclMapIt->second;
CDBConnectString &dbConnInfo = orclMapIt->second;
dbReqInfo->szDBName = dbConnInfo.m_sAlias;
dbReqInfo->szDBUser = dbConnInfo.m_sUserName;
///ERR_ConnectError
///OraclePass 服务器连接失败，说明不能建立正确的连接，后续的所有使用OraclePass
///都不需要在进行连接尝试了
if ( 2 == ora.GetOracleAccountInfo(*dbReqInfo,dbConnInfo) )
{
//2008.10.28 commented by wu.yb
//(*iter)->SetDBConnectString(orclMapIt->first.c_str(), &dbConnInfo, (*iter)->GetProbeNode());

oraConnFail = true;
break;
}

if ( reserve != dbConnInfo )
{
//update XML file SystemConfig.xml
haveChanged=true;
(*iter)->SetDBConnectString(orclMapIt->first.c_str(), &dbConnInfo, (*iter)->GetProbeNode());
}
}
g_OraclePass.insert(make_pair((*iter)->GetLocation(),orclMap));
}
}
delete dbReqInfo; dbReqInfo=NULL;

///Save the changes
if ( haveChanged )
{
CXMLDoc *pXMLDoc = pXMLCfg->GetSystemCfgDoc();
CXMLNode *pXMLRootNode = pXMLCfg->GetSystemRootNode();
pXMLRootNode->setNodeType(XMLTag);
pXMLDoc->setRootNode(pXMLRootNode);
pXMLDoc->write(pXMLCfg->m_szSystemConfig);
}
}
*/
