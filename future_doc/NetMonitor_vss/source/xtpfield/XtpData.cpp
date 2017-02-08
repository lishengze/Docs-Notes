// XtpData.cpp: 
//
///20090118	王肇东		增加了查询的日志（NT-0065）
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "XtpData.h"
#include "XtpPackageDesc.h"

/*** 应用业务FieldID ***/
REGISTER_FIELD(FID_UserLogin, CUserLoginField, "用户登录");

bool CUserLoginField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=9;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UserLogin");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Password.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Password,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserProductInfo.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserProductInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InterfaceProductInfo.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InterfaceProductInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProtocolInfo.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProtocolInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DataCenterID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DataCenterID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LoginTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LoginTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IPAddress.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IPAddress,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MaxOrderLocalID.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MaxOrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingSystemName.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingSystemName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserType.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MaxCommFlux.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MaxCommFlux,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_RspInfo, CRspInfoField, "响应信息");

bool CRspInfoField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=7;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"RspInfo");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ErrorID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ErrorID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ErrorMsg.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ErrorMsg,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CommPhase, CCommPhaseField, "通讯阶段");

bool CCommPhaseField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=9;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CommPhase");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CommPhaseNo.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CommPhaseNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ExchangeTradingDay, CExchangeTradingDayField, "交易所交易日");

bool CExchangeTradingDayField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=18;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ExchangeTradingDay");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExchangeID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_SettlementSession, CSettlementSessionField, "结算会话");

bool CSettlementSessionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=17;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"SettlementSession");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrentTime, CCurrentTimeField, "当前时间");

bool CCurrentTimeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrentTime");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	CurrDate.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrTime.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrMillisec.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrMillisec,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DataCenterDesc, CDataCenterDescField, "数据中心描述");

bool CDataCenterDescField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DataCenterDesc");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	DataCenterID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DataCenterID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_InputOrder, CInputOrderField, "输入报单");

bool CInputOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"InputOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	OrderSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderPriceType.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderPriceType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombOffsetFlag.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombHedgeFlag.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LimitPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotalOriginal.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotalOriginal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeCondition.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	GTDDate.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",GTDDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeCondition.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MinVolume.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MinVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ContingentCondition.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ContingentCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StopPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StopPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ForceCloseReason.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ForceCloseReason,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsAutoSuspend.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsAutoSuspend,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_OrderAction, COrderActionField, "报单操作");

bool COrderActionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"OrderAction");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	OrderSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActionFlag.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActionFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LimitPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeChange.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeChange,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActionLocalID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActionLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_OTCOrder, COTCOrderField, "OTC报单");

bool COTCOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"OTCOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OTCOrderSysID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OTCOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Price.getString(buf);
	thisLen=5+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Price,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OtherParticipantID.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OtherParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OtherClientID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OtherClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OtherUserID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OtherUserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OtherOffsetFlag.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OtherOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OtherHedgeFlag.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OtherHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OTCOrderLocalID.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OTCOrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OTCOrderStatus.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OTCOrderStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CancelTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CancelTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OtherClearingPartID.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OtherClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_InputQuote, CInputQuoteField, "输入报价");

bool CInputQuoteField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"InputQuote");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	QuoteSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",QuoteSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	QuoteLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",QuoteLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidCombOffsetFlag.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidCombOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidCombHedgeFlag.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidCombHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskCombOffsetFlag.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskCombOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskCombHedgeFlag.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskCombHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QuoteAction, CQuoteActionField, "报价操作");

bool CQuoteActionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QuoteAction");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	QuoteSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",QuoteSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	QuoteLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",QuoteLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActionFlag.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActionFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActionLocalID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActionLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_InputExecOrder, CInputExecOrderField, "输入执行宣告");

bool CInputExecOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"InputExecOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExecOrderLocalID.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExecOrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ExecOrderAction, CExecOrderActionField, "执行宣告操作");

bool CExecOrderActionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ExecOrderAction");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ExecOrderSysID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExecOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExecOrderLocalID.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExecOrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActionFlag.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActionFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActionLocalID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActionLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_UserLogout, CUserLogoutField, "用户登录退出");

bool CUserLogoutField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UserLogout");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_UserPasswordUpdate, CUserPasswordUpdateField, "用户口令修改");

bool CUserPasswordUpdateField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=18;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UserPasswordUpdate");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OldPassword.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OldPassword,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	NewPassword.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",NewPassword,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_LoginInfo, CLoginInfoField, "用户登录信息");

bool CLoginInfoField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=9;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"LoginInfo");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SequenceNo.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SequenceNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserProductInfo.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserProductInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InterfaceProductInfo.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InterfaceProductInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProtocolInfo.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProtocolInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IPAddress.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IPAddress,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LoginType.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LoginType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SessionType.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SessionType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ErrorID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ErrorID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_InputCombOrder, CInputCombOrderField, "输入组合报单");

bool CInputCombOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"InputCombOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	CombOrderSysID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LimitPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotalOriginal.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotalOriginal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombOrderLocalID.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID1.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple1.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag1.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID2.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple2.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag2.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID3.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple3.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag3.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID4.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple4.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag4.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ForceUserExit, CForceUserExitField, "强制用户退出");

