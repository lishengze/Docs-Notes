/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	WebLogStatics.h
///@brief	定义了apache access.log 分析使用的类
///@history
///20091201	周建军		创建该文件
#ifndef REF_WEBLOGSTATICS_H
#define REF_WEBLOGSTATICS_H

#include "public.h"
#include "Thread.h"
#include "systools.h"
#include "CachedFileFlow.h"
#include "DatabaseSpiImpl.h"
#include "FTDCSession.h"
#include "FtdPackageDesc.h"

#define VALID_SUFFIX	"html|htm|jsp|so|"	// 定义有效的页面文件后缀,以符号'|'结束及分隔
#define VALID_TOP_NUM	30					// 定义有效的TopN
#define MAX_REC_NUM		1000000				// 定义最大保留的历史记录数
#define MAX_REC_LEN		10240				// 定义了单条日志记录的最长字节数
void showTimestamp(void);
UINT64	getDateTimeNumber(tm *ptime);
UINT64	getDateTimeNumber(
			int year,
			int mon,
			int day,
			int hour,
			int min,
			int sec);

class CAccessLogConfig
{
	/* */
	public:
		CAccessLogConfig(void)
		{
			ServerName = "";
			FilePath = "";
			StatSeps = 0;
			StatRange = 0;
		}

		CAccessLogConfig(
		const char	*pName,
		const char	*pPath,
		const char	*pSeps,
		const char	*pRange)
		{
			ServerName = pName;
			FilePath = pPath;
			StatSeps = atoi(pSeps);
			StatRange = atoi(pRange);
		}

		void operator=(const CAccessLogConfig &rhs)
		{
			ServerName = rhs.ServerName;
			FilePath = rhs.FilePath;
			StatSeps = rhs.StatSeps;
			StatRange = rhs.StatRange;
		}

		~CAccessLogConfig(void)
		{
		}

		// Apache 服务器名称
		string	ServerName;

		// AccessLog 日志全路径
		string	FilePath;

		// 日志统计频率
		int StatSeps;

		// 日志统计时间范围（前N秒）
		int StatRange;
};

// 保存string - int 映射对,用于排序
class CStringIntObj
{
	/* */
	public:
		bool operator < (const CStringIntObj &rhs)const
		{
			return m_mValue > rhs.m_mValue;
		}

	/* */
	public:
		string	m_mKey;
		int m_mValue;
};
void addMapObjectCount(map<string, int> &Map, char *pszObj);

// 此类型用于单条访问记录的格式解析和加载
class CAccessRecord
{
	/* */
	public:
		CAccessRecord(void)
		{
		}

		~CAccessRecord(void)
		{
		}

		bool operator < (const CAccessRecord &rhs)const
		{
			return lTime < rhs.lTime;
		}

		bool operator>=(const CAccessRecord &rhs) const
		{
			return lTime >= rhs.lTime;
		}

		bool operator < (const UINT64 time)const
		{
			return lTime < time;
		}

		bool operator>=(const UINT64 time) const
		{
			return lTime >= time;
		}

		bool loadRecord(char *pszBuf)
		{
			static char szIP_tmp[MAX_REC_LEN];
			static char szStatus_tmp[MAX_REC_LEN];
			static char szBytes_tmp[MAX_REC_LEN];
			static char szURL_tmp[MAX_REC_LEN];
			static char szTime_tmp[MAX_REC_LEN];
			memset(szTime_tmp, 0x00, sizeof(szTime_tmp));
			memset(szIP_tmp, 0x00, sizeof(szIP_tmp));
			memset(szStatus_tmp, 0x00, sizeof(szStatus_tmp));
			memset(szBytes_tmp, 0x00, sizeof(szBytes_tmp));
			memset(szURL_tmp, 0x00, sizeof(szURL_tmp));

			int iRtn = sscanf(
					pszBuf,
					"%s - - [%s %*s \"GET %s %*s %s %s",
					szIP_tmp,
					szTime_tmp,
					szURL_tmp,
					szStatus_tmp,
					szBytes_tmp);
			if (iRtn == 5)
			{
				doClear();
				memcpy(szIP, szIP_tmp, sizeof(szIP) - 1);
				memcpy(szTime, szTime_tmp, sizeof(szTime) - 1);
				memcpy(szURL, szURL_tmp, sizeof(szURL) - 1);
				memcpy(szStatus, szStatus_tmp, sizeof(szStatus) - 1);
				memcpy(szBytes, szBytes_tmp, sizeof(szBytes) - 1);

				char *p = NULL;
				if ((p = strchr(szURL, '?')) != NULL)
				{
					*p = 0x00;	// 截断jsp等服务页面检索语句
				}

				return loadTime();
			}

			return false;
		}

