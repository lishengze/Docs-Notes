#ifdef LINUX
#include <sys/types.h>
#include <dirent.h>
#endif
#include "CConnTaskThread.h"
#include "CSynConnector.h"
#include "CCrypto.h"

//#include "CRegexConfig.h"
#ifndef LINUX
#include "net_snmp.h"
#endif
CConnBaseLineTaskThread *g_pBaseLineTaskThread = NULL;
extern CTaskInfoManager g_TaskInfoManager;
extern char g_mSSHDefaultUsrName[100];
extern char g_mSSHDefaultPasswd[100];
extern char g_mSSHDefaultAdminPasswd[100];

bool CConnTaskThread::InitInstance(void)
{
	printf("CConnTaskThread[%d] Started!\n", m_nThreadID);
	return true;
}

void CConnTaskThread::ExitInstance(void)
{
	printf("CConnTaskThread[%d] Ended!\n", m_nThreadID);
}

void CConnTaskThread::Run(void)
{
	while (1)
	{
		// 确保多线程模式下,终端模式一致
		m_oTelnetClient.TTYLock();

		CConnTaskInfo TaskInfo;

		//立即执行的特殊任务
		while( g_TaskInfoManager.m_ConnTaskList.get(TaskInfo) )
		{
			RunTask(TaskInfo);
		}

		//LinkParty任务队列
		while (g_TaskInfoManager.m_PartLinkConnTaskList.get(TaskInfo))
		{
			RunTask(TaskInfo);
		}

		//conn优先级队列
		while (g_TaskInfoManager.GetConnTask(TaskInfo))
		{
			RunTask(TaskInfo);
		}

		//conn延时队列
		while (g_TaskInfoManager.GetDelayConnTask(TaskInfo))
		{
			time_t	timep;
			char curtime[10];

			time(&timep);

			struct tm tm_time;
			LocalTime(&timep, &tm_time);
			strftime(curtime, 10, "%H:%M:%S", &tm_time);

			int comtime = TaskInfo.TaskTime.compare(curtime);
			if (comtime > 0)
			{
				//还没到执行时间
				g_TaskInfoManager.AddDelayConnTask(TaskInfo);

				if (g_TaskInfoManager.ConnTaskCount() <= 1)
				{
					break;
				}
				else
				{
					continue;
				}
			}
			else
			{
				RunTask(TaskInfo);
			}
		}

		m_oTelnetClient.TTYUnLock();
		OSSleep(1);
	}
}

void CConnTaskThread::SendTaskResult(
	CFTDRtnNetMonitorTaskResultField &field,
	string	cmd,
	string	result)
{
	int flag = field.Flag.getValue();
	if (flag >= TASK_WAIT_EXEC && flag <= TASK_START_EXEC)
	{
		int taskID = field.Task_ID.getValue();
		MAP_TASK_STATUS_ITERATOR it = g_TaskInfoManager.map_TaskStatus.find(
				taskID);
		if (it == g_TaskInfoManager.map_TaskStatus.end())
		{
			//生成任务状态统计对象
			CTaskCountStatus taskStatus;
			taskStatus.items = 1;
			taskStatus.status = flag;
			g_TaskInfoManager.map_TaskStatus[taskID] = taskStatus;

			//生成任务状态对象
			CTaskCtlStatus	ctlstatus;
			ctlstatus.TaskID = taskID;
			ctlstatus.TaskStatus = flag;
			ctlstatus.DelayGap = TASK_STATUS_CHANGE_SUCCESS;
			g_TaskInfoManager.AddTaskCtlStatus(ctlstatus);
		}
		else if (flag == TASK_DONE_EXEC)
		{
			int taskItems = 0;
			if (it->second.status != TASK_DONE_EXEC)
			{
				it->second.status = TASK_DONE_EXEC;
				it->second.items = 1;
			}
			else
			{
				it->second.items++;
			}

			//获取任务的items数
			if (g_TaskInfoManager.map_TaskItems.find(
					taskID) != g_TaskInfoManager.map_TaskItems.end())
			{
				taskItems = g_TaskInfoManager.map_TaskItems[taskID];
			}

			if (it->second.items >= taskItems)
			{
				//生成任务状态对象
				CTaskCtlStatus	ctlstatus;
				ctlstatus.TaskID = taskID;
				ctlstatus.TaskStatus = flag;
				ctlstatus.DelayGap = TASK_STATUS_CHANGE_SUCCESS;
				g_TaskInfoManager.AddTaskCtlStatus(ctlstatus);
				g_TaskInfoManager.map_TaskStatus.erase(it);
			}
		}
	}
	else
	{
		field.InstructChain = cmd.c_str();

		g_TaskInfoManager.AddTaskResult(field, result);
	}
}

