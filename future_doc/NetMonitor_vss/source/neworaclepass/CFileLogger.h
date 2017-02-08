/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CFileLogger.h
///@brief��������CFileLogger
///@history 
///20070702 ���ٻ�		������CFileLogger��
/////////////////////////////////////////////////////////////////////////

#ifndef CFILELOGGER_H
#define CFILELOGGER_H

#include "CLogger.h"

/////////////////////////////////////////////////////////////////////////
///CFileLogger�ǻ����ļ�����־�ӿڡ�ÿ��д��������fflush()������
/////////////////////////////////////////////////////////////////////////
class CFileLogger :public CLogger
{
public:
	///���캯��
	CFileLogger()
	{
		m_pInstance = this;
		m_fpLog = NULL;
		INIT_CRITICAL_VAR(m_varCritical);
	}
	///��������
	~CFileLogger()
	{
		DELETE_CRITICAL_VAR(m_varCritical);
		if (m_fpLog!=NULL) {
			fclose(m_fpLog);
			m_fpLog = NULL;
		}
	}
	
	///����־�ļ�������
	void AttachFile(FILE *fpLog)
	{
		m_fpLog = fpLog;
	}
	///�������־�ļ���
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
	///�������־�ļ�
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
	///��־�ļ�ָ��
	FILE *m_fpLog;
	///�ٽ�������ֹ���߳̽���
	CRITICAL_VAR m_varCritical;
};

#endif
