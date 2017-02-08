/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统风险监控系统
///@company 上海期货信息技术有限公司
///@file FtdcSysUserApi.h
///@brief 定义了客户端接口
///@history 
///20070227	zhangjie		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSUSERAPI_H)
#define _FTDCSYSUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcSysUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_SYSUSER_API_EXPORT
#define SYSUSER_API_EXPORT __declspec(dllexport)
#else
#define SYSUSER_API_EXPORT __declspec(dllimport)
#pragma comment(lib, "sysuserapi.lib")
#endif
#else
#define SYSUSER_API_EXPORT 
#endif

class CShfeFtdcSysUserSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	virtual void OnFrontConnected(){};
	
	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	virtual void OnFrontDisconnected(int nReason){};
		
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	virtual void OnHeartBeatWarning(int nTimeLapse){};
	

	///CPU应答
	virtual void OnRspQryTopCpuInfoTopic(CShfeFtdcRspQryTopCpuInfoField *pRspQryTopCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///CPU应答
	virtual void OnRtnTopCpuInfoTopic(CShfeFtdcRtnTopCpuInfoField *pRtnTopCpuInfo) {};

	///Mem应答
	virtual void OnRspQryTopMemInfoTopic(CShfeFtdcRspQryTopMemInfoField *pRspQryTopMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Mem应答
	virtual void OnRtnTopMemInfoTopic(CShfeFtdcRtnTopMemInfoField *pRtnTopMemInfo) {};

	///process应答
	virtual void OnRspQryTopProcessInfoTopic(CShfeFtdcRspQryTopProcessInfoField *pRspQryTopProcessInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///process应答
	virtual void OnRtnTopProcessInfoTopic(CShfeFtdcRtnTopProcessInfoField *pRtnTopProcessInfo) {};

	///filesystem应答
	virtual void OnRspQryFileSystemInfoTopic(CShfeFtdcRspQryFileSystemInfoField *pRspQryFileSystemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///filesystem应答
	virtual void OnRtnFileSystemInfoTopic(CShfeFtdcRtnFileSystemInfoField *pRtnFileSystemInfo) {};

	///network应答
	virtual void OnRspQryNetworkInfoTopic(CShfeFtdcRspQryNetworkInfoField *pRspQryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///network应答
	virtual void OnRtnNetworkInfoTopic(CShfeFtdcRtnNetworkInfoField *pRtnNetworkInfo) {};

	///获得监控对象信息应答
	virtual void OnRspQryMonitorObjectTopic(CShfeFtdcRspQryMonitorObjectField *pRspQryMonitorObject, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///获得监控对象信息应答
	virtual void OnRtnMonitorObjectTopic(CShfeFtdcRtnMonitorObjectField *pRtnMonitorObject) {};

	///获得业务进程和主机的对应关系应答
	virtual void OnRspQryObjectRationalTopic(CShfeFtdcRspQryObjectRationalField *pRspQryObjectRational, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///获得业务进程和主机的对应关系应答
	virtual void OnRtnObjectRationalTopic(CShfeFtdcRtnObjectRationalField *pRtnObjectRational) {};

	///日志文件内容应答
	virtual void OnRspQrySyslogInfoTopic(CShfeFtdcRspQrySyslogInfoField *pRspQrySyslogInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///日志文件内容应答
	virtual void OnRtnSyslogInfoTopic(CShfeFtdcRtnSyslogInfoField *pRtnSyslogInfo) {};

	///监控内容订阅应答
	virtual void OnRspQrySubscriberTopic(CShfeFtdcRspQrySubscriberField *pRspQrySubscriber, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对象关系查询应答
	virtual void OnRspQryOidRelationTopic(CShfeFtdcRspQryOidRelationField *pRspQryOidRelation, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对象关系查询应答
	virtual void OnRtnOidRelationTopic(CShfeFtdcRtnOidRelationField *pRtnOidRelation) {};

	///用户信息查询请求应答
	virtual void OnRspQryUserInfoTopic(CShfeFtdcRspQryUserInfoField *pRspQryUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户信息查询请求应答
	virtual void OnRtnUserInfoTopic(CShfeFtdcRtnUserInfoField *pRtnUserInfo) {};

	///在线用户信息查询请求应答
	virtual void OnRspQryOnlineUserInfoTopic(CShfeFtdcRspQryOnlineUserInfoField *pRspQryOnlineUserInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///在线用户信息查询请求应答
	virtual void OnRtnOnlineUserInfoTopic(CShfeFtdcRtnOnlineUserInfoField *pRtnOnlineUserInfo) {};

	///告警事件查询请求应答
	virtual void OnRspQryWarningEventTopic(CShfeFtdcRspQryWarningEventField *pRspQryWarningEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警事件查询请求应答
	virtual void OnRtnWarningEventTopic(CShfeFtdcRtnWarningEventField *pRtnWarningEvent) {};

	///对象状态指标查询应答
	virtual void OnRspQryObjectAttrTopic(CShfeFtdcRspQryObjectAttrField *pRspQryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///对象状态指标查询应答
	virtual void OnRtnObjectAttrTopic(CShfeFtdcRtnObjectAttrField *pRtnObjectAttr) {};

	///无效报单查询应答
	virtual void OnRspQryInvalidateOrderTopic(CShfeFtdcRspQryInvalidateOrderField *pRspQryInvalidateOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///无效报单查询应答
	virtual void OnRtnInvalidateOrderTopic(CShfeFtdcRtnInvalidateOrderField *pRtnInvalidateOrder) {};

	///报单状态查询应答
	virtual void OnRspQryOrderStatusTopic(CShfeFtdcRspQryOrderStatusField *pRspQryOrderStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单状态查询应答
	virtual void OnRtnOrderStatusTopic(CShfeFtdcRtnOrderStatusField *pRtnOrderStatus) {};

	///报单成交查询应答
	virtual void OnRspQryBargainOrderTopic(CShfeFtdcRspQryBargainOrderField *pRspQryBargainOrder, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///报单成交查询应答
	virtual void OnRtnBargainOrderTopic(CShfeFtdcRtnBargainOrderField *pRtnBargainOrder) {};

	///合约基本属性查询应答
	virtual void OnRspQryInstPropertyTopic(CShfeFtdcRspQryInstPropertyField *pRspQryInstProperty, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约基本属性查询应答
	virtual void OnRtnInstPropertyTopic(CShfeFtdcRtnInstPropertyField *pRtnInstProperty) {};

	///合约保证金率查询应答
	virtual void OnRspQryMarginRateTopic(CShfeFtdcRspQryMarginRateField *pRspQryMarginRate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约保证金率查询应答
	virtual void OnRtnMarginRateTopic(CShfeFtdcRtnMarginRateField *pRtnMarginRate) {};

	///合约涨跌停板查询应答
	virtual void OnRspQryPriceLimitTopic(CShfeFtdcRspQryPriceLimitField *pRspQryPriceLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///合约涨跌停板查询应答
	virtual void OnRtnPriceLimitTopic(CShfeFtdcRtnPriceLimitField *pRtnPriceLimit) {};

	///会员限仓查询应答
	virtual void OnRspQryPartPosiLimitTopic(CShfeFtdcRspQryPartPosiLimitField *pRspQryPartPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员限仓查询应答
	virtual void OnRtnPartPosiLimitTopic(CShfeFtdcRtnPartPosiLimitField *pRtnPartPosiLimit) {};

	///客户限仓查询应答
	virtual void OnRspQryClientPosiLimitTopic(CShfeFtdcRspQryClientPosiLimitField *pRspQryClientPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户限仓查询应答
	virtual void OnRtnClientPosiLimitTopic(CShfeFtdcRtnClientPosiLimitField *pRtnClientPosiLimit) {};

	///特殊客户限仓查询应答
	virtual void OnRspQrySpecialPosiLimitTopic(CShfeFtdcRspQrySpecialPosiLimitField *pRspQrySpecialPosiLimit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///特殊客户限仓查询应答
	virtual void OnRtnSpecialPosiLimitTopic(CShfeFtdcRtnSpecialPosiLimitField *pRtnSpecialPosiLimit) {};

	///账户出入金查询应答
	virtual void OnRspQryTransactionChgTopic(CShfeFtdcRspQryTransactionChgField *pRspQryTransactionChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///账户出入金查询应答
	virtual void OnRtnTransactionChgTopic(CShfeFtdcRtnTransactionChgField *pRtnTransactionChg) {};

	///客户数据变动查询应答
	virtual void OnRspQryClientChgTopic(CShfeFtdcRspQryClientChgField *pRspQryClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户数据变动查询应答
	virtual void OnRtnClientChgTopic(CShfeFtdcRtnClientChgField *pRtnClientChg) {};

	///会员客户对照变动查询应答
	virtual void OnRspQryPartClientChgTopic(CShfeFtdcRspQryPartClientChgField *pRspQryPartClientChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员客户对照变动查询应答
	virtual void OnRtnPartClientChgTopic(CShfeFtdcRtnPartClientChgField *pRtnPartClientChg) {};

	///限仓数据变动查询应答
	virtual void OnRspQryPosiLimitChgTopic(CShfeFtdcRspQryPosiLimitChgField *pRspQryPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///限仓数据变动查询应答
	virtual void OnRtnPosiLimitChgTopic(CShfeFtdcRtnPosiLimitChgField *pRtnPosiLimitChg) {};

	///保值额度变动查询应答
	virtual void OnRspQryHedgeDetailChgTopic(CShfeFtdcRspQryHedgeDetailChgField *pRspQryHedgeDetailChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///保值额度变动查询应答
	virtual void OnRtnHedgeDetailChgTopic(CShfeFtdcRtnHedgeDetailChgField *pRtnHedgeDetailChg) {};

	///会员变动查询应答
	virtual void OnRspQryParticipantChgTopic(CShfeFtdcRspQryParticipantChgField *pRspQryParticipantChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员变动查询应答
	virtual void OnRtnParticipantChgTopic(CShfeFtdcRtnParticipantChgField *pRtnParticipantChg) {};

	///保证金率变动查询应答
	virtual void OnRspQryMarginRateChgTopic(CShfeFtdcRspQryMarginRateChgField *pRspQryMarginRateChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///保证金率变动查询应答
	virtual void OnRtnMarginRateChgTopic(CShfeFtdcRtnMarginRateChgField *pRtnMarginRateChg) {};

	///IP地址变动查询应答
	virtual void OnRspQryUserIpChgTopic(CShfeFtdcRspQryUserIpChgField *pRspQryUserIpChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///IP地址变动查询应答
	virtual void OnRtnUserIpChgTopic(CShfeFtdcRtnUserIpChgField *pRtnUserIpChg) {};

	///限仓数据变动查询应答
	virtual void OnRspQryClientPosiLimitChgTopic(CShfeFtdcRspQryClientPosiLimitChgField *pRspQryClientPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///限仓数据变动查询应答
	virtual void OnRtnClientPosiLimitChgTopic(CShfeFtdcRtnClientPosiLimitChgField *pRtnClientPosiLimitChg) {};

	///限仓数据变动查询应答
	virtual void OnRspQrySpecPosiLimitChgTopic(CShfeFtdcRspQrySpecPosiLimitChgField *pRspQrySpecPosiLimitChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///限仓数据变动查询应答
	virtual void OnRtnSpecPosiLimitChgTopic(CShfeFtdcRtnSpecPosiLimitChgField *pRtnSpecPosiLimitChg) {};

	///历史对象状态指标查询应答
	virtual void OnRspQryHistoryObjectAttrTopic(CShfeFtdcRspQryHistoryObjectAttrField *pRspQryHistoryObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///历史对象状态指标查询应答
	virtual void OnRtnHistoryObjectAttrTopic(CShfeFtdcRtnHistoryObjectAttrField *pRtnHistoryObjectAttr) {};

	///前置响应信息查询应答
	virtual void OnRspQryFrontInfoTopic(CShfeFtdcRspQryFrontInfoField *pRspQryFrontInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///前置响应信息查询应答
	virtual void OnRtnFrontInfoTopic(CShfeFtdcRtnFrontInfoField *pRtnFrontInfo) {};

	///用户登录应答
	virtual void OnRspQrySysUserLoginTopic(CShfeFtdcRspQrySysUserLoginField *pRspQrySysUserLogin, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户登出应答
	virtual void OnRspQrySysUserLogoutTopic(CShfeFtdcRspQrySysUserLogoutField *pRspQrySysUserLogout, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///用户修改密码应答
	virtual void OnRspQrySysUserPasswordUpdateTopic(CShfeFtdcRspQrySysUserPasswordUpdateField *pRspQrySysUserPasswordUpdate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///注册用户应答
	virtual void OnRspQrySysUserRegisterTopic(CShfeFtdcRspQrySysUserRegisterField *pRspQrySysUserRegister, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///删除用户应答
	virtual void OnRspQrySysUserDeleteTopic(CShfeFtdcRspQrySysUserDeleteField *pRspQrySysUserDelete, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员初始化应答
	virtual void OnRspQryParticipantInitTopic(CShfeFtdcRspQryParticipantInitField *pRspQryParticipantInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员初始化应答
	virtual void OnRtnParticipantInitTopic(CShfeFtdcRtnParticipantInitField *pRtnParticipantInit) {};

	///座席初始化应答
	virtual void OnRspQryUserInitTopic(CShfeFtdcRspQryUserInitField *pRspQryUserInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///座席初始化应答
	virtual void OnRtnUserInitTopic(CShfeFtdcRtnUserInitField *pRtnUserInit) {};

	///客户初始化应答
	virtual void OnRspQryClientInitTopic(CShfeFtdcRspQryClientInitField *pRspQryClientInit, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///客户初始化应答
	virtual void OnRtnClientInitTopic(CShfeFtdcRtnClientInitField *pRtnClientInit) {};

	///交易日志查询应答
	virtual void OnRspQryTradeLogTopic(CShfeFtdcRspQryTradeLogField *pRspQryTradeLog, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易日志查询应答
	virtual void OnRtnTradeLogTopic(CShfeFtdcRtnTradeLogField *pRtnTradeLog) {};

	///交易系统登录信息
	virtual void OnRspQryTradeUserLoginInfoTopic(CShfeFtdcRspQryTradeUserLoginInfoField *pRspQryTradeUserLoginInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统登录信息
	virtual void OnRtnTradeUserLoginInfoTopic(CShfeFtdcRtnTradeUserLoginInfoField *pRtnTradeUserLoginInfo) {};

	///会员交易查询应答
	virtual void OnRspQryPartTradeTopic(CShfeFtdcRspQryPartTradeField *pRspQryPartTrade, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易峰值查询应答
	virtual void OnRspQryTradepeakTopic(CShfeFtdcRspQryTradepeakField *pRspQryTradepeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///
	virtual void OnRtnUpdateSysConfigTopic(CShfeFtdcRtnUpdateSysConfigField *pRtnUpdateSysConfig) {};

	///
	virtual void OnRtnSysUser(CShfeFtdcRtnSysUserField *pRtnSysUser) {};

	///
	virtual void OnRspQryHistoryCpuInfoTopic(CShfeFtdcRspQryHistoryCpuInfoField *pRspQryHistoryCpuInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///
	virtual void OnRspQryHistoryMemInfoTopic(CShfeFtdcRspQryHistoryMemInfoField *pRspQryHistoryMemInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///
	virtual void OnRspQryHistoryNetworkInfoTopic(CShfeFtdcRspQryHistoryNetworkInfoField *pRspQryHistoryNetworkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控系统在线用户应答
	virtual void OnRspQryMonitorOnlineUser(CShfeFtdcRspQryMonitorOnlineUserField *pRspQryMonitorOnlineUser, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统前置统计应答
	virtual void OnRspQryFrontStat(CShfeFtdcRspQryFrontStatField *pRspQryFrontStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控系统时钟同步
	virtual void OnRtnSysTimeSyncTopic(CShfeFtdcRtnSysTimeSyncField *pRtnSysTimeSync) {};

	///数据中心切换通知
	virtual void OnRtnDataCenterChgTopic(CShfeFtdcRtnDataCenterChgField *pRtnDataCenterChg) {};

	///历史峰值查询应答
	virtual void OnRspQryHistoryTradePeakTopic(CShfeFtdcRspQryHistoryTradePeakField *pRspQryHistoryTradePeak, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///日志事件查询应答
	virtual void OnRspQrySyslogEventTopic(CShfeFtdcRspQrySyslogEventField *pRspQrySyslogEvent, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///日志事件应答
	virtual void OnRtnSyslogEventTopic(CShfeFtdcRtnSyslogEventField *pRtnSyslogEvent) {};

	///Web应用信息
	virtual void OnRspQryWebAppInfoTopic(CShfeFtdcRspQryWebAppInfoField *pRspQryWebAppInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Web应用信息
	virtual void OnRtnWebAppInfoTopic(CShfeFtdcRtnWebAppInfoField *pRtnWebAppInfo) {};

	///应用servlet信息
	virtual void OnRspQryServletInfoTopic(CShfeFtdcRspQryServletInfoField *pRspQryServletInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///应用servlet信息
	virtual void OnRtnServletInfoTopic(CShfeFtdcRtnServletInfoField *pRtnServletInfo) {};

	///文件信息
	virtual void OnRspQryFileInfoTopic(CShfeFtdcRspQryFileInfoField *pRspQryFileInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件信息
	virtual void OnRtnFileInfoTopic(CShfeFtdcRtnFileInfoField *pRtnFileInfo) {};

	///应用会话信息
	virtual void OnRspQrySessionInfoTopic(CShfeFtdcRspQrySessionInfoField *pRspQrySessionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///应用会话信息
	virtual void OnRtnSessionInfoTopic(CShfeFtdcRtnSessionInfoField *pRtnSessionInfo) {};

	///JDBC信息
	virtual void OnRspQryJDBCInfoTopic(CShfeFtdcRspQryJDBCInfoField *pRspQryJDBCInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///JDBC信息
	virtual void OnRtnJDBCInfoTopic(CShfeFtdcRtnJDBCInfoField *pRtnJDBCInfo) {};

	///线程信息
	virtual void OnRspQryThreadInfoTopic(CShfeFtdcRspQryThreadInfoField *pRspQryThreadInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///线程信息
	virtual void OnRtnThreadInfoTopic(CShfeFtdcRtnThreadInfoField *pRtnThreadInfo) {};

	///虚拟机信息
	virtual void OnRspQryVMInfoTopic(CShfeFtdcRspQryVMInfoField *pRspQryVMInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///虚拟机信息
	virtual void OnRtnVMInfoTopic(CShfeFtdcRtnVMInfoField *pRtnVMInfo) {};

	///系统属性信息
	virtual void OnRspQryPropertyInfoTopic(CShfeFtdcRspQryPropertyInfoField *pRspQryPropertyInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统属性信息
	virtual void OnRtnPropertyInfoTopic(CShfeFtdcRtnPropertyInfoField *pRtnPropertyInfo) {};

	///系统内存池信息
	virtual void OnRspQryMemPoolInfoTopic(CShfeFtdcRspQryMemPoolInfoField *pRspQryMemPoolInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统内存池信息
	virtual void OnRtnMemPoolInfoTopic(CShfeFtdcRtnMemPoolInfoField *pRtnMemPoolInfo) {};

	///文件内容信息
	virtual void OnRspQryFileContentInfoTopic(CShfeFtdcRspQryFileContentInfoField *pRspQryFileContentInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件内容信息
	virtual void OnRtnFileContentInfoTopic(CShfeFtdcRtnFileContentInfoField *pRtnFileContentInfo) {};

	///连接信息
	virtual void OnRspQryConnectionInfoTopic(CShfeFtdcRspQryConnectionInfoField *pRspQryConnectionInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///连接信息
	virtual void OnRtnConnectionInfoTopic(CShfeFtdcRtnConnectionInfoField *pRtnConnectionInfo) {};

	///连接器信息
	virtual void OnRspQryConnectorInfoTopic(CShfeFtdcRspQryConnectorInfoField *pRspQryConnectorInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///连接器信息
	virtual void OnRtnConnectorInfoTopic(CShfeFtdcRtnConnectorInfoField *pRtnConnectorInfo) {};

	///数据库查询应答
	virtual void OnRspQryDBQueryTopic(CShfeFtdcRspQryDBQueryField *pRspQryDBQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///数据库查询应答
	virtual void OnRtnDBQueryTopic(CShfeFtdcRtnDBQueryField *pRtnDBQuery) {};

	///通用返回应答
	virtual void OnRspQryGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通用返回应答
	virtual void OnRtnGeneralFieldTopic(CShfeFtdcSysGeneralFieldField *pSysGeneralField) {};

	///文件传输应答
	virtual void OnRspQryGetFileTopic(CShfeFtdcRspQryGetFileField *pRspQryGetFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警明细
	virtual void OnRspQryWarningQueryTopic(CShfeFtdcRspQryWarningQueryField *pRspQryWarningQuery, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///告警激活变更
	virtual void OnRtnWarningActiveChange(CShfeFtdcRtnWarningActiveChangeField *pRtnWarningActiveChange) {};

	///通用操作
	virtual void OnRspQryGeneralOperateTopic(CShfeFtdcRspQryGeneralOperateField *pRspQryGeneralOperate, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///通用操作
	virtual void OnRtnGeneralOperateTopic(CShfeFtdcRtnGeneralOperateField *pRtnGeneralOperate) {};

	///网络设备连接关系
	virtual void OnRspQryNetDeviceLinkedTopic(CShfeFtdcRspQryNetDeviceLinkedField *pRspQryNetDeviceLinked, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络设备连接关系
	virtual void OnRtnNetDeviceLinkedTopic(CShfeFtdcRtnNetDeviceLinkedField *pRtnNetDeviceLinked) {};

	///交易系统登录信息
	virtual void OnRspQryTradeUserLoginStatTopic(CShfeFtdcRspQryTradeUserLoginStatField *pRspQryTradeUserLoginStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统前置报单响应信息
	virtual void OnRspQryTradeFrontOrderRttStatTopic(CShfeFtdcRspQryTradeFrontOrderRttStatField *pRspQryTradeFrontOrderRttStat, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统前置报单响应信息
	virtual void OnRtnTradeFrontOrderRttStatTopic(CShfeFtdcRtnTradeFrontOrderRttStatField *pRtnTradeFrontOrderRttStat) {};

	///会员席位交易状态
	virtual void OnRspQryParticTradeOrderStatesTopic(CShfeFtdcRspQryParticTradeOrderStatesField *pRspQryParticTradeOrderStates, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员席位交易状态
	virtual void OnRtnParticTradeOrderStatesTopic(CShfeFtdcRtnParticTradeOrderStatesField *pRtnParticTradeOrderStates) {};

	///系统路由信息
	virtual void OnRspQryRouterInfoTopic(CShfeFtdcRspQryRouterInfoField *pRspQryRouterInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统路由信息
	virtual void OnRtnRouterInfoTopic(CShfeFtdcRtnRouterInfoField *pRtnRouterInfo) {};

	///磁盘I/O信息
	virtual void OnRspQryDiskIOTopic(CShfeFtdcRspQryDiskIOField *pRspQryDiskIO, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///磁盘I/O信息
	virtual void OnRtnDiskIOTopic(CShfeFtdcRtnDiskIOField *pRtnDiskIO) {};

	///系统状态信息
	virtual void OnRspQryStatInfoTopic(CShfeFtdcRspQryStatInfoField *pRspQryStatInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///系统状态信息
	virtual void OnRtnStatInfoTopic(CShfeFtdcRtnStatInfoField *pRtnStatInfo) {};

	///交易系统前置报单分布区间
	virtual void OnRspQryTradeOrderRttCutLineTopic(CShfeFtdcRspQryTradeOrderRttCutLineField *pRspQryTradeOrderRttCutLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///交易系统前置报单分布区间
	virtual void OnRtnTradeOrderRttCutLineTopic(CShfeFtdcRtnTradeOrderRttCutLineField *pRtnTradeOrderRttCutLine) {};

	///会员客户信息
	virtual void OnRspQryClientInfoTopic(CShfeFtdcRspQryClientInfoField *pRspQryClientInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员客户信息
	virtual void OnRtnClientInfoTopic(CShfeFtdcRtnClientInfoField *pRtnClientInfo) {};

	///应答事件描述
	virtual void OnRspQryEventDescriptionTopic(CShfeFtdcRspQryEventDescriptionField *pRspQryEventDescription, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅事件描述
	virtual void OnRtnEventDescriptionTopic(CShfeFtdcRtnEventDescriptionField *pRtnEventDescription) {};

	///应答前置唯一ID信息
	virtual void OnRspQryFrontUniqueIDTopic(CShfeFtdcRspQryFrontUniqueIDField *pRspQryFrontUniqueID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅前置唯一ID信息
	virtual void OnRtnFrontUniqueIDTopic(CShfeFtdcRtnFrontUniqueIDField *pRtnFrontUniqueID) {};

	///会员线路地址变更回应
	virtual void OnRspQryNetPartyLinkAddrChangeTopic(CShfeFtdcRspQryNetPartyLinkAddrChangeField *pRspQryNetPartyLinkAddrChange, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅会员线路地址变更信息
	virtual void OnRtnNetPartyLinkAddrChangeTopic(CShfeFtdcRtnNetPartyLinkAddrChangeField *pRtnNetPartyLinkAddrChange) {};

	///应答已删除会员列表信息
	virtual void OnRspQryNetDelPartyLinkInfoTopic(CShfeFtdcRspQryNetDelPartyLinkInfoField *pRspQryNetDelPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅已删除会员列表信息
	virtual void OnRtnNetDelPartyLinkInfoTopic(CShfeFtdcRtnNetDelPartyLinkInfoField *pRtnNetDelPartyLinkInfo) {};

	///返回网络性能排序
	virtual void OnRspQryPerformanceTopTopic(CShfeFtdcRspQryPerformanceTopField *pRspQryPerformanceTop, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅网络性能排序
	virtual void OnRtnPerformanceTopTopic(CShfeFtdcRtnPerformanceTopField *pRtnPerformanceTop) {};

	///返回约状态切换数据
	virtual void OnRspQryInstrumentStatusTopic(CShfeFtdcRspQryInstrumentStatusField *pRspQryInstrumentStatus, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅约状态切换数据
	virtual void OnRtnInstrumentStatusTopic(CShfeFtdcRtnInstrumentStatusField *pRtnInstrumentStatus) {};

	///返回合约交易节信息
	virtual void OnRspQryCurrTradingSegmentAttrTopic(CShfeFtdcRspQryCurrTradingSegmentAttrField *pRspQryCurrTradingSegmentAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅合约交易节信息
	virtual void OnRtnCurrTradingSegmentAttrTopic(CShfeFtdcRtnCurrTradingSegmentAttrField *pRtnCurrTradingSegmentAttr) {};

	///网络大区划分应答
	virtual void OnRspQryNetAreaTopic(CShfeFtdcRspQryNetAreaField *pRspQryNetArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络大区划分应答
	virtual void OnRtnNetAreaTopic(CShfeFtdcRtnNetAreaField *pRtnNetArea) {};

	///网络子区应答
	virtual void OnRspQryNetSubAreaTopic(CShfeFtdcRspQryNetSubAreaField *pRspQryNetSubArea, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络子区应答
	virtual void OnRtnNetSubAreaTopic(CShfeFtdcRtnNetSubAreaField *pRtnNetSubArea) {};

	///网络子区IP应答
	virtual void OnRspQryNetSubAreaIPTopic(CShfeFtdcRspQryNetSubAreaIPField *pRspQryNetSubAreaIP, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络子区IP应答
	virtual void OnRtnNetSubAreaIPTopic(CShfeFtdcRtnNetSubAreaIPField *pRtnNetSubAreaIP) {};

	///网络设备
	virtual void OnRspQryNetDeviceTopic(CShfeFtdcRspQryNetDeviceField *pRspQryNetDevice, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///网络设备
	virtual void OnRtnNetDeviceTopic(CShfeFtdcRtnNetDeviceField *pRtnNetDevice) {};

	///网络设备探测请求应答
	virtual void OnRspQryNetDeviceDetectTopic(CShfeFtdcRspQryNetDeviceDetectField *pRspQryNetDeviceDetect, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///大楼
	virtual void OnRspQryNetBuildingTopic(CShfeFtdcRspQryNetBuildingField *pRspQryNetBuilding, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///大楼
	virtual void OnRtnNetBuildingTopic(CShfeFtdcRtnNetBuildingField *pRtnNetBuilding) {};

	///机房
	virtual void OnRspQryNetRoomTopic(CShfeFtdcRspQryNetRoomField *pRspQryNetRoom, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///机房
	virtual void OnRtnNetRoomTopic(CShfeFtdcRtnNetRoomField *pRtnNetRoom) {};

	///机柜
	virtual void OnRspQryNetCabinetsTopic(CShfeFtdcRspQryNetCabinetsField *pRspQryNetCabinets, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///机柜
	virtual void OnRtnNetCabinetsTopic(CShfeFtdcRtnNetCabinetsField *pRtnNetCabinets) {};

	///OID
	virtual void OnRspQryNetOIDTopic(CShfeFtdcRspQryNetOIDField *pRspQryNetOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///OID
	virtual void OnRtnNetOIDTopic(CShfeFtdcRtnNetOIDField *pRtnNetOID) {};

	///时间策略
	virtual void OnRspQryNetTimePolicyTopic(CShfeFtdcRspQryNetTimePolicyField *pRspQryNetTimePolicy, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///时间策略
	virtual void OnRtnNetTimePolicyTopic(CShfeFtdcRtnNetTimePolicyField *pRtnNetTimePolicy) {};

	///采集任务
	virtual void OnRspQryNetGatherTaskTopic(CShfeFtdcRspQryNetGatherTaskField *pRspQryNetGatherTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///采集任务
	virtual void OnRtnNetGatherTaskTopic(CShfeFtdcRtnNetGatherTaskField *pRtnNetGatherTask) {};

	///设备变更
	virtual void OnRspQryNetDeviceChgTopic(CShfeFtdcRspQryNetDeviceChgField *pRspQryNetDeviceChg, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备变更
	virtual void OnRtnNetDeviceChgTopic(CShfeFtdcRtnNetDeviceChgField *pRtnNetDeviceChg) {};

	///常用设备型号
	virtual void OnRspQryNetDeviceTypeTopic(CShfeFtdcRspQryNetDeviceTypeField *pRspQryNetDeviceType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///常用设备型号
	virtual void OnRtnNetDeviceTypeTopic(CShfeFtdcRtnNetDeviceTypeField *pRtnNetDeviceType) {};

	///常用设备类别
	virtual void OnRspQryNetDeviceCategoryTopic(CShfeFtdcRspQryNetDeviceCategoryField *pRspQryNetDeviceCategory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///常用设备类别
	virtual void OnRtnNetDeviceCategoryTopic(CShfeFtdcRtnNetDeviceCategoryField *pRtnNetDeviceCategory) {};

	///设备厂商
	virtual void OnRspQryNetManufactoryTopic(CShfeFtdcRspQryNetManufactoryField *pRspQryNetManufactory, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备厂商
	virtual void OnRtnNetManufactoryTopic(CShfeFtdcRtnNetManufactoryField *pRtnNetManufactory) {};

	///设备共同体
	virtual void OnRspQryNetCommunityTopic(CShfeFtdcRspQryNetCommunityField *pRspQryNetCommunity, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备共同体
	virtual void OnRtnNetCommunityTopic(CShfeFtdcRtnNetCommunityField *pRtnNetCommunity) {};

	///端口类型
	virtual void OnRspQryNetPortTypeTopic(CShfeFtdcRspQryNetPortTypeField *pRspQryNetPortType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///端口类型
	virtual void OnRtnNetPortTypeTopic(CShfeFtdcRtnNetPortTypeField *pRtnNetPortType) {};

	///会员接入地点
	virtual void OnRspQryNetPartAccessSpotTopic(CShfeFtdcRspQryNetPartAccessSpotField *pRspQryNetPartAccessSpot, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员接入地点
	virtual void OnRtnNetPartAccessSpotTopic(CShfeFtdcRtnNetPartAccessSpotField *pRtnNetPartAccessSpot) {};

	///端口
	virtual void OnRspQryNetInterfaceTopic(CShfeFtdcRspQryNetInterfaceField *pRspQryNetInterface, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///端口
	virtual void OnRtnNetInterfaceTopic(CShfeFtdcRtnNetInterfaceField *pRtnNetInterface) {};

	///GeneralOID
	virtual void OnRspQryNetGeneralOIDTopic(CShfeFtdcRspQryNetGeneralOIDField *pRspQryNetGeneralOID, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///GeneralOID
	virtual void OnRtnNetGeneralOIDTopic(CShfeFtdcRtnNetGeneralOIDField *pRtnNetGeneralOID) {};

	///监控对象类别
	virtual void OnRspQryNetMonitorTypeTopic(CShfeFtdcRspQryNetMonitorTypeField *pRspQryNetMonitorType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控对象类别
	virtual void OnRtnNetMonitorTypeTopic(CShfeFtdcRtnNetMonitorTypeField *pRtnNetMonitorType) {};

	///指标统表
	virtual void OnRspQryNetMonitorAttrScopeTopic(CShfeFtdcRspQryNetMonitorAttrScopeField *pRspQryNetMonitorAttrScope, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///指标统表
	virtual void OnRtnNetMonitorAttrScopeTopic(CShfeFtdcRtnNetMonitorAttrScopeField *pRtnNetMonitorAttrScope) {};

	///监控指标表
	virtual void OnRspQryNetMonitorAttrTypeTopic(CShfeFtdcRspQryNetMonitorAttrTypeField *pRspQryNetMonitorAttrType, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控指标表
	virtual void OnRtnNetMonitorAttrTypeTopic(CShfeFtdcRtnNetMonitorAttrTypeField *pRtnNetMonitorAttrType) {};

	///监控对象指标表
	virtual void OnRspQryNetMonitorObjectAttrTopic(CShfeFtdcRspQryNetMonitorObjectAttrField *pRspQryNetMonitorObjectAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///监控对象指标表
	virtual void OnRtnNetMonitorObjectAttrTopic(CShfeFtdcRtnNetMonitorObjectAttrField *pRtnNetMonitorObjectAttr) {};

	///设备对象组表
	virtual void OnRspQryNetMonitorDeviceGroupTopic(CShfeFtdcRspQryNetMonitorDeviceGroupField *pRspQryNetMonitorDeviceGroup, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备对象组表
	virtual void OnRtnNetMonitorDeviceGroupTopic(CShfeFtdcRtnNetMonitorDeviceGroupField *pRtnNetMonitorDeviceGroup) {};

	///任务信息表
	virtual void OnRspQryNetMonitorTaskInfoTopic(CShfeFtdcRspQryNetMonitorTaskInfoField *pRspQryNetMonitorTaskInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务信息表
	virtual void OnRtnNetMonitorTaskInfoTopic(CShfeFtdcRtnNetMonitorTaskInfoField *pRtnNetMonitorTaskInfo) {};

	///任务结果表
	virtual void OnRspQryNetMonitorTaskResultTopic(CShfeFtdcRspQryNetMonitorTaskResultField *pRspQryNetMonitorTaskResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务结果表
	virtual void OnRtnNetMonitorTaskResultTopic(CShfeFtdcRtnNetMonitorTaskResultField *pRtnNetMonitorTaskResult) {};

	///任务对象集
	virtual void OnRspQryNetMonitorTaskObjectSetTopic(CShfeFtdcRspQryNetMonitorTaskObjectSetField *pRspQryNetMonitorTaskObjectSet, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务对象集
	virtual void OnRtnNetMonitorTaskObjectSetTopic(CShfeFtdcRtnNetMonitorTaskObjectSetField *pRtnNetMonitorTaskObjectSet) {};

	///会员链路信息表
	virtual void OnRspQryNetPartyLinkInfoTopic(CShfeFtdcRspQryNetPartyLinkInfoField *pRspQryNetPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员链路信息表
	virtual void OnRtnNetPartyLinkInfoTopic(CShfeFtdcRtnNetPartyLinkInfoField *pRtnNetPartyLinkInfo) {};

	///监控动作指标对照表
	virtual void OnRspQryNetMonitorActionAttrTopic(CShfeFtdcRspQryNetMonitorActionAttrField *pRspQryNetMonitorActionAttr, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///模块
	virtual void OnRspQryNetModuleTopic(CShfeFtdcRspQryNetModuleField *pRspQryNetModule, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///模块
	virtual void OnRtnNetModuleTopic(CShfeFtdcRtnNetModuleField *pRtnNetModule) {};

	///任务结果状态表
	virtual void OnRspQryNetMonitorTaskStatusResultTopic(CShfeFtdcRspQryNetMonitorTaskStatusResultField *pRspQryNetMonitorTaskStatusResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务结果状态表
	virtual void OnRtnNetMonitorTaskStatusResultTopic(CShfeFtdcRtnNetMonitorTaskStatusResultField *pRtnNetMonitorTaskStatusResult) {};

	///设备配置表
	virtual void OnRspQryNetCfgFileTopic(CShfeFtdcRspQryNetCfgFileField *pRspQryNetCfgFile, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///设备配置表
	virtual void OnRtnNetCfgFileTopic(CShfeFtdcRtnNetCfgFileField *pRtnNetCfgFile) {};

	///任务结果规则分析表
	virtual void OnRspQryNetMonitorDeviceTaskTopic(CShfeFtdcRspQryNetMonitorDeviceTaskField *pRspQryNetMonitorDeviceTask, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///任务结果规则分析表
	virtual void OnRtnNetMonitorDeviceTaskTopic(CShfeFtdcRtnNetMonitorDeviceTaskField *pRtnNetMonitorDeviceTask) {};

	///文件通用操作
	virtual void OnRspQryFileGeneralOperTopic(CShfeFtdcRspQryFileGeneralOperField *pRspQryFileGeneralOper, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///文件通用操作
	virtual void OnRtnFileGeneralOperTopic(CShfeFtdcRtnFileGeneralOperField *pRtnFileGeneralOper) {};

	///基线表
	virtual void OnRspQryNetBaseLineTopic(CShfeFtdcRspQryNetBaseLineField *pRspQryNetBaseLine, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///基线表
	virtual void OnRtnNetBaseLineTopic(CShfeFtdcRtnNetBaseLineField *pRtnNetBaseLine) {};

	///基线结果表
	virtual void OnRspQryNetBaseLineResultTopic(CShfeFtdcRspQryNetBaseLineResultField *pRspQryNetBaseLineResult, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///基线结果表
	virtual void OnRtnNetBaseLineResultTopic(CShfeFtdcRtnNetBaseLineResultField *pRtnNetBaseLineResult) {};

	///会员链路状态信息表
	virtual void OnRspQryNetPartyLinkStatusInfoTopic(CShfeFtdcRspQryNetPartyLinkStatusInfoField *pRspQryNetPartyLinkStatusInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///会员链路状态信息表
	virtual void OnRtnNetPartyLinkStatusInfoTopic(CShfeFtdcRtnNetPartyLinkStatusInfoField *pRtnNetPartyLinkStatusInfo) {};

	///本地ping结果
	virtual void OnRspQryNetLocalPingResultInfoTopic(CShfeFtdcRspQryNetLocalPingResultInfoField *pRspQryNetLocalPingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///本地ping结果
	virtual void OnRtnNetLocalPingResultInfoTopic(CShfeFtdcRtnNetLocalPingResultInfoField *pRtnNetLocalPingResultInfo) {};

	///远程ping结果
	virtual void OnRspQryNetRomotePingResultInfoTopic(CShfeFtdcRspQryNetRomotePingResultInfoField *pRspQryNetRomotePingResultInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///远程ping结果
	virtual void OnRtnNetRomotePingResultInfoTopic(CShfeFtdcRtnNetRomotePingResultInfoField *pRtnNetRomotePingResultInfo) {};

	///返回会员链路费用表
	virtual void OnRspQryMemberLinkCostTopic(CShfeFtdcRspQryMemberLinkCostField *pRspQryMemberLinkCost, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅会员链路费用表
	virtual void OnRtnMemberLinkCostTopic(CShfeFtdcRtnMemberLinkCostField *pRtnMemberLinkCost) {};

	///返回非会员链路表信息
	virtual void OnRspQryNetNonPartyLinkInfoTopic(CShfeFtdcRspQryNetNonPartyLinkInfoField *pRspQryNetNonPartyLinkInfo, CShfeFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///订阅非会员链路表信息
	virtual void OnRtnNetNonPartyLinkInfoTopic(CShfeFtdcRtnNetNonPartyLinkInfoField *pRtnNetNonPartyLinkInfo) {};
};

class SYSUSER_API_EXPORT CShfeFtdcSysUserApi
{
public:
	///创建SysUserApi
	///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
	///@return 创建出的UserApi
	static CShfeFtdcSysUserApi *CreateFtdcSysUserApi(const char *pszFlowPath = "");
	
	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	virtual void Release() = 0;
	
	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	virtual void Init() = 0;
	
	///等待接口线程结束运行
	///@return 线程退出代码
	virtual int Join() = 0;
	
	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	virtual const char *GetTradingDay() = 0;
	
	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	virtual void RegisterSpi(CShfeFtdcSysUserSpi *pSpi) = 0;
	
	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        TERT_RESTART:从本交易日开始重传
	///        TERT_RESUME:从上次收到的续传
	///        TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	virtual void SubscribeMarketDataTopic(int nTopicID, TE_RESUME_TYPE nResumeType) = 0;
	
	///订阅会员实时资金状况。
	///@remark 该方法要在Init方法前调用。若不调用则不会收到数据。
	virtual void SubscribePartAccount(void) = 0;

	///用户登录请求
	virtual int ReqUserLogin(CShfeFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	

	///CPU查询
	virtual int ReqQryTopCpuInfoTopic(CShfeFtdcReqQryTopCpuInfoField *pReqQryTopCpuInfo, int nRequestID) = 0;

	///Mem查询
	virtual int ReqQryTopMemInfoTopic(CShfeFtdcReqQryTopMemInfoField *pReqQryTopMemInfo, int nRequestID) = 0;

	///process查询
	virtual int ReqQryTopProcessInfoTopic(CShfeFtdcReqQryTopProcessInfoField *pReqQryTopProcessInfo, int nRequestID) = 0;

	///filesystem查询
	virtual int ReqQryFileSystemInfoTopic(CShfeFtdcReqQryFileSystemInfoField *pReqQryFileSystemInfo, int nRequestID) = 0;

	///network查询
	virtual int ReqQryNetworkInfoTopic(CShfeFtdcReqQryNetworkInfoField *pReqQryNetworkInfo, int nRequestID) = 0;

	///主机环境信息查询
	virtual int ReqQryHostEnvTopic(CShfeFtdcReqQryHostEnvField *pReqQryHostEnv, int nRequestID) = 0;

	///获得监控对象信息查询
	virtual int ReqQryMonitorObjectTopic(CShfeFtdcReqQryMonitorObjectField *pReqQryMonitorObject, int nRequestID) = 0;

	///获得业务进程和主机的对应关系查询
	virtual int ReqQryObjectRationalTopic(CShfeFtdcReqQryObjectRationalField *pReqQryObjectRational, int nRequestID) = 0;

	///日志文件内容查询
	virtual int ReqQrySyslogInfoTopic(CShfeFtdcReqQrySyslogInfoField *pReqQrySyslogInfo, int nRequestID) = 0;

	///监控内容订阅请求
	virtual int ReqQrySubscriberTopic(CShfeFtdcReqQrySubscriberField *pReqQrySubscriber, int nRequestID) = 0;

	///对象关系查询
	virtual int ReqQryOidRelationTopic(CShfeFtdcReqQryOidRelationField *pReqQryOidRelation, int nRequestID) = 0;

	///用户信息查询请求
	virtual int ReqQryUserInfoTopic(CShfeFtdcReqQryUserInfoField *pReqQryUserInfo, int nRequestID) = 0;

	///在线用户信息查询请求
	virtual int ReqQryOnlineUserInfoTopic(CShfeFtdcReqQryOnlineUserInfoField *pReqQryOnlineUserInfo, int nRequestID) = 0;

	///告警事件查询请求
	virtual int ReqQryWarningEventTopic(CShfeFtdcReqQryWarningEventField *pReqQryWarningEvent, int nRequestID) = 0;

	///对象状态指标查询
	virtual int ReqQryObjectAttrTopic(CShfeFtdcReqQryObjectAttrField *pReqQryObjectAttr, int nRequestID) = 0;

	///无效报单查询
	virtual int ReqQryInvalidateOrderTopic(CShfeFtdcReqQryInvalidateOrderField *pReqQryInvalidateOrder, int nRequestID) = 0;

	///报单状态查询
	virtual int ReqQryOrderStatusTopic(CShfeFtdcReqQryOrderStatusField *pReqQryOrderStatus, int nRequestID) = 0;

	///报单成交查询
	virtual int ReqQryBargainOrderTopic(CShfeFtdcReqQryBargainOrderField *pReqQryBargainOrder, int nRequestID) = 0;

	///合约基本属性查询
	virtual int ReqQryInstPropertyTopic(CShfeFtdcReqQryInstPropertyField *pReqQryInstProperty, int nRequestID) = 0;

	///合约保证金率查询
	virtual int ReqQryMarginRateTopic(CShfeFtdcReqQryMarginRateField *pReqQryMarginRate, int nRequestID) = 0;

	///合约涨跌停板查询
	virtual int ReqQryPriceLimitTopic(CShfeFtdcReqQryPriceLimitField *pReqQryPriceLimit, int nRequestID) = 0;

	///会员限仓查询
	virtual int ReqQryPartPosiLimitTopic(CShfeFtdcReqQryPartPosiLimitField *pReqQryPartPosiLimit, int nRequestID) = 0;

	///客户限仓查询
	virtual int ReqQryClientPosiLimitTopic(CShfeFtdcReqQryClientPosiLimitField *pReqQryClientPosiLimit, int nRequestID) = 0;

	///特殊客户限仓查询
	virtual int ReqQrySpecialPosiLimitTopic(CShfeFtdcReqQrySpecialPosiLimitField *pReqQrySpecialPosiLimit, int nRequestID) = 0;

	///账户出入金查询
	virtual int ReqQryTransactionChgTopic(CShfeFtdcReqQryTransactionChgField *pReqQryTransactionChg, int nRequestID) = 0;

	///客户数据变动查询
	virtual int ReqQryClientChgTopic(CShfeFtdcReqQryClientChgField *pReqQryClientChg, int nRequestID) = 0;

	///会员客户对照变动查询
	virtual int ReqQryPartClientChgTopic(CShfeFtdcReqQryPartClientChgField *pReqQryPartClientChg, int nRequestID) = 0;

	///限仓数据变动查询
	virtual int ReqQryPosiLimitChgTopic(CShfeFtdcReqQryPosiLimitChgField *pReqQryPosiLimitChg, int nRequestID) = 0;

	///保值额度变动查询
	virtual int ReqQryHedgeDetailChgTopic(CShfeFtdcReqQryHedgeDetailChgField *pReqQryHedgeDetailChg, int nRequestID) = 0;

	///会员变动查询
	virtual int ReqQryParticipantChgTopic(CShfeFtdcReqQryParticipantChgField *pReqQryParticipantChg, int nRequestID) = 0;

	///保证金率变动查询
	virtual int ReqQryMarginRateChgTopic(CShfeFtdcReqQryMarginRateChgField *pReqQryMarginRateChg, int nRequestID) = 0;

	///IP地址变动查询
	virtual int ReqQryUserIpChgTopic(CShfeFtdcReqQryUserIpChgField *pReqQryUserIpChg, int nRequestID) = 0;

	///限仓数据变动查询
	virtual int ReqQryClientPosiLimitChgTopic(CShfeFtdcReqQryClientPosiLimitChgField *pReqQryClientPosiLimitChg, int nRequestID) = 0;

	///限仓数据变动查询
	virtual int ReqQrySpecPosiLimitChgTopic(CShfeFtdcReqQrySpecPosiLimitChgField *pReqQrySpecPosiLimitChg, int nRequestID) = 0;

	///历史对象状态指标查询
	virtual int ReqQryHistoryObjectAttrTopic(CShfeFtdcReqQryHistoryObjectAttrField *pReqQryHistoryObjectAttr, int nRequestID) = 0;

	///前置响应信息查询
	virtual int ReqQryFrontInfoTopic(CShfeFtdcReqQryFrontInfoField *pReqQryFrontInfo, int nRequestID) = 0;

	///用户登录
	virtual int ReqQrySysUserLoginTopic(CShfeFtdcReqQrySysUserLoginField *pReqQrySysUserLogin, int nRequestID) = 0;

	///用户登出
	virtual int ReqQrySysUserLogoutTopic(CShfeFtdcReqQrySysUserLogoutField *pReqQrySysUserLogout, int nRequestID) = 0;

	///用户修改密码
	virtual int ReqQrySysUserPasswordUpdateTopic(CShfeFtdcReqQrySysUserPasswordUpdateField *pReqQrySysUserPasswordUpdate, int nRequestID) = 0;

	///注册用户
	virtual int ReqQrySysUserRegisterTopic(CShfeFtdcReqQrySysUserRegisterField *pReqQrySysUserRegister, int nRequestID) = 0;

	///删除用户
	virtual int ReqQrySysUserDeleteTopic(CShfeFtdcReqQrySysUserDeleteField *pReqQrySysUserDelete, int nRequestID) = 0;

	///交易日志查询
	virtual int ReqQryTradeLogTopic(CShfeFtdcReqQryTradeLogField *pReqQryTradeLog, int nRequestID) = 0;

	///告警事件修改
	virtual int ReqQryWarningEventUpdateTopic(CShfeFtdcReqQryWarningEventUpdateField *pReqQryWarningEventUpdate, int nRequestID) = 0;

	///交易系统登录信息查询
	virtual int ReqQryTradeUserLoginInfoTopic(CShfeFtdcReqQryTradeUserLoginInfoField *pReqQryTradeUserLoginInfo, int nRequestID) = 0;

	///会员交易查询
	virtual int ReqQryPartTradeTopic(CShfeFtdcReqQryPartTradeField *pReqQryPartTrade, int nRequestID) = 0;

	///交易峰值查询
	virtual int ReqQryTradepeakTopic(CShfeFtdcReqQryTradepeakField *pReqQryTradepeak, int nRequestID) = 0;

	///管理平台初始化信息查询
	virtual int ReqQryParticipantInitTopic(CShfeFtdcReqQryParticipantInitField *pReqQryParticipantInit, int nRequestID) = 0;

	///管理平台初始化信息查询
	virtual int ReqQryUserInitTopic(CShfeFtdcReqQryUserInitField *pReqQryUserInit, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryCpuInfoTopic(CShfeFtdcReqQryHistoryCpuInfoField *pReqQryHistoryCpuInfo, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryMemInfoTopic(CShfeFtdcReqQryHistoryMemInfoField *pReqQryHistoryMemInfo, int nRequestID) = 0;

	///
	virtual int ReqQryHistoryNetworkInfoTopic(CShfeFtdcReqQryHistoryNetworkInfoField *pReqQryHistoryNetworkInfo, int nRequestID) = 0;

	///监控系统在线用户查询
	virtual int ReqQryMonitorOnlineUser(CShfeFtdcReqQryMonitorOnlineUserField *pReqQryMonitorOnlineUser, int nRequestID) = 0;

	///交易系统前置统计查询
	virtual int ReqQryFrontStat(CShfeFtdcReqQryFrontStatField *pReqQryFrontStat, int nRequestID) = 0;

	///历史峰值查询
	virtual int ReqQryHistoryTradePeakTopic(CShfeFtdcReqQryHistoryTradePeakField *pReqQryHistoryTradePeak, int nRequestID) = 0;

	///日志事件查询
	virtual int ReqQrySyslogEventTopic(CShfeFtdcReqQrySyslogEventField *pReqQrySyslogEvent, int nRequestID) = 0;

	///日志事件订阅请求
	virtual int ReqQrySyslogEventSubcriberTopic(CShfeFtdcReqQrySyslogEventSubcriberField *pReqQrySyslogEventSubcriber, int nRequestID) = 0;

	///tomcat信息查询
	virtual int ReqQryTomcatInfoTopic(CShfeFtdcReqQryTomcatInfoField *pReqQryTomcatInfo, int nRequestID) = 0;

	///数据库查询
	virtual int ReqQryDBQueryTopic(CShfeFtdcReqQryDBQueryField *pReqQryDBQuery, int nRequestID) = 0;

	///文件传输请求
	virtual int ReqQryGetFileTopic(CShfeFtdcReqQryGetFileField *pReqQryGetFile, int nRequestID) = 0;

	///日志事件修改请求
	virtual int ReqQrySyslogEventUpdateTopic(CShfeFtdcReqQrySyslogEventUpdateField *pReqQrySyslogEventUpdate, int nRequestID) = 0;

	///告警明细查询
	virtual int ReqQryWarningQueryTopic(CShfeFtdcReqQryWarningQueryField *pReqQryWarningQuery, int nRequestID) = 0;

	///网站访问查询
	virtual int ReqQryWebVisitTopic(CShfeFtdcReqQryWebVisitField *pReqQryWebVisit, int nRequestID) = 0;

	///告警激活变更
	virtual int ReqQryWarningActiveChange(CShfeFtdcReqQryWarningActiveChangeField *pReqQryWarningActiveChange, int nRequestID) = 0;

	///通用操作
	virtual int ReqQryGeneralOperateTopic(CShfeFtdcReqQryGeneralOperateField *pReqQryGeneralOperate, int nRequestID) = 0;

	///网络设备连接关系请求
	virtual int ReqQryNetDeviceLinkedTopic(CShfeFtdcReqQryNetDeviceLinkedField *pReqQryNetDeviceLinked, int nRequestID) = 0;

	///交易系统登录信息请求
	virtual int ReqQryTradeUserLoginStatTopic(CShfeFtdcReqQryTradeUserLoginStatField *pReqQryTradeUserLoginStat, int nRequestID) = 0;

	///交易系统前置报单响应信息
	virtual int ReqQryTradeFrontOrderRttStatTopic(CShfeFtdcReqQryTradeFrontOrderRttStatField *pReqQryTradeFrontOrderRttStat, int nRequestID) = 0;

	///会员席位交易状态
	virtual int ReqQryParticTradeOrderStatesTopic(CShfeFtdcReqQryParticTradeOrderStatesField *pReqQryParticTradeOrderStates, int nRequestID) = 0;

	///系统路由信息
	virtual int ReqQryRouterInfoTopic(CShfeFtdcReqQryRouterInfoField *pReqQryRouterInfo, int nRequestID) = 0;

	///磁盘I/O信息
	virtual int ReqQryDiskIOTopic(CShfeFtdcReqQryDiskIOField *pReqQryDiskIO, int nRequestID) = 0;

	///系统状态信息
	virtual int ReqQryStatInfoTopic(CShfeFtdcReqQryStatInfoField *pReqQryStatInfo, int nRequestID) = 0;

	///交易系统前置报单分布区间
	virtual int ReqQryTradeOrderRttCutLineTopic(CShfeFtdcReqQryTradeOrderRttCutLineField *pReqQryTradeOrderRttCutLine, int nRequestID) = 0;

	///会员客户信息
	virtual int ReqQryClientInfoTopic(CShfeFtdcReqQryClientInfoField *pReqQryClientInfo, int nRequestID) = 0;

	///请求事件描述
	virtual int ReqQryEventDescriptionTopic(CShfeFtdcReqQryEventDescriptionField *pReqQryEventDescription, int nRequestID) = 0;

	///订阅前置唯一ID信息
	virtual int ReqQryFrontUniqueIDTopic(CShfeFtdcReqQryFrontUniqueIDField *pReqQryFrontUniqueID, int nRequestID) = 0;

	///会员线路地址变更请求
	virtual int ReqQryNetPartyLinkAddrChangeTopic(CShfeFtdcReqQryNetPartyLinkAddrChangeField *pReqQryNetPartyLinkAddrChange, int nRequestID) = 0;

	///请求已删除会员列表信息
	virtual int ReqQryNetDelPartyLinkInfoTopic(CShfeFtdcReqQryNetDelPartyLinkInfoField *pReqQryNetDelPartyLinkInfo, int nRequestID) = 0;

	///请求网络性能排序
	virtual int ReqQryPerformanceTopTopic(CShfeFtdcReqQryPerformanceTopField *pReqQryPerformanceTop, int nRequestID) = 0;

	///请求约状态切换数据
	virtual int ReqQryInstrumentStatusTopic(CShfeFtdcReqQryInstrumentStatusField *pReqQryInstrumentStatus, int nRequestID) = 0;

	///请求合约交易节信息
	virtual int ReqQryCurrTradingSegmentAttrTopic(CShfeFtdcReqQryCurrTradingSegmentAttrField *pReqQryCurrTradingSegmentAttr, int nRequestID) = 0;

	///最新网络指标查询
	virtual int ReqQryRealTimeNetObjectAttrTopic(CShfeFtdcReqQryRealTimeNetObjectAttrField *pReqQryRealTimeNetObjectAttr, int nRequestID) = 0;

	///网络大区划分查询
	virtual int ReqQryNetAreaTopic(CShfeFtdcReqQryNetAreaField *pReqQryNetArea, int nRequestID) = 0;

	///网络子区查询
	virtual int ReqQryNetSubAreaTopic(CShfeFtdcReqQryNetSubAreaField *pReqQryNetSubArea, int nRequestID) = 0;

	///网络子区IP查询
	virtual int ReqQryNetSubAreaIPTopic(CShfeFtdcReqQryNetSubAreaIPField *pReqQryNetSubAreaIP, int nRequestID) = 0;

	///网络设备探测请求
	virtual int ReqQryNetDeviceDetectTopic(CShfeFtdcReqQryNetDeviceDetectField *pReqQryNetDeviceDetect, int nRequestID) = 0;

	///网络设备查询请求
	virtual int ReqQryNetDeviceRequestTopic(CShfeFtdcReqQryNetDeviceRequestField *pReqQryNetDeviceRequest, int nRequestID) = 0;

	///大楼查询
	virtual int ReqQryNetBuildingTopic(CShfeFtdcReqQryNetBuildingField *pReqQryNetBuilding, int nRequestID) = 0;

	///机房查询
	virtual int ReqQryNetRoomTopic(CShfeFtdcReqQryNetRoomField *pReqQryNetRoom, int nRequestID) = 0;

	///机柜查询
	virtual int ReqQryNetCabinetsTopic(CShfeFtdcReqQryNetCabinetsField *pReqQryNetCabinets, int nRequestID) = 0;

	///OID
	virtual int ReqQryNetOIDTopic(CShfeFtdcReqQryNetOIDField *pReqQryNetOID, int nRequestID) = 0;

	///时间策略
	virtual int ReqQryNetTimePolicyTopic(CShfeFtdcReqQryNetTimePolicyField *pReqQryNetTimePolicy, int nRequestID) = 0;

	///采集任务查询
	virtual int ReqQryNetGatherTaskTopic(CShfeFtdcReqQryNetGatherTaskField *pReqQryNetGatherTask, int nRequestID) = 0;

	///设备变更请求
	virtual int ReqQryNetDeviceChgTopic(CShfeFtdcReqQryNetDeviceChgField *pReqQryNetDeviceChg, int nRequestID) = 0;

	///常用设备型号请求
	virtual int ReqQryNetDeviceTypeTopic(CShfeFtdcReqQryNetDeviceTypeField *pReqQryNetDeviceType, int nRequestID) = 0;

	///常用设备类别请求
	virtual int ReqQryNetDeviceCategoryTopic(CShfeFtdcReqQryNetDeviceCategoryField *pReqQryNetDeviceCategory, int nRequestID) = 0;

	///设备厂商请求
	virtual int ReqQryNetManufactoryTopic(CShfeFtdcReqQryNetManufactoryField *pReqQryNetManufactory, int nRequestID) = 0;

	///设备共同体请求
	virtual int ReqQryNetCommunityTopic(CShfeFtdcReqQryNetCommunityField *pReqQryNetCommunity, int nRequestID) = 0;

	///端口类型请求
	virtual int ReqQryNetPortTypeTopic(CShfeFtdcReqQryNetPortTypeField *pReqQryNetPortType, int nRequestID) = 0;

	///会员接入地点请求
	virtual int ReqQryNetPartAccessSpotTopic(CShfeFtdcReqQryNetPartAccessSpotField *pReqQryNetPartAccessSpot, int nRequestID) = 0;

	///端口请求
	virtual int ReqQryNetInterfaceTopic(CShfeFtdcReqQryNetInterfaceField *pReqQryNetInterface, int nRequestID) = 0;

	///GeneralOID请求
	virtual int ReqQryNetGeneralOIDTopic(CShfeFtdcReqQryNetGeneralOIDField *pReqQryNetGeneralOID, int nRequestID) = 0;

	///监控对象类别
	virtual int ReqQryNetMonitorTypeTopic(CShfeFtdcReqQryNetMonitorTypeField *pReqQryNetMonitorType, int nRequestID) = 0;

	///指标统表
	virtual int ReqQryNetMonitorAttrScopeTopic(CShfeFtdcReqQryNetMonitorAttrScopeField *pReqQryNetMonitorAttrScope, int nRequestID) = 0;

	///监控指标表
	virtual int ReqQryNetMonitorAttrTypeTopic(CShfeFtdcReqQryNetMonitorAttrTypeField *pReqQryNetMonitorAttrType, int nRequestID) = 0;

	///监控对象指标表
	virtual int ReqQryNetMonitorObjectAttrTopic(CShfeFtdcReqQryNetMonitorObjectAttrField *pReqQryNetMonitorObjectAttr, int nRequestID) = 0;

	///设备对象组表
	virtual int ReqQryNetMonitorDeviceGroupTopic(CShfeFtdcReqQryNetMonitorDeviceGroupField *pReqQryNetMonitorDeviceGroup, int nRequestID) = 0;

	///任务信息表
	virtual int ReqQryNetMonitorTaskInfoTopic(CShfeFtdcReqQryNetMonitorTaskInfoField *pReqQryNetMonitorTaskInfo, int nRequestID) = 0;

	///任务结果表
	virtual int ReqQryNetMonitorTaskResultTopic(CShfeFtdcReqQryNetMonitorTaskResultField *pReqQryNetMonitorTaskResult, int nRequestID) = 0;

	///任务对象集
	virtual int ReqQryNetMonitorTaskObjectSetTopic(CShfeFtdcReqQryNetMonitorTaskObjectSetField *pReqQryNetMonitorTaskObjectSet, int nRequestID) = 0;

	///会员链路信息表
	virtual int ReqQryNetPartyLinkInfoTopic(CShfeFtdcReqQryNetPartyLinkInfoField *pReqQryNetPartyLinkInfo, int nRequestID) = 0;

	///监控动作指标对照表
	virtual int ReqQryNetMonitorActionAttrTopic(CShfeFtdcReqQryNetMonitorActionAttrField *pReqQryNetMonitorActionAttr, int nRequestID) = 0;

	///模块
	virtual int ReqQryNetModuleTopic(CShfeFtdcReqQryNetModuleField *pReqQryNetModule, int nRequestID) = 0;

	///任务结果状态表
	virtual int ReqQryNetMonitorTaskStatusResultTopic(CShfeFtdcReqQryNetMonitorTaskStatusResultField *pReqQryNetMonitorTaskStatusResult, int nRequestID) = 0;

	///设备配置表
	virtual int ReqQryNetCfgFileTopic(CShfeFtdcReqQryNetCfgFileField *pReqQryNetCfgFile, int nRequestID) = 0;

	///任务结果规则分析表
	virtual int ReqQryNetMonitorDeviceTaskTopic(CShfeFtdcReqQryNetMonitorDeviceTaskField *pReqQryNetMonitorDeviceTask, int nRequestID) = 0;

	///文件通用操作
	virtual int ReqQryFileGeneralOperTopic(CShfeFtdcReqQryFileGeneralOperField *pReqQryFileGeneralOper, int nRequestID) = 0;

	///基线表
	virtual int ReqQryNetBaseLineTopic(CShfeFtdcReqQryNetBaseLineField *pReqQryNetBaseLine, int nRequestID) = 0;

	///基线结果表
	virtual int ReqQryNetBaseLineResultTopic(CShfeFtdcReqQryNetBaseLineResultField *pReqQryNetBaseLineResult, int nRequestID) = 0;

	///会员链路状态信息表
	virtual int ReqQryNetPartyLinkStatusInfoTopic(CShfeFtdcReqQryNetPartyLinkStatusInfoField *pReqQryNetPartyLinkStatusInfo, int nRequestID) = 0;

	///本地ping结果
	virtual int ReqQryNetLocalPingResultInfoTopic(CShfeFtdcReqQryNetLocalPingResultInfoField *pReqQryNetLocalPingResultInfo, int nRequestID) = 0;

	///远程ping结果
	virtual int ReqQryNetRomotePingResultInfoTopic(CShfeFtdcReqQryNetRomotePingResultInfoField *pReqQryNetRomotePingResultInfo, int nRequestID) = 0;

	///请求非会员链路表信息
	virtual int ReqQryNetNonPartyLinkInfoTopic(CShfeFtdcReqQryNetNonPartyLinkInfoField *pReqQryNetNonPartyLinkInfo, int nRequestID) = 0;


protected:
	~CShfeFtdcSysUserApi(){};
};

#endif
