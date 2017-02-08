// OfpData.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(_OFPDATA_H)
#define _OFPDATA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OFPDataType.h"

//心跳指令
const WORD OFP_VARY_PingRequest = 0x9999;

struct COFPPingRequestField
{
	//处理机日期
	COFPStringType<8> Date;
	//处理机时间
	COFPStringType<6> Time;
};

void dumpOFPField(COFPPingRequestField *pField);

//用户登录指令
const WORD OFP_VARY_LoginRequest = 0x0401;

struct COFPLoginRequestField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLoginRequestField *pField);

//用户登录指令
const WORD OFP_VARY_LoginV2Request = 0x0401;

struct COFPLoginV2RequestField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Passwd;
	//私有流最大编号
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPLoginV2RequestField *pField);

//用户登录应答
const WORD OFP_VARY_LoginResponse = 0x0501;

struct COFPLoginResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Password;
	//交易员姓名
	COFPStringType<8> Usernm;
	//交易员用最大本地编号
	COFPStringType<8> Localno0;
	//交易系统时间
	COFPStringType<8> Time;
	//交易系统状态
	COFPNumberType<8> Sysstat;
	//所属会员
	COFPStringType<8> Membid;
	//当前交易代码
	COFPStringType<2> Section;
	//交易节状态
	COFPCharType Sstatus;
};

void dumpOFPField(COFPLoginResponseField *pField);

//用户登录应答
const WORD OFP_VARY_LoginV2Response = 0x0501;

struct COFPLoginV2ResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Password;
	//交易员姓名
	COFPStringType<8> Usernm;
	//交易日期
	COFPStringType<8> Date;
	//交易系统时间
	COFPStringType<8> Time;
	//交易系统状态
	COFPNumberType<8> Sysstat;
	//所属会员
	COFPStringType<8> Membid;
	//当前交易代码
	COFPStringType<2> Section;
	//交易节状态
	COFPCharType Sstatus;
	//交易员用最大报单本地编号
	COFPStringType<8> Localno0;
	//私有流最大编号
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPLoginV2ResponseField *pField);

//用户登录失败应答
const WORD OFP_VARY_LoginErrorResponse = 0x0501;

struct COFPLoginErrorResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLoginErrorResponseField *pField);

//用户登录失败应答
const WORD OFP_VARY_LoginV2ErrorResponse = 0x0501;

struct COFPLoginV2ErrorResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Passwd;
	//私有流最大编号
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPLoginV2ErrorResponseField *pField);

//用户登录退出指令
const WORD OFP_VARY_LogoutRequest = 0x0407;

struct COFPLogoutRequestField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLogoutRequestField *pField);

//用户登录退出应答
const WORD OFP_VARY_LogoutResponse = 0x0507;

struct COFPLogoutResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLogoutResponseField *pField);

//用户登录退出失败应答
const WORD OFP_VARY_LogoutErrorResponse = 0x0507;

struct COFPLogoutErrorResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPLogoutErrorResponseField *pField);

//用户口令修改指令
const WORD OFP_VARY_PasswordUpdateRequest = 0x0220;

struct COFPPasswordUpdateRequestField
{
	//交易员
	COFPStringType<15> Userid;
	//旧口令
	COFPStringType<40> OldPasswd;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPPasswordUpdateRequestField *pField);

//用户口令修改应答
const WORD OFP_VARY_PasswordUpdateResponse = 0x0320;

struct COFPPasswordUpdateResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//旧口令
	COFPStringType<40> OldPasswd;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPPasswordUpdateResponseField *pField);

//用户口令修改失败应答
const WORD OFP_VARY_PasswordUpdateErrorResponse = 0x0320;

struct COFPPasswordUpdateErrorResponseField
{
	//交易员
	COFPStringType<15> Userid;
	//旧口令
	COFPStringType<40> OldPasswd;
	//口令
	COFPStringType<40> Passwd;
};

void dumpOFPField(COFPPasswordUpdateErrorResponseField *pField);

//系统警告
const WORD OFP_VARY_SystemWarning = 0x2310;

struct COFPSystemWarningField
{
	//警告信息
	COFPStringType<70> Content;
};

void dumpOFPField(COFPSystemWarningField *pField);

//报单录入指令
const WORD OFP_VARY_OrderInsertRequest = 0x0202;

struct COFPOrderInsertRequestField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderInsertRequestField *pField);

//报单录入指令
const WORD OFP_VARY_OrderInsertNotUseRequest = 0x0202;

struct COFPOrderInsertNotUseRequestField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderInsertNotUseRequestField *pField);

//报单录入应答
const WORD OFP_VARY_OrderInsertResponse = 0x0302;

