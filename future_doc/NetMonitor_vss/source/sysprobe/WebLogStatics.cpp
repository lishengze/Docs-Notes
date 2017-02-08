/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	WebLogStatics.cpp
///@brief	实现了apache access.log 分析使用的类
///@history
///20091201	周建军		创建该文件
#include "WebLogStatics.h"
#include "SyslogSpiImpl.h"

int g_iStatInterval = 0;
extern int	g_nTimeZoneSec;						// 换算成秒的时差
extern CManageConSession g_mManageConSession;	// 保存所有连接的地址信息
extern char g_pDataCenterName[32];				// 保存数据中心名称
#define DBSENDPACKAGETO g_mManageConSession.sendFTDCPackage(&m_pkgSend);

CWebLogStatSpiThread::CWebLogStatSpiThread(void)
{
	m_pkgSend.ConstructAllocate(FTDC_PACKAGE_MAX_SIZE, 512);
	m_pScanerRun = NULL;
	m_pStatRun = NULL;
	m_pDailyStatRun = NULL;
}

CWebLogStatSpiThread::~CWebLogStatSpiThread(void)
{
	ExitThread();
}

/**虚函数，子类可做一些实例化工作
* @return true:创建成功 false:创建失败
*/
bool CWebLogStatSpiThread::InitInstance(void)
{
	return true;
}

/**虚函数，子类清楚实例
*/
void CWebLogStatSpiThread::ExitInstance(void)
{
}

void CWebLogStatSpiThread::UpdateConfig(
	const char	*pServerName,
	const char	*pPath,
	const char	*pSeps,
	const char	*pInterval)
{
	map_AccessLogConfig[pServerName] = CAccessLogConfig(
			pServerName,
			pPath,
			pSeps,
			pInterval);
	m_cmdLock.Lock();

	map<string, CAccessLogAnalyzer *>::iterator it = map_AccessLogAnalyzer.find(
			pServerName);
	if (it == map_AccessLogAnalyzer.end())
	{
		CAccessLogAnalyzer	*pAnalyzer = new CAccessLogAnalyzer(
				pServerName,
				pPath);
		map_AccessLogAnalyzer.insert(make_pair(pServerName, pAnalyzer));
	}
	else if (it->second->isNewConfig(pServerName, pPath))
	{
		// 仅当配置项发生变化时，重构采样器
		printf("Get new AccessLog config item, rebuild analyzer!\n");
		delete it->second;
		map_AccessLogAnalyzer.erase(it++);

		CAccessLogAnalyzer	*pAnalyzer = new CAccessLogAnalyzer(
				pServerName,
				pPath);
		map_AccessLogAnalyzer.insert(make_pair(pServerName, pAnalyzer));
	}

	if (NULL == m_pScanerRun)
	{
		m_pScanerRun = new CJudgeRun("00:00:00-23:59:59.1");		// 每秒钟读一次日志文件
	}

	if (NULL == m_pDailyStatRun)
	{
		m_pDailyStatRun = new CJudgeRun("00:10:00-00:30:00.3600");	// 每天00:10:00作一次前一天的全天访问统计
	}

	if (NULL == m_pStatRun)
	{
		m_pStatRun = new CJudgeRun(pSeps);
	}

	g_iStatInterval = atoi(pInterval) > 0 ? atoi(pInterval) : g_iStatInterval;
	m_cmdLock.UnLock();
	return;
}

