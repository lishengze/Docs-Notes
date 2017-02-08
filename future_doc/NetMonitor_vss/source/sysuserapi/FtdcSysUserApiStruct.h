/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file FtdcStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
///20070227	zhangjie		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(_FTDCSYSSTRUCT_H)
#define _FTDCSYSSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FtdcSysUserApiDataType.h"

///信息分发
struct CShfeFtdcDisseminationField
{
	///序列系列号
	TShfeFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	TShfeFtdcSequenceNoType	SequenceNo;
};

///响应信息
struct CShfeFtdcRspInfoField
{
	///错误代码
	TShfeFtdcErrorIDType	ErrorID;
	///错误信息
	TShfeFtdcErrorMsgType	ErrorMsg;
};

///通讯阶段
struct CShfeFtdcCommPhaseField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///通讯时段号
	TShfeFtdcCommPhaseNoType	CommPhaseNo;
};

///交易所交易日
struct CShfeFtdcExchangeTradingDayField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///交易所代码
	TShfeFtdcExchangeIDType	ExchangeID;
};

///结算会话
struct CShfeFtdcSettlementSessionField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
};

///当前时间
struct CShfeFtdcCurrentTimeField
{
	///当前日期
	TShfeFtdcDateType	CurrDate;
	///当前时间
	TShfeFtdcTimeType	CurrTime;
	///当前时间（毫秒）
	TShfeFtdcMillisecType	CurrMillisec;
};

///用户登录请求
struct CShfeFtdcReqUserLoginField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///密码
	TShfeFtdcPasswordType	Password;
	///用户端产品信息
	TShfeFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TShfeFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///数据中心代码
	TShfeFtdcDataCenterIDType	DataCenterID;
};

///用户登录应答
struct CShfeFtdcRspUserLoginField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///登录成功时间
	TShfeFtdcTimeType	LoginTime;
	///最大本地报单号
	TShfeFtdcOrderLocalIDType	MaxOrderLocalID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易系统名称
	TShfeFtdcTradingSystemNameType	TradingSystemName;
	///数据中心代码
	TShfeFtdcDataCenterIDType	DataCenterID;
	///会员私有流当前长度
	TShfeFtdcSequenceNoType	PrivateFlowSize;
	///交易员私有流当前长度
	TShfeFtdcSequenceNoType	UserFlowSize;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
};

///用户登出请求
struct CShfeFtdcReqUserLogoutField
{
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
};

///用户登出应答
struct CShfeFtdcRspUserLogoutField
{
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
};

///输入报单
struct CShfeFtdcInputOrderField
{
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///报单价格条件
	TShfeFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///组合开平标志
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TShfeFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TShfeFtdcDateType	GTDDate;
	///成交量类型
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TShfeFtdcVolumeType	MinVolume;
	///触发条件
	TShfeFtdcContingentConditionType	ContingentCondition;
	///止损价
	TShfeFtdcPriceType	StopPrice;
	///强平原因
	TShfeFtdcForceCloseReasonType	ForceCloseReason;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///自动挂起标志
	TShfeFtdcBoolType	IsAutoSuspend;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///报单操作
struct CShfeFtdcOrderActionField
{
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///报单操作标志
	TShfeFtdcActionFlagType	ActionFlag;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量变化
	TShfeFtdcVolumeType	VolumeChange;
	///操作本地编号
	TShfeFtdcOrderLocalIDType	ActionLocalID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///OTC报单
struct CShfeFtdcOTCOrderField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///OTC报单编号
	TShfeFtdcOTCOrderSysIDType	OTCOrderSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///开平标志
	TShfeFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///价格
	TShfeFtdcPriceType	Price;
	///数量
	TShfeFtdcVolumeType	Volume;
	///对手方会员代码
	TShfeFtdcParticipantIDType	OtherParticipantID;
	///对手方客户代码
	TShfeFtdcClientIDType	OtherClientID;
	///对手方交易用户代码
	TShfeFtdcUserIDType	OtherUserID;
	///对手方开平标志
	TShfeFtdcOffsetFlagType	OtherOffsetFlag;
	///对手方套保标志
	TShfeFtdcHedgeFlagType	OtherHedgeFlag;
	///本地OTC报单编号
	TShfeFtdcOrderLocalIDType	OTCOrderLocalID;
	///OTC报单状态
	TShfeFtdcOTCOrderStatusType	OTCOrderStatus;
	///插入时间
	TShfeFtdcTimeType	InsertTime;
	///撤销时间
	TShfeFtdcTimeType	CancelTime;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///对手方结算会员编号
	TShfeFtdcParticipantIDType	OtherClearingPartID;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
	///efp对应期货或期权合约代码
	TShfeFtdcInstrumentIDType	EfpInstrumentID;
	///期权行权后是否保留期货头寸的标记
	TShfeFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///交割模式
	TShfeFtdcDeliveryModeType	DeliveryMode;
};

///报单会话
struct CShfeFtdcOrderSessionField
{
	///前置编号
	TShfeFtdcFrontIDType	FrontID;
	///会话编号
	TShfeFtdcSessionIDType	SessionID;
	///请求编号
	TShfeFtdcSequenceNoType	RequestID;
};

///输入报价
struct CShfeFtdcInputQuoteField
{
	///报价编号
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///数量
	TShfeFtdcVolumeType	Volume;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///本地报价编号
	TShfeFtdcOrderLocalIDType	QuoteLocalID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	TShfeFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///买方组合套保标志
	TShfeFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///买方价格
	TShfeFtdcPriceType	BidPrice;
	///卖方组合开平标志
	TShfeFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///卖方组合套保标志
	TShfeFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///卖方价格
	TShfeFtdcPriceType	AskPrice;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///报价操作
struct CShfeFtdcQuoteActionField
{
	///报价编号
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///本地报价编号
	TShfeFtdcOrderLocalIDType	QuoteLocalID;
	///报单操作标志
	TShfeFtdcActionFlagType	ActionFlag;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///操作本地编号
	TShfeFtdcOrderLocalIDType	ActionLocalID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///输入执行宣告
struct CShfeFtdcInputExecOrderField
{
	///合约编号
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///本地执行宣告编号
	TShfeFtdcOrderLocalIDType	ExecOrderLocalID;
	///数量
	TShfeFtdcVolumeType	Volume;
	///开平标志
	TShfeFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///持仓方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TShfeFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TShfeFtdcExecOrderCloseFlagType	CloseFlag;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///执行宣告操作
struct CShfeFtdcExecOrderActionField
{
	///执行宣告编号
	TShfeFtdcExecOrderSysIDType	ExecOrderSysID;
	///本地执行宣告编号
	TShfeFtdcOrderLocalIDType	ExecOrderLocalID;
	///报单操作标志
	TShfeFtdcActionFlagType	ActionFlag;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///操作本地编号
	TShfeFtdcOrderLocalIDType	ActionLocalID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///用户登录退出
struct CShfeFtdcUserLogoutField
{
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
};

///用户口令修改
struct CShfeFtdcUserPasswordUpdateField
{
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///旧密码
	TShfeFtdcPasswordType	OldPassword;
	///新密码
	TShfeFtdcPasswordType	NewPassword;
};

///输入非标组合报单
struct CShfeFtdcInputCombOrderField
{
	///组合报单编号
	TShfeFtdcOrderSysIDType	CombOrderSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	CombOrderLocalID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///合约代码1
	TShfeFtdcInstrumentIDType	InstrumentID1;
	///买卖方向1
	TShfeFtdcDirectionType	Direction1;
	///分腿乘数1
	TShfeFtdcLegMultipleType	LegMultiple1;
	///开平标志1
	TShfeFtdcOffsetFlagType	OffsetFlag1;
	///投机套保标志1
	TShfeFtdcHedgeFlagType	HedgeFlag1;
	///合约代码2
	TShfeFtdcInstrumentIDType	InstrumentID2;
	///买卖方向2
	TShfeFtdcDirectionType	Direction2;
	///分腿乘数2
	TShfeFtdcLegMultipleType	LegMultiple2;
	///开平标志2
	TShfeFtdcOffsetFlagType	OffsetFlag2;
	///投机套保标志2
	TShfeFtdcHedgeFlagType	HedgeFlag2;
	///合约代码3
	TShfeFtdcInstrumentIDType	InstrumentID3;
	///买卖方向3
	TShfeFtdcDirectionType	Direction3;
	///分腿乘数3
	TShfeFtdcLegMultipleType	LegMultiple3;
	///开平标志3
	TShfeFtdcOffsetFlagType	OffsetFlag3;
	///投机套保标志3
	TShfeFtdcHedgeFlagType	HedgeFlag3;
	///合约代码4
	TShfeFtdcInstrumentIDType	InstrumentID4;
	///买卖方向4
	TShfeFtdcDirectionType	Direction4;
	///分腿乘数4
	TShfeFtdcLegMultipleType	LegMultiple4;
	///开平标志4
	TShfeFtdcOffsetFlagType	OffsetFlag4;
	///投机套保标志4
	TShfeFtdcHedgeFlagType	HedgeFlag4;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///强制用户退出
struct CShfeFtdcForceUserExitField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
};

///会员资金帐户入金
struct CShfeFtdcAccountDepositField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///资金账号
	TShfeFtdcAccountIDType	Account;
	///入金金额
	TShfeFtdcMoneyType	Deposit;
};

///报单查询
struct CShfeFtdcQryOrderField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///开始时间
	TShfeFtdcTimeType	TimeStart;
	///结束时间
	TShfeFtdcTimeType	TimeEnd;
};

///报价查询
struct CShfeFtdcQryQuoteField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///报价编号
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
};

///成交查询
struct CShfeFtdcQryTradeField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///起始合约代码
	TShfeFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TShfeFtdcInstrumentIDType	InstIDEnd;
	///成交编号
	TShfeFtdcTradeIDType	TradeID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///开始时间
	TShfeFtdcTimeType	TimeStart;
	///结束时间
	TShfeFtdcTimeType	TimeEnd;
};

///行情查询
struct CShfeFtdcQryMarketDataField
{
	///产品代码
	TShfeFtdcProductIDType	ProductID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
};

///客户查询
struct CShfeFtdcQryClientField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TShfeFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TShfeFtdcClientIDType	ClientIDEnd;
};

///会员持仓查询
struct CShfeFtdcQryPartPositionField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///起始合约代码
	TShfeFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///客户持仓查询
struct CShfeFtdcQryClientPositionField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TShfeFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TShfeFtdcClientIDType	ClientIDEnd;
	///起始合约代码
	TShfeFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TShfeFtdcInstrumentIDType	InstIDEnd;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
};

///交易资金查询
struct CShfeFtdcQryPartAccountField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///资金帐号
	TShfeFtdcAccountIDType	AccountID;
};

///合约查询
struct CShfeFtdcQryInstrumentField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///产品组代码
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///产品代码
	TShfeFtdcProductIDType	ProductID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
};

///合约状态查询
struct CShfeFtdcQryInstrumentStatusField
{
	///起始合约代码
	TShfeFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///结算组状态查询
struct CShfeFtdcQrySGDataSyncStatusField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
};

///用户在线查询
struct CShfeFtdcQryUserSessionField
{
	///起始交易用户代码
	TShfeFtdcUserIDType	UserIDStart;
	///结束交易用户代码
	TShfeFtdcUserIDType	UserIDEnd;
};

///用户查询
struct CShfeFtdcQryUserField
{
	///起始交易用户代码
	TShfeFtdcUserIDType	UserIDStart;
	///结束交易用户代码
	TShfeFtdcUserIDType	UserIDEnd;
};

///公告查询
struct CShfeFtdcQryBulletinField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///市场代码
	TShfeFtdcMarketIDType	MarketID;
	///公告编号
	TShfeFtdcBulletinIDType	BulletinID;
	///公告类型
	TShfeFtdcNewsTypeType	NewsType;
	///紧急程度
	TShfeFtdcNewsUrgencyType	NewsUrgency;
};

///会员查询
struct CShfeFtdcQryParticipantField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
};

///保值额度查询
struct CShfeFtdcQryHedgeVolumeField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TShfeFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TShfeFtdcClientIDType	ClientIDEnd;
	///起始合约代码
	TShfeFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///合约价位查询
struct CShfeFtdcQryMBLMarketDataField
{
	///起始合约代码
	TShfeFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TShfeFtdcInstrumentIDType	InstIDEnd;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
};

///信用限额查询
struct CShfeFtdcQryCreditLimitField
{
	///交易会员编号
	TShfeFtdcParticipantIDType	ParticipantID;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
};

///执行宣告查询
struct CShfeFtdcQryExecOrderField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///执行宣告编号
	TShfeFtdcExecOrderSysIDType	ExecOrderSysID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///开始时间
	TShfeFtdcTimeType	TimeStart;
	///结束时间
	TShfeFtdcTimeType	TimeEnd;
};

///非标组合报单查询
struct CShfeFtdcQryCombOrderField
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///组合报单编号
	TShfeFtdcOrderSysIDType	CombOrderSysID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
};

///会员资金应答
struct CShfeFtdcRspPartAccountField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///上次结算准备金
	TShfeFtdcMoneyType	PreBalance;
	///当前保证金总额
	TShfeFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TShfeFtdcMoneyType	CloseProfit;
	///期权权利金收支
	TShfeFtdcMoneyType	Premium;
	///入金金额
	TShfeFtdcMoneyType	Deposit;
	///出金金额
	TShfeFtdcMoneyType	Withdraw;
	///期货结算准备金
	TShfeFtdcMoneyType	Balance;
	///可提资金
	TShfeFtdcMoneyType	Available;
	///资金帐号
	TShfeFtdcAccountIDType	AccountID;
	///冻结的保证金
	TShfeFtdcMoneyType	FrozenMargin;
	///冻结的权利金
	TShfeFtdcMoneyType	FrozenPremium;
	///基本准备金
	TShfeFtdcMoneyType	BaseReserve;
};

///会员持仓应答
struct CShfeFtdcRspPartPositionField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TShfeFtdcVolumeType	YdPosition;
	///今日持仓
	TShfeFtdcVolumeType	Position;
	///多头冻结
	TShfeFtdcVolumeType	LongFrozen;
	///空头冻结
	TShfeFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TShfeFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TShfeFtdcVolumeType	YdShortFrozen;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
};

///客户持仓应答
struct CShfeFtdcRspClientPositionField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TShfeFtdcVolumeType	YdPosition;
	///今日持仓
	TShfeFtdcVolumeType	Position;
	///多头冻结
	TShfeFtdcVolumeType	LongFrozen;
	///空头冻结
	TShfeFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TShfeFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TShfeFtdcVolumeType	YdShortFrozen;
	///当日买成交量
	TShfeFtdcVolumeType	BuyTradeVolume;
	///当日卖成交量
	TShfeFtdcVolumeType	SellTradeVolume;
	///持仓成本
	TShfeFtdcMoneyType	PositionCost;
	///昨日持仓成本
	TShfeFtdcMoneyType	YdPositionCost;
	///占用的保证金
	TShfeFtdcMoneyType	UseMargin;
	///冻结的保证金
	TShfeFtdcMoneyType	FrozenMargin;
	///多头冻结的保证金
	TShfeFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TShfeFtdcMoneyType	ShortFrozenMargin;
	///冻结的权利金
	TShfeFtdcMoneyType	FrozenPremium;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
};

///合约查询应答
struct CShfeFtdcRspInstrumentField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TShfeFtdcProductIDType	ProductID;
	///产品组代码
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///基础商品代码
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///产品类型
	TShfeFtdcProductClassType	ProductClass;
	///持仓类型
	TShfeFtdcPositionTypeType	PositionType;
	///执行价
	TShfeFtdcPriceType	StrikePrice;
	///期权类型
	TShfeFtdcOptionsTypeType	OptionsType;
	///合约数量乘数
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TShfeFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TShfeFtdcYearType	DeliveryYear;
	///交割月
	TShfeFtdcMonthType	DeliveryMonth;
	///提前月份
	TShfeFtdcAdvanceMonthType	AdvanceMonth;
	///当前是否交易
	TShfeFtdcBoolType	IsTrading;
	///创建日
	TShfeFtdcDateType	CreateDate;
	///上市日
	TShfeFtdcDateType	OpenDate;
	///到期日
	TShfeFtdcDateType	ExpireDate;
	///开始交割日
	TShfeFtdcDateType	StartDelivDate;
	///最后交割日
	TShfeFtdcDateType	EndDelivDate;
	///挂牌基准价
	TShfeFtdcPriceType	BasisPrice;
	///市价单最大下单量
	TShfeFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TShfeFtdcVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	TShfeFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TShfeFtdcVolumeType	MinLimitOrderVolume;
	///最小变动价位
	TShfeFtdcPriceType	PriceTick;
	///交割月自然人开仓
	TShfeFtdcMonthCountType	AllowDelivPersonOpen;
	///币种代码
	TShfeFtdcCurrencyIDType	CurrencyID;
};

///信息查询
struct CShfeFtdcQryInformationField
{
	///起始信息代码
	TShfeFtdcInformationIDType	InformationIDStart;
	///结束信息代码
	TShfeFtdcInformationIDType	InformationIDEnd;
};

///信息查询
struct CShfeFtdcInformationField
{
	///信息编号
	TShfeFtdcInformationIDType	InformationID;
	///序列号
	TShfeFtdcSequenceNoType	SequenceNo;
	///消息正文
	TShfeFtdcContentType	Content;
	///正文长度
	TShfeFtdcContentLengthType	ContentLength;
	///是否完成
	TShfeFtdcBoolType	IsAccomplished;
};

///信用限额
struct CShfeFtdcCreditLimitField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///上次结算准备金
	TShfeFtdcMoneyType	PreBalance;
	///当前保证金总额
	TShfeFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TShfeFtdcMoneyType	CloseProfit;
	///期权权利金收支
	TShfeFtdcMoneyType	Premium;
	///入金金额
	TShfeFtdcMoneyType	Deposit;
	///出金金额
	TShfeFtdcMoneyType	Withdraw;
	///期货结算准备金
	TShfeFtdcMoneyType	Balance;
	///可提资金
	TShfeFtdcMoneyType	Available;
	///交易会员编号
	TShfeFtdcParticipantIDType	ParticipantID;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///冻结的保证金
	TShfeFtdcMoneyType	FrozenMargin;
	///冻结的权利金
	TShfeFtdcMoneyType	FrozenPremium;
};

///客户查询应答
struct CShfeFtdcRspClientField
{
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///原证件号码
	TShfeFtdcIdentifiedCardNoV1Type	UseLess;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///会员号
	TShfeFtdcParticipantIDType	ParticipantID;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
};

///数据流回退
struct CShfeFtdcFlowMessageCancelField
{
	///序列系列号
	TShfeFtdcSequenceSeriesType	SequenceSeries;
	///交易日
	TShfeFtdcDateType	TradingDay;
	///数据中心代码
	TShfeFtdcDataCenterIDType	DataCenterID;
	///回退起始序列号
	TShfeFtdcSequenceNoType	StartSequenceNo;
	///回退结束序列号
	TShfeFtdcSequenceNoType	EndSequenceNo;
};

///汇率查询
struct CShfeFtdcQryExchangeRateField
{
	///币种代码
	TShfeFtdcCurrencyIDType	CurrencyID;
};

///汇率查询应答
struct CShfeFtdcRspExchangeRateField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///币种代码
	TShfeFtdcCurrencyIDType	CurrencyID;
	///外汇交易单位
	TShfeFtdcRateUnitType	RateUnit;
	///外汇中间价
	TShfeFtdcExRatePriceType	RatePrice;
};

///会员
struct CShfeFtdcParticipantField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///会员简称
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///会员类型
	TShfeFtdcMemberTypeType	MemberType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
};

///用户
struct CShfeFtdcUserField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///交易用户类型
	TShfeFtdcUserTypeType	UserType;
	///密码
	TShfeFtdcPasswordType	Password;
	///交易员权限
	TShfeFtdcUserActiveType	IsActive;
	///交易员是否禁止直接连接前置
	TShfeFtdcBoolType	IsDirectConnForbidden;
};

///客户
struct CShfeFtdcClientField
{
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
};

///用户会话
struct CShfeFtdcUserSessionField
{
	///前置编号
	TShfeFtdcFrontIDType	FrontID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///交易用户类型
	TShfeFtdcUserTypeType	UserType;
	///会话编号
	TShfeFtdcSessionIDType	SessionID;
	///登录时间
	TShfeFtdcTimeType	LoginTime;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///用户端产品信息
	TShfeFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TShfeFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///会话类型
	TShfeFtdcSessionTypeType	SessionType;
};

///产品组
struct CShfeFtdcProductGroupField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///产品组代码
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///产品组名称
	TShfeFtdcProductGroupNameType	ProductGroupName;
	///商品代码
	TShfeFtdcCommodityIDType	CommodityID;
};

///产品
struct CShfeFtdcProductField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TShfeFtdcProductIDType	ProductID;
	///产品组代码
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///产品名称
	TShfeFtdcProductNameType	ProductName;
	///产品类型
	TShfeFtdcProductClassType	ProductClass;
};

///合约
struct CShfeFtdcInstrumentField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///产品代码
	TShfeFtdcProductIDType	ProductID;
	///产品组代码
	TShfeFtdcProductGroupIDType	ProductGroupID;
	///基础商品代码
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///产品类型
	TShfeFtdcProductClassType	ProductClass;
	///持仓类型
	TShfeFtdcPositionTypeType	PositionType;
	///执行价
	TShfeFtdcPriceType	StrikePrice;
	///期权类型
	TShfeFtdcOptionsTypeType	OptionsType;
	///合约数量乘数
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///合约名称
	TShfeFtdcInstrumentNameType	InstrumentName;
	///交割年份
	TShfeFtdcYearType	DeliveryYear;
	///交割月
	TShfeFtdcMonthType	DeliveryMonth;
	///提前月份
	TShfeFtdcAdvanceMonthType	AdvanceMonth;
	///当前是否交易
	TShfeFtdcBoolType	IsTrading;
	///币种代码
	TShfeFtdcCurrencyIDType	CurrencyID;
};

///组合交易合约的单腿
struct CShfeFtdcCombinationLegField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///组合合约代码
	TShfeFtdcInstrumentIDType	CombInstrumentID;
	///单腿编号
	TShfeFtdcLegIDType	LegID;
	///单腿合约代码
	TShfeFtdcInstrumentIDType	LegInstrumentID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///单腿乘数
	TShfeFtdcLegMultipleType	LegMultiple;
	///推导层数
	TShfeFtdcImplyLevelType	ImplyLevel;
};

///账户资金信息
struct CShfeFtdcAccountInfoField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///上次结算准备金
	TShfeFtdcMoneyType	PreBalance;
	///当前保证金总额
	TShfeFtdcMoneyType	CurrMargin;
	///平仓盈亏
	TShfeFtdcMoneyType	CloseProfit;
	///期权权利金收支
	TShfeFtdcMoneyType	Premium;
	///入金金额
	TShfeFtdcMoneyType	Deposit;
	///出金金额
	TShfeFtdcMoneyType	Withdraw;
	///期货结算准备金
	TShfeFtdcMoneyType	Balance;
	///可提资金
	TShfeFtdcMoneyType	Available;
	///开户日期
	TShfeFtdcDateType	DateAccountOpen;
	///上次结算的日期
	TShfeFtdcDateType	PreDate;
	///上结算的编号
	TShfeFtdcSettlementIDType	PreSettlementID;
	///上次保证金总额
	TShfeFtdcMoneyType	PreMargin;
	///期货保证金
	TShfeFtdcMoneyType	FuturesMargin;
	///期权保证金
	TShfeFtdcMoneyType	OptionsMargin;
	///持仓盈亏
	TShfeFtdcMoneyType	PositionProfit;
	///当日盈亏
	TShfeFtdcMoneyType	Profit;
	///利息收入
	TShfeFtdcMoneyType	Interest;
	///手续费
	TShfeFtdcMoneyType	Fee;
	///总质押金额
	TShfeFtdcMoneyType	TotalCollateral;
	///用质押抵的保证金金额
	TShfeFtdcMoneyType	CollateralForMargin;
	///上次资金利息积数
	TShfeFtdcMoneyType	PreAccmulateInterest;
	///资金利息积数
	TShfeFtdcMoneyType	AccumulateInterest;
	///质押手续费积数
	TShfeFtdcMoneyType	AccumulateFee;
	///冻结资金
	TShfeFtdcMoneyType	ForzenDeposit;
	///帐户状态
	TShfeFtdcAccountStatusType	AccountStatus;
	///资金帐号
	TShfeFtdcAccountIDType	AccountID;
};

///会员合约持仓
struct CShfeFtdcPartPositionField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TShfeFtdcVolumeType	YdPosition;
	///今日持仓
	TShfeFtdcVolumeType	Position;
	///多头冻结
	TShfeFtdcVolumeType	LongFrozen;
	///空头冻结
	TShfeFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TShfeFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TShfeFtdcVolumeType	YdShortFrozen;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
};

///客户合约持仓
struct CShfeFtdcClientPositionField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///持仓多空方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///上日持仓
	TShfeFtdcVolumeType	YdPosition;
	///今日持仓
	TShfeFtdcVolumeType	Position;
	///多头冻结
	TShfeFtdcVolumeType	LongFrozen;
	///空头冻结
	TShfeFtdcVolumeType	ShortFrozen;
	///昨日多头冻结
	TShfeFtdcVolumeType	YdLongFrozen;
	///昨日空头冻结
	TShfeFtdcVolumeType	YdShortFrozen;
	///当日买成交量
	TShfeFtdcVolumeType	BuyTradeVolume;
	///当日卖成交量
	TShfeFtdcVolumeType	SellTradeVolume;
	///持仓成本
	TShfeFtdcMoneyType	PositionCost;
	///昨日持仓成本
	TShfeFtdcMoneyType	YdPositionCost;
	///占用的保证金
	TShfeFtdcMoneyType	UseMargin;
	///冻结的保证金
	TShfeFtdcMoneyType	FrozenMargin;
	///多头冻结的保证金
	TShfeFtdcMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	TShfeFtdcMoneyType	ShortFrozenMargin;
	///冻结的权利金
	TShfeFtdcMoneyType	FrozenPremium;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
};

///保值额度量
struct CShfeFtdcHedgeVolumeField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///多头保值额度最初申请量
	TShfeFtdcVolumeType	LongVolumeOriginal;
	///空头保值额度最初申请量
	TShfeFtdcVolumeType	ShortVolumeOriginal;
	///多头保值额度
	TShfeFtdcVolumeType	LongVolume;
	///空头保值额度
	TShfeFtdcVolumeType	ShortVolume;
};

///市场行情
struct CShfeFtdcMarketDataField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///最新价
	TShfeFtdcPriceType	LastPrice;
	///昨结算
	TShfeFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TShfeFtdcPriceType	PreClosePrice;
	///昨持仓量
	TShfeFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TShfeFtdcPriceType	OpenPrice;
	///最高价
	TShfeFtdcPriceType	HighestPrice;
	///最低价
	TShfeFtdcPriceType	LowestPrice;
	///数量
	TShfeFtdcVolumeType	Volume;
	///成交金额
	TShfeFtdcMoneyType	Turnover;
	///持仓量
	TShfeFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TShfeFtdcPriceType	ClosePrice;
	///今结算
	TShfeFtdcPriceType	SettlementPrice;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
	///昨虚实度
	TShfeFtdcRatioType	PreDelta;
	///今虚实度
	TShfeFtdcRatioType	CurrDelta;
	///最后修改时间
	TShfeFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TShfeFtdcMillisecType	UpdateMillisec;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
};