		void doClear(void)
		{
			lTime = 0;
			memset(szTime, 0x00, sizeof(szTime));
			memset(szIP, 0x00, sizeof(szIP));
			memset(szStatus, 0x00, sizeof(szStatus));
			memset(szBytes, 0x00, sizeof(szBytes));
			memset(szURL, 0x00, sizeof(szURL));
		}

	/* */
	private:
		bool loadTime(void)
		{
			int iYear;

			int iMon;

			int iDay;

			int iHour;

			int iMin;

			int iSec;
			char szMon[40] = "";

			// 解析格式如"24/Nov/2009:04:36:49"
			int iRtn = sscanf(
					szTime,
					"%d/%[A-Z|a-z]/%d:%d:%d:%d",
					&iDay,
					szMon,
					&iYear,
					&iHour,
					&iMin,
					&iSec);
			if (iRtn == 6)
			{
				iMon = getIntMonth(szMon);
				lTime = getDateTimeNumber(iYear, iMon, iDay, iHour, iMin, iSec);

				//			printf("Current time is : %ld, %04d/%02d/%02d %02d:%02d:%02d\n", lTime, iYear, iMon, iDay, iHour, iMin, iSec);
				return true;
			}

			printf("Failed to get Time!\n");
			return false;
		}

		bool loadURL(char *pszTask)
		{
			static char szTmp[MAX_REC_LEN];
			memset(szTmp, 0x00, sizeof(szTmp));

			// 仅加载 "GET ..." 项
			int iRtn = sscanf(pszTask, "GET %[^ ] %*s", szTmp);
			if (iRtn == 1)
			{
				memcpy(szURL, szTmp, sizeof(szURL) - 1);
				return true;
			}

			return false;
		}

		int getIntMonth(char *pszMonth)
		{
			if (pszMonth != NULL)
			{
				if (strcmp(pszMonth, "Jan") == 0)
				{
					return 1;
				}
				else if (strcmp(pszMonth, "Feb") == 0)
				{
					return 2;
				}
				else if (strcmp(pszMonth, "Mar") == 0)
				{
					return 3;
				}
				else if (strcmp(pszMonth, "Apr") == 0)
				{
					return 4;
				}
				else if (strcmp(pszMonth, "May") == 0)
				{
					return 5;
				}
				else if (strcmp(pszMonth, "Jun") == 0)
				{
					return 6;
				}
				else if (strcmp(pszMonth, "Jul") == 0)
				{
					return 7;
				}
				else if (strcmp(pszMonth, "Aug") == 0)
				{
					return 8;
				}
				else if (strcmp(pszMonth, "Sep") == 0)
				{
					return 9;
				}
				else if (strcmp(pszMonth, "Oct") == 0)
				{
					return 10;
				}
				else if (strcmp(pszMonth, "Nov") == 0)
				{
					return 11;
				}
				else if (strcmp(pszMonth, "Dec") == 0)
				{
					return 12;
				}
			}

			return 0;
		}

	/* */
	public:
		UINT64	lTime;
		char szIP[16];
		char szStatus[16];
		char szBytes[16];
		char szURL[512];
		char szTime[22];
};