void CConnTaskThread::SendConfigFile(
	string	objectid,
	string	date,
	string	time,
	string	content,
	int version,
	int taskid)
{
	TaskConfigContent taskconfig;
	taskconfig.objectid = objectid;
	taskconfig.filedate = date;
	taskconfig.filetime = time;
	taskconfig.filecontent = content;
	taskconfig.fileversion = version;
	taskconfig.task_id = taskid;

	m_listTaskConfigContent.add(taskconfig);
}

void CConnTaskThread::CheckVersion(
	CConnTaskInfo TaskInfo,
	string	cmd,
	string	result)
{
	CFTDRtnNetMonitorTaskResultField field;

	field.ObjectID = TaskInfo.ObjectID.c_str();
	field.Task_ID = TaskInfo.TaskID;
	field.OperateTime = TaskInfo.RunTimes;
	field.MonDate = m_date;
	field.MonTime = m_time;
	field.Flag = TASK_CONFIG_DISMATCH;

	string	currFileName = m_oTelnetClient.GetFileName();
	string	lastFileName;

	// 尝试找到之前最近一次获取的配置文件
	if (m_oTelnetClient.GetLastFileName(currFileName, lastFileName))
	{
		// 设置文件对比引擎的文件对
		m_oFileDiff.SetFiles(currFileName.c_str(), lastFileName.c_str());

		//		printf("File1:%s  File2:%s\n", currFileName.c_str(), lastFileName.c_str());
		// 进行文件比较,返回两文件的差异行数
		int nDiff = m_oFileDiff.Compare();
		if (nDiff == 0)
		{
			// 文件一致
			//			m_oFileDiff.Show();		// 输出对比结果
			CFTDRtnSyslogEventField syslogEvent;
			memset(&syslogEvent, 0x00, sizeof(syslogEvent));
			syslogEvent.ObjectID = TaskInfo.ObjectID.c_str();
			syslogEvent.MonDate = m_date;
			syslogEvent.MonTime = m_time;
			syslogEvent.OccurDate = m_date;
			syslogEvent.OccurTime = m_time;
			syslogEvent.EventName = EVENT_CHKVER_NOCHG;
			syslogEvent.FullEventName = "设备配置无变化";

			/// Mod by Henchi, 20111227
						/// 事件处理标识调整为"G"，表示系统生成的日志事件
			syslogEvent.ProcessFlag = "G";
			syslogEvent.WarningLevel = "Level4";
			syslogEvent.EventDes = "Comment='Device running-config have not changed.'";
			syslogEvent.EventDealDes = "";
			syslogEvent.IPAddress = TaskInfo.IPAddress.c_str();
			m_listSyslogEvent.add(syslogEvent);

			field.Flag = TASK_CONFIG_MATCH;
		}
		else if (nDiff >= 0)
		{
			// 文件不一致
			//			m_oFileDiff.Show();		// 输出对比结果
			CFTDRtnSyslogEventField syslogEvent;
			memset(&syslogEvent, 0x00, sizeof(syslogEvent));
			syslogEvent.ObjectID = TaskInfo.ObjectID.c_str();
			syslogEvent.MonDate = m_date;
			syslogEvent.MonTime = m_time;
			syslogEvent.OccurDate = m_date;
			syslogEvent.OccurTime = m_time;
			syslogEvent.EventName = EVENT_CHKVER_CHANGE;
			syslogEvent.FullEventName = "设备配置发生变化";

			/// Mod by Henchi, 20111227
						/// 事件处理标识调整为"G"，表示系统生成的日志事件
			syslogEvent.ProcessFlag = "G";
			syslogEvent.WarningLevel = "Level4";
			syslogEvent.EventDes = "Comment='Device running-config has changed.'";
			syslogEvent.EventDealDes = "";
			syslogEvent.IPAddress = TaskInfo.IPAddress.c_str();

			m_listSyslogEvent.add(syslogEvent);

			CFTDRtnWarningEventField warningEvent;
			memset(&warningEvent, 0x00, sizeof(warningEvent));
			warningEvent.ObjectID = TaskInfo.ObjectID.c_str();
			warningEvent.MonDate = m_date;
			warningEvent.MonTime = m_time;
			warningEvent.OccurDate = m_date;
			warningEvent.OccurTime = m_time;
			warningEvent.EventName = EVENT_CHKVER_CHANGE;
			warningEvent.FullEventName = "设备配置发生变化";
			warningEvent.ProcessFlag = "N";
			warningEvent.WarningLevel = "Level4";
			warningEvent.EventDes = "Comment='Device running-config has changed.'";
			warningEvent.EventDealDes = "";
			warningEvent.IPAddress = TaskInfo.IPAddress.c_str();

			m_listWarningEvent.add(warningEvent);
		}
		else
		{
			printf("FileDiff Error(%d)\n", nDiff);	// 发生异常
		}

		SendTaskResult(field, TaskInfo.cmdAlias, "");
	}
	else
	{
		field.Flag = TASK_CONFIG_MATCH;
		printf("Failed to GetLastFileName with [%s]\n", currFileName.c_str());	// 发生异常
	}

	//将配置文件内容及其比对结果发送给event
	SendConfigFile(TaskInfo.ObjectID, m_date, m_time, result, field.Flag);
}