bool CForceUserExitField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ForceUserExit");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryOrder, CQryOrderField, "报单查询");

bool CQryOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeStart.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeEnd.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryQuote, CQryQuoteField, "报价查询");

bool CQryQuoteField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryQuote");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	QuoteSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",QuoteSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryTrade, CQryTradeField, "成交查询");

bool CQryTradeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryTrade");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradeID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeStart.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeEnd.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryMarketData, CQryMarketDataField, "行情查询");

bool CQryMarketDataField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryMarketData");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryClient, CQryClientField, "客户查询");

bool CQryClientField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=9;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryClient");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientIDStart.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientIDEnd.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryPartPosition, CQryPartPositionField, "会员持仓查询");

bool CQryPartPositionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryPartPosition");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryClientPosition, CQryClientPositionField, "客户持仓查询");

bool CQryClientPositionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=17;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryClientPosition");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientIDStart.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientIDEnd.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientType.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryPartAccount, CQryPartAccountField, "交易资金查询");

bool CQryPartAccountField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryPartAccount");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AccountID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AccountID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryInstrument, CQryInstrumentField, "合约查询");

bool CQryInstrumentField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryInstrument");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductGroupID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryInstrumentStatus, CQryInstrumentStatusField, "合约状态查询");

bool CQryInstrumentStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryInstrumentStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InstIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QrySGDataSyncStatus, CQrySGDataSyncStatusField, "结算组状态查询");

bool CQrySGDataSyncStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QrySGDataSyncStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryUserSession, CQryUserSessionField, "用户在线查询");

bool CQryUserSessionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryUserSession");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryUser, CQryUserField, "用户查询");

bool CQryUserField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=7;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryUser");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryBulletin, CQryBulletinField, "公告查询");

bool CQryBulletinField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryBulletin");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MarketID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BulletinID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BulletinID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	NewsType.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",NewsType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	NewsUrgency.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",NewsUrgency,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryParticipant, CQryParticipantField, "会员查询");

bool CQryParticipantField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryParticipant");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryHedgeVolume, CQryHedgeVolumeField, "保值额度查询");

bool CQryHedgeVolumeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryHedgeVolume");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientIDStart.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientIDEnd.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryExchangeStatus, CQryExchangeStatusField, "交易所状态查询");

bool CQryExchangeStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=17;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryExchangeStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ExchangeID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QrySettlementGroupStatus, CQrySettlementGroupStatusField, "结算组状态查询");

bool CQrySettlementGroupStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=24;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QrySettlementGroupStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryMBLMarketData, CQryMBLMarketDataField, "合约价位查询");

bool CQryMBLMarketDataField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=16;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryMBLMarketData");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InstIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryExchangeDataSyncStatus, CQryExchangeDataSyncStatusField, "交易所数据同步状态查询");

bool CQryExchangeDataSyncStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=25;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryExchangeDataSyncStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ExchangeID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryCombOrder, CQryCombOrderField, "组合报单查询");

bool CQryCombOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=12;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryCombOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	PartIDStart.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartIDEnd.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombOrderSysID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_RspPartAccount, CRspPartAccountField, "会员资金应答");

bool CRspPartAccountField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"RspPartAccount");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreBalance.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreBalance,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrMargin.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CloseProfit.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CloseProfit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Premium.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Premium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Deposit.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Deposit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Withdraw.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Withdraw,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Balance.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Balance,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Available.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Available,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AccountID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AccountID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenMargin.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenPremium.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenPremium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BaseReserve.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BaseReserve,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_RspPartPosition, CRspPartPositionField, "会员持仓应答");

bool CRspPartPositionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"RspPartPosition");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PosiDirection.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PosiDirection,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdPosition.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Position.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Position,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongFrozen.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortFrozen.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdLongFrozen.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdLongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdShortFrozen.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_RspClientPosition, CRspClientPositionField, "客户持仓应答");

bool CRspClientPositionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=17;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"RspClientPosition");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PosiDirection.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PosiDirection,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdPosition.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Position.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Position,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongFrozen.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortFrozen.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdLongFrozen.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdLongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdShortFrozen.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BuyTradeVolume.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BuyTradeVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SellTradeVolume.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SellTradeVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PositionCost.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PositionCost,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdPositionCost.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdPositionCost,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UseMargin.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UseMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenMargin.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongFrozenMargin.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongFrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortFrozenMargin.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortFrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenPremium.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenPremium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_RspInstrument, CRspInstrumentField, "合约查询应答");