///深度市场行情
struct CShfeFtdcDepthMarketDataField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///最新价
	TShfeFtdcPriceType	LastPrice;
	///昨结算
	TShfeFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TShfeFtdcPriceType	PreClosePrice;
	///昨持仓量
	TShfeFtdcLargeVolumeType	PreOpenInterest;
	///今开盘
	TShfeFtdcPriceType	OpenPrice;
	///最高价
	TShfeFtdcPriceType	HighestPrice;
	///最低价
	TShfeFtdcPriceType	LowestPrice;
	///数量
	TShfeFtdcVolumeType	Volume;
	///成交金额
	TShfeFtdcMoneyType	Turnover;
	///持仓量
	TShfeFtdcLargeVolumeType	OpenInterest;
	///今收盘
	TShfeFtdcPriceType	ClosePrice;
	///今结算
	TShfeFtdcPriceType	SettlementPrice;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
	///昨虚实度
	TShfeFtdcRatioType	PreDelta;
	///今虚实度
	TShfeFtdcRatioType	CurrDelta;
	///最后修改时间
	TShfeFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TShfeFtdcMillisecType	UpdateMillisec;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///申买价一
	TShfeFtdcPriceType	BidPrice1;
	///申买量一
	TShfeFtdcVolumeType	BidVolume1;
	///申卖价一
	TShfeFtdcPriceType	AskPrice1;
	///申卖量一
	TShfeFtdcVolumeType	AskVolume1;
	///申买价二
	TShfeFtdcPriceType	BidPrice2;
	///申买量二
	TShfeFtdcVolumeType	BidVolume2;
	///申卖价二
	TShfeFtdcPriceType	AskPrice2;
	///申卖量二
	TShfeFtdcVolumeType	AskVolume2;
	///申买价三
	TShfeFtdcPriceType	BidPrice3;
	///申买量三
	TShfeFtdcVolumeType	BidVolume3;
	///申卖价三
	TShfeFtdcPriceType	AskPrice3;
	///申卖量三
	TShfeFtdcVolumeType	AskVolume3;
	///申买价四
	TShfeFtdcPriceType	BidPrice4;
	///申买量四
	TShfeFtdcVolumeType	BidVolume4;
	///申卖价四
	TShfeFtdcPriceType	AskPrice4;
	///申卖量四
	TShfeFtdcVolumeType	AskVolume4;
	///申买价五
	TShfeFtdcPriceType	BidPrice5;
	///申买量五
	TShfeFtdcVolumeType	BidVolume5;
	///申卖价五
	TShfeFtdcPriceType	AskPrice5;
	///申卖量五
	TShfeFtdcVolumeType	AskVolume5;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
};

///分价表
struct CShfeFtdcMBLMarketDataField
{
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///价格
	TShfeFtdcPriceType	Price;
	///数量
	TShfeFtdcVolumeType	Volume;
};

///别名定义
struct CShfeFtdcAliasDefineField
{
	///起始位置
	TShfeFtdcStartPosType	StartPos;
	///别名
	TShfeFtdcAliasType	Alias;
	///原文
	TShfeFtdcOriginalTextType	OriginalText;
};

///行情基础属性
struct CShfeFtdcMarketDataBaseField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///昨结算
	TShfeFtdcPriceType	PreSettlementPrice;
	///昨收盘
	TShfeFtdcPriceType	PreClosePrice;
	///昨持仓量
	TShfeFtdcLargeVolumeType	PreOpenInterest;
	///昨虚实度
	TShfeFtdcRatioType	PreDelta;
};

///行情静态属性
struct CShfeFtdcMarketDataStaticField
{
	///今开盘
	TShfeFtdcPriceType	OpenPrice;
	///最高价
	TShfeFtdcPriceType	HighestPrice;
	///最低价
	TShfeFtdcPriceType	LowestPrice;
	///今收盘
	TShfeFtdcPriceType	ClosePrice;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
	///今结算
	TShfeFtdcPriceType	SettlementPrice;
	///今虚实度
	TShfeFtdcRatioType	CurrDelta;
};

///行情最新成交属性
struct CShfeFtdcMarketDataLastMatchField
{
	///最新价
	TShfeFtdcPriceType	LastPrice;
	///数量
	TShfeFtdcVolumeType	Volume;
	///成交金额
	TShfeFtdcMoneyType	Turnover;
	///持仓量
	TShfeFtdcLargeVolumeType	OpenInterest;
};

///行情最优价属性
struct CShfeFtdcMarketDataBestPriceField
{
	///申买价一
	TShfeFtdcPriceType	BidPrice1;
	///申买量一
	TShfeFtdcVolumeType	BidVolume1;
	///申卖价一
	TShfeFtdcPriceType	AskPrice1;
	///申卖量一
	TShfeFtdcVolumeType	AskVolume1;
};

///行情申买二、三属性
struct CShfeFtdcMarketDataBid23Field
{
	///申买价二
	TShfeFtdcPriceType	BidPrice2;
	///申买量二
	TShfeFtdcVolumeType	BidVolume2;
	///申买价三
	TShfeFtdcPriceType	BidPrice3;
	///申买量三
	TShfeFtdcVolumeType	BidVolume3;
};

///行情申卖二、三属性
struct CShfeFtdcMarketDataAsk23Field
{
	///申卖价二
	TShfeFtdcPriceType	AskPrice2;
	///申卖量二
	TShfeFtdcVolumeType	AskVolume2;
	///申卖价三
	TShfeFtdcPriceType	AskPrice3;
	///申卖量三
	TShfeFtdcVolumeType	AskVolume3;
};

///行情申买四、五属性
struct CShfeFtdcMarketDataBid45Field
{
	///申买价四
	TShfeFtdcPriceType	BidPrice4;
	///申买量四
	TShfeFtdcVolumeType	BidVolume4;
	///申买价五
	TShfeFtdcPriceType	BidPrice5;
	///申买量五
	TShfeFtdcVolumeType	BidVolume5;
};

///行情申卖四、五属性
struct CShfeFtdcMarketDataAsk45Field
{
	///申卖价四
	TShfeFtdcPriceType	AskPrice4;
	///申卖量四
	TShfeFtdcVolumeType	AskVolume4;
	///申卖价五
	TShfeFtdcPriceType	AskPrice5;
	///申卖量五
	TShfeFtdcVolumeType	AskVolume5;
};

///行情更新时间属性
struct CShfeFtdcMarketDataUpdateTimeField
{
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TShfeFtdcTimeType	UpdateTime;
	///最后修改毫秒
	TShfeFtdcMillisecType	UpdateMillisec;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
};

///报价
struct CShfeFtdcQuoteField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///报价编号
	TShfeFtdcQuoteSysIDType	QuoteSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///数量
	TShfeFtdcVolumeType	Volume;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///本地报价编号
	TShfeFtdcOrderLocalIDType	QuoteLocalID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	TShfeFtdcCombOffsetFlagType	BidCombOffsetFlag;
	///买方组合套保标志
	TShfeFtdcCombHedgeFlagType	BidCombHedgeFlag;
	///买方价格
	TShfeFtdcPriceType	BidPrice;
	///卖方组合开平标志
	TShfeFtdcCombOffsetFlagType	AskCombOffsetFlag;
	///卖方组合套保标志
	TShfeFtdcCombHedgeFlagType	AskCombHedgeFlag;
	///卖方价格
	TShfeFtdcPriceType	AskPrice;
	///插入时间
	TShfeFtdcTimeType	InsertTime;
	///撤销时间
	TShfeFtdcTimeType	CancelTime;
	///成交时间
	TShfeFtdcTimeType	TradeTime;
	///买方报单编号
	TShfeFtdcOrderSysIDType	BidOrderSysID;
	///卖方报单编号
	TShfeFtdcOrderSysIDType	AskOrderSysID;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///成交
struct CShfeFtdcTradeField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///成交编号
	TShfeFtdcTradeIDType	TradeID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///资金帐号
	TShfeFtdcAccountIDType	AccountID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///开平标志
	TShfeFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///价格
	TShfeFtdcPriceType	Price;
	///数量
	TShfeFtdcVolumeType	Volume;
	///成交时间
	TShfeFtdcTimeType	TradeTime;
	///成交类型
	TShfeFtdcTradeTypeType	TradeType;
	///成交价来源
	TShfeFtdcPriceSourceType	PriceSource;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
};

///报单
struct CShfeFtdcOrderField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///报单价格条件
	TShfeFtdcOrderPriceTypeType	OrderPriceType;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///组合开平标志
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TShfeFtdcTimeConditionType	TimeCondition;
	///GTD日期
	TShfeFtdcDateType	GTDDate;
	///成交量类型
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TShfeFtdcVolumeType	MinVolume;
	///触发条件
	TShfeFtdcContingentConditionType	ContingentCondition;
	///止损价
	TShfeFtdcPriceType	StopPrice;
	///强平原因
	TShfeFtdcForceCloseReasonType	ForceCloseReason;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///自动挂起标志
	TShfeFtdcBoolType	IsAutoSuspend;
	///报单来源
	TShfeFtdcOrderSourceType	OrderSource;
	///报单状态
	TShfeFtdcOrderStatusType	OrderStatus;
	///报单类型
	TShfeFtdcOrderTypeType	OrderType;
	///今成交数量
	TShfeFtdcVolumeType	VolumeTraded;
	///剩余数量
	TShfeFtdcVolumeType	VolumeTotal;
	///报单日期
	TShfeFtdcDateType	InsertDate;
	///插入时间
	TShfeFtdcTimeType	InsertTime;
	///激活时间
	TShfeFtdcTimeType	ActiveTime;
	///挂起时间
	TShfeFtdcTimeType	SuspendTime;
	///最后修改时间
	TShfeFtdcTimeType	UpdateTime;
	///撤销时间
	TShfeFtdcTimeType	CancelTime;
	///最后修改交易用户代码
	TShfeFtdcUserIDType	ActiveUserID;
	///优先权
	TShfeFtdcPriorityType	Priority;
	///按时间排队的序号
	TShfeFtdcTimeSortIDType	TimeSortID;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///执行宣告
struct CShfeFtdcExecOrderField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///合约编号
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///本地执行宣告编号
	TShfeFtdcOrderLocalIDType	ExecOrderLocalID;
	///数量
	TShfeFtdcVolumeType	Volume;
	///开平标志
	TShfeFtdcOffsetFlagType	OffsetFlag;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///持仓方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	TShfeFtdcExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	TShfeFtdcExecOrderCloseFlagType	CloseFlag;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///执行宣告编号
	TShfeFtdcExecOrderSysIDType	ExecOrderSysID;
	///报单日期
	TShfeFtdcDateType	InsertDate;
	///插入时间
	TShfeFtdcTimeType	InsertTime;
	///撤销时间
	TShfeFtdcTimeType	CancelTime;
	///执行结果
	TShfeFtdcExecResultType	ExecResult;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///非标组合报单
struct CShfeFtdcCombOrderField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///组合报单编号
	TShfeFtdcOrderSysIDType	CombOrderSysID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	CombOrderLocalID;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///合约代码1
	TShfeFtdcInstrumentIDType	InstrumentID1;
	///买卖方向1
	TShfeFtdcDirectionType	Direction1;
	///分腿乘数1
	TShfeFtdcLegMultipleType	LegMultiple1;
	///开平标志1
	TShfeFtdcOffsetFlagType	OffsetFlag1;
	///投机套保标志1
	TShfeFtdcHedgeFlagType	HedgeFlag1;
	///合约代码2
	TShfeFtdcInstrumentIDType	InstrumentID2;
	///买卖方向2
	TShfeFtdcDirectionType	Direction2;
	///分腿乘数2
	TShfeFtdcLegMultipleType	LegMultiple2;
	///开平标志2
	TShfeFtdcOffsetFlagType	OffsetFlag2;
	///投机套保标志2
	TShfeFtdcHedgeFlagType	HedgeFlag2;
	///合约代码3
	TShfeFtdcInstrumentIDType	InstrumentID3;
	///买卖方向3
	TShfeFtdcDirectionType	Direction3;
	///分腿乘数3
	TShfeFtdcLegMultipleType	LegMultiple3;
	///开平标志3
	TShfeFtdcOffsetFlagType	OffsetFlag3;
	///投机套保标志3
	TShfeFtdcHedgeFlagType	HedgeFlag3;
	///合约代码4
	TShfeFtdcInstrumentIDType	InstrumentID4;
	///买卖方向4
	TShfeFtdcDirectionType	Direction4;
	///分腿乘数4
	TShfeFtdcLegMultipleType	LegMultiple4;
	///开平标志4
	TShfeFtdcOffsetFlagType	OffsetFlag4;
	///投机套保标志4
	TShfeFtdcHedgeFlagType	HedgeFlag4;
	///报单来源
	TShfeFtdcOrderSourceType	OrderSource;
	///今成交数量
	TShfeFtdcVolumeType	VolumeTraded;
	///剩余数量
	TShfeFtdcVolumeType	VolumeTotal;
	///报单日期
	TShfeFtdcDateType	InsertDate;
	///插入时间
	TShfeFtdcTimeType	InsertTime;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///本地业务标识
	TShfeFtdcBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	TShfeFtdcDateType	ActionDay;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///Mac地址
	TShfeFtdcMacAddressType	MacAddress;
};

///管理报单
struct CShfeFtdcAdminOrderField
{
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///管理报单命令
	TShfeFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///交易会员编号
	TShfeFtdcParticipantIDType	ParticipantID;
	///金额
	TShfeFtdcMoneyType	Amount;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
};

///管理报单输入
struct CShfeFtdcInputAdminOrderField
{
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///管理报单命令
	TShfeFtdcAdminOrderCommandFlagType	AdminOrderCommand;
	///结算会员编号
	TShfeFtdcParticipantIDType	ClearingPartID;
	///交易会员编号
	TShfeFtdcParticipantIDType	ParticipantID;
	///金额
	TShfeFtdcMoneyType	Amount;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
};

///公告
struct CShfeFtdcBulletinField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///公告编号
	TShfeFtdcBulletinIDType	BulletinID;
	///序列号
	TShfeFtdcSequenceNoType	SequenceNo;
	///公告类型
	TShfeFtdcNewsTypeType	NewsType;
	///紧急程度
	TShfeFtdcNewsUrgencyType	NewsUrgency;
	///发送时间
	TShfeFtdcTimeType	SendTime;
	///消息摘要
	TShfeFtdcAbstractType	Abstract;
	///消息来源
	TShfeFtdcComeFromType	ComeFrom;
	///消息正文
	TShfeFtdcContentType	Content;
	///WEB地址
	TShfeFtdcURLLinkType	URLLink;
	///市场代码
	TShfeFtdcMarketIDType	MarketID;
};

///交易所数据同步状态
struct CShfeFtdcExchangeDataSyncStatusField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///交易所代码
	TShfeFtdcExchangeIDType	ExchangeID;
	///交易所数据同步状态
	TShfeFtdcExchangeDataSyncStatusType	ExchangeDataSyncStatus;
};

///结算组数据同步状态
struct CShfeFtdcSGDataSyncStatusField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///交易日
	TShfeFtdcDateType	TradingDay;
	///结算编号
	TShfeFtdcSettlementIDType	SettlementID;
	///结算组数据同步状态
	TShfeFtdcSGDataSyncStatusType	SGDataSyncStatus;
};

///合约状态
struct CShfeFtdcInstrumentStatusField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	TShfeFtdcTimeType	EnterTime;
	///进入本状态原因
	TShfeFtdcInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	TShfeFtdcDateType	EnterDate;
};

///客户持仓查询
struct CShfeFtdcQryClientPositionV1Field
{
	///起始会员代码
	TShfeFtdcParticipantIDType	PartIDStart;
	///结束会员代码
	TShfeFtdcParticipantIDType	PartIDEnd;
	///起始客户代码
	TShfeFtdcClientIDType	ClientIDStart;
	///结束客户代码
	TShfeFtdcClientIDType	ClientIDEnd;
	///起始合约代码
	TShfeFtdcInstrumentIDType	InstIDStart;
	///结束合约代码
	TShfeFtdcInstrumentIDType	InstIDEnd;
};

///用户流控参数
struct CShfeFtdcUserCommFluxControlField
{
	///最大交易报文速度
	TShfeFtdcCommFluxType	MaxTradeCommFlux;
	///最大交易在途报文数目
	TShfeFtdcCommFluxType	MaxTradeOnWayCommFlux;
	///最大查询报文速度
	TShfeFtdcCommFluxType	MaxQueryCommFlux;
	///最大查询在途报文数目
	TShfeFtdcCommFluxType	MaxQueryOnWayCommFlux;
};

///回路度量
struct CShfeFtdcLoopMeasureField
{
	///用户编号
	TShfeFtdcUserIDType	UserID;
	///会话类型
	TShfeFtdcSessionTypeType	SessionType;
	///度量序列号
	TShfeFtdcSequenceNoType	MeasureSeq;
	///前置编号
	TShfeFtdcFrontIDType	FrontID;
	///会话编号
	TShfeFtdcSessionIDType	SessionID;
};

///节点度量
struct CShfeFtdcNodeMeasureField
{
	///节点标记 
	TShfeFtdcBusinessUnitType	NodeID;
	///阶段编号
	TShfeFtdcPeriodIDType	PeriodID;
	///回路报文度量时间点
	TShfeFtdcMeasureSecType	Sec;
	///回路报文度量时间点微秒值
	TShfeFtdcMeasureUsecType	Usec;
};

///行情代理信息
struct CShfeFtdcMDProxyField
{
	///代理编号
	TShfeFtdcFrontIDType	ProxyID;
	///上一层代理会话编号
	TShfeFtdcSessionIDType	UpperProxySessionID;
	///代理会话编号
	TShfeFtdcSessionIDType	CurrProxySessionID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///请求编号
	TShfeFtdcSequenceNoType	RequestID;
	///代理深度
	TShfeFtdcDepthType	Depth;
	///连接状态
	TShfeFtdcSessionStatusType	SessionStatus;
	///删除的会话编号
	TShfeFtdcSessionIDType	DeletedSessionID;
	///最大通讯量
	TShfeFtdcCommFluxType	MaxCommFlux;
};

///CPU资源使用查询
struct CShfeFtdcReqQryTopCpuInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///CPU资源使用信息
struct CShfeFtdcRspQryTopCpuInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///CPU的编号
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcRatioType	LOAD;
	///
	TShfeFtdcRatioType	USER;
	///
	TShfeFtdcRatioType	NICE;
	///
	TShfeFtdcRatioType	SYS;
	///
	TShfeFtdcRatioType	IDLE;
	///
	TShfeFtdcRatioType	BLOCK;
	///
	TShfeFtdcRatioType	SWAIT;
	///
	TShfeFtdcRatioType	INTR;
	///
	TShfeFtdcRatioType	SSYS;
};

///CPU资源使用信息
struct CShfeFtdcRtnTopCpuInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///CPU的编号
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcRatioType	LOAD;
	///
	TShfeFtdcRatioType	USER;
	///
	TShfeFtdcRatioType	NICE;
	///
	TShfeFtdcRatioType	SYS;
	///
	TShfeFtdcRatioType	IDLE;
	///
	TShfeFtdcRatioType	BLOCK;
	///
	TShfeFtdcRatioType	SWAIT;
	///
	TShfeFtdcRatioType	INTR;
	///
	TShfeFtdcRatioType	SSYS;
};

///Mem资源使用查询
struct CShfeFtdcReqQryTopMemInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///Mem资源使用信息
struct CShfeFtdcRspQryTopMemInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///Total Real Memory
	TShfeFtdcVolumeType	TOTALREAL;
	///Active Real Memory
	TShfeFtdcVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	TShfeFtdcVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	TShfeFtdcVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	TShfeFtdcVolumeType	FREE;
};

///Mem资源使用信息
struct CShfeFtdcRtnTopMemInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///Total Real Memory
	TShfeFtdcVolumeType	TOTALREAL;
	///Active Real Memory
	TShfeFtdcVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	TShfeFtdcVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	TShfeFtdcVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	TShfeFtdcVolumeType	FREE;
};

///process资源使用查询
struct CShfeFtdcReqQryTopProcessInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///process资源使用信息
struct CShfeFtdcRspQryTopProcessInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///处理器号
	TShfeFtdcTypeCPUIdType	CPU;
	///终端名
	TShfeFtdcTypeChar10Type	TTY;
	///进程号
	TShfeFtdcVolumeType	PID;
	///用户名
	TShfeFtdcTypeChar10Type	USERNAME;
	///任务的优先级
	TShfeFtdcVolumeType	PRI;
	///任务的nice值
	TShfeFtdcVolumeType	NI;
	///任务的代码加上数据再加上栈空间的大小
	TShfeFtdcVolumeType	SIZE;
	///任务使用的物理内存的总数量
	TShfeFtdcVolumeType	RES;
	///任务的状态
	TShfeFtdcTypeChar10Type	STATE;
	///自任务开始时使用的总CPU时间
	TShfeFtdcTimeType	TIME;
	///进程的CPU利用率权重百分比
	TShfeFtdcRatioType	pWCPU;
	///进程的原始的CPU利用率百分比
	TShfeFtdcRatioType	pCPU;
	///启动进程的命令名
	TShfeFtdcTypeCommandType	COMMAND;
};

///process资源使用信息
struct CShfeFtdcRtnTopProcessInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///处理器号
	TShfeFtdcTypeCPUIdType	CPU;
	///终端名
	TShfeFtdcTypeChar10Type	TTY;
	///进程号
	TShfeFtdcVolumeType	PID;
	///用户名
	TShfeFtdcTypeChar10Type	USERNAME;
	///任务的优先级
	TShfeFtdcVolumeType	PRI;
	///任务的nice值
	TShfeFtdcVolumeType	NI;
	///任务的代码加上数据再加上栈空间的大小
	TShfeFtdcVolumeType	SIZE;
	///任务使用的物理内存的总数量
	TShfeFtdcVolumeType	RES;
	///任务的状态
	TShfeFtdcTypeChar10Type	STATE;
	///自任务开始时使用的总CPU时间
	TShfeFtdcTimeType	TIME;
	///进程的CPU利用率权重百分比
	TShfeFtdcRatioType	pWCPU;
	///进程的原始的CPU利用率百分比
	TShfeFtdcRatioType	pCPU;
	///启动进程的命令名
	TShfeFtdcTypeCommandType	COMMAND;
};

///filesystem资源使用查询
struct CShfeFtdcReqQryFileSystemInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///filesystem资源使用信息
struct CShfeFtdcRspQryFileSystemInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///文件系统物理名
	TShfeFtdcTypeCommandType	FILESYSTEM;
	///空间总数
	TShfeFtdcVolumeType	SIZE;
	///已用空间大小
	TShfeFtdcVolumeType	USED;
	///可用空间大小
	TShfeFtdcVolumeType	AVAIL;
	///已用的百分比
	TShfeFtdcRatioType	pUSERD;
	///inode总数
	TShfeFtdcVolumeType	ISIZE;
	///已用inode大小
	TShfeFtdcVolumeType	IUSED;
	///可用inode大小
	TShfeFtdcVolumeType	IFREE;
	///已用的百分比
	TShfeFtdcRatioType	pIUSED;
	///加载位置
	TShfeFtdcTypeCommandType	MountedOn;
};

///filesystem资源使用信息
struct CShfeFtdcRtnFileSystemInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///文件系统物理名
	TShfeFtdcTypeCommandType	FILESYSTEM;
	///空间总数
	TShfeFtdcVolumeType	SIZE;
	///已用空间大小
	TShfeFtdcVolumeType	USED;
	///可用空间大小
	TShfeFtdcVolumeType	AVAIL;
	///已用的百分比
	TShfeFtdcRatioType	pUSERD;
	///inode总数
	TShfeFtdcVolumeType	ISIZE;
	///已用inode大小
	TShfeFtdcVolumeType	IUSED;
	///可用inode大小
	TShfeFtdcVolumeType	IFREE;
	///已用的百分比
	TShfeFtdcRatioType	pIUSED;
	///加载位置
	TShfeFtdcTypeCommandType	MountedOn;
};

///network资源使用查询
struct CShfeFtdcReqQryNetworkInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///网卡名
	TShfeFtdcTypeLanNameType	LANNAME;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///network资源使用信息
struct CShfeFtdcRspQryNetworkInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///网卡名
	TShfeFtdcTypeLanNameType	LANNAME;
	///网卡的up或down状态
	TShfeFtdcTypeLanStatusType	LANSTATUS;
	///网卡的ip地址
	TShfeFtdcIPAddressType	IPADDRESS;
	///网卡接收的流量
	TShfeFtdcLargeNumberType	RECVBYTES;
	///网卡接收的数据包
	TShfeFtdcLargeNumberType	RECVPACKETS;
	///网卡接收端错误数据包
	TShfeFtdcLargeNumberType	RECVERRORPACKETS;
	///网卡接收端丢失数据包
	TShfeFtdcLargeNumberType	RECVDROPPACKETS;
	///网卡发送的流量
	TShfeFtdcLargeNumberType	SENDBYTES;
	///网卡发送的数据包
	TShfeFtdcLargeNumberType	SENDPACKETS;
	///网卡发送端错误数据包
	TShfeFtdcLargeNumberType	SENDERRORPACKETS;
	///网卡发送端丢失数据包
	TShfeFtdcLargeNumberType	SENDDROPPACKETS;
};

///network资源使用信息
struct CShfeFtdcRtnNetworkInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///网卡名
	TShfeFtdcTypeLanNameType	LANNAME;
	///网卡的up或down状态
	TShfeFtdcTypeLanStatusType	LANSTATUS;
	///网卡的ip地址
	TShfeFtdcIPAddressType	IPADDRESS;
	///网卡接收的流量
	TShfeFtdcLargeNumberType	RECVBYTES;
	///网卡接收的数据包
	TShfeFtdcLargeNumberType	RECVPACKETS;
	///网卡接收端错误数据包
	TShfeFtdcLargeNumberType	RECVERRORPACKETS;
	///网卡接收端丢失数据包
	TShfeFtdcLargeNumberType	RECVDROPPACKETS;
	///网卡发送的流量
	TShfeFtdcLargeNumberType	SENDBYTES;
	///网卡发送的数据包
	TShfeFtdcLargeNumberType	SENDPACKETS;
	///网卡发送端错误数据包
	TShfeFtdcLargeNumberType	SENDERRORPACKETS;
	///网卡发送端丢失数据包
	TShfeFtdcLargeNumberType	SENDDROPPACKETS;
};

///主机环境信息查询请求
struct CShfeFtdcReqQryHostEnvField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///主机环境信息应答信息
struct CShfeFtdcRspQryHostEnvCommonField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///主机型号
	TShfeFtdcTypeHostModelType	HostModel;
	///内存大小(K)
	TShfeFtdcVolumeType	MainMemory;
	///CPU厂商
	TShfeFtdcTypeHostModelType	CPUVendor;
	///CPU型号
	TShfeFtdcTypeHostModelType	CPUModel;
	///CPU主频
	TShfeFtdcTypeHostModelType	CPUMHz;
	///CPU缓存
	TShfeFtdcTypeHostModelType	CPUCache;
	///CPU内核数
	TShfeFtdcVolumeType	CPUCores;
	///CPU个数
	TShfeFtdcVolumeType	Processors;
	///32位还是64位操作系统
	TShfeFtdcVolumeType	OsMode;
};

///主机环境信息应答信息
struct CShfeFtdcRspQryHostEnvLanField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///LanID
	TShfeFtdcTypeHostModelType	LanHardwareID;
	///Mac地址
	TShfeFtdcTypeHostModelType	LanHardwareValue;
};

///主机环境信息应答信息
struct CShfeFtdcRspQryHostEnvStorageField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///Storage Devices
	TShfeFtdcTypeHostModelType	StorageDev;
	///HW Path
	TShfeFtdcTypeHostModelType	HWPath;
	///Interface
	TShfeFtdcTypeHostModelType	Interface;
};

///主机环境信息应答信息
struct CShfeFtdcRspQryHostEnvIOField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///IO Class
	TShfeFtdcTypeChar10Type	IoClass;
	///H/W Path
	TShfeFtdcTypeChar10Type	H_WPath;
	///Driver
	TShfeFtdcTypeChar10Type	IoDriver;
	///Description
	TShfeFtdcTypeDescriptionType	IoDescription;
};

