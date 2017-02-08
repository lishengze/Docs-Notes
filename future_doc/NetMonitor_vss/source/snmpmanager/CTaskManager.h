/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CTaskManager.h
///@brief	实现了任务管理类
///@history
///20110718	晏鹤春	创建该文件
#ifndef REF_CTASKMANAGER_H
#define REF_CTASKMANAGER_H

#include <map>
#include <list>

#include "public.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"
#include "systools.h"
#include "CTimePolicy.h"

using namespace std;

#define FLAG_TIMEPOLICY		1
#define FLAG_DEVICEGROUP	2
#define FLAG_ACTIONGRUOP	4

#define FLAG_ELEMENT_EMPTY	0
#define FLAG_ELEMENT_FULL	FLAG_TIMEPOLICY | FLAG_DEVICEGROUP | FLAG_ACTIONGRUOP

enum TASK_TYPE
{
	TASK_TYPE_CONN, //指令任务
	TASK_TYPE_SNMP, //指标任务
};

//@int key=id，对应实例的ID索引号,@CFTDSysNetDeviceField value=实例
typedef std::map<int, CFTDSysNetDeviceField> MAP_DEVICE;
typedef MAP_DEVICE::iterator MAP_DEVICE_IT;

//@int key=id，对应实例的ID索引号,@CFTDSysNetMonitorDeviceGroupField value=实例
typedef std::map<int, CFTDSysNetMonitorDeviceGroupField> MAP_DEVICEGROUP;
typedef MAP_DEVICEGROUP::iterator MAP_DEVICEGROUP_IT;

typedef list<int> LIST_ID;
typedef LIST_ID::iterator LIST_ID_IT;

//@int key=id，设备分组ID标识,@list <int> value=设备对象ID列表
typedef std::map<int, LIST_ID> MAP_DEVICEGROUPLIST;
typedef MAP_DEVICEGROUPLIST::iterator MAP_DEVICEGROUPLIST_IT;

typedef std::map<int, LIST_ID> MAP_POLICYTASKLIST;
typedef MAP_POLICYTASKLIST::iterator MAP_POLICYTASKLIST_IT;

//@int key=id，对应实例的ID索引号,@CFTDSysNetTimePolicyField value=实例
typedef std::map<int, CFTDSysNetTimePolicyField> MAP_TIMEPOLICY;
typedef MAP_TIMEPOLICY::iterator MAP_TIMEPOLICY_IT;

//@int key=id，对应实例的ID索引号,@CFTDSysNetTimePolicyField value=实例
typedef std::map<int, CTimePolicy> MAP_TIMEPOLICYENTITY;
typedef MAP_TIMEPOLICYENTITY::iterator MAP_TIMEPOLICYENTITY_IT;

//@int key=id，对应实例的ID索引号,@CFTDSysNetMonitorActionGroupField value=实例
typedef std::map<int, CFTDSysNetMonitorActionGroupField> MAP_ACTIONGROUP;
typedef MAP_ACTIONGROUP::iterator MAP_ACTIONGROUP_IT;

//@int key=id，对应实例的ID索引号,@CFTDSysNetMonitorCommandTypeField value=实例
typedef std::map<int, CFTDSysNetMonitorCommandTypeField> MAP_COMMAND;
typedef MAP_COMMAND::iterator MAP_COMMAND_IT;

//@string key=设备特征串，由设备厂商\动作族等标识的特征串,@string value=指令串
typedef std::map<string, string> MAP_COMMANDSTRING;
typedef MAP_COMMANDSTRING::iterator MAP_COMMANDSTRING_IT;

//@string key=动作ID，@string value=指标集合
typedef std::map<int, vector<std::string> > MAP_ACTIONATTR;
typedef MAP_ACTIONATTR::iterator MAP_ACTIONATTR_IT;

//@int key=id，对应实例的ID索引号,@CFTDSysNetMonitorTaskInfoField value=实例
typedef std::map<int, CFTDSysNetMonitorTaskInfoField> MAP_TASK;
typedef MAP_TASK::iterator MAP_TASK_IT;

