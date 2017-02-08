/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseGroupActions.h
///@brief���������ɸ��ڴ����ݿ��Ⱥ�����
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEGROUPACTIONS_H
#define DATABASEGROUPACTIONS_H

#include "BaseDataStruct.h"
#include "databaseFactories.h"


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMonitorEntityActionFunc)(CMonitorEntity * pMonitorEntity, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMonitorEntityUpdateFunc)(CWriteableMonitorEntity * pMonitorEntity, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMonitorEntitySelectFunc)(CMonitorEntity * pMonitorEntity,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMonitorEntityIterator *pIterator, TMonitorEntityActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMonitorEntityIterator *pIterator, TMonitorEntityUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMonitorEntityIterator *pIterator, TMonitorEntitySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TEventEntityActionFunc)(CEventEntity * pEventEntity, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TEventEntityUpdateFunc)(CWriteableEventEntity * pEventEntity, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TEventEntitySelectFunc)(CEventEntity * pEventEntity,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CEventEntityIterator *pIterator, TEventEntityActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CEventEntityIterator *pIterator, TEventEntityUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CEventEntityIterator *pIterator, TEventEntitySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

#endif
