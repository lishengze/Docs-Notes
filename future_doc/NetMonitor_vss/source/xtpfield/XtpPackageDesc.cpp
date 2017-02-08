// XtpPackageDesc.cpp: 
//
//////////////////////////////////////////////////////////////////////

#include "public.h"
#include "XtpPackageDesc.h"


const char *getPackageName(DWORD tid)
{
	switch (tid)
	{
	case TID_Nop:
		return "Nop";
	case TID_RspError:
		return "RspError";
	case TID_ReqUserLogin:
		return "ReqUserLogin";
	case TID_RspUserLogin:
		return "RspUserLogin";
	case TID_ReqUserLogout:
		return "ReqUserLogout";
	case TID_RspUserLogout:
		return "RspUserLogout";
	case TID_ReqOrderInsert:
		return "ReqOrderInsert";
	case TID_RspOrderInsert:
		return "RspOrderInsert";
	case TID_ReqOrderAction:
		return "ReqOrderAction";
	case TID_RspOrderAction:
		return "RspOrderAction";
	case TID_ReqQuoteInsert:
		return "ReqQuoteInsert";
	case TID_RspQuoteInsert:
		return "RspQuoteInsert";
	case TID_ReqQuoteAction:
		return "ReqQuoteAction";
	case TID_RspQuoteAction:
		return "RspQuoteAction";
	case TID_ReqOTCOrderInsert:
		return "ReqOTCOrderInsert";
	case TID_RspOTCOrderInsert:
		return "RspOTCOrderInsert";
	case TID_ReqUserPasswordUpdate:
		return "ReqUserPasswordUpdate";
	case TID_RspUserPasswordUpdate:
		return "RspUserPasswordUpdate";
	case TID_ReqExecOrderInsert:
		return "ReqExecOrderInsert";
	case TID_RspExecOrderInsert:
		return "RspExecOrderInsert";
	case TID_ReqExecOrderAction:
		return "ReqExecOrderAction";
	case TID_RspExecOrderAction:
		return "RspExecOrderAction";
	case TID_ReqAdminOrderInsert:
		return "ReqAdminOrderInsert";
	case TID_RspAdminOrderInsert:
		return "RspAdminOrderInsert";
	case TID_ReqCombOrderInsert:
		return "ReqCombOrderInsert";
	case TID_RspCombOrderInsert:
		return "RspCombOrderInsert";
	case TID_ReqBulletin:
		return "ReqBulletin";
	case TID_RspBulletin:
		return "RspBulletin";
	case TID_ReqInstrumentStatusUpdate:
		return "ReqInstrumentStatusUpdate";
	case TID_RspInstrumentStatusUpdate:
		return "RspInstrumentStatusUpdate";
	case TID_ReqForceUserExit:
		return "ReqForceUserExit";
	case TID_RspForceUserExit:
		return "RspForceUserExit";
	case TID_ReqForceUserLogout:
		return "ReqForceUserLogout";
	case TID_RspForceUserLogout:
		return "RspForceUserLogout";
	case TID_ReqExchangeDataSyncStatusUpdate:
		return "ReqExchangeDataSyncStatusUpdate";
	case TID_RspExchangeDataSyncStatusUpdate:
		return "RspExchangeDataSyncStatusUpdate";
	case TID_ReqSGDataSyncStatusUpdate:
		return "ReqSGDataSyncStatusUpdate";
	case TID_RspSGDataSyncStatusUpdate:
		return "RspSGDataSyncStatusUpdate";
	case TID_ReqExchangeDataSync:
		return "ReqExchangeDataSync";
	case TID_RspExchangeDataSync:
		return "RspExchangeDataSync";
	case TID_ReqSgDataSync:
		return "ReqSgDataSync";
	case TID_RspSgDataSync:
		return "RspSgDataSync";
	case TID_ReqInformation:
		return "ReqInformation";
	case TID_RspInformation:
		return "RspInformation";
	case TID_ReqFrontStatus:
		return "ReqFrontStatus";
	case TID_RspFrontStatus:
		return "RspFrontStatus";
	case TID_ReqQryPartAccount:
		return "ReqQryPartAccount";
	case TID_RspQryPartAccount:
		return "RspQryPartAccount";
	case TID_ReqQryOrder:
		return "ReqQryOrder";
	case TID_RspQryOrder:
		return "RspQryOrder";
	case TID_ReqQryQuote:
		return "ReqQryQuote";
	case TID_RspQryQuote:
		return "RspQryQuote";
	case TID_ReqQryTrade:
		return "ReqQryTrade";
	case TID_RspQryTrade:
		return "RspQryTrade";
	case TID_ReqQryClient:
		return "ReqQryClient";
	case TID_RspQryClient:
		return "RspQryClient";
	case TID_ReqQryPartPosition:
		return "ReqQryPartPosition";
	case TID_RspQryPartPosition:
		return "RspQryPartPosition";
	case TID_ReqQryClientPosition:
		return "ReqQryClientPosition";
	case TID_RspQryClientPosition:
		return "RspQryClientPosition";
	case TID_ReqQryInstrument:
		return "ReqQryInstrument";
	case TID_RspQryInstrument:
		return "RspQryInstrument";
	case TID_ReqQryInstrumentStatus:
		return "ReqQryInstrumentStatus";
	case TID_RspQryInstrumentStatus:
		return "RspQryInstrumentStatus";
	case TID_ReqQrySGDataSyncStatus:
		return "ReqQrySGDataSyncStatus";
	case TID_RspQrySGDataSyncStatus:
		return "RspQrySGDataSyncStatus";
	case TID_ReqQryHedgeVolume:
		return "ReqQryHedgeVolume";
	case TID_RspQryHedgeVolume:
		return "RspQryHedgeVolume";
	case TID_ReqQryCombOrder:
		return "ReqQryCombOrder";
	case TID_RspQryCombOrder:
		return "RspQryCombOrder";
	case TID_ReqQryMarketData:
		return "ReqQryMarketData";
	case TID_RspQryMarketData:
		return "RspQryMarketData";
	case TID_ReqQryBulletin:
		return "ReqQryBulletin";
	case TID_RspQryBulletin:
		return "RspQryBulletin";
	case TID_ReqQryUserSession:
		return "ReqQryUserSession";
	case TID_RspQryUserSession:
		return "RspQryUserSession";
	case TID_ReqQryUser:
		return "ReqQryUser";
	case TID_RspQryUser:
		return "RspQryUser";
	case TID_ReqQryParticipant:
		return "ReqQryParticipant";
	case TID_RspQryParticipant:
		return "RspQryParticipant";
	case TID_ReqQryMBLMarketData:
		return "ReqQryMBLMarketData";
	case TID_RspQryMBLMarketData:
		return "RspQryMBLMarketData";
	case TID_ReqQryInformation:
		return "ReqQryInformation";
	case TID_RspQryInformation:
		return "RspQryInformation";
	case TID_ReqQryExchangeStatus:
		return "ReqQryExchangeStatus";
	case TID_RspQryExchangeStatus:
		return "RspQryExchangeStatus";
	case TID_ReqQryExchangeDataSyncStatus:
		return "ReqQryExchangeDataSyncStatus";
	case TID_RspQryExchangeDataSyncStatus:
		return "RspQryExchangeDataSyncStatus";
	case TID_ReqQrySettlementGroupStatus:
		return "ReqQrySettlementGroupStatus";
	case TID_RspQrySettlementGroupStatus:
		return "RspQrySettlementGroupStatus";
	case TID_ReqQryCreditLimit:
		return "ReqQryCreditLimit";
	case TID_RspQryCreditLimit:
		return "RspQryCreditLimit";
	case TID_DbAccountDeposit:
		return "DbAccountDeposit";
	case TID_DbUpdateAllInstrumentStatus:
		return "DbUpdateAllInstrumentStatus";
	case TID_DbInsClient:
		return "DbInsClient";
	case TID_DbUpdClient:
		return "DbUpdClient";
	case TID_DbInsPartClient:
		return "DbInsPartClient";
	case TID_DbDelPartClient:
		return "DbDelPartClient";
	case TID_DbInsCurrPartPosiLimitDetail:
		return "DbInsCurrPartPosiLimitDetail";
	case TID_DbUpdCurrPartPosiLimitDetail:
		return "DbUpdCurrPartPosiLimitDetail";
	case TID_DbDelCurrPartPosiLimitDetail:
		return "DbDelCurrPartPosiLimitDetail";
	case TID_DbInsCurrClientPosiLimitDetail:
		return "DbInsCurrClientPosiLimitDetail";
	case TID_DbUpdCurrClientPosiLimitDetail:
		return "DbUpdCurrClientPosiLimitDetail";
	case TID_DbDelCurrClientPosiLimitDetail:
		return "DbDelCurrClientPosiLimitDetail";
	case TID_DbInsCurrSpecialPosiLimitDetail:
		return "DbInsCurrSpecialPosiLimitDetail";
	case TID_DbUpdCurrSpecialPosiLimitDetail:
		return "DbUpdCurrSpecialPosiLimitDetail";
	case TID_DbDelCurrSpecialPosiLimitDetail:
		return "DbDelCurrSpecialPosiLimitDetail";
	case TID_DbInsHedgeDetail:
		return "DbInsHedgeDetail";
	case TID_DbUpdCurrHedge:
		return "DbUpdCurrHedge";
	case TID_DbInsUser:
		return "DbInsUser";
	case TID_DbUpdUser:
		return "DbUpdUser";
	case TID_DbInsPartProductRight:
		return "DbInsPartProductRight";
	case TID_DbUpdPartProductRight:
		return "DbUpdPartProductRight";
	case TID_DbDelPartProductRight:
		return "DbDelPartProductRight";
	case TID_DbInsClientProductRight:
		return "DbInsClientProductRight";
	case TID_DbUpdClientProductRight:
		return "DbUpdClientProductRight";
	case TID_DbDelClientProductRight:
		return "DbDelClientProductRight";
	case TID_DbInsPartInstrumentRight:
		return "DbInsPartInstrumentRight";
	case TID_DbUpdPartInstrumentRight:
		return "DbUpdPartInstrumentRight";
	case TID_DbDelPartInstrumentRight:
		return "DbDelPartInstrumentRight";
	case TID_DbInsClientInstrumentRight:
		return "DbInsClientInstrumentRight";
	case TID_DbUpdClientInstrumentRight:
		return "DbUpdClientInstrumentRight";
	case TID_DbDelClientInstrumentRight:
		return "DbDelClientInstrumentRight";
	case TID_DbInsPartClientProductRight:
		return "DbInsPartClientProductRight";
	case TID_DbUpdPartClientProductRight:
		return "DbUpdPartClientProductRight";
	case TID_DbDelPartClientProductRight:
		return "DbDelPartClientProductRight";
	case TID_DbInsPartClientInstrumentRight:
		return "DbInsPartClientInstrumentRight";
	case TID_DbUpdPartClientInstrumentRight:
		return "DbUpdPartClientInstrumentRight";
	case TID_DbDelPartClientInstrumentRight:
		return "DbDelPartClientInstrumentRight";
	case TID_DbInsCurrMarginRateDetail:
		return "DbInsCurrMarginRateDetail";
	case TID_DbUpdCurrMarginRateDetail:
		return "DbUpdCurrMarginRateDetail";
	case TID_DbDelCurrMarginRateDetail:
		return "DbDelCurrMarginRateDetail";
	case TID_DbUpdMarketData:
		return "DbUpdMarketData";
	case TID_DbInsUserIP:
		return "DbInsUserIP";
	case TID_DbDelUserIP:
		return "DbDelUserIP";
	case TID_DbInsCurrPriceBanding:
		return "DbInsCurrPriceBanding";
	case TID_DbUpdCurrPriceBanding:
		return "DbUpdCurrPriceBanding";
	case TID_DbDelCurrPriceBanding:
		return "DbDelCurrPriceBanding";
	case TID_DbInsPartTopicSubscribe:
		return "DbInsPartTopicSubscribe";
	case TID_DbDelPartTopicSubscribe:
		return "DbDelPartTopicSubscribe";
	case TID_NtfTimeSync:
		return "NtfTimeSync";
	case TID_NtfCommPhaseChange:
		return "NtfCommPhaseChange";
	case TID_NtfDataCenterDesc:
		return "NtfDataCenterDesc";
	case TID_NtfInsInstrument:
		return "NtfInsInstrument";
	case TID_NtfDelInstrument:
		return "NtfDelInstrument";
	case TID_NtfInsCombinationLeg:
		return "NtfInsCombinationLeg";
	case TID_NtfDelCombinationLeg:
		return "NtfDelCombinationLeg";
	case TID_NtfAliasDefine:
		return "NtfAliasDefine";
	case TID_NtfOrder:
		return "NtfOrder";
	case TID_NtfTrade:
		return "NtfTrade";
	case TID_NtfQuote:
		return "NtfQuote";
	case TID_NtfExecOrder:
		return "NtfExecOrder";
	case TID_NtfCombOrder:
		return "NtfCombOrder";
	case TID_NtfInstrumentStatusUpdate:
		return "NtfInstrumentStatusUpdate";
	case TID_NtfDelUserSession:
		return "NtfDelUserSession";
	case TID_NtfBulletin:
		return "NtfBulletin";
	case TID_NtfMarketData:
		return "NtfMarketData";
	case TID_NtfDepthMarketData:
		return "NtfDepthMarketData";
	case TID_NtfAdminOrder:
		return "NtfAdminOrder";
	case TID_ExchangeDataSyncStart:
		return "ExchangeDataSyncStart";
	case TID_ExchangeDataSyncEnd:
		return "ExchangeDataSyncEnd";
	case TID_InitExchange:
		return "InitExchange";
	case TID_InitSettlementGroup:
		return "InitSettlementGroup";
	case TID_InitMarket:
		return "InitMarket";
	case TID_InitMarketProduct:
		return "InitMarketProduct";
	case TID_InitMarketProductGroup:
		return "InitMarketProductGroup";
	case TID_InitMarketDataTopic:
		return "InitMarketDataTopic";
	case TID_InitPartTopicSubscribe:
		return "InitPartTopicSubscribe";
	case TID_InitParticipant:
		return "InitParticipant";
	case TID_InitUser:
		return "InitUser";
	case TID_InitClient:
		return "InitClient";
	case TID_InitPartClient:
		return "InitPartClient";
	case TID_InitUserIP:
		return "InitUserIP";
	case TID_InitMdPubStatus:
		return "InitMdPubStatus";
	case TID_InitAliasDefine:
		return "InitAliasDefine";
	case TID_InitClearingTradingPart:
		return "InitClearingTradingPart";
	case TID_InitUserFunctionRight:
		return "InitUserFunctionRight";
	case TID_InitAccount:
		return "InitAccount";
	case TID_InitUserCommFlux:
		return "InitUserCommFlux";
	case TID_SettlementGroupDataSyncStart:
		return "SettlementGroupDataSyncStart";
	case TID_SettlementGroupDataSyncEnd:
		return "SettlementGroupDataSyncEnd";
	case TID_InitInstrument:
		return "InitInstrument";
	case TID_InitCombinationLeg:
		return "InitCombinationLeg";
	case TID_InitPartRoleAccount:
		return "InitPartRoleAccount";
	case TID_InitPartProductRole:
		return "InitPartProductRole";
	case TID_InitPartProductRight:
		return "InitPartProductRight";
	case TID_InitPartInstrumentRight:
		return "InitPartInstrumentRight";
	case TID_InitClientProductRight:
		return "InitClientProductRight";
	case TID_InitClientInstrumentRight:
		return "InitClientInstrumentRight";
	case TID_InitPartClientProductRight:
		return "InitPartClientProductRight";
	case TID_InitPartClientInstrumentRight:
		return "InitPartClientInstrumentRight";
	case TID_InitCurrProductProperty:
		return "InitCurrProductProperty";
	case TID_InitCurrInstrumentProperty:
		return "InitCurrInstrumentProperty";
	case TID_InitCurrPriceBanding:
		return "InitCurrPriceBanding";
	case TID_InitCurrMarginRate:
		return "InitCurrMarginRate";
	case TID_InitCurrMarginRateDetail:
		return "InitCurrMarginRateDetail";
	case TID_InitCurrPartPosiLimit:
		return "InitCurrPartPosiLimit";
	case TID_InitCurrPartPosiLimitDetail:
		return "InitCurrPartPosiLimitDetail";
	case TID_InitCurrClientPosiLimit:
		return "InitCurrClientPosiLimit";
	case TID_InitCurrClientPosiLimitDetail:
		return "InitCurrClientPosiLimitDetail";
	case TID_InitCurrSpecialPosiLimit:
		return "InitCurrSpecialPosiLimit";
	case TID_InitCurrSpecialPosiLimitDetail:
		return "InitCurrSpecialPosiLimitDetail";
	case TID_InitCurrHedgeRule:
		return "InitCurrHedgeRule";
	case TID_InitCurrTradingSegmentAttr:
		return "InitCurrTradingSegmentAttr";
	case TID_InitCurrFuse:
		return "InitCurrFuse";
	case TID_InitTradingAccount:
		return "InitTradingAccount";
	case TID_InitPartPosition:
		return "InitPartPosition";
	case TID_InitClientPosition:
		return "InitClientPosition";
	case TID_InitHedgeVolume:
		return "InitHedgeVolume";
	case TID_InitRemainOrder:
		return "InitRemainOrder";
	case TID_InitMarketData:
		return "InitMarketData";
	case TID_InitBaseReserveAccount:
		return "InitBaseReserveAccount";
	case TID_InitCurrInstrumentOption:
		return "InitCurrInstrumentOption";
	case TID_NtfInputMarketData:
		return "NtfInputMarketData";
	}
	return "unknown";
}

