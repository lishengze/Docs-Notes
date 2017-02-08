/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file BaseDataStruct.h
///@brief�������ڴ����ݿ��õĻ������ݽṹ�࣬�Լ�iterator��trigger�Ļ���
///@history 
///20060128	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef BASEDATASTRUCT_H
#define BASEDATASTRUCT_H

#include "platform.h"
#include "CBaseObject.h"
#include "customDataType.h"
#include "CTransaction.h"

///�жϽ���Ƿ���������
extern bool satisfy(int value,int type);

///�ַ����ȽϺ���
///@param	s1	�ַ���1
///@param	s2	�ַ���2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const char *s1, const char *s2);

///�����ȽϺ���
///@param	v1	����1
///@param	v2	����2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const int v1,const int v2);

///�������ȽϺ���
///@param	v1	������1
///@param	v2	������2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const double v1,const double v2);

///��buffer�л�ȡ��һ��token�������token���Զ��Ż��߻��зָ���
///��ʹ��ʱ����һ��Ӧ������ָ����buffer���Ժ�Ӧ����������NULL��
///������������ȡ�����е�token�����������ı�buffer�е����ݣ�����
///���������Լ��������ݡ����������������⣬��һ��ȡtoken�����н�
///��ǰ����ʼ�µ�һ��ȡtoken���У���Ӱ��ǰ��һ���Ľ�����������
///strtok����������
///@param	buffer	Ҫȡtoken��buffer��NULL��ʾ���ϴ�ȡ��buffer��ȡ��һ��
///@return	�õ���token
char *getNextToken(char *buffer);

class CWriteableExchangeDataSyncStatus;
class CExchangeDataSyncStatusFactory;
class CWriteableSGDataSyncStatus;
class CSGDataSyncStatusFactory;
class CWriteableCurrentTime;
class CCurrentTimeFactory;
class CWriteableDataCenterDesc;
class CDataCenterDescFactory;
class CWriteableExchange;
class CExchangeFactory;
class CWriteableSettlementGroup;
class CSettlementGroupFactory;
class CWriteableMarket;
class CMarketFactory;
class CWriteableMarketProduct;
class CMarketProductFactory;
class CWriteableMarketProductGroup;
class CMarketProductGroupFactory;
class CWriteableMdPubStatus;
class CMdPubStatusFactory;
class CWriteableMarketDataTopic;
class CMarketDataTopicFactory;
class CWriteablePartTopicSubscribe;
class CPartTopicSubscribeFactory;
class CWriteableParticipant;
class CParticipantFactory;
class CWriteableUser;
class CUserFactory;
class CWriteableClient;
class CClientFactory;
class CWriteableUserIP;
class CUserIPFactory;
class CWriteablePartClient;
class CPartClientFactory;
class CWriteableClearingTradingPart;
class CClearingTradingPartFactory;
class CWriteableAliasDefine;
class CAliasDefineFactory;
class CWriteableUserFunctionRight;
class CUserFunctionRightFactory;
class CWriteableAccount;
class CAccountFactory;
class CWriteableUserCommFlux;
class CUserCommFluxFactory;
class CWriteableMarketDataLog;
class CMarketDataLogFactory;
class CWriteableUserSession;
class CUserSessionFactory;
class CWriteableMDSession;
class CMDSessionFactory;
class CWriteableLoginInfo;
class CLoginInfoFactory;
class CWriteableDepthMarketDataDetail;
class CDepthMarketDataDetailFactory;
class CWriteableInstrumentStatusDetail;
class CInstrumentStatusDetailFactory;
class CWriteableFrontStatus;
class CFrontStatusFactory;
class CWriteableMaxLocalID;
class CMaxLocalIDFactory;
class CWriteableBulletin;
class CBulletinFactory;
class CWriteableMarketDataModify;
class CMarketDataModifyFactory;
class CWriteableDepthMarketData;
class CDepthMarketDataFactory;
class CWriteableTopicMarketData;
class CTopicMarketDataFactory;
class CWriteableTopicMarketDataVersion;
class CTopicMarketDataVersionFactory;
class CWriteableInformation;
class CInformationFactory;
class CWriteableOrderCount;
class COrderCountFactory;
class CWriteableInstrument;
class CInstrumentFactory;
class CWriteableCombinationLeg;
class CCombinationLegFactory;
class CWriteablePartRoleAccount;
class CPartRoleAccountFactory;
class CWriteablePartProductRole;
class CPartProductRoleFactory;
class CWriteablePartProductRight;
class CPartProductRightFactory;
class CWriteablePartInstrumentRight;
class CPartInstrumentRightFactory;
class CWriteableClientProductRight;
class CClientProductRightFactory;
class CWriteableClientInstrumentRight;
class CClientInstrumentRightFactory;
class CWriteablePartClientProductRight;
class CPartClientProductRightFactory;
class CWriteablePartClientInstrumentRight;
class CPartClientInstrumentRightFactory;
class CWriteableCurrProductProperty;
class CCurrProductPropertyFactory;
class CWriteableCurrInstrumentProperty;
class CCurrInstrumentPropertyFactory;
class CWriteableCurrPriceBanding;
class CCurrPriceBandingFactory;
class CWriteableCurrMarginRate;
class CCurrMarginRateFactory;
class CWriteableCurrMarginRateDetail;
class CCurrMarginRateDetailFactory;
class CWriteableCurrPartPosiLimit;
class CCurrPartPosiLimitFactory;
class CWriteableCurrPartPosiLimitDetail;
class CCurrPartPosiLimitDetailFactory;
class CWriteableCurrClientPosiLimit;
class CCurrClientPosiLimitFactory;
class CWriteableCurrClientPosiLimitDetail;
class CCurrClientPosiLimitDetailFactory;
class CWriteableCurrSpecialPosiLimit;
class CCurrSpecialPosiLimitFactory;
class CWriteableCurrSpecialPosiLimitDetail;
class CCurrSpecialPosiLimitDetailFactory;
class CWriteableCurrHedgeRule;
class CCurrHedgeRuleFactory;
class CWriteableCurrTradingSegmentAttr;
class CCurrTradingSegmentAttrFactory;
class CWriteableCurrFuse;
class CCurrFuseFactory;
class CWriteableTradingAccount;
class CTradingAccountFactory;
class CWriteableBaseReserveAccount;
class CBaseReserveAccountFactory;
class CWriteablePartPosition;
class CPartPositionFactory;
class CWriteableClientPosition;
class CClientPositionFactory;
class CWriteableHedgeVolume;
class CHedgeVolumeFactory;
class CWriteableRemainOrder;
class CRemainOrderFactory;
class CWriteableMarketData;
class CMarketDataFactory;
class CWriteableClearingPartPosition;
class CClearingPartPositionFactory;
class CWriteableInstrumentStatus;
class CInstrumentStatusFactory;
class CWriteableOrder;
class COrderFactory;
class CWriteableCombOrder;
class CCombOrderFactory;
class CWriteableOTCOrder;
class COTCOrderFactory;
class CWriteableImplyOrder;
class CImplyOrderFactory;
class CWriteableQuote;
class CQuoteFactory;
class CWriteableMBLMarketData;
class CMBLMarketDataFactory;
class CWriteableTrade;
class CTradeFactory;
class CWriteableFusePhase;
class CFusePhaseFactory;
class CWriteableExecOrder;
class CExecOrderFactory;
class CWriteableUniPressure;
class CUniPressureFactory;
class CWriteableBasePriceLimit;
class CBasePriceLimitFactory;
class CWriteableCreditLimit;
class CCreditLimitFactory;
class CWriteableHedgeDetail;
class CWriteableOrderAction;
class CWriteableQuoteAction;
class CWriteableExecOrderAction;
class CWriteableAccountDeposit;
class CWriteableUpdateAllInstrumentStatus;
class CWriteableAdminOrder;
class CWriteableCommPhase;
class CWriteableCurrHedge;
class CWriteableCurrInstrumentOption;
class CCurrInstrumentOptionFactory;

