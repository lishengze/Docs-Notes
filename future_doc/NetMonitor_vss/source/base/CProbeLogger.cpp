/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CProbeLogger.cpp
///@brief	ʵ��̽��Ľӿ�
///@history 
///20060716	���ض�		�������ļ�
// 20110622 ����		NT-0138 ����ϵͳ�������ܣ���CQWordMonitorIndex���CQWordTotalMonitorIndex���ṩ֧��
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
