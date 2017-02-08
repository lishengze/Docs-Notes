/////////////////////////////////////////////////////////////////////////
///@system 执行引擎系统
///@company 上海期货信息技术有限公司
///@file CMemoryDB.cpp
///@brief实现了类CMemoryDB
///@history 
///20050824	王肇东		创建该文件
///20120111 江鹏		NT-0163 kernel命令行增加指定用户密码参数
/////////////////////////////////////////////////////////////////////////

#include "CMemoryDB.h"
#include <map>
#include <string>
using namespace std;

#define MEMORYDB_ID			0
#define MAX_TABLE_COUNT		300				///引导块中每块放置的内存数据库表或者索引的数量

CMemoryDB::CMemoryDB(void)
{
	m_SysInvalidateOrderFactory=NULL;
	m_SysOrderStatusFactory=NULL;
	m_SysBargainOrderFactory=NULL;
	m_SysInstPropertyFactory=NULL;
	m_SysMarginRateFactory=NULL;
	m_SysPriceLimitFactory=NULL;
	m_SysPartPosiLimitFactory=NULL;
	m_SysClientPosiLimitFactory=NULL;
	m_SysSpecialPosiLimitFactory=NULL;
	m_SysTransactionChgFactory=NULL;
	m_SysClientChgFactory=NULL;
	m_SysPartClientChgFactory=NULL;
	m_SysPosiLimitChgFactory=NULL;
	m_SysClientPosiLimitChgFactory=NULL;
	m_SysSpecPosiLimitChgFactory=NULL;
	m_SysHedgeDetailChgFactory=NULL;
	m_SysParticipantChgFactory=NULL;
	m_SysMarginRateChgFactory=NULL;
	m_SysUserIpChgFactory=NULL;
	m_SysPartTradeFactory=NULL;
	m_SysMdbObjectAttrFactory=NULL;
	m_SysMdbSyslogInfoFactory=NULL;
	m_SysUserInfoFactory=NULL;
	m_SysOnlineUserInfoFactory=NULL;
	m_SysWarningEventFactory=NULL;
	m_SysWarningQueryFactory=NULL;
	m_SyslogEventFactory=NULL;
	m_SysEventDescripFactory=NULL;
	m_RspQryHostEnvCommonFactory=NULL;
	m_RspQryHostEnvLanFactory=NULL;
	m_RspQryHostEnvStorageFactory=NULL;
	m_RspQryHostEnvIOFactory=NULL;
	m_RspQryHostEnvFSFactory=NULL;
	m_RspQryHostEnvSwapFactory=NULL;
	m_RspQryHostEnvLanCfgFactory=NULL;
	m_SysMdbTopCpuInfoFactory=NULL;
	m_SysMdbTopMemInfoFactory=NULL;
	m_SysMdbTopProcessInfoFactory=NULL;
	m_SysMdbFileSystemInfoFactory=NULL;
	m_SysMdbNetworkInfoFactory=NULL;
	m_SysParticipantInitFactory=NULL;
	m_SysUserInitFactory=NULL;
	m_SysClientInitFactory=NULL;
	m_SysTradeUserLoginInfoFactory=NULL;
	m_SysMdbWebAppInfoFactory=NULL;
	m_SysMdbMemPoolInfoFactory=NULL;
	m_SysMdbConnectorInfoFactory=NULL;
	m_SysMdbDBQueryFactory=NULL;
	m_SysNetAreaFactory=NULL;
	m_SysNetSubAreaFactory=NULL;
	m_SysNetSubAreaIPFactory=NULL;
	m_SysNetFuncAreaFactory=NULL;
	m_SysNetDeviceFactory=NULL;
	m_SysNetDeviceLinkedFactory=NULL;
	m_SysNetOIDFactory=NULL;
	m_SysNetDeviceTypeFactory=NULL;
	m_SysNetTimePolicyFactory=NULL;
	m_SysNetGatherTaskFactory=NULL;
	m_SysNetDeviceCategoryFactory=NULL;
	m_SysNetManufactoryFactory=NULL;
	m_SysNetCommunityFactory=NULL;
	m_SysNetPortTypeFactory=NULL;
	m_SysNetInterfaceFactory=NULL;
	m_SysNetGeneralOIDFactory=NULL;
	m_SysNetMonitorTypeFactory=NULL;
	m_SysNetMonitorAttrScopeFactory=NULL;
	m_SysNetMonitorAttrTypeFactory=NULL;
	m_SysNetMonitorCommandTypeFactory=NULL;
	m_SysNetMonitorActionGroupFactory=NULL;
	m_SysNetMonitorDeviceGroupFactory=NULL;
	m_SysNetMonitorTaskInfoFactory=NULL;
	m_SysNetMonitorTaskObjectSetFactory=NULL;
	m_SysNetMonitorTaskResultFactory=NULL;
	m_SysNetPartyLinkInfoFactory=NULL;
	m_SysNetDelPartyLinkInfoFactory=NULL;
	m_SysNetPartyLinkAddrChangeFactory=NULL;
	m_SysNetMonitorActionAttrFactory=NULL;
	m_SysNetModuleFactory=NULL;
	m_SysNetEventExprFactory=NULL;
	m_SysNetEventTypeFactory=NULL;
	m_SysNetSubEventTypeFactory=NULL;
	m_SysNetEventLevelFactory=NULL;
	m_SysNetMonitorDeviceTaskFactory=NULL;
	m_SysNetMonitorTaskInstAttrsFactory=NULL;
	m_SysNetBaseLineFactory=NULL;
	m_SysNetBaseLineTaskFactory=NULL;
	m_SysMdbNetPartyLinkStatusInfoFactory=NULL;
	m_SysNetMemberSDHLineInfoFactory=NULL;
	m_SysNetDDNLinkInfoFactory=NULL;
	m_SysNetPseudMemberLinkInfoFactory=NULL;
	m_SysNetOuterDeviceInfoFactory=NULL;
	m_SysLocalPingResultInfoFactory=NULL;
	m_SysRomotePingResultInfoFactory=NULL;
	m_SysParticTradeOrderStatesFactory=NULL;
	m_SysMdbRouterInfoFactory=NULL;
	m_SysMdbDiskIOFactory=NULL;
	m_SysMdbStatInfoFactory=NULL;
	m_SysMdbTradeFrontOrderRttStatFactory=NULL;
	m_SysInstrumentStatusFactory=NULL;
	m_SysCurrTradingSegmentAttrFactory=NULL;
	m_SysMemberLinkCostFactory=NULL;
	m_SysNetPartylinkMonthlyRentFactory=NULL;
	m_SysNetNonPartyLinkInfoFactory=NULL;
	m_ForceUserPassword.setValue(NULL);
}
	
