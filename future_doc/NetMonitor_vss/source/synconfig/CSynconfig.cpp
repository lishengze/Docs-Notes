/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSynconfig.h
///@brief	定义了配置服务管理类
///@history
///20110928	李志伟		实现该文件
#include "CSynconfig.h"
#include "ConfigInfo.h"
#include <xmlcfg.h>
#include "Config.h"
#include <public.h>
#include <databaseData.h>
#include <CFilelogService.h>
#include "SessionProxy.h"
#include <CDeployConfig.h>
#include "MemoryDBInitFunc_internal.h"
#include <FTDDataHelper.h>
#include <UFCopy.h>

const char	*INI_FILE_NAME = "synconfig.ini";
CMemoryDB *pMemoryDB;
char g_SysVersion[200] = "";

CLogger *g_pPackOutput;					// TODO
CFileLogger *g_recvPkgLogger = NULL;	// 数据包输出到文件
CBufferLogger *g_bufferLogger = NULL;

//////////////////////////////////////////////////////////////////////////
//add by feng.q 记录t_sysnetmonitordevicetask记录数
int g_nCntOfdevicetask = 0;

//////////////////////////////////////////////////////////////////////////
CSynconfig::CSynconfig(void) :
	m_frontServer(&m_frontReactor),
	m_snmpServer(&m_snmpReactor),
	m_eventServer(&m_eventReactor),
	m_syncServer(&m_syncReactor)
{
	m_dbHandler.SetOperateMaster("CFrontServer",NULL);	
}

bool CSynconfig::Init(int argc, char *argv[])
{
	char id[6];
	SNPRINTF(id, 6, "%d", getStartId(argc, argv));
	ConfigInfo::Instance().InitSynconfigID(id);

	char cfgPath[200];			//保存配置文件路径
	char flowPath[200];			//保存流文件存储路径
	char traceLogPath[200];		//系统运行日志路径
		/// Added by Henchi, 20111215
		/// for msgFile
	char szWarningPath[200];	//保存消息文件存放路径
	char szSystemNum[200];		//保存当前系统消息标识ID
	char szMsgPolicy[200];		//保存消息队列落地的策略串
	GetConfigString(INI_FILE_NAME, "ConfigPath", cfgPath, sizeof(cfgPath));
	GetConfigString(INI_FILE_NAME, "FlowPath", flowPath, sizeof(flowPath));
	GetConfigString(
		INI_FILE_NAME,
		"TraceLogPath",
		traceLogPath,
		sizeof(traceLogPath));
	GetConfigString(
		INI_FILE_NAME,
		"WarningPath",
		szWarningPath,
		sizeof(szWarningPath));
	GetConfigString(
		INI_FILE_NAME,
		"MsgPolicy",
		szMsgPolicy,
		sizeof(szMsgPolicy));
	GetConfigString(
		INI_FILE_NAME,
		"SystemNum",
		szSystemNum,
		sizeof(szSystemNum));
	GetConfigString(
		INI_FILE_NAME,
		"SysVersion",
		g_SysVersion,
		sizeof(g_SysVersion));

#ifdef PACKAGE_OUTPUT
	g_recvPkgLogger = new CFileLogger();

	char FilePath[100];
	sprintf(FilePath, "%s%s", flowPath, "synconfig.log");
	if (!((CFileLogger *)g_recvPkgLogger)->Open(FilePath))
	{
		printf("can't open output file %s\n", FilePath);
		fflush(stdout);
		return false;
	}

	g_bufferLogger = new CBufferLogger();
#endif
	g_traceLog = new CFileLogger();
	if (!g_traceLog->Open(traceLogPath))
	{
		printf(
			"create trace log file failed! path detail (%s)\n",
			traceLogPath);
		fflush(stdout);
		return false;
	}

	LOG_INFO("log file is created!");

	CConfig config(INI_FILE_NAME);
	currentConfig = &config;
	pMemoryDB = new CMemoryDB();
	pMemoryDB->init(currentConfig);

	char *syslogFileName = config.getConfig("SyslogPath");
	CMonitorIndex::init(
			CFilelogService::CreateInstance(argc, argv, syslogFileName),
			&config);

	try
	{
		CDeployConfig cfg;

		cfg.Parse(cfgPath);

		CDeployConfig::SynconfigCfgInfo info = cfg.GetSynconfigCfgInfo(
				ConfigInfo::Instance().synconfigID());

		if (info.m_serverType == CDeployConfig::ST_Invalid)
		{
			throw new CRuntimeError(
					"Invalid Server Type. Check deploy configuration",
					__FILE__,
					__LINE__);
		}

		ConfigInfo::Instance().InitServerType(info.m_serverType);

		ConfigInfo::Instance().InitListenServer(
				info.ServerAddr("sysfront"),
				info.ServerAddr("snmpmanager"),
				info.ServerAddr("syseventcounter"),
				info.ServerAddr("synconfig"));

		CDeployConfig::DBCfgInfo dbInfo = cfg.GetDBCfgInfo(info.m_dc);

		ConfigInfo::Instance().InitDBInfo(
				dbInfo.m_ip,
				dbInfo.m_port,
				dbInfo.m_dbname,
				dbInfo.m_username,
				dbInfo.m_pwd);

		ConfigInfo::Instance().InitParsedDeployCfg(cfg);
	}

	catch(CRuntimeError * e)
	{
		printf("%s\n", e->GetMsg());
		fflush(stdout);
		return false;
	}

	SessionProxy::Instance().Init(
			&m_frontServer,
			&m_snmpServer,
			&m_eventServer,
			&m_syncServer);

	feedUpMemoryDB();

	m_frontServer.Init();
	m_snmpServer.Init();
	m_eventServer.Init(szWarningPath, szMsgPolicy, szSystemNum);
	m_syncServer.Init();

	return true;
}

