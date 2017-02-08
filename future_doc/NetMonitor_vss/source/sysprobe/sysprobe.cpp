/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	sysprobe.cpp
///@brief	探针的main主函数实现
///@history
///20080508	周建军		创建该文件
///20080623	周建军		修订注释
///20090430	晏鹤春		添加程序启动标识的校验
/////////////////////////////////////////////////////////////////////////
#include "public.h"
#include "Config.h"
#include "CConfig.h"
#include "CFilelogService.h"
#include "SelectReactor.h"
#include "SessionFactory.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "ProbeServer.h"
#include "version.h"
#include "md5Handler.h"
#include "FileCheck.h"
#include "SANCaptureThread.h"
#include "CSysInternalTopology.h"

#include <iostream>
CCachedFileFlow *g_pFlow = NULL;

map<string, int> mapMonth;
map<int, string> mapMonthStr;

///@key	业务系统ID编号
///@value	业务系统名称
map<string, string> g_mapSysID;

int g_nTimeZoneSec = 0;								//换算成秒的时差
int g_mFileSegSize = 8;
char pProbeLocation[100] = "tcp://127.0.0.1:9200";
char g_mFlowPath[100];								//保存流文件存储路径
char g_mSavePacketNumFile[200];						//保存索引文件存储路径名
char *g_pPositionFile = g_mSavePacketNumFile;
char g_mTradeDay[9];

const char	*INI_FILE_NAME = "sysprobe.ini";
const char	*XML_FILE_NAME = "sysprobe.xml";
const char	*APP_NAME = "sysprobe";
char g_pHostName[32];								// 保存主机名称
char g_pDataCenterName[32];							// 保存数据中心名称，如TRADE.PuDian
char g_pCenterName[32];								// 保存纯数据中心名称，如PuDian或ZhangJ

//char *g_pDataCenterName = NULL;                // 保存数据中心名称
#ifdef PACKAGE_OUTPUT
CLogger *g_pPackOutput = NULL;						// 数据包输出到文件
#endif
extern bool UseNetCompressLog;						// 报文压缩信息输出开关

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
	printf("Sysprobe Start Running !!! %s ", ctime(&timep));
	fflush(stdout);

	// Mod by Henchi, 20100121
	// 修正时区偏移可能造成的日期偏移歧义
	g_nTimeZoneSec = getTimeZoneOffset();

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

	mapMonthStr[1] = string("Jan");
	mapMonthStr[2] = string("Feb");
	mapMonthStr[3] = string("Mar");
	mapMonthStr[4] = string("Apr");
	mapMonthStr[5] = string("May");
	mapMonthStr[6] = string("Jun");
	mapMonthStr[7] = string("Jul");
	mapMonthStr[8] = string("Aug");
	mapMonthStr[9] = string("Sep");
	mapMonthStr[10] = string("Oct");
	mapMonthStr[11] = string("Nov");
	mapMonthStr[12] = string("Dec");

	memset(g_pDataCenterName, 0, 32);
	memset(g_pCenterName, 0, 32);
	if (gethostname(g_pHostName, 31) != 0)
	{
		memset(g_pHostName, 0, 32);
	}
	else
	{
		char *p;
		while ((p = strchr(g_pHostName, '.')))
		{											// Mod by Henchi, 20090423
			*p = '_';
		}
	}

	GetConfigString(
		INI_FILE_NAME,
		"FileSegSize",
		pProbeLocation,
		sizeof(pProbeLocation));
	if (atoi(pProbeLocation) > 0)
	{
		g_mFileSegSize = atoi(pProbeLocation);
	}

	GetConfigString(
		INI_FILE_NAME,
		"ProbeLocation",
		pProbeLocation,
		sizeof(pProbeLocation));
	GetConfigString(
		INI_FILE_NAME,
		"FlowPath",
		g_mFlowPath,
		sizeof(g_mFlowPath));
	sprintf(g_mSavePacketNumFile, "%s%s", g_mFlowPath, "probeflow.txt");

	// Added by Henchi, 20120320
	// 系统ID标识信息由sysprobe.xml文件中读取
	CXMLDoc xmlConfig;

	try
	{
		xmlConfig.read((char *)XML_FILE_NAME);

		CXMLNode *pRoot = xmlConfig.getRootNode();
		CXMLNode *pSystemNode = pRoot->findNode(
				XMLTag,
				XML_TAG_SYSTEM,
				NULL,
				NULL);
		CXMLNodeList *pNodeList = pSystemNode->getNodeList();
		CXMLNodeList::iterator	pos;
		for (pos = pNodeList->begin(); pos != pNodeList->end(); ++pos)
		{
			CXMLNode *pNode = *pos;
			char *pID = pNode->findProperty(XML_PROP_ID);
			char *pName = pNode->findProperty(XML_PROP_NAME);
			if (pID != NULL && pName != NULL)
			{
				printf("ID [%s]  SYS [%s]\n", pID, pName);
				g_mapSysID[pID] = pName;
			}
		}
	}

	catch(CParseError * pParseError)
	{
		printf(
			"\nline=%d, error:%s\n",
			pParseError->getLineNo(),
			pParseError->getMsg());
		printf("Failed to read configuration file %s, quit.\n", XML_FILE_NAME);
		exit(-1);
	}

