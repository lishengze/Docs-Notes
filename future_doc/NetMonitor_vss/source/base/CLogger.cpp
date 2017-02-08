/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CLogger.cpp
///@briefʵ������CLogger
///@history 
///20041218	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////
#include "CLogger.h"

///����ĺ궨��Ӱ�����ȱʡ����־���ã�������ʱ������ͨ���ı���������ֵ���ı��ȱʡ����

///ҵ����־
	///�Ƿ�ʹ��ҵ��״̬��־
	#define USE_BIZ_STATUS_LOG
	///�Ƿ�ʹ��ҵ������־
	#define USE_BIZ_OPERATION_LOG
	///�Ƿ�ʹ��ҵ���쳣��־
	#define USE_BIZ_EXCEPTION_LOG

///ͨѶ��־
	///�Ƿ�ʹ������״̬��־
	#define USE_NET_STATUS_LOG
	///�Ƿ�ʹ���������ӶϿ���־
	#define USE_NET_CONNECT_LOG
	///�Ƿ�ʹ�������շ���־
	#define USE_NET_IO_LOG
	///�Ƿ�ʹ�����籨����־
	#define USE_NET_PACKAGE_LOG
	///�Ƿ�ʹ������ѹ����־
	#define USE_NET_COMPRESS_LOG
	///�Ƿ�ʹ�������쳣��־
	#define USE_NET_EXCEPTION_LOG

///������־
	///�Ƿ�ʹ��������־
	#define USE_PROCESS_LOG


///ҵ����־
	///�Ƿ�ʹ��ҵ��״̬��־
	#ifdef USE_BIZ_STATUS_LOG
		bool UseBizStatusLog=true;
	#else
		bool UseBizStatusLog=false;
	#endif
	
	///�Ƿ�ʹ��ҵ������־
	#ifdef USE_BIZ_OPERATION_LOG
		bool UseBizOperationLog=true;
	#else
		bool UseBizOperationLog=false;
	#endif
	
	///�Ƿ�ʹ��ҵ���쳣��־
	#ifdef USE_BIZ_EXCEPTION_LOG
		bool UseBizExceptionLog=true;
	#else
		bool UseBizExceptionLog=false;
	#endif

///ͨѶ��־
	///�Ƿ�ʹ������״̬��־
	#ifdef USE_NET_STATUS_LOG
		bool UseNetStatusLog=true;
	#else
		bool UseNetStatusLog=false;
	#endif

	///�Ƿ�ʹ���������ӶϿ���־
	#ifdef USE_NET_CONNECT_LOG
		bool UseNetConnectLog=true;
	#else
		bool UseNetConnectLog=false;
	#endif

	///�Ƿ�ʹ�������շ���־
	#ifdef USE_NET_IO_LOG
		bool UseNetIOLog=true;
	#else
		bool UseNetIOLog=false;
	#endif
	
	///�Ƿ�ʹ�����籨����־
	#ifdef USE_NET_PACKAGE_LOG
		bool UseNetPackageLog=true;
	#else
		bool UseNetPackageLog=false;
	#endif
	
	///�Ƿ�ʹ������ѹ����־
	#ifdef USE_NET_COMPRESS_LOG
		bool UseNetCompressLog=true;
	#else
		bool UseNetCompressLog=false;
	#endif
	
	///�Ƿ�ʹ�������쳣��־
	#ifdef USE_NET_EXCEPTION_LOG
		bool UseNetExceptionLog=true;
	#else
		bool UseNetExceptionLog=false;
	#endif

///������־
	///�Ƿ�ʹ��������־
	#ifdef USE_PROCESS_LOG
		bool UseProcessLog=true;
	#else
		bool UseProcessLog=false;
	#endif

CLogger * CLogger::m_pInstance;

CLogger * CLogger::GetInstance()
{
	return m_pInstance;
}

void CLogger::output(int indent,int level,char *format,...)
{
	output(level,"\n");
	for (int i=0;i<indent;i++)
	{
		output(level,"\t");
	}
	va_list v;
	va_start(v,format);
	output(level,format,v);
	va_end(v);
}

void CLogger::output(char *format,...)
{
	va_list v;
	va_start(v,format);
	output(LL_DEBUG, format, v);
	va_end(v);
}


class CStdLogger :public CLogger
{
public:
	CStdLogger()
	{
		m_pInstance = this;
		INIT_CRITICAL_VAR(m_varCritical);
	}
	~CStdLogger()
	{
		DELETE_CRITICAL_VAR(m_varCritical);
	}
	
	virtual void output(int level, char *format, ...)
	{
		ENTER_CRITICAL(m_varCritical);
		va_list v;
		va_start(v,format);
		vfprintf(stdout,format,v);
		va_end(v);

		fflush(stdout);
		LEAVE_CRITICAL(m_varCritical);
	}
private:
	static CStdLogger m_stdLogger;
	CRITICAL_VAR m_varCritical;
};

CStdLogger CStdLogger::m_stdLogger;

