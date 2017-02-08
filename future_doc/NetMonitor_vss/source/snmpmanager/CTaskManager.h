/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CTaskManager.h
///@brief	ʵ�������������
///@history
///20110718	�̺״�	�������ļ�
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
	TASK_TYPE_CONN, //ָ������
	TASK_TYPE_SNMP, //ָ������
};

//@int key=id����Ӧʵ����ID������,@CFTDSysNetDeviceField value=ʵ��
typedef std::map<int, CFTDSysNetDeviceField> MAP_DEVICE;
typedef MAP_DEVICE::iterator MAP_DEVICE_IT;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetMonitorDeviceGroupField value=ʵ��
typedef std::map<int, CFTDSysNetMonitorDeviceGroupField> MAP_DEVICEGROUP;
typedef MAP_DEVICEGROUP::iterator MAP_DEVICEGROUP_IT;

typedef list<int> LIST_ID;
typedef LIST_ID::iterator LIST_ID_IT;

//@int key=id���豸����ID��ʶ,@list <int> value=�豸����ID�б�
typedef std::map<int, LIST_ID> MAP_DEVICEGROUPLIST;
typedef MAP_DEVICEGROUPLIST::iterator MAP_DEVICEGROUPLIST_IT;

typedef std::map<int, LIST_ID> MAP_POLICYTASKLIST;
typedef MAP_POLICYTASKLIST::iterator MAP_POLICYTASKLIST_IT;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetTimePolicyField value=ʵ��
typedef std::map<int, CFTDSysNetTimePolicyField> MAP_TIMEPOLICY;
typedef MAP_TIMEPOLICY::iterator MAP_TIMEPOLICY_IT;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetTimePolicyField value=ʵ��
typedef std::map<int, CTimePolicy> MAP_TIMEPOLICYENTITY;
typedef MAP_TIMEPOLICYENTITY::iterator MAP_TIMEPOLICYENTITY_IT;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetMonitorActionGroupField value=ʵ��
typedef std::map<int, CFTDSysNetMonitorActionGroupField> MAP_ACTIONGROUP;
typedef MAP_ACTIONGROUP::iterator MAP_ACTIONGROUP_IT;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetMonitorCommandTypeField value=ʵ��
typedef std::map<int, CFTDSysNetMonitorCommandTypeField> MAP_COMMAND;
typedef MAP_COMMAND::iterator MAP_COMMAND_IT;

//@string key=�豸�����������豸����\������ȱ�ʶ��������,@string value=ָ�
typedef std::map<string, string> MAP_COMMANDSTRING;
typedef MAP_COMMANDSTRING::iterator MAP_COMMANDSTRING_IT;

//@string key=����ID��@string value=ָ�꼯��
typedef std::map<int, vector<std::string> > MAP_ACTIONATTR;
typedef MAP_ACTIONATTR::iterator MAP_ACTIONATTR_IT;

//@int key=id����Ӧʵ����ID������,@CFTDSysNetMonitorTaskInfoField value=ʵ��
typedef std::map<int, CFTDSysNetMonitorTaskInfoField> MAP_TASK;
typedef MAP_TASK::iterator MAP_TASK_IT;

//@<string��string> key=<ip,cmd>,�豸ip ָ��id�飬 @CFTDSysNetMonitorDeviceTaskField value=ʵ��
typedef std::map<pair<string, string> , CFTDSysNetMonitorDeviceTaskField>
	MAP_DEV_TASK;
typedef MAP_DEV_TASK::iterator MAP_DEV_TASK_IT;

//
typedef std::map<int, CFTDSysNetMonitorTaskInstAttrsField> MAP_INSTRU_INFO;
typedef MAP_INSTRU_INFO::iterator MAP_INSTRU_INFO_IT;

// ���߱ȶ������
typedef std::map<int, CFTDSysNetBaseLineTaskField> MAP_BASELINETASK;
typedef MAP_BASELINETASK::iterator MAP_BASELINETASK_ITERATOR;

// Ping�ķ�ֵ
//@<string��string> key=<Str_Ip, Des_Ip>,Դ�豸ip Ŀ���豸IP�� @int value=��ֵ
typedef map<pair<string, string>, int> MAP_PINGTHRESHOLD;
typedef MAP_PINGTHRESHOLD::iterator MAP_PINGTHRESHOLD_IT;

