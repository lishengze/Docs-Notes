#ifndef _PRJ_COMMON_H
#define _PRJ_COMMON_H

#include <CLogger.h>
#include <string>
#include <time.h>
#include "CDeployConfig.h"
#include "systools.h"

// 在windows平台下，使用windows的dbg版本的crt来检测内存泄露
#ifdef WIN32
#ifdef _DEBUG
#include <crtdbg.h>
#define new			new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define malloc(cb)	_malloc_dbg((cb), _NORMAL_BLOCK, __FILE__, __LINE__)
#endif // end _DEBUG
#endif // end WIN32
#define DISALLOW_COPY_AND_ASSIGN(type) \
	type (const type &);			   \
	void operator = (const type &)
#define ARRAY_LEN(a)	sizeof(a) / sizeof((a)[0])

// 定义字符串
#ifdef WIN32
#define SNPRINTF	_snprintf
#else
#define SNPRINTF	snprintf
#endif
#ifdef PACKAGE_OUTPUT
extern CLogger *g_pPackOutput;		// 数据包输出到文件
#endif

// define log helper macro
extern CFileLogger	*g_traceLog;	//系统运行日志
#ifdef LOG_DEBUG
#undef LOG_DEBUG

//g_traceLog->outputLevelHeader(LL_DEBUG);
#define LOG_DEBUG(...)							   \
	do											   \
	{											   \
		g_traceLog->output(LL_DEBUG, __VA_ARGS__); \
	} while (0)
#endif
#ifdef LOG_INFO
#undef LOG_INFO

//g_traceLog->outputLevelHeader(LL_INFO);
#define LOG_INFO(...)							   \
	do											   \
	{											   \
		g_traceLog->output(LL_DEBUG, __VA_ARGS__); \
	} while (0)
#endif
#ifdef LOG_WARNING
#undef LOG_WARNING

//g_traceLog->outputLevelHeader(LL_WARNING);
#define LOG_WARNING(...)						   \
	do											   \
	{											   \
		g_traceLog->output(LL_DEBUG, __VA_ARGS__); \
	} while (0)
#endif
#ifdef LOG_ERROR
#undef LOG_ERROR

//g_traceLog->outputLevelHeader(LL_ERR);
#define LOG_ERROR(...)							   \
	do											   \
	{											   \
		g_traceLog->output(LL_DEBUG, __VA_ARGS__); \
	} while (0)
#endif

				// 返回当前时区的时间
				inline const char *CurrentTime(void)
			{
				time_t	t;
				time(&t);
				return ctime(&t);
			}

// 返回object ID所包含的数据中心标志
inline CDataCenterFlagType GetCenterFromOID(string oid)
{
	string	center = oid.substr(0, oid.find('.'));	// OID is like zhangjiang.xxx.xxx.xxx
	return CDeployConfig::TransCenterFlag(center.c_str());
}

void LogPkg(
		CFTDCPackage *pkg,
		CBufferLogger *bufLogger,
		CFileLogger *fileLogger);
#endif //_PRJ_COMMON_H
