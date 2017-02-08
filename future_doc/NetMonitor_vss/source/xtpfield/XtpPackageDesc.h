// XtpPackageDesc.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPPACKAGEDESC_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_)
#define AFX_XTPPACKAGEDESC_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XtpData.h"
#include "HashMap.h"
#include "FieldSet.h"

//空操作
const DWORD TID_Nop=0x00000009;
//错误应答
const DWORD TID_RspError=0x00000001;
//用户登录请求
const DWORD TID_ReqUserLogin=0x00001001;
//用户登录应答
const DWORD TID_RspUserLogin=0x00001002;
//用户退出请求
const DWORD TID_ReqUserLogout=0x00001003;
//用户退出应答
const DWORD TID_RspUserLogout=0x00001004;
//报单录入请求
const DWORD TID_ReqOrderInsert=0x00001005;
//报单录入应答
const DWORD TID_RspOrderInsert=0x00001006;
//报单操作请求
const DWORD TID_ReqOrderAction=0x00001007;
//报单操作应答
const DWORD TID_RspOrderAction=0x00001008;
//报价录入请求
const DWORD TID_ReqQuoteInsert=0x00001009;
//报价录入应答
const DWORD TID_RspQuoteInsert=0x0000100A;
//报价操作请求
const DWORD TID_ReqQuoteAction=0x0000100B;
//报价操作应答
const DWORD TID_RspQuoteAction=0x0000100C;
//OTC报单录入请求
const DWORD TID_ReqOTCOrderInsert=0x0000100D;
//OTC报单录入应答
const DWORD TID_RspOTCOrderInsert=0x0000100E;
//用户密码修改请求
const DWORD TID_ReqUserPasswordUpdate=0x0000100F;
//用户密码修改应答
const DWORD TID_RspUserPasswordUpdate=0x00001010;
//执行宣告录入请求
const DWORD TID_ReqExecOrderInsert=0x00001011;
//执行宣告录入应答
const DWORD TID_RspExecOrderInsert=0x00001012;
//执行宣告操作请求
const DWORD TID_ReqExecOrderAction=0x00001013;
//执行宣告操作应答
const DWORD TID_RspExecOrderAction=0x00001014;
//管理报单录入请求
const DWORD TID_ReqAdminOrderInsert=0x00001015;
//管理报单录入应答
const DWORD TID_RspAdminOrderInsert=0x00001016;
//组合报单录入请求
const DWORD TID_ReqCombOrderInsert=0x00001017;
//组合报单录入应答
const DWORD TID_RspCombOrderInsert=0x00001018;
//交易所公告请求
const DWORD TID_ReqBulletin=0x00002005;
//交易所公告请求应答
const DWORD TID_RspBulletin=0x00002006;
//合约交易状态改变请求
const DWORD TID_ReqInstrumentStatusUpdate=0x00002007;
//合约交易状态改变应答
const DWORD TID_RspInstrumentStatusUpdate=0x00002008;
//强制用户退出请求
const DWORD TID_ReqForceUserExit=0x0000200B;
//强制用户退出应答
const DWORD TID_RspForceUserExit=0x0000200C;
//用户会话删除请求
const DWORD TID_ReqForceUserLogout=0x0000200D;
//用户会话删除应答
const DWORD TID_RspForceUserLogout=0x0000200E;
//交易所数据同步状态改变请求
const DWORD TID_ReqExchangeDataSyncStatusUpdate=0x00002013;
//交易所数据同步状态改变应答
const DWORD TID_RspExchangeDataSyncStatusUpdate=0x00002014;
//结算组数据同步状态改变请求
const DWORD TID_ReqSGDataSyncStatusUpdate=0x00002015;
//结算组数据同步状态改变应答
const DWORD TID_RspSGDataSyncStatusUpdate=0x00002016;
//交易所数据同步请求
const DWORD TID_ReqExchangeDataSync=0x00002801;
//交易所数据同步应答
const DWORD TID_RspExchangeDataSync=0x00002802;
//结算组数据同步请求
const DWORD TID_ReqSgDataSync=0x00002803;
//结算组数据同步应答
const DWORD TID_RspSgDataSync=0x00002804;
//交易所信息请求
const DWORD TID_ReqInformation=0x00002805;
//交易所公告信息应答
const DWORD TID_RspInformation=0x00002806;
//前置状态报告请求
const DWORD TID_ReqFrontStatus=0x00009001;
//前置状态报告应答
const DWORD TID_RspFrontStatus=0x00009002;
//会员资金查询请求
const DWORD TID_ReqQryPartAccount=0x00004001;
//会员资金查询应答
const DWORD TID_RspQryPartAccount=0x00004002;
//报单查询请求
const DWORD TID_ReqQryOrder=0x00004003;
//报单查询应答
const DWORD TID_RspQryOrder=0x00004004;
//报价查询请求
const DWORD TID_ReqQryQuote=0x00004005;
//报价查询应答
const DWORD TID_RspQryQuote=0x00004006;
//成交单查询请求
const DWORD TID_ReqQryTrade=0x00004007;
//成交单查询应答
const DWORD TID_RspQryTrade=0x00004008;
//会员客户查询请求
const DWORD TID_ReqQryClient=0x00004009;
//会员客户查询应答
const DWORD TID_RspQryClient=0x0000400A;
//会员持仓查询请求
const DWORD TID_ReqQryPartPosition=0x0000400B;
//会员持仓查询应答
const DWORD TID_RspQryPartPosition=0x0000400C;
//客户持仓查询请求
const DWORD TID_ReqQryClientPosition=0x0000400D;
//客户持仓查询应答
const DWORD TID_RspQryClientPosition=0x0000400E;
//合约查询请求
const DWORD TID_ReqQryInstrument=0x0000400F;
//合约查询应答
const DWORD TID_RspQryInstrument=0x00004010;
//合约交易状态查询请求
const DWORD TID_ReqQryInstrumentStatus=0x00004011;
//合约交易状态查询应答
const DWORD TID_RspQryInstrumentStatus=0x00004012;
//结算组数据同步状态查询请求
const DWORD TID_ReqQrySGDataSyncStatus=0x00004013;
//结算组数据同步状态查询应答
const DWORD TID_RspQrySGDataSyncStatus=0x00004014;
//保值额度查询
const DWORD TID_ReqQryHedgeVolume=0x00004015;
//保值额度应答
const DWORD TID_RspQryHedgeVolume=0x00004016;
//组合报单查询请求
const DWORD TID_ReqQryCombOrder=0x00004017;
//组合报单查询应答
const DWORD TID_RspQryCombOrder=0x00004018;
//普通行情查询请求
const DWORD TID_ReqQryMarketData=0x00004101;
//普通行情查询应答
const DWORD TID_RspQryMarketData=0x00004102;
//交易所公告查询请求
const DWORD TID_ReqQryBulletin=0x00004103;
//交易所公告查询应答
const DWORD TID_RspQryBulletin=0x00004104;
//用户在线查询请求
const DWORD TID_ReqQryUserSession=0x000043D1;
//用户在线查询应答
const DWORD TID_RspQryUserSession=0x000043D2;
//用户查询请求
const DWORD TID_ReqQryUser=0x000043D3;
//用户查询应答
const DWORD TID_RspQryUser=0x000043D4;
//会员查询请求
const DWORD TID_ReqQryParticipant=0x000043D5;
//会员查询应答
const DWORD TID_RspQryParticipant=0x000043D6;
//合约价位查询
const DWORD TID_ReqQryMBLMarketData=0x000043E1;
//合约价位查询应答
const DWORD TID_RspQryMBLMarketData=0x000043E2;
//信息查询
const DWORD TID_ReqQryInformation=0x000043E3;
//信息查询应答
const DWORD TID_RspQryInformation=0x000043E4;
//交易所状态查询
const DWORD TID_ReqQryExchangeStatus=0x00004801;
//交易所状态应答
const DWORD TID_RspQryExchangeStatus=0x00004802;
//交易所数据同步状态查询
const DWORD TID_ReqQryExchangeDataSyncStatus=0x00004803;
//交易所数据同步状态应答
const DWORD TID_RspQryExchangeDataSyncStatus=0x00004804;
//结算组状态查询
const DWORD TID_ReqQrySettlementGroupStatus=0x00004811;
//结算组状态应答
const DWORD TID_RspQrySettlementGroupStatus=0x00004812;
//信用限额查询请求
const DWORD TID_ReqQryCreditLimit=0x00004813;
//信用限额查询应答
const DWORD TID_RspQryCreditLimit=0x00004814;
//资金帐户入金
const DWORD TID_DbAccountDeposit=0x00003001;
//调整所有合约状态
const DWORD TID_DbUpdateAllInstrumentStatus=0x00003002;
//增加客户
const DWORD TID_DbInsClient=0x00003021;
//修改客户
const DWORD TID_DbUpdClient=0x00003022;
//增加会员客户关系
const DWORD TID_DbInsPartClient=0x00003024;
//删除会员客户关系
const DWORD TID_DbDelPartClient=0x00003025;
//增加会员合约持仓限额
const DWORD TID_DbInsCurrPartPosiLimitDetail=0x00003031;
//修改会员合约持仓限额
const DWORD TID_DbUpdCurrPartPosiLimitDetail=0x00003032;
//删除会员合约持仓限额
const DWORD TID_DbDelCurrPartPosiLimitDetail=0x00003033;
//增加客户合约持仓限额
const DWORD TID_DbInsCurrClientPosiLimitDetail=0x00003041;
//修改客户合约持仓限额
const DWORD TID_DbUpdCurrClientPosiLimitDetail=0x00003042;
//删除客户合约持仓限额
const DWORD TID_DbDelCurrClientPosiLimitDetail=0x00003043;
//增加特殊客户合约持仓限额
const DWORD TID_DbInsCurrSpecialPosiLimitDetail=0x00003051;
//修改特殊客户合约持仓限额
const DWORD TID_DbUpdCurrSpecialPosiLimitDetail=0x00003052;
//删除特殊客户合约持仓限额
const DWORD TID_DbDelCurrSpecialPosiLimitDetail=0x00003053;
//增加保值额度
const DWORD TID_DbInsHedgeDetail=0x00003061;
//更新当前保值额度
const DWORD TID_DbUpdCurrHedge=0x00003062;
//增加交易用户
const DWORD TID_DbInsUser=0x00003071;
//修改交易用户
const DWORD TID_DbUpdUser=0x00003072;
//增加会员产品权限
const DWORD TID_DbInsPartProductRight=0x00003081;
//修改会员产品权限
const DWORD TID_DbUpdPartProductRight=0x00003082;
//删除会员产品权限
const DWORD TID_DbDelPartProductRight=0x00003083;
//增加客户产品权限
const DWORD TID_DbInsClientProductRight=0x00003084;
//修改客户产品权限
const DWORD TID_DbUpdClientProductRight=0x00003085;
//删除客户产品权限
const DWORD TID_DbDelClientProductRight=0x00003086;
//增加会员合约权限
const DWORD TID_DbInsPartInstrumentRight=0x00003091;
//修改会员合约权限
const DWORD TID_DbUpdPartInstrumentRight=0x00003092;
//删除会员合约权限
const DWORD TID_DbDelPartInstrumentRight=0x00003093;
//增加客户合约权限
const DWORD TID_DbInsClientInstrumentRight=0x00003094;
//修改客户合约权限
const DWORD TID_DbUpdClientInstrumentRight=0x00003095;
//删除会员客户权限
const DWORD TID_DbDelClientInstrumentRight=0x00003096;
//增加会员客户产品权限
const DWORD TID_DbInsPartClientProductRight=0x000030F1;
//修改会员客户产品权限
const DWORD TID_DbUpdPartClientProductRight=0x000030F2;
//删除会员客户产品权限
const DWORD TID_DbDelPartClientProductRight=0x000030F3;
//增加会员客户合约权限
const DWORD TID_DbInsPartClientInstrumentRight=0x000030F4;
//修改会员客户合约权限
const DWORD TID_DbUpdPartClientInstrumentRight=0x000030F5;
//删除会员客户合约权限
const DWORD TID_DbDelPartClientInstrumentRight=0x000030F6;
//增加会员合约保证金率
const DWORD TID_DbInsCurrMarginRateDetail=0x000030A1;
//修改会员合约保证金率
const DWORD TID_DbUpdCurrMarginRateDetail=0x000030A2;
//删除会员合约保证金率
const DWORD TID_DbDelCurrMarginRateDetail=0x000030A3;
//数据库发出的最终行情
const DWORD TID_DbUpdMarketData=0x000030B1;
//增加用户IP地址
const DWORD TID_DbInsUserIP=0x000030C1;
//删除用户IP地址
const DWORD TID_DbDelUserIP=0x000030C3;
//增加价格绑定
const DWORD TID_DbInsCurrPriceBanding=0x000030D1;
//修改价格绑定
const DWORD TID_DbUpdCurrPriceBanding=0x000030D2;
//删除价格绑定
const DWORD TID_DbDelCurrPriceBanding=0x000030D3;
//增加会员订阅市场
const DWORD TID_DbInsPartTopicSubscribe=0x000030E1;
//删除会员订阅市场
const DWORD TID_DbDelPartTopicSubscribe=0x000030E3;
//时间同步
const DWORD TID_NtfTimeSync=0x00005001;
//通讯阶段切换通知
const DWORD TID_NtfCommPhaseChange=0x00005002;
//数据中心位置通知
const DWORD TID_NtfDataCenterDesc=0x00005003;
//增加合约通知
const DWORD TID_NtfInsInstrument=0x00005101;
//删除合约通知
const DWORD TID_NtfDelInstrument=0x00005102;
//增加组合合约单腿通知
const DWORD TID_NtfInsCombinationLeg=0x00005103;
//删除组合合约单腿通知
const DWORD TID_NtfDelCombinationLeg=0x00005104;
//别名定义通知
const DWORD TID_NtfAliasDefine=0x0000510A;
//报单通知
const DWORD TID_NtfOrder=0x00005201;
//成交通知
const DWORD TID_NtfTrade=0x00005202;
//报价通知
const DWORD TID_NtfQuote=0x00005203;
//执行宣告通知
const DWORD TID_NtfExecOrder=0x00005204;
//组合报单通知
const DWORD TID_NtfCombOrder=0x00005205;
//合约交易状态改变通知
const DWORD TID_NtfInstrumentStatusUpdate=0x00005211;
//会话删除通知
const DWORD TID_NtfDelUserSession=0x00005313;
//交易所公告请求通知
const DWORD TID_NtfBulletin=0x00005801;
//普通行情通知
const DWORD TID_NtfMarketData=0x00005802;
//深度行情通知
const DWORD TID_NtfDepthMarketData=0x00005803;
//管理报单通知
const DWORD TID_NtfAdminOrder=0x00005A01;
//交易所数据同步开始
const DWORD TID_ExchangeDataSyncStart=0x00006001;
//交易所数据同步结束
const DWORD TID_ExchangeDataSyncEnd=0x00006002;
//交易所
const DWORD TID_InitExchange=0x00006101;
//结算组
const DWORD TID_InitSettlementGroup=0x00006102;
//市场
const DWORD TID_InitMarket=0x00006201;
//市场产品关联
const DWORD TID_InitMarketProduct=0x00006202;
//市场产品组关联
const DWORD TID_InitMarketProductGroup=0x00006203;
//行情主题
const DWORD TID_InitMarketDataTopic=0x00006204;
//会员订阅市场
const DWORD TID_InitPartTopicSubscribe=0x00006205;
//会员
const DWORD TID_InitParticipant=0x00006401;
//用户
const DWORD TID_InitUser=0x00006402;
//客户
const DWORD TID_InitClient=0x00006403;
//会员客户关系
const DWORD TID_InitPartClient=0x00006404;
//用户IP地址
const DWORD TID_InitUserIP=0x00006405;
//行情发布状态
const DWORD TID_InitMdPubStatus=0x00006406;
//别名定义
const DWORD TID_InitAliasDefine=0x00006407;
//结算交易会员关系
const DWORD TID_InitClearingTradingPart=0x00006408;
//用户功能权限
const DWORD TID_InitUserFunctionRight=0x00006409;
//资金账户
const DWORD TID_InitAccount=0x0000640A;
//用户通讯量
const DWORD TID_InitUserCommFlux=0x0000640B;
//结算组数据同步开始
const DWORD TID_SettlementGroupDataSyncStart=0x00007001;
//结算组数据同步结束
const DWORD TID_SettlementGroupDataSyncEnd=0x00007002;
//合约
const DWORD TID_InitInstrument=0x00007103;
//组合交易合约的单腿
const DWORD TID_InitCombinationLeg=0x00007104;
//会员账户关系
const DWORD TID_InitPartRoleAccount=0x00007105;
//会员产品角色
const DWORD TID_InitPartProductRole=0x00007201;
//会员产品交易权限
const DWORD TID_InitPartProductRight=0x00007202;
//会员合约交易权限
const DWORD TID_InitPartInstrumentRight=0x00007203;
//客户产品交易权限
const DWORD TID_InitClientProductRight=0x00007204;
//客户合约交易权限
const DWORD TID_InitClientInstrumentRight=0x00007205;
//会员客户产品交易权限
const DWORD TID_InitPartClientProductRight=0x00007206;
//会员客户合约交易权限
const DWORD TID_InitPartClientInstrumentRight=0x00007207;
//产品属性
const DWORD TID_InitCurrProductProperty=0x00007301;
//合约属性
const DWORD TID_InitCurrInstrumentProperty=0x00007303;
//当前合约价格绑定
const DWORD TID_InitCurrPriceBanding=0x00007304;
//当前合约保证金率
const DWORD TID_InitCurrMarginRate=0x00007305;
//当前合约保证金率的详细内容
const DWORD TID_InitCurrMarginRateDetail=0x00007306;
//当前会员合约限仓
const DWORD TID_InitCurrPartPosiLimit=0x00007307;
//当前会员合约限仓的详细内容
const DWORD TID_InitCurrPartPosiLimitDetail=0x00007308;
//当前客户合约限仓
const DWORD TID_InitCurrClientPosiLimit=0x00007309;
//当前客户合约限仓的详细内容
const DWORD TID_InitCurrClientPosiLimitDetail=0x0000730A;
//当前特殊客户合约限仓
const DWORD TID_InitCurrSpecialPosiLimit=0x0000730B;
//当前特殊客户合约限仓的详细内容
const DWORD TID_InitCurrSpecialPosiLimitDetail=0x0000730C;
//当前合约套期保值属性
const DWORD TID_InitCurrHedgeRule=0x0000730D;
//当前合约交易阶段属性
const DWORD TID_InitCurrTradingSegmentAttr=0x0000730E;
//当前合约熔断属性
const DWORD TID_InitCurrFuse=0x0000730F;
//交易账户信息
const DWORD TID_InitTradingAccount=0x00007401;
//会员合约持仓
const DWORD TID_InitPartPosition=0x00007402;
//客户合约持仓
const DWORD TID_InitClientPosition=0x00007403;
//保值额度量
const DWORD TID_InitHedgeVolume=0x00007404;
//上日遗留报单
const DWORD TID_InitRemainOrder=0x00007405;
//市场行情
const DWORD TID_InitMarketData=0x00007407;
//基础准备金账户
const DWORD TID_InitBaseReserveAccount=0x0000740A;
//当日期货合约期权属性
const DWORD TID_InitCurrInstrumentOption=0x0000740B;
//输入行情信息
const DWORD TID_NtfInputMarketData=0x0000740C;

///获取报单的名称
///@param	tid	报单编号
///@return	报单名称
const char *getPackageName(DWORD tid);

#ifndef FIELD_USE_DEFINE
#define FIELD_USE_DEFINE

#define UNLIMITED_FIELD_OCCUR 1000
#define MAX_PACKAGE_NAME_LEN		100
#define MAX_COMMENT_LEN		100
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
	char packageName[MAX_PACKAGE_NAME_LEN];
	char comment[MAX_COMMENT_LEN];
}	TPackageDefine;

#endif

extern TPackageDefine XTPPackageDefines[];

class CXTPPackageDefineMap: public CHashMap<DWORD, TPackageDefine *, HashInt>
{
public:
	CXTPPackageDefineMap(TPackageDefine *pXTPPackageDefines, int nDefineCount)
	{
		for(int i=0; i<nDefineCount; i++)
		{
			Insert(pXTPPackageDefines->tid, pXTPPackageDefines);
			pXTPPackageDefines++;
		}
	}
};

extern CXTPPackageDefineMap g_XTPPackageDefineMap;
void XTP_DEBUG_BODY(DWORD tid, CFieldSet *pPackage, CLogger *pLogger);
#endif