//@<string，string> key=<ip,cmd>,设备ip 指令id组， @CFTDSysNetMonitorDeviceTaskField value=实例
typedef std::map<pair<string, string> , CFTDSysNetMonitorDeviceTaskField>
	MAP_DEV_TASK;
typedef MAP_DEV_TASK::iterator MAP_DEV_TASK_IT;

//
typedef std::map<int, CFTDSysNetMonitorTaskInstAttrsField> MAP_INSTRU_INFO;
typedef MAP_INSTRU_INFO::iterator MAP_INSTRU_INFO_IT;

// 基线比对任务表
typedef std::map<int, CFTDSysNetBaseLineTaskField> MAP_BASELINETASK;
typedef MAP_BASELINETASK::iterator MAP_BASELINETASK_ITERATOR;

// Ping的阀值
//@<string，string> key=<Str_Ip, Des_Ip>,源设备ip 目的设备IP， @int value=阀值
typedef map<pair<string, string>, int> MAP_PINGTHRESHOLD;
typedef MAP_PINGTHRESHOLD::iterator MAP_PINGTHRESHOLD_IT;

enum TASK_STATUS
{
	//任务执行结果
	TASK_SUCCESS								= 0,	//指令执行成功
	TASK_CONNECT_FAIL,			//服务器连接失败
	TASK_USERNAME_ERROR,		//用户名错误
	TASK_USERPASSWD_ERROR,		//用户密码错误
	TASK_USERCOMMAND_FAIL,		//用户命令执行失败
	TASK_ADMINPASSWD_ERROR,		//管理员密码错误
	TASK_ADMINCOMMAND_ERROR,	//管理员命令执行失败
	TASK_OTHER_ERROR,			//其他错误

	//配置文件备份结果
	TASK_CFGBACKUP_SUCCESS,		//配置备份成功
	TASK_CFGBACKUP_FAIL,		//配置备份失败

	//配置文件比对结果
	TASK_CONFIG_MATCH,			//配置文件比对一致
	TASK_CONFIG_DISMATCH,		//配置文件比对不一致

	//任务结果异常
	TASK_RESULT_ERROR							= 12,

	//任务状态通知，由manager发起
	TASK_WAIT_EXEC								= 21,	//任务状态:等待执行
	TASK_CANCEL_EXEC,						//任务状态:取消执行
	TASK_DOING_EXEC,						//任务状态:正在执行
	TASK_DONE_EXEC,							//任务状态:完成执行

	//任务状态改变，由客户端发起
	TASK_STOP_EXEC,							//中止任务
	TASK_DELAY_EXEC,						//推迟任务
	TASK_PAUSE_EXEC,						//取消任务:暂停执行	
	TASK_ACTIVATE_EXEC,						//激活任务:恢复执行
	TASK_START_EXEC,						//开始任务（手动执行）

	//任务状态改变结果
	TASK_STATUS_CHANGE_SUCCESS,				//状态改变成功
	TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND, //任务不存在
	TASK_STATUS_CHANGE_FAIL_TASK_STATUS_ERROR,	//任务状态错误

	//增加任务结果处理情况
	TASK_RESULT_WRITE_FILE_ERROR,	//任务结果写文件失败
};

enum TASK_PRIORITY
{
	TASK_LOW_PRIORITY							= 1,
	TASK_MIDDLE_PRIORITY,
	TASK_HIGH_PRIORITY,
};

class CFTDRtnNetMonitorTaskTotalResult
{
	/* */
	public:
		CFTDRtnNetMonitorTaskTotalResult(void)
		{
		}