// 此类用于保存已经成功解析的单个URL相关记录数据
class CURLAccessInfo
{
	/* */
	public:
		CURLAccessInfo(void)
		{
			m_mCount = 0;
		}

		CURLAccessInfo(char *pszURL)
		{
			m_mURL = pszURL;
			m_mCount = 0;
		}

		~CURLAccessInfo(void)
		{
		}

		void addAccessInfo(char *pszIP)
		{
			addMapObjectCount(map_IP2Num, pszIP);
			m_mCount++;
		}

		void addAccessInfo(CAccessRecord record)
		{
			addMapObjectCount(map_IP2Num, record.szIP);
			m_mCount++;
		}

	/* */
	public:
		string	m_mURL;					// 保存访问的URL地址
		map<string, int> map_IP2Num;	// 保存对象及其出现次数的map
		int m_mCount;					// 保存该URL所有的访问计数
};

void sortStringIntMap(map<string, int> &Map, list<CStringIntObj> &List);
void sortStringIntMap(
		map<string, CURLAccessInfo> &Map,
		list<CStringIntObj> &List);

// 此类用于保存已经成功解析的所有记录数据,并提供相应的排序和统计方法
class CAccessInfo
{
	/* */
	public:
		CAccessInfo(void)
		{
			m_mCount = 0;
			m_mStatCount = 0;
		}

		~CAccessInfo(void)
		{
		}

		void addAccessRecord(CAccessRecord record)
		{
			if (m_mCount >= MAX_REC_NUM)
			{
				dropHistoryByPercent(25);	// 清除前25%的历史
			}

			list_Record.push_back(record);	// 访问记录先存入list
			m_mCount++;
		}

		void dropHistoryRecords(void)
		{
			list_Record.clear();
			m_mCount = 0;
		}

		void dropHistoryByTimestamp(UINT64 lTime)
		{
			list<CAccessRecord>::iterator it = list_Record.begin();
			int iCount = 0;
			for (; it != list_Record.end(); it++, iCount++)
			{
				CAccessRecord &record = (*it);
				if (record >= lTime)
				{	// 认为list记录时间为有序,找到首个时间点
					break;
				}
			}

			list_Record.erase(list_Record.begin(), it);
			m_mCount -= iCount;
			list_Record.resize(m_mCount);
			printf(
				"list<CAccessRecord> drop %d history records before %ld\n",
				iCount,
				lTime);
		}

		void dropHistoryByPercent(int percent)
		{
			list<CAccessRecord>::iterator it = list_Record.begin();
			int iNum = (percent > 0 && percent <= 100) ? m_mCount *
				percent /
				100 : m_mCount /
				4;

			for (int i = 0; i < iNum; i++, it++)
			{
				// Iterator add
			}

			list_Record.erase(list_Record.begin(), it);
			m_mCount -= iNum;
			list_Record.resize(m_mCount);
			printf(
				"list<CAccessRecord> drop %d history records by %d%%\n",
				iNum,
				percent);
		}

		bool loadAccessInfo(void)
		{
			clearAccessInfo();
			for (list<CAccessRecord>::iterator it = list_Record.begin();
				 it != list_Record.end();
				 it++)
			{
				addAccessInfo(*it);
			}

			return m_mStatCount > 0 ? true : false;
		}

		bool loadAccessInfo(UINT64 lTime)
		{
			clearAccessInfo();
			for (list<CAccessRecord>::iterator it = list_Record.begin();
				 it != list_Record.end();
				 it++)
			{
				if ((*it).lTime >= lTime)
				{
					addAccessInfo(*it);
				}
			}

			return m_mStatCount > 0 ? true : false;
		}

		bool loadAccessInfo(UINT64 lBeginTime, UINT64 lEndTime)
		{
			clearAccessInfo();
			for (list<CAccessRecord>::iterator it = list_Record.begin();
				 it != list_Record.end();
				 it++)
			{
				if ((*it).lTime >= lBeginTime && (*it).lTime < lEndTime)
				{
					addAccessInfo(*it);
				}
			}

			return m_mStatCount > 0 ? true : false;
		}