#if 0
	char idBuffer[512];

	char *p;

	char *q;

	char *r;
	memset(idBuffer, 0, 512);

	GetConfigString(INI_FILE_NAME, "SYSID", idBuffer, sizeof(idBuffer));
	p = idBuffer + strlen(idBuffer);
	*p = ',';
	p++;

	GetConfigString(
		INI_FILE_NAME,
		"SYSID1",
		p,
		sizeof(idBuffer) - strlen(idBuffer));
	p = idBuffer + strlen(idBuffer);
	*p = ',';
	p++;
	GetConfigString(
		INI_FILE_NAME,
		"SYSID2",
		p,
		sizeof(idBuffer) - strlen(idBuffer));

	cout << "业务系统ID定义 [" << idBuffer << "]" << endl;

	p = idBuffer;
	while (NULL != p)
	{
		q = strchr(p, ',');
		if (NULL == q)
		{
			r = strchr(p, ':');
			if (NULL == r)
			{
				break;
			}
			else
			{
				*r = '\0';
				r++;
				g_mapSysID[r] = p;
			}

			break;
		}
		else
		{
			*q = '\0';
			r = strchr(p, ':');
			if (NULL == r)
			{
				printf("SYSID配置不符合定义的格式\n");
				fflush(stdout);
				exit(0);
			}
			else
			{
				*r = '\0';
				r++;
				g_mapSysID[r] = p;
			}

			q++;
			p = q;
		}
	}

#endif
#ifdef WIN32
	{
		HANDLE	hToken;
		LUID uID;
		TOKEN_PRIVILEGES tp;
		OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken);
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &uID);

		tp.PrivilegeCount = 1;
		tp.Privileges[0].Luid = uID;
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
		CloseHandle(hToken);
	}

#endif
#ifdef PACKAGE_OUTPUT
	g_pPackOutput = new CFileLogger();

	char FilePath[100];
	sprintf(FilePath, "%s%s", g_mFlowPath, "probepackage.log");
	if (!((CFileLogger *)g_pPackOutput)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		exit(0);
	}

#endif
}

//void test1();
#ifdef LINUX
extern CFileCheckThread *g_pFileCheckThread;		// 文件校验线程指针
void testFileCheck(void)
{
	if (NULL == g_pFileCheckThread)
	{
		g_pFileCheckThread = new CFileCheckThread();
		g_pFileCheckThread->Create();
	}

	g_pFileCheckThread->UpdateCheckConfig(
			"/home/zjj/html",
			"/home/zjj/hash",
			"08:00:00-20:00:00.20");
}

#endif
int main(int argc, char *argv[])
{
#ifdef UNIX
	signal(SIGABRT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);

	//	signal(SIGINT, SIG_IGN);
#endif
	showVersion(argc, argv);
#ifndef WIN32
	getStartId(argc, argv);							// Mod by henchi, 20090430
#endif
	globalEnvInit();

	//test1();
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
		g_SysInternalTopology = new CSysInternalTopology(APP_NAME, iStartID);
	}
	delete pConfig;

	// 关闭报文压缩输出信息
	UseNetCompressLog = false;

	CProbeReactor reactor;
	CProbeServer myServer(&reactor);
	myServer.RegisterListener(pProbeLocation);
	reactor.Create();
	myServer.Start();
	reactor.Join();

	return 0;
}