/**线程开始运行，纯虚函数，子类必须继承实现
*/
void CWebLogStatSpiThread::Run(void)
{
	while (1)
	{
		time_t	nTimeZone = time((time_t *)NULL);
		nTimeZone = nTimeZone - g_nTimeZoneSec;
		if (NULL != m_pScanerRun)
		{
			if (m_pScanerRun->needExcute(nTimeZone))
			{
				m_cmdLock.Lock();
				for (map < string, CAccessLogAnalyzer * >::iterator it =
						 map_AccessLogAnalyzer.begin();
				 it != map_AccessLogAnalyzer.end();
					 it++)
				{
					m_dataLock.Lock();
					it->second->doScanFile();
					m_dataLock.UnLock();
				}

				m_cmdLock.UnLock();
			}
		}

		if (NULL != m_pStatRun)
		{
			if (m_pStatRun->needExcute(nTimeZone))
			{
				// 计算统计时间段
				time_t	nEndTime = g_iStatInterval == 0 ? nTimeZone -
					(nTimeZone % 86400 % 3600) : nTimeZone -
						(nTimeZone % 86400 % g_iStatInterval);
				time_t	nBeginTime = g_iStatInterval == 0 ? nEndTime -
					3600 : nEndTime -
					g_iStatInterval;
				m_cmdLock.Lock();
				for (map < string, CAccessLogAnalyzer * >::iterator it =
						 map_AccessLogAnalyzer.begin();
				 it != map_AccessLogAnalyzer.end();
					 it++)
				{
					if (it->second->doStat(nBeginTime, nEndTime))
					{
						m_dataLock.Lock();
						GetStatResult(*(it->second), nEndTime, "");
						m_dataLock.UnLock();
					}
				}

				m_cmdLock.UnLock();
			}
		}

		if (NULL != m_pDailyStatRun)
		{
			if (m_pDailyStatRun->needExcute(nTimeZone))
			{
				m_cmdLock.Lock();

				// 计算统计时间段
				time_t	nEndTime = nTimeZone - (nTimeZone % 86400);
				time_t	nBeginTime = nEndTime - 86400;
				for (map < string, CAccessLogAnalyzer * >::iterator it =
						 map_AccessLogAnalyzer.begin();
				 it != map_AccessLogAnalyzer.end();
					 it++)
				{
					if (it->second->doStat(nBeginTime, nEndTime))
					{
						m_dataLock.Lock();
						GetStatResult(*(it->second), nEndTime, "Daily");
						m_dataLock.UnLock();
					}

					it->second->dropHistoryByTime(nEndTime);
				}

				m_cmdLock.UnLock();
			}
		}

		SleepMs(500);
	}
}

void CWebLogStatSpiThread::GetStatResult(
	CAccessLogAnalyzer	&analyzer,
	time_t	datetime,
	const char	*pszPrefix)
{
	GetGMDateTime(datetime);

	CFTDRtnDBQueryField field;
	sprintf(
		(char *)field.ObjectID.getValue(),
		"%s.apache.%s",
		g_pDataCenterName,
		analyzer.getObjectName());
	field.MonDate = m_mDate;
	field.MonTime = m_mTime;

	GetURLAccessInfo(field, analyzer, pszPrefix);
	sprintf((char *)field.AttrType.getValue(), "%sIPAccessInfo", pszPrefix);
	GetIPAccessInfo(field, analyzer);
	sprintf((char *)field.AttrType.getValue(), "%sStatInfo", pszPrefix);
	GetStatInfo(field, analyzer);
}

void CWebLogStatSpiThread::GetStatInfo(
	CFTDRtnDBQueryField &field,
	CAccessLogAnalyzer	&analyzer)
{
	list<string> list_Records;
	char szRecord[1024];

#ifdef PRINT_DEBUG
	printf("Total Bytes:%lld\n", analyzer.getReadBytes());
	printf(
		"Total Recs :%d - %d\n",
		analyzer.getTotalRecords(),
		analyzer.getStatRecords());
	printf(
		"Time range :%lld - %lld \n",
		analyzer.getRangeStart(),
		analyzer.getRangeEnd());
#endif
	sprintf(
		szRecord,
		"BeginTime%s%s%s",
		DBSEPARATORSTRING,
		analyzer.getRangeStartTime(),
		DBSEPARATORRECORD);
	list_Records.push_back(szRecord);
	sprintf(
		szRecord,
		"EndTime%s%s%s",
		DBSEPARATORSTRING,
		analyzer.getRangeEndTime(),
		DBSEPARATORRECORD);
	list_Records.push_back(szRecord);
	sprintf(
		szRecord,
		"TotalRecords%s%ld%s",
		DBSEPARATORSTRING,
		analyzer.getTotalRecords(),
		DBSEPARATORRECORD);
	list_Records.push_back(szRecord);
	sprintf(
		szRecord,
		"StatRecords%s%ld%s",
		DBSEPARATORSTRING,
		analyzer.getStatRecords(),
		DBSEPARATORRECORD);
	list_Records.push_back(szRecord);
	AddRtnDBQueryInfo(field, "", list_Records);
}

