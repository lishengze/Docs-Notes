/////////////////////////////////////////////////////////////////////////
///@system	交易监控系统
///@company	上海期货信息技术有限公司
///@file	CPackageFilter.cpp
///@brief	实现了数据包过滤的类
///@auther	赵鸿昊
///@history
#include "CPackageFilter.h"

extern char g_szTimeBuffer[10];
extern bool g_bAnalysisRTT;

bool CPackageFilter::CheckTime(void)
{
	bool bIn = false;
	for (size_t i=0; i<m_vecTimeInteral.size(); i++)
	{
		if(m_vecTimeInteral[i].startTime.compare(g_szTimeBuffer)<=0 && 
			m_vecTimeInteral[i].endTime.compare(g_szTimeBuffer)>=0)
		{
			bIn = true;
			break;
		}
	}
	return bIn;
}

bool CPackageFilter::IsolateTime(const string& timeInterval)
{
	size_t pos = timeInterval.find("-");
	if(pos != string::npos)
	{
		TimeInterval tI;
		tI.startTime = timeInterval.substr(0,pos);
		tI.endTime = timeInterval.substr(pos+1);
		tI.startTime = Trim(tI.startTime);
		tI.endTime = Trim(tI.endTime);
		m_vecTimeInteral.push_back(tI);
		return true;
	}
	else
		return false;
}

string& CPackageFilter::Trim(string &s)
{
	s.erase(0,s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	return s;
}
bool CPackageFilter::ResolveTimeIntervals(const char* timeInterval)
{
	assert(timeInterval != NULL);
	string str(timeInterval);
	string front;
	size_t pos;
	bool bResolveRight = false;
	while ((pos=str.find(";")) != string::npos)
	{
		front = str.substr(0,pos);
		if (IsolateTime(front)== false)
			return false;
		str = str.substr(pos+1);
	}
	if (IsolateTime(str)== false)
		return false;
	return true;
}
bool CPackageFilter::CheckEventOutput(void)
{
	return (!g_bAnalysisRTT && CheckTime() && m_DesiredTids.size() == 0);
}