CMemoryDB::~CMemoryDB(void)
{
	if (m_SysInvalidateOrderFactory!=NULL)
		delete m_SysInvalidateOrderFactory;
	if (m_SysOrderStatusFactory!=NULL)
		delete m_SysOrderStatusFactory;
	if (m_SysBargainOrderFactory!=NULL)
		delete m_SysBargainOrderFactory;
	if (m_SysInstPropertyFactory!=NULL)
		delete m_SysInstPropertyFactory;
	if (m_SysMarginRateFactory!=NULL)
		delete m_SysMarginRateFactory;
	if (m_SysPriceLimitFactory!=NULL)
		delete m_SysPriceLimitFactory;
	if (m_SysPartPosiLimitFactory!=NULL)
		delete m_SysPartPosiLimitFactory;
	if (m_SysClientPosiLimitFactory!=NULL)
		delete m_SysClientPosiLimitFactory;
	if (m_SysSpecialPosiLimitFactory!=NULL)
		delete m_SysSpecialPosiLimitFactory;
	if (m_SysTransactionChgFactory!=NULL)
		delete m_SysTransactionChgFactory;
	if (m_SysClientChgFactory!=NULL)
		delete m_SysClientChgFactory;
	if (m_SysPartClientChgFactory!=NULL)
		delete m_SysPartClientChgFactory;
	if (m_SysPosiLimitChgFactory!=NULL)
		delete m_SysPosiLimitChgFactory;
	if (m_SysClientPosiLimitChgFactory!=NULL)
		delete m_SysClientPosiLimitChgFactory;
	if (m_SysSpecPosiLimitChgFactory!=NULL)
		delete m_SysSpecPosiLimitChgFactory;
	if (m_SysHedgeDetailChgFactory!=NULL)
		delete m_SysHedgeDetailChgFactory;
	if (m_SysParticipantChgFactory!=NULL)
		delete m_SysParticipantChgFactory;
	if (m_SysMarginRateChgFactory!=NULL)
		delete m_SysMarginRateChgFactory;
	if (m_SysUserIpChgFactory!=NULL)
		delete m_SysUserIpChgFactory;
	if (m_SysPartTradeFactory!=NULL)
		delete m_SysPartTradeFactory;
	if (m_SysMdbObjectAttrFactory!=NULL)
		delete m_SysMdbObjectAttrFactory;
	if (m_SysMdbSyslogInfoFactory!=NULL)
		delete m_SysMdbSyslogInfoFactory;
	if (m_SysUserInfoFactory!=NULL)
		delete m_SysUserInfoFactory;
	if (m_SysOnlineUserInfoFactory!=NULL)
		delete m_SysOnlineUserInfoFactory;
	if (m_SysWarningEventFactory!=NULL)
		delete m_SysWarningEventFactory;
	if (m_SysWarningQueryFactory!=NULL)
		delete m_SysWarningQueryFactory;
	if (m_SyslogEventFactory!=NULL)
		delete m_SyslogEventFactory;
	if (m_SysEventDescripFactory!=NULL)
		delete m_SysEventDescripFactory;
	if (m_RspQryHostEnvCommonFactory!=NULL)
		delete m_RspQryHostEnvCommonFactory;
	if (m_RspQryHostEnvLanFactory!=NULL)
		delete m_RspQryHostEnvLanFactory;
	if (m_RspQryHostEnvStorageFactory!=NULL)
		delete m_RspQryHostEnvStorageFactory;
	if (m_RspQryHostEnvIOFactory!=NULL)
		delete m_RspQryHostEnvIOFactory;
	if (m_RspQryHostEnvFSFactory!=NULL)
		delete m_RspQryHostEnvFSFactory;
	if (m_RspQryHostEnvSwapFactory!=NULL)
		delete m_RspQryHostEnvSwapFactory;
	if (m_RspQryHostEnvLanCfgFactory!=NULL)
		delete m_RspQryHostEnvLanCfgFactory;
	if (m_SysMdbTopCpuInfoFactory!=NULL)
		delete m_SysMdbTopCpuInfoFactory;
	if (m_SysMdbTopMemInfoFactory!=NULL)
		delete m_SysMdbTopMemInfoFactory;
	if (m_SysMdbTopProcessInfoFactory!=NULL)
		delete m_SysMdbTopProcessInfoFactory;
	if (m_SysMdbFileSystemInfoFactory!=NULL)
		delete m_SysMdbFileSystemInfoFactory;
	if (m_SysMdbNetworkInfoFactory!=NULL)
		delete m_SysMdbNetworkInfoFactory;
	if (m_SysParticipantInitFactory!=NULL)
		delete m_SysParticipantInitFactory;
	if (m_SysUserInitFactory!=NULL)
		delete m_SysUserInitFactory;
	if (m_SysClientInitFactory!=NULL)
		delete m_SysClientInitFactory;
	if (m_SysTradeUserLoginInfoFactory!=NULL)
		delete m_SysTradeUserLoginInfoFactory;
	if (m_SysMdbWebAppInfoFactory!=NULL)
		delete m_SysMdbWebAppInfoFactory;
	if (m_SysMdbMemPoolInfoFactory!=NULL)
		delete m_SysMdbMemPoolInfoFactory;
	if (m_SysMdbConnectorInfoFactory!=NULL)
		delete m_SysMdbConnectorInfoFactory;
	if (m_SysMdbDBQueryFactory!=NULL)
		delete m_SysMdbDBQueryFactory;
	if (m_SysNetAreaFactory!=NULL)
		delete m_SysNetAreaFactory;
	if (m_SysNetSubAreaFactory!=NULL)
		delete m_SysNetSubAreaFactory;
	if (m_SysNetSubAreaIPFactory!=NULL)
		delete m_SysNetSubAreaIPFactory;
	if (m_SysNetFuncAreaFactory!=NULL)
		delete m_SysNetFuncAreaFactory;
	if (m_SysNetDeviceFactory!=NULL)
		delete m_SysNetDeviceFactory;
	if (m_SysNetDeviceLinkedFactory!=NULL)
		delete m_SysNetDeviceLinkedFactory;
	if (m_SysNetOIDFactory!=NULL)
		delete m_SysNetOIDFactory;
	if (m_SysNetDeviceTypeFactory!=NULL)
		delete m_SysNetDeviceTypeFactory;
	if (m_SysNetTimePolicyFactory!=NULL)
		delete m_SysNetTimePolicyFactory;
	if (m_SysNetGatherTaskFactory!=NULL)
		delete m_SysNetGatherTaskFactory;
	if (m_SysNetDeviceCategoryFactory!=NULL)
		delete m_SysNetDeviceCategoryFactory;
	if (m_SysNetManufactoryFactory!=NULL)
		delete m_SysNetManufactoryFactory;
	if (m_SysNetCommunityFactory!=NULL)
		delete m_SysNetCommunityFactory;
	if (m_SysNetPortTypeFactory!=NULL)
		delete m_SysNetPortTypeFactory;
	if (m_SysNetInterfaceFactory!=NULL)
		delete m_SysNetInterfaceFactory;
	if (m_SysNetGeneralOIDFactory!=NULL)
		delete m_SysNetGeneralOIDFactory;
	if (m_SysNetMonitorTypeFactory!=NULL)
		delete m_SysNetMonitorTypeFactory;
	if (m_SysNetMonitorAttrScopeFactory!=NULL)
		delete m_SysNetMonitorAttrScopeFactory;
	if (m_SysNetMonitorAttrTypeFactory!=NULL)
		delete m_SysNetMonitorAttrTypeFactory;
	if (m_SysNetMonitorCommandTypeFactory!=NULL)
		delete m_SysNetMonitorCommandTypeFactory;
	if (m_SysNetMonitorActionGroupFactory!=NULL)
		delete m_SysNetMonitorActionGroupFactory;
	if (m_SysNetMonitorDeviceGroupFactory!=NULL)
		delete m_SysNetMonitorDeviceGroupFactory;
	if (m_SysNetMonitorTaskInfoFactory!=NULL)
		delete m_SysNetMonitorTaskInfoFactory;
	if (m_SysNetMonitorTaskObjectSetFactory!=NULL)
		delete m_SysNetMonitorTaskObjectSetFactory;
	if (m_SysNetMonitorTaskResultFactory!=NULL)
		delete m_SysNetMonitorTaskResultFactory;
	if (m_SysNetPartyLinkInfoFactory!=NULL)
		delete m_SysNetPartyLinkInfoFactory;
	if (m_SysNetDelPartyLinkInfoFactory!=NULL)
		delete m_SysNetDelPartyLinkInfoFactory;
	if (m_SysNetPartyLinkAddrChangeFactory!=NULL)
		delete m_SysNetPartyLinkAddrChangeFactory;
	if (m_SysNetMonitorActionAttrFactory!=NULL)
		delete m_SysNetMonitorActionAttrFactory;
	if (m_SysNetModuleFactory!=NULL)
		delete m_SysNetModuleFactory;
	if (m_SysNetEventExprFactory!=NULL)
		delete m_SysNetEventExprFactory;
	if (m_SysNetEventTypeFactory!=NULL)
		delete m_SysNetEventTypeFactory;
	if (m_SysNetSubEventTypeFactory!=NULL)
		delete m_SysNetSubEventTypeFactory;
	if (m_SysNetEventLevelFactory!=NULL)
		delete m_SysNetEventLevelFactory;
	if (m_SysNetMonitorDeviceTaskFactory!=NULL)
		delete m_SysNetMonitorDeviceTaskFactory;
	if (m_SysNetMonitorTaskInstAttrsFactory!=NULL)
		delete m_SysNetMonitorTaskInstAttrsFactory;
	if (m_SysNetBaseLineFactory!=NULL)
		delete m_SysNetBaseLineFactory;
	if (m_SysNetBaseLineTaskFactory!=NULL)
		delete m_SysNetBaseLineTaskFactory;
	if (m_SysMdbNetPartyLinkStatusInfoFactory!=NULL)
		delete m_SysMdbNetPartyLinkStatusInfoFactory;
	if (m_SysNetMemberSDHLineInfoFactory!=NULL)
		delete m_SysNetMemberSDHLineInfoFactory;
	if (m_SysNetDDNLinkInfoFactory!=NULL)
		delete m_SysNetDDNLinkInfoFactory;
	if (m_SysNetPseudMemberLinkInfoFactory!=NULL)
		delete m_SysNetPseudMemberLinkInfoFactory;
	if (m_SysNetOuterDeviceInfoFactory!=NULL)
		delete m_SysNetOuterDeviceInfoFactory;
	if (m_SysLocalPingResultInfoFactory!=NULL)
		delete m_SysLocalPingResultInfoFactory;
	if (m_SysRomotePingResultInfoFactory!=NULL)
		delete m_SysRomotePingResultInfoFactory;
	if (m_SysParticTradeOrderStatesFactory!=NULL)
		delete m_SysParticTradeOrderStatesFactory;
	if (m_SysMdbRouterInfoFactory!=NULL)
		delete m_SysMdbRouterInfoFactory;
	if (m_SysMdbDiskIOFactory!=NULL)
		delete m_SysMdbDiskIOFactory;
	if (m_SysMdbStatInfoFactory!=NULL)
		delete m_SysMdbStatInfoFactory;
	if (m_SysMdbTradeFrontOrderRttStatFactory!=NULL)
		delete m_SysMdbTradeFrontOrderRttStatFactory;
	if (m_SysInstrumentStatusFactory!=NULL)
		delete m_SysInstrumentStatusFactory;
	if (m_SysCurrTradingSegmentAttrFactory!=NULL)
		delete m_SysCurrTradingSegmentAttrFactory;
	if (m_SysMemberLinkCostFactory!=NULL)
		delete m_SysMemberLinkCostFactory;
	if (m_SysNetPartylinkMonthlyRentFactory!=NULL)
		delete m_SysNetPartylinkMonthlyRentFactory;
	if (m_SysNetNonPartyLinkInfoFactory!=NULL)
		delete m_SysNetNonPartyLinkInfoFactory;
}
	
int CMemoryDB::isA(char *objectType)
{
	if (!strcmp(objectType,"CMemoryDB"))
		return 1;
	return CBaseObject::isA(objectType);
}

char *CMemoryDB::getType(void)
{
	return "CMemoryDB";
}