enum TASK_STATUS
{
	//����ִ�н��
	TASK_SUCCESS								= 0,	//ָ��ִ�гɹ�
	TASK_CONNECT_FAIL,			//����������ʧ��
	TASK_USERNAME_ERROR,		//�û�������
	TASK_USERPASSWD_ERROR,		//�û��������
	TASK_USERCOMMAND_FAIL,		//�û�����ִ��ʧ��
	TASK_ADMINPASSWD_ERROR,		//����Ա�������
	TASK_ADMINCOMMAND_ERROR,	//����Ա����ִ��ʧ��
	TASK_OTHER_ERROR,			//��������

	//�����ļ����ݽ��
	TASK_CFGBACKUP_SUCCESS,		//���ñ��ݳɹ�
	TASK_CFGBACKUP_FAIL,		//���ñ���ʧ��

	//�����ļ��ȶԽ��
	TASK_CONFIG_MATCH,			//�����ļ��ȶ�һ��
	TASK_CONFIG_DISMATCH,		//�����ļ��ȶԲ�һ��

	//�������쳣
	TASK_RESULT_ERROR							= 12,

	//����״̬֪ͨ����manager����
	TASK_WAIT_EXEC								= 21,	//����״̬:�ȴ�ִ��
	TASK_CANCEL_EXEC,						//����״̬:ȡ��ִ��
	TASK_DOING_EXEC,						//����״̬:����ִ��
	TASK_DONE_EXEC,							//����״̬:���ִ��

	//����״̬�ı䣬�ɿͻ��˷���
	TASK_STOP_EXEC,							//��ֹ����
	TASK_DELAY_EXEC,						//�Ƴ�����
	TASK_PAUSE_EXEC,						//ȡ������:��ִͣ��	
	TASK_ACTIVATE_EXEC,						//��������:�ָ�ִ��
	TASK_START_EXEC,						//��ʼ�����ֶ�ִ�У�

	//����״̬�ı���
	TASK_STATUS_CHANGE_SUCCESS,				//״̬�ı�ɹ�
	TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND, //���񲻴���
	TASK_STATUS_CHANGE_FAIL_TASK_STATUS_ERROR,	//����״̬����

	//�����������������
	TASK_RESULT_WRITE_FILE_ERROR,	//������д�ļ�ʧ��
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

/// CSnmpTaskInfo ������SNMPָ��������Ϣ��
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
		int TaskStatus; //����״̬
};

/// CConnTaskInfo ����������ָ��������Ϣ��
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
		int TaskStatus; //����״̬
};

///������ִ�д���
class CTaskRunTimes
{
	/* */
	public:
		int TaskID;
		int RunTimes;
};

///����ǰ����״̬
class CTaskCtlStatus
{
	/* */
	public:
		int TaskID;
		int TaskStatus;
		int DelayGap;	//��ʱʱ��
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


/// CTaskInfoManager ������������Ϣ�ı���������������
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

		//������߱ȶ�����
		int ProcessBaseLineTask(
				CFTDSysNetBaseLineTaskField bl_task,
				CFTDSysNetDeviceField dev);

		MAP_TIMEPOLICYENTITY &GetMapTimePolicyEntity(void);
		LIST_ID &GetTaskListByPolicy(int PolicyID);

		//��list�л�ȡһ��task����
		bool GetSnmpTask(CSnmpTaskInfo &TaskInfo);
		bool GetConnTask(CConnTaskInfo &TaskInfo);

		//��task�����Ƶ�listβ��
		void MoveToConnTaskTail(CConnTaskInfo &TaskInfo);
		void MoveToSnmpTaskTail(CSnmpTaskInfo &TaskInfo);

		//����task��״̬
		void UpdateTaskStatus(
				int task_id,
				string object_id,
				string attrname,
				int task_status,
				int task_type);

		//��ȡlist��task�ĸ���
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
		//����ֹͣ��������
		int ProcessStopTaskReq(int taskid);

		//����ȡ����������
		int ProcessPauseTaskReq(int taskid);

		//��������������
		int ProcessActivateTaskReq(int taskid);

		//�����ӳ���������
		int ProcessDelayTaskReq(int taskid, int delaygap);

