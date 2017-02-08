/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file monitorIndex.h
///@brief	定义与监控有关的若干指标
///@history 
///20060716	王肇东		创建该文件
///20070828	赵鸿昊		(1)将该文件从probelogger移至base
///						(2)CMonitorIndex::init使用CConfig接口改为抽象的
///						   CParameterMap,不再实例化具体的CProbeLogger,而
///						   是由参数传入
///						(3)增加了宏EMERGENCY_EXIT
///20110526	江鹏		NT-0133-独立线程写日志并可写多个日志
// 20110622 江鹏		NT-0138 增加系统度量功能：增加CQWordMonitorIndex类和CQWordTotalMonitorIndex类
/////////////////////////////////////////////////////////////////////////

#ifndef MONITORINDEX_H
#define MONITORINDEX_H

#include "platform.h"
#include "CProbeLogger.h"
#include "ParameterMap.h"
#include "CLogger.h"

/////////////////////////////////////////////////////////////////////////
///IMonitorIndex是抽象的监控指标的接口
///@author	王肇东
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class IMonitorIndex
{
public:
	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger)=0;
};

/////////////////////////////////////////////////////////////////////////
///CMonitorIndex是监控指标的基础类，所有的具体类型必须继承此类
///@author	王肇东
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CMonitorIndex: public IMonitorIndex
{
public:
	///构造方法
	///@param	frequncy	本指标的刷新频率,小于等于0表示不需要统一报告
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
	
	///析构方法
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
	
	///设置探针
	///@param	pProbeLogger	新的探针
	///@param	logId	        日志id
	static void setProbeLogger(CProbeLogger *pProbeLogger, int logId = 0);

	///得到探针
	static CProbeLogger* getProbeLogger(int logId);

	///初始化，自动使用CSyslogService，应当在main函数中使用
	///@param	argc	main函数的参数
	///@param	argv	main函数的参数
	///@param	fileName	文件名称
	///@param	pConfig	系统配置
	//******//
	//	王肇东，20060929：将文件名称从参数中传入
	//******//
	///-------
	///王肇东，20061210：通过配置管理所有的标准输出内容
	///-------
	static void init(CProbeLogger *pProbeLogger, CParameterMap *pConfig);

	///增加监控日志，此logId必须大于等于1；通过init生成的日志logId默认为0
	static void add(CProbeLogger *pProbeLogger, int logId);

	///完成一次事情处理，将进行适当地检查，并在必要的情况下，予以报告
	static void handleOne(void);

	///设置新的事情处理检查频率
	///@param	newFrequncy	新的刷新频率
	static void setHandleCountCheckFrequncy(int newFrequncy);
	
	///报告所有的指标
	static void reportAll(void);
protected:
	///本指标的logId
	int m_logId;

	///本指标的刷新频率
	int m_frequncy;

	///各个组的下次刷新事件
	time_t m_nextTime;

	///最下的下一次的时间
	static time_t m_minNextTime;
	
	///记录所有指标清单
	static vector<CMonitorIndex *>	*m_indexList;
	
	///使用的探针
	static map<int, CProbeLogger*>* m_probeLoggerMap;

	///还要等多少次事情的处理，再进行检查
	static int m_handleCountWait;

	///处理事情的次数每当到多少时，进行一次检查
	static int m_handleCountCheckFrequncy;

	///临界区变量
	static CRITICAL_VAR m_criticalVar;

	///是否所有变量已经完成初始化
	static bool m_inited;
	
	///目前的日志级别，范围是0至3，数字越大，日志越多
	static int m_logLevel;
};

/////////////////////////////////////////////////////////////////////////
///CIntMonitorIndex是监控一个整数指标的类
///@author	王肇东
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CIntMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	frequncy	本指标的刷新频率
	CIntMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
	}
	
	///析构函数
	~CIntMonitorIndex(void)
	{
	}
	
	///增加值
	///@param	value	新的值
	void incValue(int value=1)
	{
		m_value+=value;
	}

	///设置值
	///@param	value	新的值
	void setValue(int value)
	{
		m_value=value;
	}
	
	///获取值
	///@return	得到的当前值
	int getValue(void)
	{
		return m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile int m_value;
};

/////////////////////////////////////////////////////////////////////////
///CQWordMonitorIndex是监控一个整数指标的类
///@author	江鹏
///@version	1.0,20110623
/////////////////////////////////////////////////////////////////////////
class CQWordMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	frequncy	本指标的刷新频率
	CQWordMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
	}
	
	///析构函数
	~CQWordMonitorIndex(void)
	{
	}
	
	///增加值
	///@param	value	新的值
	void incValue(QWORD value=1)
	{
		m_value+=value;
	}

	///设置值
	///@param	value	新的值
	void setValue(QWORD value)
	{
		m_value=value;
	}
	
	///获取值
	///@return	得到的当前值
	QWORD getValue(void)
	{
		return m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile QWORD m_value;
};