void CMemoryDB::output(CLogger *pLogger,int indent)
{
	CHECK_TYPE("CMemoryDB");
	pLogger->output(indent,0,"CMemoryDB:");
	if (m_SysInvalidateOrderFactory!=NULL)
		m_SysInvalidateOrderFactory->output(pLogger,indent+1);
	if (m_SysOrderStatusFactory!=NULL)
		m_SysOrderStatusFactory->output(pLogger,indent+1);
	if (m_SysBargainOrderFactory!=NULL)
		m_SysBargainOrderFactory->output(pLogger,indent+1);
	if (m_SysInstPropertyFactory!=NULL)
		m_SysInstPropertyFactory->output(pLogger,indent+1);
	if (m_SysMarginRateFactory!=NULL)
		m_SysMarginRateFactory->output(pLogger,indent+1);
	if (m_SysPriceLimitFactory!=NULL)
		m_SysPriceLimitFactory->output(pLogger,indent+1);
	if (m_SysPartPosiLimitFactory!=NULL)
		m_SysPartPosiLimitFactory->output(pLogger,indent+1);
	if (m_SysClientPosiLimitFactory!=NULL)
		m_SysClientPosiLimitFactory->output(pLogger,indent+1);
	if (m_SysSpecialPosiLimitFactory!=NULL)
		m_SysSpecialPosiLimitFactory->output(pLogger,indent+1);
	if (m_SysTransactionChgFactory!=NULL)
		m_SysTransactionChgFactory->output(pLogger,indent+1);
	if (m_SysClientChgFactory!=NULL)
		m_SysClientChgFactory->output(pLogger,indent+1);
	if (m_SysPartClientChgFactory!=NULL)
		m_SysPartClientChgFactory->output(pLogger,indent+1);
	if (m_SysPosiLimitChgFactory!=NULL)
		m_SysPosiLimitChgFactory->output(pLogger,indent+1);
	if (m_SysClientPosiLimitChgFactory!=NULL)
		m_SysClientPosiLimitChgFactory->output(pLogger,indent+1);
	if (m_SysSpecPosiLimitChgFactory!=NULL)
		m_SysSpecPosiLimitChgFactory->output(pLogger,indent+1);
	if (m_SysHedgeDetailChgFactory!=NULL)
		m_SysHedgeDetailChgFactory->output(pLogger,indent+1);
	if (m_SysParticipantChgFactory!=NULL)
		m_SysParticipantChgFactory->output(pLogger,indent+1);
	if (m_SysMarginRateChgFactory!=NULL)
		m_SysMarginRateChgFactory->output(pLogger,indent+1);
	if (m_SysUserIpChgFactory!=NULL)
		m_SysUserIpChgFactory->output(pLogger,indent+1);
	if (m_SysPartTradeFactory!=NULL)
		m_SysPartTradeFactory->output(pLogger,indent+1);
	if (m_SysMdbObjectAttrFactory!=NULL)
		m_SysMdbObjectAttrFactory->output(pLogger,indent+1);
	if (m_SysMdbSyslogInfoFactory!=NULL)
		m_SysMdbSyslogInfoFactory->output(pLogger,indent+1);
	if (m_SysUserInfoFactory!=NULL)
		m_SysUserInfoFactory->output(pLogger,indent+1);
	if (m_SysOnlineUserInfoFactory!=NULL)
		m_SysOnlineUserInfoFactory->output(pLogger,indent+1);
	if (m_SysWarningEventFactory!=NULL)
		m_SysWarningEventFactory->output(pLogger,indent+1);
	if (m_SysWarningQueryFactory!=NULL)
		m_SysWarningQueryFactory->output(pLogger,indent+1);
	if (m_SyslogEventFactory!=NULL)
		m_SyslogEventFactory->output(pLogger,indent+1);
	if (m_SysEventDescripFactory!=NULL)
		m_SysEventDescripFactory->output(pLogger,indent+1);
	if (m_RspQryHostEnvCommonFactory!=NULL)
		m_RspQryHostEnvCommonFactory->output(pLogger,indent+1);
	if (m_RspQryHostEnvLanFactory!=NULL)
		m_RspQryHostEnvLanFactory->output(pLogger,indent+1);
	if (m_RspQryHostEnvStorageFactory!=NULL)
		m_RspQryHostEnvStorageFactory->output(pLogger,indent+1);
	if (m_RspQryHostEnvIOFactory!=NULL)
		m_RspQryHostEnvIOFactory->output(pLogger,indent+1);
	if (m_RspQryHostEnvFSFactory!=NULL)
		m_RspQryHostEnvFSFactory->output(pLogger,indent+1);
	if (m_RspQryHostEnvSwapFactory!=NULL)
		m_RspQryHostEnvSwapFactory->output(pLogger,indent+1);
	if (m_RspQryHostEnvLanCfgFactory!=NULL)
		m_RspQryHostEnvLanCfgFactory->output(pLogger,indent+1);
	if (m_SysMdbTopCpuInfoFactory!=NULL)
		m_SysMdbTopCpuInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbTopMemInfoFactory!=NULL)
		m_SysMdbTopMemInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbTopProcessInfoFactory!=NULL)
		m_SysMdbTopProcessInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbFileSystemInfoFactory!=NULL)
		m_SysMdbFileSystemInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbNetworkInfoFactory!=NULL)
		m_SysMdbNetworkInfoFactory->output(pLogger,indent+1);
	if (m_SysParticipantInitFactory!=NULL)
		m_SysParticipantInitFactory->output(pLogger,indent+1);
	if (m_SysUserInitFactory!=NULL)
		m_SysUserInitFactory->output(pLogger,indent+1);
	if (m_SysClientInitFactory!=NULL)
		m_SysClientInitFactory->output(pLogger,indent+1);
	if (m_SysTradeUserLoginInfoFactory!=NULL)
		m_SysTradeUserLoginInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbWebAppInfoFactory!=NULL)
		m_SysMdbWebAppInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbMemPoolInfoFactory!=NULL)
		m_SysMdbMemPoolInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbConnectorInfoFactory!=NULL)
		m_SysMdbConnectorInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbDBQueryFactory!=NULL)
		m_SysMdbDBQueryFactory->output(pLogger,indent+1);
	if (m_SysNetAreaFactory!=NULL)
		m_SysNetAreaFactory->output(pLogger,indent+1);
	if (m_SysNetSubAreaFactory!=NULL)
		m_SysNetSubAreaFactory->output(pLogger,indent+1);
	if (m_SysNetSubAreaIPFactory!=NULL)
		m_SysNetSubAreaIPFactory->output(pLogger,indent+1);
	if (m_SysNetFuncAreaFactory!=NULL)
		m_SysNetFuncAreaFactory->output(pLogger,indent+1);
	if (m_SysNetDeviceFactory!=NULL)
		m_SysNetDeviceFactory->output(pLogger,indent+1);
	if (m_SysNetDeviceLinkedFactory!=NULL)
		m_SysNetDeviceLinkedFactory->output(pLogger,indent+1);
	if (m_SysNetOIDFactory!=NULL)
		m_SysNetOIDFactory->output(pLogger,indent+1);
	if (m_SysNetDeviceTypeFactory!=NULL)
		m_SysNetDeviceTypeFactory->output(pLogger,indent+1);
	if (m_SysNetTimePolicyFactory!=NULL)
		m_SysNetTimePolicyFactory->output(pLogger,indent+1);
	if (m_SysNetGatherTaskFactory!=NULL)
		m_SysNetGatherTaskFactory->output(pLogger,indent+1);
	if (m_SysNetDeviceCategoryFactory!=NULL)
		m_SysNetDeviceCategoryFactory->output(pLogger,indent+1);
	if (m_SysNetManufactoryFactory!=NULL)
		m_SysNetManufactoryFactory->output(pLogger,indent+1);
	if (m_SysNetCommunityFactory!=NULL)
		m_SysNetCommunityFactory->output(pLogger,indent+1);
	if (m_SysNetPortTypeFactory!=NULL)
		m_SysNetPortTypeFactory->output(pLogger,indent+1);
	if (m_SysNetInterfaceFactory!=NULL)
		m_SysNetInterfaceFactory->output(pLogger,indent+1);
	if (m_SysNetGeneralOIDFactory!=NULL)
		m_SysNetGeneralOIDFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorTypeFactory!=NULL)
		m_SysNetMonitorTypeFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorAttrScopeFactory!=NULL)
		m_SysNetMonitorAttrScopeFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorAttrTypeFactory!=NULL)
		m_SysNetMonitorAttrTypeFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorCommandTypeFactory!=NULL)
		m_SysNetMonitorCommandTypeFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorActionGroupFactory!=NULL)
		m_SysNetMonitorActionGroupFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorDeviceGroupFactory!=NULL)
		m_SysNetMonitorDeviceGroupFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorTaskInfoFactory!=NULL)
		m_SysNetMonitorTaskInfoFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorTaskObjectSetFactory!=NULL)
		m_SysNetMonitorTaskObjectSetFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorTaskResultFactory!=NULL)
		m_SysNetMonitorTaskResultFactory->output(pLogger,indent+1);
	if (m_SysNetPartyLinkInfoFactory!=NULL)
		m_SysNetPartyLinkInfoFactory->output(pLogger,indent+1);
	if (m_SysNetDelPartyLinkInfoFactory!=NULL)
		m_SysNetDelPartyLinkInfoFactory->output(pLogger,indent+1);
	if (m_SysNetPartyLinkAddrChangeFactory!=NULL)
		m_SysNetPartyLinkAddrChangeFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorActionAttrFactory!=NULL)
		m_SysNetMonitorActionAttrFactory->output(pLogger,indent+1);
	if (m_SysNetModuleFactory!=NULL)
		m_SysNetModuleFactory->output(pLogger,indent+1);
	if (m_SysNetEventExprFactory!=NULL)
		m_SysNetEventExprFactory->output(pLogger,indent+1);
	if (m_SysNetEventTypeFactory!=NULL)
		m_SysNetEventTypeFactory->output(pLogger,indent+1);
	if (m_SysNetSubEventTypeFactory!=NULL)
		m_SysNetSubEventTypeFactory->output(pLogger,indent+1);
	if (m_SysNetEventLevelFactory!=NULL)
		m_SysNetEventLevelFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorDeviceTaskFactory!=NULL)
		m_SysNetMonitorDeviceTaskFactory->output(pLogger,indent+1);
	if (m_SysNetMonitorTaskInstAttrsFactory!=NULL)
		m_SysNetMonitorTaskInstAttrsFactory->output(pLogger,indent+1);
	if (m_SysNetBaseLineFactory!=NULL)
		m_SysNetBaseLineFactory->output(pLogger,indent+1);
	if (m_SysNetBaseLineTaskFactory!=NULL)
		m_SysNetBaseLineTaskFactory->output(pLogger,indent+1);
	if (m_SysMdbNetPartyLinkStatusInfoFactory!=NULL)
		m_SysMdbNetPartyLinkStatusInfoFactory->output(pLogger,indent+1);
	if (m_SysNetMemberSDHLineInfoFactory!=NULL)
		m_SysNetMemberSDHLineInfoFactory->output(pLogger,indent+1);
	if (m_SysNetDDNLinkInfoFactory!=NULL)
		m_SysNetDDNLinkInfoFactory->output(pLogger,indent+1);
	if (m_SysNetPseudMemberLinkInfoFactory!=NULL)
		m_SysNetPseudMemberLinkInfoFactory->output(pLogger,indent+1);
	if (m_SysNetOuterDeviceInfoFactory!=NULL)
		m_SysNetOuterDeviceInfoFactory->output(pLogger,indent+1);
	if (m_SysLocalPingResultInfoFactory!=NULL)
		m_SysLocalPingResultInfoFactory->output(pLogger,indent+1);
	if (m_SysRomotePingResultInfoFactory!=NULL)
		m_SysRomotePingResultInfoFactory->output(pLogger,indent+1);
	if (m_SysParticTradeOrderStatesFactory!=NULL)
		m_SysParticTradeOrderStatesFactory->output(pLogger,indent+1);
	if (m_SysMdbRouterInfoFactory!=NULL)
		m_SysMdbRouterInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbDiskIOFactory!=NULL)
		m_SysMdbDiskIOFactory->output(pLogger,indent+1);
	if (m_SysMdbStatInfoFactory!=NULL)
		m_SysMdbStatInfoFactory->output(pLogger,indent+1);
	if (m_SysMdbTradeFrontOrderRttStatFactory!=NULL)
		m_SysMdbTradeFrontOrderRttStatFactory->output(pLogger,indent+1);
	if (m_SysInstrumentStatusFactory!=NULL)
		m_SysInstrumentStatusFactory->output(pLogger,indent+1);
	if (m_SysCurrTradingSegmentAttrFactory!=NULL)
		m_SysCurrTradingSegmentAttrFactory->output(pLogger,indent+1);
	if (m_SysMemberLinkCostFactory!=NULL)
		m_SysMemberLinkCostFactory->output(pLogger,indent+1);
	if (m_SysNetPartylinkMonthlyRentFactory!=NULL)
		m_SysNetPartylinkMonthlyRentFactory->output(pLogger,indent+1);
	if (m_SysNetNonPartyLinkInfoFactory!=NULL)
		m_SysNetNonPartyLinkInfoFactory->output(pLogger,indent+1);
}

