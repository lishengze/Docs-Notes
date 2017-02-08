// FtdData.h: 
//
//////////////////////////////////////////////////////////////////////

#if !defined(_FTDDATA_H)
#define _FTDDATA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FieldDescribe.h"
#include "customDataType.h"

///信息分发
class CFTDDisseminationField
{
public:
	///序列系列号
	CSequenceSeriesType	SequenceSeries;
	///序列号
	CSequenceNoType	SequenceNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SequenceSeries)
		,
		TYPE_DESC(SequenceNo)
	));
};
const DWORD FTD_FID_Dissemination=0x0001;

///响应信息
class CFTDRspInfoField
{
public:
	///错误代码
	CErrorIDType	ErrorID;
	///错误信息
	CErrorMsgType	ErrorMsg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
	));
};
const DWORD FTD_FID_RspInfo=0x0003;

///通讯阶段
class CFTDCommPhaseField
{
public:
	///交易日
	CDateType	TradingDay;
	///通讯时段号
	CCommPhaseNoType	CommPhaseNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(CommPhaseNo)
	));
};
const DWORD FTD_FID_CommPhase=0x0004;

///交易所交易日
class CFTDExchangeTradingDayField
{
public:
	///交易日
	CDateType	TradingDay;
	///交易所代码
	CExchangeIDType	ExchangeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(ExchangeID)
	));
};
const DWORD FTD_FID_ExchangeTradingDay=0x0005;

///结算会话
class CFTDSettlementSessionField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
	));
};
const DWORD FTD_FID_SettlementSession=0x0006;

///当前时间
class CFTDCurrentTimeField
{
public:
	///当前日期
	CDateType	CurrDate;
	///当前时间
	CTimeType	CurrTime;
	///当前时间（毫秒）
	CMillisecType	CurrMillisec;
	TYPE_DESCRIPTOR((
		TYPE_DESC(CurrDate)
		,
		TYPE_DESC(CurrTime)
		,
		TYPE_DESC(CurrMillisec)
	));
};
const DWORD FTD_FID_CurrentTime=0x0007;

///用户登录请求
class CFTDReqUserLoginField
{
public:
	///交易日
	CDateType	TradingDay;
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///密码
	CPasswordType	Password;
	///用户端产品信息
	CProductInfoType	UserProductInfo;
	///接口端产品信息
	CProductInfoType	InterfaceProductInfo;
	///协议信息
	CProtocolInfoType	ProtocolInfo;
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(DataCenterID)
	));
};
const DWORD FTD_FID_ReqUserLogin=0x000A;

///用户登录应答
class CFTDRspUserLoginField
{
public:
	///交易日
	CDateType	TradingDay;
	///登录成功时间
	CTimeType	LoginTime;
	///最大本地报单号
	COrderLocalIDType	MaxOrderLocalID;
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易系统名称
	CTradingSystemNameType	TradingSystemName;
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	///会员私有流当前长度
	CSequenceNoType	PrivateFlowSize;
	///交易员私有流当前长度
	CSequenceNoType	UserFlowSize;
	///业务发生日期
	CDateType	ActionDay;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(MaxOrderLocalID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingSystemName)
		,
		TYPE_DESC(DataCenterID)
		,
		TYPE_DESC(PrivateFlowSize)
		,
		TYPE_DESC(UserFlowSize)
		,
		TYPE_DESC(ActionDay)
	));
};
const DWORD FTD_FID_RspUserLogin=0x000B;

///用户登出请求
class CFTDReqUserLogoutField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
	));
};
const DWORD FTD_FID_ReqUserLogout=0x000C;

///用户登出应答
class CFTDRspUserLogoutField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
	));
};
const DWORD FTD_FID_RspUserLogout=0x000D;

///输入报单
class CFTDInputOrderField
{
public:
	///报单编号
	COrderSysIDType	OrderSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///报单价格条件
	COrderPriceTypeType	OrderPriceType;
	///买卖方向
	CDirectionType	Direction;
	///组合开平标志
	CCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType	CombHedgeFlag;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType	TimeCondition;
	///GTD日期
	CDateType	GTDDate;
	///成交量类型
	CVolumeConditionType	VolumeCondition;
	///最小成交量
	CVolumeType	MinVolume;
	///触发条件
	CContingentConditionType	ContingentCondition;
	///止损价
	CPriceType	StopPrice;
	///强平原因
	CForceCloseReasonType	ForceCloseReason;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///自动挂起标志
	CBoolType	IsAutoSuspend;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OrderPriceType)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(CombOffsetFlag)
		,
		TYPE_DESC(CombHedgeFlag)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(GTDDate)
		,
		TYPE_DESC(VolumeCondition)
		,
		TYPE_DESC(MinVolume)
		,
		TYPE_DESC(ContingentCondition)
		,
		TYPE_DESC(StopPrice)
		,
		TYPE_DESC(ForceCloseReason)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(IsAutoSuspend)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_InputOrder=0x0011;

///报单操作
class CFTDOrderActionField
{
public:
	///报单编号
	COrderSysIDType	OrderSysID;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///报单操作标志
	CActionFlagType	ActionFlag;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///价格
	CPriceType	LimitPrice;
	///数量变化
	CVolumeType	VolumeChange;
	///操作本地编号
	COrderLocalIDType	ActionLocalID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(ActionFlag)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeChange)
		,
		TYPE_DESC(ActionLocalID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_OrderAction=0x0012;

///OTC报单
class CFTDOTCOrderField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///OTC报单编号
	COTCOrderSysIDType	OTCOrderSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///买卖方向
	CDirectionType	Direction;
	///开平标志
	COffsetFlagType	OffsetFlag;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///价格
	CPriceType	Price;
	///数量
	CVolumeType	Volume;
	///对手方会员代码
	CParticipantIDType	OtherParticipantID;
	///对手方客户代码
	CClientIDType	OtherClientID;
	///对手方交易用户代码
	CUserIDType	OtherUserID;
	///对手方开平标志
	COffsetFlagType	OtherOffsetFlag;
	///对手方套保标志
	CHedgeFlagType	OtherHedgeFlag;
	///本地OTC报单编号
	COrderLocalIDType	OTCOrderLocalID;
	///OTC报单状态
	COTCOrderStatusType	OTCOrderStatus;
	///插入时间
	CTimeType	InsertTime;
	///撤销时间
	CTimeType	CancelTime;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///对手方结算会员编号
	CParticipantIDType	OtherClearingPartID;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	CDateType	ActionDay;
	///efp对应期货或期权合约代码
	CInstrumentIDType	EfpInstrumentID;
	///期权行权后是否保留期货头寸的标记
	CExecOrderPositionFlagType	ReservePositionFlag;
	///交割模式
	CDeliveryModeType	DeliveryMode;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(OTCOrderSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(OtherParticipantID)
		,
		TYPE_DESC(OtherClientID)
		,
		TYPE_DESC(OtherUserID)
		,
		TYPE_DESC(OtherOffsetFlag)
		,
		TYPE_DESC(OtherHedgeFlag)
		,
		TYPE_DESC(OTCOrderLocalID)
		,
		TYPE_DESC(OTCOrderStatus)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(CancelTime)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(OtherClearingPartID)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(ActionDay)
		,
		TYPE_DESC(EfpInstrumentID)
		,
		TYPE_DESC(ReservePositionFlag)
		,
		TYPE_DESC(DeliveryMode)
	));
};
const DWORD FTD_FID_OTCOrder=0x0013;

///报单会话
class CFTDOrderSessionField
{
public:
	///前置编号
	CFrontIDType	FrontID;
	///会话编号
	CSessionIDType	SessionID;
	///请求编号
	CSequenceNoType	RequestID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(RequestID)
	));
};
const DWORD FTD_FID_OrderSession=0x0014;

///输入报价
class CFTDInputQuoteField
{
public:
	///报价编号
	CQuoteSysIDType	QuoteSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///数量
	CVolumeType	Volume;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///本地报价编号
	COrderLocalIDType	QuoteLocalID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	CCombOffsetFlagType	BidCombOffsetFlag;
	///买方组合套保标志
	CCombHedgeFlagType	BidCombHedgeFlag;
	///买方价格
	CPriceType	BidPrice;
	///卖方组合开平标志
	CCombOffsetFlagType	AskCombOffsetFlag;
	///卖方组合套保标志
	CCombHedgeFlagType	AskCombHedgeFlag;
	///卖方价格
	CPriceType	AskPrice;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(QuoteSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(QuoteLocalID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BidCombOffsetFlag)
		,
		TYPE_DESC(BidCombHedgeFlag)
		,
		TYPE_DESC(BidPrice)
		,
		TYPE_DESC(AskCombOffsetFlag)
		,
		TYPE_DESC(AskCombHedgeFlag)
		,
		TYPE_DESC(AskPrice)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_InputQuote=0x0021;

///报价操作
class CFTDQuoteActionField
{
public:
	///报价编号
	CQuoteSysIDType	QuoteSysID;
	///本地报价编号
	COrderLocalIDType	QuoteLocalID;
	///报单操作标志
	CActionFlagType	ActionFlag;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///操作本地编号
	COrderLocalIDType	ActionLocalID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(QuoteSysID)
		,
		TYPE_DESC(QuoteLocalID)
		,
		TYPE_DESC(ActionFlag)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ActionLocalID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_QuoteAction=0x0022;

///输入执行宣告
class CFTDInputExecOrderField
{
public:
	///合约编号
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///本地执行宣告编号
	COrderLocalIDType	ExecOrderLocalID;
	///数量
	CVolumeType	Volume;
	///开平标志
	COffsetFlagType	OffsetFlag;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///持仓方向
	CPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	CExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	CExecOrderCloseFlagType	CloseFlag;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ExecOrderLocalID)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(ReservePositionFlag)
		,
		TYPE_DESC(CloseFlag)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_InputExecOrder=0x0023;

///执行宣告操作
class CFTDExecOrderActionField
{
public:
	///执行宣告编号
	CExecOrderSysIDType	ExecOrderSysID;
	///本地执行宣告编号
	COrderLocalIDType	ExecOrderLocalID;
	///报单操作标志
	CActionFlagType	ActionFlag;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///操作本地编号
	COrderLocalIDType	ActionLocalID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ExecOrderSysID)
		,
		TYPE_DESC(ExecOrderLocalID)
		,
		TYPE_DESC(ActionFlag)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ActionLocalID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_ExecOrderAction=0x0024;

///用户登录退出
class CFTDUserLogoutField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
	));
};
const DWORD FTD_FID_UserLogout=0x0031;

///用户口令修改
class CFTDUserPasswordUpdateField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///旧密码
	CPasswordType	OldPassword;
	///新密码
	CPasswordType	NewPassword;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(OldPassword)
		,
		TYPE_DESC(NewPassword)
	));
};
const DWORD FTD_FID_UserPasswordUpdate=0x0032;

///输入非标组合报单
class CFTDInputCombOrderField
{
public:
	///组合报单编号
	COrderSysIDType	CombOrderSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///本地报单编号
	COrderLocalIDType	CombOrderLocalID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///合约代码1
	CInstrumentIDType	InstrumentID1;
	///买卖方向1
	CDirectionType	Direction1;
	///分腿乘数1
	CLegMultipleType	LegMultiple1;
	///开平标志1
	COffsetFlagType	OffsetFlag1;
	///投机套保标志1
	CHedgeFlagType	HedgeFlag1;
	///合约代码2
	CInstrumentIDType	InstrumentID2;
	///买卖方向2
	CDirectionType	Direction2;
	///分腿乘数2
	CLegMultipleType	LegMultiple2;
	///开平标志2
	COffsetFlagType	OffsetFlag2;
	///投机套保标志2
	CHedgeFlagType	HedgeFlag2;
	///合约代码3
	CInstrumentIDType	InstrumentID3;
	///买卖方向3
	CDirectionType	Direction3;
	///分腿乘数3
	CLegMultipleType	LegMultiple3;
	///开平标志3
	COffsetFlagType	OffsetFlag3;
	///投机套保标志3
	CHedgeFlagType	HedgeFlag3;
	///合约代码4
	CInstrumentIDType	InstrumentID4;
	///买卖方向4
	CDirectionType	Direction4;
	///分腿乘数4
	CLegMultipleType	LegMultiple4;
	///开平标志4
	COffsetFlagType	OffsetFlag4;
	///投机套保标志4
	CHedgeFlagType	HedgeFlag4;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(CombOrderSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(CombOrderLocalID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(InstrumentID1)
		,
		TYPE_DESC(Direction1)
		,
		TYPE_DESC(LegMultiple1)
		,
		TYPE_DESC(OffsetFlag1)
		,
		TYPE_DESC(HedgeFlag1)
		,
		TYPE_DESC(InstrumentID2)
		,
		TYPE_DESC(Direction2)
		,
		TYPE_DESC(LegMultiple2)
		,
		TYPE_DESC(OffsetFlag2)
		,
		TYPE_DESC(HedgeFlag2)
		,
		TYPE_DESC(InstrumentID3)
		,
		TYPE_DESC(Direction3)
		,
		TYPE_DESC(LegMultiple3)
		,
		TYPE_DESC(OffsetFlag3)
		,
		TYPE_DESC(HedgeFlag3)
		,
		TYPE_DESC(InstrumentID4)
		,
		TYPE_DESC(Direction4)
		,
		TYPE_DESC(LegMultiple4)
		,
		TYPE_DESC(OffsetFlag4)
		,
		TYPE_DESC(HedgeFlag4)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_InputCombOrder=0x0041;

///强制用户退出
class CFTDForceUserExitField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_ForceUserExit=0x0053;

///会员资金帐户入金
class CFTDAccountDepositField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///资金账号
	CAccountIDType	Account;
	///入金金额
	CMoneyType	Deposit;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(Account)
		,
		TYPE_DESC(Deposit)
	));
};
const DWORD FTD_FID_AccountDeposit=0x0061;

///报单查询
class CFTDQryOrderField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///报单编号
	COrderSysIDType	OrderSysID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///开始时间
	CTimeType	TimeStart;
	///结束时间
	CTimeType	TimeEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(TimeStart)
		,
		TYPE_DESC(TimeEnd)
	));
};
const DWORD FTD_FID_QryOrder=0x3001;

///报价查询
class CFTDQryQuoteField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///报价编号
	CQuoteSysIDType	QuoteSysID;
	///客户代码
	CClientIDType	ClientID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///交易用户代码
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(QuoteSysID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_QryQuote=0x3002;

///成交查询
class CFTDQryTradeField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///起始合约代码
	CInstrumentIDType	InstIDStart;
	///结束合约代码
	CInstrumentIDType	InstIDEnd;
	///成交编号
	CTradeIDType	TradeID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///开始时间
	CTimeType	TimeStart;
	///结束时间
	CTimeType	TimeEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
		,
		TYPE_DESC(TradeID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(TimeStart)
		,
		TYPE_DESC(TimeEnd)
	));
};
const DWORD FTD_FID_QryTrade=0x3003;

///行情查询
class CFTDQryMarketDataField
{
public:
	///产品代码
	CProductIDType	ProductID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(InstrumentID)
	));
};
const DWORD FTD_FID_QryMarketData=0x3004;

///客户查询
class CFTDQryClientField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///起始客户代码
	CClientIDType	ClientIDStart;
	///结束客户代码
	CClientIDType	ClientIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(ClientIDStart)
		,
		TYPE_DESC(ClientIDEnd)
	));
};
const DWORD FTD_FID_QryClient=0x3006;

///会员持仓查询
class CFTDQryPartPositionField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///起始合约代码
	CInstrumentIDType	InstIDStart;
	///结束合约代码
	CInstrumentIDType	InstIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
	));
};
const DWORD FTD_FID_QryPartPosition=0x3007;

///客户持仓查询
class CFTDQryClientPositionField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///起始客户代码
	CClientIDType	ClientIDStart;
	///结束客户代码
	CClientIDType	ClientIDEnd;
	///起始合约代码
	CInstrumentIDType	InstIDStart;
	///结束合约代码
	CInstrumentIDType	InstIDEnd;
	///客户类型
	CClientTypeType	ClientType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(ClientIDStart)
		,
		TYPE_DESC(ClientIDEnd)
		,
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
		,
		TYPE_DESC(ClientType)
	));
};
const DWORD FTD_FID_QryClientPosition=0x3008;

///交易资金查询
class CFTDQryPartAccountField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///资金帐号
	CAccountIDType	AccountID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(AccountID)
	));
};
const DWORD FTD_FID_QryPartAccount=0x3009;

///合约查询
class CFTDQryInstrumentField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品组代码
	CProductGroupIDType	ProductGroupID;
	///产品代码
	CProductIDType	ProductID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(InstrumentID)
	));
};
const DWORD FTD_FID_QryInstrument=0x300A;

///合约状态查询
class CFTDQryInstrumentStatusField
{
public:
	///起始合约代码
	CInstrumentIDType	InstIDStart;
	///结束合约代码
	CInstrumentIDType	InstIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
	));
};
const DWORD FTD_FID_QryInstrumentStatus=0x300B;

///结算组状态查询
class CFTDQrySGDataSyncStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
	));
};
const DWORD FTD_FID_QrySGDataSyncStatus=0x300C;

///用户在线查询
class CFTDQryUserSessionField
{
public:
	///起始交易用户代码
	CUserIDType	UserIDStart;
	///结束交易用户代码
	CUserIDType	UserIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserIDStart)
		,
		TYPE_DESC(UserIDEnd)
	));
};
const DWORD FTD_FID_QryUserSession=0x300D;

///用户查询
class CFTDQryUserField
{
public:
	///起始交易用户代码
	CUserIDType	UserIDStart;
	///结束交易用户代码
	CUserIDType	UserIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserIDStart)
		,
		TYPE_DESC(UserIDEnd)
	));
};
const DWORD FTD_FID_QryUser=0x300E;

///公告查询
class CFTDQryBulletinField
{
public:
	///交易日
	CDateType	TradingDay;
	///市场代码
	CMarketIDType	MarketID;
	///公告编号
	CBulletinIDType	BulletinID;
	///公告类型
	CNewsTypeType	NewsType;
	///紧急程度
	CNewsUrgencyType	NewsUrgency;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(BulletinID)
		,
		TYPE_DESC(NewsType)
		,
		TYPE_DESC(NewsUrgency)
	));
};
const DWORD FTD_FID_QryBulletin=0x300F;

///会员查询
class CFTDQryParticipantField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
	));
};
const DWORD FTD_FID_QryParticipant=0x3010;

///保值额度查询
class CFTDQryHedgeVolumeField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///起始客户代码
	CClientIDType	ClientIDStart;
	///结束客户代码
	CClientIDType	ClientIDEnd;
	///起始合约代码
	CInstrumentIDType	InstIDStart;
	///结束合约代码
	CInstrumentIDType	InstIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(ClientIDStart)
		,
		TYPE_DESC(ClientIDEnd)
		,
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
	));
};
const DWORD FTD_FID_QryHedgeVolume=0x3011;

///合约价位查询
class CFTDQryMBLMarketDataField
{
public:
	///起始合约代码
	CInstrumentIDType	InstIDStart;
	///结束合约代码
	CInstrumentIDType	InstIDEnd;
	///买卖方向
	CDirectionType	Direction;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
		,
		TYPE_DESC(Direction)
	));
};
const DWORD FTD_FID_QryMBLMarketData=0x3014;

///信用限额查询
class CFTDQryCreditLimitField
{
public:
	///交易会员编号
	CParticipantIDType	ParticipantID;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClearingPartID)
	));
};
const DWORD FTD_FID_QryCreditLimit=0x3015;

///执行宣告查询
class CFTDQryExecOrderField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///执行宣告编号
	CExecOrderSysIDType	ExecOrderSysID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///开始时间
	CTimeType	TimeStart;
	///结束时间
	CTimeType	TimeEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(ExecOrderSysID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(TimeStart)
		,
		TYPE_DESC(TimeEnd)
	));
};
const DWORD FTD_FID_QryExecOrder=0x3016;

///非标组合报单查询
class CFTDQryCombOrderField
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///组合报单编号
	COrderSysIDType	CombOrderSysID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(CombOrderSysID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_QryCombOrder=0x3001;

///会员资金应答
class CFTDRspPartAccountField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///上次结算准备金
	CMoneyType	PreBalance;
	///当前保证金总额
	CMoneyType	CurrMargin;
	///平仓盈亏
	CMoneyType	CloseProfit;
	///期权权利金收支
	CMoneyType	Premium;
	///入金金额
	CMoneyType	Deposit;
	///出金金额
	CMoneyType	Withdraw;
	///期货结算准备金
	CMoneyType	Balance;
	///可提资金
	CMoneyType	Available;
	///资金帐号
	CAccountIDType	AccountID;
	///冻结的保证金
	CMoneyType	FrozenMargin;
	///冻结的权利金
	CMoneyType	FrozenPremium;
	///基本准备金
	CMoneyType	BaseReserve;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(PreBalance)
		,
		TYPE_DESC(CurrMargin)
		,
		TYPE_DESC(CloseProfit)
		,
		TYPE_DESC(Premium)
		,
		TYPE_DESC(Deposit)
		,
		TYPE_DESC(Withdraw)
		,
		TYPE_DESC(Balance)
		,
		TYPE_DESC(Available)
		,
		TYPE_DESC(AccountID)
		,
		TYPE_DESC(FrozenMargin)
		,
		TYPE_DESC(FrozenPremium)
		,
		TYPE_DESC(BaseReserve)
	));
};
const DWORD FTD_FID_RspPartAccount=0x3101;

///会员持仓应答
class CFTDRspPartPositionField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///持仓多空方向
	CPosiDirectionType	PosiDirection;
	///上日持仓
	CVolumeType	YdPosition;
	///今日持仓
	CVolumeType	Position;
	///多头冻结
	CVolumeType	LongFrozen;
	///空头冻结
	CVolumeType	ShortFrozen;
	///昨日多头冻结
	CVolumeType	YdLongFrozen;
	///昨日空头冻结
	CVolumeType	YdShortFrozen;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CTradingRoleType	TradingRole;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(YdPosition)
		,
		TYPE_DESC(Position)
		,
		TYPE_DESC(LongFrozen)
		,
		TYPE_DESC(ShortFrozen)
		,
		TYPE_DESC(YdLongFrozen)
		,
		TYPE_DESC(YdShortFrozen)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
	));
};
const DWORD FTD_FID_RspPartPosition=0x3102;

///客户持仓应答
class CFTDRspClientPositionField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///持仓多空方向
	CPosiDirectionType	PosiDirection;
	///上日持仓
	CVolumeType	YdPosition;
	///今日持仓
	CVolumeType	Position;
	///多头冻结
	CVolumeType	LongFrozen;
	///空头冻结
	CVolumeType	ShortFrozen;
	///昨日多头冻结
	CVolumeType	YdLongFrozen;
	///昨日空头冻结
	CVolumeType	YdShortFrozen;
	///当日买成交量
	CVolumeType	BuyTradeVolume;
	///当日卖成交量
	CVolumeType	SellTradeVolume;
	///持仓成本
	CMoneyType	PositionCost;
	///昨日持仓成本
	CMoneyType	YdPositionCost;
	///占用的保证金
	CMoneyType	UseMargin;
	///冻结的保证金
	CMoneyType	FrozenMargin;
	///多头冻结的保证金
	CMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	CMoneyType	ShortFrozenMargin;
	///冻结的权利金
	CMoneyType	FrozenPremium;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(YdPosition)
		,
		TYPE_DESC(Position)
		,
		TYPE_DESC(LongFrozen)
		,
		TYPE_DESC(ShortFrozen)
		,
		TYPE_DESC(YdLongFrozen)
		,
		TYPE_DESC(YdShortFrozen)
		,
		TYPE_DESC(BuyTradeVolume)
		,
		TYPE_DESC(SellTradeVolume)
		,
		TYPE_DESC(PositionCost)
		,
		TYPE_DESC(YdPositionCost)
		,
		TYPE_DESC(UseMargin)
		,
		TYPE_DESC(FrozenMargin)
		,
		TYPE_DESC(LongFrozenMargin)
		,
		TYPE_DESC(ShortFrozenMargin)
		,
		TYPE_DESC(FrozenPremium)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
	));
};
const DWORD FTD_FID_RspClientPosition=0x3103;

///合约查询应答
class CFTDRspInstrumentField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///产品组代码
	CProductGroupIDType	ProductGroupID;
	///基础商品代码
	CInstrumentIDType	UnderlyingInstrID;
	///产品类型
	CProductClassType	ProductClass;
	///持仓类型
	CPositionTypeType	PositionType;
	///执行价
	CPriceType	StrikePrice;
	///期权类型
	COptionsTypeType	OptionsType;
	///合约数量乘数
	CVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	CUnderlyingMultipleType	UnderlyingMultiple;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///合约名称
	CInstrumentNameType	InstrumentName;
	///交割年份
	CYearType	DeliveryYear;
	///交割月
	CMonthType	DeliveryMonth;
	///提前月份
	CAdvanceMonthType	AdvanceMonth;
	///当前是否交易
	CBoolType	IsTrading;
	///创建日
	CDateType	CreateDate;
	///上市日
	CDateType	OpenDate;
	///到期日
	CDateType	ExpireDate;
	///开始交割日
	CDateType	StartDelivDate;
	///最后交割日
	CDateType	EndDelivDate;
	///挂牌基准价
	CPriceType	BasisPrice;
	///市价单最大下单量
	CVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	CVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	CVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	CVolumeType	MinLimitOrderVolume;
	///最小变动价位
	CPriceType	PriceTick;
	///交割月自然人开仓
	CMonthCountType	AllowDelivPersonOpen;
	///币种代码
	CCurrencyIDType	CurrencyID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ProductGroupID)
		,
		TYPE_DESC(UnderlyingInstrID)
		,
		TYPE_DESC(ProductClass)
		,
		TYPE_DESC(PositionType)
		,
		TYPE_DESC(StrikePrice)
		,
		TYPE_DESC(OptionsType)
		,
		TYPE_DESC(VolumeMultiple)
		,
		TYPE_DESC(UnderlyingMultiple)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentName)
		,
		TYPE_DESC(DeliveryYear)
		,
		TYPE_DESC(DeliveryMonth)
		,
		TYPE_DESC(AdvanceMonth)
		,
		TYPE_DESC(IsTrading)
		,
		TYPE_DESC(CreateDate)
		,
		TYPE_DESC(OpenDate)
		,
		TYPE_DESC(ExpireDate)
		,
		TYPE_DESC(StartDelivDate)
		,
		TYPE_DESC(EndDelivDate)
		,
		TYPE_DESC(BasisPrice)
		,
		TYPE_DESC(MaxMarketOrderVolume)
		,
		TYPE_DESC(MinMarketOrderVolume)
		,
		TYPE_DESC(MaxLimitOrderVolume)
		,
		TYPE_DESC(MinLimitOrderVolume)
		,
		TYPE_DESC(PriceTick)
		,
		TYPE_DESC(AllowDelivPersonOpen)
		,
		TYPE_DESC(CurrencyID)
	));
};
const DWORD FTD_FID_RspInstrument=0x3104;

///信息查询
class CFTDQryInformationField
{
public:
	///起始信息代码
	CInformationIDType	InformationIDStart;
	///结束信息代码
	CInformationIDType	InformationIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InformationIDStart)
		,
		TYPE_DESC(InformationIDEnd)
	));
};
const DWORD FTD_FID_QryInformation=0x3105;

///信息查询
class CFTDInformationField
{
public:
	///信息编号
	CInformationIDType	InformationID;
	///序列号
	CSequenceNoType	SequenceNo;
	///消息正文
	CContentType	Content;
	///正文长度
	CContentLengthType	ContentLength;
	///是否完成
	CBoolType	IsAccomplished;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InformationID)
		,
		TYPE_DESC(SequenceNo)
		,
		TYPE_DESC(Content)
		,
		TYPE_DESC(ContentLength)
		,
		TYPE_DESC(IsAccomplished)
	));
};
const DWORD FTD_FID_Information=0x3106;

///信用限额
class CFTDCreditLimitField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///上次结算准备金
	CMoneyType	PreBalance;
	///当前保证金总额
	CMoneyType	CurrMargin;
	///平仓盈亏
	CMoneyType	CloseProfit;
	///期权权利金收支
	CMoneyType	Premium;
	///入金金额
	CMoneyType	Deposit;
	///出金金额
	CMoneyType	Withdraw;
	///期货结算准备金
	CMoneyType	Balance;
	///可提资金
	CMoneyType	Available;
	///交易会员编号
	CParticipantIDType	ParticipantID;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///冻结的保证金
	CMoneyType	FrozenMargin;
	///冻结的权利金
	CMoneyType	FrozenPremium;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(PreBalance)
		,
		TYPE_DESC(CurrMargin)
		,
		TYPE_DESC(CloseProfit)
		,
		TYPE_DESC(Premium)
		,
		TYPE_DESC(Deposit)
		,
		TYPE_DESC(Withdraw)
		,
		TYPE_DESC(Balance)
		,
		TYPE_DESC(Available)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(FrozenMargin)
		,
		TYPE_DESC(FrozenPremium)
	));
};
const DWORD FTD_FID_CreditLimit=0x3108;

///客户查询应答
class CFTDRspClientField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///原证件号码
	CIdentifiedCardNoV1Type	UseLess;
	///交易角色
	CTradingRoleType	TradingRole;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	///会员号
	CParticipantIDType	ParticipantID;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(UseLess)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(IdentifiedCardNo)
	));
};
const DWORD FTD_FID_RspClient=0x3109;

///数据流回退
class CFTDFlowMessageCancelField
{
public:
	///序列系列号
	CSequenceSeriesType	SequenceSeries;
	///交易日
	CDateType	TradingDay;
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	///回退起始序列号
	CSequenceNoType	StartSequenceNo;
	///回退结束序列号
	CSequenceNoType	EndSequenceNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SequenceSeries)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(DataCenterID)
		,
		TYPE_DESC(StartSequenceNo)
		,
		TYPE_DESC(EndSequenceNo)
	));
};
const DWORD FTD_FID_FlowMessageCancel=0x3201;

///汇率查询
class CFTDQryExchangeRateField
{
public:
	///币种代码
	CCurrencyIDType	CurrencyID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(CurrencyID)
	));
};
const DWORD FTD_FID_QryExchangeRate=0x310A;

///汇率查询应答
class CFTDRspExchangeRateField
{
public:
	///交易日
	CDateType	TradingDay;
	///币种代码
	CCurrencyIDType	CurrencyID;
	///外汇交易单位
	CRateUnitType	RateUnit;
	///外汇中间价
	CExRatePriceType	RatePrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(CurrencyID)
		,
		TYPE_DESC(RateUnit)
		,
		TYPE_DESC(RatePrice)
	));
};
const DWORD FTD_FID_RspExchangeRate=0x310B;

///会员
class CFTDParticipantField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///会员简称
	CParticipantAbbrType	ParticipantAbbr;
	///会员类型
	CMemberTypeType	MemberType;
	///是否活跃
	CBoolType	IsActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ParticipantAbbr)
		,
		TYPE_DESC(MemberType)
		,
		TYPE_DESC(IsActive)
	));
};
const DWORD FTD_FID_Participant=0x1401;

///用户
class CFTDUserField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///交易用户类型
	CUserTypeType	UserType;
	///密码
	CPasswordType	Password;
	///交易员权限
	CUserActiveType	IsActive;
	///交易员是否禁止直接连接前置
	CBoolType	IsDirectConnForbidden;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(IsDirectConnForbidden)
	));
};
const DWORD FTD_FID_User=0x1402;

///客户
class CFTDClientField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	CTradingRoleType	TradingRole;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(IdentifiedCardNo)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
	));
};
const DWORD FTD_FID_Client=0x1403;

///用户会话
class CFTDUserSessionField
{
public:
	///前置编号
	CFrontIDType	FrontID;
	///交易用户代码
	CUserIDType	UserID;
	///交易用户类型
	CUserTypeType	UserType;
	///会话编号
	CSessionIDType	SessionID;
	///登录时间
	CTimeType	LoginTime;
	///会员代码
	CParticipantIDType	ParticipantID;
	///IP地址
	CIPAddressType	IPAddress;
	///用户端产品信息
	CProductInfoType	UserProductInfo;
	///接口端产品信息
	CProductInfoType	InterfaceProductInfo;
	///协议信息
	CProtocolInfoType	ProtocolInfo;
	///会话类型
	CSessionTypeType	SessionType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(SessionType)
	));
};
const DWORD FTD_FID_UserSession=0x1406;

///产品组
class CFTDProductGroupField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品组代码
	CProductGroupIDType	ProductGroupID;
	///产品组名称
	CProductGroupNameType	ProductGroupName;
	///商品代码
	CCommodityIDType	CommodityID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductGroupID)
		,
		TYPE_DESC(ProductGroupName)
		,
		TYPE_DESC(CommodityID)
	));
};
const DWORD FTD_FID_ProductGroup=0x2101;

///产品
class CFTDProductField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///产品组代码
	CProductGroupIDType	ProductGroupID;
	///产品名称
	CProductNameType	ProductName;
	///产品类型
	CProductClassType	ProductClass;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ProductGroupID)
		,
		TYPE_DESC(ProductName)
		,
		TYPE_DESC(ProductClass)
	));
};
const DWORD FTD_FID_Product=0x2102;

///合约
class CFTDInstrumentField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///产品组代码
	CProductGroupIDType	ProductGroupID;
	///基础商品代码
	CInstrumentIDType	UnderlyingInstrID;
	///产品类型
	CProductClassType	ProductClass;
	///持仓类型
	CPositionTypeType	PositionType;
	///执行价
	CPriceType	StrikePrice;
	///期权类型
	COptionsTypeType	OptionsType;
	///合约数量乘数
	CVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	CUnderlyingMultipleType	UnderlyingMultiple;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///合约名称
	CInstrumentNameType	InstrumentName;
	///交割年份
	CYearType	DeliveryYear;
	///交割月
	CMonthType	DeliveryMonth;
	///提前月份
	CAdvanceMonthType	AdvanceMonth;
	///当前是否交易
	CBoolType	IsTrading;
	///币种代码
	CCurrencyIDType	CurrencyID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ProductGroupID)
		,
		TYPE_DESC(UnderlyingInstrID)
		,
		TYPE_DESC(ProductClass)
		,
		TYPE_DESC(PositionType)
		,
		TYPE_DESC(StrikePrice)
		,
		TYPE_DESC(OptionsType)
		,
		TYPE_DESC(VolumeMultiple)
		,
		TYPE_DESC(UnderlyingMultiple)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentName)
		,
		TYPE_DESC(DeliveryYear)
		,
		TYPE_DESC(DeliveryMonth)
		,
		TYPE_DESC(AdvanceMonth)
		,
		TYPE_DESC(IsTrading)
		,
		TYPE_DESC(CurrencyID)
	));
};
const DWORD FTD_FID_Instrument=0x2103;

///组合交易合约的单腿
class CFTDCombinationLegField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///组合合约代码
	CInstrumentIDType	CombInstrumentID;
	///单腿编号
	CLegIDType	LegID;
	///单腿合约代码
	CInstrumentIDType	LegInstrumentID;
	///买卖方向
	CDirectionType	Direction;
	///单腿乘数
	CLegMultipleType	LegMultiple;
	///推导层数
	CImplyLevelType	ImplyLevel;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(CombInstrumentID)
		,
		TYPE_DESC(LegID)
		,
		TYPE_DESC(LegInstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(LegMultiple)
		,
		TYPE_DESC(ImplyLevel)
	));
};
const DWORD FTD_FID_CombinationLeg=0x2104;

///账户资金信息
class CFTDAccountInfoField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///上次结算准备金
	CMoneyType	PreBalance;
	///当前保证金总额
	CMoneyType	CurrMargin;
	///平仓盈亏
	CMoneyType	CloseProfit;
	///期权权利金收支
	CMoneyType	Premium;
	///入金金额
	CMoneyType	Deposit;
	///出金金额
	CMoneyType	Withdraw;
	///期货结算准备金
	CMoneyType	Balance;
	///可提资金
	CMoneyType	Available;
	///开户日期
	CDateType	DateAccountOpen;
	///上次结算的日期
	CDateType	PreDate;
	///上结算的编号
	CSettlementIDType	PreSettlementID;
	///上次保证金总额
	CMoneyType	PreMargin;
	///期货保证金
	CMoneyType	FuturesMargin;
	///期权保证金
	CMoneyType	OptionsMargin;
	///持仓盈亏
	CMoneyType	PositionProfit;
	///当日盈亏
	CMoneyType	Profit;
	///利息收入
	CMoneyType	Interest;
	///手续费
	CMoneyType	Fee;
	///总质押金额
	CMoneyType	TotalCollateral;
	///用质押抵的保证金金额
	CMoneyType	CollateralForMargin;
	///上次资金利息积数
	CMoneyType	PreAccmulateInterest;
	///资金利息积数
	CMoneyType	AccumulateInterest;
	///质押手续费积数
	CMoneyType	AccumulateFee;
	///冻结资金
	CMoneyType	ForzenDeposit;
	///帐户状态
	CAccountStatusType	AccountStatus;
	///资金帐号
	CAccountIDType	AccountID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(PreBalance)
		,
		TYPE_DESC(CurrMargin)
		,
		TYPE_DESC(CloseProfit)
		,
		TYPE_DESC(Premium)
		,
		TYPE_DESC(Deposit)
		,
		TYPE_DESC(Withdraw)
		,
		TYPE_DESC(Balance)
		,
		TYPE_DESC(Available)
		,
		TYPE_DESC(DateAccountOpen)
		,
		TYPE_DESC(PreDate)
		,
		TYPE_DESC(PreSettlementID)
		,
		TYPE_DESC(PreMargin)
		,
		TYPE_DESC(FuturesMargin)
		,
		TYPE_DESC(OptionsMargin)
		,
		TYPE_DESC(PositionProfit)
		,
		TYPE_DESC(Profit)
		,
		TYPE_DESC(Interest)
		,
		TYPE_DESC(Fee)
		,
		TYPE_DESC(TotalCollateral)
		,
		TYPE_DESC(CollateralForMargin)
		,
		TYPE_DESC(PreAccmulateInterest)
		,
		TYPE_DESC(AccumulateInterest)
		,
		TYPE_DESC(AccumulateFee)
		,
		TYPE_DESC(ForzenDeposit)
		,
		TYPE_DESC(AccountStatus)
		,
		TYPE_DESC(AccountID)
	));
};
const DWORD FTD_FID_AccountInfo=0x2401;

///会员合约持仓
class CFTDPartPositionField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///持仓多空方向
	CPosiDirectionType	PosiDirection;
	///上日持仓
	CVolumeType	YdPosition;
	///今日持仓
	CVolumeType	Position;
	///多头冻结
	CVolumeType	LongFrozen;
	///空头冻结
	CVolumeType	ShortFrozen;
	///昨日多头冻结
	CVolumeType	YdLongFrozen;
	///昨日空头冻结
	CVolumeType	YdShortFrozen;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CTradingRoleType	TradingRole;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(YdPosition)
		,
		TYPE_DESC(Position)
		,
		TYPE_DESC(LongFrozen)
		,
		TYPE_DESC(ShortFrozen)
		,
		TYPE_DESC(YdLongFrozen)
		,
		TYPE_DESC(YdShortFrozen)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
	));
};
const DWORD FTD_FID_PartPosition=0x2402;

///客户合约持仓
class CFTDClientPositionField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///持仓多空方向
	CPosiDirectionType	PosiDirection;
	///上日持仓
	CVolumeType	YdPosition;
	///今日持仓
	CVolumeType	Position;
	///多头冻结
	CVolumeType	LongFrozen;
	///空头冻结
	CVolumeType	ShortFrozen;
	///昨日多头冻结
	CVolumeType	YdLongFrozen;
	///昨日空头冻结
	CVolumeType	YdShortFrozen;
	///当日买成交量
	CVolumeType	BuyTradeVolume;
	///当日卖成交量
	CVolumeType	SellTradeVolume;
	///持仓成本
	CMoneyType	PositionCost;
	///昨日持仓成本
	CMoneyType	YdPositionCost;
	///占用的保证金
	CMoneyType	UseMargin;
	///冻结的保证金
	CMoneyType	FrozenMargin;
	///多头冻结的保证金
	CMoneyType	LongFrozenMargin;
	///空头冻结的保证金
	CMoneyType	ShortFrozenMargin;
	///冻结的权利金
	CMoneyType	FrozenPremium;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(YdPosition)
		,
		TYPE_DESC(Position)
		,
		TYPE_DESC(LongFrozen)
		,
		TYPE_DESC(ShortFrozen)
		,
		TYPE_DESC(YdLongFrozen)
		,
		TYPE_DESC(YdShortFrozen)
		,
		TYPE_DESC(BuyTradeVolume)
		,
		TYPE_DESC(SellTradeVolume)
		,
		TYPE_DESC(PositionCost)
		,
		TYPE_DESC(YdPositionCost)
		,
		TYPE_DESC(UseMargin)
		,
		TYPE_DESC(FrozenMargin)
		,
		TYPE_DESC(LongFrozenMargin)
		,
		TYPE_DESC(ShortFrozenMargin)
		,
		TYPE_DESC(FrozenPremium)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
	));
};
const DWORD FTD_FID_ClientPosition=0x2403;

///保值额度量
class CFTDHedgeVolumeField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///多头保值额度最初申请量
	CVolumeType	LongVolumeOriginal;
	///空头保值额度最初申请量
	CVolumeType	ShortVolumeOriginal;
	///多头保值额度
	CVolumeType	LongVolume;
	///空头保值额度
	CVolumeType	ShortVolume;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(LongVolumeOriginal)
		,
		TYPE_DESC(ShortVolumeOriginal)
		,
		TYPE_DESC(LongVolume)
		,
		TYPE_DESC(ShortVolume)
	));
};
const DWORD FTD_FID_HedgeVolume=0x2404;

///市场行情
class CFTDMarketDataField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///最新价
	CPriceType	LastPrice;
	///昨结算
	CPriceType	PreSettlementPrice;
	///昨收盘
	CPriceType	PreClosePrice;
	///昨持仓量
	CLargeVolumeType	PreOpenInterest;
	///今开盘
	CPriceType	OpenPrice;
	///最高价
	CPriceType	HighestPrice;
	///最低价
	CPriceType	LowestPrice;
	///数量
	CVolumeType	Volume;
	///成交金额
	CMoneyType	Turnover;
	///持仓量
	CLargeVolumeType	OpenInterest;
	///今收盘
	CPriceType	ClosePrice;
	///今结算
	CPriceType	SettlementPrice;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	///昨虚实度
	CRatioType	PreDelta;
	///今虚实度
	CRatioType	CurrDelta;
	///最后修改时间
	CTimeType	UpdateTime;
	///最后修改毫秒
	CMillisecType	UpdateMillisec;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///业务发生日期
	CDateType	ActionDay;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(LastPrice)
		,
		TYPE_DESC(PreSettlementPrice)
		,
		TYPE_DESC(PreClosePrice)
		,
		TYPE_DESC(PreOpenInterest)
		,
		TYPE_DESC(OpenPrice)
		,
		TYPE_DESC(HighestPrice)
		,
		TYPE_DESC(LowestPrice)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(Turnover)
		,
		TYPE_DESC(OpenInterest)
		,
		TYPE_DESC(ClosePrice)
		,
		TYPE_DESC(SettlementPrice)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
		,
		TYPE_DESC(PreDelta)
		,
		TYPE_DESC(CurrDelta)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ActionDay)
	));
};
const DWORD FTD_FID_MarketData=0x2407;

///深度市场行情
class CFTDDepthMarketDataField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///最新价
	CPriceType	LastPrice;
	///昨结算
	CPriceType	PreSettlementPrice;
	///昨收盘
	CPriceType	PreClosePrice;
	///昨持仓量
	CLargeVolumeType	PreOpenInterest;
	///今开盘
	CPriceType	OpenPrice;
	///最高价
	CPriceType	HighestPrice;
	///最低价
	CPriceType	LowestPrice;
	///数量
	CVolumeType	Volume;
	///成交金额
	CMoneyType	Turnover;
	///持仓量
	CLargeVolumeType	OpenInterest;
	///今收盘
	CPriceType	ClosePrice;
	///今结算
	CPriceType	SettlementPrice;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	///昨虚实度
	CRatioType	PreDelta;
	///今虚实度
	CRatioType	CurrDelta;
	///最后修改时间
	CTimeType	UpdateTime;
	///最后修改毫秒
	CMillisecType	UpdateMillisec;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///申买价一
	CPriceType	BidPrice1;
	///申买量一
	CVolumeType	BidVolume1;
	///申卖价一
	CPriceType	AskPrice1;
	///申卖量一
	CVolumeType	AskVolume1;
	///申买价二
	CPriceType	BidPrice2;
	///申买量二
	CVolumeType	BidVolume2;
	///申卖价二
	CPriceType	AskPrice2;
	///申卖量二
	CVolumeType	AskVolume2;
	///申买价三
	CPriceType	BidPrice3;
	///申买量三
	CVolumeType	BidVolume3;
	///申卖价三
	CPriceType	AskPrice3;
	///申卖量三
	CVolumeType	AskVolume3;
	///申买价四
	CPriceType	BidPrice4;
	///申买量四
	CVolumeType	BidVolume4;
	///申卖价四
	CPriceType	AskPrice4;
	///申卖量四
	CVolumeType	AskVolume4;
	///申买价五
	CPriceType	BidPrice5;
	///申买量五
	CVolumeType	BidVolume5;
	///申卖价五
	CPriceType	AskPrice5;
	///申卖量五
	CVolumeType	AskVolume5;
	///业务发生日期
	CDateType	ActionDay;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(LastPrice)
		,
		TYPE_DESC(PreSettlementPrice)
		,
		TYPE_DESC(PreClosePrice)
		,
		TYPE_DESC(PreOpenInterest)
		,
		TYPE_DESC(OpenPrice)
		,
		TYPE_DESC(HighestPrice)
		,
		TYPE_DESC(LowestPrice)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(Turnover)
		,
		TYPE_DESC(OpenInterest)
		,
		TYPE_DESC(ClosePrice)
		,
		TYPE_DESC(SettlementPrice)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
		,
		TYPE_DESC(PreDelta)
		,
		TYPE_DESC(CurrDelta)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(BidPrice1)
		,
		TYPE_DESC(BidVolume1)
		,
		TYPE_DESC(AskPrice1)
		,
		TYPE_DESC(AskVolume1)
		,
		TYPE_DESC(BidPrice2)
		,
		TYPE_DESC(BidVolume2)
		,
		TYPE_DESC(AskPrice2)
		,
		TYPE_DESC(AskVolume2)
		,
		TYPE_DESC(BidPrice3)
		,
		TYPE_DESC(BidVolume3)
		,
		TYPE_DESC(AskPrice3)
		,
		TYPE_DESC(AskVolume3)
		,
		TYPE_DESC(BidPrice4)
		,
		TYPE_DESC(BidVolume4)
		,
		TYPE_DESC(AskPrice4)
		,
		TYPE_DESC(AskVolume4)
		,
		TYPE_DESC(BidPrice5)
		,
		TYPE_DESC(BidVolume5)
		,
		TYPE_DESC(AskPrice5)
		,
		TYPE_DESC(AskVolume5)
		,
		TYPE_DESC(ActionDay)
	));
};
const DWORD FTD_FID_DepthMarketData=0x2408;

///分价表
class CFTDMBLMarketDataField
{
public:
	///合约代码
	CInstrumentIDType	InstrumentID;
	///买卖方向
	CDirectionType	Direction;
	///价格
	CPriceType	Price;
	///数量
	CVolumeType	Volume;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
	));
};
const DWORD FTD_FID_MBLMarketData=0x2410;

///别名定义
class CFTDAliasDefineField
{
public:
	///起始位置
	CStartPosType	StartPos;
	///别名
	CAliasType	Alias;
	///原文
	COriginalTextType	OriginalText;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartPos)
		,
		TYPE_DESC(Alias)
		,
		TYPE_DESC(OriginalText)
	));
};
const DWORD FTD_FID_AliasDefine=0x2411;

///行情基础属性
class CFTDMarketDataBaseField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///昨结算
	CPriceType	PreSettlementPrice;
	///昨收盘
	CPriceType	PreClosePrice;
	///昨持仓量
	CLargeVolumeType	PreOpenInterest;
	///昨虚实度
	CRatioType	PreDelta;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(PreSettlementPrice)
		,
		TYPE_DESC(PreClosePrice)
		,
		TYPE_DESC(PreOpenInterest)
		,
		TYPE_DESC(PreDelta)
	));
};
const DWORD FTD_FID_MarketDataBase=0x2431;

///行情静态属性
class CFTDMarketDataStaticField
{
public:
	///今开盘
	CPriceType	OpenPrice;
	///最高价
	CPriceType	HighestPrice;
	///最低价
	CPriceType	LowestPrice;
	///今收盘
	CPriceType	ClosePrice;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	///今结算
	CPriceType	SettlementPrice;
	///今虚实度
	CRatioType	CurrDelta;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OpenPrice)
		,
		TYPE_DESC(HighestPrice)
		,
		TYPE_DESC(LowestPrice)
		,
		TYPE_DESC(ClosePrice)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
		,
		TYPE_DESC(SettlementPrice)
		,
		TYPE_DESC(CurrDelta)
	));
};
const DWORD FTD_FID_MarketDataStatic=0x2432;

///行情最新成交属性
class CFTDMarketDataLastMatchField
{
public:
	///最新价
	CPriceType	LastPrice;
	///数量
	CVolumeType	Volume;
	///成交金额
	CMoneyType	Turnover;
	///持仓量
	CLargeVolumeType	OpenInterest;
	TYPE_DESCRIPTOR((
		TYPE_DESC(LastPrice)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(Turnover)
		,
		TYPE_DESC(OpenInterest)
	));
};
const DWORD FTD_FID_MarketDataLastMatch=0x2433;

///行情最优价属性
class CFTDMarketDataBestPriceField
{
public:
	///申买价一
	CPriceType	BidPrice1;
	///申买量一
	CVolumeType	BidVolume1;
	///申卖价一
	CPriceType	AskPrice1;
	///申卖量一
	CVolumeType	AskVolume1;
	TYPE_DESCRIPTOR((
		TYPE_DESC(BidPrice1)
		,
		TYPE_DESC(BidVolume1)
		,
		TYPE_DESC(AskPrice1)
		,
		TYPE_DESC(AskVolume1)
	));
};
const DWORD FTD_FID_MarketDataBestPrice=0x2434;

///行情申买二、三属性
class CFTDMarketDataBid23Field
{
public:
	///申买价二
	CPriceType	BidPrice2;
	///申买量二
	CVolumeType	BidVolume2;
	///申买价三
	CPriceType	BidPrice3;
	///申买量三
	CVolumeType	BidVolume3;
	TYPE_DESCRIPTOR((
		TYPE_DESC(BidPrice2)
		,
		TYPE_DESC(BidVolume2)
		,
		TYPE_DESC(BidPrice3)
		,
		TYPE_DESC(BidVolume3)
	));
};
const DWORD FTD_FID_MarketDataBid23=0x2435;

///行情申卖二、三属性
class CFTDMarketDataAsk23Field
{
public:
	///申卖价二
	CPriceType	AskPrice2;
	///申卖量二
	CVolumeType	AskVolume2;
	///申卖价三
	CPriceType	AskPrice3;
	///申卖量三
	CVolumeType	AskVolume3;
	TYPE_DESCRIPTOR((
		TYPE_DESC(AskPrice2)
		,
		TYPE_DESC(AskVolume2)
		,
		TYPE_DESC(AskPrice3)
		,
		TYPE_DESC(AskVolume3)
	));
};
const DWORD FTD_FID_MarketDataAsk23=0x2436;

///行情申买四、五属性
class CFTDMarketDataBid45Field
{
public:
	///申买价四
	CPriceType	BidPrice4;
	///申买量四
	CVolumeType	BidVolume4;
	///申买价五
	CPriceType	BidPrice5;
	///申买量五
	CVolumeType	BidVolume5;
	TYPE_DESCRIPTOR((
		TYPE_DESC(BidPrice4)
		,
		TYPE_DESC(BidVolume4)
		,
		TYPE_DESC(BidPrice5)
		,
		TYPE_DESC(BidVolume5)
	));
};
const DWORD FTD_FID_MarketDataBid45=0x2437;

///行情申卖四、五属性
class CFTDMarketDataAsk45Field
{
public:
	///申卖价四
	CPriceType	AskPrice4;
	///申卖量四
	CVolumeType	AskVolume4;
	///申卖价五
	CPriceType	AskPrice5;
	///申卖量五
	CVolumeType	AskVolume5;
	TYPE_DESCRIPTOR((
		TYPE_DESC(AskPrice4)
		,
		TYPE_DESC(AskVolume4)
		,
		TYPE_DESC(AskPrice5)
		,
		TYPE_DESC(AskVolume5)
	));
};
const DWORD FTD_FID_MarketDataAsk45=0x2438;

///行情更新时间属性
class CFTDMarketDataUpdateTimeField
{
public:
	///合约代码
	CInstrumentIDType	InstrumentID;
	///最后修改时间
	CTimeType	UpdateTime;
	///最后修改毫秒
	CMillisecType	UpdateMillisec;
	///业务发生日期
	CDateType	ActionDay;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
		,
		TYPE_DESC(ActionDay)
	));
};
const DWORD FTD_FID_MarketDataUpdateTime=0x2439;

///报价
class CFTDQuoteField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///报价编号
	CQuoteSysIDType	QuoteSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///数量
	CVolumeType	Volume;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///本地报价编号
	COrderLocalIDType	QuoteLocalID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///买方组合开平标志
	CCombOffsetFlagType	BidCombOffsetFlag;
	///买方组合套保标志
	CCombHedgeFlagType	BidCombHedgeFlag;
	///买方价格
	CPriceType	BidPrice;
	///卖方组合开平标志
	CCombOffsetFlagType	AskCombOffsetFlag;
	///卖方组合套保标志
	CCombHedgeFlagType	AskCombHedgeFlag;
	///卖方价格
	CPriceType	AskPrice;
	///插入时间
	CTimeType	InsertTime;
	///撤销时间
	CTimeType	CancelTime;
	///成交时间
	CTimeType	TradeTime;
	///买方报单编号
	COrderSysIDType	BidOrderSysID;
	///卖方报单编号
	COrderSysIDType	AskOrderSysID;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	CDateType	ActionDay;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(QuoteSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(QuoteLocalID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BidCombOffsetFlag)
		,
		TYPE_DESC(BidCombHedgeFlag)
		,
		TYPE_DESC(BidPrice)
		,
		TYPE_DESC(AskCombOffsetFlag)
		,
		TYPE_DESC(AskCombHedgeFlag)
		,
		TYPE_DESC(AskPrice)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(CancelTime)
		,
		TYPE_DESC(TradeTime)
		,
		TYPE_DESC(BidOrderSysID)
		,
		TYPE_DESC(AskOrderSysID)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(ActionDay)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_Quote=0x2506;

///成交
class CFTDTradeField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///成交编号
	CTradeIDType	TradeID;
	///买卖方向
	CDirectionType	Direction;
	///报单编号
	COrderSysIDType	OrderSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易角色
	CTradingRoleType	TradingRole;
	///资金帐号
	CAccountIDType	AccountID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///开平标志
	COffsetFlagType	OffsetFlag;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///价格
	CPriceType	Price;
	///数量
	CVolumeType	Volume;
	///成交时间
	CTimeType	TradeTime;
	///成交类型
	CTradeTypeType	TradeType;
	///成交价来源
	CPriceSourceType	PriceSource;
	///交易用户代码
	CUserIDType	UserID;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	CDateType	ActionDay;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(TradeID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(AccountID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(TradeTime)
		,
		TYPE_DESC(TradeType)
		,
		TYPE_DESC(PriceSource)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(ActionDay)
	));
};
const DWORD FTD_FID_Trade=0x2507;

///报单
class CFTDOrderField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///报单编号
	COrderSysIDType	OrderSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///报单价格条件
	COrderPriceTypeType	OrderPriceType;
	///买卖方向
	CDirectionType	Direction;
	///组合开平标志
	CCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType	CombHedgeFlag;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType	TimeCondition;
	///GTD日期
	CDateType	GTDDate;
	///成交量类型
	CVolumeConditionType	VolumeCondition;
	///最小成交量
	CVolumeType	MinVolume;
	///触发条件
	CContingentConditionType	ContingentCondition;
	///止损价
	CPriceType	StopPrice;
	///强平原因
	CForceCloseReasonType	ForceCloseReason;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///自动挂起标志
	CBoolType	IsAutoSuspend;
	///报单来源
	COrderSourceType	OrderSource;
	///报单状态
	COrderStatusType	OrderStatus;
	///报单类型
	COrderTypeType	OrderType;
	///今成交数量
	CVolumeType	VolumeTraded;
	///剩余数量
	CVolumeType	VolumeTotal;
	///报单日期
	CDateType	InsertDate;
	///插入时间
	CTimeType	InsertTime;
	///激活时间
	CTimeType	ActiveTime;
	///挂起时间
	CTimeType	SuspendTime;
	///最后修改时间
	CTimeType	UpdateTime;
	///撤销时间
	CTimeType	CancelTime;
	///最后修改交易用户代码
	CUserIDType	ActiveUserID;
	///优先权
	CPriorityType	Priority;
	///按时间排队的序号
	CTimeSortIDType	TimeSortID;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	CDateType	ActionDay;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OrderPriceType)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(CombOffsetFlag)
		,
		TYPE_DESC(CombHedgeFlag)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(GTDDate)
		,
		TYPE_DESC(VolumeCondition)
		,
		TYPE_DESC(MinVolume)
		,
		TYPE_DESC(ContingentCondition)
		,
		TYPE_DESC(StopPrice)
		,
		TYPE_DESC(ForceCloseReason)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(IsAutoSuspend)
		,
		TYPE_DESC(OrderSource)
		,
		TYPE_DESC(OrderStatus)
		,
		TYPE_DESC(OrderType)
		,
		TYPE_DESC(VolumeTraded)
		,
		TYPE_DESC(VolumeTotal)
		,
		TYPE_DESC(InsertDate)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(ActiveTime)
		,
		TYPE_DESC(SuspendTime)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(CancelTime)
		,
		TYPE_DESC(ActiveUserID)
		,
		TYPE_DESC(Priority)
		,
		TYPE_DESC(TimeSortID)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(ActionDay)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_Order=0x2508;

///执行宣告
class CFTDExecOrderField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///合约编号
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///本地执行宣告编号
	COrderLocalIDType	ExecOrderLocalID;
	///数量
	CVolumeType	Volume;
	///开平标志
	COffsetFlagType	OffsetFlag;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///持仓方向
	CPosiDirectionType	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	CExecOrderPositionFlagType	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	CExecOrderCloseFlagType	CloseFlag;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///执行宣告编号
	CExecOrderSysIDType	ExecOrderSysID;
	///报单日期
	CDateType	InsertDate;
	///插入时间
	CTimeType	InsertTime;
	///撤销时间
	CTimeType	CancelTime;
	///执行结果
	CExecResultType	ExecResult;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	CDateType	ActionDay;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ExecOrderLocalID)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(ReservePositionFlag)
		,
		TYPE_DESC(CloseFlag)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(ExecOrderSysID)
		,
		TYPE_DESC(InsertDate)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(CancelTime)
		,
		TYPE_DESC(ExecResult)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(ActionDay)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_ExecOrder=0x2509;

///非标组合报单
class CFTDCombOrderField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///组合报单编号
	COrderSysIDType	CombOrderSysID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易用户代码
	CUserIDType	UserID;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///本地报单编号
	COrderLocalIDType	CombOrderLocalID;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///合约代码1
	CInstrumentIDType	InstrumentID1;
	///买卖方向1
	CDirectionType	Direction1;
	///分腿乘数1
	CLegMultipleType	LegMultiple1;
	///开平标志1
	COffsetFlagType	OffsetFlag1;
	///投机套保标志1
	CHedgeFlagType	HedgeFlag1;
	///合约代码2
	CInstrumentIDType	InstrumentID2;
	///买卖方向2
	CDirectionType	Direction2;
	///分腿乘数2
	CLegMultipleType	LegMultiple2;
	///开平标志2
	COffsetFlagType	OffsetFlag2;
	///投机套保标志2
	CHedgeFlagType	HedgeFlag2;
	///合约代码3
	CInstrumentIDType	InstrumentID3;
	///买卖方向3
	CDirectionType	Direction3;
	///分腿乘数3
	CLegMultipleType	LegMultiple3;
	///开平标志3
	COffsetFlagType	OffsetFlag3;
	///投机套保标志3
	CHedgeFlagType	HedgeFlag3;
	///合约代码4
	CInstrumentIDType	InstrumentID4;
	///买卖方向4
	CDirectionType	Direction4;
	///分腿乘数4
	CLegMultipleType	LegMultiple4;
	///开平标志4
	COffsetFlagType	OffsetFlag4;
	///投机套保标志4
	CHedgeFlagType	HedgeFlag4;
	///报单来源
	COrderSourceType	OrderSource;
	///今成交数量
	CVolumeType	VolumeTraded;
	///剩余数量
	CVolumeType	VolumeTotal;
	///报单日期
	CDateType	InsertDate;
	///插入时间
	CTimeType	InsertTime;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///本地业务标识
	CBusinessLocalIDType	BusinessLocalID;
	///业务发生日期
	CDateType	ActionDay;
	///IP地址
	CIPAddressType	IPAddress;
	///Mac地址
	CMacAddressType	MacAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(CombOrderSysID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(CombOrderLocalID)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(InstrumentID1)
		,
		TYPE_DESC(Direction1)
		,
		TYPE_DESC(LegMultiple1)
		,
		TYPE_DESC(OffsetFlag1)
		,
		TYPE_DESC(HedgeFlag1)
		,
		TYPE_DESC(InstrumentID2)
		,
		TYPE_DESC(Direction2)
		,
		TYPE_DESC(LegMultiple2)
		,
		TYPE_DESC(OffsetFlag2)
		,
		TYPE_DESC(HedgeFlag2)
		,
		TYPE_DESC(InstrumentID3)
		,
		TYPE_DESC(Direction3)
		,
		TYPE_DESC(LegMultiple3)
		,
		TYPE_DESC(OffsetFlag3)
		,
		TYPE_DESC(HedgeFlag3)
		,
		TYPE_DESC(InstrumentID4)
		,
		TYPE_DESC(Direction4)
		,
		TYPE_DESC(LegMultiple4)
		,
		TYPE_DESC(OffsetFlag4)
		,
		TYPE_DESC(HedgeFlag4)
		,
		TYPE_DESC(OrderSource)
		,
		TYPE_DESC(VolumeTraded)
		,
		TYPE_DESC(VolumeTotal)
		,
		TYPE_DESC(InsertDate)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(BusinessLocalID)
		,
		TYPE_DESC(ActionDay)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MacAddress)
	));
};
const DWORD FTD_FID_CombOrder=0x250A;

///管理报单
class CFTDAdminOrderField
{
public:
	///合约代码
	CInstrumentIDType	InstrumentID;
	///管理报单命令
	CAdminOrderCommandFlagType	AdminOrderCommand;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///交易会员编号
	CParticipantIDType	ParticipantID;
	///金额
	CMoneyType	Amount;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(AdminOrderCommand)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(Amount)
		,
		TYPE_DESC(SettlementGroupID)
	));
};
const DWORD FTD_FID_AdminOrder=0x2510;

///管理报单输入
class CFTDInputAdminOrderField
{
public:
	///合约代码
	CInstrumentIDType	InstrumentID;
	///管理报单命令
	CAdminOrderCommandFlagType	AdminOrderCommand;
	///结算会员编号
	CParticipantIDType	ClearingPartID;
	///交易会员编号
	CParticipantIDType	ParticipantID;
	///金额
	CMoneyType	Amount;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(AdminOrderCommand)
		,
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(Amount)
		,
		TYPE_DESC(SettlementGroupID)
	));
};
const DWORD FTD_FID_InputAdminOrder=0x2511;

///公告
class CFTDBulletinField
{
public:
	///交易日
	CDateType	TradingDay;
	///公告编号
	CBulletinIDType	BulletinID;
	///序列号
	CSequenceNoType	SequenceNo;
	///公告类型
	CNewsTypeType	NewsType;
	///紧急程度
	CNewsUrgencyType	NewsUrgency;
	///发送时间
	CTimeType	SendTime;
	///消息摘要
	CAbstractType	Abstract;
	///消息来源
	CComeFromType	ComeFrom;
	///消息正文
	CContentType	Content;
	///WEB地址
	CURLLinkType	URLLink;
	///市场代码
	CMarketIDType	MarketID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(BulletinID)
		,
		TYPE_DESC(SequenceNo)
		,
		TYPE_DESC(NewsType)
		,
		TYPE_DESC(NewsUrgency)
		,
		TYPE_DESC(SendTime)
		,
		TYPE_DESC(Abstract)
		,
		TYPE_DESC(ComeFrom)
		,
		TYPE_DESC(Content)
		,
		TYPE_DESC(URLLink)
		,
		TYPE_DESC(MarketID)
	));
};
const DWORD FTD_FID_Bulletin=0x2607;

///交易所数据同步状态
class CFTDExchangeDataSyncStatusField
{
public:
	///交易日
	CDateType	TradingDay;
	///交易所代码
	CExchangeIDType	ExchangeID;
	///交易所数据同步状态
	CExchangeDataSyncStatusType	ExchangeDataSyncStatus;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ExchangeDataSyncStatus)
	));
};
const DWORD FTD_FID_ExchangeDataSyncStatus=0x2701;

///结算组数据同步状态
class CFTDSGDataSyncStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///交易日
	CDateType	TradingDay;
	///结算编号
	CSettlementIDType	SettlementID;
	///结算组数据同步状态
	CSGDataSyncStatusType	SGDataSyncStatus;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(SGDataSyncStatus)
	));
};
const DWORD FTD_FID_SGDataSyncStatus=0x2702;

///合约状态
class CFTDInstrumentStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	CTimeType	EnterTime;
	///进入本状态原因
	CInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	CDateType	EnterDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(EnterTime)
		,
		TYPE_DESC(EnterReason)
		,
		TYPE_DESC(EnterDate)
	));
};
const DWORD FTD_FID_InstrumentStatus=0x2703;

///客户持仓查询
class CFTDQryClientPositionV1Field
{
public:
	///起始会员代码
	CParticipantIDType	PartIDStart;
	///结束会员代码
	CParticipantIDType	PartIDEnd;
	///起始客户代码
	CClientIDType	ClientIDStart;
	///结束客户代码
	CClientIDType	ClientIDEnd;
	///起始合约代码
	CInstrumentIDType	InstIDStart;
	///结束合约代码
	CInstrumentIDType	InstIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
		,
		TYPE_DESC(ClientIDStart)
		,
		TYPE_DESC(ClientIDEnd)
		,
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
	));
};
const DWORD FTD_FID_QryClientPositionV1=0x3008;

///用户流控参数
class CFTDUserCommFluxControlField
{
public:
	///最大交易报文速度
	CCommFluxType	MaxTradeCommFlux;
	///最大交易在途报文数目
	CCommFluxType	MaxTradeOnWayCommFlux;
	///最大查询报文速度
	CCommFluxType	MaxQueryCommFlux;
	///最大查询在途报文数目
	CCommFluxType	MaxQueryOnWayCommFlux;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MaxTradeCommFlux)
		,
		TYPE_DESC(MaxTradeOnWayCommFlux)
		,
		TYPE_DESC(MaxQueryCommFlux)
		,
		TYPE_DESC(MaxQueryOnWayCommFlux)
	));
};
const DWORD FTD_FID_UserCommFluxControl=0x3202;

///回路度量
class CFTDLoopMeasureField
{
public:
	///用户编号
	CUserIDType	UserID;
	///会话类型
	CSessionTypeType	SessionType;
	///度量序列号
	CSequenceNoType	MeasureSeq;
	///前置编号
	CFrontIDType	FrontID;
	///会话编号
	CSessionIDType	SessionID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(SessionType)
		,
		TYPE_DESC(MeasureSeq)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(SessionID)
	));
};
const DWORD FTD_FID_LoopMeasure=0x8002;

///节点度量
class CFTDNodeMeasureField
{
public:
	///节点标记 
	CBusinessUnitType	NodeID;
	///阶段编号
	CPeriodIDType	PeriodID;
	///回路报文度量时间点
	CMeasureSecType	Sec;
	///回路报文度量时间点微秒值
	CMeasureUsecType	Usec;
	TYPE_DESCRIPTOR((
		TYPE_DESC(NodeID)
		,
		TYPE_DESC(PeriodID)
		,
		TYPE_DESC(Sec)
		,
		TYPE_DESC(Usec)
	));
};
const DWORD FTD_FID_NodeMeasure=0x8003;

///行情代理信息
class CFTDMDProxyField
{
public:
	///代理编号
	CFrontIDType	ProxyID;
	///上一层代理会话编号
	CSessionIDType	UpperProxySessionID;
	///代理会话编号
	CSessionIDType	CurrProxySessionID;
	///IP地址
	CIPAddressType	IPAddress;
	///请求编号
	CSequenceNoType	RequestID;
	///代理深度
	CDepthType	Depth;
	///连接状态
	CSessionStatusType	SessionStatus;
	///删除的会话编号
	CSessionIDType	DeletedSessionID;
	///最大通讯量
	CCommFluxType	MaxCommFlux;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ProxyID)
		,
		TYPE_DESC(UpperProxySessionID)
		,
		TYPE_DESC(CurrProxySessionID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(RequestID)
		,
		TYPE_DESC(Depth)
		,
		TYPE_DESC(SessionStatus)
		,
		TYPE_DESC(DeletedSessionID)
		,
		TYPE_DESC(MaxCommFlux)
	));
};
const DWORD FTD_FID_MDProxy=0x8004;

///CPU资源使用查询
class CFTDReqQryTopCpuInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CTypeCPUIdType	CPU;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryTopCpuInfo=0x5001;

///CPU资源使用信息
class CFTDRspQryTopCpuInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///CPU的编号
	CTypeCPUIdType	CPU;
	///
	CRatioType	LOAD;
	///
	CRatioType	USER;
	///
	CRatioType	NICE;
	///
	CRatioType	SYS;
	///
	CRatioType	IDLE;
	///
	CRatioType	BLOCK;
	///
	CRatioType	SWAIT;
	///
	CRatioType	INTR;
	///
	CRatioType	SSYS;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(LOAD)
		,
		TYPE_DESC(USER)
		,
		TYPE_DESC(NICE)
		,
		TYPE_DESC(SYS)
		,
		TYPE_DESC(IDLE)
		,
		TYPE_DESC(BLOCK)
		,
		TYPE_DESC(SWAIT)
		,
		TYPE_DESC(INTR)
		,
		TYPE_DESC(SSYS)
	));
};
const DWORD FTD_FID_RspQryTopCpuInfo=0x5002;

///CPU资源使用信息
class CFTDRtnTopCpuInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///CPU的编号
	CTypeCPUIdType	CPU;
	///
	CRatioType	LOAD;
	///
	CRatioType	USER;
	///
	CRatioType	NICE;
	///
	CRatioType	SYS;
	///
	CRatioType	IDLE;
	///
	CRatioType	BLOCK;
	///
	CRatioType	SWAIT;
	///
	CRatioType	INTR;
	///
	CRatioType	SSYS;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(LOAD)
		,
		TYPE_DESC(USER)
		,
		TYPE_DESC(NICE)
		,
		TYPE_DESC(SYS)
		,
		TYPE_DESC(IDLE)
		,
		TYPE_DESC(BLOCK)
		,
		TYPE_DESC(SWAIT)
		,
		TYPE_DESC(INTR)
		,
		TYPE_DESC(SSYS)
	));
};
const DWORD FTD_FID_RtnTopCpuInfo=0x5003;

///Mem资源使用查询
class CFTDReqQryTopMemInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryTopMemInfo=0x5004;

///Mem资源使用信息
class CFTDRspQryTopMemInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///Total Real Memory
	CVolumeType	TOTALREAL;
	///Active Real Memory
	CVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	CVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	CVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	CVolumeType	FREE;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(TOTALREAL)
		,
		TYPE_DESC(ACTIVEREAL)
		,
		TYPE_DESC(TOTALVIRTUAL)
		,
		TYPE_DESC(ACTIVEVIRTUAL)
		,
		TYPE_DESC(FREE)
	));
};
const DWORD FTD_FID_RspQryTopMemInfo=0x5005;

///Mem资源使用信息
class CFTDRtnTopMemInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///Total Real Memory
	CVolumeType	TOTALREAL;
	///Active Real Memory
	CVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	CVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	CVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	CVolumeType	FREE;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(TOTALREAL)
		,
		TYPE_DESC(ACTIVEREAL)
		,
		TYPE_DESC(TOTALVIRTUAL)
		,
		TYPE_DESC(ACTIVEVIRTUAL)
		,
		TYPE_DESC(FREE)
	));
};
const DWORD FTD_FID_RtnTopMemInfo=0x5006;

///process资源使用查询
class CFTDReqQryTopProcessInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryTopProcessInfo=0x5007;

///process资源使用信息
class CFTDRspQryTopProcessInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///处理器号
	CTypeCPUIdType	CPU;
	///终端名
	CTypeChar10Type	TTY;
	///进程号
	CVolumeType	PID;
	///用户名
	CTypeChar10Type	USERNAME;
	///任务的优先级
	CVolumeType	PRI;
	///任务的nice值
	CVolumeType	NI;
	///任务的代码加上数据再加上栈空间的大小
	CVolumeType	SIZE;
	///任务使用的物理内存的总数量
	CVolumeType	RES;
	///任务的状态
	CTypeChar10Type	STATE;
	///自任务开始时使用的总CPU时间
	CTimeType	TIME;
	///进程的CPU利用率权重百分比
	CRatioType	pWCPU;
	///进程的原始的CPU利用率百分比
	CRatioType	pCPU;
	///启动进程的命令名
	CTypeCommandType	COMMAND;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(TTY)
		,
		TYPE_DESC(PID)
		,
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(PRI)
		,
		TYPE_DESC(NI)
		,
		TYPE_DESC(SIZE)
		,
		TYPE_DESC(RES)
		,
		TYPE_DESC(STATE)
		,
		TYPE_DESC(TIME)
		,
		TYPE_DESC(pWCPU)
		,
		TYPE_DESC(pCPU)
		,
		TYPE_DESC(COMMAND)
	));
};
const DWORD FTD_FID_RspQryTopProcessInfo=0x5008;

///process资源使用信息
class CFTDRtnTopProcessInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///处理器号
	CTypeCPUIdType	CPU;
	///终端名
	CTypeChar10Type	TTY;
	///进程号
	CVolumeType	PID;
	///用户名
	CTypeChar10Type	USERNAME;
	///任务的优先级
	CVolumeType	PRI;
	///任务的nice值
	CVolumeType	NI;
	///任务的代码加上数据再加上栈空间的大小
	CVolumeType	SIZE;
	///任务使用的物理内存的总数量
	CVolumeType	RES;
	///任务的状态
	CTypeChar10Type	STATE;
	///自任务开始时使用的总CPU时间
	CTimeType	TIME;
	///进程的CPU利用率权重百分比
	CRatioType	pWCPU;
	///进程的原始的CPU利用率百分比
	CRatioType	pCPU;
	///启动进程的命令名
	CTypeCommandType	COMMAND;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(TTY)
		,
		TYPE_DESC(PID)
		,
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(PRI)
		,
		TYPE_DESC(NI)
		,
		TYPE_DESC(SIZE)
		,
		TYPE_DESC(RES)
		,
		TYPE_DESC(STATE)
		,
		TYPE_DESC(TIME)
		,
		TYPE_DESC(pWCPU)
		,
		TYPE_DESC(pCPU)
		,
		TYPE_DESC(COMMAND)
	));
};
const DWORD FTD_FID_RtnTopProcessInfo=0x5009;

///filesystem资源使用查询
class CFTDReqQryFileSystemInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryFileSystemInfo=0x500A;

///filesystem资源使用信息
class CFTDRspQryFileSystemInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///文件系统物理名
	CTypeCommandType	FILESYSTEM;
	///空间总数
	CVolumeType	SIZE;
	///已用空间大小
	CVolumeType	USED;
	///可用空间大小
	CVolumeType	AVAIL;
	///已用的百分比
	CRatioType	pUSERD;
	///inode总数
	CVolumeType	ISIZE;
	///已用inode大小
	CVolumeType	IUSED;
	///可用inode大小
	CVolumeType	IFREE;
	///已用的百分比
	CRatioType	pIUSED;
	///加载位置
	CTypeCommandType	MountedOn;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(FILESYSTEM)
		,
		TYPE_DESC(SIZE)
		,
		TYPE_DESC(USED)
		,
		TYPE_DESC(AVAIL)
		,
		TYPE_DESC(pUSERD)
		,
		TYPE_DESC(ISIZE)
		,
		TYPE_DESC(IUSED)
		,
		TYPE_DESC(IFREE)
		,
		TYPE_DESC(pIUSED)
		,
		TYPE_DESC(MountedOn)
	));
};
const DWORD FTD_FID_RspQryFileSystemInfo=0x500B;

///filesystem资源使用信息
class CFTDRtnFileSystemInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///文件系统物理名
	CTypeCommandType	FILESYSTEM;
	///空间总数
	CVolumeType	SIZE;
	///已用空间大小
	CVolumeType	USED;
	///可用空间大小
	CVolumeType	AVAIL;
	///已用的百分比
	CRatioType	pUSERD;
	///inode总数
	CVolumeType	ISIZE;
	///已用inode大小
	CVolumeType	IUSED;
	///可用inode大小
	CVolumeType	IFREE;
	///已用的百分比
	CRatioType	pIUSED;
	///加载位置
	CTypeCommandType	MountedOn;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(FILESYSTEM)
		,
		TYPE_DESC(SIZE)
		,
		TYPE_DESC(USED)
		,
		TYPE_DESC(AVAIL)
		,
		TYPE_DESC(pUSERD)
		,
		TYPE_DESC(ISIZE)
		,
		TYPE_DESC(IUSED)
		,
		TYPE_DESC(IFREE)
		,
		TYPE_DESC(pIUSED)
		,
		TYPE_DESC(MountedOn)
	));
};
const DWORD FTD_FID_RtnFileSystemInfo=0x500C;

///network资源使用查询
class CFTDReqQryNetworkInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///网卡名
	CTypeLanNameType	LANNAME;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(LANNAME)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryNetworkInfo=0x500D;

///network资源使用信息
class CFTDRspQryNetworkInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///网卡名
	CTypeLanNameType	LANNAME;
	///网卡的up或down状态
	CTypeLanStatusType	LANSTATUS;
	///网卡的ip地址
	CIPAddressType	IPADDRESS;
	///网卡接收的流量
	CLargeNumberType	RECVBYTES;
	///网卡接收的数据包
	CLargeNumberType	RECVPACKETS;
	///网卡接收端错误数据包
	CLargeNumberType	RECVERRORPACKETS;
	///网卡接收端丢失数据包
	CLargeNumberType	RECVDROPPACKETS;
	///网卡发送的流量
	CLargeNumberType	SENDBYTES;
	///网卡发送的数据包
	CLargeNumberType	SENDPACKETS;
	///网卡发送端错误数据包
	CLargeNumberType	SENDERRORPACKETS;
	///网卡发送端丢失数据包
	CLargeNumberType	SENDDROPPACKETS;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(LANNAME)
		,
		TYPE_DESC(LANSTATUS)
		,
		TYPE_DESC(IPADDRESS)
		,
		TYPE_DESC(RECVBYTES)
		,
		TYPE_DESC(RECVPACKETS)
		,
		TYPE_DESC(RECVERRORPACKETS)
		,
		TYPE_DESC(RECVDROPPACKETS)
		,
		TYPE_DESC(SENDBYTES)
		,
		TYPE_DESC(SENDPACKETS)
		,
		TYPE_DESC(SENDERRORPACKETS)
		,
		TYPE_DESC(SENDDROPPACKETS)
	));
};
const DWORD FTD_FID_RspQryNetworkInfo=0x500E;

///network资源使用信息
class CFTDRtnNetworkInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///网卡名
	CTypeLanNameType	LANNAME;
	///网卡的up或down状态
	CTypeLanStatusType	LANSTATUS;
	///网卡的ip地址
	CIPAddressType	IPADDRESS;
	///网卡接收的流量
	CLargeNumberType	RECVBYTES;
	///网卡接收的数据包
	CLargeNumberType	RECVPACKETS;
	///网卡接收端错误数据包
	CLargeNumberType	RECVERRORPACKETS;
	///网卡接收端丢失数据包
	CLargeNumberType	RECVDROPPACKETS;
	///网卡发送的流量
	CLargeNumberType	SENDBYTES;
	///网卡发送的数据包
	CLargeNumberType	SENDPACKETS;
	///网卡发送端错误数据包
	CLargeNumberType	SENDERRORPACKETS;
	///网卡发送端丢失数据包
	CLargeNumberType	SENDDROPPACKETS;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(LANNAME)
		,
		TYPE_DESC(LANSTATUS)
		,
		TYPE_DESC(IPADDRESS)
		,
		TYPE_DESC(RECVBYTES)
		,
		TYPE_DESC(RECVPACKETS)
		,
		TYPE_DESC(RECVERRORPACKETS)
		,
		TYPE_DESC(RECVDROPPACKETS)
		,
		TYPE_DESC(SENDBYTES)
		,
		TYPE_DESC(SENDPACKETS)
		,
		TYPE_DESC(SENDERRORPACKETS)
		,
		TYPE_DESC(SENDDROPPACKETS)
	));
};
const DWORD FTD_FID_RtnNetworkInfo=0x500F;

///主机环境信息查询请求
class CFTDReqQryHostEnvField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryHostEnv=0x5022;

///主机环境信息应答信息
class CFTDRspQryHostEnvCommonField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///主机型号
	CTypeHostModelType	HostModel;
	///内存大小(K)
	CVolumeType	MainMemory;
	///CPU厂商
	CTypeHostModelType	CPUVendor;
	///CPU型号
	CTypeHostModelType	CPUModel;
	///CPU主频
	CTypeHostModelType	CPUMHz;
	///CPU缓存
	CTypeHostModelType	CPUCache;
	///CPU内核数
	CVolumeType	CPUCores;
	///CPU个数
	CVolumeType	Processors;
	///32位还是64位操作系统
	CVolumeType	OsMode;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(HostModel)
		,
		TYPE_DESC(MainMemory)
		,
		TYPE_DESC(CPUVendor)
		,
		TYPE_DESC(CPUModel)
		,
		TYPE_DESC(CPUMHz)
		,
		TYPE_DESC(CPUCache)
		,
		TYPE_DESC(CPUCores)
		,
		TYPE_DESC(Processors)
		,
		TYPE_DESC(OsMode)
	));
};
const DWORD FTD_FID_RspQryHostEnvCommon=0x5023;

///主机环境信息应答信息
class CFTDRspQryHostEnvLanField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///LanID
	CTypeHostModelType	LanHardwareID;
	///Mac地址
	CTypeHostModelType	LanHardwareValue;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(LanHardwareID)
		,
		TYPE_DESC(LanHardwareValue)
	));
};
const DWORD FTD_FID_RspQryHostEnvLan=0x5024;

///主机环境信息应答信息
class CFTDRspQryHostEnvStorageField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///Storage Devices
	CTypeHostModelType	StorageDev;
	///HW Path
	CTypeHostModelType	HWPath;
	///Interface
	CTypeHostModelType	Interface;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(StorageDev)
		,
		TYPE_DESC(HWPath)
		,
		TYPE_DESC(Interface)
	));
};
const DWORD FTD_FID_RspQryHostEnvStorage=0x5025;

///主机环境信息应答信息
class CFTDRspQryHostEnvIOField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///IO Class
	CTypeChar10Type	IoClass;
	///H/W Path
	CTypeChar10Type	H_WPath;
	///Driver
	CTypeChar10Type	IoDriver;
	///Description
	CTypeDescriptionType	IoDescription;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(IoClass)
		,
		TYPE_DESC(H_WPath)
		,
		TYPE_DESC(IoDriver)
		,
		TYPE_DESC(IoDescription)
	));
};
const DWORD FTD_FID_RspQryHostEnvIO=0x5026;

///主机环境信息应答信息
class CFTDRspQryHostEnvFSField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///LVM Device file
	CTypeHostModelType	LVMDeviceFile;
	///mount point
	CTypeCommandType	MountPoint;
	///size
	CVolumeType	FSsize;
	///fs type
	CTypeChar10Type	FSType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(LVMDeviceFile)
		,
		TYPE_DESC(MountPoint)
		,
		TYPE_DESC(FSsize)
		,
		TYPE_DESC(FSType)
	));
};
const DWORD FTD_FID_RspQryHostEnvFS=0x5027;

///主机环境信息应答信息
class CFTDRspQryHostEnvSwapField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///type
	CTypeChar10Type	type;
	///size
	CVolumeType	size;
	///priority
	CVolumeType	priority;
	///device location
	CTypeHostModelType	location;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(type)
		,
		TYPE_DESC(size)
		,
		TYPE_DESC(priority)
		,
		TYPE_DESC(location)
	));
};
const DWORD FTD_FID_RspQryHostEnvSwap=0x5028;

///主机环境信息应答信息
class CFTDRspQryHostEnvLanCfgField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///
	CTypeLanNameType	LanName;
	///
	CIPAddressType	IpAddress;
	///
	CIPAddressType	IpMask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(LanName)
		,
		TYPE_DESC(IpAddress)
		,
		TYPE_DESC(IpMask)
	));
};
const DWORD FTD_FID_RspQryHostEnvLanCfg=0x5029;

///客户端登录查询请求
class CFTDReqQryClientLoginField
{
public:
	///登录用户名
	CTypeUserNameType	UserName;
	///登录密码
	CTypeUserNameType	PassWord;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserName)
		,
		TYPE_DESC(PassWord)
	));
};
const DWORD FTD_FID_ReqQryClientLogin=0x502A;

///客户端登录应答信息
class CFTDRspQryClientLoginField
{
public:
	///登录用户名
	CTypeUserNameType	UserName;
	///登录权限
	CTypeUserNameType	Privalage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserName)
		,
		TYPE_DESC(Privalage)
	));
};
const DWORD FTD_FID_RspQryClientLogin=0x502B;

///获得监控对象信息查询请求
class CFTDReqQryMonitorObjectField
{
public:
	///业务进程对象ID
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryMonitorObject=0x502C;

///获得监控对象信息应答信息
class CFTDRspQryMonitorObjectField
{
public:
	///业务进程对象ID
	CTypeObjectIDType	ObjectID;
	///本级业务进程对象名字
	CTypeLongObjectNameType	ObjectName;
	///告警事件产生标志位
	CTypeIsActiveType	WarningActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(ObjectName)
		,
		TYPE_DESC(WarningActive)
	));
};
const DWORD FTD_FID_RspQryMonitorObject=0x502D;

///获得监控对象信息应答信息
class CFTDRtnMonitorObjectField
{
public:
	///业务进程对象ID
	CTypeObjectIDType	ObjectID;
	///本级业务进程对象名字
	CTypeLongObjectNameType	ObjectName;
	///告警事件产生标志位
	CTypeIsActiveType	WarningActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(ObjectName)
		,
		TYPE_DESC(WarningActive)
	));
};
const DWORD FTD_FID_RtnMonitorObject=0x502E;

///获得业务进程和主机的对应关系查询请求
class CFTDReqQryObjectRationalField
{
public:
	///业务进程对象ID
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryObjectRational=0x502F;

///获得业务进程和主机的对应关系应答信息
class CFTDRspQryObjectRationalField
{
public:
	///业务进程对象ID
	CTypeObjectIDType	ObjectID;
	///业务进程所在的主机ID
	CTypeObjectIDType	HostObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HostObjectID)
	));
};
const DWORD FTD_FID_RspQryObjectRational=0x5030;

///获得业务进程和主机的对应关系应答信息
class CFTDRtnObjectRationalField
{
public:
	///业务进程对象ID
	CTypeObjectIDType	ObjectID;
	///业务进程所在的主机ID
	CTypeObjectIDType	HostObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HostObjectID)
	));
};
const DWORD FTD_FID_RtnObjectRational=0x5031;

///日志文件内容查询请求
class CFTDReqQrySyslogInfoField
{
public:
	///请求文件路径
	CTypeObjectIDType	FileName;
	///文件名
	CTypeObjectIDType	subFileName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FileName)
		,
		TYPE_DESC(subFileName)
	));
};
const DWORD FTD_FID_ReqQrySyslogInfo=0x5038;

///日志文件内容应答信息
class CFTDRspQrySyslogInfoField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///监控指标类型
	CAttrTypeType	AttrType;
	///文件内容长度
	CTypeContLenType	ContLen;
	///文件内容
	CTypeFileContentType	FileContent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(ContLen)
		,
		TYPE_DESC(FileContent)
	));
};
const DWORD FTD_FID_RspQrySyslogInfo=0x5039;

///日志文件内容应答信息
class CFTDRtnSyslogInfoField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///监控指标类型
	CAttrTypeType	AttrType;
	///文件内容长度
	CTypeContLenType	ContLen;
	///文件内容
	CTypeFileContentType	FileContent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(ContLen)
		,
		TYPE_DESC(FileContent)
	));
};
const DWORD FTD_FID_RtnSyslogInfo=0x503A;

///监控内容订阅请求
class CFTDReqQrySubscriberField
{
public:
	///订阅对象名
	CTypeSubcriberObjectIDType	ObjectID;
	///初次返回对象数
	CVolumeType	ObjectNum;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	///返回的初始日期
	CDateType	MonDate;
	///返回的初始时间
	CTimeType	MonTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(ObjectNum)
		,
		TYPE_DESC(KeepAlive)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
	));
};
const DWORD FTD_FID_ReqQrySubscriber=0x503B;

///监控内容订阅应答信息
class CFTDRspQrySubscriberField
{
public:
	///错误代码
	CErrorIDType	ErrorID;
	///错误信息
	CErrorMsgType	ErrorMsg;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
		,
		TYPE_DESC(ObjectID)
	));
};
const DWORD FTD_FID_RspQrySubscriber=0x503C;

///监控内容订阅应答信息
class CFTDRtnSubscriberField
{
public:
	///错误代码
	CErrorIDType	ErrorID;
	///错误信息
	CErrorMsgType	ErrorMsg;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
		,
		TYPE_DESC(ObjectID)
	));
};
const DWORD FTD_FID_RtnSubscriber=0x503D;

///对象关系查询请求
class CFTDReqQryOidRelationField
{
public:
	///
	CTypeObjectIDType	ObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
	));
};
const DWORD FTD_FID_ReqQryOidRelation=0x5196;

///对象关系查询应答信息
class CFTDRspQryOidRelationField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///定义对象名
	CTypeObjectIDType	HoldObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HoldObjectID)
	));
};
const DWORD FTD_FID_RspQryOidRelation=0x5197;

///对象关系查询应答信息
class CFTDRtnOidRelationField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///定义对象名
	CTypeObjectIDType	HoldObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HoldObjectID)
	));
};
const DWORD FTD_FID_RtnOidRelation=0x5198;

///用户信息查询请求
class CFTDReqQryUserInfoField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryUserInfo=0x5202;

///用户信息查询应答信息
class CFTDRspQryUserInfoField
{
public:
	///用户名
	CTypeUserNameType	USERNAME;
	///用户ID
	CVolumeType	USERID;
	///用户组名
	CTypeUserNameType	GROUPNAME;
	///用户组ID
	CVolumeType	GROUPID;
	///HOME路径
	CTypeUserNameType	HOMEPATH;
	///用户使用SHELL环境
	CTypeUserNameType	SHELL;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的时间
	CTimeType	MonTime;
	///采集的日期
	CDateType	MonDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(USERID)
		,
		TYPE_DESC(GROUPNAME)
		,
		TYPE_DESC(GROUPID)
		,
		TYPE_DESC(HOMEPATH)
		,
		TYPE_DESC(SHELL)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(MonDate)
	));
};
const DWORD FTD_FID_RspQryUserInfo=0x5203;

///用户信息查询应答信息
class CFTDRtnUserInfoField
{
public:
	///用户名
	CTypeUserNameType	USERNAME;
	///用户ID
	CVolumeType	USERID;
	///用户组名
	CTypeUserNameType	GROUPNAME;
	///用户组ID
	CVolumeType	GROUPID;
	///HOME路径
	CTypeUserNameType	HOMEPATH;
	///用户使用SHELL环境
	CTypeUserNameType	SHELL;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的时间
	CTimeType	MonTime;
	///采集的日期
	CDateType	MonDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(USERID)
		,
		TYPE_DESC(GROUPNAME)
		,
		TYPE_DESC(GROUPID)
		,
		TYPE_DESC(HOMEPATH)
		,
		TYPE_DESC(SHELL)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(MonDate)
	));
};
const DWORD FTD_FID_RtnUserInfo=0x5204;

///在线用户信息查询请求
class CFTDReqQryOnlineUserInfoField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryOnlineUserInfo=0x5205;

///在线用户信息应答信息
class CFTDRspQryOnlineUserInfoField
{
public:
	///用户名
	CTypeUserNameType	USERNAME;
	///登录时间
	CTypeUserNameType	TIME;
	///终端类型
	CTypeUserNameType	TTY;
	///IP地址
	CTypeUserNameType	IP;
	///连接时间
	CTypeUserNameType	CONNECTIME;
	///进程ID
	CVolumeType	PID;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的时间
	CTimeType	MonTime;
	///采集的日期
	CDateType	MonDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(TIME)
		,
		TYPE_DESC(TTY)
		,
		TYPE_DESC(IP)
		,
		TYPE_DESC(CONNECTIME)
		,
		TYPE_DESC(PID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(MonDate)
	));
};
const DWORD FTD_FID_RspQryOnlineUserInfo=0x5206;

///在线用户信息应答信息
class CFTDRtnOnlineUserInfoField
{
public:
	///用户名
	CTypeUserNameType	USERNAME;
	///登录时间
	CTypeUserNameType	TIME;
	///终端类型
	CTypeUserNameType	TTY;
	///IP地址
	CTypeUserNameType	IP;
	///连接时间
	CTypeUserNameType	CONNECTIME;
	///进程ID
	CVolumeType	PID;
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的时间
	CTimeType	MonTime;
	///采集的日期
	CDateType	MonDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(TIME)
		,
		TYPE_DESC(TTY)
		,
		TYPE_DESC(IP)
		,
		TYPE_DESC(CONNECTIME)
		,
		TYPE_DESC(PID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(MonDate)
	));
};
const DWORD FTD_FID_RtnOnlineUserInfo=0x5207;

///告警事件
class CFTDSysWarningEventField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件发生日期
	CDateType	OccurDate;
	///事件发生时间
	CTimeType	OccurTime;
	///事件ID
	CVolumeType	EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///事件名
	CTypeObjectIDType	EventName;
	///事件标签
	CVolumeType	EventNum;
	///事件类型
	CVolumeType	EventType;
	///事件描述
	CTypeDescriptionType	EventDes;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///事件处理描述
	CTypeObjectIDType	EventDealDes;
	///事件全名
	CNetAttrTypeType	FullEventName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(OccurDate)
		,
		TYPE_DESC(OccurTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(EventNum)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(EventDes)
		,
		TYPE_DESC(ProcessFlag)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(EventDealDes)
		,
		TYPE_DESC(FullEventName)
	));
};
const DWORD FTD_FID_SysWarningEvent=0x5210;

///告警事件查询请求
class CFTDReqQryWarningEventField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///事件类型
	CVolumeType	EventType;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///事件名
	CTypeObjectIDType	EventName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(EventName)
	));
};
const DWORD FTD_FID_ReqQryWarningEvent=0x5211;

///告警事件应答信息
class CFTDRspQryWarningEventField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件发生日期
	CDateType	OccurDate;
	///事件发生时间
	CTimeType	OccurTime;
	///事件ID
	CVolumeType	EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///事件名
	CTypeObjectIDType	EventName;
	///事件标签
	CVolumeType	EventNum;
	///事件类型
	CVolumeType	EventType;
	///事件描述
	CTypeDescriptionType	EventDes;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///事件处理描述
	CTypeObjectIDType	EventDealDes;
	///事件全名
	CNetAttrTypeType	FullEventName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(OccurDate)
		,
		TYPE_DESC(OccurTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(EventNum)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(EventDes)
		,
		TYPE_DESC(ProcessFlag)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(EventDealDes)
		,
		TYPE_DESC(FullEventName)
	));
};
const DWORD FTD_FID_RspQryWarningEvent=0x5212;

///告警事件应答信息
class CFTDRtnWarningEventField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件发生日期
	CDateType	OccurDate;
	///事件发生时间
	CTimeType	OccurTime;
	///事件ID
	CVolumeType	EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///事件名
	CTypeObjectIDType	EventName;
	///事件标签
	CVolumeType	EventNum;
	///事件类型
	CVolumeType	EventType;
	///事件描述
	CTypeDescriptionType	EventDes;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///事件处理描述
	CTypeObjectIDType	EventDealDes;
	///事件全名
	CNetAttrTypeType	FullEventName;
	///事件条数
	CCounterType	EventCount;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(OccurDate)
		,
		TYPE_DESC(OccurTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(EventNum)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(EventDes)
		,
		TYPE_DESC(ProcessFlag)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(EventDealDes)
		,
		TYPE_DESC(FullEventName)
		,
		TYPE_DESC(EventCount)
	));
};
const DWORD FTD_FID_RtnWarningEvent=0x5213;

///KeyFile请求
class CFTDReqQryKeyFileInfoField
{
public:
	///请求文件名ID
	CTypeObjectIDType	FileName;
	///请求文件名路径
	CTypeObjectIDType	PathName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FileName)
		,
		TYPE_DESC(PathName)
	));
};
const DWORD FTD_FID_ReqQryKeyFileInfo=0x5214;

///HostMonitorCfg请求
class CFTDReqQryHostMonitorCfgField
{
public:
	///
	CTypeMonitorTypeType	MonitorType;
	///请求文件名路径
	CTypeObjectIDType	PathName;
	///
	CVolumeType	Interval;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(PathName)
		,
		TYPE_DESC(Interval)
	));
};
const DWORD FTD_FID_ReqQryHostMonitorCfg=0x5215;

///AppMonitorCfg请求
class CFTDReqQryAppMonitorCfgField
{
public:
	///
	CTypeMonitorTypeType	MonitorType;
	///
	CTypePositionType	FSPosition;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(FSPosition)
	));
};
const DWORD FTD_FID_ReqQryAppMonitorCfg=0x5216;

///CPU使用率查询请求
class CFTDReqQryCPUUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryCPUUsage=0x5217;

///CPU使用率应答信息
class CFTDRspQryCPUUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///CPU使用率
	CRatioType	CPUUsage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPUUsage)
	));
};
const DWORD FTD_FID_RspQryCPUUsage=0x5218;

///CPU使用率应答信息
class CFTDRtnCPUUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///CPU使用率
	CRatioType	CPUUsage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPUUsage)
	));
};
const DWORD FTD_FID_RtnCPUUsage=0x5219;

///内存使用率查询请求
class CFTDReqQryMemoryUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryMemoryUsage=0x5220;

///内存使用率应答信息
class CFTDRspQryMemoryUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///内存使用率
	CRatioType	MemoryUsage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(MemoryUsage)
	));
};
const DWORD FTD_FID_RspQryMemoryUsage=0x5221;

///内存使用率应答信息
class CFTDRtnMemoryUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///内存使用率
	CRatioType	MemoryUsage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(MemoryUsage)
	));
};
const DWORD FTD_FID_RtnMemoryUsage=0x5222;

///硬盘使用率查询请求
class CFTDReqQryDiskUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryDiskUsage=0x5223;

///硬盘使用率应答信息
class CFTDRspQryDiskUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///硬盘使用率
	CRatioType	DiskUsage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(DiskUsage)
	));
};
const DWORD FTD_FID_RspQryDiskUsage=0x5224;

///硬盘使用率应答信息
class CFTDRtnDiskUsageField
{
public:
	///定义对象名
	CTypeObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///硬盘使用率
	CRatioType	DiskUsage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(DiskUsage)
	));
};
const DWORD FTD_FID_RtnDiskUsage=0x5225;

///对象状态指标查询
class CFTDReqQryObjectAttrField
{
public:
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryObjectAttr=0x5226;

///对象状态指标查询应答
class CFTDRspQryObjectAttrField
{
public:
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///监控指标的值类型
	CValueTypeType	ValueType;
	///监控指标的具体值
	CAttrValueType	AttrValue;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ValueType)
		,
		TYPE_DESC(AttrValue)
	));
};
const DWORD FTD_FID_RspQryObjectAttr=0x5227;

///对象状态指标查询应答
class CFTDRtnObjectAttrField
{
public:
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///监控指标的值类型
	CValueTypeType	ValueType;
	///监控指标的具体值
	CAttrValueType	AttrValue;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ValueType)
		,
		TYPE_DESC(AttrValue)
	));
};
const DWORD FTD_FID_RtnObjectAttr=0x5228;

///主机配置查询请求
class CFTDReqQryHostConfigField
{
public:
	///
	CCfgTypeType	CfgType;
	///
	CCfgNameType	CfgDataCenter;
	///
	CTypeObjectIDType	CfgName;
	///
	CFilePathNameType	CfgLocation;
	///
	CTypeObjectIDType	CfgHostName;
	///
	CTypeObjectIDType	CfgAttend;
	TYPE_DESCRIPTOR((
		TYPE_DESC(CfgType)
		,
		TYPE_DESC(CfgDataCenter)
		,
		TYPE_DESC(CfgName)
		,
		TYPE_DESC(CfgLocation)
		,
		TYPE_DESC(CfgHostName)
		,
		TYPE_DESC(CfgAttend)
	));
};
const DWORD FTD_FID_ReqQryHostConfig=0x5232;

///无效报单查询
class CFTDReqQryInvalidateOrderField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryInvalidateOrder=0x5300;

///无效报单查询应答
class CFTDRspQryInvalidateOrderField
{
public:
	///报单编号
	COrderSysIDType	OrderSysID;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///插入日期
	CDateType	ActionDate;
	///插入时间
	CTimeType	ActionTime;
	///错误信息
	CErrorMsgType	ErrorMsg;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///客户代码
	CClientIDType	ClientID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///买卖方向
	CDirectionType	Direction;
	///组合开平标志
	CCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType	CombHedgeFlag;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType	TimeCondition;
	///成交量类型
	CVolumeConditionType	VolumeCondition;
	///最小成交量
	CVolumeType	MinVolume;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ErrorMsg)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(CombOffsetFlag)
		,
		TYPE_DESC(CombHedgeFlag)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(VolumeCondition)
		,
		TYPE_DESC(MinVolume)
	));
};
const DWORD FTD_FID_RspQryInvalidateOrder=0x5301;

///无效报单查询应答
class CFTDRtnInvalidateOrderField
{
public:
	///报单编号
	COrderSysIDType	OrderSysID;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///插入日期
	CDateType	ActionDate;
	///插入时间
	CTimeType	ActionTime;
	///错误信息
	CErrorMsgType	ErrorMsg;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///客户代码
	CClientIDType	ClientID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///买卖方向
	CDirectionType	Direction;
	///组合开平标志
	CCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType	CombHedgeFlag;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType	TimeCondition;
	///成交量类型
	CVolumeConditionType	VolumeCondition;
	///最小成交量
	CVolumeType	MinVolume;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ErrorMsg)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(CombOffsetFlag)
		,
		TYPE_DESC(CombHedgeFlag)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(VolumeCondition)
		,
		TYPE_DESC(MinVolume)
	));
};
const DWORD FTD_FID_RtnInvalidateOrder=0x5302;

///报单状态查询
class CFTDReqQryOrderStatusField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryOrderStatus=0x5303;

///报单状态查询应答
class CFTDRspQryOrderStatusField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///报单编号
	COrderSysIDType	OrderSysID;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///报单日期
	CDateType	InsertDate;
	///插入时间
	CTimeType	InsertTime;
	///报单状态
	COrderStatusType	OrderStatus;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///客户代码
	CClientIDType	ClientID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///买卖方向
	CDirectionType	Direction;
	///组合开平标志
	CCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType	CombHedgeFlag;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType	TimeCondition;
	///成交量类型
	CVolumeConditionType	VolumeCondition;
	///最小成交量
	CVolumeType	MinVolume;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(InsertDate)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(OrderStatus)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(CombOffsetFlag)
		,
		TYPE_DESC(CombHedgeFlag)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(VolumeCondition)
		,
		TYPE_DESC(MinVolume)
	));
};
const DWORD FTD_FID_RspQryOrderStatus=0x5304;

///报单状态查询应答
class CFTDRtnOrderStatusField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///报单编号
	COrderSysIDType	OrderSysID;
	///本地报单编号
	COrderLocalIDType	OrderLocalID;
	///报单日期
	CDateType	InsertDate;
	///插入时间
	CTimeType	InsertTime;
	///报单状态
	COrderStatusType	OrderStatus;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///客户代码
	CClientIDType	ClientID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///买卖方向
	CDirectionType	Direction;
	///组合开平标志
	CCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	CCombHedgeFlagType	CombHedgeFlag;
	///价格
	CPriceType	LimitPrice;
	///数量
	CVolumeType	VolumeTotalOriginal;
	///有效期类型
	CTimeConditionType	TimeCondition;
	///成交量类型
	CVolumeConditionType	VolumeCondition;
	///最小成交量
	CVolumeType	MinVolume;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(OrderLocalID)
		,
		TYPE_DESC(InsertDate)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(OrderStatus)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(CombOffsetFlag)
		,
		TYPE_DESC(CombHedgeFlag)
		,
		TYPE_DESC(LimitPrice)
		,
		TYPE_DESC(VolumeTotalOriginal)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(VolumeCondition)
		,
		TYPE_DESC(MinVolume)
	));
};
const DWORD FTD_FID_RtnOrderStatus=0x5305;

///报单成交查询
class CFTDReqQryBargainOrderField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryBargainOrder=0x5306;

///报单成交查询应答
class CFTDRspQryBargainOrderField
{
public:
	///成交日期
	CDateType	ActionDate;
	///成交时间
	CTimeType	ActionTime;
	///成交编号
	CTradeIDType	TradeID;
	///报单编号
	COrderSysIDType	OrderSysID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///价格
	CPriceType	Price;
	///数量
	CVolumeType	Volume;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///客户代码
	CClientIDType	ClientID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(TradeID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ClientID)
	));
};
const DWORD FTD_FID_RspQryBargainOrder=0x5307;

///报单成交查询应答
class CFTDRtnBargainOrderField
{
public:
	///成交日期
	CDateType	ActionDate;
	///成交时间
	CTimeType	ActionTime;
	///成交编号
	CTradeIDType	TradeID;
	///报单编号
	COrderSysIDType	OrderSysID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///价格
	CPriceType	Price;
	///数量
	CVolumeType	Volume;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///客户代码
	CClientIDType	ClientID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(TradeID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ClientID)
	));
};
const DWORD FTD_FID_RtnBargainOrder=0x5308;

///合约基本属性查询
class CFTDReqQryInstPropertyField
{
public:
	///
	CDateType	StartDate;
	///
	CDateType	EndDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(EndDate)
	));
};
const DWORD FTD_FID_ReqQryInstProperty=0x5309;

///合约基本属性查询应答
class CFTDRspQryInstPropertyField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///基础商品代码
	CInstrumentIDType	UnderlyingInstrID;
	///产品类型
	CProductClassType	ProductClass;
	///持仓类型
	CPositionTypeType	PositionType;
	///合约数量乘数
	CVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	CUnderlyingMultipleType	UnderlyingMultiple;
	///合约生命周期状态
	CInstLifePhaseType	InstLifePhase;
	///上市日
	CDateType	OpenDate;
	///到期日
	CDateType	ExpireDate;
	///开始交割日
	CDateType	StartDelivDate;
	///最后交割日
	CDateType	EndDelivDate;
	///挂牌基准价
	CPriceType	BasisPrice;
	///市价单最大下单量
	CVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	CVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	CVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	CVolumeType	MinLimitOrderVolume;
	///最小变动价位
	CPriceType	PriceTick;
	///交割月自然人开仓
	CMonthCountType	AllowDelivPersonOpen;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(UnderlyingInstrID)
		,
		TYPE_DESC(ProductClass)
		,
		TYPE_DESC(PositionType)
		,
		TYPE_DESC(VolumeMultiple)
		,
		TYPE_DESC(UnderlyingMultiple)
		,
		TYPE_DESC(InstLifePhase)
		,
		TYPE_DESC(OpenDate)
		,
		TYPE_DESC(ExpireDate)
		,
		TYPE_DESC(StartDelivDate)
		,
		TYPE_DESC(EndDelivDate)
		,
		TYPE_DESC(BasisPrice)
		,
		TYPE_DESC(MaxMarketOrderVolume)
		,
		TYPE_DESC(MinMarketOrderVolume)
		,
		TYPE_DESC(MaxLimitOrderVolume)
		,
		TYPE_DESC(MinLimitOrderVolume)
		,
		TYPE_DESC(PriceTick)
		,
		TYPE_DESC(AllowDelivPersonOpen)
	));
};
const DWORD FTD_FID_RspQryInstProperty=0x5310;

///合约基本属性查询应答
class CFTDRtnInstPropertyField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///基础商品代码
	CInstrumentIDType	UnderlyingInstrID;
	///产品类型
	CProductClassType	ProductClass;
	///持仓类型
	CPositionTypeType	PositionType;
	///合约数量乘数
	CVolumeMultipleType	VolumeMultiple;
	///合约基础商品乘数
	CUnderlyingMultipleType	UnderlyingMultiple;
	///合约生命周期状态
	CInstLifePhaseType	InstLifePhase;
	///上市日
	CDateType	OpenDate;
	///到期日
	CDateType	ExpireDate;
	///开始交割日
	CDateType	StartDelivDate;
	///最后交割日
	CDateType	EndDelivDate;
	///挂牌基准价
	CPriceType	BasisPrice;
	///市价单最大下单量
	CVolumeType	MaxMarketOrderVolume;
	///市价单最小下单量
	CVolumeType	MinMarketOrderVolume;
	///限价单最大下单量
	CVolumeType	MaxLimitOrderVolume;
	///限价单最小下单量
	CVolumeType	MinLimitOrderVolume;
	///最小变动价位
	CPriceType	PriceTick;
	///交割月自然人开仓
	CMonthCountType	AllowDelivPersonOpen;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(UnderlyingInstrID)
		,
		TYPE_DESC(ProductClass)
		,
		TYPE_DESC(PositionType)
		,
		TYPE_DESC(VolumeMultiple)
		,
		TYPE_DESC(UnderlyingMultiple)
		,
		TYPE_DESC(InstLifePhase)
		,
		TYPE_DESC(OpenDate)
		,
		TYPE_DESC(ExpireDate)
		,
		TYPE_DESC(StartDelivDate)
		,
		TYPE_DESC(EndDelivDate)
		,
		TYPE_DESC(BasisPrice)
		,
		TYPE_DESC(MaxMarketOrderVolume)
		,
		TYPE_DESC(MinMarketOrderVolume)
		,
		TYPE_DESC(MaxLimitOrderVolume)
		,
		TYPE_DESC(MinLimitOrderVolume)
		,
		TYPE_DESC(PriceTick)
		,
		TYPE_DESC(AllowDelivPersonOpen)
	));
};
const DWORD FTD_FID_RtnInstProperty=0x5311;

///合约保证金率查询
class CFTDReqQryMarginRateField
{
public:
	///
	CDateType	StartDate;
	///
	CDateType	EndDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(EndDate)
	));
};
const DWORD FTD_FID_ReqQryMarginRate=0x5312;

///合约保证金率查询应答
class CFTDRspQryMarginRateField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CTradingRoleType	TradingRole;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///取值方式
	CValueModeType	ValueMode;
	///多头保证金率
	CRatioType	LongMarginRatio;
	///空头保证金率
	CRatioType	ShortMarginRatio;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongMarginRatio)
		,
		TYPE_DESC(ShortMarginRatio)
	));
};
const DWORD FTD_FID_RspQryMarginRate=0x5313;

///合约保证金率查询应答
class CFTDRtnMarginRateField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CTradingRoleType	TradingRole;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///取值方式
	CValueModeType	ValueMode;
	///多头保证金率
	CRatioType	LongMarginRatio;
	///空头保证金率
	CRatioType	ShortMarginRatio;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongMarginRatio)
		,
		TYPE_DESC(ShortMarginRatio)
	));
};
const DWORD FTD_FID_RtnMarginRate=0x5314;

///合约涨跌停板查询
class CFTDReqQryPriceLimitField
{
public:
	///
	CDateType	StartDate;
	///
	CDateType	EndDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(EndDate)
	));
};
const DWORD FTD_FID_ReqQryPriceLimit=0x5315;

///合约涨跌停板查询应答
class CFTDRspQryPriceLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///取值方式
	CValueModeType	ValueMode;
	///舍入方式
	CRoundingModeType	RoundingMode;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(RoundingMode)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RspQryPriceLimit=0x5316;

///合约涨跌停板查询应答
class CFTDRtnPriceLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///取值方式
	CValueModeType	ValueMode;
	///舍入方式
	CRoundingModeType	RoundingMode;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(RoundingMode)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RtnPriceLimit=0x5317;

///会员限仓查询
class CFTDReqQryPartPosiLimitField
{
public:
	///
	CDateType	StartDate;
	///
	CDateType	EndDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(EndDate)
	));
};
const DWORD FTD_FID_ReqQryPartPosiLimit=0x5318;

///会员限仓查询应答
class CFTDRspQryPartPosiLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RspQryPartPosiLimit=0x5319;

///会员限仓查询应答
class CFTDRtnPartPosiLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RtnPartPosiLimit=0x5320;

///客户限仓查询
class CFTDReqQryClientPosiLimitField
{
public:
	///
	CDateType	StartDate;
	///
	CDateType	EndDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(EndDate)
	));
};
const DWORD FTD_FID_ReqQryClientPosiLimit=0x5321;

///客户限仓查询应答
class CFTDRspQryClientPosiLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户类型
	CClientTypeType	ClientType;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RspQryClientPosiLimit=0x5322;

///客户限仓查询应答
class CFTDRtnClientPosiLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户类型
	CClientTypeType	ClientType;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RtnClientPosiLimit=0x5323;

///特殊客户限仓查询
class CFTDReqQrySpecialPosiLimitField
{
public:
	///
	CDateType	StartDate;
	///
	CDateType	EndDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(EndDate)
	));
};
const DWORD FTD_FID_ReqQrySpecialPosiLimit=0x5324;

///特殊客户限仓查询应答
class CFTDRspQrySpecialPosiLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RspQrySpecialPosiLimit=0x5325;

///特殊客户限仓查询应答
class CFTDRtnSpecialPosiLimitField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
	));
};
const DWORD FTD_FID_RtnSpecialPosiLimit=0x5326;

///账户出入金查询
class CFTDReqQryTransactionChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryTransactionChg=0x5327;

///账户出入金查询应答
class CFTDRspQryTransactionChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///帐户往来流水号
	CSerialNoType	BillSN;
	///资金账户
	CAccountIDType	ParticipantAccount;
	///会员代码
	CParticipantIDType	ParticipantID;
	///发生额
	CMoneyType	Amount;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(BillSN)
		,
		TYPE_DESC(ParticipantAccount)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(Amount)
	));
};
const DWORD FTD_FID_RspQryTransactionChg=0x5328;

///账户出入金查询应答
class CFTDRtnTransactionChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///帐户往来流水号
	CSerialNoType	BillSN;
	///资金账户
	CAccountIDType	ParticipantAccount;
	///会员代码
	CParticipantIDType	ParticipantID;
	///发生额
	CMoneyType	Amount;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(BillSN)
		,
		TYPE_DESC(ParticipantAccount)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(Amount)
	));
};
const DWORD FTD_FID_RtnTransactionChg=0x5329;

///客户数据变动查询
class CFTDReqQryClientChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryClientChg=0x5330;

///客户数据变动查询应答
class CFTDRspQryClientChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(IdentifiedCardNo)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryClientChg=0x5331;

///客户数据变动查询应答
class CFTDRtnClientChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(IdentifiedCardNo)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnClientChg=0x5332;

///会员客户对照变动查询
class CFTDReqQryPartClientChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryPartClientChg=0x5333;

///会员客户对照变动查询应答
class CFTDRspQryPartClientChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///客户代码
	CClientIDType	ClientID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryPartClientChg=0x5334;

///会员客户对照变动查询应答
class CFTDRtnPartClientChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///客户代码
	CClientIDType	ClientID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnPartClientChg=0x5335;

///限仓数据变动查询
class CFTDReqQryPosiLimitChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryPosiLimitChg=0x5336;

///限仓数据变动查询应答
class CFTDRspQryPosiLimitChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryPosiLimitChg=0x5337;

///限仓数据变动查询应答
class CFTDRtnPosiLimitChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnPosiLimitChg=0x5338;

///保值额度变动查询
class CFTDReqQryHedgeDetailChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryHedgeDetailChg=0x5339;

///保值额度变动查询应答
class CFTDRspQryHedgeDetailChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///用户代码
	COperatorIDType	OperatorID;
	///时间
	CTimeType	Time;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///持仓多空方向
	CPosiDirectionType	PosiDirection;
	///发生额
	CVolumeType	TradingVolume;
	///保值额度
	CVolumeType	HedgeQuota;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(OperatorID)
		,
		TYPE_DESC(Time)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(TradingVolume)
		,
		TYPE_DESC(HedgeQuota)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryHedgeDetailChg=0x5340;

///保值额度变动查询应答
class CFTDRtnHedgeDetailChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///用户代码
	COperatorIDType	OperatorID;
	///时间
	CTimeType	Time;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///持仓多空方向
	CPosiDirectionType	PosiDirection;
	///发生额
	CVolumeType	TradingVolume;
	///保值额度
	CVolumeType	HedgeQuota;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(OperatorID)
		,
		TYPE_DESC(Time)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(TradingVolume)
		,
		TYPE_DESC(HedgeQuota)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnHedgeDetailChg=0x5341;

///会员变动查询
class CFTDReqQryParticipantChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryParticipantChg=0x5342;

///会员变动查询应答
class CFTDRspQryParticipantChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///会员代码
	CParticipantIDType	ParticipantID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///会员简称
	CParticipantAbbrType	ParticipantAbbr;
	///会员类型
	CMemberTypeType	MemberType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ParticipantAbbr)
		,
		TYPE_DESC(MemberType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryParticipantChg=0x5343;

///会员变动查询应答
class CFTDRtnParticipantChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///会员代码
	CParticipantIDType	ParticipantID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///会员简称
	CParticipantAbbrType	ParticipantAbbr;
	///会员类型
	CMemberTypeType	MemberType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ParticipantAbbr)
		,
		TYPE_DESC(MemberType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnParticipantChg=0x5344;

///保证金率变动查询
class CFTDReqQryMarginRateChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryMarginRateChg=0x5345;

///保证金率变动查询应答
class CFTDRspQryMarginRateChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CTradingRoleType	TradingRole;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///取值方式
	CValueModeType	ValueMode;
	///多头保证金率
	CRatioType	LongMarginRatio;
	///空头保证金率
	CRatioType	ShortMarginRatio;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongMarginRatio)
		,
		TYPE_DESC(ShortMarginRatio)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryMarginRateChg=0x5346;

///保证金率变动查询应答
class CFTDRtnMarginRateChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CTradingRoleType	TradingRole;
	///投机套保标志
	CHedgeFlagType	HedgeFlag;
	///取值方式
	CValueModeType	ValueMode;
	///多头保证金率
	CRatioType	LongMarginRatio;
	///空头保证金率
	CRatioType	ShortMarginRatio;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongMarginRatio)
		,
		TYPE_DESC(ShortMarginRatio)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnMarginRateChg=0x5347;

///IP地址变动查询
class CFTDReqQryUserIpChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryUserIpChg=0x5348;

///IP地址变动查询应答
class CFTDRspQryUserIpChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///交易用户代码
	CUserIDType	UserID;
	///IP地址
	CIPAddressType	IPAddress;
	///IP地址掩码
	CIPAddressType	IPMask;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(IPMask)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryUserIpChg=0x5349;

///IP地址变动查询应答
class CFTDRtnUserIpChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///交易用户代码
	CUserIDType	UserID;
	///IP地址
	CIPAddressType	IPAddress;
	///IP地址掩码
	CIPAddressType	IPMask;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(IPMask)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnUserIpChg=0x5350;

///限仓数据变动查询
class CFTDReqQryClientPosiLimitChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryClientPosiLimitChg=0x5351;

///限仓数据变动查询应答
class CFTDRspQryClientPosiLimitChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户类型
	CClientTypeType	ClientType;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryClientPosiLimitChg=0x5352;

///限仓数据变动查询应答
class CFTDRtnClientPosiLimitChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户类型
	CClientTypeType	ClientType;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnClientPosiLimitChg=0x5353;

///限仓数据变动查询
class CFTDReqQrySpecPosiLimitChgField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQrySpecPosiLimitChg=0x5354;

///限仓数据变动查询应答
class CFTDRspQrySpecPosiLimitChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQrySpecPosiLimitChg=0x5355;

///限仓数据变动查询应答
class CFTDRtnSpecPosiLimitChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnSpecPosiLimitChg=0x5356;

///历史对象状态查询
class CFTDReqQryHistoryObjectAttrField
{
public:
	///定义对象名
	CNetObjectIDType	ObjectID;
	///监控指标类型
	CNetAttrTypeType	AttrType;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryHistoryObjectAttr=0x5357;

///历史对象状态查询应答
class CFTDRspQryHistoryObjectAttrField
{
public:
	///采集的日期
	CDateType	MonDate;
	///本周期开始时间
	CTimeType	BeginTime;
	///本周期结束时间
	CTimeType	EndTime;
	///定义对象名
	CNetObjectIDType	ObjectID;
	///监控指标类型
	CNetAttrTypeType	AttrType;
	///监控指标的值类型
	CValueTypeType	ValueType;
	///本周期收到第一个值
	CCapValueType	FirstValue;
	///本周期收到最后一个值
	CCapValueType	EndValue;
	///本周期平均值
	CCapValueType	AvgValue;
	///本周期收到最小值
	CCapValueType	MinValue;
	///本周期收到最大值
	CCapValueType	MaxValue;
	///本周期收到指标个数
	CVolumeType	ValueCount;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(BeginTime)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(ValueType)
		,
		TYPE_DESC(FirstValue)
		,
		TYPE_DESC(EndValue)
		,
		TYPE_DESC(AvgValue)
		,
		TYPE_DESC(MinValue)
		,
		TYPE_DESC(MaxValue)
		,
		TYPE_DESC(ValueCount)
	));
};
const DWORD FTD_FID_RspQryHistoryObjectAttr=0x5358;

///历史对象状态查询应答
class CFTDRtnHistoryObjectAttrField
{
public:
	///采集的日期
	CDateType	MonDate;
	///本周期开始时间
	CTimeType	BeginTime;
	///本周期结束时间
	CTimeType	EndTime;
	///定义对象名
	CNetObjectIDType	ObjectID;
	///监控指标类型
	CNetAttrTypeType	AttrType;
	///监控指标的值类型
	CValueTypeType	ValueType;
	///本周期收到第一个值
	CCapValueType	FirstValue;
	///本周期收到最后一个值
	CCapValueType	EndValue;
	///本周期平均值
	CCapValueType	AvgValue;
	///本周期收到最小值
	CCapValueType	MinValue;
	///本周期收到最大值
	CCapValueType	MaxValue;
	///本周期收到指标个数
	CVolumeType	ValueCount;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(BeginTime)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(ValueType)
		,
		TYPE_DESC(FirstValue)
		,
		TYPE_DESC(EndValue)
		,
		TYPE_DESC(AvgValue)
		,
		TYPE_DESC(MinValue)
		,
		TYPE_DESC(MaxValue)
		,
		TYPE_DESC(ValueCount)
	));
};
const DWORD FTD_FID_RtnHistoryObjectAttr=0x5359;

///前置响应信息查询
class CFTDReqQryFrontInfoField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryFrontInfo=0x5360;

///前置响应信息查询应答
class CFTDRspQryFrontInfoField
{
public:
	///日期
	CDateType	MonDate;
	///本周期开始时间
	CTimeType	MonTime;
	///前置机名
	CTypeObjectIDType	FrontId;
	///前置响应时间条件
	CVolumeType	RspCondition;
	///请求数
	CVolumeType	ReqCount;
	///所占总笔数比率
	CRatioType	ReqRate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(FrontId)
		,
		TYPE_DESC(RspCondition)
		,
		TYPE_DESC(ReqCount)
		,
		TYPE_DESC(ReqRate)
	));
};
const DWORD FTD_FID_RspQryFrontInfo=0x5361;

///前置响应信息查询应答
class CFTDRtnFrontInfoField
{
public:
	///日期
	CDateType	MonDate;
	///本周期开始时间
	CTimeType	MonTime;
	///前置机名
	CTypeObjectIDType	FrontId;
	///前置响应时间条件
	CVolumeType	RspCondition;
	///请求数
	CVolumeType	ReqCount;
	///所占总笔数比率
	CRatioType	ReqRate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(FrontId)
		,
		TYPE_DESC(RspCondition)
		,
		TYPE_DESC(ReqCount)
		,
		TYPE_DESC(ReqRate)
	));
};
const DWORD FTD_FID_RtnFrontInfo=0x5362;

///用户登录查询
class CFTDReqQrySysUserLoginField
{
public:
	///用户代码
	CUserIDType	UserID;
	///密码
	CPasswordType	Password;
	///版本号
	CVersionIDType	VersionID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(VersionID)
	));
};
const DWORD FTD_FID_ReqQrySysUserLogin=0x5363;

///用户登录应答
class CFTDRspQrySysUserLoginField
{
public:
	///用户代码
	CUserIDType	UserID;
	///交易日
	CDateType	TradingDay;
	///登录成功时间
	CTimeType	LoginTime;
	///用户权限
	CPrivilegeType	Privilege;
	///版本匹配标识
	CVersionFlagType	VersionFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(Privilege)
		,
		TYPE_DESC(VersionFlag)
	));
};
const DWORD FTD_FID_RspQrySysUserLogin=0x5364;

///用户登出
class CFTDReqQrySysUserLogoutField
{
public:
	///用户代码
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_ReqQrySysUserLogout=0x5365;

///用户登出应答
class CFTDRspQrySysUserLogoutField
{
public:
	///用户代码
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_RspQrySysUserLogout=0x5366;

///用户修改密码
class CFTDReqQrySysUserPasswordUpdateField
{
public:
	///用户代码
	CUserIDType	UserID;
	///旧密码
	CPasswordType	OldPassword;
	///新密码
	CPasswordType	NewPassword;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(OldPassword)
		,
		TYPE_DESC(NewPassword)
	));
};
const DWORD FTD_FID_ReqQrySysUserPasswordUpdate=0x5367;

///用户修改密码应答
class CFTDRspQrySysUserPasswordUpdateField
{
public:
	///用户代码
	CUserIDType	UserID;
	///密码修改返回信息
	CActionMsgType	PasswordChgMsg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(PasswordChgMsg)
	));
};
const DWORD FTD_FID_RspQrySysUserPasswordUpdate=0x5368;

///用户注册
class CFTDReqQrySysUserRegisterField
{
public:
	///用户代码
	CUserIDType	UserID;
	///用户姓名
	CUserIDType	UserName;
	///用户信息
	CUserInfoType	UserInfo;
	///密码
	CPasswordType	Password;
	///用户权限
	CPrivilegeType	Privilege;
	///用户电子邮件
	CEMailType	EMail;
	///用户电子邮件接收标记
	CReciveFlagType	EMailFlag;
	///用户固定电话
	CTelephoneType	HomePhone;
	///用户固定电话接收标记
	CReciveFlagType	HomePhoneFlag;
	///用户手机
	CTelephoneType	MobilePhone;
	///用户手机接收标记
	CReciveFlagType	MobilePhoneFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(UserInfo)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(Privilege)
		,
		TYPE_DESC(EMail)
		,
		TYPE_DESC(EMailFlag)
		,
		TYPE_DESC(HomePhone)
		,
		TYPE_DESC(HomePhoneFlag)
		,
		TYPE_DESC(MobilePhone)
		,
		TYPE_DESC(MobilePhoneFlag)
	));
};
const DWORD FTD_FID_ReqQrySysUserRegister=0x5369;

///用户注册应答
class CFTDRspQrySysUserRegisterField
{
public:
	///用户代码
	CUserIDType	UserID;
	///用户权限
	CPrivilegeType	Privilege;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Privilege)
	));
};
const DWORD FTD_FID_RspQrySysUserRegister=0x5370;

///删除用户
class CFTDReqQrySysUserDeleteField
{
public:
	///用户代码
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_ReqQrySysUserDelete=0x5371;

///删除用户应答
class CFTDRspQrySysUserDeleteField
{
public:
	///用户代码
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_RspQrySysUserDelete=0x5372;

///会员初始化应答
class CFTDRspQryParticipantInitField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///会员简称
	CParticipantAbbrType	ParticipantAbbr;
	///会员类型
	CMemberTypeType	MemberType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ParticipantAbbr)
		,
		TYPE_DESC(MemberType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryParticipantInit=0x5374;

///会员初始化应答
class CFTDRtnParticipantInitField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///会员简称
	CParticipantAbbrType	ParticipantAbbr;
	///会员类型
	CMemberTypeType	MemberType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ParticipantAbbr)
		,
		TYPE_DESC(MemberType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnParticipantInit=0x5375;

///座席初始化应答
class CFTDRspQryUserInitField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///交易用户类型
	CUserTypeType	UserType;
	///密码
	CPasswordType	Password;
	///交易员权限
	CUserActiveType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryUserInit=0x5376;

///座席初始化应答
class CFTDRtnUserInitField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///交易用户类型
	CUserTypeType	UserType;
	///密码
	CPasswordType	Password;
	///交易员权限
	CUserActiveType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnUserInit=0x5377;

///客户初始化应答
class CFTDRspQryClientInitField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	CTradingRoleType	TradingRole;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(IdentifiedCardNo)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryClientInit=0x5378;

///客户初始化应答
class CFTDRtnClientInitField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	CTradingRoleType	TradingRole;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(IdentifiedCardNo)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnClientInit=0x5379;

///交易日志查询
class CFTDReqQryTradeLogField
{
public:
	///交易日
	CDateType	TradingDay;
	///IP地址
	CIPAddressType	IPAddress;
	///前置号
	CCommodityIDType	FrontID;
	///起始会员号
	CParticipantIDType	StartParticipant;
	///结束会员号
	CParticipantIDType	EndParticipant;
	///起始席位号
	CUserIDType	StartUser;
	///结束席位号
	CUserIDType	EndUser;
	///开始时间
	CTimeType	StartTime;
	///结束时间
	CTimeType	EndTime;
	///起始会话ID
	CCommodityIDType	StartSessionID;
	///结束会话ID
	CCommodityIDType	EndSessionID;
	///根据IP过滤标记
	CBoolType	IPFlag;
	///根据会员过滤标记
	CBoolType	PartFlag;
	///根据席位过滤标记
	CBoolType	UserIDFlag;
	///根据时间过滤标记
	CBoolType	TimeFlag;
	///根据前置号过滤标记
	CBoolType	FrontFlag;
	///根据会话号过滤标记
	CBoolType	SessionFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(StartParticipant)
		,
		TYPE_DESC(EndParticipant)
		,
		TYPE_DESC(StartUser)
		,
		TYPE_DESC(EndUser)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(StartSessionID)
		,
		TYPE_DESC(EndSessionID)
		,
		TYPE_DESC(IPFlag)
		,
		TYPE_DESC(PartFlag)
		,
		TYPE_DESC(UserIDFlag)
		,
		TYPE_DESC(TimeFlag)
		,
		TYPE_DESC(FrontFlag)
		,
		TYPE_DESC(SessionFlag)
	));
};
const DWORD FTD_FID_ReqQryTradeLog=0x5380;

///交易日志查询应答
class CFTDRspQryTradeLogField
{
public:
	///
	CBoolType	bFlag;
	///
	CTradeLogStrType	TradeLogStr;
	TYPE_DESCRIPTOR((
		TYPE_DESC(bFlag)
		,
		TYPE_DESC(TradeLogStr)
	));
};
const DWORD FTD_FID_RspQryTradeLog=0x5381;

///交易日志查询应答
class CFTDRtnTradeLogField
{
public:
	///
	CBoolType	bFlag;
	///
	CTradeLogStrType	TradeLogStr;
	TYPE_DESCRIPTOR((
		TYPE_DESC(bFlag)
		,
		TYPE_DESC(TradeLogStr)
	));
};
const DWORD FTD_FID_RtnTradeLog=0x5382;

///告警时间修改
class CFTDReqQryWarningEventUpdateField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件发生日期
	CDateType	OccurDate;
	///事件发生时间
	CTimeType	OccurTime;
	///事件ID
	CVolumeType	EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///事件名
	CTypeObjectIDType	EventName;
	///事件标签
	CVolumeType	EventNum;
	///事件类型
	CVolumeType	EventType;
	///事件描述
	CTypeDescriptionType	EventDes;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///告警激活日期
	CDateType	ActiveDate;
	///告警激活时间
	CTimeType	ActiveTime;
	///事件处理描述
	CTypeObjectIDType	EventDealDes;
	///事件全名
	CNetAttrTypeType	FullEventName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(OccurDate)
		,
		TYPE_DESC(OccurTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(EventNum)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(EventDes)
		,
		TYPE_DESC(ProcessFlag)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(ActiveDate)
		,
		TYPE_DESC(ActiveTime)
		,
		TYPE_DESC(EventDealDes)
		,
		TYPE_DESC(FullEventName)
	));
};
const DWORD FTD_FID_ReqQryWarningEventUpdate=0x5385;

///交易系统登录信息查询
class CFTDReqQryTradeUserLoginInfoField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryTradeUserLoginInfo=0x5386;

///交易系统登录信息应答
class CFTDRspQryTradeUserLoginInfoField
{
public:
	///对象ID
	CTypeObjectIDType	ObjectID;
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///协议信息
	CProtocolInfoType	ProtocolInfo;
	///IP地址
	CIPAddressType	IPAddress;
	///前置机编号
	CFrontIDType	FrontID;
	///用户类别
	CTypeObjectIDType	UserType;
	/// 接入方式
	CTypeObjectIDType	AccessType;
	///登录或登出日期
	CDateType	ActionDate;
	///登录或登出时间
	CTimeType	ActionTime;
	///登录或登出标记
	CValueTypeType	ActionFlag;
	///数据中心名
	CTypeObjectIDType	DataCenter;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(AccessType)
		,
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ActionFlag)
		,
		TYPE_DESC(DataCenter)
	));
};
const DWORD FTD_FID_RspQryTradeUserLoginInfo=0x5387;

///交易系统登录信息应答
class CFTDRtnTradeUserLoginInfoField
{
public:
	///对象ID
	CTypeObjectIDType	ObjectID;
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///协议信息
	CProtocolInfoType	ProtocolInfo;
	///IP地址
	CIPAddressType	IPAddress;
	///前置机编号
	CFrontIDType	FrontID;
	///用户类别
	CTypeObjectIDType	UserType;
	/// 接入方式
	CTypeObjectIDType	AccessType;
	///登录或登出日期
	CDateType	ActionDate;
	///登录或登出时间
	CTimeType	ActionTime;
	///登录或登出标记
	CValueTypeType	ActionFlag;
	///数据中心名
	CTypeObjectIDType	DataCenter;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(AccessType)
		,
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ActionFlag)
		,
		TYPE_DESC(DataCenter)
	));
};
const DWORD FTD_FID_RtnTradeUserLoginInfo=0x5388;

///会员交易查询
class CFTDReqQryPartTradeField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryPartTrade=0x5389;

///会员交易查询应答
class CFTDRspQryPartTradeField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///总报买单量
	CVolumeType	TotalPositiveOrder;
	///总报单卖量
	CVolumeType	TotalNegativeOrder;
	///买单总成交量
	CVolumeType	TotalPositiveTrade;
	///卖单总成交量
	CVolumeType	TotalNegativeTrade;
	///总多头持仓量
	CVolumeType	TotalPositivePosi;
	///总空头持仓量
	CVolumeType	TotalNegativePosi;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TotalPositiveOrder)
		,
		TYPE_DESC(TotalNegativeOrder)
		,
		TYPE_DESC(TotalPositiveTrade)
		,
		TYPE_DESC(TotalNegativeTrade)
		,
		TYPE_DESC(TotalPositivePosi)
		,
		TYPE_DESC(TotalNegativePosi)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryPartTrade=0x5390;

///交易峰值查询
class CFTDReqQryTradepeakField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///
	CTradepeakFlagType	TradepeakFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(TradepeakFlag)
	));
};
const DWORD FTD_FID_ReqQryTradepeak=0x5391;

///交易峰值查询应答
class CFTDRspQryTradepeakField
{
public:
	///统计信息步长分类
	CTradepeakFlagType	TradepeakFlag;
	///时间
	CTimeType	PeakTime;
	///报单申请量
	CVolumeType	InsertOrder;
	///报单操作量
	CVolumeType	ActionOrder;
	///无效报单量
	CVolumeType	InvalidOrder;
	///交易合计
	CVolumeType	TotalBusiness;
	///成交数
	CVolumeType	TradeCount;
	///合计
	CVolumeType	TotalCount;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradepeakFlag)
		,
		TYPE_DESC(PeakTime)
		,
		TYPE_DESC(InsertOrder)
		,
		TYPE_DESC(ActionOrder)
		,
		TYPE_DESC(InvalidOrder)
		,
		TYPE_DESC(TotalBusiness)
		,
		TYPE_DESC(TradeCount)
		,
		TYPE_DESC(TotalCount)
	));
};
const DWORD FTD_FID_RspQryTradepeak=0x5392;

///
class CFTDRtnUpdateSysConfigField
{
public:
	///更新类型
	CTypeObjectIDType	UpdateType;
	///旧值
	CTypeObjectIDType	OldValue;
	///新值
	CTypeObjectIDType	NewValue;
	///备用
	CTypeObjectIDType	Standby;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UpdateType)
		,
		TYPE_DESC(OldValue)
		,
		TYPE_DESC(NewValue)
		,
		TYPE_DESC(Standby)
	));
};
const DWORD FTD_FID_RtnUpdateSysConfig=0x5393;

///
class CFTDRtnSysUserField
{
public:
	///用户代码
	CUserIDType	UserID;
	///用户姓名
	CUserIDType	UserName;
	///用户信息
	CUserInfoType	UserInfo;
	///密码
	CPasswordType	Password;
	///用户权限
	CPrivilegeType	Privilege;
	///用户电子邮件
	CEMailType	EMail;
	///用户电子邮件接收标记
	CReciveFlagType	EMailFlag;
	///用户固定电话
	CTelephoneType	HomePhone;
	///用户固定电话接收标记
	CReciveFlagType	HomePhoneFlag;
	///用户手机
	CTelephoneType	MobilePhone;
	///用户手机接收标记
	CReciveFlagType	MobilePhoneFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(UserInfo)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(Privilege)
		,
		TYPE_DESC(EMail)
		,
		TYPE_DESC(EMailFlag)
		,
		TYPE_DESC(HomePhone)
		,
		TYPE_DESC(HomePhoneFlag)
		,
		TYPE_DESC(MobilePhone)
		,
		TYPE_DESC(MobilePhoneFlag)
	));
};
const DWORD FTD_FID_RtnSysUser=0x5394;

///
class CFTDRtnPriceLimitChgField
{
public:
	///操作日期
	CDateType	ActionDate;
	///操作时间
	CTimeType	ActionTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///取值方式
	CValueModeType	ValueMode;
	///舍入方式
	CRoundingModeType	RoundingMode;
	///涨停板价
	CPriceType	UpperLimitPrice;
	///跌停板价
	CPriceType	LowerLimitPrice;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(RoundingMode)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnPriceLimitChg=0x5395;

///管理平台初始化信息查询
class CFTDReqQryParticipantInitField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryParticipantInit=0x5396;

///管理平台初始化信息查询
class CFTDReqQryUserInitField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryUserInit=0x5397;

///文件读写标记
class CFTDSysFileAccessInfoField
{
public:
	///
	CTypeObjectIDType	ObjectID;
	///
	CLargeVolumeType	FileSize;
	///
	CLargeVolumeType	FileTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(FileSize)
		,
		TYPE_DESC(FileTime)
	));
};
const DWORD FTD_FID_SysFileAccessInfo=0x5398;

///历史Cpu状态查询
class CFTDReqQryHistoryCpuInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CTypeCPUIdType	CPU;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryHistoryCpuInfo=0x5400;

///历史Cpu查询应答
class CFTDRspQryHistoryCpuInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///CPU的编号
	CTypeCPUIdType	CPU;
	///
	CRatioType	LOAD;
	///
	CRatioType	USER;
	///
	CRatioType	NICE;
	///
	CRatioType	SYS;
	///
	CRatioType	IDLE;
	///
	CRatioType	BLOCK;
	///
	CRatioType	SWAIT;
	///
	CRatioType	INTR;
	///
	CRatioType	SSYS;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(LOAD)
		,
		TYPE_DESC(USER)
		,
		TYPE_DESC(NICE)
		,
		TYPE_DESC(SYS)
		,
		TYPE_DESC(IDLE)
		,
		TYPE_DESC(BLOCK)
		,
		TYPE_DESC(SWAIT)
		,
		TYPE_DESC(INTR)
		,
		TYPE_DESC(SSYS)
	));
};
const DWORD FTD_FID_RspQryHistoryCpuInfo=0x5401;

///历史Mem状态查询
class CFTDReqQryHistoryMemInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryHistoryMemInfo=0x5402;

///历史Mem查询应答
class CFTDRspQryHistoryMemInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///Total Real Memory
	CVolumeType	TOTALREAL;
	///Active Real Memory
	CVolumeType	ACTIVEREAL;
	///Total Virtual Memory
	CVolumeType	TOTALVIRTUAL;
	///Active Virtual Memory
	CVolumeType	ACTIVEVIRTUAL;
	///Free Memory
	CVolumeType	FREE;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(TOTALREAL)
		,
		TYPE_DESC(ACTIVEREAL)
		,
		TYPE_DESC(TOTALVIRTUAL)
		,
		TYPE_DESC(ACTIVEVIRTUAL)
		,
		TYPE_DESC(FREE)
	));
};
const DWORD FTD_FID_RspQryHistoryMemInfo=0x5403;

///历史网络状态查询
class CFTDReqQryHistoryNetworkInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///网卡名
	CTypeLanNameType	LANNAME;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(LANNAME)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryHistoryNetworkInfo=0x5404;

///历史网络查询应答
class CFTDRspQryHistoryNetworkInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///网卡名
	CTypeLanNameType	LANNAME;
	///网卡的up或down状态
	CTypeLanStatusType	LANSTATUS;
	///网卡的ip地址
	CIPAddressType	IPADDRESS;
	///网卡接收的流量
	CLargeNumberType	RECVBYTES;
	///网卡接收的数据包
	CLargeNumberType	RECVPACKETS;
	///网卡接收端错误数据包
	CLargeNumberType	RECVERRORPACKETS;
	///网卡接收端丢失数据包
	CLargeNumberType	RECVDROPPACKETS;
	///网卡发送的流量
	CLargeNumberType	SENDBYTES;
	///网卡发送的数据包
	CLargeNumberType	SENDPACKETS;
	///网卡发送端错误数据包
	CLargeNumberType	SENDERRORPACKETS;
	///网卡发送端丢失数据包
	CLargeNumberType	SENDDROPPACKETS;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(LANNAME)
		,
		TYPE_DESC(LANSTATUS)
		,
		TYPE_DESC(IPADDRESS)
		,
		TYPE_DESC(RECVBYTES)
		,
		TYPE_DESC(RECVPACKETS)
		,
		TYPE_DESC(RECVERRORPACKETS)
		,
		TYPE_DESC(RECVDROPPACKETS)
		,
		TYPE_DESC(SENDBYTES)
		,
		TYPE_DESC(SENDPACKETS)
		,
		TYPE_DESC(SENDERRORPACKETS)
		,
		TYPE_DESC(SENDDROPPACKETS)
	));
};
const DWORD FTD_FID_RspQryHistoryNetworkInfo=0x5405;

///主机配置查询请求应答
class CFTDRspQryHostConfigField
{
public:
	///
	CCfgTypeType	CfgType;
	///
	CCfgNameType	CfgDataCenter;
	///
	CTypeObjectIDType	CfgName;
	///
	CFilePathNameType	CfgLocation;
	///
	CTypeObjectIDType	CfgHostName;
	///
	CTypeObjectIDType	CfgAttend;
	TYPE_DESCRIPTOR((
		TYPE_DESC(CfgType)
		,
		TYPE_DESC(CfgDataCenter)
		,
		TYPE_DESC(CfgName)
		,
		TYPE_DESC(CfgLocation)
		,
		TYPE_DESC(CfgHostName)
		,
		TYPE_DESC(CfgAttend)
	));
};
const DWORD FTD_FID_RspQryHostConfig=0x5406;

///监控系统在线用户查询
class CFTDReqQryMonitorOnlineUserField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryMonitorOnlineUser=0x5407;

///监控系统在线用户应答
class CFTDRspQryMonitorOnlineUserField
{
public:
	///用户代码
	CUserIDType	UserID;
	///IP地址
	CIPAddressType	IPAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(IPAddress)
	));
};
const DWORD FTD_FID_RspQryMonitorOnlineUser=0x5408;

///交易系统前置统计查询
class CFTDReqQryFrontStatField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryFrontStat=0x5409;

///交易系统前置统计应答
class CFTDRspQryFrontStatField
{
public:
	///前置机编号
	CFrontIDType	FrontID;
	///总报买笔数
	CVolumeType	PositiveOrder;
	///总报卖笔数
	CVolumeType	NegativeOrder;
	///总报买手数
	CVolumeType	TotalPositiveOrder;
	///总报卖手数
	CVolumeType	TotalNegativeOrder;
	///报单状态改变笔数
	CVolumeType	OrderAction;
	///报单状态改变手数
	CVolumeType	TotalOrderAction;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(PositiveOrder)
		,
		TYPE_DESC(NegativeOrder)
		,
		TYPE_DESC(TotalPositiveOrder)
		,
		TYPE_DESC(TotalNegativeOrder)
		,
		TYPE_DESC(OrderAction)
		,
		TYPE_DESC(TotalOrderAction)
	));
};
const DWORD FTD_FID_RspQryFrontStat=0x5410;

///监控系统时钟同步
class CFTDRtnSysTimeSyncField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
	));
};
const DWORD FTD_FID_RtnSysTimeSync=0x5411;

///数据中心切换通知
class CFTDRtnDataCenterChgField
{
public:
	///主数据中心名
	CTypeObjectIDType	DataCenterID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DataCenterID)
	));
};
const DWORD FTD_FID_RtnDataCenterChg=0x5412;

///历史峰值查询
class CFTDReqQryHistoryTradePeakField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryHistoryTradePeak=0x5413;

///历史峰值查询应答
class CFTDRspQryHistoryTradePeakField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控最新日期
	CDateType	MonDate;
	///监控最新时间
	CTimeType	MonTime;
	///监控指标
	CAttrTypeType	AttrType;
	///监控最新值
	CMoneyType	AttrValue;
	///相关指标
	CAttrTypeType	RltAttrType;
	///相关指标当时的值
	CMoneyType	RltAttrValue;
	///最大值的日期
	CDateType	MaxMonDate;
	///最大值的时间
	CTimeType	MaxMonTime;
	///指标历史最大值
	CMoneyType	MaxAttrValue;
	///相关指标当时的值
	CMoneyType	MaxRltAttrValue;
	///次新值的日期
	CDateType	OldMonDate;
	///次新值的时间
	CTimeType	OldMonTime;
	///监控指标的次新值
	CMoneyType	OldAttrValue;
	///相关指标当时的值
	CMoneyType	OldRltAttrValue;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(AttrValue)
		,
		TYPE_DESC(RltAttrType)
		,
		TYPE_DESC(RltAttrValue)
		,
		TYPE_DESC(MaxMonDate)
		,
		TYPE_DESC(MaxMonTime)
		,
		TYPE_DESC(MaxAttrValue)
		,
		TYPE_DESC(MaxRltAttrValue)
		,
		TYPE_DESC(OldMonDate)
		,
		TYPE_DESC(OldMonTime)
		,
		TYPE_DESC(OldAttrValue)
		,
		TYPE_DESC(OldRltAttrValue)
	));
};
const DWORD FTD_FID_RspQryHistoryTradePeak=0x5414;

///历史峰值查询应答
class CFTDRtnHistoryTradePeakField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控最新日期
	CDateType	MonDate;
	///监控最新时间
	CTimeType	MonTime;
	///监控指标
	CAttrTypeType	AttrType;
	///监控最新值
	CMoneyType	AttrValue;
	///相关指标
	CAttrTypeType	RltAttrType;
	///相关指标当时的值
	CMoneyType	RltAttrValue;
	///最大值的日期
	CDateType	MaxMonDate;
	///最大值的时间
	CTimeType	MaxMonTime;
	///指标历史最大值
	CMoneyType	MaxAttrValue;
	///相关指标当时的值
	CMoneyType	MaxRltAttrValue;
	///次新值的日期
	CDateType	OldMonDate;
	///次新值的时间
	CTimeType	OldMonTime;
	///监控指标的次新值
	CMoneyType	OldAttrValue;
	///相关指标当时的值
	CMoneyType	OldRltAttrValue;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(AttrValue)
		,
		TYPE_DESC(RltAttrType)
		,
		TYPE_DESC(RltAttrValue)
		,
		TYPE_DESC(MaxMonDate)
		,
		TYPE_DESC(MaxMonTime)
		,
		TYPE_DESC(MaxAttrValue)
		,
		TYPE_DESC(MaxRltAttrValue)
		,
		TYPE_DESC(OldMonDate)
		,
		TYPE_DESC(OldMonTime)
		,
		TYPE_DESC(OldAttrValue)
		,
		TYPE_DESC(OldRltAttrValue)
	));
};
const DWORD FTD_FID_RtnHistoryTradePeak=0x5415;

///日志事件查询
class CFTDReqQrySyslogEventField
{
public:
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///事件类型
	CVolumeType	EventType;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///事件名
	CTypeObjectIDType	EventName;
	///IP地址
	CIPAddressType	IPAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(IPAddress)
	));
};
const DWORD FTD_FID_ReqQrySyslogEvent=0x5416;

///日志事件查询应答
class CFTDRspQrySyslogEventField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件发生日期
	CDateType	OccurDate;
	///事件发生时间
	CTimeType	OccurTime;
	///事件ID
	CVolumeType	EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///事件名
	CTypeObjectIDType	EventName;
	///事件标签
	CVolumeType	EventNum;
	///事件类型
	CVolumeType	EventType;
	///事件描述
	CTypeDescriptionType	EventDes;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///事件处理描述
	CTypeObjectIDType	EventDealDes;
	///事件全名
	CNetAttrTypeType	FullEventName;
	///事件条数
	CCounterType	EventCount;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(OccurDate)
		,
		TYPE_DESC(OccurTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(EventNum)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(EventDes)
		,
		TYPE_DESC(ProcessFlag)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(EventDealDes)
		,
		TYPE_DESC(FullEventName)
		,
		TYPE_DESC(EventCount)
	));
};
const DWORD FTD_FID_RspQrySyslogEvent=0x5417;

///日志事件应答
class CFTDRtnSyslogEventField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件发生日期
	CDateType	OccurDate;
	///事件发生时间
	CTimeType	OccurTime;
	///事件ID
	CVolumeType	EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///事件名
	CTypeObjectIDType	EventName;
	///事件标签
	CVolumeType	EventNum;
	///事件类型
	CVolumeType	EventType;
	///事件描述
	CTypeDescriptionType	EventDes;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///事件处理描述
	CTypeObjectIDType	EventDealDes;
	///事件全名
	CNetAttrTypeType	FullEventName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(OccurDate)
		,
		TYPE_DESC(OccurTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(EventNum)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(EventDes)
		,
		TYPE_DESC(ProcessFlag)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(EventDealDes)
		,
		TYPE_DESC(FullEventName)
	));
};
const DWORD FTD_FID_RtnSyslogEvent=0x5418;

///日志事件订阅请求
class CFTDReqQrySyslogEventSubcriberField
{
public:
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///事件名
	CTypeObjectIDType	EventName;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///过滤条件组
	CTypeSubcriberObjectIDType	filter;
	///反过滤条件组
	CTypeSubcriberObjectIDType	antifilter;
	///初次返回对象数
	CVolumeType	ObjectNum;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	///返回的初始日期
	CDateType	MonDate;
	///返回的初始时间
	CTimeType	MonTime;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(filter)
		,
		TYPE_DESC(antifilter)
		,
		TYPE_DESC(ObjectNum)
		,
		TYPE_DESC(KeepAlive)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ProcessFlag)
	));
};
const DWORD FTD_FID_ReqQrySyslogEventSubcriber=0x5419;

///交易日切换通知
class CFTDReqQryTradeDayChangeField
{
public:
	///切换类型
	CTypeObjectIDType	ChangeType;
	///原交易日
	CDateType	OldDate;
	///新交易日
	CDateType	NewDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ChangeType)
		,
		TYPE_DESC(OldDate)
		,
		TYPE_DESC(NewDate)
	));
};
const DWORD FTD_FID_ReqQryTradeDayChange=0x5420;

///交易日切换通知
class CFTDRspQryTradeDayChangeField
{
public:
	///切换类型
	CTypeObjectIDType	ChangeType;
	///原交易日
	CDateType	OldDate;
	///新交易日
	CDateType	NewDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ChangeType)
		,
		TYPE_DESC(OldDate)
		,
		TYPE_DESC(NewDate)
	));
};
const DWORD FTD_FID_RspQryTradeDayChange=0x5421;

///tomcat信息查询
class CFTDReqQryTomcatInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryTomcatInfo=0x5422;

///Web应用信息
class CFTDRspQryWebAppInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///Web应用名称
	CCfgNameType	AppName;
	///应用运行状态
	CTypeObjectNameType	Status;
	///应用描述信息
	CTypeDescriptionType	Desc;
	///应用启动时间
	CTypeCurrentTimeType	StartTime;
	///应用servlet数量
	CTypeChar10Type	ServletNum;
	///应用处理总时长
	CTypeCommandType	ProcessTime;
	///应用累计接收请求数
	CTypeCommandType	RequestNum;
	///应用累计错误数
	CTypeCommandType	ErrorNum;
	///应用当前会话数
	CTypeChar10Type	SessionSize;
	///会话超时时长(秒)
	CTypeChar10Type	TimeOut;
	///应用JDBC连接使用率
	CTypeChar10Type	JDBCUsage;
	///应用JSP文件数量
	CTypeChar10Type	JSPNum;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(AppName)
		,
		TYPE_DESC(Status)
		,
		TYPE_DESC(Desc)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(ServletNum)
		,
		TYPE_DESC(ProcessTime)
		,
		TYPE_DESC(RequestNum)
		,
		TYPE_DESC(ErrorNum)
		,
		TYPE_DESC(SessionSize)
		,
		TYPE_DESC(TimeOut)
		,
		TYPE_DESC(JDBCUsage)
		,
		TYPE_DESC(JSPNum)
	));
};
const DWORD FTD_FID_RspQryWebAppInfo=0x5423;

///Web应用信息
class CFTDRtnWebAppInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///Web应用名称
	CCfgNameType	AppName;
	///应用运行状态
	CTypeObjectNameType	Status;
	///应用描述信息
	CTypeDescriptionType	Desc;
	///应用启动时间
	CTypeCurrentTimeType	StartTime;
	///应用servlet数量
	CTypeChar10Type	ServletNum;
	///应用处理总时长
	CTypeCommandType	ProcessTime;
	///应用累计接收请求数
	CTypeCommandType	RequestNum;
	///应用累计错误数
	CTypeCommandType	ErrorNum;
	///应用当前会话数
	CTypeChar10Type	SessionSize;
	///会话超时时长(秒)
	CTypeChar10Type	TimeOut;
	///应用JDBC连接使用率
	CTypeChar10Type	JDBCUsage;
	///应用JSP文件数量
	CTypeChar10Type	JSPNum;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(AppName)
		,
		TYPE_DESC(Status)
		,
		TYPE_DESC(Desc)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(ServletNum)
		,
		TYPE_DESC(ProcessTime)
		,
		TYPE_DESC(RequestNum)
		,
		TYPE_DESC(ErrorNum)
		,
		TYPE_DESC(SessionSize)
		,
		TYPE_DESC(TimeOut)
		,
		TYPE_DESC(JDBCUsage)
		,
		TYPE_DESC(JSPNum)
	));
};
const DWORD FTD_FID_RtnWebAppInfo=0x5424;

///应用servlet信息
class CFTDRspQryServletInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///servlet名称
	CTypeObjectIDType	Name;
	///加载耗时
	CTypeContLenType	LoadTime;
	///接收请求数量
	CRatioType	RequestNum;
	///错误数量
	CRatioType	RequestErrNum;
	///处理时长
	CRatioType	ProcessTime;
	///最小处理时间
	CTypeContLenType	MixTime;
	///最大处理时间
	CTypeContLenType	MaxTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(LoadTime)
		,
		TYPE_DESC(RequestNum)
		,
		TYPE_DESC(RequestErrNum)
		,
		TYPE_DESC(ProcessTime)
		,
		TYPE_DESC(MixTime)
		,
		TYPE_DESC(MaxTime)
	));
};
const DWORD FTD_FID_RspQryServletInfo=0x5425;

///应用servlet信息
class CFTDRtnServletInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///servlet名称
	CTypeObjectIDType	Name;
	///加载耗时
	CTypeContLenType	LoadTime;
	///接收请求数量
	CRatioType	RequestNum;
	///错误数量
	CRatioType	RequestErrNum;
	///处理时长
	CRatioType	ProcessTime;
	///最小处理时间
	CTypeContLenType	MixTime;
	///最大处理时间
	CTypeContLenType	MaxTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(LoadTime)
		,
		TYPE_DESC(RequestNum)
		,
		TYPE_DESC(RequestErrNum)
		,
		TYPE_DESC(ProcessTime)
		,
		TYPE_DESC(MixTime)
		,
		TYPE_DESC(MaxTime)
	));
};
const DWORD FTD_FID_RtnServletInfo=0x5426;

///文件信息
class CFTDRspQryFileInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///文件全路径名
	CFilePathNameType	PathName;
	///文件大小
	CTypeChar10Type	FileSize;
	///文件最后修改时间
	CTypeMonitorTypeType	LastModDate;
	///文件属性
	CTypeObjectNameType	FileType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(PathName)
		,
		TYPE_DESC(FileSize)
		,
		TYPE_DESC(LastModDate)
		,
		TYPE_DESC(FileType)
	));
};
const DWORD FTD_FID_RspQryFileInfo=0x5427;

///文件信息
class CFTDRtnFileInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///文件全路径名
	CFilePathNameType	PathName;
	///文件大小
	CTypeChar10Type	FileSize;
	///文件最后修改时间
	CTypeMonitorTypeType	LastModDate;
	///文件属性
	CTypeObjectNameType	FileType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(PathName)
		,
		TYPE_DESC(FileSize)
		,
		TYPE_DESC(LastModDate)
		,
		TYPE_DESC(FileType)
	));
};
const DWORD FTD_FID_RtnFileInfo=0x5428;

///应用会话信息
class CFTDRspQrySessionInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///Session编号
	CCfgNameType	SessionID;
	///Session名称
	CTypeObjectIDType	SessionName;
	///Session对应客户端IP地址
	CTypeObjectNameType	RemoteIP;
	///Session创建时间
	CTypeHostModelType	BeginTime;
	///Session最新请求时间
	CTypeHostModelType	LatestTime;
	///Session超时时间(秒)
	CTypeContLenType	MaxIdleTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(SessionName)
		,
		TYPE_DESC(RemoteIP)
		,
		TYPE_DESC(BeginTime)
		,
		TYPE_DESC(LatestTime)
		,
		TYPE_DESC(MaxIdleTime)
	));
};
const DWORD FTD_FID_RspQrySessionInfo=0x5429;

///应用会话信息
class CFTDRtnSessionInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///Session编号
	CCfgNameType	SessionID;
	///Session名称
	CTypeObjectIDType	SessionName;
	///Session对应客户端IP地址
	CTypeObjectNameType	RemoteIP;
	///Session创建时间
	CTypeHostModelType	BeginTime;
	///Session最新请求时间
	CTypeHostModelType	LatestTime;
	///Session超时时间(秒)
	CTypeContLenType	MaxIdleTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(SessionName)
		,
		TYPE_DESC(RemoteIP)
		,
		TYPE_DESC(BeginTime)
		,
		TYPE_DESC(LatestTime)
		,
		TYPE_DESC(MaxIdleTime)
	));
};
const DWORD FTD_FID_RtnSessionInfo=0x5430;

///JDBC信息
class CFTDRspQryJDBCInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///应用程序名称
	CCfgNameType	AppName;
	///JDBC连接池名称
	CCfgNameType	Name;
	///连接池使用比例
	CStockPercentType	Usage;
	///最大连接数
	CTypeContLenType	ConnNumMax;
	///空闲连接数
	CTypeContLenType	ConnNumFree;
	///不可重用连接数
	CTypeContLenType	ConnNumUnRU;
	///可重用连接数
	CTypeContLenType	ConnNumRU;
	///对应数据库用户
	CCfgNameType	UserName;
	///JDBC类型
	CTypeObjectIDType	Type;
	///JDBC Url
	CTypeObjectIDType	URL;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(AppName)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(Usage)
		,
		TYPE_DESC(ConnNumMax)
		,
		TYPE_DESC(ConnNumFree)
		,
		TYPE_DESC(ConnNumUnRU)
		,
		TYPE_DESC(ConnNumRU)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(Type)
		,
		TYPE_DESC(URL)
	));
};
const DWORD FTD_FID_RspQryJDBCInfo=0x5431;

///JDBC信息
class CFTDRtnJDBCInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///应用程序名称
	CCfgNameType	AppName;
	///JDBC连接池名称
	CCfgNameType	Name;
	///连接池使用比例
	CStockPercentType	Usage;
	///最大连接数
	CTypeContLenType	ConnNumMax;
	///空闲连接数
	CTypeContLenType	ConnNumFree;
	///不可重用连接数
	CTypeContLenType	ConnNumUnRU;
	///可重用连接数
	CTypeContLenType	ConnNumRU;
	///对应数据库用户
	CCfgNameType	UserName;
	///JDBC类型
	CTypeObjectIDType	Type;
	///JDBC Url
	CTypeObjectIDType	URL;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(AppName)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(Usage)
		,
		TYPE_DESC(ConnNumMax)
		,
		TYPE_DESC(ConnNumFree)
		,
		TYPE_DESC(ConnNumUnRU)
		,
		TYPE_DESC(ConnNumRU)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(Type)
		,
		TYPE_DESC(URL)
	));
};
const DWORD FTD_FID_RtnJDBCInfo=0x5432;

///线程信息
class CFTDRspQryThreadInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///线程名称
	CTypeObjectIDType	Name;
	///线程编号
	CTypeContLenType	ThreadNum;
	///线程状态
	CTypeObjectNameType	ThreadStatus;
	///线程Native标识
	CTypeContLenType	InNative;
	///线程Suspended标识
	CTypeLanNameType	Suspended;
	///线程阻塞总数
	CTypeLanNameType	BlockCount;
	///线程等待总数
	CTypeContLenType	WaitCount;
	///线程CPU时间
	CRatioType	CpuTime;
	///线程用户时间
	CRatioType	UserTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(ThreadNum)
		,
		TYPE_DESC(ThreadStatus)
		,
		TYPE_DESC(InNative)
		,
		TYPE_DESC(Suspended)
		,
		TYPE_DESC(BlockCount)
		,
		TYPE_DESC(WaitCount)
		,
		TYPE_DESC(CpuTime)
		,
		TYPE_DESC(UserTime)
	));
};
const DWORD FTD_FID_RspQryThreadInfo=0x5433;

///线程信息
class CFTDRtnThreadInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///线程名称
	CTypeObjectIDType	Name;
	///线程编号
	CTypeContLenType	ThreadNum;
	///线程状态
	CTypeObjectNameType	ThreadStatus;
	///线程Native标识
	CTypeContLenType	InNative;
	///线程Suspended标识
	CTypeLanNameType	Suspended;
	///线程阻塞总数
	CTypeLanNameType	BlockCount;
	///线程等待总数
	CTypeContLenType	WaitCount;
	///线程CPU时间
	CRatioType	CpuTime;
	///线程用户时间
	CRatioType	UserTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(ThreadNum)
		,
		TYPE_DESC(ThreadStatus)
		,
		TYPE_DESC(InNative)
		,
		TYPE_DESC(Suspended)
		,
		TYPE_DESC(BlockCount)
		,
		TYPE_DESC(WaitCount)
		,
		TYPE_DESC(CpuTime)
		,
		TYPE_DESC(UserTime)
	));
};
const DWORD FTD_FID_RtnThreadInfo=0x5434;

///虚拟机信息查询
class CFTDReqQryVMInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryVMInfo=0x5435;

///虚拟机信息
class CFTDRspQryVMInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///虚拟机名称
	CTypeObjectIDType	Name;
	///虚拟机类型
	CTypeObjectIDType	VmName;
	///供应商
	CTypeObjectIDType	VmVendor;
	///虚拟机版本
	CTypeObjectIDType	VmVersion;
	///启动时间
	CTypeObjectIDType	StartTime;
	///启动类路径
	CTypeFileContentType	BootClassPath;
	///类路径
	CTypeFileContentType	ClassPath;
	///库路径
	CTypeFileContentType	LibraryPath;
	///启动参数
	CTypeFileContentType	Arguments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(VmName)
		,
		TYPE_DESC(VmVendor)
		,
		TYPE_DESC(VmVersion)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(BootClassPath)
		,
		TYPE_DESC(ClassPath)
		,
		TYPE_DESC(LibraryPath)
		,
		TYPE_DESC(Arguments)
	));
};
const DWORD FTD_FID_RspQryVMInfo=0x5436;

///虚拟机信息
class CFTDRtnVMInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///虚拟机名称
	CTypeObjectIDType	Name;
	///虚拟机类型
	CTypeObjectIDType	VmName;
	///供应商
	CTypeObjectIDType	VmVendor;
	///虚拟机版本
	CTypeObjectIDType	VmVersion;
	///启动时间
	CTypeObjectIDType	StartTime;
	///启动类路径
	CTypeFileContentType	BootClassPath;
	///类路径
	CTypeFileContentType	ClassPath;
	///库路径
	CTypeFileContentType	LibraryPath;
	///启动参数
	CTypeFileContentType	Arguments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(VmName)
		,
		TYPE_DESC(VmVendor)
		,
		TYPE_DESC(VmVersion)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(BootClassPath)
		,
		TYPE_DESC(ClassPath)
		,
		TYPE_DESC(LibraryPath)
		,
		TYPE_DESC(Arguments)
	));
};
const DWORD FTD_FID_RtnVMInfo=0x5437;

///系统属性信息查询
class CFTDReqQryPropertyInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryPropertyInfo=0x5438;

///系统属性信息
class CFTDRspQryPropertyInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///系统属性名
	CTypeObjectIDType	Property;
	///分割标识
	CTypeContLenType	ClipFlag;
	///属性值
	CFilePathNameType	Value;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Property)
		,
		TYPE_DESC(ClipFlag)
		,
		TYPE_DESC(Value)
	));
};
const DWORD FTD_FID_RspQryPropertyInfo=0x5439;

///系统属性信息
class CFTDRtnPropertyInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///系统属性名
	CTypeObjectIDType	Property;
	///分割标识
	CTypeContLenType	ClipFlag;
	///属性值
	CFilePathNameType	Value;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Property)
		,
		TYPE_DESC(ClipFlag)
		,
		TYPE_DESC(Value)
	));
};
const DWORD FTD_FID_RtnPropertyInfo=0x5440;

///系统内存池信息查询
class CFTDReqQryMemPoolInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryMemPoolInfo=0x5441;

///系统内存池信息
class CFTDRspQryMemPoolInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///系统属性名
	CCfgNameType	PoolName;
	///系统属性名
	CTypeChar10Type	Usage;
	///系统属性名
	CTypeCommandType	committedbytes;
	///系统属性名
	CTypeCommandType	initbytes;
	///系统属性名
	CTypeCommandType	maxbytes;
	///系统属性名
	CTypeCommandType	usedbytes;
	///系统属性名
	CTypeChar10Type	Type;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(PoolName)
		,
		TYPE_DESC(Usage)
		,
		TYPE_DESC(committedbytes)
		,
		TYPE_DESC(initbytes)
		,
		TYPE_DESC(maxbytes)
		,
		TYPE_DESC(usedbytes)
		,
		TYPE_DESC(Type)
	));
};
const DWORD FTD_FID_RspQryMemPoolInfo=0x5442;

///系统内存池信息
class CFTDRtnMemPoolInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///系统属性名
	CCfgNameType	PoolName;
	///系统属性名
	CTypeChar10Type	Usage;
	///系统属性名
	CTypeCommandType	committedbytes;
	///系统属性名
	CTypeCommandType	initbytes;
	///系统属性名
	CTypeCommandType	maxbytes;
	///系统属性名
	CTypeCommandType	usedbytes;
	///系统属性名
	CTypeChar10Type	Type;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(PoolName)
		,
		TYPE_DESC(Usage)
		,
		TYPE_DESC(committedbytes)
		,
		TYPE_DESC(initbytes)
		,
		TYPE_DESC(maxbytes)
		,
		TYPE_DESC(usedbytes)
		,
		TYPE_DESC(Type)
	));
};
const DWORD FTD_FID_RtnMemPoolInfo=0x5443;

///文件内容信息查询
class CFTDReqQryFileContentInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryFileContentInfo=0x5444;

///文件内容信息
class CFTDRspQryFileContentInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///文件名
	CFilePathNameType	FileName;
	///文件内容
	CTypeFileContentType	FileContent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(FileName)
		,
		TYPE_DESC(FileContent)
	));
};
const DWORD FTD_FID_RspQryFileContentInfo=0x5445;

///文件内容信息
class CFTDRtnFileContentInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///文件名
	CFilePathNameType	FileName;
	///文件内容
	CTypeFileContentType	FileContent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(FileName)
		,
		TYPE_DESC(FileContent)
	));
};
const DWORD FTD_FID_RtnFileContentInfo=0x5446;

///连接信息查询
class CFTDReqQryConnectionInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryConnectionInfo=0x5447;

///连接信息
class CFTDRspQryConnectionInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///服务线程名
	CCfgNameType	ServiceName;
	///当前状态
	CTypeChar10Type	Stage;
	///累计接收请求数
	CRatioType	RequestCount;
	///累计错误数
	CRatioType	ErrorCount;
	///累计处理时长
	CRatioType	ProcTime;
	///累计接收字节数
	CRatioType	BytesReceived;
	///累计发送字节数
	CRatioType	BytesSent;
	///远程IP地址
	CTypeObjectNameType	RemoteIP;
	///最大请求URI
	CAttrTypeType	MaxAccessURI;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ServiceName)
		,
		TYPE_DESC(Stage)
		,
		TYPE_DESC(RequestCount)
		,
		TYPE_DESC(ErrorCount)
		,
		TYPE_DESC(ProcTime)
		,
		TYPE_DESC(BytesReceived)
		,
		TYPE_DESC(BytesSent)
		,
		TYPE_DESC(RemoteIP)
		,
		TYPE_DESC(MaxAccessURI)
	));
};
const DWORD FTD_FID_RspQryConnectionInfo=0x5448;

///连接信息
class CFTDRtnConnectionInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///服务线程名
	CCfgNameType	ServiceName;
	///当前状态
	CTypeChar10Type	Stage;
	///累计接收请求数
	CRatioType	RequestCount;
	///累计错误数
	CRatioType	ErrorCount;
	///累计处理时长
	CRatioType	ProcTime;
	///累计接收字节数
	CRatioType	BytesReceived;
	///累计发送字节数
	CRatioType	BytesSent;
	///远程IP地址
	CTypeObjectNameType	RemoteIP;
	///最大请求URI
	CAttrTypeType	MaxAccessURI;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ServiceName)
		,
		TYPE_DESC(Stage)
		,
		TYPE_DESC(RequestCount)
		,
		TYPE_DESC(ErrorCount)
		,
		TYPE_DESC(ProcTime)
		,
		TYPE_DESC(BytesReceived)
		,
		TYPE_DESC(BytesSent)
		,
		TYPE_DESC(RemoteIP)
		,
		TYPE_DESC(MaxAccessURI)
	));
};
const DWORD FTD_FID_RtnConnectionInfo=0x5449;

///连接器信息查询
class CFTDReqQryConnectorInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryConnectorInfo=0x5450;

///连接器信息
class CFTDRspQryConnectorInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///连接器名称
	CTypeObjectNameType	Name;
	///当前处理线程数
	CTypeChar10Type	ThreadsCount;
	///当前繁忙线程数
	CTypeChar10Type	BusyThreadsCount;
	///最大线程数
	CTypeChar10Type	MaxThreads;
	///最大空闲线程数
	CTypeChar10Type	MaxSpareThreads;
	///最小空闲线程数
	CTypeChar10Type	MinSpareThreads;
	///最长连接时间
	CTypeCommandType	MaxTime;
	///最长处理时间
	CTypeCommandType	MaxProcTime;
	///累计接收请求数
	CTypeCommandType	RequestCount;
	///累计错误数
	CTypeCommandType	ErrorCount;
	///累计接收字节数
	CTypeChar10Type	BytesReceived;
	///累计发送字节数
	CTypeChar10Type	BytesSent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(ThreadsCount)
		,
		TYPE_DESC(BusyThreadsCount)
		,
		TYPE_DESC(MaxThreads)
		,
		TYPE_DESC(MaxSpareThreads)
		,
		TYPE_DESC(MinSpareThreads)
		,
		TYPE_DESC(MaxTime)
		,
		TYPE_DESC(MaxProcTime)
		,
		TYPE_DESC(RequestCount)
		,
		TYPE_DESC(ErrorCount)
		,
		TYPE_DESC(BytesReceived)
		,
		TYPE_DESC(BytesSent)
	));
};
const DWORD FTD_FID_RspQryConnectorInfo=0x5451;

///连接器信息
class CFTDRtnConnectorInfoField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///连接器名称
	CTypeObjectNameType	Name;
	///当前处理线程数
	CTypeChar10Type	ThreadsCount;
	///当前繁忙线程数
	CTypeChar10Type	BusyThreadsCount;
	///最大线程数
	CTypeChar10Type	MaxThreads;
	///最大空闲线程数
	CTypeChar10Type	MaxSpareThreads;
	///最小空闲线程数
	CTypeChar10Type	MinSpareThreads;
	///最长连接时间
	CTypeCommandType	MaxTime;
	///最长处理时间
	CTypeCommandType	MaxProcTime;
	///累计接收请求数
	CTypeCommandType	RequestCount;
	///累计错误数
	CTypeCommandType	ErrorCount;
	///累计接收字节数
	CTypeChar10Type	BytesReceived;
	///累计发送字节数
	CTypeChar10Type	BytesSent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(ThreadsCount)
		,
		TYPE_DESC(BusyThreadsCount)
		,
		TYPE_DESC(MaxThreads)
		,
		TYPE_DESC(MaxSpareThreads)
		,
		TYPE_DESC(MinSpareThreads)
		,
		TYPE_DESC(MaxTime)
		,
		TYPE_DESC(MaxProcTime)
		,
		TYPE_DESC(RequestCount)
		,
		TYPE_DESC(ErrorCount)
		,
		TYPE_DESC(BytesReceived)
		,
		TYPE_DESC(BytesSent)
	));
};
const DWORD FTD_FID_RtnConnectorInfo=0x5452;

///数据库查询
class CFTDReqQryDBQueryField
{
public:
	///数据库实例对象ID
	CTypeObjectIDType	ObjectID;
	///存储过程名
	CAttrTypeType	AttrType;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryDBQuery=0x5453;

///数据库查询应答
class CFTDRspQryDBQueryField
{
public:
	///数据库实例对象ID
	CTypeObjectIDType	ObjectID;
	///存储过程名
	CAttrTypeType	AttrType;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///数据库查询结果
	CDBQueryResultType	DBQueryResult;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(DBQueryResult)
	));
};
const DWORD FTD_FID_RspQryDBQuery=0x5454;

///数据库查询应答
class CFTDRtnDBQueryField
{
public:
	///数据库实例对象ID
	CTypeObjectIDType	ObjectID;
	///存储过程名
	CAttrTypeType	AttrType;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///数据库查询结果
	CDBQueryResultType	DBQueryResult;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(DBQueryResult)
	));
};
const DWORD FTD_FID_RtnDBQuery=0x5455;

///通用返回应答
class CFTDSysGeneralFieldField
{
public:
	///监控日期
	CDateType	MonDate;
	///监控时间
	CTimeType	MonTime;
	///监控对象
	CTypeObjectIDType	ObjectID;
	///子监控对象
	CTypeObjectIDType	SubObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	///通用返回字段
	CGeneralResultType	Content;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(SubObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(Content)
	));
};
const DWORD FTD_FID_SysGeneralField=0x5457;

///文件传输请求
class CFTDReqQryGetFileField
{
public:
	///文件名称
	CNetAttrTypeType	FileName;
	///文件版本
	CFileVersionType	Version;
	///文件偏移
	COffsetType	Offset;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FileName)
		,
		TYPE_DESC(Version)
		,
		TYPE_DESC(Offset)
	));
};
const DWORD FTD_FID_ReqQryGetFile=0x5458;

///文件传输应答
class CFTDRspQryGetFileField
{
public:
	///文件名称
	CNetAttrTypeType	FileName;
	///文件版本
	CFileVersionType	Version;
	///文件偏移
	COffsetType	Offset;
	///Comment中实际内容长度
	CCommLengthType	Length;
	///文件内容
	CFileCommentType	Comment;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FileName)
		,
		TYPE_DESC(Version)
		,
		TYPE_DESC(Offset)
		,
		TYPE_DESC(Length)
		,
		TYPE_DESC(Comment)
	));
};
const DWORD FTD_FID_RspQryGetFile=0x5459;

///日志事件修改请求
class CFTDReqQrySyslogEventUpdateField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件发生日期
	CDateType	OccurDate;
	///事件发生时间
	CTimeType	OccurTime;
	///事件ID
	CVolumeType	EvendID;
	///发生事件的对象ID指标
	CNetAttrTypeType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///事件名
	CTypeObjectIDType	EventName;
	///事件标签
	CVolumeType	EventNum;
	///事件类型
	CVolumeType	EventType;
	///事件描述
	CTypeDescriptionType	EventDes;
	///清除标记
	CTypeProcessFlagType	ProcessFlag;
	///警告级别
	CTypeWarningLevelType	WarningLevel;
	///事件处理描述
	CTypeObjectIDType	EventDealDes;
	///事件全名
	CNetAttrTypeType	FullEventName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(OccurDate)
		,
		TYPE_DESC(OccurTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(EventName)
		,
		TYPE_DESC(EventNum)
		,
		TYPE_DESC(EventType)
		,
		TYPE_DESC(EventDes)
		,
		TYPE_DESC(ProcessFlag)
		,
		TYPE_DESC(WarningLevel)
		,
		TYPE_DESC(EventDealDes)
		,
		TYPE_DESC(FullEventName)
	));
};
const DWORD FTD_FID_ReqQrySyslogEventUpdate=0x5460;

///告警明细查询
class CFTDReqQryWarningQueryField
{
public:
	///事件ID
	CVolumeType	EvendID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(EvendID)
	));
};
const DWORD FTD_FID_ReqQryWarningQuery=0x5461;

///告警明细
class CFTDRspQryWarningQueryField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件ID
	CVolumeType	EvendID;
	///数据库查询结果
	CDBQueryResultType	DBQueryResult;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(DBQueryResult)
	));
};
const DWORD FTD_FID_RspQryWarningQuery=0x5462;

///告警明细
class CFTDRtnWarningQueryField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///事件ID
	CVolumeType	EvendID;
	///数据库查询结果
	CDBQueryResultType	DBQueryResult;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(EvendID)
		,
		TYPE_DESC(DBQueryResult)
	));
};
const DWORD FTD_FID_RtnWarningQuery=0x5463;

///网站访问查询
class CFTDReqQryWebVisitField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///监控指标
	CFilePathNameType	AttrType;
	///起始日期
	CDateType	BeginDate;
	///起始时间
	CTimeType	BeginTime;
	///结束日期
	CDateType	EndDate;
	///结束时间
	CTimeType	EndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(BeginDate)
		,
		TYPE_DESC(BeginTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
	));
};
const DWORD FTD_FID_ReqQryWebVisit=0x5464;

///主机配置查询订阅应答
class CFTDRtnHostConfigField
{
public:
	///
	CCfgTypeType	CfgType;
	///
	CCfgNameType	CfgDataCenter;
	///
	CTypeObjectIDType	CfgName;
	///
	CFilePathNameType	CfgLocation;
	///
	CTypeObjectIDType	CfgHostName;
	///
	CTypeObjectIDType	CfgAttend;
	TYPE_DESCRIPTOR((
		TYPE_DESC(CfgType)
		,
		TYPE_DESC(CfgDataCenter)
		,
		TYPE_DESC(CfgName)
		,
		TYPE_DESC(CfgLocation)
		,
		TYPE_DESC(CfgHostName)
		,
		TYPE_DESC(CfgAttend)
	));
};
const DWORD FTD_FID_RtnHostConfig=0x5465;

///告警激活变更
class CFTDReqQryWarningActiveChangeField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///日期
	CDateType	MonDate;
	///时间
	CTimeType	MonTime;
	///告警事件产生标志位
	CTypeIsActiveType	WarningActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(WarningActive)
	));
};
const DWORD FTD_FID_ReqQryWarningActiveChange=0x5466;

///告警激活变更
class CFTDRspQryWarningActiveChangeField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///日期
	CDateType	MonDate;
	///时间
	CTimeType	MonTime;
	///告警事件产生标志位
	CTypeIsActiveType	WarningActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(WarningActive)
	));
};
const DWORD FTD_FID_RspQryWarningActiveChange=0x5467;

///告警激活变更
class CFTDRtnWarningActiveChangeField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	///日期
	CDateType	MonDate;
	///时间
	CTimeType	MonTime;
	///告警事件产生标志位
	CTypeIsActiveType	WarningActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(WarningActive)
	));
};
const DWORD FTD_FID_RtnWarningActiveChange=0x5468;

///通用操作
class CFTDReqQryGeneralOperateField
{
public:
	///通用操作类型
	CGeneralOperateTypeType	GeneralOperateType;
	///通用操作表
	CGeneralOperateTableType	GeneralOperateTable;
	///通用操作选项
	CGeneralOperateOptionType	GeneralOperateOption;
	///通用操作集
	CGeneralOperateSetType	GeneralOperateSet;
	TYPE_DESCRIPTOR((
		TYPE_DESC(GeneralOperateType)
		,
		TYPE_DESC(GeneralOperateTable)
		,
		TYPE_DESC(GeneralOperateOption)
		,
		TYPE_DESC(GeneralOperateSet)
	));
};
const DWORD FTD_FID_ReqQryGeneralOperate=0x5469;

///通用操作
class CFTDRspQryGeneralOperateField
{
public:
	///通用操作类型
	CGeneralOperateTypeType	GeneralOperateType;
	///通用操作表
	CGeneralOperateTableType	GeneralOperateTable;
	///通用操作选项
	CGeneralOperateOptionType	GeneralOperateOption;
	///通用操作集
	CGeneralOperateSetType	GeneralOperateSet;
	TYPE_DESCRIPTOR((
		TYPE_DESC(GeneralOperateType)
		,
		TYPE_DESC(GeneralOperateTable)
		,
		TYPE_DESC(GeneralOperateOption)
		,
		TYPE_DESC(GeneralOperateSet)
	));
};
const DWORD FTD_FID_RspQryGeneralOperate=0x5470;

///通用操作
class CFTDRtnGeneralOperateField
{
public:
	///通用操作类型
	CGeneralOperateTypeType	GeneralOperateType;
	///通用操作表
	CGeneralOperateTableType	GeneralOperateTable;
	///通用操作选项
	CGeneralOperateOptionType	GeneralOperateOption;
	///通用操作集
	CGeneralOperateSetType	GeneralOperateSet;
	TYPE_DESCRIPTOR((
		TYPE_DESC(GeneralOperateType)
		,
		TYPE_DESC(GeneralOperateTable)
		,
		TYPE_DESC(GeneralOperateOption)
		,
		TYPE_DESC(GeneralOperateSet)
	));
};
const DWORD FTD_FID_RtnGeneralOperate=0x5471;

///网络设备连接关系请求
class CFTDReqQryNetDeviceLinkedField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///人为划分的职能区域
	CTypeObjectIDType	FuctionArea;
	///IP码
	CVolumeType	IPDECODE;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(FuctionArea)
		,
		TYPE_DESC(IPDECODE)
		,
		TYPE_DESC(ObjectID)
	));
};
const DWORD FTD_FID_ReqQryNetDeviceLinked=0x5472;

///网络设备连接关系
class CFTDRspQryNetDeviceLinkedField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备ID
	CVolumeType	NetDeviceID;
	///设备端口ID
	CVolumeType	NetPortID;
	///监控对象
	CNetObjectIDType	NetObjectID;
	///监控对象端口类型
	CNetDevicePortTypeType	NetPortType;
	///连接设备ID
	CVolumeType	LinkNetDeviceID;
	///连接设备端口ID
	CVolumeType	LinkNetPortID;
	///连接对象
	CNetObjectIDType	LinkNetObjectID;
	///连接对象端口类型
	CNetDevicePortTypeType	LinkNetPortType;
	///链接来源
	CVolumeType	LinkSource;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(NetDeviceID)
		,
		TYPE_DESC(NetPortID)
		,
		TYPE_DESC(NetObjectID)
		,
		TYPE_DESC(NetPortType)
		,
		TYPE_DESC(LinkNetDeviceID)
		,
		TYPE_DESC(LinkNetPortID)
		,
		TYPE_DESC(LinkNetObjectID)
		,
		TYPE_DESC(LinkNetPortType)
		,
		TYPE_DESC(LinkSource)
	));
};
const DWORD FTD_FID_RspQryNetDeviceLinked=0x5473;

///网络设备连接关系
class CFTDRtnNetDeviceLinkedField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备ID
	CVolumeType	NetDeviceID;
	///设备端口ID
	CVolumeType	NetPortID;
	///监控对象
	CNetObjectIDType	NetObjectID;
	///监控对象端口类型
	CNetDevicePortTypeType	NetPortType;
	///连接设备ID
	CVolumeType	LinkNetDeviceID;
	///连接设备端口ID
	CVolumeType	LinkNetPortID;
	///连接对象
	CNetObjectIDType	LinkNetObjectID;
	///连接对象端口类型
	CNetDevicePortTypeType	LinkNetPortType;
	///链接来源
	CVolumeType	LinkSource;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(NetDeviceID)
		,
		TYPE_DESC(NetPortID)
		,
		TYPE_DESC(NetObjectID)
		,
		TYPE_DESC(NetPortType)
		,
		TYPE_DESC(LinkNetDeviceID)
		,
		TYPE_DESC(LinkNetPortID)
		,
		TYPE_DESC(LinkNetObjectID)
		,
		TYPE_DESC(LinkNetPortType)
		,
		TYPE_DESC(LinkSource)
	));
};
const DWORD FTD_FID_RtnNetDeviceLinked=0x5474;

///交易系统登录信息请求
class CFTDReqQryTradeUserLoginStatField
{
public:
	///监控对象
	CTypeObjectIDType	ObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
	));
};
const DWORD FTD_FID_ReqQryTradeUserLoginStat=0x5475;

///交易系统登录信息
class CFTDRspQryTradeUserLoginStatField
{
public:
	///登录日期
	CDateType	MonDate;
	///登录时间
	CTimeType	MonTime;
	///监控对象
	CTypeObjectIDType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///前置机名
	CTypeObjectIDType	FrontId;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(FrontId)
	));
};
const DWORD FTD_FID_RspQryTradeUserLoginStat=0x5476;

///交易系统前置报单响应信息
class CFTDReqQryTradeFrontOrderRttStatField
{
public:
	///前置对象
	CTypeObjectIDType	ObjectID;
	///报单日期
	CDateType	MonDate;
	///报单查询起始时间
	CTimeType	MonStartTime;
	///报单查询结束时间
	CTimeType	MonEndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonStartTime)
		,
		TYPE_DESC(MonEndTime)
	));
};
const DWORD FTD_FID_ReqQryTradeFrontOrderRttStat=0x5477;

///交易系统前置报单响应信息
class CFTDRspQryTradeFrontOrderRttStatField
{
public:
	///报单日期
	CDateType	MonDate;
	///报单时间
	CTimeType	MonTime;
	///前置对象
	CTypeObjectIDType	ObjectID;
	///报单量
	CLargeNumberType	OrderCount;
	///报单响应时间和
	CLargeNumberType	OrderRttSum;
	///最大报单响应时间
	CVolumeType	OrderMaxRtt;
	///最小报单响应时间
	CVolumeType	OrderMinRtt;
	///1秒内响应时间均差
	CVolumeType	OrderRttSqu;
	///1秒内响应时间分布
	CNumberListsType	OrderRttCutDistrib;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(OrderCount)
		,
		TYPE_DESC(OrderRttSum)
		,
		TYPE_DESC(OrderMaxRtt)
		,
		TYPE_DESC(OrderMinRtt)
		,
		TYPE_DESC(OrderRttSqu)
		,
		TYPE_DESC(OrderRttCutDistrib)
	));
};
const DWORD FTD_FID_RspQryTradeFrontOrderRttStat=0x5478;

///交易系统前置报单响应信息
class CFTDRtnTradeFrontOrderRttStatField
{
public:
	///报单日期
	CDateType	MonDate;
	///报单时间
	CTimeType	MonTime;
	///前置对象
	CTypeObjectIDType	ObjectID;
	///报单量
	CLargeNumberType	OrderCount;
	///报单响应时间和
	CLargeNumberType	OrderRttSum;
	///最大报单响应时间
	CVolumeType	OrderMaxRtt;
	///最小报单响应时间
	CVolumeType	OrderMinRtt;
	///1秒内响应时间均差
	CVolumeType	OrderRttSqu;
	///1秒内响应时间分布
	CNumberListsType	OrderRttCutDistrib;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(OrderCount)
		,
		TYPE_DESC(OrderRttSum)
		,
		TYPE_DESC(OrderMaxRtt)
		,
		TYPE_DESC(OrderMinRtt)
		,
		TYPE_DESC(OrderRttSqu)
		,
		TYPE_DESC(OrderRttCutDistrib)
	));
};
const DWORD FTD_FID_RtnTradeFrontOrderRttStat=0x5479;

///会员席位交易状态
class CFTDReqQryParticTradeOrderStatesField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///报单日期
	CDateType	MonDate;
	///报单查询起始时间
	CTimeType	MonStartTime;
	///报单查询结束时间
	CTimeType	MonEndTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonStartTime)
		,
		TYPE_DESC(MonEndTime)
	));
};
const DWORD FTD_FID_ReqQryParticTradeOrderStates=0x547a;

///会员席位交易状态
class CFTDRspQryParticTradeOrderStatesField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///报单统计日期
	CDateType	MonDate;
	///报单统计时间
	CTimeType	MonTime;
	///统计时长(sec)
	CVolumeType	StaticWidth;
	///前置ID
	CVolumeType	FrontID;
	///报单数
	CVolumeType	OrderCount;
	///撤单数
	CVolumeType	CancleCount;
	///查询数
	CVolumeType	QueryCount;
	///成交数
	CVolumeType	TradeCount;
	///成交金额
	CVolumeType	TradeMoney;
	///最大报单数
	CVolumeType	OrderCntMax;
	///最大撤单数
	CVolumeType	CancleCntMax;
	///最大查询数
	CVolumeType	QueryCntMax;
	///最大成交数
	CVolumeType	TradeCntMax;
	///最大成交金额
	CVolumeType	TradeMoneyMax;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(StaticWidth)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(OrderCount)
		,
		TYPE_DESC(CancleCount)
		,
		TYPE_DESC(QueryCount)
		,
		TYPE_DESC(TradeCount)
		,
		TYPE_DESC(TradeMoney)
		,
		TYPE_DESC(OrderCntMax)
		,
		TYPE_DESC(CancleCntMax)
		,
		TYPE_DESC(QueryCntMax)
		,
		TYPE_DESC(TradeCntMax)
		,
		TYPE_DESC(TradeMoneyMax)
	));
};
const DWORD FTD_FID_RspQryParticTradeOrderStates=0x547b;

///会员席位交易状态
class CFTDRtnParticTradeOrderStatesField
{
public:
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易用户代码
	CUserIDType	UserID;
	///报单统计日期
	CDateType	MonDate;
	///报单统计时间
	CTimeType	MonTime;
	///统计时长(sec)
	CVolumeType	StaticWidth;
	///前置ID
	CVolumeType	FrontID;
	///报单数
	CVolumeType	OrderCount;
	///撤单数
	CVolumeType	CancleCount;
	///查询数
	CVolumeType	QueryCount;
	///成交数
	CVolumeType	TradeCount;
	///成交金额
	CVolumeType	TradeMoney;
	///最大报单数
	CVolumeType	OrderCntMax;
	///最大撤单数
	CVolumeType	CancleCntMax;
	///最大查询数
	CVolumeType	QueryCntMax;
	///最大成交数
	CVolumeType	TradeCntMax;
	///最大成交金额
	CVolumeType	TradeMoneyMax;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(StaticWidth)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(OrderCount)
		,
		TYPE_DESC(CancleCount)
		,
		TYPE_DESC(QueryCount)
		,
		TYPE_DESC(TradeCount)
		,
		TYPE_DESC(TradeMoney)
		,
		TYPE_DESC(OrderCntMax)
		,
		TYPE_DESC(CancleCntMax)
		,
		TYPE_DESC(QueryCntMax)
		,
		TYPE_DESC(TradeCntMax)
		,
		TYPE_DESC(TradeMoneyMax)
	));
};
const DWORD FTD_FID_RtnParticTradeOrderStates=0x547c;

///系统路由信息
class CFTDReqQryRouterInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryRouterInfo=0x547d;

///系统路由信息
class CFTDRspQryRouterInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///设备接口名
	CTypeCommandType	Dev;
	///目标网段ip地址
	CIPAddressType	Destination;
	///网关ip地址
	CIPAddressType	Gateway;
	///掩码ip地址
	CIPAddressType	Mask;
	///网络状态
	CTypeLanStatusType	Flag;
	///关联计数
	CVolumeType	RefCnt;
	///使用计数
	CVolumeType	Use;
	///metric值
	CVolumeType	Metric;
	///mtu值
	CVolumeType	Mtu;
	///win值
	CVolumeType	Win;
	///rtt值
	CVolumeType	Rtt;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Dev)
		,
		TYPE_DESC(Destination)
		,
		TYPE_DESC(Gateway)
		,
		TYPE_DESC(Mask)
		,
		TYPE_DESC(Flag)
		,
		TYPE_DESC(RefCnt)
		,
		TYPE_DESC(Use)
		,
		TYPE_DESC(Metric)
		,
		TYPE_DESC(Mtu)
		,
		TYPE_DESC(Win)
		,
		TYPE_DESC(Rtt)
	));
};
const DWORD FTD_FID_RspQryRouterInfo=0x547e;

///系统路由信息
class CFTDRtnRouterInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///设备接口名
	CTypeCommandType	Dev;
	///目标网段ip地址
	CIPAddressType	Destination;
	///网关ip地址
	CIPAddressType	Gateway;
	///掩码ip地址
	CIPAddressType	Mask;
	///网络状态
	CTypeLanStatusType	Flag;
	///关联计数
	CVolumeType	RefCnt;
	///使用计数
	CVolumeType	Use;
	///metric值
	CVolumeType	Metric;
	///mtu值
	CVolumeType	Mtu;
	///win值
	CVolumeType	Win;
	///rtt值
	CVolumeType	Rtt;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Dev)
		,
		TYPE_DESC(Destination)
		,
		TYPE_DESC(Gateway)
		,
		TYPE_DESC(Mask)
		,
		TYPE_DESC(Flag)
		,
		TYPE_DESC(RefCnt)
		,
		TYPE_DESC(Use)
		,
		TYPE_DESC(Metric)
		,
		TYPE_DESC(Mtu)
		,
		TYPE_DESC(Win)
		,
		TYPE_DESC(Rtt)
	));
};
const DWORD FTD_FID_RtnRouterInfo=0x547f;

///磁盘I/O信息
class CFTDReqQryDiskIOField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryDiskIO=0x5480;

///磁盘I/O信息
class CFTDRspQryDiskIOField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///分区名
	CTypeCommandType	PartName;
	///每秒ReadMerge数
	CPriceType	ReadMerges;
	///每秒WriteMerge数
	CPriceType	WriteMerges;
	///每秒ReadIO数
	CPriceType	ReadIOs;
	///每秒WriteIO数
	CPriceType	WriteIOs;
	///每秒Read字节数
	CPriceType	ReadKBs;
	///每秒Write字节数
	CPriceType	WriteKBs;
	///Size值
	CPriceType	SizeVal;
	///Queue值
	CPriceType	QueueVal;
	///Svc_t值
	CPriceType	Svc_t;
	///繁忙百分率
	CRatioType	Busy;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(PartName)
		,
		TYPE_DESC(ReadMerges)
		,
		TYPE_DESC(WriteMerges)
		,
		TYPE_DESC(ReadIOs)
		,
		TYPE_DESC(WriteIOs)
		,
		TYPE_DESC(ReadKBs)
		,
		TYPE_DESC(WriteKBs)
		,
		TYPE_DESC(SizeVal)
		,
		TYPE_DESC(QueueVal)
		,
		TYPE_DESC(Svc_t)
		,
		TYPE_DESC(Busy)
	));
};
const DWORD FTD_FID_RspQryDiskIO=0x5481;

///磁盘I/O信息
class CFTDRtnDiskIOField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///分区名
	CTypeCommandType	PartName;
	///每秒ReadMerge数
	CPriceType	ReadMerges;
	///每秒WriteMerge数
	CPriceType	WriteMerges;
	///每秒ReadIO数
	CPriceType	ReadIOs;
	///每秒WriteIO数
	CPriceType	WriteIOs;
	///每秒Read字节数
	CPriceType	ReadKBs;
	///每秒Write字节数
	CPriceType	WriteKBs;
	///Size值
	CPriceType	SizeVal;
	///Queue值
	CPriceType	QueueVal;
	///Svc_t值
	CPriceType	Svc_t;
	///繁忙百分率
	CRatioType	Busy;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(PartName)
		,
		TYPE_DESC(ReadMerges)
		,
		TYPE_DESC(WriteMerges)
		,
		TYPE_DESC(ReadIOs)
		,
		TYPE_DESC(WriteIOs)
		,
		TYPE_DESC(ReadKBs)
		,
		TYPE_DESC(WriteKBs)
		,
		TYPE_DESC(SizeVal)
		,
		TYPE_DESC(QueueVal)
		,
		TYPE_DESC(Svc_t)
		,
		TYPE_DESC(Busy)
	));
};
const DWORD FTD_FID_RtnDiskIO=0x5482;

///系统状态信息
class CFTDReqQryStatInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///持续订阅标记
	CTypeKeepAliveType	KeepAlive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(StartDate)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(EndDate)
		,
		TYPE_DESC(EndTime)
		,
		TYPE_DESC(KeepAlive)
	));
};
const DWORD FTD_FID_ReqQryStatInfo=0x5483;

///系统状态信息
class CFTDRspQryStatInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///活跃进程数
	CVolumeType	ProcRun;
	///阻塞进程数
	CVolumeType	ProcBlk;
	///每秒由磁盘进入Swap的页面数
	CVolumeType	SwapIn;
	///每秒由Swap进入磁盘的页面数
	CVolumeType	SwapOut;
	///每秒从块设备读入的Block数
	CVolumeType	BlockIn;
	///每秒向块设备写入的Block数
	CVolumeType	BlockOut;
	///每秒设备中段次数
	CVolumeType	Inter;
	///每秒上下文切换次数
	CVolumeType	Context;
	///用户态CPU百分率
	CRatioType	CPUUser;
	///系统态CPU百分率
	CRatioType	CPUSys;
	///空闲态CPU百分率
	CRatioType	CPUIdle;
	///IO等待态CPU百分率
	CRatioType	CPUIOWait;
	///窃取态CPU百分率
	CRatioType	CPUSteal;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ProcRun)
		,
		TYPE_DESC(ProcBlk)
		,
		TYPE_DESC(SwapIn)
		,
		TYPE_DESC(SwapOut)
		,
		TYPE_DESC(BlockIn)
		,
		TYPE_DESC(BlockOut)
		,
		TYPE_DESC(Inter)
		,
		TYPE_DESC(Context)
		,
		TYPE_DESC(CPUUser)
		,
		TYPE_DESC(CPUSys)
		,
		TYPE_DESC(CPUIdle)
		,
		TYPE_DESC(CPUIOWait)
		,
		TYPE_DESC(CPUSteal)
	));
};
const DWORD FTD_FID_RspQryStatInfo=0x5484;

///系统状态信息
class CFTDRtnStatInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///活跃进程数
	CVolumeType	ProcRun;
	///阻塞进程数
	CVolumeType	ProcBlk;
	///每秒由磁盘进入Swap的页面数
	CVolumeType	SwapIn;
	///每秒由Swap进入磁盘的页面数
	CVolumeType	SwapOut;
	///每秒从块设备读入的Block数
	CVolumeType	BlockIn;
	///每秒向块设备写入的Block数
	CVolumeType	BlockOut;
	///每秒设备中段次数
	CVolumeType	Inter;
	///每秒上下文切换次数
	CVolumeType	Context;
	///用户态CPU百分率
	CRatioType	CPUUser;
	///系统态CPU百分率
	CRatioType	CPUSys;
	///空闲态CPU百分率
	CRatioType	CPUIdle;
	///IO等待态CPU百分率
	CRatioType	CPUIOWait;
	///窃取态CPU百分率
	CRatioType	CPUSteal;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(ProcRun)
		,
		TYPE_DESC(ProcBlk)
		,
		TYPE_DESC(SwapIn)
		,
		TYPE_DESC(SwapOut)
		,
		TYPE_DESC(BlockIn)
		,
		TYPE_DESC(BlockOut)
		,
		TYPE_DESC(Inter)
		,
		TYPE_DESC(Context)
		,
		TYPE_DESC(CPUUser)
		,
		TYPE_DESC(CPUSys)
		,
		TYPE_DESC(CPUIdle)
		,
		TYPE_DESC(CPUIOWait)
		,
		TYPE_DESC(CPUSteal)
	));
};
const DWORD FTD_FID_RtnStatInfo=0x5485;

///交易系统前置报单分布区间
class CFTDReqQryTradeOrderRttCutLineField
{
public:
	///区间生效日期
	CDateType	MonDate;
	///区间修改时间
	CTimeType	MonTime;
	///修改用户对象
	CTypeObjectIDType	UserName;
	///响应时间分布
	CNumberListsType	OrderRttCutLine;
	///统计颗粒度
	CVolumeType	OrderRttWidth;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(OrderRttCutLine)
		,
		TYPE_DESC(OrderRttWidth)
	));
};
const DWORD FTD_FID_ReqQryTradeOrderRttCutLine=0x5486;

///交易系统前置报单分布区间
class CFTDRspQryTradeOrderRttCutLineField
{
public:
	///区间生效日期
	CDateType	MonDate;
	///区间修改时间
	CTimeType	MonTime;
	///修改用户对象
	CTypeObjectIDType	UserName;
	///响应时间分布
	CNumberListsType	OrderRttCutLine;
	///统计颗粒度
	CVolumeType	OrderRttWidth;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(OrderRttCutLine)
		,
		TYPE_DESC(OrderRttWidth)
	));
};
const DWORD FTD_FID_RspQryTradeOrderRttCutLine=0x5487;

///交易系统前置报单分布区间
class CFTDRtnTradeOrderRttCutLineField
{
public:
	///区间生效日期
	CDateType	MonDate;
	///响应时间分布
	CNumberListsType	OrderRttCutLine;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(OrderRttCutLine)
	));
};
const DWORD FTD_FID_RtnTradeOrderRttCutLine=0x5488;

///会员客户信息
class CFTDReqQryClientInfoField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
	));
};
const DWORD FTD_FID_ReqQryClientInfo=0x5489;

///会员客户信息
class CFTDRspQryClientInfoField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	CTradingRoleType	TradingRole;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(IdentifiedCardNo)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RspQryClientInfo=0x548a;

///会员客户信息
class CFTDRtnClientInfoField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///客户名称
	CPartyNameType	ClientName;
	///证件类型
	CIdCardTypeType	IdentifiedCardType;
	///证件号码
	CIdentifiedCardNoType	IdentifiedCardNo;
	///交易角色
	CTradingRoleType	TradingRole;
	///客户类型
	CClientTypeType	ClientType;
	///是否活跃
	CBoolType	IsActive;
	///操作类型
	CDBOperationTypeType	OperationType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(IdentifiedCardType)
		,
		TYPE_DESC(IdentifiedCardNo)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(OperationType)
	));
};
const DWORD FTD_FID_RtnClientInfo=0x548b;

///事件描述请求
class CFTDReqQryEventDescriptionField
{
public:
	///处理ID号
	CEventDesIDType	EventDesID;
	///事件处理人
	CTypeObjectIDType	UserName;
	///事件处理日期
	CDateType	MonDate;
	///事件处理时间
	CTimeType	MonTime;
	///处理描述
	CDescriptionType	EventDes;
	TYPE_DESCRIPTOR((
		TYPE_DESC(EventDesID)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(EventDes)
	));
};
const DWORD FTD_FID_ReqQryEventDescription=0x548c;

///事件描述返回请求
class CFTDRspQryEventDescriptionField
{
public:
	///处理ID号
	CEventDesIDType	EventDesID;
	///事件处理人
	CTypeObjectIDType	UserName;
	///事件处理日期
	CDateType	MonDate;
	///事件处理时间
	CTimeType	MonTime;
	///处理描述
	CDescriptionType	EventDes;
	TYPE_DESCRIPTOR((
		TYPE_DESC(EventDesID)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(EventDes)
	));
};
const DWORD FTD_FID_RspQryEventDescription=0x548d;

///事件描述订阅
class CFTDRtnEventDescriptionField
{
public:
	///处理ID号
	CEventDesIDType	EventDesID;
	///事件处理人
	CTypeObjectIDType	UserName;
	///事件处理日期
	CDateType	MonDate;
	///事件处理时间
	CTimeType	MonTime;
	///处理描述
	CDescriptionType	EventDes;
	TYPE_DESCRIPTOR((
		TYPE_DESC(EventDesID)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(EventDes)
	));
};
const DWORD FTD_FID_RtnEventDescription=0x548e;

///前置唯一ID请求
class CFTDReqQryFrontUniqueIDField
{
public:
	///前置唯一ID编号
	CFrontIDType	FrontID;
	///前置编号全名
	CFrontSerialNumType	FrontName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(FrontName)
	));
};
const DWORD FTD_FID_ReqQryFrontUniqueID=0x548f;

///前置唯一ID返回
class CFTDRspQryFrontUniqueIDField
{
public:
	///前置唯一ID编号
	CFrontIDType	FrontID;
	///前置编号全名
	CFrontSerialNumType	FrontName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(FrontName)
	));
};
const DWORD FTD_FID_RspQryFrontUniqueID=0x5490;

///订阅前置唯一ID信息
class CFTDRtnFrontUniqueIDField
{
public:
	///前置唯一ID编号
	CFrontIDType	FrontID;
	///前置编号全名
	CFrontSerialNumType	FrontName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(FrontName)
	));
};
const DWORD FTD_FID_RtnFrontUniqueID=0x5491;

///会员线路地址变更请求
class CFTDReqQryNetPartyLinkAddrChangeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ID
	CVolumeType	RelationID;
	///变更前地址
	CNetAttrTypeType	OLDADDRESS;
	///变更后地址
	CNetAttrTypeType	NEWADDRESS;
	///操作人
	CCfgNameType	OPERATOR;
	///修改日期
	CDateType	MonDate;
	///修改时间
	CTimeType	MonTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(RelationID)
		,
		TYPE_DESC(OLDADDRESS)
		,
		TYPE_DESC(NEWADDRESS)
		,
		TYPE_DESC(OPERATOR)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
	));
};
const DWORD FTD_FID_ReqQryNetPartyLinkAddrChange=0x5492;

///会员线路地址变更回应
class CFTDRspQryNetPartyLinkAddrChangeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ID
	CVolumeType	RelationID;
	///变更前地址
	CNetAttrTypeType	OLDADDRESS;
	///变更后地址
	CNetAttrTypeType	NEWADDRESS;
	///操作人
	CCfgNameType	OPERATOR;
	///修改日期
	CDateType	MonDate;
	///修改时间
	CTimeType	MonTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(RelationID)
		,
		TYPE_DESC(OLDADDRESS)
		,
		TYPE_DESC(NEWADDRESS)
		,
		TYPE_DESC(OPERATOR)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
	));
};
const DWORD FTD_FID_RspQryNetPartyLinkAddrChange=0x5493;

///订阅会员线路地址变更信息
class CFTDRtnNetPartyLinkAddrChangeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ID
	CVolumeType	RelationID;
	///变更前地址
	CNetAttrTypeType	OLDADDRESS;
	///变更后地址
	CNetAttrTypeType	NEWADDRESS;
	///操作人
	CCfgNameType	OPERATOR;
	///修改日期
	CDateType	MonDate;
	///修改时间
	CTimeType	MonTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(RelationID)
		,
		TYPE_DESC(OLDADDRESS)
		,
		TYPE_DESC(NEWADDRESS)
		,
		TYPE_DESC(OPERATOR)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
	));
};
const DWORD FTD_FID_RtnNetPartyLinkAddrChange=0x5494;

///请求已删除会员列表信息
class CFTDReqQryNetDelPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_ReqQryNetDelPartyLinkInfo=0x5495;

///应答已删除会员列表信息
class CFTDRspQryNetDelPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_RspQryNetDelPartyLinkInfo=0x5496;

///订阅已删除会员列表信息
class CFTDRtnNetDelPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_RtnNetDelPartyLinkInfo=0x5497;

///请求网络性能排序
class CFTDReqQryPerformanceTopField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///监控指标类型
	CAttrTypeType	AttrType;
	///网络区域
	CNetAreaType	NetArea;
	///网络子区域
	CNetSubAreaType	NetSubArea;
	///查询关键字
	CKeyWordType	KeyWord;
	///所排序值类型
	CSortValueType	SortValue;
	///排序类型
	CSortTypeType	SortType;
	///查询时间类型
	CDuringTimeTypeType	DuringTimeType;
	///查询时间值
	CDuringTimeValueType	DuringTimeValue;
	///前N的值
	CTopNType	TopN;
	///性能排序结果
	CTopResultType	TopResult;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(NetArea)
		,
		TYPE_DESC(NetSubArea)
		,
		TYPE_DESC(KeyWord)
		,
		TYPE_DESC(SortValue)
		,
		TYPE_DESC(SortType)
		,
		TYPE_DESC(DuringTimeType)
		,
		TYPE_DESC(DuringTimeValue)
		,
		TYPE_DESC(TopN)
		,
		TYPE_DESC(TopResult)
	));
};
const DWORD FTD_FID_ReqQryPerformanceTop=0x5498;

///返回网络性能排序
class CFTDRspQryPerformanceTopField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///监控指标类型
	CAttrTypeType	AttrType;
	///网络区域
	CNetAreaType	NetArea;
	///网络子区域
	CNetSubAreaType	NetSubArea;
	///查询关键字
	CKeyWordType	KeyWord;
	///所排序值类型
	CSortValueType	SortValue;
	///排序类型
	CSortTypeType	SortType;
	///查询时间类型
	CDuringTimeTypeType	DuringTimeType;
	///查询时间值
	CDuringTimeValueType	DuringTimeValue;
	///前N的值
	CTopNType	TopN;
	///性能排序结果
	CTopResultType	TopResult;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(NetArea)
		,
		TYPE_DESC(NetSubArea)
		,
		TYPE_DESC(KeyWord)
		,
		TYPE_DESC(SortValue)
		,
		TYPE_DESC(SortType)
		,
		TYPE_DESC(DuringTimeType)
		,
		TYPE_DESC(DuringTimeValue)
		,
		TYPE_DESC(TopN)
		,
		TYPE_DESC(TopResult)
	));
};
const DWORD FTD_FID_RspQryPerformanceTop=0x5499;

///订阅网络性能排序
class CFTDRtnPerformanceTopField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///监控指标类型
	CAttrTypeType	AttrType;
	///网络区域
	CNetAreaType	NetArea;
	///网络子区域
	CNetSubAreaType	NetSubArea;
	///查询关键字
	CKeyWordType	KeyWord;
	///所排序值类型
	CSortValueType	SortValue;
	///排序类型
	CSortTypeType	SortType;
	///查询时间类型
	CDuringTimeTypeType	DuringTimeType;
	///查询时间值
	CDuringTimeValueType	DuringTimeValue;
	///前N的值
	CTopNType	TopN;
	///性能排序结果
	CTopResultType	TopResult;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(NetArea)
		,
		TYPE_DESC(NetSubArea)
		,
		TYPE_DESC(KeyWord)
		,
		TYPE_DESC(SortValue)
		,
		TYPE_DESC(SortType)
		,
		TYPE_DESC(DuringTimeType)
		,
		TYPE_DESC(DuringTimeValue)
		,
		TYPE_DESC(TopN)
		,
		TYPE_DESC(TopResult)
	));
};
const DWORD FTD_FID_RtnPerformanceTop=0x549a;

///请求合约状态切换
class CFTDReqQryInstrumentStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	CTimeType	EnterTime;
	///进入本状态原因
	CInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	CDateType	EnterDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(EnterTime)
		,
		TYPE_DESC(EnterReason)
		,
		TYPE_DESC(EnterDate)
	));
};
const DWORD FTD_FID_ReqQryInstrumentStatus=0x549b;

///返回合约状态切换
class CFTDRspQryInstrumentStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	CTimeType	EnterTime;
	///进入本状态原因
	CInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	CDateType	EnterDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(EnterTime)
		,
		TYPE_DESC(EnterReason)
		,
		TYPE_DESC(EnterDate)
	));
};
const DWORD FTD_FID_RspQryInstrumentStatus=0x549c;

///订阅合约状态切换
class CFTDRtnInstrumentStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///进入本状态时间
	CTimeType	EnterTime;
	///进入本状态原因
	CInstStatusEnterReasonType	EnterReason;
	///进入本状态日期
	CDateType	EnterDate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(EnterTime)
		,
		TYPE_DESC(EnterReason)
		,
		TYPE_DESC(EnterDate)
	));
};
const DWORD FTD_FID_RtnInstrumentStatus=0x549d;

///请求合约交易节信息
class CFTDReqQryCurrTradingSegmentAttrField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///交易阶段名称
	CTradingSegmentNameType	TradingSegmentName;
	///起始时间
	CTimeType	StartTime;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///提前天数
	CAdvanceDaysType	AdvanceDays;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(TradingSegmentName)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(AdvanceDays)
	));
};
const DWORD FTD_FID_ReqQryCurrTradingSegmentAttr=0x549e;

///返回合约交易节信息
class CFTDRspQryCurrTradingSegmentAttrField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///交易阶段名称
	CTradingSegmentNameType	TradingSegmentName;
	///起始时间
	CTimeType	StartTime;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///提前天数
	CAdvanceDaysType	AdvanceDays;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(TradingSegmentName)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(AdvanceDays)
	));
};
const DWORD FTD_FID_RspQryCurrTradingSegmentAttr=0x549f;

///订阅合约交易节信息
class CFTDRtnCurrTradingSegmentAttrField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///交易阶段名称
	CTradingSegmentNameType	TradingSegmentName;
	///起始时间
	CTimeType	StartTime;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///提前天数
	CAdvanceDaysType	AdvanceDays;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(TradingSegmentName)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(AdvanceDays)
	));
};
const DWORD FTD_FID_RtnCurrTradingSegmentAttr=0x54a0;

///实时网络对象请求
class CFTDReqQryRealTimeNetObjectAttrField
{
public:
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryRealTimeNetObjectAttr=0x8003;

///网络对象请求
class CFTDReqQryNetAreaField
{
public:
	///ID
	CVolumeType	ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
	));
};
const DWORD FTD_FID_ReqQryNetArea=0x8010;

///网络对象应答
class CFTDRspQryNetAreaField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetArea=0x8011;

///网络对象应答
class CFTDRtnNetAreaField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetArea=0x8012;

///网络对象请求
class CFTDReqQryNetSubAreaField
{
public:
	///ID
	CVolumeType	ID;
	///SysNetArea
	CVolumeType	SysNetAreaID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetAreaID)
	));
};
const DWORD FTD_FID_ReqQryNetSubArea=0x8013;

///网络对象应答
class CFTDRspQryNetSubAreaField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetAreaID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetSubArea=0x8014;

///网络对象应答
class CFTDRtnNetSubAreaField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetAreaID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetSubArea=0x8015;

///网络对象请求
class CFTDReqQryNetSubAreaIPField
{
public:
	///ID
	CVolumeType	ID;
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetAreaID)
		,
		TYPE_DESC(SysNetSubAreaID)
	));
};
const DWORD FTD_FID_ReqQryNetSubAreaIP=0x8016;

///网络对象应答
class CFTDRspQryNetSubAreaIPField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip地址
	CIPAddressType	IP;
	///掩码
	CIPAddressType	Mask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(IP)
		,
		TYPE_DESC(Mask)
	));
};
const DWORD FTD_FID_RspQryNetSubAreaIP=0x8017;

///网络对象应答
class CFTDRtnNetSubAreaIPField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip地址
	CIPAddressType	IP;
	///掩码
	CIPAddressType	Mask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(IP)
		,
		TYPE_DESC(Mask)
	));
};
const DWORD FTD_FID_RtnNetSubAreaIP=0x8018;

///网络设备探测请求
class CFTDReqQryNetDeviceDetectField
{
public:
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip地址
	CIPAddressType	IP;
	///掩码
	CIPAddressType	Mask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SysNetAreaID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(IP)
		,
		TYPE_DESC(Mask)
	));
};
const DWORD FTD_FID_ReqQryNetDeviceDetect=0x8019;

///网络设备查询请求
class CFTDReqQryNetDeviceRequestField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///人为划分的职能区域
	CTypeObjectIDType	FuctionArea;
	///IP码
	CVolumeType	IPDECODE;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(FuctionArea)
		,
		TYPE_DESC(IPDECODE)
	));
};
const DWORD FTD_FID_ReqQryNetDeviceRequest=0x8020;

///网络设备
class CFTDRspQryNetDeviceField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///分类ID  
	CVolumeType	CATEGORY_ID;
	///人为划分的职能区域  
	CTypeObjectIDType	FuctionArea;
	///IP地址  
	CIPAddressType	IPADDR;
	///IP码    
	CVolumeType	IPDECODE;
	///设备名称 
	CNetObjectIDType	NAME;
	///             
	CVolumeType	PORTNUMBER;
	///          
	CTypeObjectIDType	CONFIGFILE;
	///共同体名  
	CTypeObjectIDType	RCOMMUNITY;
	///snmp版本     
	CVolumeType	SNMPVERSION;
	///ramsize(B)   
	CVolumeType	RAMSIZE;
	///falshsize(B) 
	CVolumeType	FLASHSIZE;
	///nvramsize(B) 
	CVolumeType	NVRAMSIZE;
	///所属机柜
	CVolumeType	CABINET_ID;
	///
	CVolumeType	ROOM_ID;
	///软件版本
	CVolumeType	IOSVERSION_ID;
	///系统描述
	CNetAttrTypeType	DESCRIPTION;
	///登录用户名
	CTypeObjectIDType	USERNAME;
	///登录密码
	CNetAttrTypeType	PASSWD;
	///enable密码
	CNetAttrTypeType	ENPASSWD;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///配置备份协议
	CVolumeType	CFGSAVETYPE;
	///设备型号
	CNetObjectIDType	DEVICETYPE;
	///是否短信告警
	CVolumeType	SENDSMS;
	///是否自动snmp探测
	CVolumeType	ISSNMP;
	///槽位数
	CVolumeType	SLOTNUM;
	///是否自动ping
	CVolumeType	ISPING;
	///端口数量
	CVolumeType	IFNUM;
	///巡检分区
	CVolumeType	APPLICATION_ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(CATEGORY_ID)
		,
		TYPE_DESC(FuctionArea)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(IPDECODE)
		,
		TYPE_DESC(NAME)
		,
		TYPE_DESC(PORTNUMBER)
		,
		TYPE_DESC(CONFIGFILE)
		,
		TYPE_DESC(RCOMMUNITY)
		,
		TYPE_DESC(SNMPVERSION)
		,
		TYPE_DESC(RAMSIZE)
		,
		TYPE_DESC(FLASHSIZE)
		,
		TYPE_DESC(NVRAMSIZE)
		,
		TYPE_DESC(CABINET_ID)
		,
		TYPE_DESC(ROOM_ID)
		,
		TYPE_DESC(IOSVERSION_ID)
		,
		TYPE_DESC(DESCRIPTION)
		,
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(PASSWD)
		,
		TYPE_DESC(ENPASSWD)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(CFGSAVETYPE)
		,
		TYPE_DESC(DEVICETYPE)
		,
		TYPE_DESC(SENDSMS)
		,
		TYPE_DESC(ISSNMP)
		,
		TYPE_DESC(SLOTNUM)
		,
		TYPE_DESC(ISPING)
		,
		TYPE_DESC(IFNUM)
		,
		TYPE_DESC(APPLICATION_ID)
	));
};
const DWORD FTD_FID_RspQryNetDevice=0x8021;

///网络设备
class CFTDRtnNetDeviceField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///分类ID  
	CVolumeType	CATEGORY_ID;
	///人为划分的职能区域  
	CTypeObjectIDType	FuctionArea;
	///IP地址  
	CIPAddressType	IPADDR;
	///IP码    
	CVolumeType	IPDECODE;
	///设备名称 
	CNetObjectIDType	NAME;
	///             
	CVolumeType	PORTNUMBER;
	///          
	CTypeObjectIDType	CONFIGFILE;
	///共同体名  
	CTypeObjectIDType	RCOMMUNITY;
	///snmp版本     
	CVolumeType	SNMPVERSION;
	///ramsize(B)   
	CVolumeType	RAMSIZE;
	///falshsize(B) 
	CVolumeType	FLASHSIZE;
	///nvramsize(B) 
	CVolumeType	NVRAMSIZE;
	///所属机柜
	CVolumeType	CABINET_ID;
	///
	CVolumeType	ROOM_ID;
	///软件版本
	CVolumeType	IOSVERSION_ID;
	///系统描述
	CNetAttrTypeType	DESCRIPTION;
	///登录用户名
	CTypeObjectIDType	USERNAME;
	///登录密码
	CNetAttrTypeType	PASSWD;
	///enable密码
	CNetAttrTypeType	ENPASSWD;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///配置备份协议
	CVolumeType	CFGSAVETYPE;
	///设备型号
	CNetObjectIDType	DEVICETYPE;
	///是否短信告警
	CVolumeType	SENDSMS;
	///是否自动snmp探测
	CVolumeType	ISSNMP;
	///槽位数
	CVolumeType	SLOTNUM;
	///是否自动ping
	CVolumeType	ISPING;
	///端口数量
	CVolumeType	IFNUM;
	///巡检分区
	CVolumeType	APPLICATION_ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(CATEGORY_ID)
		,
		TYPE_DESC(FuctionArea)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(IPDECODE)
		,
		TYPE_DESC(NAME)
		,
		TYPE_DESC(PORTNUMBER)
		,
		TYPE_DESC(CONFIGFILE)
		,
		TYPE_DESC(RCOMMUNITY)
		,
		TYPE_DESC(SNMPVERSION)
		,
		TYPE_DESC(RAMSIZE)
		,
		TYPE_DESC(FLASHSIZE)
		,
		TYPE_DESC(NVRAMSIZE)
		,
		TYPE_DESC(CABINET_ID)
		,
		TYPE_DESC(ROOM_ID)
		,
		TYPE_DESC(IOSVERSION_ID)
		,
		TYPE_DESC(DESCRIPTION)
		,
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(PASSWD)
		,
		TYPE_DESC(ENPASSWD)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(CFGSAVETYPE)
		,
		TYPE_DESC(DEVICETYPE)
		,
		TYPE_DESC(SENDSMS)
		,
		TYPE_DESC(ISSNMP)
		,
		TYPE_DESC(SLOTNUM)
		,
		TYPE_DESC(ISPING)
		,
		TYPE_DESC(IFNUM)
		,
		TYPE_DESC(APPLICATION_ID)
	));
};
const DWORD FTD_FID_RtnNetDevice=0x8022;

///网络设备探测请求应答
class CFTDRspQryNetDeviceDetectField
{
public:
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip地址
	CIPAddressType	IP;
	///掩码
	CIPAddressType	Mask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SysNetAreaID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(IP)
		,
		TYPE_DESC(Mask)
	));
};
const DWORD FTD_FID_RspQryNetDeviceDetect=0x8023;

///大楼查询
class CFTDReqQryNetBuildingField
{
public:
	///ID
	CVolumeType	ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
	));
};
const DWORD FTD_FID_ReqQryNetBuilding=0x8024;

///大楼
class CFTDRspQryNetBuildingField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetBuilding=0x8025;

///大楼
class CFTDRtnNetBuildingField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetBuilding=0x8026;

///机房查询
class CFTDReqQryNetRoomField
{
public:
	///ID
	CVolumeType	ID;
	///SysNetBuildingID
	CVolumeType	SysNetBuildingID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetBuildingID)
	));
};
const DWORD FTD_FID_ReqQryNetRoom=0x8027;

///机房
class CFTDRspQryNetRoomField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///大楼
	CVolumeType	SysNetBuildingID;
	///机房中文名
	CTypeObjectIDType	CName;
	///机房英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetBuildingID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetRoom=0x8028;

///机房
class CFTDRtnNetRoomField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///大楼
	CVolumeType	SysNetBuildingID;
	///机房中文名
	CTypeObjectIDType	CName;
	///机房英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetBuildingID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetRoom=0x8029;

///机柜
class CFTDReqQryNetCabinetsField
{
public:
	///ID
	CVolumeType	ID;
	///SysNetRoomID
	CVolumeType	SysNetRoomID;
	///SysNetBuildingID
	CVolumeType	SysNetBuildingID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetRoomID)
		,
		TYPE_DESC(SysNetBuildingID)
	));
};
const DWORD FTD_FID_ReqQryNetCabinets=0x8030;

///机柜
class CFTDRspQryNetCabinetsField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetRoomID
	CVolumeType	SysNetRoomID;
	///SysNetBuildingID
	CVolumeType	SysNetBuildingID;
	///机房中文名
	CTypeObjectIDType	CName;
	///机房英文名
	CTypeObjectIDType	EName;
	///机柜类型
	CTypeObjectIDType	CabinetsType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetRoomID)
		,
		TYPE_DESC(SysNetBuildingID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(CabinetsType)
	));
};
const DWORD FTD_FID_RspQryNetCabinets=0x8031;

///机柜
class CFTDRtnNetCabinetsField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetRoomID
	CVolumeType	SysNetRoomID;
	///SysNetBuildingID
	CVolumeType	SysNetBuildingID;
	///机房中文名
	CTypeObjectIDType	CName;
	///机房英文名
	CTypeObjectIDType	EName;
	///机柜类型
	CTypeObjectIDType	CabinetsType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetRoomID)
		,
		TYPE_DESC(SysNetBuildingID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(CabinetsType)
	));
};
const DWORD FTD_FID_RtnNetCabinets=0x8032;

///OID
class CFTDReqQryNetOIDField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///单位
	CTypeObjectIDType	Unit;
	///是否标量标志
	CVolumeType	isTheTable;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(OID)
		,
		TYPE_DESC(Unit)
		,
		TYPE_DESC(isTheTable)
	));
};
const DWORD FTD_FID_ReqQryNetOID=0x8033;

///OID
class CFTDRspQryNetOIDField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///单位
	CTypeObjectIDType	Unit;
	///是否标量标志
	CVolumeType	isTheTable;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(OID)
		,
		TYPE_DESC(Unit)
		,
		TYPE_DESC(isTheTable)
	));
};
const DWORD FTD_FID_RspQryNetOID=0x8034;

///OID
class CFTDRtnNetOIDField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///单位
	CTypeObjectIDType	Unit;
	///是否标量标志
	CVolumeType	isTheTable;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(OID)
		,
		TYPE_DESC(Unit)
		,
		TYPE_DESC(isTheTable)
	));
};
const DWORD FTD_FID_RtnNetOID=0x8035;

///时间策略
class CFTDReqQryNetTimePolicyField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///时间策略中文名
	CTypeObjectIDType	CName;
	///时间策略英文名
	CTypeObjectIDType	EName;
	///策略类型
	CVolumeType	PolicyType;
	///策略项配置串
	CPolicyStringTypeType	PolicyString;
	///交易日限制
	CVolumeType	TradingDay;
	///策略项描述
	CNetAttrTypeType	Description;
	///操作类型
	CVolumeType	Operation;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(PolicyType)
		,
		TYPE_DESC(PolicyString)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(Operation)
	));
};
const DWORD FTD_FID_ReqQryNetTimePolicy=0x8036;

///时间策略
class CFTDRspQryNetTimePolicyField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///时间策略中文名
	CTypeObjectIDType	CName;
	///时间策略英文名
	CTypeObjectIDType	EName;
	///策略类型
	CVolumeType	PolicyType;
	///策略项配置串
	CPolicyStringTypeType	PolicyString;
	///交易日限制
	CVolumeType	TradingDay;
	///策略项描述
	CNetAttrTypeType	Description;
	///操作类型
	CVolumeType	Operation;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(PolicyType)
		,
		TYPE_DESC(PolicyString)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(Operation)
	));
};
const DWORD FTD_FID_RspQryNetTimePolicy=0x8037;

///时间策略
class CFTDRtnNetTimePolicyField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///时间策略中文名
	CTypeObjectIDType	CName;
	///时间策略英文名
	CTypeObjectIDType	EName;
	///策略类型
	CVolumeType	PolicyType;
	///策略项配置串
	CPolicyStringTypeType	PolicyString;
	///交易日限制
	CVolumeType	TradingDay;
	///策略项描述
	CNetAttrTypeType	Description;
	///操作类型
	CVolumeType	Operation;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(PolicyType)
		,
		TYPE_DESC(PolicyString)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(Operation)
	));
};
const DWORD FTD_FID_RtnNetTimePolicy=0x8038;

///采集任务查询
class CFTDReqQryNetGatherTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	///返回类型
	CVolumeType	DataType;
	///类型标识
	CVolumeType	TypeFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
		,
		TYPE_DESC(DataType)
		,
		TYPE_DESC(TypeFlag)
	));
};
const DWORD FTD_FID_ReqQryNetGatherTask=0x8039;

///采集任务
class CFTDRspQryNetGatherTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	///返回类型
	CVolumeType	DataType;
	///类型标识
	CVolumeType	TypeFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
		,
		TYPE_DESC(DataType)
		,
		TYPE_DESC(TypeFlag)
	));
};
const DWORD FTD_FID_RspQryNetGatherTask=0x8040;

///采集任务
class CFTDRtnNetGatherTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	///返回类型
	CVolumeType	DataType;
	///类型标识
	CVolumeType	TypeFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
		,
		TYPE_DESC(DataType)
		,
		TYPE_DESC(TypeFlag)
	));
};
const DWORD FTD_FID_RtnNetGatherTask=0x8041;

///采集任务查询
class CFTDReqQryNetDeviceChgField
{
public:
	///设备ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	CNetObjectIDType	OldObjectID;
	///网络监控对象ID
	CNetObjectIDType	NewObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(OldObjectID)
		,
		TYPE_DESC(NewObjectID)
	));
};
const DWORD FTD_FID_ReqQryNetDeviceChg=0x8042;

///采集任务
class CFTDRspQryNetDeviceChgField
{
public:
	///设备ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	CNetObjectIDType	OldObjectID;
	///网络监控对象ID
	CNetObjectIDType	NewObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(OldObjectID)
		,
		TYPE_DESC(NewObjectID)
	));
};
const DWORD FTD_FID_RspQryNetDeviceChg=0x8043;

///采集任务
class CFTDRtnNetDeviceChgField
{
public:
	///设备ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	CNetObjectIDType	OldObjectID;
	///网络监控对象ID
	CNetObjectIDType	NewObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(OldObjectID)
		,
		TYPE_DESC(NewObjectID)
	));
};
const DWORD FTD_FID_RtnNetDeviceChg=0x8044;

///常用设备型号请求
class CFTDReqQryNetDeviceTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
	));
};
const DWORD FTD_FID_ReqQryNetDeviceType=0x8045;

///常用设备型号
class CFTDRspQryNetDeviceTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
	));
};
const DWORD FTD_FID_RspQryNetDeviceType=0x8046;

///常用设备型号
class CFTDRtnNetDeviceTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
	));
};
const DWORD FTD_FID_RtnNetDeviceType=0x8047;

///常用设备类别请求
class CFTDReqQryNetDeviceCategoryField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///类别中文名
	CTypeObjectIDType	CName;
	///类别英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_ReqQryNetDeviceCategory=0x8048;

///常用设备类别
class CFTDRspQryNetDeviceCategoryField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///类别中文名
	CTypeObjectIDType	CName;
	///类别英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetDeviceCategory=0x8049;

///常用设备类别
class CFTDRtnNetDeviceCategoryField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///类别中文名
	CTypeObjectIDType	CName;
	///类别英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetDeviceCategory=0x8050;

///设备厂商请求
class CFTDReqQryNetManufactoryField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商中文名
	CTypeObjectIDType	CName;
	///厂商英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_ReqQryNetManufactory=0x8051;

///设备厂商
class CFTDRspQryNetManufactoryField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商中文名
	CTypeObjectIDType	CName;
	///厂商英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetManufactory=0x8052;

///设备厂商
class CFTDRtnNetManufactoryField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商中文名
	CTypeObjectIDType	CName;
	///厂商英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetManufactory=0x8053;

///设备共同体请求
class CFTDReqQryNetCommunityField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP地址
	CIPAddressType	IPADDR;
	///共同体名
	CTypeObjectIDType	COMMUNITY;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(COMMUNITY)
	));
};
const DWORD FTD_FID_ReqQryNetCommunity=0x8054;

///设备共同体
class CFTDRspQryNetCommunityField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP地址
	CIPAddressType	IPADDR;
	///共同体名
	CTypeObjectIDType	COMMUNITY;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(COMMUNITY)
	));
};
const DWORD FTD_FID_RspQryNetCommunity=0x8055;

///设备共同体
class CFTDRtnNetCommunityField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP地址
	CIPAddressType	IPADDR;
	///共同体名
	CTypeObjectIDType	COMMUNITY;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(COMMUNITY)
	));
};
const DWORD FTD_FID_RtnNetCommunity=0x8056;

///端口类型请求
class CFTDReqQryNetPortTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文名
	CTypeObjectIDType	CName;
	///英文名
	CTypeObjectIDType	EName;
	///描述
	CTypeObjectIDType	Description;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Description)
	));
};
const DWORD FTD_FID_ReqQryNetPortType=0x8057;

///端口类型
class CFTDRspQryNetPortTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文名
	CTypeObjectIDType	CName;
	///英文名
	CTypeObjectIDType	EName;
	///描述
	CTypeObjectIDType	Description;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Description)
	));
};
const DWORD FTD_FID_RspQryNetPortType=0x8058;

///端口类型
class CFTDRtnNetPortTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文名
	CTypeObjectIDType	CName;
	///英文名
	CTypeObjectIDType	EName;
	///描述
	CTypeObjectIDType	Description;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Description)
	));
};
const DWORD FTD_FID_RtnNetPortType=0x8059;

///会员接入地点请求
class CFTDReqQryNetPartAccessSpotField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文名
	CTypeObjectIDType	CName;
	///英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_ReqQryNetPartAccessSpot=0x8060;

///会员接入地点
class CFTDRspQryNetPartAccessSpotField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文名
	CTypeObjectIDType	CName;
	///英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetPartAccessSpot=0x8061;

///会员接入地点
class CFTDRtnNetPartAccessSpotField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文名
	CTypeObjectIDType	CName;
	///英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetPartAccessSpot=0x8062;

///端口请求
class CFTDReqQryNetInterfaceField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///端口类型
	CVolumeType	IfType;
	///端口名
	CTypeObjectIDType	EName;
	///IP地址
	CIPAddressType	IpAddress;
	///掩码
	CIPAddressType	IpMask;
	///端口状态
	CVolumeType	IfStatus;
	///物理地址
	CTypeObjectIDType	MAC;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	CTypeObjectNameType	DeviceIndex;
	///是否轮询
	CVolumeType	isPolling;
	///描述
	CTypeObjectIDType	Description;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(IfType)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(IpAddress)
		,
		TYPE_DESC(IpMask)
		,
		TYPE_DESC(IfStatus)
		,
		TYPE_DESC(MAC)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(DeviceIndex)
		,
		TYPE_DESC(isPolling)
		,
		TYPE_DESC(Description)
	));
};
const DWORD FTD_FID_ReqQryNetInterface=0x8063;

///端口
class CFTDRspQryNetInterfaceField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///端口类型
	CVolumeType	IfType;
	///端口名
	CTypeObjectIDType	EName;
	///IP地址
	CIPAddressType	IpAddress;
	///掩码
	CIPAddressType	IpMask;
	///端口状态
	CVolumeType	IfStatus;
	///物理地址
	CTypeObjectIDType	MAC;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	CTypeObjectNameType	DeviceIndex;
	///是否轮询
	CVolumeType	isPolling;
	///描述
	CTypeObjectIDType	Description;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(IfType)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(IpAddress)
		,
		TYPE_DESC(IpMask)
		,
		TYPE_DESC(IfStatus)
		,
		TYPE_DESC(MAC)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(DeviceIndex)
		,
		TYPE_DESC(isPolling)
		,
		TYPE_DESC(Description)
	));
};
const DWORD FTD_FID_RspQryNetInterface=0x8064;

///端口
class CFTDRtnNetInterfaceField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///端口类型
	CVolumeType	IfType;
	///端口名
	CTypeObjectIDType	EName;
	///IP地址
	CIPAddressType	IpAddress;
	///掩码
	CIPAddressType	IpMask;
	///端口状态
	CVolumeType	IfStatus;
	///物理地址
	CTypeObjectIDType	MAC;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	CTypeObjectNameType	DeviceIndex;
	///是否轮询
	CVolumeType	isPolling;
	///描述
	CTypeObjectIDType	Description;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(IfType)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(IpAddress)
		,
		TYPE_DESC(IpMask)
		,
		TYPE_DESC(IfStatus)
		,
		TYPE_DESC(MAC)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(DeviceIndex)
		,
		TYPE_DESC(isPolling)
		,
		TYPE_DESC(Description)
	));
};
const DWORD FTD_FID_RtnNetInterface=0x8065;

///GeneralOID
class CFTDReqQryNetGeneralOIDField
{
public:
	///ID
	CVolumeType	ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
	));
};
const DWORD FTD_FID_ReqQryNetGeneralOID=0x8066;

///GeneralOID
class CFTDRspQryNetGeneralOIDField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///单位
	CTypeObjectIDType	Unit;
	///是否标量标志
	CVolumeType	isTheTable;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(OID)
		,
		TYPE_DESC(Unit)
		,
		TYPE_DESC(isTheTable)
	));
};
const DWORD FTD_FID_RspQryNetGeneralOID=0x8067;

///GeneralOID
class CFTDRtnNetGeneralOIDField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///单位
	CTypeObjectIDType	Unit;
	///是否标量标志
	CVolumeType	isTheTable;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(OID)
		,
		TYPE_DESC(Unit)
		,
		TYPE_DESC(isTheTable)
	));
};
const DWORD FTD_FID_RtnNetGeneralOID=0x8068;

///监控对象类别
class CFTDReqQryNetMonitorTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorType=0x8069;

///监控对象类别
class CFTDRspQryNetMonitorTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetMonitorType=0x8070;

///监控对象类别
class CFTDRtnNetMonitorTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetMonitorType=0x8071;

///指标统表
class CFTDReqQryNetMonitorAttrScopeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///指标中文名
	CNetAttrTypeType	CName;
	///指标英文名
	CNetAttrTypeType	EName;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorAttrScope=0x8072;

///指标统表
class CFTDRspQryNetMonitorAttrScopeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///指标中文名
	CNetAttrTypeType	CName;
	///指标英文名
	CNetAttrTypeType	EName;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RspQryNetMonitorAttrScope=0x8073;

///指标统表
class CFTDRtnNetMonitorAttrScopeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///指标中文名
	CNetAttrTypeType	CName;
	///指标英文名
	CNetAttrTypeType	EName;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RtnNetMonitorAttrScope=0x8074;

///监控指标表
class CFTDReqQryNetMonitorAttrTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///设备类别
	CVolumeType	MonitorType_ID;
	///网络监控指标ID
	CVolumeType	AttrType_ID;
	///厂商类型
	CTypeObjectIDType	MANUFACTORY;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(AttrType_ID)
		,
		TYPE_DESC(MANUFACTORY)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorAttrType=0x8075;

///监控指标表
class CFTDRspQryNetMonitorAttrTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///设备类别
	CVolumeType	MonitorType_ID;
	///网络监控指标ID
	CVolumeType	AttrType_ID;
	///厂商类型
	CTypeObjectIDType	MANUFACTORY;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(AttrType_ID)
		,
		TYPE_DESC(MANUFACTORY)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_RspQryNetMonitorAttrType=0x8076;

///监控指标表
class CFTDRtnNetMonitorAttrTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///设备类别
	CVolumeType	MonitorType_ID;
	///网络监控指标ID
	CVolumeType	AttrType_ID;
	///厂商类型
	CTypeObjectIDType	MANUFACTORY;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(AttrType_ID)
		,
		TYPE_DESC(MANUFACTORY)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_RtnNetMonitorAttrType=0x8077;

///监控对象指标表
class CFTDReqQryNetMonitorObjectAttrField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorObjectAttr=0x8078;

///监控对象指标表
class CFTDRspQryNetMonitorObjectAttrField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
	));
};
const DWORD FTD_FID_RspQryNetMonitorObjectAttr=0x8079;

///监控对象指标表
class CFTDRtnNetMonitorObjectAttrField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
	));
};
const DWORD FTD_FID_RtnNetMonitorObjectAttr=0x8080;

///职能区
class CFTDReqQryNetFuncAreaField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_ReqQryNetFuncArea=0x8081;

///职能区
class CFTDRspQryNetFuncAreaField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetFuncArea=0x8082;

///职能区
class CFTDRtnNetFuncAreaField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetFuncArea=0x8083;

///监控指令表
class CFTDReqQryNetMonitorCommandTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型ID
	CVolumeType	Manufactory_ID;
	///设备类别ID
	CVolumeType	MonitorType_ID;
	///设备型号ID
	CVolumeType	DeviceModle_ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///厂商类型
	CTypeObjectIDType	Manufactory;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///设备型号
	CTypeObjectIDType	DeviceModle;
	///动作族
	CTypeObjectIDType	ActionGroup;
	///指令码
	CNetAttrTypeType	Command;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceModle_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(DeviceModle)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(Command)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorCommandType=0x8084;

///监控指令表
class CFTDRspQryNetMonitorCommandTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型ID
	CVolumeType	Manufactory_ID;
	///设备类别ID
	CVolumeType	MonitorType_ID;
	///设备型号ID
	CVolumeType	DeviceModle_ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///厂商类型
	CTypeObjectIDType	Manufactory;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///设备型号
	CTypeObjectIDType	DeviceModle;
	///动作族
	CTypeObjectIDType	ActionGroup;
	///指令码
	CNetAttrTypeType	Command;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceModle_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(DeviceModle)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(Command)
	));
};
const DWORD FTD_FID_RspQryNetMonitorCommandType=0x8085;

///监控指令表
class CFTDRtnNetMonitorCommandTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型ID
	CVolumeType	Manufactory_ID;
	///设备类别ID
	CVolumeType	MonitorType_ID;
	///设备型号ID
	CVolumeType	DeviceModle_ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///厂商类型
	CTypeObjectIDType	Manufactory;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///设备型号
	CTypeObjectIDType	DeviceModle;
	///动作族
	CTypeObjectIDType	ActionGroup;
	///指令码
	CNetAttrTypeType	Command;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceModle_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(DeviceModle)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(Command)
	));
};
const DWORD FTD_FID_RtnNetMonitorCommandType=0x8086;

///动作族表
class CFTDReqQryNetMonitorActionGroupField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///动作族中文名
	CTypeObjectIDType	CName;
	///动作族英文名
	CTypeObjectIDType	EName;
	///动作类型码
	CVolumeType	ActionType;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(ActionType)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorActionGroup=0x8087;

///动作族表
class CFTDRspQryNetMonitorActionGroupField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///动作族中文名
	CTypeObjectIDType	CName;
	///动作族英文名
	CTypeObjectIDType	EName;
	///动作类型码
	CVolumeType	ActionType;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(ActionType)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RspQryNetMonitorActionGroup=0x8088;

///动作族表
class CFTDRtnNetMonitorActionGroupField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///动作族中文名
	CTypeObjectIDType	CName;
	///动作族英文名
	CTypeObjectIDType	EName;
	///动作类型码
	CVolumeType	ActionType;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(ActionType)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RtnNetMonitorActionGroup=0x8089;

///设备对象组表
class CFTDReqQryNetMonitorDeviceGroupField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备对象组中文名
	CTypeObjectIDType	CName;
	///设备对象组英文名
	CTypeObjectIDType	EName;
	///设备过滤条件
	CNetString512Type	Condition;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Condition)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorDeviceGroup=0x8090;

///设备对象组表
class CFTDRspQryNetMonitorDeviceGroupField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备对象组中文名
	CTypeObjectIDType	CName;
	///设备对象组英文名
	CTypeObjectIDType	EName;
	///设备过滤条件
	CNetString512Type	Condition;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Condition)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RspQryNetMonitorDeviceGroup=0x8091;

///设备对象组表
class CFTDRtnNetMonitorDeviceGroupField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备对象组中文名
	CTypeObjectIDType	CName;
	///设备对象组英文名
	CTypeObjectIDType	EName;
	///设备过滤条件
	CNetString512Type	Condition;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Condition)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RtnNetMonitorDeviceGroup=0x8092;

///任务信息表
class CFTDReqQryNetMonitorTaskInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///任务中文名
	CTypeObjectIDType	CName;
	///任务英文名
	CTypeObjectIDType	EName;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	CVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	CVolumeType	TimePolicy_ID;
	///任务优先级ID
	CVolumeType	TaskPriority_ID;
	///结果输出策略ID
	CVolumeType	OutputPolicy_ID;
	///任务动作族ID
	CVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	CGeneralResultType	EventExprStr;
	///设备对象组
	CTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	CTypeObjectIDType	ManagerGroup;
	///任务时间策略
	CTypeObjectIDType	TimePolicy;
	///任务优先级
	CTypeObjectIDType	TaskPriority;
	///结果输出策略
	CTypeObjectIDType	OutputPolicy;
	///任务动作族
	CTypeObjectIDType	ActionGroup;
	///任务有效性标识
	CVolumeType	ValidFlag;
	///任务状态标识
	CVolumeType	TaskStatus;
	///任务描述
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(ManagerGroup_ID)
		,
		TYPE_DESC(TimePolicy_ID)
		,
		TYPE_DESC(TaskPriority_ID)
		,
		TYPE_DESC(OutputPolicy_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(EventExprStr)
		,
		TYPE_DESC(DeviceGroup)
		,
		TYPE_DESC(ManagerGroup)
		,
		TYPE_DESC(TimePolicy)
		,
		TYPE_DESC(TaskPriority)
		,
		TYPE_DESC(OutputPolicy)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(ValidFlag)
		,
		TYPE_DESC(TaskStatus)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorTaskInfo=0x8093;

///任务信息表
class CFTDRspQryNetMonitorTaskInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///任务中文名
	CTypeObjectIDType	CName;
	///任务英文名
	CTypeObjectIDType	EName;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	CVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	CVolumeType	TimePolicy_ID;
	///任务优先级ID
	CVolumeType	TaskPriority_ID;
	///结果输出策略ID
	CVolumeType	OutputPolicy_ID;
	///任务动作族ID
	CVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	CGeneralResultType	EventExprStr;
	///设备对象组
	CTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	CTypeObjectIDType	ManagerGroup;
	///任务时间策略
	CTypeObjectIDType	TimePolicy;
	///任务优先级
	CTypeObjectIDType	TaskPriority;
	///结果输出策略
	CTypeObjectIDType	OutputPolicy;
	///任务动作族
	CTypeObjectIDType	ActionGroup;
	///任务有效性标识
	CVolumeType	ValidFlag;
	///任务状态标识
	CVolumeType	TaskStatus;
	///任务描述
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(ManagerGroup_ID)
		,
		TYPE_DESC(TimePolicy_ID)
		,
		TYPE_DESC(TaskPriority_ID)
		,
		TYPE_DESC(OutputPolicy_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(EventExprStr)
		,
		TYPE_DESC(DeviceGroup)
		,
		TYPE_DESC(ManagerGroup)
		,
		TYPE_DESC(TimePolicy)
		,
		TYPE_DESC(TaskPriority)
		,
		TYPE_DESC(OutputPolicy)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(ValidFlag)
		,
		TYPE_DESC(TaskStatus)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RspQryNetMonitorTaskInfo=0x8094;

///任务信息表
class CFTDRtnNetMonitorTaskInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///任务中文名
	CTypeObjectIDType	CName;
	///任务英文名
	CTypeObjectIDType	EName;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	CVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	CVolumeType	TimePolicy_ID;
	///任务优先级ID
	CVolumeType	TaskPriority_ID;
	///结果输出策略ID
	CVolumeType	OutputPolicy_ID;
	///任务动作族ID
	CVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	CGeneralResultType	EventExprStr;
	///设备对象组
	CTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	CTypeObjectIDType	ManagerGroup;
	///任务时间策略
	CTypeObjectIDType	TimePolicy;
	///任务优先级
	CTypeObjectIDType	TaskPriority;
	///结果输出策略
	CTypeObjectIDType	OutputPolicy;
	///任务动作族
	CTypeObjectIDType	ActionGroup;
	///任务有效性标识
	CVolumeType	ValidFlag;
	///任务状态标识
	CVolumeType	TaskStatus;
	///任务描述
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(ManagerGroup_ID)
		,
		TYPE_DESC(TimePolicy_ID)
		,
		TYPE_DESC(TaskPriority_ID)
		,
		TYPE_DESC(OutputPolicy_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(EventExprStr)
		,
		TYPE_DESC(DeviceGroup)
		,
		TYPE_DESC(ManagerGroup)
		,
		TYPE_DESC(TimePolicy)
		,
		TYPE_DESC(TaskPriority)
		,
		TYPE_DESC(OutputPolicy)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(ValidFlag)
		,
		TYPE_DESC(TaskStatus)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_RtnNetMonitorTaskInfo=0x8095;

///任务结果表
class CFTDReqQryNetMonitorTaskResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///任务ID
	CVolumeType	Task_ID;
	///执行次数
	CVolumeType	OperateTime;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///指令串
	CNetString256Type	InstructChain;
	///结果串
	CNetString1KType	ResultChain;
	///任务执行标识
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(Task_ID)
		,
		TYPE_DESC(OperateTime)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(ResultChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorTaskResult=0x8096;

///任务结果表
class CFTDRspQryNetMonitorTaskResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///任务ID
	CVolumeType	Task_ID;
	///执行次数
	CVolumeType	OperateTime;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///指令串
	CNetString256Type	InstructChain;
	///结果串
	CNetString1KType	ResultChain;
	///任务执行标识
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(Task_ID)
		,
		TYPE_DESC(OperateTime)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(ResultChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RspQryNetMonitorTaskResult=0x8097;

///任务结果表
class CFTDRtnNetMonitorTaskResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///任务ID
	CVolumeType	Task_ID;
	///执行次数
	CVolumeType	OperateTime;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///指令串
	CNetString256Type	InstructChain;
	///结果串
	CNetString1KType	ResultChain;
	///任务执行标识
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(Task_ID)
		,
		TYPE_DESC(OperateTime)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(ResultChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RtnNetMonitorTaskResult=0x8098;

///任务对象集
class CFTDReqQryNetMonitorTaskObjectSetField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///设备ID
	CVolumeType	Device_ID;
	///DataCenter
	CDataCenterFlagType	DataCenter;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(Device_ID)
		,
		TYPE_DESC(DataCenter)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorTaskObjectSet=0x8099;

///任务对象集
class CFTDRspQryNetMonitorTaskObjectSetField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///设备ID
	CVolumeType	Device_ID;
	///DataCenter
	CDataCenterFlagType	DataCenter;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(Device_ID)
		,
		TYPE_DESC(DataCenter)
	));
};
const DWORD FTD_FID_RspQryNetMonitorTaskObjectSet=0x8100;

///任务对象集
class CFTDRtnNetMonitorTaskObjectSetField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///设备ID
	CVolumeType	Device_ID;
	///DataCenter
	CDataCenterFlagType	DataCenter;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(Device_ID)
		,
		TYPE_DESC(DataCenter)
	));
};
const DWORD FTD_FID_RtnNetMonitorTaskObjectSet=0x8101;

///会员链路信息表
class CFTDReqQryNetPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_ReqQryNetPartyLinkInfo=0x8102;

///会员链路信息表
class CFTDRspQryNetPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_RspQryNetPartyLinkInfo=0x8103;

///会员链路信息表
class CFTDRtnNetPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_RtnNetPartyLinkInfo=0x8104;

///监控动作指标对照表
class CFTDReqQryNetMonitorActionAttrField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///监控对象ID
	CVolumeType	MonitorAttr_ID;
	///指标英文名
	CNetAttrTypeType	MonitorAttrName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(MonitorAttr_ID)
		,
		TYPE_DESC(MonitorAttrName)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorActionAttr=0x8105;

///监控动作指标对照表
class CFTDRspQryNetMonitorActionAttrField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///监控对象ID
	CVolumeType	MonitorAttr_ID;
	///指标英文名
	CNetAttrTypeType	MonitorAttrName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(MonitorAttr_ID)
		,
		TYPE_DESC(MonitorAttrName)
	));
};
const DWORD FTD_FID_RspQryNetMonitorActionAttr=0x8106;

///监控动作指标对照表
class CFTDRtnNetMonitorActionAttrField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///监控对象ID
	CVolumeType	MonitorAttr_ID;
	///指标英文名
	CNetAttrTypeType	MonitorAttrName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(MonitorAttr_ID)
		,
		TYPE_DESC(MonitorAttrName)
	));
};
const DWORD FTD_FID_RtnNetMonitorActionAttr=0x8107;

///模块
class CFTDReqQryNetModuleField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///名字
	CTypeObjectIDType	Name;
	///描述
	CNetObjectIDType	Description;
	///模块索引
	CVolumeType	ModuleIndex;
	///物理索引
	CVolumeType	EntPhyIndex;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(ModuleIndex)
		,
		TYPE_DESC(EntPhyIndex)
	));
};
const DWORD FTD_FID_ReqQryNetModule=0x8111;

///模块
class CFTDRspQryNetModuleField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///名字
	CTypeObjectIDType	Name;
	///描述
	CNetObjectIDType	Description;
	///模块索引
	CVolumeType	ModuleIndex;
	///物理索引
	CVolumeType	EntPhyIndex;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(ModuleIndex)
		,
		TYPE_DESC(EntPhyIndex)
	));
};
const DWORD FTD_FID_RspQryNetModule=0x8112;

///模块
class CFTDRtnNetModuleField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///名字
	CTypeObjectIDType	Name;
	///描述
	CNetObjectIDType	Description;
	///模块索引
	CVolumeType	ModuleIndex;
	///物理索引
	CVolumeType	EntPhyIndex;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(ModuleIndex)
		,
		TYPE_DESC(EntPhyIndex)
	));
};
const DWORD FTD_FID_RtnNetModule=0x8113;

///告警表达式信息表
class CFTDReqQryNetEventExprField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文事件名
	CNetObjectIDType	CNAME;
	///英文事件名
	CNetObjectIDType	ENAME;
	///事件级别
	CCfgNameType	WarningLEVEL;
	///事件类型
	CVolumeType	EventTypeID;
	///事件子类型
	CVolumeType	SubEventTypeID;
	///告警间隔时间
	CVolumeType	GIVEUPTIME;
	///控制定义项
	CGeneralResultType	CONTROL;
	///表达式定义项
	CGeneralResultType	EXPR;
	///事件简述
	CTypeObjectIDType	BRIEF;
	///事件描述项
	CNetAttrTypeType	DISCRIPTION;
	///消息组ID
	CVolumeType	MSGGROUP_ID;
	///管理员组ID
	CVolumeType	ADMINGROUP_ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CNAME)
		,
		TYPE_DESC(ENAME)
		,
		TYPE_DESC(WarningLEVEL)
		,
		TYPE_DESC(EventTypeID)
		,
		TYPE_DESC(SubEventTypeID)
		,
		TYPE_DESC(GIVEUPTIME)
		,
		TYPE_DESC(CONTROL)
		,
		TYPE_DESC(EXPR)
		,
		TYPE_DESC(BRIEF)
		,
		TYPE_DESC(DISCRIPTION)
		,
		TYPE_DESC(MSGGROUP_ID)
		,
		TYPE_DESC(ADMINGROUP_ID)
	));
};
const DWORD FTD_FID_ReqQryNetEventExpr=0x8114;

///告警表达式信息表
class CFTDRspQryNetEventExprField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文事件名
	CNetObjectIDType	CNAME;
	///英文事件名
	CNetObjectIDType	ENAME;
	///事件级别
	CCfgNameType	WarningLEVEL;
	///事件类型
	CVolumeType	EventTypeID;
	///事件子类型
	CVolumeType	SubEventTypeID;
	///告警间隔时间
	CVolumeType	GIVEUPTIME;
	///控制定义项
	CGeneralResultType	CONTROL;
	///表达式定义项
	CGeneralResultType	EXPR;
	///事件简述
	CTypeObjectIDType	BRIEF;
	///事件描述项
	CNetAttrTypeType	DISCRIPTION;
	///消息组ID
	CVolumeType	MSGGROUP_ID;
	///管理员组ID
	CVolumeType	ADMINGROUP_ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CNAME)
		,
		TYPE_DESC(ENAME)
		,
		TYPE_DESC(WarningLEVEL)
		,
		TYPE_DESC(EventTypeID)
		,
		TYPE_DESC(SubEventTypeID)
		,
		TYPE_DESC(GIVEUPTIME)
		,
		TYPE_DESC(CONTROL)
		,
		TYPE_DESC(EXPR)
		,
		TYPE_DESC(BRIEF)
		,
		TYPE_DESC(DISCRIPTION)
		,
		TYPE_DESC(MSGGROUP_ID)
		,
		TYPE_DESC(ADMINGROUP_ID)
	));
};
const DWORD FTD_FID_RspQryNetEventExpr=0x8115;

///告警表达式信息表
class CFTDRtnNetEventExprField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///中文事件名
	CNetObjectIDType	CNAME;
	///英文事件名
	CNetObjectIDType	ENAME;
	///事件级别
	CCfgNameType	WarningLEVEL;
	///事件类型
	CVolumeType	EventTypeID;
	///事件子类型
	CVolumeType	SubEventTypeID;
	///告警间隔时间
	CVolumeType	GIVEUPTIME;
	///控制定义项
	CGeneralResultType	CONTROL;
	///表达式定义项
	CGeneralResultType	EXPR;
	///事件简述
	CTypeObjectIDType	BRIEF;
	///事件描述项
	CNetAttrTypeType	DISCRIPTION;
	///消息组ID
	CVolumeType	MSGGROUP_ID;
	///管理员组ID
	CVolumeType	ADMINGROUP_ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CNAME)
		,
		TYPE_DESC(ENAME)
		,
		TYPE_DESC(WarningLEVEL)
		,
		TYPE_DESC(EventTypeID)
		,
		TYPE_DESC(SubEventTypeID)
		,
		TYPE_DESC(GIVEUPTIME)
		,
		TYPE_DESC(CONTROL)
		,
		TYPE_DESC(EXPR)
		,
		TYPE_DESC(BRIEF)
		,
		TYPE_DESC(DISCRIPTION)
		,
		TYPE_DESC(MSGGROUP_ID)
		,
		TYPE_DESC(ADMINGROUP_ID)
	));
};
const DWORD FTD_FID_RtnNetEventExpr=0x8116;

///事件类型
class CFTDReqQryNetEventTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件类型中文名
	CTypeObjectIDType	CName;
	///事件类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_ReqQryNetEventType=0x8117;

///事件类型
class CFTDRspQryNetEventTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件类型中文名
	CTypeObjectIDType	CName;
	///事件类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetEventType=0x8118;

///事件类型
class CFTDRtnNetEventTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件类型中文名
	CTypeObjectIDType	CName;
	///事件类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetEventType=0x8119;

///事件子类型
class CFTDReqQryNetSubEventTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件子类型中文名
	CTypeObjectIDType	CName;
	///事件子类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_ReqQryNetSubEventType=0x8120;

///事件子类型
class CFTDRspQryNetSubEventTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件子类型中文名
	CTypeObjectIDType	CName;
	///事件子类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RspQryNetSubEventType=0x8121;

///事件子类型
class CFTDRtnNetSubEventTypeField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件子类型中文名
	CTypeObjectIDType	CName;
	///事件子类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_RtnNetSubEventType=0x8122;

///事件级别
class CFTDReqQryNetEventLevelField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件级别中文名
	CTypeObjectIDType	CName;
	///事件级别英文名
	CTypeObjectIDType	EName;
	///事件级别描述项
	CNetAttrTypeType	DISCRIPTION;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DISCRIPTION)
	));
};
const DWORD FTD_FID_ReqQryNetEventLevel=0x8123;

///事件级别
class CFTDRspQryNetEventLevelField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件级别中文名
	CTypeObjectIDType	CName;
	///事件级别英文名
	CTypeObjectIDType	EName;
	///事件级别描述项
	CNetAttrTypeType	DISCRIPTION;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DISCRIPTION)
	));
};
const DWORD FTD_FID_RspQryNetEventLevel=0x8124;

///事件级别
class CFTDRtnNetEventLevelField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///事件级别中文名
	CTypeObjectIDType	CName;
	///事件级别英文名
	CTypeObjectIDType	EName;
	///事件级别描述项
	CNetAttrTypeType	DISCRIPTION;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DISCRIPTION)
	));
};
const DWORD FTD_FID_RtnNetEventLevel=0x8125;

///任务结果状态表
class CFTDReqQryNetMonitorTaskStatusResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///任务ID
	CVolumeType	Task_ID;
	///执行次数
	CVolumeType	OperateTime;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///任务执行标识
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(Task_ID)
		,
		TYPE_DESC(OperateTime)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorTaskStatusResult=0x8126;

///任务结果状态表
class CFTDRspQryNetMonitorTaskStatusResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///任务ID
	CVolumeType	Task_ID;
	///执行次数
	CVolumeType	OperateTime;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///任务执行标识
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(Task_ID)
		,
		TYPE_DESC(OperateTime)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RspQryNetMonitorTaskStatusResult=0x8127;

///任务结果状态表
class CFTDRtnNetMonitorTaskStatusResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///任务ID
	CVolumeType	Task_ID;
	///执行次数
	CVolumeType	OperateTime;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///任务执行标识
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(Task_ID)
		,
		TYPE_DESC(OperateTime)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RtnNetMonitorTaskStatusResult=0x8128;

///登陆配置服务的请求
class CFTDReqConfigLoginField
{
public:
	///DataCenter
	CDataCenterFlagType	DataCenter;
	///ID
	CVolumeType	ID;
	///HasConfig
	CVolumeType	HasConfig;
	///Authorization
	CAuthorizationInfoType	Authorization;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DataCenter)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(HasConfig)
		,
		TYPE_DESC(Authorization)
	));
};
const DWORD FTD_FID_ReqConfigLogin=0x8129;

///对登陆配置服务请求的响应
class CFTDRspQryConfigLoginField
{
public:
	///错误代码
	CErrorIDType	ErrorID;
	///错误信息
	CErrorMsgType	ErrorMsg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
	));
};
const DWORD FTD_FID_RspQryConfigLogin=0x8130;

///对当前登录配置的服务角色的响应
class CFTDRspServerTypeField
{
public:
	///IsMaster
	CVolumeType	IsMaster;
	TYPE_DESCRIPTOR((
		TYPE_DESC(IsMaster)
	));
};
const DWORD FTD_FID_RspServerType=0x8131;

///退出服务请求
class CFTDReqSysServerExitField
{
public:
	///Time
	CDateTimeType	Time;
	///Authorization
	CAuthorizationInfoType	Authorization;
	TYPE_DESCRIPTOR((
		TYPE_DESC(Time)
		,
		TYPE_DESC(Authorization)
	));
};
const DWORD FTD_FID_ReqSysServerExit=0x8150;

///设备配置表
class CFTDReqQryNetCfgFileField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///监控对象
	CNetObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///配置文件名
	CNetAttrTypeType	CfgFileName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CfgFileName)
	));
};
const DWORD FTD_FID_ReqQryNetCfgFile=0x8151;

///设备配置表
class CFTDRspQryNetCfgFileField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///监控对象
	CNetObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///配置文件名
	CNetAttrTypeType	CfgFileName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CfgFileName)
	));
};
const DWORD FTD_FID_RspQryNetCfgFile=0x8152;

///设备配置表
class CFTDRtnNetCfgFileField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///监控对象
	CNetObjectIDType	ObjectID;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///配置文件名
	CNetAttrTypeType	CfgFileName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CfgFileName)
	));
};
const DWORD FTD_FID_RtnNetCfgFile=0x8153;

///任务结果规则分析表
class CFTDReqQryNetMonitorDeviceTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令
	CNetString256Type	InstructChain;
	///指令别名
	CNetString128Type	InstructAlias;
	///指令参数串
	CNetString256Type	InstructArgs;
	///指标阀值串
	CNetString2KType	DefParamChain;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(InstructArgs)
		,
		TYPE_DESC(DefParamChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorDeviceTask=0x8154;

///任务结果规则分析表
class CFTDRspQryNetMonitorDeviceTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令
	CNetString256Type	InstructChain;
	///指令别名
	CNetString128Type	InstructAlias;
	///指令参数串
	CNetString256Type	InstructArgs;
	///指标阀值串
	CNetString2KType	DefParamChain;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(InstructArgs)
		,
		TYPE_DESC(DefParamChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RspQryNetMonitorDeviceTask=0x8155;

///任务结果规则分析表
class CFTDRtnNetMonitorDeviceTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令
	CNetString256Type	InstructChain;
	///指令别名
	CNetString128Type	InstructAlias;
	///指令参数串
	CNetString256Type	InstructArgs;
	///指标阀值串
	CNetString2KType	DefParamChain;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(InstructArgs)
		,
		TYPE_DESC(DefParamChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RtnNetMonitorDeviceTask=0x8156;

///任务指令指标集表
class CFTDReqQryNetMonitorTaskInstAttrsField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令别名
	CNetString128Type	InstructAlias;
	///设备型号
	CNetString128Type	DEVICETYPE;
	///指标串
	CNetString256Type	AttrsChain;
	///指标规则串
	CNetString512Type	DefRegularChain;
	///指标阀值串
	CNetString2KType	DefParamChain;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(DEVICETYPE)
		,
		TYPE_DESC(AttrsChain)
		,
		TYPE_DESC(DefRegularChain)
		,
		TYPE_DESC(DefParamChain)
	));
};
const DWORD FTD_FID_ReqQryNetMonitorTaskInstAttrs=0x8157;

///任务指令指标集表
class CFTDRspQryNetMonitorTaskInstAttrsField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令别名
	CNetString128Type	InstructAlias;
	///设备型号
	CNetString128Type	DEVICETYPE;
	///指标串
	CNetString256Type	AttrsChain;
	///指标规则串
	CNetString512Type	DefRegularChain;
	///指标阀值串
	CNetString2KType	DefParamChain;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(DEVICETYPE)
		,
		TYPE_DESC(AttrsChain)
		,
		TYPE_DESC(DefRegularChain)
		,
		TYPE_DESC(DefParamChain)
	));
};
const DWORD FTD_FID_RspQryNetMonitorTaskInstAttrs=0x8158;

///任务指令指标集表
class CFTDRtnNetMonitorTaskInstAttrsField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令别名
	CNetString128Type	InstructAlias;
	///设备型号
	CNetString128Type	DEVICETYPE;
	///指标串
	CNetString256Type	AttrsChain;
	///指标规则串
	CNetString512Type	DefRegularChain;
	///指标阀值串
	CNetString2KType	DefParamChain;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(DEVICETYPE)
		,
		TYPE_DESC(AttrsChain)
		,
		TYPE_DESC(DefRegularChain)
		,
		TYPE_DESC(DefParamChain)
	));
};
const DWORD FTD_FID_RtnNetMonitorTaskInstAttrs=0x8159;

///文件通用操作
class CFTDReqQryFileGeneralOperField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///文件名
	CNetAttrTypeType	FileName;
	///文件版本
	CFileVersionType	Version;
	///小版本号
	CVolumeType	SubVersion;
	///日期
	CDateType	MonDate;
	///时间
	CTimeType	MonTime;
	///文件操作用户
	CTypeUserNameType	UserName;
	///操作类型
	CVolumeType	OperType;
	///操作结果
	CVolumeType	OperResult;
	///注释
	CNetAttrTypeType	Comments;
	///文件偏移
	COffsetType	Offset;
	///Content中实际内容长度
	CCommLengthType	Length;
	///文件内容
	CFileCommentType	FileContent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(FileName)
		,
		TYPE_DESC(Version)
		,
		TYPE_DESC(SubVersion)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(OperType)
		,
		TYPE_DESC(OperResult)
		,
		TYPE_DESC(Comments)
		,
		TYPE_DESC(Offset)
		,
		TYPE_DESC(Length)
		,
		TYPE_DESC(FileContent)
	));
};
const DWORD FTD_FID_ReqQryFileGeneralOper=0x8160;

///文件通用操作
class CFTDRspQryFileGeneralOperField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///文件名
	CNetAttrTypeType	FileName;
	///文件版本
	CFileVersionType	Version;
	///小版本号
	CVolumeType	SubVersion;
	///日期
	CDateType	MonDate;
	///时间
	CTimeType	MonTime;
	///文件操作用户
	CTypeUserNameType	UserName;
	///操作类型
	CVolumeType	OperType;
	///操作结果
	CVolumeType	OperResult;
	///注释
	CNetAttrTypeType	Comments;
	///文件偏移
	COffsetType	Offset;
	///Content中实际内容长度
	CCommLengthType	Length;
	///文件内容
	CFileCommentType	FileContent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(FileName)
		,
		TYPE_DESC(Version)
		,
		TYPE_DESC(SubVersion)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(OperType)
		,
		TYPE_DESC(OperResult)
		,
		TYPE_DESC(Comments)
		,
		TYPE_DESC(Offset)
		,
		TYPE_DESC(Length)
		,
		TYPE_DESC(FileContent)
	));
};
const DWORD FTD_FID_RspQryFileGeneralOper=0x8161;

///文件通用操作
class CFTDRtnFileGeneralOperField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///文件名
	CNetAttrTypeType	FileName;
	///文件版本
	CFileVersionType	Version;
	///小版本号
	CVolumeType	SubVersion;
	///日期
	CDateType	MonDate;
	///时间
	CTimeType	MonTime;
	///文件操作用户
	CTypeUserNameType	UserName;
	///操作类型
	CVolumeType	OperType;
	///操作结果
	CVolumeType	OperResult;
	///注释
	CNetAttrTypeType	Comments;
	///文件偏移
	COffsetType	Offset;
	///Content中实际内容长度
	CCommLengthType	Length;
	///文件内容
	CFileCommentType	FileContent;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(FileName)
		,
		TYPE_DESC(Version)
		,
		TYPE_DESC(SubVersion)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(OperType)
		,
		TYPE_DESC(OperResult)
		,
		TYPE_DESC(Comments)
		,
		TYPE_DESC(Offset)
		,
		TYPE_DESC(Length)
		,
		TYPE_DESC(FileContent)
	));
};
const DWORD FTD_FID_RtnFileGeneralOper=0x8162;

///基线表
class CFTDReqQryNetBaseLineField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///基线名
	CNetObjectIDType	Name;
	///设备型号
	CNetObjectIDType	SerialUsed;
	///文件内容
	CbaseCommentType	data;
	///备注
	CNetAttrTypeType	memo;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(SerialUsed)
		,
		TYPE_DESC(data)
		,
		TYPE_DESC(memo)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_ReqQryNetBaseLine=0x8163;

///基线表
class CFTDRspQryNetBaseLineField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///基线名
	CNetObjectIDType	Name;
	///设备型号
	CNetObjectIDType	SerialUsed;
	///文件内容
	CbaseCommentType	data;
	///备注
	CNetAttrTypeType	memo;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(SerialUsed)
		,
		TYPE_DESC(data)
		,
		TYPE_DESC(memo)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RspQryNetBaseLine=0x8164;

///基线表
class CFTDRtnNetBaseLineField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///基线名
	CNetObjectIDType	Name;
	///设备型号
	CNetObjectIDType	SerialUsed;
	///文件内容
	CbaseCommentType	data;
	///备注
	CNetAttrTypeType	memo;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(SerialUsed)
		,
		TYPE_DESC(data)
		,
		TYPE_DESC(memo)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RtnNetBaseLine=0x8165;

///基线任务表
class CFTDReqQryNetBaseLineTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///基线任务名
	CNetObjectIDType	Name;
	///基线ID列表
	CGeneralResultType	BaseLineIDList;
	///设备ID列表
	CGeneralResultType	DeviceIDList;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(BaseLineIDList)
		,
		TYPE_DESC(DeviceIDList)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_ReqQryNetBaseLineTask=0x8166;

///基线任务表
class CFTDRspQryNetBaseLineTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///基线任务名
	CNetObjectIDType	Name;
	///基线ID列表
	CGeneralResultType	BaseLineIDList;
	///设备ID列表
	CGeneralResultType	DeviceIDList;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(BaseLineIDList)
		,
		TYPE_DESC(DeviceIDList)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_RspQryNetBaseLineTask=0x8167;

///基线任务表
class CFTDRtnNetBaseLineTaskField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///基线任务名
	CNetObjectIDType	Name;
	///基线ID列表
	CGeneralResultType	BaseLineIDList;
	///设备ID列表
	CGeneralResultType	DeviceIDList;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(BaseLineIDList)
		,
		TYPE_DESC(DeviceIDList)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_RtnNetBaseLineTask=0x8168;

///基线结果表
class CFTDReqQryNetBaseLineResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///基线名称
	CNetObjectIDType	BaseLineName;
	///设备ObjID
	CNetObjectIDType	DeviceObjID;
	///设备IP
	CIPAddressType	DeviceIP;
	///基线结果
	CFileCommentType	Result;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(BaseLineName)
		,
		TYPE_DESC(DeviceObjID)
		,
		TYPE_DESC(DeviceIP)
		,
		TYPE_DESC(Result)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_ReqQryNetBaseLineResult=0x8169;

///基线结果表
class CFTDRspQryNetBaseLineResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///基线名称
	CNetObjectIDType	BaseLineName;
	///设备ObjID
	CNetObjectIDType	DeviceObjID;
	///设备IP
	CIPAddressType	DeviceIP;
	///基线结果
	CFileCommentType	Result;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(BaseLineName)
		,
		TYPE_DESC(DeviceObjID)
		,
		TYPE_DESC(DeviceIP)
		,
		TYPE_DESC(Result)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RspQryNetBaseLineResult=0x8170;

///基线结果表
class CFTDRtnNetBaseLineResultField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///基线名称
	CNetObjectIDType	BaseLineName;
	///设备ObjID
	CNetObjectIDType	DeviceObjID;
	///设备IP
	CIPAddressType	DeviceIP;
	///基线结果
	CFileCommentType	Result;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(BaseLineName)
		,
		TYPE_DESC(DeviceObjID)
		,
		TYPE_DESC(DeviceIP)
		,
		TYPE_DESC(Result)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_RtnNetBaseLineResult=0x8171;

///会员链路状态信息表
class CFTDReqQryNetPartyLinkStatusInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///查找方式
	CCompareTypeType	KeyCompare;
	///索引名称
	CNetAttrTypeType	KeyName;
	///索引值
	CNetAttrTypeType	KeyValue;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///席位号
	CCfgNameType	SEAT_NO;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///链路状态
	CTypeObjectIDType	status;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(KeyCompare)
		,
		TYPE_DESC(KeyName)
		,
		TYPE_DESC(KeyValue)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(status)
	));
};
const DWORD FTD_FID_ReqQryNetPartyLinkStatusInfo=0x8172;

///会员链路状态信息表
class CFTDRspQryNetPartyLinkStatusInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///席位号
	CCfgNameType	SEAT_NO;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///链路状态
	CTypeObjectIDType	status;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(status)
	));
};
const DWORD FTD_FID_RspQryNetPartyLinkStatusInfo=0x8173;

///会员链路状态信息表
class CFTDRtnNetPartyLinkStatusInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///席位号
	CCfgNameType	SEAT_NO;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///链路状态
	CTypeObjectIDType	status;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(status)
	));
};
const DWORD FTD_FID_RtnNetPartyLinkStatusInfo=0x8174;

///会员SDH线路明细表
class CFTDReqQryNetMemberSDHLineInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///会员号
	CPartyIDType	MemberNo;
	///会员名称
	CParticipantNameType	ParticipantName;
	///客户经理
	CNetString128Type	ClientManager;
	///带宽
	CNetString128Type	Bandwidth;
	///接口类
	CNetString128Type	InterfaceType;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///备注
	CNetString128Type	Remark;
	///A端接入地址
	CNetString512Type	EndALineAddress;
	///A端联系人
	CNetString128Type	EndAContact;
	///Z端接入地址
	CNetString512Type	EndZLineAddress;
	///联系人
	CIndividualNameType	ContactName;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///所属省份
	CCfgNameType	PROVINCE;
	///起始设备端口
	CNetString256Type	StartPortID;
	///起始设备跳接端
	CNetString128Type	StartJump;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(MemberNo)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ClientManager)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(InterfaceType)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(Remark)
		,
		TYPE_DESC(EndALineAddress)
		,
		TYPE_DESC(EndAContact)
		,
		TYPE_DESC(EndZLineAddress)
		,
		TYPE_DESC(ContactName)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(StartPortID)
		,
		TYPE_DESC(StartJump)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(DataCenterID)
	));
};
const DWORD FTD_FID_ReqQryNetMemberSDHLineInfo=0x8175;

///会员SDH线路明细表
class CFTDRspQryNetMemberSDHLineInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///会员号
	CPartyIDType	MemberNo;
	///会员名称
	CParticipantNameType	ParticipantName;
	///客户经理
	CNetString128Type	ClientManager;
	///带宽
	CNetString128Type	Bandwidth;
	///接口类
	CNetString128Type	InterfaceType;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///备注
	CNetString128Type	Remark;
	///A端接入地址
	CNetString512Type	EndALineAddress;
	///A端联系人
	CNetString128Type	EndAContact;
	///Z端接入地址
	CNetString512Type	EndZLineAddress;
	///联系人
	CIndividualNameType	ContactName;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///所属省份
	CCfgNameType	PROVINCE;
	///起始设备端口
	CNetString256Type	StartPortID;
	///起始设备跳接端
	CNetString128Type	StartJump;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(MemberNo)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ClientManager)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(InterfaceType)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(Remark)
		,
		TYPE_DESC(EndALineAddress)
		,
		TYPE_DESC(EndAContact)
		,
		TYPE_DESC(EndZLineAddress)
		,
		TYPE_DESC(ContactName)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(StartPortID)
		,
		TYPE_DESC(StartJump)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(DataCenterID)
	));
};
const DWORD FTD_FID_RspQryNetMemberSDHLineInfo=0x8176;

///会员SDH线路明细表
class CFTDRtnNetMemberSDHLineInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///会员号
	CPartyIDType	MemberNo;
	///会员名称
	CParticipantNameType	ParticipantName;
	///客户经理
	CNetString128Type	ClientManager;
	///带宽
	CNetString128Type	Bandwidth;
	///接口类
	CNetString128Type	InterfaceType;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///备注
	CNetString128Type	Remark;
	///A端接入地址
	CNetString512Type	EndALineAddress;
	///A端联系人
	CNetString128Type	EndAContact;
	///Z端接入地址
	CNetString512Type	EndZLineAddress;
	///联系人
	CIndividualNameType	ContactName;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///所属省份
	CCfgNameType	PROVINCE;
	///起始设备端口
	CNetString256Type	StartPortID;
	///起始设备跳接端
	CNetString128Type	StartJump;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(MemberNo)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ClientManager)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(InterfaceType)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(Remark)
		,
		TYPE_DESC(EndALineAddress)
		,
		TYPE_DESC(EndAContact)
		,
		TYPE_DESC(EndZLineAddress)
		,
		TYPE_DESC(ContactName)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(StartPortID)
		,
		TYPE_DESC(StartJump)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(DataCenterID)
	));
};
const DWORD FTD_FID_RtnNetMemberSDHLineInfo=0x8177;

///DDN链路信息表
class CFTDReqQryNetDDNLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///客户名称
	CPartyNameType	ClientName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
	));
};
const DWORD FTD_FID_ReqQryNetDDNLinkInfo=0x8178;

///DDN链路信息表
class CFTDRspQryNetDDNLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///客户名称
	CPartyNameType	ClientName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
	));
};
const DWORD FTD_FID_RspQryNetDDNLinkInfo=0x8179;

///DDN链路信息表
class CFTDRtnNetDDNLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///客户名称
	CPartyNameType	ClientName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
	));
};
const DWORD FTD_FID_RtnNetDDNLinkInfo=0x817a;

///非会员线路使用信息
class CFTDReqQryNetPseudMemberLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///线路用途
	CNetString128Type	LineUsage;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///业务
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	///乙端电话号码
	CTelephoneType	Telephone;
	///线路信息
	CTypeObjectIDType	LineInfo;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(LineUsage)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
		,
		TYPE_DESC(Telephone)
		,
		TYPE_DESC(LineInfo)
		,
		TYPE_DESC(IPADDR)
	));
};
const DWORD FTD_FID_ReqQryNetPseudMemberLinkInfo=0x817b;

///非会员线路使用信息
class CFTDRspQryNetPseudMemberLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///线路用途
	CNetString128Type	LineUsage;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///业务
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	///乙端电话号码
	CTelephoneType	Telephone;
	///线路信息
	CTypeObjectIDType	LineInfo;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(LineUsage)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
		,
		TYPE_DESC(Telephone)
		,
		TYPE_DESC(LineInfo)
		,
		TYPE_DESC(IPADDR)
	));
};
const DWORD FTD_FID_RspQryNetPseudMemberLinkInfo=0x817c;

///非会员线路使用信息
class CFTDRtnNetPseudMemberLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///线路用途
	CNetString128Type	LineUsage;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///业务
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	///乙端电话号码
	CTelephoneType	Telephone;
	///线路信息
	CTypeObjectIDType	LineInfo;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(LineUsage)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
		,
		TYPE_DESC(Telephone)
		,
		TYPE_DESC(LineInfo)
		,
		TYPE_DESC(IPADDR)
	));
};
const DWORD FTD_FID_RtnNetPseudMemberLinkInfo=0x817d;

///远端设备信息
class CFTDReqQryOuterDeviceInfField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP地址  
	CIPAddressType	IPADDR;
	///设备名称 
	CNetObjectIDType	NAME;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(NAME)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_ReqQryOuterDeviceInf=0x817e;

///远端设备信息
class CFTDRspQryOuterDeviceInfField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP地址  
	CIPAddressType	IPADDR;
	///设备名称 
	CNetObjectIDType	NAME;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(NAME)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_RspQryOuterDeviceInf=0x817f;

///远端设备信息
class CFTDRtnNetOuterDeviceInfField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP地址  
	CIPAddressType	IPADDR;
	///设备名称 
	CNetObjectIDType	NAME;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(NAME)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_RtnNetOuterDeviceInf=0x8180;

///本地ping结果
class CFTDReqQryNetLocalPingResultInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
	));
};
const DWORD FTD_FID_ReqQryNetLocalPingResultInfo=0x8181;

///本地ping结果
class CFTDRspQryNetLocalPingResultInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
	));
};
const DWORD FTD_FID_RspQryNetLocalPingResultInfo=0x8182;

///本地ping结果
class CFTDRtnNetLocalPingResultInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
	));
};
const DWORD FTD_FID_RtnNetLocalPingResultInfo=0x8183;

///远程ping结果
class CFTDReqQryNetRomotePingResultInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	///最小时延
	CNetString128Type	TimeDlyMin;
	///最大时延
	CNetString128Type	TimeDlyMax;
	///平均时延
	CNetString128Type	TimeDlyAvg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
		,
		TYPE_DESC(TimeDlyMin)
		,
		TYPE_DESC(TimeDlyMax)
		,
		TYPE_DESC(TimeDlyAvg)
	));
};
const DWORD FTD_FID_ReqQryNetRomotePingResultInfo=0x8184;

///远程ping结果
class CFTDRspQryNetRomotePingResultInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	///最小时延
	CNetString128Type	TimeDlyMin;
	///最大时延
	CNetString128Type	TimeDlyMax;
	///平均时延
	CNetString128Type	TimeDlyAvg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
		,
		TYPE_DESC(TimeDlyMin)
		,
		TYPE_DESC(TimeDlyMax)
		,
		TYPE_DESC(TimeDlyAvg)
	));
};
const DWORD FTD_FID_RspQryNetRomotePingResultInfo=0x8185;

///远程ping结果
class CFTDRtnNetRomotePingResultInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	///最小时延
	CNetString128Type	TimeDlyMin;
	///最大时延
	CNetString128Type	TimeDlyMax;
	///平均时延
	CNetString128Type	TimeDlyAvg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
		,
		TYPE_DESC(TimeDlyMin)
		,
		TYPE_DESC(TimeDlyMax)
		,
		TYPE_DESC(TimeDlyAvg)
	));
};
const DWORD FTD_FID_RtnNetRomotePingResultInfo=0x8186;

///
class CFTDRtnMonitorTopProcessInfoField
{
public:
	///主机名称
	CTypeObjectIDType	HostName;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///处理器号
	CTypeCPUIdType	CPU;
	///终端名
	CTypeChar10Type	TTY;
	///进程号
	CVolumeType	PID;
	///用户名
	CTypeChar10Type	USERNAME;
	///任务的优先级
	CVolumeType	PRI;
	///任务的nice值
	CVolumeType	NI;
	///任务的代码加上数据再加上栈空间的大小
	CVolumeType	SSIZE;
	///任务使用的物理内存的总数量
	CVolumeType	RES;
	///任务的状态
	CTypeChar10Type	STATE;
	///自任务开始时使用的总CPU时间
	CTimeType	STIME;
	///进程的CPU利用率权重百分比
	CRatioType	pWCPU;
	///进程的原始的CPU利用率百分比
	CRatioType	pCPU;
	///启动进程的命令名
	CTypeCommandType	COMMAND;
	TYPE_DESCRIPTOR((
		TYPE_DESC(HostName)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(CPU)
		,
		TYPE_DESC(TTY)
		,
		TYPE_DESC(PID)
		,
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(PRI)
		,
		TYPE_DESC(NI)
		,
		TYPE_DESC(SSIZE)
		,
		TYPE_DESC(RES)
		,
		TYPE_DESC(STATE)
		,
		TYPE_DESC(STIME)
		,
		TYPE_DESC(pWCPU)
		,
		TYPE_DESC(pCPU)
		,
		TYPE_DESC(COMMAND)
	));
};
const DWORD FTD_FID_RtnMonitorTopProcessInfo=0x8187;

///系统内部级联关系
class CFTDReqQrySysInternalTopologyField
{
public:
	///携带信息的类型
	CReportIDType	InfoType;
	///节点1的ID
	CNodeIDType	Node1_ID;
	///节点1的信息
	CNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	CLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	CLinkStateType	LinkState;
	///节点2的ID
	CNodeIDType	Node2_ID;
	///节点2的信息
	CNodeInfoType	Node2_Info;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InfoType)
		,
		TYPE_DESC(Node1_ID)
		,
		TYPE_DESC(Node1_Info)
		,
		TYPE_DESC(LinkInfo)
		,
		TYPE_DESC(LinkState)
		,
		TYPE_DESC(Node2_ID)
		,
		TYPE_DESC(Node2_Info)
	));
};
const DWORD FTD_FID_ReqQrySysInternalTopology=0x8188;

///系统内部级联关系
class CFTDRspQrySysInternalTopologyField
{
public:
	///携带信息的类型
	CReportIDType	InfoType;
	///节点1的ID
	CNodeIDType	Node1_ID;
	///节点1的信息
	CNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	CLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	CLinkStateType	LinkState;
	///节点2的ID
	CNodeIDType	Node2_ID;
	///节点2的信息
	CNodeInfoType	Node2_Info;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InfoType)
		,
		TYPE_DESC(Node1_ID)
		,
		TYPE_DESC(Node1_Info)
		,
		TYPE_DESC(LinkInfo)
		,
		TYPE_DESC(LinkState)
		,
		TYPE_DESC(Node2_ID)
		,
		TYPE_DESC(Node2_Info)
	));
};
const DWORD FTD_FID_RspQrySysInternalTopology=0x8189;

///系统内部级联关系
class CFTDRtnSysInternalTopologyField
{
public:
	///携带信息的类型
	CReportIDType	InfoType;
	///节点1的ID
	CNodeIDType	Node1_ID;
	///节点1的信息
	CNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	CLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	CLinkStateType	LinkState;
	///节点2的ID
	CNodeIDType	Node2_ID;
	///节点2的信息
	CNodeInfoType	Node2_Info;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InfoType)
		,
		TYPE_DESC(Node1_ID)
		,
		TYPE_DESC(Node1_Info)
		,
		TYPE_DESC(LinkInfo)
		,
		TYPE_DESC(LinkState)
		,
		TYPE_DESC(Node2_ID)
		,
		TYPE_DESC(Node2_Info)
	));
};
const DWORD FTD_FID_RtnSysInternalTopology=0x8190;

///请求会员链路费用表
class CFTDReqQryMemberLinkCostField
{
public:
	///ID
	CVolumeType	ID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///付款日期
	CCfgNameType	Pay_Date;
	///账期起始日期
	CCfgNameType	B_Pay_Date;
	///账期终止日期
	CCfgNameType	D_Pay_Date;
	///金额
	CVolumeType	Charge;
	///费用类型
	CCfgNameType	Fee_Type;
	///备注
	CPolicyStringTypeType	Pro;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(Pay_Date)
		,
		TYPE_DESC(B_Pay_Date)
		,
		TYPE_DESC(D_Pay_Date)
		,
		TYPE_DESC(Charge)
		,
		TYPE_DESC(Fee_Type)
		,
		TYPE_DESC(Pro)
	));
};
const DWORD FTD_FID_ReqQryMemberLinkCost=0x8191;

///返回会员链路费用表
class CFTDRspQryMemberLinkCostField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///付款日期
	CCfgNameType	Pay_Date;
	///账期起始日期
	CCfgNameType	B_Pay_Date;
	///账期终止日期
	CCfgNameType	D_Pay_Date;
	///金额
	CVolumeType	Charge;
	///费用类型
	CCfgNameType	Fee_Type;
	///备注
	CPolicyStringTypeType	Pro;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(Pay_Date)
		,
		TYPE_DESC(B_Pay_Date)
		,
		TYPE_DESC(D_Pay_Date)
		,
		TYPE_DESC(Charge)
		,
		TYPE_DESC(Fee_Type)
		,
		TYPE_DESC(Pro)
	));
};
const DWORD FTD_FID_RspQryMemberLinkCost=0x8192;

///订阅会员链路费用表
class CFTDRtnMemberLinkCostField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///付款日期
	CCfgNameType	Pay_Date;
	///账期起始日期
	CCfgNameType	B_Pay_Date;
	///账期终止日期
	CCfgNameType	D_Pay_Date;
	///金额
	CVolumeType	Charge;
	///费用类型
	CCfgNameType	Fee_Type;
	///备注
	CPolicyStringTypeType	Pro;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(Pay_Date)
		,
		TYPE_DESC(B_Pay_Date)
		,
		TYPE_DESC(D_Pay_Date)
		,
		TYPE_DESC(Charge)
		,
		TYPE_DESC(Fee_Type)
		,
		TYPE_DESC(Pro)
	));
};
const DWORD FTD_FID_RtnMemberLinkCost=0x8193;

///请求会员链路月租表
class CFTDReqQryNetPartylinkMonthlyRentField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///线路名称
	CParticipantNameType	LineName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///备注
	CNetString128Type	Remark;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(LineName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(Remark)
	));
};
const DWORD FTD_FID_ReqQryNetPartylinkMonthlyRent=0x8194;

///返回会员链路月租表
class CFTDRspQryNetPartylinkMonthlyRentField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///线路名称
	CParticipantNameType	LineName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///备注
	CNetString128Type	Remark;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(LineName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(Remark)
	));
};
const DWORD FTD_FID_RspQryNetPartylinkMonthlyRent=0x8195;

///订阅会员链路月租表
class CFTDRtnNetPartylinkMonthlyRentField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///线路名称
	CParticipantNameType	LineName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///备注
	CNetString128Type	Remark;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(LineName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(Remark)
	));
};
const DWORD FTD_FID_RtnNetPartylinkMonthlyRent=0x8196;

///请求非会员链路信息
class CFTDReqQryNetNonPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_ReqQryNetNonPartyLinkInfo=0x8197;

///返回非会员链路信息
class CFTDRspQryNetNonPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_RspQryNetNonPartyLinkInfo=0x8198;

///订阅非会员链路信息
class CFTDRtnNetNonPartyLinkInfoField
{
public:
	///操作类型
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(OperationType)
		,
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_RtnNetNonPartyLinkInfo=0x8199;

///
class CFTDSysNetAreaField
{
public:
	///ID
	CVolumeType	ID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetArea=0x9001;

///
class CFTDSysNetSubAreaField
{
public:
	///ID
	CVolumeType	ID;
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetAreaID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetSubArea=0x9002;

///
class CFTDSysNetSubAreaIPField
{
public:
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip地址
	CIPAddressType	IP;
	///掩码
	CIPAddressType	Mask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(IP)
		,
		TYPE_DESC(Mask)
	));
};
const DWORD FTD_FID_SysNetSubAreaIP=0x9003;

///
class CFTDSysNetDeviceTypeField
{
public:
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
	));
};
const DWORD FTD_FID_SysNetDeviceType=0x9004;

///
class CFTDSysNetOIDField
{
public:
	///ID
	CVolumeType	ID;
	///生产商名
	CTypeObjectIDType	Manufactory;
	///设备型号
	CTypeObjectIDType	DeviceType;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///单位
	CTypeObjectIDType	Unit;
	///是否标量标志
	CVolumeType	isTheTable;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(DeviceType)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(OID)
		,
		TYPE_DESC(Unit)
		,
		TYPE_DESC(isTheTable)
	));
};
const DWORD FTD_FID_SysNetOID=0x9005;

///
class CFTDSysNetTimePolicyField
{
public:
	///ID
	CVolumeType	ID;
	///时间策略中文名
	CTypeObjectIDType	CName;
	///时间策略英文名
	CTypeObjectIDType	EName;
	///策略类型
	CVolumeType	PolicyType;
	///策略项配置串
	CPolicyStringTypeType	PolicyString;
	///交易日限制
	CVolumeType	TradingDay;
	///策略项描述
	CNetAttrTypeType	Description;
	///操作类型
	CVolumeType	Operation;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(PolicyType)
		,
		TYPE_DESC(PolicyString)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(Operation)
	));
};
const DWORD FTD_FID_SysNetTimePolicy=0x9006;

///
class CFTDSysNetGatherTaskField
{
public:
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///网络监控指标类型
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	///返回类型
	CVolumeType	DataType;
	///类型标识
	CVolumeType	TypeFlag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
		,
		TYPE_DESC(DataType)
		,
		TYPE_DESC(TypeFlag)
	));
};
const DWORD FTD_FID_SysNetGatherTask=0x9007;

///
class CFTDSysNetDeviceCategoryField
{
public:
	///ID
	CVolumeType	ID;
	///类别中文名
	CTypeObjectIDType	CName;
	///类别英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetDeviceCategory=0x9008;

///
class CFTDSysNetManufactoryField
{
public:
	///ID
	CVolumeType	ID;
	///厂商中文名
	CTypeObjectIDType	CName;
	///厂商英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetManufactory=0x9009;

///
class CFTDSysNetCommunityField
{
public:
	///ID
	CVolumeType	ID;
	///IP地址
	CIPAddressType	IPADDR;
	///共同体名
	CTypeObjectIDType	COMMUNITY;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(COMMUNITY)
	));
};
const DWORD FTD_FID_SysNetCommunity=0x9010;

///
class CFTDSysNetGeneralOIDField
{
public:
	///ID
	CVolumeType	ID;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///单位
	CTypeObjectIDType	Unit;
	///是否标量标志
	CVolumeType	isTheTable;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(OID)
		,
		TYPE_DESC(Unit)
		,
		TYPE_DESC(isTheTable)
	));
};
const DWORD FTD_FID_SysNetGeneralOID=0x9011;

///
class CFTDSysNetDeviceLinkedField
{
public:
	///ID
	CVolumeType	ID;
	///设备ID
	CVolumeType	NetDeviceID;
	///设备端口ID
	CVolumeType	NetPortID;
	///监控对象
	CNetObjectIDType	NetObjectID;
	///监控对象端口类型
	CNetDevicePortTypeType	NetPortType;
	///连接设备ID
	CVolumeType	LinkNetDeviceID;
	///连接设备端口ID
	CVolumeType	LinkNetPortID;
	///连接对象
	CNetObjectIDType	LinkNetObjectID;
	///连接对象端口类型
	CNetDevicePortTypeType	LinkNetPortType;
	///链接来源
	CVolumeType	LinkSource;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(NetDeviceID)
		,
		TYPE_DESC(NetPortID)
		,
		TYPE_DESC(NetObjectID)
		,
		TYPE_DESC(NetPortType)
		,
		TYPE_DESC(LinkNetDeviceID)
		,
		TYPE_DESC(LinkNetPortID)
		,
		TYPE_DESC(LinkNetObjectID)
		,
		TYPE_DESC(LinkNetPortType)
		,
		TYPE_DESC(LinkSource)
	));
};
const DWORD FTD_FID_SysNetDeviceLinked=0x9012;

///
class CFTDSysNetDeviceField
{
public:
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///分类ID  
	CVolumeType	CATEGORY_ID;
	///人为划分的职能区域  
	CTypeObjectIDType	FuctionArea;
	///IP地址  
	CIPAddressType	IPADDR;
	///IP码    
	CVolumeType	IPDECODE;
	///设备名称 
	CNetObjectIDType	NAME;
	///             
	CVolumeType	PORTNUMBER;
	///          
	CTypeObjectIDType	CONFIGFILE;
	///共同体名  
	CTypeObjectIDType	RCOMMUNITY;
	///snmp版本     
	CVolumeType	SNMPVERSION;
	///ramsize(B)   
	CVolumeType	RAMSIZE;
	///falshsize(B) 
	CVolumeType	FLASHSIZE;
	///nvramsize(B) 
	CVolumeType	NVRAMSIZE;
	///所属机柜
	CVolumeType	CABINET_ID;
	///
	CVolumeType	ROOM_ID;
	///软件版本
	CVolumeType	IOSVERSION_ID;
	///系统描述
	CNetAttrTypeType	DESCRIPTION;
	///登录用户名
	CTypeObjectIDType	USERNAME;
	///登录密码
	CNetAttrTypeType	PASSWD;
	///enable密码
	CNetAttrTypeType	ENPASSWD;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///配置备份协议
	CVolumeType	CFGSAVETYPE;
	///设备型号
	CNetObjectIDType	DEVICETYPE;
	///是否短信告警
	CVolumeType	SENDSMS;
	///是否自动snmp探测
	CVolumeType	ISSNMP;
	///槽位数
	CVolumeType	SLOTNUM;
	///是否自动ping
	CVolumeType	ISPING;
	///端口数量
	CVolumeType	IFNUM;
	///巡检分区
	CVolumeType	APPLICATION_ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(CATEGORY_ID)
		,
		TYPE_DESC(FuctionArea)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(IPDECODE)
		,
		TYPE_DESC(NAME)
		,
		TYPE_DESC(PORTNUMBER)
		,
		TYPE_DESC(CONFIGFILE)
		,
		TYPE_DESC(RCOMMUNITY)
		,
		TYPE_DESC(SNMPVERSION)
		,
		TYPE_DESC(RAMSIZE)
		,
		TYPE_DESC(FLASHSIZE)
		,
		TYPE_DESC(NVRAMSIZE)
		,
		TYPE_DESC(CABINET_ID)
		,
		TYPE_DESC(ROOM_ID)
		,
		TYPE_DESC(IOSVERSION_ID)
		,
		TYPE_DESC(DESCRIPTION)
		,
		TYPE_DESC(USERNAME)
		,
		TYPE_DESC(PASSWD)
		,
		TYPE_DESC(ENPASSWD)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(CFGSAVETYPE)
		,
		TYPE_DESC(DEVICETYPE)
		,
		TYPE_DESC(SENDSMS)
		,
		TYPE_DESC(ISSNMP)
		,
		TYPE_DESC(SLOTNUM)
		,
		TYPE_DESC(ISPING)
		,
		TYPE_DESC(IFNUM)
		,
		TYPE_DESC(APPLICATION_ID)
	));
};
const DWORD FTD_FID_SysNetDevice=0x9013;

///
class CFTDSysNetInterfaceField
{
public:
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///端口类型
	CVolumeType	IfType;
	///端口名
	CTypeObjectIDType	EName;
	///IP地址
	CIPAddressType	IpAddress;
	///掩码
	CIPAddressType	IpMask;
	///端口状态
	CVolumeType	IfStatus;
	///物理地址
	CTypeObjectIDType	MAC;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///所属设备端口索引
	CTypeObjectNameType	DeviceIndex;
	///是否轮询
	CVolumeType	isPolling;
	///描述
	CTypeObjectIDType	Description;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(IfType)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(IpAddress)
		,
		TYPE_DESC(IpMask)
		,
		TYPE_DESC(IfStatus)
		,
		TYPE_DESC(MAC)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(DeviceIndex)
		,
		TYPE_DESC(isPolling)
		,
		TYPE_DESC(Description)
	));
};
const DWORD FTD_FID_SysNetInterface=0x9014;

///
class CFTDSysNetMonitorTypeField
{
public:
	///ID
	CVolumeType	ID;
	///OID中文名
	CTypeObjectIDType	CName;
	///OID英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetMonitorType=0x9015;

///
class CFTDSysNetMonitorAttrScopeField
{
public:
	///ID
	CVolumeType	ID;
	///指标中文名
	CNetAttrTypeType	CName;
	///指标英文名
	CNetAttrTypeType	EName;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_SysNetMonitorAttrScope=0x9016;

///
class CFTDSysNetMonitorAttrTypeField
{
public:
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///设备类别
	CVolumeType	MonitorType_ID;
	///网络监控指标ID
	CVolumeType	AttrType_ID;
	///厂商类型
	CTypeObjectIDType	MANUFACTORY;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(AttrType_ID)
		,
		TYPE_DESC(MANUFACTORY)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_SysNetMonitorAttrType=0x9017;

///
class CFTDSysNetMonitorObjectAttrField
{
public:
	///ID
	CVolumeType	ID;
	///监控对象
	CNetObjectIDType	ObjectID;
	///网络监控指标
	CNetAttrTypeType	AttrType;
	///时间策略ID
	CVolumeType	PolicyTypeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
		,
		TYPE_DESC(PolicyTypeID)
	));
};
const DWORD FTD_FID_SysNetMonitorObjectAttr=0x9018;

///
class CFTDSysNetFuncAreaField
{
public:
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///区域中文名
	CTypeObjectIDType	CName;
	///区域英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetFuncArea=0x9019;

///
class CFTDSysNetMonitorCommandTypeField
{
public:
	///ID
	CVolumeType	ID;
	///厂商类型ID
	CVolumeType	Manufactory_ID;
	///设备类别ID
	CVolumeType	MonitorType_ID;
	///设备型号ID
	CVolumeType	DeviceModle_ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///厂商类型
	CTypeObjectIDType	Manufactory;
	///设备类别
	CTypeObjectIDType	MonitorType;
	///设备型号
	CTypeObjectIDType	DeviceModle;
	///动作族
	CTypeObjectIDType	ActionGroup;
	///指令码
	CNetAttrTypeType	Command;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceModle_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(Manufactory)
		,
		TYPE_DESC(MonitorType)
		,
		TYPE_DESC(DeviceModle)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(Command)
	));
};
const DWORD FTD_FID_SysNetMonitorCommandType=0x9020;

///
class CFTDSysNetMonitorActionGroupField
{
public:
	///ID
	CVolumeType	ID;
	///动作族中文名
	CTypeObjectIDType	CName;
	///动作族英文名
	CTypeObjectIDType	EName;
	///动作类型码
	CVolumeType	ActionType;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(ActionType)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_SysNetMonitorActionGroup=0x9021;

///
class CFTDSysNetMonitorDeviceGroupField
{
public:
	///ID
	CVolumeType	ID;
	///设备对象组中文名
	CTypeObjectIDType	CName;
	///设备对象组英文名
	CTypeObjectIDType	EName;
	///设备过滤条件
	CNetString512Type	Condition;
	///注释
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(Condition)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_SysNetMonitorDeviceGroup=0x9022;

///
class CFTDSysNetMonitorTaskInfoField
{
public:
	///ID
	CVolumeType	ID;
	///任务中文名
	CTypeObjectIDType	CName;
	///任务英文名
	CTypeObjectIDType	EName;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///管理人员对象组ID
	CVolumeType	ManagerGroup_ID;
	///任务时间策略ID
	CVolumeType	TimePolicy_ID;
	///任务优先级ID
	CVolumeType	TaskPriority_ID;
	///结果输出策略ID
	CVolumeType	OutputPolicy_ID;
	///任务动作族ID
	CVolumeType	ActionGroup_ID;
	///任务表达式ID联合串
	CGeneralResultType	EventExprStr;
	///设备对象组
	CTypeObjectIDType	DeviceGroup;
	///管理人员对象组
	CTypeObjectIDType	ManagerGroup;
	///任务时间策略
	CTypeObjectIDType	TimePolicy;
	///任务优先级
	CTypeObjectIDType	TaskPriority;
	///结果输出策略
	CTypeObjectIDType	OutputPolicy;
	///任务动作族
	CTypeObjectIDType	ActionGroup;
	///任务有效性标识
	CVolumeType	ValidFlag;
	///任务状态标识
	CVolumeType	TaskStatus;
	///任务描述
	CNetAttrTypeType	Comments;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(ManagerGroup_ID)
		,
		TYPE_DESC(TimePolicy_ID)
		,
		TYPE_DESC(TaskPriority_ID)
		,
		TYPE_DESC(OutputPolicy_ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(EventExprStr)
		,
		TYPE_DESC(DeviceGroup)
		,
		TYPE_DESC(ManagerGroup)
		,
		TYPE_DESC(TimePolicy)
		,
		TYPE_DESC(TaskPriority)
		,
		TYPE_DESC(OutputPolicy)
		,
		TYPE_DESC(ActionGroup)
		,
		TYPE_DESC(ValidFlag)
		,
		TYPE_DESC(TaskStatus)
		,
		TYPE_DESC(Comments)
	));
};
const DWORD FTD_FID_SysNetMonitorTaskInfo=0x9023;

///
class CFTDSysNetDeviceChgField
{
public:
	///设备ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///网络监控对象ID
	CNetObjectIDType	OldObjectID;
	///网络监控对象ID
	CNetObjectIDType	NewObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(SysNetSubAreaID)
		,
		TYPE_DESC(OldObjectID)
		,
		TYPE_DESC(NewObjectID)
	));
};
const DWORD FTD_FID_SysNetDeviceChg=0x9024;

///
class CFTDSysNetMonitorTaskResultField
{
public:
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///任务ID
	CVolumeType	Task_ID;
	///执行次数
	CVolumeType	OperateTime;
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///指令串
	CNetString256Type	InstructChain;
	///结果串
	CNetString1KType	ResultChain;
	///任务执行标识
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(Task_ID)
		,
		TYPE_DESC(OperateTime)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(ResultChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_SysNetMonitorTaskResult=0x9025;

///
class CFTDSysNetMonitorTaskObjectSetField
{
public:
	///ID
	CVolumeType	ID;
	///设备对象组ID
	CVolumeType	DeviceGroup_ID;
	///设备ID
	CVolumeType	Device_ID;
	///DataCenter
	CDataCenterFlagType	DataCenter;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(DeviceGroup_ID)
		,
		TYPE_DESC(Device_ID)
		,
		TYPE_DESC(DataCenter)
	));
};
const DWORD FTD_FID_SysNetMonitorTaskObjectSet=0x9026;

///
class CFTDSysNetPartyLinkInfoField
{
public:
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_SysNetPartyLinkInfo=0x9027;

///
class CFTDSysNetMonitorActionAttrField
{
public:
	///ID
	CVolumeType	ID;
	///动作族ID
	CVolumeType	ActionGroup_ID;
	///监控对象ID
	CVolumeType	MonitorAttr_ID;
	///指标英文名
	CNetAttrTypeType	MonitorAttrName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ActionGroup_ID)
		,
		TYPE_DESC(MonitorAttr_ID)
		,
		TYPE_DESC(MonitorAttrName)
	));
};
const DWORD FTD_FID_SysNetMonitorActionAttr=0x9028;

///
class CFTDSysNetModuleField
{
public:
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///监控对象类型
	CVolumeType	MonitorType_ID;
	///所属设备ID
	CVolumeType	DeviceID;
	///所属设备ObjectID
	CNetObjectIDType	DeviceObjectID;
	///名字
	CTypeObjectIDType	Name;
	///描述
	CNetObjectIDType	Description;
	///模块索引
	CVolumeType	ModuleIndex;
	///物理索引
	CVolumeType	EntPhyIndex;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(MonitorType_ID)
		,
		TYPE_DESC(DeviceID)
		,
		TYPE_DESC(DeviceObjectID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(Description)
		,
		TYPE_DESC(ModuleIndex)
		,
		TYPE_DESC(EntPhyIndex)
	));
};
const DWORD FTD_FID_SysNetModule=0x9029;

///
class CFTDSysNetEventExprField
{
public:
	///ID
	CVolumeType	ID;
	///中文事件名
	CNetObjectIDType	CNAME;
	///英文事件名
	CNetObjectIDType	ENAME;
	///事件级别
	CCfgNameType	WarningLEVEL;
	///事件类型
	CVolumeType	EventTypeID;
	///事件子类型
	CVolumeType	SubEventTypeID;
	///告警间隔时间
	CVolumeType	GIVEUPTIME;
	///控制定义项
	CGeneralResultType	CONTROL;
	///表达式定义项
	CGeneralResultType	EXPR;
	///事件简述
	CTypeObjectIDType	BRIEF;
	///事件描述项
	CNetAttrTypeType	DISCRIPTION;
	///消息组ID
	CVolumeType	MSGGROUP_ID;
	///管理员组ID
	CVolumeType	ADMINGROUP_ID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CNAME)
		,
		TYPE_DESC(ENAME)
		,
		TYPE_DESC(WarningLEVEL)
		,
		TYPE_DESC(EventTypeID)
		,
		TYPE_DESC(SubEventTypeID)
		,
		TYPE_DESC(GIVEUPTIME)
		,
		TYPE_DESC(CONTROL)
		,
		TYPE_DESC(EXPR)
		,
		TYPE_DESC(BRIEF)
		,
		TYPE_DESC(DISCRIPTION)
		,
		TYPE_DESC(MSGGROUP_ID)
		,
		TYPE_DESC(ADMINGROUP_ID)
	));
};
const DWORD FTD_FID_SysNetEventExpr=0x9031;

///
class CFTDSysNetEventTypeField
{
public:
	///ID
	CVolumeType	ID;
	///事件类型中文名
	CTypeObjectIDType	CName;
	///事件类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetEventType=0x9032;

///
class CFTDSysNetSubEventTypeField
{
public:
	///ID
	CVolumeType	ID;
	///事件子类型中文名
	CTypeObjectIDType	CName;
	///事件子类型英文名
	CTypeObjectIDType	EName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
	));
};
const DWORD FTD_FID_SysNetSubEventType=0x9033;

///
class CFTDSysNetEventLevelField
{
public:
	///ID
	CVolumeType	ID;
	///事件级别中文名
	CTypeObjectIDType	CName;
	///事件级别英文名
	CTypeObjectIDType	EName;
	///事件级别描述项
	CNetAttrTypeType	DISCRIPTION;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(CName)
		,
		TYPE_DESC(EName)
		,
		TYPE_DESC(DISCRIPTION)
	));
};
const DWORD FTD_FID_SysNetEventLevel=0x9034;

///
class CFTDSysNetMonitorDeviceTaskField
{
public:
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令
	CNetString256Type	InstructChain;
	///指令别名
	CNetString128Type	InstructAlias;
	///指令参数串
	CNetString256Type	InstructArgs;
	///指标阀值串
	CNetString2KType	DefParamChain;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(InstructArgs)
		,
		TYPE_DESC(DefParamChain)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_SysNetMonitorDeviceTask=0x9036;

///
class CFTDSysNetMonitorTaskInstAttrsField
{
public:
	///ID
	CVolumeType	ID;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令别名
	CNetString128Type	InstructAlias;
	///设备型号
	CNetString128Type	DEVICETYPE;
	///指标串
	CNetString256Type	AttrsChain;
	///指标规则串
	CNetString512Type	DefRegularChain;
	///指标阀值串
	CNetString2KType	DefParamChain;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(DEVICETYPE)
		,
		TYPE_DESC(AttrsChain)
		,
		TYPE_DESC(DefRegularChain)
		,
		TYPE_DESC(DefParamChain)
	));
};
const DWORD FTD_FID_SysNetMonitorTaskInstAttrs=0x9037;

///
class CFTDSysNetBaseLineField
{
public:
	///ID
	CVolumeType	ID;
	///厂商类型
	CVolumeType	MANUFACTORY_ID;
	///基线名
	CNetObjectIDType	Name;
	///设备型号
	CNetObjectIDType	SerialUsed;
	///文件内容
	CbaseCommentType	data;
	///备注
	CNetAttrTypeType	memo;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(MANUFACTORY_ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(SerialUsed)
		,
		TYPE_DESC(data)
		,
		TYPE_DESC(memo)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_SysNetBaseLine=0x9038;

///
class CFTDSysNetBaseLineTaskField
{
public:
	///ID
	CVolumeType	ID;
	///基线任务名
	CNetObjectIDType	Name;
	///基线ID列表
	CGeneralResultType	BaseLineIDList;
	///设备ID列表
	CGeneralResultType	DeviceIDList;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(Name)
		,
		TYPE_DESC(BaseLineIDList)
		,
		TYPE_DESC(DeviceIDList)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_SysNetBaseLineTask=0x9039;

///
class CFTDSysNetBaseLineResultField
{
public:
	///ID
	CVolumeType	ID;
	///基线名称
	CNetObjectIDType	BaseLineName;
	///设备ObjID
	CNetObjectIDType	DeviceObjID;
	///设备IP
	CIPAddressType	DeviceIP;
	///基线结果
	CFileCommentType	Result;
	///生成日期
	CDateType	GenDate;
	///生成时间
	CTimeType	GenTime;
	///生成者
	CTypeUserNameType	GenUser;
	///结束标志
	CVolumeType	Flag;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(BaseLineName)
		,
		TYPE_DESC(DeviceObjID)
		,
		TYPE_DESC(DeviceIP)
		,
		TYPE_DESC(Result)
		,
		TYPE_DESC(GenDate)
		,
		TYPE_DESC(GenTime)
		,
		TYPE_DESC(GenUser)
		,
		TYPE_DESC(Flag)
	));
};
const DWORD FTD_FID_SysNetBaseLineResult=0x9040;

///
class CFTDSysNetPartyLinkStatusInfoField
{
public:
	///采集的日期
	CDateType	MonDate;
	///采集的时间
	CTimeType	MonTime;
	///席位号
	CCfgNameType	SEAT_NO;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///链路状态
	CTypeObjectIDType	status;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(status)
	));
};
const DWORD FTD_FID_SysNetPartyLinkStatusInfo=0x9041;

///
class CFTDSysNetMemberSDHLineInfoField
{
public:
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///会员号
	CPartyIDType	MemberNo;
	///会员名称
	CParticipantNameType	ParticipantName;
	///客户经理
	CNetString128Type	ClientManager;
	///带宽
	CNetString128Type	Bandwidth;
	///接口类
	CNetString128Type	InterfaceType;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///备注
	CNetString128Type	Remark;
	///A端接入地址
	CNetString512Type	EndALineAddress;
	///A端联系人
	CNetString128Type	EndAContact;
	///Z端接入地址
	CNetString512Type	EndZLineAddress;
	///联系人
	CIndividualNameType	ContactName;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///所属省份
	CCfgNameType	PROVINCE;
	///起始设备端口
	CNetString256Type	StartPortID;
	///起始设备跳接端
	CNetString128Type	StartJump;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(MemberNo)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(ClientManager)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(InterfaceType)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(Remark)
		,
		TYPE_DESC(EndALineAddress)
		,
		TYPE_DESC(EndAContact)
		,
		TYPE_DESC(EndZLineAddress)
		,
		TYPE_DESC(ContactName)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(StartPortID)
		,
		TYPE_DESC(StartJump)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(DataCenterID)
	));
};
const DWORD FTD_FID_SysNetMemberSDHLineInfo=0x9042;

///
class CFTDSysNetDDNLinkInfoField
{
public:
	///ID
	CVolumeType	ID;
	///客户名称
	CPartyNameType	ClientName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///业务单元
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ClientName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
	));
};
const DWORD FTD_FID_SysNetDDNLinkInfo=0x9043;

///
class CFTDSysNetPseudMemberLinkInfoField
{
public:
	///ID
	CVolumeType	ID;
	///序列号
	CVolumeType	SeqNo;
	///合同号
	CContractSeqNoType	MemContractNo;
	///线路用途
	CNetString128Type	LineUsage;
	///本地电路编码
	CNetString128Type	LocalCircuit;
	///长途电路编码
	CNetString128Type	RemoteCircuit;
	///业务
	CBusinessUnitType	BusinessUnit;
	///速率
	CNetString128Type	Bandwidth;
	///申请人
	CApplyPersonType	ApplyPerson;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///甲端地址
	CAddressType	EndAAddress;
	///甲端联系人
	CIndividualNameType	EndAContactName;
	///乙端地址
	CAddressType	EndZAddress;
	///乙端联系人
	CIndividualNameType	EndZContactName;
	///乙端电话号码
	CTelephoneType	Telephone;
	///线路信息
	CTypeObjectIDType	LineInfo;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SeqNo)
		,
		TYPE_DESC(MemContractNo)
		,
		TYPE_DESC(LineUsage)
		,
		TYPE_DESC(LocalCircuit)
		,
		TYPE_DESC(RemoteCircuit)
		,
		TYPE_DESC(BusinessUnit)
		,
		TYPE_DESC(Bandwidth)
		,
		TYPE_DESC(ApplyPerson)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(EndAAddress)
		,
		TYPE_DESC(EndAContactName)
		,
		TYPE_DESC(EndZAddress)
		,
		TYPE_DESC(EndZContactName)
		,
		TYPE_DESC(Telephone)
		,
		TYPE_DESC(LineInfo)
		,
		TYPE_DESC(IPADDR)
	));
};
const DWORD FTD_FID_SysNetPseudMemberLinkInfo=0x9044;

///
class CFTDSysNetMonitorDeviceTask2Field
{
public:
	///ID
	CVolumeType	ID;
	///网络监控对象ID
	CNetObjectIDType	ObjectID;
	///IP地址
	CIPAddressType	IPAddress;
	///网络设备产商ID
	CVolumeType	Manufactory_ID;
	///指令
	CNetString256Type	InstructChain;
	///指令别名
	CNetString128Type	InstructAlias;
	///指令参数串
	CNetString256Type	InstructArgs;
	///指标阀值串
	CNetString2KType	DefParamChain;
	///结束标志
	CVolumeType	Flag;
	///PrimID
	CVolumeType	SecondID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(Manufactory_ID)
		,
		TYPE_DESC(InstructChain)
		,
		TYPE_DESC(InstructAlias)
		,
		TYPE_DESC(InstructArgs)
		,
		TYPE_DESC(DefParamChain)
		,
		TYPE_DESC(Flag)
		,
		TYPE_DESC(SecondID)
	));
};
const DWORD FTD_FID_SysNetMonitorDeviceTask2=0x9045;

///
class CFTDSysNetOuterDeviceInfoField
{
public:
	///ID
	CVolumeType	ID;
	///IP地址  
	CIPAddressType	IPADDR;
	///设备名称 
	CNetObjectIDType	NAME;
	///备注
	CNetAttrTypeType	memo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(NAME)
		,
		TYPE_DESC(memo)
	));
};
const DWORD FTD_FID_SysNetOuterDeviceInfo=0x9046;

///
class CFTDSysLocalPingResultInfoField
{
public:
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
	));
};
const DWORD FTD_FID_SysLocalPingResultInfo=0x9047;

///
class CFTDSysRomotePingResultInfoField
{
public:
	///ID
	CVolumeType	ID;
	///源IP地址  
	CIPAddressType	SouIPADDR;
	///源设备名称 
	CNetObjectIDType	SouNAME;
	///目的IP地址  
	CIPAddressType	TarIPADDR;
	///目的设备名称 
	CNetObjectIDType	TarNAME;
	///生成日期
	CDateType	PDateSta;
	///时间戳
	CTimeType	PTimeSta;
	///连通率
	CVolumeType	ConnRate;
	///最小时延
	CNetString128Type	TimeDlyMin;
	///最大时延
	CNetString128Type	TimeDlyMax;
	///平均时延
	CNetString128Type	TimeDlyAvg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(SouIPADDR)
		,
		TYPE_DESC(SouNAME)
		,
		TYPE_DESC(TarIPADDR)
		,
		TYPE_DESC(TarNAME)
		,
		TYPE_DESC(PDateSta)
		,
		TYPE_DESC(PTimeSta)
		,
		TYPE_DESC(ConnRate)
		,
		TYPE_DESC(TimeDlyMin)
		,
		TYPE_DESC(TimeDlyMax)
		,
		TYPE_DESC(TimeDlyAvg)
	));
};
const DWORD FTD_FID_SysRomotePingResultInfo=0x9048;

///
class CFTDSysNetDelPartyLinkInfoField
{
public:
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_SysNetDelPartyLinkInfo=0x9049;

///
class CFTDSysNetPartyLinkAddrChangeField
{
public:
	///ID
	CVolumeType	ID;
	///ID
	CVolumeType	RelationID;
	///变更前地址
	CNetAttrTypeType	OLDADDRESS;
	///变更后地址
	CNetAttrTypeType	NEWADDRESS;
	///操作人
	CCfgNameType	OPERATOR;
	///修改日期
	CDateType	MonDate;
	///修改时间
	CTimeType	MonTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(RelationID)
		,
		TYPE_DESC(OLDADDRESS)
		,
		TYPE_DESC(NEWADDRESS)
		,
		TYPE_DESC(OPERATOR)
		,
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
	));
};
const DWORD FTD_FID_SysNetPartyLinkAddrChange=0x904a;

///
class CFTDSysInternalTopologyField
{
public:
	///携带信息的类型
	CReportIDType	InfoType;
	///节点1的ID
	CNodeIDType	Node1_ID;
	///节点1的信息
	CNodeInfoType	Node1_Info;
	///两节点之间的链路信息
	CLinkInfoType	LinkInfo;
	///两节点之间的链路状态
	CLinkStateType	LinkState;
	///节点2的ID
	CNodeIDType	Node2_ID;
	///节点2的信息
	CNodeInfoType	Node2_Info;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InfoType)
		,
		TYPE_DESC(Node1_ID)
		,
		TYPE_DESC(Node1_Info)
		,
		TYPE_DESC(LinkInfo)
		,
		TYPE_DESC(LinkState)
		,
		TYPE_DESC(Node2_ID)
		,
		TYPE_DESC(Node2_Info)
	));
};
const DWORD FTD_FID_SysInternalTopology=0x904b;

///
class CFTDSysMemberLinkCostField
{
public:
	///ID
	CVolumeType	ID;
	///会员名称
	CParticipantNameType	ParticipantName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///付款日期
	CCfgNameType	Pay_Date;
	///账期起始日期
	CCfgNameType	B_Pay_Date;
	///账期终止日期
	CCfgNameType	D_Pay_Date;
	///金额
	CVolumeType	Charge;
	///费用类型
	CCfgNameType	Fee_Type;
	///备注
	CPolicyStringTypeType	Pro;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(ParticipantName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(Pay_Date)
		,
		TYPE_DESC(B_Pay_Date)
		,
		TYPE_DESC(D_Pay_Date)
		,
		TYPE_DESC(Charge)
		,
		TYPE_DESC(Fee_Type)
		,
		TYPE_DESC(Pro)
	));
};
const DWORD FTD_FID_SysMemberLinkCost=0x904c;

///
class CFTDSysNetPartylinkMonthlyRentField
{
public:
	///ID
	CVolumeType	ID;
	///线路名称
	CParticipantNameType	LineName;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///运营商
	CCfgNameType	ServiceProvider;
	///月租费用
	CLongVolumeType	MonthlyRental;
	///备注
	CNetString128Type	Remark;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(LineName)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(ServiceProvider)
		,
		TYPE_DESC(MonthlyRental)
		,
		TYPE_DESC(Remark)
	));
};
const DWORD FTD_FID_SysNetPartylinkMonthlyRent=0x904d;

///
class CFTDSysNetNonPartyLinkInfoField
{
public:
	///ID
	CVolumeType	ID;
	///会员号
	CCfgNameType	MEMBER_NO;
	///会员名称
	CTypeObjectIDType	MEMBER_NAME;
	///会员接入地点
	CTypeObjectIDType	REMOTE_ADDR;
	///上期所接入点
	CTypeObjectIDType	LOCAL_ADDR;
	///地址
	CNetAttrTypeType	ADDRESS;
	///线路状态
	CCfgNameType	LINE_STATUS;
	///联系人
	CCfgNameType	CONTACT;
	///联系电话
	CTypeObjectIDType	TELEPHONE;
	///手机号
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///传真
	CTypeObjectIDType	FAX;
	///所属省份
	CCfgNameType	PROVINCE;
	///线路编号
	CTypeObjectIDType	DDN_NO;
	///接入方式
	CTypeObjectIDType	IN_MODE;
	///入网IP广域
	CTypeObjectIDType	IP_WAN;
	///入网IP局域
	CTypeObjectIDType	IP_LAN;
	///路由器网管IP
	CTypeObjectIDType	IPADDR;
	///路由器端口号
	CTypeObjectIDType	Interface;
	///接口开通日期
	CCfgNameType	INTERFACE_DATE;
	///所用软件
	CCfgNameType	SOFTWARE;
	///付费类型
	CCfgNameType	FEE_TYPE;
	///运营商
	CCfgNameType	SERVICEPROVIDER;
	///是否自营
	CCfgNameType	IF_ZIYING;
	///是否托管
	CCfgNameType	IF_TUOGUAN;
	///有无他所线路
	CCfgNameType	HASOTHER;
	///席位号
	CGeneralResultType	SEAT_NO;
	///备注
	CPolicyStringTypeType	PRO;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ID)
		,
		TYPE_DESC(MEMBER_NO)
		,
		TYPE_DESC(MEMBER_NAME)
		,
		TYPE_DESC(REMOTE_ADDR)
		,
		TYPE_DESC(LOCAL_ADDR)
		,
		TYPE_DESC(ADDRESS)
		,
		TYPE_DESC(LINE_STATUS)
		,
		TYPE_DESC(CONTACT)
		,
		TYPE_DESC(TELEPHONE)
		,
		TYPE_DESC(MOBILEPHONE)
		,
		TYPE_DESC(EMAIL)
		,
		TYPE_DESC(FAX)
		,
		TYPE_DESC(PROVINCE)
		,
		TYPE_DESC(DDN_NO)
		,
		TYPE_DESC(IN_MODE)
		,
		TYPE_DESC(IP_WAN)
		,
		TYPE_DESC(IP_LAN)
		,
		TYPE_DESC(IPADDR)
		,
		TYPE_DESC(Interface)
		,
		TYPE_DESC(INTERFACE_DATE)
		,
		TYPE_DESC(SOFTWARE)
		,
		TYPE_DESC(FEE_TYPE)
		,
		TYPE_DESC(SERVICEPROVIDER)
		,
		TYPE_DESC(IF_ZIYING)
		,
		TYPE_DESC(IF_TUOGUAN)
		,
		TYPE_DESC(HASOTHER)
		,
		TYPE_DESC(SEAT_NO)
		,
		TYPE_DESC(PRO)
	));
};
const DWORD FTD_FID_SysNetNonPartyLinkInfo=0x904e;




#endif
