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

///��Ϣ�ַ�
class CFTDDisseminationField
{
public:
	///����ϵ�к�
	CSequenceSeriesType	SequenceSeries;
	///���к�
	CSequenceNoType	SequenceNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SequenceSeries)
		,
		TYPE_DESC(SequenceNo)
	));
};
const DWORD FTD_FID_Dissemination=0x0001;

///��Ӧ��Ϣ
class CFTDRspInfoField
{
public:
	///�������
	CErrorIDType	ErrorID;
	///������Ϣ
	CErrorMsgType	ErrorMsg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
	));
};
const DWORD FTD_FID_RspInfo=0x0003;

///ͨѶ�׶�
class CFTDCommPhaseField
{
public:
	///������
	CDateType	TradingDay;
	///ͨѶʱ�κ�
	CCommPhaseNoType	CommPhaseNo;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(CommPhaseNo)
	));
};
const DWORD FTD_FID_CommPhase=0x0004;

///������������
class CFTDExchangeTradingDayField
{
public:
	///������
	CDateType	TradingDay;
	///����������
	CExchangeIDType	ExchangeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(ExchangeID)
	));
};
const DWORD FTD_FID_ExchangeTradingDay=0x0005;

///����Ự
class CFTDSettlementSessionField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
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

///��ǰʱ��
class CFTDCurrentTimeField
{
public:
	///��ǰ����
	CDateType	CurrDate;
	///��ǰʱ��
	CTimeType	CurrTime;
	///��ǰʱ�䣨���룩
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

///�û���¼����
class CFTDReqUserLoginField
{
public:
	///������
	CDateType	TradingDay;
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///����
	CPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	CProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	CProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	CProtocolInfoType	ProtocolInfo;
	///�������Ĵ���
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

///�û���¼Ӧ��
class CFTDRspUserLoginField
{
public:
	///������
	CDateType	TradingDay;
	///��¼�ɹ�ʱ��
	CTimeType	LoginTime;
	///��󱾵ر�����
	COrderLocalIDType	MaxOrderLocalID;
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///����ϵͳ����
	CTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	CDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	CSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	CSequenceNoType	UserFlowSize;
	///ҵ��������
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

///�û��ǳ�����
class CFTDReqUserLogoutField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
	));
};
const DWORD FTD_FID_ReqUserLogout=0x000C;

///�û��ǳ�Ӧ��
class CFTDRspUserLogoutField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
	));
};
const DWORD FTD_FID_RspUserLogout=0x000D;

///���뱨��
class CFTDInputOrderField
{
public:
	///�������
	COrderSysIDType	OrderSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�����۸�����
	COrderPriceTypeType	OrderPriceType;
	///��������
	CDirectionType	Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType	TimeCondition;
	///GTD����
	CDateType	GTDDate;
	///�ɽ�������
	CVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	CVolumeType	MinVolume;
	///��������
	CContingentConditionType	ContingentCondition;
	///ֹ���
	CPriceType	StopPrice;
	///ǿƽԭ��
	CForceCloseReasonType	ForceCloseReason;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///�Զ������־
	CBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///��������
class CFTDOrderActionField
{
public:
	///�������
	COrderSysIDType	OrderSysID;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///����������־
	CActionFlagType	ActionFlag;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///�۸�
	CPriceType	LimitPrice;
	///�����仯
	CVolumeType	VolumeChange;
	///�������ر��
	COrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///OTC����
class CFTDOTCOrderField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///OTC�������
	COTCOrderSysIDType	OTCOrderSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��������
	CDirectionType	Direction;
	///��ƽ��־
	COffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�۸�
	CPriceType	Price;
	///����
	CVolumeType	Volume;
	///���ַ���Ա����
	CParticipantIDType	OtherParticipantID;
	///���ַ��ͻ�����
	CClientIDType	OtherClientID;
	///���ַ������û�����
	CUserIDType	OtherUserID;
	///���ַ���ƽ��־
	COffsetFlagType	OtherOffsetFlag;
	///���ַ��ױ���־
	CHedgeFlagType	OtherHedgeFlag;
	///����OTC�������
	COrderLocalIDType	OTCOrderLocalID;
	///OTC����״̬
	COTCOrderStatusType	OTCOrderStatus;
	///����ʱ��
	CTimeType	InsertTime;
	///����ʱ��
	CTimeType	CancelTime;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///���ַ������Ա���
	CParticipantIDType	OtherClearingPartID;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///ҵ��������
	CDateType	ActionDay;
	///efp��Ӧ�ڻ�����Ȩ��Լ����
	CInstrumentIDType	EfpInstrumentID;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	CExecOrderPositionFlagType	ReservePositionFlag;
	///����ģʽ
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

///�����Ự
class CFTDOrderSessionField
{
public:
	///ǰ�ñ��
	CFrontIDType	FrontID;
	///�Ự���
	CSessionIDType	SessionID;
	///������
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

///���뱨��
class CFTDInputQuoteField
{
public:
	///���۱��
	CQuoteSysIDType	QuoteSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///����
	CVolumeType	Volume;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///���ر��۱��
	COrderLocalIDType	QuoteLocalID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	CCombOffsetFlagType	BidCombOffsetFlag;
	///������ױ���־
	CCombHedgeFlagType	BidCombHedgeFlag;
	///�򷽼۸�
	CPriceType	BidPrice;
	///������Ͽ�ƽ��־
	CCombOffsetFlagType	AskCombOffsetFlag;
	///��������ױ���־
	CCombHedgeFlagType	AskCombHedgeFlag;
	///�����۸�
	CPriceType	AskPrice;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///���۲���
class CFTDQuoteActionField
{
public:
	///���۱��
	CQuoteSysIDType	QuoteSysID;
	///���ر��۱��
	COrderLocalIDType	QuoteLocalID;
	///����������־
	CActionFlagType	ActionFlag;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///�������ر��
	COrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///����ִ������
class CFTDInputExecOrderField
{
public:
	///��Լ���
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///����ִ��������
	COrderLocalIDType	ExecOrderLocalID;
	///����
	CVolumeType	Volume;
	///��ƽ��־
	COffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�ֲַ���
	CPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	CExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	CExecOrderCloseFlagType	CloseFlag;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///ִ���������
class CFTDExecOrderActionField
{
public:
	///ִ��������
	CExecOrderSysIDType	ExecOrderSysID;
	///����ִ��������
	COrderLocalIDType	ExecOrderLocalID;
	///����������־
	CActionFlagType	ActionFlag;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///�������ر��
	COrderLocalIDType	ActionLocalID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///�û���¼�˳�
class CFTDUserLogoutField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ParticipantID)
	));
};
const DWORD FTD_FID_UserLogout=0x0031;

///�û������޸�
class CFTDUserPasswordUpdateField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///������
	CPasswordType	OldPassword;
	///������
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

///����Ǳ���ϱ���
class CFTDInputCombOrderField
{
public:
	///��ϱ������
	COrderSysIDType	CombOrderSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///���ر������
	COrderLocalIDType	CombOrderLocalID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///��Լ����1
	CInstrumentIDType	InstrumentID1;
	///��������1
	CDirectionType	Direction1;
	///���ȳ���1
	CLegMultipleType	LegMultiple1;
	///��ƽ��־1
	COffsetFlagType	OffsetFlag1;
	///Ͷ���ױ���־1
	CHedgeFlagType	HedgeFlag1;
	///��Լ����2
	CInstrumentIDType	InstrumentID2;
	///��������2
	CDirectionType	Direction2;
	///���ȳ���2
	CLegMultipleType	LegMultiple2;
	///��ƽ��־2
	COffsetFlagType	OffsetFlag2;
	///Ͷ���ױ���־2
	CHedgeFlagType	HedgeFlag2;
	///��Լ����3
	CInstrumentIDType	InstrumentID3;
	///��������3
	CDirectionType	Direction3;
	///���ȳ���3
	CLegMultipleType	LegMultiple3;
	///��ƽ��־3
	COffsetFlagType	OffsetFlag3;
	///Ͷ���ױ���־3
	CHedgeFlagType	HedgeFlag3;
	///��Լ����4
	CInstrumentIDType	InstrumentID4;
	///��������4
	CDirectionType	Direction4;
	///���ȳ���4
	CLegMultipleType	LegMultiple4;
	///��ƽ��־4
	COffsetFlagType	OffsetFlag4;
	///Ͷ���ױ���־4
	CHedgeFlagType	HedgeFlag4;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///ǿ���û��˳�
class CFTDForceUserExitField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_ForceUserExit=0x0053;

///��Ա�ʽ��ʻ����
class CFTDAccountDepositField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�ʽ��˺�
	CAccountIDType	Account;
	///�����
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

///������ѯ
class CFTDQryOrderField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///�������
	COrderSysIDType	OrderSysID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///��ʼʱ��
	CTimeType	TimeStart;
	///����ʱ��
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

///���۲�ѯ
class CFTDQryQuoteField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///���۱��
	CQuoteSysIDType	QuoteSysID;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�����û�����
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

///�ɽ���ѯ
class CFTDQryTradeField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///��ʼ��Լ����
	CInstrumentIDType	InstIDStart;
	///������Լ����
	CInstrumentIDType	InstIDEnd;
	///�ɽ����
	CTradeIDType	TradeID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///��ʼʱ��
	CTimeType	TimeStart;
	///����ʱ��
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

///�����ѯ
class CFTDQryMarketDataField
{
public:
	///��Ʒ����
	CProductIDType	ProductID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(InstrumentID)
	));
};
const DWORD FTD_FID_QryMarketData=0x3004;

///�ͻ���ѯ
class CFTDQryClientField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	CClientIDType	ClientIDStart;
	///�����ͻ�����
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

///��Ա�ֲֲ�ѯ
class CFTDQryPartPositionField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///��ʼ��Լ����
	CInstrumentIDType	InstIDStart;
	///������Լ����
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

///�ͻ��ֲֲ�ѯ
class CFTDQryClientPositionField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	CClientIDType	ClientIDStart;
	///�����ͻ�����
	CClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	CInstrumentIDType	InstIDStart;
	///������Լ����
	CInstrumentIDType	InstIDEnd;
	///�ͻ�����
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

///�����ʽ��ѯ
class CFTDQryPartAccountField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///�ʽ��ʺ�
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

///��Լ��ѯ
class CFTDQryInstrumentField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ�����
	CProductGroupIDType	ProductGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Լ����
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

///��Լ״̬��ѯ
class CFTDQryInstrumentStatusField
{
public:
	///��ʼ��Լ����
	CInstrumentIDType	InstIDStart;
	///������Լ����
	CInstrumentIDType	InstIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstIDStart)
		,
		TYPE_DESC(InstIDEnd)
	));
};
const DWORD FTD_FID_QryInstrumentStatus=0x300B;

///������״̬��ѯ
class CFTDQrySGDataSyncStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
	));
};
const DWORD FTD_FID_QrySGDataSyncStatus=0x300C;

///�û����߲�ѯ
class CFTDQryUserSessionField
{
public:
	///��ʼ�����û�����
	CUserIDType	UserIDStart;
	///���������û�����
	CUserIDType	UserIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserIDStart)
		,
		TYPE_DESC(UserIDEnd)
	));
};
const DWORD FTD_FID_QryUserSession=0x300D;

///�û���ѯ
class CFTDQryUserField
{
public:
	///��ʼ�����û�����
	CUserIDType	UserIDStart;
	///���������û�����
	CUserIDType	UserIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserIDStart)
		,
		TYPE_DESC(UserIDEnd)
	));
};
const DWORD FTD_FID_QryUser=0x300E;

///�����ѯ
class CFTDQryBulletinField
{
public:
	///������
	CDateType	TradingDay;
	///�г�����
	CMarketIDType	MarketID;
	///������
	CBulletinIDType	BulletinID;
	///��������
	CNewsTypeType	NewsType;
	///�����̶�
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

///��Ա��ѯ
class CFTDQryParticipantField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(PartIDStart)
		,
		TYPE_DESC(PartIDEnd)
	));
};
const DWORD FTD_FID_QryParticipant=0x3010;

///��ֵ��Ȳ�ѯ
class CFTDQryHedgeVolumeField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	CClientIDType	ClientIDStart;
	///�����ͻ�����
	CClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	CInstrumentIDType	InstIDStart;
	///������Լ����
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

///��Լ��λ��ѯ
class CFTDQryMBLMarketDataField
{
public:
	///��ʼ��Լ����
	CInstrumentIDType	InstIDStart;
	///������Լ����
	CInstrumentIDType	InstIDEnd;
	///��������
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

///�����޶��ѯ
class CFTDQryCreditLimitField
{
public:
	///���׻�Ա���
	CParticipantIDType	ParticipantID;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ClearingPartID)
	));
};
const DWORD FTD_FID_QryCreditLimit=0x3015;

///ִ�������ѯ
class CFTDQryExecOrderField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///ִ��������
	CExecOrderSysIDType	ExecOrderSysID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///��ʼʱ��
	CTimeType	TimeStart;
	///����ʱ��
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

///�Ǳ���ϱ�����ѯ
class CFTDQryCombOrderField
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///��ϱ������
	COrderSysIDType	CombOrderSysID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
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

///��Ա�ʽ�Ӧ��
class CFTDRspPartAccountField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///�ϴν���׼����
	CMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	CMoneyType	CurrMargin;
	///ƽ��ӯ��
	CMoneyType	CloseProfit;
	///��ȨȨ������֧
	CMoneyType	Premium;
	///�����
	CMoneyType	Deposit;
	///������
	CMoneyType	Withdraw;
	///�ڻ�����׼����
	CMoneyType	Balance;
	///�����ʽ�
	CMoneyType	Available;
	///�ʽ��ʺ�
	CAccountIDType	AccountID;
	///����ı�֤��
	CMoneyType	FrozenMargin;
	///�����Ȩ����
	CMoneyType	FrozenPremium;
	///����׼����
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

///��Ա�ֲ�Ӧ��
class CFTDRspPartPositionField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	CPosiDirectionType	PosiDirection;
	///���ճֲ�
	CVolumeType	YdPosition;
	///���ճֲ�
	CVolumeType	Position;
	///��ͷ����
	CVolumeType	LongFrozen;
	///��ͷ����
	CVolumeType	ShortFrozen;
	///���ն�ͷ����
	CVolumeType	YdLongFrozen;
	///���տ�ͷ����
	CVolumeType	YdShortFrozen;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
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

///�ͻ��ֲ�Ӧ��
class CFTDRspClientPositionField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	CPosiDirectionType	PosiDirection;
	///���ճֲ�
	CVolumeType	YdPosition;
	///���ճֲ�
	CVolumeType	Position;
	///��ͷ����
	CVolumeType	LongFrozen;
	///��ͷ����
	CVolumeType	ShortFrozen;
	///���ն�ͷ����
	CVolumeType	YdLongFrozen;
	///���տ�ͷ����
	CVolumeType	YdShortFrozen;
	///������ɽ���
	CVolumeType	BuyTradeVolume;
	///�������ɽ���
	CVolumeType	SellTradeVolume;
	///�ֲֳɱ�
	CMoneyType	PositionCost;
	///���ճֲֳɱ�
	CMoneyType	YdPositionCost;
	///ռ�õı�֤��
	CMoneyType	UseMargin;
	///����ı�֤��
	CMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	CMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	CMoneyType	ShortFrozenMargin;
	///�����Ȩ����
	CMoneyType	FrozenPremium;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
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

///��Լ��ѯӦ��
class CFTDRspInstrumentField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ʒ�����
	CProductGroupIDType	ProductGroupID;
	///������Ʒ����
	CInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	CProductClassType	ProductClass;
	///�ֲ�����
	CPositionTypeType	PositionType;
	///ִ�м�
	CPriceType	StrikePrice;
	///��Ȩ����
	COptionsTypeType	OptionsType;
	///��Լ��������
	CVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	CUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Լ����
	CInstrumentNameType	InstrumentName;
	///�������
	CYearType	DeliveryYear;
	///������
	CMonthType	DeliveryMonth;
	///��ǰ�·�
	CAdvanceMonthType	AdvanceMonth;
	///��ǰ�Ƿ���
	CBoolType	IsTrading;
	///������
	CDateType	CreateDate;
	///������
	CDateType	OpenDate;
	///������
	CDateType	ExpireDate;
	///��ʼ������
	CDateType	StartDelivDate;
	///��󽻸���
	CDateType	EndDelivDate;
	///���ƻ�׼��
	CPriceType	BasisPrice;
	///�м۵�����µ���
	CVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	CVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	CVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	CVolumeType	MinLimitOrderVolume;
	///��С�䶯��λ
	CPriceType	PriceTick;
	///��������Ȼ�˿���
	CMonthCountType	AllowDelivPersonOpen;
	///���ִ���
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

///��Ϣ��ѯ
class CFTDQryInformationField
{
public:
	///��ʼ��Ϣ����
	CInformationIDType	InformationIDStart;
	///������Ϣ����
	CInformationIDType	InformationIDEnd;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InformationIDStart)
		,
		TYPE_DESC(InformationIDEnd)
	));
};
const DWORD FTD_FID_QryInformation=0x3105;

///��Ϣ��ѯ
class CFTDInformationField
{
public:
	///��Ϣ���
	CInformationIDType	InformationID;
	///���к�
	CSequenceNoType	SequenceNo;
	///��Ϣ����
	CContentType	Content;
	///���ĳ���
	CContentLengthType	ContentLength;
	///�Ƿ����
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

///�����޶�
class CFTDCreditLimitField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///�ϴν���׼����
	CMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	CMoneyType	CurrMargin;
	///ƽ��ӯ��
	CMoneyType	CloseProfit;
	///��ȨȨ������֧
	CMoneyType	Premium;
	///�����
	CMoneyType	Deposit;
	///������
	CMoneyType	Withdraw;
	///�ڻ�����׼����
	CMoneyType	Balance;
	///�����ʽ�
	CMoneyType	Available;
	///���׻�Ա���
	CParticipantIDType	ParticipantID;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///����ı�֤��
	CMoneyType	FrozenMargin;
	///�����Ȩ����
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

///�ͻ���ѯӦ��
class CFTDRspClientField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///ԭ֤������
	CIdentifiedCardNoV1Type	UseLess;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��Ա��
	CParticipantIDType	ParticipantID;
	///֤������
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

///����������
class CFTDFlowMessageCancelField
{
public:
	///����ϵ�к�
	CSequenceSeriesType	SequenceSeries;
	///������
	CDateType	TradingDay;
	///�������Ĵ���
	CDataCenterIDType	DataCenterID;
	///������ʼ���к�
	CSequenceNoType	StartSequenceNo;
	///���˽������к�
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

///���ʲ�ѯ
class CFTDQryExchangeRateField
{
public:
	///���ִ���
	CCurrencyIDType	CurrencyID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(CurrencyID)
	));
};
const DWORD FTD_FID_QryExchangeRate=0x310A;

