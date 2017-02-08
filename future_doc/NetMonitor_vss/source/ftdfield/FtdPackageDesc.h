// FtdPackageDesc.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(_FTDPACKAGEDESC_H)
#define _FTDPACKAGEDESC_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdData.h"
#include "FieldSet.h"


#define FTD_VERSION 4

const WORD TSS_DIALOG = 1;		//对话流
const WORD TSS_PRIVATE = 2;		//会员私有流
const WORD TSS_PUBLIC = 3;		//公共流
const WORD TSS_QUERY = 4;		//查询
const WORD TSS_USER = 5;		//交易员私有流


//错误应答
const DWORD FTD_TID_RspError=0x00000001;
//用户登录请求
const DWORD FTD_TID_ReqUserLogin=0x00001001;
//用户登录应答
const DWORD FTD_TID_RspUserLogin=0x00001002;
//用户退出请求
const DWORD FTD_TID_ReqUserLogout=0x00001003;
//用户退出应答
const DWORD FTD_TID_RspUserLogout=0x00001004;
//报单录入请求
const DWORD FTD_TID_ReqOrderInsert=0x00001005;
//报单录入应答
const DWORD FTD_TID_RspOrderInsert=0x00001006;
//报单操作请求
const DWORD FTD_TID_ReqOrderAction=0x00001007;
//报单操作应答
const DWORD FTD_TID_RspOrderAction=0x00001008;
//报价录入请求
const DWORD FTD_TID_ReqQuoteInsert=0x00001009;
//报价录入应答
const DWORD FTD_TID_RspQuoteInsert=0x0000100A;
//报价操作请求
const DWORD FTD_TID_ReqQuoteAction=0x0000100B;
//报价操作应答
const DWORD FTD_TID_RspQuoteAction=0x0000100C;
//OTC报单录入请求
const DWORD FTD_TID_ReqOTCOrderInsert=0x0000100D;
//OTC报单录入应答
const DWORD FTD_TID_RspOTCOrderInsert=0x0000100E;
//用户密码修改请求
const DWORD FTD_TID_ReqUserPasswordUpdate=0x0000100F;
//用户密码修改应答
const DWORD FTD_TID_RspUserPasswordUpdate=0x00001010;
//执行宣告录入请求
const DWORD FTD_TID_ReqExecOrderInsert=0x00001011;
//执行宣告录入应答
const DWORD FTD_TID_RspExecOrderInsert=0x00001012;
//执行宣告操作请求
const DWORD FTD_TID_ReqExecOrderAction=0x00001013;
//执行宣告操作应答
const DWORD FTD_TID_RspExecOrderAction=0x00001014;
//管理报单录入请求
const DWORD FTD_TID_ReqAdminOrderInsert=0x00001015;
//管理报单录入应答
const DWORD FTD_TID_RspAdminOrderInsert=0x00001016;
//非标组合报单录入请求
const DWORD FTD_TID_ReqCombOrderInsert=0x00001017;
//非标组合报单录入应答
const DWORD FTD_TID_RspCombOrderInsert=0x00001018;
//订阅主题请求
const DWORD FTD_TID_ReqSubscribeTopic=0x00001F01;
//订阅主题应答
const DWORD FTD_TID_RspSubscribeTopic=0x00001F02;
//交易所公告请求
const DWORD FTD_TID_ReqBulletin=0x00002005;
//交易所公告请求应答
const DWORD FTD_TID_RspBulletin=0x00002006;
//交易所信息请求
const DWORD FTD_TID_ReqInformation=0x00002805;
//交易所公告信息应答
const DWORD FTD_TID_RspInformation=0x00002806;
//合约交易状态改变请求
const DWORD FTD_TID_ReqInstrumentStatusUpdate=0x00002007;
//合约交易状态改变应答
const DWORD FTD_TID_RspInstrumentStatusUpdate=0x00002008;
//强制用户退出请求
const DWORD FTD_TID_ReqForceUserExit=0x0000200B;
//强制用户退出应答
const DWORD FTD_TID_RspForceUserExit=0x0000200C;
//用户会话删除请求
const DWORD FTD_TID_ReqForceUserLogout=0x0000200D;
//用户会话删除应答
const DWORD FTD_TID_RspForceUserLogout=0x0000200E;
//交易所数据同步状态改变请求
const DWORD FTD_TID_ReqExchangeDataSyncStatusUpdate=0x00002013;
//交易所数据同步状态改变应答
const DWORD FTD_TID_RspExchangeDataSyncStatusUpdate=0x00002014;
//结算组数据同步状态改变请求
const DWORD FTD_TID_ReqSGDataSyncStatusUpdate=0x00002015;
//结算组数据同步状态改变应答
const DWORD FTD_TID_RspSGDataSyncStatusUpdate=0x00002016;
//会员资金查询请求
const DWORD FTD_TID_ReqQryPartAccount=0x00004001;
//会员资金查询应答
const DWORD FTD_TID_RspQryPartAccount=0x00004002;
//报单查询请求
const DWORD FTD_TID_ReqQryOrder=0x00004003;
//报单查询应答
const DWORD FTD_TID_RspQryOrder=0x00004004;
//报价查询请求
const DWORD FTD_TID_ReqQryQuote=0x00004005;
//报价查询应答
const DWORD FTD_TID_RspQryQuote=0x00004006;
//成交单查询请求
const DWORD FTD_TID_ReqQryTrade=0x00004007;
//成交单查询应答
const DWORD FTD_TID_RspQryTrade=0x00004008;
//会员客户查询请求
const DWORD FTD_TID_ReqQryClient=0x00004009;
//会员客户查询应答
const DWORD FTD_TID_RspQryClient=0x0000400A;
//会员持仓查询请求
const DWORD FTD_TID_ReqQryPartPosition=0x0000400B;
//会员持仓查询应答
const DWORD FTD_TID_RspQryPartPosition=0x0000400C;
//客户持仓查询请求
const DWORD FTD_TID_ReqQryClientPosition=0x0000400D;
//客户持仓查询应答
const DWORD FTD_TID_RspQryClientPosition=0x0000400E;
//合约查询请求
const DWORD FTD_TID_ReqQryInstrument=0x0000400F;
//合约查询应答
const DWORD FTD_TID_RspQryInstrument=0x00004010;
//合约交易状态查询请求
const DWORD FTD_TID_ReqQryInstrumentStatus=0x00004011;
//合约交易状态查询应答
const DWORD FTD_TID_RspQryInstrumentStatus=0x00004012;
//结算组状态查询请求
const DWORD FTD_TID_ReqQrySGDataSyncStatus=0x00004013;
//结算组状态查询应答
const DWORD FTD_TID_RspQrySGDataSyncStatus=0x00004014;
//保值额度查询
const DWORD FTD_TID_ReqQryHedgeVolume=0x00004015;
//保值额度应答
const DWORD FTD_TID_RspQryHedgeVolume=0x00004016;
//信用限额查询请求
const DWORD FTD_TID_ReqQryCreditLimit=0x00004017;
//信用限额查询应答
const DWORD FTD_TID_RspQryCreditLimit=0x00004018;
//非标组合报单查询请求
const DWORD FTD_TID_ReqQryCombOrder=0x00004019;
//非标组合报单查询应答
const DWORD FTD_TID_RspQryCombOrder=0x0000401A;
//执行宣告查询请求
const DWORD FTD_TID_ReqQryExecOrder=0x00004020;
//执行宣告查询应答
const DWORD FTD_TID_RspQryExecOrder=0x00004021;
//普通行情查询请求
const DWORD FTD_TID_ReqQryMarketData=0x00004101;
//普通行情查询应答
const DWORD FTD_TID_RspQryMarketData=0x00004102;
//交易所公告查询请求
const DWORD FTD_TID_ReqQryBulletin=0x00004103;
//交易所公告查询请求应答
const DWORD FTD_TID_RspQryBulletin=0x00004104;
//主题查询请求
const DWORD FTD_TID_ReqQryTopic=0x00004201;
//主题查询应答
const DWORD FTD_TID_RspQryTopic=0x00004202;
//用户在线查询请求
const DWORD FTD_TID_ReqQryUserSession=0x000043D1;
//用户在线查询应答
const DWORD FTD_TID_RspQryUserSession=0x000043D2;
//用户查询请求
const DWORD FTD_TID_ReqQryUser=0x000043D3;
//用户查询应答
const DWORD FTD_TID_RspQryUser=0x000043D4;
//会员查询请求
const DWORD FTD_TID_ReqQryParticipant=0x000043D5;
//会员查询应答
const DWORD FTD_TID_RspQryParticipant=0x000043D6;
//合约价位查询
const DWORD FTD_TID_ReqQryMBLMarketData=0x000043E1;
//合约价位查询应答
const DWORD FTD_TID_RspQryMBLMarketData=0x000043E2;
//信息查询
const DWORD FTD_TID_ReqQryInformation=0x000043E3;
//信息查询应答
const DWORD FTD_TID_RspQryInformation=0x000043E4;
//成交回报
const DWORD FTD_TID_RtnTrade=0x00005001;
//报单回报
const DWORD FTD_TID_RtnOrder=0x00005002;
//执行宣告回报
const DWORD FTD_TID_RtnExecOrder=0x00005003;
//报价回报
const DWORD FTD_TID_RtnQuote=0x00005004;
//非标组合报单回报
const DWORD FTD_TID_RtnCombOrder=0x00005005;
//合约交易状态通知
const DWORD FTD_TID_RtnInstrumentStatus=0x00005011;
//增加合约通知
const DWORD FTD_TID_RtnInsInstrument=0x00005101;
//删除合约通知
const DWORD FTD_TID_RtnDelInstrument=0x00005102;
//增加合约单腿通知
const DWORD FTD_TID_RtnInsCombinationLeg=0x00005103;
//删除合约单腿通知
const DWORD FTD_TID_RtnDelCombinationLeg=0x00005104;
//别名定义通知
const DWORD FTD_TID_RtnAliasDefine=0x0000510A;
//数据流回退通知
const DWORD FTD_TID_RtnFlowMessageCancel=0x00005201;
//公告通知
const DWORD FTD_TID_RtnBulletin=0x00005801;
//普通行情通知
const DWORD FTD_TID_RtnMarketData=0x00005802;
//深度行情通知
const DWORD FTD_TID_RtnDepthMarketData=0x00005803;
//内部分发信息通知
const DWORD FTD_TID_IntlRtnDissemination=0x00005901;
//内部深度行情通知
const DWORD FTD_TID_IntlRtnDepthMarketData=0x00005902;
//管理报单通知
const DWORD FTD_TID_RtnAdminOrder=0x00005A01;
//报单录入错误回报
const DWORD FTD_TID_ErrRtnOrderInsert=0x00006081;
//报单操作错误回报
const DWORD FTD_TID_ErrRtnOrderAction=0x00006082;
//报价录入错误回报
const DWORD FTD_TID_ErrRtnQuoteInsert=0x00006083;
//报价操作错误回报
const DWORD FTD_TID_ErrRtnQuoteAction=0x00006084;
//执行宣告录入错误回报
const DWORD FTD_TID_ErrRtnExecOrderInsert=0x00006085;
//执行宣告操作错误回报
const DWORD FTD_TID_ErrRtnExecOrderAction=0x00006086;
//管理报单录入错误回报
const DWORD FTD_TID_ErrAdminOrderInsert=0x00006087;
//非标组合报单录入错误回报
const DWORD FTD_TID_ErrRtnCombOrderInsert=0x00006088;
//客户持仓查询请求
const DWORD FTD_TID_ReqQryClientPositionV1=0x0000400D;
//汇率查询请求
const DWORD FTD_TID_ReqQryExchangeRate=0x00006089;
//汇率查询应答
const DWORD FTD_TID_RspQryExchangeRate=0x0000608A;
//回路度量
const DWORD FTD_TID_IntlLoopMeasureData=0x0000608B;
//CPU查询
const DWORD FTD_TID_ReqQryTopCpuInfoTopic=0x00009001;
//CPU应答
const DWORD FTD_TID_RspQryTopCpuInfoTopic=0x00009002;
//CPU应答
const DWORD FTD_TID_RtnTopCpuInfoTopic=0x00009003;
//Mem查询
const DWORD FTD_TID_ReqQryTopMemInfoTopic=0x00009004;
//Mem应答
const DWORD FTD_TID_RspQryTopMemInfoTopic=0x00009005;
//Mem应答
const DWORD FTD_TID_RtnTopMemInfoTopic=0x00009006;
//process查询
const DWORD FTD_TID_ReqQryTopProcessInfoTopic=0x00009007;
//process应答
const DWORD FTD_TID_RspQryTopProcessInfoTopic=0x00009008;
//process应答
const DWORD FTD_TID_RtnTopProcessInfoTopic=0x00009009;
//filesystem查询
const DWORD FTD_TID_ReqQryFileSystemInfoTopic=0x0000900A;
//filesystem应答
const DWORD FTD_TID_RspQryFileSystemInfoTopic=0x0000900B;
//filesystem应答
const DWORD FTD_TID_RtnFileSystemInfoTopic=0x0000900C;
//network查询
const DWORD FTD_TID_ReqQryNetworkInfoTopic=0x0000900D;
//network应答
const DWORD FTD_TID_RspQryNetworkInfoTopic=0x0000900E;
//network应答
const DWORD FTD_TID_RtnNetworkInfoTopic=0x0000900F;
//主机环境信息查询
const DWORD FTD_TID_ReqQryHostEnvTopic=0x00009022;
//客户端登录查询
const DWORD FTD_TID_ReqQryClientLoginTopic=0x00009025;
//客户端登录应答
const DWORD FTD_TID_RspQryClientLoginTopic=0x00009026;
//获得监控对象信息查询
const DWORD FTD_TID_ReqQryMonitorObjectTopic=0x00009028;
//获得监控对象信息应答
const DWORD FTD_TID_RspQryMonitorObjectTopic=0x00009029;
//获得监控对象信息应答
const DWORD FTD_TID_RtnMonitorObjectTopic=0x0000902A;
//获得业务进程和主机的对应关系查询
const DWORD FTD_TID_ReqQryObjectRationalTopic=0x0000902B;
//获得业务进程和主机的对应关系应答
const DWORD FTD_TID_RspQryObjectRationalTopic=0x0000902C;
//获得业务进程和主机的对应关系应答
const DWORD FTD_TID_RtnObjectRationalTopic=0x0000902D;
//日志文件内容查询
const DWORD FTD_TID_ReqQrySyslogInfoTopic=0x00009034;
//日志文件内容应答
const DWORD FTD_TID_RspQrySyslogInfoTopic=0x00009035;
//日志文件内容应答
const DWORD FTD_TID_RtnSyslogInfoTopic=0x00009036;
//监控内容订阅请求
const DWORD FTD_TID_ReqQrySubscriberTopic=0x00009037;
//监控内容订阅应答
const DWORD FTD_TID_RspQrySubscriberTopic=0x00009038;
//对象关系查询
const DWORD FTD_TID_ReqQryOidRelationTopic=0x00009196;
//对象关系查询应答
const DWORD FTD_TID_RspQryOidRelationTopic=0x00009197;
//对象关系查询应答
const DWORD FTD_TID_RtnOidRelationTopic=0x00009198;
//用户信息查询请求
const DWORD FTD_TID_ReqQryUserInfoTopic=0x00009212;
//用户信息查询请求应答
const DWORD FTD_TID_RspQryUserInfoTopic=0x00009213;
//用户信息查询请求应答
const DWORD FTD_TID_RtnUserInfoTopic=0x00009214;
//在线用户信息查询请求
const DWORD FTD_TID_ReqQryOnlineUserInfoTopic=0x00009215;
//在线用户信息查询请求应答
const DWORD FTD_TID_RspQryOnlineUserInfoTopic=0x00009216;
//在线用户信息查询请求应答
const DWORD FTD_TID_RtnOnlineUserInfoTopic=0x00009217;
//告警事件查询请求
const DWORD FTD_TID_ReqQryWarningEventTopic=0x00009221;
//告警事件查询请求应答
const DWORD FTD_TID_RspQryWarningEventTopic=0x00009222;
//告警事件查询请求应答
const DWORD FTD_TID_RtnWarningEventTopic=0x00009223;
//CPU使用率查询请求
const DWORD FTD_TID_ReqQryCPUUsageTopic=0x00009227;
//CPU使用率查询请求应答
const DWORD FTD_TID_RspQryCPUUsageTopic=0x00009228;
//CPU使用率查询请求应答
const DWORD FTD_TID_RtnCPUUsageTopic=0x00009229;
//内存使用率查询请求
const DWORD FTD_TID_ReqQryMemoryUsageTopic=0x00009230;
//内存使用率查询请求应答
const DWORD FTD_TID_RspQryMemoryUsageTopic=0x00009231;
//内存使用率查询请求应答
const DWORD FTD_TID_RtnMemoryUsageTopic=0x00009232;
//硬盘使用率查询请求
const DWORD FTD_TID_ReqQryDiskUsageTopic=0x00009233;
//硬盘使用率查询请求应答
const DWORD FTD_TID_RspQryDiskUsageTopic=0x00009234;
//硬盘使用率查询请求应答
const DWORD FTD_TID_RtnDiskUsageTopic=0x00009235;
//对象状态指标查询
const DWORD FTD_TID_ReqQryObjectAttrTopic=0x00009236;
//对象状态指标查询应答
const DWORD FTD_TID_RspQryObjectAttrTopic=0x00009237;
//对象状态指标查询应答
const DWORD FTD_TID_RtnObjectAttrTopic=0x00009238;
//KeyFile查询请求
const DWORD FTD_TID_ReqQryKeyFileInfoTopic=0x00009224;
//HostMonitorCfg查询请求
const DWORD FTD_TID_ReqQryHostMonitorCfgTopic=0x00009225;
//AppMonitorCfg查询请求
const DWORD FTD_TID_ReqQryAppMonitorCfgTopic=0x00009226;
//HostConfig查询请求
const DWORD FTD_TID_ReqQryHostConfigTopic=0x00009242;
//无效报单查询
const DWORD FTD_TID_ReqQryInvalidateOrderTopic=0x00009400;
//无效报单查询应答
const DWORD FTD_TID_RspQryInvalidateOrderTopic=0x00009401;
//无效报单查询应答
const DWORD FTD_TID_RtnInvalidateOrderTopic=0x00009402;
//报单状态查询
const DWORD FTD_TID_ReqQryOrderStatusTopic=0x00009403;
//报单状态查询应答
const DWORD FTD_TID_RspQryOrderStatusTopic=0x00009404;
//报单状态查询应答
const DWORD FTD_TID_RtnOrderStatusTopic=0x00009405;
//报单成交查询
const DWORD FTD_TID_ReqQryBargainOrderTopic=0x00009406;
//报单成交查询应答
const DWORD FTD_TID_RspQryBargainOrderTopic=0x00009407;
//报单成交查询应答
const DWORD FTD_TID_RtnBargainOrderTopic=0x00009408;
//合约基本属性查询
const DWORD FTD_TID_ReqQryInstPropertyTopic=0x00009409;
//合约基本属性查询应答
const DWORD FTD_TID_RspQryInstPropertyTopic=0x00009410;
//合约基本属性查询应答
const DWORD FTD_TID_RtnInstPropertyTopic=0x00009411;
//合约保证金率查询
const DWORD FTD_TID_ReqQryMarginRateTopic=0x00009412;
//合约保证金率查询应答
const DWORD FTD_TID_RspQryMarginRateTopic=0x00009413;
//合约保证金率查询应答
const DWORD FTD_TID_RtnMarginRateTopic=0x00009414;
//合约涨跌停板查询
const DWORD FTD_TID_ReqQryPriceLimitTopic=0x00009415;
//合约涨跌停板查询应答
const DWORD FTD_TID_RspQryPriceLimitTopic=0x00009416;
//合约涨跌停板查询应答
const DWORD FTD_TID_RtnPriceLimitTopic=0x00009417;
//会员限仓查询
const DWORD FTD_TID_ReqQryPartPosiLimitTopic=0x00009418;
//会员限仓查询应答
const DWORD FTD_TID_RspQryPartPosiLimitTopic=0x00009419;
//会员限仓查询应答
const DWORD FTD_TID_RtnPartPosiLimitTopic=0x00009420;
//客户限仓查询
const DWORD FTD_TID_ReqQryClientPosiLimitTopic=0x00009421;
//客户限仓查询应答
const DWORD FTD_TID_RspQryClientPosiLimitTopic=0x00009422;
//客户限仓查询应答
const DWORD FTD_TID_RtnClientPosiLimitTopic=0x00009423;
//特殊客户限仓查询
const DWORD FTD_TID_ReqQrySpecialPosiLimitTopic=0x00009424;
//特殊客户限仓查询应答
const DWORD FTD_TID_RspQrySpecialPosiLimitTopic=0x00009425;
//特殊客户限仓查询应答
const DWORD FTD_TID_RtnSpecialPosiLimitTopic=0x00009426;
//账户出入金查询
const DWORD FTD_TID_ReqQryTransactionChgTopic=0x00009427;
//账户出入金查询应答
const DWORD FTD_TID_RspQryTransactionChgTopic=0x00009428;
//账户出入金查询应答
const DWORD FTD_TID_RtnTransactionChgTopic=0x00009429;
//客户数据变动查询
const DWORD FTD_TID_ReqQryClientChgTopic=0x00009430;
//客户数据变动查询应答
const DWORD FTD_TID_RspQryClientChgTopic=0x00009431;
//客户数据变动查询应答
const DWORD FTD_TID_RtnClientChgTopic=0x00009432;
//会员客户对照变动查询
const DWORD FTD_TID_ReqQryPartClientChgTopic=0x00009433;
//会员客户对照变动查询应答
const DWORD FTD_TID_RspQryPartClientChgTopic=0x00009434;
//会员客户对照变动查询应答
const DWORD FTD_TID_RtnPartClientChgTopic=0x00009435;
//限仓数据变动查询
const DWORD FTD_TID_ReqQryPosiLimitChgTopic=0x00009436;
//限仓数据变动查询应答
const DWORD FTD_TID_RspQryPosiLimitChgTopic=0x00009437;
//限仓数据变动查询应答
const DWORD FTD_TID_RtnPosiLimitChgTopic=0x00009438;
//保值额度变动查询
const DWORD FTD_TID_ReqQryHedgeDetailChgTopic=0x00009439;
//保值额度变动查询应答
const DWORD FTD_TID_RspQryHedgeDetailChgTopic=0x00009440;
//保值额度变动查询应答
const DWORD FTD_TID_RtnHedgeDetailChgTopic=0x00009441;
//会员变动查询
const DWORD FTD_TID_ReqQryParticipantChgTopic=0x00009442;
//会员变动查询应答
const DWORD FTD_TID_RspQryParticipantChgTopic=0x00009443;
//会员变动查询应答
const DWORD FTD_TID_RtnParticipantChgTopic=0x00009444;
//保证金率变动查询
const DWORD FTD_TID_ReqQryMarginRateChgTopic=0x00009445;
//保证金率变动查询应答
const DWORD FTD_TID_RspQryMarginRateChgTopic=0x00009446;
//保证金率变动查询应答
const DWORD FTD_TID_RtnMarginRateChgTopic=0x00009447;
//IP地址变动查询
const DWORD FTD_TID_ReqQryUserIpChgTopic=0x00009448;
//IP地址变动查询应答
const DWORD FTD_TID_RspQryUserIpChgTopic=0x00009449;
//IP地址变动查询应答
const DWORD FTD_TID_RtnUserIpChgTopic=0x00009450;
//限仓数据变动查询
const DWORD FTD_TID_ReqQryClientPosiLimitChgTopic=0x00009451;
//限仓数据变动查询应答
const DWORD FTD_TID_RspQryClientPosiLimitChgTopic=0x00009452;
//限仓数据变动查询应答
const DWORD FTD_TID_RtnClientPosiLimitChgTopic=0x00009453;
//限仓数据变动查询
const DWORD FTD_TID_ReqQrySpecPosiLimitChgTopic=0x00009454;
//限仓数据变动查询应答
const DWORD FTD_TID_RspQrySpecPosiLimitChgTopic=0x00009455;
//限仓数据变动查询应答
const DWORD FTD_TID_RtnSpecPosiLimitChgTopic=0x00009456;
//历史对象状态指标查询
const DWORD FTD_TID_ReqQryHistoryObjectAttrTopic=0x00009457;
//历史对象状态指标查询应答
const DWORD FTD_TID_RspQryHistoryObjectAttrTopic=0x00009458;
//历史对象状态指标查询应答
const DWORD FTD_TID_RtnHistoryObjectAttrTopic=0x00009459;
//前置响应信息查询
const DWORD FTD_TID_ReqQryFrontInfoTopic=0x00009460;
//前置响应信息查询应答
const DWORD FTD_TID_RspQryFrontInfoTopic=0x00009461;
//前置响应信息查询应答
const DWORD FTD_TID_RtnFrontInfoTopic=0x00009462;
//用户登录
const DWORD FTD_TID_ReqQrySysUserLoginTopic=0x00009463;
//用户登录应答
const DWORD FTD_TID_RspQrySysUserLoginTopic=0x00009464;
//用户登出
const DWORD FTD_TID_ReqQrySysUserLogoutTopic=0x00009465;
//用户登出应答
const DWORD FTD_TID_RspQrySysUserLogoutTopic=0x00009466;
//用户修改密码
const DWORD FTD_TID_ReqQrySysUserPasswordUpdateTopic=0x00009467;
//用户修改密码应答
const DWORD FTD_TID_RspQrySysUserPasswordUpdateTopic=0x00009468;
//注册用户
const DWORD FTD_TID_ReqQrySysUserRegisterTopic=0x00009469;
//注册用户应答
const DWORD FTD_TID_RspQrySysUserRegisterTopic=0x00009470;
//删除用户
const DWORD FTD_TID_ReqQrySysUserDeleteTopic=0x00009471;
//删除用户应答
const DWORD FTD_TID_RspQrySysUserDeleteTopic=0x00009472;
//会员初始化应答
const DWORD FTD_TID_RspQryParticipantInitTopic=0x00009474;
//会员初始化应答
const DWORD FTD_TID_RtnParticipantInitTopic=0x00009475;
//座席初始化应答
const DWORD FTD_TID_RspQryUserInitTopic=0x00009476;
//座席初始化应答
const DWORD FTD_TID_RtnUserInitTopic=0x00009477;
//客户初始化应答
const DWORD FTD_TID_RspQryClientInitTopic=0x00009478;
//客户初始化应答
const DWORD FTD_TID_RtnClientInitTopic=0x00009479;
//交易日志查询
const DWORD FTD_TID_ReqQryTradeLogTopic=0x00009480;
//交易日志查询应答
const DWORD FTD_TID_RspQryTradeLogTopic=0x00009481;
//交易日志查询应答
const DWORD FTD_TID_RtnTradeLogTopic=0x00009482;
//告警事件修改
const DWORD FTD_TID_ReqQryWarningEventUpdateTopic=0x00009485;
//交易系统登录信息查询
const DWORD FTD_TID_ReqQryTradeUserLoginInfoTopic=0x00009486;
//交易系统登录信息
const DWORD FTD_TID_RspQryTradeUserLoginInfoTopic=0x00009487;
//交易系统登录信息
const DWORD FTD_TID_RtnTradeUserLoginInfoTopic=0x00009488;
//会员交易查询
const DWORD FTD_TID_ReqQryPartTradeTopic=0x00009489;
//会员交易查询应答
const DWORD FTD_TID_RspQryPartTradeTopic=0x00009490;
//交易峰值查询
const DWORD FTD_TID_ReqQryTradepeakTopic=0x00009491;
//交易峰值查询应答
const DWORD FTD_TID_RspQryTradepeakTopic=0x00009492;
//
const DWORD FTD_TID_RtnUpdateSysConfigTopic=0x00009493;
//
const DWORD FTD_TID_RtnSysUser=0x00009494;
//
const DWORD FTD_TID_RtnPriceLimitChgTopic=0x00009495;
//管理平台初始化信息查询
const DWORD FTD_TID_ReqQryParticipantInitTopic=0x00009496;
//管理平台初始化信息查询
const DWORD FTD_TID_ReqQryUserInitTopic=0x00009497;
//
const DWORD FTD_TID_ReqQryHistoryCpuInfoTopic=0x00009500;
//
const DWORD FTD_TID_RspQryHistoryCpuInfoTopic=0x00009501;
//
const DWORD FTD_TID_ReqQryHistoryMemInfoTopic=0x00009502;
//
const DWORD FTD_TID_RspQryHistoryMemInfoTopic=0x00009503;
//
const DWORD FTD_TID_ReqQryHistoryNetworkInfoTopic=0x00009504;
//
const DWORD FTD_TID_RspQryHistoryNetworkInfoTopic=0x00009505;
//HostConfig查询请求应答
const DWORD FTD_TID_RspQryHostConfig=0x00009506;
//监控系统在线用户查询
const DWORD FTD_TID_ReqQryMonitorOnlineUser=0x00009507;
//监控系统在线用户应答
const DWORD FTD_TID_RspQryMonitorOnlineUser=0x00009508;
//交易系统前置统计查询
const DWORD FTD_TID_ReqQryFrontStat=0x00009509;
//交易系统前置统计应答
const DWORD FTD_TID_RspQryFrontStat=0x00009510;
//监控系统时钟同步
const DWORD FTD_TID_RtnSysTimeSyncTopic=0x00009511;
//数据中心切换通知
const DWORD FTD_TID_RtnDataCenterChgTopic=0x00009512;
//历史峰值查询
const DWORD FTD_TID_ReqQryHistoryTradePeakTopic=0x00009513;
//历史峰值查询应答
const DWORD FTD_TID_RspQryHistoryTradePeakTopic=0x00009514;
//历史峰值查询应答
const DWORD FTD_TID_RtnHistoryTradePeakTopic=0x00009515;
//日志事件查询
const DWORD FTD_TID_ReqQrySyslogEventTopic=0x00009516;
//日志事件查询应答
const DWORD FTD_TID_RspQrySyslogEventTopic=0x00009517;
//日志事件应答
const DWORD FTD_TID_RtnSyslogEventTopic=0x00009518;
//日志事件订阅请求
const DWORD FTD_TID_ReqQrySyslogEventSubcriberTopic=0x00009519;
//交易日切换通知
const DWORD FTD_TID_ReqQryTradeDayChangeTopic=0x00009520;
//交易日切换通知
const DWORD FTD_TID_RspQryTradeDayChangeTopic=0x00009521;
//tomcat信息查询
const DWORD FTD_TID_ReqQryTomcatInfoTopic=0x00009522;
//Web应用信息
const DWORD FTD_TID_RspQryWebAppInfoTopic=0x00009523;
//Web应用信息
const DWORD FTD_TID_RtnWebAppInfoTopic=0x00009524;
//应用servlet信息
const DWORD FTD_TID_RspQryServletInfoTopic=0x00009525;
//应用servlet信息
const DWORD FTD_TID_RtnServletInfoTopic=0x00009526;
//文件信息
const DWORD FTD_TID_RspQryFileInfoTopic=0x00009527;
//文件信息
const DWORD FTD_TID_RtnFileInfoTopic=0x00009528;
//应用会话信息
const DWORD FTD_TID_RspQrySessionInfoTopic=0x00009529;
//应用会话信息
const DWORD FTD_TID_RtnSessionInfoTopic=0x00009530;
//JDBC信息
const DWORD FTD_TID_RspQryJDBCInfoTopic=0x00009531;
//JDBC信息
const DWORD FTD_TID_RtnJDBCInfoTopic=0x00009532;
//线程信息
const DWORD FTD_TID_RspQryThreadInfoTopic=0x00009533;
//线程信息
const DWORD FTD_TID_RtnThreadInfoTopic=0x00009534;
//虚拟机信息查询
const DWORD FTD_TID_ReqQryVMInfoTopic=0x00009535;
//虚拟机信息
const DWORD FTD_TID_RspQryVMInfoTopic=0x00009536;
//虚拟机信息
const DWORD FTD_TID_RtnVMInfoTopic=0x00009537;
//系统属性信息查询
const DWORD FTD_TID_ReqQryPropertyInfoTopic=0x00009538;
//系统属性信息
const DWORD FTD_TID_RspQryPropertyInfoTopic=0x00009539;
//系统属性信息
const DWORD FTD_TID_RtnPropertyInfoTopic=0x00009540;
//系统内存池信息查询
const DWORD FTD_TID_ReqQryMemPoolInfoTopic=0x00009541;
//系统内存池信息
const DWORD FTD_TID_RspQryMemPoolInfoTopic=0x00009542;
//系统内存池信息
const DWORD FTD_TID_RtnMemPoolInfoTopic=0x00009543;
//文件内容信息查询
const DWORD FTD_TID_ReqQryFileContentInfoTopic=0x00009544;
//文件内容信息
const DWORD FTD_TID_RspQryFileContentInfoTopic=0x00009545;
//文件内容信息
const DWORD FTD_TID_RtnFileContentInfoTopic=0x00009546;
//连接信息查询
const DWORD FTD_TID_ReqQryConnectionInfoTopic=0x00009547;
//连接信息
const DWORD FTD_TID_RspQryConnectionInfoTopic=0x00009548;
//连接信息
const DWORD FTD_TID_RtnConnectionInfoTopic=0x00009549;
//连接器信息查询
const DWORD FTD_TID_ReqQryConnectorInfoTopic=0x00009550;
//连接器信息
const DWORD FTD_TID_RspQryConnectorInfoTopic=0x00009551;
//连接器信息
const DWORD FTD_TID_RtnConnectorInfoTopic=0x00009552;
//数据库查询
const DWORD FTD_TID_ReqQryDBQueryTopic=0x00009553;
//数据库查询应答
const DWORD FTD_TID_RspQryDBQueryTopic=0x00009554;
//数据库查询应答
const DWORD FTD_TID_RtnDBQueryTopic=0x00009555;
//通用返回应答
const DWORD FTD_TID_RspQryGeneralFieldTopic=0x00009556;
//通用返回应答
const DWORD FTD_TID_RtnGeneralFieldTopic=0x00009557;
//文件传输请求
const DWORD FTD_TID_ReqQryGetFileTopic=0x00009558;
//文件传输应答
const DWORD FTD_TID_RspQryGetFileTopic=0x00009559;
//日志事件修改请求
const DWORD FTD_TID_ReqQrySyslogEventUpdateTopic=0x00009560;
//告警明细查询
const DWORD FTD_TID_ReqQryWarningQueryTopic=0x00009561;
//告警明细
const DWORD FTD_TID_RspQryWarningQueryTopic=0x00009562;
//告警明细
const DWORD FTD_TID_RtnWarningQueryTopic=0x00009563;
//网站访问查询
const DWORD FTD_TID_ReqQryWebVisitTopic=0x00009564;
//HostConfig订阅应答
const DWORD FTD_TID_RtnHostConfig=0x00009565;
//告警激活变更
const DWORD FTD_TID_ReqQryWarningActiveChange=0x00009566;
//告警激活变更
const DWORD FTD_TID_RspQryWarningActiveChange=0x00009567;
//告警激活变更
const DWORD FTD_TID_RtnWarningActiveChange=0x00009568;
//通用操作
const DWORD FTD_TID_ReqQryGeneralOperateTopic=0x00009569;
//通用操作
const DWORD FTD_TID_RspQryGeneralOperateTopic=0x00009570;
//通用操作
const DWORD FTD_TID_RtnGeneralOperateTopic=0x00009571;
//网络设备连接关系请求
const DWORD FTD_TID_ReqQryNetDeviceLinkedTopic=0x00009572;
//网络设备连接关系
const DWORD FTD_TID_RspQryNetDeviceLinkedTopic=0x00009573;
//网络设备连接关系
const DWORD FTD_TID_RtnNetDeviceLinkedTopic=0x00009574;
//交易系统登录信息请求
const DWORD FTD_TID_ReqQryTradeUserLoginStatTopic=0x00009575;
//交易系统登录信息
const DWORD FTD_TID_RspQryTradeUserLoginStatTopic=0x00009576;
//交易系统前置报单响应信息
const DWORD FTD_TID_ReqQryTradeFrontOrderRttStatTopic=0x00009577;
//交易系统前置报单响应信息
const DWORD FTD_TID_RspQryTradeFrontOrderRttStatTopic=0x00009578;
//交易系统前置报单响应信息
const DWORD FTD_TID_RtnTradeFrontOrderRttStatTopic=0x00009579;
//会员席位交易状态
const DWORD FTD_TID_ReqQryParticTradeOrderStatesTopic=0x0000957a;
//会员席位交易状态
const DWORD FTD_TID_RspQryParticTradeOrderStatesTopic=0x0000957b;
//会员席位交易状态
const DWORD FTD_TID_RtnParticTradeOrderStatesTopic=0x0000957c;
//系统路由信息
const DWORD FTD_TID_ReqQryRouterInfoTopic=0x0000957d;
//系统路由信息
const DWORD FTD_TID_RspQryRouterInfoTopic=0x0000957e;
//系统路由信息
const DWORD FTD_TID_RtnRouterInfoTopic=0x0000957f;
//磁盘I/O信息
const DWORD FTD_TID_ReqQryDiskIOTopic=0x00009580;
//磁盘I/O信息
const DWORD FTD_TID_RspQryDiskIOTopic=0x00009581;
//磁盘I/O信息
const DWORD FTD_TID_RtnDiskIOTopic=0x00009582;
//系统状态信息
const DWORD FTD_TID_ReqQryStatInfoTopic=0x00009583;
//系统状态信息
const DWORD FTD_TID_RspQryStatInfoTopic=0x00009584;
//系统状态信息
const DWORD FTD_TID_RtnStatInfoTopic=0x00009585;
//交易系统前置报单分布区间
const DWORD FTD_TID_ReqQryTradeOrderRttCutLineTopic=0x00009586;
//交易系统前置报单分布区间
const DWORD FTD_TID_RspQryTradeOrderRttCutLineTopic=0x00009587;
//交易系统前置报单分布区间
const DWORD FTD_TID_RtnTradeOrderRttCutLineTopic=0x00009588;
//会员客户信息
const DWORD FTD_TID_ReqQryClientInfoTopic=0x00009589;
//会员客户信息
const DWORD FTD_TID_RspQryClientInfoTopic=0x0000958a;
//会员客户信息
const DWORD FTD_TID_RtnClientInfoTopic=0x0000958b;
//请求事件描述
const DWORD FTD_TID_ReqQryEventDescriptionTopic=0x0000958c;
//应答事件描述
const DWORD FTD_TID_RspQryEventDescriptionTopic=0x0000958d;
//订阅事件描述
const DWORD FTD_TID_RtnEventDescriptionTopic=0x0000958e;
//订阅前置唯一ID信息
const DWORD FTD_TID_ReqQryFrontUniqueIDTopic=0x0000958f;
//应答前置唯一ID信息
const DWORD FTD_TID_RspQryFrontUniqueIDTopic=0x00009590;
//订阅前置唯一ID信息
const DWORD FTD_TID_RtnFrontUniqueIDTopic=0x00009591;
//会员线路地址变更请求
const DWORD FTD_TID_ReqQryNetPartyLinkAddrChangeTopic=0x00009592;
//会员线路地址变更回应
const DWORD FTD_TID_RspQryNetPartyLinkAddrChangeTopic=0x00009593;
//订阅会员线路地址变更信息
const DWORD FTD_TID_RtnNetPartyLinkAddrChangeTopic=0x00009594;
//请求已删除会员列表信息
const DWORD FTD_TID_ReqQryNetDelPartyLinkInfoTopic=0x00009595;
//应答已删除会员列表信息
const DWORD FTD_TID_RspQryNetDelPartyLinkInfoTopic=0x00009596;
//订阅已删除会员列表信息
const DWORD FTD_TID_RtnNetDelPartyLinkInfoTopic=0x00009597;
//请求网络性能排序
const DWORD FTD_TID_ReqQryPerformanceTopTopic=0x00009598;
//返回网络性能排序
const DWORD FTD_TID_RspQryPerformanceTopTopic=0x00009599;
//订阅网络性能排序
const DWORD FTD_TID_RtnPerformanceTopTopic=0x0000959a;
//请求约状态切换数据
const DWORD FTD_TID_ReqQryInstrumentStatusTopic=0x0000959b;
//返回约状态切换数据
const DWORD FTD_TID_RspQryInstrumentStatusTopic=0x0000959c;
//订阅约状态切换数据
const DWORD FTD_TID_RtnInstrumentStatusTopic=0x0000959d;
//请求合约交易节信息
const DWORD FTD_TID_ReqQryCurrTradingSegmentAttrTopic=0x0000959e;
//返回合约交易节信息
const DWORD FTD_TID_RspQryCurrTradingSegmentAttrTopic=0x0000959f;
//订阅合约交易节信息
const DWORD FTD_TID_RtnCurrTradingSegmentAttrTopic=0x000095a0;
//最新网络指标查询
const DWORD FTD_TID_ReqQryRealTimeNetObjectAttrTopic=0x00100003;
//网络大区划分查询
const DWORD FTD_TID_ReqQryNetAreaTopic=0x00100010;
//网络大区划分应答
const DWORD FTD_TID_RspQryNetAreaTopic=0x00100011;
//网络大区划分应答
const DWORD FTD_TID_RtnNetAreaTopic=0x00100012;
//网络子区查询
const DWORD FTD_TID_ReqQryNetSubAreaTopic=0x00100013;
//网络子区应答
const DWORD FTD_TID_RspQryNetSubAreaTopic=0x00100014;
//网络子区应答
const DWORD FTD_TID_RtnNetSubAreaTopic=0x00100015;
//网络子区IP查询
const DWORD FTD_TID_ReqQryNetSubAreaIPTopic=0x00100016;
//网络子区IP应答
const DWORD FTD_TID_RspQryNetSubAreaIPTopic=0x00100017;
//网络子区IP应答
const DWORD FTD_TID_RtnNetSubAreaIPTopic=0x00100018;
//网络设备探测请求
const DWORD FTD_TID_ReqQryNetDeviceDetectTopic=0x00100019;
//网络设备查询请求
const DWORD FTD_TID_ReqQryNetDeviceRequestTopic=0x00100020;
//网络设备
const DWORD FTD_TID_RspQryNetDeviceTopic=0x00100021;
//网络设备
const DWORD FTD_TID_RtnNetDeviceTopic=0x00100022;
//网络设备探测请求应答
const DWORD FTD_TID_RspQryNetDeviceDetectTopic=0x00100023;
//大楼查询
const DWORD FTD_TID_ReqQryNetBuildingTopic=0x00100024;
//大楼
const DWORD FTD_TID_RspQryNetBuildingTopic=0x00100025;
//大楼
const DWORD FTD_TID_RtnNetBuildingTopic=0x00100026;
//机房查询
const DWORD FTD_TID_ReqQryNetRoomTopic=0x00100027;
//机房
const DWORD FTD_TID_RspQryNetRoomTopic=0x00100028;
//机房
const DWORD FTD_TID_RtnNetRoomTopic=0x00100029;
//机柜查询
const DWORD FTD_TID_ReqQryNetCabinetsTopic=0x00100030;
//机柜
const DWORD FTD_TID_RspQryNetCabinetsTopic=0x00100031;
//机柜
const DWORD FTD_TID_RtnNetCabinetsTopic=0x00100032;
//OID
const DWORD FTD_TID_ReqQryNetOIDTopic=0x00100033;
//OID
const DWORD FTD_TID_RspQryNetOIDTopic=0x00100034;
//OID
const DWORD FTD_TID_RtnNetOIDTopic=0x00100035;
//时间策略
const DWORD FTD_TID_ReqQryNetTimePolicyTopic=0x00100036;
//时间策略
const DWORD FTD_TID_RspQryNetTimePolicyTopic=0x00100037;
//时间策略
const DWORD FTD_TID_RtnNetTimePolicyTopic=0x00100038;
//采集任务查询
const DWORD FTD_TID_ReqQryNetGatherTaskTopic=0x00100039;
//采集任务
const DWORD FTD_TID_RspQryNetGatherTaskTopic=0x00100040;
//采集任务
const DWORD FTD_TID_RtnNetGatherTaskTopic=0x00100041;
//设备变更请求
const DWORD FTD_TID_ReqQryNetDeviceChgTopic=0x00100042;
//设备变更
const DWORD FTD_TID_RspQryNetDeviceChgTopic=0x00100043;
//设备变更
const DWORD FTD_TID_RtnNetDeviceChgTopic=0x00100044;
//常用设备型号请求
const DWORD FTD_TID_ReqQryNetDeviceTypeTopic=0x00100045;
//常用设备型号
const DWORD FTD_TID_RspQryNetDeviceTypeTopic=0x00100046;
//常用设备型号
const DWORD FTD_TID_RtnNetDeviceTypeTopic=0x00100047;
//常用设备类别请求
const DWORD FTD_TID_ReqQryNetDeviceCategoryTopic=0x00100048;
//常用设备类别
const DWORD FTD_TID_RspQryNetDeviceCategoryTopic=0x00100049;
//常用设备类别
const DWORD FTD_TID_RtnNetDeviceCategoryTopic=0x00100050;
//设备厂商请求
const DWORD FTD_TID_ReqQryNetManufactoryTopic=0x00100051;
//设备厂商
const DWORD FTD_TID_RspQryNetManufactoryTopic=0x00100052;
//设备厂商
const DWORD FTD_TID_RtnNetManufactoryTopic=0x00100053;
//设备共同体请求
const DWORD FTD_TID_ReqQryNetCommunityTopic=0x00100054;
//设备共同体
const DWORD FTD_TID_RspQryNetCommunityTopic=0x00100055;
//设备共同体
const DWORD FTD_TID_RtnNetCommunityTopic=0x00100056;
//端口类型请求
const DWORD FTD_TID_ReqQryNetPortTypeTopic=0x00100057;
//端口类型
const DWORD FTD_TID_RspQryNetPortTypeTopic=0x00100058;
//端口类型
const DWORD FTD_TID_RtnNetPortTypeTopic=0x00100059;
//会员接入地点请求
const DWORD FTD_TID_ReqQryNetPartAccessSpotTopic=0x00100060;
//会员接入地点
const DWORD FTD_TID_RspQryNetPartAccessSpotTopic=0x00100061;
//会员接入地点
const DWORD FTD_TID_RtnNetPartAccessSpotTopic=0x00100062;
//端口请求
const DWORD FTD_TID_ReqQryNetInterfaceTopic=0x00100063;
//端口
const DWORD FTD_TID_RspQryNetInterfaceTopic=0x00100064;
//端口
const DWORD FTD_TID_RtnNetInterfaceTopic=0x00100065;
//GeneralOID请求
const DWORD FTD_TID_ReqQryNetGeneralOIDTopic=0x00100066;
//GeneralOID
const DWORD FTD_TID_RspQryNetGeneralOIDTopic=0x00100067;
//GeneralOID
const DWORD FTD_TID_RtnNetGeneralOIDTopic=0x00100068;
//监控对象类别
const DWORD FTD_TID_ReqQryNetMonitorTypeTopic=0x00100069;
//监控对象类别
const DWORD FTD_TID_RspQryNetMonitorTypeTopic=0x00100070;
//监控对象类别
const DWORD FTD_TID_RtnNetMonitorTypeTopic=0x00100071;
//指标统表
const DWORD FTD_TID_ReqQryNetMonitorAttrScopeTopic=0x00100072;
//指标统表
const DWORD FTD_TID_RspQryNetMonitorAttrScopeTopic=0x00100073;
//指标统表
const DWORD FTD_TID_RtnNetMonitorAttrScopeTopic=0x00100074;
//监控指标表
const DWORD FTD_TID_ReqQryNetMonitorAttrTypeTopic=0x00100075;
//监控指标表
const DWORD FTD_TID_RspQryNetMonitorAttrTypeTopic=0x00100076;
//监控指标表
const DWORD FTD_TID_RtnNetMonitorAttrTypeTopic=0x00100077;
//监控对象指标表
const DWORD FTD_TID_ReqQryNetMonitorObjectAttrTopic=0x00100078;
//监控对象指标表
const DWORD FTD_TID_RspQryNetMonitorObjectAttrTopic=0x00100079;
//监控对象指标表
const DWORD FTD_TID_RtnNetMonitorObjectAttrTopic=0x00100080;
//职能区
const DWORD FTD_TID_ReqQryNetFuncAreaTopic=0x00100081;
//职能区
const DWORD FTD_TID_RspQryNetFuncAreaTopic=0x00100082;
//职能区
const DWORD FTD_TID_RtnNetFuncAreaTopic=0x00100083;
//监控指令表
const DWORD FTD_TID_ReqQryNetMonitorCommandTypeTopic=0x00100084;
//监控指令表
const DWORD FTD_TID_RspQryNetMonitorCommandTypeTopic=0x00100085;
//监控指令表
const DWORD FTD_TID_RtnNetMonitorCommandTypeTopic=0x00100086;
//动作族表
const DWORD FTD_TID_ReqQryNetMonitorActionGroupTopic=0x00100087;
//动作族表
const DWORD FTD_TID_RspQryNetMonitorActionGroupTopic=0x00100088;
//动作族表
const DWORD FTD_TID_RtnNetMonitorActionGroupTopic=0x00100089;
//设备对象组表
const DWORD FTD_TID_ReqQryNetMonitorDeviceGroupTopic=0x00100090;
//设备对象组表
const DWORD FTD_TID_RspQryNetMonitorDeviceGroupTopic=0x00100091;
//设备对象组表
const DWORD FTD_TID_RtnNetMonitorDeviceGroupTopic=0x00100092;
//任务信息表
const DWORD FTD_TID_ReqQryNetMonitorTaskInfoTopic=0x00100093;
//任务信息表
const DWORD FTD_TID_RspQryNetMonitorTaskInfoTopic=0x00100094;
//任务信息表
const DWORD FTD_TID_RtnNetMonitorTaskInfoTopic=0x00100095;
//任务结果表
const DWORD FTD_TID_ReqQryNetMonitorTaskResultTopic=0x00100096;
//任务结果表
const DWORD FTD_TID_RspQryNetMonitorTaskResultTopic=0x00100097;
//任务结果表
const DWORD FTD_TID_RtnNetMonitorTaskResultTopic=0x00100098;
//任务对象集
const DWORD FTD_TID_ReqQryNetMonitorTaskObjectSetTopic=0x00100099;
//任务对象集
const DWORD FTD_TID_RspQryNetMonitorTaskObjectSetTopic=0x00100100;
//任务对象集
const DWORD FTD_TID_RtnNetMonitorTaskObjectSetTopic=0x00100101;
//会员链路信息表
const DWORD FTD_TID_ReqQryNetPartyLinkInfoTopic=0x00100102;
//会员链路信息表
const DWORD FTD_TID_RspQryNetPartyLinkInfoTopic=0x00100103;
//会员链路信息表
const DWORD FTD_TID_RtnNetPartyLinkInfoTopic=0x00100104;
//监控动作指标对照表
const DWORD FTD_TID_ReqQryNetMonitorActionAttrTopic=0x00100105;
//监控动作指标对照表
const DWORD FTD_TID_RspQryNetMonitorActionAttrTopic=0x00100106;
//监控动作指标对照表
const DWORD FTD_TID_RtnNetMonitorActionAttrTopic=0x00100107;
//模块
const DWORD FTD_TID_ReqQryNetModuleTopic=0x00100111;
//模块
const DWORD FTD_TID_RspQryNetModuleTopic=0x00100112;
//模块
const DWORD FTD_TID_RtnNetModuleTopic=0x00100113;
//告警表达式信息表
const DWORD FTD_TID_ReqQryNetEventExprTopic=0x00100114;
//告警表达式信息表
const DWORD FTD_TID_RspQryNetEventExprTopic=0x00100115;
//告警表达式信息表
const DWORD FTD_TID_RtnNetEventExprTopic=0x00100116;
//事件类型
const DWORD FTD_TID_ReqQryNetEventTypeTopic=0x00100117;
//事件类型
const DWORD FTD_TID_RspQryNetEventTypeTopic=0x00100118;
//事件类型
const DWORD FTD_TID_RtnNetEventTypeTopic=0x00100119;
//事件子类型
const DWORD FTD_TID_ReqQryNetSubEventTypeTopic=0x00100120;
//事件子类型
const DWORD FTD_TID_RspQryNetSubEventTypeTopic=0x00100121;
//事件子类型
const DWORD FTD_TID_RtnNetSubEventTypeTopic=0x00100122;
//事件级别
const DWORD FTD_TID_ReqQryNetEventLevelTopic=0x00100123;
//事件级别
const DWORD FTD_TID_RspQryNetEventLevelTopic=0x00100124;
//事件级别
const DWORD FTD_TID_RtnNetEventLevelTopic=0x00100125;
//任务结果状态表
const DWORD FTD_TID_ReqQryNetMonitorTaskStatusResultTopic=0x00100126;
//任务结果状态表
const DWORD FTD_TID_RspQryNetMonitorTaskStatusResultTopic=0x00100127;
//任务结果状态表
const DWORD FTD_TID_RtnNetMonitorTaskStatusResultTopic=0x00100128;
//登陆配置服务的请求
const DWORD FTD_TID_ReqConfigLoginTopic=0x00100129;
//配置服务对登陆的响应
const DWORD FTD_TID_RspConfigLoginTopic=0x00100130;
//对当前登录配置的服务角色的响应
const DWORD FTD_TID_RspServerTypeTopic=0x00100131;
//告知服务，让其退出
const DWORD FTD_TID_ReqSysServerExitTopic=0x00100150;
//设备配置表
const DWORD FTD_TID_ReqQryNetCfgFileTopic=0x00100151;
//设备配置表
const DWORD FTD_TID_RspQryNetCfgFileTopic=0x00100152;
//设备配置表
const DWORD FTD_TID_RtnNetCfgFileTopic=0x00100153;
//任务结果规则分析表
const DWORD FTD_TID_ReqQryNetMonitorDeviceTaskTopic=0x00100154;
//任务结果规则分析表
const DWORD FTD_TID_RspQryNetMonitorDeviceTaskTopic=0x00100155;
//任务结果规则分析表
const DWORD FTD_TID_RtnNetMonitorDeviceTaskTopic=0x00100156;
//任务指令指标集表
const DWORD FTD_TID_ReqQryNetMonitorTaskInstAttrsTopic=0x00100157;
//任务指令指标集表
const DWORD FTD_TID_RspQryNetMonitorTaskInstAttrsTopic=0x00100158;
//任务指令指标集表
const DWORD FTD_TID_RtnNetMonitorTaskInstAttrsTopic=0x00100159;
//文件通用操作
const DWORD FTD_TID_ReqQryFileGeneralOperTopic=0x00100160;
//文件通用操作
const DWORD FTD_TID_RspQryFileGeneralOperTopic=0x00100161;
//文件通用操作
const DWORD FTD_TID_RtnFileGeneralOperTopic=0x00100162;
//基线表
const DWORD FTD_TID_ReqQryNetBaseLineTopic=0x00100163;
//基线表
const DWORD FTD_TID_RspQryNetBaseLineTopic=0x00100164;
//基线表
const DWORD FTD_TID_RtnNetBaseLineTopic=0x00100165;
//基线任务表
const DWORD FTD_TID_ReqQryNetBaseLineTaskTopic=0x00100166;
//基线任务表
const DWORD FTD_TID_RspQryNetBaseLineTaskTopic=0x00100167;
//基线任务表
const DWORD FTD_TID_RtnNetBaseLineTaskTopic=0x00100168;
//基线结果表
const DWORD FTD_TID_ReqQryNetBaseLineResultTopic=0x00100169;
//基线结果表
const DWORD FTD_TID_RspQryNetBaseLineResultTopic=0x00100170;
//基线结果表
const DWORD FTD_TID_RtnNetBaseLineResultTopic=0x00100171;
//会员链路状态信息表
const DWORD FTD_TID_ReqQryNetPartyLinkStatusInfoTopic=0x00100172;
//会员链路状态信息表
const DWORD FTD_TID_RspQryNetPartyLinkStatusInfoTopic=0x00100173;
//会员链路状态信息表
const DWORD FTD_TID_RtnNetPartyLinkStatusInfoTopic=0x00100174;
//会员SDH线路明细表
const DWORD FTD_TID_ReqQryNetMemberSDHLineInfoTopic=0x00100175;
//会员SDH线路明细表
const DWORD FTD_TID_RspQryNetMemberSDHLineInfoTopic=0x00100176;
//会员SDH线路明细表
const DWORD FTD_TID_RtnNetMemberSDHLineInfoTopic=0x00100177;
//DDN链路信息表
const DWORD FTD_TID_ReqQryNetDDNLinkInfoTopic=0x00100178;
//DDN链路信息表
const DWORD FTD_TID_RspQryNetDDNLinkInfoTopic=0x00100179;
//DDN链路信息表
const DWORD FTD_TID_RtnNetDDNLinkInfoTopic=0x0010017a;
//非会员线路使用信息
const DWORD FTD_TID_ReqQryNetPseudMemberLinkInfoTopic=0x0010017b;
//非会员线路使用信息
const DWORD FTD_TID_RspQryNetPseudMemberLinkInfoTopic=0x0010017c;
//非会员线路使用信息
const DWORD FTD_TID_RtnNetPseudMemberLinkInfoTopic=0x0010017d;
//远端设备信息
const DWORD FTD_TID_ReqQryOuterDeviceInfTopic=0x0010017e;
//远端设备信息
const DWORD FTD_TID_RspQryOuterDeviceInfTopic=0x0010017f;
//远端设备信息
const DWORD FTD_TID_RtnNetOuterDeviceInfTopic=0x00100180;
//本地ping结果
const DWORD FTD_TID_ReqQryNetLocalPingResultInfoTopic=0x00100181;
//本地ping结果
const DWORD FTD_TID_RspQryNetLocalPingResultInfoTopic=0x00100182;
//本地ping结果
const DWORD FTD_TID_RtnNetLocalPingResultInfoTopic=0x00100183;
//远程ping结果
const DWORD FTD_TID_ReqQryNetRomotePingResultInfoTopic=0x00100184;
//远程ping结果
const DWORD FTD_TID_RspQryNetRomotePingResultInfoTopic=0x00100185;
//远程ping结果
const DWORD FTD_TID_RtnNetRomotePingResultInfoTopic=0x00100186;
//进程信息数据库专用
const DWORD FTD_TID_RtnMonitorTopProcessInfo=0x00100187;
//系统内部级联关系
const DWORD FTD_TID_ReqQrySysInternalTopologyTopic=0x00100188;
//系统内部级联关系
const DWORD FTD_TID_RspQrySysInternalTopologyTopic=0x00100189;
//系统内部级联关系
const DWORD FTD_TID_RtnSysInternalTopologyTopic=0x00100190;
//请求会员链路费用表
const DWORD FTD_TID_ReqQryMemberLinkCostTopic=0x00100191;
//返回会员链路费用表
const DWORD FTD_TID_RspQryMemberLinkCostTopic=0x00100192;
//订阅会员链路费用表
const DWORD FTD_TID_RtnMemberLinkCostTopic=0x00100193;
//请求会员链路月租表
const DWORD FTD_TID_ReqQryNetPartylinkMonthlyRentTopic=0x00100194;
//返回会员链路月租表
const DWORD FTD_TID_RspQryNetPartylinkMonthlyRentTopic=0x00100195;
//订阅会员链路月租表
const DWORD FTD_TID_RtnNetPartylinkMonthlyRentTopic=0x00100196;
//请求非会员链路表信息
const DWORD FTD_TID_ReqQryNetNonPartyLinkInfoTopic=0x00100197;
//返回非会员链路表信息
const DWORD FTD_TID_RspQryNetNonPartyLinkInfoTopic=0x00100198;
//订阅非会员链路表信息
const DWORD FTD_TID_RtnNetNonPartyLinkInfoTopic=0x00100199;

#ifndef FIELD_USE_DEFINE
#define FIELD_USE_DEFINE

#define UNLIMITED_FIELD_OCCUR 1000

typedef struct
{
	DWORD fid;
	CFieldDescribe *pFieldDescribe;
	int minOccur;
	int maxOccur;
}	TFieldUse;

typedef struct
{
	DWORD tid;
	int fieldUseCount;
	TFieldUse *fieldUse;
}	TPackageDefine;

#endif

extern TPackageDefine FTDPackageDefines[];

void FTDC_DEBUG_BODY(DWORD tid, CFieldSet *pPackage, CLogger *pLogger);

#endif
