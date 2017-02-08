/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file monitorIndex.h
///@brief	���������йص�����ָ��
///@history 
///20060716	���ض�		�������ļ�
///20070828	�Ժ��		(1)�����ļ���probelogger����base
///						(2)CMonitorIndex::initʹ��CConfig�ӿڸ�Ϊ�����
///						   CParameterMap,����ʵ���������CProbeLogger,��
///						   ���ɲ�������
///						(3)�����˺�EMERGENCY_EXIT
///20110526	����		NT-0133-�����߳�д��־����д�����־
// 20110622 ����		NT-0138 ����ϵͳ�������ܣ�����CQWordMonitorIndex���CQWordTotalMonitorIndex��
/////////////////////////////////////////////////////////////////////////

#ifndef MONITORINDEX_H
#define MONITORINDEX_H

#include "platform.h"
#include "CProbeLogger.h"
#include "ParameterMap.h"
#include "CLogger.h"

/////////////////////////////////////////////////////////////////////////
///IMonitorIndex�ǳ���ļ��ָ��Ľӿ�
///@author	���ض�
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class IMonitorIndex
{
public:
	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorIndex�Ǽ��ָ��Ļ����࣬���еľ������ͱ���̳д���
///@author	���ض�
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CMonitorIndex: public IMonitorIndex
{
public:
	///���췽��
	///@param	frequncy	��ָ���ˢ��Ƶ��,С�ڵ���0��ʾ����Ҫͳһ����
	CMonitorIndex(int frequncy, int logId = 0)
	{
		if (!m_inited)
		{
			INIT_CRITICAL_VAR(m_criticalVar);
			m_probeLoggerMap = new map<int, CProbeLogger*>();
			m_indexList=new vector<CMonitorIndex *>;
			m_inited=true;
		}

		m_logId = logId;
		m_frequncy = frequncy;

		ENTER_CRITICAL(m_criticalVar);
		m_indexList->push_back(this);
		m_nextTime=0;
		LEAVE_CRITICAL(m_criticalVar);
	}
	
	///��������
	virtual ~CMonitorIndex(void)
	{
		ENTER_CRITICAL(m_criticalVar);
		vector<CMonitorIndex *>::iterator it;
		for (it=m_indexList->begin();it<m_indexList->end();it++)
		{
			if (*it==this)
			{
				m_indexList->erase(it);
				break;
			}
		}
		LEAVE_CRITICAL(m_criticalVar);
	}
	
	///����̽��
	///@param	pProbeLogger	�µ�̽��
	///@param	logId	        ��־id
	static void setProbeLogger(CProbeLogger *pProbeLogger, int logId = 0);

	///�õ�̽��
	static CProbeLogger* getProbeLogger(int logId);

	///��ʼ�����Զ�ʹ��CSyslogService��Ӧ����main������ʹ��
	///@param	argc	main�����Ĳ���
	///@param	argv	main�����Ĳ���
	///@param	fileName	�ļ�����
	///@param	pConfig	ϵͳ����
	//******//
	//	���ض���20060929�����ļ����ƴӲ����д���
	//******//
	///-------
	///���ض���20061210��ͨ�����ù������еı�׼�������
	///-------
	static void init(CProbeLogger *pProbeLogger, CParameterMap *pConfig);

	///���Ӽ����־����logId������ڵ���1��ͨ��init���ɵ���־logIdĬ��Ϊ0
	static void add(CProbeLogger *pProbeLogger, int logId);

	///���һ�����鴦���������ʵ��ؼ�飬���ڱ�Ҫ������£����Ա���
	static void handleOne(void);

	///�����µ����鴦����Ƶ��
	///@param	newFrequncy	�µ�ˢ��Ƶ��
	static void setHandleCountCheckFrequncy(int newFrequncy);
	
	///�������е�ָ��
	static void reportAll(void);
protected:
	///��ָ���logId
	int m_logId;

	///��ָ���ˢ��Ƶ��
	int m_frequncy;

	///��������´�ˢ���¼�
	time_t m_nextTime;

	///���µ���һ�ε�ʱ��
	static time_t m_minNextTime;
	
	///��¼����ָ���嵥
	static vector<CMonitorIndex *>	*m_indexList;
	
	///ʹ�õ�̽��
	static map<int, CProbeLogger*>* m_probeLoggerMap;

	///��Ҫ�ȶ��ٴ�����Ĵ����ٽ��м��
	static int m_handleCountWait;

	///��������Ĵ���ÿ��������ʱ������һ�μ��
	static int m_handleCountCheckFrequncy;

	///�ٽ�������
	static CRITICAL_VAR m_criticalVar;

	///�Ƿ����б����Ѿ���ɳ�ʼ��
	static bool m_inited;
	
	///Ŀǰ����־���𣬷�Χ��0��3������Խ����־Խ��
	static int m_logLevel;
};

/////////////////////////////////////////////////////////////////////////
///CIntMonitorIndex�Ǽ��һ������ָ�����
///@author	���ض�
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CIntMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CIntMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
	}
	
	///��������
	~CIntMonitorIndex(void)
	{
	}
	
	///����ֵ
	///@param	value	�µ�ֵ
	void incValue(int value=1)
	{
		m_value+=value;
	}

	///����ֵ
	///@param	value	�µ�ֵ
	void setValue(int value)
	{
		m_value=value;
	}
	
	///��ȡֵ
	///@return	�õ��ĵ�ǰֵ
	int getValue(void)
	{
		return m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile int m_value;
};