void CWebLogStatSpiThread::GetIPAccessInfo(
	CFTDRtnDBQueryField &field,
	CAccessLogAnalyzer	&analyzer)
{
	list<CStringIntObj> m_list;
	list<string> list_Records;

#ifdef PRINT_DEBUG
	printf("\nGet Top %d IP access info:\n", VALID_TOP_NUM);
	showListTopN(analyzer.getIPAccessList(m_list));
#endif

	char szTip[1024];
	sprintf(
		szTip,
		"NO.%sIP%sCount%s",
		DBSEPARATORSTRING,
		DBSEPARATORSTRING,
		DBSEPARATORRECORD);
	GetRecordsList(list_Records, analyzer.getIPAccessList(m_list));
	AddRtnDBQueryInfo(field, szTip, list_Records);
}

void CWebLogStatSpiThread::GetURLAccessInfo(
	CFTDRtnDBQueryField &field,
	CAccessLogAnalyzer	&analyzer,
	const char	*pszPrefix)
{
	list<CStringIntObj> m_list;
	list<CStringIntObj> List;
	list<string> list_Records;

#ifdef PRINT_DEBUG
	printf("\nGet Top %d URL access info:\n", VALID_TOP_NUM);
	showListTopN(analyzer.getURLAccessList(m_list));
#endif

	char szTip[1024];
	sprintf(
		szTip,
		"NO.%sURL%sCount%s",
		DBSEPARATORSTRING,
		DBSEPARATORSTRING,
		DBSEPARATORRECORD);
	sprintf((char *)field.AttrType.getValue(), "%sURLAccessInfo", pszPrefix);
	GetRecordsList(list_Records, analyzer.getURLAccessList(m_list));
	AddRtnDBQueryInfo(field, szTip, list_Records);

	list<CStringIntObj>::iterator it = m_list.begin();
	for (int iCount = 1;
		 it != m_list.end() && iCount <= VALID_TOP_NUM;
		 it++, iCount++)
	{
#ifdef PRINT_DEBUG
		printf(
			"\nGet Top %d IP access info for URL:%s:\n",
			VALID_TOP_NUM,
			(*it).m_mKey.c_str());
		showListTopN(analyzer.getIPAccessListWithURL(List, (*it).m_mKey));
#endif
		sprintf(
			szTip,
			"NO.%sIP%sCount%s",
			DBSEPARATORSTRING,
			DBSEPARATORSTRING,
			DBSEPARATORRECORD);
		GetRecordsList(
			list_Records,
			analyzer.getIPAccessListWithURL(List, (*it).m_mKey));
		sprintf(
			(char *)field.AttrType.getValue(),
			"%sURLAccessInfo_%02d",
			pszPrefix,
			iCount);
		AddRtnDBQueryInfo(field, szTip, list_Records);
	}
}

void CWebLogStatSpiThread::GetRecordsList(
	list<string> &list_Records,
	list<CStringIntObj> &list_Info)
{
	list_Records.clear();

	char szBuf[4096];
	list<CStringIntObj>::iterator it = list_Info.begin();
	for (int iCount = 1;
		 it != list_Info.end() && iCount <= VALID_TOP_NUM;
		 it++, iCount++)
	{
		sprintf(
			szBuf,
			"%02d%s%s%s%d%s",
			iCount,
			DBSEPARATORSTRING,
			(*it).m_mKey.c_str(),
			DBSEPARATORSTRING,
			(*it).m_mValue,
			DBSEPARATORRECORD);
		list_Records.push_back(szBuf);
	}
}

void CWebLogStatSpiThread::AddRtnDBQueryInfo(
	CFTDRtnDBQueryField &field,
	string	tips,
	list<string> &records)
{
	int m_iTipLen = tips.length();
	int m_iResultLen = sizeof(field.DBQueryResult) - m_iTipLen;
	int m_iLen = 0;
	string	sResult = tips;

	for (list<string>::iterator it = records.begin(); it != records.end(); it++)
	{
		if (m_iLen + (*it).length() >= m_iResultLen)
		{
			field.DBQueryResult = sResult.c_str();
			m_dbqueryInfo.push_back(field);
			sResult = tips;
			m_iLen = 0;
		}

		sResult += (*it);
		m_iLen += (*it).length();
	}

	field.DBQueryResult = sResult.c_str();
	m_dbqueryInfo.push_back(field);
}

