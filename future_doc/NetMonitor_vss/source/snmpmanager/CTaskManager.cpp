/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CTaskManager.cpp
///@brief	实现了任务管理类
///@history
///20110718	晏鹤春	创建该文件
#include "CTaskManager.h"
#include "CConnTaskThread.h"
#include "CGetTransFiberDevice.h"
#include "CCrypto.h"

#ifndef WIN32
#include <sys/types.h>
#include <dirent.h>
#endif
#ifndef LINUX
#include "net_snmp.h"
#endif
CTaskInfoManager g_TaskInfoManager;
CGetTransFiberDevice *g_pGetTransFiberDevice = NULL; //采集传输设备线程;
extern CConnBaseLineTaskThread	*g_pBaseLineTaskThread;
extern map<string, list<string> > g_mapDeviceCMDS;

extern char g_mSSHDefaultUsrName[100];
extern char g_mSSHDefaultPasswd[100];
extern char g_mSSHDefaultAdminPasswd[100];
extern bool g_isMasterRole;

CTaskInfoManager::CTaskInfoManager(void)
{
}

CTaskInfoManager::~CTaskInfoManager(void)
{
}

bool CTaskInfoManager::GetConnTask(CConnTaskInfo &TaskInfo)
{
	connPrioLock.Lock();

	CONNTASKINFOLIST connlist;

	int high_prio = TASK_HIGH_PRIORITY;
	int mid_prio = TASK_MIDDLE_PRIORITY;
	int low_prio = TASK_LOW_PRIORITY;

	//优先级从高到低
	CONNPRIOTASKMAP::iterator c_it = map_ConnPrioTask.find(TASK_HIGH_PRIORITY);
	if (c_it == map_ConnPrioTask.end())
	{
		c_it = map_ConnPrioTask.find(TASK_MIDDLE_PRIORITY);
		if (c_it == map_ConnPrioTask.end())
		{
			c_it = map_ConnPrioTask.find(TASK_LOW_PRIORITY);
			if (c_it == map_ConnPrioTask.end())
			{
				//无任何任务数据
				connPrioLock.UnLock();
				return false;
			}
		}
	}

	TaskInfo = c_it->second.front();
	c_it->second.pop_front();

	if (c_it->second.size() == 0)
	{
		//list中无数据，清除该key
		map_ConnPrioTask.erase(c_it);
	}

	connPrioLock.UnLock();
	return true;
}

bool CTaskInfoManager::GetSnmpTask(CSnmpTaskInfo &TaskInfo)
{
	snmpPrioLock.Lock();

	SNMPTASKINFOLIST snmplist;

	int high_prio = TASK_HIGH_PRIORITY;
	int mid_prio = TASK_MIDDLE_PRIORITY;
	int low_prio = TASK_LOW_PRIORITY;

	//优先级从高到低
	SNMPPRIOTASKMAP::iterator s_it = map_SnmpPrioTask.find(TASK_HIGH_PRIORITY);
	if (s_it == map_SnmpPrioTask.end())
	{
		s_it = map_SnmpPrioTask.find(TASK_MIDDLE_PRIORITY);
		if (s_it == map_SnmpPrioTask.end())
		{
			s_it = map_SnmpPrioTask.find(TASK_LOW_PRIORITY);
			if (s_it == map_SnmpPrioTask.end())
			{
				//无任何任务数据
				snmpPrioLock.UnLock();
				return false;
			}
		}
	}

	TaskInfo = s_it->second.front();
	s_it->second.pop_front();

	if (s_it->second.size() == 0)
	{
		//list中无数据，清除该key
		map_SnmpPrioTask.erase(s_it);
	}

	snmpPrioLock.UnLock();
	return true;
}

//int CTaskInfoManager::GetTaskItems( int taskID )
//{
//	int items = 0;
//	MAP_TASK_IT m_it = map_Task.find( taskID );
//	if( m_it != map_Task.end() )
//	{
//		if( map_DeviceGroupList.find(m_it->second.DeviceGroup_ID) != map_DeviceGroupList.end() )
//			items = map_DeviceGroupList[ m_it->second.DeviceGroup_ID ].size();
//	}
//	return items;

//}
void CTaskInfoManager::MoveToConnTaskTail(CConnTaskInfo &task_info)
{
	MAP_TASK_IT m_it = map_Task.find(task_info.TaskID);
	if (m_it != map_Task.end())
	{
		connPrioLock.Lock();

		int prioid = m_it->second.TaskPriority_ID.getValue();
		CONNPRIOTASKMAP::iterator c_it = map_ConnPrioTask.find(prioid);
		if (c_it != map_ConnPrioTask.end())
		{
			c_it->second.push_back(task_info);
		}
		else
		{
			CONNTASKINFOLIST conntasklist;
			conntasklist.push_back(task_info);
			map_ConnPrioTask[prioid] = conntasklist;
		}

		connPrioLock.UnLock();
	}
}

void CTaskInfoManager::MoveToSnmpTaskTail(CSnmpTaskInfo &task_info)
{
	MAP_TASK_IT m_it = map_Task.find(task_info.TaskID);
	if (m_it != map_Task.end())
	{
		snmpPrioLock.Lock();

		int prioid = m_it->second.TaskPriority_ID.getValue();
		SNMPPRIOTASKMAP::iterator s_it = map_SnmpPrioTask.find(prioid);
		if (s_it != map_SnmpPrioTask.end())
		{
			s_it->second.push_back(task_info);
		}
		else
		{
			SNMPTASKINFOLIST snmptasklist;
			snmptasklist.push_back(task_info);
			map_SnmpPrioTask[prioid] = snmptasklist;
		}

		snmpPrioLock.UnLock();
	}
}

void CTaskInfoManager::UpdateTaskStatus(
	int task_id,
	string	object_id,
	string	attrname,
	int task_status,
	int task_type)
{
	MAP_TASK_IT m_it = map_Task.find(task_id);
	if (m_it == map_Task.end())
	{
		printf("can't find task by task_id:%d in UpdateTaskStatus\n", task_id);
		return;
	}

	int prio_id = m_it->second.TaskPriority_ID.getValue();
	if (TASK_TYPE_CONN == task_type)
	{
		connPrioLock.Lock();

		CONNPRIOTASKMAP::iterator c_it = map_ConnPrioTask.find(prio_id);
		if (c_it != map_ConnPrioTask.end())
		{
			CTaskInfoManager::CONNTASKINFOLIST::iterator l_it = c_it->second.begin();
			for (; l_it != c_it->second.end(); l_it++)
			{
				if (l_it->TaskID == task_id
				&&	l_it->ObjectID.compare(object_id) == 0
				&&	l_it->Cmds.compare(attrname) == 0)
				{
					l_it->TaskStatus = task_status;
					break;
				}
			}
		}

		connPrioLock.UnLock();
	}
	else if (TASK_TYPE_SNMP == task_type)
	{
		snmpPrioLock.Lock();

		SNMPPRIOTASKMAP::iterator s_it = map_SnmpPrioTask.find(prio_id);
		if (s_it != map_SnmpPrioTask.end())
		{
			CTaskInfoManager::SNMPTASKINFOLIST::iterator l_it = s_it->second.begin();
			for (; l_it != s_it->second.end(); l_it++)
			{
				if (l_it->TaskID == task_id
				&&	l_it->ObjectID.compare(object_id) == 0
				&&	l_it->AttrName.compare(attrname) == 0)
				{
					l_it->TaskStatus = task_status;
					break;
				}
			}
		}

		snmpPrioLock.UnLock();
	}
	else
	{
		printf(
			"invalid task_type:%d for task_id:%d in UpdateTaskStatus",
			task_type,
			task_id);
	}
}

// Device
void CTaskInfoManager::AddDeviceInfo(CFTDSysNetDeviceField info)
{
	map_Device[info.ID.getValue()] = info;
	map_ipDev[info.IPADDR.getValue()] = info.ID.getValue();
}