		void addAccessInfo(CAccessRecord record)
		{
			addMapObjectCount(map_IP2Num, record.szIP); // IP访问计数
			map<string, CURLAccessInfo>::iterator it = map_URL2Info.find(
					record.szURL);
			if (it == map_URL2Info.end())
			{
				CURLAccessInfo	info(record.szURL);		// 新注册一个URL信息实体
				info.addAccessInfo(record);
				map_URL2Info.insert(make_pair(record.szURL, info));
			}
			else
			{
				CURLAccessInfo	&info = it->second;		// 获取已存入的URL信息实体
				info.addAccessInfo(record);
			}

			m_mStatCount++;
		}

		void clearAccessInfo(void)
		{
			map_URL2Info.clear();
			map_IP2Num.clear();
			m_mStatCount = 0;
		}

	/* */
	public:
		map<string, CURLAccessInfo> map_URL2Info;	// 保存URL及其访问信息实体 的map对象
		map<string, int> map_IP2Num;				// 保存IP地址及其出现的次数
		list<CAccessRecord> list_Record;			// 保存访问历史记录 的list对象
		unsigned long m_mCount;
		unsigned long m_mStatCount;
};

// 此类为访问日志解析的主要功能类,负责读取文件并调用解析和统计方法类
class CAccessLogAnalyzer
{
	/* */
	public:
		CAccessLogAnalyzer(void)
		{
		}

		CAccessLogAnalyzer(const char *pszObject, const char *pszFileName)
		{
			memset(m_mszObjectName, 0x00, 33);
			strncpy(m_mszObjectName, pszObject, 32);
			memset(m_mszFileName, 0x00, 513);
			strncpy(m_mszFileName, pszFileName, 512);
			m_mlRangeStart = 0;
			m_mlRangeEnd = 0;
			if (openReadFile())
			{
				doScanFile();
			}
		}

		~CAccessLogAnalyzer(void)
		{
			closeReadFile();
		}

		bool isNewConfig(const char *pszObject, const char *pszFileName)
		{
			return strcmp(m_mszObjectName, pszObject) == 0 && strcmp(
					m_mszFileName,
					pszFileName) == 0 ? false : true;
		}

		void initMembers(void)
		{
			m_mpFile = NULL;
			m_mlHaveRead = 0;
		}

		FILE *getFilePointer(void)
		{
			return m_mpFile;
		}

		bool openReadFile(void)
		{
			initMembers();
			m_mpFile = fopen(m_mszFileName, "r");
			return m_mpFile != NULL ? (fseek(m_mpFile, 0, SEEK_SET) == 0 ? true : false) : false;
		}

		bool closeReadFile(void)
		{
			if (m_mpFile != NULL)
			{
				fclose(m_mpFile);
			}

			initMembers();
			return true;
		}

		UINT64 getRangeStart(void)
		{
			return m_mlRangeStart;
		}

		const char *getRangeStartTime(void)
		{
			return m_mszRangeStart;
		}

		const char *getRangeEndTime(void)
		{
			return m_mszRangeEnd;
		}

		UINT64 getRangeEnd(void)
		{
			return m_mlRangeEnd;
		}

		UINT64 getReadBytes(void)
		{
			return m_mlHaveRead;
		}

		unsigned long getStatRecords(void)
		{
			return m_mInfo.m_mStatCount;
		}

		unsigned long getTotalRecords(void)
		{
			return m_mInfo.m_mCount;
		}

		list<CStringIntObj> &getIPAccessList(list<CStringIntObj> &List)
		{
			sortStringIntMap(m_mInfo.map_IP2Num, List);
			return List;
		}

		list<CStringIntObj> &getURLAccessList(list<CStringIntObj> &List)
		{
			sortStringIntMap(m_mInfo.map_URL2Info, List);
			return List;
		}