void CWebLogStatSpiThread::GetSpi(void)
{
	TIME_MEASURE_START(__FUNCTION__);
	m_dataLock.Lock();

	// 拿到了锁 , 进行数据发送
	deque<CFTDRtnObjectAttrField>::iterator attrIt;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnObjectAttrTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	for (attrIt = m_attrInfo.begin(); attrIt != m_attrInfo.end(); ++attrIt)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnObjectAttrField) >= FTDC_PACKAGE_MAX_SIZE)
		{
			DBSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnObjectAttrTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &(*attrIt));
	}

	if (m_pkgSend.Length() > 0)
	{
		DBSENDPACKAGETO;
	}

	m_attrInfo.clear();

	deque<CFTDRtnWarningEventField>::iterator eventIt;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnWarningEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	for (eventIt = m_eventInfo.begin(); eventIt != m_eventInfo.end(); ++eventIt)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnWarningEventField) >= FTDC_PACKAGE_MAX_SIZE)
		{
			DBSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnWarningEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &(*eventIt));
	}

	if (m_pkgSend.Length() > 0)
	{
		DBSENDPACKAGETO;
	}

	m_eventInfo.clear();

	deque<CFTDRtnSyslogEventField>::iterator syslogIt;
	m_pkgSend.PreparePackage(
			FTD_TID_RtnSyslogEventTopic,
			FTDC_CHAIN_LAST,
			FTD_VERSION);
	for (syslogIt = m_syslogInfo.begin();
		 syslogIt != m_syslogInfo.end();
		 ++syslogIt)
	{
		if (m_pkgSend.Length() +
			sizeof(CFTDRtnSyslogEventField) >= FTDC_PACKAGE_MAX_SIZE)
		{
			DBSENDPACKAGETO;
			m_pkgSend.PreparePackage(
					FTD_TID_RtnSyslogEventTopic,
					FTDC_CHAIN_LAST,
					FTD_VERSION);
		}

		FTDC_ADD_FIELD(&m_pkgSend, &(*syslogIt));
	}

	if (m_pkgSend.Length() > 0)
	{
		DBSENDPACKAGETO;
	}

	m_syslogInfo.clear();

	deque<CFTDRtnDBQueryField>::iterator dbqueryIt;
	for (dbqueryIt = m_dbqueryInfo.begin();
		 dbqueryIt != m_dbqueryInfo.end();
		 ++dbqueryIt)
	{
		m_pkgSend.PreparePackage(
				FTD_TID_RtnDBQueryTopic,
				FTDC_CHAIN_LAST,
				FTD_VERSION);
		FTDC_ADD_FIELD(&m_pkgSend, &(*dbqueryIt));
		DBSENDPACKAGETO;
	}

	m_dbqueryInfo.clear();

	m_dataLock.UnLock();
	TIME_MEASURE_END(__FUNCTION__);
	return;
}

UINT64 getDateTimeNumber(tm *ptime)
{
	return getDateTimeNumber(
			ptime->tm_year + 1900,
			ptime->tm_mon + 1,
			ptime->tm_mday,
			ptime->tm_hour,
			ptime->tm_min,
			ptime->tm_sec);
}

UINT64 getDateTimeNumber(int year, int mon, int day, int hour, int min, int sec)
{
	return
		(
			(UINT64) year *
				10000000000 +
				(UINT64) mon *
				100000000 +
				(UINT64) day *
				1000000 +
				(UINT64) hour *
				10000 +
				(UINT64) min *
				100 +
				(UINT64) sec
		);
}

void addMapObjectCount(map<string, int> &Map, char *pszObj)
{
	map<string, int>::iterator	it = Map.find(pszObj);
	if (it == Map.end())
	{
		Map[pszObj] = 1;
	}
	else
	{
		Map[pszObj] += 1;
	}
}

