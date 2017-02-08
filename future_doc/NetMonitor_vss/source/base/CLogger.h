/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CLogger.h
///@brief��������CLogger
///@history 
///20041218	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CLOGGER_H
#define CLOGGER_H

#include "platform.h"

///������LOG����
#if 0
#define LL_EMERG       0       /* system is unusable */
#define LL_ALERT       1       /* action must be taken immediately */
#define LL_CRIT        2       /* critical conditions */
#define LL_ERR         3       /* error conditions */
#define LL_WARNING     4       /* warning conditions */
#define LL_NOTICE      5       /* normal but signification condition */
#define LL_INFO        6       /* informational */
#endif
#define LL_DEBUG       7       /* debug-level messages */

/**CLogger��һ���������־�ӿڣ�����Ӧ�ó��������־
* ����ȫ��ֻ��һ��ʵ����Ĭ��ʵ��Ϊ��stdout�����־��
* Ӧ�ó�����Լ̳�CLogger��ʵ�����ѵ���־��
*/
class CLogger
{
public:
	/** ��ȡCLoggerʵ��
	*@return ��ȡ��CLoggerʵ��
	*/
	static CLogger *GetInstance();

	///������־���
	///@param	indent	���ʱ������
	///@param	level	��־����ֵԽС������Խ��
	///@param	format	�����ʽ������printf�ĸ�ʽҪ��
	///@param	...	����������
	void output(int indent,int level,char *format,...);
	
	///������־���
	///@param	level	��־����ֵԽС������Խ��
	///@param	format	�����ʽ������printf�ĸ�ʽҪ��
	///@param	...	����������
	virtual void output(int level,char *format,...) = 0;
	
	///������־�������־����ΪLL_DEBUG
	///@param	format	�����ʽ������printf�ĸ�ʽҪ��
	///@param	...	����������
	void output(char *format,...);

protected:
	/**��������
	*/
	virtual ~CLogger(){};
protected:
	static CLogger *m_pInstance;		/**<CLoggerʵ��*/
};

#define LOG0(level, sz)					CLogger::GetInstance()->output(level, "%s", sz)
#define LOG1(level, sz, p1)				CLogger::GetInstance()->output(level, sz, p1)
#define LOG2(level, sz, p1, p2)			CLogger::GetInstance()->output(level, sz, p1, p2)
#define LOG3(level, sz, p1, p2, p3)		CLogger::GetInstance()->output(level, sz, p1, p2, p3)

///��־�ķ������������ͨ��ע�͵�����ĺ꣬��ɽ�ֹĳ����־�����

///-------
///���ض���20061210���޸�����־����ķ�ʽ������ʹ�ú������ƣ�����ͨ������������������
///-------
extern bool UseBizStatusLog,UseBizOperationLog,UseBizExceptionLog;
extern bool UseNetStatusLog,UseNetConnectLog,UseNetIOLog,UseNetPackageLog,UseNetCompressLog,UseNetExceptionLog;
extern bool UseProcessLog;

#ifndef DEBUG_NOT_LOG
	#define CHECK_LOG(logFlag,logCommand)	{if (logFlag) logCommand;}
#else
	#define CHECK_LOG(logFlag,logCommand)
#endif

