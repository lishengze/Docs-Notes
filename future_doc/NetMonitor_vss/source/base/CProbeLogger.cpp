/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CProbeLogger.cpp
///@brief	实现探针的接口
///@history 
///20060716	王肇东		创建该文件
// 20110622 江鹏		NT-0138 增加系统度量功能：对CQWordMonitorIndex类和CQWordTotalMonitorIndex类提供支持
/////////////////////////////////////////////////////////////////////////

#include "CProbeLogger.h"

void CProbeLogger::SendProbeMessage(const char *parameter, const char *value)
{
	SendProbeMessageImpl(m_programName,m_globalSeq,parameter,value);
}

void CProbeLogger::SendProbeMessage(const char *parameter, const int value)
{
	char buffer[100];
	sprintf(buffer,"%d",value);
	SendProbeMessageImpl(m_programName,m_globalSeq,parameter,buffer);
}

void CProbeLogger::SendProbeMessage(const char *parameter, const double value)
{
	char buffer[100];
	sprintf(buffer,"%lf",value);
	SendProbeMessageImpl(m_programName,m_globalSeq,parameter,buffer);
}

void CProbeLogger::SendPercentageProbeMessage(const char *parameter, const double value)
{
	char buffer[100];
	sprintf(buffer,"%.2lf%%",value*100);
	SendProbeMessageImpl(m_programName,m_globalSeq,parameter,buffer);
}

void CProbeLogger::SendProbeMessage(const char *parameter, const QWORD value)
{
	char buffer[100];

#ifdef WINDOWS
	sprintf(buffer,"%I64d", value);
#else
	sprintf(buffer,"%lld", value);
#endif		

	SendProbeMessageImpl(m_programName, m_globalSeq, parameter, buffer);
}
