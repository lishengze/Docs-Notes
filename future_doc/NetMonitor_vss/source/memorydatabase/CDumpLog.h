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
///CExchangeDataSyncStatusDumpTrigger�ǲ�������������ͬ��״̬ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusDumpTrigger: public CExchangeDataSyncStatusActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CExchangeDataSyncStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CExchangeDataSyncStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pExchangeDataSyncStatus	Ҫ�����ExchangeDataSyncStatus
	virtual void beforeAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///����ǰ����	
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	�µ�ֵ
	virtual void beforeUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus);
	
	///ɾ��ǰ����
	///@param	pExchangeDataSyncStatus	Ҫɾ����CExchangeDataSyncStatus
	virtual void beforeRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusDumpTrigger�ǲ�������������ͬ��״̬ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusDumpTrigger: public CSGDataSyncStatusActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSGDataSyncStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSGDataSyncStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSGDataSyncStatus	Ҫ�����SGDataSyncStatus
	virtual void beforeAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus);
	
	///����ǰ����	
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	�µ�ֵ
	virtual void beforeUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus);
	
	///ɾ��ǰ����
	///@param	pSGDataSyncStatus	Ҫɾ����CSGDataSyncStatus
	virtual void beforeRemove(CSGDataSyncStatus *pSGDataSyncStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeDumpTrigger�ǲ�����ǰʱ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeDumpTrigger: public CCurrentTimeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrentTimeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrentTimeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrentTime	Ҫ�����CurrentTime
	virtual void beforeAdd(CWriteableCurrentTime *pCurrentTime);
	
	///����ǰ����	
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	///@param	pNewCurrentTime	�µ�ֵ
	virtual void beforeUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime);
	
	///ɾ��ǰ����
	///@param	pCurrentTime	Ҫɾ����CCurrentTime
	virtual void beforeRemove(CCurrentTime *pCurrentTime);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescDumpTrigger�ǲ���������������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescDumpTrigger: public CDataCenterDescActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CDataCenterDescDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CDataCenterDescDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pDataCenterDesc	Ҫ�����DataCenterDesc
	virtual void beforeAdd(CWriteableDataCenterDesc *pDataCenterDesc);
	
	///����ǰ����	
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	///@param	pNewDataCenterDesc	�µ�ֵ
	virtual void beforeUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc);
	
	///ɾ��ǰ����
	///@param	pDataCenterDesc	Ҫɾ����CDataCenterDesc
	virtual void beforeRemove(CDataCenterDesc *pDataCenterDesc);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDumpTrigger�ǲ���������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDumpTrigger: public CExchangeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CExchangeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CExchangeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pExchange	Ҫ�����Exchange
	virtual void beforeAdd(CWriteableExchange *pExchange);
	
	///����ǰ����	
	///@param	pExchange	��ˢ�µ�CExchange
	///@param	pNewExchange	�µ�ֵ
	virtual void beforeUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange);
	
	///ɾ��ǰ����
	///@param	pExchange	Ҫɾ����CExchange
	virtual void beforeRemove(CExchange *pExchange);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupDumpTrigger�ǲ���������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupDumpTrigger: public CSettlementGroupActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CSettlementGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CSettlementGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pSettlementGroup	Ҫ�����SettlementGroup
	virtual void beforeAdd(CWriteableSettlementGroup *pSettlementGroup);
	
	///����ǰ����	
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	///@param	pNewSettlementGroup	�µ�ֵ
	virtual void beforeUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup);
	
	///ɾ��ǰ����
	///@param	pSettlementGroup	Ҫɾ����CSettlementGroup
	virtual void beforeRemove(CSettlementGroup *pSettlementGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDumpTrigger�ǲ����г�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDumpTrigger: public CMarketActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMarketDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMarketDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMarket	Ҫ�����Market
	virtual void beforeAdd(CWriteableMarket *pMarket);
	
	///����ǰ����	
	///@param	pMarket	��ˢ�µ�CMarket
	///@param	pNewMarket	�µ�ֵ
	virtual void beforeUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket);
	
	///ɾ��ǰ����
	///@param	pMarket	Ҫɾ����CMarket
	virtual void beforeRemove(CMarket *pMarket);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductDumpTrigger�ǲ����г���Ʒ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductDumpTrigger: public CMarketProductActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMarketProductDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMarketProductDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMarketProduct	Ҫ�����MarketProduct
	virtual void beforeAdd(CWriteableMarketProduct *pMarketProduct);
	
	///����ǰ����	
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	///@param	pNewMarketProduct	�µ�ֵ
	virtual void beforeUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct);
	
	///ɾ��ǰ����
	///@param	pMarketProduct	Ҫɾ����CMarketProduct
	virtual void beforeRemove(CMarketProduct *pMarketProduct);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupDumpTrigger�ǲ����г���Ʒ�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupDumpTrigger: public CMarketProductGroupActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMarketProductGroupDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMarketProductGroupDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMarketProductGroup	Ҫ�����MarketProductGroup
	virtual void beforeAdd(CWriteableMarketProductGroup *pMarketProductGroup);
	
	///����ǰ����	
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	///@param	pNewMarketProductGroup	�µ�ֵ
	virtual void beforeUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup);
	
	///ɾ��ǰ����
	///@param	pMarketProductGroup	Ҫɾ����CMarketProductGroup
	virtual void beforeRemove(CMarketProductGroup *pMarketProductGroup);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusDumpTrigger�ǲ������鷢��״̬ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusDumpTrigger: public CMdPubStatusActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMdPubStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMdPubStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMdPubStatus	Ҫ�����MdPubStatus
	virtual void beforeAdd(CWriteableMdPubStatus *pMdPubStatus);
	
	///����ǰ����	
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	///@param	pNewMdPubStatus	�µ�ֵ
	virtual void beforeUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus);
	
	///ɾ��ǰ����
	///@param	pMdPubStatus	Ҫɾ����CMdPubStatus
	virtual void beforeRemove(CMdPubStatus *pMdPubStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicDumpTrigger�ǲ�����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicDumpTrigger: public CMarketDataTopicActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMarketDataTopicDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMarketDataTopicDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMarketDataTopic	Ҫ�����MarketDataTopic
	virtual void beforeAdd(CWriteableMarketDataTopic *pMarketDataTopic);
	
	///����ǰ����	
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	///@param	pNewMarketDataTopic	�µ�ֵ
	virtual void beforeUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic);
	
	///ɾ��ǰ����
	///@param	pMarketDataTopic	Ҫɾ����CMarketDataTopic
	virtual void beforeRemove(CMarketDataTopic *pMarketDataTopic);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeDumpTrigger�ǲ�����Ա�����г�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeDumpTrigger: public CPartTopicSubscribeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartTopicSubscribeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartTopicSubscribeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartTopicSubscribe	Ҫ�����PartTopicSubscribe
	virtual void beforeAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe);
	
	///����ǰ����	
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	�µ�ֵ
	virtual void beforeUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe);
	
	///ɾ��ǰ����
	///@param	pPartTopicSubscribe	Ҫɾ����CPartTopicSubscribe
	virtual void beforeRemove(CPartTopicSubscribe *pPartTopicSubscribe);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantDumpTrigger�ǲ�����Աʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantDumpTrigger: public CParticipantActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CParticipantDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CParticipantDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pParticipant	Ҫ�����Participant
	virtual void beforeAdd(CWriteableParticipant *pParticipant);
	
	///����ǰ����	
	///@param	pParticipant	��ˢ�µ�CParticipant
	///@param	pNewParticipant	�µ�ֵ
	virtual void beforeUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant);
	
	///ɾ��ǰ����
	///@param	pParticipant	Ҫɾ����CParticipant
	virtual void beforeRemove(CParticipant *pParticipant);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserDumpTrigger�ǲ����û�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserDumpTrigger: public CUserActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CUserDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CUserDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pUser	Ҫ�����User
	virtual void beforeAdd(CWriteableUser *pUser);
	
	///����ǰ����	
	///@param	pUser	��ˢ�µ�CUser
	///@param	pNewUser	�µ�ֵ
	virtual void beforeUpdate(CUser *pUser, CWriteableUser *pNewUser);
	
	///ɾ��ǰ����
	///@param	pUser	Ҫɾ����CUser
	virtual void beforeRemove(CUser *pUser);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientDumpTrigger�ǲ����ͻ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientDumpTrigger: public CClientActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CClientDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CClientDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pClient	Ҫ�����Client
	virtual void beforeAdd(CWriteableClient *pClient);
	
	///����ǰ����	
	///@param	pClient	��ˢ�µ�CClient
	///@param	pNewClient	�µ�ֵ
	virtual void beforeUpdate(CClient *pClient, CWriteableClient *pNewClient);
	
	///ɾ��ǰ����
	///@param	pClient	Ҫɾ����CClient
	virtual void beforeRemove(CClient *pClient);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPDumpTrigger�ǲ�������ԱIP��ַʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPDumpTrigger: public CUserIPActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CUserIPDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CUserIPDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pUserIP	Ҫ�����UserIP
	virtual void beforeAdd(CWriteableUserIP *pUserIP);
	
	///����ǰ����	
	///@param	pUserIP	��ˢ�µ�CUserIP
	///@param	pNewUserIP	�µ�ֵ
	virtual void beforeUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP);
	
	///ɾ��ǰ����
	///@param	pUserIP	Ҫɾ����CUserIP
	virtual void beforeRemove(CUserIP *pUserIP);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientDumpTrigger�ǲ�����Ա�ͻ���ϵʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientDumpTrigger: public CPartClientActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartClientDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartClientDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartClient	Ҫ�����PartClient
	virtual void beforeAdd(CWriteablePartClient *pPartClient);
	
	///����ǰ����	
	///@param	pPartClient	��ˢ�µ�CPartClient
	///@param	pNewPartClient	�µ�ֵ
	virtual void beforeUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient);
	
	///ɾ��ǰ����
	///@param	pPartClient	Ҫɾ����CPartClient
	virtual void beforeRemove(CPartClient *pPartClient);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartDumpTrigger�ǲ������㽻�׻�Ա��ϵʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartDumpTrigger: public CClearingTradingPartActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CClearingTradingPartDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CClearingTradingPartDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pClearingTradingPart	Ҫ�����ClearingTradingPart
	virtual void beforeAdd(CWriteableClearingTradingPart *pClearingTradingPart);
	
	///����ǰ����	
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	///@param	pNewClearingTradingPart	�µ�ֵ
	virtual void beforeUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart);
	
	///ɾ��ǰ����
	///@param	pClearingTradingPart	Ҫɾ����CClearingTradingPart
	virtual void beforeRemove(CClearingTradingPart *pClearingTradingPart);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineDumpTrigger�ǲ�����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineDumpTrigger: public CAliasDefineActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CAliasDefineDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CAliasDefineDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pAliasDefine	Ҫ�����AliasDefine
	virtual void beforeAdd(CWriteableAliasDefine *pAliasDefine);
	
	///����ǰ����	
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	///@param	pNewAliasDefine	�µ�ֵ
	virtual void beforeUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine);
	
	///ɾ��ǰ����
	///@param	pAliasDefine	Ҫɾ����CAliasDefine
	virtual void beforeRemove(CAliasDefine *pAliasDefine);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightDumpTrigger�ǲ����û�����Ȩ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightDumpTrigger: public CUserFunctionRightActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CUserFunctionRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CUserFunctionRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pUserFunctionRight	Ҫ�����UserFunctionRight
	virtual void beforeAdd(CWriteableUserFunctionRight *pUserFunctionRight);
	
	///����ǰ����	
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	///@param	pNewUserFunctionRight	�µ�ֵ
	virtual void beforeUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight);
	
	///ɾ��ǰ����
	///@param	pUserFunctionRight	Ҫɾ����CUserFunctionRight
	virtual void beforeRemove(CUserFunctionRight *pUserFunctionRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CAccountDumpTrigger�ǲ����ʽ��˻�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountDumpTrigger: public CAccountActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pAccount	Ҫ�����Account
	virtual void beforeAdd(CWriteableAccount *pAccount);
	
	///����ǰ����	
	///@param	pAccount	��ˢ�µ�CAccount
	///@param	pNewAccount	�µ�ֵ
	virtual void beforeUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount);
	
	///ɾ��ǰ����
	///@param	pAccount	Ҫɾ����CAccount
	virtual void beforeRemove(CAccount *pAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxDumpTrigger�ǲ����û�ͨѶ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxDumpTrigger: public CUserCommFluxActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CUserCommFluxDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CUserCommFluxDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pUserCommFlux	Ҫ�����UserCommFlux
	virtual void beforeAdd(CWriteableUserCommFlux *pUserCommFlux);
	
	///����ǰ����	
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	///@param	pNewUserCommFlux	�µ�ֵ
	virtual void beforeUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux);
	
	///ɾ��ǰ����
	///@param	pUserCommFlux	Ҫɾ����CUserCommFlux
	virtual void beforeRemove(CUserCommFlux *pUserCommFlux);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogDumpTrigger�ǲ���������ˮʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogDumpTrigger: public CMarketDataLogActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMarketDataLogDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMarketDataLogDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMarketDataLog	Ҫ�����MarketDataLog
	virtual void beforeAdd(CWriteableMarketDataLog *pMarketDataLog);
	
	///����ǰ����	
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	///@param	pNewMarketDataLog	�µ�ֵ
	virtual void beforeUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog);
	
	///ɾ��ǰ����
	///@param	pMarketDataLog	Ҫɾ����CMarketDataLog
	virtual void beforeRemove(CMarketDataLog *pMarketDataLog);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionDumpTrigger�ǲ�������Ա���߻Ựʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionDumpTrigger: public CUserSessionActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CUserSessionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CUserSessionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pUserSession	Ҫ�����UserSession
	virtual void beforeAdd(CWriteableUserSession *pUserSession);
	
	///����ǰ����	
	///@param	pUserSession	��ˢ�µ�CUserSession
	///@param	pNewUserSession	�µ�ֵ
	virtual void beforeUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession);
	
	///ɾ��ǰ����
	///@param	pUserSession	Ҫɾ����CUserSession
	virtual void beforeRemove(CUserSession *pUserSession);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionDumpTrigger�ǲ������鶩�������߻Ựʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionDumpTrigger: public CMDSessionActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMDSessionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMDSessionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMDSession	Ҫ�����MDSession
	virtual void beforeAdd(CWriteableMDSession *pMDSession);
	
	///����ǰ����	
	///@param	pMDSession	��ˢ�µ�CMDSession
	///@param	pNewMDSession	�µ�ֵ
	virtual void beforeUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession);
	
	///ɾ��ǰ����
	///@param	pMDSession	Ҫɾ����CMDSession
	virtual void beforeRemove(CMDSession *pMDSession);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoDumpTrigger�ǲ����û���½�ǳ���Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoDumpTrigger: public CLoginInfoActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CLoginInfoDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CLoginInfoDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pLoginInfo	Ҫ�����LoginInfo
	virtual void beforeAdd(CWriteableLoginInfo *pLoginInfo);
	
	///����ǰ����	
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	///@param	pNewLoginInfo	�µ�ֵ
	virtual void beforeUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo);
	
	///ɾ��ǰ����
	///@param	pLoginInfo	Ҫɾ����CLoginInfo
	virtual void beforeRemove(CLoginInfo *pLoginInfo);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailDumpTrigger�ǲ�������г�������ϸʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailDumpTrigger: public CDepthMarketDataDetailActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CDepthMarketDataDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CDepthMarketDataDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pDepthMarketDataDetail	Ҫ�����DepthMarketDataDetail
	virtual void beforeAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///����ǰ����	
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	�µ�ֵ
	virtual void beforeUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail);
	
	///ɾ��ǰ����
	///@param	pDepthMarketDataDetail	Ҫɾ����CDepthMarketDataDetail
	virtual void beforeRemove(CDepthMarketDataDetail *pDepthMarketDataDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailDumpTrigger�ǲ�����Լ����״̬��ˮʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailDumpTrigger: public CInstrumentStatusDetailActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CInstrumentStatusDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CInstrumentStatusDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pInstrumentStatusDetail	Ҫ�����InstrumentStatusDetail
	virtual void beforeAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///����ǰ����	
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	�µ�ֵ
	virtual void beforeUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail);
	
	///ɾ��ǰ����
	///@param	pInstrumentStatusDetail	Ҫɾ����CInstrumentStatusDetail
	virtual void beforeRemove(CInstrumentStatusDetail *pInstrumentStatusDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusDumpTrigger�ǲ���ǰ��״̬ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusDumpTrigger: public CFrontStatusActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CFrontStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CFrontStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pFrontStatus	Ҫ�����FrontStatus
	virtual void beforeAdd(CWriteableFrontStatus *pFrontStatus);
	
	///����ǰ����	
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	///@param	pNewFrontStatus	�µ�ֵ
	virtual void beforeUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus);
	
	///ɾ��ǰ����
	///@param	pFrontStatus	Ҫɾ����CFrontStatus
	virtual void beforeRemove(CFrontStatus *pFrontStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDDumpTrigger�ǲ�����󱾵ر�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDDumpTrigger: public CMaxLocalIDActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMaxLocalIDDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMaxLocalIDDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMaxLocalID	Ҫ�����MaxLocalID
	virtual void beforeAdd(CWriteableMaxLocalID *pMaxLocalID);
	
	///����ǰ����	
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	///@param	pNewMaxLocalID	�µ�ֵ
	virtual void beforeUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID);
	
	///ɾ��ǰ����
	///@param	pMaxLocalID	Ҫɾ����CMaxLocalID
	virtual void beforeRemove(CMaxLocalID *pMaxLocalID);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinDumpTrigger�ǲ���������Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinDumpTrigger: public CBulletinActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CBulletinDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CBulletinDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pBulletin	Ҫ�����Bulletin
	virtual void beforeAdd(CWriteableBulletin *pBulletin);
	
	///����ǰ����	
	///@param	pBulletin	��ˢ�µ�CBulletin
	///@param	pNewBulletin	�µ�ֵ
	virtual void beforeUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin);
	
	///ɾ��ǰ����
	///@param	pBulletin	Ҫɾ����CBulletin
	virtual void beforeRemove(CBulletin *pBulletin);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyDumpTrigger�ǲ�������䶯ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyDumpTrigger: public CMarketDataModifyActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMarketDataModifyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMarketDataModifyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMarketDataModify	Ҫ�����MarketDataModify
	virtual void beforeAdd(CWriteableMarketDataModify *pMarketDataModify);
	
	///����ǰ����	
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	///@param	pNewMarketDataModify	�µ�ֵ
	virtual void beforeUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify);
	
	///ɾ��ǰ����
	///@param	pMarketDataModify	Ҫɾ����CMarketDataModify
	virtual void beforeRemove(CMarketDataModify *pMarketDataModify);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDumpTrigger�ǲ����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDumpTrigger: public CDepthMarketDataActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CDepthMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CDepthMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pDepthMarketData	Ҫ�����DepthMarketData
	virtual void beforeAdd(CWriteableDepthMarketData *pDepthMarketData);
	
	///����ǰ����	
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	///@param	pNewDepthMarketData	�µ�ֵ
	virtual void beforeUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData);
	
	///ɾ��ǰ����
	///@param	pDepthMarketData	Ҫɾ����CDepthMarketData
	virtual void beforeRemove(CDepthMarketData *pDepthMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataDumpTrigger�ǲ�������������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataDumpTrigger: public CTopicMarketDataActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CTopicMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CTopicMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pTopicMarketData	Ҫ�����TopicMarketData
	virtual void beforeAdd(CWriteableTopicMarketData *pTopicMarketData);
	
	///����ǰ����	
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	///@param	pNewTopicMarketData	�µ�ֵ
	virtual void beforeUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData);
	
	///ɾ��ǰ����
	///@param	pTopicMarketData	Ҫɾ����CTopicMarketData
	virtual void beforeRemove(CTopicMarketData *pTopicMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionDumpTrigger�ǲ����������������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionDumpTrigger: public CTopicMarketDataVersionActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CTopicMarketDataVersionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CTopicMarketDataVersionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pTopicMarketDataVersion	Ҫ�����TopicMarketDataVersion
	virtual void beforeAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///����ǰ����	
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	�µ�ֵ
	virtual void beforeUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion);
	
	///ɾ��ǰ����
	///@param	pTopicMarketDataVersion	Ҫɾ����CTopicMarketDataVersion
	virtual void beforeRemove(CTopicMarketDataVersion *pTopicMarketDataVersion);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInformationDumpTrigger�ǲ�����Ϣʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationDumpTrigger: public CInformationActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CInformationDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CInformationDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pInformation	Ҫ�����Information
	virtual void beforeAdd(CWriteableInformation *pInformation);
	
	///����ǰ����	
	///@param	pInformation	��ˢ�µ�CInformation
	///@param	pNewInformation	�µ�ֵ
	virtual void beforeUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation);
	
	///ɾ��ǰ����
	///@param	pInformation	Ҫɾ����CInformation
	virtual void beforeRemove(CInformation *pInformation);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountDumpTrigger�ǲ�����������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountDumpTrigger: public COrderCountActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	COrderCountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~COrderCountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pOrderCount	Ҫ�����OrderCount
	virtual void beforeAdd(CWriteableOrderCount *pOrderCount);
	
	///����ǰ����	
	///@param	pOrderCount	��ˢ�µ�COrderCount
	///@param	pNewOrderCount	�µ�ֵ
	virtual void beforeUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount);
	
	///ɾ��ǰ����
	///@param	pOrderCount	Ҫɾ����COrderCount
	virtual void beforeRemove(COrderCount *pOrderCount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentDumpTrigger�ǲ�����Լʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentDumpTrigger: public CInstrumentActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CInstrumentDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CInstrumentDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pInstrument	Ҫ�����Instrument
	virtual void beforeAdd(CWriteableInstrument *pInstrument);
	
	///����ǰ����	
	///@param	pInstrument	��ˢ�µ�CInstrument
	///@param	pNewInstrument	�µ�ֵ
	virtual void beforeUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument);
	
	///ɾ��ǰ����
	///@param	pInstrument	Ҫɾ����CInstrument
	virtual void beforeRemove(CInstrument *pInstrument);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegDumpTrigger�ǲ�����Ϻ�Լ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegDumpTrigger: public CCombinationLegActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCombinationLegDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCombinationLegDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCombinationLeg	Ҫ�����CombinationLeg
	virtual void beforeAdd(CWriteableCombinationLeg *pCombinationLeg);
	
	///����ǰ����	
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	///@param	pNewCombinationLeg	�µ�ֵ
	virtual void beforeUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg);
	
	///ɾ��ǰ����
	///@param	pCombinationLeg	Ҫɾ����CCombinationLeg
	virtual void beforeRemove(CCombinationLeg *pCombinationLeg);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountDumpTrigger�ǲ�����Ա�˻���ϵʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountDumpTrigger: public CPartRoleAccountActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartRoleAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartRoleAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartRoleAccount	Ҫ�����PartRoleAccount
	virtual void beforeAdd(CWriteablePartRoleAccount *pPartRoleAccount);
	
	///����ǰ����	
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	///@param	pNewPartRoleAccount	�µ�ֵ
	virtual void beforeUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount);
	
	///ɾ��ǰ����
	///@param	pPartRoleAccount	Ҫɾ����CPartRoleAccount
	virtual void beforeRemove(CPartRoleAccount *pPartRoleAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleDumpTrigger�ǲ�����Ա��Ʒ��ɫʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleDumpTrigger: public CPartProductRoleActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartProductRoleDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartProductRoleDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartProductRole	Ҫ�����PartProductRole
	virtual void beforeAdd(CWriteablePartProductRole *pPartProductRole);
	
	///����ǰ����	
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	///@param	pNewPartProductRole	�µ�ֵ
	virtual void beforeUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole);
	
	///ɾ��ǰ����
	///@param	pPartProductRole	Ҫɾ����CPartProductRole
	virtual void beforeRemove(CPartProductRole *pPartProductRole);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightDumpTrigger�ǲ�����Ա��Ʒ����Ȩ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightDumpTrigger: public CPartProductRightActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartProductRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartProductRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartProductRight	Ҫ�����PartProductRight
	virtual void beforeAdd(CWriteablePartProductRight *pPartProductRight);
	
	///����ǰ����	
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	///@param	pNewPartProductRight	�µ�ֵ
	virtual void beforeUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight);
	
	///ɾ��ǰ����
	///@param	pPartProductRight	Ҫɾ����CPartProductRight
	virtual void beforeRemove(CPartProductRight *pPartProductRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightDumpTrigger�ǲ�����Ա��Լ����Ȩ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightDumpTrigger: public CPartInstrumentRightActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartInstrumentRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartInstrumentRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartInstrumentRight	Ҫ�����PartInstrumentRight
	virtual void beforeAdd(CWriteablePartInstrumentRight *pPartInstrumentRight);
	
	///����ǰ����	
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	///@param	pNewPartInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight);
	
	///ɾ��ǰ����
	///@param	pPartInstrumentRight	Ҫɾ����CPartInstrumentRight
	virtual void beforeRemove(CPartInstrumentRight *pPartInstrumentRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightDumpTrigger�ǲ����ͻ���Ʒ����Ȩ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightDumpTrigger: public CClientProductRightActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CClientProductRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CClientProductRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pClientProductRight	Ҫ�����ClientProductRight
	virtual void beforeAdd(CWriteableClientProductRight *pClientProductRight);
	
	///����ǰ����	
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	///@param	pNewClientProductRight	�µ�ֵ
	virtual void beforeUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight);
	
	///ɾ��ǰ����
	///@param	pClientProductRight	Ҫɾ����CClientProductRight
	virtual void beforeRemove(CClientProductRight *pClientProductRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightDumpTrigger�ǲ����ͻ���Լ����Ȩ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightDumpTrigger: public CClientInstrumentRightActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CClientInstrumentRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CClientInstrumentRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pClientInstrumentRight	Ҫ�����ClientInstrumentRight
	virtual void beforeAdd(CWriteableClientInstrumentRight *pClientInstrumentRight);
	
	///����ǰ����	
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	///@param	pNewClientInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight);
	
	///ɾ��ǰ����
	///@param	pClientInstrumentRight	Ҫɾ����CClientInstrumentRight
	virtual void beforeRemove(CClientInstrumentRight *pClientInstrumentRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightDumpTrigger�ǲ�����Ա�ͻ���Ʒ����Ȩ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightDumpTrigger: public CPartClientProductRightActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartClientProductRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartClientProductRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartClientProductRight	Ҫ�����PartClientProductRight
	virtual void beforeAdd(CWriteablePartClientProductRight *pPartClientProductRight);
	
	///����ǰ����	
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	///@param	pNewPartClientProductRight	�µ�ֵ
	virtual void beforeUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight);
	
	///ɾ��ǰ����
	///@param	pPartClientProductRight	Ҫɾ����CPartClientProductRight
	virtual void beforeRemove(CPartClientProductRight *pPartClientProductRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightDumpTrigger�ǲ�����Ա�ͻ���Լ����Ȩ��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightDumpTrigger: public CPartClientInstrumentRightActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartClientInstrumentRightDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartClientInstrumentRightDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartClientInstrumentRight	Ҫ�����PartClientInstrumentRight
	virtual void beforeAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);
	
	///����ǰ����	
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight);
	
	///ɾ��ǰ����
	///@param	pPartClientInstrumentRight	Ҫɾ����CPartClientInstrumentRight
	virtual void beforeRemove(CPartClientInstrumentRight *pPartClientInstrumentRight);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyDumpTrigger�ǲ�����Ʒ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyDumpTrigger: public CCurrProductPropertyActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrProductPropertyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrProductPropertyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrProductProperty	Ҫ�����CurrProductProperty
	virtual void beforeAdd(CWriteableCurrProductProperty *pCurrProductProperty);
	
	///����ǰ����	
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	///@param	pNewCurrProductProperty	�µ�ֵ
	virtual void beforeUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty);
	
	///ɾ��ǰ����
	///@param	pCurrProductProperty	Ҫɾ����CCurrProductProperty
	virtual void beforeRemove(CCurrProductProperty *pCurrProductProperty);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyDumpTrigger�ǲ�����Լ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyDumpTrigger: public CCurrInstrumentPropertyActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrInstrumentPropertyDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrInstrumentPropertyDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrInstrumentProperty	Ҫ�����CurrInstrumentProperty
	virtual void beforeAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///����ǰ����	
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	�µ�ֵ
	virtual void beforeUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty);
	
	///ɾ��ǰ����
	///@param	pCurrInstrumentProperty	Ҫɾ����CCurrInstrumentProperty
	virtual void beforeRemove(CCurrInstrumentProperty *pCurrInstrumentProperty);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingDumpTrigger�ǲ�����ǰ�۸��ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingDumpTrigger: public CCurrPriceBandingActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrPriceBandingDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrPriceBandingDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrPriceBanding	Ҫ�����CurrPriceBanding
	virtual void beforeAdd(CWriteableCurrPriceBanding *pCurrPriceBanding);
	
	///����ǰ����	
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	///@param	pNewCurrPriceBanding	�µ�ֵ
	virtual void beforeUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding);
	
	///ɾ��ǰ����
	///@param	pCurrPriceBanding	Ҫɾ����CCurrPriceBanding
	virtual void beforeRemove(CCurrPriceBanding *pCurrPriceBanding);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDumpTrigger�ǲ��������Լ��֤����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDumpTrigger: public CCurrMarginRateActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrMarginRateDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrMarginRateDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrMarginRate	Ҫ�����CurrMarginRate
	virtual void beforeAdd(CWriteableCurrMarginRate *pCurrMarginRate);
	
	///����ǰ����	
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	///@param	pNewCurrMarginRate	�µ�ֵ
	virtual void beforeUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate);
	
	///ɾ��ǰ����
	///@param	pCurrMarginRate	Ҫɾ����CCurrMarginRate
	virtual void beforeRemove(CCurrMarginRate *pCurrMarginRate);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailDumpTrigger�ǲ��������Լ��֤���ʵ���ϸ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailDumpTrigger: public CCurrMarginRateDetailActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrMarginRateDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrMarginRateDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrMarginRateDetail	Ҫ�����CurrMarginRateDetail
	virtual void beforeAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///����ǰ����	
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail);
	
	///ɾ��ǰ����
	///@param	pCurrMarginRateDetail	Ҫɾ����CCurrMarginRateDetail
	virtual void beforeRemove(CCurrMarginRateDetail *pCurrMarginRateDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDumpTrigger�ǲ�����ǰ��Ա��Լ�޲�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDumpTrigger: public CCurrPartPosiLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrPartPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrPartPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrPartPosiLimit	Ҫ�����CurrPartPosiLimit
	virtual void beforeAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///����ǰ����	
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit);
	
	///ɾ��ǰ����
	///@param	pCurrPartPosiLimit	Ҫɾ����CCurrPartPosiLimit
	virtual void beforeRemove(CCurrPartPosiLimit *pCurrPartPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailDumpTrigger�ǲ�����ǰ��Ա��Լ�޲ֵ���ϸ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailDumpTrigger: public CCurrPartPosiLimitDetailActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrPartPosiLimitDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrPartPosiLimitDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrPartPosiLimitDetail	Ҫ�����CurrPartPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///����ǰ����	
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail);
	
	///ɾ��ǰ����
	///@param	pCurrPartPosiLimitDetail	Ҫɾ����CCurrPartPosiLimitDetail
	virtual void beforeRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDumpTrigger�ǲ�����ǰ�ͻ���Լ�޲�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDumpTrigger: public CCurrClientPosiLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrClientPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrClientPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrClientPosiLimit	Ҫ�����CurrClientPosiLimit
	virtual void beforeAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///����ǰ����	
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit);
	
	///ɾ��ǰ����
	///@param	pCurrClientPosiLimit	Ҫɾ����CCurrClientPosiLimit
	virtual void beforeRemove(CCurrClientPosiLimit *pCurrClientPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailDumpTrigger�ǲ�����ǰ�ͻ���Լ�޲ֵ���ϸ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailDumpTrigger: public CCurrClientPosiLimitDetailActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrClientPosiLimitDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrClientPosiLimitDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrClientPosiLimitDetail	Ҫ�����CurrClientPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///����ǰ����	
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail);
	
	///ɾ��ǰ����
	///@param	pCurrClientPosiLimitDetail	Ҫɾ����CCurrClientPosiLimitDetail
	virtual void beforeRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDumpTrigger�ǲ�����ǰ����ͻ���Լ�޲�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDumpTrigger: public CCurrSpecialPosiLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrSpecialPosiLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrSpecialPosiLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrSpecialPosiLimit	Ҫ�����CurrSpecialPosiLimit
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///����ǰ����	
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit);
	
	///ɾ��ǰ����
	///@param	pCurrSpecialPosiLimit	Ҫɾ����CCurrSpecialPosiLimit
	virtual void beforeRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailDumpTrigger�ǲ�����ǰ����ͻ���Լ�޲ֵ���ϸ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailDumpTrigger: public CCurrSpecialPosiLimitDetailActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrSpecialPosiLimitDetailDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrSpecialPosiLimitDetailDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrSpecialPosiLimitDetail	Ҫ�����CurrSpecialPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///����ǰ����	
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail);
	
	///ɾ��ǰ����
	///@param	pCurrSpecialPosiLimitDetail	Ҫɾ����CCurrSpecialPosiLimitDetail
	virtual void beforeRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleDumpTrigger�ǲ�����ǰ��Լ���ڱ�ֵ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleDumpTrigger: public CCurrHedgeRuleActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrHedgeRuleDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrHedgeRuleDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrHedgeRule	Ҫ�����CurrHedgeRule
	virtual void beforeAdd(CWriteableCurrHedgeRule *pCurrHedgeRule);
	
	///����ǰ����	
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	///@param	pNewCurrHedgeRule	�µ�ֵ
	virtual void beforeUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule);
	
	///ɾ��ǰ����
	///@param	pCurrHedgeRule	Ҫɾ����CCurrHedgeRule
	virtual void beforeRemove(CCurrHedgeRule *pCurrHedgeRule);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrDumpTrigger�ǲ�����ǰ��Լ���׽׶�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrDumpTrigger: public CCurrTradingSegmentAttrActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrTradingSegmentAttrDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrTradingSegmentAttrDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrTradingSegmentAttr	Ҫ�����CurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///����ǰ����	
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	�µ�ֵ
	virtual void beforeUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr);
	
	///ɾ��ǰ����
	///@param	pCurrTradingSegmentAttr	Ҫɾ����CCurrTradingSegmentAttr
	virtual void beforeRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseDumpTrigger�ǲ�����ǰ��Լ�۶�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseDumpTrigger: public CCurrFuseActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrFuseDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrFuseDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrFuse	Ҫ�����CurrFuse
	virtual void beforeAdd(CWriteableCurrFuse *pCurrFuse);
	
	///����ǰ����	
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	///@param	pNewCurrFuse	�µ�ֵ
	virtual void beforeUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse);
	
	///ɾ��ǰ����
	///@param	pCurrFuse	Ҫɾ����CCurrFuse
	virtual void beforeRemove(CCurrFuse *pCurrFuse);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountDumpTrigger�ǲ��������˻�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountDumpTrigger: public CTradingAccountActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CTradingAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CTradingAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pTradingAccount	Ҫ�����TradingAccount
	virtual void beforeAdd(CWriteableTradingAccount *pTradingAccount);
	
	///����ǰ����	
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	///@param	pNewTradingAccount	�µ�ֵ
	virtual void beforeUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount);
	
	///ɾ��ǰ����
	///@param	pTradingAccount	Ҫɾ����CTradingAccount
	virtual void beforeRemove(CTradingAccount *pTradingAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountDumpTrigger�ǲ�������׼�����˻�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountDumpTrigger: public CBaseReserveAccountActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CBaseReserveAccountDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CBaseReserveAccountDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pBaseReserveAccount	Ҫ�����BaseReserveAccount
	virtual void beforeAdd(CWriteableBaseReserveAccount *pBaseReserveAccount);
	
	///����ǰ����	
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	///@param	pNewBaseReserveAccount	�µ�ֵ
	virtual void beforeUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount);
	
	///ɾ��ǰ����
	///@param	pBaseReserveAccount	Ҫɾ����CBaseReserveAccount
	virtual void beforeRemove(CBaseReserveAccount *pBaseReserveAccount);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionDumpTrigger�ǲ�����Ա�ֲ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionDumpTrigger: public CPartPositionActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CPartPositionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CPartPositionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pPartPosition	Ҫ�����PartPosition
	virtual void beforeAdd(CWriteablePartPosition *pPartPosition);
	
	///����ǰ����	
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	///@param	pNewPartPosition	�µ�ֵ
	virtual void beforeUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition);
	
	///ɾ��ǰ����
	///@param	pPartPosition	Ҫɾ����CPartPosition
	virtual void beforeRemove(CPartPosition *pPartPosition);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionDumpTrigger�ǲ����ͻ��ֲ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionDumpTrigger: public CClientPositionActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CClientPositionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CClientPositionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pClientPosition	Ҫ�����ClientPosition
	virtual void beforeAdd(CWriteableClientPosition *pClientPosition);
	
	///����ǰ����	
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	///@param	pNewClientPosition	�µ�ֵ
	virtual void beforeUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition);
	
	///ɾ��ǰ����
	///@param	pClientPosition	Ҫɾ����CClientPosition
	virtual void beforeRemove(CClientPosition *pClientPosition);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeDumpTrigger�ǲ�����ֵ�����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeDumpTrigger: public CHedgeVolumeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CHedgeVolumeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CHedgeVolumeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pHedgeVolume	Ҫ�����HedgeVolume
	virtual void beforeAdd(CWriteableHedgeVolume *pHedgeVolume);
	
	///����ǰ����	
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	///@param	pNewHedgeVolume	�µ�ֵ
	virtual void beforeUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume);
	
	///ɾ��ǰ����
	///@param	pHedgeVolume	Ҫɾ����CHedgeVolume
	virtual void beforeRemove(CHedgeVolume *pHedgeVolume);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderDumpTrigger�ǲ�����ʷ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderDumpTrigger: public CRemainOrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CRemainOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CRemainOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pRemainOrder	Ҫ�����RemainOrder
	virtual void beforeAdd(CWriteableRemainOrder *pRemainOrder);
	
	///����ǰ����	
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	///@param	pNewRemainOrder	�µ�ֵ
	virtual void beforeUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder);
	
	///ɾ��ǰ����
	///@param	pRemainOrder	Ҫɾ����CRemainOrder
	virtual void beforeRemove(CRemainOrder *pRemainOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataDumpTrigger�ǲ�������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataDumpTrigger: public CMarketDataActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMarketData	Ҫ�����MarketData
	virtual void beforeAdd(CWriteableMarketData *pMarketData);
	
	///����ǰ����	
	///@param	pMarketData	��ˢ�µ�CMarketData
	///@param	pNewMarketData	�µ�ֵ
	virtual void beforeUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData);
	
	///ɾ��ǰ����
	///@param	pMarketData	Ҫɾ����CMarketData
	virtual void beforeRemove(CMarketData *pMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionDumpTrigger�ǲ��������Ա�ֲ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionDumpTrigger: public CClearingPartPositionActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CClearingPartPositionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CClearingPartPositionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pClearingPartPosition	Ҫ�����ClearingPartPosition
	virtual void beforeAdd(CWriteableClearingPartPosition *pClearingPartPosition);
	
	///����ǰ����	
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	///@param	pNewClearingPartPosition	�µ�ֵ
	virtual void beforeUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition);
	
	///ɾ��ǰ����
	///@param	pClearingPartPosition	Ҫɾ����CClearingPartPosition
	virtual void beforeRemove(CClearingPartPosition *pClearingPartPosition);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDumpTrigger�ǲ�����Լ״̬ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDumpTrigger: public CInstrumentStatusActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CInstrumentStatusDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CInstrumentStatusDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pInstrumentStatus	Ҫ�����InstrumentStatus
	virtual void beforeAdd(CWriteableInstrumentStatus *pInstrumentStatus);
	
	///����ǰ����	
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	///@param	pNewInstrumentStatus	�µ�ֵ
	virtual void beforeUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus);
	
	///ɾ��ǰ����
	///@param	pInstrumentStatus	Ҫɾ����CInstrumentStatus
	virtual void beforeRemove(CInstrumentStatus *pInstrumentStatus);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///COrderDumpTrigger�ǲ�������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderDumpTrigger: public COrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	COrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~COrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pOrder	Ҫ�����Order
	virtual void beforeAdd(CWriteableOrder *pOrder);
	
	///����ǰ����	
	///@param	pOrder	��ˢ�µ�COrder
	///@param	pNewOrder	�µ�ֵ
	virtual void beforeUpdate(COrder *pOrder, CWriteableOrder *pNewOrder);
	
	///ɾ��ǰ����
	///@param	pOrder	Ҫɾ����COrder
	virtual void beforeRemove(COrder *pOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderDumpTrigger�ǲ�����ϱ���ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderDumpTrigger: public CCombOrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCombOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCombOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCombOrder	Ҫ�����CombOrder
	virtual void beforeAdd(CWriteableCombOrder *pCombOrder);
	
	///����ǰ����	
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	///@param	pNewCombOrder	�µ�ֵ
	virtual void beforeUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder);
	
	///ɾ��ǰ����
	///@param	pCombOrder	Ҫɾ����CCombOrder
	virtual void beforeRemove(CCombOrder *pCombOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderDumpTrigger�ǲ���OTC����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderDumpTrigger: public COTCOrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	COTCOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~COTCOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pOTCOrder	Ҫ�����OTCOrder
	virtual void beforeAdd(CWriteableOTCOrder *pOTCOrder);
	
	///����ǰ����	
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	///@param	pNewOTCOrder	�µ�ֵ
	virtual void beforeUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder);
	
	///ɾ��ǰ����
	///@param	pOTCOrder	Ҫɾ����COTCOrder
	virtual void beforeRemove(COTCOrder *pOTCOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderDumpTrigger�ǲ�����ʽ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderDumpTrigger: public CImplyOrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CImplyOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CImplyOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pImplyOrder	Ҫ�����ImplyOrder
	virtual void beforeAdd(CWriteableImplyOrder *pImplyOrder);
	
	///����ǰ����	
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	///@param	pNewImplyOrder	�µ�ֵ
	virtual void beforeUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder);
	
	///ɾ��ǰ����
	///@param	pImplyOrder	Ҫɾ����CImplyOrder
	virtual void beforeRemove(CImplyOrder *pImplyOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteDumpTrigger�ǲ�������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteDumpTrigger: public CQuoteActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CQuoteDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CQuoteDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pQuote	Ҫ�����Quote
	virtual void beforeAdd(CWriteableQuote *pQuote);
	
	///����ǰ����	
	///@param	pQuote	��ˢ�µ�CQuote
	///@param	pNewQuote	�µ�ֵ
	virtual void beforeUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote);
	
	///ɾ��ǰ����
	///@param	pQuote	Ҫɾ����CQuote
	virtual void beforeRemove(CQuote *pQuote);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataDumpTrigger�ǲ����ּ۱�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataDumpTrigger: public CMBLMarketDataActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CMBLMarketDataDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CMBLMarketDataDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pMBLMarketData	Ҫ�����MBLMarketData
	virtual void beforeAdd(CWriteableMBLMarketData *pMBLMarketData);
	
	///����ǰ����	
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	///@param	pNewMBLMarketData	�µ�ֵ
	virtual void beforeUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData);
	
	///ɾ��ǰ����
	///@param	pMBLMarketData	Ҫɾ����CMBLMarketData
	virtual void beforeRemove(CMBLMarketData *pMBLMarketData);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CTradeDumpTrigger�ǲ����ɽ�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeDumpTrigger: public CTradeActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CTradeDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CTradeDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pTrade	Ҫ�����Trade
	virtual void beforeAdd(CWriteableTrade *pTrade);
	
	///����ǰ����	
	///@param	pTrade	��ˢ�µ�CTrade
	///@param	pNewTrade	�µ�ֵ
	virtual void beforeUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade);
	
	///ɾ��ǰ����
	///@param	pTrade	Ҫɾ����CTrade
	virtual void beforeRemove(CTrade *pTrade);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseDumpTrigger�ǲ����۶Ͻ׶�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseDumpTrigger: public CFusePhaseActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CFusePhaseDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CFusePhaseDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pFusePhase	Ҫ�����FusePhase
	virtual void beforeAdd(CWriteableFusePhase *pFusePhase);
	
	///����ǰ����	
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	///@param	pNewFusePhase	�µ�ֵ
	virtual void beforeUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase);
	
	///ɾ��ǰ����
	///@param	pFusePhase	Ҫɾ����CFusePhase
	virtual void beforeRemove(CFusePhase *pFusePhase);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderDumpTrigger�ǲ���ִ������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderDumpTrigger: public CExecOrderActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CExecOrderDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CExecOrderDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pExecOrder	Ҫ�����ExecOrder
	virtual void beforeAdd(CWriteableExecOrder *pExecOrder);
	
	///����ǰ����	
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	///@param	pNewExecOrder	�µ�ֵ
	virtual void beforeUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder);
	
	///ɾ��ǰ����
	///@param	pExecOrder	Ҫɾ����CExecOrder
	virtual void beforeRemove(CExecOrder *pExecOrder);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureDumpTrigger�ǲ������������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureDumpTrigger: public CUniPressureActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CUniPressureDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CUniPressureDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pUniPressure	Ҫ�����UniPressure
	virtual void beforeAdd(CWriteableUniPressure *pUniPressure);
	
	///����ǰ����	
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	///@param	pNewUniPressure	�µ�ֵ
	virtual void beforeUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure);
	
	///ɾ��ǰ����
	///@param	pUniPressure	Ҫɾ����CUniPressure
	virtual void beforeRemove(CUniPressure *pUniPressure);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitDumpTrigger�ǲ����ǵ�ͣ������ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitDumpTrigger: public CBasePriceLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CBasePriceLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CBasePriceLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pBasePriceLimit	Ҫ�����BasePriceLimit
	virtual void beforeAdd(CWriteableBasePriceLimit *pBasePriceLimit);
	
	///����ǰ����	
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	///@param	pNewBasePriceLimit	�µ�ֵ
	virtual void beforeUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit);
	
	///ɾ��ǰ����
	///@param	pBasePriceLimit	Ҫɾ����CBasePriceLimit
	virtual void beforeRemove(CBasePriceLimit *pBasePriceLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitDumpTrigger�ǲ��������޶�ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitDumpTrigger: public CCreditLimitActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCreditLimitDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCreditLimitDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCreditLimit	Ҫ�����CreditLimit
	virtual void beforeAdd(CWriteableCreditLimit *pCreditLimit);
	
	///����ǰ����	
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	///@param	pNewCreditLimit	�µ�ֵ
	virtual void beforeUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit);
	
	///ɾ��ǰ����
	///@param	pCreditLimit	Ҫɾ����CCreditLimit
	virtual void beforeRemove(CCreditLimit *pCreditLimit);
	
