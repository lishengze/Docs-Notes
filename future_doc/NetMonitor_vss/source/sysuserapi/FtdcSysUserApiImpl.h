/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统风险监控系统
///@company 上海期货信息技术有限公司
///@file FtdcSysUserApiImpl.h
///@brief 定义了客户端接口实现
///@history 
///20070207 zhangjie		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSUSERAPIIMPL_H)
#define _FTDCSYSUSERAPIIMPL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "FtdcSysUserApi.h"

#include "FtdcSysUserApiImplBase.h"

///SysUserApi接口实现
class CFtdcSysUserApiImpl : public CFtdcSysUserApiImplBase
{
public:	
	CFtdcSysUserApiImpl(const char *pszFlowPath, CSelectReactor *pReactor);
	virtual void HandleResponse(CFTDCPackage *pMessage, WORD nSequenceSeries);
	

	///CPU查询
	virtual int ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID);

	///Mem查询
	virtual int ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID);

	///process查询
	virtual int ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID);

	///filesystem查询
	virtual int ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID);

	///network查询
	virtual int ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID);

	///主机环境信息查询
	virtual int ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID);

	///获得监控对象信息查询
	virtual int ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID);

	///获得业务进程和主机的对应关系查询
	virtual int ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID);

	///日志文件内容查询
	virtual int ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID);

	///监控内容订阅请求
	virtual int ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID);

	///对象关系查询
	virtual int ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID);

	///用户信息查询请求
	virtual int ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID);

	///在线用户信息查询请求
	virtual int ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID);

	///告警事件查询请求
	virtual int ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID);

	///对象状态指标查询
	virtual int ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID);

	///无效报单查询
	virtual int ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID);

	///报单状态查询
	virtual int ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID);

	///报单成交查询
	virtual int ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID);

	///合约基本属性查询
	virtual int ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID);

	///合约保证金率查询
	virtual int ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID);

	///合约涨跌停板查询
	virtual int ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID);

	///会员限仓查询
	virtual int ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID);

	///客户限仓查询
	virtual int ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID);

	///特殊客户限仓查询
	virtual int ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID);

	///账户出入金查询
	virtual int ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID);

	///客户数据变动查询
	virtual int ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID);

	///会员客户对照变动查询
	virtual int ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID);

	///限仓数据变动查询
	virtual int ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID);

	///保值额度变动查询
	virtual int ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID);

	///会员变动查询
	virtual int ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID);

	///保证金率变动查询
	virtual int ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID);

	///IP地址变动查询
	virtual int ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID);

	///限仓数据变动查询
	virtual int ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID);

	///限仓数据变动查询
	virtual int ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID);

	///历史对象状态指标查询
	virtual int ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID);

	///前置响应信息查询
	virtual int ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID);

	///用户登录
	virtual int ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID);

	///用户登出
	virtual int ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID);

	///用户修改密码
	virtual int ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID);

	///注册用户
	virtual int ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID);

	///删除用户
	virtual int ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID);

	///交易日志查询
	virtual int ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID);

	///告警事件修改
	virtual int ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID);

	///交易系统登录信息查询
	virtual int ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID);

	///会员交易查询
	virtual int ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID);

	///交易峰值查询
	virtual int ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID);

	///管理平台初始化信息查询
	virtual int ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID);

	///管理平台初始化信息查询
	virtual int ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID);

	///
	virtual int ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID);

	///
	virtual int ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID);

	///
	virtual int ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID);

	///监控系统在线用户查询
	virtual int ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID);

	///交易系统前置统计查询
	virtual int ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID);

	///历史峰值查询
	virtual int ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID);

	///日志事件查询
	virtual int ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID);

	///日志事件订阅请求
	virtual int ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID);

	///tomcat信息查询
	virtual int ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID);

	///数据库查询
	virtual int ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID);

	///文件传输请求
	virtual int ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID);

	///日志事件修改请求
	virtual int ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID);

	///告警明细查询
	virtual int ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID);

	///网站访问查询
	virtual int ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID);

	///告警激活变更
	virtual int ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID);

	///通用操作
	virtual int ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID);

	///网络设备连接关系请求
	virtual int ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID);

	///交易系统登录信息请求
	virtual int ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID);

	///交易系统前置报单响应信息
	virtual int ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID);

	///会员席位交易状态
	virtual int ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID);

	///系统路由信息
	virtual int ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID);

	///磁盘I/O信息
	virtual int ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID);

	///系统状态信息
	virtual int ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID);

	///交易系统前置报单分布区间
	virtual int ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID);

	///会员客户信息
	virtual int ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID);

	///请求事件描述
	virtual int ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID);

	///订阅前置唯一ID信息
	virtual int ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID);

	///会员线路地址变更请求
	virtual int ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID);

	///请求已删除会员列表信息
	virtual int ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID);

	///请求网络性能排序
	virtual int ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID);

	///请求约状态切换数据
	virtual int ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID);

	///请求合约交易节信息
	virtual int ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID);

	///最新网络指标查询
	virtual int ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID);

	///网络大区划分查询
	virtual int ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID);

	///网络子区查询
	virtual int ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID);

	///网络子区IP查询
	virtual int ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID);

	///网络设备探测请求
	virtual int ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID);

	///网络设备查询请求
	virtual int ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID);

	///大楼查询
	virtual int ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID);

	///机房查询
	virtual int ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID);

	///机柜查询
	virtual int ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID);

	///OID
	virtual int ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID);

	///时间策略
	virtual int ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID);

	///采集任务查询
	virtual int ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID);

	///设备变更请求
	virtual int ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID);

	///常用设备型号请求
	virtual int ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID);

	///常用设备类别请求
	virtual int ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID);

	///设备厂商请求
	virtual int ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID);

	///设备共同体请求
	virtual int ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID);

	///端口类型请求
	virtual int ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID);

	///会员接入地点请求
	virtual int ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID);

	///端口请求
	virtual int ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID);

	///GeneralOID请求
	virtual int ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID);

	///监控对象类别
	virtual int ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID);

	///指标统表
	virtual int ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID);

	///监控指标表
	virtual int ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID);

	///监控对象指标表
	virtual int ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID);

	///设备对象组表
	virtual int ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID);

	///任务信息表
	virtual int ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID);

	///任务结果表
	virtual int ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID);

	///任务对象集
	virtual int ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID);

	///会员链路信息表
	virtual int ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID);

	///监控动作指标对照表
	virtual int ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID);

	///模块
	virtual int ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID);

	///任务结果状态表
	virtual int ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID);

	///设备配置表
	virtual int ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID);

	///任务结果规则分析表
	virtual int ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID);

	///文件通用操作
	virtual int ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID);

	///基线表
	virtual int ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID);

	///基线结果表
	virtual int ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID);

	///会员链路状态信息表
	virtual int ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID);

	///本地ping结果
	virtual int ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID);

	///远程ping结果
	virtual int ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID);

	///请求非会员链路表信息
	virtual int ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID);