		CFTDRtnNetMonitorTaskTotalResult(
		CFTDRtnNetMonitorTaskResultField fd,
		string rt)
		{
			field.Flag = fd.Flag;
			field.InstructChain = fd.InstructChain;
			field.MonDate = fd.MonDate;
			field.MonTime = fd.MonTime;
			field.ObjectID = fd.ObjectID;
			field.OperateTime = fd.OperateTime;
			field.OperationType = fd.OperationType;
			field.Task_ID = fd.Task_ID;

			result = rt;
			user = "";
		}

		CFTDRtnNetMonitorTaskResultField field;
		string result;
		string user;
};

/// CSnmpTaskInfo 定义了SNMP指标任务信息体
class CSnmpTaskInfo
{
	/* */
	public:
		int TaskID;
		int RunTimes;
		string TaskDate;
		string TaskTime;
		string ObjectID;
		string IPAddress;
		string Community;
		string AttrName;
		int TaskStatus; //任务状态
};

/// CConnTaskInfo 定义了连接指令任务信息体
class CConnTaskInfo
{
	/* */
	public:
		int TaskID;
		int RunTimes;
		string TaskDate;
		string TaskTime;
		string ObjectID;
		string IPAddress;
		int Port;
		int Protocal;
		string UserName;
		string Password;
		string CfgPassword;
		string Cmds;
		string cmdAlias;
		int TaskStatus; //任务状态
};

///任务当天执行次数
class CTaskRunTimes
{
	/* */
	public:
		int TaskID;
		int RunTimes;
};

///任务当前控制状态
class CTaskCtlStatus
{
	/* */
	public:
		int TaskID;
		int TaskStatus;
		int DelayGap;	//延时时间
};

class CTaskCountStatus
{
	/* */
	public:
		int items;
		int status;
};

typedef std::map<int, CTaskCountStatus> MAP_TASK_STATUS;
typedef MAP_TASK_STATUS::iterator MAP_TASK_STATUS_ITERATOR;


/// CTaskInfoManager 定义了任务信息的保存容器及管理方法
class CTaskInfoManager
{
	/* */
	public:
		CTaskInfoManager(void);

		~ CTaskInfoManager(void);

		// Device
		void AddDeviceInfo(CFTDSysNetDeviceField info);
		void UpdDeviceInfo(CFTDSysNetDeviceField info, int casement);

		// DeviceGroup
		void AddDeviceGroupInfo(CFTDSysNetMonitorDeviceGroupField info);
		void UpdDeviceGroupInfo(
				CFTDSysNetMonitorDeviceGroupField info,
				int casement);

		// DeviceGroupList
		void AddDeviceGroupListInfo(CFTDSysNetMonitorTaskObjectSetField info);
		void UpdDeviceGroupListInfo(
				CFTDSysNetMonitorTaskObjectSetField info,
				int casement);

		// TimePolicy
		void AddTimePolicyInfo(CFTDSysNetTimePolicyField info);
		void UpdTimePolicyInfo(CFTDSysNetTimePolicyField info, int casement);

		// ActionGroup
		void AddActionGroupInfo(CFTDSysNetMonitorActionGroupField info);
		void UpdActionGroupInfo(
				CFTDSysNetMonitorActionGroupField info,
				int casement);

		// Command
		void AddCommandInfo(CFTDSysNetMonitorCommandTypeField info);
		void UpdCommandInfo(
				CFTDSysNetMonitorCommandTypeField info,
				int casement);

		// ActionAttr
		void AddActionAttrInfo(CFTDSysNetMonitorActionAttrField info);
		void UpdActionAttrInfo(
				CFTDSysNetMonitorActionAttrField info,
				int casement);

		// Task
		void AddTaskInfo(CFTDSysNetMonitorTaskInfoField info);
		void UpdTaskInfo(CFTDSysNetMonitorTaskInfoField info, int casement);

		void AddPolicyTask(int PolicyID, int TaskID);
		void DelPolicyTask(int PolicyID, int TaskID);

