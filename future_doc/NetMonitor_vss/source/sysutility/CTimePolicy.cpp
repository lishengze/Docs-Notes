/////////////////////////////////////////////////////////////////////////
///@system	网络监控系统
///@company	上海期货信息技术有限公司
///@file	CTimePolicy.cpp
///@brief	定义了网络监控系统共用的时间策略类和函数
///@history
///20110210	晏鹤春		创建该文件
///20110525	晏鹤春		修订注释
#include <iostream>
#include <iterator>

#include <string.h>
#include "CTimePolicy.h"
#include "utility.h"


/// CDateTime start
CDateTime::CDateTime(void)
{
	m_Time = 0;
	m_Drift = 0;
	m_bDriftOpen = false;
	memset(&m_TimeStruct, 0x00, sizeof(m_TimeStruct));
}

CDateTime::CDateTime(const CDateTime &ob)
{
	m_Time = ob.m_Time;
	m_Drift = ob.m_Drift;
	m_bDriftOpen = ob.m_bDriftOpen;
	memcpy(&m_TimeStruct, &(ob.m_TimeStruct), sizeof(m_TimeStruct));
}

CDateTime &CDateTime::operator=(const CDateTime &ob)
{
	m_Time = ob.m_Time;
	m_Drift = ob.m_Drift;
	m_bDriftOpen = ob.m_bDriftOpen;
	memcpy(&m_TimeStruct, &(ob.m_TimeStruct), sizeof(m_TimeStruct));
	return *this;
}

bool CDateTime::operator==(const CDateTime &ob)
{
	return m_Time == ob.m_Time
	&&	m_Drift == ob.m_Drift
	&&	m_bDriftOpen == ob.m_bDriftOpen
	&&	memcmp(&m_TimeStruct, &(ob.m_TimeStruct), sizeof(m_TimeStruct)) == 0;
}

CDateTime::~CDateTime(void)
{
}

void CDateTime::OpenDrift(void)
{
	m_Drift = getTimeZoneOffset();
	m_bDriftOpen = true;
}

void CDateTime::CloseDrift(void)
{
	m_bDriftOpen = false;
}

void CDateTime::TimeDrift(time_t &timesec)
{
	if (m_bDriftOpen == true)
	{
		timesec -= m_Drift;
	}
}

void CDateTime::FreshTimestamp(time_t timesec)
{
	m_Time = timesec;
}

void CDateTime::FreshTimeStruct(time_t timesec)
{
	GMTime(&timesec, &m_TimeStruct);
}

void CDateTime::FreshTime(time_t timesec)
{
	TimeDrift(timesec);
	FreshTimestamp(timesec);
	FreshTimeStruct(timesec);
}

void CDateTime::FreshTime(void)
{
	FreshTime(time(NULL));
}

time_t CDateTime::GetTimeSec(void)
{
	return m_Time;
}

time_t CDateTime::GetTimeSec(const char *pDate, const char *pTime)
{
	tm	TimeStruct;
	memset(&TimeStruct, 0x00, sizeof(TimeStruct));

	char szTmp[10];

	strcpy(szTmp, pDate);
	TimeStruct.tm_mday = atoi(szTmp + 6);
	*(szTmp + 6) = '\0';
	TimeStruct.tm_mon = atoi(szTmp + 4) - 1;
	*(szTmp + 4) = '\0';
	TimeStruct.tm_year = atoi(szTmp) - 1900;
	strcpy(szTmp, pTime);
	TimeStruct.tm_hour = atoi(szTmp);
	TimeStruct.tm_min = atoi(szTmp + 3);
	TimeStruct.tm_sec = atoi(szTmp + 6);
	return mktime(&TimeStruct) - m_Drift;
}

time_t CDateTime::GetTimeDrift(void)
{
	return m_Drift;
}

struct tm *CDateTime::GetTimeStruct(void)
{
	return &m_TimeStruct;
}

time_t CDateTime::GetCurrTimeSec(void)
{
	FreshTime();
	return m_Time;
}

struct tm *CDateTime::GetCurrTimeStruct(void)
{
	FreshTime();
	return &m_TimeStruct;
}

