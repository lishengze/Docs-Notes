#include "CSysLogReader.h"
#include "CSysLogConfig.h"
#include "CSynConnector.h"

#define READFILEINTERVAL	60
#define SIZE_BUF			4096

map<string, string> g_mapMonthStr;
list<string> g_syslogsubwordslist;

//@key	  IP地址
//@value	拼接完成的主机名ID，如Pudian.OA.router
extern TemplateMutexMap<string, string> g_mapIpHostId;

//@Key	IP地址拼接端口索引，如127.0.0.1:100101
//@Value	接口名，如Etheret0/1
extern TemplateMutexMap<string, string> g_mapIFName;
extern bool g_isMasterRole;
extern std::map<std::string, std::string> ip_objId;
extern string g_eventlevelips;

CSysLogRecord::CSysLogRecord(void)
{
	time_t timer;
	time(&timer);

	struct tm tm_time;
	LocalTime(&timer, &tm_time);

	char year[10] = { 0 };
	sprintf(year, "%d", tm_time.tm_year + 1900);

	strYear = year;
	bValidFlag = false;
}

CSysLogRecord::CSysLogRecord(char szYear)
{
	strYear = szYear;
	bValidFlag = false;
}

CSysLogRecord::CSysLogRecord(const CSysLogRecord& rec)
{
	strDate = rec.strDate;
	strTime = rec.strTime;
	strHost = rec.strHost;
	strInfo = rec.strInfo;
	strYear = rec.strYear;
	bValidFlag = rec.bValidFlag;
}

CSysLogRecord::~CSysLogRecord(void)
{
}

void CSysLogRecord::Reset(void)
{
	bValidFlag = true;
}

string CSysLogRecord::GetDateString(char *pszMonth, char *pszDay)
{
	/// Mod by Henchi, 20111208
		/// 修正日期码为个位数时可能出现的异常
	string Day = strlen(pszDay) == 1 ? string("0") + string(pszDay) : pszDay;
	string Date = strYear + string(g_mapMonthStr[pszMonth]) + Day;
	return Date;
}

bool CSysLogRecord::IsValidRec(string record)
{
	/// Mar 30 00:00:50 172.1.128.102 210476: 210472: Mar 29 23:52:31.420 BJ: %SEC-6-IPACCESSLOGP: list T-SCGL_to_T-SCHX denied udp 172.25.254.14(1985) -> 224.0.0.2(1985), 204 packets
	char *pRec = (char *)record.data();
	if (pRec[3] == ' '
	&&	pRec[6] == ' '
	&&	pRec[9] == ':'
	&&	pRec[12] == ':'
	&&	pRec[15] == ' ')
	{
		return true;
	}
	else
	{
		bValidFlag = false;
		return false;
	}
}

bool CSysLogRecord::LoadRec(string record)
{
	/// Mar 30 00:00:50 172.1.128.102 210476: 210472: Mar 29 23:52:31.420 BJ: %SEC-6-IPACCESSLOGP: list T-SCGL_to_T-SCHX denied udp 172.25.254.14(1985) -> 224.0.0.2(1985), 204 packets
	if (IsValidRec(record))
	{
		int iYear, iMonth,
				iDay,
				iHour,
				iMinite,
				iSecond;
		char szMonth[16], szDay[16],
						szTime[16],
						szHostname[64],
						szInfo[4096];

		int iRtn = sscanf(
				record.c_str(),
				"%[A-Za-z] %[0-9] %[0-9:] %s %[^\n]\n",
				szMonth,
				szDay,
				szTime,
				szHostname,
				szInfo);
		if (iRtn == 5)
		{
			if (strlen(szTime) == 7 && szTime[1] == ':')
			{
				sprintf(szTime, "0%s", szTime);
			}
			else
			{
				strTime = szTime;
			}

			trim(szInfo);

			strDate = GetDateString(szMonth, szDay);
			strHost = szHostname;
			strInfo = szInfo;
			bValidFlag = true;
			return true;
		}
	}

	printf("Get Invalid record:[%s]\n", record.c_str());
	bValidFlag = false;
	return false;
}

CSysLogReader::CSysLogReader(void)
{
	m_strFilePath = "";
	m_lReadPos = 0;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_tLastLoadTime = 0;
}

CSysLogReader::CSysLogReader(string strFilePath)
{
	m_strFilePath = strFilePath;
	m_lReadPos = 0;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_iReadTime = 0;
}

CSysLogReader::CSysLogReader(string strFilePath, long lReads)
{
	m_strFilePath = strFilePath;
	m_lReadPos = lReads;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_iReadTime = 0;
}

CSysLogReader::CSysLogReader(string strFilePath, long lReads, int iReadTime)
{
	m_strFilePath = strFilePath;
	m_lReadPos = lReads;
	m_pFile = NULL;
	m_iValidFlag = READFILEINTERVAL;
	m_tModify = 0;
	m_iReadTime = iReadTime;
}

CSysLogReader::~CSysLogReader(void)
{
}

bool CSysLogReader::InitInstance(void)
{
	return true;
}