struct COFPOrderInsertResponseField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Back;
};

void dumpOFPField(COFPOrderInsertResponseField *pField);

//报单录入失败应答
const WORD OFP_VARY_OrderInsertErrorResponse = 0x0302;

struct COFPOrderInsertErrorResponseField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderInsertErrorResponseField *pField);

//报单删除指令
const WORD OFP_VARY_OrderDelRequest = 0x0203;

struct COFPOrderDelRequestField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易员编码
	COFPStringType<15> Userid;
};

void dumpOFPField(COFPOrderDelRequestField *pField);

//报单删除应答
const WORD OFP_VARY_OrderDelResponse = 0x0303;

struct COFPOrderDelResponseField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderDelResponseField *pField);

//报单删除失败应答
const WORD OFP_VARY_OrderDelErrorResponse = 0x0303;

struct COFPOrderDelErrorResponseField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPOrderDelErrorResponseField *pField);

//报单删除找不到失败应答
const WORD OFP_VARY_OrderDelNotFoundResponse = 0x0303;

struct COFPOrderDelNotFoundResponseField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易员编码
	COFPStringType<15> Userid;
};

void dumpOFPField(COFPOrderDelNotFoundResponseField *pField);

//授权报单删除
const WORD OFP_VARY_AuthorizedOrderDelRequest = 0x0250;

struct COFPAuthorizedOrderDelRequestField
{
	//报单系统编号，数字型
	COFPStringType<8> orderid;
};

void dumpOFPField(COFPAuthorizedOrderDelRequestField *pField);

//授权报单删除应答
const WORD OFP_VARY_AuthorizedOrderDelResponse = 0x0350;

struct COFPAuthorizedOrderDelResponseField
{
	//报单系统编号，数字型
	COFPStringType<8> orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPAuthorizedOrderDelResponseField *pField);

//授权报单删除失败应答
const WORD OFP_VARY_AuthorizedOrderDelErrorResponse = 0x0350;

struct COFPAuthorizedOrderDelErrorResponseField
{
	//报单系统编号，数字型
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPAuthorizedOrderDelErrorResponseField *pField);

//国际行情查询
const WORD OFP_VARY_QryInternationalMarketRequest = 0x0205;

struct COFPQryInternationalMarketRequestField
{
	//发送命令交易员
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryInternationalMarketRequestField *pField);

//国际行情查询应答
const WORD OFP_VARY_QryInternationalMarketResponse = 0x0305;

struct COFPQryInternationalMarketResponseField
{
	//文本信息
	COFPStringType<500> content;
};

void dumpOFPField(COFPQryInternationalMarketResponseField *pField);

//国际行情查询失败应答
const WORD OFP_VARY_QryInternationalMarketErrorResponse = 0x0305;

struct COFPQryInternationalMarketErrorResponseField
{
	//发送命令交易员
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryInternationalMarketErrorResponseField *pField);

//橡胶行情查询
const WORD OFP_VARY_QryRubberMarketRequest = 0x0206;

struct COFPQryRubberMarketRequestField
{
	//发送命令交易员
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryRubberMarketRequestField *pField);

//橡胶行情查询应答
const WORD OFP_VARY_QryRubberMarketResponse = 0x0306;

struct COFPQryRubberMarketResponseField
{
	//文本信息
	COFPStringType<500> content;
};

void dumpOFPField(COFPQryRubberMarketResponseField *pField);

//橡胶行情查询失败应答
const WORD OFP_VARY_QryRubberMarketErrorResponse = 0x0306;

struct COFPQryRubberMarketErrorResponseField
{
	//发送命令交易员
	COFPStringType<15> userid;
};

void dumpOFPField(COFPQryRubberMarketErrorResponseField *pField);

//报单修改提醒
const WORD OFP_VARY_MBackOrder = 0x0701;

struct COFPMBackOrderField
{
	//私有流序列号
	COFPNumberType<8> mqid;
	//信息类型
	COFPNumberType<4> cmd;
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//报单状态
	COFPCharType Orderf;
	//报单录入日期
	COFPStringType<8> Orderd;
	//报单录入时间
	COFPStringType<8> Ordert;
	//报单删除时间
	COFPStringType<8> Orderdt;
	//未用
	COFPStringType<20> Filler;
};

void dumpOFPField(COFPMBackOrderField *pField);

//报单修改失败提醒
const WORD OFP_VARY_MBackOrderError = 0x0701;

struct COFPMBackOrderErrorField
{
	//私有流序列号
	COFPNumberType<8> mqid;
	//信息类型
	COFPNumberType<4> cmd;
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//申报价格
	COFPNumberType<6> Orderp;
	//申报手数
	COFPNumberType<6> Orderv;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//买卖方向
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//未用
	COFPStringType<10> Filler;
};

