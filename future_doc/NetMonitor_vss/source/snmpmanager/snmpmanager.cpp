/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	netmanager.cpp
///@brief	采集代理的main主函数实现
///@history
///20100908	周建军		创建该文件
/////////////////////////////////////////////////////////////////////////
#include "version.h"
#include "public.h"
#include "Config.h"
#include "CConfig.h"
#include "CFilelogService.h"
#include "xmlcfg.h"

#include "ping_common.h"
#include "CSnmpManager.h"
#include "CSysLogReader.h"
#include "CSysLogConfig.h"
#include "CDeployConfig.h"
#include "CTelnetClient.h"

const char	*INI_FILE_NAME = "snmpmanager.ini";
const char	*SYSLOG_CFG_NAME = "snmpmanager.xml";
const char	*REGEX_CFG_NAME = "snmpmanager.regex";
const char	*APP_NAME = "snmpmanager";
char g_mCfgPath[100];						//部署文件存储路径
char g_mFlowPath[100];						//保存流文件存储路径
char g_mMibsPath[100];						//mib文件存储路径
char g_mTrapLogPath[100];					//Trap日志文件路径
char g_mSysLogPath[100];					//Syslogd日志文件路径
char g_mCommunity[100];						//Community 关键字
char g_mDevDomain[100];						//设备域名
char g_mManagerLocation[100];				//服务器监听端口
char g_mSynLocation[100];					//配置管理服务的连接串
char g_msysNetArea;							//服务器地理位置
int g_nstartSeq = 0;						//服务进程的启动编号
int g_nSnmpGetThreadNum = 0;				//启动的snmp采集线程数量
map<string, int> g_mapDeviceNo;				// 保存设备信息及其数组内偏移位置
int g_nDeviceNo = 0;						// 保存当前设置计数
CTelnetDevice g_Devices[MAX_DEVICE_NUM];	// 保存设备配置信息的数组
CSysLogReader *g_pSyslogReader = NULL;		//Syslog解析线程指针

//string g_eventlevelips = "snmpmanager.eventlevel_iplist";
CCheckConnThread *g_pCheckConn = NULL;

map<string, list<string> >	g_mapDeviceCMDS;
//map<string, list<string> >  g_mapDeviceIfs; //<ip, ifs> //2013 06.17 by Lee

char g_mSSHDefaultUsrName[100];
char g_mSSHDefaultPasswd[100];
char g_mSSHDefaultAdminPasswd[100];

//typedef enum {UNINIT=0, MASTER, SLAVE} MANAGERROLE;
bool g_isMasterRole;

#ifdef PACKAGE_OUTPUT
CLogger *g_pPackOutput = NULL;				// 数据包输出到文件
#endif
extern bool UseNetCompressLog;				// 报文压缩信息输出开关