		void AddTask(int TaskID, int Times, string MonDate, string MonTime);
		void AddConnTask(
				int TaskID,
				int Times,
				string MonDate,
				string MonTime,
				CFTDSysNetDeviceField DeviceInfo,
				string Command,
				string CommandAlias,
				int TaskStatus);
		void AddSnmpTask(
				int TaskID,
				int Times,
				string MonDate,
				string MonTime,
				CFTDSysNetDeviceField DeviceInfo,
				string AttrName,
				int TaskStatus);
		void AddPartyLinkTask(CFTDSysNetDeviceField DeviceInfo);

		//Device Tasks
		void AddDeviceTaskInfo(CFTDSysNetMonitorDeviceTaskField d_task);
		void UdpDeviceTaskInfo(
				CFTDSysNetMonitorDeviceTaskField d_task,
				int op_type);

		//Instruction infomation
		void AddInstructionInfo(CFTDSysNetMonitorTaskInstAttrsField instr);
		void UdpInstructionInfo(
				CFTDSysNetMonitorTaskInstAttrsField instr,
				int op_type);

		//BaseLine Tasks
		void AddBaseLineTask(CFTDSysNetBaseLineTaskField b_task);
		void DelBaseLineTask(int id);

		//处理基线比对任务
		int ProcessBaseLineTask(
				CFTDSysNetBaseLineTaskField bl_task,
				CFTDSysNetDeviceField dev);

		MAP_TIMEPOLICYENTITY &GetMapTimePolicyEntity(void);
		LIST_ID &GetTaskListByPolicy(int PolicyID);

		//从list中获取一个task对象
		bool GetSnmpTask(CSnmpTaskInfo &TaskInfo);
		bool GetConnTask(CConnTaskInfo &TaskInfo);

		//将task对象移到list尾部
		void MoveToConnTaskTail(CConnTaskInfo &TaskInfo);
		void MoveToSnmpTaskTail(CSnmpTaskInfo &TaskInfo);

		//更新task的状态
		void UpdateTaskStatus(
				int task_id,
				string object_id,
				string attrname,
				int task_status,
				int task_type);

		//获取list中task的个数
		int ConnTaskCount(void);
		int SnmpTaskCount(void);

		void AddTaskResult(
		const CFTDRtnNetMonitorTaskResultField	&field,
		string result)
		{
			CFTDRtnNetMonitorTaskTotalResult totalResult(field, result);
			if (field.Task_ID != 0
			&&	field.Flag >= TASK_SUCCESS
			&&	field.Flag <= TASK_CONFIG_DISMATCH)
			{
				char keystr[128] = "\0";
				int taskid = field.Task_ID.getValue();
				int iTimes = GetTaskCurTimes(taskid);
				sprintf(keystr, "%d_%d", taskid, iTimes);

				std::map<string, string>::iterator	it = map_TaskRunner.find(
						keystr);
				if (it != map_TaskRunner.end())
				{
					printf(
						"@@@@@ find runner [%s] in task result with taskid_times[%s].\n",
						it->second.c_str(),
						keystr);
					totalResult.user = it->second;
				}
			}

			m_listTaskResult.add(totalResult);
		}

		void AddRemotePingResult(
		const CFTDRtnNetRomotePingResultInfoField &field)
		{
			m_listRemotePingResult.add(field);
		}

		bool GetTaskResult(CFTDRtnNetMonitorTaskTotalResult &totalresult)
		{
			return m_listTaskResult.get(totalresult);
		}

		bool GetRemotePingResult(
		CFTDRtnNetRomotePingResultInfoField &pingresult)
		{
			return m_listRemotePingResult.get(pingresult);
		}

		void AddLocalPingResult(const CFTDRtnNetLocalPingResultInfoField &field)
		{
			m_listLocalPingResult.add(field);
		}

		bool GetLocalPingResult(CFTDRtnNetLocalPingResultInfoField &pingresult)
		{
			return m_listLocalPingResult.get(pingresult);
		}

		void AddTMWarningEvent(const CFTDRtnWarningEventField &field)
		{
			m_listTMWarningEvent.add(field);
		}