void dumpOFPField(COFPMBackOrderErrorField *pField);

//成交回报
const WORD OFP_VARY_TradeInsert = 0x0702;

struct COFPTradeInsertField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//买卖方向
	COFPCharType Posit;
	//报单申报手数
	COFPNumberType<6> Orderv;
	//报单申报价格
	COFPNumberType<6> Orderp;
	//报单当前成交手数
	COFPNumberType<6> Compv;
	//报单当前成交价格
	COFPNumberType<6> Compp;
	//报单未成交剩余手数
	COFPNumberType<6> Balance;
	//未用
	COFPStringType<2> Comps;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//当前撮合编号
	COFPStringType<8> Matcno;
	//撮合日期
	COFPStringType<8> Compd;
	//撮合时间
	COFPStringType<8> Compt;
};

void dumpOFPField(COFPTradeInsertField *pField);

//成交回报
const WORD OFP_VARY_MBackTrade = 0x0701;

struct COFPMBackTradeField
{
	//私有流序列号
	COFPNumberType<8> mqid;
	//信息类型
	COFPNumberType<4> cmd;
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//买卖方向
	COFPCharType Posit;
	//报单申报手数
	COFPNumberType<6> Orderv;
	//报单申报价格
	COFPNumberType<6> Orderp;
	//报单当前成交手数
	COFPNumberType<6> Compv;
	//报单当前成交价格
	COFPNumberType<6> Compp;
	//客户编码
	COFPStringType<8> Custid;
	//交易员编码
	COFPStringType<15> Userid;
	//本地编号
	COFPStringType<8> Lorderid;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志
	COFPCharType Tjbz;
	//当前撮合编号
	COFPStringType<8> Matcno;
	//撮合日期
	COFPStringType<8> Compd;
	//撮合时间
	COFPStringType<8> Compt;
	//未用
	COFPStringType<20> Filler;
};

void dumpOFPField(COFPMBackTradeField *pField);

//会员保证金查询指令
const WORD OFP_VARY_QryDepositRequest = 0x0207;

struct COFPQryDepositRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryDepositRequestField *pField);

//会员保证金查询应答
const WORD OFP_VARY_QryDepositResponse = 0x0307;

struct COFPQryDepositResponseField
{
	//会员
	COFPStringType<8> Membid;
	//日初资金
	COFPFloatType Margit;
	//未使用
	COFPStringType<15> Credii;
	//买入使用资金
	COFPFloatType Buymar;
	//卖出使用资金
	COFPFloatType Sellma;
	//开仓使用资金
	COFPFloatType Totall;
	//剩余可用资金
	COFPFloatType Closec;
};

void dumpOFPField(COFPQryDepositResponseField *pField);

//会员保证金查询失败应答
const WORD OFP_VARY_QryDepositErrorResponse = 0x0307;

struct COFPQryDepositErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryDepositErrorResponseField *pField);

//保值额度查询指令
const WORD OFP_VARY_QryHedgeRequest = 0x0724;

struct COFPQryHedgeRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeRequestField *pField);

//保值额度查询应答
const WORD OFP_VARY_QryHedgeResponse = 0x0824;

struct COFPQryHedgeResponseField
{
	//交易员所属会员的客户编码
	COFPStringType<8> Custid;
	//交易品种
	COFPStringType<6> Commid;
	//买保值额度申请吨数
	COFPNumberType<8> Brequam;
	//买保值额度使用吨数
	COFPNumberType<8> Buseram;
	//买保值额度剩余吨数
	COFPNumberType<8> Bbalance;
	//卖保值额度申请吨数
	COFPNumberType<8> Srequam;
	//卖保值额度使用吨数
	COFPNumberType<8> Suseram;
	//卖保值额度剩余吨数
	COFPNumberType<8> Sbalance;
};

void dumpOFPField(COFPQryHedgeResponseField *pField);

//保值额度查询失败应答
const WORD OFP_VARY_QryHedgeErrorResponse = 0x0824;

struct COFPQryHedgeErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeErrorResponseField *pField);

//保值额度查询指令
const WORD OFP_VARY_QryHedgeV2Request = 0x501a;

struct COFPQryHedgeV2RequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeV2RequestField *pField);

//保值额度查询应答
const WORD OFP_VARY_QryHedgeV2Response = 0x511a;