bool CRspInstrumentField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"RspInstrument");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductGroupID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UnderlyingInstrID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UnderlyingInstrID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductClass.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductClass,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PositionType.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PositionType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StrikePrice.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StrikePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OptionsType.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OptionsType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeMultiple.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeMultiple,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UnderlyingMultiple.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UnderlyingMultiple,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentName.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DeliveryYear.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DeliveryYear,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DeliveryMonth.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DeliveryMonth,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AdvanceMonth.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AdvanceMonth,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsTrading.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsTrading,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CreateDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CreateDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenDate.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExpireDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExpireDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartDelivDate.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartDelivDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	EndDelivDate.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",EndDelivDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BasisPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BasisPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MaxMarketOrderVolume.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MaxMarketOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MinMarketOrderVolume.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MinMarketOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MaxLimitOrderVolume.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MaxLimitOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MinLimitOrderVolume.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MinLimitOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PriceTick.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PriceTick,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AllowDelivPersonOpen.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AllowDelivPersonOpen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryInformation, CQryInformationField, "信息查询");

bool CQryInformationField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryInformation");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InformationIDStart.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InformationIDStart,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InformationIDEnd.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InformationIDEnd,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Information, CInformationField, "信息查询");

bool CInformationField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Information");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InformationID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InformationID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SequenceNo.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SequenceNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Content.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Content,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ContentLength.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ContentLength,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsAccomplished.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsAccomplished,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_QryCreditLimit, CQryCreditLimitField, "信用限额查询");

bool CQryCreditLimitField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"QryCreditLimit");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CreditLimit, CCreditLimitField, "信用限额");

bool CCreditLimitField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CreditLimit");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreBalance.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreBalance,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrMargin.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CloseProfit.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CloseProfit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Premium.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Premium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Deposit.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Deposit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Withdraw.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Withdraw,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Balance.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Balance,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Available.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Available,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenMargin.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenPremium.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenPremium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_RspClient, CRspClientField, "客户查询应答");

bool CRspClientField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=9;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"RspClient");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientName.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IdentifiedCardType.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IdentifiedCardType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IdentifiedCardNo.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IdentifiedCardNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientType.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsActive.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsActive,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Exchange, CExchangeField, "交易所");

bool CExchangeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Exchange");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ExchangeID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExchangeName.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_SettlementGroup, CSettlementGroupField, "结算组");

bool CSettlementGroupField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"SettlementGroup");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupName.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExchangeID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Currency.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Currency,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Market, CMarketField, "市场");

bool CMarketField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=6;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Market");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	MarketID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MarketName.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketProduct, CMarketProductField, "市场产品关联");

bool CMarketProductField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketProduct");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	MarketID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketProductGroup, CMarketProductGroupField, "市场产品组关联");

bool CMarketProductGroupField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=18;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketProductGroup");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	MarketID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductGroupID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataTopic, CMarketDataTopicField, "行情主题");

bool CMarketDataTopicField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataTopic");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TopicID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TopicName.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TopicName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MarketID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SnapShotFeq.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SnapShotFeq,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MarketDataDepth.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketDataDepth,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DelaySeconds.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DelaySeconds,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MarketDataMode.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketDataMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartTopicSubscribe, CPartTopicSubscribeField, "会员订阅市场");

bool CPartTopicSubscribeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=18;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartTopicSubscribe");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantType.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TopicID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Participant, CParticipantField, "会员");

bool CParticipantField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Participant");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantName.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantAbbr.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantAbbr,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MemberType.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MemberType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsActive.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsActive,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_User, CUserField, "用户");

bool CUserField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=4;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"User");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserType.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Password.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Password,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsActive.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsActive,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Client, CClientField, "客户");

bool CClientField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=6;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Client");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientName.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IdentifiedCardType.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IdentifiedCardType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IdentifiedCardNo.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IdentifiedCardNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientType.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsActive.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsActive,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartClient, CPartClientField, "会员客户关系");

bool CPartClientField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartClient");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_UserIP, CUserIPField, "用户IP");

bool CUserIPField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=6;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UserIP");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IPAddress.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IPAddress,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IPMask.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IPMask,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_UserSession, CUserSessionField, "用户会话");

bool CUserSessionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UserSession");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	FrontID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrontID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserType.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SessionID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SessionID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LoginTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LoginTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IPAddress.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IPAddress,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserProductInfo.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserProductInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InterfaceProductInfo.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InterfaceProductInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProtocolInfo.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProtocolInfo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SessionType.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SessionType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MdPubStatus, CMdPubStatusField, "行情发布状态");

bool CMdPubStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MdPubStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentStatus.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MdPubStatus.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MdPubStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ClearingTradingPart, CClearingTradingPartField, "结算交易会员关系");

bool CClearingTradingPartField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ClearingTradingPart");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_UserFunctionRight, CUserFunctionRightField, "用户功能权限");

bool CUserFunctionRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=17;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UserFunctionRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FunctionCode.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FunctionCode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Account, CAccountField, "资金账户");

bool CAccountField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=7;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Account");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AccountID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AccountID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Currency.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Currency,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_UserCommFlux, CUserCommFluxField, "用户通讯量");

bool CUserCommFluxField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=12;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UserCommFlux");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MaxCommFlux.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MaxCommFlux,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ProductGroup, CProductGroupField, "产品组");

bool CProductGroupField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=12;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ProductGroup");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductGroupID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductGroupName.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductGroupName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CommodityID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CommodityID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Product, CProductField, "产品");