/////////////////////////////////////////////////////////////////////////
///CIntUsageMonitorIndex是监控一个整数为基础的需要计算使用率的指标类
///@author	王肇东
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CIntUsageMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	totalValue	本指标的总量
	///@param	frequncy	本指标的刷新频率
	CIntUsageMonitorIndex(const char *name,int totalValue, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
		m_totalValue=totalValue;
		sprintf(m_usageName,"%sUsage",m_name);
	}
	
	///析构函数
	~CIntUsageMonitorIndex(void)
	{
	}
	
	///增加值
	///@param	value	新的值
	void incValue(int value=1)
	{
		m_value+=value;
	}

	///设置值
	///@param	value	新的值
	void setValue(int value)
	{
		m_value=value;
	}
	
	///获取值
	///@return	得到的当前值
	int getValue(void)
	{
		return m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	char m_usageName[MAX_PARAMETER_NAME];
	volatile int m_value;
	volatile int m_totalValue;
};


/////////////////////////////////////////////////////////////////////////
///CIntPtrMonitorIndex是监控一个整数指标的类（使用指针）
///@author	王肇东
///@version	1.0,20060719
/////////////////////////////////////////////////////////////////////////
class CIntPtrMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	ptr	指向整数的指针
	///@param	frequncy	本指标的刷新频率
	CIntPtrMonitorIndex(const char *name, const int *ptr,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_ptr=ptr;
	}
	
	///析构函数
	~CIntPtrMonitorIndex(void)
	{
	}
	
	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile const int *m_ptr;
};

/////////////////////////////////////////////////////////////////////////
///CBoolMonitorIndex是监控一个布尔值指标的类
///@author	王肇东
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CBoolMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	frequncy	本指标的刷新频率
	CBoolMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
	}
	
	///析构函数
	~CBoolMonitorIndex(void)
	{
	}
	
	///设置值
	///@param	value	新的值
	void setValue(bool value)
	{
		m_value=value;
	}
	
	///获取值
	///@return	得到的当前值
	bool getValue(void)
	{
		return m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile bool m_value;
};

/////////////////////////////////////////////////////////////////////////
///CStringMonitorIndex是监控一个字符串值指标的类
///@author	王肇东
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CStringMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	value	指定的字符串
	///@param	frequncy	本指标的刷新频率
	CStringMonitorIndex(const char *name,const char *value, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=value;
	}
	
	///析构函数
	~CStringMonitorIndex(void)
	{
	}
	
	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile const char *m_value;
};

/////////////////////////////////////////////////////////////////////////
///CIntTotalMonitorIndex是监控一个整数总量的指标类
///@author	王肇东
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CIntTotalMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	frequncy	本指标的刷新频率
	CIntTotalMonitorIndex(const char *name, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
		m_totalValue=0;
		sprintf(m_totalName,"%sTotal",m_name);
	}
	
	///析构函数
	~CIntTotalMonitorIndex(void)
	{
	}
	
	///增加值
	///@param	value	新的值
	void incValue(int value=1)
	{
		m_value+=value;
	}
	
	///获取值
	///@return	得到的当前值
	int getValue(void)
	{
		return m_value;
	}

	///获取累计值
	///@return	当前的累计值
	int getTotalValue(void)
	{
		return m_totalValue+m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	char m_totalName[MAX_PARAMETER_NAME];
	volatile int m_value;
	volatile int m_totalValue;
};

/////////////////////////////////////////////////////////////////////////
///CQWordTotalMonitorIndex是监控一个整数总量的指标类
///@author	江鹏
///@version	1.0,20110623
/////////////////////////////////////////////////////////////////////////
class CQWordTotalMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	frequncy	本指标的刷新频率
	CQWordTotalMonitorIndex(const char *name, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0;
		m_totalValue=0;
		sprintf(m_totalName,"%sTotal",m_name);
	}
	
	///析构函数
	~CQWordTotalMonitorIndex(void)
	{
	}
	
	///增加值
	///@param	value	新的值
	void incValue(QWORD value=1)
	{
		m_value+=value;
	}
	
	///获取值
	///@return	得到的当前值
	QWORD getValue(void)
	{
		return m_value;
	}

	///获取累计值
	///@return	当前的累计值
	QWORD getTotalValue(void)
	{
		return m_totalValue+m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	char m_totalName[MAX_PARAMETER_NAME];
	volatile QWORD m_value;
	volatile QWORD m_totalValue;
};