struct COFPQryHedgeV2ResponseField
{
	//交易员所属会员编码
	COFPStringType<8> Membid;
	//交易员所属会员的客户编码
	COFPStringType<8> Custid;
	//交易品种
	COFPStringType<6> Commid;
	//买保值额度申请吨数
	COFPNumberType<8> Brequam;
	//买保值额度使用吨数
	COFPNumberType<8> Buseram;
	//买保值额度剩余吨数
	COFPNumberType<8> Bbalance;
	//卖保值额度申请吨数
	COFPNumberType<8> Srequam;
	//卖保值额度使用吨数
	COFPNumberType<8> Suseram;
	//卖保值额度剩余吨数
	COFPNumberType<8> Sbalance;
};

void dumpOFPField(COFPQryHedgeV2ResponseField *pField);

//保值额度查询失败应答
const WORD OFP_VARY_QryHedgeV2ErrorResponse = 0x511a;

struct COFPQryHedgeV2ErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryHedgeV2ErrorResponseField *pField);

//客户资料查询指令
const WORD OFP_VARY_QryClientRequest = 0x1010;

struct COFPQryClientRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryClientRequestField *pField);

//客户资料查询应答
const WORD OFP_VARY_QryClientResponse = 0x1110;

struct COFPQryClientResponseField
{
	//未用
	COFPCharType Rstus;
	//客户编码
	COFPStringType<8> Custid;
	//客户名称
	COFPStringType<50> Custnm;
	//客户地址
	COFPStringType<50> Custad;
	//客户联系电话
	COFPStringType<18> Custtel;
	//客户企业性质
	COFPCharType Tradtp;
	//法人代表
	COFPStringType<8> Reprnm;
	//客户标志
	COFPCharType custle;
	//所属会员
	COFPStringType<8> Emplid;
	//未用
	COFPCharType Credit;
	//是否允许交易
	COFPCharType Trades;
	//未用
	COFPCharType Tradau;
	//开户日期
	COFPStringType<8> Indate;
	//未用
	COFPStringType<8> Modate;
	//未用
	COFPStringType<8> Instaff;
	//未用
	COFPStringType<8> Mostaff;
	//客户类型
	COFPCharType Comple;
	//注册／营运资金
	COFPStringType<15> Regisf;
	//未用
	COFPStringType<8> Floortr;
	//证件号码或身份证号码
	COFPStringType<20> Zjhm;
};

void dumpOFPField(COFPQryClientResponseField *pField);

//客户资料查询失败应答
const WORD OFP_VARY_QryClientErrorResponse = 0x1110;

struct COFPQryClientErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryClientErrorResponseField *pField);

//交易品种查询指令
const WORD OFP_VARY_QryInstrumentRequest = 0x1000;

struct COFPQryInstrumentRequestField
{
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryInstrumentRequestField *pField);

//交易品种查询应答
const WORD OFP_VARY_QryInstrumentResponse = 0x1100;

struct COFPQryInstrumentResponseField
{
	//交易品种代码
	COFPStringType<6> Commid;
	//交易品种名称
	COFPStringType<8> Commnm;
	//交割月份，格式为yymm＋space（2）
	COFPStringType<6> Delim;
	//大类品种的数字编码，如‘01’为铜
	COFPStringType<2> Abbr;
	//每手数量（吨）
	COFPNumberType<6> Trade;
	//最小变动价位
	COFPNumberType<6> Tick;
	//未用，应该是涨跌停板率
	COFPStringType<6> Daill;
	//未用，应该是保值平仓允许开始日期
	COFPStringType<8> Closed;
	//品种类型，‘f’‘F’期货／其他
	COFPCharType Commtp;
	//开始交易日期
	COFPStringType<8> Stard;
	//开始交割日期
	COFPStringType<8> Delid;
	//结束交易日期
	COFPStringType<8> Stopd;
	//报单单笔最大申报手数
	COFPNumberType<6> Posil;
	//品种交易状态，‘a’允许／其他不允许
	COFPCharType Commst;
	//结束交割日期
	COFPStringType<8> Lastde;
	//未用，为‘1．00’
	COFPStringType<4> Margin;
	//未用，为‘0．00’
	COFPStringType<4> Sxfl;
};

void dumpOFPField(COFPQryInstrumentResponseField *pField);

//交易品种查询失败应答
const WORD OFP_VARY_QryInstrumentErrorResponse = 0x1100;

struct COFPQryInstrumentErrorResponseField
{
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryInstrumentErrorResponseField *pField);

//授权报单查询命令
const WORD OFP_VARY_QryAuthorizedOrderRequest = 0x0251;

struct COFPQryAuthorizedOrderRequestField
{
	//指定交易员或会员的编码
	COFPStringType<15> username;
};

void dumpOFPField(COFPQryAuthorizedOrderRequestField *pField);

//授权报单查询应答
const WORD OFP_VARY_QryAuthorizedOrderResponse = 0x0351;

