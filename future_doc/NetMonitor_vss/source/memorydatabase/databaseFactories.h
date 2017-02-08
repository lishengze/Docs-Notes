/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file databaseFactories.h
///@brief���������ɸ��ڴ����ݿ�Ķ��󹤳�
///@history 
///20060127	���ض�		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef DATABASEFACTORIES_H
#define DATABASEFACTORIES_H

#include "platform.h"
#include "CBaseObject.h"
#include "CConfig.h"
#include "CAVLTree.h"
#include "CHashIndex.h"
#include "customDataType.h"
#include "CDatabaseDataFactory.h"
#include "CTransaction.h"
#include "BaseDataStruct.h"
#include "CDatabaseResource.h"
#include "Allocator.h"

class CExchangeDataSyncStatusFactory;
class CExchangeDataSyncStatusResource;
class CSGDataSyncStatusFactory;
class CSGDataSyncStatusResource;
class CCurrentTimeFactory;
class CCurrentTimeResource;
class CDataCenterDescFactory;
class CDataCenterDescResource;
class CExchangeFactory;
class CExchangeResource;
class CSettlementGroupFactory;
class CSettlementGroupResource;
class CMarketFactory;
class CMarketResource;
class CMarketProductFactory;
class CMarketProductResource;
class CMarketProductGroupFactory;
class CMarketProductGroupResource;
class CMdPubStatusFactory;
class CMdPubStatusResource;
class CMarketDataTopicFactory;
class CMarketDataTopicResource;
class CPartTopicSubscribeFactory;
class CPartTopicSubscribeResource;
class CParticipantFactory;
class CParticipantResource;
class CUserFactory;
class CUserResource;
class CClientFactory;
class CClientResource;
class CUserIPFactory;
class CUserIPResource;
class CPartClientFactory;
class CPartClientResource;
class CClearingTradingPartFactory;
class CClearingTradingPartResource;
class CAliasDefineFactory;
class CAliasDefineResource;
class CUserFunctionRightFactory;
class CUserFunctionRightResource;
class CAccountFactory;
class CAccountResource;
class CUserCommFluxFactory;
class CUserCommFluxResource;
class CMarketDataLogFactory;
class CMarketDataLogResource;
class CUserSessionFactory;
class CUserSessionResource;
class CMDSessionFactory;
class CMDSessionResource;
class CLoginInfoFactory;
class CLoginInfoResource;
class CDepthMarketDataDetailFactory;
class CDepthMarketDataDetailResource;
class CInstrumentStatusDetailFactory;
class CInstrumentStatusDetailResource;
class CFrontStatusFactory;
class CFrontStatusResource;
class CMaxLocalIDFactory;
class CMaxLocalIDResource;
class CBulletinFactory;
class CBulletinResource;
class CMarketDataModifyFactory;
class CMarketDataModifyResource;
class CDepthMarketDataFactory;
class CDepthMarketDataResource;
class CTopicMarketDataFactory;
class CTopicMarketDataResource;
class CTopicMarketDataVersionFactory;
class CTopicMarketDataVersionResource;
class CInformationFactory;
class CInformationResource;
class COrderCountFactory;
class COrderCountResource;
class CInstrumentFactory;
class CInstrumentResource;
class CCombinationLegFactory;
class CCombinationLegResource;
class CPartRoleAccountFactory;
class CPartRoleAccountResource;
class CPartProductRoleFactory;
class CPartProductRoleResource;
class CPartProductRightFactory;
class CPartProductRightResource;
class CPartInstrumentRightFactory;
class CPartInstrumentRightResource;
class CClientProductRightFactory;
class CClientProductRightResource;
class CClientInstrumentRightFactory;
class CClientInstrumentRightResource;
class CPartClientProductRightFactory;
class CPartClientProductRightResource;
class CPartClientInstrumentRightFactory;
class CPartClientInstrumentRightResource;
class CCurrProductPropertyFactory;
class CCurrProductPropertyResource;
class CCurrInstrumentPropertyFactory;
class CCurrInstrumentPropertyResource;
class CCurrPriceBandingFactory;
class CCurrPriceBandingResource;
class CCurrMarginRateFactory;
class CCurrMarginRateResource;
class CCurrMarginRateDetailFactory;
class CCurrMarginRateDetailResource;
class CCurrPartPosiLimitFactory;
class CCurrPartPosiLimitResource;
class CCurrPartPosiLimitDetailFactory;
class CCurrPartPosiLimitDetailResource;
class CCurrClientPosiLimitFactory;
class CCurrClientPosiLimitResource;
class CCurrClientPosiLimitDetailFactory;
class CCurrClientPosiLimitDetailResource;
class CCurrSpecialPosiLimitFactory;
class CCurrSpecialPosiLimitResource;
class CCurrSpecialPosiLimitDetailFactory;
class CCurrSpecialPosiLimitDetailResource;
class CCurrHedgeRuleFactory;
class CCurrHedgeRuleResource;
class CCurrTradingSegmentAttrFactory;
class CCurrTradingSegmentAttrResource;
class CCurrFuseFactory;
class CCurrFuseResource;
class CTradingAccountFactory;
class CTradingAccountResource;
class CBaseReserveAccountFactory;
class CBaseReserveAccountResource;
class CPartPositionFactory;
class CPartPositionResource;
class CClientPositionFactory;
class CClientPositionResource;
class CHedgeVolumeFactory;
class CHedgeVolumeResource;
class CRemainOrderFactory;
class CRemainOrderResource;
class CMarketDataFactory;
class CMarketDataResource;
class CClearingPartPositionFactory;
class CClearingPartPositionResource;
class CInstrumentStatusFactory;
class CInstrumentStatusResource;
class COrderFactory;
class COrderResource;
class CCombOrderFactory;
class CCombOrderResource;
class COTCOrderFactory;
class COTCOrderResource;
class CImplyOrderFactory;
class CImplyOrderResource;
class CQuoteFactory;
class CQuoteResource;
class CMBLMarketDataFactory;
class CMBLMarketDataResource;
class CTradeFactory;
class CTradeResource;
class CFusePhaseFactory;
class CFusePhaseResource;
class CExecOrderFactory;
class CExecOrderResource;
class CUniPressureFactory;
class CUniPressureResource;
class CBasePriceLimitFactory;
class CBasePriceLimitResource;
class CCreditLimitFactory;
class CCreditLimitResource;
class CHedgeDetailFactory;
class CHedgeDetailResource;
class COrderActionFactory;
class COrderActionResource;
class CQuoteActionFactory;
class CQuoteActionResource;
class CExecOrderActionFactory;
class CExecOrderActionResource;
class CAccountDepositFactory;
class CAccountDepositResource;
class CUpdateAllInstrumentStatusFactory;
class CUpdateAllInstrumentStatusResource;
class CAdminOrderFactory;
class CAdminOrderResource;
class CCommPhaseFactory;
class CCommPhaseResource;
class CCurrHedgeFactory;
class CCurrHedgeResource;
class CCurrInstrumentOptionFactory;
class CCurrInstrumentOptionResource;

/////////////////////////////////////////////////////////////////////////
///CExchangeDataSyncStatusFactory��һ������������ͬ��״̬�Ķ��󹤳�����������һ������������ͬ��״̬��
///ͬʱ�ֽ����������������Է����ѯ��
///	ExchangeIDIndex
///ʹ�ñ����󹤳���������ɶԽ���������ͬ��״̬����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByExchangeID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeDataSyncStatusFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CExchangeDataSyncStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxExchangeDataSyncStatus��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CExchangeDataSyncStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExchangeDataSyncStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ExchangeDataSyncStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ExchangeDataSyncStatus���ļ��������������ļ��еĶ���ExchangeDataSyncStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ExchangeDataSyncStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ExchangeDataSyncStatus���ļ��������������ļ��еĶ���ExchangeDataSyncStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CExchangeDataSyncStatusResource;

	///��һ��CExchangeDataSyncStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pExchangeDataSyncStatus	Ҫ�����ExchangeDataSyncStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CExchangeDataSyncStatus *add(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CExchangeDataSyncStatus��ֵ
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pExchangeDataSyncStatus	  ��Ҫ��ˢ�»���������CExchangeDataSyncStatus,����NULL��ʾ����Ҫ������
	///@param	pNewExchangeDataSyncStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CExchangeDataSyncStatus* addOrUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CExchangeDataSyncStatus��ͬʱɾ��������
	///@param	pExchangeDataSyncStatus	Ҫɾ����CExchangeDataSyncStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CExchangeDataSyncStatus
	///@param	pExchangeDataSyncStatus	Ҫ��ȡ��CExchangeDataSyncStatus
	///@param	pTragetExchangeDataSyncStatus	��Ž����CExchangeDataSyncStatus
	void retrieve(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pTargetExchangeDataSyncStatus);
	
	///��ȡ��һ��CExchangeDataSyncStatus
	///@return	�õ��ĵ�һ��CExchangeDataSyncStatus�����û�У��򷵻�NULL
	CExchangeDataSyncStatus *getFirst(void);
	
	///��ȡ��һ��CExchangeDataSyncStatus
	///@return	�õ���һ��CExchangeDataSyncStatus�����û�У��򷵻�NULL
	CExchangeDataSyncStatus *getNext(void);
	
	///������ȡCExchangeDataSyncStatus
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CExchangeDataSyncStatusActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CExchangeDataSyncStatusActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CExchangeDataSyncStatusCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CExchangeDataSyncStatusCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CExchangeDataSyncStatus
	///@param	ExchangeID	����������
	///@return	�ҵ���CExchangeDataSyncStatus������Ҳ���������NULL
	CExchangeDataSyncStatus *findByExchangeID( const CReadOnlyExchangeIDType&  ExchangeID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CExchangeDataSyncStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pExchangeDataSyncStatus	Ҫ�����ExchangeDataSyncStatus
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CExchangeDataSyncStatus *internalAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus, bool bNoTransaction);
	
	
	///ˢ�¸�CExchangeDataSyncStatus�ļ�ֵ
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CExchangeDataSyncStatus��ͬʱɾ��������
	///@param	pExchangeDataSyncStatus	Ҫɾ����CExchangeDataSyncStatus
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus, bool bNoTransaction);
/*
	///���ĳ��CExchangeDataSyncStatus�Ƿ����ڱ����󹤳�
	///@param	pExchangeDataSyncStatus	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ExchangeID������
	CAVLTree *pExchangeIDIndex;
	
	
	
	///����ǰ����
	///@param	pExchangeDataSyncStatus	Ҫ�����ExchangeDataSyncStatus
	virtual void beforeAdd(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///����󴥷�
	///@param	pExchangeDataSyncStatus	�Ѿ������ExchangeDataSyncStatus
	virtual void afterAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus);

	///����ǰ����	
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	///@param	pNewExchangeDataSyncStatus	�µ�ֵ
	virtual void beforeUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pNewExchangeDataSyncStatus);
	
	///���º󴥷�
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	virtual void afterUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///ɾ��ǰ����
	///@param	pExchangeDataSyncStatus	Ҫɾ����CExchangeDataSyncStatus
	virtual void beforeRemove(CExchangeDataSyncStatus *pExchangeDataSyncStatus);
	
	///ȷ�ϼ���󴥷�
	///@param	pExchangeDataSyncStatus	�Ѿ������ExchangeDataSyncStatus
	virtual void commitAdd(CExchangeDataSyncStatus *pExchangeDataSyncStatus);

	///ȷ�ϸ��º󴥷�
	///@param	pExchangeDataSyncStatus	��ˢ�µ�CExchangeDataSyncStatus
	///@param	poldExchangeDataSyncStatus	ԭ����ֵ
	virtual void commitUpdate(CExchangeDataSyncStatus *pExchangeDataSyncStatus, CWriteableExchangeDataSyncStatus *pOldExchangeDataSyncStatus);
	
	///ȷ��ɾ���󴥷�
	///@param	pExchangeDataSyncStatus	�Ѿ�ɾ����CExchangeDataSyncStatus
	virtual void commitRemove(CWriteableExchangeDataSyncStatus *pExchangeDataSyncStatus);

	///������صĴ�����
	vector<CExchangeDataSyncStatusActionTrigger *> *pActionTriggers;
	vector<CExchangeDataSyncStatusCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableExchangeDataSyncStatus compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSGDataSyncStatusFactory��һ������������ͬ��״̬�Ķ��󹤳�����������һ������������ͬ��״̬��
///ͬʱ�ֽ����������������Է����ѯ��
///	SettlementGroupIDIndex
///ʹ�ñ����󹤳���������ɶԽ���������ͬ��״̬����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findBySettlementGroupID��Ψһ�ҵ�����
///		ʹ��startFindStartBySettlementGroupID��findNextStartBySettlementGroupID��endFindStartBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSGDataSyncStatusFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CSGDataSyncStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxSGDataSyncStatus��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CSGDataSyncStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSGDataSyncStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�SGDataSyncStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�SGDataSyncStatus���ļ��������������ļ��еĶ���SGDataSyncStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�SGDataSyncStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�SGDataSyncStatus���ļ��������������ļ��еĶ���SGDataSyncStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CSGDataSyncStatusResource;

	///��һ��CSGDataSyncStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pSGDataSyncStatus	Ҫ�����SGDataSyncStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CSGDataSyncStatus *add(CWriteableSGDataSyncStatus *pSGDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CSGDataSyncStatus��ֵ
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pSGDataSyncStatus	  ��Ҫ��ˢ�»���������CSGDataSyncStatus,����NULL��ʾ����Ҫ������
	///@param	pNewSGDataSyncStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CSGDataSyncStatus* addOrUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CSGDataSyncStatus��ͬʱɾ��������
	///@param	pSGDataSyncStatus	Ҫɾ����CSGDataSyncStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CSGDataSyncStatus *pSGDataSyncStatus, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CSGDataSyncStatus
	///@param	pSGDataSyncStatus	Ҫ��ȡ��CSGDataSyncStatus
	///@param	pTragetSGDataSyncStatus	��Ž����CSGDataSyncStatus
	void retrieve(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pTargetSGDataSyncStatus);
	
	///��ȡ��һ��CSGDataSyncStatus
	///@return	�õ��ĵ�һ��CSGDataSyncStatus�����û�У��򷵻�NULL
	CSGDataSyncStatus *getFirst(void);
	
	///��ȡ��һ��CSGDataSyncStatus
	///@return	�õ���һ��CSGDataSyncStatus�����û�У��򷵻�NULL
	CSGDataSyncStatus *getNext(void);
	
	///������ȡCSGDataSyncStatus
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CSGDataSyncStatusActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CSGDataSyncStatusActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CSGDataSyncStatusCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CSGDataSyncStatusCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CSGDataSyncStatus
	///@param	SettlementGroupID	���������
	///@return	�ҵ���CSGDataSyncStatus������Ҳ���������NULL
	CSGDataSyncStatus *findBySettlementGroupID( const CReadOnlySettlementGroupIDType&  SettlementGroupID);



	friend class CSGDataSyncStatusIteratorStartBySettlementGroupID;

	///��ʼѰ��CSGDataSyncStatus
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CSGDataSyncStatus������Ҳ���������NULL
	CSGDataSyncStatus *startFindStartBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CSGDataSyncStatus��������startFindStartBySettlementGroupID�Ժ�endFindStartBySettlementGroupID֮ǰ����
	///@return	��һ����������CSGDataSyncStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CSGDataSyncStatus *findNextStartBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CSGDataSyncStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pSGDataSyncStatus	Ҫ�����SGDataSyncStatus
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CSGDataSyncStatus *internalAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus, bool bNoTransaction);
	
	
	///ˢ�¸�CSGDataSyncStatus�ļ�ֵ
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CSGDataSyncStatus��ͬʱɾ��������
	///@param	pSGDataSyncStatus	Ҫɾ����CSGDataSyncStatus
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CSGDataSyncStatus *pSGDataSyncStatus, bool bNoTransaction);
/*
	///���ĳ��CSGDataSyncStatus�Ƿ����ڱ����󹤳�
	///@param	pSGDataSyncStatus	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CSGDataSyncStatus *pSGDataSyncStatus);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����SettlementGroupID������
	CAVLTree *pSettlementGroupIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchStartBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartBySettlementGroupID;
	
	///����ǰ����
	///@param	pSGDataSyncStatus	Ҫ�����SGDataSyncStatus
	virtual void beforeAdd(CWriteableSGDataSyncStatus *pSGDataSyncStatus);
	
	///����󴥷�
	///@param	pSGDataSyncStatus	�Ѿ������SGDataSyncStatus
	virtual void afterAdd(CSGDataSyncStatus *pSGDataSyncStatus);

	///����ǰ����	
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	///@param	pNewSGDataSyncStatus	�µ�ֵ
	virtual void beforeUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pNewSGDataSyncStatus);
	
	///���º󴥷�
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	virtual void afterUpdate(CSGDataSyncStatus *pSGDataSyncStatus);
	
	///ɾ��ǰ����
	///@param	pSGDataSyncStatus	Ҫɾ����CSGDataSyncStatus
	virtual void beforeRemove(CSGDataSyncStatus *pSGDataSyncStatus);
	
	///ȷ�ϼ���󴥷�
	///@param	pSGDataSyncStatus	�Ѿ������SGDataSyncStatus
	virtual void commitAdd(CSGDataSyncStatus *pSGDataSyncStatus);

	///ȷ�ϸ��º󴥷�
	///@param	pSGDataSyncStatus	��ˢ�µ�CSGDataSyncStatus
	///@param	poldSGDataSyncStatus	ԭ����ֵ
	virtual void commitUpdate(CSGDataSyncStatus *pSGDataSyncStatus, CWriteableSGDataSyncStatus *pOldSGDataSyncStatus);
	
	///ȷ��ɾ���󴥷�
	///@param	pSGDataSyncStatus	�Ѿ�ɾ����CSGDataSyncStatus
	virtual void commitRemove(CWriteableSGDataSyncStatus *pSGDataSyncStatus);

	///������صĴ�����
	vector<CSGDataSyncStatusActionTrigger *> *pActionTriggers;
	vector<CSGDataSyncStatusCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableSGDataSyncStatus compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrentTimeFactory��һ����ǰʱ��Ķ��󹤳�����������һ����ǰʱ�䣬
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԵ�ǰʱ�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrentTimeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrentTime��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrentTimeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrentTimeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrentTime
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrentTime���ļ��������������ļ��еĶ���CurrentTimeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrentTime
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrentTime���ļ��������������ļ��еĶ���CurrentTimeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrentTimeResource;

	///��һ��CCurrentTime���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrentTime	Ҫ�����CurrentTime
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrentTime *add(CWriteableCurrentTime *pCurrentTime, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrentTime��ֵ
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	///@param	pNewCurrentTime	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrentTime	  ��Ҫ��ˢ�»���������CCurrentTime,����NULL��ʾ����Ҫ������
	///@param	pNewCurrentTime	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrentTime* addOrUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrentTime��ͬʱɾ��������
	///@param	pCurrentTime	Ҫɾ����CCurrentTime
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrentTime *pCurrentTime, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrentTime
	///@param	pCurrentTime	Ҫ��ȡ��CCurrentTime
	///@param	pTragetCurrentTime	��Ž����CCurrentTime
	void retrieve(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pTargetCurrentTime);
	
	///��ȡ��һ��CCurrentTime
	///@return	�õ��ĵ�һ��CCurrentTime�����û�У��򷵻�NULL
	CCurrentTime *getFirst(void);
	
	///��ȡ��һ��CCurrentTime
	///@return	�õ���һ��CCurrentTime�����û�У��򷵻�NULL
	CCurrentTime *getNext(void);
	
	///������ȡCCurrentTime
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrentTimeActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrentTimeActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrentTimeCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrentTimeCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrentTime���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrentTime	Ҫ�����CurrentTime
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrentTime *internalAdd(CWriteableCurrentTime *pCurrentTime, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrentTime�ļ�ֵ
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	///@param	pNewCurrentTime	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrentTime��ͬʱɾ��������
	///@param	pCurrentTime	Ҫɾ����CCurrentTime
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrentTime *pCurrentTime, bool bNoTransaction);
/*
	///���ĳ��CCurrentTime�Ƿ����ڱ����󹤳�
	///@param	pCurrentTime	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrentTime *pCurrentTime);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	
	///����ǰ����
	///@param	pCurrentTime	Ҫ�����CurrentTime
	virtual void beforeAdd(CWriteableCurrentTime *pCurrentTime);
	
	///����󴥷�
	///@param	pCurrentTime	�Ѿ������CurrentTime
	virtual void afterAdd(CCurrentTime *pCurrentTime);

	///����ǰ����	
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	///@param	pNewCurrentTime	�µ�ֵ
	virtual void beforeUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime);
	
	///���º󴥷�
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	virtual void afterUpdate(CCurrentTime *pCurrentTime);
	
	///ɾ��ǰ����
	///@param	pCurrentTime	Ҫɾ����CCurrentTime
	virtual void beforeRemove(CCurrentTime *pCurrentTime);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrentTime	�Ѿ������CurrentTime
	virtual void commitAdd(CCurrentTime *pCurrentTime);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrentTime	��ˢ�µ�CCurrentTime
	///@param	poldCurrentTime	ԭ����ֵ
	virtual void commitUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pOldCurrentTime);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrentTime	�Ѿ�ɾ����CCurrentTime
	virtual void commitRemove(CWriteableCurrentTime *pCurrentTime);

	///������صĴ�����
	vector<CCurrentTimeActionTrigger *> *pActionTriggers;
	vector<CCurrentTimeCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrentTime compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CDataCenterDescFactory��һ���������������Ķ��󹤳�����������һ����������������
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶ�����������������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDataCenterDescFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CDataCenterDescFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxDataCenterDesc��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CDataCenterDescFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDataCenterDescFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�DataCenterDesc
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�DataCenterDesc���ļ��������������ļ��еĶ���DataCenterDescCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�DataCenterDesc
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�DataCenterDesc���ļ��������������ļ��еĶ���DataCenterDescCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CDataCenterDescResource;

	///��һ��CDataCenterDesc���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pDataCenterDesc	Ҫ�����DataCenterDesc
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CDataCenterDesc *add(CWriteableDataCenterDesc *pDataCenterDesc, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CDataCenterDesc��ֵ
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	///@param	pNewDataCenterDesc	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pDataCenterDesc	  ��Ҫ��ˢ�»���������CDataCenterDesc,����NULL��ʾ����Ҫ������
	///@param	pNewDataCenterDesc	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CDataCenterDesc* addOrUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CDataCenterDesc��ͬʱɾ��������
	///@param	pDataCenterDesc	Ҫɾ����CDataCenterDesc
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CDataCenterDesc *pDataCenterDesc, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CDataCenterDesc
	///@param	pDataCenterDesc	Ҫ��ȡ��CDataCenterDesc
	///@param	pTragetDataCenterDesc	��Ž����CDataCenterDesc
	void retrieve(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pTargetDataCenterDesc);
	
	///��ȡ��һ��CDataCenterDesc
	///@return	�õ��ĵ�һ��CDataCenterDesc�����û�У��򷵻�NULL
	CDataCenterDesc *getFirst(void);
	
	///��ȡ��һ��CDataCenterDesc
	///@return	�õ���һ��CDataCenterDesc�����û�У��򷵻�NULL
	CDataCenterDesc *getNext(void);
	
	///������ȡCDataCenterDesc
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CDataCenterDescActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CDataCenterDescActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CDataCenterDescCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CDataCenterDescCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CDataCenterDesc���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pDataCenterDesc	Ҫ�����DataCenterDesc
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CDataCenterDesc *internalAdd(CWriteableDataCenterDesc *pDataCenterDesc, bool bNoTransaction);
	
	
	///ˢ�¸�CDataCenterDesc�ļ�ֵ
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	///@param	pNewDataCenterDesc	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CDataCenterDesc��ͬʱɾ��������
	///@param	pDataCenterDesc	Ҫɾ����CDataCenterDesc
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CDataCenterDesc *pDataCenterDesc, bool bNoTransaction);
/*
	///���ĳ��CDataCenterDesc�Ƿ����ڱ����󹤳�
	///@param	pDataCenterDesc	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CDataCenterDesc *pDataCenterDesc);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	
	///����ǰ����
	///@param	pDataCenterDesc	Ҫ�����DataCenterDesc
	virtual void beforeAdd(CWriteableDataCenterDesc *pDataCenterDesc);
	
	///����󴥷�
	///@param	pDataCenterDesc	�Ѿ������DataCenterDesc
	virtual void afterAdd(CDataCenterDesc *pDataCenterDesc);

	///����ǰ����	
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	///@param	pNewDataCenterDesc	�µ�ֵ
	virtual void beforeUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pNewDataCenterDesc);
	
	///���º󴥷�
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	virtual void afterUpdate(CDataCenterDesc *pDataCenterDesc);
	
	///ɾ��ǰ����
	///@param	pDataCenterDesc	Ҫɾ����CDataCenterDesc
	virtual void beforeRemove(CDataCenterDesc *pDataCenterDesc);
	
	///ȷ�ϼ���󴥷�
	///@param	pDataCenterDesc	�Ѿ������DataCenterDesc
	virtual void commitAdd(CDataCenterDesc *pDataCenterDesc);

	///ȷ�ϸ��º󴥷�
	///@param	pDataCenterDesc	��ˢ�µ�CDataCenterDesc
	///@param	poldDataCenterDesc	ԭ����ֵ
	virtual void commitUpdate(CDataCenterDesc *pDataCenterDesc, CWriteableDataCenterDesc *pOldDataCenterDesc);
	
	///ȷ��ɾ���󴥷�
	///@param	pDataCenterDesc	�Ѿ�ɾ����CDataCenterDesc
	virtual void commitRemove(CWriteableDataCenterDesc *pDataCenterDesc);

	///������صĴ�����
	vector<CDataCenterDescActionTrigger *> *pActionTriggers;
	vector<CDataCenterDescCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableDataCenterDesc compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CExchangeFactory��һ���������Ķ��󹤳�����������һ����������
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԽ���������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByExchangeID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExchangeFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CExchangeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxExchange��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CExchangeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExchangeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Exchange
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Exchange���ļ��������������ļ��еĶ���ExchangeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Exchange
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Exchange���ļ��������������ļ��еĶ���ExchangeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CExchangeResource;

	///��һ��CExchange���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pExchange	Ҫ�����Exchange
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CExchange *add(CWriteableExchange *pExchange, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CExchange��ֵ
	///@param	pExchange	��ˢ�µ�CExchange
	///@param	pNewExchange	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CExchange *pExchange, CWriteableExchange *pNewExchange, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pExchange	  ��Ҫ��ˢ�»���������CExchange,����NULL��ʾ����Ҫ������
	///@param	pNewExchange	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CExchange* addOrUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CExchange��ͬʱɾ��������
	///@param	pExchange	Ҫɾ����CExchange
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CExchange *pExchange, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CExchange
	///@param	pExchange	Ҫ��ȡ��CExchange
	///@param	pTragetExchange	��Ž����CExchange
	void retrieve(CExchange *pExchange, CWriteableExchange *pTargetExchange);
	
	///��ȡ��һ��CExchange
	///@return	�õ��ĵ�һ��CExchange�����û�У��򷵻�NULL
	CExchange *getFirst(void);
	
	///��ȡ��һ��CExchange
	///@return	�õ���һ��CExchange�����û�У��򷵻�NULL
	CExchange *getNext(void);
	
	///������ȡCExchange
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CExchangeActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CExchangeActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CExchangeCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CExchangeCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CExchange
	///@param	ExchangeID	���������
	///@return	�ҵ���CExchange������Ҳ���������NULL
	CExchange *findByExchangeID( const CReadOnlyExchangeIDType&  ExchangeID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CExchange���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pExchange	Ҫ�����Exchange
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CExchange *internalAdd(CWriteableExchange *pExchange, bool bNoTransaction);
	
	
	///ˢ�¸�CExchange�ļ�ֵ
	///@param	pExchange	��ˢ�µ�CExchange
	///@param	pNewExchange	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CExchange��ͬʱɾ��������
	///@param	pExchange	Ҫɾ����CExchange
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CExchange *pExchange, bool bNoTransaction);
/*
	///���ĳ��CExchange�Ƿ����ڱ����󹤳�
	///@param	pExchange	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CExchange *pExchange);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	
	///����ǰ����
	///@param	pExchange	Ҫ�����Exchange
	virtual void beforeAdd(CWriteableExchange *pExchange);
	
	///����󴥷�
	///@param	pExchange	�Ѿ������Exchange
	virtual void afterAdd(CExchange *pExchange);

	///����ǰ����	
	///@param	pExchange	��ˢ�µ�CExchange
	///@param	pNewExchange	�µ�ֵ
	virtual void beforeUpdate(CExchange *pExchange, CWriteableExchange *pNewExchange);
	
	///���º󴥷�
	///@param	pExchange	��ˢ�µ�CExchange
	virtual void afterUpdate(CExchange *pExchange);
	
	///ɾ��ǰ����
	///@param	pExchange	Ҫɾ����CExchange
	virtual void beforeRemove(CExchange *pExchange);
	
	///ȷ�ϼ���󴥷�
	///@param	pExchange	�Ѿ������Exchange
	virtual void commitAdd(CExchange *pExchange);

	///ȷ�ϸ��º󴥷�
	///@param	pExchange	��ˢ�µ�CExchange
	///@param	poldExchange	ԭ����ֵ
	virtual void commitUpdate(CExchange *pExchange, CWriteableExchange *pOldExchange);
	
	///ȷ��ɾ���󴥷�
	///@param	pExchange	�Ѿ�ɾ����CExchange
	virtual void commitRemove(CWriteableExchange *pExchange);

	///������صĴ�����
	vector<CExchangeActionTrigger *> *pActionTriggers;
	vector<CExchangeCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableExchange compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CSettlementGroupFactory��һ��������Ķ��󹤳�����������һ�������飬
///ͬʱ�ֽ����������������Է����ѯ��
///	SettlementGroupIDIndex
///ʹ�ñ����󹤳���������ɶԽ��������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findBySettlementGroupID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSettlementGroupFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CSettlementGroupFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxSettlementGroup��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CSettlementGroupFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSettlementGroupFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�SettlementGroup
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�SettlementGroup���ļ��������������ļ��еĶ���SettlementGroupCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�SettlementGroup
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�SettlementGroup���ļ��������������ļ��еĶ���SettlementGroupCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CSettlementGroupResource;

	///��һ��CSettlementGroup���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pSettlementGroup	Ҫ�����SettlementGroup
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CSettlementGroup *add(CWriteableSettlementGroup *pSettlementGroup, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CSettlementGroup��ֵ
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	///@param	pNewSettlementGroup	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pSettlementGroup	  ��Ҫ��ˢ�»���������CSettlementGroup,����NULL��ʾ����Ҫ������
	///@param	pNewSettlementGroup	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CSettlementGroup* addOrUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CSettlementGroup��ͬʱɾ��������
	///@param	pSettlementGroup	Ҫɾ����CSettlementGroup
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CSettlementGroup *pSettlementGroup, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CSettlementGroup
	///@param	pSettlementGroup	Ҫ��ȡ��CSettlementGroup
	///@param	pTragetSettlementGroup	��Ž����CSettlementGroup
	void retrieve(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pTargetSettlementGroup);
	
	///��ȡ��һ��CSettlementGroup
	///@return	�õ��ĵ�һ��CSettlementGroup�����û�У��򷵻�NULL
	CSettlementGroup *getFirst(void);
	
	///��ȡ��һ��CSettlementGroup
	///@return	�õ���һ��CSettlementGroup�����û�У��򷵻�NULL
	CSettlementGroup *getNext(void);
	
	///������ȡCSettlementGroup
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CSettlementGroupActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CSettlementGroupActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CSettlementGroupCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CSettlementGroupCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CSettlementGroup
	///@param	SettlementGroupID	��������
	///@return	�ҵ���CSettlementGroup������Ҳ���������NULL
	CSettlementGroup *findBySettlementGroupID( const CReadOnlySettlementGroupIDType&  SettlementGroupID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CSettlementGroup���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pSettlementGroup	Ҫ�����SettlementGroup
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CSettlementGroup *internalAdd(CWriteableSettlementGroup *pSettlementGroup, bool bNoTransaction);
	
	
	///ˢ�¸�CSettlementGroup�ļ�ֵ
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	///@param	pNewSettlementGroup	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CSettlementGroup��ͬʱɾ��������
	///@param	pSettlementGroup	Ҫɾ����CSettlementGroup
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CSettlementGroup *pSettlementGroup, bool bNoTransaction);
/*
	///���ĳ��CSettlementGroup�Ƿ����ڱ����󹤳�
	///@param	pSettlementGroup	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CSettlementGroup *pSettlementGroup);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����SettlementGroupID������
	CAVLTree *pSettlementGroupIDIndex;
	
	
	
	///����ǰ����
	///@param	pSettlementGroup	Ҫ�����SettlementGroup
	virtual void beforeAdd(CWriteableSettlementGroup *pSettlementGroup);
	
	///����󴥷�
	///@param	pSettlementGroup	�Ѿ������SettlementGroup
	virtual void afterAdd(CSettlementGroup *pSettlementGroup);

	///����ǰ����	
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	///@param	pNewSettlementGroup	�µ�ֵ
	virtual void beforeUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pNewSettlementGroup);
	
	///���º󴥷�
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	virtual void afterUpdate(CSettlementGroup *pSettlementGroup);
	
	///ɾ��ǰ����
	///@param	pSettlementGroup	Ҫɾ����CSettlementGroup
	virtual void beforeRemove(CSettlementGroup *pSettlementGroup);
	
	///ȷ�ϼ���󴥷�
	///@param	pSettlementGroup	�Ѿ������SettlementGroup
	virtual void commitAdd(CSettlementGroup *pSettlementGroup);

	///ȷ�ϸ��º󴥷�
	///@param	pSettlementGroup	��ˢ�µ�CSettlementGroup
	///@param	poldSettlementGroup	ԭ����ֵ
	virtual void commitUpdate(CSettlementGroup *pSettlementGroup, CWriteableSettlementGroup *pOldSettlementGroup);
	
	///ȷ��ɾ���󴥷�
	///@param	pSettlementGroup	�Ѿ�ɾ����CSettlementGroup
	virtual void commitRemove(CWriteableSettlementGroup *pSettlementGroup);

	///������صĴ�����
	vector<CSettlementGroupActionTrigger *> *pActionTriggers;
	vector<CSettlementGroupCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableSettlementGroup compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketFactory��һ���г��Ķ��󹤳�����������һ���г���
///ͬʱ�ֽ����������������Է����ѯ��
///	MarketIDIndex
///ʹ�ñ����󹤳���������ɶ��г�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByMarketID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMarket��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Market
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Market���ļ��������������ļ��еĶ���MarketCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Market
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Market���ļ��������������ļ��еĶ���MarketCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMarketResource;

	///��һ��CMarket���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarket	Ҫ�����Market
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarket *add(CWriteableMarket *pMarket, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMarket��ֵ
	///@param	pMarket	��ˢ�µ�CMarket
	///@param	pNewMarket	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMarket *pMarket, CWriteableMarket *pNewMarket, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMarket	  ��Ҫ��ˢ�»���������CMarket,����NULL��ʾ����Ҫ������
	///@param	pNewMarket	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMarket* addOrUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMarket��ͬʱɾ��������
	///@param	pMarket	Ҫɾ����CMarket
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMarket *pMarket, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMarket
	///@param	pMarket	Ҫ��ȡ��CMarket
	///@param	pTragetMarket	��Ž����CMarket
	void retrieve(CMarket *pMarket, CWriteableMarket *pTargetMarket);
	
	///��ȡ��һ��CMarket
	///@return	�õ��ĵ�һ��CMarket�����û�У��򷵻�NULL
	CMarket *getFirst(void);
	
	///��ȡ��һ��CMarket
	///@return	�õ���һ��CMarket�����û�У��򷵻�NULL
	CMarket *getNext(void);
	
	///������ȡCMarket
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMarketActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMarketActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMarketCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMarketCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CMarket
	///@param	MarketID	�г����
	///@return	�ҵ���CMarket������Ҳ���������NULL
	CMarket *findByMarketID( const CReadOnlyMarketIDType&  MarketID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMarket���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarket	Ҫ�����Market
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarket *internalAdd(CWriteableMarket *pMarket, bool bNoTransaction);
	
	
	///ˢ�¸�CMarket�ļ�ֵ
	///@param	pMarket	��ˢ�µ�CMarket
	///@param	pNewMarket	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMarket��ͬʱɾ��������
	///@param	pMarket	Ҫɾ����CMarket
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMarket *pMarket, bool bNoTransaction);
/*
	///���ĳ��CMarket�Ƿ����ڱ����󹤳�
	///@param	pMarket	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMarket *pMarket);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����MarketID������
	CAVLTree *pMarketIDIndex;
	
	
	
	///����ǰ����
	///@param	pMarket	Ҫ�����Market
	virtual void beforeAdd(CWriteableMarket *pMarket);
	
	///����󴥷�
	///@param	pMarket	�Ѿ������Market
	virtual void afterAdd(CMarket *pMarket);

	///����ǰ����	
	///@param	pMarket	��ˢ�µ�CMarket
	///@param	pNewMarket	�µ�ֵ
	virtual void beforeUpdate(CMarket *pMarket, CWriteableMarket *pNewMarket);
	
	///���º󴥷�
	///@param	pMarket	��ˢ�µ�CMarket
	virtual void afterUpdate(CMarket *pMarket);
	
	///ɾ��ǰ����
	///@param	pMarket	Ҫɾ����CMarket
	virtual void beforeRemove(CMarket *pMarket);
	
	///ȷ�ϼ���󴥷�
	///@param	pMarket	�Ѿ������Market
	virtual void commitAdd(CMarket *pMarket);

	///ȷ�ϸ��º󴥷�
	///@param	pMarket	��ˢ�µ�CMarket
	///@param	poldMarket	ԭ����ֵ
	virtual void commitUpdate(CMarket *pMarket, CWriteableMarket *pOldMarket);
	
	///ȷ��ɾ���󴥷�
	///@param	pMarket	�Ѿ�ɾ����CMarket
	virtual void commitRemove(CWriteableMarket *pMarket);

	///������صĴ�����
	vector<CMarketActionTrigger *> *pActionTriggers;
	vector<CMarketCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMarket compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductFactory��һ���г���Ʒ�����Ķ��󹤳�����������һ���г���Ʒ������
///ͬʱ�ֽ����������������Է����ѯ��
///	ProductIDIndex
///ʹ�ñ����󹤳���������ɶ��г���Ʒ��������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByProductID��findNextByProductID��endFindByProductID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketProductFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMarketProduct��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketProductFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketProductFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MarketProduct
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MarketProduct���ļ��������������ļ��еĶ���MarketProductCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MarketProduct
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MarketProduct���ļ��������������ļ��еĶ���MarketProductCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMarketProductResource;

	///��һ��CMarketProduct���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketProduct	Ҫ�����MarketProduct
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketProduct *add(CWriteableMarketProduct *pMarketProduct, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMarketProduct��ֵ
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	///@param	pNewMarketProduct	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMarketProduct	  ��Ҫ��ˢ�»���������CMarketProduct,����NULL��ʾ����Ҫ������
	///@param	pNewMarketProduct	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMarketProduct* addOrUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMarketProduct��ͬʱɾ��������
	///@param	pMarketProduct	Ҫɾ����CMarketProduct
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMarketProduct *pMarketProduct, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMarketProduct
	///@param	pMarketProduct	Ҫ��ȡ��CMarketProduct
	///@param	pTragetMarketProduct	��Ž����CMarketProduct
	void retrieve(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pTargetMarketProduct);
	
	///��ȡ��һ��CMarketProduct
	///@return	�õ��ĵ�һ��CMarketProduct�����û�У��򷵻�NULL
	CMarketProduct *getFirst(void);
	
	///��ȡ��һ��CMarketProduct
	///@return	�õ���һ��CMarketProduct�����û�У��򷵻�NULL
	CMarketProduct *getNext(void);
	
	///������ȡCMarketProduct
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMarketProductActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMarketProductActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMarketProductCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMarketProductCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CMarketProductIteratorByProductID;

	///��ʼѰ��CMarketProduct
	///@param	ProductID	��Ʒ����
	///@return	���������ĵ�һ��CMarketProduct������Ҳ���������NULL
	CMarketProduct *startFindByProductID( const CReadOnlyProductIDType& ProductID);

	///Ѱ����һ������������CMarketProduct��������startFindByProductID�Ժ�endFindByProductID֮ǰ����
	///@return	��һ����������CMarketProduct������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMarketProduct *findNextByProductID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByProductID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMarketProduct���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketProduct	Ҫ�����MarketProduct
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketProduct *internalAdd(CWriteableMarketProduct *pMarketProduct, bool bNoTransaction);
	
	
	///ˢ�¸�CMarketProduct�ļ�ֵ
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	///@param	pNewMarketProduct	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMarketProduct��ͬʱɾ��������
	///@param	pMarketProduct	Ҫɾ����CMarketProduct
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMarketProduct *pMarketProduct, bool bNoTransaction);
/*
	///���ĳ��CMarketProduct�Ƿ����ڱ����󹤳�
	///@param	pMarketProduct	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMarketProduct *pMarketProduct);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ProductID������
	CAVLTree *pProductIDIndex;
	
	
	///����ProductID����ʱ���洢�Ĳ�ѯ����
	CProductIDType queryProductIDInSearchByProductID;
	
	///����ProductID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByProductID;
	
	///����ǰ����
	///@param	pMarketProduct	Ҫ�����MarketProduct
	virtual void beforeAdd(CWriteableMarketProduct *pMarketProduct);
	
	///����󴥷�
	///@param	pMarketProduct	�Ѿ������MarketProduct
	virtual void afterAdd(CMarketProduct *pMarketProduct);

	///����ǰ����	
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	///@param	pNewMarketProduct	�µ�ֵ
	virtual void beforeUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pNewMarketProduct);
	
	///���º󴥷�
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	virtual void afterUpdate(CMarketProduct *pMarketProduct);
	
	///ɾ��ǰ����
	///@param	pMarketProduct	Ҫɾ����CMarketProduct
	virtual void beforeRemove(CMarketProduct *pMarketProduct);
	
	///ȷ�ϼ���󴥷�
	///@param	pMarketProduct	�Ѿ������MarketProduct
	virtual void commitAdd(CMarketProduct *pMarketProduct);

	///ȷ�ϸ��º󴥷�
	///@param	pMarketProduct	��ˢ�µ�CMarketProduct
	///@param	poldMarketProduct	ԭ����ֵ
	virtual void commitUpdate(CMarketProduct *pMarketProduct, CWriteableMarketProduct *pOldMarketProduct);
	
	///ȷ��ɾ���󴥷�
	///@param	pMarketProduct	�Ѿ�ɾ����CMarketProduct
	virtual void commitRemove(CWriteableMarketProduct *pMarketProduct);

	///������صĴ�����
	vector<CMarketProductActionTrigger *> *pActionTriggers;
	vector<CMarketProductCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMarketProduct compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketProductGroupFactory��һ���г���Ʒ������Ķ��󹤳�����������һ���г���Ʒ�������
///ͬʱ�ֽ����������������Է����ѯ��
///	ProductGroupIDIndex
///ʹ�ñ����󹤳���������ɶ��г���Ʒ���������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByProductGroupID��findNextByProductGroupID��endFindByProductGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketProductGroupFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketProductGroupFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMarketProductGroup��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketProductGroupFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketProductGroupFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MarketProductGroup
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MarketProductGroup���ļ��������������ļ��еĶ���MarketProductGroupCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MarketProductGroup
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MarketProductGroup���ļ��������������ļ��еĶ���MarketProductGroupCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMarketProductGroupResource;

	///��һ��CMarketProductGroup���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketProductGroup	Ҫ�����MarketProductGroup
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketProductGroup *add(CWriteableMarketProductGroup *pMarketProductGroup, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMarketProductGroup��ֵ
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	///@param	pNewMarketProductGroup	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMarketProductGroup	  ��Ҫ��ˢ�»���������CMarketProductGroup,����NULL��ʾ����Ҫ������
	///@param	pNewMarketProductGroup	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMarketProductGroup* addOrUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMarketProductGroup��ͬʱɾ��������
	///@param	pMarketProductGroup	Ҫɾ����CMarketProductGroup
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMarketProductGroup *pMarketProductGroup, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMarketProductGroup
	///@param	pMarketProductGroup	Ҫ��ȡ��CMarketProductGroup
	///@param	pTragetMarketProductGroup	��Ž����CMarketProductGroup
	void retrieve(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pTargetMarketProductGroup);
	
	///��ȡ��һ��CMarketProductGroup
	///@return	�õ��ĵ�һ��CMarketProductGroup�����û�У��򷵻�NULL
	CMarketProductGroup *getFirst(void);
	
	///��ȡ��һ��CMarketProductGroup
	///@return	�õ���һ��CMarketProductGroup�����û�У��򷵻�NULL
	CMarketProductGroup *getNext(void);
	
	///������ȡCMarketProductGroup
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMarketProductGroupActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMarketProductGroupActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMarketProductGroupCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMarketProductGroupCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CMarketProductGroupIteratorByProductGroupID;

	///��ʼѰ��CMarketProductGroup
	///@param	ProductGroupID	��Ʒ�����
	///@return	���������ĵ�һ��CMarketProductGroup������Ҳ���������NULL
	CMarketProductGroup *startFindByProductGroupID( const CReadOnlyProductGroupIDType& ProductGroupID);

	///Ѱ����һ������������CMarketProductGroup��������startFindByProductGroupID�Ժ�endFindByProductGroupID֮ǰ����
	///@return	��һ����������CMarketProductGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMarketProductGroup *findNextByProductGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByProductGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMarketProductGroup���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketProductGroup	Ҫ�����MarketProductGroup
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketProductGroup *internalAdd(CWriteableMarketProductGroup *pMarketProductGroup, bool bNoTransaction);
	
	
	///ˢ�¸�CMarketProductGroup�ļ�ֵ
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	///@param	pNewMarketProductGroup	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMarketProductGroup��ͬʱɾ��������
	///@param	pMarketProductGroup	Ҫɾ����CMarketProductGroup
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMarketProductGroup *pMarketProductGroup, bool bNoTransaction);
/*
	///���ĳ��CMarketProductGroup�Ƿ����ڱ����󹤳�
	///@param	pMarketProductGroup	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMarketProductGroup *pMarketProductGroup);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ProductGroupID������
	CAVLTree *pProductGroupIDIndex;
	
	
	///����ProductGroupID����ʱ���洢�Ĳ�ѯ����
	CProductGroupIDType queryProductGroupIDInSearchByProductGroupID;
	
	///����ProductGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByProductGroupID;
	
	///����ǰ����
	///@param	pMarketProductGroup	Ҫ�����MarketProductGroup
	virtual void beforeAdd(CWriteableMarketProductGroup *pMarketProductGroup);
	
	///����󴥷�
	///@param	pMarketProductGroup	�Ѿ������MarketProductGroup
	virtual void afterAdd(CMarketProductGroup *pMarketProductGroup);

	///����ǰ����	
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	///@param	pNewMarketProductGroup	�µ�ֵ
	virtual void beforeUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pNewMarketProductGroup);
	
	///���º󴥷�
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	virtual void afterUpdate(CMarketProductGroup *pMarketProductGroup);
	
	///ɾ��ǰ����
	///@param	pMarketProductGroup	Ҫɾ����CMarketProductGroup
	virtual void beforeRemove(CMarketProductGroup *pMarketProductGroup);
	
	///ȷ�ϼ���󴥷�
	///@param	pMarketProductGroup	�Ѿ������MarketProductGroup
	virtual void commitAdd(CMarketProductGroup *pMarketProductGroup);

	///ȷ�ϸ��º󴥷�
	///@param	pMarketProductGroup	��ˢ�µ�CMarketProductGroup
	///@param	poldMarketProductGroup	ԭ����ֵ
	virtual void commitUpdate(CMarketProductGroup *pMarketProductGroup, CWriteableMarketProductGroup *pOldMarketProductGroup);
	
	///ȷ��ɾ���󴥷�
	///@param	pMarketProductGroup	�Ѿ�ɾ����CMarketProductGroup
	virtual void commitRemove(CWriteableMarketProductGroup *pMarketProductGroup);

	///������صĴ�����
	vector<CMarketProductGroupActionTrigger *> *pActionTriggers;
	vector<CMarketProductGroupCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMarketProductGroup compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMdPubStatusFactory��һ�����鷢��״̬�Ķ��󹤳�����������һ�����鷢��״̬��
///ͬʱ�ֽ����������������Է����ѯ��
///	ProductIDInstrumentStatusIndex
///ʹ�ñ����󹤳���������ɶ����鷢��״̬����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByProductIDInstrumentStatus��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMdPubStatusFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMdPubStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMdPubStatus��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMdPubStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMdPubStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MdPubStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MdPubStatus���ļ��������������ļ��еĶ���MdPubStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MdPubStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MdPubStatus���ļ��������������ļ��еĶ���MdPubStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMdPubStatusResource;

	///��һ��CMdPubStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMdPubStatus	Ҫ�����MdPubStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMdPubStatus *add(CWriteableMdPubStatus *pMdPubStatus, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMdPubStatus��ֵ
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	///@param	pNewMdPubStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMdPubStatus	  ��Ҫ��ˢ�»���������CMdPubStatus,����NULL��ʾ����Ҫ������
	///@param	pNewMdPubStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMdPubStatus* addOrUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMdPubStatus��ͬʱɾ��������
	///@param	pMdPubStatus	Ҫɾ����CMdPubStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMdPubStatus *pMdPubStatus, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMdPubStatus
	///@param	pMdPubStatus	Ҫ��ȡ��CMdPubStatus
	///@param	pTragetMdPubStatus	��Ž����CMdPubStatus
	void retrieve(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pTargetMdPubStatus);
	
	///��ȡ��һ��CMdPubStatus
	///@return	�õ��ĵ�һ��CMdPubStatus�����û�У��򷵻�NULL
	CMdPubStatus *getFirst(void);
	
	///��ȡ��һ��CMdPubStatus
	///@return	�õ���һ��CMdPubStatus�����û�У��򷵻�NULL
	CMdPubStatus *getNext(void);
	
	///������ȡCMdPubStatus
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMdPubStatusActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMdPubStatusActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMdPubStatusCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMdPubStatusCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CMdPubStatus
	///@param	ProductID	��Ʒ����
	///@param	InstrumentStatus	��Լ����״̬
	///@return	�ҵ���CMdPubStatus������Ҳ���������NULL
	CMdPubStatus *findByProductIDInstrumentStatus( const CReadOnlyProductIDType&  ProductID,  const CReadOnlyInstrumentStatusType&  InstrumentStatus);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMdPubStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMdPubStatus	Ҫ�����MdPubStatus
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMdPubStatus *internalAdd(CWriteableMdPubStatus *pMdPubStatus, bool bNoTransaction);
	
	
	///ˢ�¸�CMdPubStatus�ļ�ֵ
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	///@param	pNewMdPubStatus	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMdPubStatus��ͬʱɾ��������
	///@param	pMdPubStatus	Ҫɾ����CMdPubStatus
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMdPubStatus *pMdPubStatus, bool bNoTransaction);
/*
	///���ĳ��CMdPubStatus�Ƿ����ڱ����󹤳�
	///@param	pMdPubStatus	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMdPubStatus *pMdPubStatus);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ProductID+InstrumentStatus������
	CAVLTree *pProductIDInstrumentStatusIndex;
	
	
	
	///����ǰ����
	///@param	pMdPubStatus	Ҫ�����MdPubStatus
	virtual void beforeAdd(CWriteableMdPubStatus *pMdPubStatus);
	
	///����󴥷�
	///@param	pMdPubStatus	�Ѿ������MdPubStatus
	virtual void afterAdd(CMdPubStatus *pMdPubStatus);

	///����ǰ����	
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	///@param	pNewMdPubStatus	�µ�ֵ
	virtual void beforeUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pNewMdPubStatus);
	
	///���º󴥷�
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	virtual void afterUpdate(CMdPubStatus *pMdPubStatus);
	
	///ɾ��ǰ����
	///@param	pMdPubStatus	Ҫɾ����CMdPubStatus
	virtual void beforeRemove(CMdPubStatus *pMdPubStatus);
	
	///ȷ�ϼ���󴥷�
	///@param	pMdPubStatus	�Ѿ������MdPubStatus
	virtual void commitAdd(CMdPubStatus *pMdPubStatus);

	///ȷ�ϸ��º󴥷�
	///@param	pMdPubStatus	��ˢ�µ�CMdPubStatus
	///@param	poldMdPubStatus	ԭ����ֵ
	virtual void commitUpdate(CMdPubStatus *pMdPubStatus, CWriteableMdPubStatus *pOldMdPubStatus);
	
	///ȷ��ɾ���󴥷�
	///@param	pMdPubStatus	�Ѿ�ɾ����CMdPubStatus
	virtual void commitRemove(CWriteableMdPubStatus *pMdPubStatus);

	///������صĴ�����
	vector<CMdPubStatusActionTrigger *> *pActionTriggers;
	vector<CMdPubStatusCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMdPubStatus compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataTopicFactory��һ����������Ķ��󹤳�����������һ���������⣬
///ͬʱ�ֽ����������������Է����ѯ��
///	TopicIDIndex
///	MarketIDIndex
///ʹ�ñ����󹤳���������ɶ������������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByTopicID��Ψһ�ҵ�����
///		ʹ��startFindByMarketID��findNextByMarketID��endFindByMarketID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataTopicFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataTopicFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMarketDataTopic��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataTopicFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataTopicFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MarketDataTopic
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MarketDataTopic���ļ��������������ļ��еĶ���MarketDataTopicCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MarketDataTopic
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MarketDataTopic���ļ��������������ļ��еĶ���MarketDataTopicCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMarketDataTopicResource;

	///��һ��CMarketDataTopic���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketDataTopic	Ҫ�����MarketDataTopic
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketDataTopic *add(CWriteableMarketDataTopic *pMarketDataTopic, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMarketDataTopic��ֵ
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	///@param	pNewMarketDataTopic	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMarketDataTopic	  ��Ҫ��ˢ�»���������CMarketDataTopic,����NULL��ʾ����Ҫ������
	///@param	pNewMarketDataTopic	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMarketDataTopic* addOrUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMarketDataTopic��ͬʱɾ��������
	///@param	pMarketDataTopic	Ҫɾ����CMarketDataTopic
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMarketDataTopic *pMarketDataTopic, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMarketDataTopic
	///@param	pMarketDataTopic	Ҫ��ȡ��CMarketDataTopic
	///@param	pTragetMarketDataTopic	��Ž����CMarketDataTopic
	void retrieve(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pTargetMarketDataTopic);
	
	///��ȡ��һ��CMarketDataTopic
	///@return	�õ��ĵ�һ��CMarketDataTopic�����û�У��򷵻�NULL
	CMarketDataTopic *getFirst(void);
	
	///��ȡ��һ��CMarketDataTopic
	///@return	�õ���һ��CMarketDataTopic�����û�У��򷵻�NULL
	CMarketDataTopic *getNext(void);
	
	///������ȡCMarketDataTopic
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMarketDataTopicActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMarketDataTopicActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMarketDataTopicCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMarketDataTopicCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CMarketDataTopic
	///@param	TopicID	�����������
	///@return	�ҵ���CMarketDataTopic������Ҳ���������NULL
	CMarketDataTopic *findByTopicID( const CReadOnlyTopicIDType&  TopicID);



	friend class CMarketDataTopicIteratorByMarketID;

	///��ʼѰ��CMarketDataTopic
	///@param	MarketID	�г�����
	///@return	���������ĵ�һ��CMarketDataTopic������Ҳ���������NULL
	CMarketDataTopic *startFindByMarketID( const CReadOnlyMarketIDType& MarketID);

	///Ѱ����һ������������CMarketDataTopic��������startFindByMarketID�Ժ�endFindByMarketID֮ǰ����
	///@return	��һ����������CMarketDataTopic������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMarketDataTopic *findNextByMarketID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByMarketID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMarketDataTopic���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketDataTopic	Ҫ�����MarketDataTopic
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketDataTopic *internalAdd(CWriteableMarketDataTopic *pMarketDataTopic, bool bNoTransaction);
	
	
	///ˢ�¸�CMarketDataTopic�ļ�ֵ
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	///@param	pNewMarketDataTopic	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMarketDataTopic��ͬʱɾ��������
	///@param	pMarketDataTopic	Ҫɾ����CMarketDataTopic
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMarketDataTopic *pMarketDataTopic, bool bNoTransaction);
/*
	///���ĳ��CMarketDataTopic�Ƿ����ڱ����󹤳�
	///@param	pMarketDataTopic	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMarketDataTopic *pMarketDataTopic);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����TopicID������
	CAVLTree *pTopicIDIndex;
	///����MarketID������
	CAVLTree *pMarketIDIndex;
	
	
	///����MarketID����ʱ���洢�Ĳ�ѯ����
	CMarketIDType queryMarketIDInSearchByMarketID;
	
	///����MarketID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByMarketID;
	
	///����ǰ����
	///@param	pMarketDataTopic	Ҫ�����MarketDataTopic
	virtual void beforeAdd(CWriteableMarketDataTopic *pMarketDataTopic);
	
	///����󴥷�
	///@param	pMarketDataTopic	�Ѿ������MarketDataTopic
	virtual void afterAdd(CMarketDataTopic *pMarketDataTopic);

	///����ǰ����	
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	///@param	pNewMarketDataTopic	�µ�ֵ
	virtual void beforeUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pNewMarketDataTopic);
	
	///���º󴥷�
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	virtual void afterUpdate(CMarketDataTopic *pMarketDataTopic);
	
	///ɾ��ǰ����
	///@param	pMarketDataTopic	Ҫɾ����CMarketDataTopic
	virtual void beforeRemove(CMarketDataTopic *pMarketDataTopic);
	
	///ȷ�ϼ���󴥷�
	///@param	pMarketDataTopic	�Ѿ������MarketDataTopic
	virtual void commitAdd(CMarketDataTopic *pMarketDataTopic);

	///ȷ�ϸ��º󴥷�
	///@param	pMarketDataTopic	��ˢ�µ�CMarketDataTopic
	///@param	poldMarketDataTopic	ԭ����ֵ
	virtual void commitUpdate(CMarketDataTopic *pMarketDataTopic, CWriteableMarketDataTopic *pOldMarketDataTopic);
	
	///ȷ��ɾ���󴥷�
	///@param	pMarketDataTopic	�Ѿ�ɾ����CMarketDataTopic
	virtual void commitRemove(CWriteableMarketDataTopic *pMarketDataTopic);

	///������صĴ�����
	vector<CMarketDataTopicActionTrigger *> *pActionTriggers;
	vector<CMarketDataTopicCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMarketDataTopic compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartTopicSubscribeFactory��һ����Ա�����г��Ķ��󹤳�����������һ����Ա�����г���
///ͬʱ�ֽ����������������Է����ѯ��
///	PartIDTopicIDIndex
///ʹ�ñ����󹤳���������ɶԻ�Ա�����г�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPartIDTopicID��Ψһ�ҵ�����
///		ʹ��startFindByPartID��findNextByPartID��endFindByPartID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartTopicSubscribeFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartTopicSubscribeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartTopicSubscribe��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartTopicSubscribeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartTopicSubscribeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartTopicSubscribe
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartTopicSubscribe���ļ��������������ļ��еĶ���PartTopicSubscribeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartTopicSubscribe
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartTopicSubscribe���ļ��������������ļ��еĶ���PartTopicSubscribeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartTopicSubscribeResource;

	///��һ��CPartTopicSubscribe���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartTopicSubscribe	Ҫ�����PartTopicSubscribe
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartTopicSubscribe *add(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartTopicSubscribe��ֵ
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartTopicSubscribe	  ��Ҫ��ˢ�»���������CPartTopicSubscribe,����NULL��ʾ����Ҫ������
	///@param	pNewPartTopicSubscribe	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartTopicSubscribe* addOrUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartTopicSubscribe��ͬʱɾ��������
	///@param	pPartTopicSubscribe	Ҫɾ����CPartTopicSubscribe
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartTopicSubscribe
	///@param	pPartTopicSubscribe	Ҫ��ȡ��CPartTopicSubscribe
	///@param	pTragetPartTopicSubscribe	��Ž����CPartTopicSubscribe
	void retrieve(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pTargetPartTopicSubscribe);
	
	///��ȡ��һ��CPartTopicSubscribe
	///@return	�õ��ĵ�һ��CPartTopicSubscribe�����û�У��򷵻�NULL
	CPartTopicSubscribe *getFirst(void);
	
	///��ȡ��һ��CPartTopicSubscribe
	///@return	�õ���һ��CPartTopicSubscribe�����û�У��򷵻�NULL
	CPartTopicSubscribe *getNext(void);
	
	///������ȡCPartTopicSubscribe
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartTopicSubscribeActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartTopicSubscribeActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartTopicSubscribeCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartTopicSubscribeCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CPartTopicSubscribe
	///@param	ParticipantID	��Ա����
	///@param	TopicID	�����������
	///@return	�ҵ���CPartTopicSubscribe������Ҳ���������NULL
	CPartTopicSubscribe *findByPartIDTopicID( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTopicIDType&  TopicID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա����
	///@param	TopicID	�����������
	///@return	�ҵ���CPartTopicSubscribe������Ҳ���������NULL
	CPartTopicSubscribe *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTopicIDType&  TopicID);
	
	///��������Ѱ��CPartTopicSubscribe
	///@param	pPartTopicSubscribe	Ҫ�ҵ�ֵ
	///@return	�ҵ���CPartTopicSubscribe������Ҳ���������NULL
	CPartTopicSubscribe *findByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe);

	///����������ȡCPartTopicSubscribe
	///@param	pPartTopicSubscribe	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CPartTopicSubscribe������Ҳ���������NULL
	bool retrieveByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe);

	///�������������µ�CPartTopicSubscribe
	///@param	pPartTopicSubscribe	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CPartTopicSubscribe���������ʧ�ܣ��򷵻�NULL
	CPartTopicSubscribe *addByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);

	///������������CPartTopicSubscribe��ֵ
	///@param	pPartTopicSubscribe	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CPartTopicSubscribe
	///@param	pPartTopicSubscribe	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteablePartTopicSubscribe *pPartTopicSubscribe, CTransaction *pTransaction=NULL);


	friend class CPartTopicSubscribeIteratorByPartID;

	///��ʼѰ��CPartTopicSubscribe
	///@param	ParticipantID	��Ա����
	///@return	���������ĵ�һ��CPartTopicSubscribe������Ҳ���������NULL
	CPartTopicSubscribe *startFindByPartID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CPartTopicSubscribe��������startFindByPartID�Ժ�endFindByPartID֮ǰ����
	///@return	��һ����������CPartTopicSubscribe������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartTopicSubscribe *findNextByPartID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByPartID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartTopicSubscribe���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartTopicSubscribe	Ҫ�����PartTopicSubscribe
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartTopicSubscribe *internalAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe, bool bNoTransaction);
	
	
	///ˢ�¸�CPartTopicSubscribe�ļ�ֵ
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartTopicSubscribe��ͬʱɾ��������
	///@param	pPartTopicSubscribe	Ҫɾ����CPartTopicSubscribe
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartTopicSubscribe *pPartTopicSubscribe, bool bNoTransaction);
/*
	///���ĳ��CPartTopicSubscribe�Ƿ����ڱ����󹤳�
	///@param	pPartTopicSubscribe	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartTopicSubscribe *pPartTopicSubscribe);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID+TopicID������
	CAVLTree *pPartIDTopicIDIndex;
	
	
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchByPartID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByPartID;
	
	///����ǰ����
	///@param	pPartTopicSubscribe	Ҫ�����PartTopicSubscribe
	virtual void beforeAdd(CWriteablePartTopicSubscribe *pPartTopicSubscribe);
	
	///����󴥷�
	///@param	pPartTopicSubscribe	�Ѿ������PartTopicSubscribe
	virtual void afterAdd(CPartTopicSubscribe *pPartTopicSubscribe);

	///����ǰ����	
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	///@param	pNewPartTopicSubscribe	�µ�ֵ
	virtual void beforeUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pNewPartTopicSubscribe);
	
	///���º󴥷�
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	virtual void afterUpdate(CPartTopicSubscribe *pPartTopicSubscribe);
	
	///ɾ��ǰ����
	///@param	pPartTopicSubscribe	Ҫɾ����CPartTopicSubscribe
	virtual void beforeRemove(CPartTopicSubscribe *pPartTopicSubscribe);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartTopicSubscribe	�Ѿ������PartTopicSubscribe
	virtual void commitAdd(CPartTopicSubscribe *pPartTopicSubscribe);

	///ȷ�ϸ��º󴥷�
	///@param	pPartTopicSubscribe	��ˢ�µ�CPartTopicSubscribe
	///@param	poldPartTopicSubscribe	ԭ����ֵ
	virtual void commitUpdate(CPartTopicSubscribe *pPartTopicSubscribe, CWriteablePartTopicSubscribe *pOldPartTopicSubscribe);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartTopicSubscribe	�Ѿ�ɾ����CPartTopicSubscribe
	virtual void commitRemove(CWriteablePartTopicSubscribe *pPartTopicSubscribe);

	///������صĴ�����
	vector<CPartTopicSubscribeActionTrigger *> *pActionTriggers;
	vector<CPartTopicSubscribeCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartTopicSubscribe compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CParticipantFactory��һ����Ա�Ķ��󹤳�����������һ����Ա��
///ͬʱ�ֽ����������������Է����ѯ��
///	ParticipantIDIndex
///ʹ�ñ����󹤳���������ɶԻ�Ա����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByParticipantID��Ψһ�ҵ�����
///		ʹ��startFindStartByParticipantID��findNextStartByParticipantID��endFindStartByParticipantID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CParticipantFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CParticipantFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxParticipant��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CParticipantFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CParticipantFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Participant
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Participant���ļ��������������ļ��еĶ���ParticipantCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Participant
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Participant���ļ��������������ļ��еĶ���ParticipantCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CParticipantResource;

	///��һ��CParticipant���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pParticipant	Ҫ�����Participant
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CParticipant *add(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CParticipant��ֵ
	///@param	pParticipant	��ˢ�µ�CParticipant
	///@param	pNewParticipant	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pParticipant	  ��Ҫ��ˢ�»���������CParticipant,����NULL��ʾ����Ҫ������
	///@param	pNewParticipant	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CParticipant* addOrUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CParticipant��ͬʱɾ��������
	///@param	pParticipant	Ҫɾ����CParticipant
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CParticipant *pParticipant, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CParticipant
	///@param	pParticipant	Ҫ��ȡ��CParticipant
	///@param	pTragetParticipant	��Ž����CParticipant
	void retrieve(CParticipant *pParticipant, CWriteableParticipant *pTargetParticipant);
	
	///��ȡ��һ��CParticipant
	///@return	�õ��ĵ�һ��CParticipant�����û�У��򷵻�NULL
	CParticipant *getFirst(void);
	
	///��ȡ��һ��CParticipant
	///@return	�õ���һ��CParticipant�����û�У��򷵻�NULL
	CParticipant *getNext(void);
	
	///������ȡCParticipant
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CParticipantActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CParticipantActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CParticipantCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CParticipantCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�Ľ��㽻�׻�Ա��ϵ��ָ��
	///@param	pFactory	�����Ӧ�Ľ��㽻�׻�Ա��ϵ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllClearingTradingPart(CClearingTradingPartFactory *pFactory);
	
	///Ѱ��CParticipant
	///@param	ParticipantID	��Ա���
	///@return	�ҵ���CParticipant������Ҳ���������NULL
	CParticipant *findByParticipantID( const CReadOnlyParticipantIDType&  ParticipantID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա���
	///@return	�ҵ���CParticipant������Ҳ���������NULL
	CParticipant *findByPK( const CReadOnlyParticipantIDType&  ParticipantID);
	
	///��������Ѱ��CParticipant
	///@param	pParticipant	Ҫ�ҵ�ֵ
	///@return	�ҵ���CParticipant������Ҳ���������NULL
	CParticipant *findByPK(CWriteableParticipant *pParticipant);

	///����������ȡCParticipant
	///@param	pParticipant	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CParticipant������Ҳ���������NULL
	bool retrieveByPK(CWriteableParticipant *pParticipant);

	///�������������µ�CParticipant
	///@param	pParticipant	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CParticipant���������ʧ�ܣ��򷵻�NULL
	CParticipant *addByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL);

	///������������CParticipant��ֵ
	///@param	pParticipant	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CParticipant
	///@param	pParticipant	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableParticipant *pParticipant, CTransaction *pTransaction=NULL);


	friend class CParticipantIteratorStartByParticipantID;

	///��ʼѰ��CParticipant
	///@param	ParticipantID	��Ա���
	///@return	���������ĵ�һ��CParticipant������Ҳ���������NULL
	CParticipant *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CParticipant��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CParticipant������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CParticipant *findNextStartByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipantID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CParticipant���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pParticipant	Ҫ�����Participant
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CParticipant *internalAdd(CWriteableParticipant *pParticipant, bool bNoTransaction);
	
	
	///ˢ�¸�CParticipant�ļ�ֵ
	///@param	pParticipant	��ˢ�µ�CParticipant
	///@param	pNewParticipant	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CParticipant��ͬʱɾ��������
	///@param	pParticipant	Ҫɾ����CParticipant
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CParticipant *pParticipant, bool bNoTransaction);
/*
	///���ĳ��CParticipant�Ƿ����ڱ����󹤳�
	///@param	pParticipant	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CParticipant *pParticipant);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID������
	CAVLTree *pParticipantIDIndex;
	
	
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	
	///����ǰ����
	///@param	pParticipant	Ҫ�����Participant
	virtual void beforeAdd(CWriteableParticipant *pParticipant);
	
	///����󴥷�
	///@param	pParticipant	�Ѿ������Participant
	virtual void afterAdd(CParticipant *pParticipant);

	///����ǰ����	
	///@param	pParticipant	��ˢ�µ�CParticipant
	///@param	pNewParticipant	�µ�ֵ
	virtual void beforeUpdate(CParticipant *pParticipant, CWriteableParticipant *pNewParticipant);
	
	///���º󴥷�
	///@param	pParticipant	��ˢ�µ�CParticipant
	virtual void afterUpdate(CParticipant *pParticipant);
	
	///ɾ��ǰ����
	///@param	pParticipant	Ҫɾ����CParticipant
	virtual void beforeRemove(CParticipant *pParticipant);
	
	///ȷ�ϼ���󴥷�
	///@param	pParticipant	�Ѿ������Participant
	virtual void commitAdd(CParticipant *pParticipant);

	///ȷ�ϸ��º󴥷�
	///@param	pParticipant	��ˢ�µ�CParticipant
	///@param	poldParticipant	ԭ����ֵ
	virtual void commitUpdate(CParticipant *pParticipant, CWriteableParticipant *pOldParticipant);
	
	///ȷ��ɾ���󴥷�
	///@param	pParticipant	�Ѿ�ɾ����CParticipant
	virtual void commitRemove(CWriteableParticipant *pParticipant);

	///������صĴ�����
	vector<CParticipantActionTrigger *> *pActionTriggers;
	vector<CParticipantCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableParticipant compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserFactory��һ���û��Ķ��󹤳�����������һ���û���
///ͬʱ�ֽ����������������Է����ѯ��
///	UserIDIndex
///ʹ�ñ����󹤳���������ɶ��û�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByUserID��Ψһ�ҵ�����
///		ʹ��startFindStartByUserID��findNextStartByUserID��endFindStartByUserID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxUser��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�User
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�User���ļ��������������ļ��еĶ���UserCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�User
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�User���ļ��������������ļ��еĶ���UserCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CUserResource;

	///��һ��CUser���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUser	Ҫ�����User
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUser *add(CWriteableUser *pUser, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CUser��ֵ
	///@param	pUser	��ˢ�µ�CUser
	///@param	pNewUser	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CUser *pUser, CWriteableUser *pNewUser, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pUser	  ��Ҫ��ˢ�»���������CUser,����NULL��ʾ����Ҫ������
	///@param	pNewUser	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CUser* addOrUpdate(CUser *pUser, CWriteableUser *pNewUser, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CUser��ͬʱɾ��������
	///@param	pUser	Ҫɾ����CUser
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CUser *pUser, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CUser
	///@param	pUser	Ҫ��ȡ��CUser
	///@param	pTragetUser	��Ž����CUser
	void retrieve(CUser *pUser, CWriteableUser *pTargetUser);
	
	///��ȡ��һ��CUser
	///@return	�õ��ĵ�һ��CUser�����û�У��򷵻�NULL
	CUser *getFirst(void);
	
	///��ȡ��һ��CUser
	///@return	�õ���һ��CUser�����û�У��򷵻�NULL
	CUser *getNext(void);
	
	///������ȡCUser
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CUserActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CUserActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CUserCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CUserCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CUser
	///@param	UserID	�û����
	///@return	�ҵ���CUser������Ҳ���������NULL
	CUser *findByUserID( const CReadOnlyUserIDType&  UserID);

	///��������Ѱ��
	///@param	UserID	�û����
	///@return	�ҵ���CUser������Ҳ���������NULL
	CUser *findByPK( const CReadOnlyUserIDType&  UserID);
	
	///��������Ѱ��CUser
	///@param	pUser	Ҫ�ҵ�ֵ
	///@return	�ҵ���CUser������Ҳ���������NULL
	CUser *findByPK(CWriteableUser *pUser);

	///����������ȡCUser
	///@param	pUser	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CUser������Ҳ���������NULL
	bool retrieveByPK(CWriteableUser *pUser);

	///�������������µ�CUser
	///@param	pUser	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CUser���������ʧ�ܣ��򷵻�NULL
	CUser *addByPK(CWriteableUser *pUser, CTransaction *pTransaction=NULL);

	///������������CUser��ֵ
	///@param	pUser	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableUser *pUser, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CUser
	///@param	pUser	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableUser *pUser, CTransaction *pTransaction=NULL);


	friend class CUserIteratorStartByUserID;

	///��ʼѰ��CUser
	///@param	UserID	�û����
	///@return	���������ĵ�һ��CUser������Ҳ���������NULL
	CUser *startFindStartByUserID( const CReadOnlyUserIDType& UserID);

	///Ѱ����һ������������CUser��������startFindStartByUserID�Ժ�endFindStartByUserID֮ǰ����
	///@return	��һ����������CUser������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CUser *findNextStartByUserID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByUserID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CUser���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUser	Ҫ�����User
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUser *internalAdd(CWriteableUser *pUser, bool bNoTransaction);
	
	
	///ˢ�¸�CUser�ļ�ֵ
	///@param	pUser	��ˢ�µ�CUser
	///@param	pNewUser	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CUser *pUser, CWriteableUser *pNewUser, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CUser��ͬʱɾ��������
	///@param	pUser	Ҫɾ����CUser
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CUser *pUser, bool bNoTransaction);
/*
	///���ĳ��CUser�Ƿ����ڱ����󹤳�
	///@param	pUser	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CUser *pUser);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����UserID������
	CAVLTree *pUserIDIndex;
	
	
	///����UserID����ʱ���洢�Ĳ�ѯ����
	CUserIDType queryUserIDInSearchStartByUserID;
	
	///����UserID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByUserID;
	
	///����ǰ����
	///@param	pUser	Ҫ�����User
	virtual void beforeAdd(CWriteableUser *pUser);
	
	///����󴥷�
	///@param	pUser	�Ѿ������User
	virtual void afterAdd(CUser *pUser);

	///����ǰ����	
	///@param	pUser	��ˢ�µ�CUser
	///@param	pNewUser	�µ�ֵ
	virtual void beforeUpdate(CUser *pUser, CWriteableUser *pNewUser);
	
	///���º󴥷�
	///@param	pUser	��ˢ�µ�CUser
	virtual void afterUpdate(CUser *pUser);
	
	///ɾ��ǰ����
	///@param	pUser	Ҫɾ����CUser
	virtual void beforeRemove(CUser *pUser);
	
	///ȷ�ϼ���󴥷�
	///@param	pUser	�Ѿ������User
	virtual void commitAdd(CUser *pUser);

	///ȷ�ϸ��º󴥷�
	///@param	pUser	��ˢ�µ�CUser
	///@param	poldUser	ԭ����ֵ
	virtual void commitUpdate(CUser *pUser, CWriteableUser *pOldUser);
	
	///ȷ��ɾ���󴥷�
	///@param	pUser	�Ѿ�ɾ����CUser
	virtual void commitRemove(CWriteableUser *pUser);

	///������صĴ�����
	vector<CUserActionTrigger *> *pActionTriggers;
	vector<CUserCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableUser compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientFactory��һ���ͻ��Ķ��󹤳�����������һ���ͻ���
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԿͻ�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByClientID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxClient��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Client
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Client���ļ��������������ļ��еĶ���ClientCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Client
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Client���ļ��������������ļ��еĶ���ClientCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CClientResource;

	///��һ��CClient���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClient	Ҫ�����Client
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClient *add(CWriteableClient *pClient, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CClient��ֵ
	///@param	pClient	��ˢ�µ�CClient
	///@param	pNewClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CClient *pClient, CWriteableClient *pNewClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pClient	  ��Ҫ��ˢ�»���������CClient,����NULL��ʾ����Ҫ������
	///@param	pNewClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CClient* addOrUpdate(CClient *pClient, CWriteableClient *pNewClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CClient��ͬʱɾ��������
	///@param	pClient	Ҫɾ����CClient
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CClient *pClient, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CClient
	///@param	pClient	Ҫ��ȡ��CClient
	///@param	pTragetClient	��Ž����CClient
	void retrieve(CClient *pClient, CWriteableClient *pTargetClient);
	
	///��ȡ��һ��CClient
	///@return	�õ��ĵ�һ��CClient�����û�У��򷵻�NULL
	CClient *getFirst(void);
	
	///��ȡ��һ��CClient
	///@return	�õ���һ��CClient�����û�У��򷵻�NULL
	CClient *getNext(void);
	
	///������ȡCClient
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CClientActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CClientActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CClientCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CClientCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CClient
	///@param	ClientID	�ͻ����
	///@return	�ҵ���CClient������Ҳ���������NULL
	CClient *findByClientID( const CReadOnlyClientIDType&  ClientID);

	///��������Ѱ��
	///@param	ClientID	�ͻ����
	///@return	�ҵ���CClient������Ҳ���������NULL
	CClient *findByPK( const CReadOnlyClientIDType&  ClientID);
	
	///��������Ѱ��CClient
	///@param	pClient	Ҫ�ҵ�ֵ
	///@return	�ҵ���CClient������Ҳ���������NULL
	CClient *findByPK(CWriteableClient *pClient);

	///����������ȡCClient
	///@param	pClient	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CClient������Ҳ���������NULL
	bool retrieveByPK(CWriteableClient *pClient);

	///�������������µ�CClient
	///@param	pClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CClient���������ʧ�ܣ��򷵻�NULL
	CClient *addByPK(CWriteableClient *pClient, CTransaction *pTransaction=NULL);

	///������������CClient��ֵ
	///@param	pClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableClient *pClient, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CClient
	///@param	pClient	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableClient *pClient, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CClient���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClient	Ҫ�����Client
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClient *internalAdd(CWriteableClient *pClient, bool bNoTransaction);
	
	
	///ˢ�¸�CClient�ļ�ֵ
	///@param	pClient	��ˢ�µ�CClient
	///@param	pNewClient	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CClient *pClient, CWriteableClient *pNewClient, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CClient��ͬʱɾ��������
	///@param	pClient	Ҫɾ����CClient
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CClient *pClient, bool bNoTransaction);
/*
	///���ĳ��CClient�Ƿ����ڱ����󹤳�
	///@param	pClient	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CClient *pClient);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ClientID��hash����
	CHashIndex *pClientIDHashIndex;
	
	
	///����ǰ����
	///@param	pClient	Ҫ�����Client
	virtual void beforeAdd(CWriteableClient *pClient);
	
	///����󴥷�
	///@param	pClient	�Ѿ������Client
	virtual void afterAdd(CClient *pClient);

	///����ǰ����	
	///@param	pClient	��ˢ�µ�CClient
	///@param	pNewClient	�µ�ֵ
	virtual void beforeUpdate(CClient *pClient, CWriteableClient *pNewClient);
	
	///���º󴥷�
	///@param	pClient	��ˢ�µ�CClient
	virtual void afterUpdate(CClient *pClient);
	
	///ɾ��ǰ����
	///@param	pClient	Ҫɾ����CClient
	virtual void beforeRemove(CClient *pClient);
	
	///ȷ�ϼ���󴥷�
	///@param	pClient	�Ѿ������Client
	virtual void commitAdd(CClient *pClient);

	///ȷ�ϸ��º󴥷�
	///@param	pClient	��ˢ�µ�CClient
	///@param	poldClient	ԭ����ֵ
	virtual void commitUpdate(CClient *pClient, CWriteableClient *pOldClient);
	
	///ȷ��ɾ���󴥷�
	///@param	pClient	�Ѿ�ɾ����CClient
	virtual void commitRemove(CWriteableClient *pClient);

	///������صĴ�����
	vector<CClientActionTrigger *> *pActionTriggers;
	vector<CClientCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableClient compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserIPFactory��һ������ԱIP��ַ�Ķ��󹤳�����������һ������ԱIP��ַ��
///ͬʱ�ֽ����������������Է����ѯ��
///	UserIPMaskIndex
///ʹ�ñ����󹤳���������ɶԽ���ԱIP��ַ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByUserID��findNextByUserID��endFindByUserID��ɲ�ѯ����
///		ʹ��findByUserIPAndMask��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserIPFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserIPFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxUserIP��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserIPFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserIPFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�UserIP
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�UserIP���ļ��������������ļ��еĶ���UserIPCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�UserIP
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�UserIP���ļ��������������ļ��еĶ���UserIPCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CUserIPResource;

	///��һ��CUserIP���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserIP	Ҫ�����UserIP
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserIP *add(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CUserIP��ֵ
	///@param	pUserIP	��ˢ�µ�CUserIP
	///@param	pNewUserIP	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pUserIP	  ��Ҫ��ˢ�»���������CUserIP,����NULL��ʾ����Ҫ������
	///@param	pNewUserIP	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CUserIP* addOrUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CUserIP��ͬʱɾ��������
	///@param	pUserIP	Ҫɾ����CUserIP
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CUserIP *pUserIP, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CUserIP
	///@param	pUserIP	Ҫ��ȡ��CUserIP
	///@param	pTragetUserIP	��Ž����CUserIP
	void retrieve(CUserIP *pUserIP, CWriteableUserIP *pTargetUserIP);
	
	///��ȡ��һ��CUserIP
	///@return	�õ��ĵ�һ��CUserIP�����û�У��򷵻�NULL
	CUserIP *getFirst(void);
	
	///��ȡ��һ��CUserIP
	///@return	�õ���һ��CUserIP�����û�У��򷵻�NULL
	CUserIP *getNext(void);
	
	///������ȡCUserIP
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CUserIPActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CUserIPActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CUserIPCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CUserIPCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CUserIPIteratorByUserID;

	///��ʼѰ��CUserIP
	///@param	UserID	�û����
	///@return	���������ĵ�һ��CUserIP������Ҳ���������NULL
	CUserIP *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///Ѱ����һ������������CUserIP��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CUserIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CUserIP *findNextByUserID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByUserID(void);

	///Ѱ��CUserIP
	///@param	UserID	�û����
	///@param	IPAddress	IP��ַ
	///@param	IPMask	IP��ַ����
	///@return	�ҵ���CUserIP������Ҳ���������NULL
	CUserIP *findByUserIPAndMask( const CReadOnlyUserIDType&  UserID,  const CReadOnlyIPAddressType&  IPAddress,  const CReadOnlyIPAddressType&  IPMask);

	///��������Ѱ��
	///@param	UserID	�û����
	///@param	IPAddress	IP��ַ
	///@param	IPMask	IP��ַ����
	///@return	�ҵ���CUserIP������Ҳ���������NULL
	CUserIP *findByPK( const CReadOnlyUserIDType&  UserID,  const CReadOnlyIPAddressType&  IPAddress,  const CReadOnlyIPAddressType&  IPMask);
	
	///��������Ѱ��CUserIP
	///@param	pUserIP	Ҫ�ҵ�ֵ
	///@return	�ҵ���CUserIP������Ҳ���������NULL
	CUserIP *findByPK(CWriteableUserIP *pUserIP);

	///����������ȡCUserIP
	///@param	pUserIP	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CUserIP������Ҳ���������NULL
	bool retrieveByPK(CWriteableUserIP *pUserIP);

	///�������������µ�CUserIP
	///@param	pUserIP	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CUserIP���������ʧ�ܣ��򷵻�NULL
	CUserIP *addByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL);

	///������������CUserIP��ֵ
	///@param	pUserIP	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CUserIP
	///@param	pUserIP	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableUserIP *pUserIP, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CUserIP���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserIP	Ҫ�����UserIP
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserIP *internalAdd(CWriteableUserIP *pUserIP, bool bNoTransaction);
	
	
	///ˢ�¸�CUserIP�ļ�ֵ
	///@param	pUserIP	��ˢ�µ�CUserIP
	///@param	pNewUserIP	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CUserIP��ͬʱɾ��������
	///@param	pUserIP	Ҫɾ����CUserIP
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CUserIP *pUserIP, bool bNoTransaction);
/*
	///���ĳ��CUserIP�Ƿ����ڱ����󹤳�
	///@param	pUserIP	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CUserIP *pUserIP);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����UserID+IPAddress+IPMask������
	CAVLTree *pUserIPMaskIndex;
	
	
	///����UserID����ʱ���洢�Ĳ�ѯ����
	CUserIDType queryUserIDInSearchByUserID;
	
	///����UserID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByUserID;
	
	///����ǰ����
	///@param	pUserIP	Ҫ�����UserIP
	virtual void beforeAdd(CWriteableUserIP *pUserIP);
	
	///����󴥷�
	///@param	pUserIP	�Ѿ������UserIP
	virtual void afterAdd(CUserIP *pUserIP);

	///����ǰ����	
	///@param	pUserIP	��ˢ�µ�CUserIP
	///@param	pNewUserIP	�µ�ֵ
	virtual void beforeUpdate(CUserIP *pUserIP, CWriteableUserIP *pNewUserIP);
	
	///���º󴥷�
	///@param	pUserIP	��ˢ�µ�CUserIP
	virtual void afterUpdate(CUserIP *pUserIP);
	
	///ɾ��ǰ����
	///@param	pUserIP	Ҫɾ����CUserIP
	virtual void beforeRemove(CUserIP *pUserIP);
	
	///ȷ�ϼ���󴥷�
	///@param	pUserIP	�Ѿ������UserIP
	virtual void commitAdd(CUserIP *pUserIP);

	///ȷ�ϸ��º󴥷�
	///@param	pUserIP	��ˢ�µ�CUserIP
	///@param	poldUserIP	ԭ����ֵ
	virtual void commitUpdate(CUserIP *pUserIP, CWriteableUserIP *pOldUserIP);
	
	///ȷ��ɾ���󴥷�
	///@param	pUserIP	�Ѿ�ɾ����CUserIP
	virtual void commitRemove(CWriteableUserIP *pUserIP);

	///������صĴ�����
	vector<CUserIPActionTrigger *> *pActionTriggers;
	vector<CUserIPCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableUserIP compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientFactory��һ����Ա�ͻ���ϵ�Ķ��󹤳�����������һ����Ա�ͻ���ϵ��
///ͬʱ�ֽ����������������Է����ѯ��
///	PartClientIndex
///	ClientIndex
///ʹ�ñ����󹤳���������ɶԻ�Ա�ͻ���ϵ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPartClient��Ψһ�ҵ�����
///		ʹ��startFindStartByParticipant��findNextStartByParticipant��endFindStartByParticipant��ɲ�ѯ����
///		ʹ��startFindStartByClient��findNextStartByClient��endFindStartByClient��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartClientFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartClient��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartClientFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartClient
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartClient���ļ��������������ļ��еĶ���PartClientCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartClient
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartClient���ļ��������������ļ��еĶ���PartClientCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartClientResource;

	///��һ��CPartClient���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartClient	Ҫ�����PartClient
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartClient *add(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartClient��ֵ
	///@param	pPartClient	��ˢ�µ�CPartClient
	///@param	pNewPartClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartClient	  ��Ҫ��ˢ�»���������CPartClient,����NULL��ʾ����Ҫ������
	///@param	pNewPartClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartClient* addOrUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartClient��ͬʱɾ��������
	///@param	pPartClient	Ҫɾ����CPartClient
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartClient *pPartClient, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartClient
	///@param	pPartClient	Ҫ��ȡ��CPartClient
	///@param	pTragetPartClient	��Ž����CPartClient
	void retrieve(CPartClient *pPartClient, CWriteablePartClient *pTargetPartClient);
	
	///��ȡ��һ��CPartClient
	///@return	�õ��ĵ�һ��CPartClient�����û�У��򷵻�NULL
	CPartClient *getFirst(void);
	
	///��ȡ��һ��CPartClient
	///@return	�õ���һ��CPartClient�����û�У��򷵻�NULL
	CPartClient *getNext(void);
	
	///������ȡCPartClient
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartClientActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartClientActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartClientCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartClientCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�Ļ�Ա��ָ��
	///@param	pFactory	�����Ӧ�Ļ�Ա��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllParticipant(CParticipantFactory *pFactory);
	
	///�������ж�Ӧ�Ŀͻ���ָ��
	///@param	pFactory	�����Ӧ�Ŀͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllClient(CClientFactory *pFactory);
	
	///Ѱ��CPartClient
	///@param	ParticipantID	��Ա��
	///@param	ClientID	�ͻ���
	///@return	�ҵ���CPartClient������Ҳ���������NULL
	CPartClient *findByPartClient( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա��
	///@param	ClientID	�ͻ���
	///@return	�ҵ���CPartClient������Ҳ���������NULL
	CPartClient *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID);
	
	///��������Ѱ��CPartClient
	///@param	pPartClient	Ҫ�ҵ�ֵ
	///@return	�ҵ���CPartClient������Ҳ���������NULL
	CPartClient *findByPK(CWriteablePartClient *pPartClient);

	///����������ȡCPartClient
	///@param	pPartClient	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CPartClient������Ҳ���������NULL
	bool retrieveByPK(CWriteablePartClient *pPartClient);

	///�������������µ�CPartClient
	///@param	pPartClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CPartClient���������ʧ�ܣ��򷵻�NULL
	CPartClient *addByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL);

	///������������CPartClient��ֵ
	///@param	pPartClient	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CPartClient
	///@param	pPartClient	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteablePartClient *pPartClient, CTransaction *pTransaction=NULL);


	friend class CPartClientIteratorStartByParticipant;

	///��ʼѰ��CPartClient
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CPartClient������Ҳ���������NULL
	CPartClient *startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CPartClient��������startFindStartByParticipant�Ժ�endFindStartByParticipant֮ǰ����
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartClient *findNextStartByParticipant(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipant(void);

	friend class CPartClientIteratorStartByClient;

	///��ʼѰ��CPartClient
	///@param	ClientID	�ͻ���
	///@return	���������ĵ�һ��CPartClient������Ҳ���������NULL
	CPartClient *startFindStartByClient( const CReadOnlyClientIDType& ClientID);

	///Ѱ����һ������������CPartClient��������startFindStartByClient�Ժ�endFindStartByClient֮ǰ����
	///@return	��һ����������CPartClient������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartClient *findNextStartByClient(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByClient(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartClient���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartClient	Ҫ�����PartClient
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartClient *internalAdd(CWriteablePartClient *pPartClient, bool bNoTransaction);
	
	
	///ˢ�¸�CPartClient�ļ�ֵ
	///@param	pPartClient	��ˢ�µ�CPartClient
	///@param	pNewPartClient	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartClient��ͬʱɾ��������
	///@param	pPartClient	Ҫɾ����CPartClient
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartClient *pPartClient, bool bNoTransaction);
/*
	///���ĳ��CPartClient�Ƿ����ڱ����󹤳�
	///@param	pPartClient	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartClient *pPartClient);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID+ClientID������
	CAVLTree *pPartClientIndex;
	///����ClientID������
	CAVLTree *pClientIndex;
	
	///����PartClient��hash����
	CHashIndex *pPartClientHashIndex;
	
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipant;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipant;
	///����ClientID����ʱ���洢�Ĳ�ѯ����
	CClientIDType queryClientIDInSearchStartByClient;
	
	///����ClientID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByClient;
	
	///����ǰ����
	///@param	pPartClient	Ҫ�����PartClient
	virtual void beforeAdd(CWriteablePartClient *pPartClient);
	
	///����󴥷�
	///@param	pPartClient	�Ѿ������PartClient
	virtual void afterAdd(CPartClient *pPartClient);

	///����ǰ����	
	///@param	pPartClient	��ˢ�µ�CPartClient
	///@param	pNewPartClient	�µ�ֵ
	virtual void beforeUpdate(CPartClient *pPartClient, CWriteablePartClient *pNewPartClient);
	
	///���º󴥷�
	///@param	pPartClient	��ˢ�µ�CPartClient
	virtual void afterUpdate(CPartClient *pPartClient);
	
	///ɾ��ǰ����
	///@param	pPartClient	Ҫɾ����CPartClient
	virtual void beforeRemove(CPartClient *pPartClient);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartClient	�Ѿ������PartClient
	virtual void commitAdd(CPartClient *pPartClient);

	///ȷ�ϸ��º󴥷�
	///@param	pPartClient	��ˢ�µ�CPartClient
	///@param	poldPartClient	ԭ����ֵ
	virtual void commitUpdate(CPartClient *pPartClient, CWriteablePartClient *pOldPartClient);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartClient	�Ѿ�ɾ����CPartClient
	virtual void commitRemove(CWriteablePartClient *pPartClient);

	///������صĴ�����
	vector<CPartClientActionTrigger *> *pActionTriggers;
	vector<CPartClientCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartClient compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClearingTradingPartFactory��һ�����㽻�׻�Ա��ϵ�Ķ��󹤳�����������һ�����㽻�׻�Ա��ϵ��
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԽ��㽻�׻�Ա��ϵ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByParticipant��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingTradingPartFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClearingTradingPartFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxClearingTradingPart��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClearingTradingPartFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClearingTradingPartFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ClearingTradingPart
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ClearingTradingPart���ļ��������������ļ��еĶ���ClearingTradingPartCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ClearingTradingPart
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ClearingTradingPart���ļ��������������ļ��еĶ���ClearingTradingPartCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CClearingTradingPartResource;

	///��һ��CClearingTradingPart���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClearingTradingPart	Ҫ�����ClearingTradingPart
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClearingTradingPart *add(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CClearingTradingPart��ֵ
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	///@param	pNewClearingTradingPart	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pClearingTradingPart	  ��Ҫ��ˢ�»���������CClearingTradingPart,����NULL��ʾ����Ҫ������
	///@param	pNewClearingTradingPart	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CClearingTradingPart* addOrUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CClearingTradingPart��ͬʱɾ��������
	///@param	pClearingTradingPart	Ҫɾ����CClearingTradingPart
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CClearingTradingPart
	///@param	pClearingTradingPart	Ҫ��ȡ��CClearingTradingPart
	///@param	pTragetClearingTradingPart	��Ž����CClearingTradingPart
	void retrieve(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pTargetClearingTradingPart);
	
	///��ȡ��һ��CClearingTradingPart
	///@return	�õ��ĵ�һ��CClearingTradingPart�����û�У��򷵻�NULL
	CClearingTradingPart *getFirst(void);
	
	///��ȡ��һ��CClearingTradingPart
	///@return	�õ���һ��CClearingTradingPart�����û�У��򷵻�NULL
	CClearingTradingPart *getNext(void);
	
	///������ȡCClearingTradingPart
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CClearingTradingPartActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CClearingTradingPartActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CClearingTradingPartCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CClearingTradingPartCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CClearingTradingPart
	///@param	ParticipantID	��Ա��
	///@return	�ҵ���CClearingTradingPart������Ҳ���������NULL
	CClearingTradingPart *findByParticipant( const CReadOnlyParticipantIDType&  ParticipantID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա��
	///@return	�ҵ���CClearingTradingPart������Ҳ���������NULL
	CClearingTradingPart *findByPK( const CReadOnlyParticipantIDType&  ParticipantID);
	
	///��������Ѱ��CClearingTradingPart
	///@param	pClearingTradingPart	Ҫ�ҵ�ֵ
	///@return	�ҵ���CClearingTradingPart������Ҳ���������NULL
	CClearingTradingPart *findByPK(CWriteableClearingTradingPart *pClearingTradingPart);

	///����������ȡCClearingTradingPart
	///@param	pClearingTradingPart	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CClearingTradingPart������Ҳ���������NULL
	bool retrieveByPK(CWriteableClearingTradingPart *pClearingTradingPart);

	///�������������µ�CClearingTradingPart
	///@param	pClearingTradingPart	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CClearingTradingPart���������ʧ�ܣ��򷵻�NULL
	CClearingTradingPart *addByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);

	///������������CClearingTradingPart��ֵ
	///@param	pClearingTradingPart	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CClearingTradingPart
	///@param	pClearingTradingPart	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableClearingTradingPart *pClearingTradingPart, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CClearingTradingPart���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClearingTradingPart	Ҫ�����ClearingTradingPart
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClearingTradingPart *internalAdd(CWriteableClearingTradingPart *pClearingTradingPart, bool bNoTransaction);
	
	
	///ˢ�¸�CClearingTradingPart�ļ�ֵ
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	///@param	pNewClearingTradingPart	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CClearingTradingPart��ͬʱɾ��������
	///@param	pClearingTradingPart	Ҫɾ����CClearingTradingPart
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CClearingTradingPart *pClearingTradingPart, bool bNoTransaction);
/*
	///���ĳ��CClearingTradingPart�Ƿ����ڱ����󹤳�
	///@param	pClearingTradingPart	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CClearingTradingPart *pClearingTradingPart);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ParticipantID��hash����
	CHashIndex *pParticipantIDHashIndex;
	
	
	///����ǰ����
	///@param	pClearingTradingPart	Ҫ�����ClearingTradingPart
	virtual void beforeAdd(CWriteableClearingTradingPart *pClearingTradingPart);
	
	///����󴥷�
	///@param	pClearingTradingPart	�Ѿ������ClearingTradingPart
	virtual void afterAdd(CClearingTradingPart *pClearingTradingPart);

	///����ǰ����	
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	///@param	pNewClearingTradingPart	�µ�ֵ
	virtual void beforeUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pNewClearingTradingPart);
	
	///���º󴥷�
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	virtual void afterUpdate(CClearingTradingPart *pClearingTradingPart);
	
	///ɾ��ǰ����
	///@param	pClearingTradingPart	Ҫɾ����CClearingTradingPart
	virtual void beforeRemove(CClearingTradingPart *pClearingTradingPart);
	
	///ȷ�ϼ���󴥷�
	///@param	pClearingTradingPart	�Ѿ������ClearingTradingPart
	virtual void commitAdd(CClearingTradingPart *pClearingTradingPart);

	///ȷ�ϸ��º󴥷�
	///@param	pClearingTradingPart	��ˢ�µ�CClearingTradingPart
	///@param	poldClearingTradingPart	ԭ����ֵ
	virtual void commitUpdate(CClearingTradingPart *pClearingTradingPart, CWriteableClearingTradingPart *pOldClearingTradingPart);
	
	///ȷ��ɾ���󴥷�
	///@param	pClearingTradingPart	�Ѿ�ɾ����CClearingTradingPart
	virtual void commitRemove(CWriteableClearingTradingPart *pClearingTradingPart);

	///������صĴ�����
	vector<CClearingTradingPartActionTrigger *> *pActionTriggers;
	vector<CClearingTradingPartCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableClearingTradingPart compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CAliasDefineFactory��һ����������Ķ��󹤳�����������һ���������壬
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԱ����������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAliasDefineFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CAliasDefineFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxAliasDefine��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CAliasDefineFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CAliasDefineFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�AliasDefine
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�AliasDefine���ļ��������������ļ��еĶ���AliasDefineCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�AliasDefine
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�AliasDefine���ļ��������������ļ��еĶ���AliasDefineCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CAliasDefineResource;

	///��һ��CAliasDefine���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pAliasDefine	Ҫ�����AliasDefine
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CAliasDefine *add(CWriteableAliasDefine *pAliasDefine, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CAliasDefine��ֵ
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	///@param	pNewAliasDefine	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pAliasDefine	  ��Ҫ��ˢ�»���������CAliasDefine,����NULL��ʾ����Ҫ������
	///@param	pNewAliasDefine	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CAliasDefine* addOrUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CAliasDefine��ͬʱɾ��������
	///@param	pAliasDefine	Ҫɾ����CAliasDefine
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CAliasDefine *pAliasDefine, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CAliasDefine
	///@param	pAliasDefine	Ҫ��ȡ��CAliasDefine
	///@param	pTragetAliasDefine	��Ž����CAliasDefine
	void retrieve(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pTargetAliasDefine);
	
	///��ȡ��һ��CAliasDefine
	///@return	�õ��ĵ�һ��CAliasDefine�����û�У��򷵻�NULL
	CAliasDefine *getFirst(void);
	
	///��ȡ��һ��CAliasDefine
	///@return	�õ���һ��CAliasDefine�����û�У��򷵻�NULL
	CAliasDefine *getNext(void);
	
	///������ȡCAliasDefine
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CAliasDefineActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CAliasDefineActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CAliasDefineCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CAliasDefineCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CAliasDefine���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pAliasDefine	Ҫ�����AliasDefine
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CAliasDefine *internalAdd(CWriteableAliasDefine *pAliasDefine, bool bNoTransaction);
	
	
	///ˢ�¸�CAliasDefine�ļ�ֵ
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	///@param	pNewAliasDefine	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CAliasDefine��ͬʱɾ��������
	///@param	pAliasDefine	Ҫɾ����CAliasDefine
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CAliasDefine *pAliasDefine, bool bNoTransaction);
/*
	///���ĳ��CAliasDefine�Ƿ����ڱ����󹤳�
	///@param	pAliasDefine	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CAliasDefine *pAliasDefine);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	
	///����ǰ����
	///@param	pAliasDefine	Ҫ�����AliasDefine
	virtual void beforeAdd(CWriteableAliasDefine *pAliasDefine);
	
	///����󴥷�
	///@param	pAliasDefine	�Ѿ������AliasDefine
	virtual void afterAdd(CAliasDefine *pAliasDefine);

	///����ǰ����	
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	///@param	pNewAliasDefine	�µ�ֵ
	virtual void beforeUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pNewAliasDefine);
	
	///���º󴥷�
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	virtual void afterUpdate(CAliasDefine *pAliasDefine);
	
	///ɾ��ǰ����
	///@param	pAliasDefine	Ҫɾ����CAliasDefine
	virtual void beforeRemove(CAliasDefine *pAliasDefine);
	
	///ȷ�ϼ���󴥷�
	///@param	pAliasDefine	�Ѿ������AliasDefine
	virtual void commitAdd(CAliasDefine *pAliasDefine);

	///ȷ�ϸ��º󴥷�
	///@param	pAliasDefine	��ˢ�µ�CAliasDefine
	///@param	poldAliasDefine	ԭ����ֵ
	virtual void commitUpdate(CAliasDefine *pAliasDefine, CWriteableAliasDefine *pOldAliasDefine);
	
	///ȷ��ɾ���󴥷�
	///@param	pAliasDefine	�Ѿ�ɾ����CAliasDefine
	virtual void commitRemove(CWriteableAliasDefine *pAliasDefine);

	///������صĴ�����
	vector<CAliasDefineActionTrigger *> *pActionTriggers;
	vector<CAliasDefineCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableAliasDefine compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserFunctionRightFactory��һ���û�����Ȩ�޵Ķ��󹤳�����������һ���û�����Ȩ�ޣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶ��û�����Ȩ�޵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByUserFunction��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserFunctionRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxUserFunctionRight��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserFunctionRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserFunctionRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�UserFunctionRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�UserFunctionRight���ļ��������������ļ��еĶ���UserFunctionRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�UserFunctionRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�UserFunctionRight���ļ��������������ļ��еĶ���UserFunctionRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CUserFunctionRightResource;

	///��һ��CUserFunctionRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserFunctionRight	Ҫ�����UserFunctionRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserFunctionRight *add(CWriteableUserFunctionRight *pUserFunctionRight, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CUserFunctionRight��ֵ
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	///@param	pNewUserFunctionRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pUserFunctionRight	  ��Ҫ��ˢ�»���������CUserFunctionRight,����NULL��ʾ����Ҫ������
	///@param	pNewUserFunctionRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CUserFunctionRight* addOrUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CUserFunctionRight��ͬʱɾ��������
	///@param	pUserFunctionRight	Ҫɾ����CUserFunctionRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CUserFunctionRight *pUserFunctionRight, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CUserFunctionRight
	///@param	pUserFunctionRight	Ҫ��ȡ��CUserFunctionRight
	///@param	pTragetUserFunctionRight	��Ž����CUserFunctionRight
	void retrieve(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pTargetUserFunctionRight);
	
	///��ȡ��һ��CUserFunctionRight
	///@return	�õ��ĵ�һ��CUserFunctionRight�����û�У��򷵻�NULL
	CUserFunctionRight *getFirst(void);
	
	///��ȡ��һ��CUserFunctionRight
	///@return	�õ���һ��CUserFunctionRight�����û�У��򷵻�NULL
	CUserFunctionRight *getNext(void);
	
	///������ȡCUserFunctionRight
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CUserFunctionRightActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CUserFunctionRightActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CUserFunctionRightCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CUserFunctionRightCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CUserFunctionRight
	///@param	UserID	�û�����
	///@param	FunctionCode	���ܴ���
	///@return	�ҵ���CUserFunctionRight������Ҳ���������NULL
	CUserFunctionRight *findByUserFunction( const CReadOnlyUserIDType&  UserID,  const CReadOnlyFunctionCodeType&  FunctionCode);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CUserFunctionRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserFunctionRight	Ҫ�����UserFunctionRight
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserFunctionRight *internalAdd(CWriteableUserFunctionRight *pUserFunctionRight, bool bNoTransaction);
	
	
	///ˢ�¸�CUserFunctionRight�ļ�ֵ
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	///@param	pNewUserFunctionRight	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CUserFunctionRight��ͬʱɾ��������
	///@param	pUserFunctionRight	Ҫɾ����CUserFunctionRight
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CUserFunctionRight *pUserFunctionRight, bool bNoTransaction);
/*
	///���ĳ��CUserFunctionRight�Ƿ����ڱ����󹤳�
	///@param	pUserFunctionRight	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CUserFunctionRight *pUserFunctionRight);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����UserFunction��hash����
	CHashIndex *pUserFunctionHashIndex;
	
	
	///����ǰ����
	///@param	pUserFunctionRight	Ҫ�����UserFunctionRight
	virtual void beforeAdd(CWriteableUserFunctionRight *pUserFunctionRight);
	
	///����󴥷�
	///@param	pUserFunctionRight	�Ѿ������UserFunctionRight
	virtual void afterAdd(CUserFunctionRight *pUserFunctionRight);

	///����ǰ����	
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	///@param	pNewUserFunctionRight	�µ�ֵ
	virtual void beforeUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight);
	
	///���º󴥷�
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	virtual void afterUpdate(CUserFunctionRight *pUserFunctionRight);
	
	///ɾ��ǰ����
	///@param	pUserFunctionRight	Ҫɾ����CUserFunctionRight
	virtual void beforeRemove(CUserFunctionRight *pUserFunctionRight);
	
	///ȷ�ϼ���󴥷�
	///@param	pUserFunctionRight	�Ѿ������UserFunctionRight
	virtual void commitAdd(CUserFunctionRight *pUserFunctionRight);

	///ȷ�ϸ��º󴥷�
	///@param	pUserFunctionRight	��ˢ�µ�CUserFunctionRight
	///@param	poldUserFunctionRight	ԭ����ֵ
	virtual void commitUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pOldUserFunctionRight);
	
	///ȷ��ɾ���󴥷�
	///@param	pUserFunctionRight	�Ѿ�ɾ����CUserFunctionRight
	virtual void commitRemove(CWriteableUserFunctionRight *pUserFunctionRight);

	///������صĴ�����
	vector<CUserFunctionRightActionTrigger *> *pActionTriggers;
	vector<CUserFunctionRightCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableUserFunctionRight compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CAccountFactory��һ���ʽ��˻��Ķ��󹤳�����������һ���ʽ��˻���
///ͬʱ�ֽ����������������Է����ѯ��
///	AccountIDIndex
///	ParticipantIDIndex
///ʹ�ñ����󹤳���������ɶ��ʽ��˻�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByAccountID��Ψһ�ҵ�����
///		ʹ��startFindStartByParticipantID��findNextStartByParticipantID��endFindStartByParticipantID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CAccountFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxAccount��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Account
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Account���ļ��������������ļ��еĶ���AccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Account
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Account���ļ��������������ļ��еĶ���AccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CAccountResource;

	///��һ��CAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pAccount	Ҫ�����Account
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CAccount *add(CWriteableAccount *pAccount, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CAccount��ֵ
	///@param	pAccount	��ˢ�µ�CAccount
	///@param	pNewAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CAccount *pAccount, CWriteableAccount *pNewAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pAccount	  ��Ҫ��ˢ�»���������CAccount,����NULL��ʾ����Ҫ������
	///@param	pNewAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CAccount* addOrUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CAccount��ͬʱɾ��������
	///@param	pAccount	Ҫɾ����CAccount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CAccount *pAccount, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CAccount
	///@param	pAccount	Ҫ��ȡ��CAccount
	///@param	pTragetAccount	��Ž����CAccount
	void retrieve(CAccount *pAccount, CWriteableAccount *pTargetAccount);
	
	///��ȡ��һ��CAccount
	///@return	�õ��ĵ�һ��CAccount�����û�У��򷵻�NULL
	CAccount *getFirst(void);
	
	///��ȡ��һ��CAccount
	///@return	�õ���һ��CAccount�����û�У��򷵻�NULL
	CAccount *getNext(void);
	
	///������ȡCAccount
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CAccountActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CAccountActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CAccountCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CAccountCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�Ľ����˻���ָ��
	///@param	pFactory	�����Ӧ�Ľ����˻���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllTradingAccount(CTradingAccountFactory *pFactory);
	
	///Ѱ��CAccount
	///@param	AccountID	�ʽ��ʺ�
	///@return	�ҵ���CAccount������Ҳ���������NULL
	CAccount *findByAccountID( const CReadOnlyAccountIDType&  AccountID);



	friend class CAccountIteratorStartByParticipantID;

	///��ʼѰ��CAccount
	///@param	ParticipantID	��Ա���
	///@return	���������ĵ�һ��CAccount������Ҳ���������NULL
	CAccount *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CAccount��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CAccount *findNextStartByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipantID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pAccount	Ҫ�����Account
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CAccount *internalAdd(CWriteableAccount *pAccount, bool bNoTransaction);
	
	
	///ˢ�¸�CAccount�ļ�ֵ
	///@param	pAccount	��ˢ�µ�CAccount
	///@param	pNewAccount	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CAccount��ͬʱɾ��������
	///@param	pAccount	Ҫɾ����CAccount
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CAccount *pAccount, bool bNoTransaction);
/*
	///���ĳ��CAccount�Ƿ����ڱ����󹤳�
	///@param	pAccount	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CAccount *pAccount);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����AccountID������
	CAVLTree *pAccountIDIndex;
	///����ParticipantID������
	CAVLTree *pParticipantIDIndex;
	
	
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	
	///����ǰ����
	///@param	pAccount	Ҫ�����Account
	virtual void beforeAdd(CWriteableAccount *pAccount);
	
	///����󴥷�
	///@param	pAccount	�Ѿ������Account
	virtual void afterAdd(CAccount *pAccount);

	///����ǰ����	
	///@param	pAccount	��ˢ�µ�CAccount
	///@param	pNewAccount	�µ�ֵ
	virtual void beforeUpdate(CAccount *pAccount, CWriteableAccount *pNewAccount);
	
	///���º󴥷�
	///@param	pAccount	��ˢ�µ�CAccount
	virtual void afterUpdate(CAccount *pAccount);
	
	///ɾ��ǰ����
	///@param	pAccount	Ҫɾ����CAccount
	virtual void beforeRemove(CAccount *pAccount);
	
	///ȷ�ϼ���󴥷�
	///@param	pAccount	�Ѿ������Account
	virtual void commitAdd(CAccount *pAccount);

	///ȷ�ϸ��º󴥷�
	///@param	pAccount	��ˢ�µ�CAccount
	///@param	poldAccount	ԭ����ֵ
	virtual void commitUpdate(CAccount *pAccount, CWriteableAccount *pOldAccount);
	
	///ȷ��ɾ���󴥷�
	///@param	pAccount	�Ѿ�ɾ����CAccount
	virtual void commitRemove(CWriteableAccount *pAccount);

	///������صĴ�����
	vector<CAccountActionTrigger *> *pActionTriggers;
	vector<CAccountCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableAccount compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserCommFluxFactory��һ���û�ͨѶ���Ķ��󹤳�����������һ���û�ͨѶ����
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶ��û�ͨѶ������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByUserID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserCommFluxFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserCommFluxFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxUserCommFlux��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserCommFluxFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserCommFluxFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�UserCommFlux
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�UserCommFlux���ļ��������������ļ��еĶ���UserCommFluxCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�UserCommFlux
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�UserCommFlux���ļ��������������ļ��еĶ���UserCommFluxCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CUserCommFluxResource;

	///��һ��CUserCommFlux���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserCommFlux	Ҫ�����UserCommFlux
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserCommFlux *add(CWriteableUserCommFlux *pUserCommFlux, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CUserCommFlux��ֵ
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	///@param	pNewUserCommFlux	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pUserCommFlux	  ��Ҫ��ˢ�»���������CUserCommFlux,����NULL��ʾ����Ҫ������
	///@param	pNewUserCommFlux	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CUserCommFlux* addOrUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CUserCommFlux��ͬʱɾ��������
	///@param	pUserCommFlux	Ҫɾ����CUserCommFlux
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CUserCommFlux *pUserCommFlux, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CUserCommFlux
	///@param	pUserCommFlux	Ҫ��ȡ��CUserCommFlux
	///@param	pTragetUserCommFlux	��Ž����CUserCommFlux
	void retrieve(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pTargetUserCommFlux);
	
	///��ȡ��һ��CUserCommFlux
	///@return	�õ��ĵ�һ��CUserCommFlux�����û�У��򷵻�NULL
	CUserCommFlux *getFirst(void);
	
	///��ȡ��һ��CUserCommFlux
	///@return	�õ���һ��CUserCommFlux�����û�У��򷵻�NULL
	CUserCommFlux *getNext(void);
	
	///������ȡCUserCommFlux
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CUserCommFluxActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CUserCommFluxActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CUserCommFluxCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CUserCommFluxCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CUserCommFlux
	///@param	UserID	�û�����
	///@return	�ҵ���CUserCommFlux������Ҳ���������NULL
	CUserCommFlux *findByUserID( const CReadOnlyUserIDType&  UserID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CUserCommFlux���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserCommFlux	Ҫ�����UserCommFlux
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserCommFlux *internalAdd(CWriteableUserCommFlux *pUserCommFlux, bool bNoTransaction);
	
	
	///ˢ�¸�CUserCommFlux�ļ�ֵ
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	///@param	pNewUserCommFlux	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CUserCommFlux��ͬʱɾ��������
	///@param	pUserCommFlux	Ҫɾ����CUserCommFlux
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CUserCommFlux *pUserCommFlux, bool bNoTransaction);
/*
	///���ĳ��CUserCommFlux�Ƿ����ڱ����󹤳�
	///@param	pUserCommFlux	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CUserCommFlux *pUserCommFlux);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����UserID��hash����
	CHashIndex *pUserIDHashIndex;
	
	
	///����ǰ����
	///@param	pUserCommFlux	Ҫ�����UserCommFlux
	virtual void beforeAdd(CWriteableUserCommFlux *pUserCommFlux);
	
	///����󴥷�
	///@param	pUserCommFlux	�Ѿ������UserCommFlux
	virtual void afterAdd(CUserCommFlux *pUserCommFlux);

	///����ǰ����	
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	///@param	pNewUserCommFlux	�µ�ֵ
	virtual void beforeUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pNewUserCommFlux);
	
	///���º󴥷�
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	virtual void afterUpdate(CUserCommFlux *pUserCommFlux);
	
	///ɾ��ǰ����
	///@param	pUserCommFlux	Ҫɾ����CUserCommFlux
	virtual void beforeRemove(CUserCommFlux *pUserCommFlux);
	
	///ȷ�ϼ���󴥷�
	///@param	pUserCommFlux	�Ѿ������UserCommFlux
	virtual void commitAdd(CUserCommFlux *pUserCommFlux);

	///ȷ�ϸ��º󴥷�
	///@param	pUserCommFlux	��ˢ�µ�CUserCommFlux
	///@param	poldUserCommFlux	ԭ����ֵ
	virtual void commitUpdate(CUserCommFlux *pUserCommFlux, CWriteableUserCommFlux *pOldUserCommFlux);
	
	///ȷ��ɾ���󴥷�
	///@param	pUserCommFlux	�Ѿ�ɾ����CUserCommFlux
	virtual void commitRemove(CWriteableUserCommFlux *pUserCommFlux);

	///������صĴ�����
	vector<CUserCommFluxActionTrigger *> *pActionTriggers;
	vector<CUserCommFluxCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableUserCommFlux compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataLogFactory��һ��������ˮ�Ķ��󹤳�����������һ��������ˮ��
///ͬʱ�ֽ����������������Է����ѯ��
///	MarketDataLogNoIndex
///ʹ�ñ����󹤳���������ɶ�������ˮ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByMarketDataLogNo��findNextByMarketDataLogNo��endFindByMarketDataLogNo��ɲ�ѯ����
///		ʹ��findMaxMarketDataLogNo��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataLogFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataLogFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMarketDataLog��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataLogFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataLogFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MarketDataLog
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MarketDataLog���ļ��������������ļ��еĶ���MarketDataLogCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MarketDataLog
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MarketDataLog���ļ��������������ļ��еĶ���MarketDataLogCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMarketDataLogResource;

	///��һ��CMarketDataLog���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketDataLog	Ҫ�����MarketDataLog
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketDataLog *add(CWriteableMarketDataLog *pMarketDataLog, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMarketDataLog��ֵ
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	///@param	pNewMarketDataLog	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMarketDataLog	  ��Ҫ��ˢ�»���������CMarketDataLog,����NULL��ʾ����Ҫ������
	///@param	pNewMarketDataLog	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMarketDataLog* addOrUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMarketDataLog��ͬʱɾ��������
	///@param	pMarketDataLog	Ҫɾ����CMarketDataLog
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMarketDataLog *pMarketDataLog, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMarketDataLog
	///@param	pMarketDataLog	Ҫ��ȡ��CMarketDataLog
	///@param	pTragetMarketDataLog	��Ž����CMarketDataLog
	void retrieve(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pTargetMarketDataLog);
	
	///��ȡ��һ��CMarketDataLog
	///@return	�õ��ĵ�һ��CMarketDataLog�����û�У��򷵻�NULL
	CMarketDataLog *getFirst(void);
	
	///��ȡ��һ��CMarketDataLog
	///@return	�õ���һ��CMarketDataLog�����û�У��򷵻�NULL
	CMarketDataLog *getNext(void);
	
	///������ȡCMarketDataLog
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMarketDataLogActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMarketDataLogActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMarketDataLogCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMarketDataLogCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CMarketDataLogIteratorByMarketDataLogNo;

	///��ʼѰ��CMarketDataLog
	///@param	MarketDataLogNo	������ˮ���
	///@return	���������ĵ�һ��CMarketDataLog������Ҳ���������NULL
	CMarketDataLog *startFindByMarketDataLogNo( const CReadOnlySequenceNoType& MarketDataLogNo);

	///Ѱ����һ������������CMarketDataLog��������startFindByMarketDataLogNo�Ժ�endFindByMarketDataLogNo֮ǰ����
	///@return	��һ����������CMarketDataLog������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMarketDataLog *findNextByMarketDataLogNo(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByMarketDataLogNo(void);

	///Ѱ��CMarketDataLog
	///@return	�ҵ���CMarketDataLog������Ҳ���������NULL
	CMarketDataLog *findMaxMarketDataLogNo();



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMarketDataLog���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketDataLog	Ҫ�����MarketDataLog
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketDataLog *internalAdd(CWriteableMarketDataLog *pMarketDataLog, bool bNoTransaction);
	
	
	///ˢ�¸�CMarketDataLog�ļ�ֵ
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	///@param	pNewMarketDataLog	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMarketDataLog��ͬʱɾ��������
	///@param	pMarketDataLog	Ҫɾ����CMarketDataLog
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMarketDataLog *pMarketDataLog, bool bNoTransaction);
/*
	///���ĳ��CMarketDataLog�Ƿ����ڱ����󹤳�
	///@param	pMarketDataLog	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMarketDataLog *pMarketDataLog);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����MarketDataLogNo������
	CAVLTree *pMarketDataLogNoIndex;
	
	
	///����MarketDataLogNo����ʱ���洢�Ĳ�ѯ����
	CSequenceNoType queryMarketDataLogNoInSearchByMarketDataLogNo;
	
	///����MarketDataLogNo����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByMarketDataLogNo;
	
	///����ǰ����
	///@param	pMarketDataLog	Ҫ�����MarketDataLog
	virtual void beforeAdd(CWriteableMarketDataLog *pMarketDataLog);
	
	///����󴥷�
	///@param	pMarketDataLog	�Ѿ������MarketDataLog
	virtual void afterAdd(CMarketDataLog *pMarketDataLog);

	///����ǰ����	
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	///@param	pNewMarketDataLog	�µ�ֵ
	virtual void beforeUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pNewMarketDataLog);
	
	///���º󴥷�
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	virtual void afterUpdate(CMarketDataLog *pMarketDataLog);
	
	///ɾ��ǰ����
	///@param	pMarketDataLog	Ҫɾ����CMarketDataLog
	virtual void beforeRemove(CMarketDataLog *pMarketDataLog);
	
	///ȷ�ϼ���󴥷�
	///@param	pMarketDataLog	�Ѿ������MarketDataLog
	virtual void commitAdd(CMarketDataLog *pMarketDataLog);

	///ȷ�ϸ��º󴥷�
	///@param	pMarketDataLog	��ˢ�µ�CMarketDataLog
	///@param	poldMarketDataLog	ԭ����ֵ
	virtual void commitUpdate(CMarketDataLog *pMarketDataLog, CWriteableMarketDataLog *pOldMarketDataLog);
	
	///ȷ��ɾ���󴥷�
	///@param	pMarketDataLog	�Ѿ�ɾ����CMarketDataLog
	virtual void commitRemove(CWriteableMarketDataLog *pMarketDataLog);

	///������صĴ�����
	vector<CMarketDataLogActionTrigger *> *pActionTriggers;
	vector<CMarketDataLogCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMarketDataLog compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUserSessionFactory��һ������Ա���߻Ự�Ķ��󹤳�����������һ������Ա���߻Ự��
///ͬʱ�ֽ����������������Է����ѯ��
///	SessionIDIndex
///	UserIndex
///ʹ�ñ����󹤳���������ɶԽ���Ա���߻Ự����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findBySessionID��Ψһ�ҵ�����
///		ʹ��startFindByFrontID��findNextByFrontID��endFindByFrontID��ɲ�ѯ����
///		ʹ��findByUserID��Ψһ�ҵ�����
///		ʹ��startFindStartByUserID��findNextStartByUserID��endFindStartByUserID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUserSessionFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserSessionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxUserSession��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUserSessionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUserSessionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�UserSession
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�UserSession���ļ��������������ļ��еĶ���UserSessionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�UserSession
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�UserSession���ļ��������������ļ��еĶ���UserSessionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CUserSessionResource;

	///��һ��CUserSession���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserSession	Ҫ�����UserSession
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserSession *add(CWriteableUserSession *pUserSession, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CUserSession��ֵ
	///@param	pUserSession	��ˢ�µ�CUserSession
	///@param	pNewUserSession	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pUserSession	  ��Ҫ��ˢ�»���������CUserSession,����NULL��ʾ����Ҫ������
	///@param	pNewUserSession	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CUserSession* addOrUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CUserSession��ͬʱɾ��������
	///@param	pUserSession	Ҫɾ����CUserSession
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CUserSession *pUserSession, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CUserSession
	///@param	pUserSession	Ҫ��ȡ��CUserSession
	///@param	pTragetUserSession	��Ž����CUserSession
	void retrieve(CUserSession *pUserSession, CWriteableUserSession *pTargetUserSession);
	
	///��ȡ��һ��CUserSession
	///@return	�õ��ĵ�һ��CUserSession�����û�У��򷵻�NULL
	CUserSession *getFirst(void);
	
	///��ȡ��һ��CUserSession
	///@return	�õ���һ��CUserSession�����û�У��򷵻�NULL
	CUserSession *getNext(void);
	
	///������ȡCUserSession
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CUserSessionActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CUserSessionActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CUserSessionCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CUserSessionCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�Ľ���Ա��ָ��
	///@param	pFactory	�����Ӧ�Ľ���Ա��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllUser(CUserFactory *pFactory);
	
	///Ѱ��CUserSession
	///@param	SessionID	�Ự��
	///@param	FrontID	ǰ�ñ��
	///@return	�ҵ���CUserSession������Ҳ���������NULL
	CUserSession *findBySessionID( const CReadOnlySessionIDType&  SessionID,  const CReadOnlyFrontIDType&  FrontID);



	friend class CUserSessionIteratorByFrontID;

	///��ʼѰ��CUserSession
	///@param	FrontID	ǰ�ñ��
	///@return	���������ĵ�һ��CUserSession������Ҳ���������NULL
	CUserSession *startFindByFrontID( const CReadOnlyFrontIDType& FrontID);

	///Ѱ����һ������������CUserSession��������startFindByFrontID�Ժ�endFindByFrontID֮ǰ����
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CUserSession *findNextByFrontID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByFrontID(void);

	///Ѱ��CUserSession
	///@param	UserID	�û���
	///@return	�ҵ���CUserSession������Ҳ���������NULL
	CUserSession *findByUserID( const CReadOnlyUserIDType&  UserID);



	friend class CUserSessionIteratorStartByUserID;

	///��ʼѰ��CUserSession
	///@param	UserID	�û���
	///@return	���������ĵ�һ��CUserSession������Ҳ���������NULL
	CUserSession *startFindStartByUserID( const CReadOnlyUserIDType& UserID);

	///Ѱ����һ������������CUserSession��������startFindStartByUserID�Ժ�endFindStartByUserID֮ǰ����
	///@return	��һ����������CUserSession������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CUserSession *findNextStartByUserID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByUserID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CUserSession���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUserSession	Ҫ�����UserSession
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUserSession *internalAdd(CWriteableUserSession *pUserSession, bool bNoTransaction);
	
	
	///ˢ�¸�CUserSession�ļ�ֵ
	///@param	pUserSession	��ˢ�µ�CUserSession
	///@param	pNewUserSession	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CUserSession��ͬʱɾ��������
	///@param	pUserSession	Ҫɾ����CUserSession
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CUserSession *pUserSession, bool bNoTransaction);
/*
	///���ĳ��CUserSession�Ƿ����ڱ����󹤳�
	///@param	pUserSession	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CUserSession *pUserSession);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����FrontID+SessionID������
	CAVLTree *pSessionIDIndex;
	///����UserID������
	CAVLTree *pUserIndex;
	
	
	///����FrontID����ʱ���洢�Ĳ�ѯ����
	CFrontIDType queryFrontIDInSearchByFrontID;
	
	///����FrontID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByFrontID;
	///����UserID����ʱ���洢�Ĳ�ѯ����
	CUserIDType queryUserIDInSearchStartByUserID;
	
	///����UserID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByUserID;
	
	///����ǰ����
	///@param	pUserSession	Ҫ�����UserSession
	virtual void beforeAdd(CWriteableUserSession *pUserSession);
	
	///����󴥷�
	///@param	pUserSession	�Ѿ������UserSession
	virtual void afterAdd(CUserSession *pUserSession);

	///����ǰ����	
	///@param	pUserSession	��ˢ�µ�CUserSession
	///@param	pNewUserSession	�µ�ֵ
	virtual void beforeUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession);
	
	///���º󴥷�
	///@param	pUserSession	��ˢ�µ�CUserSession
	virtual void afterUpdate(CUserSession *pUserSession);
	
	///ɾ��ǰ����
	///@param	pUserSession	Ҫɾ����CUserSession
	virtual void beforeRemove(CUserSession *pUserSession);
	
	///ȷ�ϼ���󴥷�
	///@param	pUserSession	�Ѿ������UserSession
	virtual void commitAdd(CUserSession *pUserSession);

	///ȷ�ϸ��º󴥷�
	///@param	pUserSession	��ˢ�µ�CUserSession
	///@param	poldUserSession	ԭ����ֵ
	virtual void commitUpdate(CUserSession *pUserSession, CWriteableUserSession *pOldUserSession);
	
	///ȷ��ɾ���󴥷�
	///@param	pUserSession	�Ѿ�ɾ����CUserSession
	virtual void commitRemove(CWriteableUserSession *pUserSession);

	///������صĴ�����
	vector<CUserSessionActionTrigger *> *pActionTriggers;
	vector<CUserSessionCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableUserSession compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMDSessionFactory��һ�����鶩�������߻Ự�Ķ��󹤳�����������һ�����鶩�������߻Ự��
///ͬʱ�ֽ����������������Է����ѯ��
///	SessionIDIndex
///	UserIndex
///ʹ�ñ����󹤳���������ɶ����鶩�������߻Ự����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findBySessionID��Ψһ�ҵ�����
///		ʹ��findByUserID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMDSessionFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMDSessionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMDSession��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMDSessionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMDSessionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MDSession
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MDSession���ļ��������������ļ��еĶ���MDSessionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MDSession
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MDSession���ļ��������������ļ��еĶ���MDSessionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMDSessionResource;

	///��һ��CMDSession���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMDSession	Ҫ�����MDSession
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMDSession *add(CWriteableMDSession *pMDSession, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMDSession��ֵ
	///@param	pMDSession	��ˢ�µ�CMDSession
	///@param	pNewMDSession	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMDSession	  ��Ҫ��ˢ�»���������CMDSession,����NULL��ʾ����Ҫ������
	///@param	pNewMDSession	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMDSession* addOrUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMDSession��ͬʱɾ��������
	///@param	pMDSession	Ҫɾ����CMDSession
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMDSession *pMDSession, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMDSession
	///@param	pMDSession	Ҫ��ȡ��CMDSession
	///@param	pTragetMDSession	��Ž����CMDSession
	void retrieve(CMDSession *pMDSession, CWriteableMDSession *pTargetMDSession);
	
	///��ȡ��һ��CMDSession
	///@return	�õ��ĵ�һ��CMDSession�����û�У��򷵻�NULL
	CMDSession *getFirst(void);
	
	///��ȡ��һ��CMDSession
	///@return	�õ���һ��CMDSession�����û�У��򷵻�NULL
	CMDSession *getNext(void);
	
	///������ȡCMDSession
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMDSessionActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMDSessionActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMDSessionCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMDSessionCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CMDSession
	///@param	SessionID	�Ự��
	///@param	FrontID	ǰ�ñ��
	///@return	�ҵ���CMDSession������Ҳ���������NULL
	CMDSession *findBySessionID( const CReadOnlySessionIDType&  SessionID,  const CReadOnlyFrontIDType&  FrontID);



	///Ѱ��CMDSession
	///@param	UserID	�û���
	///@return	�ҵ���CMDSession������Ҳ���������NULL
	CMDSession *findByUserID( const CReadOnlyUserIDType&  UserID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMDSession���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMDSession	Ҫ�����MDSession
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMDSession *internalAdd(CWriteableMDSession *pMDSession, bool bNoTransaction);
	
	
	///ˢ�¸�CMDSession�ļ�ֵ
	///@param	pMDSession	��ˢ�µ�CMDSession
	///@param	pNewMDSession	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMDSession��ͬʱɾ��������
	///@param	pMDSession	Ҫɾ����CMDSession
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMDSession *pMDSession, bool bNoTransaction);
/*
	///���ĳ��CMDSession�Ƿ����ڱ����󹤳�
	///@param	pMDSession	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMDSession *pMDSession);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����SessionID+FrontID������
	CAVLTree *pSessionIDIndex;
	///����UserID������
	CAVLTree *pUserIndex;
	
	
	
	///����ǰ����
	///@param	pMDSession	Ҫ�����MDSession
	virtual void beforeAdd(CWriteableMDSession *pMDSession);
	
	///����󴥷�
	///@param	pMDSession	�Ѿ������MDSession
	virtual void afterAdd(CMDSession *pMDSession);

	///����ǰ����	
	///@param	pMDSession	��ˢ�µ�CMDSession
	///@param	pNewMDSession	�µ�ֵ
	virtual void beforeUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession);
	
	///���º󴥷�
	///@param	pMDSession	��ˢ�µ�CMDSession
	virtual void afterUpdate(CMDSession *pMDSession);
	
	///ɾ��ǰ����
	///@param	pMDSession	Ҫɾ����CMDSession
	virtual void beforeRemove(CMDSession *pMDSession);
	
	///ȷ�ϼ���󴥷�
	///@param	pMDSession	�Ѿ������MDSession
	virtual void commitAdd(CMDSession *pMDSession);

	///ȷ�ϸ��º󴥷�
	///@param	pMDSession	��ˢ�µ�CMDSession
	///@param	poldMDSession	ԭ����ֵ
	virtual void commitUpdate(CMDSession *pMDSession, CWriteableMDSession *pOldMDSession);
	
	///ȷ��ɾ���󴥷�
	///@param	pMDSession	�Ѿ�ɾ����CMDSession
	virtual void commitRemove(CWriteableMDSession *pMDSession);

	///������صĴ�����
	vector<CMDSessionActionTrigger *> *pActionTriggers;
	vector<CMDSessionCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMDSession compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CLoginInfoFactory��һ���û���½�ǳ���Ϣ�Ķ��󹤳�����������һ���û���½�ǳ���Ϣ��
///ͬʱ�ֽ����������������Է����ѯ��
///	PrimaryKeyIndex
///ʹ�ñ����󹤳���������ɶ��û���½�ǳ���Ϣ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPrimaryKey��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CLoginInfoFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CLoginInfoFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxLoginInfo��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CLoginInfoFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CLoginInfoFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�LoginInfo
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�LoginInfo���ļ��������������ļ��еĶ���LoginInfoCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�LoginInfo
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�LoginInfo���ļ��������������ļ��еĶ���LoginInfoCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CLoginInfoResource;

	///��һ��CLoginInfo���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pLoginInfo	Ҫ�����LoginInfo
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CLoginInfo *add(CWriteableLoginInfo *pLoginInfo, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CLoginInfo��ֵ
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	///@param	pNewLoginInfo	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pLoginInfo	  ��Ҫ��ˢ�»���������CLoginInfo,����NULL��ʾ����Ҫ������
	///@param	pNewLoginInfo	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CLoginInfo* addOrUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CLoginInfo��ͬʱɾ��������
	///@param	pLoginInfo	Ҫɾ����CLoginInfo
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CLoginInfo *pLoginInfo, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CLoginInfo
	///@param	pLoginInfo	Ҫ��ȡ��CLoginInfo
	///@param	pTragetLoginInfo	��Ž����CLoginInfo
	void retrieve(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pTargetLoginInfo);
	
	///��ȡ��һ��CLoginInfo
	///@return	�õ��ĵ�һ��CLoginInfo�����û�У��򷵻�NULL
	CLoginInfo *getFirst(void);
	
	///��ȡ��һ��CLoginInfo
	///@return	�õ���һ��CLoginInfo�����û�У��򷵻�NULL
	CLoginInfo *getNext(void);
	
	///������ȡCLoginInfo
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CLoginInfoActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CLoginInfoActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CLoginInfoCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CLoginInfoCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CLoginInfo
	///@param	TradingDay	������
	///@param	SequenceNo	���
	///@return	�ҵ���CLoginInfo������Ҳ���������NULL
	CLoginInfo *findByPrimaryKey( const CReadOnlyDateType&  TradingDay,  const CReadOnlySequenceNoType&  SequenceNo);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CLoginInfo���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pLoginInfo	Ҫ�����LoginInfo
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CLoginInfo *internalAdd(CWriteableLoginInfo *pLoginInfo, bool bNoTransaction);
	
	
	///ˢ�¸�CLoginInfo�ļ�ֵ
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	///@param	pNewLoginInfo	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CLoginInfo��ͬʱɾ��������
	///@param	pLoginInfo	Ҫɾ����CLoginInfo
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CLoginInfo *pLoginInfo, bool bNoTransaction);
/*
	///���ĳ��CLoginInfo�Ƿ����ڱ����󹤳�
	///@param	pLoginInfo	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CLoginInfo *pLoginInfo);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����TradingDay+SequenceNo������
	CAVLTree *pPrimaryKeyIndex;
	
	
	
	///����ǰ����
	///@param	pLoginInfo	Ҫ�����LoginInfo
	virtual void beforeAdd(CWriteableLoginInfo *pLoginInfo);
	
	///����󴥷�
	///@param	pLoginInfo	�Ѿ������LoginInfo
	virtual void afterAdd(CLoginInfo *pLoginInfo);

	///����ǰ����	
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	///@param	pNewLoginInfo	�µ�ֵ
	virtual void beforeUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pNewLoginInfo);
	
	///���º󴥷�
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	virtual void afterUpdate(CLoginInfo *pLoginInfo);
	
	///ɾ��ǰ����
	///@param	pLoginInfo	Ҫɾ����CLoginInfo
	virtual void beforeRemove(CLoginInfo *pLoginInfo);
	
	///ȷ�ϼ���󴥷�
	///@param	pLoginInfo	�Ѿ������LoginInfo
	virtual void commitAdd(CLoginInfo *pLoginInfo);

	///ȷ�ϸ��º󴥷�
	///@param	pLoginInfo	��ˢ�µ�CLoginInfo
	///@param	poldLoginInfo	ԭ����ֵ
	virtual void commitUpdate(CLoginInfo *pLoginInfo, CWriteableLoginInfo *pOldLoginInfo);
	
	///ȷ��ɾ���󴥷�
	///@param	pLoginInfo	�Ѿ�ɾ����CLoginInfo
	virtual void commitRemove(CWriteableLoginInfo *pLoginInfo);

	///������صĴ�����
	vector<CLoginInfoActionTrigger *> *pActionTriggers;
	vector<CLoginInfoCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableLoginInfo compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataDetailFactory��һ������г�������ϸ�Ķ��󹤳�����������һ������г�������ϸ��
///ͬʱ�ֽ����������������Է����ѯ��
///	PrimaryKeyIndex
///ʹ�ñ����󹤳���������ɶ�����г�������ϸ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPrimaryKey��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataDetailFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CDepthMarketDataDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxDepthMarketDataDetail��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CDepthMarketDataDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDepthMarketDataDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�DepthMarketDataDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�DepthMarketDataDetail���ļ��������������ļ��еĶ���DepthMarketDataDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�DepthMarketDataDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�DepthMarketDataDetail���ļ��������������ļ��еĶ���DepthMarketDataDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CDepthMarketDataDetailResource;

	///��һ��CDepthMarketDataDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pDepthMarketDataDetail	Ҫ�����DepthMarketDataDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CDepthMarketDataDetail *add(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CDepthMarketDataDetail��ֵ
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pDepthMarketDataDetail	  ��Ҫ��ˢ�»���������CDepthMarketDataDetail,����NULL��ʾ����Ҫ������
	///@param	pNewDepthMarketDataDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CDepthMarketDataDetail* addOrUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CDepthMarketDataDetail��ͬʱɾ��������
	///@param	pDepthMarketDataDetail	Ҫɾ����CDepthMarketDataDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CDepthMarketDataDetail *pDepthMarketDataDetail, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CDepthMarketDataDetail
	///@param	pDepthMarketDataDetail	Ҫ��ȡ��CDepthMarketDataDetail
	///@param	pTragetDepthMarketDataDetail	��Ž����CDepthMarketDataDetail
	void retrieve(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pTargetDepthMarketDataDetail);
	
	///��ȡ��һ��CDepthMarketDataDetail
	///@return	�õ��ĵ�һ��CDepthMarketDataDetail�����û�У��򷵻�NULL
	CDepthMarketDataDetail *getFirst(void);
	
	///��ȡ��һ��CDepthMarketDataDetail
	///@return	�õ���һ��CDepthMarketDataDetail�����û�У��򷵻�NULL
	CDepthMarketDataDetail *getNext(void);
	
	///������ȡCDepthMarketDataDetail
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CDepthMarketDataDetailActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CDepthMarketDataDetailActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CDepthMarketDataDetailCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CDepthMarketDataDetailCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CDepthMarketDataDetail
	///@param	TradingDay	������
	///@param	SettlementGroupID	���������
	///@param	SettlementID	������
	///@param	InstrumentID	��Լ����
	///@param	SequenceNo	���
	///@return	�ҵ���CDepthMarketDataDetail������Ҳ���������NULL
	CDepthMarketDataDetail *findByPrimaryKey( const CReadOnlyDateType&  TradingDay,  const CReadOnlySettlementGroupIDType&  SettlementGroupID,  const CReadOnlySettlementIDType&  SettlementID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlySequenceNoType&  SequenceNo);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CDepthMarketDataDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pDepthMarketDataDetail	Ҫ�����DepthMarketDataDetail
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CDepthMarketDataDetail *internalAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail, bool bNoTransaction);
	
	
	///ˢ�¸�CDepthMarketDataDetail�ļ�ֵ
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CDepthMarketDataDetail��ͬʱɾ��������
	///@param	pDepthMarketDataDetail	Ҫɾ����CDepthMarketDataDetail
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CDepthMarketDataDetail *pDepthMarketDataDetail, bool bNoTransaction);
/*
	///���ĳ��CDepthMarketDataDetail�Ƿ����ڱ����󹤳�
	///@param	pDepthMarketDataDetail	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CDepthMarketDataDetail *pDepthMarketDataDetail);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����TradingDay+SettlementGroupID+SettlementID+InstrumentID+SequenceNo������
	CAVLTree *pPrimaryKeyIndex;
	
	
	
	///����ǰ����
	///@param	pDepthMarketDataDetail	Ҫ�����DepthMarketDataDetail
	virtual void beforeAdd(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///����󴥷�
	///@param	pDepthMarketDataDetail	�Ѿ������DepthMarketDataDetail
	virtual void afterAdd(CDepthMarketDataDetail *pDepthMarketDataDetail);

	///����ǰ����	
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	///@param	pNewDepthMarketDataDetail	�µ�ֵ
	virtual void beforeUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pNewDepthMarketDataDetail);
	
	///���º󴥷�
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	virtual void afterUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///ɾ��ǰ����
	///@param	pDepthMarketDataDetail	Ҫɾ����CDepthMarketDataDetail
	virtual void beforeRemove(CDepthMarketDataDetail *pDepthMarketDataDetail);
	
	///ȷ�ϼ���󴥷�
	///@param	pDepthMarketDataDetail	�Ѿ������DepthMarketDataDetail
	virtual void commitAdd(CDepthMarketDataDetail *pDepthMarketDataDetail);

	///ȷ�ϸ��º󴥷�
	///@param	pDepthMarketDataDetail	��ˢ�µ�CDepthMarketDataDetail
	///@param	poldDepthMarketDataDetail	ԭ����ֵ
	virtual void commitUpdate(CDepthMarketDataDetail *pDepthMarketDataDetail, CWriteableDepthMarketDataDetail *pOldDepthMarketDataDetail);
	
	///ȷ��ɾ���󴥷�
	///@param	pDepthMarketDataDetail	�Ѿ�ɾ����CDepthMarketDataDetail
	virtual void commitRemove(CWriteableDepthMarketDataDetail *pDepthMarketDataDetail);

	///������صĴ�����
	vector<CDepthMarketDataDetailActionTrigger *> *pActionTriggers;
	vector<CDepthMarketDataDetailCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableDepthMarketDataDetail compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusDetailFactory��һ����Լ����״̬��ˮ�Ķ��󹤳�����������һ����Լ����״̬��ˮ��
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԺ�Լ����״̬��ˮ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusDetailFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInstrumentStatusDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxInstrumentStatusDetail��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInstrumentStatusDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentStatusDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�InstrumentStatusDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�InstrumentStatusDetail���ļ��������������ļ��еĶ���InstrumentStatusDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�InstrumentStatusDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�InstrumentStatusDetail���ļ��������������ļ��еĶ���InstrumentStatusDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CInstrumentStatusDetailResource;

	///��һ��CInstrumentStatusDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInstrumentStatusDetail	Ҫ�����InstrumentStatusDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInstrumentStatusDetail *add(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CInstrumentStatusDetail��ֵ
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pInstrumentStatusDetail	  ��Ҫ��ˢ�»���������CInstrumentStatusDetail,����NULL��ʾ����Ҫ������
	///@param	pNewInstrumentStatusDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CInstrumentStatusDetail* addOrUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CInstrumentStatusDetail��ͬʱɾ��������
	///@param	pInstrumentStatusDetail	Ҫɾ����CInstrumentStatusDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CInstrumentStatusDetail *pInstrumentStatusDetail, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CInstrumentStatusDetail
	///@param	pInstrumentStatusDetail	Ҫ��ȡ��CInstrumentStatusDetail
	///@param	pTragetInstrumentStatusDetail	��Ž����CInstrumentStatusDetail
	void retrieve(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pTargetInstrumentStatusDetail);
	
	///��ȡ��һ��CInstrumentStatusDetail
	///@return	�õ��ĵ�һ��CInstrumentStatusDetail�����û�У��򷵻�NULL
	CInstrumentStatusDetail *getFirst(void);
	
	///��ȡ��һ��CInstrumentStatusDetail
	///@return	�õ���һ��CInstrumentStatusDetail�����û�У��򷵻�NULL
	CInstrumentStatusDetail *getNext(void);
	
	///������ȡCInstrumentStatusDetail
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CInstrumentStatusDetailActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CInstrumentStatusDetailActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CInstrumentStatusDetailCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CInstrumentStatusDetailCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CInstrumentStatusDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInstrumentStatusDetail	Ҫ�����InstrumentStatusDetail
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInstrumentStatusDetail *internalAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail, bool bNoTransaction);
	
	
	///ˢ�¸�CInstrumentStatusDetail�ļ�ֵ
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CInstrumentStatusDetail��ͬʱɾ��������
	///@param	pInstrumentStatusDetail	Ҫɾ����CInstrumentStatusDetail
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CInstrumentStatusDetail *pInstrumentStatusDetail, bool bNoTransaction);
/*
	///���ĳ��CInstrumentStatusDetail�Ƿ����ڱ����󹤳�
	///@param	pInstrumentStatusDetail	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CInstrumentStatusDetail *pInstrumentStatusDetail);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	
	///����ǰ����
	///@param	pInstrumentStatusDetail	Ҫ�����InstrumentStatusDetail
	virtual void beforeAdd(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///����󴥷�
	///@param	pInstrumentStatusDetail	�Ѿ������InstrumentStatusDetail
	virtual void afterAdd(CInstrumentStatusDetail *pInstrumentStatusDetail);

	///����ǰ����	
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	///@param	pNewInstrumentStatusDetail	�µ�ֵ
	virtual void beforeUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pNewInstrumentStatusDetail);
	
	///���º󴥷�
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	virtual void afterUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///ɾ��ǰ����
	///@param	pInstrumentStatusDetail	Ҫɾ����CInstrumentStatusDetail
	virtual void beforeRemove(CInstrumentStatusDetail *pInstrumentStatusDetail);
	
	///ȷ�ϼ���󴥷�
	///@param	pInstrumentStatusDetail	�Ѿ������InstrumentStatusDetail
	virtual void commitAdd(CInstrumentStatusDetail *pInstrumentStatusDetail);

	///ȷ�ϸ��º󴥷�
	///@param	pInstrumentStatusDetail	��ˢ�µ�CInstrumentStatusDetail
	///@param	poldInstrumentStatusDetail	ԭ����ֵ
	virtual void commitUpdate(CInstrumentStatusDetail *pInstrumentStatusDetail, CWriteableInstrumentStatusDetail *pOldInstrumentStatusDetail);
	
	///ȷ��ɾ���󴥷�
	///@param	pInstrumentStatusDetail	�Ѿ�ɾ����CInstrumentStatusDetail
	virtual void commitRemove(CWriteableInstrumentStatusDetail *pInstrumentStatusDetail);

	///������صĴ�����
	vector<CInstrumentStatusDetailActionTrigger *> *pActionTriggers;
	vector<CInstrumentStatusDetailCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableInstrumentStatusDetail compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CFrontStatusFactory��һ��ǰ��״̬�Ķ��󹤳�����������һ��ǰ��״̬��
///ͬʱ�ֽ����������������Է����ѯ��
///	FrontIDIndex
///ʹ�ñ����󹤳���������ɶ�ǰ��״̬����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByFrontID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFrontStatusFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CFrontStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxFrontStatus��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CFrontStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CFrontStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�FrontStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�FrontStatus���ļ��������������ļ��еĶ���FrontStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�FrontStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�FrontStatus���ļ��������������ļ��еĶ���FrontStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CFrontStatusResource;

	///��һ��CFrontStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pFrontStatus	Ҫ�����FrontStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CFrontStatus *add(CWriteableFrontStatus *pFrontStatus, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CFrontStatus��ֵ
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	///@param	pNewFrontStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pFrontStatus	  ��Ҫ��ˢ�»���������CFrontStatus,����NULL��ʾ����Ҫ������
	///@param	pNewFrontStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CFrontStatus* addOrUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CFrontStatus��ͬʱɾ��������
	///@param	pFrontStatus	Ҫɾ����CFrontStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CFrontStatus *pFrontStatus, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CFrontStatus
	///@param	pFrontStatus	Ҫ��ȡ��CFrontStatus
	///@param	pTragetFrontStatus	��Ž����CFrontStatus
	void retrieve(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pTargetFrontStatus);
	
	///��ȡ��һ��CFrontStatus
	///@return	�õ��ĵ�һ��CFrontStatus�����û�У��򷵻�NULL
	CFrontStatus *getFirst(void);
	
	///��ȡ��һ��CFrontStatus
	///@return	�õ���һ��CFrontStatus�����û�У��򷵻�NULL
	CFrontStatus *getNext(void);
	
	///������ȡCFrontStatus
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CFrontStatusActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CFrontStatusActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CFrontStatusCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CFrontStatusCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CFrontStatus
	///@param	FrontID	ǰ�ñ��
	///@return	�ҵ���CFrontStatus������Ҳ���������NULL
	CFrontStatus *findByFrontID( const CReadOnlyFrontIDType&  FrontID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CFrontStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pFrontStatus	Ҫ�����FrontStatus
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CFrontStatus *internalAdd(CWriteableFrontStatus *pFrontStatus, bool bNoTransaction);
	
	
	///ˢ�¸�CFrontStatus�ļ�ֵ
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	///@param	pNewFrontStatus	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CFrontStatus��ͬʱɾ��������
	///@param	pFrontStatus	Ҫɾ����CFrontStatus
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CFrontStatus *pFrontStatus, bool bNoTransaction);
/*
	///���ĳ��CFrontStatus�Ƿ����ڱ����󹤳�
	///@param	pFrontStatus	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CFrontStatus *pFrontStatus);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����FrontID������
	CAVLTree *pFrontIDIndex;
	
	
	
	///����ǰ����
	///@param	pFrontStatus	Ҫ�����FrontStatus
	virtual void beforeAdd(CWriteableFrontStatus *pFrontStatus);
	
	///����󴥷�
	///@param	pFrontStatus	�Ѿ������FrontStatus
	virtual void afterAdd(CFrontStatus *pFrontStatus);

	///����ǰ����	
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	///@param	pNewFrontStatus	�µ�ֵ
	virtual void beforeUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pNewFrontStatus);
	
	///���º󴥷�
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	virtual void afterUpdate(CFrontStatus *pFrontStatus);
	
	///ɾ��ǰ����
	///@param	pFrontStatus	Ҫɾ����CFrontStatus
	virtual void beforeRemove(CFrontStatus *pFrontStatus);
	
	///ȷ�ϼ���󴥷�
	///@param	pFrontStatus	�Ѿ������FrontStatus
	virtual void commitAdd(CFrontStatus *pFrontStatus);

	///ȷ�ϸ��º󴥷�
	///@param	pFrontStatus	��ˢ�µ�CFrontStatus
	///@param	poldFrontStatus	ԭ����ֵ
	virtual void commitUpdate(CFrontStatus *pFrontStatus, CWriteableFrontStatus *pOldFrontStatus);
	
	///ȷ��ɾ���󴥷�
	///@param	pFrontStatus	�Ѿ�ɾ����CFrontStatus
	virtual void commitRemove(CWriteableFrontStatus *pFrontStatus);

	///������صĴ�����
	vector<CFrontStatusActionTrigger *> *pActionTriggers;
	vector<CFrontStatusCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableFrontStatus compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMaxLocalIDFactory��һ����󱾵ر����ŵĶ��󹤳�����������һ����󱾵ر����ţ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶ���󱾵ر����ŵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByUserID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMaxLocalIDFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMaxLocalID��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMaxLocalIDFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMaxLocalIDFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MaxLocalID
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MaxLocalID���ļ��������������ļ��еĶ���MaxLocalIDCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MaxLocalID
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MaxLocalID���ļ��������������ļ��еĶ���MaxLocalIDCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMaxLocalIDResource;

	///��һ��CMaxLocalID���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMaxLocalID	Ҫ�����MaxLocalID
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMaxLocalID *add(CWriteableMaxLocalID *pMaxLocalID, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMaxLocalID��ֵ
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	///@param	pNewMaxLocalID	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMaxLocalID	  ��Ҫ��ˢ�»���������CMaxLocalID,����NULL��ʾ����Ҫ������
	///@param	pNewMaxLocalID	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMaxLocalID* addOrUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMaxLocalID��ͬʱɾ��������
	///@param	pMaxLocalID	Ҫɾ����CMaxLocalID
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMaxLocalID *pMaxLocalID, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMaxLocalID
	///@param	pMaxLocalID	Ҫ��ȡ��CMaxLocalID
	///@param	pTragetMaxLocalID	��Ž����CMaxLocalID
	void retrieve(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pTargetMaxLocalID);
	
	///��ȡ��һ��CMaxLocalID
	///@return	�õ��ĵ�һ��CMaxLocalID�����û�У��򷵻�NULL
	CMaxLocalID *getFirst(void);
	
	///��ȡ��һ��CMaxLocalID
	///@return	�õ���һ��CMaxLocalID�����û�У��򷵻�NULL
	CMaxLocalID *getNext(void);
	
	///������ȡCMaxLocalID
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMaxLocalIDActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMaxLocalIDActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMaxLocalIDCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMaxLocalIDCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CMaxLocalID
	///@param	UserID	�û����
	///@return	�ҵ���CMaxLocalID������Ҳ���������NULL
	CMaxLocalID *findByUserID( const CReadOnlyUserIDType&  UserID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMaxLocalID���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMaxLocalID	Ҫ�����MaxLocalID
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMaxLocalID *internalAdd(CWriteableMaxLocalID *pMaxLocalID, bool bNoTransaction);
	
	
	///ˢ�¸�CMaxLocalID�ļ�ֵ
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	///@param	pNewMaxLocalID	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMaxLocalID��ͬʱɾ��������
	///@param	pMaxLocalID	Ҫɾ����CMaxLocalID
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMaxLocalID *pMaxLocalID, bool bNoTransaction);
/*
	///���ĳ��CMaxLocalID�Ƿ����ڱ����󹤳�
	///@param	pMaxLocalID	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMaxLocalID *pMaxLocalID);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����UserID��hash����
	CHashIndex *pUserIDHashIndex;
	
	
	///����ǰ����
	///@param	pMaxLocalID	Ҫ�����MaxLocalID
	virtual void beforeAdd(CWriteableMaxLocalID *pMaxLocalID);
	
	///����󴥷�
	///@param	pMaxLocalID	�Ѿ������MaxLocalID
	virtual void afterAdd(CMaxLocalID *pMaxLocalID);

	///����ǰ����	
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	///@param	pNewMaxLocalID	�µ�ֵ
	virtual void beforeUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID);
	
	///���º󴥷�
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	virtual void afterUpdate(CMaxLocalID *pMaxLocalID);
	
	///ɾ��ǰ����
	///@param	pMaxLocalID	Ҫɾ����CMaxLocalID
	virtual void beforeRemove(CMaxLocalID *pMaxLocalID);
	
	///ȷ�ϼ���󴥷�
	///@param	pMaxLocalID	�Ѿ������MaxLocalID
	virtual void commitAdd(CMaxLocalID *pMaxLocalID);

	///ȷ�ϸ��º󴥷�
	///@param	pMaxLocalID	��ˢ�µ�CMaxLocalID
	///@param	poldMaxLocalID	ԭ����ֵ
	virtual void commitUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pOldMaxLocalID);
	
	///ȷ��ɾ���󴥷�
	///@param	pMaxLocalID	�Ѿ�ɾ����CMaxLocalID
	virtual void commitRemove(CWriteableMaxLocalID *pMaxLocalID);

	///������صĴ�����
	vector<CMaxLocalIDActionTrigger *> *pActionTriggers;
	vector<CMaxLocalIDCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMaxLocalID compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CBulletinFactory��һ��������Ϣ�Ķ��󹤳�����������һ��������Ϣ��
///ͬʱ�ֽ����������������Է����ѯ��
///	BulletinIDIndex
///ʹ�ñ����󹤳���������ɶԹ�����Ϣ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByBulletinID��Ψһ�ҵ�����
///		ʹ��startFindStartByBulletinID��findNextStartByBulletinID��endFindStartByBulletinID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBulletinFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CBulletinFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxBulletin��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CBulletinFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBulletinFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Bulletin
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Bulletin���ļ��������������ļ��еĶ���BulletinCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Bulletin
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Bulletin���ļ��������������ļ��еĶ���BulletinCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CBulletinResource;

	///��һ��CBulletin���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pBulletin	Ҫ�����Bulletin
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CBulletin *add(CWriteableBulletin *pBulletin, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CBulletin��ֵ
	///@param	pBulletin	��ˢ�µ�CBulletin
	///@param	pNewBulletin	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pBulletin	  ��Ҫ��ˢ�»���������CBulletin,����NULL��ʾ����Ҫ������
	///@param	pNewBulletin	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CBulletin* addOrUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CBulletin��ͬʱɾ��������
	///@param	pBulletin	Ҫɾ����CBulletin
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CBulletin *pBulletin, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CBulletin
	///@param	pBulletin	Ҫ��ȡ��CBulletin
	///@param	pTragetBulletin	��Ž����CBulletin
	void retrieve(CBulletin *pBulletin, CWriteableBulletin *pTargetBulletin);
	
	///��ȡ��һ��CBulletin
	///@return	�õ��ĵ�һ��CBulletin�����û�У��򷵻�NULL
	CBulletin *getFirst(void);
	
	///��ȡ��һ��CBulletin
	///@return	�õ���һ��CBulletin�����û�У��򷵻�NULL
	CBulletin *getNext(void);
	
	///������ȡCBulletin
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CBulletinActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CBulletinActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CBulletinCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CBulletinCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CBulletin
	///@param	BulletinID	������
	///@param	TradingDay	������
	///@param	MarketID	������
	///@return	�ҵ���CBulletin������Ҳ���������NULL
	CBulletin *findByBulletinID( const CReadOnlyBulletinIDType&  BulletinID,  const CReadOnlyDateType&  TradingDay,  const CReadOnlyMarketIDType&  MarketID);



	friend class CBulletinIteratorStartByBulletinID;

	///��ʼѰ��CBulletin
	///@param	BulletinID	������
	///@return	���������ĵ�һ��CBulletin������Ҳ���������NULL
	CBulletin *startFindStartByBulletinID( const CReadOnlyBulletinIDType& BulletinID);

	///Ѱ����һ������������CBulletin��������startFindStartByBulletinID�Ժ�endFindStartByBulletinID֮ǰ����
	///@return	��һ����������CBulletin������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CBulletin *findNextStartByBulletinID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByBulletinID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CBulletin���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pBulletin	Ҫ�����Bulletin
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CBulletin *internalAdd(CWriteableBulletin *pBulletin, bool bNoTransaction);
	
	
	///ˢ�¸�CBulletin�ļ�ֵ
	///@param	pBulletin	��ˢ�µ�CBulletin
	///@param	pNewBulletin	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CBulletin��ͬʱɾ��������
	///@param	pBulletin	Ҫɾ����CBulletin
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CBulletin *pBulletin, bool bNoTransaction);
/*
	///���ĳ��CBulletin�Ƿ����ڱ����󹤳�
	///@param	pBulletin	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CBulletin *pBulletin);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����BulletinID+TradingDay+MarketID������
	CAVLTree *pBulletinIDIndex;
	
	
	///����BulletinID����ʱ���洢�Ĳ�ѯ����
	CBulletinIDType queryBulletinIDInSearchStartByBulletinID;
	
	///����BulletinID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByBulletinID;
	
	///����ǰ����
	///@param	pBulletin	Ҫ�����Bulletin
	virtual void beforeAdd(CWriteableBulletin *pBulletin);
	
	///����󴥷�
	///@param	pBulletin	�Ѿ������Bulletin
	virtual void afterAdd(CBulletin *pBulletin);

	///����ǰ����	
	///@param	pBulletin	��ˢ�µ�CBulletin
	///@param	pNewBulletin	�µ�ֵ
	virtual void beforeUpdate(CBulletin *pBulletin, CWriteableBulletin *pNewBulletin);
	
	///���º󴥷�
	///@param	pBulletin	��ˢ�µ�CBulletin
	virtual void afterUpdate(CBulletin *pBulletin);
	
	///ɾ��ǰ����
	///@param	pBulletin	Ҫɾ����CBulletin
	virtual void beforeRemove(CBulletin *pBulletin);
	
	///ȷ�ϼ���󴥷�
	///@param	pBulletin	�Ѿ������Bulletin
	virtual void commitAdd(CBulletin *pBulletin);

	///ȷ�ϸ��º󴥷�
	///@param	pBulletin	��ˢ�µ�CBulletin
	///@param	poldBulletin	ԭ����ֵ
	virtual void commitUpdate(CBulletin *pBulletin, CWriteableBulletin *pOldBulletin);
	
	///ȷ��ɾ���󴥷�
	///@param	pBulletin	�Ѿ�ɾ����CBulletin
	virtual void commitRemove(CWriteableBulletin *pBulletin);

	///������صĴ�����
	vector<CBulletinActionTrigger *> *pActionTriggers;
	vector<CBulletinCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableBulletin compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataModifyFactory��һ������䶯�Ķ��󹤳�����������һ������䶯��
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶ�����䶯����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataModifyFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataModifyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMarketDataModify��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataModifyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataModifyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MarketDataModify
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MarketDataModify���ļ��������������ļ��еĶ���MarketDataModifyCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MarketDataModify
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MarketDataModify���ļ��������������ļ��еĶ���MarketDataModifyCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMarketDataModifyResource;

	///��һ��CMarketDataModify���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketDataModify	Ҫ�����MarketDataModify
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketDataModify *add(CWriteableMarketDataModify *pMarketDataModify, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMarketDataModify��ֵ
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	///@param	pNewMarketDataModify	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMarketDataModify	  ��Ҫ��ˢ�»���������CMarketDataModify,����NULL��ʾ����Ҫ������
	///@param	pNewMarketDataModify	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMarketDataModify* addOrUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMarketDataModify��ͬʱɾ��������
	///@param	pMarketDataModify	Ҫɾ����CMarketDataModify
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMarketDataModify *pMarketDataModify, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMarketDataModify
	///@param	pMarketDataModify	Ҫ��ȡ��CMarketDataModify
	///@param	pTragetMarketDataModify	��Ž����CMarketDataModify
	void retrieve(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pTargetMarketDataModify);
	
	///��ȡ��һ��CMarketDataModify
	///@return	�õ��ĵ�һ��CMarketDataModify�����û�У��򷵻�NULL
	CMarketDataModify *getFirst(void);
	
	///��ȡ��һ��CMarketDataModify
	///@return	�õ���һ��CMarketDataModify�����û�У��򷵻�NULL
	CMarketDataModify *getNext(void);
	
	///������ȡCMarketDataModify
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMarketDataModifyActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMarketDataModifyActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMarketDataModifyCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMarketDataModifyCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ����������ָ��
	///@param	pFactory	�����Ӧ����������ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllDepthMarketData(CDepthMarketDataFactory *pFactory);
	
	friend class CMarketDataModifyIteratorBySettlementGroupID;

	///��ʼѰ��CMarketDataModify
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CMarketDataModify������Ҳ���������NULL
	CMarketDataModify *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CMarketDataModify��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CMarketDataModify������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMarketDataModify *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CMarketDataModify
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CMarketDataModify������Ҳ���������NULL
	CMarketDataModify *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMarketDataModify���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketDataModify	Ҫ�����MarketDataModify
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketDataModify *internalAdd(CWriteableMarketDataModify *pMarketDataModify, bool bNoTransaction);
	
	
	///ˢ�¸�CMarketDataModify�ļ�ֵ
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	///@param	pNewMarketDataModify	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMarketDataModify��ͬʱɾ��������
	///@param	pMarketDataModify	Ҫɾ����CMarketDataModify
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMarketDataModify *pMarketDataModify, bool bNoTransaction);
/*
	///���ĳ��CMarketDataModify�Ƿ����ڱ����󹤳�
	///@param	pMarketDataModify	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMarketDataModify *pMarketDataModify);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CMarketDataModify *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pMarketDataModify	Ҫ�����MarketDataModify
	virtual void beforeAdd(CWriteableMarketDataModify *pMarketDataModify);
	
	///����󴥷�
	///@param	pMarketDataModify	�Ѿ������MarketDataModify
	virtual void afterAdd(CMarketDataModify *pMarketDataModify);

	///����ǰ����	
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	///@param	pNewMarketDataModify	�µ�ֵ
	virtual void beforeUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pNewMarketDataModify);
	
	///���º󴥷�
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	virtual void afterUpdate(CMarketDataModify *pMarketDataModify);
	
	///ɾ��ǰ����
	///@param	pMarketDataModify	Ҫɾ����CMarketDataModify
	virtual void beforeRemove(CMarketDataModify *pMarketDataModify);
	
	///ȷ�ϼ���󴥷�
	///@param	pMarketDataModify	�Ѿ������MarketDataModify
	virtual void commitAdd(CMarketDataModify *pMarketDataModify);

	///ȷ�ϸ��º󴥷�
	///@param	pMarketDataModify	��ˢ�µ�CMarketDataModify
	///@param	poldMarketDataModify	ԭ����ֵ
	virtual void commitUpdate(CMarketDataModify *pMarketDataModify, CWriteableMarketDataModify *pOldMarketDataModify);
	
	///ȷ��ɾ���󴥷�
	///@param	pMarketDataModify	�Ѿ�ɾ����CMarketDataModify
	virtual void commitRemove(CWriteableMarketDataModify *pMarketDataModify);

	///������صĴ�����
	vector<CMarketDataModifyActionTrigger *> *pActionTriggers;
	vector<CMarketDataModifyCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMarketDataModify compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CDepthMarketDataFactory��һ���������Ķ��󹤳�����������һ��������飬
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶ�����������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CDepthMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxDepthMarketData��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CDepthMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CDepthMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�DepthMarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�DepthMarketData���ļ��������������ļ��еĶ���DepthMarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�DepthMarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�DepthMarketData���ļ��������������ļ��еĶ���DepthMarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CDepthMarketDataResource;

	///��һ��CDepthMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pDepthMarketData	Ҫ�����DepthMarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CDepthMarketData *add(CWriteableDepthMarketData *pDepthMarketData, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CDepthMarketData��ֵ
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	///@param	pNewDepthMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pDepthMarketData	  ��Ҫ��ˢ�»���������CDepthMarketData,����NULL��ʾ����Ҫ������
	///@param	pNewDepthMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CDepthMarketData* addOrUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CDepthMarketData��ͬʱɾ��������
	///@param	pDepthMarketData	Ҫɾ����CDepthMarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CDepthMarketData *pDepthMarketData, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CDepthMarketData
	///@param	pDepthMarketData	Ҫ��ȡ��CDepthMarketData
	///@param	pTragetDepthMarketData	��Ž����CDepthMarketData
	void retrieve(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pTargetDepthMarketData);
	
	///��ȡ��һ��CDepthMarketData
	///@return	�õ��ĵ�һ��CDepthMarketData�����û�У��򷵻�NULL
	CDepthMarketData *getFirst(void);
	
	///��ȡ��һ��CDepthMarketData
	///@return	�õ���һ��CDepthMarketData�����û�У��򷵻�NULL
	CDepthMarketData *getNext(void);
	
	///������ȡCDepthMarketData
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CDepthMarketDataActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CDepthMarketDataActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CDepthMarketDataCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CDepthMarketDataCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	friend class CDepthMarketDataIteratorBySettlementGroupID;

	///��ʼѰ��CDepthMarketData
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CDepthMarketData������Ҳ���������NULL
	CDepthMarketData *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CDepthMarketData��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CDepthMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CDepthMarketData *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CDepthMarketData
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CDepthMarketData������Ҳ���������NULL
	CDepthMarketData *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CDepthMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pDepthMarketData	Ҫ�����DepthMarketData
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CDepthMarketData *internalAdd(CWriteableDepthMarketData *pDepthMarketData, bool bNoTransaction);
	
	
	///ˢ�¸�CDepthMarketData�ļ�ֵ
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	///@param	pNewDepthMarketData	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CDepthMarketData��ͬʱɾ��������
	///@param	pDepthMarketData	Ҫɾ����CDepthMarketData
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CDepthMarketData *pDepthMarketData, bool bNoTransaction);
/*
	///���ĳ��CDepthMarketData�Ƿ����ڱ����󹤳�
	///@param	pDepthMarketData	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CDepthMarketData *pDepthMarketData);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CDepthMarketData *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pDepthMarketData	Ҫ�����DepthMarketData
	virtual void beforeAdd(CWriteableDepthMarketData *pDepthMarketData);
	
	///����󴥷�
	///@param	pDepthMarketData	�Ѿ������DepthMarketData
	virtual void afterAdd(CDepthMarketData *pDepthMarketData);

	///����ǰ����	
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	///@param	pNewDepthMarketData	�µ�ֵ
	virtual void beforeUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData);
	
	///���º󴥷�
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	virtual void afterUpdate(CDepthMarketData *pDepthMarketData);
	
	///ɾ��ǰ����
	///@param	pDepthMarketData	Ҫɾ����CDepthMarketData
	virtual void beforeRemove(CDepthMarketData *pDepthMarketData);
	
	///ȷ�ϼ���󴥷�
	///@param	pDepthMarketData	�Ѿ������DepthMarketData
	virtual void commitAdd(CDepthMarketData *pDepthMarketData);

	///ȷ�ϸ��º󴥷�
	///@param	pDepthMarketData	��ˢ�µ�CDepthMarketData
	///@param	poldDepthMarketData	ԭ����ֵ
	virtual void commitUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pOldDepthMarketData);
	
	///ȷ��ɾ���󴥷�
	///@param	pDepthMarketData	�Ѿ�ɾ����CDepthMarketData
	virtual void commitRemove(CWriteableDepthMarketData *pDepthMarketData);

	///������صĴ�����
	vector<CDepthMarketDataActionTrigger *> *pActionTriggers;
	vector<CDepthMarketDataCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableDepthMarketData compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataFactory��һ������������Ķ��󹤳�����������һ�����������飬
///ͬʱ�ֽ����������������Է����ѯ��
///	TopicAndInstrumentIndex
///	InstrumentIndex
///ʹ�ñ����󹤳���������ɶԷ������������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByTopicAndInstrument��Ψһ�ҵ�����
///		ʹ��startFindByTopicID��findNextByTopicID��endFindByTopicID��ɲ�ѯ����
///		ʹ��startFindByInstrumentID��findNextByInstrumentID��endFindByInstrumentID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTopicMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxTopicMarketData��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTopicMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�TopicMarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�TopicMarketData���ļ��������������ļ��еĶ���TopicMarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�TopicMarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�TopicMarketData���ļ��������������ļ��еĶ���TopicMarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CTopicMarketDataResource;

	///��һ��CTopicMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTopicMarketData	Ҫ�����TopicMarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTopicMarketData *add(CWriteableTopicMarketData *pTopicMarketData, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CTopicMarketData��ֵ
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	///@param	pNewTopicMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pTopicMarketData	  ��Ҫ��ˢ�»���������CTopicMarketData,����NULL��ʾ����Ҫ������
	///@param	pNewTopicMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CTopicMarketData* addOrUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CTopicMarketData��ͬʱɾ��������
	///@param	pTopicMarketData	Ҫɾ����CTopicMarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CTopicMarketData *pTopicMarketData, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CTopicMarketData
	///@param	pTopicMarketData	Ҫ��ȡ��CTopicMarketData
	///@param	pTragetTopicMarketData	��Ž����CTopicMarketData
	void retrieve(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pTargetTopicMarketData);
	
	///��ȡ��һ��CTopicMarketData
	///@return	�õ��ĵ�һ��CTopicMarketData�����û�У��򷵻�NULL
	CTopicMarketData *getFirst(void);
	
	///��ȡ��һ��CTopicMarketData
	///@return	�õ���һ��CTopicMarketData�����û�У��򷵻�NULL
	CTopicMarketData *getNext(void);
	
	///������ȡCTopicMarketData
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CTopicMarketDataActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CTopicMarketDataActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CTopicMarketDataCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CTopicMarketDataCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CTopicMarketData
	///@param	TopicID	�������
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CTopicMarketData������Ҳ���������NULL
	CTopicMarketData *findByTopicAndInstrument( const CReadOnlyTopicIDType&  TopicID,  const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CTopicMarketDataIteratorByTopicID;

	///��ʼѰ��CTopicMarketData
	///@param	TopicID	�������
	///@return	���������ĵ�һ��CTopicMarketData������Ҳ���������NULL
	CTopicMarketData *startFindByTopicID( const CReadOnlyTopicIDType& TopicID);

	///Ѱ����һ������������CTopicMarketData��������startFindByTopicID�Ժ�endFindByTopicID֮ǰ����
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTopicMarketData *findNextByTopicID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByTopicID(void);

	friend class CTopicMarketDataIteratorByInstrumentID;

	///��ʼѰ��CTopicMarketData
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CTopicMarketData������Ҳ���������NULL
	CTopicMarketData *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CTopicMarketData��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTopicMarketData *findNextByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByInstrumentID(void);

	friend class CTopicMarketDataIteratorBySettlementGroupID;

	///��ʼѰ��CTopicMarketData
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CTopicMarketData������Ҳ���������NULL
	CTopicMarketData *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CTopicMarketData��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CTopicMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTopicMarketData *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CTopicMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTopicMarketData	Ҫ�����TopicMarketData
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTopicMarketData *internalAdd(CWriteableTopicMarketData *pTopicMarketData, bool bNoTransaction);
	
	
	///ˢ�¸�CTopicMarketData�ļ�ֵ
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	///@param	pNewTopicMarketData	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CTopicMarketData��ͬʱɾ��������
	///@param	pTopicMarketData	Ҫɾ����CTopicMarketData
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CTopicMarketData *pTopicMarketData, bool bNoTransaction);
/*
	///���ĳ��CTopicMarketData�Ƿ����ڱ����󹤳�
	///@param	pTopicMarketData	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CTopicMarketData *pTopicMarketData);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����TopicID+InstrumentID������
	CAVLTree *pTopicAndInstrumentIndex;
	///����InstrumentID������
	CAVLTree *pInstrumentIndex;
	
	
	///����TopicID����ʱ���洢�Ĳ�ѯ����
	CTopicIDType queryTopicIDInSearchByTopicID;
	
	///����TopicID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByTopicID;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByInstrumentID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CTopicMarketData *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pTopicMarketData	Ҫ�����TopicMarketData
	virtual void beforeAdd(CWriteableTopicMarketData *pTopicMarketData);
	
	///����󴥷�
	///@param	pTopicMarketData	�Ѿ������TopicMarketData
	virtual void afterAdd(CTopicMarketData *pTopicMarketData);

	///����ǰ����	
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	///@param	pNewTopicMarketData	�µ�ֵ
	virtual void beforeUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pNewTopicMarketData);
	
	///���º󴥷�
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	virtual void afterUpdate(CTopicMarketData *pTopicMarketData);
	
	///ɾ��ǰ����
	///@param	pTopicMarketData	Ҫɾ����CTopicMarketData
	virtual void beforeRemove(CTopicMarketData *pTopicMarketData);
	
	///ȷ�ϼ���󴥷�
	///@param	pTopicMarketData	�Ѿ������TopicMarketData
	virtual void commitAdd(CTopicMarketData *pTopicMarketData);

	///ȷ�ϸ��º󴥷�
	///@param	pTopicMarketData	��ˢ�µ�CTopicMarketData
	///@param	poldTopicMarketData	ԭ����ֵ
	virtual void commitUpdate(CTopicMarketData *pTopicMarketData, CWriteableTopicMarketData *pOldTopicMarketData);
	
	///ȷ��ɾ���󴥷�
	///@param	pTopicMarketData	�Ѿ�ɾ����CTopicMarketData
	virtual void commitRemove(CWriteableTopicMarketData *pTopicMarketData);

	///������صĴ�����
	vector<CTopicMarketDataActionTrigger *> *pActionTriggers;
	vector<CTopicMarketDataCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableTopicMarketData compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTopicMarketDataVersionFactory��һ��������������յĶ��󹤳�����������һ��������������գ�
///ͬʱ�ֽ����������������Է����ѯ��
///	TopicAndVersion
///ʹ�ñ����󹤳���������ɶԷ�����������յ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByTopicAndVersion��findNextByTopicAndVersion��endFindByTopicAndVersion��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTopicMarketDataVersionFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTopicMarketDataVersionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxTopicMarketDataVersion��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTopicMarketDataVersionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTopicMarketDataVersionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�TopicMarketDataVersion
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�TopicMarketDataVersion���ļ��������������ļ��еĶ���TopicMarketDataVersionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�TopicMarketDataVersion
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�TopicMarketDataVersion���ļ��������������ļ��еĶ���TopicMarketDataVersionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CTopicMarketDataVersionResource;

	///��һ��CTopicMarketDataVersion���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTopicMarketDataVersion	Ҫ�����TopicMarketDataVersion
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTopicMarketDataVersion *add(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CTopicMarketDataVersion��ֵ
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pTopicMarketDataVersion	  ��Ҫ��ˢ�»���������CTopicMarketDataVersion,����NULL��ʾ����Ҫ������
	///@param	pNewTopicMarketDataVersion	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CTopicMarketDataVersion* addOrUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CTopicMarketDataVersion��ͬʱɾ��������
	///@param	pTopicMarketDataVersion	Ҫɾ����CTopicMarketDataVersion
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CTopicMarketDataVersion *pTopicMarketDataVersion, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CTopicMarketDataVersion
	///@param	pTopicMarketDataVersion	Ҫ��ȡ��CTopicMarketDataVersion
	///@param	pTragetTopicMarketDataVersion	��Ž����CTopicMarketDataVersion
	void retrieve(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pTargetTopicMarketDataVersion);
	
	///��ȡ��һ��CTopicMarketDataVersion
	///@return	�õ��ĵ�һ��CTopicMarketDataVersion�����û�У��򷵻�NULL
	CTopicMarketDataVersion *getFirst(void);
	
	///��ȡ��һ��CTopicMarketDataVersion
	///@return	�õ���һ��CTopicMarketDataVersion�����û�У��򷵻�NULL
	CTopicMarketDataVersion *getNext(void);
	
	///������ȡCTopicMarketDataVersion
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CTopicMarketDataVersionActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CTopicMarketDataVersionActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CTopicMarketDataVersionCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CTopicMarketDataVersionCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CTopicMarketDataVersionIteratorByTopicAndVersion;

	///��ʼѰ��CTopicMarketDataVersion
	///@param	TopicID	�������
	///@param	Version	���հ汾
	///@return	���������ĵ�һ��CTopicMarketDataVersion������Ҳ���������NULL
	CTopicMarketDataVersion *startFindByTopicAndVersion( const CReadOnlyTopicIDType& TopicID,  const CReadOnlySequenceNoType& Version);

	///Ѱ����һ������������CTopicMarketDataVersion��������startFindByTopicAndVersion�Ժ�endFindByTopicAndVersion֮ǰ����
	///@return	��һ����������CTopicMarketDataVersion������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTopicMarketDataVersion *findNextByTopicAndVersion(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByTopicAndVersion(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CTopicMarketDataVersion���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTopicMarketDataVersion	Ҫ�����TopicMarketDataVersion
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTopicMarketDataVersion *internalAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion, bool bNoTransaction);
	
	
	///ˢ�¸�CTopicMarketDataVersion�ļ�ֵ
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CTopicMarketDataVersion��ͬʱɾ��������
	///@param	pTopicMarketDataVersion	Ҫɾ����CTopicMarketDataVersion
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CTopicMarketDataVersion *pTopicMarketDataVersion, bool bNoTransaction);
/*
	///���ĳ��CTopicMarketDataVersion�Ƿ����ڱ����󹤳�
	///@param	pTopicMarketDataVersion	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CTopicMarketDataVersion *pTopicMarketDataVersion);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����TopicID+Version������
	CAVLTree *pTopicAndVersion;
	
	
	///����TopicID��Version����ʱ���洢�Ĳ�ѯ����
	CTopicIDType queryTopicIDInSearchByTopicAndVersion;
	CSequenceNoType queryVersionInSearchByTopicAndVersion;
	
	///����TopicID��Version����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByTopicAndVersion;
	
	///����ǰ����
	///@param	pTopicMarketDataVersion	Ҫ�����TopicMarketDataVersion
	virtual void beforeAdd(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///����󴥷�
	///@param	pTopicMarketDataVersion	�Ѿ������TopicMarketDataVersion
	virtual void afterAdd(CTopicMarketDataVersion *pTopicMarketDataVersion);

	///����ǰ����	
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	///@param	pNewTopicMarketDataVersion	�µ�ֵ
	virtual void beforeUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pNewTopicMarketDataVersion);
	
	///���º󴥷�
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	virtual void afterUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///ɾ��ǰ����
	///@param	pTopicMarketDataVersion	Ҫɾ����CTopicMarketDataVersion
	virtual void beforeRemove(CTopicMarketDataVersion *pTopicMarketDataVersion);
	
	///ȷ�ϼ���󴥷�
	///@param	pTopicMarketDataVersion	�Ѿ������TopicMarketDataVersion
	virtual void commitAdd(CTopicMarketDataVersion *pTopicMarketDataVersion);

	///ȷ�ϸ��º󴥷�
	///@param	pTopicMarketDataVersion	��ˢ�µ�CTopicMarketDataVersion
	///@param	poldTopicMarketDataVersion	ԭ����ֵ
	virtual void commitUpdate(CTopicMarketDataVersion *pTopicMarketDataVersion, CWriteableTopicMarketDataVersion *pOldTopicMarketDataVersion);
	
	///ȷ��ɾ���󴥷�
	///@param	pTopicMarketDataVersion	�Ѿ�ɾ����CTopicMarketDataVersion
	virtual void commitRemove(CWriteableTopicMarketDataVersion *pTopicMarketDataVersion);

	///������صĴ�����
	vector<CTopicMarketDataVersionActionTrigger *> *pActionTriggers;
	vector<CTopicMarketDataVersionCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableTopicMarketDataVersion compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInformationFactory��һ����Ϣ�Ķ��󹤳�����������һ����Ϣ��
///ͬʱ�ֽ����������������Է����ѯ��
///	InformationIDIndex
///	InformationIDLastIndex
///ʹ�ñ����󹤳���������ɶ���Ϣ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByInformationID��findNextByInformationID��endFindByInformationID��ɲ�ѯ����
///		ʹ��findLastInInformationID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInformationFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInformationFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxInformation��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInformationFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInformationFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Information
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Information���ļ��������������ļ��еĶ���InformationCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Information
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Information���ļ��������������ļ��еĶ���InformationCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CInformationResource;

	///��һ��CInformation���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInformation	Ҫ�����Information
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInformation *add(CWriteableInformation *pInformation, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CInformation��ֵ
	///@param	pInformation	��ˢ�µ�CInformation
	///@param	pNewInformation	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CInformation *pInformation, CWriteableInformation *pNewInformation, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pInformation	  ��Ҫ��ˢ�»���������CInformation,����NULL��ʾ����Ҫ������
	///@param	pNewInformation	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CInformation* addOrUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CInformation��ͬʱɾ��������
	///@param	pInformation	Ҫɾ����CInformation
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CInformation *pInformation, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CInformation
	///@param	pInformation	Ҫ��ȡ��CInformation
	///@param	pTragetInformation	��Ž����CInformation
	void retrieve(CInformation *pInformation, CWriteableInformation *pTargetInformation);
	
	///��ȡ��һ��CInformation
	///@return	�õ��ĵ�һ��CInformation�����û�У��򷵻�NULL
	CInformation *getFirst(void);
	
	///��ȡ��һ��CInformation
	///@return	�õ���һ��CInformation�����û�У��򷵻�NULL
	CInformation *getNext(void);
	
	///������ȡCInformation
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CInformationActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CInformationActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CInformationCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CInformationCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CInformationIteratorByInformationID;

	///��ʼѰ��CInformation
	///@param	InformationID	��Ϣ���
	///@return	���������ĵ�һ��CInformation������Ҳ���������NULL
	CInformation *startFindByInformationID( const CReadOnlyInformationIDType& InformationID);

	///Ѱ����һ������������CInformation��������startFindByInformationID�Ժ�endFindByInformationID֮ǰ����
	///@return	��һ����������CInformation������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInformation *findNextByInformationID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByInformationID(void);

	///Ѱ��CInformation
	///@param	InformationID	��Ϣ���
	///@return	�ҵ���CInformation������Ҳ���������NULL
	CInformation *findLastInInformationID( const CReadOnlyInformationIDType&  InformationID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CInformation���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInformation	Ҫ�����Information
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInformation *internalAdd(CWriteableInformation *pInformation, bool bNoTransaction);
	
	
	///ˢ�¸�CInformation�ļ�ֵ
	///@param	pInformation	��ˢ�µ�CInformation
	///@param	pNewInformation	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CInformation��ͬʱɾ��������
	///@param	pInformation	Ҫɾ����CInformation
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CInformation *pInformation, bool bNoTransaction);
/*
	///���ĳ��CInformation�Ƿ����ڱ����󹤳�
	///@param	pInformation	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CInformation *pInformation);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InformationID+SequenceNo������
	CAVLTree *pInformationIDIndex;
	///����InformationID+SequenceNo������
	CAVLTree *pInformationIDLastIndex;
	
	
	///����InformationID����ʱ���洢�Ĳ�ѯ����
	CInformationIDType queryInformationIDInSearchByInformationID;
	
	///����InformationID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByInformationID;
	
	///����ǰ����
	///@param	pInformation	Ҫ�����Information
	virtual void beforeAdd(CWriteableInformation *pInformation);
	
	///����󴥷�
	///@param	pInformation	�Ѿ������Information
	virtual void afterAdd(CInformation *pInformation);

	///����ǰ����	
	///@param	pInformation	��ˢ�µ�CInformation
	///@param	pNewInformation	�µ�ֵ
	virtual void beforeUpdate(CInformation *pInformation, CWriteableInformation *pNewInformation);
	
	///���º󴥷�
	///@param	pInformation	��ˢ�µ�CInformation
	virtual void afterUpdate(CInformation *pInformation);
	
	///ɾ��ǰ����
	///@param	pInformation	Ҫɾ����CInformation
	virtual void beforeRemove(CInformation *pInformation);
	
	///ȷ�ϼ���󴥷�
	///@param	pInformation	�Ѿ������Information
	virtual void commitAdd(CInformation *pInformation);

	///ȷ�ϸ��º󴥷�
	///@param	pInformation	��ˢ�µ�CInformation
	///@param	poldInformation	ԭ����ֵ
	virtual void commitUpdate(CInformation *pInformation, CWriteableInformation *pOldInformation);
	
	///ȷ��ɾ���󴥷�
	///@param	pInformation	�Ѿ�ɾ����CInformation
	virtual void commitRemove(CWriteableInformation *pInformation);

	///������صĴ�����
	vector<CInformationActionTrigger *> *pActionTriggers;
	vector<CInformationCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableInformation compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///COrderCountFactory��һ�����������Ķ��󹤳�����������һ������������
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԱ�����������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByParticipantID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderCountFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	COrderCountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxOrderCount��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	COrderCountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderCountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�OrderCount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�OrderCount���ļ��������������ļ��еĶ���OrderCountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�OrderCount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�OrderCount���ļ��������������ļ��еĶ���OrderCountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class COrderCountResource;

	///��һ��COrderCount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pOrderCount	Ҫ�����OrderCount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	COrderCount *add(CWriteableOrderCount *pOrderCount, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�COrderCount��ֵ
	///@param	pOrderCount	��ˢ�µ�COrderCount
	///@param	pNewOrderCount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pOrderCount	  ��Ҫ��ˢ�»���������COrderCount,����NULL��ʾ����Ҫ������
	///@param	pNewOrderCount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	COrderCount* addOrUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��COrderCount��ͬʱɾ��������
	///@param	pOrderCount	Ҫɾ����COrderCount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(COrderCount *pOrderCount, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��COrderCount
	///@param	pOrderCount	Ҫ��ȡ��COrderCount
	///@param	pTragetOrderCount	��Ž����COrderCount
	void retrieve(COrderCount *pOrderCount, CWriteableOrderCount *pTargetOrderCount);
	
	///��ȡ��һ��COrderCount
	///@return	�õ��ĵ�һ��COrderCount�����û�У��򷵻�NULL
	COrderCount *getFirst(void);
	
	///��ȡ��һ��COrderCount
	///@return	�õ���һ��COrderCount�����û�У��򷵻�NULL
	COrderCount *getNext(void);
	
	///������ȡCOrderCount
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(COrderCountActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(COrderCountActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(COrderCountCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(COrderCountCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��COrderCount
	///@param	ParticipantID	��Ա����
	///@return	�ҵ���COrderCount������Ҳ���������NULL
	COrderCount *findByParticipantID( const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��COrderCount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pOrderCount	Ҫ�����OrderCount
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	COrderCount *internalAdd(CWriteableOrderCount *pOrderCount, bool bNoTransaction);
	
	
	///ˢ�¸�COrderCount�ļ�ֵ
	///@param	pOrderCount	��ˢ�µ�COrderCount
	///@param	pNewOrderCount	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��COrderCount��ͬʱɾ��������
	///@param	pOrderCount	Ҫɾ����COrderCount
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(COrderCount *pOrderCount, bool bNoTransaction);
/*
	///���ĳ��COrderCount�Ƿ����ڱ����󹤳�
	///@param	pOrderCount	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(COrderCount *pOrderCount);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����HashParticipantID��hash����
	CHashIndex *pHashParticipantIDIndex;
	
	
	///����ǰ����
	///@param	pOrderCount	Ҫ�����OrderCount
	virtual void beforeAdd(CWriteableOrderCount *pOrderCount);
	
	///����󴥷�
	///@param	pOrderCount	�Ѿ������OrderCount
	virtual void afterAdd(COrderCount *pOrderCount);

	///����ǰ����	
	///@param	pOrderCount	��ˢ�µ�COrderCount
	///@param	pNewOrderCount	�µ�ֵ
	virtual void beforeUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pNewOrderCount);
	
	///���º󴥷�
	///@param	pOrderCount	��ˢ�µ�COrderCount
	virtual void afterUpdate(COrderCount *pOrderCount);
	
	///ɾ��ǰ����
	///@param	pOrderCount	Ҫɾ����COrderCount
	virtual void beforeRemove(COrderCount *pOrderCount);
	
	///ȷ�ϼ���󴥷�
	///@param	pOrderCount	�Ѿ������OrderCount
	virtual void commitAdd(COrderCount *pOrderCount);

	///ȷ�ϸ��º󴥷�
	///@param	pOrderCount	��ˢ�µ�COrderCount
	///@param	poldOrderCount	ԭ����ֵ
	virtual void commitUpdate(COrderCount *pOrderCount, CWriteableOrderCount *pOldOrderCount);
	
	///ȷ��ɾ���󴥷�
	///@param	pOrderCount	�Ѿ�ɾ����COrderCount
	virtual void commitRemove(CWriteableOrderCount *pOrderCount);

	///������صĴ�����
	vector<COrderCountActionTrigger *> *pActionTriggers;
	vector<COrderCountCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableOrderCount compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentFactory��һ����Լ�Ķ��󹤳�����������һ����Լ��
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///	ProductIDIndex
///	ProductGroupIDIndex
///	ProductGroupIDRevIndex
///ʹ�ñ����󹤳���������ɶԺ�Լ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��startFindByProductID��findNextByProductID��endFindByProductID��ɲ�ѯ����
///		ʹ��startFindByProductGroupID��findNextByProductGroupID��endFindByProductGroupID��ɲ�ѯ����
///		ʹ��startFindByDeliveryMonth��findNextByDeliveryMonth��endFindByDeliveryMonth��ɲ�ѯ����
///		ʹ��startFindByRevDeliveryMonth��findNextByRevDeliveryMonth��endFindByRevDeliveryMonth��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInstrumentFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxInstrument��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInstrumentFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Instrument
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Instrument���ļ��������������ļ��еĶ���InstrumentCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Instrument
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Instrument���ļ��������������ļ��еĶ���InstrumentCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CInstrumentResource;

	///��һ��CInstrument���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInstrument	Ҫ�����Instrument
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInstrument *add(CWriteableInstrument *pInstrument, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CInstrument��ֵ
	///@param	pInstrument	��ˢ�µ�CInstrument
	///@param	pNewInstrument	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pInstrument	  ��Ҫ��ˢ�»���������CInstrument,����NULL��ʾ����Ҫ������
	///@param	pNewInstrument	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CInstrument* addOrUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CInstrument��ͬʱɾ��������
	///@param	pInstrument	Ҫɾ����CInstrument
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CInstrument *pInstrument, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CInstrument
	///@param	pInstrument	Ҫ��ȡ��CInstrument
	///@param	pTragetInstrument	��Ž����CInstrument
	void retrieve(CInstrument *pInstrument, CWriteableInstrument *pTargetInstrument);
	
	///��ȡ��һ��CInstrument
	///@return	�õ��ĵ�һ��CInstrument�����û�У��򷵻�NULL
	CInstrument *getFirst(void);
	
	///��ȡ��һ��CInstrument
	///@return	�õ���һ��CInstrument�����û�У��򷵻�NULL
	CInstrument *getNext(void);
	
	///������ȡCInstrument
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CInstrumentActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CInstrumentActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CInstrumentCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CInstrumentCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�Ļ�����Լ��ָ��
	///@param	pFactory	�����Ӧ�Ļ�����Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllBaseInstrument(CInstrumentFactory *pFactory);
	
	///�������ж�Ӧ�ĺ�Լ���Ե�ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ���Ե�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrumentProperty(CCurrInstrumentPropertyFactory *pFactory);
	
	///�������ж�Ӧ�ĺ�Լ״̬��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrumentStatus(CInstrumentStatusFactory *pFactory);
	
	///�������ж�Ӧ�������ָ��
	///@param	pFactory	�����Ӧ�������ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllMarketData(CMarketDataFactory *pFactory);
	
	///�������ж�Ӧ�����ڱ�ֵ�����ָ��
	///@param	pFactory	�����Ӧ�����ڱ�ֵ�����ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllCurrHedgeRule(CCurrHedgeRuleFactory *pFactory);
	
	///�������ж�Ӧ���۶Ϲ����ָ��
	///@param	pFactory	�����Ӧ���۶Ϲ����ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllCurrFuse(CCurrFuseFactory *pFactory);
	
	///�������ж�Ӧ���۶�״̬��ָ��
	///@param	pFactory	�����Ӧ���۶�״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllFusePhase(CFusePhaseFactory *pFactory);
	
	///�������ж�Ӧ���ǵ�ͣ�����õ�ָ��
	///@param	pFactory	�����Ӧ���ǵ�ͣ�����õ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllBasePriceLimit(CBasePriceLimitFactory *pFactory);
	
	///�������ж�Ӧ�ĵ����������ָ��
	///@param	pFactory	�����Ӧ�ĵ����������ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllUniPressure(CUniPressureFactory *pFactory);
	
	///�������ж�Ӧ�Ľ�����ͬ��״̬��ָ��
	///@param	pFactory	�����Ӧ�Ľ�����ͬ��״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllSGDataSyncStatus(CSGDataSyncStatusFactory *pFactory);
	
	///Ѱ��CInstrument
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CInstrument������Ҳ���������NULL
	CInstrument *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CInstrumentIteratorStartByInstrumentID;

	///��ʼѰ��CInstrument
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CInstrument������Ҳ���������NULL
	CInstrument *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CInstrument��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrument *findNextStartByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByInstrumentID(void);

	friend class CInstrumentIteratorBySettlementGroupID;

	///��ʼѰ��CInstrument
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CInstrument������Ҳ���������NULL
	CInstrument *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CInstrument��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrument *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	friend class CInstrumentIteratorByProductID;

	///��ʼѰ��CInstrument
	///@param	ProductID	��Ʒ���
	///@return	���������ĵ�һ��CInstrument������Ҳ���������NULL
	CInstrument *startFindByProductID( const CReadOnlyProductIDType& ProductID);

	///Ѱ����һ������������CInstrument��������startFindByProductID�Ժ�endFindByProductID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrument *findNextByProductID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByProductID(void);

	friend class CInstrumentIteratorByProductGroupID;

	///��ʼѰ��CInstrument
	///@param	ProductGroupID	��Ʒ����
	///@return	���������ĵ�һ��CInstrument������Ҳ���������NULL
	CInstrument *startFindByProductGroupID( const CReadOnlyProductGroupIDType& ProductGroupID);

	///Ѱ����һ������������CInstrument��������startFindByProductGroupID�Ժ�endFindByProductGroupID֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrument *findNextByProductGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByProductGroupID(void);

	friend class CInstrumentIteratorByDeliveryMonth;

	///��ʼѰ��CInstrument
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	///@return	���������ĵ�һ��CInstrument������Ҳ���������NULL
	CInstrument *startFindByDeliveryMonth( const CReadOnlyProductGroupIDType& ProductGroupID,  const CReadOnlyYearType& DeliveryYear,  const CReadOnlyMonthType& DeliveryMonth);

	///Ѱ����һ������������CInstrument��������startFindByDeliveryMonth�Ժ�endFindByDeliveryMonth֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrument *findNextByDeliveryMonth(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByDeliveryMonth(void);

	friend class CInstrumentIteratorByRevDeliveryMonth;

	///��ʼѰ��CInstrument
	///@param	ProductGroupID	��Ʒ����
	///@param	DeliveryYear	�������
	///@param	DeliveryMonth	�����·�
	///@return	���������ĵ�һ��CInstrument������Ҳ���������NULL
	CInstrument *startFindByRevDeliveryMonth( const CReadOnlyProductGroupIDType& ProductGroupID,  const CReadOnlyYearType& DeliveryYear,  const CReadOnlyMonthType& DeliveryMonth);

	///Ѱ����һ������������CInstrument��������startFindByRevDeliveryMonth�Ժ�endFindByRevDeliveryMonth֮ǰ����
	///@return	��һ����������CInstrument������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrument *findNextByRevDeliveryMonth(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByRevDeliveryMonth(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CInstrument���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInstrument	Ҫ�����Instrument
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInstrument *internalAdd(CWriteableInstrument *pInstrument, bool bNoTransaction);
	
	
	///ˢ�¸�CInstrument�ļ�ֵ
	///@param	pInstrument	��ˢ�µ�CInstrument
	///@param	pNewInstrument	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CInstrument��ͬʱɾ��������
	///@param	pInstrument	Ҫɾ����CInstrument
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CInstrument *pInstrument, bool bNoTransaction);
/*
	///���ĳ��CInstrument�Ƿ����ڱ����󹤳�
	///@param	pInstrument	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CInstrument *pInstrument);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	///����ProductID������
	CAVLTree *pProductIDIndex;
	///����ProductGroupID+DeliveryYear+DeliveryMonth������
	CAVLTree *pProductGroupIDIndex;
	///����ProductGroupID+DeliveryYear+DeliveryMonth������
	CAVLTree *pProductGroupIDRevIndex;
	
	///����InstrumentID��hash����
	CHashIndex *pInstrumentIDHashIndex;
	
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CInstrument *pLastFoundInSearchBySettlementGroupID;
	///����ProductID����ʱ���洢�Ĳ�ѯ����
	CProductIDType queryProductIDInSearchByProductID;
	
	///����ProductID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByProductID;
	///����ProductGroupID����ʱ���洢�Ĳ�ѯ����
	CProductGroupIDType queryProductGroupIDInSearchByProductGroupID;
	
	///����ProductGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByProductGroupID;
	///����ProductGroupID��DeliveryYear��DeliveryMonth����ʱ���洢�Ĳ�ѯ����
	CProductGroupIDType queryProductGroupIDInSearchByDeliveryMonth;
	CYearType queryDeliveryYearInSearchByDeliveryMonth;
	CMonthType queryDeliveryMonthInSearchByDeliveryMonth;
	
	///����ProductGroupID��DeliveryYear��DeliveryMonth����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByDeliveryMonth;
	///����ProductGroupID��DeliveryYear��DeliveryMonth����ʱ���洢�Ĳ�ѯ����
	CProductGroupIDType queryProductGroupIDInSearchByRevDeliveryMonth;
	CYearType queryDeliveryYearInSearchByRevDeliveryMonth;
	CMonthType queryDeliveryMonthInSearchByRevDeliveryMonth;
	
	///����ProductGroupID��DeliveryYear��DeliveryMonth����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByRevDeliveryMonth;
	
	///����ǰ����
	///@param	pInstrument	Ҫ�����Instrument
	virtual void beforeAdd(CWriteableInstrument *pInstrument);
	
	///����󴥷�
	///@param	pInstrument	�Ѿ������Instrument
	virtual void afterAdd(CInstrument *pInstrument);

	///����ǰ����	
	///@param	pInstrument	��ˢ�µ�CInstrument
	///@param	pNewInstrument	�µ�ֵ
	virtual void beforeUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument);
	
	///���º󴥷�
	///@param	pInstrument	��ˢ�µ�CInstrument
	virtual void afterUpdate(CInstrument *pInstrument);
	
	///ɾ��ǰ����
	///@param	pInstrument	Ҫɾ����CInstrument
	virtual void beforeRemove(CInstrument *pInstrument);
	
	///ȷ�ϼ���󴥷�
	///@param	pInstrument	�Ѿ������Instrument
	virtual void commitAdd(CInstrument *pInstrument);

	///ȷ�ϸ��º󴥷�
	///@param	pInstrument	��ˢ�µ�CInstrument
	///@param	poldInstrument	ԭ����ֵ
	virtual void commitUpdate(CInstrument *pInstrument, CWriteableInstrument *pOldInstrument);
	
	///ȷ��ɾ���󴥷�
	///@param	pInstrument	�Ѿ�ɾ����CInstrument
	virtual void commitRemove(CWriteableInstrument *pInstrument);

	///������صĴ�����
	vector<CInstrumentActionTrigger *> *pActionTriggers;
	vector<CInstrumentCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableInstrument compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCombinationLegFactory��һ����Ϻ�Լ���ȵĶ��󹤳�����������һ����Ϻ�Լ���ȣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	CombinationIndex
///	LegIndex
///ʹ�ñ����󹤳���������ɶ���Ϻ�Լ���ȵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByCombination��findNextByCombination��endFindByCombination��ɲ�ѯ����
///		ʹ��findByCombinationLegID��Ψһ�ҵ�����
///		ʹ��startFindByLeg��findNextByLeg��endFindByLeg��ɲ�ѯ����
///		ʹ��findByCombinationAndLeg��Ψһ�ҵ�����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombinationLegFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCombinationLegFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCombinationLeg��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCombinationLegFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombinationLegFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CombinationLeg
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CombinationLeg���ļ��������������ļ��еĶ���CombinationLegCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CombinationLeg
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CombinationLeg���ļ��������������ļ��еĶ���CombinationLegCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCombinationLegResource;

	///��һ��CCombinationLeg���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCombinationLeg	Ҫ�����CombinationLeg
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCombinationLeg *add(CWriteableCombinationLeg *pCombinationLeg, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCombinationLeg��ֵ
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	///@param	pNewCombinationLeg	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCombinationLeg	  ��Ҫ��ˢ�»���������CCombinationLeg,����NULL��ʾ����Ҫ������
	///@param	pNewCombinationLeg	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCombinationLeg* addOrUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCombinationLeg��ͬʱɾ��������
	///@param	pCombinationLeg	Ҫɾ����CCombinationLeg
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCombinationLeg *pCombinationLeg, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCombinationLeg
	///@param	pCombinationLeg	Ҫ��ȡ��CCombinationLeg
	///@param	pTragetCombinationLeg	��Ž����CCombinationLeg
	void retrieve(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pTargetCombinationLeg);
	
	///��ȡ��һ��CCombinationLeg
	///@return	�õ��ĵ�һ��CCombinationLeg�����û�У��򷵻�NULL
	CCombinationLeg *getFirst(void);
	
	///��ȡ��һ��CCombinationLeg
	///@return	�õ���һ��CCombinationLeg�����û�У��򷵻�NULL
	CCombinationLeg *getNext(void);
	
	///������ȡCCombinationLeg
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCombinationLegActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCombinationLegActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCombinationLegCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCombinationLegCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ����Ϻ�Լ��ָ��
	///@param	pFactory	�����Ӧ����Ϻ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	void linkAllCombinationInstrument(CInstrumentFactory *pFactory);
	
	///�������ж�Ӧ�ĵ��Ⱥ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĵ��Ⱥ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	///@exception	����Ҳ��������׳�RUNTIME_ERROR
	void linkAllLegInstrument(CInstrumentFactory *pFactory);
	
	friend class CCombinationLegIteratorByCombination;

	///��ʼѰ��CCombinationLeg
	///@param	CombInstrumentID	��Ϻ�Լ����
	///@return	���������ĵ�һ��CCombinationLeg������Ҳ���������NULL
	CCombinationLeg *startFindByCombination( const CReadOnlyInstrumentIDType& CombInstrumentID);

	///Ѱ����һ������������CCombinationLeg��������startFindByCombination�Ժ�endFindByCombination֮ǰ����
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCombinationLeg *findNextByCombination(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByCombination(void);

	///Ѱ��CCombinationLeg
	///@param	CombInstrumentID	��Ϻ�Լ����
	///@param	LegID	���ȱ��
	///@return	�ҵ���CCombinationLeg������Ҳ���������NULL
	CCombinationLeg *findByCombinationLegID( const CReadOnlyInstrumentIDType&  CombInstrumentID,  const CReadOnlyLegIDType&  LegID);



	friend class CCombinationLegIteratorByLeg;

	///��ʼѰ��CCombinationLeg
	///@param	LegInstrumentID	���Ⱥ�Լ����
	///@return	���������ĵ�һ��CCombinationLeg������Ҳ���������NULL
	CCombinationLeg *startFindByLeg( const CReadOnlyInstrumentIDType& LegInstrumentID);

	///Ѱ����һ������������CCombinationLeg��������startFindByLeg�Ժ�endFindByLeg֮ǰ����
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCombinationLeg *findNextByLeg(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByLeg(void);

	///Ѱ��CCombinationLeg
	///@param	CombInstrumentID	��Ϻ�Լ����
	///@param	LegInstrumentID	���Ⱥ�Լ����
	///@return	�ҵ���CCombinationLeg������Ҳ���������NULL
	CCombinationLeg *findByCombinationAndLeg( const CReadOnlyInstrumentIDType&  CombInstrumentID,  const CReadOnlyInstrumentIDType&  LegInstrumentID);



	friend class CCombinationLegIteratorBySettlementGroupID;

	///��ʼѰ��CCombinationLeg
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCombinationLeg������Ҳ���������NULL
	CCombinationLeg *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCombinationLeg��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCombinationLeg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCombinationLeg *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCombinationLeg���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCombinationLeg	Ҫ�����CombinationLeg
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCombinationLeg *internalAdd(CWriteableCombinationLeg *pCombinationLeg, bool bNoTransaction);
	
	
	///ˢ�¸�CCombinationLeg�ļ�ֵ
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	///@param	pNewCombinationLeg	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCombinationLeg��ͬʱɾ��������
	///@param	pCombinationLeg	Ҫɾ����CCombinationLeg
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCombinationLeg *pCombinationLeg, bool bNoTransaction);
/*
	///���ĳ��CCombinationLeg�Ƿ����ڱ����󹤳�
	///@param	pCombinationLeg	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCombinationLeg *pCombinationLeg);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����CombInstrumentID+LegID������
	CAVLTree *pCombinationIndex;
	///����LegInstrumentID+CombInstrumentID������
	CAVLTree *pLegIndex;
	
	
	///����CombInstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryCombInstrumentIDInSearchByCombination;
	
	///����CombInstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByCombination;
	///����LegInstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryLegInstrumentIDInSearchByLeg;
	
	///����LegInstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByLeg;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCombinationLeg *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCombinationLeg	Ҫ�����CombinationLeg
	virtual void beforeAdd(CWriteableCombinationLeg *pCombinationLeg);
	
	///����󴥷�
	///@param	pCombinationLeg	�Ѿ������CombinationLeg
	virtual void afterAdd(CCombinationLeg *pCombinationLeg);

	///����ǰ����	
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	///@param	pNewCombinationLeg	�µ�ֵ
	virtual void beforeUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pNewCombinationLeg);
	
	///���º󴥷�
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	virtual void afterUpdate(CCombinationLeg *pCombinationLeg);
	
	///ɾ��ǰ����
	///@param	pCombinationLeg	Ҫɾ����CCombinationLeg
	virtual void beforeRemove(CCombinationLeg *pCombinationLeg);
	
	///ȷ�ϼ���󴥷�
	///@param	pCombinationLeg	�Ѿ������CombinationLeg
	virtual void commitAdd(CCombinationLeg *pCombinationLeg);

	///ȷ�ϸ��º󴥷�
	///@param	pCombinationLeg	��ˢ�µ�CCombinationLeg
	///@param	poldCombinationLeg	ԭ����ֵ
	virtual void commitUpdate(CCombinationLeg *pCombinationLeg, CWriteableCombinationLeg *pOldCombinationLeg);
	
	///ȷ��ɾ���󴥷�
	///@param	pCombinationLeg	�Ѿ�ɾ����CCombinationLeg
	virtual void commitRemove(CWriteableCombinationLeg *pCombinationLeg);

	///������صĴ�����
	vector<CCombinationLegActionTrigger *> *pActionTriggers;
	vector<CCombinationLegCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCombinationLeg compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartRoleAccountFactory��һ����Ա�˻���ϵ�Ķ��󹤳�����������һ����Ա�˻���ϵ��
///ͬʱ�ֽ����������������Է����ѯ��
///	PartRoleAndSGIndex
///ʹ�ñ����󹤳���������ɶԻ�Ա�˻���ϵ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPartRoleAndSG��Ψһ�ҵ�����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��startFindStartByParticipantID��findNextStartByParticipantID��endFindStartByParticipantID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartRoleAccountFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartRoleAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartRoleAccount��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartRoleAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartRoleAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartRoleAccount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartRoleAccount���ļ��������������ļ��еĶ���PartRoleAccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartRoleAccount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartRoleAccount���ļ��������������ļ��еĶ���PartRoleAccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartRoleAccountResource;

	///��һ��CPartRoleAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartRoleAccount	Ҫ�����PartRoleAccount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartRoleAccount *add(CWriteablePartRoleAccount *pPartRoleAccount, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartRoleAccount��ֵ
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	///@param	pNewPartRoleAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartRoleAccount	  ��Ҫ��ˢ�»���������CPartRoleAccount,����NULL��ʾ����Ҫ������
	///@param	pNewPartRoleAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartRoleAccount* addOrUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartRoleAccount��ͬʱɾ��������
	///@param	pPartRoleAccount	Ҫɾ����CPartRoleAccount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartRoleAccount *pPartRoleAccount, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartRoleAccount
	///@param	pPartRoleAccount	Ҫ��ȡ��CPartRoleAccount
	///@param	pTragetPartRoleAccount	��Ž����CPartRoleAccount
	void retrieve(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pTargetPartRoleAccount);
	
	///��ȡ��һ��CPartRoleAccount
	///@return	�õ��ĵ�һ��CPartRoleAccount�����û�У��򷵻�NULL
	CPartRoleAccount *getFirst(void);
	
	///��ȡ��һ��CPartRoleAccount
	///@return	�õ���һ��CPartRoleAccount�����û�У��򷵻�NULL
	CPartRoleAccount *getNext(void);
	
	///������ȡCPartRoleAccount
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartRoleAccountActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartRoleAccountActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartRoleAccountCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartRoleAccountCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ���ʻ���ָ��
	///@param	pFactory	�����Ӧ���ʻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllTradingAccount(CTradingAccountFactory *pFactory);
	
	///Ѱ��CPartRoleAccount
	///@param	ParticipantID	��Ա��
	///@param	TradingRole	���׽�ɫ
	///@param	SettlementGroupID	���������
	///@return	�ҵ���CPartRoleAccount������Ҳ���������NULL
	CPartRoleAccount *findByPartRoleAndSG( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlySettlementGroupIDType&  SettlementGroupID);



	friend class CPartRoleAccountIteratorBySettlementGroupID;

	///��ʼѰ��CPartRoleAccount
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CPartRoleAccount������Ҳ���������NULL
	CPartRoleAccount *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CPartRoleAccount��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartRoleAccount *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	friend class CPartRoleAccountIteratorStartByParticipantID;

	///��ʼѰ��CPartRoleAccount
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CPartRoleAccount������Ҳ���������NULL
	CPartRoleAccount *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CPartRoleAccount��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CPartRoleAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartRoleAccount *findNextStartByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipantID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartRoleAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartRoleAccount	Ҫ�����PartRoleAccount
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartRoleAccount *internalAdd(CWriteablePartRoleAccount *pPartRoleAccount, bool bNoTransaction);
	
	
	///ˢ�¸�CPartRoleAccount�ļ�ֵ
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	///@param	pNewPartRoleAccount	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartRoleAccount��ͬʱɾ��������
	///@param	pPartRoleAccount	Ҫɾ����CPartRoleAccount
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartRoleAccount *pPartRoleAccount, bool bNoTransaction);
/*
	///���ĳ��CPartRoleAccount�Ƿ����ڱ����󹤳�
	///@param	pPartRoleAccount	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartRoleAccount *pPartRoleAccount);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID+TradingRole+SettlementGroupID������
	CAVLTree *pPartRoleAndSGIndex;
	
	///����PartRoleAndSG��hash����
	CHashIndex *pPartRoleAndSGHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CPartRoleAccount *pLastFoundInSearchBySettlementGroupID;
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	
	///����ǰ����
	///@param	pPartRoleAccount	Ҫ�����PartRoleAccount
	virtual void beforeAdd(CWriteablePartRoleAccount *pPartRoleAccount);
	
	///����󴥷�
	///@param	pPartRoleAccount	�Ѿ������PartRoleAccount
	virtual void afterAdd(CPartRoleAccount *pPartRoleAccount);

	///����ǰ����	
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	///@param	pNewPartRoleAccount	�µ�ֵ
	virtual void beforeUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pNewPartRoleAccount);
	
	///���º󴥷�
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	virtual void afterUpdate(CPartRoleAccount *pPartRoleAccount);
	
	///ɾ��ǰ����
	///@param	pPartRoleAccount	Ҫɾ����CPartRoleAccount
	virtual void beforeRemove(CPartRoleAccount *pPartRoleAccount);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartRoleAccount	�Ѿ������PartRoleAccount
	virtual void commitAdd(CPartRoleAccount *pPartRoleAccount);

	///ȷ�ϸ��º󴥷�
	///@param	pPartRoleAccount	��ˢ�µ�CPartRoleAccount
	///@param	poldPartRoleAccount	ԭ����ֵ
	virtual void commitUpdate(CPartRoleAccount *pPartRoleAccount, CWriteablePartRoleAccount *pOldPartRoleAccount);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartRoleAccount	�Ѿ�ɾ����CPartRoleAccount
	virtual void commitRemove(CWriteablePartRoleAccount *pPartRoleAccount);

	///������صĴ�����
	vector<CPartRoleAccountActionTrigger *> *pActionTriggers;
	vector<CPartRoleAccountCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartRoleAccount compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRoleFactory��һ����Ա��Ʒ��ɫ�Ķ��󹤳�����������һ����Ա��Ʒ��ɫ��
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԻ�Ա��Ʒ��ɫ����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByParticipantProductRole��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRoleFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartProductRoleFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartProductRole��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartProductRoleFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartProductRoleFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartProductRole
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartProductRole���ļ��������������ļ��еĶ���PartProductRoleCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartProductRole
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartProductRole���ļ��������������ļ��еĶ���PartProductRoleCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartProductRoleResource;

	///��һ��CPartProductRole���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartProductRole	Ҫ�����PartProductRole
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartProductRole *add(CWriteablePartProductRole *pPartProductRole, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartProductRole��ֵ
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	///@param	pNewPartProductRole	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartProductRole	  ��Ҫ��ˢ�»���������CPartProductRole,����NULL��ʾ����Ҫ������
	///@param	pNewPartProductRole	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartProductRole* addOrUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartProductRole��ͬʱɾ��������
	///@param	pPartProductRole	Ҫɾ����CPartProductRole
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartProductRole *pPartProductRole, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartProductRole
	///@param	pPartProductRole	Ҫ��ȡ��CPartProductRole
	///@param	pTragetPartProductRole	��Ž����CPartProductRole
	void retrieve(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pTargetPartProductRole);
	
	///��ȡ��һ��CPartProductRole
	///@return	�õ��ĵ�һ��CPartProductRole�����û�У��򷵻�NULL
	CPartProductRole *getFirst(void);
	
	///��ȡ��һ��CPartProductRole
	///@return	�õ���һ��CPartProductRole�����û�У��򷵻�NULL
	CPartProductRole *getNext(void);
	
	///������ȡCPartProductRole
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartProductRoleActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartProductRoleActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartProductRoleCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartProductRoleCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CPartProductRoleIteratorBySettlementGroupID;

	///��ʼѰ��CPartProductRole
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CPartProductRole������Ҳ���������NULL
	CPartProductRole *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CPartProductRole��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartProductRole������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartProductRole *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CPartProductRole
	///@param	ParticipantID	��Ա���
	///@param	ProductID	��Ʒ���
	///@param	TradingRole	���׽�ɫ
	///@return	�ҵ���CPartProductRole������Ҳ���������NULL
	CPartProductRole *findByParticipantProductRole( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID,  const CReadOnlyTradingRoleType&  TradingRole);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartProductRole���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartProductRole	Ҫ�����PartProductRole
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartProductRole *internalAdd(CWriteablePartProductRole *pPartProductRole, bool bNoTransaction);
	
	
	///ˢ�¸�CPartProductRole�ļ�ֵ
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	///@param	pNewPartProductRole	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartProductRole��ͬʱɾ��������
	///@param	pPartProductRole	Ҫɾ����CPartProductRole
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartProductRole *pPartProductRole, bool bNoTransaction);
/*
	///���ĳ��CPartProductRole�Ƿ����ڱ����󹤳�
	///@param	pPartProductRole	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartProductRole *pPartProductRole);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ParticipantProductRole��hash����
	CHashIndex *pParticipantProductRoleHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CPartProductRole *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pPartProductRole	Ҫ�����PartProductRole
	virtual void beforeAdd(CWriteablePartProductRole *pPartProductRole);
	
	///����󴥷�
	///@param	pPartProductRole	�Ѿ������PartProductRole
	virtual void afterAdd(CPartProductRole *pPartProductRole);

	///����ǰ����	
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	///@param	pNewPartProductRole	�µ�ֵ
	virtual void beforeUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pNewPartProductRole);
	
	///���º󴥷�
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	virtual void afterUpdate(CPartProductRole *pPartProductRole);
	
	///ɾ��ǰ����
	///@param	pPartProductRole	Ҫɾ����CPartProductRole
	virtual void beforeRemove(CPartProductRole *pPartProductRole);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartProductRole	�Ѿ������PartProductRole
	virtual void commitAdd(CPartProductRole *pPartProductRole);

	///ȷ�ϸ��º󴥷�
	///@param	pPartProductRole	��ˢ�µ�CPartProductRole
	///@param	poldPartProductRole	ԭ����ֵ
	virtual void commitUpdate(CPartProductRole *pPartProductRole, CWriteablePartProductRole *pOldPartProductRole);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartProductRole	�Ѿ�ɾ����CPartProductRole
	virtual void commitRemove(CWriteablePartProductRole *pPartProductRole);

	///������صĴ�����
	vector<CPartProductRoleActionTrigger *> *pActionTriggers;
	vector<CPartProductRoleCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartProductRole compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartProductRightFactory��һ����Ա��Ʒ����Ȩ�޵Ķ��󹤳�����������һ����Ա��Ʒ����Ȩ�ޣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԻ�Ա��Ʒ����Ȩ�޵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByParticipantAndProduct��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartProductRightFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartProductRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartProductRight��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartProductRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartProductRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartProductRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartProductRight���ļ��������������ļ��еĶ���PartProductRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartProductRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartProductRight���ļ��������������ļ��еĶ���PartProductRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartProductRightResource;

	///��һ��CPartProductRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartProductRight	Ҫ�����PartProductRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartProductRight *add(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartProductRight��ֵ
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	///@param	pNewPartProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartProductRight	  ��Ҫ��ˢ�»���������CPartProductRight,����NULL��ʾ����Ҫ������
	///@param	pNewPartProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartProductRight* addOrUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartProductRight��ͬʱɾ��������
	///@param	pPartProductRight	Ҫɾ����CPartProductRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartProductRight
	///@param	pPartProductRight	Ҫ��ȡ��CPartProductRight
	///@param	pTragetPartProductRight	��Ž����CPartProductRight
	void retrieve(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pTargetPartProductRight);
	
	///��ȡ��һ��CPartProductRight
	///@return	�õ��ĵ�һ��CPartProductRight�����û�У��򷵻�NULL
	CPartProductRight *getFirst(void);
	
	///��ȡ��һ��CPartProductRight
	///@return	�õ���һ��CPartProductRight�����û�У��򷵻�NULL
	CPartProductRight *getNext(void);
	
	///������ȡCPartProductRight
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartProductRightActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartProductRightActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartProductRightCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartProductRightCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CPartProductRightIteratorBySettlementGroupID;

	///��ʼѰ��CPartProductRight
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CPartProductRight������Ҳ���������NULL
	CPartProductRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CPartProductRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartProductRight *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CPartProductRight
	///@param	ParticipantID	��Ա���
	///@param	ProductID	��Ʒ���
	///@return	�ҵ���CPartProductRight������Ҳ���������NULL
	CPartProductRight *findByParticipantAndProduct( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա���
	///@param	ProductID	��Ʒ���
	///@return	�ҵ���CPartProductRight������Ҳ���������NULL
	CPartProductRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyProductIDType&  ProductID);
	
	///��������Ѱ��CPartProductRight
	///@param	pPartProductRight	Ҫ�ҵ�ֵ
	///@return	�ҵ���CPartProductRight������Ҳ���������NULL
	CPartProductRight *findByPK(CWriteablePartProductRight *pPartProductRight);

	///����������ȡCPartProductRight
	///@param	pPartProductRight	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CPartProductRight������Ҳ���������NULL
	bool retrieveByPK(CWriteablePartProductRight *pPartProductRight);

	///�������������µ�CPartProductRight
	///@param	pPartProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CPartProductRight���������ʧ�ܣ��򷵻�NULL
	CPartProductRight *addByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);

	///������������CPartProductRight��ֵ
	///@param	pPartProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CPartProductRight
	///@param	pPartProductRight	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteablePartProductRight *pPartProductRight, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartProductRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartProductRight	Ҫ�����PartProductRight
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartProductRight *internalAdd(CWriteablePartProductRight *pPartProductRight, bool bNoTransaction);
	
	
	///ˢ�¸�CPartProductRight�ļ�ֵ
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	///@param	pNewPartProductRight	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartProductRight��ͬʱɾ��������
	///@param	pPartProductRight	Ҫɾ����CPartProductRight
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartProductRight *pPartProductRight, bool bNoTransaction);
/*
	///���ĳ��CPartProductRight�Ƿ����ڱ����󹤳�
	///@param	pPartProductRight	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartProductRight *pPartProductRight);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ParticipantAndProduct��hash����
	CHashIndex *pParticipantAndProductHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CPartProductRight *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pPartProductRight	Ҫ�����PartProductRight
	virtual void beforeAdd(CWriteablePartProductRight *pPartProductRight);
	
	///����󴥷�
	///@param	pPartProductRight	�Ѿ������PartProductRight
	virtual void afterAdd(CPartProductRight *pPartProductRight);

	///����ǰ����	
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	///@param	pNewPartProductRight	�µ�ֵ
	virtual void beforeUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pNewPartProductRight);
	
	///���º󴥷�
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	virtual void afterUpdate(CPartProductRight *pPartProductRight);
	
	///ɾ��ǰ����
	///@param	pPartProductRight	Ҫɾ����CPartProductRight
	virtual void beforeRemove(CPartProductRight *pPartProductRight);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartProductRight	�Ѿ������PartProductRight
	virtual void commitAdd(CPartProductRight *pPartProductRight);

	///ȷ�ϸ��º󴥷�
	///@param	pPartProductRight	��ˢ�µ�CPartProductRight
	///@param	poldPartProductRight	ԭ����ֵ
	virtual void commitUpdate(CPartProductRight *pPartProductRight, CWriteablePartProductRight *pOldPartProductRight);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartProductRight	�Ѿ�ɾ����CPartProductRight
	virtual void commitRemove(CWriteablePartProductRight *pPartProductRight);

	///������صĴ�����
	vector<CPartProductRightActionTrigger *> *pActionTriggers;
	vector<CPartProductRightCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartProductRight compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartInstrumentRightFactory��һ����Ա��Լ����Ȩ�޵Ķ��󹤳�����������һ����Ա��Լ����Ȩ�ޣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԻ�Ա��Լ����Ȩ�޵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByParticipantAndInstrument��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartInstrumentRightFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartInstrumentRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartInstrumentRight��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartInstrumentRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartInstrumentRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartInstrumentRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartInstrumentRight���ļ��������������ļ��еĶ���PartInstrumentRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartInstrumentRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartInstrumentRight���ļ��������������ļ��еĶ���PartInstrumentRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartInstrumentRightResource;

	///��һ��CPartInstrumentRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartInstrumentRight	Ҫ�����PartInstrumentRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartInstrumentRight *add(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartInstrumentRight��ֵ
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	///@param	pNewPartInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartInstrumentRight	  ��Ҫ��ˢ�»���������CPartInstrumentRight,����NULL��ʾ����Ҫ������
	///@param	pNewPartInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartInstrumentRight* addOrUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartInstrumentRight��ͬʱɾ��������
	///@param	pPartInstrumentRight	Ҫɾ����CPartInstrumentRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartInstrumentRight
	///@param	pPartInstrumentRight	Ҫ��ȡ��CPartInstrumentRight
	///@param	pTragetPartInstrumentRight	��Ž����CPartInstrumentRight
	void retrieve(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pTargetPartInstrumentRight);
	
	///��ȡ��һ��CPartInstrumentRight
	///@return	�õ��ĵ�һ��CPartInstrumentRight�����û�У��򷵻�NULL
	CPartInstrumentRight *getFirst(void);
	
	///��ȡ��һ��CPartInstrumentRight
	///@return	�õ���һ��CPartInstrumentRight�����û�У��򷵻�NULL
	CPartInstrumentRight *getNext(void);
	
	///������ȡCPartInstrumentRight
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartInstrumentRightActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartInstrumentRightActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartInstrumentRightCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartInstrumentRightCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CPartInstrumentRightIteratorBySettlementGroupID;

	///��ʼѰ��CPartInstrumentRight
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CPartInstrumentRight������Ҳ���������NULL
	CPartInstrumentRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CPartInstrumentRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartInstrumentRight *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CPartInstrumentRight
	///@param	ParticipantID	��Ա���
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CPartInstrumentRight������Ҳ���������NULL
	CPartInstrumentRight *findByParticipantAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա���
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CPartInstrumentRight������Ҳ���������NULL
	CPartInstrumentRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///��������Ѱ��CPartInstrumentRight
	///@param	pPartInstrumentRight	Ҫ�ҵ�ֵ
	///@return	�ҵ���CPartInstrumentRight������Ҳ���������NULL
	CPartInstrumentRight *findByPK(CWriteablePartInstrumentRight *pPartInstrumentRight);

	///����������ȡCPartInstrumentRight
	///@param	pPartInstrumentRight	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CPartInstrumentRight������Ҳ���������NULL
	bool retrieveByPK(CWriteablePartInstrumentRight *pPartInstrumentRight);

	///�������������µ�CPartInstrumentRight
	///@param	pPartInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CPartInstrumentRight���������ʧ�ܣ��򷵻�NULL
	CPartInstrumentRight *addByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);

	///������������CPartInstrumentRight��ֵ
	///@param	pPartInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CPartInstrumentRight
	///@param	pPartInstrumentRight	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteablePartInstrumentRight *pPartInstrumentRight, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartInstrumentRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartInstrumentRight	Ҫ�����PartInstrumentRight
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartInstrumentRight *internalAdd(CWriteablePartInstrumentRight *pPartInstrumentRight, bool bNoTransaction);
	
	
	///ˢ�¸�CPartInstrumentRight�ļ�ֵ
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	///@param	pNewPartInstrumentRight	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartInstrumentRight��ͬʱɾ��������
	///@param	pPartInstrumentRight	Ҫɾ����CPartInstrumentRight
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartInstrumentRight *pPartInstrumentRight, bool bNoTransaction);
/*
	///���ĳ��CPartInstrumentRight�Ƿ����ڱ����󹤳�
	///@param	pPartInstrumentRight	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartInstrumentRight *pPartInstrumentRight);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ParticipantAndInstrument��hash����
	CHashIndex *pParticipantAndInstrumentHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CPartInstrumentRight *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pPartInstrumentRight	Ҫ�����PartInstrumentRight
	virtual void beforeAdd(CWriteablePartInstrumentRight *pPartInstrumentRight);
	
	///����󴥷�
	///@param	pPartInstrumentRight	�Ѿ������PartInstrumentRight
	virtual void afterAdd(CPartInstrumentRight *pPartInstrumentRight);

	///����ǰ����	
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	///@param	pNewPartInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pNewPartInstrumentRight);
	
	///���º󴥷�
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	virtual void afterUpdate(CPartInstrumentRight *pPartInstrumentRight);
	
	///ɾ��ǰ����
	///@param	pPartInstrumentRight	Ҫɾ����CPartInstrumentRight
	virtual void beforeRemove(CPartInstrumentRight *pPartInstrumentRight);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartInstrumentRight	�Ѿ������PartInstrumentRight
	virtual void commitAdd(CPartInstrumentRight *pPartInstrumentRight);

	///ȷ�ϸ��º󴥷�
	///@param	pPartInstrumentRight	��ˢ�µ�CPartInstrumentRight
	///@param	poldPartInstrumentRight	ԭ����ֵ
	virtual void commitUpdate(CPartInstrumentRight *pPartInstrumentRight, CWriteablePartInstrumentRight *pOldPartInstrumentRight);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartInstrumentRight	�Ѿ�ɾ����CPartInstrumentRight
	virtual void commitRemove(CWriteablePartInstrumentRight *pPartInstrumentRight);

	///������صĴ�����
	vector<CPartInstrumentRightActionTrigger *> *pActionTriggers;
	vector<CPartInstrumentRightCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartInstrumentRight compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientProductRightFactory��һ���ͻ���Ʒ����Ȩ�޵Ķ��󹤳�����������һ���ͻ���Ʒ����Ȩ�ޣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԿͻ���Ʒ����Ȩ�޵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByClientAndProduct��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientProductRightFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientProductRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxClientProductRight��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientProductRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientProductRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ClientProductRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ClientProductRight���ļ��������������ļ��еĶ���ClientProductRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ClientProductRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ClientProductRight���ļ��������������ļ��еĶ���ClientProductRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CClientProductRightResource;

	///��һ��CClientProductRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClientProductRight	Ҫ�����ClientProductRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClientProductRight *add(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CClientProductRight��ֵ
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	///@param	pNewClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pClientProductRight	  ��Ҫ��ˢ�»���������CClientProductRight,����NULL��ʾ����Ҫ������
	///@param	pNewClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CClientProductRight* addOrUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CClientProductRight��ͬʱɾ��������
	///@param	pClientProductRight	Ҫɾ����CClientProductRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CClientProductRight
	///@param	pClientProductRight	Ҫ��ȡ��CClientProductRight
	///@param	pTragetClientProductRight	��Ž����CClientProductRight
	void retrieve(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pTargetClientProductRight);
	
	///��ȡ��һ��CClientProductRight
	///@return	�õ��ĵ�һ��CClientProductRight�����û�У��򷵻�NULL
	CClientProductRight *getFirst(void);
	
	///��ȡ��һ��CClientProductRight
	///@return	�õ���һ��CClientProductRight�����û�У��򷵻�NULL
	CClientProductRight *getNext(void);
	
	///������ȡCClientProductRight
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CClientProductRightActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CClientProductRightActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CClientProductRightCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CClientProductRightCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CClientProductRightIteratorBySettlementGroupID;

	///��ʼѰ��CClientProductRight
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CClientProductRight������Ҳ���������NULL
	CClientProductRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CClientProductRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientProductRight *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CClientProductRight
	///@param	ClientID	�ͻ����
	///@param	ProductID	��Ʒ���
	///@return	�ҵ���CClientProductRight������Ҳ���������NULL
	CClientProductRight *findByClientAndProduct( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);

	///��������Ѱ��
	///@param	ClientID	�ͻ����
	///@param	ProductID	��Ʒ���
	///@return	�ҵ���CClientProductRight������Ҳ���������NULL
	CClientProductRight *findByPK( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);
	
	///��������Ѱ��CClientProductRight
	///@param	pClientProductRight	Ҫ�ҵ�ֵ
	///@return	�ҵ���CClientProductRight������Ҳ���������NULL
	CClientProductRight *findByPK(CWriteableClientProductRight *pClientProductRight);

	///����������ȡCClientProductRight
	///@param	pClientProductRight	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CClientProductRight������Ҳ���������NULL
	bool retrieveByPK(CWriteableClientProductRight *pClientProductRight);

	///�������������µ�CClientProductRight
	///@param	pClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CClientProductRight���������ʧ�ܣ��򷵻�NULL
	CClientProductRight *addByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);

	///������������CClientProductRight��ֵ
	///@param	pClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CClientProductRight
	///@param	pClientProductRight	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableClientProductRight *pClientProductRight, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CClientProductRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClientProductRight	Ҫ�����ClientProductRight
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClientProductRight *internalAdd(CWriteableClientProductRight *pClientProductRight, bool bNoTransaction);
	
	
	///ˢ�¸�CClientProductRight�ļ�ֵ
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	///@param	pNewClientProductRight	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CClientProductRight��ͬʱɾ��������
	///@param	pClientProductRight	Ҫɾ����CClientProductRight
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CClientProductRight *pClientProductRight, bool bNoTransaction);
/*
	///���ĳ��CClientProductRight�Ƿ����ڱ����󹤳�
	///@param	pClientProductRight	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CClientProductRight *pClientProductRight);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ClientAndProduct��hash����
	CHashIndex *pClientAndProductHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CClientProductRight *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pClientProductRight	Ҫ�����ClientProductRight
	virtual void beforeAdd(CWriteableClientProductRight *pClientProductRight);
	
	///����󴥷�
	///@param	pClientProductRight	�Ѿ������ClientProductRight
	virtual void afterAdd(CClientProductRight *pClientProductRight);

	///����ǰ����	
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	///@param	pNewClientProductRight	�µ�ֵ
	virtual void beforeUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pNewClientProductRight);
	
	///���º󴥷�
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	virtual void afterUpdate(CClientProductRight *pClientProductRight);
	
	///ɾ��ǰ����
	///@param	pClientProductRight	Ҫɾ����CClientProductRight
	virtual void beforeRemove(CClientProductRight *pClientProductRight);
	
	///ȷ�ϼ���󴥷�
	///@param	pClientProductRight	�Ѿ������ClientProductRight
	virtual void commitAdd(CClientProductRight *pClientProductRight);

	///ȷ�ϸ��º󴥷�
	///@param	pClientProductRight	��ˢ�µ�CClientProductRight
	///@param	poldClientProductRight	ԭ����ֵ
	virtual void commitUpdate(CClientProductRight *pClientProductRight, CWriteableClientProductRight *pOldClientProductRight);
	
	///ȷ��ɾ���󴥷�
	///@param	pClientProductRight	�Ѿ�ɾ����CClientProductRight
	virtual void commitRemove(CWriteableClientProductRight *pClientProductRight);

	///������صĴ�����
	vector<CClientProductRightActionTrigger *> *pActionTriggers;
	vector<CClientProductRightCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableClientProductRight compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientInstrumentRightFactory��һ���ͻ���Լ����Ȩ�޵Ķ��󹤳�����������һ���ͻ���Լ����Ȩ�ޣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԿͻ���Լ����Ȩ�޵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByClientAndInstrument��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientInstrumentRightFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientInstrumentRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxClientInstrumentRight��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientInstrumentRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientInstrumentRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ClientInstrumentRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ClientInstrumentRight���ļ��������������ļ��еĶ���ClientInstrumentRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ClientInstrumentRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ClientInstrumentRight���ļ��������������ļ��еĶ���ClientInstrumentRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CClientInstrumentRightResource;

	///��һ��CClientInstrumentRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClientInstrumentRight	Ҫ�����ClientInstrumentRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClientInstrumentRight *add(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CClientInstrumentRight��ֵ
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	///@param	pNewClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pClientInstrumentRight	  ��Ҫ��ˢ�»���������CClientInstrumentRight,����NULL��ʾ����Ҫ������
	///@param	pNewClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CClientInstrumentRight* addOrUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CClientInstrumentRight��ͬʱɾ��������
	///@param	pClientInstrumentRight	Ҫɾ����CClientInstrumentRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CClientInstrumentRight
	///@param	pClientInstrumentRight	Ҫ��ȡ��CClientInstrumentRight
	///@param	pTragetClientInstrumentRight	��Ž����CClientInstrumentRight
	void retrieve(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pTargetClientInstrumentRight);
	
	///��ȡ��һ��CClientInstrumentRight
	///@return	�õ��ĵ�һ��CClientInstrumentRight�����û�У��򷵻�NULL
	CClientInstrumentRight *getFirst(void);
	
	///��ȡ��һ��CClientInstrumentRight
	///@return	�õ���һ��CClientInstrumentRight�����û�У��򷵻�NULL
	CClientInstrumentRight *getNext(void);
	
	///������ȡCClientInstrumentRight
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CClientInstrumentRightActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CClientInstrumentRightActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CClientInstrumentRightCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CClientInstrumentRightCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CClientInstrumentRightIteratorBySettlementGroupID;

	///��ʼѰ��CClientInstrumentRight
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CClientInstrumentRight������Ҳ���������NULL
	CClientInstrumentRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CClientInstrumentRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientInstrumentRight *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CClientInstrumentRight
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CClientInstrumentRight������Ҳ���������NULL
	CClientInstrumentRight *findByClientAndInstrument( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);

	///��������Ѱ��
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CClientInstrumentRight������Ҳ���������NULL
	CClientInstrumentRight *findByPK( const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///��������Ѱ��CClientInstrumentRight
	///@param	pClientInstrumentRight	Ҫ�ҵ�ֵ
	///@return	�ҵ���CClientInstrumentRight������Ҳ���������NULL
	CClientInstrumentRight *findByPK(CWriteableClientInstrumentRight *pClientInstrumentRight);

	///����������ȡCClientInstrumentRight
	///@param	pClientInstrumentRight	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CClientInstrumentRight������Ҳ���������NULL
	bool retrieveByPK(CWriteableClientInstrumentRight *pClientInstrumentRight);

	///�������������µ�CClientInstrumentRight
	///@param	pClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CClientInstrumentRight���������ʧ�ܣ��򷵻�NULL
	CClientInstrumentRight *addByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);

	///������������CClientInstrumentRight��ֵ
	///@param	pClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CClientInstrumentRight
	///@param	pClientInstrumentRight	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableClientInstrumentRight *pClientInstrumentRight, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CClientInstrumentRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClientInstrumentRight	Ҫ�����ClientInstrumentRight
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClientInstrumentRight *internalAdd(CWriteableClientInstrumentRight *pClientInstrumentRight, bool bNoTransaction);
	
	
	///ˢ�¸�CClientInstrumentRight�ļ�ֵ
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	///@param	pNewClientInstrumentRight	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CClientInstrumentRight��ͬʱɾ��������
	///@param	pClientInstrumentRight	Ҫɾ����CClientInstrumentRight
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CClientInstrumentRight *pClientInstrumentRight, bool bNoTransaction);
/*
	///���ĳ��CClientInstrumentRight�Ƿ����ڱ����󹤳�
	///@param	pClientInstrumentRight	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CClientInstrumentRight *pClientInstrumentRight);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ClientAndInstrument��hash����
	CHashIndex *pClientAndInstrumentHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CClientInstrumentRight *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pClientInstrumentRight	Ҫ�����ClientInstrumentRight
	virtual void beforeAdd(CWriteableClientInstrumentRight *pClientInstrumentRight);
	
	///����󴥷�
	///@param	pClientInstrumentRight	�Ѿ������ClientInstrumentRight
	virtual void afterAdd(CClientInstrumentRight *pClientInstrumentRight);

	///����ǰ����	
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	///@param	pNewClientInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pNewClientInstrumentRight);
	
	///���º󴥷�
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	virtual void afterUpdate(CClientInstrumentRight *pClientInstrumentRight);
	
	///ɾ��ǰ����
	///@param	pClientInstrumentRight	Ҫɾ����CClientInstrumentRight
	virtual void beforeRemove(CClientInstrumentRight *pClientInstrumentRight);
	
	///ȷ�ϼ���󴥷�
	///@param	pClientInstrumentRight	�Ѿ������ClientInstrumentRight
	virtual void commitAdd(CClientInstrumentRight *pClientInstrumentRight);

	///ȷ�ϸ��º󴥷�
	///@param	pClientInstrumentRight	��ˢ�µ�CClientInstrumentRight
	///@param	poldClientInstrumentRight	ԭ����ֵ
	virtual void commitUpdate(CClientInstrumentRight *pClientInstrumentRight, CWriteableClientInstrumentRight *pOldClientInstrumentRight);
	
	///ȷ��ɾ���󴥷�
	///@param	pClientInstrumentRight	�Ѿ�ɾ����CClientInstrumentRight
	virtual void commitRemove(CWriteableClientInstrumentRight *pClientInstrumentRight);

	///������صĴ�����
	vector<CClientInstrumentRightActionTrigger *> *pActionTriggers;
	vector<CClientInstrumentRightCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableClientInstrumentRight compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientProductRightFactory��һ����Ա�ͻ���Ʒ����Ȩ�޵Ķ��󹤳�����������һ����Ա�ͻ���Ʒ����Ȩ�ޣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԻ�Ա�ͻ���Ʒ����Ȩ�޵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByParticipantAndClientAndProduct��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientProductRightFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartClientProductRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartClientProductRight��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartClientProductRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientProductRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartClientProductRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartClientProductRight���ļ��������������ļ��еĶ���PartClientProductRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartClientProductRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartClientProductRight���ļ��������������ļ��еĶ���PartClientProductRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartClientProductRightResource;

	///��һ��CPartClientProductRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartClientProductRight	Ҫ�����PartClientProductRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartClientProductRight *add(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartClientProductRight��ֵ
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	///@param	pNewPartClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartClientProductRight	  ��Ҫ��ˢ�»���������CPartClientProductRight,����NULL��ʾ����Ҫ������
	///@param	pNewPartClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartClientProductRight* addOrUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartClientProductRight��ͬʱɾ��������
	///@param	pPartClientProductRight	Ҫɾ����CPartClientProductRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartClientProductRight
	///@param	pPartClientProductRight	Ҫ��ȡ��CPartClientProductRight
	///@param	pTragetPartClientProductRight	��Ž����CPartClientProductRight
	void retrieve(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pTargetPartClientProductRight);
	
	///��ȡ��һ��CPartClientProductRight
	///@return	�õ��ĵ�һ��CPartClientProductRight�����û�У��򷵻�NULL
	CPartClientProductRight *getFirst(void);
	
	///��ȡ��һ��CPartClientProductRight
	///@return	�õ���һ��CPartClientProductRight�����û�У��򷵻�NULL
	CPartClientProductRight *getNext(void);
	
	///������ȡCPartClientProductRight
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartClientProductRightActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartClientProductRightActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartClientProductRightCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartClientProductRightCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CPartClientProductRightIteratorBySettlementGroupID;

	///��ʼѰ��CPartClientProductRight
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CPartClientProductRight������Ҳ���������NULL
	CPartClientProductRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CPartClientProductRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartClientProductRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartClientProductRight *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CPartClientProductRight
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	ProductID	��Ʒ���
	///@return	�ҵ���CPartClientProductRight������Ҳ���������NULL
	CPartClientProductRight *findByParticipantAndClientAndProduct( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	ProductID	��Ʒ���
	///@return	�ҵ���CPartClientProductRight������Ҳ���������NULL
	CPartClientProductRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyProductIDType&  ProductID);
	
	///��������Ѱ��CPartClientProductRight
	///@param	pPartClientProductRight	Ҫ�ҵ�ֵ
	///@return	�ҵ���CPartClientProductRight������Ҳ���������NULL
	CPartClientProductRight *findByPK(CWriteablePartClientProductRight *pPartClientProductRight);

	///����������ȡCPartClientProductRight
	///@param	pPartClientProductRight	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CPartClientProductRight������Ҳ���������NULL
	bool retrieveByPK(CWriteablePartClientProductRight *pPartClientProductRight);

	///�������������µ�CPartClientProductRight
	///@param	pPartClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CPartClientProductRight���������ʧ�ܣ��򷵻�NULL
	CPartClientProductRight *addByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);

	///������������CPartClientProductRight��ֵ
	///@param	pPartClientProductRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CPartClientProductRight
	///@param	pPartClientProductRight	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteablePartClientProductRight *pPartClientProductRight, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartClientProductRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartClientProductRight	Ҫ�����PartClientProductRight
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartClientProductRight *internalAdd(CWriteablePartClientProductRight *pPartClientProductRight, bool bNoTransaction);
	
	
	///ˢ�¸�CPartClientProductRight�ļ�ֵ
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	///@param	pNewPartClientProductRight	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartClientProductRight��ͬʱɾ��������
	///@param	pPartClientProductRight	Ҫɾ����CPartClientProductRight
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartClientProductRight *pPartClientProductRight, bool bNoTransaction);
/*
	///���ĳ��CPartClientProductRight�Ƿ����ڱ����󹤳�
	///@param	pPartClientProductRight	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartClientProductRight *pPartClientProductRight);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ParticipantAndClientAndProduct��hash����
	CHashIndex *pParticipantAndClientAndProductHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CPartClientProductRight *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pPartClientProductRight	Ҫ�����PartClientProductRight
	virtual void beforeAdd(CWriteablePartClientProductRight *pPartClientProductRight);
	
	///����󴥷�
	///@param	pPartClientProductRight	�Ѿ������PartClientProductRight
	virtual void afterAdd(CPartClientProductRight *pPartClientProductRight);

	///����ǰ����	
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	///@param	pNewPartClientProductRight	�µ�ֵ
	virtual void beforeUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pNewPartClientProductRight);
	
	///���º󴥷�
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	virtual void afterUpdate(CPartClientProductRight *pPartClientProductRight);
	
	///ɾ��ǰ����
	///@param	pPartClientProductRight	Ҫɾ����CPartClientProductRight
	virtual void beforeRemove(CPartClientProductRight *pPartClientProductRight);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartClientProductRight	�Ѿ������PartClientProductRight
	virtual void commitAdd(CPartClientProductRight *pPartClientProductRight);

	///ȷ�ϸ��º󴥷�
	///@param	pPartClientProductRight	��ˢ�µ�CPartClientProductRight
	///@param	poldPartClientProductRight	ԭ����ֵ
	virtual void commitUpdate(CPartClientProductRight *pPartClientProductRight, CWriteablePartClientProductRight *pOldPartClientProductRight);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartClientProductRight	�Ѿ�ɾ����CPartClientProductRight
	virtual void commitRemove(CWriteablePartClientProductRight *pPartClientProductRight);

	///������صĴ�����
	vector<CPartClientProductRightActionTrigger *> *pActionTriggers;
	vector<CPartClientProductRightCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartClientProductRight compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartClientInstrumentRightFactory��һ����Ա�ͻ���Լ����Ȩ�޵Ķ��󹤳�����������һ����Ա�ͻ���Լ����Ȩ�ޣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԻ�Ա�ͻ���Լ����Ȩ�޵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByParticipantAndClientAndInstrument��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartClientInstrumentRightFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartClientInstrumentRightFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartClientInstrumentRight��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartClientInstrumentRightFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartClientInstrumentRightFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartClientInstrumentRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartClientInstrumentRight���ļ��������������ļ��еĶ���PartClientInstrumentRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartClientInstrumentRight
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartClientInstrumentRight���ļ��������������ļ��еĶ���PartClientInstrumentRightCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartClientInstrumentRightResource;

	///��һ��CPartClientInstrumentRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartClientInstrumentRight	Ҫ�����PartClientInstrumentRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartClientInstrumentRight *add(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartClientInstrumentRight��ֵ
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartClientInstrumentRight	  ��Ҫ��ˢ�»���������CPartClientInstrumentRight,����NULL��ʾ����Ҫ������
	///@param	pNewPartClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartClientInstrumentRight* addOrUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartClientInstrumentRight��ͬʱɾ��������
	///@param	pPartClientInstrumentRight	Ҫɾ����CPartClientInstrumentRight
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	Ҫ��ȡ��CPartClientInstrumentRight
	///@param	pTragetPartClientInstrumentRight	��Ž����CPartClientInstrumentRight
	void retrieve(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pTargetPartClientInstrumentRight);
	
	///��ȡ��һ��CPartClientInstrumentRight
	///@return	�õ��ĵ�һ��CPartClientInstrumentRight�����û�У��򷵻�NULL
	CPartClientInstrumentRight *getFirst(void);
	
	///��ȡ��һ��CPartClientInstrumentRight
	///@return	�õ���һ��CPartClientInstrumentRight�����û�У��򷵻�NULL
	CPartClientInstrumentRight *getNext(void);
	
	///������ȡCPartClientInstrumentRight
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartClientInstrumentRightActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartClientInstrumentRightActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartClientInstrumentRightCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartClientInstrumentRightCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CPartClientInstrumentRightIteratorBySettlementGroupID;

	///��ʼѰ��CPartClientInstrumentRight
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CPartClientInstrumentRight������Ҳ���������NULL
	CPartClientInstrumentRight *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CPartClientInstrumentRight��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartClientInstrumentRight������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartClientInstrumentRight *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CPartClientInstrumentRight
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CPartClientInstrumentRight������Ҳ���������NULL
	CPartClientInstrumentRight *findByParticipantAndClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);

	///��������Ѱ��
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CPartClientInstrumentRight������Ҳ���������NULL
	CPartClientInstrumentRight *findByPK( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///��������Ѱ��CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	Ҫ�ҵ�ֵ
	///@return	�ҵ���CPartClientInstrumentRight������Ҳ���������NULL
	CPartClientInstrumentRight *findByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);

	///����������ȡCPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CPartClientInstrumentRight������Ҳ���������NULL
	bool retrieveByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);

	///�������������µ�CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CPartClientInstrumentRight���������ʧ�ܣ��򷵻�NULL
	CPartClientInstrumentRight *addByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);

	///������������CPartClientInstrumentRight��ֵ
	///@param	pPartClientInstrumentRight	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CPartClientInstrumentRight
	///@param	pPartClientInstrumentRight	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartClientInstrumentRight���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartClientInstrumentRight	Ҫ�����PartClientInstrumentRight
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartClientInstrumentRight *internalAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight, bool bNoTransaction);
	
	
	///ˢ�¸�CPartClientInstrumentRight�ļ�ֵ
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartClientInstrumentRight��ͬʱɾ��������
	///@param	pPartClientInstrumentRight	Ҫɾ����CPartClientInstrumentRight
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartClientInstrumentRight *pPartClientInstrumentRight, bool bNoTransaction);
/*
	///���ĳ��CPartClientInstrumentRight�Ƿ����ڱ����󹤳�
	///@param	pPartClientInstrumentRight	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartClientInstrumentRight *pPartClientInstrumentRight);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����ParticipantAndClientAndInstrument��hash����
	CHashIndex *pParticipantAndClientAndInstrumentHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CPartClientInstrumentRight *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pPartClientInstrumentRight	Ҫ�����PartClientInstrumentRight
	virtual void beforeAdd(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);
	
	///����󴥷�
	///@param	pPartClientInstrumentRight	�Ѿ������PartClientInstrumentRight
	virtual void afterAdd(CPartClientInstrumentRight *pPartClientInstrumentRight);

	///����ǰ����	
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	///@param	pNewPartClientInstrumentRight	�µ�ֵ
	virtual void beforeUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pNewPartClientInstrumentRight);
	
	///���º󴥷�
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	virtual void afterUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight);
	
	///ɾ��ǰ����
	///@param	pPartClientInstrumentRight	Ҫɾ����CPartClientInstrumentRight
	virtual void beforeRemove(CPartClientInstrumentRight *pPartClientInstrumentRight);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartClientInstrumentRight	�Ѿ������PartClientInstrumentRight
	virtual void commitAdd(CPartClientInstrumentRight *pPartClientInstrumentRight);

	///ȷ�ϸ��º󴥷�
	///@param	pPartClientInstrumentRight	��ˢ�µ�CPartClientInstrumentRight
	///@param	poldPartClientInstrumentRight	ԭ����ֵ
	virtual void commitUpdate(CPartClientInstrumentRight *pPartClientInstrumentRight, CWriteablePartClientInstrumentRight *pOldPartClientInstrumentRight);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartClientInstrumentRight	�Ѿ�ɾ����CPartClientInstrumentRight
	virtual void commitRemove(CWriteablePartClientInstrumentRight *pPartClientInstrumentRight);

	///������صĴ�����
	vector<CPartClientInstrumentRightActionTrigger *> *pActionTriggers;
	vector<CPartClientInstrumentRightCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartClientInstrumentRight compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrProductPropertyFactory��һ����Ʒ���ԵĶ��󹤳�����������һ����Ʒ���ԣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	ProductIDIndex
///ʹ�ñ����󹤳���������ɶԲ�Ʒ���Ե���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByProductID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrProductPropertyFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrProductPropertyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrProductProperty��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrProductPropertyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrProductPropertyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrProductProperty
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrProductProperty���ļ��������������ļ��еĶ���CurrProductPropertyCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrProductProperty
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrProductProperty���ļ��������������ļ��еĶ���CurrProductPropertyCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrProductPropertyResource;

	///��һ��CCurrProductProperty���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrProductProperty	Ҫ�����CurrProductProperty
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrProductProperty *add(CWriteableCurrProductProperty *pCurrProductProperty, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrProductProperty��ֵ
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	///@param	pNewCurrProductProperty	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrProductProperty	  ��Ҫ��ˢ�»���������CCurrProductProperty,����NULL��ʾ����Ҫ������
	///@param	pNewCurrProductProperty	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrProductProperty* addOrUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrProductProperty��ͬʱɾ��������
	///@param	pCurrProductProperty	Ҫɾ����CCurrProductProperty
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrProductProperty *pCurrProductProperty, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrProductProperty
	///@param	pCurrProductProperty	Ҫ��ȡ��CCurrProductProperty
	///@param	pTragetCurrProductProperty	��Ž����CCurrProductProperty
	void retrieve(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pTargetCurrProductProperty);
	
	///��ȡ��һ��CCurrProductProperty
	///@return	�õ��ĵ�һ��CCurrProductProperty�����û�У��򷵻�NULL
	CCurrProductProperty *getFirst(void);
	
	///��ȡ��һ��CCurrProductProperty
	///@return	�õ���һ��CCurrProductProperty�����û�У��򷵻�NULL
	CCurrProductProperty *getNext(void);
	
	///������ȡCCurrProductProperty
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrProductPropertyActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrProductPropertyActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrProductPropertyCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrProductPropertyCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrProductPropertyIteratorBySettlementGroupID;

	///��ʼѰ��CCurrProductProperty
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrProductProperty������Ҳ���������NULL
	CCurrProductProperty *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrProductProperty��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrProductProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrProductProperty *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrProductProperty
	///@param	ProductID	��Ʒ���
	///@return	�ҵ���CCurrProductProperty������Ҳ���������NULL
	CCurrProductProperty *findByProductID( const CReadOnlyProductIDType&  ProductID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrProductProperty���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrProductProperty	Ҫ�����CurrProductProperty
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrProductProperty *internalAdd(CWriteableCurrProductProperty *pCurrProductProperty, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrProductProperty�ļ�ֵ
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	///@param	pNewCurrProductProperty	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrProductProperty��ͬʱɾ��������
	///@param	pCurrProductProperty	Ҫɾ����CCurrProductProperty
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrProductProperty *pCurrProductProperty, bool bNoTransaction);
/*
	///���ĳ��CCurrProductProperty�Ƿ����ڱ����󹤳�
	///@param	pCurrProductProperty	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrProductProperty *pCurrProductProperty);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ProductID������
	CAVLTree *pProductIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrProductProperty *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrProductProperty	Ҫ�����CurrProductProperty
	virtual void beforeAdd(CWriteableCurrProductProperty *pCurrProductProperty);
	
	///����󴥷�
	///@param	pCurrProductProperty	�Ѿ������CurrProductProperty
	virtual void afterAdd(CCurrProductProperty *pCurrProductProperty);

	///����ǰ����	
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	///@param	pNewCurrProductProperty	�µ�ֵ
	virtual void beforeUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pNewCurrProductProperty);
	
	///���º󴥷�
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	virtual void afterUpdate(CCurrProductProperty *pCurrProductProperty);
	
	///ɾ��ǰ����
	///@param	pCurrProductProperty	Ҫɾ����CCurrProductProperty
	virtual void beforeRemove(CCurrProductProperty *pCurrProductProperty);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrProductProperty	�Ѿ������CurrProductProperty
	virtual void commitAdd(CCurrProductProperty *pCurrProductProperty);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrProductProperty	��ˢ�µ�CCurrProductProperty
	///@param	poldCurrProductProperty	ԭ����ֵ
	virtual void commitUpdate(CCurrProductProperty *pCurrProductProperty, CWriteableCurrProductProperty *pOldCurrProductProperty);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrProductProperty	�Ѿ�ɾ����CCurrProductProperty
	virtual void commitRemove(CWriteableCurrProductProperty *pCurrProductProperty);

	///������صĴ�����
	vector<CCurrProductPropertyActionTrigger *> *pActionTriggers;
	vector<CCurrProductPropertyCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrProductProperty compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentPropertyFactory��һ����Լ���ԵĶ��󹤳�����������һ����Լ���ԣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԺ�Լ���Ե���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentPropertyFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrInstrumentPropertyFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrInstrumentProperty��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrInstrumentPropertyFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrInstrumentPropertyFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrInstrumentProperty
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrInstrumentProperty���ļ��������������ļ��еĶ���CurrInstrumentPropertyCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrInstrumentProperty
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrInstrumentProperty���ļ��������������ļ��еĶ���CurrInstrumentPropertyCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrInstrumentPropertyResource;

	///��һ��CCurrInstrumentProperty���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrInstrumentProperty	Ҫ�����CurrInstrumentProperty
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrInstrumentProperty *add(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrInstrumentProperty��ֵ
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrInstrumentProperty	  ��Ҫ��ˢ�»���������CCurrInstrumentProperty,����NULL��ʾ����Ҫ������
	///@param	pNewCurrInstrumentProperty	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrInstrumentProperty* addOrUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrInstrumentProperty��ͬʱɾ��������
	///@param	pCurrInstrumentProperty	Ҫɾ����CCurrInstrumentProperty
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrInstrumentProperty *pCurrInstrumentProperty, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrInstrumentProperty
	///@param	pCurrInstrumentProperty	Ҫ��ȡ��CCurrInstrumentProperty
	///@param	pTragetCurrInstrumentProperty	��Ž����CCurrInstrumentProperty
	void retrieve(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pTargetCurrInstrumentProperty);
	
	///��ȡ��һ��CCurrInstrumentProperty
	///@return	�õ��ĵ�һ��CCurrInstrumentProperty�����û�У��򷵻�NULL
	CCurrInstrumentProperty *getFirst(void);
	
	///��ȡ��һ��CCurrInstrumentProperty
	///@return	�õ���һ��CCurrInstrumentProperty�����û�У��򷵻�NULL
	CCurrInstrumentProperty *getNext(void);
	
	///������ȡCCurrInstrumentProperty
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrInstrumentPropertyActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrInstrumentPropertyActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrInstrumentPropertyCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrInstrumentPropertyCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrInstrumentPropertyIteratorBySettlementGroupID;

	///��ʼѰ��CCurrInstrumentProperty
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrInstrumentProperty������Ҳ���������NULL
	CCurrInstrumentProperty *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrInstrumentProperty��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrInstrumentProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrInstrumentProperty *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrInstrumentProperty
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CCurrInstrumentProperty������Ҳ���������NULL
	CCurrInstrumentProperty *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrInstrumentProperty���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrInstrumentProperty	Ҫ�����CurrInstrumentProperty
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrInstrumentProperty *internalAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrInstrumentProperty�ļ�ֵ
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrInstrumentProperty��ͬʱɾ��������
	///@param	pCurrInstrumentProperty	Ҫɾ����CCurrInstrumentProperty
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrInstrumentProperty *pCurrInstrumentProperty, bool bNoTransaction);
/*
	///���ĳ��CCurrInstrumentProperty�Ƿ����ڱ����󹤳�
	///@param	pCurrInstrumentProperty	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrInstrumentProperty *pCurrInstrumentProperty);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrInstrumentProperty *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrInstrumentProperty	Ҫ�����CurrInstrumentProperty
	virtual void beforeAdd(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///����󴥷�
	///@param	pCurrInstrumentProperty	�Ѿ������CurrInstrumentProperty
	virtual void afterAdd(CCurrInstrumentProperty *pCurrInstrumentProperty);

	///����ǰ����	
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	///@param	pNewCurrInstrumentProperty	�µ�ֵ
	virtual void beforeUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pNewCurrInstrumentProperty);
	
	///���º󴥷�
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	virtual void afterUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///ɾ��ǰ����
	///@param	pCurrInstrumentProperty	Ҫɾ����CCurrInstrumentProperty
	virtual void beforeRemove(CCurrInstrumentProperty *pCurrInstrumentProperty);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrInstrumentProperty	�Ѿ������CurrInstrumentProperty
	virtual void commitAdd(CCurrInstrumentProperty *pCurrInstrumentProperty);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrInstrumentProperty	��ˢ�µ�CCurrInstrumentProperty
	///@param	poldCurrInstrumentProperty	ԭ����ֵ
	virtual void commitUpdate(CCurrInstrumentProperty *pCurrInstrumentProperty, CWriteableCurrInstrumentProperty *pOldCurrInstrumentProperty);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrInstrumentProperty	�Ѿ�ɾ����CCurrInstrumentProperty
	virtual void commitRemove(CWriteableCurrInstrumentProperty *pCurrInstrumentProperty);

	///������صĴ�����
	vector<CCurrInstrumentPropertyActionTrigger *> *pActionTriggers;
	vector<CCurrInstrumentPropertyCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrInstrumentProperty compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPriceBandingFactory��һ����ǰ�۸�󶨵Ķ��󹤳�����������һ����ǰ�۸�󶨣�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentAndSegmentIndex
///ʹ�ñ����󹤳���������ɶԵ�ǰ�۸�󶨵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentAndSegment��Ψһ�ҵ�����
///		ʹ��findByInstrumentAndOneSegment��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPriceBandingFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrPriceBandingFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrPriceBanding��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrPriceBandingFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPriceBandingFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrPriceBanding
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrPriceBanding���ļ��������������ļ��еĶ���CurrPriceBandingCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrPriceBanding
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrPriceBanding���ļ��������������ļ��еĶ���CurrPriceBandingCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrPriceBandingResource;

	///��һ��CCurrPriceBanding���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrPriceBanding	Ҫ�����CurrPriceBanding
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrPriceBanding *add(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrPriceBanding��ֵ
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	///@param	pNewCurrPriceBanding	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrPriceBanding	  ��Ҫ��ˢ�»���������CCurrPriceBanding,����NULL��ʾ����Ҫ������
	///@param	pNewCurrPriceBanding	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrPriceBanding* addOrUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrPriceBanding��ͬʱɾ��������
	///@param	pCurrPriceBanding	Ҫɾ����CCurrPriceBanding
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrPriceBanding
	///@param	pCurrPriceBanding	Ҫ��ȡ��CCurrPriceBanding
	///@param	pTragetCurrPriceBanding	��Ž����CCurrPriceBanding
	void retrieve(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pTargetCurrPriceBanding);
	
	///��ȡ��һ��CCurrPriceBanding
	///@return	�õ��ĵ�һ��CCurrPriceBanding�����û�У��򷵻�NULL
	CCurrPriceBanding *getFirst(void);
	
	///��ȡ��һ��CCurrPriceBanding
	///@return	�õ���һ��CCurrPriceBanding�����û�У��򷵻�NULL
	CCurrPriceBanding *getNext(void);
	
	///������ȡCCurrPriceBanding
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrPriceBandingActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrPriceBandingActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrPriceBandingCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrPriceBandingCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrPriceBandingIteratorBySettlementGroupID;

	///��ʼѰ��CCurrPriceBanding
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrPriceBanding������Ҳ���������NULL
	CCurrPriceBanding *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrPriceBanding��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrPriceBanding������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrPriceBanding *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrPriceBanding
	///@param	InstrumentID	��Լ����
	///@param	TradingSegmentSN	���׽׶α��
	///@return	�ҵ���CCurrPriceBanding������Ҳ���������NULL
	CCurrPriceBanding *findByInstrumentAndSegment( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);



	///Ѱ��CCurrPriceBanding
	///@param	InstrumentID	��Լ����
	///@param	TradingSegmentSN	���׽׶α��
	///@return	�ҵ���CCurrPriceBanding������Ҳ���������NULL
	CCurrPriceBanding *findByInstrumentAndOneSegment( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);

	///��������Ѱ��
	///@param	InstrumentID	��Լ����
	///@param	TradingSegmentSN	���׽׶α��
	///@return	�ҵ���CCurrPriceBanding������Ҳ���������NULL
	CCurrPriceBanding *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);
	
	///��������Ѱ��CCurrPriceBanding
	///@param	pCurrPriceBanding	Ҫ�ҵ�ֵ
	///@return	�ҵ���CCurrPriceBanding������Ҳ���������NULL
	CCurrPriceBanding *findByPK(CWriteableCurrPriceBanding *pCurrPriceBanding);

	///����������ȡCCurrPriceBanding
	///@param	pCurrPriceBanding	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CCurrPriceBanding������Ҳ���������NULL
	bool retrieveByPK(CWriteableCurrPriceBanding *pCurrPriceBanding);

	///�������������µ�CCurrPriceBanding
	///@param	pCurrPriceBanding	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CCurrPriceBanding���������ʧ�ܣ��򷵻�NULL
	CCurrPriceBanding *addByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);

	///������������CCurrPriceBanding��ֵ
	///@param	pCurrPriceBanding	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CCurrPriceBanding
	///@param	pCurrPriceBanding	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableCurrPriceBanding *pCurrPriceBanding, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrPriceBanding���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrPriceBanding	Ҫ�����CurrPriceBanding
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrPriceBanding *internalAdd(CWriteableCurrPriceBanding *pCurrPriceBanding, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrPriceBanding�ļ�ֵ
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	///@param	pNewCurrPriceBanding	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrPriceBanding��ͬʱɾ��������
	///@param	pCurrPriceBanding	Ҫɾ����CCurrPriceBanding
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrPriceBanding *pCurrPriceBanding, bool bNoTransaction);
/*
	///���ĳ��CCurrPriceBanding�Ƿ����ڱ����󹤳�
	///@param	pCurrPriceBanding	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrPriceBanding *pCurrPriceBanding);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID+TradingSegmentSN������
	CAVLTree *pInstrumentAndSegmentIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrPriceBanding *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrPriceBanding	Ҫ�����CurrPriceBanding
	virtual void beforeAdd(CWriteableCurrPriceBanding *pCurrPriceBanding);
	
	///����󴥷�
	///@param	pCurrPriceBanding	�Ѿ������CurrPriceBanding
	virtual void afterAdd(CCurrPriceBanding *pCurrPriceBanding);

	///����ǰ����	
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	///@param	pNewCurrPriceBanding	�µ�ֵ
	virtual void beforeUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pNewCurrPriceBanding);
	
	///���º󴥷�
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	virtual void afterUpdate(CCurrPriceBanding *pCurrPriceBanding);
	
	///ɾ��ǰ����
	///@param	pCurrPriceBanding	Ҫɾ����CCurrPriceBanding
	virtual void beforeRemove(CCurrPriceBanding *pCurrPriceBanding);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrPriceBanding	�Ѿ������CurrPriceBanding
	virtual void commitAdd(CCurrPriceBanding *pCurrPriceBanding);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrPriceBanding	��ˢ�µ�CCurrPriceBanding
	///@param	poldCurrPriceBanding	ԭ����ֵ
	virtual void commitUpdate(CCurrPriceBanding *pCurrPriceBanding, CWriteableCurrPriceBanding *pOldCurrPriceBanding);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrPriceBanding	�Ѿ�ɾ����CCurrPriceBanding
	virtual void commitRemove(CWriteableCurrPriceBanding *pCurrPriceBanding);

	///������صĴ�����
	vector<CCurrPriceBandingActionTrigger *> *pActionTriggers;
	vector<CCurrPriceBandingCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrPriceBanding compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateFactory��һ�������Լ��֤���ʵĶ��󹤳�����������һ�������Լ��֤���ʣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԵ����Լ��֤���ʵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentAndPart��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrMarginRateFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrMarginRate��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrMarginRateFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrMarginRateFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrMarginRate
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrMarginRate���ļ��������������ļ��еĶ���CurrMarginRateCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrMarginRate
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrMarginRate���ļ��������������ļ��еĶ���CurrMarginRateCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrMarginRateResource;

	///��һ��CCurrMarginRate���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrMarginRate	Ҫ�����CurrMarginRate
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrMarginRate *add(CWriteableCurrMarginRate *pCurrMarginRate, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrMarginRate��ֵ
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	///@param	pNewCurrMarginRate	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrMarginRate	  ��Ҫ��ˢ�»���������CCurrMarginRate,����NULL��ʾ����Ҫ������
	///@param	pNewCurrMarginRate	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrMarginRate* addOrUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrMarginRate��ͬʱɾ��������
	///@param	pCurrMarginRate	Ҫɾ����CCurrMarginRate
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrMarginRate *pCurrMarginRate, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrMarginRate
	///@param	pCurrMarginRate	Ҫ��ȡ��CCurrMarginRate
	///@param	pTragetCurrMarginRate	��Ž����CCurrMarginRate
	void retrieve(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pTargetCurrMarginRate);
	
	///��ȡ��һ��CCurrMarginRate
	///@return	�õ��ĵ�һ��CCurrMarginRate�����û�У��򷵻�NULL
	CCurrMarginRate *getFirst(void);
	
	///��ȡ��һ��CCurrMarginRate
	///@return	�õ���һ��CCurrMarginRate�����û�У��򷵻�NULL
	CCurrMarginRate *getNext(void);
	
	///������ȡCCurrMarginRate
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrMarginRateActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrMarginRateActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrMarginRateCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrMarginRateCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrMarginRateIteratorBySettlementGroupID;

	///��ʼѰ��CCurrMarginRate
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrMarginRate������Ҳ���������NULL
	CCurrMarginRate *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrMarginRate��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrMarginRate *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrMarginRate
	///@param	InstrumentID	��Լ����
	///@param	ParticipantID	��Ա����
	///@return	�ҵ���CCurrMarginRate������Ҳ���������NULL
	CCurrMarginRate *findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrMarginRate���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrMarginRate	Ҫ�����CurrMarginRate
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrMarginRate *internalAdd(CWriteableCurrMarginRate *pCurrMarginRate, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrMarginRate�ļ�ֵ
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	///@param	pNewCurrMarginRate	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrMarginRate��ͬʱɾ��������
	///@param	pCurrMarginRate	Ҫɾ����CCurrMarginRate
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrMarginRate *pCurrMarginRate, bool bNoTransaction);
/*
	///���ĳ��CCurrMarginRate�Ƿ����ڱ����󹤳�
	///@param	pCurrMarginRate	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrMarginRate *pCurrMarginRate);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrMarginRate *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrMarginRate	Ҫ�����CurrMarginRate
	virtual void beforeAdd(CWriteableCurrMarginRate *pCurrMarginRate);
	
	///����󴥷�
	///@param	pCurrMarginRate	�Ѿ������CurrMarginRate
	virtual void afterAdd(CCurrMarginRate *pCurrMarginRate);

	///����ǰ����	
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	///@param	pNewCurrMarginRate	�µ�ֵ
	virtual void beforeUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pNewCurrMarginRate);
	
	///���º󴥷�
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	virtual void afterUpdate(CCurrMarginRate *pCurrMarginRate);
	
	///ɾ��ǰ����
	///@param	pCurrMarginRate	Ҫɾ����CCurrMarginRate
	virtual void beforeRemove(CCurrMarginRate *pCurrMarginRate);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrMarginRate	�Ѿ������CurrMarginRate
	virtual void commitAdd(CCurrMarginRate *pCurrMarginRate);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrMarginRate	��ˢ�µ�CCurrMarginRate
	///@param	poldCurrMarginRate	ԭ����ֵ
	virtual void commitUpdate(CCurrMarginRate *pCurrMarginRate, CWriteableCurrMarginRate *pOldCurrMarginRate);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrMarginRate	�Ѿ�ɾ����CCurrMarginRate
	virtual void commitRemove(CWriteableCurrMarginRate *pCurrMarginRate);

	///������صĴ�����
	vector<CCurrMarginRateActionTrigger *> *pActionTriggers;
	vector<CCurrMarginRateCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrMarginRate compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrMarginRateDetailFactory��һ�������Լ��֤���ʵ���ϸ���ݵĶ��󹤳�����������һ�������Լ��֤���ʵ���ϸ���ݣ�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԵ����Լ��֤���ʵ���ϸ���ݵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentAndParticipant��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrMarginRateDetailFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrMarginRateDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrMarginRateDetail��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrMarginRateDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrMarginRateDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrMarginRateDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrMarginRateDetail���ļ��������������ļ��еĶ���CurrMarginRateDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrMarginRateDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrMarginRateDetail���ļ��������������ļ��еĶ���CurrMarginRateDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrMarginRateDetailResource;

	///��һ��CCurrMarginRateDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrMarginRateDetail	Ҫ�����CurrMarginRateDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrMarginRateDetail *add(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrMarginRateDetail��ֵ
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrMarginRateDetail	  ��Ҫ��ˢ�»���������CCurrMarginRateDetail,����NULL��ʾ����Ҫ������
	///@param	pNewCurrMarginRateDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrMarginRateDetail* addOrUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrMarginRateDetail��ͬʱɾ��������
	///@param	pCurrMarginRateDetail	Ҫɾ����CCurrMarginRateDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	Ҫ��ȡ��CCurrMarginRateDetail
	///@param	pTragetCurrMarginRateDetail	��Ž����CCurrMarginRateDetail
	void retrieve(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pTargetCurrMarginRateDetail);
	
	///��ȡ��һ��CCurrMarginRateDetail
	///@return	�õ��ĵ�һ��CCurrMarginRateDetail�����û�У��򷵻�NULL
	CCurrMarginRateDetail *getFirst(void);
	
	///��ȡ��һ��CCurrMarginRateDetail
	///@return	�õ���һ��CCurrMarginRateDetail�����û�У��򷵻�NULL
	CCurrMarginRateDetail *getNext(void);
	
	///������ȡCCurrMarginRateDetail
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrMarginRateDetailActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrMarginRateDetailActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrMarginRateDetailCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrMarginRateDetailCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrMarginRateDetailIteratorBySettlementGroupID;

	///��ʼѰ��CCurrMarginRateDetail
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrMarginRateDetail������Ҳ���������NULL
	CCurrMarginRateDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrMarginRateDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrMarginRateDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrMarginRateDetail *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrMarginRateDetail
	///@param	InstrumentID	��Լ����
	///@param	ParticipantID	��Ա���
	///@param	TradingRole	���׽�ɫ
	///@param	HedgeFlag	Ͷ���ױ���־
	///@return	�ҵ���CCurrMarginRateDetail������Ҳ���������NULL
	CCurrMarginRateDetail *findByInstrumentAndParticipant( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlyHedgeFlagType&  HedgeFlag);

	///��������Ѱ��
	///@param	InstrumentID	��Լ����
	///@param	ParticipantID	��Ա���
	///@param	TradingRole	���׽�ɫ
	///@param	HedgeFlag	Ͷ���ױ���־
	///@return	�ҵ���CCurrMarginRateDetail������Ҳ���������NULL
	CCurrMarginRateDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyTradingRoleType&  TradingRole,  const CReadOnlyHedgeFlagType&  HedgeFlag);
	
	///��������Ѱ��CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	Ҫ�ҵ�ֵ
	///@return	�ҵ���CCurrMarginRateDetail������Ҳ���������NULL
	CCurrMarginRateDetail *findByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);

	///����������ȡCCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CCurrMarginRateDetail������Ҳ���������NULL
	bool retrieveByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);

	///�������������µ�CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CCurrMarginRateDetail���������ʧ�ܣ��򷵻�NULL
	CCurrMarginRateDetail *addByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);

	///������������CCurrMarginRateDetail��ֵ
	///@param	pCurrMarginRateDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CCurrMarginRateDetail
	///@param	pCurrMarginRateDetail	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrMarginRateDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrMarginRateDetail	Ҫ�����CurrMarginRateDetail
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrMarginRateDetail *internalAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrMarginRateDetail�ļ�ֵ
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrMarginRateDetail��ͬʱɾ��������
	///@param	pCurrMarginRateDetail	Ҫɾ����CCurrMarginRateDetail
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrMarginRateDetail *pCurrMarginRateDetail, bool bNoTransaction);
/*
	///���ĳ��CCurrMarginRateDetail�Ƿ����ڱ����󹤳�
	///@param	pCurrMarginRateDetail	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrMarginRateDetail *pCurrMarginRateDetail);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����InstrumentAndParticipant��hash����
	CHashIndex *pInstrumentAndParticipantHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrMarginRateDetail *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrMarginRateDetail	Ҫ�����CurrMarginRateDetail
	virtual void beforeAdd(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///����󴥷�
	///@param	pCurrMarginRateDetail	�Ѿ������CurrMarginRateDetail
	virtual void afterAdd(CCurrMarginRateDetail *pCurrMarginRateDetail);

	///����ǰ����	
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	///@param	pNewCurrMarginRateDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pNewCurrMarginRateDetail);
	
	///���º󴥷�
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	virtual void afterUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///ɾ��ǰ����
	///@param	pCurrMarginRateDetail	Ҫɾ����CCurrMarginRateDetail
	virtual void beforeRemove(CCurrMarginRateDetail *pCurrMarginRateDetail);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrMarginRateDetail	�Ѿ������CurrMarginRateDetail
	virtual void commitAdd(CCurrMarginRateDetail *pCurrMarginRateDetail);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrMarginRateDetail	��ˢ�µ�CCurrMarginRateDetail
	///@param	poldCurrMarginRateDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrMarginRateDetail *pCurrMarginRateDetail, CWriteableCurrMarginRateDetail *pOldCurrMarginRateDetail);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrMarginRateDetail	�Ѿ�ɾ����CCurrMarginRateDetail
	virtual void commitRemove(CWriteableCurrMarginRateDetail *pCurrMarginRateDetail);

	///������صĴ�����
	vector<CCurrMarginRateDetailActionTrigger *> *pActionTriggers;
	vector<CCurrMarginRateDetailCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrMarginRateDetail compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitFactory��һ����ǰ��Ա��Լ�޲ֵĶ��󹤳�����������һ����ǰ��Ա��Լ�޲֣�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԵ�ǰ��Ա��Լ�޲ֵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentAndPart��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrPartPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrPartPosiLimit��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrPartPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPartPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrPartPosiLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrPartPosiLimit���ļ��������������ļ��еĶ���CurrPartPosiLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrPartPosiLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrPartPosiLimit���ļ��������������ļ��еĶ���CurrPartPosiLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrPartPosiLimitResource;

	///��һ��CCurrPartPosiLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrPartPosiLimit	Ҫ�����CurrPartPosiLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrPartPosiLimit *add(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrPartPosiLimit��ֵ
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrPartPosiLimit	  ��Ҫ��ˢ�»���������CCurrPartPosiLimit,����NULL��ʾ����Ҫ������
	///@param	pNewCurrPartPosiLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrPartPosiLimit* addOrUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrPartPosiLimit��ͬʱɾ��������
	///@param	pCurrPartPosiLimit	Ҫɾ����CCurrPartPosiLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrPartPosiLimit *pCurrPartPosiLimit, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrPartPosiLimit
	///@param	pCurrPartPosiLimit	Ҫ��ȡ��CCurrPartPosiLimit
	///@param	pTragetCurrPartPosiLimit	��Ž����CCurrPartPosiLimit
	void retrieve(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pTargetCurrPartPosiLimit);
	
	///��ȡ��һ��CCurrPartPosiLimit
	///@return	�õ��ĵ�һ��CCurrPartPosiLimit�����û�У��򷵻�NULL
	CCurrPartPosiLimit *getFirst(void);
	
	///��ȡ��һ��CCurrPartPosiLimit
	///@return	�õ���һ��CCurrPartPosiLimit�����û�У��򷵻�NULL
	CCurrPartPosiLimit *getNext(void);
	
	///������ȡCCurrPartPosiLimit
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrPartPosiLimitActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrPartPosiLimitActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrPartPosiLimitCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrPartPosiLimitCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrPartPosiLimitIteratorBySettlementGroupID;

	///��ʼѰ��CCurrPartPosiLimit
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrPartPosiLimit������Ҳ���������NULL
	CCurrPartPosiLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrPartPosiLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrPartPosiLimit *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrPartPosiLimit
	///@param	InstrumentID	��Լ����
	///@param	ParticipantID	��Ա����
	///@return	�ҵ���CCurrPartPosiLimit������Ҳ���������NULL
	CCurrPartPosiLimit *findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrPartPosiLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrPartPosiLimit	Ҫ�����CurrPartPosiLimit
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrPartPosiLimit *internalAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrPartPosiLimit�ļ�ֵ
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrPartPosiLimit��ͬʱɾ��������
	///@param	pCurrPartPosiLimit	Ҫɾ����CCurrPartPosiLimit
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrPartPosiLimit *pCurrPartPosiLimit, bool bNoTransaction);
/*
	///���ĳ��CCurrPartPosiLimit�Ƿ����ڱ����󹤳�
	///@param	pCurrPartPosiLimit	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrPartPosiLimit *pCurrPartPosiLimit);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrPartPosiLimit *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrPartPosiLimit	Ҫ�����CurrPartPosiLimit
	virtual void beforeAdd(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///����󴥷�
	///@param	pCurrPartPosiLimit	�Ѿ������CurrPartPosiLimit
	virtual void afterAdd(CCurrPartPosiLimit *pCurrPartPosiLimit);

	///����ǰ����	
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	///@param	pNewCurrPartPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pNewCurrPartPosiLimit);
	
	///���º󴥷�
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	virtual void afterUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///ɾ��ǰ����
	///@param	pCurrPartPosiLimit	Ҫɾ����CCurrPartPosiLimit
	virtual void beforeRemove(CCurrPartPosiLimit *pCurrPartPosiLimit);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrPartPosiLimit	�Ѿ������CurrPartPosiLimit
	virtual void commitAdd(CCurrPartPosiLimit *pCurrPartPosiLimit);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrPartPosiLimit	��ˢ�µ�CCurrPartPosiLimit
	///@param	poldCurrPartPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CCurrPartPosiLimit *pCurrPartPosiLimit, CWriteableCurrPartPosiLimit *pOldCurrPartPosiLimit);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrPartPosiLimit	�Ѿ�ɾ����CCurrPartPosiLimit
	virtual void commitRemove(CWriteableCurrPartPosiLimit *pCurrPartPosiLimit);

	///������صĴ�����
	vector<CCurrPartPosiLimitActionTrigger *> *pActionTriggers;
	vector<CCurrPartPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrPartPosiLimit compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrPartPosiLimitDetailFactory��һ����ǰ��Ա��Լ�޲ֵ���ϸ���ݵĶ��󹤳�����������һ����ǰ��Ա��Լ�޲ֵ���ϸ���ݣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentAndPartIndex
///ʹ�ñ����󹤳���������ɶԵ�ǰ��Ա��Լ�޲ֵ���ϸ���ݵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentAndPart��Ψһ�ҵ�����
///		ʹ��findByInstrumentPartAndStartPosition��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrPartPosiLimitDetailFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrPartPosiLimitDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrPartPosiLimitDetail��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrPartPosiLimitDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrPartPosiLimitDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrPartPosiLimitDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrPartPosiLimitDetail���ļ��������������ļ��еĶ���CurrPartPosiLimitDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrPartPosiLimitDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrPartPosiLimitDetail���ļ��������������ļ��еĶ���CurrPartPosiLimitDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrPartPosiLimitDetailResource;

	///��һ��CCurrPartPosiLimitDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrPartPosiLimitDetail	Ҫ�����CurrPartPosiLimitDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrPartPosiLimitDetail *add(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrPartPosiLimitDetail��ֵ
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrPartPosiLimitDetail	  ��Ҫ��ˢ�»���������CCurrPartPosiLimitDetail,����NULL��ʾ����Ҫ������
	///@param	pNewCurrPartPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrPartPosiLimitDetail* addOrUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrPartPosiLimitDetail��ͬʱɾ��������
	///@param	pCurrPartPosiLimitDetail	Ҫɾ����CCurrPartPosiLimitDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	Ҫ��ȡ��CCurrPartPosiLimitDetail
	///@param	pTragetCurrPartPosiLimitDetail	��Ž����CCurrPartPosiLimitDetail
	void retrieve(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pTargetCurrPartPosiLimitDetail);
	
	///��ȡ��һ��CCurrPartPosiLimitDetail
	///@return	�õ��ĵ�һ��CCurrPartPosiLimitDetail�����û�У��򷵻�NULL
	CCurrPartPosiLimitDetail *getFirst(void);
	
	///��ȡ��һ��CCurrPartPosiLimitDetail
	///@return	�õ���һ��CCurrPartPosiLimitDetail�����û�У��򷵻�NULL
	CCurrPartPosiLimitDetail *getNext(void);
	
	///������ȡCCurrPartPosiLimitDetail
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrPartPosiLimitDetailActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrPartPosiLimitDetailActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrPartPosiLimitDetailCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrPartPosiLimitDetailCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrPartPosiLimitDetailIteratorBySettlementGroupID;

	///��ʼѰ��CCurrPartPosiLimitDetail
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrPartPosiLimitDetail������Ҳ���������NULL
	CCurrPartPosiLimitDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrPartPosiLimitDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrPartPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrPartPosiLimitDetail *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrPartPosiLimitDetail
	///@param	InstrumentID	�ͻ����
	///@param	ParticipantID	��Ա���
	///@param	TradingRole	���׽�ɫ
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrPartPosiLimitDetail������Ҳ���������NULL
	CCurrPartPosiLimitDetail *findByInstrumentAndPart( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition);



	///Ѱ��CCurrPartPosiLimitDetail
	///@param	InstrumentID	�ͻ����
	///@param	ParticipantID	��Ա���
	///@param	TradingRole	���׽�ɫ
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrPartPosiLimitDetail������Ҳ���������NULL
	CCurrPartPosiLimitDetail *findByInstrumentPartAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition);

	///��������Ѱ��
	///@param	InstrumentID	�ͻ����
	///@param	ParticipantID	��Ա���
	///@param	TradingRole	���׽�ɫ
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrPartPosiLimitDetail������Ҳ���������NULL
	CCurrPartPosiLimitDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyPositionTradingRoleType&  TradingRole,  const CReadOnlyLargeVolumeType&  StartTotalPosition);
	
	///��������Ѱ��CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	Ҫ�ҵ�ֵ
	///@return	�ҵ���CCurrPartPosiLimitDetail������Ҳ���������NULL
	CCurrPartPosiLimitDetail *findByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///����������ȡCCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CCurrPartPosiLimitDetail������Ҳ���������NULL
	bool retrieveByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///�������������µ�CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CCurrPartPosiLimitDetail���������ʧ�ܣ��򷵻�NULL
	CCurrPartPosiLimitDetail *addByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);

	///������������CCurrPartPosiLimitDetail��ֵ
	///@param	pCurrPartPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CCurrPartPosiLimitDetail
	///@param	pCurrPartPosiLimitDetail	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrPartPosiLimitDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrPartPosiLimitDetail	Ҫ�����CurrPartPosiLimitDetail
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrPartPosiLimitDetail *internalAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrPartPosiLimitDetail�ļ�ֵ
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrPartPosiLimitDetail��ͬʱɾ��������
	///@param	pCurrPartPosiLimitDetail	Ҫɾ����CCurrPartPosiLimitDetail
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, bool bNoTransaction);
/*
	///���ĳ��CCurrPartPosiLimitDetail�Ƿ����ڱ����󹤳�
	///@param	pCurrPartPosiLimitDetail	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID+ParticipantID+TradingRole+StartTotalPosition������
	CAVLTree *pInstrumentAndPartIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrPartPosiLimitDetail *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrPartPosiLimitDetail	Ҫ�����CurrPartPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///����󴥷�
	///@param	pCurrPartPosiLimitDetail	�Ѿ������CurrPartPosiLimitDetail
	virtual void afterAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///����ǰ����	
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	///@param	pNewCurrPartPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pNewCurrPartPosiLimitDetail);
	
	///���º󴥷�
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	virtual void afterUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///ɾ��ǰ����
	///@param	pCurrPartPosiLimitDetail	Ҫɾ����CCurrPartPosiLimitDetail
	virtual void beforeRemove(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrPartPosiLimitDetail	�Ѿ������CurrPartPosiLimitDetail
	virtual void commitAdd(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrPartPosiLimitDetail	��ˢ�µ�CCurrPartPosiLimitDetail
	///@param	poldCurrPartPosiLimitDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail, CWriteableCurrPartPosiLimitDetail *pOldCurrPartPosiLimitDetail);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrPartPosiLimitDetail	�Ѿ�ɾ����CCurrPartPosiLimitDetail
	virtual void commitRemove(CWriteableCurrPartPosiLimitDetail *pCurrPartPosiLimitDetail);

	///������صĴ�����
	vector<CCurrPartPosiLimitDetailActionTrigger *> *pActionTriggers;
	vector<CCurrPartPosiLimitDetailCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrPartPosiLimitDetail compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitFactory��һ����ǰ�ͻ���Լ�޲ֵĶ��󹤳�����������һ����ǰ�ͻ���Լ�޲֣�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԵ�ǰ�ͻ���Լ�޲ֵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrClientPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrClientPosiLimit��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrClientPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrClientPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrClientPosiLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrClientPosiLimit���ļ��������������ļ��еĶ���CurrClientPosiLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrClientPosiLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrClientPosiLimit���ļ��������������ļ��еĶ���CurrClientPosiLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrClientPosiLimitResource;

	///��һ��CCurrClientPosiLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrClientPosiLimit	Ҫ�����CurrClientPosiLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrClientPosiLimit *add(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrClientPosiLimit��ֵ
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrClientPosiLimit	  ��Ҫ��ˢ�»���������CCurrClientPosiLimit,����NULL��ʾ����Ҫ������
	///@param	pNewCurrClientPosiLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrClientPosiLimit* addOrUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrClientPosiLimit��ͬʱɾ��������
	///@param	pCurrClientPosiLimit	Ҫɾ����CCurrClientPosiLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrClientPosiLimit *pCurrClientPosiLimit, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrClientPosiLimit
	///@param	pCurrClientPosiLimit	Ҫ��ȡ��CCurrClientPosiLimit
	///@param	pTragetCurrClientPosiLimit	��Ž����CCurrClientPosiLimit
	void retrieve(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pTargetCurrClientPosiLimit);
	
	///��ȡ��һ��CCurrClientPosiLimit
	///@return	�õ��ĵ�һ��CCurrClientPosiLimit�����û�У��򷵻�NULL
	CCurrClientPosiLimit *getFirst(void);
	
	///��ȡ��һ��CCurrClientPosiLimit
	///@return	�õ���һ��CCurrClientPosiLimit�����û�У��򷵻�NULL
	CCurrClientPosiLimit *getNext(void);
	
	///������ȡCCurrClientPosiLimit
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrClientPosiLimitActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrClientPosiLimitActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrClientPosiLimitCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrClientPosiLimitCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrClientPosiLimitIteratorBySettlementGroupID;

	///��ʼѰ��CCurrClientPosiLimit
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrClientPosiLimit������Ҳ���������NULL
	CCurrClientPosiLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrClientPosiLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrClientPosiLimit *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrClientPosiLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrClientPosiLimit	Ҫ�����CurrClientPosiLimit
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrClientPosiLimit *internalAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrClientPosiLimit�ļ�ֵ
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrClientPosiLimit��ͬʱɾ��������
	///@param	pCurrClientPosiLimit	Ҫɾ����CCurrClientPosiLimit
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrClientPosiLimit *pCurrClientPosiLimit, bool bNoTransaction);
/*
	///���ĳ��CCurrClientPosiLimit�Ƿ����ڱ����󹤳�
	///@param	pCurrClientPosiLimit	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrClientPosiLimit *pCurrClientPosiLimit);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrClientPosiLimit *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrClientPosiLimit	Ҫ�����CurrClientPosiLimit
	virtual void beforeAdd(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///����󴥷�
	///@param	pCurrClientPosiLimit	�Ѿ������CurrClientPosiLimit
	virtual void afterAdd(CCurrClientPosiLimit *pCurrClientPosiLimit);

	///����ǰ����	
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	///@param	pNewCurrClientPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pNewCurrClientPosiLimit);
	
	///���º󴥷�
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	virtual void afterUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///ɾ��ǰ����
	///@param	pCurrClientPosiLimit	Ҫɾ����CCurrClientPosiLimit
	virtual void beforeRemove(CCurrClientPosiLimit *pCurrClientPosiLimit);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrClientPosiLimit	�Ѿ������CurrClientPosiLimit
	virtual void commitAdd(CCurrClientPosiLimit *pCurrClientPosiLimit);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrClientPosiLimit	��ˢ�µ�CCurrClientPosiLimit
	///@param	poldCurrClientPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CCurrClientPosiLimit *pCurrClientPosiLimit, CWriteableCurrClientPosiLimit *pOldCurrClientPosiLimit);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrClientPosiLimit	�Ѿ�ɾ����CCurrClientPosiLimit
	virtual void commitRemove(CWriteableCurrClientPosiLimit *pCurrClientPosiLimit);

	///������صĴ�����
	vector<CCurrClientPosiLimitActionTrigger *> *pActionTriggers;
	vector<CCurrClientPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrClientPosiLimit compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrClientPosiLimitDetailFactory��һ����ǰ�ͻ���Լ�޲ֵ���ϸ���ݵĶ��󹤳�����������һ����ǰ�ͻ���Լ�޲ֵ���ϸ���ݣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentAndClientTypeIndex
///ʹ�ñ����󹤳���������ɶԵ�ǰ�ͻ���Լ�޲ֵ���ϸ���ݵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentAndClientType��Ψһ�ҵ�����
///		ʹ��findByInstrumentClientTypeAndStartPosition��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrClientPosiLimitDetailFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrClientPosiLimitDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrClientPosiLimitDetail��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrClientPosiLimitDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrClientPosiLimitDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrClientPosiLimitDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrClientPosiLimitDetail���ļ��������������ļ��еĶ���CurrClientPosiLimitDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrClientPosiLimitDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrClientPosiLimitDetail���ļ��������������ļ��еĶ���CurrClientPosiLimitDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrClientPosiLimitDetailResource;

	///��һ��CCurrClientPosiLimitDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrClientPosiLimitDetail	Ҫ�����CurrClientPosiLimitDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrClientPosiLimitDetail *add(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrClientPosiLimitDetail��ֵ
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrClientPosiLimitDetail	  ��Ҫ��ˢ�»���������CCurrClientPosiLimitDetail,����NULL��ʾ����Ҫ������
	///@param	pNewCurrClientPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrClientPosiLimitDetail* addOrUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrClientPosiLimitDetail��ͬʱɾ��������
	///@param	pCurrClientPosiLimitDetail	Ҫɾ����CCurrClientPosiLimitDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	Ҫ��ȡ��CCurrClientPosiLimitDetail
	///@param	pTragetCurrClientPosiLimitDetail	��Ž����CCurrClientPosiLimitDetail
	void retrieve(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pTargetCurrClientPosiLimitDetail);
	
	///��ȡ��һ��CCurrClientPosiLimitDetail
	///@return	�õ��ĵ�һ��CCurrClientPosiLimitDetail�����û�У��򷵻�NULL
	CCurrClientPosiLimitDetail *getFirst(void);
	
	///��ȡ��һ��CCurrClientPosiLimitDetail
	///@return	�õ���һ��CCurrClientPosiLimitDetail�����û�У��򷵻�NULL
	CCurrClientPosiLimitDetail *getNext(void);
	
	///������ȡCCurrClientPosiLimitDetail
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrClientPosiLimitDetailActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrClientPosiLimitDetailActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrClientPosiLimitDetailCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrClientPosiLimitDetailCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrClientPosiLimitDetailIteratorBySettlementGroupID;

	///��ʼѰ��CCurrClientPosiLimitDetail
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrClientPosiLimitDetail������Ҳ���������NULL
	CCurrClientPosiLimitDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrClientPosiLimitDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrClientPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrClientPosiLimitDetail *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrClientPosiLimitDetail
	///@param	InstrumentID	��Լ����
	///@param	ClientType	�ͻ�����
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrClientPosiLimitDetail������Ҳ���������NULL
	CCurrClientPosiLimitDetail *findByInstrumentAndClientType( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition);



	///Ѱ��CCurrClientPosiLimitDetail
	///@param	InstrumentID	��Լ����
	///@param	ClientType	�ͻ�����
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrClientPosiLimitDetail������Ҳ���������NULL
	CCurrClientPosiLimitDetail *findByInstrumentClientTypeAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition);

	///��������Ѱ��
	///@param	InstrumentID	��Լ����
	///@param	ClientType	�ͻ�����
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrClientPosiLimitDetail������Ҳ���������NULL
	CCurrClientPosiLimitDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientTypeType&  ClientType,  const CReadOnlyLargeVolumeType&  StartTotalPosition);
	
	///��������Ѱ��CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	Ҫ�ҵ�ֵ
	///@return	�ҵ���CCurrClientPosiLimitDetail������Ҳ���������NULL
	CCurrClientPosiLimitDetail *findByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///����������ȡCCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CCurrClientPosiLimitDetail������Ҳ���������NULL
	bool retrieveByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///�������������µ�CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CCurrClientPosiLimitDetail���������ʧ�ܣ��򷵻�NULL
	CCurrClientPosiLimitDetail *addByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);

	///������������CCurrClientPosiLimitDetail��ֵ
	///@param	pCurrClientPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CCurrClientPosiLimitDetail
	///@param	pCurrClientPosiLimitDetail	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrClientPosiLimitDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrClientPosiLimitDetail	Ҫ�����CurrClientPosiLimitDetail
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrClientPosiLimitDetail *internalAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrClientPosiLimitDetail�ļ�ֵ
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrClientPosiLimitDetail��ͬʱɾ��������
	///@param	pCurrClientPosiLimitDetail	Ҫɾ����CCurrClientPosiLimitDetail
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, bool bNoTransaction);
/*
	///���ĳ��CCurrClientPosiLimitDetail�Ƿ����ڱ����󹤳�
	///@param	pCurrClientPosiLimitDetail	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID+ClientType+StartTotalPosition������
	CAVLTree *pInstrumentAndClientTypeIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrClientPosiLimitDetail *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrClientPosiLimitDetail	Ҫ�����CurrClientPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///����󴥷�
	///@param	pCurrClientPosiLimitDetail	�Ѿ������CurrClientPosiLimitDetail
	virtual void afterAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///����ǰ����	
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	///@param	pNewCurrClientPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pNewCurrClientPosiLimitDetail);
	
	///���º󴥷�
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	virtual void afterUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///ɾ��ǰ����
	///@param	pCurrClientPosiLimitDetail	Ҫɾ����CCurrClientPosiLimitDetail
	virtual void beforeRemove(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrClientPosiLimitDetail	�Ѿ������CurrClientPosiLimitDetail
	virtual void commitAdd(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrClientPosiLimitDetail	��ˢ�µ�CCurrClientPosiLimitDetail
	///@param	poldCurrClientPosiLimitDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail, CWriteableCurrClientPosiLimitDetail *pOldCurrClientPosiLimitDetail);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrClientPosiLimitDetail	�Ѿ�ɾ����CCurrClientPosiLimitDetail
	virtual void commitRemove(CWriteableCurrClientPosiLimitDetail *pCurrClientPosiLimitDetail);

	///������صĴ�����
	vector<CCurrClientPosiLimitDetailActionTrigger *> *pActionTriggers;
	vector<CCurrClientPosiLimitDetailCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrClientPosiLimitDetail compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitFactory��һ����ǰ����ͻ���Լ�޲ֵĶ��󹤳�����������һ����ǰ����ͻ���Լ�޲֣�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԵ�ǰ����ͻ���Լ�޲ֵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrSpecialPosiLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrSpecialPosiLimit��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrSpecialPosiLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrSpecialPosiLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrSpecialPosiLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrSpecialPosiLimit���ļ��������������ļ��еĶ���CurrSpecialPosiLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrSpecialPosiLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrSpecialPosiLimit���ļ��������������ļ��еĶ���CurrSpecialPosiLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrSpecialPosiLimitResource;

	///��һ��CCurrSpecialPosiLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrSpecialPosiLimit	Ҫ�����CurrSpecialPosiLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrSpecialPosiLimit *add(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrSpecialPosiLimit��ֵ
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrSpecialPosiLimit	  ��Ҫ��ˢ�»���������CCurrSpecialPosiLimit,����NULL��ʾ����Ҫ������
	///@param	pNewCurrSpecialPosiLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrSpecialPosiLimit* addOrUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrSpecialPosiLimit��ͬʱɾ��������
	///@param	pCurrSpecialPosiLimit	Ҫɾ����CCurrSpecialPosiLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrSpecialPosiLimit
	///@param	pCurrSpecialPosiLimit	Ҫ��ȡ��CCurrSpecialPosiLimit
	///@param	pTragetCurrSpecialPosiLimit	��Ž����CCurrSpecialPosiLimit
	void retrieve(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pTargetCurrSpecialPosiLimit);
	
	///��ȡ��һ��CCurrSpecialPosiLimit
	///@return	�õ��ĵ�һ��CCurrSpecialPosiLimit�����û�У��򷵻�NULL
	CCurrSpecialPosiLimit *getFirst(void);
	
	///��ȡ��һ��CCurrSpecialPosiLimit
	///@return	�õ���һ��CCurrSpecialPosiLimit�����û�У��򷵻�NULL
	CCurrSpecialPosiLimit *getNext(void);
	
	///������ȡCCurrSpecialPosiLimit
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrSpecialPosiLimitActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrSpecialPosiLimitActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrSpecialPosiLimitCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrSpecialPosiLimitCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrSpecialPosiLimitIteratorBySettlementGroupID;

	///��ʼѰ��CCurrSpecialPosiLimit
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrSpecialPosiLimit������Ҳ���������NULL
	CCurrSpecialPosiLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrSpecialPosiLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrSpecialPosiLimit *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrSpecialPosiLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrSpecialPosiLimit	Ҫ�����CurrSpecialPosiLimit
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrSpecialPosiLimit *internalAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrSpecialPosiLimit�ļ�ֵ
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrSpecialPosiLimit��ͬʱɾ��������
	///@param	pCurrSpecialPosiLimit	Ҫɾ����CCurrSpecialPosiLimit
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, bool bNoTransaction);
/*
	///���ĳ��CCurrSpecialPosiLimit�Ƿ����ڱ����󹤳�
	///@param	pCurrSpecialPosiLimit	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrSpecialPosiLimit *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrSpecialPosiLimit	Ҫ�����CurrSpecialPosiLimit
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///����󴥷�
	///@param	pCurrSpecialPosiLimit	�Ѿ������CurrSpecialPosiLimit
	virtual void afterAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///����ǰ����	
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	///@param	pNewCurrSpecialPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pNewCurrSpecialPosiLimit);
	
	///���º󴥷�
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	virtual void afterUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///ɾ��ǰ����
	///@param	pCurrSpecialPosiLimit	Ҫɾ����CCurrSpecialPosiLimit
	virtual void beforeRemove(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrSpecialPosiLimit	�Ѿ������CurrSpecialPosiLimit
	virtual void commitAdd(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrSpecialPosiLimit	��ˢ�µ�CCurrSpecialPosiLimit
	///@param	poldCurrSpecialPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CCurrSpecialPosiLimit *pCurrSpecialPosiLimit, CWriteableCurrSpecialPosiLimit *pOldCurrSpecialPosiLimit);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrSpecialPosiLimit	�Ѿ�ɾ����CCurrSpecialPosiLimit
	virtual void commitRemove(CWriteableCurrSpecialPosiLimit *pCurrSpecialPosiLimit);

	///������صĴ�����
	vector<CCurrSpecialPosiLimitActionTrigger *> *pActionTriggers;
	vector<CCurrSpecialPosiLimitCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrSpecialPosiLimit compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrSpecialPosiLimitDetailFactory��һ����ǰ����ͻ���Լ�޲ֵ���ϸ���ݵĶ��󹤳�����������һ����ǰ����ͻ���Լ�޲ֵ���ϸ���ݣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentAndClientIndex
///ʹ�ñ����󹤳���������ɶԵ�ǰ����ͻ���Լ�޲ֵ���ϸ���ݵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentAndClient��Ψһ�ҵ�����
///		ʹ��findByInstrumentClientAndStartPosition��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrSpecialPosiLimitDetailFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrSpecialPosiLimitDetailFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrSpecialPosiLimitDetail��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrSpecialPosiLimitDetailFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrSpecialPosiLimitDetailFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrSpecialPosiLimitDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrSpecialPosiLimitDetail���ļ��������������ļ��еĶ���CurrSpecialPosiLimitDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrSpecialPosiLimitDetail
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrSpecialPosiLimitDetail���ļ��������������ļ��еĶ���CurrSpecialPosiLimitDetailCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrSpecialPosiLimitDetailResource;

	///��һ��CCurrSpecialPosiLimitDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrSpecialPosiLimitDetail	Ҫ�����CurrSpecialPosiLimitDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrSpecialPosiLimitDetail *add(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrSpecialPosiLimitDetail��ֵ
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrSpecialPosiLimitDetail	  ��Ҫ��ˢ�»���������CCurrSpecialPosiLimitDetail,����NULL��ʾ����Ҫ������
	///@param	pNewCurrSpecialPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrSpecialPosiLimitDetail* addOrUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrSpecialPosiLimitDetail��ͬʱɾ��������
	///@param	pCurrSpecialPosiLimitDetail	Ҫɾ����CCurrSpecialPosiLimitDetail
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	Ҫ��ȡ��CCurrSpecialPosiLimitDetail
	///@param	pTragetCurrSpecialPosiLimitDetail	��Ž����CCurrSpecialPosiLimitDetail
	void retrieve(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pTargetCurrSpecialPosiLimitDetail);
	
	///��ȡ��һ��CCurrSpecialPosiLimitDetail
	///@return	�õ��ĵ�һ��CCurrSpecialPosiLimitDetail�����û�У��򷵻�NULL
	CCurrSpecialPosiLimitDetail *getFirst(void);
	
	///��ȡ��һ��CCurrSpecialPosiLimitDetail
	///@return	�õ���һ��CCurrSpecialPosiLimitDetail�����û�У��򷵻�NULL
	CCurrSpecialPosiLimitDetail *getNext(void);
	
	///������ȡCCurrSpecialPosiLimitDetail
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrSpecialPosiLimitDetailActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrSpecialPosiLimitDetailActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrSpecialPosiLimitDetailCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrSpecialPosiLimitDetailCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrSpecialPosiLimitDetailIteratorBySettlementGroupID;

	///��ʼѰ��CCurrSpecialPosiLimitDetail
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrSpecialPosiLimitDetail������Ҳ���������NULL
	CCurrSpecialPosiLimitDetail *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrSpecialPosiLimitDetail��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrSpecialPosiLimitDetail������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrSpecialPosiLimitDetail *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrSpecialPosiLimitDetail
	///@param	InstrumentID	��Լ����
	///@param	ClientID	�ͻ����
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrSpecialPosiLimitDetail������Ҳ���������NULL
	CCurrSpecialPosiLimitDetail *findByInstrumentAndClient( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition);



	///Ѱ��CCurrSpecialPosiLimitDetail
	///@param	InstrumentID	��Լ����
	///@param	ClientID	�ͻ����
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrSpecialPosiLimitDetail������Ҳ���������NULL
	CCurrSpecialPosiLimitDetail *findByInstrumentClientAndStartPosition( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition);

	///��������Ѱ��
	///@param	InstrumentID	��Լ����
	///@param	ClientID	�ͻ����
	///@param	StartTotalPosition	��ʼ�ֲܳ�
	///@return	�ҵ���CCurrSpecialPosiLimitDetail������Ҳ���������NULL
	CCurrSpecialPosiLimitDetail *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyLargeVolumeType&  StartTotalPosition);
	
	///��������Ѱ��CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	Ҫ�ҵ�ֵ
	///@return	�ҵ���CCurrSpecialPosiLimitDetail������Ҳ���������NULL
	CCurrSpecialPosiLimitDetail *findByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///����������ȡCCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CCurrSpecialPosiLimitDetail������Ҳ���������NULL
	bool retrieveByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///�������������µ�CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CCurrSpecialPosiLimitDetail���������ʧ�ܣ��򷵻�NULL
	CCurrSpecialPosiLimitDetail *addByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);

	///������������CCurrSpecialPosiLimitDetail��ֵ
	///@param	pCurrSpecialPosiLimitDetail	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CCurrSpecialPosiLimitDetail
	///@param	pCurrSpecialPosiLimitDetail	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrSpecialPosiLimitDetail���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrSpecialPosiLimitDetail	Ҫ�����CurrSpecialPosiLimitDetail
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrSpecialPosiLimitDetail *internalAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrSpecialPosiLimitDetail�ļ�ֵ
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrSpecialPosiLimitDetail��ͬʱɾ��������
	///@param	pCurrSpecialPosiLimitDetail	Ҫɾ����CCurrSpecialPosiLimitDetail
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, bool bNoTransaction);
/*
	///���ĳ��CCurrSpecialPosiLimitDetail�Ƿ����ڱ����󹤳�
	///@param	pCurrSpecialPosiLimitDetail	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID+ClientID+StartTotalPosition������
	CAVLTree *pInstrumentAndClientIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrSpecialPosiLimitDetail *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrSpecialPosiLimitDetail	Ҫ�����CurrSpecialPosiLimitDetail
	virtual void beforeAdd(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///����󴥷�
	///@param	pCurrSpecialPosiLimitDetail	�Ѿ������CurrSpecialPosiLimitDetail
	virtual void afterAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///����ǰ����	
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	///@param	pNewCurrSpecialPosiLimitDetail	�µ�ֵ
	virtual void beforeUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pNewCurrSpecialPosiLimitDetail);
	
	///���º󴥷�
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	virtual void afterUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///ɾ��ǰ����
	///@param	pCurrSpecialPosiLimitDetail	Ҫɾ����CCurrSpecialPosiLimitDetail
	virtual void beforeRemove(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrSpecialPosiLimitDetail	�Ѿ������CurrSpecialPosiLimitDetail
	virtual void commitAdd(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrSpecialPosiLimitDetail	��ˢ�µ�CCurrSpecialPosiLimitDetail
	///@param	poldCurrSpecialPosiLimitDetail	ԭ����ֵ
	virtual void commitUpdate(CCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail, CWriteableCurrSpecialPosiLimitDetail *pOldCurrSpecialPosiLimitDetail);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrSpecialPosiLimitDetail	�Ѿ�ɾ����CCurrSpecialPosiLimitDetail
	virtual void commitRemove(CWriteableCurrSpecialPosiLimitDetail *pCurrSpecialPosiLimitDetail);

	///������صĴ�����
	vector<CCurrSpecialPosiLimitDetailActionTrigger *> *pActionTriggers;
	vector<CCurrSpecialPosiLimitDetailCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrSpecialPosiLimitDetail compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrHedgeRuleFactory��һ����ǰ��Լ���ڱ�ֵ���ԵĶ��󹤳�����������һ����ǰ��Լ���ڱ�ֵ���ԣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԵ�ǰ��Լ���ڱ�ֵ���Ե���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrHedgeRuleFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrHedgeRuleFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrHedgeRule��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrHedgeRuleFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrHedgeRuleFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrHedgeRule
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrHedgeRule���ļ��������������ļ��еĶ���CurrHedgeRuleCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrHedgeRule
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrHedgeRule���ļ��������������ļ��еĶ���CurrHedgeRuleCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrHedgeRuleResource;

	///��һ��CCurrHedgeRule���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrHedgeRule	Ҫ�����CurrHedgeRule
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrHedgeRule *add(CWriteableCurrHedgeRule *pCurrHedgeRule, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrHedgeRule��ֵ
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	///@param	pNewCurrHedgeRule	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrHedgeRule	  ��Ҫ��ˢ�»���������CCurrHedgeRule,����NULL��ʾ����Ҫ������
	///@param	pNewCurrHedgeRule	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrHedgeRule* addOrUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrHedgeRule��ͬʱɾ��������
	///@param	pCurrHedgeRule	Ҫɾ����CCurrHedgeRule
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrHedgeRule *pCurrHedgeRule, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrHedgeRule
	///@param	pCurrHedgeRule	Ҫ��ȡ��CCurrHedgeRule
	///@param	pTragetCurrHedgeRule	��Ž����CCurrHedgeRule
	void retrieve(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pTargetCurrHedgeRule);
	
	///��ȡ��һ��CCurrHedgeRule
	///@return	�õ��ĵ�һ��CCurrHedgeRule�����û�У��򷵻�NULL
	CCurrHedgeRule *getFirst(void);
	
	///��ȡ��һ��CCurrHedgeRule
	///@return	�õ���һ��CCurrHedgeRule�����û�У��򷵻�NULL
	CCurrHedgeRule *getNext(void);
	
	///������ȡCCurrHedgeRule
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrHedgeRuleActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrHedgeRuleActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrHedgeRuleCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrHedgeRuleCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrHedgeRuleIteratorBySettlementGroupID;

	///��ʼѰ��CCurrHedgeRule
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrHedgeRule������Ҳ���������NULL
	CCurrHedgeRule *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrHedgeRule��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrHedgeRule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrHedgeRule *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrHedgeRule
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CCurrHedgeRule������Ҳ���������NULL
	CCurrHedgeRule *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrHedgeRule���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrHedgeRule	Ҫ�����CurrHedgeRule
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrHedgeRule *internalAdd(CWriteableCurrHedgeRule *pCurrHedgeRule, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrHedgeRule�ļ�ֵ
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	///@param	pNewCurrHedgeRule	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrHedgeRule��ͬʱɾ��������
	///@param	pCurrHedgeRule	Ҫɾ����CCurrHedgeRule
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrHedgeRule *pCurrHedgeRule, bool bNoTransaction);
/*
	///���ĳ��CCurrHedgeRule�Ƿ����ڱ����󹤳�
	///@param	pCurrHedgeRule	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrHedgeRule *pCurrHedgeRule);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrHedgeRule *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrHedgeRule	Ҫ�����CurrHedgeRule
	virtual void beforeAdd(CWriteableCurrHedgeRule *pCurrHedgeRule);
	
	///����󴥷�
	///@param	pCurrHedgeRule	�Ѿ������CurrHedgeRule
	virtual void afterAdd(CCurrHedgeRule *pCurrHedgeRule);

	///����ǰ����	
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	///@param	pNewCurrHedgeRule	�µ�ֵ
	virtual void beforeUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pNewCurrHedgeRule);
	
	///���º󴥷�
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	virtual void afterUpdate(CCurrHedgeRule *pCurrHedgeRule);
	
	///ɾ��ǰ����
	///@param	pCurrHedgeRule	Ҫɾ����CCurrHedgeRule
	virtual void beforeRemove(CCurrHedgeRule *pCurrHedgeRule);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrHedgeRule	�Ѿ������CurrHedgeRule
	virtual void commitAdd(CCurrHedgeRule *pCurrHedgeRule);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrHedgeRule	��ˢ�µ�CCurrHedgeRule
	///@param	poldCurrHedgeRule	ԭ����ֵ
	virtual void commitUpdate(CCurrHedgeRule *pCurrHedgeRule, CWriteableCurrHedgeRule *pOldCurrHedgeRule);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrHedgeRule	�Ѿ�ɾ����CCurrHedgeRule
	virtual void commitRemove(CWriteableCurrHedgeRule *pCurrHedgeRule);

	///������صĴ�����
	vector<CCurrHedgeRuleActionTrigger *> *pActionTriggers;
	vector<CCurrHedgeRuleCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrHedgeRule compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrTradingSegmentAttrFactory��һ����ǰ��Լ���׽׶����ԵĶ��󹤳�����������һ����ǰ��Լ���׽׶����ԣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	TimeIndex
///	InstrumentIndex
///ʹ�ñ����󹤳���������ɶԵ�ǰ��Լ���׽׶����Ե���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��startFindByTime��findNextByTime��endFindByTime��ɲ�ѯ����
///		ʹ��startFindByInstrument��findNextByInstrument��endFindByInstrument��ɲ�ѯ����
///		ʹ��findByInstrumentAndSegement��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrTradingSegmentAttrFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrTradingSegmentAttrFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrTradingSegmentAttr��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrTradingSegmentAttrFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrTradingSegmentAttrFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrTradingSegmentAttr
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrTradingSegmentAttr���ļ��������������ļ��еĶ���CurrTradingSegmentAttrCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrTradingSegmentAttr
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrTradingSegmentAttr���ļ��������������ļ��еĶ���CurrTradingSegmentAttrCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrTradingSegmentAttrResource;

	///��һ��CCurrTradingSegmentAttr���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrTradingSegmentAttr	Ҫ�����CurrTradingSegmentAttr
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrTradingSegmentAttr *add(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrTradingSegmentAttr��ֵ
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrTradingSegmentAttr	  ��Ҫ��ˢ�»���������CCurrTradingSegmentAttr,����NULL��ʾ����Ҫ������
	///@param	pNewCurrTradingSegmentAttr	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrTradingSegmentAttr* addOrUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrTradingSegmentAttr��ͬʱɾ��������
	///@param	pCurrTradingSegmentAttr	Ҫɾ����CCurrTradingSegmentAttr
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrTradingSegmentAttr
	///@param	pCurrTradingSegmentAttr	Ҫ��ȡ��CCurrTradingSegmentAttr
	///@param	pTragetCurrTradingSegmentAttr	��Ž����CCurrTradingSegmentAttr
	void retrieve(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pTargetCurrTradingSegmentAttr);
	
	///��ȡ��һ��CCurrTradingSegmentAttr
	///@return	�õ��ĵ�һ��CCurrTradingSegmentAttr�����û�У��򷵻�NULL
	CCurrTradingSegmentAttr *getFirst(void);
	
	///��ȡ��һ��CCurrTradingSegmentAttr
	///@return	�õ���һ��CCurrTradingSegmentAttr�����û�У��򷵻�NULL
	CCurrTradingSegmentAttr *getNext(void);
	
	///������ȡCCurrTradingSegmentAttr
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrTradingSegmentAttrActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrTradingSegmentAttrActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrTradingSegmentAttrCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrTradingSegmentAttrCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrTradingSegmentAttrIteratorBySettlementGroupID;

	///��ʼѰ��CCurrTradingSegmentAttr
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrTradingSegmentAttr������Ҳ���������NULL
	CCurrTradingSegmentAttr *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrTradingSegmentAttr��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrTradingSegmentAttr *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	friend class CCurrTradingSegmentAttrIteratorByTime;

	///��ʼѰ��CCurrTradingSegmentAttr
	///@param	StartTime	��ʼʱ��
	///@return	���������ĵ�һ��CCurrTradingSegmentAttr������Ҳ���������NULL
	CCurrTradingSegmentAttr *startFindByTime( const CReadOnlyTimeType& StartTime);

	///Ѱ����һ������������CCurrTradingSegmentAttr��������startFindByTime�Ժ�endFindByTime֮ǰ����
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrTradingSegmentAttr *findNextByTime(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByTime(void);

	friend class CCurrTradingSegmentAttrIteratorByInstrument;

	///��ʼѰ��CCurrTradingSegmentAttr
	///@param	InstrumentID	��Լ���
	///@return	���������ĵ�һ��CCurrTradingSegmentAttr������Ҳ���������NULL
	CCurrTradingSegmentAttr *startFindByInstrument( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CCurrTradingSegmentAttr��������startFindByInstrument�Ժ�endFindByInstrument֮ǰ����
	///@return	��һ����������CCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrTradingSegmentAttr *findNextByInstrument(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByInstrument(void);

	///Ѱ��CCurrTradingSegmentAttr
	///@param	InstrumentID	��Լ���
	///@param	TradingSegmentSN	���׽׶α��
	///@return	�ҵ���CCurrTradingSegmentAttr������Ҳ���������NULL
	CCurrTradingSegmentAttr *findByInstrumentAndSegement( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyTradingSegmentSNType&  TradingSegmentSN);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrTradingSegmentAttr���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrTradingSegmentAttr	Ҫ�����CurrTradingSegmentAttr
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrTradingSegmentAttr *internalAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrTradingSegmentAttr�ļ�ֵ
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrTradingSegmentAttr��ͬʱɾ��������
	///@param	pCurrTradingSegmentAttr	Ҫɾ����CCurrTradingSegmentAttr
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, bool bNoTransaction);
/*
	///���ĳ��CCurrTradingSegmentAttr�Ƿ����ڱ����󹤳�
	///@param	pCurrTradingSegmentAttr	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����StartTime+TradingSegmentSN������
	CAVLTree *pTimeIndex;
	///����InstrumentID+TradingSegmentSN������
	CAVLTree *pInstrumentIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrTradingSegmentAttr *pLastFoundInSearchBySettlementGroupID;
	///����StartTime����ʱ���洢�Ĳ�ѯ����
	CTimeType queryStartTimeInSearchByTime;
	
	///����StartTime����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByTime;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchByInstrument;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByInstrument;
	
	///����ǰ����
	///@param	pCurrTradingSegmentAttr	Ҫ�����CurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///����󴥷�
	///@param	pCurrTradingSegmentAttr	�Ѿ������CurrTradingSegmentAttr
	virtual void afterAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///����ǰ����	
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	///@param	pNewCurrTradingSegmentAttr	�µ�ֵ
	virtual void beforeUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pNewCurrTradingSegmentAttr);
	
	///���º󴥷�
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	virtual void afterUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///ɾ��ǰ����
	///@param	pCurrTradingSegmentAttr	Ҫɾ����CCurrTradingSegmentAttr
	virtual void beforeRemove(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrTradingSegmentAttr	�Ѿ������CurrTradingSegmentAttr
	virtual void commitAdd(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrTradingSegmentAttr	��ˢ�µ�CCurrTradingSegmentAttr
	///@param	poldCurrTradingSegmentAttr	ԭ����ֵ
	virtual void commitUpdate(CCurrTradingSegmentAttr *pCurrTradingSegmentAttr, CWriteableCurrTradingSegmentAttr *pOldCurrTradingSegmentAttr);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrTradingSegmentAttr	�Ѿ�ɾ����CCurrTradingSegmentAttr
	virtual void commitRemove(CWriteableCurrTradingSegmentAttr *pCurrTradingSegmentAttr);

	///������صĴ�����
	vector<CCurrTradingSegmentAttrActionTrigger *> *pActionTriggers;
	vector<CCurrTradingSegmentAttrCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrTradingSegmentAttr compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrFuseFactory��һ����ǰ��Լ�۶����ԵĶ��󹤳�����������һ����ǰ��Լ�۶����ԣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԵ�ǰ��Լ�۶����Ե���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrFuseFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrFuseFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrFuse��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrFuseFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrFuseFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrFuse
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrFuse���ļ��������������ļ��еĶ���CurrFuseCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrFuse
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrFuse���ļ��������������ļ��еĶ���CurrFuseCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrFuseResource;

	///��һ��CCurrFuse���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrFuse	Ҫ�����CurrFuse
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrFuse *add(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrFuse��ֵ
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	///@param	pNewCurrFuse	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrFuse	  ��Ҫ��ˢ�»���������CCurrFuse,����NULL��ʾ����Ҫ������
	///@param	pNewCurrFuse	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrFuse* addOrUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrFuse��ͬʱɾ��������
	///@param	pCurrFuse	Ҫɾ����CCurrFuse
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrFuse
	///@param	pCurrFuse	Ҫ��ȡ��CCurrFuse
	///@param	pTragetCurrFuse	��Ž����CCurrFuse
	void retrieve(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pTargetCurrFuse);
	
	///��ȡ��һ��CCurrFuse
	///@return	�õ��ĵ�һ��CCurrFuse�����û�У��򷵻�NULL
	CCurrFuse *getFirst(void);
	
	///��ȡ��һ��CCurrFuse
	///@return	�õ���һ��CCurrFuse�����û�У��򷵻�NULL
	CCurrFuse *getNext(void);
	
	///������ȡCCurrFuse
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrFuseActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrFuseActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrFuseCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrFuseCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrFuseIteratorBySettlementGroupID;

	///��ʼѰ��CCurrFuse
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrFuse������Ҳ���������NULL
	CCurrFuse *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrFuse��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrFuse������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrFuse *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrFuse
	///@param	InstrumentID	��Լ���
	///@return	�ҵ���CCurrFuse������Ҳ���������NULL
	CCurrFuse *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);

	///��������Ѱ��
	///@param	InstrumentID	��Լ���
	///@return	�ҵ���CCurrFuse������Ҳ���������NULL
	CCurrFuse *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///��������Ѱ��CCurrFuse
	///@param	pCurrFuse	Ҫ�ҵ�ֵ
	///@return	�ҵ���CCurrFuse������Ҳ���������NULL
	CCurrFuse *findByPK(CWriteableCurrFuse *pCurrFuse);

	///����������ȡCCurrFuse
	///@param	pCurrFuse	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CCurrFuse������Ҳ���������NULL
	bool retrieveByPK(CWriteableCurrFuse *pCurrFuse);

	///�������������µ�CCurrFuse
	///@param	pCurrFuse	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CCurrFuse���������ʧ�ܣ��򷵻�NULL
	CCurrFuse *addByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);

	///������������CCurrFuse��ֵ
	///@param	pCurrFuse	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CCurrFuse
	///@param	pCurrFuse	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableCurrFuse *pCurrFuse, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrFuse���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrFuse	Ҫ�����CurrFuse
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrFuse *internalAdd(CWriteableCurrFuse *pCurrFuse, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrFuse�ļ�ֵ
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	///@param	pNewCurrFuse	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrFuse��ͬʱɾ��������
	///@param	pCurrFuse	Ҫɾ����CCurrFuse
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrFuse *pCurrFuse, bool bNoTransaction);
/*
	///���ĳ��CCurrFuse�Ƿ����ڱ����󹤳�
	///@param	pCurrFuse	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrFuse *pCurrFuse);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrFuse *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrFuse	Ҫ�����CurrFuse
	virtual void beforeAdd(CWriteableCurrFuse *pCurrFuse);
	
	///����󴥷�
	///@param	pCurrFuse	�Ѿ������CurrFuse
	virtual void afterAdd(CCurrFuse *pCurrFuse);

	///����ǰ����	
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	///@param	pNewCurrFuse	�µ�ֵ
	virtual void beforeUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pNewCurrFuse);
	
	///���º󴥷�
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	virtual void afterUpdate(CCurrFuse *pCurrFuse);
	
	///ɾ��ǰ����
	///@param	pCurrFuse	Ҫɾ����CCurrFuse
	virtual void beforeRemove(CCurrFuse *pCurrFuse);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrFuse	�Ѿ������CurrFuse
	virtual void commitAdd(CCurrFuse *pCurrFuse);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrFuse	��ˢ�µ�CCurrFuse
	///@param	poldCurrFuse	ԭ����ֵ
	virtual void commitUpdate(CCurrFuse *pCurrFuse, CWriteableCurrFuse *pOldCurrFuse);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrFuse	�Ѿ�ɾ����CCurrFuse
	virtual void commitRemove(CWriteableCurrFuse *pCurrFuse);

	///������صĴ�����
	vector<CCurrFuseActionTrigger *> *pActionTriggers;
	vector<CCurrFuseCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrFuse compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTradingAccountFactory��һ�������˻��Ķ��󹤳�����������һ�������˻���
///ͬʱ�ֽ����������������Է����ѯ��
///	AccountIDIndex
///ʹ�ñ����󹤳���������ɶԽ����˻�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByAccountID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradingAccountFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTradingAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxTradingAccount��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTradingAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradingAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�TradingAccount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�TradingAccount���ļ��������������ļ��еĶ���TradingAccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�TradingAccount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�TradingAccount���ļ��������������ļ��еĶ���TradingAccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CTradingAccountResource;

	///��һ��CTradingAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTradingAccount	Ҫ�����TradingAccount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTradingAccount *add(CWriteableTradingAccount *pTradingAccount, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CTradingAccount��ֵ
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	///@param	pNewTradingAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pTradingAccount	  ��Ҫ��ˢ�»���������CTradingAccount,����NULL��ʾ����Ҫ������
	///@param	pNewTradingAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CTradingAccount* addOrUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CTradingAccount��ͬʱɾ��������
	///@param	pTradingAccount	Ҫɾ����CTradingAccount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CTradingAccount *pTradingAccount, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CTradingAccount
	///@param	pTradingAccount	Ҫ��ȡ��CTradingAccount
	///@param	pTragetTradingAccount	��Ž����CTradingAccount
	void retrieve(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pTargetTradingAccount);
	
	///��ȡ��һ��CTradingAccount
	///@return	�õ��ĵ�һ��CTradingAccount�����û�У��򷵻�NULL
	CTradingAccount *getFirst(void);
	
	///��ȡ��һ��CTradingAccount
	///@return	�õ���һ��CTradingAccount�����û�У��򷵻�NULL
	CTradingAccount *getNext(void);
	
	///������ȡCTradingAccount
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CTradingAccountActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CTradingAccountActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CTradingAccountCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CTradingAccountCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�Ļ���׼�����˻���ָ��
	///@param	pFactory	�����Ӧ�Ļ���׼�����˻���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllBaseReserveAccount(CBaseReserveAccountFactory *pFactory);
	
	friend class CTradingAccountIteratorBySettlementGroupID;

	///��ʼѰ��CTradingAccount
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CTradingAccount������Ҳ���������NULL
	CTradingAccount *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CTradingAccount��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CTradingAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTradingAccount *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CTradingAccount
	///@param	AccountID	�˻�����
	///@return	�ҵ���CTradingAccount������Ҳ���������NULL
	CTradingAccount *findByAccountID( const CReadOnlyAccountIDType&  AccountID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CTradingAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTradingAccount	Ҫ�����TradingAccount
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTradingAccount *internalAdd(CWriteableTradingAccount *pTradingAccount, bool bNoTransaction);
	
	
	///ˢ�¸�CTradingAccount�ļ�ֵ
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	///@param	pNewTradingAccount	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CTradingAccount��ͬʱɾ��������
	///@param	pTradingAccount	Ҫɾ����CTradingAccount
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CTradingAccount *pTradingAccount, bool bNoTransaction);
/*
	///���ĳ��CTradingAccount�Ƿ����ڱ����󹤳�
	///@param	pTradingAccount	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CTradingAccount *pTradingAccount);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����AccountID������
	CAVLTree *pAccountIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CTradingAccount *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pTradingAccount	Ҫ�����TradingAccount
	virtual void beforeAdd(CWriteableTradingAccount *pTradingAccount);
	
	///����󴥷�
	///@param	pTradingAccount	�Ѿ������TradingAccount
	virtual void afterAdd(CTradingAccount *pTradingAccount);

	///����ǰ����	
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	///@param	pNewTradingAccount	�µ�ֵ
	virtual void beforeUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pNewTradingAccount);
	
	///���º󴥷�
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	virtual void afterUpdate(CTradingAccount *pTradingAccount);
	
	///ɾ��ǰ����
	///@param	pTradingAccount	Ҫɾ����CTradingAccount
	virtual void beforeRemove(CTradingAccount *pTradingAccount);
	
	///ȷ�ϼ���󴥷�
	///@param	pTradingAccount	�Ѿ������TradingAccount
	virtual void commitAdd(CTradingAccount *pTradingAccount);

	///ȷ�ϸ��º󴥷�
	///@param	pTradingAccount	��ˢ�µ�CTradingAccount
	///@param	poldTradingAccount	ԭ����ֵ
	virtual void commitUpdate(CTradingAccount *pTradingAccount, CWriteableTradingAccount *pOldTradingAccount);
	
	///ȷ��ɾ���󴥷�
	///@param	pTradingAccount	�Ѿ�ɾ����CTradingAccount
	virtual void commitRemove(CWriteableTradingAccount *pTradingAccount);

	///������صĴ�����
	vector<CTradingAccountActionTrigger *> *pActionTriggers;
	vector<CTradingAccountCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableTradingAccount compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CBaseReserveAccountFactory��һ������׼�����˻��Ķ��󹤳�����������һ������׼�����˻���
///ͬʱ�ֽ����������������Է����ѯ��
///	AccountIDIndex
///ʹ�ñ����󹤳���������ɶԻ���׼�����˻�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByAccountID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBaseReserveAccountFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CBaseReserveAccountFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxBaseReserveAccount��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CBaseReserveAccountFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBaseReserveAccountFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�BaseReserveAccount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�BaseReserveAccount���ļ��������������ļ��еĶ���BaseReserveAccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�BaseReserveAccount
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�BaseReserveAccount���ļ��������������ļ��еĶ���BaseReserveAccountCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CBaseReserveAccountResource;

	///��һ��CBaseReserveAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pBaseReserveAccount	Ҫ�����BaseReserveAccount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CBaseReserveAccount *add(CWriteableBaseReserveAccount *pBaseReserveAccount, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CBaseReserveAccount��ֵ
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	///@param	pNewBaseReserveAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pBaseReserveAccount	  ��Ҫ��ˢ�»���������CBaseReserveAccount,����NULL��ʾ����Ҫ������
	///@param	pNewBaseReserveAccount	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CBaseReserveAccount* addOrUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CBaseReserveAccount��ͬʱɾ��������
	///@param	pBaseReserveAccount	Ҫɾ����CBaseReserveAccount
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CBaseReserveAccount *pBaseReserveAccount, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CBaseReserveAccount
	///@param	pBaseReserveAccount	Ҫ��ȡ��CBaseReserveAccount
	///@param	pTragetBaseReserveAccount	��Ž����CBaseReserveAccount
	void retrieve(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pTargetBaseReserveAccount);
	
	///��ȡ��һ��CBaseReserveAccount
	///@return	�õ��ĵ�һ��CBaseReserveAccount�����û�У��򷵻�NULL
	CBaseReserveAccount *getFirst(void);
	
	///��ȡ��һ��CBaseReserveAccount
	///@return	�õ���һ��CBaseReserveAccount�����û�У��򷵻�NULL
	CBaseReserveAccount *getNext(void);
	
	///������ȡCBaseReserveAccount
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CBaseReserveAccountActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CBaseReserveAccountActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CBaseReserveAccountCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CBaseReserveAccountCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CBaseReserveAccountIteratorBySettlementGroupID;

	///��ʼѰ��CBaseReserveAccount
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CBaseReserveAccount������Ҳ���������NULL
	CBaseReserveAccount *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CBaseReserveAccount��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CBaseReserveAccount������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CBaseReserveAccount *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CBaseReserveAccount
	///@param	AccountID	�˻�����
	///@return	�ҵ���CBaseReserveAccount������Ҳ���������NULL
	CBaseReserveAccount *findByAccountID( const CReadOnlyAccountIDType&  AccountID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CBaseReserveAccount���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pBaseReserveAccount	Ҫ�����BaseReserveAccount
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CBaseReserveAccount *internalAdd(CWriteableBaseReserveAccount *pBaseReserveAccount, bool bNoTransaction);
	
	
	///ˢ�¸�CBaseReserveAccount�ļ�ֵ
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	///@param	pNewBaseReserveAccount	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CBaseReserveAccount��ͬʱɾ��������
	///@param	pBaseReserveAccount	Ҫɾ����CBaseReserveAccount
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CBaseReserveAccount *pBaseReserveAccount, bool bNoTransaction);
/*
	///���ĳ��CBaseReserveAccount�Ƿ����ڱ����󹤳�
	///@param	pBaseReserveAccount	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CBaseReserveAccount *pBaseReserveAccount);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����AccountID������
	CAVLTree *pAccountIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CBaseReserveAccount *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pBaseReserveAccount	Ҫ�����BaseReserveAccount
	virtual void beforeAdd(CWriteableBaseReserveAccount *pBaseReserveAccount);
	
	///����󴥷�
	///@param	pBaseReserveAccount	�Ѿ������BaseReserveAccount
	virtual void afterAdd(CBaseReserveAccount *pBaseReserveAccount);

	///����ǰ����	
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	///@param	pNewBaseReserveAccount	�µ�ֵ
	virtual void beforeUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pNewBaseReserveAccount);
	
	///���º󴥷�
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	virtual void afterUpdate(CBaseReserveAccount *pBaseReserveAccount);
	
	///ɾ��ǰ����
	///@param	pBaseReserveAccount	Ҫɾ����CBaseReserveAccount
	virtual void beforeRemove(CBaseReserveAccount *pBaseReserveAccount);
	
	///ȷ�ϼ���󴥷�
	///@param	pBaseReserveAccount	�Ѿ������BaseReserveAccount
	virtual void commitAdd(CBaseReserveAccount *pBaseReserveAccount);

	///ȷ�ϸ��º󴥷�
	///@param	pBaseReserveAccount	��ˢ�µ�CBaseReserveAccount
	///@param	poldBaseReserveAccount	ԭ����ֵ
	virtual void commitUpdate(CBaseReserveAccount *pBaseReserveAccount, CWriteableBaseReserveAccount *pOldBaseReserveAccount);
	
	///ȷ��ɾ���󴥷�
	///@param	pBaseReserveAccount	�Ѿ�ɾ����CBaseReserveAccount
	virtual void commitRemove(CWriteableBaseReserveAccount *pBaseReserveAccount);

	///������صĴ�����
	vector<CBaseReserveAccountActionTrigger *> *pActionTriggers;
	vector<CBaseReserveAccountCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableBaseReserveAccount compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CPartPositionFactory��һ����Ա�ֲֵĶ��󹤳�����������һ����Ա�ֲ֣�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIndex
///	PartInstrumentIndex
///ʹ�ñ����󹤳���������ɶԻ�Ա�ֲֵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPartAndInstrument��Ψһ�ҵ�����
///		ʹ��startFindStartByInstrument��findNextStartByInstrument��endFindStartByInstrument��ɲ�ѯ����
///		ʹ��startFindStartByParticipant��findNextStartByParticipant��endFindStartByParticipant��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CPartPositionFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartPositionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxPartPosition��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CPartPositionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CPartPositionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�PartPosition
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�PartPosition���ļ��������������ļ��еĶ���PartPositionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�PartPosition
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�PartPosition���ļ��������������ļ��еĶ���PartPositionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CPartPositionResource;

	///��һ��CPartPosition���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartPosition	Ҫ�����PartPosition
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartPosition *add(CWriteablePartPosition *pPartPosition, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CPartPosition��ֵ
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	///@param	pNewPartPosition	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pPartPosition	  ��Ҫ��ˢ�»���������CPartPosition,����NULL��ʾ����Ҫ������
	///@param	pNewPartPosition	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CPartPosition* addOrUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CPartPosition��ͬʱɾ��������
	///@param	pPartPosition	Ҫɾ����CPartPosition
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CPartPosition *pPartPosition, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CPartPosition
	///@param	pPartPosition	Ҫ��ȡ��CPartPosition
	///@param	pTragetPartPosition	��Ž����CPartPosition
	void retrieve(CPartPosition *pPartPosition, CWriteablePartPosition *pTargetPartPosition);
	
	///��ȡ��һ��CPartPosition
	///@return	�õ��ĵ�һ��CPartPosition�����û�У��򷵻�NULL
	CPartPosition *getFirst(void);
	
	///��ȡ��һ��CPartPosition
	///@return	�õ���һ��CPartPosition�����û�У��򷵻�NULL
	CPartPosition *getNext(void);
	
	///������ȡCPartPosition
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CPartPositionActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CPartPositionActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CPartPositionCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CPartPositionCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CPartPosition
	///@param	ParticipantID	��Ա��
	///@param	InstrumentID	��Լ��
	///@param	PosiDirection	��շ���
	///@param	HedgeFlag	Ͷ����־
	///@param	TradingRole	���׽�ɫ
	///@return	�ҵ���CPartPosition������Ҳ���������NULL
	CPartPosition *findByPartAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag,  const CReadOnlyTradingRoleType&  TradingRole);



	friend class CPartPositionIteratorStartByInstrument;

	///��ʼѰ��CPartPosition
	///@param	InstrumentID	��Լ��
	///@return	���������ĵ�һ��CPartPosition������Ҳ���������NULL
	CPartPosition *startFindStartByInstrument( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CPartPosition��������startFindStartByInstrument�Ժ�endFindStartByInstrument֮ǰ����
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartPosition *findNextStartByInstrument(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByInstrument(void);

	friend class CPartPositionIteratorStartByParticipant;

	///��ʼѰ��CPartPosition
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CPartPosition������Ҳ���������NULL
	CPartPosition *startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CPartPosition��������startFindStartByParticipant�Ժ�endFindStartByParticipant֮ǰ����
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartPosition *findNextStartByParticipant(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipant(void);

	friend class CPartPositionIteratorBySettlementGroupID;

	///��ʼѰ��CPartPosition
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CPartPosition������Ҳ���������NULL
	CPartPosition *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CPartPosition��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CPartPosition *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CPartPosition���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pPartPosition	Ҫ�����PartPosition
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CPartPosition *internalAdd(CWriteablePartPosition *pPartPosition, bool bNoTransaction);
	
	
	///ˢ�¸�CPartPosition�ļ�ֵ
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	///@param	pNewPartPosition	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CPartPosition��ͬʱɾ��������
	///@param	pPartPosition	Ҫɾ����CPartPosition
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CPartPosition *pPartPosition, bool bNoTransaction);
/*
	///���ĳ��CPartPosition�Ƿ����ڱ����󹤳�
	///@param	pPartPosition	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CPartPosition *pPartPosition);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID+ParticipantID+PosiDirection+HedgeFlag+TradingRole������
	CAVLTree *pInstrumentIndex;
	///����ParticipantID+InstrumentID+PosiDirection+HedgeFlag+TradingRole������
	CAVLTree *pPartInstrumentIndex;
	
	///����PartAndInstrument��hash����
	CHashIndex *pPartAndInstrumentHashIndex;
	
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrument;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByInstrument;
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipant;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipant;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CPartPosition *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pPartPosition	Ҫ�����PartPosition
	virtual void beforeAdd(CWriteablePartPosition *pPartPosition);
	
	///����󴥷�
	///@param	pPartPosition	�Ѿ������PartPosition
	virtual void afterAdd(CPartPosition *pPartPosition);

	///����ǰ����	
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	///@param	pNewPartPosition	�µ�ֵ
	virtual void beforeUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pNewPartPosition);
	
	///���º󴥷�
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	virtual void afterUpdate(CPartPosition *pPartPosition);
	
	///ɾ��ǰ����
	///@param	pPartPosition	Ҫɾ����CPartPosition
	virtual void beforeRemove(CPartPosition *pPartPosition);
	
	///ȷ�ϼ���󴥷�
	///@param	pPartPosition	�Ѿ������PartPosition
	virtual void commitAdd(CPartPosition *pPartPosition);

	///ȷ�ϸ��º󴥷�
	///@param	pPartPosition	��ˢ�µ�CPartPosition
	///@param	poldPartPosition	ԭ����ֵ
	virtual void commitUpdate(CPartPosition *pPartPosition, CWriteablePartPosition *pOldPartPosition);
	
	///ȷ��ɾ���󴥷�
	///@param	pPartPosition	�Ѿ�ɾ����CPartPosition
	virtual void commitRemove(CWriteablePartPosition *pPartPosition);

	///������صĴ�����
	vector<CPartPositionActionTrigger *> *pActionTriggers;
	vector<CPartPositionCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteablePartPosition compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClientPositionFactory��һ���ͻ��ֲֵĶ��󹤳�����������һ���ͻ��ֲ֣�
///ͬʱ�ֽ����������������Է����ѯ��
///	PartClientAndInstumentIndex
///	ClientAndInstumentIndex
///	InstumentIndex
///ʹ�ñ����󹤳���������ɶԿͻ��ֲֵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPartClientAndInstrument��Ψһ�ҵ�����
///		ʹ��startFindByClientAndInstrument��findNextByClientAndInstrument��endFindByClientAndInstrument��ɲ�ѯ����
///		ʹ��startFindStartByParticipant��findNextStartByParticipant��endFindStartByParticipant��ɲ�ѯ����
///		ʹ��startFindStartByClient��findNextStartByClient��endFindStartByClient��ɲ�ѯ����
///		ʹ��startFindStartByInstrument��findNextStartByInstrument��endFindStartByInstrument��ɲ�ѯ����
///		ʹ��startFindByInstrumentID��findNextByInstrumentID��endFindByInstrumentID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClientPositionFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientPositionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxClientPosition��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClientPositionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClientPositionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ClientPosition
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ClientPosition���ļ��������������ļ��еĶ���ClientPositionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ClientPosition
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ClientPosition���ļ��������������ļ��еĶ���ClientPositionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CClientPositionResource;

	///��һ��CClientPosition���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClientPosition	Ҫ�����ClientPosition
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClientPosition *add(CWriteableClientPosition *pClientPosition, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CClientPosition��ֵ
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	///@param	pNewClientPosition	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pClientPosition	  ��Ҫ��ˢ�»���������CClientPosition,����NULL��ʾ����Ҫ������
	///@param	pNewClientPosition	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CClientPosition* addOrUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CClientPosition��ͬʱɾ��������
	///@param	pClientPosition	Ҫɾ����CClientPosition
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CClientPosition *pClientPosition, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CClientPosition
	///@param	pClientPosition	Ҫ��ȡ��CClientPosition
	///@param	pTragetClientPosition	��Ž����CClientPosition
	void retrieve(CClientPosition *pClientPosition, CWriteableClientPosition *pTargetClientPosition);
	
	///��ȡ��һ��CClientPosition
	///@return	�õ��ĵ�һ��CClientPosition�����û�У��򷵻�NULL
	CClientPosition *getFirst(void);
	
	///��ȡ��һ��CClientPosition
	///@return	�õ���һ��CClientPosition�����û�У��򷵻�NULL
	CClientPosition *getNext(void);
	
	///������ȡCClientPosition
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CClientPositionActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CClientPositionActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CClientPositionCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CClientPositionCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�����ö�ȵ�ָ��
	///@param	pFactory	�����Ӧ�����ö�ȵ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllCreditLimit(CCreditLimitFactory *pFactory);
	
	///�������ж�Ӧ�Ļ�Ա��ɫ�ʺŵ�ָ��
	///@param	pFactory	�����Ӧ�Ļ�Ա��ɫ�ʺŵ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllPartRoleAccount(CPartRoleAccountFactory *pFactory);
	
	///Ѱ��CClientPosition
	///@param	ParticipantID	��Ա��
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	///@param	PosiDirection	��շ���
	///@param	HedgeFlag	Ͷ����־
	///@return	�ҵ���CClientPosition������Ҳ���������NULL
	CClientPosition *findByPartClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag);



	friend class CClientPositionIteratorByClientAndInstrument;

	///��ʼѰ��CClientPosition
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	///@param	PosiDirection	��շ���
	///@param	HedgeFlag	Ͷ����־
	///@return	���������ĵ�һ��CClientPosition������Ҳ���������NULL
	CClientPosition *startFindByClientAndInstrument( const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID,  const CReadOnlyPosiDirectionType& PosiDirection,  const CReadOnlyHedgeFlagType& HedgeFlag);

	///Ѱ����һ������������CClientPosition��������startFindByClientAndInstrument�Ժ�endFindByClientAndInstrument֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientPosition *findNextByClientAndInstrument(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByClientAndInstrument(void);

	friend class CClientPositionIteratorStartByParticipant;

	///��ʼѰ��CClientPosition
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CClientPosition������Ҳ���������NULL
	CClientPosition *startFindStartByParticipant( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CClientPosition��������startFindStartByParticipant�Ժ�endFindStartByParticipant֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientPosition *findNextStartByParticipant(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipant(void);

	friend class CClientPositionIteratorStartByClient;

	///��ʼѰ��CClientPosition
	///@param	ClientID	�ͻ���
	///@return	���������ĵ�һ��CClientPosition������Ҳ���������NULL
	CClientPosition *startFindStartByClient( const CReadOnlyClientIDType& ClientID);

	///Ѱ����һ������������CClientPosition��������startFindStartByClient�Ժ�endFindStartByClient֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientPosition *findNextStartByClient(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByClient(void);

	friend class CClientPositionIteratorStartByInstrument;

	///��ʼѰ��CClientPosition
	///@param	InstrumentID	��Լ��
	///@return	���������ĵ�һ��CClientPosition������Ҳ���������NULL
	CClientPosition *startFindStartByInstrument( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CClientPosition��������startFindStartByInstrument�Ժ�endFindStartByInstrument֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientPosition *findNextStartByInstrument(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByInstrument(void);

	friend class CClientPositionIteratorByInstrumentID;

	///��ʼѰ��CClientPosition
	///@param	InstrumentID	��Լ��
	///@return	���������ĵ�һ��CClientPosition������Ҳ���������NULL
	CClientPosition *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CClientPosition��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientPosition *findNextByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByInstrumentID(void);

	friend class CClientPositionIteratorBySettlementGroupID;

	///��ʼѰ��CClientPosition
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CClientPosition������Ҳ���������NULL
	CClientPosition *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CClientPosition��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClientPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClientPosition *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CClientPosition���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClientPosition	Ҫ�����ClientPosition
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClientPosition *internalAdd(CWriteableClientPosition *pClientPosition, bool bNoTransaction);
	
	
	///ˢ�¸�CClientPosition�ļ�ֵ
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	///@param	pNewClientPosition	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CClientPosition��ͬʱɾ��������
	///@param	pClientPosition	Ҫɾ����CClientPosition
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CClientPosition *pClientPosition, bool bNoTransaction);
/*
	///���ĳ��CClientPosition�Ƿ����ڱ����󹤳�
	///@param	pClientPosition	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CClientPosition *pClientPosition);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID+ClientID+InstrumentID+PosiDirection+HedgeFlag������
	CAVLTree *pPartClientAndInstumentIndex;
	///����ClientID+ParticipantID+InstrumentID+PosiDirection+HedgeFlag������
	CAVLTree *pClientAndInstumentIndex;
	///����InstrumentID+ParticipantID+ClientID+PosiDirection+HedgeFlag������
	CAVLTree *pInstumentIndex;
	
	///����ClientAndInstrument��hash����
	CHashIndex *pClientAndInstrumentHashIndex;
	
	///����ClientID��InstrumentID��PosiDirection��HedgeFlag����ʱ���洢�Ĳ�ѯ����
	CClientIDType queryClientIDInSearchByClientAndInstrument;
	CInstrumentIDType queryInstrumentIDInSearchByClientAndInstrument;
	CPosiDirectionType queryPosiDirectionInSearchByClientAndInstrument;
	CHedgeFlagType queryHedgeFlagInSearchByClientAndInstrument;
	
	///����ClientID��InstrumentID��PosiDirection��HedgeFlag����ʱ���洢���һ���ҵ��������ڵ�
	CHashIndexNode *pLastFoundInSearchByClientAndInstrument;
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipant;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipant;
	///����ClientID����ʱ���洢�Ĳ�ѯ����
	CClientIDType queryClientIDInSearchStartByClient;
	
	///����ClientID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByClient;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrument;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByInstrument;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CClientPosition *pLastFoundInSearchByInstrumentID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CClientPosition *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pClientPosition	Ҫ�����ClientPosition
	virtual void beforeAdd(CWriteableClientPosition *pClientPosition);
	
	///����󴥷�
	///@param	pClientPosition	�Ѿ������ClientPosition
	virtual void afterAdd(CClientPosition *pClientPosition);

	///����ǰ����	
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	///@param	pNewClientPosition	�µ�ֵ
	virtual void beforeUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pNewClientPosition);
	
	///���º󴥷�
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	virtual void afterUpdate(CClientPosition *pClientPosition);
	
	///ɾ��ǰ����
	///@param	pClientPosition	Ҫɾ����CClientPosition
	virtual void beforeRemove(CClientPosition *pClientPosition);
	
	///ȷ�ϼ���󴥷�
	///@param	pClientPosition	�Ѿ������ClientPosition
	virtual void commitAdd(CClientPosition *pClientPosition);

	///ȷ�ϸ��º󴥷�
	///@param	pClientPosition	��ˢ�µ�CClientPosition
	///@param	poldClientPosition	ԭ����ֵ
	virtual void commitUpdate(CClientPosition *pClientPosition, CWriteableClientPosition *pOldClientPosition);
	
	///ȷ��ɾ���󴥷�
	///@param	pClientPosition	�Ѿ�ɾ����CClientPosition
	virtual void commitRemove(CWriteableClientPosition *pClientPosition);

	///������صĴ�����
	vector<CClientPositionActionTrigger *> *pActionTriggers;
	vector<CClientPositionCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableClientPosition compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CHedgeVolumeFactory��һ����ֵ������Ķ��󹤳�����������һ����ֵ�������
///ͬʱ�ֽ����������������Է����ѯ��
///	PartClientAndInstrumentIndex
///ʹ�ñ����󹤳���������ɶԱ�ֵ���������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentPartClient��Ψһ�ҵ�����
///		ʹ��startFindStartByPartClientAndInstrument��findNextStartByPartClientAndInstrument��endFindStartByPartClientAndInstrument��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CHedgeVolumeFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CHedgeVolumeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxHedgeVolume��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CHedgeVolumeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CHedgeVolumeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�HedgeVolume
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�HedgeVolume���ļ��������������ļ��еĶ���HedgeVolumeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�HedgeVolume
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�HedgeVolume���ļ��������������ļ��еĶ���HedgeVolumeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CHedgeVolumeResource;

	///��һ��CHedgeVolume���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pHedgeVolume	Ҫ�����HedgeVolume
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CHedgeVolume *add(CWriteableHedgeVolume *pHedgeVolume, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CHedgeVolume��ֵ
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	///@param	pNewHedgeVolume	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pHedgeVolume	  ��Ҫ��ˢ�»���������CHedgeVolume,����NULL��ʾ����Ҫ������
	///@param	pNewHedgeVolume	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CHedgeVolume* addOrUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CHedgeVolume��ͬʱɾ��������
	///@param	pHedgeVolume	Ҫɾ����CHedgeVolume
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CHedgeVolume *pHedgeVolume, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CHedgeVolume
	///@param	pHedgeVolume	Ҫ��ȡ��CHedgeVolume
	///@param	pTragetHedgeVolume	��Ž����CHedgeVolume
	void retrieve(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pTargetHedgeVolume);
	
	///��ȡ��һ��CHedgeVolume
	///@return	�õ��ĵ�һ��CHedgeVolume�����û�У��򷵻�NULL
	CHedgeVolume *getFirst(void);
	
	///��ȡ��һ��CHedgeVolume
	///@return	�õ���һ��CHedgeVolume�����û�У��򷵻�NULL
	CHedgeVolume *getNext(void);
	
	///������ȡCHedgeVolume
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CHedgeVolumeActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CHedgeVolumeActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CHedgeVolumeCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CHedgeVolumeCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CHedgeVolumeIteratorBySettlementGroupID;

	///��ʼѰ��CHedgeVolume
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CHedgeVolume������Ҳ���������NULL
	CHedgeVolume *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CHedgeVolume��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CHedgeVolume *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CHedgeVolume
	///@param	InstrumentID	��Լ����
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@return	�ҵ���CHedgeVolume������Ҳ���������NULL
	CHedgeVolume *findByInstrumentPartClient( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID);



	friend class CHedgeVolumeIteratorStartByPartClientAndInstrument;

	///��ʼѰ��CHedgeVolume
	///@param	ParticipantID	��Ա���
	///@param	ClientID	�ͻ����
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CHedgeVolume������Ҳ���������NULL
	CHedgeVolume *startFindStartByPartClientAndInstrument( const CReadOnlyParticipantIDType& ParticipantID,  const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CHedgeVolume��������startFindStartByPartClientAndInstrument�Ժ�endFindStartByPartClientAndInstrument֮ǰ����
	///@return	��һ����������CHedgeVolume������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CHedgeVolume *findNextStartByPartClientAndInstrument(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByPartClientAndInstrument(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CHedgeVolume���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pHedgeVolume	Ҫ�����HedgeVolume
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CHedgeVolume *internalAdd(CWriteableHedgeVolume *pHedgeVolume, bool bNoTransaction);
	
	
	///ˢ�¸�CHedgeVolume�ļ�ֵ
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	///@param	pNewHedgeVolume	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CHedgeVolume��ͬʱɾ��������
	///@param	pHedgeVolume	Ҫɾ����CHedgeVolume
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CHedgeVolume *pHedgeVolume, bool bNoTransaction);
/*
	///���ĳ��CHedgeVolume�Ƿ����ڱ����󹤳�
	///@param	pHedgeVolume	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CHedgeVolume *pHedgeVolume);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID+ClientID+InstrumentID������
	CAVLTree *pPartClientAndInstrumentIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CHedgeVolume *pLastFoundInSearchBySettlementGroupID;
	///����ParticipantID��ClientID��InstrumentID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByPartClientAndInstrument;
	CClientIDType queryClientIDInSearchStartByPartClientAndInstrument;
	CInstrumentIDType queryInstrumentIDInSearchStartByPartClientAndInstrument;
	
	///����ParticipantID��ClientID��InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByPartClientAndInstrument;
	
	///����ǰ����
	///@param	pHedgeVolume	Ҫ�����HedgeVolume
	virtual void beforeAdd(CWriteableHedgeVolume *pHedgeVolume);
	
	///����󴥷�
	///@param	pHedgeVolume	�Ѿ������HedgeVolume
	virtual void afterAdd(CHedgeVolume *pHedgeVolume);

	///����ǰ����	
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	///@param	pNewHedgeVolume	�µ�ֵ
	virtual void beforeUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pNewHedgeVolume);
	
	///���º󴥷�
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	virtual void afterUpdate(CHedgeVolume *pHedgeVolume);
	
	///ɾ��ǰ����
	///@param	pHedgeVolume	Ҫɾ����CHedgeVolume
	virtual void beforeRemove(CHedgeVolume *pHedgeVolume);
	
	///ȷ�ϼ���󴥷�
	///@param	pHedgeVolume	�Ѿ������HedgeVolume
	virtual void commitAdd(CHedgeVolume *pHedgeVolume);

	///ȷ�ϸ��º󴥷�
	///@param	pHedgeVolume	��ˢ�µ�CHedgeVolume
	///@param	poldHedgeVolume	ԭ����ֵ
	virtual void commitUpdate(CHedgeVolume *pHedgeVolume, CWriteableHedgeVolume *pOldHedgeVolume);
	
	///ȷ��ɾ���󴥷�
	///@param	pHedgeVolume	�Ѿ�ɾ����CHedgeVolume
	virtual void commitRemove(CWriteableHedgeVolume *pHedgeVolume);

	///������صĴ�����
	vector<CHedgeVolumeActionTrigger *> *pActionTriggers;
	vector<CHedgeVolumeCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableHedgeVolume compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CRemainOrderFactory��һ����ʷ�����Ķ��󹤳�����������һ����ʷ������
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶ���ʷ��������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��startFindByInstrumentID��findNextByInstrumentID��endFindByInstrumentID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRemainOrderFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CRemainOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxRemainOrder��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CRemainOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRemainOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�RemainOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�RemainOrder���ļ��������������ļ��еĶ���RemainOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�RemainOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�RemainOrder���ļ��������������ļ��еĶ���RemainOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CRemainOrderResource;

	///��һ��CRemainOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pRemainOrder	Ҫ�����RemainOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CRemainOrder *add(CWriteableRemainOrder *pRemainOrder, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CRemainOrder��ֵ
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	///@param	pNewRemainOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pRemainOrder	  ��Ҫ��ˢ�»���������CRemainOrder,����NULL��ʾ����Ҫ������
	///@param	pNewRemainOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CRemainOrder* addOrUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CRemainOrder��ͬʱɾ��������
	///@param	pRemainOrder	Ҫɾ����CRemainOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CRemainOrder *pRemainOrder, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CRemainOrder
	///@param	pRemainOrder	Ҫ��ȡ��CRemainOrder
	///@param	pTragetRemainOrder	��Ž����CRemainOrder
	void retrieve(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pTargetRemainOrder);
	
	///��ȡ��һ��CRemainOrder
	///@return	�õ��ĵ�һ��CRemainOrder�����û�У��򷵻�NULL
	CRemainOrder *getFirst(void);
	
	///��ȡ��һ��CRemainOrder
	///@return	�õ���һ��CRemainOrder�����û�У��򷵻�NULL
	CRemainOrder *getNext(void);
	
	///������ȡCRemainOrder
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CRemainOrderActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CRemainOrderActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CRemainOrderCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CRemainOrderCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CRemainOrderIteratorBySettlementGroupID;

	///��ʼѰ��CRemainOrder
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CRemainOrder������Ҳ���������NULL
	CRemainOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CRemainOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CRemainOrder *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	friend class CRemainOrderIteratorByInstrumentID;

	///��ʼѰ��CRemainOrder
	///@param	InstrumentID	��Լ���
	///@return	���������ĵ�һ��CRemainOrder������Ҳ���������NULL
	CRemainOrder *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CRemainOrder��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������CRemainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CRemainOrder *findNextByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByInstrumentID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CRemainOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pRemainOrder	Ҫ�����RemainOrder
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CRemainOrder *internalAdd(CWriteableRemainOrder *pRemainOrder, bool bNoTransaction);
	
	
	///ˢ�¸�CRemainOrder�ļ�ֵ
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	///@param	pNewRemainOrder	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CRemainOrder��ͬʱɾ��������
	///@param	pRemainOrder	Ҫɾ����CRemainOrder
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CRemainOrder *pRemainOrder, bool bNoTransaction);
/*
	///���ĳ��CRemainOrder�Ƿ����ڱ����󹤳�
	///@param	pRemainOrder	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CRemainOrder *pRemainOrder);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CRemainOrder *pLastFoundInSearchBySettlementGroupID;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByInstrumentID;
	
	///����ǰ����
	///@param	pRemainOrder	Ҫ�����RemainOrder
	virtual void beforeAdd(CWriteableRemainOrder *pRemainOrder);
	
	///����󴥷�
	///@param	pRemainOrder	�Ѿ������RemainOrder
	virtual void afterAdd(CRemainOrder *pRemainOrder);

	///����ǰ����	
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	///@param	pNewRemainOrder	�µ�ֵ
	virtual void beforeUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pNewRemainOrder);
	
	///���º󴥷�
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	virtual void afterUpdate(CRemainOrder *pRemainOrder);
	
	///ɾ��ǰ����
	///@param	pRemainOrder	Ҫɾ����CRemainOrder
	virtual void beforeRemove(CRemainOrder *pRemainOrder);
	
	///ȷ�ϼ���󴥷�
	///@param	pRemainOrder	�Ѿ������RemainOrder
	virtual void commitAdd(CRemainOrder *pRemainOrder);

	///ȷ�ϸ��º󴥷�
	///@param	pRemainOrder	��ˢ�µ�CRemainOrder
	///@param	poldRemainOrder	ԭ����ֵ
	virtual void commitUpdate(CRemainOrder *pRemainOrder, CWriteableRemainOrder *pOldRemainOrder);
	
	///ȷ��ɾ���󴥷�
	///@param	pRemainOrder	�Ѿ�ɾ����CRemainOrder
	virtual void commitRemove(CWriteableRemainOrder *pRemainOrder);

	///������صĴ�����
	vector<CRemainOrderActionTrigger *> *pActionTriggers;
	vector<CRemainOrderCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableRemainOrder compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMarketDataFactory��һ������Ķ��󹤳�����������һ�����飬
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶ��������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMarketDataFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMarketData��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MarketData���ļ��������������ļ��еĶ���MarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MarketData���ļ��������������ļ��еĶ���MarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMarketDataResource;

	///��һ��CMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketData	Ҫ�����MarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketData *add(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMarketData��ֵ
	///@param	pMarketData	��ˢ�µ�CMarketData
	///@param	pNewMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMarketData	  ��Ҫ��ˢ�»���������CMarketData,����NULL��ʾ����Ҫ������
	///@param	pNewMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMarketData* addOrUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMarketData��ͬʱɾ��������
	///@param	pMarketData	Ҫɾ����CMarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMarketData *pMarketData, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMarketData
	///@param	pMarketData	Ҫ��ȡ��CMarketData
	///@param	pTragetMarketData	��Ž����CMarketData
	void retrieve(CMarketData *pMarketData, CWriteableMarketData *pTargetMarketData);
	
	///��ȡ��һ��CMarketData
	///@return	�õ��ĵ�һ��CMarketData�����û�У��򷵻�NULL
	CMarketData *getFirst(void);
	
	///��ȡ��һ��CMarketData
	///@return	�õ���һ��CMarketData�����û�У��򷵻�NULL
	CMarketData *getNext(void);
	
	///������ȡCMarketData
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMarketDataActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMarketDataActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMarketDataCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMarketDataCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CMarketDataIteratorBySettlementGroupID;

	///��ʼѰ��CMarketData
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CMarketData������Ҳ���������NULL
	CMarketData *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CMarketData��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMarketData *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CMarketData
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CMarketData������Ҳ���������NULL
	CMarketData *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);

	///��������Ѱ��
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CMarketData������Ҳ���������NULL
	CMarketData *findByPK( const CReadOnlyInstrumentIDType&  InstrumentID);
	
	///��������Ѱ��CMarketData
	///@param	pMarketData	Ҫ�ҵ�ֵ
	///@return	�ҵ���CMarketData������Ҳ���������NULL
	CMarketData *findByPK(CWriteableMarketData *pMarketData);

	///����������ȡCMarketData
	///@param	pMarketData	Ҫ��ȡ��ֵ��ͬʱ���ڴ�ŷ��صĽ��
	///@return	�ҵ���CMarketData������Ҳ���������NULL
	bool retrieveByPK(CWriteableMarketData *pMarketData);

	///�������������µ�CMarketData
	///@param	pMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	���ز����CMarketData���������ʧ�ܣ��򷵻�NULL
	CMarketData *addByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL);

	///������������CMarketData��ֵ
	///@param	pMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool updateByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);

	///��������ɾ��CMarketData
	///@param	pMarketData	Ҫɾ����ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	true��ʾ�ɹ���false��ʾʧ��
	bool removeByPK(CWriteableMarketData *pMarketData, CTransaction *pTransaction=NULL);


private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMarketData	Ҫ�����MarketData
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMarketData *internalAdd(CWriteableMarketData *pMarketData, bool bNoTransaction);
	
	
	///ˢ�¸�CMarketData�ļ�ֵ
	///@param	pMarketData	��ˢ�µ�CMarketData
	///@param	pNewMarketData	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMarketData��ͬʱɾ��������
	///@param	pMarketData	Ҫɾ����CMarketData
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMarketData *pMarketData, bool bNoTransaction);
/*
	///���ĳ��CMarketData�Ƿ����ڱ����󹤳�
	///@param	pMarketData	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMarketData *pMarketData);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CMarketData *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pMarketData	Ҫ�����MarketData
	virtual void beforeAdd(CWriteableMarketData *pMarketData);
	
	///����󴥷�
	///@param	pMarketData	�Ѿ������MarketData
	virtual void afterAdd(CMarketData *pMarketData);

	///����ǰ����	
	///@param	pMarketData	��ˢ�µ�CMarketData
	///@param	pNewMarketData	�µ�ֵ
	virtual void beforeUpdate(CMarketData *pMarketData, CWriteableMarketData *pNewMarketData);
	
	///���º󴥷�
	///@param	pMarketData	��ˢ�µ�CMarketData
	virtual void afterUpdate(CMarketData *pMarketData);
	
	///ɾ��ǰ����
	///@param	pMarketData	Ҫɾ����CMarketData
	virtual void beforeRemove(CMarketData *pMarketData);
	
	///ȷ�ϼ���󴥷�
	///@param	pMarketData	�Ѿ������MarketData
	virtual void commitAdd(CMarketData *pMarketData);

	///ȷ�ϸ��º󴥷�
	///@param	pMarketData	��ˢ�µ�CMarketData
	///@param	poldMarketData	ԭ����ֵ
	virtual void commitUpdate(CMarketData *pMarketData, CWriteableMarketData *pOldMarketData);
	
	///ȷ��ɾ���󴥷�
	///@param	pMarketData	�Ѿ�ɾ����CMarketData
	virtual void commitRemove(CWriteableMarketData *pMarketData);

	///������صĴ�����
	vector<CMarketDataActionTrigger *> *pActionTriggers;
	vector<CMarketDataCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMarketData compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CClearingPartPositionFactory��һ�������Ա�ֲֵĶ��󹤳�����������һ�������Ա�ֲ֣�
///ͬʱ�ֽ����������������Է����ѯ��
///ʹ�ñ����󹤳���������ɶԽ����Ա�ֲֵ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByPartAndInstrument��Ψһ�ҵ�����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CClearingPartPositionFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClearingPartPositionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxClearingPartPosition��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CClearingPartPositionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CClearingPartPositionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ClearingPartPosition
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ClearingPartPosition���ļ��������������ļ��еĶ���ClearingPartPositionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ClearingPartPosition
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ClearingPartPosition���ļ��������������ļ��еĶ���ClearingPartPositionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CClearingPartPositionResource;

	///��һ��CClearingPartPosition���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClearingPartPosition	Ҫ�����ClearingPartPosition
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClearingPartPosition *add(CWriteableClearingPartPosition *pClearingPartPosition, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CClearingPartPosition��ֵ
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	///@param	pNewClearingPartPosition	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pClearingPartPosition	  ��Ҫ��ˢ�»���������CClearingPartPosition,����NULL��ʾ����Ҫ������
	///@param	pNewClearingPartPosition	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CClearingPartPosition* addOrUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CClearingPartPosition��ͬʱɾ��������
	///@param	pClearingPartPosition	Ҫɾ����CClearingPartPosition
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CClearingPartPosition *pClearingPartPosition, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CClearingPartPosition
	///@param	pClearingPartPosition	Ҫ��ȡ��CClearingPartPosition
	///@param	pTragetClearingPartPosition	��Ž����CClearingPartPosition
	void retrieve(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pTargetClearingPartPosition);
	
	///��ȡ��һ��CClearingPartPosition
	///@return	�õ��ĵ�һ��CClearingPartPosition�����û�У��򷵻�NULL
	CClearingPartPosition *getFirst(void);
	
	///��ȡ��һ��CClearingPartPosition
	///@return	�õ���һ��CClearingPartPosition�����û�У��򷵻�NULL
	CClearingPartPosition *getNext(void);
	
	///������ȡCClearingPartPosition
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CClearingPartPositionActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CClearingPartPositionActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CClearingPartPositionCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CClearingPartPositionCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///Ѱ��CClearingPartPosition
	///@param	ParticipantID	��Ա��
	///@param	InstrumentID	��Լ��
	///@param	PosiDirection	��շ���
	///@param	HedgeFlag	Ͷ����־
	///@param	TradingRole	���׽�ɫ
	///@return	�ҵ���CClearingPartPosition������Ҳ���������NULL
	CClearingPartPosition *findByPartAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyPosiDirectionType&  PosiDirection,  const CReadOnlyHedgeFlagType&  HedgeFlag,  const CReadOnlyTradingRoleType&  TradingRole);



	friend class CClearingPartPositionIteratorBySettlementGroupID;

	///��ʼѰ��CClearingPartPosition
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CClearingPartPosition������Ҳ���������NULL
	CClearingPartPosition *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CClearingPartPosition��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CClearingPartPosition������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CClearingPartPosition *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CClearingPartPosition���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pClearingPartPosition	Ҫ�����ClearingPartPosition
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CClearingPartPosition *internalAdd(CWriteableClearingPartPosition *pClearingPartPosition, bool bNoTransaction);
	
	
	///ˢ�¸�CClearingPartPosition�ļ�ֵ
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	///@param	pNewClearingPartPosition	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CClearingPartPosition��ͬʱɾ��������
	///@param	pClearingPartPosition	Ҫɾ����CClearingPartPosition
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CClearingPartPosition *pClearingPartPosition, bool bNoTransaction);
/*
	///���ĳ��CClearingPartPosition�Ƿ����ڱ����󹤳�
	///@param	pClearingPartPosition	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CClearingPartPosition *pClearingPartPosition);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	
	///����PartAndInstrument��hash����
	CHashIndex *pPartAndInstrumentHashIndex;
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CClearingPartPosition *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pClearingPartPosition	Ҫ�����ClearingPartPosition
	virtual void beforeAdd(CWriteableClearingPartPosition *pClearingPartPosition);
	
	///����󴥷�
	///@param	pClearingPartPosition	�Ѿ������ClearingPartPosition
	virtual void afterAdd(CClearingPartPosition *pClearingPartPosition);

	///����ǰ����	
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	///@param	pNewClearingPartPosition	�µ�ֵ
	virtual void beforeUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pNewClearingPartPosition);
	
	///���º󴥷�
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	virtual void afterUpdate(CClearingPartPosition *pClearingPartPosition);
	
	///ɾ��ǰ����
	///@param	pClearingPartPosition	Ҫɾ����CClearingPartPosition
	virtual void beforeRemove(CClearingPartPosition *pClearingPartPosition);
	
	///ȷ�ϼ���󴥷�
	///@param	pClearingPartPosition	�Ѿ������ClearingPartPosition
	virtual void commitAdd(CClearingPartPosition *pClearingPartPosition);

	///ȷ�ϸ��º󴥷�
	///@param	pClearingPartPosition	��ˢ�µ�CClearingPartPosition
	///@param	poldClearingPartPosition	ԭ����ֵ
	virtual void commitUpdate(CClearingPartPosition *pClearingPartPosition, CWriteableClearingPartPosition *pOldClearingPartPosition);
	
	///ȷ��ɾ���󴥷�
	///@param	pClearingPartPosition	�Ѿ�ɾ����CClearingPartPosition
	virtual void commitRemove(CWriteableClearingPartPosition *pClearingPartPosition);

	///������صĴ�����
	vector<CClearingPartPositionActionTrigger *> *pActionTriggers;
	vector<CClearingPartPositionCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableClearingPartPosition compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CInstrumentStatusFactory��һ����Լ״̬�Ķ��󹤳�����������һ����Լ״̬��
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԺ�Լ״̬����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CInstrumentStatusFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInstrumentStatusFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxInstrumentStatus��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CInstrumentStatusFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CInstrumentStatusFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�InstrumentStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�InstrumentStatus���ļ��������������ļ��еĶ���InstrumentStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�InstrumentStatus
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�InstrumentStatus���ļ��������������ļ��еĶ���InstrumentStatusCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CInstrumentStatusResource;

	///��һ��CInstrumentStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInstrumentStatus	Ҫ�����InstrumentStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInstrumentStatus *add(CWriteableInstrumentStatus *pInstrumentStatus, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CInstrumentStatus��ֵ
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	///@param	pNewInstrumentStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pInstrumentStatus	  ��Ҫ��ˢ�»���������CInstrumentStatus,����NULL��ʾ����Ҫ������
	///@param	pNewInstrumentStatus	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CInstrumentStatus* addOrUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CInstrumentStatus��ͬʱɾ��������
	///@param	pInstrumentStatus	Ҫɾ����CInstrumentStatus
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CInstrumentStatus *pInstrumentStatus, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CInstrumentStatus
	///@param	pInstrumentStatus	Ҫ��ȡ��CInstrumentStatus
	///@param	pTragetInstrumentStatus	��Ž����CInstrumentStatus
	void retrieve(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pTargetInstrumentStatus);
	
	///��ȡ��һ��CInstrumentStatus
	///@return	�õ��ĵ�һ��CInstrumentStatus�����û�У��򷵻�NULL
	CInstrumentStatus *getFirst(void);
	
	///��ȡ��һ��CInstrumentStatus
	///@return	�õ���һ��CInstrumentStatus�����û�У��򷵻�NULL
	CInstrumentStatus *getNext(void);
	
	///������ȡCInstrumentStatus
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CInstrumentStatusActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CInstrumentStatusActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CInstrumentStatusCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CInstrumentStatusCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///�������ж�Ӧ�ļ۸�󶨵�ָ��
	///@param	pFactory	�����Ӧ�ļ۸�󶨵�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllCurrPriceBanding(CCurrPriceBandingFactory *pFactory);
	
	///�������ж�Ӧ�����鷢��״̬��ָ��
	///@param	pFactory	�����Ӧ�����鷢��״̬��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllMdPubStatus(CMdPubStatusFactory *pFactory);
	
	///Ѱ��CInstrumentStatus
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CInstrumentStatus������Ҳ���������NULL
	CInstrumentStatus *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CInstrumentStatusIteratorStartByInstrumentID;

	///��ʼѰ��CInstrumentStatus
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CInstrumentStatus������Ҳ���������NULL
	CInstrumentStatus *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CInstrumentStatus��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrumentStatus *findNextStartByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByInstrumentID(void);

	friend class CInstrumentStatusIteratorBySettlementGroupID;

	///��ʼѰ��CInstrumentStatus
	///@param	SettlementGroupID	��������
	///@return	���������ĵ�һ��CInstrumentStatus������Ҳ���������NULL
	CInstrumentStatus *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CInstrumentStatus��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CInstrumentStatus *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CInstrumentStatus���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pInstrumentStatus	Ҫ�����InstrumentStatus
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CInstrumentStatus *internalAdd(CWriteableInstrumentStatus *pInstrumentStatus, bool bNoTransaction);
	
	
	///ˢ�¸�CInstrumentStatus�ļ�ֵ
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	///@param	pNewInstrumentStatus	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CInstrumentStatus��ͬʱɾ��������
	///@param	pInstrumentStatus	Ҫɾ����CInstrumentStatus
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CInstrumentStatus *pInstrumentStatus, bool bNoTransaction);
/*
	///���ĳ��CInstrumentStatus�Ƿ����ڱ����󹤳�
	///@param	pInstrumentStatus	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CInstrumentStatus *pInstrumentStatus);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CInstrumentStatus *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pInstrumentStatus	Ҫ�����InstrumentStatus
	virtual void beforeAdd(CWriteableInstrumentStatus *pInstrumentStatus);
	
	///����󴥷�
	///@param	pInstrumentStatus	�Ѿ������InstrumentStatus
	virtual void afterAdd(CInstrumentStatus *pInstrumentStatus);

	///����ǰ����	
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	///@param	pNewInstrumentStatus	�µ�ֵ
	virtual void beforeUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pNewInstrumentStatus);
	
	///���º󴥷�
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	virtual void afterUpdate(CInstrumentStatus *pInstrumentStatus);
	
	///ɾ��ǰ����
	///@param	pInstrumentStatus	Ҫɾ����CInstrumentStatus
	virtual void beforeRemove(CInstrumentStatus *pInstrumentStatus);
	
	///ȷ�ϼ���󴥷�
	///@param	pInstrumentStatus	�Ѿ������InstrumentStatus
	virtual void commitAdd(CInstrumentStatus *pInstrumentStatus);

	///ȷ�ϸ��º󴥷�
	///@param	pInstrumentStatus	��ˢ�µ�CInstrumentStatus
	///@param	poldInstrumentStatus	ԭ����ֵ
	virtual void commitUpdate(CInstrumentStatus *pInstrumentStatus, CWriteableInstrumentStatus *pOldInstrumentStatus);
	
	///ȷ��ɾ���󴥷�
	///@param	pInstrumentStatus	�Ѿ�ɾ����CInstrumentStatus
	virtual void commitRemove(CWriteableInstrumentStatus *pInstrumentStatus);

	///������صĴ�����
	vector<CInstrumentStatusActionTrigger *> *pActionTriggers;
	vector<CInstrumentStatusCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableInstrumentStatus compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///COrderFactory��һ�������Ķ��󹤳�����������һ��������
///ͬʱ�ֽ����������������Է����ѯ��
///	ParticipantIDIndex
///	OrderLocalIDIndex
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԱ�������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByOrderID��Ψһ�ҵ�����
///		ʹ��startFindStartByParticipantID��findNextStartByParticipantID��endFindStartByParticipantID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByOrderLocalID��Ψһ�ҵ�����
///		ʹ��startFindByUserID��findNextByUserID��endFindByUserID��ɲ�ѯ����
///		ʹ��startFindByInstrumentID��findNextByInstrumentID��endFindByInstrumentID��ɲ�ѯ����
///		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COrderFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	COrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxOrder��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	COrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~COrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Order
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Order���ļ��������������ļ��еĶ���OrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Order
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Order���ļ��������������ļ��еĶ���OrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class COrderResource;

	///��һ��COrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pOrder	Ҫ�����Order
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	COrder *add(CWriteableOrder *pOrder, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�COrder��ֵ
	///@param	pOrder	��ˢ�µ�COrder
	///@param	pNewOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(COrder *pOrder, CWriteableOrder *pNewOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pOrder	  ��Ҫ��ˢ�»���������COrder,����NULL��ʾ����Ҫ������
	///@param	pNewOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	COrder* addOrUpdate(COrder *pOrder, CWriteableOrder *pNewOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��COrder��ͬʱɾ��������
	///@param	pOrder	Ҫɾ����COrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(COrder *pOrder, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��COrder
	///@param	pOrder	Ҫ��ȡ��COrder
	///@param	pTragetOrder	��Ž����COrder
	void retrieve(COrder *pOrder, CWriteableOrder *pTargetOrder);
	
	///��ȡ��һ��COrder
	///@return	�õ��ĵ�һ��COrder�����û�У��򷵻�NULL
	COrder *getFirst(void);
	
	///��ȡ��һ��COrder
	///@return	�õ���һ��COrder�����û�У��򷵻�NULL
	COrder *getNext(void);
	
	///������ȡCOrder
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(COrderActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(COrderActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(COrderCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(COrderCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///��������ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///�������ж�Ӧ�Ŀͻ��ֲֵ�ָ��
	///@param	pFactory	�����Ӧ�Ŀͻ��ֲֵ�ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllClientPosition(CClientPositionFactory *pFactory);
	
	///Ѱ��COrder
	///@param	OrderSysID	����ϵͳ���
	///@return	�ҵ���COrder������Ҳ���������NULL
	COrder *findByOrderID( const CReadOnlyOrderSysIDType&  OrderSysID);



	friend class COrderIteratorStartByParticipantID;

	///��ʼѰ��COrder
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��COrder������Ҳ���������NULL
	COrder *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������COrder��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	COrder *findNextStartByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipantID(void);

	friend class COrderIteratorBySettlementGroupID;

	///��ʼѰ��COrder
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��COrder������Ҳ���������NULL
	COrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������COrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	COrder *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��COrder
	///@param	UserID	����Ա����
	///@param	OrderLocalID	�������ر��
	///@return	�ҵ���COrder������Ҳ���������NULL
	COrder *findByOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  OrderLocalID);



	friend class COrderIteratorByUserID;

	///��ʼѰ��COrder
	///@param	UserID	����Ա����
	///@return	���������ĵ�һ��COrder������Ҳ���������NULL
	COrder *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///Ѱ����һ������������COrder��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	COrder *findNextByUserID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByUserID(void);

	friend class COrderIteratorByInstrumentID;

	///��ʼѰ��COrder
	///@param	InstrumentID	��Լ��
	///@return	���������ĵ�һ��COrder������Ҳ���������NULL
	COrder *startFindByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������COrder��������startFindByInstrumentID�Ժ�endFindByInstrumentID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	COrder *findNextByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByInstrumentID(void);

	friend class COrderIteratorStartByInstrumentID;

	///��ʼѰ��COrder
	///@param	InstrumentID	��Լ��
	///@return	���������ĵ�һ��COrder������Ҳ���������NULL
	COrder *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������COrder��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������COrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	COrder *findNextStartByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByInstrumentID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��COrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pOrder	Ҫ�����Order
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	COrder *internalAdd(CWriteableOrder *pOrder, bool bNoTransaction);
	
	
	///ˢ�¸�COrder�ļ�ֵ
	///@param	pOrder	��ˢ�µ�COrder
	///@param	pNewOrder	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(COrder *pOrder, CWriteableOrder *pNewOrder, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��COrder��ͬʱɾ��������
	///@param	pOrder	Ҫɾ����COrder
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(COrder *pOrder, bool bNoTransaction);
/*
	///���ĳ��COrder�Ƿ����ڱ����󹤳�
	///@param	pOrder	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(COrder *pOrder);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID������
	CAVLTree *pParticipantIDIndex;
	///����UserID+OrderLocalID������
	CAVLTree *pOrderLocalIDIndex;
	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	///����OrderSysID��hash����
	CHashIndex *pOrderSysIDHashIndex;
	
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	COrder *pLastFoundInSearchBySettlementGroupID;
	///����UserID����ʱ���洢�Ĳ�ѯ����
	CUserIDType queryUserIDInSearchByUserID;
	
	///����UserID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByUserID;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	COrder *pLastFoundInSearchByInstrumentID;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	
	///����ǰ����
	///@param	pOrder	Ҫ�����Order
	virtual void beforeAdd(CWriteableOrder *pOrder);
	
	///����󴥷�
	///@param	pOrder	�Ѿ������Order
	virtual void afterAdd(COrder *pOrder);

	///����ǰ����	
	///@param	pOrder	��ˢ�µ�COrder
	///@param	pNewOrder	�µ�ֵ
	virtual void beforeUpdate(COrder *pOrder, CWriteableOrder *pNewOrder);
	
	///���º󴥷�
	///@param	pOrder	��ˢ�µ�COrder
	virtual void afterUpdate(COrder *pOrder);
	
	///ɾ��ǰ����
	///@param	pOrder	Ҫɾ����COrder
	virtual void beforeRemove(COrder *pOrder);
	
	///ȷ�ϼ���󴥷�
	///@param	pOrder	�Ѿ������Order
	virtual void commitAdd(COrder *pOrder);

	///ȷ�ϸ��º󴥷�
	///@param	pOrder	��ˢ�µ�COrder
	///@param	poldOrder	ԭ����ֵ
	virtual void commitUpdate(COrder *pOrder, CWriteableOrder *pOldOrder);
	
	///ȷ��ɾ���󴥷�
	///@param	pOrder	�Ѿ�ɾ����COrder
	virtual void commitRemove(CWriteableOrder *pOrder);

	///������صĴ�����
	vector<COrderActionTrigger *> *pActionTriggers;
	vector<COrderCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableOrder compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCombOrderFactory��һ����ϱ����Ķ��󹤳�����������һ����ϱ�����
///ͬʱ�ֽ����������������Է����ѯ��
///	ParticipantIDIndex
///	CombOrderLocalIDIndex
///ʹ�ñ����󹤳���������ɶ���ϱ�������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByCombOrderID��Ψһ�ҵ�����
///		ʹ��startFindStartByParticipantID��findNextStartByParticipantID��endFindStartByParticipantID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByCombOrderLocalID��Ψһ�ҵ�����
///		ʹ��startFindByUserID��findNextByUserID��endFindByUserID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCombOrderFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCombOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCombOrder��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCombOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCombOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CombOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CombOrder���ļ��������������ļ��еĶ���CombOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CombOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CombOrder���ļ��������������ļ��еĶ���CombOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCombOrderResource;

	///��һ��CCombOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCombOrder	Ҫ�����CombOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCombOrder *add(CWriteableCombOrder *pCombOrder, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCombOrder��ֵ
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	///@param	pNewCombOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCombOrder	  ��Ҫ��ˢ�»���������CCombOrder,����NULL��ʾ����Ҫ������
	///@param	pNewCombOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCombOrder* addOrUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCombOrder��ͬʱɾ��������
	///@param	pCombOrder	Ҫɾ����CCombOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCombOrder *pCombOrder, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCombOrder
	///@param	pCombOrder	Ҫ��ȡ��CCombOrder
	///@param	pTragetCombOrder	��Ž����CCombOrder
	void retrieve(CCombOrder *pCombOrder, CWriteableCombOrder *pTargetCombOrder);
	
	///��ȡ��һ��CCombOrder
	///@return	�õ��ĵ�һ��CCombOrder�����û�У��򷵻�NULL
	CCombOrder *getFirst(void);
	
	///��ȡ��һ��CCombOrder
	///@return	�õ���һ��CCombOrder�����û�У��򷵻�NULL
	CCombOrder *getNext(void);
	
	///������ȡCCombOrder
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCombOrderActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCombOrderActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCombOrderCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCombOrderCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///��������ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///�������ж�Ӧ�ĺ�Լ1��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ1��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument1(CInstrumentFactory *pFactory);
	
	///�������ж�Ӧ�ĺ�Լ2��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ2��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument2(CInstrumentFactory *pFactory);
	
	///�������ж�Ӧ�ĺ�Լ3��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ3��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument3(CInstrumentFactory *pFactory);
	
	///�������ж�Ӧ�ĺ�Լ4��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ4��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument4(CInstrumentFactory *pFactory);
	
	///Ѱ��CCombOrder
	///@param	CombOrderSysID	��ϱ���ϵͳ���
	///@return	�ҵ���CCombOrder������Ҳ���������NULL
	CCombOrder *findByCombOrderID( const CReadOnlyOrderSysIDType&  CombOrderSysID);



	friend class CCombOrderIteratorStartByParticipantID;

	///��ʼѰ��CCombOrder
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CCombOrder������Ҳ���������NULL
	CCombOrder *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CCombOrder��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCombOrder *findNextStartByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipantID(void);

	friend class CCombOrderIteratorBySettlementGroupID;

	///��ʼѰ��CCombOrder
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCombOrder������Ҳ���������NULL
	CCombOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCombOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCombOrder *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCombOrder
	///@param	UserID	����Ա����
	///@param	CombOrderLocalID	��ϱ������ر��
	///@return	�ҵ���CCombOrder������Ҳ���������NULL
	CCombOrder *findByCombOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  CombOrderLocalID);



	friend class CCombOrderIteratorByUserID;

	///��ʼѰ��CCombOrder
	///@param	UserID	����Ա����
	///@return	���������ĵ�һ��CCombOrder������Ҳ���������NULL
	CCombOrder *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///Ѱ����һ������������CCombOrder��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CCombOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCombOrder *findNextByUserID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByUserID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCombOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCombOrder	Ҫ�����CombOrder
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCombOrder *internalAdd(CWriteableCombOrder *pCombOrder, bool bNoTransaction);
	
	
	///ˢ�¸�CCombOrder�ļ�ֵ
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	///@param	pNewCombOrder	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCombOrder��ͬʱɾ��������
	///@param	pCombOrder	Ҫɾ����CCombOrder
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCombOrder *pCombOrder, bool bNoTransaction);
/*
	///���ĳ��CCombOrder�Ƿ����ڱ����󹤳�
	///@param	pCombOrder	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCombOrder *pCombOrder);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID������
	CAVLTree *pParticipantIDIndex;
	///����UserID+CombOrderLocalID������
	CAVLTree *pCombOrderLocalIDIndex;
	
	///����CombOrderSysID��hash����
	CHashIndex *pCombOrderSysIDHashIndex;
	
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCombOrder *pLastFoundInSearchBySettlementGroupID;
	///����UserID����ʱ���洢�Ĳ�ѯ����
	CUserIDType queryUserIDInSearchByUserID;
	
	///����UserID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByUserID;
	
	///����ǰ����
	///@param	pCombOrder	Ҫ�����CombOrder
	virtual void beforeAdd(CWriteableCombOrder *pCombOrder);
	
	///����󴥷�
	///@param	pCombOrder	�Ѿ������CombOrder
	virtual void afterAdd(CCombOrder *pCombOrder);

	///����ǰ����	
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	///@param	pNewCombOrder	�µ�ֵ
	virtual void beforeUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pNewCombOrder);
	
	///���º󴥷�
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	virtual void afterUpdate(CCombOrder *pCombOrder);
	
	///ɾ��ǰ����
	///@param	pCombOrder	Ҫɾ����CCombOrder
	virtual void beforeRemove(CCombOrder *pCombOrder);
	
	///ȷ�ϼ���󴥷�
	///@param	pCombOrder	�Ѿ������CombOrder
	virtual void commitAdd(CCombOrder *pCombOrder);

	///ȷ�ϸ��º󴥷�
	///@param	pCombOrder	��ˢ�µ�CCombOrder
	///@param	poldCombOrder	ԭ����ֵ
	virtual void commitUpdate(CCombOrder *pCombOrder, CWriteableCombOrder *pOldCombOrder);
	
	///ȷ��ɾ���󴥷�
	///@param	pCombOrder	�Ѿ�ɾ����CCombOrder
	virtual void commitRemove(CWriteableCombOrder *pCombOrder);

	///������صĴ�����
	vector<CCombOrderActionTrigger *> *pActionTriggers;
	vector<CCombOrderCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCombOrder compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///COTCOrderFactory��һ��OTC�����Ķ��󹤳�����������һ��OTC������
///ͬʱ�ֽ����������������Է����ѯ��
///	OTCOrderIDIndex
///	OTCOrderLocalIDIndex
///ʹ�ñ����󹤳���������ɶ�OTC��������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByOTCOrderLocalID��Ψһ�ҵ�����
///		ʹ��findByOTCOrderID��Ψһ�ҵ�����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class COTCOrderFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	COTCOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxOTCOrder��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	COTCOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~COTCOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�OTCOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�OTCOrder���ļ��������������ļ��еĶ���OTCOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�OTCOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�OTCOrder���ļ��������������ļ��еĶ���OTCOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class COTCOrderResource;

	///��һ��COTCOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pOTCOrder	Ҫ�����OTCOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	COTCOrder *add(CWriteableOTCOrder *pOTCOrder, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�COTCOrder��ֵ
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	///@param	pNewOTCOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pOTCOrder	  ��Ҫ��ˢ�»���������COTCOrder,����NULL��ʾ����Ҫ������
	///@param	pNewOTCOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	COTCOrder* addOrUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��COTCOrder��ͬʱɾ��������
	///@param	pOTCOrder	Ҫɾ����COTCOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(COTCOrder *pOTCOrder, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��COTCOrder
	///@param	pOTCOrder	Ҫ��ȡ��COTCOrder
	///@param	pTragetOTCOrder	��Ž����COTCOrder
	void retrieve(COTCOrder *pOTCOrder, CWriteableOTCOrder *pTargetOTCOrder);
	
	///��ȡ��һ��COTCOrder
	///@return	�õ��ĵ�һ��COTCOrder�����û�У��򷵻�NULL
	COTCOrder *getFirst(void);
	
	///��ȡ��һ��COTCOrder
	///@return	�õ���һ��COTCOrder�����û�У��򷵻�NULL
	COTCOrder *getNext(void);
	
	///������ȡCOTCOrder
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(COTCOrderActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(COTCOrderActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(COTCOrderCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(COTCOrderCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///Ѱ��COTCOrder
	///@param	UserID	����Ա����
	///@param	OTCOrderLocalID	OTC�������ر��
	///@return	�ҵ���COTCOrder������Ҳ���������NULL
	COTCOrder *findByOTCOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  OTCOrderLocalID);



	///Ѱ��COTCOrder
	///@param	OTCOrderSysID	OTC����ϵͳ���
	///@return	�ҵ���COTCOrder������Ҳ���������NULL
	COTCOrder *findByOTCOrderID( const CReadOnlyOTCOrderSysIDType&  OTCOrderSysID);



	friend class COTCOrderIteratorBySettlementGroupID;

	///��ʼѰ��COTCOrder
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��COTCOrder������Ҳ���������NULL
	COTCOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������COTCOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������COTCOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	COTCOrder *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��COTCOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pOTCOrder	Ҫ�����OTCOrder
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	COTCOrder *internalAdd(CWriteableOTCOrder *pOTCOrder, bool bNoTransaction);
	
	
	///ˢ�¸�COTCOrder�ļ�ֵ
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	///@param	pNewOTCOrder	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��COTCOrder��ͬʱɾ��������
	///@param	pOTCOrder	Ҫɾ����COTCOrder
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(COTCOrder *pOTCOrder, bool bNoTransaction);
/*
	///���ĳ��COTCOrder�Ƿ����ڱ����󹤳�
	///@param	pOTCOrder	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(COTCOrder *pOTCOrder);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����OTCOrderSysID������
	CAVLTree *pOTCOrderIDIndex;
	///����UserID+OTCOrderLocalID������
	CAVLTree *pOTCOrderLocalIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	COTCOrder *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pOTCOrder	Ҫ�����OTCOrder
	virtual void beforeAdd(CWriteableOTCOrder *pOTCOrder);
	
	///����󴥷�
	///@param	pOTCOrder	�Ѿ������OTCOrder
	virtual void afterAdd(COTCOrder *pOTCOrder);

	///����ǰ����	
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	///@param	pNewOTCOrder	�µ�ֵ
	virtual void beforeUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pNewOTCOrder);
	
	///���º󴥷�
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	virtual void afterUpdate(COTCOrder *pOTCOrder);
	
	///ɾ��ǰ����
	///@param	pOTCOrder	Ҫɾ����COTCOrder
	virtual void beforeRemove(COTCOrder *pOTCOrder);
	
	///ȷ�ϼ���󴥷�
	///@param	pOTCOrder	�Ѿ������OTCOrder
	virtual void commitAdd(COTCOrder *pOTCOrder);

	///ȷ�ϸ��º󴥷�
	///@param	pOTCOrder	��ˢ�µ�COTCOrder
	///@param	poldOTCOrder	ԭ����ֵ
	virtual void commitUpdate(COTCOrder *pOTCOrder, CWriteableOTCOrder *pOldOTCOrder);
	
	///ȷ��ɾ���󴥷�
	///@param	pOTCOrder	�Ѿ�ɾ����COTCOrder
	virtual void commitRemove(CWriteableOTCOrder *pOTCOrder);

	///������صĴ�����
	vector<COTCOrderActionTrigger *> *pActionTriggers;
	vector<COTCOrderCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableOTCOrder compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CImplyOrderFactory��һ����ʽ�����Ķ��󹤳�����������һ����ʽ������
///ͬʱ�ֽ����������������Է����ѯ��
///	ImplyLegInstrumentIndex
///	ImplyOrderAndAnchorLegIndex
///ʹ�ñ����󹤳���������ɶ���ʽ��������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByImplyLeg��findNextByImplyLeg��endFindByImplyLeg��ɲ�ѯ����
///		ʹ��startFindByImplyOrderAndAnchorLeg��findNextByImplyOrderAndAnchorLeg��endFindByImplyOrderAndAnchorLeg��ɲ�ѯ����
///		ʹ��startFindByImplyOrder��findNextByImplyOrder��endFindByImplyOrder��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CImplyOrderFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CImplyOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxImplyOrder��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CImplyOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CImplyOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ImplyOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ImplyOrder���ļ��������������ļ��еĶ���ImplyOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ImplyOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ImplyOrder���ļ��������������ļ��еĶ���ImplyOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CImplyOrderResource;

	///��һ��CImplyOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pImplyOrder	Ҫ�����ImplyOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CImplyOrder *add(CWriteableImplyOrder *pImplyOrder, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CImplyOrder��ֵ
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	///@param	pNewImplyOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pImplyOrder	  ��Ҫ��ˢ�»���������CImplyOrder,����NULL��ʾ����Ҫ������
	///@param	pNewImplyOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CImplyOrder* addOrUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CImplyOrder��ͬʱɾ��������
	///@param	pImplyOrder	Ҫɾ����CImplyOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CImplyOrder *pImplyOrder, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CImplyOrder
	///@param	pImplyOrder	Ҫ��ȡ��CImplyOrder
	///@param	pTragetImplyOrder	��Ž����CImplyOrder
	void retrieve(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pTargetImplyOrder);
	
	///��ȡ��һ��CImplyOrder
	///@return	�õ��ĵ�һ��CImplyOrder�����û�У��򷵻�NULL
	CImplyOrder *getFirst(void);
	
	///��ȡ��һ��CImplyOrder
	///@return	�õ���һ��CImplyOrder�����û�У��򷵻�NULL
	CImplyOrder *getNext(void);
	
	///������ȡCImplyOrder
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CImplyOrderActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CImplyOrderActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CImplyOrderCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CImplyOrderCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CImplyOrderIteratorByImplyLeg;

	///��ʼѰ��CImplyOrder
	///@param	CombInstrumentID	��ϱ�����
	///@param	ImplyLegID	�����������ȱ��
	///@param	Direction	����������������
	///@return	���������ĵ�һ��CImplyOrder������Ҳ���������NULL
	CImplyOrder *startFindByImplyLeg( const CReadOnlyInstrumentIDType& CombInstrumentID,  const CReadOnlyLegIDType& ImplyLegID,  const CReadOnlyDirectionType& Direction);

	///Ѱ����һ������������CImplyOrder��������startFindByImplyLeg�Ժ�endFindByImplyLeg֮ǰ����
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CImplyOrder *findNextByImplyLeg(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByImplyLeg(void);

	friend class CImplyOrderIteratorByImplyOrderAndAnchorLeg;

	///��ʼѰ��CImplyOrder
	///@param	ImplyOrderID	����������
	///@param	AnchorLegID	ê�������ȱ��
	///@return	���������ĵ�һ��CImplyOrder������Ҳ���������NULL
	CImplyOrder *startFindByImplyOrderAndAnchorLeg( const CReadOnlyOrderSysIDType& ImplyOrderID,  const CReadOnlyLegIDType& AnchorLegID);

	///Ѱ����һ������������CImplyOrder��������startFindByImplyOrderAndAnchorLeg�Ժ�endFindByImplyOrderAndAnchorLeg֮ǰ����
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CImplyOrder *findNextByImplyOrderAndAnchorLeg(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByImplyOrderAndAnchorLeg(void);

	friend class CImplyOrderIteratorByImplyOrder;

	///��ʼѰ��CImplyOrder
	///@param	ImplyOrderID	����������
	///@return	���������ĵ�һ��CImplyOrder������Ҳ���������NULL
	CImplyOrder *startFindByImplyOrder( const CReadOnlyOrderSysIDType& ImplyOrderID);

	///Ѱ����һ������������CImplyOrder��������startFindByImplyOrder�Ժ�endFindByImplyOrder֮ǰ����
	///@return	��һ����������CImplyOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CImplyOrder *findNextByImplyOrder(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByImplyOrder(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CImplyOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pImplyOrder	Ҫ�����ImplyOrder
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CImplyOrder *internalAdd(CWriteableImplyOrder *pImplyOrder, bool bNoTransaction);
	
	
	///ˢ�¸�CImplyOrder�ļ�ֵ
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	///@param	pNewImplyOrder	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CImplyOrder��ͬʱɾ��������
	///@param	pImplyOrder	Ҫɾ����CImplyOrder
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CImplyOrder *pImplyOrder, bool bNoTransaction);
/*
	///���ĳ��CImplyOrder�Ƿ����ڱ����󹤳�
	///@param	pImplyOrder	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CImplyOrder *pImplyOrder);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����CombInstrumentID+ImplyLegID+Direction������
	CAVLTree *pImplyLegInstrumentIndex;
	///����ImplyOrderID+AnchorLegID+Priority������
	CAVLTree *pImplyOrderAndAnchorLegIndex;
	
	
	///����CombInstrumentID��ImplyLegID��Direction����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryCombInstrumentIDInSearchByImplyLeg;
	CLegIDType queryImplyLegIDInSearchByImplyLeg;
	CDirectionType queryDirectionInSearchByImplyLeg;
	
	///����CombInstrumentID��ImplyLegID��Direction����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByImplyLeg;
	///����ImplyOrderID��AnchorLegID����ʱ���洢�Ĳ�ѯ����
	COrderSysIDType queryImplyOrderIDInSearchByImplyOrderAndAnchorLeg;
	CLegIDType queryAnchorLegIDInSearchByImplyOrderAndAnchorLeg;
	
	///����ImplyOrderID��AnchorLegID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByImplyOrderAndAnchorLeg;
	///����ImplyOrderID����ʱ���洢�Ĳ�ѯ����
	COrderSysIDType queryImplyOrderIDInSearchByImplyOrder;
	
	///����ImplyOrderID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByImplyOrder;
	
	///����ǰ����
	///@param	pImplyOrder	Ҫ�����ImplyOrder
	virtual void beforeAdd(CWriteableImplyOrder *pImplyOrder);
	
	///����󴥷�
	///@param	pImplyOrder	�Ѿ������ImplyOrder
	virtual void afterAdd(CImplyOrder *pImplyOrder);

	///����ǰ����	
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	///@param	pNewImplyOrder	�µ�ֵ
	virtual void beforeUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pNewImplyOrder);
	
	///���º󴥷�
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	virtual void afterUpdate(CImplyOrder *pImplyOrder);
	
	///ɾ��ǰ����
	///@param	pImplyOrder	Ҫɾ����CImplyOrder
	virtual void beforeRemove(CImplyOrder *pImplyOrder);
	
	///ȷ�ϼ���󴥷�
	///@param	pImplyOrder	�Ѿ������ImplyOrder
	virtual void commitAdd(CImplyOrder *pImplyOrder);

	///ȷ�ϸ��º󴥷�
	///@param	pImplyOrder	��ˢ�µ�CImplyOrder
	///@param	poldImplyOrder	ԭ����ֵ
	virtual void commitUpdate(CImplyOrder *pImplyOrder, CWriteableImplyOrder *pOldImplyOrder);
	
	///ȷ��ɾ���󴥷�
	///@param	pImplyOrder	�Ѿ�ɾ����CImplyOrder
	virtual void commitRemove(CWriteableImplyOrder *pImplyOrder);

	///������صĴ�����
	vector<CImplyOrderActionTrigger *> *pActionTriggers;
	vector<CImplyOrderCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableImplyOrder compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CQuoteFactory��һ�����۵Ķ��󹤳�����������һ�����ۣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	QuoteIDIndex
///	PartClientAndInstrumentIndex
///	QuoteLocalIDIndex
///ʹ�ñ����󹤳���������ɶԱ��۵���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByQuoteID��Ψһ�ҵ�����
///		ʹ��findByQuoteLocalID��Ψһ�ҵ�����
///		ʹ��startFindByUserID��findNextByUserID��endFindByUserID��ɲ�ѯ����
///		ʹ��findByPartClientAndInstrument��Ψһ�ҵ�����
///		ʹ��startFindStartByParticipantID��findNextStartByParticipantID��endFindStartByParticipantID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByAskOrder��Ψһ�ҵ�����
///		ʹ��findByBidOrder��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CQuoteFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CQuoteFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxQuote��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CQuoteFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CQuoteFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Quote
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Quote���ļ��������������ļ��еĶ���QuoteCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Quote
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Quote���ļ��������������ļ��еĶ���QuoteCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CQuoteResource;

	///��һ��CQuote���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pQuote	Ҫ�����Quote
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CQuote *add(CWriteableQuote *pQuote, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CQuote��ֵ
	///@param	pQuote	��ˢ�µ�CQuote
	///@param	pNewQuote	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CQuote *pQuote, CWriteableQuote *pNewQuote, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pQuote	  ��Ҫ��ˢ�»���������CQuote,����NULL��ʾ����Ҫ������
	///@param	pNewQuote	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CQuote* addOrUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CQuote��ͬʱɾ��������
	///@param	pQuote	Ҫɾ����CQuote
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CQuote *pQuote, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CQuote
	///@param	pQuote	Ҫ��ȡ��CQuote
	///@param	pTragetQuote	��Ž����CQuote
	void retrieve(CQuote *pQuote, CWriteableQuote *pTargetQuote);
	
	///��ȡ��һ��CQuote
	///@return	�õ��ĵ�һ��CQuote�����û�У��򷵻�NULL
	CQuote *getFirst(void);
	
	///��ȡ��һ��CQuote
	///@return	�õ���һ��CQuote�����û�У��򷵻�NULL
	CQuote *getNext(void);
	
	///������ȡCQuote
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CQuoteActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CQuoteActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CQuoteCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CQuoteCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///��������ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///Ѱ��CQuote
	///@param	QuoteSysID	���۱��
	///@return	�ҵ���CQuote������Ҳ���������NULL
	CQuote *findByQuoteID( const CReadOnlyQuoteSysIDType&  QuoteSysID);



	///Ѱ��CQuote
	///@param	UserID	����Ա����
	///@param	QuoteLocalID	���۱��ر��
	///@return	�ҵ���CQuote������Ҳ���������NULL
	CQuote *findByQuoteLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  QuoteLocalID);



	friend class CQuoteIteratorByUserID;

	///��ʼѰ��CQuote
	///@param	UserID	�û�
	///@return	���������ĵ�һ��CQuote������Ҳ���������NULL
	CQuote *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///Ѱ����һ������������CQuote��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CQuote *findNextByUserID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByUserID(void);

	///Ѱ��CQuote
	///@param	ParticipantID	��Ա��
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	///@return	�ҵ���CQuote������Ҳ���������NULL
	CQuote *findByPartClientAndInstrument( const CReadOnlyParticipantIDType&  ParticipantID,  const CReadOnlyClientIDType&  ClientID,  const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CQuoteIteratorStartByParticipantID;

	///��ʼѰ��CQuote
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CQuote������Ҳ���������NULL
	CQuote *startFindStartByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CQuote��������startFindStartByParticipantID�Ժ�endFindStartByParticipantID֮ǰ����
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CQuote *findNextStartByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByParticipantID(void);

	friend class CQuoteIteratorBySettlementGroupID;

	///��ʼѰ��CQuote
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CQuote������Ҳ���������NULL
	CQuote *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CQuote��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CQuote������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CQuote *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CQuote
	///@param	AskOrderSysID	����������
	///@return	�ҵ���CQuote������Ҳ���������NULL
	CQuote *findByAskOrder( const CReadOnlyOrderSysIDType&  AskOrderSysID);



	///Ѱ��CQuote
	///@param	BidOrderSysID	�򷽱�����
	///@return	�ҵ���CQuote������Ҳ���������NULL
	CQuote *findByBidOrder( const CReadOnlyOrderSysIDType&  BidOrderSysID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CQuote���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pQuote	Ҫ�����Quote
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CQuote *internalAdd(CWriteableQuote *pQuote, bool bNoTransaction);
	
	
	///ˢ�¸�CQuote�ļ�ֵ
	///@param	pQuote	��ˢ�µ�CQuote
	///@param	pNewQuote	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CQuote��ͬʱɾ��������
	///@param	pQuote	Ҫɾ����CQuote
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CQuote *pQuote, bool bNoTransaction);
/*
	///���ĳ��CQuote�Ƿ����ڱ����󹤳�
	///@param	pQuote	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CQuote *pQuote);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����QuoteSysID������
	CAVLTree *pQuoteIDIndex;
	///����ParticipantID+ClientID+InstrumentID+QuoteSysID������
	CAVLTree *pPartClientAndInstrumentIndex;
	///����UserID+QuoteLocalID������
	CAVLTree *pQuoteLocalIDIndex;
	
	///����AskOrderSysIDHashKey��hash����
	CHashIndex *pAskOrderHashIndex;
	///����BidOrderSysIDHashKey��hash����
	CHashIndex *pBidOrderHashIndex;
	
	///����UserID����ʱ���洢�Ĳ�ѯ����
	CUserIDType queryUserIDInSearchByUserID;
	
	///����UserID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByUserID;
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByParticipantID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CQuote *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pQuote	Ҫ�����Quote
	virtual void beforeAdd(CWriteableQuote *pQuote);
	
	///����󴥷�
	///@param	pQuote	�Ѿ������Quote
	virtual void afterAdd(CQuote *pQuote);

	///����ǰ����	
	///@param	pQuote	��ˢ�µ�CQuote
	///@param	pNewQuote	�µ�ֵ
	virtual void beforeUpdate(CQuote *pQuote, CWriteableQuote *pNewQuote);
	
	///���º󴥷�
	///@param	pQuote	��ˢ�µ�CQuote
	virtual void afterUpdate(CQuote *pQuote);
	
	///ɾ��ǰ����
	///@param	pQuote	Ҫɾ����CQuote
	virtual void beforeRemove(CQuote *pQuote);
	
	///ȷ�ϼ���󴥷�
	///@param	pQuote	�Ѿ������Quote
	virtual void commitAdd(CQuote *pQuote);

	///ȷ�ϸ��º󴥷�
	///@param	pQuote	��ˢ�µ�CQuote
	///@param	poldQuote	ԭ����ֵ
	virtual void commitUpdate(CQuote *pQuote, CWriteableQuote *pOldQuote);
	
	///ȷ��ɾ���󴥷�
	///@param	pQuote	�Ѿ�ɾ����CQuote
	virtual void commitRemove(CWriteableQuote *pQuote);

	///������صĴ�����
	vector<CQuoteActionTrigger *> *pActionTriggers;
	vector<CQuoteCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableQuote compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CMBLMarketDataFactory��һ���ּ۱�Ķ��󹤳�����������һ���ּ۱�
///ͬʱ�ֽ����������������Է����ѯ��
///	BuyMBLIndex
///	SellMBLIndex
///	QBuyMBLIndex
///	QSellMBLIndex
///ʹ�ñ����󹤳���������ɶԷּ۱����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindByBuyMBLData��findNextByBuyMBLData��endFindByBuyMBLData��ɲ�ѯ����
///		ʹ��startFindBySellMBLData��findNextBySellMBLData��endFindBySellMBLData��ɲ�ѯ����
///		ʹ��startFindStartByBuyMBLData��findNextStartByBuyMBLData��endFindStartByBuyMBLData��ɲ�ѯ����
///		ʹ��startFindStartBySellMBLData��findNextStartBySellMBLData��endFindStartBySellMBLData��ɲ�ѯ����
///		ʹ��findByPrice��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CMBLMarketDataFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMBLMarketDataFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxMBLMarketData��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CMBLMarketDataFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMBLMarketDataFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�MBLMarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�MBLMarketData���ļ��������������ļ��еĶ���MBLMarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�MBLMarketData
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�MBLMarketData���ļ��������������ļ��еĶ���MBLMarketDataCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CMBLMarketDataResource;

	///��һ��CMBLMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMBLMarketData	Ҫ�����MBLMarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMBLMarketData *add(CWriteableMBLMarketData *pMBLMarketData, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CMBLMarketData��ֵ
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	///@param	pNewMBLMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pMBLMarketData	  ��Ҫ��ˢ�»���������CMBLMarketData,����NULL��ʾ����Ҫ������
	///@param	pNewMBLMarketData	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CMBLMarketData* addOrUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CMBLMarketData��ͬʱɾ��������
	///@param	pMBLMarketData	Ҫɾ����CMBLMarketData
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CMBLMarketData *pMBLMarketData, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CMBLMarketData
	///@param	pMBLMarketData	Ҫ��ȡ��CMBLMarketData
	///@param	pTragetMBLMarketData	��Ž����CMBLMarketData
	void retrieve(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pTargetMBLMarketData);
	
	///��ȡ��һ��CMBLMarketData
	///@return	�õ��ĵ�һ��CMBLMarketData�����û�У��򷵻�NULL
	CMBLMarketData *getFirst(void);
	
	///��ȡ��һ��CMBLMarketData
	///@return	�õ���һ��CMBLMarketData�����û�У��򷵻�NULL
	CMBLMarketData *getNext(void);
	
	///������ȡCMBLMarketData
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CMBLMarketDataActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CMBLMarketDataActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CMBLMarketDataCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CMBLMarketDataCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CMBLMarketDataIteratorByBuyMBLData;

	///��ʼѰ��CMBLMarketData
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CMBLMarketData������Ҳ���������NULL
	CMBLMarketData *startFindByBuyMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CMBLMarketData��������startFindByBuyMBLData�Ժ�endFindByBuyMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMBLMarketData *findNextByBuyMBLData(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByBuyMBLData(void);

	friend class CMBLMarketDataIteratorBySellMBLData;

	///��ʼѰ��CMBLMarketData
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CMBLMarketData������Ҳ���������NULL
	CMBLMarketData *startFindBySellMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CMBLMarketData��������startFindBySellMBLData�Ժ�endFindBySellMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMBLMarketData *findNextBySellMBLData(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySellMBLData(void);

	friend class CMBLMarketDataIteratorStartByBuyMBLData;

	///��ʼѰ��CMBLMarketData
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CMBLMarketData������Ҳ���������NULL
	CMBLMarketData *startFindStartByBuyMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CMBLMarketData��������startFindStartByBuyMBLData�Ժ�endFindStartByBuyMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMBLMarketData *findNextStartByBuyMBLData(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByBuyMBLData(void);

	friend class CMBLMarketDataIteratorStartBySellMBLData;

	///��ʼѰ��CMBLMarketData
	///@param	InstrumentID	��Լ����
	///@return	���������ĵ�һ��CMBLMarketData������Ҳ���������NULL
	CMBLMarketData *startFindStartBySellMBLData( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CMBLMarketData��������startFindStartBySellMBLData�Ժ�endFindStartBySellMBLData֮ǰ����
	///@return	��һ����������CMBLMarketData������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CMBLMarketData *findNextStartBySellMBLData(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartBySellMBLData(void);

	///Ѱ��CMBLMarketData
	///@param	InstrumentID	��Լ����
	///@param	Direction	��������
	///@param	Price	�۸�
	///@return	�ҵ���CMBLMarketData������Ҳ���������NULL
	CMBLMarketData *findByPrice( const CReadOnlyInstrumentIDType&  InstrumentID,  const CReadOnlyDirectionType&  Direction,  const CReadOnlyPriceType&  Price);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CMBLMarketData���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pMBLMarketData	Ҫ�����MBLMarketData
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CMBLMarketData *internalAdd(CWriteableMBLMarketData *pMBLMarketData, bool bNoTransaction);
	
	
	///ˢ�¸�CMBLMarketData�ļ�ֵ
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	///@param	pNewMBLMarketData	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CMBLMarketData��ͬʱɾ��������
	///@param	pMBLMarketData	Ҫɾ����CMBLMarketData
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CMBLMarketData *pMBLMarketData, bool bNoTransaction);
/*
	///���ĳ��CMBLMarketData�Ƿ����ڱ����󹤳�
	///@param	pMBLMarketData	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CMBLMarketData *pMBLMarketData);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID+Direction+Price������
	CAVLTree *pBuyMBLIndex;
	///����InstrumentID+Direction+Price������
	CAVLTree *pSellMBLIndex;
	///����Direction+InstrumentID+Price������
	CAVLTree *pQBuyMBLIndex;
	///����Direction+InstrumentID+Price������
	CAVLTree *pQSellMBLIndex;
	
	
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchByBuyMBLData;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByBuyMBLData;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchBySellMBLData;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchBySellMBLData;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartByBuyMBLData;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByBuyMBLData;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartBySellMBLData;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartBySellMBLData;
	
	///����ǰ����
	///@param	pMBLMarketData	Ҫ�����MBLMarketData
	virtual void beforeAdd(CWriteableMBLMarketData *pMBLMarketData);
	
	///����󴥷�
	///@param	pMBLMarketData	�Ѿ������MBLMarketData
	virtual void afterAdd(CMBLMarketData *pMBLMarketData);

	///����ǰ����	
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	///@param	pNewMBLMarketData	�µ�ֵ
	virtual void beforeUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pNewMBLMarketData);
	
	///���º󴥷�
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	virtual void afterUpdate(CMBLMarketData *pMBLMarketData);
	
	///ɾ��ǰ����
	///@param	pMBLMarketData	Ҫɾ����CMBLMarketData
	virtual void beforeRemove(CMBLMarketData *pMBLMarketData);
	
	///ȷ�ϼ���󴥷�
	///@param	pMBLMarketData	�Ѿ������MBLMarketData
	virtual void commitAdd(CMBLMarketData *pMBLMarketData);

	///ȷ�ϸ��º󴥷�
	///@param	pMBLMarketData	��ˢ�µ�CMBLMarketData
	///@param	poldMBLMarketData	ԭ����ֵ
	virtual void commitUpdate(CMBLMarketData *pMBLMarketData, CWriteableMBLMarketData *pOldMBLMarketData);
	
	///ȷ��ɾ���󴥷�
	///@param	pMBLMarketData	�Ѿ�ɾ����CMBLMarketData
	virtual void commitRemove(CWriteableMBLMarketData *pMBLMarketData);

	///������صĴ�����
	vector<CMBLMarketDataActionTrigger *> *pActionTriggers;
	vector<CMBLMarketDataCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableMBLMarketData compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CTradeFactory��һ���ɽ��Ķ��󹤳�����������һ���ɽ���
///ͬʱ�ֽ����������������Է����ѯ��
///	TradeIDIndex
///	PartIDIndex
///	ClientIDIndex
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԳɽ�����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindAll��findNextAll��endFindAll��ɲ�ѯ����
///		ʹ��startFindByTradeID��findNextByTradeID��endFindByTradeID��ɲ�ѯ����
///		ʹ��startFindStartByPartID��findNextStartByPartID��endFindStartByPartID��ɲ�ѯ����
///		ʹ��startFindByClientID��findNextByClientID��endFindByClientID��ɲ�ѯ����
///		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CTradeFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTradeFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxTrade��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CTradeFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CTradeFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�Trade
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�Trade���ļ��������������ļ��еĶ���TradeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�Trade
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�Trade���ļ��������������ļ��еĶ���TradeCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CTradeResource;

	///��һ��CTrade���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTrade	Ҫ�����Trade
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTrade *add(CWriteableTrade *pTrade, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CTrade��ֵ
	///@param	pTrade	��ˢ�µ�CTrade
	///@param	pNewTrade	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CTrade *pTrade, CWriteableTrade *pNewTrade, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pTrade	  ��Ҫ��ˢ�»���������CTrade,����NULL��ʾ����Ҫ������
	///@param	pNewTrade	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CTrade* addOrUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CTrade��ͬʱɾ��������
	///@param	pTrade	Ҫɾ����CTrade
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CTrade *pTrade, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CTrade
	///@param	pTrade	Ҫ��ȡ��CTrade
	///@param	pTragetTrade	��Ž����CTrade
	void retrieve(CTrade *pTrade, CWriteableTrade *pTargetTrade);
	
	///��ȡ��һ��CTrade
	///@return	�õ��ĵ�һ��CTrade�����û�У��򷵻�NULL
	CTrade *getFirst(void);
	
	///��ȡ��һ��CTrade
	///@return	�õ���һ��CTrade�����û�У��򷵻�NULL
	CTrade *getNext(void);
	
	///������ȡCTrade
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CTradeActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CTradeActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CTradeCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CTradeCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///��������ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	friend class CTradeIteratorAll;

	///��ʼѰ��CTrade
	///@return	���������ĵ�һ��CTrade������Ҳ���������NULL
	CTrade *startFindAll();

	///Ѱ����һ������������CTrade��������startFindAll�Ժ�endFindAll֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTrade *findNextAll(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindAll(void);

	friend class CTradeIteratorByTradeID;

	///��ʼѰ��CTrade
	///@param	TradeID	�ɽ����
	///@return	���������ĵ�һ��CTrade������Ҳ���������NULL
	CTrade *startFindByTradeID( const CReadOnlyTradeIDType& TradeID);

	///Ѱ����һ������������CTrade��������startFindByTradeID�Ժ�endFindByTradeID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTrade *findNextByTradeID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByTradeID(void);

	friend class CTradeIteratorStartByPartID;

	///��ʼѰ��CTrade
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CTrade������Ҳ���������NULL
	CTrade *startFindStartByPartID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CTrade��������startFindStartByPartID�Ժ�endFindStartByPartID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTrade *findNextStartByPartID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByPartID(void);

	friend class CTradeIteratorByClientID;

	///��ʼѰ��CTrade
	///@param	ClientID	�ͻ���
	///@return	���������ĵ�һ��CTrade������Ҳ���������NULL
	CTrade *startFindByClientID( const CReadOnlyClientIDType& ClientID);

	///Ѱ����һ������������CTrade��������startFindByClientID�Ժ�endFindByClientID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTrade *findNextByClientID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByClientID(void);

	friend class CTradeIteratorStartByInstrumentID;

	///��ʼѰ��CTrade
	///@param	InstrumentID	��Լ��
	///@return	���������ĵ�һ��CTrade������Ҳ���������NULL
	CTrade *startFindStartByInstrumentID( const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CTrade��������startFindStartByInstrumentID�Ժ�endFindStartByInstrumentID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTrade *findNextStartByInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindStartByInstrumentID(void);

	friend class CTradeIteratorBySettlementGroupID;

	///��ʼѰ��CTrade
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CTrade������Ҳ���������NULL
	CTrade *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CTrade��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CTrade *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CTrade���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pTrade	Ҫ�����Trade
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CTrade *internalAdd(CWriteableTrade *pTrade, bool bNoTransaction);
	
	
	///ˢ�¸�CTrade�ļ�ֵ
	///@param	pTrade	��ˢ�µ�CTrade
	///@param	pNewTrade	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CTrade��ͬʱɾ��������
	///@param	pTrade	Ҫɾ����CTrade
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CTrade *pTrade, bool bNoTransaction);
/*
	///���ĳ��CTrade�Ƿ����ڱ����󹤳�
	///@param	pTrade	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CTrade *pTrade);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����TradeID+ParticipantID+ClientID+InstrumentID������
	CAVLTree *pTradeIDIndex;
	///����ParticipantID+TradeID+ClientID+InstrumentID������
	CAVLTree *pPartIDIndex;
	///����ClientID+TradeID������
	CAVLTree *pClientIDIndex;
	///����InstrumentID+TradeID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///���ռ���ʱ���洢�Ĳ�ѯ����
	
	///���ռ���ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchAll;
	///����TradeID����ʱ���洢�Ĳ�ѯ����
	CTradeIDType queryTradeIDInSearchByTradeID;
	
	///����TradeID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByTradeID;
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchStartByPartID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByPartID;
	///����ClientID����ʱ���洢�Ĳ�ѯ����
	CClientIDType queryClientIDInSearchByClientID;
	
	///����ClientID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByClientID;
	///����InstrumentID����ʱ���洢�Ĳ�ѯ����
	CInstrumentIDType queryInstrumentIDInSearchStartByInstrumentID;
	
	///����InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchStartByInstrumentID;
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CTrade *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pTrade	Ҫ�����Trade
	virtual void beforeAdd(CWriteableTrade *pTrade);
	
	///����󴥷�
	///@param	pTrade	�Ѿ������Trade
	virtual void afterAdd(CTrade *pTrade);

	///����ǰ����	
	///@param	pTrade	��ˢ�µ�CTrade
	///@param	pNewTrade	�µ�ֵ
	virtual void beforeUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade);
	
	///���º󴥷�
	///@param	pTrade	��ˢ�µ�CTrade
	virtual void afterUpdate(CTrade *pTrade);
	
	///ɾ��ǰ����
	///@param	pTrade	Ҫɾ����CTrade
	virtual void beforeRemove(CTrade *pTrade);
	
	///ȷ�ϼ���󴥷�
	///@param	pTrade	�Ѿ������Trade
	virtual void commitAdd(CTrade *pTrade);

	///ȷ�ϸ��º󴥷�
	///@param	pTrade	��ˢ�µ�CTrade
	///@param	poldTrade	ԭ����ֵ
	virtual void commitUpdate(CTrade *pTrade, CWriteableTrade *pOldTrade);
	
	///ȷ��ɾ���󴥷�
	///@param	pTrade	�Ѿ�ɾ����CTrade
	virtual void commitRemove(CWriteableTrade *pTrade);

	///������صĴ�����
	vector<CTradeActionTrigger *> *pActionTriggers;
	vector<CTradeCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableTrade compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CFusePhaseFactory��һ���۶Ͻ׶εĶ��󹤳�����������һ���۶Ͻ׶Σ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶ��۶Ͻ׶ε���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CFusePhaseFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CFusePhaseFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxFusePhase��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CFusePhaseFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CFusePhaseFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�FusePhase
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�FusePhase���ļ��������������ļ��еĶ���FusePhaseCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�FusePhase
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�FusePhase���ļ��������������ļ��еĶ���FusePhaseCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CFusePhaseResource;

	///��һ��CFusePhase���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pFusePhase	Ҫ�����FusePhase
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CFusePhase *add(CWriteableFusePhase *pFusePhase, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CFusePhase��ֵ
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	///@param	pNewFusePhase	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pFusePhase	  ��Ҫ��ˢ�»���������CFusePhase,����NULL��ʾ����Ҫ������
	///@param	pNewFusePhase	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CFusePhase* addOrUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CFusePhase��ͬʱɾ��������
	///@param	pFusePhase	Ҫɾ����CFusePhase
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CFusePhase *pFusePhase, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CFusePhase
	///@param	pFusePhase	Ҫ��ȡ��CFusePhase
	///@param	pTragetFusePhase	��Ž����CFusePhase
	void retrieve(CFusePhase *pFusePhase, CWriteableFusePhase *pTargetFusePhase);
	
	///��ȡ��һ��CFusePhase
	///@return	�õ��ĵ�һ��CFusePhase�����û�У��򷵻�NULL
	CFusePhase *getFirst(void);
	
	///��ȡ��һ��CFusePhase
	///@return	�õ���һ��CFusePhase�����û�У��򷵻�NULL
	CFusePhase *getNext(void);
	
	///������ȡCFusePhase
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CFusePhaseActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CFusePhaseActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CFusePhaseCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CFusePhaseCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	///Ѱ��CFusePhase
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CFusePhase������Ҳ���������NULL
	CFusePhase *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



	friend class CFusePhaseIteratorBySettlementGroupID;

	///��ʼѰ��CFusePhase
	///@param	SettlementGroupID	��������
	///@return	���������ĵ�һ��CFusePhase������Ҳ���������NULL
	CFusePhase *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CFusePhase��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CFusePhase������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CFusePhase *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CFusePhase���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pFusePhase	Ҫ�����FusePhase
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CFusePhase *internalAdd(CWriteableFusePhase *pFusePhase, bool bNoTransaction);
	
	
	///ˢ�¸�CFusePhase�ļ�ֵ
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	///@param	pNewFusePhase	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CFusePhase��ͬʱɾ��������
	///@param	pFusePhase	Ҫɾ����CFusePhase
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CFusePhase *pFusePhase, bool bNoTransaction);
/*
	///���ĳ��CFusePhase�Ƿ����ڱ����󹤳�
	///@param	pFusePhase	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CFusePhase *pFusePhase);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CFusePhase *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pFusePhase	Ҫ�����FusePhase
	virtual void beforeAdd(CWriteableFusePhase *pFusePhase);
	
	///����󴥷�
	///@param	pFusePhase	�Ѿ������FusePhase
	virtual void afterAdd(CFusePhase *pFusePhase);

	///����ǰ����	
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	///@param	pNewFusePhase	�µ�ֵ
	virtual void beforeUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pNewFusePhase);
	
	///���º󴥷�
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	virtual void afterUpdate(CFusePhase *pFusePhase);
	
	///ɾ��ǰ����
	///@param	pFusePhase	Ҫɾ����CFusePhase
	virtual void beforeRemove(CFusePhase *pFusePhase);
	
	///ȷ�ϼ���󴥷�
	///@param	pFusePhase	�Ѿ������FusePhase
	virtual void commitAdd(CFusePhase *pFusePhase);

	///ȷ�ϸ��º󴥷�
	///@param	pFusePhase	��ˢ�µ�CFusePhase
	///@param	poldFusePhase	ԭ����ֵ
	virtual void commitUpdate(CFusePhase *pFusePhase, CWriteableFusePhase *pOldFusePhase);
	
	///ȷ��ɾ���󴥷�
	///@param	pFusePhase	�Ѿ�ɾ����CFusePhase
	virtual void commitRemove(CWriteableFusePhase *pFusePhase);

	///������صĴ�����
	vector<CFusePhaseActionTrigger *> *pActionTriggers;
	vector<CFusePhaseCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableFusePhase compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CExecOrderFactory��һ��ִ������Ķ��󹤳�����������һ��ִ�����棬
///ͬʱ�ֽ����������������Է����ѯ��
///	ExecOrderIDIndex
///	ParticipantIDIndex
///	ClientAndInstrumentIndex
///	ExecOrderLocalIDIndex
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶ�ִ���������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByExecOrderID��Ψһ�ҵ�����
///		ʹ��startFindByParticipantID��findNextByParticipantID��endFindByParticipantID��ɲ�ѯ����
///		ʹ��startFindByClientID��findNextByClientID��endFindByClientID��ɲ�ѯ����
///		ʹ��startFindByClientIDAndInstrumentID��findNextByClientIDAndInstrumentID��endFindByClientIDAndInstrumentID��ɲ�ѯ����
///		ʹ��findByExecOrderLocalID��Ψһ�ҵ�����
///		ʹ��startFindByUserID��findNextByUserID��endFindByUserID��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CExecOrderFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CExecOrderFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxExecOrder��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CExecOrderFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CExecOrderFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�ExecOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�ExecOrder���ļ��������������ļ��еĶ���ExecOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�ExecOrder
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�ExecOrder���ļ��������������ļ��еĶ���ExecOrderCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CExecOrderResource;

	///��һ��CExecOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pExecOrder	Ҫ�����ExecOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CExecOrder *add(CWriteableExecOrder *pExecOrder, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CExecOrder��ֵ
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	///@param	pNewExecOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pExecOrder	  ��Ҫ��ˢ�»���������CExecOrder,����NULL��ʾ����Ҫ������
	///@param	pNewExecOrder	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CExecOrder* addOrUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CExecOrder��ͬʱɾ��������
	///@param	pExecOrder	Ҫɾ����CExecOrder
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CExecOrder *pExecOrder, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CExecOrder
	///@param	pExecOrder	Ҫ��ȡ��CExecOrder
	///@param	pTragetExecOrder	��Ž����CExecOrder
	void retrieve(CExecOrder *pExecOrder, CWriteableExecOrder *pTargetExecOrder);
	
	///��ȡ��һ��CExecOrder
	///@return	�õ��ĵ�һ��CExecOrder�����û�У��򷵻�NULL
	CExecOrder *getFirst(void);
	
	///��ȡ��һ��CExecOrder
	///@return	�õ���һ��CExecOrder�����û�У��򷵻�NULL
	CExecOrder *getNext(void);
	
	///������ȡCExecOrder
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CExecOrderActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CExecOrderActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CExecOrderCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CExecOrderCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	///��������ָ���Ļ�Ա�ͻ���ָ��
	///@param	pFactory	����ָ���Ļ�Ա�ͻ���ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllPartClient(CPartClientFactory *pFactory);
	
	///�������ж�Ӧ�ĺ�Լ��ָ��
	///@param	pFactory	�����Ӧ�ĺ�Լ��ָ��ʱ��Ѱ�ҵĶ��󹤳�
	void linkAllInstrument(CInstrumentFactory *pFactory);
	
	friend class CExecOrderIteratorBySettlementGroupID;

	///��ʼѰ��CExecOrder
	///@param	SettlementGroupID	��������
	///@return	���������ĵ�һ��CExecOrder������Ҳ���������NULL
	CExecOrder *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CExecOrder��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CExecOrder *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CExecOrder
	///@param	ExecOrderSysID	ִ������ϵͳ���
	///@return	�ҵ���CExecOrder������Ҳ���������NULL
	CExecOrder *findByExecOrderID( const CReadOnlyExecOrderSysIDType&  ExecOrderSysID);



	friend class CExecOrderIteratorByParticipantID;

	///��ʼѰ��CExecOrder
	///@param	ParticipantID	��Ա��
	///@return	���������ĵ�һ��CExecOrder������Ҳ���������NULL
	CExecOrder *startFindByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CExecOrder��������startFindByParticipantID�Ժ�endFindByParticipantID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CExecOrder *findNextByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByParticipantID(void);

	friend class CExecOrderIteratorByClientID;

	///��ʼѰ��CExecOrder
	///@param	ClientID	�ͻ���
	///@return	���������ĵ�һ��CExecOrder������Ҳ���������NULL
	CExecOrder *startFindByClientID( const CReadOnlyClientIDType& ClientID);

	///Ѱ����һ������������CExecOrder��������startFindByClientID�Ժ�endFindByClientID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CExecOrder *findNextByClientID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByClientID(void);

	friend class CExecOrderIteratorByClientIDAndInstrumentID;

	///��ʼѰ��CExecOrder
	///@param	ClientID	�ͻ���
	///@param	InstrumentID	��Լ��
	///@return	���������ĵ�һ��CExecOrder������Ҳ���������NULL
	CExecOrder *startFindByClientIDAndInstrumentID( const CReadOnlyClientIDType& ClientID,  const CReadOnlyInstrumentIDType& InstrumentID);

	///Ѱ����һ������������CExecOrder��������startFindByClientIDAndInstrumentID�Ժ�endFindByClientIDAndInstrumentID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CExecOrder *findNextByClientIDAndInstrumentID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByClientIDAndInstrumentID(void);

	///Ѱ��CExecOrder
	///@param	UserID	����Ա����
	///@param	ExecOrderLocalID	�������ر��
	///@return	�ҵ���CExecOrder������Ҳ���������NULL
	CExecOrder *findByExecOrderLocalID( const CReadOnlyUserIDType&  UserID,  const CReadOnlyOrderLocalIDType&  ExecOrderLocalID);



	friend class CExecOrderIteratorByUserID;

	///��ʼѰ��CExecOrder
	///@param	UserID	����Ա����
	///@return	���������ĵ�һ��CExecOrder������Ҳ���������NULL
	CExecOrder *startFindByUserID( const CReadOnlyUserIDType& UserID);

	///Ѱ����һ������������CExecOrder��������startFindByUserID�Ժ�endFindByUserID֮ǰ����
	///@return	��һ����������CExecOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CExecOrder *findNextByUserID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindByUserID(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CExecOrder���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pExecOrder	Ҫ�����ExecOrder
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CExecOrder *internalAdd(CWriteableExecOrder *pExecOrder, bool bNoTransaction);
	
	
	///ˢ�¸�CExecOrder�ļ�ֵ
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	///@param	pNewExecOrder	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CExecOrder��ͬʱɾ��������
	///@param	pExecOrder	Ҫɾ����CExecOrder
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CExecOrder *pExecOrder, bool bNoTransaction);
/*
	///���ĳ��CExecOrder�Ƿ����ڱ����󹤳�
	///@param	pExecOrder	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CExecOrder *pExecOrder);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ExecOrderSysID������
	CAVLTree *pExecOrderIDIndex;
	///����ParticipantID������
	CAVLTree *pParticipantIDIndex;
	///����ClientID+InstrumentID������
	CAVLTree *pClientAndInstrumentIndex;
	///����UserID+ExecOrderLocalID������
	CAVLTree *pExecOrderLocalIDIndex;
	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CExecOrder *pLastFoundInSearchBySettlementGroupID;
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByParticipantID;
	///����ClientID����ʱ���洢�Ĳ�ѯ����
	CClientIDType queryClientIDInSearchByClientID;
	
	///����ClientID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByClientID;
	///����ClientID��InstrumentID����ʱ���洢�Ĳ�ѯ����
	CClientIDType queryClientIDInSearchByClientIDAndInstrumentID;
	CInstrumentIDType queryInstrumentIDInSearchByClientIDAndInstrumentID;
	
	///����ClientID��InstrumentID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByClientIDAndInstrumentID;
	///����UserID����ʱ���洢�Ĳ�ѯ����
	CUserIDType queryUserIDInSearchByUserID;
	
	///����UserID����ʱ���洢���һ���ҵ��������ڵ�
	CAVLNode *pLastFoundInSearchByUserID;
	
	///����ǰ����
	///@param	pExecOrder	Ҫ�����ExecOrder
	virtual void beforeAdd(CWriteableExecOrder *pExecOrder);
	
	///����󴥷�
	///@param	pExecOrder	�Ѿ������ExecOrder
	virtual void afterAdd(CExecOrder *pExecOrder);

	///����ǰ����	
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	///@param	pNewExecOrder	�µ�ֵ
	virtual void beforeUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pNewExecOrder);
	
	///���º󴥷�
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	virtual void afterUpdate(CExecOrder *pExecOrder);
	
	///ɾ��ǰ����
	///@param	pExecOrder	Ҫɾ����CExecOrder
	virtual void beforeRemove(CExecOrder *pExecOrder);
	
	///ȷ�ϼ���󴥷�
	///@param	pExecOrder	�Ѿ������ExecOrder
	virtual void commitAdd(CExecOrder *pExecOrder);

	///ȷ�ϸ��º󴥷�
	///@param	pExecOrder	��ˢ�µ�CExecOrder
	///@param	poldExecOrder	ԭ����ֵ
	virtual void commitUpdate(CExecOrder *pExecOrder, CWriteableExecOrder *pOldExecOrder);
	
	///ȷ��ɾ���󴥷�
	///@param	pExecOrder	�Ѿ�ɾ����CExecOrder
	virtual void commitRemove(CWriteableExecOrder *pExecOrder);

	///������صĴ�����
	vector<CExecOrderActionTrigger *> *pActionTriggers;
	vector<CExecOrderCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableExecOrder compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CUniPressureFactory��һ������������Ķ��󹤳�����������һ�������������
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԵ������������ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CUniPressureFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUniPressureFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxUniPressure��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CUniPressureFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CUniPressureFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�UniPressure
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�UniPressure���ļ��������������ļ��еĶ���UniPressureCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�UniPressure
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�UniPressure���ļ��������������ļ��еĶ���UniPressureCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CUniPressureResource;

	///��һ��CUniPressure���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUniPressure	Ҫ�����UniPressure
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUniPressure *add(CWriteableUniPressure *pUniPressure, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CUniPressure��ֵ
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	///@param	pNewUniPressure	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pUniPressure	  ��Ҫ��ˢ�»���������CUniPressure,����NULL��ʾ����Ҫ������
	///@param	pNewUniPressure	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CUniPressure* addOrUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CUniPressure��ͬʱɾ��������
	///@param	pUniPressure	Ҫɾ����CUniPressure
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CUniPressure *pUniPressure, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CUniPressure
	///@param	pUniPressure	Ҫ��ȡ��CUniPressure
	///@param	pTragetUniPressure	��Ž����CUniPressure
	void retrieve(CUniPressure *pUniPressure, CWriteableUniPressure *pTargetUniPressure);
	
	///��ȡ��һ��CUniPressure
	///@return	�õ��ĵ�һ��CUniPressure�����û�У��򷵻�NULL
	CUniPressure *getFirst(void);
	
	///��ȡ��һ��CUniPressure
	///@return	�õ���һ��CUniPressure�����û�У��򷵻�NULL
	CUniPressure *getNext(void);
	
	///������ȡCUniPressure
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CUniPressureActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CUniPressureActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CUniPressureCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CUniPressureCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CUniPressureIteratorBySettlementGroupID;

	///��ʼѰ��CUniPressure
	///@param	SettlementGroupID	��������
	///@return	���������ĵ�һ��CUniPressure������Ҳ���������NULL
	CUniPressure *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CUniPressure��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CUniPressure������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CUniPressure *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CUniPressure
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CUniPressure������Ҳ���������NULL
	CUniPressure *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CUniPressure���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pUniPressure	Ҫ�����UniPressure
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CUniPressure *internalAdd(CWriteableUniPressure *pUniPressure, bool bNoTransaction);
	
	
	///ˢ�¸�CUniPressure�ļ�ֵ
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	///@param	pNewUniPressure	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CUniPressure��ͬʱɾ��������
	///@param	pUniPressure	Ҫɾ����CUniPressure
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CUniPressure *pUniPressure, bool bNoTransaction);
/*
	///���ĳ��CUniPressure�Ƿ����ڱ����󹤳�
	///@param	pUniPressure	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CUniPressure *pUniPressure);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CUniPressure *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pUniPressure	Ҫ�����UniPressure
	virtual void beforeAdd(CWriteableUniPressure *pUniPressure);
	
	///����󴥷�
	///@param	pUniPressure	�Ѿ������UniPressure
	virtual void afterAdd(CUniPressure *pUniPressure);

	///����ǰ����	
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	///@param	pNewUniPressure	�µ�ֵ
	virtual void beforeUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pNewUniPressure);
	
	///���º󴥷�
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	virtual void afterUpdate(CUniPressure *pUniPressure);
	
	///ɾ��ǰ����
	///@param	pUniPressure	Ҫɾ����CUniPressure
	virtual void beforeRemove(CUniPressure *pUniPressure);
	
	///ȷ�ϼ���󴥷�
	///@param	pUniPressure	�Ѿ������UniPressure
	virtual void commitAdd(CUniPressure *pUniPressure);

	///ȷ�ϸ��º󴥷�
	///@param	pUniPressure	��ˢ�µ�CUniPressure
	///@param	poldUniPressure	ԭ����ֵ
	virtual void commitUpdate(CUniPressure *pUniPressure, CWriteableUniPressure *pOldUniPressure);
	
	///ȷ��ɾ���󴥷�
	///@param	pUniPressure	�Ѿ�ɾ����CUniPressure
	virtual void commitRemove(CWriteableUniPressure *pUniPressure);

	///������صĴ�����
	vector<CUniPressureActionTrigger *> *pActionTriggers;
	vector<CUniPressureCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableUniPressure compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CBasePriceLimitFactory��һ���ǵ�ͣ�����õĶ��󹤳�����������һ���ǵ�ͣ�����ã�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶ��ǵ�ͣ�����õ���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CBasePriceLimitFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CBasePriceLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxBasePriceLimit��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CBasePriceLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CBasePriceLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�BasePriceLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�BasePriceLimit���ļ��������������ļ��еĶ���BasePriceLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�BasePriceLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�BasePriceLimit���ļ��������������ļ��еĶ���BasePriceLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CBasePriceLimitResource;

	///��һ��CBasePriceLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pBasePriceLimit	Ҫ�����BasePriceLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CBasePriceLimit *add(CWriteableBasePriceLimit *pBasePriceLimit, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CBasePriceLimit��ֵ
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	///@param	pNewBasePriceLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pBasePriceLimit	  ��Ҫ��ˢ�»���������CBasePriceLimit,����NULL��ʾ����Ҫ������
	///@param	pNewBasePriceLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CBasePriceLimit* addOrUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CBasePriceLimit��ͬʱɾ��������
	///@param	pBasePriceLimit	Ҫɾ����CBasePriceLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CBasePriceLimit *pBasePriceLimit, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CBasePriceLimit
	///@param	pBasePriceLimit	Ҫ��ȡ��CBasePriceLimit
	///@param	pTragetBasePriceLimit	��Ž����CBasePriceLimit
	void retrieve(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pTargetBasePriceLimit);
	
	///��ȡ��һ��CBasePriceLimit
	///@return	�õ��ĵ�һ��CBasePriceLimit�����û�У��򷵻�NULL
	CBasePriceLimit *getFirst(void);
	
	///��ȡ��һ��CBasePriceLimit
	///@return	�õ���һ��CBasePriceLimit�����û�У��򷵻�NULL
	CBasePriceLimit *getNext(void);
	
	///������ȡCBasePriceLimit
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CBasePriceLimitActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CBasePriceLimitActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CBasePriceLimitCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CBasePriceLimitCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CBasePriceLimitIteratorBySettlementGroupID;

	///��ʼѰ��CBasePriceLimit
	///@param	SettlementGroupID	��������
	///@return	���������ĵ�һ��CBasePriceLimit������Ҳ���������NULL
	CBasePriceLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CBasePriceLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CBasePriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CBasePriceLimit *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CBasePriceLimit
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CBasePriceLimit������Ҳ���������NULL
	CBasePriceLimit *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CBasePriceLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pBasePriceLimit	Ҫ�����BasePriceLimit
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CBasePriceLimit *internalAdd(CWriteableBasePriceLimit *pBasePriceLimit, bool bNoTransaction);
	
	
	///ˢ�¸�CBasePriceLimit�ļ�ֵ
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	///@param	pNewBasePriceLimit	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CBasePriceLimit��ͬʱɾ��������
	///@param	pBasePriceLimit	Ҫɾ����CBasePriceLimit
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CBasePriceLimit *pBasePriceLimit, bool bNoTransaction);
/*
	///���ĳ��CBasePriceLimit�Ƿ����ڱ����󹤳�
	///@param	pBasePriceLimit	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CBasePriceLimit *pBasePriceLimit);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CBasePriceLimit *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pBasePriceLimit	Ҫ�����BasePriceLimit
	virtual void beforeAdd(CWriteableBasePriceLimit *pBasePriceLimit);
	
	///����󴥷�
	///@param	pBasePriceLimit	�Ѿ������BasePriceLimit
	virtual void afterAdd(CBasePriceLimit *pBasePriceLimit);

	///����ǰ����	
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	///@param	pNewBasePriceLimit	�µ�ֵ
	virtual void beforeUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pNewBasePriceLimit);
	
	///���º󴥷�
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	virtual void afterUpdate(CBasePriceLimit *pBasePriceLimit);
	
	///ɾ��ǰ����
	///@param	pBasePriceLimit	Ҫɾ����CBasePriceLimit
	virtual void beforeRemove(CBasePriceLimit *pBasePriceLimit);
	
	///ȷ�ϼ���󴥷�
	///@param	pBasePriceLimit	�Ѿ������BasePriceLimit
	virtual void commitAdd(CBasePriceLimit *pBasePriceLimit);

	///ȷ�ϸ��º󴥷�
	///@param	pBasePriceLimit	��ˢ�µ�CBasePriceLimit
	///@param	poldBasePriceLimit	ԭ����ֵ
	virtual void commitUpdate(CBasePriceLimit *pBasePriceLimit, CWriteableBasePriceLimit *pOldBasePriceLimit);
	
	///ȷ��ɾ���󴥷�
	///@param	pBasePriceLimit	�Ѿ�ɾ����CBasePriceLimit
	virtual void commitRemove(CWriteableBasePriceLimit *pBasePriceLimit);

	///������صĴ�����
	vector<CBasePriceLimitActionTrigger *> *pActionTriggers;
	vector<CBasePriceLimitCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableBasePriceLimit compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCreditLimitFactory��һ�������޶�Ķ��󹤳�����������һ�������޶
///ͬʱ�ֽ����������������Է����ѯ��
///	ParticipantIDIndex
///ʹ�ñ����󹤳���������ɶ������޶����ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByParticipantID��Ψһ�ҵ�����
///		ʹ��startFindAllByParticipantID��findNextAllByParticipantID��endFindAllByParticipantID��ɲ�ѯ����
///		ʹ��startFindAllByClearingPartID��findNextAllByClearingPartID��endFindAllByClearingPartID��ɲ�ѯ����
///		ʹ��startFindAll��findNextAll��endFindAll��ɲ�ѯ����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCreditLimitFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCreditLimitFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCreditLimit��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCreditLimitFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCreditLimitFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CreditLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CreditLimit���ļ��������������ļ��еĶ���CreditLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CreditLimit
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CreditLimit���ļ��������������ļ��еĶ���CreditLimitCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCreditLimitResource;

	///��һ��CCreditLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCreditLimit	Ҫ�����CreditLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCreditLimit *add(CWriteableCreditLimit *pCreditLimit, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCreditLimit��ֵ
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	///@param	pNewCreditLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCreditLimit	  ��Ҫ��ˢ�»���������CCreditLimit,����NULL��ʾ����Ҫ������
	///@param	pNewCreditLimit	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCreditLimit* addOrUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCreditLimit��ͬʱɾ��������
	///@param	pCreditLimit	Ҫɾ����CCreditLimit
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCreditLimit *pCreditLimit, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCreditLimit
	///@param	pCreditLimit	Ҫ��ȡ��CCreditLimit
	///@param	pTragetCreditLimit	��Ž����CCreditLimit
	void retrieve(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pTargetCreditLimit);
	
	///��ȡ��һ��CCreditLimit
	///@return	�õ��ĵ�һ��CCreditLimit�����û�У��򷵻�NULL
	CCreditLimit *getFirst(void);
	
	///��ȡ��һ��CCreditLimit
	///@return	�õ���һ��CCreditLimit�����û�У��򷵻�NULL
	CCreditLimit *getNext(void);
	
	///������ȡCCreditLimit
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCreditLimitActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCreditLimitActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCreditLimitCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCreditLimitCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCreditLimitIteratorBySettlementGroupID;

	///��ʼѰ��CCreditLimit
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCreditLimit������Ҳ���������NULL
	CCreditLimit *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCreditLimit��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCreditLimit *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCreditLimit
	///@param	SettlementGroupID	��������
	///@param	ParticipantID	��Ա���
	///@return	�ҵ���CCreditLimit������Ҳ���������NULL
	CCreditLimit *findByParticipantID( const CReadOnlySettlementGroupIDType&  SettlementGroupID,  const CReadOnlyParticipantIDType&  ParticipantID);



	friend class CCreditLimitIteratorAllByParticipantID;

	///��ʼѰ��CCreditLimit
	///@param	ParticipantID	���׻�Ա���
	///@return	���������ĵ�һ��CCreditLimit������Ҳ���������NULL
	CCreditLimit *startFindAllByParticipantID( const CReadOnlyParticipantIDType& ParticipantID);

	///Ѱ����һ������������CCreditLimit��������startFindAllByParticipantID�Ժ�endFindAllByParticipantID֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCreditLimit *findNextAllByParticipantID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindAllByParticipantID(void);

	friend class CCreditLimitIteratorAllByClearingPartID;

	///��ʼѰ��CCreditLimit
	///@param	ClearingPartID	�����Ա���
	///@return	���������ĵ�һ��CCreditLimit������Ҳ���������NULL
	CCreditLimit *startFindAllByClearingPartID( const CReadOnlyParticipantIDType& ClearingPartID);

	///Ѱ����һ������������CCreditLimit��������startFindAllByClearingPartID�Ժ�endFindAllByClearingPartID֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCreditLimit *findNextAllByClearingPartID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindAllByClearingPartID(void);

	friend class CCreditLimitIteratorAll;

	///��ʼѰ��CCreditLimit
	///@return	���������ĵ�һ��CCreditLimit������Ҳ���������NULL
	CCreditLimit *startFindAll();

	///Ѱ����һ������������CCreditLimit��������startFindAll�Ժ�endFindAll֮ǰ����
	///@return	��һ����������CCreditLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCreditLimit *findNextAll(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindAll(void);

private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCreditLimit���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCreditLimit	Ҫ�����CreditLimit
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCreditLimit *internalAdd(CWriteableCreditLimit *pCreditLimit, bool bNoTransaction);
	
	
	///ˢ�¸�CCreditLimit�ļ�ֵ
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	///@param	pNewCreditLimit	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCreditLimit��ͬʱɾ��������
	///@param	pCreditLimit	Ҫɾ����CCreditLimit
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCreditLimit *pCreditLimit, bool bNoTransaction);
/*
	///���ĳ��CCreditLimit�Ƿ����ڱ����󹤳�
	///@param	pCreditLimit	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCreditLimit *pCreditLimit);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����ParticipantID+SettlementGroupID������
	CAVLTree *pParticipantIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCreditLimit *pLastFoundInSearchBySettlementGroupID;
	///����ParticipantID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryParticipantIDInSearchAllByParticipantID;
	
	///����ParticipantID����ʱ���洢���һ���ҵ��������ڵ�
	CCreditLimit *pLastFoundInSearchAllByParticipantID;
	///����ClearingPartID����ʱ���洢�Ĳ�ѯ����
	CParticipantIDType queryClearingPartIDInSearchAllByClearingPartID;
	
	///����ClearingPartID����ʱ���洢���һ���ҵ��������ڵ�
	CCreditLimit *pLastFoundInSearchAllByClearingPartID;
	///���ռ���ʱ���洢�Ĳ�ѯ����
	
	///���ռ���ʱ���洢���һ���ҵ��������ڵ�
	CCreditLimit *pLastFoundInSearchAll;
	
	///����ǰ����
	///@param	pCreditLimit	Ҫ�����CreditLimit
	virtual void beforeAdd(CWriteableCreditLimit *pCreditLimit);
	
	///����󴥷�
	///@param	pCreditLimit	�Ѿ������CreditLimit
	virtual void afterAdd(CCreditLimit *pCreditLimit);

	///����ǰ����	
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	///@param	pNewCreditLimit	�µ�ֵ
	virtual void beforeUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pNewCreditLimit);
	
	///���º󴥷�
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	virtual void afterUpdate(CCreditLimit *pCreditLimit);
	
	///ɾ��ǰ����
	///@param	pCreditLimit	Ҫɾ����CCreditLimit
	virtual void beforeRemove(CCreditLimit *pCreditLimit);
	
	///ȷ�ϼ���󴥷�
	///@param	pCreditLimit	�Ѿ������CreditLimit
	virtual void commitAdd(CCreditLimit *pCreditLimit);

	///ȷ�ϸ��º󴥷�
	///@param	pCreditLimit	��ˢ�µ�CCreditLimit
	///@param	poldCreditLimit	ԭ����ֵ
	virtual void commitUpdate(CCreditLimit *pCreditLimit, CWriteableCreditLimit *pOldCreditLimit);
	
	///ȷ��ɾ���󴥷�
	///@param	pCreditLimit	�Ѿ�ɾ����CCreditLimit
	virtual void commitRemove(CWriteableCreditLimit *pCreditLimit);

	///������صĴ�����
	vector<CCreditLimitActionTrigger *> *pActionTriggers;
	vector<CCreditLimitCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCreditLimit compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

/////////////////////////////////////////////////////////////////////////
///CCurrInstrumentOptionFactory��һ�������ڻ���Լ��Ȩ���ԵĶ��󹤳�����������һ�������ڻ���Լ��Ȩ���ԣ�
///ͬʱ�ֽ����������������Է����ѯ��
///	InstrumentIDIndex
///ʹ�ñ����󹤳���������ɶԵ����ڻ���Լ��Ȩ���Ե���ɾ�Ĳ���������巽�����£�
///	���ӣ�����add����ɼ���
///	ɾ��������remove�Ϳ���ɾ��
///	��ѯ�������·������Բ�ѯ��
///		ʹ��startFindBySettlementGroupID��findNextBySettlementGroupID��endFindBySettlementGroupID��ɲ�ѯ����
///		ʹ��findByInstrumentID��Ψһ�ҵ�����
///	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
///	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
///		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrInstrumentOptionFactory :public CDatabaseDataFactory
{
public:
	///���췽��
	///@param	maxUnit	��ʼ�����ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrInstrumentOptionFactory(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID=-1, int readOnly=0);
	
	///���췽��
	///@param	pConfig	��ǰ�������ļ��������󽫸��������ļ��еĶ���MaxCurrInstrumentOption��������Ķ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	CCurrInstrumentOptionFactory(CConfig *pConfig,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse=false, int reuseID = -1,int readOnly=0);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CCurrInstrumentOptionFactory(void);

	virtual void output(CLogger *pLogger,int indent=0);
	
	///��CSV�ļ��ж�ȡ���е�CurrInstrumentOption
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(char *filename);

	///��CSV�ļ��ж�ȡ���е�CurrInstrumentOption���ļ��������������ļ��еĶ���CurrInstrumentOptionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int readCSV(CConfig *pConfig);
	
	///��CSV�ļ���д�����е�CurrInstrumentOption
	///@param	filename	�ļ���
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(char *filename);

	///��CSV�ļ���д�����е�CurrInstrumentOption���ļ��������������ļ��еĶ���CurrInstrumentOptionCSVFile
	///@param	pConfig	��ǰ�������ļ�
	///@return	1��ʾ��ɣ�0��ʾû�����
	virtual int writeCSV(CConfig *pConfig);

	///������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	///������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	///������еļ�¼
	virtual void clearAll(void);

	friend class CCurrInstrumentOptionResource;

	///��һ��CCurrInstrumentOption���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrInstrumentOption	Ҫ�����CurrInstrumentOption
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrInstrumentOption *add(CWriteableCurrInstrumentOption *pCurrInstrumentOption, CTransaction *pTransaction=NULL);
	
	///ˢ�¸�CCurrInstrumentOption��ֵ
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	�Ƿ���Ҫ��������
	void update(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///���ӻ��߸�������
	///@param	pCurrInstrumentOption	  ��Ҫ��ˢ�»���������CCurrInstrumentOption,����NULL��ʾ����Ҫ������
	///@param	pNewCurrInstrumentOption	�µ�ֵ
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	///@param	updateIndex	  �Ƿ���Ҫ��������
	///@param	���������޸ĺ������
	CCurrInstrumentOption* addOrUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption, CTransaction *pTransaction=NULL, bool updateIndex=true);
	
	///ɾ��һ��CCurrInstrumentOption��ͬʱɾ��������
	///@param	pCurrInstrumentOption	Ҫɾ����CCurrInstrumentOption
	///@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	void remove(CCurrInstrumentOption *pCurrInstrumentOption, CTransaction *pTransaction=NULL);
	
	///��ȡĳ��CCurrInstrumentOption
	///@param	pCurrInstrumentOption	Ҫ��ȡ��CCurrInstrumentOption
	///@param	pTragetCurrInstrumentOption	��Ž����CCurrInstrumentOption
	void retrieve(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pTargetCurrInstrumentOption);
	
	///��ȡ��һ��CCurrInstrumentOption
	///@return	�õ��ĵ�һ��CCurrInstrumentOption�����û�У��򷵻�NULL
	CCurrInstrumentOption *getFirst(void);
	
	///��ȡ��һ��CCurrInstrumentOption
	///@return	�õ���һ��CCurrInstrumentOption�����û�У��򷵻�NULL
	CCurrInstrumentOption *getNext(void);
	
	///������ȡCCurrInstrumentOption
	void endGet(void);

	///����һ������������
	///@param	pTrigger	Ҫ����Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addActionTrigger(CCurrInstrumentOptionActionTrigger *pTrigger);
	
	///ɾ��һ������������
	///@param	pTrigger	Ҫɾ���Ĳ���������
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeActionTrigger(CCurrInstrumentOptionActionTrigger *pTrigger);

	///����һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫ�����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int addCommitTrigger(CCurrInstrumentOptionCommitTrigger *pTrigger);
	
	///ɾ��һ��ȷ�ϴ�����
	///@param	pTrigger	Ҫɾ����ȷ�ϴ�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	int removeCommitTrigger(CCurrInstrumentOptionCommitTrigger *pTrigger);
	
	///����ȷ�ϴ�������ȱʡ�Ǽ����
	///@param	activation	true��ʾҪ���false��ʾҪͣ��
	void activeCommitTrigger(bool activation);

	friend class CCurrInstrumentOptionIteratorBySettlementGroupID;

	///��ʼѰ��CCurrInstrumentOption
	///@param	SettlementGroupID	���������
	///@return	���������ĵ�һ��CCurrInstrumentOption������Ҳ���������NULL
	CCurrInstrumentOption *startFindBySettlementGroupID( const CReadOnlySettlementGroupIDType& SettlementGroupID);

	///Ѱ����һ������������CCurrInstrumentOption��������startFindBySettlementGroupID�Ժ�endFindBySettlementGroupID֮ǰ����
	///@return	��һ����������CCurrInstrumentOption������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	CCurrInstrumentOption *findNextBySettlementGroupID(void);

	///������һ�β�ѯ������ɲ�ѯ�������ñ�����
	void endFindBySettlementGroupID(void);

	///Ѱ��CCurrInstrumentOption
	///@param	InstrumentID	��Լ����
	///@return	�ҵ���CCurrInstrumentOption������Ҳ���������NULL
	CCurrInstrumentOption *findByInstrumentID( const CReadOnlyInstrumentIDType&  InstrumentID);



private:
	///����Լ��ĳ�ʼ������
	///@param	maxUnit	�������ݶ������
	///@param	pAllocator	�����ڴ����ķ�����
	///@param	pIndexMap	�������ƺ��ڴ��ŵĶ�Ӧ���ڷ�����ʱ��д�룬������ʱֻ����
	///@param	reuse	�Ƿ�����
	///@param	reuseID	���ñ�ţ�������ʱӦ����Ϊ-1
	///@param	readOnly	1��ʾ��CFixMem��ֻ���ģ�0��ʾ���Զ�д
	void init(int maxUnit,IMemoryAllocator *pAllocator,map<string,int>* pIndexMap,bool reuse,int reuseID,int readOnly);
	
	
	///��һ��CCurrInstrumentOption���뵽�ö��󹤳���ʵ����������޸������Ĺ���
	///@param	pCurrInstrumentOption	Ҫ�����CurrInstrumentOption
	///@param	bNoTransaction �Ƿ������κ�����
	///@return	�����ö����λ�ã���pTransaction!=NULLʱ�����Ƿ���NULL
	CCurrInstrumentOption *internalAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption, bool bNoTransaction);
	
	
	///ˢ�¸�CCurrInstrumentOption�ļ�ֵ
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	�µ�ֵ
	///@param	updateIndex	�Ƿ���Ҫ��������
	///@param	bNoTransaction �Ƿ������κ�����
	void internalUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption, bool updateIndex,bool bNoTransaction);
	
	///ɾ��һ��CCurrInstrumentOption��ͬʱɾ��������
	///@param	pCurrInstrumentOption	Ҫɾ����CCurrInstrumentOption
	///@param	bNoTransaction �Ƿ������κ�����
	void internalRemove(CCurrInstrumentOption *pCurrInstrumentOption, bool bNoTransaction);
/*
	///���ĳ��CCurrInstrumentOption�Ƿ����ڱ����󹤳�
	///@param	pCurrInstrumentOption	Ҫ���Ķ���
	///@exception	CDesignError	��������ڣ����׳����쳣
	void checkAddress(CCurrInstrumentOption *pCurrInstrumentOption);
*/
	///ʹ�õ������ļ�
	CConfig *m_pConfig;

	///����InstrumentID������
	CAVLTree *pInstrumentIDIndex;
	
	
	///����SettlementGroupID����ʱ���洢�Ĳ�ѯ����
	CSettlementGroupIDType querySettlementGroupIDInSearchBySettlementGroupID;
	
	///����SettlementGroupID����ʱ���洢���һ���ҵ��������ڵ�
	CCurrInstrumentOption *pLastFoundInSearchBySettlementGroupID;
	
	///����ǰ����
	///@param	pCurrInstrumentOption	Ҫ�����CurrInstrumentOption
	virtual void beforeAdd(CWriteableCurrInstrumentOption *pCurrInstrumentOption);
	
	///����󴥷�
	///@param	pCurrInstrumentOption	�Ѿ������CurrInstrumentOption
	virtual void afterAdd(CCurrInstrumentOption *pCurrInstrumentOption);

	///����ǰ����	
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	///@param	pNewCurrInstrumentOption	�µ�ֵ
	virtual void beforeUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pNewCurrInstrumentOption);
	
	///���º󴥷�
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	virtual void afterUpdate(CCurrInstrumentOption *pCurrInstrumentOption);
	
	///ɾ��ǰ����
	///@param	pCurrInstrumentOption	Ҫɾ����CCurrInstrumentOption
	virtual void beforeRemove(CCurrInstrumentOption *pCurrInstrumentOption);
	
	///ȷ�ϼ���󴥷�
	///@param	pCurrInstrumentOption	�Ѿ������CurrInstrumentOption
	virtual void commitAdd(CCurrInstrumentOption *pCurrInstrumentOption);

	///ȷ�ϸ��º󴥷�
	///@param	pCurrInstrumentOption	��ˢ�µ�CCurrInstrumentOption
	///@param	poldCurrInstrumentOption	ԭ����ֵ
	virtual void commitUpdate(CCurrInstrumentOption *pCurrInstrumentOption, CWriteableCurrInstrumentOption *pOldCurrInstrumentOption);
	
	///ȷ��ɾ���󴥷�
	///@param	pCurrInstrumentOption	�Ѿ�ɾ����CCurrInstrumentOption
	virtual void commitRemove(CWriteableCurrInstrumentOption *pCurrInstrumentOption);

	///������صĴ�����
	vector<CCurrInstrumentOptionActionTrigger *> *pActionTriggers;
	vector<CCurrInstrumentOptionCommitTrigger *> *pCommitTriggers;
	
	///���в�ѯʱ�����ڱȽϵĶ���
	CWriteableCurrInstrumentOption compareObject;
	
	///�Ƿ񼤻�ȷ�ϴ�����
	bool m_activeCommitTrigger;
};

#endif
