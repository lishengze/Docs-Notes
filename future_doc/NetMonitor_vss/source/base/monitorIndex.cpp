/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file monitorIndex.cpp
///@brief	ʵ�������йص�����ָ��
///@history 
///20060716	���ض�		�������ļ�
///20070828	�Ժ��		(1)�����ļ���probelogger����base
///						(2)CMonitorIndex::initʹ��CConfig�ӿڸ�Ϊ�����
///						   CParameterMap,����ʵ���������CProbeLogger,��
///						   ���ɲ�������
///20110526	����		NT-0133-�����߳�д��־����д�����־
// 20110622 ����		NT-0138 ����ϵͳ�������ܣ�����CQWordMonitorIndex���CQWordTotalMonitorIndex��
/////////////////////////////////////////////////////////////////////////

#include "monitorIndex.h"
#include "mpath.h"

time_t CMonitorIndex::m_minNextTime=0;
vector<CMonitorIndex *>	*CMonitorIndex::m_indexList;
map<int, CProbeLogger*>* CMonitorIndex::m_probeLoggerMap = NULL;
int CMonitorIndex::m_handleCountWait=1;
int CMonitorIndex::m_handleCountCheckFrequncy=1;
CRITICAL_VAR CMonitorIndex::m_criticalVar;
bool CMonitorIndex::m_inited=0;
int CMonitorIndex::m_logLevel=0;

void CMonitorIndex::setProbeLogger(CProbeLogger *pProbeLogger, int logId)
{
	if (m_probeLoggerMap == NULL)
		return;

	map<int, CProbeLogger*>::iterator it = m_probeLoggerMap->find(logId);

	if (it != m_probeLoggerMap->end())
	{
		if (it->second != NULL)
			delete it->second;

		it->second = pProbeLogger;
	}
	else
	{
		m_probeLoggerMap->insert(pair<int, CProbeLogger*>(logId, pProbeLogger));
	}
}

CProbeLogger* CMonitorIndex::getProbeLogger(int logId)
{
	if (m_probeLoggerMap == NULL)
		return NULL;

	map<int, CProbeLogger*>::iterator it = m_probeLoggerMap->find(logId);

	if (it != m_probeLoggerMap->end())
		return it->second;
	else
		return NULL;
}

///------
//	���ض���20070114���޸��˳�ʼ���Ĺ��̣��������û������Syslog������£�һЩ�������ܲ���ʹ�õ�����
///======

