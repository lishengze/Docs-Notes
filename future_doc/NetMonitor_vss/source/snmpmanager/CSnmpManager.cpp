/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CSnmpManager.cpp
///@brief	实现了SnmpManager使用的类
///@history
///20100920	周建军		创建该文件
#include "CSnmpManager.h"
#include "CachedFileFlow.h"
#include "CGetDeviceInfo.h"
#include "CSysLogReader.h"
#include "CSysLogConfig.h"
#include "CTaskManager.h"

#define FLOWCHANGETIME	(3 * 3600)
extern bool g_bThreadActiveFlag;
extern CSysLogReader *g_pSyslogReader;			//Syslog解析线程指针
extern CTelnetDevice g_Devices[MAX_DEVICE_NUM]; // 保存设备配置信息的数组
extern CTaskInfoManager g_TaskInfoManager;
extern CConnBaseLineTaskThread	*g_pBaseLineTaskThread;
extern bool g_isMasterRole;

//key = ip;
//valeu =objid;
std::map<std::string, std::string>	ip_objId;

SInfoHost g_hosts[6] =
{
	SInfoHost("172.1.128.1", "thbczh2005"),
	SInfoHost("172.1.128.2", "thbczh2005"),
	SInfoHost("172.1.128.3", "thbczh2005"),
	SInfoHost("172.1.128.4", "thbczh2005"),
	SInfoHost("172.1.128.5", "thbczh2005"),
	SInfoHost("172.1.128.6", "thbczh2005"),

	//SInfoHost("172.16.80.201",	 "sfit"),
	//SInfoHost("172.16.80.202",	 "sfit"),
	//SInfoHost("172.16.80.203",	 "sfit")
	//1.3.6.1.2.1.1.1.0", "sysDescr"
	//1.3.6.1.2.1.1.2.0", "sysObjectID"
	//1.3.6.1.2.1.1.3.0", "sysUpTime"
	//1.3.6.1.2.1.1.4.0", "sysContact"
	//1.3.6.1.2.1.1.5.0", "SysName"
	//1.3.6.1.2.1.1.6.0", "sysLocation"
	//1.3.6.1.2.1.1.7.0", "sysServices"
	//1.3.6.1.2.1.2.1.0", "ifNum"
	//1.3.6.1.2.1.2.2.0", "ifTable"
	//1.3.6.1.2.1.4.1.0", "ipForwarding"
	//1.3.6.1.4.1.9.3.6.6.0", "processorRam"
	//1.3.6.1.4.1.9.3.6.7.0", "nvRAMSize"
	//1.3.6.1.4.1.9.9.48.1.1.1.5.1", "UsedMemory"
	//1.3.6.1.4.1.9.9.48.1.1.1.6.1", "FreeMemory"
	//1.3.6.1.2.1.2.2.1.8.10002", "ifOperStatus" cisco
};

CManagerTimmer::CManagerTimmer(CReactor *pReactor) :
	CEventHandler(pReactor)
{
	m_nEventId = 0;
	m_pThread = NULL;
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
}