bool CProductField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=7;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Product");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductGroupID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductName.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductClass.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductClass,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Instrument, CInstrumentField, "合约");

bool CInstrumentField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Instrument");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductGroupID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UnderlyingInstrID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UnderlyingInstrID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductClass.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductClass,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PositionType.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PositionType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StrikePrice.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StrikePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OptionsType.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OptionsType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeMultiple.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeMultiple,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UnderlyingMultiple.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UnderlyingMultiple,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentName.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DeliveryYear.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DeliveryYear,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DeliveryMonth.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DeliveryMonth,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AdvanceMonth.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AdvanceMonth,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsTrading.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsTrading,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CombinationLeg, CCombinationLegField, "组合交易合约的单腿");

bool CCombinationLegField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CombinationLeg");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombInstrumentID.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombInstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegID.getString(buf);
	thisLen=5+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegInstrumentID.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegInstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ImplyLevel.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ImplyLevel,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartRoleAccount, CPartRoleAccountField, "会员账户关系");

bool CPartRoleAccountField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartRoleAccount");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AccountID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AccountID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartProductRole, CPartProductRoleField, "会员产品角色");

bool CPartProductRoleField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartProductRole");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartProductRight, CPartProductRightField, "会员产品交易权限");

bool CPartProductRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=16;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartProductRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartInstrumentRight, CPartInstrumentRightField, "会员合约交易权限");

bool CPartInstrumentRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartInstrumentRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ClientProductRight, CClientProductRightField, "客户产品交易权限");

bool CClientProductRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=18;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ClientProductRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ClientInstrumentRight, CClientInstrumentRightField, "客户合约交易权限");

bool CClientInstrumentRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=21;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ClientInstrumentRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartClientProductRight, CPartClientProductRightField, "会员客户产品交易权限");

bool CPartClientProductRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=22;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartClientProductRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartClientInstrumentRight, CPartClientInstrumentRightField, "会员客户合约交易权限");

bool CPartClientInstrumentRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=25;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartClientInstrumentRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrProductProperty, CCurrProductPropertyField, "产品属性");

bool CCurrProductPropertyField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrProductProperty");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductLifePhase.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductLifePhase,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingModel.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingModel,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OptionsLimitRatio.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OptionsLimitRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OptionsMgRatio.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OptionsMgRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlePriceSeconds.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlePriceSeconds,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrInstrumentProperty, CCurrInstrumentPropertyField, "合约属性");

bool CCurrInstrumentPropertyField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=22;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrInstrumentProperty");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CreateDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CreateDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenDate.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExpireDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExpireDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartDelivDate.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartDelivDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	EndDelivDate.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",EndDelivDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BasisPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BasisPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MaxMarketOrderVolume.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MaxMarketOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MinMarketOrderVolume.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MinMarketOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MaxLimitOrderVolume.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MaxLimitOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MinLimitOrderVolume.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MinLimitOrderVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PriceTick.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PriceTick,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AllowDelivPersonOpen.getString(buf);
	thisLen=20+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AllowDelivPersonOpen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstLifePhase.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstLifePhase,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsFirstTradingDay.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsFirstTradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrPriceBanding, CCurrPriceBandingField, "当前合约价格绑定");

bool CCurrPriceBandingField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=16;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrPriceBanding");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PriceLimitType.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PriceLimitType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	RoundingMode.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",RoundingMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperValue.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperValue,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerValue.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerValue,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingSegmentSN.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingSegmentSN,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrMarginRate, CCurrMarginRateField, "当前合约保证金率");

bool CCurrMarginRateField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrMarginRate");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MarginCalcID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarginCalcID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrMarginRateDetail, CCurrMarginRateDetailField, "当前合约保证金率的详细内容");

bool CCurrMarginRateDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=20;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrMarginRateDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongMarginRatio.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongMarginRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortMarginRatio.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortMarginRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrPartPosiLimit, CCurrPartPosiLimitField, "当前会员合约限仓");

bool CCurrPartPosiLimitField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=17;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrPartPosiLimit");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PartPosiLimitCalcID.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PartPosiLimitCalcID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrPartPosiLimitDetail, CCurrPartPosiLimitDetailField, "当前会员合约限仓的详细内容");

bool CCurrPartPosiLimitDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=23;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrPartPosiLimitDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartTotalPosition.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartTotalPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongPosLimit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortPosLimit.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrClientPosiLimit, CCurrClientPosiLimitField, "当前客户合约限仓");

bool CCurrClientPosiLimitField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrClientPosiLimit");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientPosiLimitCalcID.getString(buf);
	thisLen=21+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientPosiLimitCalcID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrClientPosiLimitDetail, CCurrClientPosiLimitDetailField, "当前客户合约限仓的详细内容");

bool CCurrClientPosiLimitDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=25;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrClientPosiLimitDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartTotalPosition.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartTotalPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongPosLimit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortPosLimit.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientType.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrSpecialPosiLimit, CCurrSpecialPosiLimitField, "当前特殊客户合约限仓");