struct COFPQryAuthorizedOrderResponseField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//交易品种
	COFPStringType<6> Commid;
	//买卖方向，‘b’买／‘s’卖
	COFPCharType Posit;
	//报单状态，‘o’有效报单
	COFPCharType Orderf;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志，‘0’保值／‘1’投机
	COFPCharType Tjbz;
	//报单申报手数
	COFPNumberType<6> Orderv;
	//报单申报价格
	COFPNumberType<6> Orderp;
	//客户
	COFPStringType<8> Custid;
	//会员
	COFPStringType<8> Membid;
	//交易员
	COFPStringType<15> Userid;
	//总成交手数
	COFPNumberType<6> Compv;
	//最后一笔成交价格
	COFPNumberType<6> Compp;
	//报单时间
	COFPStringType<8> Ordert;
	//报单删除时间
	COFPStringType<8> DOrdt;
	//报单本地编号
	COFPStringType<8> Lorderid;
};

void dumpOFPField(COFPQryAuthorizedOrderResponseField *pField);

//授权报单查询失败应答
const WORD OFP_VARY_QryAuthorizedOrderErrorResponse = 0x0351;

struct COFPQryAuthorizedOrderErrorResponseField
{
	//指定交易员或会员的编码
	COFPStringType<15> username;
};

void dumpOFPField(COFPQryAuthorizedOrderErrorResponseField *pField);

//报单查询指令
const WORD OFP_VARY_QryOrderRequest = 0x0208;

struct COFPQryOrderRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryOrderRequestField *pField);

//报单查询指令
const WORD OFP_VARY_QryAllOrderRequest = 0x0208;

struct COFPQryAllOrderRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryAllOrderRequestField *pField);

//报单查询应答
const WORD OFP_VARY_QryOrderResponse = 0x0308;

struct COFPQryOrderResponseField
{
	//报单系统编号
	COFPStringType<8> Orderid;
	//报单申报时间
	COFPStringType<8> Ordert;
	//交易品种
	COFPStringType<6> Commid;
	//交割月份，未用
	COFPStringType<6> Delim;
	//买卖方向，‘b’买／‘s’卖
	COFPCharType Posit;
	//报单状态，‘o’有效报单
	COFPCharType Orderf;
	//报单申报手数
	COFPNumberType<6> Orderv;
	//报单申报价格
	COFPNumberType<6> Orderp;
	//总成交手数
	COFPNumberType<6> Compv;
	//最后一笔成交价格
	COFPNumberType<6> Compp;
	//报单剩余手数
	COFPNumberType<6> Balance;
	//客户编码
	COFPStringType<8> Custid;
	//交易员
	COFPStringType<15> Userid;
	//报单本地编号
	COFPStringType<8> Lorderid;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志，‘0’保值／‘1’投机
	COFPCharType Tjbz;
};

void dumpOFPField(COFPQryOrderResponseField *pField);

//报单查询失败应答
const WORD OFP_VARY_QryOrderErrorResponse = 0x0308;

struct COFPQryOrderErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
};

void dumpOFPField(COFPQryOrderErrorResponseField *pField);

//成交单查询指令
const WORD OFP_VARY_QryTradeRequest = 0x5201;

struct COFPQryTradeRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryTradeRequestField *pField);

//成交单查询应答
const WORD OFP_VARY_QryTradeResponse = 0x5301;

struct COFPQryTradeResponseField
{
	//报单本地编号
	COFPStringType<8> Lorderid;
	//交易品种
	COFPStringType<6> Commid;
	//买卖标志，‘b’买／‘s’卖
	COFPCharType Posit;
	//开平仓标志
	COFPCharType Closef;
	//投机保值标志，‘0’保值／‘1’投机
	COFPCharType Tjbz;
	//总成交手数
	COFPNumberType<6> Compv;
	//最后一笔成交价格
	COFPNumberType<6> Compp;
	//客户编码
	COFPStringType<8> Custid;
	//交易员
	COFPStringType<8> Membid;
	//成交日期，格式ccyymmdd
	COFPStringType<8> Compd;
	//成交时间，格式hhmmssuu
	COFPStringType<8> Compt;
	//撮合编号
	COFPStringType<8> Matcno;
	//报单系统编号
	COFPStringType<8> Orderid;
	//报单申报手数
	COFPNumberType<6> Orderv;
	//报单申报价格
	COFPNumberType<6> Orderp;
	//报单时间
	COFPStringType<8> Ordert;
};

void dumpOFPField(COFPQryTradeResponseField *pField);

//成交单查询失败应答
const WORD OFP_VARY_QryTradeErrorResponse = 0x5301;

struct COFPQryTradeErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
};

void dumpOFPField(COFPQryTradeErrorResponseField *pField);

