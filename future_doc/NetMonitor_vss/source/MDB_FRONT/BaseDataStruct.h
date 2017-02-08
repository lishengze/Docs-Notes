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

///64λ�޷��������ȽϺ���
///@param	v1	����1
///@param	v2	����2
///@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
int compare(const QWORD v1,const QWORD v2);

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

class CWriteableSysInvalidateOrder;
class CSysInvalidateOrderFactory;
class CWriteableSysOrderStatus;
class CSysOrderStatusFactory;
class CWriteableSysBargainOrder;
class CSysBargainOrderFactory;
class CWriteableSysInstProperty;
class CSysInstPropertyFactory;
class CWriteableSysMarginRate;
class CSysMarginRateFactory;
class CWriteableSysPriceLimit;
class CSysPriceLimitFactory;
class CWriteableSysPartPosiLimit;
class CSysPartPosiLimitFactory;
class CWriteableSysClientPosiLimit;
class CSysClientPosiLimitFactory;
class CWriteableSysSpecialPosiLimit;
class CSysSpecialPosiLimitFactory;
class CWriteableSysTransactionChg;
class CSysTransactionChgFactory;
class CWriteableSysClientChg;
class CSysClientChgFactory;
class CWriteableSysPartClientChg;
class CSysPartClientChgFactory;
class CWriteableSysPosiLimitChg;
class CSysPosiLimitChgFactory;
class CWriteableSysClientPosiLimitChg;
class CSysClientPosiLimitChgFactory;
class CWriteableSysSpecPosiLimitChg;
class CSysSpecPosiLimitChgFactory;
class CWriteableSysHedgeDetailChg;
class CSysHedgeDetailChgFactory;
class CWriteableSysParticipantChg;
class CSysParticipantChgFactory;
class CWriteableSysMarginRateChg;
class CSysMarginRateChgFactory;
class CWriteableSysUserIpChg;
class CSysUserIpChgFactory;
class CWriteableSysPartTrade;
class CSysPartTradeFactory;
class CWriteableSysMdbObjectAttr;
class CSysMdbObjectAttrFactory;
class CWriteableSysMdbSyslogInfo;
class CSysMdbSyslogInfoFactory;
class CWriteableSysUserInfo;
class CSysUserInfoFactory;
class CWriteableSysOnlineUserInfo;
class CSysOnlineUserInfoFactory;
class CWriteableSysWarningEvent;
class CSysWarningEventFactory;
class CWriteableSysWarningQuery;
class CSysWarningQueryFactory;
class CWriteableSyslogEvent;
class CSyslogEventFactory;
class CWriteableSysEventDescrip;
class CSysEventDescripFactory;
class CWriteableRspQryHostEnvCommon;
class CRspQryHostEnvCommonFactory;
class CWriteableRspQryHostEnvLan;
class CRspQryHostEnvLanFactory;
class CWriteableRspQryHostEnvStorage;
class CRspQryHostEnvStorageFactory;
class CWriteableRspQryHostEnvIO;
class CRspQryHostEnvIOFactory;
class CWriteableRspQryHostEnvFS;
class CRspQryHostEnvFSFactory;
class CWriteableRspQryHostEnvSwap;
class CRspQryHostEnvSwapFactory;
class CWriteableRspQryHostEnvLanCfg;
class CRspQryHostEnvLanCfgFactory;
class CWriteableSysMdbTopCpuInfo;
class CSysMdbTopCpuInfoFactory;
class CWriteableSysMdbTopMemInfo;
class CSysMdbTopMemInfoFactory;
class CWriteableSysMdbTopProcessInfo;
class CSysMdbTopProcessInfoFactory;
class CWriteableSysMdbFileSystemInfo;
class CSysMdbFileSystemInfoFactory;
class CWriteableSysMdbNetworkInfo;
class CSysMdbNetworkInfoFactory;
class CWriteableSysParticipantInit;
class CSysParticipantInitFactory;
class CWriteableSysUserInit;
class CSysUserInitFactory;
class CWriteableSysClientInit;
class CSysClientInitFactory;
class CWriteableSysTradeUserLoginInfo;
class CSysTradeUserLoginInfoFactory;
class CWriteableSysMdbWebAppInfo;
class CSysMdbWebAppInfoFactory;
class CWriteableSysMdbMemPoolInfo;
class CSysMdbMemPoolInfoFactory;
class CWriteableSysMdbConnectorInfo;
class CSysMdbConnectorInfoFactory;
class CWriteableSysMdbDBQuery;
class CSysMdbDBQueryFactory;
class CWriteableSysNetArea;
class CSysNetAreaFactory;
class CWriteableSysNetSubArea;
class CSysNetSubAreaFactory;
class CWriteableSysNetSubAreaIP;
class CSysNetSubAreaIPFactory;
class CWriteableSysNetFuncArea;
class CSysNetFuncAreaFactory;
class CWriteableSysNetDevice;
class CSysNetDeviceFactory;
class CWriteableSysNetDeviceLinked;
class CSysNetDeviceLinkedFactory;
class CWriteableSysNetOID;
class CSysNetOIDFactory;
class CWriteableSysNetDeviceType;
class CSysNetDeviceTypeFactory;
class CWriteableSysNetTimePolicy;
class CSysNetTimePolicyFactory;
class CWriteableSysNetGatherTask;
class CSysNetGatherTaskFactory;
class CWriteableSysNetDeviceCategory;
class CSysNetDeviceCategoryFactory;
class CWriteableSysNetManufactory;
class CSysNetManufactoryFactory;
class CWriteableSysNetCommunity;
class CSysNetCommunityFactory;
class CWriteableSysNetPortType;
class CSysNetPortTypeFactory;
class CWriteableSysNetInterface;
class CSysNetInterfaceFactory;
class CWriteableSysNetGeneralOID;
class CSysNetGeneralOIDFactory;
class CWriteableSysNetMonitorType;
class CSysNetMonitorTypeFactory;
class CWriteableSysNetMonitorAttrScope;
class CSysNetMonitorAttrScopeFactory;
class CWriteableSysNetMonitorAttrType;
class CSysNetMonitorAttrTypeFactory;
class CWriteableSysNetMonitorCommandType;
class CSysNetMonitorCommandTypeFactory;
class CWriteableSysNetMonitorActionGroup;
class CSysNetMonitorActionGroupFactory;
class CWriteableSysNetMonitorDeviceGroup;
class CSysNetMonitorDeviceGroupFactory;
class CWriteableSysNetMonitorTaskInfo;
class CSysNetMonitorTaskInfoFactory;
class CWriteableSysNetMonitorTaskObjectSet;
class CSysNetMonitorTaskObjectSetFactory;
class CWriteableSysNetMonitorTaskResult;
class CSysNetMonitorTaskResultFactory;
class CWriteableSysNetPartyLinkInfo;
class CSysNetPartyLinkInfoFactory;
class CWriteableSysNetDelPartyLinkInfo;
class CSysNetDelPartyLinkInfoFactory;
class CWriteableSysNetPartyLinkAddrChange;
class CSysNetPartyLinkAddrChangeFactory;
class CWriteableSysNetMonitorActionAttr;
class CSysNetMonitorActionAttrFactory;
class CWriteableSysNetModule;
class CSysNetModuleFactory;
class CWriteableSysNetEventExpr;
class CSysNetEventExprFactory;
class CWriteableSysNetEventType;
class CSysNetEventTypeFactory;
class CWriteableSysNetSubEventType;
class CSysNetSubEventTypeFactory;
class CWriteableSysNetEventLevel;
class CSysNetEventLevelFactory;
class CWriteableSysNetMonitorDeviceTask;
class CSysNetMonitorDeviceTaskFactory;
class CWriteableSysNetMonitorTaskInstAttrs;
class CSysNetMonitorTaskInstAttrsFactory;
class CWriteableSysNetBaseLine;
class CSysNetBaseLineFactory;
class CWriteableSysNetBaseLineTask;
class CSysNetBaseLineTaskFactory;
class CWriteableSysMdbNetPartyLinkStatusInfo;
class CSysMdbNetPartyLinkStatusInfoFactory;
class CWriteableSysNetMemberSDHLineInfo;
class CSysNetMemberSDHLineInfoFactory;
class CWriteableSysNetDDNLinkInfo;
class CSysNetDDNLinkInfoFactory;
class CWriteableSysNetPseudMemberLinkInfo;
class CSysNetPseudMemberLinkInfoFactory;
class CWriteableSysNetOuterDeviceInfo;
class CSysNetOuterDeviceInfoFactory;
class CWriteableSysLocalPingResultInfo;
class CSysLocalPingResultInfoFactory;
class CWriteableSysRomotePingResultInfo;
class CSysRomotePingResultInfoFactory;
class CWriteableSysParticTradeOrderStates;
class CSysParticTradeOrderStatesFactory;
class CWriteableSysMdbRouterInfo;
class CSysMdbRouterInfoFactory;
class CWriteableSysMdbDiskIO;
class CSysMdbDiskIOFactory;
class CWriteableSysMdbStatInfo;
class CSysMdbStatInfoFactory;
class CWriteableSysMdbTradeFrontOrderRttStat;
class CSysMdbTradeFrontOrderRttStatFactory;
class CWriteableSysInstrumentStatus;
class CSysInstrumentStatusFactory;
class CWriteableSysCurrTradingSegmentAttr;
class CSysCurrTradingSegmentAttrFactory;
class CWriteableSysMemberLinkCost;
class CSysMemberLinkCostFactory;
class CWriteableSysNetPartylinkMonthlyRent;
class CSysNetPartylinkMonthlyRentFactory;
class CWriteableSysNetNonPartyLinkInfo;
class CSysNetNonPartyLinkInfoFactory;

/////////////////////////////////////////////////////////////////////////
///CWriteableSysInvalidateOrder��һ���洢��Ч�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysInvalidateOrder
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ErrorMsg.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! InstrumentID.isValid())
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
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysInvalidateOrder *pOriginal) const;
	
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
	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///������Ϣ
	CErrorMsgType ErrorMsg;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�����û�����
	CUserIDType UserID;
	///�ͻ�����
	CClientIDType ClientID;
	///��Լ����
	CInstrumentIDType InstrumentID;
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
	///�ɽ�������
	CVolumeConditionType VolumeCondition;
	///��С�ɽ���
	CVolumeType MinVolume;
	
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