/////////////////////////////////////////////////////////////////////////
///CQWordMonitorIndex�Ǽ��һ������ָ�����
///@author	����
///@version	1.0,20110623
/////////////////////////////////////////////////////////////////////////
class CQWordMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CQWordMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
	}
	
	///��������
	~CQWordMonitorIndex(void)
	{
	}
	
	///����ֵ
	///@param	value	�µ�ֵ
	void incValue(QWORD value=1)
	{
		m_value+=value;
	}

	///����ֵ
	///@param	value	�µ�ֵ
	void setValue(QWORD value)
	{
		m_value=value;
	}
	
	///��ȡֵ
	///@return	�õ��ĵ�ǰֵ
	QWORD getValue(void)
	{
		return m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile QWORD m_value;
};

/////////////////////////////////////////////////////////////////////////
///CIntUsageMonitorIndex�Ǽ��һ������Ϊ��������Ҫ����ʹ���ʵ�ָ����
///@author	���ض�
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CIntUsageMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	totalValue	��ָ�������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CIntUsageMonitorIndex(const char *name,int totalValue, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
		m_totalValue=totalValue;
		sprintf(m_usageName,"%sUsage",m_name);
	}
	
	///��������
	~CIntUsageMonitorIndex(void)
	{
	}
	
	///����ֵ
	///@param	value	�µ�ֵ
	void incValue(int value=1)
	{
		m_value+=value;
	}

	///����ֵ
	///@param	value	�µ�ֵ
	void setValue(int value)
	{
		m_value=value;
	}
	
	///��ȡֵ
	///@return	�õ��ĵ�ǰֵ
	int getValue(void)
	{
		return m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	char m_usageName[MAX_PARAMETER_NAME];
	volatile int m_value;
	volatile int m_totalValue;
};


/////////////////////////////////////////////////////////////////////////
///CIntPtrMonitorIndex�Ǽ��һ������ָ����ࣨʹ��ָ�룩
///@author	���ض�
///@version	1.0,20060719
/////////////////////////////////////////////////////////////////////////
class CIntPtrMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	ptr	ָ��������ָ��
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CIntPtrMonitorIndex(const char *name, const int *ptr,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_ptr=ptr;
	}
	
	///��������
	~CIntPtrMonitorIndex(void)
	{
	}
	
	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile const int *m_ptr;
};

/////////////////////////////////////////////////////////////////////////
///CBoolMonitorIndex�Ǽ��һ������ֵָ�����
///@author	���ض�
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CBoolMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CBoolMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
	}
	
	///��������
	~CBoolMonitorIndex(void)
	{
	}
	
	///����ֵ
	///@param	value	�µ�ֵ
	void setValue(bool value)
	{
		m_value=value;
	}
	
	///��ȡֵ
	///@return	�õ��ĵ�ǰֵ
	bool getValue(void)
	{
		return m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile bool m_value;
};