TFieldUse NopFieldUse[]=
{
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse RspErrorFieldUse[]=
{
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqUserLoginFieldUse[]=
{
		{ FID_UserLogin, &CUserLoginField::m_Describe, 1,  1  }
};

TFieldUse RspUserLoginFieldUse[]=
{
		{ FID_UserLogin, &CUserLoginField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqUserLogoutFieldUse[]=
{
		{ FID_UserLogout, &CUserLogoutField::m_Describe, 1,  1  }
};

TFieldUse RspUserLogoutFieldUse[]=
{
		{ FID_UserLogout, &CUserLogoutField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqOrderInsertFieldUse[]=
{
		{ FID_InputOrder, &CInputOrderField::m_Describe, 1,  1  }
};

TFieldUse RspOrderInsertFieldUse[]=
{
		{ FID_InputOrder, &CInputOrderField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqOrderActionFieldUse[]=
{
		{ FID_OrderAction, &COrderActionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse RspOrderActionFieldUse[]=
{
		{ FID_OrderAction, &COrderActionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQuoteInsertFieldUse[]=
{
		{ FID_InputQuote, &CInputQuoteField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse RspQuoteInsertFieldUse[]=
{
		{ FID_InputQuote, &CInputQuoteField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQuoteActionFieldUse[]=
{
		{ FID_QuoteAction, &CQuoteActionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse RspQuoteActionFieldUse[]=
{
		{ FID_QuoteAction, &CQuoteActionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqOTCOrderInsertFieldUse[]=
{
		{ FID_OTCOrder, &COTCOrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse RspOTCOrderInsertFieldUse[]=
{
		{ FID_OTCOrder, &COTCOrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqUserPasswordUpdateFieldUse[]=
{
		{ FID_UserPasswordUpdate, &CUserPasswordUpdateField::m_Describe, 1,  1  }
};

TFieldUse RspUserPasswordUpdateFieldUse[]=
{
		{ FID_UserPasswordUpdate, &CUserPasswordUpdateField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqExecOrderInsertFieldUse[]=
{
		{ FID_InputExecOrder, &CInputExecOrderField::m_Describe, 1,  1  }
};

TFieldUse RspExecOrderInsertFieldUse[]=
{
		{ FID_InputExecOrder, &CInputExecOrderField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqExecOrderActionFieldUse[]=
{
		{ FID_ExecOrderAction, &CExecOrderActionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse RspExecOrderActionFieldUse[]=
{
		{ FID_ExecOrderAction, &CExecOrderActionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqAdminOrderInsertFieldUse[]=
{
		{ FID_InputAdminOrder, &CInputAdminOrderField::m_Describe, 1,  1  }
};

TFieldUse RspAdminOrderInsertFieldUse[]=
{
		{ FID_InputAdminOrder, &CInputAdminOrderField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqCombOrderInsertFieldUse[]=
{
		{ FID_InputCombOrder, &CInputCombOrderField::m_Describe, 1,  1  }
};

TFieldUse RspCombOrderInsertFieldUse[]=
{
		{ FID_InputCombOrder, &CInputCombOrderField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqBulletinFieldUse[]=
{
		{ FID_Bulletin, &CBulletinField::m_Describe, 1,  1  }
};

TFieldUse RspBulletinFieldUse[]=
{
		{ FID_Bulletin, &CBulletinField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqInstrumentStatusUpdateFieldUse[]=
{
		{ FID_InstrumentStatus, &CInstrumentStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse RspInstrumentStatusUpdateFieldUse[]=
{
		{ FID_InstrumentStatus, &CInstrumentStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqForceUserExitFieldUse[]=
{
		{ FID_ForceUserExit, &CForceUserExitField::m_Describe, 1,  1  }
};

TFieldUse RspForceUserExitFieldUse[]=
{
		{ FID_ForceUserExit, &CForceUserExitField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqForceUserLogoutFieldUse[]=
{
		{ FID_ForceUserExit, &CForceUserExitField::m_Describe, 1,  1  }
};

TFieldUse RspForceUserLogoutFieldUse[]=
{
		{ FID_ForceUserExit, &CForceUserExitField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqExchangeDataSyncStatusUpdateFieldUse[]=
{
		{ FID_ExchangeDataSyncStatus, &CExchangeDataSyncStatusField::m_Describe, 1,  1  }
};

TFieldUse RspExchangeDataSyncStatusUpdateFieldUse[]=
{
		{ FID_ExchangeDataSyncStatus, &CExchangeDataSyncStatusField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqSGDataSyncStatusUpdateFieldUse[]=
{
		{ FID_SGDataSyncStatus, &CSGDataSyncStatusField::m_Describe, 1,  1  }
};

TFieldUse RspSGDataSyncStatusUpdateFieldUse[]=
{
		{ FID_SGDataSyncStatus, &CSGDataSyncStatusField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqExchangeDataSyncFieldUse[]=
{
		{ FID_ExchangeTradingDay, &CExchangeTradingDayField::m_Describe, 1,  1  }
};

TFieldUse RspExchangeDataSyncFieldUse[]=
{
		{ FID_ExchangeTradingDay, &CExchangeTradingDayField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqSgDataSyncFieldUse[]=
{
		{ FID_SettlementSession, &CSettlementSessionField::m_Describe, 1,  1  }
};

TFieldUse RspSgDataSyncFieldUse[]=
{
		{ FID_SettlementSession, &CSettlementSessionField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqInformationFieldUse[]=
{
		{ FID_Information, &CInformationField::m_Describe, 1,  1  }
};

TFieldUse RspInformationFieldUse[]=
{
		{ FID_Information, &CInformationField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqFrontStatusFieldUse[]=
{
		{ FID_FrontStatus, &CFrontStatusField::m_Describe, 1,  1  }
};

TFieldUse RspFrontStatusFieldUse[]=
{
		{ FID_FrontStatus, &CFrontStatusField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryPartAccountFieldUse[]=
{
		{ FID_QryPartAccount, &CQryPartAccountField::m_Describe, 1,  1  }
};

TFieldUse RspQryPartAccountFieldUse[]=
{
		{ FID_RspPartAccount, &CRspPartAccountField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryOrderFieldUse[]=
{
		{ FID_QryOrder, &CQryOrderField::m_Describe, 1,  1  }
};

TFieldUse RspQryOrderFieldUse[]=
{
		{ FID_Order, &COrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryQuoteFieldUse[]=
{
		{ FID_QryQuote, &CQryQuoteField::m_Describe, 1,  1  }
};

TFieldUse RspQryQuoteFieldUse[]=
{
		{ FID_Quote, &CQuoteField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryTradeFieldUse[]=
{
		{ FID_QryTrade, &CQryTradeField::m_Describe, 1,  1  }
};

TFieldUse RspQryTradeFieldUse[]=
{
		{ FID_Trade, &CTradeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryClientFieldUse[]=
{
		{ FID_QryClient, &CQryClientField::m_Describe, 1,  1  }
};

TFieldUse RspQryClientFieldUse[]=
{
		{ FID_RspClient, &CRspClientField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryPartPositionFieldUse[]=
{
		{ FID_QryPartPosition, &CQryPartPositionField::m_Describe, 1,  1  }
};

TFieldUse RspQryPartPositionFieldUse[]=
{
		{ FID_RspPartPosition, &CRspPartPositionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryClientPositionFieldUse[]=
{
		{ FID_QryClientPosition, &CQryClientPositionField::m_Describe, 1,  1  }
};

TFieldUse RspQryClientPositionFieldUse[]=
{
		{ FID_RspClientPosition, &CRspClientPositionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryInstrumentFieldUse[]=
{
		{ FID_QryInstrument, &CQryInstrumentField::m_Describe, 1,  1  }
};

TFieldUse RspQryInstrumentFieldUse[]=
{
		{ FID_RspInstrument, &CRspInstrumentField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryInstrumentStatusFieldUse[]=
{
		{ FID_QryInstrumentStatus, &CQryInstrumentStatusField::m_Describe, 1,  1  }
};

TFieldUse RspQryInstrumentStatusFieldUse[]=
{
		{ FID_InstrumentStatus, &CInstrumentStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQrySGDataSyncStatusFieldUse[]=
{
		{ FID_QrySGDataSyncStatus, &CQrySGDataSyncStatusField::m_Describe, 1,  1  }
};

TFieldUse RspQrySGDataSyncStatusFieldUse[]=
{
		{ FID_SGDataSyncStatus, &CSGDataSyncStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryHedgeVolumeFieldUse[]=
{
		{ FID_QryHedgeVolume, &CQryHedgeVolumeField::m_Describe, 1,  1  }
};

TFieldUse RspQryHedgeVolumeFieldUse[]=
{
		{ FID_HedgeVolume, &CHedgeVolumeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryCombOrderFieldUse[]=
{
		{ FID_QryCombOrder, &CQryCombOrderField::m_Describe, 1,  1  }
};

TFieldUse RspQryCombOrderFieldUse[]=
{
		{ FID_CombOrder, &CCombOrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryMarketDataFieldUse[]=
{
		{ FID_QryMarketData, &CQryMarketDataField::m_Describe, 1,  1  }
};

TFieldUse RspQryMarketDataFieldUse[]=
{
		{ FID_MarketData, &CMarketDataField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ReqQryBulletinFieldUse[]=
{
		{ FID_QryBulletin, &CQryBulletinField::m_Describe, 1,  1  }
};

TFieldUse RspQryBulletinFieldUse[]=
{
		{ FID_Bulletin, &CBulletinField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryUserSessionFieldUse[]=
{
		{ FID_QryUserSession, &CQryUserSessionField::m_Describe, 1,  1  }
};

TFieldUse RspQryUserSessionFieldUse[]=
{
		{ FID_UserSession, &CUserSessionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryUserFieldUse[]=
{
		{ FID_QryUser, &CQryUserField::m_Describe, 1,  1  }
};

TFieldUse RspQryUserFieldUse[]=
{
		{ FID_User, &CUserField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryParticipantFieldUse[]=
{
		{ FID_QryParticipant, &CQryParticipantField::m_Describe, 1,  1  }
};

TFieldUse RspQryParticipantFieldUse[]=
{
		{ FID_Participant, &CParticipantField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryMBLMarketDataFieldUse[]=
{
		{ FID_QryMBLMarketData, &CQryMBLMarketDataField::m_Describe, 1,  1  }
};

TFieldUse RspQryMBLMarketDataFieldUse[]=
{
		{ FID_MBLMarketData, &CMBLMarketDataField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryInformationFieldUse[]=
{
		{ FID_QryInformation, &CQryInformationField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse RspQryInformationFieldUse[]=
{
		{ FID_Information, &CInformationField::m_Describe, 1,  1  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryExchangeStatusFieldUse[]=
{
		{ FID_QryExchangeStatus, &CQryExchangeStatusField::m_Describe, 1,  1  }
};

TFieldUse RspQryExchangeStatusFieldUse[]=
{
		{ FID_ExchangeStatus, &CExchangeStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryExchangeDataSyncStatusFieldUse[]=
{
		{ FID_QryExchangeDataSyncStatus, &CQryExchangeDataSyncStatusField::m_Describe, 1,  1  }
};

TFieldUse RspQryExchangeDataSyncStatusFieldUse[]=
{
		{ FID_ExchangeDataSyncStatus, &CExchangeDataSyncStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQrySettlementGroupStatusFieldUse[]=
{
		{ FID_QrySettlementGroupStatus, &CQrySettlementGroupStatusField::m_Describe, 1,  1  }
};

TFieldUse RspQrySettlementGroupStatusFieldUse[]=
{
		{ FID_SettlementGroupStatus, &CSettlementGroupStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse ReqQryCreditLimitFieldUse[]=
{
		{ FID_QryCreditLimit, &CQryCreditLimitField::m_Describe, 1,  1  }
};

TFieldUse RspQryCreditLimitFieldUse[]=
{
		{ FID_CreditLimit, &CCreditLimitField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
			,
		{ FID_RspInfo, &CRspInfoField::m_Describe, 1,  1  }
};

TFieldUse DbAccountDepositFieldUse[]=
{
		{ FID_DbmtAccountDeposit, &CDbmtAccountDepositField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdateAllInstrumentStatusFieldUse[]=
{
		{ FID_DbmtUpdateAllInstrumentStatus, &CDbmtUpdateAllInstrumentStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsClientFieldUse[]=
{
		{ FID_DbmtClient, &CDbmtClientField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdClientFieldUse[]=
{
		{ FID_DbmtClient, &CDbmtClientField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsPartClientFieldUse[]=
{
		{ FID_DbmtPartClient, &CDbmtPartClientField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelPartClientFieldUse[]=
{
		{ FID_DbmtPartClient, &CDbmtPartClientField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsCurrPartPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrPartPosiLimitDetail, &CDbmtCurrPartPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdCurrPartPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrPartPosiLimitDetail, &CDbmtCurrPartPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelCurrPartPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrPartPosiLimitDetail, &CDbmtCurrPartPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsCurrClientPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrClientPosiLimitDetail, &CDbmtCurrClientPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdCurrClientPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrClientPosiLimitDetail, &CDbmtCurrClientPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelCurrClientPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrClientPosiLimitDetail, &CDbmtCurrClientPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsCurrSpecialPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrSpecialPosiLimitDetail, &CDbmtCurrSpecialPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdCurrSpecialPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrSpecialPosiLimitDetail, &CDbmtCurrSpecialPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelCurrSpecialPosiLimitDetailFieldUse[]=
{
		{ FID_DbmtCurrSpecialPosiLimitDetail, &CDbmtCurrSpecialPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsHedgeDetailFieldUse[]=
{
		{ FID_DbmtHedgeDetail, &CDbmtHedgeDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdCurrHedgeFieldUse[]=
{
		{ FID_DbmtCurrHedge, &CDbmtCurrHedgeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsUserFieldUse[]=
{
		{ FID_DbmtUser, &CDbmtUserField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdUserFieldUse[]=
{
		{ FID_DbmtUser, &CDbmtUserField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsPartProductRightFieldUse[]=
{
		{ FID_DbmtPartProductRight, &CDbmtPartProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdPartProductRightFieldUse[]=
{
		{ FID_DbmtPartProductRight, &CDbmtPartProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelPartProductRightFieldUse[]=
{
		{ FID_DbmtPartProductRight, &CDbmtPartProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsClientProductRightFieldUse[]=
{
		{ FID_DbmtClientProductRight, &CDbmtClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdClientProductRightFieldUse[]=
{
		{ FID_DbmtClientProductRight, &CDbmtClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelClientProductRightFieldUse[]=
{
		{ FID_DbmtClientProductRight, &CDbmtClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsPartInstrumentRightFieldUse[]=
{
		{ FID_DbmtPartInstrumentRight, &CDbmtPartInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdPartInstrumentRightFieldUse[]=
{
		{ FID_DbmtPartInstrumentRight, &CDbmtPartInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelPartInstrumentRightFieldUse[]=
{
		{ FID_DbmtPartInstrumentRight, &CDbmtPartInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsClientInstrumentRightFieldUse[]=
{
		{ FID_DbmtClientInstrumentRight, &CDbmtClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdClientInstrumentRightFieldUse[]=
{
		{ FID_DbmtClientInstrumentRight, &CDbmtClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelClientInstrumentRightFieldUse[]=
{
		{ FID_DbmtClientInstrumentRight, &CDbmtClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsPartClientProductRightFieldUse[]=
{
		{ FID_DbmtPartClientProductRight, &CDbmtPartClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdPartClientProductRightFieldUse[]=
{
		{ FID_DbmtPartClientProductRight, &CDbmtPartClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelPartClientProductRightFieldUse[]=
{
		{ FID_DbmtPartClientProductRight, &CDbmtPartClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsPartClientInstrumentRightFieldUse[]=
{
		{ FID_DbmtPartClientInstrumentRight, &CDbmtPartClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdPartClientInstrumentRightFieldUse[]=
{
		{ FID_DbmtPartClientInstrumentRight, &CDbmtPartClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelPartClientInstrumentRightFieldUse[]=
{
		{ FID_DbmtPartClientInstrumentRight, &CDbmtPartClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsCurrMarginRateDetailFieldUse[]=
{
		{ FID_DbmtCurrMarginRateDetail, &CDbmtCurrMarginRateDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdCurrMarginRateDetailFieldUse[]=
{
		{ FID_DbmtCurrMarginRateDetail, &CDbmtCurrMarginRateDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelCurrMarginRateDetailFieldUse[]=
{
		{ FID_DbmtCurrMarginRateDetail, &CDbmtCurrMarginRateDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdMarketDataFieldUse[]=
{
		{ FID_DbmtMarketData, &CDbmtMarketDataField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsUserIPFieldUse[]=
{
		{ FID_DbmtUserIP, &CDbmtUserIPField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelUserIPFieldUse[]=
{
		{ FID_DbmtUserIP, &CDbmtUserIPField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsCurrPriceBandingFieldUse[]=
{
		{ FID_DbmtCurrPriceBanding, &CDbmtCurrPriceBandingField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbUpdCurrPriceBandingFieldUse[]=
{
		{ FID_DbmtCurrPriceBanding, &CDbmtCurrPriceBandingField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelCurrPriceBandingFieldUse[]=
{
		{ FID_DbmtCurrPriceBanding, &CDbmtCurrPriceBandingField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbInsPartTopicSubscribeFieldUse[]=
{
		{ FID_DbmtPartTopicSubscribe, &CDbmtPartTopicSubscribeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse DbDelPartTopicSubscribeFieldUse[]=
{
		{ FID_DbmtPartTopicSubscribe, &CDbmtPartTopicSubscribeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfTimeSyncFieldUse[]=
{
		{ FID_CurrentTime, &CCurrentTimeField::m_Describe, 1,  1  }
};

TFieldUse NtfCommPhaseChangeFieldUse[]=
{
		{ FID_CommPhase, &CCommPhaseField::m_Describe, 1,  1  }
};

TFieldUse NtfDataCenterDescFieldUse[]=
{
		{ FID_DataCenterDesc, &CDataCenterDescField::m_Describe, 1,  1  }
};

TFieldUse NtfInsInstrumentFieldUse[]=
{
		{ FID_Instrument, &CInstrumentField::m_Describe, 1,  1  }
};

TFieldUse NtfDelInstrumentFieldUse[]=
{
		{ FID_Instrument, &CInstrumentField::m_Describe, 1,  1  }
};

TFieldUse NtfInsCombinationLegFieldUse[]=
{
		{ FID_CombinationLeg, &CCombinationLegField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfDelCombinationLegFieldUse[]=
{
		{ FID_CombinationLeg, &CCombinationLegField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfAliasDefineFieldUse[]=
{
		{ FID_AliasDefine, &CAliasDefineField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfOrderFieldUse[]=
{
		{ FID_Order, &COrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfTradeFieldUse[]=
{
		{ FID_Trade, &CTradeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfQuoteFieldUse[]=
{
		{ FID_Quote, &CQuoteField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfExecOrderFieldUse[]=
{
		{ FID_ExecOrder, &CExecOrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfCombOrderFieldUse[]=
{
		{ FID_CombOrder, &CCombOrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfInstrumentStatusUpdateFieldUse[]=
{
		{ FID_InstrumentStatus, &CInstrumentStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfDelUserSessionFieldUse[]=
{
		{ FID_UserSession, &CUserSessionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfBulletinFieldUse[]=
{
		{ FID_Bulletin, &CBulletinField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfMarketDataFieldUse[]=
{
		{ FID_MarketData, &CMarketDataField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfDepthMarketDataFieldUse[]=
{
		{ FID_MarketDataBase, &CMarketDataBaseField::m_Describe, 0,  1  }
			,
		{ FID_MarketDataStatic, &CMarketDataStaticField::m_Describe, 0,  1  }
			,
		{ FID_MarketDataLastMatch, &CMarketDataLastMatchField::m_Describe, 0,  1  }
			,
		{ FID_MarketDataBestPrice, &CMarketDataBestPriceField::m_Describe, 0,  1  }
			,
		{ FID_MarketDataBid23, &CMarketDataBid23Field::m_Describe, 0,  1  }
			,
		{ FID_MarketDataAsk23, &CMarketDataAsk23Field::m_Describe, 0,  1  }
			,
		{ FID_MarketDataBid45, &CMarketDataBid45Field::m_Describe, 0,  1  }
			,
		{ FID_MarketDataAsk45, &CMarketDataAsk45Field::m_Describe, 0,  1  }
			,
		{ FID_MarketDataUpdateTime, &CMarketDataUpdateTimeField::m_Describe, 1,  1  }
};

TFieldUse NtfAdminOrderFieldUse[]=
{
		{ FID_AdminOrder, &CAdminOrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse ExchangeDataSyncStartFieldUse[]=
{
		{ FID_ExchangeTradingDay, &CExchangeTradingDayField::m_Describe, 1,  1  }
};

TFieldUse ExchangeDataSyncEndFieldUse[]=
{
		{ FID_ExchangeTradingDay, &CExchangeTradingDayField::m_Describe, 1,  1  }
};

TFieldUse InitExchangeFieldUse[]=
{
		{ FID_Exchange, &CExchangeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitSettlementGroupFieldUse[]=
{
		{ FID_SettlementGroup, &CSettlementGroupField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitMarketFieldUse[]=
{
		{ FID_Market, &CMarketField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitMarketProductFieldUse[]=
{
		{ FID_MarketProduct, &CMarketProductField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitMarketProductGroupFieldUse[]=
{
		{ FID_MarketProductGroup, &CMarketProductGroupField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitMarketDataTopicFieldUse[]=
{
		{ FID_MarketDataTopic, &CMarketDataTopicField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartTopicSubscribeFieldUse[]=
{
		{ FID_PartTopicSubscribe, &CPartTopicSubscribeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitParticipantFieldUse[]=
{
		{ FID_Participant, &CParticipantField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitUserFieldUse[]=
{
		{ FID_User, &CUserField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitClientFieldUse[]=
{
		{ FID_Client, &CClientField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartClientFieldUse[]=
{
		{ FID_PartClient, &CPartClientField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitUserIPFieldUse[]=
{
		{ FID_UserIP, &CUserIPField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitMdPubStatusFieldUse[]=
{
		{ FID_MdPubStatus, &CMdPubStatusField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitAliasDefineFieldUse[]=
{
		{ FID_AliasDefine, &CAliasDefineField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitClearingTradingPartFieldUse[]=
{
		{ FID_ClearingTradingPart, &CClearingTradingPartField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitUserFunctionRightFieldUse[]=
{
		{ FID_UserFunctionRight, &CUserFunctionRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitAccountFieldUse[]=
{
		{ FID_Account, &CAccountField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitUserCommFluxFieldUse[]=
{
		{ FID_UserCommFlux, &CUserCommFluxField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse SettlementGroupDataSyncStartFieldUse[]=
{
		{ FID_SettlementSession, &CSettlementSessionField::m_Describe, 1,  1  }
};

TFieldUse SettlementGroupDataSyncEndFieldUse[]=
{
		{ FID_SettlementSession, &CSettlementSessionField::m_Describe, 1,  1  }
};

TFieldUse InitInstrumentFieldUse[]=
{
		{ FID_Instrument, &CInstrumentField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCombinationLegFieldUse[]=
{
		{ FID_CombinationLeg, &CCombinationLegField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartRoleAccountFieldUse[]=
{
		{ FID_PartRoleAccount, &CPartRoleAccountField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartProductRoleFieldUse[]=
{
		{ FID_PartProductRole, &CPartProductRoleField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartProductRightFieldUse[]=
{
		{ FID_PartProductRight, &CPartProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartInstrumentRightFieldUse[]=
{
		{ FID_PartInstrumentRight, &CPartInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitClientProductRightFieldUse[]=
{
		{ FID_ClientProductRight, &CClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitClientInstrumentRightFieldUse[]=
{
		{ FID_ClientInstrumentRight, &CClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartClientProductRightFieldUse[]=
{
		{ FID_PartClientProductRight, &CPartClientProductRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartClientInstrumentRightFieldUse[]=
{
		{ FID_PartClientInstrumentRight, &CPartClientInstrumentRightField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrProductPropertyFieldUse[]=
{
		{ FID_CurrProductProperty, &CCurrProductPropertyField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrInstrumentPropertyFieldUse[]=
{
		{ FID_CurrInstrumentProperty, &CCurrInstrumentPropertyField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrPriceBandingFieldUse[]=
{
		{ FID_CurrPriceBanding, &CCurrPriceBandingField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrMarginRateFieldUse[]=
{
		{ FID_CurrMarginRate, &CCurrMarginRateField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrMarginRateDetailFieldUse[]=
{
		{ FID_CurrMarginRateDetail, &CCurrMarginRateDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrPartPosiLimitFieldUse[]=
{
		{ FID_CurrPartPosiLimit, &CCurrPartPosiLimitField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrPartPosiLimitDetailFieldUse[]=
{
		{ FID_CurrPartPosiLimitDetail, &CCurrPartPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrClientPosiLimitFieldUse[]=
{
		{ FID_CurrClientPosiLimit, &CCurrClientPosiLimitField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrClientPosiLimitDetailFieldUse[]=
{
		{ FID_CurrClientPosiLimitDetail, &CCurrClientPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrSpecialPosiLimitFieldUse[]=
{
		{ FID_CurrSpecialPosiLimit, &CCurrSpecialPosiLimitField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrSpecialPosiLimitDetailFieldUse[]=
{
		{ FID_CurrSpecialPosiLimitDetail, &CCurrSpecialPosiLimitDetailField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrHedgeRuleFieldUse[]=
{
		{ FID_CurrHedgeRule, &CCurrHedgeRuleField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrTradingSegmentAttrFieldUse[]=
{
		{ FID_CurrTradingSegmentAttr, &CCurrTradingSegmentAttrField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrFuseFieldUse[]=
{
		{ FID_CurrFuse, &CCurrFuseField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitTradingAccountFieldUse[]=
{
		{ FID_TradingAccount, &CTradingAccountField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitPartPositionFieldUse[]=
{
		{ FID_PartPosition, &CPartPositionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitClientPositionFieldUse[]=
{
		{ FID_ClientPosition, &CClientPositionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitHedgeVolumeFieldUse[]=
{
		{ FID_HedgeVolume, &CHedgeVolumeField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitRemainOrderFieldUse[]=
{
		{ FID_RemainOrder, &CRemainOrderField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitMarketDataFieldUse[]=
{
		{ FID_MarketData, &CMarketDataField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitBaseReserveAccountFieldUse[]=
{
		{ FID_BaseReserveAccount, &CBaseReserveAccountField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse InitCurrInstrumentOptionFieldUse[]=
{
		{ FID_CurrInstrumentOption, &CCurrInstrumentOptionField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};

TFieldUse NtfInputMarketDataFieldUse[]=
{
		{ FID_MarketData, &CMarketDataField::m_Describe, 1,  UNLIMITED_FIELD_OCCUR  }
};


TPackageDefine XTPPackageDefines[]=
{
	{ TID_Nop, 1, NopFieldUse, "Nop", "�ղ���" }
		,
	{ TID_RspError, 1, RspErrorFieldUse, "RspError", "����Ӧ��" }
		,
	{ TID_ReqUserLogin, 1, ReqUserLoginFieldUse, "ReqUserLogin", "�û���¼����" }
		,
	{ TID_RspUserLogin, 2, RspUserLoginFieldUse, "RspUserLogin", "�û���¼Ӧ��" }
		,
	{ TID_ReqUserLogout, 1, ReqUserLogoutFieldUse, "ReqUserLogout", "�û��˳�����" }
		,
	{ TID_RspUserLogout, 2, RspUserLogoutFieldUse, "RspUserLogout", "�û��˳�Ӧ��" }
		,
	{ TID_ReqOrderInsert, 1, ReqOrderInsertFieldUse, "ReqOrderInsert", "����¼������" }
		,
	{ TID_RspOrderInsert, 2, RspOrderInsertFieldUse, "RspOrderInsert", "����¼��Ӧ��" }
		,
	{ TID_ReqOrderAction, 1, ReqOrderActionFieldUse, "ReqOrderAction", "������������" }
		,
	{ TID_RspOrderAction, 2, RspOrderActionFieldUse, "RspOrderAction", "��������Ӧ��" }
		,
	{ TID_ReqQuoteInsert, 1, ReqQuoteInsertFieldUse, "ReqQuoteInsert", "����¼������" }
		,
	{ TID_RspQuoteInsert, 2, RspQuoteInsertFieldUse, "RspQuoteInsert", "����¼��Ӧ��" }
		,
	{ TID_ReqQuoteAction, 1, ReqQuoteActionFieldUse, "ReqQuoteAction", "���۲�������" }
		,
	{ TID_RspQuoteAction, 2, RspQuoteActionFieldUse, "RspQuoteAction", "���۲���Ӧ��" }
		,
	{ TID_ReqOTCOrderInsert, 1, ReqOTCOrderInsertFieldUse, "ReqOTCOrderInsert", "OTC����¼������" }
		,
	{ TID_RspOTCOrderInsert, 2, RspOTCOrderInsertFieldUse, "RspOTCOrderInsert", "OTC����¼��Ӧ��" }
		,
	{ TID_ReqUserPasswordUpdate, 1, ReqUserPasswordUpdateFieldUse, "ReqUserPasswordUpdate", "�û������޸�����" }
		,
	{ TID_RspUserPasswordUpdate, 2, RspUserPasswordUpdateFieldUse, "RspUserPasswordUpdate", "�û������޸�Ӧ��" }
		,
	{ TID_ReqExecOrderInsert, 1, ReqExecOrderInsertFieldUse, "ReqExecOrderInsert", "ִ������¼������" }
		,
	{ TID_RspExecOrderInsert, 2, RspExecOrderInsertFieldUse, "RspExecOrderInsert", "ִ������¼��Ӧ��" }
		,
	{ TID_ReqExecOrderAction, 1, ReqExecOrderActionFieldUse, "ReqExecOrderAction", "ִ�������������" }
		,
	{ TID_RspExecOrderAction, 2, RspExecOrderActionFieldUse, "RspExecOrderAction", "ִ���������Ӧ��" }
		,
	{ TID_ReqAdminOrderInsert, 1, ReqAdminOrderInsertFieldUse, "ReqAdminOrderInsert", "������¼������" }
		,
	{ TID_RspAdminOrderInsert, 2, RspAdminOrderInsertFieldUse, "RspAdminOrderInsert", "������¼��Ӧ��" }
		,
	{ TID_ReqCombOrderInsert, 1, ReqCombOrderInsertFieldUse, "ReqCombOrderInsert", "��ϱ���¼������" }
		,
	{ TID_RspCombOrderInsert, 2, RspCombOrderInsertFieldUse, "RspCombOrderInsert", "��ϱ���¼��Ӧ��" }
		,
	{ TID_ReqBulletin, 1, ReqBulletinFieldUse, "ReqBulletin", "��������������" }
		,
	{ TID_RspBulletin, 2, RspBulletinFieldUse, "RspBulletin", "��������������Ӧ��" }
		,
	{ TID_ReqInstrumentStatusUpdate, 1, ReqInstrumentStatusUpdateFieldUse, "ReqInstrumentStatusUpdate", "��Լ����״̬�ı�����" }
		,
	{ TID_RspInstrumentStatusUpdate, 2, RspInstrumentStatusUpdateFieldUse, "RspInstrumentStatusUpdate", "��Լ����״̬�ı�Ӧ��" }
		,
	{ TID_ReqForceUserExit, 1, ReqForceUserExitFieldUse, "ReqForceUserExit", "ǿ���û��˳�����" }
		,
	{ TID_RspForceUserExit, 2, RspForceUserExitFieldUse, "RspForceUserExit", "ǿ���û��˳�Ӧ��" }
		,
	{ TID_ReqForceUserLogout, 1, ReqForceUserLogoutFieldUse, "ReqForceUserLogout", "�û��Ựɾ������" }
		,
	{ TID_RspForceUserLogout, 2, RspForceUserLogoutFieldUse, "RspForceUserLogout", "�û��Ựɾ��Ӧ��" }
		,
	{ TID_ReqExchangeDataSyncStatusUpdate, 1, ReqExchangeDataSyncStatusUpdateFieldUse, "ReqExchangeDataSyncStatusUpdate", "����������ͬ��״̬�ı�����" }
		,
	{ TID_RspExchangeDataSyncStatusUpdate, 2, RspExchangeDataSyncStatusUpdateFieldUse, "RspExchangeDataSyncStatusUpdate", "����������ͬ��״̬�ı�Ӧ��" }
		,
	{ TID_ReqSGDataSyncStatusUpdate, 1, ReqSGDataSyncStatusUpdateFieldUse, "ReqSGDataSyncStatusUpdate", "����������ͬ��״̬�ı�����" }
		,
	{ TID_RspSGDataSyncStatusUpdate, 2, RspSGDataSyncStatusUpdateFieldUse, "RspSGDataSyncStatusUpdate", "����������ͬ��״̬�ı�Ӧ��" }
		,
	{ TID_ReqExchangeDataSync, 1, ReqExchangeDataSyncFieldUse, "ReqExchangeDataSync", "����������ͬ������" }
		,
	{ TID_RspExchangeDataSync, 2, RspExchangeDataSyncFieldUse, "RspExchangeDataSync", "����������ͬ��Ӧ��" }
		,
	{ TID_ReqSgDataSync, 1, ReqSgDataSyncFieldUse, "ReqSgDataSync", "����������ͬ������" }
		,
	{ TID_RspSgDataSync, 2, RspSgDataSyncFieldUse, "RspSgDataSync", "����������ͬ��Ӧ��" }
		,
	{ TID_ReqInformation, 1, ReqInformationFieldUse, "ReqInformation", "��������Ϣ����" }
		,
	{ TID_RspInformation, 2, RspInformationFieldUse, "RspInformation", "������������ϢӦ��" }
		,
	{ TID_ReqFrontStatus, 1, ReqFrontStatusFieldUse, "ReqFrontStatus", "ǰ��״̬��������" }
		,
	{ TID_RspFrontStatus, 2, RspFrontStatusFieldUse, "RspFrontStatus", "ǰ��״̬����Ӧ��" }
		,
	{ TID_ReqQryPartAccount, 1, ReqQryPartAccountFieldUse, "ReqQryPartAccount", "��Ա�ʽ��ѯ����" }
		,
	{ TID_RspQryPartAccount, 2, RspQryPartAccountFieldUse, "RspQryPartAccount", "��Ա�ʽ��ѯӦ��" }
		,
	{ TID_ReqQryOrder, 1, ReqQryOrderFieldUse, "ReqQryOrder", "������ѯ����" }
		,
	{ TID_RspQryOrder, 2, RspQryOrderFieldUse, "RspQryOrder", "������ѯӦ��" }
		,
	{ TID_ReqQryQuote, 1, ReqQryQuoteFieldUse, "ReqQryQuote", "���۲�ѯ����" }
		,
	{ TID_RspQryQuote, 2, RspQryQuoteFieldUse, "RspQryQuote", "���۲�ѯӦ��" }
		,
	{ TID_ReqQryTrade, 1, ReqQryTradeFieldUse, "ReqQryTrade", "�ɽ�����ѯ����" }
		,
	{ TID_RspQryTrade, 2, RspQryTradeFieldUse, "RspQryTrade", "�ɽ�����ѯӦ��" }
		,
	{ TID_ReqQryClient, 1, ReqQryClientFieldUse, "ReqQryClient", "��Ա�ͻ���ѯ����" }
		,
	{ TID_RspQryClient, 2, RspQryClientFieldUse, "RspQryClient", "��Ա�ͻ���ѯӦ��" }
		,
	{ TID_ReqQryPartPosition, 1, ReqQryPartPositionFieldUse, "ReqQryPartPosition", "��Ա�ֲֲ�ѯ����" }
		,
	{ TID_RspQryPartPosition, 2, RspQryPartPositionFieldUse, "RspQryPartPosition", "��Ա�ֲֲ�ѯӦ��" }
		,
	{ TID_ReqQryClientPosition, 1, ReqQryClientPositionFieldUse, "ReqQryClientPosition", "�ͻ��ֲֲ�ѯ����" }
		,
	{ TID_RspQryClientPosition, 2, RspQryClientPositionFieldUse, "RspQryClientPosition", "�ͻ��ֲֲ�ѯӦ��" }
		,
	{ TID_ReqQryInstrument, 1, ReqQryInstrumentFieldUse, "ReqQryInstrument", "��Լ��ѯ����" }
		,
	{ TID_RspQryInstrument, 2, RspQryInstrumentFieldUse, "RspQryInstrument", "��Լ��ѯӦ��" }
		,
	{ TID_ReqQryInstrumentStatus, 1, ReqQryInstrumentStatusFieldUse, "ReqQryInstrumentStatus", "��Լ����״̬��ѯ����" }
		,
	{ TID_RspQryInstrumentStatus, 2, RspQryInstrumentStatusFieldUse, "RspQryInstrumentStatus", "��Լ����״̬��ѯӦ��" }
		,
	{ TID_ReqQrySGDataSyncStatus, 1, ReqQrySGDataSyncStatusFieldUse, "ReqQrySGDataSyncStatus", "����������ͬ��״̬��ѯ����" }
		,
	{ TID_RspQrySGDataSyncStatus, 2, RspQrySGDataSyncStatusFieldUse, "RspQrySGDataSyncStatus", "����������ͬ��״̬��ѯӦ��" }
		,
	{ TID_ReqQryHedgeVolume, 1, ReqQryHedgeVolumeFieldUse, "ReqQryHedgeVolume", "��ֵ��Ȳ�ѯ" }
		,
	{ TID_RspQryHedgeVolume, 2, RspQryHedgeVolumeFieldUse, "RspQryHedgeVolume", "��ֵ���Ӧ��" }
		,
	{ TID_ReqQryCombOrder, 1, ReqQryCombOrderFieldUse, "ReqQryCombOrder", "��ϱ�����ѯ����" }
		,
	{ TID_RspQryCombOrder, 2, RspQryCombOrderFieldUse, "RspQryCombOrder", "��ϱ�����ѯӦ��" }
		,
	{ TID_ReqQryMarketData, 1, ReqQryMarketDataFieldUse, "ReqQryMarketData", "��ͨ�����ѯ����" }
		,
	{ TID_RspQryMarketData, 2, RspQryMarketDataFieldUse, "RspQryMarketData", "��ͨ�����ѯӦ��" }
		,
	{ TID_ReqQryBulletin, 1, ReqQryBulletinFieldUse, "ReqQryBulletin", "�����������ѯ����" }
		,
	{ TID_RspQryBulletin, 2, RspQryBulletinFieldUse, "RspQryBulletin", "�����������ѯӦ��" }
		,
	{ TID_ReqQryUserSession, 1, ReqQryUserSessionFieldUse, "ReqQryUserSession", "�û����߲�ѯ����" }
		,
	{ TID_RspQryUserSession, 2, RspQryUserSessionFieldUse, "RspQryUserSession", "�û����߲�ѯӦ��" }
		,
	{ TID_ReqQryUser, 1, ReqQryUserFieldUse, "ReqQryUser", "�û���ѯ����" }
		,
	{ TID_RspQryUser, 2, RspQryUserFieldUse, "RspQryUser", "�û���ѯӦ��" }
		,
	{ TID_ReqQryParticipant, 1, ReqQryParticipantFieldUse, "ReqQryParticipant", "��Ա��ѯ����" }
		,
	{ TID_RspQryParticipant, 2, RspQryParticipantFieldUse, "RspQryParticipant", "��Ա��ѯӦ��" }
		,
	{ TID_ReqQryMBLMarketData, 1, ReqQryMBLMarketDataFieldUse, "ReqQryMBLMarketData", "��Լ��λ��ѯ" }
		,
	{ TID_RspQryMBLMarketData, 2, RspQryMBLMarketDataFieldUse, "RspQryMBLMarketData", "��Լ��λ��ѯӦ��" }
		,
	{ TID_ReqQryInformation, 1, ReqQryInformationFieldUse, "ReqQryInformation", "��Ϣ��ѯ" }
		,
	{ TID_RspQryInformation, 2, RspQryInformationFieldUse, "RspQryInformation", "��Ϣ��ѯӦ��" }
		,
	{ TID_ReqQryExchangeStatus, 1, ReqQryExchangeStatusFieldUse, "ReqQryExchangeStatus", "������״̬��ѯ" }
		,
	{ TID_RspQryExchangeStatus, 2, RspQryExchangeStatusFieldUse, "RspQryExchangeStatus", "������״̬Ӧ��" }
		,
	{ TID_ReqQryExchangeDataSyncStatus, 1, ReqQryExchangeDataSyncStatusFieldUse, "ReqQryExchangeDataSyncStatus", "����������ͬ��״̬��ѯ" }
		,
	{ TID_RspQryExchangeDataSyncStatus, 2, RspQryExchangeDataSyncStatusFieldUse, "RspQryExchangeDataSyncStatus", "����������ͬ��״̬Ӧ��" }
		,
	{ TID_ReqQrySettlementGroupStatus, 1, ReqQrySettlementGroupStatusFieldUse, "ReqQrySettlementGroupStatus", "������״̬��ѯ" }
		,
	{ TID_RspQrySettlementGroupStatus, 2, RspQrySettlementGroupStatusFieldUse, "RspQrySettlementGroupStatus", "������״̬Ӧ��" }
		,
	{ TID_ReqQryCreditLimit, 1, ReqQryCreditLimitFieldUse, "ReqQryCreditLimit", "�����޶��ѯ����" }
		,
	{ TID_RspQryCreditLimit, 2, RspQryCreditLimitFieldUse, "RspQryCreditLimit", "�����޶��ѯӦ��" }
		,
	{ TID_DbAccountDeposit, 1, DbAccountDepositFieldUse, "DbAccountDeposit", "�ʽ��ʻ����" }
		,
	{ TID_DbUpdateAllInstrumentStatus, 1, DbUpdateAllInstrumentStatusFieldUse, "DbUpdateAllInstrumentStatus", "�������к�Լ״̬" }
		,
	{ TID_DbInsClient, 1, DbInsClientFieldUse, "DbInsClient", "���ӿͻ�" }
		,
	{ TID_DbUpdClient, 1, DbUpdClientFieldUse, "DbUpdClient", "�޸Ŀͻ�" }
		,
	{ TID_DbInsPartClient, 1, DbInsPartClientFieldUse, "DbInsPartClient", "���ӻ�Ա�ͻ���ϵ" }
		,
	{ TID_DbDelPartClient, 1, DbDelPartClientFieldUse, "DbDelPartClient", "ɾ����Ա�ͻ���ϵ" }
		,
	{ TID_DbInsCurrPartPosiLimitDetail, 1, DbInsCurrPartPosiLimitDetailFieldUse, "DbInsCurrPartPosiLimitDetail", "���ӻ�Ա��Լ�ֲ��޶�" }
		,
	{ TID_DbUpdCurrPartPosiLimitDetail, 1, DbUpdCurrPartPosiLimitDetailFieldUse, "DbUpdCurrPartPosiLimitDetail", "�޸Ļ�Ա��Լ�ֲ��޶�" }
		,
	{ TID_DbDelCurrPartPosiLimitDetail, 1, DbDelCurrPartPosiLimitDetailFieldUse, "DbDelCurrPartPosiLimitDetail", "ɾ����Ա��Լ�ֲ��޶�" }
		,
	{ TID_DbInsCurrClientPosiLimitDetail, 1, DbInsCurrClientPosiLimitDetailFieldUse, "DbInsCurrClientPosiLimitDetail", "���ӿͻ���Լ�ֲ��޶�" }
		,
	{ TID_DbUpdCurrClientPosiLimitDetail, 1, DbUpdCurrClientPosiLimitDetailFieldUse, "DbUpdCurrClientPosiLimitDetail", "�޸Ŀͻ���Լ�ֲ��޶�" }
		,
	{ TID_DbDelCurrClientPosiLimitDetail, 1, DbDelCurrClientPosiLimitDetailFieldUse, "DbDelCurrClientPosiLimitDetail", "ɾ���ͻ���Լ�ֲ��޶�" }
		,
	{ TID_DbInsCurrSpecialPosiLimitDetail, 1, DbInsCurrSpecialPosiLimitDetailFieldUse, "DbInsCurrSpecialPosiLimitDetail", "��������ͻ���Լ�ֲ��޶�" }
		,
	{ TID_DbUpdCurrSpecialPosiLimitDetail, 1, DbUpdCurrSpecialPosiLimitDetailFieldUse, "DbUpdCurrSpecialPosiLimitDetail", "�޸�����ͻ���Լ�ֲ��޶�" }
		,
	{ TID_DbDelCurrSpecialPosiLimitDetail, 1, DbDelCurrSpecialPosiLimitDetailFieldUse, "DbDelCurrSpecialPosiLimitDetail", "ɾ������ͻ���Լ�ֲ��޶�" }
		,
	{ TID_DbInsHedgeDetail, 1, DbInsHedgeDetailFieldUse, "DbInsHedgeDetail", "���ӱ�ֵ���" }
		,
	{ TID_DbUpdCurrHedge, 1, DbUpdCurrHedgeFieldUse, "DbUpdCurrHedge", "���µ�ǰ��ֵ���" }
		,
	{ TID_DbInsUser, 1, DbInsUserFieldUse, "DbInsUser", "���ӽ����û�" }
		,
	{ TID_DbUpdUser, 1, DbUpdUserFieldUse, "DbUpdUser", "�޸Ľ����û�" }
		,
	{ TID_DbInsPartProductRight, 1, DbInsPartProductRightFieldUse, "DbInsPartProductRight", "���ӻ�Ա��ƷȨ��" }
		,
	{ TID_DbUpdPartProductRight, 1, DbUpdPartProductRightFieldUse, "DbUpdPartProductRight", "�޸Ļ�Ա��ƷȨ��" }
		,
	{ TID_DbDelPartProductRight, 1, DbDelPartProductRightFieldUse, "DbDelPartProductRight", "ɾ����Ա��ƷȨ��" }
		,
	{ TID_DbInsClientProductRight, 1, DbInsClientProductRightFieldUse, "DbInsClientProductRight", "���ӿͻ���ƷȨ��" }
		,
	{ TID_DbUpdClientProductRight, 1, DbUpdClientProductRightFieldUse, "DbUpdClientProductRight", "�޸Ŀͻ���ƷȨ��" }
		,
	{ TID_DbDelClientProductRight, 1, DbDelClientProductRightFieldUse, "DbDelClientProductRight", "ɾ���ͻ���ƷȨ��" }
		,
	{ TID_DbInsPartInstrumentRight, 1, DbInsPartInstrumentRightFieldUse, "DbInsPartInstrumentRight", "���ӻ�Ա��ԼȨ��" }
		,
	{ TID_DbUpdPartInstrumentRight, 1, DbUpdPartInstrumentRightFieldUse, "DbUpdPartInstrumentRight", "�޸Ļ�Ա��ԼȨ��" }
		,
	{ TID_DbDelPartInstrumentRight, 1, DbDelPartInstrumentRightFieldUse, "DbDelPartInstrumentRight", "ɾ����Ա��ԼȨ��" }
		,
	{ TID_DbInsClientInstrumentRight, 1, DbInsClientInstrumentRightFieldUse, "DbInsClientInstrumentRight", "���ӿͻ���ԼȨ��" }
		,
	{ TID_DbUpdClientInstrumentRight, 1, DbUpdClientInstrumentRightFieldUse, "DbUpdClientInstrumentRight", "�޸Ŀͻ���ԼȨ��" }
		,
	{ TID_DbDelClientInstrumentRight, 1, DbDelClientInstrumentRightFieldUse, "DbDelClientInstrumentRight", "ɾ����Ա�ͻ�Ȩ��" }
		,
	{ TID_DbInsPartClientProductRight, 1, DbInsPartClientProductRightFieldUse, "DbInsPartClientProductRight", "���ӻ�Ա�ͻ���ƷȨ��" }
		,
	{ TID_DbUpdPartClientProductRight, 1, DbUpdPartClientProductRightFieldUse, "DbUpdPartClientProductRight", "�޸Ļ�Ա�ͻ���ƷȨ��" }
		,
	{ TID_DbDelPartClientProductRight, 1, DbDelPartClientProductRightFieldUse, "DbDelPartClientProductRight", "ɾ����Ա�ͻ���ƷȨ��" }
		,
	{ TID_DbInsPartClientInstrumentRight, 1, DbInsPartClientInstrumentRightFieldUse, "DbInsPartClientInstrumentRight", "���ӻ�Ա�ͻ���ԼȨ��" }
		,
	{ TID_DbUpdPartClientInstrumentRight, 1, DbUpdPartClientInstrumentRightFieldUse, "DbUpdPartClientInstrumentRight", "�޸Ļ�Ա�ͻ���ԼȨ��" }
		,
	{ TID_DbDelPartClientInstrumentRight, 1, DbDelPartClientInstrumentRightFieldUse, "DbDelPartClientInstrumentRight", "ɾ����Ա�ͻ���ԼȨ��" }
		,
	{ TID_DbInsCurrMarginRateDetail, 1, DbInsCurrMarginRateDetailFieldUse, "DbInsCurrMarginRateDetail", "���ӻ�Ա��Լ��֤����" }
		,
	{ TID_DbUpdCurrMarginRateDetail, 1, DbUpdCurrMarginRateDetailFieldUse, "DbUpdCurrMarginRateDetail", "�޸Ļ�Ա��Լ��֤����" }
		,
	{ TID_DbDelCurrMarginRateDetail, 1, DbDelCurrMarginRateDetailFieldUse, "DbDelCurrMarginRateDetail", "ɾ����Ա��Լ��֤����" }
		,
	{ TID_DbUpdMarketData, 1, DbUpdMarketDataFieldUse, "DbUpdMarketData", "���ݿⷢ������������" }
		,
	{ TID_DbInsUserIP, 1, DbInsUserIPFieldUse, "DbInsUserIP", "�����û�IP��ַ" }
		,
	{ TID_DbDelUserIP, 1, DbDelUserIPFieldUse, "DbDelUserIP", "ɾ���û�IP��ַ" }
		,
	{ TID_DbInsCurrPriceBanding, 1, DbInsCurrPriceBandingFieldUse, "DbInsCurrPriceBanding", "���Ӽ۸��" }
		,
	{ TID_DbUpdCurrPriceBanding, 1, DbUpdCurrPriceBandingFieldUse, "DbUpdCurrPriceBanding", "�޸ļ۸��" }
		,
	{ TID_DbDelCurrPriceBanding, 1, DbDelCurrPriceBandingFieldUse, "DbDelCurrPriceBanding", "ɾ���۸��" }
		,
	{ TID_DbInsPartTopicSubscribe, 1, DbInsPartTopicSubscribeFieldUse, "DbInsPartTopicSubscribe", "���ӻ�Ա�����г�" }
		,
	{ TID_DbDelPartTopicSubscribe, 1, DbDelPartTopicSubscribeFieldUse, "DbDelPartTopicSubscribe", "ɾ����Ա�����г�" }
		,
	{ TID_NtfTimeSync, 1, NtfTimeSyncFieldUse, "NtfTimeSync", "ʱ��ͬ��" }
		,
	{ TID_NtfCommPhaseChange, 1, NtfCommPhaseChangeFieldUse, "NtfCommPhaseChange", "ͨѶ�׶��л�֪ͨ" }
		,
	{ TID_NtfDataCenterDesc, 1, NtfDataCenterDescFieldUse, "NtfDataCenterDesc", "��������λ��֪ͨ" }
		,
	{ TID_NtfInsInstrument, 1, NtfInsInstrumentFieldUse, "NtfInsInstrument", "���Ӻ�Լ֪ͨ" }
		,
	{ TID_NtfDelInstrument, 1, NtfDelInstrumentFieldUse, "NtfDelInstrument", "ɾ����Լ֪ͨ" }
		,
	{ TID_NtfInsCombinationLeg, 1, NtfInsCombinationLegFieldUse, "NtfInsCombinationLeg", "������Ϻ�Լ����֪ͨ" }
		,
	{ TID_NtfDelCombinationLeg, 1, NtfDelCombinationLegFieldUse, "NtfDelCombinationLeg", "ɾ����Ϻ�Լ����֪ͨ" }
		,
	{ TID_NtfAliasDefine, 1, NtfAliasDefineFieldUse, "NtfAliasDefine", "��������֪ͨ" }
		,
	{ TID_NtfOrder, 1, NtfOrderFieldUse, "NtfOrder", "����֪ͨ" }
		,
	{ TID_NtfTrade, 1, NtfTradeFieldUse, "NtfTrade", "�ɽ�֪ͨ" }
		,
	{ TID_NtfQuote, 1, NtfQuoteFieldUse, "NtfQuote", "����֪ͨ" }
		,
	{ TID_NtfExecOrder, 1, NtfExecOrderFieldUse, "NtfExecOrder", "ִ������֪ͨ" }
		,
	{ TID_NtfCombOrder, 1, NtfCombOrderFieldUse, "NtfCombOrder", "��ϱ���֪ͨ" }
		,
	{ TID_NtfInstrumentStatusUpdate, 1, NtfInstrumentStatusUpdateFieldUse, "NtfInstrumentStatusUpdate", "��Լ����״̬�ı�֪ͨ" }
		,
	{ TID_NtfDelUserSession, 1, NtfDelUserSessionFieldUse, "NtfDelUserSession", "�Ựɾ��֪ͨ" }
		,
	{ TID_NtfBulletin, 1, NtfBulletinFieldUse, "NtfBulletin", "��������������֪ͨ" }
		,
	{ TID_NtfMarketData, 1, NtfMarketDataFieldUse, "NtfMarketData", "��ͨ����֪ͨ" }
		,
	{ TID_NtfDepthMarketData, 9, NtfDepthMarketDataFieldUse, "NtfDepthMarketData", "�������֪ͨ" }
		,
	{ TID_NtfAdminOrder, 1, NtfAdminOrderFieldUse, "NtfAdminOrder", "������֪ͨ" }
		,
	{ TID_ExchangeDataSyncStart, 1, ExchangeDataSyncStartFieldUse, "ExchangeDataSyncStart", "����������ͬ����ʼ" }
		,
	{ TID_ExchangeDataSyncEnd, 1, ExchangeDataSyncEndFieldUse, "ExchangeDataSyncEnd", "����������ͬ������" }
		,
	{ TID_InitExchange, 1, InitExchangeFieldUse, "InitExchange", "������" }
		,
	{ TID_InitSettlementGroup, 1, InitSettlementGroupFieldUse, "InitSettlementGroup", "������" }
		,
	{ TID_InitMarket, 1, InitMarketFieldUse, "InitMarket", "�г�" }
		,
	{ TID_InitMarketProduct, 1, InitMarketProductFieldUse, "InitMarketProduct", "�г���Ʒ����" }
		,
	{ TID_InitMarketProductGroup, 1, InitMarketProductGroupFieldUse, "InitMarketProductGroup", "�г���Ʒ�����" }
		,
	{ TID_InitMarketDataTopic, 1, InitMarketDataTopicFieldUse, "InitMarketDataTopic", "��������" }
		,
	{ TID_InitPartTopicSubscribe, 1, InitPartTopicSubscribeFieldUse, "InitPartTopicSubscribe", "��Ա�����г�" }
		,
	{ TID_InitParticipant, 1, InitParticipantFieldUse, "InitParticipant", "��Ա" }
		,
	{ TID_InitUser, 1, InitUserFieldUse, "InitUser", "�û�" }
		,
	{ TID_InitClient, 1, InitClientFieldUse, "InitClient", "�ͻ�" }
		,
	{ TID_InitPartClient, 1, InitPartClientFieldUse, "InitPartClient", "��Ա�ͻ���ϵ" }
		,
	{ TID_InitUserIP, 1, InitUserIPFieldUse, "InitUserIP", "�û�IP��ַ" }
		,
	{ TID_InitMdPubStatus, 1, InitMdPubStatusFieldUse, "InitMdPubStatus", "���鷢��״̬" }
		,
	{ TID_InitAliasDefine, 1, InitAliasDefineFieldUse, "InitAliasDefine", "��������" }
		,
	{ TID_InitClearingTradingPart, 1, InitClearingTradingPartFieldUse, "InitClearingTradingPart", "���㽻�׻�Ա��ϵ" }
		,
	{ TID_InitUserFunctionRight, 1, InitUserFunctionRightFieldUse, "InitUserFunctionRight", "�û�����Ȩ��" }
		,
	{ TID_InitAccount, 1, InitAccountFieldUse, "InitAccount", "�ʽ��˻�" }
		,
	{ TID_InitUserCommFlux, 1, InitUserCommFluxFieldUse, "InitUserCommFlux", "�û�ͨѶ��" }
		,
	{ TID_SettlementGroupDataSyncStart, 1, SettlementGroupDataSyncStartFieldUse, "SettlementGroupDataSyncStart", "����������ͬ����ʼ" }
		,
	{ TID_SettlementGroupDataSyncEnd, 1, SettlementGroupDataSyncEndFieldUse, "SettlementGroupDataSyncEnd", "����������ͬ������" }
		,
	{ TID_InitInstrument, 1, InitInstrumentFieldUse, "InitInstrument", "��Լ" }
		,
	{ TID_InitCombinationLeg, 1, InitCombinationLegFieldUse, "InitCombinationLeg", "��Ͻ��׺�Լ�ĵ���" }
		,
	{ TID_InitPartRoleAccount, 1, InitPartRoleAccountFieldUse, "InitPartRoleAccount", "��Ա�˻���ϵ" }
		,
	{ TID_InitPartProductRole, 1, InitPartProductRoleFieldUse, "InitPartProductRole", "��Ա��Ʒ��ɫ" }
		,
	{ TID_InitPartProductRight, 1, InitPartProductRightFieldUse, "InitPartProductRight", "��Ա��Ʒ����Ȩ��" }
		,
	{ TID_InitPartInstrumentRight, 1, InitPartInstrumentRightFieldUse, "InitPartInstrumentRight", "��Ա��Լ����Ȩ��" }
		,
	{ TID_InitClientProductRight, 1, InitClientProductRightFieldUse, "InitClientProductRight", "�ͻ���Ʒ����Ȩ��" }
		,
	{ TID_InitClientInstrumentRight, 1, InitClientInstrumentRightFieldUse, "InitClientInstrumentRight", "�ͻ���Լ����Ȩ��" }
		,
	{ TID_InitPartClientProductRight, 1, InitPartClientProductRightFieldUse, "InitPartClientProductRight", "��Ա�ͻ���Ʒ����Ȩ��" }
		,
	{ TID_InitPartClientInstrumentRight, 1, InitPartClientInstrumentRightFieldUse, "InitPartClientInstrumentRight", "��Ա�ͻ���Լ����Ȩ��" }
		,
	{ TID_InitCurrProductProperty, 1, InitCurrProductPropertyFieldUse, "InitCurrProductProperty", "��Ʒ����" }
		,
	{ TID_InitCurrInstrumentProperty, 1, InitCurrInstrumentPropertyFieldUse, "InitCurrInstrumentProperty", "��Լ����" }
		,
	{ TID_InitCurrPriceBanding, 1, InitCurrPriceBandingFieldUse, "InitCurrPriceBanding", "��ǰ��Լ�۸��" }
		,
	{ TID_InitCurrMarginRate, 1, InitCurrMarginRateFieldUse, "InitCurrMarginRate", "��ǰ��Լ��֤����" }
		,
	{ TID_InitCurrMarginRateDetail, 1, InitCurrMarginRateDetailFieldUse, "InitCurrMarginRateDetail", "��ǰ��Լ��֤���ʵ���ϸ����" }
		,
	{ TID_InitCurrPartPosiLimit, 1, InitCurrPartPosiLimitFieldUse, "InitCurrPartPosiLimit", "��ǰ��Ա��Լ�޲�" }
		,
	{ TID_InitCurrPartPosiLimitDetail, 1, InitCurrPartPosiLimitDetailFieldUse, "InitCurrPartPosiLimitDetail", "��ǰ��Ա��Լ�޲ֵ���ϸ����" }
		,
	{ TID_InitCurrClientPosiLimit, 1, InitCurrClientPosiLimitFieldUse, "InitCurrClientPosiLimit", "��ǰ�ͻ���Լ�޲�" }
		,
	{ TID_InitCurrClientPosiLimitDetail, 1, InitCurrClientPosiLimitDetailFieldUse, "InitCurrClientPosiLimitDetail", "��ǰ�ͻ���Լ�޲ֵ���ϸ����" }
		,
	{ TID_InitCurrSpecialPosiLimit, 1, InitCurrSpecialPosiLimitFieldUse, "InitCurrSpecialPosiLimit", "��ǰ����ͻ���Լ�޲�" }
		,
	{ TID_InitCurrSpecialPosiLimitDetail, 1, InitCurrSpecialPosiLimitDetailFieldUse, "InitCurrSpecialPosiLimitDetail", "��ǰ����ͻ���Լ�޲ֵ���ϸ����" }
		,
	{ TID_InitCurrHedgeRule, 1, InitCurrHedgeRuleFieldUse, "InitCurrHedgeRule", "��ǰ��Լ���ڱ�ֵ����" }
		,
	{ TID_InitCurrTradingSegmentAttr, 1, InitCurrTradingSegmentAttrFieldUse, "InitCurrTradingSegmentAttr", "��ǰ��Լ���׽׶�����" }
		,
	{ TID_InitCurrFuse, 1, InitCurrFuseFieldUse, "InitCurrFuse", "��ǰ��Լ�۶�����" }
		,
	{ TID_InitTradingAccount, 1, InitTradingAccountFieldUse, "InitTradingAccount", "�����˻���Ϣ" }
		,
	{ TID_InitPartPosition, 1, InitPartPositionFieldUse, "InitPartPosition", "��Ա��Լ�ֲ�" }
		,
	{ TID_InitClientPosition, 1, InitClientPositionFieldUse, "InitClientPosition", "�ͻ���Լ�ֲ�" }
		,
	{ TID_InitHedgeVolume, 1, InitHedgeVolumeFieldUse, "InitHedgeVolume", "��ֵ�����" }
		,
	{ TID_InitRemainOrder, 1, InitRemainOrderFieldUse, "InitRemainOrder", "������������" }
		,
	{ TID_InitMarketData, 1, InitMarketDataFieldUse, "InitMarketData", "�г�����" }
		,
	{ TID_InitBaseReserveAccount, 1, InitBaseReserveAccountFieldUse, "InitBaseReserveAccount", "����׼�����˻�" }
		,
	{ TID_InitCurrInstrumentOption, 1, InitCurrInstrumentOptionFieldUse, "InitCurrInstrumentOption", "�����ڻ���Լ��Ȩ����" }
		,
	{ TID_NtfInputMarketData, 1, NtfInputMarketDataFieldUse, "NtfInputMarketData", "����������Ϣ" }
};


CXTPPackageDefineMap g_XTPPackageDefineMap(XTPPackageDefines, sizeof(XTPPackageDefines)/ sizeof(TPackageDefine));

void XTP_DEBUG_BODY(DWORD tid, CFieldSet *pPackage, CLogger *pLogger)
{
	pLogger->output(LL_DEBUG, "\tXTP PACKAGE CONTENT START\n");					
	TPackageDefine **pFind = g_XTPPackageDefineMap.Find(tid);	
	if(pFind == NULL)													
	{																	
		pLogger->output(LL_DEBUG, "\tCan't find package define [%08x]\n", tid);				
		return;															
	}																	
	char buf[10000];													
	TPackageDefine *pPackageDefine = *pFind;							
	CFieldTypeIterator itor = pPackage->GetFieldTypeIterator();			
	while(!itor.IsEnd())												
	{																	
		TFieldHeader fieldHeader;										
		itor.RetrieveHeader(fieldHeader);								
		TFieldUse *pFieldUse = pPackageDefine->fieldUse;				
		for(int i=0; i<pPackageDefine->fieldUseCount; i++)				
		{																
			if(pFieldUse->fid == fieldHeader.FieldID)					
			{															
				itor.Retrieve(pFieldUse->pFieldDescribe, buf);			
				FIELD_DEBUG(buf, pFieldUse->pFieldDescribe, pLogger);	
				break;													
			}															
			pFieldUse++;												
		}																
		itor.Next();													
	}																	
	pLogger->output(LL_DEBUG, "\tXTP PACKAGE CONTENT END\n");						
}