void CTaskInfoManager::UpdDeviceInfo(CFTDSysNetDeviceField info, int casement)
{
	MAP_DEVICE_IT it = map_Device.end();
	CFTDSysNetDeviceField *pInfo = (CFTDSysNetDeviceField *) &info;
	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			map_Device[info.ID.getValue()] = (CFTDSysNetDeviceField) * pInfo;
			map_ipDev[info.IPADDR.getValue()] = info.ID.getValue();
			break;
		case 3:
			/// 删除
			it = map_Device.find(info.ID.getValue());
			if (it != map_Device.end())
			{
				map_ipDev.erase(it->second.IPADDR.getValue());
				map_Device.erase(it);
			}

			break;
		case 4:
			/// 修改
			map_Device[info.ID.getValue()] = info;
			map_ipDev[info.IPADDR.getValue()] = info.ID.getValue();
			break;
	}
}

// DeviceGroup
void CTaskInfoManager::AddDeviceGroupInfo(
	CFTDSysNetMonitorDeviceGroupField info)
{
	map_DeviceGroup[info.ID.getValue()] = info;
}

void CTaskInfoManager::UpdDeviceGroupInfo(
	CFTDSysNetMonitorDeviceGroupField info,
	int casement)
{
	MAP_DEVICEGROUP_IT	it = map_DeviceGroup.end();
	MAP_DEVICEGROUPLIST_IT	itor = map_DeviceGroupList.end();

	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			map_DeviceGroup[info.ID.getValue()] = info;
			break;
		case 3:
			/// 删除
			it = map_DeviceGroup.find(info.ID.getValue());
			if (it != map_DeviceGroup.end())
			{
				map_DeviceGroup.erase(it);
			}

			itor = map_DeviceGroupList.find(info.ID.getValue());
			if (itor != map_DeviceGroupList.end())
			{
				map_DeviceGroupList.erase(itor);
			}

			break;
		case 4:
			/// 修改
			map_DeviceGroup[info.ID.getValue()] = info;
			break;
	}
}

// DeviceGroupList
void CTaskInfoManager::AddDeviceGroupListInfo(
	CFTDSysNetMonitorTaskObjectSetField info)
{
	MAP_DEVICEGROUPLIST_IT	it = map_DeviceGroupList.find(
			info.DeviceGroup_ID.getValue());
	if (it != map_DeviceGroupList.end())
	{
		LIST_ID &List = it->second;
		List.push_back(info.Device_ID.getValue());
		List.unique();
	}
	else
	{
		LIST_ID List;
		List.push_back(info.Device_ID.getValue());
		List.unique();
		map_DeviceGroupList[info.DeviceGroup_ID.getValue()] = List;
	}
}

void CTaskInfoManager::UpdDeviceGroupListInfo(
	CFTDSysNetMonitorTaskObjectSetField info,
	int casement)
{
	MAP_DEVICEGROUPLIST_IT	it = map_DeviceGroupList.find(
			info.DeviceGroup_ID.getValue());
	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			if (it != map_DeviceGroupList.end())
			{
				LIST_ID &List = it->second;
				List.push_back(info.Device_ID.getValue());
				List.unique();
			}
			else
			{
				LIST_ID List;
				List.push_back(info.Device_ID.getValue());
				List.unique();
				map_DeviceGroupList[info.DeviceGroup_ID.getValue()] = List;
			}

			break;
		case 3:
			/// 删除
			if (it != map_DeviceGroupList.end())
			{
				LIST_ID &List = it->second;
				LIST_ID_IT	iter = List.begin();
				for (; iter != List.end(); iter++)
				{
					if ((*iter) == info.Device_ID.getValue())
					{
						List.erase(iter);
						break;
					}
				}
			}

			break;
		case 4:
			/// 修改
			break;
	}
}

// TimePolicy
void CTaskInfoManager::AddTimePolicyInfo(CFTDSysNetTimePolicyField info)
{
	map_TimePolicy[info.ID.getValue()] = info;

	MAP_TIMEPOLICYENTITY_IT map_it = map_TimePolicyEntity.find(
			info.ID.getValue());
	if (map_it != map_TimePolicyEntity.end())
	{
		CTimePolicy TimePolicy = CTimePolicy(info.PolicyString.getValue());
		if (map_it->second == TimePolicy)
		{
			/// Do nothing
		}
		else
		{
			/// Update
			map_TimePolicyEntity[info.ID.getValue()] = TimePolicy;
		}
	}
	else
	{
		map_TimePolicyEntity[info.ID.getValue()] = CTimePolicy(
				info.PolicyString.getValue());
	}
}

void CTaskInfoManager::UpdTimePolicyInfo(
	CFTDSysNetTimePolicyField info,
	int casement)
{
	MAP_TIMEPOLICY_IT it = map_TimePolicy.end();
	MAP_TIMEPOLICYENTITY_IT iter = map_TimePolicyEntity.end();
	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			AddTimePolicyInfo(info);
			break;
		case 3:
			/// 删除
			it = map_TimePolicy.find(info.ID.getValue());
			if (it != map_TimePolicy.end())
			{
				map_TimePolicy.erase(it);
			}

			iter = map_TimePolicyEntity.find(info.ID.getValue());
			if (iter != map_TimePolicyEntity.end())
			{
				map_TimePolicyEntity.erase(iter);
			}

			break;
		case 4:
			/// 修改
			map_TimePolicy[info.ID.getValue()] = info;
			map_TimePolicyEntity[info.ID.getValue()] = CTimePolicy(
					info.PolicyString.getValue());
			break;
	}
}

// ActionGroup
void CTaskInfoManager::AddActionGroupInfo(
	CFTDSysNetMonitorActionGroupField info)
{
	map_ActionGroup[info.ID.getValue()] = info;
}

void CTaskInfoManager::UpdActionGroupInfo(
	CFTDSysNetMonitorActionGroupField info,
	int casement)
{
	MAP_ACTIONGROUP_IT	it = map_ActionGroup.end();

	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			map_ActionGroup[info.ID.getValue()] = info;
			break;
		case 3:
			/// 删除
			it = map_ActionGroup.find(info.ID.getValue());
			if (it != map_ActionGroup.end())
			{
				map_ActionGroup.erase(it);
			}

			break;
		case 4:
			/// 修改
			map_ActionGroup[info.ID.getValue()] = info;
			break;
	}
}

// Command
void CTaskInfoManager::AddCommandInfo(CFTDSysNetMonitorCommandTypeField info)
{
	char szTmp[64] = "\0";
	string	serial;
	serial = info.DeviceModle.getValue();
	if (serial.empty() || strcasecmp(serial.c_str(), "default") == 0)
	{
		sprintf(
			szTmp,
			"%d.%d",
			info.Manufactory_ID.getValue(),
			info.ActionGroup_ID.getValue());
		map_CommandString[szTmp] = info.Command.getValue();
	}
	else
	{
		char *p = strtok((char *)(serial.c_str()), ";");
		sprintf(
			szTmp,
			"%d.%d.%s",
			info.Manufactory_ID.getValue(),
			info.ActionGroup_ID.getValue(),
			p);
		map_CommandString[szTmp] = info.Command.getValue();

		while ((p = strtok(NULL, ";")) != NULL)
		{
			sprintf(
				szTmp,
				"%d.%d.%s",
				info.Manufactory_ID.getValue(),
				info.ActionGroup_ID.getValue(),
				p);
			map_CommandString[szTmp] = info.Command.getValue();
		}
	}

	//sprintf(szTmp, "%d.%d.%d", info.Manufactory_ID.getValue(), info.MonitorType_ID.getValue(), info.ActionGroup_ID.getValue());
	//map_CommandString[szTmp] = info.Command.getValue();
	map_Command[info.ID.getValue()] = info;
}