int CConnTaskThread::RunTask(CConnTaskInfo TaskInfo)
{
	int ret_flag = -1;

	char keystr[1024];
	sprintf(keystr, "%d_%d", TaskInfo.TaskID, TaskInfo.RunTimes);

	time_t	timep;

	time(&timep);

	struct tm tm_time;
	LocalTime(&timep, &tm_time);
	strftime(m_time, 10, "%H:%M:%S", &tm_time);
	strftime(m_date, 10, "%Y%m%d", &tm_time);

	CFTDRtnNetMonitorTaskResultField field;

	field.ObjectID = TaskInfo.ObjectID.c_str();
	field.Task_ID = TaskInfo.TaskID;
	field.OperateTime = TaskInfo.RunTimes;
	field.MonDate = m_date;
	field.MonTime = m_time;

	//notify client
	field.Flag = TASK_DOING_EXEC;
	SendTaskResult(field, "", "");

	//modify task status
	g_TaskInfoManager.UpdateTaskStatus(
			TaskInfo.TaskID,
			TaskInfo.ObjectID,
			TaskInfo.Cmds,
			TASK_DOING_EXEC,
			TASK_TYPE_CONN);

	printf(
		"+++ ConnTaskThread[%d] Init: Task%02d[%04d] [%s %s]\n\t%s %d %s %s %s\n\t[%s]\n",
		m_nThreadID,
		TaskInfo.TaskID,
		TaskInfo.RunTimes,
		TaskInfo.TaskDate.c_str(),
		TaskInfo.TaskTime.c_str(),
		TaskInfo.IPAddress.c_str(),
		TaskInfo.Port,
		TaskInfo.UserName.c_str(),
		TaskInfo.Password.c_str(),
		TaskInfo.CfgPassword.c_str(),
		TaskInfo.Cmds.c_str());

	CTelnetConnEntry entry = CTelnetConnEntry(
			TaskInfo.IPAddress.c_str(),
			TaskInfo.Port,
			ssh,
			TaskInfo.UserName.c_str(),
			TaskInfo.Password.c_str(),
			TaskInfo.CfgPassword.c_str(),
			TaskInfo.Cmds.c_str());

	// 初始化任务的采集对象
	int id = g_TaskInfoManager.GetDeviceManuIDByIP(TaskInfo.IPAddress.c_str());
	m_oTelnetClient.Init(entry, id);

	// 重置输出文件目录
	if (strcasecmp(TaskInfo.cmdAlias.c_str(), "RunningConfig") == 0)
	{
		m_oTelnetClient.SetOutputPath(TMP_DIRNAME);
	}
	else
	{
		m_oTelnetClient.SetOutputPath(RESULT_DIRNAME);
	}

	// 进行一次任务执行
	int ret = m_oTelnetClient.DoTask();
	if (ret == 0)
	{
		ret_flag = TASK_SUCCESS;	//记录执行结果
		map<string, CCiscoPingResult> &map_CommPing = m_oTelnetClient.
			getPingCommMap();
		map<string, string> &map_Comm = m_oTelnetClient.getCommMap();

		map<string, CCiscoPingResult>::iterator map_ping_it = map_CommPing.begin();
		for (; map_ping_it != map_CommPing.end(); map_ping_it++)
		{
			CFTDRtnNetRomotePingResultInfoField pingField;
			memset(&pingField, 0, sizeof(CFTDRtnNetRomotePingResultInfoField));

			pingField.SouIPADDR = TaskInfo.IPAddress.c_str();
			pingField.SouNAME = CSynConnector::GetInstancePoint()->GetDevNameByIP(TaskInfo.IPAddress.c_str());
			pingField.TarIPADDR = (map_ping_it->second.GetAddress()).c_str();
			pingField.TarNAME = CSynConnector::GetInstancePoint()->GetDevNameByIP((map_ping_it->second.GetAddress()).c_str());
			pingField.PTimeSta = m_time;
			pingField.PDateSta = m_date;

			pingField.ConnRate = map_ping_it->second.GetSuccCount();

			char value_buff[64] = "\0";
			int _PingThreshold = 0;	// 阀值
			int _PingResult = 1;	// 比较结果，1为正常，0为不正常。在无阀值的情况下，结果仍为1
			// 查找是否包含该<源IP，目的IP>对应的ping阀值
			pair<string, string> _ThresholdIndex (TaskInfo.IPAddress, map_ping_it->second.GetAddress());
			MAP_PINGTHRESHOLD_IT it_pingThreshold = g_TaskInfoManager.map_PingThreshold.find(_ThresholdIndex);
			if (it_pingThreshold != g_TaskInfoManager.map_PingThreshold.end())
			{
				_PingThreshold = it_pingThreshold->second;
				_PingResult = (map_ping_it->second.GetAvgDelay() <= _PingThreshold) ? 1 : 0;
			}
			// 如果连通率为0，则将ping结果置为0（不正常）
			if (map_ping_it->second.GetSuccCount() == 0)
				_PingResult = 0;
			// avgDelay:threshold:result
			sprintf(value_buff, "%d:%d:%d", map_ping_it->second.GetAvgDelay(), _PingThreshold, _PingResult);
			pingField.TimeDlyAvg = value_buff;
			
			memset(value_buff, 0, 64);
			sprintf(value_buff, "%d", map_ping_it->second.GetMaxDelay());
			pingField.TimeDlyMax = value_buff;
			memset(value_buff, 0, 64);
			sprintf(value_buff, "%d", map_ping_it->second.GetMinDelay());
			pingField.TimeDlyMin = value_buff;

			g_TaskInfoManager.AddRemotePingResult(pingField);
		}

		map<string, string>::iterator map_it = map_Comm.begin();
		for (; map_it != map_Comm.end(); map_it++)
		{
			// 发送任务成功消息
			field.Flag = TASK_SUCCESS;

			/// Added by Henchi, 20111229
						/// 不发送 "term length 0" 的指令结果
			if ((map_it->first).compare("term length 0") != 0
			&&	(map_it->first).compare("set console page 0") != 0)
			{
				SendTaskResult(field, TaskInfo.cmdAlias, map_it->second);
			}

			//从结果中提取指标信息
			//ParseCommandResult(map_it->first, map_it->second, TaskInfo.ObjectID, TaskInfo.IPAddress);
			//别名"RunningConfig"导致非配置内容的数据误作为巡警结果下发出去 2015.1.5 by Lee
			if ( strncasecmp(map_it->first.c_str(), "show running-config", strlen("show running-config")) == 0
			||  strncasecmp(map_it->first.c_str(), "get config", strlen("get config")) == 0
			||  strncasecmp(map_it->first.c_str(), "cat bigip.conf", strlen("cat bigip.conf")) == 0
			||  strncasecmp(map_it->first.c_str(), "show configuration", strlen("show configuration")) == 0 )
			//if( strcasecmp( TaskInfo.cmdAlias.c_str(), "RunningConfig") == 0
			//	&&( TaskInfo.Cmds.length()>0 && TaskInfo.Cmds.compare("term length 0")!=0 ) )
			{
				// 配置文件备份成功
				CFTDRtnSyslogEventField syslogEvent;
				memset(&syslogEvent, 0x00, sizeof(syslogEvent));
				syslogEvent.ObjectID = TaskInfo.ObjectID.c_str();
				syslogEvent.MonDate = m_date;
				syslogEvent.MonTime = m_time;
				syslogEvent.OccurDate = m_date;
				syslogEvent.OccurTime = m_time;
				syslogEvent.EventName = EVENT_BACKUP_SUCCEED;
				syslogEvent.FullEventName = "设备配置备份成功";

				/// Mod by Henchi, 20111227
								/// 事件处理标识调整为"G"，表示系统生成的日志事件
				syslogEvent.ProcessFlag = "G";
				syslogEvent.WarningLevel = "Level4";
				syslogEvent.EventDes = "Comment='Buckup running-config succeeded.'";
				syslogEvent.EventDealDes = "";
				syslogEvent.IPAddress = TaskInfo.IPAddress.c_str();

				m_listSyslogEvent.add(syslogEvent);

				// 发送备份成功消息
				field.Flag = TASK_CFGBACKUP_SUCCESS;
				SendTaskResult(field, TaskInfo.cmdAlias, "");

				//将配置文件内容直接发送给event，比较及产生的告警由event自己完成，
				//20130221 by Lee
				SendConfigFile(TaskInfo.ObjectID, m_date, m_time, map_it->second, TaskInfo.RunTimes, TaskInfo.TaskID);

				//CheckVersion(TaskInfo, map_it->first, map_it->second);

			}
		}
	}

	//else if(TaskInfo.TaskID==0 && strcasecmp(TaskInfo.cmdAlias.c_str(), "IfsInfo")==0)
	//{
	//	field.Flag = TASK_SUCCESS;	
	//	char data[ ] ="Interface              IP-Address      OK? Method Status                Protocol\r\n\
	//				  Vlan1                  unassigned      YES NVRAM  administratively down down\r\n\
	//				  Vlan247                172.25.47.250   YES manual up                    up\r\n\
	//				  FastEthernet1/0/1      unassigned      YES unset  down                  down\r\n\
	//				  FastEthernet1/0/2      unassigned      YES unset  up                    up      ";
	//	SendTaskResult( field, TaskInfo.cmdAlias,data);
	//}
	else
	{
		// 发送任务失败消息
		switch (ret)
		{
			case Start:
				field.Flag = TASK_CONNECT_FAIL;
				break;
			case ReqUser:
			case RspUser:
				field.Flag = TASK_USERNAME_ERROR;
				break;
			case ReqPswd:
			case RspPswd:
				field.Flag = TASK_USERPASSWD_ERROR;
				break;
			case ReqCmd:
			case RspCmd:
				field.Flag = TASK_USERCOMMAND_FAIL;
				break;
			case ReqCfgPswd:
			case RspCfgPswd:
				field.Flag = TASK_ADMINPASSWD_ERROR;
				break;
			case ReqCfgCmd:
				field.Flag = TASK_ADMINCOMMAND_ERROR;
				break;
			case -1:
				field.Flag = TASK_RESULT_WRITE_FILE_ERROR;
			default:
				field.Flag = TASK_OTHER_ERROR;
				break;
		}

		ret_flag = field.Flag;		//记录执行结果
		map<string, string> &map_Comm = m_oTelnetClient.getCommMap();
		map<string, string>::iterator map_it = map_Comm.begin();
		for (; map_it != map_Comm.end(); map_it++)
		{
			//发送任务失败消息
			field.Flag = ret_flag;

			/// Added by Henchi, 20111229
						/// 不发送 "term length 0" 的指令结果
			if ((map_it->first).compare("term length 0") != 0
			&&	(map_it->first).compare("set console page 0") != 0)
			{
				SendTaskResult(field, TaskInfo.cmdAlias, map_it->second);
			}

			if ((map_it->first).compare("show running-config") == 0
			||	(map_it->first).compare("get config") == 0
			||	(map_it->first).compare("cat bigip.conf") == 0)
			//if( strcasecmp( TaskInfo.cmdAlias.c_str(), "RunningConfig") == 0 )
			{
				// 配置文件备份失败
				CFTDRtnSyslogEventField syslogEvent;
				memset(&syslogEvent, 0x00, sizeof(syslogEvent));
				syslogEvent.ObjectID = TaskInfo.ObjectID.c_str();
				syslogEvent.MonDate = m_date;
				syslogEvent.MonTime = m_time;
				syslogEvent.OccurDate = m_date;
				syslogEvent.OccurTime = m_time;
				syslogEvent.EventName = EVENT_BACKUP_FAILED;
				syslogEvent.FullEventName = "设备配置备份失败";

				/// Mod by Henchi, 20111227
								/// 事件处理标识调整为"G"，表示系统生成的日志事件
				syslogEvent.ProcessFlag = "G";
				syslogEvent.WarningLevel = "Level4";
				syslogEvent.EventDes = "Comment='Buckup running-config failed.'";
				syslogEvent.EventDealDes = "";
				syslogEvent.IPAddress = TaskInfo.IPAddress.c_str();

				m_listSyslogEvent.add(syslogEvent);

				// 发送备份失败消息
				field.Flag = TASK_CFGBACKUP_FAIL;
				SendTaskResult(field, TaskInfo.cmdAlias, "");
			}
		}

		printf(
			"dotask fail for taskid:%d, failflag:%d, dotaskret=%d, deviceip:%s, cmd:%s\n",
			TaskInfo.TaskID,
			ret_flag,
			ret,
			TaskInfo.IPAddress.c_str(),
			TaskInfo.Cmds.c_str());
	}

	//notify client
	field.Flag = TASK_DONE_EXEC;
	SendTaskResult(field, "", "");

	//modify task status
	g_TaskInfoManager.UpdateTaskStatus(
			TaskInfo.TaskID,
			TaskInfo.ObjectID,
			TaskInfo.Cmds,
			TASK_DONE_EXEC,
			TASK_TYPE_CONN);

	return ret_flag;
}




