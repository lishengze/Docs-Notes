#ifdef LINUX
#include <sys/types.h>
#include <dirent.h>
#endif
#include "CTelnetConnThread.h"

bool CTelnetConnThread::InitInstance(void)
{
	printf("Thread[%d] Started!\n", m_nThreadID);
	return true;
}

void CTelnetConnThread::ExitInstance(void)
{
	printf("Thread[%d] Ended!\n", m_nThreadID);
}

void CTelnetConnThread::Run(void)
{
	while (1)
	{
		time_t	timep;
		struct tm curTime;
		time(&timep);
		LocalTime(&timep, &curTime);
		strftime(m_time, 10, "%H:%M:%S", &curTime);
		strftime(m_date, 10, "%Y%m%d", &curTime);

		// ȷ�����߳�ģʽ��,�ն�ģʽһ��
		m_oTelnetClient.TTYLock();
		for (int i = 0; i < MAX_DEVICE_NUM; i++)
		{
			// ���߳̽��������ȡ��ΪĿ��ֵ�ķǿ��豸����.
			if (m_pDevices[i].m_bValid == false
			||	i % MAX_THREAD_NUM != m_nDeviceNum)
			{
				continue;
			}

			CTelnetDevice &device = (CTelnetDevice &)m_pDevices[i];

			// �жϵ�ǰʱ���Ƿ�Ҫִ��
			if (device.ShouldRun(timep - m_nTimeZoneSec))
			{
				CObjectIDName &object = device.GetObjectIDName();
				CTelnetConnEntry &entry = device.GetTelnetConnEntry();
				string	sOutputPath = device.GetPath();
				printf(
					"Thread[%d] +++++ Init:%s %d %s %s %s!\n",
					m_nThreadID,
					entry.m_sIP.c_str(),
					entry.m_nPort,
					entry.m_sUser.c_str(),
					entry.m_sPswd.c_str(),
					entry.m_sCfgPswd.c_str());
#ifdef PRINT_DEBUG
#endif

				// ��ʼ������Ĳɼ�����
				m_oTelnetClient.Init(entry);

				// ��������ļ�Ŀ¼
				m_oTelnetClient.SetOutputPath(sOutputPath.c_str());

				// ����һ���豸��Ϣ�ɼ�,������Ϊ�ļ�
				if ((m_oTelnetClient.DoTask() == 0))
				{
					printf(
						"Thread[%d] ----- Get Device [%s] Config to [%s]!\n",
						m_nThreadID,
						m_oTelnetClient.GetDeviceName().c_str(),
						m_oTelnetClient.GetFileName().c_str());
#ifdef PRINT_DEBUG
#endif

					// �����ļ����ݳɹ�
					CFTDRtnSyslogEventField syslogEvent;
					syslogEvent.ObjectID = device.GetObjectIDName().m_sObjectIDName.c_str();
					syslogEvent.MonDate = m_date;
					syslogEvent.MonTime = m_time;
					syslogEvent.OccurTime = m_time;
					syslogEvent.EventName = EVENT_BACKUP_SUCCEED;
					syslogEvent.ProcessFlag = "L";
					syslogEvent.WarningLevel = "info";
					syslogEvent.EventDes = "Comment='Buckup running-config succeeded.'";
					syslogEvent.EventDealDes = "N";
					syslogEvent.IPAddress = entry.m_sIP.c_str();
					m_listSyslogEvent.add(syslogEvent);

					CheckVersion(object, entry.m_sIP);
				}
				else
				{
					printf(
						"Thread[%d] ----- Get Device [%s] Config Failed!\n",
						m_nThreadID,
						entry.m_sIP.c_str());
#ifdef PRINT_DEBUG
#endif

					// �����ļ�����ʧ��
					CFTDRtnSyslogEventField syslogEvent;
					syslogEvent.ObjectID = device.GetObjectIDName().m_sObjectIDName.c_str();
					syslogEvent.MonDate = m_date;
					syslogEvent.MonTime = m_time;
					syslogEvent.OccurDate = m_date;
					syslogEvent.OccurTime = m_time;
					syslogEvent.EventName = EVENT_BACKUP_FAILED;
					syslogEvent.FullEventName = "�����ļ�����ʧ��";
					syslogEvent.ProcessFlag = "L";
					syslogEvent.WarningLevel = "notify";
					syslogEvent.EventDes = "Comment='Buckup running-config failed.'";
					syslogEvent.EventDealDes = "N";
					syslogEvent.IPAddress = entry.m_sIP.c_str();
					m_listSyslogEvent.add(syslogEvent);
				}
			}
		}

		m_oTelnetClient.TTYUnLock();

		OSSleep(2);
	}
}

void CTelnetConnThread::CheckVersion(CObjectIDName &object, string ip)
{
	string	currFileName = m_oTelnetClient.GetFileName();
	string	lastFileName;

	// �����ҵ�֮ǰ���һ�λ�ȡ�������ļ�
	if (m_oTelnetClient.GetLastFileName(currFileName, lastFileName))
	{
		// �����ļ��Ա�������ļ���
		m_oFileDiff.SetFiles(currFileName.c_str(), lastFileName.c_str());

		//		printf("File1:%s  File2:%s\n", currFileName.c_str(), lastFileName.c_str());
		// �����ļ��Ƚ�,�������ļ��Ĳ�������
		int nDiff = m_oFileDiff.Compare();
		if (nDiff == 0)
		{
			// �ļ�һ��
			//			m_oFileDiff.Show();		// ����ԱȽ��
			CFTDRtnSyslogEventField syslogEvent;
			syslogEvent.ObjectID = object.m_sObjectIDName.c_str();
			syslogEvent.MonDate = m_date;
			syslogEvent.MonTime = m_time;
			syslogEvent.OccurDate = m_date;
			syslogEvent.OccurTime = m_time;
			syslogEvent.EventName = EVENT_CHKVER_NOCHG;
			syslogEvent.FullEventName = "�����ļ��޸���";
			syslogEvent.ProcessFlag = "L";
			syslogEvent.WarningLevel = "info";
			syslogEvent.EventDes = "Comment='Device running-config have not changed.'";
			syslogEvent.EventDealDes = "N";
			syslogEvent.IPAddress = ip.c_str();
			m_listSyslogEvent.add(syslogEvent);
		}
		else if (nDiff >= 0)
		{
			// �ļ���һ��
			//			m_oFileDiff.Show();		// ����ԱȽ��
			CFTDRtnSyslogEventField syslogEvent;
			syslogEvent.ObjectID = object.m_sObjectIDName.c_str();
			syslogEvent.MonDate = m_date;
			syslogEvent.MonTime = m_time;
			syslogEvent.OccurDate = m_date;
			syslogEvent.OccurTime = m_time;
			syslogEvent.EventName = EVENT_CHKVER_CHANGE;
			syslogEvent.FullEventName = "�����ļ��и���";
			syslogEvent.ProcessFlag = "L";
			syslogEvent.WarningLevel = "notify";
			syslogEvent.EventDes = "Comment='Device running-config has changed.'";
			syslogEvent.EventDealDes = "N";
			syslogEvent.IPAddress = ip.c_str();
			m_listSyslogEvent.add(syslogEvent);
		}
		else
		{
			printf("FileDiff Error(%d)\n", nDiff);	// �����쳣
		}
	}
	else
	{
		printf("Failed to GetLastFileName with [%s]\n", currFileName.c_str());	// �����쳣
	}
}
