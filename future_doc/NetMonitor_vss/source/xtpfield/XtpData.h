// XtpData.h: 
//
///20090118	王肇东		增加了查询的日志（NT-0065）
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPDATA_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_)
#define AFX_XTPDATA_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FieldDescribe.h"
#include "customDataType.h"

///用户登录
class CUserLoginField
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
	///登录成功时间
	CTimeType	LoginTime;
	///IP地址
	CIPAddressType	IPAddress;
	///最大报单本地编号
	COrderLocalIDType	MaxOrderLocalID;
	///交易系统名称
	CTradingSystemNameType	TradingSystemName;
	///用户类型
	CUserTypeType	UserType;
	///最大通讯量
	CCommFluxType	MaxCommFlux;
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
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(MaxOrderLocalID)
		,
		TYPE_DESC(TradingSystemName)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(MaxCommFlux)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserLogin=0x0001;

///响应信息
class CRspInfoField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspInfo=0x0003;

///通讯阶段
class CCommPhaseField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CommPhase=0x0004;

///交易所交易日
class CExchangeTradingDayField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExchangeTradingDay=0x0005;

///结算会话
class CSettlementSessionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SettlementSession=0x0006;

///当前时间
class CCurrentTimeField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrentTime=0x0007;

///数据中心描述
class CDataCenterDescField
{
public:
	///数据中心代码
	CDataCenterIDType	DataCenterID;
	///启动模式
	CStartModeType	StartMode;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DataCenterID)
		,
		TYPE_DESC(StartMode)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DataCenterDesc=0x0008;

///输入报单
class CInputOrderField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputOrder=0x0011;

///报单操作
class COrderActionField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_OrderAction=0x0012;

///OTC报单
class COTCOrderField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_OTCOrder=0x0013;

///输入报价
class CInputQuoteField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputQuote=0x0021;

///报价操作
class CQuoteActionField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QuoteAction=0x0022;

///输入执行宣告
class CInputExecOrderField
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
	///业务单元
	CBusinessUnitType	BusinessUnit;
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
		TYPE_DESC(BusinessUnit)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputExecOrder=0x0023;

///执行宣告操作
class CExecOrderActionField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExecOrderAction=0x0024;

///用户登录退出
class CUserLogoutField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserLogout=0x0031;

///用户口令修改
class CUserPasswordUpdateField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserPasswordUpdate=0x0032;

///用户登录信息
class CLoginInfoField
{
public:
	///交易日
	CDateType	TradingDay;
	///序号
	CSequenceNoType	SequenceNo;
	///交易用户代码
	CUserIDType	UserID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///用户端产品信息
	CProductInfoType	UserProductInfo;
	///接口端产品信息
	CProductInfoType	InterfaceProductInfo;
	///协议信息
	CProtocolInfoType	ProtocolInfo;
	///IP地址
	CIPAddressType	IPAddress;
	///登录类型
	CLoginTypeType	LoginType;
	///会话类型
	CSessionTypeType	SessionType;
	///错误代码
	CErrorIDType	ErrorID;
	///更新日期
	CDateType	UpdateDate;
	///更新时间
	CTimeType	UpdateTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SequenceNo)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(LoginType)
		,
		TYPE_DESC(SessionType)
		,
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(UpdateDate)
		,
		TYPE_DESC(UpdateTime)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_LoginInfo=0x0033;

///输入组合报单
class CInputCombOrderField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputCombOrder=0x0041;

///强制用户退出
class CForceUserExitField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ForceUserExit=0x0053;

///报单查询
class CQryOrderField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryOrder=0x3001;

///报价查询
class CQryQuoteField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryQuote=0x3002;

///成交查询
class CQryTradeField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryTrade=0x3003;

///行情查询
class CQryMarketDataField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryMarketData=0x3004;

///客户查询
class CQryClientField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryClient=0x3006;

///会员持仓查询
class CQryPartPositionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryPartPosition=0x3007;