		bool GetTMWarningEvent(CFTDRtnWarningEventField &field)
		{
			return m_listTMWarningEvent.get(field);
		}

		void AddTMSyslogEventField(const CFTDRtnSyslogEventField &field)
		{
			m_listTMSyslogEvent.add(field);
		}

		bool GetTMSyslogEventField(CFTDRtnSyslogEventField &field)
		{
			return m_listTMSyslogEvent.get(field);
		}

		////
		//int GetTaskItems(int taskID );
		//处理停止任务请求
		int ProcessStopTaskReq(int taskid);

		//处理取消任务请求
		int ProcessPauseTaskReq(int taskid);

		//处理激活任务请求
		int ProcessActivateTaskReq(int taskid);

		//处理延迟任务请求
		int ProcessDelayTaskReq(int taskid, int delaygap);

		//处理任务立即执行请求
		int ProcessDoNowTaskReq(int taskid, const char *name = NULL);

		int ProcessDeviceTaskReq( CFTDSysNetDeviceField *hp, const char* command, const char *name );

		MAP_DEVICE map_Device;
		map<string, int> map_ipDev; //string ip,int id
		MAP_DEVICEGROUP map_DeviceGroup;
		MAP_DEVICEGROUPLIST map_DeviceGroupList;
		MAP_TIMEPOLICY map_TimePolicy;
		MAP_TIMEPOLICYENTITY map_TimePolicyEntity;
		MAP_ACTIONGROUP map_ActionGroup;
		MAP_COMMAND map_Command;
		MAP_COMMANDSTRING map_CommandString;
		MAP_TASK map_Task;
		TemplateMutexCatch<int> list_Task; //立即执行任务列表
		MAP_POLICYTASKLIST map_PolicyTaskList;
		MAP_ACTIONATTR map_ActionAttr;

		MAP_DEV_TASK map_Devicetasks;
		MAP_INSTRU_INFO map_Instrus;

		MAP_BASELINETASK map_BaseLineTask;

		MAP_PINGTHRESHOLD map_PingThreshold;	// 保存对每个Ping操作的阀值
		void AddPingThreshold(string _SrcIp, string _DesIp, int _PingThreshold)
		{
			pair<string, string> PingIndex (_SrcIp, _DesIp);
			map_PingThreshold[PingIndex] = _PingThreshold;
		}

		//任务状态信息
		MAP_TASK_STATUS map_TaskStatus;

		//int@key=taskid, int@value=device numbers.以设备总数为标准
		std::map<int, int> map_TaskItems;

		std::map<int, int> map_DelayTaskList;

		//string@key="taskid_runtimes", string@value=runner
		std::map<string, string> map_TaskRunner;

		//snmp任务列表
		typedef list<CSnmpTaskInfo> SNMPTASKINFOLIST;

		//snmp任务优先级map,key:任务优先级，value:该优先级的任务list
		typedef map<int, SNMPTASKINFOLIST> SNMPPRIOTASKMAP;
		SNMPPRIOTASKMAP map_SnmpPrioTask;

		//snmp任务读写锁
		CMutex snmpPrioLock;

		//延时snmp任务队列
		TemplateMutexCatch<CSnmpTaskInfo> m_DelaySnmpTaskList;

		void AddDelaySnmpTask(const CSnmpTaskInfo &task)
		{
			m_DelaySnmpTaskList.add(task);
		}

		bool GetDelaySnmpTask(CSnmpTaskInfo &task)
		{
			return m_DelaySnmpTaskList.get(task);
		}

		//conn任务列表
		typedef list<CConnTaskInfo> CONNTASKINFOLIST;

		//conn任务优先级map,key:任务优先级，value:该优先级的任务list
		typedef map<int, CONNTASKINFOLIST> CONNPRIOTASKMAP;
		CONNPRIOTASKMAP map_ConnPrioTask;

		//conn任务读写锁	
		CMutex connPrioLock;