///@param	startSeq	本进程的启动编号
void globalEnvInit(char *startSeq)
{
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
	GetConfigString(
		INI_FILE_NAME,
		"TrapLog",
		g_mTrapLogPath,
		sizeof(g_mTrapLogPath));
	GetConfigString(
		INI_FILE_NAME,
		"SysLog",
		g_mSysLogPath,
		sizeof(g_mSysLogPath));
	GetConfigString(
		INI_FILE_NAME,
		"Community",
		g_mCommunity,
		sizeof(g_mCommunity));
	GetConfigString(
		INI_FILE_NAME,
		"DevDomain",
		g_mDevDomain,
		sizeof(g_mDevDomain));
	g_nSnmpGetThreadNum = MAX(
			GetConfigInt(INI_FILE_NAME, "SnmpGetThreadNum"),
			1);
	GetConfigString(
		INI_FILE_NAME,
		"MibsPath",
		g_mMibsPath,
		sizeof(g_mMibsPath));				//"..\\..\\config\\snmp\\mibs"

	//wei.c add,默认的ssh登录信息
	GetConfigString(
		INI_FILE_NAME,
		"SSHUsrName",
		g_mSSHDefaultUsrName,
		sizeof(g_mSSHDefaultUsrName));
	GetConfigString(
		INI_FILE_NAME,
		"SSHPasswd",
		g_mSSHDefaultPasswd,
		sizeof(g_mSSHDefaultPasswd));
	GetConfigString(
		INI_FILE_NAME,
		"SSHAdminPasswd",
		g_mSSHDefaultAdminPasswd,
		sizeof(g_mSSHDefaultAdminPasswd));

	if (startSeq != NULL)
	{
		g_nstartSeq = atoi(startSeq);
	}

#ifdef WIN32
	strcpy(g_mMibsPath, "..\\..\\config\\snmp\\mibs");
#endif
#ifdef PACKAGE_OUTPUT
	g_pPackOutput = new CFileLogger();

	char FilePath[100];
	sprintf(FilePath, "%s%s", g_mFlowPath, "synconfig_datastream_package.log");
	if (!((CFileLogger *)g_pPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

#endif

	//CXMLConfig *pXMLCfg = new CXMLConfig(g_mCfgPath);
	//if ( pXMLCfg != NULL)
	//{
	//	pXMLCfg->GetServiceLocation(g_mManagerLocation, "snmpmanager", XML_PROP_ITEM, startSeq);
	//	pXMLCfg->GetServiceLocation(g_mSynLocation, "synconfig", XML_PROP_TYPE, "snmpmanager");
	//	delete pXMLCfg;
	//	pXMLCfg = NULL;
	//}
	//xml文档结构变更
	CDeployConfig *pXMLCfg = new CDeployConfig();
	if (pXMLCfg != NULL)
	{
		pXMLCfg->Parse(g_mCfgPath);

		CDeployConfig::SnmpCfgInfo	cfg = pXMLCfg->GetSnmpCfgInfo(startSeq);

		strcpy(g_mManagerLocation, cfg.ServerAddr("syseventcounter").c_str());
		strcpy(g_mSynLocation, cfg.ServerAddr("synconfig").c_str());

		g_msysNetArea = cfg.m_dc.getValue();

		delete pXMLCfg;
		pXMLCfg = NULL;
	}

	printf("manager initial role is:[UNKNOW]\n");
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
	getStartId(argc, argv);					// Mod by henchi, 20090430
#endif
	globalEnvInit(argv[1]);

	///载入配置并开始输出Syslog:
	SysReactor	reactor;
	CConfig *pConfig = new CConfig(INI_FILE_NAME);
	char *syslogFileName = pConfig->getConfig("SyslogPath");
	CMonitorIndex::init(
			CFilelogService::CreateInstance(argc, argv, syslogFileName),
			pConfig);
	delete pConfig;

	// 关闭报文压缩输出信息
	UseNetCompressLog = false;
	// add by cao.ning
	// 加载复合指标信息
	CMonDevice::InitCompoundAttrs((char*)SYSLOG_CFG_NAME);

	//加载syslog过滤信息的配置文件
	if (CSysLogConfigManager::Instance()->LoadConfig(SYSLOG_CFG_NAME) != 0)
	{
		printf("LoadConfig faile for %s\n", SYSLOG_CFG_NAME);
		return 0;
	}

	CSysLogConfigManager::Instance()->DumpConfig();

	CSnmpManagerServer	myServer(
							&reactor,
							g_nSnmpGetThreadNum,
							g_mMibsPath,
							g_mFlowPath,
							atoi(argv[1]),
							g_mManagerLocation);

	g_pSyslogReader = new CSysLogReader(g_mSysLogPath);
	g_pCheckConn = new CCheckConnThread();
	g_pCheckConn->Create();

	//加载事件级别变更ip列表
	//if( g_pSyslogReader->LoadConfig() == 0 )
	//{
	//	printf("warning:LoadConfig fail for %s.\n",g_eventlevelips.c_str());
	//}
	//接受完配置信息再启动
	//g_pSyslogReader->Create();
	//telnet 初始化
	CTelnetClient::TelnetGlobalInit();

	myServer.RegisterListener(g_mManagerLocation);
	myServer.RegisterSynConnecter(g_mSynLocation);
	reactor.Create();
	myServer.StartAll();
	reactor.Join();

	CTelnetClient::TelnetGlobalFinish();
#if 0
	unsigned long start;

	unsigned long val;
	getip(start, val, argv[1], argv[2]);

	//printf("%u %u \n", argv[1], argv[2]);
	//printf("start %u val %u\n", start,val);
	for (int tmp = val; tmp >= 0; tmp--)
	{
		//CPing tmp(3,
		struct in_addr	addr;
		addr.s_addr = ntohl(start + tmp);
		printf("ip [%s] %u\n", inet_ntoa(addr), start + tmp);

		CPing ping(3, inet_ntoa(addr));
		ping.run();
	}

	return 0;
#endif
}