		//������������ִ������
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
		TemplateMutexCatch<int> list_Task; //����ִ�������б�
		MAP_POLICYTASKLIST map_PolicyTaskList;
		MAP_ACTIONATTR map_ActionAttr;

		MAP_DEV_TASK map_Devicetasks;
		MAP_INSTRU_INFO map_Instrus;

		MAP_BASELINETASK map_BaseLineTask;

		MAP_PINGTHRESHOLD map_PingThreshold;	// �����ÿ��Ping�����ķ�ֵ
		void AddPingThreshold(string _SrcIp, string _DesIp, int _PingThreshold)
		{
			pair<string, string> PingIndex (_SrcIp, _DesIp);
			map_PingThreshold[PingIndex] = _PingThreshold;
		}

		//����״̬��Ϣ
		MAP_TASK_STATUS map_TaskStatus;

		//int@key=taskid, int@value=device numbers.���豸����Ϊ��׼
		std::map<int, int> map_TaskItems;

		std::map<int, int> map_DelayTaskList;

		//string@key="taskid_runtimes", string@value=runner
		std::map<string, string> map_TaskRunner;

		//snmp�����б�
		typedef list<CSnmpTaskInfo> SNMPTASKINFOLIST;

		//snmp�������ȼ�map,key:�������ȼ���value:�����ȼ�������list
		typedef map<int, SNMPTASKINFOLIST> SNMPPRIOTASKMAP;
		SNMPPRIOTASKMAP map_SnmpPrioTask;

		//snmp�����д��
		CMutex snmpPrioLock;

		//��ʱsnmp�������
		TemplateMutexCatch<CSnmpTaskInfo> m_DelaySnmpTaskList;

		void AddDelaySnmpTask(const CSnmpTaskInfo &task)
		{
			m_DelaySnmpTaskList.add(task);
		}

		bool GetDelaySnmpTask(CSnmpTaskInfo &task)
		{
			return m_DelaySnmpTaskList.get(task);
		}

		//conn�����б�
		typedef list<CConnTaskInfo> CONNTASKINFOLIST;

		//conn�������ȼ�map,key:�������ȼ���value:�����ȼ�������list
		typedef map<int, CONNTASKINFOLIST> CONNPRIOTASKMAP;
		CONNPRIOTASKMAP map_ConnPrioTask;

		//conn�����д��	
		CMutex connPrioLock;

		//��ʱconn�������
		TemplateMutexCatch<CConnTaskInfo> m_DelayConnTaskList;

		//�ض���conn�������
		TemplateMutexCatch<CConnTaskInfo> m_PartLinkConnTaskList;

		//���������б�
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
		/// ����ID���������������д���
		map<int, int> map_TaskRunTimes;

	/* */
	private:
		///���������У���������״̬��ָ��ִ�н��
		TemplateMutexCatch<CFTDRtnNetMonitorTaskTotalResult> m_listTaskResult;
		TemplateMutexCatch<CFTDRtnNetRomotePingResultInfoField>
			m_listRemotePingResult;
		TemplateMutexCatch<CFTDRtnNetLocalPingResultInfoField>
			m_listLocalPingResult;
		TemplateMutexCatch<CFTDRtnWarningEventField> m_listTMWarningEvent;
		TemplateMutexCatch<CFTDRtnSyslogEventField> m_listTMSyslogEvent;

		///�����������
		TemplateMutexCatch<CTaskRunTimes> m_listTaskRunTimes;

		///�������״̬����
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

		/**�麯�����������һЩʵ��������
	* @return true:�����ɹ� false:����ʧ��
	*/
		virtual bool InitInstance(void);

		/**�麯�����������ʵ��
	*/
		virtual void ExitInstance(void);

		/**�߳̿�ʼ���У����麯�����������̳�ʵ��
	*/
		virtual void Run(void);

		void UpdateTime()
		{
			time_t tDatetime = time(NULL);
			m_strMonDate = m_DateTime.GetDateStr(tDatetime);
		}

	/* */
	protected:
		/// ��ǰ������
		string m_strMonDate;

		/// ��ǰ����ʱ��
		string m_strMonTime;

		CDateTime m_DateTime;
		list<int> m_TaskQueue;
};
#endif