///������־�Ŀ���
	#define BIZ_STATUS_LOG0(sz)				CHECK_LOG(UseBizStatusLog,LOG0(LL_DEBUG, sz))
	#define BIZ_STATUS_LOG1(sz,p1)			CHECK_LOG(UseBizStatusLog,LOG1(LL_DEBUG, sz,p1))
	#define BIZ_STATUS_LOG2(sz,p1,p2)		CHECK_LOG(UseBizStatusLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define BIZ_STATUS_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseBizStatusLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define BIZ_OPERATION_LOG0(sz)			CHECK_LOG(UseBizOperationLog,LOG0(LL_DEBUG, sz))
	#define BIZ_OPERATION_LOG1(sz,p1)		CHECK_LOG(UseBizOperationLog,LOG1(LL_DEBUG, sz,p1))
	#define BIZ_OPERATION_LOG2(sz,p1,p2)	CHECK_LOG(UseBizOperationLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define BIZ_OPERATION_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseBizOperationLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define BIZ_EXCEPTION_LOG0(sz)			CHECK_LOG(UseBizExceptionLog,LOG0(LL_DEBUG, sz))
	#define BIZ_EXCEPTION_LOG1(sz,p1)		CHECK_LOG(UseBizExceptionLog,LOG1(LL_DEBUG, sz,p1))
	#define BIZ_EXCEPTION_LOG2(sz,p1,p2)	CHECK_LOG(UseBizExceptionLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define BIZ_EXCEPTION_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseBizExceptionLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define NET_STATUS_LOG0(sz)				CHECK_LOG(UseNetStatusLog,LOG0(LL_DEBUG, sz))
	#define NET_STATUS_LOG1(sz,p1)			CHECK_LOG(UseNetStatusLog,LOG1(LL_DEBUG, sz,p1))
	#define NET_STATUS_LOG2(sz,p1,p2)		CHECK_LOG(UseNetStatusLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define NET_STATUS_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseNetStatusLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define NET_CONNECT_LOG0(sz)			CHECK_LOG(UseNetConnectLog,LOG0(LL_DEBUG, sz))
	#define NET_CONNECT_LOG1(sz,p1)			CHECK_LOG(UseNetConnectLog,LOG1(LL_DEBUG, sz,p1))
	#define NET_CONNECT_LOG2(sz,p1,p2)		CHECK_LOG(UseNetConnectLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define NET_CONNECT_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseNetConnectLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define NET_IO_LOG0(sz)					CHECK_LOG(UseNetIOLog,LOG0(LL_DEBUG, sz))
	#define NET_IO_LOG1(sz,p1)				CHECK_LOG(UseNetIOLog,LOG1(LL_DEBUG, sz,p1))
	#define NET_IO_LOG2(sz,p1,p2)			CHECK_LOG(UseNetIOLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define NET_IO_LOG3(sz,p1,p2,p3)		CHECK_LOG(UseNetIOLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define NET_PACKAGE_LOG0(sz)			CHECK_LOG(UseNetPackageLog,LOG0(LL_DEBUG, sz))
	#define NET_PACKAGE_LOG1(sz,p1)			CHECK_LOG(UseNetPackageLog,LOG1(LL_DEBUG, sz,p1))
	#define NET_PACKAGE_LOG2(sz,p1,p2)		CHECK_LOG(UseNetPackageLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define NET_PACKAGE_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseNetPackageLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define NET_COMPRESS_LOG0(sz)			CHECK_LOG(UseNetCompressLog,LOG0(LL_DEBUG, sz))
	#define NET_COMPRESS_LOG1(sz,p1)		CHECK_LOG(UseNetCompressLog,LOG1(LL_DEBUG, sz,p1))
	#define NET_COMPRESS_LOG2(sz,p1,p2)		CHECK_LOG(UseNetCompressLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define NET_COMPRESS_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseNetCompressLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define NET_EXCEPTION_LOG0(sz)			CHECK_LOG(UseNetExceptionLog,LOG0(LL_DEBUG, sz))
	#define NET_EXCEPTION_LOG1(sz,p1)		CHECK_LOG(UseNetExceptionLog,LOG1(LL_DEBUG, sz,p1))
	#define NET_EXCEPTION_LOG2(sz,p1,p2)	CHECK_LOG(UseNetExceptionLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define NET_EXCEPTION_LOG3(sz,p1,p2,p3)	CHECK_LOG(UseNetExceptionLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

	#define PROCESS_LOG0(sz)				CHECK_LOG(UseProcessLog,LOG0(LL_DEBUG, sz))
	#define PROCESS_LOG1(sz,p1)				CHECK_LOG(UseProcessLog,LOG1(LL_DEBUG, sz,p1))
	#define PROCESS_LOG2(sz,p1,p2)			CHECK_LOG(UseProcessLog,LOG2(LL_DEBUG, sz,p1,p2))
	#define PROCESS_LOG3(sz,p1,p2,p3)		CHECK_LOG(UseProcessLog,LOG3(LL_DEBUG, sz,p1,p2,p3))

#endif