bool CCurrSpecialPosiLimitField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=20;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrSpecialPosiLimit");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientPosiLimitCalcID.getString(buf);
	thisLen=21+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientPosiLimitCalcID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrSpecialPosiLimitDetail, CCurrSpecialPosiLimitDetailField, "当前特殊客户合约限仓的详细内容");

bool CCurrSpecialPosiLimitDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=26;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrSpecialPosiLimitDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartTotalPosition.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartTotalPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongPosLimit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortPosLimit.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrHedgeRule, CCurrHedgeRuleField, "当前合约套期保值属性");

bool CCurrHedgeRuleField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrHedgeRule");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeUsageType.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeUsageType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeCloseTodayType.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeCloseTodayType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrTradingSegmentAttr, CCurrTradingSegmentAttrField, "当前合约交易阶段属性");

bool CCurrTradingSegmentAttrField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=22;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrTradingSegmentAttr");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingSegmentSN.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingSegmentSN,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingSegmentName.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingSegmentName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentStatus.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrFuse, CCurrFuseField, "当前合约熔断属性");

bool CCurrFuseField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrFuse");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PriceLimitType.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PriceLimitType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	RoundingMode.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",RoundingMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperValue.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperValue,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerValue.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerValue,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PriceLimitDuration.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PriceLimitDuration,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FuseDuration.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FuseDuration,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingFlag.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	NoFuseTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",NoFuseTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_TradingAccount, CTradingAccountField, "交易账户资金信息");

bool CTradingAccountField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"TradingAccount");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreBalance.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreBalance,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrMargin.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CloseProfit.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CloseProfit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Premium.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Premium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Deposit.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Deposit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Withdraw.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Withdraw,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Balance.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Balance,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Available.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Available,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AccountID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AccountID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenMargin.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenPremium.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenPremium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_PartPosition, CPartPositionField, "会员合约持仓");

bool CPartPositionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=12;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"PartPosition");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PosiDirection.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PosiDirection,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdPosition.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Position.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Position,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongFrozen.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortFrozen.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdLongFrozen.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdLongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdShortFrozen.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ClientPosition, CClientPositionField, "客户合约持仓");

bool CClientPositionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ClientPosition");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PosiDirection.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PosiDirection,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdPosition.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Position.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Position,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongFrozen.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortFrozen.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdLongFrozen.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdLongFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdShortFrozen.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdShortFrozen,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BuyTradeVolume.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BuyTradeVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SellTradeVolume.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SellTradeVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PositionCost.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PositionCost,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	YdPositionCost.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",YdPositionCost,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UseMargin.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UseMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenMargin.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongFrozenMargin.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongFrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortFrozenMargin.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortFrozenMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	FrozenPremium.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrozenPremium,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_HedgeVolume, CHedgeVolumeField, "保值额度量");

bool CHedgeVolumeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"HedgeVolume");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongVolumeOriginal.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongVolumeOriginal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortVolumeOriginal.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortVolumeOriginal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongVolume.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortVolume.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_RemainOrder, CRemainOrderField, "上日遗留报单");

bool CRemainOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"RemainOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderPriceType.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderPriceType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombOffsetFlag.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombHedgeFlag.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LimitPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotalOriginal.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotalOriginal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeCondition.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	GTDDate.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",GTDDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeCondition.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MinVolume.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MinVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ContingentCondition.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ContingentCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StopPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StopPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ForceCloseReason.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ForceCloseReason,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsAutoSuspend.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsAutoSuspend,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderSource.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSource,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderStatus.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderType.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTraded.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTraded,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotal.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActiveTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActiveTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SuspendTime.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SuspendTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CancelTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CancelTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActiveUserID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActiveUserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Priority.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Priority,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeSortID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeSortID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketData, CMarketDataField, "市场行情");

bool CMarketDataField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketData");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LastPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LastPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreSettlementPrice.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreSettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreClosePrice.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreOpenInterest.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreOpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HighestPrice.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HighestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowestPrice.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Turnover.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Turnover,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenInterest.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClosePrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreDelta.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrDelta.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateMillisec.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateMillisec,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DepthMarketData, CDepthMarketDataField, "深度行情");

bool CDepthMarketDataField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DepthMarketData");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LastPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LastPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreSettlementPrice.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreSettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreClosePrice.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreOpenInterest.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreOpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HighestPrice.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HighestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowestPrice.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Turnover.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Turnover,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenInterest.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClosePrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreDelta.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrDelta.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateMillisec.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateMillisec,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice1.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice1.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice2.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice2.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice3.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice3.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice4.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice4.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice5.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume5.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice5.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume5.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MBLMarketData, CMBLMarketDataField, "分价表");

bool CMBLMarketDataField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MBLMarketData");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Price.getString(buf);
	thisLen=5+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Price,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_AliasDefine, CAliasDefineField, "别名定义");

bool CAliasDefineField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"AliasDefine");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	StartPos.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartPos,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Alias.getString(buf);
	thisLen=5+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Alias,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OriginalText.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OriginalText,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataBase, CMarketDataBaseField, "行情基础属性");