string CDateTime::GetYearStr(time_t timesec)
{
	char szBuf[SIZE_BUF_S];
	if (timesec > 0)
	{
		FreshTime(timesec);
	}

	sprintf(szBuf, "%04d", m_TimeStruct.tm_year + 1900);
	return string(szBuf);
}

string CDateTime::GetYearStr(void)
{
	return GetYearStr(time(NULL));
}

string CDateTime::GetMonthStr(time_t timesec)
{
	char szBuf[SIZE_BUF_S];
	if (timesec > 0)
	{
		FreshTime(timesec);
	}

	sprintf(szBuf, "%02d", m_TimeStruct.tm_mon + 1);
	return string(szBuf);
}

string CDateTime::GetMonthStr(void)
{
	return GetMonthStr(time(NULL));
}

int CDateTime::GetWeekdayNo(time_t timesec)
{
	if (timesec > 0)
	{
		FreshTime(timesec);
	}

	return m_TimeStruct.tm_wday;
}

string CDateTime::GetDayStr(time_t timesec)
{
	char szBuf[SIZE_BUF_S];
	if (timesec > 0)
	{
		FreshTime(timesec);
	}

	sprintf(szBuf, "%02d", m_TimeStruct.tm_mday);
	return string(szBuf);
}

string CDateTime::GetDayStr(void)
{
	return GetDayStr(time(NULL));
}

string CDateTime::GetDayNoStr(time_t timesec)
{
	char szBuf[SIZE_BUF_S];
	if (timesec > 0)
	{
		FreshTime(timesec);
	}

	sprintf(szBuf, "%d", m_TimeStruct.tm_wday + 40);
	return string(szBuf);
}

string CDateTime::GetDayNoStr(void)
{
	return GetDayNoStr(time(NULL));
}

string CDateTime::GetYearByDate(string strDate)
{
	return strDate.length() >= 4 ? strDate.substr(0, 4) : "";
}

string CDateTime::GetMonthByDate(string strDate)
{
	return strDate.length() >= 6 ? strDate.substr(4, 2) : "";
}

string CDateTime::GetDayByDate(string strDate)
{
	return strDate.length() >= 8 ? strDate.substr(6, 2) : "";
}

string CDateTime::GetDayNoByDate(string strDate)
{
	char szBuf[SIZE_BUF_S];
	int nYear;
	int nMonth;
	int nDay;
	sscanf(GetYearByDate(strDate).c_str(), "%04d", &nYear);
	sscanf(GetMonthByDate(strDate).c_str(), "%02d", &nMonth);
	sscanf(GetDayByDate(strDate).c_str(), "%02d", &nDay);
	m_TimeStruct.tm_year = nYear - 1900;
	m_TimeStruct.tm_mon = nMonth - 1;
	m_TimeStruct.tm_mday = nDay;
	if (mktime(&m_TimeStruct) != -1)
	{
		sprintf(szBuf, "%d", m_TimeStruct.tm_wday + 40);
		return string(szBuf);
	}
	else
	{
		return "";
	}
}

string CDateTime::GetDateStr(time_t timesec)
{
	char szBuf[SIZE_BUF_S];
	if (timesec > 0)
	{
		FreshTime(timesec);
	}

	sprintf(
		szBuf,
		"%04d%02d%02d",
		m_TimeStruct.tm_year + 1900,
		m_TimeStruct.tm_mon + 1,
		m_TimeStruct.tm_mday);
	return string(szBuf);
}

string CDateTime::GetDateStr(void)
{
	return GetDateStr(time(NULL));
}

string CDateTime::GetTimeStr(time_t timesec)
{
	char szBuf[SIZE_BUF_S];
	if (timesec > 0)
	{
		FreshTime(timesec);
	}

	sprintf(
		szBuf,
		"%02d:%02d:%02d",
		m_TimeStruct.tm_hour,
		m_TimeStruct.tm_min,
		m_TimeStruct.tm_sec);
	return string(szBuf);
}

string CDateTime::GetTimeStr(void)
{
	return GetTimeStr(time(NULL));
}

/// CDateTime end


/// CSepData start
CSepData::CSepData(void)
{
	m_lStart = 0;
	m_lEnd = 0;
	m_lGap = 0;
}