void CTaskInfoManager::UpdCommandInfo(
	CFTDSysNetMonitorCommandTypeField info,
	int casement)
{
	char szTmp[64];
	MAP_COMMAND_IT	it = map_Command.end();
	MAP_COMMANDSTRING_IT iter = map_CommandString.end();
	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			//sprintf(szTmp, "%d.%d.%d", info.Manufactory_ID.getValue(), info.MonitorType_ID.getValue(), info.ActionGroup_ID.getValue());
			//map_CommandString[szTmp] = info.Command.getValue();
			//map_Command[info.ID.getValue()] = info;
			AddCommandInfo(info);
			break;
		case 3:
			/// 删除
			it = map_Command.find(info.ID.getValue());
			if (it != map_Command.end())
			{
				map_Command.erase(it);
			}

			for (iter = map_CommandString.begin(); iter != map_CommandString.end();)
			{
				if (strcmp(iter->second.c_str(), info.Command.getValue()) == 0)
				{
					map_CommandString.erase(iter);
				}
				else
				{
					iter++;
				}
			}

			break;
		case 4:
			/// 修改
			//char szTmp[64];
			//sprintf(szTmp, "%d.%d.%d", info.Manufactory_ID.getValue(), info.MonitorType_ID.getValue(), info.ActionGroup_ID.getValue());
			//map_CommandString[szTmp] = info.Command.getValue();
			//map_Command[info.ID.getValue()] = info;
			AddCommandInfo(info);
			break;
	}
}

void CTaskInfoManager::AddActionAttrInfo(CFTDSysNetMonitorActionAttrField info)
{
	MAP_ACTIONATTR_IT it = map_ActionAttr.find(info.ActionGroup_ID.getValue());
	if (it != map_ActionAttr.end())
	{
		it->second.push_back(info.MonitorAttrName.getValue());
	}
	else
	{
		std::vector<std::string> attrvec;
		attrvec.push_back(info.MonitorAttrName.getValue());

		map_ActionAttr[info.ActionGroup_ID.getValue()] = attrvec;
	}
}

void CTaskInfoManager::UpdActionAttrInfo(
	CFTDSysNetMonitorActionAttrField info,
	int casement)
{
	MAP_ACTIONATTR_IT it = map_ActionAttr.end();
	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			it = map_ActionAttr.find(info.ActionGroup_ID.getValue());
			if (it != map_ActionAttr.end())
			{
				it->second.push_back(info.MonitorAttrName.getValue());
			}
			else
			{
				std::vector<std::string> attrvec;
				attrvec.push_back(info.MonitorAttrName.getValue());

				map_ActionAttr[info.ActionGroup_ID.getValue()] = attrvec;
			}

			break;
		case 3:
			/// 删除
			it = map_ActionAttr.find(info.ActionGroup_ID.getValue());
			if (it != map_ActionAttr.end())
			{
				std::vector<std::string>::iterator	v_i = it->second.begin();
				for (; v_i != it->second.end(); ++v_i)
				{
					std::string str = *v_i;
					if (str.compare(info.MonitorAttrName.getValue()) == 0)
					{
						it->second.erase(v_i);

						//无任何指标，删除该action
						if (it->second.size() == 0)
						{
							map_ActionAttr.erase(it);
						}

						break;
					}
				}
			}

			break;
		case 4:
			/// 修改, 不支持
			printf("UpdActionAttrInfo not support modify!\n");
			break;
	}
}

// Task
void CTaskInfoManager::AddTaskInfo(CFTDSysNetMonitorTaskInfoField info)
{
	int status = TASK_WAIT_EXEC;
	MAP_TASK_IT it = map_Task.find(info.ID.getValue());
	if (it != map_Task.end())
	{
		//保留重启前的任务状态
		status = it->second.TaskStatus.getValue();
	}

	info.TaskStatus = status;
	map_Task[info.ID.getValue()] = info;
	AddPolicyTask(info.TimePolicy_ID.getValue(), info.ID.getValue());
}

void CTaskInfoManager::UpdTaskInfo(
	CFTDSysNetMonitorTaskInfoField info,
	int casement)
{
	MAP_TASK_IT it = map_Task.end();

	switch (casement)
	{
		case 1:
			/// 查询
			break;
		case 2:
			/// 增加
			info.TaskStatus = TASK_WAIT_EXEC;
			map_Task[info.ID.getValue()] = info;
			AddPolicyTask(info.TimePolicy_ID.getValue(), info.ID.getValue());
			break;
		case 3:
			/// 删除
			it = map_Task.find(info.ID.getValue());
			if (it != map_Task.end())
			{
				map_Task.erase(it);
			}

			DelPolicyTask(info.TimePolicy_ID.getValue(), info.ID.getValue());
			break;
		case 4:
			/// 修改
			info.TaskStatus = TASK_WAIT_EXEC;

			it = map_Task.find(info.ID.getValue());
			if (it != map_Task.end())
			{
				DelPolicyTask(
					it->second.TimePolicy_ID.getValue(),
					info.ID.getValue());
			}

			map_Task[info.ID.getValue()] = info;
			AddPolicyTask(info.TimePolicy_ID.getValue(), info.ID.getValue());
			break;
	}
}

void CTaskInfoManager::AddPolicyTask(int PolicyID, int TaskID)
{
	MAP_POLICYTASKLIST_IT it = map_PolicyTaskList.find(PolicyID);
	if (it == map_PolicyTaskList.end())
	{
		// New Policy
		LIST_ID List;
		List.push_back(TaskID);
		map_PolicyTaskList[PolicyID] = List;
	}
	else
	{
		it->second.push_back(TaskID);
		it->second.unique();
	}
}

void CTaskInfoManager::DelPolicyTask(int PolicyID, int TaskID)
{
	MAP_POLICYTASKLIST_IT it = map_PolicyTaskList.find(PolicyID);
	if (it != map_PolicyTaskList.end())
	{
		LIST_ID_IT iter = it->second.begin();
		for (; iter != it->second.end(); iter++)
		{
			if ((*iter) == TaskID)
			{
				it->second.erase(iter);
				break;
			}
		}
	}
}

MAP_TIMEPOLICYENTITY &CTaskInfoManager::GetMapTimePolicyEntity(void)
{
	return map_TimePolicyEntity;
}

LIST_ID &CTaskInfoManager::GetTaskListByPolicy(int PolicyID)
{
	MAP_POLICYTASKLIST_IT it = map_PolicyTaskList.find(PolicyID);
	if (it == map_PolicyTaskList.end())
	{
		LIST_ID List;
		return List;
	}
	else
	{
		return it->second;
	}
}

void CTaskInfoManager::AddDeviceTaskInfo(
	CFTDSysNetMonitorDeviceTaskField d_task)
{
	//只记录命令中带参数的设备任务 2012.10.10 by Lee
	if (d_task.InstructArgs.isNull())
	{
		return;
	}

	string key_ip = d_task.IPAddress.getValue();
	string key_alias = d_task.InstructAlias.getValue(); //指令
	map_Devicetasks[make_pair(key_ip, key_alias)] = d_task;
}

void CTaskInfoManager::UdpDeviceTaskInfo(
	CFTDSysNetMonitorDeviceTaskField d_task,
	int op_type)
{
	MAP_DEV_TASK_IT it;
	it = map_Devicetasks.find(
			make_pair(
				d_task.IPAddress.getValue(),
				d_task.InstructChain.getValue()));

	switch (op_type)
	{
		case 1:
			//查询
			break;
		case 2:
			//增加
			AddDeviceTaskInfo(d_task);
			break;
		case 3:
			//删除		
			if (it != map_Devicetasks.end())
			{
				map_Devicetasks.erase(it);
			}

			break;
		case 4:
			//修改
			if (it != map_Devicetasks.end())
			{
				it->second = d_task;
			}

			break;
		default:
			break;
	}
}

void CTaskInfoManager::AddInstructionInfo(
	CFTDSysNetMonitorTaskInstAttrsField instr)
{
	map_Instrus[instr.ID.getValue()] = instr;			//Manufactory_ID指令ID
}

void CTaskInfoManager::UdpInstructionInfo(
	CFTDSysNetMonitorTaskInstAttrsField instr,
	int op_type)
{
	MAP_INSTRU_INFO_IT it;
	switch (op_type)
	{
		case 1:
			// 查询
			break;
		case 2:
			// 增加
			map_Instrus[instr.Manufactory_ID.getValue()] = instr;
			break;
		case 3:
			//  删除
			it = map_Instrus.find(instr.Manufactory_ID.getValue());
			if (it != map_Instrus.end())
			{
				map_Instrus.erase(it);
			}

			break;
		case 4:
			// 修改
			it = map_Instrus.find(instr.Manufactory_ID.getValue());
			if (it != map_Instrus.end())
			{
				it->second = instr;
			}

			break;
		default:
			break;
	}
}