typedef const CWriteableSysInvalidateOrder CSysInvalidateOrder;

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderActionTrigger�ǲ�����Ч����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderActionTrigger
{
public:
	///���췽��
	CSysInvalidateOrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysInvalidateOrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysInvalidateOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysInvalidateOrder	Ҫ�����SysInvalidateOrder
	virtual void beforeAdd(CWriteableSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysInvalidateOrder	�Ѿ������SysInvalidateOrder
	virtual void afterAdd(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysInvalidateOrder	��ˢ�µ�CSysInvalidateOrder
	///@param	pNewSysInvalidateOrder	�µ�ֵ
	virtual void beforeUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pNewSysInvalidateOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysInvalidateOrder	��ˢ�µ�CSysInvalidateOrder
	virtual void afterUpdate(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysInvalidateOrder	Ҫɾ����CSysInvalidateOrder
	virtual void beforeRemove(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysInvalidateOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderCommitTrigger��ȷ����Ч����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderCommitTrigger
{
public:
	///���췽��
	CSysInvalidateOrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysInvalidateOrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysInvalidateOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysInvalidateOrder	�Ѿ������SysInvalidateOrder
	virtual void commitAdd(CSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysInvalidateOrder	��ˢ�µ�CSysInvalidateOrder
	///@param	poldSysInvalidateOrder	ԭ����ֵ
	virtual void commitUpdate(CSysInvalidateOrder *pSysInvalidateOrder, CWriteableSysInvalidateOrder *pOldSysInvalidateOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysInvalidateOrder	�Ѿ�ɾ����CSysInvalidateOrder
	virtual void commitRemove(CWriteableSysInvalidateOrder *pSysInvalidateOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysInvalidateOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInvalidateOrderIterator��һ������Ч������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInvalidateOrderIterator
{
public:
	///���췽��
	CSysInvalidateOrderIterator(void)
	{
	}

	///���췽��
	CSysInvalidateOrderIterator(CSysInvalidateOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysInvalidateOrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysInvalidateOrder
	///@return	��һ����������CSysInvalidateOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInvalidateOrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysInvalidateOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInvalidateOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInvalidateOrder * pSysInvalidateOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysInvalidateOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysOrderStatus��һ���洢����״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysOrderStatus
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! OrderLocalID.isValid())
			return 0;
		if (! InsertDate.isValid())
			return 0;
		if (! InsertTime.isValid())
			return 0;
		if (! OrderStatus.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! InstrumentID.isValid())
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
		if (! VolumeCondition.isValid())
			return 0;
		if (! MinVolume.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysOrderStatus *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///�������
	COrderSysIDType OrderSysID;
	///���ر������
	COrderLocalIDType OrderLocalID;
	///��������
	CDateType InsertDate;
	///����ʱ��
	CTimeType InsertTime;
	///����״̬
	COrderStatusType OrderStatus;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�����û�����
	CUserIDType UserID;
	///�ͻ�����
	CClientIDType ClientID;
	///��Լ����
	CInstrumentIDType InstrumentID;
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
	///�ɽ�������
	CVolumeConditionType VolumeCondition;
	///��С�ɽ���
	CVolumeType MinVolume;
	
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

typedef const CWriteableSysOrderStatus CSysOrderStatus;

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusActionTrigger�ǲ�������״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusActionTrigger
{
public:
	///���췽��
	CSysOrderStatusActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysOrderStatusActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysOrderStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysOrderStatus	Ҫ�����SysOrderStatus
	virtual void beforeAdd(CWriteableSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysOrderStatus	�Ѿ������SysOrderStatus
	virtual void afterAdd(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysOrderStatus	��ˢ�µ�CSysOrderStatus
	///@param	pNewSysOrderStatus	�µ�ֵ
	virtual void beforeUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pNewSysOrderStatus)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysOrderStatus	��ˢ�µ�CSysOrderStatus
	virtual void afterUpdate(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysOrderStatus	Ҫɾ����CSysOrderStatus
	virtual void beforeRemove(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysOrderStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusCommitTrigger��ȷ�ϱ���״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusCommitTrigger
{
public:
	///���췽��
	CSysOrderStatusCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysOrderStatusCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysOrderStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysOrderStatus	�Ѿ������SysOrderStatus
	virtual void commitAdd(CSysOrderStatus *pSysOrderStatus)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysOrderStatus	��ˢ�µ�CSysOrderStatus
	///@param	poldSysOrderStatus	ԭ����ֵ
	virtual void commitUpdate(CSysOrderStatus *pSysOrderStatus, CWriteableSysOrderStatus *pOldSysOrderStatus)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysOrderStatus	�Ѿ�ɾ����CSysOrderStatus
	virtual void commitRemove(CWriteableSysOrderStatus *pSysOrderStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysOrderStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOrderStatusIterator��һ���Ա���״̬��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOrderStatusIterator
{
public:
	///���췽��
	CSysOrderStatusIterator(void)
	{
	}

	///���췽��
	CSysOrderStatusIterator(CSysOrderStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysOrderStatusIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysOrderStatus
	///@return	��һ����������CSysOrderStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOrderStatus *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysOrderStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOrderStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOrderStatus * pSysOrderStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysOrderStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysBargainOrder��һ���洢�����ɽ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysBargainOrder
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! TradeID.isValid())
			return 0;
		if (! OrderSysID.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! Price.isValid())
			return 0;
		if (! Volume.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! UserID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysBargainOrder *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�ɽ�����
	CDateType ActionDate;
	///�ɽ�ʱ��
	CTimeType ActionTime;
	///�ɽ����
	CTradeIDType TradeID;
	///�������
	COrderSysIDType OrderSysID;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�۸�
	CPriceType Price;
	///����
	CVolumeType Volume;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�����û�����
	CUserIDType UserID;
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

typedef const CWriteableSysBargainOrder CSysBargainOrder;

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderActionTrigger�ǲ��������ɽ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderActionTrigger
{
public:
	///���췽��
	CSysBargainOrderActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysBargainOrderActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysBargainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysBargainOrder	Ҫ�����SysBargainOrder
	virtual void beforeAdd(CWriteableSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysBargainOrder	�Ѿ������SysBargainOrder
	virtual void afterAdd(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysBargainOrder	��ˢ�µ�CSysBargainOrder
	///@param	pNewSysBargainOrder	�µ�ֵ
	virtual void beforeUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pNewSysBargainOrder)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysBargainOrder	��ˢ�µ�CSysBargainOrder
	virtual void afterUpdate(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysBargainOrder	Ҫɾ����CSysBargainOrder
	virtual void beforeRemove(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysBargainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderCommitTrigger��ȷ�ϱ����ɽ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderCommitTrigger
{
public:
	///���췽��
	CSysBargainOrderCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysBargainOrderCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysBargainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysBargainOrder	�Ѿ������SysBargainOrder
	virtual void commitAdd(CSysBargainOrder *pSysBargainOrder)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysBargainOrder	��ˢ�µ�CSysBargainOrder
	///@param	poldSysBargainOrder	ԭ����ֵ
	virtual void commitUpdate(CSysBargainOrder *pSysBargainOrder, CWriteableSysBargainOrder *pOldSysBargainOrder)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysBargainOrder	�Ѿ�ɾ����CSysBargainOrder
	virtual void commitRemove(CWriteableSysBargainOrder *pSysBargainOrder)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysBargainOrderFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysBargainOrderIterator��һ���Ա����ɽ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysBargainOrderIterator
{
public:
	///���췽��
	CSysBargainOrderIterator(void)
	{
	}

	///���췽��
	CSysBargainOrderIterator(CSysBargainOrderFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysBargainOrderIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysBargainOrder
	///@return	��һ����������CSysBargainOrder������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysBargainOrder *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysBargainOrderFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysBargainOrder ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysBargainOrder * pSysBargainOrder,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysBargainOrderFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysInstProperty��һ���洢��Լ�������ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysInstProperty
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! SettlementGroupID.isValid())
			return 0;
		if (! UnderlyingInstrID.isValid())
			return 0;
		if (! ProductClass.isValid())
			return 0;
		if (! PositionType.isValid())
			return 0;
		if (! VolumeMultiple.isValid())
			return 0;
		if (! UnderlyingMultiple.isValid())
			return 0;
		if (! InstLifePhase.isValid())
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
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableSysInstProperty *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///���������
	CSettlementGroupIDType SettlementGroupID;
	///������Ʒ����
	CInstrumentIDType UnderlyingInstrID;
	///��Ʒ����
	CProductClassType ProductClass;
	///�ֲ�����
	CPositionTypeType PositionType;
	///��Լ��������
	CVolumeMultipleType VolumeMultiple;
	///��Լ������Ʒ����
	CUnderlyingMultipleType UnderlyingMultiple;
	///��Լ��������״̬
	CInstLifePhaseType InstLifePhase;
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

typedef const CWriteableSysInstProperty CSysInstProperty;

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyActionTrigger�ǲ�����Լ��������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyActionTrigger
{
public:
	///���췽��
	CSysInstPropertyActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysInstPropertyActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysInstPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysInstProperty	Ҫ�����SysInstProperty
	virtual void beforeAdd(CWriteableSysInstProperty *pSysInstProperty)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysInstProperty	�Ѿ������SysInstProperty
	virtual void afterAdd(CSysInstProperty *pSysInstProperty)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysInstProperty	��ˢ�µ�CSysInstProperty
	///@param	pNewSysInstProperty	�µ�ֵ
	virtual void beforeUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pNewSysInstProperty)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysInstProperty	��ˢ�µ�CSysInstProperty
	virtual void afterUpdate(CSysInstProperty *pSysInstProperty)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysInstProperty	Ҫɾ����CSysInstProperty
	virtual void beforeRemove(CSysInstProperty *pSysInstProperty)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysInstPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyCommitTrigger��ȷ�Ϻ�Լ��������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyCommitTrigger
{
public:
	///���췽��
	CSysInstPropertyCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysInstPropertyCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysInstPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysInstProperty	�Ѿ������SysInstProperty
	virtual void commitAdd(CSysInstProperty *pSysInstProperty)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysInstProperty	��ˢ�µ�CSysInstProperty
	///@param	poldSysInstProperty	ԭ����ֵ
	virtual void commitUpdate(CSysInstProperty *pSysInstProperty, CWriteableSysInstProperty *pOldSysInstProperty)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysInstProperty	�Ѿ�ɾ����CSysInstProperty
	virtual void commitRemove(CWriteableSysInstProperty *pSysInstProperty)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysInstPropertyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstPropertyIterator��һ���Ժ�Լ�������Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstPropertyIterator
{
public:
	///���췽��
	CSysInstPropertyIterator(void)
	{
	}

	///���췽��
	CSysInstPropertyIterator(CSysInstPropertyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysInstPropertyIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysInstProperty
	///@return	��һ����������CSysInstProperty������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstProperty *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysInstPropertyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstProperty ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstProperty * pSysInstProperty,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysInstPropertyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMarginRate��һ���洢��Լ��֤���ʵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMarginRate
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
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
		return 1;
	}

	///������д���ļ���,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp=NULL,int index=-1) const;
	
	///������д���ļ���ͻ����ʾ�仯������
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	///@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CWriteableSysMarginRate *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
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

typedef const CWriteableSysMarginRate CSysMarginRate;

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateActionTrigger�ǲ�����Լ��֤����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateActionTrigger
{
public:
	///���췽��
	CSysMarginRateActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMarginRateActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMarginRate	Ҫ�����SysMarginRate
	virtual void beforeAdd(CWriteableSysMarginRate *pSysMarginRate)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMarginRate	�Ѿ������SysMarginRate
	virtual void afterAdd(CSysMarginRate *pSysMarginRate)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMarginRate	��ˢ�µ�CSysMarginRate
	///@param	pNewSysMarginRate	�µ�ֵ
	virtual void beforeUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pNewSysMarginRate)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMarginRate	��ˢ�µ�CSysMarginRate
	virtual void afterUpdate(CSysMarginRate *pSysMarginRate)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMarginRate	Ҫɾ����CSysMarginRate
	virtual void beforeRemove(CSysMarginRate *pSysMarginRate)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateCommitTrigger��ȷ�Ϻ�Լ��֤����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateCommitTrigger
{
public:
	///���췽��
	CSysMarginRateCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMarginRateCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMarginRate	�Ѿ������SysMarginRate
	virtual void commitAdd(CSysMarginRate *pSysMarginRate)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMarginRate	��ˢ�µ�CSysMarginRate
	///@param	poldSysMarginRate	ԭ����ֵ
	virtual void commitUpdate(CSysMarginRate *pSysMarginRate, CWriteableSysMarginRate *pOldSysMarginRate)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMarginRate	�Ѿ�ɾ����CSysMarginRate
	virtual void commitRemove(CWriteableSysMarginRate *pSysMarginRate)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMarginRateFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateIterator��һ���Ժ�Լ��֤���ʵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateIterator
{
public:
	///���췽��
	CSysMarginRateIterator(void)
	{
	}

	///���췽��
	CSysMarginRateIterator(CSysMarginRateFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMarginRateIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMarginRate
	///@return	��һ����������CSysMarginRate������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRate *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMarginRateFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRate ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRate * pSysMarginRate,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMarginRateFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPriceLimit��һ���洢��Լ�ǵ�ͣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPriceLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! RoundingMode.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPriceLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///���뷽ʽ
	CRoundingModeType RoundingMode;
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

typedef const CWriteableSysPriceLimit CSysPriceLimit;

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitActionTrigger�ǲ�����Լ�ǵ�ͣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitActionTrigger
{
public:
	///���췽��
	CSysPriceLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPriceLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysPriceLimit	Ҫ�����SysPriceLimit
	virtual void beforeAdd(CWriteableSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysPriceLimit	�Ѿ������SysPriceLimit
	virtual void afterAdd(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysPriceLimit	��ˢ�µ�CSysPriceLimit
	///@param	pNewSysPriceLimit	�µ�ֵ
	virtual void beforeUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pNewSysPriceLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysPriceLimit	��ˢ�µ�CSysPriceLimit
	virtual void afterUpdate(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysPriceLimit	Ҫɾ����CSysPriceLimit
	virtual void beforeRemove(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitCommitTrigger��ȷ�Ϻ�Լ�ǵ�ͣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitCommitTrigger
{
public:
	///���췽��
	CSysPriceLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPriceLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysPriceLimit	�Ѿ������SysPriceLimit
	virtual void commitAdd(CSysPriceLimit *pSysPriceLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysPriceLimit	��ˢ�µ�CSysPriceLimit
	///@param	poldSysPriceLimit	ԭ����ֵ
	virtual void commitUpdate(CSysPriceLimit *pSysPriceLimit, CWriteableSysPriceLimit *pOldSysPriceLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysPriceLimit	�Ѿ�ɾ����CSysPriceLimit
	virtual void commitRemove(CWriteableSysPriceLimit *pSysPriceLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPriceLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPriceLimitIterator��һ���Ժ�Լ�ǵ�ͣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPriceLimitIterator
{
public:
	///���췽��
	CSysPriceLimitIterator(void)
	{
	}

	///���췽��
	CSysPriceLimitIterator(CSysPriceLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPriceLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysPriceLimit
	///@return	��һ����������CSysPriceLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPriceLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysPriceLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPriceLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPriceLimit * pSysPriceLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysPriceLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPartPosiLimit��һ���洢��Ա�޲ֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPartPosiLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPartPosiLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType TradingRole;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
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

typedef const CWriteableSysPartPosiLimit CSysPartPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitActionTrigger�ǲ�����Ա�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitActionTrigger
{
public:
	///���췽��
	CSysPartPosiLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPartPosiLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysPartPosiLimit	Ҫ�����SysPartPosiLimit
	virtual void beforeAdd(CWriteableSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysPartPosiLimit	�Ѿ������SysPartPosiLimit
	virtual void afterAdd(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysPartPosiLimit	��ˢ�µ�CSysPartPosiLimit
	///@param	pNewSysPartPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pNewSysPartPosiLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysPartPosiLimit	��ˢ�µ�CSysPartPosiLimit
	virtual void afterUpdate(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysPartPosiLimit	Ҫɾ����CSysPartPosiLimit
	virtual void beforeRemove(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitCommitTrigger��ȷ�ϻ�Ա�޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitCommitTrigger
{
public:
	///���췽��
	CSysPartPosiLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPartPosiLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysPartPosiLimit	�Ѿ������SysPartPosiLimit
	virtual void commitAdd(CSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysPartPosiLimit	��ˢ�µ�CSysPartPosiLimit
	///@param	poldSysPartPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CSysPartPosiLimit *pSysPartPosiLimit, CWriteableSysPartPosiLimit *pOldSysPartPosiLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysPartPosiLimit	�Ѿ�ɾ����CSysPartPosiLimit
	virtual void commitRemove(CWriteableSysPartPosiLimit *pSysPartPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPartPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartPosiLimitIterator��һ���Ի�Ա�޲ֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartPosiLimitIterator
{
public:
	///���췽��
	CSysPartPosiLimitIterator(void)
	{
	}

	///���췽��
	CSysPartPosiLimitIterator(CSysPartPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPartPosiLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysPartPosiLimit
	///@return	��һ����������CSysPartPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartPosiLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysPartPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartPosiLimit * pSysPartPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysPartPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientPosiLimit��һ���洢�ͻ��޲ֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientPosiLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientPosiLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientTypeType ClientType;
	///���׽�ɫ
	CPositionTradingRoleType TradingRole;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
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

typedef const CWriteableSysClientPosiLimit CSysClientPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitActionTrigger�ǲ����ͻ��޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitActionTrigger
{
public:
	///���췽��
	CSysClientPosiLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientPosiLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysClientPosiLimit	Ҫ�����SysClientPosiLimit
	virtual void beforeAdd(CWriteableSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysClientPosiLimit	�Ѿ������SysClientPosiLimit
	virtual void afterAdd(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysClientPosiLimit	��ˢ�µ�CSysClientPosiLimit
	///@param	pNewSysClientPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pNewSysClientPosiLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysClientPosiLimit	��ˢ�µ�CSysClientPosiLimit
	virtual void afterUpdate(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysClientPosiLimit	Ҫɾ����CSysClientPosiLimit
	virtual void beforeRemove(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitCommitTrigger��ȷ�Ͽͻ��޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitCommitTrigger
{
public:
	///���췽��
	CSysClientPosiLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientPosiLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysClientPosiLimit	�Ѿ������SysClientPosiLimit
	virtual void commitAdd(CSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysClientPosiLimit	��ˢ�µ�CSysClientPosiLimit
	///@param	poldSysClientPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CSysClientPosiLimit *pSysClientPosiLimit, CWriteableSysClientPosiLimit *pOldSysClientPosiLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysClientPosiLimit	�Ѿ�ɾ����CSysClientPosiLimit
	virtual void commitRemove(CWriteableSysClientPosiLimit *pSysClientPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitIterator��һ���Կͻ��޲ֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitIterator
{
public:
	///���췽��
	CSysClientPosiLimitIterator(void)
	{
	}

	///���췽��
	CSysClientPosiLimitIterator(CSysClientPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientPosiLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysClientPosiLimit
	///@return	��һ����������CSysClientPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysClientPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimit * pSysClientPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysClientPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysSpecialPosiLimit��һ���洢����ͻ��޲ֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysSpecialPosiLimit
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysSpecialPosiLimit *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientIDType ClientID;
	///���׽�ɫ
	CPositionTradingRoleType TradingRole;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
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

typedef const CWriteableSysSpecialPosiLimit CSysSpecialPosiLimit;

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitActionTrigger�ǲ�������ͻ��޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitActionTrigger
{
public:
	///���췽��
	CSysSpecialPosiLimitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysSpecialPosiLimitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysSpecialPosiLimit	Ҫ�����SysSpecialPosiLimit
	virtual void beforeAdd(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysSpecialPosiLimit	�Ѿ������SysSpecialPosiLimit
	virtual void afterAdd(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysSpecialPosiLimit	��ˢ�µ�CSysSpecialPosiLimit
	///@param	pNewSysSpecialPosiLimit	�µ�ֵ
	virtual void beforeUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pNewSysSpecialPosiLimit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysSpecialPosiLimit	��ˢ�µ�CSysSpecialPosiLimit
	virtual void afterUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysSpecialPosiLimit	Ҫɾ����CSysSpecialPosiLimit
	virtual void beforeRemove(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitCommitTrigger��ȷ������ͻ��޲�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitCommitTrigger
{
public:
	///���췽��
	CSysSpecialPosiLimitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysSpecialPosiLimitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysSpecialPosiLimit	�Ѿ������SysSpecialPosiLimit
	virtual void commitAdd(CSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysSpecialPosiLimit	��ˢ�µ�CSysSpecialPosiLimit
	///@param	poldSysSpecialPosiLimit	ԭ����ֵ
	virtual void commitUpdate(CSysSpecialPosiLimit *pSysSpecialPosiLimit, CWriteableSysSpecialPosiLimit *pOldSysSpecialPosiLimit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysSpecialPosiLimit	�Ѿ�ɾ����CSysSpecialPosiLimit
	virtual void commitRemove(CWriteableSysSpecialPosiLimit *pSysSpecialPosiLimit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysSpecialPosiLimitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecialPosiLimitIterator��һ��������ͻ��޲ֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecialPosiLimitIterator
{
public:
	///���췽��
	CSysSpecialPosiLimitIterator(void)
	{
	}

	///���췽��
	CSysSpecialPosiLimitIterator(CSysSpecialPosiLimitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysSpecialPosiLimitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysSpecialPosiLimit
	///@return	��һ����������CSysSpecialPosiLimit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecialPosiLimit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysSpecialPosiLimitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecialPosiLimit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecialPosiLimit * pSysSpecialPosiLimit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysSpecialPosiLimitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysTransactionChg��һ���洢�˻�������ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysTransactionChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! BillSN.isValid())
			return 0;
		if (! ParticipantAccount.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! Amount.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysTransactionChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///�ʻ�������ˮ��
	CSerialNoType BillSN;
	///�ʽ��˻�
	CAccountIDType ParticipantAccount;
	///��Ա����
	CParticipantIDType ParticipantID;
	///������
	CMoneyType Amount;
	
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

typedef const CWriteableSysTransactionChg CSysTransactionChg;

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgActionTrigger�ǲ����˻�������ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgActionTrigger
{
public:
	///���췽��
	CSysTransactionChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysTransactionChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysTransactionChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysTransactionChg	Ҫ�����SysTransactionChg
	virtual void beforeAdd(CWriteableSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysTransactionChg	�Ѿ������SysTransactionChg
	virtual void afterAdd(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysTransactionChg	��ˢ�µ�CSysTransactionChg
	///@param	pNewSysTransactionChg	�µ�ֵ
	virtual void beforeUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pNewSysTransactionChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysTransactionChg	��ˢ�µ�CSysTransactionChg
	virtual void afterUpdate(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysTransactionChg	Ҫɾ����CSysTransactionChg
	virtual void beforeRemove(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysTransactionChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgCommitTrigger��ȷ���˻�������ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgCommitTrigger
{
public:
	///���췽��
	CSysTransactionChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysTransactionChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysTransactionChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysTransactionChg	�Ѿ������SysTransactionChg
	virtual void commitAdd(CSysTransactionChg *pSysTransactionChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysTransactionChg	��ˢ�µ�CSysTransactionChg
	///@param	poldSysTransactionChg	ԭ����ֵ
	virtual void commitUpdate(CSysTransactionChg *pSysTransactionChg, CWriteableSysTransactionChg *pOldSysTransactionChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysTransactionChg	�Ѿ�ɾ����CSysTransactionChg
	virtual void commitRemove(CWriteableSysTransactionChg *pSysTransactionChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysTransactionChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTransactionChgIterator��һ�����˻�������ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTransactionChgIterator
{
public:
	///���췽��
	CSysTransactionChgIterator(void)
	{
	}

	///���췽��
	CSysTransactionChgIterator(CSysTransactionChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysTransactionChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysTransactionChg
	///@return	��һ����������CSysTransactionChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTransactionChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysTransactionChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTransactionChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTransactionChg * pSysTransactionChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysTransactionChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientChg��һ���洢�ͻ����ݱ䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! ClientName.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! IsActive.isValid())
			return 0;
		if (! IdentifiedCardType.isValid())
			return 0;
		if (! IdentifiedCardNo.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///�ͻ�����
	CClientIDType ClientID;
	///�ͻ�����
	CPartyNameType ClientName;
	///�ͻ�����
	CClientTypeType ClientType;
	///�Ƿ��Ծ
	CBoolType IsActive;
	///֤������
	CIdCardTypeType IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType IdentifiedCardNo;
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysClientChg CSysClientChg;

/////////////////////////////////////////////////////////////////////////
///CSysClientChgActionTrigger�ǲ����ͻ����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgActionTrigger
{
public:
	///���췽��
	CSysClientChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysClientChg	Ҫ�����SysClientChg
	virtual void beforeAdd(CWriteableSysClientChg *pSysClientChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysClientChg	�Ѿ������SysClientChg
	virtual void afterAdd(CSysClientChg *pSysClientChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysClientChg	��ˢ�µ�CSysClientChg
	///@param	pNewSysClientChg	�µ�ֵ
	virtual void beforeUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pNewSysClientChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysClientChg	��ˢ�µ�CSysClientChg
	virtual void afterUpdate(CSysClientChg *pSysClientChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysClientChg	Ҫɾ����CSysClientChg
	virtual void beforeRemove(CSysClientChg *pSysClientChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgCommitTrigger��ȷ�Ͽͻ����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgCommitTrigger
{
public:
	///���췽��
	CSysClientChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysClientChg	�Ѿ������SysClientChg
	virtual void commitAdd(CSysClientChg *pSysClientChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysClientChg	��ˢ�µ�CSysClientChg
	///@param	poldSysClientChg	ԭ����ֵ
	virtual void commitUpdate(CSysClientChg *pSysClientChg, CWriteableSysClientChg *pOldSysClientChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysClientChg	�Ѿ�ɾ����CSysClientChg
	virtual void commitRemove(CWriteableSysClientChg *pSysClientChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientChgIterator��һ���Կͻ����ݱ䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientChgIterator
{
public:
	///���췽��
	CSysClientChgIterator(void)
	{
	}

	///���췽��
	CSysClientChgIterator(CSysClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysClientChg
	///@return	��һ����������CSysClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysClientChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientChg * pSysClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysClientChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPartClientChg��һ���洢��Ա�ͻ����ձ䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPartClientChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPartClientChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///�ͻ�����
	CClientIDType ClientID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysPartClientChg CSysPartClientChg;

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgActionTrigger�ǲ�����Ա�ͻ����ձ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgActionTrigger
{
public:
	///���췽��
	CSysPartClientChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPartClientChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPartClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysPartClientChg	Ҫ�����SysPartClientChg
	virtual void beforeAdd(CWriteableSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysPartClientChg	�Ѿ������SysPartClientChg
	virtual void afterAdd(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysPartClientChg	��ˢ�µ�CSysPartClientChg
	///@param	pNewSysPartClientChg	�µ�ֵ
	virtual void beforeUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pNewSysPartClientChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysPartClientChg	��ˢ�µ�CSysPartClientChg
	virtual void afterUpdate(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysPartClientChg	Ҫɾ����CSysPartClientChg
	virtual void beforeRemove(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPartClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgCommitTrigger��ȷ�ϻ�Ա�ͻ����ձ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgCommitTrigger
{
public:
	///���췽��
	CSysPartClientChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPartClientChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPartClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysPartClientChg	�Ѿ������SysPartClientChg
	virtual void commitAdd(CSysPartClientChg *pSysPartClientChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysPartClientChg	��ˢ�µ�CSysPartClientChg
	///@param	poldSysPartClientChg	ԭ����ֵ
	virtual void commitUpdate(CSysPartClientChg *pSysPartClientChg, CWriteableSysPartClientChg *pOldSysPartClientChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysPartClientChg	�Ѿ�ɾ����CSysPartClientChg
	virtual void commitRemove(CWriteableSysPartClientChg *pSysPartClientChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPartClientChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartClientChgIterator��һ���Ի�Ա�ͻ����ձ䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartClientChgIterator
{
public:
	///���췽��
	CSysPartClientChgIterator(void)
	{
	}

	///���췽��
	CSysPartClientChgIterator(CSysPartClientChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPartClientChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysPartClientChg
	///@return	��һ����������CSysPartClientChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartClientChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysPartClientChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartClientChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartClientChg * pSysPartClientChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysPartClientChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPosiLimitChg��һ���洢�޲����ݱ䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPosiLimitChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPosiLimitChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType TradingRole;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysPosiLimitChg CSysPosiLimitChg;

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgActionTrigger�ǲ����޲����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgActionTrigger
{
public:
	///���췽��
	CSysPosiLimitChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPosiLimitChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysPosiLimitChg	Ҫ�����SysPosiLimitChg
	virtual void beforeAdd(CWriteableSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysPosiLimitChg	�Ѿ������SysPosiLimitChg
	virtual void afterAdd(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysPosiLimitChg	��ˢ�µ�CSysPosiLimitChg
	///@param	pNewSysPosiLimitChg	�µ�ֵ
	virtual void beforeUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pNewSysPosiLimitChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysPosiLimitChg	��ˢ�µ�CSysPosiLimitChg
	virtual void afterUpdate(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysPosiLimitChg	Ҫɾ����CSysPosiLimitChg
	virtual void beforeRemove(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgCommitTrigger��ȷ���޲����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgCommitTrigger
{
public:
	///���췽��
	CSysPosiLimitChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPosiLimitChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysPosiLimitChg	�Ѿ������SysPosiLimitChg
	virtual void commitAdd(CSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysPosiLimitChg	��ˢ�µ�CSysPosiLimitChg
	///@param	poldSysPosiLimitChg	ԭ����ֵ
	virtual void commitUpdate(CSysPosiLimitChg *pSysPosiLimitChg, CWriteableSysPosiLimitChg *pOldSysPosiLimitChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysPosiLimitChg	�Ѿ�ɾ����CSysPosiLimitChg
	virtual void commitRemove(CWriteableSysPosiLimitChg *pSysPosiLimitChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPosiLimitChgIterator��һ�����޲����ݱ䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPosiLimitChgIterator
{
public:
	///���췽��
	CSysPosiLimitChgIterator(void)
	{
	}

	///���췽��
	CSysPosiLimitChgIterator(CSysPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPosiLimitChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysPosiLimitChg
	///@return	��һ����������CSysPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPosiLimitChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysPosiLimitChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPosiLimitChg * pSysPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysPosiLimitChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientPosiLimitChg��һ���洢�޲����ݱ䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientPosiLimitChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientType.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientPosiLimitChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientTypeType ClientType;
	///���׽�ɫ
	CPositionTradingRoleType TradingRole;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysClientPosiLimitChg CSysClientPosiLimitChg;

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgActionTrigger�ǲ����޲����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgActionTrigger
{
public:
	///���췽��
	CSysClientPosiLimitChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientPosiLimitChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysClientPosiLimitChg	Ҫ�����SysClientPosiLimitChg
	virtual void beforeAdd(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysClientPosiLimitChg	�Ѿ������SysClientPosiLimitChg
	virtual void afterAdd(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysClientPosiLimitChg	��ˢ�µ�CSysClientPosiLimitChg
	///@param	pNewSysClientPosiLimitChg	�µ�ֵ
	virtual void beforeUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pNewSysClientPosiLimitChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysClientPosiLimitChg	��ˢ�µ�CSysClientPosiLimitChg
	virtual void afterUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysClientPosiLimitChg	Ҫɾ����CSysClientPosiLimitChg
	virtual void beforeRemove(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgCommitTrigger��ȷ���޲����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgCommitTrigger
{
public:
	///���췽��
	CSysClientPosiLimitChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientPosiLimitChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysClientPosiLimitChg	�Ѿ������SysClientPosiLimitChg
	virtual void commitAdd(CSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysClientPosiLimitChg	��ˢ�µ�CSysClientPosiLimitChg
	///@param	poldSysClientPosiLimitChg	ԭ����ֵ
	virtual void commitUpdate(CSysClientPosiLimitChg *pSysClientPosiLimitChg, CWriteableSysClientPosiLimitChg *pOldSysClientPosiLimitChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysClientPosiLimitChg	�Ѿ�ɾ����CSysClientPosiLimitChg
	virtual void commitRemove(CWriteableSysClientPosiLimitChg *pSysClientPosiLimitChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientPosiLimitChgIterator��һ�����޲����ݱ䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientPosiLimitChgIterator
{
public:
	///���췽��
	CSysClientPosiLimitChgIterator(void)
	{
	}

	///���췽��
	CSysClientPosiLimitChgIterator(CSysClientPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientPosiLimitChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysClientPosiLimitChg
	///@return	��һ����������CSysClientPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientPosiLimitChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysClientPosiLimitChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientPosiLimitChg * pSysClientPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysClientPosiLimitChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysSpecPosiLimitChg��һ���洢�޲����ݱ䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysSpecPosiLimitChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ClientID.isValid())
			return 0;
		if (! TradingRole.isValid())
			return 0;
		if (! StartTotalPosition.isValid())
			return 0;
		if (! ValueMode.isValid())
			return 0;
		if (! LongPosLimit.isValid())
			return 0;
		if (! ShortPosLimit.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysSpecPosiLimitChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///�ͻ�����
	CClientIDType ClientID;
	///���׽�ɫ
	CPositionTradingRoleType TradingRole;
	///�޲����
	CLargeVolumeType StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType ValueMode;
	///��ͷ�޲�
	CRatioType LongPosLimit;
	///��ͷ�޲�
	CRatioType ShortPosLimit;
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysSpecPosiLimitChg CSysSpecPosiLimitChg;

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgActionTrigger�ǲ����޲����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgActionTrigger
{
public:
	///���췽��
	CSysSpecPosiLimitChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysSpecPosiLimitChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysSpecPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysSpecPosiLimitChg	Ҫ�����SysSpecPosiLimitChg
	virtual void beforeAdd(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysSpecPosiLimitChg	�Ѿ������SysSpecPosiLimitChg
	virtual void afterAdd(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysSpecPosiLimitChg	��ˢ�µ�CSysSpecPosiLimitChg
	///@param	pNewSysSpecPosiLimitChg	�µ�ֵ
	virtual void beforeUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pNewSysSpecPosiLimitChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysSpecPosiLimitChg	��ˢ�µ�CSysSpecPosiLimitChg
	virtual void afterUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysSpecPosiLimitChg	Ҫɾ����CSysSpecPosiLimitChg
	virtual void beforeRemove(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysSpecPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgCommitTrigger��ȷ���޲����ݱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgCommitTrigger
{
public:
	///���췽��
	CSysSpecPosiLimitChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysSpecPosiLimitChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysSpecPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysSpecPosiLimitChg	�Ѿ������SysSpecPosiLimitChg
	virtual void commitAdd(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysSpecPosiLimitChg	��ˢ�µ�CSysSpecPosiLimitChg
	///@param	poldSysSpecPosiLimitChg	ԭ����ֵ
	virtual void commitUpdate(CSysSpecPosiLimitChg *pSysSpecPosiLimitChg, CWriteableSysSpecPosiLimitChg *pOldSysSpecPosiLimitChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysSpecPosiLimitChg	�Ѿ�ɾ����CSysSpecPosiLimitChg
	virtual void commitRemove(CWriteableSysSpecPosiLimitChg *pSysSpecPosiLimitChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysSpecPosiLimitChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysSpecPosiLimitChgIterator��һ�����޲����ݱ䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysSpecPosiLimitChgIterator
{
public:
	///���췽��
	CSysSpecPosiLimitChgIterator(void)
	{
	}

	///���췽��
	CSysSpecPosiLimitChgIterator(CSysSpecPosiLimitChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysSpecPosiLimitChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysSpecPosiLimitChg
	///@return	��һ����������CSysSpecPosiLimitChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysSpecPosiLimitChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysSpecPosiLimitChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysSpecPosiLimitChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysSpecPosiLimitChg * pSysSpecPosiLimitChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysSpecPosiLimitChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysHedgeDetailChg��һ���洢��ֵ��ȱ䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysHedgeDetailChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ClientID.isValid())
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysHedgeDetailChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ͻ�����
	CClientIDType ClientID;
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
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysHedgeDetailChg CSysHedgeDetailChg;

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgActionTrigger�ǲ�����ֵ��ȱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgActionTrigger
{
public:
	///���췽��
	CSysHedgeDetailChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysHedgeDetailChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysHedgeDetailChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysHedgeDetailChg	Ҫ�����SysHedgeDetailChg
	virtual void beforeAdd(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysHedgeDetailChg	�Ѿ������SysHedgeDetailChg
	virtual void afterAdd(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysHedgeDetailChg	��ˢ�µ�CSysHedgeDetailChg
	///@param	pNewSysHedgeDetailChg	�µ�ֵ
	virtual void beforeUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pNewSysHedgeDetailChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysHedgeDetailChg	��ˢ�µ�CSysHedgeDetailChg
	virtual void afterUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysHedgeDetailChg	Ҫɾ����CSysHedgeDetailChg
	virtual void beforeRemove(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysHedgeDetailChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgCommitTrigger��ȷ�ϱ�ֵ��ȱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgCommitTrigger
{
public:
	///���췽��
	CSysHedgeDetailChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysHedgeDetailChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysHedgeDetailChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysHedgeDetailChg	�Ѿ������SysHedgeDetailChg
	virtual void commitAdd(CSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysHedgeDetailChg	��ˢ�µ�CSysHedgeDetailChg
	///@param	poldSysHedgeDetailChg	ԭ����ֵ
	virtual void commitUpdate(CSysHedgeDetailChg *pSysHedgeDetailChg, CWriteableSysHedgeDetailChg *pOldSysHedgeDetailChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysHedgeDetailChg	�Ѿ�ɾ����CSysHedgeDetailChg
	virtual void commitRemove(CWriteableSysHedgeDetailChg *pSysHedgeDetailChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysHedgeDetailChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysHedgeDetailChgIterator��һ���Ա�ֵ��ȱ䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysHedgeDetailChgIterator
{
public:
	///���췽��
	CSysHedgeDetailChgIterator(void)
	{
	}

	///���췽��
	CSysHedgeDetailChgIterator(CSysHedgeDetailChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysHedgeDetailChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysHedgeDetailChg
	///@return	��һ����������CSysHedgeDetailChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysHedgeDetailChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysHedgeDetailChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysHedgeDetailChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysHedgeDetailChg * pSysHedgeDetailChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysHedgeDetailChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysParticipantChg��һ���洢��Ա�䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysParticipantChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysParticipantChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
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
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysParticipantChg CSysParticipantChg;

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgActionTrigger�ǲ�����Ա�䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgActionTrigger
{
public:
	///���췽��
	CSysParticipantChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysParticipantChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysParticipantChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysParticipantChg	Ҫ�����SysParticipantChg
	virtual void beforeAdd(CWriteableSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysParticipantChg	�Ѿ������SysParticipantChg
	virtual void afterAdd(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysParticipantChg	��ˢ�µ�CSysParticipantChg
	///@param	pNewSysParticipantChg	�µ�ֵ
	virtual void beforeUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pNewSysParticipantChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysParticipantChg	��ˢ�µ�CSysParticipantChg
	virtual void afterUpdate(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysParticipantChg	Ҫɾ����CSysParticipantChg
	virtual void beforeRemove(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysParticipantChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgCommitTrigger��ȷ�ϻ�Ա�䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgCommitTrigger
{
public:
	///���췽��
	CSysParticipantChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysParticipantChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysParticipantChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysParticipantChg	�Ѿ������SysParticipantChg
	virtual void commitAdd(CSysParticipantChg *pSysParticipantChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysParticipantChg	��ˢ�µ�CSysParticipantChg
	///@param	poldSysParticipantChg	ԭ����ֵ
	virtual void commitUpdate(CSysParticipantChg *pSysParticipantChg, CWriteableSysParticipantChg *pOldSysParticipantChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysParticipantChg	�Ѿ�ɾ����CSysParticipantChg
	virtual void commitRemove(CWriteableSysParticipantChg *pSysParticipantChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysParticipantChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantChgIterator��һ���Ի�Ա�䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantChgIterator
{
public:
	///���췽��
	CSysParticipantChgIterator(void)
	{
	}

	///���췽��
	CSysParticipantChgIterator(CSysParticipantChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysParticipantChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysParticipantChg
	///@return	��һ����������CSysParticipantChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysParticipantChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantChg * pSysParticipantChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysParticipantChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMarginRateChg��һ���洢��֤���ʱ䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMarginRateChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMarginRateChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
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
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysMarginRateChg CSysMarginRateChg;

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgActionTrigger�ǲ�����֤���ʱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgActionTrigger
{
public:
	///���췽��
	CSysMarginRateChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMarginRateChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMarginRateChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMarginRateChg	Ҫ�����SysMarginRateChg
	virtual void beforeAdd(CWriteableSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMarginRateChg	�Ѿ������SysMarginRateChg
	virtual void afterAdd(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMarginRateChg	��ˢ�µ�CSysMarginRateChg
	///@param	pNewSysMarginRateChg	�µ�ֵ
	virtual void beforeUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pNewSysMarginRateChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMarginRateChg	��ˢ�µ�CSysMarginRateChg
	virtual void afterUpdate(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMarginRateChg	Ҫɾ����CSysMarginRateChg
	virtual void beforeRemove(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMarginRateChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgCommitTrigger��ȷ�ϱ�֤���ʱ䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgCommitTrigger
{
public:
	///���췽��
	CSysMarginRateChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMarginRateChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMarginRateChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMarginRateChg	�Ѿ������SysMarginRateChg
	virtual void commitAdd(CSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMarginRateChg	��ˢ�µ�CSysMarginRateChg
	///@param	poldSysMarginRateChg	ԭ����ֵ
	virtual void commitUpdate(CSysMarginRateChg *pSysMarginRateChg, CWriteableSysMarginRateChg *pOldSysMarginRateChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMarginRateChg	�Ѿ�ɾ����CSysMarginRateChg
	virtual void commitRemove(CWriteableSysMarginRateChg *pSysMarginRateChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMarginRateChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMarginRateChgIterator��һ���Ա�֤���ʱ䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMarginRateChgIterator
{
public:
	///���췽��
	CSysMarginRateChgIterator(void)
	{
	}

	///���췽��
	CSysMarginRateChgIterator(CSysMarginRateChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMarginRateChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMarginRateChg
	///@return	��һ����������CSysMarginRateChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMarginRateChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMarginRateChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMarginRateChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMarginRateChg * pSysMarginRateChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMarginRateChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysUserIpChg��һ���洢IP��ַ�䶯��ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysUserIpChg
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! IPMask.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysUserIpChg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///�����û�����
	CUserIDType UserID;
	///IP��ַ
	CIPAddressType IPAddress;
	///IP��ַ����
	CIPAddressType IPMask;
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysUserIpChg CSysUserIpChg;

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgActionTrigger�ǲ���IP��ַ�䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgActionTrigger
{
public:
	///���췽��
	CSysUserIpChgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysUserIpChgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysUserIpChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysUserIpChg	Ҫ�����SysUserIpChg
	virtual void beforeAdd(CWriteableSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysUserIpChg	�Ѿ������SysUserIpChg
	virtual void afterAdd(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysUserIpChg	��ˢ�µ�CSysUserIpChg
	///@param	pNewSysUserIpChg	�µ�ֵ
	virtual void beforeUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pNewSysUserIpChg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysUserIpChg	��ˢ�µ�CSysUserIpChg
	virtual void afterUpdate(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysUserIpChg	Ҫɾ����CSysUserIpChg
	virtual void beforeRemove(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysUserIpChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgCommitTrigger��ȷ��IP��ַ�䶯��ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgCommitTrigger
{
public:
	///���췽��
	CSysUserIpChgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysUserIpChgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysUserIpChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysUserIpChg	�Ѿ������SysUserIpChg
	virtual void commitAdd(CSysUserIpChg *pSysUserIpChg)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysUserIpChg	��ˢ�µ�CSysUserIpChg
	///@param	poldSysUserIpChg	ԭ����ֵ
	virtual void commitUpdate(CSysUserIpChg *pSysUserIpChg, CWriteableSysUserIpChg *pOldSysUserIpChg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysUserIpChg	�Ѿ�ɾ����CSysUserIpChg
	virtual void commitRemove(CWriteableSysUserIpChg *pSysUserIpChg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysUserIpChgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserIpChgIterator��һ����IP��ַ�䶯��ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserIpChgIterator
{
public:
	///���췽��
	CSysUserIpChgIterator(void)
	{
	}

	///���췽��
	CSysUserIpChgIterator(CSysUserIpChgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserIpChgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysUserIpChg
	///@return	��һ����������CSysUserIpChg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserIpChg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysUserIpChgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserIpChg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserIpChg * pSysUserIpChg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysUserIpChgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysPartTrade��һ���洢��Ա������Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysPartTrade
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
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! InstrumentID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! TotalPositiveOrder.isValid())
			return 0;
		if (! TotalNegativeOrder.isValid())
			return 0;
		if (! TotalPositiveTrade.isValid())
			return 0;
		if (! TotalNegativeTrade.isValid())
			return 0;
		if (! TotalPositivePosi.isValid())
			return 0;
		if (! TotalNegativePosi.isValid())
			return 0;
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysPartTrade *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CDateType ActionDate;
	///����ʱ��
	CTimeType ActionTime;
	///��Լ����
	CInstrumentIDType InstrumentID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///�ܱ�����
	CVolumeType TotalPositiveOrder;
	///�ܱ�������
	CVolumeType TotalNegativeOrder;
	///���ܳɽ���
	CVolumeType TotalPositiveTrade;
	///�����ܳɽ���
	CVolumeType TotalNegativeTrade;
	///�ܶ�ͷ�ֲ���
	CVolumeType TotalPositivePosi;
	///�ܿ�ͷ�ֲ���
	CVolumeType TotalNegativePosi;
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysPartTrade CSysPartTrade;

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeActionTrigger�ǲ�����Ա������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeActionTrigger
{
public:
	///���췽��
	CSysPartTradeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPartTradeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPartTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysPartTrade	Ҫ�����SysPartTrade
	virtual void beforeAdd(CWriteableSysPartTrade *pSysPartTrade)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysPartTrade	�Ѿ������SysPartTrade
	virtual void afterAdd(CSysPartTrade *pSysPartTrade)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysPartTrade	��ˢ�µ�CSysPartTrade
	///@param	pNewSysPartTrade	�µ�ֵ
	virtual void beforeUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pNewSysPartTrade)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysPartTrade	��ˢ�µ�CSysPartTrade
	virtual void afterUpdate(CSysPartTrade *pSysPartTrade)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysPartTrade	Ҫɾ����CSysPartTrade
	virtual void beforeRemove(CSysPartTrade *pSysPartTrade)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPartTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeCommitTrigger��ȷ�ϻ�Ա������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeCommitTrigger
{
public:
	///���췽��
	CSysPartTradeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysPartTradeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysPartTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysPartTrade	�Ѿ������SysPartTrade
	virtual void commitAdd(CSysPartTrade *pSysPartTrade)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysPartTrade	��ˢ�µ�CSysPartTrade
	///@param	poldSysPartTrade	ԭ����ֵ
	virtual void commitUpdate(CSysPartTrade *pSysPartTrade, CWriteableSysPartTrade *pOldSysPartTrade)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysPartTrade	�Ѿ�ɾ����CSysPartTrade
	virtual void commitRemove(CWriteableSysPartTrade *pSysPartTrade)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysPartTradeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysPartTradeIterator��һ���Ի�Ա������Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysPartTradeIterator
{
public:
	///���췽��
	CSysPartTradeIterator(void)
	{
	}

	///���췽��
	CSysPartTradeIterator(CSysPartTradeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysPartTradeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysPartTrade
	///@return	��һ����������CSysPartTrade������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysPartTrade *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysPartTradeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysPartTrade ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysPartTrade * pSysPartTrade,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysPartTradeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbObjectAttr��һ���洢����״ָ̬��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbObjectAttr
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
		if (! SubcriberID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ValueType.isValid())
			return 0;
		if (! AttrValue.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbObjectAttr *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///�������ID
	CVolumeType ObjectID;
	///���ָ������ID
	CVolumeType AttrType;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///���ָ���ֵ����
	CValueTypeType ValueType;
	///���ָ��ľ���ֵ
	CAttrValueType AttrValue;
	
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

typedef const CWriteableSysMdbObjectAttr CSysMdbObjectAttr;

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrActionTrigger�ǲ�������״ָ̬��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrActionTrigger
{
public:
	///���췽��
	CSysMdbObjectAttrActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbObjectAttrActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbObjectAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbObjectAttr	Ҫ�����SysMdbObjectAttr
	virtual void beforeAdd(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbObjectAttr	�Ѿ������SysMdbObjectAttr
	virtual void afterAdd(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbObjectAttr	��ˢ�µ�CSysMdbObjectAttr
	///@param	pNewSysMdbObjectAttr	�µ�ֵ
	virtual void beforeUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pNewSysMdbObjectAttr)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbObjectAttr	��ˢ�µ�CSysMdbObjectAttr
	virtual void afterUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbObjectAttr	Ҫɾ����CSysMdbObjectAttr
	virtual void beforeRemove(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbObjectAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrCommitTrigger��ȷ�϶���״ָ̬��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrCommitTrigger
{
public:
	///���췽��
	CSysMdbObjectAttrCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbObjectAttrCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbObjectAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbObjectAttr	�Ѿ������SysMdbObjectAttr
	virtual void commitAdd(CSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbObjectAttr	��ˢ�µ�CSysMdbObjectAttr
	///@param	poldSysMdbObjectAttr	ԭ����ֵ
	virtual void commitUpdate(CSysMdbObjectAttr *pSysMdbObjectAttr, CWriteableSysMdbObjectAttr *pOldSysMdbObjectAttr)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbObjectAttr	�Ѿ�ɾ����CSysMdbObjectAttr
	virtual void commitRemove(CWriteableSysMdbObjectAttr *pSysMdbObjectAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbObjectAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbObjectAttrIterator��һ���Զ���״ָ̬���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbObjectAttrIterator
{
public:
	///���췽��
	CSysMdbObjectAttrIterator(void)
	{
	}

	///���췽��
	CSysMdbObjectAttrIterator(CSysMdbObjectAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbObjectAttrIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbObjectAttr
	///@return	��һ����������CSysMdbObjectAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbObjectAttr *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbObjectAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbObjectAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbObjectAttr * pSysMdbObjectAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbObjectAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbSyslogInfo��һ���洢��־�ļ����ݴ�����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbSyslogInfo
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! ContLen.isValid())
			return 0;
		if (! FileContent.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbSyslogInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�������ID
	CVolumeType ObjectID;
	///���ָ������ID
	CVolumeType AttrType;
	///�ļ����ݳ���
	CTypeContLenType ContLen;
	///�ļ�����
	CTypeFileContentType FileContent;
	
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

typedef const CWriteableSysMdbSyslogInfo CSysMdbSyslogInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoActionTrigger�ǲ�����־�ļ����ݴ�����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoActionTrigger
{
public:
	///���췽��
	CSysMdbSyslogInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbSyslogInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbSyslogInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbSyslogInfo	Ҫ�����SysMdbSyslogInfo
	virtual void beforeAdd(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbSyslogInfo	�Ѿ������SysMdbSyslogInfo
	virtual void afterAdd(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbSyslogInfo	��ˢ�µ�CSysMdbSyslogInfo
	///@param	pNewSysMdbSyslogInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pNewSysMdbSyslogInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbSyslogInfo	��ˢ�µ�CSysMdbSyslogInfo
	virtual void afterUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbSyslogInfo	Ҫɾ����CSysMdbSyslogInfo
	virtual void beforeRemove(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbSyslogInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoCommitTrigger��ȷ����־�ļ����ݴ�����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbSyslogInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbSyslogInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbSyslogInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbSyslogInfo	�Ѿ������SysMdbSyslogInfo
	virtual void commitAdd(CSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbSyslogInfo	��ˢ�µ�CSysMdbSyslogInfo
	///@param	poldSysMdbSyslogInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbSyslogInfo *pSysMdbSyslogInfo, CWriteableSysMdbSyslogInfo *pOldSysMdbSyslogInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbSyslogInfo	�Ѿ�ɾ����CSysMdbSyslogInfo
	virtual void commitRemove(CWriteableSysMdbSyslogInfo *pSysMdbSyslogInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbSyslogInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbSyslogInfoIterator��һ������־�ļ����ݴ�����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbSyslogInfoIterator
{
public:
	///���췽��
	CSysMdbSyslogInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbSyslogInfoIterator(CSysMdbSyslogInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbSyslogInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbSyslogInfo
	///@return	��һ����������CSysMdbSyslogInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbSyslogInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbSyslogInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbSyslogInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbSyslogInfo * pSysMdbSyslogInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbSyslogInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysUserInfo��һ���洢�û���Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysUserInfo
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
		if (! USERNAME.isValid())
			return 0;
		if (! USERID.isValid())
			return 0;
		if (! GROUPNAME.isValid())
			return 0;
		if (! GROUPID.isValid())
			return 0;
		if (! HOMEPATH.isValid())
			return 0;
		if (! SHELL.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! MonDate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysUserInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�û���
	CTypeUserNameType USERNAME;
	///�û�ID
	CVolumeType USERID;
	///�û�����
	CTypeUserNameType GROUPNAME;
	///�û���ID
	CVolumeType GROUPID;
	///HOME·��
	CTypeUserNameType HOMEPATH;
	///�û�ʹ��SHELL����
	CTypeUserNameType SHELL;
	///���������
	CTypeObjectIDType ObjectID;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�ɼ�������
	CDateType MonDate;
	
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

typedef const CWriteableSysUserInfo CSysUserInfo;

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoActionTrigger�ǲ����û���Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoActionTrigger
{
public:
	///���췽��
	CSysUserInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysUserInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysUserInfo	Ҫ�����SysUserInfo
	virtual void beforeAdd(CWriteableSysUserInfo *pSysUserInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysUserInfo	�Ѿ������SysUserInfo
	virtual void afterAdd(CSysUserInfo *pSysUserInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysUserInfo	��ˢ�µ�CSysUserInfo
	///@param	pNewSysUserInfo	�µ�ֵ
	virtual void beforeUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pNewSysUserInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysUserInfo	��ˢ�µ�CSysUserInfo
	virtual void afterUpdate(CSysUserInfo *pSysUserInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysUserInfo	Ҫɾ����CSysUserInfo
	virtual void beforeRemove(CSysUserInfo *pSysUserInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoCommitTrigger��ȷ���û���Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoCommitTrigger
{
public:
	///���췽��
	CSysUserInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysUserInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysUserInfo	�Ѿ������SysUserInfo
	virtual void commitAdd(CSysUserInfo *pSysUserInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysUserInfo	��ˢ�µ�CSysUserInfo
	///@param	poldSysUserInfo	ԭ����ֵ
	virtual void commitUpdate(CSysUserInfo *pSysUserInfo, CWriteableSysUserInfo *pOldSysUserInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysUserInfo	�Ѿ�ɾ����CSysUserInfo
	virtual void commitRemove(CWriteableSysUserInfo *pSysUserInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInfoIterator��һ�����û���Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInfoIterator
{
public:
	///���췽��
	CSysUserInfoIterator(void)
	{
	}

	///���췽��
	CSysUserInfoIterator(CSysUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysUserInfo
	///@return	��һ����������CSysUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysUserInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInfo * pSysUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysUserInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysOnlineUserInfo��һ���洢�����û���Ϣ��ѯӦ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysOnlineUserInfo
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
		if (! USERNAME.isValid())
			return 0;
		if (! TIME.isValid())
			return 0;
		if (! TTY.isValid())
			return 0;
		if (! IP.isValid())
			return 0;
		if (! CONNECTIME.isValid())
			return 0;
		if (! PID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! MonDate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysOnlineUserInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�û���
	CTypeUserNameType USERNAME;
	///��¼ʱ��
	CTypeUserNameType TIME;
	///�ն�����
	CTypeUserNameType TTY;
	///IP��ַ
	CTypeUserNameType IP;
	///����ʱ��
	CTypeUserNameType CONNECTIME;
	///����ID
	CVolumeType PID;
	///���������
	CTypeObjectIDType ObjectID;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�ɼ�������
	CDateType MonDate;
	
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

typedef const CWriteableSysOnlineUserInfo CSysOnlineUserInfo;

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoActionTrigger�ǲ��������û���Ϣ��ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoActionTrigger
{
public:
	///���췽��
	CSysOnlineUserInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysOnlineUserInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysOnlineUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysOnlineUserInfo	Ҫ�����SysOnlineUserInfo
	virtual void beforeAdd(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysOnlineUserInfo	�Ѿ������SysOnlineUserInfo
	virtual void afterAdd(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysOnlineUserInfo	��ˢ�µ�CSysOnlineUserInfo
	///@param	pNewSysOnlineUserInfo	�µ�ֵ
	virtual void beforeUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pNewSysOnlineUserInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysOnlineUserInfo	��ˢ�µ�CSysOnlineUserInfo
	virtual void afterUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysOnlineUserInfo	Ҫɾ����CSysOnlineUserInfo
	virtual void beforeRemove(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysOnlineUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoCommitTrigger��ȷ�������û���Ϣ��ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoCommitTrigger
{
public:
	///���췽��
	CSysOnlineUserInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysOnlineUserInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysOnlineUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysOnlineUserInfo	�Ѿ������SysOnlineUserInfo
	virtual void commitAdd(CSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysOnlineUserInfo	��ˢ�µ�CSysOnlineUserInfo
	///@param	poldSysOnlineUserInfo	ԭ����ֵ
	virtual void commitUpdate(CSysOnlineUserInfo *pSysOnlineUserInfo, CWriteableSysOnlineUserInfo *pOldSysOnlineUserInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysOnlineUserInfo	�Ѿ�ɾ����CSysOnlineUserInfo
	virtual void commitRemove(CWriteableSysOnlineUserInfo *pSysOnlineUserInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysOnlineUserInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysOnlineUserInfoIterator��һ���������û���Ϣ��ѯӦ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysOnlineUserInfoIterator
{
public:
	///���췽��
	CSysOnlineUserInfoIterator(void)
	{
	}

	///���췽��
	CSysOnlineUserInfoIterator(CSysOnlineUserInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysOnlineUserInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysOnlineUserInfo
	///@return	��һ����������CSysOnlineUserInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysOnlineUserInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysOnlineUserInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysOnlineUserInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysOnlineUserInfo * pSysOnlineUserInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysOnlineUserInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysWarningEvent��һ���洢�澯�¼���ѯӦ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysWarningEvent
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! OccurDate.isValid())
			return 0;
		if (! OccurTime.isValid())
			return 0;
		if (! EvendID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! EventName.isValid())
			return 0;
		if (! EventNum.isValid())
			return 0;
		if (! EventType.isValid())
			return 0;
		if (! EventDes.isValid())
			return 0;
		if (! ProcessFlag.isValid())
			return 0;
		if (! WarningLevel.isValid())
			return 0;
		if (! EventDealDes.isValid())
			return 0;
		if (! FullEventName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysWarningEvent *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�¼���������
	CDateType OccurDate;
	///�¼�����ʱ��
	CTimeType OccurTime;
	///�¼�ID
	CVolumeType EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType ObjectID;
	///IP��ַ
	CIPAddressType IPAddress;
	///�¼���
	CTypeObjectIDType EventName;
	///�¼���ǩ
	CVolumeType EventNum;
	///�¼�����
	CVolumeType EventType;
	///�¼�����
	CTypeDescriptionType EventDes;
	///������
	CTypeProcessFlagType ProcessFlag;
	///���漶��
	CTypeWarningLevelType WarningLevel;
	///�¼���������
	CTypeObjectIDType EventDealDes;
	///�¼�ȫ��
	CNetAttrTypeType FullEventName;
	
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

typedef const CWriteableSysWarningEvent CSysWarningEvent;

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventActionTrigger�ǲ����澯�¼���ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventActionTrigger
{
public:
	///���췽��
	CSysWarningEventActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysWarningEventActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysWarningEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysWarningEvent	Ҫ�����SysWarningEvent
	virtual void beforeAdd(CWriteableSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysWarningEvent	�Ѿ������SysWarningEvent
	virtual void afterAdd(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysWarningEvent	��ˢ�µ�CSysWarningEvent
	///@param	pNewSysWarningEvent	�µ�ֵ
	virtual void beforeUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pNewSysWarningEvent)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysWarningEvent	��ˢ�µ�CSysWarningEvent
	virtual void afterUpdate(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysWarningEvent	Ҫɾ����CSysWarningEvent
	virtual void beforeRemove(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysWarningEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventCommitTrigger��ȷ�ϸ澯�¼���ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventCommitTrigger
{
public:
	///���췽��
	CSysWarningEventCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysWarningEventCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysWarningEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysWarningEvent	�Ѿ������SysWarningEvent
	virtual void commitAdd(CSysWarningEvent *pSysWarningEvent)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysWarningEvent	��ˢ�µ�CSysWarningEvent
	///@param	poldSysWarningEvent	ԭ����ֵ
	virtual void commitUpdate(CSysWarningEvent *pSysWarningEvent, CWriteableSysWarningEvent *pOldSysWarningEvent)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysWarningEvent	�Ѿ�ɾ����CSysWarningEvent
	virtual void commitRemove(CWriteableSysWarningEvent *pSysWarningEvent)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysWarningEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningEventIterator��һ���Ը澯�¼���ѯӦ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningEventIterator
{
public:
	///���췽��
	CSysWarningEventIterator(void)
	{
	}

	///���췽��
	CSysWarningEventIterator(CSysWarningEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysWarningEventIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysWarningEvent
	///@return	��һ����������CSysWarningEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningEvent *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysWarningEventFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningEvent * pSysWarningEvent,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysWarningEventFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysWarningQuery��һ���洢�澯��ϸӦ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysWarningQuery
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! EvendID.isValid())
			return 0;
		if (! DBQueryResult.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysWarningQuery *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�¼�ID
	CVolumeType EvendID;
	///���ݿ��ѯ���
	CDBQueryResultType DBQueryResult;
	
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

typedef const CWriteableSysWarningQuery CSysWarningQuery;

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryActionTrigger�ǲ����澯��ϸӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryActionTrigger
{
public:
	///���췽��
	CSysWarningQueryActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysWarningQueryActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysWarningQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysWarningQuery	Ҫ�����SysWarningQuery
	virtual void beforeAdd(CWriteableSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysWarningQuery	�Ѿ������SysWarningQuery
	virtual void afterAdd(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysWarningQuery	��ˢ�µ�CSysWarningQuery
	///@param	pNewSysWarningQuery	�µ�ֵ
	virtual void beforeUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pNewSysWarningQuery)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysWarningQuery	��ˢ�µ�CSysWarningQuery
	virtual void afterUpdate(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysWarningQuery	Ҫɾ����CSysWarningQuery
	virtual void beforeRemove(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysWarningQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryCommitTrigger��ȷ�ϸ澯��ϸӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryCommitTrigger
{
public:
	///���췽��
	CSysWarningQueryCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysWarningQueryCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysWarningQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysWarningQuery	�Ѿ������SysWarningQuery
	virtual void commitAdd(CSysWarningQuery *pSysWarningQuery)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysWarningQuery	��ˢ�µ�CSysWarningQuery
	///@param	poldSysWarningQuery	ԭ����ֵ
	virtual void commitUpdate(CSysWarningQuery *pSysWarningQuery, CWriteableSysWarningQuery *pOldSysWarningQuery)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysWarningQuery	�Ѿ�ɾ����CSysWarningQuery
	virtual void commitRemove(CWriteableSysWarningQuery *pSysWarningQuery)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysWarningQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysWarningQueryIterator��һ���Ը澯��ϸӦ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysWarningQueryIterator
{
public:
	///���췽��
	CSysWarningQueryIterator(void)
	{
	}

	///���췽��
	CSysWarningQueryIterator(CSysWarningQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysWarningQueryIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysWarningQuery
	///@return	��һ����������CSysWarningQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysWarningQuery *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysWarningQueryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysWarningQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysWarningQuery * pSysWarningQuery,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysWarningQueryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSyslogEvent��һ���洢��־�¼���ѯӦ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSyslogEvent
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! OccurDate.isValid())
			return 0;
		if (! OccurTime.isValid())
			return 0;
		if (! EvendID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! EventName.isValid())
			return 0;
		if (! EventNum.isValid())
			return 0;
		if (! EventType.isValid())
			return 0;
		if (! EventDes.isValid())
			return 0;
		if (! ProcessFlag.isValid())
			return 0;
		if (! WarningLevel.isValid())
			return 0;
		if (! EventDealDes.isValid())
			return 0;
		if (! FullEventName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSyslogEvent *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�¼���������
	CDateType OccurDate;
	///�¼�����ʱ��
	CTimeType OccurTime;
	///�¼�ID
	CVolumeType EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType ObjectID;
	///IP��ַ
	CIPAddressType IPAddress;
	///�¼���
	CTypeObjectIDType EventName;
	///�¼���ǩ
	CVolumeType EventNum;
	///�¼�����
	CVolumeType EventType;
	///�¼�����
	CTypeDescriptionType EventDes;
	///������
	CTypeProcessFlagType ProcessFlag;
	///���漶��
	CTypeWarningLevelType WarningLevel;
	///�¼���������
	CTypeObjectIDType EventDealDes;
	///�¼�ȫ��
	CNetAttrTypeType FullEventName;
	
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

typedef const CWriteableSyslogEvent CSyslogEvent;

/////////////////////////////////////////////////////////////////////////
///CSyslogEventActionTrigger�ǲ�����־�¼���ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventActionTrigger
{
public:
	///���췽��
	CSyslogEventActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSyslogEventActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSyslogEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSyslogEvent	Ҫ�����SyslogEvent
	virtual void beforeAdd(CWriteableSyslogEvent *pSyslogEvent)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSyslogEvent	�Ѿ������SyslogEvent
	virtual void afterAdd(CSyslogEvent *pSyslogEvent)
	{
		return;
	}

	///����ǰ����	
	///@param	pSyslogEvent	��ˢ�µ�CSyslogEvent
	///@param	pNewSyslogEvent	�µ�ֵ
	virtual void beforeUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pNewSyslogEvent)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSyslogEvent	��ˢ�µ�CSyslogEvent
	virtual void afterUpdate(CSyslogEvent *pSyslogEvent)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSyslogEvent	Ҫɾ����CSyslogEvent
	virtual void beforeRemove(CSyslogEvent *pSyslogEvent)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSyslogEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventCommitTrigger��ȷ����־�¼���ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventCommitTrigger
{
public:
	///���췽��
	CSyslogEventCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSyslogEventCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSyslogEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSyslogEvent	�Ѿ������SyslogEvent
	virtual void commitAdd(CSyslogEvent *pSyslogEvent)
	{
		return;
	}

	///���º󴥷�
	///@param	pSyslogEvent	��ˢ�µ�CSyslogEvent
	///@param	poldSyslogEvent	ԭ����ֵ
	virtual void commitUpdate(CSyslogEvent *pSyslogEvent, CWriteableSyslogEvent *pOldSyslogEvent)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSyslogEvent	�Ѿ�ɾ����CSyslogEvent
	virtual void commitRemove(CWriteableSyslogEvent *pSyslogEvent)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSyslogEventFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSyslogEventIterator��һ������־�¼���ѯӦ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSyslogEventIterator
{
public:
	///���췽��
	CSyslogEventIterator(void)
	{
	}

	///���췽��
	CSyslogEventIterator(CSyslogEventFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSyslogEventIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SyslogEvent
	///@return	��һ����������CSyslogEvent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSyslogEvent *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSyslogEventFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSyslogEvent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSyslogEvent * pSyslogEvent,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSyslogEventFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysEventDescrip��һ���洢�¼�������ѯ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysEventDescrip
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
		if (! EventDesID.isValid())
			return 0;
		if (! UserName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! EventDes.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysEventDescrip *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///����ID��
	CEventDesIDType EventDesID;
	///�¼�������
	CTypeObjectIDType UserName;
	///�¼���������
	CDateType MonDate;
	///�¼�����ʱ��
	CTimeType MonTime;
	///��������
	CDescriptionType EventDes;
	
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

typedef const CWriteableSysEventDescrip CSysEventDescrip;

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripActionTrigger�ǲ����¼�������ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripActionTrigger
{
public:
	///���췽��
	CSysEventDescripActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysEventDescripActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysEventDescripFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysEventDescrip	Ҫ�����SysEventDescrip
	virtual void beforeAdd(CWriteableSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysEventDescrip	�Ѿ������SysEventDescrip
	virtual void afterAdd(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysEventDescrip	��ˢ�µ�CSysEventDescrip
	///@param	pNewSysEventDescrip	�µ�ֵ
	virtual void beforeUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pNewSysEventDescrip)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysEventDescrip	��ˢ�µ�CSysEventDescrip
	virtual void afterUpdate(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysEventDescrip	Ҫɾ����CSysEventDescrip
	virtual void beforeRemove(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysEventDescripFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripCommitTrigger��ȷ���¼�������ѯʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripCommitTrigger
{
public:
	///���췽��
	CSysEventDescripCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysEventDescripCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysEventDescripFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysEventDescrip	�Ѿ������SysEventDescrip
	virtual void commitAdd(CSysEventDescrip *pSysEventDescrip)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysEventDescrip	��ˢ�µ�CSysEventDescrip
	///@param	poldSysEventDescrip	ԭ����ֵ
	virtual void commitUpdate(CSysEventDescrip *pSysEventDescrip, CWriteableSysEventDescrip *pOldSysEventDescrip)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysEventDescrip	�Ѿ�ɾ����CSysEventDescrip
	virtual void commitRemove(CWriteableSysEventDescrip *pSysEventDescrip)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysEventDescripFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysEventDescripIterator��һ�����¼�������ѯ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysEventDescripIterator
{
public:
	///���췽��
	CSysEventDescripIterator(void)
	{
	}

	///���췽��
	CSysEventDescripIterator(CSysEventDescripFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysEventDescripIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysEventDescrip
	///@return	��һ����������CSysEventDescrip������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysEventDescrip *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysEventDescripFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysEventDescrip ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysEventDescrip * pSysEventDescrip,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysEventDescripFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvCommon��һ���洢����������Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvCommon
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! HostModel.isValid())
			return 0;
		if (! MainMemory.isValid())
			return 0;
		if (! CPUVendor.isValid())
			return 0;
		if (! CPUModel.isValid())
			return 0;
		if (! CPUMHz.isValid())
			return 0;
		if (! CPUCache.isValid())
			return 0;
		if (! CPUCores.isValid())
			return 0;
		if (! Processors.isValid())
			return 0;
		if (! OsMode.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvCommon *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�����ͺ�
	CTypeHostModelType HostModel;
	///�ڴ��С(K)
	CVolumeType MainMemory;
	///CPU����
	CTypeHostModelType CPUVendor;
	///CPU�ͺ�
	CTypeHostModelType CPUModel;
	///CPU��Ƶ
	CTypeHostModelType CPUMHz;
	///CPU����
	CTypeHostModelType CPUCache;
	///CPU�ں���
	CVolumeType CPUCores;
	///CPU����
	CVolumeType Processors;
	///32λ����64λ����ϵͳ
	CVolumeType OsMode;
	
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

typedef const CWriteableRspQryHostEnvCommon CRspQryHostEnvCommon;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonActionTrigger�ǲ�������������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonActionTrigger
{
public:
	///���췽��
	CRspQryHostEnvCommonActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvCommonActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvCommonFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRspQryHostEnvCommon	Ҫ�����RspQryHostEnvCommon
	virtual void beforeAdd(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRspQryHostEnvCommon	�Ѿ������RspQryHostEnvCommon
	virtual void afterAdd(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}

	///����ǰ����	
	///@param	pRspQryHostEnvCommon	��ˢ�µ�CRspQryHostEnvCommon
	///@param	pNewRspQryHostEnvCommon	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pNewRspQryHostEnvCommon)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRspQryHostEnvCommon	��ˢ�µ�CRspQryHostEnvCommon
	virtual void afterUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvCommon	Ҫɾ����CRspQryHostEnvCommon
	virtual void beforeRemove(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvCommonFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonCommitTrigger��ȷ������������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonCommitTrigger
{
public:
	///���췽��
	CRspQryHostEnvCommonCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvCommonCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvCommonFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRspQryHostEnvCommon	�Ѿ������RspQryHostEnvCommon
	virtual void commitAdd(CRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}

	///���º󴥷�
	///@param	pRspQryHostEnvCommon	��ˢ�µ�CRspQryHostEnvCommon
	///@param	poldRspQryHostEnvCommon	ԭ����ֵ
	virtual void commitUpdate(CRspQryHostEnvCommon *pRspQryHostEnvCommon, CWriteableRspQryHostEnvCommon *pOldRspQryHostEnvCommon)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRspQryHostEnvCommon	�Ѿ�ɾ����CRspQryHostEnvCommon
	virtual void commitRemove(CWriteableRspQryHostEnvCommon *pRspQryHostEnvCommon)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvCommonFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvCommonIterator��һ��������������Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvCommonIterator
{
public:
	///���췽��
	CRspQryHostEnvCommonIterator(void)
	{
	}

	///���췽��
	CRspQryHostEnvCommonIterator(CRspQryHostEnvCommonFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvCommonIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RspQryHostEnvCommon
	///@return	��һ����������CRspQryHostEnvCommon������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvCommon *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRspQryHostEnvCommonFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvCommon ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvCommon * pRspQryHostEnvCommon,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRspQryHostEnvCommonFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvLan��һ���洢��������Lan��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvLan
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LanHardwareID.isValid())
			return 0;
		if (! LanHardwareValue.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvLan *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///LanID
	CTypeHostModelType LanHardwareID;
	///Mac��ַ
	CTypeHostModelType LanHardwareValue;
	
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

typedef const CWriteableRspQryHostEnvLan CRspQryHostEnvLan;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanActionTrigger�ǲ�����������Lan��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanActionTrigger
{
public:
	///���췽��
	CRspQryHostEnvLanActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvLanActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvLanFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRspQryHostEnvLan	Ҫ�����RspQryHostEnvLan
	virtual void beforeAdd(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRspQryHostEnvLan	�Ѿ������RspQryHostEnvLan
	virtual void afterAdd(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}

	///����ǰ����	
	///@param	pRspQryHostEnvLan	��ˢ�µ�CRspQryHostEnvLan
	///@param	pNewRspQryHostEnvLan	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pNewRspQryHostEnvLan)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRspQryHostEnvLan	��ˢ�µ�CRspQryHostEnvLan
	virtual void afterUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvLan	Ҫɾ����CRspQryHostEnvLan
	virtual void beforeRemove(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvLanFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCommitTrigger��ȷ����������Lan��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCommitTrigger
{
public:
	///���췽��
	CRspQryHostEnvLanCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvLanCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvLanFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRspQryHostEnvLan	�Ѿ������RspQryHostEnvLan
	virtual void commitAdd(CRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}

	///���º󴥷�
	///@param	pRspQryHostEnvLan	��ˢ�µ�CRspQryHostEnvLan
	///@param	poldRspQryHostEnvLan	ԭ����ֵ
	virtual void commitUpdate(CRspQryHostEnvLan *pRspQryHostEnvLan, CWriteableRspQryHostEnvLan *pOldRspQryHostEnvLan)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRspQryHostEnvLan	�Ѿ�ɾ����CRspQryHostEnvLan
	virtual void commitRemove(CWriteableRspQryHostEnvLan *pRspQryHostEnvLan)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvLanFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanIterator��һ������������Lan��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanIterator
{
public:
	///���췽��
	CRspQryHostEnvLanIterator(void)
	{
	}

	///���췽��
	CRspQryHostEnvLanIterator(CRspQryHostEnvLanFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvLanIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RspQryHostEnvLan
	///@return	��һ����������CRspQryHostEnvLan������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLan *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRspQryHostEnvLanFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLan ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLan * pRspQryHostEnvLan,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRspQryHostEnvLanFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvStorage��һ���洢���������洢�豸��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvStorage
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! StorageDev.isValid())
			return 0;
		if (! HWPath.isValid())
			return 0;
		if (! Interface.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvStorage *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///Storage Devices
	CTypeHostModelType StorageDev;
	///HW Path
	CTypeHostModelType HWPath;
	///Interface
	CTypeHostModelType Interface;
	
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

typedef const CWriteableRspQryHostEnvStorage CRspQryHostEnvStorage;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageActionTrigger�ǲ������������洢�豸��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageActionTrigger
{
public:
	///���췽��
	CRspQryHostEnvStorageActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvStorageActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvStorageFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRspQryHostEnvStorage	Ҫ�����RspQryHostEnvStorage
	virtual void beforeAdd(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRspQryHostEnvStorage	�Ѿ������RspQryHostEnvStorage
	virtual void afterAdd(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}

	///����ǰ����	
	///@param	pRspQryHostEnvStorage	��ˢ�µ�CRspQryHostEnvStorage
	///@param	pNewRspQryHostEnvStorage	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pNewRspQryHostEnvStorage)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRspQryHostEnvStorage	��ˢ�µ�CRspQryHostEnvStorage
	virtual void afterUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvStorage	Ҫɾ����CRspQryHostEnvStorage
	virtual void beforeRemove(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvStorageFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageCommitTrigger��ȷ�����������洢�豸��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageCommitTrigger
{
public:
	///���췽��
	CRspQryHostEnvStorageCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvStorageCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvStorageFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRspQryHostEnvStorage	�Ѿ������RspQryHostEnvStorage
	virtual void commitAdd(CRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}

	///���º󴥷�
	///@param	pRspQryHostEnvStorage	��ˢ�µ�CRspQryHostEnvStorage
	///@param	poldRspQryHostEnvStorage	ԭ����ֵ
	virtual void commitUpdate(CRspQryHostEnvStorage *pRspQryHostEnvStorage, CWriteableRspQryHostEnvStorage *pOldRspQryHostEnvStorage)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRspQryHostEnvStorage	�Ѿ�ɾ����CRspQryHostEnvStorage
	virtual void commitRemove(CWriteableRspQryHostEnvStorage *pRspQryHostEnvStorage)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvStorageFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvStorageIterator��һ�������������洢�豸��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvStorageIterator
{
public:
	///���췽��
	CRspQryHostEnvStorageIterator(void)
	{
	}

	///���췽��
	CRspQryHostEnvStorageIterator(CRspQryHostEnvStorageFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvStorageIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RspQryHostEnvStorage
	///@return	��һ����������CRspQryHostEnvStorage������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvStorage *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRspQryHostEnvStorageFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvStorage ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvStorage * pRspQryHostEnvStorage,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRspQryHostEnvStorageFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvIO��һ���洢��������IO�豸��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvIO
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! IoClass.isValid())
			return 0;
		if (! H_WPath.isValid())
			return 0;
		if (! IoDriver.isValid())
			return 0;
		if (! IoDescription.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvIO *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///IO Class
	CTypeChar10Type IoClass;
	///H/W Path
	CTypeChar10Type H_WPath;
	///Driver
	CTypeChar10Type IoDriver;
	///Description
	CTypeDescriptionType IoDescription;
	
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

typedef const CWriteableRspQryHostEnvIO CRspQryHostEnvIO;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOActionTrigger�ǲ�����������IO�豸��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOActionTrigger
{
public:
	///���췽��
	CRspQryHostEnvIOActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvIOActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRspQryHostEnvIO	Ҫ�����RspQryHostEnvIO
	virtual void beforeAdd(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRspQryHostEnvIO	�Ѿ������RspQryHostEnvIO
	virtual void afterAdd(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}

	///����ǰ����	
	///@param	pRspQryHostEnvIO	��ˢ�µ�CRspQryHostEnvIO
	///@param	pNewRspQryHostEnvIO	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pNewRspQryHostEnvIO)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRspQryHostEnvIO	��ˢ�µ�CRspQryHostEnvIO
	virtual void afterUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvIO	Ҫɾ����CRspQryHostEnvIO
	virtual void beforeRemove(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOCommitTrigger��ȷ����������IO�豸��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOCommitTrigger
{
public:
	///���췽��
	CRspQryHostEnvIOCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvIOCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRspQryHostEnvIO	�Ѿ������RspQryHostEnvIO
	virtual void commitAdd(CRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}

	///���º󴥷�
	///@param	pRspQryHostEnvIO	��ˢ�µ�CRspQryHostEnvIO
	///@param	poldRspQryHostEnvIO	ԭ����ֵ
	virtual void commitUpdate(CRspQryHostEnvIO *pRspQryHostEnvIO, CWriteableRspQryHostEnvIO *pOldRspQryHostEnvIO)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRspQryHostEnvIO	�Ѿ�ɾ����CRspQryHostEnvIO
	virtual void commitRemove(CWriteableRspQryHostEnvIO *pRspQryHostEnvIO)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvIOIterator��һ������������IO�豸��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvIOIterator
{
public:
	///���췽��
	CRspQryHostEnvIOIterator(void)
	{
	}

	///���췽��
	CRspQryHostEnvIOIterator(CRspQryHostEnvIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvIOIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RspQryHostEnvIO
	///@return	��һ����������CRspQryHostEnvIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvIO *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRspQryHostEnvIOFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvIO * pRspQryHostEnvIO,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRspQryHostEnvIOFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvFS��һ���洢���������ļ�ϵͳ��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvFS
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LVMDeviceFile.isValid())
			return 0;
		if (! MountPoint.isValid())
			return 0;
		if (! FSsize.isValid())
			return 0;
		if (! FSType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvFS *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///LVM Device file
	CTypeHostModelType LVMDeviceFile;
	///mount point
	CTypeCommandType MountPoint;
	///size
	CVolumeType FSsize;
	///fs type
	CTypeChar10Type FSType;
	
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

typedef const CWriteableRspQryHostEnvFS CRspQryHostEnvFS;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSActionTrigger�ǲ������������ļ�ϵͳ��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSActionTrigger
{
public:
	///���췽��
	CRspQryHostEnvFSActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvFSActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvFSFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRspQryHostEnvFS	Ҫ�����RspQryHostEnvFS
	virtual void beforeAdd(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRspQryHostEnvFS	�Ѿ������RspQryHostEnvFS
	virtual void afterAdd(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}

	///����ǰ����	
	///@param	pRspQryHostEnvFS	��ˢ�µ�CRspQryHostEnvFS
	///@param	pNewRspQryHostEnvFS	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pNewRspQryHostEnvFS)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRspQryHostEnvFS	��ˢ�µ�CRspQryHostEnvFS
	virtual void afterUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvFS	Ҫɾ����CRspQryHostEnvFS
	virtual void beforeRemove(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvFSFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSCommitTrigger��ȷ�����������ļ�ϵͳ��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSCommitTrigger
{
public:
	///���췽��
	CRspQryHostEnvFSCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvFSCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvFSFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRspQryHostEnvFS	�Ѿ������RspQryHostEnvFS
	virtual void commitAdd(CRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}

	///���º󴥷�
	///@param	pRspQryHostEnvFS	��ˢ�µ�CRspQryHostEnvFS
	///@param	poldRspQryHostEnvFS	ԭ����ֵ
	virtual void commitUpdate(CRspQryHostEnvFS *pRspQryHostEnvFS, CWriteableRspQryHostEnvFS *pOldRspQryHostEnvFS)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRspQryHostEnvFS	�Ѿ�ɾ����CRspQryHostEnvFS
	virtual void commitRemove(CWriteableRspQryHostEnvFS *pRspQryHostEnvFS)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvFSFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvFSIterator��һ�������������ļ�ϵͳ��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvFSIterator
{
public:
	///���췽��
	CRspQryHostEnvFSIterator(void)
	{
	}

	///���췽��
	CRspQryHostEnvFSIterator(CRspQryHostEnvFSFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvFSIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RspQryHostEnvFS
	///@return	��һ����������CRspQryHostEnvFS������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvFS *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRspQryHostEnvFSFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvFS ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvFS * pRspQryHostEnvFS,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRspQryHostEnvFSFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvSwap��һ���洢������������������Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvSwap
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! type.isValid())
			return 0;
		if (! size.isValid())
			return 0;
		if (! priority.isValid())
			return 0;
		if (! location.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvSwap *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///type
	CTypeChar10Type type;
	///size
	CVolumeType size;
	///priority
	CVolumeType priority;
	///device location
	CTypeHostModelType location;
	
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

typedef const CWriteableRspQryHostEnvSwap CRspQryHostEnvSwap;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapActionTrigger�ǲ���������������������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapActionTrigger
{
public:
	///���췽��
	CRspQryHostEnvSwapActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvSwapActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvSwapFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRspQryHostEnvSwap	Ҫ�����RspQryHostEnvSwap
	virtual void beforeAdd(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRspQryHostEnvSwap	�Ѿ������RspQryHostEnvSwap
	virtual void afterAdd(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}

	///����ǰ����	
	///@param	pRspQryHostEnvSwap	��ˢ�µ�CRspQryHostEnvSwap
	///@param	pNewRspQryHostEnvSwap	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pNewRspQryHostEnvSwap)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRspQryHostEnvSwap	��ˢ�µ�CRspQryHostEnvSwap
	virtual void afterUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvSwap	Ҫɾ����CRspQryHostEnvSwap
	virtual void beforeRemove(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvSwapFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapCommitTrigger��ȷ��������������������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapCommitTrigger
{
public:
	///���췽��
	CRspQryHostEnvSwapCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvSwapCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvSwapFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRspQryHostEnvSwap	�Ѿ������RspQryHostEnvSwap
	virtual void commitAdd(CRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}

	///���º󴥷�
	///@param	pRspQryHostEnvSwap	��ˢ�µ�CRspQryHostEnvSwap
	///@param	poldRspQryHostEnvSwap	ԭ����ֵ
	virtual void commitUpdate(CRspQryHostEnvSwap *pRspQryHostEnvSwap, CWriteableRspQryHostEnvSwap *pOldRspQryHostEnvSwap)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRspQryHostEnvSwap	�Ѿ�ɾ����CRspQryHostEnvSwap
	virtual void commitRemove(CWriteableRspQryHostEnvSwap *pRspQryHostEnvSwap)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvSwapFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvSwapIterator��һ����������������������Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvSwapIterator
{
public:
	///���췽��
	CRspQryHostEnvSwapIterator(void)
	{
	}

	///���췽��
	CRspQryHostEnvSwapIterator(CRspQryHostEnvSwapFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvSwapIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RspQryHostEnvSwap
	///@return	��һ����������CRspQryHostEnvSwap������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvSwap *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRspQryHostEnvSwapFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvSwap ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvSwap * pRspQryHostEnvSwap,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRspQryHostEnvSwapFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableRspQryHostEnvLanCfg��һ���洢������������������Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableRspQryHostEnvLanCfg
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LanName.isValid())
			return 0;
		if (! IpAddress.isValid())
			return 0;
		if (! IpMask.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableRspQryHostEnvLanCfg *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	CTypeLanNameType LanName;
	CIPAddressType IpAddress;
	CIPAddressType IpMask;
	
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

typedef const CWriteableRspQryHostEnvLanCfg CRspQryHostEnvLanCfg;

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgActionTrigger�ǲ���������������������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgActionTrigger
{
public:
	///���췽��
	CRspQryHostEnvLanCfgActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvLanCfgActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvLanCfgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pRspQryHostEnvLanCfg	Ҫ�����RspQryHostEnvLanCfg
	virtual void beforeAdd(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///����󴥷�
	///@param	pRspQryHostEnvLanCfg	�Ѿ������RspQryHostEnvLanCfg
	virtual void afterAdd(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}

	///����ǰ����	
	///@param	pRspQryHostEnvLanCfg	��ˢ�µ�CRspQryHostEnvLanCfg
	///@param	pNewRspQryHostEnvLanCfg	�µ�ֵ
	virtual void beforeUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pNewRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pRspQryHostEnvLanCfg	��ˢ�µ�CRspQryHostEnvLanCfg
	virtual void afterUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pRspQryHostEnvLanCfg	Ҫɾ����CRspQryHostEnvLanCfg
	virtual void beforeRemove(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvLanCfgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgCommitTrigger��ȷ��������������������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgCommitTrigger
{
public:
	///���췽��
	CRspQryHostEnvLanCfgCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CRspQryHostEnvLanCfgCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CRspQryHostEnvLanCfgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pRspQryHostEnvLanCfg	�Ѿ������RspQryHostEnvLanCfg
	virtual void commitAdd(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}

	///���º󴥷�
	///@param	pRspQryHostEnvLanCfg	��ˢ�µ�CRspQryHostEnvLanCfg
	///@param	poldRspQryHostEnvLanCfg	ԭ����ֵ
	virtual void commitUpdate(CRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg, CWriteableRspQryHostEnvLanCfg *pOldRspQryHostEnvLanCfg)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pRspQryHostEnvLanCfg	�Ѿ�ɾ����CRspQryHostEnvLanCfg
	virtual void commitRemove(CWriteableRspQryHostEnvLanCfg *pRspQryHostEnvLanCfg)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CRspQryHostEnvLanCfgFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CRspQryHostEnvLanCfgIterator��һ����������������������Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CRspQryHostEnvLanCfgIterator
{
public:
	///���췽��
	CRspQryHostEnvLanCfgIterator(void)
	{
	}

	///���췽��
	CRspQryHostEnvLanCfgIterator(CRspQryHostEnvLanCfgFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CRspQryHostEnvLanCfgIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��RspQryHostEnvLanCfg
	///@return	��һ����������CRspQryHostEnvLanCfg������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CRspQryHostEnvLanCfg *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CRspQryHostEnvLanCfgFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pRspQryHostEnvLanCfg ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableRspQryHostEnvLanCfg * pRspQryHostEnvLanCfg,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CRspQryHostEnvLanCfgFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTopCpuInfo��һ���洢CPU��Դʹ����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTopCpuInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! CPU.isValid())
			return 0;
		if (! LOAD.isValid())
			return 0;
		if (! USER.isValid())
			return 0;
		if (! NICE.isValid())
			return 0;
		if (! SYS.isValid())
			return 0;
		if (! IDLE.isValid())
			return 0;
		if (! BLOCK.isValid())
			return 0;
		if (! SWAIT.isValid())
			return 0;
		if (! INTR.isValid())
			return 0;
		if (! SSYS.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTopCpuInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CVolumeType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///CPU�ı��
	CTypeCPUIdType CPU;
	CRatioType LOAD;
	CRatioType USER;
	CRatioType NICE;
	CRatioType SYS;
	CRatioType IDLE;
	CRatioType BLOCK;
	CRatioType SWAIT;
	CRatioType INTR;
	CRatioType SSYS;
	
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

typedef const CWriteableSysMdbTopCpuInfo CSysMdbTopCpuInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoActionTrigger�ǲ���CPU��Դʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoActionTrigger
{
public:
	///���췽��
	CSysMdbTopCpuInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTopCpuInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTopCpuInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbTopCpuInfo	Ҫ�����SysMdbTopCpuInfo
	virtual void beforeAdd(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbTopCpuInfo	�Ѿ������SysMdbTopCpuInfo
	virtual void afterAdd(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbTopCpuInfo	��ˢ�µ�CSysMdbTopCpuInfo
	///@param	pNewSysMdbTopCpuInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pNewSysMdbTopCpuInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbTopCpuInfo	��ˢ�µ�CSysMdbTopCpuInfo
	virtual void afterUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbTopCpuInfo	Ҫɾ����CSysMdbTopCpuInfo
	virtual void beforeRemove(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTopCpuInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoCommitTrigger��ȷ��CPU��Դʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbTopCpuInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTopCpuInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTopCpuInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbTopCpuInfo	�Ѿ������SysMdbTopCpuInfo
	virtual void commitAdd(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbTopCpuInfo	��ˢ�µ�CSysMdbTopCpuInfo
	///@param	poldSysMdbTopCpuInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbTopCpuInfo *pSysMdbTopCpuInfo, CWriteableSysMdbTopCpuInfo *pOldSysMdbTopCpuInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbTopCpuInfo	�Ѿ�ɾ����CSysMdbTopCpuInfo
	virtual void commitRemove(CWriteableSysMdbTopCpuInfo *pSysMdbTopCpuInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTopCpuInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopCpuInfoIterator��һ����CPU��Դʹ����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopCpuInfoIterator
{
public:
	///���췽��
	CSysMdbTopCpuInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbTopCpuInfoIterator(CSysMdbTopCpuInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopCpuInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbTopCpuInfo
	///@return	��һ����������CSysMdbTopCpuInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopCpuInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbTopCpuInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopCpuInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopCpuInfo * pSysMdbTopCpuInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbTopCpuInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTopMemInfo��һ���洢�ڴ���Դʹ����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTopMemInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! TOTALREAL.isValid())
			return 0;
		if (! ACTIVEREAL.isValid())
			return 0;
		if (! TOTALVIRTUAL.isValid())
			return 0;
		if (! ACTIVEVIRTUAL.isValid())
			return 0;
		if (! FREE.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTopMemInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CVolumeType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///Total Real Memory
	CVolumeType TOTALREAL;
	///Active Real Memory
	CVolumeType ACTIVEREAL;
	///Total Virtual Memory
	CVolumeType TOTALVIRTUAL;
	///Active Virtual Memory
	CVolumeType ACTIVEVIRTUAL;
	///Free Memory
	CVolumeType FREE;
	
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

typedef const CWriteableSysMdbTopMemInfo CSysMdbTopMemInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoActionTrigger�ǲ����ڴ���Դʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoActionTrigger
{
public:
	///���췽��
	CSysMdbTopMemInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTopMemInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTopMemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbTopMemInfo	Ҫ�����SysMdbTopMemInfo
	virtual void beforeAdd(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbTopMemInfo	�Ѿ������SysMdbTopMemInfo
	virtual void afterAdd(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbTopMemInfo	��ˢ�µ�CSysMdbTopMemInfo
	///@param	pNewSysMdbTopMemInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pNewSysMdbTopMemInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbTopMemInfo	��ˢ�µ�CSysMdbTopMemInfo
	virtual void afterUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbTopMemInfo	Ҫɾ����CSysMdbTopMemInfo
	virtual void beforeRemove(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTopMemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoCommitTrigger��ȷ���ڴ���Դʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbTopMemInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTopMemInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTopMemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbTopMemInfo	�Ѿ������SysMdbTopMemInfo
	virtual void commitAdd(CSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbTopMemInfo	��ˢ�µ�CSysMdbTopMemInfo
	///@param	poldSysMdbTopMemInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbTopMemInfo *pSysMdbTopMemInfo, CWriteableSysMdbTopMemInfo *pOldSysMdbTopMemInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbTopMemInfo	�Ѿ�ɾ����CSysMdbTopMemInfo
	virtual void commitRemove(CWriteableSysMdbTopMemInfo *pSysMdbTopMemInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTopMemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopMemInfoIterator��һ�����ڴ���Դʹ����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopMemInfoIterator
{
public:
	///���췽��
	CSysMdbTopMemInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbTopMemInfoIterator(CSysMdbTopMemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopMemInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbTopMemInfo
	///@return	��һ����������CSysMdbTopMemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopMemInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbTopMemInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopMemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopMemInfo * pSysMdbTopMemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbTopMemInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTopProcessInfo��һ���洢������Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTopProcessInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! CPU.isValid())
			return 0;
		if (! TTY.isValid())
			return 0;
		if (! PID.isValid())
			return 0;
		if (! USERNAME.isValid())
			return 0;
		if (! PRI.isValid())
			return 0;
		if (! NI.isValid())
			return 0;
		if (! SIZE.isValid())
			return 0;
		if (! RES.isValid())
			return 0;
		if (! STATE.isValid())
			return 0;
		if (! TIME.isValid())
			return 0;
		if (! pWCPU.isValid())
			return 0;
		if (! pCPU.isValid())
			return 0;
		if (! COMMAND.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTopProcessInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CVolumeType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///��������
	CTypeCPUIdType CPU;
	///�ն���
	CTypeChar10Type TTY;
	///���̺�
	CVolumeType PID;
	///�û���
	CTypeChar10Type USERNAME;
	///��������ȼ�
	CVolumeType PRI;
	///�����niceֵ
	CVolumeType NI;
	///����Ĵ�����������ټ���ջ�ռ�Ĵ�С
	CVolumeType SIZE;
	///����ʹ�õ������ڴ��������
	CVolumeType RES;
	///�����״̬
	CTypeChar10Type STATE;
	///������ʼʱʹ�õ���CPUʱ��
	CTimeType TIME;
	///���̵�CPU������Ȩ�ذٷֱ�
	CRatioType pWCPU;
	///���̵�ԭʼ��CPU�����ʰٷֱ�
	CRatioType pCPU;
	///�������̵�������
	CTypeCommandType COMMAND;
	
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

typedef const CWriteableSysMdbTopProcessInfo CSysMdbTopProcessInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoActionTrigger�ǲ���������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoActionTrigger
{
public:
	///���췽��
	CSysMdbTopProcessInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTopProcessInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTopProcessInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbTopProcessInfo	Ҫ�����SysMdbTopProcessInfo
	virtual void beforeAdd(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbTopProcessInfo	�Ѿ������SysMdbTopProcessInfo
	virtual void afterAdd(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbTopProcessInfo	��ˢ�µ�CSysMdbTopProcessInfo
	///@param	pNewSysMdbTopProcessInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pNewSysMdbTopProcessInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbTopProcessInfo	��ˢ�µ�CSysMdbTopProcessInfo
	virtual void afterUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbTopProcessInfo	Ҫɾ����CSysMdbTopProcessInfo
	virtual void beforeRemove(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTopProcessInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoCommitTrigger��ȷ�Ͻ�����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbTopProcessInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTopProcessInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTopProcessInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbTopProcessInfo	�Ѿ������SysMdbTopProcessInfo
	virtual void commitAdd(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbTopProcessInfo	��ˢ�µ�CSysMdbTopProcessInfo
	///@param	poldSysMdbTopProcessInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbTopProcessInfo *pSysMdbTopProcessInfo, CWriteableSysMdbTopProcessInfo *pOldSysMdbTopProcessInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbTopProcessInfo	�Ѿ�ɾ����CSysMdbTopProcessInfo
	virtual void commitRemove(CWriteableSysMdbTopProcessInfo *pSysMdbTopProcessInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTopProcessInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTopProcessInfoIterator��һ���Խ�����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTopProcessInfoIterator
{
public:
	///���췽��
	CSysMdbTopProcessInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbTopProcessInfoIterator(CSysMdbTopProcessInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTopProcessInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbTopProcessInfo
	///@return	��һ����������CSysMdbTopProcessInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTopProcessInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbTopProcessInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTopProcessInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTopProcessInfo * pSysMdbTopProcessInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbTopProcessInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbFileSystemInfo��һ���洢�ļ�ϵͳ��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbFileSystemInfo
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
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! FILESYSTEM.isValid())
			return 0;
		if (! SIZE.isValid())
			return 0;
		if (! USED.isValid())
			return 0;
		if (! AVAIL.isValid())
			return 0;
		if (! pUSERD.isValid())
			return 0;
		if (! ISIZE.isValid())
			return 0;
		if (! IUSED.isValid())
			return 0;
		if (! IFREE.isValid())
			return 0;
		if (! pIUSED.isValid())
			return 0;
		if (! MountedOn.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbFileSystemInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��������
	CVolumeType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�ļ�ϵͳ������
	CTypeCommandType FILESYSTEM;
	///�ռ�����
	CVolumeType SIZE;
	///���ÿռ��С
	CVolumeType USED;
	///���ÿռ��С
	CVolumeType AVAIL;
	///���õİٷֱ�
	CRatioType pUSERD;
	///inode����
	CVolumeType ISIZE;
	///����inode��С
	CVolumeType IUSED;
	///����inode��С
	CVolumeType IFREE;
	///���õİٷֱ�
	CRatioType pIUSED;
	///����λ��
	CTypeCommandType MountedOn;
	
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

typedef const CWriteableSysMdbFileSystemInfo CSysMdbFileSystemInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoActionTrigger�ǲ����ļ�ϵͳ��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoActionTrigger
{
public:
	///���췽��
	CSysMdbFileSystemInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbFileSystemInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbFileSystemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbFileSystemInfo	Ҫ�����SysMdbFileSystemInfo
	virtual void beforeAdd(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbFileSystemInfo	�Ѿ������SysMdbFileSystemInfo
	virtual void afterAdd(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbFileSystemInfo	��ˢ�µ�CSysMdbFileSystemInfo
	///@param	pNewSysMdbFileSystemInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pNewSysMdbFileSystemInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbFileSystemInfo	��ˢ�µ�CSysMdbFileSystemInfo
	virtual void afterUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbFileSystemInfo	Ҫɾ����CSysMdbFileSystemInfo
	virtual void beforeRemove(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbFileSystemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoCommitTrigger��ȷ���ļ�ϵͳ��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbFileSystemInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbFileSystemInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbFileSystemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbFileSystemInfo	�Ѿ������SysMdbFileSystemInfo
	virtual void commitAdd(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbFileSystemInfo	��ˢ�µ�CSysMdbFileSystemInfo
	///@param	poldSysMdbFileSystemInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbFileSystemInfo *pSysMdbFileSystemInfo, CWriteableSysMdbFileSystemInfo *pOldSysMdbFileSystemInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbFileSystemInfo	�Ѿ�ɾ����CSysMdbFileSystemInfo
	virtual void commitRemove(CWriteableSysMdbFileSystemInfo *pSysMdbFileSystemInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbFileSystemInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbFileSystemInfoIterator��һ�����ļ�ϵͳ��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbFileSystemInfoIterator
{
public:
	///���췽��
	CSysMdbFileSystemInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbFileSystemInfoIterator(CSysMdbFileSystemInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbFileSystemInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbFileSystemInfo
	///@return	��һ����������CSysMdbFileSystemInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbFileSystemInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbFileSystemInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbFileSystemInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbFileSystemInfo * pSysMdbFileSystemInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbFileSystemInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbNetworkInfo��һ���洢����ʹ����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbNetworkInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! LANNAME.isValid())
			return 0;
		if (! LANSTATUS.isValid())
			return 0;
		if (! IPADDRESS.isValid())
			return 0;
		if (! RECVBYTES.isValid())
			return 0;
		if (! RECVPACKETS.isValid())
			return 0;
		if (! RECVERRORPACKETS.isValid())
			return 0;
		if (! RECVDROPPACKETS.isValid())
			return 0;
		if (! SENDBYTES.isValid())
			return 0;
		if (! SENDPACKETS.isValid())
			return 0;
		if (! SENDERRORPACKETS.isValid())
			return 0;
		if (! SENDDROPPACKETS.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbNetworkInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///��������
	CVolumeType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///������
	CTypeLanNameType LANNAME;
	///������up��down״̬
	CTypeLanStatusType LANSTATUS;
	///������ip��ַ
	CIPAddressType IPADDRESS;
	///�������յ�����
	CLargeNumberType RECVBYTES;
	///�������յ����ݰ�
	CLargeNumberType RECVPACKETS;
	///�������ն˴������ݰ�
	CLargeNumberType RECVERRORPACKETS;
	///�������ն˶�ʧ���ݰ�
	CLargeNumberType RECVDROPPACKETS;
	///�������͵�����
	CLargeNumberType SENDBYTES;
	///�������͵����ݰ�
	CLargeNumberType SENDPACKETS;
	///�������Ͷ˴������ݰ�
	CLargeNumberType SENDERRORPACKETS;
	///�������Ͷ˶�ʧ���ݰ�
	CLargeNumberType SENDDROPPACKETS;
	
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

typedef const CWriteableSysMdbNetworkInfo CSysMdbNetworkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoActionTrigger�ǲ�������ʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoActionTrigger
{
public:
	///���췽��
	CSysMdbNetworkInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbNetworkInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbNetworkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbNetworkInfo	Ҫ�����SysMdbNetworkInfo
	virtual void beforeAdd(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbNetworkInfo	�Ѿ������SysMdbNetworkInfo
	virtual void afterAdd(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbNetworkInfo	��ˢ�µ�CSysMdbNetworkInfo
	///@param	pNewSysMdbNetworkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pNewSysMdbNetworkInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbNetworkInfo	��ˢ�µ�CSysMdbNetworkInfo
	virtual void afterUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbNetworkInfo	Ҫɾ����CSysMdbNetworkInfo
	virtual void beforeRemove(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbNetworkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoCommitTrigger��ȷ������ʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbNetworkInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbNetworkInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbNetworkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbNetworkInfo	�Ѿ������SysMdbNetworkInfo
	virtual void commitAdd(CSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbNetworkInfo	��ˢ�µ�CSysMdbNetworkInfo
	///@param	poldSysMdbNetworkInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbNetworkInfo *pSysMdbNetworkInfo, CWriteableSysMdbNetworkInfo *pOldSysMdbNetworkInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbNetworkInfo	�Ѿ�ɾ����CSysMdbNetworkInfo
	virtual void commitRemove(CWriteableSysMdbNetworkInfo *pSysMdbNetworkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbNetworkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetworkInfoIterator��һ��������ʹ����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetworkInfoIterator
{
public:
	///���췽��
	CSysMdbNetworkInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbNetworkInfoIterator(CSysMdbNetworkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetworkInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbNetworkInfo
	///@return	��һ����������CSysMdbNetworkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetworkInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbNetworkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetworkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetworkInfo * pSysMdbNetworkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbNetworkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysParticipantInit��һ���洢��Ա�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysParticipantInit
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysParticipantInit *pOriginal) const;
	
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
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysParticipantInit CSysParticipantInit;

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitActionTrigger�ǲ�����Աʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitActionTrigger
{
public:
	///���췽��
	CSysParticipantInitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysParticipantInitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysParticipantInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysParticipantInit	Ҫ�����SysParticipantInit
	virtual void beforeAdd(CWriteableSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysParticipantInit	�Ѿ������SysParticipantInit
	virtual void afterAdd(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysParticipantInit	��ˢ�µ�CSysParticipantInit
	///@param	pNewSysParticipantInit	�µ�ֵ
	virtual void beforeUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pNewSysParticipantInit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysParticipantInit	��ˢ�µ�CSysParticipantInit
	virtual void afterUpdate(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysParticipantInit	Ҫɾ����CSysParticipantInit
	virtual void beforeRemove(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysParticipantInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitCommitTrigger��ȷ�ϻ�Աʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitCommitTrigger
{
public:
	///���췽��
	CSysParticipantInitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysParticipantInitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysParticipantInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysParticipantInit	�Ѿ������SysParticipantInit
	virtual void commitAdd(CSysParticipantInit *pSysParticipantInit)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysParticipantInit	��ˢ�µ�CSysParticipantInit
	///@param	poldSysParticipantInit	ԭ����ֵ
	virtual void commitUpdate(CSysParticipantInit *pSysParticipantInit, CWriteableSysParticipantInit *pOldSysParticipantInit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysParticipantInit	�Ѿ�ɾ����CSysParticipantInit
	virtual void commitRemove(CWriteableSysParticipantInit *pSysParticipantInit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysParticipantInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticipantInitIterator��һ���Ի�Ա��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticipantInitIterator
{
public:
	///���췽��
	CSysParticipantInitIterator(void)
	{
	}

	///���췽��
	CSysParticipantInitIterator(CSysParticipantInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysParticipantInitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysParticipantInit
	///@return	��һ����������CSysParticipantInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticipantInit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysParticipantInitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticipantInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticipantInit * pSysParticipantInit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysParticipantInitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysUserInit��һ���洢�����û��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysUserInit
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysUserInit *pOriginal) const;
	
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
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysUserInit CSysUserInit;

/////////////////////////////////////////////////////////////////////////
///CSysUserInitActionTrigger�ǲ��������û�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitActionTrigger
{
public:
	///���췽��
	CSysUserInitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysUserInitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysUserInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysUserInit	Ҫ�����SysUserInit
	virtual void beforeAdd(CWriteableSysUserInit *pSysUserInit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysUserInit	�Ѿ������SysUserInit
	virtual void afterAdd(CSysUserInit *pSysUserInit)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysUserInit	��ˢ�µ�CSysUserInit
	///@param	pNewSysUserInit	�µ�ֵ
	virtual void beforeUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pNewSysUserInit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysUserInit	��ˢ�µ�CSysUserInit
	virtual void afterUpdate(CSysUserInit *pSysUserInit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysUserInit	Ҫɾ����CSysUserInit
	virtual void beforeRemove(CSysUserInit *pSysUserInit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysUserInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitCommitTrigger��ȷ�Ͻ����û�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitCommitTrigger
{
public:
	///���췽��
	CSysUserInitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysUserInitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysUserInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysUserInit	�Ѿ������SysUserInit
	virtual void commitAdd(CSysUserInit *pSysUserInit)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysUserInit	��ˢ�µ�CSysUserInit
	///@param	poldSysUserInit	ԭ����ֵ
	virtual void commitUpdate(CSysUserInit *pSysUserInit, CWriteableSysUserInit *pOldSysUserInit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysUserInit	�Ѿ�ɾ����CSysUserInit
	virtual void commitRemove(CWriteableSysUserInit *pSysUserInit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysUserInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysUserInitIterator��һ���Խ����û���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysUserInitIterator
{
public:
	///���췽��
	CSysUserInitIterator(void)
	{
	}

	///���췽��
	CSysUserInitIterator(CSysUserInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysUserInitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysUserInit
	///@return	��һ����������CSysUserInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysUserInit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysUserInitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysUserInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysUserInit * pSysUserInit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysUserInitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysClientInit��һ���洢�ͻ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysClientInit
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
		if (! OperationType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysClientInit *pOriginal) const;
	
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
	///��������
	CDBOperationTypeType OperationType;
	
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

typedef const CWriteableSysClientInit CSysClientInit;

/////////////////////////////////////////////////////////////////////////
///CSysClientInitActionTrigger�ǲ����ͻ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitActionTrigger
{
public:
	///���췽��
	CSysClientInitActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientInitActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysClientInit	Ҫ�����SysClientInit
	virtual void beforeAdd(CWriteableSysClientInit *pSysClientInit)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysClientInit	�Ѿ������SysClientInit
	virtual void afterAdd(CSysClientInit *pSysClientInit)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysClientInit	��ˢ�µ�CSysClientInit
	///@param	pNewSysClientInit	�µ�ֵ
	virtual void beforeUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pNewSysClientInit)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysClientInit	��ˢ�µ�CSysClientInit
	virtual void afterUpdate(CSysClientInit *pSysClientInit)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysClientInit	Ҫɾ����CSysClientInit
	virtual void beforeRemove(CSysClientInit *pSysClientInit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitCommitTrigger��ȷ�Ͽͻ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitCommitTrigger
{
public:
	///���췽��
	CSysClientInitCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysClientInitCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysClientInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysClientInit	�Ѿ������SysClientInit
	virtual void commitAdd(CSysClientInit *pSysClientInit)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysClientInit	��ˢ�µ�CSysClientInit
	///@param	poldSysClientInit	ԭ����ֵ
	virtual void commitUpdate(CSysClientInit *pSysClientInit, CWriteableSysClientInit *pOldSysClientInit)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysClientInit	�Ѿ�ɾ����CSysClientInit
	virtual void commitRemove(CWriteableSysClientInit *pSysClientInit)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysClientInitFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysClientInitIterator��һ���Կͻ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysClientInitIterator
{
public:
	///���췽��
	CSysClientInitIterator(void)
	{
	}

	///���췽��
	CSysClientInitIterator(CSysClientInitFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysClientInitIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysClientInit
	///@return	��һ����������CSysClientInit������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysClientInit *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysClientInitFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysClientInit ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysClientInit * pSysClientInit,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysClientInitFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysTradeUserLoginInfo��һ���洢����ϵͳ��¼��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysTradeUserLoginInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! UserID.isValid())
			return 0;
		if (! ParticipantID.isValid())
			return 0;
		if (! ProtocolInfo.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! FrontID.isValid())
			return 0;
		if (! UserType.isValid())
			return 0;
		if (! AccessType.isValid())
			return 0;
		if (! ActionDate.isValid())
			return 0;
		if (! ActionTime.isValid())
			return 0;
		if (! ActionFlag.isValid())
			return 0;
		if (! DataCenter.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysTradeUserLoginInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///����ID
	CTypeObjectIDType ObjectID;
	///�����û�����
	CUserIDType UserID;
	///��Ա����
	CParticipantIDType ParticipantID;
	///Э����Ϣ
	CProtocolInfoType ProtocolInfo;
	///IP��ַ
	CIPAddressType IPAddress;
	///ǰ�û����
	CFrontIDType FrontID;
	///�û����
	CTypeObjectIDType UserType;
	/// ���뷽ʽ
	CTypeObjectIDType AccessType;
	///��¼��ǳ�����
	CDateType ActionDate;
	///��¼��ǳ�ʱ��
	CTimeType ActionTime;
	///��¼��ǳ����
	CValueTypeType ActionFlag;
	///����������
	CTypeObjectIDType DataCenter;
	
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

typedef const CWriteableSysTradeUserLoginInfo CSysTradeUserLoginInfo;

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoActionTrigger�ǲ�������ϵͳ��¼��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoActionTrigger
{
public:
	///���췽��
	CSysTradeUserLoginInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysTradeUserLoginInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysTradeUserLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysTradeUserLoginInfo	Ҫ�����SysTradeUserLoginInfo
	virtual void beforeAdd(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysTradeUserLoginInfo	�Ѿ������SysTradeUserLoginInfo
	virtual void afterAdd(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysTradeUserLoginInfo	��ˢ�µ�CSysTradeUserLoginInfo
	///@param	pNewSysTradeUserLoginInfo	�µ�ֵ
	virtual void beforeUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pNewSysTradeUserLoginInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysTradeUserLoginInfo	��ˢ�µ�CSysTradeUserLoginInfo
	virtual void afterUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysTradeUserLoginInfo	Ҫɾ����CSysTradeUserLoginInfo
	virtual void beforeRemove(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysTradeUserLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoCommitTrigger��ȷ�Ͻ���ϵͳ��¼��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoCommitTrigger
{
public:
	///���췽��
	CSysTradeUserLoginInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysTradeUserLoginInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysTradeUserLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysTradeUserLoginInfo	�Ѿ������SysTradeUserLoginInfo
	virtual void commitAdd(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysTradeUserLoginInfo	��ˢ�µ�CSysTradeUserLoginInfo
	///@param	poldSysTradeUserLoginInfo	ԭ����ֵ
	virtual void commitUpdate(CSysTradeUserLoginInfo *pSysTradeUserLoginInfo, CWriteableSysTradeUserLoginInfo *pOldSysTradeUserLoginInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysTradeUserLoginInfo	�Ѿ�ɾ����CSysTradeUserLoginInfo
	virtual void commitRemove(CWriteableSysTradeUserLoginInfo *pSysTradeUserLoginInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysTradeUserLoginInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysTradeUserLoginInfoIterator��һ���Խ���ϵͳ��¼��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysTradeUserLoginInfoIterator
{
public:
	///���췽��
	CSysTradeUserLoginInfoIterator(void)
	{
	}

	///���췽��
	CSysTradeUserLoginInfoIterator(CSysTradeUserLoginInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysTradeUserLoginInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysTradeUserLoginInfo
	///@return	��һ����������CSysTradeUserLoginInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysTradeUserLoginInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysTradeUserLoginInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysTradeUserLoginInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysTradeUserLoginInfo * pSysTradeUserLoginInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysTradeUserLoginInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbWebAppInfo��һ���洢WebӦ����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbWebAppInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! AppName.isValid())
			return 0;
		if (! Status.isValid())
			return 0;
		if (! Desc.isValid())
			return 0;
		if (! StartTime.isValid())
			return 0;
		if (! ServletNum.isValid())
			return 0;
		if (! ProcessTime.isValid())
			return 0;
		if (! RequestNum.isValid())
			return 0;
		if (! ErrorNum.isValid())
			return 0;
		if (! SessionSize.isValid())
			return 0;
		if (! TimeOut.isValid())
			return 0;
		if (! JDBCUsage.isValid())
			return 0;
		if (! JSPNum.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbWebAppInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��ض���
	CVolumeType ObjectID;
	///�������
	CDateType MonDate;
	///���ʱ��
	CTimeType MonTime;
	///WebӦ������
	CCfgNameType AppName;
	///Ӧ������״̬
	CTypeObjectNameType Status;
	///Ӧ��������Ϣ
	CTypeDescriptionType Desc;
	///Ӧ������ʱ��
	CTypeCurrentTimeType StartTime;
	///Ӧ��servlet����
	CTypeChar10Type ServletNum;
	///Ӧ�ô�����ʱ��
	CTypeCommandType ProcessTime;
	///Ӧ���ۼƽ���������
	CTypeCommandType RequestNum;
	///Ӧ���ۼƴ�����
	CTypeCommandType ErrorNum;
	///Ӧ�õ�ǰ�Ự��
	CTypeChar10Type SessionSize;
	///�Ự��ʱʱ��(��)
	CTypeChar10Type TimeOut;
	///Ӧ��JDBC����ʹ����
	CTypeChar10Type JDBCUsage;
	///Ӧ��JSP�ļ�����
	CTypeChar10Type JSPNum;
	
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

typedef const CWriteableSysMdbWebAppInfo CSysMdbWebAppInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoActionTrigger�ǲ���WebӦ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoActionTrigger
{
public:
	///���췽��
	CSysMdbWebAppInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbWebAppInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbWebAppInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbWebAppInfo	Ҫ�����SysMdbWebAppInfo
	virtual void beforeAdd(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbWebAppInfo	�Ѿ������SysMdbWebAppInfo
	virtual void afterAdd(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbWebAppInfo	��ˢ�µ�CSysMdbWebAppInfo
	///@param	pNewSysMdbWebAppInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pNewSysMdbWebAppInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbWebAppInfo	��ˢ�µ�CSysMdbWebAppInfo
	virtual void afterUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbWebAppInfo	Ҫɾ����CSysMdbWebAppInfo
	virtual void beforeRemove(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbWebAppInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoCommitTrigger��ȷ��WebӦ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbWebAppInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbWebAppInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbWebAppInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbWebAppInfo	�Ѿ������SysMdbWebAppInfo
	virtual void commitAdd(CSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbWebAppInfo	��ˢ�µ�CSysMdbWebAppInfo
	///@param	poldSysMdbWebAppInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbWebAppInfo *pSysMdbWebAppInfo, CWriteableSysMdbWebAppInfo *pOldSysMdbWebAppInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbWebAppInfo	�Ѿ�ɾ����CSysMdbWebAppInfo
	virtual void commitRemove(CWriteableSysMdbWebAppInfo *pSysMdbWebAppInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbWebAppInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbWebAppInfoIterator��һ����WebӦ����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbWebAppInfoIterator
{
public:
	///���췽��
	CSysMdbWebAppInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbWebAppInfoIterator(CSysMdbWebAppInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbWebAppInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbWebAppInfo
	///@return	��һ����������CSysMdbWebAppInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbWebAppInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbWebAppInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbWebAppInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbWebAppInfo * pSysMdbWebAppInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbWebAppInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbMemPoolInfo��һ���洢ϵͳ�ڴ����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbMemPoolInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! PoolName.isValid())
			return 0;
		if (! Usage.isValid())
			return 0;
		if (! committedbytes.isValid())
			return 0;
		if (! initbytes.isValid())
			return 0;
		if (! maxbytes.isValid())
			return 0;
		if (! usedbytes.isValid())
			return 0;
		if (! Type.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbMemPoolInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��ض���
	CVolumeType ObjectID;
	///�������
	CDateType MonDate;
	///���ʱ��
	CTimeType MonTime;
	///ϵͳ������
	CCfgNameType PoolName;
	///ϵͳ������
	CTypeChar10Type Usage;
	///ϵͳ������
	CTypeCommandType committedbytes;
	///ϵͳ������
	CTypeCommandType initbytes;
	///ϵͳ������
	CTypeCommandType maxbytes;
	///ϵͳ������
	CTypeCommandType usedbytes;
	///ϵͳ������
	CTypeChar10Type Type;
	
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

typedef const CWriteableSysMdbMemPoolInfo CSysMdbMemPoolInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoActionTrigger�ǲ���ϵͳ�ڴ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoActionTrigger
{
public:
	///���췽��
	CSysMdbMemPoolInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbMemPoolInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbMemPoolInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbMemPoolInfo	Ҫ�����SysMdbMemPoolInfo
	virtual void beforeAdd(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbMemPoolInfo	�Ѿ������SysMdbMemPoolInfo
	virtual void afterAdd(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbMemPoolInfo	��ˢ�µ�CSysMdbMemPoolInfo
	///@param	pNewSysMdbMemPoolInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pNewSysMdbMemPoolInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbMemPoolInfo	��ˢ�µ�CSysMdbMemPoolInfo
	virtual void afterUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbMemPoolInfo	Ҫɾ����CSysMdbMemPoolInfo
	virtual void beforeRemove(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbMemPoolInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoCommitTrigger��ȷ��ϵͳ�ڴ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbMemPoolInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbMemPoolInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbMemPoolInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbMemPoolInfo	�Ѿ������SysMdbMemPoolInfo
	virtual void commitAdd(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbMemPoolInfo	��ˢ�µ�CSysMdbMemPoolInfo
	///@param	poldSysMdbMemPoolInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbMemPoolInfo *pSysMdbMemPoolInfo, CWriteableSysMdbMemPoolInfo *pOldSysMdbMemPoolInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbMemPoolInfo	�Ѿ�ɾ����CSysMdbMemPoolInfo
	virtual void commitRemove(CWriteableSysMdbMemPoolInfo *pSysMdbMemPoolInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbMemPoolInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbMemPoolInfoIterator��һ����ϵͳ�ڴ����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbMemPoolInfoIterator
{
public:
	///���췽��
	CSysMdbMemPoolInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbMemPoolInfoIterator(CSysMdbMemPoolInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbMemPoolInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbMemPoolInfo
	///@return	��һ����������CSysMdbMemPoolInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbMemPoolInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbMemPoolInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbMemPoolInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbMemPoolInfo * pSysMdbMemPoolInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbMemPoolInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbConnectorInfo��һ���洢��������Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbConnectorInfo
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
		if (! ObjectID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! ThreadsCount.isValid())
			return 0;
		if (! BusyThreadsCount.isValid())
			return 0;
		if (! MaxThreads.isValid())
			return 0;
		if (! MaxSpareThreads.isValid())
			return 0;
		if (! MinSpareThreads.isValid())
			return 0;
		if (! MaxTime.isValid())
			return 0;
		if (! MaxProcTime.isValid())
			return 0;
		if (! RequestCount.isValid())
			return 0;
		if (! ErrorCount.isValid())
			return 0;
		if (! BytesReceived.isValid())
			return 0;
		if (! BytesSent.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbConnectorInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///��ض���
	CVolumeType ObjectID;
	///�������
	CDateType MonDate;
	///���ʱ��
	CTimeType MonTime;
	///����������
	CTypeObjectNameType Name;
	///��ǰ�����߳���
	CTypeChar10Type ThreadsCount;
	///��ǰ��æ�߳���
	CTypeChar10Type BusyThreadsCount;
	///����߳���
	CTypeChar10Type MaxThreads;
	///�������߳���
	CTypeChar10Type MaxSpareThreads;
	///��С�����߳���
	CTypeChar10Type MinSpareThreads;
	///�����ʱ��
	CTypeCommandType MaxTime;
	///�����ʱ��
	CTypeCommandType MaxProcTime;
	///�ۼƽ���������
	CTypeCommandType RequestCount;
	///�ۼƴ�����
	CTypeCommandType ErrorCount;
	///�ۼƽ����ֽ���
	CTypeChar10Type BytesReceived;
	///�ۼƷ����ֽ���
	CTypeChar10Type BytesSent;
	
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

typedef const CWriteableSysMdbConnectorInfo CSysMdbConnectorInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoActionTrigger�ǲ�����������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoActionTrigger
{
public:
	///���췽��
	CSysMdbConnectorInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbConnectorInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbConnectorInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbConnectorInfo	Ҫ�����SysMdbConnectorInfo
	virtual void beforeAdd(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbConnectorInfo	�Ѿ������SysMdbConnectorInfo
	virtual void afterAdd(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbConnectorInfo	��ˢ�µ�CSysMdbConnectorInfo
	///@param	pNewSysMdbConnectorInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pNewSysMdbConnectorInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbConnectorInfo	��ˢ�µ�CSysMdbConnectorInfo
	virtual void afterUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbConnectorInfo	Ҫɾ����CSysMdbConnectorInfo
	virtual void beforeRemove(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbConnectorInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoCommitTrigger��ȷ����������Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbConnectorInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbConnectorInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbConnectorInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbConnectorInfo	�Ѿ������SysMdbConnectorInfo
	virtual void commitAdd(CSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbConnectorInfo	��ˢ�µ�CSysMdbConnectorInfo
	///@param	poldSysMdbConnectorInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbConnectorInfo *pSysMdbConnectorInfo, CWriteableSysMdbConnectorInfo *pOldSysMdbConnectorInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbConnectorInfo	�Ѿ�ɾ����CSysMdbConnectorInfo
	virtual void commitRemove(CWriteableSysMdbConnectorInfo *pSysMdbConnectorInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbConnectorInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbConnectorInfoIterator��һ������������Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbConnectorInfoIterator
{
public:
	///���췽��
	CSysMdbConnectorInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbConnectorInfoIterator(CSysMdbConnectorInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbConnectorInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbConnectorInfo
	///@return	��һ����������CSysMdbConnectorInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbConnectorInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbConnectorInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbConnectorInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbConnectorInfo * pSysMdbConnectorInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbConnectorInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbDBQuery��һ���洢���ݿ��ѯӦ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbDBQuery
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
		if (! SubcriberID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! DBQueryResult.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbDBQuery *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///���ݿ�ʵ������ID
	CVolumeType ObjectID;
	///�洢������
	CVolumeType AttrType;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///���ݿ��ѯ���
	CDBQueryResultType DBQueryResult;
	
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

typedef const CWriteableSysMdbDBQuery CSysMdbDBQuery;

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryActionTrigger�ǲ������ݿ��ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryActionTrigger
{
public:
	///���췽��
	CSysMdbDBQueryActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbDBQueryActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbDBQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbDBQuery	Ҫ�����SysMdbDBQuery
	virtual void beforeAdd(CWriteableSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbDBQuery	�Ѿ������SysMdbDBQuery
	virtual void afterAdd(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbDBQuery	��ˢ�µ�CSysMdbDBQuery
	///@param	pNewSysMdbDBQuery	�µ�ֵ
	virtual void beforeUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pNewSysMdbDBQuery)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbDBQuery	��ˢ�µ�CSysMdbDBQuery
	virtual void afterUpdate(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbDBQuery	Ҫɾ����CSysMdbDBQuery
	virtual void beforeRemove(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbDBQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryCommitTrigger��ȷ�����ݿ��ѯӦ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryCommitTrigger
{
public:
	///���췽��
	CSysMdbDBQueryCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbDBQueryCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbDBQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbDBQuery	�Ѿ������SysMdbDBQuery
	virtual void commitAdd(CSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbDBQuery	��ˢ�µ�CSysMdbDBQuery
	///@param	poldSysMdbDBQuery	ԭ����ֵ
	virtual void commitUpdate(CSysMdbDBQuery *pSysMdbDBQuery, CWriteableSysMdbDBQuery *pOldSysMdbDBQuery)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbDBQuery	�Ѿ�ɾ����CSysMdbDBQuery
	virtual void commitRemove(CWriteableSysMdbDBQuery *pSysMdbDBQuery)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbDBQueryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDBQueryIterator��һ�������ݿ��ѯӦ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDBQueryIterator
{
public:
	///���췽��
	CSysMdbDBQueryIterator(void)
	{
	}

	///���췽��
	CSysMdbDBQueryIterator(CSysMdbDBQueryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDBQueryIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbDBQuery
	///@return	��һ����������CSysMdbDBQuery������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDBQuery *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbDBQueryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDBQuery ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDBQuery * pSysMdbDBQuery,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbDBQueryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetArea��һ���洢����������ֵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetArea
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetArea *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///����������
	CTypeObjectIDType CName;
	///����Ӣ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetArea CSysNetArea;

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaActionTrigger�ǲ��������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaActionTrigger
{
public:
	///���췽��
	CSysNetAreaActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetAreaActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetArea	Ҫ�����SysNetArea
	virtual void beforeAdd(CWriteableSysNetArea *pSysNetArea)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetArea	�Ѿ������SysNetArea
	virtual void afterAdd(CSysNetArea *pSysNetArea)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetArea	��ˢ�µ�CSysNetArea
	///@param	pNewSysNetArea	�µ�ֵ
	virtual void beforeUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pNewSysNetArea)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetArea	��ˢ�µ�CSysNetArea
	virtual void afterUpdate(CSysNetArea *pSysNetArea)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetArea	Ҫɾ����CSysNetArea
	virtual void beforeRemove(CSysNetArea *pSysNetArea)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaCommitTrigger��ȷ�������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaCommitTrigger
{
public:
	///���췽��
	CSysNetAreaCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetAreaCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetArea	�Ѿ������SysNetArea
	virtual void commitAdd(CSysNetArea *pSysNetArea)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetArea	��ˢ�µ�CSysNetArea
	///@param	poldSysNetArea	ԭ����ֵ
	virtual void commitUpdate(CSysNetArea *pSysNetArea, CWriteableSysNetArea *pOldSysNetArea)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetArea	�Ѿ�ɾ����CSysNetArea
	virtual void commitRemove(CWriteableSysNetArea *pSysNetArea)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetAreaIterator��һ��������������ֵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetAreaIterator
{
public:
	///���췽��
	CSysNetAreaIterator(void)
	{
	}

	///���췽��
	CSysNetAreaIterator(CSysNetAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetAreaIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetArea
	///@return	��һ����������CSysNetArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetArea *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetAreaFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetArea * pSysNetArea,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetAreaFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetSubArea��һ���洢���������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetSubArea
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
		if (! ID.isValid())
			return 0;
		if (! SysNetAreaID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetSubArea *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///SysNetArea
	CVolumeType SysNetAreaID;
	///����������
	CTypeObjectIDType CName;
	///����Ӣ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetSubArea CSysNetSubArea;

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaActionTrigger�ǲ�����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaActionTrigger
{
public:
	///���췽��
	CSysNetSubAreaActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetSubAreaActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetSubAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetSubArea	Ҫ�����SysNetSubArea
	virtual void beforeAdd(CWriteableSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetSubArea	�Ѿ������SysNetSubArea
	virtual void afterAdd(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetSubArea	��ˢ�µ�CSysNetSubArea
	///@param	pNewSysNetSubArea	�µ�ֵ
	virtual void beforeUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pNewSysNetSubArea)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetSubArea	��ˢ�µ�CSysNetSubArea
	virtual void afterUpdate(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetSubArea	Ҫɾ����CSysNetSubArea
	virtual void beforeRemove(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetSubAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaCommitTrigger��ȷ����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaCommitTrigger
{
public:
	///���췽��
	CSysNetSubAreaCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetSubAreaCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetSubAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetSubArea	�Ѿ������SysNetSubArea
	virtual void commitAdd(CSysNetSubArea *pSysNetSubArea)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetSubArea	��ˢ�µ�CSysNetSubArea
	///@param	poldSysNetSubArea	ԭ����ֵ
	virtual void commitUpdate(CSysNetSubArea *pSysNetSubArea, CWriteableSysNetSubArea *pOldSysNetSubArea)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetSubArea	�Ѿ�ɾ����CSysNetSubArea
	virtual void commitRemove(CWriteableSysNetSubArea *pSysNetSubArea)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetSubAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIterator��һ��������������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIterator
{
public:
	///���췽��
	CSysNetSubAreaIterator(void)
	{
	}

	///���췽��
	CSysNetSubAreaIterator(CSysNetSubAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetSubAreaIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetSubArea
	///@return	��һ����������CSysNetSubArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubArea *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetSubAreaFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubArea * pSysNetSubArea,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetSubAreaFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetSubAreaIP��һ���洢��������IP�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetSubAreaIP
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
		if (! ID.isValid())
			return 0;
		if (! SysNetSubAreaID.isValid())
			return 0;
		if (! IP.isValid())
			return 0;
		if (! Mask.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetSubAreaIP *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///SysNetSubAreaID
	CVolumeType SysNetSubAreaID;
	///ip��ַ
	CIPAddressType IP;
	///����
	CIPAddressType Mask;
	
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

typedef const CWriteableSysNetSubAreaIP CSysNetSubAreaIP;

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPActionTrigger�ǲ�����������IPʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPActionTrigger
{
public:
	///���췽��
	CSysNetSubAreaIPActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetSubAreaIPActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetSubAreaIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetSubAreaIP	Ҫ�����SysNetSubAreaIP
	virtual void beforeAdd(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetSubAreaIP	�Ѿ������SysNetSubAreaIP
	virtual void afterAdd(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetSubAreaIP	��ˢ�µ�CSysNetSubAreaIP
	///@param	pNewSysNetSubAreaIP	�µ�ֵ
	virtual void beforeUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pNewSysNetSubAreaIP)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetSubAreaIP	��ˢ�µ�CSysNetSubAreaIP
	virtual void afterUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetSubAreaIP	Ҫɾ����CSysNetSubAreaIP
	virtual void beforeRemove(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetSubAreaIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPCommitTrigger��ȷ����������IPʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPCommitTrigger
{
public:
	///���췽��
	CSysNetSubAreaIPCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetSubAreaIPCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetSubAreaIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetSubAreaIP	�Ѿ������SysNetSubAreaIP
	virtual void commitAdd(CSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetSubAreaIP	��ˢ�µ�CSysNetSubAreaIP
	///@param	poldSysNetSubAreaIP	ԭ����ֵ
	virtual void commitUpdate(CSysNetSubAreaIP *pSysNetSubAreaIP, CWriteableSysNetSubAreaIP *pOldSysNetSubAreaIP)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetSubAreaIP	�Ѿ�ɾ����CSysNetSubAreaIP
	virtual void commitRemove(CWriteableSysNetSubAreaIP *pSysNetSubAreaIP)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetSubAreaIPFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubAreaIPIterator��һ������������IP��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubAreaIPIterator
{
public:
	///���췽��
	CSysNetSubAreaIPIterator(void)
	{
	}

	///���췽��
	CSysNetSubAreaIPIterator(CSysNetSubAreaIPFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetSubAreaIPIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetSubAreaIP
	///@return	��һ����������CSysNetSubAreaIP������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubAreaIP *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetSubAreaIPFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubAreaIP ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubAreaIP * pSysNetSubAreaIP,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetSubAreaIPFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetFuncArea��һ���洢ְ�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetFuncArea
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
		if (! ID.isValid())
			return 0;
		if (! SysNetSubAreaID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetFuncArea *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///SysNetSubAreaID
	CVolumeType SysNetSubAreaID;
	///����������
	CTypeObjectIDType CName;
	///����Ӣ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetFuncArea CSysNetFuncArea;

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaActionTrigger�ǲ���ְ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaActionTrigger
{
public:
	///���췽��
	CSysNetFuncAreaActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetFuncAreaActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetFuncAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetFuncArea	Ҫ�����SysNetFuncArea
	virtual void beforeAdd(CWriteableSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetFuncArea	�Ѿ������SysNetFuncArea
	virtual void afterAdd(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetFuncArea	��ˢ�µ�CSysNetFuncArea
	///@param	pNewSysNetFuncArea	�µ�ֵ
	virtual void beforeUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pNewSysNetFuncArea)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetFuncArea	��ˢ�µ�CSysNetFuncArea
	virtual void afterUpdate(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetFuncArea	Ҫɾ����CSysNetFuncArea
	virtual void beforeRemove(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetFuncAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaCommitTrigger��ȷ��ְ����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaCommitTrigger
{
public:
	///���췽��
	CSysNetFuncAreaCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetFuncAreaCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetFuncAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetFuncArea	�Ѿ������SysNetFuncArea
	virtual void commitAdd(CSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetFuncArea	��ˢ�µ�CSysNetFuncArea
	///@param	poldSysNetFuncArea	ԭ����ֵ
	virtual void commitUpdate(CSysNetFuncArea *pSysNetFuncArea, CWriteableSysNetFuncArea *pOldSysNetFuncArea)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetFuncArea	�Ѿ�ɾ����CSysNetFuncArea
	virtual void commitRemove(CWriteableSysNetFuncArea *pSysNetFuncArea)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetFuncAreaFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetFuncAreaIterator��һ����ְ������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetFuncAreaIterator
{
public:
	///���췽��
	CSysNetFuncAreaIterator(void)
	{
	}

	///���췽��
	CSysNetFuncAreaIterator(CSysNetFuncAreaFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetFuncAreaIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetFuncArea
	///@return	��һ����������CSysNetFuncArea������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetFuncArea *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetFuncAreaFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetFuncArea ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetFuncArea * pSysNetFuncArea,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetFuncAreaFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDevice��һ���洢�����豸�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDevice
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! SysNetSubAreaID.isValid())
			return 0;
		if (! CATEGORY_ID.isValid())
			return 0;
		if (! FuctionArea.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! IPDECODE.isValid())
			return 0;
		if (! NAME.isValid())
			return 0;
		if (! PORTNUMBER.isValid())
			return 0;
		if (! CONFIGFILE.isValid())
			return 0;
		if (! RCOMMUNITY.isValid())
			return 0;
		if (! SNMPVERSION.isValid())
			return 0;
		if (! RAMSIZE.isValid())
			return 0;
		if (! FLASHSIZE.isValid())
			return 0;
		if (! NVRAMSIZE.isValid())
			return 0;
		if (! CABINET_ID.isValid())
			return 0;
		if (! ROOM_ID.isValid())
			return 0;
		if (! IOSVERSION_ID.isValid())
			return 0;
		if (! DESCRIPTION.isValid())
			return 0;
		if (! USERNAME.isValid())
			return 0;
		if (! PASSWD.isValid())
			return 0;
		if (! ENPASSWD.isValid())
			return 0;
		if (! MANUFACTORY_ID.isValid())
			return 0;
		if (! CFGSAVETYPE.isValid())
			return 0;
		if (! DEVICETYPE.isValid())
			return 0;
		if (! SENDSMS.isValid())
			return 0;
		if (! ISSNMP.isValid())
			return 0;
		if (! SLOTNUM.isValid())
			return 0;
		if (! ISPING.isValid())
			return 0;
		if (! IFNUM.isValid())
			return 0;
		if (! APPLICATION_ID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDevice *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��ض���
	CNetObjectIDType ObjectID;
	///��ض�������
	CVolumeType MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType SysNetSubAreaID;
	///����ID  
	CVolumeType CATEGORY_ID;
	///��Ϊ���ֵ�ְ������  
	CTypeObjectIDType FuctionArea;
	///IP��ַ  
	CIPAddressType IPADDR;
	///IP��    
	CVolumeType IPDECODE;
	///�豸���� 
	CNetObjectIDType NAME;
	///             
	CVolumeType PORTNUMBER;
	///          
	CTypeObjectIDType CONFIGFILE;
	///��ͬ����  
	CTypeObjectIDType RCOMMUNITY;
	///snmp�汾     
	CVolumeType SNMPVERSION;
	///ramsize(B)   
	CVolumeType RAMSIZE;
	///falshsize(B) 
	CVolumeType FLASHSIZE;
	///nvramsize(B) 
	CVolumeType NVRAMSIZE;
	///��������
	CVolumeType CABINET_ID;
	CVolumeType ROOM_ID;
	///����汾
	CVolumeType IOSVERSION_ID;
	///ϵͳ����
	CNetAttrTypeType DESCRIPTION;
	///��¼�û���
	CTypeObjectIDType USERNAME;
	///��¼����
	CNetAttrTypeType PASSWD;
	///enable����
	CNetAttrTypeType ENPASSWD;
	///��������
	CVolumeType MANUFACTORY_ID;
	///���ñ���Э��
	CVolumeType CFGSAVETYPE;
	///�豸�ͺ�
	CNetObjectIDType DEVICETYPE;
	///�Ƿ���Ÿ澯
	CVolumeType SENDSMS;
	///�Ƿ��Զ�snmp̽��
	CVolumeType ISSNMP;
	///��λ��
	CVolumeType SLOTNUM;
	///�Ƿ��Զ�ping
	CVolumeType ISPING;
	///�˿�����
	CVolumeType IFNUM;
	///Ѳ�����
	CVolumeType APPLICATION_ID;
	
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

typedef const CWriteableSysNetDevice CSysNetDevice;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceActionTrigger�ǲ��������豸ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceActionTrigger
{
public:
	///���췽��
	CSysNetDeviceActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetDevice	Ҫ�����SysNetDevice
	virtual void beforeAdd(CWriteableSysNetDevice *pSysNetDevice)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetDevice	�Ѿ������SysNetDevice
	virtual void afterAdd(CSysNetDevice *pSysNetDevice)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetDevice	��ˢ�µ�CSysNetDevice
	///@param	pNewSysNetDevice	�µ�ֵ
	virtual void beforeUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pNewSysNetDevice)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetDevice	��ˢ�µ�CSysNetDevice
	virtual void afterUpdate(CSysNetDevice *pSysNetDevice)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetDevice	Ҫɾ����CSysNetDevice
	virtual void beforeRemove(CSysNetDevice *pSysNetDevice)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCommitTrigger��ȷ�������豸ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCommitTrigger
{
public:
	///���췽��
	CSysNetDeviceCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetDevice	�Ѿ������SysNetDevice
	virtual void commitAdd(CSysNetDevice *pSysNetDevice)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetDevice	��ˢ�µ�CSysNetDevice
	///@param	poldSysNetDevice	ԭ����ֵ
	virtual void commitUpdate(CSysNetDevice *pSysNetDevice, CWriteableSysNetDevice *pOldSysNetDevice)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetDevice	�Ѿ�ɾ����CSysNetDevice
	virtual void commitRemove(CWriteableSysNetDevice *pSysNetDevice)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceIterator��һ���������豸��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceIterator
{
public:
	///���췽��
	CSysNetDeviceIterator(void)
	{
	}

	///���췽��
	CSysNetDeviceIterator(CSysNetDeviceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetDevice
	///@return	��һ����������CSysNetDevice������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDevice *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetDeviceFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDevice ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDevice * pSysNetDevice,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetDeviceFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDeviceLinked��һ���洢�����豸���ӹ�ϵ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDeviceLinked
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
		if (! ID.isValid())
			return 0;
		if (! NetDeviceID.isValid())
			return 0;
		if (! NetPortID.isValid())
			return 0;
		if (! NetObjectID.isValid())
			return 0;
		if (! NetPortType.isValid())
			return 0;
		if (! LinkNetDeviceID.isValid())
			return 0;
		if (! LinkNetPortID.isValid())
			return 0;
		if (! LinkNetObjectID.isValid())
			return 0;
		if (! LinkNetPortType.isValid())
			return 0;
		if (! LinkSource.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDeviceLinked *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�豸ID
	CVolumeType NetDeviceID;
	///�豸�˿�ID
	CVolumeType NetPortID;
	///��ض���
	CNetObjectIDType NetObjectID;
	///��ض���˿�����
	CNetDevicePortTypeType NetPortType;
	///�����豸ID
	CVolumeType LinkNetDeviceID;
	///�����豸�˿�ID
	CVolumeType LinkNetPortID;
	///���Ӷ���
	CNetObjectIDType LinkNetObjectID;
	///���Ӷ���˿�����
	CNetDevicePortTypeType LinkNetPortType;
	///������Դ
	CVolumeType LinkSource;
	
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

typedef const CWriteableSysNetDeviceLinked CSysNetDeviceLinked;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedActionTrigger�ǲ��������豸���ӹ�ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedActionTrigger
{
public:
	///���췽��
	CSysNetDeviceLinkedActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceLinkedActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceLinkedFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetDeviceLinked	Ҫ�����SysNetDeviceLinked
	virtual void beforeAdd(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetDeviceLinked	�Ѿ������SysNetDeviceLinked
	virtual void afterAdd(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetDeviceLinked	��ˢ�µ�CSysNetDeviceLinked
	///@param	pNewSysNetDeviceLinked	�µ�ֵ
	virtual void beforeUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pNewSysNetDeviceLinked)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetDeviceLinked	��ˢ�µ�CSysNetDeviceLinked
	virtual void afterUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetDeviceLinked	Ҫɾ����CSysNetDeviceLinked
	virtual void beforeRemove(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceLinkedFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedCommitTrigger��ȷ�������豸���ӹ�ϵʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedCommitTrigger
{
public:
	///���췽��
	CSysNetDeviceLinkedCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceLinkedCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceLinkedFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetDeviceLinked	�Ѿ������SysNetDeviceLinked
	virtual void commitAdd(CSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetDeviceLinked	��ˢ�µ�CSysNetDeviceLinked
	///@param	poldSysNetDeviceLinked	ԭ����ֵ
	virtual void commitUpdate(CSysNetDeviceLinked *pSysNetDeviceLinked, CWriteableSysNetDeviceLinked *pOldSysNetDeviceLinked)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetDeviceLinked	�Ѿ�ɾ����CSysNetDeviceLinked
	virtual void commitRemove(CWriteableSysNetDeviceLinked *pSysNetDeviceLinked)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceLinkedFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceLinkedIterator��һ���������豸���ӹ�ϵ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceLinkedIterator
{
public:
	///���췽��
	CSysNetDeviceLinkedIterator(void)
	{
	}

	///���췽��
	CSysNetDeviceLinkedIterator(CSysNetDeviceLinkedFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceLinkedIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetDeviceLinked
	///@return	��һ����������CSysNetDeviceLinked������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceLinked *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetDeviceLinkedFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceLinked ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceLinked * pSysNetDeviceLinked,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetDeviceLinkedFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetOID��һ���洢OID�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetOID
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory.isValid())
			return 0;
		if (! DeviceType.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! OID.isValid())
			return 0;
		if (! Unit.isValid())
			return 0;
		if (! isTheTable.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetOID *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��������
	CTypeObjectIDType Manufactory;
	///�豸�ͺ�
	CTypeObjectIDType DeviceType;
	///OID������
	CTypeObjectIDType CName;
	///OIDӢ����
	CTypeObjectIDType EName;
	///OID
	CTypeObjectIDType OID;
	///��λ
	CTypeObjectIDType Unit;
	///�Ƿ������־
	CVolumeType isTheTable;
	
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

typedef const CWriteableSysNetOID CSysNetOID;

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDActionTrigger�ǲ���OIDʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDActionTrigger
{
public:
	///���췽��
	CSysNetOIDActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetOIDActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetOID	Ҫ�����SysNetOID
	virtual void beforeAdd(CWriteableSysNetOID *pSysNetOID)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetOID	�Ѿ������SysNetOID
	virtual void afterAdd(CSysNetOID *pSysNetOID)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetOID	��ˢ�µ�CSysNetOID
	///@param	pNewSysNetOID	�µ�ֵ
	virtual void beforeUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pNewSysNetOID)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetOID	��ˢ�µ�CSysNetOID
	virtual void afterUpdate(CSysNetOID *pSysNetOID)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetOID	Ҫɾ����CSysNetOID
	virtual void beforeRemove(CSysNetOID *pSysNetOID)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDCommitTrigger��ȷ��OIDʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDCommitTrigger
{
public:
	///���췽��
	CSysNetOIDCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetOIDCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetOID	�Ѿ������SysNetOID
	virtual void commitAdd(CSysNetOID *pSysNetOID)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetOID	��ˢ�µ�CSysNetOID
	///@param	poldSysNetOID	ԭ����ֵ
	virtual void commitUpdate(CSysNetOID *pSysNetOID, CWriteableSysNetOID *pOldSysNetOID)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetOID	�Ѿ�ɾ����CSysNetOID
	virtual void commitRemove(CWriteableSysNetOID *pSysNetOID)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOIDIterator��һ����OID��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOIDIterator
{
public:
	///���췽��
	CSysNetOIDIterator(void)
	{
	}

	///���췽��
	CSysNetOIDIterator(CSysNetOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetOIDIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetOID
	///@return	��һ����������CSysNetOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOID *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetOIDFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOID * pSysNetOID,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetOIDFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDeviceType��һ���洢�����豸���͵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDeviceType
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory.isValid())
			return 0;
		if (! DeviceType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDeviceType *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��������
	CTypeObjectIDType Manufactory;
	///�豸�ͺ�
	CTypeObjectIDType DeviceType;
	
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

typedef const CWriteableSysNetDeviceType CSysNetDeviceType;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeActionTrigger�ǲ��������豸����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeActionTrigger
{
public:
	///���췽��
	CSysNetDeviceTypeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceTypeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetDeviceType	Ҫ�����SysNetDeviceType
	virtual void beforeAdd(CWriteableSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetDeviceType	�Ѿ������SysNetDeviceType
	virtual void afterAdd(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetDeviceType	��ˢ�µ�CSysNetDeviceType
	///@param	pNewSysNetDeviceType	�µ�ֵ
	virtual void beforeUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pNewSysNetDeviceType)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetDeviceType	��ˢ�µ�CSysNetDeviceType
	virtual void afterUpdate(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetDeviceType	Ҫɾ����CSysNetDeviceType
	virtual void beforeRemove(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeCommitTrigger��ȷ�������豸����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeCommitTrigger
{
public:
	///���췽��
	CSysNetDeviceTypeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceTypeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetDeviceType	�Ѿ������SysNetDeviceType
	virtual void commitAdd(CSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetDeviceType	��ˢ�µ�CSysNetDeviceType
	///@param	poldSysNetDeviceType	ԭ����ֵ
	virtual void commitUpdate(CSysNetDeviceType *pSysNetDeviceType, CWriteableSysNetDeviceType *pOldSysNetDeviceType)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetDeviceType	�Ѿ�ɾ����CSysNetDeviceType
	virtual void commitRemove(CWriteableSysNetDeviceType *pSysNetDeviceType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceTypeIterator��һ���������豸���͵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceTypeIterator
{
public:
	///���췽��
	CSysNetDeviceTypeIterator(void)
	{
	}

	///���췽��
	CSysNetDeviceTypeIterator(CSysNetDeviceTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceTypeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetDeviceType
	///@return	��һ����������CSysNetDeviceType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceType *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetDeviceTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceType * pSysNetDeviceType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetDeviceTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetTimePolicy��һ���洢ʱ����ԵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetTimePolicy
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! PolicyType.isValid())
			return 0;
		if (! PolicyString.isValid())
			return 0;
		if (! TradingDay.isValid())
			return 0;
		if (! Description.isValid())
			return 0;
		if (! Operation.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetTimePolicy *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///ʱ�����������
	CTypeObjectIDType CName;
	///ʱ�����Ӣ����
	CTypeObjectIDType EName;
	///��������
	CVolumeType PolicyType;
	///���������ô�
	CPolicyStringTypeType PolicyString;
	///����������
	CVolumeType TradingDay;
	///����������
	CNetAttrTypeType Description;
	///��������
	CVolumeType Operation;
	
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

typedef const CWriteableSysNetTimePolicy CSysNetTimePolicy;

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyActionTrigger�ǲ���ʱ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyActionTrigger
{
public:
	///���췽��
	CSysNetTimePolicyActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetTimePolicyActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetTimePolicyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetTimePolicy	Ҫ�����SysNetTimePolicy
	virtual void beforeAdd(CWriteableSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetTimePolicy	�Ѿ������SysNetTimePolicy
	virtual void afterAdd(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetTimePolicy	��ˢ�µ�CSysNetTimePolicy
	///@param	pNewSysNetTimePolicy	�µ�ֵ
	virtual void beforeUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pNewSysNetTimePolicy)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetTimePolicy	��ˢ�µ�CSysNetTimePolicy
	virtual void afterUpdate(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetTimePolicy	Ҫɾ����CSysNetTimePolicy
	virtual void beforeRemove(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetTimePolicyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyCommitTrigger��ȷ��ʱ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyCommitTrigger
{
public:
	///���췽��
	CSysNetTimePolicyCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetTimePolicyCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetTimePolicyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetTimePolicy	�Ѿ������SysNetTimePolicy
	virtual void commitAdd(CSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetTimePolicy	��ˢ�µ�CSysNetTimePolicy
	///@param	poldSysNetTimePolicy	ԭ����ֵ
	virtual void commitUpdate(CSysNetTimePolicy *pSysNetTimePolicy, CWriteableSysNetTimePolicy *pOldSysNetTimePolicy)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetTimePolicy	�Ѿ�ɾ����CSysNetTimePolicy
	virtual void commitRemove(CWriteableSysNetTimePolicy *pSysNetTimePolicy)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetTimePolicyFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetTimePolicyIterator��һ����ʱ����Ե�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetTimePolicyIterator
{
public:
	///���췽��
	CSysNetTimePolicyIterator(void)
	{
	}

	///���췽��
	CSysNetTimePolicyIterator(CSysNetTimePolicyFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetTimePolicyIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetTimePolicy
	///@return	��һ����������CSysNetTimePolicy������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetTimePolicy *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetTimePolicyFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetTimePolicy ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetTimePolicy * pSysNetTimePolicy,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetTimePolicyFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetGatherTask��һ���洢�ɼ�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetGatherTask
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! AttrType.isValid())
			return 0;
		if (! PolicyTypeID.isValid())
			return 0;
		if (! DataType.isValid())
			return 0;
		if (! TypeFlag.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetGatherTask *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�����ض���ID
	CNetObjectIDType ObjectID;
	///������ָ������
	CNetAttrTypeType AttrType;
	///ʱ�����ID
	CVolumeType PolicyTypeID;
	///��������
	CVolumeType DataType;
	///���ͱ�ʶ
	CVolumeType TypeFlag;
	
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

typedef const CWriteableSysNetGatherTask CSysNetGatherTask;

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskActionTrigger�ǲ����ɼ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskActionTrigger
{
public:
	///���췽��
	CSysNetGatherTaskActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetGatherTaskActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetGatherTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetGatherTask	Ҫ�����SysNetGatherTask
	virtual void beforeAdd(CWriteableSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetGatherTask	�Ѿ������SysNetGatherTask
	virtual void afterAdd(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetGatherTask	��ˢ�µ�CSysNetGatherTask
	///@param	pNewSysNetGatherTask	�µ�ֵ
	virtual void beforeUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pNewSysNetGatherTask)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetGatherTask	��ˢ�µ�CSysNetGatherTask
	virtual void afterUpdate(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetGatherTask	Ҫɾ����CSysNetGatherTask
	virtual void beforeRemove(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetGatherTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskCommitTrigger��ȷ�ϲɼ�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskCommitTrigger
{
public:
	///���췽��
	CSysNetGatherTaskCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetGatherTaskCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetGatherTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetGatherTask	�Ѿ������SysNetGatherTask
	virtual void commitAdd(CSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetGatherTask	��ˢ�µ�CSysNetGatherTask
	///@param	poldSysNetGatherTask	ԭ����ֵ
	virtual void commitUpdate(CSysNetGatherTask *pSysNetGatherTask, CWriteableSysNetGatherTask *pOldSysNetGatherTask)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetGatherTask	�Ѿ�ɾ����CSysNetGatherTask
	virtual void commitRemove(CWriteableSysNetGatherTask *pSysNetGatherTask)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetGatherTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGatherTaskIterator��һ���Բɼ������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGatherTaskIterator
{
public:
	///���췽��
	CSysNetGatherTaskIterator(void)
	{
	}

	///���췽��
	CSysNetGatherTaskIterator(CSysNetGatherTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetGatherTaskIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetGatherTask
	///@return	��һ����������CSysNetGatherTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGatherTask *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetGatherTaskFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGatherTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGatherTask * pSysNetGatherTask,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetGatherTaskFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDeviceCategory��һ���洢�����豸���Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDeviceCategory
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDeviceCategory *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///���������
	CTypeObjectIDType CName;
	///���Ӣ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetDeviceCategory CSysNetDeviceCategory;

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryActionTrigger�ǲ��������豸���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryActionTrigger
{
public:
	///���췽��
	CSysNetDeviceCategoryActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceCategoryActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceCategoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetDeviceCategory	Ҫ�����SysNetDeviceCategory
	virtual void beforeAdd(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetDeviceCategory	�Ѿ������SysNetDeviceCategory
	virtual void afterAdd(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetDeviceCategory	��ˢ�µ�CSysNetDeviceCategory
	///@param	pNewSysNetDeviceCategory	�µ�ֵ
	virtual void beforeUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pNewSysNetDeviceCategory)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetDeviceCategory	��ˢ�µ�CSysNetDeviceCategory
	virtual void afterUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetDeviceCategory	Ҫɾ����CSysNetDeviceCategory
	virtual void beforeRemove(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceCategoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryCommitTrigger��ȷ�ϳ����豸���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryCommitTrigger
{
public:
	///���췽��
	CSysNetDeviceCategoryCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDeviceCategoryCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDeviceCategoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetDeviceCategory	�Ѿ������SysNetDeviceCategory
	virtual void commitAdd(CSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetDeviceCategory	��ˢ�µ�CSysNetDeviceCategory
	///@param	poldSysNetDeviceCategory	ԭ����ֵ
	virtual void commitUpdate(CSysNetDeviceCategory *pSysNetDeviceCategory, CWriteableSysNetDeviceCategory *pOldSysNetDeviceCategory)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetDeviceCategory	�Ѿ�ɾ����CSysNetDeviceCategory
	virtual void commitRemove(CWriteableSysNetDeviceCategory *pSysNetDeviceCategory)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDeviceCategoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDeviceCategoryIterator��һ���Գ����豸����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDeviceCategoryIterator
{
public:
	///���췽��
	CSysNetDeviceCategoryIterator(void)
	{
	}

	///���췽��
	CSysNetDeviceCategoryIterator(CSysNetDeviceCategoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDeviceCategoryIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetDeviceCategory
	///@return	��һ����������CSysNetDeviceCategory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDeviceCategory *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetDeviceCategoryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDeviceCategory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDeviceCategory * pSysNetDeviceCategory,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetDeviceCategoryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetManufactory��һ���洢�豸���̵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetManufactory
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetManufactory *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///����������
	CTypeObjectIDType CName;
	///����Ӣ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetManufactory CSysNetManufactory;

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryActionTrigger�ǲ����豸����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryActionTrigger
{
public:
	///���췽��
	CSysNetManufactoryActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetManufactoryActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetManufactoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetManufactory	Ҫ�����SysNetManufactory
	virtual void beforeAdd(CWriteableSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetManufactory	�Ѿ������SysNetManufactory
	virtual void afterAdd(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetManufactory	��ˢ�µ�CSysNetManufactory
	///@param	pNewSysNetManufactory	�µ�ֵ
	virtual void beforeUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pNewSysNetManufactory)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetManufactory	��ˢ�µ�CSysNetManufactory
	virtual void afterUpdate(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetManufactory	Ҫɾ����CSysNetManufactory
	virtual void beforeRemove(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetManufactoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryCommitTrigger��ȷ���豸����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryCommitTrigger
{
public:
	///���췽��
	CSysNetManufactoryCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetManufactoryCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetManufactoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetManufactory	�Ѿ������SysNetManufactory
	virtual void commitAdd(CSysNetManufactory *pSysNetManufactory)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetManufactory	��ˢ�µ�CSysNetManufactory
	///@param	poldSysNetManufactory	ԭ����ֵ
	virtual void commitUpdate(CSysNetManufactory *pSysNetManufactory, CWriteableSysNetManufactory *pOldSysNetManufactory)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetManufactory	�Ѿ�ɾ����CSysNetManufactory
	virtual void commitRemove(CWriteableSysNetManufactory *pSysNetManufactory)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetManufactoryFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetManufactoryIterator��һ�����豸���̵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetManufactoryIterator
{
public:
	///���췽��
	CSysNetManufactoryIterator(void)
	{
	}

	///���췽��
	CSysNetManufactoryIterator(CSysNetManufactoryFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetManufactoryIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetManufactory
	///@return	��һ����������CSysNetManufactory������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetManufactory *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetManufactoryFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetManufactory ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetManufactory * pSysNetManufactory,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetManufactoryFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetCommunity��һ���洢�豸��ͬ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetCommunity
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
		if (! ID.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! COMMUNITY.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetCommunity *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///IP��ַ
	CIPAddressType IPADDR;
	///��ͬ����
	CTypeObjectIDType COMMUNITY;
	
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

typedef const CWriteableSysNetCommunity CSysNetCommunity;

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityActionTrigger�ǲ����豸��ͬ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityActionTrigger
{
public:
	///���췽��
	CSysNetCommunityActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetCommunityActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetCommunityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetCommunity	Ҫ�����SysNetCommunity
	virtual void beforeAdd(CWriteableSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetCommunity	�Ѿ������SysNetCommunity
	virtual void afterAdd(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetCommunity	��ˢ�µ�CSysNetCommunity
	///@param	pNewSysNetCommunity	�µ�ֵ
	virtual void beforeUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pNewSysNetCommunity)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetCommunity	��ˢ�µ�CSysNetCommunity
	virtual void afterUpdate(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetCommunity	Ҫɾ����CSysNetCommunity
	virtual void beforeRemove(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetCommunityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityCommitTrigger��ȷ���豸��ͬ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityCommitTrigger
{
public:
	///���췽��
	CSysNetCommunityCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetCommunityCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetCommunityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetCommunity	�Ѿ������SysNetCommunity
	virtual void commitAdd(CSysNetCommunity *pSysNetCommunity)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetCommunity	��ˢ�µ�CSysNetCommunity
	///@param	poldSysNetCommunity	ԭ����ֵ
	virtual void commitUpdate(CSysNetCommunity *pSysNetCommunity, CWriteableSysNetCommunity *pOldSysNetCommunity)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetCommunity	�Ѿ�ɾ����CSysNetCommunity
	virtual void commitRemove(CWriteableSysNetCommunity *pSysNetCommunity)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetCommunityFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetCommunityIterator��һ�����豸��ͬ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetCommunityIterator
{
public:
	///���췽��
	CSysNetCommunityIterator(void)
	{
	}

	///���췽��
	CSysNetCommunityIterator(CSysNetCommunityFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetCommunityIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetCommunity
	///@return	��һ����������CSysNetCommunity������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetCommunity *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetCommunityFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetCommunity ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetCommunity * pSysNetCommunity,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetCommunityFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPortType��һ���洢�˿����͵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPortType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! Description.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPortType *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///������
	CTypeObjectIDType CName;
	///Ӣ����
	CTypeObjectIDType EName;
	///����
	CTypeObjectIDType Description;
	
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

typedef const CWriteableSysNetPortType CSysNetPortType;

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeActionTrigger�ǲ����˿�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeActionTrigger
{
public:
	///���췽��
	CSysNetPortTypeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPortTypeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPortTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetPortType	Ҫ�����SysNetPortType
	virtual void beforeAdd(CWriteableSysNetPortType *pSysNetPortType)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetPortType	�Ѿ������SysNetPortType
	virtual void afterAdd(CSysNetPortType *pSysNetPortType)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetPortType	��ˢ�µ�CSysNetPortType
	///@param	pNewSysNetPortType	�µ�ֵ
	virtual void beforeUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pNewSysNetPortType)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetPortType	��ˢ�µ�CSysNetPortType
	virtual void afterUpdate(CSysNetPortType *pSysNetPortType)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetPortType	Ҫɾ����CSysNetPortType
	virtual void beforeRemove(CSysNetPortType *pSysNetPortType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPortTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeCommitTrigger��ȷ�϶˿�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeCommitTrigger
{
public:
	///���췽��
	CSysNetPortTypeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPortTypeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPortTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetPortType	�Ѿ������SysNetPortType
	virtual void commitAdd(CSysNetPortType *pSysNetPortType)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetPortType	��ˢ�µ�CSysNetPortType
	///@param	poldSysNetPortType	ԭ����ֵ
	virtual void commitUpdate(CSysNetPortType *pSysNetPortType, CWriteableSysNetPortType *pOldSysNetPortType)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetPortType	�Ѿ�ɾ����CSysNetPortType
	virtual void commitRemove(CWriteableSysNetPortType *pSysNetPortType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPortTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPortTypeIterator��һ���Զ˿����͵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPortTypeIterator
{
public:
	///���췽��
	CSysNetPortTypeIterator(void)
	{
	}

	///���췽��
	CSysNetPortTypeIterator(CSysNetPortTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPortTypeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetPortType
	///@return	��һ����������CSysNetPortType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPortType *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetPortTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPortType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPortType * pSysNetPortType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetPortTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetInterface��һ���洢�˿ڵĶ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetInterface
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! IfType.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! IpAddress.isValid())
			return 0;
		if (! IpMask.isValid())
			return 0;
		if (! IfStatus.isValid())
			return 0;
		if (! MAC.isValid())
			return 0;
		if (! DeviceID.isValid())
			return 0;
		if (! DeviceObjectID.isValid())
			return 0;
		if (! DeviceIndex.isValid())
			return 0;
		if (! isPolling.isValid())
			return 0;
		if (! Description.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetInterface *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��ض���
	CNetObjectIDType ObjectID;
	///��ض�������
	CVolumeType MonitorType_ID;
	///�˿�����
	CVolumeType IfType;
	///�˿���
	CTypeObjectIDType EName;
	///IP��ַ
	CIPAddressType IpAddress;
	///����
	CIPAddressType IpMask;
	///�˿�״̬
	CVolumeType IfStatus;
	///�����ַ
	CTypeObjectIDType MAC;
	///�����豸ID
	CVolumeType DeviceID;
	///�����豸ObjectID
	CNetObjectIDType DeviceObjectID;
	///�����豸�˿�����
	CTypeObjectNameType DeviceIndex;
	///�Ƿ���ѯ
	CVolumeType isPolling;
	///����
	CTypeObjectIDType Description;
	
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

typedef const CWriteableSysNetInterface CSysNetInterface;

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceActionTrigger�ǲ����˿�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceActionTrigger
{
public:
	///���췽��
	CSysNetInterfaceActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetInterfaceActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetInterfaceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetInterface	Ҫ�����SysNetInterface
	virtual void beforeAdd(CWriteableSysNetInterface *pSysNetInterface)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetInterface	�Ѿ������SysNetInterface
	virtual void afterAdd(CSysNetInterface *pSysNetInterface)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetInterface	��ˢ�µ�CSysNetInterface
	///@param	pNewSysNetInterface	�µ�ֵ
	virtual void beforeUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pNewSysNetInterface)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetInterface	��ˢ�µ�CSysNetInterface
	virtual void afterUpdate(CSysNetInterface *pSysNetInterface)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetInterface	Ҫɾ����CSysNetInterface
	virtual void beforeRemove(CSysNetInterface *pSysNetInterface)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetInterfaceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceCommitTrigger��ȷ�϶˿�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceCommitTrigger
{
public:
	///���췽��
	CSysNetInterfaceCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetInterfaceCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetInterfaceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetInterface	�Ѿ������SysNetInterface
	virtual void commitAdd(CSysNetInterface *pSysNetInterface)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetInterface	��ˢ�µ�CSysNetInterface
	///@param	poldSysNetInterface	ԭ����ֵ
	virtual void commitUpdate(CSysNetInterface *pSysNetInterface, CWriteableSysNetInterface *pOldSysNetInterface)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetInterface	�Ѿ�ɾ����CSysNetInterface
	virtual void commitRemove(CWriteableSysNetInterface *pSysNetInterface)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetInterfaceFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetInterfaceIterator��һ���Զ˿ڵ�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetInterfaceIterator
{
public:
	///���췽��
	CSysNetInterfaceIterator(void)
	{
	}

	///���췽��
	CSysNetInterfaceIterator(CSysNetInterfaceFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetInterfaceIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetInterface
	///@return	��һ����������CSysNetInterface������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetInterface *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetInterfaceFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetInterface ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetInterface * pSysNetInterface,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetInterfaceFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetGeneralOID��һ���洢ͨ��OID�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetGeneralOID
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! OID.isValid())
			return 0;
		if (! Unit.isValid())
			return 0;
		if (! isTheTable.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetGeneralOID *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///OID������
	CTypeObjectIDType CName;
	///OIDӢ����
	CTypeObjectIDType EName;
	///OID
	CTypeObjectIDType OID;
	///��λ
	CTypeObjectIDType Unit;
	///�Ƿ������־
	CVolumeType isTheTable;
	
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

typedef const CWriteableSysNetGeneralOID CSysNetGeneralOID;

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDActionTrigger�ǲ���ͨ��OIDʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDActionTrigger
{
public:
	///���췽��
	CSysNetGeneralOIDActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetGeneralOIDActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetGeneralOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetGeneralOID	Ҫ�����SysNetGeneralOID
	virtual void beforeAdd(CWriteableSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetGeneralOID	�Ѿ������SysNetGeneralOID
	virtual void afterAdd(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetGeneralOID	��ˢ�µ�CSysNetGeneralOID
	///@param	pNewSysNetGeneralOID	�µ�ֵ
	virtual void beforeUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pNewSysNetGeneralOID)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetGeneralOID	��ˢ�µ�CSysNetGeneralOID
	virtual void afterUpdate(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetGeneralOID	Ҫɾ����CSysNetGeneralOID
	virtual void beforeRemove(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetGeneralOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDCommitTrigger��ȷ��ͨ��OIDʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDCommitTrigger
{
public:
	///���췽��
	CSysNetGeneralOIDCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetGeneralOIDCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetGeneralOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetGeneralOID	�Ѿ������SysNetGeneralOID
	virtual void commitAdd(CSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetGeneralOID	��ˢ�µ�CSysNetGeneralOID
	///@param	poldSysNetGeneralOID	ԭ����ֵ
	virtual void commitUpdate(CSysNetGeneralOID *pSysNetGeneralOID, CWriteableSysNetGeneralOID *pOldSysNetGeneralOID)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetGeneralOID	�Ѿ�ɾ����CSysNetGeneralOID
	virtual void commitRemove(CWriteableSysNetGeneralOID *pSysNetGeneralOID)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetGeneralOIDFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetGeneralOIDIterator��һ����ͨ��OID��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetGeneralOIDIterator
{
public:
	///���췽��
	CSysNetGeneralOIDIterator(void)
	{
	}

	///���췽��
	CSysNetGeneralOIDIterator(CSysNetGeneralOIDFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetGeneralOIDIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetGeneralOID
	///@return	��һ����������CSysNetGeneralOID������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetGeneralOID *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetGeneralOIDFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetGeneralOID ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetGeneralOID * pSysNetGeneralOID,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetGeneralOIDFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorType��һ���洢��ض������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorType *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///OID������
	CTypeObjectIDType CName;
	///OIDӢ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetMonitorType CSysNetMonitorType;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeActionTrigger�ǲ�����ض������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeActionTrigger
{
public:
	///���췽��
	CSysNetMonitorTypeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTypeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorType	Ҫ�����SysNetMonitorType
	virtual void beforeAdd(CWriteableSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorType	�Ѿ������SysNetMonitorType
	virtual void afterAdd(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorType	��ˢ�µ�CSysNetMonitorType
	///@param	pNewSysNetMonitorType	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pNewSysNetMonitorType)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorType	��ˢ�µ�CSysNetMonitorType
	virtual void afterUpdate(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorType	Ҫɾ����CSysNetMonitorType
	virtual void beforeRemove(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeCommitTrigger��ȷ�ϼ�ض������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorTypeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTypeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorType	�Ѿ������SysNetMonitorType
	virtual void commitAdd(CSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorType	��ˢ�µ�CSysNetMonitorType
	///@param	poldSysNetMonitorType	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorType *pSysNetMonitorType, CWriteableSysNetMonitorType *pOldSysNetMonitorType)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorType	�Ѿ�ɾ����CSysNetMonitorType
	virtual void commitRemove(CWriteableSysNetMonitorType *pSysNetMonitorType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTypeIterator��һ���Լ�ض�������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTypeIterator
{
public:
	///���췽��
	CSysNetMonitorTypeIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorTypeIterator(CSysNetMonitorTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTypeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorType
	///@return	��һ����������CSysNetMonitorType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorType *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorType * pSysNetMonitorType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorAttrScope��һ���洢ָ��ͳ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorAttrScope
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorAttrScope *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///ָ��������
	CNetAttrTypeType CName;
	///ָ��Ӣ����
	CNetAttrTypeType EName;
	///ע��
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorAttrScope CSysNetMonitorAttrScope;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeActionTrigger�ǲ���ָ��ͳ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeActionTrigger
{
public:
	///���췽��
	CSysNetMonitorAttrScopeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorAttrScopeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorAttrScopeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorAttrScope	Ҫ�����SysNetMonitorAttrScope
	virtual void beforeAdd(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorAttrScope	�Ѿ������SysNetMonitorAttrScope
	virtual void afterAdd(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorAttrScope	��ˢ�µ�CSysNetMonitorAttrScope
	///@param	pNewSysNetMonitorAttrScope	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pNewSysNetMonitorAttrScope)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorAttrScope	��ˢ�µ�CSysNetMonitorAttrScope
	virtual void afterUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorAttrScope	Ҫɾ����CSysNetMonitorAttrScope
	virtual void beforeRemove(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorAttrScopeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeCommitTrigger��ȷ��ָ��ͳ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorAttrScopeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorAttrScopeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorAttrScopeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorAttrScope	�Ѿ������SysNetMonitorAttrScope
	virtual void commitAdd(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorAttrScope	��ˢ�µ�CSysNetMonitorAttrScope
	///@param	poldSysNetMonitorAttrScope	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorAttrScope *pSysNetMonitorAttrScope, CWriteableSysNetMonitorAttrScope *pOldSysNetMonitorAttrScope)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorAttrScope	�Ѿ�ɾ����CSysNetMonitorAttrScope
	virtual void commitRemove(CWriteableSysNetMonitorAttrScope *pSysNetMonitorAttrScope)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorAttrScopeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrScopeIterator��һ����ָ��ͳ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrScopeIterator
{
public:
	///���췽��
	CSysNetMonitorAttrScopeIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorAttrScopeIterator(CSysNetMonitorAttrScopeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorAttrScopeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorAttrScope
	///@return	��һ����������CSysNetMonitorAttrScope������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrScope *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorAttrScopeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrScope ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrScope * pSysNetMonitorAttrScope,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorAttrScopeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorAttrType��һ���洢���ָ���Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorAttrType
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
		if (! ID.isValid())
			return 0;
		if (! MANUFACTORY_ID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! AttrType_ID.isValid())
			return 0;
		if (! MANUFACTORY.isValid())
			return 0;
		if (! MonitorType.isValid())
			return 0;
		if (! AttrType.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorAttrType *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��������
	CVolumeType MANUFACTORY_ID;
	///�豸���
	CVolumeType MonitorType_ID;
	///������ָ��ID
	CVolumeType AttrType_ID;
	///��������
	CTypeObjectIDType MANUFACTORY;
	///�豸���
	CTypeObjectIDType MonitorType;
	///������ָ��
	CNetAttrTypeType AttrType;
	
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

typedef const CWriteableSysNetMonitorAttrType CSysNetMonitorAttrType;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeActionTrigger�ǲ������ָ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeActionTrigger
{
public:
	///���췽��
	CSysNetMonitorAttrTypeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorAttrTypeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorAttrTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorAttrType	Ҫ�����SysNetMonitorAttrType
	virtual void beforeAdd(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorAttrType	�Ѿ������SysNetMonitorAttrType
	virtual void afterAdd(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorAttrType	��ˢ�µ�CSysNetMonitorAttrType
	///@param	pNewSysNetMonitorAttrType	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pNewSysNetMonitorAttrType)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorAttrType	��ˢ�µ�CSysNetMonitorAttrType
	virtual void afterUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorAttrType	Ҫɾ����CSysNetMonitorAttrType
	virtual void beforeRemove(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorAttrTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeCommitTrigger��ȷ�ϼ��ָ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorAttrTypeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorAttrTypeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorAttrTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorAttrType	�Ѿ������SysNetMonitorAttrType
	virtual void commitAdd(CSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorAttrType	��ˢ�µ�CSysNetMonitorAttrType
	///@param	poldSysNetMonitorAttrType	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorAttrType *pSysNetMonitorAttrType, CWriteableSysNetMonitorAttrType *pOldSysNetMonitorAttrType)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorAttrType	�Ѿ�ɾ����CSysNetMonitorAttrType
	virtual void commitRemove(CWriteableSysNetMonitorAttrType *pSysNetMonitorAttrType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorAttrTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorAttrTypeIterator��һ���Լ��ָ����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorAttrTypeIterator
{
public:
	///���췽��
	CSysNetMonitorAttrTypeIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorAttrTypeIterator(CSysNetMonitorAttrTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorAttrTypeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorAttrType
	///@return	��һ����������CSysNetMonitorAttrType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorAttrType *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorAttrTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorAttrType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorAttrType * pSysNetMonitorAttrType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorAttrTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorCommandType��һ���洢���ָ���Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorCommandType
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory_ID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! DeviceModle_ID.isValid())
			return 0;
		if (! ActionGroup_ID.isValid())
			return 0;
		if (! Manufactory.isValid())
			return 0;
		if (! MonitorType.isValid())
			return 0;
		if (! DeviceModle.isValid())
			return 0;
		if (! ActionGroup.isValid())
			return 0;
		if (! Command.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorCommandType *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��������ID
	CVolumeType Manufactory_ID;
	///�豸���ID
	CVolumeType MonitorType_ID;
	///�豸�ͺ�ID
	CVolumeType DeviceModle_ID;
	///������ID
	CVolumeType ActionGroup_ID;
	///��������
	CTypeObjectIDType Manufactory;
	///�豸���
	CTypeObjectIDType MonitorType;
	///�豸�ͺ�
	CTypeObjectIDType DeviceModle;
	///������
	CTypeObjectIDType ActionGroup;
	///ָ����
	CNetAttrTypeType Command;
	
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

typedef const CWriteableSysNetMonitorCommandType CSysNetMonitorCommandType;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeActionTrigger�ǲ������ָ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeActionTrigger
{
public:
	///���췽��
	CSysNetMonitorCommandTypeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorCommandTypeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorCommandTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorCommandType	Ҫ�����SysNetMonitorCommandType
	virtual void beforeAdd(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorCommandType	�Ѿ������SysNetMonitorCommandType
	virtual void afterAdd(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorCommandType	��ˢ�µ�CSysNetMonitorCommandType
	///@param	pNewSysNetMonitorCommandType	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pNewSysNetMonitorCommandType)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorCommandType	��ˢ�µ�CSysNetMonitorCommandType
	virtual void afterUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorCommandType	Ҫɾ����CSysNetMonitorCommandType
	virtual void beforeRemove(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorCommandTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeCommitTrigger��ȷ�ϼ��ָ���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorCommandTypeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorCommandTypeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorCommandTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorCommandType	�Ѿ������SysNetMonitorCommandType
	virtual void commitAdd(CSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorCommandType	��ˢ�µ�CSysNetMonitorCommandType
	///@param	poldSysNetMonitorCommandType	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorCommandType *pSysNetMonitorCommandType, CWriteableSysNetMonitorCommandType *pOldSysNetMonitorCommandType)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorCommandType	�Ѿ�ɾ����CSysNetMonitorCommandType
	virtual void commitRemove(CWriteableSysNetMonitorCommandType *pSysNetMonitorCommandType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorCommandTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorCommandTypeIterator��һ���Լ��ָ����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorCommandTypeIterator
{
public:
	///���췽��
	CSysNetMonitorCommandTypeIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorCommandTypeIterator(CSysNetMonitorCommandTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorCommandTypeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorCommandType
	///@return	��һ����������CSysNetMonitorCommandType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorCommandType *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorCommandTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorCommandType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorCommandType * pSysNetMonitorCommandType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorCommandTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorActionGroup��һ���洢�������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorActionGroup
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! ActionType.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorActionGroup *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///������������
	CTypeObjectIDType CName;
	///������Ӣ����
	CTypeObjectIDType EName;
	///����������
	CVolumeType ActionType;
	///ע��
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorActionGroup CSysNetMonitorActionGroup;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupActionTrigger�ǲ����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupActionTrigger
{
public:
	///���췽��
	CSysNetMonitorActionGroupActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorActionGroupActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorActionGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorActionGroup	Ҫ�����SysNetMonitorActionGroup
	virtual void beforeAdd(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorActionGroup	�Ѿ������SysNetMonitorActionGroup
	virtual void afterAdd(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorActionGroup	��ˢ�µ�CSysNetMonitorActionGroup
	///@param	pNewSysNetMonitorActionGroup	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pNewSysNetMonitorActionGroup)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorActionGroup	��ˢ�µ�CSysNetMonitorActionGroup
	virtual void afterUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorActionGroup	Ҫɾ����CSysNetMonitorActionGroup
	virtual void beforeRemove(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorActionGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupCommitTrigger��ȷ�϶������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorActionGroupCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorActionGroupCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorActionGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorActionGroup	�Ѿ������SysNetMonitorActionGroup
	virtual void commitAdd(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorActionGroup	��ˢ�µ�CSysNetMonitorActionGroup
	///@param	poldSysNetMonitorActionGroup	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorActionGroup *pSysNetMonitorActionGroup, CWriteableSysNetMonitorActionGroup *pOldSysNetMonitorActionGroup)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorActionGroup	�Ѿ�ɾ����CSysNetMonitorActionGroup
	virtual void commitRemove(CWriteableSysNetMonitorActionGroup *pSysNetMonitorActionGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorActionGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionGroupIterator��һ���Զ�������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionGroupIterator
{
public:
	///���췽��
	CSysNetMonitorActionGroupIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorActionGroupIterator(CSysNetMonitorActionGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorActionGroupIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorActionGroup
	///@return	��һ����������CSysNetMonitorActionGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionGroup *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorActionGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionGroup * pSysNetMonitorActionGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorActionGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorDeviceGroup��һ���洢�豸�������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorDeviceGroup
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! Condition.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorDeviceGroup *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�豸������������
	CTypeObjectIDType CName;
	///�豸������Ӣ����
	CTypeObjectIDType EName;
	///�豸��������
	CNetString512Type Condition;
	///ע��
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorDeviceGroup CSysNetMonitorDeviceGroup;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupActionTrigger�ǲ����豸�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupActionTrigger
{
public:
	///���췽��
	CSysNetMonitorDeviceGroupActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorDeviceGroupActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorDeviceGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorDeviceGroup	Ҫ�����SysNetMonitorDeviceGroup
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorDeviceGroup	�Ѿ������SysNetMonitorDeviceGroup
	virtual void afterAdd(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorDeviceGroup	��ˢ�µ�CSysNetMonitorDeviceGroup
	///@param	pNewSysNetMonitorDeviceGroup	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pNewSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorDeviceGroup	��ˢ�µ�CSysNetMonitorDeviceGroup
	virtual void afterUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorDeviceGroup	Ҫɾ����CSysNetMonitorDeviceGroup
	virtual void beforeRemove(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorDeviceGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupCommitTrigger��ȷ���豸�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorDeviceGroupCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorDeviceGroupCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorDeviceGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorDeviceGroup	�Ѿ������SysNetMonitorDeviceGroup
	virtual void commitAdd(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorDeviceGroup	��ˢ�µ�CSysNetMonitorDeviceGroup
	///@param	poldSysNetMonitorDeviceGroup	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup, CWriteableSysNetMonitorDeviceGroup *pOldSysNetMonitorDeviceGroup)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorDeviceGroup	�Ѿ�ɾ����CSysNetMonitorDeviceGroup
	virtual void commitRemove(CWriteableSysNetMonitorDeviceGroup *pSysNetMonitorDeviceGroup)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorDeviceGroupFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceGroupIterator��һ�����豸��������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceGroupIterator
{
public:
	///���췽��
	CSysNetMonitorDeviceGroupIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorDeviceGroupIterator(CSysNetMonitorDeviceGroupFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorDeviceGroupIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorDeviceGroup
	///@return	��һ����������CSysNetMonitorDeviceGroup������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceGroup *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorDeviceGroupFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceGroup ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceGroup * pSysNetMonitorDeviceGroup,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorDeviceGroupFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskInfo��һ���洢������Ϣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskInfo
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! DeviceGroup_ID.isValid())
			return 0;
		if (! ManagerGroup_ID.isValid())
			return 0;
		if (! TimePolicy_ID.isValid())
			return 0;
		if (! TaskPriority_ID.isValid())
			return 0;
		if (! OutputPolicy_ID.isValid())
			return 0;
		if (! ActionGroup_ID.isValid())
			return 0;
		if (! EventExprStr.isValid())
			return 0;
		if (! DeviceGroup.isValid())
			return 0;
		if (! ManagerGroup.isValid())
			return 0;
		if (! TimePolicy.isValid())
			return 0;
		if (! TaskPriority.isValid())
			return 0;
		if (! OutputPolicy.isValid())
			return 0;
		if (! ActionGroup.isValid())
			return 0;
		if (! ValidFlag.isValid())
			return 0;
		if (! TaskStatus.isValid())
			return 0;
		if (! Comments.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///����������
	CTypeObjectIDType CName;
	///����Ӣ����
	CTypeObjectIDType EName;
	///�豸������ID
	CVolumeType DeviceGroup_ID;
	///������Ա������ID
	CVolumeType ManagerGroup_ID;
	///����ʱ�����ID
	CVolumeType TimePolicy_ID;
	///�������ȼ�ID
	CVolumeType TaskPriority_ID;
	///����������ID
	CVolumeType OutputPolicy_ID;
	///��������ID
	CVolumeType ActionGroup_ID;
	///������ʽID���ϴ�
	CGeneralResultType EventExprStr;
	///�豸������
	CTypeObjectIDType DeviceGroup;
	///������Ա������
	CTypeObjectIDType ManagerGroup;
	///����ʱ�����
	CTypeObjectIDType TimePolicy;
	///�������ȼ�
	CTypeObjectIDType TaskPriority;
	///����������
	CTypeObjectIDType OutputPolicy;
	///��������
	CTypeObjectIDType ActionGroup;
	///������Ч�Ա�ʶ
	CVolumeType ValidFlag;
	///����״̬��ʶ
	CVolumeType TaskStatus;
	///��������
	CNetAttrTypeType Comments;
	
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

typedef const CWriteableSysNetMonitorTaskInfo CSysNetMonitorTaskInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoActionTrigger�ǲ���������Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoActionTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorTaskInfo	Ҫ�����SysNetMonitorTaskInfo
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorTaskInfo	�Ѿ������SysNetMonitorTaskInfo
	virtual void afterAdd(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorTaskInfo	��ˢ�µ�CSysNetMonitorTaskInfo
	///@param	pNewSysNetMonitorTaskInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pNewSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorTaskInfo	��ˢ�µ�CSysNetMonitorTaskInfo
	virtual void afterUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskInfo	Ҫɾ����CSysNetMonitorTaskInfo
	virtual void beforeRemove(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoCommitTrigger��ȷ��������Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorTaskInfo	�Ѿ������SysNetMonitorTaskInfo
	virtual void commitAdd(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorTaskInfo	��ˢ�µ�CSysNetMonitorTaskInfo
	///@param	poldSysNetMonitorTaskInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo, CWriteableSysNetMonitorTaskInfo *pOldSysNetMonitorTaskInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorTaskInfo	�Ѿ�ɾ����CSysNetMonitorTaskInfo
	virtual void commitRemove(CWriteableSysNetMonitorTaskInfo *pSysNetMonitorTaskInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInfoIterator��һ����������Ϣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInfoIterator
{
public:
	///���췽��
	CSysNetMonitorTaskInfoIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorTaskInfoIterator(CSysNetMonitorTaskInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorTaskInfo
	///@return	��һ����������CSysNetMonitorTaskInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInfo * pSysNetMonitorTaskInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorTaskInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskObjectSet��һ���洢������󼯵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskObjectSet
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
		if (! ID.isValid())
			return 0;
		if (! DeviceGroup_ID.isValid())
			return 0;
		if (! Device_ID.isValid())
			return 0;
		if (! DataCenter.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskObjectSet *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�豸������ID
	CVolumeType DeviceGroup_ID;
	///�豸ID
	CVolumeType Device_ID;
	///DataCenter
	CDataCenterFlagType DataCenter;
	
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

typedef const CWriteableSysNetMonitorTaskObjectSet CSysNetMonitorTaskObjectSet;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetActionTrigger�ǲ����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetActionTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskObjectSetActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskObjectSetActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskObjectSetFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorTaskObjectSet	Ҫ�����SysNetMonitorTaskObjectSet
	virtual void beforeAdd(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorTaskObjectSet	�Ѿ������SysNetMonitorTaskObjectSet
	virtual void afterAdd(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorTaskObjectSet	��ˢ�µ�CSysNetMonitorTaskObjectSet
	///@param	pNewSysNetMonitorTaskObjectSet	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pNewSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorTaskObjectSet	��ˢ�µ�CSysNetMonitorTaskObjectSet
	virtual void afterUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskObjectSet	Ҫɾ����CSysNetMonitorTaskObjectSet
	virtual void beforeRemove(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskObjectSetFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetCommitTrigger��ȷ���������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskObjectSetCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskObjectSetCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskObjectSetFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorTaskObjectSet	�Ѿ������SysNetMonitorTaskObjectSet
	virtual void commitAdd(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorTaskObjectSet	��ˢ�µ�CSysNetMonitorTaskObjectSet
	///@param	poldSysNetMonitorTaskObjectSet	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet, CWriteableSysNetMonitorTaskObjectSet *pOldSysNetMonitorTaskObjectSet)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorTaskObjectSet	�Ѿ�ɾ����CSysNetMonitorTaskObjectSet
	virtual void commitRemove(CWriteableSysNetMonitorTaskObjectSet *pSysNetMonitorTaskObjectSet)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskObjectSetFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskObjectSetIterator��һ����������󼯵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskObjectSetIterator
{
public:
	///���췽��
	CSysNetMonitorTaskObjectSetIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorTaskObjectSetIterator(CSysNetMonitorTaskObjectSetFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskObjectSetIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorTaskObjectSet
	///@return	��һ����������CSysNetMonitorTaskObjectSet������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskObjectSet *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskObjectSetFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskObjectSet ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskObjectSet * pSysNetMonitorTaskObjectSet,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorTaskObjectSetFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskResult��һ���洢��������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskResult
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
		if (! ObjectID.isValid())
			return 0;
		if (! Task_ID.isValid())
			return 0;
		if (! OperateTime.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! InstructChain.isValid())
			return 0;
		if (! ResultChain.isValid())
			return 0;
		if (! Flag.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskResult *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///�����ض���ID
	CNetObjectIDType ObjectID;
	///����ID
	CVolumeType Task_ID;
	///ִ�д���
	CVolumeType OperateTime;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///ָ�
	CNetString256Type InstructChain;
	///�����
	CNetString1KType ResultChain;
	///����ִ�б�ʶ
	CVolumeType Flag;
	
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

typedef const CWriteableSysNetMonitorTaskResult CSysNetMonitorTaskResult;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultActionTrigger�ǲ�����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultActionTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskResultActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskResultActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskResultFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorTaskResult	Ҫ�����SysNetMonitorTaskResult
	virtual void beforeAdd(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorTaskResult	�Ѿ������SysNetMonitorTaskResult
	virtual void afterAdd(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorTaskResult	��ˢ�µ�CSysNetMonitorTaskResult
	///@param	pNewSysNetMonitorTaskResult	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pNewSysNetMonitorTaskResult)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorTaskResult	��ˢ�µ�CSysNetMonitorTaskResult
	virtual void afterUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskResult	Ҫɾ����CSysNetMonitorTaskResult
	virtual void beforeRemove(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskResultFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultCommitTrigger��ȷ����������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskResultCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskResultCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskResultFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorTaskResult	�Ѿ������SysNetMonitorTaskResult
	virtual void commitAdd(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorTaskResult	��ˢ�µ�CSysNetMonitorTaskResult
	///@param	poldSysNetMonitorTaskResult	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorTaskResult *pSysNetMonitorTaskResult, CWriteableSysNetMonitorTaskResult *pOldSysNetMonitorTaskResult)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorTaskResult	�Ѿ�ɾ����CSysNetMonitorTaskResult
	virtual void commitRemove(CWriteableSysNetMonitorTaskResult *pSysNetMonitorTaskResult)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskResultFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskResultIterator��һ�������������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskResultIterator
{
public:
	///���췽��
	CSysNetMonitorTaskResultIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorTaskResultIterator(CSysNetMonitorTaskResultFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskResultIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorTaskResult
	///@return	��һ����������CSysNetMonitorTaskResult������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskResult *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskResultFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskResult ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskResult * pSysNetMonitorTaskResult,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorTaskResultFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPartyLinkInfo��һ���洢��Ա��·��Ϣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPartyLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! MEMBER_NO.isValid())
			return 0;
		if (! MEMBER_NAME.isValid())
			return 0;
		if (! REMOTE_ADDR.isValid())
			return 0;
		if (! LOCAL_ADDR.isValid())
			return 0;
		if (! ADDRESS.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! CONTACT.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! EMAIL.isValid())
			return 0;
		if (! FAX.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! IN_MODE.isValid())
			return 0;
		if (! IP_WAN.isValid())
			return 0;
		if (! IP_LAN.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! INTERFACE_DATE.isValid())
			return 0;
		if (! SOFTWARE.isValid())
			return 0;
		if (! FEE_TYPE.isValid())
			return 0;
		if (! SERVICEPROVIDER.isValid())
			return 0;
		if (! IF_ZIYING.isValid())
			return 0;
		if (! IF_TUOGUAN.isValid())
			return 0;
		if (! HASOTHER.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! PRO.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPartyLinkInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��Ա��
	CCfgNameType MEMBER_NO;
	///��Ա����
	CTypeObjectIDType MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType REMOTE_ADDR;
	///�����������
	CTypeObjectIDType LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType ADDRESS;
	///��·״̬
	CCfgNameType LINE_STATUS;
	///��ϵ��
	CCfgNameType CONTACT;
	///��ϵ�绰
	CTypeObjectIDType TELEPHONE;
	///�ֻ���
	CTypeObjectIDType MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType EMAIL;
	///����
	CTypeObjectIDType FAX;
	///����ʡ��
	CCfgNameType PROVINCE;
	///��·���
	CTypeObjectIDType DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType IN_MODE;
	///����IP����
	CTypeObjectIDType IP_WAN;
	///����IP����
	CTypeObjectIDType IP_LAN;
	///·��������IP
	CTypeObjectIDType IPADDR;
	///·�����˿ں�
	CTypeObjectIDType Interface;
	///�ӿڿ�ͨ����
	CCfgNameType INTERFACE_DATE;
	///�������
	CCfgNameType SOFTWARE;
	///��������
	CCfgNameType FEE_TYPE;
	///��Ӫ��
	CCfgNameType SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType IF_TUOGUAN;
	///����������·
	CCfgNameType HASOTHER;
	///ϯλ��
	CGeneralResultType SEAT_NO;
	///��ע
	CPolicyStringTypeType PRO;
	
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

typedef const CWriteableSysNetPartyLinkInfo CSysNetPartyLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoActionTrigger�ǲ�����Ա��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoActionTrigger
{
public:
	///���췽��
	CSysNetPartyLinkInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPartyLinkInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetPartyLinkInfo	Ҫ�����SysNetPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetPartyLinkInfo	�Ѿ������SysNetPartyLinkInfo
	virtual void afterAdd(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetPartyLinkInfo	��ˢ�µ�CSysNetPartyLinkInfo
	///@param	pNewSysNetPartyLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pNewSysNetPartyLinkInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetPartyLinkInfo	��ˢ�µ�CSysNetPartyLinkInfo
	virtual void afterUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetPartyLinkInfo	Ҫɾ����CSysNetPartyLinkInfo
	virtual void beforeRemove(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoCommitTrigger��ȷ�ϻ�Ա��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoCommitTrigger
{
public:
	///���췽��
	CSysNetPartyLinkInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPartyLinkInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetPartyLinkInfo	�Ѿ������SysNetPartyLinkInfo
	virtual void commitAdd(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetPartyLinkInfo	��ˢ�µ�CSysNetPartyLinkInfo
	///@param	poldSysNetPartyLinkInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetPartyLinkInfo *pSysNetPartyLinkInfo, CWriteableSysNetPartyLinkInfo *pOldSysNetPartyLinkInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetPartyLinkInfo	�Ѿ�ɾ����CSysNetPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetPartyLinkInfo *pSysNetPartyLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkInfoIterator��һ���Ի�Ա��·��Ϣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkInfoIterator
{
public:
	///���췽��
	CSysNetPartyLinkInfoIterator(void)
	{
	}

	///���췽��
	CSysNetPartyLinkInfoIterator(CSysNetPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartyLinkInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetPartyLinkInfo
	///@return	��һ����������CSysNetPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetPartyLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkInfo * pSysNetPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetPartyLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDelPartyLinkInfo��һ���洢��Ա��·��Ϣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDelPartyLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! MEMBER_NO.isValid())
			return 0;
		if (! MEMBER_NAME.isValid())
			return 0;
		if (! REMOTE_ADDR.isValid())
			return 0;
		if (! LOCAL_ADDR.isValid())
			return 0;
		if (! ADDRESS.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! CONTACT.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! EMAIL.isValid())
			return 0;
		if (! FAX.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! IN_MODE.isValid())
			return 0;
		if (! IP_WAN.isValid())
			return 0;
		if (! IP_LAN.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! INTERFACE_DATE.isValid())
			return 0;
		if (! SOFTWARE.isValid())
			return 0;
		if (! FEE_TYPE.isValid())
			return 0;
		if (! SERVICEPROVIDER.isValid())
			return 0;
		if (! IF_ZIYING.isValid())
			return 0;
		if (! IF_TUOGUAN.isValid())
			return 0;
		if (! HASOTHER.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! PRO.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDelPartyLinkInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��Ա��
	CCfgNameType MEMBER_NO;
	///��Ա����
	CTypeObjectIDType MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType REMOTE_ADDR;
	///�����������
	CTypeObjectIDType LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType ADDRESS;
	///��·״̬
	CCfgNameType LINE_STATUS;
	///��ϵ��
	CCfgNameType CONTACT;
	///��ϵ�绰
	CTypeObjectIDType TELEPHONE;
	///�ֻ���
	CTypeObjectIDType MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType EMAIL;
	///����
	CTypeObjectIDType FAX;
	///����ʡ��
	CCfgNameType PROVINCE;
	///��·���
	CTypeObjectIDType DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType IN_MODE;
	///����IP����
	CTypeObjectIDType IP_WAN;
	///����IP����
	CTypeObjectIDType IP_LAN;
	///·��������IP
	CTypeObjectIDType IPADDR;
	///·�����˿ں�
	CTypeObjectIDType Interface;
	///�ӿڿ�ͨ����
	CCfgNameType INTERFACE_DATE;
	///�������
	CCfgNameType SOFTWARE;
	///��������
	CCfgNameType FEE_TYPE;
	///��Ӫ��
	CCfgNameType SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType IF_TUOGUAN;
	///����������·
	CCfgNameType HASOTHER;
	///ϯλ��
	CGeneralResultType SEAT_NO;
	///��ע
	CPolicyStringTypeType PRO;
	
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

typedef const CWriteableSysNetDelPartyLinkInfo CSysNetDelPartyLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoActionTrigger�ǲ�����Ա��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoActionTrigger
{
public:
	///���췽��
	CSysNetDelPartyLinkInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDelPartyLinkInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDelPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetDelPartyLinkInfo	Ҫ�����SysNetDelPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetDelPartyLinkInfo	�Ѿ������SysNetDelPartyLinkInfo
	virtual void afterAdd(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetDelPartyLinkInfo	��ˢ�µ�CSysNetDelPartyLinkInfo
	///@param	pNewSysNetDelPartyLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pNewSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetDelPartyLinkInfo	��ˢ�µ�CSysNetDelPartyLinkInfo
	virtual void afterUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetDelPartyLinkInfo	Ҫɾ����CSysNetDelPartyLinkInfo
	virtual void beforeRemove(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDelPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoCommitTrigger��ȷ�ϻ�Ա��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoCommitTrigger
{
public:
	///���췽��
	CSysNetDelPartyLinkInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDelPartyLinkInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDelPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetDelPartyLinkInfo	�Ѿ������SysNetDelPartyLinkInfo
	virtual void commitAdd(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetDelPartyLinkInfo	��ˢ�µ�CSysNetDelPartyLinkInfo
	///@param	poldSysNetDelPartyLinkInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo, CWriteableSysNetDelPartyLinkInfo *pOldSysNetDelPartyLinkInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetDelPartyLinkInfo	�Ѿ�ɾ����CSysNetDelPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetDelPartyLinkInfo *pSysNetDelPartyLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDelPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDelPartyLinkInfoIterator��һ���Ի�Ա��·��Ϣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDelPartyLinkInfoIterator
{
public:
	///���췽��
	CSysNetDelPartyLinkInfoIterator(void)
	{
	}

	///���췽��
	CSysNetDelPartyLinkInfoIterator(CSysNetDelPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDelPartyLinkInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetDelPartyLinkInfo
	///@return	��һ����������CSysNetDelPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDelPartyLinkInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetDelPartyLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDelPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDelPartyLinkInfo * pSysNetDelPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetDelPartyLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPartyLinkAddrChange��һ���洢��Ա��·��Ϣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPartyLinkAddrChange
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
		if (! ID.isValid())
			return 0;
		if (! RelationID.isValid())
			return 0;
		if (! OLDADDRESS.isValid())
			return 0;
		if (! NEWADDRESS.isValid())
			return 0;
		if (! OPERATOR.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPartyLinkAddrChange *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///ID
	CVolumeType RelationID;
	///���ǰ��ַ
	CNetAttrTypeType OLDADDRESS;
	///������ַ
	CNetAttrTypeType NEWADDRESS;
	///������
	CCfgNameType OPERATOR;
	///�޸�����
	CDateType MonDate;
	///�޸�ʱ��
	CTimeType MonTime;
	
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

typedef const CWriteableSysNetPartyLinkAddrChange CSysNetPartyLinkAddrChange;

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeActionTrigger�ǲ�����Ա��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeActionTrigger
{
public:
	///���췽��
	CSysNetPartyLinkAddrChangeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPartyLinkAddrChangeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPartyLinkAddrChangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetPartyLinkAddrChange	Ҫ�����SysNetPartyLinkAddrChange
	virtual void beforeAdd(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetPartyLinkAddrChange	�Ѿ������SysNetPartyLinkAddrChange
	virtual void afterAdd(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetPartyLinkAddrChange	��ˢ�µ�CSysNetPartyLinkAddrChange
	///@param	pNewSysNetPartyLinkAddrChange	�µ�ֵ
	virtual void beforeUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pNewSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetPartyLinkAddrChange	��ˢ�µ�CSysNetPartyLinkAddrChange
	virtual void afterUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetPartyLinkAddrChange	Ҫɾ����CSysNetPartyLinkAddrChange
	virtual void beforeRemove(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPartyLinkAddrChangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeCommitTrigger��ȷ�ϻ�Ա��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeCommitTrigger
{
public:
	///���췽��
	CSysNetPartyLinkAddrChangeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPartyLinkAddrChangeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPartyLinkAddrChangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetPartyLinkAddrChange	�Ѿ������SysNetPartyLinkAddrChange
	virtual void commitAdd(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetPartyLinkAddrChange	��ˢ�µ�CSysNetPartyLinkAddrChange
	///@param	poldSysNetPartyLinkAddrChange	ԭ����ֵ
	virtual void commitUpdate(CSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange, CWriteableSysNetPartyLinkAddrChange *pOldSysNetPartyLinkAddrChange)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetPartyLinkAddrChange	�Ѿ�ɾ����CSysNetPartyLinkAddrChange
	virtual void commitRemove(CWriteableSysNetPartyLinkAddrChange *pSysNetPartyLinkAddrChange)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPartyLinkAddrChangeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartyLinkAddrChangeIterator��һ���Ի�Ա��·��Ϣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartyLinkAddrChangeIterator
{
public:
	///���췽��
	CSysNetPartyLinkAddrChangeIterator(void)
	{
	}

	///���췽��
	CSysNetPartyLinkAddrChangeIterator(CSysNetPartyLinkAddrChangeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartyLinkAddrChangeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetPartyLinkAddrChange
	///@return	��һ����������CSysNetPartyLinkAddrChange������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartyLinkAddrChange *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetPartyLinkAddrChangeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartyLinkAddrChange ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartyLinkAddrChange * pSysNetPartyLinkAddrChange,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetPartyLinkAddrChangeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorActionAttr��һ���洢��ض���ָ����ձ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorActionAttr
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
		if (! ID.isValid())
			return 0;
		if (! ActionGroup_ID.isValid())
			return 0;
		if (! MonitorAttr_ID.isValid())
			return 0;
		if (! MonitorAttrName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorActionAttr *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///������ID
	CVolumeType ActionGroup_ID;
	///��ض���ID
	CVolumeType MonitorAttr_ID;
	///ָ��Ӣ����
	CNetAttrTypeType MonitorAttrName;
	
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

typedef const CWriteableSysNetMonitorActionAttr CSysNetMonitorActionAttr;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrActionTrigger�ǲ�����ض���ָ����ձ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrActionTrigger
{
public:
	///���췽��
	CSysNetMonitorActionAttrActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorActionAttrActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorActionAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorActionAttr	Ҫ�����SysNetMonitorActionAttr
	virtual void beforeAdd(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorActionAttr	�Ѿ������SysNetMonitorActionAttr
	virtual void afterAdd(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorActionAttr	��ˢ�µ�CSysNetMonitorActionAttr
	///@param	pNewSysNetMonitorActionAttr	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pNewSysNetMonitorActionAttr)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorActionAttr	��ˢ�µ�CSysNetMonitorActionAttr
	virtual void afterUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorActionAttr	Ҫɾ����CSysNetMonitorActionAttr
	virtual void beforeRemove(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorActionAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrCommitTrigger��ȷ�ϼ�ض���ָ����ձ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorActionAttrCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorActionAttrCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorActionAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorActionAttr	�Ѿ������SysNetMonitorActionAttr
	virtual void commitAdd(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorActionAttr	��ˢ�µ�CSysNetMonitorActionAttr
	///@param	poldSysNetMonitorActionAttr	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorActionAttr *pSysNetMonitorActionAttr, CWriteableSysNetMonitorActionAttr *pOldSysNetMonitorActionAttr)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorActionAttr	�Ѿ�ɾ����CSysNetMonitorActionAttr
	virtual void commitRemove(CWriteableSysNetMonitorActionAttr *pSysNetMonitorActionAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorActionAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorActionAttrIterator��һ���Լ�ض���ָ����ձ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorActionAttrIterator
{
public:
	///���췽��
	CSysNetMonitorActionAttrIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorActionAttrIterator(CSysNetMonitorActionAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorActionAttrIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorActionAttr
	///@return	��һ����������CSysNetMonitorActionAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorActionAttr *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorActionAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorActionAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorActionAttr * pSysNetMonitorActionAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorActionAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetModule��һ���洢ģ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetModule
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! MonitorType_ID.isValid())
			return 0;
		if (! DeviceID.isValid())
			return 0;
		if (! DeviceObjectID.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! Description.isValid())
			return 0;
		if (! ModuleIndex.isValid())
			return 0;
		if (! EntPhyIndex.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetModule *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�����ض���ID
	CNetObjectIDType ObjectID;
	///��ض�������
	CVolumeType MonitorType_ID;
	///�����豸ID
	CVolumeType DeviceID;
	///�����豸ObjectID
	CNetObjectIDType DeviceObjectID;
	///����
	CTypeObjectIDType Name;
	///����
	CNetObjectIDType Description;
	///ģ������
	CVolumeType ModuleIndex;
	///��������
	CVolumeType EntPhyIndex;
	
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

typedef const CWriteableSysNetModule CSysNetModule;

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleActionTrigger�ǲ���ģ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleActionTrigger
{
public:
	///���췽��
	CSysNetModuleActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetModuleActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetModuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetModule	Ҫ�����SysNetModule
	virtual void beforeAdd(CWriteableSysNetModule *pSysNetModule)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetModule	�Ѿ������SysNetModule
	virtual void afterAdd(CSysNetModule *pSysNetModule)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetModule	��ˢ�µ�CSysNetModule
	///@param	pNewSysNetModule	�µ�ֵ
	virtual void beforeUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pNewSysNetModule)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetModule	��ˢ�µ�CSysNetModule
	virtual void afterUpdate(CSysNetModule *pSysNetModule)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetModule	Ҫɾ����CSysNetModule
	virtual void beforeRemove(CSysNetModule *pSysNetModule)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetModuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleCommitTrigger��ȷ��ģ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleCommitTrigger
{
public:
	///���췽��
	CSysNetModuleCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetModuleCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetModuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetModule	�Ѿ������SysNetModule
	virtual void commitAdd(CSysNetModule *pSysNetModule)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetModule	��ˢ�µ�CSysNetModule
	///@param	poldSysNetModule	ԭ����ֵ
	virtual void commitUpdate(CSysNetModule *pSysNetModule, CWriteableSysNetModule *pOldSysNetModule)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetModule	�Ѿ�ɾ����CSysNetModule
	virtual void commitRemove(CWriteableSysNetModule *pSysNetModule)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetModuleFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetModuleIterator��һ����ģ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetModuleIterator
{
public:
	///���췽��
	CSysNetModuleIterator(void)
	{
	}

	///���췽��
	CSysNetModuleIterator(CSysNetModuleFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetModuleIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetModule
	///@return	��һ����������CSysNetModule������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetModule *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetModuleFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetModule ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetModule * pSysNetModule,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetModuleFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetEventExpr��һ���洢�澯���ʽ��Ϣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetEventExpr
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
		if (! ID.isValid())
			return 0;
		if (! CNAME.isValid())
			return 0;
		if (! ENAME.isValid())
			return 0;
		if (! WarningLEVEL.isValid())
			return 0;
		if (! EventTypeID.isValid())
			return 0;
		if (! SubEventTypeID.isValid())
			return 0;
		if (! GIVEUPTIME.isValid())
			return 0;
		if (! CONTROL.isValid())
			return 0;
		if (! EXPR.isValid())
			return 0;
		if (! BRIEF.isValid())
			return 0;
		if (! DISCRIPTION.isValid())
			return 0;
		if (! MSGGROUP_ID.isValid())
			return 0;
		if (! ADMINGROUP_ID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetEventExpr *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�����¼���
	CNetObjectIDType CNAME;
	///Ӣ���¼���
	CNetObjectIDType ENAME;
	///�¼�����
	CCfgNameType WarningLEVEL;
	///�¼�����
	CVolumeType EventTypeID;
	///�¼�������
	CVolumeType SubEventTypeID;
	///�澯���ʱ��
	CVolumeType GIVEUPTIME;
	///���ƶ�����
	CGeneralResultType CONTROL;
	///���ʽ������
	CGeneralResultType EXPR;
	///�¼�����
	CTypeObjectIDType BRIEF;
	///�¼�������
	CNetAttrTypeType DISCRIPTION;
	///��Ϣ��ID
	CVolumeType MSGGROUP_ID;
	///����Ա��ID
	CVolumeType ADMINGROUP_ID;
	
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

typedef const CWriteableSysNetEventExpr CSysNetEventExpr;

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprActionTrigger�ǲ����澯���ʽ��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprActionTrigger
{
public:
	///���췽��
	CSysNetEventExprActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetEventExprActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetEventExprFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetEventExpr	Ҫ�����SysNetEventExpr
	virtual void beforeAdd(CWriteableSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetEventExpr	�Ѿ������SysNetEventExpr
	virtual void afterAdd(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetEventExpr	��ˢ�µ�CSysNetEventExpr
	///@param	pNewSysNetEventExpr	�µ�ֵ
	virtual void beforeUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pNewSysNetEventExpr)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetEventExpr	��ˢ�µ�CSysNetEventExpr
	virtual void afterUpdate(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetEventExpr	Ҫɾ����CSysNetEventExpr
	virtual void beforeRemove(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetEventExprFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprCommitTrigger��ȷ�ϸ澯���ʽ��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprCommitTrigger
{
public:
	///���췽��
	CSysNetEventExprCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetEventExprCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetEventExprFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetEventExpr	�Ѿ������SysNetEventExpr
	virtual void commitAdd(CSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetEventExpr	��ˢ�µ�CSysNetEventExpr
	///@param	poldSysNetEventExpr	ԭ����ֵ
	virtual void commitUpdate(CSysNetEventExpr *pSysNetEventExpr, CWriteableSysNetEventExpr *pOldSysNetEventExpr)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetEventExpr	�Ѿ�ɾ����CSysNetEventExpr
	virtual void commitRemove(CWriteableSysNetEventExpr *pSysNetEventExpr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetEventExprFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventExprIterator��һ���Ը澯���ʽ��Ϣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventExprIterator
{
public:
	///���췽��
	CSysNetEventExprIterator(void)
	{
	}

	///���췽��
	CSysNetEventExprIterator(CSysNetEventExprFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetEventExprIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetEventExpr
	///@return	��һ����������CSysNetEventExpr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventExpr *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetEventExprFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventExpr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventExpr * pSysNetEventExpr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetEventExprFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetEventType��һ���洢�¼����͵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetEventType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetEventType *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�¼�����������
	CTypeObjectIDType CName;
	///�¼�����Ӣ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetEventType CSysNetEventType;

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeActionTrigger�ǲ����¼�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeActionTrigger
{
public:
	///���췽��
	CSysNetEventTypeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetEventTypeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetEventType	Ҫ�����SysNetEventType
	virtual void beforeAdd(CWriteableSysNetEventType *pSysNetEventType)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetEventType	�Ѿ������SysNetEventType
	virtual void afterAdd(CSysNetEventType *pSysNetEventType)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetEventType	��ˢ�µ�CSysNetEventType
	///@param	pNewSysNetEventType	�µ�ֵ
	virtual void beforeUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pNewSysNetEventType)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetEventType	��ˢ�µ�CSysNetEventType
	virtual void afterUpdate(CSysNetEventType *pSysNetEventType)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetEventType	Ҫɾ����CSysNetEventType
	virtual void beforeRemove(CSysNetEventType *pSysNetEventType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeCommitTrigger��ȷ���¼�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeCommitTrigger
{
public:
	///���췽��
	CSysNetEventTypeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetEventTypeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetEventType	�Ѿ������SysNetEventType
	virtual void commitAdd(CSysNetEventType *pSysNetEventType)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetEventType	��ˢ�µ�CSysNetEventType
	///@param	poldSysNetEventType	ԭ����ֵ
	virtual void commitUpdate(CSysNetEventType *pSysNetEventType, CWriteableSysNetEventType *pOldSysNetEventType)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetEventType	�Ѿ�ɾ����CSysNetEventType
	virtual void commitRemove(CWriteableSysNetEventType *pSysNetEventType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventTypeIterator��һ�����¼����͵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventTypeIterator
{
public:
	///���췽��
	CSysNetEventTypeIterator(void)
	{
	}

	///���췽��
	CSysNetEventTypeIterator(CSysNetEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetEventTypeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetEventType
	///@return	��һ����������CSysNetEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventType *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetEventTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventType * pSysNetEventType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetEventTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetSubEventType��һ���洢�¼������͵Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetSubEventType
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetSubEventType *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�¼�������������
	CTypeObjectIDType CName;
	///�¼�������Ӣ����
	CTypeObjectIDType EName;
	
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

typedef const CWriteableSysNetSubEventType CSysNetSubEventType;

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeActionTrigger�ǲ����¼�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeActionTrigger
{
public:
	///���췽��
	CSysNetSubEventTypeActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetSubEventTypeActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetSubEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetSubEventType	Ҫ�����SysNetSubEventType
	virtual void beforeAdd(CWriteableSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetSubEventType	�Ѿ������SysNetSubEventType
	virtual void afterAdd(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetSubEventType	��ˢ�µ�CSysNetSubEventType
	///@param	pNewSysNetSubEventType	�µ�ֵ
	virtual void beforeUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pNewSysNetSubEventType)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetSubEventType	��ˢ�µ�CSysNetSubEventType
	virtual void afterUpdate(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetSubEventType	Ҫɾ����CSysNetSubEventType
	virtual void beforeRemove(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetSubEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeCommitTrigger��ȷ���¼�������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeCommitTrigger
{
public:
	///���췽��
	CSysNetSubEventTypeCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetSubEventTypeCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetSubEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetSubEventType	�Ѿ������SysNetSubEventType
	virtual void commitAdd(CSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetSubEventType	��ˢ�µ�CSysNetSubEventType
	///@param	poldSysNetSubEventType	ԭ����ֵ
	virtual void commitUpdate(CSysNetSubEventType *pSysNetSubEventType, CWriteableSysNetSubEventType *pOldSysNetSubEventType)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetSubEventType	�Ѿ�ɾ����CSysNetSubEventType
	virtual void commitRemove(CWriteableSysNetSubEventType *pSysNetSubEventType)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetSubEventTypeFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetSubEventTypeIterator��һ�����¼������͵�ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetSubEventTypeIterator
{
public:
	///���췽��
	CSysNetSubEventTypeIterator(void)
	{
	}

	///���췽��
	CSysNetSubEventTypeIterator(CSysNetSubEventTypeFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetSubEventTypeIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetSubEventType
	///@return	��һ����������CSysNetSubEventType������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetSubEventType *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetSubEventTypeFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetSubEventType ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetSubEventType * pSysNetSubEventType,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetSubEventTypeFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetEventLevel��һ���洢�¼�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetEventLevel
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
		if (! ID.isValid())
			return 0;
		if (! CName.isValid())
			return 0;
		if (! EName.isValid())
			return 0;
		if (! DISCRIPTION.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetEventLevel *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�¼�����������
	CTypeObjectIDType CName;
	///�¼�����Ӣ����
	CTypeObjectIDType EName;
	///�¼�����������
	CNetAttrTypeType DISCRIPTION;
	
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

typedef const CWriteableSysNetEventLevel CSysNetEventLevel;

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelActionTrigger�ǲ����¼�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelActionTrigger
{
public:
	///���췽��
	CSysNetEventLevelActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetEventLevelActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetEventLevelFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetEventLevel	Ҫ�����SysNetEventLevel
	virtual void beforeAdd(CWriteableSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetEventLevel	�Ѿ������SysNetEventLevel
	virtual void afterAdd(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetEventLevel	��ˢ�µ�CSysNetEventLevel
	///@param	pNewSysNetEventLevel	�µ�ֵ
	virtual void beforeUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pNewSysNetEventLevel)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetEventLevel	��ˢ�µ�CSysNetEventLevel
	virtual void afterUpdate(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetEventLevel	Ҫɾ����CSysNetEventLevel
	virtual void beforeRemove(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetEventLevelFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelCommitTrigger��ȷ���¼�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelCommitTrigger
{
public:
	///���췽��
	CSysNetEventLevelCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetEventLevelCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetEventLevelFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetEventLevel	�Ѿ������SysNetEventLevel
	virtual void commitAdd(CSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetEventLevel	��ˢ�µ�CSysNetEventLevel
	///@param	poldSysNetEventLevel	ԭ����ֵ
	virtual void commitUpdate(CSysNetEventLevel *pSysNetEventLevel, CWriteableSysNetEventLevel *pOldSysNetEventLevel)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetEventLevel	�Ѿ�ɾ����CSysNetEventLevel
	virtual void commitRemove(CWriteableSysNetEventLevel *pSysNetEventLevel)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetEventLevelFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetEventLevelIterator��һ�����¼������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetEventLevelIterator
{
public:
	///���췽��
	CSysNetEventLevelIterator(void)
	{
	}

	///���췽��
	CSysNetEventLevelIterator(CSysNetEventLevelFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetEventLevelIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetEventLevel
	///@return	��һ����������CSysNetEventLevel������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetEventLevel *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetEventLevelFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetEventLevel ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetEventLevel * pSysNetEventLevel,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetEventLevelFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorDeviceTask��һ���洢���������������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorDeviceTask
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
		if (! ID.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! IPAddress.isValid())
			return 0;
		if (! Manufactory_ID.isValid())
			return 0;
		if (! InstructChain.isValid())
			return 0;
		if (! InstructAlias.isValid())
			return 0;
		if (! InstructArgs.isValid())
			return 0;
		if (! DefParamChain.isValid())
			return 0;
		if (! Flag.isValid())
			return 0;
		if (! SecondID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorDeviceTask *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�����ض���ID
	CNetObjectIDType ObjectID;
	///IP��ַ
	CIPAddressType IPAddress;
	///�����豸����ID
	CVolumeType Manufactory_ID;
	///ָ��
	CNetString256Type InstructChain;
	///ָ�����
	CNetString128Type InstructAlias;
	///ָ�������
	CNetString256Type InstructArgs;
	///ָ�귧ֵ��
	CNetString2KType DefParamChain;
	///������־
	CVolumeType Flag;
	///PrimID
	CVolumeType SecondID;
	
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

typedef const CWriteableSysNetMonitorDeviceTask CSysNetMonitorDeviceTask;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskActionTrigger�ǲ������������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskActionTrigger
{
public:
	///���췽��
	CSysNetMonitorDeviceTaskActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorDeviceTaskActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorDeviceTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorDeviceTask	Ҫ�����SysNetMonitorDeviceTask
	virtual void beforeAdd(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorDeviceTask	�Ѿ������SysNetMonitorDeviceTask
	virtual void afterAdd(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorDeviceTask	��ˢ�µ�CSysNetMonitorDeviceTask
	///@param	pNewSysNetMonitorDeviceTask	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pNewSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorDeviceTask	��ˢ�µ�CSysNetMonitorDeviceTask
	virtual void afterUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorDeviceTask	Ҫɾ����CSysNetMonitorDeviceTask
	virtual void beforeRemove(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorDeviceTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskCommitTrigger��ȷ�����������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorDeviceTaskCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorDeviceTaskCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorDeviceTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorDeviceTask	�Ѿ������SysNetMonitorDeviceTask
	virtual void commitAdd(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorDeviceTask	��ˢ�µ�CSysNetMonitorDeviceTask
	///@param	poldSysNetMonitorDeviceTask	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask, CWriteableSysNetMonitorDeviceTask *pOldSysNetMonitorDeviceTask)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorDeviceTask	�Ѿ�ɾ����CSysNetMonitorDeviceTask
	virtual void commitRemove(CWriteableSysNetMonitorDeviceTask *pSysNetMonitorDeviceTask)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorDeviceTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorDeviceTaskIterator��һ��������������������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorDeviceTaskIterator
{
public:
	///���췽��
	CSysNetMonitorDeviceTaskIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorDeviceTaskIterator(CSysNetMonitorDeviceTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorDeviceTaskIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorDeviceTask
	///@return	��һ����������CSysNetMonitorDeviceTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorDeviceTask *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorDeviceTaskFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorDeviceTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorDeviceTask * pSysNetMonitorDeviceTask,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorDeviceTaskFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMonitorTaskInstAttrs��һ���洢����ָ��ָ�꼯��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMonitorTaskInstAttrs
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
		if (! ID.isValid())
			return 0;
		if (! Manufactory_ID.isValid())
			return 0;
		if (! InstructAlias.isValid())
			return 0;
		if (! DEVICETYPE.isValid())
			return 0;
		if (! AttrsChain.isValid())
			return 0;
		if (! DefRegularChain.isValid())
			return 0;
		if (! DefParamChain.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMonitorTaskInstAttrs *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�����豸����ID
	CVolumeType Manufactory_ID;
	///ָ�����
	CNetString128Type InstructAlias;
	///�豸�ͺ�
	CNetString128Type DEVICETYPE;
	///ָ�괮
	CNetString256Type AttrsChain;
	///ָ�����
	CNetString512Type DefRegularChain;
	///ָ�귧ֵ��
	CNetString2KType DefParamChain;
	
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

typedef const CWriteableSysNetMonitorTaskInstAttrs CSysNetMonitorTaskInstAttrs;

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsActionTrigger�ǲ�������ָ��ָ�꼯��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsActionTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskInstAttrsActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskInstAttrsActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskInstAttrsFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMonitorTaskInstAttrs	Ҫ�����SysNetMonitorTaskInstAttrs
	virtual void beforeAdd(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMonitorTaskInstAttrs	�Ѿ������SysNetMonitorTaskInstAttrs
	virtual void afterAdd(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMonitorTaskInstAttrs	��ˢ�µ�CSysNetMonitorTaskInstAttrs
	///@param	pNewSysNetMonitorTaskInstAttrs	�µ�ֵ
	virtual void beforeUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pNewSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMonitorTaskInstAttrs	��ˢ�µ�CSysNetMonitorTaskInstAttrs
	virtual void afterUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMonitorTaskInstAttrs	Ҫɾ����CSysNetMonitorTaskInstAttrs
	virtual void beforeRemove(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskInstAttrsFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsCommitTrigger��ȷ������ָ��ָ�꼯��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsCommitTrigger
{
public:
	///���췽��
	CSysNetMonitorTaskInstAttrsCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMonitorTaskInstAttrsCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMonitorTaskInstAttrsFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMonitorTaskInstAttrs	�Ѿ������SysNetMonitorTaskInstAttrs
	virtual void commitAdd(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMonitorTaskInstAttrs	��ˢ�µ�CSysNetMonitorTaskInstAttrs
	///@param	poldSysNetMonitorTaskInstAttrs	ԭ����ֵ
	virtual void commitUpdate(CSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs, CWriteableSysNetMonitorTaskInstAttrs *pOldSysNetMonitorTaskInstAttrs)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMonitorTaskInstAttrs	�Ѿ�ɾ����CSysNetMonitorTaskInstAttrs
	virtual void commitRemove(CWriteableSysNetMonitorTaskInstAttrs *pSysNetMonitorTaskInstAttrs)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskInstAttrsFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMonitorTaskInstAttrsIterator��һ��������ָ��ָ�꼯���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMonitorTaskInstAttrsIterator
{
public:
	///���췽��
	CSysNetMonitorTaskInstAttrsIterator(void)
	{
	}

	///���췽��
	CSysNetMonitorTaskInstAttrsIterator(CSysNetMonitorTaskInstAttrsFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMonitorTaskInstAttrsIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMonitorTaskInstAttrs
	///@return	��һ����������CSysNetMonitorTaskInstAttrs������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMonitorTaskInstAttrs *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMonitorTaskInstAttrsFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMonitorTaskInstAttrs ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMonitorTaskInstAttrs * pSysNetMonitorTaskInstAttrs,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMonitorTaskInstAttrsFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetBaseLine��һ���洢���߱�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetBaseLine
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
		if (! ID.isValid())
			return 0;
		if (! MANUFACTORY_ID.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! SerialUsed.isValid())
			return 0;
		if (! data.isValid())
			return 0;
		if (! memo.isValid())
			return 0;
		if (! Flag.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetBaseLine *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��������
	CVolumeType MANUFACTORY_ID;
	///������
	CNetObjectIDType Name;
	///�豸�ͺ�
	CNetObjectIDType SerialUsed;
	///�ļ�����
	CbaseCommentType data;
	///��ע
	CNetAttrTypeType memo;
	///������־
	CVolumeType Flag;
	
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

typedef const CWriteableSysNetBaseLine CSysNetBaseLine;

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineActionTrigger�ǲ������߱�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineActionTrigger
{
public:
	///���췽��
	CSysNetBaseLineActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetBaseLineActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetBaseLineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetBaseLine	Ҫ�����SysNetBaseLine
	virtual void beforeAdd(CWriteableSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetBaseLine	�Ѿ������SysNetBaseLine
	virtual void afterAdd(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetBaseLine	��ˢ�µ�CSysNetBaseLine
	///@param	pNewSysNetBaseLine	�µ�ֵ
	virtual void beforeUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pNewSysNetBaseLine)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetBaseLine	��ˢ�µ�CSysNetBaseLine
	virtual void afterUpdate(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetBaseLine	Ҫɾ����CSysNetBaseLine
	virtual void beforeRemove(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetBaseLineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineCommitTrigger��ȷ�ϻ��߱�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineCommitTrigger
{
public:
	///���췽��
	CSysNetBaseLineCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetBaseLineCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetBaseLineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetBaseLine	�Ѿ������SysNetBaseLine
	virtual void commitAdd(CSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetBaseLine	��ˢ�µ�CSysNetBaseLine
	///@param	poldSysNetBaseLine	ԭ����ֵ
	virtual void commitUpdate(CSysNetBaseLine *pSysNetBaseLine, CWriteableSysNetBaseLine *pOldSysNetBaseLine)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetBaseLine	�Ѿ�ɾ����CSysNetBaseLine
	virtual void commitRemove(CWriteableSysNetBaseLine *pSysNetBaseLine)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetBaseLineFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineIterator��һ���Ի��߱��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineIterator
{
public:
	///���췽��
	CSysNetBaseLineIterator(void)
	{
	}

	///���췽��
	CSysNetBaseLineIterator(CSysNetBaseLineFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetBaseLineIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetBaseLine
	///@return	��һ����������CSysNetBaseLine������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLine *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetBaseLineFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLine ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLine * pSysNetBaseLine,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetBaseLineFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetBaseLineTask��һ���洢���������Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetBaseLineTask
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
		if (! ID.isValid())
			return 0;
		if (! Name.isValid())
			return 0;
		if (! BaseLineIDList.isValid())
			return 0;
		if (! DeviceIDList.isValid())
			return 0;
		if (! GenDate.isValid())
			return 0;
		if (! GenTime.isValid())
			return 0;
		if (! GenUser.isValid())
			return 0;
		if (! memo.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetBaseLineTask *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///����������
	CNetObjectIDType Name;
	///����ID�б�
	CGeneralResultType BaseLineIDList;
	///�豸ID�б�
	CGeneralResultType DeviceIDList;
	///��������
	CDateType GenDate;
	///����ʱ��
	CTimeType GenTime;
	///������
	CTypeUserNameType GenUser;
	///��ע
	CNetAttrTypeType memo;
	
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

typedef const CWriteableSysNetBaseLineTask CSysNetBaseLineTask;

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskActionTrigger�ǲ������������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskActionTrigger
{
public:
	///���췽��
	CSysNetBaseLineTaskActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetBaseLineTaskActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetBaseLineTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetBaseLineTask	Ҫ�����SysNetBaseLineTask
	virtual void beforeAdd(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetBaseLineTask	�Ѿ������SysNetBaseLineTask
	virtual void afterAdd(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetBaseLineTask	��ˢ�µ�CSysNetBaseLineTask
	///@param	pNewSysNetBaseLineTask	�µ�ֵ
	virtual void beforeUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pNewSysNetBaseLineTask)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetBaseLineTask	��ˢ�µ�CSysNetBaseLineTask
	virtual void afterUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetBaseLineTask	Ҫɾ����CSysNetBaseLineTask
	virtual void beforeRemove(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetBaseLineTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskCommitTrigger��ȷ�ϻ��������ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskCommitTrigger
{
public:
	///���췽��
	CSysNetBaseLineTaskCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetBaseLineTaskCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetBaseLineTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetBaseLineTask	�Ѿ������SysNetBaseLineTask
	virtual void commitAdd(CSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetBaseLineTask	��ˢ�µ�CSysNetBaseLineTask
	///@param	poldSysNetBaseLineTask	ԭ����ֵ
	virtual void commitUpdate(CSysNetBaseLineTask *pSysNetBaseLineTask, CWriteableSysNetBaseLineTask *pOldSysNetBaseLineTask)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetBaseLineTask	�Ѿ�ɾ����CSysNetBaseLineTask
	virtual void commitRemove(CWriteableSysNetBaseLineTask *pSysNetBaseLineTask)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetBaseLineTaskFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetBaseLineTaskIterator��һ���Ի���������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetBaseLineTaskIterator
{
public:
	///���췽��
	CSysNetBaseLineTaskIterator(void)
	{
	}

	///���췽��
	CSysNetBaseLineTaskIterator(CSysNetBaseLineTaskFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetBaseLineTaskIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetBaseLineTask
	///@return	��һ����������CSysNetBaseLineTask������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetBaseLineTask *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetBaseLineTaskFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetBaseLineTask ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetBaseLineTask * pSysNetBaseLineTask,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetBaseLineTaskFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbNetPartyLinkStatusInfo��һ���洢��Ա��·״̬��Ϣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbNetPartyLinkStatusInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! status.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbNetPartyLinkStatusInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///ϯλ��
	CCfgNameType SEAT_NO;
	///·��������IP
	CTypeObjectIDType IPADDR;
	///·�����˿ں�
	CTypeObjectIDType Interface;
	///��·״̬
	CTypeObjectIDType status;
	
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

typedef const CWriteableSysMdbNetPartyLinkStatusInfo CSysMdbNetPartyLinkStatusInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoActionTrigger�ǲ�����Ա��·״̬��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoActionTrigger
{
public:
	///���췽��
	CSysMdbNetPartyLinkStatusInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbNetPartyLinkStatusInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbNetPartyLinkStatusInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫ�����SysMdbNetPartyLinkStatusInfo
	virtual void beforeAdd(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbNetPartyLinkStatusInfo	�Ѿ������SysMdbNetPartyLinkStatusInfo
	virtual void afterAdd(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbNetPartyLinkStatusInfo	��ˢ�µ�CSysMdbNetPartyLinkStatusInfo
	///@param	pNewSysMdbNetPartyLinkStatusInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pNewSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbNetPartyLinkStatusInfo	��ˢ�µ�CSysMdbNetPartyLinkStatusInfo
	virtual void afterUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbNetPartyLinkStatusInfo	Ҫɾ����CSysMdbNetPartyLinkStatusInfo
	virtual void beforeRemove(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbNetPartyLinkStatusInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoCommitTrigger��ȷ�ϻ�Ա��·״̬��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbNetPartyLinkStatusInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbNetPartyLinkStatusInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbNetPartyLinkStatusInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbNetPartyLinkStatusInfo	�Ѿ������SysMdbNetPartyLinkStatusInfo
	virtual void commitAdd(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbNetPartyLinkStatusInfo	��ˢ�µ�CSysMdbNetPartyLinkStatusInfo
	///@param	poldSysMdbNetPartyLinkStatusInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo, CWriteableSysMdbNetPartyLinkStatusInfo *pOldSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbNetPartyLinkStatusInfo	�Ѿ�ɾ����CSysMdbNetPartyLinkStatusInfo
	virtual void commitRemove(CWriteableSysMdbNetPartyLinkStatusInfo *pSysMdbNetPartyLinkStatusInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbNetPartyLinkStatusInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbNetPartyLinkStatusInfoIterator��һ���Ի�Ա��·״̬��Ϣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbNetPartyLinkStatusInfoIterator
{
public:
	///���췽��
	CSysMdbNetPartyLinkStatusInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbNetPartyLinkStatusInfoIterator(CSysMdbNetPartyLinkStatusInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbNetPartyLinkStatusInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbNetPartyLinkStatusInfo
	///@return	��һ����������CSysMdbNetPartyLinkStatusInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbNetPartyLinkStatusInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbNetPartyLinkStatusInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbNetPartyLinkStatusInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbNetPartyLinkStatusInfo * pSysMdbNetPartyLinkStatusInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbNetPartyLinkStatusInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetMemberSDHLineInfo��һ���洢��ԱSDH��·��ϸ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetMemberSDHLineInfo
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
		if (! ID.isValid())
			return 0;
		if (! SeqNo.isValid())
			return 0;
		if (! MemContractNo.isValid())
			return 0;
		if (! ApplyPerson.isValid())
			return 0;
		if (! MonthlyRental.isValid())
			return 0;
		if (! MemberNo.isValid())
			return 0;
		if (! ParticipantName.isValid())
			return 0;
		if (! ClientManager.isValid())
			return 0;
		if (! Bandwidth.isValid())
			return 0;
		if (! InterfaceType.isValid())
			return 0;
		if (! RemoteCircuit.isValid())
			return 0;
		if (! LocalCircuit.isValid())
			return 0;
		if (! Remark.isValid())
			return 0;
		if (! EndALineAddress.isValid())
			return 0;
		if (! EndAContact.isValid())
			return 0;
		if (! EndZLineAddress.isValid())
			return 0;
		if (! ContactName.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! StartPortID.isValid())
			return 0;
		if (! StartJump.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! DataCenterID.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetMemberSDHLineInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///���к�
	CVolumeType SeqNo;
	///��ͬ��
	CContractSeqNoType MemContractNo;
	///������
	CApplyPersonType ApplyPerson;
	///�������
	CLongVolumeType MonthlyRental;
	///��Ա��
	CPartyIDType MemberNo;
	///��Ա����
	CParticipantNameType ParticipantName;
	///�ͻ�����
	CNetString128Type ClientManager;
	///����
	CNetString128Type Bandwidth;
	///�ӿ���
	CNetString128Type InterfaceType;
	///��;��·����
	CNetString128Type RemoteCircuit;
	///���ص�·����
	CNetString128Type LocalCircuit;
	///��ע
	CNetString128Type Remark;
	///A�˽����ַ
	CNetString512Type EndALineAddress;
	///A����ϵ��
	CNetString128Type EndAContact;
	///Z�˽����ַ
	CNetString512Type EndZLineAddress;
	///��ϵ��
	CIndividualNameType ContactName;
	///��ϵ�绰
	CTypeObjectIDType TELEPHONE;
	///�ֻ���
	CTypeObjectIDType MOBILEPHONE;
	///·��������IP
	CTypeObjectIDType IPADDR;
	///·�����˿ں�
	CTypeObjectIDType Interface;
	///����ʡ��
	CCfgNameType PROVINCE;
	///��ʼ�豸�˿�
	CNetString256Type StartPortID;
	///��ʼ�豸���Ӷ�
	CNetString128Type StartJump;
	///��·״̬
	CCfgNameType LINE_STATUS;
	///�������Ĵ���
	CDataCenterIDType DataCenterID;
	
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

typedef const CWriteableSysNetMemberSDHLineInfo CSysNetMemberSDHLineInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoActionTrigger�ǲ�����ԱSDH��·��ϸ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoActionTrigger
{
public:
	///���췽��
	CSysNetMemberSDHLineInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMemberSDHLineInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMemberSDHLineInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetMemberSDHLineInfo	Ҫ�����SysNetMemberSDHLineInfo
	virtual void beforeAdd(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetMemberSDHLineInfo	�Ѿ������SysNetMemberSDHLineInfo
	virtual void afterAdd(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetMemberSDHLineInfo	��ˢ�µ�CSysNetMemberSDHLineInfo
	///@param	pNewSysNetMemberSDHLineInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pNewSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetMemberSDHLineInfo	��ˢ�µ�CSysNetMemberSDHLineInfo
	virtual void afterUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetMemberSDHLineInfo	Ҫɾ����CSysNetMemberSDHLineInfo
	virtual void beforeRemove(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMemberSDHLineInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoCommitTrigger��ȷ�ϻ�ԱSDH��·��ϸ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoCommitTrigger
{
public:
	///���췽��
	CSysNetMemberSDHLineInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetMemberSDHLineInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetMemberSDHLineInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetMemberSDHLineInfo	�Ѿ������SysNetMemberSDHLineInfo
	virtual void commitAdd(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetMemberSDHLineInfo	��ˢ�µ�CSysNetMemberSDHLineInfo
	///@param	poldSysNetMemberSDHLineInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo, CWriteableSysNetMemberSDHLineInfo *pOldSysNetMemberSDHLineInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetMemberSDHLineInfo	�Ѿ�ɾ����CSysNetMemberSDHLineInfo
	virtual void commitRemove(CWriteableSysNetMemberSDHLineInfo *pSysNetMemberSDHLineInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetMemberSDHLineInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetMemberSDHLineInfoIterator��һ���Ի�ԱSDH��·��ϸ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetMemberSDHLineInfoIterator
{
public:
	///���췽��
	CSysNetMemberSDHLineInfoIterator(void)
	{
	}

	///���췽��
	CSysNetMemberSDHLineInfoIterator(CSysNetMemberSDHLineInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetMemberSDHLineInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetMemberSDHLineInfo
	///@return	��һ����������CSysNetMemberSDHLineInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetMemberSDHLineInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetMemberSDHLineInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetMemberSDHLineInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetMemberSDHLineInfo * pSysNetMemberSDHLineInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetMemberSDHLineInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetDDNLinkInfo��һ���洢DDN��·��Ϣ��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetDDNLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! ClientName.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! Bandwidth.isValid())
			return 0;
		if (! EndAAddress.isValid())
			return 0;
		if (! EndAContactName.isValid())
			return 0;
		if (! EndZAddress.isValid())
			return 0;
		if (! EndZContactName.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetDDNLinkInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///�ͻ�����
	CPartyNameType ClientName;
	///��·���
	CTypeObjectIDType DDN_NO;
	///ҵ��Ԫ
	CBusinessUnitType BusinessUnit;
	///����
	CNetString128Type Bandwidth;
	///�׶˵�ַ
	CAddressType EndAAddress;
	///�׶���ϵ��
	CIndividualNameType EndAContactName;
	///�Ҷ˵�ַ
	CAddressType EndZAddress;
	///�Ҷ���ϵ��
	CIndividualNameType EndZContactName;
	
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

typedef const CWriteableSysNetDDNLinkInfo CSysNetDDNLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoActionTrigger�ǲ���DDN��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoActionTrigger
{
public:
	///���췽��
	CSysNetDDNLinkInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDDNLinkInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDDNLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetDDNLinkInfo	Ҫ�����SysNetDDNLinkInfo
	virtual void beforeAdd(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetDDNLinkInfo	�Ѿ������SysNetDDNLinkInfo
	virtual void afterAdd(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetDDNLinkInfo	��ˢ�µ�CSysNetDDNLinkInfo
	///@param	pNewSysNetDDNLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pNewSysNetDDNLinkInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetDDNLinkInfo	��ˢ�µ�CSysNetDDNLinkInfo
	virtual void afterUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetDDNLinkInfo	Ҫɾ����CSysNetDDNLinkInfo
	virtual void beforeRemove(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDDNLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoCommitTrigger��ȷ��DDN��·��Ϣ��ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoCommitTrigger
{
public:
	///���췽��
	CSysNetDDNLinkInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetDDNLinkInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetDDNLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetDDNLinkInfo	�Ѿ������SysNetDDNLinkInfo
	virtual void commitAdd(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetDDNLinkInfo	��ˢ�µ�CSysNetDDNLinkInfo
	///@param	poldSysNetDDNLinkInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetDDNLinkInfo *pSysNetDDNLinkInfo, CWriteableSysNetDDNLinkInfo *pOldSysNetDDNLinkInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetDDNLinkInfo	�Ѿ�ɾ����CSysNetDDNLinkInfo
	virtual void commitRemove(CWriteableSysNetDDNLinkInfo *pSysNetDDNLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetDDNLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetDDNLinkInfoIterator��һ����DDN��·��Ϣ���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetDDNLinkInfoIterator
{
public:
	///���췽��
	CSysNetDDNLinkInfoIterator(void)
	{
	}

	///���췽��
	CSysNetDDNLinkInfoIterator(CSysNetDDNLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetDDNLinkInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetDDNLinkInfo
	///@return	��һ����������CSysNetDDNLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetDDNLinkInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetDDNLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetDDNLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetDDNLinkInfo * pSysNetDDNLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetDDNLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPseudMemberLinkInfo��һ���洢�ǻ�Ա��·ʹ����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPseudMemberLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! SeqNo.isValid())
			return 0;
		if (! MemContractNo.isValid())
			return 0;
		if (! LineUsage.isValid())
			return 0;
		if (! LocalCircuit.isValid())
			return 0;
		if (! RemoteCircuit.isValid())
			return 0;
		if (! BusinessUnit.isValid())
			return 0;
		if (! Bandwidth.isValid())
			return 0;
		if (! ApplyPerson.isValid())
			return 0;
		if (! MonthlyRental.isValid())
			return 0;
		if (! EndAAddress.isValid())
			return 0;
		if (! EndAContactName.isValid())
			return 0;
		if (! EndZAddress.isValid())
			return 0;
		if (! EndZContactName.isValid())
			return 0;
		if (! Telephone.isValid())
			return 0;
		if (! LineInfo.isValid())
			return 0;
		if (! IPADDR.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPseudMemberLinkInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///���к�
	CVolumeType SeqNo;
	///��ͬ��
	CContractSeqNoType MemContractNo;
	///��·��;
	CNetString128Type LineUsage;
	///���ص�·����
	CNetString128Type LocalCircuit;
	///��;��·����
	CNetString128Type RemoteCircuit;
	///ҵ��
	CBusinessUnitType BusinessUnit;
	///����
	CNetString128Type Bandwidth;
	///������
	CApplyPersonType ApplyPerson;
	///�������
	CLongVolumeType MonthlyRental;
	///�׶˵�ַ
	CAddressType EndAAddress;
	///�׶���ϵ��
	CIndividualNameType EndAContactName;
	///�Ҷ˵�ַ
	CAddressType EndZAddress;
	///�Ҷ���ϵ��
	CIndividualNameType EndZContactName;
	///�Ҷ˵绰����
	CTelephoneType Telephone;
	///��·��Ϣ
	CTypeObjectIDType LineInfo;
	///·��������IP
	CTypeObjectIDType IPADDR;
	
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

typedef const CWriteableSysNetPseudMemberLinkInfo CSysNetPseudMemberLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoActionTrigger�ǲ����ǻ�Ա��·ʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoActionTrigger
{
public:
	///���췽��
	CSysNetPseudMemberLinkInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPseudMemberLinkInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPseudMemberLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetPseudMemberLinkInfo	Ҫ�����SysNetPseudMemberLinkInfo
	virtual void beforeAdd(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetPseudMemberLinkInfo	�Ѿ������SysNetPseudMemberLinkInfo
	virtual void afterAdd(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetPseudMemberLinkInfo	��ˢ�µ�CSysNetPseudMemberLinkInfo
	///@param	pNewSysNetPseudMemberLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pNewSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetPseudMemberLinkInfo	��ˢ�µ�CSysNetPseudMemberLinkInfo
	virtual void afterUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetPseudMemberLinkInfo	Ҫɾ����CSysNetPseudMemberLinkInfo
	virtual void beforeRemove(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPseudMemberLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoCommitTrigger��ȷ�Ϸǻ�Ա��·ʹ����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoCommitTrigger
{
public:
	///���췽��
	CSysNetPseudMemberLinkInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPseudMemberLinkInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPseudMemberLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetPseudMemberLinkInfo	�Ѿ������SysNetPseudMemberLinkInfo
	virtual void commitAdd(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetPseudMemberLinkInfo	��ˢ�µ�CSysNetPseudMemberLinkInfo
	///@param	poldSysNetPseudMemberLinkInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo, CWriteableSysNetPseudMemberLinkInfo *pOldSysNetPseudMemberLinkInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetPseudMemberLinkInfo	�Ѿ�ɾ����CSysNetPseudMemberLinkInfo
	virtual void commitRemove(CWriteableSysNetPseudMemberLinkInfo *pSysNetPseudMemberLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPseudMemberLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPseudMemberLinkInfoIterator��һ���Էǻ�Ա��·ʹ����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPseudMemberLinkInfoIterator
{
public:
	///���췽��
	CSysNetPseudMemberLinkInfoIterator(void)
	{
	}

	///���췽��
	CSysNetPseudMemberLinkInfoIterator(CSysNetPseudMemberLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPseudMemberLinkInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetPseudMemberLinkInfo
	///@return	��һ����������CSysNetPseudMemberLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPseudMemberLinkInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetPseudMemberLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPseudMemberLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPseudMemberLinkInfo * pSysNetPseudMemberLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetPseudMemberLinkInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetOuterDeviceInfo��һ���洢Զ���豸��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetOuterDeviceInfo
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
		if (! ID.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! NAME.isValid())
			return 0;
		if (! memo.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetOuterDeviceInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///IP��ַ  
	CIPAddressType IPADDR;
	///�豸���� 
	CNetObjectIDType NAME;
	///��ע
	CNetAttrTypeType memo;
	
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

typedef const CWriteableSysNetOuterDeviceInfo CSysNetOuterDeviceInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoActionTrigger�ǲ���Զ���豸��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoActionTrigger
{
public:
	///���췽��
	CSysNetOuterDeviceInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetOuterDeviceInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetOuterDeviceInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetOuterDeviceInfo	Ҫ�����SysNetOuterDeviceInfo
	virtual void beforeAdd(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetOuterDeviceInfo	�Ѿ������SysNetOuterDeviceInfo
	virtual void afterAdd(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetOuterDeviceInfo	��ˢ�µ�CSysNetOuterDeviceInfo
	///@param	pNewSysNetOuterDeviceInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pNewSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetOuterDeviceInfo	��ˢ�µ�CSysNetOuterDeviceInfo
	virtual void afterUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetOuterDeviceInfo	Ҫɾ����CSysNetOuterDeviceInfo
	virtual void beforeRemove(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetOuterDeviceInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoCommitTrigger��ȷ��Զ���豸��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoCommitTrigger
{
public:
	///���췽��
	CSysNetOuterDeviceInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetOuterDeviceInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetOuterDeviceInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetOuterDeviceInfo	�Ѿ������SysNetOuterDeviceInfo
	virtual void commitAdd(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetOuterDeviceInfo	��ˢ�µ�CSysNetOuterDeviceInfo
	///@param	poldSysNetOuterDeviceInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo, CWriteableSysNetOuterDeviceInfo *pOldSysNetOuterDeviceInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetOuterDeviceInfo	�Ѿ�ɾ����CSysNetOuterDeviceInfo
	virtual void commitRemove(CWriteableSysNetOuterDeviceInfo *pSysNetOuterDeviceInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetOuterDeviceInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetOuterDeviceInfoIterator��һ����Զ���豸��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetOuterDeviceInfoIterator
{
public:
	///���췽��
	CSysNetOuterDeviceInfoIterator(void)
	{
	}

	///���췽��
	CSysNetOuterDeviceInfoIterator(CSysNetOuterDeviceInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetOuterDeviceInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetOuterDeviceInfo
	///@return	��һ����������CSysNetOuterDeviceInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetOuterDeviceInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetOuterDeviceInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetOuterDeviceInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetOuterDeviceInfo * pSysNetOuterDeviceInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetOuterDeviceInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysLocalPingResultInfo��һ���洢����ping����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysLocalPingResultInfo
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
		if (! ID.isValid())
			return 0;
		if (! SouIPADDR.isValid())
			return 0;
		if (! SouNAME.isValid())
			return 0;
		if (! TarIPADDR.isValid())
			return 0;
		if (! TarNAME.isValid())
			return 0;
		if (! PDateSta.isValid())
			return 0;
		if (! PTimeSta.isValid())
			return 0;
		if (! ConnRate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysLocalPingResultInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///ԴIP��ַ  
	CIPAddressType SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType TarNAME;
	///��������
	CDateType PDateSta;
	///ʱ���
	CTimeType PTimeSta;
	///��ͨ��
	CVolumeType ConnRate;
	
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

typedef const CWriteableSysLocalPingResultInfo CSysLocalPingResultInfo;

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoActionTrigger�ǲ�������ping���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoActionTrigger
{
public:
	///���췽��
	CSysLocalPingResultInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysLocalPingResultInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysLocalPingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysLocalPingResultInfo	Ҫ�����SysLocalPingResultInfo
	virtual void beforeAdd(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysLocalPingResultInfo	�Ѿ������SysLocalPingResultInfo
	virtual void afterAdd(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysLocalPingResultInfo	��ˢ�µ�CSysLocalPingResultInfo
	///@param	pNewSysLocalPingResultInfo	�µ�ֵ
	virtual void beforeUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pNewSysLocalPingResultInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysLocalPingResultInfo	��ˢ�µ�CSysLocalPingResultInfo
	virtual void afterUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysLocalPingResultInfo	Ҫɾ����CSysLocalPingResultInfo
	virtual void beforeRemove(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysLocalPingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoCommitTrigger��ȷ�ϱ���ping���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoCommitTrigger
{
public:
	///���췽��
	CSysLocalPingResultInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysLocalPingResultInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysLocalPingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysLocalPingResultInfo	�Ѿ������SysLocalPingResultInfo
	virtual void commitAdd(CSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysLocalPingResultInfo	��ˢ�µ�CSysLocalPingResultInfo
	///@param	poldSysLocalPingResultInfo	ԭ����ֵ
	virtual void commitUpdate(CSysLocalPingResultInfo *pSysLocalPingResultInfo, CWriteableSysLocalPingResultInfo *pOldSysLocalPingResultInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysLocalPingResultInfo	�Ѿ�ɾ����CSysLocalPingResultInfo
	virtual void commitRemove(CWriteableSysLocalPingResultInfo *pSysLocalPingResultInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysLocalPingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysLocalPingResultInfoIterator��һ���Ա���ping�����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysLocalPingResultInfoIterator
{
public:
	///���췽��
	CSysLocalPingResultInfoIterator(void)
	{
	}

	///���췽��
	CSysLocalPingResultInfoIterator(CSysLocalPingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysLocalPingResultInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysLocalPingResultInfo
	///@return	��һ����������CSysLocalPingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysLocalPingResultInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysLocalPingResultInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysLocalPingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysLocalPingResultInfo * pSysLocalPingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysLocalPingResultInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysRomotePingResultInfo��һ���洢Զ��ping����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysRomotePingResultInfo
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
		if (! ID.isValid())
			return 0;
		if (! SouIPADDR.isValid())
			return 0;
		if (! SouNAME.isValid())
			return 0;
		if (! TarIPADDR.isValid())
			return 0;
		if (! TarNAME.isValid())
			return 0;
		if (! PDateSta.isValid())
			return 0;
		if (! PTimeSta.isValid())
			return 0;
		if (! ConnRate.isValid())
			return 0;
		if (! TimeDlyMin.isValid())
			return 0;
		if (! TimeDlyMax.isValid())
			return 0;
		if (! TimeDlyAvg.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysRomotePingResultInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///ԴIP��ַ  
	CIPAddressType SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType TarNAME;
	///��������
	CDateType PDateSta;
	///ʱ���
	CTimeType PTimeSta;
	///��ͨ��
	CVolumeType ConnRate;
	///��Сʱ��
	CNetString128Type TimeDlyMin;
	///���ʱ��
	CNetString128Type TimeDlyMax;
	///ƽ��ʱ��
	CNetString128Type TimeDlyAvg;
	
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

typedef const CWriteableSysRomotePingResultInfo CSysRomotePingResultInfo;

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoActionTrigger�ǲ���Զ��ping���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoActionTrigger
{
public:
	///���췽��
	CSysRomotePingResultInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysRomotePingResultInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysRomotePingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysRomotePingResultInfo	Ҫ�����SysRomotePingResultInfo
	virtual void beforeAdd(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysRomotePingResultInfo	�Ѿ������SysRomotePingResultInfo
	virtual void afterAdd(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysRomotePingResultInfo	��ˢ�µ�CSysRomotePingResultInfo
	///@param	pNewSysRomotePingResultInfo	�µ�ֵ
	virtual void beforeUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pNewSysRomotePingResultInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysRomotePingResultInfo	��ˢ�µ�CSysRomotePingResultInfo
	virtual void afterUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysRomotePingResultInfo	Ҫɾ����CSysRomotePingResultInfo
	virtual void beforeRemove(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysRomotePingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoCommitTrigger��ȷ��Զ��ping���ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoCommitTrigger
{
public:
	///���췽��
	CSysRomotePingResultInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysRomotePingResultInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysRomotePingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysRomotePingResultInfo	�Ѿ������SysRomotePingResultInfo
	virtual void commitAdd(CSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysRomotePingResultInfo	��ˢ�µ�CSysRomotePingResultInfo
	///@param	poldSysRomotePingResultInfo	ԭ����ֵ
	virtual void commitUpdate(CSysRomotePingResultInfo *pSysRomotePingResultInfo, CWriteableSysRomotePingResultInfo *pOldSysRomotePingResultInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysRomotePingResultInfo	�Ѿ�ɾ����CSysRomotePingResultInfo
	virtual void commitRemove(CWriteableSysRomotePingResultInfo *pSysRomotePingResultInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysRomotePingResultInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysRomotePingResultInfoIterator��һ����Զ��ping�����ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysRomotePingResultInfoIterator
{
public:
	///���췽��
	CSysRomotePingResultInfoIterator(void)
	{
	}

	///���췽��
	CSysRomotePingResultInfoIterator(CSysRomotePingResultInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysRomotePingResultInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysRomotePingResultInfo
	///@return	��һ����������CSysRomotePingResultInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysRomotePingResultInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysRomotePingResultInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysRomotePingResultInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysRomotePingResultInfo * pSysRomotePingResultInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysRomotePingResultInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysParticTradeOrderStates��һ���洢��Աϯλ����״̬�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysParticTradeOrderStates
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
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! StaticWidth.isValid())
			return 0;
		if (! FrontID.isValid())
			return 0;
		if (! OrderCount.isValid())
			return 0;
		if (! CancleCount.isValid())
			return 0;
		if (! QueryCount.isValid())
			return 0;
		if (! TradeCount.isValid())
			return 0;
		if (! TradeMoney.isValid())
			return 0;
		if (! OrderCntMax.isValid())
			return 0;
		if (! CancleCntMax.isValid())
			return 0;
		if (! QueryCntMax.isValid())
			return 0;
		if (! TradeCntMax.isValid())
			return 0;
		if (! TradeMoneyMax.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysParticTradeOrderStates *pOriginal) const;
	
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
	///����ͳ������
	CDateType MonDate;
	///����ͳ��ʱ��
	CTimeType MonTime;
	///ͳ��ʱ��(sec)
	CVolumeType StaticWidth;
	///ǰ��ID
	CVolumeType FrontID;
	///������
	CVolumeType OrderCount;
	///������
	CVolumeType CancleCount;
	///��ѯ��
	CVolumeType QueryCount;
	///�ɽ���
	CVolumeType TradeCount;
	///�ɽ����
	CVolumeType TradeMoney;
	///��󱨵���
	CVolumeType OrderCntMax;
	///��󳷵���
	CVolumeType CancleCntMax;
	///����ѯ��
	CVolumeType QueryCntMax;
	///���ɽ���
	CVolumeType TradeCntMax;
	///���ɽ����
	CVolumeType TradeMoneyMax;
	
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

typedef const CWriteableSysParticTradeOrderStates CSysParticTradeOrderStates;

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesActionTrigger�ǲ�����Աϯλ����״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesActionTrigger
{
public:
	///���췽��
	CSysParticTradeOrderStatesActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysParticTradeOrderStatesActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysParticTradeOrderStatesFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysParticTradeOrderStates	Ҫ�����SysParticTradeOrderStates
	virtual void beforeAdd(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysParticTradeOrderStates	�Ѿ������SysParticTradeOrderStates
	virtual void afterAdd(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysParticTradeOrderStates	��ˢ�µ�CSysParticTradeOrderStates
	///@param	pNewSysParticTradeOrderStates	�µ�ֵ
	virtual void beforeUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pNewSysParticTradeOrderStates)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysParticTradeOrderStates	��ˢ�µ�CSysParticTradeOrderStates
	virtual void afterUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysParticTradeOrderStates	Ҫɾ����CSysParticTradeOrderStates
	virtual void beforeRemove(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysParticTradeOrderStatesFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesCommitTrigger��ȷ�ϻ�Աϯλ����״̬ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesCommitTrigger
{
public:
	///���췽��
	CSysParticTradeOrderStatesCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysParticTradeOrderStatesCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysParticTradeOrderStatesFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysParticTradeOrderStates	�Ѿ������SysParticTradeOrderStates
	virtual void commitAdd(CSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysParticTradeOrderStates	��ˢ�µ�CSysParticTradeOrderStates
	///@param	poldSysParticTradeOrderStates	ԭ����ֵ
	virtual void commitUpdate(CSysParticTradeOrderStates *pSysParticTradeOrderStates, CWriteableSysParticTradeOrderStates *pOldSysParticTradeOrderStates)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysParticTradeOrderStates	�Ѿ�ɾ����CSysParticTradeOrderStates
	virtual void commitRemove(CWriteableSysParticTradeOrderStates *pSysParticTradeOrderStates)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysParticTradeOrderStatesFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysParticTradeOrderStatesIterator��һ���Ի�Աϯλ����״̬��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysParticTradeOrderStatesIterator
{
public:
	///���췽��
	CSysParticTradeOrderStatesIterator(void)
	{
	}

	///���췽��
	CSysParticTradeOrderStatesIterator(CSysParticTradeOrderStatesFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysParticTradeOrderStatesIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysParticTradeOrderStates
	///@return	��һ����������CSysParticTradeOrderStates������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysParticTradeOrderStates *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysParticTradeOrderStatesFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysParticTradeOrderStates ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysParticTradeOrderStates * pSysParticTradeOrderStates,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysParticTradeOrderStatesFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbRouterInfo��һ���洢ϵͳ·����Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbRouterInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! Dev.isValid())
			return 0;
		if (! Destination.isValid())
			return 0;
		if (! Gateway.isValid())
			return 0;
		if (! Mask.isValid())
			return 0;
		if (! Flag.isValid())
			return 0;
		if (! RefCnt.isValid())
			return 0;
		if (! Use.isValid())
			return 0;
		if (! Metric.isValid())
			return 0;
		if (! Mtu.isValid())
			return 0;
		if (! Win.isValid())
			return 0;
		if (! Rtt.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbRouterInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///�豸�ӿ���
	CTypeCommandType Dev;
	///Ŀ������ip��ַ
	CIPAddressType Destination;
	///����ip��ַ
	CIPAddressType Gateway;
	///����ip��ַ
	CIPAddressType Mask;
	///����״̬
	CTypeLanStatusType Flag;
	///��������
	CVolumeType RefCnt;
	///ʹ�ü���
	CVolumeType Use;
	///metricֵ
	CVolumeType Metric;
	///mtuֵ
	CVolumeType Mtu;
	///winֵ
	CVolumeType Win;
	///rttֵ
	CVolumeType Rtt;
	
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

typedef const CWriteableSysMdbRouterInfo CSysMdbRouterInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoActionTrigger�ǲ���ϵͳ·����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoActionTrigger
{
public:
	///���췽��
	CSysMdbRouterInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbRouterInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbRouterInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbRouterInfo	Ҫ�����SysMdbRouterInfo
	virtual void beforeAdd(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbRouterInfo	�Ѿ������SysMdbRouterInfo
	virtual void afterAdd(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbRouterInfo	��ˢ�µ�CSysMdbRouterInfo
	///@param	pNewSysMdbRouterInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pNewSysMdbRouterInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbRouterInfo	��ˢ�µ�CSysMdbRouterInfo
	virtual void afterUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbRouterInfo	Ҫɾ����CSysMdbRouterInfo
	virtual void beforeRemove(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbRouterInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoCommitTrigger��ȷ��ϵͳ·����Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbRouterInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbRouterInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbRouterInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbRouterInfo	�Ѿ������SysMdbRouterInfo
	virtual void commitAdd(CSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbRouterInfo	��ˢ�µ�CSysMdbRouterInfo
	///@param	poldSysMdbRouterInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbRouterInfo *pSysMdbRouterInfo, CWriteableSysMdbRouterInfo *pOldSysMdbRouterInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbRouterInfo	�Ѿ�ɾ����CSysMdbRouterInfo
	virtual void commitRemove(CWriteableSysMdbRouterInfo *pSysMdbRouterInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbRouterInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbRouterInfoIterator��һ����ϵͳ·����Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbRouterInfoIterator
{
public:
	///���췽��
	CSysMdbRouterInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbRouterInfoIterator(CSysMdbRouterInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbRouterInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbRouterInfo
	///@return	��һ����������CSysMdbRouterInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbRouterInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbRouterInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbRouterInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbRouterInfo * pSysMdbRouterInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbRouterInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbDiskIO��һ���洢����I/O��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbDiskIO
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! PartName.isValid())
			return 0;
		if (! ReadMerges.isValid())
			return 0;
		if (! WriteMerges.isValid())
			return 0;
		if (! ReadIOs.isValid())
			return 0;
		if (! WriteIOs.isValid())
			return 0;
		if (! ReadKBs.isValid())
			return 0;
		if (! WriteKBs.isValid())
			return 0;
		if (! SizeVal.isValid())
			return 0;
		if (! QueueVal.isValid())
			return 0;
		if (! Svc_t.isValid())
			return 0;
		if (! Busy.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbDiskIO *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///������
	CTypeCommandType PartName;
	///ÿ��ReadMerge��
	CPriceType ReadMerges;
	///ÿ��WriteMerge��
	CPriceType WriteMerges;
	///ÿ��ReadIO��
	CPriceType ReadIOs;
	///ÿ��WriteIO��
	CPriceType WriteIOs;
	///ÿ��Read�ֽ���
	CPriceType ReadKBs;
	///ÿ��Write�ֽ���
	CPriceType WriteKBs;
	///Sizeֵ
	CPriceType SizeVal;
	///Queueֵ
	CPriceType QueueVal;
	///Svc_tֵ
	CPriceType Svc_t;
	///��æ�ٷ���
	CRatioType Busy;
	
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

typedef const CWriteableSysMdbDiskIO CSysMdbDiskIO;

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOActionTrigger�ǲ�������I/O��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOActionTrigger
{
public:
	///���췽��
	CSysMdbDiskIOActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbDiskIOActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbDiskIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbDiskIO	Ҫ�����SysMdbDiskIO
	virtual void beforeAdd(CWriteableSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbDiskIO	�Ѿ������SysMdbDiskIO
	virtual void afterAdd(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbDiskIO	��ˢ�µ�CSysMdbDiskIO
	///@param	pNewSysMdbDiskIO	�µ�ֵ
	virtual void beforeUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pNewSysMdbDiskIO)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbDiskIO	��ˢ�µ�CSysMdbDiskIO
	virtual void afterUpdate(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbDiskIO	Ҫɾ����CSysMdbDiskIO
	virtual void beforeRemove(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbDiskIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOCommitTrigger��ȷ�ϴ���I/O��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOCommitTrigger
{
public:
	///���췽��
	CSysMdbDiskIOCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbDiskIOCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbDiskIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbDiskIO	�Ѿ������SysMdbDiskIO
	virtual void commitAdd(CSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbDiskIO	��ˢ�µ�CSysMdbDiskIO
	///@param	poldSysMdbDiskIO	ԭ����ֵ
	virtual void commitUpdate(CSysMdbDiskIO *pSysMdbDiskIO, CWriteableSysMdbDiskIO *pOldSysMdbDiskIO)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbDiskIO	�Ѿ�ɾ����CSysMdbDiskIO
	virtual void commitRemove(CWriteableSysMdbDiskIO *pSysMdbDiskIO)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbDiskIOFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbDiskIOIterator��һ���Դ���I/O��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbDiskIOIterator
{
public:
	///���췽��
	CSysMdbDiskIOIterator(void)
	{
	}

	///���췽��
	CSysMdbDiskIOIterator(CSysMdbDiskIOFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbDiskIOIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbDiskIO
	///@return	��һ����������CSysMdbDiskIO������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbDiskIO *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbDiskIOFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbDiskIO ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbDiskIO * pSysMdbDiskIO,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbDiskIOFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbStatInfo��һ���洢ϵͳ״̬��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbStatInfo
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
		if (! SubcriberID.isValid())
			return 0;
		if (! HostName.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ProcRun.isValid())
			return 0;
		if (! ProcBlk.isValid())
			return 0;
		if (! SwapIn.isValid())
			return 0;
		if (! SwapOut.isValid())
			return 0;
		if (! BlockIn.isValid())
			return 0;
		if (! BlockOut.isValid())
			return 0;
		if (! Inter.isValid())
			return 0;
		if (! Context.isValid())
			return 0;
		if (! CPUUser.isValid())
			return 0;
		if (! CPUSys.isValid())
			return 0;
		if (! CPUIdle.isValid())
			return 0;
		if (! CPUIOWait.isValid())
			return 0;
		if (! CPUSteal.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbStatInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///��������
	CTypeObjectIDType HostName;
	///�ɼ�������
	CDateType MonDate;
	///�ɼ���ʱ��
	CTimeType MonTime;
	///��Ծ������
	CVolumeType ProcRun;
	///����������
	CVolumeType ProcBlk;
	///ÿ���ɴ��̽���Swap��ҳ����
	CVolumeType SwapIn;
	///ÿ����Swap������̵�ҳ����
	CVolumeType SwapOut;
	///ÿ��ӿ��豸�����Block��
	CVolumeType BlockIn;
	///ÿ������豸д���Block��
	CVolumeType BlockOut;
	///ÿ���豸�жδ���
	CVolumeType Inter;
	///ÿ���������л�����
	CVolumeType Context;
	///�û�̬CPU�ٷ���
	CRatioType CPUUser;
	///ϵͳ̬CPU�ٷ���
	CRatioType CPUSys;
	///����̬CPU�ٷ���
	CRatioType CPUIdle;
	///IO�ȴ�̬CPU�ٷ���
	CRatioType CPUIOWait;
	///��ȡ̬CPU�ٷ���
	CRatioType CPUSteal;
	
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

typedef const CWriteableSysMdbStatInfo CSysMdbStatInfo;

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoActionTrigger�ǲ���ϵͳ״̬��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoActionTrigger
{
public:
	///���췽��
	CSysMdbStatInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbStatInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbStatInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbStatInfo	Ҫ�����SysMdbStatInfo
	virtual void beforeAdd(CWriteableSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbStatInfo	�Ѿ������SysMdbStatInfo
	virtual void afterAdd(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbStatInfo	��ˢ�µ�CSysMdbStatInfo
	///@param	pNewSysMdbStatInfo	�µ�ֵ
	virtual void beforeUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pNewSysMdbStatInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbStatInfo	��ˢ�µ�CSysMdbStatInfo
	virtual void afterUpdate(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbStatInfo	Ҫɾ����CSysMdbStatInfo
	virtual void beforeRemove(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbStatInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoCommitTrigger��ȷ��ϵͳ״̬��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoCommitTrigger
{
public:
	///���췽��
	CSysMdbStatInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbStatInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbStatInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbStatInfo	�Ѿ������SysMdbStatInfo
	virtual void commitAdd(CSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbStatInfo	��ˢ�µ�CSysMdbStatInfo
	///@param	poldSysMdbStatInfo	ԭ����ֵ
	virtual void commitUpdate(CSysMdbStatInfo *pSysMdbStatInfo, CWriteableSysMdbStatInfo *pOldSysMdbStatInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbStatInfo	�Ѿ�ɾ����CSysMdbStatInfo
	virtual void commitRemove(CWriteableSysMdbStatInfo *pSysMdbStatInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbStatInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbStatInfoIterator��һ����ϵͳ״̬��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbStatInfoIterator
{
public:
	///���췽��
	CSysMdbStatInfoIterator(void)
	{
	}

	///���췽��
	CSysMdbStatInfoIterator(CSysMdbStatInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbStatInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbStatInfo
	///@return	��һ����������CSysMdbStatInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbStatInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbStatInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbStatInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbStatInfo * pSysMdbStatInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbStatInfoFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMdbTradeFrontOrderRttStat��һ���洢����ϵͳǰ�ñ�����Ӧ��Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMdbTradeFrontOrderRttStat
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
		if (! SubcriberID.isValid())
			return 0;
		if (! MonDate.isValid())
			return 0;
		if (! MonTime.isValid())
			return 0;
		if (! ObjectID.isValid())
			return 0;
		if (! OrderCount.isValid())
			return 0;
		if (! OrderRttSum.isValid())
			return 0;
		if (! OrderMaxRtt.isValid())
			return 0;
		if (! OrderMinRtt.isValid())
			return 0;
		if (! OrderRttSqu.isValid())
			return 0;
		if (! OrderRttCutDistrib.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMdbTradeFrontOrderRttStat *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///���Ķ���ID
	CVolumeType SubcriberID;
	///��������
	CDateType MonDate;
	///����ʱ��
	CTimeType MonTime;
	///ǰ�ö���
	CTypeObjectIDType ObjectID;
	///������
	CLargeNumberType OrderCount;
	///������Ӧʱ���
	CLargeNumberType OrderRttSum;
	///��󱨵���Ӧʱ��
	CVolumeType OrderMaxRtt;
	///��С������Ӧʱ��
	CVolumeType OrderMinRtt;
	///1������Ӧʱ�����
	CVolumeType OrderRttSqu;
	///1������Ӧʱ��ֲ�
	CNumberListsType OrderRttCutDistrib;
	
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

typedef const CWriteableSysMdbTradeFrontOrderRttStat CSysMdbTradeFrontOrderRttStat;

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatActionTrigger�ǲ�������ϵͳǰ�ñ�����Ӧ��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatActionTrigger
{
public:
	///���췽��
	CSysMdbTradeFrontOrderRttStatActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTradeFrontOrderRttStatActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTradeFrontOrderRttStatFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫ�����SysMdbTradeFrontOrderRttStat
	virtual void beforeAdd(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMdbTradeFrontOrderRttStat	�Ѿ������SysMdbTradeFrontOrderRttStat
	virtual void afterAdd(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMdbTradeFrontOrderRttStat	��ˢ�µ�CSysMdbTradeFrontOrderRttStat
	///@param	pNewSysMdbTradeFrontOrderRttStat	�µ�ֵ
	virtual void beforeUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pNewSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMdbTradeFrontOrderRttStat	��ˢ�µ�CSysMdbTradeFrontOrderRttStat
	virtual void afterUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMdbTradeFrontOrderRttStat	Ҫɾ����CSysMdbTradeFrontOrderRttStat
	virtual void beforeRemove(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTradeFrontOrderRttStatFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatCommitTrigger��ȷ�Ͻ���ϵͳǰ�ñ�����Ӧ��Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatCommitTrigger
{
public:
	///���췽��
	CSysMdbTradeFrontOrderRttStatCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMdbTradeFrontOrderRttStatCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMdbTradeFrontOrderRttStatFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMdbTradeFrontOrderRttStat	�Ѿ������SysMdbTradeFrontOrderRttStat
	virtual void commitAdd(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMdbTradeFrontOrderRttStat	��ˢ�µ�CSysMdbTradeFrontOrderRttStat
	///@param	poldSysMdbTradeFrontOrderRttStat	ԭ����ֵ
	virtual void commitUpdate(CSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat, CWriteableSysMdbTradeFrontOrderRttStat *pOldSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMdbTradeFrontOrderRttStat	�Ѿ�ɾ����CSysMdbTradeFrontOrderRttStat
	virtual void commitRemove(CWriteableSysMdbTradeFrontOrderRttStat *pSysMdbTradeFrontOrderRttStat)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMdbTradeFrontOrderRttStatFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMdbTradeFrontOrderRttStatIterator��һ���Խ���ϵͳǰ�ñ�����Ӧ��Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMdbTradeFrontOrderRttStatIterator
{
public:
	///���췽��
	CSysMdbTradeFrontOrderRttStatIterator(void)
	{
	}

	///���췽��
	CSysMdbTradeFrontOrderRttStatIterator(CSysMdbTradeFrontOrderRttStatFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMdbTradeFrontOrderRttStatIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMdbTradeFrontOrderRttStat
	///@return	��һ����������CSysMdbTradeFrontOrderRttStat������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMdbTradeFrontOrderRttStat *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMdbTradeFrontOrderRttStatFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMdbTradeFrontOrderRttStat ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMdbTradeFrontOrderRttStat * pSysMdbTradeFrontOrderRttStat,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMdbTradeFrontOrderRttStatFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysInstrumentStatus��һ���洢��Լ״̬�л��Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysInstrumentStatus
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
		if (! EnterDate.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysInstrumentStatus *pOriginal) const;
	
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
	///���뱾״̬����
	CDateType EnterDate;
	
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

typedef const CWriteableSysInstrumentStatus CSysInstrumentStatus;

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusActionTrigger�ǲ�����Լ״̬�л�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusActionTrigger
{
public:
	///���췽��
	CSysInstrumentStatusActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysInstrumentStatusActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysInstrumentStatus	Ҫ�����SysInstrumentStatus
	virtual void beforeAdd(CWriteableSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysInstrumentStatus	�Ѿ������SysInstrumentStatus
	virtual void afterAdd(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysInstrumentStatus	��ˢ�µ�CSysInstrumentStatus
	///@param	pNewSysInstrumentStatus	�µ�ֵ
	virtual void beforeUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pNewSysInstrumentStatus)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysInstrumentStatus	��ˢ�µ�CSysInstrumentStatus
	virtual void afterUpdate(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysInstrumentStatus	Ҫɾ����CSysInstrumentStatus
	virtual void beforeRemove(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusCommitTrigger��ȷ�Ϻ�Լ״̬�л�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusCommitTrigger
{
public:
	///���췽��
	CSysInstrumentStatusCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysInstrumentStatusCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysInstrumentStatus	�Ѿ������SysInstrumentStatus
	virtual void commitAdd(CSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysInstrumentStatus	��ˢ�µ�CSysInstrumentStatus
	///@param	poldSysInstrumentStatus	ԭ����ֵ
	virtual void commitUpdate(CSysInstrumentStatus *pSysInstrumentStatus, CWriteableSysInstrumentStatus *pOldSysInstrumentStatus)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysInstrumentStatus	�Ѿ�ɾ����CSysInstrumentStatus
	virtual void commitRemove(CWriteableSysInstrumentStatus *pSysInstrumentStatus)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysInstrumentStatusFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysInstrumentStatusIterator��һ���Ժ�Լ״̬�л���ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysInstrumentStatusIterator
{
public:
	///���췽��
	CSysInstrumentStatusIterator(void)
	{
	}

	///���췽��
	CSysInstrumentStatusIterator(CSysInstrumentStatusFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysInstrumentStatusIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysInstrumentStatus
	///@return	��һ����������CSysInstrumentStatus������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysInstrumentStatus *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysInstrumentStatusFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysInstrumentStatus ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysInstrumentStatus * pSysInstrumentStatus,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysInstrumentStatusFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysCurrTradingSegmentAttr��һ���洢��Լ���׽���Ϣ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysCurrTradingSegmentAttr
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
		if (! AdvanceDays.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysCurrTradingSegmentAttr *pOriginal) const;
	
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
	///��ǰ����
	CAdvanceDaysType AdvanceDays;
	
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

typedef const CWriteableSysCurrTradingSegmentAttr CSysCurrTradingSegmentAttr;

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrActionTrigger�ǲ�����Լ���׽���Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrActionTrigger
{
public:
	///���췽��
	CSysCurrTradingSegmentAttrActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysCurrTradingSegmentAttrActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysCurrTradingSegmentAttr	Ҫ�����SysCurrTradingSegmentAttr
	virtual void beforeAdd(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysCurrTradingSegmentAttr	�Ѿ������SysCurrTradingSegmentAttr
	virtual void afterAdd(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysCurrTradingSegmentAttr	��ˢ�µ�CSysCurrTradingSegmentAttr
	///@param	pNewSysCurrTradingSegmentAttr	�µ�ֵ
	virtual void beforeUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pNewSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysCurrTradingSegmentAttr	��ˢ�µ�CSysCurrTradingSegmentAttr
	virtual void afterUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysCurrTradingSegmentAttr	Ҫɾ����CSysCurrTradingSegmentAttr
	virtual void beforeRemove(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrCommitTrigger��ȷ�Ϻ�Լ���׽���Ϣʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrCommitTrigger
{
public:
	///���췽��
	CSysCurrTradingSegmentAttrCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysCurrTradingSegmentAttrCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysCurrTradingSegmentAttr	�Ѿ������SysCurrTradingSegmentAttr
	virtual void commitAdd(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysCurrTradingSegmentAttr	��ˢ�µ�CSysCurrTradingSegmentAttr
	///@param	poldSysCurrTradingSegmentAttr	ԭ����ֵ
	virtual void commitUpdate(CSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr, CWriteableSysCurrTradingSegmentAttr *pOldSysCurrTradingSegmentAttr)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysCurrTradingSegmentAttr	�Ѿ�ɾ����CSysCurrTradingSegmentAttr
	virtual void commitRemove(CWriteableSysCurrTradingSegmentAttr *pSysCurrTradingSegmentAttr)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysCurrTradingSegmentAttrFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysCurrTradingSegmentAttrIterator��һ���Ժ�Լ���׽���Ϣ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysCurrTradingSegmentAttrIterator
{
public:
	///���췽��
	CSysCurrTradingSegmentAttrIterator(void)
	{
	}

	///���췽��
	CSysCurrTradingSegmentAttrIterator(CSysCurrTradingSegmentAttrFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysCurrTradingSegmentAttrIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysCurrTradingSegmentAttr
	///@return	��һ����������CSysCurrTradingSegmentAttr������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysCurrTradingSegmentAttr *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysCurrTradingSegmentAttrFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysCurrTradingSegmentAttr ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysCurrTradingSegmentAttr * pSysCurrTradingSegmentAttr,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysCurrTradingSegmentAttrFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysMemberLinkCost��һ���洢��Ա��·���ñ�Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysMemberLinkCost
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
		if (! ID.isValid())
			return 0;
		if (! ParticipantName.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! ServiceProvider.isValid())
			return 0;
		if (! Pay_Date.isValid())
			return 0;
		if (! B_Pay_Date.isValid())
			return 0;
		if (! D_Pay_Date.isValid())
			return 0;
		if (! Charge.isValid())
			return 0;
		if (! Fee_Type.isValid())
			return 0;
		if (! Pro.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysMemberLinkCost *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��Ա����
	CParticipantNameType ParticipantName;
	///��·���
	CTypeObjectIDType DDN_NO;
	///��Ӫ��
	CCfgNameType ServiceProvider;
	///��������
	CCfgNameType Pay_Date;
	///������ʼ����
	CCfgNameType B_Pay_Date;
	///������ֹ����
	CCfgNameType D_Pay_Date;
	///���
	CVolumeType Charge;
	///��������
	CCfgNameType Fee_Type;
	///��ע
	CPolicyStringTypeType Pro;
	
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

typedef const CWriteableSysMemberLinkCost CSysMemberLinkCost;

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostActionTrigger�ǲ�����Ա��·���ñ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostActionTrigger
{
public:
	///���췽��
	CSysMemberLinkCostActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMemberLinkCostActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMemberLinkCostFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysMemberLinkCost	Ҫ�����SysMemberLinkCost
	virtual void beforeAdd(CWriteableSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysMemberLinkCost	�Ѿ������SysMemberLinkCost
	virtual void afterAdd(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysMemberLinkCost	��ˢ�µ�CSysMemberLinkCost
	///@param	pNewSysMemberLinkCost	�µ�ֵ
	virtual void beforeUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pNewSysMemberLinkCost)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysMemberLinkCost	��ˢ�µ�CSysMemberLinkCost
	virtual void afterUpdate(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysMemberLinkCost	Ҫɾ����CSysMemberLinkCost
	virtual void beforeRemove(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMemberLinkCostFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostCommitTrigger��ȷ�ϻ�Ա��·���ñ�ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostCommitTrigger
{
public:
	///���췽��
	CSysMemberLinkCostCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysMemberLinkCostCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysMemberLinkCostFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysMemberLinkCost	�Ѿ������SysMemberLinkCost
	virtual void commitAdd(CSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysMemberLinkCost	��ˢ�µ�CSysMemberLinkCost
	///@param	poldSysMemberLinkCost	ԭ����ֵ
	virtual void commitUpdate(CSysMemberLinkCost *pSysMemberLinkCost, CWriteableSysMemberLinkCost *pOldSysMemberLinkCost)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysMemberLinkCost	�Ѿ�ɾ����CSysMemberLinkCost
	virtual void commitRemove(CWriteableSysMemberLinkCost *pSysMemberLinkCost)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysMemberLinkCostFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysMemberLinkCostIterator��һ���Ի�Ա��·���ñ��ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysMemberLinkCostIterator
{
public:
	///���췽��
	CSysMemberLinkCostIterator(void)
	{
	}

	///���췽��
	CSysMemberLinkCostIterator(CSysMemberLinkCostFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysMemberLinkCostIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysMemberLinkCost
	///@return	��һ����������CSysMemberLinkCost������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysMemberLinkCost *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysMemberLinkCostFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysMemberLinkCost ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysMemberLinkCost * pSysMemberLinkCost,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysMemberLinkCostFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetPartylinkMonthlyRent��һ���洢��Ա��·�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetPartylinkMonthlyRent
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
		if (! ID.isValid())
			return 0;
		if (! LineName.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! ServiceProvider.isValid())
			return 0;
		if (! MonthlyRental.isValid())
			return 0;
		if (! Remark.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetPartylinkMonthlyRent *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��·����
	CParticipantNameType LineName;
	///��·���
	CTypeObjectIDType DDN_NO;
	///��Ӫ��
	CCfgNameType ServiceProvider;
	///�������
	CLongVolumeType MonthlyRental;
	///��ע
	CNetString128Type Remark;
	
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

typedef const CWriteableSysNetPartylinkMonthlyRent CSysNetPartylinkMonthlyRent;

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentActionTrigger�ǲ�����Ա��·�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentActionTrigger
{
public:
	///���췽��
	CSysNetPartylinkMonthlyRentActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPartylinkMonthlyRentActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPartylinkMonthlyRentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetPartylinkMonthlyRent	Ҫ�����SysNetPartylinkMonthlyRent
	virtual void beforeAdd(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetPartylinkMonthlyRent	�Ѿ������SysNetPartylinkMonthlyRent
	virtual void afterAdd(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetPartylinkMonthlyRent	��ˢ�µ�CSysNetPartylinkMonthlyRent
	///@param	pNewSysNetPartylinkMonthlyRent	�µ�ֵ
	virtual void beforeUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pNewSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetPartylinkMonthlyRent	��ˢ�µ�CSysNetPartylinkMonthlyRent
	virtual void afterUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetPartylinkMonthlyRent	Ҫɾ����CSysNetPartylinkMonthlyRent
	virtual void beforeRemove(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPartylinkMonthlyRentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentCommitTrigger��ȷ�ϻ�Ա��·�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentCommitTrigger
{
public:
	///���췽��
	CSysNetPartylinkMonthlyRentCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetPartylinkMonthlyRentCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetPartylinkMonthlyRentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetPartylinkMonthlyRent	�Ѿ������SysNetPartylinkMonthlyRent
	virtual void commitAdd(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetPartylinkMonthlyRent	��ˢ�µ�CSysNetPartylinkMonthlyRent
	///@param	poldSysNetPartylinkMonthlyRent	ԭ����ֵ
	virtual void commitUpdate(CSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent, CWriteableSysNetPartylinkMonthlyRent *pOldSysNetPartylinkMonthlyRent)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetPartylinkMonthlyRent	�Ѿ�ɾ����CSysNetPartylinkMonthlyRent
	virtual void commitRemove(CWriteableSysNetPartylinkMonthlyRent *pSysNetPartylinkMonthlyRent)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetPartylinkMonthlyRentFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetPartylinkMonthlyRentIterator��һ���Ի�Ա��·������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetPartylinkMonthlyRentIterator
{
public:
	///���췽��
	CSysNetPartylinkMonthlyRentIterator(void)
	{
	}

	///���췽��
	CSysNetPartylinkMonthlyRentIterator(CSysNetPartylinkMonthlyRentFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetPartylinkMonthlyRentIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetPartylinkMonthlyRent
	///@return	��һ����������CSysNetPartylinkMonthlyRent������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetPartylinkMonthlyRent *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetPartylinkMonthlyRentFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetPartylinkMonthlyRent ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetPartylinkMonthlyRent * pSysNetPartylinkMonthlyRent,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetPartylinkMonthlyRentFactory *m_Factory;	
};

/////////////////////////////////////////////////////////////////////////
///CWriteableSysNetNonPartyLinkInfo��һ���洢��Ա��·�����Ķ��󣬿���д����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CWriteableSysNetNonPartyLinkInfo
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
		if (! ID.isValid())
			return 0;
		if (! MEMBER_NO.isValid())
			return 0;
		if (! MEMBER_NAME.isValid())
			return 0;
		if (! REMOTE_ADDR.isValid())
			return 0;
		if (! LOCAL_ADDR.isValid())
			return 0;
		if (! ADDRESS.isValid())
			return 0;
		if (! LINE_STATUS.isValid())
			return 0;
		if (! CONTACT.isValid())
			return 0;
		if (! TELEPHONE.isValid())
			return 0;
		if (! MOBILEPHONE.isValid())
			return 0;
		if (! EMAIL.isValid())
			return 0;
		if (! FAX.isValid())
			return 0;
		if (! PROVINCE.isValid())
			return 0;
		if (! DDN_NO.isValid())
			return 0;
		if (! IN_MODE.isValid())
			return 0;
		if (! IP_WAN.isValid())
			return 0;
		if (! IP_LAN.isValid())
			return 0;
		if (! IPADDR.isValid())
			return 0;
		if (! Interface.isValid())
			return 0;
		if (! INTERFACE_DATE.isValid())
			return 0;
		if (! SOFTWARE.isValid())
			return 0;
		if (! FEE_TYPE.isValid())
			return 0;
		if (! SERVICEPROVIDER.isValid())
			return 0;
		if (! IF_ZIYING.isValid())
			return 0;
		if (! IF_TUOGUAN.isValid())
			return 0;
		if (! HASOTHER.isValid())
			return 0;
		if (! SEAT_NO.isValid())
			return 0;
		if (! PRO.isValid())
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
	void dumpDiff(FILE *fp, const CWriteableSysNetNonPartyLinkInfo *pOriginal) const;
	
	///������д���ļ���һ����,����DEBUG
	///@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp=NULL) const;

	///������д��һ���ַ�����
	///@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

	///ID
	CVolumeType ID;
	///��Ա��
	CCfgNameType MEMBER_NO;
	///��Ա����
	CTypeObjectIDType MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType REMOTE_ADDR;
	///�����������
	CTypeObjectIDType LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType ADDRESS;
	///��·״̬
	CCfgNameType LINE_STATUS;
	///��ϵ��
	CCfgNameType CONTACT;
	///��ϵ�绰
	CTypeObjectIDType TELEPHONE;
	///�ֻ���
	CTypeObjectIDType MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType EMAIL;
	///����
	CTypeObjectIDType FAX;
	///����ʡ��
	CCfgNameType PROVINCE;
	///��·���
	CTypeObjectIDType DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType IN_MODE;
	///����IP����
	CTypeObjectIDType IP_WAN;
	///����IP����
	CTypeObjectIDType IP_LAN;
	///·��������IP
	CTypeObjectIDType IPADDR;
	///·�����˿ں�
	CTypeObjectIDType Interface;
	///�ӿڿ�ͨ����
	CCfgNameType INTERFACE_DATE;
	///�������
	CCfgNameType SOFTWARE;
	///��������
	CCfgNameType FEE_TYPE;
	///��Ӫ��
	CCfgNameType SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType IF_TUOGUAN;
	///����������·
	CCfgNameType HASOTHER;
	///ϯλ��
	CGeneralResultType SEAT_NO;
	///��ע
	CPolicyStringTypeType PRO;
	
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

typedef const CWriteableSysNetNonPartyLinkInfo CSysNetNonPartyLinkInfo;

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoActionTrigger�ǲ�����Ա��·�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoActionTrigger
{
public:
	///���췽��
	CSysNetNonPartyLinkInfoActionTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetNonPartyLinkInfoActionTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetNonPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����ǰ����
	///@param	pSysNetNonPartyLinkInfo	Ҫ�����SysNetNonPartyLinkInfo
	virtual void beforeAdd(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///����󴥷�
	///@param	pSysNetNonPartyLinkInfo	�Ѿ������SysNetNonPartyLinkInfo
	virtual void afterAdd(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}

	///����ǰ����	
	///@param	pSysNetNonPartyLinkInfo	��ˢ�µ�CSysNetNonPartyLinkInfo
	///@param	pNewSysNetNonPartyLinkInfo	�µ�ֵ
	virtual void beforeUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pNewSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///���º󴥷�
	///@param	pSysNetNonPartyLinkInfo	��ˢ�µ�CSysNetNonPartyLinkInfo
	virtual void afterUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///ɾ��ǰ����
	///@param	pSysNetNonPartyLinkInfo	Ҫɾ����CSysNetNonPartyLinkInfo
	virtual void beforeRemove(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetNonPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoCommitTrigger��ȷ�ϻ�Ա��·�����ʱ�Ĵ�����
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoCommitTrigger
{
public:
	///���췽��
	CSysNetNonPartyLinkInfoCommitTrigger(void)
	{
	}
	
	///��������
	virtual ~CSysNetNonPartyLinkInfoCommitTrigger(void)
	{
	}

	///�趨��Ӧ�Ķ��󹤳�
	///@param	pFactory	ָ���Ķ��󹤳�
	void setFactory(CSysNetNonPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///����󴥷�
	///@param	pSysNetNonPartyLinkInfo	�Ѿ������SysNetNonPartyLinkInfo
	virtual void commitAdd(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}

	///���º󴥷�
	///@param	pSysNetNonPartyLinkInfo	��ˢ�µ�CSysNetNonPartyLinkInfo
	///@param	poldSysNetNonPartyLinkInfo	ԭ����ֵ
	virtual void commitUpdate(CSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo, CWriteableSysNetNonPartyLinkInfo *pOldSysNetNonPartyLinkInfo)
	{
		return;
	}
	
	///ɾ���󴥷�
	///@param	pSysNetNonPartyLinkInfo	�Ѿ�ɾ����CSysNetNonPartyLinkInfo
	virtual void commitRemove(CWriteableSysNetNonPartyLinkInfo *pSysNetNonPartyLinkInfo)
	{
		return;
	}
protected:
	///�ô�������Ӧ�Ķ��󹤳�
	CSysNetNonPartyLinkInfoFactory *m_Factory;
};

/////////////////////////////////////////////////////////////////////////
///CSysNetNonPartyLinkInfoIterator��һ���Ի�Ա��·������ö�����ӿ�
///@author	���ض�
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CSysNetNonPartyLinkInfoIterator
{
public:
	///���췽��
	CSysNetNonPartyLinkInfoIterator(void)
	{
	}

	///���췽��
	CSysNetNonPartyLinkInfoIterator(CSysNetNonPartyLinkInfoFactory *pFactory)
	{
		m_Factory=pFactory;
	}

	///�����������������ͷ���ռ�õĿռ�
	virtual ~CSysNetNonPartyLinkInfoIterator(void);
	
	///�ͷ��Լ�
	virtual void free(void)
	{
		delete this;
	}

	///�����һ��SysNetNonPartyLinkInfo
	///@return	��һ����������CSysNetNonPartyLinkInfo������Ѿ�û��һ������Ҫ���ˣ��򷵻�NULL
	virtual CSysNetNonPartyLinkInfo *next(void)=0;
	
	///��ö�Ӧ�Ķ��󹤳�
	///@return	��Ӧ�Ķ��󹤳�
	CSysNetNonPartyLinkInfoFactory *getFactory(void)
	{
		return m_Factory;
	}
	
	///ɾ��Iterator��ǰָ��ļ�¼
	///@param	pTransaction	�˴�ɾ�����ڵ�����NULL��ʾ�������κ���������ִ��
	virtual void DeleteCurrent(CTransaction *pTransaction = NULL) = 0;
	
	///���µ�ǰIteratorָ��ļ�¼
	///@param	pSysNetNonPartyLinkInfo ��Ҫ���³ɵ��¼�¼����
	///@param	pTransaction	�˴θ������ڵ�����NULL��ʾ�������κ���������ִ��
	///@param	updateIndex	true��ʾ��Ҫ����������false��ʾ����Ҫ��������
	virtual void UpdateCurrent(CWriteableSysNetNonPartyLinkInfo * pSysNetNonPartyLinkInfo,CTransaction *pTransaction = NULL, bool updateIndex=true)=0;
	
	///����ö��������������ȫ�����
	///@param	output	Ҫ�����λ��
	void dump(FILE *output);

protected:
	///���в�ѯʱʹ�õĶ��󹤳�
	CSysNetNonPartyLinkInfoFactory *m_Factory;	
};


#include "databaseFactories.h"

#endif


