/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	sysagent.cpp
///@brief	�ɼ������main������ʵ��
///@history
///20080508	�ܽ���		�������ļ�
///20080623	�ܽ���		�޶�ע��
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
char g_mCfgPath[200];					//���������ļ�·��
CObjectIdSession g_mObjectIdSession;	//���浱ǰ���е�ObjectID��������session��Ϣ
COraclePassClient g_mOraclePassClient;	//���ڱ��浱ǰ����BNS������IP���˿���Ϣ
map<string, CRequstDBConnectInfo> g_mapDBConnectInfo;	//���ڱ������ݿ�����������������Ϣ�ṹ��ӳ��
map<string, map<string, CDBConnectString> > g_OraclePass;
map<string, int> mapMonth;

///��̽�����¼������������������������RID�б�
CManageReqIDSession g_cProbeToEventReq;

///���¼�������������̽�뷢�����������RID�б�
CManageReqIDSession g_cEventToProbeReq;

#ifdef PACKAGE_OUTPUT
char g_mFlowPath[200];						//�������ļ��洢·��
CLogger *g_pPackOutput = NULL;				// ���ݰ�������ļ�
#endif
extern bool UseNetCompressLog;				// ����ѹ����Ϣ�������

// add by cao.ning
// ϵͳ�ڲ���������
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
				/// ����BNS��֤ʱ��������������Ϣ����ʱ������BNS��֤������ֱ�Ӳ���������
		if (!connectInfo.m_ConnectInfo.IsValid())
		{
			g_mOraclePassClient.GetOracleAccountInfo(
					connectInfo.m_RequestInfo,
					connectInfo.m_ConnectInfo);
		}

		/// ����������Ч������ͨ��BNS�ɹ���ȡ������ʱ����������Ϣ����ȫ��Map
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
		g_SysInternalTopology = new CSysInternalTopology(APP_NAME, g_mAgentId);
	}

	delete pConfig;

	// �رձ���ѹ�������Ϣ
	UseNetCompressLog = false;

	int i = 0;
	for (i = 0; i < MAXPROBECONFIGNUM; i++)
	{
		g_pConnector[i] = NULL;
	}

	memset(pCounterLocation, 0x00, sizeof(pCounterLocation));

	if (g_bProxyFlag)						///�����Ͳɼ�����
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

			// Added by Henchi, 20100329	��ʼ��BNS�б�
			list<CBNSInfo>	listBNS;
			list<CDBConnectString>	listDBConnect;

			//// Mod by Henchi, 20100527
						//// BNS��������Ǳ�Ҫ����
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
							printf("���ӳ����������,�˳�!!\n");
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

			///2008.09.22 ����һ����ȫ�ֳ�ʼ��OraclePass����
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
printf("���ӳ����������,�˳�!!\n");
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
printf("���ӳ����������,  �˳�!!!!\n");
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
// ��OraclePass�ķ����У���Ҫ5��������������������user, dbname�������������ļ��У��Ƕ��
// �Ͳ���ini�ļ��н�������
char szServerIP[128],szEnv[16];
//char szDBName[32],szDBUser[32];
int iPort;

///��ȡ�����ļ�����ȡoraclePass�ķ�������������Ϣ
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
//��Ӧ�õ�����㣬��OraclePass�漰�����ݽ���һ���Գ�ʼ��
//�Ժ�ʹ�õ�ʱ��ֱ��ʹ�þ�OraclePass�����õ�����
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

//���OraclePass �ǻ�û�����ӹ��������������ǳɹ���
for(orclMapIt = orclMap.begin(); !oraConnFail && orclMapIt != orclMap.end(); orclMapIt++)
{
CDBConnectString reserve = orclMapIt->second;
CDBConnectString &dbConnInfo = orclMapIt->second;
dbReqInfo->szDBName = dbConnInfo.m_sAlias;
dbReqInfo->szDBUser = dbConnInfo.m_sUserName;
///ERR_ConnectError
///OraclePass ����������ʧ�ܣ�˵�����ܽ�����ȷ�����ӣ�����������ʹ��OraclePass
///������Ҫ�ڽ������ӳ�����
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
