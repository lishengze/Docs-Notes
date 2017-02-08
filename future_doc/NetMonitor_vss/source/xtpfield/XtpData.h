// XtpData.h: 
//
///20090118	���ض�		�����˲�ѯ����־��NT-0065��
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XTPDATA_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_)
#define AFX_XTPDATA_H__EA501ADE_818C_4F9A_8738_AC9CCAF0B941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FieldDescribe.h"
#include "customDataType.h"

///�û���¼
class CUserLoginField
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
	///��¼�ɹ�ʱ��
	CTimeType	LoginTime;
	///IP��ַ
	CIPAddressType	IPAddress;
	///��󱨵����ر��
	COrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	CTradingSystemNameType	TradingSystemName;
	///�û�����
	CUserTypeType	UserType;
	///���ͨѶ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserLogin=0x0001;

///��Ӧ��Ϣ
class CRspInfoField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspInfo=0x0003;

///ͨѶ�׶�
class CCommPhaseField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CommPhase=0x0004;

///������������
class CExchangeTradingDayField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExchangeTradingDay=0x0005;

///����Ự
class CSettlementSessionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SettlementSession=0x0006;

///��ǰʱ��
class CCurrentTimeField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrentTime=0x0007;

///������������
class CDataCenterDescField
{
public:
	///�������Ĵ���
	CDataCenterIDType	DataCenterID;
	///����ģʽ
	CStartModeType	StartMode;
	TYPE_DESCRIPTOR((
		TYPE_DESC(DataCenterID)
		,
		TYPE_DESC(StartMode)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DataCenterDesc=0x0008;

///���뱨��
class CInputOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputOrder=0x0011;

///��������
class COrderActionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_OrderAction=0x0012;

///OTC����
class COTCOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_OTCOrder=0x0013;

///���뱨��
class CInputQuoteField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputQuote=0x0021;

///���۲���
class CQuoteActionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QuoteAction=0x0022;

///����ִ������
class CInputExecOrderField
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
	///ҵ��Ԫ
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputExecOrder=0x0023;

///ִ���������
class CExecOrderActionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExecOrderAction=0x0024;

///�û���¼�˳�
class CUserLogoutField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserLogout=0x0031;

///�û������޸�
class CUserPasswordUpdateField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserPasswordUpdate=0x0032;

///�û���¼��Ϣ
class CLoginInfoField
{
public:
	///������
	CDateType	TradingDay;
	///���
	CSequenceNoType	SequenceNo;
	///�����û�����
	CUserIDType	UserID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�û��˲�Ʒ��Ϣ
	CProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	CProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	CProtocolInfoType	ProtocolInfo;
	///IP��ַ
	CIPAddressType	IPAddress;
	///��¼����
	CLoginTypeType	LoginType;
	///�Ự����
	CSessionTypeType	SessionType;
	///�������
	CErrorIDType	ErrorID;
	///��������
	CDateType	UpdateDate;
	///����ʱ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_LoginInfo=0x0033;

///������ϱ���
class CInputCombOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputCombOrder=0x0041;

///ǿ���û��˳�
class CForceUserExitField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ForceUserExit=0x0053;

///������ѯ
class CQryOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryOrder=0x3001;

///���۲�ѯ
class CQryQuoteField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryQuote=0x3002;

///�ɽ���ѯ
class CQryTradeField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryTrade=0x3003;

///�����ѯ
class CQryMarketDataField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryMarketData=0x3004;

///�ͻ���ѯ
class CQryClientField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryClient=0x3006;

///��Ա�ֲֲ�ѯ
class CQryPartPositionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryPartPosition=0x3007;

///�ͻ��ֲֲ�ѯ
class CQryClientPositionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryClientPosition=0x3008;

///�����ʽ��ѯ
class CQryPartAccountField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryPartAccount=0x3009;

///��Լ��ѯ
class CQryInstrumentField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryInstrument=0x300A;

///��Լ״̬��ѯ
class CQryInstrumentStatusField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryInstrumentStatus=0x300B;

///������״̬��ѯ
class CQrySGDataSyncStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QrySGDataSyncStatus=0x300C;

///�û����߲�ѯ
class CQryUserSessionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryUserSession=0x300D;

///�û���ѯ
class CQryUserField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryUser=0x300E;

///�����ѯ
class CQryBulletinField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryBulletin=0x300F;

///��Ա��ѯ
class CQryParticipantField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryParticipant=0x3010;

///��ֵ��Ȳ�ѯ
class CQryHedgeVolumeField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryHedgeVolume=0x3011;

///������״̬��ѯ
class CQryExchangeStatusField
{
public:
	///����������
	CExchangeIDType	ExchangeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryExchangeStatus=0x3012;

///������״̬��ѯ
class CQrySettlementGroupStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QrySettlementGroupStatus=0x3013;

///��Լ��λ��ѯ
class CQryMBLMarketDataField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryMBLMarketData=0x3014;

///����������ͬ��״̬��ѯ
class CQryExchangeDataSyncStatusField
{
public:
	///����������
	CExchangeIDType	ExchangeID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryExchangeDataSyncStatus=0x3015;

///��ϱ�����ѯ
class CQryCombOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryCombOrder=0x3006;

///��Ա�ʽ�Ӧ��
class CRspPartAccountField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspPartAccount=0x3101;

///��Ա�ֲ�Ӧ��
class CRspPartPositionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspPartPosition=0x3102;

///�ͻ��ֲ�Ӧ��
class CRspClientPositionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspClientPosition=0x3103;

///��Լ��ѯӦ��
class CRspInstrumentField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspInstrument=0x3104;

///��Ϣ��ѯ
class CQryInformationField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryInformation=0x3105;

///��Ϣ��ѯ
class CInformationField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Information=0x3106;

///�����޶��ѯ
class CQryCreditLimitField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_QryCreditLimit=0x3108;

///�����޶�
class CCreditLimitField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CreditLimit=0x310A;

///�ͻ���ѯӦ��
class CRspClientField
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
	///��Ա��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RspClient=0x310B;

///������
class CExchangeField
{
public:
	///����������
	CExchangeIDType	ExchangeID;
	///����������
	CExchangeNameType	ExchangeName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ExchangeName)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Exchange=0x1101;

///������
class CSettlementGroupField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///����������
	CSettlementGroupNameType	SettlementGroupName;
	///����������
	CExchangeIDType	ExchangeID;
	///����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SettlementGroup=0x1102;

///�г�
class CMarketField
{
public:
	///�г�����
	CMarketIDType	MarketID;
	///�г�����
	CMarketNameType	MarketName;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(MarketName)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Market=0x1201;

///�г���Ʒ����
class CMarketProductField
{
public:
	///�г�����
	CMarketIDType	MarketID;
	///��Ʒ����
	CProductIDType	ProductID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(ProductID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketProduct=0x1202;

///�г���Ʒ�����
class CMarketProductGroupField
{
public:
	///�г�����
	CMarketIDType	MarketID;
	///��Ʒ�����
	CProductGroupIDType	ProductGroupID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(MarketID)
		,
		TYPE_DESC(ProductGroupID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketProductGroup=0x1203;

///��������
class CMarketDataTopicField
{
public:
	///�������
	CTopicIDType	TopicID;
	///��������
	CTopicNameType	TopicName;
	///�г�����
	CMarketIDType	MarketID;
	///����Ƶ��
	CSecondsType	SnapShotFeq;
	///�г��������
	CMarketDataDepthType	MarketDataDepth;
	///�ӳ�����
	CSecondsType	DelaySeconds;
	///����ģʽ
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataTopic=0x1204;

///��Ա�����г�
class CPartTopicSubscribeField
{
public:
	///�����ߴ���
	CParticipantIDType	ParticipantID;
	///����������
	CParticipantTypeType	ParticipantType;
	///�������
	CTopicIDType	TopicID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(ParticipantType)
		,
		TYPE_DESC(TopicID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartTopicSubscribe=0x1205;

///��Ա
class CParticipantField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Participant=0x1401;

///�û�
class CUserField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_User=0x1402;

///�ͻ�
class CClientField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Client=0x1403;

///��Ա�ͻ���ϵ
class CPartClientField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ParticipantID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartClient=0x1404;

///�û�IP
class CUserIPField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///IP��ַ����
	CIPAddressType	IPMask;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(IPMask)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserIP=0x1405;

///�û��Ự
class CUserSessionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserSession=0x1406;

///���鷢��״̬
class CMdPubStatusField
{
public:
	///��Ʒ����
	CProductIDType	ProductID;
	///��Լ����״̬
	CInstrumentStatusType	InstrumentStatus;
	///���鷢��״̬
	CMdPubStatusType	MdPubStatus;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(MdPubStatus)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MdPubStatus=0x1407;

///���㽻�׻�Ա��ϵ
class CClearingTradingPartField
{
public:
	///�����Ա
	CParticipantIDType	ClearingPartID;
	///���׻�Ա
	CParticipantIDType	ParticipantID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(ClearingPartID)
		,
		TYPE_DESC(ParticipantID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClearingTradingPart=0x1408;

///�û�����Ȩ��
class CUserFunctionRightField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///���ܴ���
	CFunctionCodeType	FunctionCode;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(FunctionCode)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserFunctionRight=0x1409;

///�ʽ��˻�
class CAccountField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�ʽ��ʺ�
	CAccountIDType	AccountID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Account=0x140A;

///�û�ͨѶ��
class CUserCommFluxField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///���ͨѶ��
	CCommFluxType	MaxCommFlux;
	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(MaxCommFlux)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UserCommFlux=0x140B;

///��Ʒ��
class CProductGroupField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ProductGroup=0x2101;

///��Ʒ
class CProductField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Product=0x2102;

///��Լ
class CInstrumentField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Instrument=0x2103;

///��Ͻ��׺�Լ�ĵ���
class CCombinationLegField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CombinationLeg=0x2104;

///��Ա�˻���ϵ
class CPartRoleAccountField
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
	///���׽�ɫ
	CTradingRoleType	TradingRole;
	///�ʽ��ʺ�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartRoleAccount=0x2105;

///��Ա��Ʒ��ɫ
class CPartProductRoleField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///��Ʒ����
	CProductIDType	ProductID;
	///���׽�ɫ
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartProductRole=0x2201;

///��Ա��Ʒ����Ȩ��
class CPartProductRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///����Ȩ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartProductRight=0x2202;

///��Ա��Լ����Ȩ��
class CPartInstrumentRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///����Ȩ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartInstrumentRight=0x2203;

///�ͻ���Ʒ����Ȩ��
class CClientProductRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClientProductRight=0x2204;

///�ͻ���Լ����Ȩ��
class CClientInstrumentRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClientInstrumentRight=0x2205;

///��Ա�ͻ���Ʒ����Ȩ��
class CPartClientProductRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartClientProductRight=0x2206;

///��Ա�ͻ���Լ����Ȩ��
class CPartClientInstrumentRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartClientInstrumentRight=0x2207;

///��Ʒ����
class CCurrProductPropertyField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ʒ��������״̬
	CProductLifePhaseType	ProductLifePhase;
	///����ģʽ
	CTradingModelType	TradingModel;
	///��Ȩ�޲�ϵ��
	CRatioType	OptionsLimitRatio;
	///��Ȩ��֤�����ϵ��
	CRatioType	OptionsMgRatio;
	///����ȡ��ʱ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrProductProperty=0x2301;

///��Լ����
class CCurrInstrumentPropertyField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
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
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Լ��������״̬
	CInstLifePhaseType	InstLifePhase;
	///�Ƿ��׽�����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrInstrumentProperty=0x2303;

///��ǰ��Լ�۸��
class CCurrPriceBandingField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޼�����
	CPriceLimitTypeType	PriceLimitType;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///���뷽ʽ
	CRoundingModeType	RoundingMode;
	///����
	CPriceType	UpperValue;
	///����
	CPriceType	LowerValue;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///���׽׶α��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrPriceBanding=0x2304;

///��ǰ��Լ��֤����
class CCurrMarginRateField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��֤���㷨����
	CMarginCalcIDType	MarginCalcID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrMarginRate=0x2305;

///��ǰ��Լ��֤���ʵ���ϸ����
class CCurrMarginRateDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
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
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrMarginRateDetail=0x2306;

///��ǰ��Ա��Լ�޲�
class CCurrPartPosiLimitField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ա�޲��㷨����
	CPartPosiLimitCalcIDType	PartPosiLimitCalcID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrPartPosiLimit=0x2307;

///��ǰ��Ա��Լ�޲ֵ���ϸ����
class CCurrPartPosiLimitDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrPartPosiLimitDetail=0x2308;

///��ǰ�ͻ���Լ�޲�
class CCurrClientPosiLimitField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�ͻ��޲��㷨����
	CClientPosiLimitCalcIDType	ClientPosiLimitCalcID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	TYPE_DESCRIPTOR((
		TYPE_DESC(SettlementGroupID)
		,
		TYPE_DESC(ClientPosiLimitCalcID)
		,
		TYPE_DESC(InstrumentID)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrClientPosiLimit=0x2309;

///��ǰ�ͻ���Լ�޲ֵ���ϸ����
class CCurrClientPosiLimitDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrClientPosiLimitDetail=0x230A;

///��ǰ����ͻ���Լ�޲�
class CCurrSpecialPosiLimitField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�ͻ��޲��㷨����
	CClientPosiLimitCalcIDType	ClientPosiLimitCalcID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrSpecialPosiLimit=0x230B;

///��ǰ����ͻ���Լ�޲ֵ���ϸ����
class CCurrSpecialPosiLimitDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrSpecialPosiLimitDetail=0x230C;

///��ǰ��Լ���ڱ�ֵ����
class CCurrHedgeRuleField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///�ױ����ʹ������
	CHedgeUsageTypeType	HedgeUsageType;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ױ����ƽ�������
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrHedgeRule=0x230D;

///��ǰ��Լ���׽׶�����
class CCurrTradingSegmentAttrField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrTradingSegmentAttr=0x230E;

///��ǰ��Լ�۶�����
class CCurrFuseField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޼�����
	CPriceLimitTypeType	PriceLimitType;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///���뷽ʽ
	CRoundingModeType	RoundingMode;
	///����
	CPriceType	UpperValue;
	///����
	CPriceType	LowerValue;
	///ͣ�����ʱ��
	CDurationType	PriceLimitDuration;
	///�۶���
	CDurationType	FuseDuration;
	///�۶����Ƿ���
	CBoolType	TradingFlag;
	///�������۶�ʱ��
	CTimeType	NoFuseTime;
	///��Լ����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrFuse=0x230F;

///�����˻��ʽ���Ϣ
class CTradingAccountField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_TradingAccount=0x2401;

///��Ա��Լ�ֲ�
class CPartPositionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_PartPosition=0x2402;

///�ͻ���Լ�ֲ�
class CClientPositionField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ClientPosition=0x2403;

///��ֵ�����
class CHedgeVolumeField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_HedgeVolume=0x2404;

///������������
class CRemainOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_RemainOrder=0x2405;

///�г�����
class CMarketDataField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketData=0x2407;

///�������
class CDepthMarketDataField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DepthMarketData=0x2409;

///�ּ۱�
class CMBLMarketDataField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MBLMarketData=0x2410;

///��������
class CAliasDefineField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_AliasDefine=0x2411;

///�����������
class CMarketDataBaseField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBase=0x2431;

///���龲̬����
class CMarketDataStaticField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataStatic=0x2432;

///�������³ɽ�����
class CMarketDataLastMatchField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataLastMatch=0x2433;

///�������ż�����
class CMarketDataBestPriceField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBestPrice=0x2434;

///�����������������
class CMarketDataBid23Field
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBid23=0x2435;

///������������������
class CMarketDataAsk23Field
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataAsk23=0x2436;

///���������ġ�������
class CMarketDataBid45Field
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataBid45=0x2437;

///���������ġ�������
class CMarketDataAsk45Field
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataAsk45=0x2438;

///�������ʱ������
class CMarketDataUpdateTimeField
{
public:
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	CTimeType	UpdateTime;
	///����޸ĺ���
	CMillisecType	UpdateMillisec;
	TYPE_DESCRIPTOR((
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_MarketDataUpdateTime=0x2439;

///����׼�����˻�
class CBaseReserveAccountField
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
	///�ʽ��ʺ�
	CAccountIDType	AccountID;
	///����׼����
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_BaseReserveAccount=0x243A;

///Dbmt��Ա�ʽ��ʻ����
class CDbmtAccountDepositField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�ʽ��˺�
	CAccountIDType	Account;
	///�����
	CMoneyType	Deposit;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtAccountDeposit=0x2800;

///Dbmt�ͻ�
class CDbmtClientField
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
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtClient=0x2801;

///Dbmt��Ա�ͻ�
class CDbmtPartClientField
{
public:
	///�ͻ�����
	CClientIDType	ClientID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartClient=0x2802;

///Dbmt��Ա��Լ�ֲ��޶�
class CDbmtCurrPartPosiLimitDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///���׽�ɫ
	CPositionTradingRoleType	TradingRole;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrPartPosiLimitDetail=0x2803;

///Dbmt�ͻ���Լ�ֲ��޶�
class CDbmtCurrClientPosiLimitDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientTypeType	ClientType;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrClientPosiLimitDetail=0x2804;

///Dbmt����ͻ���Լ�ֲ��޶�
class CDbmtCurrSpecialPosiLimitDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޲����
	CLargeVolumeType	StartTotalPosition;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///��ͷ�޲�
	CRatioType	LongPosLimit;
	///��ͷ�޲�
	CRatioType	ShortPosLimit;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrSpecialPosiLimitDetail=0x2805;

///Dbmt��ֵ�����ϸ
class CDbmtHedgeDetailField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///��ˮ��
	CSerialNoType	HedgeQuotaSN;
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
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtHedgeDetail=0x2806;

///Dbmt�û�
class CDbmtUserField
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
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtUser=0x2807;

///Dbmt��Ա��ƷȨ��
class CDbmtPartProductRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///����Ȩ��
	CTradingRightType	TradingRight;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartProductRight=0x2808;

///Dbmt�ͻ���ƷȨ��
class CDbmtClientProductRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
	CTradingRightType	TradingRight;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtClientProductRight=0x2809;

///Dbmt��Ա��ԼȨ��
class CDbmtPartInstrumentRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///����Ȩ��
	CTradingRightType	TradingRight;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartInstrumentRight=0x280A;

///Dbmt�ͻ���ԼȨ��
class CDbmtClientInstrumentRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
	CTradingRightType	TradingRight;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtClientInstrumentRight=0x280B;

///Dbmt��Ա�ͻ���ƷȨ��
class CDbmtPartClientProductRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Ʒ����
	CProductIDType	ProductID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
	CTradingRightType	TradingRight;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartClientProductRight=0x2812;

///Dbmt��Ա�ͻ���ԼȨ��
class CDbmtPartClientInstrumentRightField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///����Ȩ��
	CTradingRightType	TradingRight;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartClientInstrumentRight=0x2813;

///Dbmt��Ա��Լ��֤����
class CDbmtCurrMarginRateDetailField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
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
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrMarginRateDetail=0x280C;

///Dbmt����
class CDbmtMarketDataField
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
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtMarketData=0x280D;

///Dbmt�û�IP��ַ
class CDbmtUserIPField
{
public:
	///�����û�����
	CUserIDType	UserID;
	///IP��ַ
	CIPAddressType	IPAddress;
	///IP��ַ����
	CIPAddressType	IPMask;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtUserIP=0x280E;

///Dbmt�۸��
class CDbmtCurrPriceBandingField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///�޼�����
	CPriceLimitTypeType	PriceLimitType;
	///ȡֵ��ʽ
	CValueModeType	ValueMode;
	///���뷽ʽ
	CRoundingModeType	RoundingMode;
	///����
	CPriceType	UpperValue;
	///����
	CPriceType	LowerValue;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///���׽׶α��
	CTradingSegmentSNType	TradingSegmentSN;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrPriceBanding=0x280F;

///Dbmt�������к�Լ״̬
class CDbmtUpdateAllInstrumentStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ״̬
	CInstrumentStatusType	InstrumentStatus;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtUpdateAllInstrumentStatus=0x2810;

///Dbmt��Ա�����г�
class CDbmtPartTopicSubscribeField
{
public:
	///�����ߴ���
	CParticipantIDType	ParticipantID;
	///����������
	CParticipantTypeType	ParticipantType;
	///�������
	CTopicIDType	TopicID;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtPartTopicSubscribe=0x2811;

///Dbmt��ǰ��ֵ���
class CDbmtCurrHedgeField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///��ˮ��
	CSerialNoType	HedgeQuotaSN;
	///�û�����
	COperatorIDType	OperatorID;
	///ʱ��
	CTimeType	Time;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///�ֲֶ�շ���
	CPosiDirectionType	PosiDirection;
	///��ǰ��ֵ���
	CVolumeType	CurrVolume;
	///��Ա����
	CParticipantIDType	ParticipantID;
	///�ͻ�����
	CClientIDType	ClientID;
	///Dbmt�����
	CDbmtTopicIDType	DbmtTopicID;
	///Dbmt���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DbmtCurrHedge=0x2815;

///����
class CQuoteField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Quote=0x2506;

///�ɽ�
class CTradeField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Trade=0x2507;

///����
class COrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Order=0x2508;

///ִ������
class CExecOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExecOrder=0x2509;

///��ϱ���
class CCombOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CombOrder=0x250A;

///������
class CAdminOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_AdminOrder=0x2510;

///����������
class CInputAdminOrderField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InputAdminOrder=0x2511;

///����
class CBulletinField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_Bulletin=0x2607;

///����������ͬ��״̬
class CExchangeDataSyncStatusField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExchangeDataSyncStatus=0x2701;

///����������ͬ��״̬
class CSGDataSyncStatusField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SGDataSyncStatus=0x2702;

///��Լ״̬
class CInstrumentStatusField
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InstrumentStatus=0x2703;

///��Լ����״̬��ˮ
class CInstrumentStatusDetailField
{
public:
	///������
	CDateType	TradingDay;
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
	///������
	CSettlementIDType	SettlementID;
	///���к�
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_InstrumentStatusDetail=0x2704;

///ǰ��״̬
class CFrontStatusField
{
public:
	///ǰ�ñ��
	CFrontIDType	FrontID;
	///�ϴα���ʱ��
	CTimeType	LastReportTime;
	///�Ƿ��Ծ
	CBoolType	IsActive;
	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(LastReportTime)
		,
		TYPE_DESC(IsActive)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_FrontStatus=0x2705;

///������״̬
class CExchangeStatusField
{
public:
	///������
	CDateType	TradingDay;
	///����������
	CExchangeIDType	ExchangeID;
	///������״̬
	CExchangeStatusType	ExchangeStatus;
	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ExchangeStatus)
	));
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_ExchangeStatus=0x2708;

///������״̬
class CSettlementGroupStatusField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CDateType	TradingDay;
	///������
	CSettlementIDType	SettlementID;
	///������״̬
	CSettlementGroupStatusType	SettlementGroupStatus;
	///���뱾״̬ʱ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_SettlementGroupStatus=0x2709;

///���������
class CUniPressureField
{
public:
	///������
	CDateType	TradingDay;
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///������
	CSettlementIDType	SettlementID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///��ѹ����ʼʱ��
	CTimeType	UpperPressureStartTime;
	///��ѹ����ʼʱ��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_UniPressure=0x2710;

///���������ˮ
class CDepthMarketDataDetailField
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
	///���
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_DepthMarketDataDetail=0x2711;

///�����ڻ���Լ��Ȩ����
class CCurrInstrumentOptionField
{
public:
	///���������
	CSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	CInstrumentIDType	InstrumentID;
	///ͬ�����Ȩ�ĺϲ��ֱֲ���
	CRatioType	OptPostLimitRatio;
	///�ڻ���ͬ�����Ȩ�ĺϲ��ֱֲ���
	CRatioType	UniPostLimitRatio;
	///��λ���֣���Ȩ��Լ��С��֤��
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
	
	///����field�����buffer�У�buffer����Ϊlen��������Ȳ����������þ��������ԭ��
	///@param	buffer	Ҫ���ý���Ļ�����
	///@param	len	�������ĳ���
	///@return	true��ʾȫ���ųɹ���false��ʾû��ȫ���ųɹ���
	bool dumpLine(char *buffer, int len);
};
const DWORD FID_CurrInstrumentOption=0x2712;




#endif