CSepData::CSepData(long lStart, long lEnd, long lGap)
{
	m_lStart = lStart;
	m_lEnd = lEnd;
	m_lGap = lGap;
}

CSepData::CSepData(const CSepData &ob)
{
	m_lStart = ob.m_lStart;
	m_lEnd = ob.m_lEnd;
	m_lGap = ob.m_lGap;
}

CSepData::~CSepData(void)
{
}

CSepData &CSepData::operator=(const CSepData &ob)
{
	m_lStart = ob.m_lStart;
	m_lEnd = ob.m_lEnd;
	m_lGap = ob.m_lGap;
	return *this;
}

bool CSepData::operator==(const CSepData &ob)
{
	return m_lStart == ob.m_lStart
	&&	m_lEnd == ob.m_lEnd
	&&	m_lGap == ob.m_lGap;
}

bool CSepData::IsInRange(time_t timesec)
{
	time_t	TimeSec = timesec % 86400;
	return TimeSec >= m_lStart && TimeSec < m_lEnd;
}

bool CSepData::IsLess(time_t timesec)
{
	time_t	TimeSec = timesec % 86400;
	return TimeSec < m_lStart;
}

bool CSepData::IsLarger(time_t timesec)
{
	time_t	TimeSec = timesec % 86400;
	return TimeSec >= m_lEnd;
}

/// CSepData end


/// CSepsInfo start
CSepsInfo::CSepsInfo(void)
{
	Init();
}

CSepsInfo::CSepsInfo(const CSepsInfo &ob)
{
	m_strTaskTime = ob.m_strTaskTime;
	m_NextRunTime = ob.m_NextRunTime;
	m_SepData = ob.m_SepData;
	m_mapStart.clear();
	m_mapEnd.clear();
	m_listSepData.clear();
	copy(
		ob.m_listSepData.begin(),
		ob.m_listSepData.end(),
		back_inserter(m_listSepData));

	map<long, long>::iterator mapIt;
	map<long, long> &mapStart = (map<long, long> &) ob.m_mapStart;
	map<long, long> &mapEnd = (map<long, long> &) ob.m_mapEnd;
	for (mapIt = mapStart.begin(); mapIt != mapStart.end(); mapIt++)
	{
		m_mapStart[mapIt->first] = mapIt->second;
	}

	for (mapIt = mapEnd.begin(); mapIt != mapEnd.end(); mapIt++)
	{
		m_mapEnd[mapIt->first] = mapIt->second;
	}
}

CSepsInfo::~CSepsInfo(void)
{
}

void CSepsInfo::Init(void)
{
	m_NextRunTime = 0;
	m_strTaskTime = "";
	m_mapStart.clear();
	m_mapEnd.clear();
}

void CSepsInfo::AddTimeSep(char *pszSep)
{
	// 后续收到的Sep串可能覆盖之前存在的相同时刻值。
	int nHourS;

	// 后续收到的Sep串可能覆盖之前存在的相同时刻值。
	int nHourE;

	// 后续收到的Sep串可能覆盖之前存在的相同时刻值。
	int nMinuteS;

	// 后续收到的Sep串可能覆盖之前存在的相同时刻值。
	int nMinuteE;

	// 后续收到的Sep串可能覆盖之前存在的相同时刻值。
	int nSecondS;

	// 后续收到的Sep串可能覆盖之前存在的相同时刻值。
	int nSecondE;
	long lTimeS;
	long lTimeE;
	long lGaps;
	if (sscanf(
			pszSep,
		"%02d:%02d:%02d-%02d:%02d:%02d.%ld",
		&nHourS,
		&nMinuteS,
		&nSecondS,
		&nHourE,
		&nMinuteE,
		&nSecondE,
		&lGaps) == 7)
	{
		lTimeS = nHourS * 3600 + nMinuteS * 60 + nSecondS;
		lTimeE = nHourE * 3600 + nMinuteE * 60 + nSecondE;
		if (lTimeS < lTimeE)
		{
			m_mapStart[lTimeS] = lGaps;
			m_mapEnd[lTimeE] = lGaps;
		}
		else
		{
			m_mapStart[lTimeE] = lGaps;
			m_mapEnd[lTimeS] = lGaps;
		}
	}
}

