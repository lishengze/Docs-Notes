/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CSyslogService.cpp
///@brief	实现了使用syslog实现探针接口
///@history 
///20060716	王肇东		创建该文件
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