void CConnBaseLineTaskThread::Run(void)
{
	CConnTaskInfo TaskInfo;
	TaskInfo.TaskID = 0;
	TaskInfo.RunTimes = 0;
	TaskInfo.Cmds = "term length 0;show running-config";
	TaskInfo.cmdAlias = "RunningConfig";
	TaskInfo.TaskStatus = TASK_WAIT_EXEC;

	CFTDRtnNetBaseLineTaskField rtn_bl_task;

	while (true)
	{
		pair<CFTDRtnNetBaseLineTaskField, CFTDSysNetDeviceField> bl_pair;
		while (m_listBaseLineTaskRun.get(bl_pair))
		{
			TaskInfo.TaskDate = bl_pair.first.GenDate.getValue();
			TaskInfo.TaskTime = bl_pair.first.GenTime.getValue();
			TaskInfo.ObjectID = bl_pair.second.ObjectID.getValue();
			TaskInfo.IPAddress = bl_pair.second.IPADDR.getValue();
			TaskInfo.Port = bl_pair.second.PORTNUMBER.getValue();
			TaskInfo.Protocal = bl_pair.second.CFGSAVETYPE.getValue();
			TaskInfo.UserName = bl_pair.second.USERNAME.getValue();
			//TaskInfo.Password = bl_pair.second.PASSWD.getValue();
			//TaskInfo.CfgPassword = bl_pair.second.ENPASSWD.getValue();

			//密码改成加密模式  20130401
			CDesEncryptAlgorithm key;
			key.SetPassword("monitor");
			char buff[256]="\0";
			key.Decrypt((char *)(bl_pair.second.PASSWD.getValue()),buff);
			TaskInfo.Password = buff;
			memset(buff, 256, 0);
			key.Decrypt((char *)(bl_pair.second.ENPASSWD.getValue()),buff);
			TaskInfo.CfgPassword = buff;

			TaskInfo.UserName = TaskInfo.UserName.length() == 0 ? g_mSSHDefaultUsrName : TaskInfo.UserName;
			TaskInfo.Password = TaskInfo.Password.length() == 0 ? g_mSSHDefaultPasswd : TaskInfo.Password;
			TaskInfo.CfgPassword = TaskInfo.CfgPassword.length() == 0 ? g_mSSHDefaultAdminPasswd : TaskInfo.CfgPassword;

			int ret = RunTask(TaskInfo);

			rtn_bl_task = bl_pair.first;
			rtn_bl_task.OperationType = ret;
			m_RspBaselinepLock.Lock();

			//printf("get the lock [%s]\n")
			m_listBaseLineTask.add(rtn_bl_task);
			m_RspBaselinepLock.UnLock();
		}

		OSSleep(1);
	}
}

