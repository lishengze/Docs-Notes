/////////////////////////////////////////////////////////////////////////
///@system 交易引擎系统
///@company 上海期货信息技术有限公司
///@file CDumpLog.h
///@brief定义了类CDumpLog
///@history 
///20041001	王肇东		创建该文件
/////////////////////////////////////////////////////////////////////////

#ifndef CDUMPLOG_H
#define CDUMPLOG_H

#include "CMemoryDB.h"

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityDumpTrigger是操作监控实体时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityDumpTrigger: public CMonitorEntityActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CMonitorEntityDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CMonitorEntityDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pMonitorEntity	要加入的MonitorEntity
	virtual void beforeAdd(CWriteableMonitorEntity *pMonitorEntity);
	
	///更新前触发	
	///@param	pMonitorEntity	被刷新的CMonitorEntity
	///@param	pNewMonitorEntity	新的值
	virtual void beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity);
	
	///删除前触发
	///@param	pMonitorEntity	要删除的CMonitorEntity
	virtual void beforeRemove(CMonitorEntity *pMonitorEntity);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityDumpTrigger是操作事件实体时的触发器，在变化时进行输出
///@author	王肇东
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityDumpTrigger: public CEventEntityActionTrigger
{
public:
	///构造方法
	///@param	output	输出用的文件
	///@param	flag	控制输出的具体项，是CREATE_ACTION、DELETE_ACTION和UPDATE_ACTION的或
	CEventEntityDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///析构方法
	virtual ~CEventEntityDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///加入前触发
	///@param	pEventEntity	要加入的EventEntity
	virtual void beforeAdd(CWriteableEventEntity *pEventEntity);
	
	///更新前触发	
	///@param	pEventEntity	被刷新的CEventEntity
	///@param	pNewEventEntity	新的值
	virtual void beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity);
	
	///删除前触发
	///@param	pEventEntity	要删除的CEventEntity
	virtual void beforeRemove(CEventEntity *pEventEntity);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDumpLog是一个将所有的修改以Dump方式输出的交易引擎提醒实现
///@author	王肇东
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CDumpLog
{
public:
	///构造方法，创建一个输出器
	///@param	pDB	要输出的内存数据库
	///@param	pConfig	配置信息
	CDumpLog(CMemoryDB *pDB, CConfig *pConfig);
	
	///析构方法，将负责释放所占用的空间
	virtual ~CDumpLog(void);

	///启动dump
	void start(void);
	
	///停止dump
	void stop(void);
	
	///是否已经启动
	///@return	1表示已经启动，0表示没有启动
	int isStarted(void);
	
	///输出信息
	///@param	format	信息格式，按照fprintf的要求
	///@param	...	信息的详细内容
	void dumpMsg(char *format,...);

private:
	///输出文件
	FILE *m_DumpOutput;
	
	///内存数据库
	CMemoryDB *m_DB;
	
	///是否已经启动
	int m_Started;
	
	CMonitorEntityDumpTrigger *m_MonitorEntityTrigger;
	CEventEntityDumpTrigger *m_EventEntityTrigger;
};

#endif