///主机环境信息应答信息
struct CShfeFtdcRspQryHostEnvFSField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///LVM Device file
	TShfeFtdcTypeHostModelType	LVMDeviceFile;
	///mount point
	TShfeFtdcTypeCommandType	MountPoint;
	///size
	TShfeFtdcVolumeType	FSsize;
	///fs type
	TShfeFtdcTypeChar10Type	FSType;
};

///主机环境信息应答信息
struct CShfeFtdcRspQryHostEnvSwapField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///type
	TShfeFtdcTypeChar10Type	type;
	///size
	TShfeFtdcVolumeType	size;
	///priority
	TShfeFtdcVolumeType	priority;
	///device location
	TShfeFtdcTypeHostModelType	location;
};

///主机环境信息应答信息
struct CShfeFtdcRspQryHostEnvLanCfgField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///
	TShfeFtdcTypeLanNameType	LanName;
	///
	TShfeFtdcIPAddressType	IpAddress;
	///
	TShfeFtdcIPAddressType	IpMask;
};

///客户端登录查询请求
struct CShfeFtdcReqQryClientLoginField
{
	///登录用户名
	TShfeFtdcTypeUserNameType	UserName;
	///登录密码
	TShfeFtdcTypeUserNameType	PassWord;
};

///客户端登录应答信息
struct CShfeFtdcRspQryClientLoginField
{
	///登录用户名
	TShfeFtdcTypeUserNameType	UserName;
	///登录权限
	TShfeFtdcTypeUserNameType	Privalage;
};

///获得监控对象信息查询请求
struct CShfeFtdcReqQryMonitorObjectField
{
	///业务进程对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///获得监控对象信息应答信息
struct CShfeFtdcRspQryMonitorObjectField
{
	///业务进程对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///本级业务进程对象名字
	TShfeFtdcTypeLongObjectNameType	ObjectName;
	///告警事件产生标志位
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///获得监控对象信息应答信息
struct CShfeFtdcRtnMonitorObjectField
{
	///业务进程对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///本级业务进程对象名字
	TShfeFtdcTypeLongObjectNameType	ObjectName;
	///告警事件产生标志位
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///获得业务进程和主机的对应关系查询请求
struct CShfeFtdcReqQryObjectRationalField
{
	///业务进程对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///获得业务进程和主机的对应关系应答信息
struct CShfeFtdcRspQryObjectRationalField
{
	///业务进程对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///业务进程所在的主机ID
	TShfeFtdcTypeObjectIDType	HostObjectID;
};

///获得业务进程和主机的对应关系应答信息
struct CShfeFtdcRtnObjectRationalField
{
	///业务进程对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///业务进程所在的主机ID
	TShfeFtdcTypeObjectIDType	HostObjectID;
};

///日志文件内容查询请求
struct CShfeFtdcReqQrySyslogInfoField
{
	///请求文件路径
	TShfeFtdcTypeObjectIDType	FileName;
	///文件名
	TShfeFtdcTypeObjectIDType	subFileName;
};

///日志文件内容应答信息
struct CShfeFtdcRspQrySyslogInfoField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控指标类型
	TShfeFtdcAttrTypeType	AttrType;
	///文件内容长度
	TShfeFtdcTypeContLenType	ContLen;
	///文件内容
	TShfeFtdcTypeFileContentType	FileContent;
};

///日志文件内容应答信息
struct CShfeFtdcRtnSyslogInfoField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控指标类型
	TShfeFtdcAttrTypeType	AttrType;
	///文件内容长度
	TShfeFtdcTypeContLenType	ContLen;
	///文件内容
	TShfeFtdcTypeFileContentType	FileContent;
};

///监控内容订阅请求
struct CShfeFtdcReqQrySubscriberField
{
	///订阅对象名
	TShfeFtdcTypeSubcriberObjectIDType	ObjectID;
	///初次返回对象数
	TShfeFtdcVolumeType	ObjectNum;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
	///返回的初始日期
	TShfeFtdcDateType	MonDate;
	///返回的初始时间
	TShfeFtdcTimeType	MonTime;
};

///监控内容订阅应答信息
struct CShfeFtdcRspQrySubscriberField
{
	///错误代码
	TShfeFtdcErrorIDType	ErrorID;
	///错误信息
	TShfeFtdcErrorMsgType	ErrorMsg;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///监控内容订阅应答信息
struct CShfeFtdcRtnSubscriberField
{
	///错误代码
	TShfeFtdcErrorIDType	ErrorID;
	///错误信息
	TShfeFtdcErrorMsgType	ErrorMsg;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///对象关系查询请求
struct CShfeFtdcReqQryOidRelationField
{
	///
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///对象关系查询应答信息
struct CShfeFtdcRspQryOidRelationField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///定义对象名
	TShfeFtdcTypeObjectIDType	HoldObjectID;
};

///对象关系查询应答信息
struct CShfeFtdcRtnOidRelationField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///定义对象名
	TShfeFtdcTypeObjectIDType	HoldObjectID;
};

///用户信息查询请求
struct CShfeFtdcReqQryUserInfoField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///用户信息查询应答信息
struct CShfeFtdcRspQryUserInfoField
{
	///用户名
	TShfeFtdcTypeUserNameType	USERNAME;
	///用户ID
	TShfeFtdcVolumeType	USERID;
	///用户组名
	TShfeFtdcTypeUserNameType	GROUPNAME;
	///用户组ID
	TShfeFtdcVolumeType	GROUPID;
	///HOME路径
	TShfeFtdcTypeUserNameType	HOMEPATH;
	///用户使用SHELL环境
	TShfeFtdcTypeUserNameType	SHELL;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
};

///用户信息查询应答信息
struct CShfeFtdcRtnUserInfoField
{
	///用户名
	TShfeFtdcTypeUserNameType	USERNAME;
	///用户ID
	TShfeFtdcVolumeType	USERID;
	///用户组名
	TShfeFtdcTypeUserNameType	GROUPNAME;
	///用户组ID
	TShfeFtdcVolumeType	GROUPID;
	///HOME路径
	TShfeFtdcTypeUserNameType	HOMEPATH;
	///用户使用SHELL环境
	TShfeFtdcTypeUserNameType	SHELL;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
};

///在线用户信息查询请求
struct CShfeFtdcReqQryOnlineUserInfoField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///在线用户信息应答信息
struct CShfeFtdcRspQryOnlineUserInfoField
{
	///用户名
	TShfeFtdcTypeUserNameType	USERNAME;
	///登录时间
	TShfeFtdcTypeUserNameType	TIME;
	///终端类型
	TShfeFtdcTypeUserNameType	TTY;
	///IP地址
	TShfeFtdcTypeUserNameType	IP;
	///连接时间
	TShfeFtdcTypeUserNameType	CONNECTIME;
	///进程ID
	TShfeFtdcVolumeType	PID;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
};

///在线用户信息应答信息
struct CShfeFtdcRtnOnlineUserInfoField
{
	///用户名
	TShfeFtdcTypeUserNameType	USERNAME;
	///登录时间
	TShfeFtdcTypeUserNameType	TIME;
	///终端类型
	TShfeFtdcTypeUserNameType	TTY;
	///IP地址
	TShfeFtdcTypeUserNameType	IP;
	///连接时间
	TShfeFtdcTypeUserNameType	CONNECTIME;
	///进程ID
	TShfeFtdcVolumeType	PID;
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
};

///告警事件
struct CShfeFtdcSysWarningEventField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件发生日期
	TShfeFtdcDateType	OccurDate;
	///事件发生时间
	TShfeFtdcTimeType	OccurTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///事件标签
	TShfeFtdcVolumeType	EventNum;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///事件描述
	TShfeFtdcTypeDescriptionType	EventDes;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///事件处理描述
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///事件全名
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///告警事件查询请求
struct CShfeFtdcReqQryWarningEventField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
};

///告警事件应答信息
struct CShfeFtdcRspQryWarningEventField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件发生日期
	TShfeFtdcDateType	OccurDate;
	///事件发生时间
	TShfeFtdcTimeType	OccurTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///事件标签
	TShfeFtdcVolumeType	EventNum;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///事件描述
	TShfeFtdcTypeDescriptionType	EventDes;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///事件处理描述
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///事件全名
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///告警事件应答信息
struct CShfeFtdcRtnWarningEventField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件发生日期
	TShfeFtdcDateType	OccurDate;
	///事件发生时间
	TShfeFtdcTimeType	OccurTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///事件标签
	TShfeFtdcVolumeType	EventNum;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///事件描述
	TShfeFtdcTypeDescriptionType	EventDes;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///事件处理描述
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///事件全名
	TShfeFtdcNetAttrTypeType	FullEventName;
	///事件条数
	TShfeFtdcCounterType	EventCount;
};

///KeyFile请求
struct CShfeFtdcReqQryKeyFileInfoField
{
	///请求文件名ID
	TShfeFtdcTypeObjectIDType	FileName;
	///请求文件名路径
	TShfeFtdcTypeObjectIDType	PathName;
};

///HostMonitorCfg请求
struct CShfeFtdcReqQryHostMonitorCfgField
{
	///
	TShfeFtdcTypeMonitorTypeType	MonitorType;
	///请求文件名路径
	TShfeFtdcTypeObjectIDType	PathName;
	///
	TShfeFtdcVolumeType	Interval;
};

///AppMonitorCfg请求
struct CShfeFtdcReqQryAppMonitorCfgField
{
	///
	TShfeFtdcTypeMonitorTypeType	MonitorType;
	///
	TShfeFtdcTypePositionType	FSPosition;
};

///CPU使用率查询请求
struct CShfeFtdcReqQryCPUUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///CPU使用率应答信息
struct CShfeFtdcRspQryCPUUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///CPU使用率
	TShfeFtdcRatioType	CPUUsage;
};

///CPU使用率应答信息
struct CShfeFtdcRtnCPUUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///CPU使用率
	TShfeFtdcRatioType	CPUUsage;
};

///内存使用率查询请求
struct CShfeFtdcReqQryMemoryUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///内存使用率应答信息
struct CShfeFtdcRspQryMemoryUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///内存使用率
	TShfeFtdcRatioType	MemoryUsage;
};

///内存使用率应答信息
struct CShfeFtdcRtnMemoryUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///内存使用率
	TShfeFtdcRatioType	MemoryUsage;
};

///硬盘使用率查询请求
struct CShfeFtdcReqQryDiskUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///硬盘使用率应答信息
struct CShfeFtdcRspQryDiskUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///硬盘使用率
	TShfeFtdcRatioType	DiskUsage;
};

///硬盘使用率应答信息
struct CShfeFtdcRtnDiskUsageField
{
	///定义对象名
	TShfeFtdcTypeObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///硬盘使用率
	TShfeFtdcRatioType	DiskUsage;
};

///对象状态指标查询
struct CShfeFtdcReqQryObjectAttrField
{
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///对象状态指标查询应答
struct CShfeFtdcRspQryObjectAttrField
{
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///监控指标的值类型
	TShfeFtdcValueTypeType	ValueType;
	///监控指标的具体值
	TShfeFtdcAttrValueType	AttrValue;
};

///对象状态指标查询应答
struct CShfeFtdcRtnObjectAttrField
{
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///监控指标的值类型
	TShfeFtdcValueTypeType	ValueType;
	///监控指标的具体值
	TShfeFtdcAttrValueType	AttrValue;
};

///主机配置查询请求
struct CShfeFtdcReqQryHostConfigField
{
	///
	TShfeFtdcCfgTypeType	CfgType;
	///
	TShfeFtdcCfgNameType	CfgDataCenter;
	///
	TShfeFtdcTypeObjectIDType	CfgName;
	///
	TShfeFtdcFilePathNameType	CfgLocation;
	///
	TShfeFtdcTypeObjectIDType	CfgHostName;
	///
	TShfeFtdcTypeObjectIDType	CfgAttend;
};

///无效报单查询
struct CShfeFtdcReqQryInvalidateOrderField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///无效报单查询应答
struct CShfeFtdcRspQryInvalidateOrderField
{
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///插入日期
	TShfeFtdcDateType	ActionDate;
	///插入时间
	TShfeFtdcTimeType	ActionTime;
	///错误信息
	TShfeFtdcErrorMsgType	ErrorMsg;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///组合开平标志
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TShfeFtdcTimeConditionType	TimeCondition;
	///成交量类型
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TShfeFtdcVolumeType	MinVolume;
};

///无效报单查询应答
struct CShfeFtdcRtnInvalidateOrderField
{
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///插入日期
	TShfeFtdcDateType	ActionDate;
	///插入时间
	TShfeFtdcTimeType	ActionTime;
	///错误信息
	TShfeFtdcErrorMsgType	ErrorMsg;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///组合开平标志
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TShfeFtdcTimeConditionType	TimeCondition;
	///成交量类型
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TShfeFtdcVolumeType	MinVolume;
};

///报单状态查询
struct CShfeFtdcReqQryOrderStatusField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///报单状态查询应答
struct CShfeFtdcRspQryOrderStatusField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///报单日期
	TShfeFtdcDateType	InsertDate;
	///插入时间
	TShfeFtdcTimeType	InsertTime;
	///报单状态
	TShfeFtdcOrderStatusType	OrderStatus;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///组合开平标志
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TShfeFtdcTimeConditionType	TimeCondition;
	///成交量类型
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TShfeFtdcVolumeType	MinVolume;
};

///报单状态查询应答
struct CShfeFtdcRtnOrderStatusField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///本地报单编号
	TShfeFtdcOrderLocalIDType	OrderLocalID;
	///报单日期
	TShfeFtdcDateType	InsertDate;
	///插入时间
	TShfeFtdcTimeType	InsertTime;
	///报单状态
	TShfeFtdcOrderStatusType	OrderStatus;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	TShfeFtdcDirectionType	Direction;
	///组合开平标志
	TShfeFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TShfeFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	TShfeFtdcPriceType	LimitPrice;
	///数量
	TShfeFtdcVolumeType	VolumeTotalOriginal;
	///有效期类型
	TShfeFtdcTimeConditionType	TimeCondition;
	///成交量类型
	TShfeFtdcVolumeConditionType	VolumeCondition;
	///最小成交量
	TShfeFtdcVolumeType	MinVolume;
};

///报单成交查询
struct CShfeFtdcReqQryBargainOrderField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///报单成交查询应答
struct CShfeFtdcRspQryBargainOrderField
{
	///成交日期
	TShfeFtdcDateType	ActionDate;
	///成交时间
	TShfeFtdcTimeType	ActionTime;
	///成交编号
	TShfeFtdcTradeIDType	TradeID;
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///价格
	TShfeFtdcPriceType	Price;
	///数量
	TShfeFtdcVolumeType	Volume;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
};

///报单成交查询应答
struct CShfeFtdcRtnBargainOrderField
{
	///成交日期
	TShfeFtdcDateType	ActionDate;
	///成交时间
	TShfeFtdcTimeType	ActionTime;
	///成交编号
	TShfeFtdcTradeIDType	TradeID;
	///报单编号
	TShfeFtdcOrderSysIDType	OrderSysID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///价格
	TShfeFtdcPriceType	Price;
	///数量
	TShfeFtdcVolumeType	Volume;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
};

///合约基本属性查询
struct CShfeFtdcReqQryInstPropertyField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///合约基本属性查询应答
struct CShfeFtdcRspQryInstPropertyField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///基础商品代码
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///产品类型
	TShfeFtdcProductClassType	ProductClass;
	///持仓类型
	TShfeFtdcPositionTypeType	PositionType;
	///合约数量乘数
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///合约生命周期状态
	TShfeFtdcInstLifePhaseType	InstLifePhase;
	///上市日
	TShfeFtdcDateType	OpenDate;
	///到期日
	TShfeFtdcDateType	ExpireDate;
	///开始交割日
	TShfeFtdcDateType	StartDelivDate;
	///最后交割日
	TShfeFtdcDateType	EndDelivDate;
	///挂牌基准价
	TShfeFtdcPriceType	BasisPrice;
	///市价单最大下单量
	TShfeFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TShfeFtdcVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	TShfeFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TShfeFtdcVolumeType	MinLimitOrderVolume;
	///最小变动价位
	TShfeFtdcPriceType	PriceTick;
	///交割月自然人开仓
	TShfeFtdcMonthCountType	AllowDelivPersonOpen;
};

///合约基本属性查询应答
struct CShfeFtdcRtnInstPropertyField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///基础商品代码
	TShfeFtdcInstrumentIDType	UnderlyingInstrID;
	///产品类型
	TShfeFtdcProductClassType	ProductClass;
	///持仓类型
	TShfeFtdcPositionTypeType	PositionType;
	///合约数量乘数
	TShfeFtdcVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	TShfeFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///合约生命周期状态
	TShfeFtdcInstLifePhaseType	InstLifePhase;
	///上市日
	TShfeFtdcDateType	OpenDate;
	///到期日
	TShfeFtdcDateType	ExpireDate;
	///开始交割日
	TShfeFtdcDateType	StartDelivDate;
	///最后交割日
	TShfeFtdcDateType	EndDelivDate;
	///挂牌基准价
	TShfeFtdcPriceType	BasisPrice;
	///市价单最大下单量
	TShfeFtdcVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	TShfeFtdcVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	TShfeFtdcVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	TShfeFtdcVolumeType	MinLimitOrderVolume;
	///最小变动价位
	TShfeFtdcPriceType	PriceTick;
	///交割月自然人开仓
	TShfeFtdcMonthCountType	AllowDelivPersonOpen;
};

///合约保证金率查询
struct CShfeFtdcReqQryMarginRateField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///合约保证金率查询应答
struct CShfeFtdcRspQryMarginRateField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头保证金率
	TShfeFtdcRatioType	LongMarginRatio;
	///空头保证金率
	TShfeFtdcRatioType	ShortMarginRatio;
};

///合约保证金率查询应答
struct CShfeFtdcRtnMarginRateField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头保证金率
	TShfeFtdcRatioType	LongMarginRatio;
	///空头保证金率
	TShfeFtdcRatioType	ShortMarginRatio;
};

///合约涨跌停板查询
struct CShfeFtdcReqQryPriceLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///合约涨跌停板查询应答
struct CShfeFtdcRspQryPriceLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///舍入方式
	TShfeFtdcRoundingModeType	RoundingMode;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///合约涨跌停板查询应答
struct CShfeFtdcRtnPriceLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///舍入方式
	TShfeFtdcRoundingModeType	RoundingMode;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///会员限仓查询
struct CShfeFtdcReqQryPartPosiLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///会员限仓查询应答
struct CShfeFtdcRspQryPartPosiLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///会员限仓查询应答
struct CShfeFtdcRtnPartPosiLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///客户限仓查询
struct CShfeFtdcReqQryClientPosiLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///客户限仓查询应答
struct CShfeFtdcRspQryClientPosiLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///客户限仓查询应答
struct CShfeFtdcRtnClientPosiLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///特殊客户限仓查询
struct CShfeFtdcReqQrySpecialPosiLimitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcDateType	EndDate;
};

///特殊客户限仓查询应答
struct CShfeFtdcRspQrySpecialPosiLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///特殊客户限仓查询应答
struct CShfeFtdcRtnSpecialPosiLimitField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
};

///账户出入金查询
struct CShfeFtdcReqQryTransactionChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///账户出入金查询应答
struct CShfeFtdcRspQryTransactionChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///帐户往来流水号
	TShfeFtdcSerialNoType	BillSN;
	///资金账户
	TShfeFtdcAccountIDType	ParticipantAccount;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///发生额
	TShfeFtdcMoneyType	Amount;
};

///账户出入金查询应答
struct CShfeFtdcRtnTransactionChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///帐户往来流水号
	TShfeFtdcSerialNoType	BillSN;
	///资金账户
	TShfeFtdcAccountIDType	ParticipantAccount;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///发生额
	TShfeFtdcMoneyType	Amount;
};

///客户数据变动查询
struct CShfeFtdcReqQryClientChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///客户数据变动查询应答
struct CShfeFtdcRspQryClientChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///客户数据变动查询应答
struct CShfeFtdcRtnClientChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///会员客户对照变动查询
struct CShfeFtdcReqQryPartClientChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///会员客户对照变动查询应答
struct CShfeFtdcRspQryPartClientChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///会员客户对照变动查询应答
struct CShfeFtdcRtnPartClientChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///限仓数据变动查询
struct CShfeFtdcReqQryPosiLimitChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///限仓数据变动查询应答
struct CShfeFtdcRspQryPosiLimitChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///限仓数据变动查询应答
struct CShfeFtdcRtnPosiLimitChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///保值额度变动查询
struct CShfeFtdcReqQryHedgeDetailChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///保值额度变动查询应答
struct CShfeFtdcRspQryHedgeDetailChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///用户代码
	TShfeFtdcOperatorIDType	OperatorID;
	///时间
	TShfeFtdcTimeType	Time;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///持仓多空方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///发生额
	TShfeFtdcVolumeType	TradingVolume;
	///保值额度
	TShfeFtdcVolumeType	HedgeQuota;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///保值额度变动查询应答
struct CShfeFtdcRtnHedgeDetailChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///用户代码
	TShfeFtdcOperatorIDType	OperatorID;
	///时间
	TShfeFtdcTimeType	Time;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///持仓多空方向
	TShfeFtdcPosiDirectionType	PosiDirection;
	///发生额
	TShfeFtdcVolumeType	TradingVolume;
	///保值额度
	TShfeFtdcVolumeType	HedgeQuota;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///会员变动查询
struct CShfeFtdcReqQryParticipantChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///会员变动查询应答
struct CShfeFtdcRspQryParticipantChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///会员简称
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///会员类型
	TShfeFtdcMemberTypeType	MemberType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///会员变动查询应答
struct CShfeFtdcRtnParticipantChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///会员简称
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///会员类型
	TShfeFtdcMemberTypeType	MemberType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///保证金率变动查询
struct CShfeFtdcReqQryMarginRateChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///保证金率变动查询应答
struct CShfeFtdcRspQryMarginRateChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头保证金率
	TShfeFtdcRatioType	LongMarginRatio;
	///空头保证金率
	TShfeFtdcRatioType	ShortMarginRatio;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///保证金率变动查询应答
struct CShfeFtdcRtnMarginRateChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///投机套保标志
	TShfeFtdcHedgeFlagType	HedgeFlag;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头保证金率
	TShfeFtdcRatioType	LongMarginRatio;
	///空头保证金率
	TShfeFtdcRatioType	ShortMarginRatio;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///IP地址变动查询
struct CShfeFtdcReqQryUserIpChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///IP地址变动查询应答
struct CShfeFtdcRspQryUserIpChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///IP地址掩码
	TShfeFtdcIPAddressType	IPMask;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///IP地址变动查询应答
struct CShfeFtdcRtnUserIpChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///IP地址掩码
	TShfeFtdcIPAddressType	IPMask;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///限仓数据变动查询
struct CShfeFtdcReqQryClientPosiLimitChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///限仓数据变动查询应答
struct CShfeFtdcRspQryClientPosiLimitChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///限仓数据变动查询应答
struct CShfeFtdcRtnClientPosiLimitChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///限仓数据变动查询
struct CShfeFtdcReqQrySpecPosiLimitChgField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///限仓数据变动查询应答
struct CShfeFtdcRspQrySpecPosiLimitChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///限仓数据变动查询应答
struct CShfeFtdcRtnSpecPosiLimitChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///交易角色
	TShfeFtdcPositionTradingRoleType	TradingRole;
	///限仓起点
	TShfeFtdcLargeVolumeType	StartTotalPosition;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///多头限仓
	TShfeFtdcRatioType	LongPosLimit;
	///空头限仓
	TShfeFtdcRatioType	ShortPosLimit;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///历史对象状态查询
struct CShfeFtdcReqQryHistoryObjectAttrField
{
	///定义对象名
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///历史对象状态查询应答
struct CShfeFtdcRspQryHistoryObjectAttrField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///本周期开始时间
	TShfeFtdcTimeType	BeginTime;
	///本周期结束时间
	TShfeFtdcTimeType	EndTime;
	///定义对象名
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///监控指标的值类型
	TShfeFtdcValueTypeType	ValueType;
	///本周期收到第一个值
	TShfeFtdcCapValueType	FirstValue;
	///本周期收到最后一个值
	TShfeFtdcCapValueType	EndValue;
	///本周期平均值
	TShfeFtdcCapValueType	AvgValue;
	///本周期收到最小值
	TShfeFtdcCapValueType	MinValue;
	///本周期收到最大值
	TShfeFtdcCapValueType	MaxValue;
	///本周期收到指标个数
	TShfeFtdcVolumeType	ValueCount;
};

///历史对象状态查询应答
struct CShfeFtdcRtnHistoryObjectAttrField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///本周期开始时间
	TShfeFtdcTimeType	BeginTime;
	///本周期结束时间
	TShfeFtdcTimeType	EndTime;
	///定义对象名
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///监控指标的值类型
	TShfeFtdcValueTypeType	ValueType;
	///本周期收到第一个值
	TShfeFtdcCapValueType	FirstValue;
	///本周期收到最后一个值
	TShfeFtdcCapValueType	EndValue;
	///本周期平均值
	TShfeFtdcCapValueType	AvgValue;
	///本周期收到最小值
	TShfeFtdcCapValueType	MinValue;
	///本周期收到最大值
	TShfeFtdcCapValueType	MaxValue;
	///本周期收到指标个数
	TShfeFtdcVolumeType	ValueCount;
};

///前置响应信息查询
struct CShfeFtdcReqQryFrontInfoField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///前置响应信息查询应答
struct CShfeFtdcRspQryFrontInfoField
{
	///日期
	TShfeFtdcDateType	MonDate;
	///本周期开始时间
	TShfeFtdcTimeType	MonTime;
	///前置机名
	TShfeFtdcTypeObjectIDType	FrontId;
	///前置响应时间条件
	TShfeFtdcVolumeType	RspCondition;
	///请求数
	TShfeFtdcVolumeType	ReqCount;
	///所占总笔数比率
	TShfeFtdcRatioType	ReqRate;
};

///前置响应信息查询应答
struct CShfeFtdcRtnFrontInfoField
{
	///日期
	TShfeFtdcDateType	MonDate;
	///本周期开始时间
	TShfeFtdcTimeType	MonTime;
	///前置机名
	TShfeFtdcTypeObjectIDType	FrontId;
	///前置响应时间条件
	TShfeFtdcVolumeType	RspCondition;
	///请求数
	TShfeFtdcVolumeType	ReqCount;
	///所占总笔数比率
	TShfeFtdcRatioType	ReqRate;
};

///用户登录查询
struct CShfeFtdcReqQrySysUserLoginField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///密码
	TShfeFtdcPasswordType	Password;
	///版本号
	TShfeFtdcVersionIDType	VersionID;
};

///用户登录应答
struct CShfeFtdcRspQrySysUserLoginField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///交易日
	TShfeFtdcDateType	TradingDay;
	///登录成功时间
	TShfeFtdcTimeType	LoginTime;
	///用户权限
	TShfeFtdcPrivilegeType	Privilege;
	///版本匹配标识
	TShfeFtdcVersionFlagType	VersionFlag;
};

///用户登出
struct CShfeFtdcReqQrySysUserLogoutField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
};

///用户登出应答
struct CShfeFtdcRspQrySysUserLogoutField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
};

///用户修改密码
struct CShfeFtdcReqQrySysUserPasswordUpdateField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///旧密码
	TShfeFtdcPasswordType	OldPassword;
	///新密码
	TShfeFtdcPasswordType	NewPassword;
};

///用户修改密码应答
struct CShfeFtdcRspQrySysUserPasswordUpdateField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///密码修改返回信息
	TShfeFtdcActionMsgType	PasswordChgMsg;
};

