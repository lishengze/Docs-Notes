!!enter system!!
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

!!travel tables!!
!!if !strcmp(@hasTable,"yes")!!
/////////////////////////////////////////////////////////////////////////
///C!!@name!!DumpTrigger�ǲ���!!@usage!!ʱ�Ĵ��������ڱ仯ʱ�������
///@author	!!@author!!
///@version	!!@version!!
/////////////////////////////////////////////////////////////////////////
class C!!@name!!DumpTrigger: public C!!@name!!ActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	C!!@name!!DumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~C!!@name!!DumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	p!!@name!!	Ҫ�����!!@name!!
	virtual void beforeAdd(CWriteable!!@name!! *p!!@name!!);
	
	///����ǰ����	
	///@param	p!!@name!!	��ˢ�µ�C!!@name!!
	///@param	pNew!!@name!!	�µ�ֵ
	virtual void beforeUpdate(C!!@name!! *p!!@name!!, CWriteable!!@name!! *pNew!!@name!!);
	
	///ɾ��ǰ����
	///@param	p!!@name!!	Ҫɾ����C!!@name!!
	virtual void beforeRemove(C!!@name!! *p!!@name!!);
	
private:
	FILE *m_output;
	int m_flag;
};

!!endif!!
!!next!!
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
	
	!!travel tables!!
	!!if !strcmp(@hasTable,"yes")!!
	C!!@name!!DumpTrigger *m_!!@name!!Trigger;
	!!endif!!
	!!next!!
};

#endif
!!leave!!