bool CConnBaseLineTaskThread::InitInstance(void)
{
	printf("CConnBaseLineTaskThread Started!\n");
	return true;
}

void CConnBaseLineTaskThread::ExitInstance(void)
{
	printf("CConnBaseLineTaskThread[%d] Ended!\n");
}

/*
void CConnTaskThread::ParseCommandResult(string command, string result, string objectid, string deviceip)
{
	time_t timep;

	time(&timep);
	struct tm *curTime=localtime(&timep);

	char curTimeStr[10];
	char curDateStr[10];

	strftime(curTimeStr,10, "%H:%M:%S", curTime);
	strftime(curDateStr,10, "%Y%m%d"  , curTime);

	map<string, vector<CRegexNode> >::iterator r_i = CRegexConfigManager::Instance()->m_mRegexList.find(command);
	if(r_i != CRegexConfigManager::Instance()->m_mRegexList.end())
	{		
		for(int i = 0; i < r_i->second.size(); ++i)
		{
			cmatch what;	
			int flag_type = regex_constants::normal;

			if(r_i->second[i].ismatchsingle)
			{
				flag_type |= regex_constants::match_single_line;
			}

			if(r_i->second[i].ignorecase)
			{
				flag_type |= regex::icase;
			}

			regex expression(r_i->second[i].condition.c_str(), flag_type);
			if(regex_match(result.c_str(), what, expression))
			{
				for(int m=1;m<what.size();m++)
				{
					//printf("what %d value %s\n", m, what[m].str().c_str());
					if(r_i->second[i].attrnamelist.size() < m)
					{
						printf("attrname config error for command:%s condition:%s\n"
							, command.c_str(), r_i->second[i].condition.c_str());
						return;
					}
					else
					{
						if(r_i->second[i].attrnamelist[m - 1].compare("regex_next_input_value") == 0)
						{
							result = what[m].str();
						}
						else
						{
							if(command.compare("show ip interface brief") == 0)
							{
								if(m != 1)
								{
									continue;
								}

								ParseShowIPInterfaceResult(what, objectid, curDateStr, curTimeStr, deviceip);
							}
							else
							{
								CFTDRtnObjectAttrField fieldinfo;

								//generate attr value
								fieldinfo.ObjectID = objectid.c_str();
								fieldinfo.MonDate = curDateStr;
								fieldinfo.MonTime = curTimeStr;
								fieldinfo.AttrType = r_i->second[i].attrnamelist[m - 1].c_str();

								fieldinfo.ValueType = STRING_ATTR;
								fieldinfo.AttrValue = what[m].str().c_str();

								printf("$$$$$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
								m_listObjectAttr.add(fieldinfo);
							}
						}
					}
				}

				if(r_i->second[i].isloop)
				{
					while(result.size() > 0)
					{
						cmatch what2;
						if(regex_match(result.c_str(), what2, expression))
						{
							for(int n=1;n<what2.size();n++)
							{
								if(r_i->second[i].attrnamelist.size() < n)
								{
									printf("attrname config error for command:%s condition:%s\n"
										, command.c_str(), r_i->second[i].condition.c_str());
									return;
								}
								else
								{
									if(r_i->second[i].attrnamelist[n - 1].compare("regex_next_input_value") == 0)
									{
										result = what2[n].str();
									}
									else
									{
										if(command.compare("show ip interface brief") == 0)
										{
											if(n != 1)
											{
												continue;
											}

											ParseShowIPInterfaceResult(what2, objectid, curDateStr, curTimeStr, deviceip);
										}
										else
										{
											CFTDRtnObjectAttrField fieldinfo;
											memset(&fieldinfo, 0, sizeof(CFTDRtnObjectAttrField));

											//generate attr value
											fieldinfo.ObjectID = objectid.c_str();
											fieldinfo.MonDate = curDateStr;
											fieldinfo.MonTime = curTimeStr;
											fieldinfo.AttrType = r_i->second[i].attrnamelist[n - 1].c_str();

											fieldinfo.ValueType = STRING_ATTR;
											fieldinfo.AttrValue = what2[n].str().c_str();

											printf("$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
											m_listObjectAttr.add(fieldinfo);
										}
									}
								}
							}	
						}
						else
						{
							printf("command:%s not match condition:%s, result:%s\n"
								, command.c_str(), r_i->second[i].condition.c_str(), result.c_str());

							if(r_i->second[i].notmatchattrname.size() > 0)
							{
								CFTDRtnObjectAttrField fieldinfo;

								//generate attr value
								fieldinfo.ObjectID = objectid.c_str();
								fieldinfo.MonDate = curDateStr;
								fieldinfo.MonTime = curTimeStr;
								fieldinfo.AttrType = r_i->second[i].notmatchattrname.c_str();

								fieldinfo.ValueType = STRING_ATTR;
								fieldinfo.AttrValue = "";

								printf("$$$$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
								m_listObjectAttr.add(fieldinfo);
							}

							break;
						}
					}

					//循环匹配一定出现在最底层的条件中
					return;
				}

			}
			else
			{
				printf("command:%s not match condition:%s, result:%s\n"
					, command.c_str(), r_i->second[i].condition.c_str(), result.c_str());

				if(r_i->second[i].notmatchattrname.size() > 0)
				{
					CFTDRtnObjectAttrField fieldinfo;

					//generate attr value
					fieldinfo.ObjectID = objectid.c_str();
					fieldinfo.MonDate = curDateStr;
					fieldinfo.MonTime = curTimeStr;
					fieldinfo.AttrType = r_i->second[i].notmatchattrname.c_str();

					fieldinfo.ValueType = STRING_ATTR;
					fieldinfo.AttrValue = "";

					printf("$$$$$$$$$$$$$$generate attrname:%s, attrvalue:%s\n", fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue());
					m_listObjectAttr.add(fieldinfo);
				}

				//当前条件不匹配，不进行剩余条件的匹配
				return;
			}
		}
	}
}

void CConnTaskThread::ParseShowIPInterfaceResult(cmatch what, string objectid, string curdate, string curtime, string deviceip)
{
	string interface_id = what[1].str();
								
	char *p = NULL;
	while((p= strchr((char *)interface_id.c_str(),'.') )!= NULL)
	{
		*p = '_';
	}
	
	string status = what[2].str();
	string protocol = what[3].str();

	string attrvalue;
	
	string eventname = "";
	string fulleventname = "";
	string eventlevel;
	string eventinfo;

	if(status.compare("up") == 0)
	{
		if(protocol.compare("up") == 0)
		{
			attrvalue = "0";
		}
		else if(protocol.compare("down") == 0)
		{
			attrvalue = "2";
		}
		else
		{
			printf("invalid protocol:%s for show ip interface brief\n", protocol.c_str());
			return;
		}
	}
	else if(status.compare("down") == 0)
	{
		attrvalue = "1";
		
		eventname = "LINK_UPDOWN";
		fulleventname = "链路状态切换";
		eventlevel = "Level2";
		
		eventinfo = "Interface ";
		eventinfo += interface_id;
		eventinfo += ", changed state to down";
	}
	else if(status.compare("administratively") == 0)
	{
		attrvalue = "3";
		
		eventname = "LINKADMIN_UPDOWN";
		fulleventname = "链路状态切换";
		eventlevel = "Level4";
		
		eventinfo = "Interface ";
		eventinfo += interface_id;
		/// Mod by Henchi, 20111227
		/// 事件描述添加administratively标识，以作区分
		eventinfo += ", changed state to administratively down";
	}
	else
	{
		printf("invalid status:%s for show ip interface brief\n", status.c_str());
		return;
	}
	
	CFTDRtnObjectAttrField fieldinfo;

	memset(&fieldinfo, 0, sizeof(CFTDRtnObjectAttrField));

	//generate attr value
	string total_id = objectid;
	total_id += ".";
	total_id += interface_id;

	fieldinfo.ObjectID = total_id.c_str();
	fieldinfo.MonDate = curdate.c_str();
	fieldinfo.MonTime = curtime.c_str();
	fieldinfo.AttrType = "interfaceStatus";

	fieldinfo.ValueType = INT_ATTR;
	fieldinfo.AttrValue = attrvalue.c_str();

	printf("$$$$$$$$$$$$$generate 11111 attrname:%s, attrvalue:%s, total_id:%s\n"
		, fieldinfo.AttrType.getValue(), fieldinfo.AttrValue.getValue(), total_id.c_str());
	m_listObjectAttr.add(fieldinfo);

	//generate warning event according to "status"
	if(eventname.length() > 0)
	{
		CFTDRtnWarningEventField warninglogEvent;

		memset(&warninglogEvent, 0, sizeof(CFTDRtnWarningEventField));

		warninglogEvent.ObjectID = total_id.c_str();
		warninglogEvent.MonDate = curdate.c_str();
		warninglogEvent.MonTime = curtime.c_str();

		warninglogEvent.OccurDate = curdate.c_str();
		warninglogEvent.OccurTime = curtime.c_str();
		
		warninglogEvent.EventName = eventname.c_str();
		warninglogEvent.FullEventName = fulleventname.c_str();

		warninglogEvent.EventType = "1";
		warninglogEvent.WarningLevel = eventlevel.c_str();
		
		warninglogEvent.EventDes = eventinfo.c_str();
		/// Mod by Henchi, 20111227
		/// 事件处理标识调整为"I"，表示初始状态事件
		warninglogEvent.ProcessFlag = "I";
		warninglogEvent.IPAddress = deviceip.c_str();

		m_listWarningEvent.add(warninglogEvent);
	}

	//generate warning event according to "proto"
	if(protocol.compare("down") == 0)
	{
		eventname = "LINEPROTO_UPDOWN";
		fulleventname = "链路协议状态切换";
		eventlevel = "Level3";
		
		eventinfo = "Line protocol on Interface ";
		eventinfo += interface_id;
		eventinfo += ", changed state to down";

		CFTDRtnWarningEventField warninglogEvent;

		memset(&warninglogEvent, 0, sizeof(CFTDRtnWarningEventField));

		warninglogEvent.ObjectID = total_id.c_str();
		warninglogEvent.MonDate = curdate.c_str();
		warninglogEvent.MonTime = curtime.c_str();

		warninglogEvent.OccurDate = curdate.c_str();
		warninglogEvent.OccurTime = curtime.c_str();
		
		warninglogEvent.EventName = eventname.c_str();	
		warninglogEvent.FullEventName = fulleventname.c_str();

		warninglogEvent.EventType = "1";
		warninglogEvent.WarningLevel = eventlevel.c_str();
		
		warninglogEvent.EventDes = eventinfo.c_str();
		/// Mod by Henchi, 20111227
		/// 事件处理标识调整为"I"，表示初始状态事件
		warninglogEvent.ProcessFlag = "I";
		warninglogEvent.IPAddress = deviceip.c_str();

		m_listWarningEvent.add(warninglogEvent);		
	}
}

*/