bool CMarketDataBaseField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataBase");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreSettlementPrice.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreSettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreClosePrice.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreOpenInterest.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreOpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreDelta.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataStatic, CMarketDataStaticField, "行情静态属性");

bool CMarketDataStaticField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=16;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataStatic");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	OpenPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HighestPrice.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HighestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowestPrice.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClosePrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrDelta.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataLastMatch, CMarketDataLastMatchField, "行情最新成交属性");

bool CMarketDataLastMatchField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataLastMatch");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	LastPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LastPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Turnover.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Turnover,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenInterest.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataBestPrice, CMarketDataBestPriceField, "行情最优价属性");

bool CMarketDataBestPriceField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=19;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataBestPrice");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	BidPrice1.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice1.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataBid23, CMarketDataBid23Field, "行情申买二、三属性");

bool CMarketDataBid23Field::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataBid23");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	BidPrice2.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice3.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataAsk23, CMarketDataAsk23Field, "行情申卖二、三属性");

bool CMarketDataAsk23Field::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataAsk23");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	AskPrice2.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice3.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataBid45, CMarketDataBid45Field, "行情申买四、五属性");

bool CMarketDataBid45Field::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataBid45");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	BidPrice4.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice5.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume5.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataAsk45, CMarketDataAsk45Field, "行情申卖四、五属性");

bool CMarketDataAsk45Field::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataAsk45");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	AskPrice4.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice5.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume5.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_MarketDataUpdateTime, CMarketDataUpdateTimeField, "行情更新时间属性");

bool CMarketDataUpdateTimeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=20;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"MarketDataUpdateTime");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateMillisec.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateMillisec,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_BaseReserveAccount, CBaseReserveAccountField, "基础准备金账户");

bool CBaseReserveAccountField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=18;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"BaseReserveAccount");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AccountID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AccountID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Reserve.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Reserve,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtAccountDeposit, CDbmtAccountDepositField, "Dbmt会员资金帐户入金");

bool CDbmtAccountDepositField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=18;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtAccountDeposit");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Account.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Account,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Deposit.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Deposit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtClient, CDbmtClientField, "Dbmt客户");

bool CDbmtClientField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtClient");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientName.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientName,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IdentifiedCardType.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IdentifiedCardType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IdentifiedCardNo.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IdentifiedCardNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientType.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsActive.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsActive,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtPartClient, CDbmtPartClientField, "Dbmt会员客户");

bool CDbmtPartClientField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtPartClient");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtCurrPartPosiLimitDetail, CDbmtCurrPartPosiLimitDetailField, "Dbmt会员合约持仓限额");

bool CDbmtCurrPartPosiLimitDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=27;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtCurrPartPosiLimitDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartTotalPosition.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartTotalPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongPosLimit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortPosLimit.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtCurrClientPosiLimitDetail, CDbmtCurrClientPosiLimitDetailField, "Dbmt客户合约持仓限额");

bool CDbmtCurrClientPosiLimitDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=29;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtCurrClientPosiLimitDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartTotalPosition.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartTotalPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongPosLimit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortPosLimit.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientType.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtCurrSpecialPosiLimitDetail, CDbmtCurrSpecialPosiLimitDetailField, "Dbmt特殊客户合约持仓限额");

bool CDbmtCurrSpecialPosiLimitDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=30;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtCurrSpecialPosiLimitDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StartTotalPosition.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StartTotalPosition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongPosLimit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortPosLimit.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortPosLimit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtHedgeDetail, CDbmtHedgeDetailField, "Dbmt保值额度明细");

bool CDbmtHedgeDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtHedgeDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeQuotaSN.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeQuotaSN,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OperatorID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OperatorID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Time.getString(buf);
	thisLen=4+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Time,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PosiDirection.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PosiDirection,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingVolume.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeQuota.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeQuota,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtUser, CDbmtUserField, "Dbmt用户");

bool CDbmtUserField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtUser");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserType.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Password.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Password,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsActive.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsActive,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtPartProductRight, CDbmtPartProductRightField, "Dbmt会员产品权限");

bool CDbmtPartProductRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=20;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtPartProductRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtClientProductRight, CDbmtClientProductRightField, "Dbmt客户产品权限");

bool CDbmtClientProductRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=22;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtClientProductRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtPartInstrumentRight, CDbmtPartInstrumentRightField, "Dbmt会员合约权限");

bool CDbmtPartInstrumentRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=23;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtPartInstrumentRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtClientInstrumentRight, CDbmtClientInstrumentRightField, "Dbmt客户合约权限");

bool CDbmtClientInstrumentRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=25;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtClientInstrumentRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtPartClientProductRight, CDbmtPartClientProductRightField, "Dbmt会员客户产品权限");

bool CDbmtPartClientProductRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=26;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtPartClientProductRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ProductID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ProductID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtPartClientInstrumentRight, CDbmtPartClientInstrumentRightField, "Dbmt会员客户合约权限");

bool CDbmtPartClientInstrumentRightField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=29;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtPartClientInstrumentRight");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRight.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRight,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtCurrMarginRateDetail, CDbmtCurrMarginRateDetailField, "Dbmt会员合约保证金率");

bool CDbmtCurrMarginRateDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=24;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtCurrMarginRateDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LongMarginRatio.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LongMarginRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ShortMarginRatio.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ShortMarginRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtMarketData, CDbmtMarketDataField, "Dbmt行情");

bool CDbmtMarketDataField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtMarketData");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LastPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LastPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreSettlementPrice.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreSettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreClosePrice.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreOpenInterest.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreOpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HighestPrice.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HighestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowestPrice.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Turnover.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Turnover,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenInterest.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClosePrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreDelta.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrDelta.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateMillisec.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateMillisec,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtUserIP, CDbmtUserIPField, "Dbmt用户IP地址");

bool CDbmtUserIPField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtUserIP");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IPAddress.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IPAddress,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IPMask.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IPMask,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtCurrPriceBanding, CDbmtCurrPriceBandingField, "Dbmt价格绑定");

bool CDbmtCurrPriceBandingField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=20;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtCurrPriceBanding");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PriceLimitType.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PriceLimitType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ValueMode.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ValueMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	RoundingMode.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",RoundingMode,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperValue.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperValue,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerValue.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerValue,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingSegmentSN.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingSegmentSN,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtUpdateAllInstrumentStatus, CDbmtUpdateAllInstrumentStatusField, "Dbmt更新所有合约状态");

bool CDbmtUpdateAllInstrumentStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=29;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtUpdateAllInstrumentStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentStatus.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtPartTopicSubscribe, CDbmtPartTopicSubscribeField, "Dbmt会员订阅市场");

bool CDbmtPartTopicSubscribeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=22;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtPartTopicSubscribe");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantType.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TopicID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DbmtCurrHedge, CDbmtCurrHedgeField, "Dbmt当前保值额度");

bool CDbmtCurrHedgeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=13;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DbmtCurrHedge");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeQuotaSN.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeQuotaSN,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OperatorID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OperatorID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Time.getString(buf);
	thisLen=4+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Time,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PosiDirection.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PosiDirection,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrVolume.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtTopicID.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtTopicID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	DbmtSequenceID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",DbmtSequenceID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Quote, CQuoteField, "报价");

bool CQuoteField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=5;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Quote");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	QuoteSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",QuoteSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	QuoteLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",QuoteLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidCombOffsetFlag.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidCombOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidCombHedgeFlag.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidCombHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskCombOffsetFlag.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskCombOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskCombHedgeFlag.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskCombHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CancelTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CancelTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradeTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradeTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidOrderSysID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskOrderSysID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Trade, CTradeField, "成交");

bool CTradeField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=5;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Trade");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradeID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingRole.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingRole,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AccountID.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AccountID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Price.getString(buf);
	thisLen=5+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Price,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradeTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradeTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradeType.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradeType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PriceSource.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PriceSource,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Order, COrderField, "报单");

bool COrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=5;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Order");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderSysID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderPriceType.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderPriceType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombOffsetFlag.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOffsetFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombHedgeFlag.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombHedgeFlag,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LimitPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotalOriginal.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotalOriginal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeCondition.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	GTDDate.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",GTDDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeCondition.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MinVolume.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MinVolume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ContingentCondition.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ContingentCondition,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	StopPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",StopPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ForceCloseReason.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ForceCloseReason,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderLocalID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsAutoSuspend.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsAutoSuspend,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderSource.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSource,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderStatus.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderType.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTraded.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTraded,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotal.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActiveTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActiveTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SuspendTime.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SuspendTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CancelTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CancelTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ActiveUserID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ActiveUserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Priority.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Priority,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TimeSortID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TimeSortID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ExecOrder, CExecOrderField, "执行宣告");

bool CExecOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=9;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ExecOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExecOrderLocalID.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExecOrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExecOrderSysID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExecOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CancelTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CancelTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExecResult.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExecResult,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CombOrder, CCombOrderField, "组合报单");

bool CCombOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=9;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CombOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombOrderSysID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOrderSysID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClientID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClientID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UserID.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UserID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LimitPrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotalOriginal.getString(buf);
	thisLen=19+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotalOriginal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CombOrderLocalID.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CombOrderLocalID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BusinessUnit.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BusinessUnit,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID1.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple1.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag1.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID2.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple2.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag2.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID3.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple3.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag3.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID4.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Direction4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Direction4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LegMultiple4.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LegMultiple4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OffsetFlag4.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OffsetFlag4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HedgeFlag4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HedgeFlag4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OrderSource.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OrderSource,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTraded.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTraded,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	VolumeTotal.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",VolumeTotal,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertDate.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertDate,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InsertTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InsertTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_AdminOrder, CAdminOrderField, "管理报单");

bool CAdminOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=10;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"AdminOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AdminOrderCommand.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AdminOrderCommand,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Amount.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Amount,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_InputAdminOrder, CInputAdminOrderField, "管理报单输入");

bool CInputAdminOrderField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=15;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"InputAdminOrder");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AdminOrderCommand.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AdminOrderCommand,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClearingPartID.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClearingPartID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ParticipantID.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ParticipantID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Amount.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Amount,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_Bulletin, CBulletinField, "公告");