void CTaskInfoManager::AddTask(
	int TaskID,
	int Times,
	string MonDate,
	string MonTime)
{
	MAP_TASK_IT it = map_Task.find(TaskID);
	string cmdAlias;
	if (it != map_Task.end())
	{
		int iFlag = FLAG_ELEMENT_EMPTY;
		CFTDSysNetMonitorTaskInfoField TaskInfo = it->second;
		int iDeviceGroupID = TaskInfo.DeviceGroup_ID.getValue();
		int iActionGroupID = TaskInfo.ActionGroup_ID.getValue();
		if (map_ActionGroup.find(iActionGroupID) != map_ActionGroup.end())
		{
			cmdAlias = map_ActionGroup[iActionGroupID].EName.getValue();
		}
		else
		{
			printf(
				"there is no cmd Alias in taskid=[%d] iActionGroupID=[%d].\n",
				TaskID,
				iActionGroupID);
			return;
		}

		//查找动作类型
		MAP_ACTIONGROUP_IT a_it = map_ActionGroup.find(iActionGroupID);
		if (a_it == map_ActionGroup.end())
		{
			printf("can't find actiongroup by id:%d\n", iActionGroupID);
			return;
		}

		MAP_DEVICEGROUPLIST_IT map_it = map_DeviceGroupList.find(
				iDeviceGroupID);
		if (map_it != map_DeviceGroupList.end() && map_it->second.size() > 0)
		{
			map_TaskItems[TaskID] = map_it->second.size();

			LIST_ID &List = map_it->second;
			for (LIST_ID_IT list_it = List.begin();
				 list_it != List.end();
				 list_it++)
			{
				int iDeviceID = (*list_it);
				MAP_DEVICE_IT map_Device_it = map_Device.find(iDeviceID);
				if (map_Device_it != map_Device.end())
				{
					CFTDSysNetDeviceField DeviceInfo = map_Device_it->second;

					//过滤掉设备上不需要执行的命令
					map<string, list<string> >::iterator it_deviceCMD =
						g_mapDeviceCMDS.find(DeviceInfo.IPADDR.getValue());
					if (it_deviceCMD != g_mapDeviceCMDS.end()
					&&	find(
							it_deviceCMD->second.begin(),
						it_deviceCMD->second.end(),
						cmdAlias.c_str()) != it_deviceCMD->second.end())
					//&& it_deviceCMD->second.find(cmdAlias.c_str())!=string::npos )
					{
						map_TaskItems[TaskID] = map_TaskItems[TaskID] - 1;
						printf(
							"don't run cmd alias=[%s] with the device ip=[%s] in taskid=[%d].\n",
							cmdAlias.c_str(),
							DeviceInfo.IPADDR.getValue(),
							TaskID);
						continue;
					}

					if (a_it->second.ActionType <= 0
					||	a_it->second.ActionType >= 4)
					{
						printf(
							"invalid actiontype:%d for device:%d\n",
							a_it->second.ActionType,
							iDeviceID);
						return;
					}

					//动作类型，1: 指令,2:指标,3:指令加指标,4:配置任务(特殊的指令)
					if (a_it->second.ActionType == 1
					||	a_it->second.ActionType == 3
					||	a_it->second.ActionType == 4)
					{
						string strCmd;
						string args;
						char cmdbuff[256] = "\0";
						char szTmp[64] = "\0";

						sprintf(
							szTmp,
							"%d.%d.%s",
							DeviceInfo.MANUFACTORY_ID.getValue(),
							iActionGroupID,
							DeviceInfo.DEVICETYPE.getValue());

						MAP_COMMANDSTRING_IT map_CommandString_it =
							map_CommandString.find(szTmp);

						if (map_CommandString_it == map_CommandString.end())
						{
							memset(szTmp, 0, 64);
							sprintf(
								szTmp,
								"%d.%d",
								DeviceInfo.MANUFACTORY_ID.getValue(),
								iActionGroupID);
							map_CommandString_it = map_CommandString.find(
									szTmp);
						}

						if (map_CommandString_it != map_CommandString.end())
						{
							strCmd = map_CommandString_it->second;

							MAP_DEV_TASK_IT it = map_Devicetasks.find(
									make_pair(
										DeviceInfo.IPADDR.getValue(),
										cmdAlias));
							if (it != map_Devicetasks.end())
							{
								args = it->second.InstructArgs.getValue();
								if (args.length() > 0)
								{
									string cmd_temp = "";
									int index = strCmd.find("term length 0");
									if (index != string::npos)
									{
										cmd_temp = strCmd.substr(
												index +
													strlen("term length 0") +
													1);
									}
									else
									{
										cmd_temp = strCmd;
									}

									memset(cmdbuff, 0, 256);

									// 如果指令为Ping操作，以下过程从参数中解析出阀值，并将阀值信息从参数中删除
									if (strcasecmp(it->second.InstructAlias.getValue(), "Ping") == 0)
									{
										printf("Received a Ping Instruct. Args:%s\n", args.c_str());
										printf("\tRebuild Ping args...\n");

										int args_Processing = 0;	// 若当前处理的字段为IP地址，该值：0; 阀值：1；其他：2
										string _SrcIP = DeviceInfo.IPADDR.getValue();	// ping的源地址
										string _DesIP = "";		// 目的IP地址
										int _PingThreshold = 0;		// 阀值
										for (int string_index = 0;string_index != args.size();++string_index)
										{
											char CurChar = args[string_index];	// 当前处理字符
											if (CurChar == ' ')		// 当前字符为空格，表示后续字符为其他参数
											{
												args_Processing = 2;
												continue;
											}
											else if (CurChar == '#')	// 当前字符为#，表示后续字符为阀值
											{
												args_Processing = 1;
												args.erase(string_index, 1);	// 删除#
												string_index--;		// 删除字符后，处理标记-1，防止越界
												continue;
											}
											else if (CurChar == ';')	// 当前字符为“；”，表示一条记录处理结束，后续字符为IP地址
											{
												args_Processing = 0;
												// 保存源IP地址，目的IP地址和阀值信息
												if (_PingThreshold > 0)
												{
													g_TaskInfoManager.AddPingThreshold(_SrcIP, _DesIP, _PingThreshold);
													printf("\t[S]%s [D]%s [T]%d\n", _SrcIP.c_str(), _DesIP.c_str(), _PingThreshold);
												}
												else
												{
													if (_PingThreshold == 0)
														printf("\tNo Threshold\n");
													else
														printf("\tError Threshold\n");
												}

												// 重置目的IP，阀值
												_DesIP = "";
												_PingThreshold = 0;
												continue;
											} // end if (CurChar == ' ')

											// 如果处理的是IP地址字段，则将IP地址保存至目的IP地址
											if (args_Processing == 0)
											{
												_DesIP.append(1, CurChar);
											}
											else if (args_Processing == 1)
											{
												// 检测阀值字段的正确性
												if (CurChar >= '0' && CurChar <= '9' && _PingThreshold != -1)
													_PingThreshold = _PingThreshold * 10 + (CurChar - '0');
												else
													_PingThreshold = -1;		// 若阀值字段任意字符错误，则将阀值置为-1，后续的检测将会跳过

												args.erase(string_index, 1);	// 删除阀值字符串
												string_index--;		// 删除字符后，处理标记-1，防止越界
											} // end if (args_Processing == 0)
											
										} // end for

										// 保存最后一组源IP地址，目的IP地址和阀值信息
										if (_PingThreshold > 0)
										{
											g_TaskInfoManager.AddPingThreshold(_SrcIP, _DesIP, _PingThreshold);
											printf("\t[S]%s [D]%s [T]%d\n", _SrcIP.c_str(), _DesIP.c_str(), _PingThreshold);
										}
										else
										{
											if (_PingThreshold == 0)
												printf("\tNo Threshold\n");
											else
												printf("\tError Threshold\n");
										}

										printf("\tRebuild Ping args. Args:%s\n", args.c_str());
									} // end if (strcasecmp(it->second.InstructAlias.getValue(), "Ping") == 0)

									string pingdata = "";
									int ipos = 0;
									char *p = strtok(
											(char *)(args.c_str()),
											";");
									strCmd.append(" ");
									if (strcasecmp(
											it->second.InstructAlias.getValue(),
									"Ping") == 0)	// 如果是Ping操作
									{
										pingdata = p;

										ipos = pingdata.find_first_of(' ');
										if (ipos != string::npos)
										{
											pingdata.insert(ipos, " repeat");
										}

										strCmd.append(pingdata.c_str());

										while ((p = strtok(NULL, ";")) != NULL)
										{
											strCmd.append(";");
											strCmd.append(cmd_temp.c_str());
											strCmd.append(" ");
											pingdata = p;

											ipos = pingdata.find_first_of(' ');
											if (ipos != string::npos)
											{
												pingdata.insert(
														ipos,
														" repeat");
											}

											strCmd.append(pingdata.c_str());
										}
									}
									else
									{
										strCmd.append(p);

										while ((p = strtok(NULL, ";")) != NULL)
										{
											strCmd.append(";");
											strCmd.append(cmd_temp.c_str());
											strCmd.append(" ");
											strCmd.append(p);
										}
									}

									//AddConnTask(TaskID, Times, MonDate, MonTime, DeviceInfo, cmdbuff, cmdAlias,TaskInfo.TaskStatus);
									//while ((p = strtok(NULL, ";")) != NULL)
									//{
									//	memset( cmdbuff, 0, 128 );
									//	sprintf( cmdbuff, "%s %s", strCmd.c_str(), p );
									//	AddConnTask(TaskID, Times, MonDate, MonTime, DeviceInfo, cmdbuff, cmdAlias,TaskInfo.TaskStatus);
									//}
								}

								AddConnTask(
									TaskID,
									Times,
									MonDate,
									MonTime,
									DeviceInfo,
									strCmd,
									cmdAlias,
									TaskInfo.TaskStatus);
							}
							else
							{
								AddConnTask(
									TaskID,
									Times,
									MonDate,
									MonTime,
									DeviceInfo,
									strCmd,
									cmdAlias,
									TaskInfo.TaskStatus);
							}
						}
						else
						{
							strCmd = "";
							printf(
								"warn:cann't find command string strCmd=[%s] with manufactory=[%d], actionGroupID=[%d], devip=[%s], devtype=[%s]\n",
								strCmd.c_str(),
								DeviceInfo.MANUFACTORY_ID.getValue(),
								iActionGroupID,
								DeviceInfo.IPADDR.getValue(),
								DeviceInfo.DEVICETYPE.getValue());
						}
					}

					//指标类
					if (a_it->second.ActionType == 2
					||	a_it->second.ActionType == 3)
					{
						MAP_ACTIONATTR_IT s_it = map_ActionAttr.find(
								iActionGroupID);
						if (s_it != map_ActionAttr.end())
						{
							for (int i = 0; i < s_it->second.size(); ++i)
							{
								if( strcmp(s_it->second[i].c_str(),"cMsDwdmIfTransportPower") == 0 
									|| strcmp(s_it->second[i].c_str(),"cOpticalParameterValue") == 0 
									|| strcmp(s_it->second[i].c_str(),"ifInErrors")==0 ) //传输设备光功率
								{
									if( NULL == g_pGetTransFiberDevice )
									{
										g_pGetTransFiberDevice = new CGetTransFiberDevice();
										g_pGetTransFiberDevice->Create();

									}
									g_pGetTransFiberDevice->AddCTransFiberTaskInfo(
										TaskID,
										Times,
										MonDate,
										MonTime,
										DeviceInfo,
										s_it->second[i],
										TaskInfo.TaskStatus);
								}
								else
								{
									AddSnmpTask(
										TaskID,
										Times,
										MonDate,
										MonTime,
										DeviceInfo,
										s_it->second[i],
										TaskInfo.TaskStatus);
								}
							}
						}
						else
						{
							printf(
								"can't find snmpindex by actionid:%d\n",
								iActionGroupID);
						}
					}
				}
			}

			CTaskCtlStatus ctlstatus;

			ctlstatus.TaskID = TaskID;
			ctlstatus.TaskStatus = it->second.TaskStatus.getValue();
			ctlstatus.DelayGap = it->second.ValidFlag.getValue();

			//发送任务 状态到config
			AddTaskCtlStatus(ctlstatus);
		}
		else
		{
			printf(
				"can't find DeviceGroup by id:%d with task id:%d .\n",
				iDeviceGroupID,
				TaskID);
		}
	}
}