///客户持仓查询
class CQryClientPositionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryClientPosition=0x3008;

///交易资金查询
class CQryPartAccountField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryPartAccount=0x3009;

///合约查询
class CQryInstrumentField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryInstrument=0x300A;

///合约状态查询
class CQryInstrumentStatusField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryInstrumentStatus=0x300B;

///结算组状态查询
class CQrySGDataSyncStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QrySGDataSyncStatus=0x300C;

///用户在线查询
class CQryUserSessionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryUserSession=0x300D;

///用户查询
class CQryUserField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryUser=0x300E;

///公告查询
class CQryBulletinField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryBulletin=0x300F;

///会员查询
class CQryParticipantField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryParticipant=0x3010;

///保值额度查询
class CQryHedgeVolumeField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryHedgeVolume=0x3011;

///交易所状态查询
class CQryExchangeStatusField
{
public:
	///交易所代码
	CExchangeIDType	ExchangeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryExchangeStatus=0x3012;

///结算组状态查询
class CQrySettlementGroupStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QrySettlementGroupStatus=0x3013;

///合约价位查询
class CQryMBLMarketDataField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryMBLMarketData=0x3014;

///交易所数据同步状态查询
class CQryExchangeDataSyncStatusField
{
public:
	///交易所代码
	CExchangeIDType	ExchangeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryExchangeDataSyncStatus=0x3015;

///组合报单查询
class CQryCombOrderField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryCombOrder=0x3006;

///会员资金应答
class CRspPartAccountField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspPartAccount=0x3101;

///会员持仓应答
class CRspPartPositionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspPartPosition=0x3102;

///客户持仓应答
class CRspClientPositionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspClientPosition=0x3103;

///合约查询应答
class CRspInstrumentField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspInstrument=0x3104;

///信息查询
class CQryInformationField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryInformation=0x3105;

///信息查询
class CInformationField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Information=0x3106;

///信用限额查询
class CQryCreditLimitField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryCreditLimit=0x3108;

///信用限额
class CCreditLimitField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CreditLimit=0x310A;

///客户查询应答
class CRspClientField
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
	///会员号
	CParticipantIDType	ParticipantID;
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
		TYPE_DESC(ParticipantID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspClient=0x310B;

///交易所
class CExchangeField
{
public:
	///交易所代码
	CExchangeIDType	ExchangeID;
	///交易所名称
	CExchangeNameType	ExchangeName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ExchangeName)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Exchange=0x1101;

///结算组
class CSettlementGroupField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算组名称
	CSettlementGroupNameType	SettlementGroupName;
	///交易所代码
	CExchangeIDType	ExchangeID;
	///币种
	CCurrencyType	Currency;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementGroupName)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(Currency)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SettlementGroup=0x1102;

///市场
class CMarketField
{
public:
	///市场代码
	CMarketIDType	MarketID;
	///市场名称
	CMarketNameType	MarketName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(MarketName)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Market=0x1201;

///市场产品关联
class CMarketProductField
{
public:
	///市场代码
	CMarketIDType	MarketID;
	///产品代码
	CProductIDType	ProductID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(ProductID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketProduct=0x1202;

///市场产品组关联
class CMarketProductGroupField
{
public:
	///市场代码
	CMarketIDType	MarketID;
	///产品组代码
	CProductGroupIDType	ProductGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(ProductGroupID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketProductGroup=0x1203;

///行情主题
class CMarketDataTopicField
{
public:
	///主题代码
	CTopicIDType	TopicID;
	///主题名称
	CTopicNameType	TopicName;
	///市场代码
	CMarketIDType	MarketID;
	///采样频率
	CSecondsType	SnapShotFeq;
	///市场行情深度
	CMarketDataDepthType	MarketDataDepth;
	///延迟秒数
	CSecondsType	DelaySeconds;
	///行情模式
	CMarketDataModeType	MarketDataMode;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TopicID)
		,
		TYPE_DESC(TopicName)
		,
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(SnapShotFeq)
		,
		TYPE_DESC(MarketDataDepth)
		,
		TYPE_DESC(DelaySeconds)
		,
		TYPE_DESC(MarketDataMode)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataTopic=0x1204;

///会员订阅市场
class CPartTopicSubscribeField
{
public:
	///参与者代码
	CParticipantIDType	ParticipantID;
	///参与者类型
	CParticipantTypeType	ParticipantType;
	///主题代码
	CTopicIDType	TopicID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantType)
		,
		TYPE_DESC(TopicID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartTopicSubscribe=0x1205;

///会员
class CParticipantField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Participant=0x1401;

///用户
class CUserField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_User=0x1402;

///客户
class CClientField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Client=0x1403;

///会员客户关系
class CPartClientField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///会员代码
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ParticipantID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartClient=0x1404;

///用户IP
class CUserIPField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///IP地址
	CIPAddressType	IPAddress;
	///IP地址掩码
	CIPAddressType	IPMask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(IPMask)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserIP=0x1405;

///用户会话
class CUserSessionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserSession=0x1406;

///行情发布状态
class CMdPubStatusField
{
public:
	///产品代码
	CProductIDType	ProductID;
	///合约交易状态
	CInstrumentStatusType	InstrumentStatus;
	///行情发布状态
	CMdPubStatusType	MdPubStatus;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(MdPubStatus)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MdPubStatus=0x1407;

///结算交易会员关系
class CClearingTradingPartField
{
public:
	///结算会员
	CParticipantIDType	ClearingPartID;
	///交易会员
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(ParticipantID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClearingTradingPart=0x1408;

///用户功能权限
class CUserFunctionRightField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///功能代码
	CFunctionCodeType	FunctionCode;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(FunctionCode)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserFunctionRight=0x1409;

///资金账户
class CAccountField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///资金帐号
	CAccountIDType	AccountID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///币种
	CCurrencyType	Currency;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(AccountID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(Currency)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Account=0x140A;

///用户通讯量
class CUserCommFluxField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///最大通讯量
	CCommFluxType	MaxCommFlux;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(MaxCommFlux)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserCommFlux=0x140B;

///产品组
class CProductGroupField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ProductGroup=0x2101;

///产品
class CProductField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Product=0x2102;

///合约
class CInstrumentField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Instrument=0x2103;

///组合交易合约的单腿
class CCombinationLegField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CombinationLeg=0x2104;

///会员账户关系
class CPartRoleAccountField
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
	///交易角色
	CTradingRoleType	TradingRole;
	///资金帐号
	CAccountIDType	AccountID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(AccountID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartRoleAccount=0x2105;

///会员产品角色
class CPartProductRoleField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///产品代码
	CProductIDType	ProductID;
	///交易角色
	CTradingRoleType	TradingRole;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(TradingRole)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartProductRole=0x2201;

///会员产品交易权限
class CPartProductRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易权限
	CTradingRightType	TradingRight;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRight)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartProductRight=0x2202;

///会员合约交易权限
class CPartInstrumentRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易权限
	CTradingRightType	TradingRight;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRight)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartInstrumentRight=0x2203;

///客户产品交易权限
class CClientProductRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClientProductRight=0x2204;

///客户合约交易权限
class CClientInstrumentRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClientInstrumentRight=0x2205;

///会员客户产品交易权限
class CPartClientProductRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartClientProductRight=0x2206;

///会员客户合约交易权限
class CPartClientInstrumentRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartClientInstrumentRight=0x2207;

///产品属性
class CCurrProductPropertyField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///产品生命周期状态
	CProductLifePhaseType	ProductLifePhase;
	///交易模式
	CTradingModelType	TradingModel;
	///期权限仓系数
	CRatioType	OptionsLimitRatio;
	///期权保证金调整系数
	CRatioType	OptionsMgRatio;
	///结算取样时间
	CSettlePriceSecondsType	SettlePriceSeconds;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ProductLifePhase)
		,
		TYPE_DESC(TradingModel)
		,
		TYPE_DESC(OptionsLimitRatio)
		,
		TYPE_DESC(OptionsMgRatio)
		,
		TYPE_DESC(SettlePriceSeconds)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrProductProperty=0x2301;

///合约属性
class CCurrInstrumentPropertyField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
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
	///合约代码
	CInstrumentIDType	InstrumentID;
	///合约生命周期状态
	CInstLifePhaseType	InstLifePhase;
	///是否首交易日
	CBoolType	IsFirstTradingDay;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
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
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstLifePhase)
		,
		TYPE_DESC(IsFirstTradingDay)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrInstrumentProperty=0x2303;

///当前合约价格绑定
class CCurrPriceBandingField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限价类型
	CPriceLimitTypeType	PriceLimitType;
	///取值方式
	CValueModeType	ValueMode;
	///舍入方式
	CRoundingModeType	RoundingMode;
	///上限
	CPriceType	UpperValue;
	///下限
	CPriceType	LowerValue;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(PriceLimitType)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(RoundingMode)
		,
		TYPE_DESC(UpperValue)
		,
		TYPE_DESC(LowerValue)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(TradingSegmentSN)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrPriceBanding=0x2304;

///当前合约保证金率
class CCurrMarginRateField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///保证金算法代码
	CMarginCalcIDType	MarginCalcID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(MarginCalcID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrMarginRate=0x2305;

///当前合约保证金率的详细内容
class CCurrMarginRateDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
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
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
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
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrMarginRateDetail=0x2306;

///当前会员合约限仓
class CCurrPartPosiLimitField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///会员限仓算法代码
	CPartPosiLimitCalcIDType	PartPosiLimitCalcID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(PartPosiLimitCalcID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrPartPosiLimit=0x2307;

///当前会员合约限仓的详细内容
class CCurrPartPosiLimitDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrPartPosiLimitDetail=0x2308;

///当前客户合约限仓
class CCurrClientPosiLimitField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///客户限仓算法代码
	CClientPosiLimitCalcIDType	ClientPosiLimitCalcID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ClientPosiLimitCalcID)
		,
		TYPE_DESC(InstrumentID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrClientPosiLimit=0x2309;

///当前客户合约限仓的详细内容
class CCurrClientPosiLimitDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户类型
	CClientTypeType	ClientType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientType)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrClientPosiLimitDetail=0x230A;

///当前特殊客户合约限仓
class CCurrSpecialPosiLimitField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///客户限仓算法代码
	CClientPosiLimitCalcIDType	ClientPosiLimitCalcID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ClientPosiLimitCalcID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrSpecialPosiLimit=0x230B;

///当前特殊客户合约限仓的详细内容
class CCurrSpecialPosiLimitDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrSpecialPosiLimitDetail=0x230C;

///当前合约套期保值属性
class CCurrHedgeRuleField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///套保额度使用类型
	CHedgeUsageTypeType	HedgeUsageType;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///套保额度平今仓类型
	CHedgeCloseTodayTypeType	HedgeCloseTodayType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(HedgeUsageType)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(HedgeCloseTodayType)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrHedgeRule=0x230D;

///当前合约交易阶段属性
class CCurrTradingSegmentAttrField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrTradingSegmentAttr=0x230E;

///当前合约熔断属性
class CCurrFuseField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限价类型
	CPriceLimitTypeType	PriceLimitType;
	///取值方式
	CValueModeType	ValueMode;
	///舍入方式
	CRoundingModeType	RoundingMode;
	///上限
	CPriceType	UpperValue;
	///下限
	CPriceType	LowerValue;
	///停板持续时间
	CDurationType	PriceLimitDuration;
	///熔断期
	CDurationType	FuseDuration;
	///熔断期是否交易
	CBoolType	TradingFlag;
	///不启动熔断时间
	CTimeType	NoFuseTime;
	///合约代码
	CInstrumentIDType	InstrumentID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(PriceLimitType)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(RoundingMode)
		,
		TYPE_DESC(UpperValue)
		,
		TYPE_DESC(LowerValue)
		,
		TYPE_DESC(PriceLimitDuration)
		,
		TYPE_DESC(FuseDuration)
		,
		TYPE_DESC(TradingFlag)
		,
		TYPE_DESC(NoFuseTime)
		,
		TYPE_DESC(InstrumentID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrFuse=0x230F;

///交易账户资金信息
class CTradingAccountField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_TradingAccount=0x2401;

///会员合约持仓
class CPartPositionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartPosition=0x2402;

///客户合约持仓
class CClientPositionField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClientPosition=0x2403;

///保值额度量
class CHedgeVolumeField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_HedgeVolume=0x2404;

///上日遗留报单
class CRemainOrderField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RemainOrder=0x2405;

///市场行情
class CMarketDataField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketData=0x2407;

///深度行情
class CDepthMarketDataField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DepthMarketData=0x2409;

///分价表
class CMBLMarketDataField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MBLMarketData=0x2410;

///别名定义
class CAliasDefineField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_AliasDefine=0x2411;

///行情基础属性
class CMarketDataBaseField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBase=0x2431;

///行情静态属性
class CMarketDataStaticField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataStatic=0x2432;

///行情最新成交属性
class CMarketDataLastMatchField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataLastMatch=0x2433;

///行情最优价属性
class CMarketDataBestPriceField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBestPrice=0x2434;

///行情申买二、三属性
class CMarketDataBid23Field
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBid23=0x2435;

///行情申卖二、三属性
class CMarketDataAsk23Field
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataAsk23=0x2436;

///行情申买四、五属性
class CMarketDataBid45Field
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBid45=0x2437;

///行情申卖四、五属性
class CMarketDataAsk45Field
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataAsk45=0x2438;

///行情更新时间属性
class CMarketDataUpdateTimeField
{
public:
	///合约代码
	CInstrumentIDType	InstrumentID;
	///最后修改时间
	CTimeType	UpdateTime;
	///最后修改毫秒
	CMillisecType	UpdateMillisec;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataUpdateTime=0x2439;

///基础准备金账户
class CBaseReserveAccountField
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
	///资金帐号
	CAccountIDType	AccountID;
	///基本准备金
	CMoneyType	Reserve;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(AccountID)
		,
		TYPE_DESC(Reserve)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_BaseReserveAccount=0x243A;

///Dbmt会员资金帐户入金
class CDbmtAccountDepositField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///资金账号
	CAccountIDType	Account;
	///入金金额
	CMoneyType	Deposit;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(Account)
		,
		TYPE_DESC(Deposit)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtAccountDeposit=0x2800;

///Dbmt客户
class CDbmtClientField
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
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
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
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtClient=0x2801;

///Dbmt会员客户
class CDbmtPartClientField
{
public:
	///客户代码
	CClientIDType	ClientID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartClient=0x2802;

///Dbmt会员合约持仓限额
class CDbmtCurrPartPosiLimitDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易角色
	CPositionTradingRoleType	TradingRole;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRole)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrPartPosiLimitDetail=0x2803;

///Dbmt客户合约持仓限额
class CDbmtCurrClientPosiLimitDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户类型
	CClientTypeType	ClientType;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientType)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrClientPosiLimitDetail=0x2804;

///Dbmt特殊客户合约持仓限额
class CDbmtCurrSpecialPosiLimitDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限仓起点
	CLargeVolumeType	StartTotalPosition;
	///取值方式
	CValueModeType	ValueMode;
	///多头限仓
	CRatioType	LongPosLimit;
	///空头限仓
	CRatioType	ShortPosLimit;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(StartTotalPosition)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(LongPosLimit)
		,
		TYPE_DESC(ShortPosLimit)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrSpecialPosiLimitDetail=0x2805;

///Dbmt保值额度明细
class CDbmtHedgeDetailField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///流水号
	CSerialNoType	HedgeQuotaSN;
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
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(HedgeQuotaSN)
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
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtHedgeDetail=0x2806;

///Dbmt用户
class CDbmtUserField
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
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
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
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtUser=0x2807;

///Dbmt会员产品权限
class CDbmtPartProductRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易权限
	CTradingRightType	TradingRight;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRight)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartProductRight=0x2808;

///Dbmt客户产品权限
class CDbmtClientProductRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtClientProductRight=0x2809;

///Dbmt会员合约权限
class CDbmtPartInstrumentRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///交易权限
	CTradingRightType	TradingRight;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(TradingRight)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartInstrumentRight=0x280A;

///Dbmt客户合约权限
class CDbmtClientInstrumentRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtClientInstrumentRight=0x280B;

///Dbmt会员客户产品权限
class CDbmtPartClientProductRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///产品代码
	CProductIDType	ProductID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartClientProductRight=0x2812;

///Dbmt会员客户合约权限
class CDbmtPartClientInstrumentRightField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///交易权限
	CTradingRightType	TradingRight;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(TradingRight)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartClientInstrumentRight=0x2813;

///Dbmt会员合约保证金率
class CDbmtCurrMarginRateDetailField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
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
	///合约代码
	CInstrumentIDType	InstrumentID;
	///会员代码
	CParticipantIDType	ParticipantID;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
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
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrMarginRateDetail=0x280C;

///Dbmt行情
class CDbmtMarketDataField
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
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
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
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtMarketData=0x280D;

///Dbmt用户IP地址
class CDbmtUserIPField
{
public:
	///交易用户代码
	CUserIDType	UserID;
	///IP地址
	CIPAddressType	IPAddress;
	///IP地址掩码
	CIPAddressType	IPMask;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(IPMask)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtUserIP=0x280E;

///Dbmt价格绑定
class CDbmtCurrPriceBandingField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///限价类型
	CPriceLimitTypeType	PriceLimitType;
	///取值方式
	CValueModeType	ValueMode;
	///舍入方式
	CRoundingModeType	RoundingMode;
	///上限
	CPriceType	UpperValue;
	///下限
	CPriceType	LowerValue;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///交易阶段编号
	CTradingSegmentSNType	TradingSegmentSN;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(PriceLimitType)
		,
		TYPE_DESC(ValueMode)
		,
		TYPE_DESC(RoundingMode)
		,
		TYPE_DESC(UpperValue)
		,
		TYPE_DESC(LowerValue)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrPriceBanding=0x280F;

///Dbmt更新所有合约状态
class CDbmtUpdateAllInstrumentStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约状态
	CInstrumentStatusType	InstrumentStatus;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtUpdateAllInstrumentStatus=0x2810;

///Dbmt会员订阅市场
class CDbmtPartTopicSubscribeField
{
public:
	///参与者代码
	CParticipantIDType	ParticipantID;
	///参与者类型
	CParticipantTypeType	ParticipantType;
	///主题代码
	CTopicIDType	TopicID;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantType)
		,
		TYPE_DESC(TopicID)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartTopicSubscribe=0x2811;

///Dbmt当前保值额度
class CDbmtCurrHedgeField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///流水号
	CSerialNoType	HedgeQuotaSN;
	///用户代码
	COperatorIDType	OperatorID;
	///时间
	CTimeType	Time;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///持仓多空方向
	CPosiDirectionType	PosiDirection;
	///当前保值额度
	CVolumeType	CurrVolume;
	///会员代码
	CParticipantIDType	ParticipantID;
	///客户代码
	CClientIDType	ClientID;
	///Dbmt主题号
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt序列号
	CDbmtSequenceIDType	DbmtSequenceID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(HedgeQuotaSN)
		,
		TYPE_DESC(OperatorID)
		,
		TYPE_DESC(Time)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(PosiDirection)
		,
		TYPE_DESC(CurrVolume)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(DbmtTopicID)
		,
		TYPE_DESC(DbmtSequenceID)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrHedge=0x2815;

///报价
class CQuoteField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Quote=0x2506;

///成交
class CTradeField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Trade=0x2507;

///报单
class COrderField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Order=0x2508;

///执行宣告
class CExecOrderField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExecOrder=0x2509;

///组合报单
class CCombOrderField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CombOrder=0x250A;

///管理报单
class CAdminOrderField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_AdminOrder=0x2510;

///管理报单输入
class CInputAdminOrderField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputAdminOrder=0x2511;

///公告
class CBulletinField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Bulletin=0x2607;

///交易所数据同步状态
class CExchangeDataSyncStatusField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExchangeDataSyncStatus=0x2701;

///结算组数据同步状态
class CSGDataSyncStatusField
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
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SGDataSyncStatus=0x2702;

///合约状态
class CInstrumentStatusField
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
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InstrumentStatus=0x2703;

///合约交易状态流水
class CInstrumentStatusDetailField
{
public:
	///交易日
	CDateType	TradingDay;
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
	///结算编号
	CSettlementIDType	SettlementID;
	///序列号
	CSequenceNoType	SequenceNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
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
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(SequenceNo)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InstrumentStatusDetail=0x2704;

///前置状态
class CFrontStatusField
{
public:
	///前置编号
	CFrontIDType	FrontID;
	///上次报告时间
	CTimeType	LastReportTime;
	///是否活跃
	CBoolType	IsActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(LastReportTime)
		,
		TYPE_DESC(IsActive)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_FrontStatus=0x2705;

///交易所状态
class CExchangeStatusField
{
public:
	///交易日
	CDateType	TradingDay;
	///交易所代码
	CExchangeIDType	ExchangeID;
	///交易所状态
	CExchangeStatusType	ExchangeStatus;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ExchangeStatus)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExchangeStatus=0x2708;

///结算组状态
class CSettlementGroupStatusField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///交易日
	CDateType	TradingDay;
	///结算编号
	CSettlementIDType	SettlementID;
	///结算组状态
	CSettlementGroupStatusType	SettlementGroupStatus;
	///进入本状态时间
	CTimeType	EnterTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(SettlementGroupStatus)
		,
		TYPE_DESC(EnterTime)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SettlementGroupStatus=0x2709;

///单边市情况
class CUniPressureField
{
public:
	///交易日
	CDateType	TradingDay;
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///结算编号
	CSettlementIDType	SettlementID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///涨压力开始时间
	CTimeType	UpperPressureStartTime;
	///跌压力开始时间
	CTimeType	LowerPressureStartTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(UpperPressureStartTime)
		,
		TYPE_DESC(LowerPressureStartTime)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UniPressure=0x2710;

///深度行情流水
class CDepthMarketDataDetailField
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
	///序号
	CSequenceNoType	SequenceNo;
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
		TYPE_DESC(SequenceNo)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DepthMarketDataDetail=0x2711;

///当日期货合约期权属性
class CCurrInstrumentOptionField
{
public:
	///结算组代码
	CSettlementGroupIDType	SettlementGroupID;
	///合约代码
	CInstrumentIDType	InstrumentID;
	///同标的期权的合并持仓倍数
	CRatioType	OptPostLimitRatio;
	///期货和同标的期权的合并持仓倍数
	CRatioType	UniPostLimitRatio;
	///单位（手）期权合约最小保证金
	CMoneyType	MiniMargin;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OptPostLimitRatio)
		,
		TYPE_DESC(UniPostLimitRatio)
		,
		TYPE_DESC(MiniMargin)
	));
	
	///将本field输出到buffer中，buffer长度为len，如果长度不够，将采用尽量输出的原则
	///@param	buffer	要放置结果的缓冲区
	///@param	len	缓冲区的长度
	///@return	true表示全部放成功，false表示没有全部放成功。
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrInstrumentOption=0x2712;




#endif
