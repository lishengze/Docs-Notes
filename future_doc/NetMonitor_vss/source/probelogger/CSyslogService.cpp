/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CSyslogService.cpp
///@brief	ʵ����ʹ��syslogʵ��̽��ӿ�
///@history 
///20060716	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////
#ifdef UNIX

#include "CSyslogService.h"

void CSyslogService::SendProbeMessageImpl
	(
		const char *programName,
		const int globalSeq,
		const char *parameter,
		const char *value
	)
{
	syslog( LOG_INFO, "%s %s\n", parameter, value );
}

#endif
