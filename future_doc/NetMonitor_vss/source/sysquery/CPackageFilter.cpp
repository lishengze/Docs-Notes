/////////////////////////////////////////////////////////////////////////
///@system	���׼��ϵͳ
///@company	�Ϻ��ڻ���Ϣ�������޹�˾
///@file	CPackageFilter.cpp
///@brief	ʵ�������ݰ����˵���
///@auther	�Ժ��
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