bool CSynconfig::Start(void)
{
	// 定义主备指标
	CBoolMonitorIndex *pIsMasterIndex = new CBoolMonitorIndex("IsMaster", 20);

	if (ConfigInfo::Instance().isMaster())
	{
		m_frontServer.RegisterListener(
				ConfigInfo::Instance().frontListener().c_str());
		m_frontReactor.Create();

		m_snmpServer.RegisterListener(
				ConfigInfo::Instance().snmpListener().c_str());
		m_snmpReactor.Create();

		m_eventServer.RegisterListener(
				ConfigInfo::Instance().eventListener().c_str());
		m_eventReactor.Create();

		m_syncServer.RegisterListener(
				ConfigInfo::Instance().configListener().c_str());
		m_syncReactor.Create();

		pIsMasterIndex->setValue(true);
	}
	else
	{
		m_syncReactor.Create();
		m_syncServer.RegisterMaster(
				ConfigInfo::Instance().configListener().c_str());
		m_syncServer.Start();

		pIsMasterIndex->setValue(false);
	}

	return true;
}

void CSynconfig::Stop(void)
{
	m_frontReactor.Stop();
	m_snmpReactor.Stop();
	m_eventReactor.Stop();
	m_syncReactor.Stop();
}

bool CSynconfig::Wait(void)
{
	m_frontReactor.Join();
	m_snmpReactor.Join();
	m_eventReactor.Join();
	m_syncReactor.Join();

	delete pMemoryDB;

	return true;
}

static void FUNC_NAME (SysNetMonitorTaskObjectSet)
	(
		SACommand & records,
		void *pGroupID
	)
{
	assert(pGroupID);

	CWriteableSysNetMonitorTaskObjectSet mdbfield;

	mdbfield.DeviceGroup_ID = *(int *)pGroupID;
	mdbfield.Device_ID = records.
	Field("ID")
	.asLong();
	mdbfield.DataCenter = GetCenterFromOID((const char *)records.Field("ObjectID").asString());

	pMemoryDB->m_SysNetMonitorTaskObjectSetFactory->add(&mdbfield, NULL);
}

extern string searchIDFromSysNetDevice(string condition);	// defined in CFrontServer.cpp
extern map<int, taskStatus> g_taskStatus;

static void handleNetMonitorTaskStatusResult(SACommand &records, void *data)
{
	CFTDRspQryNetMonitorTaskStatusResultField field;
	CFtdData obj(
				&field,
				&CFTDRspQryNetMonitorTaskStatusResultField::m_Describe);
	obj.FromDBRecord(records);

	vector<CFTDRspQryNetMonitorTaskStatusResultField> *cb_data =
		(vector<CFTDRspQryNetMonitorTaskStatusResultField> *) data;
	cb_data->push_back(field);
}

static void HandDeviceTaskCntQuery(SACommand &records, void *data)
{
	if (records.FieldCount() > 0)
	{
		g_nCntOfdevicetask = records.Field(1).asLong();
	}
}

