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
	
	
	
	///��Ч������
	CSysInvalidateOrderFactory *m_SysInvalidateOrderFactory;
	
	///����״̬��
	CSysOrderStatusFactory *m_SysOrderStatusFactory;
	
	///�����ɽ���
	CSysBargainOrderFactory *m_SysBargainOrderFactory;
	
	///��Լ�������Ա�
	CSysInstPropertyFactory *m_SysInstPropertyFactory;
	
	///��Լ��֤���ʱ�
	CSysMarginRateFactory *m_SysMarginRateFactory;
	
	///��Լ�ǵ�ͣ���
	CSysPriceLimitFactory *m_SysPriceLimitFactory;
	
	///��Ա�޲ֱ�
	CSysPartPosiLimitFactory *m_SysPartPosiLimitFactory;
	
	///�ͻ��޲ֱ�
	CSysClientPosiLimitFactory *m_SysClientPosiLimitFactory;
	
	///����ͻ��޲ֱ�
	CSysSpecialPosiLimitFactory *m_SysSpecialPosiLimitFactory;
	
	///�˻�������ѯ��
	CSysTransactionChgFactory *m_SysTransactionChgFactory;
	
	///�ͻ����ݱ䶯��ѯ��
	CSysClientChgFactory *m_SysClientChgFactory;
	
	///��Ա�ͻ����ձ䶯��ѯ��
	CSysPartClientChgFactory *m_SysPartClientChgFactory;
	
	///�޲����ݱ䶯��ѯ��
	CSysPosiLimitChgFactory *m_SysPosiLimitChgFactory;
	
	///�޲����ݱ䶯��ѯ��
	CSysClientPosiLimitChgFactory *m_SysClientPosiLimitChgFactory;
	
	///�޲����ݱ䶯��ѯ��
	CSysSpecPosiLimitChgFactory *m_SysSpecPosiLimitChgFactory;
	
	///��ֵ��ȱ䶯��ѯ��
	CSysHedgeDetailChgFactory *m_SysHedgeDetailChgFactory;
	
	///��Ա�䶯��ѯ��
	CSysParticipantChgFactory *m_SysParticipantChgFactory;
	
	///��֤���ʱ䶯��ѯ��
	CSysMarginRateChgFactory *m_SysMarginRateChgFactory;
	
	///IP��ַ�䶯��ѯ��
	CSysUserIpChgFactory *m_SysUserIpChgFactory;
	
	///��Ա������Ϣ��
	CSysPartTradeFactory *m_SysPartTradeFactory;
	
	///����״ָ̬���
	CSysMdbObjectAttrFactory *m_SysMdbObjectAttrFactory;
	
	///��־�ļ����ݴ�����Ϣ��
	CSysMdbSyslogInfoFactory *m_SysMdbSyslogInfoFactory;
	
	///�û���Ϣ��
	CSysUserInfoFactory *m_SysUserInfoFactory;
	
	///�����û���Ϣ��ѯӦ���
	CSysOnlineUserInfoFactory *m_SysOnlineUserInfoFactory;
	
	///�澯�¼���ѯӦ���
	CSysWarningEventFactory *m_SysWarningEventFactory;
	
	///�澯��ϸӦ���
	CSysWarningQueryFactory *m_SysWarningQueryFactory;
	
	///��־�¼���ѯӦ���
	CSyslogEventFactory *m_SyslogEventFactory;
	
	///�¼�������ѯ��
	CSysEventDescripFactory *m_SysEventDescripFactory;
	
	///����������Ϣ��
	CRspQryHostEnvCommonFactory *m_RspQryHostEnvCommonFactory;
	
	///��������Lan��Ϣ��
	CRspQryHostEnvLanFactory *m_RspQryHostEnvLanFactory;
	
	///���������洢�豸��Ϣ��
	CRspQryHostEnvStorageFactory *m_RspQryHostEnvStorageFactory;
	
	///��������IO�豸��Ϣ��
	CRspQryHostEnvIOFactory *m_RspQryHostEnvIOFactory;
	
	///���������ļ�ϵͳ��Ϣ��
	CRspQryHostEnvFSFactory *m_RspQryHostEnvFSFactory;
	
	///������������������Ϣ��
	CRspQryHostEnvSwapFactory *m_RspQryHostEnvSwapFactory;
	
	///������������������Ϣ��
	CRspQryHostEnvLanCfgFactory *m_RspQryHostEnvLanCfgFactory;
	
	///CPU��Դʹ����Ϣ��
	CSysMdbTopCpuInfoFactory *m_SysMdbTopCpuInfoFactory;
	
	///�ڴ���Դʹ����Ϣ��
	CSysMdbTopMemInfoFactory *m_SysMdbTopMemInfoFactory;
	
	///������Ϣ��
	CSysMdbTopProcessInfoFactory *m_SysMdbTopProcessInfoFactory;
	
	///�ļ�ϵͳ��Ϣ��
	CSysMdbFileSystemInfoFactory *m_SysMdbFileSystemInfoFactory;
	
	///����ʹ����Ϣ��
	CSysMdbNetworkInfoFactory *m_SysMdbNetworkInfoFactory;
	
	///��Ա��
	CSysParticipantInitFactory *m_SysParticipantInitFactory;
	
	///�����û���
	CSysUserInitFactory *m_SysUserInitFactory;
	
	///�ͻ���
	CSysClientInitFactory *m_SysClientInitFactory;
	
	///����ϵͳ��¼��Ϣ��
	CSysTradeUserLoginInfoFactory *m_SysTradeUserLoginInfoFactory;
	
	///WebӦ����Ϣ��
	CSysMdbWebAppInfoFactory *m_SysMdbWebAppInfoFactory;
	
	///ϵͳ�ڴ����Ϣ��
	CSysMdbMemPoolInfoFactory *m_SysMdbMemPoolInfoFactory;
	
	///��������Ϣ��
	CSysMdbConnectorInfoFactory *m_SysMdbConnectorInfoFactory;
	
	///���ݿ��ѯӦ���
	CSysMdbDBQueryFactory *m_SysMdbDBQueryFactory;
	
	///����������ֱ�
	CSysNetAreaFactory *m_SysNetAreaFactory;
	
	///����������
	CSysNetSubAreaFactory *m_SysNetSubAreaFactory;
	
	///��������IP��
	CSysNetSubAreaIPFactory *m_SysNetSubAreaIPFactory;
	
	///ְ������
	CSysNetFuncAreaFactory *m_SysNetFuncAreaFactory;
	
	///�����豸��
	CSysNetDeviceFactory *m_SysNetDeviceFactory;
	
	///�����豸���ӹ�ϵ��
	CSysNetDeviceLinkedFactory *m_SysNetDeviceLinkedFactory;
	
	///OID��
	CSysNetOIDFactory *m_SysNetOIDFactory;
	
	///�����豸���ͱ�
	CSysNetDeviceTypeFactory *m_SysNetDeviceTypeFactory;
	
	///ʱ����Ա�
	CSysNetTimePolicyFactory *m_SysNetTimePolicyFactory;
	
	///�ɼ������
	CSysNetGatherTaskFactory *m_SysNetGatherTaskFactory;
	
	///�����豸����
	CSysNetDeviceCategoryFactory *m_SysNetDeviceCategoryFactory;
	
	///�豸���̱�
	CSysNetManufactoryFactory *m_SysNetManufactoryFactory;
	
	///�豸��ͬ���
	CSysNetCommunityFactory *m_SysNetCommunityFactory;
	
	///�˿����ͱ�
	CSysNetPortTypeFactory *m_SysNetPortTypeFactory;
	
	///�˿ڱ�
	CSysNetInterfaceFactory *m_SysNetInterfaceFactory;
	
	///ͨ��OID��
	CSysNetGeneralOIDFactory *m_SysNetGeneralOIDFactory;
	
	///��ض�������
	CSysNetMonitorTypeFactory *m_SysNetMonitorTypeFactory;
	
	///ָ��ͳ���
	CSysNetMonitorAttrScopeFactory *m_SysNetMonitorAttrScopeFactory;
	
	///���ָ����
	CSysNetMonitorAttrTypeFactory *m_SysNetMonitorAttrTypeFactory;
	
	///���ָ����
	CSysNetMonitorCommandTypeFactory *m_SysNetMonitorCommandTypeFactory;
	
	///��������
	CSysNetMonitorActionGroupFactory *m_SysNetMonitorActionGroupFactory;
	
	///�豸��������
	CSysNetMonitorDeviceGroupFactory *m_SysNetMonitorDeviceGroupFactory;
	
	///������Ϣ���
	CSysNetMonitorTaskInfoFactory *m_SysNetMonitorTaskInfoFactory;
	
	///������󼯱�
	CSysNetMonitorTaskObjectSetFactory *m_SysNetMonitorTaskObjectSetFactory;
	
	///���������
	CSysNetMonitorTaskResultFactory *m_SysNetMonitorTaskResultFactory;
	
	///��Ա��·��Ϣ���
	CSysNetPartyLinkInfoFactory *m_SysNetPartyLinkInfoFactory;
	
	///��Ա��·��Ϣ���
	CSysNetDelPartyLinkInfoFactory *m_SysNetDelPartyLinkInfoFactory;
	
	///��Ա��·��Ϣ���
	CSysNetPartyLinkAddrChangeFactory *m_SysNetPartyLinkAddrChangeFactory;
	
	///��ض���ָ����ձ��
	CSysNetMonitorActionAttrFactory *m_SysNetMonitorActionAttrFactory;
	
	///ģ���
	CSysNetModuleFactory *m_SysNetModuleFactory;
	
	///�澯���ʽ��Ϣ���
	CSysNetEventExprFactory *m_SysNetEventExprFactory;
	
	///�¼����ͱ�
	CSysNetEventTypeFactory *m_SysNetEventTypeFactory;
	
	///�¼������ͱ�
	CSysNetSubEventTypeFactory *m_SysNetSubEventTypeFactory;
	
	///�¼������
	CSysNetEventLevelFactory *m_SysNetEventLevelFactory;
	
	///����������������
	CSysNetMonitorDeviceTaskFactory *m_SysNetMonitorDeviceTaskFactory;
	
	///����ָ��ָ�꼯���
	CSysNetMonitorTaskInstAttrsFactory *m_SysNetMonitorTaskInstAttrsFactory;
	
	///���߱��
	CSysNetBaseLineFactory *m_SysNetBaseLineFactory;
	
	///����������
	CSysNetBaseLineTaskFactory *m_SysNetBaseLineTaskFactory;
	
	///��Ա��·״̬��Ϣ���
	CSysMdbNetPartyLinkStatusInfoFactory *m_SysMdbNetPartyLinkStatusInfoFactory;
	
	///��ԱSDH��·��ϸ���
	CSysNetMemberSDHLineInfoFactory *m_SysNetMemberSDHLineInfoFactory;
	
	///DDN��·��Ϣ���
	CSysNetDDNLinkInfoFactory *m_SysNetDDNLinkInfoFactory;
	
	///�ǻ�Ա��·ʹ����Ϣ��
	CSysNetPseudMemberLinkInfoFactory *m_SysNetPseudMemberLinkInfoFactory;
	
	///Զ���豸��Ϣ��
	CSysNetOuterDeviceInfoFactory *m_SysNetOuterDeviceInfoFactory;
	
	///����ping�����
	CSysLocalPingResultInfoFactory *m_SysLocalPingResultInfoFactory;
	
	///Զ��ping�����
	CSysRomotePingResultInfoFactory *m_SysRomotePingResultInfoFactory;
	
	///��Աϯλ����״̬��
	CSysParticTradeOrderStatesFactory *m_SysParticTradeOrderStatesFactory;
	
	///ϵͳ·����Ϣ��
	CSysMdbRouterInfoFactory *m_SysMdbRouterInfoFactory;
	
	///����I/O��Ϣ��
	CSysMdbDiskIOFactory *m_SysMdbDiskIOFactory;
	
	///ϵͳ״̬��Ϣ��
	CSysMdbStatInfoFactory *m_SysMdbStatInfoFactory;
	
	///����ϵͳǰ�ñ�����Ӧ��Ϣ��
	CSysMdbTradeFrontOrderRttStatFactory *m_SysMdbTradeFrontOrderRttStatFactory;
	
	///��Լ״̬�л���
	CSysInstrumentStatusFactory *m_SysInstrumentStatusFactory;
	
	///��Լ���׽���Ϣ��
	CSysCurrTradingSegmentAttrFactory *m_SysCurrTradingSegmentAttrFactory;
	
	///��Ա��·���ñ��
	CSysMemberLinkCostFactory *m_SysMemberLinkCostFactory;
	
	///��Ա��·������
	CSysNetPartylinkMonthlyRentFactory *m_SysNetPartylinkMonthlyRentFactory;
	
	///��Ա��·������
	CSysNetNonPartyLinkInfoFactory *m_SysNetNonPartyLinkInfoFactory;
	
	///��kernelǿ��ָ�����û�����
	CPasswordType m_ForceUserPassword;
	
private:
	CFixMem *pMem;		///������ű����Ϣ
};

#endif