///用户注册
struct CShfeFtdcReqQrySysUserRegisterField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///用户姓名
	TShfeFtdcUserIDType	UserName;
	///用户信息
	TShfeFtdcUserInfoType	UserInfo;
	///密码
	TShfeFtdcPasswordType	Password;
	///用户权限
	TShfeFtdcPrivilegeType	Privilege;
	///用户电子邮件
	TShfeFtdcEMailType	EMail;
	///用户电子邮件接收标记
	TShfeFtdcReciveFlagType	EMailFlag;
	///用户固定电话
	TShfeFtdcTelephoneType	HomePhone;
	///用户固定电话接收标记
	TShfeFtdcReciveFlagType	HomePhoneFlag;
	///用户手机
	TShfeFtdcTelephoneType	MobilePhone;
	///用户手机接收标记
	TShfeFtdcReciveFlagType	MobilePhoneFlag;
};

///用户注册应答
struct CShfeFtdcRspQrySysUserRegisterField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///用户权限
	TShfeFtdcPrivilegeType	Privilege;
};

///删除用户
struct CShfeFtdcReqQrySysUserDeleteField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
};

///删除用户应答
struct CShfeFtdcRspQrySysUserDeleteField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
};

///会员初始化应答
struct CShfeFtdcRspQryParticipantInitField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///会员简称
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///会员类型
	TShfeFtdcMemberTypeType	MemberType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///会员初始化应答
struct CShfeFtdcRtnParticipantInitField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///会员简称
	TShfeFtdcParticipantAbbrType	ParticipantAbbr;
	///会员类型
	TShfeFtdcMemberTypeType	MemberType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///座席初始化应答
struct CShfeFtdcRspQryUserInitField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///交易用户类型
	TShfeFtdcUserTypeType	UserType;
	///密码
	TShfeFtdcPasswordType	Password;
	///交易员权限
	TShfeFtdcUserActiveType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///座席初始化应答
struct CShfeFtdcRtnUserInitField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///交易用户类型
	TShfeFtdcUserTypeType	UserType;
	///密码
	TShfeFtdcPasswordType	Password;
	///交易员权限
	TShfeFtdcUserActiveType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///客户初始化应答
struct CShfeFtdcRspQryClientInitField
{
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///客户初始化应答
struct CShfeFtdcRtnClientInitField
{
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///交易日志查询
struct CShfeFtdcReqQryTradeLogField
{
	///交易日
	TShfeFtdcDateType	TradingDay;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///前置号
	TShfeFtdcCommodityIDType	FrontID;
	///起始会员号
	TShfeFtdcParticipantIDType	StartParticipant;
	///结束会员号
	TShfeFtdcParticipantIDType	EndParticipant;
	///起始席位号
	TShfeFtdcUserIDType	StartUser;
	///结束席位号
	TShfeFtdcUserIDType	EndUser;
	///开始时间
	TShfeFtdcTimeType	StartTime;
	///结束时间
	TShfeFtdcTimeType	EndTime;
	///起始会话ID
	TShfeFtdcCommodityIDType	StartSessionID;
	///结束会话ID
	TShfeFtdcCommodityIDType	EndSessionID;
	///根据IP过滤标记
	TShfeFtdcBoolType	IPFlag;
	///根据会员过滤标记
	TShfeFtdcBoolType	PartFlag;
	///根据席位过滤标记
	TShfeFtdcBoolType	UserIDFlag;
	///根据时间过滤标记
	TShfeFtdcBoolType	TimeFlag;
	///根据前置号过滤标记
	TShfeFtdcBoolType	FrontFlag;
	///根据会话号过滤标记
	TShfeFtdcBoolType	SessionFlag;
};

///交易日志查询应答
struct CShfeFtdcRspQryTradeLogField
{
	///
	TShfeFtdcBoolType	bFlag;
	///
	TShfeFtdcTradeLogStrType	TradeLogStr;
};

///交易日志查询应答
struct CShfeFtdcRtnTradeLogField
{
	///
	TShfeFtdcBoolType	bFlag;
	///
	TShfeFtdcTradeLogStrType	TradeLogStr;
};

///告警时间修改
struct CShfeFtdcReqQryWarningEventUpdateField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件发生日期
	TShfeFtdcDateType	OccurDate;
	///事件发生时间
	TShfeFtdcTimeType	OccurTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///事件标签
	TShfeFtdcVolumeType	EventNum;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///事件描述
	TShfeFtdcTypeDescriptionType	EventDes;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///告警激活日期
	TShfeFtdcDateType	ActiveDate;
	///告警激活时间
	TShfeFtdcTimeType	ActiveTime;
	///事件处理描述
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///事件全名
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///交易系统登录信息查询
struct CShfeFtdcReqQryTradeUserLoginInfoField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///交易系统登录信息应答
struct CShfeFtdcRspQryTradeUserLoginInfoField
{
	///对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///协议信息
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///前置机编号
	TShfeFtdcFrontIDType	FrontID;
	///用户类别
	TShfeFtdcTypeObjectIDType	UserType;
	/// 接入方式
	TShfeFtdcTypeObjectIDType	AccessType;
	///登录或登出日期
	TShfeFtdcDateType	ActionDate;
	///登录或登出时间
	TShfeFtdcTimeType	ActionTime;
	///登录或登出标记
	TShfeFtdcValueTypeType	ActionFlag;
	///数据中心名
	TShfeFtdcTypeObjectIDType	DataCenter;
};

///交易系统登录信息应答
struct CShfeFtdcRtnTradeUserLoginInfoField
{
	///对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///协议信息
	TShfeFtdcProtocolInfoType	ProtocolInfo;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///前置机编号
	TShfeFtdcFrontIDType	FrontID;
	///用户类别
	TShfeFtdcTypeObjectIDType	UserType;
	/// 接入方式
	TShfeFtdcTypeObjectIDType	AccessType;
	///登录或登出日期
	TShfeFtdcDateType	ActionDate;
	///登录或登出时间
	TShfeFtdcTimeType	ActionTime;
	///登录或登出标记
	TShfeFtdcValueTypeType	ActionFlag;
	///数据中心名
	TShfeFtdcTypeObjectIDType	DataCenter;
};

///会员交易查询
struct CShfeFtdcReqQryPartTradeField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///会员交易查询应答
struct CShfeFtdcRspQryPartTradeField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///总报买单量
	TShfeFtdcVolumeType	TotalPositiveOrder;
	///总报单卖量
	TShfeFtdcVolumeType	TotalNegativeOrder;
	///买单总成交量
	TShfeFtdcVolumeType	TotalPositiveTrade;
	///卖单总成交量
	TShfeFtdcVolumeType	TotalNegativeTrade;
	///总多头持仓量
	TShfeFtdcVolumeType	TotalPositivePosi;
	///总空头持仓量
	TShfeFtdcVolumeType	TotalNegativePosi;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///交易峰值查询
struct CShfeFtdcReqQryTradepeakField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///
	TShfeFtdcTradepeakFlagType	TradepeakFlag;
};

///交易峰值查询应答
struct CShfeFtdcRspQryTradepeakField
{
	///统计信息步长分类
	TShfeFtdcTradepeakFlagType	TradepeakFlag;
	///时间
	TShfeFtdcTimeType	PeakTime;
	///报单申请量
	TShfeFtdcVolumeType	InsertOrder;
	///报单操作量
	TShfeFtdcVolumeType	ActionOrder;
	///无效报单量
	TShfeFtdcVolumeType	InvalidOrder;
	///交易合计
	TShfeFtdcVolumeType	TotalBusiness;
	///成交数
	TShfeFtdcVolumeType	TradeCount;
	///合计
	TShfeFtdcVolumeType	TotalCount;
};

///
struct CShfeFtdcRtnUpdateSysConfigField
{
	///更新类型
	TShfeFtdcTypeObjectIDType	UpdateType;
	///旧值
	TShfeFtdcTypeObjectIDType	OldValue;
	///新值
	TShfeFtdcTypeObjectIDType	NewValue;
	///备用
	TShfeFtdcTypeObjectIDType	Standby;
};

///
struct CShfeFtdcRtnSysUserField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///用户姓名
	TShfeFtdcUserIDType	UserName;
	///用户信息
	TShfeFtdcUserInfoType	UserInfo;
	///密码
	TShfeFtdcPasswordType	Password;
	///用户权限
	TShfeFtdcPrivilegeType	Privilege;
	///用户电子邮件
	TShfeFtdcEMailType	EMail;
	///用户电子邮件接收标记
	TShfeFtdcReciveFlagType	EMailFlag;
	///用户固定电话
	TShfeFtdcTelephoneType	HomePhone;
	///用户固定电话接收标记
	TShfeFtdcReciveFlagType	HomePhoneFlag;
	///用户手机
	TShfeFtdcTelephoneType	MobilePhone;
	///用户手机接收标记
	TShfeFtdcReciveFlagType	MobilePhoneFlag;
};

///
struct CShfeFtdcRtnPriceLimitChgField
{
	///操作日期
	TShfeFtdcDateType	ActionDate;
	///操作时间
	TShfeFtdcTimeType	ActionTime;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///取值方式
	TShfeFtdcValueModeType	ValueMode;
	///舍入方式
	TShfeFtdcRoundingModeType	RoundingMode;
	///涨停板价
	TShfeFtdcPriceType	UpperLimitPrice;
	///跌停板价
	TShfeFtdcPriceType	LowerLimitPrice;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///管理平台初始化信息查询
struct CShfeFtdcReqQryParticipantInitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///管理平台初始化信息查询
struct CShfeFtdcReqQryUserInitField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///文件读写标记
struct CShfeFtdcSysFileAccessInfoField
{
	///
	TShfeFtdcTypeObjectIDType	ObjectID;
	///
	TShfeFtdcLargeVolumeType	FileSize;
	///
	TShfeFtdcLargeVolumeType	FileTime;
};

///历史Cpu状态查询
struct CShfeFtdcReqQryHistoryCpuInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///历史Cpu查询应答
struct CShfeFtdcRspQryHistoryCpuInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///CPU的编号
	TShfeFtdcTypeCPUIdType	CPU;
	///
	TShfeFtdcRatioType	LOAD;
	///
	TShfeFtdcRatioType	USER;
	///
	TShfeFtdcRatioType	NICE;
	///
	TShfeFtdcRatioType	SYS;
	///
	TShfeFtdcRatioType	IDLE;
	///
	TShfeFtdcRatioType	BLOCK;
	///
	TShfeFtdcRatioType	SWAIT;
	///
	TShfeFtdcRatioType	INTR;
	///
	TShfeFtdcRatioType	SSYS;
};

///历史Mem状态查询
struct CShfeFtdcReqQryHistoryMemInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///历史Mem查询应答
struct CShfeFtdcRspQryHistoryMemInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///Total Real Memory
	TShfeFtdcVolumeType	TOTALREAL;
	///Active Real Memory
	TShfeFtdcVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	TShfeFtdcVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	TShfeFtdcVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	TShfeFtdcVolumeType	FREE;
};

///历史网络状态查询
struct CShfeFtdcReqQryHistoryNetworkInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///网卡名
	TShfeFtdcTypeLanNameType	LANNAME;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///历史网络查询应答
struct CShfeFtdcRspQryHistoryNetworkInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///网卡名
	TShfeFtdcTypeLanNameType	LANNAME;
	///网卡的up或down状态
	TShfeFtdcTypeLanStatusType	LANSTATUS;
	///网卡的ip地址
	TShfeFtdcIPAddressType	IPADDRESS;
	///网卡接收的流量
	TShfeFtdcLargeNumberType	RECVBYTES;
	///网卡接收的数据包
	TShfeFtdcLargeNumberType	RECVPACKETS;
	///网卡接收端错误数据包
	TShfeFtdcLargeNumberType	RECVERRORPACKETS;
	///网卡接收端丢失数据包
	TShfeFtdcLargeNumberType	RECVDROPPACKETS;
	///网卡发送的流量
	TShfeFtdcLargeNumberType	SENDBYTES;
	///网卡发送的数据包
	TShfeFtdcLargeNumberType	SENDPACKETS;
	///网卡发送端错误数据包
	TShfeFtdcLargeNumberType	SENDERRORPACKETS;
	///网卡发送端丢失数据包
	TShfeFtdcLargeNumberType	SENDDROPPACKETS;
};

///主机配置查询请求应答
struct CShfeFtdcRspQryHostConfigField
{
	///
	TShfeFtdcCfgTypeType	CfgType;
	///
	TShfeFtdcCfgNameType	CfgDataCenter;
	///
	TShfeFtdcTypeObjectIDType	CfgName;
	///
	TShfeFtdcFilePathNameType	CfgLocation;
	///
	TShfeFtdcTypeObjectIDType	CfgHostName;
	///
	TShfeFtdcTypeObjectIDType	CfgAttend;
};

///监控系统在线用户查询
struct CShfeFtdcReqQryMonitorOnlineUserField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///监控系统在线用户应答
struct CShfeFtdcRspQryMonitorOnlineUserField
{
	///用户代码
	TShfeFtdcUserIDType	UserID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
};

///交易系统前置统计查询
struct CShfeFtdcReqQryFrontStatField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///交易系统前置统计应答
struct CShfeFtdcRspQryFrontStatField
{
	///前置机编号
	TShfeFtdcFrontIDType	FrontID;
	///总报买笔数
	TShfeFtdcVolumeType	PositiveOrder;
	///总报卖笔数
	TShfeFtdcVolumeType	NegativeOrder;
	///总报买手数
	TShfeFtdcVolumeType	TotalPositiveOrder;
	///总报卖手数
	TShfeFtdcVolumeType	TotalNegativeOrder;
	///报单状态改变笔数
	TShfeFtdcVolumeType	OrderAction;
	///报单状态改变手数
	TShfeFtdcVolumeType	TotalOrderAction;
};

///监控系统时钟同步
struct CShfeFtdcRtnSysTimeSyncField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
};

///数据中心切换通知
struct CShfeFtdcRtnDataCenterChgField
{
	///主数据中心名
	TShfeFtdcTypeObjectIDType	DataCenterID;
};

///历史峰值查询
struct CShfeFtdcReqQryHistoryTradePeakField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///历史峰值查询应答
struct CShfeFtdcRspQryHistoryTradePeakField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控最新日期
	TShfeFtdcDateType	MonDate;
	///监控最新时间
	TShfeFtdcTimeType	MonTime;
	///监控指标
	TShfeFtdcAttrTypeType	AttrType;
	///监控最新值
	TShfeFtdcMoneyType	AttrValue;
	///相关指标
	TShfeFtdcAttrTypeType	RltAttrType;
	///相关指标当时的值
	TShfeFtdcMoneyType	RltAttrValue;
	///最大值的日期
	TShfeFtdcDateType	MaxMonDate;
	///最大值的时间
	TShfeFtdcTimeType	MaxMonTime;
	///指标历史最大值
	TShfeFtdcMoneyType	MaxAttrValue;
	///相关指标当时的值
	TShfeFtdcMoneyType	MaxRltAttrValue;
	///次新值的日期
	TShfeFtdcDateType	OldMonDate;
	///次新值的时间
	TShfeFtdcTimeType	OldMonTime;
	///监控指标的次新值
	TShfeFtdcMoneyType	OldAttrValue;
	///相关指标当时的值
	TShfeFtdcMoneyType	OldRltAttrValue;
};

///历史峰值查询应答
struct CShfeFtdcRtnHistoryTradePeakField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控最新日期
	TShfeFtdcDateType	MonDate;
	///监控最新时间
	TShfeFtdcTimeType	MonTime;
	///监控指标
	TShfeFtdcAttrTypeType	AttrType;
	///监控最新值
	TShfeFtdcMoneyType	AttrValue;
	///相关指标
	TShfeFtdcAttrTypeType	RltAttrType;
	///相关指标当时的值
	TShfeFtdcMoneyType	RltAttrValue;
	///最大值的日期
	TShfeFtdcDateType	MaxMonDate;
	///最大值的时间
	TShfeFtdcTimeType	MaxMonTime;
	///指标历史最大值
	TShfeFtdcMoneyType	MaxAttrValue;
	///相关指标当时的值
	TShfeFtdcMoneyType	MaxRltAttrValue;
	///次新值的日期
	TShfeFtdcDateType	OldMonDate;
	///次新值的时间
	TShfeFtdcTimeType	OldMonTime;
	///监控指标的次新值
	TShfeFtdcMoneyType	OldAttrValue;
	///相关指标当时的值
	TShfeFtdcMoneyType	OldRltAttrValue;
};

///日志事件查询
struct CShfeFtdcReqQrySyslogEventField
{
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
};

///日志事件查询应答
struct CShfeFtdcRspQrySyslogEventField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件发生日期
	TShfeFtdcDateType	OccurDate;
	///事件发生时间
	TShfeFtdcTimeType	OccurTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///事件标签
	TShfeFtdcVolumeType	EventNum;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///事件描述
	TShfeFtdcTypeDescriptionType	EventDes;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///事件处理描述
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///事件全名
	TShfeFtdcNetAttrTypeType	FullEventName;
	///事件条数
	TShfeFtdcCounterType	EventCount;
};

///日志事件应答
struct CShfeFtdcRtnSyslogEventField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件发生日期
	TShfeFtdcDateType	OccurDate;
	///事件发生时间
	TShfeFtdcTimeType	OccurTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///事件标签
	TShfeFtdcVolumeType	EventNum;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///事件描述
	TShfeFtdcTypeDescriptionType	EventDes;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///事件处理描述
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///事件全名
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///日志事件订阅请求
struct CShfeFtdcReqQrySyslogEventSubcriberField
{
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///过滤条件组
	TShfeFtdcTypeSubcriberObjectIDType	filter;
	///反过滤条件组
	TShfeFtdcTypeSubcriberObjectIDType	antifilter;
	///初次返回对象数
	TShfeFtdcVolumeType	ObjectNum;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
	///返回的初始日期
	TShfeFtdcDateType	MonDate;
	///返回的初始时间
	TShfeFtdcTimeType	MonTime;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
};

///交易日切换通知
struct CShfeFtdcReqQryTradeDayChangeField
{
	///切换类型
	TShfeFtdcTypeObjectIDType	ChangeType;
	///原交易日
	TShfeFtdcDateType	OldDate;
	///新交易日
	TShfeFtdcDateType	NewDate;
};

///交易日切换通知
struct CShfeFtdcRspQryTradeDayChangeField
{
	///切换类型
	TShfeFtdcTypeObjectIDType	ChangeType;
	///原交易日
	TShfeFtdcDateType	OldDate;
	///新交易日
	TShfeFtdcDateType	NewDate;
};

///tomcat信息查询
struct CShfeFtdcReqQryTomcatInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
};

///Web应用信息
struct CShfeFtdcRspQryWebAppInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///Web应用名称
	TShfeFtdcCfgNameType	AppName;
	///应用运行状态
	TShfeFtdcTypeObjectNameType	Status;
	///应用描述信息
	TShfeFtdcTypeDescriptionType	Desc;
	///应用启动时间
	TShfeFtdcTypeCurrentTimeType	StartTime;
	///应用servlet数量
	TShfeFtdcTypeChar10Type	ServletNum;
	///应用处理总时长
	TShfeFtdcTypeCommandType	ProcessTime;
	///应用累计接收请求数
	TShfeFtdcTypeCommandType	RequestNum;
	///应用累计错误数
	TShfeFtdcTypeCommandType	ErrorNum;
	///应用当前会话数
	TShfeFtdcTypeChar10Type	SessionSize;
	///会话超时时长(秒)
	TShfeFtdcTypeChar10Type	TimeOut;
	///应用JDBC连接使用率
	TShfeFtdcTypeChar10Type	JDBCUsage;
	///应用JSP文件数量
	TShfeFtdcTypeChar10Type	JSPNum;
};

///Web应用信息
struct CShfeFtdcRtnWebAppInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///Web应用名称
	TShfeFtdcCfgNameType	AppName;
	///应用运行状态
	TShfeFtdcTypeObjectNameType	Status;
	///应用描述信息
	TShfeFtdcTypeDescriptionType	Desc;
	///应用启动时间
	TShfeFtdcTypeCurrentTimeType	StartTime;
	///应用servlet数量
	TShfeFtdcTypeChar10Type	ServletNum;
	///应用处理总时长
	TShfeFtdcTypeCommandType	ProcessTime;
	///应用累计接收请求数
	TShfeFtdcTypeCommandType	RequestNum;
	///应用累计错误数
	TShfeFtdcTypeCommandType	ErrorNum;
	///应用当前会话数
	TShfeFtdcTypeChar10Type	SessionSize;
	///会话超时时长(秒)
	TShfeFtdcTypeChar10Type	TimeOut;
	///应用JDBC连接使用率
	TShfeFtdcTypeChar10Type	JDBCUsage;
	///应用JSP文件数量
	TShfeFtdcTypeChar10Type	JSPNum;
};

///应用servlet信息
struct CShfeFtdcRspQryServletInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///servlet名称
	TShfeFtdcTypeObjectIDType	Name;
	///加载耗时
	TShfeFtdcTypeContLenType	LoadTime;
	///接收请求数量
	TShfeFtdcRatioType	RequestNum;
	///错误数量
	TShfeFtdcRatioType	RequestErrNum;
	///处理时长
	TShfeFtdcRatioType	ProcessTime;
	///最小处理时间
	TShfeFtdcTypeContLenType	MixTime;
	///最大处理时间
	TShfeFtdcTypeContLenType	MaxTime;
};

///应用servlet信息
struct CShfeFtdcRtnServletInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///servlet名称
	TShfeFtdcTypeObjectIDType	Name;
	///加载耗时
	TShfeFtdcTypeContLenType	LoadTime;
	///接收请求数量
	TShfeFtdcRatioType	RequestNum;
	///错误数量
	TShfeFtdcRatioType	RequestErrNum;
	///处理时长
	TShfeFtdcRatioType	ProcessTime;
	///最小处理时间
	TShfeFtdcTypeContLenType	MixTime;
	///最大处理时间
	TShfeFtdcTypeContLenType	MaxTime;
};

///文件信息
struct CShfeFtdcRspQryFileInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///文件全路径名
	TShfeFtdcFilePathNameType	PathName;
	///文件大小
	TShfeFtdcTypeChar10Type	FileSize;
	///文件最后修改时间
	TShfeFtdcTypeMonitorTypeType	LastModDate;
	///文件属性
	TShfeFtdcTypeObjectNameType	FileType;
};

///文件信息
struct CShfeFtdcRtnFileInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///文件全路径名
	TShfeFtdcFilePathNameType	PathName;
	///文件大小
	TShfeFtdcTypeChar10Type	FileSize;
	///文件最后修改时间
	TShfeFtdcTypeMonitorTypeType	LastModDate;
	///文件属性
	TShfeFtdcTypeObjectNameType	FileType;
};

///应用会话信息
struct CShfeFtdcRspQrySessionInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///Session编号
	TShfeFtdcCfgNameType	SessionID;
	///Session名称
	TShfeFtdcTypeObjectIDType	SessionName;
	///Session对应客户端IP地址
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///Session创建时间
	TShfeFtdcTypeHostModelType	BeginTime;
	///Session最新请求时间
	TShfeFtdcTypeHostModelType	LatestTime;
	///Session超时时间(秒)
	TShfeFtdcTypeContLenType	MaxIdleTime;
};

///应用会话信息
struct CShfeFtdcRtnSessionInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///Session编号
	TShfeFtdcCfgNameType	SessionID;
	///Session名称
	TShfeFtdcTypeObjectIDType	SessionName;
	///Session对应客户端IP地址
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///Session创建时间
	TShfeFtdcTypeHostModelType	BeginTime;
	///Session最新请求时间
	TShfeFtdcTypeHostModelType	LatestTime;
	///Session超时时间(秒)
	TShfeFtdcTypeContLenType	MaxIdleTime;
};

///JDBC信息
struct CShfeFtdcRspQryJDBCInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///应用程序名称
	TShfeFtdcCfgNameType	AppName;
	///JDBC连接池名称
	TShfeFtdcCfgNameType	Name;
	///连接池使用比例
	TShfeFtdcStockPercentType	Usage;
	///最大连接数
	TShfeFtdcTypeContLenType	ConnNumMax;
	///空闲连接数
	TShfeFtdcTypeContLenType	ConnNumFree;
	///不可重用连接数
	TShfeFtdcTypeContLenType	ConnNumUnRU;
	///可重用连接数
	TShfeFtdcTypeContLenType	ConnNumRU;
	///对应数据库用户
	TShfeFtdcCfgNameType	UserName;
	///JDBC类型
	TShfeFtdcTypeObjectIDType	Type;
	///JDBC Url
	TShfeFtdcTypeObjectIDType	URL;
};

///JDBC信息
struct CShfeFtdcRtnJDBCInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///应用程序名称
	TShfeFtdcCfgNameType	AppName;
	///JDBC连接池名称
	TShfeFtdcCfgNameType	Name;
	///连接池使用比例
	TShfeFtdcStockPercentType	Usage;
	///最大连接数
	TShfeFtdcTypeContLenType	ConnNumMax;
	///空闲连接数
	TShfeFtdcTypeContLenType	ConnNumFree;
	///不可重用连接数
	TShfeFtdcTypeContLenType	ConnNumUnRU;
	///可重用连接数
	TShfeFtdcTypeContLenType	ConnNumRU;
	///对应数据库用户
	TShfeFtdcCfgNameType	UserName;
	///JDBC类型
	TShfeFtdcTypeObjectIDType	Type;
	///JDBC Url
	TShfeFtdcTypeObjectIDType	URL;
};

///线程信息
struct CShfeFtdcRspQryThreadInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///线程名称
	TShfeFtdcTypeObjectIDType	Name;
	///线程编号
	TShfeFtdcTypeContLenType	ThreadNum;
	///线程状态
	TShfeFtdcTypeObjectNameType	ThreadStatus;
	///线程Native标识
	TShfeFtdcTypeContLenType	InNative;
	///线程Suspended标识
	TShfeFtdcTypeLanNameType	Suspended;
	///线程阻塞总数
	TShfeFtdcTypeLanNameType	BlockCount;
	///线程等待总数
	TShfeFtdcTypeContLenType	WaitCount;
	///线程CPU时间
	TShfeFtdcRatioType	CpuTime;
	///线程用户时间
	TShfeFtdcRatioType	UserTime;
};

///线程信息
struct CShfeFtdcRtnThreadInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///线程名称
	TShfeFtdcTypeObjectIDType	Name;
	///线程编号
	TShfeFtdcTypeContLenType	ThreadNum;
	///线程状态
	TShfeFtdcTypeObjectNameType	ThreadStatus;
	///线程Native标识
	TShfeFtdcTypeContLenType	InNative;
	///线程Suspended标识
	TShfeFtdcTypeLanNameType	Suspended;
	///线程阻塞总数
	TShfeFtdcTypeLanNameType	BlockCount;
	///线程等待总数
	TShfeFtdcTypeContLenType	WaitCount;
	///线程CPU时间
	TShfeFtdcRatioType	CpuTime;
	///线程用户时间
	TShfeFtdcRatioType	UserTime;
};

///虚拟机信息查询
struct CShfeFtdcReqQryVMInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
};

///虚拟机信息
struct CShfeFtdcRspQryVMInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///虚拟机名称
	TShfeFtdcTypeObjectIDType	Name;
	///虚拟机类型
	TShfeFtdcTypeObjectIDType	VmName;
	///供应商
	TShfeFtdcTypeObjectIDType	VmVendor;
	///虚拟机版本
	TShfeFtdcTypeObjectIDType	VmVersion;
	///启动时间
	TShfeFtdcTypeObjectIDType	StartTime;
	///启动类路径
	TShfeFtdcTypeFileContentType	BootClassPath;
	///类路径
	TShfeFtdcTypeFileContentType	ClassPath;
	///库路径
	TShfeFtdcTypeFileContentType	LibraryPath;
	///启动参数
	TShfeFtdcTypeFileContentType	Arguments;
};

