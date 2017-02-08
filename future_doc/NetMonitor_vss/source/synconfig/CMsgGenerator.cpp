/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CMsgGenerator.cpp
///@brief	定义了生成消息文件的工具类
///@history
///20111214	晏鹤春	创建该文件
#include "CMsgGenerator.h"

CMutex	g_lockMsgFile;	// 消息文件锁
CMsgNMEvent::CMsgNMEvent(void)
{
}

CMsgNMEvent::CMsgNMEvent(
	CFTDRtnWarningEventField &EventField,
	string	&Device,
	string	&Party,
	int Times)
{
	memcpy(&m_EventField, &EventField, sizeof(m_EventField));
	m_strDevice = Device;
	m_strParty = Party;
	m_iTimes = Times;
}

CMsgNMEvent::~CMsgNMEvent(void)
{
}

CMsgGenerator::CMsgGenerator(void)
{
	m_iMaxRetry = 3;
	m_iRetrySpan = 300;
}

CMsgGenerator::CMsgGenerator(
	char *pszPath,
	char *pszMsgPolicy,
	char *pszSystemID)
{
	m_iMaxRetry = 3;
	m_iRetrySpan = 300;
	Init(pszPath, pszMsgPolicy, pszSystemID);
}

CMsgGenerator::~CMsgGenerator(void)
{
}

bool CMsgGenerator::InitInstance(void)
{
	printf("CMsgGenerator thread Started!\n");
	return true;
}

void CMsgGenerator::ExitInstance(void)
{
	printf("CMsgGenerator thread Ended!\n");
}

void CMsgGenerator::Run(void)
{
	while (1)
	{
		if (m_TimePolicy.ShouldRun(time(NULL)))
		{
			GenNetDeviceEventMsg();
		}
		else
		{
#ifdef PRINT_DEBUG
			printf("Time out range, MsgList[%d]", m)
#endif
		}

		OSSleep(1);
	}
}

void CMsgGenerator::Init(char *pszPath, char *pszMsgPolicy, char *pszSystemID)
{
	m_strPath = (NULL != pszPath && strlen(pszPath) > 0) ? pszPath : "./";
	m_strSystemID =
		(
			NULL != pszSystemID
		&&	strlen(pszSystemID) > 0
		) ? pszSystemID : "NetMonitor";
	m_TimePolicy.Init();
	m_DateTime.OpenDrift();

	if (!m_TimePolicy.AddPolicyStr(pszMsgPolicy))
	{
		printf(
			"Error: CMsgGenerator init timepolicy[%s] Failed!",
			pszMsgPolicy);
	}
}

/// 生成网络设备事件消息
int CMsgGenerator::GenNetDeviceEventMsg(void)
{
	int iCount = 0;
	CMsgNMEvent EventInfo;
	CFTDRtnWarningEventField &EventField = EventInfo.m_EventField;
	while (m_lEvents.get(EventInfo))
	{
		int iEventNum = EventField.EventNum.getValue();
		map<int, time_t>::iterator	mapIt = m_mapEventDumpTime.find(iEventNum);

		time_t	CurrTime = m_DateTime.GetCurrTimeSec();
		if (mapIt != m_mapEventDumpTime.end())
		{
			time_t	DumpTime = mapIt->second;
			if (CurrTime < DumpTime + 1800)
			{
				/// 对于半小时内已落地过的事件，直接丢弃处理
				printf(
					"Info: Drop new event[%d %s(%d) %s]\nNow[%ld] Latest[%ld]\n",
					EventField.EvendID.getValue(),
					EventField.EventName.getValue(),
					EventField.EventNum.getValue(),
					EventField.ObjectID.getValue(),
					CurrTime,
					DumpTime);
				continue;
			}
		}

		// 20140324
		// 临时修改，对于以NM开头的事件（监控系统内部事件）不需要落地
		if (strncmp(EventField.EventName.getValue(), "NM_", 3) == 0)
		{
			char tmpTime[20]={0};
			struct tm tm_time;
			LocalTime(&CurrTime, &tm_time);
			strftime(tmpTime, 20, "%Y%m%d %H:%M:%S", &tm_time);

			printf(
				"@@@ NM Event Drop: [%s] [%d] [%s(%d)] [%s] [%s]\n",
				tmpTime,
				EventField.EvendID.getValue(),
				EventField.EventName.getValue(),
				EventField.EventNum.getValue(),
				EventField.ObjectID.getValue(),
				EventField.EventDes.getValue());
			continue;
		}

		m_mapEventDumpTime[iEventNum] = CurrTime;

		WriteMsg(
			GenMsgFileName(),
			GenNetDeviceEventContent(
					EventInfo.m_EventField,
					EventInfo.m_strDevice,
					EventInfo.m_strParty,
					EventInfo.m_iTimes));
		iCount++;
	}

	return iCount;
}