bool CSepsInfo::Load(string strTimeSeps)
{
	Init();

	char szBuf[SIZE_BUF_S];
	char *p = (char *)strTimeSeps.data();
	char *q = strchr(p, ',');
	while (q != NULL)
	{
		memset(szBuf, 0x00, sizeof(szBuf));
		memcpy(szBuf, p, q - p);
		AddTimeSep(szBuf);
		p = q + 1;
		q = strchr(p, ',');
	}

	strcpy(szBuf, p);
	AddTimeSep(szBuf);

	// 记录加载的策略字段
	m_strTaskTime = strTimeSeps;
	return Gernerate();
}

bool CSepsInfo::Equal(string strTimeSeps)
{
	return m_strTaskTime.compare(strTimeSeps) == 0 ? true : false;
}

bool CSepsInfo::NewJudge(time_t timesec)
{
	// 小于最近运行时间的,无需重新判断;
	if (timesec < m_NextRunTime)
	{
		return false;
	}

	// 全新校验,遍历工作时段列表,尝试找到匹配区间,并判断是否工作
	list<CSepData>::iterator itList = m_listSepData.begin();
	for (; itList != m_listSepData.end(); itList++)
	{
		// list中时段信息已排序
		// 如果小于时间区间左值,找到最近一次需运行时间
		if ((*itList).IsLess(timesec))
		{
			// 计算预期最近的下一次运行时间
			m_NextRunTime = timesec - (timesec % 86400) + (*itList).m_lStart;
			return false;
		}

		// 如果在目标时间区间内
		else if ((*itList).IsInRange(timesec))
		{
			m_SepData = (*itList);
			m_NextRunTime = timesec + m_SepData.m_lGap;
			return true;
		}
	}

	// 当日已不存在其运行时段,预期最近下一次运行时间为次日0点
	// 计算预期最近的下一次运行时间
	m_NextRunTime = timesec - (timesec % 86400) + 86400;
	return false;
}

bool CSepsInfo::JudgeRun(time_t timesec)
{
	// 是否有历史匹配信息,通过此缓存实现快速比较
	if (m_SepData.m_lEnd != 0)
	{
		// 有历史匹配信息,判断是否符合最近一次校验的时间区段
		if (timesec < m_NextRunTime)
		{
			return false;
		}

		if (m_SepData.IsInRange(timesec))
		{
			// 属于历史匹配时间段,直接引用此缓存信息快速比较	
			m_NextRunTime = timesec + m_SepData.m_lGap;
			return true;
		}
		else
		{
			// 缓存无效,进行全新匹配校验
			return NewJudge(timesec);
		}
	}
	else
	{
		// 无历史匹配信息,尝试全新检验
		m_NextRunTime = 0;
		return NewJudge(timesec);
	}
}

void CSepsInfo::AddSepData(long lStart, long lEnd, long lGap)
{
	m_listSepData.push_back(CSepData(lStart, lEnd, lGap));
}

bool CSepsInfo::Gernerate(void)
{
	if (m_mapStart.size() <= 0 || m_mapEnd.size() <= 0)
	{
		return false;
	}

	map<long, long>::iterator itMapStart = m_mapStart.begin();
	map<long, long>::iterator itMapEnd = m_mapEnd.begin();

	/// 初始化对比信息
	bool bRightMove = false;	// 右值偏移标识,用于界定引用的周期值
	long lStart;

	// 右值偏移标识,用于界定引用的周期值
	long lEnd;

	// 右值偏移标识,用于界定引用的周期值
	long lGaps;
	lStart = itMapStart->first;
	lGaps = itMapStart->second;
	itMapStart++;

	/// 此时,itMapStart指向第2个元素,itMapEnd指向第1个元素.
	while (itMapEnd != m_mapEnd.end())
	{
		// 左值必先遍历结束
		while (itMapStart != m_mapStart.end())
		{
			if (itMapStart->first >= itMapEnd->first)
			{
				// 右值偏移
				lEnd = itMapEnd->first;

				// 此处需界定引用的周期值,如前为双右值,周期直接引用后面的一个,否则引用更大的一个.
				if (bRightMove)
				{
					lGaps = itMapEnd->second;
				}
				else
				{
					lGaps = lGaps > itMapEnd->second ? lGaps : itMapEnd->second;
				}

				AddSepData(lStart, lEnd, lGaps);

				// 判断下一区段的开始位置,由左值列表及右值列表的后续值决定
				itMapEnd++;
				if (itMapStart->first > itMapEnd->first)
				{
					// 存在双右值情况,左值不再移动
					lStart = lEnd;
					bRightMove = true;
				}
				else
				{
					// 不存在双右值,左值继续偏移
					lStart = itMapStart->first;
					bRightMove = false;
					itMapStart++;
				}
			}
			else
			{
				// 左值偏移
				lEnd = itMapStart->first;
				AddSepData(lStart, lEnd, lGaps);

				lStart = itMapStart->first;
				lGaps = itMapStart->second;
				itMapStart++;
			}
		}

		if (itMapEnd != m_mapEnd.end())
		{
			// 右值偏移
			lEnd = itMapEnd->first;
			lGaps = itMapEnd->second;
			AddSepData(lStart, lEnd, lGaps);

			lStart = itMapEnd->first;
			itMapEnd++;
		}
	}

	//	ShowSepsInfo();
	return true;
}