///虚拟机信息
struct CShfeFtdcRtnVMInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///虚拟机名称
	TShfeFtdcTypeObjectIDType	Name;
	///虚拟机类型
	TShfeFtdcTypeObjectIDType	VmName;
	///供应商
	TShfeFtdcTypeObjectIDType	VmVendor;
	///虚拟机版本
	TShfeFtdcTypeObjectIDType	VmVersion;
	///启动时间
	TShfeFtdcTypeObjectIDType	StartTime;
	///启动类路径
	TShfeFtdcTypeFileContentType	BootClassPath;
	///类路径
	TShfeFtdcTypeFileContentType	ClassPath;
	///库路径
	TShfeFtdcTypeFileContentType	LibraryPath;
	///启动参数
	TShfeFtdcTypeFileContentType	Arguments;
};

///系统属性信息查询
struct CShfeFtdcReqQryPropertyInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
};

///系统属性信息
struct CShfeFtdcRspQryPropertyInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///系统属性名
	TShfeFtdcTypeObjectIDType	Property;
	///分割标识
	TShfeFtdcTypeContLenType	ClipFlag;
	///属性值
	TShfeFtdcFilePathNameType	Value;
};

///系统属性信息
struct CShfeFtdcRtnPropertyInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///系统属性名
	TShfeFtdcTypeObjectIDType	Property;
	///分割标识
	TShfeFtdcTypeContLenType	ClipFlag;
	///属性值
	TShfeFtdcFilePathNameType	Value;
};

///系统内存池信息查询
struct CShfeFtdcReqQryMemPoolInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
};

///系统内存池信息
struct CShfeFtdcRspQryMemPoolInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///系统属性名
	TShfeFtdcCfgNameType	PoolName;
	///系统属性名
	TShfeFtdcTypeChar10Type	Usage;
	///系统属性名
	TShfeFtdcTypeCommandType	committedbytes;
	///系统属性名
	TShfeFtdcTypeCommandType	initbytes;
	///系统属性名
	TShfeFtdcTypeCommandType	maxbytes;
	///系统属性名
	TShfeFtdcTypeCommandType	usedbytes;
	///系统属性名
	TShfeFtdcTypeChar10Type	Type;
};

///系统内存池信息
struct CShfeFtdcRtnMemPoolInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///系统属性名
	TShfeFtdcCfgNameType	PoolName;
	///系统属性名
	TShfeFtdcTypeChar10Type	Usage;
	///系统属性名
	TShfeFtdcTypeCommandType	committedbytes;
	///系统属性名
	TShfeFtdcTypeCommandType	initbytes;
	///系统属性名
	TShfeFtdcTypeCommandType	maxbytes;
	///系统属性名
	TShfeFtdcTypeCommandType	usedbytes;
	///系统属性名
	TShfeFtdcTypeChar10Type	Type;
};

///文件内容信息查询
struct CShfeFtdcReqQryFileContentInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
};

///文件内容信息
struct CShfeFtdcRspQryFileContentInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///文件名
	TShfeFtdcFilePathNameType	FileName;
	///文件内容
	TShfeFtdcTypeFileContentType	FileContent;
};

///文件内容信息
struct CShfeFtdcRtnFileContentInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///文件名
	TShfeFtdcFilePathNameType	FileName;
	///文件内容
	TShfeFtdcTypeFileContentType	FileContent;
};

///连接信息查询
struct CShfeFtdcReqQryConnectionInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
};

///连接信息
struct CShfeFtdcRspQryConnectionInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///服务线程名
	TShfeFtdcCfgNameType	ServiceName;
	///当前状态
	TShfeFtdcTypeChar10Type	Stage;
	///累计接收请求数
	TShfeFtdcRatioType	RequestCount;
	///累计错误数
	TShfeFtdcRatioType	ErrorCount;
	///累计处理时长
	TShfeFtdcRatioType	ProcTime;
	///累计接收字节数
	TShfeFtdcRatioType	BytesReceived;
	///累计发送字节数
	TShfeFtdcRatioType	BytesSent;
	///远程IP地址
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///最大请求URI
	TShfeFtdcAttrTypeType	MaxAccessURI;
};

///连接信息
struct CShfeFtdcRtnConnectionInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///服务线程名
	TShfeFtdcCfgNameType	ServiceName;
	///当前状态
	TShfeFtdcTypeChar10Type	Stage;
	///累计接收请求数
	TShfeFtdcRatioType	RequestCount;
	///累计错误数
	TShfeFtdcRatioType	ErrorCount;
	///累计处理时长
	TShfeFtdcRatioType	ProcTime;
	///累计接收字节数
	TShfeFtdcRatioType	BytesReceived;
	///累计发送字节数
	TShfeFtdcRatioType	BytesSent;
	///远程IP地址
	TShfeFtdcTypeObjectNameType	RemoteIP;
	///最大请求URI
	TShfeFtdcAttrTypeType	MaxAccessURI;
};

///连接器信息查询
struct CShfeFtdcReqQryConnectorInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
};

///连接器信息
struct CShfeFtdcRspQryConnectorInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///连接器名称
	TShfeFtdcTypeObjectNameType	Name;
	///当前处理线程数
	TShfeFtdcTypeChar10Type	ThreadsCount;
	///当前繁忙线程数
	TShfeFtdcTypeChar10Type	BusyThreadsCount;
	///最大线程数
	TShfeFtdcTypeChar10Type	MaxThreads;
	///最大空闲线程数
	TShfeFtdcTypeChar10Type	MaxSpareThreads;
	///最小空闲线程数
	TShfeFtdcTypeChar10Type	MinSpareThreads;
	///最长连接时间
	TShfeFtdcTypeCommandType	MaxTime;
	///最长处理时间
	TShfeFtdcTypeCommandType	MaxProcTime;
	///累计接收请求数
	TShfeFtdcTypeCommandType	RequestCount;
	///累计错误数
	TShfeFtdcTypeCommandType	ErrorCount;
	///累计接收字节数
	TShfeFtdcTypeChar10Type	BytesReceived;
	///累计发送字节数
	TShfeFtdcTypeChar10Type	BytesSent;
};

///连接器信息
struct CShfeFtdcRtnConnectorInfoField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///连接器名称
	TShfeFtdcTypeObjectNameType	Name;
	///当前处理线程数
	TShfeFtdcTypeChar10Type	ThreadsCount;
	///当前繁忙线程数
	TShfeFtdcTypeChar10Type	BusyThreadsCount;
	///最大线程数
	TShfeFtdcTypeChar10Type	MaxThreads;
	///最大空闲线程数
	TShfeFtdcTypeChar10Type	MaxSpareThreads;
	///最小空闲线程数
	TShfeFtdcTypeChar10Type	MinSpareThreads;
	///最长连接时间
	TShfeFtdcTypeCommandType	MaxTime;
	///最长处理时间
	TShfeFtdcTypeCommandType	MaxProcTime;
	///累计接收请求数
	TShfeFtdcTypeCommandType	RequestCount;
	///累计错误数
	TShfeFtdcTypeCommandType	ErrorCount;
	///累计接收字节数
	TShfeFtdcTypeChar10Type	BytesReceived;
	///累计发送字节数
	TShfeFtdcTypeChar10Type	BytesSent;
};

///数据库查询
struct CShfeFtdcReqQryDBQueryField
{
	///数据库实例对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///存储过程名
	TShfeFtdcAttrTypeType	AttrType;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
};

///数据库查询应答
struct CShfeFtdcRspQryDBQueryField
{
	///数据库实例对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///存储过程名
	TShfeFtdcAttrTypeType	AttrType;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///数据库查询结果
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///数据库查询应答
struct CShfeFtdcRtnDBQueryField
{
	///数据库实例对象ID
	TShfeFtdcTypeObjectIDType	ObjectID;
	///存储过程名
	TShfeFtdcAttrTypeType	AttrType;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///数据库查询结果
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///通用返回应答
struct CShfeFtdcSysGeneralFieldField
{
	///监控日期
	TShfeFtdcDateType	MonDate;
	///监控时间
	TShfeFtdcTimeType	MonTime;
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///子监控对象
	TShfeFtdcTypeObjectIDType	SubObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
	///通用返回字段
	TShfeFtdcGeneralResultType	Content;
};

///文件传输请求
struct CShfeFtdcReqQryGetFileField
{
	///文件名称
	TShfeFtdcNetAttrTypeType	FileName;
	///文件版本
	TShfeFtdcFileVersionType	Version;
	///文件偏移
	TShfeFtdcOffsetType	Offset;
};

///文件传输应答
struct CShfeFtdcRspQryGetFileField
{
	///文件名称
	TShfeFtdcNetAttrTypeType	FileName;
	///文件版本
	TShfeFtdcFileVersionType	Version;
	///文件偏移
	TShfeFtdcOffsetType	Offset;
	///Comment中实际内容长度
	TShfeFtdcCommLengthType	Length;
	///文件内容
	TShfeFtdcFileCommentType	Comment;
};

///日志事件修改请求
struct CShfeFtdcReqQrySyslogEventUpdateField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件发生日期
	TShfeFtdcDateType	OccurDate;
	///事件发生时间
	TShfeFtdcTimeType	OccurTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///发生事件的对象ID指标
	TShfeFtdcNetAttrTypeType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///事件名
	TShfeFtdcTypeObjectIDType	EventName;
	///事件标签
	TShfeFtdcVolumeType	EventNum;
	///事件类型
	TShfeFtdcVolumeType	EventType;
	///事件描述
	TShfeFtdcTypeDescriptionType	EventDes;
	///清除标记
	TShfeFtdcTypeProcessFlagType	ProcessFlag;
	///警告级别
	TShfeFtdcTypeWarningLevelType	WarningLevel;
	///事件处理描述
	TShfeFtdcTypeObjectIDType	EventDealDes;
	///事件全名
	TShfeFtdcNetAttrTypeType	FullEventName;
};

///告警明细查询
struct CShfeFtdcReqQryWarningQueryField
{
	///事件ID
	TShfeFtdcVolumeType	EvendID;
};

///告警明细
struct CShfeFtdcRspQryWarningQueryField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///数据库查询结果
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///告警明细
struct CShfeFtdcRtnWarningQueryField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///事件ID
	TShfeFtdcVolumeType	EvendID;
	///数据库查询结果
	TShfeFtdcDBQueryResultType	DBQueryResult;
};

///网站访问查询
struct CShfeFtdcReqQryWebVisitField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///监控指标
	TShfeFtdcFilePathNameType	AttrType;
	///起始日期
	TShfeFtdcDateType	BeginDate;
	///起始时间
	TShfeFtdcTimeType	BeginTime;
	///结束日期
	TShfeFtdcDateType	EndDate;
	///结束时间
	TShfeFtdcTimeType	EndTime;
};

///主机配置查询订阅应答
struct CShfeFtdcRtnHostConfigField
{
	///
	TShfeFtdcCfgTypeType	CfgType;
	///
	TShfeFtdcCfgNameType	CfgDataCenter;
	///
	TShfeFtdcTypeObjectIDType	CfgName;
	///
	TShfeFtdcFilePathNameType	CfgLocation;
	///
	TShfeFtdcTypeObjectIDType	CfgHostName;
	///
	TShfeFtdcTypeObjectIDType	CfgAttend;
};

///告警激活变更
struct CShfeFtdcReqQryWarningActiveChangeField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///日期
	TShfeFtdcDateType	MonDate;
	///时间
	TShfeFtdcTimeType	MonTime;
	///告警事件产生标志位
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///告警激活变更
struct CShfeFtdcRspQryWarningActiveChangeField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///日期
	TShfeFtdcDateType	MonDate;
	///时间
	TShfeFtdcTimeType	MonTime;
	///告警事件产生标志位
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///告警激活变更
struct CShfeFtdcRtnWarningActiveChangeField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///日期
	TShfeFtdcDateType	MonDate;
	///时间
	TShfeFtdcTimeType	MonTime;
	///告警事件产生标志位
	TShfeFtdcTypeIsActiveType	WarningActive;
};

///通用操作
struct CShfeFtdcReqQryGeneralOperateField
{
	///通用操作类型
	TShfeFtdcGeneralOperateTypeType	GeneralOperateType;
	///通用操作表
	TShfeFtdcGeneralOperateTableType	GeneralOperateTable;
	///通用操作选项
	TShfeFtdcGeneralOperateOptionType	GeneralOperateOption;
	///通用操作集
	TShfeFtdcGeneralOperateSetType	GeneralOperateSet;
};

///通用操作
struct CShfeFtdcRspQryGeneralOperateField
{
	///通用操作类型
	TShfeFtdcGeneralOperateTypeType	GeneralOperateType;
	///通用操作表
	TShfeFtdcGeneralOperateTableType	GeneralOperateTable;
	///通用操作选项
	TShfeFtdcGeneralOperateOptionType	GeneralOperateOption;
	///通用操作集
	TShfeFtdcGeneralOperateSetType	GeneralOperateSet;
};

///通用操作
struct CShfeFtdcRtnGeneralOperateField
{
	///通用操作类型
	TShfeFtdcGeneralOperateTypeType	GeneralOperateType;
	///通用操作表
	TShfeFtdcGeneralOperateTableType	GeneralOperateTable;
	///通用操作选项
	TShfeFtdcGeneralOperateOptionType	GeneralOperateOption;
	///通用操作集
	TShfeFtdcGeneralOperateSetType	GeneralOperateSet;
};

///网络设备连接关系请求
struct CShfeFtdcReqQryNetDeviceLinkedField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///人为划分的职能区域
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP码
	TShfeFtdcVolumeType	IPDECODE;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
};

///网络设备连接关系
struct CShfeFtdcRspQryNetDeviceLinkedField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备ID
	TShfeFtdcVolumeType	NetDeviceID;
	///设备端口ID
	TShfeFtdcVolumeType	NetPortID;
	///监控对象
	TShfeFtdcNetObjectIDType	NetObjectID;
	///监控对象端口类型
	TShfeFtdcNetDevicePortTypeType	NetPortType;
	///连接设备ID
	TShfeFtdcVolumeType	LinkNetDeviceID;
	///连接设备端口ID
	TShfeFtdcVolumeType	LinkNetPortID;
	///连接对象
	TShfeFtdcNetObjectIDType	LinkNetObjectID;
	///连接对象端口类型
	TShfeFtdcNetDevicePortTypeType	LinkNetPortType;
	///链接来源
	TShfeFtdcVolumeType	LinkSource;
};

///网络设备连接关系
struct CShfeFtdcRtnNetDeviceLinkedField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备ID
	TShfeFtdcVolumeType	NetDeviceID;
	///设备端口ID
	TShfeFtdcVolumeType	NetPortID;
	///监控对象
	TShfeFtdcNetObjectIDType	NetObjectID;
	///监控对象端口类型
	TShfeFtdcNetDevicePortTypeType	NetPortType;
	///连接设备ID
	TShfeFtdcVolumeType	LinkNetDeviceID;
	///连接设备端口ID
	TShfeFtdcVolumeType	LinkNetPortID;
	///连接对象
	TShfeFtdcNetObjectIDType	LinkNetObjectID;
	///连接对象端口类型
	TShfeFtdcNetDevicePortTypeType	LinkNetPortType;
	///链接来源
	TShfeFtdcVolumeType	LinkSource;
};

///交易系统登录信息请求
struct CShfeFtdcReqQryTradeUserLoginStatField
{
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
};

///交易系统登录信息
struct CShfeFtdcRspQryTradeUserLoginStatField
{
	///登录日期
	TShfeFtdcDateType	MonDate;
	///登录时间
	TShfeFtdcTimeType	MonTime;
	///监控对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///前置机名
	TShfeFtdcTypeObjectIDType	FrontId;
};

///交易系统前置报单响应信息
struct CShfeFtdcReqQryTradeFrontOrderRttStatField
{
	///前置对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///报单日期
	TShfeFtdcDateType	MonDate;
	///报单查询起始时间
	TShfeFtdcTimeType	MonStartTime;
	///报单查询结束时间
	TShfeFtdcTimeType	MonEndTime;
};

///交易系统前置报单响应信息
struct CShfeFtdcRspQryTradeFrontOrderRttStatField
{
	///报单日期
	TShfeFtdcDateType	MonDate;
	///报单时间
	TShfeFtdcTimeType	MonTime;
	///前置对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///报单量
	TShfeFtdcLargeNumberType	OrderCount;
	///报单响应时间和
	TShfeFtdcLargeNumberType	OrderRttSum;
	///最大报单响应时间
	TShfeFtdcVolumeType	OrderMaxRtt;
	///最小报单响应时间
	TShfeFtdcVolumeType	OrderMinRtt;
	///1秒内响应时间均差
	TShfeFtdcVolumeType	OrderRttSqu;
	///1秒内响应时间分布
	TShfeFtdcNumberListsType	OrderRttCutDistrib;
};

///交易系统前置报单响应信息
struct CShfeFtdcRtnTradeFrontOrderRttStatField
{
	///报单日期
	TShfeFtdcDateType	MonDate;
	///报单时间
	TShfeFtdcTimeType	MonTime;
	///前置对象
	TShfeFtdcTypeObjectIDType	ObjectID;
	///报单量
	TShfeFtdcLargeNumberType	OrderCount;
	///报单响应时间和
	TShfeFtdcLargeNumberType	OrderRttSum;
	///最大报单响应时间
	TShfeFtdcVolumeType	OrderMaxRtt;
	///最小报单响应时间
	TShfeFtdcVolumeType	OrderMinRtt;
	///1秒内响应时间均差
	TShfeFtdcVolumeType	OrderRttSqu;
	///1秒内响应时间分布
	TShfeFtdcNumberListsType	OrderRttCutDistrib;
};

///会员席位交易状态
struct CShfeFtdcReqQryParticTradeOrderStatesField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///报单日期
	TShfeFtdcDateType	MonDate;
	///报单查询起始时间
	TShfeFtdcTimeType	MonStartTime;
	///报单查询结束时间
	TShfeFtdcTimeType	MonEndTime;
};

///会员席位交易状态
struct CShfeFtdcRspQryParticTradeOrderStatesField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///报单统计日期
	TShfeFtdcDateType	MonDate;
	///报单统计时间
	TShfeFtdcTimeType	MonTime;
	///统计时长(sec)
	TShfeFtdcVolumeType	StaticWidth;
	///前置ID
	TShfeFtdcVolumeType	FrontID;
	///报单数
	TShfeFtdcVolumeType	OrderCount;
	///撤单数
	TShfeFtdcVolumeType	CancleCount;
	///查询数
	TShfeFtdcVolumeType	QueryCount;
	///成交数
	TShfeFtdcVolumeType	TradeCount;
	///成交金额
	TShfeFtdcVolumeType	TradeMoney;
	///最大报单数
	TShfeFtdcVolumeType	OrderCntMax;
	///最大撤单数
	TShfeFtdcVolumeType	CancleCntMax;
	///最大查询数
	TShfeFtdcVolumeType	QueryCntMax;
	///最大成交数
	TShfeFtdcVolumeType	TradeCntMax;
	///最大成交金额
	TShfeFtdcVolumeType	TradeMoneyMax;
};

///会员席位交易状态
struct CShfeFtdcRtnParticTradeOrderStatesField
{
	///会员代码
	TShfeFtdcParticipantIDType	ParticipantID;
	///交易用户代码
	TShfeFtdcUserIDType	UserID;
	///报单统计日期
	TShfeFtdcDateType	MonDate;
	///报单统计时间
	TShfeFtdcTimeType	MonTime;
	///统计时长(sec)
	TShfeFtdcVolumeType	StaticWidth;
	///前置ID
	TShfeFtdcVolumeType	FrontID;
	///报单数
	TShfeFtdcVolumeType	OrderCount;
	///撤单数
	TShfeFtdcVolumeType	CancleCount;
	///查询数
	TShfeFtdcVolumeType	QueryCount;
	///成交数
	TShfeFtdcVolumeType	TradeCount;
	///成交金额
	TShfeFtdcVolumeType	TradeMoney;
	///最大报单数
	TShfeFtdcVolumeType	OrderCntMax;
	///最大撤单数
	TShfeFtdcVolumeType	CancleCntMax;
	///最大查询数
	TShfeFtdcVolumeType	QueryCntMax;
	///最大成交数
	TShfeFtdcVolumeType	TradeCntMax;
	///最大成交金额
	TShfeFtdcVolumeType	TradeMoneyMax;
};

///系统路由信息
struct CShfeFtdcReqQryRouterInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///系统路由信息
struct CShfeFtdcRspQryRouterInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///设备接口名
	TShfeFtdcTypeCommandType	Dev;
	///目标网段ip地址
	TShfeFtdcIPAddressType	Destination;
	///网关ip地址
	TShfeFtdcIPAddressType	Gateway;
	///掩码ip地址
	TShfeFtdcIPAddressType	Mask;
	///网络状态
	TShfeFtdcTypeLanStatusType	Flag;
	///关联计数
	TShfeFtdcVolumeType	RefCnt;
	///使用计数
	TShfeFtdcVolumeType	Use;
	///metric值
	TShfeFtdcVolumeType	Metric;
	///mtu值
	TShfeFtdcVolumeType	Mtu;
	///win值
	TShfeFtdcVolumeType	Win;
	///rtt值
	TShfeFtdcVolumeType	Rtt;
};

///系统路由信息
struct CShfeFtdcRtnRouterInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///设备接口名
	TShfeFtdcTypeCommandType	Dev;
	///目标网段ip地址
	TShfeFtdcIPAddressType	Destination;
	///网关ip地址
	TShfeFtdcIPAddressType	Gateway;
	///掩码ip地址
	TShfeFtdcIPAddressType	Mask;
	///网络状态
	TShfeFtdcTypeLanStatusType	Flag;
	///关联计数
	TShfeFtdcVolumeType	RefCnt;
	///使用计数
	TShfeFtdcVolumeType	Use;
	///metric值
	TShfeFtdcVolumeType	Metric;
	///mtu值
	TShfeFtdcVolumeType	Mtu;
	///win值
	TShfeFtdcVolumeType	Win;
	///rtt值
	TShfeFtdcVolumeType	Rtt;
};

///磁盘I/O信息
struct CShfeFtdcReqQryDiskIOField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///磁盘I/O信息
struct CShfeFtdcRspQryDiskIOField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///分区名
	TShfeFtdcTypeCommandType	PartName;
	///每秒ReadMerge数
	TShfeFtdcPriceType	ReadMerges;
	///每秒WriteMerge数
	TShfeFtdcPriceType	WriteMerges;
	///每秒ReadIO数
	TShfeFtdcPriceType	ReadIOs;
	///每秒WriteIO数
	TShfeFtdcPriceType	WriteIOs;
	///每秒Read字节数
	TShfeFtdcPriceType	ReadKBs;
	///每秒Write字节数
	TShfeFtdcPriceType	WriteKBs;
	///Size值
	TShfeFtdcPriceType	SizeVal;
	///Queue值
	TShfeFtdcPriceType	QueueVal;
	///Svc_t值
	TShfeFtdcPriceType	Svc_t;
	///繁忙百分率
	TShfeFtdcRatioType	Busy;
};

///磁盘I/O信息
struct CShfeFtdcRtnDiskIOField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///分区名
	TShfeFtdcTypeCommandType	PartName;
	///每秒ReadMerge数
	TShfeFtdcPriceType	ReadMerges;
	///每秒WriteMerge数
	TShfeFtdcPriceType	WriteMerges;
	///每秒ReadIO数
	TShfeFtdcPriceType	ReadIOs;
	///每秒WriteIO数
	TShfeFtdcPriceType	WriteIOs;
	///每秒Read字节数
	TShfeFtdcPriceType	ReadKBs;
	///每秒Write字节数
	TShfeFtdcPriceType	WriteKBs;
	///Size值
	TShfeFtdcPriceType	SizeVal;
	///Queue值
	TShfeFtdcPriceType	QueueVal;
	///Svc_t值
	TShfeFtdcPriceType	Svc_t;
	///繁忙百分率
	TShfeFtdcRatioType	Busy;
};

///系统状态信息
struct CShfeFtdcReqQryStatInfoField
{
	///
	TShfeFtdcTypeObjectIDType	HostName;
	///
	TShfeFtdcDateType	StartDate;
	///
	TShfeFtdcTimeType	StartTime;
	///
	TShfeFtdcDateType	EndDate;
	///
	TShfeFtdcTimeType	EndTime;
	///持续订阅标记
	TShfeFtdcTypeKeepAliveType	KeepAlive;
};

///系统状态信息
struct CShfeFtdcRspQryStatInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///活跃进程数
	TShfeFtdcVolumeType	ProcRun;
	///阻塞进程数
	TShfeFtdcVolumeType	ProcBlk;
	///每秒由磁盘进入Swap的页面数
	TShfeFtdcVolumeType	SwapIn;
	///每秒由Swap进入磁盘的页面数
	TShfeFtdcVolumeType	SwapOut;
	///每秒从块设备读入的Block数
	TShfeFtdcVolumeType	BlockIn;
	///每秒向块设备写入的Block数
	TShfeFtdcVolumeType	BlockOut;
	///每秒设备中段次数
	TShfeFtdcVolumeType	Inter;
	///每秒上下文切换次数
	TShfeFtdcVolumeType	Context;
	///用户态CPU百分率
	TShfeFtdcRatioType	CPUUser;
	///系统态CPU百分率
	TShfeFtdcRatioType	CPUSys;
	///空闲态CPU百分率
	TShfeFtdcRatioType	CPUIdle;
	///IO等待态CPU百分率
	TShfeFtdcRatioType	CPUIOWait;
	///窃取态CPU百分率
	TShfeFtdcRatioType	CPUSteal;
};

///系统状态信息
struct CShfeFtdcRtnStatInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///活跃进程数
	TShfeFtdcVolumeType	ProcRun;
	///阻塞进程数
	TShfeFtdcVolumeType	ProcBlk;
	///每秒由磁盘进入Swap的页面数
	TShfeFtdcVolumeType	SwapIn;
	///每秒由Swap进入磁盘的页面数
	TShfeFtdcVolumeType	SwapOut;
	///每秒从块设备读入的Block数
	TShfeFtdcVolumeType	BlockIn;
	///每秒向块设备写入的Block数
	TShfeFtdcVolumeType	BlockOut;
	///每秒设备中段次数
	TShfeFtdcVolumeType	Inter;
	///每秒上下文切换次数
	TShfeFtdcVolumeType	Context;
	///用户态CPU百分率
	TShfeFtdcRatioType	CPUUser;
	///系统态CPU百分率
	TShfeFtdcRatioType	CPUSys;
	///空闲态CPU百分率
	TShfeFtdcRatioType	CPUIdle;
	///IO等待态CPU百分率
	TShfeFtdcRatioType	CPUIOWait;
	///窃取态CPU百分率
	TShfeFtdcRatioType	CPUSteal;
};

///交易系统前置报单分布区间
struct CShfeFtdcReqQryTradeOrderRttCutLineField
{
	///区间生效日期
	TShfeFtdcDateType	MonDate;
	///区间修改时间
	TShfeFtdcTimeType	MonTime;
	///修改用户对象
	TShfeFtdcTypeObjectIDType	UserName;
	///响应时间分布
	TShfeFtdcNumberListsType	OrderRttCutLine;
	///统计颗粒度
	TShfeFtdcVolumeType	OrderRttWidth;
};

///交易系统前置报单分布区间
struct CShfeFtdcRspQryTradeOrderRttCutLineField
{
	///区间生效日期
	TShfeFtdcDateType	MonDate;
	///区间修改时间
	TShfeFtdcTimeType	MonTime;
	///修改用户对象
	TShfeFtdcTypeObjectIDType	UserName;
	///响应时间分布
	TShfeFtdcNumberListsType	OrderRttCutLine;
	///统计颗粒度
	TShfeFtdcVolumeType	OrderRttWidth;
};