int CMemoryDB::init(CConfig *pConfig,IMemoryAllocator *pAllocator,bool reuse)
{
	if(pAllocator == NULL)
	{
		pAllocator = new CNormalMemoryAllocator();
		pAllocator->init(reuse);
	}
	if(!reuse)
	{
		map<string,int> indexMap;
		pMem=new CFixMem(sizeof(TableStruct),MAX_TABLE_COUNT,pAllocator,false,MEMORYDB_ID);
		TableStruct* pStru = NULL;
		
		m_SysInvalidateOrderFactory=new CSysInvalidateOrderFactory(pConfig,pAllocator,&indexMap);
		if (m_SysInvalidateOrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysInvalidateOrder");
		pStru->reuseID = m_SysInvalidateOrderFactory->getReuseID();
				
		m_SysOrderStatusFactory=new CSysOrderStatusFactory(pConfig,pAllocator,&indexMap);
		if (m_SysOrderStatusFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysOrderStatus");
		pStru->reuseID = m_SysOrderStatusFactory->getReuseID();
				
		m_SysBargainOrderFactory=new CSysBargainOrderFactory(pConfig,pAllocator,&indexMap);
		if (m_SysBargainOrderFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysBargainOrder");
		pStru->reuseID = m_SysBargainOrderFactory->getReuseID();
				
		m_SysInstPropertyFactory=new CSysInstPropertyFactory(pConfig,pAllocator,&indexMap);
		if (m_SysInstPropertyFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysInstProperty");
		pStru->reuseID = m_SysInstPropertyFactory->getReuseID();
				
		m_SysMarginRateFactory=new CSysMarginRateFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMarginRateFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMarginRate");
		pStru->reuseID = m_SysMarginRateFactory->getReuseID();
				
		m_SysPriceLimitFactory=new CSysPriceLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_SysPriceLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysPriceLimit");
		pStru->reuseID = m_SysPriceLimitFactory->getReuseID();
				
		m_SysPartPosiLimitFactory=new CSysPartPosiLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_SysPartPosiLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysPartPosiLimit");
		pStru->reuseID = m_SysPartPosiLimitFactory->getReuseID();
				
		m_SysClientPosiLimitFactory=new CSysClientPosiLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_SysClientPosiLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysClientPosiLimit");
		pStru->reuseID = m_SysClientPosiLimitFactory->getReuseID();
				
		m_SysSpecialPosiLimitFactory=new CSysSpecialPosiLimitFactory(pConfig,pAllocator,&indexMap);
		if (m_SysSpecialPosiLimitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysSpecialPosiLimit");
		pStru->reuseID = m_SysSpecialPosiLimitFactory->getReuseID();
				
		m_SysTransactionChgFactory=new CSysTransactionChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysTransactionChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysTransactionChg");
		pStru->reuseID = m_SysTransactionChgFactory->getReuseID();
				
		m_SysClientChgFactory=new CSysClientChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysClientChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysClientChg");
		pStru->reuseID = m_SysClientChgFactory->getReuseID();
				
		m_SysPartClientChgFactory=new CSysPartClientChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysPartClientChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysPartClientChg");
		pStru->reuseID = m_SysPartClientChgFactory->getReuseID();
				
		m_SysPosiLimitChgFactory=new CSysPosiLimitChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysPosiLimitChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysPosiLimitChg");
		pStru->reuseID = m_SysPosiLimitChgFactory->getReuseID();
				
		m_SysClientPosiLimitChgFactory=new CSysClientPosiLimitChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysClientPosiLimitChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysClientPosiLimitChg");
		pStru->reuseID = m_SysClientPosiLimitChgFactory->getReuseID();
				
		m_SysSpecPosiLimitChgFactory=new CSysSpecPosiLimitChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysSpecPosiLimitChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysSpecPosiLimitChg");
		pStru->reuseID = m_SysSpecPosiLimitChgFactory->getReuseID();
				
		m_SysHedgeDetailChgFactory=new CSysHedgeDetailChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysHedgeDetailChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysHedgeDetailChg");
		pStru->reuseID = m_SysHedgeDetailChgFactory->getReuseID();
				
		m_SysParticipantChgFactory=new CSysParticipantChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysParticipantChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysParticipantChg");
		pStru->reuseID = m_SysParticipantChgFactory->getReuseID();
				
		m_SysMarginRateChgFactory=new CSysMarginRateChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMarginRateChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMarginRateChg");
		pStru->reuseID = m_SysMarginRateChgFactory->getReuseID();
				
		m_SysUserIpChgFactory=new CSysUserIpChgFactory(pConfig,pAllocator,&indexMap);
		if (m_SysUserIpChgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysUserIpChg");
		pStru->reuseID = m_SysUserIpChgFactory->getReuseID();
				
		m_SysPartTradeFactory=new CSysPartTradeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysPartTradeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysPartTrade");
		pStru->reuseID = m_SysPartTradeFactory->getReuseID();
				
		m_SysMdbObjectAttrFactory=new CSysMdbObjectAttrFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbObjectAttrFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbObjectAttr");
		pStru->reuseID = m_SysMdbObjectAttrFactory->getReuseID();
				
		m_SysMdbSyslogInfoFactory=new CSysMdbSyslogInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbSyslogInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbSyslogInfo");
		pStru->reuseID = m_SysMdbSyslogInfoFactory->getReuseID();
				
		m_SysUserInfoFactory=new CSysUserInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysUserInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysUserInfo");
		pStru->reuseID = m_SysUserInfoFactory->getReuseID();
				
		m_SysOnlineUserInfoFactory=new CSysOnlineUserInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysOnlineUserInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysOnlineUserInfo");
		pStru->reuseID = m_SysOnlineUserInfoFactory->getReuseID();
				
		m_SysWarningEventFactory=new CSysWarningEventFactory(pConfig,pAllocator,&indexMap);
		if (m_SysWarningEventFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysWarningEvent");
		pStru->reuseID = m_SysWarningEventFactory->getReuseID();
				
		m_SysWarningQueryFactory=new CSysWarningQueryFactory(pConfig,pAllocator,&indexMap);
		if (m_SysWarningQueryFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysWarningQuery");
		pStru->reuseID = m_SysWarningQueryFactory->getReuseID();
				
		m_SyslogEventFactory=new CSyslogEventFactory(pConfig,pAllocator,&indexMap);
		if (m_SyslogEventFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SyslogEvent");
		pStru->reuseID = m_SyslogEventFactory->getReuseID();
				
		m_SysEventDescripFactory=new CSysEventDescripFactory(pConfig,pAllocator,&indexMap);
		if (m_SysEventDescripFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysEventDescrip");
		pStru->reuseID = m_SysEventDescripFactory->getReuseID();
				
		m_RspQryHostEnvCommonFactory=new CRspQryHostEnvCommonFactory(pConfig,pAllocator,&indexMap);
		if (m_RspQryHostEnvCommonFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RspQryHostEnvCommon");
		pStru->reuseID = m_RspQryHostEnvCommonFactory->getReuseID();
				
		m_RspQryHostEnvLanFactory=new CRspQryHostEnvLanFactory(pConfig,pAllocator,&indexMap);
		if (m_RspQryHostEnvLanFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RspQryHostEnvLan");
		pStru->reuseID = m_RspQryHostEnvLanFactory->getReuseID();
				
		m_RspQryHostEnvStorageFactory=new CRspQryHostEnvStorageFactory(pConfig,pAllocator,&indexMap);
		if (m_RspQryHostEnvStorageFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RspQryHostEnvStorage");
		pStru->reuseID = m_RspQryHostEnvStorageFactory->getReuseID();
				
		m_RspQryHostEnvIOFactory=new CRspQryHostEnvIOFactory(pConfig,pAllocator,&indexMap);
		if (m_RspQryHostEnvIOFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RspQryHostEnvIO");
		pStru->reuseID = m_RspQryHostEnvIOFactory->getReuseID();
				
		m_RspQryHostEnvFSFactory=new CRspQryHostEnvFSFactory(pConfig,pAllocator,&indexMap);
		if (m_RspQryHostEnvFSFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RspQryHostEnvFS");
		pStru->reuseID = m_RspQryHostEnvFSFactory->getReuseID();
				
		m_RspQryHostEnvSwapFactory=new CRspQryHostEnvSwapFactory(pConfig,pAllocator,&indexMap);
		if (m_RspQryHostEnvSwapFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RspQryHostEnvSwap");
		pStru->reuseID = m_RspQryHostEnvSwapFactory->getReuseID();
				
		m_RspQryHostEnvLanCfgFactory=new CRspQryHostEnvLanCfgFactory(pConfig,pAllocator,&indexMap);
		if (m_RspQryHostEnvLanCfgFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"RspQryHostEnvLanCfg");
		pStru->reuseID = m_RspQryHostEnvLanCfgFactory->getReuseID();
				
		m_SysMdbTopCpuInfoFactory=new CSysMdbTopCpuInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbTopCpuInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbTopCpuInfo");
		pStru->reuseID = m_SysMdbTopCpuInfoFactory->getReuseID();
				
		m_SysMdbTopMemInfoFactory=new CSysMdbTopMemInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbTopMemInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbTopMemInfo");
		pStru->reuseID = m_SysMdbTopMemInfoFactory->getReuseID();
				
		m_SysMdbTopProcessInfoFactory=new CSysMdbTopProcessInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbTopProcessInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbTopProcessInfo");
		pStru->reuseID = m_SysMdbTopProcessInfoFactory->getReuseID();
				
		m_SysMdbFileSystemInfoFactory=new CSysMdbFileSystemInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbFileSystemInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbFileSystemInfo");
		pStru->reuseID = m_SysMdbFileSystemInfoFactory->getReuseID();
				
		m_SysMdbNetworkInfoFactory=new CSysMdbNetworkInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbNetworkInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbNetworkInfo");
		pStru->reuseID = m_SysMdbNetworkInfoFactory->getReuseID();
				
		m_SysParticipantInitFactory=new CSysParticipantInitFactory(pConfig,pAllocator,&indexMap);
		if (m_SysParticipantInitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysParticipantInit");
		pStru->reuseID = m_SysParticipantInitFactory->getReuseID();
				
		m_SysUserInitFactory=new CSysUserInitFactory(pConfig,pAllocator,&indexMap);
		if (m_SysUserInitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysUserInit");
		pStru->reuseID = m_SysUserInitFactory->getReuseID();
				
		m_SysClientInitFactory=new CSysClientInitFactory(pConfig,pAllocator,&indexMap);
		if (m_SysClientInitFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysClientInit");
		pStru->reuseID = m_SysClientInitFactory->getReuseID();
				
		m_SysTradeUserLoginInfoFactory=new CSysTradeUserLoginInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysTradeUserLoginInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysTradeUserLoginInfo");
		pStru->reuseID = m_SysTradeUserLoginInfoFactory->getReuseID();
				
		m_SysMdbWebAppInfoFactory=new CSysMdbWebAppInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbWebAppInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbWebAppInfo");
		pStru->reuseID = m_SysMdbWebAppInfoFactory->getReuseID();
				
		m_SysMdbMemPoolInfoFactory=new CSysMdbMemPoolInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbMemPoolInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbMemPoolInfo");
		pStru->reuseID = m_SysMdbMemPoolInfoFactory->getReuseID();
				
		m_SysMdbConnectorInfoFactory=new CSysMdbConnectorInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbConnectorInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbConnectorInfo");
		pStru->reuseID = m_SysMdbConnectorInfoFactory->getReuseID();
				
		m_SysMdbDBQueryFactory=new CSysMdbDBQueryFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbDBQueryFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbDBQuery");
		pStru->reuseID = m_SysMdbDBQueryFactory->getReuseID();
				
		m_SysNetAreaFactory=new CSysNetAreaFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetAreaFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetArea");
		pStru->reuseID = m_SysNetAreaFactory->getReuseID();
				
		m_SysNetSubAreaFactory=new CSysNetSubAreaFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetSubAreaFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetSubArea");
		pStru->reuseID = m_SysNetSubAreaFactory->getReuseID();
				
		m_SysNetSubAreaIPFactory=new CSysNetSubAreaIPFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetSubAreaIPFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetSubAreaIP");
		pStru->reuseID = m_SysNetSubAreaIPFactory->getReuseID();
				
		m_SysNetFuncAreaFactory=new CSysNetFuncAreaFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetFuncAreaFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetFuncArea");
		pStru->reuseID = m_SysNetFuncAreaFactory->getReuseID();
				
		m_SysNetDeviceFactory=new CSysNetDeviceFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetDeviceFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetDevice");
		pStru->reuseID = m_SysNetDeviceFactory->getReuseID();
				
		m_SysNetDeviceLinkedFactory=new CSysNetDeviceLinkedFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetDeviceLinkedFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetDeviceLinked");
		pStru->reuseID = m_SysNetDeviceLinkedFactory->getReuseID();
				
		m_SysNetOIDFactory=new CSysNetOIDFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetOIDFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetOID");
		pStru->reuseID = m_SysNetOIDFactory->getReuseID();
				
		m_SysNetDeviceTypeFactory=new CSysNetDeviceTypeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetDeviceTypeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetDeviceType");
		pStru->reuseID = m_SysNetDeviceTypeFactory->getReuseID();
				
		m_SysNetTimePolicyFactory=new CSysNetTimePolicyFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetTimePolicyFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetTimePolicy");
		pStru->reuseID = m_SysNetTimePolicyFactory->getReuseID();
				
		m_SysNetGatherTaskFactory=new CSysNetGatherTaskFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetGatherTaskFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetGatherTask");
		pStru->reuseID = m_SysNetGatherTaskFactory->getReuseID();
				
		m_SysNetDeviceCategoryFactory=new CSysNetDeviceCategoryFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetDeviceCategoryFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetDeviceCategory");
		pStru->reuseID = m_SysNetDeviceCategoryFactory->getReuseID();
				
		m_SysNetManufactoryFactory=new CSysNetManufactoryFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetManufactoryFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetManufactory");
		pStru->reuseID = m_SysNetManufactoryFactory->getReuseID();
				
		m_SysNetCommunityFactory=new CSysNetCommunityFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetCommunityFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetCommunity");
		pStru->reuseID = m_SysNetCommunityFactory->getReuseID();
				
		m_SysNetPortTypeFactory=new CSysNetPortTypeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetPortTypeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetPortType");
		pStru->reuseID = m_SysNetPortTypeFactory->getReuseID();
				
		m_SysNetInterfaceFactory=new CSysNetInterfaceFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetInterfaceFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetInterface");
		pStru->reuseID = m_SysNetInterfaceFactory->getReuseID();
				
		m_SysNetGeneralOIDFactory=new CSysNetGeneralOIDFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetGeneralOIDFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetGeneralOID");
		pStru->reuseID = m_SysNetGeneralOIDFactory->getReuseID();
				
		m_SysNetMonitorTypeFactory=new CSysNetMonitorTypeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorTypeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorType");
		pStru->reuseID = m_SysNetMonitorTypeFactory->getReuseID();
				
		m_SysNetMonitorAttrScopeFactory=new CSysNetMonitorAttrScopeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorAttrScopeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorAttrScope");
		pStru->reuseID = m_SysNetMonitorAttrScopeFactory->getReuseID();
				
		m_SysNetMonitorAttrTypeFactory=new CSysNetMonitorAttrTypeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorAttrTypeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorAttrType");
		pStru->reuseID = m_SysNetMonitorAttrTypeFactory->getReuseID();
				
		m_SysNetMonitorCommandTypeFactory=new CSysNetMonitorCommandTypeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorCommandTypeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorCommandType");
		pStru->reuseID = m_SysNetMonitorCommandTypeFactory->getReuseID();
				
		m_SysNetMonitorActionGroupFactory=new CSysNetMonitorActionGroupFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorActionGroupFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorActionGroup");
		pStru->reuseID = m_SysNetMonitorActionGroupFactory->getReuseID();
				
		m_SysNetMonitorDeviceGroupFactory=new CSysNetMonitorDeviceGroupFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorDeviceGroupFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorDeviceGroup");
		pStru->reuseID = m_SysNetMonitorDeviceGroupFactory->getReuseID();
				
		m_SysNetMonitorTaskInfoFactory=new CSysNetMonitorTaskInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorTaskInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorTaskInfo");
		pStru->reuseID = m_SysNetMonitorTaskInfoFactory->getReuseID();
				
		m_SysNetMonitorTaskObjectSetFactory=new CSysNetMonitorTaskObjectSetFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorTaskObjectSetFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorTaskObjectSet");
		pStru->reuseID = m_SysNetMonitorTaskObjectSetFactory->getReuseID();
				
		m_SysNetMonitorTaskResultFactory=new CSysNetMonitorTaskResultFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorTaskResultFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorTaskResult");
		pStru->reuseID = m_SysNetMonitorTaskResultFactory->getReuseID();
				
		m_SysNetPartyLinkInfoFactory=new CSysNetPartyLinkInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetPartyLinkInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetPartyLinkInfo");
		pStru->reuseID = m_SysNetPartyLinkInfoFactory->getReuseID();
				
		m_SysNetDelPartyLinkInfoFactory=new CSysNetDelPartyLinkInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetDelPartyLinkInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetDelPartyLinkInfo");
		pStru->reuseID = m_SysNetDelPartyLinkInfoFactory->getReuseID();
				
		m_SysNetPartyLinkAddrChangeFactory=new CSysNetPartyLinkAddrChangeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetPartyLinkAddrChangeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetPartyLinkAddrChange");
		pStru->reuseID = m_SysNetPartyLinkAddrChangeFactory->getReuseID();
				
		m_SysNetMonitorActionAttrFactory=new CSysNetMonitorActionAttrFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorActionAttrFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorActionAttr");
		pStru->reuseID = m_SysNetMonitorActionAttrFactory->getReuseID();
				
		m_SysNetModuleFactory=new CSysNetModuleFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetModuleFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetModule");
		pStru->reuseID = m_SysNetModuleFactory->getReuseID();
				
		m_SysNetEventExprFactory=new CSysNetEventExprFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetEventExprFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetEventExpr");
		pStru->reuseID = m_SysNetEventExprFactory->getReuseID();
				
		m_SysNetEventTypeFactory=new CSysNetEventTypeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetEventTypeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetEventType");
		pStru->reuseID = m_SysNetEventTypeFactory->getReuseID();
				
		m_SysNetSubEventTypeFactory=new CSysNetSubEventTypeFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetSubEventTypeFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetSubEventType");
		pStru->reuseID = m_SysNetSubEventTypeFactory->getReuseID();
				
		m_SysNetEventLevelFactory=new CSysNetEventLevelFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetEventLevelFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetEventLevel");
		pStru->reuseID = m_SysNetEventLevelFactory->getReuseID();
				
		m_SysNetMonitorDeviceTaskFactory=new CSysNetMonitorDeviceTaskFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorDeviceTaskFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorDeviceTask");
		pStru->reuseID = m_SysNetMonitorDeviceTaskFactory->getReuseID();
				
		m_SysNetMonitorTaskInstAttrsFactory=new CSysNetMonitorTaskInstAttrsFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMonitorTaskInstAttrsFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMonitorTaskInstAttrs");
		pStru->reuseID = m_SysNetMonitorTaskInstAttrsFactory->getReuseID();
				
		m_SysNetBaseLineFactory=new CSysNetBaseLineFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetBaseLineFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetBaseLine");
		pStru->reuseID = m_SysNetBaseLineFactory->getReuseID();
				
		m_SysNetBaseLineTaskFactory=new CSysNetBaseLineTaskFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetBaseLineTaskFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetBaseLineTask");
		pStru->reuseID = m_SysNetBaseLineTaskFactory->getReuseID();
				
		m_SysMdbNetPartyLinkStatusInfoFactory=new CSysMdbNetPartyLinkStatusInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbNetPartyLinkStatusInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbNetPartyLinkStatusInfo");
		pStru->reuseID = m_SysMdbNetPartyLinkStatusInfoFactory->getReuseID();
				
		m_SysNetMemberSDHLineInfoFactory=new CSysNetMemberSDHLineInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetMemberSDHLineInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetMemberSDHLineInfo");
		pStru->reuseID = m_SysNetMemberSDHLineInfoFactory->getReuseID();
				
		m_SysNetDDNLinkInfoFactory=new CSysNetDDNLinkInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetDDNLinkInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetDDNLinkInfo");
		pStru->reuseID = m_SysNetDDNLinkInfoFactory->getReuseID();
				
		m_SysNetPseudMemberLinkInfoFactory=new CSysNetPseudMemberLinkInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetPseudMemberLinkInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetPseudMemberLinkInfo");
		pStru->reuseID = m_SysNetPseudMemberLinkInfoFactory->getReuseID();
				
		m_SysNetOuterDeviceInfoFactory=new CSysNetOuterDeviceInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetOuterDeviceInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetOuterDeviceInfo");
		pStru->reuseID = m_SysNetOuterDeviceInfoFactory->getReuseID();
				
		m_SysLocalPingResultInfoFactory=new CSysLocalPingResultInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysLocalPingResultInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysLocalPingResultInfo");
		pStru->reuseID = m_SysLocalPingResultInfoFactory->getReuseID();
				
		m_SysRomotePingResultInfoFactory=new CSysRomotePingResultInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysRomotePingResultInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysRomotePingResultInfo");
		pStru->reuseID = m_SysRomotePingResultInfoFactory->getReuseID();
				
		m_SysParticTradeOrderStatesFactory=new CSysParticTradeOrderStatesFactory(pConfig,pAllocator,&indexMap);
		if (m_SysParticTradeOrderStatesFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysParticTradeOrderStates");
		pStru->reuseID = m_SysParticTradeOrderStatesFactory->getReuseID();
				
		m_SysMdbRouterInfoFactory=new CSysMdbRouterInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbRouterInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbRouterInfo");
		pStru->reuseID = m_SysMdbRouterInfoFactory->getReuseID();
				
		m_SysMdbDiskIOFactory=new CSysMdbDiskIOFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbDiskIOFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbDiskIO");
		pStru->reuseID = m_SysMdbDiskIOFactory->getReuseID();
				
		m_SysMdbStatInfoFactory=new CSysMdbStatInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbStatInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbStatInfo");
		pStru->reuseID = m_SysMdbStatInfoFactory->getReuseID();
				
		m_SysMdbTradeFrontOrderRttStatFactory=new CSysMdbTradeFrontOrderRttStatFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMdbTradeFrontOrderRttStatFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMdbTradeFrontOrderRttStat");
		pStru->reuseID = m_SysMdbTradeFrontOrderRttStatFactory->getReuseID();
				
		m_SysInstrumentStatusFactory=new CSysInstrumentStatusFactory(pConfig,pAllocator,&indexMap);
		if (m_SysInstrumentStatusFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysInstrumentStatus");
		pStru->reuseID = m_SysInstrumentStatusFactory->getReuseID();
				
		m_SysCurrTradingSegmentAttrFactory=new CSysCurrTradingSegmentAttrFactory(pConfig,pAllocator,&indexMap);
		if (m_SysCurrTradingSegmentAttrFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysCurrTradingSegmentAttr");
		pStru->reuseID = m_SysCurrTradingSegmentAttrFactory->getReuseID();
				
		m_SysMemberLinkCostFactory=new CSysMemberLinkCostFactory(pConfig,pAllocator,&indexMap);
		if (m_SysMemberLinkCostFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysMemberLinkCost");
		pStru->reuseID = m_SysMemberLinkCostFactory->getReuseID();
				
		m_SysNetPartylinkMonthlyRentFactory=new CSysNetPartylinkMonthlyRentFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetPartylinkMonthlyRentFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetPartylinkMonthlyRent");
		pStru->reuseID = m_SysNetPartylinkMonthlyRentFactory->getReuseID();
				
		m_SysNetNonPartyLinkInfoFactory=new CSysNetNonPartyLinkInfoFactory(pConfig,pAllocator,&indexMap);
		if (m_SysNetNonPartyLinkInfoFactory==NULL)
			return 0;
		pStru = (TableStruct *)pMem->alloc();
		strcpy(pStru->tableName,"SysNetNonPartyLinkInfo");
		pStru->reuseID = m_SysNetNonPartyLinkInfoFactory->getReuseID();
				
	
		map<string,int>::iterator it = indexMap.begin();
		for(;it!=indexMap.end();it++)
		{
			pStru = (TableStruct *)pMem->alloc();
			strcpy(pStru->tableName,it->first.c_str());
			pStru->reuseID = it->second;
		}
	}
	else
	{
		pMem=new CFixMem(sizeof(TableStruct),MAX_TABLE_COUNT,pAllocator,true,MEMORYDB_ID);
		map<string,int> blockMap;
		TableStruct* pStru = NULL;
		for(int i=0;i<pMem->getCount();i++)
		{
			pStru = (TableStruct *)pMem->getObject(i);
			blockMap.insert(map<string,int>::value_type(pStru->tableName,pStru->reuseID));
		}
		map<string,int>::iterator it;
			
		it = blockMap.find("SysInvalidateOrder");
		if(it == blockMap.end())
			m_SysInvalidateOrderFactory=new CSysInvalidateOrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysInvalidateOrderFactory=new CSysInvalidateOrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysInvalidateOrderFactory==NULL)
			return 0;
				
		it = blockMap.find("SysOrderStatus");
		if(it == blockMap.end())
			m_SysOrderStatusFactory=new CSysOrderStatusFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysOrderStatusFactory=new CSysOrderStatusFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysOrderStatusFactory==NULL)
			return 0;
				
		it = blockMap.find("SysBargainOrder");
		if(it == blockMap.end())
			m_SysBargainOrderFactory=new CSysBargainOrderFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysBargainOrderFactory=new CSysBargainOrderFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysBargainOrderFactory==NULL)
			return 0;
				
		it = blockMap.find("SysInstProperty");
		if(it == blockMap.end())
			m_SysInstPropertyFactory=new CSysInstPropertyFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysInstPropertyFactory=new CSysInstPropertyFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysInstPropertyFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMarginRate");
		if(it == blockMap.end())
			m_SysMarginRateFactory=new CSysMarginRateFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMarginRateFactory=new CSysMarginRateFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMarginRateFactory==NULL)
			return 0;
				
		it = blockMap.find("SysPriceLimit");
		if(it == blockMap.end())
			m_SysPriceLimitFactory=new CSysPriceLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysPriceLimitFactory=new CSysPriceLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysPriceLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("SysPartPosiLimit");
		if(it == blockMap.end())
			m_SysPartPosiLimitFactory=new CSysPartPosiLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysPartPosiLimitFactory=new CSysPartPosiLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysPartPosiLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("SysClientPosiLimit");
		if(it == blockMap.end())
			m_SysClientPosiLimitFactory=new CSysClientPosiLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysClientPosiLimitFactory=new CSysClientPosiLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysClientPosiLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("SysSpecialPosiLimit");
		if(it == blockMap.end())
			m_SysSpecialPosiLimitFactory=new CSysSpecialPosiLimitFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysSpecialPosiLimitFactory=new CSysSpecialPosiLimitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysSpecialPosiLimitFactory==NULL)
			return 0;
				
		it = blockMap.find("SysTransactionChg");
		if(it == blockMap.end())
			m_SysTransactionChgFactory=new CSysTransactionChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysTransactionChgFactory=new CSysTransactionChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysTransactionChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysClientChg");
		if(it == blockMap.end())
			m_SysClientChgFactory=new CSysClientChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysClientChgFactory=new CSysClientChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysClientChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysPartClientChg");
		if(it == blockMap.end())
			m_SysPartClientChgFactory=new CSysPartClientChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysPartClientChgFactory=new CSysPartClientChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysPartClientChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysPosiLimitChg");
		if(it == blockMap.end())
			m_SysPosiLimitChgFactory=new CSysPosiLimitChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysPosiLimitChgFactory=new CSysPosiLimitChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysPosiLimitChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysClientPosiLimitChg");
		if(it == blockMap.end())
			m_SysClientPosiLimitChgFactory=new CSysClientPosiLimitChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysClientPosiLimitChgFactory=new CSysClientPosiLimitChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysClientPosiLimitChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysSpecPosiLimitChg");
		if(it == blockMap.end())
			m_SysSpecPosiLimitChgFactory=new CSysSpecPosiLimitChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysSpecPosiLimitChgFactory=new CSysSpecPosiLimitChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysSpecPosiLimitChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysHedgeDetailChg");
		if(it == blockMap.end())
			m_SysHedgeDetailChgFactory=new CSysHedgeDetailChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysHedgeDetailChgFactory=new CSysHedgeDetailChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysHedgeDetailChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysParticipantChg");
		if(it == blockMap.end())
			m_SysParticipantChgFactory=new CSysParticipantChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysParticipantChgFactory=new CSysParticipantChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysParticipantChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMarginRateChg");
		if(it == blockMap.end())
			m_SysMarginRateChgFactory=new CSysMarginRateChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMarginRateChgFactory=new CSysMarginRateChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMarginRateChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysUserIpChg");
		if(it == blockMap.end())
			m_SysUserIpChgFactory=new CSysUserIpChgFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysUserIpChgFactory=new CSysUserIpChgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysUserIpChgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysPartTrade");
		if(it == blockMap.end())
			m_SysPartTradeFactory=new CSysPartTradeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysPartTradeFactory=new CSysPartTradeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysPartTradeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbObjectAttr");
		if(it == blockMap.end())
			m_SysMdbObjectAttrFactory=new CSysMdbObjectAttrFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbObjectAttrFactory=new CSysMdbObjectAttrFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbObjectAttrFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbSyslogInfo");
		if(it == blockMap.end())
			m_SysMdbSyslogInfoFactory=new CSysMdbSyslogInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbSyslogInfoFactory=new CSysMdbSyslogInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbSyslogInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysUserInfo");
		if(it == blockMap.end())
			m_SysUserInfoFactory=new CSysUserInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysUserInfoFactory=new CSysUserInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysUserInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysOnlineUserInfo");
		if(it == blockMap.end())
			m_SysOnlineUserInfoFactory=new CSysOnlineUserInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysOnlineUserInfoFactory=new CSysOnlineUserInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysOnlineUserInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysWarningEvent");
		if(it == blockMap.end())
			m_SysWarningEventFactory=new CSysWarningEventFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysWarningEventFactory=new CSysWarningEventFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysWarningEventFactory==NULL)
			return 0;
				
		it = blockMap.find("SysWarningQuery");
		if(it == blockMap.end())
			m_SysWarningQueryFactory=new CSysWarningQueryFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysWarningQueryFactory=new CSysWarningQueryFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysWarningQueryFactory==NULL)
			return 0;
				
		it = blockMap.find("SyslogEvent");
		if(it == blockMap.end())
			m_SyslogEventFactory=new CSyslogEventFactory(pConfig,pAllocator,&blockMap);
		else
			m_SyslogEventFactory=new CSyslogEventFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SyslogEventFactory==NULL)
			return 0;
				
		it = blockMap.find("SysEventDescrip");
		if(it == blockMap.end())
			m_SysEventDescripFactory=new CSysEventDescripFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysEventDescripFactory=new CSysEventDescripFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysEventDescripFactory==NULL)
			return 0;
				
		it = blockMap.find("RspQryHostEnvCommon");
		if(it == blockMap.end())
			m_RspQryHostEnvCommonFactory=new CRspQryHostEnvCommonFactory(pConfig,pAllocator,&blockMap);
		else
			m_RspQryHostEnvCommonFactory=new CRspQryHostEnvCommonFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RspQryHostEnvCommonFactory==NULL)
			return 0;
				
		it = blockMap.find("RspQryHostEnvLan");
		if(it == blockMap.end())
			m_RspQryHostEnvLanFactory=new CRspQryHostEnvLanFactory(pConfig,pAllocator,&blockMap);
		else
			m_RspQryHostEnvLanFactory=new CRspQryHostEnvLanFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RspQryHostEnvLanFactory==NULL)
			return 0;
				
		it = blockMap.find("RspQryHostEnvStorage");
		if(it == blockMap.end())
			m_RspQryHostEnvStorageFactory=new CRspQryHostEnvStorageFactory(pConfig,pAllocator,&blockMap);
		else
			m_RspQryHostEnvStorageFactory=new CRspQryHostEnvStorageFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RspQryHostEnvStorageFactory==NULL)
			return 0;
				
		it = blockMap.find("RspQryHostEnvIO");
		if(it == blockMap.end())
			m_RspQryHostEnvIOFactory=new CRspQryHostEnvIOFactory(pConfig,pAllocator,&blockMap);
		else
			m_RspQryHostEnvIOFactory=new CRspQryHostEnvIOFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RspQryHostEnvIOFactory==NULL)
			return 0;
				
		it = blockMap.find("RspQryHostEnvFS");
		if(it == blockMap.end())
			m_RspQryHostEnvFSFactory=new CRspQryHostEnvFSFactory(pConfig,pAllocator,&blockMap);
		else
			m_RspQryHostEnvFSFactory=new CRspQryHostEnvFSFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RspQryHostEnvFSFactory==NULL)
			return 0;
				
		it = blockMap.find("RspQryHostEnvSwap");
		if(it == blockMap.end())
			m_RspQryHostEnvSwapFactory=new CRspQryHostEnvSwapFactory(pConfig,pAllocator,&blockMap);
		else
			m_RspQryHostEnvSwapFactory=new CRspQryHostEnvSwapFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RspQryHostEnvSwapFactory==NULL)
			return 0;
				
		it = blockMap.find("RspQryHostEnvLanCfg");
		if(it == blockMap.end())
			m_RspQryHostEnvLanCfgFactory=new CRspQryHostEnvLanCfgFactory(pConfig,pAllocator,&blockMap);
		else
			m_RspQryHostEnvLanCfgFactory=new CRspQryHostEnvLanCfgFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_RspQryHostEnvLanCfgFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbTopCpuInfo");
		if(it == blockMap.end())
			m_SysMdbTopCpuInfoFactory=new CSysMdbTopCpuInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbTopCpuInfoFactory=new CSysMdbTopCpuInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbTopCpuInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbTopMemInfo");
		if(it == blockMap.end())
			m_SysMdbTopMemInfoFactory=new CSysMdbTopMemInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbTopMemInfoFactory=new CSysMdbTopMemInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbTopMemInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbTopProcessInfo");
		if(it == blockMap.end())
			m_SysMdbTopProcessInfoFactory=new CSysMdbTopProcessInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbTopProcessInfoFactory=new CSysMdbTopProcessInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbTopProcessInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbFileSystemInfo");
		if(it == blockMap.end())
			m_SysMdbFileSystemInfoFactory=new CSysMdbFileSystemInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbFileSystemInfoFactory=new CSysMdbFileSystemInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbFileSystemInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbNetworkInfo");
		if(it == blockMap.end())
			m_SysMdbNetworkInfoFactory=new CSysMdbNetworkInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbNetworkInfoFactory=new CSysMdbNetworkInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbNetworkInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysParticipantInit");
		if(it == blockMap.end())
			m_SysParticipantInitFactory=new CSysParticipantInitFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysParticipantInitFactory=new CSysParticipantInitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysParticipantInitFactory==NULL)
			return 0;
				
		it = blockMap.find("SysUserInit");
		if(it == blockMap.end())
			m_SysUserInitFactory=new CSysUserInitFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysUserInitFactory=new CSysUserInitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysUserInitFactory==NULL)
			return 0;
				
		it = blockMap.find("SysClientInit");
		if(it == blockMap.end())
			m_SysClientInitFactory=new CSysClientInitFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysClientInitFactory=new CSysClientInitFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysClientInitFactory==NULL)
			return 0;
				
		it = blockMap.find("SysTradeUserLoginInfo");
		if(it == blockMap.end())
			m_SysTradeUserLoginInfoFactory=new CSysTradeUserLoginInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysTradeUserLoginInfoFactory=new CSysTradeUserLoginInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysTradeUserLoginInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbWebAppInfo");
		if(it == blockMap.end())
			m_SysMdbWebAppInfoFactory=new CSysMdbWebAppInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbWebAppInfoFactory=new CSysMdbWebAppInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbWebAppInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbMemPoolInfo");
		if(it == blockMap.end())
			m_SysMdbMemPoolInfoFactory=new CSysMdbMemPoolInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbMemPoolInfoFactory=new CSysMdbMemPoolInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbMemPoolInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbConnectorInfo");
		if(it == blockMap.end())
			m_SysMdbConnectorInfoFactory=new CSysMdbConnectorInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbConnectorInfoFactory=new CSysMdbConnectorInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbConnectorInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbDBQuery");
		if(it == blockMap.end())
			m_SysMdbDBQueryFactory=new CSysMdbDBQueryFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbDBQueryFactory=new CSysMdbDBQueryFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbDBQueryFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetArea");
		if(it == blockMap.end())
			m_SysNetAreaFactory=new CSysNetAreaFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetAreaFactory=new CSysNetAreaFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetAreaFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetSubArea");
		if(it == blockMap.end())
			m_SysNetSubAreaFactory=new CSysNetSubAreaFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetSubAreaFactory=new CSysNetSubAreaFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetSubAreaFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetSubAreaIP");
		if(it == blockMap.end())
			m_SysNetSubAreaIPFactory=new CSysNetSubAreaIPFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetSubAreaIPFactory=new CSysNetSubAreaIPFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetSubAreaIPFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetFuncArea");
		if(it == blockMap.end())
			m_SysNetFuncAreaFactory=new CSysNetFuncAreaFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetFuncAreaFactory=new CSysNetFuncAreaFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetFuncAreaFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetDevice");
		if(it == blockMap.end())
			m_SysNetDeviceFactory=new CSysNetDeviceFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetDeviceFactory=new CSysNetDeviceFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetDeviceFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetDeviceLinked");
		if(it == blockMap.end())
			m_SysNetDeviceLinkedFactory=new CSysNetDeviceLinkedFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetDeviceLinkedFactory=new CSysNetDeviceLinkedFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetDeviceLinkedFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetOID");
		if(it == blockMap.end())
			m_SysNetOIDFactory=new CSysNetOIDFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetOIDFactory=new CSysNetOIDFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetOIDFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetDeviceType");
		if(it == blockMap.end())
			m_SysNetDeviceTypeFactory=new CSysNetDeviceTypeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetDeviceTypeFactory=new CSysNetDeviceTypeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetDeviceTypeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetTimePolicy");
		if(it == blockMap.end())
			m_SysNetTimePolicyFactory=new CSysNetTimePolicyFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetTimePolicyFactory=new CSysNetTimePolicyFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetTimePolicyFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetGatherTask");
		if(it == blockMap.end())
			m_SysNetGatherTaskFactory=new CSysNetGatherTaskFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetGatherTaskFactory=new CSysNetGatherTaskFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetGatherTaskFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetDeviceCategory");
		if(it == blockMap.end())
			m_SysNetDeviceCategoryFactory=new CSysNetDeviceCategoryFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetDeviceCategoryFactory=new CSysNetDeviceCategoryFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetDeviceCategoryFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetManufactory");
		if(it == blockMap.end())
			m_SysNetManufactoryFactory=new CSysNetManufactoryFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetManufactoryFactory=new CSysNetManufactoryFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetManufactoryFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetCommunity");
		if(it == blockMap.end())
			m_SysNetCommunityFactory=new CSysNetCommunityFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetCommunityFactory=new CSysNetCommunityFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetCommunityFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetPortType");
		if(it == blockMap.end())
			m_SysNetPortTypeFactory=new CSysNetPortTypeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetPortTypeFactory=new CSysNetPortTypeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetPortTypeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetInterface");
		if(it == blockMap.end())
			m_SysNetInterfaceFactory=new CSysNetInterfaceFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetInterfaceFactory=new CSysNetInterfaceFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetInterfaceFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetGeneralOID");
		if(it == blockMap.end())
			m_SysNetGeneralOIDFactory=new CSysNetGeneralOIDFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetGeneralOIDFactory=new CSysNetGeneralOIDFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetGeneralOIDFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorType");
		if(it == blockMap.end())
			m_SysNetMonitorTypeFactory=new CSysNetMonitorTypeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorTypeFactory=new CSysNetMonitorTypeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorTypeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorAttrScope");
		if(it == blockMap.end())
			m_SysNetMonitorAttrScopeFactory=new CSysNetMonitorAttrScopeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorAttrScopeFactory=new CSysNetMonitorAttrScopeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorAttrScopeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorAttrType");
		if(it == blockMap.end())
			m_SysNetMonitorAttrTypeFactory=new CSysNetMonitorAttrTypeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorAttrTypeFactory=new CSysNetMonitorAttrTypeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorAttrTypeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorCommandType");
		if(it == blockMap.end())
			m_SysNetMonitorCommandTypeFactory=new CSysNetMonitorCommandTypeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorCommandTypeFactory=new CSysNetMonitorCommandTypeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorCommandTypeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorActionGroup");
		if(it == blockMap.end())
			m_SysNetMonitorActionGroupFactory=new CSysNetMonitorActionGroupFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorActionGroupFactory=new CSysNetMonitorActionGroupFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorActionGroupFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorDeviceGroup");
		if(it == blockMap.end())
			m_SysNetMonitorDeviceGroupFactory=new CSysNetMonitorDeviceGroupFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorDeviceGroupFactory=new CSysNetMonitorDeviceGroupFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorDeviceGroupFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorTaskInfo");
		if(it == blockMap.end())
			m_SysNetMonitorTaskInfoFactory=new CSysNetMonitorTaskInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorTaskInfoFactory=new CSysNetMonitorTaskInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorTaskInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorTaskObjectSet");
		if(it == blockMap.end())
			m_SysNetMonitorTaskObjectSetFactory=new CSysNetMonitorTaskObjectSetFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorTaskObjectSetFactory=new CSysNetMonitorTaskObjectSetFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorTaskObjectSetFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorTaskResult");
		if(it == blockMap.end())
			m_SysNetMonitorTaskResultFactory=new CSysNetMonitorTaskResultFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorTaskResultFactory=new CSysNetMonitorTaskResultFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorTaskResultFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetPartyLinkInfo");
		if(it == blockMap.end())
			m_SysNetPartyLinkInfoFactory=new CSysNetPartyLinkInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetPartyLinkInfoFactory=new CSysNetPartyLinkInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetPartyLinkInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetDelPartyLinkInfo");
		if(it == blockMap.end())
			m_SysNetDelPartyLinkInfoFactory=new CSysNetDelPartyLinkInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetDelPartyLinkInfoFactory=new CSysNetDelPartyLinkInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetDelPartyLinkInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetPartyLinkAddrChange");
		if(it == blockMap.end())
			m_SysNetPartyLinkAddrChangeFactory=new CSysNetPartyLinkAddrChangeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetPartyLinkAddrChangeFactory=new CSysNetPartyLinkAddrChangeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetPartyLinkAddrChangeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorActionAttr");
		if(it == blockMap.end())
			m_SysNetMonitorActionAttrFactory=new CSysNetMonitorActionAttrFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorActionAttrFactory=new CSysNetMonitorActionAttrFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorActionAttrFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetModule");
		if(it == blockMap.end())
			m_SysNetModuleFactory=new CSysNetModuleFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetModuleFactory=new CSysNetModuleFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetModuleFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetEventExpr");
		if(it == blockMap.end())
			m_SysNetEventExprFactory=new CSysNetEventExprFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetEventExprFactory=new CSysNetEventExprFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetEventExprFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetEventType");
		if(it == blockMap.end())
			m_SysNetEventTypeFactory=new CSysNetEventTypeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetEventTypeFactory=new CSysNetEventTypeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetEventTypeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetSubEventType");
		if(it == blockMap.end())
			m_SysNetSubEventTypeFactory=new CSysNetSubEventTypeFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetSubEventTypeFactory=new CSysNetSubEventTypeFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetSubEventTypeFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetEventLevel");
		if(it == blockMap.end())
			m_SysNetEventLevelFactory=new CSysNetEventLevelFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetEventLevelFactory=new CSysNetEventLevelFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetEventLevelFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorDeviceTask");
		if(it == blockMap.end())
			m_SysNetMonitorDeviceTaskFactory=new CSysNetMonitorDeviceTaskFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorDeviceTaskFactory=new CSysNetMonitorDeviceTaskFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorDeviceTaskFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMonitorTaskInstAttrs");
		if(it == blockMap.end())
			m_SysNetMonitorTaskInstAttrsFactory=new CSysNetMonitorTaskInstAttrsFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMonitorTaskInstAttrsFactory=new CSysNetMonitorTaskInstAttrsFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMonitorTaskInstAttrsFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetBaseLine");
		if(it == blockMap.end())
			m_SysNetBaseLineFactory=new CSysNetBaseLineFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetBaseLineFactory=new CSysNetBaseLineFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetBaseLineFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetBaseLineTask");
		if(it == blockMap.end())
			m_SysNetBaseLineTaskFactory=new CSysNetBaseLineTaskFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetBaseLineTaskFactory=new CSysNetBaseLineTaskFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetBaseLineTaskFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbNetPartyLinkStatusInfo");
		if(it == blockMap.end())
			m_SysMdbNetPartyLinkStatusInfoFactory=new CSysMdbNetPartyLinkStatusInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbNetPartyLinkStatusInfoFactory=new CSysMdbNetPartyLinkStatusInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbNetPartyLinkStatusInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetMemberSDHLineInfo");
		if(it == blockMap.end())
			m_SysNetMemberSDHLineInfoFactory=new CSysNetMemberSDHLineInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetMemberSDHLineInfoFactory=new CSysNetMemberSDHLineInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetMemberSDHLineInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetDDNLinkInfo");
		if(it == blockMap.end())
			m_SysNetDDNLinkInfoFactory=new CSysNetDDNLinkInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetDDNLinkInfoFactory=new CSysNetDDNLinkInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetDDNLinkInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetPseudMemberLinkInfo");
		if(it == blockMap.end())
			m_SysNetPseudMemberLinkInfoFactory=new CSysNetPseudMemberLinkInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetPseudMemberLinkInfoFactory=new CSysNetPseudMemberLinkInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetPseudMemberLinkInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetOuterDeviceInfo");
		if(it == blockMap.end())
			m_SysNetOuterDeviceInfoFactory=new CSysNetOuterDeviceInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetOuterDeviceInfoFactory=new CSysNetOuterDeviceInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetOuterDeviceInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysLocalPingResultInfo");
		if(it == blockMap.end())
			m_SysLocalPingResultInfoFactory=new CSysLocalPingResultInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysLocalPingResultInfoFactory=new CSysLocalPingResultInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysLocalPingResultInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysRomotePingResultInfo");
		if(it == blockMap.end())
			m_SysRomotePingResultInfoFactory=new CSysRomotePingResultInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysRomotePingResultInfoFactory=new CSysRomotePingResultInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysRomotePingResultInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysParticTradeOrderStates");
		if(it == blockMap.end())
			m_SysParticTradeOrderStatesFactory=new CSysParticTradeOrderStatesFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysParticTradeOrderStatesFactory=new CSysParticTradeOrderStatesFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysParticTradeOrderStatesFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbRouterInfo");
		if(it == blockMap.end())
			m_SysMdbRouterInfoFactory=new CSysMdbRouterInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbRouterInfoFactory=new CSysMdbRouterInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbRouterInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbDiskIO");
		if(it == blockMap.end())
			m_SysMdbDiskIOFactory=new CSysMdbDiskIOFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbDiskIOFactory=new CSysMdbDiskIOFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbDiskIOFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbStatInfo");
		if(it == blockMap.end())
			m_SysMdbStatInfoFactory=new CSysMdbStatInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbStatInfoFactory=new CSysMdbStatInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbStatInfoFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMdbTradeFrontOrderRttStat");
		if(it == blockMap.end())
			m_SysMdbTradeFrontOrderRttStatFactory=new CSysMdbTradeFrontOrderRttStatFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMdbTradeFrontOrderRttStatFactory=new CSysMdbTradeFrontOrderRttStatFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMdbTradeFrontOrderRttStatFactory==NULL)
			return 0;
				
		it = blockMap.find("SysInstrumentStatus");
		if(it == blockMap.end())
			m_SysInstrumentStatusFactory=new CSysInstrumentStatusFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysInstrumentStatusFactory=new CSysInstrumentStatusFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysInstrumentStatusFactory==NULL)
			return 0;
				
		it = blockMap.find("SysCurrTradingSegmentAttr");
		if(it == blockMap.end())
			m_SysCurrTradingSegmentAttrFactory=new CSysCurrTradingSegmentAttrFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysCurrTradingSegmentAttrFactory=new CSysCurrTradingSegmentAttrFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysCurrTradingSegmentAttrFactory==NULL)
			return 0;
				
		it = blockMap.find("SysMemberLinkCost");
		if(it == blockMap.end())
			m_SysMemberLinkCostFactory=new CSysMemberLinkCostFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysMemberLinkCostFactory=new CSysMemberLinkCostFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysMemberLinkCostFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetPartylinkMonthlyRent");
		if(it == blockMap.end())
			m_SysNetPartylinkMonthlyRentFactory=new CSysNetPartylinkMonthlyRentFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetPartylinkMonthlyRentFactory=new CSysNetPartylinkMonthlyRentFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetPartylinkMonthlyRentFactory==NULL)
			return 0;
				
		it = blockMap.find("SysNetNonPartyLinkInfo");
		if(it == blockMap.end())
			m_SysNetNonPartyLinkInfoFactory=new CSysNetNonPartyLinkInfoFactory(pConfig,pAllocator,&blockMap);
		else
			m_SysNetNonPartyLinkInfoFactory=new CSysNetNonPartyLinkInfoFactory(pConfig,pAllocator,&blockMap,true,it->second);
		if (m_SysNetNonPartyLinkInfoFactory==NULL)
			return 0;
				
	}
	return 1;
}

int CMemoryDB::load(CConfig *pConfig)
{
	return 1;
}

int CMemoryDB::save(CConfig *pConfig)
{
	if (!m_SysInvalidateOrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysOrderStatusFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysBargainOrderFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysInstPropertyFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMarginRateFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysPriceLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysPartPosiLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysClientPosiLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysSpecialPosiLimitFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysTransactionChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysClientChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysPartClientChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysPosiLimitChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysClientPosiLimitChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysSpecPosiLimitChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysHedgeDetailChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysParticipantChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMarginRateChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysUserIpChgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysPartTradeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbObjectAttrFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbSyslogInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysUserInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysOnlineUserInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysWarningEventFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysWarningQueryFactory->writeCSV(pConfig))
		return 0;
	if (!m_SyslogEventFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysEventDescripFactory->writeCSV(pConfig))
		return 0;
	if (!m_RspQryHostEnvCommonFactory->writeCSV(pConfig))
		return 0;
	if (!m_RspQryHostEnvLanFactory->writeCSV(pConfig))
		return 0;
	if (!m_RspQryHostEnvStorageFactory->writeCSV(pConfig))
		return 0;
	if (!m_RspQryHostEnvIOFactory->writeCSV(pConfig))
		return 0;
	if (!m_RspQryHostEnvFSFactory->writeCSV(pConfig))
		return 0;
	if (!m_RspQryHostEnvSwapFactory->writeCSV(pConfig))
		return 0;
	if (!m_RspQryHostEnvLanCfgFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbTopCpuInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbTopMemInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbTopProcessInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbFileSystemInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbNetworkInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysParticipantInitFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysUserInitFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysClientInitFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysTradeUserLoginInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbWebAppInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbMemPoolInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbConnectorInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbDBQueryFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetAreaFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetSubAreaFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetSubAreaIPFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetFuncAreaFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetDeviceFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetDeviceLinkedFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetOIDFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetDeviceTypeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetTimePolicyFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetGatherTaskFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetDeviceCategoryFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetManufactoryFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetCommunityFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetPortTypeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetInterfaceFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetGeneralOIDFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorTypeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorAttrScopeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorAttrTypeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorCommandTypeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorActionGroupFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorDeviceGroupFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorTaskInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorTaskObjectSetFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorTaskResultFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetPartyLinkInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetDelPartyLinkInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetPartyLinkAddrChangeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorActionAttrFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetModuleFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetEventExprFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetEventTypeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetSubEventTypeFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetEventLevelFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorDeviceTaskFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMonitorTaskInstAttrsFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetBaseLineFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetBaseLineTaskFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbNetPartyLinkStatusInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetMemberSDHLineInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetDDNLinkInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetPseudMemberLinkInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetOuterDeviceInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysLocalPingResultInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysRomotePingResultInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysParticTradeOrderStatesFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbRouterInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbDiskIOFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbStatInfoFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMdbTradeFrontOrderRttStatFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysInstrumentStatusFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysCurrTradingSegmentAttrFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysMemberLinkCostFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetPartylinkMonthlyRentFactory->writeCSV(pConfig))
		return 0;
	if (!m_SysNetNonPartyLinkInfoFactory->writeCSV(pConfig))
		return 0;
	return 1;
}

void CMemoryDB::clear(void)
{
	m_SysInvalidateOrderFactory->clearAll();
	m_SysOrderStatusFactory->clearAll();
	m_SysBargainOrderFactory->clearAll();
	m_SysInstPropertyFactory->clearAll();
	m_SysMarginRateFactory->clearAll();
	m_SysPriceLimitFactory->clearAll();
	m_SysPartPosiLimitFactory->clearAll();
	m_SysClientPosiLimitFactory->clearAll();
	m_SysSpecialPosiLimitFactory->clearAll();
	m_SysTransactionChgFactory->clearAll();
	m_SysClientChgFactory->clearAll();
	m_SysPartClientChgFactory->clearAll();
	m_SysPosiLimitChgFactory->clearAll();
	m_SysClientPosiLimitChgFactory->clearAll();
	m_SysSpecPosiLimitChgFactory->clearAll();
	m_SysHedgeDetailChgFactory->clearAll();
	m_SysParticipantChgFactory->clearAll();
	m_SysMarginRateChgFactory->clearAll();
	m_SysUserIpChgFactory->clearAll();
	m_SysPartTradeFactory->clearAll();
	m_SysMdbObjectAttrFactory->clearAll();
	m_SysMdbSyslogInfoFactory->clearAll();
	m_SysUserInfoFactory->clearAll();
	m_SysOnlineUserInfoFactory->clearAll();
	m_SysWarningEventFactory->clearAll();
	m_SysWarningQueryFactory->clearAll();
	m_SyslogEventFactory->clearAll();
	m_SysEventDescripFactory->clearAll();
	m_RspQryHostEnvCommonFactory->clearAll();
	m_RspQryHostEnvLanFactory->clearAll();
	m_RspQryHostEnvStorageFactory->clearAll();
	m_RspQryHostEnvIOFactory->clearAll();
	m_RspQryHostEnvFSFactory->clearAll();
	m_RspQryHostEnvSwapFactory->clearAll();
	m_RspQryHostEnvLanCfgFactory->clearAll();
	m_SysMdbTopCpuInfoFactory->clearAll();
	m_SysMdbTopMemInfoFactory->clearAll();
	m_SysMdbTopProcessInfoFactory->clearAll();
	m_SysMdbFileSystemInfoFactory->clearAll();
	m_SysMdbNetworkInfoFactory->clearAll();
	m_SysParticipantInitFactory->clearAll();
	m_SysUserInitFactory->clearAll();
	m_SysClientInitFactory->clearAll();
	m_SysTradeUserLoginInfoFactory->clearAll();
	m_SysMdbWebAppInfoFactory->clearAll();
	m_SysMdbMemPoolInfoFactory->clearAll();
	m_SysMdbConnectorInfoFactory->clearAll();
	m_SysMdbDBQueryFactory->clearAll();
	m_SysNetAreaFactory->clearAll();
	m_SysNetSubAreaFactory->clearAll();
	m_SysNetSubAreaIPFactory->clearAll();
	m_SysNetFuncAreaFactory->clearAll();
	m_SysNetDeviceFactory->clearAll();
	m_SysNetDeviceLinkedFactory->clearAll();
	m_SysNetOIDFactory->clearAll();
	m_SysNetDeviceTypeFactory->clearAll();
	m_SysNetTimePolicyFactory->clearAll();
	m_SysNetGatherTaskFactory->clearAll();
	m_SysNetDeviceCategoryFactory->clearAll();
	m_SysNetManufactoryFactory->clearAll();
	m_SysNetCommunityFactory->clearAll();
	m_SysNetPortTypeFactory->clearAll();
	m_SysNetInterfaceFactory->clearAll();
	m_SysNetGeneralOIDFactory->clearAll();
	m_SysNetMonitorTypeFactory->clearAll();
	m_SysNetMonitorAttrScopeFactory->clearAll();
	m_SysNetMonitorAttrTypeFactory->clearAll();
	m_SysNetMonitorCommandTypeFactory->clearAll();
	m_SysNetMonitorActionGroupFactory->clearAll();
	m_SysNetMonitorDeviceGroupFactory->clearAll();
	m_SysNetMonitorTaskInfoFactory->clearAll();
	m_SysNetMonitorTaskObjectSetFactory->clearAll();
	m_SysNetMonitorTaskResultFactory->clearAll();
	m_SysNetPartyLinkInfoFactory->clearAll();
	m_SysNetDelPartyLinkInfoFactory->clearAll();
	m_SysNetPartyLinkAddrChangeFactory->clearAll();
	m_SysNetMonitorActionAttrFactory->clearAll();
	m_SysNetModuleFactory->clearAll();
	m_SysNetEventExprFactory->clearAll();
	m_SysNetEventTypeFactory->clearAll();
	m_SysNetSubEventTypeFactory->clearAll();
	m_SysNetEventLevelFactory->clearAll();
	m_SysNetMonitorDeviceTaskFactory->clearAll();
	m_SysNetMonitorTaskInstAttrsFactory->clearAll();
	m_SysNetBaseLineFactory->clearAll();
	m_SysNetBaseLineTaskFactory->clearAll();
	m_SysMdbNetPartyLinkStatusInfoFactory->clearAll();
	m_SysNetMemberSDHLineInfoFactory->clearAll();
	m_SysNetDDNLinkInfoFactory->clearAll();
	m_SysNetPseudMemberLinkInfoFactory->clearAll();
	m_SysNetOuterDeviceInfoFactory->clearAll();
	m_SysLocalPingResultInfoFactory->clearAll();
	m_SysRomotePingResultInfoFactory->clearAll();
	m_SysParticTradeOrderStatesFactory->clearAll();
	m_SysMdbRouterInfoFactory->clearAll();
	m_SysMdbDiskIOFactory->clearAll();
	m_SysMdbStatInfoFactory->clearAll();
	m_SysMdbTradeFrontOrderRttStatFactory->clearAll();
	m_SysInstrumentStatusFactory->clearAll();
	m_SysCurrTradingSegmentAttrFactory->clearAll();
	m_SysMemberLinkCostFactory->clearAll();
	m_SysNetPartylinkMonthlyRentFactory->clearAll();
	m_SysNetNonPartyLinkInfoFactory->clearAll();
	m_ForceUserPassword.clear();
}

void CMemoryDB::linkAll(void)
{
}