void CTaskInfoManager::AddConnTask(
	int TaskID,
	int Times,
	string MonDate,
	string MonTime,
	CFTDSysNetDeviceField DeviceInfo,
	string Command,
	string CommandAlias,
	int TaskStatus)
{
	CConnTaskInfo TaskInfo;
	TaskInfo.TaskID = TaskID;
	TaskInfo.RunTimes = Times;
	TaskInfo.TaskDate = MonDate;
	TaskInfo.TaskTime = MonTime;
	TaskInfo.ObjectID = DeviceInfo.ObjectID.getValue();
	TaskInfo.IPAddress = DeviceInfo.IPADDR.getValue();
	TaskInfo.Port = DeviceInfo.PORTNUMBER.getValue();
	TaskInfo.Protocal = DeviceInfo.CFGSAVETYPE.getValue();
	TaskInfo.UserName = DeviceInfo.USERNAME.getValue();
	//TaskInfo.Password = DeviceInfo.PASSWD.getValue();
	//TaskInfo.CfgPassword = DeviceInfo.ENPASSWD.getValue();

	//密码改成加密模式  20130401
	CDesEncryptAlgorithm key;
	key.SetPassword("monitor");
	char buff[256]="\0";
	key.Decrypt((char *)(DeviceInfo.PASSWD.getValue()),buff);
	TaskInfo.Password = buff;
	memset(buff, 256, 0);
	key.Decrypt((char *)(DeviceInfo.ENPASSWD.getValue()),buff);
	TaskInfo.CfgPassword = buff;

	TaskInfo.Cmds = Command;
	TaskInfo.cmdAlias = CommandAlias;
	TaskInfo.TaskStatus = TASK_WAIT_EXEC;

	//notify client
	time_t timep;
	CFTDRtnNetMonitorTaskResultField field;
	char curdate[10];
	char curtime[10];

	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);

	strftime(curtime, 10, "%H%M%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	field.ObjectID = TaskInfo.ObjectID.c_str();
	field.Task_ID = TaskInfo.TaskID;
	field.OperateTime = TaskInfo.RunTimes;
	field.MonDate = curdate;
	field.MonTime = curtime;
	field.Flag = TASK_WAIT_EXEC;
	AddTaskResult(field, "");

	TaskInfo.UserName = TaskInfo.UserName.length() == 0 ? g_mSSHDefaultUsrName : TaskInfo.UserName;
	TaskInfo.Password = TaskInfo.Password.length() == 0 ? g_mSSHDefaultPasswd : TaskInfo.Password;
	TaskInfo.CfgPassword = TaskInfo.CfgPassword.length() == 0 ? g_mSSHDefaultAdminPasswd : TaskInfo.CfgPassword;

	if (TaskInfo.Cmds.length() > 0)
	{
		if (TaskStatus == TASK_WAIT_EXEC || TaskStatus == TASK_START_EXEC)
		{
			connPrioLock.Lock();

			//更新任务优先级map
			MAP_TASK_IT m_it = map_Task.find(TaskID);
			if (m_it != map_Task.end())
			{
				int prioid = m_it->second.TaskPriority_ID.getValue();
				CONNPRIOTASKMAP::iterator c_it = map_ConnPrioTask.find(prioid);
				if (c_it != map_ConnPrioTask.end())
				{
					c_it->second.push_back(TaskInfo);
				}
				else
				{
					CONNTASKINFOLIST conntasklist;
					conntasklist.push_back(TaskInfo);
					map_ConnPrioTask[prioid] = conntasklist;
				}
			}

			connPrioLock.UnLock();
		}
		else if (TaskStatus == TASK_DELAY_EXEC)
		{
			map<int, int>::iterator d_i = map_DelayTaskList.find(TaskID);
			if (d_i == map_DelayTaskList.end())
			{
				printf("delay task :%d has no delaygap info\n", TaskID);
			}
			else
			{
				string strYear = TaskInfo.TaskDate.substr(0, 4);
				string strMonth = TaskInfo.TaskDate.substr(4, 2);
				string strDate = TaskInfo.TaskDate.substr(6, 2);

				string strHour = TaskInfo.TaskTime.substr(0, 2);
				string strMin = TaskInfo.TaskTime.substr(3, 2);
				string strSec = TaskInfo.TaskTime.substr(6, 2);

				struct tm taskTm;
				taskTm.tm_year = atoi(strYear.c_str()) - 1900;
				taskTm.tm_mon = atoi(strMonth.c_str()) - 1;
				taskTm.tm_mday = atoi(strDate.c_str());
				taskTm.tm_hour = atoi(strHour.c_str());
				taskTm.tm_min = atoi(strMin.c_str());
				taskTm.tm_sec = atoi(strSec.c_str());

				time_t tasktime = mktime(&taskTm);

				//更新时间戳
				tasktime += d_i->second;

				struct tm tm_time;
				LocalTime(&tasktime, &tm_time);

				char newTaskTime[10];
				char newTaskDate[10];
				strftime(newTaskTime, 10, "%H:%M:%S", &tm_time);
				strftime(newTaskDate, 10, "%Y%m%d", &tm_time);

				//生成新的任务时间
				TaskInfo.TaskDate = newTaskDate;
				TaskInfo.TaskTime = newTaskTime;

				m_DelayConnTaskList.add(TaskInfo);
			}
		}
		else
		{
			printf(
				"Invalid task_status:%d for task_id:%d in %s\n",
				TaskStatus,
				TaskID,
				__FUNCTION__);
		}
	}
}