//会员持仓查询指令
const WORD OFP_VARY_QryPPositionRequest = 0x1007;

struct COFPQryPPositionRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryPPositionRequestField *pField);

//会员持仓查询应答
const WORD OFP_VARY_QryPPositionResponse = 0x1107;

struct COFPQryPPositionResponseField
{
	//会员编码
	COFPStringType<8> Membid;
	//客户编码，为ASCII空格
	COFPStringType<8> Custid;
	//交易品种
	COFPStringType<6> Commid;
	//买保值手数
	COFPNumberType<6> Buyvb;
	//买投机手数
	COFPNumberType<6> Buyvt;
	//卖保值手数
	COFPNumberType<6> Sellvb;
	//卖投机手数
	COFPNumberType<6> Sellvt;
	//今买保值新开仓手数
	COFPNumberType<6> Openbvb;
	//今买投机新开仓手数
	COFPNumberType<6> Openbvt;
	//今卖保值新开仓手数
	COFPNumberType<6> Opensvb;
	//今卖投机新开仓手数
	COFPNumberType<6> Opensvt;
	//买保值冻结持仓手数
	COFPNumberType<6> Fbuyvb;
	//买投机冻结持仓手数
	COFPNumberType<6> Fbuyvt;
	//卖保值冻结持仓手数
	COFPNumberType<6> Fsellvb;
	//卖投机冻结持仓手数
	COFPNumberType<6> Fsellvt;
	//前交易日结算价
	COFPNumberType<6> Clearp;
	//未用，保值使用保证金（格式％15．2f）
	COFPFloatType Margamb;
	//未用，投机使用保证金（格式％15．2f）
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryPPositionResponseField *pField);

//会员持仓查询失败应答
const WORD OFP_VARY_QryPPositionErrorResponse = 0x1107;

struct COFPQryPPositionErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryPPositionErrorResponseField *pField);

//简要会员持仓查询指令
const WORD OFP_VARY_QryBriefPPositionRequest = 0x2007;

struct COFPQryBriefPPositionRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPPositionRequestField *pField);

//简要会员持仓查询应答
const WORD OFP_VARY_QryBriefPPositionResponse = 0x2107;

struct COFPQryBriefPPositionResponseField
{
	//会员编码
	COFPStringType<8> Membid;
	//交易品种
	COFPStringType<6> Commid;
	//买保值手数
	COFPNumberType<6> Buyvb;
	//买投机手数
	COFPNumberType<6> Buyvt;
	//卖保值手数
	COFPNumberType<6> Sellvb;
	//卖投机手数
	COFPNumberType<6> Sellvt;
	//前交易日结算价
	COFPNumberType<6> Clearp;
	//未用，保值使用保证金（格式％15．2f）
	COFPFloatType Margamb;
	//未用，投机使用保证金（格式％15．2f）
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryBriefPPositionResponseField *pField);

//简要会员持仓查询失败应答
const WORD OFP_VARY_QryBriefPPositionErrorResponse = 0x2107;

struct COFPQryBriefPPositionErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPPositionErrorResponseField *pField);

//会员客户持仓查询指令
const WORD OFP_VARY_QryPositionRequest = 0x1009;

struct COFPQryPositionRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始客户
	COFPStringType<8> Custid;
	//查询结束客户
	COFPStringType<8> Custidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryPositionRequestField *pField);

//会员客户持仓查询应答
const WORD OFP_VARY_QryPositionResponse = 0x1109;

struct COFPQryPositionResponseField
{
	//会员编码
	COFPStringType<8> Membid;
	//客户编码，为ASCII空格
	COFPStringType<8> Custid;
	//交易品种
	COFPStringType<6> Commid;
	//买保值手数
	COFPNumberType<6> Buyvb;
	//买投机手数
	COFPNumberType<6> Buyvt;
	//卖保值手数
	COFPNumberType<6> Sellvb;
	//卖投机手数
	COFPNumberType<6> Sellvt;
	//今买保值新开仓手数
	COFPNumberType<6> Openbvb;
	//今买投机新开仓手数
	COFPNumberType<6> Openbvt;
	//今卖保值新开仓手数
	COFPNumberType<6> Opensvb;
	//今卖投机新开仓手数
	COFPNumberType<6> Opensvt;
	//买保值冻结持仓手数
	COFPNumberType<6> Fbuyvb;
	//买投机冻结持仓手数
	COFPNumberType<6> Fbuyvt;
	//卖保值冻结持仓手数
	COFPNumberType<6> Fsellvb;
	//卖投机冻结持仓手数
	COFPNumberType<6> Fsellvt;
	//前交易日结算价
	COFPNumberType<6> Clearp;
	//未用，保值使用保证金（格式％15．2f）
	COFPFloatType Margamb;
	//未用，投机使用保证金（格式％15．2f）
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryPositionResponseField *pField);