bool CSynconfig::feedUpMemoryDB(void)
{
	m_dbHandler.Open(
			ConfigInfo::Instance().DBIp(),
			ConfigInfo::Instance().DBPort(),
			ConfigInfo::Instance().DBName(),
			ConfigInfo::Instance().DBUser(),
			ConfigInfo::Instance().DBPwd());

	SqlGenerator sql;
	int size = ARRAY_LEN(memInitData);
	for (int i = 0; i < size; i++)
	{
		m_dbHandler.SearchRecord(
				sql.SearchAllCmd(memInitData[i].table),
				memInitData[i].initCB,
				NULL);
		m_dbHandler.SearchRecord(
				sql.SearchMaxCmd(memInitData[i].table, "ID"),
				memInitData[i].setIDCB,
				(void *)memInitData[i].table);

		if (i==12)
		{
            CSysNetDevice* memField=pMemoryDB->m_SysNetDeviceFactory->startFindByAll();
			CWriteableSysNetDevice ftdField;
			for (; memField != NULL; memField = (CSysNetDevice *)pMemoryDB->m_SysNetDeviceFactory->findNextByAll())
			{
				CopySysNetDeviceEntity(&ftdField,memField);
				bool dbResult=false;
				bool NeedUpdate=false;
				CDesEncryptAlgorithm despassw;
				despassw.SetPassword("monitor");
				char* cs=new char[257];                
				ftdField.ENPASSWD.getString(cs);
				{
					if (strcmp(cs,""))
					{
						if (!despassw.IsEnOrDe(cs))
						{
							char* miwen=new char[257];
							despassw.Encrypt(cs,miwen);   
							ftdField.ENPASSWD.setValue(miwen);
							NeedUpdate=true;
						}
					}
				}
				ftdField.PASSWD.getString(cs);
				{
					if (strcmp(cs,""))
					{
						if (!despassw.IsEnOrDe(cs))
						{
							char* miwen=new char[257];
							despassw.Encrypt(cs,miwen);
							ftdField.PASSWD.setValue(miwen);
							NeedUpdate=true;
						}
					}
				}
			    if (NeedUpdate)
			    {
				   UPDATE_OBJ_TO_DB(NetDevice, ftdField, "ID", m_dbHandler, dbResult);
				   if (dbResult)
				   {
					   pMemoryDB->m_SysNetDeviceFactory->update(memField, &ftdField);
				   }
			    }
		     }
			 pMemoryDB->m_SysNetDeviceFactory->endFindByAll();
		}
	}

	// 初始化SysNetMonitorTaskObjectSet内存表
	ITERATE_MEMORYDB_BYALL_BEGIN(NetMonitorDeviceGroup)
	{
		string	conditionSql = searchIDFromSysNetDevice(
				pField->Condition.getValue());

		int groupID = pField->ID;
		m_dbHandler.SearchRecord(
				conditionSql,
				FUNC_NAME(SysNetMonitorTaskObjectSet),
				&groupID);
	}

	ITERATE_MEMORYDB_BYALL_END(NetMonitorDeviceGroup)
	//////////////////////////////////////////////////////////////////////////
	//add by feng.q 查询t_sysnetmonitordevicetask记录数
	{
		SACommand cmd;

		cmd.setCommandText(
				"select count(*) AS CNT from t_SysNetMonitorDeviceTask");
		m_dbHandler.SearchRecord(cmd, HandDeviceTaskCntQuery, NULL);

		//		SAConnection con;
		// 		try
		// 		{
		// 			//SACommand cmd(&con);
		// 			con.Connect(
		// 				"172.1.128.117:1521/MDB", "monitor_zj", "monitor_zj", SA_Oracle_Client);
		// 			
		// 			SACommand cmd;
		//
		// 			cmd.setCommandText("select count(*) AS CNT from t_SysNetMonitorDeviceTask");
		// 			cmd.setConnection(&con);
		//
		// 			cmd.Execute();
		// 			
		// 			while(cmd.FetchNext())
		// 			{
		// 				g_nCntOfdevicetask = cmd.Field("CNT").asShort();
		// 			}
		// 		}
		// 		catch (SAException& ex)
		// 		{
		// 			LOG_ERROR("SearchRecord raise exception: (%s)\n", (const char*)ex.ErrText());
		// 		}
	}

	//////////////////////////////////////////////////////////////////////////
	
	
	    //// 初始化当天任务结果信息
	//SACommand cmd;
	//cmd.setCommandText("select * from t_SysNetMonitorTaskResult where MonDate= :1");
	//cmd << NowDate.getValue();
	//vector<CFTDRspQryNetMonitorTaskStatusResultField> task_status_results;
	//dbHandler.SearchRecord(cmd, handleNetMonitorTaskStatusResult, &task_status_results);
	//for (int i=0; i<task_status_results.size(); i++)
	//{
	//    CFTDRspQryNetMonitorTaskStatusResultField tfield = task_status_results[i];
	//    map<int ,taskStatus>::iterator it =g_taskStatus.find(tfield.Task_ID);
	//    if(it !=g_taskStatus.end())
	//    {
	//        it->second.times =tfield.OperateTime;
	//    }
	//    else
	//    {
	//        taskStatus ts;
	//        ts.status =-1;
	//        ts.delay =-1;
	//        ts.times =tfield.OperateTime;
	//        g_taskStatus[tfield.Task_ID] =ts;
	//    }
	//}
	return true;
}