void CTaskInfoManager::AddSnmpTask(
	int TaskID,
	int Times,
	string MonDate,
	string MonTime,
	CFTDSysNetDeviceField DeviceInfo,
	string AttrName,
	int TaskStatus)
{
	CSnmpTaskInfo TaskInfo;

	TaskInfo.TaskID = TaskID;
	TaskInfo.RunTimes = Times;
	TaskInfo.TaskDate = MonDate;
	TaskInfo.TaskTime = MonTime;
	TaskInfo.ObjectID = DeviceInfo.ObjectID.getValue();
	TaskInfo.IPAddress = DeviceInfo.IPADDR.getValue();

	TaskInfo.Community = DeviceInfo.RCOMMUNITY.getValue();
	TaskInfo.AttrName = AttrName;

	TaskInfo.TaskStatus = TASK_WAIT_EXEC;

	//notify client
	time_t timep;
	CFTDRtnNetMonitorTaskResultField field;
	char curdate[10];
	char curtime[10];

	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);

	strftime(curtime, 10, "%H%M%S", &tm_time);
	strftime(curdate, 10, "%Y%m%d", &tm_time);

	field.ObjectID = TaskInfo.ObjectID.c_str();
	field.Task_ID = TaskInfo.TaskID;
	field.OperateTime = TaskInfo.RunTimes;
	field.MonDate = curdate;
	field.MonTime = curtime;
	field.Flag = TASK_WAIT_EXEC;
	AddTaskResult(field, "");

	//更新任务优先级map
	MAP_TASK_IT m_it = map_Task.find(TaskID);
	if (m_it != map_Task.end())
	{
		if (TaskStatus == TASK_WAIT_EXEC)
		{
			snmpPrioLock.Lock();

			int prioid = m_it->second.TaskPriority_ID.getValue();
			SNMPPRIOTASKMAP::iterator s_it = map_SnmpPrioTask.find(prioid);
			if (s_it != map_SnmpPrioTask.end())
			{
				s_it->second.push_back(TaskInfo);
			}
			else
			{
				SNMPTASKINFOLIST snmptasklist;
				snmptasklist.push_back(TaskInfo);
				map_SnmpPrioTask[prioid] = snmptasklist;
			}

			snmpPrioLock.UnLock();
		}
		else if (TaskStatus == TASK_DELAY_EXEC)
		{
			map<int, int>::iterator d_i = map_DelayTaskList.find(TaskID);
			if (d_i == map_DelayTaskList.end())
			{
				printf("delay task :%d has no delaygap info\n", TaskID);
			}
			else
			{
				string strYear = TaskInfo.TaskDate.substr(0, 4);
				string strMonth = TaskInfo.TaskDate.substr(4, 2);
				string strDate = TaskInfo.TaskDate.substr(6, 2);

				string strHour = TaskInfo.TaskTime.substr(0, 2);
				string strMin = TaskInfo.TaskTime.substr(3, 2);
				string strSec = TaskInfo.TaskTime.substr(6, 2);

				struct tm taskTm;
				taskTm.tm_year = atoi(strYear.c_str()) - 1900;
				taskTm.tm_mon = atoi(strMonth.c_str()) - 1;
				taskTm.tm_mday = atoi(strDate.c_str());
				taskTm.tm_hour = atoi(strHour.c_str());
				taskTm.tm_min = atoi(strMin.c_str());
				taskTm.tm_sec = atoi(strSec.c_str());

				time_t tasktime = mktime(&taskTm);

				//更新时间戳
				tasktime += d_i->second;

				struct tm tm_time;
				LocalTime(&tasktime, &tm_time);

				char newTaskTime[10];
				char newTaskDate[10];
				strftime(newTaskTime, 10, "%H:%M:%S", &tm_time);
				strftime(newTaskDate, 10, "%Y%m%d", &tm_time);

				//生成新的任务时间
				TaskInfo.TaskDate = newTaskDate;
				TaskInfo.TaskTime = newTaskTime;

				m_DelaySnmpTaskList.add(TaskInfo);
			}
		}
		else
		{
			printf(
				"Invalid task_status:%d for task_id:%d in %s\n",
				TaskStatus,
				TaskID,
				__FUNCTION__);
		}
	}
}

void CTaskInfoManager::AddPartyLinkTask(CFTDSysNetDeviceField DeviceInfo)
{
	CConnTaskInfo TaskInfo;
	TaskInfo.TaskID = 0;
	TaskInfo.RunTimes = 0;
	TaskInfo.ObjectID = DeviceInfo.ObjectID.getValue();
	TaskInfo.IPAddress = DeviceInfo.IPADDR.getValue();
	TaskInfo.Port = DeviceInfo.PORTNUMBER.getValue();
	TaskInfo.Protocal = DeviceInfo.CFGSAVETYPE.getValue();
	TaskInfo.UserName = DeviceInfo.USERNAME.getValue();
	//TaskInfo.Password = DeviceInfo.PASSWD.getValue();
	//TaskInfo.CfgPassword = DeviceInfo.ENPASSWD.getValue();

	//密码改成加密模式  2013.04.01
	CDesEncryptAlgorithm key;
	key.SetPassword("monitor");
	char buff[256]="\0";
	key.Decrypt((char *)(DeviceInfo.PASSWD.getValue()),buff);
	TaskInfo.Password = buff;
	memset(buff, 256, 0);
	key.Decrypt((char *)(DeviceInfo.ENPASSWD.getValue()),buff);
	TaskInfo.CfgPassword = buff;

	TaskInfo.Cmds = "term length 0;show ip int brief";
	TaskInfo.cmdAlias = "IfsInfo";
	TaskInfo.TaskStatus = TASK_WAIT_EXEC;

	time_t timep;
	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	char curTimeStr[10];
	char curDateStr[10];

	strftime(curTimeStr, 10, "%H%M%S", &tm_time);
	strftime(curDateStr, 10, "%Y%m%d", &tm_time);

	TaskInfo.TaskDate = curDateStr;
	TaskInfo.TaskTime = curTimeStr;

	TaskInfo.UserName = TaskInfo.UserName.length() == 0 ? g_mSSHDefaultUsrName : TaskInfo.UserName;
	TaskInfo.Password = TaskInfo.Password.length() == 0 ? g_mSSHDefaultPasswd : TaskInfo.Password;
	TaskInfo.CfgPassword = TaskInfo.CfgPassword.length() == 0 ? g_mSSHDefaultAdminPasswd : TaskInfo.CfgPassword;

	m_PartLinkConnTaskList.add(TaskInfo);
}