//会员客户持仓查询失败应答
const WORD OFP_VARY_QryPositionErrorResponse = 0x1109;

struct COFPQryPositionErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始客户
	COFPStringType<8> Custid;
	//查询结束客户
	COFPStringType<8> Custidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryPositionErrorResponseField *pField);

//简要会员客户持仓查询指令
const WORD OFP_VARY_QryBriefPositionRequest = 0x2009;

struct COFPQryBriefPositionRequestField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始客户
	COFPStringType<8> Custid;
	//查询结束客户
	COFPStringType<8> Custidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPositionRequestField *pField);

//简要会员客户持仓查询应答
const WORD OFP_VARY_QryBriefPositionResponse = 0x2109;

struct COFPQryBriefPositionResponseField
{
	//客户编码，为ASCII空格
	COFPStringType<8> Custid;
	//交易品种
	COFPStringType<6> Commid;
	//买保值手数
	COFPNumberType<6> Buyvb;
	//买投机手数
	COFPNumberType<6> Buyvt;
	//卖保值手数
	COFPNumberType<6> Sellvb;
	//卖投机手数
	COFPNumberType<6> Sellvt;
	//前交易日结算价
	COFPNumberType<6> Clearp;
	//未用，保值使用保证金（格式％15．2f）
	COFPFloatType Margamb;
	//未用，投机使用保证金（格式％15．2f）
	COFPFloatType Margamt;
};

void dumpOFPField(COFPQryBriefPositionResponseField *pField);

//简要会员客户持仓查询失败应答
const WORD OFP_VARY_QryBriefPositionErrorResponse = 0x2109;

struct COFPQryBriefPositionErrorResponseField
{
	//查询起始会员
	COFPStringType<8> Membid;
	//查询结束会员
	COFPStringType<8> Membidt;
	//查询起始客户
	COFPStringType<8> Custid;
	//查询结束客户
	COFPStringType<8> Custidt;
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryBriefPositionErrorResponseField *pField);

//品种价位查询指令
const WORD OFP_VARY_QryInstrumentPriceRequest = 0x1006;

struct COFPQryInstrumentPriceRequestField
{
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryInstrumentPriceRequestField *pField);

//品种价位查询应答
const WORD OFP_VARY_QryInstrumentPriceResponse = 0x1106;

struct COFPQryInstrumentPriceResponseField
{
	//买卖报价，‘b’买／‘s’卖
	COFPCharType Bsflag;
	//交易品种
	COFPStringType<6> Commid;
	//报价
	COFPNumberType<6> Orderp;
	//所有申报手数
	COFPNumberType<8> Orderv;
	//所有成交手数
	COFPNumberType<8> Compv;
	//所有撤单手数
	COFPNumberType<8> Cancelv;
	//所有有效手数
	COFPNumberType<8> Currentv;
};

void dumpOFPField(COFPQryInstrumentPriceResponseField *pField);

//品种价位查询失败应答
const WORD OFP_VARY_QryInstrumentPriceErrorResponse = 0x1106;

struct COFPQryInstrumentPriceErrorResponseField
{
	//查询起始交易品种
	COFPStringType<6> Commid;
	//查询结束交易品种
	COFPStringType<6> Commidt;
	//查询选项
	COFPCharType Option;
};

void dumpOFPField(COFPQryInstrumentPriceErrorResponseField *pField);

//交易品种数字编码查询命令
const WORD OFP_VARY_QryInstrumentNumberRequest = 0x1001;

struct COFPQryInstrumentNumberRequestField
{
};

void dumpOFPField(COFPQryInstrumentNumberRequestField *pField);

//交易品种数字编码查询应答
const WORD OFP_VARY_QryInstrumentNumberResponse = 0x1101;

struct COFPQryInstrumentNumberResponseField
{
	//未用，为‘　’
	COFPCharType rstus;
	//交易品种大类代码，如‘cu’，‘al’等
	COFPStringType<2> comm;
	//交易品种大类数字代码，如‘01’、‘02’等
	COFPStringType<2> abbrev;
};

void dumpOFPField(COFPQryInstrumentNumberResponseField *pField);

//交易品种数字编码查失败应答
const WORD OFP_VARY_QryInstrumentNumberErrorResponse = 0x1101;

struct COFPQryInstrumentNumberErrorResponseField
{
};

void dumpOFPField(COFPQryInstrumentNumberErrorResponseField *pField);

//会员私有流回报编号查询指令
const WORD OFP_VARY_QryTrasnferIdRequest = 0x1016;