		list<CStringIntObj> &getIPAccessListWithURL(
		list<CStringIntObj> &List,
		string	Url)
		{
			if (m_mInfo.map_URL2Info.find(Url) != m_mInfo.map_URL2Info.end())
			{
				sortStringIntMap(m_mInfo.map_URL2Info[Url].map_IP2Num, List);
			}

			return List;
		}

		const char *getObjectName(void)
		{
			return m_mszObjectName;
		}

		void dropHistoryByTime(time_t tTime);

		void doReadFile(void);

		void doScanFile(void);

		bool doStat(time_t tBeginTime, time_t tEndTime);

	/* */
	private:
		char m_mszFileName[513];
		char m_mszObjectName[33];
		char m_mszRangeStart[20];
		char m_mszRangeEnd[20];
		FILE *m_mpFile;
		UINT64	m_mlHaveRead;
		UINT64	m_mlRangeStart;
		UINT64	m_mlRangeEnd;

		CAccessInfo m_mInfo;
		CAccessRecord m_mRecord;
};

void showListTopN(list<CStringIntObj> &m_list);

class CWebLogStatSpiThread :
	public CThread
{
	/* */
	public:
		CWebLogStatSpiThread(void);
		~ CWebLogStatSpiThread(void);

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

	/* */
	public:
		// 用于让主程序把线程生成的数据发送出去
		void GetSpi(void);

		///用于更新网站访问日志对象函数
			///@param	pServerName	网站服务器别名
			///@param	pPath	访问日志所在路径
			///@param	pSeps	日志统计时段及频率
			///@param	pInterval	日志统计的时间区间
		void UpdateConfig(
				const char	*pServerName,
				const char	*pPath,
				const char	*pSeps,
				const char	*pInterval);

		inline void GetDateTime(void)
		{
			time_t	now;
			time(&now);
			struct tm tm_time;
			LocalTime(&now, &tm_time);			
			strftime(m_mTime, 10, "%H:%M:%S", &tm_time);
			strftime(m_mDate, 10, "%Y%m%d", &tm_time);
		}

		inline void GetGMDateTime(time_t ttime)
		{
			struct tm tm_time;
			GMTime(&ttime, &tm_time);
			strftime(m_mTime, 10, "%H:%M:%S", &tm_time);
			strftime(m_mDate, 10, "%Y%m%d", &tm_time);
		}

		void GetStatInfo(
				CFTDRtnDBQueryField &field,
				CAccessLogAnalyzer	&analyzer);
		void GetIPAccessInfo(
				CFTDRtnDBQueryField &field,
				CAccessLogAnalyzer	&analyzer);
		void GetURLAccessInfo(
				CFTDRtnDBQueryField &field,
				CAccessLogAnalyzer	&analyzer,
				const char	*pszPrefix);
		void GetStatResult(
				CAccessLogAnalyzer	&analyzer,
				time_t	datetime,
				const char	*pszPrefix);
		void GetRecordsList(
				list<string> &list_Records,
				list<CStringIntObj> &list_Info);
		void AddRtnDBQueryInfo(
				CFTDRtnDBQueryField &field,
				string	tips,
				list<string> &records);

	/* */
	private:
		///保存当前采集日期
		char m_mDate[10];

		///保存当前采集时间
		char m_mTime[10];

		CMutex	m_dataLock;
		CMutex	m_cmdLock;
		deque<CFTDRtnObjectAttrField> m_attrInfo;
		deque<CFTDRtnWarningEventField> m_eventInfo;
		deque<CFTDRtnSyslogEventField>	m_syslogInfo;
		deque<CFTDRtnDBQueryField>	m_dbqueryInfo;

		map<string, CAccessLogConfig> map_AccessLogConfig;
		map<string, CAccessLogAnalyzer *> map_AccessLogAnalyzer;

		CJudgeRun *m_pScanerRun;
		CJudgeRun *m_pStatRun;
		CJudgeRun *m_pDailyStatRun;

		///FTD数据包发送缓冲区
		CFTDCPackage m_pkgSend;
};
#endif // !defined(REF_WEBLOGSTATICS_H)