int CMsgGenerator::AddNetDeviceEventMsg(
	CFTDRtnWarningEventField &EventField,
	string	&Device,
	string	&Party,
	int Times)
{
	char *pMonDate = (char *)EventField.MonDate.getValue();
	char *pMonTime = (char *)EventField.MonTime.getValue();
	char *pOccurDate = (char *)EventField.OccurDate.getValue();
	char *pOccurTime = (char *)EventField.OccurTime.getValue();

	char *pDate = (strlen(pOccurDate) == 8) ? pOccurDate : pMonDate;
	char *pTime = (strlen(pOccurTime) == 8) ? pOccurTime : pMonTime;
	time_t	tCurr = m_DateTime.GetCurrTimeSec();
	time_t	tEventOccur = m_DateTime.GetTimeSec(pDate, pTime);

	/// 判断事件是否为过期事件
	if (tEventOccur < tCurr - 3600)
	{
		printf(
			"Info: Drop timeout EVENT[%d %s(%d) %s]\nNow[%ld] Occur[%ld]\n",
			EventField.EvendID.getValue(),
			EventField.EventName.getValue(),
			EventField.EventNum.getValue(),
			EventField.ObjectID.getValue(),
			tCurr,
			tEventOccur);
	}
	else
	{
		m_lEvents.add(CMsgNMEvent(EventField, Device, Party, Times));
	}

	return m_lEvents.size();
}

char *CMsgGenerator::GenNetDeviceEventContent(
	CFTDRtnWarningEventField &EventField,
	string	&Device,
	string	&Party,
	int Times)
{
	static char szContent[4096];
	string	strParty = Party.empty() ? "" : " [" + Party + "] ";

	/// 如果消息不分组，那么一个事件只发送一次，消息序列号可参考事件ID号
	UINT64	seq = m_DateTime.GetCurrTimeSec() * 1000000 + EventField.EvendID;

	/// 消息接口：<Message MessageId="200" Category="300" SubjectId="" Level="1" TransferType="mail" Receiver="name@xxx.com" Content="this is content" UpdateTime="2009-02-26 11:11:11" MaxRetry="3" RetrySpan="300" MaxWait="" RequestReply="0" CopyTo="" EventId="" />
		/// 内容示例："<Message MessageId=\"%llu\" SubjectId=\"%s\" MonDate=\"%s\" MonTime=\"%s\" Content=\"%s %s %s[%s %s]%s%s(已发生%d次)\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n"
		/// 消息示例："20111215 08:00:00 EventName[Level3] [DeviceName-172.1.128.111] [Party] EventComments(已发生5次)"
	sprintf(
		szContent,
		"<Message MessageId=\"%llu\" SubjectId=\"%s\" DumpDate=\"%s\" DumpTime=\"%s\" MonDate=\"%s\" MonTime=\"%s\" Content=\"%s %s %s[%s] [%s %s]%s%s(已发生%d次)\" MaxRetry=\"%d\" RetrySpan=\"%d\" SenderId=\"%s\" />\r\n",
		seq,
		"NM_All",
		m_DateTime.GetDateStr().c_str(),
		m_DateTime.GetTimeStr().c_str(),
		EventField.MonDate.getValue(),
		EventField.MonTime.getValue(),
		EventField.OccurDate.getValue(),
		EventField.OccurTime.getValue(),
		EventField.EventName.getValue(),
		EventField.WarningLevel.getValue(),
		Device.c_str(),
		EventField.IPAddress.getValue(),
		strParty.c_str(),
		EventField.EventDes.getValue(),
		Times,
		m_iMaxRetry,
		m_iRetrySpan,
		m_strSystemID.c_str());
	return szContent;
}

int CMsgGenerator::WriteMsg(char *pszFile, char *pszMsg)
{
	g_lockMsgFile.Lock();

	FILE *fp = fopen(pszFile, "a"); // append mode
	if (fp == NULL)
	{
		printf("[ERROR]In function writeMsg: open file %s failed\n", pszFile);
		return 1;
	}

#ifdef PRINT_DEBUG
	printf("Generate Msg:\n%s", pszMsg);
#endif
	fwrite(pszMsg, strlen(pszMsg), 1, fp);
	fflush(fp);
	fclose(fp);
	g_lockMsgFile.UnLock();
	return 0;
}

void CMsgGenerator::RefreshDateTime(void)
{
	m_DateTime.FreshTime();
}

char *CMsgGenerator::GenMsgFileName(void)
{
	static char szFileName[512];
	sprintf(
		szFileName,
		"%s%s.im",
		m_strPath.c_str(),
		m_DateTime.GetDateStr().c_str());
	return szFileName;
}