///���ʲ�ѯӦ��
class CFTDRspExchangeRateField
{
public:
	///������
	CDateType	TradingDay;
	///���ִ���
	CCurrencyIDType	CurrencyID;
	///��㽻�׵�λ
	CRateUnitType	RateUnit;
	///����м��
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

///��Ա
class CFTDParticipantField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��Ա���
	CParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	CMemberTypeType	MemberType;
	///�Ƿ��Ծ
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

///�û�
class CFTDUserField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�����û�����
	CUserTypeType	UserType;
	///����
	CPasswordType	Password;
	///����ԱȨ��
	CUserActiveType	IsActive;
	///����Ա�Ƿ��ֱֹ������ǰ��
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

///�ͻ�
class CFTDClientField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
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

///�û��Ự
class CFTDUserSessionField
{
public:
	///ǰ�ñ��
	CFrontIDType	FrontID;
	///�����û�����
	CUserIDType	UserID;
	///�����û�����
	CUserTypeType	UserType;
	///�Ự���
	CSessionIDType	SessionID;
	///��¼ʱ��
	CTimeType	LoginTime;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�û��˲�Ʒ��Ϣ
	CProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	CProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	CProtocolInfoType	ProtocolInfo;
	///�Ự����
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

///��Ʒ��
class CFTDProductGroupField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ�����
	CProductGroupIDType	ProductGroupID;
	///��Ʒ������
	CProductGroupNameType	ProductGroupName;
	///��Ʒ����
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

///��Ʒ
class CFTDProductField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ʒ�����
	CProductGroupIDType	ProductGroupID;
	///��Ʒ����
	CProductNameType	ProductName;
	///��Ʒ����
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

///��Լ
class CFTDInstrumentField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ʒ�����
	CProductGroupIDType	ProductGroupID;
	///������Ʒ����
	CInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	CProductClassType	ProductClass;
	///�ֲ�����
	CPositionTypeType	PositionType;
	///ִ�м�
	CPriceType	StrikePrice;
	///��Ȩ����
	COptionsTypeType	OptionsType;
	///��Լ��������
	CVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	CUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Լ����
	CInstrumentNameType	InstrumentName;
	///�������
	CYearType	DeliveryYear;
	///������
	CMonthType	DeliveryMonth;
	///��ǰ�·�
	CAdvanceMonthType	AdvanceMonth;
	///��ǰ�Ƿ���
	CBoolType	IsTrading;
	///���ִ���
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

///��Ͻ��׺�Լ�ĵ���
class CFTDCombinationLegField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ϻ�Լ����
	CInstrumentIDType	CombInstrumentID;
	///���ȱ��
	CLegIDType	LegID;
	///���Ⱥ�Լ����
	CInstrumentIDType	LegInstrumentID;
	///��������
	CDirectionType	Direction;
	///���ȳ���
	CLegMultipleType	LegMultiple;
	///�Ƶ�����
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

///�˻��ʽ���Ϣ
class CFTDAccountInfoField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///�ϴν���׼����
	CMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	CMoneyType	CurrMargin;
	///ƽ��ӯ��
	CMoneyType	CloseProfit;
	///��ȨȨ������֧
	CMoneyType	Premium;
	///�����
	CMoneyType	Deposit;
	///������
	CMoneyType	Withdraw;
	///�ڻ�����׼����
	CMoneyType	Balance;
	///�����ʽ�
	CMoneyType	Available;
	///��������
	CDateType	DateAccountOpen;
	///�ϴν��������
	CDateType	PreDate;
	///�Ͻ���ı��
	CSettlementIDType	PreSettlementID;
	///�ϴα�֤���ܶ�
	CMoneyType	PreMargin;
	///�ڻ���֤��
	CMoneyType	FuturesMargin;
	///��Ȩ��֤��
	CMoneyType	OptionsMargin;
	///�ֲ�ӯ��
	CMoneyType	PositionProfit;
	///����ӯ��
	CMoneyType	Profit;
	///��Ϣ����
	CMoneyType	Interest;
	///������
	CMoneyType	Fee;
	///����Ѻ���
	CMoneyType	TotalCollateral;
	///����Ѻ�ֵı�֤����
	CMoneyType	CollateralForMargin;
	///�ϴ��ʽ���Ϣ����
	CMoneyType	PreAccmulateInterest;
	///�ʽ���Ϣ����
	CMoneyType	AccumulateInterest;
	///��Ѻ�����ѻ���
	CMoneyType	AccumulateFee;
	///�����ʽ�
	CMoneyType	ForzenDeposit;
	///�ʻ�״̬
	CAccountStatusType	AccountStatus;
	///�ʽ��ʺ�
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

///��Ա��Լ�ֲ�
class CFTDPartPositionField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	CPosiDirectionType	PosiDirection;
	///���ճֲ�
	CVolumeType	YdPosition;
	///���ճֲ�
	CVolumeType	Position;
	///��ͷ����
	CVolumeType	LongFrozen;
	///��ͷ����
	CVolumeType	ShortFrozen;
	///���ն�ͷ����
	CVolumeType	YdLongFrozen;
	///���տ�ͷ����
	CVolumeType	YdShortFrozen;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
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

///�ͻ���Լ�ֲ�
class CFTDClientPositionField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	CPosiDirectionType	PosiDirection;
	///���ճֲ�
	CVolumeType	YdPosition;
	///���ճֲ�
	CVolumeType	Position;
	///��ͷ����
	CVolumeType	LongFrozen;
	///��ͷ����
	CVolumeType	ShortFrozen;
	///���ն�ͷ����
	CVolumeType	YdLongFrozen;
	///���տ�ͷ����
	CVolumeType	YdShortFrozen;
	///������ɽ���
	CVolumeType	BuyTradeVolume;
	///�������ɽ���
	CVolumeType	SellTradeVolume;
	///�ֲֳɱ�
	CMoneyType	PositionCost;
	///���ճֲֳɱ�
	CMoneyType	YdPositionCost;
	///ռ�õı�֤��
	CMoneyType	UseMargin;
	///����ı�֤��
	CMoneyType	FrozenMargin;
	///��ͷ����ı�֤��
	CMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	CMoneyType	ShortFrozenMargin;
	///�����Ȩ����
	CMoneyType	FrozenPremium;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
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

///��ֵ�����
class CFTDHedgeVolumeField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��ͷ��ֵ������������
	CVolumeType	LongVolumeOriginal;
	///��ͷ��ֵ������������
	CVolumeType	ShortVolumeOriginal;
	///��ͷ��ֵ���
	CVolumeType	LongVolume;
	///��ͷ��ֵ���
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

///�г�����
class CFTDMarketDataField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///���¼�
	CPriceType	LastPrice;
	///�����
	CPriceType	PreSettlementPrice;
	///������
	CPriceType	PreClosePrice;
	///��ֲ���
	CLargeVolumeType	PreOpenInterest;
	///����
	CPriceType	OpenPrice;
	///��߼�
	CPriceType	HighestPrice;
	///��ͼ�
	CPriceType	LowestPrice;
	///����
	CVolumeType	Volume;
	///�ɽ����
	CMoneyType	Turnover;
	///�ֲ���
	CLargeVolumeType	OpenInterest;
	///������
	CPriceType	ClosePrice;
	///�����
	CPriceType	SettlementPrice;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
	CPriceType	LowerLimitPrice;
	///����ʵ��
	CRatioType	PreDelta;
	///����ʵ��
	CRatioType	CurrDelta;
	///����޸�ʱ��
	CTimeType	UpdateTime;
	///����޸ĺ���
	CMillisecType	UpdateMillisec;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///ҵ��������
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

///����г�����
class CFTDDepthMarketDataField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///���¼�
	CPriceType	LastPrice;
	///�����
	CPriceType	PreSettlementPrice;
	///������
	CPriceType	PreClosePrice;
	///��ֲ���
	CLargeVolumeType	PreOpenInterest;
	///����
	CPriceType	OpenPrice;
	///��߼�
	CPriceType	HighestPrice;
	///��ͼ�
	CPriceType	LowestPrice;
	///����
	CVolumeType	Volume;
	///�ɽ����
	CMoneyType	Turnover;
	///�ֲ���
	CLargeVolumeType	OpenInterest;
	///������
	CPriceType	ClosePrice;
	///�����
	CPriceType	SettlementPrice;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
	CPriceType	LowerLimitPrice;
	///����ʵ��
	CRatioType	PreDelta;
	///����ʵ��
	CRatioType	CurrDelta;
	///����޸�ʱ��
	CTimeType	UpdateTime;
	///����޸ĺ���
	CMillisecType	UpdateMillisec;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�����һ
	CPriceType	BidPrice1;
	///������һ
	CVolumeType	BidVolume1;
	///������һ
	CPriceType	AskPrice1;
	///������һ
	CVolumeType	AskVolume1;
	///����۶�
	CPriceType	BidPrice2;
	///��������
	CVolumeType	BidVolume2;
	///�����۶�
	CPriceType	AskPrice2;
	///��������
	CVolumeType	AskVolume2;
	///�������
	CPriceType	BidPrice3;
	///��������
	CVolumeType	BidVolume3;
	///��������
	CPriceType	AskPrice3;
	///��������
	CVolumeType	AskVolume3;
	///�������
	CPriceType	BidPrice4;
	///��������
	CVolumeType	BidVolume4;
	///��������
	CPriceType	AskPrice4;
	///��������
	CVolumeType	AskVolume4;
	///�������
	CPriceType	BidPrice5;
	///��������
	CVolumeType	BidVolume5;
	///��������
	CPriceType	AskPrice5;
	///��������
	CVolumeType	AskVolume5;
	///ҵ��������
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

///�ּ۱�
class CFTDMBLMarketDataField
{
public:
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��������
	CDirectionType	Direction;
	///�۸�
	CPriceType	Price;
	///����
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

///��������
class CFTDAliasDefineField
{
public:
	///��ʼλ��
	CStartPosType	StartPos;
	///����
	CAliasType	Alias;
	///ԭ��
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

///�����������
class CFTDMarketDataBaseField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///�����
	CPriceType	PreSettlementPrice;
	///������
	CPriceType	PreClosePrice;
	///��ֲ���
	CLargeVolumeType	PreOpenInterest;
	///����ʵ��
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

///���龲̬����
class CFTDMarketDataStaticField
{
public:
	///����
	CPriceType	OpenPrice;
	///��߼�
	CPriceType	HighestPrice;
	///��ͼ�
	CPriceType	LowestPrice;
	///������
	CPriceType	ClosePrice;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
	CPriceType	LowerLimitPrice;
	///�����
	CPriceType	SettlementPrice;
	///����ʵ��
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

///�������³ɽ�����
class CFTDMarketDataLastMatchField
{
public:
	///���¼�
	CPriceType	LastPrice;
	///����
	CVolumeType	Volume;
	///�ɽ����
	CMoneyType	Turnover;
	///�ֲ���
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

///�������ż�����
class CFTDMarketDataBestPriceField
{
public:
	///�����һ
	CPriceType	BidPrice1;
	///������һ
	CVolumeType	BidVolume1;
	///������һ
	CPriceType	AskPrice1;
	///������һ
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

///�����������������
class CFTDMarketDataBid23Field
{
public:
	///����۶�
	CPriceType	BidPrice2;
	///��������
	CVolumeType	BidVolume2;
	///�������
	CPriceType	BidPrice3;
	///��������
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

///������������������
class CFTDMarketDataAsk23Field
{
public:
	///�����۶�
	CPriceType	AskPrice2;
	///��������
	CVolumeType	AskVolume2;
	///��������
	CPriceType	AskPrice3;
	///��������
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

///���������ġ�������
class CFTDMarketDataBid45Field
{
public:
	///�������
	CPriceType	BidPrice4;
	///��������
	CVolumeType	BidVolume4;
	///�������
	CPriceType	BidPrice5;
	///��������
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

///���������ġ�������
class CFTDMarketDataAsk45Field
{
public:
	///��������
	CPriceType	AskPrice4;
	///��������
	CVolumeType	AskVolume4;
	///��������
	CPriceType	AskPrice5;
	///��������
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

///�������ʱ������
class CFTDMarketDataUpdateTimeField
{
public:
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	CTimeType	UpdateTime;
	///����޸ĺ���
	CMillisecType	UpdateMillisec;
	///ҵ��������
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

///����
class CFTDQuoteField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///���۱��
	CQuoteSysIDType	QuoteSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///����
	CVolumeType	Volume;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///���ر��۱��
	COrderLocalIDType	QuoteLocalID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����Ͽ�ƽ��־
	CCombOffsetFlagType	BidCombOffsetFlag;
	///������ױ���־
	CCombHedgeFlagType	BidCombHedgeFlag;
	///�򷽼۸�
	CPriceType	BidPrice;
	///������Ͽ�ƽ��־
	CCombOffsetFlagType	AskCombOffsetFlag;
	///��������ױ���־
	CCombHedgeFlagType	AskCombHedgeFlag;
	///�����۸�
	CPriceType	AskPrice;
	///����ʱ��
	CTimeType	InsertTime;
	///����ʱ��
	CTimeType	CancelTime;
	///�ɽ�ʱ��
	CTimeType	TradeTime;
	///�򷽱������
	COrderSysIDType	BidOrderSysID;
	///�����������
	COrderSysIDType	AskOrderSysID;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///ҵ��������
	CDateType	ActionDay;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///�ɽ�
class CFTDTradeField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///�ɽ����
	CTradeIDType	TradeID;
	///��������
	CDirectionType	Direction;
	///�������
	COrderSysIDType	OrderSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ʽ��ʺ�
	CAccountIDType	AccountID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��ƽ��־
	COffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�۸�
	CPriceType	Price;
	///����
	CVolumeType	Volume;
	///�ɽ�ʱ��
	CTimeType	TradeTime;
	///�ɽ�����
	CTradeTypeType	TradeType;
	///�ɽ�����Դ
	CPriceSourceType	PriceSource;
	///�����û�����
	CUserIDType	UserID;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///ҵ��������
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

///����
class CFTDOrderField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///�������
	COrderSysIDType	OrderSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�����۸�����
	COrderPriceTypeType	OrderPriceType;
	///��������
	CDirectionType	Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType	TimeCondition;
	///GTD����
	CDateType	GTDDate;
	///�ɽ�������
	CVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	CVolumeType	MinVolume;
	///��������
	CContingentConditionType	ContingentCondition;
	///ֹ���
	CPriceType	StopPrice;
	///ǿƽԭ��
	CForceCloseReasonType	ForceCloseReason;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///�Զ������־
	CBoolType	IsAutoSuspend;
	///������Դ
	COrderSourceType	OrderSource;
	///����״̬
	COrderStatusType	OrderStatus;
	///��������
	COrderTypeType	OrderType;
	///��ɽ�����
	CVolumeType	VolumeTraded;
	///ʣ������
	CVolumeType	VolumeTotal;
	///��������
	CDateType	InsertDate;
	///����ʱ��
	CTimeType	InsertTime;
	///����ʱ��
	CTimeType	ActiveTime;
	///����ʱ��
	CTimeType	SuspendTime;
	///����޸�ʱ��
	CTimeType	UpdateTime;
	///����ʱ��
	CTimeType	CancelTime;
	///����޸Ľ����û�����
	CUserIDType	ActiveUserID;
	///����Ȩ
	CPriorityType	Priority;
	///��ʱ���Ŷӵ����
	CTimeSortIDType	TimeSortID;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///ҵ��������
	CDateType	ActionDay;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///ִ������
class CFTDExecOrderField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///��Լ���
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///����ִ��������
	COrderLocalIDType	ExecOrderLocalID;
	///����
	CVolumeType	Volume;
	///��ƽ��־
	COffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///�ֲַ���
	CPosiDirectionType	PosiDirection;
	///��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı��
	CExecOrderPositionFlagType	ReservePositionFlag;
	///��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ��
	CExecOrderCloseFlagType	CloseFlag;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///ִ��������
	CExecOrderSysIDType	ExecOrderSysID;
	///��������
	CDateType	InsertDate;
	///����ʱ��
	CTimeType	InsertTime;
	///����ʱ��
	CTimeType	CancelTime;
	///ִ�н��
	CExecResultType	ExecResult;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///ҵ��������
	CDateType	ActionDay;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///�Ǳ���ϱ���
class CFTDCombOrderField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///��ϱ������
	COrderSysIDType	CombOrderSysID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�����û�����
	CUserIDType	UserID;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///���ر������
	COrderLocalIDType	CombOrderLocalID;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///��Լ����1
	CInstrumentIDType	InstrumentID1;
	///��������1
	CDirectionType	Direction1;
	///���ȳ���1
	CLegMultipleType	LegMultiple1;
	///��ƽ��־1
	COffsetFlagType	OffsetFlag1;
	///Ͷ���ױ���־1
	CHedgeFlagType	HedgeFlag1;
	///��Լ����2
	CInstrumentIDType	InstrumentID2;
	///��������2
	CDirectionType	Direction2;
	///���ȳ���2
	CLegMultipleType	LegMultiple2;
	///��ƽ��־2
	COffsetFlagType	OffsetFlag2;
	///Ͷ���ױ���־2
	CHedgeFlagType	HedgeFlag2;
	///��Լ����3
	CInstrumentIDType	InstrumentID3;
	///��������3
	CDirectionType	Direction3;
	///���ȳ���3
	CLegMultipleType	LegMultiple3;
	///��ƽ��־3
	COffsetFlagType	OffsetFlag3;
	///Ͷ���ױ���־3
	CHedgeFlagType	HedgeFlag3;
	///��Լ����4
	CInstrumentIDType	InstrumentID4;
	///��������4
	CDirectionType	Direction4;
	///���ȳ���4
	CLegMultipleType	LegMultiple4;
	///��ƽ��־4
	COffsetFlagType	OffsetFlag4;
	///Ͷ���ױ���־4
	CHedgeFlagType	HedgeFlag4;
	///������Դ
	COrderSourceType	OrderSource;
	///��ɽ�����
	CVolumeType	VolumeTraded;
	///ʣ������
	CVolumeType	VolumeTotal;
	///��������
	CDateType	InsertDate;
	///����ʱ��
	CTimeType	InsertTime;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///����ҵ���ʶ
	CBusinessLocalIDType	BusinessLocalID;
	///ҵ��������
	CDateType	ActionDay;
	///IP��ַ
	CIPAddressType	IPAddress;
	///Mac��ַ
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

///������
class CFTDAdminOrderField
{
public:
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///����������
	CAdminOrderCommandFlagType	AdminOrderCommand;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///���׻�Ա���
	CParticipantIDType	ParticipantID;
	///���
	CMoneyType	Amount;
	///���������
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

///����������
class CFTDInputAdminOrderField
{
public:
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///����������
	CAdminOrderCommandFlagType	AdminOrderCommand;
	///�����Ա���
	CParticipantIDType	ClearingPartID;
	///���׻�Ա���
	CParticipantIDType	ParticipantID;
	///���
	CMoneyType	Amount;
	///���������
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

///����
class CFTDBulletinField
{
public:
	///������
	CDateType	TradingDay;
	///������
	CBulletinIDType	BulletinID;
	///���к�
	CSequenceNoType	SequenceNo;
	///��������
	CNewsTypeType	NewsType;
	///�����̶�
	CNewsUrgencyType	NewsUrgency;
	///����ʱ��
	CTimeType	SendTime;
	///��ϢժҪ
	CAbstractType	Abstract;
	///��Ϣ��Դ
	CComeFromType	ComeFrom;
	///��Ϣ����
	CContentType	Content;
	///WEB��ַ
	CURLLinkType	URLLink;
	///�г�����
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

///����������ͬ��״̬
class CFTDExchangeDataSyncStatusField
{
public:
	///������
	CDateType	TradingDay;
	///����������
	CExchangeIDType	ExchangeID;
	///����������ͬ��״̬
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

///����������ͬ��״̬
class CFTDSGDataSyncStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CDateType	TradingDay;
	///������
	CSettlementIDType	SettlementID;
	///����������ͬ��״̬
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

///��Լ״̬
class CFTDInstrumentStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	CTimeType	EnterTime;
	///���뱾״̬ԭ��
	CInstStatusEnterReasonType	EnterReason;
	///���뱾״̬����
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

///�ͻ��ֲֲ�ѯ
class CFTDQryClientPositionV1Field
{
public:
	///��ʼ��Ա����
	CParticipantIDType	PartIDStart;
	///������Ա����
	CParticipantIDType	PartIDEnd;
	///��ʼ�ͻ�����
	CClientIDType	ClientIDStart;
	///�����ͻ�����
	CClientIDType	ClientIDEnd;
	///��ʼ��Լ����
	CInstrumentIDType	InstIDStart;
	///������Լ����
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

///�û����ز���
class CFTDUserCommFluxControlField
{
public:
	///����ױ����ٶ�
	CCommFluxType	MaxTradeCommFlux;
	///�������;������Ŀ
	CCommFluxType	MaxTradeOnWayCommFlux;
	///����ѯ�����ٶ�
	CCommFluxType	MaxQueryCommFlux;
	///����ѯ��;������Ŀ
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

///��·����
class CFTDLoopMeasureField
{
public:
	///�û����
	CUserIDType	UserID;
	///�Ự����
	CSessionTypeType	SessionType;
	///�������к�
	CSequenceNoType	MeasureSeq;
	///ǰ�ñ��
	CFrontIDType	FrontID;
	///�Ự���
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

///�ڵ����
class CFTDNodeMeasureField
{
public:
	///�ڵ��� 
	CBusinessUnitType	NodeID;
	///�׶α��
	CPeriodIDType	PeriodID;
	///��·���Ķ���ʱ���
	CMeasureSecType	Sec;
	///��·���Ķ���ʱ���΢��ֵ
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

///���������Ϣ
class CFTDMDProxyField
{
public:
	///������
	CFrontIDType	ProxyID;
	///��һ�����Ự���
	CSessionIDType	UpperProxySessionID;
	///����Ự���
	CSessionIDType	CurrProxySessionID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///������
	CSequenceNoType	RequestID;
	///�������
	CDepthType	Depth;
	///����״̬
	CSessionStatusType	SessionStatus;
	///ɾ���ĻỰ���
	CSessionIDType	DeletedSessionID;
	///���ͨѶ��
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

///CPU��Դʹ�ò�ѯ
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
	///�������ı��
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

///CPU��Դʹ����Ϣ
class CFTDRspQryTopCpuInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///CPU�ı��
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

///CPU��Դʹ����Ϣ
class CFTDRtnTopCpuInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///CPU�ı��
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

///Mem��Դʹ�ò�ѯ
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
	///�������ı��
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

///Mem��Դʹ����Ϣ
class CFTDRspQryTopMemInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///Mem��Դʹ����Ϣ
class CFTDRtnTopMemInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///process��Դʹ�ò�ѯ
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
	///�������ı��
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

///process��Դʹ����Ϣ
class CFTDRspQryTopProcessInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///��������
	CTypeCPUIdType	CPU;
	///�ն���
	CTypeChar10Type	TTY;
	///���̺�
	CVolumeType	PID;
	///�û���
	CTypeChar10Type	USERNAME;
	///��������ȼ�
	CVolumeType	PRI;
	///�����niceֵ
	CVolumeType	NI;
	///����Ĵ�����������ټ���ջ�ռ�Ĵ�С
	CVolumeType	SIZE;
	///����ʹ�õ������ڴ��������
	CVolumeType	RES;
	///�����״̬
	CTypeChar10Type	STATE;
	///������ʼʱʹ�õ���CPUʱ��
	CTimeType	TIME;
	///���̵�CPU������Ȩ�ذٷֱ�
	CRatioType	pWCPU;
	///���̵�ԭʼ��CPU�����ʰٷֱ�
	CRatioType	pCPU;
	///�������̵�������
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

///process��Դʹ����Ϣ
class CFTDRtnTopProcessInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///��������
	CTypeCPUIdType	CPU;
	///�ն���
	CTypeChar10Type	TTY;
	///���̺�
	CVolumeType	PID;
	///�û���
	CTypeChar10Type	USERNAME;
	///��������ȼ�
	CVolumeType	PRI;
	///�����niceֵ
	CVolumeType	NI;
	///����Ĵ�����������ټ���ջ�ռ�Ĵ�С
	CVolumeType	SIZE;
	///����ʹ�õ������ڴ��������
	CVolumeType	RES;
	///�����״̬
	CTypeChar10Type	STATE;
	///������ʼʱʹ�õ���CPUʱ��
	CTimeType	TIME;
	///���̵�CPU������Ȩ�ذٷֱ�
	CRatioType	pWCPU;
	///���̵�ԭʼ��CPU�����ʰٷֱ�
	CRatioType	pCPU;
	///�������̵�������
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

///filesystem��Դʹ�ò�ѯ
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
	///�������ı��
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

///filesystem��Դʹ����Ϣ
class CFTDRspQryFileSystemInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ļ�ϵͳ������
	CTypeCommandType	FILESYSTEM;
	///�ռ�����
	CVolumeType	SIZE;
	///���ÿռ��С
	CVolumeType	USED;
	///���ÿռ��С
	CVolumeType	AVAIL;
	///���õİٷֱ�
	CRatioType	pUSERD;
	///inode����
	CVolumeType	ISIZE;
	///����inode��С
	CVolumeType	IUSED;
	///����inode��С
	CVolumeType	IFREE;
	///���õİٷֱ�
	CRatioType	pIUSED;
	///����λ��
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

///filesystem��Դʹ����Ϣ
class CFTDRtnFileSystemInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ļ�ϵͳ������
	CTypeCommandType	FILESYSTEM;
	///�ռ�����
	CVolumeType	SIZE;
	///���ÿռ��С
	CVolumeType	USED;
	///���ÿռ��С
	CVolumeType	AVAIL;
	///���õİٷֱ�
	CRatioType	pUSERD;
	///inode����
	CVolumeType	ISIZE;
	///����inode��С
	CVolumeType	IUSED;
	///����inode��С
	CVolumeType	IFREE;
	///���õİٷֱ�
	CRatioType	pIUSED;
	///����λ��
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

///network��Դʹ�ò�ѯ
class CFTDReqQryNetworkInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///������
	CTypeLanNameType	LANNAME;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///�������ı��
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

///network��Դʹ����Ϣ
class CFTDRspQryNetworkInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///������
	CTypeLanNameType	LANNAME;
	///������up��down״̬
	CTypeLanStatusType	LANSTATUS;
	///������ip��ַ
	CIPAddressType	IPADDRESS;
	///�������յ�����
	CLargeNumberType	RECVBYTES;
	///�������յ����ݰ�
	CLargeNumberType	RECVPACKETS;
	///�������ն˴������ݰ�
	CLargeNumberType	RECVERRORPACKETS;
	///�������ն˶�ʧ���ݰ�
	CLargeNumberType	RECVDROPPACKETS;
	///�������͵�����
	CLargeNumberType	SENDBYTES;
	///�������͵����ݰ�
	CLargeNumberType	SENDPACKETS;
	///�������Ͷ˴������ݰ�
	CLargeNumberType	SENDERRORPACKETS;
	///�������Ͷ˶�ʧ���ݰ�
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

///network��Դʹ����Ϣ
class CFTDRtnNetworkInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///������
	CTypeLanNameType	LANNAME;
	///������up��down״̬
	CTypeLanStatusType	LANSTATUS;
	///������ip��ַ
	CIPAddressType	IPADDRESS;
	///�������յ�����
	CLargeNumberType	RECVBYTES;
	///�������յ����ݰ�
	CLargeNumberType	RECVPACKETS;
	///�������ն˴������ݰ�
	CLargeNumberType	RECVERRORPACKETS;
	///�������ն˶�ʧ���ݰ�
	CLargeNumberType	RECVDROPPACKETS;
	///�������͵�����
	CLargeNumberType	SENDBYTES;
	///�������͵����ݰ�
	CLargeNumberType	SENDPACKETS;
	///�������Ͷ˴������ݰ�
	CLargeNumberType	SENDERRORPACKETS;
	///�������Ͷ˶�ʧ���ݰ�
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

///����������Ϣ��ѯ����
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
	///�������ı��
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

///����������ϢӦ����Ϣ
class CFTDRspQryHostEnvCommonField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�����ͺ�
	CTypeHostModelType	HostModel;
	///�ڴ��С(K)
	CVolumeType	MainMemory;
	///CPU����
	CTypeHostModelType	CPUVendor;
	///CPU�ͺ�
	CTypeHostModelType	CPUModel;
	///CPU��Ƶ
	CTypeHostModelType	CPUMHz;
	///CPU����
	CTypeHostModelType	CPUCache;
	///CPU�ں���
	CVolumeType	CPUCores;
	///CPU����
	CVolumeType	Processors;
	///32λ����64λ����ϵͳ
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

///����������ϢӦ����Ϣ
class CFTDRspQryHostEnvLanField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///LanID
	CTypeHostModelType	LanHardwareID;
	///Mac��ַ
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

///����������ϢӦ����Ϣ
class CFTDRspQryHostEnvStorageField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///����������ϢӦ����Ϣ
class CFTDRspQryHostEnvIOField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///����������ϢӦ����Ϣ
class CFTDRspQryHostEnvFSField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///����������ϢӦ����Ϣ
class CFTDRspQryHostEnvSwapField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///����������ϢӦ����Ϣ
class CFTDRspQryHostEnvLanCfgField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///�ͻ��˵�¼��ѯ����
class CFTDReqQryClientLoginField
{
public:
	///��¼�û���
	CTypeUserNameType	UserName;
	///��¼����
	CTypeUserNameType	PassWord;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserName)
		,
		TYPE_DESC(PassWord)
	));
};
const DWORD FTD_FID_ReqQryClientLogin=0x502A;

///�ͻ��˵�¼Ӧ����Ϣ
class CFTDRspQryClientLoginField
{
public:
	///��¼�û���
	CTypeUserNameType	UserName;
	///��¼Ȩ��
	CTypeUserNameType	Privalage;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserName)
		,
		TYPE_DESC(Privalage)
	));
};
const DWORD FTD_FID_RspQryClientLogin=0x502B;

///��ü�ض�����Ϣ��ѯ����
class CFTDReqQryMonitorObjectField
{
public:
	///ҵ����̶���ID
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///�������ı��
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

///��ü�ض�����ϢӦ����Ϣ
class CFTDRspQryMonitorObjectField
{
public:
	///ҵ����̶���ID
	CTypeObjectIDType	ObjectID;
	///����ҵ����̶�������
	CTypeLongObjectNameType	ObjectName;
	///�澯�¼�������־λ
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

///��ü�ض�����ϢӦ����Ϣ
class CFTDRtnMonitorObjectField
{
public:
	///ҵ����̶���ID
	CTypeObjectIDType	ObjectID;
	///����ҵ����̶�������
	CTypeLongObjectNameType	ObjectName;
	///�澯�¼�������־λ
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

///���ҵ����̺������Ķ�Ӧ��ϵ��ѯ����
class CFTDReqQryObjectRationalField
{
public:
	///ҵ����̶���ID
	CTypeObjectIDType	ObjectID;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///�������ı��
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

///���ҵ����̺������Ķ�Ӧ��ϵӦ����Ϣ
class CFTDRspQryObjectRationalField
{
public:
	///ҵ����̶���ID
	CTypeObjectIDType	ObjectID;
	///ҵ��������ڵ�����ID
	CTypeObjectIDType	HostObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HostObjectID)
	));
};
const DWORD FTD_FID_RspQryObjectRational=0x5030;

///���ҵ����̺������Ķ�Ӧ��ϵӦ����Ϣ
class CFTDRtnObjectRationalField
{
public:
	///ҵ����̶���ID
	CTypeObjectIDType	ObjectID;
	///ҵ��������ڵ�����ID
	CTypeObjectIDType	HostObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HostObjectID)
	));
};
const DWORD FTD_FID_RtnObjectRational=0x5031;

///��־�ļ����ݲ�ѯ����
class CFTDReqQrySyslogInfoField
{
public:
	///�����ļ�·��
	CTypeObjectIDType	FileName;
	///�ļ���
	CTypeObjectIDType	subFileName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FileName)
		,
		TYPE_DESC(subFileName)
	));
};
const DWORD FTD_FID_ReqQrySyslogInfo=0x5038;

///��־�ļ�����Ӧ����Ϣ
class CFTDRspQrySyslogInfoField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///���������
	CTypeObjectIDType	ObjectID;
	///���ָ������
	CAttrTypeType	AttrType;
	///�ļ����ݳ���
	CTypeContLenType	ContLen;
	///�ļ�����
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

///��־�ļ�����Ӧ����Ϣ
class CFTDRtnSyslogInfoField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///���������
	CTypeObjectIDType	ObjectID;
	///���ָ������
	CAttrTypeType	AttrType;
	///�ļ����ݳ���
	CTypeContLenType	ContLen;
	///�ļ�����
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

///������ݶ�������
class CFTDReqQrySubscriberField
{
public:
	///���Ķ�����
	CTypeSubcriberObjectIDType	ObjectID;
	///���η��ض�����
	CVolumeType	ObjectNum;
	///�������ı��
	CTypeKeepAliveType	KeepAlive;
	///���صĳ�ʼ����
	CDateType	MonDate;
	///���صĳ�ʼʱ��
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

///������ݶ���Ӧ����Ϣ
class CFTDRspQrySubscriberField
{
public:
	///�������
	CErrorIDType	ErrorID;
	///������Ϣ
	CErrorMsgType	ErrorMsg;
	///���������
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

///������ݶ���Ӧ����Ϣ
class CFTDRtnSubscriberField
{
public:
	///�������
	CErrorIDType	ErrorID;
	///������Ϣ
	CErrorMsgType	ErrorMsg;
	///���������
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

///�����ϵ��ѯ����
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

///�����ϵ��ѯӦ����Ϣ
class CFTDRspQryOidRelationField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///���������
	CTypeObjectIDType	HoldObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HoldObjectID)
	));
};
const DWORD FTD_FID_RspQryOidRelation=0x5197;

///�����ϵ��ѯӦ����Ϣ
class CFTDRtnOidRelationField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///���������
	CTypeObjectIDType	HoldObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(HoldObjectID)
	));
};
const DWORD FTD_FID_RtnOidRelation=0x5198;

///�û���Ϣ��ѯ����
class CFTDReqQryUserInfoField
{
public:
	///���������
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

///�û���Ϣ��ѯӦ����Ϣ
class CFTDRspQryUserInfoField
{
public:
	///�û���
	CTypeUserNameType	USERNAME;
	///�û�ID
	CVolumeType	USERID;
	///�û�����
	CTypeUserNameType	GROUPNAME;
	///�û���ID
	CVolumeType	GROUPID;
	///HOME·��
	CTypeUserNameType	HOMEPATH;
	///�û�ʹ��SHELL����
	CTypeUserNameType	SHELL;
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ɼ�������
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

///�û���Ϣ��ѯӦ����Ϣ
class CFTDRtnUserInfoField
{
public:
	///�û���
	CTypeUserNameType	USERNAME;
	///�û�ID
	CVolumeType	USERID;
	///�û�����
	CTypeUserNameType	GROUPNAME;
	///�û���ID
	CVolumeType	GROUPID;
	///HOME·��
	CTypeUserNameType	HOMEPATH;
	///�û�ʹ��SHELL����
	CTypeUserNameType	SHELL;
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ɼ�������
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

///�����û���Ϣ��ѯ����
class CFTDReqQryOnlineUserInfoField
{
public:
	///���������
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

///�����û���ϢӦ����Ϣ
class CFTDRspQryOnlineUserInfoField
{
public:
	///�û���
	CTypeUserNameType	USERNAME;
	///��¼ʱ��
	CTypeUserNameType	TIME;
	///�ն�����
	CTypeUserNameType	TTY;
	///IP��ַ
	CTypeUserNameType	IP;
	///����ʱ��
	CTypeUserNameType	CONNECTIME;
	///����ID
	CVolumeType	PID;
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ɼ�������
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

///�����û���ϢӦ����Ϣ
class CFTDRtnOnlineUserInfoField
{
public:
	///�û���
	CTypeUserNameType	USERNAME;
	///��¼ʱ��
	CTypeUserNameType	TIME;
	///�ն�����
	CTypeUserNameType	TTY;
	///IP��ַ
	CTypeUserNameType	IP;
	///����ʱ��
	CTypeUserNameType	CONNECTIME;
	///����ID
	CVolumeType	PID;
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ɼ�������
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

///�澯�¼�
class CFTDSysWarningEventField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼���������
	CDateType	OccurDate;
	///�¼�����ʱ��
	CTimeType	OccurTime;
	///�¼�ID
	CVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�¼���
	CTypeObjectIDType	EventName;
	///�¼���ǩ
	CVolumeType	EventNum;
	///�¼�����
	CVolumeType	EventType;
	///�¼�����
	CTypeDescriptionType	EventDes;
	///������
	CTypeProcessFlagType	ProcessFlag;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�¼���������
	CTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
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

///�澯�¼���ѯ����
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
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�¼�����
	CVolumeType	EventType;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///�¼���
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

///�澯�¼�Ӧ����Ϣ
class CFTDRspQryWarningEventField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼���������
	CDateType	OccurDate;
	///�¼�����ʱ��
	CTimeType	OccurTime;
	///�¼�ID
	CVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�¼���
	CTypeObjectIDType	EventName;
	///�¼���ǩ
	CVolumeType	EventNum;
	///�¼�����
	CVolumeType	EventType;
	///�¼�����
	CTypeDescriptionType	EventDes;
	///������
	CTypeProcessFlagType	ProcessFlag;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�¼���������
	CTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
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

///�澯�¼�Ӧ����Ϣ
class CFTDRtnWarningEventField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼���������
	CDateType	OccurDate;
	///�¼�����ʱ��
	CTimeType	OccurTime;
	///�¼�ID
	CVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�¼���
	CTypeObjectIDType	EventName;
	///�¼���ǩ
	CVolumeType	EventNum;
	///�¼�����
	CVolumeType	EventType;
	///�¼�����
	CTypeDescriptionType	EventDes;
	///������
	CTypeProcessFlagType	ProcessFlag;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�¼���������
	CTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	CNetAttrTypeType	FullEventName;
	///�¼�����
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

///KeyFile����
class CFTDReqQryKeyFileInfoField
{
public:
	///�����ļ���ID
	CTypeObjectIDType	FileName;
	///�����ļ���·��
	CTypeObjectIDType	PathName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FileName)
		,
		TYPE_DESC(PathName)
	));
};
const DWORD FTD_FID_ReqQryKeyFileInfo=0x5214;

///HostMonitorCfg����
class CFTDReqQryHostMonitorCfgField
{
public:
	///
	CTypeMonitorTypeType	MonitorType;
	///�����ļ���·��
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

///AppMonitorCfg����
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

///CPUʹ���ʲ�ѯ����
class CFTDReqQryCPUUsageField
{
public:
	///���������
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

///CPUʹ����Ӧ����Ϣ
class CFTDRspQryCPUUsageField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///CPUʹ����
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

///CPUʹ����Ӧ����Ϣ
class CFTDRtnCPUUsageField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///CPUʹ����
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

///�ڴ�ʹ���ʲ�ѯ����
class CFTDReqQryMemoryUsageField
{
public:
	///���������
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

///�ڴ�ʹ����Ӧ����Ϣ
class CFTDRspQryMemoryUsageField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ڴ�ʹ����
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

///�ڴ�ʹ����Ӧ����Ϣ
class CFTDRtnMemoryUsageField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�ڴ�ʹ����
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

///Ӳ��ʹ���ʲ�ѯ����
class CFTDReqQryDiskUsageField
{
public:
	///���������
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

///Ӳ��ʹ����Ӧ����Ϣ
class CFTDRspQryDiskUsageField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///Ӳ��ʹ����
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

///Ӳ��ʹ����Ӧ����Ϣ
class CFTDRtnDiskUsageField
{
public:
	///���������
	CTypeObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///Ӳ��ʹ����
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

///����״ָ̬���ѯ
class CFTDReqQryObjectAttrField
{
public:
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
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

///����״ָ̬���ѯӦ��
class CFTDRspQryObjectAttrField
{
public:
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
	CNetAttrTypeType	AttrType;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///���ָ���ֵ����
	CValueTypeType	ValueType;
	///���ָ��ľ���ֵ
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

///����״ָ̬���ѯӦ��
class CFTDRtnObjectAttrField
{
public:
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
	CNetAttrTypeType	AttrType;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///���ָ���ֵ����
	CValueTypeType	ValueType;
	///���ָ��ľ���ֵ
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

///�������ò�ѯ����
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

///��Ч������ѯ
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

///��Ч������ѯӦ��
class CFTDRspQryInvalidateOrderField
{
public:
	///�������
	COrderSysIDType	OrderSysID;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///������Ϣ
	CErrorMsgType	ErrorMsg;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��������
	CDirectionType	Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType	TimeCondition;
	///�ɽ�������
	CVolumeConditionType	VolumeCondition;
	///��С�ɽ���
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

///��Ч������ѯӦ��
class CFTDRtnInvalidateOrderField
{
public:
	///�������
	COrderSysIDType	OrderSysID;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///������Ϣ
	CErrorMsgType	ErrorMsg;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��������
	CDirectionType	Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType	TimeCondition;
	///�ɽ�������
	CVolumeConditionType	VolumeCondition;
	///��С�ɽ���
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

///����״̬��ѯ
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

///����״̬��ѯӦ��
class CFTDRspQryOrderStatusField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�������
	COrderSysIDType	OrderSysID;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///��������
	CDateType	InsertDate;
	///����ʱ��
	CTimeType	InsertTime;
	///����״̬
	COrderStatusType	OrderStatus;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��������
	CDirectionType	Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType	TimeCondition;
	///�ɽ�������
	CVolumeConditionType	VolumeCondition;
	///��С�ɽ���
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

///����״̬��ѯӦ��
class CFTDRtnOrderStatusField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�������
	COrderSysIDType	OrderSysID;
	///���ر������
	COrderLocalIDType	OrderLocalID;
	///��������
	CDateType	InsertDate;
	///����ʱ��
	CTimeType	InsertTime;
	///����״̬
	COrderStatusType	OrderStatus;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��������
	CDirectionType	Direction;
	///��Ͽ�ƽ��־
	CCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	CCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	CPriceType	LimitPrice;
	///����
	CVolumeType	VolumeTotalOriginal;
	///��Ч������
	CTimeConditionType	TimeCondition;
	///�ɽ�������
	CVolumeConditionType	VolumeCondition;
	///��С�ɽ���
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

///�����ɽ���ѯ
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

///�����ɽ���ѯӦ��
class CFTDRspQryBargainOrderField
{
public:
	///�ɽ�����
	CDateType	ActionDate;
	///�ɽ�ʱ��
	CTimeType	ActionTime;
	///�ɽ����
	CTradeIDType	TradeID;
	///�������
	COrderSysIDType	OrderSysID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�۸�
	CPriceType	Price;
	///����
	CVolumeType	Volume;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�ͻ�����
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

///�����ɽ���ѯӦ��
class CFTDRtnBargainOrderField
{
public:
	///�ɽ�����
	CDateType	ActionDate;
	///�ɽ�ʱ��
	CTimeType	ActionTime;
	///�ɽ����
	CTradeIDType	TradeID;
	///�������
	COrderSysIDType	OrderSysID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�۸�
	CPriceType	Price;
	///����
	CVolumeType	Volume;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�ͻ�����
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

///��Լ�������Բ�ѯ
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

///��Լ�������Բ�ѯӦ��
class CFTDRspQryInstPropertyField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������Ʒ����
	CInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	CProductClassType	ProductClass;
	///�ֲ�����
	CPositionTypeType	PositionType;
	///��Լ��������
	CVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	CUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ��������״̬
	CInstLifePhaseType	InstLifePhase;
	///������
	CDateType	OpenDate;
	///������
	CDateType	ExpireDate;
	///��ʼ������
	CDateType	StartDelivDate;
	///��󽻸���
	CDateType	EndDelivDate;
	///���ƻ�׼��
	CPriceType	BasisPrice;
	///�м۵�����µ���
	CVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	CVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	CVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	CVolumeType	MinLimitOrderVolume;
	///��С�䶯��λ
	CPriceType	PriceTick;
	///��������Ȼ�˿���
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

///��Լ�������Բ�ѯӦ��
class CFTDRtnInstPropertyField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������Ʒ����
	CInstrumentIDType	UnderlyingInstrID;
	///��Ʒ����
	CProductClassType	ProductClass;
	///�ֲ�����
	CPositionTypeType	PositionType;
	///��Լ��������
	CVolumeMultipleType	VolumeMultiple;
	///��Լ������Ʒ����
	CUnderlyingMultipleType	UnderlyingMultiple;
	///��Լ��������״̬
	CInstLifePhaseType	InstLifePhase;
	///������
	CDateType	OpenDate;
	///������
	CDateType	ExpireDate;
	///��ʼ������
	CDateType	StartDelivDate;
	///��󽻸���
	CDateType	EndDelivDate;
	///���ƻ�׼��
	CPriceType	BasisPrice;
	///�м۵�����µ���
	CVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	CVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	CVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	CVolumeType	MinLimitOrderVolume;
	///��С�䶯��λ
	CPriceType	PriceTick;
	///��������Ȼ�˿���
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

///��Լ��֤���ʲ�ѯ
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

///��Լ��֤���ʲ�ѯӦ��
class CFTDRspQryMarginRateField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ��֤����
	CRatioType	LongMarginRatio;
	///��ͷ��֤����
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

///��Լ��֤���ʲ�ѯӦ��
class CFTDRtnMarginRateField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ��֤����
	CRatioType	LongMarginRatio;
	///��ͷ��֤����
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

///��Լ�ǵ�ͣ���ѯ
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

///��Լ�ǵ�ͣ���ѯӦ��
class CFTDRspQryPriceLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///���뷽ʽ
	CRoundingModeType	RoundingMode;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///��Լ�ǵ�ͣ���ѯӦ��
class CFTDRtnPriceLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///���뷽ʽ
	CRoundingModeType	RoundingMode;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///��Ա�޲ֲ�ѯ
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

///��Ա�޲ֲ�ѯӦ��
class CFTDRspQryPartPosiLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///��Ա�޲ֲ�ѯӦ��
class CFTDRtnPartPosiLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///�ͻ��޲ֲ�ѯ
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

///�ͻ��޲ֲ�ѯӦ��
class CFTDRspQryClientPosiLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientTypeType	ClientType;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///�ͻ��޲ֲ�ѯӦ��
class CFTDRtnClientPosiLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientTypeType	ClientType;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///����ͻ��޲ֲ�ѯ
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

///����ͻ��޲ֲ�ѯӦ��
class CFTDRspQrySpecialPosiLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///����ͻ��޲ֲ�ѯӦ��
class CFTDRtnSpecialPosiLimitField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
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

///�˻�������ѯ
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

///�˻�������ѯӦ��
class CFTDRspQryTransactionChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�ʻ�������ˮ��
	CSerialNoType	BillSN;
	///�ʽ��˻�
	CAccountIDType	ParticipantAccount;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///������
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

///�˻�������ѯӦ��
class CFTDRtnTransactionChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�ʻ�������ˮ��
	CSerialNoType	BillSN;
	///�ʽ��˻�
	CAccountIDType	ParticipantAccount;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///������
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

///�ͻ����ݱ䶯��ѯ
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

///�ͻ����ݱ䶯��ѯӦ��
class CFTDRspQryClientChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType	IdentifiedCardNo;
	///��������
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

///�ͻ����ݱ䶯��ѯӦ��
class CFTDRtnClientChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType	IdentifiedCardNo;
	///��������
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

///��Ա�ͻ����ձ䶯��ѯ
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

///��Ա�ͻ����ձ䶯��ѯӦ��
class CFTDRspQryPartClientChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��������
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

///��Ա�ͻ����ձ䶯��ѯӦ��
class CFTDRtnPartClientChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�ͻ�����
	CClientIDType	ClientID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��������
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

///�޲����ݱ䶯��ѯ
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

///�޲����ݱ䶯��ѯӦ��
class CFTDRspQryPosiLimitChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��������
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

///�޲����ݱ䶯��ѯӦ��
class CFTDRtnPosiLimitChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��������
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

///��ֵ��ȱ䶯��ѯ
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

///��ֵ��ȱ䶯��ѯӦ��
class CFTDRspQryHedgeDetailChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�û�����
	COperatorIDType	OperatorID;
	///ʱ��
	CTimeType	Time;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ֲֶ�շ���
	CPosiDirectionType	PosiDirection;
	///������
	CVolumeType	TradingVolume;
	///��ֵ���
	CVolumeType	HedgeQuota;
	///��������
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

///��ֵ��ȱ䶯��ѯӦ��
class CFTDRtnHedgeDetailChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///�û�����
	COperatorIDType	OperatorID;
	///ʱ��
	CTimeType	Time;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ֲֶ�շ���
	CPosiDirectionType	PosiDirection;
	///������
	CVolumeType	TradingVolume;
	///��ֵ���
	CVolumeType	HedgeQuota;
	///��������
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

///��Ա�䶯��ѯ
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

///��Ա�䶯��ѯӦ��
class CFTDRspQryParticipantChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��Ա���
	CParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	CMemberTypeType	MemberType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///��Ա�䶯��ѯӦ��
class CFTDRtnParticipantChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��Ա���
	CParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	CMemberTypeType	MemberType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///��֤���ʱ䶯��ѯ
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

///��֤���ʱ䶯��ѯӦ��
class CFTDRspQryMarginRateChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ��֤����
	CRatioType	LongMarginRatio;
	///��ͷ��֤����
	CRatioType	ShortMarginRatio;
	///��������
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

///��֤���ʱ䶯��ѯӦ��
class CFTDRtnMarginRateChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///Ͷ���ױ���־
	CHedgeFlagType	HedgeFlag;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ��֤����
	CRatioType	LongMarginRatio;
	///��ͷ��֤����
	CRatioType	ShortMarginRatio;
	///��������
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

///IP��ַ�䶯��ѯ
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

///IP��ַ�䶯��ѯӦ��
class CFTDRspQryUserIpChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�����û�����
	CUserIDType	UserID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///IP��ַ����
	CIPAddressType	IPMask;
	///��������
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

///IP��ַ�䶯��ѯӦ��
class CFTDRtnUserIpChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///�����û�����
	CUserIDType	UserID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///IP��ַ����
	CIPAddressType	IPMask;
	///��������
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

///�޲����ݱ䶯��ѯ
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

///�޲����ݱ䶯��ѯӦ��
class CFTDRspQryClientPosiLimitChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientTypeType	ClientType;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��������
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

///�޲����ݱ䶯��ѯӦ��
class CFTDRtnClientPosiLimitChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientTypeType	ClientType;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��������
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

///�޲����ݱ䶯��ѯ
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

///�޲����ݱ䶯��ѯӦ��
class CFTDRspQrySpecPosiLimitChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��������
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

///�޲����ݱ䶯��ѯӦ��
class CFTDRtnSpecPosiLimitChgField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��������
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

///��ʷ����״̬��ѯ
class CFTDReqQryHistoryObjectAttrField
{
public:
	///���������
	CNetObjectIDType	ObjectID;
	///���ָ������
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

///��ʷ����״̬��ѯӦ��
class CFTDRspQryHistoryObjectAttrField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�����ڿ�ʼʱ��
	CTimeType	BeginTime;
	///�����ڽ���ʱ��
	CTimeType	EndTime;
	///���������
	CNetObjectIDType	ObjectID;
	///���ָ������
	CNetAttrTypeType	AttrType;
	///���ָ���ֵ����
	CValueTypeType	ValueType;
	///�������յ���һ��ֵ
	CCapValueType	FirstValue;
	///�������յ����һ��ֵ
	CCapValueType	EndValue;
	///������ƽ��ֵ
	CCapValueType	AvgValue;
	///�������յ���Сֵ
	CCapValueType	MinValue;
	///�������յ����ֵ
	CCapValueType	MaxValue;
	///�������յ�ָ�����
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

///��ʷ����״̬��ѯӦ��
class CFTDRtnHistoryObjectAttrField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�����ڿ�ʼʱ��
	CTimeType	BeginTime;
	///�����ڽ���ʱ��
	CTimeType	EndTime;
	///���������
	CNetObjectIDType	ObjectID;
	///���ָ������
	CNetAttrTypeType	AttrType;
	///���ָ���ֵ����
	CValueTypeType	ValueType;
	///�������յ���һ��ֵ
	CCapValueType	FirstValue;
	///�������յ����һ��ֵ
	CCapValueType	EndValue;
	///������ƽ��ֵ
	CCapValueType	AvgValue;
	///�������յ���Сֵ
	CCapValueType	MinValue;
	///�������յ����ֵ
	CCapValueType	MaxValue;
	///�������յ�ָ�����
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

///ǰ����Ӧ��Ϣ��ѯ
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

///ǰ����Ӧ��Ϣ��ѯӦ��
class CFTDRspQryFrontInfoField
{
public:
	///����
	CDateType	MonDate;
	///�����ڿ�ʼʱ��
	CTimeType	MonTime;
	///ǰ�û���
	CTypeObjectIDType	FrontId;
	///ǰ����Ӧʱ������
	CVolumeType	RspCondition;
	///������
	CVolumeType	ReqCount;
	///��ռ�ܱ�������
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

///ǰ����Ӧ��Ϣ��ѯӦ��
class CFTDRtnFrontInfoField
{
public:
	///����
	CDateType	MonDate;
	///�����ڿ�ʼʱ��
	CTimeType	MonTime;
	///ǰ�û���
	CTypeObjectIDType	FrontId;
	///ǰ����Ӧʱ������
	CVolumeType	RspCondition;
	///������
	CVolumeType	ReqCount;
	///��ռ�ܱ�������
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

///�û���¼��ѯ
class CFTDReqQrySysUserLoginField
{
public:
	///�û�����
	CUserIDType	UserID;
	///����
	CPasswordType	Password;
	///�汾��
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

///�û���¼Ӧ��
class CFTDRspQrySysUserLoginField
{
public:
	///�û�����
	CUserIDType	UserID;
	///������
	CDateType	TradingDay;
	///��¼�ɹ�ʱ��
	CTimeType	LoginTime;
	///�û�Ȩ��
	CPrivilegeType	Privilege;
	///�汾ƥ���ʶ
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

///�û��ǳ�
class CFTDReqQrySysUserLogoutField
{
public:
	///�û�����
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_ReqQrySysUserLogout=0x5365;

///�û��ǳ�Ӧ��
class CFTDRspQrySysUserLogoutField
{
public:
	///�û�����
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_RspQrySysUserLogout=0x5366;

///�û��޸�����
class CFTDReqQrySysUserPasswordUpdateField
{
public:
	///�û�����
	CUserIDType	UserID;
	///������
	CPasswordType	OldPassword;
	///������
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

///�û��޸�����Ӧ��
class CFTDRspQrySysUserPasswordUpdateField
{
public:
	///�û�����
	CUserIDType	UserID;
	///�����޸ķ�����Ϣ
	CActionMsgType	PasswordChgMsg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(PasswordChgMsg)
	));
};
const DWORD FTD_FID_RspQrySysUserPasswordUpdate=0x5368;

///�û�ע��
class CFTDReqQrySysUserRegisterField
{
public:
	///�û�����
	CUserIDType	UserID;
	///�û�����
	CUserIDType	UserName;
	///�û���Ϣ
	CUserInfoType	UserInfo;
	///����
	CPasswordType	Password;
	///�û�Ȩ��
	CPrivilegeType	Privilege;
	///�û������ʼ�
	CEMailType	EMail;
	///�û������ʼ����ձ��
	CReciveFlagType	EMailFlag;
	///�û��̶��绰
	CTelephoneType	HomePhone;
	///�û��̶��绰���ձ��
	CReciveFlagType	HomePhoneFlag;
	///�û��ֻ�
	CTelephoneType	MobilePhone;
	///�û��ֻ����ձ��
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

///�û�ע��Ӧ��
class CFTDRspQrySysUserRegisterField
{
public:
	///�û�����
	CUserIDType	UserID;
	///�û�Ȩ��
	CPrivilegeType	Privilege;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Privilege)
	));
};
const DWORD FTD_FID_RspQrySysUserRegister=0x5370;

///ɾ���û�
class CFTDReqQrySysUserDeleteField
{
public:
	///�û�����
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_ReqQrySysUserDelete=0x5371;

///ɾ���û�Ӧ��
class CFTDRspQrySysUserDeleteField
{
public:
	///�û�����
	CUserIDType	UserID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
	));
};
const DWORD FTD_FID_RspQrySysUserDelete=0x5372;

///��Ա��ʼ��Ӧ��
class CFTDRspQryParticipantInitField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��Ա���
	CParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	CMemberTypeType	MemberType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///��Ա��ʼ��Ӧ��
class CFTDRtnParticipantInitField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��Ա���
	CParticipantAbbrType	ParticipantAbbr;
	///��Ա����
	CMemberTypeType	MemberType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///��ϯ��ʼ��Ӧ��
class CFTDRspQryUserInitField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�����û�����
	CUserTypeType	UserType;
	///����
	CPasswordType	Password;
	///����ԱȨ��
	CUserActiveType	IsActive;
	///��������
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

///��ϯ��ʼ��Ӧ��
class CFTDRtnUserInitField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///�����û�����
	CUserTypeType	UserType;
	///����
	CPasswordType	Password;
	///����ԱȨ��
	CUserActiveType	IsActive;
	///��������
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

///�ͻ���ʼ��Ӧ��
class CFTDRspQryClientInitField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///�ͻ���ʼ��Ӧ��
class CFTDRtnClientInitField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///������־��ѯ
class CFTDReqQryTradeLogField
{
public:
	///������
	CDateType	TradingDay;
	///IP��ַ
	CIPAddressType	IPAddress;
	///ǰ�ú�
	CCommodityIDType	FrontID;
	///��ʼ��Ա��
	CParticipantIDType	StartParticipant;
	///������Ա��
	CParticipantIDType	EndParticipant;
	///��ʼϯλ��
	CUserIDType	StartUser;
	///����ϯλ��
	CUserIDType	EndUser;
	///��ʼʱ��
	CTimeType	StartTime;
	///����ʱ��
	CTimeType	EndTime;
	///��ʼ�ỰID
	CCommodityIDType	StartSessionID;
	///�����ỰID
	CCommodityIDType	EndSessionID;
	///����IP���˱��
	CBoolType	IPFlag;
	///���ݻ�Ա���˱��
	CBoolType	PartFlag;
	///����ϯλ���˱��
	CBoolType	UserIDFlag;
	///����ʱ����˱��
	CBoolType	TimeFlag;
	///����ǰ�úŹ��˱��
	CBoolType	FrontFlag;
	///���ݻỰ�Ź��˱��
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

///������־��ѯӦ��
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

///������־��ѯӦ��
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

///�澯ʱ���޸�
class CFTDReqQryWarningEventUpdateField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼���������
	CDateType	OccurDate;
	///�¼�����ʱ��
	CTimeType	OccurTime;
	///�¼�ID
	CVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�¼���
	CTypeObjectIDType	EventName;
	///�¼���ǩ
	CVolumeType	EventNum;
	///�¼�����
	CVolumeType	EventType;
	///�¼�����
	CTypeDescriptionType	EventDes;
	///������
	CTypeProcessFlagType	ProcessFlag;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�澯��������
	CDateType	ActiveDate;
	///�澯����ʱ��
	CTimeType	ActiveTime;
	///�¼���������
	CTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
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

///����ϵͳ��¼��Ϣ��ѯ
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

///����ϵͳ��¼��ϢӦ��
class CFTDRspQryTradeUserLoginInfoField
{
public:
	///����ID
	CTypeObjectIDType	ObjectID;
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///Э����Ϣ
	CProtocolInfoType	ProtocolInfo;
	///IP��ַ
	CIPAddressType	IPAddress;
	///ǰ�û����
	CFrontIDType	FrontID;
	///�û����
	CTypeObjectIDType	UserType;
	/// ���뷽ʽ
	CTypeObjectIDType	AccessType;
	///��¼��ǳ�����
	CDateType	ActionDate;
	///��¼��ǳ�ʱ��
	CTimeType	ActionTime;
	///��¼��ǳ����
	CValueTypeType	ActionFlag;
	///����������
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

///����ϵͳ��¼��ϢӦ��
class CFTDRtnTradeUserLoginInfoField
{
public:
	///����ID
	CTypeObjectIDType	ObjectID;
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///Э����Ϣ
	CProtocolInfoType	ProtocolInfo;
	///IP��ַ
	CIPAddressType	IPAddress;
	///ǰ�û����
	CFrontIDType	FrontID;
	///�û����
	CTypeObjectIDType	UserType;
	/// ���뷽ʽ
	CTypeObjectIDType	AccessType;
	///��¼��ǳ�����
	CDateType	ActionDate;
	///��¼��ǳ�ʱ��
	CTimeType	ActionTime;
	///��¼��ǳ����
	CValueTypeType	ActionFlag;
	///����������
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

///��Ա���ײ�ѯ
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

///��Ա���ײ�ѯӦ��
class CFTDRspQryPartTradeField
{
public:
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ܱ�����
	CVolumeType	TotalPositiveOrder;
	///�ܱ�������
	CVolumeType	TotalNegativeOrder;
	///���ܳɽ���
	CVolumeType	TotalPositiveTrade;
	///�����ܳɽ���
	CVolumeType	TotalNegativeTrade;
	///�ܶ�ͷ�ֲ���
	CVolumeType	TotalPositivePosi;
	///�ܿ�ͷ�ֲ���
	CVolumeType	TotalNegativePosi;
	///��������
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

///���׷�ֵ��ѯ
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

///���׷�ֵ��ѯӦ��
class CFTDRspQryTradepeakField
{
public:
	///ͳ����Ϣ��������
	CTradepeakFlagType	TradepeakFlag;
	///ʱ��
	CTimeType	PeakTime;
	///����������
	CVolumeType	InsertOrder;
	///����������
	CVolumeType	ActionOrder;
	///��Ч������
	CVolumeType	InvalidOrder;
	///���׺ϼ�
	CVolumeType	TotalBusiness;
	///�ɽ���
	CVolumeType	TradeCount;
	///�ϼ�
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
	///��������
	CTypeObjectIDType	UpdateType;
	///��ֵ
	CTypeObjectIDType	OldValue;
	///��ֵ
	CTypeObjectIDType	NewValue;
	///����
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
	///�û�����
	CUserIDType	UserID;
	///�û�����
	CUserIDType	UserName;
	///�û���Ϣ
	CUserInfoType	UserInfo;
	///����
	CPasswordType	Password;
	///�û�Ȩ��
	CPrivilegeType	Privilege;
	///�û������ʼ�
	CEMailType	EMail;
	///�û������ʼ����ձ��
	CReciveFlagType	EMailFlag;
	///�û��̶��绰
	CTelephoneType	HomePhone;
	///�û��̶��绰���ձ��
	CReciveFlagType	HomePhoneFlag;
	///�û��ֻ�
	CTelephoneType	MobilePhone;
	///�û��ֻ����ձ��
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
	///��������
	CDateType	ActionDate;
	///����ʱ��
	CTimeType	ActionTime;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///���뷽ʽ
	CRoundingModeType	RoundingMode;
	///��ͣ���
	CPriceType	UpperLimitPrice;
	///��ͣ���
	CPriceType	LowerLimitPrice;
	///��������
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

///����ƽ̨��ʼ����Ϣ��ѯ
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

///����ƽ̨��ʼ����Ϣ��ѯ
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

///�ļ���д���
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

///��ʷCpu״̬��ѯ
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
	///�������ı��
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

///��ʷCpu��ѯӦ��
class CFTDRspQryHistoryCpuInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///CPU�ı��
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

///��ʷMem״̬��ѯ
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
	///�������ı��
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

///��ʷMem��ѯӦ��
class CFTDRspQryHistoryMemInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
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

///��ʷ����״̬��ѯ
class CFTDReqQryHistoryNetworkInfoField
{
public:
	///
	CTypeObjectIDType	HostName;
	///������
	CTypeLanNameType	LANNAME;
	///
	CDateType	StartDate;
	///
	CTimeType	StartTime;
	///
	CDateType	EndDate;
	///
	CTimeType	EndTime;
	///�������ı��
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

///��ʷ�����ѯӦ��
class CFTDRspQryHistoryNetworkInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///������
	CTypeLanNameType	LANNAME;
	///������up��down״̬
	CTypeLanStatusType	LANSTATUS;
	///������ip��ַ
	CIPAddressType	IPADDRESS;
	///�������յ�����
	CLargeNumberType	RECVBYTES;
	///�������յ����ݰ�
	CLargeNumberType	RECVPACKETS;
	///�������ն˴������ݰ�
	CLargeNumberType	RECVERRORPACKETS;
	///�������ն˶�ʧ���ݰ�
	CLargeNumberType	RECVDROPPACKETS;
	///�������͵�����
	CLargeNumberType	SENDBYTES;
	///�������͵����ݰ�
	CLargeNumberType	SENDPACKETS;
	///�������Ͷ˴������ݰ�
	CLargeNumberType	SENDERRORPACKETS;
	///�������Ͷ˶�ʧ���ݰ�
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

///�������ò�ѯ����Ӧ��
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

///���ϵͳ�����û���ѯ
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

///���ϵͳ�����û�Ӧ��
class CFTDRspQryMonitorOnlineUserField
{
public:
	///�û�����
	CUserIDType	UserID;
	///IP��ַ
	CIPAddressType	IPAddress;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(IPAddress)
	));
};
const DWORD FTD_FID_RspQryMonitorOnlineUser=0x5408;

///����ϵͳǰ��ͳ�Ʋ�ѯ
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

///����ϵͳǰ��ͳ��Ӧ��
class CFTDRspQryFrontStatField
{
public:
	///ǰ�û����
	CFrontIDType	FrontID;
	///�ܱ������
	CVolumeType	PositiveOrder;
	///�ܱ�������
	CVolumeType	NegativeOrder;
	///�ܱ�������
	CVolumeType	TotalPositiveOrder;
	///�ܱ�������
	CVolumeType	TotalNegativeOrder;
	///����״̬�ı����
	CVolumeType	OrderAction;
	///����״̬�ı�����
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

///���ϵͳʱ��ͬ��
class CFTDRtnSysTimeSyncField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(MonTime)
	));
};
const DWORD FTD_FID_RtnSysTimeSync=0x5411;

///���������л�֪ͨ
class CFTDRtnDataCenterChgField
{
public:
	///������������
	CTypeObjectIDType	DataCenterID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DataCenterID)
	));
};
const DWORD FTD_FID_RtnDataCenterChg=0x5412;

///��ʷ��ֵ��ѯ
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

///��ʷ��ֵ��ѯӦ��
class CFTDRspQryHistoryTradePeakField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�����������
	CDateType	MonDate;
	///�������ʱ��
	CTimeType	MonTime;
	///���ָ��
	CAttrTypeType	AttrType;
	///�������ֵ
	CMoneyType	AttrValue;
	///���ָ��
	CAttrTypeType	RltAttrType;
	///���ָ�굱ʱ��ֵ
	CMoneyType	RltAttrValue;
	///���ֵ������
	CDateType	MaxMonDate;
	///���ֵ��ʱ��
	CTimeType	MaxMonTime;
	///ָ����ʷ���ֵ
	CMoneyType	MaxAttrValue;
	///���ָ�굱ʱ��ֵ
	CMoneyType	MaxRltAttrValue;
	///����ֵ������
	CDateType	OldMonDate;
	///����ֵ��ʱ��
	CTimeType	OldMonTime;
	///���ָ��Ĵ���ֵ
	CMoneyType	OldAttrValue;
	///���ָ�굱ʱ��ֵ
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

///��ʷ��ֵ��ѯӦ��
class CFTDRtnHistoryTradePeakField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�����������
	CDateType	MonDate;
	///�������ʱ��
	CTimeType	MonTime;
	///���ָ��
	CAttrTypeType	AttrType;
	///�������ֵ
	CMoneyType	AttrValue;
	///���ָ��
	CAttrTypeType	RltAttrType;
	///���ָ�굱ʱ��ֵ
	CMoneyType	RltAttrValue;
	///���ֵ������
	CDateType	MaxMonDate;
	///���ֵ��ʱ��
	CTimeType	MaxMonTime;
	///ָ����ʷ���ֵ
	CMoneyType	MaxAttrValue;
	///���ָ�굱ʱ��ֵ
	CMoneyType	MaxRltAttrValue;
	///����ֵ������
	CDateType	OldMonDate;
	///����ֵ��ʱ��
	CTimeType	OldMonTime;
	///���ָ��Ĵ���ֵ
	CMoneyType	OldAttrValue;
	///���ָ�굱ʱ��ֵ
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

///��־�¼���ѯ
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
	///�¼�����
	CVolumeType	EventType;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///�¼���
	CTypeObjectIDType	EventName;
	///IP��ַ
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

///��־�¼���ѯӦ��
class CFTDRspQrySyslogEventField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼���������
	CDateType	OccurDate;
	///�¼�����ʱ��
	CTimeType	OccurTime;
	///�¼�ID
	CVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�¼���
	CTypeObjectIDType	EventName;
	///�¼���ǩ
	CVolumeType	EventNum;
	///�¼�����
	CVolumeType	EventType;
	///�¼�����
	CTypeDescriptionType	EventDes;
	///������
	CTypeProcessFlagType	ProcessFlag;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�¼���������
	CTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
	CNetAttrTypeType	FullEventName;
	///�¼�����
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

///��־�¼�Ӧ��
class CFTDRtnSyslogEventField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼���������
	CDateType	OccurDate;
	///�¼�����ʱ��
	CTimeType	OccurTime;
	///�¼�ID
	CVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�¼���
	CTypeObjectIDType	EventName;
	///�¼���ǩ
	CVolumeType	EventNum;
	///�¼�����
	CVolumeType	EventType;
	///�¼�����
	CTypeDescriptionType	EventDes;
	///������
	CTypeProcessFlagType	ProcessFlag;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�¼���������
	CTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
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

///��־�¼���������
class CFTDReqQrySyslogEventSubcriberField
{
public:
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///�¼���
	CTypeObjectIDType	EventName;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///����������
	CTypeSubcriberObjectIDType	filter;
	///������������
	CTypeSubcriberObjectIDType	antifilter;
	///���η��ض�����
	CVolumeType	ObjectNum;
	///�������ı��
	CTypeKeepAliveType	KeepAlive;
	///���صĳ�ʼ����
	CDateType	MonDate;
	///���صĳ�ʼʱ��
	CTimeType	MonTime;
	///������
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

///�������л�֪ͨ
class CFTDReqQryTradeDayChangeField
{
public:
	///�л�����
	CTypeObjectIDType	ChangeType;
	///ԭ������
	CDateType	OldDate;
	///�½�����
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

///�������л�֪ͨ
class CFTDRspQryTradeDayChangeField
{
public:
	///�л�����
	CTypeObjectIDType	ChangeType;
	///ԭ������
	CDateType	OldDate;
	///�½�����
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

///tomcat��Ϣ��ѯ
class CFTDReqQryTomcatInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
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

///WebӦ����Ϣ
class CFTDRspQryWebAppInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///WebӦ������
	CCfgNameType	AppName;
	///Ӧ������״̬
	CTypeObjectNameType	Status;
	///Ӧ��������Ϣ
	CTypeDescriptionType	Desc;
	///Ӧ������ʱ��
	CTypeCurrentTimeType	StartTime;
	///Ӧ��servlet����
	CTypeChar10Type	ServletNum;
	///Ӧ�ô�����ʱ��
	CTypeCommandType	ProcessTime;
	///Ӧ���ۼƽ���������
	CTypeCommandType	RequestNum;
	///Ӧ���ۼƴ�����
	CTypeCommandType	ErrorNum;
	///Ӧ�õ�ǰ�Ự��
	CTypeChar10Type	SessionSize;
	///�Ự��ʱʱ��(��)
	CTypeChar10Type	TimeOut;
	///Ӧ��JDBC����ʹ����
	CTypeChar10Type	JDBCUsage;
	///Ӧ��JSP�ļ�����
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

///WebӦ����Ϣ
class CFTDRtnWebAppInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///WebӦ������
	CCfgNameType	AppName;
	///Ӧ������״̬
	CTypeObjectNameType	Status;
	///Ӧ��������Ϣ
	CTypeDescriptionType	Desc;
	///Ӧ������ʱ��
	CTypeCurrentTimeType	StartTime;
	///Ӧ��servlet����
	CTypeChar10Type	ServletNum;
	///Ӧ�ô�����ʱ��
	CTypeCommandType	ProcessTime;
	///Ӧ���ۼƽ���������
	CTypeCommandType	RequestNum;
	///Ӧ���ۼƴ�����
	CTypeCommandType	ErrorNum;
	///Ӧ�õ�ǰ�Ự��
	CTypeChar10Type	SessionSize;
	///�Ự��ʱʱ��(��)
	CTypeChar10Type	TimeOut;
	///Ӧ��JDBC����ʹ����
	CTypeChar10Type	JDBCUsage;
	///Ӧ��JSP�ļ�����
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

///Ӧ��servlet��Ϣ
class CFTDRspQryServletInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///servlet����
	CTypeObjectIDType	Name;
	///���غ�ʱ
	CTypeContLenType	LoadTime;
	///������������
	CRatioType	RequestNum;
	///��������
	CRatioType	RequestErrNum;
	///����ʱ��
	CRatioType	ProcessTime;
	///��С����ʱ��
	CTypeContLenType	MixTime;
	///�����ʱ��
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

///Ӧ��servlet��Ϣ
class CFTDRtnServletInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///servlet����
	CTypeObjectIDType	Name;
	///���غ�ʱ
	CTypeContLenType	LoadTime;
	///������������
	CRatioType	RequestNum;
	///��������
	CRatioType	RequestErrNum;
	///����ʱ��
	CRatioType	ProcessTime;
	///��С����ʱ��
	CTypeContLenType	MixTime;
	///�����ʱ��
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

///�ļ���Ϣ
class CFTDRspQryFileInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�ļ�ȫ·����
	CFilePathNameType	PathName;
	///�ļ���С
	CTypeChar10Type	FileSize;
	///�ļ�����޸�ʱ��
	CTypeMonitorTypeType	LastModDate;
	///�ļ�����
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

///�ļ���Ϣ
class CFTDRtnFileInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�ļ�ȫ·����
	CFilePathNameType	PathName;
	///�ļ���С
	CTypeChar10Type	FileSize;
	///�ļ�����޸�ʱ��
	CTypeMonitorTypeType	LastModDate;
	///�ļ�����
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

///Ӧ�ûỰ��Ϣ
class CFTDRspQrySessionInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///Session���
	CCfgNameType	SessionID;
	///Session����
	CTypeObjectIDType	SessionName;
	///Session��Ӧ�ͻ���IP��ַ
	CTypeObjectNameType	RemoteIP;
	///Session����ʱ��
	CTypeHostModelType	BeginTime;
	///Session��������ʱ��
	CTypeHostModelType	LatestTime;
	///Session��ʱʱ��(��)
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

///Ӧ�ûỰ��Ϣ
class CFTDRtnSessionInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///Session���
	CCfgNameType	SessionID;
	///Session����
	CTypeObjectIDType	SessionName;
	///Session��Ӧ�ͻ���IP��ַ
	CTypeObjectNameType	RemoteIP;
	///Session����ʱ��
	CTypeHostModelType	BeginTime;
	///Session��������ʱ��
	CTypeHostModelType	LatestTime;
	///Session��ʱʱ��(��)
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

///JDBC��Ϣ
class CFTDRspQryJDBCInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///Ӧ�ó�������
	CCfgNameType	AppName;
	///JDBC���ӳ�����
	CCfgNameType	Name;
	///���ӳ�ʹ�ñ���
	CStockPercentType	Usage;
	///���������
	CTypeContLenType	ConnNumMax;
	///����������
	CTypeContLenType	ConnNumFree;
	///��������������
	CTypeContLenType	ConnNumUnRU;
	///������������
	CTypeContLenType	ConnNumRU;
	///��Ӧ���ݿ��û�
	CCfgNameType	UserName;
	///JDBC����
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

///JDBC��Ϣ
class CFTDRtnJDBCInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///Ӧ�ó�������
	CCfgNameType	AppName;
	///JDBC���ӳ�����
	CCfgNameType	Name;
	///���ӳ�ʹ�ñ���
	CStockPercentType	Usage;
	///���������
	CTypeContLenType	ConnNumMax;
	///����������
	CTypeContLenType	ConnNumFree;
	///��������������
	CTypeContLenType	ConnNumUnRU;
	///������������
	CTypeContLenType	ConnNumRU;
	///��Ӧ���ݿ��û�
	CCfgNameType	UserName;
	///JDBC����
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

///�߳���Ϣ
class CFTDRspQryThreadInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�߳�����
	CTypeObjectIDType	Name;
	///�̱߳��
	CTypeContLenType	ThreadNum;
	///�߳�״̬
	CTypeObjectNameType	ThreadStatus;
	///�߳�Native��ʶ
	CTypeContLenType	InNative;
	///�߳�Suspended��ʶ
	CTypeLanNameType	Suspended;
	///�߳���������
	CTypeLanNameType	BlockCount;
	///�̵߳ȴ�����
	CTypeContLenType	WaitCount;
	///�߳�CPUʱ��
	CRatioType	CpuTime;
	///�߳��û�ʱ��
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

///�߳���Ϣ
class CFTDRtnThreadInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�߳�����
	CTypeObjectIDType	Name;
	///�̱߳��
	CTypeContLenType	ThreadNum;
	///�߳�״̬
	CTypeObjectNameType	ThreadStatus;
	///�߳�Native��ʶ
	CTypeContLenType	InNative;
	///�߳�Suspended��ʶ
	CTypeLanNameType	Suspended;
	///�߳���������
	CTypeLanNameType	BlockCount;
	///�̵߳ȴ�����
	CTypeContLenType	WaitCount;
	///�߳�CPUʱ��
	CRatioType	CpuTime;
	///�߳��û�ʱ��
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

///�������Ϣ��ѯ
class CFTDReqQryVMInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
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

///�������Ϣ
class CFTDRspQryVMInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///���������
	CTypeObjectIDType	Name;
	///���������
	CTypeObjectIDType	VmName;
	///��Ӧ��
	CTypeObjectIDType	VmVendor;
	///������汾
	CTypeObjectIDType	VmVersion;
	///����ʱ��
	CTypeObjectIDType	StartTime;
	///������·��
	CTypeFileContentType	BootClassPath;
	///��·��
	CTypeFileContentType	ClassPath;
	///��·��
	CTypeFileContentType	LibraryPath;
	///��������
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

///�������Ϣ
class CFTDRtnVMInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///���������
	CTypeObjectIDType	Name;
	///���������
	CTypeObjectIDType	VmName;
	///��Ӧ��
	CTypeObjectIDType	VmVendor;
	///������汾
	CTypeObjectIDType	VmVersion;
	///����ʱ��
	CTypeObjectIDType	StartTime;
	///������·��
	CTypeFileContentType	BootClassPath;
	///��·��
	CTypeFileContentType	ClassPath;
	///��·��
	CTypeFileContentType	LibraryPath;
	///��������
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

///ϵͳ������Ϣ��ѯ
class CFTDReqQryPropertyInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
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

///ϵͳ������Ϣ
class CFTDRspQryPropertyInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///ϵͳ������
	CTypeObjectIDType	Property;
	///�ָ��ʶ
	CTypeContLenType	ClipFlag;
	///����ֵ
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

///ϵͳ������Ϣ
class CFTDRtnPropertyInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///ϵͳ������
	CTypeObjectIDType	Property;
	///�ָ��ʶ
	CTypeContLenType	ClipFlag;
	///����ֵ
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

///ϵͳ�ڴ����Ϣ��ѯ
class CFTDReqQryMemPoolInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
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

///ϵͳ�ڴ����Ϣ
class CFTDRspQryMemPoolInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///ϵͳ������
	CCfgNameType	PoolName;
	///ϵͳ������
	CTypeChar10Type	Usage;
	///ϵͳ������
	CTypeCommandType	committedbytes;
	///ϵͳ������
	CTypeCommandType	initbytes;
	///ϵͳ������
	CTypeCommandType	maxbytes;
	///ϵͳ������
	CTypeCommandType	usedbytes;
	///ϵͳ������
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

///ϵͳ�ڴ����Ϣ
class CFTDRtnMemPoolInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///ϵͳ������
	CCfgNameType	PoolName;
	///ϵͳ������
	CTypeChar10Type	Usage;
	///ϵͳ������
	CTypeCommandType	committedbytes;
	///ϵͳ������
	CTypeCommandType	initbytes;
	///ϵͳ������
	CTypeCommandType	maxbytes;
	///ϵͳ������
	CTypeCommandType	usedbytes;
	///ϵͳ������
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

///�ļ�������Ϣ��ѯ
class CFTDReqQryFileContentInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
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

///�ļ�������Ϣ
class CFTDRspQryFileContentInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�ļ���
	CFilePathNameType	FileName;
	///�ļ�����
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

///�ļ�������Ϣ
class CFTDRtnFileContentInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�ļ���
	CFilePathNameType	FileName;
	///�ļ�����
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

///������Ϣ��ѯ
class CFTDReqQryConnectionInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
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

///������Ϣ
class CFTDRspQryConnectionInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�����߳���
	CCfgNameType	ServiceName;
	///��ǰ״̬
	CTypeChar10Type	Stage;
	///�ۼƽ���������
	CRatioType	RequestCount;
	///�ۼƴ�����
	CRatioType	ErrorCount;
	///�ۼƴ���ʱ��
	CRatioType	ProcTime;
	///�ۼƽ����ֽ���
	CRatioType	BytesReceived;
	///�ۼƷ����ֽ���
	CRatioType	BytesSent;
	///Զ��IP��ַ
	CTypeObjectNameType	RemoteIP;
	///�������URI
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

///������Ϣ
class CFTDRtnConnectionInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///�����߳���
	CCfgNameType	ServiceName;
	///��ǰ״̬
	CTypeChar10Type	Stage;
	///�ۼƽ���������
	CRatioType	RequestCount;
	///�ۼƴ�����
	CRatioType	ErrorCount;
	///�ۼƴ���ʱ��
	CRatioType	ProcTime;
	///�ۼƽ����ֽ���
	CRatioType	BytesReceived;
	///�ۼƷ����ֽ���
	CRatioType	BytesSent;
	///Զ��IP��ַ
	CTypeObjectNameType	RemoteIP;
	///�������URI
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

///��������Ϣ��ѯ
class CFTDReqQryConnectorInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
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

///��������Ϣ
class CFTDRspQryConnectorInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///����������
	CTypeObjectNameType	Name;
	///��ǰ�����߳���
	CTypeChar10Type	ThreadsCount;
	///��ǰ��æ�߳���
	CTypeChar10Type	BusyThreadsCount;
	///����߳���
	CTypeChar10Type	MaxThreads;
	///�������߳���
	CTypeChar10Type	MaxSpareThreads;
	///��С�����߳���
	CTypeChar10Type	MinSpareThreads;
	///�����ʱ��
	CTypeCommandType	MaxTime;
	///�����ʱ��
	CTypeCommandType	MaxProcTime;
	///�ۼƽ���������
	CTypeCommandType	RequestCount;
	///�ۼƴ�����
	CTypeCommandType	ErrorCount;
	///�ۼƽ����ֽ���
	CTypeChar10Type	BytesReceived;
	///�ۼƷ����ֽ���
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

///��������Ϣ
class CFTDRtnConnectorInfoField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///����������
	CTypeObjectNameType	Name;
	///��ǰ�����߳���
	CTypeChar10Type	ThreadsCount;
	///��ǰ��æ�߳���
	CTypeChar10Type	BusyThreadsCount;
	///����߳���
	CTypeChar10Type	MaxThreads;
	///�������߳���
	CTypeChar10Type	MaxSpareThreads;
	///��С�����߳���
	CTypeChar10Type	MinSpareThreads;
	///�����ʱ��
	CTypeCommandType	MaxTime;
	///�����ʱ��
	CTypeCommandType	MaxProcTime;
	///�ۼƽ���������
	CTypeCommandType	RequestCount;
	///�ۼƴ�����
	CTypeCommandType	ErrorCount;
	///�ۼƽ����ֽ���
	CTypeChar10Type	BytesReceived;
	///�ۼƷ����ֽ���
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

///���ݿ��ѯ
class CFTDReqQryDBQueryField
{
public:
	///���ݿ�ʵ������ID
	CTypeObjectIDType	ObjectID;
	///�洢������
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

///���ݿ��ѯӦ��
class CFTDRspQryDBQueryField
{
public:
	///���ݿ�ʵ������ID
	CTypeObjectIDType	ObjectID;
	///�洢������
	CAttrTypeType	AttrType;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///���ݿ��ѯ���
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

///���ݿ��ѯӦ��
class CFTDRtnDBQueryField
{
public:
	///���ݿ�ʵ������ID
	CTypeObjectIDType	ObjectID;
	///�洢������
	CAttrTypeType	AttrType;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///���ݿ��ѯ���
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

///ͨ�÷���Ӧ��
class CFTDSysGeneralFieldField
{
public:
	///�������
	CDateType	MonDate;
	///���ʱ��
	CTimeType	MonTime;
	///��ض���
	CTypeObjectIDType	ObjectID;
	///�Ӽ�ض���
	CTypeObjectIDType	SubObjectID;
	///���ָ��
	CFilePathNameType	AttrType;
	///ͨ�÷����ֶ�
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

///�ļ���������
class CFTDReqQryGetFileField
{
public:
	///�ļ�����
	CNetAttrTypeType	FileName;
	///�ļ��汾
	CFileVersionType	Version;
	///�ļ�ƫ��
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

///�ļ�����Ӧ��
class CFTDRspQryGetFileField
{
public:
	///�ļ�����
	CNetAttrTypeType	FileName;
	///�ļ��汾
	CFileVersionType	Version;
	///�ļ�ƫ��
	COffsetType	Offset;
	///Comment��ʵ�����ݳ���
	CCommLengthType	Length;
	///�ļ�����
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

///��־�¼��޸�����
class CFTDReqQrySyslogEventUpdateField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼���������
	CDateType	OccurDate;
	///�¼�����ʱ��
	CTimeType	OccurTime;
	///�¼�ID
	CVolumeType	EvendID;
	///�����¼��Ķ���IDָ��
	CNetAttrTypeType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�¼���
	CTypeObjectIDType	EventName;
	///�¼���ǩ
	CVolumeType	EventNum;
	///�¼�����
	CVolumeType	EventType;
	///�¼�����
	CTypeDescriptionType	EventDes;
	///������
	CTypeProcessFlagType	ProcessFlag;
	///���漶��
	CTypeWarningLevelType	WarningLevel;
	///�¼���������
	CTypeObjectIDType	EventDealDes;
	///�¼�ȫ��
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

///�澯��ϸ��ѯ
class CFTDReqQryWarningQueryField
{
public:
	///�¼�ID
	CVolumeType	EvendID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(EvendID)
	));
};
const DWORD FTD_FID_ReqQryWarningQuery=0x5461;

///�澯��ϸ
class CFTDRspQryWarningQueryField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼�ID
	CVolumeType	EvendID;
	///���ݿ��ѯ���
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

///�澯��ϸ
class CFTDRtnWarningQueryField
{
public:
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�¼�ID
	CVolumeType	EvendID;
	///���ݿ��ѯ���
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

///��վ���ʲ�ѯ
class CFTDReqQryWebVisitField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///���ָ��
	CFilePathNameType	AttrType;
	///��ʼ����
	CDateType	BeginDate;
	///��ʼʱ��
	CTimeType	BeginTime;
	///��������
	CDateType	EndDate;
	///����ʱ��
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

///�������ò�ѯ����Ӧ��
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

///�澯������
class CFTDReqQryWarningActiveChangeField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///����
	CDateType	MonDate;
	///ʱ��
	CTimeType	MonTime;
	///�澯�¼�������־λ
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

///�澯������
class CFTDRspQryWarningActiveChangeField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///����
	CDateType	MonDate;
	///ʱ��
	CTimeType	MonTime;
	///�澯�¼�������־λ
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

///�澯������
class CFTDRtnWarningActiveChangeField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	///����
	CDateType	MonDate;
	///ʱ��
	CTimeType	MonTime;
	///�澯�¼�������־λ
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

///ͨ�ò���
class CFTDReqQryGeneralOperateField
{
public:
	///ͨ�ò�������
	CGeneralOperateTypeType	GeneralOperateType;
	///ͨ�ò�����
	CGeneralOperateTableType	GeneralOperateTable;
	///ͨ�ò���ѡ��
	CGeneralOperateOptionType	GeneralOperateOption;
	///ͨ�ò�����
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

///ͨ�ò���
class CFTDRspQryGeneralOperateField
{
public:
	///ͨ�ò�������
	CGeneralOperateTypeType	GeneralOperateType;
	///ͨ�ò�����
	CGeneralOperateTableType	GeneralOperateTable;
	///ͨ�ò���ѡ��
	CGeneralOperateOptionType	GeneralOperateOption;
	///ͨ�ò�����
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

///ͨ�ò���
class CFTDRtnGeneralOperateField
{
public:
	///ͨ�ò�������
	CGeneralOperateTypeType	GeneralOperateType;
	///ͨ�ò�����
	CGeneralOperateTableType	GeneralOperateTable;
	///ͨ�ò���ѡ��
	CGeneralOperateOptionType	GeneralOperateOption;
	///ͨ�ò�����
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

///�����豸���ӹ�ϵ����
class CFTDReqQryNetDeviceLinkedField
{
public:
	///��������
	CVolumeType	OperationType;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///��Ϊ���ֵ�ְ������
	CTypeObjectIDType	FuctionArea;
	///IP��
	CVolumeType	IPDECODE;
	///�����ض���ID
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

///�����豸���ӹ�ϵ
class CFTDRspQryNetDeviceLinkedField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸ID
	CVolumeType	NetDeviceID;
	///�豸�˿�ID
	CVolumeType	NetPortID;
	///��ض���
	CNetObjectIDType	NetObjectID;
	///��ض���˿�����
	CNetDevicePortTypeType	NetPortType;
	///�����豸ID
	CVolumeType	LinkNetDeviceID;
	///�����豸�˿�ID
	CVolumeType	LinkNetPortID;
	///���Ӷ���
	CNetObjectIDType	LinkNetObjectID;
	///���Ӷ���˿�����
	CNetDevicePortTypeType	LinkNetPortType;
	///������Դ
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

///�����豸���ӹ�ϵ
class CFTDRtnNetDeviceLinkedField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸ID
	CVolumeType	NetDeviceID;
	///�豸�˿�ID
	CVolumeType	NetPortID;
	///��ض���
	CNetObjectIDType	NetObjectID;
	///��ض���˿�����
	CNetDevicePortTypeType	NetPortType;
	///�����豸ID
	CVolumeType	LinkNetDeviceID;
	///�����豸�˿�ID
	CVolumeType	LinkNetPortID;
	///���Ӷ���
	CNetObjectIDType	LinkNetObjectID;
	///���Ӷ���˿�����
	CNetDevicePortTypeType	LinkNetPortType;
	///������Դ
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

///����ϵͳ��¼��Ϣ����
class CFTDReqQryTradeUserLoginStatField
{
public:
	///��ض���
	CTypeObjectIDType	ObjectID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
	));
};
const DWORD FTD_FID_ReqQryTradeUserLoginStat=0x5475;

///����ϵͳ��¼��Ϣ
class CFTDRspQryTradeUserLoginStatField
{
public:
	///��¼����
	CDateType	MonDate;
	///��¼ʱ��
	CTimeType	MonTime;
	///��ض���
	CTypeObjectIDType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///ǰ�û���
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

///����ϵͳǰ�ñ�����Ӧ��Ϣ
class CFTDReqQryTradeFrontOrderRttStatField
{
public:
	///ǰ�ö���
	CTypeObjectIDType	ObjectID;
	///��������
	CDateType	MonDate;
	///������ѯ��ʼʱ��
	CTimeType	MonStartTime;
	///������ѯ����ʱ��
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

///����ϵͳǰ�ñ�����Ӧ��Ϣ
class CFTDRspQryTradeFrontOrderRttStatField
{
public:
	///��������
	CDateType	MonDate;
	///����ʱ��
	CTimeType	MonTime;
	///ǰ�ö���
	CTypeObjectIDType	ObjectID;
	///������
	CLargeNumberType	OrderCount;
	///������Ӧʱ���
	CLargeNumberType	OrderRttSum;
	///��󱨵���Ӧʱ��
	CVolumeType	OrderMaxRtt;
	///��С������Ӧʱ��
	CVolumeType	OrderMinRtt;
	///1������Ӧʱ�����
	CVolumeType	OrderRttSqu;
	///1������Ӧʱ��ֲ�
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

///����ϵͳǰ�ñ�����Ӧ��Ϣ
class CFTDRtnTradeFrontOrderRttStatField
{
public:
	///��������
	CDateType	MonDate;
	///����ʱ��
	CTimeType	MonTime;
	///ǰ�ö���
	CTypeObjectIDType	ObjectID;
	///������
	CLargeNumberType	OrderCount;
	///������Ӧʱ���
	CLargeNumberType	OrderRttSum;
	///��󱨵���Ӧʱ��
	CVolumeType	OrderMaxRtt;
	///��С������Ӧʱ��
	CVolumeType	OrderMinRtt;
	///1������Ӧʱ�����
	CVolumeType	OrderRttSqu;
	///1������Ӧʱ��ֲ�
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

///��Աϯλ����״̬
class CFTDReqQryParticTradeOrderStatesField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///��������
	CDateType	MonDate;
	///������ѯ��ʼʱ��
	CTimeType	MonStartTime;
	///������ѯ����ʱ��
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

///��Աϯλ����״̬
class CFTDRspQryParticTradeOrderStatesField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///����ͳ������
	CDateType	MonDate;
	///����ͳ��ʱ��
	CTimeType	MonTime;
	///ͳ��ʱ��(sec)
	CVolumeType	StaticWidth;
	///ǰ��ID
	CVolumeType	FrontID;
	///������
	CVolumeType	OrderCount;
	///������
	CVolumeType	CancleCount;
	///��ѯ��
	CVolumeType	QueryCount;
	///�ɽ���
	CVolumeType	TradeCount;
	///�ɽ����
	CVolumeType	TradeMoney;
	///��󱨵���
	CVolumeType	OrderCntMax;
	///��󳷵���
	CVolumeType	CancleCntMax;
	///����ѯ��
	CVolumeType	QueryCntMax;
	///���ɽ���
	CVolumeType	TradeCntMax;
	///���ɽ����
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

///��Աϯλ����״̬
class CFTDRtnParticTradeOrderStatesField
{
public:
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�����û�����
	CUserIDType	UserID;
	///����ͳ������
	CDateType	MonDate;
	///����ͳ��ʱ��
	CTimeType	MonTime;
	///ͳ��ʱ��(sec)
	CVolumeType	StaticWidth;
	///ǰ��ID
	CVolumeType	FrontID;
	///������
	CVolumeType	OrderCount;
	///������
	CVolumeType	CancleCount;
	///��ѯ��
	CVolumeType	QueryCount;
	///�ɽ���
	CVolumeType	TradeCount;
	///�ɽ����
	CVolumeType	TradeMoney;
	///��󱨵���
	CVolumeType	OrderCntMax;
	///��󳷵���
	CVolumeType	CancleCntMax;
	///����ѯ��
	CVolumeType	QueryCntMax;
	///���ɽ���
	CVolumeType	TradeCntMax;
	///���ɽ����
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

///ϵͳ·����Ϣ
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
	///�������ı��
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

///ϵͳ·����Ϣ
class CFTDRspQryRouterInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�豸�ӿ���
	CTypeCommandType	Dev;
	///Ŀ������ip��ַ
	CIPAddressType	Destination;
	///����ip��ַ
	CIPAddressType	Gateway;
	///����ip��ַ
	CIPAddressType	Mask;
	///����״̬
	CTypeLanStatusType	Flag;
	///��������
	CVolumeType	RefCnt;
	///ʹ�ü���
	CVolumeType	Use;
	///metricֵ
	CVolumeType	Metric;
	///mtuֵ
	CVolumeType	Mtu;
	///winֵ
	CVolumeType	Win;
	///rttֵ
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

///ϵͳ·����Ϣ
class CFTDRtnRouterInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�豸�ӿ���
	CTypeCommandType	Dev;
	///Ŀ������ip��ַ
	CIPAddressType	Destination;
	///����ip��ַ
	CIPAddressType	Gateway;
	///����ip��ַ
	CIPAddressType	Mask;
	///����״̬
	CTypeLanStatusType	Flag;
	///��������
	CVolumeType	RefCnt;
	///ʹ�ü���
	CVolumeType	Use;
	///metricֵ
	CVolumeType	Metric;
	///mtuֵ
	CVolumeType	Mtu;
	///winֵ
	CVolumeType	Win;
	///rttֵ
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

///����I/O��Ϣ
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
	///�������ı��
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

///����I/O��Ϣ
class CFTDRspQryDiskIOField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///������
	CTypeCommandType	PartName;
	///ÿ��ReadMerge��
	CPriceType	ReadMerges;
	///ÿ��WriteMerge��
	CPriceType	WriteMerges;
	///ÿ��ReadIO��
	CPriceType	ReadIOs;
	///ÿ��WriteIO��
	CPriceType	WriteIOs;
	///ÿ��Read�ֽ���
	CPriceType	ReadKBs;
	///ÿ��Write�ֽ���
	CPriceType	WriteKBs;
	///Sizeֵ
	CPriceType	SizeVal;
	///Queueֵ
	CPriceType	QueueVal;
	///Svc_tֵ
	CPriceType	Svc_t;
	///��æ�ٷ���
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

///����I/O��Ϣ
class CFTDRtnDiskIOField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///������
	CTypeCommandType	PartName;
	///ÿ��ReadMerge��
	CPriceType	ReadMerges;
	///ÿ��WriteMerge��
	CPriceType	WriteMerges;
	///ÿ��ReadIO��
	CPriceType	ReadIOs;
	///ÿ��WriteIO��
	CPriceType	WriteIOs;
	///ÿ��Read�ֽ���
	CPriceType	ReadKBs;
	///ÿ��Write�ֽ���
	CPriceType	WriteKBs;
	///Sizeֵ
	CPriceType	SizeVal;
	///Queueֵ
	CPriceType	QueueVal;
	///Svc_tֵ
	CPriceType	Svc_t;
	///��æ�ٷ���
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

///ϵͳ״̬��Ϣ
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
	///�������ı��
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

///ϵͳ״̬��Ϣ
class CFTDRspQryStatInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///��Ծ������
	CVolumeType	ProcRun;
	///����������
	CVolumeType	ProcBlk;
	///ÿ���ɴ��̽���Swap��ҳ����
	CVolumeType	SwapIn;
	///ÿ����Swap������̵�ҳ����
	CVolumeType	SwapOut;
	///ÿ��ӿ��豸�����Block��
	CVolumeType	BlockIn;
	///ÿ������豸д���Block��
	CVolumeType	BlockOut;
	///ÿ���豸�жδ���
	CVolumeType	Inter;
	///ÿ���������л�����
	CVolumeType	Context;
	///�û�̬CPU�ٷ���
	CRatioType	CPUUser;
	///ϵͳ̬CPU�ٷ���
	CRatioType	CPUSys;
	///����̬CPU�ٷ���
	CRatioType	CPUIdle;
	///IO�ȴ�̬CPU�ٷ���
	CRatioType	CPUIOWait;
	///��ȡ̬CPU�ٷ���
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

///ϵͳ״̬��Ϣ
class CFTDRtnStatInfoField
{
public:
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///��Ծ������
	CVolumeType	ProcRun;
	///����������
	CVolumeType	ProcBlk;
	///ÿ���ɴ��̽���Swap��ҳ����
	CVolumeType	SwapIn;
	///ÿ����Swap������̵�ҳ����
	CVolumeType	SwapOut;
	///ÿ��ӿ��豸�����Block��
	CVolumeType	BlockIn;
	///ÿ������豸д���Block��
	CVolumeType	BlockOut;
	///ÿ���豸�жδ���
	CVolumeType	Inter;
	///ÿ���������л�����
	CVolumeType	Context;
	///�û�̬CPU�ٷ���
	CRatioType	CPUUser;
	///ϵͳ̬CPU�ٷ���
	CRatioType	CPUSys;
	///����̬CPU�ٷ���
	CRatioType	CPUIdle;
	///IO�ȴ�̬CPU�ٷ���
	CRatioType	CPUIOWait;
	///��ȡ̬CPU�ٷ���
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

///����ϵͳǰ�ñ����ֲ�����
class CFTDReqQryTradeOrderRttCutLineField
{
public:
	///������Ч����
	CDateType	MonDate;
	///�����޸�ʱ��
	CTimeType	MonTime;
	///�޸��û�����
	CTypeObjectIDType	UserName;
	///��Ӧʱ��ֲ�
	CNumberListsType	OrderRttCutLine;
	///ͳ�ƿ�����
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

///����ϵͳǰ�ñ����ֲ�����
class CFTDRspQryTradeOrderRttCutLineField
{
public:
	///������Ч����
	CDateType	MonDate;
	///�����޸�ʱ��
	CTimeType	MonTime;
	///�޸��û�����
	CTypeObjectIDType	UserName;
	///��Ӧʱ��ֲ�
	CNumberListsType	OrderRttCutLine;
	///ͳ�ƿ�����
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

///����ϵͳǰ�ñ����ֲ�����
class CFTDRtnTradeOrderRttCutLineField
{
public:
	///������Ч����
	CDateType	MonDate;
	///��Ӧʱ��ֲ�
	CNumberListsType	OrderRttCutLine;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MonDate)
		,
		TYPE_DESC(OrderRttCutLine)
	));
};
const DWORD FTD_FID_RtnTradeOrderRttCutLine=0x5488;

///��Ա�ͻ���Ϣ
class CFTDReqQryClientInfoField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ClientName)
	));
};
const DWORD FTD_FID_ReqQryClientInfo=0x5489;

///��Ա�ͻ���Ϣ
class CFTDRspQryClientInfoField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///��Ա�ͻ���Ϣ
class CFTDRtnClientInfoField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///֤������
	CIdCardTypeType	IdentifiedCardType;
	///֤������
	CIdentifiedCardNoType	IdentifiedCardNo;
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ͻ�����
	CClientTypeType	ClientType;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	///��������
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

///�¼���������
class CFTDReqQryEventDescriptionField
{
public:
	///����ID��
	CEventDesIDType	EventDesID;
	///�¼�������
	CTypeObjectIDType	UserName;
	///�¼���������
	CDateType	MonDate;
	///�¼�����ʱ��
	CTimeType	MonTime;
	///��������
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

///�¼�������������
class CFTDRspQryEventDescriptionField
{
public:
	///����ID��
	CEventDesIDType	EventDesID;
	///�¼�������
	CTypeObjectIDType	UserName;
	///�¼���������
	CDateType	MonDate;
	///�¼�����ʱ��
	CTimeType	MonTime;
	///��������
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

///�¼���������
class CFTDRtnEventDescriptionField
{
public:
	///����ID��
	CEventDesIDType	EventDesID;
	///�¼�������
	CTypeObjectIDType	UserName;
	///�¼���������
	CDateType	MonDate;
	///�¼�����ʱ��
	CTimeType	MonTime;
	///��������
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

///ǰ��ΨһID����
class CFTDReqQryFrontUniqueIDField
{
public:
	///ǰ��ΨһID���
	CFrontIDType	FrontID;
	///ǰ�ñ��ȫ��
	CFrontSerialNumType	FrontName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(FrontName)
	));
};
const DWORD FTD_FID_ReqQryFrontUniqueID=0x548f;

///ǰ��ΨһID����
class CFTDRspQryFrontUniqueIDField
{
public:
	///ǰ��ΨһID���
	CFrontIDType	FrontID;
	///ǰ�ñ��ȫ��
	CFrontSerialNumType	FrontName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(FrontName)
	));
};
const DWORD FTD_FID_RspQryFrontUniqueID=0x5490;

///����ǰ��ΨһID��Ϣ
class CFTDRtnFrontUniqueIDField
{
public:
	///ǰ��ΨһID���
	CFrontIDType	FrontID;
	///ǰ�ñ��ȫ��
	CFrontSerialNumType	FrontName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(FrontName)
	));
};
const DWORD FTD_FID_RtnFrontUniqueID=0x5491;

///��Ա��·��ַ�������
class CFTDReqQryNetPartyLinkAddrChangeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ID
	CVolumeType	RelationID;
	///���ǰ��ַ
	CNetAttrTypeType	OLDADDRESS;
	///������ַ
	CNetAttrTypeType	NEWADDRESS;
	///������
	CCfgNameType	OPERATOR;
	///�޸�����
	CDateType	MonDate;
	///�޸�ʱ��
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

///��Ա��·��ַ�����Ӧ
class CFTDRspQryNetPartyLinkAddrChangeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ID
	CVolumeType	RelationID;
	///���ǰ��ַ
	CNetAttrTypeType	OLDADDRESS;
	///������ַ
	CNetAttrTypeType	NEWADDRESS;
	///������
	CCfgNameType	OPERATOR;
	///�޸�����
	CDateType	MonDate;
	///�޸�ʱ��
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

///���Ļ�Ա��·��ַ�����Ϣ
class CFTDRtnNetPartyLinkAddrChangeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ID
	CVolumeType	RelationID;
	///���ǰ��ַ
	CNetAttrTypeType	OLDADDRESS;
	///������ַ
	CNetAttrTypeType	NEWADDRESS;
	///������
	CCfgNameType	OPERATOR;
	///�޸�����
	CDateType	MonDate;
	///�޸�ʱ��
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

///������ɾ����Ա�б���Ϣ
class CFTDReqQryNetDelPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///Ӧ����ɾ����Ա�б���Ϣ
class CFTDRspQryNetDelPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///������ɾ����Ա�б���Ϣ
class CFTDRtnNetDelPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///����������������
class CFTDReqQryPerformanceTopField
{
public:
	///��������
	CVolumeType	OperationType;
	///���ָ������
	CAttrTypeType	AttrType;
	///��������
	CNetAreaType	NetArea;
	///����������
	CNetSubAreaType	NetSubArea;
	///��ѯ�ؼ���
	CKeyWordType	KeyWord;
	///������ֵ����
	CSortValueType	SortValue;
	///��������
	CSortTypeType	SortType;
	///��ѯʱ������
	CDuringTimeTypeType	DuringTimeType;
	///��ѯʱ��ֵ
	CDuringTimeValueType	DuringTimeValue;
	///ǰN��ֵ
	CTopNType	TopN;
	///����������
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

///����������������
class CFTDRspQryPerformanceTopField
{
public:
	///��������
	CVolumeType	OperationType;
	///���ָ������
	CAttrTypeType	AttrType;
	///��������
	CNetAreaType	NetArea;
	///����������
	CNetSubAreaType	NetSubArea;
	///��ѯ�ؼ���
	CKeyWordType	KeyWord;
	///������ֵ����
	CSortValueType	SortValue;
	///��������
	CSortTypeType	SortType;
	///��ѯʱ������
	CDuringTimeTypeType	DuringTimeType;
	///��ѯʱ��ֵ
	CDuringTimeValueType	DuringTimeValue;
	///ǰN��ֵ
	CTopNType	TopN;
	///����������
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

///����������������
class CFTDRtnPerformanceTopField
{
public:
	///��������
	CVolumeType	OperationType;
	///���ָ������
	CAttrTypeType	AttrType;
	///��������
	CNetAreaType	NetArea;
	///����������
	CNetSubAreaType	NetSubArea;
	///��ѯ�ؼ���
	CKeyWordType	KeyWord;
	///������ֵ����
	CSortValueType	SortValue;
	///��������
	CSortTypeType	SortType;
	///��ѯʱ������
	CDuringTimeTypeType	DuringTimeType;
	///��ѯʱ��ֵ
	CDuringTimeValueType	DuringTimeValue;
	///ǰN��ֵ
	CTopNType	TopN;
	///����������
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

///�����Լ״̬�л�
class CFTDReqQryInstrumentStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	CTimeType	EnterTime;
	///���뱾״̬ԭ��
	CInstStatusEnterReasonType	EnterReason;
	///���뱾״̬����
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

///���غ�Լ״̬�л�
class CFTDRspQryInstrumentStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	CTimeType	EnterTime;
	///���뱾״̬ԭ��
	CInstStatusEnterReasonType	EnterReason;
	///���뱾״̬����
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

///���ĺ�Լ״̬�л�
class CFTDRtnInstrumentStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	CTimeType	EnterTime;
	///���뱾״̬ԭ��
	CInstStatusEnterReasonType	EnterReason;
	///���뱾״̬����
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

///�����Լ���׽���Ϣ
class CFTDReqQryCurrTradingSegmentAttrField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///���׽׶�����
	CTradingSegmentNameType	TradingSegmentName;
	///��ʼʱ��
	CTimeType	StartTime;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��ǰ����
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

///���غ�Լ���׽���Ϣ
class CFTDRspQryCurrTradingSegmentAttrField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///���׽׶�����
	CTradingSegmentNameType	TradingSegmentName;
	///��ʼʱ��
	CTimeType	StartTime;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��ǰ����
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

///���ĺ�Լ���׽���Ϣ
class CFTDRtnCurrTradingSegmentAttrField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///���׽׶�����
	CTradingSegmentNameType	TradingSegmentName;
	///��ʼʱ��
	CTimeType	StartTime;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��ǰ����
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

///ʵʱ�����������
class CFTDReqQryRealTimeNetObjectAttrField
{
public:
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
	CNetAttrTypeType	AttrType;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ObjectID)
		,
		TYPE_DESC(AttrType)
	));
};
const DWORD FTD_FID_ReqQryRealTimeNetObjectAttr=0x8003;

///�����������
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

///�������Ӧ��
class CFTDRspQryNetAreaField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///�������Ӧ��
class CFTDRtnNetAreaField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///�����������
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

///�������Ӧ��
class CFTDRspQryNetSubAreaField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///�������Ӧ��
class CFTDRtnNetSubAreaField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///�����������
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

///�������Ӧ��
class CFTDRspQryNetSubAreaIPField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip��ַ
	CIPAddressType	IP;
	///����
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

///�������Ӧ��
class CFTDRtnNetSubAreaIPField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip��ַ
	CIPAddressType	IP;
	///����
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

///�����豸̽������
class CFTDReqQryNetDeviceDetectField
{
public:
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip��ַ
	CIPAddressType	IP;
	///����
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

///�����豸��ѯ����
class CFTDReqQryNetDeviceRequestField
{
public:
	///��������
	CVolumeType	OperationType;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///��Ϊ���ֵ�ְ������
	CTypeObjectIDType	FuctionArea;
	///IP��
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

///�����豸
class CFTDRspQryNetDeviceField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///����ID  
	CVolumeType	CATEGORY_ID;
	///��Ϊ���ֵ�ְ������  
	CTypeObjectIDType	FuctionArea;
	///IP��ַ  
	CIPAddressType	IPADDR;
	///IP��    
	CVolumeType	IPDECODE;
	///�豸���� 
	CNetObjectIDType	NAME;
	///             
	CVolumeType	PORTNUMBER;
	///          
	CTypeObjectIDType	CONFIGFILE;
	///��ͬ����  
	CTypeObjectIDType	RCOMMUNITY;
	///snmp�汾     
	CVolumeType	SNMPVERSION;
	///ramsize(B)   
	CVolumeType	RAMSIZE;
	///falshsize(B) 
	CVolumeType	FLASHSIZE;
	///nvramsize(B) 
	CVolumeType	NVRAMSIZE;
	///��������
	CVolumeType	CABINET_ID;
	///
	CVolumeType	ROOM_ID;
	///����汾
	CVolumeType	IOSVERSION_ID;
	///ϵͳ����
	CNetAttrTypeType	DESCRIPTION;
	///��¼�û���
	CTypeObjectIDType	USERNAME;
	///��¼����
	CNetAttrTypeType	PASSWD;
	///enable����
	CNetAttrTypeType	ENPASSWD;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///���ñ���Э��
	CVolumeType	CFGSAVETYPE;
	///�豸�ͺ�
	CNetObjectIDType	DEVICETYPE;
	///�Ƿ���Ÿ澯
	CVolumeType	SENDSMS;
	///�Ƿ��Զ�snmp̽��
	CVolumeType	ISSNMP;
	///��λ��
	CVolumeType	SLOTNUM;
	///�Ƿ��Զ�ping
	CVolumeType	ISPING;
	///�˿�����
	CVolumeType	IFNUM;
	///Ѳ�����
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

///�����豸
class CFTDRtnNetDeviceField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///����ID  
	CVolumeType	CATEGORY_ID;
	///��Ϊ���ֵ�ְ������  
	CTypeObjectIDType	FuctionArea;
	///IP��ַ  
	CIPAddressType	IPADDR;
	///IP��    
	CVolumeType	IPDECODE;
	///�豸���� 
	CNetObjectIDType	NAME;
	///             
	CVolumeType	PORTNUMBER;
	///          
	CTypeObjectIDType	CONFIGFILE;
	///��ͬ����  
	CTypeObjectIDType	RCOMMUNITY;
	///snmp�汾     
	CVolumeType	SNMPVERSION;
	///ramsize(B)   
	CVolumeType	RAMSIZE;
	///falshsize(B) 
	CVolumeType	FLASHSIZE;
	///nvramsize(B) 
	CVolumeType	NVRAMSIZE;
	///��������
	CVolumeType	CABINET_ID;
	///
	CVolumeType	ROOM_ID;
	///����汾
	CVolumeType	IOSVERSION_ID;
	///ϵͳ����
	CNetAttrTypeType	DESCRIPTION;
	///��¼�û���
	CTypeObjectIDType	USERNAME;
	///��¼����
	CNetAttrTypeType	PASSWD;
	///enable����
	CNetAttrTypeType	ENPASSWD;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///���ñ���Э��
	CVolumeType	CFGSAVETYPE;
	///�豸�ͺ�
	CNetObjectIDType	DEVICETYPE;
	///�Ƿ���Ÿ澯
	CVolumeType	SENDSMS;
	///�Ƿ��Զ�snmp̽��
	CVolumeType	ISSNMP;
	///��λ��
	CVolumeType	SLOTNUM;
	///�Ƿ��Զ�ping
	CVolumeType	ISPING;
	///�˿�����
	CVolumeType	IFNUM;
	///Ѳ�����
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

///�����豸̽������Ӧ��
class CFTDRspQryNetDeviceDetectField
{
public:
	///SysNetArea
	CVolumeType	SysNetAreaID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///ip��ַ
	CIPAddressType	IP;
	///����
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

///��¥��ѯ
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

///��¥
class CFTDRspQryNetBuildingField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///��¥
class CFTDRtnNetBuildingField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///������ѯ
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

///����
class CFTDRspQryNetRoomField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��¥
	CVolumeType	SysNetBuildingID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///����
class CFTDRtnNetRoomField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��¥
	CVolumeType	SysNetBuildingID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///����
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

///����
class CFTDRspQryNetCabinetsField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetRoomID
	CVolumeType	SysNetRoomID;
	///SysNetBuildingID
	CVolumeType	SysNetBuildingID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
	CTypeObjectIDType	EName;
	///��������
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

///����
class CFTDRtnNetCabinetsField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetRoomID
	CVolumeType	SysNetRoomID;
	///SysNetBuildingID
	CVolumeType	SysNetBuildingID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
	CTypeObjectIDType	EName;
	///��������
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
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceType;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///��λ
	CTypeObjectIDType	Unit;
	///�Ƿ������־
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
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceType;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///��λ
	CTypeObjectIDType	Unit;
	///�Ƿ������־
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
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceType;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///��λ
	CTypeObjectIDType	Unit;
	///�Ƿ������־
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

///ʱ�����
class CFTDReqQryNetTimePolicyField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ʱ�����������
	CTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	CTypeObjectIDType	EName;
	///��������
	CVolumeType	PolicyType;
	///���������ô�
	CPolicyStringTypeType	PolicyString;
	///����������
	CVolumeType	TradingDay;
	///����������
	CNetAttrTypeType	Description;
	///��������
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

///ʱ�����
class CFTDRspQryNetTimePolicyField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ʱ�����������
	CTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	CTypeObjectIDType	EName;
	///��������
	CVolumeType	PolicyType;
	///���������ô�
	CPolicyStringTypeType	PolicyString;
	///����������
	CVolumeType	TradingDay;
	///����������
	CNetAttrTypeType	Description;
	///��������
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

///ʱ�����
class CFTDRtnNetTimePolicyField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ʱ�����������
	CTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	CTypeObjectIDType	EName;
	///��������
	CVolumeType	PolicyType;
	///���������ô�
	CPolicyStringTypeType	PolicyString;
	///����������
	CVolumeType	TradingDay;
	///����������
	CNetAttrTypeType	Description;
	///��������
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

///�ɼ������ѯ
class CFTDReqQryNetGatherTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
	CVolumeType	PolicyTypeID;
	///��������
	CVolumeType	DataType;
	///���ͱ�ʶ
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

///�ɼ�����
class CFTDRspQryNetGatherTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
	CVolumeType	PolicyTypeID;
	///��������
	CVolumeType	DataType;
	///���ͱ�ʶ
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

///�ɼ�����
class CFTDRtnNetGatherTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
	CVolumeType	PolicyTypeID;
	///��������
	CVolumeType	DataType;
	///���ͱ�ʶ
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

///�ɼ������ѯ
class CFTDReqQryNetDeviceChgField
{
public:
	///�豸ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///�����ض���ID
	CNetObjectIDType	OldObjectID;
	///�����ض���ID
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

///�ɼ�����
class CFTDRspQryNetDeviceChgField
{
public:
	///�豸ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///�����ض���ID
	CNetObjectIDType	OldObjectID;
	///�����ض���ID
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

///�ɼ�����
class CFTDRtnNetDeviceChgField
{
public:
	///�豸ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///�����ض���ID
	CNetObjectIDType	OldObjectID;
	///�����ض���ID
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

///�����豸�ͺ�����
class CFTDReqQryNetDeviceTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
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

///�����豸�ͺ�
class CFTDRspQryNetDeviceTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
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

///�����豸�ͺ�
class CFTDRtnNetDeviceTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
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

///�����豸�������
class CFTDReqQryNetDeviceCategoryField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���������
	CTypeObjectIDType	CName;
	///���Ӣ����
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

///�����豸���
class CFTDRspQryNetDeviceCategoryField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���������
	CTypeObjectIDType	CName;
	///���Ӣ����
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

///�����豸���
class CFTDRtnNetDeviceCategoryField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���������
	CTypeObjectIDType	CName;
	///���Ӣ����
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

///�豸��������
class CFTDReqQryNetManufactoryField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///�豸����
class CFTDRspQryNetManufactoryField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///�豸����
class CFTDRtnNetManufactoryField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///�豸��ͬ������
class CFTDReqQryNetCommunityField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP��ַ
	CIPAddressType	IPADDR;
	///��ͬ����
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

///�豸��ͬ��
class CFTDRspQryNetCommunityField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP��ַ
	CIPAddressType	IPADDR;
	///��ͬ����
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

///�豸��ͬ��
class CFTDRtnNetCommunityField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP��ַ
	CIPAddressType	IPADDR;
	///��ͬ����
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

///�˿���������
class CFTDReqQryNetPortTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������
	CTypeObjectIDType	CName;
	///Ӣ����
	CTypeObjectIDType	EName;
	///����
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

///�˿�����
class CFTDRspQryNetPortTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������
	CTypeObjectIDType	CName;
	///Ӣ����
	CTypeObjectIDType	EName;
	///����
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

///�˿�����
class CFTDRtnNetPortTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������
	CTypeObjectIDType	CName;
	///Ӣ����
	CTypeObjectIDType	EName;
	///����
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

///��Ա����ص�����
class CFTDReqQryNetPartAccessSpotField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������
	CTypeObjectIDType	CName;
	///Ӣ����
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

///��Ա����ص�
class CFTDRspQryNetPartAccessSpotField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������
	CTypeObjectIDType	CName;
	///Ӣ����
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

///��Ա����ص�
class CFTDRtnNetPartAccessSpotField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������
	CTypeObjectIDType	CName;
	///Ӣ����
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

///�˿�����
class CFTDReqQryNetInterfaceField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�˿�����
	CVolumeType	IfType;
	///�˿���
	CTypeObjectIDType	EName;
	///IP��ַ
	CIPAddressType	IpAddress;
	///����
	CIPAddressType	IpMask;
	///�˿�״̬
	CVolumeType	IfStatus;
	///�����ַ
	CTypeObjectIDType	MAC;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	CTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	CVolumeType	isPolling;
	///����
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

///�˿�
class CFTDRspQryNetInterfaceField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�˿�����
	CVolumeType	IfType;
	///�˿���
	CTypeObjectIDType	EName;
	///IP��ַ
	CIPAddressType	IpAddress;
	///����
	CIPAddressType	IpMask;
	///�˿�״̬
	CVolumeType	IfStatus;
	///�����ַ
	CTypeObjectIDType	MAC;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	CTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	CVolumeType	isPolling;
	///����
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

///�˿�
class CFTDRtnNetInterfaceField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�˿�����
	CVolumeType	IfType;
	///�˿���
	CTypeObjectIDType	EName;
	///IP��ַ
	CIPAddressType	IpAddress;
	///����
	CIPAddressType	IpMask;
	///�˿�״̬
	CVolumeType	IfStatus;
	///�����ַ
	CTypeObjectIDType	MAC;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	CTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	CVolumeType	isPolling;
	///����
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
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///��λ
	CTypeObjectIDType	Unit;
	///�Ƿ������־
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
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///��λ
	CTypeObjectIDType	Unit;
	///�Ƿ������־
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

///��ض������
class CFTDReqQryNetMonitorTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
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

///��ض������
class CFTDRspQryNetMonitorTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
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

///��ض������
class CFTDRtnNetMonitorTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
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

///ָ��ͳ��
class CFTDReqQryNetMonitorAttrScopeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ָ��������
	CNetAttrTypeType	CName;
	///ָ��Ӣ����
	CNetAttrTypeType	EName;
	///ע��
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

///ָ��ͳ��
class CFTDRspQryNetMonitorAttrScopeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ָ��������
	CNetAttrTypeType	CName;
	///ָ��Ӣ����
	CNetAttrTypeType	EName;
	///ע��
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

///ָ��ͳ��
class CFTDRtnNetMonitorAttrScopeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ָ��������
	CNetAttrTypeType	CName;
	///ָ��Ӣ����
	CNetAttrTypeType	EName;
	///ע��
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

///���ָ���
class CFTDReqQryNetMonitorAttrTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///�豸���
	CVolumeType	MonitorType_ID;
	///������ָ��ID
	CVolumeType	AttrType_ID;
	///��������
	CTypeObjectIDType	MANUFACTORY;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///������ָ��
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

///���ָ���
class CFTDRspQryNetMonitorAttrTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///�豸���
	CVolumeType	MonitorType_ID;
	///������ָ��ID
	CVolumeType	AttrType_ID;
	///��������
	CTypeObjectIDType	MANUFACTORY;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///������ָ��
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

///���ָ���
class CFTDRtnNetMonitorAttrTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///�豸���
	CVolumeType	MonitorType_ID;
	///������ָ��ID
	CVolumeType	AttrType_ID;
	///��������
	CTypeObjectIDType	MANUFACTORY;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///������ָ��
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

///��ض���ָ���
class CFTDReqQryNetMonitorObjectAttrField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///������ָ��
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
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

///��ض���ָ���
class CFTDRspQryNetMonitorObjectAttrField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///������ָ��
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
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

///��ض���ָ���
class CFTDRtnNetMonitorObjectAttrField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��ض���
	CNetObjectIDType	ObjectID;
	///������ָ��
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
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

///ְ����
class CFTDReqQryNetFuncAreaField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///ְ����
class CFTDRspQryNetFuncAreaField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///ְ����
class CFTDRtnNetFuncAreaField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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

///���ָ���
class CFTDReqQryNetMonitorCommandTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������ID
	CVolumeType	Manufactory_ID;
	///�豸���ID
	CVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	CVolumeType	DeviceModle_ID;
	///������ID
	CVolumeType	ActionGroup_ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceModle;
	///������
	CTypeObjectIDType	ActionGroup;
	///ָ����
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

///���ָ���
class CFTDRspQryNetMonitorCommandTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������ID
	CVolumeType	Manufactory_ID;
	///�豸���ID
	CVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	CVolumeType	DeviceModle_ID;
	///������ID
	CVolumeType	ActionGroup_ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceModle;
	///������
	CTypeObjectIDType	ActionGroup;
	///ָ����
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

///���ָ���
class CFTDRtnNetMonitorCommandTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������ID
	CVolumeType	Manufactory_ID;
	///�豸���ID
	CVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	CVolumeType	DeviceModle_ID;
	///������ID
	CVolumeType	ActionGroup_ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceModle;
	///������
	CTypeObjectIDType	ActionGroup;
	///ָ����
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

///�������
class CFTDReqQryNetMonitorActionGroupField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������������
	CTypeObjectIDType	CName;
	///������Ӣ����
	CTypeObjectIDType	EName;
	///����������
	CVolumeType	ActionType;
	///ע��
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

///�������
class CFTDRspQryNetMonitorActionGroupField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������������
	CTypeObjectIDType	CName;
	///������Ӣ����
	CTypeObjectIDType	EName;
	///����������
	CVolumeType	ActionType;
	///ע��
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

///�������
class CFTDRtnNetMonitorActionGroupField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������������
	CTypeObjectIDType	CName;
	///������Ӣ����
	CTypeObjectIDType	EName;
	///����������
	CVolumeType	ActionType;
	///ע��
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

///�豸�������
class CFTDReqQryNetMonitorDeviceGroupField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸������������
	CTypeObjectIDType	CName;
	///�豸������Ӣ����
	CTypeObjectIDType	EName;
	///�豸��������
	CNetString512Type	Condition;
	///ע��
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

///�豸�������
class CFTDRspQryNetMonitorDeviceGroupField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸������������
	CTypeObjectIDType	CName;
	///�豸������Ӣ����
	CTypeObjectIDType	EName;
	///�豸��������
	CNetString512Type	Condition;
	///ע��
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

///�豸�������
class CFTDRtnNetMonitorDeviceGroupField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸������������
	CTypeObjectIDType	CName;
	///�豸������Ӣ����
	CTypeObjectIDType	EName;
	///�豸��������
	CNetString512Type	Condition;
	///ע��
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

///������Ϣ��
class CFTDReqQryNetMonitorTaskInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
	CTypeObjectIDType	EName;
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///������Ա������ID
	CVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	CVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	CVolumeType	TaskPriority_ID;
	///����������ID
	CVolumeType	OutputPolicy_ID;
	///��������ID
	CVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	CGeneralResultType	EventExprStr;
	///�豸������
	CTypeObjectIDType	DeviceGroup;
	///������Ա������
	CTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	CTypeObjectIDType	TimePolicy;
	///�������ȼ�
	CTypeObjectIDType	TaskPriority;
	///����������
	CTypeObjectIDType	OutputPolicy;
	///��������
	CTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	CVolumeType	ValidFlag;
	///����״̬��ʶ
	CVolumeType	TaskStatus;
	///��������
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

///������Ϣ��
class CFTDRspQryNetMonitorTaskInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
	CTypeObjectIDType	EName;
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///������Ա������ID
	CVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	CVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	CVolumeType	TaskPriority_ID;
	///����������ID
	CVolumeType	OutputPolicy_ID;
	///��������ID
	CVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	CGeneralResultType	EventExprStr;
	///�豸������
	CTypeObjectIDType	DeviceGroup;
	///������Ա������
	CTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	CTypeObjectIDType	TimePolicy;
	///�������ȼ�
	CTypeObjectIDType	TaskPriority;
	///����������
	CTypeObjectIDType	OutputPolicy;
	///��������
	CTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	CVolumeType	ValidFlag;
	///����״̬��ʶ
	CVolumeType	TaskStatus;
	///��������
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

///������Ϣ��
class CFTDRtnNetMonitorTaskInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
	CTypeObjectIDType	EName;
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///������Ա������ID
	CVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	CVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	CVolumeType	TaskPriority_ID;
	///����������ID
	CVolumeType	OutputPolicy_ID;
	///��������ID
	CVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	CGeneralResultType	EventExprStr;
	///�豸������
	CTypeObjectIDType	DeviceGroup;
	///������Ա������
	CTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	CTypeObjectIDType	TimePolicy;
	///�������ȼ�
	CTypeObjectIDType	TaskPriority;
	///����������
	CTypeObjectIDType	OutputPolicy;
	///��������
	CTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	CVolumeType	ValidFlag;
	///����״̬��ʶ
	CVolumeType	TaskStatus;
	///��������
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

///��������
class CFTDReqQryNetMonitorTaskResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///����ID
	CVolumeType	Task_ID;
	///ִ�д���
	CVolumeType	OperateTime;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ָ�
	CNetString256Type	InstructChain;
	///�����
	CNetString1KType	ResultChain;
	///����ִ�б�ʶ
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

///��������
class CFTDRspQryNetMonitorTaskResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///����ID
	CVolumeType	Task_ID;
	///ִ�д���
	CVolumeType	OperateTime;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ָ�
	CNetString256Type	InstructChain;
	///�����
	CNetString1KType	ResultChain;
	///����ִ�б�ʶ
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

///��������
class CFTDRtnNetMonitorTaskResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///����ID
	CVolumeType	Task_ID;
	///ִ�д���
	CVolumeType	OperateTime;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ָ�
	CNetString256Type	InstructChain;
	///�����
	CNetString1KType	ResultChain;
	///����ִ�б�ʶ
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

///�������
class CFTDReqQryNetMonitorTaskObjectSetField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///�豸ID
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

///�������
class CFTDRspQryNetMonitorTaskObjectSetField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///�豸ID
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

///�������
class CFTDRtnNetMonitorTaskObjectSetField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///�豸ID
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

///��Ա��·��Ϣ��
class CFTDReqQryNetPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///��Ա��·��Ϣ��
class CFTDRspQryNetPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///��Ա��·��Ϣ��
class CFTDRtnNetPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///��ض���ָ����ձ�
class CFTDReqQryNetMonitorActionAttrField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������ID
	CVolumeType	ActionGroup_ID;
	///��ض���ID
	CVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
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

///��ض���ָ����ձ�
class CFTDRspQryNetMonitorActionAttrField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������ID
	CVolumeType	ActionGroup_ID;
	///��ض���ID
	CVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
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

///��ض���ָ����ձ�
class CFTDRtnNetMonitorActionAttrField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///������ID
	CVolumeType	ActionGroup_ID;
	///��ض���ID
	CVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
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

///ģ��
class CFTDReqQryNetModuleField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///����
	CTypeObjectIDType	Name;
	///����
	CNetObjectIDType	Description;
	///ģ������
	CVolumeType	ModuleIndex;
	///��������
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

///ģ��
class CFTDRspQryNetModuleField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///����
	CTypeObjectIDType	Name;
	///����
	CNetObjectIDType	Description;
	///ģ������
	CVolumeType	ModuleIndex;
	///��������
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

///ģ��
class CFTDRtnNetModuleField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///����
	CTypeObjectIDType	Name;
	///����
	CNetObjectIDType	Description;
	///ģ������
	CVolumeType	ModuleIndex;
	///��������
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

///�澯���ʽ��Ϣ��
class CFTDReqQryNetEventExprField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����¼���
	CNetObjectIDType	CNAME;
	///Ӣ���¼���
	CNetObjectIDType	ENAME;
	///�¼�����
	CCfgNameType	WarningLEVEL;
	///�¼�����
	CVolumeType	EventTypeID;
	///�¼�������
	CVolumeType	SubEventTypeID;
	///�澯���ʱ��
	CVolumeType	GIVEUPTIME;
	///���ƶ�����
	CGeneralResultType	CONTROL;
	///���ʽ������
	CGeneralResultType	EXPR;
	///�¼�����
	CTypeObjectIDType	BRIEF;
	///�¼�������
	CNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	CVolumeType	MSGGROUP_ID;
	///����Ա��ID
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

///�澯���ʽ��Ϣ��
class CFTDRspQryNetEventExprField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����¼���
	CNetObjectIDType	CNAME;
	///Ӣ���¼���
	CNetObjectIDType	ENAME;
	///�¼�����
	CCfgNameType	WarningLEVEL;
	///�¼�����
	CVolumeType	EventTypeID;
	///�¼�������
	CVolumeType	SubEventTypeID;
	///�澯���ʱ��
	CVolumeType	GIVEUPTIME;
	///���ƶ�����
	CGeneralResultType	CONTROL;
	///���ʽ������
	CGeneralResultType	EXPR;
	///�¼�����
	CTypeObjectIDType	BRIEF;
	///�¼�������
	CNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	CVolumeType	MSGGROUP_ID;
	///����Ա��ID
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

///�澯���ʽ��Ϣ��
class CFTDRtnNetEventExprField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����¼���
	CNetObjectIDType	CNAME;
	///Ӣ���¼���
	CNetObjectIDType	ENAME;
	///�¼�����
	CCfgNameType	WarningLEVEL;
	///�¼�����
	CVolumeType	EventTypeID;
	///�¼�������
	CVolumeType	SubEventTypeID;
	///�澯���ʱ��
	CVolumeType	GIVEUPTIME;
	///���ƶ�����
	CGeneralResultType	CONTROL;
	///���ʽ������
	CGeneralResultType	EXPR;
	///�¼�����
	CTypeObjectIDType	BRIEF;
	///�¼�������
	CNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	CVolumeType	MSGGROUP_ID;
	///����Ա��ID
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

///�¼�����
class CFTDReqQryNetEventTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
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

///�¼�����
class CFTDRspQryNetEventTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
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

///�¼�����
class CFTDRtnNetEventTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
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

///�¼�������
class CFTDReqQryNetSubEventTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�������������
	CTypeObjectIDType	CName;
	///�¼�������Ӣ����
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

///�¼�������
class CFTDRspQryNetSubEventTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�������������
	CTypeObjectIDType	CName;
	///�¼�������Ӣ����
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

///�¼�������
class CFTDRtnNetSubEventTypeField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�������������
	CTypeObjectIDType	CName;
	///�¼�������Ӣ����
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

///�¼�����
class CFTDReqQryNetEventLevelField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
	CTypeObjectIDType	EName;
	///�¼�����������
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

///�¼�����
class CFTDRspQryNetEventLevelField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
	CTypeObjectIDType	EName;
	///�¼�����������
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

///�¼�����
class CFTDRtnNetEventLevelField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
	CTypeObjectIDType	EName;
	///�¼�����������
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

///������״̬��
class CFTDReqQryNetMonitorTaskStatusResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///����ID
	CVolumeType	Task_ID;
	///ִ�д���
	CVolumeType	OperateTime;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///����ִ�б�ʶ
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

///������״̬��
class CFTDRspQryNetMonitorTaskStatusResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///����ID
	CVolumeType	Task_ID;
	///ִ�д���
	CVolumeType	OperateTime;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///����ִ�б�ʶ
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

///������״̬��
class CFTDRtnNetMonitorTaskStatusResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///����ID
	CVolumeType	Task_ID;
	///ִ�д���
	CVolumeType	OperateTime;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///����ִ�б�ʶ
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

///��½���÷��������
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

///�Ե�½���÷����������Ӧ
class CFTDRspQryConfigLoginField
{
public:
	///�������
	CErrorIDType	ErrorID;
	///������Ϣ
	CErrorMsgType	ErrorMsg;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
	));
};
const DWORD FTD_FID_RspQryConfigLogin=0x8130;

///�Ե�ǰ��¼���õķ����ɫ����Ӧ
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

///�˳���������
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

///�豸���ñ�
class CFTDReqQryNetCfgFileField
{
public:
	///��������
	CVolumeType	OperationType;
	///��ض���
	CNetObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�����ļ���
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

///�豸���ñ�
class CFTDRspQryNetCfgFileField
{
public:
	///��������
	CVolumeType	OperationType;
	///��ض���
	CNetObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�����ļ���
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

///�豸���ñ�
class CFTDRtnNetCfgFileField
{
public:
	///��������
	CVolumeType	OperationType;
	///��ض���
	CNetObjectIDType	ObjectID;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///�����ļ���
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

///���������������
class CFTDReqQryNetMonitorDeviceTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ��
	CNetString256Type	InstructChain;
	///ָ�����
	CNetString128Type	InstructAlias;
	///ָ�������
	CNetString256Type	InstructArgs;
	///ָ�귧ֵ��
	CNetString2KType	DefParamChain;
	///������־
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

///���������������
class CFTDRspQryNetMonitorDeviceTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ��
	CNetString256Type	InstructChain;
	///ָ�����
	CNetString128Type	InstructAlias;
	///ָ�������
	CNetString256Type	InstructArgs;
	///ָ�귧ֵ��
	CNetString2KType	DefParamChain;
	///������־
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

///���������������
class CFTDRtnNetMonitorDeviceTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ��
	CNetString256Type	InstructChain;
	///ָ�����
	CNetString128Type	InstructAlias;
	///ָ�������
	CNetString256Type	InstructArgs;
	///ָ�귧ֵ��
	CNetString2KType	DefParamChain;
	///������־
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

///����ָ��ָ�꼯��
class CFTDReqQryNetMonitorTaskInstAttrsField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ�����
	CNetString128Type	InstructAlias;
	///�豸�ͺ�
	CNetString128Type	DEVICETYPE;
	///ָ�괮
	CNetString256Type	AttrsChain;
	///ָ�����
	CNetString512Type	DefRegularChain;
	///ָ�귧ֵ��
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

///����ָ��ָ�꼯��
class CFTDRspQryNetMonitorTaskInstAttrsField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ�����
	CNetString128Type	InstructAlias;
	///�豸�ͺ�
	CNetString128Type	DEVICETYPE;
	///ָ�괮
	CNetString256Type	AttrsChain;
	///ָ�����
	CNetString512Type	DefRegularChain;
	///ָ�귧ֵ��
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

///����ָ��ָ�꼯��
class CFTDRtnNetMonitorTaskInstAttrsField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ�����
	CNetString128Type	InstructAlias;
	///�豸�ͺ�
	CNetString128Type	DEVICETYPE;
	///ָ�괮
	CNetString256Type	AttrsChain;
	///ָ�����
	CNetString512Type	DefRegularChain;
	///ָ�귧ֵ��
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

///�ļ�ͨ�ò���
class CFTDReqQryFileGeneralOperField
{
public:
	///��������
	CVolumeType	OperationType;
	///�ļ���
	CNetAttrTypeType	FileName;
	///�ļ��汾
	CFileVersionType	Version;
	///С�汾��
	CVolumeType	SubVersion;
	///����
	CDateType	MonDate;
	///ʱ��
	CTimeType	MonTime;
	///�ļ������û�
	CTypeUserNameType	UserName;
	///��������
	CVolumeType	OperType;
	///�������
	CVolumeType	OperResult;
	///ע��
	CNetAttrTypeType	Comments;
	///�ļ�ƫ��
	COffsetType	Offset;
	///Content��ʵ�����ݳ���
	CCommLengthType	Length;
	///�ļ�����
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

///�ļ�ͨ�ò���
class CFTDRspQryFileGeneralOperField
{
public:
	///��������
	CVolumeType	OperationType;
	///�ļ���
	CNetAttrTypeType	FileName;
	///�ļ��汾
	CFileVersionType	Version;
	///С�汾��
	CVolumeType	SubVersion;
	///����
	CDateType	MonDate;
	///ʱ��
	CTimeType	MonTime;
	///�ļ������û�
	CTypeUserNameType	UserName;
	///��������
	CVolumeType	OperType;
	///�������
	CVolumeType	OperResult;
	///ע��
	CNetAttrTypeType	Comments;
	///�ļ�ƫ��
	COffsetType	Offset;
	///Content��ʵ�����ݳ���
	CCommLengthType	Length;
	///�ļ�����
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

///�ļ�ͨ�ò���
class CFTDRtnFileGeneralOperField
{
public:
	///��������
	CVolumeType	OperationType;
	///�ļ���
	CNetAttrTypeType	FileName;
	///�ļ��汾
	CFileVersionType	Version;
	///С�汾��
	CVolumeType	SubVersion;
	///����
	CDateType	MonDate;
	///ʱ��
	CTimeType	MonTime;
	///�ļ������û�
	CTypeUserNameType	UserName;
	///��������
	CVolumeType	OperType;
	///�������
	CVolumeType	OperResult;
	///ע��
	CNetAttrTypeType	Comments;
	///�ļ�ƫ��
	COffsetType	Offset;
	///Content��ʵ�����ݳ���
	CCommLengthType	Length;
	///�ļ�����
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

///���߱�
class CFTDReqQryNetBaseLineField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///������
	CNetObjectIDType	Name;
	///�豸�ͺ�
	CNetObjectIDType	SerialUsed;
	///�ļ�����
	CbaseCommentType	data;
	///��ע
	CNetAttrTypeType	memo;
	///������־
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

///���߱�
class CFTDRspQryNetBaseLineField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///������
	CNetObjectIDType	Name;
	///�豸�ͺ�
	CNetObjectIDType	SerialUsed;
	///�ļ�����
	CbaseCommentType	data;
	///��ע
	CNetAttrTypeType	memo;
	///������־
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

///���߱�
class CFTDRtnNetBaseLineField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///������
	CNetObjectIDType	Name;
	///�豸�ͺ�
	CNetObjectIDType	SerialUsed;
	///�ļ�����
	CbaseCommentType	data;
	///��ע
	CNetAttrTypeType	memo;
	///������־
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

///���������
class CFTDReqQryNetBaseLineTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CNetObjectIDType	Name;
	///����ID�б�
	CGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	CGeneralResultType	DeviceIDList;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///��ע
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

///���������
class CFTDRspQryNetBaseLineTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CNetObjectIDType	Name;
	///����ID�б�
	CGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	CGeneralResultType	DeviceIDList;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///��ע
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

///���������
class CFTDRtnNetBaseLineTaskField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///����������
	CNetObjectIDType	Name;
	///����ID�б�
	CGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	CGeneralResultType	DeviceIDList;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///��ע
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

///���߽����
class CFTDReqQryNetBaseLineResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CNetObjectIDType	BaseLineName;
	///�豸ObjID
	CNetObjectIDType	DeviceObjID;
	///�豸IP
	CIPAddressType	DeviceIP;
	///���߽��
	CFileCommentType	Result;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///������־
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

///���߽����
class CFTDRspQryNetBaseLineResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CNetObjectIDType	BaseLineName;
	///�豸ObjID
	CNetObjectIDType	DeviceObjID;
	///�豸IP
	CIPAddressType	DeviceIP;
	///���߽��
	CFileCommentType	Result;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///������־
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

///���߽����
class CFTDRtnNetBaseLineResultField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��������
	CNetObjectIDType	BaseLineName;
	///�豸ObjID
	CNetObjectIDType	DeviceObjID;
	///�豸IP
	CIPAddressType	DeviceIP;
	///���߽��
	CFileCommentType	Result;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///������־
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

///��Ա��·״̬��Ϣ��
class CFTDReqQryNetPartyLinkStatusInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///���ҷ�ʽ
	CCompareTypeType	KeyCompare;
	///��������
	CNetAttrTypeType	KeyName;
	///����ֵ
	CNetAttrTypeType	KeyValue;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ϯλ��
	CCfgNameType	SEAT_NO;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///��·״̬
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

///��Ա��·״̬��Ϣ��
class CFTDRspQryNetPartyLinkStatusInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ϯλ��
	CCfgNameType	SEAT_NO;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///��·״̬
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

///��Ա��·״̬��Ϣ��
class CFTDRtnNetPartyLinkStatusInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ϯλ��
	CCfgNameType	SEAT_NO;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///��·״̬
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

///��ԱSDH��·��ϸ��
class CFTDReqQryNetMemberSDHLineInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///��Ա��
	CPartyIDType	MemberNo;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///�ͻ�����
	CNetString128Type	ClientManager;
	///����
	CNetString128Type	Bandwidth;
	///�ӿ���
	CNetString128Type	InterfaceType;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��ע
	CNetString128Type	Remark;
	///A�˽����ַ
	CNetString512Type	EndALineAddress;
	///A����ϵ��
	CNetString128Type	EndAContact;
	///Z�˽����ַ
	CNetString512Type	EndZLineAddress;
	///��ϵ��
	CIndividualNameType	ContactName;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��ʼ�豸�˿�
	CNetString256Type	StartPortID;
	///��ʼ�豸���Ӷ�
	CNetString128Type	StartJump;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///�������Ĵ���
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

///��ԱSDH��·��ϸ��
class CFTDRspQryNetMemberSDHLineInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///��Ա��
	CPartyIDType	MemberNo;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///�ͻ�����
	CNetString128Type	ClientManager;
	///����
	CNetString128Type	Bandwidth;
	///�ӿ���
	CNetString128Type	InterfaceType;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��ע
	CNetString128Type	Remark;
	///A�˽����ַ
	CNetString512Type	EndALineAddress;
	///A����ϵ��
	CNetString128Type	EndAContact;
	///Z�˽����ַ
	CNetString512Type	EndZLineAddress;
	///��ϵ��
	CIndividualNameType	ContactName;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��ʼ�豸�˿�
	CNetString256Type	StartPortID;
	///��ʼ�豸���Ӷ�
	CNetString128Type	StartJump;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///�������Ĵ���
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

///��ԱSDH��·��ϸ��
class CFTDRtnNetMemberSDHLineInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///��Ա��
	CPartyIDType	MemberNo;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///�ͻ�����
	CNetString128Type	ClientManager;
	///����
	CNetString128Type	Bandwidth;
	///�ӿ���
	CNetString128Type	InterfaceType;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��ע
	CNetString128Type	Remark;
	///A�˽����ַ
	CNetString512Type	EndALineAddress;
	///A����ϵ��
	CNetString128Type	EndAContact;
	///Z�˽����ַ
	CNetString512Type	EndZLineAddress;
	///��ϵ��
	CIndividualNameType	ContactName;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��ʼ�豸�˿�
	CNetString256Type	StartPortID;
	///��ʼ�豸���Ӷ�
	CNetString128Type	StartJump;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///�������Ĵ���
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

///DDN��·��Ϣ��
class CFTDReqQryNetDDNLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
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

///DDN��·��Ϣ��
class CFTDRspQryNetDDNLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
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

///DDN��·��Ϣ��
class CFTDRtnNetDDNLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///�ͻ�����
	CPartyNameType	ClientName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
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

///�ǻ�Ա��·ʹ����Ϣ
class CFTDReqQryNetPseudMemberLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///��·��;
	CNetString128Type	LineUsage;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///ҵ��
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
	CIndividualNameType	EndZContactName;
	///�Ҷ˵绰����
	CTelephoneType	Telephone;
	///��·��Ϣ
	CTypeObjectIDType	LineInfo;
	///·��������IP
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

///�ǻ�Ա��·ʹ����Ϣ
class CFTDRspQryNetPseudMemberLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///��·��;
	CNetString128Type	LineUsage;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///ҵ��
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
	CIndividualNameType	EndZContactName;
	///�Ҷ˵绰����
	CTelephoneType	Telephone;
	///��·��Ϣ
	CTypeObjectIDType	LineInfo;
	///·��������IP
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

///�ǻ�Ա��·ʹ����Ϣ
class CFTDRtnNetPseudMemberLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///��·��;
	CNetString128Type	LineUsage;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///ҵ��
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
	CIndividualNameType	EndZContactName;
	///�Ҷ˵绰����
	CTelephoneType	Telephone;
	///��·��Ϣ
	CTypeObjectIDType	LineInfo;
	///·��������IP
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

///Զ���豸��Ϣ
class CFTDReqQryOuterDeviceInfField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP��ַ  
	CIPAddressType	IPADDR;
	///�豸���� 
	CNetObjectIDType	NAME;
	///��ע
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

///Զ���豸��Ϣ
class CFTDRspQryOuterDeviceInfField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP��ַ  
	CIPAddressType	IPADDR;
	///�豸���� 
	CNetObjectIDType	NAME;
	///��ע
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

///Զ���豸��Ϣ
class CFTDRtnNetOuterDeviceInfField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///IP��ַ  
	CIPAddressType	IPADDR;
	///�豸���� 
	CNetObjectIDType	NAME;
	///��ע
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

///����ping���
class CFTDReqQryNetLocalPingResultInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
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

///����ping���
class CFTDRspQryNetLocalPingResultInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
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

///����ping���
class CFTDRtnNetLocalPingResultInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
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

///Զ��ping���
class CFTDReqQryNetRomotePingResultInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
	CVolumeType	ConnRate;
	///��Сʱ��
	CNetString128Type	TimeDlyMin;
	///���ʱ��
	CNetString128Type	TimeDlyMax;
	///ƽ��ʱ��
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

///Զ��ping���
class CFTDRspQryNetRomotePingResultInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
	CVolumeType	ConnRate;
	///��Сʱ��
	CNetString128Type	TimeDlyMin;
	///���ʱ��
	CNetString128Type	TimeDlyMax;
	///ƽ��ʱ��
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

///Զ��ping���
class CFTDRtnNetRomotePingResultInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
	CVolumeType	ConnRate;
	///��Сʱ��
	CNetString128Type	TimeDlyMin;
	///���ʱ��
	CNetString128Type	TimeDlyMax;
	///ƽ��ʱ��
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
	///��������
	CTypeObjectIDType	HostName;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///��������
	CTypeCPUIdType	CPU;
	///�ն���
	CTypeChar10Type	TTY;
	///���̺�
	CVolumeType	PID;
	///�û���
	CTypeChar10Type	USERNAME;
	///��������ȼ�
	CVolumeType	PRI;
	///�����niceֵ
	CVolumeType	NI;
	///����Ĵ�����������ټ���ջ�ռ�Ĵ�С
	CVolumeType	SSIZE;
	///����ʹ�õ������ڴ��������
	CVolumeType	RES;
	///�����״̬
	CTypeChar10Type	STATE;
	///������ʼʱʹ�õ���CPUʱ��
	CTimeType	STIME;
	///���̵�CPU������Ȩ�ذٷֱ�
	CRatioType	pWCPU;
	///���̵�ԭʼ��CPU�����ʰٷֱ�
	CRatioType	pCPU;
	///�������̵�������
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

///ϵͳ�ڲ�������ϵ
class CFTDReqQrySysInternalTopologyField
{
public:
	///Я����Ϣ������
	CReportIDType	InfoType;
	///�ڵ�1��ID
	CNodeIDType	Node1_ID;
	///�ڵ�1����Ϣ
	CNodeInfoType	Node1_Info;
	///���ڵ�֮�����·��Ϣ
	CLinkInfoType	LinkInfo;
	///���ڵ�֮�����·״̬
	CLinkStateType	LinkState;
	///�ڵ�2��ID
	CNodeIDType	Node2_ID;
	///�ڵ�2����Ϣ
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

///ϵͳ�ڲ�������ϵ
class CFTDRspQrySysInternalTopologyField
{
public:
	///Я����Ϣ������
	CReportIDType	InfoType;
	///�ڵ�1��ID
	CNodeIDType	Node1_ID;
	///�ڵ�1����Ϣ
	CNodeInfoType	Node1_Info;
	///���ڵ�֮�����·��Ϣ
	CLinkInfoType	LinkInfo;
	///���ڵ�֮�����·״̬
	CLinkStateType	LinkState;
	///�ڵ�2��ID
	CNodeIDType	Node2_ID;
	///�ڵ�2����Ϣ
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

///ϵͳ�ڲ�������ϵ
class CFTDRtnSysInternalTopologyField
{
public:
	///Я����Ϣ������
	CReportIDType	InfoType;
	///�ڵ�1��ID
	CNodeIDType	Node1_ID;
	///�ڵ�1����Ϣ
	CNodeInfoType	Node1_Info;
	///���ڵ�֮�����·��Ϣ
	CLinkInfoType	LinkInfo;
	///���ڵ�֮�����·״̬
	CLinkStateType	LinkState;
	///�ڵ�2��ID
	CNodeIDType	Node2_ID;
	///�ڵ�2����Ϣ
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

///�����Ա��·���ñ�
class CFTDReqQryMemberLinkCostField
{
public:
	///ID
	CVolumeType	ID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///��������
	CCfgNameType	Pay_Date;
	///������ʼ����
	CCfgNameType	B_Pay_Date;
	///������ֹ����
	CCfgNameType	D_Pay_Date;
	///���
	CVolumeType	Charge;
	///��������
	CCfgNameType	Fee_Type;
	///��ע
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

///���ػ�Ա��·���ñ�
class CFTDRspQryMemberLinkCostField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///��������
	CCfgNameType	Pay_Date;
	///������ʼ����
	CCfgNameType	B_Pay_Date;
	///������ֹ����
	CCfgNameType	D_Pay_Date;
	///���
	CVolumeType	Charge;
	///��������
	CCfgNameType	Fee_Type;
	///��ע
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

///���Ļ�Ա��·���ñ�
class CFTDRtnMemberLinkCostField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///��������
	CCfgNameType	Pay_Date;
	///������ʼ����
	CCfgNameType	B_Pay_Date;
	///������ֹ����
	CCfgNameType	D_Pay_Date;
	///���
	CVolumeType	Charge;
	///��������
	CCfgNameType	Fee_Type;
	///��ע
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

///�����Ա��·�����
class CFTDReqQryNetPartylinkMonthlyRentField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��·����
	CParticipantNameType	LineName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///�������
	CLongVolumeType	MonthlyRental;
	///��ע
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

///���ػ�Ա��·�����
class CFTDRspQryNetPartylinkMonthlyRentField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��·����
	CParticipantNameType	LineName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///�������
	CLongVolumeType	MonthlyRental;
	///��ע
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

///���Ļ�Ա��·�����
class CFTDRtnNetPartylinkMonthlyRentField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��·����
	CParticipantNameType	LineName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///�������
	CLongVolumeType	MonthlyRental;
	///��ע
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

///����ǻ�Ա��·��Ϣ
class CFTDReqQryNetNonPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///���طǻ�Ա��·��Ϣ
class CFTDRspQryNetNonPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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

///���ķǻ�Ա��·��Ϣ
class CFTDRtnNetNonPartyLinkInfoField
{
public:
	///��������
	CVolumeType	OperationType;
	///ID
	CVolumeType	ID;
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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
	///ip��ַ
	CIPAddressType	IP;
	///����
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
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
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
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceType;
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///��λ
	CTypeObjectIDType	Unit;
	///�Ƿ������־
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
	///ʱ�����������
	CTypeObjectIDType	CName;
	///ʱ�����Ӣ����
	CTypeObjectIDType	EName;
	///��������
	CVolumeType	PolicyType;
	///���������ô�
	CPolicyStringTypeType	PolicyString;
	///����������
	CVolumeType	TradingDay;
	///����������
	CNetAttrTypeType	Description;
	///��������
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
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///������ָ������
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
	CVolumeType	PolicyTypeID;
	///��������
	CVolumeType	DataType;
	///���ͱ�ʶ
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
	///���������
	CTypeObjectIDType	CName;
	///���Ӣ����
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
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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
	///IP��ַ
	CIPAddressType	IPADDR;
	///��ͬ����
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
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
	CTypeObjectIDType	EName;
	///OID
	CTypeObjectIDType	OID;
	///��λ
	CTypeObjectIDType	Unit;
	///�Ƿ������־
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
	///�豸ID
	CVolumeType	NetDeviceID;
	///�豸�˿�ID
	CVolumeType	NetPortID;
	///��ض���
	CNetObjectIDType	NetObjectID;
	///��ض���˿�����
	CNetDevicePortTypeType	NetPortType;
	///�����豸ID
	CVolumeType	LinkNetDeviceID;
	///�����豸�˿�ID
	CVolumeType	LinkNetPortID;
	///���Ӷ���
	CNetObjectIDType	LinkNetObjectID;
	///���Ӷ���˿�����
	CNetDevicePortTypeType	LinkNetPortType;
	///������Դ
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
	///��ض���
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///����ID  
	CVolumeType	CATEGORY_ID;
	///��Ϊ���ֵ�ְ������  
	CTypeObjectIDType	FuctionArea;
	///IP��ַ  
	CIPAddressType	IPADDR;
	///IP��    
	CVolumeType	IPDECODE;
	///�豸���� 
	CNetObjectIDType	NAME;
	///             
	CVolumeType	PORTNUMBER;
	///          
	CTypeObjectIDType	CONFIGFILE;
	///��ͬ����  
	CTypeObjectIDType	RCOMMUNITY;
	///snmp�汾     
	CVolumeType	SNMPVERSION;
	///ramsize(B)   
	CVolumeType	RAMSIZE;
	///falshsize(B) 
	CVolumeType	FLASHSIZE;
	///nvramsize(B) 
	CVolumeType	NVRAMSIZE;
	///��������
	CVolumeType	CABINET_ID;
	///
	CVolumeType	ROOM_ID;
	///����汾
	CVolumeType	IOSVERSION_ID;
	///ϵͳ����
	CNetAttrTypeType	DESCRIPTION;
	///��¼�û���
	CTypeObjectIDType	USERNAME;
	///��¼����
	CNetAttrTypeType	PASSWD;
	///enable����
	CNetAttrTypeType	ENPASSWD;
	///��������
	CVolumeType	MANUFACTORY_ID;
	///���ñ���Э��
	CVolumeType	CFGSAVETYPE;
	///�豸�ͺ�
	CNetObjectIDType	DEVICETYPE;
	///�Ƿ���Ÿ澯
	CVolumeType	SENDSMS;
	///�Ƿ��Զ�snmp̽��
	CVolumeType	ISSNMP;
	///��λ��
	CVolumeType	SLOTNUM;
	///�Ƿ��Զ�ping
	CVolumeType	ISPING;
	///�˿�����
	CVolumeType	IFNUM;
	///Ѳ�����
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
	///��ض���
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�˿�����
	CVolumeType	IfType;
	///�˿���
	CTypeObjectIDType	EName;
	///IP��ַ
	CIPAddressType	IpAddress;
	///����
	CIPAddressType	IpMask;
	///�˿�״̬
	CVolumeType	IfStatus;
	///�����ַ
	CTypeObjectIDType	MAC;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///�����豸�˿�����
	CTypeObjectNameType	DeviceIndex;
	///�Ƿ���ѯ
	CVolumeType	isPolling;
	///����
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
	///OID������
	CTypeObjectIDType	CName;
	///OIDӢ����
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
	///ָ��������
	CNetAttrTypeType	CName;
	///ָ��Ӣ����
	CNetAttrTypeType	EName;
	///ע��
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
	///��������
	CVolumeType	MANUFACTORY_ID;
	///�豸���
	CVolumeType	MonitorType_ID;
	///������ָ��ID
	CVolumeType	AttrType_ID;
	///��������
	CTypeObjectIDType	MANUFACTORY;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///������ָ��
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
	///��ض���
	CNetObjectIDType	ObjectID;
	///������ָ��
	CNetAttrTypeType	AttrType;
	///ʱ�����ID
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
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
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
	///��������ID
	CVolumeType	Manufactory_ID;
	///�豸���ID
	CVolumeType	MonitorType_ID;
	///�豸�ͺ�ID
	CVolumeType	DeviceModle_ID;
	///������ID
	CVolumeType	ActionGroup_ID;
	///��������
	CTypeObjectIDType	Manufactory;
	///�豸���
	CTypeObjectIDType	MonitorType;
	///�豸�ͺ�
	CTypeObjectIDType	DeviceModle;
	///������
	CTypeObjectIDType	ActionGroup;
	///ָ����
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
	///������������
	CTypeObjectIDType	CName;
	///������Ӣ����
	CTypeObjectIDType	EName;
	///����������
	CVolumeType	ActionType;
	///ע��
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
	///�豸������������
	CTypeObjectIDType	CName;
	///�豸������Ӣ����
	CTypeObjectIDType	EName;
	///�豸��������
	CNetString512Type	Condition;
	///ע��
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
	///����������
	CTypeObjectIDType	CName;
	///����Ӣ����
	CTypeObjectIDType	EName;
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///������Ա������ID
	CVolumeType	ManagerGroup_ID;
	///����ʱ�����ID
	CVolumeType	TimePolicy_ID;
	///�������ȼ�ID
	CVolumeType	TaskPriority_ID;
	///����������ID
	CVolumeType	OutputPolicy_ID;
	///��������ID
	CVolumeType	ActionGroup_ID;
	///������ʽID���ϴ�
	CGeneralResultType	EventExprStr;
	///�豸������
	CTypeObjectIDType	DeviceGroup;
	///������Ա������
	CTypeObjectIDType	ManagerGroup;
	///����ʱ�����
	CTypeObjectIDType	TimePolicy;
	///�������ȼ�
	CTypeObjectIDType	TaskPriority;
	///����������
	CTypeObjectIDType	OutputPolicy;
	///��������
	CTypeObjectIDType	ActionGroup;
	///������Ч�Ա�ʶ
	CVolumeType	ValidFlag;
	///����״̬��ʶ
	CVolumeType	TaskStatus;
	///��������
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
	///�豸ID
	CVolumeType	DeviceID;
	///SysNetSubAreaID
	CVolumeType	SysNetSubAreaID;
	///�����ض���ID
	CNetObjectIDType	OldObjectID;
	///�����ض���ID
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
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///����ID
	CVolumeType	Task_ID;
	///ִ�д���
	CVolumeType	OperateTime;
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ָ�
	CNetString256Type	InstructChain;
	///�����
	CNetString1KType	ResultChain;
	///����ִ�б�ʶ
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
	///�豸������ID
	CVolumeType	DeviceGroup_ID;
	///�豸ID
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
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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
	///������ID
	CVolumeType	ActionGroup_ID;
	///��ض���ID
	CVolumeType	MonitorAttr_ID;
	///ָ��Ӣ����
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
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///��ض�������
	CVolumeType	MonitorType_ID;
	///�����豸ID
	CVolumeType	DeviceID;
	///�����豸ObjectID
	CNetObjectIDType	DeviceObjectID;
	///����
	CTypeObjectIDType	Name;
	///����
	CNetObjectIDType	Description;
	///ģ������
	CVolumeType	ModuleIndex;
	///��������
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
	///�����¼���
	CNetObjectIDType	CNAME;
	///Ӣ���¼���
	CNetObjectIDType	ENAME;
	///�¼�����
	CCfgNameType	WarningLEVEL;
	///�¼�����
	CVolumeType	EventTypeID;
	///�¼�������
	CVolumeType	SubEventTypeID;
	///�澯���ʱ��
	CVolumeType	GIVEUPTIME;
	///���ƶ�����
	CGeneralResultType	CONTROL;
	///���ʽ������
	CGeneralResultType	EXPR;
	///�¼�����
	CTypeObjectIDType	BRIEF;
	///�¼�������
	CNetAttrTypeType	DISCRIPTION;
	///��Ϣ��ID
	CVolumeType	MSGGROUP_ID;
	///����Ա��ID
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
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
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
	///�¼�������������
	CTypeObjectIDType	CName;
	///�¼�������Ӣ����
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
	///�¼�����������
	CTypeObjectIDType	CName;
	///�¼�����Ӣ����
	CTypeObjectIDType	EName;
	///�¼�����������
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
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ��
	CNetString256Type	InstructChain;
	///ָ�����
	CNetString128Type	InstructAlias;
	///ָ�������
	CNetString256Type	InstructArgs;
	///ָ�귧ֵ��
	CNetString2KType	DefParamChain;
	///������־
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
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ�����
	CNetString128Type	InstructAlias;
	///�豸�ͺ�
	CNetString128Type	DEVICETYPE;
	///ָ�괮
	CNetString256Type	AttrsChain;
	///ָ�����
	CNetString512Type	DefRegularChain;
	///ָ�귧ֵ��
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
	///��������
	CVolumeType	MANUFACTORY_ID;
	///������
	CNetObjectIDType	Name;
	///�豸�ͺ�
	CNetObjectIDType	SerialUsed;
	///�ļ�����
	CbaseCommentType	data;
	///��ע
	CNetAttrTypeType	memo;
	///������־
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
	///����������
	CNetObjectIDType	Name;
	///����ID�б�
	CGeneralResultType	BaseLineIDList;
	///�豸ID�б�
	CGeneralResultType	DeviceIDList;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///��ע
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
	///��������
	CNetObjectIDType	BaseLineName;
	///�豸ObjID
	CNetObjectIDType	DeviceObjID;
	///�豸IP
	CIPAddressType	DeviceIP;
	///���߽��
	CFileCommentType	Result;
	///��������
	CDateType	GenDate;
	///����ʱ��
	CTimeType	GenTime;
	///������
	CTypeUserNameType	GenUser;
	///������־
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
	///�ɼ�������
	CDateType	MonDate;
	///�ɼ���ʱ��
	CTimeType	MonTime;
	///ϯλ��
	CCfgNameType	SEAT_NO;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///��·״̬
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
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///��Ա��
	CPartyIDType	MemberNo;
	///��Ա����
	CParticipantNameType	ParticipantName;
	///�ͻ�����
	CNetString128Type	ClientManager;
	///����
	CNetString128Type	Bandwidth;
	///�ӿ���
	CNetString128Type	InterfaceType;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��ע
	CNetString128Type	Remark;
	///A�˽����ַ
	CNetString512Type	EndALineAddress;
	///A����ϵ��
	CNetString128Type	EndAContact;
	///Z�˽����ַ
	CNetString512Type	EndZLineAddress;
	///��ϵ��
	CIndividualNameType	ContactName;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��ʼ�豸�˿�
	CNetString256Type	StartPortID;
	///��ʼ�豸���Ӷ�
	CNetString128Type	StartJump;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///�������Ĵ���
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
	///�ͻ�����
	CPartyNameType	ClientName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///ҵ��Ԫ
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
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
	///���к�
	CVolumeType	SeqNo;
	///��ͬ��
	CContractSeqNoType	MemContractNo;
	///��·��;
	CNetString128Type	LineUsage;
	///���ص�·����
	CNetString128Type	LocalCircuit;
	///��;��·����
	CNetString128Type	RemoteCircuit;
	///ҵ��
	CBusinessUnitType	BusinessUnit;
	///����
	CNetString128Type	Bandwidth;
	///������
	CApplyPersonType	ApplyPerson;
	///�������
	CLongVolumeType	MonthlyRental;
	///�׶˵�ַ
	CAddressType	EndAAddress;
	///�׶���ϵ��
	CIndividualNameType	EndAContactName;
	///�Ҷ˵�ַ
	CAddressType	EndZAddress;
	///�Ҷ���ϵ��
	CIndividualNameType	EndZContactName;
	///�Ҷ˵绰����
	CTelephoneType	Telephone;
	///��·��Ϣ
	CTypeObjectIDType	LineInfo;
	///·��������IP
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
	///�����ض���ID
	CNetObjectIDType	ObjectID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///�����豸����ID
	CVolumeType	Manufactory_ID;
	///ָ��
	CNetString256Type	InstructChain;
	///ָ�����
	CNetString128Type	InstructAlias;
	///ָ�������
	CNetString256Type	InstructArgs;
	///ָ�귧ֵ��
	CNetString2KType	DefParamChain;
	///������־
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
	///IP��ַ  
	CIPAddressType	IPADDR;
	///�豸���� 
	CNetObjectIDType	NAME;
	///��ע
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
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
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
	///ԴIP��ַ  
	CIPAddressType	SouIPADDR;
	///Դ�豸���� 
	CNetObjectIDType	SouNAME;
	///Ŀ��IP��ַ  
	CIPAddressType	TarIPADDR;
	///Ŀ���豸���� 
	CNetObjectIDType	TarNAME;
	///��������
	CDateType	PDateSta;
	///ʱ���
	CTimeType	PTimeSta;
	///��ͨ��
	CVolumeType	ConnRate;
	///��Сʱ��
	CNetString128Type	TimeDlyMin;
	///���ʱ��
	CNetString128Type	TimeDlyMax;
	///ƽ��ʱ��
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
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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
	///���ǰ��ַ
	CNetAttrTypeType	OLDADDRESS;
	///������ַ
	CNetAttrTypeType	NEWADDRESS;
	///������
	CCfgNameType	OPERATOR;
	///�޸�����
	CDateType	MonDate;
	///�޸�ʱ��
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
	///Я����Ϣ������
	CReportIDType	InfoType;
	///�ڵ�1��ID
	CNodeIDType	Node1_ID;
	///�ڵ�1����Ϣ
	CNodeInfoType	Node1_Info;
	///���ڵ�֮�����·��Ϣ
	CLinkInfoType	LinkInfo;
	///���ڵ�֮�����·״̬
	CLinkStateType	LinkState;
	///�ڵ�2��ID
	CNodeIDType	Node2_ID;
	///�ڵ�2����Ϣ
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
	///��Ա����
	CParticipantNameType	ParticipantName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///��������
	CCfgNameType	Pay_Date;
	///������ʼ����
	CCfgNameType	B_Pay_Date;
	///������ֹ����
	CCfgNameType	D_Pay_Date;
	///���
	CVolumeType	Charge;
	///��������
	CCfgNameType	Fee_Type;
	///��ע
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
	///��·����
	CParticipantNameType	LineName;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///��Ӫ��
	CCfgNameType	ServiceProvider;
	///�������
	CLongVolumeType	MonthlyRental;
	///��ע
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
	///��Ա��
	CCfgNameType	MEMBER_NO;
	///��Ա����
	CTypeObjectIDType	MEMBER_NAME;
	///��Ա����ص�
	CTypeObjectIDType	REMOTE_ADDR;
	///�����������
	CTypeObjectIDType	LOCAL_ADDR;
	///��ַ
	CNetAttrTypeType	ADDRESS;
	///��·״̬
	CCfgNameType	LINE_STATUS;
	///��ϵ��
	CCfgNameType	CONTACT;
	///��ϵ�绰
	CTypeObjectIDType	TELEPHONE;
	///�ֻ���
	CTypeObjectIDType	MOBILEPHONE;
	///EMAIL
	CTypeObjectIDType	EMAIL;
	///����
	CTypeObjectIDType	FAX;
	///����ʡ��
	CCfgNameType	PROVINCE;
	///��·���
	CTypeObjectIDType	DDN_NO;
	///���뷽ʽ
	CTypeObjectIDType	IN_MODE;
	///����IP����
	CTypeObjectIDType	IP_WAN;
	///����IP����
	CTypeObjectIDType	IP_LAN;
	///·��������IP
	CTypeObjectIDType	IPADDR;
	///·�����˿ں�
	CTypeObjectIDType	Interface;
	///�ӿڿ�ͨ����
	CCfgNameType	INTERFACE_DATE;
	///�������
	CCfgNameType	SOFTWARE;
	///��������
	CCfgNameType	FEE_TYPE;
	///��Ӫ��
	CCfgNameType	SERVICEPROVIDER;
	///�Ƿ���Ӫ
	CCfgNameType	IF_ZIYING;
	///�Ƿ��й�
	CCfgNameType	IF_TUOGUAN;
	///����������·
	CCfgNameType	HASOTHER;
	///ϯλ��
	CGeneralResultType	SEAT_NO;
	///��ע
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