void sortStringIntMap(map<string, int> &Map, list<CStringIntObj> &List)
{
	List.clear();
	for (map<string, int>::iterator it = Map.begin(); it != Map.end(); it++)
	{
		CStringIntObj obj;
		obj.m_mKey = it->first;
		obj.m_mValue = it->second;
		List.push_back(obj);
	}

	List.sort();
}

void sortStringIntMap(
	map<string, CURLAccessInfo> &Map,
	list<CStringIntObj> &List)
{
	List.clear();
	for (map<string, CURLAccessInfo>::iterator it = Map.begin();
		 it != Map.end();
		 it++)
	{
		CStringIntObj obj;
		obj.m_mKey = it->first;
		obj.m_mValue = it->second.m_mCount;
		List.push_back(obj);
	}

	List.sort();
}

void showListTopN(list<CStringIntObj> &m_list)
{
	list<CStringIntObj>::iterator it = m_list.begin();
	for (int i = 1; it != m_list.end() && i <= VALID_TOP_NUM; i++, it++)
	{
		printf(" %02d: %-40s %6d\n", i, (*it).m_mKey.c_str(), (*it).m_mValue);
	}
}

void CAccessLogAnalyzer::doReadFile(void)
{
	int iBytes = 0;
	char szBuf[10240];
	memset(szBuf, 0x00, sizeof(szBuf));

	if (m_mlHaveRead > 0 && fseek(m_mpFile, m_mlHaveRead, SEEK_SET) < 0)
	{
		printf("File %s seek error!\n", m_mszFileName);
		fflush(stdout);
		return;
	}

	while (m_mpFile != NULL && !feof(m_mpFile))
	{
		if (fgets(szBuf, sizeof(szBuf) - 1, m_mpFile) == NULL)
		{
			return;
		}

		m_mlHaveRead += strlen(szBuf);
		if (m_mRecord.loadRecord(szBuf))
		{
			m_mInfo.addAccessRecord(m_mRecord);
		}
	}
}

void CAccessLogAnalyzer::doScanFile(void)
{
	static int	m_iFailedTimes = 0;
	struct stat filestat;
#ifdef PRINT_DEBUG
	printf("Current File:%s Pos:%d\n", m_mszFileName, m_mlHaveRead);
#endif
	if (m_mpFile == NULL)	// 文件加载失败时，每100次扫描后尝试重新打开文件
	{
		m_iFailedTimes++;
		if (m_iFailedTimes >= 100)
		{
			openReadFile();
		}

		return;
	}

	// stat文件失败，说明该文件被删除;文件尺寸变小，说明日志文件已发生切换。二者均需重新打开文件
	if (stat(m_mszFileName, &filestat) < 0 || filestat.st_size < m_mlHaveRead)
	{
		closeReadFile();
		openReadFile();
	}
	else if (filestat.st_size > m_mlHaveRead)
	{
		// 文件状态正常且已增长，正常读取文件
		doReadFile();
	}
}

void CAccessLogAnalyzer::dropHistoryByTime(time_t tTime)
{
	struct tm tm_time;
	GMTime(&tTime, &tm_time);	
	m_mInfo.dropHistoryByTimestamp(getDateTimeNumber(&tm_time));
}

bool CAccessLogAnalyzer::doStat(time_t tBeginTime, time_t tEndTime)
{
	struct tm tm_time;

	GMTime(&tBeginTime, &tm_time);	
	m_mlRangeStart = getDateTimeNumber(&tm_time);
	strftime(m_mszRangeStart, 20, "%Y-%m-%d %H:%M:%S", &tm_time);

	GMTime(&tEndTime, &tm_time);	
	m_mlRangeEnd = getDateTimeNumber(&tm_time);
	strftime(m_mszRangeEnd, 20, "%Y-%m-%d %H:%M:%S", &tm_time);
	
	return m_mInfo.loadAccessInfo(m_mlRangeStart, m_mlRangeEnd);
}

void showTimestamp(void)
{
	time_t	t = time(NULL);
	struct tm tm_time;
	LocalTime(&t, &tm_time);
	UINT64	lTime = getDateTimeNumber(&tm_time);
	printf("CurrentTime: %lld \n", lTime);
}