/////////////////////////////////////////////////////////////////////////
///CStringMonitorIndex�Ǽ��һ���ַ���ֵָ�����
///@author	���ض�
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CStringMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	value	ָ�����ַ���
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CStringMonitorIndex(const char *name,const char *value, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=value;
	}
	
	///��������
	~CStringMonitorIndex(void)
	{
	}
	
	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile const char *m_value;
};

/////////////////////////////////////////////////////////////////////////
///CIntTotalMonitorIndex�Ǽ��һ������������ָ����
///@author	���ض�
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CIntTotalMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CIntTotalMonitorIndex(const char *name, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
		m_totalValue=0;
		sprintf(m_totalName,"%sTotal",m_name);
	}
	
	///��������
	~CIntTotalMonitorIndex(void)
	{
	}
	
	///����ֵ
	///@param	value	�µ�ֵ
	void incValue(int value=1)
	{
		m_value+=value;
	}
	
	///��ȡֵ
	///@return	�õ��ĵ�ǰֵ
	int getValue(void)
	{
		return m_value;
	}

	///��ȡ�ۼ�ֵ
	///@return	��ǰ���ۼ�ֵ
	int getTotalValue(void)
	{
		return m_totalValue+m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	char m_totalName[MAX_PARAMETER_NAME];
	volatile int m_value;
	volatile int m_totalValue;
};

/////////////////////////////////////////////////////////////////////////
///CQWordTotalMonitorIndex�Ǽ��һ������������ָ����
///@author	����
///@version	1.0,20110623
/////////////////////////////////////////////////////////////////////////
class CQWordTotalMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CQWordTotalMonitorIndex(const char *name, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
		m_totalValue=0;
		sprintf(m_totalName,"%sTotal",m_name);
	}
	
	///��������
	~CQWordTotalMonitorIndex(void)
	{
	}
	
	///����ֵ
	///@param	value	�µ�ֵ
	void incValue(QWORD value=1)
	{
		m_value+=value;
	}
	
	///��ȡֵ
	///@return	�õ��ĵ�ǰֵ
	QWORD getValue(void)
	{
		return m_value;
	}

	///��ȡ�ۼ�ֵ
	///@return	��ǰ���ۼ�ֵ
	QWORD getTotalValue(void)
	{
		return m_totalValue+m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	char m_totalName[MAX_PARAMETER_NAME];
	volatile QWORD m_value;
	volatile QWORD m_totalValue;
};

/////////////////////////////////////////////////////////////////////////
///CStringBufferMonitorIndex�Ǽ��һ���ַ���ֵָ�����
///@author	���ض�
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CStringBufferMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CStringBufferMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value[0]='\0';
	}
	
	///���캯��
	///@param	name	��������
	///@param	value	����ֵ
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CStringBufferMonitorIndex(const char *name,const char *value, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		setValue(value);
	}

	///��������
	~CStringBufferMonitorIndex(void)
	{
	}

	///����ֵ
	///@param	value	����ֵ
	void setValue(const char *value)
	{
		strcpy((char*) m_value,value);
	}

	///��ȡֵ
	///@return	��ǰ��ֵ
	const char *getValue(void)
	{
		return (char*) m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile char m_value[1024];
};

/////////////////////////////////////////////////////////////////////////
///CStringBufferArrayMonitorIndex�Ǽ��һ���ַ���ֵָ���������
///@author	���ض�
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CStringBufferArrayMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	size	�����С
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CStringBufferArrayMonitorIndex(const char *name,int size, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_size=size;
		m_value=new volatile char*[size];
		for (int i=0;i<size;i++)
		{
			m_value[i]=new char[1024];
			m_value[i][0]='\0';
		}
	}
	
	///��������
	~CStringBufferArrayMonitorIndex(void)
	{
	}

	///����ֵ
	///@param	id	�±�
	///@param	value	����ֵ
	void setValue(int id, const char *value)
	{
		if ((id<1)||(id>m_size))
		{
			return;
		}
		strcpy((char*) m_value[id-1],value);
	}

	///��ȡֵ
	///@param	id	�±�
	///@return	��ǰ��ֵ
	const char *getValue(int id)
	{
		if ((id<1)||(id>m_size))
		{
			return "";
		}
		return (char*) m_value[id-1];
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile char **m_value;
	int m_size;
};

