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
	if (m_strStartTime.compare(g_szTimeBuffer) > 0
	||	m_strEndTime.compare(g_szTimeBuffer) < 0)
	{
		return false;
	}

	return true;
}

bool CPackageFilter::CheckEventOutput(void)
{
	return (!g_bAnalysisRTT && CheckTime() && m_DesiredTids.size() == 0);
}