/////////////////////////////////////////////////////////////////////////
///CWriteableExchangeDataSyncStatus��һ���洢����������ͬ��״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExchangeDataSyncStatus
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! ExchangeID.isValid())
			return 0;
		if (! ExchangeDataSyncStatus.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableExchangeDataSyncStatus *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///����������
	CExchangeIDType ExchangeID;
	///����������ͬ��״̬
	CExchangeDataSyncStatusType ExchangeDataSyncStatus;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableExchangeDataSyncStatus CExchangeDataSyncStatus;

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusActionTrigger�ǲ�������������ͬ��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusActionTrigger
{
public:
	///���췽��
	CExchangeDataSyncStatusActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CExchangeDataSyncStatusActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CExchangeDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pExchangeDataSyncStatus	Ҫ�����ExchangeDataSyncStatus
	virtual void beforeAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
	
	///����󴥷�
	///@param	pExchangeDataSyncStatus	�Ѿ������ExchangeDataSyncStatus
	virtual void afterAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}

	///����ǰ����	
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	�µ�ֵ
	virtual void beforeUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	virtual void afterUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pExchangeDataSyncStatus	Ҫɾ����CExchangeDataSyncStatus
	virtual void beforeRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CExchangeDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusCommitTrigger��ȷ�Ͻ���������ͬ��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusCommitTrigger
{
public:
	///���췽��
	CExchangeDataSyncStatusCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CExchangeDataSyncStatusCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CExchangeDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pExchangeDataSyncStatus	�Ѿ������ExchangeDataSyncStatus
	virtual void commitAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}

	///���º󴥷�
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	///@param	poldExchangeDataSyncStatus	ԭ����ֵ
	virtual void commitUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pOldExchangeDataSyncStatus)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pExchangeDataSyncStatus	�Ѿ�ɾ����CExchangeDataSyncStatus
	virtual void commitRemove(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CExchangeDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusIterator��һ���Խ���������ͬ��״̬��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusIterator
{
public:
	///���췽��
	CExchangeDataSyncStatusIterator(void)
	{
	}

	///���췽��
	CExchangeDataSyncStatusIterator(CExchangeDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExchangeDataSyncStatusIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ExchangeDataSyncStatus
	///@return	��һ����������CExchangeDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchangeDataSyncStatus *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CExchangeDataSyncStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchangeDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchangeDataSyncStatus * pExchangeDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CExchangeDataSyncStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSGDataSyncStatus��һ���洢����������ͬ��״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSGDataSyncStatus
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! SGDataSyncStatus.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableSGDataSyncStatus *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CDateType TradingDay;
	///������
	CSettlementIDType SettlementID;
	///����������ͬ��״̬
	CSGDataSyncStatusType SGDataSyncStatus;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableSGDataSyncStatus CSGDataSyncStatus;

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusActionTrigger�ǲ�������������ͬ��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusActionTrigger
{
public:
	///���췽��
	CSGDataSyncStatusActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSGDataSyncStatusActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSGDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSGDataSyncStatus	Ҫ�����SGDataSyncStatus
	virtual void beforeAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSGDataSyncStatus	�Ѿ������SGDataSyncStatus
	virtual void afterAdd(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}

	///����ǰ����	
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	�µ�ֵ
	virtual void beforeUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	virtual void afterUpdate(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSGDataSyncStatus	Ҫɾ����CSGDataSyncStatus
	virtual void beforeRemove(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSGDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusCommitTrigger��ȷ�Ͻ���������ͬ��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusCommitTrigger
{
public:
	///���췽��
	CSGDataSyncStatusCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSGDataSyncStatusCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSGDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSGDataSyncStatus	�Ѿ������SGDataSyncStatus
	virtual void commitAdd(CSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}

	///���º󴥷�
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	///@param	poldSGDataSyncStatus	ԭ����ֵ
	virtual void commitUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pOldSGDataSyncStatus)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSGDataSyncStatus	�Ѿ�ɾ����CSGDataSyncStatus
	virtual void commitRemove(CWriteableSGDataSyncStatus *pSGDataSyncStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSGDataSyncStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusIterator��һ���Խ���������ͬ��״̬��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusIterator
{
public:
	///���췽��
	CSGDataSyncStatusIterator(void)
	{
	}

	///���췽��
	CSGDataSyncStatusIterator(CSGDataSyncStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSGDataSyncStatusIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SGDataSyncStatus
	///@return	��һ����������CSGDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSGDataSyncStatus *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSGDataSyncStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSGDataSyncStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSGDataSyncStatus * pSGDataSyncStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSGDataSyncStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrentTime��һ���洢��ǰʱ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrentTime
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! CurrDate.isValid())
			return 0;
		if (! CurrTime.isValid())
			return 0;
		if (! CurrMillisec.isValid())
			return 0;
		if (! OldTime.isValid())
			return 0;
		if (! OldMillisec.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrentTime *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��ǰ����
	CDateType CurrDate;
	///��ǰʱ��
	CTimeType CurrTime;
	///��ǰʱ�䣨���룩
	CMillisecType CurrMillisec;
	///ԭ��ʱ��
	CTimeType OldTime;
	///ԭ��ʱ�䣨���룩
	CMillisecType OldMillisec;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrentTime CCurrentTime;

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeActionTrigger�ǲ�����ǰʱ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeActionTrigger
{
public:
	///���췽��
	CCurrentTimeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrentTimeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrentTimeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrentTime	Ҫ�����CurrentTime
	virtual void beforeAdd(CWriteableCurrentTime *pCurrentTime)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrentTime	�Ѿ������CurrentTime
	virtual void afterAdd(CCurrentTime *pCurrentTime)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	///@param	pNewCurrentTime	�µ�ֵ
	virtual void beforeUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	virtual void afterUpdate(CCurrentTime *pCurrentTime)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrentTime	Ҫɾ����CCurrentTime
	virtual void beforeRemove(CCurrentTime *pCurrentTime)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrentTimeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeCommitTrigger��ȷ�ϵ�ǰʱ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeCommitTrigger
{
public:
	///���췽��
	CCurrentTimeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrentTimeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrentTimeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrentTime	�Ѿ������CurrentTime
	virtual void commitAdd(CCurrentTime *pCurrentTime)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	///@param	poldCurrentTime	ԭ����ֵ
	virtual void commitUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pOldCurrentTime)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrentTime	�Ѿ�ɾ����CCurrentTime
	virtual void commitRemove(CWriteableCurrentTime *pCurrentTime)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrentTimeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeIterator��һ���Ե�ǰʱ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeIterator
{
public:
	///���췽��
	CCurrentTimeIterator(void)
	{
	}

	///���췽��
	CCurrentTimeIterator(CCurrentTimeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrentTimeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrentTime
	///@return	��һ����������CCurrentTime������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrentTime *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrentTimeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrentTime ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrentTime * pCurrentTime,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrentTimeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableDataCenterDesc��һ���洢�������������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableDataCenterDesc
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! DataCenterID.isValid())
			return 0;
		if (! StartMode.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableDataCenterDesc *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�������Ĵ���
	CDataCenterIDType DataCenterID;
	///����ģʽ
	CStartModeType StartMode;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableDataCenterDesc CDataCenterDesc;

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescActionTrigger�ǲ���������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescActionTrigger
{
public:
	///���췽��
	CDataCenterDescActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CDataCenterDescActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CDataCenterDescFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pDataCenterDesc	Ҫ�����DataCenterDesc
	virtual void beforeAdd(CWriteableDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
	
	///����󴥷�
	///@param	pDataCenterDesc	�Ѿ������DataCenterDesc
	virtual void afterAdd(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}

	///����ǰ����	
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	///@param	pNewDataCenterDesc	�µ�ֵ
	virtual void beforeUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	virtual void afterUpdate(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pDataCenterDesc	Ҫɾ����CDataCenterDesc
	virtual void beforeRemove(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CDataCenterDescFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescCommitTrigger��ȷ��������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescCommitTrigger
{
public:
	///���췽��
	CDataCenterDescCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CDataCenterDescCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CDataCenterDescFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pDataCenterDesc	�Ѿ������DataCenterDesc
	virtual void commitAdd(CDataCenterDesc *pDataCenterDesc)
	{
		return;
	}

	///���º󴥷�
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	///@param	poldDataCenterDesc	ԭ����ֵ
	virtual void commitUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pOldDataCenterDesc)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pDataCenterDesc	�Ѿ�ɾ����CDataCenterDesc
	virtual void commitRemove(CWriteableDataCenterDesc *pDataCenterDesc)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CDataCenterDescFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescIterator��һ������������������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescIterator
{
public:
	///���췽��
	CDataCenterDescIterator(void)
	{
	}

	///���췽��
	CDataCenterDescIterator(CDataCenterDescFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDataCenterDescIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��DataCenterDesc
	///@return	��һ����������CDataCenterDesc������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDataCenterDesc *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CDataCenterDescFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDataCenterDesc ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDataCenterDesc * pDataCenterDesc,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CDataCenterDescFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableExchange��һ���洢�������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExchange
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ExchangeID.isValid())
			return 0;
		if (! ExchangeName.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableExchange *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///����������
	CExchangeIDType ExchangeID;
	///����������
	CExchangeNameType ExchangeName;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableExchange CExchange;

/////////////////////////////////////////////////////////////////////////
///CExchangeActionTrigger�ǲ���������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeActionTrigger
{
public:
	///���췽��
	CExchangeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CExchangeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CExchangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pExchange	Ҫ�����Exchange
	virtual void beforeAdd(CWriteableExchange *pExchange)
	{
		return;
	}
	
	///����󴥷�
	///@param	pExchange	�Ѿ������Exchange
	virtual void afterAdd(CExchange *pExchange)
	{
		return;
	}

	///����ǰ����	
	///@param	pExchange	��ˢ�µ�CExchange
	///@param	pNewExchange	�µ�ֵ
	virtual void beforeUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pExchange	��ˢ�µ�CExchange
	virtual void afterUpdate(CExchange *pExchange)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pExchange	Ҫɾ����CExchange
	virtual void beforeRemove(CExchange *pExchange)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CExchangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeCommitTrigger��ȷ�Ͻ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeCommitTrigger
{
public:
	///���췽��
	CExchangeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CExchangeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CExchangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pExchange	�Ѿ������Exchange
	virtual void commitAdd(CExchange *pExchange)
	{
		return;
	}

	///���º󴥷�
	///@param	pExchange	��ˢ�µ�CExchange
	///@param	poldExchange	ԭ����ֵ
	virtual void commitUpdate(CExchange *pExchange, CWriteableExchange *pOldExchange)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pExchange	�Ѿ�ɾ����CExchange
	virtual void commitRemove(CWriteableExchange *pExchange)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CExchangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeIterator��һ���Խ�������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeIterator
{
public:
	///���췽��
	CExchangeIterator(void)
	{
	}

	///���췽��
	CExchangeIterator(CExchangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExchangeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Exchange
	///@return	��һ����������CExchange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExchange *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CExchangeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExchange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExchange * pExchange,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CExchangeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSettlementGroup��һ���洢������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSettlementGroup
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementGroupName.isValid())
			return 0;
		if (! ExchangeID.isValid())
			return 0;
		if (! Currency.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableSettlementGroup *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///����������
	CSettlementGroupNameType SettlementGroupName;
	///����������
	CExchangeIDType ExchangeID;
	///����
	CCurrencyType Currency;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableSettlementGroup CSettlementGroup;

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupActionTrigger�ǲ���������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupActionTrigger
{
public:
	///���췽��
	CSettlementGroupActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSettlementGroupActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSettlementGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSettlementGroup	Ҫ�����SettlementGroup
	virtual void beforeAdd(CWriteableSettlementGroup *pSettlementGroup)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSettlementGroup	�Ѿ������SettlementGroup
	virtual void afterAdd(CSettlementGroup *pSettlementGroup)
	{
		return;
	}

	///����ǰ����	
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	///@param	pNewSettlementGroup	�µ�ֵ
	virtual void beforeUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	virtual void afterUpdate(CSettlementGroup *pSettlementGroup)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSettlementGroup	Ҫɾ����CSettlementGroup
	virtual void beforeRemove(CSettlementGroup *pSettlementGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSettlementGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupCommitTrigger��ȷ�Ͻ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupCommitTrigger
{
public:
	///���췽��
	CSettlementGroupCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSettlementGroupCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSettlementGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSettlementGroup	�Ѿ������SettlementGroup
	virtual void commitAdd(CSettlementGroup *pSettlementGroup)
	{
		return;
	}

	///���º󴥷�
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	///@param	poldSettlementGroup	ԭ����ֵ
	virtual void commitUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pOldSettlementGroup)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSettlementGroup	�Ѿ�ɾ����CSettlementGroup
	virtual void commitRemove(CWriteableSettlementGroup *pSettlementGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSettlementGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupIterator��һ���Խ������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupIterator
{
public:
	///���췽��
	CSettlementGroupIterator(void)
	{
	}

	///���췽��
	CSettlementGroupIterator(CSettlementGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSettlementGroupIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SettlementGroup
	///@return	��һ����������CSettlementGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSettlementGroup *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSettlementGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSettlementGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSettlementGroup * pSettlementGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSettlementGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarket��һ���洢�г��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarket
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! MarketID.isValid())
			return 0;
		if (! MarketName.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMarket *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�г�����
	CMarketIDType MarketID;
	///�г�����
	CMarketNameType MarketName;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarket CMarket;

/////////////////////////////////////////////////////////////////////////
///CMarketActionTrigger�ǲ����г�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketActionTrigger
{
public:
	///���췽��
	CMarketActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMarket	Ҫ�����Market
	virtual void beforeAdd(CWriteableMarket *pMarket)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMarket	�Ѿ������Market
	virtual void afterAdd(CMarket *pMarket)
	{
		return;
	}

	///����ǰ����	
	///@param	pMarket	��ˢ�µ�CMarket
	///@param	pNewMarket	�µ�ֵ
	virtual void beforeUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMarket	��ˢ�µ�CMarket
	virtual void afterUpdate(CMarket *pMarket)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMarket	Ҫɾ����CMarket
	virtual void beforeRemove(CMarket *pMarket)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketCommitTrigger��ȷ���г�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketCommitTrigger
{
public:
	///���췽��
	CMarketCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMarket	�Ѿ������Market
	virtual void commitAdd(CMarket *pMarket)
	{
		return;
	}

	///���º󴥷�
	///@param	pMarket	��ˢ�µ�CMarket
	///@param	poldMarket	ԭ����ֵ
	virtual void commitUpdate(CMarket *pMarket, CWriteableMarket *pOldMarket)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMarket	�Ѿ�ɾ����CMarket
	virtual void commitRemove(CWriteableMarket *pMarket)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketIterator��һ�����г���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketIterator
{
public:
	///���췽��
	CMarketIterator(void)
	{
	}

	///���췽��
	CMarketIterator(CMarketFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Market
	///@return	��һ����������CMarket������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarket *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMarketFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarket ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarket * pMarket,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMarketFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketProduct��һ���洢�г���Ʒ�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketProduct
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! MarketID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMarketProduct *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�г�����
	CMarketIDType MarketID;
	///��Ʒ����
	CProductIDType ProductID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketProduct CMarketProduct;

/////////////////////////////////////////////////////////////////////////
///CMarketProductActionTrigger�ǲ����г���Ʒ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductActionTrigger
{
public:
	///���췽��
	CMarketProductActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketProductActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketProductFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMarketProduct	Ҫ�����MarketProduct
	virtual void beforeAdd(CWriteableMarketProduct *pMarketProduct)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMarketProduct	�Ѿ������MarketProduct
	virtual void afterAdd(CMarketProduct *pMarketProduct)
	{
		return;
	}

	///����ǰ����	
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	///@param	pNewMarketProduct	�µ�ֵ
	virtual void beforeUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	virtual void afterUpdate(CMarketProduct *pMarketProduct)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMarketProduct	Ҫɾ����CMarketProduct
	virtual void beforeRemove(CMarketProduct *pMarketProduct)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketProductFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductCommitTrigger��ȷ���г���Ʒ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductCommitTrigger
{
public:
	///���췽��
	CMarketProductCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketProductCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketProductFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMarketProduct	�Ѿ������MarketProduct
	virtual void commitAdd(CMarketProduct *pMarketProduct)
	{
		return;
	}

	///���º󴥷�
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	///@param	poldMarketProduct	ԭ����ֵ
	virtual void commitUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pOldMarketProduct)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMarketProduct	�Ѿ�ɾ����CMarketProduct
	virtual void commitRemove(CWriteableMarketProduct *pMarketProduct)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketProductFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductIterator��һ�����г���Ʒ������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductIterator
{
public:
	///���췽��
	CMarketProductIterator(void)
	{
	}

	///���췽��
	CMarketProductIterator(CMarketProductFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketProductIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MarketProduct
	///@return	��һ����������CMarketProduct������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProduct *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMarketProductFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProduct ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProduct * pMarketProduct,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMarketProductFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketProductGroup��һ���洢�г���Ʒ������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketProductGroup
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! MarketID.isValid())
			return 0;
		if (! ProductGroupID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMarketProductGroup *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�г�����
	CMarketIDType MarketID;
	///��Ʒ�����
	CProductGroupIDType ProductGroupID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketProductGroup CMarketProductGroup;

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupActionTrigger�ǲ����г���Ʒ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupActionTrigger
{
public:
	///���췽��
	CMarketProductGroupActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketProductGroupActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketProductGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMarketProductGroup	Ҫ�����MarketProductGroup
	virtual void beforeAdd(CWriteableMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMarketProductGroup	�Ѿ������MarketProductGroup
	virtual void afterAdd(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}

	///����ǰ����	
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	///@param	pNewMarketProductGroup	�µ�ֵ
	virtual void beforeUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	virtual void afterUpdate(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMarketProductGroup	Ҫɾ����CMarketProductGroup
	virtual void beforeRemove(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketProductGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupCommitTrigger��ȷ���г���Ʒ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupCommitTrigger
{
public:
	///���췽��
	CMarketProductGroupCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketProductGroupCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketProductGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMarketProductGroup	�Ѿ������MarketProductGroup
	virtual void commitAdd(CMarketProductGroup *pMarketProductGroup)
	{
		return;
	}

	///���º󴥷�
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	///@param	poldMarketProductGroup	ԭ����ֵ
	virtual void commitUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pOldMarketProductGroup)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMarketProductGroup	�Ѿ�ɾ����CMarketProductGroup
	virtual void commitRemove(CWriteableMarketProductGroup *pMarketProductGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketProductGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupIterator��һ�����г���Ʒ�������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupIterator
{
public:
	///���췽��
	CMarketProductGroupIterator(void)
	{
	}

	///���췽��
	CMarketProductGroupIterator(CMarketProductGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketProductGroupIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MarketProductGroup
	///@return	��һ����������CMarketProductGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketProductGroup *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMarketProductGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketProductGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketProductGroup * pMarketProductGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMarketProductGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMdPubStatus��һ���洢���鷢��״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMdPubStatus
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ProductID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! MdPubStatus.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMdPubStatus *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��Ʒ����
	CProductIDType ProductID;
	///��Լ����״̬
	CInstrumentStatusType InstrumentStatus;
	///���鷢��״̬
	CMdPubStatusType MdPubStatus;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMdPubStatus CMdPubStatus;

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusActionTrigger�ǲ������鷢��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusActionTrigger
{
public:
	///���췽��
	CMdPubStatusActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMdPubStatusActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMdPubStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMdPubStatus	Ҫ�����MdPubStatus
	virtual void beforeAdd(CWriteableMdPubStatus *pMdPubStatus)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMdPubStatus	�Ѿ������MdPubStatus
	virtual void afterAdd(CMdPubStatus *pMdPubStatus)
	{
		return;
	}

	///����ǰ����	
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	///@param	pNewMdPubStatus	�µ�ֵ
	virtual void beforeUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	virtual void afterUpdate(CMdPubStatus *pMdPubStatus)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMdPubStatus	Ҫɾ����CMdPubStatus
	virtual void beforeRemove(CMdPubStatus *pMdPubStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMdPubStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusCommitTrigger��ȷ�����鷢��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusCommitTrigger
{
public:
	///���췽��
	CMdPubStatusCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMdPubStatusCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMdPubStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMdPubStatus	�Ѿ������MdPubStatus
	virtual void commitAdd(CMdPubStatus *pMdPubStatus)
	{
		return;
	}

	///���º󴥷�
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	///@param	poldMdPubStatus	ԭ����ֵ
	virtual void commitUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pOldMdPubStatus)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMdPubStatus	�Ѿ�ɾ����CMdPubStatus
	virtual void commitRemove(CWriteableMdPubStatus *pMdPubStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMdPubStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusIterator��һ�������鷢��״̬��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusIterator
{
public:
	///���췽��
	CMdPubStatusIterator(void)
	{
	}

	///���췽��
	CMdPubStatusIterator(CMdPubStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMdPubStatusIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MdPubStatus
	///@return	��һ����������CMdPubStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMdPubStatus *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMdPubStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMdPubStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMdPubStatus * pMdPubStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMdPubStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketDataTopic��һ���洢��������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketDataTopic
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! NextPublishTime.isValid())
			return 0;
		if (! NextLogID.isValid())
			return 0;
		if (! TopicID.isValid())
			return 0;
		if (! TopicName.isValid())
			return 0;
		if (! MarketID.isValid())
			return 0;
		if (! SnapShotFeq.isValid())
			return 0;
		if (! MarketDataDepth.isValid())
			return 0;
		if (! DelaySeconds.isValid())
			return 0;
		if (! MarketDataMode.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMarketDataTopic *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�´η�������ʱ��
	CTimeType NextPublishTime;
	///�´�Ҫ����������ˮ���
	CSequenceNoType NextLogID;
	///�������
	CTopicIDType TopicID;
	///��������
	CTopicNameType TopicName;
	///�г�����
	CMarketIDType MarketID;
	///����Ƶ��
	CSecondsType SnapShotFeq;
	///�г��������
	CMarketDataDepthType MarketDataDepth;
	///�ӳ�����
	CSecondsType DelaySeconds;
	///����ģʽ
	CMarketDataModeType MarketDataMode;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketDataTopic CMarketDataTopic;

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicActionTrigger�ǲ�����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicActionTrigger
{
public:
	///���췽��
	CMarketDataTopicActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataTopicActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataTopicFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMarketDataTopic	Ҫ�����MarketDataTopic
	virtual void beforeAdd(CWriteableMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMarketDataTopic	�Ѿ������MarketDataTopic
	virtual void afterAdd(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}

	///����ǰ����	
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	///@param	pNewMarketDataTopic	�µ�ֵ
	virtual void beforeUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	virtual void afterUpdate(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMarketDataTopic	Ҫɾ����CMarketDataTopic
	virtual void beforeRemove(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataTopicFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicCommitTrigger��ȷ����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicCommitTrigger
{
public:
	///���췽��
	CMarketDataTopicCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataTopicCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataTopicFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMarketDataTopic	�Ѿ������MarketDataTopic
	virtual void commitAdd(CMarketDataTopic *pMarketDataTopic)
	{
		return;
	}

	///���º󴥷�
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	///@param	poldMarketDataTopic	ԭ����ֵ
	virtual void commitUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pOldMarketDataTopic)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMarketDataTopic	�Ѿ�ɾ����CMarketDataTopic
	virtual void commitRemove(CWriteableMarketDataTopic *pMarketDataTopic)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataTopicFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicIterator��һ�������������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicIterator
{
public:
	///���췽��
	CMarketDataTopicIterator(void)
	{
	}

	///���췽��
	CMarketDataTopicIterator(CMarketDataTopicFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataTopicIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MarketDataTopic
	///@return	��һ����������CMarketDataTopic������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataTopic *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMarketDataTopicFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataTopic ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataTopic * pMarketDataTopic,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMarketDataTopicFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartTopicSubscribe��һ���洢��Ա�����г��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartTopicSubscribe
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! ParticipantType.isValid())
			return 0;
		if (! TopicID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartTopicSubscribe *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�����ߴ���
	CParticipantIDType ParticipantID;
	///����������
	CParticipantTypeType ParticipantType;
	///�������
	CTopicIDType TopicID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteablePartTopicSubscribe CPartTopicSubscribe;

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeActionTrigger�ǲ�����Ա�����г�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeActionTrigger
{
public:
	///���췽��
	CPartTopicSubscribeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartTopicSubscribeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartTopicSubscribeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartTopicSubscribe	Ҫ�����PartTopicSubscribe
	virtual void beforeAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartTopicSubscribe	�Ѿ������PartTopicSubscribe
	virtual void afterAdd(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	�µ�ֵ
	virtual void beforeUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	virtual void afterUpdate(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartTopicSubscribe	Ҫɾ����CPartTopicSubscribe
	virtual void beforeRemove(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartTopicSubscribeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeCommitTrigger��ȷ�ϻ�Ա�����г�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeCommitTrigger
{
public:
	///���췽��
	CPartTopicSubscribeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartTopicSubscribeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartTopicSubscribeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartTopicSubscribe	�Ѿ������PartTopicSubscribe
	virtual void commitAdd(CPartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	///@param	poldPartTopicSubscribe	ԭ����ֵ
	virtual void commitUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pOldPartTopicSubscribe)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartTopicSubscribe	�Ѿ�ɾ����CPartTopicSubscribe
	virtual void commitRemove(CWriteablePartTopicSubscribe *pPartTopicSubscribe)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartTopicSubscribeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeIterator��һ���Ի�Ա�����г���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeIterator
{
public:
	///���췽��
	CPartTopicSubscribeIterator(void)
	{
	}

	///���췽��
	CPartTopicSubscribeIterator(CPartTopicSubscribeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartTopicSubscribeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartTopicSubscribe
	///@return	��һ����������CPartTopicSubscribe������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartTopicSubscribe *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartTopicSubscribeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartTopicSubscribe ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartTopicSubscribe * pPartTopicSubscribe,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartTopicSubscribeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableParticipant��һ���洢��Ա�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableParticipant
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! ParticipantName.isValid())
			return 0;
		if (! ParticipantAbbr.isValid())
			return 0;
		if (! MemberType.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableParticipant *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��Ա����
	CParticipantIDType ParticipantID;
	///��Ա����
	CParticipantNameType ParticipantName;
	///��Ա���
	CParticipantAbbrType ParticipantAbbr;
	///��Ա����
	CMemberTypeType MemberType;
	///�Ƿ��Ծ
	CBoolType IsActive;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�Ľ��㽻�׻�Ա��ϵ��ָ��
	///@param	pFactory	�����Ӧ�Ľ��㽻�׻�Ա��ϵ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ľ��㽻�׻�Ա��ϵ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableClearingTradingPart *linkClearingTradingPart(CClearingTradingPartFactory *pFactory) const;

	///�����Ӧ�Ľ��㽻�׻�Ա��ϵָ��
	///@param	pClearingTradingPart	Ҫ���ӵ��Ķ���
	///@return	�����pClearingTradingPart
	const CWriteableClearingTradingPart *linkClearingTradingPart(const CWriteableClearingTradingPart *pClearingTradingPart) const
	{
		void *target=(void *)(&(this->pClearingTradingPart));
		*((const CWriteableClearingTradingPart **)target)=pClearingTradingPart;
		return pClearingTradingPart;
	}
	
	///��ȡ��Ӧ�Ľ��㽻�׻�Ա��ϵ��ָ��
	///@return	�ҵ��Ķ�Ӧ�Ľ��㽻�׻�Ա��ϵ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableClearingTradingPart *getClearingTradingPart(void) const
	{
		return pClearingTradingPart;
	}

private:
	///��Ӧ�Ľ��㽻�׻�Ա��ϵ
	const CWriteableClearingTradingPart *pClearingTradingPart;
};

typedef const CWriteableParticipant CParticipant;

/////////////////////////////////////////////////////////////////////////
///CParticipantActionTrigger�ǲ�����Աʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantActionTrigger
{
public:
	///���췽��
	CParticipantActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CParticipantActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CParticipantFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pParticipant	Ҫ�����Participant
	virtual void beforeAdd(CWriteableParticipant *pParticipant)
	{
		return;
	}
	
	///����󴥷�
	///@param	pParticipant	�Ѿ������Participant
	virtual void afterAdd(CParticipant *pParticipant)
	{
		return;
	}

	///����ǰ����	
	///@param	pParticipant	��ˢ�µ�CParticipant
	///@param	pNewParticipant	�µ�ֵ
	virtual void beforeUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pParticipant	��ˢ�µ�CParticipant
	virtual void afterUpdate(CParticipant *pParticipant)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pParticipant	Ҫɾ����CParticipant
	virtual void beforeRemove(CParticipant *pParticipant)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CParticipantFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantCommitTrigger��ȷ�ϻ�Աʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantCommitTrigger
{
public:
	///���췽��
	CParticipantCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CParticipantCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CParticipantFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pParticipant	�Ѿ������Participant
	virtual void commitAdd(CParticipant *pParticipant)
	{
		return;
	}

	///���º󴥷�
	///@param	pParticipant	��ˢ�µ�CParticipant
	///@param	poldParticipant	ԭ����ֵ
	virtual void commitUpdate(CParticipant *pParticipant, CWriteableParticipant *pOldParticipant)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pParticipant	�Ѿ�ɾ����CParticipant
	virtual void commitRemove(CWriteableParticipant *pParticipant)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CParticipantFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantIterator��һ���Ի�Ա��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantIterator
{
public:
	///���췽��
	CParticipantIterator(void)
	{
	}

	///���췽��
	CParticipantIterator(CParticipantFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CParticipantIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Participant
	///@return	��һ����������CParticipant������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CParticipant *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CParticipantFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pParticipant ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableParticipant * pParticipant,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CParticipantFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUser��һ���洢�û��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUser
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! Password.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableUser *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��Ա����
	CParticipantIDType ParticipantID;
	///�����û�����
	CUserIDType UserID;
	///�����û�����
	CUserTypeType UserType;
	///����
	CPasswordType Password;
	///����ԱȨ��
	CUserActiveType IsActive;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUser CUser;

/////////////////////////////////////////////////////////////////////////
///CUserActionTrigger�ǲ����û�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserActionTrigger
{
public:
	///���췽��
	CUserActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pUser	Ҫ�����User
	virtual void beforeAdd(CWriteableUser *pUser)
	{
		return;
	}
	
	///����󴥷�
	///@param	pUser	�Ѿ������User
	virtual void afterAdd(CUser *pUser)
	{
		return;
	}

	///����ǰ����	
	///@param	pUser	��ˢ�µ�CUser
	///@param	pNewUser	�µ�ֵ
	virtual void beforeUpdate(CUser *pUser, CWriteableUser *pNewUser)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pUser	��ˢ�µ�CUser
	virtual void afterUpdate(CUser *pUser)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pUser	Ҫɾ����CUser
	virtual void beforeRemove(CUser *pUser)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommitTrigger��ȷ���û�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommitTrigger
{
public:
	///���췽��
	CUserCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pUser	�Ѿ������User
	virtual void commitAdd(CUser *pUser)
	{
		return;
	}

	///���º󴥷�
	///@param	pUser	��ˢ�µ�CUser
	///@param	poldUser	ԭ����ֵ
	virtual void commitUpdate(CUser *pUser, CWriteableUser *pOldUser)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pUser	�Ѿ�ɾ����CUser
	virtual void commitRemove(CWriteableUser *pUser)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserIterator��һ�����û���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIterator
{
public:
	///���췽��
	CUserIterator(void)
	{
	}

	///���췽��
	CUserIterator(CUserFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��User
	///@return	��һ����������CUser������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUser *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CUserFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUser ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUser * pUser,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CUserFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClient��һ���洢�ͻ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClient
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ClientID.isValid())
			return 0;
		if (! ClientName.isValid())
			return 0;
		if (! IdentifiedCardType.isValid())
			return 0;
		if (! IdentifiedCardNo.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableClient *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�ͻ�����
	CClientIDType ClientID;
	///�ͻ�����
	CPartyNameType ClientName;
	///֤������
	CIdCardTypeType IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType IdentifiedCardNo;
	///���׽�ɫ
	CTradingRoleType TradingRole;
	///�ͻ�����
	CClientTypeType ClientType;
	///�Ƿ��Ծ
	CBoolType IsActive;
	unsigned int HashClientID;
	
	///����ClientID��hashֵ
	void calHashClientID(void)
	{
		unsigned key=0;
		key=ClientID.hash(key);
		HashClientID=key;
	}
	
	///������Ҫ���������ClientID��hashֵ
	void updateHashClientID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashClientID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashClientID();
	}
	

private:
};

typedef const CWriteableClient CClient;

/////////////////////////////////////////////////////////////////////////
///CClientActionTrigger�ǲ����ͻ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientActionTrigger
{
public:
	///���췽��
	CClientActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pClient	Ҫ�����Client
	virtual void beforeAdd(CWriteableClient *pClient)
	{
		return;
	}
	
	///����󴥷�
	///@param	pClient	�Ѿ������Client
	virtual void afterAdd(CClient *pClient)
	{
		return;
	}

	///����ǰ����	
	///@param	pClient	��ˢ�µ�CClient
	///@param	pNewClient	�µ�ֵ
	virtual void beforeUpdate(CClient *pClient, CWriteableClient *pNewClient)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pClient	��ˢ�µ�CClient
	virtual void afterUpdate(CClient *pClient)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pClient	Ҫɾ����CClient
	virtual void beforeRemove(CClient *pClient)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientCommitTrigger��ȷ�Ͽͻ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientCommitTrigger
{
public:
	///���췽��
	CClientCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pClient	�Ѿ������Client
	virtual void commitAdd(CClient *pClient)
	{
		return;
	}

	///���º󴥷�
	///@param	pClient	��ˢ�µ�CClient
	///@param	poldClient	ԭ����ֵ
	virtual void commitUpdate(CClient *pClient, CWriteableClient *pOldClient)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pClient	�Ѿ�ɾ����CClient
	virtual void commitRemove(CWriteableClient *pClient)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientIterator��һ���Կͻ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientIterator
{
public:
	///���췽��
	CClientIterator(void)
	{
	}

	///���췽��
	CClientIterator(CClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Client
	///@return	��һ����������CClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClient *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CClientFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClient * pClient,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CClientFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserIP��һ���洢����ԱIP��ַ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserIP
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! IPMask.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableUserIP *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�����û�����
	CUserIDType UserID;
	///IP��ַ
	CIPAddressType IPAddress;
	///IP��ַ����
	CIPAddressType IPMask;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUserIP CUserIP;

/////////////////////////////////////////////////////////////////////////
///CUserIPActionTrigger�ǲ�������ԱIP��ַʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPActionTrigger
{
public:
	///���췽��
	CUserIPActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserIPActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pUserIP	Ҫ�����UserIP
	virtual void beforeAdd(CWriteableUserIP *pUserIP)
	{
		return;
	}
	
	///����󴥷�
	///@param	pUserIP	�Ѿ������UserIP
	virtual void afterAdd(CUserIP *pUserIP)
	{
		return;
	}

	///����ǰ����	
	///@param	pUserIP	��ˢ�µ�CUserIP
	///@param	pNewUserIP	�µ�ֵ
	virtual void beforeUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pUserIP	��ˢ�µ�CUserIP
	virtual void afterUpdate(CUserIP *pUserIP)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pUserIP	Ҫɾ����CUserIP
	virtual void beforeRemove(CUserIP *pUserIP)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPCommitTrigger��ȷ�Ͻ���ԱIP��ַʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPCommitTrigger
{
public:
	///���췽��
	CUserIPCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserIPCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pUserIP	�Ѿ������UserIP
	virtual void commitAdd(CUserIP *pUserIP)
	{
		return;
	}

	///���º󴥷�
	///@param	pUserIP	��ˢ�µ�CUserIP
	///@param	poldUserIP	ԭ����ֵ
	virtual void commitUpdate(CUserIP *pUserIP, CWriteableUserIP *pOldUserIP)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pUserIP	�Ѿ�ɾ����CUserIP
	virtual void commitRemove(CWriteableUserIP *pUserIP)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPIterator��һ���Խ���ԱIP��ַ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPIterator
{
public:
	///���췽��
	CUserIPIterator(void)
	{
	}

	///���췽��
	CUserIPIterator(CUserIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserIPIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��UserIP
	///@return	��һ����������CUserIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserIP *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CUserIPFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserIP * pUserIP,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CUserIPFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartClient��һ���洢��Ա�ͻ���ϵ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartClient
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ClientID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartClient *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�ͻ�����
	CClientIDType ClientID;
	///��Ա����
	CParticipantIDType ParticipantID;
	unsigned int HashPartClient;
	
	///����PartClient��hashֵ
	void calHashPartClient(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ClientID.hash(key);
		HashPartClient=key;
	}
	
	///������Ҫ���������PartClient��hashֵ
	void updateHashPartClient(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashPartClient();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashPartClient();
	}
	
	///�����Ӧ�Ļ�Ա��ָ��
	///@param	pFactory	�����Ӧ�Ļ�Ա��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ļ�Ա��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableParticipant *linkParticipant(CParticipantFactory *pFactory) const;

	///�����Ӧ�Ļ�Աָ��
	///@param	pParticipant	Ҫ���ӵ��Ķ���
	///@return	�����pParticipant
	const CWriteableParticipant *linkParticipant(const CWriteableParticipant *pParticipant) const
	{
		void *target=(void *)(&(this->pParticipant));
		*((const CWriteableParticipant **)target)=pParticipant;
		return pParticipant;
	}
	
	///��ȡ��Ӧ�Ļ�Ա��ָ��
	///@return	�ҵ��Ķ�Ӧ�Ļ�Ա��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableParticipant *getParticipant(void) const
	{
		return pParticipant;
	}
	///�����Ӧ�Ŀͻ���ָ��
	///@param	pFactory	�����Ӧ�Ŀͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ŀͻ���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableClient *linkClient(CClientFactory *pFactory) const;

	///�����Ӧ�Ŀͻ�ָ��
	///@param	pClient	Ҫ���ӵ��Ķ���
	///@return	�����pClient
	const CWriteableClient *linkClient(const CWriteableClient *pClient) const
	{
		void *target=(void *)(&(this->pClient));
		*((const CWriteableClient **)target)=pClient;
		return pClient;
	}
	
	///��ȡ��Ӧ�Ŀͻ���ָ��
	///@return	�ҵ��Ķ�Ӧ�Ŀͻ���ָ�룬����Ҳ����򷵻�NULL
	const CWriteableClient *getClient(void) const
	{
		return pClient;
	}

private:
	///��Ӧ�Ļ�Ա
	const CWriteableParticipant *pParticipant;
	///��Ӧ�Ŀͻ�
	const CWriteableClient *pClient;
};

typedef const CWriteablePartClient CPartClient;

/////////////////////////////////////////////////////////////////////////
///CPartClientActionTrigger�ǲ�����Ա�ͻ���ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientActionTrigger
{
public:
	///���췽��
	CPartClientActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartClientActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartClient	Ҫ�����PartClient
	virtual void beforeAdd(CWriteablePartClient *pPartClient)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartClient	�Ѿ������PartClient
	virtual void afterAdd(CPartClient *pPartClient)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartClient	��ˢ�µ�CPartClient
	///@param	pNewPartClient	�µ�ֵ
	virtual void beforeUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartClient	��ˢ�µ�CPartClient
	virtual void afterUpdate(CPartClient *pPartClient)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartClient	Ҫɾ����CPartClient
	virtual void beforeRemove(CPartClient *pPartClient)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientCommitTrigger��ȷ�ϻ�Ա�ͻ���ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientCommitTrigger
{
public:
	///���췽��
	CPartClientCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartClientCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartClient	�Ѿ������PartClient
	virtual void commitAdd(CPartClient *pPartClient)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartClient	��ˢ�µ�CPartClient
	///@param	poldPartClient	ԭ����ֵ
	virtual void commitUpdate(CPartClient *pPartClient, CWriteablePartClient *pOldPartClient)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartClient	�Ѿ�ɾ����CPartClient
	virtual void commitRemove(CWriteablePartClient *pPartClient)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartClientFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientIterator��һ���Ի�Ա�ͻ���ϵ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientIterator
{
public:
	///���췽��
	CPartClientIterator(void)
	{
	}

	///���췽��
	CPartClientIterator(CPartClientFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartClient
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClient *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartClientFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClient ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClient * pPartClient,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartClientFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClearingTradingPart��һ���洢���㽻�׻�Ա��ϵ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClearingTradingPart
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ClearingPartID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableClearingTradingPart *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�����Ա
	CParticipantIDType ClearingPartID;
	///���׻�Ա
	CParticipantIDType ParticipantID;
	unsigned int HashParticipantID;
	
	///����ParticipantID��hashֵ
	void calHashParticipantID(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		HashParticipantID=key;
	}
	
	///������Ҫ���������ParticipantID��hashֵ
	void updateHashParticipantID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashParticipantID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashParticipantID();
	}
	

private:
};

typedef const CWriteableClearingTradingPart CClearingTradingPart;

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartActionTrigger�ǲ������㽻�׻�Ա��ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartActionTrigger
{
public:
	///���췽��
	CClearingTradingPartActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CClearingTradingPartActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClearingTradingPartFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pClearingTradingPart	Ҫ�����ClearingTradingPart
	virtual void beforeAdd(CWriteableClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
	
	///����󴥷�
	///@param	pClearingTradingPart	�Ѿ������ClearingTradingPart
	virtual void afterAdd(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}

	///����ǰ����	
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	///@param	pNewClearingTradingPart	�µ�ֵ
	virtual void beforeUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	virtual void afterUpdate(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pClearingTradingPart	Ҫɾ����CClearingTradingPart
	virtual void beforeRemove(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClearingTradingPartFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartCommitTrigger��ȷ�Ͻ��㽻�׻�Ա��ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartCommitTrigger
{
public:
	///���췽��
	CClearingTradingPartCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CClearingTradingPartCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClearingTradingPartFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pClearingTradingPart	�Ѿ������ClearingTradingPart
	virtual void commitAdd(CClearingTradingPart *pClearingTradingPart)
	{
		return;
	}

	///���º󴥷�
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	///@param	poldClearingTradingPart	ԭ����ֵ
	virtual void commitUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pOldClearingTradingPart)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pClearingTradingPart	�Ѿ�ɾ����CClearingTradingPart
	virtual void commitRemove(CWriteableClearingTradingPart *pClearingTradingPart)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClearingTradingPartFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartIterator��һ���Խ��㽻�׻�Ա��ϵ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartIterator
{
public:
	///���췽��
	CClearingTradingPartIterator(void)
	{
	}

	///���췽��
	CClearingTradingPartIterator(CClearingTradingPartFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClearingTradingPartIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ClearingTradingPart
	///@return	��һ����������CClearingTradingPart������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingTradingPart *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CClearingTradingPartFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingTradingPart ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingTradingPart * pClearingTradingPart,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CClearingTradingPartFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableAliasDefine��һ���洢��������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAliasDefine
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! StartPos.isValid())
			return 0;
		if (! Alias.isValid())
			return 0;
		if (! OriginalText.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableAliasDefine *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��ʼλ��
	CStartPosType StartPos;
	///����
	CAliasType Alias;
	///ԭ��
	COriginalTextType OriginalText;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableAliasDefine CAliasDefine;

/////////////////////////////////////////////////////////////////////////
///CAliasDefineActionTrigger�ǲ�����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineActionTrigger
{
public:
	///���췽��
	CAliasDefineActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CAliasDefineActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CAliasDefineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pAliasDefine	Ҫ�����AliasDefine
	virtual void beforeAdd(CWriteableAliasDefine *pAliasDefine)
	{
		return;
	}
	
	///����󴥷�
	///@param	pAliasDefine	�Ѿ������AliasDefine
	virtual void afterAdd(CAliasDefine *pAliasDefine)
	{
		return;
	}

	///����ǰ����	
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	///@param	pNewAliasDefine	�µ�ֵ
	virtual void beforeUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	virtual void afterUpdate(CAliasDefine *pAliasDefine)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pAliasDefine	Ҫɾ����CAliasDefine
	virtual void beforeRemove(CAliasDefine *pAliasDefine)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CAliasDefineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineCommitTrigger��ȷ�ϱ�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineCommitTrigger
{
public:
	///���췽��
	CAliasDefineCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CAliasDefineCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CAliasDefineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pAliasDefine	�Ѿ������AliasDefine
	virtual void commitAdd(CAliasDefine *pAliasDefine)
	{
		return;
	}

	///���º󴥷�
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	///@param	poldAliasDefine	ԭ����ֵ
	virtual void commitUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pOldAliasDefine)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pAliasDefine	�Ѿ�ɾ����CAliasDefine
	virtual void commitRemove(CWriteableAliasDefine *pAliasDefine)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CAliasDefineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineIterator��һ���Ա��������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineIterator
{
public:
	///���췽��
	CAliasDefineIterator(void)
	{
	}

	///���췽��
	CAliasDefineIterator(CAliasDefineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CAliasDefineIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��AliasDefine
	///@return	��һ����������CAliasDefine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAliasDefine *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CAliasDefineFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAliasDefine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAliasDefine * pAliasDefine,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CAliasDefineFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserFunctionRight��һ���洢�û�����Ȩ�޵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserFunctionRight
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! FunctionCode.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableUserFunctionRight *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�����û�����
	CUserIDType UserID;
	///���ܴ���
	CFunctionCodeType FunctionCode;
	unsigned int HashUserFunction;
	
	///����UserFunction��hashֵ
	void calHashUserFunction(void)
	{
		unsigned key=0;
		key=UserID.hash(key);
		key=FunctionCode.hash(key);
		HashUserFunction=key;
	}
	
	///������Ҫ���������UserFunction��hashֵ
	void updateHashUserFunction(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashUserFunction();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashUserFunction();
	}
	

private:
};

typedef const CWriteableUserFunctionRight CUserFunctionRight;

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightActionTrigger�ǲ����û�����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightActionTrigger
{
public:
	///���췽��
	CUserFunctionRightActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserFunctionRightActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserFunctionRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pUserFunctionRight	Ҫ�����UserFunctionRight
	virtual void beforeAdd(CWriteableUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
	
	///����󴥷�
	///@param	pUserFunctionRight	�Ѿ������UserFunctionRight
	virtual void afterAdd(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}

	///����ǰ����	
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	///@param	pNewUserFunctionRight	�µ�ֵ
	virtual void beforeUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	virtual void afterUpdate(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pUserFunctionRight	Ҫɾ����CUserFunctionRight
	virtual void beforeRemove(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserFunctionRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightCommitTrigger��ȷ���û�����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightCommitTrigger
{
public:
	///���췽��
	CUserFunctionRightCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserFunctionRightCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserFunctionRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pUserFunctionRight	�Ѿ������UserFunctionRight
	virtual void commitAdd(CUserFunctionRight *pUserFunctionRight)
	{
		return;
	}

	///���º󴥷�
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	///@param	poldUserFunctionRight	ԭ����ֵ
	virtual void commitUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pOldUserFunctionRight)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pUserFunctionRight	�Ѿ�ɾ����CUserFunctionRight
	virtual void commitRemove(CWriteableUserFunctionRight *pUserFunctionRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserFunctionRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightIterator��һ�����û�����Ȩ�޵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightIterator
{
public:
	///���췽��
	CUserFunctionRightIterator(void)
	{
	}

	///���췽��
	CUserFunctionRightIterator(CUserFunctionRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserFunctionRightIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��UserFunctionRight
	///@return	��һ����������CUserFunctionRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserFunctionRight *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CUserFunctionRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserFunctionRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserFunctionRight * pUserFunctionRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CUserFunctionRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableAccount��һ���洢�ʽ��˻��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAccount
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! Currency.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableAccount *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�ʽ��ʺ�
	CAccountIDType AccountID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///����
	CCurrencyType Currency;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�Ľ����˻���ָ��
	///@param	pFactory	�����Ӧ�Ľ����˻���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ľ����˻���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableTradingAccount *linkTradingAccount(CTradingAccountFactory *pFactory) const;

	///�����Ӧ�Ľ����˻�ָ��
	///@param	pTradingAccount	Ҫ���ӵ��Ķ���
	///@return	�����pTradingAccount
	const CWriteableTradingAccount *linkTradingAccount(const CWriteableTradingAccount *pTradingAccount) const
	{
		void *target=(void *)(&(this->pTradingAccount));
		*((const CWriteableTradingAccount **)target)=pTradingAccount;
		return pTradingAccount;
	}
	
	///��ȡ��Ӧ�Ľ����˻���ָ��
	///@return	�ҵ��Ķ�Ӧ�Ľ����˻���ָ�룬����Ҳ����򷵻�NULL
	const CWriteableTradingAccount *getTradingAccount(void) const
	{
		return pTradingAccount;
	}

private:
	///��Ӧ�Ľ����˻�
	const CWriteableTradingAccount *pTradingAccount;
};

typedef const CWriteableAccount CAccount;

/////////////////////////////////////////////////////////////////////////
///CAccountActionTrigger�ǲ����ʽ��˻�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountActionTrigger
{
public:
	///���췽��
	CAccountActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CAccountActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pAccount	Ҫ�����Account
	virtual void beforeAdd(CWriteableAccount *pAccount)
	{
		return;
	}
	
	///����󴥷�
	///@param	pAccount	�Ѿ������Account
	virtual void afterAdd(CAccount *pAccount)
	{
		return;
	}

	///����ǰ����	
	///@param	pAccount	��ˢ�µ�CAccount
	///@param	pNewAccount	�µ�ֵ
	virtual void beforeUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pAccount	��ˢ�µ�CAccount
	virtual void afterUpdate(CAccount *pAccount)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pAccount	Ҫɾ����CAccount
	virtual void beforeRemove(CAccount *pAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAccountCommitTrigger��ȷ���ʽ��˻�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountCommitTrigger
{
public:
	///���췽��
	CAccountCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CAccountCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pAccount	�Ѿ������Account
	virtual void commitAdd(CAccount *pAccount)
	{
		return;
	}

	///���º󴥷�
	///@param	pAccount	��ˢ�µ�CAccount
	///@param	poldAccount	ԭ����ֵ
	virtual void commitUpdate(CAccount *pAccount, CWriteableAccount *pOldAccount)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pAccount	�Ѿ�ɾ����CAccount
	virtual void commitRemove(CWriteableAccount *pAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CAccountIterator��һ�����ʽ��˻���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountIterator
{
public:
	///���췽��
	CAccountIterator(void)
	{
	}

	///���췽��
	CAccountIterator(CAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CAccountIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Account
	///@return	��һ����������CAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CAccount *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableAccount * pAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserCommFlux��һ���洢�û�ͨѶ���Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserCommFlux
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! MaxCommFlux.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableUserCommFlux *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�����û�����
	CUserIDType UserID;
	///���ͨѶ��
	CCommFluxType MaxCommFlux;
	unsigned int HashUserID;
	
	///����UserID��hashֵ
	void calHashUserID(void)
	{
		unsigned key=0;
		key=UserID.hash(key);
		HashUserID=key;
	}
	
	///������Ҫ���������UserID��hashֵ
	void updateHashUserID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashUserID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashUserID();
	}
	

private:
};

typedef const CWriteableUserCommFlux CUserCommFlux;

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxActionTrigger�ǲ����û�ͨѶ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxActionTrigger
{
public:
	///���췽��
	CUserCommFluxActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserCommFluxActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserCommFluxFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pUserCommFlux	Ҫ�����UserCommFlux
	virtual void beforeAdd(CWriteableUserCommFlux *pUserCommFlux)
	{
		return;
	}
	
	///����󴥷�
	///@param	pUserCommFlux	�Ѿ������UserCommFlux
	virtual void afterAdd(CUserCommFlux *pUserCommFlux)
	{
		return;
	}

	///����ǰ����	
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	///@param	pNewUserCommFlux	�µ�ֵ
	virtual void beforeUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	virtual void afterUpdate(CUserCommFlux *pUserCommFlux)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pUserCommFlux	Ҫɾ����CUserCommFlux
	virtual void beforeRemove(CUserCommFlux *pUserCommFlux)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserCommFluxFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxCommitTrigger��ȷ���û�ͨѶ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxCommitTrigger
{
public:
	///���췽��
	CUserCommFluxCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserCommFluxCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserCommFluxFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pUserCommFlux	�Ѿ������UserCommFlux
	virtual void commitAdd(CUserCommFlux *pUserCommFlux)
	{
		return;
	}

	///���º󴥷�
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	///@param	poldUserCommFlux	ԭ����ֵ
	virtual void commitUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pOldUserCommFlux)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pUserCommFlux	�Ѿ�ɾ����CUserCommFlux
	virtual void commitRemove(CWriteableUserCommFlux *pUserCommFlux)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserCommFluxFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxIterator��һ�����û�ͨѶ����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxIterator
{
public:
	///���췽��
	CUserCommFluxIterator(void)
	{
	}

	///���췽��
	CUserCommFluxIterator(CUserCommFluxFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserCommFluxIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��UserCommFlux
	///@return	��һ����������CUserCommFlux������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserCommFlux *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CUserCommFluxFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserCommFlux ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserCommFlux * pUserCommFlux,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CUserCommFluxFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketDataLog��һ���洢������ˮ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketDataLog
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! MarketDataLogNo.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMarketDataLog *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������ˮ���
	CSequenceNoType MarketDataLogNo;
	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///���¼�
	CPriceType LastPrice;
	///�����
	CPriceType PreSettlementPrice;
	///������
	CPriceType PreClosePrice;
	///��ֲ���
	CLargeVolumeType PreOpenInterest;
	///����
	CPriceType OpenPrice;
	///��߼�
	CPriceType HighestPrice;
	///��ͼ�
	CPriceType LowestPrice;
	///����
	CVolumeType Volume;
	///�ɽ����
	CMoneyType Turnover;
	///�ֲ���
	CLargeVolumeType OpenInterest;
	///������
	CPriceType ClosePrice;
	///�����
	CPriceType SettlementPrice;
	///��ͣ���
	CPriceType UpperLimitPrice;
	///��ͣ���
	CPriceType LowerLimitPrice;
	///����ʵ��
	CRatioType PreDelta;
	///����ʵ��
	CRatioType CurrDelta;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����޸ĺ���
	CMillisecType UpdateMillisec;
	///��Լ����
	CInstrumentIDType InstrumentID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketDataLog CMarketDataLog;

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogActionTrigger�ǲ���������ˮʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogActionTrigger
{
public:
	///���췽��
	CMarketDataLogActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataLogActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataLogFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMarketDataLog	Ҫ�����MarketDataLog
	virtual void beforeAdd(CWriteableMarketDataLog *pMarketDataLog)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMarketDataLog	�Ѿ������MarketDataLog
	virtual void afterAdd(CMarketDataLog *pMarketDataLog)
	{
		return;
	}

	///����ǰ����	
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	///@param	pNewMarketDataLog	�µ�ֵ
	virtual void beforeUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	virtual void afterUpdate(CMarketDataLog *pMarketDataLog)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMarketDataLog	Ҫɾ����CMarketDataLog
	virtual void beforeRemove(CMarketDataLog *pMarketDataLog)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataLogFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogCommitTrigger��ȷ��������ˮʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogCommitTrigger
{
public:
	///���췽��
	CMarketDataLogCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataLogCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataLogFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMarketDataLog	�Ѿ������MarketDataLog
	virtual void commitAdd(CMarketDataLog *pMarketDataLog)
	{
		return;
	}

	///���º󴥷�
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	///@param	poldMarketDataLog	ԭ����ֵ
	virtual void commitUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pOldMarketDataLog)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMarketDataLog	�Ѿ�ɾ����CMarketDataLog
	virtual void commitRemove(CWriteableMarketDataLog *pMarketDataLog)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataLogFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogIterator��һ����������ˮ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogIterator
{
public:
	///���췽��
	CMarketDataLogIterator(void)
	{
	}

	///���췽��
	CMarketDataLogIterator(CMarketDataLogFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataLogIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MarketDataLog
	///@return	��һ����������CMarketDataLog������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataLog *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMarketDataLogFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataLog ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataLog * pMarketDataLog,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMarketDataLogFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUserSession��һ���洢����Ա���߻Ự�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUserSession
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! FrontID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! SessionID.isValid())
			return 0;
		if (! LoginTime.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! UserProductInfo.isValid())
			return 0;
		if (! InterfaceProductInfo.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! SessionType.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableUserSession *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ǰ�ñ��
	CFrontIDType FrontID;
	///�����û�����
	CUserIDType UserID;
	///�����û�����
	CUserTypeType UserType;
	///�Ự���
	CSessionIDType SessionID;
	///��¼ʱ��
	CTimeType LoginTime;
	///��Ա����
	CParticipantIDType ParticipantID;
	///IP��ַ
	CIPAddressType IPAddress;
	///�û��˲�Ʒ��Ϣ
	CProductInfoType UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	CProductInfoType InterfaceProductInfo;
	///Э����Ϣ
	CProtocolInfoType ProtocolInfo;
	///�Ự����
	CSessionTypeType SessionType;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�Ľ���Ա��ָ��
	///@param	pFactory	�����Ӧ�Ľ���Ա��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ľ���Ա��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableUser *linkUser(CUserFactory *pFactory) const;

	///�����Ӧ�Ľ���Աָ��
	///@param	pUser	Ҫ���ӵ��Ķ���
	///@return	�����pUser
	const CWriteableUser *linkUser(const CWriteableUser *pUser) const
	{
		void *target=(void *)(&(this->pUser));
		*((const CWriteableUser **)target)=pUser;
		return pUser;
	}
	
	///��ȡ��Ӧ�Ľ���Ա��ָ��
	///@return	�ҵ��Ķ�Ӧ�Ľ���Ա��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableUser *getUser(void) const
	{
		return pUser;
	}

private:
	///��Ӧ�Ľ���Ա
	const CWriteableUser *pUser;
};

typedef const CWriteableUserSession CUserSession;

/////////////////////////////////////////////////////////////////////////
///CUserSessionActionTrigger�ǲ�������Ա���߻Ựʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionActionTrigger
{
public:
	///���췽��
	CUserSessionActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserSessionActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pUserSession	Ҫ�����UserSession
	virtual void beforeAdd(CWriteableUserSession *pUserSession)
	{
		return;
	}
	
	///����󴥷�
	///@param	pUserSession	�Ѿ������UserSession
	virtual void afterAdd(CUserSession *pUserSession)
	{
		return;
	}

	///����ǰ����	
	///@param	pUserSession	��ˢ�µ�CUserSession
	///@param	pNewUserSession	�µ�ֵ
	virtual void beforeUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pUserSession	��ˢ�µ�CUserSession
	virtual void afterUpdate(CUserSession *pUserSession)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pUserSession	Ҫɾ����CUserSession
	virtual void beforeRemove(CUserSession *pUserSession)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionCommitTrigger��ȷ�Ͻ���Ա���߻Ựʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionCommitTrigger
{
public:
	///���췽��
	CUserSessionCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CUserSessionCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUserSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pUserSession	�Ѿ������UserSession
	virtual void commitAdd(CUserSession *pUserSession)
	{
		return;
	}

	///���º󴥷�
	///@param	pUserSession	��ˢ�µ�CUserSession
	///@param	poldUserSession	ԭ����ֵ
	virtual void commitUpdate(CUserSession *pUserSession, CWriteableUserSession *pOldUserSession)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pUserSession	�Ѿ�ɾ����CUserSession
	virtual void commitRemove(CWriteableUserSession *pUserSession)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUserSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionIterator��һ���Խ���Ա���߻Ự��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionIterator
{
public:
	///���췽��
	CUserSessionIterator(void)
	{
	}

	///���췽��
	CUserSessionIterator(CUserSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserSessionIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��UserSession
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUserSession *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CUserSessionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUserSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUserSession * pUserSession,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CUserSessionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMDSession��һ���洢���鶩�������߻Ự�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMDSession
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! FrontID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! SessionID.isValid())
			return 0;
		if (! LoginTime.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! UserProductInfo.isValid())
			return 0;
		if (! InterfaceProductInfo.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! SessionType.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMDSession *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ǰ�ñ��
	CFrontIDType FrontID;
	///�����û�����
	CUserIDType UserID;
	///�����û�����
	CUserTypeType UserType;
	///�Ự���
	CSessionIDType SessionID;
	///��¼ʱ��
	CTimeType LoginTime;
	///��Ա����
	CParticipantIDType ParticipantID;
	///IP��ַ
	CIPAddressType IPAddress;
	///�û��˲�Ʒ��Ϣ
	CProductInfoType UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	CProductInfoType InterfaceProductInfo;
	///Э����Ϣ
	CProtocolInfoType ProtocolInfo;
	///�Ự����
	CSessionTypeType SessionType;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMDSession CMDSession;

/////////////////////////////////////////////////////////////////////////
///CMDSessionActionTrigger�ǲ������鶩�������߻Ựʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionActionTrigger
{
public:
	///���췽��
	CMDSessionActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMDSessionActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMDSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMDSession	Ҫ�����MDSession
	virtual void beforeAdd(CWriteableMDSession *pMDSession)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMDSession	�Ѿ������MDSession
	virtual void afterAdd(CMDSession *pMDSession)
	{
		return;
	}

	///����ǰ����	
	///@param	pMDSession	��ˢ�µ�CMDSession
	///@param	pNewMDSession	�µ�ֵ
	virtual void beforeUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMDSession	��ˢ�µ�CMDSession
	virtual void afterUpdate(CMDSession *pMDSession)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMDSession	Ҫɾ����CMDSession
	virtual void beforeRemove(CMDSession *pMDSession)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMDSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionCommitTrigger��ȷ�����鶩�������߻Ựʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionCommitTrigger
{
public:
	///���췽��
	CMDSessionCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMDSessionCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMDSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMDSession	�Ѿ������MDSession
	virtual void commitAdd(CMDSession *pMDSession)
	{
		return;
	}

	///���º󴥷�
	///@param	pMDSession	��ˢ�µ�CMDSession
	///@param	poldMDSession	ԭ����ֵ
	virtual void commitUpdate(CMDSession *pMDSession, CWriteableMDSession *pOldMDSession)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMDSession	�Ѿ�ɾ����CMDSession
	virtual void commitRemove(CWriteableMDSession *pMDSession)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMDSessionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionIterator��һ�������鶩�������߻Ự��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionIterator
{
public:
	///���췽��
	CMDSessionIterator(void)
	{
	}

	///���췽��
	CMDSessionIterator(CMDSessionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMDSessionIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MDSession
	///@return	��һ����������CMDSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMDSession *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMDSessionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMDSession ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMDSession * pMDSession,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMDSessionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableLoginInfo��һ���洢�û���½�ǳ���Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableLoginInfo
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserProductInfo.isValid())
			return 0;
		if (! InterfaceProductInfo.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! LoginType.isValid())
			return 0;
		if (! SessionType.isValid())
			return 0;
		if (! ErrorID.isValid())
			return 0;
		if (! UpdateDate.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableLoginInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���
	CSequenceNoType SequenceNo;
	///�����û�����
	CUserIDType UserID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�û��˲�Ʒ��Ϣ
	CProductInfoType UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	CProductInfoType InterfaceProductInfo;
	///Э����Ϣ
	CProtocolInfoType ProtocolInfo;
	///IP��ַ
	CIPAddressType IPAddress;
	///��¼����
	CLoginTypeType LoginType;
	///�Ự����
	CSessionTypeType SessionType;
	///�������
	CErrorIDType ErrorID;
	///��������
	CDateType UpdateDate;
	///����ʱ��
	CTimeType UpdateTime;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableLoginInfo CLoginInfo;

/////////////////////////////////////////////////////////////////////////
///CLoginInfoActionTrigger�ǲ����û���½�ǳ���Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoActionTrigger
{
public:
	///���췽��
	CLoginInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CLoginInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pLoginInfo	Ҫ�����LoginInfo
	virtual void beforeAdd(CWriteableLoginInfo *pLoginInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pLoginInfo	�Ѿ������LoginInfo
	virtual void afterAdd(CLoginInfo *pLoginInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	///@param	pNewLoginInfo	�µ�ֵ
	virtual void beforeUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	virtual void afterUpdate(CLoginInfo *pLoginInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pLoginInfo	Ҫɾ����CLoginInfo
	virtual void beforeRemove(CLoginInfo *pLoginInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoCommitTrigger��ȷ���û���½�ǳ���Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoCommitTrigger
{
public:
	///���췽��
	CLoginInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CLoginInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pLoginInfo	�Ѿ������LoginInfo
	virtual void commitAdd(CLoginInfo *pLoginInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	///@param	poldLoginInfo	ԭ����ֵ
	virtual void commitUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pOldLoginInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pLoginInfo	�Ѿ�ɾ����CLoginInfo
	virtual void commitRemove(CWriteableLoginInfo *pLoginInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoIterator��һ�����û���½�ǳ���Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoIterator
{
public:
	///���췽��
	CLoginInfoIterator(void)
	{
	}

	///���췽��
	CLoginInfoIterator(CLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CLoginInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��LoginInfo
	///@return	��һ����������CLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CLoginInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CLoginInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableLoginInfo * pLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CLoginInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableDepthMarketDataDetail��һ���洢����г�������ϸ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableDepthMarketDataDetail
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableDepthMarketDataDetail *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///���¼�
	CPriceType LastPrice;
	///�����
	CPriceType PreSettlementPrice;
	///������
	CPriceType PreClosePrice;
	///��ֲ���
	CLargeVolumeType PreOpenInterest;
	///����
	CPriceType OpenPrice;
	///��߼�
	CPriceType HighestPrice;
	///��ͼ�
	CPriceType LowestPrice;
	///����
	CVolumeType Volume;
	///�ɽ����
	CMoneyType Turnover;
	///�ֲ���
	CLargeVolumeType OpenInterest;
	///������
	CPriceType ClosePrice;
	///�����
	CPriceType SettlementPrice;
	///��ͣ���
	CPriceType UpperLimitPrice;
	///��ͣ���
	CPriceType LowerLimitPrice;
	///����ʵ��
	CRatioType PreDelta;
	///����ʵ��
	CRatioType CurrDelta;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����޸ĺ���
	CMillisecType UpdateMillisec;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�����һ
	CPriceType BidPrice1;
	///������һ
	CVolumeType BidVolume1;
	///������һ
	CPriceType AskPrice1;
	///������һ
	CVolumeType AskVolume1;
	///����۶�
	CPriceType BidPrice2;
	///��������
	CVolumeType BidVolume2;
	///�����۶�
	CPriceType AskPrice2;
	///��������
	CVolumeType AskVolume2;
	///�������
	CPriceType BidPrice3;
	///��������
	CVolumeType BidVolume3;
	///��������
	CPriceType AskPrice3;
	///��������
	CVolumeType AskVolume3;
	///�������
	CPriceType BidPrice4;
	///��������
	CVolumeType BidVolume4;
	///��������
	CPriceType AskPrice4;
	///��������
	CVolumeType AskVolume4;
	///�������
	CPriceType BidPrice5;
	///��������
	CVolumeType BidVolume5;
	///��������
	CPriceType AskPrice5;
	///��������
	CVolumeType AskVolume5;
	///���
	CSequenceNoType SequenceNo;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableDepthMarketDataDetail CDepthMarketDataDetail;

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailActionTrigger�ǲ�������г�������ϸʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailActionTrigger
{
public:
	///���췽��
	CDepthMarketDataDetailActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CDepthMarketDataDetailActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CDepthMarketDataDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pDepthMarketDataDetail	Ҫ�����DepthMarketDataDetail
	virtual void beforeAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
	
	///����󴥷�
	///@param	pDepthMarketDataDetail	�Ѿ������DepthMarketDataDetail
	virtual void afterAdd(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}

	///����ǰ����	
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	�µ�ֵ
	virtual void beforeUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	virtual void afterUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pDepthMarketDataDetail	Ҫɾ����CDepthMarketDataDetail
	virtual void beforeRemove(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CDepthMarketDataDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailCommitTrigger��ȷ������г�������ϸʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailCommitTrigger
{
public:
	///���췽��
	CDepthMarketDataDetailCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CDepthMarketDataDetailCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CDepthMarketDataDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pDepthMarketDataDetail	�Ѿ������DepthMarketDataDetail
	virtual void commitAdd(CDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}

	///���º󴥷�
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	///@param	poldDepthMarketDataDetail	ԭ����ֵ
	virtual void commitUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pOldDepthMarketDataDetail)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pDepthMarketDataDetail	�Ѿ�ɾ����CDepthMarketDataDetail
	virtual void commitRemove(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CDepthMarketDataDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailIterator��һ��������г�������ϸ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailIterator
{
public:
	///���췽��
	CDepthMarketDataDetailIterator(void)
	{
	}

	///���췽��
	CDepthMarketDataDetailIterator(CDepthMarketDataDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDepthMarketDataDetailIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��DepthMarketDataDetail
	///@return	��һ����������CDepthMarketDataDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketDataDetail *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CDepthMarketDataDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketDataDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketDataDetail * pDepthMarketDataDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CDepthMarketDataDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInstrumentStatusDetail��һ���洢��Լ����״̬��ˮ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInstrumentStatusDetail
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		if (! EnterTime.isValid())
			return 0;
		if (! EnterReason.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableInstrumentStatusDetail *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Լ����״̬
	CInstrumentStatusType InstrumentStatus;
	///���׽׶α��
	CTradingSegmentSNType TradingSegmentSN;
	///���뱾״̬ʱ��
	CTimeType EnterTime;
	///���뱾״̬ԭ��
	CInstStatusEnterReasonType EnterReason;
	///������
	CSettlementIDType SettlementID;
	///���к�
	CSequenceNoType SequenceNo;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableInstrumentStatusDetail CInstrumentStatusDetail;

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailActionTrigger�ǲ�����Լ����״̬��ˮʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailActionTrigger
{
public:
	///���췽��
	CInstrumentStatusDetailActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CInstrumentStatusDetailActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInstrumentStatusDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pInstrumentStatusDetail	Ҫ�����InstrumentStatusDetail
	virtual void beforeAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
	
	///����󴥷�
	///@param	pInstrumentStatusDetail	�Ѿ������InstrumentStatusDetail
	virtual void afterAdd(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}

	///����ǰ����	
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	�µ�ֵ
	virtual void beforeUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	virtual void afterUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pInstrumentStatusDetail	Ҫɾ����CInstrumentStatusDetail
	virtual void beforeRemove(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInstrumentStatusDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailCommitTrigger��ȷ�Ϻ�Լ����״̬��ˮʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailCommitTrigger
{
public:
	///���췽��
	CInstrumentStatusDetailCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CInstrumentStatusDetailCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInstrumentStatusDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pInstrumentStatusDetail	�Ѿ������InstrumentStatusDetail
	virtual void commitAdd(CInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}

	///���º󴥷�
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	///@param	poldInstrumentStatusDetail	ԭ����ֵ
	virtual void commitUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pOldInstrumentStatusDetail)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pInstrumentStatusDetail	�Ѿ�ɾ����CInstrumentStatusDetail
	virtual void commitRemove(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInstrumentStatusDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailIterator��һ���Ժ�Լ����״̬��ˮ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailIterator
{
public:
	///���췽��
	CInstrumentStatusDetailIterator(void)
	{
	}

	///���췽��
	CInstrumentStatusDetailIterator(CInstrumentStatusDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentStatusDetailIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��InstrumentStatusDetail
	///@return	��һ����������CInstrumentStatusDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatusDetail *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CInstrumentStatusDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatusDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatusDetail * pInstrumentStatusDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CInstrumentStatusDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableFrontStatus��һ���洢ǰ��״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableFrontStatus
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! FrontID.isValid())
			return 0;
		if (! LastReportTime.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableFrontStatus *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ǰ�ñ��
	CFrontIDType FrontID;
	///�ϴα���ʱ��
	CTimeType LastReportTime;
	///�Ƿ��Ծ
	CBoolType IsActive;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableFrontStatus CFrontStatus;

/////////////////////////////////////////////////////////////////////////
///CFrontStatusActionTrigger�ǲ���ǰ��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusActionTrigger
{
public:
	///���췽��
	CFrontStatusActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CFrontStatusActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CFrontStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pFrontStatus	Ҫ�����FrontStatus
	virtual void beforeAdd(CWriteableFrontStatus *pFrontStatus)
	{
		return;
	}
	
	///����󴥷�
	///@param	pFrontStatus	�Ѿ������FrontStatus
	virtual void afterAdd(CFrontStatus *pFrontStatus)
	{
		return;
	}

	///����ǰ����	
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	///@param	pNewFrontStatus	�µ�ֵ
	virtual void beforeUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	virtual void afterUpdate(CFrontStatus *pFrontStatus)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pFrontStatus	Ҫɾ����CFrontStatus
	virtual void beforeRemove(CFrontStatus *pFrontStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CFrontStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusCommitTrigger��ȷ��ǰ��״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusCommitTrigger
{
public:
	///���췽��
	CFrontStatusCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CFrontStatusCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CFrontStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pFrontStatus	�Ѿ������FrontStatus
	virtual void commitAdd(CFrontStatus *pFrontStatus)
	{
		return;
	}

	///���º󴥷�
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	///@param	poldFrontStatus	ԭ����ֵ
	virtual void commitUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pOldFrontStatus)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pFrontStatus	�Ѿ�ɾ����CFrontStatus
	virtual void commitRemove(CWriteableFrontStatus *pFrontStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CFrontStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusIterator��һ����ǰ��״̬��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusIterator
{
public:
	///���췽��
	CFrontStatusIterator(void)
	{
	}

	///���췽��
	CFrontStatusIterator(CFrontStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CFrontStatusIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��FrontStatus
	///@return	��һ����������CFrontStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFrontStatus *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CFrontStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFrontStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFrontStatus * pFrontStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CFrontStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMaxLocalID��һ���洢��󱾵ر����ŵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMaxLocalID
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! UserID.isValid())
			return 0;
		if (! MaxOrderLocalID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMaxLocalID *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�����û�����
	CUserIDType UserID;
	///��󱨵����ر��
	COrderLocalIDType MaxOrderLocalID;
	unsigned int HashUserID;
	
	///����UserID��hashֵ
	void calHashUserID(void)
	{
		unsigned key=0;
		key=UserID.hash(key);
		HashUserID=key;
	}
	
	///������Ҫ���������UserID��hashֵ
	void updateHashUserID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashUserID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashUserID();
	}
	

private:
};

typedef const CWriteableMaxLocalID CMaxLocalID;

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDActionTrigger�ǲ�����󱾵ر�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDActionTrigger
{
public:
	///���췽��
	CMaxLocalIDActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMaxLocalIDActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMaxLocalIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMaxLocalID	Ҫ�����MaxLocalID
	virtual void beforeAdd(CWriteableMaxLocalID *pMaxLocalID)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMaxLocalID	�Ѿ������MaxLocalID
	virtual void afterAdd(CMaxLocalID *pMaxLocalID)
	{
		return;
	}

	///����ǰ����	
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	///@param	pNewMaxLocalID	�µ�ֵ
	virtual void beforeUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	virtual void afterUpdate(CMaxLocalID *pMaxLocalID)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMaxLocalID	Ҫɾ����CMaxLocalID
	virtual void beforeRemove(CMaxLocalID *pMaxLocalID)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMaxLocalIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDCommitTrigger��ȷ����󱾵ر�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDCommitTrigger
{
public:
	///���췽��
	CMaxLocalIDCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMaxLocalIDCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMaxLocalIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMaxLocalID	�Ѿ������MaxLocalID
	virtual void commitAdd(CMaxLocalID *pMaxLocalID)
	{
		return;
	}

	///���º󴥷�
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	///@param	poldMaxLocalID	ԭ����ֵ
	virtual void commitUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pOldMaxLocalID)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMaxLocalID	�Ѿ�ɾ����CMaxLocalID
	virtual void commitRemove(CWriteableMaxLocalID *pMaxLocalID)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMaxLocalIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDIterator��һ������󱾵ر����ŵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDIterator
{
public:
	///���췽��
	CMaxLocalIDIterator(void)
	{
	}

	///���췽��
	CMaxLocalIDIterator(CMaxLocalIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMaxLocalIDIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MaxLocalID
	///@return	��һ����������CMaxLocalID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMaxLocalID *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMaxLocalIDFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMaxLocalID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMaxLocalID * pMaxLocalID,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMaxLocalIDFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableBulletin��һ���洢������Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableBulletin
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! BulletinID.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		if (! NewsType.isValid())
			return 0;
		if (! NewsUrgency.isValid())
			return 0;
		if (! SendTime.isValid())
			return 0;
		if (! Abstract.isValid())
			return 0;
		if (! ComeFrom.isValid())
			return 0;
		if (! Content.isValid())
			return 0;
		if (! URLLink.isValid())
			return 0;
		if (! MarketID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableBulletin *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///������
	CBulletinIDType BulletinID;
	///���к�
	CSequenceNoType SequenceNo;
	///��������
	CNewsTypeType NewsType;
	///�����̶�
	CNewsUrgencyType NewsUrgency;
	///����ʱ��
	CTimeType SendTime;
	///��ϢժҪ
	CAbstractType Abstract;
	///��Ϣ��Դ
	CComeFromType ComeFrom;
	///��Ϣ����
	CContentType Content;
	///WEB��ַ
	CURLLinkType URLLink;
	///�г�����
	CMarketIDType MarketID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableBulletin CBulletin;

/////////////////////////////////////////////////////////////////////////
///CBulletinActionTrigger�ǲ���������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinActionTrigger
{
public:
	///���췽��
	CBulletinActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CBulletinActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CBulletinFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pBulletin	Ҫ�����Bulletin
	virtual void beforeAdd(CWriteableBulletin *pBulletin)
	{
		return;
	}
	
	///����󴥷�
	///@param	pBulletin	�Ѿ������Bulletin
	virtual void afterAdd(CBulletin *pBulletin)
	{
		return;
	}

	///����ǰ����	
	///@param	pBulletin	��ˢ�µ�CBulletin
	///@param	pNewBulletin	�µ�ֵ
	virtual void beforeUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pBulletin	��ˢ�µ�CBulletin
	virtual void afterUpdate(CBulletin *pBulletin)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pBulletin	Ҫɾ����CBulletin
	virtual void beforeRemove(CBulletin *pBulletin)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CBulletinFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinCommitTrigger��ȷ�Ϲ�����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinCommitTrigger
{
public:
	///���췽��
	CBulletinCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CBulletinCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CBulletinFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pBulletin	�Ѿ������Bulletin
	virtual void commitAdd(CBulletin *pBulletin)
	{
		return;
	}

	///���º󴥷�
	///@param	pBulletin	��ˢ�µ�CBulletin
	///@param	poldBulletin	ԭ����ֵ
	virtual void commitUpdate(CBulletin *pBulletin, CWriteableBulletin *pOldBulletin)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pBulletin	�Ѿ�ɾ����CBulletin
	virtual void commitRemove(CWriteableBulletin *pBulletin)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CBulletinFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinIterator��һ���Թ�����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinIterator
{
public:
	///���췽��
	CBulletinIterator(void)
	{
	}

	///���췽��
	CBulletinIterator(CBulletinFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBulletinIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Bulletin
	///@return	��һ����������CBulletin������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBulletin *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CBulletinFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBulletin ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBulletin * pBulletin,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CBulletinFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketDataModify��һ���洢����䶯�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketDataModify
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ModifySequence.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMarketDataModify *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///����䶯���
	CSequenceNoType ModifySequence;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ����������ָ��
	///@param	pFactory	�����Ӧ����������ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ����������ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableDepthMarketData *linkDepthMarketData(CDepthMarketDataFactory *pFactory) const;

	///�����Ӧ���������ָ��
	///@param	pDepthMarketData	Ҫ���ӵ��Ķ���
	///@return	�����pDepthMarketData
	const CWriteableDepthMarketData *linkDepthMarketData(const CWriteableDepthMarketData *pDepthMarketData) const
	{
		void *target=(void *)(&(this->pDepthMarketData));
		*((const CWriteableDepthMarketData **)target)=pDepthMarketData;
		return pDepthMarketData;
	}
	
	///��ȡ��Ӧ����������ָ��
	///@return	�ҵ��Ķ�Ӧ����������ָ�룬����Ҳ����򷵻�NULL
	const CWriteableDepthMarketData *getDepthMarketData(void) const
	{
		return pDepthMarketData;
	}

private:
	///��Ӧ���������
	const CWriteableDepthMarketData *pDepthMarketData;
};

typedef const CWriteableMarketDataModify CMarketDataModify;

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyActionTrigger�ǲ�������䶯ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyActionTrigger
{
public:
	///���췽��
	CMarketDataModifyActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataModifyActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataModifyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMarketDataModify	Ҫ�����MarketDataModify
	virtual void beforeAdd(CWriteableMarketDataModify *pMarketDataModify)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMarketDataModify	�Ѿ������MarketDataModify
	virtual void afterAdd(CMarketDataModify *pMarketDataModify)
	{
		return;
	}

	///����ǰ����	
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	///@param	pNewMarketDataModify	�µ�ֵ
	virtual void beforeUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	virtual void afterUpdate(CMarketDataModify *pMarketDataModify)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMarketDataModify	Ҫɾ����CMarketDataModify
	virtual void beforeRemove(CMarketDataModify *pMarketDataModify)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataModifyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyCommitTrigger��ȷ������䶯ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyCommitTrigger
{
public:
	///���췽��
	CMarketDataModifyCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataModifyCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataModifyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMarketDataModify	�Ѿ������MarketDataModify
	virtual void commitAdd(CMarketDataModify *pMarketDataModify)
	{
		return;
	}

	///���º󴥷�
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	///@param	poldMarketDataModify	ԭ����ֵ
	virtual void commitUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pOldMarketDataModify)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMarketDataModify	�Ѿ�ɾ����CMarketDataModify
	virtual void commitRemove(CWriteableMarketDataModify *pMarketDataModify)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataModifyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyIterator��һ��������䶯��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyIterator
{
public:
	///���췽��
	CMarketDataModifyIterator(void)
	{
	}

	///���췽��
	CMarketDataModifyIterator(CMarketDataModifyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataModifyIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MarketDataModify
	///@return	��һ����������CMarketDataModify������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketDataModify *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMarketDataModifyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketDataModify ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketDataModify * pMarketDataModify,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMarketDataModifyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableDepthMarketData��һ���洢�������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableDepthMarketData
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableDepthMarketData *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///���¼�
	CPriceType LastPrice;
	///�����
	CPriceType PreSettlementPrice;
	///������
	CPriceType PreClosePrice;
	///��ֲ���
	CLargeVolumeType PreOpenInterest;
	///����
	CPriceType OpenPrice;
	///��߼�
	CPriceType HighestPrice;
	///��ͼ�
	CPriceType LowestPrice;
	///����
	CVolumeType Volume;
	///�ɽ����
	CMoneyType Turnover;
	///�ֲ���
	CLargeVolumeType OpenInterest;
	///������
	CPriceType ClosePrice;
	///�����
	CPriceType SettlementPrice;
	///��ͣ���
	CPriceType UpperLimitPrice;
	///��ͣ���
	CPriceType LowerLimitPrice;
	///����ʵ��
	CRatioType PreDelta;
	///����ʵ��
	CRatioType CurrDelta;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����޸ĺ���
	CMillisecType UpdateMillisec;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�����һ
	CPriceType BidPrice1;
	///������һ
	CVolumeType BidVolume1;
	///������һ
	CPriceType AskPrice1;
	///������һ
	CVolumeType AskVolume1;
	///����۶�
	CPriceType BidPrice2;
	///��������
	CVolumeType BidVolume2;
	///�����۶�
	CPriceType AskPrice2;
	///��������
	CVolumeType AskVolume2;
	///�������
	CPriceType BidPrice3;
	///��������
	CVolumeType BidVolume3;
	///��������
	CPriceType AskPrice3;
	///��������
	CVolumeType AskVolume3;
	///�������
	CPriceType BidPrice4;
	///��������
	CVolumeType BidVolume4;
	///��������
	CPriceType AskPrice4;
	///��������
	CVolumeType AskVolume4;
	///�������
	CPriceType BidPrice5;
	///��������
	CVolumeType BidVolume5;
	///��������
	CPriceType AskPrice5;
	///��������
	CVolumeType AskVolume5;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableDepthMarketData CDepthMarketData;

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataActionTrigger�ǲ����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataActionTrigger
{
public:
	///���췽��
	CDepthMarketDataActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CDepthMarketDataActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CDepthMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pDepthMarketData	Ҫ�����DepthMarketData
	virtual void beforeAdd(CWriteableDepthMarketData *pDepthMarketData)
	{
		return;
	}
	
	///����󴥷�
	///@param	pDepthMarketData	�Ѿ������DepthMarketData
	virtual void afterAdd(CDepthMarketData *pDepthMarketData)
	{
		return;
	}

	///����ǰ����	
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	///@param	pNewDepthMarketData	�µ�ֵ
	virtual void beforeUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	virtual void afterUpdate(CDepthMarketData *pDepthMarketData)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pDepthMarketData	Ҫɾ����CDepthMarketData
	virtual void beforeRemove(CDepthMarketData *pDepthMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CDepthMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataCommitTrigger��ȷ���������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataCommitTrigger
{
public:
	///���췽��
	CDepthMarketDataCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CDepthMarketDataCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CDepthMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pDepthMarketData	�Ѿ������DepthMarketData
	virtual void commitAdd(CDepthMarketData *pDepthMarketData)
	{
		return;
	}

	///���º󴥷�
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	///@param	poldDepthMarketData	ԭ����ֵ
	virtual void commitUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pOldDepthMarketData)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pDepthMarketData	�Ѿ�ɾ����CDepthMarketData
	virtual void commitRemove(CWriteableDepthMarketData *pDepthMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CDepthMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataIterator��һ������������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataIterator
{
public:
	///���췽��
	CDepthMarketDataIterator(void)
	{
	}

	///���췽��
	CDepthMarketDataIterator(CDepthMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDepthMarketDataIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��DepthMarketData
	///@return	��һ����������CDepthMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CDepthMarketData *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CDepthMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pDepthMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableDepthMarketData * pDepthMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CDepthMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTopicMarketData��һ���洢����������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTopicMarketData
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TopicID.isValid())
			return 0;
		if (! SnapShotFeq.isValid())
			return 0;
		if (! MarketDataDepth.isValid())
			return 0;
		if (! MarketDataMode.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableTopicMarketData *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�������
	CTopicIDType TopicID;
	///����Ƶ��
	CSecondsType SnapShotFeq;
	///�г��������
	CMarketDataDepthType MarketDataDepth;
	///����ģʽ
	CMarketDataModeType MarketDataMode;
	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///���¼�
	CPriceType LastPrice;
	///�����
	CPriceType PreSettlementPrice;
	///������
	CPriceType PreClosePrice;
	///��ֲ���
	CLargeVolumeType PreOpenInterest;
	///����
	CPriceType OpenPrice;
	///��߼�
	CPriceType HighestPrice;
	///��ͼ�
	CPriceType LowestPrice;
	///����
	CVolumeType Volume;
	///�ɽ����
	CMoneyType Turnover;
	///�ֲ���
	CLargeVolumeType OpenInterest;
	///������
	CPriceType ClosePrice;
	///�����
	CPriceType SettlementPrice;
	///��ͣ���
	CPriceType UpperLimitPrice;
	///��ͣ���
	CPriceType LowerLimitPrice;
	///����ʵ��
	CRatioType PreDelta;
	///����ʵ��
	CRatioType CurrDelta;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����޸ĺ���
	CMillisecType UpdateMillisec;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�����һ
	CPriceType BidPrice1;
	///������һ
	CVolumeType BidVolume1;
	///������һ
	CPriceType AskPrice1;
	///������һ
	CVolumeType AskVolume1;
	///����۶�
	CPriceType BidPrice2;
	///��������
	CVolumeType BidVolume2;
	///�����۶�
	CPriceType AskPrice2;
	///��������
	CVolumeType AskVolume2;
	///�������
	CPriceType BidPrice3;
	///��������
	CVolumeType BidVolume3;
	///��������
	CPriceType AskPrice3;
	///��������
	CVolumeType AskVolume3;
	///�������
	CPriceType BidPrice4;
	///��������
	CVolumeType BidVolume4;
	///��������
	CPriceType AskPrice4;
	///��������
	CVolumeType AskVolume4;
	///�������
	CPriceType BidPrice5;
	///��������
	CVolumeType BidVolume5;
	///��������
	CPriceType AskPrice5;
	///��������
	CVolumeType AskVolume5;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableTopicMarketData CTopicMarketData;

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataActionTrigger�ǲ�������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataActionTrigger
{
public:
	///���췽��
	CTopicMarketDataActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CTopicMarketDataActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTopicMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pTopicMarketData	Ҫ�����TopicMarketData
	virtual void beforeAdd(CWriteableTopicMarketData *pTopicMarketData)
	{
		return;
	}
	
	///����󴥷�
	///@param	pTopicMarketData	�Ѿ������TopicMarketData
	virtual void afterAdd(CTopicMarketData *pTopicMarketData)
	{
		return;
	}

	///����ǰ����	
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	///@param	pNewTopicMarketData	�µ�ֵ
	virtual void beforeUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	virtual void afterUpdate(CTopicMarketData *pTopicMarketData)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pTopicMarketData	Ҫɾ����CTopicMarketData
	virtual void beforeRemove(CTopicMarketData *pTopicMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTopicMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataCommitTrigger��ȷ�Ϸ���������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataCommitTrigger
{
public:
	///���췽��
	CTopicMarketDataCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CTopicMarketDataCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTopicMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pTopicMarketData	�Ѿ������TopicMarketData
	virtual void commitAdd(CTopicMarketData *pTopicMarketData)
	{
		return;
	}

	///���º󴥷�
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	///@param	poldTopicMarketData	ԭ����ֵ
	virtual void commitUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pOldTopicMarketData)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pTopicMarketData	�Ѿ�ɾ����CTopicMarketData
	virtual void commitRemove(CWriteableTopicMarketData *pTopicMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTopicMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataIterator��һ���Է����������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataIterator
{
public:
	///���췽��
	CTopicMarketDataIterator(void)
	{
	}

	///���췽��
	CTopicMarketDataIterator(CTopicMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��TopicMarketData
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketData *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CTopicMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketData * pTopicMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CTopicMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTopicMarketDataVersion��һ���洢������������յĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTopicMarketDataVersion
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TopicID.isValid())
			return 0;
		if (! Version.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! BidPrice1.isValid())
			return 0;
		if (! BidVolume1.isValid())
			return 0;
		if (! AskPrice1.isValid())
			return 0;
		if (! AskVolume1.isValid())
			return 0;
		if (! BidPrice2.isValid())
			return 0;
		if (! BidVolume2.isValid())
			return 0;
		if (! AskPrice2.isValid())
			return 0;
		if (! AskVolume2.isValid())
			return 0;
		if (! BidPrice3.isValid())
			return 0;
		if (! BidVolume3.isValid())
			return 0;
		if (! AskPrice3.isValid())
			return 0;
		if (! AskVolume3.isValid())
			return 0;
		if (! BidPrice4.isValid())
			return 0;
		if (! BidVolume4.isValid())
			return 0;
		if (! AskPrice4.isValid())
			return 0;
		if (! AskVolume4.isValid())
			return 0;
		if (! BidPrice5.isValid())
			return 0;
		if (! BidVolume5.isValid())
			return 0;
		if (! AskPrice5.isValid())
			return 0;
		if (! AskVolume5.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableTopicMarketDataVersion *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�������
	CTopicIDType TopicID;
	///���հ汾
	CSequenceNoType Version;
	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///���¼�
	CPriceType LastPrice;
	///�����
	CPriceType PreSettlementPrice;
	///������
	CPriceType PreClosePrice;
	///��ֲ���
	CLargeVolumeType PreOpenInterest;
	///����
	CPriceType OpenPrice;
	///��߼�
	CPriceType HighestPrice;
	///��ͼ�
	CPriceType LowestPrice;
	///����
	CVolumeType Volume;
	///�ɽ����
	CMoneyType Turnover;
	///�ֲ���
	CLargeVolumeType OpenInterest;
	///������
	CPriceType ClosePrice;
	///�����
	CPriceType SettlementPrice;
	///��ͣ���
	CPriceType UpperLimitPrice;
	///��ͣ���
	CPriceType LowerLimitPrice;
	///����ʵ��
	CRatioType PreDelta;
	///����ʵ��
	CRatioType CurrDelta;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����޸ĺ���
	CMillisecType UpdateMillisec;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�����һ
	CPriceType BidPrice1;
	///������һ
	CVolumeType BidVolume1;
	///������һ
	CPriceType AskPrice1;
	///������һ
	CVolumeType AskVolume1;
	///����۶�
	CPriceType BidPrice2;
	///��������
	CVolumeType BidVolume2;
	///�����۶�
	CPriceType AskPrice2;
	///��������
	CVolumeType AskVolume2;
	///�������
	CPriceType BidPrice3;
	///��������
	CVolumeType BidVolume3;
	///��������
	CPriceType AskPrice3;
	///��������
	CVolumeType AskVolume3;
	///�������
	CPriceType BidPrice4;
	///��������
	CVolumeType BidVolume4;
	///��������
	CPriceType AskPrice4;
	///��������
	CVolumeType AskVolume4;
	///�������
	CPriceType BidPrice5;
	///��������
	CVolumeType BidVolume5;
	///��������
	CPriceType AskPrice5;
	///��������
	CVolumeType AskVolume5;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableTopicMarketDataVersion CTopicMarketDataVersion;

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionActionTrigger�ǲ����������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionActionTrigger
{
public:
	///���췽��
	CTopicMarketDataVersionActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CTopicMarketDataVersionActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTopicMarketDataVersionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pTopicMarketDataVersion	Ҫ�����TopicMarketDataVersion
	virtual void beforeAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
	
	///����󴥷�
	///@param	pTopicMarketDataVersion	�Ѿ������TopicMarketDataVersion
	virtual void afterAdd(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}

	///����ǰ����	
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	�µ�ֵ
	virtual void beforeUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	virtual void afterUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pTopicMarketDataVersion	Ҫɾ����CTopicMarketDataVersion
	virtual void beforeRemove(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTopicMarketDataVersionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionCommitTrigger��ȷ�Ϸ������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionCommitTrigger
{
public:
	///���췽��
	CTopicMarketDataVersionCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CTopicMarketDataVersionCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTopicMarketDataVersionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pTopicMarketDataVersion	�Ѿ������TopicMarketDataVersion
	virtual void commitAdd(CTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}

	///���º󴥷�
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	///@param	poldTopicMarketDataVersion	ԭ����ֵ
	virtual void commitUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pOldTopicMarketDataVersion)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pTopicMarketDataVersion	�Ѿ�ɾ����CTopicMarketDataVersion
	virtual void commitRemove(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTopicMarketDataVersionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionIterator��һ���Է�����������յ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionIterator
{
public:
	///���췽��
	CTopicMarketDataVersionIterator(void)
	{
	}

	///���췽��
	CTopicMarketDataVersionIterator(CTopicMarketDataVersionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataVersionIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��TopicMarketDataVersion
	///@return	��һ����������CTopicMarketDataVersion������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTopicMarketDataVersion *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CTopicMarketDataVersionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTopicMarketDataVersion ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTopicMarketDataVersion * pTopicMarketDataVersion,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CTopicMarketDataVersionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInformation��һ���洢��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInformation
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! InformationID.isValid())
			return 0;
		if (! SequenceNo.isValid())
			return 0;
		if (! Content.isValid())
			return 0;
		if (! ContentLength.isValid())
			return 0;
		if (! IsAccomplished.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableInformation *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��Ϣ���
	CInformationIDType InformationID;
	///���к�
	CSequenceNoType SequenceNo;
	///��Ϣ����
	CContentType Content;
	///���ĳ���
	CContentLengthType ContentLength;
	///�Ƿ����
	CBoolType IsAccomplished;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableInformation CInformation;

/////////////////////////////////////////////////////////////////////////
///CInformationActionTrigger�ǲ�����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationActionTrigger
{
public:
	///���췽��
	CInformationActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CInformationActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInformationFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pInformation	Ҫ�����Information
	virtual void beforeAdd(CWriteableInformation *pInformation)
	{
		return;
	}
	
	///����󴥷�
	///@param	pInformation	�Ѿ������Information
	virtual void afterAdd(CInformation *pInformation)
	{
		return;
	}

	///����ǰ����	
	///@param	pInformation	��ˢ�µ�CInformation
	///@param	pNewInformation	�µ�ֵ
	virtual void beforeUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pInformation	��ˢ�µ�CInformation
	virtual void afterUpdate(CInformation *pInformation)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pInformation	Ҫɾ����CInformation
	virtual void beforeRemove(CInformation *pInformation)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInformationFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInformationCommitTrigger��ȷ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationCommitTrigger
{
public:
	///���췽��
	CInformationCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CInformationCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInformationFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pInformation	�Ѿ������Information
	virtual void commitAdd(CInformation *pInformation)
	{
		return;
	}

	///���º󴥷�
	///@param	pInformation	��ˢ�µ�CInformation
	///@param	poldInformation	ԭ����ֵ
	virtual void commitUpdate(CInformation *pInformation, CWriteableInformation *pOldInformation)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pInformation	�Ѿ�ɾ����CInformation
	virtual void commitRemove(CWriteableInformation *pInformation)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInformationFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInformationIterator��һ������Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationIterator
{
public:
	///���췽��
	CInformationIterator(void)
	{
	}

	///���췽��
	CInformationIterator(CInformationFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInformationIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Information
	///@return	��һ����������CInformation������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInformation *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CInformationFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInformation ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInformation * pInformation,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CInformationFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableOrderCount��һ���洢���������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOrderCount
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ParticipantID.isValid())
			return 0;
		if (! StopOrderCount.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableOrderCount *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��Ա����
	CParticipantIDType ParticipantID;
	///ֹ�𱨵�����
	COrderCountType StopOrderCount;
	unsigned int HashHashParticipantID;
	
	///����HashParticipantID��hashֵ
	void calHashHashParticipantID(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		HashHashParticipantID=key;
	}
	
	///������Ҫ���������HashParticipantID��hashֵ
	void updateHashHashParticipantID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashHashParticipantID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashHashParticipantID();
	}
	

private:
};

typedef const CWriteableOrderCount COrderCount;

/////////////////////////////////////////////////////////////////////////
///COrderCountActionTrigger�ǲ�����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountActionTrigger
{
public:
	///���췽��
	COrderCountActionTrigger(void)
	{
	}
	
	///��������
	virtual ~COrderCountActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(COrderCountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pOrderCount	Ҫ�����OrderCount
	virtual void beforeAdd(CWriteableOrderCount *pOrderCount)
	{
		return;
	}
	
	///����󴥷�
	///@param	pOrderCount	�Ѿ������OrderCount
	virtual void afterAdd(COrderCount *pOrderCount)
	{
		return;
	}

	///����ǰ����	
	///@param	pOrderCount	��ˢ�µ�COrderCount
	///@param	pNewOrderCount	�µ�ֵ
	virtual void beforeUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pOrderCount	��ˢ�µ�COrderCount
	virtual void afterUpdate(COrderCount *pOrderCount)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pOrderCount	Ҫɾ����COrderCount
	virtual void beforeRemove(COrderCount *pOrderCount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	COrderCountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountCommitTrigger��ȷ�ϱ�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountCommitTrigger
{
public:
	///���췽��
	COrderCountCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~COrderCountCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(COrderCountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pOrderCount	�Ѿ������OrderCount
	virtual void commitAdd(COrderCount *pOrderCount)
	{
		return;
	}

	///���º󴥷�
	///@param	pOrderCount	��ˢ�µ�COrderCount
	///@param	poldOrderCount	ԭ����ֵ
	virtual void commitUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pOldOrderCount)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pOrderCount	�Ѿ�ɾ����COrderCount
	virtual void commitRemove(CWriteableOrderCount *pOrderCount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	COrderCountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountIterator��һ���Ա���������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountIterator
{
public:
	///���췽��
	COrderCountIterator(void)
	{
	}

	///���췽��
	COrderCountIterator(COrderCountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderCountIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��OrderCount
	///@return	��һ����������COrderCount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrderCount *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	COrderCountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrderCount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrderCount * pOrderCount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	COrderCountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInstrument��һ���洢��Լ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInstrument
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ProductGroupID.isValid())
			return 0;
		if (! UnderlyingInstrID.isValid())
			return 0;
		if (! ProductClass.isValid())
			return 0;
		if (! PositionType.isValid())
			return 0;
		if (! StrikePrice.isValid())
			return 0;
		if (! OptionsType.isValid())
			return 0;
		if (! VolumeMultiple.isValid())
			return 0;
		if (! UnderlyingMultiple.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstrumentName.isValid())
			return 0;
		if (! DeliveryYear.isValid())
			return 0;
		if (! DeliveryMonth.isValid())
			return 0;
		if (! AdvanceMonth.isValid())
			return 0;
		if (! IsTrading.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableInstrument *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ʒ����
	CProductIDType ProductID;
	///��Ʒ�����
	CProductGroupIDType ProductGroupID;
	///������Ʒ����
	CInstrumentIDType UnderlyingInstrID;
	///��Ʒ����
	CProductClassType ProductClass;
	///�ֲ�����
	CPositionTypeType PositionType;
	///ִ�м�
	CPriceType StrikePrice;
	///��Ȩ����
	COptionsTypeType OptionsType;
	///��Լ��������
	CVolumeMultipleType VolumeMultiple;
	///��Լ������Ʒ����
	CUnderlyingMultipleType UnderlyingMultiple;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Լ����
	CInstrumentNameType InstrumentName;
	///�������
	CYearType DeliveryYear;
	///������
	CMonthType DeliveryMonth;
	///��ǰ�·�
	CAdvanceMonthType AdvanceMonth;
	///��ǰ�Ƿ���
	CBoolType IsTrading;
	unsigned int HashInstrumentID;
	
	///����InstrumentID��hashֵ
	void calHashInstrumentID(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		HashInstrumentID=key;
	}
	
	///������Ҫ���������InstrumentID��hashֵ
	void updateHashInstrumentID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashInstrumentID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashInstrumentID();
	}
	
	///�����Ӧ�Ļ�����Լ��ָ��
	///@param	pFactory	�����Ӧ�Ļ�����Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ļ�����Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkBaseInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�Ļ�����Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkBaseInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pBaseInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�Ļ�����Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�Ļ�����Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getBaseInstrument(void) const
	{
		return pBaseInstrument;
	}
	///�����Ӧ�ĺ�Լ���Ե�ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ���Ե�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ���Ե�ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableCurrInstrumentProperty *linkInstrumentProperty(CCurrInstrumentPropertyFactory *pFactory) const;

	///�����Ӧ�ĺ�Լ����ָ��
	///@param	pCurrInstrumentProperty	Ҫ���ӵ��Ķ���
	///@return	�����pCurrInstrumentProperty
	const CWriteableCurrInstrumentProperty *linkInstrumentProperty(const CWriteableCurrInstrumentProperty *pCurrInstrumentProperty) const
	{
		void *target=(void *)(&(this->pInstrumentProperty));
		*((const CWriteableCurrInstrumentProperty **)target)=pCurrInstrumentProperty;
		return pCurrInstrumentProperty;
	}
	
	///��ȡ��Ӧ�ĺ�Լ���Ե�ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ���Ե�ָ�룬����Ҳ����򷵻�NULL
	const CWriteableCurrInstrumentProperty *getInstrumentProperty(void) const
	{
		return pInstrumentProperty;
	}
	///�����Ӧ�ĺ�Լ״̬��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ״̬��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrumentStatus *linkInstrumentStatus(CInstrumentStatusFactory *pFactory) const;

	///�����Ӧ�ĺ�Լ״ָ̬��
	///@param	pInstrumentStatus	Ҫ���ӵ��Ķ���
	///@return	�����pInstrumentStatus
	const CWriteableInstrumentStatus *linkInstrumentStatus(const CWriteableInstrumentStatus *pInstrumentStatus) const
	{
		void *target=(void *)(&(this->pInstrumentStatus));
		*((const CWriteableInstrumentStatus **)target)=pInstrumentStatus;
		return pInstrumentStatus;
	}
	
	///��ȡ��Ӧ�ĺ�Լ״̬��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ״̬��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrumentStatus *getInstrumentStatus(void) const
	{
		return pInstrumentStatus;
	}
	///�����Ӧ�������ָ��
	///@param	pFactory	�����Ӧ�������ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�������ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableMarketData *linkMarketData(CMarketDataFactory *pFactory) const;

	///�����Ӧ������ָ��
	///@param	pMarketData	Ҫ���ӵ��Ķ���
	///@return	�����pMarketData
	const CWriteableMarketData *linkMarketData(const CWriteableMarketData *pMarketData) const
	{
		void *target=(void *)(&(this->pMarketData));
		*((const CWriteableMarketData **)target)=pMarketData;
		return pMarketData;
	}
	
	///��ȡ��Ӧ�������ָ��
	///@return	�ҵ��Ķ�Ӧ�������ָ�룬����Ҳ����򷵻�NULL
	const CWriteableMarketData *getMarketData(void) const
	{
		return pMarketData;
	}
	///�����Ӧ�����ڱ�ֵ�����ָ��
	///@param	pFactory	�����Ӧ�����ڱ�ֵ�����ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�����ڱ�ֵ�����ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableCurrHedgeRule *linkCurrHedgeRule(CCurrHedgeRuleFactory *pFactory) const;

	///�����Ӧ�����ڱ�ֵ����ָ��
	///@param	pCurrHedgeRule	Ҫ���ӵ��Ķ���
	///@return	�����pCurrHedgeRule
	const CWriteableCurrHedgeRule *linkCurrHedgeRule(const CWriteableCurrHedgeRule *pCurrHedgeRule) const
	{
		void *target=(void *)(&(this->pCurrHedgeRule));
		*((const CWriteableCurrHedgeRule **)target)=pCurrHedgeRule;
		return pCurrHedgeRule;
	}
	
	///��ȡ��Ӧ�����ڱ�ֵ�����ָ��
	///@return	�ҵ��Ķ�Ӧ�����ڱ�ֵ�����ָ�룬����Ҳ����򷵻�NULL
	const CWriteableCurrHedgeRule *getCurrHedgeRule(void) const
	{
		return pCurrHedgeRule;
	}
	///�����Ӧ���۶Ϲ����ָ��
	///@param	pFactory	�����Ӧ���۶Ϲ����ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ���۶Ϲ����ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableCurrFuse *linkCurrFuse(CCurrFuseFactory *pFactory) const;

	///�����Ӧ���۶Ϲ���ָ��
	///@param	pCurrFuse	Ҫ���ӵ��Ķ���
	///@return	�����pCurrFuse
	const CWriteableCurrFuse *linkCurrFuse(const CWriteableCurrFuse *pCurrFuse) const
	{
		void *target=(void *)(&(this->pCurrFuse));
		*((const CWriteableCurrFuse **)target)=pCurrFuse;
		return pCurrFuse;
	}
	
	///��ȡ��Ӧ���۶Ϲ����ָ��
	///@return	�ҵ��Ķ�Ӧ���۶Ϲ����ָ�룬����Ҳ����򷵻�NULL
	const CWriteableCurrFuse *getCurrFuse(void) const
	{
		return pCurrFuse;
	}
	///�����Ӧ���۶�״̬��ָ��
	///@param	pFactory	�����Ӧ���۶�״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ���۶�״̬��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableFusePhase *linkFusePhase(CFusePhaseFactory *pFactory) const;

	///�����Ӧ���۶�״ָ̬��
	///@param	pFusePhase	Ҫ���ӵ��Ķ���
	///@return	�����pFusePhase
	const CWriteableFusePhase *linkFusePhase(const CWriteableFusePhase *pFusePhase) const
	{
		void *target=(void *)(&(this->pFusePhase));
		*((const CWriteableFusePhase **)target)=pFusePhase;
		return pFusePhase;
	}
	
	///��ȡ��Ӧ���۶�״̬��ָ��
	///@return	�ҵ��Ķ�Ӧ���۶�״̬��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableFusePhase *getFusePhase(void) const
	{
		return pFusePhase;
	}
	///�����Ӧ���ǵ�ͣ�����õ�ָ��
	///@param	pFactory	�����Ӧ���ǵ�ͣ�����õ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ���ǵ�ͣ�����õ�ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableBasePriceLimit *linkBasePriceLimit(CBasePriceLimitFactory *pFactory) const;

	///�����Ӧ���ǵ�ͣ������ָ��
	///@param	pBasePriceLimit	Ҫ���ӵ��Ķ���
	///@return	�����pBasePriceLimit
	const CWriteableBasePriceLimit *linkBasePriceLimit(const CWriteableBasePriceLimit *pBasePriceLimit) const
	{
		void *target=(void *)(&(this->pBasePriceLimit));
		*((const CWriteableBasePriceLimit **)target)=pBasePriceLimit;
		return pBasePriceLimit;
	}
	
	///��ȡ��Ӧ���ǵ�ͣ�����õ�ָ��
	///@return	�ҵ��Ķ�Ӧ���ǵ�ͣ�����õ�ָ�룬����Ҳ����򷵻�NULL
	const CWriteableBasePriceLimit *getBasePriceLimit(void) const
	{
		return pBasePriceLimit;
	}
	///�����Ӧ�ĵ����������ָ��
	///@param	pFactory	�����Ӧ�ĵ����������ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĵ����������ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableUniPressure *linkUniPressure(CUniPressureFactory *pFactory) const;

	///�����Ӧ�ĵ��������ָ��
	///@param	pUniPressure	Ҫ���ӵ��Ķ���
	///@return	�����pUniPressure
	const CWriteableUniPressure *linkUniPressure(const CWriteableUniPressure *pUniPressure) const
	{
		void *target=(void *)(&(this->pUniPressure));
		*((const CWriteableUniPressure **)target)=pUniPressure;
		return pUniPressure;
	}
	
	///��ȡ��Ӧ�ĵ����������ָ��
	///@return	�ҵ��Ķ�Ӧ�ĵ����������ָ�룬����Ҳ����򷵻�NULL
	const CWriteableUniPressure *getUniPressure(void) const
	{
		return pUniPressure;
	}
	///�����Ӧ�Ľ�����ͬ��״̬��ָ��
	///@param	pFactory	�����Ӧ�Ľ�����ͬ��״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ľ�����ͬ��״̬��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableSGDataSyncStatus *linkSGDataSyncStatus(CSGDataSyncStatusFactory *pFactory) const;

	///�����Ӧ�Ľ�����ͬ��״ָ̬��
	///@param	pSGDataSyncStatus	Ҫ���ӵ��Ķ���
	///@return	�����pSGDataSyncStatus
	const CWriteableSGDataSyncStatus *linkSGDataSyncStatus(const CWriteableSGDataSyncStatus *pSGDataSyncStatus) const
	{
		void *target=(void *)(&(this->pSGDataSyncStatus));
		*((const CWriteableSGDataSyncStatus **)target)=pSGDataSyncStatus;
		return pSGDataSyncStatus;
	}
	
	///��ȡ��Ӧ�Ľ�����ͬ��״̬��ָ��
	///@return	�ҵ��Ķ�Ӧ�Ľ�����ͬ��״̬��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableSGDataSyncStatus *getSGDataSyncStatus(void) const
	{
		return pSGDataSyncStatus;
	}

private:
	///��Ӧ�Ļ�����Լ
	const CWriteableInstrument *pBaseInstrument;
	///��Ӧ�ĺ�Լ����
	const CWriteableCurrInstrumentProperty *pInstrumentProperty;
	///��Ӧ�ĺ�Լ״̬
	const CWriteableInstrumentStatus *pInstrumentStatus;
	///��Ӧ������
	const CWriteableMarketData *pMarketData;
	///��Ӧ�����ڱ�ֵ����
	const CWriteableCurrHedgeRule *pCurrHedgeRule;
	///��Ӧ���۶Ϲ���
	const CWriteableCurrFuse *pCurrFuse;
	///��Ӧ���۶�״̬
	const CWriteableFusePhase *pFusePhase;
	///��Ӧ���ǵ�ͣ������
	const CWriteableBasePriceLimit *pBasePriceLimit;
	///��Ӧ�ĵ��������
	const CWriteableUniPressure *pUniPressure;
	///��Ӧ�Ľ�����ͬ��״̬
	const CWriteableSGDataSyncStatus *pSGDataSyncStatus;
};

typedef const CWriteableInstrument CInstrument;

/////////////////////////////////////////////////////////////////////////
///CInstrumentActionTrigger�ǲ�����Լʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentActionTrigger
{
public:
	///���췽��
	CInstrumentActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CInstrumentActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInstrumentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pInstrument	Ҫ�����Instrument
	virtual void beforeAdd(CWriteableInstrument *pInstrument)
	{
		return;
	}
	
	///����󴥷�
	///@param	pInstrument	�Ѿ������Instrument
	virtual void afterAdd(CInstrument *pInstrument)
	{
		return;
	}

	///����ǰ����	
	///@param	pInstrument	��ˢ�µ�CInstrument
	///@param	pNewInstrument	�µ�ֵ
	virtual void beforeUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pInstrument	��ˢ�µ�CInstrument
	virtual void afterUpdate(CInstrument *pInstrument)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pInstrument	Ҫɾ����CInstrument
	virtual void beforeRemove(CInstrument *pInstrument)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInstrumentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentCommitTrigger��ȷ�Ϻ�Լʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentCommitTrigger
{
public:
	///���췽��
	CInstrumentCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CInstrumentCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInstrumentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pInstrument	�Ѿ������Instrument
	virtual void commitAdd(CInstrument *pInstrument)
	{
		return;
	}

	///���º󴥷�
	///@param	pInstrument	��ˢ�µ�CInstrument
	///@param	poldInstrument	ԭ����ֵ
	virtual void commitUpdate(CInstrument *pInstrument, CWriteableInstrument *pOldInstrument)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pInstrument	�Ѿ�ɾ����CInstrument
	virtual void commitRemove(CWriteableInstrument *pInstrument)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInstrumentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentIterator��һ���Ժ�Լ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentIterator
{
public:
	///���췽��
	CInstrumentIterator(void)
	{
	}

	///���췽��
	CInstrumentIterator(CInstrumentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Instrument
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrument *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CInstrumentFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrument ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrument * pInstrument,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CInstrumentFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCombinationLeg��һ���洢��Ϻ�Լ���ȵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCombinationLeg
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! CombInstrumentID.isValid())
			return 0;
		if (! LegID.isValid())
			return 0;
		if (! LegInstrumentID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! LegMultiple.isValid())
			return 0;
		if (! ImplyLevel.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCombinationLeg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ϻ�Լ����
	CInstrumentIDType CombInstrumentID;
	///���ȱ��
	CLegIDType LegID;
	///���Ⱥ�Լ����
	CInstrumentIDType LegInstrumentID;
	///��������
	CDirectionType Direction;
	///���ȳ���
	CLegMultipleType LegMultiple;
	///�Ƶ�����
	CImplyLevelType ImplyLevel;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ����Ϻ�Լ��ָ��
	///@param	pFactory	�����Ӧ����Ϻ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ����Ϻ�Լ��ָ��
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	inline const CWriteableInstrument *linkCombinationInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ����Ϻ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkCombinationInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pCombinationInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ����Ϻ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ����Ϻ�Լ��ָ��
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	const CWriteableInstrument *getCombinationInstrument(void) const
	{
		return pCombinationInstrument;
	}
	///�����Ӧ�ĵ��Ⱥ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĵ��Ⱥ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĵ��Ⱥ�Լ��ָ��
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	inline const CWriteableInstrument *linkLegInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĵ��Ⱥ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkLegInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pLegInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĵ��Ⱥ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĵ��Ⱥ�Լ��ָ��
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	const CWriteableInstrument *getLegInstrument(void) const
	{
		return pLegInstrument;
	}

private:
	///��Ӧ����Ϻ�Լ
	const CWriteableInstrument *pCombinationInstrument;
	///��Ӧ�ĵ��Ⱥ�Լ
	const CWriteableInstrument *pLegInstrument;
};

typedef const CWriteableCombinationLeg CCombinationLeg;

/////////////////////////////////////////////////////////////////////////
///CCombinationLegActionTrigger�ǲ�����Ϻ�Լ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegActionTrigger
{
public:
	///���췽��
	CCombinationLegActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCombinationLegActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCombinationLegFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCombinationLeg	Ҫ�����CombinationLeg
	virtual void beforeAdd(CWriteableCombinationLeg *pCombinationLeg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCombinationLeg	�Ѿ������CombinationLeg
	virtual void afterAdd(CCombinationLeg *pCombinationLeg)
	{
		return;
	}

	///����ǰ����	
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	///@param	pNewCombinationLeg	�µ�ֵ
	virtual void beforeUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	virtual void afterUpdate(CCombinationLeg *pCombinationLeg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCombinationLeg	Ҫɾ����CCombinationLeg
	virtual void beforeRemove(CCombinationLeg *pCombinationLeg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCombinationLegFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegCommitTrigger��ȷ����Ϻ�Լ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegCommitTrigger
{
public:
	///���췽��
	CCombinationLegCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCombinationLegCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCombinationLegFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCombinationLeg	�Ѿ������CombinationLeg
	virtual void commitAdd(CCombinationLeg *pCombinationLeg)
	{
		return;
	}

	///���º󴥷�
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	///@param	poldCombinationLeg	ԭ����ֵ
	virtual void commitUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pOldCombinationLeg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCombinationLeg	�Ѿ�ɾ����CCombinationLeg
	virtual void commitRemove(CWriteableCombinationLeg *pCombinationLeg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCombinationLegFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegIterator��һ������Ϻ�Լ���ȵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegIterator
{
public:
	///���췽��
	CCombinationLegIterator(void)
	{
	}

	///���췽��
	CCombinationLegIterator(CCombinationLegFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombinationLegIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CombinationLeg
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombinationLeg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCombinationLegFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombinationLeg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombinationLeg * pCombinationLeg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCombinationLegFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartRoleAccount��һ���洢��Ա�˻���ϵ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartRoleAccount
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartRoleAccount *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///���׽�ɫ
	CTradingRoleType TradingRole;
	///�ʽ��ʺ�
	CAccountIDType AccountID;
	unsigned int HashPartRoleAndSG;
	
	///����PartRoleAndSG��hashֵ
	void calHashPartRoleAndSG(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		key=SettlementGroupID.hash(key);
		HashPartRoleAndSG=key;
	}
	
	///������Ҫ���������PartRoleAndSG��hashֵ
	void updateHashPartRoleAndSG(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashPartRoleAndSG();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashPartRoleAndSG();
	}
	
	///�����Ӧ���ʻ���ָ��
	///@param	pFactory	�����Ӧ���ʻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ���ʻ���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableTradingAccount *linkTradingAccount(CTradingAccountFactory *pFactory) const;

	///�����Ӧ���ʻ�ָ��
	///@param	pTradingAccount	Ҫ���ӵ��Ķ���
	///@return	�����pTradingAccount
	const CWriteableTradingAccount *linkTradingAccount(const CWriteableTradingAccount *pTradingAccount) const
	{
		void *target=(void *)(&(this->pTradingAccount));
		*((const CWriteableTradingAccount **)target)=pTradingAccount;
		return pTradingAccount;
	}
	
	///��ȡ��Ӧ���ʻ���ָ��
	///@return	�ҵ��Ķ�Ӧ���ʻ���ָ�룬����Ҳ����򷵻�NULL
	const CWriteableTradingAccount *getTradingAccount(void) const
	{
		return pTradingAccount;
	}

private:
	///��Ӧ���ʻ�
	const CWriteableTradingAccount *pTradingAccount;
};

typedef const CWriteablePartRoleAccount CPartRoleAccount;

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountActionTrigger�ǲ�����Ա�˻���ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountActionTrigger
{
public:
	///���췽��
	CPartRoleAccountActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartRoleAccountActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartRoleAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartRoleAccount	Ҫ�����PartRoleAccount
	virtual void beforeAdd(CWriteablePartRoleAccount *pPartRoleAccount)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartRoleAccount	�Ѿ������PartRoleAccount
	virtual void afterAdd(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	///@param	pNewPartRoleAccount	�µ�ֵ
	virtual void beforeUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	virtual void afterUpdate(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartRoleAccount	Ҫɾ����CPartRoleAccount
	virtual void beforeRemove(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartRoleAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountCommitTrigger��ȷ�ϻ�Ա�˻���ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountCommitTrigger
{
public:
	///���췽��
	CPartRoleAccountCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartRoleAccountCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartRoleAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartRoleAccount	�Ѿ������PartRoleAccount
	virtual void commitAdd(CPartRoleAccount *pPartRoleAccount)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	///@param	poldPartRoleAccount	ԭ����ֵ
	virtual void commitUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pOldPartRoleAccount)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartRoleAccount	�Ѿ�ɾ����CPartRoleAccount
	virtual void commitRemove(CWriteablePartRoleAccount *pPartRoleAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartRoleAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountIterator��һ���Ի�Ա�˻���ϵ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountIterator
{
public:
	///���췽��
	CPartRoleAccountIterator(void)
	{
	}

	///���췽��
	CPartRoleAccountIterator(CPartRoleAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartRoleAccountIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartRoleAccount
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartRoleAccount *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartRoleAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartRoleAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartRoleAccount * pPartRoleAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartRoleAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartProductRole��һ���洢��Ա��Ʒ��ɫ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartProductRole
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartProductRole *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///��Ʒ����
	CProductIDType ProductID;
	///���׽�ɫ
	CTradingRoleType TradingRole;
	unsigned int HashParticipantProductRole;
	
	///����ParticipantProductRole��hashֵ
	void calHashParticipantProductRole(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ProductID.hash(key);
		key=TradingRole.hash(key);
		HashParticipantProductRole=key;
	}
	
	///������Ҫ���������ParticipantProductRole��hashֵ
	void updateHashParticipantProductRole(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashParticipantProductRole();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashParticipantProductRole();
	}
	

private:
};

typedef const CWriteablePartProductRole CPartProductRole;

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleActionTrigger�ǲ�����Ա��Ʒ��ɫʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleActionTrigger
{
public:
	///���췽��
	CPartProductRoleActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartProductRoleActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartProductRoleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartProductRole	Ҫ�����PartProductRole
	virtual void beforeAdd(CWriteablePartProductRole *pPartProductRole)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartProductRole	�Ѿ������PartProductRole
	virtual void afterAdd(CPartProductRole *pPartProductRole)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	///@param	pNewPartProductRole	�µ�ֵ
	virtual void beforeUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	virtual void afterUpdate(CPartProductRole *pPartProductRole)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartProductRole	Ҫɾ����CPartProductRole
	virtual void beforeRemove(CPartProductRole *pPartProductRole)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartProductRoleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleCommitTrigger��ȷ�ϻ�Ա��Ʒ��ɫʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleCommitTrigger
{
public:
	///���췽��
	CPartProductRoleCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartProductRoleCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartProductRoleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartProductRole	�Ѿ������PartProductRole
	virtual void commitAdd(CPartProductRole *pPartProductRole)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	///@param	poldPartProductRole	ԭ����ֵ
	virtual void commitUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pOldPartProductRole)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartProductRole	�Ѿ�ɾ����CPartProductRole
	virtual void commitRemove(CWriteablePartProductRole *pPartProductRole)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartProductRoleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleIterator��һ���Ի�Ա��Ʒ��ɫ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleIterator
{
public:
	///���췽��
	CPartProductRoleIterator(void)
	{
	}

	///���췽��
	CPartProductRoleIterator(CPartProductRoleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartProductRoleIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartProductRole
	///@return	��һ����������CPartProductRole������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRole *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartProductRoleFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRole ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRole * pPartProductRole,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartProductRoleFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartProductRight��һ���洢��Ա��Ʒ����Ȩ�޵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartProductRight
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartProductRight *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ʒ����
	CProductIDType ProductID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///����Ȩ��
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndProduct;
	
	///����ParticipantAndProduct��hashֵ
	void calHashParticipantAndProduct(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ProductID.hash(key);
		HashParticipantAndProduct=key;
	}
	
	///������Ҫ���������ParticipantAndProduct��hashֵ
	void updateHashParticipantAndProduct(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashParticipantAndProduct();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashParticipantAndProduct();
	}
	

private:
};

typedef const CWriteablePartProductRight CPartProductRight;

/////////////////////////////////////////////////////////////////////////
///CPartProductRightActionTrigger�ǲ�����Ա��Ʒ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightActionTrigger
{
public:
	///���췽��
	CPartProductRightActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartProductRightActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartProductRight	Ҫ�����PartProductRight
	virtual void beforeAdd(CWriteablePartProductRight *pPartProductRight)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartProductRight	�Ѿ������PartProductRight
	virtual void afterAdd(CPartProductRight *pPartProductRight)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	///@param	pNewPartProductRight	�µ�ֵ
	virtual void beforeUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	virtual void afterUpdate(CPartProductRight *pPartProductRight)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartProductRight	Ҫɾ����CPartProductRight
	virtual void beforeRemove(CPartProductRight *pPartProductRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightCommitTrigger��ȷ�ϻ�Ա��Ʒ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightCommitTrigger
{
public:
	///���췽��
	CPartProductRightCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartProductRightCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartProductRight	�Ѿ������PartProductRight
	virtual void commitAdd(CPartProductRight *pPartProductRight)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	///@param	poldPartProductRight	ԭ����ֵ
	virtual void commitUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pOldPartProductRight)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartProductRight	�Ѿ�ɾ����CPartProductRight
	virtual void commitRemove(CWriteablePartProductRight *pPartProductRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightIterator��һ���Ի�Ա��Ʒ����Ȩ�޵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightIterator
{
public:
	///���췽��
	CPartProductRightIterator(void)
	{
	}

	///���췽��
	CPartProductRightIterator(CPartProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartProductRightIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartProductRight
	///@return	��һ����������CPartProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartProductRight *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartProductRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartProductRight * pPartProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartProductRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartInstrumentRight��һ���洢��Ա��Լ����Ȩ�޵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartInstrumentRight
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartInstrumentRight *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///����Ȩ��
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndInstrument;
	
	///����ParticipantAndInstrument��hashֵ
	void calHashParticipantAndInstrument(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=InstrumentID.hash(key);
		HashParticipantAndInstrument=key;
	}
	
	///������Ҫ���������ParticipantAndInstrument��hashֵ
	void updateHashParticipantAndInstrument(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashParticipantAndInstrument();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashParticipantAndInstrument();
	}
	

private:
};

typedef const CWriteablePartInstrumentRight CPartInstrumentRight;

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightActionTrigger�ǲ�����Ա��Լ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightActionTrigger
{
public:
	///���췽��
	CPartInstrumentRightActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartInstrumentRightActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartInstrumentRight	Ҫ�����PartInstrumentRight
	virtual void beforeAdd(CWriteablePartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartInstrumentRight	�Ѿ������PartInstrumentRight
	virtual void afterAdd(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	///@param	pNewPartInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	virtual void afterUpdate(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartInstrumentRight	Ҫɾ����CPartInstrumentRight
	virtual void beforeRemove(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightCommitTrigger��ȷ�ϻ�Ա��Լ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightCommitTrigger
{
public:
	///���췽��
	CPartInstrumentRightCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartInstrumentRightCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartInstrumentRight	�Ѿ������PartInstrumentRight
	virtual void commitAdd(CPartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	///@param	poldPartInstrumentRight	ԭ����ֵ
	virtual void commitUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pOldPartInstrumentRight)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartInstrumentRight	�Ѿ�ɾ����CPartInstrumentRight
	virtual void commitRemove(CWriteablePartInstrumentRight *pPartInstrumentRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightIterator��һ���Ի�Ա��Լ����Ȩ�޵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightIterator
{
public:
	///���췽��
	CPartInstrumentRightIterator(void)
	{
	}

	///���췽��
	CPartInstrumentRightIterator(CPartInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartInstrumentRightIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartInstrumentRight
	///@return	��һ����������CPartInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartInstrumentRight *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartInstrumentRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartInstrumentRight * pPartInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartInstrumentRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClientProductRight��һ���洢�ͻ���Ʒ����Ȩ�޵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClientProductRight
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableClientProductRight *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ʒ����
	CProductIDType ProductID;
	///�ͻ�����
	CClientIDType ClientID;
	///����Ȩ��
	CTradingRightType TradingRight;
	unsigned int HashClientAndProduct;
	
	///����ClientAndProduct��hashֵ
	void calHashClientAndProduct(void)
	{
		unsigned key=0;
		key=ClientID.hash(key);
		key=ProductID.hash(key);
		HashClientAndProduct=key;
	}
	
	///������Ҫ���������ClientAndProduct��hashֵ
	void updateHashClientAndProduct(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashClientAndProduct();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashClientAndProduct();
	}
	

private:
};

typedef const CWriteableClientProductRight CClientProductRight;

/////////////////////////////////////////////////////////////////////////
///CClientProductRightActionTrigger�ǲ����ͻ���Ʒ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightActionTrigger
{
public:
	///���췽��
	CClientProductRightActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientProductRightActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pClientProductRight	Ҫ�����ClientProductRight
	virtual void beforeAdd(CWriteableClientProductRight *pClientProductRight)
	{
		return;
	}
	
	///����󴥷�
	///@param	pClientProductRight	�Ѿ������ClientProductRight
	virtual void afterAdd(CClientProductRight *pClientProductRight)
	{
		return;
	}

	///����ǰ����	
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	///@param	pNewClientProductRight	�µ�ֵ
	virtual void beforeUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	virtual void afterUpdate(CClientProductRight *pClientProductRight)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pClientProductRight	Ҫɾ����CClientProductRight
	virtual void beforeRemove(CClientProductRight *pClientProductRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightCommitTrigger��ȷ�Ͽͻ���Ʒ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightCommitTrigger
{
public:
	///���췽��
	CClientProductRightCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientProductRightCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pClientProductRight	�Ѿ������ClientProductRight
	virtual void commitAdd(CClientProductRight *pClientProductRight)
	{
		return;
	}

	///���º󴥷�
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	///@param	poldClientProductRight	ԭ����ֵ
	virtual void commitUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pOldClientProductRight)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pClientProductRight	�Ѿ�ɾ����CClientProductRight
	virtual void commitRemove(CWriteableClientProductRight *pClientProductRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightIterator��һ���Կͻ���Ʒ����Ȩ�޵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightIterator
{
public:
	///���췽��
	CClientProductRightIterator(void)
	{
	}

	///���췽��
	CClientProductRightIterator(CClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientProductRightIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ClientProductRight
	///@return	��һ����������CClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientProductRight *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CClientProductRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientProductRight * pClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CClientProductRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClientInstrumentRight��һ���洢�ͻ���Լ����Ȩ�޵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClientInstrumentRight
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableClientInstrumentRight *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientIDType ClientID;
	///����Ȩ��
	CTradingRightType TradingRight;
	unsigned int HashClientAndInstrument;
	
	///����ClientAndInstrument��hashֵ
	void calHashClientAndInstrument(void)
	{
		unsigned key=0;
		key=ClientID.hash(key);
		key=InstrumentID.hash(key);
		HashClientAndInstrument=key;
	}
	
	///������Ҫ���������ClientAndInstrument��hashֵ
	void updateHashClientAndInstrument(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashClientAndInstrument();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashClientAndInstrument();
	}
	

private:
};

typedef const CWriteableClientInstrumentRight CClientInstrumentRight;

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightActionTrigger�ǲ����ͻ���Լ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightActionTrigger
{
public:
	///���췽��
	CClientInstrumentRightActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientInstrumentRightActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pClientInstrumentRight	Ҫ�����ClientInstrumentRight
	virtual void beforeAdd(CWriteableClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
	
	///����󴥷�
	///@param	pClientInstrumentRight	�Ѿ������ClientInstrumentRight
	virtual void afterAdd(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}

	///����ǰ����	
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	///@param	pNewClientInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	virtual void afterUpdate(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pClientInstrumentRight	Ҫɾ����CClientInstrumentRight
	virtual void beforeRemove(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightCommitTrigger��ȷ�Ͽͻ���Լ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightCommitTrigger
{
public:
	///���췽��
	CClientInstrumentRightCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientInstrumentRightCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pClientInstrumentRight	�Ѿ������ClientInstrumentRight
	virtual void commitAdd(CClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}

	///���º󴥷�
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	///@param	poldClientInstrumentRight	ԭ����ֵ
	virtual void commitUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pOldClientInstrumentRight)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pClientInstrumentRight	�Ѿ�ɾ����CClientInstrumentRight
	virtual void commitRemove(CWriteableClientInstrumentRight *pClientInstrumentRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightIterator��һ���Կͻ���Լ����Ȩ�޵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightIterator
{
public:
	///���췽��
	CClientInstrumentRightIterator(void)
	{
	}

	///���췽��
	CClientInstrumentRightIterator(CClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientInstrumentRightIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ClientInstrumentRight
	///@return	��һ����������CClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientInstrumentRight *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CClientInstrumentRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientInstrumentRight * pClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CClientInstrumentRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartClientProductRight��һ���洢��Ա�ͻ���Ʒ����Ȩ�޵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartClientProductRight
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartClientProductRight *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ʒ����
	CProductIDType ProductID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///����Ȩ��
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndClientAndProduct;
	
	///����ParticipantAndClientAndProduct��hashֵ
	void calHashParticipantAndClientAndProduct(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ClientID.hash(key);
		key=ProductID.hash(key);
		HashParticipantAndClientAndProduct=key;
	}
	
	///������Ҫ���������ParticipantAndClientAndProduct��hashֵ
	void updateHashParticipantAndClientAndProduct(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashParticipantAndClientAndProduct();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashParticipantAndClientAndProduct();
	}
	

private:
};

typedef const CWriteablePartClientProductRight CPartClientProductRight;

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightActionTrigger�ǲ�����Ա�ͻ���Ʒ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightActionTrigger
{
public:
	///���췽��
	CPartClientProductRightActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartClientProductRightActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartClientProductRight	Ҫ�����PartClientProductRight
	virtual void beforeAdd(CWriteablePartClientProductRight *pPartClientProductRight)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartClientProductRight	�Ѿ������PartClientProductRight
	virtual void afterAdd(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	///@param	pNewPartClientProductRight	�µ�ֵ
	virtual void beforeUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	virtual void afterUpdate(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartClientProductRight	Ҫɾ����CPartClientProductRight
	virtual void beforeRemove(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightCommitTrigger��ȷ�ϻ�Ա�ͻ���Ʒ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightCommitTrigger
{
public:
	///���췽��
	CPartClientProductRightCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartClientProductRightCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartClientProductRight	�Ѿ������PartClientProductRight
	virtual void commitAdd(CPartClientProductRight *pPartClientProductRight)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	///@param	poldPartClientProductRight	ԭ����ֵ
	virtual void commitUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pOldPartClientProductRight)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartClientProductRight	�Ѿ�ɾ����CPartClientProductRight
	virtual void commitRemove(CWriteablePartClientProductRight *pPartClientProductRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartClientProductRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightIterator��һ���Ի�Ա�ͻ���Ʒ����Ȩ�޵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightIterator
{
public:
	///���췽��
	CPartClientProductRightIterator(void)
	{
	}

	///���췽��
	CPartClientProductRightIterator(CPartClientProductRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientProductRightIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartClientProductRight
	///@return	��һ����������CPartClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientProductRight *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartClientProductRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientProductRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientProductRight * pPartClientProductRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartClientProductRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartClientInstrumentRight��һ���洢��Ա�ͻ���Լ����Ȩ�޵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartClientInstrumentRight
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRight.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartClientInstrumentRight *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///����Ȩ��
	CTradingRightType TradingRight;
	unsigned int HashParticipantAndClientAndInstrument;
	
	///����ParticipantAndClientAndInstrument��hashֵ
	void calHashParticipantAndClientAndInstrument(void)
	{
		unsigned key=0;
		key=ParticipantID.hash(key);
		key=ClientID.hash(key);
		key=InstrumentID.hash(key);
		HashParticipantAndClientAndInstrument=key;
	}
	
	///������Ҫ���������ParticipantAndClientAndInstrument��hashֵ
	void updateHashParticipantAndClientAndInstrument(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashParticipantAndClientAndInstrument();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashParticipantAndClientAndInstrument();
	}
	

private:
};

typedef const CWriteablePartClientInstrumentRight CPartClientInstrumentRight;

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightActionTrigger�ǲ�����Ա�ͻ���Լ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightActionTrigger
{
public:
	///���췽��
	CPartClientInstrumentRightActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartClientInstrumentRightActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartClientInstrumentRight	Ҫ�����PartClientInstrumentRight
	virtual void beforeAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartClientInstrumentRight	�Ѿ������PartClientInstrumentRight
	virtual void afterAdd(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	virtual void afterUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartClientInstrumentRight	Ҫɾ����CPartClientInstrumentRight
	virtual void beforeRemove(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightCommitTrigger��ȷ�ϻ�Ա�ͻ���Լ����Ȩ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightCommitTrigger
{
public:
	///���췽��
	CPartClientInstrumentRightCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartClientInstrumentRightCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartClientInstrumentRight	�Ѿ������PartClientInstrumentRight
	virtual void commitAdd(CPartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	///@param	poldPartClientInstrumentRight	ԭ����ֵ
	virtual void commitUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pOldPartClientInstrumentRight)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartClientInstrumentRight	�Ѿ�ɾ����CPartClientInstrumentRight
	virtual void commitRemove(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartClientInstrumentRightFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightIterator��һ���Ի�Ա�ͻ���Լ����Ȩ�޵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightIterator
{
public:
	///���췽��
	CPartClientInstrumentRightIterator(void)
	{
	}

	///���췽��
	CPartClientInstrumentRightIterator(CPartClientInstrumentRightFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientInstrumentRightIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartClientInstrumentRight
	///@return	��һ����������CPartClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartClientInstrumentRight *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartClientInstrumentRightFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartClientInstrumentRight ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartClientInstrumentRight * pPartClientInstrumentRight,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartClientInstrumentRightFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrProductProperty��һ���洢��Ʒ���ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrProductProperty
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ProductID.isValid())
			return 0;
		if (! ProductLifePhase.isValid())
			return 0;
		if (! TradingModel.isValid())
			return 0;
		if (! OptionsLimitRatio.isValid())
			return 0;
		if (! OptionsMgRatio.isValid())
			return 0;
		if (! SettlePriceSeconds.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrProductProperty *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ʒ����
	CProductIDType ProductID;
	///��Ʒ��������״̬
	CProductLifePhaseType ProductLifePhase;
	///����ģʽ
	CTradingModelType TradingModel;
	///��Ȩ�޲�ϵ��
	CRatioType OptionsLimitRatio;
	///��Ȩ��֤�����ϵ��
	CRatioType OptionsMgRatio;
	///����ȡ��ʱ��
	CSettlePriceSecondsType SettlePriceSeconds;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrProductProperty CCurrProductProperty;

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyActionTrigger�ǲ�����Ʒ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyActionTrigger
{
public:
	///���췽��
	CCurrProductPropertyActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrProductPropertyActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrProductPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrProductProperty	Ҫ�����CurrProductProperty
	virtual void beforeAdd(CWriteableCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrProductProperty	�Ѿ������CurrProductProperty
	virtual void afterAdd(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	///@param	pNewCurrProductProperty	�µ�ֵ
	virtual void beforeUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	virtual void afterUpdate(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrProductProperty	Ҫɾ����CCurrProductProperty
	virtual void beforeRemove(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrProductPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyCommitTrigger��ȷ�ϲ�Ʒ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyCommitTrigger
{
public:
	///���췽��
	CCurrProductPropertyCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrProductPropertyCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrProductPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrProductProperty	�Ѿ������CurrProductProperty
	virtual void commitAdd(CCurrProductProperty *pCurrProductProperty)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	///@param	poldCurrProductProperty	ԭ����ֵ
	virtual void commitUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pOldCurrProductProperty)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrProductProperty	�Ѿ�ɾ����CCurrProductProperty
	virtual void commitRemove(CWriteableCurrProductProperty *pCurrProductProperty)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrProductPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyIterator��һ���Բ�Ʒ���Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyIterator
{
public:
	///���췽��
	CCurrProductPropertyIterator(void)
	{
	}

	///���췽��
	CCurrProductPropertyIterator(CCurrProductPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrProductPropertyIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrProductProperty
	///@return	��һ����������CCurrProductProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrProductProperty *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrProductPropertyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrProductProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrProductProperty * pCurrProductProperty,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrProductPropertyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrInstrumentProperty��һ���洢��Լ���ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrInstrumentProperty
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! CreateDate.isValid())
			return 0;
		if (! OpenDate.isValid())
			return 0;
		if (! ExpireDate.isValid())
			return 0;
		if (! StartDelivDate.isValid())
			return 0;
		if (! EndDelivDate.isValid())
			return 0;
		if (! BasisPrice.isValid())
			return 0;
		if (! MaxMarketOrderVolume.isValid())
			return 0;
		if (! MinMarketOrderVolume.isValid())
			return 0;
		if (! MaxLimitOrderVolume.isValid())
			return 0;
		if (! MinLimitOrderVolume.isValid())
			return 0;
		if (! PriceTick.isValid())
			return 0;
		if (! AllowDelivPersonOpen.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstLifePhase.isValid())
			return 0;
		if (! IsFirstTradingDay.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrInstrumentProperty *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CDateType CreateDate;
	///������
	CDateType OpenDate;
	///������
	CDateType ExpireDate;
	///��ʼ������
	CDateType StartDelivDate;
	///��󽻸���
	CDateType EndDelivDate;
	///���ƻ�׼��
	CPriceType BasisPrice;
	///�м۵�����µ���
	CVolumeType MaxMarketOrderVolume;
	///�м۵���С�µ���
	CVolumeType MinMarketOrderVolume;
	///�޼۵�����µ���
	CVolumeType MaxLimitOrderVolume;
	///�޼۵���С�µ���
	CVolumeType MinLimitOrderVolume;
	///��С�䶯��λ
	CPriceType PriceTick;
	///��������Ȼ�˿���
	CMonthCountType AllowDelivPersonOpen;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Լ��������״̬
	CInstLifePhaseType InstLifePhase;
	///�Ƿ��׽�����
	CBoolType IsFirstTradingDay;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrInstrumentProperty CCurrInstrumentProperty;

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyActionTrigger�ǲ�����Լ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyActionTrigger
{
public:
	///���췽��
	CCurrInstrumentPropertyActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrInstrumentPropertyActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrInstrumentPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrInstrumentProperty	Ҫ�����CurrInstrumentProperty
	virtual void beforeAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrInstrumentProperty	�Ѿ������CurrInstrumentProperty
	virtual void afterAdd(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	�µ�ֵ
	virtual void beforeUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	virtual void afterUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrInstrumentProperty	Ҫɾ����CCurrInstrumentProperty
	virtual void beforeRemove(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrInstrumentPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyCommitTrigger��ȷ�Ϻ�Լ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyCommitTrigger
{
public:
	///���췽��
	CCurrInstrumentPropertyCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrInstrumentPropertyCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrInstrumentPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrInstrumentProperty	�Ѿ������CurrInstrumentProperty
	virtual void commitAdd(CCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	///@param	poldCurrInstrumentProperty	ԭ����ֵ
	virtual void commitUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pOldCurrInstrumentProperty)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrInstrumentProperty	�Ѿ�ɾ����CCurrInstrumentProperty
	virtual void commitRemove(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrInstrumentPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyIterator��һ���Ժ�Լ���Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyIterator
{
public:
	///���췽��
	CCurrInstrumentPropertyIterator(void)
	{
	}

	///���췽��
	CCurrInstrumentPropertyIterator(CCurrInstrumentPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrInstrumentPropertyIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrInstrumentProperty
	///@return	��һ����������CCurrInstrumentProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentProperty *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrInstrumentPropertyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentProperty * pCurrInstrumentProperty,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrInstrumentPropertyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrPriceBanding��һ���洢��ǰ�۸�󶨵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrPriceBanding
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! PriceLimitType.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! RoundingMode.isValid())
			return 0;
		if (! UpperValue.isValid())
			return 0;
		if (! LowerValue.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrPriceBanding *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�޼�����
	CPriceLimitTypeType PriceLimitType;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///���뷽ʽ
	CRoundingModeType RoundingMode;
	///����
	CPriceType UpperValue;
	///����
	CPriceType LowerValue;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///���׽׶α��
	CTradingSegmentSNType TradingSegmentSN;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrPriceBanding CCurrPriceBanding;

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingActionTrigger�ǲ�����ǰ�۸��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingActionTrigger
{
public:
	///���췽��
	CCurrPriceBandingActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrPriceBandingActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrPriceBandingFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrPriceBanding	Ҫ�����CurrPriceBanding
	virtual void beforeAdd(CWriteableCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrPriceBanding	�Ѿ������CurrPriceBanding
	virtual void afterAdd(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	///@param	pNewCurrPriceBanding	�µ�ֵ
	virtual void beforeUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	virtual void afterUpdate(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrPriceBanding	Ҫɾ����CCurrPriceBanding
	virtual void beforeRemove(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrPriceBandingFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingCommitTrigger��ȷ�ϵ�ǰ�۸��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingCommitTrigger
{
public:
	///���췽��
	CCurrPriceBandingCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrPriceBandingCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrPriceBandingFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrPriceBanding	�Ѿ������CurrPriceBanding
	virtual void commitAdd(CCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	///@param	poldCurrPriceBanding	ԭ����ֵ
	virtual void commitUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pOldCurrPriceBanding)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrPriceBanding	�Ѿ�ɾ����CCurrPriceBanding
	virtual void commitRemove(CWriteableCurrPriceBanding *pCurrPriceBanding)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrPriceBandingFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingIterator��һ���Ե�ǰ�۸�󶨵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingIterator
{
public:
	///���췽��
	CCurrPriceBandingIterator(void)
	{
	}

	///���췽��
	CCurrPriceBandingIterator(CCurrPriceBandingFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPriceBandingIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrPriceBanding
	///@return	��һ����������CCurrPriceBanding������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPriceBanding *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrPriceBandingFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPriceBanding ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPriceBanding * pCurrPriceBanding,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrPriceBandingFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrMarginRate��һ���洢�����Լ��֤���ʵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrMarginRate
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! MarginCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrMarginRate *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��֤���㷨����
	CMarginCalcIDType MarginCalcID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrMarginRate CCurrMarginRate;

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateActionTrigger�ǲ��������Լ��֤����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateActionTrigger
{
public:
	///���췽��
	CCurrMarginRateActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrMarginRateActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrMarginRate	Ҫ�����CurrMarginRate
	virtual void beforeAdd(CWriteableCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrMarginRate	�Ѿ������CurrMarginRate
	virtual void afterAdd(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	///@param	pNewCurrMarginRate	�µ�ֵ
	virtual void beforeUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	virtual void afterUpdate(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrMarginRate	Ҫɾ����CCurrMarginRate
	virtual void beforeRemove(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateCommitTrigger��ȷ�ϵ����Լ��֤����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateCommitTrigger
{
public:
	///���췽��
	CCurrMarginRateCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrMarginRateCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrMarginRate	�Ѿ������CurrMarginRate
	virtual void commitAdd(CCurrMarginRate *pCurrMarginRate)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	///@param	poldCurrMarginRate	ԭ����ֵ
	virtual void commitUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pOldCurrMarginRate)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrMarginRate	�Ѿ�ɾ����CCurrMarginRate
	virtual void commitRemove(CWriteableCurrMarginRate *pCurrMarginRate)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateIterator��һ���Ե����Լ��֤���ʵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateIterator
{
public:
	///���췽��
	CCurrMarginRateIterator(void)
	{
	}

	///���췽��
	CCurrMarginRateIterator(CCurrMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrMarginRateIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrMarginRate
	///@return	��һ����������CCurrMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRate *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrMarginRateFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRate * pCurrMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrMarginRateFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrMarginRateDetail��һ���洢�����Լ��֤���ʵ���ϸ���ݵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrMarginRateDetail
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongMarginRatio.isValid())
			return 0;
		if (! ShortMarginRatio.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrMarginRateDetail *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///���׽�ɫ
	CTradingRoleType TradingRole;
	///Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ��֤����
	CRatioType LongMarginRatio;
	///��ͷ��֤����
	CRatioType ShortMarginRatio;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	unsigned int HashInstrumentAndParticipant;
	
	///����InstrumentAndParticipant��hashֵ
	void calHashInstrumentAndParticipant(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		key=HedgeFlag.hash(key);
		HashInstrumentAndParticipant=key;
	}
	
	///������Ҫ���������InstrumentAndParticipant��hashֵ
	void updateHashInstrumentAndParticipant(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashInstrumentAndParticipant();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashInstrumentAndParticipant();
	}
	

private:
};

typedef const CWriteableCurrMarginRateDetail CCurrMarginRateDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailActionTrigger�ǲ��������Լ��֤���ʵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailActionTrigger
{
public:
	///���췽��
	CCurrMarginRateDetailActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrMarginRateDetailActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrMarginRateDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrMarginRateDetail	Ҫ�����CurrMarginRateDetail
	virtual void beforeAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrMarginRateDetail	�Ѿ������CurrMarginRateDetail
	virtual void afterAdd(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	virtual void afterUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrMarginRateDetail	Ҫɾ����CCurrMarginRateDetail
	virtual void beforeRemove(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrMarginRateDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailCommitTrigger��ȷ�ϵ����Լ��֤���ʵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailCommitTrigger
{
public:
	///���췽��
	CCurrMarginRateDetailCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrMarginRateDetailCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrMarginRateDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrMarginRateDetail	�Ѿ������CurrMarginRateDetail
	virtual void commitAdd(CCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	///@param	poldCurrMarginRateDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pOldCurrMarginRateDetail)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrMarginRateDetail	�Ѿ�ɾ����CCurrMarginRateDetail
	virtual void commitRemove(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrMarginRateDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailIterator��һ���Ե����Լ��֤���ʵ���ϸ���ݵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailIterator
{
public:
	///���췽��
	CCurrMarginRateDetailIterator(void)
	{
	}

	///���췽��
	CCurrMarginRateDetailIterator(CCurrMarginRateDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrMarginRateDetailIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrMarginRateDetail
	///@return	��һ����������CCurrMarginRateDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrMarginRateDetail *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrMarginRateDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrMarginRateDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrMarginRateDetail * pCurrMarginRateDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrMarginRateDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrPartPosiLimit��һ���洢��ǰ��Ա��Լ�޲ֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrPartPosiLimit
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! PartPosiLimitCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrPartPosiLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Ա�޲��㷨����
	CPartPosiLimitCalcIDType PartPosiLimitCalcID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrPartPosiLimit CCurrPartPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitActionTrigger�ǲ�����ǰ��Ա��Լ�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitActionTrigger
{
public:
	///���췽��
	CCurrPartPosiLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrPartPosiLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrPartPosiLimit	Ҫ�����CurrPartPosiLimit
	virtual void beforeAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrPartPosiLimit	�Ѿ������CurrPartPosiLimit
	virtual void afterAdd(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	virtual void afterUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrPartPosiLimit	Ҫɾ����CCurrPartPosiLimit
	virtual void beforeRemove(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitCommitTrigger��ȷ�ϵ�ǰ��Ա��Լ�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitCommitTrigger
{
public:
	///���췽��
	CCurrPartPosiLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrPartPosiLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrPartPosiLimit	�Ѿ������CurrPartPosiLimit
	virtual void commitAdd(CCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	///@param	poldCurrPartPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pOldCurrPartPosiLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrPartPosiLimit	�Ѿ�ɾ����CCurrPartPosiLimit
	virtual void commitRemove(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitIterator��һ���Ե�ǰ��Ա��Լ�޲ֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitIterator
{
public:
	///���췽��
	CCurrPartPosiLimitIterator(void)
	{
	}

	///���췽��
	CCurrPartPosiLimitIterator(CCurrPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPartPosiLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrPartPosiLimit
	///@return	��һ����������CCurrPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrPartPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimit * pCurrPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrPartPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrPartPosiLimitDetail��һ���洢��ǰ��Ա��Լ�޲ֵ���ϸ���ݵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrPartPosiLimitDetail
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrPartPosiLimitDetail *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType TradingRole;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrPartPosiLimitDetail CCurrPartPosiLimitDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailActionTrigger�ǲ�����ǰ��Ա��Լ�޲ֵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailActionTrigger
{
public:
	///���췽��
	CCurrPartPosiLimitDetailActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrPartPosiLimitDetailActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrPartPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrPartPosiLimitDetail	Ҫ�����CurrPartPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrPartPosiLimitDetail	�Ѿ������CurrPartPosiLimitDetail
	virtual void afterAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	virtual void afterUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrPartPosiLimitDetail	Ҫɾ����CCurrPartPosiLimitDetail
	virtual void beforeRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrPartPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailCommitTrigger��ȷ�ϵ�ǰ��Ա��Լ�޲ֵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailCommitTrigger
{
public:
	///���췽��
	CCurrPartPosiLimitDetailCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrPartPosiLimitDetailCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrPartPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrPartPosiLimitDetail	�Ѿ������CurrPartPosiLimitDetail
	virtual void commitAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	///@param	poldCurrPartPosiLimitDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pOldCurrPartPosiLimitDetail)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrPartPosiLimitDetail	�Ѿ�ɾ����CCurrPartPosiLimitDetail
	virtual void commitRemove(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrPartPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailIterator��һ���Ե�ǰ��Ա��Լ�޲ֵ���ϸ���ݵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailIterator
{
public:
	///���췽��
	CCurrPartPosiLimitDetailIterator(void)
	{
	}

	///���췽��
	CCurrPartPosiLimitDetailIterator(CCurrPartPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPartPosiLimitDetailIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrPartPosiLimitDetail
	///@return	��һ����������CCurrPartPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrPartPosiLimitDetail *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrPartPosiLimitDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrPartPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrPartPosiLimitDetail * pCurrPartPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrPartPosiLimitDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrClientPosiLimit��һ���洢��ǰ�ͻ���Լ�޲ֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrClientPosiLimit
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ClientPosiLimitCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrClientPosiLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�ͻ��޲��㷨����
	CClientPosiLimitCalcIDType ClientPosiLimitCalcID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrClientPosiLimit CCurrClientPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitActionTrigger�ǲ�����ǰ�ͻ���Լ�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitActionTrigger
{
public:
	///���췽��
	CCurrClientPosiLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrClientPosiLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrClientPosiLimit	Ҫ�����CurrClientPosiLimit
	virtual void beforeAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrClientPosiLimit	�Ѿ������CurrClientPosiLimit
	virtual void afterAdd(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	virtual void afterUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrClientPosiLimit	Ҫɾ����CCurrClientPosiLimit
	virtual void beforeRemove(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitCommitTrigger��ȷ�ϵ�ǰ�ͻ���Լ�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitCommitTrigger
{
public:
	///���췽��
	CCurrClientPosiLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrClientPosiLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrClientPosiLimit	�Ѿ������CurrClientPosiLimit
	virtual void commitAdd(CCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	///@param	poldCurrClientPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pOldCurrClientPosiLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrClientPosiLimit	�Ѿ�ɾ����CCurrClientPosiLimit
	virtual void commitRemove(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitIterator��һ���Ե�ǰ�ͻ���Լ�޲ֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitIterator
{
public:
	///���췽��
	CCurrClientPosiLimitIterator(void)
	{
	}

	///���췽��
	CCurrClientPosiLimitIterator(CCurrClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrClientPosiLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrClientPosiLimit
	///@return	��һ����������CCurrClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrClientPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimit * pCurrClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrClientPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrClientPosiLimitDetail��һ���洢��ǰ�ͻ���Լ�޲ֵ���ϸ���ݵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrClientPosiLimitDetail
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrClientPosiLimitDetail *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientTypeType ClientType;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrClientPosiLimitDetail CCurrClientPosiLimitDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailActionTrigger�ǲ�����ǰ�ͻ���Լ�޲ֵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailActionTrigger
{
public:
	///���췽��
	CCurrClientPosiLimitDetailActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrClientPosiLimitDetailActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrClientPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrClientPosiLimitDetail	Ҫ�����CurrClientPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrClientPosiLimitDetail	�Ѿ������CurrClientPosiLimitDetail
	virtual void afterAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	virtual void afterUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrClientPosiLimitDetail	Ҫɾ����CCurrClientPosiLimitDetail
	virtual void beforeRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrClientPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailCommitTrigger��ȷ�ϵ�ǰ�ͻ���Լ�޲ֵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailCommitTrigger
{
public:
	///���췽��
	CCurrClientPosiLimitDetailCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrClientPosiLimitDetailCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrClientPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrClientPosiLimitDetail	�Ѿ������CurrClientPosiLimitDetail
	virtual void commitAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	///@param	poldCurrClientPosiLimitDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pOldCurrClientPosiLimitDetail)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrClientPosiLimitDetail	�Ѿ�ɾ����CCurrClientPosiLimitDetail
	virtual void commitRemove(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrClientPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailIterator��һ���Ե�ǰ�ͻ���Լ�޲ֵ���ϸ���ݵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailIterator
{
public:
	///���췽��
	CCurrClientPosiLimitDetailIterator(void)
	{
	}

	///���췽��
	CCurrClientPosiLimitDetailIterator(CCurrClientPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrClientPosiLimitDetailIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrClientPosiLimitDetail
	///@return	��һ����������CCurrClientPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrClientPosiLimitDetail *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrClientPosiLimitDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrClientPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrClientPosiLimitDetail * pCurrClientPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrClientPosiLimitDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrSpecialPosiLimit��һ���洢��ǰ����ͻ���Լ�޲ֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrSpecialPosiLimit
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! ClientPosiLimitCalcID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrSpecialPosiLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�ͻ��޲��㷨����
	CClientPosiLimitCalcIDType ClientPosiLimitCalcID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientIDType ClientID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrSpecialPosiLimit CCurrSpecialPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitActionTrigger�ǲ�����ǰ����ͻ���Լ�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitActionTrigger
{
public:
	///���췽��
	CCurrSpecialPosiLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrSpecialPosiLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrSpecialPosiLimit	Ҫ�����CurrSpecialPosiLimit
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrSpecialPosiLimit	�Ѿ������CurrSpecialPosiLimit
	virtual void afterAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	virtual void afterUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrSpecialPosiLimit	Ҫɾ����CCurrSpecialPosiLimit
	virtual void beforeRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitCommitTrigger��ȷ�ϵ�ǰ����ͻ���Լ�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitCommitTrigger
{
public:
	///���췽��
	CCurrSpecialPosiLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrSpecialPosiLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrSpecialPosiLimit	�Ѿ������CurrSpecialPosiLimit
	virtual void commitAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	///@param	poldCurrSpecialPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pOldCurrSpecialPosiLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrSpecialPosiLimit	�Ѿ�ɾ����CCurrSpecialPosiLimit
	virtual void commitRemove(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitIterator��һ���Ե�ǰ����ͻ���Լ�޲ֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitIterator
{
public:
	///���췽��
	CCurrSpecialPosiLimitIterator(void)
	{
	}

	///���췽��
	CCurrSpecialPosiLimitIterator(CCurrSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrSpecialPosiLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrSpecialPosiLimit
	///@return	��һ����������CCurrSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrSpecialPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimit * pCurrSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrSpecialPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrSpecialPosiLimitDetail��һ���洢��ǰ����ͻ���Լ�޲ֵ���ϸ���ݵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrSpecialPosiLimitDetail
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrSpecialPosiLimitDetail *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientIDType ClientID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrSpecialPosiLimitDetail CCurrSpecialPosiLimitDetail;

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailActionTrigger�ǲ�����ǰ����ͻ���Լ�޲ֵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailActionTrigger
{
public:
	///���췽��
	CCurrSpecialPosiLimitDetailActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrSpecialPosiLimitDetailActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrSpecialPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrSpecialPosiLimitDetail	Ҫ�����CurrSpecialPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrSpecialPosiLimitDetail	�Ѿ������CurrSpecialPosiLimitDetail
	virtual void afterAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	virtual void afterUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrSpecialPosiLimitDetail	Ҫɾ����CCurrSpecialPosiLimitDetail
	virtual void beforeRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrSpecialPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailCommitTrigger��ȷ�ϵ�ǰ����ͻ���Լ�޲ֵ���ϸ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailCommitTrigger
{
public:
	///���췽��
	CCurrSpecialPosiLimitDetailCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrSpecialPosiLimitDetailCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrSpecialPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrSpecialPosiLimitDetail	�Ѿ������CurrSpecialPosiLimitDetail
	virtual void commitAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	///@param	poldCurrSpecialPosiLimitDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pOldCurrSpecialPosiLimitDetail)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrSpecialPosiLimitDetail	�Ѿ�ɾ����CCurrSpecialPosiLimitDetail
	virtual void commitRemove(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrSpecialPosiLimitDetailFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailIterator��һ���Ե�ǰ����ͻ���Լ�޲ֵ���ϸ���ݵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailIterator
{
public:
	///���췽��
	CCurrSpecialPosiLimitDetailIterator(void)
	{
	}

	///���췽��
	CCurrSpecialPosiLimitDetailIterator(CCurrSpecialPosiLimitDetailFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrSpecialPosiLimitDetailIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrSpecialPosiLimitDetail
	///@return	��һ����������CCurrSpecialPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrSpecialPosiLimitDetail *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrSpecialPosiLimitDetailFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrSpecialPosiLimitDetail ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrSpecialPosiLimitDetail * pCurrSpecialPosiLimitDetail,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrSpecialPosiLimitDetailFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrHedgeRule��һ���洢��ǰ��Լ���ڱ�ֵ���ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrHedgeRule
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeUsageType.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! HedgeCloseTodayType.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrHedgeRule *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///�ױ����ʹ������
	CHedgeUsageTypeType HedgeUsageType;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ױ����ƽ�������
	CHedgeCloseTodayTypeType HedgeCloseTodayType;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrHedgeRule CCurrHedgeRule;

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleActionTrigger�ǲ�����ǰ��Լ���ڱ�ֵ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleActionTrigger
{
public:
	///���췽��
	CCurrHedgeRuleActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrHedgeRuleActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrHedgeRuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrHedgeRule	Ҫ�����CurrHedgeRule
	virtual void beforeAdd(CWriteableCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrHedgeRule	�Ѿ������CurrHedgeRule
	virtual void afterAdd(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	///@param	pNewCurrHedgeRule	�µ�ֵ
	virtual void beforeUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	virtual void afterUpdate(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrHedgeRule	Ҫɾ����CCurrHedgeRule
	virtual void beforeRemove(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrHedgeRuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleCommitTrigger��ȷ�ϵ�ǰ��Լ���ڱ�ֵ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleCommitTrigger
{
public:
	///���췽��
	CCurrHedgeRuleCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrHedgeRuleCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrHedgeRuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrHedgeRule	�Ѿ������CurrHedgeRule
	virtual void commitAdd(CCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	///@param	poldCurrHedgeRule	ԭ����ֵ
	virtual void commitUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pOldCurrHedgeRule)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrHedgeRule	�Ѿ�ɾ����CCurrHedgeRule
	virtual void commitRemove(CWriteableCurrHedgeRule *pCurrHedgeRule)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrHedgeRuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleIterator��һ���Ե�ǰ��Լ���ڱ�ֵ���Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleIterator
{
public:
	///���췽��
	CCurrHedgeRuleIterator(void)
	{
	}

	///���췽��
	CCurrHedgeRuleIterator(CCurrHedgeRuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrHedgeRuleIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrHedgeRule
	///@return	��һ����������CCurrHedgeRule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrHedgeRule *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrHedgeRuleFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrHedgeRule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrHedgeRule * pCurrHedgeRule,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrHedgeRuleFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrTradingSegmentAttr��һ���洢��ǰ��Լ���׽׶����ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrTradingSegmentAttr
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		if (! TradingSegmentName.isValid())
			return 0;
		if (! StartTime.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrTradingSegmentAttr *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///���׽׶α��
	CTradingSegmentSNType TradingSegmentSN;
	///���׽׶�����
	CTradingSegmentNameType TradingSegmentName;
	///��ʼʱ��
	CTimeType StartTime;
	///��Լ����״̬
	CInstrumentStatusType InstrumentStatus;
	///��Լ����
	CInstrumentIDType InstrumentID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrTradingSegmentAttr CCurrTradingSegmentAttr;

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrActionTrigger�ǲ�����ǰ��Լ���׽׶�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrActionTrigger
{
public:
	///���췽��
	CCurrTradingSegmentAttrActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrTradingSegmentAttrActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrTradingSegmentAttr	Ҫ�����CurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrTradingSegmentAttr	�Ѿ������CurrTradingSegmentAttr
	virtual void afterAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	�µ�ֵ
	virtual void beforeUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	virtual void afterUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrTradingSegmentAttr	Ҫɾ����CCurrTradingSegmentAttr
	virtual void beforeRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrCommitTrigger��ȷ�ϵ�ǰ��Լ���׽׶�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrCommitTrigger
{
public:
	///���췽��
	CCurrTradingSegmentAttrCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrTradingSegmentAttrCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrTradingSegmentAttr	�Ѿ������CurrTradingSegmentAttr
	virtual void commitAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	///@param	poldCurrTradingSegmentAttr	ԭ����ֵ
	virtual void commitUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pOldCurrTradingSegmentAttr)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrTradingSegmentAttr	�Ѿ�ɾ����CCurrTradingSegmentAttr
	virtual void commitRemove(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrIterator��һ���Ե�ǰ��Լ���׽׶����Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrIterator
{
public:
	///���췽��
	CCurrTradingSegmentAttrIterator(void)
	{
	}

	///���췽��
	CCurrTradingSegmentAttrIterator(CCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrTradingSegmentAttrIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrTradingSegmentAttr
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrTradingSegmentAttr *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrTradingSegmentAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrTradingSegmentAttr * pCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrTradingSegmentAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrFuse��һ���洢��ǰ��Լ�۶����ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrFuse
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! PriceLimitType.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! RoundingMode.isValid())
			return 0;
		if (! UpperValue.isValid())
			return 0;
		if (! LowerValue.isValid())
			return 0;
		if (! PriceLimitDuration.isValid())
			return 0;
		if (! FuseDuration.isValid())
			return 0;
		if (! TradingFlag.isValid())
			return 0;
		if (! NoFuseTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrFuse *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�޼�����
	CPriceLimitTypeType PriceLimitType;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///���뷽ʽ
	CRoundingModeType RoundingMode;
	///����
	CPriceType UpperValue;
	///����
	CPriceType LowerValue;
	///ͣ�����ʱ��
	CDurationType PriceLimitDuration;
	///�۶���
	CDurationType FuseDuration;
	///�۶����Ƿ���
	CBoolType TradingFlag;
	///�������۶�ʱ��
	CTimeType NoFuseTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrFuse CCurrFuse;

/////////////////////////////////////////////////////////////////////////
///CCurrFuseActionTrigger�ǲ�����ǰ��Լ�۶�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseActionTrigger
{
public:
	///���췽��
	CCurrFuseActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrFuseActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrFuseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrFuse	Ҫ�����CurrFuse
	virtual void beforeAdd(CWriteableCurrFuse *pCurrFuse)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrFuse	�Ѿ������CurrFuse
	virtual void afterAdd(CCurrFuse *pCurrFuse)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	///@param	pNewCurrFuse	�µ�ֵ
	virtual void beforeUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	virtual void afterUpdate(CCurrFuse *pCurrFuse)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrFuse	Ҫɾ����CCurrFuse
	virtual void beforeRemove(CCurrFuse *pCurrFuse)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrFuseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseCommitTrigger��ȷ�ϵ�ǰ��Լ�۶�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseCommitTrigger
{
public:
	///���췽��
	CCurrFuseCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrFuseCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrFuseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrFuse	�Ѿ������CurrFuse
	virtual void commitAdd(CCurrFuse *pCurrFuse)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	///@param	poldCurrFuse	ԭ����ֵ
	virtual void commitUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pOldCurrFuse)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrFuse	�Ѿ�ɾ����CCurrFuse
	virtual void commitRemove(CWriteableCurrFuse *pCurrFuse)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrFuseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseIterator��һ���Ե�ǰ��Լ�۶����Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseIterator
{
public:
	///���췽��
	CCurrFuseIterator(void)
	{
	}

	///���췽��
	CCurrFuseIterator(CCurrFuseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrFuseIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrFuse
	///@return	��һ����������CCurrFuse������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrFuse *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrFuseFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrFuse ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrFuse * pCurrFuse,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrFuseFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTradingAccount��һ���洢�����˻��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTradingAccount
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! PreBalance.isValid())
			return 0;
		if (! CurrMargin.isValid())
			return 0;
		if (! CloseProfit.isValid())
			return 0;
		if (! Premium.isValid())
			return 0;
		if (! Deposit.isValid())
			return 0;
		if (! Withdraw.isValid())
			return 0;
		if (! Balance.isValid())
			return 0;
		if (! Available.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! FrozenMargin.isValid())
			return 0;
		if (! FrozenPremium.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableTradingAccount *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///�ϴν���׼����
	CMoneyType PreBalance;
	///��ǰ��֤���ܶ�
	CMoneyType CurrMargin;
	///ƽ��ӯ��
	CMoneyType CloseProfit;
	///��ȨȨ������֧
	CMoneyType Premium;
	///�����
	CMoneyType Deposit;
	///������
	CMoneyType Withdraw;
	///�ڻ�����׼����
	CMoneyType Balance;
	///�����ʽ�
	CMoneyType Available;
	///�ʽ��ʺ�
	CAccountIDType AccountID;
	///����ı�֤��
	CMoneyType FrozenMargin;
	///�����Ȩ����
	CMoneyType FrozenPremium;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�Ļ���׼�����˻���ָ��
	///@param	pFactory	�����Ӧ�Ļ���׼�����˻���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ļ���׼�����˻���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableBaseReserveAccount *linkBaseReserveAccount(CBaseReserveAccountFactory *pFactory) const;

	///�����Ӧ�Ļ���׼�����˻�ָ��
	///@param	pBaseReserveAccount	Ҫ���ӵ��Ķ���
	///@return	�����pBaseReserveAccount
	const CWriteableBaseReserveAccount *linkBaseReserveAccount(const CWriteableBaseReserveAccount *pBaseReserveAccount) const
	{
		void *target=(void *)(&(this->pBaseReserveAccount));
		*((const CWriteableBaseReserveAccount **)target)=pBaseReserveAccount;
		return pBaseReserveAccount;
	}
	
	///��ȡ��Ӧ�Ļ���׼�����˻���ָ��
	///@return	�ҵ��Ķ�Ӧ�Ļ���׼�����˻���ָ�룬����Ҳ����򷵻�NULL
	const CWriteableBaseReserveAccount *getBaseReserveAccount(void) const
	{
		return pBaseReserveAccount;
	}

private:
	///��Ӧ�Ļ���׼�����˻�
	const CWriteableBaseReserveAccount *pBaseReserveAccount;
};

typedef const CWriteableTradingAccount CTradingAccount;

/////////////////////////////////////////////////////////////////////////
///CTradingAccountActionTrigger�ǲ��������˻�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountActionTrigger
{
public:
	///���췽��
	CTradingAccountActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CTradingAccountActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTradingAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pTradingAccount	Ҫ�����TradingAccount
	virtual void beforeAdd(CWriteableTradingAccount *pTradingAccount)
	{
		return;
	}
	
	///����󴥷�
	///@param	pTradingAccount	�Ѿ������TradingAccount
	virtual void afterAdd(CTradingAccount *pTradingAccount)
	{
		return;
	}

	///����ǰ����	
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	///@param	pNewTradingAccount	�µ�ֵ
	virtual void beforeUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	virtual void afterUpdate(CTradingAccount *pTradingAccount)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pTradingAccount	Ҫɾ����CTradingAccount
	virtual void beforeRemove(CTradingAccount *pTradingAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTradingAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountCommitTrigger��ȷ�Ͻ����˻�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountCommitTrigger
{
public:
	///���췽��
	CTradingAccountCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CTradingAccountCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTradingAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pTradingAccount	�Ѿ������TradingAccount
	virtual void commitAdd(CTradingAccount *pTradingAccount)
	{
		return;
	}

	///���º󴥷�
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	///@param	poldTradingAccount	ԭ����ֵ
	virtual void commitUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pOldTradingAccount)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pTradingAccount	�Ѿ�ɾ����CTradingAccount
	virtual void commitRemove(CWriteableTradingAccount *pTradingAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTradingAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountIterator��һ���Խ����˻���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountIterator
{
public:
	///���췽��
	CTradingAccountIterator(void)
	{
	}

	///���췽��
	CTradingAccountIterator(CTradingAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradingAccountIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��TradingAccount
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTradingAccount *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CTradingAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTradingAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTradingAccount * pTradingAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CTradingAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableBaseReserveAccount��һ���洢����׼�����˻��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableBaseReserveAccount
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! Reserve.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableBaseReserveAccount *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ʽ��ʺ�
	CAccountIDType AccountID;
	///����׼����
	CMoneyType Reserve;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableBaseReserveAccount CBaseReserveAccount;

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountActionTrigger�ǲ�������׼�����˻�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountActionTrigger
{
public:
	///���췽��
	CBaseReserveAccountActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CBaseReserveAccountActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CBaseReserveAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pBaseReserveAccount	Ҫ�����BaseReserveAccount
	virtual void beforeAdd(CWriteableBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
	
	///����󴥷�
	///@param	pBaseReserveAccount	�Ѿ������BaseReserveAccount
	virtual void afterAdd(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}

	///����ǰ����	
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	///@param	pNewBaseReserveAccount	�µ�ֵ
	virtual void beforeUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	virtual void afterUpdate(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pBaseReserveAccount	Ҫɾ����CBaseReserveAccount
	virtual void beforeRemove(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CBaseReserveAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountCommitTrigger��ȷ�ϻ���׼�����˻�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountCommitTrigger
{
public:
	///���췽��
	CBaseReserveAccountCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CBaseReserveAccountCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CBaseReserveAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pBaseReserveAccount	�Ѿ������BaseReserveAccount
	virtual void commitAdd(CBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}

	///���º󴥷�
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	///@param	poldBaseReserveAccount	ԭ����ֵ
	virtual void commitUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pOldBaseReserveAccount)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pBaseReserveAccount	�Ѿ�ɾ����CBaseReserveAccount
	virtual void commitRemove(CWriteableBaseReserveAccount *pBaseReserveAccount)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CBaseReserveAccountFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountIterator��һ���Ի���׼�����˻���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountIterator
{
public:
	///���췽��
	CBaseReserveAccountIterator(void)
	{
	}

	///���췽��
	CBaseReserveAccountIterator(CBaseReserveAccountFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBaseReserveAccountIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��BaseReserveAccount
	///@return	��һ����������CBaseReserveAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBaseReserveAccount *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CBaseReserveAccountFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBaseReserveAccount ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBaseReserveAccount * pBaseReserveAccount,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CBaseReserveAccountFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteablePartPosition��һ���洢��Ա�ֲֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteablePartPosition
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! YdPosition.isValid())
			return 0;
		if (! Position.isValid())
			return 0;
		if (! LongFrozen.isValid())
			return 0;
		if (! ShortFrozen.isValid())
			return 0;
		if (! YdLongFrozen.isValid())
			return 0;
		if (! YdShortFrozen.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteablePartPosition *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	///�ֲֶ�շ���
	CPosiDirectionType PosiDirection;
	///���ճֲ�
	CVolumeType YdPosition;
	///���ճֲ�
	CVolumeType Position;
	///��ͷ����
	CVolumeType LongFrozen;
	///��ͷ����
	CVolumeType ShortFrozen;
	///���ն�ͷ����
	CVolumeType YdLongFrozen;
	///���տ�ͷ����
	CVolumeType YdShortFrozen;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///���׽�ɫ
	CTradingRoleType TradingRole;
	unsigned int HashPartAndInstrument;
	
	///����PartAndInstrument��hashֵ
	void calHashPartAndInstrument(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=PosiDirection.hash(key);
		key=HedgeFlag.hash(key);
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		HashPartAndInstrument=key;
	}
	
	///������Ҫ���������PartAndInstrument��hashֵ
	void updateHashPartAndInstrument(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashPartAndInstrument();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashPartAndInstrument();
	}
	

private:
};

typedef const CWriteablePartPosition CPartPosition;

/////////////////////////////////////////////////////////////////////////
///CPartPositionActionTrigger�ǲ�����Ա�ֲ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionActionTrigger
{
public:
	///���췽��
	CPartPositionActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartPositionActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pPartPosition	Ҫ�����PartPosition
	virtual void beforeAdd(CWriteablePartPosition *pPartPosition)
	{
		return;
	}
	
	///����󴥷�
	///@param	pPartPosition	�Ѿ������PartPosition
	virtual void afterAdd(CPartPosition *pPartPosition)
	{
		return;
	}

	///����ǰ����	
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	///@param	pNewPartPosition	�µ�ֵ
	virtual void beforeUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	virtual void afterUpdate(CPartPosition *pPartPosition)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pPartPosition	Ҫɾ����CPartPosition
	virtual void beforeRemove(CPartPosition *pPartPosition)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionCommitTrigger��ȷ�ϻ�Ա�ֲ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionCommitTrigger
{
public:
	///���췽��
	CPartPositionCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CPartPositionCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pPartPosition	�Ѿ������PartPosition
	virtual void commitAdd(CPartPosition *pPartPosition)
	{
		return;
	}

	///���º󴥷�
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	///@param	poldPartPosition	ԭ����ֵ
	virtual void commitUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pOldPartPosition)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pPartPosition	�Ѿ�ɾ����CPartPosition
	virtual void commitRemove(CWriteablePartPosition *pPartPosition)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionIterator��һ���Ի�Ա�ֲֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionIterator
{
public:
	///���췽��
	CPartPositionIterator(void)
	{
	}

	///���췽��
	CPartPositionIterator(CPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartPositionIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��PartPosition
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CPartPosition *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CPartPositionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteablePartPosition * pPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CPartPositionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClientPosition��һ���洢�ͻ��ֲֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClientPosition
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! YdPosition.isValid())
			return 0;
		if (! Position.isValid())
			return 0;
		if (! LongFrozen.isValid())
			return 0;
		if (! ShortFrozen.isValid())
			return 0;
		if (! YdLongFrozen.isValid())
			return 0;
		if (! YdShortFrozen.isValid())
			return 0;
		if (! BuyTradeVolume.isValid())
			return 0;
		if (! SellTradeVolume.isValid())
			return 0;
		if (! PositionCost.isValid())
			return 0;
		if (! YdPositionCost.isValid())
			return 0;
		if (! UseMargin.isValid())
			return 0;
		if (! FrozenMargin.isValid())
			return 0;
		if (! LongFrozenMargin.isValid())
			return 0;
		if (! ShortFrozenMargin.isValid())
			return 0;
		if (! FrozenPremium.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableClientPosition *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	///�ֲֶ�շ���
	CPosiDirectionType PosiDirection;
	///���ճֲ�
	CVolumeType YdPosition;
	///���ճֲ�
	CVolumeType Position;
	///��ͷ����
	CVolumeType LongFrozen;
	///��ͷ����
	CVolumeType ShortFrozen;
	///���ն�ͷ����
	CVolumeType YdLongFrozen;
	///���տ�ͷ����
	CVolumeType YdShortFrozen;
	///������ɽ���
	CVolumeType BuyTradeVolume;
	///�������ɽ���
	CVolumeType SellTradeVolume;
	///�ֲֳɱ�
	CMoneyType PositionCost;
	///���ճֲֳɱ�
	CMoneyType YdPositionCost;
	///ռ�õı�֤��
	CMoneyType UseMargin;
	///����ı�֤��
	CMoneyType FrozenMargin;
	///��ͷ����ı�֤��
	CMoneyType LongFrozenMargin;
	///��ͷ����ı�֤��
	CMoneyType ShortFrozenMargin;
	///�����Ȩ����
	CMoneyType FrozenPremium;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	unsigned int HashClientAndInstrument;
	
	///����ClientAndInstrument��hashֵ
	void calHashClientAndInstrument(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=PosiDirection.hash(key);
		key=HedgeFlag.hash(key);
		key=ClientID.hash(key);
		HashClientAndInstrument=key;
	}
	
	///������Ҫ���������ClientAndInstrument��hashֵ
	void updateHashClientAndInstrument(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashClientAndInstrument();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashClientAndInstrument();
	}
	
	///�����Ӧ�����ö�ȵ�ָ��
	///@param	pFactory	�����Ӧ�����ö�ȵ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�����ö�ȵ�ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableCreditLimit *linkCreditLimit(CCreditLimitFactory *pFactory) const;

	///�����Ӧ�����ö��ָ��
	///@param	pCreditLimit	Ҫ���ӵ��Ķ���
	///@return	�����pCreditLimit
	const CWriteableCreditLimit *linkCreditLimit(const CWriteableCreditLimit *pCreditLimit) const
	{
		void *target=(void *)(&(this->pCreditLimit));
		*((const CWriteableCreditLimit **)target)=pCreditLimit;
		return pCreditLimit;
	}
	
	///��ȡ��Ӧ�����ö�ȵ�ָ��
	///@return	�ҵ��Ķ�Ӧ�����ö�ȵ�ָ�룬����Ҳ����򷵻�NULL
	const CWriteableCreditLimit *getCreditLimit(void) const
	{
		return pCreditLimit;
	}
	///�����Ӧ�Ļ�Ա��ɫ�ʺŵ�ָ��
	///@param	pFactory	�����Ӧ�Ļ�Ա��ɫ�ʺŵ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ļ�Ա��ɫ�ʺŵ�ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteablePartRoleAccount *linkPartRoleAccount(CPartRoleAccountFactory *pFactory) const;

	///�����Ӧ�Ļ�Ա��ɫ�ʺ�ָ��
	///@param	pPartRoleAccount	Ҫ���ӵ��Ķ���
	///@return	�����pPartRoleAccount
	const CWriteablePartRoleAccount *linkPartRoleAccount(const CWriteablePartRoleAccount *pPartRoleAccount) const
	{
		void *target=(void *)(&(this->pPartRoleAccount));
		*((const CWriteablePartRoleAccount **)target)=pPartRoleAccount;
		return pPartRoleAccount;
	}
	
	///��ȡ��Ӧ�Ļ�Ա��ɫ�ʺŵ�ָ��
	///@return	�ҵ��Ķ�Ӧ�Ļ�Ա��ɫ�ʺŵ�ָ�룬����Ҳ����򷵻�NULL
	const CWriteablePartRoleAccount *getPartRoleAccount(void) const
	{
		return pPartRoleAccount;
	}

private:
	///��Ӧ�����ö��
	const CWriteableCreditLimit *pCreditLimit;
	///��Ӧ�Ļ�Ա��ɫ�ʺ�
	const CWriteablePartRoleAccount *pPartRoleAccount;
};

typedef const CWriteableClientPosition CClientPosition;

/////////////////////////////////////////////////////////////////////////
///CClientPositionActionTrigger�ǲ����ͻ��ֲ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionActionTrigger
{
public:
	///���췽��
	CClientPositionActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientPositionActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pClientPosition	Ҫ�����ClientPosition
	virtual void beforeAdd(CWriteableClientPosition *pClientPosition)
	{
		return;
	}
	
	///����󴥷�
	///@param	pClientPosition	�Ѿ������ClientPosition
	virtual void afterAdd(CClientPosition *pClientPosition)
	{
		return;
	}

	///����ǰ����	
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	///@param	pNewClientPosition	�µ�ֵ
	virtual void beforeUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	virtual void afterUpdate(CClientPosition *pClientPosition)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pClientPosition	Ҫɾ����CClientPosition
	virtual void beforeRemove(CClientPosition *pClientPosition)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionCommitTrigger��ȷ�Ͽͻ��ֲ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionCommitTrigger
{
public:
	///���췽��
	CClientPositionCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CClientPositionCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClientPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pClientPosition	�Ѿ������ClientPosition
	virtual void commitAdd(CClientPosition *pClientPosition)
	{
		return;
	}

	///���º󴥷�
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	///@param	poldClientPosition	ԭ����ֵ
	virtual void commitUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pOldClientPosition)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pClientPosition	�Ѿ�ɾ����CClientPosition
	virtual void commitRemove(CWriteableClientPosition *pClientPosition)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClientPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionIterator��һ���Կͻ��ֲֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionIterator
{
public:
	///���췽��
	CClientPositionIterator(void)
	{
	}

	///���췽��
	CClientPositionIterator(CClientPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ClientPosition
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClientPosition *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CClientPositionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClientPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClientPosition * pClientPosition,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CClientPositionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableHedgeVolume��һ���洢��ֵ������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableHedgeVolume
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! LongVolumeOriginal.isValid())
			return 0;
		if (! ShortVolumeOriginal.isValid())
			return 0;
		if (! LongVolume.isValid())
			return 0;
		if (! ShortVolume.isValid())
			return 0;
		if (! LongLimit.isValid())
			return 0;
		if (! ShortLimit.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableHedgeVolume *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��ͷ��ֵ������������
	CVolumeType LongVolumeOriginal;
	///��ͷ��ֵ������������
	CVolumeType ShortVolumeOriginal;
	///��ͷ��ֵ���
	CVolumeType LongVolume;
	///��ͷ��ֵ���
	CVolumeType ShortVolume;
	///��ͷ�޶�
	CVolumeType LongLimit;
	///��ͷ�޶�
	CVolumeType ShortLimit;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableHedgeVolume CHedgeVolume;

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeActionTrigger�ǲ�����ֵ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeActionTrigger
{
public:
	///���췽��
	CHedgeVolumeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CHedgeVolumeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CHedgeVolumeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pHedgeVolume	Ҫ�����HedgeVolume
	virtual void beforeAdd(CWriteableHedgeVolume *pHedgeVolume)
	{
		return;
	}
	
	///����󴥷�
	///@param	pHedgeVolume	�Ѿ������HedgeVolume
	virtual void afterAdd(CHedgeVolume *pHedgeVolume)
	{
		return;
	}

	///����ǰ����	
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	///@param	pNewHedgeVolume	�µ�ֵ
	virtual void beforeUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	virtual void afterUpdate(CHedgeVolume *pHedgeVolume)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pHedgeVolume	Ҫɾ����CHedgeVolume
	virtual void beforeRemove(CHedgeVolume *pHedgeVolume)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CHedgeVolumeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeCommitTrigger��ȷ�ϱ�ֵ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeCommitTrigger
{
public:
	///���췽��
	CHedgeVolumeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CHedgeVolumeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CHedgeVolumeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pHedgeVolume	�Ѿ������HedgeVolume
	virtual void commitAdd(CHedgeVolume *pHedgeVolume)
	{
		return;
	}

	///���º󴥷�
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	///@param	poldHedgeVolume	ԭ����ֵ
	virtual void commitUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pOldHedgeVolume)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pHedgeVolume	�Ѿ�ɾ����CHedgeVolume
	virtual void commitRemove(CWriteableHedgeVolume *pHedgeVolume)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CHedgeVolumeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeIterator��һ���Ա�ֵ�������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeIterator
{
public:
	///���췽��
	CHedgeVolumeIterator(void)
	{
	}

	///���췽��
	CHedgeVolumeIterator(CHedgeVolumeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CHedgeVolumeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��HedgeVolume
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CHedgeVolume *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CHedgeVolumeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pHedgeVolume ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableHedgeVolume * pHedgeVolume,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CHedgeVolumeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRemainOrder��һ���洢��ʷ�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRemainOrder
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! Tradable.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OrderPriceType.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! CombOffsetFlag.isValid())
			return 0;
		if (! CombHedgeFlag.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeTotalOriginal.isValid())
			return 0;
		if (! TimeCondition.isValid())
			return 0;
		if (! GTDDate.isValid())
			return 0;
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
			return 0;
		if (! ContingentCondition.isValid())
			return 0;
		if (! StopPrice.isValid())
			return 0;
		if (! ForceCloseReason.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! IsAutoSuspend.isValid())
			return 0;
		if (! OrderSource.isValid())
			return 0;
		if (! OrderStatus.isValid())
			return 0;
		if (! OrderType.isValid())
			return 0;
		if (! VolumeTraded.isValid())
			return 0;
		if (! VolumeTotal.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! ActiveTime.isValid())
			return 0;
		if (! SuspendTime.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ActiveUserID.isValid())
			return 0;
		if (! Priority.isValid())
			return 0;
		if (! TimeSortID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableRemainOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�Ƿ���Բμӽ���
	CBoolType Tradable;
	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///�������
	COrderSysIDType OrderSysID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�����۸�����
	COrderPriceTypeType OrderPriceType;
	///��������
	CDirectionType Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType CombHedgeFlag;
	///�۸�
	CPriceType LimitPrice;
	///����
	CVolumeType VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType TimeCondition;
	///GTD����
	CDateType GTDDate;
	///�ɽ�������
	CVolumeConditionType VolumeCondition;
	///��С�ɽ���
	CVolumeType MinVolume;
	///��������
	CContingentConditionType ContingentCondition;
	///ֹ���
	CPriceType StopPrice;
	///ǿƽԭ��
	CForceCloseReasonType ForceCloseReason;
	///���ر������
	COrderLocalIDType OrderLocalID;
	///�Զ������־
	CBoolType IsAutoSuspend;
	///������Դ
	COrderSourceType OrderSource;
	///����״̬
	COrderStatusType OrderStatus;
	///��������
	COrderTypeType OrderType;
	///��ɽ�����
	CVolumeType VolumeTraded;
	///ʣ������
	CVolumeType VolumeTotal;
	///��������
	CDateType InsertDate;
	///����ʱ��
	CTimeType InsertTime;
	///����ʱ��
	CTimeType ActiveTime;
	///����ʱ��
	CTimeType SuspendTime;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����ʱ��
	CTimeType CancelTime;
	///����޸Ľ����û�����
	CUserIDType ActiveUserID;
	///����Ȩ
	CPriorityType Priority;
	///��ʱ���Ŷӵ����
	CTimeSortIDType TimeSortID;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableRemainOrder CRemainOrder;

/////////////////////////////////////////////////////////////////////////
///CRemainOrderActionTrigger�ǲ�����ʷ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderActionTrigger
{
public:
	///���췽��
	CRemainOrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRemainOrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRemainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRemainOrder	Ҫ�����RemainOrder
	virtual void beforeAdd(CWriteableRemainOrder *pRemainOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRemainOrder	�Ѿ������RemainOrder
	virtual void afterAdd(CRemainOrder *pRemainOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	///@param	pNewRemainOrder	�µ�ֵ
	virtual void beforeUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	virtual void afterUpdate(CRemainOrder *pRemainOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRemainOrder	Ҫɾ����CRemainOrder
	virtual void beforeRemove(CRemainOrder *pRemainOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRemainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderCommitTrigger��ȷ����ʷ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderCommitTrigger
{
public:
	///���췽��
	CRemainOrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRemainOrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRemainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRemainOrder	�Ѿ������RemainOrder
	virtual void commitAdd(CRemainOrder *pRemainOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	///@param	poldRemainOrder	ԭ����ֵ
	virtual void commitUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pOldRemainOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRemainOrder	�Ѿ�ɾ����CRemainOrder
	virtual void commitRemove(CWriteableRemainOrder *pRemainOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRemainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderIterator��һ������ʷ������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderIterator
{
public:
	///���췽��
	CRemainOrderIterator(void)
	{
	}

	///���췽��
	CRemainOrderIterator(CRemainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRemainOrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RemainOrder
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRemainOrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRemainOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRemainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRemainOrder * pRemainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRemainOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMarketData��һ���洢����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMarketData
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! LastPrice.isValid())
			return 0;
		if (! PreSettlementPrice.isValid())
			return 0;
		if (! PreClosePrice.isValid())
			return 0;
		if (! PreOpenInterest.isValid())
			return 0;
		if (! OpenPrice.isValid())
			return 0;
		if (! HighestPrice.isValid())
			return 0;
		if (! LowestPrice.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Turnover.isValid())
			return 0;
		if (! OpenInterest.isValid())
			return 0;
		if (! ClosePrice.isValid())
			return 0;
		if (! SettlementPrice.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		if (! PreDelta.isValid())
			return 0;
		if (! CurrDelta.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! UpdateMillisec.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! TID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMarketData *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///���¼�
	CPriceType LastPrice;
	///�����
	CPriceType PreSettlementPrice;
	///������
	CPriceType PreClosePrice;
	///��ֲ���
	CLargeVolumeType PreOpenInterest;
	///����
	CPriceType OpenPrice;
	///��߼�
	CPriceType HighestPrice;
	///��ͼ�
	CPriceType LowestPrice;
	///����
	CVolumeType Volume;
	///�ɽ����
	CMoneyType Turnover;
	///�ֲ���
	CLargeVolumeType OpenInterest;
	///������
	CPriceType ClosePrice;
	///�����
	CPriceType SettlementPrice;
	///��ͣ���
	CPriceType UpperLimitPrice;
	///��ͣ���
	CPriceType LowerLimitPrice;
	///����ʵ��
	CRatioType PreDelta;
	///����ʵ��
	CRatioType CurrDelta;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����޸ĺ���
	CMillisecType UpdateMillisec;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///���к�
	CSequenceNoType TID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMarketData CMarketData;

/////////////////////////////////////////////////////////////////////////
///CMarketDataActionTrigger�ǲ�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataActionTrigger
{
public:
	///���췽��
	CMarketDataActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMarketData	Ҫ�����MarketData
	virtual void beforeAdd(CWriteableMarketData *pMarketData)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMarketData	�Ѿ������MarketData
	virtual void afterAdd(CMarketData *pMarketData)
	{
		return;
	}

	///����ǰ����	
	///@param	pMarketData	��ˢ�µ�CMarketData
	///@param	pNewMarketData	�µ�ֵ
	virtual void beforeUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMarketData	��ˢ�µ�CMarketData
	virtual void afterUpdate(CMarketData *pMarketData)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMarketData	Ҫɾ����CMarketData
	virtual void beforeRemove(CMarketData *pMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataCommitTrigger��ȷ������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataCommitTrigger
{
public:
	///���췽��
	CMarketDataCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMarketDataCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMarketData	�Ѿ������MarketData
	virtual void commitAdd(CMarketData *pMarketData)
	{
		return;
	}

	///���º󴥷�
	///@param	pMarketData	��ˢ�µ�CMarketData
	///@param	poldMarketData	ԭ����ֵ
	virtual void commitUpdate(CMarketData *pMarketData, CWriteableMarketData *pOldMarketData)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMarketData	�Ѿ�ɾ����CMarketData
	virtual void commitRemove(CWriteableMarketData *pMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataIterator��һ���������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataIterator
{
public:
	///���췽��
	CMarketDataIterator(void)
	{
	}

	///���췽��
	CMarketDataIterator(CMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MarketData
	///@return	��һ����������CMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMarketData *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMarketData * pMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableClearingPartPosition��һ���洢�����Ա�ֲֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableClearingPartPosition
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! YdPosition.isValid())
			return 0;
		if (! Position.isValid())
			return 0;
		if (! LongFrozen.isValid())
			return 0;
		if (! ShortFrozen.isValid())
			return 0;
		if (! YdLongFrozen.isValid())
			return 0;
		if (! YdShortFrozen.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableClearingPartPosition *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	///�ֲֶ�շ���
	CPosiDirectionType PosiDirection;
	///���ճֲ�
	CVolumeType YdPosition;
	///���ճֲ�
	CVolumeType Position;
	///��ͷ����
	CVolumeType LongFrozen;
	///��ͷ����
	CVolumeType ShortFrozen;
	///���ն�ͷ����
	CVolumeType YdLongFrozen;
	///���տ�ͷ����
	CVolumeType YdShortFrozen;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///���׽�ɫ
	CTradingRoleType TradingRole;
	unsigned int HashPartAndInstrument;
	
	///����PartAndInstrument��hashֵ
	void calHashPartAndInstrument(void)
	{
		unsigned key=0;
		key=InstrumentID.hash(key);
		key=PosiDirection.hash(key);
		key=HedgeFlag.hash(key);
		key=ParticipantID.hash(key);
		key=TradingRole.hash(key);
		HashPartAndInstrument=key;
	}
	
	///������Ҫ���������PartAndInstrument��hashֵ
	void updateHashPartAndInstrument(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashPartAndInstrument();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashPartAndInstrument();
	}
	

private:
};

typedef const CWriteableClearingPartPosition CClearingPartPosition;

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionActionTrigger�ǲ��������Ա�ֲ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionActionTrigger
{
public:
	///���췽��
	CClearingPartPositionActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CClearingPartPositionActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClearingPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pClearingPartPosition	Ҫ�����ClearingPartPosition
	virtual void beforeAdd(CWriteableClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
	
	///����󴥷�
	///@param	pClearingPartPosition	�Ѿ������ClearingPartPosition
	virtual void afterAdd(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}

	///����ǰ����	
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	///@param	pNewClearingPartPosition	�µ�ֵ
	virtual void beforeUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	virtual void afterUpdate(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pClearingPartPosition	Ҫɾ����CClearingPartPosition
	virtual void beforeRemove(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClearingPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionCommitTrigger��ȷ�Ͻ����Ա�ֲ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionCommitTrigger
{
public:
	///���췽��
	CClearingPartPositionCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CClearingPartPositionCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CClearingPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pClearingPartPosition	�Ѿ������ClearingPartPosition
	virtual void commitAdd(CClearingPartPosition *pClearingPartPosition)
	{
		return;
	}

	///���º󴥷�
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	///@param	poldClearingPartPosition	ԭ����ֵ
	virtual void commitUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pOldClearingPartPosition)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pClearingPartPosition	�Ѿ�ɾ����CClearingPartPosition
	virtual void commitRemove(CWriteableClearingPartPosition *pClearingPartPosition)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CClearingPartPositionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionIterator��һ���Խ����Ա�ֲֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionIterator
{
public:
	///���췽��
	CClearingPartPositionIterator(void)
	{
	}

	///���췽��
	CClearingPartPositionIterator(CClearingPartPositionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClearingPartPositionIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ClearingPartPosition
	///@return	��һ����������CClearingPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CClearingPartPosition *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CClearingPartPositionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pClearingPartPosition ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableClearingPartPosition * pClearingPartPosition,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CClearingPartPositionFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableInstrumentStatus��һ���洢��Լ״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableInstrumentStatus
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		if (! TradingSegmentSN.isValid())
			return 0;
		if (! EnterTime.isValid())
			return 0;
		if (! EnterReason.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableInstrumentStatus *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Լ����״̬
	CInstrumentStatusType InstrumentStatus;
	///���׽׶α��
	CTradingSegmentSNType TradingSegmentSN;
	///���뱾״̬ʱ��
	CTimeType EnterTime;
	///���뱾״̬ԭ��
	CInstStatusEnterReasonType EnterReason;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///�����Ӧ�ļ۸�󶨵�ָ��
	///@param	pFactory	�����Ӧ�ļ۸�󶨵�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ļ۸�󶨵�ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableCurrPriceBanding *linkCurrPriceBanding(CCurrPriceBandingFactory *pFactory) const;

	///�����Ӧ�ļ۸��ָ��
	///@param	pCurrPriceBanding	Ҫ���ӵ��Ķ���
	///@return	�����pCurrPriceBanding
	const CWriteableCurrPriceBanding *linkCurrPriceBanding(const CWriteableCurrPriceBanding *pCurrPriceBanding) const
	{
		void *target=(void *)(&(this->pCurrPriceBanding));
		*((const CWriteableCurrPriceBanding **)target)=pCurrPriceBanding;
		return pCurrPriceBanding;
	}
	
	///��ȡ��Ӧ�ļ۸�󶨵�ָ��
	///@return	�ҵ��Ķ�Ӧ�ļ۸�󶨵�ָ�룬����Ҳ����򷵻�NULL
	const CWriteableCurrPriceBanding *getCurrPriceBanding(void) const
	{
		return pCurrPriceBanding;
	}
	///�����Ӧ�����鷢��״̬��ָ��
	///@param	pFactory	�����Ӧ�����鷢��״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�����鷢��״̬��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableMdPubStatus *linkMdPubStatus(CMdPubStatusFactory *pFactory) const;

	///�����Ӧ�����鷢��״ָ̬��
	///@param	pMdPubStatus	Ҫ���ӵ��Ķ���
	///@return	�����pMdPubStatus
	const CWriteableMdPubStatus *linkMdPubStatus(const CWriteableMdPubStatus *pMdPubStatus) const
	{
		void *target=(void *)(&(this->pMdPubStatus));
		*((const CWriteableMdPubStatus **)target)=pMdPubStatus;
		return pMdPubStatus;
	}
	
	///��ȡ��Ӧ�����鷢��״̬��ָ��
	///@return	�ҵ��Ķ�Ӧ�����鷢��״̬��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableMdPubStatus *getMdPubStatus(void) const
	{
		return pMdPubStatus;
	}

private:
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
	///��Ӧ�ļ۸��
	const CWriteableCurrPriceBanding *pCurrPriceBanding;
	///��Ӧ�����鷢��״̬
	const CWriteableMdPubStatus *pMdPubStatus;
};

typedef const CWriteableInstrumentStatus CInstrumentStatus;

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusActionTrigger�ǲ�����Լ״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusActionTrigger
{
public:
	///���췽��
	CInstrumentStatusActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CInstrumentStatusActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pInstrumentStatus	Ҫ�����InstrumentStatus
	virtual void beforeAdd(CWriteableInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
	
	///����󴥷�
	///@param	pInstrumentStatus	�Ѿ������InstrumentStatus
	virtual void afterAdd(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}

	///����ǰ����	
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	///@param	pNewInstrumentStatus	�µ�ֵ
	virtual void beforeUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	virtual void afterUpdate(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pInstrumentStatus	Ҫɾ����CInstrumentStatus
	virtual void beforeRemove(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusCommitTrigger��ȷ�Ϻ�Լ״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusCommitTrigger
{
public:
	///���췽��
	CInstrumentStatusCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CInstrumentStatusCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pInstrumentStatus	�Ѿ������InstrumentStatus
	virtual void commitAdd(CInstrumentStatus *pInstrumentStatus)
	{
		return;
	}

	///���º󴥷�
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	///@param	poldInstrumentStatus	ԭ����ֵ
	virtual void commitUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pOldInstrumentStatus)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pInstrumentStatus	�Ѿ�ɾ����CInstrumentStatus
	virtual void commitRemove(CWriteableInstrumentStatus *pInstrumentStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusIterator��һ���Ժ�Լ״̬��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusIterator
{
public:
	///���췽��
	CInstrumentStatusIterator(void)
	{
	}

	///���췽��
	CInstrumentStatusIterator(CInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentStatusIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��InstrumentStatus
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CInstrumentStatus *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CInstrumentStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableInstrumentStatus * pInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CInstrumentStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableOrder��һ���洢�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOrder
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OrderPriceType.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! CombOffsetFlag.isValid())
			return 0;
		if (! CombHedgeFlag.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeTotalOriginal.isValid())
			return 0;
		if (! TimeCondition.isValid())
			return 0;
		if (! GTDDate.isValid())
			return 0;
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
			return 0;
		if (! ContingentCondition.isValid())
			return 0;
		if (! StopPrice.isValid())
			return 0;
		if (! ForceCloseReason.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! IsAutoSuspend.isValid())
			return 0;
		if (! OrderSource.isValid())
			return 0;
		if (! OrderStatus.isValid())
			return 0;
		if (! OrderType.isValid())
			return 0;
		if (! VolumeTraded.isValid())
			return 0;
		if (! VolumeTotal.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! ActiveTime.isValid())
			return 0;
		if (! SuspendTime.isValid())
			return 0;
		if (! UpdateTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ActiveUserID.isValid())
			return 0;
		if (! Priority.isValid())
			return 0;
		if (! TimeSortID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! Tradable.isValid())
			return 0;
		if (! ImplySortID.isValid())
			return 0;
		if (! TID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///�������
	COrderSysIDType OrderSysID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�����۸�����
	COrderPriceTypeType OrderPriceType;
	///��������
	CDirectionType Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType CombHedgeFlag;
	///�۸�
	CPriceType LimitPrice;
	///����
	CVolumeType VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType TimeCondition;
	///GTD����
	CDateType GTDDate;
	///�ɽ�������
	CVolumeConditionType VolumeCondition;
	///��С�ɽ���
	CVolumeType MinVolume;
	///��������
	CContingentConditionType ContingentCondition;
	///ֹ���
	CPriceType StopPrice;
	///ǿƽԭ��
	CForceCloseReasonType ForceCloseReason;
	///���ر������
	COrderLocalIDType OrderLocalID;
	///�Զ������־
	CBoolType IsAutoSuspend;
	///������Դ
	COrderSourceType OrderSource;
	///����״̬
	COrderStatusType OrderStatus;
	///��������
	COrderTypeType OrderType;
	///��ɽ�����
	CVolumeType VolumeTraded;
	///ʣ������
	CVolumeType VolumeTotal;
	///��������
	CDateType InsertDate;
	///����ʱ��
	CTimeType InsertTime;
	///����ʱ��
	CTimeType ActiveTime;
	///����ʱ��
	CTimeType SuspendTime;
	///����޸�ʱ��
	CTimeType UpdateTime;
	///����ʱ��
	CTimeType CancelTime;
	///����޸Ľ����û�����
	CUserIDType ActiveUserID;
	///����Ȩ
	CPriorityType Priority;
	///��ʱ���Ŷӵ����
	CTimeSortIDType TimeSortID;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///�Ƿ���Բμӽ���
	CBoolType Tradable;
	///��ʽ�Ƶ�ʱ�Ĵ���
	CTimeSortIDType ImplySortID;
	///���к�
	CSequenceNoType TID;
	unsigned int HashOrderSysID;
	
	///����OrderSysID��hashֵ
	void calHashOrderSysID(void)
	{
		unsigned key=0;
		key=OrderSysID.hash(key);
		HashOrderSysID=key;
	}
	
	///������Ҫ���������OrderSysID��hashֵ
	void updateHashOrderSysID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashOrderSysID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashOrderSysID();
	}
	
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///����ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///����ָ���Ļ�Ա�ͻ�ָ��
	///@param	pPartClient	Ҫ���ӵ��Ķ���
	///@return	�����pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///��ȡָ���Ļ�Ա�ͻ���ָ��
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}
	///�����Ӧ�Ŀͻ��ֲֵ�ָ��
	///@param	pFactory	�����Ӧ�Ŀͻ��ֲֵ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�Ŀͻ��ֲֵ�ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableClientPosition *linkClientPosition(CClientPositionFactory *pFactory) const;

	///�����Ӧ�Ŀͻ��ֲ�ָ��
	///@param	pClientPosition	Ҫ���ӵ��Ķ���
	///@return	�����pClientPosition
	const CWriteableClientPosition *linkClientPosition(const CWriteableClientPosition *pClientPosition) const
	{
		void *target=(void *)(&(this->pClientPosition));
		*((const CWriteableClientPosition **)target)=pClientPosition;
		return pClientPosition;
	}
	
	///��ȡ��Ӧ�Ŀͻ��ֲֵ�ָ��
	///@return	�ҵ��Ķ�Ӧ�Ŀͻ��ֲֵ�ָ�룬����Ҳ����򷵻�NULL
	const CWriteableClientPosition *getClientPosition(void) const
	{
		return pClientPosition;
	}

private:
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
	///ָ���Ļ�Ա�ͻ�
	const CWriteablePartClient *pPartClient;
	///��Ӧ�Ŀͻ��ֲ�
	const CWriteableClientPosition *pClientPosition;
};

typedef const CWriteableOrder COrder;

/////////////////////////////////////////////////////////////////////////
///COrderActionTrigger�ǲ�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderActionTrigger
{
public:
	///���췽��
	COrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~COrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(COrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pOrder	Ҫ�����Order
	virtual void beforeAdd(CWriteableOrder *pOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pOrder	�Ѿ������Order
	virtual void afterAdd(COrder *pOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pOrder	��ˢ�µ�COrder
	///@param	pNewOrder	�µ�ֵ
	virtual void beforeUpdate(COrder *pOrder, CWriteableOrder *pNewOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pOrder	��ˢ�µ�COrder
	virtual void afterUpdate(COrder *pOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pOrder	Ҫɾ����COrder
	virtual void beforeRemove(COrder *pOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	COrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderCommitTrigger��ȷ�ϱ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCommitTrigger
{
public:
	///���췽��
	COrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~COrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(COrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pOrder	�Ѿ������Order
	virtual void commitAdd(COrder *pOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pOrder	��ˢ�µ�COrder
	///@param	poldOrder	ԭ����ֵ
	virtual void commitUpdate(COrder *pOrder, CWriteableOrder *pOldOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pOrder	�Ѿ�ɾ����COrder
	virtual void commitRemove(CWriteableOrder *pOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	COrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COrderIterator��һ���Ա�����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderIterator
{
public:
	///���췽��
	COrderIterator(void)
	{
	}

	///���췽��
	COrderIterator(COrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Order
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	COrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOrder * pOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	COrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCombOrder��һ���洢��ϱ����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCombOrder
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! CombOrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeTotalOriginal.isValid())
			return 0;
		if (! CombOrderLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! InstrumentID1.isValid())
			return 0;
		if (! Direction1.isValid())
			return 0;
		if (! LegMultiple1.isValid())
			return 0;
		if (! OffsetFlag1.isValid())
			return 0;
		if (! HedgeFlag1.isValid())
			return 0;
		if (! InstrumentID2.isValid())
			return 0;
		if (! Direction2.isValid())
			return 0;
		if (! LegMultiple2.isValid())
			return 0;
		if (! OffsetFlag2.isValid())
			return 0;
		if (! HedgeFlag2.isValid())
			return 0;
		if (! InstrumentID3.isValid())
			return 0;
		if (! Direction3.isValid())
			return 0;
		if (! LegMultiple3.isValid())
			return 0;
		if (! OffsetFlag3.isValid())
			return 0;
		if (! HedgeFlag3.isValid())
			return 0;
		if (! InstrumentID4.isValid())
			return 0;
		if (! Direction4.isValid())
			return 0;
		if (! LegMultiple4.isValid())
			return 0;
		if (! OffsetFlag4.isValid())
			return 0;
		if (! HedgeFlag4.isValid())
			return 0;
		if (! OrderSource.isValid())
			return 0;
		if (! VolumeTraded.isValid())
			return 0;
		if (! VolumeTotal.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCombOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��ϱ������
	COrderSysIDType CombOrderSysID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///�۸�
	CPriceType LimitPrice;
	///����
	CVolumeType VolumeTotalOriginal;
	///���ر������
	COrderLocalIDType CombOrderLocalID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///��Լ����1
	CInstrumentIDType InstrumentID1;
	///��������1
	CDirectionType Direction1;
	///���ȳ���1
	CLegMultipleType LegMultiple1;
	///��ƽ��־1
	COffsetFlagType OffsetFlag1;
	///Ͷ���ױ���־1
	CHedgeFlagType HedgeFlag1;
	///��Լ����2
	CInstrumentIDType InstrumentID2;
	///��������2
	CDirectionType Direction2;
	///���ȳ���2
	CLegMultipleType LegMultiple2;
	///��ƽ��־2
	COffsetFlagType OffsetFlag2;
	///Ͷ���ױ���־2
	CHedgeFlagType HedgeFlag2;
	///��Լ����3
	CInstrumentIDType InstrumentID3;
	///��������3
	CDirectionType Direction3;
	///���ȳ���3
	CLegMultipleType LegMultiple3;
	///��ƽ��־3
	COffsetFlagType OffsetFlag3;
	///Ͷ���ױ���־3
	CHedgeFlagType HedgeFlag3;
	///��Լ����4
	CInstrumentIDType InstrumentID4;
	///��������4
	CDirectionType Direction4;
	///���ȳ���4
	CLegMultipleType LegMultiple4;
	///��ƽ��־4
	COffsetFlagType OffsetFlag4;
	///Ͷ���ױ���־4
	CHedgeFlagType HedgeFlag4;
	///������Դ
	COrderSourceType OrderSource;
	///��ɽ�����
	CVolumeType VolumeTraded;
	///ʣ������
	CVolumeType VolumeTotal;
	///��������
	CDateType InsertDate;
	///����ʱ��
	CTimeType InsertTime;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	unsigned int HashCombOrderSysID;
	
	///����CombOrderSysID��hashֵ
	void calHashCombOrderSysID(void)
	{
		unsigned key=0;
		key=CombOrderSysID.hash(key);
		HashCombOrderSysID=key;
	}
	
	///������Ҫ���������CombOrderSysID��hashֵ
	void updateHashCombOrderSysID(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashCombOrderSysID();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashCombOrderSysID();
	}
	
	///����ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///����ָ���Ļ�Ա�ͻ�ָ��
	///@param	pPartClient	Ҫ���ӵ��Ķ���
	///@return	�����pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///��ȡָ���Ļ�Ա�ͻ���ָ��
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}
	///�����Ӧ�ĺ�Լ1��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ1��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ1��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument1(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լ1ָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument1(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument1));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ1��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ1��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument1(void) const
	{
		return pInstrument1;
	}
	///�����Ӧ�ĺ�Լ2��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ2��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ2��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument2(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լ2ָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument2(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument2));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ2��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ2��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument2(void) const
	{
		return pInstrument2;
	}
	///�����Ӧ�ĺ�Լ3��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ3��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ3��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument3(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լ3ָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument3(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument3));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ3��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ3��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument3(void) const
	{
		return pInstrument3;
	}
	///�����Ӧ�ĺ�Լ4��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ4��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ4��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument4(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լ4ָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument4(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument4));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ4��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ4��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument4(void) const
	{
		return pInstrument4;
	}

private:
	///ָ���Ļ�Ա�ͻ�
	const CWriteablePartClient *pPartClient;
	///��Ӧ�ĺ�Լ1
	const CWriteableInstrument *pInstrument1;
	///��Ӧ�ĺ�Լ2
	const CWriteableInstrument *pInstrument2;
	///��Ӧ�ĺ�Լ3
	const CWriteableInstrument *pInstrument3;
	///��Ӧ�ĺ�Լ4
	const CWriteableInstrument *pInstrument4;
};

typedef const CWriteableCombOrder CCombOrder;

/////////////////////////////////////////////////////////////////////////
///CCombOrderActionTrigger�ǲ�����ϱ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderActionTrigger
{
public:
	///���췽��
	CCombOrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCombOrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCombOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCombOrder	Ҫ�����CombOrder
	virtual void beforeAdd(CWriteableCombOrder *pCombOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCombOrder	�Ѿ������CombOrder
	virtual void afterAdd(CCombOrder *pCombOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	///@param	pNewCombOrder	�µ�ֵ
	virtual void beforeUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	virtual void afterUpdate(CCombOrder *pCombOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCombOrder	Ҫɾ����CCombOrder
	virtual void beforeRemove(CCombOrder *pCombOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCombOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderCommitTrigger��ȷ����ϱ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderCommitTrigger
{
public:
	///���췽��
	CCombOrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCombOrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCombOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCombOrder	�Ѿ������CombOrder
	virtual void commitAdd(CCombOrder *pCombOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	///@param	poldCombOrder	ԭ����ֵ
	virtual void commitUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pOldCombOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCombOrder	�Ѿ�ɾ����CCombOrder
	virtual void commitRemove(CWriteableCombOrder *pCombOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCombOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderIterator��һ������ϱ�����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderIterator
{
public:
	///���췽��
	CCombOrderIterator(void)
	{
	}

	///���췽��
	CCombOrderIterator(CCombOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombOrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CombOrder
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCombOrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCombOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCombOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCombOrder * pCombOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCombOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableOTCOrder��һ���洢OTC�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOTCOrder
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! OTCOrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! OffsetFlag.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! OtherParticipantID.isValid())
			return 0;
		if (! OtherClientID.isValid())
			return 0;
		if (! OtherUserID.isValid())
			return 0;
		if (! OtherOffsetFlag.isValid())
			return 0;
		if (! OtherHedgeFlag.isValid())
			return 0;
		if (! OTCOrderLocalID.isValid())
			return 0;
		if (! OTCOrderStatus.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! OtherClearingPartID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableOTCOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///OTC�������
	COTCOrderSysIDType OTCOrderSysID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��������
	CDirectionType Direction;
	///��ƽ��־
	COffsetFlagType OffsetFlag;
	///Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	///�۸�
	CPriceType Price;
	///����
	CVolumeType Volume;
	///���ַ���Ա����
	CParticipantIDType OtherParticipantID;
	///���ַ��ͻ�����
	CClientIDType OtherClientID;
	///���ַ������û�����
	CUserIDType OtherUserID;
	///���ַ���ƽ��־
	COffsetFlagType OtherOffsetFlag;
	///���ַ��ױ���־
	CHedgeFlagType OtherHedgeFlag;
	///����OTC�������
	COrderLocalIDType OTCOrderLocalID;
	///OTC����״̬
	COTCOrderStatusType OTCOrderStatus;
	///����ʱ��
	CTimeType InsertTime;
	///����ʱ��
	CTimeType CancelTime;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	///���ַ������Ա���
	CParticipantIDType OtherClearingPartID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableOTCOrder COTCOrder;

/////////////////////////////////////////////////////////////////////////
///COTCOrderActionTrigger�ǲ���OTC����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderActionTrigger
{
public:
	///���췽��
	COTCOrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~COTCOrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(COTCOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pOTCOrder	Ҫ�����OTCOrder
	virtual void beforeAdd(CWriteableOTCOrder *pOTCOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pOTCOrder	�Ѿ������OTCOrder
	virtual void afterAdd(COTCOrder *pOTCOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	///@param	pNewOTCOrder	�µ�ֵ
	virtual void beforeUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	virtual void afterUpdate(COTCOrder *pOTCOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pOTCOrder	Ҫɾ����COTCOrder
	virtual void beforeRemove(COTCOrder *pOTCOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	COTCOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderCommitTrigger��ȷ��OTC����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderCommitTrigger
{
public:
	///���췽��
	COTCOrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~COTCOrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(COTCOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pOTCOrder	�Ѿ������OTCOrder
	virtual void commitAdd(COTCOrder *pOTCOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	///@param	poldOTCOrder	ԭ����ֵ
	virtual void commitUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pOldOTCOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pOTCOrder	�Ѿ�ɾ����COTCOrder
	virtual void commitRemove(CWriteableOTCOrder *pOTCOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	COTCOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderIterator��һ����OTC������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderIterator
{
public:
	///���췽��
	COTCOrderIterator(void)
	{
	}

	///���췽��
	COTCOrderIterator(COTCOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~COTCOrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��OTCOrder
	///@return	��һ����������COTCOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual COTCOrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	COTCOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pOTCOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableOTCOrder * pOTCOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	COTCOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableImplyOrder��һ���洢��ʽ�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableImplyOrder
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! AnchorOrderID.isValid())
			return 0;
		if (! ImplyOrderID.isValid())
			return 0;
		if (! CombInstrumentID.isValid())
			return 0;
		if (! AnchorLegID.isValid())
			return 0;
		if (! ImplyLegID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! Priority.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableImplyOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ê������
	COrderSysIDType AnchorOrderID;
	///����������
	COrderSysIDType ImplyOrderID;
	///��Ϻ�Լ����
	CInstrumentIDType CombInstrumentID;
	///ê�������ȱ��
	CLegIDType AnchorLegID;
	///�����������ȱ��
	CLegIDType ImplyLegID;
	///��������
	CDirectionType Direction;
	///����
	CVolumeType Volume;
	///����Ȩ
	CPriorityType Priority;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableImplyOrder CImplyOrder;

/////////////////////////////////////////////////////////////////////////
///CImplyOrderActionTrigger�ǲ�����ʽ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderActionTrigger
{
public:
	///���췽��
	CImplyOrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CImplyOrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CImplyOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pImplyOrder	Ҫ�����ImplyOrder
	virtual void beforeAdd(CWriteableImplyOrder *pImplyOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pImplyOrder	�Ѿ������ImplyOrder
	virtual void afterAdd(CImplyOrder *pImplyOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	///@param	pNewImplyOrder	�µ�ֵ
	virtual void beforeUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	virtual void afterUpdate(CImplyOrder *pImplyOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pImplyOrder	Ҫɾ����CImplyOrder
	virtual void beforeRemove(CImplyOrder *pImplyOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CImplyOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderCommitTrigger��ȷ����ʽ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderCommitTrigger
{
public:
	///���췽��
	CImplyOrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CImplyOrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CImplyOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pImplyOrder	�Ѿ������ImplyOrder
	virtual void commitAdd(CImplyOrder *pImplyOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	///@param	poldImplyOrder	ԭ����ֵ
	virtual void commitUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pOldImplyOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pImplyOrder	�Ѿ�ɾ����CImplyOrder
	virtual void commitRemove(CWriteableImplyOrder *pImplyOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CImplyOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderIterator��һ������ʽ������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderIterator
{
public:
	///���췽��
	CImplyOrderIterator(void)
	{
	}

	///���췽��
	CImplyOrderIterator(CImplyOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CImplyOrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ImplyOrder
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CImplyOrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CImplyOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pImplyOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableImplyOrder * pImplyOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CImplyOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableQuote��һ���洢���۵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableQuote
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! QuoteSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! QuoteLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! BidCombOffsetFlag.isValid())
			return 0;
		if (! BidCombHedgeFlag.isValid())
			return 0;
		if (! BidPrice.isValid())
			return 0;
		if (! AskCombOffsetFlag.isValid())
			return 0;
		if (! AskCombHedgeFlag.isValid())
			return 0;
		if (! AskPrice.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! TradeTime.isValid())
			return 0;
		if (! BidOrderSysID.isValid())
			return 0;
		if (! AskOrderSysID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableQuote *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///���۱��
	CQuoteSysIDType QuoteSysID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///����
	CVolumeType Volume;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///���ر��۱��
	COrderLocalIDType QuoteLocalID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///����Ͽ�ƽ��־
	CCombOffsetFlagType BidCombOffsetFlag;
	///������ױ���־
	CCombHedgeFlagType BidCombHedgeFlag;
	///�򷽼۸�
	CPriceType BidPrice;
	///������Ͽ�ƽ��־
	CCombOffsetFlagType AskCombOffsetFlag;
	///��������ױ���־
	CCombHedgeFlagType AskCombHedgeFlag;
	///�����۸�
	CPriceType AskPrice;
	///����ʱ��
	CTimeType InsertTime;
	///����ʱ��
	CTimeType CancelTime;
	///�ɽ�ʱ��
	CTimeType TradeTime;
	///�򷽱������
	COrderSysIDType BidOrderSysID;
	///�����������
	COrderSysIDType AskOrderSysID;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	unsigned int HashAskOrderSysIDHashKey;
	
	///����AskOrderSysIDHashKey��hashֵ
	void calHashAskOrderSysIDHashKey(void)
	{
		unsigned key=0;
		key=AskOrderSysID.hash(key);
		HashAskOrderSysIDHashKey=key;
	}
	
	///������Ҫ���������AskOrderSysIDHashKey��hashֵ
	void updateHashAskOrderSysIDHashKey(void)
	{
	}
	unsigned int HashBidOrderSysIDHashKey;
	
	///����BidOrderSysIDHashKey��hashֵ
	void calHashBidOrderSysIDHashKey(void)
	{
		unsigned key=0;
		key=BidOrderSysID.hash(key);
		HashBidOrderSysIDHashKey=key;
	}
	
	///������Ҫ���������BidOrderSysIDHashKey��hashֵ
	void updateHashBidOrderSysIDHashKey(void)
	{
	}
	
	///�������е�hashֵ
	void calAllHash(void)
	{
		calHashAskOrderSysIDHashKey();
		calHashBidOrderSysIDHashKey();
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
		updateHashAskOrderSysIDHashKey();
		updateHashBidOrderSysIDHashKey();
	}
	
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///����ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///����ָ���Ļ�Ա�ͻ�ָ��
	///@param	pPartClient	Ҫ���ӵ��Ķ���
	///@return	�����pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///��ȡָ���Ļ�Ա�ͻ���ָ��
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}

private:
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
	///ָ���Ļ�Ա�ͻ�
	const CWriteablePartClient *pPartClient;
};

typedef const CWriteableQuote CQuote;

/////////////////////////////////////////////////////////////////////////
///CQuoteActionTrigger�ǲ�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteActionTrigger
{
public:
	///���췽��
	CQuoteActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CQuoteActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CQuoteFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pQuote	Ҫ�����Quote
	virtual void beforeAdd(CWriteableQuote *pQuote)
	{
		return;
	}
	
	///����󴥷�
	///@param	pQuote	�Ѿ������Quote
	virtual void afterAdd(CQuote *pQuote)
	{
		return;
	}

	///����ǰ����	
	///@param	pQuote	��ˢ�µ�CQuote
	///@param	pNewQuote	�µ�ֵ
	virtual void beforeUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pQuote	��ˢ�µ�CQuote
	virtual void afterUpdate(CQuote *pQuote)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pQuote	Ҫɾ����CQuote
	virtual void beforeRemove(CQuote *pQuote)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CQuoteFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteCommitTrigger��ȷ�ϱ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteCommitTrigger
{
public:
	///���췽��
	CQuoteCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CQuoteCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CQuoteFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pQuote	�Ѿ������Quote
	virtual void commitAdd(CQuote *pQuote)
	{
		return;
	}

	///���º󴥷�
	///@param	pQuote	��ˢ�µ�CQuote
	///@param	poldQuote	ԭ����ֵ
	virtual void commitUpdate(CQuote *pQuote, CWriteableQuote *pOldQuote)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pQuote	�Ѿ�ɾ����CQuote
	virtual void commitRemove(CWriteableQuote *pQuote)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CQuoteFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteIterator��һ���Ա��۵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteIterator
{
public:
	///���췽��
	CQuoteIterator(void)
	{
	}

	///���췽��
	CQuoteIterator(CQuoteFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CQuoteIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Quote
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CQuote *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CQuoteFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pQuote ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableQuote * pQuote,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CQuoteFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableMBLMarketData��һ���洢�ּ۱�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableMBLMarketData
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! InstrumentID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableMBLMarketData *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��Լ����
	CInstrumentIDType InstrumentID;
	///��������
	CDirectionType Direction;
	///�۸�
	CPriceType Price;
	///����
	CVolumeType Volume;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableMBLMarketData CMBLMarketData;

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataActionTrigger�ǲ����ּ۱�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataActionTrigger
{
public:
	///���췽��
	CMBLMarketDataActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CMBLMarketDataActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMBLMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pMBLMarketData	Ҫ�����MBLMarketData
	virtual void beforeAdd(CWriteableMBLMarketData *pMBLMarketData)
	{
		return;
	}
	
	///����󴥷�
	///@param	pMBLMarketData	�Ѿ������MBLMarketData
	virtual void afterAdd(CMBLMarketData *pMBLMarketData)
	{
		return;
	}

	///����ǰ����	
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	///@param	pNewMBLMarketData	�µ�ֵ
	virtual void beforeUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	virtual void afterUpdate(CMBLMarketData *pMBLMarketData)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pMBLMarketData	Ҫɾ����CMBLMarketData
	virtual void beforeRemove(CMBLMarketData *pMBLMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMBLMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataCommitTrigger��ȷ�Ϸּ۱�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataCommitTrigger
{
public:
	///���췽��
	CMBLMarketDataCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CMBLMarketDataCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CMBLMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pMBLMarketData	�Ѿ������MBLMarketData
	virtual void commitAdd(CMBLMarketData *pMBLMarketData)
	{
		return;
	}

	///���º󴥷�
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	///@param	poldMBLMarketData	ԭ����ֵ
	virtual void commitUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pOldMBLMarketData)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pMBLMarketData	�Ѿ�ɾ����CMBLMarketData
	virtual void commitRemove(CWriteableMBLMarketData *pMBLMarketData)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CMBLMarketDataFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataIterator��һ���Էּ۱��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataIterator
{
public:
	///���췽��
	CMBLMarketDataIterator(void)
	{
	}

	///���췽��
	CMBLMarketDataIterator(CMBLMarketDataFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMBLMarketDataIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��MBLMarketData
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CMBLMarketData *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CMBLMarketDataFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pMBLMarketData ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableMBLMarketData * pMBLMarketData,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CMBLMarketDataFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableTrade��һ���洢�ɽ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableTrade
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! TradeID.isValid())
			return 0;
		if (! Direction.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! AccountID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OffsetFlag.isValid())
			return 0;
		if (! HedgeFlag.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! TradeTime.isValid())
			return 0;
		if (! TradeType.isValid())
			return 0;
		if (! PriceSource.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! TID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableTrade *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///�ɽ����
	CTradeIDType TradeID;
	///��������
	CDirectionType Direction;
	///�������
	COrderSysIDType OrderSysID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///���׽�ɫ
	CTradingRoleType TradingRole;
	///�ʽ��ʺ�
	CAccountIDType AccountID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��ƽ��־
	COffsetFlagType OffsetFlag;
	///Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	///�۸�
	CPriceType Price;
	///����
	CVolumeType Volume;
	///�ɽ�ʱ��
	CTimeType TradeTime;
	///�ɽ�����
	CTradeTypeType TradeType;
	///�ɽ�����Դ
	CPriceSourceType PriceSource;
	///�����û�����
	CUserIDType UserID;
	///���ر������
	COrderLocalIDType OrderLocalID;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///���к�
	CSequenceNoType TID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}
	///����ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///����ָ���Ļ�Ա�ͻ�ָ��
	///@param	pPartClient	Ҫ���ӵ��Ķ���
	///@return	�����pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///��ȡָ���Ļ�Ա�ͻ���ָ��
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}

private:
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
	///ָ���Ļ�Ա�ͻ�
	const CWriteablePartClient *pPartClient;
};

typedef const CWriteableTrade CTrade;

/////////////////////////////////////////////////////////////////////////
///CTradeActionTrigger�ǲ����ɽ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeActionTrigger
{
public:
	///���췽��
	CTradeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CTradeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pTrade	Ҫ�����Trade
	virtual void beforeAdd(CWriteableTrade *pTrade)
	{
		return;
	}
	
	///����󴥷�
	///@param	pTrade	�Ѿ������Trade
	virtual void afterAdd(CTrade *pTrade)
	{
		return;
	}

	///����ǰ����	
	///@param	pTrade	��ˢ�µ�CTrade
	///@param	pNewTrade	�µ�ֵ
	virtual void beforeUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pTrade	��ˢ�µ�CTrade
	virtual void afterUpdate(CTrade *pTrade)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pTrade	Ҫɾ����CTrade
	virtual void beforeRemove(CTrade *pTrade)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradeCommitTrigger��ȷ�ϳɽ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeCommitTrigger
{
public:
	///���췽��
	CTradeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CTradeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pTrade	�Ѿ������Trade
	virtual void commitAdd(CTrade *pTrade)
	{
		return;
	}

	///���º󴥷�
	///@param	pTrade	��ˢ�µ�CTrade
	///@param	poldTrade	ԭ����ֵ
	virtual void commitUpdate(CTrade *pTrade, CWriteableTrade *pOldTrade)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pTrade	�Ѿ�ɾ����CTrade
	virtual void commitRemove(CWriteableTrade *pTrade)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CTradeIterator��һ���Գɽ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeIterator
{
public:
	///���췽��
	CTradeIterator(void)
	{
	}

	///���췽��
	CTradeIterator(CTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��Trade
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CTrade *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CTradeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableTrade * pTrade,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CTradeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableFusePhase��һ���洢�۶Ͻ׶εĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableFusePhase
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! FuseStatus.isValid())
			return 0;
		if (! EnterTime.isValid())
			return 0;
		if (! ExpectLeaveTime.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableFusePhase *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�۶�״̬
	CFuseStatusType FuseStatus;
	///���뱾״̬ʱ��
	CTimeType EnterTime;
	///�ƻ��뿪ʱ��
	CTimeType ExpectLeaveTime;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableFusePhase CFusePhase;

/////////////////////////////////////////////////////////////////////////
///CFusePhaseActionTrigger�ǲ����۶Ͻ׶�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseActionTrigger
{
public:
	///���췽��
	CFusePhaseActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CFusePhaseActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CFusePhaseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pFusePhase	Ҫ�����FusePhase
	virtual void beforeAdd(CWriteableFusePhase *pFusePhase)
	{
		return;
	}
	
	///����󴥷�
	///@param	pFusePhase	�Ѿ������FusePhase
	virtual void afterAdd(CFusePhase *pFusePhase)
	{
		return;
	}

	///����ǰ����	
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	///@param	pNewFusePhase	�µ�ֵ
	virtual void beforeUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	virtual void afterUpdate(CFusePhase *pFusePhase)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pFusePhase	Ҫɾ����CFusePhase
	virtual void beforeRemove(CFusePhase *pFusePhase)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CFusePhaseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseCommitTrigger��ȷ���۶Ͻ׶�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseCommitTrigger
{
public:
	///���췽��
	CFusePhaseCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CFusePhaseCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CFusePhaseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pFusePhase	�Ѿ������FusePhase
	virtual void commitAdd(CFusePhase *pFusePhase)
	{
		return;
	}

	///���º󴥷�
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	///@param	poldFusePhase	ԭ����ֵ
	virtual void commitUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pOldFusePhase)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pFusePhase	�Ѿ�ɾ����CFusePhase
	virtual void commitRemove(CWriteableFusePhase *pFusePhase)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CFusePhaseFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseIterator��һ�����۶Ͻ׶ε�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseIterator
{
public:
	///���췽��
	CFusePhaseIterator(void)
	{
	}

	///���췽��
	CFusePhaseIterator(CFusePhaseFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CFusePhaseIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��FusePhase
	///@return	��һ����������CFusePhase������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CFusePhase *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CFusePhaseFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pFusePhase ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableFusePhase * pFusePhase,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CFusePhaseFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableExecOrder��һ���洢ִ������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExecOrder
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ExecOrderLocalID.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ExecOrderSysID.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! CancelTime.isValid())
			return 0;
		if (! ExecResult.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableExecOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��Լ���
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///����ִ��������
	COrderLocalIDType ExecOrderLocalID;
	///����
	CVolumeType Volume;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///ִ��������
	CExecOrderSysIDType ExecOrderSysID;
	///��������
	CDateType InsertDate;
	///����ʱ��
	CTimeType InsertTime;
	///����ʱ��
	CTimeType CancelTime;
	///ִ�н��
	CExecResultType ExecResult;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///����ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteablePartClient *linkPartClient(CPartClientFactory *pFactory) const;

	///����ָ���Ļ�Ա�ͻ�ָ��
	///@param	pPartClient	Ҫ���ӵ��Ķ���
	///@return	�����pPartClient
	const CWriteablePartClient *linkPartClient(const CWriteablePartClient *pPartClient) const
	{
		void *target=(void *)(&(this->pPartClient));
		*((const CWriteablePartClient **)target)=pPartClient;
		return pPartClient;
	}
	
	///��ȡָ���Ļ�Ա�ͻ���ָ��
	///@return	�ҵ���ָ���Ļ�Ա�ͻ���ָ�룬����Ҳ����򷵻�NULL
	const CWriteablePartClient *getPartClient(void) const
	{
		return pPartClient;
	}
	///�����Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableInstrument *linkInstrument(CInstrumentFactory *pFactory) const;

	///�����Ӧ�ĺ�Լָ��
	///@param	pInstrument	Ҫ���ӵ��Ķ���
	///@return	�����pInstrument
	const CWriteableInstrument *linkInstrument(const CWriteableInstrument *pInstrument) const
	{
		void *target=(void *)(&(this->pInstrument));
		*((const CWriteableInstrument **)target)=pInstrument;
		return pInstrument;
	}
	
	///��ȡ��Ӧ�ĺ�Լ��ָ��
	///@return	�ҵ��Ķ�Ӧ�ĺ�Լ��ָ�룬����Ҳ����򷵻�NULL
	const CWriteableInstrument *getInstrument(void) const
	{
		return pInstrument;
	}

private:
	///ָ���Ļ�Ա�ͻ�
	const CWriteablePartClient *pPartClient;
	///��Ӧ�ĺ�Լ
	const CWriteableInstrument *pInstrument;
};

typedef const CWriteableExecOrder CExecOrder;

/////////////////////////////////////////////////////////////////////////
///CExecOrderActionTrigger�ǲ���ִ������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderActionTrigger
{
public:
	///���췽��
	CExecOrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CExecOrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CExecOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pExecOrder	Ҫ�����ExecOrder
	virtual void beforeAdd(CWriteableExecOrder *pExecOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pExecOrder	�Ѿ������ExecOrder
	virtual void afterAdd(CExecOrder *pExecOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	///@param	pNewExecOrder	�µ�ֵ
	virtual void beforeUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	virtual void afterUpdate(CExecOrder *pExecOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pExecOrder	Ҫɾ����CExecOrder
	virtual void beforeRemove(CExecOrder *pExecOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CExecOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderCommitTrigger��ȷ��ִ������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderCommitTrigger
{
public:
	///���췽��
	CExecOrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CExecOrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CExecOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pExecOrder	�Ѿ������ExecOrder
	virtual void commitAdd(CExecOrder *pExecOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	///@param	poldExecOrder	ԭ����ֵ
	virtual void commitUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pOldExecOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pExecOrder	�Ѿ�ɾ����CExecOrder
	virtual void commitRemove(CWriteableExecOrder *pExecOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CExecOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderIterator��һ����ִ�������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderIterator
{
public:
	///���췽��
	CExecOrderIterator(void)
	{
	}

	///���췽��
	CExecOrderIterator(CExecOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExecOrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��ExecOrder
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CExecOrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CExecOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pExecOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableExecOrder * pExecOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CExecOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableUniPressure��һ���洢����������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUniPressure
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! UpperPressureStartTime.isValid())
			return 0;
		if (! LowerPressureStartTime.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableUniPressure *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��ѹ����ʼʱ��
	CTimeType UpperPressureStartTime;
	///��ѹ����ʼʱ��
	CTimeType LowerPressureStartTime;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUniPressure CUniPressure;

/////////////////////////////////////////////////////////////////////////
///CUniPressureActionTrigger�ǲ������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureActionTrigger
{
public:
	///���췽��
	CUniPressureActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CUniPressureActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUniPressureFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pUniPressure	Ҫ�����UniPressure
	virtual void beforeAdd(CWriteableUniPressure *pUniPressure)
	{
		return;
	}
	
	///����󴥷�
	///@param	pUniPressure	�Ѿ������UniPressure
	virtual void afterAdd(CUniPressure *pUniPressure)
	{
		return;
	}

	///����ǰ����	
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	///@param	pNewUniPressure	�µ�ֵ
	virtual void beforeUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	virtual void afterUpdate(CUniPressure *pUniPressure)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pUniPressure	Ҫɾ����CUniPressure
	virtual void beforeRemove(CUniPressure *pUniPressure)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUniPressureFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureCommitTrigger��ȷ�ϵ��������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureCommitTrigger
{
public:
	///���췽��
	CUniPressureCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CUniPressureCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CUniPressureFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pUniPressure	�Ѿ������UniPressure
	virtual void commitAdd(CUniPressure *pUniPressure)
	{
		return;
	}

	///���º󴥷�
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	///@param	poldUniPressure	ԭ����ֵ
	virtual void commitUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pOldUniPressure)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pUniPressure	�Ѿ�ɾ����CUniPressure
	virtual void commitRemove(CWriteableUniPressure *pUniPressure)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CUniPressureFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureIterator��һ���Ե����������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureIterator
{
public:
	///���췽��
	CUniPressureIterator(void)
	{
	}

	///���췽��
	CUniPressureIterator(CUniPressureFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUniPressureIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��UniPressure
	///@return	��һ����������CUniPressure������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CUniPressure *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CUniPressureFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pUniPressure ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableUniPressure * pUniPressure,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CUniPressureFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableBasePriceLimit��һ���洢�ǵ�ͣ�����õĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableBasePriceLimit
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! UpperLimitPrice.isValid())
			return 0;
		if (! LowerLimitPrice.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableBasePriceLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��ͣ���
	CPriceType UpperLimitPrice;
	///��ͣ���
	CPriceType LowerLimitPrice;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableBasePriceLimit CBasePriceLimit;

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitActionTrigger�ǲ����ǵ�ͣ������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitActionTrigger
{
public:
	///���췽��
	CBasePriceLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CBasePriceLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CBasePriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pBasePriceLimit	Ҫ�����BasePriceLimit
	virtual void beforeAdd(CWriteableBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pBasePriceLimit	�Ѿ������BasePriceLimit
	virtual void afterAdd(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	///@param	pNewBasePriceLimit	�µ�ֵ
	virtual void beforeUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	virtual void afterUpdate(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pBasePriceLimit	Ҫɾ����CBasePriceLimit
	virtual void beforeRemove(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CBasePriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitCommitTrigger��ȷ���ǵ�ͣ������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitCommitTrigger
{
public:
	///���췽��
	CBasePriceLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CBasePriceLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CBasePriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pBasePriceLimit	�Ѿ������BasePriceLimit
	virtual void commitAdd(CBasePriceLimit *pBasePriceLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	///@param	poldBasePriceLimit	ԭ����ֵ
	virtual void commitUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pOldBasePriceLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pBasePriceLimit	�Ѿ�ɾ����CBasePriceLimit
	virtual void commitRemove(CWriteableBasePriceLimit *pBasePriceLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CBasePriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitIterator��һ�����ǵ�ͣ�����õ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitIterator
{
public:
	///���췽��
	CBasePriceLimitIterator(void)
	{
	}

	///���췽��
	CBasePriceLimitIterator(CBasePriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBasePriceLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��BasePriceLimit
	///@return	��һ����������CBasePriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CBasePriceLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CBasePriceLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pBasePriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableBasePriceLimit * pBasePriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CBasePriceLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableCreditLimit��һ���洢�����޶�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCreditLimit
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! PreBalance.isValid())
			return 0;
		if (! CurrMargin.isValid())
			return 0;
		if (! CloseProfit.isValid())
			return 0;
		if (! Premium.isValid())
			return 0;
		if (! Deposit.isValid())
			return 0;
		if (! Withdraw.isValid())
			return 0;
		if (! Balance.isValid())
			return 0;
		if (! Available.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! FrozenMargin.isValid())
			return 0;
		if (! FrozenPremium.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCreditLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///�ϴν���׼����
	CMoneyType PreBalance;
	///��ǰ��֤���ܶ�
	CMoneyType CurrMargin;
	///ƽ��ӯ��
	CMoneyType CloseProfit;
	///��ȨȨ������֧
	CMoneyType Premium;
	///�����
	CMoneyType Deposit;
	///������
	CMoneyType Withdraw;
	///�ڻ�����׼����
	CMoneyType Balance;
	///�����ʽ�
	CMoneyType Available;
	///���׻�Ա���
	CParticipantIDType ParticipantID;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	///����ı�֤��
	CMoneyType FrozenMargin;
	///�����Ȩ����
	CMoneyType FrozenPremium;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCreditLimit CCreditLimit;

/////////////////////////////////////////////////////////////////////////
///CCreditLimitActionTrigger�ǲ��������޶�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitActionTrigger
{
public:
	///���췽��
	CCreditLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCreditLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCreditLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCreditLimit	Ҫ�����CreditLimit
	virtual void beforeAdd(CWriteableCreditLimit *pCreditLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCreditLimit	�Ѿ������CreditLimit
	virtual void afterAdd(CCreditLimit *pCreditLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	///@param	pNewCreditLimit	�µ�ֵ
	virtual void beforeUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	virtual void afterUpdate(CCreditLimit *pCreditLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCreditLimit	Ҫɾ����CCreditLimit
	virtual void beforeRemove(CCreditLimit *pCreditLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCreditLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitCommitTrigger��ȷ�������޶�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitCommitTrigger
{
public:
	///���췽��
	CCreditLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCreditLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCreditLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCreditLimit	�Ѿ������CreditLimit
	virtual void commitAdd(CCreditLimit *pCreditLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	///@param	poldCreditLimit	ԭ����ֵ
	virtual void commitUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pOldCreditLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCreditLimit	�Ѿ�ɾ����CCreditLimit
	virtual void commitRemove(CWriteableCreditLimit *pCreditLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCreditLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitIterator��һ���������޶��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitIterator
{
public:
	///���췽��
	CCreditLimitIterator(void)
	{
	}

	///���췽��
	CCreditLimitIterator(CCreditLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCreditLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CreditLimit
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCreditLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCreditLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCreditLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCreditLimit * pCreditLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCreditLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableHedgeDetail��һ���洢��ֵ�����ϸ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableHedgeDetail
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeQuotaSN.isValid())
			return 0;
		if (! OperatorID.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! TradingVolume.isValid())
			return 0;
		if (! HedgeQuota.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableHedgeDetail *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��ˮ��
	CSerialNoType HedgeQuotaSN;
	///�û�����
	COperatorIDType OperatorID;
	///ʱ��
	CTimeType Time;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ֲֶ�շ���
	CPosiDirectionType PosiDirection;
	///������
	CVolumeType TradingVolume;
	///��ֵ���
	CVolumeType HedgeQuota;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableHedgeDetail CHedgeDetail;

/////////////////////////////////////////////////////////////////////////
///CWriteableOrderAction��һ���洢���������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableOrderAction
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! OrderSysID.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! LimitPrice.isValid())
			return 0;
		if (! VolumeChange.isValid())
			return 0;
		if (! ActionLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ActionSource.isValid())
			return 0;
		if (! Tradable.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableOrderAction *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�������
	COrderSysIDType OrderSysID;
	///���ر������
	COrderLocalIDType OrderLocalID;
	///����������־
	CActionFlagType ActionFlag;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///�۸�
	CPriceType LimitPrice;
	///�����仯
	CVolumeType VolumeChange;
	///�������ر��
	COrderLocalIDType ActionLocalID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///������Դ
	CActionSourceType ActionSource;
	///�Ƿ���Բμӽ���
	CBoolType Tradable;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�ı�����ָ��
	///@param	pFactory	�����Ӧ�ı�����ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ı�����ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableOrder *linkOrder(COrderFactory *pFactory) const;

	///�����Ӧ�ı���ָ��
	///@param	pOrder	Ҫ���ӵ��Ķ���
	///@return	�����pOrder
	const CWriteableOrder *linkOrder(const CWriteableOrder *pOrder) const
	{
		void *target=(void *)(&(this->pOrder));
		*((const CWriteableOrder **)target)=pOrder;
		return pOrder;
	}
	
	///��ȡ��Ӧ�ı�����ָ��
	///@return	�ҵ��Ķ�Ӧ�ı�����ָ�룬����Ҳ����򷵻�NULL
	const CWriteableOrder *getOrder(void) const
	{
		return pOrder;
	}

private:
	///��Ӧ�ı���
	const CWriteableOrder *pOrder;
};

typedef const CWriteableOrderAction COrderAction;

/////////////////////////////////////////////////////////////////////////
///CWriteableQuoteAction��һ���洢���۲����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableQuoteAction
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! QuoteSysID.isValid())
			return 0;
		if (! QuoteLocalID.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ActionLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ActionSource.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableQuoteAction *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���۱��
	CQuoteSysIDType QuoteSysID;
	///���ر��۱��
	COrderLocalIDType QuoteLocalID;
	///����������־
	CActionFlagType ActionFlag;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///�������ر��
	COrderLocalIDType ActionLocalID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///������Դ
	CActionSourceType ActionSource;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ�ı��۵�ָ��
	///@param	pFactory	�����Ӧ�ı��۵�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ�ı��۵�ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableQuote *linkQuote(CQuoteFactory *pFactory) const;

	///�����Ӧ�ı���ָ��
	///@param	pQuote	Ҫ���ӵ��Ķ���
	///@return	�����pQuote
	const CWriteableQuote *linkQuote(const CWriteableQuote *pQuote) const
	{
		void *target=(void *)(&(this->pQuote));
		*((const CWriteableQuote **)target)=pQuote;
		return pQuote;
	}
	
	///��ȡ��Ӧ�ı��۵�ָ��
	///@return	�ҵ��Ķ�Ӧ�ı��۵�ָ�룬����Ҳ����򷵻�NULL
	const CWriteableQuote *getQuote(void) const
	{
		return pQuote;
	}

private:
	///��Ӧ�ı���
	const CWriteableQuote *pQuote;
};

typedef const CWriteableQuoteAction CQuoteAction;

/////////////////////////////////////////////////////////////////////////
///CWriteableExecOrderAction��һ���洢ִ����������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableExecOrderAction
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! ExecOrderSysID.isValid())
			return 0;
		if (! ExecOrderLocalID.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ActionLocalID.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! ActionSource.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableExecOrderAction *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ִ��������
	CExecOrderSysIDType ExecOrderSysID;
	///����ִ��������
	COrderLocalIDType ExecOrderLocalID;
	///����������־
	CActionFlagType ActionFlag;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	///�����û�����
	CUserIDType UserID;
	///�������ر��
	COrderLocalIDType ActionLocalID;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///������Դ
	CActionSourceType ActionSource;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	
	///�����Ӧ��ִ�������ָ��
	///@param	pFactory	�����Ӧ��ִ�������ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@return	�ҵ��Ķ�Ӧ��ִ�������ָ�룬����Ҳ����򷵻�NULL
	inline const CWriteableExecOrder *linkExecOrder(CExecOrderFactory *pFactory) const;

	///�����Ӧ��ִ������ָ��
	///@param	pExecOrder	Ҫ���ӵ��Ķ���
	///@return	�����pExecOrder
	const CWriteableExecOrder *linkExecOrder(const CWriteableExecOrder *pExecOrder) const
	{
		void *target=(void *)(&(this->pExecOrder));
		*((const CWriteableExecOrder **)target)=pExecOrder;
		return pExecOrder;
	}
	
	///��ȡ��Ӧ��ִ�������ָ��
	///@return	�ҵ��Ķ�Ӧ��ִ�������ָ�룬����Ҳ����򷵻�NULL
	const CWriteableExecOrder *getExecOrder(void) const
	{
		return pExecOrder;
	}

private:
	///��Ӧ��ִ������
	const CWriteableExecOrder *pExecOrder;
};

typedef const CWriteableExecOrderAction CExecOrderAction;

/////////////////////////////////////////////////////////////////////////
///CWriteableAccountDeposit��һ���洢��Ա�ʽ��ʻ����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAccountDeposit
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! Account.isValid())
			return 0;
		if (! Deposit.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableAccountDeposit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///�ʽ��˺�
	CAccountIDType Account;
	///�����
	CMoneyType Deposit;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableAccountDeposit CAccountDeposit;

/////////////////////////////////////////////////////////////////////////
///CWriteableUpdateAllInstrumentStatus��һ���洢�������к�Լ״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableUpdateAllInstrumentStatus
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentStatus.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableUpdateAllInstrumentStatus *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ״̬
	CInstrumentStatusType InstrumentStatus;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableUpdateAllInstrumentStatus CUpdateAllInstrumentStatus;

/////////////////////////////////////////////////////////////////////////
///CWriteableAdminOrder��һ���洢�������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableAdminOrder
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! InstrumentID.isValid())
			return 0;
		if (! AdminOrderCommand.isValid())
			return 0;
		if (! ClearingPartID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! Amount.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableAdminOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��Լ����
	CInstrumentIDType InstrumentID;
	///����������
	CAdminOrderCommandFlagType AdminOrderCommand;
	///�����Ա���
	CParticipantIDType ClearingPartID;
	///���׻�Ա���
	CParticipantIDType ParticipantID;
	///���
	CMoneyType Amount;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableAdminOrder CAdminOrder;

/////////////////////////////////////////////////////////////////////////
///CWriteableCommPhase��һ���洢ͨѶ�׶εĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCommPhase
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! CommPhaseNo.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCommPhase *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///ͨѶʱ�κ�
	CCommPhaseNoType CommPhaseNo;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCommPhase CCommPhase;

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrHedge��һ���洢��ǰ��ֵ��ȵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrHedge
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! TradingDay.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! SettlementID.isValid())
			return 0;
		if (! HedgeQuotaSN.isValid())
			return 0;
		if (! OperatorID.isValid())
			return 0;
		if (! Time.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! PosiDirection.isValid())
			return 0;
		if (! CurrVolume.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrHedge *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///������
	CDateType TradingDay;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������
	CSettlementIDType SettlementID;
	///��ˮ��
	CSerialNoType HedgeQuotaSN;
	///�û�����
	COperatorIDType OperatorID;
	///ʱ��
	CTimeType Time;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ֲֶ�շ���
	CPosiDirectionType PosiDirection;
	///��ǰ��ֵ���
	CVolumeType CurrVolume;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrHedge CCurrHedge;

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrInstrumentOption��һ���洢�����ڻ���Լ��Ȩ���ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableCurrInstrumentOption
{
public:
	///��CSV�ļ���д��������
	///@param	output	Ҫд�����ļ�
	static void writeCSVHead(FILE *output);

	void output(CLogger *pLogger,int indent=0);
	
	///��ʼ�������������е��ֶ����
	void init(void);
	
	///���ļ�����
	///@param	input	������ļ�
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);
	
	///���ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;
	
	///��CSV�ļ�����
	///@param	input	������ļ�
	///@param	pNames	�����ֶε����ƣ����ΪNULL����˳�����
	///@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int readCSV(FILE *input,vector<char *> *pNames=NULL);
	
	///��CSV�ļ�д��
	///@param	output д�����ļ�
	///@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int writeCSV(FILE *output) const;

	///������ݵĺϷ���
	///@return	1��ʾ�Ϸ���0��ʾ���Ϸ�
	int isValid(void) const
	{
		if (! SettlementGroupID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! OptPostLimitRatio.isValid())
			return 0;
		if (! UniPostLimitRatio.isValid())
			return 0;
		if (! MiniMargin.isValid())
			return 0;
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableCurrInstrumentOption *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���������
	CSettlementGroupIDType SettlementGroupID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///ͬ�����Ȩ�ĺϲ��ֱֲ���
	CRatioType OptPostLimitRatio;
	///�ڻ���ͬ�����Ȩ�ĺϲ��ֱֲ���
	CRatioType UniPostLimitRatio;
	///��λ���֣���Ȩ��Լ��С��֤��
	CMoneyType MiniMargin;
	
	///�������е�hashֵ
	void calAllHash(void)
	{
	}
	
	///�������е�hashֵ
	void updateAllHash(void)
	{
	}
	

private:
};

typedef const CWriteableCurrInstrumentOption CCurrInstrumentOption;

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionActionTrigger�ǲ��������ڻ���Լ��Ȩ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionActionTrigger
{
public:
	///���췽��
	CCurrInstrumentOptionActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrInstrumentOptionActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrInstrumentOptionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pCurrInstrumentOption	Ҫ�����CurrInstrumentOption
	virtual void beforeAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
	
	///����󴥷�
	///@param	pCurrInstrumentOption	�Ѿ������CurrInstrumentOption
	virtual void afterAdd(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}

	///����ǰ����	
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	�µ�ֵ
	virtual void beforeUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	virtual void afterUpdate(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pCurrInstrumentOption	Ҫɾ����CCurrInstrumentOption
	virtual void beforeRemove(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrInstrumentOptionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionCommitTrigger��ȷ�ϵ����ڻ���Լ��Ȩ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionCommitTrigger
{
public:
	///���췽��
	CCurrInstrumentOptionCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CCurrInstrumentOptionCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CCurrInstrumentOptionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pCurrInstrumentOption	�Ѿ������CurrInstrumentOption
	virtual void commitAdd(CCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}

	///���º󴥷�
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	///@param	poldCurrInstrumentOption	ԭ����ֵ
	virtual void commitUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pOldCurrInstrumentOption)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pCurrInstrumentOption	�Ѿ�ɾ����CCurrInstrumentOption
	virtual void commitRemove(CWriteableCurrInstrumentOption *pCurrInstrumentOption)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CCurrInstrumentOptionFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionIterator��һ���Ե����ڻ���Լ��Ȩ���Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionIterator
{
public:
	///���췽��
	CCurrInstrumentOptionIterator(void)
	{
	}

	///���췽��
	CCurrInstrumentOptionIterator(CCurrInstrumentOptionFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrInstrumentOptionIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��CurrInstrumentOption
	///@return	��һ����������CCurrInstrumentOption������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CCurrInstrumentOption *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CCurrInstrumentOptionFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pCurrInstrumentOption ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableCurrInstrumentOption * pCurrInstrumentOption,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CCurrInstrumentOptionFactory *m_Factory;	
};


#include "databaseFactories.h"

const CWriteableClearingTradingPart *CWriteableParticipant::linkClearingTradingPart(CClearingTradingPartFactory *pFactory) const
{
	void *target=(void *)(&pClearingTradingPart);
	*((const CWriteableClearingTradingPart **)target)=pFactory->findByParticipant(ParticipantID);
	return pClearingTradingPart;
}

const CWriteableParticipant *CWriteablePartClient::linkParticipant(CParticipantFactory *pFactory) const
{
	void *target=(void *)(&pParticipant);
	*((const CWriteableParticipant **)target)=pFactory->findByParticipantID(ParticipantID);
	return pParticipant;
}

const CWriteableClient *CWriteablePartClient::linkClient(CClientFactory *pFactory) const
{
	void *target=(void *)(&pClient);
	*((const CWriteableClient **)target)=pFactory->findByClientID(ClientID);
	return pClient;
}

const CWriteableTradingAccount *CWriteableAccount::linkTradingAccount(CTradingAccountFactory *pFactory) const
{
	void *target=(void *)(&pTradingAccount);
	*((const CWriteableTradingAccount **)target)=pFactory->findByAccountID(AccountID);
	return pTradingAccount;
}

const CWriteableUser *CWriteableUserSession::linkUser(CUserFactory *pFactory) const
{
	void *target=(void *)(&pUser);
	*((const CWriteableUser **)target)=pFactory->findByUserID(UserID);
	return pUser;
}

const CWriteableDepthMarketData *CWriteableMarketDataModify::linkDepthMarketData(CDepthMarketDataFactory *pFactory) const
{
	void *target=(void *)(&pDepthMarketData);
	*((const CWriteableDepthMarketData **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pDepthMarketData;
}

const CWriteableInstrument *CWriteableDepthMarketData::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableInstrument *CWriteableInstrument::linkBaseInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pBaseInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(UnderlyingInstrID);
	return pBaseInstrument;
}

const CWriteableCurrInstrumentProperty *CWriteableInstrument::linkInstrumentProperty(CCurrInstrumentPropertyFactory *pFactory) const
{
	void *target=(void *)(&pInstrumentProperty);
	*((const CWriteableCurrInstrumentProperty **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrumentProperty;
}

const CWriteableInstrumentStatus *CWriteableInstrument::linkInstrumentStatus(CInstrumentStatusFactory *pFactory) const
{
	void *target=(void *)(&pInstrumentStatus);
	*((const CWriteableInstrumentStatus **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrumentStatus;
}

const CWriteableMarketData *CWriteableInstrument::linkMarketData(CMarketDataFactory *pFactory) const
{
	void *target=(void *)(&pMarketData);
	*((const CWriteableMarketData **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pMarketData;
}

const CWriteableCurrHedgeRule *CWriteableInstrument::linkCurrHedgeRule(CCurrHedgeRuleFactory *pFactory) const
{
	void *target=(void *)(&pCurrHedgeRule);
	*((const CWriteableCurrHedgeRule **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pCurrHedgeRule;
}

const CWriteableCurrFuse *CWriteableInstrument::linkCurrFuse(CCurrFuseFactory *pFactory) const
{
	void *target=(void *)(&pCurrFuse);
	*((const CWriteableCurrFuse **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pCurrFuse;
}

const CWriteableFusePhase *CWriteableInstrument::linkFusePhase(CFusePhaseFactory *pFactory) const
{
	void *target=(void *)(&pFusePhase);
	*((const CWriteableFusePhase **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pFusePhase;
}

const CWriteableBasePriceLimit *CWriteableInstrument::linkBasePriceLimit(CBasePriceLimitFactory *pFactory) const
{
	void *target=(void *)(&pBasePriceLimit);
	*((const CWriteableBasePriceLimit **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pBasePriceLimit;
}

const CWriteableUniPressure *CWriteableInstrument::linkUniPressure(CUniPressureFactory *pFactory) const
{
	void *target=(void *)(&pUniPressure);
	*((const CWriteableUniPressure **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pUniPressure;
}

const CWriteableSGDataSyncStatus *CWriteableInstrument::linkSGDataSyncStatus(CSGDataSyncStatusFactory *pFactory) const
{
	void *target=(void *)(&pSGDataSyncStatus);
	*((const CWriteableSGDataSyncStatus **)target)=pFactory->findBySettlementGroupID(SettlementGroupID);
	return pSGDataSyncStatus;
}

const CWriteableInstrument *CWriteableCombinationLeg::linkCombinationInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pCombinationInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(CombInstrumentID);
	if (pCombinationInstrument==NULL)
	{
		RAISE_RUNTIME_ERROR("can not link CombinationInstrument in CombinationLeg");
	}
	return pCombinationInstrument;
}

const CWriteableInstrument *CWriteableCombinationLeg::linkLegInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pLegInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(LegInstrumentID);
	if (pLegInstrument==NULL)
	{
		RAISE_RUNTIME_ERROR("can not link LegInstrument in CombinationLeg");
	}
	return pLegInstrument;
}

const CWriteableTradingAccount *CWriteablePartRoleAccount::linkTradingAccount(CTradingAccountFactory *pFactory) const
{
	void *target=(void *)(&pTradingAccount);
	*((const CWriteableTradingAccount **)target)=pFactory->findByAccountID(AccountID);
	return pTradingAccount;
}

const CWriteableBaseReserveAccount *CWriteableTradingAccount::linkBaseReserveAccount(CBaseReserveAccountFactory *pFactory) const
{
	void *target=(void *)(&pBaseReserveAccount);
	*((const CWriteableBaseReserveAccount **)target)=pFactory->findByAccountID(AccountID);
	return pBaseReserveAccount;
}

const CWriteableCreditLimit *CWriteableClientPosition::linkCreditLimit(CCreditLimitFactory *pFactory) const
{
	void *target=(void *)(&pCreditLimit);
	*((const CWriteableCreditLimit **)target)=pFactory->findByParticipantID(SettlementGroupID,ParticipantID);
	return pCreditLimit;
}

const CWriteablePartRoleAccount *CWriteableClientPosition::linkPartRoleAccount(CPartRoleAccountFactory *pFactory) const
{
	void *target=(void *)(&pPartRoleAccount);
	*((const CWriteablePartRoleAccount **)target)=pFactory->findByPartRoleAndSG("",ER_Broker,"");
	return pPartRoleAccount;
}

const CWriteableInstrument *CWriteableInstrumentStatus::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableCurrPriceBanding *CWriteableInstrumentStatus::linkCurrPriceBanding(CCurrPriceBandingFactory *pFactory) const
{
	void *target=(void *)(&pCurrPriceBanding);
	*((const CWriteableCurrPriceBanding **)target)=pFactory->findByInstrumentAndSegment(InstrumentID,TradingSegmentSN);
	return pCurrPriceBanding;
}

const CWriteableMdPubStatus *CWriteableInstrumentStatus::linkMdPubStatus(CMdPubStatusFactory *pFactory) const
{
	void *target=(void *)(&pMdPubStatus);
	*((const CWriteableMdPubStatus **)target)=pFactory->findByProductIDInstrumentStatus(getInstrument()->ProductID,InstrumentStatus);
	return pMdPubStatus;
}

const CWriteableInstrument *CWriteableOrder::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableOrder::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableClientPosition *CWriteableOrder::linkClientPosition(CClientPositionFactory *pFactory) const
{
	void *target=(void *)(&pClientPosition);
	*((const CWriteableClientPosition **)target)=pFactory->findByPartClientAndInstrument(ParticipantID,ClientID,InstrumentID,PD_Net,HF_Speculation);
	return pClientPosition;
}

const CWriteablePartClient *CWriteableCombOrder::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument1(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument1);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID1);
	return pInstrument1;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument2(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument2);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID2);
	return pInstrument2;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument3(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument3);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID3);
	return pInstrument3;
}

const CWriteableInstrument *CWriteableCombOrder::linkInstrument4(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument4);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID4);
	return pInstrument4;
}

const CWriteableInstrument *CWriteableOTCOrder::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableInstrument *CWriteableQuote::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableQuote::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableTrade::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableTrade::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableFusePhase::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteablePartClient *CWriteableExecOrder::linkPartClient(CPartClientFactory *pFactory) const
{
	void *target=(void *)(&pPartClient);
	*((const CWriteablePartClient **)target)=pFactory->findByPartClient(ParticipantID,ClientID);
	return pPartClient;
}

const CWriteableInstrument *CWriteableExecOrder::linkInstrument(CInstrumentFactory *pFactory) const
{
	void *target=(void *)(&pInstrument);
	*((const CWriteableInstrument **)target)=pFactory->findByInstrumentID(InstrumentID);
	return pInstrument;
}

const CWriteableOrder *CWriteableOrderAction::linkOrder(COrderFactory *pFactory) const
{
	void *target=(void *)(&pOrder);
	*((const CWriteableOrder **)target)=pFactory->findByOrderID(OrderSysID);
	return pOrder;
}

const CWriteableQuote *CWriteableQuoteAction::linkQuote(CQuoteFactory *pFactory) const
{
	void *target=(void *)(&pQuote);
	*((const CWriteableQuote **)target)=pFactory->findByQuoteID(QuoteSysID);
	return pQuote;
}

const CWriteableExecOrder *CWriteableExecOrderAction::linkExecOrder(CExecOrderFactory *pFactory) const
{
	void *target=(void *)(&pExecOrder);
	*((const CWriteableExecOrder **)target)=pFactory->findByExecOrderID(ExecOrderSysID);
	return pExecOrder;
}

#endif