#ifdef WIN32
extern CFileCheckThread *g_pFileCheckThread;		// 文件校验线程指针
extern CSANCaptureThread *g_pSANCaptureThread;		// 读取SAN线程指针
extern COperatorSystemSpiImpl *g_pHostSpi;			// 主机采集spi实例的指针
void test1(void)
{
#if 0
	g_pHostSpi = new COperatorSystemSpiImpl(NULL);
	g_pHostSpi->GetProcessInfo();
	return;
	if (g_pSANCaptureThread == NULL)
	{
		g_pSANCaptureThread = new CSANCaptureThread(
				"",
				"test",
				"00:00:00-23:59:00.240");
		g_pSANCaptureThread->Create();
	}

	g_pSANCaptureThread->GetSpi();
	return;
	if (g_pFileCheckThread == NULL)
	{
		g_pFileCheckThread = new CFileCheckThread();
		g_pFileCheckThread->Create();
	}

	g_pFileCheckThread->UpdateCheckConfig(
			"/home/zjj/html",
			"/home/zjj/hash",
			"00:00:00-23:59:00.240");

	map<string, string> map1;
	map1["temp"] = "temp";
	map1["string"] = "string";

	map<string, string> map2 = map1;
	map2["test"] = "test";

	if (GenMD5File("d:\\log2\\index.html", "d:\\log2\\index.html.MD5") == 0)
	{
		printf("success\n");
	}

#endif

	map<string, CDataBaseAttr>	m_logmap;
	m_logmap["table1"] = CDataBaseAttr(
			"dns1",
			"instance",
			"10:00:00-12:00:00.5");
	m_logmap["table1"].m_sOpDate = "20090802";
	m_logmap["table1"].m_sOpTime = "12:12:12";
	m_logmap["table1"].m_nLogId = 10;

	m_logmap["table1"] = CDataBaseAttr(
			"dns1",
			"instance",
			"10:00:00-12:00:00.5");

	SAConnection con;
	try
	{
		//SACommand cmd(&con);
		SACommand cmd(&con, "monitor.dbmonitorpkg.getCPUUsageProc");

		con.Connect(
				"172.16.94.91:1521/SDB",
				"monitor",
				"monitor",
				SA_Oracle_Client);
		std::cout << "Connected OK!" << "\n";

		cmd.Execute();

		SACommand *pRefCursor = cmd.Param("MONCURSOR");
		CFTDRtnObjectAttrField	m_ObjAttrInfo;
		while (pRefCursor->FetchNext())
		{
			//m_ObjAttrInfo.AttrType= (const char *)cmd.Param("OBJECTNAME").asString();
			//m_ObjAttrInfo.AttrValue = (const char *)cmd.Param("OBJECTVAL").asString();
			m_ObjAttrInfo.AttrType = (const char *)pRefCursor->Field(1).asString();
			m_ObjAttrInfo.AttrType.trimRight();

			char *p = strchr((char *)m_ObjAttrInfo.AttrType.getValue(), ' ');
			while (p != NULL)
			{
				*p = '_';
				p++;
				p = strchr(p, ' ');
			}

			p = strchr((char *)m_ObjAttrInfo.AttrType.getValue(), '.');
			while (p != NULL)
			{
				*p = '_';
				p++;
				p = strchr(p, '.');
			}

			m_ObjAttrInfo.AttrValue = (const char *)pRefCursor->Field(
					2).asString();
			m_ObjAttrInfo.AttrValue.trimRight();

			//m_attrInfo.push_back(m_ObjAttrInfo);
		}

		return;

		cmd.setCommandText(
				"select logid,opdate,optime,spname,objectname,objectval from t_syslog");
		cmd.Execute();
		while (cmd.FetchNext())
		{
			cout << "== " << cmd.Field(1).asNumeric() << " ## ";
			cout << "==" << (const char *)cmd.Field(2).asString() << " ## ";
			cout << "==" << (const char *)cmd.Field(3).asString() << " ## ";
			cout << "==" << (const char *)cmd.Field(4).asString() << " ## ";
			cout << "==" << (const char *)cmd.Field(5).asString() << " ## ";
			cout <<
				"==" <<
				(const char *)cmd.Field(6).asString() <<
				" ## " <<
				endl;

			//cout<<"== "<<cmd.Field("LOGID").asNumeric()<<" ## ";
			//cout<<"=="<<(const char *)cmd.Field("opdate").asString()<<" ## ";
			//cout<<"=="<<(const char *)cmd.Field("optime").asString()<<" ## ";
			//cout<<"=="<<(const char *)cmd.Field("spname").asString()<<" ## ";
			//cout<<"=="<<(const char *)cmd.Field("objectname").asString()<<" ## ";
			//cout<<"=="<<(const char *)cmd.Field("objectval").asString()<<" ## "<<endl;
		}

		return;

		cmd.setCommandText("dbmonitorpkg.getdatafileproc");
		cmd.Execute();
		cout << "==" << cmd.Param("RETCODE").asLong() << "==" << endl;
		cout <<
			"==" <<
			(const char *)cmd.Param("RETMSG").asString() <<
			"==" <<
			endl;
		pRefCursor = cmd.Param("MONCURSOR");
		cout << pRefCursor->FieldCount() << endl;

		char buffer[3000];

		char colbuf[3000];

		char *q;

		char *p;
		CFTDRtnDBQueryField fieldQuery;
		int i;
		for (i = 1; i <= pRefCursor->FieldCount(); i++)
		{
			if (i == 1)
			{
				strcpy(colbuf, (const char *)pRefCursor->Field(i).Name());
			}
			else
			{
				sprintf(
					colbuf,
					"%s%s%s",
					colbuf,
					DBSEPARATORSTRING,
					(const char *)pRefCursor->Field(i).Name());
			}
		}

		strcat(colbuf, DBSEPARATORRECORD);
		q = p = (char *)fieldQuery.DBQueryResult.getValue();
		strcpy(p, colbuf);
		p = p + strlen(colbuf);

		while (pRefCursor->FetchNext())
		{
			for (i = 1; i <= pRefCursor->FieldCount(); i++)
			{
				if (i == 1)
				{
					strcpy(
						buffer,
						(const char *)pRefCursor->Field(i).asString());
				}
				else
				{
					sprintf(
						buffer,
						"%s%s%s",
						buffer,
						DBSEPARATORSTRING,
						(const char *)pRefCursor->Field(i).asString());
				}
			}

			strcat(buffer, DBSEPARATORRECORD);
			if ((p + strlen(buffer) - q) >= 3500)	//当前数据包已经填满数据，先放到队列，然后重新开始填充
			{
				cout << q << endl;
				p = q;
				strcpy(p, colbuf);
				p = p + strlen(colbuf);
				strcpy(p, buffer);
				p = p + strlen(buffer);
			}
			else
			{
				strcpy(p, buffer);
				p = p + strlen(buffer);
			}
		}

		std::cout << "Ref cursor fetched OK!" << "\n";
		cout << q << endl;
		return;

		cmd.setCommandText("dbmonitorpkg.getinstancenameproc");
		cmd.Execute();
		std::cout << "Stored procedure executed OK!" << "\n";

		cout << "==" << cmd.Param("RETCODE").asLong() << "==" << endl;
		cout <<
			"==" <<
			(const char *)cmd.Param("RETMSG").asString() <<
			"==" <<
			endl;

		//SACommand *pRefCursor = cmd.Param("REFCURSOR");
		pRefCursor = cmd.Param("MONCURSOR");
		std::cout << pRefCursor->FieldCount() << endl;
		while (pRefCursor->FetchNext())
		{
			std::cout << pRefCursor->FieldCount() << endl;
			std::cout << (const char *)pRefCursor->Field(1).Name() << "=" << (const char *)pRefCursor->Field(1).asString() << "\n";
			std::cout << (const char *)pRefCursor->Field(2).Name() << "=" << (const char *)pRefCursor->Field(2).asString() << "\n";
		}

		std::cout << "Ref cursor fetched OK!" << "\n";
	}

	catch(SAException & x)
	{
		// SAConnection::Rollback()
		// can also throw an exception
		// (if a network error for example),
		// we will be ready
		try
		{
			// on error rollback changes
			con.Rollback();
		}

		catch (SAException &)
		{
		}

		// print error message
		std::cout << (const char *)x.ErrText() << "\n";
	}
}

#endif