		//延时conn任务队列
		TemplateMutexCatch<CConnTaskInfo> m_DelayConnTaskList;

		//特定的conn任务队列
		TemplateMutexCatch<CConnTaskInfo> m_PartLinkConnTaskList;

		//特殊任务列表
		TemplateMutexCatch<CConnTaskInfo> m_ConnTaskList;

		void AddDelayConnTask(const CConnTaskInfo &task)
		{
			m_DelayConnTaskList.add(task);
		}

		bool GetDelayConnTask(CConnTaskInfo &task)
		{
			return m_DelayConnTaskList.get(task);
		}

		void AddTaskRunTimes(CTaskRunTimes &runtimes)
		{
			m_listTaskRunTimes.add(runtimes);
		}

		bool GetTaskRunTimes(CTaskRunTimes &runtimes)
		{
			return m_listTaskRunTimes.get(runtimes);
		}

		void AddTaskCtlStatus(CTaskCtlStatus &ctlstatus)
		{
			m_listTaskCtlStatus.add(ctlstatus);
		}

		bool GetTaskCtlStatus(CTaskCtlStatus &ctlstatus)
		{
			return m_listTaskCtlStatus.get(ctlstatus);
		}

		int GetTaskTimes(int TaskID);

		int GetTaskCurTimes(int TaskID);

		void UpdateTaskTimes(int TaskID, int Times);

		void ClearTaskTimes(void)
		{
			map_TaskRunTimes.clear();
		}

		int GetDeviceManuIDByIP(const char *ip)
		{
			map<string, int>::iterator	it = map_ipDev.find(ip);
			if (it != map_ipDev.end())
			{
				return map_Device[it->second].MANUFACTORY_ID.getValue();
			}

			return 0;
		}

		//int GetInstruID( const char *cmd )
		//{
		//	if( string(cmd).length()==0 )
		//	{
		//		return -1;
		//	}
		//	for(MAP_COMMAND_IT it =  map_Command.begin(); it != map_Command.end(); it++ )
		//	{
		//		if( string(it->second.Command.getValue()).compare(cmd) != 0 )
		//		{
		//			return it->first;
		//		}
		//	}
		//	return -1;

	//}
	public:
		/// 任务ID及此任务当日已运行次数
		map<int, int> map_TaskRunTimes;

	/* */
	private:
		///任务结果队列，包括任务状态和指令执行结果
		TemplateMutexCatch<CFTDRtnNetMonitorTaskTotalResult> m_listTaskResult;
		TemplateMutexCatch<CFTDRtnNetRomotePingResultInfoField>
			m_listRemotePingResult;
		TemplateMutexCatch<CFTDRtnNetLocalPingResultInfoField>
			m_listLocalPingResult;
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listTMWarningEvent;
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listTMSyslogEvent;

		///任务次数队列
		TemplateMutexCatch<CTaskRunTimes> m_listTaskRunTimes;

		///任务控制状态队列
		TemplateMutexCatch<CTaskCtlStatus> m_listTaskCtlStatus;
};

class CTaskManagerThread :
	public CThread
{
	/* */
	public:
		CTaskManagerThread(void);
		~ CTaskManagerThread(void);

		void GenerateTasks(void);
		void AddTask(int TaskID);

		/**虚函数，子类可做一些实例化工作
	* @return true:创建成功 false:创建失败
	*/
		virtual bool InitInstance(void);

		/**虚函数，子类清楚实例
	*/
		virtual void ExitInstance(void);

		/**线程开始运行，纯虚函数，子类必须继承实现
	*/
		virtual void Run(void);

		void UpdateTime()
		{
			time_t tDatetime = time(NULL);
			m_strMonDate = m_DateTime.GetDateStr(tDatetime);
		}

	/* */
	protected:
		/// 当前工作日
		string m_strMonDate;

		/// 当前工作时间
		string m_strMonTime;

		CDateTime m_DateTime;
		list<int> m_TaskQueue;
};
#endif