/////////////////////////////////////////////////////////////////////////
///CFloatMonitorIndex�Ǽ��һ��������ָ�����
///@author	���ض�
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CFloatMonitorIndex: public CMonitorIndex
{
public:
	///���캯��
	///@param	name	��������
	///@param	frequncy	��ָ���ˢ��Ƶ��
	CFloatMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0.0;
	}
	
	///��������
	~CFloatMonitorIndex(void)
	{
	}
	
	///����ֵ
	///@param	value	�µ�ֵ
	void incValue(double value)
	{
		m_value+=value;
	}

	///����ֵ
	///@param	value	�µ�ֵ
	void setValue(double value)
	{
		m_value=value;
	}
	
	///��ȡֵ
	///@return	�õ��ĵ�ǰֵ
	double getValue(void)
	{
		return m_value;
	}

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile double m_value;
};

///------
///	���ض���20070812����ǿ��ͨ��EvnentMonitor������־�Ĺ���
///------
#define LOG_NONE		0
#define LOG_EMERGENCY	1
#define LOG_CRITICAL	2
#define LOG_ERROR		3
#define LOG_WARNING		4
#define LOG_INFO		5
#define LOG_DEBUG		6

/////////////////////////////////////////////////////////////////////////
///CEventMonitor�Ǽ��һ���¼�����
///@author	���ض�
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CEventMonitor: public CMonitorIndex
{
public:
	///���캯��
	///@param	type	����
	///@param	ipAdr	IP��ַ
	///@param	user	�û���
	CEventMonitor(const char *type="", const char *ipAdr="", const char *user="", int logId = 0): CMonitorIndex(0, logId)
	{
		m_type=type;
		m_ipAdr=ipAdr;
		m_user=user;
		m_waitingEvents = new vector<string>();
		m_events = new vector<string>();
		INIT_CRITICAL_VAR(m_lock);
	}
	
	///��������
	~CEventMonitor(void)
	{
		delete m_events;
		delete m_waitingEvents;
	}

	///�����¼�
	///@param	detail	Ҫ�������ϸ����
	void report(const char *detail);

	///�����¼�
	///@param	type	����
	///@param	detail	Ҫ�������ϸ����
	void report(const char *type, const char *detail);
	
	///����ĳ�����͵��¼�
	///@param	level	����ļ���
	///@param	type	����
	///@param	format	����ĸ�ʽ
	///@param	...	����Ĳ���
	void report(int level, const char *type, const char *format, ...);

	///�����¼�
	///@param	type	����
	///@param	ipAdr	IP��ַ
	///@param	user	�û���
	///@param	detail	Ҫ�������ϸ����
	void report(const char *type, const char *ipAdr, const char *user, const char *detail);

	///����ָ�����Ա���
	///@param	pProbeLogger	����ʱʹ�õ�̽��
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_type;
	const char *m_ipAdr;
	const char *m_user;
	vector<string>* m_waitingEvents;
	vector<string>* m_events;
	CRITICAL_VAR m_lock;
};

extern CEventMonitor stdEventMonitor;

#define REPORT_EVENT stdEventMonitor.report

///��������޷����ƵĴ���ʱ����¼��־�����쳣�˳� 
///@param msg ��־��Ϣ
#define EMERGENCY_EXIT(msg) {														\
		REPORT_EVENT(LOG_EMERGENCY , "EmergencyExit",							\
				":%s in line %d of file %s\n",msg,__LINE__,__FILE__);			\
		char *__pNull = NULL; *__pNull = 0;										\
	}

#endif