void CManagerTimmer::OnTimer(int nIDEvent)
{
	if (nIDEvent == 3)		///定时判断监控指标的变化
	{
		printf("run the branch 3 of timer.\n");

		m_pcSyn->DispatchMonTask();
		m_pcSyn->DispatchLoopTask();
	}
	else if (nIDEvent == 2) ///定时判断时间，是否切换到对应的流编号
	{
		//
		time_t nNow = time((time_t *)NULL);
		if (nNow - m_nLastChangeTime >= FLOWCHANGETIME) //需要切换
		{
			m_nLastChangeTime = nNow;
			m_nFlowPosition++;
			m_nFlowPosition = m_nFlowPosition % MAX_EVENTFLOWNUM;
			printf(
				"OnTimer::now %d 替换到新的流编号 %u \n",
				(int)nNow,
				m_nFlowPosition);
			fflush(stdout);

			// 清流，同时要求订阅者清流
			m_pCurrFlow = m_pFlowArray[m_nFlowPosition];
			m_pCurrFlow->Truncate(0);

			// 发送消息到所有下属连接，通知该流重新开始收取
			// .....
			m_pkgSend.PreparePackage(
					FTD_TID_ReqQryTradeDayChangeTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);

			CFTDReqQryTradeDayChangeField fieldChange;
			fieldChange.ChangeType = TRUNCATEFLOW;
			fieldChange.OldDate = m_nFlowPosition;
			fieldChange.NewDate = m_nFlowPosition;
			FTDC_ADD_FIELD(&m_pkgSend, &fieldChange);

			CHashMap<DWORD, CSession *, HashInt>::iterator	itor =
				m_pSessionMap->Begin();
			while (!itor.IsEnd())
			{
				((CFTDCSession *) (*itor))->SendRequestPackage(&m_pkgSend);
				m_pkgSend.Pop(FTDCHLEN);
				itor++;
			}
		}
	}
	else if (nIDEvent == 4)
	{
		//重新加载配置文件
		CSysLogConfigManager::Instance()->ReloadConfig();
	}
	else if (nIDEvent == 5)						//syslogreader监控
	{
		//30秒钟还没启动，则强制启动
		if (g_pSyslogReader->GetHandle() == (THREAD_HANDLE) 0)
		{
			//已经收到configsvr 的device信息
			if (m_pcSyn && m_pcSyn->GetDevMap().size() > 0)
			{
				g_pSyslogReader->Create();
				KillTimer(nIDEvent);
			}
		}
		else
		{
			KillTimer(nIDEvent);
		}
	}
	else if (nIDEvent == 6)
	{
		for (int i = 0; i < m_nThreadNum; i++)
		{
			if (m_pThread[i]->it_data != m_pThread[i]->datas.end())
			{
				m_pThread[i]->GetAsyncIns()->genOneDateField(
						*(m_pThread[i]->it_data));
				(m_pThread[i]->it_data)++;
			}
			else
			{
				m_pThread[i]->it_data = m_pThread[i]->datas.begin();
			}
		}
	}

	CFTDRtnObjectAttrField objectAttr;
	CFTDRtnWarningEventField warningEvent;
	CFTDRtnSyslogEventField syslogEvent;
	CFTDRtnUpdateSysConfigField updateConfig;
	CFTDRtnNetMonitorTaskTotalResult taskTotalResult;
	CFTDRtnObjectAttrField objectConAttr;

	CFTDRtnObjectAttrField telnetobjectAttr;

	if (g_pSyslogReader != NULL)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnWarningEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		while (g_pSyslogReader->m_listWarningEvents.get(warningEvent))
		{
			//if( !g_isMasterRole )
			//	continue;
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnWarningEventField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				m_pkgSend.MakePackage();
				m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				m_pkgSend.PreparePackage(
						FTD_TID_RtnWarningEventTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &warningEvent);
		}

		if (m_pkgSend.Length() >= sizeof(CFTDRtnWarningEventField))
		{
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RtnSyslogEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		while (g_pSyslogReader->m_listSyslogEvents.get(syslogEvent))
		{
			//if( !g_isMasterRole )
			//	continue;
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnSyslogEventField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				m_pkgSend.MakePackage();
				m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				m_pkgSend.PreparePackage(
						FTD_TID_RtnSyslogEventTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &syslogEvent);
		}

		if (m_pkgSend.Length() >= sizeof(CFTDRtnSyslogEventField))
		{
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}
	}

	for (int i = 0; i < m_nThreadNum; i++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnObjectAttrTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		while (m_pThread[i]->getObjectAttr(objectAttr))
		{
			if (!g_isMasterRole)
			{
				continue;
			}

			printf("*********************");
			printf(
				"[%s][%s][%s][%s][%s]\n",
				objectAttr.ObjectID.getValue(),
				objectAttr.AttrType.getValue(),
				objectAttr.MonDate.getValue(),
				objectAttr.MonTime.getValue(),
				objectAttr.AttrValue.getValue());

			if (m_pkgSend.Length() +
				sizeof(CFTDRtnObjectAttrField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				m_pkgSend.MakePackage();
				m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				m_pkgSend.PreparePackage(
						FTD_TID_RtnObjectAttrTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &objectAttr);
		}

		if (m_pkgSend.Length() >= sizeof(CFTDRtnObjectAttrField))
		{
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		/////////////////////////////////////////////
		m_pkgSend.PreparePackage(
				FTD_TID_RtnWarningEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		while (m_pThread[i]->getWarningEvent(warningEvent))
		{
			//if( !g_isMasterRole )
			//	continue;
			printf(
				"[%s][%s][%s][%s][%s]\n",
				warningEvent.ObjectID.getValue(),
				warningEvent.EventName.getValue(),
				warningEvent.MonDate.getValue(),
				warningEvent.MonTime.getValue(),
				warningEvent.EventDes.getValue());
			if (m_pkgSend.Length() +
				sizeof(CFTDRtnWarningEventField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				m_pkgSend.MakePackage();
				m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				m_pkgSend.PreparePackage(
						FTD_TID_RtnWarningEventTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &warningEvent);
		}

		if (m_pkgSend.Length() >= sizeof(CFTDRtnWarningEventField))
		{
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		while (m_pThread[i]->getSyslogEvent(syslogEvent))
		{
			//if( !g_isMasterRole )
			//	continue;
			//printf("[%s][%s][%s][%s][%s]\n", syslogEvent.ObjectID.getValue(),syslogEvent.EventName.getValue(),
			//	syslogEvent.MonDate.getValue(),syslogEvent.MonTime.getValue(),syslogEvent.EventDes.getValue());
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &syslogEvent);
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		//while(m_pThread[i]->getUpdateSysConfig(updateConfig))
		//{
		//	;
		//}
		//send to the config
		while (m_pThread[i]->getConObjectAttr(objectConAttr))
		{
			if (!g_isMasterRole)
			{
				continue;
			}

			printf("##################");
			printf(
				"[%s][%s][%s][%s][%s]\n",
				objectConAttr.ObjectID.getValue(),
				objectConAttr.AttrType.getValue(),
				objectConAttr.MonDate.getValue(),
				objectConAttr.MonTime.getValue(),
				objectConAttr.AttrValue.getValue());

			if (m_pcSyn != NULL)
			{
				m_pcSyn->SendCFTDRtnObjectAttrField(objectConAttr);
			}
		}
	}

	for (int i = 0; i < m_nConnTaskThreadNum; i++)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnObjectAttrTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		while (m_pConnTaskThread[i]->getObjectAttr(telnetobjectAttr))
		{
			if (!g_isMasterRole)
			{
				continue;
			}

			printf("*********************");
			printf(
				"[%s][%s][%s][%s][%s]\n",
				telnetobjectAttr.ObjectID.getValue(),
				telnetobjectAttr.AttrType.getValue(),
				telnetobjectAttr.MonDate.getValue(),
				telnetobjectAttr.MonTime.getValue(),
				telnetobjectAttr.AttrValue.getValue());

			if (m_pkgSend.Length() +
				sizeof(CFTDRtnObjectAttrField) > FTDC_PACKAGE_MAX_SIZE)
			{
				m_pkgSend.SetChain(FTDC_CHAIN_CONTINUE);
				m_pkgSend.MakePackage();
				m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				m_pkgSend.PreparePackage(
						FTD_TID_RtnObjectAttrTopic,
						FTDC_CHAIN_LAST,
						FTD_VERSION);
			}

			FTDC_ADD_FIELD(&m_pkgSend, &telnetobjectAttr);

			//for test
			//break;
		}

		if (m_pkgSend.Length() >= sizeof(CFTDRtnObjectAttrField))
		{
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		while (m_pConnTaskThread[i]->getWarningEvent(warningEvent))
		{
			//if( !g_isMasterRole )
			//	continue;
			//printf("[%s][%s][%s][%s][%s]\n", warningEvent.ObjectID.getValue(),warningEvent.EventName.getValue(),
			//	warningEvent.MonDate.getValue(),warningEvent.MonTime.getValue(),warningEvent.EventDes.getValue());
			m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &warningEvent);
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		while (m_pConnTaskThread[i]->getSyslogEvent(syslogEvent))
		{
			//if( !g_isMasterRole )
			//	continue;
			//printf("[%s][%s][%s][%s][%s]\n", syslogEvent.ObjectID.getValue(),syslogEvent.EventName.getValue(),
			//	syslogEvent.MonDate.getValue(),syslogEvent.MonTime.getValue(),syslogEvent.EventDes.getValue());
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &syslogEvent);
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		//任务配置文件
		TaskConfigContent configContent;
		while (m_pConnTaskThread[i]->getTaskConfigContent(configContent))
		{
			if (!g_isMasterRole)
			{
				continue;
			}

			CFTDRspQryNetMonitorTaskResultField tfield;
			tfield.ObjectID = configContent.objectid.c_str();
			tfield.MonDate = configContent.filedate.c_str();
			tfield.MonTime = configContent.filetime.c_str();
			tfield.Task_ID = configContent.task_id;
			tfield.Flag = configContent.fileversion;

			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskResultTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			for (int i = 0, deta = 0;
				 i < configContent.filecontent.length();
				 i += deta)
			{
				deta = min(
						configContent.filecontent.length() - i,
						sizeof(tfield.ResultChain) - 1);
				tfield.ResultChain = (configContent.filecontent.substr(i, deta)).c_str();

				FTDC_ADD_FIELD(&m_pkgSend, &tfield);

				m_pkgSend.MakePackage();
				m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
			}

			tfield.ResultChain = "";

			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskResultTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}
	}

	while (g_TaskInfoManager.GetTaskResult(taskTotalResult))
	{
		if (!g_isMasterRole)
		{
			continue;
		}


		m_pkgSend.PreparePackage(
				FTD_TID_RtnNetMonitorTaskResultTopic,
				FTDC_CHAIN_CONTINUE,
				FTD_VERSION);
		for (int i = 0, deta = 0;
			 i < taskTotalResult.result.length();
			 i += deta)
		{
			deta = min(
					taskTotalResult.result.length() - i,
					sizeof(taskTotalResult.field.ResultChain) - 1);
			taskTotalResult.field.ResultChain = (taskTotalResult.result.substr(i, deta)).c_str();

			FTDC_ADD_FIELD(&m_pkgSend, &taskTotalResult.field);
			printf("+++TaskResult:[%d][%d][%s][%s][%s][%s][%s][%d]\n", 
			taskTotalResult.field.Task_ID.getValue(),taskTotalResult.field.OperateTime.getValue(),
			taskTotalResult.field.ObjectID.getValue(),taskTotalResult.field.MonDate.getValue(),
			taskTotalResult.field.MonTime.getValue(),taskTotalResult.field.InstructChain.getValue(),
			taskTotalResult.field.ResultChain.getValue(),taskTotalResult.field.Flag.getValue() );

			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
			m_pkgSend.PreparePackage(
					FTD_TID_RtnNetMonitorTaskResultTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
		}

		taskTotalResult.field.ResultChain = "";

		if (taskTotalResult.user.length() > 0)
		{
			char buff[256] = "\0";
			sprintf(
				buff,
				"%s@%s",
				taskTotalResult.field.InstructChain.getValue(),
				taskTotalResult.user.c_str());
			taskTotalResult.field.InstructChain = buff;
		}

		m_pkgSend.PreparePackage(
				FTD_TID_RtnNetMonitorTaskResultTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &taskTotalResult.field);
		m_pkgSend.MakePackage();
		m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
	}

	//发送远程ping结果
	CFTDRtnNetRomotePingResultInfoField R_pingResult;
	while (g_TaskInfoManager.GetRemotePingResult(R_pingResult))
	{
		if (!g_isMasterRole)
		{
			continue;
		}

		printf(
			"Remote ping result[source ip][target ip][conn rate][avg delay][max daly]:");
		printf(
			"[%s][%s][%d][%s][%s]\n",
			R_pingResult.SouIPADDR.getValue(),
			R_pingResult.TarIPADDR.getValue(),
			R_pingResult.ConnRate.getValue(),
			R_pingResult.TimeDlyAvg.getValue(),
			R_pingResult.TimeDlyMax.getValue());
		m_pkgSend.PreparePackage(
				FTD_TID_RtnNetRomotePingResultInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &R_pingResult);
		m_pkgSend.MakePackage();
		m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
	}

	while (g_TaskInfoManager.GetTMWarningEvent(warningEvent))
	{
		if (!g_isMasterRole)
		{
			continue;
		}

		//printf("[%s][%s][%s][%s][%s]\n", warningEvent.ObjectID.getValue(),warningEvent.EventName.getValue(),
		//	warningEvent.MonDate.getValue(),warningEvent.MonTime.getValue(),warningEvent.EventDes.getValue());
		m_pkgSend.PreparePackage(
				FTD_TID_RtnWarningEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &warningEvent);
		m_pkgSend.MakePackage();
		m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
	}

	while (g_TaskInfoManager.GetTMSyslogEventField(syslogEvent))
	{
		if (!g_isMasterRole)
		{
			continue;
		}

		//printf("[%s][%s][%s][%s][%s]\n", syslogEvent.ObjectID.getValue(),syslogEvent.EventName.getValue(),
		//	syslogEvent.MonDate.getValue(),syslogEvent.MonTime.getValue(),syslogEvent.EventDes.getValue());
		m_pkgSend.PreparePackage(
				FTD_TID_RtnSyslogEventTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &syslogEvent);
		m_pkgSend.MakePackage();
		m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
	}

	//发送本地ping结果
	CFTDRtnNetLocalPingResultInfoField L_pingResult;
	while (g_TaskInfoManager.GetLocalPingResult(L_pingResult))
	{
		if (!g_isMasterRole)
		{
			continue;
		}

		printf("Local ping result[source ip][target ip][isactive]:");
		printf(
			"[%s][%s][%d]\n",
			L_pingResult.SouIPADDR.getValue(),
			L_pingResult.TarIPADDR.getValue(),
			L_pingResult.ConnRate.getValue());
		m_pkgSend.PreparePackage(
				FTD_TID_RtnNetLocalPingResultInfoTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &L_pingResult);
		m_pkgSend.MakePackage();
		m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
	}

	//同步任务当日执行次数到config
	CTaskRunTimes runtimes;
	while (g_TaskInfoManager.GetTaskRunTimes(runtimes))
	{
		if (!g_isMasterRole)
		{
			continue;
		}

		if (m_pcSyn != NULL)
		{
			m_pcSyn->SendTaskRunTimes(runtimes.TaskID, runtimes.RunTimes);
		}
		else
		{
			printf(
				"m_pcSyn NULL, fail to send task run times info for task_id:%d, runtimes:%d\n",
				runtimes.TaskID,
				runtimes.RunTimes);
		}
	}

	//同步任务当日控制状态到config
	CTaskCtlStatus ctlstatus;
	while (g_TaskInfoManager.GetTaskCtlStatus(ctlstatus))
	{
		if (!g_isMasterRole)
		{
			continue;
		}

		if (m_pcSyn != NULL)
		{
			m_pcSyn->SendTaskStatus(
					ctlstatus.TaskID,
					ctlstatus.TaskStatus,
					ctlstatus.DelayGap);
		}
		else
		{
			printf(
				"m_pcSyn NULL, fail to send task control status info for task_id:%d, status:%d, delay:%d\n",
				ctlstatus.TaskID,
				ctlstatus.TaskStatus,
				ctlstatus.DelayGap);
		}
	}

	if (g_pBaseLineTaskThread != NULL)
	{
		//取到config的基线比对任务 2012.06.05， by Lee
		CFTDRtnNetBaseLineTaskField baselineTask;
		TaskConfigContent content;

		g_pBaseLineTaskThread->m_RspBaselinepLock.Lock();

		//任务配置文件
		while (g_pBaseLineTaskThread->getTaskConfigContent(content))
		{
			if (!g_isMasterRole)
			{
				continue;
			}

			CFTDRspQryNetMonitorTaskResultField tfield;
			tfield.ObjectID = content.objectid.c_str();
			tfield.MonDate = content.filedate.c_str();
			tfield.MonTime = content.filetime.c_str();
			tfield.Flag = content.fileversion;

			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskResultTopic,
					FTDC_CHAIN_CONTINUE,
					FTD_VERSION);
			for (int i = 0, deta = 0;
				 i < content.filecontent.length();
				 i += deta)
			{
				deta = min(
						content.filecontent.length() - i,
						sizeof(tfield.ResultChain) - 1);
				tfield.ResultChain = (content.filecontent.substr(i, deta)).c_str();

				FTDC_ADD_FIELD(&m_pkgSend, &tfield);

				m_pkgSend.MakePackage();
				m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
				m_pkgSend.PreparePackage(
						FTD_TID_RspQryNetMonitorTaskResultTopic,
						FTDC_CHAIN_CONTINUE,
						FTD_VERSION);
			}

			tfield.ResultChain = "";

			m_pkgSend.PreparePackage(
					FTD_TID_RspQryNetMonitorTaskResultTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &tfield);
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		while (g_pBaseLineTaskThread->getBaseLineTask(baselineTask))
		{
			if (!g_isMasterRole)
			{
				continue;
			}

			//printf("$$$$$$BaseLineTask");
			printf(
				"BaseLineTask:DeviceIDList=[%s] GenUser=[%s] GenDate=[%s] GenTime=[%s]\n",
				baselineTask.DeviceIDList.getValue(),
				baselineTask.GenUser.getValue(),
				baselineTask.GenDate.getValue(),
				baselineTask.GenTime.getValue());
			m_pkgSend.PreparePackage(
					FTD_TID_RtnNetBaseLineTaskTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
			FTDC_ADD_FIELD(&m_pkgSend, &baselineTask);
			m_pkgSend.MakePackage();
			m_pCurrFlow->Append(m_pkgSend.Address(), m_pkgSend.Length());
		}

		g_pBaseLineTaskThread->m_RspBaselinepLock.UnLock();
	}
}

CSnmpManagerServer::CSnmpManagerServer(
	CReactor *pReactor,
	int nThreadNum,
	const char *pMibPath,
	const char *pFlowPath,
	int nStartId,
	const char *pLocation) :
	CSessionFactory(pReactor, 10),
	m_timer(pReactor),
	m_cSynConnector(pReactor)
{
	///创建一组流文件
	char buff[10];
	for (int i = 0; i < MAX_EVENTFLOWNUM; i++)
	{
		sprintf(buff, "snmp%d", i);
		m_pFlowArray[i] = new CCachedFileFlow(
				buff,
				pFlowPath,
				true,
				1000,
				32768);

		//(buff, pFlowPath, true, 500, 32*1024); //new CCachedFlow(true, 10000000, 32*1024);
	}

	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_nThreadNum = nThreadNum;
	for (int i = 0; i < MAX_THREAD_NUM; i++)
	{
		if (i < m_nThreadNum)
		{
			m_pThread[i] = new CAyncGetThread(i, pMibPath);
			m_pThread[i]->Create();
		}
		else
		{
			m_pThread[i] = NULL;
		}
	}

	m_timer.setSessionMapPoint(&m_mapSession);
	m_timer.setFlowPoint((CCachedFileFlow **)m_pFlowArray);
	m_timer.setThreadPoint((CAyncGetThread **)m_pThread, m_nThreadNum);
	m_timer.SetTimer(1, 1000);
	m_timer.SetTimer(2, FLOWCHANGETIME);
	m_timer.setCSynConnectorPoint(&m_cSynConnector);
	m_cSynConnector.setThreadPoint((CAyncGetThread **)m_pThread, m_nThreadNum);
	m_cSynConnector.SetInstancePoint(&m_cSynConnector);
	m_timer.SetTimer(3, 1000 * 10);				//10秒钟

	//魏诚add，定期加载syslog配置文件
	m_timer.SetTimer(4, 5 * 60 * 1000);			//5分钟
	m_timer.SetTimer(5, 1000 * 30);				//30秒
	m_pLocation = (char *)pLocation;
	m_nStartId = nStartId;

	//for test	for test  to add monitor device
	m_timer.SetTimer(6, 20 * 1000);
	LoadDataFile();

#ifdef TEST_GETDEVINFO
	CGetDeviceInfoThread *m_pinfoThread = new CGetDeviceInfoThread();
	for (int i = 0; i < 6; i++)
	{
		m_pinfoThread->m_hosts.push_back(g_hosts[i]);
	}

	m_pinfoThread->Create();
#endif TEST_GETDEVINFO
	m_pTaskManagerThread = new CTaskManagerThread();
	m_timer.setTaskManagerThreadPoint(m_pTaskManagerThread);
	m_cSynConnector.SetTaskManagerThread(m_pTaskManagerThread);

	m_pTaskManagerThread->Create();
	for (int i = 0; i < MAX_THREAD_NUM; i++)
	{
		m_pConnTaskThread[i] = new CConnTaskThread(i + 1);
		m_pConnTaskThread[i]->Create();
	}

	m_timer.setConnTaskPoint(m_pConnTaskThread, MAX_THREAD_NUM);

	/// Added end
}

CSession *CSnmpManagerServer::CreateSession(CChannel *pChannel, DWORD dwMark)
{
	CFTDCSession *pSession = new CFTDCSession(m_pReactor, pChannel);
	pSession->RegisterPackageHandler(this);

	/// Added by Henchi, 20120309
	pSession->SetCompressMethod(CRPCM_ZERO);	//设置压缩算法
	printf(
		"\tCProbeServer::CreateSession:CFTDCSession %0x Connected ==\n",
		(CFTDCSession *)pSession);
	fflush(stdout);
	return pSession;
}

void CSnmpManagerServer::OnSessionConnected(CSession *pSession) // 子类重载处理连接断开事件
{
	CSessionFactory::OnSessionConnected(pSession);	// 子类调用父类处理连接断开事件
	time_t timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionConnected: CFTDCSession %0x CSession %0x %s",
		(CFTDCSession *)pSession,
		pSession,
		ctime(&timep));
	fflush(stdout);

	CFTDReqUserLoginField fieldLogin;
	m_pkgSend.PreparePackage(
			FTD_TID_ReqUserLogin,
			FTDC_CHAIN_LAST,
			FTD_VERSION);

	memset(&fieldLogin, 0, sizeof(fieldLogin));
	fieldLogin.UserID = "snmpmanager";
	sprintf(
		(char *)fieldLogin.Password.getValue(),
		"%s,%d",
		m_pLocation,
		m_nStartId);
	FTDC_ADD_FIELD(&m_pkgSend, &fieldLogin);
	((CFTDCSession *)pSession)->SendRequestPackage(&m_pkgSend);
}

void CSnmpManagerServer::OnSessionDisconnected(CSession *pSession, int nReason) // 子类重载处理连接断开事件
{
	time_t timep;
	time(&timep);
	printf(
		"\t CProbeServer::OnSessionDisconnected: CFTDCSession %0x Disconnected!  %s",
		(CFTDCSession *)pSession,
		ctime(&timep));
	fflush(stdout);
	CSessionFactory::OnSessionDisconnected(pSession, nReason);	// 子类调用父类处理连接断开事件
}

int CSnmpManagerServer::HandlePackage(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	printf(
		"\tCProbeServer::HandlePackage:Receive Package %0x\n",
		pFTDCPackage->GetTID());
	switch (pFTDCPackage->GetTID())
	{
		case FTD_TID_ReqUserLogin:
			OnReqUserLogin(pFTDCPackage, pSession);
			break;
		case FTD_TID_RtnMonitorObjectTopic:
			{
				CFTDRtnMonitorObjectField fieldObject;
				FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldObject);
			}

			break;
		case FTD_TID_RspQryHostConfig:
			break;
		case FTD_TID_RtnHostConfig:
			break;
		case FTD_TID_ReqUserLogout:
			break;
		case FTD_TID_ReqQryTradeDayChangeTopic:
			break;
		case FTD_TID_ReqQryDBQueryTopic:
			break;
		default:
			break;
	}

	return 0;
}

void CSnmpManagerServer::OnReqUserLogin(
	CFTDCPackage *pFTDCPackage,
	CFTDCSession *pSession)
{
	CFTDReqUserLoginField fieldLogin;
	FTDC_GET_SINGLE_FIELD(pFTDCPackage, &fieldLogin);

	time_t timep;
	time(&timep);
	printf(
		"\t CSnmpManagerServer::OnReqUserLogin:user=%s password=%s  %s",
		(const char *)fieldLogin.UserID,
		(const char *)fieldLogin.Password,
		ctime(&timep));

	CFTDDisseminationField fieldDissemination;
	CNamedFieldIterator itor = pFTDCPackage->GetNamedFieldIterator(
			&CFTDDisseminationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&fieldDissemination);
		printf(
			"sequernceSeries %d serquenceNo %d\n",
			(const int)fieldDissemination.SequenceSeries,
			(const int)fieldDissemination.SequenceNo);
		if ((fieldDissemination.SequenceSeries <= MAX_EVENTFLOWNUM)
		&&	(fieldDissemination.SequenceSeries >= 0))
		{
			pSession->Publish(
					m_pFlowArray[fieldDissemination.SequenceSeries - 1],
					fieldDissemination.SequenceSeries,
					fieldDissemination.SequenceNo);
		}

		//pSession->Publish(m_pFlowArray[0], fieldDissemination.SequenceSeries, fieldDissemination.SequenceNo);
		itor.Next();
		if (pFTDCPackage->GetChain() == FTDC_CHAIN_LAST && itor.IsEnd())
		{
			break;
		}
	}						// while (!itor.IsEnd()) end

	fflush(stdout);
}

void CSnmpManagerServer::LoadDataFile(const char *filename)
{
	if (filename == NULL)
	{
		filename = "snmpmanager.data";
	}

#ifdef CIVIL_TEST
	ip_objId["172.1.37.151"] = "zhangjiang.access.ZJ-OAW3825-ZJH1-2N507";
	ip_objId["172.1.37.152"] = "zhangjiang.access.ZJ-OAW3560-ZJH2-ECC";
	ip_objId["172.1.37.105"] = "zhangjiang.access.ZJ-OAW3750-C5-2N509";
	ip_objId["172.1.37.106"] = "zhangjiang.access.ZJ-OAW3750-C6-2N509";
	ip_objId["172.1.37.3"] = "zhangjiang.access.ZJ-OAW4506-C1-2N504";
	ip_objId["172.1.37.4"] = "zhangjiang.access.ZJ-OAW4506-C2-2N504";
	ip_objId["172.1.37.102"] = "zhangjiang.access.ZJ-OAW3560-C2-B1-2F";
	ip_objId["172.1.37.107"] = "zhangjiang.access.ZJ-OAW3560-C7-B2-3-FCZS";
	ip_objId["172.1.37.104"] = "zhangjiang.access.ZJ-OAW3560-C4-A1-5F";
	ip_objId["172.1.37.103"] = "zhangjiang.access.ZJ-OAW3560-C3-A2-4F";
	ip_objId["172.1.37.101"] = "zhangjiang.access.ZJ-OAW3560-C1-ECC";
#endif

	FILE *pf = NULL;
	if ((pf = fopen(filename, "r")) == NULL)
	{
		printf("open file %s fail!\n", filename);
		return;
	}

	printf("open file %s !\n", filename);

	char buff[SIZE_BUF];
	char ip[16], comm[16],
				oid_value[128],
				oid_type[32],
				freq[64],
				host[64];
	string str[6];
	memset(buff, 0x00, sizeof(buff));
	while ((fgets(buff, sizeof(buff) - 1, pf)) != NULL)
	{
		if ((buff[0] != '#') && (buff[0] != '\n') && (buff[0] != '\r'))
		{
			char *p = NULL;
			char *q = buff;
			p = strchr(q, '\n');
			if (p != NULL)
			{
				*p = '\0';
			}

			p = strchr(q, '\r');
			if (p != NULL)
			{
				*p = '\0';
			}

			if (*q == '$')	//探测指标
			{
				q++;
				sscanf(
					q,
					"%s %s %s %s %s %[^\n]",
					ip,
					comm,
					oid_value,
					oid_type,
					freq,
					host);

				int thr_id = m_cSynConnector.getDisTaskThreadIDByIP(ip);
				if (thr_id == -1)
				{
					thr_id = 0;
				}

				m_pThread[thr_id]->addMonDevice(
						host,
						ip,
						comm,
						"",
						"",
						oid_value,
						oid_type,
						freq);
			}
			else if (*q == '@') //探测指标值
			{
				q++;

				int type = *q;
				q++;
				m_pThread[0]->datas.push_back(make_pair(type, string(q)));
			}
			else if (*q == '!') //设备ip，objid信息
			{
				q++;
				sscanf(q, "%s %[^\n]", ip, host);
				ip_objId[ip] = string(host);
			}
		}

		memset(buff, 0x00, sizeof(buff));
	}

	fclose(pf);

	for (int i = 0; i < m_nThreadNum; i++)
	{
		m_pThread[i]->it_data = m_pThread[i]->datas.begin();
	}
}
