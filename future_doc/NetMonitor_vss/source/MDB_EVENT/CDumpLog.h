/////////////////////////////////////////////////////////////////////////
///@system ��������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CDumpLog.h
///@brief��������CDumpLog
///@history 
///20041001	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef CDUMPLOG_H
#define CDUMPLOG_H

#include "CMemoryDB.h"

/////////////////////////////////////////////////////////////////////////
///CMonitorEntityDumpTrigger�ǲ������ʵ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMonitorEntityDumpTrigger: public CMonitorEntityActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMonitorEntityDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMonitorEntityDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMonitorEntity	Ҫ�����MonitorEntity
	virtual void beforeAdd(CWriteableMonitorEntity *pMonitorEntity);
	
	///����ǰ����	
	///@param	pMonitorEntity	��ˢ�µ�CMonitorEntity
	///@param	pNewMonitorEntity	�µ�ֵ
	virtual void beforeUpdate(CMonitorEntity *pMonitorEntity, CWriteableMonitorEntity *pNewMonitorEntity);
	
	///ɾ��ǰ����
	///@param	pMonitorEntity	Ҫɾ����CMonitorEntity
	virtual void beforeRemove(CMonitorEntity *pMonitorEntity);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CEventEntityDumpTrigger�ǲ����¼�ʵ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CEventEntityDumpTrigger: public CEventEntityActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CEventEntityDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CEventEntityDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pEventEntity	Ҫ�����EventEntity
	virtual void beforeAdd(CWriteableEventEntity *pEventEntity);
	
	///����ǰ����	
	///@param	pEventEntity	��ˢ�µ�CEventEntity
	///@param	pNewEventEntity	�µ�ֵ
	virtual void beforeUpdate(CEventEntity *pEventEntity, CWriteableEventEntity *pNewEventEntity);
	
	///ɾ��ǰ����
	///@param	pEventEntity	Ҫɾ����CEventEntity
	virtual void beforeRemove(CEventEntity *pEventEntity);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDumpLog��һ�������е��޸���Dump��ʽ����Ľ�����������ʵ��
///@author	���ض�
///@version	1.0,20041001
/////////////////////////////////////////////////////////////////////////
class CDumpLog
{
public:
	///���췽��������һ�������
	///@param	pDB	Ҫ������ڴ����ݿ�
	///@param	pConfig	������Ϣ
	CDumpLog(CMemoryDB *pDB, CConfig *pConfig);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDumpLog(void);

	///����dump
	void start(void);
	
	///ֹͣdump
	void stop(void);
	
	///�Ƿ��Ѿ�����
	///@return	1��ʾ�Ѿ�������0��ʾû������
	int isStarted(void);
	
	///�����Ϣ
	///@param	format	��Ϣ��ʽ������fprintf��Ҫ��
	///@param	...	��Ϣ����ϸ����
	void dumpMsg(char *format,...);

private:
	///����ļ�
	FILE *m_DumpOutput;
	
	///�ڴ����ݿ�
	CMemoryDB *m_DB;
	
	///�Ƿ��Ѿ�����
	int m_Started;
	
	CMonitorEntityDumpTrigger *m_MonitorEntityTrigger;
	CEventEntityDumpTrigger *m_EventEntityTrigger;
};

#endif