void CSysLogReader::ExitInstance(void)
{
}

void CSysLogReader::Run(void)
{
	/* for testings
	g_mapIpHostId.add("172.1.128.101", "PuDian.oa.Dev1");
	g_mapIpHostId.add("172.1.128.102", "PuDian.oa.Dev2");
	g_mapIpHostId.add("172.1.128.1", "PuDian.oa.Dev3");

	g_mapIFName.add("172.1.128.1:8", "Port8");
	g_mapIFName.add("172.1.128.1:11", "Port11");
	g_mapIFName.add("172.1.128.1:12", "Port12");
*/
	while (1)
	{
		KeepReadFile();

#ifdef WIN32
		SLEEP(1000);
#else
		sleep(1);
#endif
	}
}

bool CSysLogReader::OpenFile(void)
{
	if (m_strFilePath.length() == 0)
	{
		return false;
	}
	else
	{
		if ((m_pFile = fopen(m_strFilePath.c_str(), "r")) == NULL)
		{
			printf("open file %s fail!\n", m_strFilePath.c_str());
			m_bReadFlag = false;
			m_iValidFlag = 0;
			return false;
		}

		printf("open file %s\n", m_strFilePath.c_str());

		/// 检索读取位置
		g_mapMonthStr["Jan"] = "01";
		g_mapMonthStr["Feb"] = "02";
		g_mapMonthStr["Mar"] = "03";
		g_mapMonthStr["Apr"] = "04";
		g_mapMonthStr["May"] = "05";
		g_mapMonthStr["Jun"] = "06";
		g_mapMonthStr["Jul"] = "07";
		g_mapMonthStr["Aug"] = "08";
		g_mapMonthStr["Sep"] = "09";
		g_mapMonthStr["Oct"] = "10";
		g_mapMonthStr["Nov"] = "11";
		g_mapMonthStr["Dec"] = "12";

		/// 找到当日日志信息
		time_t tNow;
		time(&tNow);
		struct tm tm_time;
		LocalTime(&tNow, &tm_time);
		char szDatetime[16];
		strftime(
			szDatetime,
			sizeof(szDatetime),
			"%b %d",
			&tm_time);
		strcat(szDatetime, " 00:00:01");

		int iToday = CFileRecordFinder::DateStringToLong(szDatetime);
		m_iReadTime = m_iReadTime >= iToday ? m_iReadTime : iToday;

		CFileRecordFinder finder(m_strFilePath.c_str());

		//off_t nPos = finder.Search(m_iReadTime);
		//m_lReadPos = m_lReadPos >= nPos ? m_lReadPos : nPos;

		off_t nPos = finder.SearchNew(m_iReadTime, true);	// 表明搜索的是SysLog文件
		if (nPos == -1)	// -1 = Error!!
		{
			printf("FileName %s Search error[-1]\n", m_strFilePath.c_str());
			fflush(stdout);
			SAFE_FCLOSE(m_pFile);
			m_pFile = NULL;
			m_iValidFlag = READFILEINTERVAL;
			return false;
		}

		// m_lReadPos默认为0，Search发生错误返回-1
		// 若不加以判断，后续读取仍然出错
		m_lReadPos = m_lReadPos >= nPos ? m_lReadPos : nPos;

		if (fseek(m_pFile, m_lReadPos, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", m_strFilePath.c_str());
			fflush(stdout);
			SAFE_FCLOSE(m_pFile);
			m_pFile = NULL;
			m_iValidFlag = READFILEINTERVAL;
			return false;
		}

		return true;
	}
}

void CSysLogReader::KeepReadFile(void)
{
	struct stat filestat;

	if (m_pFile == NULL)
	{
		m_iValidFlag++;
		if (m_iValidFlag >= READFILEINTERVAL)
		{
			if (!OpenFile())
			{
				return;
			}
		}
		else
		{
			return;
		}
	}

	int iRtn = stat(m_strFilePath.c_str(), &filestat);

	if (iRtn < 0)	///stat文件失败，意味着该文件在打开过程中被删除，返回
	{
		printf("\tFileName %s stat error\n", m_strFilePath.c_str());
		fflush(stdout);
		SAFE_FCLOSE(m_pFile);
		m_iValidFlag = READFILEINTERVAL;					///stat失败后，下一次就立即尝试文件是否存在
		m_lReadPos = 0;
		return;
	}
	else if (filestat.st_size <= m_lReadPos)
	{
		//排除第一次读取的情况
		if (m_tModify > 0 && m_tModify < filestat.st_mtime) // 该文件可能被删除过内容，重新打开
		{
			SAFE_FCLOSE(m_pFile);
			m_lReadPos = 0;
			return;
		}
	}
	else if (filestat.st_size > m_lReadPos)
	{
		SAFE_FCLOSE(m_pFile);

		if ((m_pFile = fopen(m_strFilePath.c_str(), "r")) == NULL)
		{
			printf("FileName %s reopen fail!\n", m_strFilePath.c_str());
			m_bReadFlag = false;
			m_iValidFlag = 0;
			return;
		}

		if (fseek(m_pFile, m_lReadPos, SEEK_SET) < 0)
		{
			printf("FileName %s lseek error\n", m_strFilePath.c_str());
			fflush(stdout);
			SAFE_FCLOSE(m_pFile);
			m_iValidFlag = READFILEINTERVAL;
			return;
		}

		m_tModify = filestat.st_mtime;

		int iLines = 0;
		char szBuf[SIZE_BUF];

		time_t starttime = time(NULL);

		CSysLogRecord Rec;
		memset(szBuf, 0x00, sizeof(szBuf));
		while ((fgets(szBuf, sizeof(szBuf) - 1, m_pFile)) != NULL)
		{
			//			printf("[%s]",szBuf);
			iLines++;

			//m_lReadPos += strlen(szBuf);
			if (Rec.LoadRec(string(szBuf)))
			{
				m_listRecord.add(Rec);
				FilterEventsNew(Rec);
			}

			memset(szBuf, 0x00, sizeof(szBuf));
		}

		m_lReadPos = ftell(m_pFile);

		int timeused = time(NULL) - starttime;
		if (timeused)
		{
			printf(
				"lines:%d, time used %ds, timerate=%f ms per line, linerate=%f line per s\n",
				iLines,
				timeused,
				1000 * (float)timeused / iLines,
				(float)iLines / timeused);
		}

		printf("file parse over\n");
		m_bReadFlag = false;
	}
	else
	{
		m_bReadFlag = false;
	}
}

void CSysLogReader::FilterEvents(CSysLogRecord record)
{
	if (record.strInfo.find("<link>") != string::npos)
	{
		CFTDRtnWarningEventField warningEvent;

		//extern TemplateMutexMap<string, string> g_mapIpHostId;
		//extern TemplateMutexMap<string, string> g_mapIFName;
		
		
				///加入 WarningEvent
				/// Link Event
				/// _T-JY8000-B1.1-DO NOTICE  Switch OS <link>: link up on port 7
		char szDevName[64], szLevel[16],
							szEvent[128],
							szLinkStatus[8],
							szPort[8];
		int iRtn = sscanf(
				record.strInfo.c_str(),
				"%s %s %[^:]: link %s on port %s\n",
				szDevName,
				szLevel,
				szEvent,
				szLinkStatus,
				szPort);
		if (iRtn == 5)
		{
			printf(
				"\nGet Link event: [%s] [%s] [%s] [%s] [%s]\n\n",
				szDevName,
				szLevel,
				szEvent,
				szLinkStatus,
				szPort);

			string strObject, strPortName;
			g_mapIpHostId.get(record.strHost, strObject);

			string strIPPort = record.strHost + string(":") + string(szPort);
			g_mapIFName.get(strIPPort, strPortName);

			if (strObject.length() > 0 && strPortName.length() > 0)
			{
				strObject.append(".");
				strObject.append(strPortName);
				warningEvent.ObjectID = strObject.c_str();
				warningEvent.MonDate = record.strDate.c_str();
				warningEvent.MonTime = record.strTime.c_str();
				warningEvent.EventName = strcmp(
						szLinkStatus,
						"up") == 0 ? "PortUp" : "PortDown";
				warningEvent.WarningLevel = "Level3";
				warningEvent.EventDes = record.strInfo.c_str();
				warningEvent.ProcessFlag = "N";
				m_listWarningEvents.add(warningEvent);
			}
			else
			{
				printf(
					"******************** Failed to get info for host [%s] port [%s]\n",
					record.strHost.c_str(),
					szPort);
			}
		}
	}
	else
	{
		string strObjectID;
		g_mapIpHostId.get(record.strHost, strObjectID);

		if (strObjectID.length() > 0)
		{
			CFTDRtnSyslogEventField syslogEvent;
			syslogEvent.ObjectID = strObjectID.c_str();
			syslogEvent.MonDate = record.strDate.c_str();
			syslogEvent.MonTime = record.strTime.c_str();
			syslogEvent.EventName = "DeviceMsg";
			syslogEvent.WarningLevel = "Level4";
			syslogEvent.EventDes = record.strInfo.c_str();
			syslogEvent.ProcessFlag = "N";
			m_listSyslogEvents.add(syslogEvent);
		}
		else
		{
			//printf("******************** Failed to get info for host [%s]\n", record.strHost.c_str());
		}

		///加入 SyslogEvent
	}
}

void CSysLogReader::FilterEventsNew(CSysLogRecord record)
{
	int devicetype = 0;
	int companytype = 0;
	string strObjectID;
	string strDeviceType;	// 设备型号，如NXOS

	std::string curdate;
	std::string curtime;

	time_t now;
	time(&now);

	char mTime[15];
	struct tm tm_time;
	LocalTime(&now, &tm_time);
	strftime(mTime, 10, "%Y%m%d", &tm_time);
	curdate = mTime;

	strftime(mTime, 10, "%H:%M:%S", &tm_time);
	curtime = mTime;

	//remote syslog
	char ip0[16], ip1[16],
				ip2[16],
				ip3[16];
	int iRtn = sscanf(
			record.strHost.c_str(),
			"%[1-9].%[0-9].%[0-9].%[0-9]\n",
			ip0,
			ip1,
			ip2,
			ip3);
	if (iRtn == 4)
	{
		//check ip
		if (atoi(ip0) <= 255
		&&	atoi(ip1) <= 255
		&&	atoi(ip2) <= 255
		&&	atoi(ip3) <= 255)
		{
			//get info
			CSynConnector *pSyncConnector = CSynConnector::GetInstancePoint();
			if (pSyncConnector)
			{
				pSyncConnector->GetNetDeviceInfoIDByIP(
						record.strHost.c_str(),
						devicetype,
						companytype,
						strObjectID,
						&strDeviceType);
			}
		}
		else
		{
			//不过滤本地信息		
			return;
		}
	}
	else
	{
		//不过滤本地信息
		return;
	}

	//描述信息序号
	int infostart = 0;

	//描述信息起始位置
	int infostartindex = 0;

	g_mapIpHostId.get(record.strHost, strObjectID);
	if (strObjectID.length() == 0)
	{
#ifdef TEST_MODE
		test_host_data["172.1.37.151"] = "zhangjiang.access.ZJ-OAW3825-ZJH1-2N507";
		test_host_data["172.1.37.152"] = "zhangjiang.access.ZJ-OAW3560-ZJH2-ECC";
		test_host_data["172.1.37.105"] = "zhangjiang.access.ZJ-OAW3750-C5-2N509";
		test_host_data["172.1.37.106"] = "zhangjiang.access.ZJ-OAW3750-C6-2N509";
		test_host_data["172.1.37.3"] = "zhangjiang.access.ZJ-OAW4506-C1-2N504";
		test_host_data["172.1.37.4"] = "zhangjiang.access.ZJ-OAW4506-C2-2N504";
		test_host_data["172.1.37.102"] = "zhangjiang.access.ZJ-OAW3560-C2-B1-2F";
		test_host_data["172.1.37.107"] = "zhangjiang.access.ZJ-OAW3560-C7-B2-3-FCZS";
		test_host_data["172.1.37.104"] = "zhangjiang.access.ZJ-OAW3560-C4-A1-5F";
		test_host_data["172.1.37.103"] = "zhangjiang.access.ZJ-OAW3560-C3-A2-4F";
		test_host_data["172.1.37.101"] = "zhangjiang.access.ZJ-OAW3560-C1-ECC";
#endif

		//配合数据配置文件，做测试用
		std::map<std::string, string>::iterator t_it = ip_objId.find(
				record.strHost);						//查找具体设备的objid
		if (t_it == ip_objId.end())
		{
			t_it = ip_objId.find("255.255.255.255");	//通用objid
		}

		if (t_it != ip_objId.end())
		{
			strObjectID = "TEST.JY.test" + record.strHost;	//t_it->second;
			companytype = 1;
		}
	}

	if (strObjectID.length() == 0)
	{
		printf("can't get objectid for ip:%s\n", record.strHost.c_str());
		//strObjectID = "TEST.test" + record.strHost;
		//companytype = 1;
		return;
	}

	std::map<int, int>::iterator c_i = CSysLogConfigManager::Instance()
		->m_mInfoStart.find(companytype);
	if (c_i != CSysLogConfigManager::Instance()->m_mInfoStart.end())
	{
		infostart = c_i->second - 4;
		//if (strDeviceType.compare("NXOS") == 0)
		//{
		//	infostart -= 3;
		//}		
	}

	//拆分日志信息
	int curindex = 0;
	int seglen = 0; //分隔段的长度
	int count = 0;
	std::map<int, std::string>	seginfo;
	std::map<int, int>	segindex;
	string default_name = "";

	//while (record.strInfo[curindex] != '\0')
	while (curindex < record.strInfo.size())
	{
		//已经trim过，去掉了前面的空格
		if (curindex > 0
		&&	record.strInfo[curindex] == ' '
		&&	record.strInfo[curindex - 1] != ' ')
		{
			//记录描述信息起始位置
			if (count == infostart)
			{
				infostartindex = curindex - seglen;
			}

			seginfo[count] = record.strInfo.substr(curindex - seglen, seglen);
			segindex[count] = curindex - seglen;

			if( count == 6 )
			{
				//记录事件名
				default_name = seginfo[count].substr(1,seginfo[count].length()-2);
				printf("default name is [%s]\n", default_name.c_str());
			}
			count++;
			seglen = 0;
		}

		if (record.strInfo[curindex] != ' ')
		{
			seglen++;
		}

		curindex++;
	}

	if (curindex > 0 && record.strInfo[curindex - 1] != ' ')
	{
		//记录描述信息起始位置
		if (count == infostart)
		{
			infostartindex = curindex - seglen;
		}

		seginfo[count] = record.strInfo.substr(curindex - seglen);
		segindex[count] = curindex - seglen;
		count++;
	}

	//获取事件发生时间
	char eventmonth[10] = { 0 };
	char eventday[10] = { 0 };
	char eventtime[20] = { 0 };
	int eventret = sscanf(
			record.strInfo.c_str(),
			"%*[0-9:] %*[0-9:] %[A-Za-z] %[0-9] %[0-9:].%*[^\n]\n",
			eventmonth,
			eventday,
			eventtime);
	if (eventret == 3)
	{
		record.strDate = record.GetDateString(eventmonth, eventday);

		if (strlen(eventtime) == 7 && eventtime[1] == ':')
		{
			sprintf(eventtime, "0%s", eventtime);
		}
		else
		{
			record.strTime = eventtime;
		}
	}
	else
	{
		printf(
			"parse record occur time error, info:%s\n",
			record.strInfo.c_str());
	}

	//生产网端口事件，直接生成syslog事件
	if (strcasestr(record.strInfo.c_str(), "UPDOWN") != NULL
	&&	strcasestr(record.strInfo.c_str(), "interface") != NULL)
	{
		if (CSysLogConfigManager::Instance()->m_mapIPS.find(
				record.strHost) != CSysLogConfigManager::Instance()->m_mapIPS.end())
		{
			CFTDRtnSyslogEventField cc_syslogEvent;

			memset(&cc_syslogEvent, 0, sizeof(CFTDRtnSyslogEventField));

			cc_syslogEvent.ObjectID = strObjectID.c_str();
			cc_syslogEvent.MonDate = curdate.c_str();
			cc_syslogEvent.MonTime = curtime.c_str();
			cc_syslogEvent.OccurDate = record.strDate.c_str();
			cc_syslogEvent.OccurTime = record.strTime.c_str();
			if (strcasestr(record.strInfo.c_str(), "LINEPROTO") != NULL)
			{
				cc_syslogEvent.EventName = "LINEPROTO_UPDOWN";
				cc_syslogEvent.FullEventName = "线路协议状态切换";
			}

			if (strcasestr(record.strInfo.c_str(), "LINK") != NULL)
			{
				cc_syslogEvent.EventName = "LINK_CHANGED";
				cc_syslogEvent.FullEventName = "链路状态变化";
			}

			std::string infostr = record.strInfo;
			size_t npos1 = infostr.find("%");

			if (npos1 != string::npos)
			{
				size_t npos2 = infostr.find(":", npos1);
				if (npos2 != string::npos)
				{
					cc_syslogEvent.EventName = infostr.substr(
							npos1 + 1,
							npos2 - npos1 - 1).c_str();
					cc_syslogEvent.FullEventName = "";
				}

				infostr = infostr.substr(npos2 + 1);
			}

			cc_syslogEvent.EventType = "1";				//端口类型事件
			char level_buff[8] = "\0";
			sprintf(
				level_buff,
				"Level%d",
				CSysLogConfigManager::Instance()->m_mapIPS[record.strHost]);
			cc_syslogEvent.WarningLevel = level_buff;

			cc_syslogEvent.EventDes = infostr.length() >= 511 ? infostr.substr(
					0,
					511).c_str() : infostr.c_str();
			cc_syslogEvent.ProcessFlag = "N";
			cc_syslogEvent.IPAddress = record.strHost.c_str();

			m_listSyslogEvents.add(cc_syslogEvent);
			printf(
				"----------generate syslog event,ip:%s obj:%s record info:%s\n",
				record.strHost.c_str(),
				strObjectID.c_str(),
				infostr.c_str());
			return;
		}
	}

	//开始条件过滤
	std::vector<CSysLogConfigInfo>	&refConfigList =
		(std::vector<CSysLogConfigInfo> &) CSysLogConfigManager::Instance()
			->m_lConfigInfoList;
	for (int i = 0; i < refConfigList.size(); ++i)
	{
		if (refConfigList[i].m_sDeviceType.compare("0") != 0 && devicetype != 0)
		{
			//judge device type, if not match, continue;
			if (devicetype != atoi(refConfigList[i].m_sDeviceType.c_str()))
			{
				continue;
			}
		}

		if (refConfigList[i].m_sCompanyType.compare("0") != 0
		&&	companytype != 0)
		{
			//judge company type, if not match, continue;
			if (companytype != atoi(refConfigList[i].m_sCompanyType.c_str()))
			{
				continue;
			}
		}

		//提取拼接内容
		std::string appendid;

		for (int m = 0; m < refConfigList[i].m_vAppendContent.size(); ++m)
		{
			std::map<int, std::string>::iterator it = seginfo.find(
					refConfigList[i].m_vAppendContent[m]);
			if (it != seginfo.end())
			{
				appendid += ".";

				//trim, .
				string strinfo = it->second;
				while (strinfo.length() > 0)
				{
					if (strinfo.rfind(',') != std::string::npos
					||	strinfo.rfind(' ') != std::string::npos)
					{
						strinfo = strinfo.substr(0, strinfo.length() - 1);
					}
					else
					{
						break;
					}
				}

#ifdef TEST_MODE
				//test,取缩写，GigabitEthernet->G,FastEthernet->F
				if (strinfo.find("GigabitEthernet") != std::string::npos)
				{
					strinfo = "G" + strinfo.substr(strlen("GigabitEthernet"));
				}
				else if (strinfo.find("FastEthernet") != std::string::npos)
				{
					strinfo = "F" + strinfo.substr(strlen("FastEthernet"));
				}

#endif

				char *p = NULL;
				while ((p = strchr((char *)strinfo.c_str(), '.')) != NULL)
				{
					*p = '_';
				}

				appendid += strinfo;
			}
		}

		std::vector<CConditionNode> &refConditionList =
			(std::vector<CConditionNode> &) refConfigList[i].m_sEventConditionList;
		int j;
		for (j = 0; j < refConditionList.size(); ++j)
		{
			if (refConditionList[j].index == -1)
			{
				if (record.strInfo.find(
						refConditionList[j].value) == std::string::npos)
				{
					//not match, break;
					break;
				}
			}
			else if (refConditionList[j].index == 3)	//host
			{
				if (refConditionList[j].value.compare(record.strHost) == 0)
				{
					continue;
				}
				else
				{
					break;
				}
			}
			else if (refConditionList[j].index < 3)		//date time
			{
				continue;
			}
			else
			{
				int infoindex = refConditionList[j].index - 4;
				std::map<int, std::string>::iterator m_it = seginfo.find(
						infoindex);
				if (m_it != seginfo.end())
				{
					//完全匹配
					if (refConditionList[j].patternlist.size() == 0)
					{
						//printf("value:%s, info:%s\n", refConditionList[j].value.c_str(), m_it->second.c_str());					
						if (refConditionList[j].value.compare(
								m_it->second) == 0)
						{
							continue;
						}
						else
						{
							break;
						}
					}
					else
					{
						//模式匹配
						std::map<int, int>::iterator i_it = segindex.find(
								m_it->first);
						if (i_it == segindex.end())
						{
							printf(
								"impossible, two map not match, count=%d\n",
								m_it->first);
							break;
						}

						int parseindex = i_it->second;
						static char tmpbuf[1024];

						int k = 0;

						//patternlist = "abc%[0-9]ef%[0-9]gh"
						for (; k < refConditionList[j].patternlist.size(); ++k)
						{
							std::string parsestr = record.strInfo.substr(
									parseindex);
							if (parsestr.length() > 1023)
							{
								continue;
							}

							int ret = sscanf(
									parsestr.c_str(),
									refConditionList[j].patternlist[k].c_str(),
									tmpbuf);
							if (ret != 1)
							{
								//一个条件匹配失败
								break;
							}
							else
							{
								//一个条件匹配成功
								parseindex += parsestr.find(tmpbuf) + strlen(
										tmpbuf);
								continue;
							}
						}

						if (k == refConditionList[j].patternlist.size())
						{
							//当前模式匹配成功
							continue;
						}
						else
						{
							//当前模式匹配失败
							break;
						}
					}
				}
				else
				{
					//not match, break;	
					break;
				}
			}
		}

		//generate syslogevent and return		
		if (j == refConditionList.size())
		{
			//拼接objectid
			if (appendid.length() > 0)
			{
				strObjectID += appendid;
			}

			//匹配事件
			CFTDRtnWarningEventField warninglogEvent;

			memset(&warninglogEvent, 0, sizeof(CFTDRtnWarningEventField));

			warninglogEvent.ObjectID = strObjectID.c_str();
			warninglogEvent.MonDate = curdate.c_str();
			warninglogEvent.MonTime = curtime.c_str();

			warninglogEvent.OccurDate = record.strDate.c_str();
			warninglogEvent.OccurTime = record.strTime.c_str();

			warninglogEvent.EventName = refConfigList[i].m_sEventEnName.c_str();
			warninglogEvent.FullEventName = refConfigList[i].m_sEventChName.c_str();

			warninglogEvent.EventType = refConfigList[i].m_sEventTypeID.c_str();
			warninglogEvent.WarningLevel = refConfigList[i].m_sEventLevel.c_str();

			//提取描述信息
			std::string infostr = record.strInfo.substr(infostartindex);

			warninglogEvent.EventDes = infostr.length() >= 511 ? infostr.substr(
					0,
					511).c_str() : infostr.c_str();
			warninglogEvent.ProcessFlag = "N";
			warninglogEvent.IPAddress = record.strHost.c_str();

			//端口up事件
			// add: 对会员接入设备才开启此功能
			if (refConfigList[i].m_sEventTypeID.compare("1") == 0
				&& refConfigList[i].m_sOpFlag.compare("cancle") == 0)
			{
				//产生一个syslogevent
				CFTDRtnSyslogEventField syslogEvent;

				memset(&syslogEvent, 0, sizeof(CFTDRtnSyslogEventField));

				syslogEvent.ObjectID = strObjectID.c_str();
				syslogEvent.MonDate = curdate.c_str();
				syslogEvent.MonTime = curtime.c_str();

				syslogEvent.OccurDate = record.strDate.c_str();
				syslogEvent.OccurTime = record.strTime.c_str();

				syslogEvent.EventName = refConfigList[i].m_sEventEnName.c_str();
				syslogEvent.FullEventName = refConfigList[i].m_sEventChName.c_str();

				syslogEvent.EventType = refConfigList[i].m_sEventTypeID.c_str();
				syslogEvent.WarningLevel = refConfigList[i].m_sEventLevel.c_str();

				syslogEvent.EventDes = infostr.length() >= 511 ? infostr.substr(
						0,
						511).c_str() : infostr.c_str();
				syslogEvent.ProcessFlag = "N";
				syslogEvent.IPAddress = record.strHost.c_str();

				//if(g_isMasterRole)
				//{
				m_listSyslogEvents.add(syslogEvent);
				printf(
					"+++++++++++generate syslog event,ip:%s obj:%s record info:%s\n",
					record.strHost.c_str(),
					strObjectID.c_str(),
					infostr.c_str());

				//}

				// 端口UPDOWN事件的自动恢复
				// 当启用会员接入设备端口自动恢复：事件IP地址属于会员接入设备时，会进行自动处理；否则不会自动恢复
				// 当不启用会员接入设备端口自动恢复或配置中没有定义相关节点，会进行自动处理
				std::list<std::string>::iterator IPListBegin = CSysLogConfigManager::Instance()->m_MemberAccessEquipmentList.begin();
				std::list<std::string>::iterator IPListEnd = CSysLogConfigManager::Instance()->m_MemberAccessEquipmentList.end();
				if ((CSysLogConfigManager::Instance()->m_MemberAccessEquipmentFilterEnable
					&&
					find(IPListBegin, IPListEnd, record.strHost) != IPListEnd)
					||
					!CSysLogConfigManager::Instance()->m_MemberAccessEquipmentFilterEnable
					)
				{
					printf("### Received an interface UP event. Automatic recovery.\n\tObjectID:%s EventName:%s [%s %s]\n",
							record.strHost.c_str(), 
							strObjectID.c_str(), 
							warninglogEvent.EventName.getValue(),
							record.strDate.c_str(),
							record.strTime.c_str());

					//产生一个取消down事件的warning event
					warninglogEvent.ProcessFlag = "A";

					char szDealDes[64];
					sprintf(
						szDealDes,
						"[%s %s][system] automatic recovery", // 对象状态已恢复(自动处理)
						curdate.c_str(),
						curtime.c_str());
					warninglogEvent.EventDealDes = szDealDes;

					CFTDRtnWarningEventField warningAdminlogEvent;

					memset(&warningAdminlogEvent, 0, sizeof(CFTDRtnWarningEventField));

					warningAdminlogEvent.ObjectID = strObjectID.c_str();
					warningAdminlogEvent.MonDate = curdate.c_str();
					warningAdminlogEvent.MonTime = curtime.c_str();

					warningAdminlogEvent.OccurDate = record.strDate.c_str();
					warningAdminlogEvent.OccurTime = record.strTime.c_str();

					warningAdminlogEvent.EventName = "LINKADMIN_UPDOWN";
					warningAdminlogEvent.FullEventName = "链接UPDOWN";

					warningAdminlogEvent.EventType = "1";
					warningAdminlogEvent.WarningLevel = "Level4";

					//提取描述信息
					std::string infostr = "Interface ";
					infostr += strObjectID;
					infostr += ",";

					if (strstr(warninglogEvent.EventName.getValue(), "PROTO"))
					{
						infostr += "proto ";
					}

					infostr += "changed state to up";

					warningAdminlogEvent.EventDes = infostr.c_str();
					warningAdminlogEvent.ProcessFlag = "A";
					warningAdminlogEvent.IPAddress = record.strHost.c_str();
					m_listWarningEvents.add(warningAdminlogEvent);
				}
				
			}

			//if(g_isMasterRole)
			//{
			m_listWarningEvents.add(warninglogEvent);
			printf(
				"===========generate warning event,ip:%s obj:%s record info:%s\n",
				record.strHost.c_str(),
				strObjectID.c_str(),
				infostr.c_str());

			//}
			return;
		}
	}

	//级别高的未知syslog,产生2级事件,其中以syslog原文中的“事件名”中的数字标识为判断标准（<=4 即可）
	//如：SYS-3-INVMEMINT、SYS-2-MALLOCFAIL分别代表3级，2级. 
	//增加4级的日志，告警级别调整为Level3，修正现有格式的取值，包括C6KPWR-SP-4-PSOUTPUTDROP  2014.7.7
	int level = -1;
	string::size_type index_1,index_2;
	if( default_name=="" || default_name.rfind('-')==string::npos)
	{
		std::string datastr = record.strInfo;
		index_1 = datastr.find("%");
		if (index_1 != string::npos)
		{
			index_2 = datastr.find(":", index_1);
			if(index_2 != string::npos)
			{
				default_name = datastr.substr(index_1 + 1,
					index_2 - index_1 - 1).c_str();
			}
		}
	}

	bool genflag = true; //
	//std::string syslogstr = record.strInfo.substr(infostartindex);
	for( list<string>::iterator it_key = g_syslogsubwordslist.begin(); it_key != g_syslogsubwordslist.end(); it_key++ )
	{
		if( record.strInfo.find(*it_key) != string::npos )
		{
			genflag = false;
			break ;
		}
	}

	if( genflag )
	{
		if( (index_1 = default_name.rfind('-') )!=string::npos ) 
		{	
								//index_1 = default_name.find('-');
		//index_2 = default_name.rfind('-');
		//if( index_1 != string::npos && index_2 != string::npos && index_2>index_1 )
		//{
		//	level = atoi(default_name.substr( index_1+1, index_2-index_1-1 ).c_str());
		//}
			level = atoi(default_name.substr( index_1-1,1 ).c_str());
		}
		else
		{
			printf("the default name [%s] excludes improper marks,string is [%s].\n",default_name.c_str(),record.strInfo.c_str());
			level = 0;
		}
		if( level>=0 && level<=5 )
		{

			CFTDRtnWarningEventField warningEvent;
			memset(&warningEvent, 0, sizeof(CFTDRtnWarningEventField));

			warningEvent.ObjectID = strObjectID.c_str();
			warningEvent.MonDate = curdate.c_str();
			warningEvent.MonTime = curtime.c_str();
			warningEvent.OccurDate = record.strDate.c_str();
			warningEvent.OccurTime = record.strTime.c_str();

			warningEvent.EventName = default_name.c_str();
			warningEvent.FullEventName = default_name.c_str();

			warningEvent.EventType = "8";
			warningEvent.WarningLevel = "Level3";

			//提取描述信息
			std::string infostr = record.strInfo;//.substr(infostartindex);

			warningEvent.EventDes = infostr.length() >= 511 ? infostr.substr(0,511).c_str() : infostr.c_str();
			warningEvent.ProcessFlag = "N";
			warningEvent.IPAddress = record.strHost.c_str();

			m_listWarningEvents.add(warningEvent);

			return;
		}
	}

	//2013-8-5 by Lee 骨干设备日志直接产生事件告警
	list<string>::iterator it_dev = find(CSysLogConfigManager::Instance()->m_devices.begin(),
		CSysLogConfigManager::Instance()->m_devices.end(),
		record.strHost);
	if( it_dev != CSysLogConfigManager::Instance()->m_devices.end() )
	{
		CFTDRtnWarningEventField GGWarningEvent;
		memset(&GGWarningEvent, 0, sizeof(CFTDRtnWarningEventField));

		GGWarningEvent.ObjectID = strObjectID.c_str();
		GGWarningEvent.MonDate = curdate.c_str();
		GGWarningEvent.MonTime = curtime.c_str();
		GGWarningEvent.OccurDate = record.strDate.c_str();
		GGWarningEvent.OccurTime = record.strTime.c_str();

		GGWarningEvent.EventName = default_name.c_str();
		GGWarningEvent.FullEventName = default_name.c_str();

		GGWarningEvent.EventType = "8";
		GGWarningEvent.WarningLevel = "Level2";

		//提取描述信息
		std::string infostr = record.strInfo.substr(infostartindex);

		GGWarningEvent.EventDes = infostr.length() >= 511 ? infostr.substr(0,511).c_str() : infostr.c_str();
		GGWarningEvent.ProcessFlag = "N";
		GGWarningEvent.IPAddress = record.strHost.c_str();

		m_listWarningEvents.add(GGWarningEvent);

		return;
	}

	//非匹配事件
	CFTDRtnSyslogEventField syslogEvent;

	memset(&syslogEvent, 0, sizeof(CFTDRtnSyslogEventField));

	syslogEvent.ObjectID = strObjectID.c_str();
	syslogEvent.MonDate = curdate.c_str();
	syslogEvent.MonTime = curtime.c_str();
	syslogEvent.OccurDate = record.strDate.c_str();
	syslogEvent.OccurTime = record.strTime.c_str();
	syslogEvent.EventName = "";
	syslogEvent.FullEventName = "";

	std::string infostr = record.strInfo;
	size_t npos1 = infostr.find("%");

	if (npos1 != string::npos)
	{
		size_t npos2 = infostr.find(":", npos1);
		if (npos2 != string::npos)
		{
			syslogEvent.EventName = infostr.substr(
					npos1 + 1,
					npos2 - npos1 - 1).c_str();
			syslogEvent.FullEventName = "";
		}

		infostr = infostr.substr(npos2 + 1);
	}

	syslogEvent.EventType = "8";
	syslogEvent.WarningLevel = "Level4";

	syslogEvent.EventDes = infostr.length() >= 511 ? infostr.substr(
			0,
			511).c_str() : infostr.c_str();
	syslogEvent.ProcessFlag = "N";
	syslogEvent.IPAddress = record.strHost.c_str();

	//if(g_isMasterRole)
	//{
	m_listSyslogEvents.add(syslogEvent);
	printf(
		"----------generate syslog event,ip:%s obj:%s record info:%s\n",
		record.strHost.c_str(),
		strObjectID.c_str(),
		infostr.c_str());

	//}
}