///交易系统前置报单分布区间
struct CShfeFtdcRtnTradeOrderRttCutLineField
{
	///区间生效日期
	TShfeFtdcDateType	MonDate;
	///响应时间分布
	TShfeFtdcNumberListsType	OrderRttCutLine;
};

///会员客户信息
struct CShfeFtdcReqQryClientInfoField
{
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
};

///会员客户信息
struct CShfeFtdcRspQryClientInfoField
{
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///会员客户信息
struct CShfeFtdcRtnClientInfoField
{
	///客户代码
	TShfeFtdcClientIDType	ClientID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///证件类型
	TShfeFtdcIdCardTypeType	IdentifiedCardType;
	///证件号码
	TShfeFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	TShfeFtdcTradingRoleType	TradingRole;
	///客户类型
	TShfeFtdcClientTypeType	ClientType;
	///是否活跃
	TShfeFtdcBoolType	IsActive;
	///操作类型
	TShfeFtdcDBOperationTypeType	OperationType;
};

///事件描述请求
struct CShfeFtdcReqQryEventDescriptionField
{
	///处理ID号
	TShfeFtdcEventDesIDType	EventDesID;
	///事件处理人
	TShfeFtdcTypeObjectIDType	UserName;
	///事件处理日期
	TShfeFtdcDateType	MonDate;
	///事件处理时间
	TShfeFtdcTimeType	MonTime;
	///处理描述
	TShfeFtdcDescriptionType	EventDes;
};

///事件描述返回请求
struct CShfeFtdcRspQryEventDescriptionField
{
	///处理ID号
	TShfeFtdcEventDesIDType	EventDesID;
	///事件处理人
	TShfeFtdcTypeObjectIDType	UserName;
	///事件处理日期
	TShfeFtdcDateType	MonDate;
	///事件处理时间
	TShfeFtdcTimeType	MonTime;
	///处理描述
	TShfeFtdcDescriptionType	EventDes;
};

///事件描述订阅
struct CShfeFtdcRtnEventDescriptionField
{
	///处理ID号
	TShfeFtdcEventDesIDType	EventDesID;
	///事件处理人
	TShfeFtdcTypeObjectIDType	UserName;
	///事件处理日期
	TShfeFtdcDateType	MonDate;
	///事件处理时间
	TShfeFtdcTimeType	MonTime;
	///处理描述
	TShfeFtdcDescriptionType	EventDes;
};

///前置唯一ID请求
struct CShfeFtdcReqQryFrontUniqueIDField
{
	///前置唯一ID编号
	TShfeFtdcFrontIDType	FrontID;
	///前置编号全名
	TShfeFtdcFrontSerialNumType	FrontName;
};

///前置唯一ID返回
struct CShfeFtdcRspQryFrontUniqueIDField
{
	///前置唯一ID编号
	TShfeFtdcFrontIDType	FrontID;
	///前置编号全名
	TShfeFtdcFrontSerialNumType	FrontName;
};

///订阅前置唯一ID信息
struct CShfeFtdcRtnFrontUniqueIDField
{
	///前置唯一ID编号
	TShfeFtdcFrontIDType	FrontID;
	///前置编号全名
	TShfeFtdcFrontSerialNumType	FrontName;
};

///会员线路地址变更请求
struct CShfeFtdcReqQryNetPartyLinkAddrChangeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ID
	TShfeFtdcVolumeType	RelationID;
	///变更前地址
	TShfeFtdcNetAttrTypeType	OLDADDRESS;
	///变更后地址
	TShfeFtdcNetAttrTypeType	NEWADDRESS;
	///操作人
	TShfeFtdcCfgNameType	OPERATOR;
	///修改日期
	TShfeFtdcDateType	MonDate;
	///修改时间
	TShfeFtdcTimeType	MonTime;
};

///会员线路地址变更回应
struct CShfeFtdcRspQryNetPartyLinkAddrChangeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ID
	TShfeFtdcVolumeType	RelationID;
	///变更前地址
	TShfeFtdcNetAttrTypeType	OLDADDRESS;
	///变更后地址
	TShfeFtdcNetAttrTypeType	NEWADDRESS;
	///操作人
	TShfeFtdcCfgNameType	OPERATOR;
	///修改日期
	TShfeFtdcDateType	MonDate;
	///修改时间
	TShfeFtdcTimeType	MonTime;
};

///订阅会员线路地址变更信息
struct CShfeFtdcRtnNetPartyLinkAddrChangeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///ID
	TShfeFtdcVolumeType	RelationID;
	///变更前地址
	TShfeFtdcNetAttrTypeType	OLDADDRESS;
	///变更后地址
	TShfeFtdcNetAttrTypeType	NEWADDRESS;
	///操作人
	TShfeFtdcCfgNameType	OPERATOR;
	///修改日期
	TShfeFtdcDateType	MonDate;
	///修改时间
	TShfeFtdcTimeType	MonTime;
};

///请求已删除会员列表信息
struct CShfeFtdcReqQryNetDelPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///应答已删除会员列表信息
struct CShfeFtdcRspQryNetDelPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///订阅已删除会员列表信息
struct CShfeFtdcRtnNetDelPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///请求网络性能排序
struct CShfeFtdcReqQryPerformanceTopField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///监控指标类型
	TShfeFtdcAttrTypeType	AttrType;
	///网络区域
	TShfeFtdcNetAreaType	NetArea;
	///网络子区域
	TShfeFtdcNetSubAreaType	NetSubArea;
	///查询关键字
	TShfeFtdcKeyWordType	KeyWord;
	///所排序值类型
	TShfeFtdcSortValueType	SortValue;
	///排序类型
	TShfeFtdcSortTypeType	SortType;
	///查询时间类型
	TShfeFtdcDuringTimeTypeType	DuringTimeType;
	///查询时间值
	TShfeFtdcDuringTimeValueType	DuringTimeValue;
	///前N的值
	TShfeFtdcTopNType	TopN;
	///性能排序结果
	TShfeFtdcTopResultType	TopResult;
};

///返回网络性能排序
struct CShfeFtdcRspQryPerformanceTopField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///监控指标类型
	TShfeFtdcAttrTypeType	AttrType;
	///网络区域
	TShfeFtdcNetAreaType	NetArea;
	///网络子区域
	TShfeFtdcNetSubAreaType	NetSubArea;
	///查询关键字
	TShfeFtdcKeyWordType	KeyWord;
	///所排序值类型
	TShfeFtdcSortValueType	SortValue;
	///排序类型
	TShfeFtdcSortTypeType	SortType;
	///查询时间类型
	TShfeFtdcDuringTimeTypeType	DuringTimeType;
	///查询时间值
	TShfeFtdcDuringTimeValueType	DuringTimeValue;
	///前N的值
	TShfeFtdcTopNType	TopN;
	///性能排序结果
	TShfeFtdcTopResultType	TopResult;
};

///订阅网络性能排序
struct CShfeFtdcRtnPerformanceTopField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///监控指标类型
	TShfeFtdcAttrTypeType	AttrType;
	///网络区域
	TShfeFtdcNetAreaType	NetArea;
	///网络子区域
	TShfeFtdcNetSubAreaType	NetSubArea;
	///查询关键字
	TShfeFtdcKeyWordType	KeyWord;
	///所排序值类型
	TShfeFtdcSortValueType	SortValue;
	///排序类型
	TShfeFtdcSortTypeType	SortType;
	///查询时间类型
	TShfeFtdcDuringTimeTypeType	DuringTimeType;
	///查询时间值
	TShfeFtdcDuringTimeValueType	DuringTimeValue;
	///前N的值
	TShfeFtdcTopNType	TopN;
	///性能排序结果
	TShfeFtdcTopResultType	TopResult;
};

///请求合约状态切换
struct CShfeFtdcReqQryInstrumentStatusField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	TShfeFtdcTimeType	EnterTime;
	///进入本状态原因
	TShfeFtdcInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	TShfeFtdcDateType	EnterDate;
};

///返回合约状态切换
struct CShfeFtdcRspQryInstrumentStatusField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	TShfeFtdcTimeType	EnterTime;
	///进入本状态原因
	TShfeFtdcInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	TShfeFtdcDateType	EnterDate;
};

///订阅合约状态切换
struct CShfeFtdcRtnInstrumentStatusField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	TShfeFtdcTimeType	EnterTime;
	///进入本状态原因
	TShfeFtdcInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	TShfeFtdcDateType	EnterDate;
};

///请求合约交易节信息
struct CShfeFtdcReqQryCurrTradingSegmentAttrField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///交易阶段编号
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///交易阶段名称
	TShfeFtdcTradingSegmentNameType	TradingSegmentName;
	///起始时间
	TShfeFtdcTimeType	StartTime;
	///合约交易状态
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///提前天数
	TShfeFtdcAdvanceDaysType	AdvanceDays;
};

///返回合约交易节信息
struct CShfeFtdcRspQryCurrTradingSegmentAttrField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///交易阶段编号
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///交易阶段名称
	TShfeFtdcTradingSegmentNameType	TradingSegmentName;
	///起始时间
	TShfeFtdcTimeType	StartTime;
	///合约交易状态
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///提前天数
	TShfeFtdcAdvanceDaysType	AdvanceDays;
};

///订阅合约交易节信息
struct CShfeFtdcRtnCurrTradingSegmentAttrField
{
	///结算组代码
	TShfeFtdcSettlementGroupIDType	SettlementGroupID;
	///交易阶段编号
	TShfeFtdcTradingSegmentSNType	TradingSegmentSN;
	///交易阶段名称
	TShfeFtdcTradingSegmentNameType	TradingSegmentName;
	///起始时间
	TShfeFtdcTimeType	StartTime;
	///合约交易状态
	TShfeFtdcInstrumentStatusType	InstrumentStatus;
	///合约代码
	TShfeFtdcInstrumentIDType	InstrumentID;
	///提前天数
	TShfeFtdcAdvanceDaysType	AdvanceDays;
};

///实时网络对象请求
struct CShfeFtdcReqQryRealTimeNetObjectAttrField
{
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
};

///网络对象请求
struct CShfeFtdcReqQryNetAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
};

///网络对象应答
struct CShfeFtdcRspQryNetAreaField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///网络对象应答
struct CShfeFtdcRtnNetAreaField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///网络对象请求
struct CShfeFtdcReqQryNetSubAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
};

///网络对象应答
struct CShfeFtdcRspQryNetSubAreaField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///网络对象应答
struct CShfeFtdcRtnNetSubAreaField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///网络对象请求
struct CShfeFtdcReqQryNetSubAreaIPField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
};

///网络对象应答
struct CShfeFtdcRspQryNetSubAreaIPField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip地址
	TShfeFtdcIPAddressType	IP;
	///掩码
	TShfeFtdcIPAddressType	Mask;
};

///网络对象应答
struct CShfeFtdcRtnNetSubAreaIPField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip地址
	TShfeFtdcIPAddressType	IP;
	///掩码
	TShfeFtdcIPAddressType	Mask;
};

///网络设备探测请求
struct CShfeFtdcReqQryNetDeviceDetectField
{
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip地址
	TShfeFtdcIPAddressType	IP;
	///掩码
	TShfeFtdcIPAddressType	Mask;
};

///网络设备查询请求
struct CShfeFtdcReqQryNetDeviceRequestField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///人为划分的职能区域
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP码
	TShfeFtdcVolumeType	IPDECODE;
};

///网络设备
struct CShfeFtdcRspQryNetDeviceField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///分类ID  
	TShfeFtdcVolumeType	CATEGORY_ID;
	///人为划分的职能区域  
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP地址  
	TShfeFtdcIPAddressType	IPADDR;
	///IP码    
	TShfeFtdcVolumeType	IPDECODE;
	///设备名称 
	TShfeFtdcNetObjectIDType	NAME;
	///             
	TShfeFtdcVolumeType	PORTNUMBER;
	///          
	TShfeFtdcTypeObjectIDType	CONFIGFILE;
	///共同体名  
	TShfeFtdcTypeObjectIDType	RCOMMUNITY;
	///snmp版本     
	TShfeFtdcVolumeType	SNMPVERSION;
	///ramsize(B)   
	TShfeFtdcVolumeType	RAMSIZE;
	///falshsize(B) 
	TShfeFtdcVolumeType	FLASHSIZE;
	///nvramsize(B) 
	TShfeFtdcVolumeType	NVRAMSIZE;
	///所属机柜
	TShfeFtdcVolumeType	CABINET_ID;
	///
	TShfeFtdcVolumeType	ROOM_ID;
	///软件版本
	TShfeFtdcVolumeType	IOSVERSION_ID;
	///系统描述
	TShfeFtdcNetAttrTypeType	DESCRIPTION;
	///登录用户名
	TShfeFtdcTypeObjectIDType	USERNAME;
	///登录密码
	TShfeFtdcNetAttrTypeType	PASSWD;
	///enable密码
	TShfeFtdcNetAttrTypeType	ENPASSWD;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///配置备份协议
	TShfeFtdcVolumeType	CFGSAVETYPE;
	///设备型号
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///是否短信告警
	TShfeFtdcVolumeType	SENDSMS;
	///是否自动snmp探测
	TShfeFtdcVolumeType	ISSNMP;
	///槽位数
	TShfeFtdcVolumeType	SLOTNUM;
	///是否自动ping
	TShfeFtdcVolumeType	ISPING;
	///端口数量
	TShfeFtdcVolumeType	IFNUM;
	///巡检分区
	TShfeFtdcVolumeType	APPLICATION_ID;
};

///网络设备
struct CShfeFtdcRtnNetDeviceField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///分类ID  
	TShfeFtdcVolumeType	CATEGORY_ID;
	///人为划分的职能区域  
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP地址  
	TShfeFtdcIPAddressType	IPADDR;
	///IP码    
	TShfeFtdcVolumeType	IPDECODE;
	///设备名称 
	TShfeFtdcNetObjectIDType	NAME;
	///             
	TShfeFtdcVolumeType	PORTNUMBER;
	///          
	TShfeFtdcTypeObjectIDType	CONFIGFILE;
	///共同体名  
	TShfeFtdcTypeObjectIDType	RCOMMUNITY;
	///snmp版本     
	TShfeFtdcVolumeType	SNMPVERSION;
	///ramsize(B)   
	TShfeFtdcVolumeType	RAMSIZE;
	///falshsize(B) 
	TShfeFtdcVolumeType	FLASHSIZE;
	///nvramsize(B) 
	TShfeFtdcVolumeType	NVRAMSIZE;
	///所属机柜
	TShfeFtdcVolumeType	CABINET_ID;
	///
	TShfeFtdcVolumeType	ROOM_ID;
	///软件版本
	TShfeFtdcVolumeType	IOSVERSION_ID;
	///系统描述
	TShfeFtdcNetAttrTypeType	DESCRIPTION;
	///登录用户名
	TShfeFtdcTypeObjectIDType	USERNAME;
	///登录密码
	TShfeFtdcNetAttrTypeType	PASSWD;
	///enable密码
	TShfeFtdcNetAttrTypeType	ENPASSWD;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///配置备份协议
	TShfeFtdcVolumeType	CFGSAVETYPE;
	///设备型号
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///是否短信告警
	TShfeFtdcVolumeType	SENDSMS;
	///是否自动snmp探测
	TShfeFtdcVolumeType	ISSNMP;
	///槽位数
	TShfeFtdcVolumeType	SLOTNUM;
	///是否自动ping
	TShfeFtdcVolumeType	ISPING;
	///端口数量
	TShfeFtdcVolumeType	IFNUM;
	///巡检分区
	TShfeFtdcVolumeType	APPLICATION_ID;
};

///网络设备探测请求应答
struct CShfeFtdcRspQryNetDeviceDetectField
{
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip地址
	TShfeFtdcIPAddressType	IP;
	///掩码
	TShfeFtdcIPAddressType	Mask;
};

///大楼查询
struct CShfeFtdcReqQryNetBuildingField
{
	///ID
	TShfeFtdcVolumeType	ID;
};

///大楼
struct CShfeFtdcRspQryNetBuildingField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///大楼
struct CShfeFtdcRtnNetBuildingField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///机房查询
struct CShfeFtdcReqQryNetRoomField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
};

///机房
struct CShfeFtdcRspQryNetRoomField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///大楼
	TShfeFtdcVolumeType	SysNetBuildingID;
	///机房中文名
	TShfeFtdcTypeObjectIDType	CName;
	///机房英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///机房
struct CShfeFtdcRtnNetRoomField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///大楼
	TShfeFtdcVolumeType	SysNetBuildingID;
	///机房中文名
	TShfeFtdcTypeObjectIDType	CName;
	///机房英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///机柜
struct CShfeFtdcReqQryNetCabinetsField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetRoomID
	TShfeFtdcVolumeType	SysNetRoomID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
};

///机柜
struct CShfeFtdcRspQryNetCabinetsField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetRoomID
	TShfeFtdcVolumeType	SysNetRoomID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
	///机房中文名
	TShfeFtdcTypeObjectIDType	CName;
	///机房英文名
	TShfeFtdcTypeObjectIDType	EName;
	///机柜类型
	TShfeFtdcTypeObjectIDType	CabinetsType;
};

///机柜
struct CShfeFtdcRtnNetCabinetsField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetRoomID
	TShfeFtdcVolumeType	SysNetRoomID;
	///SysNetBuildingID
	TShfeFtdcVolumeType	SysNetBuildingID;
	///机房中文名
	TShfeFtdcTypeObjectIDType	CName;
	///机房英文名
	TShfeFtdcTypeObjectIDType	EName;
	///机柜类型
	TShfeFtdcTypeObjectIDType	CabinetsType;
};

///OID
struct CShfeFtdcReqQryNetOIDField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///单位
	TShfeFtdcTypeObjectIDType	Unit;
	///是否标量标志
	TShfeFtdcVolumeType	isTheTable;
};

///OID
struct CShfeFtdcRspQryNetOIDField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///单位
	TShfeFtdcTypeObjectIDType	Unit;
	///是否标量标志
	TShfeFtdcVolumeType	isTheTable;
};

///OID
struct CShfeFtdcRtnNetOIDField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///单位
	TShfeFtdcTypeObjectIDType	Unit;
	///是否标量标志
	TShfeFtdcVolumeType	isTheTable;
};

///时间策略
struct CShfeFtdcReqQryNetTimePolicyField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///时间策略中文名
	TShfeFtdcTypeObjectIDType	CName;
	///时间策略英文名
	TShfeFtdcTypeObjectIDType	EName;
	///策略类型
	TShfeFtdcVolumeType	PolicyType;
	///策略项配置串
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///交易日限制
	TShfeFtdcVolumeType	TradingDay;
	///策略项描述
	TShfeFtdcNetAttrTypeType	Description;
	///操作类型
	TShfeFtdcVolumeType	Operation;
};

///时间策略
struct CShfeFtdcRspQryNetTimePolicyField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///时间策略中文名
	TShfeFtdcTypeObjectIDType	CName;
	///时间策略英文名
	TShfeFtdcTypeObjectIDType	EName;
	///策略类型
	TShfeFtdcVolumeType	PolicyType;
	///策略项配置串
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///交易日限制
	TShfeFtdcVolumeType	TradingDay;
	///策略项描述
	TShfeFtdcNetAttrTypeType	Description;
	///操作类型
	TShfeFtdcVolumeType	Operation;
};

///时间策略
struct CShfeFtdcRtnNetTimePolicyField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///时间策略中文名
	TShfeFtdcTypeObjectIDType	CName;
	///时间策略英文名
	TShfeFtdcTypeObjectIDType	EName;
	///策略类型
	TShfeFtdcVolumeType	PolicyType;
	///策略项配置串
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///交易日限制
	TShfeFtdcVolumeType	TradingDay;
	///策略项描述
	TShfeFtdcNetAttrTypeType	Description;
	///操作类型
	TShfeFtdcVolumeType	Operation;
};

///采集任务查询
struct CShfeFtdcReqQryNetGatherTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///返回类型
	TShfeFtdcVolumeType	DataType;
	///类型标识
	TShfeFtdcVolumeType	TypeFlag;
};

///采集任务
struct CShfeFtdcRspQryNetGatherTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///返回类型
	TShfeFtdcVolumeType	DataType;
	///类型标识
	TShfeFtdcVolumeType	TypeFlag;
};

///采集任务
struct CShfeFtdcRtnNetGatherTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///返回类型
	TShfeFtdcVolumeType	DataType;
	///类型标识
	TShfeFtdcVolumeType	TypeFlag;
};

///采集任务查询
struct CShfeFtdcReqQryNetDeviceChgField
{
	///设备ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///采集任务
struct CShfeFtdcRspQryNetDeviceChgField
{
	///设备ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///采集任务
struct CShfeFtdcRtnNetDeviceChgField
{
	///设备ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///常用设备型号请求
struct CShfeFtdcReqQryNetDeviceTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///常用设备型号
struct CShfeFtdcRspQryNetDeviceTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///常用设备型号
struct CShfeFtdcRtnNetDeviceTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///常用设备类别请求
struct CShfeFtdcReqQryNetDeviceCategoryField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///类别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///类别英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///常用设备类别
struct CShfeFtdcRspQryNetDeviceCategoryField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///类别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///类别英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///常用设备类别
struct CShfeFtdcRtnNetDeviceCategoryField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///类别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///类别英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///设备厂商请求
struct CShfeFtdcReqQryNetManufactoryField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商中文名
	TShfeFtdcTypeObjectIDType	CName;
	///厂商英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///设备厂商
struct CShfeFtdcRspQryNetManufactoryField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商中文名
	TShfeFtdcTypeObjectIDType	CName;
	///厂商英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///设备厂商
struct CShfeFtdcRtnNetManufactoryField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商中文名
	TShfeFtdcTypeObjectIDType	CName;
	///厂商英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///设备共同体请求
struct CShfeFtdcReqQryNetCommunityField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址
	TShfeFtdcIPAddressType	IPADDR;
	///共同体名
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///设备共同体
struct CShfeFtdcRspQryNetCommunityField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址
	TShfeFtdcIPAddressType	IPADDR;
	///共同体名
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///设备共同体
struct CShfeFtdcRtnNetCommunityField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址
	TShfeFtdcIPAddressType	IPADDR;
	///共同体名
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///端口类型请求
struct CShfeFtdcReqQryNetPortTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文名
	TShfeFtdcTypeObjectIDType	CName;
	///英文名
	TShfeFtdcTypeObjectIDType	EName;
	///描述
	TShfeFtdcTypeObjectIDType	Description;
};

///端口类型
struct CShfeFtdcRspQryNetPortTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文名
	TShfeFtdcTypeObjectIDType	CName;
	///英文名
	TShfeFtdcTypeObjectIDType	EName;
	///描述
	TShfeFtdcTypeObjectIDType	Description;
};

///端口类型
struct CShfeFtdcRtnNetPortTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文名
	TShfeFtdcTypeObjectIDType	CName;
	///英文名
	TShfeFtdcTypeObjectIDType	EName;
	///描述
	TShfeFtdcTypeObjectIDType	Description;
};

///会员接入地点请求
struct CShfeFtdcReqQryNetPartAccessSpotField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文名
	TShfeFtdcTypeObjectIDType	CName;
	///英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///会员接入地点
struct CShfeFtdcRspQryNetPartAccessSpotField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文名
	TShfeFtdcTypeObjectIDType	CName;
	///英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///会员接入地点
struct CShfeFtdcRtnNetPartAccessSpotField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文名
	TShfeFtdcTypeObjectIDType	CName;
	///英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///端口请求
struct CShfeFtdcReqQryNetInterfaceField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///端口类型
	TShfeFtdcVolumeType	IfType;
	///端口名
	TShfeFtdcTypeObjectIDType	EName;
	///IP地址
	TShfeFtdcIPAddressType	IpAddress;
	///掩码
	TShfeFtdcIPAddressType	IpMask;
	///端口状态
	TShfeFtdcVolumeType	IfStatus;
	///物理地址
	TShfeFtdcTypeObjectIDType	MAC;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///是否轮询
	TShfeFtdcVolumeType	isPolling;
	///描述
	TShfeFtdcTypeObjectIDType	Description;
};

///端口
struct CShfeFtdcRspQryNetInterfaceField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///端口类型
	TShfeFtdcVolumeType	IfType;
	///端口名
	TShfeFtdcTypeObjectIDType	EName;
	///IP地址
	TShfeFtdcIPAddressType	IpAddress;
	///掩码
	TShfeFtdcIPAddressType	IpMask;
	///端口状态
	TShfeFtdcVolumeType	IfStatus;
	///物理地址
	TShfeFtdcTypeObjectIDType	MAC;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///是否轮询
	TShfeFtdcVolumeType	isPolling;
	///描述
	TShfeFtdcTypeObjectIDType	Description;
};

///端口
struct CShfeFtdcRtnNetInterfaceField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///端口类型
	TShfeFtdcVolumeType	IfType;
	///端口名
	TShfeFtdcTypeObjectIDType	EName;
	///IP地址
	TShfeFtdcIPAddressType	IpAddress;
	///掩码
	TShfeFtdcIPAddressType	IpMask;
	///端口状态
	TShfeFtdcVolumeType	IfStatus;
	///物理地址
	TShfeFtdcTypeObjectIDType	MAC;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///是否轮询
	TShfeFtdcVolumeType	isPolling;
	///描述
	TShfeFtdcTypeObjectIDType	Description;
};

///GeneralOID
struct CShfeFtdcReqQryNetGeneralOIDField
{
	///ID
	TShfeFtdcVolumeType	ID;
};

///GeneralOID
struct CShfeFtdcRspQryNetGeneralOIDField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///单位
	TShfeFtdcTypeObjectIDType	Unit;
	///是否标量标志
	TShfeFtdcVolumeType	isTheTable;
};

///GeneralOID
struct CShfeFtdcRtnNetGeneralOIDField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///单位
	TShfeFtdcTypeObjectIDType	Unit;
	///是否标量标志
	TShfeFtdcVolumeType	isTheTable;
};

///监控对象类别
struct CShfeFtdcReqQryNetMonitorTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///监控对象类别
struct CShfeFtdcRspQryNetMonitorTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///监控对象类别
struct CShfeFtdcRtnNetMonitorTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///指标统表
struct CShfeFtdcReqQryNetMonitorAttrScopeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///指标中文名
	TShfeFtdcNetAttrTypeType	CName;
	///指标英文名
	TShfeFtdcNetAttrTypeType	EName;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///指标统表
struct CShfeFtdcRspQryNetMonitorAttrScopeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///指标中文名
	TShfeFtdcNetAttrTypeType	CName;
	///指标英文名
	TShfeFtdcNetAttrTypeType	EName;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///指标统表
struct CShfeFtdcRtnNetMonitorAttrScopeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///指标中文名
	TShfeFtdcNetAttrTypeType	CName;
	///指标英文名
	TShfeFtdcNetAttrTypeType	EName;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///监控指标表
struct CShfeFtdcReqQryNetMonitorAttrTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///设备类别
	TShfeFtdcVolumeType	MonitorType_ID;
	///网络监控指标ID
	TShfeFtdcVolumeType	AttrType_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
};

///监控指标表
struct CShfeFtdcRspQryNetMonitorAttrTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///设备类别
	TShfeFtdcVolumeType	MonitorType_ID;
	///网络监控指标ID
	TShfeFtdcVolumeType	AttrType_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
};

///监控指标表
struct CShfeFtdcRtnNetMonitorAttrTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///设备类别
	TShfeFtdcVolumeType	MonitorType_ID;
	///网络监控指标ID
	TShfeFtdcVolumeType	AttrType_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
};

