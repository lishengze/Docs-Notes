/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CSyslogService.h
///@brief	����ʹ��syslogʵ��̽��ӿ�
///@history 
///20060716	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////
#ifndef CSYSLOGSERVICE_H
#define CSYSLOGSERVICE_H

#ifdef UNIX
#include <syslog.h>

#include "CProbeLogger.h"

class CSyslogService : public CProbeLogger
{
private:
	char m_ident[100];
public:
	///���췽��
	///@param	programName	ָ���ĳ�����
	///@param	globalSeq	����ȫ�����к�
	CSyslogService(const char *programName, const int globalSeq): CProbeLogger(programName,globalSeq)
	{
		sprintf( m_ident, "%s %d", programName, globalSeq );
		openlog( m_ident, LOG_PID, LOG_USER );
	}
	
	///��������
	virtual ~CSyslogService(void)
	{
		closelog();
	}

	/**
	 * ����ʵ����η�����Ϣ
	 * @param programName ������
	 * @param globalSeq ����ȫ�����к�
	 * @param parameter �������ָ��
	 * @param value ����ֵ
	 */
	virtual void SendProbeMessageImpl
	(
		const char *programName,
		const int globalSeq,
		const char *parameter,
		const char *value
	);
};

#endif

#endif