void CMonitorIndex::init(CProbeLogger *pProbeLogger, CParameterMap *pConfig)
{
///------
///	���ض���20070727�������˰�����־����ķ�ʽ��������־����Ĺ���
///------
	char *logLevelString;
	logLevelString=pConfig->getConfig("LogLevel");
	if (*logLevelString)
	{
		int logLevel;
		if (!strcmp(logLevelString,"debug"))
		{
			logLevel=LOG_DEBUG;
		}
		else if (!strcmp(logLevelString,"info"))
		{
			logLevel=LOG_INFO;
		}
		else if (!strcmp(logLevelString,"critical"))
		{
			logLevel=LOG_CRITICAL;
		}
		else if (!strcmp(logLevelString,"none"))
		{
			logLevel=LOG_NONE;
		}
		else if (isdigit(*logLevelString))
		{
			logLevel=atoi(logLevelString);
		}
		else
		{
			logLevel=LOG_DEBUG;
		}
		if (logLevel>LOG_DEBUG)
		{
			logLevel=LOG_DEBUG;
		}
		else if (logLevel<LOG_NONE)
		{
			logLevel=LOG_NONE;
		}
		UseBizStatusLog=false;
		UseBizOperationLog=false;
		UseBizExceptionLog=false;
		UseNetStatusLog=false;
		UseNetConnectLog=false;
		UseNetIOLog=false;
		UseNetPackageLog=false;
		UseNetCompressLog=false;
		UseNetExceptionLog=false;
		UseProcessLog=false;
			
		if (logLevel>=LOG_DEBUG)
		{
			UseNetPackageLog=true;
			UseNetCompressLog=true;
		}
		
		if (logLevel>=LOG_INFO)
		{
			UseBizStatusLog=true;
			UseBizOperationLog=true;
			UseNetStatusLog=true;
			UseNetConnectLog=true;
			UseNetIOLog=true;
			UseProcessLog=true;
		}
		
		if (logLevel>=LOG_CRITICAL)
		{
			UseBizExceptionLog=true;
			UseNetExceptionLog=true;
		}
		
		m_logLevel=logLevel;
	}
	else
	{
		m_logLevel=LOG_DEBUG;
	}

#define GET_CONFIG(name)								\
	{													\
		if (!strcmp(pConfig->getConfig(#name),"yes"))	\
		{												\
			name=true;									\
		}												\
		if (!strcmp(pConfig->getConfig(#name),"no"))	\
		{												\
			name=false;									\
		}												\
	}

	GET_CONFIG(UseBizStatusLog);
	GET_CONFIG(UseBizOperationLog);
	GET_CONFIG(UseBizExceptionLog);
	GET_CONFIG(UseNetStatusLog);
	GET_CONFIG(UseNetConnectLog);
	GET_CONFIG(UseNetIOLog);
	GET_CONFIG(UseNetPackageLog);
	GET_CONFIG(UseNetCompressLog);
	GET_CONFIG(UseNetExceptionLog);
	GET_CONFIG(UseProcessLog);
	
	if (pProbeLogger==NULL)
	{
		return;
	}

	setProbeLogger(pProbeLogger);
	CBoolMonitorIndex *pIsActiveIndex=new CBoolMonitorIndex("IsActive",20);
	pIsActiveIndex->setValue(true);
}

void CMonitorIndex::add(CProbeLogger *pProbeLogger, int logId)
{
	if (pProbeLogger == NULL)
		return;

	setProbeLogger(pProbeLogger, logId);
}

void CMonitorIndex::handleOne(void)
{
	vector<CMonitorIndex *>::iterator it;
	
	// �Ȱ������¼���������
	for (it = m_indexList->begin(); it < m_indexList->end(); it ++)
	{
		if ((*it)->m_frequncy == 0)
		{
			// �¼�
			(*it)->report(getProbeLogger((*it)->m_logId));
		}
	}

	m_handleCountWait--;
	if (m_handleCountWait>0)
	{
		///������û�е�����
		return;
	}
	///�Ѿ����˼����ˣ��������������´μ����Ҫ�ȴ��Ĵ���
	m_handleCountWait=m_handleCountCheckFrequncy;

	if (m_probeLoggerMap==NULL)
	{
		///��û������̽�룬�ǾͲ�����
		return;
	}

	///Ȼ����ݵ�ǰ���¼����ж��Ƿ���Ҫ����
	time_t now;
	time(&now);
	if (now<m_minNextTime)
	{
		///��С���´�ʱ�䶼û�е����ǾͲ��ø���
		return;
	}

	for (it=m_indexList->begin();it<m_indexList->end();it++)
	{
		if ((*it)->m_frequncy > 0)
		{
			// ָ��
			if ((*it)->m_nextTime<=now)
			{
				///��ָ���ʱ�䵽�ˣ��ǾͶ�����б���
				(*it)->report(getProbeLogger((*it)->m_logId));
				///�����´�ʱ��
				if ((*it)->m_frequncy<=60)
				{
					(*it)->m_nextTime=(now/((*it)->m_frequncy)+1)*((*it)->m_frequncy);
				}
				else
				{
					(*it)->m_nextTime=now+(*it)->m_frequncy;
				}
			}
			if (it==m_indexList->begin())
			{
				m_minNextTime=(*it)->m_nextTime;
			}
			else
			{
				if ((*it)->m_nextTime<m_minNextTime)
				{
					m_minNextTime=(*it)->m_nextTime;
				}
			}
		}
	}
}

void CMonitorIndex::setHandleCountCheckFrequncy(int newFrequncy)
{
	m_handleCountCheckFrequncy=newFrequncy;
}

void CMonitorIndex::reportAll(void)
{
	if (m_probeLoggerMap==NULL)
	{
		///��û������̽�룬�ǾͲ�����
		return;
	}
	
	vector<CMonitorIndex *>::iterator it;
	for (it=m_indexList->begin();it<m_indexList->end();it++)
	{
		(*it)->report(getProbeLogger((*it)->m_logId));
	}
}

void CIntMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,m_value);
}

void CQWordMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,m_value);
}

void CIntUsageMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,m_value);
	pProbeLogger->SendPercentageProbeMessage(m_usageName,((double)m_value)/m_totalValue);
}

void CIntPtrMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,*m_ptr);
}

void CBoolMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,(int)m_value);
}

void CStringMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,(const char*) m_value);
}

void CIntTotalMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,m_value);
	m_totalValue+=m_value;
	pProbeLogger->SendProbeMessage(m_totalName,m_totalValue);
	m_value=0;
}

void CQWordTotalMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,m_value);
	m_totalValue+=m_value;
	pProbeLogger->SendProbeMessage(m_totalName,m_totalValue);
	m_value=0;
}

void CStringBufferMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,(const char*) m_value);
}

void CStringBufferArrayMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	for (int i=0;i<m_size;i++)
	{
		if (m_value[i][0]!='\0')
		{
			char nameBuffer[MAX_PARAMETER_NAME];
			sprintf(nameBuffer,"%s.%d",m_name,i+1);
			pProbeLogger->SendProbeMessage(nameBuffer,(const char*) m_value[i]);
		}
	}
}

void CFloatMonitorIndex::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	pProbeLogger->SendProbeMessage(m_name,m_value);
}

void CEventMonitor::report(const char *detail)
{
	char buffer[4096];
	sprintf(buffer,"%s %s %s %s",m_type,m_ipAdr,m_user,detail);

	ENTER_CRITICAL(m_lock);
	m_waitingEvents->push_back(buffer);
	LEAVE_CRITICAL(m_lock);
}

void CEventMonitor::report(const char *type, const char *detail)
{
	char buffer[4096];
	sprintf(buffer,"%s %s %s %s",type,m_ipAdr,m_user,detail);

	ENTER_CRITICAL(m_lock);
	m_waitingEvents->push_back(buffer);
	LEAVE_CRITICAL(m_lock);
}

void CEventMonitor::report(const char *type, const char *ipAdr, const char *user, const char *detail)
{
	char buffer[4096];
	sprintf(buffer,"%s %s %s %s",type,ipAdr,user,detail);

	ENTER_CRITICAL(m_lock);
	m_waitingEvents->push_back(buffer);
	LEAVE_CRITICAL(m_lock);
}

void CEventMonitor::report(CProbeLogger *pProbeLogger)
{
	if (pProbeLogger == NULL)
		return;

	ENTER_CRITICAL(m_lock);
	vector<string>* temp = m_waitingEvents;
	m_waitingEvents = m_events;
	m_events = temp;
	LEAVE_CRITICAL(m_lock);

	if (m_events->size() == 0)
		return;

	for (int i = 0; i < m_events->size(); i ++)
		pProbeLogger->SendProbeMessage("event", m_events->at(i).c_str());

	m_events->clear();
}

void CEventMonitor::report(int level, const char *type, const char *format, ...)
{
	if (level>m_logLevel)
	{
		return;
	}
	char buffer[4096];
	sprintf(buffer,"%s %d ",type,level);
	va_list v;
	va_start(v,format);
	vsprintf(buffer+strlen(buffer),format,v);
	va_end(v);
	
	ENTER_CRITICAL(m_lock);
	m_waitingEvents->push_back(buffer);
	LEAVE_CRITICAL(m_lock);
}

CEventMonitor stdEventMonitor;
