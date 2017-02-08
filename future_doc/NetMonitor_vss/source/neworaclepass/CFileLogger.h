/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CFileLogger.h
///@brief定义了类CFileLogger
///@history 
///20070702 严少辉		增加了CFileLogger类
/////////////////////////////////////////////////////////////////////////

#ifndef CFILELOGGER_H
#define CFILELOGGER_H

#include "CLogger.h"

/////////////////////////////////////////////////////////////////////////
///CFileLogger是基于文件的日志接口。每次写入后均调用fflush()函数。
/////////////////////////////////////////////////////////////////////////
class CFileLogger :public CLogger
{
public:
	///构造函数
	CFileLogger()
	{
		m_pInstance = this;
		m_fpLog = NULL;
		INIT_CRITICAL_VAR(m_varCritical);
	}
	///析构函数
	~CFileLogger()
	{
		DELETE_CRITICAL_VAR(m_varCritical);
		if (m_fpLog!=NULL) {
			fclose(m_fpLog);
			m_fpLog = NULL;
		}
	}
	
	///与日志文件关联。
	void AttachFile(FILE *fpLog)
	{
		m_fpLog = fpLog;
	}
	///输出到日志文件。
	virtual void output(int level, char *format, ...)
	{
		if (m_fpLog==NULL)
			return;
		ENTER_CRITICAL(m_varCritical);
		va_list v;
		va_start(v,format);
		vfprintf(m_fpLog,format,v);
		va_end(v);

		fflush(m_fpLog);
		LEAVE_CRITICAL(m_varCritical);
	}
	///输出到日志文件
	virtual void output(char *format, ...)
	{
		if (m_fpLog==NULL)
			return;
		ENTER_CRITICAL(m_varCritical);
		time_t t=time(NULL);
		struct tm *pTM = localtime(&t);
		fprintf(m_fpLog, "%04d%02d%02d_%02d:%02d:%02d ",
			pTM->tm_year+1900, pTM->tm_mon+1, pTM->tm_mday,
			pTM->tm_hour, pTM->tm_min, pTM->tm_sec);
		va_list v;
		va_start(v,format);
		vfprintf(m_fpLog,format,v);
		va_end(v);

		fflush(m_fpLog);
		LEAVE_CRITICAL(m_varCritical);
	}

private:
	///日志文件指针
	FILE *m_fpLog;
	///临界区，防止多线程进入
	CRITICAL_VAR m_varCritical;
};

#endif