void CSepsInfo::ShowSepsInfo(void)
{
	list<CSepData>::iterator itList = m_listSepData.begin();
	printf("SepsInfo [%s]\n", m_strTaskTime.c_str());
	for (; itList != m_listSepData.end(); itList++)
	{
		CSepData SepData = (*itList);
		printf(
			"[%6ld - %6ld][%02d:%02d:%02d - %02d:%02d:%02d][%d]\n",
			SepData.m_lStart,
			SepData.m_lEnd,
			SepData.m_lStart / 3600,
			SepData.m_lStart % 3600 / 60,
			SepData.m_lStart % 60,
			SepData.m_lEnd / 3600,
			SepData.m_lEnd % 3600 / 60,
			SepData.m_lEnd % 60,
			SepData.m_lGap);
	}
}

/// CSepsInfo end


/// CTimePolicy start
CTimePolicy::CTimePolicy(void)
{
	Init();
}

CTimePolicy::CTimePolicy(string policy)
{
	Init();
	AddPolicyStr(policy);
}

CTimePolicy::CTimePolicy(const CTimePolicy &ob)
{
	m_DateTime = ob.m_DateTime;
	m_strDateNotRun = ob.m_strDateNotRun;
	m_strDateRun = ob.m_strDateRun;
	m_strTimeSeps = ob.m_strTimeSeps;
	m_SepsInfo = ob.m_SepsInfo;
	copy(
		ob.m_listPolicys.begin(),
		ob.m_listPolicys.end(),
		back_inserter(m_listPolicys));

	map<string, map<string, string> >::iterator mapIt_main;
	map<string, map<string, string> > &Policy =
		(map < string, map<string, string> > &) ob.m_mapPolicys;
	map<string, string>::iterator mapIt_child;
	for (mapIt_main = Policy.begin(); mapIt_main != Policy.end(); mapIt_main++)
	{
		map<string, string> &mapDayPolicy =
			(map<string, string> &) mapIt_main->second;
		map<string, string> mapPolicys;
		for (mapIt_child = mapDayPolicy.begin();
			 mapIt_child != mapDayPolicy.end();
			 mapIt_child++)
		{
			mapPolicys[mapIt_child->first] = mapIt_child->second;
		}

		m_mapPolicys[mapIt_main->first] = mapPolicys;
	}
}

CTimePolicy &CTimePolicy::operator=(const CTimePolicy &ob)
{
	m_DateTime = ob.m_DateTime;
	m_strDateNotRun = ob.m_strDateNotRun;
	m_strDateRun = ob.m_strDateRun;
	m_strTimeSeps = ob.m_strTimeSeps;
	m_SepsInfo = ob.m_SepsInfo;
	copy(
		ob.m_listPolicys.begin(),
		ob.m_listPolicys.end(),
		back_inserter(m_listPolicys));

	map<string, map<string, string> >::iterator mapIt_main;
	map<string, map<string, string> > &Policy =
		(map < string, map<string, string> > &) ob.m_mapPolicys;
	map<string, string>::iterator mapIt_child;
	for (mapIt_main = Policy.begin(); mapIt_main != Policy.end(); mapIt_main++)
	{
		map<string, string> &mapDayPolicy =
			(map<string, string> &) mapIt_main->second;
		map<string, string> mapPolicys;
		for (mapIt_child = mapDayPolicy.begin();
			 mapIt_child != mapDayPolicy.end();
			 mapIt_child++)
		{
			mapPolicys[mapIt_child->first] = mapIt_child->second;
		}

		m_mapPolicys[mapIt_main->first] = mapPolicys;
	}

	return *this;
}