///监控对象指标表
struct CShfeFtdcReqQryNetMonitorObjectAttrField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///监控对象指标表
struct CShfeFtdcRspQryNetMonitorObjectAttrField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///监控对象指标表
struct CShfeFtdcRtnNetMonitorObjectAttrField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///职能区
struct CShfeFtdcReqQryNetFuncAreaField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///职能区
struct CShfeFtdcRspQryNetFuncAreaField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///职能区
struct CShfeFtdcRtnNetFuncAreaField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///监控指令表
struct CShfeFtdcReqQryNetMonitorCommandTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///设备类别ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///设备型号ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///指令码
	TShfeFtdcNetAttrTypeType	Command;
};

///监控指令表
struct CShfeFtdcRspQryNetMonitorCommandTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///设备类别ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///设备型号ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///指令码
	TShfeFtdcNetAttrTypeType	Command;
};

///监控指令表
struct CShfeFtdcRtnNetMonitorCommandTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///设备类别ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///设备型号ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///指令码
	TShfeFtdcNetAttrTypeType	Command;
};

///动作族表
struct CShfeFtdcReqQryNetMonitorActionGroupField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族中文名
	TShfeFtdcTypeObjectIDType	CName;
	///动作族英文名
	TShfeFtdcTypeObjectIDType	EName;
	///动作类型码
	TShfeFtdcVolumeType	ActionType;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///动作族表
struct CShfeFtdcRspQryNetMonitorActionGroupField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族中文名
	TShfeFtdcTypeObjectIDType	CName;
	///动作族英文名
	TShfeFtdcTypeObjectIDType	EName;
	///动作类型码
	TShfeFtdcVolumeType	ActionType;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///动作族表
struct CShfeFtdcRtnNetMonitorActionGroupField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族中文名
	TShfeFtdcTypeObjectIDType	CName;
	///动作族英文名
	TShfeFtdcTypeObjectIDType	EName;
	///动作类型码
	TShfeFtdcVolumeType	ActionType;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///设备对象组表
struct CShfeFtdcReqQryNetMonitorDeviceGroupField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组中文名
	TShfeFtdcTypeObjectIDType	CName;
	///设备对象组英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备过滤条件
	TShfeFtdcNetString512Type	Condition;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///设备对象组表
struct CShfeFtdcRspQryNetMonitorDeviceGroupField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组中文名
	TShfeFtdcTypeObjectIDType	CName;
	///设备对象组英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备过滤条件
	TShfeFtdcNetString512Type	Condition;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///设备对象组表
struct CShfeFtdcRtnNetMonitorDeviceGroupField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组中文名
	TShfeFtdcTypeObjectIDType	CName;
	///设备对象组英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备过滤条件
	TShfeFtdcNetString512Type	Condition;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///任务信息表
struct CShfeFtdcReqQryNetMonitorTaskInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///任务中文名
	TShfeFtdcTypeObjectIDType	CName;
	///任务英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///任务优先级ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///结果输出策略ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///任务动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	TShfeFtdcGeneralResultType	EventExprStr;
	///设备对象组
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///任务时间策略
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///任务优先级
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///结果输出策略
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///任务动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///任务有效性标识
	TShfeFtdcVolumeType	ValidFlag;
	///任务状态标识
	TShfeFtdcVolumeType	TaskStatus;
	///任务描述
	TShfeFtdcNetAttrTypeType	Comments;
};

///任务信息表
struct CShfeFtdcRspQryNetMonitorTaskInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///任务中文名
	TShfeFtdcTypeObjectIDType	CName;
	///任务英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///任务优先级ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///结果输出策略ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///任务动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	TShfeFtdcGeneralResultType	EventExprStr;
	///设备对象组
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///任务时间策略
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///任务优先级
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///结果输出策略
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///任务动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///任务有效性标识
	TShfeFtdcVolumeType	ValidFlag;
	///任务状态标识
	TShfeFtdcVolumeType	TaskStatus;
	///任务描述
	TShfeFtdcNetAttrTypeType	Comments;
};

///任务信息表
struct CShfeFtdcRtnNetMonitorTaskInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///任务中文名
	TShfeFtdcTypeObjectIDType	CName;
	///任务英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///任务优先级ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///结果输出策略ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///任务动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	TShfeFtdcGeneralResultType	EventExprStr;
	///设备对象组
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///任务时间策略
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///任务优先级
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///结果输出策略
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///任务动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///任务有效性标识
	TShfeFtdcVolumeType	ValidFlag;
	///任务状态标识
	TShfeFtdcVolumeType	TaskStatus;
	///任务描述
	TShfeFtdcNetAttrTypeType	Comments;
};

///任务结果表
struct CShfeFtdcReqQryNetMonitorTaskResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///任务ID
	TShfeFtdcVolumeType	Task_ID;
	///执行次数
	TShfeFtdcVolumeType	OperateTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///指令串
	TShfeFtdcNetString256Type	InstructChain;
	///结果串
	TShfeFtdcNetString1KType	ResultChain;
	///任务执行标识
	TShfeFtdcVolumeType	Flag;
};

///任务结果表
struct CShfeFtdcRspQryNetMonitorTaskResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///任务ID
	TShfeFtdcVolumeType	Task_ID;
	///执行次数
	TShfeFtdcVolumeType	OperateTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///指令串
	TShfeFtdcNetString256Type	InstructChain;
	///结果串
	TShfeFtdcNetString1KType	ResultChain;
	///任务执行标识
	TShfeFtdcVolumeType	Flag;
};

///任务结果表
struct CShfeFtdcRtnNetMonitorTaskResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///任务ID
	TShfeFtdcVolumeType	Task_ID;
	///执行次数
	TShfeFtdcVolumeType	OperateTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///指令串
	TShfeFtdcNetString256Type	InstructChain;
	///结果串
	TShfeFtdcNetString1KType	ResultChain;
	///任务执行标识
	TShfeFtdcVolumeType	Flag;
};

///任务对象集
struct CShfeFtdcReqQryNetMonitorTaskObjectSetField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///设备ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///任务对象集
struct CShfeFtdcRspQryNetMonitorTaskObjectSetField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///设备ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///任务对象集
struct CShfeFtdcRtnNetMonitorTaskObjectSetField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///设备ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///会员链路信息表
struct CShfeFtdcReqQryNetPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///会员链路信息表
struct CShfeFtdcRspQryNetPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///会员链路信息表
struct CShfeFtdcRtnNetPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///监控动作指标对照表
struct CShfeFtdcReqQryNetMonitorActionAttrField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///监控对象ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///指标英文名
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///监控动作指标对照表
struct CShfeFtdcRspQryNetMonitorActionAttrField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///监控对象ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///指标英文名
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///监控动作指标对照表
struct CShfeFtdcRtnNetMonitorActionAttrField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///监控对象ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///指标英文名
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///模块
struct CShfeFtdcReqQryNetModuleField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///名字
	TShfeFtdcTypeObjectIDType	Name;
	///描述
	TShfeFtdcNetObjectIDType	Description;
	///模块索引
	TShfeFtdcVolumeType	ModuleIndex;
	///物理索引
	TShfeFtdcVolumeType	EntPhyIndex;
};

///模块
struct CShfeFtdcRspQryNetModuleField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///名字
	TShfeFtdcTypeObjectIDType	Name;
	///描述
	TShfeFtdcNetObjectIDType	Description;
	///模块索引
	TShfeFtdcVolumeType	ModuleIndex;
	///物理索引
	TShfeFtdcVolumeType	EntPhyIndex;
};

///模块
struct CShfeFtdcRtnNetModuleField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///名字
	TShfeFtdcTypeObjectIDType	Name;
	///描述
	TShfeFtdcNetObjectIDType	Description;
	///模块索引
	TShfeFtdcVolumeType	ModuleIndex;
	///物理索引
	TShfeFtdcVolumeType	EntPhyIndex;
};

///告警表达式信息表
struct CShfeFtdcReqQryNetEventExprField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文事件名
	TShfeFtdcNetObjectIDType	CNAME;
	///英文事件名
	TShfeFtdcNetObjectIDType	ENAME;
	///事件级别
	TShfeFtdcCfgNameType	WarningLEVEL;
	///事件类型
	TShfeFtdcVolumeType	EventTypeID;
	///事件子类型
	TShfeFtdcVolumeType	SubEventTypeID;
	///告警间隔时间
	TShfeFtdcVolumeType	GIVEUPTIME;
	///控制定义项
	TShfeFtdcGeneralResultType	CONTROL;
	///表达式定义项
	TShfeFtdcGeneralResultType	EXPR;
	///事件简述
	TShfeFtdcTypeObjectIDType	BRIEF;
	///事件描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///消息组ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///管理员组ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///告警表达式信息表
struct CShfeFtdcRspQryNetEventExprField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文事件名
	TShfeFtdcNetObjectIDType	CNAME;
	///英文事件名
	TShfeFtdcNetObjectIDType	ENAME;
	///事件级别
	TShfeFtdcCfgNameType	WarningLEVEL;
	///事件类型
	TShfeFtdcVolumeType	EventTypeID;
	///事件子类型
	TShfeFtdcVolumeType	SubEventTypeID;
	///告警间隔时间
	TShfeFtdcVolumeType	GIVEUPTIME;
	///控制定义项
	TShfeFtdcGeneralResultType	CONTROL;
	///表达式定义项
	TShfeFtdcGeneralResultType	EXPR;
	///事件简述
	TShfeFtdcTypeObjectIDType	BRIEF;
	///事件描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///消息组ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///管理员组ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///告警表达式信息表
struct CShfeFtdcRtnNetEventExprField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///中文事件名
	TShfeFtdcNetObjectIDType	CNAME;
	///英文事件名
	TShfeFtdcNetObjectIDType	ENAME;
	///事件级别
	TShfeFtdcCfgNameType	WarningLEVEL;
	///事件类型
	TShfeFtdcVolumeType	EventTypeID;
	///事件子类型
	TShfeFtdcVolumeType	SubEventTypeID;
	///告警间隔时间
	TShfeFtdcVolumeType	GIVEUPTIME;
	///控制定义项
	TShfeFtdcGeneralResultType	CONTROL;
	///表达式定义项
	TShfeFtdcGeneralResultType	EXPR;
	///事件简述
	TShfeFtdcTypeObjectIDType	BRIEF;
	///事件描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///消息组ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///管理员组ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///事件类型
struct CShfeFtdcReqQryNetEventTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///事件类型
struct CShfeFtdcRspQryNetEventTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///事件类型
struct CShfeFtdcRtnNetEventTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///事件子类型
struct CShfeFtdcReqQryNetSubEventTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件子类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件子类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///事件子类型
struct CShfeFtdcRspQryNetSubEventTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件子类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件子类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///事件子类型
struct CShfeFtdcRtnNetSubEventTypeField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件子类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件子类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///事件级别
struct CShfeFtdcReqQryNetEventLevelField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件级别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件级别英文名
	TShfeFtdcTypeObjectIDType	EName;
	///事件级别描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///事件级别
struct CShfeFtdcRspQryNetEventLevelField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件级别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件级别英文名
	TShfeFtdcTypeObjectIDType	EName;
	///事件级别描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///事件级别
struct CShfeFtdcRtnNetEventLevelField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///事件级别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件级别英文名
	TShfeFtdcTypeObjectIDType	EName;
	///事件级别描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///任务结果状态表
struct CShfeFtdcReqQryNetMonitorTaskStatusResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///任务ID
	TShfeFtdcVolumeType	Task_ID;
	///执行次数
	TShfeFtdcVolumeType	OperateTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///任务执行标识
	TShfeFtdcVolumeType	Flag;
};

///任务结果状态表
struct CShfeFtdcRspQryNetMonitorTaskStatusResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///任务ID
	TShfeFtdcVolumeType	Task_ID;
	///执行次数
	TShfeFtdcVolumeType	OperateTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///任务执行标识
	TShfeFtdcVolumeType	Flag;
};

///任务结果状态表
struct CShfeFtdcRtnNetMonitorTaskStatusResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///任务ID
	TShfeFtdcVolumeType	Task_ID;
	///执行次数
	TShfeFtdcVolumeType	OperateTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///任务执行标识
	TShfeFtdcVolumeType	Flag;
};

///登陆配置服务的请求
struct CShfeFtdcReqConfigLoginField
{
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
	///ID
	TShfeFtdcVolumeType	ID;
	///HasConfig
	TShfeFtdcVolumeType	HasConfig;
	///Authorization
	TShfeFtdcAuthorizationInfoType	Authorization;
};

///对登陆配置服务请求的响应
struct CShfeFtdcRspQryConfigLoginField
{
	///错误代码
	TShfeFtdcErrorIDType	ErrorID;
	///错误信息
	TShfeFtdcErrorMsgType	ErrorMsg;
};

///对当前登录配置的服务角色的响应
struct CShfeFtdcRspServerTypeField
{
	///IsMaster
	TShfeFtdcVolumeType	IsMaster;
};

///退出服务请求
struct CShfeFtdcReqSysServerExitField
{
	///Time
	TShfeFtdcDateTimeType	Time;
	///Authorization
	TShfeFtdcAuthorizationInfoType	Authorization;
};

///设备配置表
struct CShfeFtdcReqQryNetCfgFileField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///配置文件名
	TShfeFtdcNetAttrTypeType	CfgFileName;
};

///设备配置表
struct CShfeFtdcRspQryNetCfgFileField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///配置文件名
	TShfeFtdcNetAttrTypeType	CfgFileName;
};

///设备配置表
struct CShfeFtdcRtnNetCfgFileField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///配置文件名
	TShfeFtdcNetAttrTypeType	CfgFileName;
};

///任务结果规则分析表
struct CShfeFtdcReqQryNetMonitorDeviceTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令
	TShfeFtdcNetString256Type	InstructChain;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///指令参数串
	TShfeFtdcNetString256Type	InstructArgs;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///任务结果规则分析表
struct CShfeFtdcRspQryNetMonitorDeviceTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令
	TShfeFtdcNetString256Type	InstructChain;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///指令参数串
	TShfeFtdcNetString256Type	InstructArgs;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///任务结果规则分析表
struct CShfeFtdcRtnNetMonitorDeviceTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令
	TShfeFtdcNetString256Type	InstructChain;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///指令参数串
	TShfeFtdcNetString256Type	InstructArgs;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///任务指令指标集表
struct CShfeFtdcReqQryNetMonitorTaskInstAttrsField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///设备型号
	TShfeFtdcNetString128Type	DEVICETYPE;
	///指标串
	TShfeFtdcNetString256Type	AttrsChain;
	///指标规则串
	TShfeFtdcNetString512Type	DefRegularChain;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
};

///任务指令指标集表
struct CShfeFtdcRspQryNetMonitorTaskInstAttrsField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///设备型号
	TShfeFtdcNetString128Type	DEVICETYPE;
	///指标串
	TShfeFtdcNetString256Type	AttrsChain;
	///指标规则串
	TShfeFtdcNetString512Type	DefRegularChain;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
};

///任务指令指标集表
struct CShfeFtdcRtnNetMonitorTaskInstAttrsField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///设备型号
	TShfeFtdcNetString128Type	DEVICETYPE;
	///指标串
	TShfeFtdcNetString256Type	AttrsChain;
	///指标规则串
	TShfeFtdcNetString512Type	DefRegularChain;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
};

///文件通用操作
struct CShfeFtdcReqQryFileGeneralOperField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///文件名
	TShfeFtdcNetAttrTypeType	FileName;
	///文件版本
	TShfeFtdcFileVersionType	Version;
	///小版本号
	TShfeFtdcVolumeType	SubVersion;
	///日期
	TShfeFtdcDateType	MonDate;
	///时间
	TShfeFtdcTimeType	MonTime;
	///文件操作用户
	TShfeFtdcTypeUserNameType	UserName;
	///操作类型
	TShfeFtdcVolumeType	OperType;
	///操作结果
	TShfeFtdcVolumeType	OperResult;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
	///文件偏移
	TShfeFtdcOffsetType	Offset;
	///Content中实际内容长度
	TShfeFtdcCommLengthType	Length;
	///文件内容
	TShfeFtdcFileCommentType	FileContent;
};

///文件通用操作
struct CShfeFtdcRspQryFileGeneralOperField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///文件名
	TShfeFtdcNetAttrTypeType	FileName;
	///文件版本
	TShfeFtdcFileVersionType	Version;
	///小版本号
	TShfeFtdcVolumeType	SubVersion;
	///日期
	TShfeFtdcDateType	MonDate;
	///时间
	TShfeFtdcTimeType	MonTime;
	///文件操作用户
	TShfeFtdcTypeUserNameType	UserName;
	///操作类型
	TShfeFtdcVolumeType	OperType;
	///操作结果
	TShfeFtdcVolumeType	OperResult;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
	///文件偏移
	TShfeFtdcOffsetType	Offset;
	///Content中实际内容长度
	TShfeFtdcCommLengthType	Length;
	///文件内容
	TShfeFtdcFileCommentType	FileContent;
};

///文件通用操作
struct CShfeFtdcRtnFileGeneralOperField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///文件名
	TShfeFtdcNetAttrTypeType	FileName;
	///文件版本
	TShfeFtdcFileVersionType	Version;
	///小版本号
	TShfeFtdcVolumeType	SubVersion;
	///日期
	TShfeFtdcDateType	MonDate;
	///时间
	TShfeFtdcTimeType	MonTime;
	///文件操作用户
	TShfeFtdcTypeUserNameType	UserName;
	///操作类型
	TShfeFtdcVolumeType	OperType;
	///操作结果
	TShfeFtdcVolumeType	OperResult;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
	///文件偏移
	TShfeFtdcOffsetType	Offset;
	///Content中实际内容长度
	TShfeFtdcCommLengthType	Length;
	///文件内容
	TShfeFtdcFileCommentType	FileContent;
};

///基线表
struct CShfeFtdcReqQryNetBaseLineField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///基线名
	TShfeFtdcNetObjectIDType	Name;
	///设备型号
	TShfeFtdcNetObjectIDType	SerialUsed;
	///文件内容
	TShfeFtdcbaseCommentType	data;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///基线表
struct CShfeFtdcRspQryNetBaseLineField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///基线名
	TShfeFtdcNetObjectIDType	Name;
	///设备型号
	TShfeFtdcNetObjectIDType	SerialUsed;
	///文件内容
	TShfeFtdcbaseCommentType	data;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///基线表
struct CShfeFtdcRtnNetBaseLineField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///基线名
	TShfeFtdcNetObjectIDType	Name;
	///设备型号
	TShfeFtdcNetObjectIDType	SerialUsed;
	///文件内容
	TShfeFtdcbaseCommentType	data;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///基线任务表
struct CShfeFtdcReqQryNetBaseLineTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///基线任务名
	TShfeFtdcNetObjectIDType	Name;
	///基线ID列表
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///设备ID列表
	TShfeFtdcGeneralResultType	DeviceIDList;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///基线任务表
struct CShfeFtdcRspQryNetBaseLineTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///基线任务名
	TShfeFtdcNetObjectIDType	Name;
	///基线ID列表
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///设备ID列表
	TShfeFtdcGeneralResultType	DeviceIDList;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///基线任务表
struct CShfeFtdcRtnNetBaseLineTaskField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///基线任务名
	TShfeFtdcNetObjectIDType	Name;
	///基线ID列表
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///设备ID列表
	TShfeFtdcGeneralResultType	DeviceIDList;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///基线结果表
struct CShfeFtdcReqQryNetBaseLineResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///基线名称
	TShfeFtdcNetObjectIDType	BaseLineName;
	///设备ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///设备IP
	TShfeFtdcIPAddressType	DeviceIP;
	///基线结果
	TShfeFtdcFileCommentType	Result;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///基线结果表
struct CShfeFtdcRspQryNetBaseLineResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///基线名称
	TShfeFtdcNetObjectIDType	BaseLineName;
	///设备ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///设备IP
	TShfeFtdcIPAddressType	DeviceIP;
	///基线结果
	TShfeFtdcFileCommentType	Result;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///基线结果表
struct CShfeFtdcRtnNetBaseLineResultField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///基线名称
	TShfeFtdcNetObjectIDType	BaseLineName;
	///设备ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///设备IP
	TShfeFtdcIPAddressType	DeviceIP;
	///基线结果
	TShfeFtdcFileCommentType	Result;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///会员链路状态信息表
struct CShfeFtdcReqQryNetPartyLinkStatusInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///查找方式
	TShfeFtdcCompareTypeType	KeyCompare;
	///索引名称
	TShfeFtdcNetAttrTypeType	KeyName;
	///索引值
	TShfeFtdcNetAttrTypeType	KeyValue;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///席位号
	TShfeFtdcCfgNameType	SEAT_NO;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///链路状态
	TShfeFtdcTypeObjectIDType	status;
};

///会员链路状态信息表
struct CShfeFtdcRspQryNetPartyLinkStatusInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///席位号
	TShfeFtdcCfgNameType	SEAT_NO;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///链路状态
	TShfeFtdcTypeObjectIDType	status;
};

///会员链路状态信息表
struct CShfeFtdcRtnNetPartyLinkStatusInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///席位号
	TShfeFtdcCfgNameType	SEAT_NO;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///链路状态
	TShfeFtdcTypeObjectIDType	status;
};

///会员SDH线路明细表
struct CShfeFtdcReqQryNetMemberSDHLineInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///会员号
	TShfeFtdcPartyIDType	MemberNo;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///客户经理
	TShfeFtdcNetString128Type	ClientManager;
	///带宽
	TShfeFtdcNetString128Type	Bandwidth;
	///接口类
	TShfeFtdcNetString128Type	InterfaceType;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///备注
	TShfeFtdcNetString128Type	Remark;
	///A端接入地址
	TShfeFtdcNetString512Type	EndALineAddress;
	///A端联系人
	TShfeFtdcNetString128Type	EndAContact;
	///Z端接入地址
	TShfeFtdcNetString512Type	EndZLineAddress;
	///联系人
	TShfeFtdcIndividualNameType	ContactName;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///起始设备端口
	TShfeFtdcNetString256Type	StartPortID;
	///起始设备跳接端
	TShfeFtdcNetString128Type	StartJump;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///数据中心代码
	TShfeFtdcDataCenterIDType	DataCenterID;
};

///会员SDH线路明细表
struct CShfeFtdcRspQryNetMemberSDHLineInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///会员号
	TShfeFtdcPartyIDType	MemberNo;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///客户经理
	TShfeFtdcNetString128Type	ClientManager;
	///带宽
	TShfeFtdcNetString128Type	Bandwidth;
	///接口类
	TShfeFtdcNetString128Type	InterfaceType;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///备注
	TShfeFtdcNetString128Type	Remark;
	///A端接入地址
	TShfeFtdcNetString512Type	EndALineAddress;
	///A端联系人
	TShfeFtdcNetString128Type	EndAContact;
	///Z端接入地址
	TShfeFtdcNetString512Type	EndZLineAddress;
	///联系人
	TShfeFtdcIndividualNameType	ContactName;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///起始设备端口
	TShfeFtdcNetString256Type	StartPortID;
	///起始设备跳接端
	TShfeFtdcNetString128Type	StartJump;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///数据中心代码
	TShfeFtdcDataCenterIDType	DataCenterID;
};

///会员SDH线路明细表
struct CShfeFtdcRtnNetMemberSDHLineInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///会员号
	TShfeFtdcPartyIDType	MemberNo;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///客户经理
	TShfeFtdcNetString128Type	ClientManager;
	///带宽
	TShfeFtdcNetString128Type	Bandwidth;
	///接口类
	TShfeFtdcNetString128Type	InterfaceType;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///备注
	TShfeFtdcNetString128Type	Remark;
	///A端接入地址
	TShfeFtdcNetString512Type	EndALineAddress;
	///A端联系人
	TShfeFtdcNetString128Type	EndAContact;
	///Z端接入地址
	TShfeFtdcNetString512Type	EndZLineAddress;
	///联系人
	TShfeFtdcIndividualNameType	ContactName;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///起始设备端口
	TShfeFtdcNetString256Type	StartPortID;
	///起始设备跳接端
	TShfeFtdcNetString128Type	StartJump;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///数据中心代码
	TShfeFtdcDataCenterIDType	DataCenterID;
};

///DDN链路信息表
struct CShfeFtdcReqQryNetDDNLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
};

///DDN链路信息表
struct CShfeFtdcRspQryNetDDNLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
};

///DDN链路信息表
struct CShfeFtdcRtnNetDDNLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
};

///非会员线路使用信息
struct CShfeFtdcReqQryNetPseudMemberLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///线路用途
	TShfeFtdcNetString128Type	LineUsage;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///业务
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
	///乙端电话号码
	TShfeFtdcTelephoneType	Telephone;
	///线路信息
	TShfeFtdcTypeObjectIDType	LineInfo;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
};

///非会员线路使用信息
struct CShfeFtdcRspQryNetPseudMemberLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///线路用途
	TShfeFtdcNetString128Type	LineUsage;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///业务
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
	///乙端电话号码
	TShfeFtdcTelephoneType	Telephone;
	///线路信息
	TShfeFtdcTypeObjectIDType	LineInfo;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
};

///非会员线路使用信息
struct CShfeFtdcRtnNetPseudMemberLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///线路用途
	TShfeFtdcNetString128Type	LineUsage;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///业务
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
	///乙端电话号码
	TShfeFtdcTelephoneType	Telephone;
	///线路信息
	TShfeFtdcTypeObjectIDType	LineInfo;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
};

///远端设备信息
struct CShfeFtdcReqQryOuterDeviceInfField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址  
	TShfeFtdcIPAddressType	IPADDR;
	///设备名称 
	TShfeFtdcNetObjectIDType	NAME;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///远端设备信息
struct CShfeFtdcRspQryOuterDeviceInfField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址  
	TShfeFtdcIPAddressType	IPADDR;
	///设备名称 
	TShfeFtdcNetObjectIDType	NAME;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///远端设备信息
struct CShfeFtdcRtnNetOuterDeviceInfField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址  
	TShfeFtdcIPAddressType	IPADDR;
	///设备名称 
	TShfeFtdcNetObjectIDType	NAME;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///本地ping结果
struct CShfeFtdcReqQryNetLocalPingResultInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
};

///本地ping结果
struct CShfeFtdcRspQryNetLocalPingResultInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
};

///本地ping结果
struct CShfeFtdcRtnNetLocalPingResultInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
};

///远程ping结果
struct CShfeFtdcReqQryNetRomotePingResultInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
	///最小时延
	TShfeFtdcNetString128Type	TimeDlyMin;
	///最大时延
	TShfeFtdcNetString128Type	TimeDlyMax;
	///平均时延
	TShfeFtdcNetString128Type	TimeDlyAvg;
};

///远程ping结果
struct CShfeFtdcRspQryNetRomotePingResultInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
	///最小时延
	TShfeFtdcNetString128Type	TimeDlyMin;
	///最大时延
	TShfeFtdcNetString128Type	TimeDlyMax;
	///平均时延
	TShfeFtdcNetString128Type	TimeDlyAvg;
};

///远程ping结果
struct CShfeFtdcRtnNetRomotePingResultInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
	///最小时延
	TShfeFtdcNetString128Type	TimeDlyMin;
	///最大时延
	TShfeFtdcNetString128Type	TimeDlyMax;
	///平均时延
	TShfeFtdcNetString128Type	TimeDlyAvg;
};

///
struct CShfeFtdcRtnMonitorTopProcessInfoField
{
	///主机名称
	TShfeFtdcTypeObjectIDType	HostName;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///处理器号
	TShfeFtdcTypeCPUIdType	CPU;
	///终端名
	TShfeFtdcTypeChar10Type	TTY;
	///进程号
	TShfeFtdcVolumeType	PID;
	///用户名
	TShfeFtdcTypeChar10Type	USERNAME;
	///任务的优先级
	TShfeFtdcVolumeType	PRI;
	///任务的nice值
	TShfeFtdcVolumeType	NI;
	///任务的代码加上数据再加上栈空间的大小
	TShfeFtdcVolumeType	SSIZE;
	///任务使用的物理内存的总数量
	TShfeFtdcVolumeType	RES;
	///任务的状态
	TShfeFtdcTypeChar10Type	STATE;
	///自任务开始时使用的总CPU时间
	TShfeFtdcTimeType	STIME;
	///进程的CPU利用率权重百分比
	TShfeFtdcRatioType	pWCPU;
	///进程的原始的CPU利用率百分比
	TShfeFtdcRatioType	pCPU;
	///启动进程的命令名
	TShfeFtdcTypeCommandType	COMMAND;
};