private:
	///CPU应答
	void OnRspQryTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///CPU应答
	void OnRtnTopCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Mem应答
	void OnRspQryTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Mem应答
	void OnRtnTopMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///process应答
	void OnRspQryTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///process应答
	void OnRtnTopProcessInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///filesystem应答
	void OnRspQryFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///filesystem应答
	void OnRtnFileSystemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///network应答
	void OnRspQryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///network应答
	void OnRtnNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得监控对象信息应答
	void OnRspQryMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得监控对象信息应答
	void OnRtnMonitorObjectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得业务进程和主机的对应关系应答
	void OnRspQryObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///获得业务进程和主机的对应关系应答
	void OnRtnObjectRationalTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志文件内容应答
	void OnRspQrySyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志文件内容应答
	void OnRtnSyslogInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控内容订阅应答
	void OnRspQrySubscriberTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象关系查询应答
	void OnRspQryOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象关系查询应答
	void OnRtnOidRelationTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户信息查询请求应答
	void OnRspQryUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户信息查询请求应答
	void OnRtnUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///在线用户信息查询请求应答
	void OnRspQryOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///在线用户信息查询请求应答
	void OnRtnOnlineUserInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警事件查询请求应答
	void OnRspQryWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警事件查询请求应答
	void OnRtnWarningEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象状态指标查询应答
	void OnRspQryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///对象状态指标查询应答
	void OnRtnObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///无效报单查询应答
	void OnRspQryInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///无效报单查询应答
	void OnRtnInvalidateOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单状态查询应答
	void OnRspQryOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单状态查询应答
	void OnRtnOrderStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单成交查询应答
	void OnRspQryBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///报单成交查询应答
	void OnRtnBargainOrderTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约基本属性查询应答
	void OnRspQryInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约基本属性查询应答
	void OnRtnInstPropertyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约保证金率查询应答
	void OnRspQryMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约保证金率查询应答
	void OnRtnMarginRateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约涨跌停板查询应答
	void OnRspQryPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///合约涨跌停板查询应答
	void OnRtnPriceLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员限仓查询应答
	void OnRspQryPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员限仓查询应答
	void OnRtnPartPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户限仓查询应答
	void OnRspQryClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户限仓查询应答
	void OnRtnClientPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///特殊客户限仓查询应答
	void OnRspQrySpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///特殊客户限仓查询应答
	void OnRtnSpecialPosiLimitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///账户出入金查询应答
	void OnRspQryTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///账户出入金查询应答
	void OnRtnTransactionChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户数据变动查询应答
	void OnRspQryClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户数据变动查询应答
	void OnRtnClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户对照变动查询应答
	void OnRspQryPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户对照变动查询应答
	void OnRtnPartClientChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRspQryPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRtnPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保值额度变动查询应答
	void OnRspQryHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保值额度变动查询应答
	void OnRtnHedgeDetailChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员变动查询应答
	void OnRspQryParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员变动查询应答
	void OnRtnParticipantChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保证金率变动查询应答
	void OnRspQryMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///保证金率变动查询应答
	void OnRtnMarginRateChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///IP地址变动查询应答
	void OnRspQryUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///IP地址变动查询应答
	void OnRtnUserIpChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRspQryClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRtnClientPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRspQrySpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///限仓数据变动查询应答
	void OnRtnSpecPosiLimitChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///历史对象状态指标查询应答
	void OnRspQryHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///历史对象状态指标查询应答
	void OnRtnHistoryObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///前置响应信息查询应答
	void OnRspQryFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///前置响应信息查询应答
	void OnRtnFrontInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户登录应答
	void OnRspQrySysUserLoginTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户登出应答
	void OnRspQrySysUserLogoutTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///用户修改密码应答
	void OnRspQrySysUserPasswordUpdateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///注册用户应答
	void OnRspQrySysUserRegisterTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///删除用户应答
	void OnRspQrySysUserDeleteTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员初始化应答
	void OnRspQryParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员初始化应答
	void OnRtnParticipantInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///座席初始化应答
	void OnRspQryUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///座席初始化应答
	void OnRtnUserInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户初始化应答
	void OnRspQryClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///客户初始化应答
	void OnRtnClientInitTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易日志查询应答
	void OnRspQryTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易日志查询应答
	void OnRtnTradeLogTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统登录信息
	void OnRspQryTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统登录信息
	void OnRtnTradeUserLoginInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员交易查询应答
	void OnRspQryPartTradeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易峰值查询应答
	void OnRspQryTradepeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRtnUpdateSysConfigTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRtnSysUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryCpuInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryMemInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///
	void OnRspQryHistoryNetworkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统在线用户应答
	void OnRspQryMonitorOnlineUser(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置统计应答
	void OnRspQryFrontStat(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控系统时钟同步
	void OnRtnSysTimeSyncTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据中心切换通知
	void OnRtnDataCenterChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///历史峰值查询应答
	void OnRspQryHistoryTradePeakTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志事件查询应答
	void OnRspQrySyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///日志事件应答
	void OnRtnSyslogEventTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Web应用信息
	void OnRspQryWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///Web应用信息
	void OnRtnWebAppInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用servlet信息
	void OnRspQryServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用servlet信息
	void OnRtnServletInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件信息
	void OnRspQryFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件信息
	void OnRtnFileInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用会话信息
	void OnRspQrySessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应用会话信息
	void OnRtnSessionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC信息
	void OnRspQryJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///JDBC信息
	void OnRtnJDBCInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///线程信息
	void OnRspQryThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///线程信息
	void OnRtnThreadInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///虚拟机信息
	void OnRspQryVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///虚拟机信息
	void OnRtnVMInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统属性信息
	void OnRspQryPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统属性信息
	void OnRtnPropertyInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内存池信息
	void OnRspQryMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统内存池信息
	void OnRtnMemPoolInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件内容信息
	void OnRspQryFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件内容信息
	void OnRtnFileContentInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接信息
	void OnRspQryConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接信息
	void OnRtnConnectionInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接器信息
	void OnRspQryConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///连接器信息
	void OnRtnConnectorInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据库查询应答
	void OnRspQryDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///数据库查询应答
	void OnRtnDBQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用返回应答
	void OnRspQryGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用返回应答
	void OnRtnGeneralFieldTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件传输应答
	void OnRspQryGetFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警明细
	void OnRspQryWarningQueryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///告警激活变更
	void OnRtnWarningActiveChange(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用操作
	void OnRspQryGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///通用操作
	void OnRtnGeneralOperateTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备连接关系
	void OnRspQryNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备连接关系
	void OnRtnNetDeviceLinkedTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统登录信息
	void OnRspQryTradeUserLoginStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单响应信息
	void OnRspQryTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单响应信息
	void OnRtnTradeFrontOrderRttStatTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员席位交易状态
	void OnRspQryParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员席位交易状态
	void OnRtnParticTradeOrderStatesTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统路由信息
	void OnRspQryRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统路由信息
	void OnRtnRouterInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///磁盘I/O信息
	void OnRspQryDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///磁盘I/O信息
	void OnRtnDiskIOTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统状态信息
	void OnRspQryStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///系统状态信息
	void OnRtnStatInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单分布区间
	void OnRspQryTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///交易系统前置报单分布区间
	void OnRtnTradeOrderRttCutLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户信息
	void OnRspQryClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员客户信息
	void OnRtnClientInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答事件描述
	void OnRspQryEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅事件描述
	void OnRtnEventDescriptionTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答前置唯一ID信息
	void OnRspQryFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅前置唯一ID信息
	void OnRtnFrontUniqueIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员线路地址变更回应
	void OnRspQryNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅会员线路地址变更信息
	void OnRtnNetPartyLinkAddrChangeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///应答已删除会员列表信息
	void OnRspQryNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅已删除会员列表信息
	void OnRtnNetDelPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回网络性能排序
	void OnRspQryPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅网络性能排序
	void OnRtnPerformanceTopTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回约状态切换数据
	void OnRspQryInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅约状态切换数据
	void OnRtnInstrumentStatusTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回合约交易节信息
	void OnRspQryCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅合约交易节信息
	void OnRtnCurrTradingSegmentAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络大区划分应答
	void OnRspQryNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络大区划分应答
	void OnRtnNetAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区应答
	void OnRspQryNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区应答
	void OnRtnNetSubAreaTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区IP应答
	void OnRspQryNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络子区IP应答
	void OnRtnNetSubAreaIPTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备
	void OnRspQryNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备
	void OnRtnNetDeviceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///网络设备探测请求应答
	void OnRspQryNetDeviceDetectTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///大楼
	void OnRspQryNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///大楼
	void OnRtnNetBuildingTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机房
	void OnRspQryNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机房
	void OnRtnNetRoomTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机柜
	void OnRspQryNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///机柜
	void OnRtnNetCabinetsTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OID
	void OnRspQryNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///OID
	void OnRtnNetOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///时间策略
	void OnRspQryNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///时间策略
	void OnRtnNetTimePolicyTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///采集任务
	void OnRspQryNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///采集任务
	void OnRtnNetGatherTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备变更
	void OnRspQryNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备变更
	void OnRtnNetDeviceChgTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备型号
	void OnRspQryNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备型号
	void OnRtnNetDeviceTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备类别
	void OnRspQryNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///常用设备类别
	void OnRtnNetDeviceCategoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备厂商
	void OnRspQryNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备厂商
	void OnRtnNetManufactoryTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备共同体
	void OnRspQryNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备共同体
	void OnRtnNetCommunityTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口类型
	void OnRspQryNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口类型
	void OnRtnNetPortTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员接入地点
	void OnRspQryNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员接入地点
	void OnRtnNetPartAccessSpotTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口
	void OnRspQryNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///端口
	void OnRtnNetInterfaceTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///GeneralOID
	void OnRspQryNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///GeneralOID
	void OnRtnNetGeneralOIDTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象类别
	void OnRspQryNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象类别
	void OnRtnNetMonitorTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///指标统表
	void OnRspQryNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///指标统表
	void OnRtnNetMonitorAttrScopeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控指标表
	void OnRspQryNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控指标表
	void OnRtnNetMonitorAttrTypeTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象指标表
	void OnRspQryNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控对象指标表
	void OnRtnNetMonitorObjectAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备对象组表
	void OnRspQryNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备对象组表
	void OnRtnNetMonitorDeviceGroupTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务信息表
	void OnRspQryNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务信息表
	void OnRtnNetMonitorTaskInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果表
	void OnRspQryNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果表
	void OnRtnNetMonitorTaskResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务对象集
	void OnRspQryNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务对象集
	void OnRtnNetMonitorTaskObjectSetTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路信息表
	void OnRspQryNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路信息表
	void OnRtnNetPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///监控动作指标对照表
	void OnRspQryNetMonitorActionAttrTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///模块
	void OnRspQryNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///模块
	void OnRtnNetModuleTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果状态表
	void OnRspQryNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果状态表
	void OnRtnNetMonitorTaskStatusResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备配置表
	void OnRspQryNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///设备配置表
	void OnRtnNetCfgFileTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果规则分析表
	void OnRspQryNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///任务结果规则分析表
	void OnRtnNetMonitorDeviceTaskTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件通用操作
	void OnRspQryFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///文件通用操作
	void OnRtnFileGeneralOperTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线表
	void OnRspQryNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线表
	void OnRtnNetBaseLineTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线结果表
	void OnRspQryNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///基线结果表
	void OnRtnNetBaseLineResultTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路状态信息表
	void OnRspQryNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///会员链路状态信息表
	void OnRtnNetPartyLinkStatusInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///本地ping结果
	void OnRspQryNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///本地ping结果
	void OnRtnNetLocalPingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///远程ping结果
	void OnRspQryNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///远程ping结果
	void OnRtnNetRomotePingResultInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回会员链路费用表
	void OnRspQryMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅会员链路费用表
	void OnRtnMemberLinkCostTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///返回非会员链路表信息
	void OnRspQryNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	
	///订阅非会员链路表信息
	void OnRtnNetNonPartyLinkInfoTopic(CFTDCPackage *pMessage, WORD nSequenceSeries);
	

};


#endif