int CTaskInfoManager::ConnTaskCount(void)
{
	int high_prio = TASK_HIGH_PRIORITY;
	int mid_prio = TASK_MIDDLE_PRIORITY;
	int low_prio = TASK_LOW_PRIORITY;

	int count = 0;
	CONNPRIOTASKMAP::iterator c_it = map_ConnPrioTask.find(high_prio);
	if (c_it != map_ConnPrioTask.end())
	{
		count += c_it->second.size();
	}

	c_it = map_ConnPrioTask.find(mid_prio);
	if (c_it != map_ConnPrioTask.end())
	{
		count += c_it->second.size();
	}

	c_it = map_ConnPrioTask.find(low_prio);
	if (c_it != map_ConnPrioTask.end())
	{
		count += c_it->second.size();
	}

	return count;
}

int CTaskInfoManager::SnmpTaskCount(void)
{
	int high_prio = TASK_HIGH_PRIORITY;
	int mid_prio = TASK_MIDDLE_PRIORITY;
	int low_prio = TASK_LOW_PRIORITY;

	int count = 0;
	SNMPPRIOTASKMAP::iterator s_it = map_SnmpPrioTask.find(high_prio);
	if (s_it != map_SnmpPrioTask.end())
	{
		count += s_it->second.size();
	}

	s_it = map_SnmpPrioTask.find(mid_prio);
	if (s_it != map_SnmpPrioTask.end())
	{
		count += s_it->second.size();
	}

	s_it = map_SnmpPrioTask.find(low_prio);
	if (s_it != map_SnmpPrioTask.end())
	{
		count += s_it->second.size();
	}

	return count;
}

int CTaskInfoManager::ProcessStopTaskReq(int taskid)
{
	MAP_TASK_IT it = map_Task.find(taskid);
	if (it == map_Task.end())
	{
		printf("no task to stop, task_id:%d\n", taskid);
		return TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
	}

	it->second.TaskStatus = TASK_STOP_EXEC;

	printf("task stop success, task_id:%d\n", taskid);
	return TASK_STATUS_CHANGE_SUCCESS;
}

//处理取消任务请求
int CTaskInfoManager::ProcessPauseTaskReq(int taskid)
{
	MAP_TASK_IT it = map_Task.find(taskid);
	if (it == map_Task.end())
	{
		printf("no task to stop, task_id:%d\n", taskid);
		return TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
	}

	if (it->second.TaskStatus == TASK_WAIT_EXEC
	||	it->second.TaskStatus == TASK_DELAY_EXEC)
	{
		it->second.TaskStatus = TASK_PAUSE_EXEC;

		printf("task pause success, task_id:%d\n", taskid);
		return TASK_STATUS_CHANGE_SUCCESS;
	}
	else
	{
		printf(
			"task pause fail, task_id:%d, task_status:%d\n",
			taskid,
			it->second.TaskStatus.getValue());
		return TASK_STATUS_CHANGE_FAIL_TASK_STATUS_ERROR;
	}
}

//处理激活任务请求
int CTaskInfoManager::ProcessActivateTaskReq(int taskid)
{
	MAP_TASK_IT it = map_Task.find(taskid);
	if (it == map_Task.end())
	{
		printf("no task to stop, task_id:%d\n", taskid);
		return TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
	}

	if (it->second.TaskStatus != TASK_PAUSE_EXEC)
	{
		printf(
			"ProcessActivateTaskReq fail, task_status:%d can't to activate for task_id:%d\n",
			it->second.TaskStatus.getValue(),
			taskid);
		return TASK_STATUS_CHANGE_FAIL_TASK_STATUS_ERROR;
	}

	it->second.TaskStatus = TASK_WAIT_EXEC;

	printf("task activate success, task_id:%d\n", taskid);
	return TASK_STATUS_CHANGE_SUCCESS;
}

//处理延迟任务请求
int CTaskInfoManager::ProcessDelayTaskReq(int taskid, int delaygap)
{
	MAP_TASK_IT it = map_Task.find(taskid);
	if (it == map_Task.end())
	{
		printf("no task to stop, task_id:%d\n", taskid);
		return TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
	}

	it->second.TaskStatus = TASK_DELAY_EXEC;
	it->second.ValidFlag = delaygap;

	map_DelayTaskList[taskid] = delaygap;

	printf("task delay success, task_id:%d, delaygap:%d\n", taskid, delaygap);
	return TASK_STATUS_CHANGE_SUCCESS;
}

//处理任务立即执行请求 
int CTaskInfoManager::ProcessDoNowTaskReq(int taskid, const char *name)
{
	MAP_TASK_IT it = map_Task.find(taskid);
	if (it == map_Task.end())
	{
		printf("no task to do now, task_id:%d\n", taskid);
		return TASK_STATUS_CHANGE_FAIL_TASK_NOT_FOUND;
	}

	if (it->second.TaskStatus == TASK_DOING_EXEC)
	{
		printf("task id [%d] is started already.\n", taskid);
		return TASK_STATUS_CHANGE_FAIL_TASK_STATUS_ERROR;
	}
	else
	{
		it->second.TaskStatus = TASK_START_EXEC;

		//记录下任务id，关联次数，执行者
		list_Task.add(taskid);
		if (name != NULL)
		{
			char keystr[1024] = "\0";
			int iTimes = GetTaskCurTimes(taskid);
			sprintf(keystr, "%d_%d", taskid, iTimes + 1);
			map_TaskRunner[keystr] = name;
		}

		printf("task status changed success, task_id:%d\n", taskid);
	}

	return TASK_STATUS_CHANGE_SUCCESS;
}

int CTaskInfoManager::ProcessDeviceTaskReq( CFTDSysNetDeviceField *hp, const char* command, const char *name )
{
	if( hp == NULL )
	{
		printf("warning:device point is NULL.\n");
		return -1;
	}
	CConnTaskInfo  task;
	task.TaskID = -1;
	task.RunTimes = 0;
	task.Cmds = "term length 0;show running-config";
	task.cmdAlias = "RunningConfig";
	//	task.cmdAlias = command;
	task.ObjectID = hp->ObjectID.getValue();
	task.TaskStatus = TASK_WAIT_EXEC;
	task.IPAddress = hp->IPADDR.getValue();
	task.Port = hp->PORTNUMBER.getValue();
	task.Protocal = hp->CFGSAVETYPE.getValue();
	task.UserName = hp->USERNAME.getValue();
	//task.Password = hp->PASSWD.getValue();
	//task.CfgPassword = hp->ENPASSWD.getValue();
	//密码改成加密模式
	CDesEncryptAlgorithm key;
	key.SetPassword("monitor");
	char buff[256]="\0";
	key.Decrypt((char *)hp->PASSWD.getValue(),buff);
	task.Password = buff;
	memset(buff, 256, 0);
	key.Decrypt((char *)(hp->ENPASSWD.getValue()),buff);
	task.CfgPassword = buff;

	task.UserName = task.UserName.length() == 0 ? g_mSSHDefaultUsrName : task.UserName;
	task.Password = task.Password.length() == 0 ? g_mSSHDefaultPasswd : task.Password;
	task.CfgPassword = task.CfgPassword.length() == 0 ? g_mSSHDefaultAdminPasswd : task.CfgPassword;

	char curtimebuff[10]="\0";
	time_t	nTime = time((time_t *)NULL);
	struct tm tm_time;
	LocalTime(&nTime, &tm_time);
	strftime(curtimebuff, 10, "%Y%m%d", &tm_time);
	task.TaskDate = curtimebuff;
	strftime(curtimebuff, 10, "%H:%M:%S", &tm_time);
	task.TaskTime = curtimebuff;

	m_ConnTaskList.add( task );

	return TASK_STATUS_CHANGE_SUCCESS;
}

CTaskManagerThread::CTaskManagerThread(void)
{
	time_t tDatetime = time(NULL);
	m_strMonDate = m_DateTime.GetDateStr(tDatetime);
	m_strMonTime = "";
	m_DateTime.OpenDrift();
}


CTaskManagerThread::~CTaskManagerThread(void)
{
}

bool CTaskManagerThread::InitInstance(void)
{
	return true;
}

void CTaskManagerThread::ExitInstance(void)
{
}