///系统内部级联关系
struct CShfeFtdcReqQrySysInternalTopologyField
{
	///携带信息的类型
	TShfeFtdcReportIDType	InfoType;
	///节点1的ID
	TShfeFtdcNodeIDType	Node1_ID;
	///节点1的信息
	TShfeFtdcNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	TShfeFtdcLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	TShfeFtdcLinkStateType	LinkState;
	///节点2的ID
	TShfeFtdcNodeIDType	Node2_ID;
	///节点2的信息
	TShfeFtdcNodeInfoType	Node2_Info;
};

///系统内部级联关系
struct CShfeFtdcRspQrySysInternalTopologyField
{
	///携带信息的类型
	TShfeFtdcReportIDType	InfoType;
	///节点1的ID
	TShfeFtdcNodeIDType	Node1_ID;
	///节点1的信息
	TShfeFtdcNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	TShfeFtdcLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	TShfeFtdcLinkStateType	LinkState;
	///节点2的ID
	TShfeFtdcNodeIDType	Node2_ID;
	///节点2的信息
	TShfeFtdcNodeInfoType	Node2_Info;
};

///系统内部级联关系
struct CShfeFtdcRtnSysInternalTopologyField
{
	///携带信息的类型
	TShfeFtdcReportIDType	InfoType;
	///节点1的ID
	TShfeFtdcNodeIDType	Node1_ID;
	///节点1的信息
	TShfeFtdcNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	TShfeFtdcLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	TShfeFtdcLinkStateType	LinkState;
	///节点2的ID
	TShfeFtdcNodeIDType	Node2_ID;
	///节点2的信息
	TShfeFtdcNodeInfoType	Node2_Info;
};

///请求会员链路费用表
struct CShfeFtdcReqQryMemberLinkCostField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///付款日期
	TShfeFtdcCfgNameType	Pay_Date;
	///账期起始日期
	TShfeFtdcCfgNameType	B_Pay_Date;
	///账期终止日期
	TShfeFtdcCfgNameType	D_Pay_Date;
	///金额
	TShfeFtdcVolumeType	Charge;
	///费用类型
	TShfeFtdcCfgNameType	Fee_Type;
	///备注
	TShfeFtdcPolicyStringTypeType	Pro;
};

///返回会员链路费用表
struct CShfeFtdcRspQryMemberLinkCostField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///付款日期
	TShfeFtdcCfgNameType	Pay_Date;
	///账期起始日期
	TShfeFtdcCfgNameType	B_Pay_Date;
	///账期终止日期
	TShfeFtdcCfgNameType	D_Pay_Date;
	///金额
	TShfeFtdcVolumeType	Charge;
	///费用类型
	TShfeFtdcCfgNameType	Fee_Type;
	///备注
	TShfeFtdcPolicyStringTypeType	Pro;
};

///订阅会员链路费用表
struct CShfeFtdcRtnMemberLinkCostField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///付款日期
	TShfeFtdcCfgNameType	Pay_Date;
	///账期起始日期
	TShfeFtdcCfgNameType	B_Pay_Date;
	///账期终止日期
	TShfeFtdcCfgNameType	D_Pay_Date;
	///金额
	TShfeFtdcVolumeType	Charge;
	///费用类型
	TShfeFtdcCfgNameType	Fee_Type;
	///备注
	TShfeFtdcPolicyStringTypeType	Pro;
};

///请求会员链路月租表
struct CShfeFtdcReqQryNetPartylinkMonthlyRentField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///线路名称
	TShfeFtdcParticipantNameType	LineName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///备注
	TShfeFtdcNetString128Type	Remark;
};

///返回会员链路月租表
struct CShfeFtdcRspQryNetPartylinkMonthlyRentField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///线路名称
	TShfeFtdcParticipantNameType	LineName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///备注
	TShfeFtdcNetString128Type	Remark;
};

///订阅会员链路月租表
struct CShfeFtdcRtnNetPartylinkMonthlyRentField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///线路名称
	TShfeFtdcParticipantNameType	LineName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///备注
	TShfeFtdcNetString128Type	Remark;
};

///请求非会员链路信息
struct CShfeFtdcReqQryNetNonPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///返回非会员链路信息
struct CShfeFtdcRspQryNetNonPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///订阅非会员链路信息
struct CShfeFtdcRtnNetNonPartyLinkInfoField
{
	///操作类型
	TShfeFtdcVolumeType	OperationType;
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///
struct CShfeFtdcSysNetAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetSubAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetArea
	TShfeFtdcVolumeType	SysNetAreaID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetSubAreaIPField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///ip地址
	TShfeFtdcIPAddressType	IP;
	///掩码
	TShfeFtdcIPAddressType	Mask;
};

///
struct CShfeFtdcSysNetDeviceTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
};

///
struct CShfeFtdcSysNetOIDField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///生产商名
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceType;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///单位
	TShfeFtdcTypeObjectIDType	Unit;
	///是否标量标志
	TShfeFtdcVolumeType	isTheTable;
};

///
struct CShfeFtdcSysNetTimePolicyField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///时间策略中文名
	TShfeFtdcTypeObjectIDType	CName;
	///时间策略英文名
	TShfeFtdcTypeObjectIDType	EName;
	///策略类型
	TShfeFtdcVolumeType	PolicyType;
	///策略项配置串
	TShfeFtdcPolicyStringTypeType	PolicyString;
	///交易日限制
	TShfeFtdcVolumeType	TradingDay;
	///策略项描述
	TShfeFtdcNetAttrTypeType	Description;
	///操作类型
	TShfeFtdcVolumeType	Operation;
};

///
struct CShfeFtdcSysNetGatherTaskField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标类型
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
	///返回类型
	TShfeFtdcVolumeType	DataType;
	///类型标识
	TShfeFtdcVolumeType	TypeFlag;
};

///
struct CShfeFtdcSysNetDeviceCategoryField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///类别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///类别英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetManufactoryField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商中文名
	TShfeFtdcTypeObjectIDType	CName;
	///厂商英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetCommunityField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址
	TShfeFtdcIPAddressType	IPADDR;
	///共同体名
	TShfeFtdcTypeObjectIDType	COMMUNITY;
};

///
struct CShfeFtdcSysNetGeneralOIDField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
	///OID
	TShfeFtdcTypeObjectIDType	OID;
	///单位
	TShfeFtdcTypeObjectIDType	Unit;
	///是否标量标志
	TShfeFtdcVolumeType	isTheTable;
};

///
struct CShfeFtdcSysNetDeviceLinkedField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///设备ID
	TShfeFtdcVolumeType	NetDeviceID;
	///设备端口ID
	TShfeFtdcVolumeType	NetPortID;
	///监控对象
	TShfeFtdcNetObjectIDType	NetObjectID;
	///监控对象端口类型
	TShfeFtdcNetDevicePortTypeType	NetPortType;
	///连接设备ID
	TShfeFtdcVolumeType	LinkNetDeviceID;
	///连接设备端口ID
	TShfeFtdcVolumeType	LinkNetPortID;
	///连接对象
	TShfeFtdcNetObjectIDType	LinkNetObjectID;
	///连接对象端口类型
	TShfeFtdcNetDevicePortTypeType	LinkNetPortType;
	///链接来源
	TShfeFtdcVolumeType	LinkSource;
};

///
struct CShfeFtdcSysNetDeviceField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///分类ID  
	TShfeFtdcVolumeType	CATEGORY_ID;
	///人为划分的职能区域  
	TShfeFtdcTypeObjectIDType	FuctionArea;
	///IP地址  
	TShfeFtdcIPAddressType	IPADDR;
	///IP码    
	TShfeFtdcVolumeType	IPDECODE;
	///设备名称 
	TShfeFtdcNetObjectIDType	NAME;
	///             
	TShfeFtdcVolumeType	PORTNUMBER;
	///          
	TShfeFtdcTypeObjectIDType	CONFIGFILE;
	///共同体名  
	TShfeFtdcTypeObjectIDType	RCOMMUNITY;
	///snmp版本     
	TShfeFtdcVolumeType	SNMPVERSION;
	///ramsize(B)   
	TShfeFtdcVolumeType	RAMSIZE;
	///falshsize(B) 
	TShfeFtdcVolumeType	FLASHSIZE;
	///nvramsize(B) 
	TShfeFtdcVolumeType	NVRAMSIZE;
	///所属机柜
	TShfeFtdcVolumeType	CABINET_ID;
	///
	TShfeFtdcVolumeType	ROOM_ID;
	///软件版本
	TShfeFtdcVolumeType	IOSVERSION_ID;
	///系统描述
	TShfeFtdcNetAttrTypeType	DESCRIPTION;
	///登录用户名
	TShfeFtdcTypeObjectIDType	USERNAME;
	///登录密码
	TShfeFtdcNetAttrTypeType	PASSWD;
	///enable密码
	TShfeFtdcNetAttrTypeType	ENPASSWD;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///配置备份协议
	TShfeFtdcVolumeType	CFGSAVETYPE;
	///设备型号
	TShfeFtdcNetObjectIDType	DEVICETYPE;
	///是否短信告警
	TShfeFtdcVolumeType	SENDSMS;
	///是否自动snmp探测
	TShfeFtdcVolumeType	ISSNMP;
	///槽位数
	TShfeFtdcVolumeType	SLOTNUM;
	///是否自动ping
	TShfeFtdcVolumeType	ISPING;
	///端口数量
	TShfeFtdcVolumeType	IFNUM;
	///巡检分区
	TShfeFtdcVolumeType	APPLICATION_ID;
};

///
struct CShfeFtdcSysNetInterfaceField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///端口类型
	TShfeFtdcVolumeType	IfType;
	///端口名
	TShfeFtdcTypeObjectIDType	EName;
	///IP地址
	TShfeFtdcIPAddressType	IpAddress;
	///掩码
	TShfeFtdcIPAddressType	IpMask;
	///端口状态
	TShfeFtdcVolumeType	IfStatus;
	///物理地址
	TShfeFtdcTypeObjectIDType	MAC;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	TShfeFtdcTypeObjectNameType	DeviceIndex;
	///是否轮询
	TShfeFtdcVolumeType	isPolling;
	///描述
	TShfeFtdcTypeObjectIDType	Description;
};

///
struct CShfeFtdcSysNetMonitorTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///OID中文名
	TShfeFtdcTypeObjectIDType	CName;
	///OID英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetMonitorAttrScopeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///指标中文名
	TShfeFtdcNetAttrTypeType	CName;
	///指标英文名
	TShfeFtdcNetAttrTypeType	EName;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetMonitorAttrTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///设备类别
	TShfeFtdcVolumeType	MonitorType_ID;
	///网络监控指标ID
	TShfeFtdcVolumeType	AttrType_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	MANUFACTORY;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
};

///
struct CShfeFtdcSysNetMonitorObjectAttrField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///监控对象
	TShfeFtdcNetObjectIDType	ObjectID;
	///网络监控指标
	TShfeFtdcNetAttrTypeType	AttrType;
	///时间策略ID
	TShfeFtdcVolumeType	PolicyTypeID;
};

///
struct CShfeFtdcSysNetFuncAreaField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///区域中文名
	TShfeFtdcTypeObjectIDType	CName;
	///区域英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetMonitorCommandTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///设备类别ID
	TShfeFtdcVolumeType	MonitorType_ID;
	///设备型号ID
	TShfeFtdcVolumeType	DeviceModle_ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///厂商类型
	TShfeFtdcTypeObjectIDType	Manufactory;
	///设备类别
	TShfeFtdcTypeObjectIDType	MonitorType;
	///设备型号
	TShfeFtdcTypeObjectIDType	DeviceModle;
	///动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///指令码
	TShfeFtdcNetAttrTypeType	Command;
};

///
struct CShfeFtdcSysNetMonitorActionGroupField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族中文名
	TShfeFtdcTypeObjectIDType	CName;
	///动作族英文名
	TShfeFtdcTypeObjectIDType	EName;
	///动作类型码
	TShfeFtdcVolumeType	ActionType;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetMonitorDeviceGroupField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组中文名
	TShfeFtdcTypeObjectIDType	CName;
	///设备对象组英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备过滤条件
	TShfeFtdcNetString512Type	Condition;
	///注释
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetMonitorTaskInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///任务中文名
	TShfeFtdcTypeObjectIDType	CName;
	///任务英文名
	TShfeFtdcTypeObjectIDType	EName;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	TShfeFtdcVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	TShfeFtdcVolumeType	TimePolicy_ID;
	///任务优先级ID
	TShfeFtdcVolumeType	TaskPriority_ID;
	///结果输出策略ID
	TShfeFtdcVolumeType	OutputPolicy_ID;
	///任务动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	TShfeFtdcGeneralResultType	EventExprStr;
	///设备对象组
	TShfeFtdcTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	TShfeFtdcTypeObjectIDType	ManagerGroup;
	///任务时间策略
	TShfeFtdcTypeObjectIDType	TimePolicy;
	///任务优先级
	TShfeFtdcTypeObjectIDType	TaskPriority;
	///结果输出策略
	TShfeFtdcTypeObjectIDType	OutputPolicy;
	///任务动作族
	TShfeFtdcTypeObjectIDType	ActionGroup;
	///任务有效性标识
	TShfeFtdcVolumeType	ValidFlag;
	///任务状态标识
	TShfeFtdcVolumeType	TaskStatus;
	///任务描述
	TShfeFtdcNetAttrTypeType	Comments;
};

///
struct CShfeFtdcSysNetDeviceChgField
{
	///设备ID
	TShfeFtdcVolumeType	DeviceID;
	///SysNetSubAreaID
	TShfeFtdcVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	OldObjectID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	NewObjectID;
};

///
struct CShfeFtdcSysNetMonitorTaskResultField
{
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///任务ID
	TShfeFtdcVolumeType	Task_ID;
	///执行次数
	TShfeFtdcVolumeType	OperateTime;
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///指令串
	TShfeFtdcNetString256Type	InstructChain;
	///结果串
	TShfeFtdcNetString1KType	ResultChain;
	///任务执行标识
	TShfeFtdcVolumeType	Flag;
};

///
struct CShfeFtdcSysNetMonitorTaskObjectSetField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///设备对象组ID
	TShfeFtdcVolumeType	DeviceGroup_ID;
	///设备ID
	TShfeFtdcVolumeType	Device_ID;
	///DataCenter
	TShfeFtdcDataCenterFlagType	DataCenter;
};

///
struct CShfeFtdcSysNetPartyLinkInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///
struct CShfeFtdcSysNetMonitorActionAttrField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///动作族ID
	TShfeFtdcVolumeType	ActionGroup_ID;
	///监控对象ID
	TShfeFtdcVolumeType	MonitorAttr_ID;
	///指标英文名
	TShfeFtdcNetAttrTypeType	MonitorAttrName;
};

///
struct CShfeFtdcSysNetModuleField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///监控对象类型
	TShfeFtdcVolumeType	MonitorType_ID;
	///所属设备ID
	TShfeFtdcVolumeType	DeviceID;
	///所属设备ObjectID
	TShfeFtdcNetObjectIDType	DeviceObjectID;
	///名字
	TShfeFtdcTypeObjectIDType	Name;
	///描述
	TShfeFtdcNetObjectIDType	Description;
	///模块索引
	TShfeFtdcVolumeType	ModuleIndex;
	///物理索引
	TShfeFtdcVolumeType	EntPhyIndex;
};

///
struct CShfeFtdcSysNetEventExprField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///中文事件名
	TShfeFtdcNetObjectIDType	CNAME;
	///英文事件名
	TShfeFtdcNetObjectIDType	ENAME;
	///事件级别
	TShfeFtdcCfgNameType	WarningLEVEL;
	///事件类型
	TShfeFtdcVolumeType	EventTypeID;
	///事件子类型
	TShfeFtdcVolumeType	SubEventTypeID;
	///告警间隔时间
	TShfeFtdcVolumeType	GIVEUPTIME;
	///控制定义项
	TShfeFtdcGeneralResultType	CONTROL;
	///表达式定义项
	TShfeFtdcGeneralResultType	EXPR;
	///事件简述
	TShfeFtdcTypeObjectIDType	BRIEF;
	///事件描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
	///消息组ID
	TShfeFtdcVolumeType	MSGGROUP_ID;
	///管理员组ID
	TShfeFtdcVolumeType	ADMINGROUP_ID;
};

///
struct CShfeFtdcSysNetEventTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///事件类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetSubEventTypeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///事件子类型中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件子类型英文名
	TShfeFtdcTypeObjectIDType	EName;
};

///
struct CShfeFtdcSysNetEventLevelField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///事件级别中文名
	TShfeFtdcTypeObjectIDType	CName;
	///事件级别英文名
	TShfeFtdcTypeObjectIDType	EName;
	///事件级别描述项
	TShfeFtdcNetAttrTypeType	DISCRIPTION;
};

///
struct CShfeFtdcSysNetMonitorDeviceTaskField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令
	TShfeFtdcNetString256Type	InstructChain;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///指令参数串
	TShfeFtdcNetString256Type	InstructArgs;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///
struct CShfeFtdcSysNetMonitorTaskInstAttrsField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///设备型号
	TShfeFtdcNetString128Type	DEVICETYPE;
	///指标串
	TShfeFtdcNetString256Type	AttrsChain;
	///指标规则串
	TShfeFtdcNetString512Type	DefRegularChain;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
};

///
struct CShfeFtdcSysNetBaseLineField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///厂商类型
	TShfeFtdcVolumeType	MANUFACTORY_ID;
	///基线名
	TShfeFtdcNetObjectIDType	Name;
	///设备型号
	TShfeFtdcNetObjectIDType	SerialUsed;
	///文件内容
	TShfeFtdcbaseCommentType	data;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///
struct CShfeFtdcSysNetBaseLineTaskField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///基线任务名
	TShfeFtdcNetObjectIDType	Name;
	///基线ID列表
	TShfeFtdcGeneralResultType	BaseLineIDList;
	///设备ID列表
	TShfeFtdcGeneralResultType	DeviceIDList;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///
struct CShfeFtdcSysNetBaseLineResultField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///基线名称
	TShfeFtdcNetObjectIDType	BaseLineName;
	///设备ObjID
	TShfeFtdcNetObjectIDType	DeviceObjID;
	///设备IP
	TShfeFtdcIPAddressType	DeviceIP;
	///基线结果
	TShfeFtdcFileCommentType	Result;
	///生成日期
	TShfeFtdcDateType	GenDate;
	///生成时间
	TShfeFtdcTimeType	GenTime;
	///生成者
	TShfeFtdcTypeUserNameType	GenUser;
	///结束标志
	TShfeFtdcVolumeType	Flag;
};

///
struct CShfeFtdcSysNetPartyLinkStatusInfoField
{
	///采集的日期
	TShfeFtdcDateType	MonDate;
	///采集的时间
	TShfeFtdcTimeType	MonTime;
	///席位号
	TShfeFtdcCfgNameType	SEAT_NO;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///链路状态
	TShfeFtdcTypeObjectIDType	status;
};

///
struct CShfeFtdcSysNetMemberSDHLineInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///会员号
	TShfeFtdcPartyIDType	MemberNo;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///客户经理
	TShfeFtdcNetString128Type	ClientManager;
	///带宽
	TShfeFtdcNetString128Type	Bandwidth;
	///接口类
	TShfeFtdcNetString128Type	InterfaceType;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///备注
	TShfeFtdcNetString128Type	Remark;
	///A端接入地址
	TShfeFtdcNetString512Type	EndALineAddress;
	///A端联系人
	TShfeFtdcNetString128Type	EndAContact;
	///Z端接入地址
	TShfeFtdcNetString512Type	EndZLineAddress;
	///联系人
	TShfeFtdcIndividualNameType	ContactName;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///起始设备端口
	TShfeFtdcNetString256Type	StartPortID;
	///起始设备跳接端
	TShfeFtdcNetString128Type	StartJump;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///数据中心代码
	TShfeFtdcDataCenterIDType	DataCenterID;
};

///
struct CShfeFtdcSysNetDDNLinkInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///客户名称
	TShfeFtdcPartyNameType	ClientName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///业务单元
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
};

///
struct CShfeFtdcSysNetPseudMemberLinkInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///序列号
	TShfeFtdcVolumeType	SeqNo;
	///合同号
	TShfeFtdcContractSeqNoType	MemContractNo;
	///线路用途
	TShfeFtdcNetString128Type	LineUsage;
	///本地电路编码
	TShfeFtdcNetString128Type	LocalCircuit;
	///长途电路编码
	TShfeFtdcNetString128Type	RemoteCircuit;
	///业务
	TShfeFtdcBusinessUnitType	BusinessUnit;
	///速率
	TShfeFtdcNetString128Type	Bandwidth;
	///申请人
	TShfeFtdcApplyPersonType	ApplyPerson;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///甲端地址
	TShfeFtdcAddressType	EndAAddress;
	///甲端联系人
	TShfeFtdcIndividualNameType	EndAContactName;
	///乙端地址
	TShfeFtdcAddressType	EndZAddress;
	///乙端联系人
	TShfeFtdcIndividualNameType	EndZContactName;
	///乙端电话号码
	TShfeFtdcTelephoneType	Telephone;
	///线路信息
	TShfeFtdcTypeObjectIDType	LineInfo;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
};

///
struct CShfeFtdcSysNetMonitorDeviceTask2Field
{
	///ID
	TShfeFtdcVolumeType	ID;
	///网络监控对象ID
	TShfeFtdcNetObjectIDType	ObjectID;
	///IP地址
	TShfeFtdcIPAddressType	IPAddress;
	///网络设备产商ID
	TShfeFtdcVolumeType	Manufactory_ID;
	///指令
	TShfeFtdcNetString256Type	InstructChain;
	///指令别名
	TShfeFtdcNetString128Type	InstructAlias;
	///指令参数串
	TShfeFtdcNetString256Type	InstructArgs;
	///指标阀值串
	TShfeFtdcNetString2KType	DefParamChain;
	///结束标志
	TShfeFtdcVolumeType	Flag;
	///PrimID
	TShfeFtdcVolumeType	SecondID;
};

///
struct CShfeFtdcSysNetOuterDeviceInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///IP地址  
	TShfeFtdcIPAddressType	IPADDR;
	///设备名称 
	TShfeFtdcNetObjectIDType	NAME;
	///备注
	TShfeFtdcNetAttrTypeType	memo;
};

///
struct CShfeFtdcSysLocalPingResultInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
};

///
struct CShfeFtdcSysRomotePingResultInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///源IP地址  
	TShfeFtdcIPAddressType	SouIPADDR;
	///源设备名称 
	TShfeFtdcNetObjectIDType	SouNAME;
	///目的IP地址  
	TShfeFtdcIPAddressType	TarIPADDR;
	///目的设备名称 
	TShfeFtdcNetObjectIDType	TarNAME;
	///生成日期
	TShfeFtdcDateType	PDateSta;
	///时间戳
	TShfeFtdcTimeType	PTimeSta;
	///连通率
	TShfeFtdcVolumeType	ConnRate;
	///最小时延
	TShfeFtdcNetString128Type	TimeDlyMin;
	///最大时延
	TShfeFtdcNetString128Type	TimeDlyMax;
	///平均时延
	TShfeFtdcNetString128Type	TimeDlyAvg;
};

///
struct CShfeFtdcSysNetDelPartyLinkInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};

///
struct CShfeFtdcSysNetPartyLinkAddrChangeField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///ID
	TShfeFtdcVolumeType	RelationID;
	///变更前地址
	TShfeFtdcNetAttrTypeType	OLDADDRESS;
	///变更后地址
	TShfeFtdcNetAttrTypeType	NEWADDRESS;
	///操作人
	TShfeFtdcCfgNameType	OPERATOR;
	///修改日期
	TShfeFtdcDateType	MonDate;
	///修改时间
	TShfeFtdcTimeType	MonTime;
};

///
struct CShfeFtdcSysInternalTopologyField
{
	///携带信息的类型
	TShfeFtdcReportIDType	InfoType;
	///节点1的ID
	TShfeFtdcNodeIDType	Node1_ID;
	///节点1的信息
	TShfeFtdcNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	TShfeFtdcLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	TShfeFtdcLinkStateType	LinkState;
	///节点2的ID
	TShfeFtdcNodeIDType	Node2_ID;
	///节点2的信息
	TShfeFtdcNodeInfoType	Node2_Info;
};

///
struct CShfeFtdcSysMemberLinkCostField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///会员名称
	TShfeFtdcParticipantNameType	ParticipantName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///付款日期
	TShfeFtdcCfgNameType	Pay_Date;
	///账期起始日期
	TShfeFtdcCfgNameType	B_Pay_Date;
	///账期终止日期
	TShfeFtdcCfgNameType	D_Pay_Date;
	///金额
	TShfeFtdcVolumeType	Charge;
	///费用类型
	TShfeFtdcCfgNameType	Fee_Type;
	///备注
	TShfeFtdcPolicyStringTypeType	Pro;
};

///
struct CShfeFtdcSysNetPartylinkMonthlyRentField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///线路名称
	TShfeFtdcParticipantNameType	LineName;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///运营商
	TShfeFtdcCfgNameType	ServiceProvider;
	///月租费用
	TShfeFtdcLongVolumeType	MonthlyRental;
	///备注
	TShfeFtdcNetString128Type	Remark;
};

///
struct CShfeFtdcSysNetNonPartyLinkInfoField
{
	///ID
	TShfeFtdcVolumeType	ID;
	///会员号
	TShfeFtdcCfgNameType	MEMBER_NO;
	///会员名称
	TShfeFtdcTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	TShfeFtdcTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	TShfeFtdcTypeObjectIDType	LOCAL_ADDR;
	///地址
	TShfeFtdcNetAttrTypeType	ADDRESS;
	///线路状态
	TShfeFtdcCfgNameType	LINE_STATUS;
	///联系人
	TShfeFtdcCfgNameType	CONTACT;
	///联系电话
	TShfeFtdcTypeObjectIDType	TELEPHONE;
	///手机号
	TShfeFtdcTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	TShfeFtdcTypeObjectIDType	EMAIL;
	///传真
	TShfeFtdcTypeObjectIDType	FAX;
	///所属省份
	TShfeFtdcCfgNameType	PROVINCE;
	///线路编号
	TShfeFtdcTypeObjectIDType	DDN_NO;
	///接入方式
	TShfeFtdcTypeObjectIDType	IN_MODE;
	///入网IP广域
	TShfeFtdcTypeObjectIDType	IP_WAN;
	///入网IP局域
	TShfeFtdcTypeObjectIDType	IP_LAN;
	///路由器网管IP
	TShfeFtdcTypeObjectIDType	IPADDR;
	///路由器端口号
	TShfeFtdcTypeObjectIDType	Interface;
	///接口开通日期
	TShfeFtdcCfgNameType	INTERFACE_DATE;
	///所用软件
	TShfeFtdcCfgNameType	SOFTWARE;
	///付费类型
	TShfeFtdcCfgNameType	FEE_TYPE;
	///运营商
	TShfeFtdcCfgNameType	SERVICEPROVIDER;
	///是否自营
	TShfeFtdcCfgNameType	IF_ZIYING;
	///是否托管
	TShfeFtdcCfgNameType	IF_TUOGUAN;
	///有无他所线路
	TShfeFtdcCfgNameType	HASOTHER;
	///席位号
	TShfeFtdcGeneralResultType	SEAT_NO;
	///备注
	TShfeFtdcPolicyStringTypeType	PRO;
};



#endif