private:
	FILE *m_output;
	int m_flag;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionDumpTrigger�ǲ��������ڻ���Լ��Ȩ����ʱ�Ĵ��������ڱ仯ʱ�������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionDumpTrigger: public CCurrInstrumentOptionActionTrigger
{
public:
	///���췽��
	///@param	output	����õ��ļ�
	///@param	flag	��������ľ������CREATE_ACTION��DELETE_ACTION��UPDATE_ACTION�Ļ�
	CCurrInstrumentOptionDumpTrigger(FILE *output, int flag=CREATE_ACTION|DELETE_ACTION|UPDATE_ACTION);
	
	///��������
	virtual ~CCurrInstrumentOptionDumpTrigger(void);

	virtual void output(CLogger *pLogger,int indent=0);

	///����ǰ����
	///@param	pCurrInstrumentOption	Ҫ�����CurrInstrumentOption
	virtual void beforeAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption);
	
	///����ǰ����	
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	�µ�ֵ
	virtual void beforeUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption);
	
	///ɾ��ǰ����
	///@param	pCurrInstrumentOption	Ҫɾ����CCurrInstrumentOption
	virtual void beforeRemove(CCurrInstrumentOption *pCurrInstrumentOption);
	
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
	
	CExchangeDataSyncStatusDumpTrigger *m_ExchangeDataSyncStatusTrigger;
	CSGDataSyncStatusDumpTrigger *m_SGDataSyncStatusTrigger;
	CCurrentTimeDumpTrigger *m_CurrentTimeTrigger;
	CDataCenterDescDumpTrigger *m_DataCenterDescTrigger;
	CExchangeDumpTrigger *m_ExchangeTrigger;
	CSettlementGroupDumpTrigger *m_SettlementGroupTrigger;
	CMarketDumpTrigger *m_MarketTrigger;
	CMarketProductDumpTrigger *m_MarketProductTrigger;
	CMarketProductGroupDumpTrigger *m_MarketProductGroupTrigger;
	CMdPubStatusDumpTrigger *m_MdPubStatusTrigger;
	CMarketDataTopicDumpTrigger *m_MarketDataTopicTrigger;
	CPartTopicSubscribeDumpTrigger *m_PartTopicSubscribeTrigger;
	CParticipantDumpTrigger *m_ParticipantTrigger;
	CUserDumpTrigger *m_UserTrigger;
	CClientDumpTrigger *m_ClientTrigger;
	CUserIPDumpTrigger *m_UserIPTrigger;
	CPartClientDumpTrigger *m_PartClientTrigger;
	CClearingTradingPartDumpTrigger *m_ClearingTradingPartTrigger;
	CAliasDefineDumpTrigger *m_AliasDefineTrigger;
	CUserFunctionRightDumpTrigger *m_UserFunctionRightTrigger;
	CAccountDumpTrigger *m_AccountTrigger;
	CUserCommFluxDumpTrigger *m_UserCommFluxTrigger;
	CMarketDataLogDumpTrigger *m_MarketDataLogTrigger;
	CUserSessionDumpTrigger *m_UserSessionTrigger;
	CMDSessionDumpTrigger *m_MDSessionTrigger;
	CLoginInfoDumpTrigger *m_LoginInfoTrigger;
	CDepthMarketDataDetailDumpTrigger *m_DepthMarketDataDetailTrigger;
	CInstrumentStatusDetailDumpTrigger *m_InstrumentStatusDetailTrigger;
	CFrontStatusDumpTrigger *m_FrontStatusTrigger;
	CMaxLocalIDDumpTrigger *m_MaxLocalIDTrigger;
	CBulletinDumpTrigger *m_BulletinTrigger;
	CMarketDataModifyDumpTrigger *m_MarketDataModifyTrigger;
	CDepthMarketDataDumpTrigger *m_DepthMarketDataTrigger;
	CTopicMarketDataDumpTrigger *m_TopicMarketDataTrigger;
	CTopicMarketDataVersionDumpTrigger *m_TopicMarketDataVersionTrigger;
	CInformationDumpTrigger *m_InformationTrigger;
	COrderCountDumpTrigger *m_OrderCountTrigger;
	CInstrumentDumpTrigger *m_InstrumentTrigger;
	CCombinationLegDumpTrigger *m_CombinationLegTrigger;
	CPartRoleAccountDumpTrigger *m_PartRoleAccountTrigger;
	CPartProductRoleDumpTrigger *m_PartProductRoleTrigger;
	CPartProductRightDumpTrigger *m_PartProductRightTrigger;
	CPartInstrumentRightDumpTrigger *m_PartInstrumentRightTrigger;
	CClientProductRightDumpTrigger *m_ClientProductRightTrigger;
	CClientInstrumentRightDumpTrigger *m_ClientInstrumentRightTrigger;
	CPartClientProductRightDumpTrigger *m_PartClientProductRightTrigger;
	CPartClientInstrumentRightDumpTrigger *m_PartClientInstrumentRightTrigger;
	CCurrProductPropertyDumpTrigger *m_CurrProductPropertyTrigger;
	CCurrInstrumentPropertyDumpTrigger *m_CurrInstrumentPropertyTrigger;
	CCurrPriceBandingDumpTrigger *m_CurrPriceBandingTrigger;
	CCurrMarginRateDumpTrigger *m_CurrMarginRateTrigger;
	CCurrMarginRateDetailDumpTrigger *m_CurrMarginRateDetailTrigger;
	CCurrPartPosiLimitDumpTrigger *m_CurrPartPosiLimitTrigger;
	CCurrPartPosiLimitDetailDumpTrigger *m_CurrPartPosiLimitDetailTrigger;
	CCurrClientPosiLimitDumpTrigger *m_CurrClientPosiLimitTrigger;
	CCurrClientPosiLimitDetailDumpTrigger *m_CurrClientPosiLimitDetailTrigger;
	CCurrSpecialPosiLimitDumpTrigger *m_CurrSpecialPosiLimitTrigger;
	CCurrSpecialPosiLimitDetailDumpTrigger *m_CurrSpecialPosiLimitDetailTrigger;
	CCurrHedgeRuleDumpTrigger *m_CurrHedgeRuleTrigger;
	CCurrTradingSegmentAttrDumpTrigger *m_CurrTradingSegmentAttrTrigger;
	CCurrFuseDumpTrigger *m_CurrFuseTrigger;
	CTradingAccountDumpTrigger *m_TradingAccountTrigger;
	CBaseReserveAccountDumpTrigger *m_BaseReserveAccountTrigger;
	CPartPositionDumpTrigger *m_PartPositionTrigger;
	CClientPositionDumpTrigger *m_ClientPositionTrigger;
	CHedgeVolumeDumpTrigger *m_HedgeVolumeTrigger;
	CRemainOrderDumpTrigger *m_RemainOrderTrigger;
	CMarketDataDumpTrigger *m_MarketDataTrigger;
	CClearingPartPositionDumpTrigger *m_ClearingPartPositionTrigger;
	CInstrumentStatusDumpTrigger *m_InstrumentStatusTrigger;
	COrderDumpTrigger *m_OrderTrigger;
	CCombOrderDumpTrigger *m_CombOrderTrigger;
	COTCOrderDumpTrigger *m_OTCOrderTrigger;
	CImplyOrderDumpTrigger *m_ImplyOrderTrigger;
	CQuoteDumpTrigger *m_QuoteTrigger;
	CMBLMarketDataDumpTrigger *m_MBLMarketDataTrigger;
	CTradeDumpTrigger *m_TradeTrigger;
	CFusePhaseDumpTrigger *m_FusePhaseTrigger;
	CExecOrderDumpTrigger *m_ExecOrderTrigger;
	CUniPressureDumpTrigger *m_UniPressureTrigger;
	CBasePriceLimitDumpTrigger *m_BasePriceLimitTrigger;
	CCreditLimitDumpTrigger *m_CreditLimitTrigger;
	CCurrInstrumentOptionDumpTrigger *m_CurrInstrumentOptionTrigger;
};

#endif
