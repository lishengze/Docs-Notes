/////////////////////////////////////////////////////////////////////////
///@system ִ������ϵͳ
///@company �Ϻ��ڻ���Ϣ�������޹�˾
///@file CMemoryDB.h
///@brief��������CMemoryDB
///@history 
///20050824	���ض�		�������ļ�
///20120111 ����		NT-0163 kernel����������ָ���û��������
/////////////////////////////////////////////////////////////////////////

#ifndef CMEMORYDB_H
#define CMEMORYDB_H

#include "CBaseObject.h"
#include "CConfig.h"
#include "BaseDataStruct.h"
#include "databaseFactories.h"
#include "databaseIterators.h"

struct TableStruct
{
	char tableName[100];
	int  reuseID;
};
/////////////////////////////////////////////////////////////////////////
///CMemoryDB��һ���ڴ����ݿ��࣬���������ж���ı���Ϣ
///@author	���ض�
///@version	1.0,20050824
/////////////////////////////////////////////////////////////////////////
class CMemoryDB : public CBaseObject
{
public:
	///���췽���������ڴ����ݿ�
	CMemoryDB(void);
	
	///�����������������ͷ���ռ�õĿռ�
	virtual ~CMemoryDB(void);
	
	virtual int isA(char *objectType);
	virtual char *getType(void);
	virtual void output(CLogger *pLogger,int indent=0);

	///���г�ʼ������
	///@param	pConfig	��ʼ��ʱʹ�õ�������Ϣ
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual int init(CConfig *pConfig,IMemoryAllocator *pAllocator=NULL,bool reuse=false);
	
	///�����������빤��
	///@param	pConfig	��������ʱʹ�õ�������Ϣ
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual int load(CConfig *pConfig);

	///�������ݴ洢����
	///@param	pConfig	��������ʱʹ�õ�������Ϣ
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual int save(CConfig *pConfig);
	
	///������е�����
	///@return	1��ʾ�ɹ���0��ʾʧ��
	virtual void clear(void);
	
	///����������������
	virtual void linkAll(void);
	
	
	
	///����������ͬ��״̬��
	CExchangeDataSyncStatusFactory *m_ExchangeDataSyncStatusFactory;
	
	///����������ͬ��״̬��
	CSGDataSyncStatusFactory *m_SGDataSyncStatusFactory;
	
	///��ǰʱ���
	CCurrentTimeFactory *m_CurrentTimeFactory;
	
	///��������������
	CDataCenterDescFactory *m_DataCenterDescFactory;
	
	///��������
	CExchangeFactory *m_ExchangeFactory;
	
	///�������
	CSettlementGroupFactory *m_SettlementGroupFactory;
	
	///�г���
	CMarketFactory *m_MarketFactory;
	
	///�г���Ʒ������
	CMarketProductFactory *m_MarketProductFactory;
	
	///�г���Ʒ�������
	CMarketProductGroupFactory *m_MarketProductGroupFactory;
	
	///���鷢��״̬��
	CMdPubStatusFactory *m_MdPubStatusFactory;
	
	///���������
	CMarketDataTopicFactory *m_MarketDataTopicFactory;
	
	///��Ա�����г���
	CPartTopicSubscribeFactory *m_PartTopicSubscribeFactory;
	
	///��Ա��
	CParticipantFactory *m_ParticipantFactory;
	
	///�û���
	CUserFactory *m_UserFactory;
	
	///�ͻ���
	CClientFactory *m_ClientFactory;
	
	///����ԱIP��ַ��
	CUserIPFactory *m_UserIPFactory;
	
	///��Ա�ͻ���ϵ��
	CPartClientFactory *m_PartClientFactory;
	
	///���㽻�׻�Ա��ϵ��
	CClearingTradingPartFactory *m_ClearingTradingPartFactory;
	
	///���������
	CAliasDefineFactory *m_AliasDefineFactory;
	
	///�û�����Ȩ�ޱ�
	CUserFunctionRightFactory *m_UserFunctionRightFactory;
	
	///�ʽ��˻���
	CAccountFactory *m_AccountFactory;
	
	///�û�ͨѶ����
	CUserCommFluxFactory *m_UserCommFluxFactory;
	
	///������ˮ��
	CMarketDataLogFactory *m_MarketDataLogFactory;
	
	///����Ա���߻Ự��
	CUserSessionFactory *m_UserSessionFactory;
	
	///���鶩�������߻Ự��
	CMDSessionFactory *m_MDSessionFactory;
	
	///�û���½�ǳ���Ϣ��
	CLoginInfoFactory *m_LoginInfoFactory;
	
	///����г�������ϸ��
	CDepthMarketDataDetailFactory *m_DepthMarketDataDetailFactory;
	
	///��Լ����״̬��ˮ��
	CInstrumentStatusDetailFactory *m_InstrumentStatusDetailFactory;
	
	///ǰ��״̬��
	CFrontStatusFactory *m_FrontStatusFactory;
	
	///��󱾵ر����ű�
	CMaxLocalIDFactory *m_MaxLocalIDFactory;
	
	///������Ϣ��
	CBulletinFactory *m_BulletinFactory;
	
	///����䶯��
	CMarketDataModifyFactory *m_MarketDataModifyFactory;
	
	///��������
	CDepthMarketDataFactory *m_DepthMarketDataFactory;
	
	///�����������
	CTopicMarketDataFactory *m_TopicMarketDataFactory;
	
	///������������ձ�
	CTopicMarketDataVersionFactory *m_TopicMarketDataVersionFactory;
	
	///��Ϣ��
	CInformationFactory *m_InformationFactory;
	
	///����������
	COrderCountFactory *m_OrderCountFactory;
	