/////////////////////////////////////////////////////////////////////////
///CStringBufferMonitorIndex是监控一个字符串值指标的类
///@author	王肇东
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CStringBufferMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	frequncy	本指标的刷新频率
	CStringBufferMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value[0]='\0';
	}
	
	///构造函数
	///@param	name	参数名称
	///@param	value	参数值
	///@param	frequncy	本指标的刷新频率
	CStringBufferMonitorIndex(const char *name,const char *value, int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		setValue(value);
	}

	///析构函数
	~CStringBufferMonitorIndex(void)
	{
	}

	///设置值
	///@param	value	参数值
	void setValue(const char *value)
	{
		strcpy((char*) m_value,value);
	}

	///获取值
	///@return	当前的值
	const char *getValue(void)
	{
		return (char*) m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile char m_value[1024];
};

/////////////////////////////////////////////////////////////////////////
///CStringBufferArrayMonitorIndex是监控一个字符串值指标数组的类
///@author	王肇东
///@version	1.0,20060720
/////////////////////////////////////////////////////////////////////////
class CStringBufferArrayMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	size	数组大小
	///@param	frequncy	本指标的刷新频率
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
	
	///析构函数
	~CStringBufferArrayMonitorIndex(void)
	{
	}

	///设置值
	///@param	id	下标
	///@param	value	参数值
	void setValue(int id, const char *value)
	{
		if ((id<1)||(id>m_size))
		{
			return;
		}
		strcpy((char*) m_value[id-1],value);
	}

	///获取值
	///@param	id	下标
	///@return	当前的值
	const char *getValue(int id)
	{
		if ((id<1)||(id>m_size))
		{
			return "";
		}
		return (char*) m_value[id-1];
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile char **m_value;
	int m_size;
};

/////////////////////////////////////////////////////////////////////////
///CFloatMonitorIndex是监控一个浮点数指标的类
///@author	王肇东
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CFloatMonitorIndex: public CMonitorIndex
{
public:
	///构造函数
	///@param	name	参数名称
	///@param	frequncy	本指标的刷新频率
	CFloatMonitorIndex(const char *name,int frequncy, int logId = 0): CMonitorIndex(frequncy, logId)
	{
		m_name=name;
		m_value=0.0;
	}
	
	///析构函数
	~CFloatMonitorIndex(void)
	{
	}
	
	///增加值
	///@param	value	新的值
	void incValue(double value)
	{
		m_value+=value;
	}

	///设置值
	///@param	value	新的值
	void setValue(double value)
	{
		m_value=value;
	}
	
	///获取值
	///@return	得到的当前值
	double getValue(void)
	{
		return m_value;
	}

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
	virtual void report(CProbeLogger *pProbeLogger);
private:
	const char *m_name;
	volatile double m_value;
};

///------
///	王肇东，20070812：增强了通过EvnentMonitor进行日志的功能
///------
#define LOG_NONE		0
#define LOG_EMERGENCY	1
#define LOG_CRITICAL	2
#define LOG_ERROR		3
#define LOG_WARNING		4
#define LOG_INFO		5
#define LOG_DEBUG		6

/////////////////////////////////////////////////////////////////////////
///CEventMonitor是监控一个事件的类
///@author	王肇东
///@version	1.0,20060716
/////////////////////////////////////////////////////////////////////////
class CEventMonitor: public CMonitorIndex
{
public:
	///构造函数
	///@param	type	类型
	///@param	ipAdr	IP地址
	///@param	user	用户名
	CEventMonitor(const char *type="", const char *ipAdr="", const char *user="", int logId = 0): CMonitorIndex(0, logId)
	{
		m_type=type;
		m_ipAdr=ipAdr;
		m_user=user;
		m_waitingEvents = new vector<string>();
		m_events = new vector<string>();
		INIT_CRITICAL_VAR(m_lock);
	}
	
	///析构函数
	~CEventMonitor(void)
	{
		delete m_events;
		delete m_waitingEvents;
	}

	///报告事件
	///@param	detail	要报告的详细内容
	void report(const char *detail);

	///报告事件
	///@param	type	类型
	///@param	detail	要报告的详细内容
	void report(const char *type, const char *detail);
	
	///报告某个类型的事件
	///@param	level	报告的级别
	///@param	type	类型
	///@param	format	输出的格式
	///@param	...	输出的参数
	void report(int level, const char *type, const char *format, ...);

	///报告事件
	///@param	type	类型
	///@param	ipAdr	IP地址
	///@param	user	用户名
	///@param	detail	要报告的详细内容
	void report(const char *type, const char *ipAdr, const char *user, const char *detail);

	///将此指标予以报告
	///@param	pProbeLogger	报告时使用的探针
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

///程序出现无法控制的错误时，记录日志，并异常退出 
///@param msg 日志信息
#define EMERGENCY_EXIT(msg) {														\
		REPORT_EVENT(LOG_EMERGENCY , "EmergencyExit",							\
				":%s in line %d of file %s\n",msg,__LINE__,__FILE__);			\
		char *__pNull = NULL; *__pNull = 0;										\
	}

#endif
