


/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcUserApiImpl.cpp
///@brief 实现了客户端接口
///@history 
///20060106	赵鸿昊		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "public.h"
#include "FtdcSysUserApiImpl.h"
CFtdcSysUserApiImpl::CFtdcSysUserApiImpl(const char *pszFlowPath, CSelectReactor *pReactor)
:CFtdcSysUserApiImplBase(pszFlowPath, pReactor)
{
}

///CPU查询
int CFtdcSysUserApiImpl::ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopCpuInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTopCpuInfoField ReqQryTopCpuInfoField;
	memcpy(&ReqQryTopCpuInfoField, pReqQryTopCpuInfo, sizeof(CFTDReqQryTopCpuInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTopCpuInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///Mem查询
int CFtdcSysUserApiImpl::ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopMemInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTopMemInfoField ReqQryTopMemInfoField;
	memcpy(&ReqQryTopMemInfoField, pReqQryTopMemInfo, sizeof(CFTDReqQryTopMemInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTopMemInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///process查询
int CFtdcSysUserApiImpl::ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTopProcessInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTopProcessInfoField ReqQryTopProcessInfoField;
	memcpy(&ReqQryTopProcessInfoField, pReqQryTopProcessInfo, sizeof(CFTDReqQryTopProcessInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTopProcessInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///filesystem查询
int CFtdcSysUserApiImpl::ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFileSystemInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFileSystemInfoField ReqQryFileSystemInfoField;
	memcpy(&ReqQryFileSystemInfoField, pReqQryFileSystemInfo, sizeof(CFTDReqQryFileSystemInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFileSystemInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///network查询
int CFtdcSysUserApiImpl::ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetworkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetworkInfoField ReqQryNetworkInfoField;
	memcpy(&ReqQryNetworkInfoField, pReqQryNetworkInfo, sizeof(CFTDReqQryNetworkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetworkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///主机环境信息查询
int CFtdcSysUserApiImpl::ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHostEnvTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHostEnvField ReqQryHostEnvField;
	memcpy(&ReqQryHostEnvField, pReqQryHostEnv, sizeof(CFTDReqQryHostEnvField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHostEnvField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///获得监控对象信息查询
int CFtdcSysUserApiImpl::ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonitorObjectTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonitorObjectField ReqQryMonitorObjectField;
	memcpy(&ReqQryMonitorObjectField, pReqQryMonitorObject, sizeof(CFTDReqQryMonitorObjectField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonitorObjectField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///获得业务进程和主机的对应关系查询
int CFtdcSysUserApiImpl::ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryObjectRationalTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryObjectRationalField ReqQryObjectRationalField;
	memcpy(&ReqQryObjectRationalField, pReqQryObjectRational, sizeof(CFTDReqQryObjectRationalField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryObjectRationalField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志文件内容查询
int CFtdcSysUserApiImpl::ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogInfoField ReqQrySyslogInfoField;
	memcpy(&ReqQrySyslogInfoField, pReqQrySyslogInfo, sizeof(CFTDReqQrySyslogInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控内容订阅请求
int CFtdcSysUserApiImpl::ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySubscriberTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySubscriberField ReqQrySubscriberField;
	memcpy(&ReqQrySubscriberField, pReqQrySubscriber, sizeof(CFTDReqQrySubscriberField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySubscriberField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///对象关系查询
int CFtdcSysUserApiImpl::ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOidRelationTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryOidRelationField ReqQryOidRelationField;
	memcpy(&ReqQryOidRelationField, pReqQryOidRelation, sizeof(CFTDReqQryOidRelationField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryOidRelationField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户信息查询请求
int CFtdcSysUserApiImpl::ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryUserInfoField ReqQryUserInfoField;
	memcpy(&ReqQryUserInfoField, pReqQryUserInfo, sizeof(CFTDReqQryUserInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryUserInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///在线用户信息查询请求
int CFtdcSysUserApiImpl::ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOnlineUserInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryOnlineUserInfoField ReqQryOnlineUserInfoField;
	memcpy(&ReqQryOnlineUserInfoField, pReqQryOnlineUserInfo, sizeof(CFTDReqQryOnlineUserInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryOnlineUserInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警事件查询请求
int CFtdcSysUserApiImpl::ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningEventTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningEventField ReqQryWarningEventField;
	memcpy(&ReqQryWarningEventField, pReqQryWarningEvent, sizeof(CFTDReqQryWarningEventField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningEventField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///对象状态指标查询
int CFtdcSysUserApiImpl::ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryObjectAttrField ReqQryObjectAttrField;
	memcpy(&ReqQryObjectAttrField, pReqQryObjectAttr, sizeof(CFTDReqQryObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///无效报单查询
int CFtdcSysUserApiImpl::ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInvalidateOrderTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryInvalidateOrderField ReqQryInvalidateOrderField;
	memcpy(&ReqQryInvalidateOrderField, pReqQryInvalidateOrder, sizeof(CFTDReqQryInvalidateOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryInvalidateOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单状态查询
int CFtdcSysUserApiImpl::ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryOrderStatusTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryOrderStatusField ReqQryOrderStatusField;
	memcpy(&ReqQryOrderStatusField, pReqQryOrderStatus, sizeof(CFTDReqQryOrderStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryOrderStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///报单成交查询
int CFtdcSysUserApiImpl::ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryBargainOrderTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryBargainOrderField ReqQryBargainOrderField;
	memcpy(&ReqQryBargainOrderField, pReqQryBargainOrder, sizeof(CFTDReqQryBargainOrderField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryBargainOrderField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约基本属性查询
int CFtdcSysUserApiImpl::ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstPropertyTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryInstPropertyField ReqQryInstPropertyField;
	memcpy(&ReqQryInstPropertyField, pReqQryInstProperty, sizeof(CFTDReqQryInstPropertyField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryInstPropertyField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约保证金率查询
int CFtdcSysUserApiImpl::ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMarginRateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMarginRateField ReqQryMarginRateField;
	memcpy(&ReqQryMarginRateField, pReqQryMarginRate, sizeof(CFTDReqQryMarginRateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMarginRateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///合约涨跌停板查询
int CFtdcSysUserApiImpl::ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPriceLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPriceLimitField ReqQryPriceLimitField;
	memcpy(&ReqQryPriceLimitField, pReqQryPriceLimit, sizeof(CFTDReqQryPriceLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPriceLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员限仓查询
int CFtdcSysUserApiImpl::ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartPosiLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPartPosiLimitField ReqQryPartPosiLimitField;
	memcpy(&ReqQryPartPosiLimitField, pReqQryPartPosiLimit, sizeof(CFTDReqQryPartPosiLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPartPosiLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户限仓查询
int CFtdcSysUserApiImpl::ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPosiLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientPosiLimitField ReqQryClientPosiLimitField;
	memcpy(&ReqQryClientPosiLimitField, pReqQryClientPosiLimit, sizeof(CFTDReqQryClientPosiLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientPosiLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///特殊客户限仓查询
int CFtdcSysUserApiImpl::ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySpecialPosiLimitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySpecialPosiLimitField ReqQrySpecialPosiLimitField;
	memcpy(&ReqQrySpecialPosiLimitField, pReqQrySpecialPosiLimit, sizeof(CFTDReqQrySpecialPosiLimitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySpecialPosiLimitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///账户出入金查询
int CFtdcSysUserApiImpl::ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTransactionChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTransactionChgField ReqQryTransactionChgField;
	memcpy(&ReqQryTransactionChgField, pReqQryTransactionChg, sizeof(CFTDReqQryTransactionChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTransactionChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///客户数据变动查询
int CFtdcSysUserApiImpl::ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientChgField ReqQryClientChgField;
	memcpy(&ReqQryClientChgField, pReqQryClientChg, sizeof(CFTDReqQryClientChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员客户对照变动查询
int CFtdcSysUserApiImpl::ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartClientChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPartClientChgField ReqQryPartClientChgField;
	memcpy(&ReqQryPartClientChgField, pReqQryPartClientChg, sizeof(CFTDReqQryPartClientChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPartClientChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///限仓数据变动查询
int CFtdcSysUserApiImpl::ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPosiLimitChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPosiLimitChgField ReqQryPosiLimitChgField;
	memcpy(&ReqQryPosiLimitChgField, pReqQryPosiLimitChg, sizeof(CFTDReqQryPosiLimitChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPosiLimitChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///保值额度变动查询
int CFtdcSysUserApiImpl::ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHedgeDetailChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHedgeDetailChgField ReqQryHedgeDetailChgField;
	memcpy(&ReqQryHedgeDetailChgField, pReqQryHedgeDetailChg, sizeof(CFTDReqQryHedgeDetailChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHedgeDetailChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员变动查询
int CFtdcSysUserApiImpl::ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticipantChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryParticipantChgField ReqQryParticipantChgField;
	memcpy(&ReqQryParticipantChgField, pReqQryParticipantChg, sizeof(CFTDReqQryParticipantChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryParticipantChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///保证金率变动查询
int CFtdcSysUserApiImpl::ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMarginRateChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMarginRateChgField ReqQryMarginRateChgField;
	memcpy(&ReqQryMarginRateChgField, pReqQryMarginRateChg, sizeof(CFTDReqQryMarginRateChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMarginRateChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///IP地址变动查询
int CFtdcSysUserApiImpl::ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserIpChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryUserIpChgField ReqQryUserIpChgField;
	memcpy(&ReqQryUserIpChgField, pReqQryUserIpChg, sizeof(CFTDReqQryUserIpChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryUserIpChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///限仓数据变动查询
int CFtdcSysUserApiImpl::ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientPosiLimitChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientPosiLimitChgField ReqQryClientPosiLimitChgField;
	memcpy(&ReqQryClientPosiLimitChgField, pReqQryClientPosiLimitChg, sizeof(CFTDReqQryClientPosiLimitChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientPosiLimitChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///限仓数据变动查询
int CFtdcSysUserApiImpl::ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySpecPosiLimitChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySpecPosiLimitChgField ReqQrySpecPosiLimitChgField;
	memcpy(&ReqQrySpecPosiLimitChgField, pReqQrySpecPosiLimitChg, sizeof(CFTDReqQrySpecPosiLimitChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySpecPosiLimitChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///历史对象状态指标查询
int CFtdcSysUserApiImpl::ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryObjectAttrField ReqQryHistoryObjectAttrField;
	memcpy(&ReqQryHistoryObjectAttrField, pReqQryHistoryObjectAttr, sizeof(CFTDReqQryHistoryObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///前置响应信息查询
int CFtdcSysUserApiImpl::ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFrontInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFrontInfoField ReqQryFrontInfoField;
	memcpy(&ReqQryFrontInfoField, pReqQryFrontInfo, sizeof(CFTDReqQryFrontInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFrontInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户登录
int CFtdcSysUserApiImpl::ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserLoginTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserLoginField ReqQrySysUserLoginField;
	memcpy(&ReqQrySysUserLoginField, pReqQrySysUserLogin, sizeof(CFTDReqQrySysUserLoginField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserLoginField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户登出
int CFtdcSysUserApiImpl::ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserLogoutTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserLogoutField ReqQrySysUserLogoutField;
	memcpy(&ReqQrySysUserLogoutField, pReqQrySysUserLogout, sizeof(CFTDReqQrySysUserLogoutField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserLogoutField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///用户修改密码
int CFtdcSysUserApiImpl::ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserPasswordUpdateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserPasswordUpdateField ReqQrySysUserPasswordUpdateField;
	memcpy(&ReqQrySysUserPasswordUpdateField, pReqQrySysUserPasswordUpdate, sizeof(CFTDReqQrySysUserPasswordUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserPasswordUpdateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///注册用户
int CFtdcSysUserApiImpl::ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserRegisterTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserRegisterField ReqQrySysUserRegisterField;
	memcpy(&ReqQrySysUserRegisterField, pReqQrySysUserRegister, sizeof(CFTDReqQrySysUserRegisterField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserRegisterField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///删除用户
int CFtdcSysUserApiImpl::ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySysUserDeleteTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySysUserDeleteField ReqQrySysUserDeleteField;
	memcpy(&ReqQrySysUserDeleteField, pReqQrySysUserDelete, sizeof(CFTDReqQrySysUserDeleteField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySysUserDeleteField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易日志查询
int CFtdcSysUserApiImpl::ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeLogTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeLogField ReqQryTradeLogField;
	memcpy(&ReqQryTradeLogField, pReqQryTradeLog, sizeof(CFTDReqQryTradeLogField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeLogField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警事件修改
int CFtdcSysUserApiImpl::ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningEventUpdateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningEventUpdateField ReqQryWarningEventUpdateField;
	memcpy(&ReqQryWarningEventUpdateField, pReqQryWarningEventUpdate, sizeof(CFTDReqQryWarningEventUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningEventUpdateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统登录信息查询
int CFtdcSysUserApiImpl::ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeUserLoginInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeUserLoginInfoField ReqQryTradeUserLoginInfoField;
	memcpy(&ReqQryTradeUserLoginInfoField, pReqQryTradeUserLoginInfo, sizeof(CFTDReqQryTradeUserLoginInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeUserLoginInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员交易查询
int CFtdcSysUserApiImpl::ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPartTradeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPartTradeField ReqQryPartTradeField;
	memcpy(&ReqQryPartTradeField, pReqQryPartTrade, sizeof(CFTDReqQryPartTradeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPartTradeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易峰值查询
int CFtdcSysUserApiImpl::ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradepeakTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradepeakField ReqQryTradepeakField;
	memcpy(&ReqQryTradepeakField, pReqQryTradepeak, sizeof(CFTDReqQryTradepeakField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradepeakField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///管理平台初始化信息查询
int CFtdcSysUserApiImpl::ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticipantInitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryParticipantInitField ReqQryParticipantInitField;
	memcpy(&ReqQryParticipantInitField, pReqQryParticipantInit, sizeof(CFTDReqQryParticipantInitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryParticipantInitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///管理平台初始化信息查询
int CFtdcSysUserApiImpl::ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryUserInitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryUserInitField ReqQryUserInitField;
	memcpy(&ReqQryUserInitField, pReqQryUserInit, sizeof(CFTDReqQryUserInitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryUserInitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///
int CFtdcSysUserApiImpl::ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryCpuInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryCpuInfoField ReqQryHistoryCpuInfoField;
	memcpy(&ReqQryHistoryCpuInfoField, pReqQryHistoryCpuInfo, sizeof(CFTDReqQryHistoryCpuInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryCpuInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///
int CFtdcSysUserApiImpl::ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryMemInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryMemInfoField ReqQryHistoryMemInfoField;
	memcpy(&ReqQryHistoryMemInfoField, pReqQryHistoryMemInfo, sizeof(CFTDReqQryHistoryMemInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryMemInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///
int CFtdcSysUserApiImpl::ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryNetworkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryNetworkInfoField ReqQryHistoryNetworkInfoField;
	memcpy(&ReqQryHistoryNetworkInfoField, pReqQryHistoryNetworkInfo, sizeof(CFTDReqQryHistoryNetworkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryNetworkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控系统在线用户查询
int CFtdcSysUserApiImpl::ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryMonitorOnlineUser, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryMonitorOnlineUserField ReqQryMonitorOnlineUserField;
	memcpy(&ReqQryMonitorOnlineUserField, pReqQryMonitorOnlineUser, sizeof(CFTDReqQryMonitorOnlineUserField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryMonitorOnlineUserField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统前置统计查询
int CFtdcSysUserApiImpl::ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFrontStat, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFrontStatField ReqQryFrontStatField;
	memcpy(&ReqQryFrontStatField, pReqQryFrontStat, sizeof(CFTDReqQryFrontStatField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFrontStatField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///历史峰值查询
int CFtdcSysUserApiImpl::ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryHistoryTradePeakTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryHistoryTradePeakField ReqQryHistoryTradePeakField;
	memcpy(&ReqQryHistoryTradePeakField, pReqQryHistoryTradePeak, sizeof(CFTDReqQryHistoryTradePeakField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryHistoryTradePeakField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志事件查询
int CFtdcSysUserApiImpl::ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogEventTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogEventField ReqQrySyslogEventField;
	memcpy(&ReqQrySyslogEventField, pReqQrySyslogEvent, sizeof(CFTDReqQrySyslogEventField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogEventField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志事件订阅请求
int CFtdcSysUserApiImpl::ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogEventSubcriberTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogEventSubcriberField ReqQrySyslogEventSubcriberField;
	memcpy(&ReqQrySyslogEventSubcriberField, pReqQrySyslogEventSubcriber, sizeof(CFTDReqQrySyslogEventSubcriberField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogEventSubcriberField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///tomcat信息查询
int CFtdcSysUserApiImpl::ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTomcatInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTomcatInfoField ReqQryTomcatInfoField;
	memcpy(&ReqQryTomcatInfoField, pReqQryTomcatInfo, sizeof(CFTDReqQryTomcatInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTomcatInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///数据库查询
int CFtdcSysUserApiImpl::ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryDBQueryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryDBQueryField ReqQryDBQueryField;
	memcpy(&ReqQryDBQueryField, pReqQryDBQuery, sizeof(CFTDReqQryDBQueryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryDBQueryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///文件传输请求
int CFtdcSysUserApiImpl::ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryGetFileTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryGetFileField ReqQryGetFileField;
	memcpy(&ReqQryGetFileField, pReqQryGetFile, sizeof(CFTDReqQryGetFileField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryGetFileField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///日志事件修改请求
int CFtdcSysUserApiImpl::ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQrySyslogEventUpdateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQrySyslogEventUpdateField ReqQrySyslogEventUpdateField;
	memcpy(&ReqQrySyslogEventUpdateField, pReqQrySyslogEventUpdate, sizeof(CFTDReqQrySyslogEventUpdateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQrySyslogEventUpdateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警明细查询
int CFtdcSysUserApiImpl::ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningQueryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningQueryField ReqQryWarningQueryField;
	memcpy(&ReqQryWarningQueryField, pReqQryWarningQuery, sizeof(CFTDReqQryWarningQueryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningQueryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网站访问查询
int CFtdcSysUserApiImpl::ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWebVisitTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWebVisitField ReqQryWebVisitField;
	memcpy(&ReqQryWebVisitField, pReqQryWebVisit, sizeof(CFTDReqQryWebVisitField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWebVisitField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///告警激活变更
int CFtdcSysUserApiImpl::ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryWarningActiveChange, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryWarningActiveChangeField ReqQryWarningActiveChangeField;
	memcpy(&ReqQryWarningActiveChangeField, pReqQryWarningActiveChange, sizeof(CFTDReqQryWarningActiveChangeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryWarningActiveChangeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///通用操作
int CFtdcSysUserApiImpl::ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryGeneralOperateTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryGeneralOperateField ReqQryGeneralOperateField;
	memcpy(&ReqQryGeneralOperateField, pReqQryGeneralOperate, sizeof(CFTDReqQryGeneralOperateField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryGeneralOperateField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络设备连接关系请求
int CFtdcSysUserApiImpl::ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceLinkedTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceLinkedField ReqQryNetDeviceLinkedField;
	memcpy(&ReqQryNetDeviceLinkedField, pReqQryNetDeviceLinked, sizeof(CFTDReqQryNetDeviceLinkedField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceLinkedField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统登录信息请求
int CFtdcSysUserApiImpl::ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeUserLoginStatTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeUserLoginStatField ReqQryTradeUserLoginStatField;
	memcpy(&ReqQryTradeUserLoginStatField, pReqQryTradeUserLoginStat, sizeof(CFTDReqQryTradeUserLoginStatField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeUserLoginStatField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统前置报单响应信息
int CFtdcSysUserApiImpl::ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeFrontOrderRttStatTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeFrontOrderRttStatField ReqQryTradeFrontOrderRttStatField;
	memcpy(&ReqQryTradeFrontOrderRttStatField, pReqQryTradeFrontOrderRttStat, sizeof(CFTDReqQryTradeFrontOrderRttStatField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeFrontOrderRttStatField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员席位交易状态
int CFtdcSysUserApiImpl::ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryParticTradeOrderStatesTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryParticTradeOrderStatesField ReqQryParticTradeOrderStatesField;
	memcpy(&ReqQryParticTradeOrderStatesField, pReqQryParticTradeOrderStates, sizeof(CFTDReqQryParticTradeOrderStatesField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryParticTradeOrderStatesField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统路由信息
int CFtdcSysUserApiImpl::ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryRouterInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryRouterInfoField ReqQryRouterInfoField;
	memcpy(&ReqQryRouterInfoField, pReqQryRouterInfo, sizeof(CFTDReqQryRouterInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryRouterInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///磁盘I/O信息
int CFtdcSysUserApiImpl::ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryDiskIOTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryDiskIOField ReqQryDiskIOField;
	memcpy(&ReqQryDiskIOField, pReqQryDiskIO, sizeof(CFTDReqQryDiskIOField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryDiskIOField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///系统状态信息
int CFtdcSysUserApiImpl::ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryStatInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryStatInfoField ReqQryStatInfoField;
	memcpy(&ReqQryStatInfoField, pReqQryStatInfo, sizeof(CFTDReqQryStatInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryStatInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///交易系统前置报单分布区间
int CFtdcSysUserApiImpl::ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryTradeOrderRttCutLineTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryTradeOrderRttCutLineField ReqQryTradeOrderRttCutLineField;
	memcpy(&ReqQryTradeOrderRttCutLineField, pReqQryTradeOrderRttCutLine, sizeof(CFTDReqQryTradeOrderRttCutLineField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryTradeOrderRttCutLineField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员客户信息
int CFtdcSysUserApiImpl::ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryClientInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryClientInfoField ReqQryClientInfoField;
	memcpy(&ReqQryClientInfoField, pReqQryClientInfo, sizeof(CFTDReqQryClientInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryClientInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求事件描述
int CFtdcSysUserApiImpl::ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryEventDescriptionTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryEventDescriptionField ReqQryEventDescriptionField;
	memcpy(&ReqQryEventDescriptionField, pReqQryEventDescription, sizeof(CFTDReqQryEventDescriptionField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryEventDescriptionField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///订阅前置唯一ID信息
int CFtdcSysUserApiImpl::ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFrontUniqueIDTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFrontUniqueIDField ReqQryFrontUniqueIDField;
	memcpy(&ReqQryFrontUniqueIDField, pReqQryFrontUniqueID, sizeof(CFTDReqQryFrontUniqueIDField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFrontUniqueIDField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员线路地址变更请求
int CFtdcSysUserApiImpl::ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartyLinkAddrChangeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartyLinkAddrChangeField ReqQryNetPartyLinkAddrChangeField;
	memcpy(&ReqQryNetPartyLinkAddrChangeField, pReqQryNetPartyLinkAddrChange, sizeof(CFTDReqQryNetPartyLinkAddrChangeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartyLinkAddrChangeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求已删除会员列表信息
int CFtdcSysUserApiImpl::ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDelPartyLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDelPartyLinkInfoField ReqQryNetDelPartyLinkInfoField;
	memcpy(&ReqQryNetDelPartyLinkInfoField, pReqQryNetDelPartyLinkInfo, sizeof(CFTDReqQryNetDelPartyLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDelPartyLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求网络性能排序
int CFtdcSysUserApiImpl::ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryPerformanceTopTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryPerformanceTopField ReqQryPerformanceTopField;
	memcpy(&ReqQryPerformanceTopField, pReqQryPerformanceTop, sizeof(CFTDReqQryPerformanceTopField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryPerformanceTopField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求约状态切换数据
int CFtdcSysUserApiImpl::ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryInstrumentStatusTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryInstrumentStatusField ReqQryInstrumentStatusField;
	memcpy(&ReqQryInstrumentStatusField, pReqQryInstrumentStatus, sizeof(CFTDReqQryInstrumentStatusField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryInstrumentStatusField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求合约交易节信息
int CFtdcSysUserApiImpl::ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryCurrTradingSegmentAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryCurrTradingSegmentAttrField ReqQryCurrTradingSegmentAttrField;
	memcpy(&ReqQryCurrTradingSegmentAttrField, pReqQryCurrTradingSegmentAttr, sizeof(CFTDReqQryCurrTradingSegmentAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryCurrTradingSegmentAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///最新网络指标查询
int CFtdcSysUserApiImpl::ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryRealTimeNetObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryRealTimeNetObjectAttrField ReqQryRealTimeNetObjectAttrField;
	memcpy(&ReqQryRealTimeNetObjectAttrField, pReqQryRealTimeNetObjectAttr, sizeof(CFTDReqQryRealTimeNetObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryRealTimeNetObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络大区划分查询
int CFtdcSysUserApiImpl::ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetAreaTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetAreaField ReqQryNetAreaField;
	memcpy(&ReqQryNetAreaField, pReqQryNetArea, sizeof(CFTDReqQryNetAreaField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetAreaField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络子区查询
int CFtdcSysUserApiImpl::ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetSubAreaTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetSubAreaField ReqQryNetSubAreaField;
	memcpy(&ReqQryNetSubAreaField, pReqQryNetSubArea, sizeof(CFTDReqQryNetSubAreaField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetSubAreaField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络子区IP查询
int CFtdcSysUserApiImpl::ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetSubAreaIPTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetSubAreaIPField ReqQryNetSubAreaIPField;
	memcpy(&ReqQryNetSubAreaIPField, pReqQryNetSubAreaIP, sizeof(CFTDReqQryNetSubAreaIPField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetSubAreaIPField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络设备探测请求
int CFtdcSysUserApiImpl::ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceDetectTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceDetectField ReqQryNetDeviceDetectField;
	memcpy(&ReqQryNetDeviceDetectField, pReqQryNetDeviceDetect, sizeof(CFTDReqQryNetDeviceDetectField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceDetectField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///网络设备查询请求
int CFtdcSysUserApiImpl::ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceRequestTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceRequestField ReqQryNetDeviceRequestField;
	memcpy(&ReqQryNetDeviceRequestField, pReqQryNetDeviceRequest, sizeof(CFTDReqQryNetDeviceRequestField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceRequestField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///大楼查询
int CFtdcSysUserApiImpl::ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetBuildingTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetBuildingField ReqQryNetBuildingField;
	memcpy(&ReqQryNetBuildingField, pReqQryNetBuilding, sizeof(CFTDReqQryNetBuildingField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetBuildingField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///机房查询
int CFtdcSysUserApiImpl::ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetRoomTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetRoomField ReqQryNetRoomField;
	memcpy(&ReqQryNetRoomField, pReqQryNetRoom, sizeof(CFTDReqQryNetRoomField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetRoomField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///机柜查询
int CFtdcSysUserApiImpl::ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetCabinetsTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetCabinetsField ReqQryNetCabinetsField;
	memcpy(&ReqQryNetCabinetsField, pReqQryNetCabinets, sizeof(CFTDReqQryNetCabinetsField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetCabinetsField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///OID
int CFtdcSysUserApiImpl::ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetOIDTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetOIDField ReqQryNetOIDField;
	memcpy(&ReqQryNetOIDField, pReqQryNetOID, sizeof(CFTDReqQryNetOIDField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetOIDField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///时间策略
int CFtdcSysUserApiImpl::ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetTimePolicyTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetTimePolicyField ReqQryNetTimePolicyField;
	memcpy(&ReqQryNetTimePolicyField, pReqQryNetTimePolicy, sizeof(CFTDReqQryNetTimePolicyField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetTimePolicyField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///采集任务查询
int CFtdcSysUserApiImpl::ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetGatherTaskTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetGatherTaskField ReqQryNetGatherTaskField;
	memcpy(&ReqQryNetGatherTaskField, pReqQryNetGatherTask, sizeof(CFTDReqQryNetGatherTaskField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetGatherTaskField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备变更请求
int CFtdcSysUserApiImpl::ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceChgTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceChgField ReqQryNetDeviceChgField;
	memcpy(&ReqQryNetDeviceChgField, pReqQryNetDeviceChg, sizeof(CFTDReqQryNetDeviceChgField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceChgField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///常用设备型号请求
int CFtdcSysUserApiImpl::ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceTypeField ReqQryNetDeviceTypeField;
	memcpy(&ReqQryNetDeviceTypeField, pReqQryNetDeviceType, sizeof(CFTDReqQryNetDeviceTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///常用设备类别请求
int CFtdcSysUserApiImpl::ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetDeviceCategoryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetDeviceCategoryField ReqQryNetDeviceCategoryField;
	memcpy(&ReqQryNetDeviceCategoryField, pReqQryNetDeviceCategory, sizeof(CFTDReqQryNetDeviceCategoryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetDeviceCategoryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备厂商请求
int CFtdcSysUserApiImpl::ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetManufactoryTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetManufactoryField ReqQryNetManufactoryField;
	memcpy(&ReqQryNetManufactoryField, pReqQryNetManufactory, sizeof(CFTDReqQryNetManufactoryField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetManufactoryField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备共同体请求
int CFtdcSysUserApiImpl::ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetCommunityTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetCommunityField ReqQryNetCommunityField;
	memcpy(&ReqQryNetCommunityField, pReqQryNetCommunity, sizeof(CFTDReqQryNetCommunityField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetCommunityField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///端口类型请求
int CFtdcSysUserApiImpl::ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPortTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPortTypeField ReqQryNetPortTypeField;
	memcpy(&ReqQryNetPortTypeField, pReqQryNetPortType, sizeof(CFTDReqQryNetPortTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPortTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员接入地点请求
int CFtdcSysUserApiImpl::ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartAccessSpotTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartAccessSpotField ReqQryNetPartAccessSpotField;
	memcpy(&ReqQryNetPartAccessSpotField, pReqQryNetPartAccessSpot, sizeof(CFTDReqQryNetPartAccessSpotField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartAccessSpotField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///端口请求
int CFtdcSysUserApiImpl::ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetInterfaceTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetInterfaceField ReqQryNetInterfaceField;
	memcpy(&ReqQryNetInterfaceField, pReqQryNetInterface, sizeof(CFTDReqQryNetInterfaceField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetInterfaceField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///GeneralOID请求
int CFtdcSysUserApiImpl::ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetGeneralOIDTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetGeneralOIDField ReqQryNetGeneralOIDField;
	memcpy(&ReqQryNetGeneralOIDField, pReqQryNetGeneralOID, sizeof(CFTDReqQryNetGeneralOIDField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetGeneralOIDField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控对象类别
int CFtdcSysUserApiImpl::ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTypeField ReqQryNetMonitorTypeField;
	memcpy(&ReqQryNetMonitorTypeField, pReqQryNetMonitorType, sizeof(CFTDReqQryNetMonitorTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///指标统表
int CFtdcSysUserApiImpl::ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorAttrScopeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorAttrScopeField ReqQryNetMonitorAttrScopeField;
	memcpy(&ReqQryNetMonitorAttrScopeField, pReqQryNetMonitorAttrScope, sizeof(CFTDReqQryNetMonitorAttrScopeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorAttrScopeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控指标表
int CFtdcSysUserApiImpl::ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorAttrTypeTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorAttrTypeField ReqQryNetMonitorAttrTypeField;
	memcpy(&ReqQryNetMonitorAttrTypeField, pReqQryNetMonitorAttrType, sizeof(CFTDReqQryNetMonitorAttrTypeField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorAttrTypeField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控对象指标表
int CFtdcSysUserApiImpl::ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorObjectAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorObjectAttrField ReqQryNetMonitorObjectAttrField;
	memcpy(&ReqQryNetMonitorObjectAttrField, pReqQryNetMonitorObjectAttr, sizeof(CFTDReqQryNetMonitorObjectAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorObjectAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备对象组表
int CFtdcSysUserApiImpl::ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorDeviceGroupTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorDeviceGroupField ReqQryNetMonitorDeviceGroupField;
	memcpy(&ReqQryNetMonitorDeviceGroupField, pReqQryNetMonitorDeviceGroup, sizeof(CFTDReqQryNetMonitorDeviceGroupField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorDeviceGroupField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务信息表
int CFtdcSysUserApiImpl::ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskInfoField ReqQryNetMonitorTaskInfoField;
	memcpy(&ReqQryNetMonitorTaskInfoField, pReqQryNetMonitorTaskInfo, sizeof(CFTDReqQryNetMonitorTaskInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务结果表
int CFtdcSysUserApiImpl::ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskResultTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskResultField ReqQryNetMonitorTaskResultField;
	memcpy(&ReqQryNetMonitorTaskResultField, pReqQryNetMonitorTaskResult, sizeof(CFTDReqQryNetMonitorTaskResultField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskResultField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务对象集
int CFtdcSysUserApiImpl::ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskObjectSetTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskObjectSetField ReqQryNetMonitorTaskObjectSetField;
	memcpy(&ReqQryNetMonitorTaskObjectSetField, pReqQryNetMonitorTaskObjectSet, sizeof(CFTDReqQryNetMonitorTaskObjectSetField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskObjectSetField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员链路信息表
int CFtdcSysUserApiImpl::ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartyLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartyLinkInfoField ReqQryNetPartyLinkInfoField;
	memcpy(&ReqQryNetPartyLinkInfoField, pReqQryNetPartyLinkInfo, sizeof(CFTDReqQryNetPartyLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartyLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///监控动作指标对照表
int CFtdcSysUserApiImpl::ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorActionAttrTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorActionAttrField ReqQryNetMonitorActionAttrField;
	memcpy(&ReqQryNetMonitorActionAttrField, pReqQryNetMonitorActionAttr, sizeof(CFTDReqQryNetMonitorActionAttrField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorActionAttrField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///模块
int CFtdcSysUserApiImpl::ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetModuleTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetModuleField ReqQryNetModuleField;
	memcpy(&ReqQryNetModuleField, pReqQryNetModule, sizeof(CFTDReqQryNetModuleField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetModuleField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务结果状态表
int CFtdcSysUserApiImpl::ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorTaskStatusResultTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorTaskStatusResultField ReqQryNetMonitorTaskStatusResultField;
	memcpy(&ReqQryNetMonitorTaskStatusResultField, pReqQryNetMonitorTaskStatusResult, sizeof(CFTDReqQryNetMonitorTaskStatusResultField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorTaskStatusResultField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///设备配置表
int CFtdcSysUserApiImpl::ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetCfgFileTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetCfgFileField ReqQryNetCfgFileField;
	memcpy(&ReqQryNetCfgFileField, pReqQryNetCfgFile, sizeof(CFTDReqQryNetCfgFileField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetCfgFileField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///任务结果规则分析表
int CFtdcSysUserApiImpl::ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetMonitorDeviceTaskTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetMonitorDeviceTaskField ReqQryNetMonitorDeviceTaskField;
	memcpy(&ReqQryNetMonitorDeviceTaskField, pReqQryNetMonitorDeviceTask, sizeof(CFTDReqQryNetMonitorDeviceTaskField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetMonitorDeviceTaskField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///文件通用操作
int CFtdcSysUserApiImpl::ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryFileGeneralOperTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryFileGeneralOperField ReqQryFileGeneralOperField;
	memcpy(&ReqQryFileGeneralOperField, pReqQryFileGeneralOper, sizeof(CFTDReqQryFileGeneralOperField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryFileGeneralOperField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///基线表
int CFtdcSysUserApiImpl::ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetBaseLineTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetBaseLineField ReqQryNetBaseLineField;
	memcpy(&ReqQryNetBaseLineField, pReqQryNetBaseLine, sizeof(CFTDReqQryNetBaseLineField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetBaseLineField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///基线结果表
int CFtdcSysUserApiImpl::ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetBaseLineResultTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetBaseLineResultField ReqQryNetBaseLineResultField;
	memcpy(&ReqQryNetBaseLineResultField, pReqQryNetBaseLineResult, sizeof(CFTDReqQryNetBaseLineResultField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetBaseLineResultField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///会员链路状态信息表
int CFtdcSysUserApiImpl::ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetPartyLinkStatusInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetPartyLinkStatusInfoField ReqQryNetPartyLinkStatusInfoField;
	memcpy(&ReqQryNetPartyLinkStatusInfoField, pReqQryNetPartyLinkStatusInfo, sizeof(CFTDReqQryNetPartyLinkStatusInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetPartyLinkStatusInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///本地ping结果
int CFtdcSysUserApiImpl::ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetLocalPingResultInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetLocalPingResultInfoField ReqQryNetLocalPingResultInfoField;
	memcpy(&ReqQryNetLocalPingResultInfoField, pReqQryNetLocalPingResultInfo, sizeof(CFTDReqQryNetLocalPingResultInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetLocalPingResultInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///远程ping结果
int CFtdcSysUserApiImpl::ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetRomotePingResultInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetRomotePingResultInfoField ReqQryNetRomotePingResultInfoField;
	memcpy(&ReqQryNetRomotePingResultInfoField, pReqQryNetRomotePingResultInfo, sizeof(CFTDReqQryNetRomotePingResultInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetRomotePingResultInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}
///请求非会员链路表信息
int CFtdcSysUserApiImpl::ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID)
{
	m_mutexAction.Lock();
	
	m_reqPackage.PreparePackage(FTD_TID_ReqQryNetNonPartyLinkInfoTopic, FTDC_CHAIN_LAST, FTD_VERSION);
	m_reqPackage.SetRequestId(nRequestID);
	
	CFTDReqQryNetNonPartyLinkInfoField ReqQryNetNonPartyLinkInfoField;
	memcpy(&ReqQryNetNonPartyLinkInfoField, pReqQryNetNonPartyLinkInfo, sizeof(CFTDReqQryNetNonPartyLinkInfoField));
	FTDC_ADD_FIELD(&m_reqPackage, &ReqQryNetNonPartyLinkInfoField);

	int nRet = RequestToQueryFlow();
	m_mutexAction.UnLock();
	
	return nRet;
}

void CFtdcSysUserApiImpl::HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries)
{

	switch(pMessage->GetTID()) {
	///CPU应答
	case FTD_TID_RspQryTopCpuInfoTopic:
		OnRspQryTopCpuInfoTopic(pMessage, nSequenceSeries);
		break;
	///CPU应答
	case FTD_TID_RtnTopCpuInfoTopic:
		OnRtnTopCpuInfoTopic(pMessage, nSequenceSeries);
		break;
	///Mem应答
	case FTD_TID_RspQryTopMemInfoTopic:
		OnRspQryTopMemInfoTopic(pMessage, nSequenceSeries);
		break;
	///Mem应答
	case FTD_TID_RtnTopMemInfoTopic:
		OnRtnTopMemInfoTopic(pMessage, nSequenceSeries);
		break;
	///process应答
	case FTD_TID_RspQryTopProcessInfoTopic:
		OnRspQryTopProcessInfoTopic(pMessage, nSequenceSeries);
		break;
	///process应答
	case FTD_TID_RtnTopProcessInfoTopic:
		OnRtnTopProcessInfoTopic(pMessage, nSequenceSeries);
		break;
	///filesystem应答
	case FTD_TID_RspQryFileSystemInfoTopic:
		OnRspQryFileSystemInfoTopic(pMessage, nSequenceSeries);
		break;
	///filesystem应答
	case FTD_TID_RtnFileSystemInfoTopic:
		OnRtnFileSystemInfoTopic(pMessage, nSequenceSeries);
		break;
	///network应答
	case FTD_TID_RspQryNetworkInfoTopic:
		OnRspQryNetworkInfoTopic(pMessage, nSequenceSeries);
		break;
	///network应答
	case FTD_TID_RtnNetworkInfoTopic:
		OnRtnNetworkInfoTopic(pMessage, nSequenceSeries);
		break;
	///获得监控对象信息应答
	case FTD_TID_RspQryMonitorObjectTopic:
		OnRspQryMonitorObjectTopic(pMessage, nSequenceSeries);
		break;
	///获得监控对象信息应答
	case FTD_TID_RtnMonitorObjectTopic:
		OnRtnMonitorObjectTopic(pMessage, nSequenceSeries);
		break;
	///获得业务进程和主机的对应关系应答
	case FTD_TID_RspQryObjectRationalTopic:
		OnRspQryObjectRationalTopic(pMessage, nSequenceSeries);
		break;
	///获得业务进程和主机的对应关系应答
	case FTD_TID_RtnObjectRationalTopic:
		OnRtnObjectRationalTopic(pMessage, nSequenceSeries);
		break;
	///日志文件内容应答
	case FTD_TID_RspQrySyslogInfoTopic:
		OnRspQrySyslogInfoTopic(pMessage, nSequenceSeries);
		break;
	///日志文件内容应答
	case FTD_TID_RtnSyslogInfoTopic:
		OnRtnSyslogInfoTopic(pMessage, nSequenceSeries);
		break;
	///监控内容订阅应答
	case FTD_TID_RspQrySubscriberTopic:
		OnRspQrySubscriberTopic(pMessage, nSequenceSeries);
		break;
	///对象关系查询应答
	case FTD_TID_RspQryOidRelationTopic:
		OnRspQryOidRelationTopic(pMessage, nSequenceSeries);
		break;
	///对象关系查询应答
	case FTD_TID_RtnOidRelationTopic:
		OnRtnOidRelationTopic(pMessage, nSequenceSeries);
		break;
	///用户信息查询请求应答
	case FTD_TID_RspQryUserInfoTopic:
		OnRspQryUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///用户信息查询请求应答
	case FTD_TID_RtnUserInfoTopic:
		OnRtnUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///在线用户信息查询请求应答
	case FTD_TID_RspQryOnlineUserInfoTopic:
		OnRspQryOnlineUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///在线用户信息查询请求应答
	case FTD_TID_RtnOnlineUserInfoTopic:
		OnRtnOnlineUserInfoTopic(pMessage, nSequenceSeries);
		break;
	///告警事件查询请求应答
	case FTD_TID_RspQryWarningEventTopic:
		OnRspQryWarningEventTopic(pMessage, nSequenceSeries);
		break;
	///告警事件查询请求应答
	case FTD_TID_RtnWarningEventTopic:
		OnRtnWarningEventTopic(pMessage, nSequenceSeries);
		break;
	///对象状态指标查询应答
	case FTD_TID_RspQryObjectAttrTopic:
		OnRspQryObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///对象状态指标查询应答
	case FTD_TID_RtnObjectAttrTopic:
		OnRtnObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///无效报单查询应答
	case FTD_TID_RspQryInvalidateOrderTopic:
		OnRspQryInvalidateOrderTopic(pMessage, nSequenceSeries);
		break;
	///无效报单查询应答
	case FTD_TID_RtnInvalidateOrderTopic:
		OnRtnInvalidateOrderTopic(pMessage, nSequenceSeries);
		break;
	///报单状态查询应答
	case FTD_TID_RspQryOrderStatusTopic:
		OnRspQryOrderStatusTopic(pMessage, nSequenceSeries);
		break;
	///报单状态查询应答
	case FTD_TID_RtnOrderStatusTopic:
		OnRtnOrderStatusTopic(pMessage, nSequenceSeries);
		break;
	///报单成交查询应答
	case FTD_TID_RspQryBargainOrderTopic:
		OnRspQryBargainOrderTopic(pMessage, nSequenceSeries);
		break;
	///报单成交查询应答
	case FTD_TID_RtnBargainOrderTopic:
		OnRtnBargainOrderTopic(pMessage, nSequenceSeries);
		break;
	///合约基本属性查询应答
	case FTD_TID_RspQryInstPropertyTopic:
		OnRspQryInstPropertyTopic(pMessage, nSequenceSeries);
		break;
	///合约基本属性查询应答
	case FTD_TID_RtnInstPropertyTopic:
		OnRtnInstPropertyTopic(pMessage, nSequenceSeries);
		break;
	///合约保证金率查询应答
	case FTD_TID_RspQryMarginRateTopic:
		OnRspQryMarginRateTopic(pMessage, nSequenceSeries);
		break;
	///合约保证金率查询应答
	case FTD_TID_RtnMarginRateTopic:
		OnRtnMarginRateTopic(pMessage, nSequenceSeries);
		break;
	///合约涨跌停板查询应答
	case FTD_TID_RspQryPriceLimitTopic:
		OnRspQryPriceLimitTopic(pMessage, nSequenceSeries);
		break;
	///合约涨跌停板查询应答
	case FTD_TID_RtnPriceLimitTopic:
		OnRtnPriceLimitTopic(pMessage, nSequenceSeries);
		break;
	///会员限仓查询应答
	case FTD_TID_RspQryPartPosiLimitTopic:
		OnRspQryPartPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///会员限仓查询应答
	case FTD_TID_RtnPartPosiLimitTopic:
		OnRtnPartPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///客户限仓查询应答
	case FTD_TID_RspQryClientPosiLimitTopic:
		OnRspQryClientPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///客户限仓查询应答
	case FTD_TID_RtnClientPosiLimitTopic:
		OnRtnClientPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///特殊客户限仓查询应答
	case FTD_TID_RspQrySpecialPosiLimitTopic:
		OnRspQrySpecialPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///特殊客户限仓查询应答
	case FTD_TID_RtnSpecialPosiLimitTopic:
		OnRtnSpecialPosiLimitTopic(pMessage, nSequenceSeries);
		break;
	///账户出入金查询应答
	case FTD_TID_RspQryTransactionChgTopic:
		OnRspQryTransactionChgTopic(pMessage, nSequenceSeries);
		break;
	///账户出入金查询应答
	case FTD_TID_RtnTransactionChgTopic:
		OnRtnTransactionChgTopic(pMessage, nSequenceSeries);
		break;
	///客户数据变动查询应答
	case FTD_TID_RspQryClientChgTopic:
		OnRspQryClientChgTopic(pMessage, nSequenceSeries);
		break;
	///客户数据变动查询应答
	case FTD_TID_RtnClientChgTopic:
		OnRtnClientChgTopic(pMessage, nSequenceSeries);
		break;
	///会员客户对照变动查询应答
	case FTD_TID_RspQryPartClientChgTopic:
		OnRspQryPartClientChgTopic(pMessage, nSequenceSeries);
		break;
	///会员客户对照变动查询应答
	case FTD_TID_RtnPartClientChgTopic:
		OnRtnPartClientChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RspQryPosiLimitChgTopic:
		OnRspQryPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RtnPosiLimitChgTopic:
		OnRtnPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///保值额度变动查询应答
	case FTD_TID_RspQryHedgeDetailChgTopic:
		OnRspQryHedgeDetailChgTopic(pMessage, nSequenceSeries);
		break;
	///保值额度变动查询应答
	case FTD_TID_RtnHedgeDetailChgTopic:
		OnRtnHedgeDetailChgTopic(pMessage, nSequenceSeries);
		break;
	///会员变动查询应答
	case FTD_TID_RspQryParticipantChgTopic:
		OnRspQryParticipantChgTopic(pMessage, nSequenceSeries);
		break;
	///会员变动查询应答
	case FTD_TID_RtnParticipantChgTopic:
		OnRtnParticipantChgTopic(pMessage, nSequenceSeries);
		break;
	///保证金率变动查询应答
	case FTD_TID_RspQryMarginRateChgTopic:
		OnRspQryMarginRateChgTopic(pMessage, nSequenceSeries);
		break;
	///保证金率变动查询应答
	case FTD_TID_RtnMarginRateChgTopic:
		OnRtnMarginRateChgTopic(pMessage, nSequenceSeries);
		break;
	///IP地址变动查询应答
	case FTD_TID_RspQryUserIpChgTopic:
		OnRspQryUserIpChgTopic(pMessage, nSequenceSeries);
		break;
	///IP地址变动查询应答
	case FTD_TID_RtnUserIpChgTopic:
		OnRtnUserIpChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RspQryClientPosiLimitChgTopic:
		OnRspQryClientPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RtnClientPosiLimitChgTopic:
		OnRtnClientPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RspQrySpecPosiLimitChgTopic:
		OnRspQrySpecPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///限仓数据变动查询应答
	case FTD_TID_RtnSpecPosiLimitChgTopic:
		OnRtnSpecPosiLimitChgTopic(pMessage, nSequenceSeries);
		break;
	///历史对象状态指标查询应答
	case FTD_TID_RspQryHistoryObjectAttrTopic:
		OnRspQryHistoryObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///历史对象状态指标查询应答
	case FTD_TID_RtnHistoryObjectAttrTopic:
		OnRtnHistoryObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///前置响应信息查询应答
	case FTD_TID_RspQryFrontInfoTopic:
		OnRspQryFrontInfoTopic(pMessage, nSequenceSeries);
		break;
	///前置响应信息查询应答
	case FTD_TID_RtnFrontInfoTopic:
		OnRtnFrontInfoTopic(pMessage, nSequenceSeries);
		break;
	///用户登录应答
	case FTD_TID_RspQrySysUserLoginTopic:
		OnRspQrySysUserLoginTopic(pMessage, nSequenceSeries);
		break;
	///用户登出应答
	case FTD_TID_RspQrySysUserLogoutTopic:
		OnRspQrySysUserLogoutTopic(pMessage, nSequenceSeries);
		break;
	///用户修改密码应答
	case FTD_TID_RspQrySysUserPasswordUpdateTopic:
		OnRspQrySysUserPasswordUpdateTopic(pMessage, nSequenceSeries);
		break;
	///注册用户应答
	case FTD_TID_RspQrySysUserRegisterTopic:
		OnRspQrySysUserRegisterTopic(pMessage, nSequenceSeries);
		break;
	///删除用户应答
	case FTD_TID_RspQrySysUserDeleteTopic:
		OnRspQrySysUserDeleteTopic(pMessage, nSequenceSeries);
		break;
	///会员初始化应答
	case FTD_TID_RspQryParticipantInitTopic:
		OnRspQryParticipantInitTopic(pMessage, nSequenceSeries);
		break;
	///会员初始化应答
	case FTD_TID_RtnParticipantInitTopic:
		OnRtnParticipantInitTopic(pMessage, nSequenceSeries);
		break;
	///座席初始化应答
	case FTD_TID_RspQryUserInitTopic:
		OnRspQryUserInitTopic(pMessage, nSequenceSeries);
		break;
	///座席初始化应答
	case FTD_TID_RtnUserInitTopic:
		OnRtnUserInitTopic(pMessage, nSequenceSeries);
		break;
	///客户初始化应答
	case FTD_TID_RspQryClientInitTopic:
		OnRspQryClientInitTopic(pMessage, nSequenceSeries);
		break;
	///客户初始化应答
	case FTD_TID_RtnClientInitTopic:
		OnRtnClientInitTopic(pMessage, nSequenceSeries);
		break;
	///交易日志查询应答
	case FTD_TID_RspQryTradeLogTopic:
		OnRspQryTradeLogTopic(pMessage, nSequenceSeries);
		break;
	///交易日志查询应答
	case FTD_TID_RtnTradeLogTopic:
		OnRtnTradeLogTopic(pMessage, nSequenceSeries);
		break;
	///交易系统登录信息
	case FTD_TID_RspQryTradeUserLoginInfoTopic:
		OnRspQryTradeUserLoginInfoTopic(pMessage, nSequenceSeries);
		break;
	///交易系统登录信息
	case FTD_TID_RtnTradeUserLoginInfoTopic:
		OnRtnTradeUserLoginInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员交易查询应答
	case FTD_TID_RspQryPartTradeTopic:
		OnRspQryPartTradeTopic(pMessage, nSequenceSeries);
		break;
	///交易峰值查询应答
	case FTD_TID_RspQryTradepeakTopic:
		OnRspQryTradepeakTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RtnUpdateSysConfigTopic:
		OnRtnUpdateSysConfigTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RtnSysUser:
		OnRtnSysUser(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RspQryHistoryCpuInfoTopic:
		OnRspQryHistoryCpuInfoTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RspQryHistoryMemInfoTopic:
		OnRspQryHistoryMemInfoTopic(pMessage, nSequenceSeries);
		break;
	///
	case FTD_TID_RspQryHistoryNetworkInfoTopic:
		OnRspQryHistoryNetworkInfoTopic(pMessage, nSequenceSeries);
		break;
	///监控系统在线用户应答
	case FTD_TID_RspQryMonitorOnlineUser:
		OnRspQryMonitorOnlineUser(pMessage, nSequenceSeries);
		break;
	///交易系统前置统计应答
	case FTD_TID_RspQryFrontStat:
		OnRspQryFrontStat(pMessage, nSequenceSeries);
		break;
	///监控系统时钟同步
	case FTD_TID_RtnSysTimeSyncTopic:
		OnRtnSysTimeSyncTopic(pMessage, nSequenceSeries);
		break;
	///数据中心切换通知
	case FTD_TID_RtnDataCenterChgTopic:
		OnRtnDataCenterChgTopic(pMessage, nSequenceSeries);
		break;
	///历史峰值查询应答
	case FTD_TID_RspQryHistoryTradePeakTopic:
		OnRspQryHistoryTradePeakTopic(pMessage, nSequenceSeries);
		break;
	///日志事件查询应答
	case FTD_TID_RspQrySyslogEventTopic:
		OnRspQrySyslogEventTopic(pMessage, nSequenceSeries);
		break;
	///日志事件应答
	case FTD_TID_RtnSyslogEventTopic:
		OnRtnSyslogEventTopic(pMessage, nSequenceSeries);
		break;
	///Web应用信息
	case FTD_TID_RspQryWebAppInfoTopic:
		OnRspQryWebAppInfoTopic(pMessage, nSequenceSeries);
		break;
	///Web应用信息
	case FTD_TID_RtnWebAppInfoTopic:
		OnRtnWebAppInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用servlet信息
	case FTD_TID_RspQryServletInfoTopic:
		OnRspQryServletInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用servlet信息
	case FTD_TID_RtnServletInfoTopic:
		OnRtnServletInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件信息
	case FTD_TID_RspQryFileInfoTopic:
		OnRspQryFileInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件信息
	case FTD_TID_RtnFileInfoTopic:
		OnRtnFileInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用会话信息
	case FTD_TID_RspQrySessionInfoTopic:
		OnRspQrySessionInfoTopic(pMessage, nSequenceSeries);
		break;
	///应用会话信息
	case FTD_TID_RtnSessionInfoTopic:
		OnRtnSessionInfoTopic(pMessage, nSequenceSeries);
		break;
	///JDBC信息
	case FTD_TID_RspQryJDBCInfoTopic:
		OnRspQryJDBCInfoTopic(pMessage, nSequenceSeries);
		break;
	///JDBC信息
	case FTD_TID_RtnJDBCInfoTopic:
		OnRtnJDBCInfoTopic(pMessage, nSequenceSeries);
		break;
	///线程信息
	case FTD_TID_RspQryThreadInfoTopic:
		OnRspQryThreadInfoTopic(pMessage, nSequenceSeries);
		break;
	///线程信息
	case FTD_TID_RtnThreadInfoTopic:
		OnRtnThreadInfoTopic(pMessage, nSequenceSeries);
		break;
	///虚拟机信息
	case FTD_TID_RspQryVMInfoTopic:
		OnRspQryVMInfoTopic(pMessage, nSequenceSeries);
		break;
	///虚拟机信息
	case FTD_TID_RtnVMInfoTopic:
		OnRtnVMInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统属性信息
	case FTD_TID_RspQryPropertyInfoTopic:
		OnRspQryPropertyInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统属性信息
	case FTD_TID_RtnPropertyInfoTopic:
		OnRtnPropertyInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统内存池信息
	case FTD_TID_RspQryMemPoolInfoTopic:
		OnRspQryMemPoolInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统内存池信息
	case FTD_TID_RtnMemPoolInfoTopic:
		OnRtnMemPoolInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件内容信息
	case FTD_TID_RspQryFileContentInfoTopic:
		OnRspQryFileContentInfoTopic(pMessage, nSequenceSeries);
		break;
	///文件内容信息
	case FTD_TID_RtnFileContentInfoTopic:
		OnRtnFileContentInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接信息
	case FTD_TID_RspQryConnectionInfoTopic:
		OnRspQryConnectionInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接信息
	case FTD_TID_RtnConnectionInfoTopic:
		OnRtnConnectionInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接器信息
	case FTD_TID_RspQryConnectorInfoTopic:
		OnRspQryConnectorInfoTopic(pMessage, nSequenceSeries);
		break;
	///连接器信息
	case FTD_TID_RtnConnectorInfoTopic:
		OnRtnConnectorInfoTopic(pMessage, nSequenceSeries);
		break;
	///数据库查询应答
	case FTD_TID_RspQryDBQueryTopic:
		OnRspQryDBQueryTopic(pMessage, nSequenceSeries);
		break;
	///数据库查询应答
	case FTD_TID_RtnDBQueryTopic:
		OnRtnDBQueryTopic(pMessage, nSequenceSeries);
		break;
	///通用返回应答
	case FTD_TID_RspQryGeneralFieldTopic:
		OnRspQryGeneralFieldTopic(pMessage, nSequenceSeries);
		break;
	///通用返回应答
	case FTD_TID_RtnGeneralFieldTopic:
		OnRtnGeneralFieldTopic(pMessage, nSequenceSeries);
		break;
	///文件传输应答
	case FTD_TID_RspQryGetFileTopic:
		OnRspQryGetFileTopic(pMessage, nSequenceSeries);
		break;
	///告警明细
	case FTD_TID_RspQryWarningQueryTopic:
		OnRspQryWarningQueryTopic(pMessage, nSequenceSeries);
		break;
	///告警激活变更
	case FTD_TID_RtnWarningActiveChange:
		OnRtnWarningActiveChange(pMessage, nSequenceSeries);
		break;
	///通用操作
	case FTD_TID_RspQryGeneralOperateTopic:
		OnRspQryGeneralOperateTopic(pMessage, nSequenceSeries);
		break;
	///通用操作
	case FTD_TID_RtnGeneralOperateTopic:
		OnRtnGeneralOperateTopic(pMessage, nSequenceSeries);
		break;
	///网络设备连接关系
	case FTD_TID_RspQryNetDeviceLinkedTopic:
		OnRspQryNetDeviceLinkedTopic(pMessage, nSequenceSeries);
		break;
	///网络设备连接关系
	case FTD_TID_RtnNetDeviceLinkedTopic:
		OnRtnNetDeviceLinkedTopic(pMessage, nSequenceSeries);
		break;
	///交易系统登录信息
	case FTD_TID_RspQryTradeUserLoginStatTopic:
		OnRspQryTradeUserLoginStatTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单响应信息
	case FTD_TID_RspQryTradeFrontOrderRttStatTopic:
		OnRspQryTradeFrontOrderRttStatTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单响应信息
	case FTD_TID_RtnTradeFrontOrderRttStatTopic:
		OnRtnTradeFrontOrderRttStatTopic(pMessage, nSequenceSeries);
		break;
	///会员席位交易状态
	case FTD_TID_RspQryParticTradeOrderStatesTopic:
		OnRspQryParticTradeOrderStatesTopic(pMessage, nSequenceSeries);
		break;
	///会员席位交易状态
	case FTD_TID_RtnParticTradeOrderStatesTopic:
		OnRtnParticTradeOrderStatesTopic(pMessage, nSequenceSeries);
		break;
	///系统路由信息
	case FTD_TID_RspQryRouterInfoTopic:
		OnRspQryRouterInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统路由信息
	case FTD_TID_RtnRouterInfoTopic:
		OnRtnRouterInfoTopic(pMessage, nSequenceSeries);
		break;
	///磁盘I/O信息
	case FTD_TID_RspQryDiskIOTopic:
		OnRspQryDiskIOTopic(pMessage, nSequenceSeries);
		break;
	///磁盘I/O信息
	case FTD_TID_RtnDiskIOTopic:
		OnRtnDiskIOTopic(pMessage, nSequenceSeries);
		break;
	///系统状态信息
	case FTD_TID_RspQryStatInfoTopic:
		OnRspQryStatInfoTopic(pMessage, nSequenceSeries);
		break;
	///系统状态信息
	case FTD_TID_RtnStatInfoTopic:
		OnRtnStatInfoTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单分布区间
	case FTD_TID_RspQryTradeOrderRttCutLineTopic:
		OnRspQryTradeOrderRttCutLineTopic(pMessage, nSequenceSeries);
		break;
	///交易系统前置报单分布区间
	case FTD_TID_RtnTradeOrderRttCutLineTopic:
		OnRtnTradeOrderRttCutLineTopic(pMessage, nSequenceSeries);
		break;
	///会员客户信息
	case FTD_TID_RspQryClientInfoTopic:
		OnRspQryClientInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员客户信息
	case FTD_TID_RtnClientInfoTopic:
		OnRtnClientInfoTopic(pMessage, nSequenceSeries);
		break;
	///应答事件描述
	case FTD_TID_RspQryEventDescriptionTopic:
		OnRspQryEventDescriptionTopic(pMessage, nSequenceSeries);
		break;
	///订阅事件描述
	case FTD_TID_RtnEventDescriptionTopic:
		OnRtnEventDescriptionTopic(pMessage, nSequenceSeries);
		break;
	///应答前置唯一ID信息
	case FTD_TID_RspQryFrontUniqueIDTopic:
		OnRspQryFrontUniqueIDTopic(pMessage, nSequenceSeries);
		break;
	///订阅前置唯一ID信息
	case FTD_TID_RtnFrontUniqueIDTopic:
		OnRtnFrontUniqueIDTopic(pMessage, nSequenceSeries);
		break;
	///会员线路地址变更回应
	case FTD_TID_RspQryNetPartyLinkAddrChangeTopic:
		OnRspQryNetPartyLinkAddrChangeTopic(pMessage, nSequenceSeries);
		break;
	///订阅会员线路地址变更信息
	case FTD_TID_RtnNetPartyLinkAddrChangeTopic:
		OnRtnNetPartyLinkAddrChangeTopic(pMessage, nSequenceSeries);
		break;
	///应答已删除会员列表信息
	case FTD_TID_RspQryNetDelPartyLinkInfoTopic:
		OnRspQryNetDelPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///订阅已删除会员列表信息
	case FTD_TID_RtnNetDelPartyLinkInfoTopic:
		OnRtnNetDelPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///返回网络性能排序
	case FTD_TID_RspQryPerformanceTopTopic:
		OnRspQryPerformanceTopTopic(pMessage, nSequenceSeries);
		break;
	///订阅网络性能排序
	case FTD_TID_RtnPerformanceTopTopic:
		OnRtnPerformanceTopTopic(pMessage, nSequenceSeries);
		break;
	///返回约状态切换数据
	case FTD_TID_RspQryInstrumentStatusTopic:
		OnRspQryInstrumentStatusTopic(pMessage, nSequenceSeries);
		break;
	///订阅约状态切换数据
	case FTD_TID_RtnInstrumentStatusTopic:
		OnRtnInstrumentStatusTopic(pMessage, nSequenceSeries);
		break;
	///返回合约交易节信息
	case FTD_TID_RspQryCurrTradingSegmentAttrTopic:
		OnRspQryCurrTradingSegmentAttrTopic(pMessage, nSequenceSeries);
		break;
	///订阅合约交易节信息
	case FTD_TID_RtnCurrTradingSegmentAttrTopic:
		OnRtnCurrTradingSegmentAttrTopic(pMessage, nSequenceSeries);
		break;
	///网络大区划分应答
	case FTD_TID_RspQryNetAreaTopic:
		OnRspQryNetAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络大区划分应答
	case FTD_TID_RtnNetAreaTopic:
		OnRtnNetAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络子区应答
	case FTD_TID_RspQryNetSubAreaTopic:
		OnRspQryNetSubAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络子区应答
	case FTD_TID_RtnNetSubAreaTopic:
		OnRtnNetSubAreaTopic(pMessage, nSequenceSeries);
		break;
	///网络子区IP应答
	case FTD_TID_RspQryNetSubAreaIPTopic:
		OnRspQryNetSubAreaIPTopic(pMessage, nSequenceSeries);
		break;
	///网络子区IP应答
	case FTD_TID_RtnNetSubAreaIPTopic:
		OnRtnNetSubAreaIPTopic(pMessage, nSequenceSeries);
		break;
	///网络设备
	case FTD_TID_RspQryNetDeviceTopic:
		OnRspQryNetDeviceTopic(pMessage, nSequenceSeries);
		break;
	///网络设备
	case FTD_TID_RtnNetDeviceTopic:
		OnRtnNetDeviceTopic(pMessage, nSequenceSeries);
		break;
	///网络设备探测请求应答
	case FTD_TID_RspQryNetDeviceDetectTopic:
		OnRspQryNetDeviceDetectTopic(pMessage, nSequenceSeries);
		break;
	///大楼
	case FTD_TID_RspQryNetBuildingTopic:
		OnRspQryNetBuildingTopic(pMessage, nSequenceSeries);
		break;
	///大楼
	case FTD_TID_RtnNetBuildingTopic:
		OnRtnNetBuildingTopic(pMessage, nSequenceSeries);
		break;
	///机房
	case FTD_TID_RspQryNetRoomTopic:
		OnRspQryNetRoomTopic(pMessage, nSequenceSeries);
		break;
	///机房
	case FTD_TID_RtnNetRoomTopic:
		OnRtnNetRoomTopic(pMessage, nSequenceSeries);
		break;
	///机柜
	case FTD_TID_RspQryNetCabinetsTopic:
		OnRspQryNetCabinetsTopic(pMessage, nSequenceSeries);
		break;
	///机柜
	case FTD_TID_RtnNetCabinetsTopic:
		OnRtnNetCabinetsTopic(pMessage, nSequenceSeries);
		break;
	///OID
	case FTD_TID_RspQryNetOIDTopic:
		OnRspQryNetOIDTopic(pMessage, nSequenceSeries);
		break;
	///OID
	case FTD_TID_RtnNetOIDTopic:
		OnRtnNetOIDTopic(pMessage, nSequenceSeries);
		break;
	///时间策略
	case FTD_TID_RspQryNetTimePolicyTopic:
		OnRspQryNetTimePolicyTopic(pMessage, nSequenceSeries);
		break;
	///时间策略
	case FTD_TID_RtnNetTimePolicyTopic:
		OnRtnNetTimePolicyTopic(pMessage, nSequenceSeries);
		break;
	///采集任务
	case FTD_TID_RspQryNetGatherTaskTopic:
		OnRspQryNetGatherTaskTopic(pMessage, nSequenceSeries);
		break;
	///采集任务
	case FTD_TID_RtnNetGatherTaskTopic:
		OnRtnNetGatherTaskTopic(pMessage, nSequenceSeries);
		break;
	///设备变更
	case FTD_TID_RspQryNetDeviceChgTopic:
		OnRspQryNetDeviceChgTopic(pMessage, nSequenceSeries);
		break;
	///设备变更
	case FTD_TID_RtnNetDeviceChgTopic:
		OnRtnNetDeviceChgTopic(pMessage, nSequenceSeries);
		break;
	///常用设备型号
	case FTD_TID_RspQryNetDeviceTypeTopic:
		OnRspQryNetDeviceTypeTopic(pMessage, nSequenceSeries);
		break;
	///常用设备型号
	case FTD_TID_RtnNetDeviceTypeTopic:
		OnRtnNetDeviceTypeTopic(pMessage, nSequenceSeries);
		break;
	///常用设备类别
	case FTD_TID_RspQryNetDeviceCategoryTopic:
		OnRspQryNetDeviceCategoryTopic(pMessage, nSequenceSeries);
		break;
	///常用设备类别
	case FTD_TID_RtnNetDeviceCategoryTopic:
		OnRtnNetDeviceCategoryTopic(pMessage, nSequenceSeries);
		break;
	///设备厂商
	case FTD_TID_RspQryNetManufactoryTopic:
		OnRspQryNetManufactoryTopic(pMessage, nSequenceSeries);
		break;
	///设备厂商
	case FTD_TID_RtnNetManufactoryTopic:
		OnRtnNetManufactoryTopic(pMessage, nSequenceSeries);
		break;
	///设备共同体
	case FTD_TID_RspQryNetCommunityTopic:
		OnRspQryNetCommunityTopic(pMessage, nSequenceSeries);
		break;
	///设备共同体
	case FTD_TID_RtnNetCommunityTopic:
		OnRtnNetCommunityTopic(pMessage, nSequenceSeries);
		break;
	///端口类型
	case FTD_TID_RspQryNetPortTypeTopic:
		OnRspQryNetPortTypeTopic(pMessage, nSequenceSeries);
		break;
	///端口类型
	case FTD_TID_RtnNetPortTypeTopic:
		OnRtnNetPortTypeTopic(pMessage, nSequenceSeries);
		break;
	///会员接入地点
	case FTD_TID_RspQryNetPartAccessSpotTopic:
		OnRspQryNetPartAccessSpotTopic(pMessage, nSequenceSeries);
		break;
	///会员接入地点
	case FTD_TID_RtnNetPartAccessSpotTopic:
		OnRtnNetPartAccessSpotTopic(pMessage, nSequenceSeries);
		break;
	///端口
	case FTD_TID_RspQryNetInterfaceTopic:
		OnRspQryNetInterfaceTopic(pMessage, nSequenceSeries);
		break;
	///端口
	case FTD_TID_RtnNetInterfaceTopic:
		OnRtnNetInterfaceTopic(pMessage, nSequenceSeries);
		break;
	///GeneralOID
	case FTD_TID_RspQryNetGeneralOIDTopic:
		OnRspQryNetGeneralOIDTopic(pMessage, nSequenceSeries);
		break;
	///GeneralOID
	case FTD_TID_RtnNetGeneralOIDTopic:
		OnRtnNetGeneralOIDTopic(pMessage, nSequenceSeries);
		break;
	///监控对象类别
	case FTD_TID_RspQryNetMonitorTypeTopic:
		OnRspQryNetMonitorTypeTopic(pMessage, nSequenceSeries);
		break;
	///监控对象类别
	case FTD_TID_RtnNetMonitorTypeTopic:
		OnRtnNetMonitorTypeTopic(pMessage, nSequenceSeries);
		break;
	///指标统表
	case FTD_TID_RspQryNetMonitorAttrScopeTopic:
		OnRspQryNetMonitorAttrScopeTopic(pMessage, nSequenceSeries);
		break;
	///指标统表
	case FTD_TID_RtnNetMonitorAttrScopeTopic:
		OnRtnNetMonitorAttrScopeTopic(pMessage, nSequenceSeries);
		break;
	///监控指标表
	case FTD_TID_RspQryNetMonitorAttrTypeTopic:
		OnRspQryNetMonitorAttrTypeTopic(pMessage, nSequenceSeries);
		break;
	///监控指标表
	case FTD_TID_RtnNetMonitorAttrTypeTopic:
		OnRtnNetMonitorAttrTypeTopic(pMessage, nSequenceSeries);
		break;
	///监控对象指标表
	case FTD_TID_RspQryNetMonitorObjectAttrTopic:
		OnRspQryNetMonitorObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///监控对象指标表
	case FTD_TID_RtnNetMonitorObjectAttrTopic:
		OnRtnNetMonitorObjectAttrTopic(pMessage, nSequenceSeries);
		break;
	///设备对象组表
	case FTD_TID_RspQryNetMonitorDeviceGroupTopic:
		OnRspQryNetMonitorDeviceGroupTopic(pMessage, nSequenceSeries);
		break;
	///设备对象组表
	case FTD_TID_RtnNetMonitorDeviceGroupTopic:
		OnRtnNetMonitorDeviceGroupTopic(pMessage, nSequenceSeries);
		break;
	///任务信息表
	case FTD_TID_RspQryNetMonitorTaskInfoTopic:
		OnRspQryNetMonitorTaskInfoTopic(pMessage, nSequenceSeries);
		break;
	///任务信息表
	case FTD_TID_RtnNetMonitorTaskInfoTopic:
		OnRtnNetMonitorTaskInfoTopic(pMessage, nSequenceSeries);
		break;
	///任务结果表
	case FTD_TID_RspQryNetMonitorTaskResultTopic:
		OnRspQryNetMonitorTaskResultTopic(pMessage, nSequenceSeries);
		break;
	///任务结果表
	case FTD_TID_RtnNetMonitorTaskResultTopic:
		OnRtnNetMonitorTaskResultTopic(pMessage, nSequenceSeries);
		break;
	///任务对象集
	case FTD_TID_RspQryNetMonitorTaskObjectSetTopic:
		OnRspQryNetMonitorTaskObjectSetTopic(pMessage, nSequenceSeries);
		break;
	///任务对象集
	case FTD_TID_RtnNetMonitorTaskObjectSetTopic:
		OnRtnNetMonitorTaskObjectSetTopic(pMessage, nSequenceSeries);
		break;
	///会员链路信息表
	case FTD_TID_RspQryNetPartyLinkInfoTopic:
		OnRspQryNetPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员链路信息表
	case FTD_TID_RtnNetPartyLinkInfoTopic:
		OnRtnNetPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///监控动作指标对照表
	case FTD_TID_RspQryNetMonitorActionAttrTopic:
		OnRspQryNetMonitorActionAttrTopic(pMessage, nSequenceSeries);
		break;
	///模块
	case FTD_TID_RspQryNetModuleTopic:
		OnRspQryNetModuleTopic(pMessage, nSequenceSeries);
		break;
	///模块
	case FTD_TID_RtnNetModuleTopic:
		OnRtnNetModuleTopic(pMessage, nSequenceSeries);
		break;
	///任务结果状态表
	case FTD_TID_RspQryNetMonitorTaskStatusResultTopic:
		OnRspQryNetMonitorTaskStatusResultTopic(pMessage, nSequenceSeries);
		break;
	///任务结果状态表
	case FTD_TID_RtnNetMonitorTaskStatusResultTopic:
		OnRtnNetMonitorTaskStatusResultTopic(pMessage, nSequenceSeries);
		break;
	///设备配置表
	case FTD_TID_RspQryNetCfgFileTopic:
		OnRspQryNetCfgFileTopic(pMessage, nSequenceSeries);
		break;
	///设备配置表
	case FTD_TID_RtnNetCfgFileTopic:
		OnRtnNetCfgFileTopic(pMessage, nSequenceSeries);
		break;
	///任务结果规则分析表
	case FTD_TID_RspQryNetMonitorDeviceTaskTopic:
		OnRspQryNetMonitorDeviceTaskTopic(pMessage, nSequenceSeries);
		break;
	///任务结果规则分析表
	case FTD_TID_RtnNetMonitorDeviceTaskTopic:
		OnRtnNetMonitorDeviceTaskTopic(pMessage, nSequenceSeries);
		break;
	///文件通用操作
	case FTD_TID_RspQryFileGeneralOperTopic:
		OnRspQryFileGeneralOperTopic(pMessage, nSequenceSeries);
		break;
	///文件通用操作
	case FTD_TID_RtnFileGeneralOperTopic:
		OnRtnFileGeneralOperTopic(pMessage, nSequenceSeries);
		break;
	///基线表
	case FTD_TID_RspQryNetBaseLineTopic:
		OnRspQryNetBaseLineTopic(pMessage, nSequenceSeries);
		break;
	///基线表
	case FTD_TID_RtnNetBaseLineTopic:
		OnRtnNetBaseLineTopic(pMessage, nSequenceSeries);
		break;
	///基线结果表
	case FTD_TID_RspQryNetBaseLineResultTopic:
		OnRspQryNetBaseLineResultTopic(pMessage, nSequenceSeries);
		break;
	///基线结果表
	case FTD_TID_RtnNetBaseLineResultTopic:
		OnRtnNetBaseLineResultTopic(pMessage, nSequenceSeries);
		break;
	///会员链路状态信息表
	case FTD_TID_RspQryNetPartyLinkStatusInfoTopic:
		OnRspQryNetPartyLinkStatusInfoTopic(pMessage, nSequenceSeries);
		break;
	///会员链路状态信息表
	case FTD_TID_RtnNetPartyLinkStatusInfoTopic:
		OnRtnNetPartyLinkStatusInfoTopic(pMessage, nSequenceSeries);
		break;
	///本地ping结果
	case FTD_TID_RspQryNetLocalPingResultInfoTopic:
		OnRspQryNetLocalPingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///本地ping结果
	case FTD_TID_RtnNetLocalPingResultInfoTopic:
		OnRtnNetLocalPingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///远程ping结果
	case FTD_TID_RspQryNetRomotePingResultInfoTopic:
		OnRspQryNetRomotePingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///远程ping结果
	case FTD_TID_RtnNetRomotePingResultInfoTopic:
		OnRtnNetRomotePingResultInfoTopic(pMessage, nSequenceSeries);
		break;
	///返回会员链路费用表
	case FTD_TID_RspQryMemberLinkCostTopic:
		OnRspQryMemberLinkCostTopic(pMessage, nSequenceSeries);
		break;
	///订阅会员链路费用表
	case FTD_TID_RtnMemberLinkCostTopic:
		OnRtnMemberLinkCostTopic(pMessage, nSequenceSeries);
		break;
	///返回非会员链路表信息
	case FTD_TID_RspQryNetNonPartyLinkInfoTopic:
		OnRspQryNetNonPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	///订阅非会员链路表信息
	case FTD_TID_RtnNetNonPartyLinkInfoTopic:
		OnRtnNetNonPartyLinkInfoTopic(pMessage, nSequenceSeries);
		break;
	default:
		break;
	}
}

CShfeFtdcSysUserApi *CShfeFtdcSysUserApi::CreateFtdcSysUserApi(const char *pszFlowPath)
{
	return new CFtdcSysUserApiImpl(pszFlowPath, new CSelectReactor());
}

///CPU应答
void CFtdcSysUserApiImpl::OnRspQryTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTopCpuInfoField RspQryTopCpuInfo;
	CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTopCpuInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTopCpuInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTopCpuInfo = (CShfeFtdcRspQryTopCpuInfoField *)&RspQryTopCpuInfo;
			m_pSpi->OnRspQryTopCpuInfoTopic(pRspQryTopCpuInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTopCpuInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopCpuInfoTopic(pRspQryTopCpuInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///CPU应答
void CFtdcSysUserApiImpl::OnRtnTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTopCpuInfoField RtnTopCpuInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTopCpuInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTopCpuInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTopCpuInfoTopic((CShfeFtdcRtnTopCpuInfoField *)&RtnTopCpuInfo);
		}
		itor.Next();
	}
}

///Mem应答
void CFtdcSysUserApiImpl::OnRspQryTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTopMemInfoField RspQryTopMemInfo;
	CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTopMemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTopMemInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTopMemInfo = (CShfeFtdcRspQryTopMemInfoField *)&RspQryTopMemInfo;
			m_pSpi->OnRspQryTopMemInfoTopic(pRspQryTopMemInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTopMemInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopMemInfoTopic(pRspQryTopMemInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///Mem应答
void CFtdcSysUserApiImpl::OnRtnTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTopMemInfoField RtnTopMemInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTopMemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTopMemInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTopMemInfoTopic((CShfeFtdcRtnTopMemInfoField *)&RtnTopMemInfo);
		}
		itor.Next();
	}
}

///process应答
void CFtdcSysUserApiImpl::OnRspQryTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTopProcessInfoField RspQryTopProcessInfo;
	CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTopProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTopProcessInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTopProcessInfo = (CShfeFtdcRspQryTopProcessInfoField *)&RspQryTopProcessInfo;
			m_pSpi->OnRspQryTopProcessInfoTopic(pRspQryTopProcessInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTopProcessInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTopProcessInfoTopic(pRspQryTopProcessInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///process应答
void CFtdcSysUserApiImpl::OnRtnTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTopProcessInfoField RtnTopProcessInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTopProcessInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTopProcessInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTopProcessInfoTopic((CShfeFtdcRtnTopProcessInfoField *)&RtnTopProcessInfo);
		}
		itor.Next();
	}
}

///filesystem应答
void CFtdcSysUserApiImpl::OnRspQryFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileSystemInfoField RspQryFileSystemInfo;
	CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileSystemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileSystemInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileSystemInfo = (CShfeFtdcRspQryFileSystemInfoField *)&RspQryFileSystemInfo;
			m_pSpi->OnRspQryFileSystemInfoTopic(pRspQryFileSystemInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryFileSystemInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileSystemInfoTopic(pRspQryFileSystemInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///filesystem应答
void CFtdcSysUserApiImpl::OnRtnFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnFileSystemInfoField RtnFileSystemInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileSystemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileSystemInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileSystemInfoTopic((CShfeFtdcRtnFileSystemInfoField *)&RtnFileSystemInfo);
		}
		itor.Next();
	}
}

///network应答
void CFtdcSysUserApiImpl::OnRspQryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetworkInfoField RspQryNetworkInfo;
	CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetworkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetworkInfo = (CShfeFtdcRspQryNetworkInfoField *)&RspQryNetworkInfo;
			m_pSpi->OnRspQryNetworkInfoTopic(pRspQryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetworkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetworkInfoTopic(pRspQryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///network应答
void CFtdcSysUserApiImpl::OnRtnNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetworkInfoField RtnNetworkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetworkInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetworkInfoTopic((CShfeFtdcRtnNetworkInfoField *)&RtnNetworkInfo);
		}
		itor.Next();
	}
}

///获得监控对象信息应答
void CFtdcSysUserApiImpl::OnRspQryMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonitorObjectField RspQryMonitorObject;
	CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonitorObjectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonitorObject);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonitorObject = (CShfeFtdcRspQryMonitorObjectField *)&RspQryMonitorObject;
			m_pSpi->OnRspQryMonitorObjectTopic(pRspQryMonitorObject, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryMonitorObject == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonitorObjectTopic(pRspQryMonitorObject, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///获得监控对象信息应答
void CFtdcSysUserApiImpl::OnRtnMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnMonitorObjectField RtnMonitorObject;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMonitorObjectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMonitorObject);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMonitorObjectTopic((CShfeFtdcRtnMonitorObjectField *)&RtnMonitorObject);
		}
		itor.Next();
	}
}

///获得业务进程和主机的对应关系应答
void CFtdcSysUserApiImpl::OnRspQryObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryObjectRationalField RspQryObjectRational;
	CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryObjectRationalField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryObjectRational);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryObjectRational = (CShfeFtdcRspQryObjectRationalField *)&RspQryObjectRational;
			m_pSpi->OnRspQryObjectRationalTopic(pRspQryObjectRational, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryObjectRational == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryObjectRationalTopic(pRspQryObjectRational, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///获得业务进程和主机的对应关系应答
void CFtdcSysUserApiImpl::OnRtnObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnObjectRationalField RtnObjectRational;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnObjectRationalField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnObjectRational);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnObjectRationalTopic((CShfeFtdcRtnObjectRationalField *)&RtnObjectRational);
		}
		itor.Next();
	}
}

///日志文件内容应答
void CFtdcSysUserApiImpl::OnRspQrySyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySyslogInfoField RspQrySyslogInfo;
	CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySyslogInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySyslogInfo = (CShfeFtdcRspQrySyslogInfoField *)&RspQrySyslogInfo;
			m_pSpi->OnRspQrySyslogInfoTopic(pRspQrySyslogInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySyslogInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySyslogInfoTopic(pRspQrySyslogInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///日志文件内容应答
void CFtdcSysUserApiImpl::OnRtnSyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnSyslogInfoField RtnSyslogInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSyslogInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSyslogInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSyslogInfoTopic((CShfeFtdcRtnSyslogInfoField *)&RtnSyslogInfo);
		}
		itor.Next();
	}
}

///监控内容订阅应答
void CFtdcSysUserApiImpl::OnRspQrySubscriberTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySubscriberField RspQrySubscriber;
	CShfeFtdcRspQrySubscriberField *pRspQrySubscriber = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySubscriberField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySubscriber);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySubscriber = (CShfeFtdcRspQrySubscriberField *)&RspQrySubscriber;
			m_pSpi->OnRspQrySubscriberTopic(pRspQrySubscriber, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySubscriber == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySubscriberTopic(pRspQrySubscriber, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对象关系查询应答
void CFtdcSysUserApiImpl::OnRspQryOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryOidRelationField RspQryOidRelation;
	CShfeFtdcRspQryOidRelationField *pRspQryOidRelation = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryOidRelationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryOidRelation);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryOidRelation = (CShfeFtdcRspQryOidRelationField *)&RspQryOidRelation;
			m_pSpi->OnRspQryOidRelationTopic(pRspQryOidRelation, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryOidRelation == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOidRelationTopic(pRspQryOidRelation, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对象关系查询应答
void CFtdcSysUserApiImpl::OnRtnOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnOidRelationField RtnOidRelation;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnOidRelationField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnOidRelation);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOidRelationTopic((CShfeFtdcRtnOidRelationField *)&RtnOidRelation);
		}
		itor.Next();
	}
}

///用户信息查询请求应答
void CFtdcSysUserApiImpl::OnRspQryUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryUserInfoField RspQryUserInfo;
	CShfeFtdcRspQryUserInfoField *pRspQryUserInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryUserInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryUserInfo = (CShfeFtdcRspQryUserInfoField *)&RspQryUserInfo;
			m_pSpi->OnRspQryUserInfoTopic(pRspQryUserInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryUserInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserInfoTopic(pRspQryUserInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户信息查询请求应答
void CFtdcSysUserApiImpl::OnRtnUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnUserInfoField RtnUserInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUserInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUserInfoTopic((CShfeFtdcRtnUserInfoField *)&RtnUserInfo);
		}
		itor.Next();
	}
}

///在线用户信息查询请求应答
void CFtdcSysUserApiImpl::OnRspQryOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryOnlineUserInfoField RspQryOnlineUserInfo;
	CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryOnlineUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryOnlineUserInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryOnlineUserInfo = (CShfeFtdcRspQryOnlineUserInfoField *)&RspQryOnlineUserInfo;
			m_pSpi->OnRspQryOnlineUserInfoTopic(pRspQryOnlineUserInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryOnlineUserInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOnlineUserInfoTopic(pRspQryOnlineUserInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///在线用户信息查询请求应答
void CFtdcSysUserApiImpl::OnRtnOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnOnlineUserInfoField RtnOnlineUserInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnOnlineUserInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnOnlineUserInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOnlineUserInfoTopic((CShfeFtdcRtnOnlineUserInfoField *)&RtnOnlineUserInfo);
		}
		itor.Next();
	}
}

///告警事件查询请求应答
void CFtdcSysUserApiImpl::OnRspQryWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryWarningEventField RspQryWarningEvent;
	CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryWarningEvent);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryWarningEvent = (CShfeFtdcRspQryWarningEventField *)&RspQryWarningEvent;
			m_pSpi->OnRspQryWarningEventTopic(pRspQryWarningEvent, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryWarningEvent == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryWarningEventTopic(pRspQryWarningEvent, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警事件查询请求应答
void CFtdcSysUserApiImpl::OnRtnWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnWarningEventField RtnWarningEvent;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnWarningEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnWarningEvent);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnWarningEventTopic((CShfeFtdcRtnWarningEventField *)&RtnWarningEvent);
		}
		itor.Next();
	}
}

///对象状态指标查询应答
void CFtdcSysUserApiImpl::OnRspQryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryObjectAttrField RspQryObjectAttr;
	CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryObjectAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryObjectAttr = (CShfeFtdcRspQryObjectAttrField *)&RspQryObjectAttr;
			m_pSpi->OnRspQryObjectAttrTopic(pRspQryObjectAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryObjectAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryObjectAttrTopic(pRspQryObjectAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///对象状态指标查询应答
void CFtdcSysUserApiImpl::OnRtnObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnObjectAttrField RtnObjectAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnObjectAttr);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnObjectAttrTopic((CShfeFtdcRtnObjectAttrField *)&RtnObjectAttr);
		}
		itor.Next();
	}
}

///无效报单查询应答
void CFtdcSysUserApiImpl::OnRspQryInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryInvalidateOrderField RspQryInvalidateOrder;
	CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryInvalidateOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryInvalidateOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryInvalidateOrder = (CShfeFtdcRspQryInvalidateOrderField *)&RspQryInvalidateOrder;
			m_pSpi->OnRspQryInvalidateOrderTopic(pRspQryInvalidateOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryInvalidateOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInvalidateOrderTopic(pRspQryInvalidateOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///无效报单查询应答
void CFtdcSysUserApiImpl::OnRtnInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnInvalidateOrderField RtnInvalidateOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnInvalidateOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnInvalidateOrder);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInvalidateOrderTopic((CShfeFtdcRtnInvalidateOrderField *)&RtnInvalidateOrder);
		}
		itor.Next();
	}
}

///报单状态查询应答
void CFtdcSysUserApiImpl::OnRspQryOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryOrderStatusField RspQryOrderStatus;
	CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryOrderStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryOrderStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryOrderStatus = (CShfeFtdcRspQryOrderStatusField *)&RspQryOrderStatus;
			m_pSpi->OnRspQryOrderStatusTopic(pRspQryOrderStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryOrderStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryOrderStatusTopic(pRspQryOrderStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单状态查询应答
void CFtdcSysUserApiImpl::OnRtnOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnOrderStatusField RtnOrderStatus;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnOrderStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnOrderStatus);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnOrderStatusTopic((CShfeFtdcRtnOrderStatusField *)&RtnOrderStatus);
		}
		itor.Next();
	}
}

///报单成交查询应答
void CFtdcSysUserApiImpl::OnRspQryBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryBargainOrderField RspQryBargainOrder;
	CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryBargainOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryBargainOrder);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryBargainOrder = (CShfeFtdcRspQryBargainOrderField *)&RspQryBargainOrder;
			m_pSpi->OnRspQryBargainOrderTopic(pRspQryBargainOrder, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryBargainOrder == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryBargainOrderTopic(pRspQryBargainOrder, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///报单成交查询应答
void CFtdcSysUserApiImpl::OnRtnBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnBargainOrderField RtnBargainOrder;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnBargainOrderField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnBargainOrder);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnBargainOrderTopic((CShfeFtdcRtnBargainOrderField *)&RtnBargainOrder);
		}
		itor.Next();
	}
}

///合约基本属性查询应答
void CFtdcSysUserApiImpl::OnRspQryInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryInstPropertyField RspQryInstProperty;
	CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryInstPropertyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryInstProperty);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryInstProperty = (CShfeFtdcRspQryInstPropertyField *)&RspQryInstProperty;
			m_pSpi->OnRspQryInstPropertyTopic(pRspQryInstProperty, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryInstProperty == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstPropertyTopic(pRspQryInstProperty, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约基本属性查询应答
void CFtdcSysUserApiImpl::OnRtnInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnInstPropertyField RtnInstProperty;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnInstPropertyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnInstProperty);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInstPropertyTopic((CShfeFtdcRtnInstPropertyField *)&RtnInstProperty);
		}
		itor.Next();
	}
}

///合约保证金率查询应答
void CFtdcSysUserApiImpl::OnRspQryMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMarginRateField RspQryMarginRate;
	CShfeFtdcRspQryMarginRateField *pRspQryMarginRate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMarginRateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMarginRate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMarginRate = (CShfeFtdcRspQryMarginRateField *)&RspQryMarginRate;
			m_pSpi->OnRspQryMarginRateTopic(pRspQryMarginRate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryMarginRate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMarginRateTopic(pRspQryMarginRate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约保证金率查询应答
void CFtdcSysUserApiImpl::OnRtnMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnMarginRateField RtnMarginRate;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMarginRateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMarginRate);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMarginRateTopic((CShfeFtdcRtnMarginRateField *)&RtnMarginRate);
		}
		itor.Next();
	}
}

///合约涨跌停板查询应答
void CFtdcSysUserApiImpl::OnRspQryPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPriceLimitField RspQryPriceLimit;
	CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPriceLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPriceLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPriceLimit = (CShfeFtdcRspQryPriceLimitField *)&RspQryPriceLimit;
			m_pSpi->OnRspQryPriceLimitTopic(pRspQryPriceLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryPriceLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPriceLimitTopic(pRspQryPriceLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///合约涨跌停板查询应答
void CFtdcSysUserApiImpl::OnRtnPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnPriceLimitField RtnPriceLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPriceLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPriceLimit);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPriceLimitTopic((CShfeFtdcRtnPriceLimitField *)&RtnPriceLimit);
		}
		itor.Next();
	}
}

///会员限仓查询应答
void CFtdcSysUserApiImpl::OnRspQryPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPartPosiLimitField RspQryPartPosiLimit;
	CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPartPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPartPosiLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPartPosiLimit = (CShfeFtdcRspQryPartPosiLimitField *)&RspQryPartPosiLimit;
			m_pSpi->OnRspQryPartPosiLimitTopic(pRspQryPartPosiLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryPartPosiLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartPosiLimitTopic(pRspQryPartPosiLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员限仓查询应答
void CFtdcSysUserApiImpl::OnRtnPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnPartPosiLimitField RtnPartPosiLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPartPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPartPosiLimit);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPartPosiLimitTopic((CShfeFtdcRtnPartPosiLimitField *)&RtnPartPosiLimit);
		}
		itor.Next();
	}
}

///客户限仓查询应答
void CFtdcSysUserApiImpl::OnRspQryClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientPosiLimitField RspQryClientPosiLimit;
	CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientPosiLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientPosiLimit = (CShfeFtdcRspQryClientPosiLimitField *)&RspQryClientPosiLimit;
			m_pSpi->OnRspQryClientPosiLimitTopic(pRspQryClientPosiLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryClientPosiLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientPosiLimitTopic(pRspQryClientPosiLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户限仓查询应答
void CFtdcSysUserApiImpl::OnRtnClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnClientPosiLimitField RtnClientPosiLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientPosiLimit);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientPosiLimitTopic((CShfeFtdcRtnClientPosiLimitField *)&RtnClientPosiLimit);
		}
		itor.Next();
	}
}

///特殊客户限仓查询应答
void CFtdcSysUserApiImpl::OnRspQrySpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySpecialPosiLimitField RspQrySpecialPosiLimit;
	CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySpecialPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySpecialPosiLimit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySpecialPosiLimit = (CShfeFtdcRspQrySpecialPosiLimitField *)&RspQrySpecialPosiLimit;
			m_pSpi->OnRspQrySpecialPosiLimitTopic(pRspQrySpecialPosiLimit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySpecialPosiLimit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySpecialPosiLimitTopic(pRspQrySpecialPosiLimit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///特殊客户限仓查询应答
void CFtdcSysUserApiImpl::OnRtnSpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnSpecialPosiLimitField RtnSpecialPosiLimit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSpecialPosiLimitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSpecialPosiLimit);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSpecialPosiLimitTopic((CShfeFtdcRtnSpecialPosiLimitField *)&RtnSpecialPosiLimit);
		}
		itor.Next();
	}
}

///账户出入金查询应答
void CFtdcSysUserApiImpl::OnRspQryTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTransactionChgField RspQryTransactionChg;
	CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTransactionChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTransactionChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTransactionChg = (CShfeFtdcRspQryTransactionChgField *)&RspQryTransactionChg;
			m_pSpi->OnRspQryTransactionChgTopic(pRspQryTransactionChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTransactionChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTransactionChgTopic(pRspQryTransactionChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///账户出入金查询应答
void CFtdcSysUserApiImpl::OnRtnTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTransactionChgField RtnTransactionChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTransactionChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTransactionChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTransactionChgTopic((CShfeFtdcRtnTransactionChgField *)&RtnTransactionChg);
		}
		itor.Next();
	}
}

///客户数据变动查询应答
void CFtdcSysUserApiImpl::OnRspQryClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientChgField RspQryClientChg;
	CShfeFtdcRspQryClientChgField *pRspQryClientChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientChg = (CShfeFtdcRspQryClientChgField *)&RspQryClientChg;
			m_pSpi->OnRspQryClientChgTopic(pRspQryClientChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryClientChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientChgTopic(pRspQryClientChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户数据变动查询应答
void CFtdcSysUserApiImpl::OnRtnClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnClientChgField RtnClientChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientChgTopic((CShfeFtdcRtnClientChgField *)&RtnClientChg);
		}
		itor.Next();
	}
}

///会员客户对照变动查询应答
void CFtdcSysUserApiImpl::OnRspQryPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPartClientChgField RspQryPartClientChg;
	CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPartClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPartClientChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPartClientChg = (CShfeFtdcRspQryPartClientChgField *)&RspQryPartClientChg;
			m_pSpi->OnRspQryPartClientChgTopic(pRspQryPartClientChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryPartClientChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartClientChgTopic(pRspQryPartClientChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员客户对照变动查询应答
void CFtdcSysUserApiImpl::OnRtnPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnPartClientChgField RtnPartClientChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPartClientChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPartClientChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPartClientChgTopic((CShfeFtdcRtnPartClientChgField *)&RtnPartClientChg);
		}
		itor.Next();
	}
}

///限仓数据变动查询应答
void CFtdcSysUserApiImpl::OnRspQryPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPosiLimitChgField RspQryPosiLimitChg;
	CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPosiLimitChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPosiLimitChg = (CShfeFtdcRspQryPosiLimitChgField *)&RspQryPosiLimitChg;
			m_pSpi->OnRspQryPosiLimitChgTopic(pRspQryPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryPosiLimitChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPosiLimitChgTopic(pRspQryPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///限仓数据变动查询应答
void CFtdcSysUserApiImpl::OnRtnPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnPosiLimitChgField RtnPosiLimitChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPosiLimitChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPosiLimitChgTopic((CShfeFtdcRtnPosiLimitChgField *)&RtnPosiLimitChg);
		}
		itor.Next();
	}
}

///保值额度变动查询应答
void CFtdcSysUserApiImpl::OnRspQryHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHedgeDetailChgField RspQryHedgeDetailChg;
	CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHedgeDetailChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHedgeDetailChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHedgeDetailChg = (CShfeFtdcRspQryHedgeDetailChgField *)&RspQryHedgeDetailChg;
			m_pSpi->OnRspQryHedgeDetailChgTopic(pRspQryHedgeDetailChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryHedgeDetailChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHedgeDetailChgTopic(pRspQryHedgeDetailChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///保值额度变动查询应答
void CFtdcSysUserApiImpl::OnRtnHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnHedgeDetailChgField RtnHedgeDetailChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnHedgeDetailChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnHedgeDetailChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnHedgeDetailChgTopic((CShfeFtdcRtnHedgeDetailChgField *)&RtnHedgeDetailChg);
		}
		itor.Next();
	}
}

///会员变动查询应答
void CFtdcSysUserApiImpl::OnRspQryParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryParticipantChgField RspQryParticipantChg;
	CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryParticipantChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryParticipantChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryParticipantChg = (CShfeFtdcRspQryParticipantChgField *)&RspQryParticipantChg;
			m_pSpi->OnRspQryParticipantChgTopic(pRspQryParticipantChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryParticipantChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticipantChgTopic(pRspQryParticipantChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员变动查询应答
void CFtdcSysUserApiImpl::OnRtnParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnParticipantChgField RtnParticipantChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnParticipantChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnParticipantChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnParticipantChgTopic((CShfeFtdcRtnParticipantChgField *)&RtnParticipantChg);
		}
		itor.Next();
	}
}

///保证金率变动查询应答
void CFtdcSysUserApiImpl::OnRspQryMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMarginRateChgField RspQryMarginRateChg;
	CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMarginRateChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMarginRateChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMarginRateChg = (CShfeFtdcRspQryMarginRateChgField *)&RspQryMarginRateChg;
			m_pSpi->OnRspQryMarginRateChgTopic(pRspQryMarginRateChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryMarginRateChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMarginRateChgTopic(pRspQryMarginRateChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///保证金率变动查询应答
void CFtdcSysUserApiImpl::OnRtnMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnMarginRateChgField RtnMarginRateChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMarginRateChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMarginRateChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMarginRateChgTopic((CShfeFtdcRtnMarginRateChgField *)&RtnMarginRateChg);
		}
		itor.Next();
	}
}

///IP地址变动查询应答
void CFtdcSysUserApiImpl::OnRspQryUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryUserIpChgField RspQryUserIpChg;
	CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryUserIpChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryUserIpChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryUserIpChg = (CShfeFtdcRspQryUserIpChgField *)&RspQryUserIpChg;
			m_pSpi->OnRspQryUserIpChgTopic(pRspQryUserIpChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryUserIpChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserIpChgTopic(pRspQryUserIpChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///IP地址变动查询应答
void CFtdcSysUserApiImpl::OnRtnUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnUserIpChgField RtnUserIpChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUserIpChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUserIpChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUserIpChgTopic((CShfeFtdcRtnUserIpChgField *)&RtnUserIpChg);
		}
		itor.Next();
	}
}

///限仓数据变动查询应答
void CFtdcSysUserApiImpl::OnRspQryClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientPosiLimitChgField RspQryClientPosiLimitChg;
	CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientPosiLimitChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientPosiLimitChg = (CShfeFtdcRspQryClientPosiLimitChgField *)&RspQryClientPosiLimitChg;
			m_pSpi->OnRspQryClientPosiLimitChgTopic(pRspQryClientPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryClientPosiLimitChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientPosiLimitChgTopic(pRspQryClientPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///限仓数据变动查询应答
void CFtdcSysUserApiImpl::OnRtnClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnClientPosiLimitChgField RtnClientPosiLimitChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientPosiLimitChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientPosiLimitChgTopic((CShfeFtdcRtnClientPosiLimitChgField *)&RtnClientPosiLimitChg);
		}
		itor.Next();
	}
}

///限仓数据变动查询应答
void CFtdcSysUserApiImpl::OnRspQrySpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySpecPosiLimitChgField RspQrySpecPosiLimitChg;
	CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySpecPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySpecPosiLimitChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySpecPosiLimitChg = (CShfeFtdcRspQrySpecPosiLimitChgField *)&RspQrySpecPosiLimitChg;
			m_pSpi->OnRspQrySpecPosiLimitChgTopic(pRspQrySpecPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySpecPosiLimitChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySpecPosiLimitChgTopic(pRspQrySpecPosiLimitChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///限仓数据变动查询应答
void CFtdcSysUserApiImpl::OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnSpecPosiLimitChgField RtnSpecPosiLimitChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSpecPosiLimitChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSpecPosiLimitChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSpecPosiLimitChgTopic((CShfeFtdcRtnSpecPosiLimitChgField *)&RtnSpecPosiLimitChg);
		}
		itor.Next();
	}
}

///历史对象状态指标查询应答
void CFtdcSysUserApiImpl::OnRspQryHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryObjectAttrField RspQryHistoryObjectAttr;
	CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryObjectAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryObjectAttr = (CShfeFtdcRspQryHistoryObjectAttrField *)&RspQryHistoryObjectAttr;
			m_pSpi->OnRspQryHistoryObjectAttrTopic(pRspQryHistoryObjectAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryHistoryObjectAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryObjectAttrTopic(pRspQryHistoryObjectAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///历史对象状态指标查询应答
void CFtdcSysUserApiImpl::OnRtnHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnHistoryObjectAttrField RtnHistoryObjectAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnHistoryObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnHistoryObjectAttr);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnHistoryObjectAttrTopic((CShfeFtdcRtnHistoryObjectAttrField *)&RtnHistoryObjectAttr);
		}
		itor.Next();
	}
}

///前置响应信息查询应答
void CFtdcSysUserApiImpl::OnRspQryFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFrontInfoField RspQryFrontInfo;
	CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFrontInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFrontInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFrontInfo = (CShfeFtdcRspQryFrontInfoField *)&RspQryFrontInfo;
			m_pSpi->OnRspQryFrontInfoTopic(pRspQryFrontInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryFrontInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFrontInfoTopic(pRspQryFrontInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///前置响应信息查询应答
void CFtdcSysUserApiImpl::OnRtnFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnFrontInfoField RtnFrontInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFrontInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFrontInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFrontInfoTopic((CShfeFtdcRtnFrontInfoField *)&RtnFrontInfo);
		}
		itor.Next();
	}
}

///用户登录应答
void CFtdcSysUserApiImpl::OnRspQrySysUserLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserLoginField RspQrySysUserLogin;
	CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserLoginField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserLogin);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserLogin = (CShfeFtdcRspQrySysUserLoginField *)&RspQrySysUserLogin;
			m_pSpi->OnRspQrySysUserLoginTopic(pRspQrySysUserLogin, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySysUserLogin == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserLoginTopic(pRspQrySysUserLogin, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户登出应答
void CFtdcSysUserApiImpl::OnRspQrySysUserLogoutTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserLogoutField RspQrySysUserLogout;
	CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserLogoutField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserLogout);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserLogout = (CShfeFtdcRspQrySysUserLogoutField *)&RspQrySysUserLogout;
			m_pSpi->OnRspQrySysUserLogoutTopic(pRspQrySysUserLogout, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySysUserLogout == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserLogoutTopic(pRspQrySysUserLogout, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///用户修改密码应答
void CFtdcSysUserApiImpl::OnRspQrySysUserPasswordUpdateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserPasswordUpdateField RspQrySysUserPasswordUpdate;
	CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserPasswordUpdateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserPasswordUpdate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserPasswordUpdate = (CShfeFtdcRspQrySysUserPasswordUpdateField *)&RspQrySysUserPasswordUpdate;
			m_pSpi->OnRspQrySysUserPasswordUpdateTopic(pRspQrySysUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySysUserPasswordUpdate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserPasswordUpdateTopic(pRspQrySysUserPasswordUpdate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///注册用户应答
void CFtdcSysUserApiImpl::OnRspQrySysUserRegisterTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserRegisterField RspQrySysUserRegister;
	CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserRegisterField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserRegister);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserRegister = (CShfeFtdcRspQrySysUserRegisterField *)&RspQrySysUserRegister;
			m_pSpi->OnRspQrySysUserRegisterTopic(pRspQrySysUserRegister, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySysUserRegister == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserRegisterTopic(pRspQrySysUserRegister, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///删除用户应答
void CFtdcSysUserApiImpl::OnRspQrySysUserDeleteTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySysUserDeleteField RspQrySysUserDelete;
	CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySysUserDeleteField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySysUserDelete);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySysUserDelete = (CShfeFtdcRspQrySysUserDeleteField *)&RspQrySysUserDelete;
			m_pSpi->OnRspQrySysUserDeleteTopic(pRspQrySysUserDelete, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySysUserDelete == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySysUserDeleteTopic(pRspQrySysUserDelete, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员初始化应答
void CFtdcSysUserApiImpl::OnRspQryParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryParticipantInitField RspQryParticipantInit;
	CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryParticipantInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryParticipantInit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryParticipantInit = (CShfeFtdcRspQryParticipantInitField *)&RspQryParticipantInit;
			m_pSpi->OnRspQryParticipantInitTopic(pRspQryParticipantInit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryParticipantInit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticipantInitTopic(pRspQryParticipantInit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员初始化应答
void CFtdcSysUserApiImpl::OnRtnParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnParticipantInitField RtnParticipantInit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnParticipantInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnParticipantInit);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnParticipantInitTopic((CShfeFtdcRtnParticipantInitField *)&RtnParticipantInit);
		}
		itor.Next();
	}
}

///座席初始化应答
void CFtdcSysUserApiImpl::OnRspQryUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryUserInitField RspQryUserInit;
	CShfeFtdcRspQryUserInitField *pRspQryUserInit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryUserInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryUserInit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryUserInit = (CShfeFtdcRspQryUserInitField *)&RspQryUserInit;
			m_pSpi->OnRspQryUserInitTopic(pRspQryUserInit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryUserInit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryUserInitTopic(pRspQryUserInit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///座席初始化应答
void CFtdcSysUserApiImpl::OnRtnUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnUserInitField RtnUserInit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUserInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUserInit);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUserInitTopic((CShfeFtdcRtnUserInitField *)&RtnUserInit);
		}
		itor.Next();
	}
}

///客户初始化应答
void CFtdcSysUserApiImpl::OnRspQryClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientInitField RspQryClientInit;
	CShfeFtdcRspQryClientInitField *pRspQryClientInit = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientInit);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientInit = (CShfeFtdcRspQryClientInitField *)&RspQryClientInit;
			m_pSpi->OnRspQryClientInitTopic(pRspQryClientInit, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryClientInit == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientInitTopic(pRspQryClientInit, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///客户初始化应答
void CFtdcSysUserApiImpl::OnRtnClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnClientInitField RtnClientInit;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientInitField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientInit);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientInitTopic((CShfeFtdcRtnClientInitField *)&RtnClientInit);
		}
		itor.Next();
	}
}

///交易日志查询应答
void CFtdcSysUserApiImpl::OnRspQryTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeLogField RspQryTradeLog;
	CShfeFtdcRspQryTradeLogField *pRspQryTradeLog = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeLogField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeLog);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeLog = (CShfeFtdcRspQryTradeLogField *)&RspQryTradeLog;
			m_pSpi->OnRspQryTradeLogTopic(pRspQryTradeLog, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTradeLog == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeLogTopic(pRspQryTradeLog, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易日志查询应答
void CFtdcSysUserApiImpl::OnRtnTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTradeLogField RtnTradeLog;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeLogField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeLog);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeLogTopic((CShfeFtdcRtnTradeLogField *)&RtnTradeLog);
		}
		itor.Next();
	}
}

///交易系统登录信息
void CFtdcSysUserApiImpl::OnRspQryTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeUserLoginInfoField RspQryTradeUserLoginInfo;
	CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeUserLoginInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeUserLoginInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeUserLoginInfo = (CShfeFtdcRspQryTradeUserLoginInfoField *)&RspQryTradeUserLoginInfo;
			m_pSpi->OnRspQryTradeUserLoginInfoTopic(pRspQryTradeUserLoginInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTradeUserLoginInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeUserLoginInfoTopic(pRspQryTradeUserLoginInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统登录信息
void CFtdcSysUserApiImpl::OnRtnTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTradeUserLoginInfoField RtnTradeUserLoginInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeUserLoginInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeUserLoginInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeUserLoginInfoTopic((CShfeFtdcRtnTradeUserLoginInfoField *)&RtnTradeUserLoginInfo);
		}
		itor.Next();
	}
}

///会员交易查询应答
void CFtdcSysUserApiImpl::OnRspQryPartTradeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPartTradeField RspQryPartTrade;
	CShfeFtdcRspQryPartTradeField *pRspQryPartTrade = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPartTradeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPartTrade);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPartTrade = (CShfeFtdcRspQryPartTradeField *)&RspQryPartTrade;
			m_pSpi->OnRspQryPartTradeTopic(pRspQryPartTrade, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryPartTrade == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPartTradeTopic(pRspQryPartTrade, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易峰值查询应答
void CFtdcSysUserApiImpl::OnRspQryTradepeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradepeakField RspQryTradepeak;
	CShfeFtdcRspQryTradepeakField *pRspQryTradepeak = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradepeakField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradepeak);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradepeak = (CShfeFtdcRspQryTradepeakField *)&RspQryTradepeak;
			m_pSpi->OnRspQryTradepeakTopic(pRspQryTradepeak, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTradepeak == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradepeakTopic(pRspQryTradepeak, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///
void CFtdcSysUserApiImpl::OnRtnUpdateSysConfigTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnUpdateSysConfigField RtnUpdateSysConfig;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnUpdateSysConfigField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnUpdateSysConfig);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnUpdateSysConfigTopic((CShfeFtdcRtnUpdateSysConfigField *)&RtnUpdateSysConfig);
		}
		itor.Next();
	}
}

///
void CFtdcSysUserApiImpl::OnRtnSysUser(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnSysUserField RtnSysUser;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSysUserField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSysUser);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSysUser((CShfeFtdcRtnSysUserField *)&RtnSysUser);
		}
		itor.Next();
	}
}

///
void CFtdcSysUserApiImpl::OnRspQryHistoryCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryCpuInfoField RspQryHistoryCpuInfo;
	CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryCpuInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryCpuInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryCpuInfo = (CShfeFtdcRspQryHistoryCpuInfoField *)&RspQryHistoryCpuInfo;
			m_pSpi->OnRspQryHistoryCpuInfoTopic(pRspQryHistoryCpuInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryHistoryCpuInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryCpuInfoTopic(pRspQryHistoryCpuInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///
void CFtdcSysUserApiImpl::OnRspQryHistoryMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryMemInfoField RspQryHistoryMemInfo;
	CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryMemInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryMemInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryMemInfo = (CShfeFtdcRspQryHistoryMemInfoField *)&RspQryHistoryMemInfo;
			m_pSpi->OnRspQryHistoryMemInfoTopic(pRspQryHistoryMemInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryHistoryMemInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryMemInfoTopic(pRspQryHistoryMemInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///
void CFtdcSysUserApiImpl::OnRspQryHistoryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryNetworkInfoField RspQryHistoryNetworkInfo;
	CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryNetworkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryNetworkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryNetworkInfo = (CShfeFtdcRspQryHistoryNetworkInfoField *)&RspQryHistoryNetworkInfo;
			m_pSpi->OnRspQryHistoryNetworkInfoTopic(pRspQryHistoryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryHistoryNetworkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryNetworkInfoTopic(pRspQryHistoryNetworkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控系统在线用户应答
void CFtdcSysUserApiImpl::OnRspQryMonitorOnlineUser(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMonitorOnlineUserField RspQryMonitorOnlineUser;
	CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMonitorOnlineUserField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMonitorOnlineUser);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMonitorOnlineUser = (CShfeFtdcRspQryMonitorOnlineUserField *)&RspQryMonitorOnlineUser;
			m_pSpi->OnRspQryMonitorOnlineUser(pRspQryMonitorOnlineUser, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryMonitorOnlineUser == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMonitorOnlineUser(pRspQryMonitorOnlineUser, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统前置统计应答
void CFtdcSysUserApiImpl::OnRspQryFrontStat(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFrontStatField RspQryFrontStat;
	CShfeFtdcRspQryFrontStatField *pRspQryFrontStat = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFrontStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFrontStat);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFrontStat = (CShfeFtdcRspQryFrontStatField *)&RspQryFrontStat;
			m_pSpi->OnRspQryFrontStat(pRspQryFrontStat, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryFrontStat == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFrontStat(pRspQryFrontStat, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控系统时钟同步
void CFtdcSysUserApiImpl::OnRtnSysTimeSyncTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnSysTimeSyncField RtnSysTimeSync;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSysTimeSyncField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSysTimeSync);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSysTimeSyncTopic((CShfeFtdcRtnSysTimeSyncField *)&RtnSysTimeSync);
		}
		itor.Next();
	}
}

///数据中心切换通知
void CFtdcSysUserApiImpl::OnRtnDataCenterChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnDataCenterChgField RtnDataCenterChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnDataCenterChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnDataCenterChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDataCenterChgTopic((CShfeFtdcRtnDataCenterChgField *)&RtnDataCenterChg);
		}
		itor.Next();
	}
}

///历史峰值查询应答
void CFtdcSysUserApiImpl::OnRspQryHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryHistoryTradePeakField RspQryHistoryTradePeak;
	CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryHistoryTradePeakField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryHistoryTradePeak);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryHistoryTradePeak = (CShfeFtdcRspQryHistoryTradePeakField *)&RspQryHistoryTradePeak;
			m_pSpi->OnRspQryHistoryTradePeakTopic(pRspQryHistoryTradePeak, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryHistoryTradePeak == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryHistoryTradePeakTopic(pRspQryHistoryTradePeak, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///日志事件查询应答
void CFtdcSysUserApiImpl::OnRspQrySyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySyslogEventField RspQrySyslogEvent;
	CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySyslogEvent);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySyslogEvent = (CShfeFtdcRspQrySyslogEventField *)&RspQrySyslogEvent;
			m_pSpi->OnRspQrySyslogEventTopic(pRspQrySyslogEvent, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySyslogEvent == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySyslogEventTopic(pRspQrySyslogEvent, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///日志事件应答
void CFtdcSysUserApiImpl::OnRtnSyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnSyslogEventField RtnSyslogEvent;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSyslogEventField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSyslogEvent);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSyslogEventTopic((CShfeFtdcRtnSyslogEventField *)&RtnSyslogEvent);
		}
		itor.Next();
	}
}

///Web应用信息
void CFtdcSysUserApiImpl::OnRspQryWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryWebAppInfoField RspQryWebAppInfo;
	CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryWebAppInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryWebAppInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryWebAppInfo = (CShfeFtdcRspQryWebAppInfoField *)&RspQryWebAppInfo;
			m_pSpi->OnRspQryWebAppInfoTopic(pRspQryWebAppInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryWebAppInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryWebAppInfoTopic(pRspQryWebAppInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///Web应用信息
void CFtdcSysUserApiImpl::OnRtnWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnWebAppInfoField RtnWebAppInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnWebAppInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnWebAppInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnWebAppInfoTopic((CShfeFtdcRtnWebAppInfoField *)&RtnWebAppInfo);
		}
		itor.Next();
	}
}

///应用servlet信息
void CFtdcSysUserApiImpl::OnRspQryServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryServletInfoField RspQryServletInfo;
	CShfeFtdcRspQryServletInfoField *pRspQryServletInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryServletInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryServletInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryServletInfo = (CShfeFtdcRspQryServletInfoField *)&RspQryServletInfo;
			m_pSpi->OnRspQryServletInfoTopic(pRspQryServletInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryServletInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryServletInfoTopic(pRspQryServletInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///应用servlet信息
void CFtdcSysUserApiImpl::OnRtnServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnServletInfoField RtnServletInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnServletInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnServletInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnServletInfoTopic((CShfeFtdcRtnServletInfoField *)&RtnServletInfo);
		}
		itor.Next();
	}
}

///文件信息
void CFtdcSysUserApiImpl::OnRspQryFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileInfoField RspQryFileInfo;
	CShfeFtdcRspQryFileInfoField *pRspQryFileInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileInfo = (CShfeFtdcRspQryFileInfoField *)&RspQryFileInfo;
			m_pSpi->OnRspQryFileInfoTopic(pRspQryFileInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryFileInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileInfoTopic(pRspQryFileInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件信息
void CFtdcSysUserApiImpl::OnRtnFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnFileInfoField RtnFileInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileInfoTopic((CShfeFtdcRtnFileInfoField *)&RtnFileInfo);
		}
		itor.Next();
	}
}

///应用会话信息
void CFtdcSysUserApiImpl::OnRspQrySessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQrySessionInfoField RspQrySessionInfo;
	CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQrySessionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQrySessionInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQrySessionInfo = (CShfeFtdcRspQrySessionInfoField *)&RspQrySessionInfo;
			m_pSpi->OnRspQrySessionInfoTopic(pRspQrySessionInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQrySessionInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQrySessionInfoTopic(pRspQrySessionInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///应用会话信息
void CFtdcSysUserApiImpl::OnRtnSessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnSessionInfoField RtnSessionInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnSessionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnSessionInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnSessionInfoTopic((CShfeFtdcRtnSessionInfoField *)&RtnSessionInfo);
		}
		itor.Next();
	}
}

///JDBC信息
void CFtdcSysUserApiImpl::OnRspQryJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryJDBCInfoField RspQryJDBCInfo;
	CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryJDBCInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryJDBCInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryJDBCInfo = (CShfeFtdcRspQryJDBCInfoField *)&RspQryJDBCInfo;
			m_pSpi->OnRspQryJDBCInfoTopic(pRspQryJDBCInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryJDBCInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryJDBCInfoTopic(pRspQryJDBCInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///JDBC信息
void CFtdcSysUserApiImpl::OnRtnJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnJDBCInfoField RtnJDBCInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnJDBCInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnJDBCInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnJDBCInfoTopic((CShfeFtdcRtnJDBCInfoField *)&RtnJDBCInfo);
		}
		itor.Next();
	}
}

///线程信息
void CFtdcSysUserApiImpl::OnRspQryThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryThreadInfoField RspQryThreadInfo;
	CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryThreadInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryThreadInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryThreadInfo = (CShfeFtdcRspQryThreadInfoField *)&RspQryThreadInfo;
			m_pSpi->OnRspQryThreadInfoTopic(pRspQryThreadInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryThreadInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryThreadInfoTopic(pRspQryThreadInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///线程信息
void CFtdcSysUserApiImpl::OnRtnThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnThreadInfoField RtnThreadInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnThreadInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnThreadInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnThreadInfoTopic((CShfeFtdcRtnThreadInfoField *)&RtnThreadInfo);
		}
		itor.Next();
	}
}

///虚拟机信息
void CFtdcSysUserApiImpl::OnRspQryVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryVMInfoField RspQryVMInfo;
	CShfeFtdcRspQryVMInfoField *pRspQryVMInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryVMInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryVMInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryVMInfo = (CShfeFtdcRspQryVMInfoField *)&RspQryVMInfo;
			m_pSpi->OnRspQryVMInfoTopic(pRspQryVMInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryVMInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryVMInfoTopic(pRspQryVMInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///虚拟机信息
void CFtdcSysUserApiImpl::OnRtnVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnVMInfoField RtnVMInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnVMInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnVMInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnVMInfoTopic((CShfeFtdcRtnVMInfoField *)&RtnVMInfo);
		}
		itor.Next();
	}
}

///系统属性信息
void CFtdcSysUserApiImpl::OnRspQryPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPropertyInfoField RspQryPropertyInfo;
	CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPropertyInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPropertyInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPropertyInfo = (CShfeFtdcRspQryPropertyInfoField *)&RspQryPropertyInfo;
			m_pSpi->OnRspQryPropertyInfoTopic(pRspQryPropertyInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryPropertyInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPropertyInfoTopic(pRspQryPropertyInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统属性信息
void CFtdcSysUserApiImpl::OnRtnPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnPropertyInfoField RtnPropertyInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPropertyInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPropertyInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPropertyInfoTopic((CShfeFtdcRtnPropertyInfoField *)&RtnPropertyInfo);
		}
		itor.Next();
	}
}

///系统内存池信息
void CFtdcSysUserApiImpl::OnRspQryMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMemPoolInfoField RspQryMemPoolInfo;
	CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMemPoolInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMemPoolInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMemPoolInfo = (CShfeFtdcRspQryMemPoolInfoField *)&RspQryMemPoolInfo;
			m_pSpi->OnRspQryMemPoolInfoTopic(pRspQryMemPoolInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryMemPoolInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMemPoolInfoTopic(pRspQryMemPoolInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统内存池信息
void CFtdcSysUserApiImpl::OnRtnMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnMemPoolInfoField RtnMemPoolInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMemPoolInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMemPoolInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMemPoolInfoTopic((CShfeFtdcRtnMemPoolInfoField *)&RtnMemPoolInfo);
		}
		itor.Next();
	}
}

///文件内容信息
void CFtdcSysUserApiImpl::OnRspQryFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileContentInfoField RspQryFileContentInfo;
	CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileContentInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileContentInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileContentInfo = (CShfeFtdcRspQryFileContentInfoField *)&RspQryFileContentInfo;
			m_pSpi->OnRspQryFileContentInfoTopic(pRspQryFileContentInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryFileContentInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileContentInfoTopic(pRspQryFileContentInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件内容信息
void CFtdcSysUserApiImpl::OnRtnFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnFileContentInfoField RtnFileContentInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileContentInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileContentInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileContentInfoTopic((CShfeFtdcRtnFileContentInfoField *)&RtnFileContentInfo);
		}
		itor.Next();
	}
}

///连接信息
void CFtdcSysUserApiImpl::OnRspQryConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryConnectionInfoField RspQryConnectionInfo;
	CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryConnectionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryConnectionInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryConnectionInfo = (CShfeFtdcRspQryConnectionInfoField *)&RspQryConnectionInfo;
			m_pSpi->OnRspQryConnectionInfoTopic(pRspQryConnectionInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryConnectionInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryConnectionInfoTopic(pRspQryConnectionInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///连接信息
void CFtdcSysUserApiImpl::OnRtnConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnConnectionInfoField RtnConnectionInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnConnectionInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnConnectionInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnConnectionInfoTopic((CShfeFtdcRtnConnectionInfoField *)&RtnConnectionInfo);
		}
		itor.Next();
	}
}

///连接器信息
void CFtdcSysUserApiImpl::OnRspQryConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryConnectorInfoField RspQryConnectorInfo;
	CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryConnectorInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryConnectorInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryConnectorInfo = (CShfeFtdcRspQryConnectorInfoField *)&RspQryConnectorInfo;
			m_pSpi->OnRspQryConnectorInfoTopic(pRspQryConnectorInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryConnectorInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryConnectorInfoTopic(pRspQryConnectorInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///连接器信息
void CFtdcSysUserApiImpl::OnRtnConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnConnectorInfoField RtnConnectorInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnConnectorInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnConnectorInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnConnectorInfoTopic((CShfeFtdcRtnConnectorInfoField *)&RtnConnectorInfo);
		}
		itor.Next();
	}
}

///数据库查询应答
void CFtdcSysUserApiImpl::OnRspQryDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryDBQueryField RspQryDBQuery;
	CShfeFtdcRspQryDBQueryField *pRspQryDBQuery = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryDBQuery);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryDBQuery = (CShfeFtdcRspQryDBQueryField *)&RspQryDBQuery;
			m_pSpi->OnRspQryDBQueryTopic(pRspQryDBQuery, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryDBQuery == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryDBQueryTopic(pRspQryDBQuery, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///数据库查询应答
void CFtdcSysUserApiImpl::OnRtnDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnDBQueryField RtnDBQuery;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnDBQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnDBQuery);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDBQueryTopic((CShfeFtdcRtnDBQueryField *)&RtnDBQuery);
		}
		itor.Next();
	}
}

///通用返回应答
void CFtdcSysUserApiImpl::OnRspQryGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDSysGeneralFieldField SysGeneralField;
	CShfeFtdcSysGeneralFieldField *pSysGeneralField = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSysGeneralFieldField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SysGeneralField);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pSysGeneralField = (CShfeFtdcSysGeneralFieldField *)&SysGeneralField;
			m_pSpi->OnRspQryGeneralFieldTopic(pSysGeneralField, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pSysGeneralField == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryGeneralFieldTopic(pSysGeneralField, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///通用返回应答
void CFtdcSysUserApiImpl::OnRtnGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDSysGeneralFieldField SysGeneralField;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDSysGeneralFieldField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&SysGeneralField);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnGeneralFieldTopic((CShfeFtdcSysGeneralFieldField *)&SysGeneralField);
		}
		itor.Next();
	}
}

///文件传输应答
void CFtdcSysUserApiImpl::OnRspQryGetFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryGetFileField RspQryGetFile;
	CShfeFtdcRspQryGetFileField *pRspQryGetFile = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryGetFileField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryGetFile);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryGetFile = (CShfeFtdcRspQryGetFileField *)&RspQryGetFile;
			m_pSpi->OnRspQryGetFileTopic(pRspQryGetFile, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryGetFile == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryGetFileTopic(pRspQryGetFile, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警明细
void CFtdcSysUserApiImpl::OnRspQryWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryWarningQueryField RspQryWarningQuery;
	CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryWarningQueryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryWarningQuery);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryWarningQuery = (CShfeFtdcRspQryWarningQueryField *)&RspQryWarningQuery;
			m_pSpi->OnRspQryWarningQueryTopic(pRspQryWarningQuery, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryWarningQuery == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryWarningQueryTopic(pRspQryWarningQuery, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///告警激活变更
void CFtdcSysUserApiImpl::OnRtnWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnWarningActiveChangeField RtnWarningActiveChange;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnWarningActiveChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnWarningActiveChange);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnWarningActiveChange((CShfeFtdcRtnWarningActiveChangeField *)&RtnWarningActiveChange);
		}
		itor.Next();
	}
}

///通用操作
void CFtdcSysUserApiImpl::OnRspQryGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryGeneralOperateField RspQryGeneralOperate;
	CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryGeneralOperateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryGeneralOperate);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryGeneralOperate = (CShfeFtdcRspQryGeneralOperateField *)&RspQryGeneralOperate;
			m_pSpi->OnRspQryGeneralOperateTopic(pRspQryGeneralOperate, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryGeneralOperate == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryGeneralOperateTopic(pRspQryGeneralOperate, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///通用操作
void CFtdcSysUserApiImpl::OnRtnGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnGeneralOperateField RtnGeneralOperate;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnGeneralOperateField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnGeneralOperate);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnGeneralOperateTopic((CShfeFtdcRtnGeneralOperateField *)&RtnGeneralOperate);
		}
		itor.Next();
	}
}

///网络设备连接关系
void CFtdcSysUserApiImpl::OnRspQryNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceLinkedField RspQryNetDeviceLinked;
	CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceLinkedField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceLinked);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceLinked = (CShfeFtdcRspQryNetDeviceLinkedField *)&RspQryNetDeviceLinked;
			m_pSpi->OnRspQryNetDeviceLinkedTopic(pRspQryNetDeviceLinked, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetDeviceLinked == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceLinkedTopic(pRspQryNetDeviceLinked, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络设备连接关系
void CFtdcSysUserApiImpl::OnRtnNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetDeviceLinkedField RtnNetDeviceLinked;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceLinkedField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceLinked);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceLinkedTopic((CShfeFtdcRtnNetDeviceLinkedField *)&RtnNetDeviceLinked);
		}
		itor.Next();
	}
}

///交易系统登录信息
void CFtdcSysUserApiImpl::OnRspQryTradeUserLoginStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeUserLoginStatField RspQryTradeUserLoginStat;
	CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeUserLoginStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeUserLoginStat);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeUserLoginStat = (CShfeFtdcRspQryTradeUserLoginStatField *)&RspQryTradeUserLoginStat;
			m_pSpi->OnRspQryTradeUserLoginStatTopic(pRspQryTradeUserLoginStat, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTradeUserLoginStat == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeUserLoginStatTopic(pRspQryTradeUserLoginStat, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统前置报单响应信息
void CFtdcSysUserApiImpl::OnRspQryTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeFrontOrderRttStatField RspQryTradeFrontOrderRttStat;
	CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeFrontOrderRttStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeFrontOrderRttStat);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeFrontOrderRttStat = (CShfeFtdcRspQryTradeFrontOrderRttStatField *)&RspQryTradeFrontOrderRttStat;
			m_pSpi->OnRspQryTradeFrontOrderRttStatTopic(pRspQryTradeFrontOrderRttStat, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTradeFrontOrderRttStat == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeFrontOrderRttStatTopic(pRspQryTradeFrontOrderRttStat, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统前置报单响应信息
void CFtdcSysUserApiImpl::OnRtnTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTradeFrontOrderRttStatField RtnTradeFrontOrderRttStat;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeFrontOrderRttStatField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeFrontOrderRttStat);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeFrontOrderRttStatTopic((CShfeFtdcRtnTradeFrontOrderRttStatField *)&RtnTradeFrontOrderRttStat);
		}
		itor.Next();
	}
}

///会员席位交易状态
void CFtdcSysUserApiImpl::OnRspQryParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryParticTradeOrderStatesField RspQryParticTradeOrderStates;
	CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryParticTradeOrderStatesField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryParticTradeOrderStates);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryParticTradeOrderStates = (CShfeFtdcRspQryParticTradeOrderStatesField *)&RspQryParticTradeOrderStates;
			m_pSpi->OnRspQryParticTradeOrderStatesTopic(pRspQryParticTradeOrderStates, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryParticTradeOrderStates == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryParticTradeOrderStatesTopic(pRspQryParticTradeOrderStates, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员席位交易状态
void CFtdcSysUserApiImpl::OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnParticTradeOrderStatesField RtnParticTradeOrderStates;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnParticTradeOrderStatesField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnParticTradeOrderStates);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnParticTradeOrderStatesTopic((CShfeFtdcRtnParticTradeOrderStatesField *)&RtnParticTradeOrderStates);
		}
		itor.Next();
	}
}

///系统路由信息
void CFtdcSysUserApiImpl::OnRspQryRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryRouterInfoField RspQryRouterInfo;
	CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryRouterInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryRouterInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryRouterInfo = (CShfeFtdcRspQryRouterInfoField *)&RspQryRouterInfo;
			m_pSpi->OnRspQryRouterInfoTopic(pRspQryRouterInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryRouterInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryRouterInfoTopic(pRspQryRouterInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统路由信息
void CFtdcSysUserApiImpl::OnRtnRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnRouterInfoField RtnRouterInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnRouterInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnRouterInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnRouterInfoTopic((CShfeFtdcRtnRouterInfoField *)&RtnRouterInfo);
		}
		itor.Next();
	}
}

///磁盘I/O信息
void CFtdcSysUserApiImpl::OnRspQryDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryDiskIOField RspQryDiskIO;
	CShfeFtdcRspQryDiskIOField *pRspQryDiskIO = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryDiskIOField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryDiskIO);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryDiskIO = (CShfeFtdcRspQryDiskIOField *)&RspQryDiskIO;
			m_pSpi->OnRspQryDiskIOTopic(pRspQryDiskIO, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryDiskIO == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryDiskIOTopic(pRspQryDiskIO, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///磁盘I/O信息
void CFtdcSysUserApiImpl::OnRtnDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnDiskIOField RtnDiskIO;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnDiskIOField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnDiskIO);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnDiskIOTopic((CShfeFtdcRtnDiskIOField *)&RtnDiskIO);
		}
		itor.Next();
	}
}

///系统状态信息
void CFtdcSysUserApiImpl::OnRspQryStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryStatInfoField RspQryStatInfo;
	CShfeFtdcRspQryStatInfoField *pRspQryStatInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryStatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryStatInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryStatInfo = (CShfeFtdcRspQryStatInfoField *)&RspQryStatInfo;
			m_pSpi->OnRspQryStatInfoTopic(pRspQryStatInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryStatInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryStatInfoTopic(pRspQryStatInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///系统状态信息
void CFtdcSysUserApiImpl::OnRtnStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnStatInfoField RtnStatInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnStatInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnStatInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnStatInfoTopic((CShfeFtdcRtnStatInfoField *)&RtnStatInfo);
		}
		itor.Next();
	}
}

///交易系统前置报单分布区间
void CFtdcSysUserApiImpl::OnRspQryTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryTradeOrderRttCutLineField RspQryTradeOrderRttCutLine;
	CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryTradeOrderRttCutLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryTradeOrderRttCutLine);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryTradeOrderRttCutLine = (CShfeFtdcRspQryTradeOrderRttCutLineField *)&RspQryTradeOrderRttCutLine;
			m_pSpi->OnRspQryTradeOrderRttCutLineTopic(pRspQryTradeOrderRttCutLine, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryTradeOrderRttCutLine == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryTradeOrderRttCutLineTopic(pRspQryTradeOrderRttCutLine, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///交易系统前置报单分布区间
void CFtdcSysUserApiImpl::OnRtnTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnTradeOrderRttCutLineField RtnTradeOrderRttCutLine;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnTradeOrderRttCutLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnTradeOrderRttCutLine);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnTradeOrderRttCutLineTopic((CShfeFtdcRtnTradeOrderRttCutLineField *)&RtnTradeOrderRttCutLine);
		}
		itor.Next();
	}
}

///会员客户信息
void CFtdcSysUserApiImpl::OnRspQryClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryClientInfoField RspQryClientInfo;
	CShfeFtdcRspQryClientInfoField *pRspQryClientInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryClientInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryClientInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryClientInfo = (CShfeFtdcRspQryClientInfoField *)&RspQryClientInfo;
			m_pSpi->OnRspQryClientInfoTopic(pRspQryClientInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryClientInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryClientInfoTopic(pRspQryClientInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员客户信息
void CFtdcSysUserApiImpl::OnRtnClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnClientInfoField RtnClientInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnClientInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnClientInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnClientInfoTopic((CShfeFtdcRtnClientInfoField *)&RtnClientInfo);
		}
		itor.Next();
	}
}

///应答事件描述
void CFtdcSysUserApiImpl::OnRspQryEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryEventDescriptionField RspQryEventDescription;
	CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryEventDescriptionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryEventDescription);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryEventDescription = (CShfeFtdcRspQryEventDescriptionField *)&RspQryEventDescription;
			m_pSpi->OnRspQryEventDescriptionTopic(pRspQryEventDescription, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryEventDescription == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryEventDescriptionTopic(pRspQryEventDescription, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅事件描述
void CFtdcSysUserApiImpl::OnRtnEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnEventDescriptionField RtnEventDescription;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnEventDescriptionField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnEventDescription);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnEventDescriptionTopic((CShfeFtdcRtnEventDescriptionField *)&RtnEventDescription);
		}
		itor.Next();
	}
}

///应答前置唯一ID信息
void CFtdcSysUserApiImpl::OnRspQryFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFrontUniqueIDField RspQryFrontUniqueID;
	CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFrontUniqueIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFrontUniqueID);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFrontUniqueID = (CShfeFtdcRspQryFrontUniqueIDField *)&RspQryFrontUniqueID;
			m_pSpi->OnRspQryFrontUniqueIDTopic(pRspQryFrontUniqueID, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryFrontUniqueID == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFrontUniqueIDTopic(pRspQryFrontUniqueID, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅前置唯一ID信息
void CFtdcSysUserApiImpl::OnRtnFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnFrontUniqueIDField RtnFrontUniqueID;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFrontUniqueIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFrontUniqueID);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFrontUniqueIDTopic((CShfeFtdcRtnFrontUniqueIDField *)&RtnFrontUniqueID);
		}
		itor.Next();
	}
}

///会员线路地址变更回应
void CFtdcSysUserApiImpl::OnRspQryNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartyLinkAddrChangeField RspQryNetPartyLinkAddrChange;
	CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartyLinkAddrChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartyLinkAddrChange);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartyLinkAddrChange = (CShfeFtdcRspQryNetPartyLinkAddrChangeField *)&RspQryNetPartyLinkAddrChange;
			m_pSpi->OnRspQryNetPartyLinkAddrChangeTopic(pRspQryNetPartyLinkAddrChange, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetPartyLinkAddrChange == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartyLinkAddrChangeTopic(pRspQryNetPartyLinkAddrChange, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅会员线路地址变更信息
void CFtdcSysUserApiImpl::OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetPartyLinkAddrChangeField RtnNetPartyLinkAddrChange;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartyLinkAddrChangeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartyLinkAddrChange);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartyLinkAddrChangeTopic((CShfeFtdcRtnNetPartyLinkAddrChangeField *)&RtnNetPartyLinkAddrChange);
		}
		itor.Next();
	}
}

///应答已删除会员列表信息
void CFtdcSysUserApiImpl::OnRspQryNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDelPartyLinkInfoField RspQryNetDelPartyLinkInfo;
	CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDelPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDelPartyLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDelPartyLinkInfo = (CShfeFtdcRspQryNetDelPartyLinkInfoField *)&RspQryNetDelPartyLinkInfo;
			m_pSpi->OnRspQryNetDelPartyLinkInfoTopic(pRspQryNetDelPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetDelPartyLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDelPartyLinkInfoTopic(pRspQryNetDelPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅已删除会员列表信息
void CFtdcSysUserApiImpl::OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetDelPartyLinkInfoField RtnNetDelPartyLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDelPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDelPartyLinkInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDelPartyLinkInfoTopic((CShfeFtdcRtnNetDelPartyLinkInfoField *)&RtnNetDelPartyLinkInfo);
		}
		itor.Next();
	}
}

///返回网络性能排序
void CFtdcSysUserApiImpl::OnRspQryPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryPerformanceTopField RspQryPerformanceTop;
	CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryPerformanceTopField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryPerformanceTop);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryPerformanceTop = (CShfeFtdcRspQryPerformanceTopField *)&RspQryPerformanceTop;
			m_pSpi->OnRspQryPerformanceTopTopic(pRspQryPerformanceTop, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryPerformanceTop == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryPerformanceTopTopic(pRspQryPerformanceTop, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅网络性能排序
void CFtdcSysUserApiImpl::OnRtnPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnPerformanceTopField RtnPerformanceTop;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnPerformanceTopField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnPerformanceTop);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnPerformanceTopTopic((CShfeFtdcRtnPerformanceTopField *)&RtnPerformanceTop);
		}
		itor.Next();
	}
}

///返回约状态切换数据
void CFtdcSysUserApiImpl::OnRspQryInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryInstrumentStatusField RspQryInstrumentStatus;
	CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryInstrumentStatus);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryInstrumentStatus = (CShfeFtdcRspQryInstrumentStatusField *)&RspQryInstrumentStatus;
			m_pSpi->OnRspQryInstrumentStatusTopic(pRspQryInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryInstrumentStatus == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryInstrumentStatusTopic(pRspQryInstrumentStatus, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅约状态切换数据
void CFtdcSysUserApiImpl::OnRtnInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnInstrumentStatusField RtnInstrumentStatus;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnInstrumentStatusField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnInstrumentStatus);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnInstrumentStatusTopic((CShfeFtdcRtnInstrumentStatusField *)&RtnInstrumentStatus);
		}
		itor.Next();
	}
}

///返回合约交易节信息
void CFtdcSysUserApiImpl::OnRspQryCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryCurrTradingSegmentAttrField RspQryCurrTradingSegmentAttr;
	CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryCurrTradingSegmentAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryCurrTradingSegmentAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryCurrTradingSegmentAttr = (CShfeFtdcRspQryCurrTradingSegmentAttrField *)&RspQryCurrTradingSegmentAttr;
			m_pSpi->OnRspQryCurrTradingSegmentAttrTopic(pRspQryCurrTradingSegmentAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryCurrTradingSegmentAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryCurrTradingSegmentAttrTopic(pRspQryCurrTradingSegmentAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅合约交易节信息
void CFtdcSysUserApiImpl::OnRtnCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnCurrTradingSegmentAttrField RtnCurrTradingSegmentAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnCurrTradingSegmentAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnCurrTradingSegmentAttr);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnCurrTradingSegmentAttrTopic((CShfeFtdcRtnCurrTradingSegmentAttrField *)&RtnCurrTradingSegmentAttr);
		}
		itor.Next();
	}
}

///网络大区划分应答
void CFtdcSysUserApiImpl::OnRspQryNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetAreaField RspQryNetArea;
	CShfeFtdcRspQryNetAreaField *pRspQryNetArea = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetArea);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetArea = (CShfeFtdcRspQryNetAreaField *)&RspQryNetArea;
			m_pSpi->OnRspQryNetAreaTopic(pRspQryNetArea, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetArea == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetAreaTopic(pRspQryNetArea, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络大区划分应答
void CFtdcSysUserApiImpl::OnRtnNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetAreaField RtnNetArea;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetArea);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetAreaTopic((CShfeFtdcRtnNetAreaField *)&RtnNetArea);
		}
		itor.Next();
	}
}

///网络子区应答
void CFtdcSysUserApiImpl::OnRspQryNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetSubAreaField RspQryNetSubArea;
	CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetSubAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetSubArea);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetSubArea = (CShfeFtdcRspQryNetSubAreaField *)&RspQryNetSubArea;
			m_pSpi->OnRspQryNetSubAreaTopic(pRspQryNetSubArea, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetSubArea == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetSubAreaTopic(pRspQryNetSubArea, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络子区应答
void CFtdcSysUserApiImpl::OnRtnNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetSubAreaField RtnNetSubArea;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetSubAreaField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetSubArea);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetSubAreaTopic((CShfeFtdcRtnNetSubAreaField *)&RtnNetSubArea);
		}
		itor.Next();
	}
}

///网络子区IP应答
void CFtdcSysUserApiImpl::OnRspQryNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetSubAreaIPField RspQryNetSubAreaIP;
	CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetSubAreaIPField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetSubAreaIP);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetSubAreaIP = (CShfeFtdcRspQryNetSubAreaIPField *)&RspQryNetSubAreaIP;
			m_pSpi->OnRspQryNetSubAreaIPTopic(pRspQryNetSubAreaIP, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetSubAreaIP == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetSubAreaIPTopic(pRspQryNetSubAreaIP, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络子区IP应答
void CFtdcSysUserApiImpl::OnRtnNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetSubAreaIPField RtnNetSubAreaIP;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetSubAreaIPField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetSubAreaIP);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetSubAreaIPTopic((CShfeFtdcRtnNetSubAreaIPField *)&RtnNetSubAreaIP);
		}
		itor.Next();
	}
}

///网络设备
void CFtdcSysUserApiImpl::OnRspQryNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceField RspQryNetDevice;
	CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDevice);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDevice = (CShfeFtdcRspQryNetDeviceField *)&RspQryNetDevice;
			m_pSpi->OnRspQryNetDeviceTopic(pRspQryNetDevice, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetDevice == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceTopic(pRspQryNetDevice, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///网络设备
void CFtdcSysUserApiImpl::OnRtnNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetDeviceField RtnNetDevice;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDevice);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceTopic((CShfeFtdcRtnNetDeviceField *)&RtnNetDevice);
		}
		itor.Next();
	}
}

///网络设备探测请求应答
void CFtdcSysUserApiImpl::OnRspQryNetDeviceDetectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceDetectField RspQryNetDeviceDetect;
	CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceDetectField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceDetect);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceDetect = (CShfeFtdcRspQryNetDeviceDetectField *)&RspQryNetDeviceDetect;
			m_pSpi->OnRspQryNetDeviceDetectTopic(pRspQryNetDeviceDetect, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetDeviceDetect == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceDetectTopic(pRspQryNetDeviceDetect, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///大楼
void CFtdcSysUserApiImpl::OnRspQryNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetBuildingField RspQryNetBuilding;
	CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetBuildingField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetBuilding);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetBuilding = (CShfeFtdcRspQryNetBuildingField *)&RspQryNetBuilding;
			m_pSpi->OnRspQryNetBuildingTopic(pRspQryNetBuilding, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetBuilding == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetBuildingTopic(pRspQryNetBuilding, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///大楼
void CFtdcSysUserApiImpl::OnRtnNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetBuildingField RtnNetBuilding;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetBuildingField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetBuilding);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetBuildingTopic((CShfeFtdcRtnNetBuildingField *)&RtnNetBuilding);
		}
		itor.Next();
	}
}

///机房
void CFtdcSysUserApiImpl::OnRspQryNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetRoomField RspQryNetRoom;
	CShfeFtdcRspQryNetRoomField *pRspQryNetRoom = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetRoomField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetRoom);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetRoom = (CShfeFtdcRspQryNetRoomField *)&RspQryNetRoom;
			m_pSpi->OnRspQryNetRoomTopic(pRspQryNetRoom, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetRoom == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetRoomTopic(pRspQryNetRoom, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///机房
void CFtdcSysUserApiImpl::OnRtnNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetRoomField RtnNetRoom;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetRoomField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetRoom);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetRoomTopic((CShfeFtdcRtnNetRoomField *)&RtnNetRoom);
		}
		itor.Next();
	}
}

///机柜
void CFtdcSysUserApiImpl::OnRspQryNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetCabinetsField RspQryNetCabinets;
	CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetCabinetsField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetCabinets);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetCabinets = (CShfeFtdcRspQryNetCabinetsField *)&RspQryNetCabinets;
			m_pSpi->OnRspQryNetCabinetsTopic(pRspQryNetCabinets, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetCabinets == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetCabinetsTopic(pRspQryNetCabinets, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///机柜
void CFtdcSysUserApiImpl::OnRtnNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetCabinetsField RtnNetCabinets;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetCabinetsField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetCabinets);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetCabinetsTopic((CShfeFtdcRtnNetCabinetsField *)&RtnNetCabinets);
		}
		itor.Next();
	}
}

///OID
void CFtdcSysUserApiImpl::OnRspQryNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetOIDField RspQryNetOID;
	CShfeFtdcRspQryNetOIDField *pRspQryNetOID = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetOID);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetOID = (CShfeFtdcRspQryNetOIDField *)&RspQryNetOID;
			m_pSpi->OnRspQryNetOIDTopic(pRspQryNetOID, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetOID == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetOIDTopic(pRspQryNetOID, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///OID
void CFtdcSysUserApiImpl::OnRtnNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetOIDField RtnNetOID;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetOID);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetOIDTopic((CShfeFtdcRtnNetOIDField *)&RtnNetOID);
		}
		itor.Next();
	}
}

///时间策略
void CFtdcSysUserApiImpl::OnRspQryNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetTimePolicyField RspQryNetTimePolicy;
	CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetTimePolicyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetTimePolicy);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetTimePolicy = (CShfeFtdcRspQryNetTimePolicyField *)&RspQryNetTimePolicy;
			m_pSpi->OnRspQryNetTimePolicyTopic(pRspQryNetTimePolicy, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetTimePolicy == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetTimePolicyTopic(pRspQryNetTimePolicy, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///时间策略
void CFtdcSysUserApiImpl::OnRtnNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetTimePolicyField RtnNetTimePolicy;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetTimePolicyField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetTimePolicy);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetTimePolicyTopic((CShfeFtdcRtnNetTimePolicyField *)&RtnNetTimePolicy);
		}
		itor.Next();
	}
}

///采集任务
void CFtdcSysUserApiImpl::OnRspQryNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetGatherTaskField RspQryNetGatherTask;
	CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetGatherTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetGatherTask);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetGatherTask = (CShfeFtdcRspQryNetGatherTaskField *)&RspQryNetGatherTask;
			m_pSpi->OnRspQryNetGatherTaskTopic(pRspQryNetGatherTask, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetGatherTask == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetGatherTaskTopic(pRspQryNetGatherTask, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///采集任务
void CFtdcSysUserApiImpl::OnRtnNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetGatherTaskField RtnNetGatherTask;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetGatherTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetGatherTask);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetGatherTaskTopic((CShfeFtdcRtnNetGatherTaskField *)&RtnNetGatherTask);
		}
		itor.Next();
	}
}

///设备变更
void CFtdcSysUserApiImpl::OnRspQryNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceChgField RspQryNetDeviceChg;
	CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceChg);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceChg = (CShfeFtdcRspQryNetDeviceChgField *)&RspQryNetDeviceChg;
			m_pSpi->OnRspQryNetDeviceChgTopic(pRspQryNetDeviceChg, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetDeviceChg == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceChgTopic(pRspQryNetDeviceChg, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备变更
void CFtdcSysUserApiImpl::OnRtnNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetDeviceChgField RtnNetDeviceChg;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceChgField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceChg);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceChgTopic((CShfeFtdcRtnNetDeviceChgField *)&RtnNetDeviceChg);
		}
		itor.Next();
	}
}

///常用设备型号
void CFtdcSysUserApiImpl::OnRspQryNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceTypeField RspQryNetDeviceType;
	CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceType = (CShfeFtdcRspQryNetDeviceTypeField *)&RspQryNetDeviceType;
			m_pSpi->OnRspQryNetDeviceTypeTopic(pRspQryNetDeviceType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetDeviceType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceTypeTopic(pRspQryNetDeviceType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///常用设备型号
void CFtdcSysUserApiImpl::OnRtnNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetDeviceTypeField RtnNetDeviceType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceType);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceTypeTopic((CShfeFtdcRtnNetDeviceTypeField *)&RtnNetDeviceType);
		}
		itor.Next();
	}
}

///常用设备类别
void CFtdcSysUserApiImpl::OnRspQryNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetDeviceCategoryField RspQryNetDeviceCategory;
	CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetDeviceCategoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetDeviceCategory);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetDeviceCategory = (CShfeFtdcRspQryNetDeviceCategoryField *)&RspQryNetDeviceCategory;
			m_pSpi->OnRspQryNetDeviceCategoryTopic(pRspQryNetDeviceCategory, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetDeviceCategory == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetDeviceCategoryTopic(pRspQryNetDeviceCategory, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///常用设备类别
void CFtdcSysUserApiImpl::OnRtnNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetDeviceCategoryField RtnNetDeviceCategory;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetDeviceCategoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetDeviceCategory);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetDeviceCategoryTopic((CShfeFtdcRtnNetDeviceCategoryField *)&RtnNetDeviceCategory);
		}
		itor.Next();
	}
}

///设备厂商
void CFtdcSysUserApiImpl::OnRspQryNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetManufactoryField RspQryNetManufactory;
	CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetManufactoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetManufactory);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetManufactory = (CShfeFtdcRspQryNetManufactoryField *)&RspQryNetManufactory;
			m_pSpi->OnRspQryNetManufactoryTopic(pRspQryNetManufactory, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetManufactory == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetManufactoryTopic(pRspQryNetManufactory, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备厂商
void CFtdcSysUserApiImpl::OnRtnNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetManufactoryField RtnNetManufactory;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetManufactoryField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetManufactory);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetManufactoryTopic((CShfeFtdcRtnNetManufactoryField *)&RtnNetManufactory);
		}
		itor.Next();
	}
}

///设备共同体
void CFtdcSysUserApiImpl::OnRspQryNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetCommunityField RspQryNetCommunity;
	CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetCommunityField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetCommunity);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetCommunity = (CShfeFtdcRspQryNetCommunityField *)&RspQryNetCommunity;
			m_pSpi->OnRspQryNetCommunityTopic(pRspQryNetCommunity, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetCommunity == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetCommunityTopic(pRspQryNetCommunity, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备共同体
void CFtdcSysUserApiImpl::OnRtnNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetCommunityField RtnNetCommunity;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetCommunityField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetCommunity);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetCommunityTopic((CShfeFtdcRtnNetCommunityField *)&RtnNetCommunity);
		}
		itor.Next();
	}
}

///端口类型
void CFtdcSysUserApiImpl::OnRspQryNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPortTypeField RspQryNetPortType;
	CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPortTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPortType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPortType = (CShfeFtdcRspQryNetPortTypeField *)&RspQryNetPortType;
			m_pSpi->OnRspQryNetPortTypeTopic(pRspQryNetPortType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetPortType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPortTypeTopic(pRspQryNetPortType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///端口类型
void CFtdcSysUserApiImpl::OnRtnNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetPortTypeField RtnNetPortType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPortTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPortType);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPortTypeTopic((CShfeFtdcRtnNetPortTypeField *)&RtnNetPortType);
		}
		itor.Next();
	}
}

///会员接入地点
void CFtdcSysUserApiImpl::OnRspQryNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartAccessSpotField RspQryNetPartAccessSpot;
	CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartAccessSpotField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartAccessSpot);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartAccessSpot = (CShfeFtdcRspQryNetPartAccessSpotField *)&RspQryNetPartAccessSpot;
			m_pSpi->OnRspQryNetPartAccessSpotTopic(pRspQryNetPartAccessSpot, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetPartAccessSpot == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartAccessSpotTopic(pRspQryNetPartAccessSpot, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员接入地点
void CFtdcSysUserApiImpl::OnRtnNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetPartAccessSpotField RtnNetPartAccessSpot;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartAccessSpotField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartAccessSpot);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartAccessSpotTopic((CShfeFtdcRtnNetPartAccessSpotField *)&RtnNetPartAccessSpot);
		}
		itor.Next();
	}
}

///端口
void CFtdcSysUserApiImpl::OnRspQryNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetInterfaceField RspQryNetInterface;
	CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetInterfaceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetInterface);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetInterface = (CShfeFtdcRspQryNetInterfaceField *)&RspQryNetInterface;
			m_pSpi->OnRspQryNetInterfaceTopic(pRspQryNetInterface, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetInterface == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetInterfaceTopic(pRspQryNetInterface, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///端口
void CFtdcSysUserApiImpl::OnRtnNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetInterfaceField RtnNetInterface;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetInterfaceField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetInterface);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetInterfaceTopic((CShfeFtdcRtnNetInterfaceField *)&RtnNetInterface);
		}
		itor.Next();
	}
}

///GeneralOID
void CFtdcSysUserApiImpl::OnRspQryNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetGeneralOIDField RspQryNetGeneralOID;
	CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetGeneralOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetGeneralOID);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetGeneralOID = (CShfeFtdcRspQryNetGeneralOIDField *)&RspQryNetGeneralOID;
			m_pSpi->OnRspQryNetGeneralOIDTopic(pRspQryNetGeneralOID, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetGeneralOID == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetGeneralOIDTopic(pRspQryNetGeneralOID, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///GeneralOID
void CFtdcSysUserApiImpl::OnRtnNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetGeneralOIDField RtnNetGeneralOID;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetGeneralOIDField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetGeneralOID);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetGeneralOIDTopic((CShfeFtdcRtnNetGeneralOIDField *)&RtnNetGeneralOID);
		}
		itor.Next();
	}
}

///监控对象类别
void CFtdcSysUserApiImpl::OnRspQryNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTypeField RspQryNetMonitorType;
	CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorType = (CShfeFtdcRspQryNetMonitorTypeField *)&RspQryNetMonitorType;
			m_pSpi->OnRspQryNetMonitorTypeTopic(pRspQryNetMonitorType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTypeTopic(pRspQryNetMonitorType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控对象类别
void CFtdcSysUserApiImpl::OnRtnNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorTypeField RtnNetMonitorType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorType);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTypeTopic((CShfeFtdcRtnNetMonitorTypeField *)&RtnNetMonitorType);
		}
		itor.Next();
	}
}

///指标统表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorAttrScopeField RspQryNetMonitorAttrScope;
	CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorAttrScopeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorAttrScope);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorAttrScope = (CShfeFtdcRspQryNetMonitorAttrScopeField *)&RspQryNetMonitorAttrScope;
			m_pSpi->OnRspQryNetMonitorAttrScopeTopic(pRspQryNetMonitorAttrScope, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorAttrScope == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorAttrScopeTopic(pRspQryNetMonitorAttrScope, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///指标统表
void CFtdcSysUserApiImpl::OnRtnNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorAttrScopeField RtnNetMonitorAttrScope;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorAttrScopeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorAttrScope);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorAttrScopeTopic((CShfeFtdcRtnNetMonitorAttrScopeField *)&RtnNetMonitorAttrScope);
		}
		itor.Next();
	}
}

///监控指标表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorAttrTypeField RspQryNetMonitorAttrType;
	CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorAttrTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorAttrType);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorAttrType = (CShfeFtdcRspQryNetMonitorAttrTypeField *)&RspQryNetMonitorAttrType;
			m_pSpi->OnRspQryNetMonitorAttrTypeTopic(pRspQryNetMonitorAttrType, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorAttrType == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorAttrTypeTopic(pRspQryNetMonitorAttrType, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控指标表
void CFtdcSysUserApiImpl::OnRtnNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorAttrTypeField RtnNetMonitorAttrType;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorAttrTypeField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorAttrType);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorAttrTypeTopic((CShfeFtdcRtnNetMonitorAttrTypeField *)&RtnNetMonitorAttrType);
		}
		itor.Next();
	}
}

///监控对象指标表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorObjectAttrField RspQryNetMonitorObjectAttr;
	CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorObjectAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorObjectAttr = (CShfeFtdcRspQryNetMonitorObjectAttrField *)&RspQryNetMonitorObjectAttr;
			m_pSpi->OnRspQryNetMonitorObjectAttrTopic(pRspQryNetMonitorObjectAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorObjectAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorObjectAttrTopic(pRspQryNetMonitorObjectAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///监控对象指标表
void CFtdcSysUserApiImpl::OnRtnNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorObjectAttrField RtnNetMonitorObjectAttr;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorObjectAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorObjectAttr);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorObjectAttrTopic((CShfeFtdcRtnNetMonitorObjectAttrField *)&RtnNetMonitorObjectAttr);
		}
		itor.Next();
	}
}

///设备对象组表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorDeviceGroupField RspQryNetMonitorDeviceGroup;
	CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorDeviceGroupField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorDeviceGroup);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorDeviceGroup = (CShfeFtdcRspQryNetMonitorDeviceGroupField *)&RspQryNetMonitorDeviceGroup;
			m_pSpi->OnRspQryNetMonitorDeviceGroupTopic(pRspQryNetMonitorDeviceGroup, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorDeviceGroup == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorDeviceGroupTopic(pRspQryNetMonitorDeviceGroup, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备对象组表
void CFtdcSysUserApiImpl::OnRtnNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorDeviceGroupField RtnNetMonitorDeviceGroup;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorDeviceGroupField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorDeviceGroup);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorDeviceGroupTopic((CShfeFtdcRtnNetMonitorDeviceGroupField *)&RtnNetMonitorDeviceGroup);
		}
		itor.Next();
	}
}

///任务信息表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskInfoField RspQryNetMonitorTaskInfo;
	CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskInfo = (CShfeFtdcRspQryNetMonitorTaskInfoField *)&RspQryNetMonitorTaskInfo;
			m_pSpi->OnRspQryNetMonitorTaskInfoTopic(pRspQryNetMonitorTaskInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorTaskInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskInfoTopic(pRspQryNetMonitorTaskInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务信息表
void CFtdcSysUserApiImpl::OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorTaskInfoField RtnNetMonitorTaskInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskInfoTopic((CShfeFtdcRtnNetMonitorTaskInfoField *)&RtnNetMonitorTaskInfo);
		}
		itor.Next();
	}
}

///任务结果表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskResultField RspQryNetMonitorTaskResult;
	CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskResult);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskResult = (CShfeFtdcRspQryNetMonitorTaskResultField *)&RspQryNetMonitorTaskResult;
			m_pSpi->OnRspQryNetMonitorTaskResultTopic(pRspQryNetMonitorTaskResult, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorTaskResult == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskResultTopic(pRspQryNetMonitorTaskResult, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务结果表
void CFtdcSysUserApiImpl::OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorTaskResultField RtnNetMonitorTaskResult;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskResult);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskResultTopic((CShfeFtdcRtnNetMonitorTaskResultField *)&RtnNetMonitorTaskResult);
		}
		itor.Next();
	}
}

///任务对象集
void CFtdcSysUserApiImpl::OnRspQryNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskObjectSetField RspQryNetMonitorTaskObjectSet;
	CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskObjectSetField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskObjectSet);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskObjectSet = (CShfeFtdcRspQryNetMonitorTaskObjectSetField *)&RspQryNetMonitorTaskObjectSet;
			m_pSpi->OnRspQryNetMonitorTaskObjectSetTopic(pRspQryNetMonitorTaskObjectSet, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorTaskObjectSet == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskObjectSetTopic(pRspQryNetMonitorTaskObjectSet, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务对象集
void CFtdcSysUserApiImpl::OnRtnNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorTaskObjectSetField RtnNetMonitorTaskObjectSet;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskObjectSetField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskObjectSet);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskObjectSetTopic((CShfeFtdcRtnNetMonitorTaskObjectSetField *)&RtnNetMonitorTaskObjectSet);
		}
		itor.Next();
	}
}

///会员链路信息表
void CFtdcSysUserApiImpl::OnRspQryNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartyLinkInfoField RspQryNetPartyLinkInfo;
	CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartyLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartyLinkInfo = (CShfeFtdcRspQryNetPartyLinkInfoField *)&RspQryNetPartyLinkInfo;
			m_pSpi->OnRspQryNetPartyLinkInfoTopic(pRspQryNetPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetPartyLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartyLinkInfoTopic(pRspQryNetPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员链路信息表
void CFtdcSysUserApiImpl::OnRtnNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetPartyLinkInfoField RtnNetPartyLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartyLinkInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartyLinkInfoTopic((CShfeFtdcRtnNetPartyLinkInfoField *)&RtnNetPartyLinkInfo);
		}
		itor.Next();
	}
}

///监控动作指标对照表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorActionAttrField RspQryNetMonitorActionAttr;
	CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorActionAttrField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorActionAttr);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorActionAttr = (CShfeFtdcRspQryNetMonitorActionAttrField *)&RspQryNetMonitorActionAttr;
			m_pSpi->OnRspQryNetMonitorActionAttrTopic(pRspQryNetMonitorActionAttr, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorActionAttr == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorActionAttrTopic(pRspQryNetMonitorActionAttr, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///模块
void CFtdcSysUserApiImpl::OnRspQryNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetModuleField RspQryNetModule;
	CShfeFtdcRspQryNetModuleField *pRspQryNetModule = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetModuleField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetModule);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetModule = (CShfeFtdcRspQryNetModuleField *)&RspQryNetModule;
			m_pSpi->OnRspQryNetModuleTopic(pRspQryNetModule, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetModule == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetModuleTopic(pRspQryNetModule, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///模块
void CFtdcSysUserApiImpl::OnRtnNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetModuleField RtnNetModule;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetModuleField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetModule);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetModuleTopic((CShfeFtdcRtnNetModuleField *)&RtnNetModule);
		}
		itor.Next();
	}
}

///任务结果状态表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorTaskStatusResultField RspQryNetMonitorTaskStatusResult;
	CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorTaskStatusResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorTaskStatusResult);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorTaskStatusResult = (CShfeFtdcRspQryNetMonitorTaskStatusResultField *)&RspQryNetMonitorTaskStatusResult;
			m_pSpi->OnRspQryNetMonitorTaskStatusResultTopic(pRspQryNetMonitorTaskStatusResult, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorTaskStatusResult == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorTaskStatusResultTopic(pRspQryNetMonitorTaskStatusResult, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务结果状态表
void CFtdcSysUserApiImpl::OnRtnNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorTaskStatusResultField RtnNetMonitorTaskStatusResult;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorTaskStatusResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorTaskStatusResult);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorTaskStatusResultTopic((CShfeFtdcRtnNetMonitorTaskStatusResultField *)&RtnNetMonitorTaskStatusResult);
		}
		itor.Next();
	}
}

///设备配置表
void CFtdcSysUserApiImpl::OnRspQryNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetCfgFileField RspQryNetCfgFile;
	CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetCfgFileField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetCfgFile);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetCfgFile = (CShfeFtdcRspQryNetCfgFileField *)&RspQryNetCfgFile;
			m_pSpi->OnRspQryNetCfgFileTopic(pRspQryNetCfgFile, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetCfgFile == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetCfgFileTopic(pRspQryNetCfgFile, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///设备配置表
void CFtdcSysUserApiImpl::OnRtnNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetCfgFileField RtnNetCfgFile;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetCfgFileField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetCfgFile);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetCfgFileTopic((CShfeFtdcRtnNetCfgFileField *)&RtnNetCfgFile);
		}
		itor.Next();
	}
}

///任务结果规则分析表
void CFtdcSysUserApiImpl::OnRspQryNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetMonitorDeviceTaskField RspQryNetMonitorDeviceTask;
	CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetMonitorDeviceTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetMonitorDeviceTask);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetMonitorDeviceTask = (CShfeFtdcRspQryNetMonitorDeviceTaskField *)&RspQryNetMonitorDeviceTask;
			m_pSpi->OnRspQryNetMonitorDeviceTaskTopic(pRspQryNetMonitorDeviceTask, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetMonitorDeviceTask == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetMonitorDeviceTaskTopic(pRspQryNetMonitorDeviceTask, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///任务结果规则分析表
void CFtdcSysUserApiImpl::OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetMonitorDeviceTaskField RtnNetMonitorDeviceTask;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetMonitorDeviceTaskField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetMonitorDeviceTask);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetMonitorDeviceTaskTopic((CShfeFtdcRtnNetMonitorDeviceTaskField *)&RtnNetMonitorDeviceTask);
		}
		itor.Next();
	}
}

///文件通用操作
void CFtdcSysUserApiImpl::OnRspQryFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryFileGeneralOperField RspQryFileGeneralOper;
	CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryFileGeneralOperField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryFileGeneralOper);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryFileGeneralOper = (CShfeFtdcRspQryFileGeneralOperField *)&RspQryFileGeneralOper;
			m_pSpi->OnRspQryFileGeneralOperTopic(pRspQryFileGeneralOper, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryFileGeneralOper == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryFileGeneralOperTopic(pRspQryFileGeneralOper, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///文件通用操作
void CFtdcSysUserApiImpl::OnRtnFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnFileGeneralOperField RtnFileGeneralOper;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnFileGeneralOperField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnFileGeneralOper);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnFileGeneralOperTopic((CShfeFtdcRtnFileGeneralOperField *)&RtnFileGeneralOper);
		}
		itor.Next();
	}
}

///基线表
void CFtdcSysUserApiImpl::OnRspQryNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetBaseLineField RspQryNetBaseLine;
	CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetBaseLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetBaseLine);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetBaseLine = (CShfeFtdcRspQryNetBaseLineField *)&RspQryNetBaseLine;
			m_pSpi->OnRspQryNetBaseLineTopic(pRspQryNetBaseLine, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetBaseLine == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetBaseLineTopic(pRspQryNetBaseLine, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///基线表
void CFtdcSysUserApiImpl::OnRtnNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetBaseLineField RtnNetBaseLine;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetBaseLineField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetBaseLine);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetBaseLineTopic((CShfeFtdcRtnNetBaseLineField *)&RtnNetBaseLine);
		}
		itor.Next();
	}
}

///基线结果表
void CFtdcSysUserApiImpl::OnRspQryNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetBaseLineResultField RspQryNetBaseLineResult;
	CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetBaseLineResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetBaseLineResult);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetBaseLineResult = (CShfeFtdcRspQryNetBaseLineResultField *)&RspQryNetBaseLineResult;
			m_pSpi->OnRspQryNetBaseLineResultTopic(pRspQryNetBaseLineResult, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetBaseLineResult == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetBaseLineResultTopic(pRspQryNetBaseLineResult, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///基线结果表
void CFtdcSysUserApiImpl::OnRtnNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetBaseLineResultField RtnNetBaseLineResult;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetBaseLineResultField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetBaseLineResult);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetBaseLineResultTopic((CShfeFtdcRtnNetBaseLineResultField *)&RtnNetBaseLineResult);
		}
		itor.Next();
	}
}

///会员链路状态信息表
void CFtdcSysUserApiImpl::OnRspQryNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetPartyLinkStatusInfoField RspQryNetPartyLinkStatusInfo;
	CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetPartyLinkStatusInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetPartyLinkStatusInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetPartyLinkStatusInfo = (CShfeFtdcRspQryNetPartyLinkStatusInfoField *)&RspQryNetPartyLinkStatusInfo;
			m_pSpi->OnRspQryNetPartyLinkStatusInfoTopic(pRspQryNetPartyLinkStatusInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetPartyLinkStatusInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetPartyLinkStatusInfoTopic(pRspQryNetPartyLinkStatusInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///会员链路状态信息表
void CFtdcSysUserApiImpl::OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetPartyLinkStatusInfoField RtnNetPartyLinkStatusInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetPartyLinkStatusInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetPartyLinkStatusInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetPartyLinkStatusInfoTopic((CShfeFtdcRtnNetPartyLinkStatusInfoField *)&RtnNetPartyLinkStatusInfo);
		}
		itor.Next();
	}
}

///本地ping结果
void CFtdcSysUserApiImpl::OnRspQryNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetLocalPingResultInfoField RspQryNetLocalPingResultInfo;
	CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetLocalPingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetLocalPingResultInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetLocalPingResultInfo = (CShfeFtdcRspQryNetLocalPingResultInfoField *)&RspQryNetLocalPingResultInfo;
			m_pSpi->OnRspQryNetLocalPingResultInfoTopic(pRspQryNetLocalPingResultInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetLocalPingResultInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetLocalPingResultInfoTopic(pRspQryNetLocalPingResultInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///本地ping结果
void CFtdcSysUserApiImpl::OnRtnNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetLocalPingResultInfoField RtnNetLocalPingResultInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetLocalPingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetLocalPingResultInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetLocalPingResultInfoTopic((CShfeFtdcRtnNetLocalPingResultInfoField *)&RtnNetLocalPingResultInfo);
		}
		itor.Next();
	}
}

///远程ping结果
void CFtdcSysUserApiImpl::OnRspQryNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetRomotePingResultInfoField RspQryNetRomotePingResultInfo;
	CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetRomotePingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetRomotePingResultInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetRomotePingResultInfo = (CShfeFtdcRspQryNetRomotePingResultInfoField *)&RspQryNetRomotePingResultInfo;
			m_pSpi->OnRspQryNetRomotePingResultInfoTopic(pRspQryNetRomotePingResultInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetRomotePingResultInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetRomotePingResultInfoTopic(pRspQryNetRomotePingResultInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///远程ping结果
void CFtdcSysUserApiImpl::OnRtnNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetRomotePingResultInfoField RtnNetRomotePingResultInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetRomotePingResultInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetRomotePingResultInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetRomotePingResultInfoTopic((CShfeFtdcRtnNetRomotePingResultInfoField *)&RtnNetRomotePingResultInfo);
		}
		itor.Next();
	}
}

///返回会员链路费用表
void CFtdcSysUserApiImpl::OnRspQryMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryMemberLinkCostField RspQryMemberLinkCost;
	CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryMemberLinkCostField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryMemberLinkCost);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryMemberLinkCost = (CShfeFtdcRspQryMemberLinkCostField *)&RspQryMemberLinkCost;
			m_pSpi->OnRspQryMemberLinkCostTopic(pRspQryMemberLinkCost, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryMemberLinkCost == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryMemberLinkCostTopic(pRspQryMemberLinkCost, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅会员链路费用表
void CFtdcSysUserApiImpl::OnRtnMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnMemberLinkCostField RtnMemberLinkCost;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnMemberLinkCostField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnMemberLinkCost);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnMemberLinkCostTopic((CShfeFtdcRtnMemberLinkCostField *)&RtnMemberLinkCost);
		}
		itor.Next();
	}
}

///返回非会员链路表信息
void CFtdcSysUserApiImpl::OnRspQryNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRspInfoField rspInfoField;
	CShfeFtdcRspInfoField *pRspInfoField = (CShfeFtdcRspInfoField *)&rspInfoField;
	if (FTDC_GET_SINGLE_FIELD(pMessage, &rspInfoField) <= 0)
	{
		pRspInfoField = NULL;
	}
	CFTDRspQryNetNonPartyLinkInfoField RspQryNetNonPartyLinkInfo;
	CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo = NULL;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRspQryNetNonPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RspQryNetNonPartyLinkInfo);
		itor.Next();
		if (m_pSpi != NULL)
		{
			bool bIsLast = false;
			if (pMessage->GetChain() == FTDC_CHAIN_LAST	&& itor.IsEnd())
			{
				bIsLast = true;
			}
			pRspQryNetNonPartyLinkInfo = (CShfeFtdcRspQryNetNonPartyLinkInfoField *)&RspQryNetNonPartyLinkInfo;
			m_pSpi->OnRspQryNetNonPartyLinkInfoTopic(pRspQryNetNonPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), bIsLast);
		}
	}
	
	if (pRspQryNetNonPartyLinkInfo == NULL && m_pSpi != NULL)
	{
		m_pSpi->OnRspQryNetNonPartyLinkInfoTopic(pRspQryNetNonPartyLinkInfo, pRspInfoField, pMessage->GetRequestId(), true);
	}
}

///订阅非会员链路表信息
void CFtdcSysUserApiImpl::OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries)
{
	CFTDRtnNetNonPartyLinkInfoField RtnNetNonPartyLinkInfo;
	CNamedFieldIterator itor = pMessage->GetNamedFieldIterator(&CFTDRtnNetNonPartyLinkInfoField::m_Describe);
	while (!itor.IsEnd())
	{
		itor.Retrieve(&RtnNetNonPartyLinkInfo);
		if (m_pSpi != NULL)
		{
			m_pSpi->OnRtnNetNonPartyLinkInfoTopic((CShfeFtdcRtnNetNonPartyLinkInfoField *)&RtnNetNonPartyLinkInfo);
		}
		itor.Next();
	}
}