bool CBulletinField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=8;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"Bulletin");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BulletinID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BulletinID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SequenceNo.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SequenceNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	NewsType.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",NewsType,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	NewsUrgency.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",NewsUrgency,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SendTime.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SendTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Abstract.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Abstract,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ComeFrom.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ComeFrom,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Content.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Content,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	URLLink.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",URLLink,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MarketID.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MarketID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ExchangeDataSyncStatus, CExchangeDataSyncStatusField, "交易所数据同步状态");

bool CExchangeDataSyncStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=22;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ExchangeDataSyncStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExchangeID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExchangeDataSyncStatus.getString(buf);
	thisLen=22+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeDataSyncStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_SGDataSyncStatus, CSGDataSyncStatusField, "结算组数据同步状态");

bool CSGDataSyncStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=16;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"SGDataSyncStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SGDataSyncStatus.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SGDataSyncStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_InstrumentStatus, CInstrumentStatusField, "合约状态");

bool CInstrumentStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=16;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"InstrumentStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentStatus.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingSegmentSN.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingSegmentSN,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	EnterTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",EnterTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	EnterReason.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",EnterReason,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_InstrumentStatusDetail, CInstrumentStatusDetailField, "合约交易状态流水");

bool CInstrumentStatusDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=22;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"InstrumentStatusDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentStatus.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingSegmentSN.getString(buf);
	thisLen=16+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingSegmentSN,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	EnterTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",EnterTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	EnterReason.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",EnterReason,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SequenceNo.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SequenceNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_FrontStatus, CFrontStatusField, "前置状态");

bool CFrontStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"FrontStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	FrontID.getString(buf);
	thisLen=7+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",FrontID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LastReportTime.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LastReportTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	IsActive.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",IsActive,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_ExchangeStatus, CExchangeStatusField, "交易所状态");

bool CExchangeStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=14;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"ExchangeStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExchangeID.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ExchangeStatus.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ExchangeStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_SettlementGroupStatus, CSettlementGroupStatusField, "结算组状态");

bool CSettlementGroupStatusField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=21;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"SettlementGroupStatus");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupStatus.getString(buf);
	thisLen=21+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupStatus,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	EnterTime.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",EnterTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_UniPressure, CUniPressureField, "单边市情况");

bool CUniPressureField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=11;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"UniPressure");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperPressureStartTime.getString(buf);
	thisLen=22+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperPressureStartTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerPressureStartTime.getString(buf);
	thisLen=22+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerPressureStartTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_DepthMarketDataDetail, CDepthMarketDataDetailField, "深度行情流水");

bool CDepthMarketDataDetailField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=21;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"DepthMarketDataDetail");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	TradingDay.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",TradingDay,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LastPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LastPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreSettlementPrice.getString(buf);
	thisLen=18+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreSettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreClosePrice.getString(buf);
	thisLen=13+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreOpenInterest.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreOpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenPrice.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	HighestPrice.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",HighestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowestPrice.getString(buf);
	thisLen=11+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowestPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Volume.getString(buf);
	thisLen=6+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Volume,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	Turnover.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",Turnover,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OpenInterest.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OpenInterest,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	ClosePrice.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",ClosePrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SettlementPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpperLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpperLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	LowerLimitPrice.getString(buf);
	thisLen=15+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",LowerLimitPrice,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	PreDelta.getString(buf);
	thisLen=8+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",PreDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	CurrDelta.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",CurrDelta,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateTime.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateTime,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UpdateMillisec.getString(buf);
	thisLen=14+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UpdateMillisec,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice1.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice1.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume1.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume1,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice2.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice2.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume2.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume2,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice3.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice3.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume3.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume3,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice4.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice4.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume4.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume4,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidPrice5.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidPrice5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	BidVolume5.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",BidVolume5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskPrice5.getString(buf);
	thisLen=9+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskPrice5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	AskVolume5.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",AskVolume5,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	SequenceNo.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SequenceNo,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

REGISTER_FIELD(FID_CurrInstrumentOption, CCurrInstrumentOptionField, "当日期货合约期权属性");

bool CCurrInstrumentOptionField::dumpLine(char *buffer, int len)
{
	char *pos=buffer;
	int nameLen=20;
	int thisLen;
	if (len<nameLen+1)
	{
		buffer[0]='\0';
		return false;
	}
	strcpy(pos,"CurrInstrumentOption");
	pos+=nameLen;
	len-=nameLen;

	char buf[4000];
	SettlementGroupID.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",SettlementGroupID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	InstrumentID.getString(buf);
	thisLen=12+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",InstrumentID,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	OptPostLimitRatio.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",OptPostLimitRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	UniPostLimitRatio.getString(buf);
	thisLen=17+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",UniPostLimitRatio,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	MiniMargin.getString(buf);
	thisLen=10+strlen(buf)+2;
	if (len<thisLen+1)
	{
		return false;
	}
	sprintf(pos,",MiniMargin,%s",buf);	
	pos+=thisLen;
	len-=nameLen;
	
	return true;
}