bool CTimePolicy::operator==(const CTimePolicy &ob)
{
	bool Result = false;
	if (m_listPolicys.size() == ob.m_listPolicys.size())
	{
		Result = true;

		list<string> listPolicys = ob.m_listPolicys;
		listPolicys.sort();
		m_listPolicys.sort();

		list<string>::iterator	iter1 = m_listPolicys.begin();
		list<string>::iterator	iter2 = listPolicys.begin();
		for (; iter1 != m_listPolicys.end(); iter1++, iter2++)
		{
			Result = Result & ((*iter1) == (*iter2));
		}
	}

	return Result;
}

CTimePolicy::~CTimePolicy(void)
{
}

void CTimePolicy::Init(void)
{
	m_DateTime.OpenDrift();
	m_strDateNotRun = "";
	m_strDateRun = "";
	m_strTimeSeps = "";
	m_SepsInfo.Init();
	m_listPolicys.clear();
	m_mapPolicys.clear();
}

bool CTimePolicy::AddPolicyStr(string policy)
{
	int type = IsValidPolicy(policy);
	if (type > 0)
	{
		return JoinPolicy(policy, type);
	}
	else
	{
		return false;
	}
}

bool CTimePolicy::IsSepDigits(char *pStr, char cSepChar)
{
	int nDigit = 0;
	if (pStr != NULL && strlen(pStr) > 0)
	{
		for (int i = 0; i < strlen(pStr); i++)
		{
			if (isdigit(*(pStr + i)))
			{
				if (++nDigit > 2)	// 连续3位数字码
				{
					return false;
				}
			}
			else if (*(pStr + i) == cSepChar)
			{
				if (nDigit < 2)
				{
					return false;
				}
				else
				{
					nDigit = 0;
				}
			}
		}

		return nDigit == 0 ? false : true;
	}

	return false;
}

bool CTimePolicy::IsValidTimeSep(char *p)
{
	return
		(
			*(p + 2) == ':'
		&&	*(p + 5) == ':'
		&&	*(p + 8) == '-'
		&&	*(p + 11) == ':'
		&&	*(p + 14) == ':'
		&&	*(p + 17) == '.'
		);
}