void CTaskManagerThread::Run(void)
{
	while (1)
	{
		if (g_isMasterRole)
		{
			// 获取当前时间戳,并判断是否跨天
			time_t tDatetime = time(NULL);
			string strDate = m_DateTime.GetDateStr(tDatetime);
			m_strMonTime = m_DateTime.GetTimeStr(tDatetime);
			if (m_strMonDate != strDate)
			{
				//notify config
				map<int, int>::iterator r_it = g_TaskInfoManager.
					map_TaskRunTimes.begin();
				for (; r_it != g_TaskInfoManager.map_TaskRunTimes.end(); ++r_it)
				{
					CTaskRunTimes runtimes;
					runtimes.TaskID = r_it->first;
					runtimes.RunTimes = 0;

					g_TaskInfoManager.AddTaskRunTimes(runtimes);
				}

				g_TaskInfoManager.ClearTaskTimes();
				m_strMonDate = strDate;

				//清除昨天的任务标记
				MAP_TASK_IT t_it = g_TaskInfoManager.map_Task.begin();
				for (; t_it != g_TaskInfoManager.map_Task.end(); ++t_it)
				{
					t_it->second.TaskStatus = TASK_WAIT_EXEC;

					//notify config
					CTaskCtlStatus ctlstatus;
					ctlstatus.TaskID = t_it->first;
					ctlstatus.TaskStatus = TASK_WAIT_EXEC;
					ctlstatus.DelayGap = 0;

					g_TaskInfoManager.AddTaskCtlStatus(ctlstatus);
				}

				//清除昨天的延时任务
				g_TaskInfoManager.m_DelayConnTaskList.clear();
				g_TaskInfoManager.m_DelaySnmpTaskList.clear();
			}

			// 遍历立即执行标识任务
			int task_ID;
			while (g_TaskInfoManager.list_Task.get(task_ID))
			{
				MAP_TASK_IT t_it = g_TaskInfoManager.map_Task.find(task_ID);
				if (t_it != g_TaskInfoManager.map_Task.end())
				{
					m_TaskQueue.push_back((task_ID));
				}
			}

			GenerateTasks();

			// 遍历时间策略列表,找到当前需要执行的策略项,并找到与之关联的任务列表
			MAP_TIMEPOLICYENTITY &map_TimePolicyEntity = g_TaskInfoManager.
				GetMapTimePolicyEntity();
			MAP_TIMEPOLICYENTITY_IT it = map_TimePolicyEntity.begin();
			for (; it != map_TimePolicyEntity.end(); it++)
			{
				if (it->second.ShouldRun(tDatetime))
				{
					LIST_ID &List = g_TaskInfoManager.GetTaskListByPolicy(
							it->first);
					if (List.size() > 0)
					{
						LIST_ID_IT it = List.begin();
						for (; it != List.end(); it++)
						{
							MAP_TASK_IT t_it = g_TaskInfoManager.map_Task.find(
									*it);
							if (t_it != g_TaskInfoManager.map_Task.end())
							{
								if (t_it->second.TaskStatus ==
										TASK_WAIT_EXEC
								||	t_it->second.TaskStatus ==
										TASK_DELAY_EXEC)
								{
									m_TaskQueue.push_back((*it));
								}
							}
						}
					}
				}
			}

			GenerateTasks();
		}

		OSSleep(1);
	}
}

void CTaskManagerThread::GenerateTasks(void)
{
	m_TaskQueue.unique();

	//任务队列大小控制
	if (g_TaskInfoManager.ConnTaskCount() +
		g_TaskInfoManager.SnmpTaskCount() <= 100000)
	{
		list<int>::iterator it = m_TaskQueue.begin();
		for (; it != m_TaskQueue.end(); it++)
		{
			int iTaskID = (*it);
			int iTimes = g_TaskInfoManager.GetTaskTimes(iTaskID);

			char keystr[1024];
			sprintf(keystr, "%d_%d", iTaskID, iTimes);

			CTaskCtlStatus ctlstatus;
			ctlstatus.TaskID = iTaskID;
			ctlstatus.TaskStatus = TASK_WAIT_EXEC;
			ctlstatus.DelayGap = 30;
			g_TaskInfoManager.AddTaskCtlStatus(ctlstatus);

			//生成任务	
			g_TaskInfoManager.AddTask(
					iTaskID,
					iTimes,
					m_strMonDate,
					m_strMonTime);
		}

		printf(
			"******ConnTasks in Queue [%d]******\n******SnmpTasks in Queue [%d]******\n",
			g_TaskInfoManager.ConnTaskCount(),
			g_TaskInfoManager.SnmpTaskCount());
		fflush(stdout);
	}
	else
	{
		printf(
			"******TaskQueue to limit, ConnTasks in Queue [%d], SnmpTasks in Queue [%d]\n",
			g_TaskInfoManager.ConnTaskCount(),
			g_TaskInfoManager.SnmpTaskCount());
		fflush(stdout);
	}

	m_TaskQueue.clear();
}

int CTaskInfoManager::GetTaskCurTimes(int TaskID)
{
	map<int, int>::iterator map_it = map_TaskRunTimes.find(TaskID);
	if (map_it != map_TaskRunTimes.end())
	{
		return map_it->second;
	}
	else
	{
		printf("cann't find task id[%d] current times.\n", TaskID);
		return 0;
	}
}

int CTaskInfoManager::GetTaskTimes(int TaskID)
{
	map<int, int>::iterator map_it = map_TaskRunTimes.find(TaskID);
	if (map_it != map_TaskRunTimes.end())
	{
		++(map_it->second);
	}
	else
	{
		map_TaskRunTimes[TaskID] = 1;
	}

	//notify config
	CTaskRunTimes runtimes;

	runtimes.TaskID = TaskID;
	runtimes.RunTimes = map_TaskRunTimes[TaskID];

	AddTaskRunTimes(runtimes);

	return map_TaskRunTimes[TaskID];
}

void CTaskInfoManager::UpdateTaskTimes(int TaskID, int Times)
{
	map_TaskRunTimes[TaskID] = Times;
}

void CTaskInfoManager::AddBaseLineTask(CFTDSysNetBaseLineTaskField b_task)
{
	map_BaseLineTask[b_task.ID.getValue()] = b_task;
}

void CTaskInfoManager::DelBaseLineTask(int id)
{
	MAP_BASELINETASK_ITERATOR it;
	it = map_BaseLineTask.find(id);
	if (it != map_BaseLineTask.end())
	{
		map_BaseLineTask.erase(it);
	}
}

int CTaskInfoManager::ProcessBaseLineTask(
	CFTDSysNetBaseLineTaskField bl_task,
	CFTDSysNetDeviceField dev)
{
	CFTDRtnNetBaseLineTaskField res;
	res.ID = bl_task.ID.getValue();
	res.BaseLineIDList = bl_task.BaseLineIDList.getValue();
	res.GenDate = bl_task.GenDate.getValue();
	res.GenTime = bl_task.GenTime.getValue();
	res.GenUser = bl_task.GenUser.getValue();

	char buff[256] = "\0";
	sprintf(buff, "%d", dev.ID.getValue());
	res.DeviceIDList = buff;

	if (g_pBaseLineTaskThread == NULL)
	{
		g_pBaseLineTaskThread = new CConnBaseLineTaskThread();
		g_pBaseLineTaskThread->Create();
	}

	memset(buff, 0, 256);

#ifdef WIN32
	sprintf(
		buff,
		"%s\\%s_%s",
		TMP_DIRNAME,
		dev.IPADDR.getValue(),
		dev.NAME.getValue());
#else
	sprintf(
		buff,
		"%s/%s_%s",
		TMP_DIRNAME,
		dev.IPADDR.getValue(),
		dev.NAME.getValue());
#endif
	if (opendir(buff) == NULL)
	{
		//放入执行队列
		g_pBaseLineTaskThread->m_listBaseLineTaskRun.add(make_pair(res, dev));
	}
	else
	{
		//已经执行过配置获取，直接回复eventcuoter
		res.OperationType = TASK_SUCCESS;
		g_pBaseLineTaskThread->m_listBaseLineTask.add(res);
	}

	return 0;
}