struct COFPQryTrasnferIdRequestField
{
	//交易员用户
	COFPStringType<15> Userid;
	//会员编号
	COFPStringType<8> Membid;
};

void dumpOFPField(COFPQryTrasnferIdRequestField *pField);

//会员私有流回报编号查询应答
const WORD OFP_VARY_QryTrasnferIdResponse = 0x1116;

struct COFPQryTrasnferIdResponseField
{
	//交易员用户
	COFPStringType<15> Userid;
	//会员编号
	COFPStringType<8> Membid;
	//交易系统会员私有流回报目前最大编号
	COFPNumberType<8> Transferid;
};

void dumpOFPField(COFPQryTrasnferIdResponseField *pField);

//会员私有流回报编号查询失败应答
const WORD OFP_VARY_QryTrasnferIdErrorResponse = 0x1116;

struct COFPQryTrasnferIdErrorResponseField
{
	//交易员用户
	COFPStringType<15> Userid;
	//会员编号
	COFPStringType<8> Membid;
};

void dumpOFPField(COFPQryTrasnferIdErrorResponseField *pField);

//系统开市，之后允许交易员（客户端）登录至交易系统
const WORD OFP_VARY_Start = 0x0502;

struct COFPStartField
{
};

void dumpOFPField(COFPStartField *pField);

//系统开盘，第一次开盘时当前交易节设置为“　”
const WORD OFP_VARY_Open = 0x0503;

struct COFPOpenField
{
};

void dumpOFPField(COFPOpenField *pField);

//系统暂停
const WORD OFP_VARY_Pause = 0x0504;

struct COFPPauseField
{
};

void dumpOFPField(COFPPauseField *pField);

//系统收盘，之后不允许交易员（客户端）登录至交易系统
const WORD OFP_VARY_Close = 0x0505;

struct COFPCloseField
{
};

void dumpOFPField(COFPCloseField *pField);

//系统收市
const WORD OFP_VARY_End = 0x0506;

struct COFPEndField
{
	//未使用，为‘　’
	COFPCharType rstatus;
	//交易节
	COFPStringType<2> sectid;
	//交易节描述
	COFPStringType<20> desc;
	//交易节状态
	COFPCharType sects0;
	//交易节是否收盘集合竞价初始化标志，‘1’是／其他否
	COFPCharType sects1;
	//未使用，为‘　’
	COFPStringType<24> f2;
	//客户端不用知道内容
	COFPStringType<8> starttime;
	//客户端不用知道内容
	COFPStringType<8> endtime;
	//本节铜是否交易，‘1’交易／其他否
	COFPCharType cu;
	//本节铝是否交易，‘1’交易／其他否
	COFPCharType al;
	//本节橡胶是否交易，‘1’交易／其他否
	COFPCharType ru;
	//本节甲板是否交易，‘1’交易／其他否
	COFPCharType pw;
	//本节籼米是否交易，‘1’交易／其他否
	COFPCharType rc;
	//未使用，为‘　’
	COFPStringType<35> f3;
};

void dumpOFPField(COFPEndField *pField);

//系统节初始化
const WORD OFP_VARY_Presect = 0x0521;

struct COFPPresectField
{
};

void dumpOFPField(COFPPresectField *pField);

//系统节开盘
const WORD OFP_VARY_SectionStart = 0x0522;

struct COFPSectionStartField
{
};

void dumpOFPField(COFPSectionStartField *pField);

//系统节收盘
const WORD OFP_VARY_SectionStop = 0x0523;

struct COFPSectionStopField
{
};

void dumpOFPField(COFPSectionStopField *pField);

//系统节开盘集合竞价开始
const WORD OFP_VARY_OpenAuctionSectionStart = 0x0524;

struct COFPOpenAuctionSectionStartField
{
};

void dumpOFPField(COFPOpenAuctionSectionStartField *pField);

//系统节开盘集合竞价结束
const WORD OFP_VARY_OpenAuctionSectionStop = 0x0525;

struct COFPOpenAuctionSectionStopField
{
};

void dumpOFPField(COFPOpenAuctionSectionStopField *pField);

//系统节收盘集合竞价开始
const WORD OFP_VARY_CloseAuctionSectionStart = 0x0526;

struct COFPCloseAuctionSectionStartField
{
};

void dumpOFPField(COFPCloseAuctionSectionStartField *pField);

//系统节开盘集合竞价结束
const WORD OFP_VARY_CloseAuctionSectionStop = 0x0527;

struct COFPCloseAuctionSectionStopField
{
};

void dumpOFPField(COFPCloseAuctionSectionStopField *pField);


///获取命令字理应对应的vary值
///@param	command	命令字
///@return	对应的vary值
WORD GetOFPVary(const char *command);

#endif
