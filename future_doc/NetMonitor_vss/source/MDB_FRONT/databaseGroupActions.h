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
typedef int (* TSysInvalidateOrderActionFunc)(CSysInvalidateOrder * pSysInvalidateOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInvalidateOrderUpdateFunc)(CWriteableSysInvalidateOrder * pSysInvalidateOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInvalidateOrderSelectFunc)(CSysInvalidateOrder * pSysInvalidateOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysInvalidateOrderIterator *pIterator, TSysInvalidateOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysOrderStatusActionFunc)(CSysOrderStatus * pSysOrderStatus, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysOrderStatusUpdateFunc)(CWriteableSysOrderStatus * pSysOrderStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysOrderStatusSelectFunc)(CSysOrderStatus * pSysOrderStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysOrderStatusIterator *pIterator, TSysOrderStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysOrderStatusIterator *pIterator, TSysOrderStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysOrderStatusIterator *pIterator, TSysOrderStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysBargainOrderActionFunc)(CSysBargainOrder * pSysBargainOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysBargainOrderUpdateFunc)(CWriteableSysBargainOrder * pSysBargainOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysBargainOrderSelectFunc)(CSysBargainOrder * pSysBargainOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysBargainOrderIterator *pIterator, TSysBargainOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysBargainOrderIterator *pIterator, TSysBargainOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysBargainOrderIterator *pIterator, TSysBargainOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInstPropertyActionFunc)(CSysInstProperty * pSysInstProperty, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInstPropertyUpdateFunc)(CWriteableSysInstProperty * pSysInstProperty, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInstPropertySelectFunc)(CSysInstProperty * pSysInstProperty,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysInstPropertyIterator *pIterator, TSysInstPropertyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysInstPropertyIterator *pIterator, TSysInstPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysInstPropertyIterator *pIterator, TSysInstPropertySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMarginRateActionFunc)(CSysMarginRate * pSysMarginRate, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMarginRateUpdateFunc)(CWriteableSysMarginRate * pSysMarginRate, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMarginRateSelectFunc)(CSysMarginRate * pSysMarginRate,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMarginRateIterator *pIterator, TSysMarginRateActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMarginRateIterator *pIterator, TSysMarginRateUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMarginRateIterator *pIterator, TSysMarginRateSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPriceLimitActionFunc)(CSysPriceLimit * pSysPriceLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPriceLimitUpdateFunc)(CWriteableSysPriceLimit * pSysPriceLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPriceLimitSelectFunc)(CSysPriceLimit * pSysPriceLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysPriceLimitIterator *pIterator, TSysPriceLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysPriceLimitIterator *pIterator, TSysPriceLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysPriceLimitIterator *pIterator, TSysPriceLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartPosiLimitActionFunc)(CSysPartPosiLimit * pSysPartPosiLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartPosiLimitUpdateFunc)(CWriteableSysPartPosiLimit * pSysPartPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartPosiLimitSelectFunc)(CSysPartPosiLimit * pSysPartPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysPartPosiLimitIterator *pIterator, TSysPartPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientPosiLimitActionFunc)(CSysClientPosiLimit * pSysClientPosiLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientPosiLimitUpdateFunc)(CWriteableSysClientPosiLimit * pSysClientPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientPosiLimitSelectFunc)(CSysClientPosiLimit * pSysClientPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysClientPosiLimitIterator *pIterator, TSysClientPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysSpecialPosiLimitActionFunc)(CSysSpecialPosiLimit * pSysSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysSpecialPosiLimitUpdateFunc)(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysSpecialPosiLimitSelectFunc)(CSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysSpecialPosiLimitIterator *pIterator, TSysSpecialPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysTransactionChgActionFunc)(CSysTransactionChg * pSysTransactionChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysTransactionChgUpdateFunc)(CWriteableSysTransactionChg * pSysTransactionChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysTransactionChgSelectFunc)(CSysTransactionChg * pSysTransactionChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysTransactionChgIterator *pIterator, TSysTransactionChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysTransactionChgIterator *pIterator, TSysTransactionChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysTransactionChgIterator *pIterator, TSysTransactionChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientChgActionFunc)(CSysClientChg * pSysClientChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientChgUpdateFunc)(CWriteableSysClientChg * pSysClientChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientChgSelectFunc)(CSysClientChg * pSysClientChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysClientChgIterator *pIterator, TSysClientChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysClientChgIterator *pIterator, TSysClientChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysClientChgIterator *pIterator, TSysClientChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartClientChgActionFunc)(CSysPartClientChg * pSysPartClientChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartClientChgUpdateFunc)(CWriteableSysPartClientChg * pSysPartClientChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartClientChgSelectFunc)(CSysPartClientChg * pSysPartClientChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysPartClientChgIterator *pIterator, TSysPartClientChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysPartClientChgIterator *pIterator, TSysPartClientChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysPartClientChgIterator *pIterator, TSysPartClientChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPosiLimitChgActionFunc)(CSysPosiLimitChg * pSysPosiLimitChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPosiLimitChgUpdateFunc)(CWriteableSysPosiLimitChg * pSysPosiLimitChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPosiLimitChgSelectFunc)(CSysPosiLimitChg * pSysPosiLimitChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysPosiLimitChgIterator *pIterator, TSysPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientPosiLimitChgActionFunc)(CSysClientPosiLimitChg * pSysClientPosiLimitChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientPosiLimitChgUpdateFunc)(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientPosiLimitChgSelectFunc)(CSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysClientPosiLimitChgIterator *pIterator, TSysClientPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysSpecPosiLimitChgActionFunc)(CSysSpecPosiLimitChg * pSysSpecPosiLimitChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysSpecPosiLimitChgUpdateFunc)(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysSpecPosiLimitChgSelectFunc)(CSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysSpecPosiLimitChgIterator *pIterator, TSysSpecPosiLimitChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysHedgeDetailChgActionFunc)(CSysHedgeDetailChg * pSysHedgeDetailChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysHedgeDetailChgUpdateFunc)(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysHedgeDetailChgSelectFunc)(CSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysHedgeDetailChgIterator *pIterator, TSysHedgeDetailChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticipantChgActionFunc)(CSysParticipantChg * pSysParticipantChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticipantChgUpdateFunc)(CWriteableSysParticipantChg * pSysParticipantChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticipantChgSelectFunc)(CSysParticipantChg * pSysParticipantChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysParticipantChgIterator *pIterator, TSysParticipantChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysParticipantChgIterator *pIterator, TSysParticipantChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysParticipantChgIterator *pIterator, TSysParticipantChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMarginRateChgActionFunc)(CSysMarginRateChg * pSysMarginRateChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMarginRateChgUpdateFunc)(CWriteableSysMarginRateChg * pSysMarginRateChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMarginRateChgSelectFunc)(CSysMarginRateChg * pSysMarginRateChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMarginRateChgIterator *pIterator, TSysMarginRateChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserIpChgActionFunc)(CSysUserIpChg * pSysUserIpChg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserIpChgUpdateFunc)(CWriteableSysUserIpChg * pSysUserIpChg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserIpChgSelectFunc)(CSysUserIpChg * pSysUserIpChg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysUserIpChgIterator *pIterator, TSysUserIpChgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysUserIpChgIterator *pIterator, TSysUserIpChgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysUserIpChgIterator *pIterator, TSysUserIpChgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartTradeActionFunc)(CSysPartTrade * pSysPartTrade, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartTradeUpdateFunc)(CWriteableSysPartTrade * pSysPartTrade, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysPartTradeSelectFunc)(CSysPartTrade * pSysPartTrade,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysPartTradeIterator *pIterator, TSysPartTradeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysPartTradeIterator *pIterator, TSysPartTradeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysPartTradeIterator *pIterator, TSysPartTradeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbObjectAttrActionFunc)(CSysMdbObjectAttr * pSysMdbObjectAttr, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbObjectAttrUpdateFunc)(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbObjectAttrSelectFunc)(CSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbObjectAttrIterator *pIterator, TSysMdbObjectAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbSyslogInfoActionFunc)(CSysMdbSyslogInfo * pSysMdbSyslogInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbSyslogInfoUpdateFunc)(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbSyslogInfoSelectFunc)(CSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbSyslogInfoIterator *pIterator, TSysMdbSyslogInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserInfoActionFunc)(CSysUserInfo * pSysUserInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserInfoUpdateFunc)(CWriteableSysUserInfo * pSysUserInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserInfoSelectFunc)(CSysUserInfo * pSysUserInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysUserInfoIterator *pIterator, TSysUserInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysUserInfoIterator *pIterator, TSysUserInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysUserInfoIterator *pIterator, TSysUserInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysOnlineUserInfoActionFunc)(CSysOnlineUserInfo * pSysOnlineUserInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysOnlineUserInfoUpdateFunc)(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysOnlineUserInfoSelectFunc)(CSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysOnlineUserInfoIterator *pIterator, TSysOnlineUserInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysWarningEventActionFunc)(CSysWarningEvent * pSysWarningEvent, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysWarningEventUpdateFunc)(CWriteableSysWarningEvent * pSysWarningEvent, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysWarningEventSelectFunc)(CSysWarningEvent * pSysWarningEvent,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysWarningEventIterator *pIterator, TSysWarningEventActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysWarningEventIterator *pIterator, TSysWarningEventUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysWarningEventIterator *pIterator, TSysWarningEventSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysWarningQueryActionFunc)(CSysWarningQuery * pSysWarningQuery, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysWarningQueryUpdateFunc)(CWriteableSysWarningQuery * pSysWarningQuery, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysWarningQuerySelectFunc)(CSysWarningQuery * pSysWarningQuery,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysWarningQueryIterator *pIterator, TSysWarningQueryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysWarningQueryIterator *pIterator, TSysWarningQueryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysWarningQueryIterator *pIterator, TSysWarningQuerySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSyslogEventActionFunc)(CSyslogEvent * pSyslogEvent, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSyslogEventUpdateFunc)(CWriteableSyslogEvent * pSyslogEvent, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSyslogEventSelectFunc)(CSyslogEvent * pSyslogEvent,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSyslogEventIterator *pIterator, TSyslogEventActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSyslogEventIterator *pIterator, TSyslogEventUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSyslogEventIterator *pIterator, TSyslogEventSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysEventDescripActionFunc)(CSysEventDescrip * pSysEventDescrip, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysEventDescripUpdateFunc)(CWriteableSysEventDescrip * pSysEventDescrip, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysEventDescripSelectFunc)(CSysEventDescrip * pSysEventDescrip,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysEventDescripIterator *pIterator, TSysEventDescripActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysEventDescripIterator *pIterator, TSysEventDescripUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysEventDescripIterator *pIterator, TSysEventDescripSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvCommonActionFunc)(CRspQryHostEnvCommon * pRspQryHostEnvCommon, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvCommonUpdateFunc)(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvCommonSelectFunc)(CRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRspQryHostEnvCommonIterator *pIterator, TRspQryHostEnvCommonSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvLanActionFunc)(CRspQryHostEnvLan * pRspQryHostEnvLan, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvLanUpdateFunc)(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvLanSelectFunc)(CRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRspQryHostEnvLanIterator *pIterator, TRspQryHostEnvLanSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvStorageActionFunc)(CRspQryHostEnvStorage * pRspQryHostEnvStorage, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvStorageUpdateFunc)(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvStorageSelectFunc)(CRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRspQryHostEnvStorageIterator *pIterator, TRspQryHostEnvStorageSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvIOActionFunc)(CRspQryHostEnvIO * pRspQryHostEnvIO, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvIOUpdateFunc)(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvIOSelectFunc)(CRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRspQryHostEnvIOIterator *pIterator, TRspQryHostEnvIOSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvFSActionFunc)(CRspQryHostEnvFS * pRspQryHostEnvFS, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvFSUpdateFunc)(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvFSSelectFunc)(CRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRspQryHostEnvFSIterator *pIterator, TRspQryHostEnvFSSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvSwapActionFunc)(CRspQryHostEnvSwap * pRspQryHostEnvSwap, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvSwapUpdateFunc)(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvSwapSelectFunc)(CRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRspQryHostEnvSwapIterator *pIterator, TRspQryHostEnvSwapSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvLanCfgActionFunc)(CRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvLanCfgUpdateFunc)(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRspQryHostEnvLanCfgSelectFunc)(CRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRspQryHostEnvLanCfgIterator *pIterator, TRspQryHostEnvLanCfgSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopCpuInfoActionFunc)(CSysMdbTopCpuInfo * pSysMdbTopCpuInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopCpuInfoUpdateFunc)(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopCpuInfoSelectFunc)(CSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbTopCpuInfoIterator *pIterator, TSysMdbTopCpuInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopMemInfoActionFunc)(CSysMdbTopMemInfo * pSysMdbTopMemInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopMemInfoUpdateFunc)(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopMemInfoSelectFunc)(CSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbTopMemInfoIterator *pIterator, TSysMdbTopMemInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopProcessInfoActionFunc)(CSysMdbTopProcessInfo * pSysMdbTopProcessInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopProcessInfoUpdateFunc)(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTopProcessInfoSelectFunc)(CSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbTopProcessInfoIterator *pIterator, TSysMdbTopProcessInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbFileSystemInfoActionFunc)(CSysMdbFileSystemInfo * pSysMdbFileSystemInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbFileSystemInfoUpdateFunc)(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbFileSystemInfoSelectFunc)(CSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbFileSystemInfoIterator *pIterator, TSysMdbFileSystemInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbNetworkInfoActionFunc)(CSysMdbNetworkInfo * pSysMdbNetworkInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbNetworkInfoUpdateFunc)(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbNetworkInfoSelectFunc)(CSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbNetworkInfoIterator *pIterator, TSysMdbNetworkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticipantInitActionFunc)(CSysParticipantInit * pSysParticipantInit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticipantInitUpdateFunc)(CWriteableSysParticipantInit * pSysParticipantInit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticipantInitSelectFunc)(CSysParticipantInit * pSysParticipantInit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysParticipantInitIterator *pIterator, TSysParticipantInitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysParticipantInitIterator *pIterator, TSysParticipantInitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysParticipantInitIterator *pIterator, TSysParticipantInitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserInitActionFunc)(CSysUserInit * pSysUserInit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserInitUpdateFunc)(CWriteableSysUserInit * pSysUserInit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysUserInitSelectFunc)(CSysUserInit * pSysUserInit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysUserInitIterator *pIterator, TSysUserInitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysUserInitIterator *pIterator, TSysUserInitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysUserInitIterator *pIterator, TSysUserInitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientInitActionFunc)(CSysClientInit * pSysClientInit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientInitUpdateFunc)(CWriteableSysClientInit * pSysClientInit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysClientInitSelectFunc)(CSysClientInit * pSysClientInit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysClientInitIterator *pIterator, TSysClientInitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysClientInitIterator *pIterator, TSysClientInitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysClientInitIterator *pIterator, TSysClientInitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysTradeUserLoginInfoActionFunc)(CSysTradeUserLoginInfo * pSysTradeUserLoginInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysTradeUserLoginInfoUpdateFunc)(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysTradeUserLoginInfoSelectFunc)(CSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysTradeUserLoginInfoIterator *pIterator, TSysTradeUserLoginInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbWebAppInfoActionFunc)(CSysMdbWebAppInfo * pSysMdbWebAppInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbWebAppInfoUpdateFunc)(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbWebAppInfoSelectFunc)(CSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbWebAppInfoIterator *pIterator, TSysMdbWebAppInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbMemPoolInfoActionFunc)(CSysMdbMemPoolInfo * pSysMdbMemPoolInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbMemPoolInfoUpdateFunc)(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbMemPoolInfoSelectFunc)(CSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbMemPoolInfoIterator *pIterator, TSysMdbMemPoolInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbConnectorInfoActionFunc)(CSysMdbConnectorInfo * pSysMdbConnectorInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbConnectorInfoUpdateFunc)(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbConnectorInfoSelectFunc)(CSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbConnectorInfoIterator *pIterator, TSysMdbConnectorInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbDBQueryActionFunc)(CSysMdbDBQuery * pSysMdbDBQuery, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbDBQueryUpdateFunc)(CWriteableSysMdbDBQuery * pSysMdbDBQuery, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbDBQuerySelectFunc)(CSysMdbDBQuery * pSysMdbDBQuery,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQueryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQueryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbDBQueryIterator *pIterator, TSysMdbDBQuerySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetAreaActionFunc)(CSysNetArea * pSysNetArea, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetAreaUpdateFunc)(CWriteableSysNetArea * pSysNetArea, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetAreaSelectFunc)(CSysNetArea * pSysNetArea,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetAreaIterator *pIterator, TSysNetAreaActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetAreaIterator *pIterator, TSysNetAreaUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetAreaIterator *pIterator, TSysNetAreaSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubAreaActionFunc)(CSysNetSubArea * pSysNetSubArea, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubAreaUpdateFunc)(CWriteableSysNetSubArea * pSysNetSubArea, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubAreaSelectFunc)(CSysNetSubArea * pSysNetSubArea,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetSubAreaIterator *pIterator, TSysNetSubAreaSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubAreaIPActionFunc)(CSysNetSubAreaIP * pSysNetSubAreaIP, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubAreaIPUpdateFunc)(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubAreaIPSelectFunc)(CSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetSubAreaIPIterator *pIterator, TSysNetSubAreaIPSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetFuncAreaActionFunc)(CSysNetFuncArea * pSysNetFuncArea, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetFuncAreaUpdateFunc)(CWriteableSysNetFuncArea * pSysNetFuncArea, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetFuncAreaSelectFunc)(CSysNetFuncArea * pSysNetFuncArea,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetFuncAreaIterator *pIterator, TSysNetFuncAreaSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceActionFunc)(CSysNetDevice * pSysNetDevice, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceUpdateFunc)(CWriteableSysNetDevice * pSysNetDevice, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceSelectFunc)(CSysNetDevice * pSysNetDevice,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetDeviceIterator *pIterator, TSysNetDeviceActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetDeviceIterator *pIterator, TSysNetDeviceUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetDeviceIterator *pIterator, TSysNetDeviceSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceLinkedActionFunc)(CSysNetDeviceLinked * pSysNetDeviceLinked, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceLinkedUpdateFunc)(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceLinkedSelectFunc)(CSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetDeviceLinkedIterator *pIterator, TSysNetDeviceLinkedSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetOIDActionFunc)(CSysNetOID * pSysNetOID, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetOIDUpdateFunc)(CWriteableSysNetOID * pSysNetOID, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetOIDSelectFunc)(CSysNetOID * pSysNetOID,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetOIDIterator *pIterator, TSysNetOIDActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetOIDIterator *pIterator, TSysNetOIDUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetOIDIterator *pIterator, TSysNetOIDSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceTypeActionFunc)(CSysNetDeviceType * pSysNetDeviceType, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceTypeUpdateFunc)(CWriteableSysNetDeviceType * pSysNetDeviceType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceTypeSelectFunc)(CSysNetDeviceType * pSysNetDeviceType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetDeviceTypeIterator *pIterator, TSysNetDeviceTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetTimePolicyActionFunc)(CSysNetTimePolicy * pSysNetTimePolicy, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetTimePolicyUpdateFunc)(CWriteableSysNetTimePolicy * pSysNetTimePolicy, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetTimePolicySelectFunc)(CSysNetTimePolicy * pSysNetTimePolicy,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetTimePolicyIterator *pIterator, TSysNetTimePolicySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetGatherTaskActionFunc)(CSysNetGatherTask * pSysNetGatherTask, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetGatherTaskUpdateFunc)(CWriteableSysNetGatherTask * pSysNetGatherTask, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetGatherTaskSelectFunc)(CSysNetGatherTask * pSysNetGatherTask,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetGatherTaskIterator *pIterator, TSysNetGatherTaskSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceCategoryActionFunc)(CSysNetDeviceCategory * pSysNetDeviceCategory, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceCategoryUpdateFunc)(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDeviceCategorySelectFunc)(CSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategoryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategoryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetDeviceCategoryIterator *pIterator, TSysNetDeviceCategorySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetManufactoryActionFunc)(CSysNetManufactory * pSysNetManufactory, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetManufactoryUpdateFunc)(CWriteableSysNetManufactory * pSysNetManufactory, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetManufactorySelectFunc)(CSysNetManufactory * pSysNetManufactory,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetManufactoryIterator *pIterator, TSysNetManufactoryActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetManufactoryIterator *pIterator, TSysNetManufactoryUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetManufactoryIterator *pIterator, TSysNetManufactorySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetCommunityActionFunc)(CSysNetCommunity * pSysNetCommunity, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetCommunityUpdateFunc)(CWriteableSysNetCommunity * pSysNetCommunity, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetCommunitySelectFunc)(CSysNetCommunity * pSysNetCommunity,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetCommunityIterator *pIterator, TSysNetCommunityActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetCommunityIterator *pIterator, TSysNetCommunityUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetCommunityIterator *pIterator, TSysNetCommunitySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPortTypeActionFunc)(CSysNetPortType * pSysNetPortType, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPortTypeUpdateFunc)(CWriteableSysNetPortType * pSysNetPortType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPortTypeSelectFunc)(CSysNetPortType * pSysNetPortType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetPortTypeIterator *pIterator, TSysNetPortTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetInterfaceActionFunc)(CSysNetInterface * pSysNetInterface, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetInterfaceUpdateFunc)(CWriteableSysNetInterface * pSysNetInterface, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetInterfaceSelectFunc)(CSysNetInterface * pSysNetInterface,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetInterfaceIterator *pIterator, TSysNetInterfaceSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetGeneralOIDActionFunc)(CSysNetGeneralOID * pSysNetGeneralOID, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetGeneralOIDUpdateFunc)(CWriteableSysNetGeneralOID * pSysNetGeneralOID, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetGeneralOIDSelectFunc)(CSysNetGeneralOID * pSysNetGeneralOID,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetGeneralOIDIterator *pIterator, TSysNetGeneralOIDSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTypeActionFunc)(CSysNetMonitorType * pSysNetMonitorType, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTypeUpdateFunc)(CWriteableSysNetMonitorType * pSysNetMonitorType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTypeSelectFunc)(CSysNetMonitorType * pSysNetMonitorType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorTypeIterator *pIterator, TSysNetMonitorTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorAttrScopeActionFunc)(CSysNetMonitorAttrScope * pSysNetMonitorAttrScope, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorAttrScopeUpdateFunc)(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorAttrScopeSelectFunc)(CSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorAttrScopeIterator *pIterator, TSysNetMonitorAttrScopeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorAttrTypeActionFunc)(CSysNetMonitorAttrType * pSysNetMonitorAttrType, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorAttrTypeUpdateFunc)(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorAttrTypeSelectFunc)(CSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorAttrTypeIterator *pIterator, TSysNetMonitorAttrTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorCommandTypeActionFunc)(CSysNetMonitorCommandType * pSysNetMonitorCommandType, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorCommandTypeUpdateFunc)(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorCommandTypeSelectFunc)(CSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorCommandTypeIterator *pIterator, TSysNetMonitorCommandTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorActionGroupActionFunc)(CSysNetMonitorActionGroup * pSysNetMonitorActionGroup, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorActionGroupUpdateFunc)(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorActionGroupSelectFunc)(CSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorActionGroupIterator *pIterator, TSysNetMonitorActionGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorDeviceGroupActionFunc)(CSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorDeviceGroupUpdateFunc)(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorDeviceGroupSelectFunc)(CSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorDeviceGroupIterator *pIterator, TSysNetMonitorDeviceGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskInfoActionFunc)(CSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskInfoUpdateFunc)(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskInfoSelectFunc)(CSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorTaskInfoIterator *pIterator, TSysNetMonitorTaskInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskObjectSetActionFunc)(CSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskObjectSetUpdateFunc)(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskObjectSetSelectFunc)(CSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorTaskObjectSetIterator *pIterator, TSysNetMonitorTaskObjectSetSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskResultActionFunc)(CSysNetMonitorTaskResult * pSysNetMonitorTaskResult, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskResultUpdateFunc)(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskResultSelectFunc)(CSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorTaskResultIterator *pIterator, TSysNetMonitorTaskResultSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartyLinkInfoActionFunc)(CSysNetPartyLinkInfo * pSysNetPartyLinkInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartyLinkInfoUpdateFunc)(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartyLinkInfoSelectFunc)(CSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetPartyLinkInfoIterator *pIterator, TSysNetPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDelPartyLinkInfoActionFunc)(CSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDelPartyLinkInfoUpdateFunc)(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDelPartyLinkInfoSelectFunc)(CSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetDelPartyLinkInfoIterator *pIterator, TSysNetDelPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartyLinkAddrChangeActionFunc)(CSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartyLinkAddrChangeUpdateFunc)(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartyLinkAddrChangeSelectFunc)(CSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetPartyLinkAddrChangeIterator *pIterator, TSysNetPartyLinkAddrChangeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorActionAttrActionFunc)(CSysNetMonitorActionAttr * pSysNetMonitorActionAttr, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorActionAttrUpdateFunc)(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorActionAttrSelectFunc)(CSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorActionAttrIterator *pIterator, TSysNetMonitorActionAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetModuleActionFunc)(CSysNetModule * pSysNetModule, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetModuleUpdateFunc)(CWriteableSysNetModule * pSysNetModule, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetModuleSelectFunc)(CSysNetModule * pSysNetModule,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetModuleIterator *pIterator, TSysNetModuleActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetModuleIterator *pIterator, TSysNetModuleUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetModuleIterator *pIterator, TSysNetModuleSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventExprActionFunc)(CSysNetEventExpr * pSysNetEventExpr, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventExprUpdateFunc)(CWriteableSysNetEventExpr * pSysNetEventExpr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventExprSelectFunc)(CSysNetEventExpr * pSysNetEventExpr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetEventExprIterator *pIterator, TSysNetEventExprActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetEventExprIterator *pIterator, TSysNetEventExprUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetEventExprIterator *pIterator, TSysNetEventExprSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventTypeActionFunc)(CSysNetEventType * pSysNetEventType, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventTypeUpdateFunc)(CWriteableSysNetEventType * pSysNetEventType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventTypeSelectFunc)(CSysNetEventType * pSysNetEventType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetEventTypeIterator *pIterator, TSysNetEventTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubEventTypeActionFunc)(CSysNetSubEventType * pSysNetSubEventType, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubEventTypeUpdateFunc)(CWriteableSysNetSubEventType * pSysNetSubEventType, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetSubEventTypeSelectFunc)(CSysNetSubEventType * pSysNetSubEventType,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetSubEventTypeIterator *pIterator, TSysNetSubEventTypeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventLevelActionFunc)(CSysNetEventLevel * pSysNetEventLevel, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventLevelUpdateFunc)(CWriteableSysNetEventLevel * pSysNetEventLevel, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetEventLevelSelectFunc)(CSysNetEventLevel * pSysNetEventLevel,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetEventLevelIterator *pIterator, TSysNetEventLevelSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorDeviceTaskActionFunc)(CSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorDeviceTaskUpdateFunc)(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorDeviceTaskSelectFunc)(CSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorDeviceTaskIterator *pIterator, TSysNetMonitorDeviceTaskSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskInstAttrsActionFunc)(CSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskInstAttrsUpdateFunc)(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMonitorTaskInstAttrsSelectFunc)(CSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMonitorTaskInstAttrsIterator *pIterator, TSysNetMonitorTaskInstAttrsSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetBaseLineActionFunc)(CSysNetBaseLine * pSysNetBaseLine, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetBaseLineUpdateFunc)(CWriteableSysNetBaseLine * pSysNetBaseLine, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetBaseLineSelectFunc)(CSysNetBaseLine * pSysNetBaseLine,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetBaseLineIterator *pIterator, TSysNetBaseLineSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetBaseLineTaskActionFunc)(CSysNetBaseLineTask * pSysNetBaseLineTask, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetBaseLineTaskUpdateFunc)(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetBaseLineTaskSelectFunc)(CSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetBaseLineTaskIterator *pIterator, TSysNetBaseLineTaskSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbNetPartyLinkStatusInfoActionFunc)(CSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbNetPartyLinkStatusInfoUpdateFunc)(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbNetPartyLinkStatusInfoSelectFunc)(CSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbNetPartyLinkStatusInfoIterator *pIterator, TSysMdbNetPartyLinkStatusInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMemberSDHLineInfoActionFunc)(CSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMemberSDHLineInfoUpdateFunc)(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetMemberSDHLineInfoSelectFunc)(CSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetMemberSDHLineInfoIterator *pIterator, TSysNetMemberSDHLineInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDDNLinkInfoActionFunc)(CSysNetDDNLinkInfo * pSysNetDDNLinkInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDDNLinkInfoUpdateFunc)(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetDDNLinkInfoSelectFunc)(CSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetDDNLinkInfoIterator *pIterator, TSysNetDDNLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPseudMemberLinkInfoActionFunc)(CSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPseudMemberLinkInfoUpdateFunc)(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPseudMemberLinkInfoSelectFunc)(CSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetPseudMemberLinkInfoIterator *pIterator, TSysNetPseudMemberLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetOuterDeviceInfoActionFunc)(CSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetOuterDeviceInfoUpdateFunc)(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetOuterDeviceInfoSelectFunc)(CSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetOuterDeviceInfoIterator *pIterator, TSysNetOuterDeviceInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysLocalPingResultInfoActionFunc)(CSysLocalPingResultInfo * pSysLocalPingResultInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysLocalPingResultInfoUpdateFunc)(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysLocalPingResultInfoSelectFunc)(CSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysLocalPingResultInfoIterator *pIterator, TSysLocalPingResultInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysRomotePingResultInfoActionFunc)(CSysRomotePingResultInfo * pSysRomotePingResultInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysRomotePingResultInfoUpdateFunc)(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysRomotePingResultInfoSelectFunc)(CSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysRomotePingResultInfoIterator *pIterator, TSysRomotePingResultInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticTradeOrderStatesActionFunc)(CSysParticTradeOrderStates * pSysParticTradeOrderStates, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticTradeOrderStatesUpdateFunc)(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysParticTradeOrderStatesSelectFunc)(CSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysParticTradeOrderStatesIterator *pIterator, TSysParticTradeOrderStatesSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbRouterInfoActionFunc)(CSysMdbRouterInfo * pSysMdbRouterInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbRouterInfoUpdateFunc)(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbRouterInfoSelectFunc)(CSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbRouterInfoIterator *pIterator, TSysMdbRouterInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbDiskIOActionFunc)(CSysMdbDiskIO * pSysMdbDiskIO, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbDiskIOUpdateFunc)(CWriteableSysMdbDiskIO * pSysMdbDiskIO, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbDiskIOSelectFunc)(CSysMdbDiskIO * pSysMdbDiskIO,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbDiskIOIterator *pIterator, TSysMdbDiskIOSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbStatInfoActionFunc)(CSysMdbStatInfo * pSysMdbStatInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbStatInfoUpdateFunc)(CWriteableSysMdbStatInfo * pSysMdbStatInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbStatInfoSelectFunc)(CSysMdbStatInfo * pSysMdbStatInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbStatInfoIterator *pIterator, TSysMdbStatInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTradeFrontOrderRttStatActionFunc)(CSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTradeFrontOrderRttStatUpdateFunc)(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMdbTradeFrontOrderRttStatSelectFunc)(CSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMdbTradeFrontOrderRttStatIterator *pIterator, TSysMdbTradeFrontOrderRttStatSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInstrumentStatusActionFunc)(CSysInstrumentStatus * pSysInstrumentStatus, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInstrumentStatusUpdateFunc)(CWriteableSysInstrumentStatus * pSysInstrumentStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysInstrumentStatusSelectFunc)(CSysInstrumentStatus * pSysInstrumentStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysInstrumentStatusIterator *pIterator, TSysInstrumentStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysCurrTradingSegmentAttrActionFunc)(CSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysCurrTradingSegmentAttrUpdateFunc)(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysCurrTradingSegmentAttrSelectFunc)(CSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysCurrTradingSegmentAttrIterator *pIterator, TSysCurrTradingSegmentAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMemberLinkCostActionFunc)(CSysMemberLinkCost * pSysMemberLinkCost, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMemberLinkCostUpdateFunc)(CWriteableSysMemberLinkCost * pSysMemberLinkCost, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysMemberLinkCostSelectFunc)(CSysMemberLinkCost * pSysMemberLinkCost,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysMemberLinkCostIterator *pIterator, TSysMemberLinkCostSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartylinkMonthlyRentActionFunc)(CSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartylinkMonthlyRentUpdateFunc)(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetPartylinkMonthlyRentSelectFunc)(CSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetPartylinkMonthlyRentIterator *pIterator, TSysNetPartylinkMonthlyRentSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetNonPartyLinkInfoActionFunc)(CSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetNonPartyLinkInfoUpdateFunc)(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSysNetNonPartyLinkInfoSelectFunc)(CSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSysNetNonPartyLinkInfoIterator *pIterator, TSysNetNonPartyLinkInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

#endif