bool CTimePolicy::IsTimeSeps(char *pStr)
{
	char *p = pStr;
	while (p != NULL)
	{
		if (IsValidTimeSep(p))
		{
			p = strchr(p, ',');
			if (p != NULL)
			{
				p++;
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}

int CTimePolicy::IsValidPolicy(string policy)
{
	// Policy String should like this :
	// 1: Months;Days;TimeGap;
	// 01,03,05;10,12,20,22,50,56;00:00:30-01:00:30.300,02:00:30-23:59:59.600;
	// 2: Only TimeGap;
	// 00:00:30-01:00:30.300,02:00:30-23:59:59.600
	if (policy.length() > 0 && policy.length() < SIZE_BUF)
	{
		bool bResult = false;
		char szBuf[SIZE_BUF];
		memset(szBuf, 0x00, sizeof(szBuf));

		int iLen = policy.copy(szBuf, policy.length(), 0);
		char *p = NULL;

		if (isdigit(szBuf[0]))
		{
			/// 尝试匹配标准1
			if (szBuf[iLen - 1] == ';')
			{
				p = strtok(szBuf, ";");
				if (IsSepDigits(p, ','))
				{
					bResult = true;

					int iCount = 1;
					while ((p = strtok(NULL, ";")) != NULL)
					{
						iCount++;
						if (iCount % 3 == 0)
						{
							bResult = bResult && IsTimeSeps(p);			// 时段串
						}
						else
						{
							bResult = bResult && IsSepDigits(p, ',');	// 月份\日份串
						}
					}

					return bResult == true ? 1 : 0;
				}
			}

			/// 尝试匹配标准2
			else
			{
				p = strtok(szBuf, ",");
				if (IsTimeSeps(p))
				{
					bResult = true;
					while ((p = strtok(NULL, ",")) != NULL)
					{
						bResult = bResult && IsTimeSeps(p);
					}

					return bResult == true ? 2 : 0;
				}
			}
		}
	}

	return 0;
}

bool CTimePolicy::JoinPolicy(string policy, int type)
{
	string	strMonths;

	string	strDays;

	string	strTimes;
	if (type == 1)
	{
		int nPos1 = policy.find(';', 0);
		int nPos2 = policy.find(';', nPos1 + 1);

		strMonths = policy.substr(0, nPos1);
		strDays = policy.substr(nPos1 + 1, nPos2 - nPos1 - 1);
		strTimes = policy.substr(nPos2 + 1, policy.length() - nPos2 - 2);
	}
	else if (type == 2)
	{
		strMonths = "00";
		strDays = "00";
		strTimes = policy;
	}
	else
	{
		return false;
	}

	if (strMonths.find("00", 0) != string::npos)
	{
		strMonths = "01,02,03,04,05,06,07,08,09,10,11,12";
	}

	if (strDays.find("00", 0) != string::npos)
	{
		strDays = "01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31";
	}

	map<string, string> mapDayTimes;
	GetDayTimesMap(strDays, strTimes, mapDayTimes);
	JoinPolicyMap(strMonths, mapDayTimes);
	m_listPolicys.push_back(policy);

	// 清理过滤记录
	m_strDateNotRun = "";
	m_strDateRun = "";
	m_strTimeSeps = "";
	return true;
}

void CTimePolicy::JoinDayTimeMaps(
	map<string, string> &mapTarget,
	map<string, string> &mapSource)
{
	map<string, string>::iterator itMap = mapSource.begin();
	for (; itMap != mapSource.end(); itMap++)
	{
		string	strSDay = itMap->first;
		string	strSTimes = itMap->second;
		if (mapTarget.find(strSDay) != mapTarget.end())
		{
			string	strDTimes = mapTarget[strSDay];

			// 多项时间策略连接时采用','进行分隔
			strDTimes.append(",");
			strDTimes.append(strSTimes);
			mapTarget[strSDay] = strDTimes;
		}
		else
		{
			mapTarget[strSDay] = strSTimes;
		}
	}
}

void CTimePolicy::JoinPolicyMap(
	string	strMonths,
	map<string, string> &mapDayTimes)
{
	int nPos1 = 0;
	int nPos2 = 0;
	while (nPos2 != string::npos)
	{
		nPos2 = strMonths.find(',', nPos1);

		string	strMonth = strMonths.substr(nPos1, nPos2 - nPos1);
		nPos1 = nPos2 + 1;

		map<string, map<string, string> >::iterator itMap = m_mapPolicys.find(
				strMonth);
		if (itMap != m_mapPolicys.end())
		{
			map<string, string> &mapDT = itMap->second;
			JoinDayTimeMaps(mapDT, mapDayTimes);
		}
		else
		{
			m_mapPolicys[strMonth] = mapDayTimes;
		}
	}

	//ShowPolicyMap();
}

void CTimePolicy::GetDayTimesMap(
	string	strDays,
	string	strTimes,
	map<string, string> &mapDayTimes)
{
	int nPos1 = 0;
	int nPos2 = 0;
	while (nPos2 != string::npos)
	{
		nPos2 = strDays.find(',', nPos1);

		string	strDay = strDays.substr(nPos1, nPos2 - nPos1);
		nPos1 = nPos2 + 1;
		if ((strDay.compare("01") >= 0 && strDay.compare("31") <= 0)
		||	(strDay.compare("40") >= 0 && strDay.compare("47") <= 0))
		{
			mapDayTimes[strDay] = strTimes;
		}
	}
}

bool CTimePolicy::ShouldRun(time_t time)
{
	if (JudgeRunDate(time))
	{
		// JudgeRunDate 已将时间及策略更新到成员对象 m_DateTime 和 m_strTimeSeps,此处不再传入参数
		return JudgeRunTime();
	}
	else
	{
		return false;
	}
}

string CTimePolicy::GetPolicyByDate(string strDate)
{
	return GetPolicyByMonthDay(
			m_DateTime.GetMonthByDate(strDate),
			m_DateTime.GetDayByDate(strDate),
			m_DateTime.GetDayNoByDate(strDate));
}

string CTimePolicy::GetPolicyByMonthDay(
	string	strMon,
	string	strDay,
	string	strDayNo)
{
	string	strPolicy = "";
	map<string, map<string, string> >::iterator itMap = m_mapPolicys.find(
			strMon);
	if (itMap != m_mapPolicys.end())
	{
		map<string, string> &mapDayTimes = itMap->second;
		if (mapDayTimes.find(strDay) != mapDayTimes.end())
		{
			strPolicy = mapDayTimes[strDay];
		}

		if (mapDayTimes.find(strDayNo) != mapDayTimes.end())
		{
			if (strPolicy.length() > 0)
			{
				strPolicy.append(",");
			}

			strPolicy.append(mapDayTimes[strDayNo]);
		}
	}

	return strPolicy;
}

bool CTimePolicy::JudgeRunDate(time_t timesec)
{
	string	strDate = m_DateTime.GetDateStr(timesec);
	if (strDate.compare(m_strDateNotRun) == 0)
	{
		// 已知此日当前任务不运行
		return false;
	}
	else if (strDate.compare(m_strDateRun) == 0)
	{
		// 已知此日当前任务需运行
		return true;
	}
	else
	{
		// 未知此日当前任务是否需运行
		// 尝试取得此日最近策略串
		string	strTimeSeps = GetPolicyByDate(strDate);
		if (strTimeSeps.length() == 0)
		{
			// 此日当前任务不运行
			m_strDateNotRun = strDate;
			return false;
		}
		else
		{
			// 此日当前任务需运行
			m_strDateRun = strDate;
			m_strTimeSeps = strTimeSeps;
			return true;
		}
	}
}

bool CTimePolicy::GetWorkMonth(list<string> &listMonth)
{
	listMonth.clear();

	map<string, map<string, string> >::iterator mapIt = m_mapPolicys.begin();
	for (; mapIt != m_mapPolicys.end(); mapIt++)
	{
		listMonth.push_back(mapIt->first);
	}

	return listMonth.size() > 0 ? true : false;
}

bool CTimePolicy::GetWorkDay(string strMonth, list<string> &listDay)
{
	listDay.clear();
	if (m_mapPolicys.find(strMonth) != m_mapPolicys.end())
	{
		map<string, string> &Map = m_mapPolicys[strMonth];
		map<string, string>::iterator mapIt = Map.begin();
		for (; mapIt != Map.end(); mapIt++)
		{
			listDay.push_back(mapIt->first);
		}
	}

	return listDay.size() > 0 ? true : false;
}

string CTimePolicy::GetLastestTimeSeps(void)
{
	return m_strTimeSeps;
}

bool CTimePolicy::JudgeRunTime(void)
{
	// 判断当日策略是否已加载
	if (m_SepsInfo.Equal(m_strTimeSeps))
	{
		// 已加载过当日策略,不重新加载	
		return m_SepsInfo.JudgeRun(m_DateTime.GetTimeSec());
	}
	else
	{
		// 未加载过当日策略,重新加载
		m_SepsInfo.Load(m_strTimeSeps);
		return m_SepsInfo.JudgeRun(m_DateTime.GetTimeSec());
	}

	return true;
}

void CTimePolicy::ShowPolicyMap(void)
{
	printf("\n\nTime Policys:\n");

	map<string, map<string, string> >::iterator itMap = m_mapPolicys.begin();
	for (; itMap != m_mapPolicys.end(); itMap++)
	{
		string	strMonth = itMap->first;
		map<string, string> &mapDayTimes = itMap->second;
		map<string, string>::iterator itDayTimes = mapDayTimes.begin();
		for (; itDayTimes != mapDayTimes.end(); itDayTimes++)
		{
			printf(
				"%s%s [%s]\n",
				strMonth.c_str(),
				itDayTimes->first.c_str(),
				itDayTimes->second.c_str());
		}
	}
}

/// CTimePolicy end
