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
typedef int (* TExchangeDataSyncStatusActionFunc)(CExchangeDataSyncStatus * pExchangeDataSyncStatus, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExchangeDataSyncStatusUpdateFunc)(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExchangeDataSyncStatusSelectFunc)(CExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CExchangeDataSyncStatusIterator *pIterator, TExchangeDataSyncStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSGDataSyncStatusActionFunc)(CSGDataSyncStatus * pSGDataSyncStatus, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSGDataSyncStatusUpdateFunc)(CWriteableSGDataSyncStatus * pSGDataSyncStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSGDataSyncStatusSelectFunc)(CSGDataSyncStatus * pSGDataSyncStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSGDataSyncStatusIterator *pIterator, TSGDataSyncStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrentTimeActionFunc)(CCurrentTime * pCurrentTime, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrentTimeUpdateFunc)(CWriteableCurrentTime * pCurrentTime, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrentTimeSelectFunc)(CCurrentTime * pCurrentTime,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrentTimeIterator *pIterator, TCurrentTimeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrentTimeIterator *pIterator, TCurrentTimeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrentTimeIterator *pIterator, TCurrentTimeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDataCenterDescActionFunc)(CDataCenterDesc * pDataCenterDesc, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDataCenterDescUpdateFunc)(CWriteableDataCenterDesc * pDataCenterDesc, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDataCenterDescSelectFunc)(CDataCenterDesc * pDataCenterDesc,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CDataCenterDescIterator *pIterator, TDataCenterDescActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CDataCenterDescIterator *pIterator, TDataCenterDescUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CDataCenterDescIterator *pIterator, TDataCenterDescSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExchangeActionFunc)(CExchange * pExchange, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExchangeUpdateFunc)(CWriteableExchange * pExchange, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExchangeSelectFunc)(CExchange * pExchange,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CExchangeIterator *pIterator, TExchangeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CExchangeIterator *pIterator, TExchangeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CExchangeIterator *pIterator, TExchangeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSettlementGroupActionFunc)(CSettlementGroup * pSettlementGroup, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSettlementGroupUpdateFunc)(CWriteableSettlementGroup * pSettlementGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TSettlementGroupSelectFunc)(CSettlementGroup * pSettlementGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CSettlementGroupIterator *pIterator, TSettlementGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CSettlementGroupIterator *pIterator, TSettlementGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CSettlementGroupIterator *pIterator, TSettlementGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketActionFunc)(CMarket * pMarket, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketUpdateFunc)(CWriteableMarket * pMarket, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketSelectFunc)(CMarket * pMarket,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMarketIterator *pIterator, TMarketActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMarketIterator *pIterator, TMarketUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMarketIterator *pIterator, TMarketSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketProductActionFunc)(CMarketProduct * pMarketProduct, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketProductUpdateFunc)(CWriteableMarketProduct * pMarketProduct, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketProductSelectFunc)(CMarketProduct * pMarketProduct,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMarketProductIterator *pIterator, TMarketProductActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMarketProductIterator *pIterator, TMarketProductUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMarketProductIterator *pIterator, TMarketProductSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketProductGroupActionFunc)(CMarketProductGroup * pMarketProductGroup, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketProductGroupUpdateFunc)(CWriteableMarketProductGroup * pMarketProductGroup, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketProductGroupSelectFunc)(CMarketProductGroup * pMarketProductGroup,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMarketProductGroupIterator *pIterator, TMarketProductGroupActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMarketProductGroupIterator *pIterator, TMarketProductGroupUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMarketProductGroupIterator *pIterator, TMarketProductGroupSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMdPubStatusActionFunc)(CMdPubStatus * pMdPubStatus, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMdPubStatusUpdateFunc)(CWriteableMdPubStatus * pMdPubStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMdPubStatusSelectFunc)(CMdPubStatus * pMdPubStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMdPubStatusIterator *pIterator, TMdPubStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMdPubStatusIterator *pIterator, TMdPubStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMdPubStatusIterator *pIterator, TMdPubStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataTopicActionFunc)(CMarketDataTopic * pMarketDataTopic, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataTopicUpdateFunc)(CWriteableMarketDataTopic * pMarketDataTopic, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataTopicSelectFunc)(CMarketDataTopic * pMarketDataTopic,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMarketDataTopicIterator *pIterator, TMarketDataTopicActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMarketDataTopicIterator *pIterator, TMarketDataTopicUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMarketDataTopicIterator *pIterator, TMarketDataTopicSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartTopicSubscribeActionFunc)(CPartTopicSubscribe * pPartTopicSubscribe, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartTopicSubscribeUpdateFunc)(CWriteablePartTopicSubscribe * pPartTopicSubscribe, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartTopicSubscribeSelectFunc)(CPartTopicSubscribe * pPartTopicSubscribe,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartTopicSubscribeIterator *pIterator, TPartTopicSubscribeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TParticipantActionFunc)(CParticipant * pParticipant, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TParticipantUpdateFunc)(CWriteableParticipant * pParticipant, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TParticipantSelectFunc)(CParticipant * pParticipant,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CParticipantIterator *pIterator, TParticipantActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CParticipantIterator *pIterator, TParticipantUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CParticipantIterator *pIterator, TParticipantSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserActionFunc)(CUser * pUser, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserUpdateFunc)(CWriteableUser * pUser, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserSelectFunc)(CUser * pUser,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CUserIterator *pIterator, TUserActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CUserIterator *pIterator, TUserUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CUserIterator *pIterator, TUserSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientActionFunc)(CClient * pClient, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientUpdateFunc)(CWriteableClient * pClient, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientSelectFunc)(CClient * pClient,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CClientIterator *pIterator, TClientActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CClientIterator *pIterator, TClientUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CClientIterator *pIterator, TClientSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserIPActionFunc)(CUserIP * pUserIP, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserIPUpdateFunc)(CWriteableUserIP * pUserIP, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserIPSelectFunc)(CUserIP * pUserIP,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CUserIPIterator *pIterator, TUserIPActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CUserIPIterator *pIterator, TUserIPUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CUserIPIterator *pIterator, TUserIPSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientActionFunc)(CPartClient * pPartClient, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientUpdateFunc)(CWriteablePartClient * pPartClient, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientSelectFunc)(CPartClient * pPartClient,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartClientIterator *pIterator, TPartClientActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartClientIterator *pIterator, TPartClientUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartClientIterator *pIterator, TPartClientSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClearingTradingPartActionFunc)(CClearingTradingPart * pClearingTradingPart, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClearingTradingPartUpdateFunc)(CWriteableClearingTradingPart * pClearingTradingPart, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClearingTradingPartSelectFunc)(CClearingTradingPart * pClearingTradingPart,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CClearingTradingPartIterator *pIterator, TClearingTradingPartActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CClearingTradingPartIterator *pIterator, TClearingTradingPartUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CClearingTradingPartIterator *pIterator, TClearingTradingPartSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TAliasDefineActionFunc)(CAliasDefine * pAliasDefine, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TAliasDefineUpdateFunc)(CWriteableAliasDefine * pAliasDefine, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TAliasDefineSelectFunc)(CAliasDefine * pAliasDefine,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CAliasDefineIterator *pIterator, TAliasDefineActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CAliasDefineIterator *pIterator, TAliasDefineUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CAliasDefineIterator *pIterator, TAliasDefineSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserFunctionRightActionFunc)(CUserFunctionRight * pUserFunctionRight, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserFunctionRightUpdateFunc)(CWriteableUserFunctionRight * pUserFunctionRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserFunctionRightSelectFunc)(CUserFunctionRight * pUserFunctionRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CUserFunctionRightIterator *pIterator, TUserFunctionRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CUserFunctionRightIterator *pIterator, TUserFunctionRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CUserFunctionRightIterator *pIterator, TUserFunctionRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TAccountActionFunc)(CAccount * pAccount, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TAccountUpdateFunc)(CWriteableAccount * pAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TAccountSelectFunc)(CAccount * pAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CAccountIterator *pIterator, TAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CAccountIterator *pIterator, TAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CAccountIterator *pIterator, TAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserCommFluxActionFunc)(CUserCommFlux * pUserCommFlux, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserCommFluxUpdateFunc)(CWriteableUserCommFlux * pUserCommFlux, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserCommFluxSelectFunc)(CUserCommFlux * pUserCommFlux,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CUserCommFluxIterator *pIterator, TUserCommFluxActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CUserCommFluxIterator *pIterator, TUserCommFluxUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CUserCommFluxIterator *pIterator, TUserCommFluxSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataLogActionFunc)(CMarketDataLog * pMarketDataLog, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataLogUpdateFunc)(CWriteableMarketDataLog * pMarketDataLog, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataLogSelectFunc)(CMarketDataLog * pMarketDataLog,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMarketDataLogIterator *pIterator, TMarketDataLogActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMarketDataLogIterator *pIterator, TMarketDataLogUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMarketDataLogIterator *pIterator, TMarketDataLogSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserSessionActionFunc)(CUserSession * pUserSession, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserSessionUpdateFunc)(CWriteableUserSession * pUserSession, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUserSessionSelectFunc)(CUserSession * pUserSession,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CUserSessionIterator *pIterator, TUserSessionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CUserSessionIterator *pIterator, TUserSessionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CUserSessionIterator *pIterator, TUserSessionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMDSessionActionFunc)(CMDSession * pMDSession, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMDSessionUpdateFunc)(CWriteableMDSession * pMDSession, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMDSessionSelectFunc)(CMDSession * pMDSession,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMDSessionIterator *pIterator, TMDSessionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMDSessionIterator *pIterator, TMDSessionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMDSessionIterator *pIterator, TMDSessionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TLoginInfoActionFunc)(CLoginInfo * pLoginInfo, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TLoginInfoUpdateFunc)(CWriteableLoginInfo * pLoginInfo, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TLoginInfoSelectFunc)(CLoginInfo * pLoginInfo,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CLoginInfoIterator *pIterator, TLoginInfoActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CLoginInfoIterator *pIterator, TLoginInfoUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CLoginInfoIterator *pIterator, TLoginInfoSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDepthMarketDataDetailActionFunc)(CDepthMarketDataDetail * pDepthMarketDataDetail, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDepthMarketDataDetailUpdateFunc)(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDepthMarketDataDetailSelectFunc)(CDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CDepthMarketDataDetailIterator *pIterator, TDepthMarketDataDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentStatusDetailActionFunc)(CInstrumentStatusDetail * pInstrumentStatusDetail, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentStatusDetailUpdateFunc)(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentStatusDetailSelectFunc)(CInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CInstrumentStatusDetailIterator *pIterator, TInstrumentStatusDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TFrontStatusActionFunc)(CFrontStatus * pFrontStatus, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TFrontStatusUpdateFunc)(CWriteableFrontStatus * pFrontStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TFrontStatusSelectFunc)(CFrontStatus * pFrontStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CFrontStatusIterator *pIterator, TFrontStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CFrontStatusIterator *pIterator, TFrontStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CFrontStatusIterator *pIterator, TFrontStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMaxLocalIDActionFunc)(CMaxLocalID * pMaxLocalID, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMaxLocalIDUpdateFunc)(CWriteableMaxLocalID * pMaxLocalID, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMaxLocalIDSelectFunc)(CMaxLocalID * pMaxLocalID,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMaxLocalIDIterator *pIterator, TMaxLocalIDActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMaxLocalIDIterator *pIterator, TMaxLocalIDUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMaxLocalIDIterator *pIterator, TMaxLocalIDSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBulletinActionFunc)(CBulletin * pBulletin, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBulletinUpdateFunc)(CWriteableBulletin * pBulletin, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBulletinSelectFunc)(CBulletin * pBulletin,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CBulletinIterator *pIterator, TBulletinActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CBulletinIterator *pIterator, TBulletinUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CBulletinIterator *pIterator, TBulletinSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataModifyActionFunc)(CMarketDataModify * pMarketDataModify, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataModifyUpdateFunc)(CWriteableMarketDataModify * pMarketDataModify, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataModifySelectFunc)(CMarketDataModify * pMarketDataModify,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMarketDataModifyIterator *pIterator, TMarketDataModifyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMarketDataModifyIterator *pIterator, TMarketDataModifyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMarketDataModifyIterator *pIterator, TMarketDataModifySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDepthMarketDataActionFunc)(CDepthMarketData * pDepthMarketData, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDepthMarketDataUpdateFunc)(CWriteableDepthMarketData * pDepthMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TDepthMarketDataSelectFunc)(CDepthMarketData * pDepthMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CDepthMarketDataIterator *pIterator, TDepthMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CDepthMarketDataIterator *pIterator, TDepthMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CDepthMarketDataIterator *pIterator, TDepthMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTopicMarketDataActionFunc)(CTopicMarketData * pTopicMarketData, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTopicMarketDataUpdateFunc)(CWriteableTopicMarketData * pTopicMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTopicMarketDataSelectFunc)(CTopicMarketData * pTopicMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CTopicMarketDataIterator *pIterator, TTopicMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CTopicMarketDataIterator *pIterator, TTopicMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CTopicMarketDataIterator *pIterator, TTopicMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTopicMarketDataVersionActionFunc)(CTopicMarketDataVersion * pTopicMarketDataVersion, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTopicMarketDataVersionUpdateFunc)(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTopicMarketDataVersionSelectFunc)(CTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CTopicMarketDataVersionIterator *pIterator, TTopicMarketDataVersionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInformationActionFunc)(CInformation * pInformation, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInformationUpdateFunc)(CWriteableInformation * pInformation, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInformationSelectFunc)(CInformation * pInformation,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CInformationIterator *pIterator, TInformationActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CInformationIterator *pIterator, TInformationUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CInformationIterator *pIterator, TInformationSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOrderCountActionFunc)(COrderCount * pOrderCount, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOrderCountUpdateFunc)(CWriteableOrderCount * pOrderCount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOrderCountSelectFunc)(COrderCount * pOrderCount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(COrderCountIterator *pIterator, TOrderCountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(COrderCountIterator *pIterator, TOrderCountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(COrderCountIterator *pIterator, TOrderCountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentActionFunc)(CInstrument * pInstrument, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentUpdateFunc)(CWriteableInstrument * pInstrument, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentSelectFunc)(CInstrument * pInstrument,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CInstrumentIterator *pIterator, TInstrumentActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CInstrumentIterator *pIterator, TInstrumentUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CInstrumentIterator *pIterator, TInstrumentSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCombinationLegActionFunc)(CCombinationLeg * pCombinationLeg, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCombinationLegUpdateFunc)(CWriteableCombinationLeg * pCombinationLeg, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCombinationLegSelectFunc)(CCombinationLeg * pCombinationLeg,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCombinationLegIterator *pIterator, TCombinationLegActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCombinationLegIterator *pIterator, TCombinationLegUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCombinationLegIterator *pIterator, TCombinationLegSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartRoleAccountActionFunc)(CPartRoleAccount * pPartRoleAccount, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartRoleAccountUpdateFunc)(CWriteablePartRoleAccount * pPartRoleAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartRoleAccountSelectFunc)(CPartRoleAccount * pPartRoleAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartRoleAccountIterator *pIterator, TPartRoleAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartRoleAccountIterator *pIterator, TPartRoleAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartRoleAccountIterator *pIterator, TPartRoleAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartProductRoleActionFunc)(CPartProductRole * pPartProductRole, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartProductRoleUpdateFunc)(CWriteablePartProductRole * pPartProductRole, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartProductRoleSelectFunc)(CPartProductRole * pPartProductRole,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartProductRoleIterator *pIterator, TPartProductRoleActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartProductRoleIterator *pIterator, TPartProductRoleUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartProductRoleIterator *pIterator, TPartProductRoleSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartProductRightActionFunc)(CPartProductRight * pPartProductRight, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartProductRightUpdateFunc)(CWriteablePartProductRight * pPartProductRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartProductRightSelectFunc)(CPartProductRight * pPartProductRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartProductRightIterator *pIterator, TPartProductRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartProductRightIterator *pIterator, TPartProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartProductRightIterator *pIterator, TPartProductRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartInstrumentRightActionFunc)(CPartInstrumentRight * pPartInstrumentRight, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartInstrumentRightUpdateFunc)(CWriteablePartInstrumentRight * pPartInstrumentRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartInstrumentRightSelectFunc)(CPartInstrumentRight * pPartInstrumentRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartInstrumentRightIterator *pIterator, TPartInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientProductRightActionFunc)(CClientProductRight * pClientProductRight, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientProductRightUpdateFunc)(CWriteableClientProductRight * pClientProductRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientProductRightSelectFunc)(CClientProductRight * pClientProductRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CClientProductRightIterator *pIterator, TClientProductRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CClientProductRightIterator *pIterator, TClientProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CClientProductRightIterator *pIterator, TClientProductRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientInstrumentRightActionFunc)(CClientInstrumentRight * pClientInstrumentRight, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientInstrumentRightUpdateFunc)(CWriteableClientInstrumentRight * pClientInstrumentRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientInstrumentRightSelectFunc)(CClientInstrumentRight * pClientInstrumentRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CClientInstrumentRightIterator *pIterator, TClientInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientProductRightActionFunc)(CPartClientProductRight * pPartClientProductRight, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientProductRightUpdateFunc)(CWriteablePartClientProductRight * pPartClientProductRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientProductRightSelectFunc)(CPartClientProductRight * pPartClientProductRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartClientProductRightIterator *pIterator, TPartClientProductRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartClientProductRightIterator *pIterator, TPartClientProductRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartClientProductRightIterator *pIterator, TPartClientProductRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientInstrumentRightActionFunc)(CPartClientInstrumentRight * pPartClientInstrumentRight, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientInstrumentRightUpdateFunc)(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartClientInstrumentRightSelectFunc)(CPartClientInstrumentRight * pPartClientInstrumentRight,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartClientInstrumentRightIterator *pIterator, TPartClientInstrumentRightSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrProductPropertyActionFunc)(CCurrProductProperty * pCurrProductProperty, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrProductPropertyUpdateFunc)(CWriteableCurrProductProperty * pCurrProductProperty, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrProductPropertySelectFunc)(CCurrProductProperty * pCurrProductProperty,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrProductPropertyIterator *pIterator, TCurrProductPropertyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrProductPropertyIterator *pIterator, TCurrProductPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrProductPropertyIterator *pIterator, TCurrProductPropertySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrInstrumentPropertyActionFunc)(CCurrInstrumentProperty * pCurrInstrumentProperty, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrInstrumentPropertyUpdateFunc)(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrInstrumentPropertySelectFunc)(CCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertyActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertyUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrInstrumentPropertyIterator *pIterator, TCurrInstrumentPropertySelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPriceBandingActionFunc)(CCurrPriceBanding * pCurrPriceBanding, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPriceBandingUpdateFunc)(CWriteableCurrPriceBanding * pCurrPriceBanding, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPriceBandingSelectFunc)(CCurrPriceBanding * pCurrPriceBanding,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrPriceBandingIterator *pIterator, TCurrPriceBandingSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrMarginRateActionFunc)(CCurrMarginRate * pCurrMarginRate, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrMarginRateUpdateFunc)(CWriteableCurrMarginRate * pCurrMarginRate, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrMarginRateSelectFunc)(CCurrMarginRate * pCurrMarginRate,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrMarginRateIterator *pIterator, TCurrMarginRateActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrMarginRateIterator *pIterator, TCurrMarginRateUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrMarginRateIterator *pIterator, TCurrMarginRateSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrMarginRateDetailActionFunc)(CCurrMarginRateDetail * pCurrMarginRateDetail, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrMarginRateDetailUpdateFunc)(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrMarginRateDetailSelectFunc)(CCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrMarginRateDetailIterator *pIterator, TCurrMarginRateDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPartPosiLimitActionFunc)(CCurrPartPosiLimit * pCurrPartPosiLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPartPosiLimitUpdateFunc)(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPartPosiLimitSelectFunc)(CCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrPartPosiLimitIterator *pIterator, TCurrPartPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPartPosiLimitDetailActionFunc)(CCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPartPosiLimitDetailUpdateFunc)(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrPartPosiLimitDetailSelectFunc)(CCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrPartPosiLimitDetailIterator *pIterator, TCurrPartPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrClientPosiLimitActionFunc)(CCurrClientPosiLimit * pCurrClientPosiLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrClientPosiLimitUpdateFunc)(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrClientPosiLimitSelectFunc)(CCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrClientPosiLimitIterator *pIterator, TCurrClientPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrClientPosiLimitDetailActionFunc)(CCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrClientPosiLimitDetailUpdateFunc)(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrClientPosiLimitDetailSelectFunc)(CCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrClientPosiLimitDetailIterator *pIterator, TCurrClientPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrSpecialPosiLimitActionFunc)(CCurrSpecialPosiLimit * pCurrSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrSpecialPosiLimitUpdateFunc)(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrSpecialPosiLimitSelectFunc)(CCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrSpecialPosiLimitIterator *pIterator, TCurrSpecialPosiLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrSpecialPosiLimitDetailActionFunc)(CCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrSpecialPosiLimitDetailUpdateFunc)(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrSpecialPosiLimitDetailSelectFunc)(CCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrSpecialPosiLimitDetailIterator *pIterator, TCurrSpecialPosiLimitDetailSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrHedgeRuleActionFunc)(CCurrHedgeRule * pCurrHedgeRule, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrHedgeRuleUpdateFunc)(CWriteableCurrHedgeRule * pCurrHedgeRule, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrHedgeRuleSelectFunc)(CCurrHedgeRule * pCurrHedgeRule,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrHedgeRuleIterator *pIterator, TCurrHedgeRuleSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrTradingSegmentAttrActionFunc)(CCurrTradingSegmentAttr * pCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrTradingSegmentAttrUpdateFunc)(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrTradingSegmentAttrSelectFunc)(CCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrTradingSegmentAttrIterator *pIterator, TCurrTradingSegmentAttrSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrFuseActionFunc)(CCurrFuse * pCurrFuse, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrFuseUpdateFunc)(CWriteableCurrFuse * pCurrFuse, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrFuseSelectFunc)(CCurrFuse * pCurrFuse,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrFuseIterator *pIterator, TCurrFuseActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrFuseIterator *pIterator, TCurrFuseUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrFuseIterator *pIterator, TCurrFuseSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTradingAccountActionFunc)(CTradingAccount * pTradingAccount, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTradingAccountUpdateFunc)(CWriteableTradingAccount * pTradingAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTradingAccountSelectFunc)(CTradingAccount * pTradingAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CTradingAccountIterator *pIterator, TTradingAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CTradingAccountIterator *pIterator, TTradingAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CTradingAccountIterator *pIterator, TTradingAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBaseReserveAccountActionFunc)(CBaseReserveAccount * pBaseReserveAccount, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBaseReserveAccountUpdateFunc)(CWriteableBaseReserveAccount * pBaseReserveAccount, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBaseReserveAccountSelectFunc)(CBaseReserveAccount * pBaseReserveAccount,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CBaseReserveAccountIterator *pIterator, TBaseReserveAccountSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartPositionActionFunc)(CPartPosition * pPartPosition, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartPositionUpdateFunc)(CWriteablePartPosition * pPartPosition, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TPartPositionSelectFunc)(CPartPosition * pPartPosition,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CPartPositionIterator *pIterator, TPartPositionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CPartPositionIterator *pIterator, TPartPositionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CPartPositionIterator *pIterator, TPartPositionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientPositionActionFunc)(CClientPosition * pClientPosition, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientPositionUpdateFunc)(CWriteableClientPosition * pClientPosition, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClientPositionSelectFunc)(CClientPosition * pClientPosition,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CClientPositionIterator *pIterator, TClientPositionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CClientPositionIterator *pIterator, TClientPositionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CClientPositionIterator *pIterator, TClientPositionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* THedgeVolumeActionFunc)(CHedgeVolume * pHedgeVolume, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* THedgeVolumeUpdateFunc)(CWriteableHedgeVolume * pHedgeVolume, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* THedgeVolumeSelectFunc)(CHedgeVolume * pHedgeVolume,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CHedgeVolumeIterator *pIterator, THedgeVolumeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CHedgeVolumeIterator *pIterator, THedgeVolumeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CHedgeVolumeIterator *pIterator, THedgeVolumeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRemainOrderActionFunc)(CRemainOrder * pRemainOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRemainOrderUpdateFunc)(CWriteableRemainOrder * pRemainOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TRemainOrderSelectFunc)(CRemainOrder * pRemainOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CRemainOrderIterator *pIterator, TRemainOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CRemainOrderIterator *pIterator, TRemainOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CRemainOrderIterator *pIterator, TRemainOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataActionFunc)(CMarketData * pMarketData, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataUpdateFunc)(CWriteableMarketData * pMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMarketDataSelectFunc)(CMarketData * pMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMarketDataIterator *pIterator, TMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMarketDataIterator *pIterator, TMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMarketDataIterator *pIterator, TMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClearingPartPositionActionFunc)(CClearingPartPosition * pClearingPartPosition, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClearingPartPositionUpdateFunc)(CWriteableClearingPartPosition * pClearingPartPosition, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TClearingPartPositionSelectFunc)(CClearingPartPosition * pClearingPartPosition,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CClearingPartPositionIterator *pIterator, TClearingPartPositionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CClearingPartPositionIterator *pIterator, TClearingPartPositionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CClearingPartPositionIterator *pIterator, TClearingPartPositionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentStatusActionFunc)(CInstrumentStatus * pInstrumentStatus, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentStatusUpdateFunc)(CWriteableInstrumentStatus * pInstrumentStatus, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TInstrumentStatusSelectFunc)(CInstrumentStatus * pInstrumentStatus,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CInstrumentStatusIterator *pIterator, TInstrumentStatusActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CInstrumentStatusIterator *pIterator, TInstrumentStatusUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CInstrumentStatusIterator *pIterator, TInstrumentStatusSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOrderActionFunc)(COrder * pOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOrderUpdateFunc)(CWriteableOrder * pOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOrderSelectFunc)(COrder * pOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(COrderIterator *pIterator, TOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(COrderIterator *pIterator, TOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(COrderIterator *pIterator, TOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCombOrderActionFunc)(CCombOrder * pCombOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCombOrderUpdateFunc)(CWriteableCombOrder * pCombOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCombOrderSelectFunc)(CCombOrder * pCombOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCombOrderIterator *pIterator, TCombOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCombOrderIterator *pIterator, TCombOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCombOrderIterator *pIterator, TCombOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOTCOrderActionFunc)(COTCOrder * pOTCOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOTCOrderUpdateFunc)(CWriteableOTCOrder * pOTCOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TOTCOrderSelectFunc)(COTCOrder * pOTCOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(COTCOrderIterator *pIterator, TOTCOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(COTCOrderIterator *pIterator, TOTCOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(COTCOrderIterator *pIterator, TOTCOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TImplyOrderActionFunc)(CImplyOrder * pImplyOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TImplyOrderUpdateFunc)(CWriteableImplyOrder * pImplyOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TImplyOrderSelectFunc)(CImplyOrder * pImplyOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CImplyOrderIterator *pIterator, TImplyOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CImplyOrderIterator *pIterator, TImplyOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CImplyOrderIterator *pIterator, TImplyOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TQuoteActionFunc)(CQuote * pQuote, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TQuoteUpdateFunc)(CWriteableQuote * pQuote, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TQuoteSelectFunc)(CQuote * pQuote,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CQuoteIterator *pIterator, TQuoteActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CQuoteIterator *pIterator, TQuoteUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CQuoteIterator *pIterator, TQuoteSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMBLMarketDataActionFunc)(CMBLMarketData * pMBLMarketData, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMBLMarketDataUpdateFunc)(CWriteableMBLMarketData * pMBLMarketData, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TMBLMarketDataSelectFunc)(CMBLMarketData * pMBLMarketData,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CMBLMarketDataIterator *pIterator, TMBLMarketDataActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CMBLMarketDataIterator *pIterator, TMBLMarketDataUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CMBLMarketDataIterator *pIterator, TMBLMarketDataSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTradeActionFunc)(CTrade * pTrade, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTradeUpdateFunc)(CWriteableTrade * pTrade, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TTradeSelectFunc)(CTrade * pTrade,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CTradeIterator *pIterator, TTradeActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CTradeIterator *pIterator, TTradeUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CTradeIterator *pIterator, TTradeSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TFusePhaseActionFunc)(CFusePhase * pFusePhase, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TFusePhaseUpdateFunc)(CWriteableFusePhase * pFusePhase, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TFusePhaseSelectFunc)(CFusePhase * pFusePhase,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CFusePhaseIterator *pIterator, TFusePhaseActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CFusePhaseIterator *pIterator, TFusePhaseUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CFusePhaseIterator *pIterator, TFusePhaseSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExecOrderActionFunc)(CExecOrder * pExecOrder, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExecOrderUpdateFunc)(CWriteableExecOrder * pExecOrder, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TExecOrderSelectFunc)(CExecOrder * pExecOrder,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CExecOrderIterator *pIterator, TExecOrderActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CExecOrderIterator *pIterator, TExecOrderUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CExecOrderIterator *pIterator, TExecOrderSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUniPressureActionFunc)(CUniPressure * pUniPressure, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUniPressureUpdateFunc)(CWriteableUniPressure * pUniPressure, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TUniPressureSelectFunc)(CUniPressure * pUniPressure,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CUniPressureIterator *pIterator, TUniPressureActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CUniPressureIterator *pIterator, TUniPressureUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CUniPressureIterator *pIterator, TUniPressureSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBasePriceLimitActionFunc)(CBasePriceLimit * pBasePriceLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBasePriceLimitUpdateFunc)(CWriteableBasePriceLimit * pBasePriceLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TBasePriceLimitSelectFunc)(CBasePriceLimit * pBasePriceLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CBasePriceLimitIterator *pIterator, TBasePriceLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CBasePriceLimitIterator *pIterator, TBasePriceLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CBasePriceLimitIterator *pIterator, TBasePriceLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCreditLimitActionFunc)(CCreditLimit * pCreditLimit, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCreditLimitUpdateFunc)(CWriteableCreditLimit * pCreditLimit, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCreditLimitSelectFunc)(CCreditLimit * pCreditLimit,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCreditLimitIterator *pIterator, TCreditLimitActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCreditLimitIterator *pIterator, TCreditLimitUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCreditLimitIterator *pIterator, TCreditLimitSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);


///�����������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrInstrumentOptionActionFunc)(CCurrInstrumentOption * pCurrInstrumentOption, CTransaction * pTransaction,
	void * parameter);

///���º������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrInstrumentOptionUpdateFunc)(CWriteableCurrInstrumentOption * pCurrInstrumentOption, CTransaction * pTransaction,
	void * parameter, bool * pUpdateIndex);

///ѡ�������Ͷ��壬����1��ʾ��Ҫ����������0��ʾ��Ҫ��������
typedef int (* TCurrInstrumentOptionSelectFunc)(CCurrInstrumentOption * pCurrInstrumentOption,CTransaction * pTransaction, 
	void * parameter,int *pSelected);

///��һ��ö���������ж������ĳ�����
///@param	pIterator	���в�����ö����
///@param	actionFunc	ʵ�ʲ����ĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���actionFunc
void groupAction(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionActionFunc actionFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж�����и��²���
///@param	pIterator	���в�����ö����
///@param	updateFunc	ʵ�ʽ��и��µĺ���
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���updateFunc
void groupUpdate(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionUpdateFunc updateFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

///��һ��ö���������ж������ɾ������
///@param	pIterator	���в�����ö����
///@param	selectFunc	ʵ����Ҫɾ�����жϺ�����NULL��ʾ��Ҫȫ��ɾ��
///@param	pTransaction	�������ڵ�����NULL��ʾ��ʹ������
///@param	parameter	���ݵĲ�����������ÿ�ν���selectFunc
void groupDelete(CCurrInstrumentOptionIterator *pIterator, TCurrInstrumentOptionSelectFunc selectFunc,
	CTransaction *pTransaction=NULL, void *parameter=NULL);

#endif