	///��Լ��
	CInstrumentFactory *m_InstrumentFactory;
	
	///��Ϻ�Լ���ȱ�
	CCombinationLegFactory *m_CombinationLegFactory;
	
	///��Ա�˻���ϵ��
	CPartRoleAccountFactory *m_PartRoleAccountFactory;
	
	///��Ա��Ʒ��ɫ��
	CPartProductRoleFactory *m_PartProductRoleFactory;
	
	///��Ա��Ʒ����Ȩ�ޱ�
	CPartProductRightFactory *m_PartProductRightFactory;
	
	///��Ա��Լ����Ȩ�ޱ�
	CPartInstrumentRightFactory *m_PartInstrumentRightFactory;
	
	///�ͻ���Ʒ����Ȩ�ޱ�
	CClientProductRightFactory *m_ClientProductRightFactory;
	
	///�ͻ���Լ����Ȩ�ޱ�
	CClientInstrumentRightFactory *m_ClientInstrumentRightFactory;
	
	///��Ա�ͻ���Ʒ����Ȩ�ޱ�
	CPartClientProductRightFactory *m_PartClientProductRightFactory;
	
	///��Ա�ͻ���Լ����Ȩ�ޱ�
	CPartClientInstrumentRightFactory *m_PartClientInstrumentRightFactory;
	
	///��Ʒ���Ա�
	CCurrProductPropertyFactory *m_CurrProductPropertyFactory;
	
	///��Լ���Ա�
	CCurrInstrumentPropertyFactory *m_CurrInstrumentPropertyFactory;
	
	///��ǰ�۸�󶨱�
	CCurrPriceBandingFactory *m_CurrPriceBandingFactory;
	
	///�����Լ��֤���ʱ�
	CCurrMarginRateFactory *m_CurrMarginRateFactory;
	
	///�����Լ��֤���ʵ���ϸ���ݱ�
	CCurrMarginRateDetailFactory *m_CurrMarginRateDetailFactory;
	
	///��ǰ��Ա��Լ�޲ֱ�
	CCurrPartPosiLimitFactory *m_CurrPartPosiLimitFactory;
	
	///��ǰ��Ա��Լ�޲ֵ���ϸ���ݱ�
	CCurrPartPosiLimitDetailFactory *m_CurrPartPosiLimitDetailFactory;
	
	///��ǰ�ͻ���Լ�޲ֱ�
	CCurrClientPosiLimitFactory *m_CurrClientPosiLimitFactory;
	
	///��ǰ�ͻ���Լ�޲ֵ���ϸ���ݱ�
	CCurrClientPosiLimitDetailFactory *m_CurrClientPosiLimitDetailFactory;
	
	///��ǰ����ͻ���Լ�޲ֱ�
	CCurrSpecialPosiLimitFactory *m_CurrSpecialPosiLimitFactory;
	
	///��ǰ����ͻ���Լ�޲ֵ���ϸ���ݱ�
	CCurrSpecialPosiLimitDetailFactory *m_CurrSpecialPosiLimitDetailFactory;
	
	///��ǰ��Լ���ڱ�ֵ���Ա�
	CCurrHedgeRuleFactory *m_CurrHedgeRuleFactory;
	
	///��ǰ��Լ���׽׶����Ա�
	CCurrTradingSegmentAttrFactory *m_CurrTradingSegmentAttrFactory;
	
	///��ǰ��Լ�۶����Ա�
	CCurrFuseFactory *m_CurrFuseFactory;
	
	///�����˻���
	CTradingAccountFactory *m_TradingAccountFactory;
	
	///����׼�����˻���
	CBaseReserveAccountFactory *m_BaseReserveAccountFactory;
	
	///��Ա�ֱֲ�
	CPartPositionFactory *m_PartPositionFactory;
	
	///�ͻ��ֱֲ�
	CClientPositionFactory *m_ClientPositionFactory;
	
	///��ֵ�������
	CHedgeVolumeFactory *m_HedgeVolumeFactory;
	
	///��ʷ������
	CRemainOrderFactory *m_RemainOrderFactory;
	
	///�����
	CMarketDataFactory *m_MarketDataFactory;
	
	///�����Ա�ֱֲ�
	CClearingPartPositionFactory *m_ClearingPartPositionFactory;
	
	///��Լ״̬��
	CInstrumentStatusFactory *m_InstrumentStatusFactory;
	
	///������
	COrderFactory *m_OrderFactory;
	
	///��ϱ�����
	CCombOrderFactory *m_CombOrderFactory;
	
	///OTC������
	COTCOrderFactory *m_OTCOrderFactory;
	
	///��ʽ������
	CImplyOrderFactory *m_ImplyOrderFactory;
	
	///���۱�
	CQuoteFactory *m_QuoteFactory;
	
	///�ּ۱��
	CMBLMarketDataFactory *m_MBLMarketDataFactory;
	
	///�ɽ���
	CTradeFactory *m_TradeFactory;
	
	///�۶Ͻ׶α�
	CFusePhaseFactory *m_FusePhaseFactory;
	
	///ִ�������
	CExecOrderFactory *m_ExecOrderFactory;
	
	///�����������
	CUniPressureFactory *m_UniPressureFactory;
	
	///�ǵ�ͣ�����ñ�
	CBasePriceLimitFactory *m_BasePriceLimitFactory;
	
	///�����޶��
	CCreditLimitFactory *m_CreditLimitFactory;
	
	///�����ڻ���Լ��Ȩ���Ա�
	CCurrInstrumentOptionFactory *m_CurrInstrumentOptionFactory;
	
	///��kernelǿ��ָ�����û�����
	CPasswordType m_ForceUserPassword;
	
private:
	CFixMem *pMem;		///������ű����Ϣ
};

#endif
