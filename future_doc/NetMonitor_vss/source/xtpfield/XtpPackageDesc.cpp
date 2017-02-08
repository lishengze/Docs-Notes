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
	{ TID_Nop, 1, NopFieldUse, "Nop", "空操作" }
		,
	{ TID_RspError, 1, RspErrorFieldUse, "RspError", "错误应答" }
		,
	{ TID_ReqUserLogin, 1, ReqUserLoginFieldUse, "ReqUserLogin", "用户登录请求" }
		,
	{ TID_RspUserLogin, 2, RspUserLoginFieldUse, "RspUserLogin", "用户登录应答" }
		,
	{ TID_ReqUserLogout, 1, ReqUserLogoutFieldUse, "ReqUserLogout", "用户退出请求" }
		,
	{ TID_RspUserLogout, 2, RspUserLogoutFieldUse, "RspUserLogout", "用户退出应答" }
		,
	{ TID_ReqOrderInsert, 1, ReqOrderInsertFieldUse, "ReqOrderInsert", "报单录入请求" }
		,
	{ TID_RspOrderInsert, 2, RspOrderInsertFieldUse, "RspOrderInsert", "报单录入应答" }
		,
	{ TID_ReqOrderAction, 1, ReqOrderActionFieldUse, "ReqOrderAction", "报单操作请求" }
		,
	{ TID_RspOrderAction, 2, RspOrderActionFieldUse, "RspOrderAction", "报单操作应答" }
		,
	{ TID_ReqQuoteInsert, 1, ReqQuoteInsertFieldUse, "ReqQuoteInsert", "报价录入请求" }
		,
	{ TID_RspQuoteInsert, 2, RspQuoteInsertFieldUse, "RspQuoteInsert", "报价录入应答" }
		,
	{ TID_ReqQuoteAction, 1, ReqQuoteActionFieldUse, "ReqQuoteAction", "报价操作请求" }
		,
	{ TID_RspQuoteAction, 2, RspQuoteActionFieldUse, "RspQuoteAction", "报价操作应答" }
		,
	{ TID_ReqOTCOrderInsert, 1, ReqOTCOrderInsertFieldUse, "ReqOTCOrderInsert", "OTC报单录入请求" }
		,
	{ TID_RspOTCOrderInsert, 2, RspOTCOrderInsertFieldUse, "RspOTCOrderInsert", "OTC报单录入应答" }
		,
	{ TID_ReqUserPasswordUpdate, 1, ReqUserPasswordUpdateFieldUse, "ReqUserPasswordUpdate", "用户密码修改请求" }
		,
	{ TID_RspUserPasswordUpdate, 2, RspUserPasswordUpdateFieldUse, "RspUserPasswordUpdate", "用户密码修改应答" }
		,
	{ TID_ReqExecOrderInsert, 1, ReqExecOrderInsertFieldUse, "ReqExecOrderInsert", "执行宣告录入请求" }
		,
	{ TID_RspExecOrderInsert, 2, RspExecOrderInsertFieldUse, "RspExecOrderInsert", "执行宣告录入应答" }
		,
	{ TID_ReqExecOrderAction, 1, ReqExecOrderActionFieldUse, "ReqExecOrderAction", "执行宣告操作请求" }
		,
	{ TID_RspExecOrderAction, 2, RspExecOrderActionFieldUse, "RspExecOrderAction", "执行宣告操作应答" }
		,
	{ TID_ReqAdminOrderInsert, 1, ReqAdminOrderInsertFieldUse, "ReqAdminOrderInsert", "管理报单录入请求" }
		,
	{ TID_RspAdminOrderInsert, 2, RspAdminOrderInsertFieldUse, "RspAdminOrderInsert", "管理报单录入应答" }
		,
	{ TID_ReqCombOrderInsert, 1, ReqCombOrderInsertFieldUse, "ReqCombOrderInsert", "组合报单录入请求" }
		,
	{ TID_RspCombOrderInsert, 2, RspCombOrderInsertFieldUse, "RspCombOrderInsert", "组合报单录入应答" }
		,
	{ TID_ReqBulletin, 1, ReqBulletinFieldUse, "ReqBulletin", "交易所公告请求" }
		,
	{ TID_RspBulletin, 2, RspBulletinFieldUse, "RspBulletin", "交易所公告请求应答" }
		,
	{ TID_ReqInstrumentStatusUpdate, 1, ReqInstrumentStatusUpdateFieldUse, "ReqInstrumentStatusUpdate", "合约交易状态改变请求" }
		,
	{ TID_RspInstrumentStatusUpdate, 2, RspInstrumentStatusUpdateFieldUse, "RspInstrumentStatusUpdate", "合约交易状态改变应答" }
		,
	{ TID_ReqForceUserExit, 1, ReqForceUserExitFieldUse, "ReqForceUserExit", "强制用户退出请求" }
		,
	{ TID_RspForceUserExit, 2, RspForceUserExitFieldUse, "RspForceUserExit", "强制用户退出应答" }
		,
	{ TID_ReqForceUserLogout, 1, ReqForceUserLogoutFieldUse, "ReqForceUserLogout", "用户会话删除请求" }
		,
	{ TID_RspForceUserLogout, 2, RspForceUserLogoutFieldUse, "RspForceUserLogout", "用户会话删除应答" }
		,
	{ TID_ReqExchangeDataSyncStatusUpdate, 1, ReqExchangeDataSyncStatusUpdateFieldUse, "ReqExchangeDataSyncStatusUpdate", "交易所数据同步状态改变请求" }
		,
	{ TID_RspExchangeDataSyncStatusUpdate, 2, RspExchangeDataSyncStatusUpdateFieldUse, "RspExchangeDataSyncStatusUpdate", "交易所数据同步状态改变应答" }
		,
	{ TID_ReqSGDataSyncStatusUpdate, 1, ReqSGDataSyncStatusUpdateFieldUse, "ReqSGDataSyncStatusUpdate", "结算组数据同步状态改变请求" }
		,
	{ TID_RspSGDataSyncStatusUpdate, 2, RspSGDataSyncStatusUpdateFieldUse, "RspSGDataSyncStatusUpdate", "结算组数据同步状态改变应答" }
		,
	{ TID_ReqExchangeDataSync, 1, ReqExchangeDataSyncFieldUse, "ReqExchangeDataSync", "交易所数据同步请求" }
		,
	{ TID_RspExchangeDataSync, 2, RspExchangeDataSyncFieldUse, "RspExchangeDataSync", "交易所数据同步应答" }
		,
	{ TID_ReqSgDataSync, 1, ReqSgDataSyncFieldUse, "ReqSgDataSync", "结算组数据同步请求" }
		,
	{ TID_RspSgDataSync, 2, RspSgDataSyncFieldUse, "RspSgDataSync", "结算组数据同步应答" }
		,
	{ TID_ReqInformation, 1, ReqInformationFieldUse, "ReqInformation", "交易所信息请求" }
		,
	{ TID_RspInformation, 2, RspInformationFieldUse, "RspInformation", "交易所公告信息应答" }
		,
	{ TID_ReqFrontStatus, 1, ReqFrontStatusFieldUse, "ReqFrontStatus", "前置状态报告请求" }
		,
	{ TID_RspFrontStatus, 2, RspFrontStatusFieldUse, "RspFrontStatus", "前置状态报告应答" }
		,
	{ TID_ReqQryPartAccount, 1, ReqQryPartAccountFieldUse, "ReqQryPartAccount", "会员资金查询请求" }
		,
	{ TID_RspQryPartAccount, 2, RspQryPartAccountFieldUse, "RspQryPartAccount", "会员资金查询应答" }
		,
	{ TID_ReqQryOrder, 1, ReqQryOrderFieldUse, "ReqQryOrder", "报单查询请求" }
		,
	{ TID_RspQryOrder, 2, RspQryOrderFieldUse, "RspQryOrder", "报单查询应答" }
		,
	{ TID_ReqQryQuote, 1, ReqQryQuoteFieldUse, "ReqQryQuote", "报价查询请求" }
		,
	{ TID_RspQryQuote, 2, RspQryQuoteFieldUse, "RspQryQuote", "报价查询应答" }
		,
	{ TID_ReqQryTrade, 1, ReqQryTradeFieldUse, "ReqQryTrade", "成交单查询请求" }
		,
	{ TID_RspQryTrade, 2, RspQryTradeFieldUse, "RspQryTrade", "成交单查询应答" }
		,
	{ TID_ReqQryClient, 1, ReqQryClientFieldUse, "ReqQryClient", "会员客户查询请求" }
		,
	{ TID_RspQryClient, 2, RspQryClientFieldUse, "RspQryClient", "会员客户查询应答" }
		,
	{ TID_ReqQryPartPosition, 1, ReqQryPartPositionFieldUse, "ReqQryPartPosition", "会员持仓查询请求" }
		,
	{ TID_RspQryPartPosition, 2, RspQryPartPositionFieldUse, "RspQryPartPosition", "会员持仓查询应答" }
		,
	{ TID_ReqQryClientPosition, 1, ReqQryClientPositionFieldUse, "ReqQryClientPosition", "客户持仓查询请求" }
		,
	{ TID_RspQryClientPosition, 2, RspQryClientPositionFieldUse, "RspQryClientPosition", "客户持仓查询应答" }
		,
	{ TID_ReqQryInstrument, 1, ReqQryInstrumentFieldUse, "ReqQryInstrument", "合约查询请求" }
		,
	{ TID_RspQryInstrument, 2, RspQryInstrumentFieldUse, "RspQryInstrument", "合约查询应答" }
		,
	{ TID_ReqQryInstrumentStatus, 1, ReqQryInstrumentStatusFieldUse, "ReqQryInstrumentStatus", "合约交易状态查询请求" }
		,
	{ TID_RspQryInstrumentStatus, 2, RspQryInstrumentStatusFieldUse, "RspQryInstrumentStatus", "合约交易状态查询应答" }
		,
	{ TID_ReqQrySGDataSyncStatus, 1, ReqQrySGDataSyncStatusFieldUse, "ReqQrySGDataSyncStatus", "结算组数据同步状态查询请求" }
		,
	{ TID_RspQrySGDataSyncStatus, 2, RspQrySGDataSyncStatusFieldUse, "RspQrySGDataSyncStatus", "结算组数据同步状态查询应答" }
		,
	{ TID_ReqQryHedgeVolume, 1, ReqQryHedgeVolumeFieldUse, "ReqQryHedgeVolume", "保值额度查询" }
		,
	{ TID_RspQryHedgeVolume, 2, RspQryHedgeVolumeFieldUse, "RspQryHedgeVolume", "保值额度应答" }
		,
	{ TID_ReqQryCombOrder, 1, ReqQryCombOrderFieldUse, "ReqQryCombOrder", "组合报单查询请求" }
		,
	{ TID_RspQryCombOrder, 2, RspQryCombOrderFieldUse, "RspQryCombOrder", "组合报单查询应答" }
		,
	{ TID_ReqQryMarketData, 1, ReqQryMarketDataFieldUse, "ReqQryMarketData", "普通行情查询请求" }
		,
	{ TID_RspQryMarketData, 2, RspQryMarketDataFieldUse, "RspQryMarketData", "普通行情查询应答" }
		,
	{ TID_ReqQryBulletin, 1, ReqQryBulletinFieldUse, "ReqQryBulletin", "交易所公告查询请求" }
		,
	{ TID_RspQryBulletin, 2, RspQryBulletinFieldUse, "RspQryBulletin", "交易所公告查询应答" }
		,
	{ TID_ReqQryUserSession, 1, ReqQryUserSessionFieldUse, "ReqQryUserSession", "用户在线查询请求" }
		,
	{ TID_RspQryUserSession, 2, RspQryUserSessionFieldUse, "RspQryUserSession", "用户在线查询应答" }
		,
	{ TID_ReqQryUser, 1, ReqQryUserFieldUse, "ReqQryUser", "用户查询请求" }
		,
	{ TID_RspQryUser, 2, RspQryUserFieldUse, "RspQryUser", "用户查询应答" }
		,
	{ TID_ReqQryParticipant, 1, ReqQryParticipantFieldUse, "ReqQryParticipant", "会员查询请求" }
		,
	{ TID_RspQryParticipant, 2, RspQryParticipantFieldUse, "RspQryParticipant", "会员查询应答" }
		,
	{ TID_ReqQryMBLMarketData, 1, ReqQryMBLMarketDataFieldUse, "ReqQryMBLMarketData", "合约价位查询" }
		,
	{ TID_RspQryMBLMarketData, 2, RspQryMBLMarketDataFieldUse, "RspQryMBLMarketData", "合约价位查询应答" }
		,
	{ TID_ReqQryInformation, 1, ReqQryInformationFieldUse, "ReqQryInformation", "信息查询" }
		,
	{ TID_RspQryInformation, 2, RspQryInformationFieldUse, "RspQryInformation", "信息查询应答" }
		,
	{ TID_ReqQryExchangeStatus, 1, ReqQryExchangeStatusFieldUse, "ReqQryExchangeStatus", "交易所状态查询" }
		,
	{ TID_RspQryExchangeStatus, 2, RspQryExchangeStatusFieldUse, "RspQryExchangeStatus", "交易所状态应答" }
		,
	{ TID_ReqQryExchangeDataSyncStatus, 1, ReqQryExchangeDataSyncStatusFieldUse, "ReqQryExchangeDataSyncStatus", "交易所数据同步状态查询" }
		,
	{ TID_RspQryExchangeDataSyncStatus, 2, RspQryExchangeDataSyncStatusFieldUse, "RspQryExchangeDataSyncStatus", "交易所数据同步状态应答" }
		,
	{ TID_ReqQrySettlementGroupStatus, 1, ReqQrySettlementGroupStatusFieldUse, "ReqQrySettlementGroupStatus", "结算组状态查询" }
		,
	{ TID_RspQrySettlementGroupStatus, 2, RspQrySettlementGroupStatusFieldUse, "RspQrySettlementGroupStatus", "结算组状态应答" }
		,
	{ TID_ReqQryCreditLimit, 1, ReqQryCreditLimitFieldUse, "ReqQryCreditLimit", "信用限额查询请求" }
		,
	{ TID_RspQryCreditLimit, 2, RspQryCreditLimitFieldUse, "RspQryCreditLimit", "信用限额查询应答" }
		,
	{ TID_DbAccountDeposit, 1, DbAccountDepositFieldUse, "DbAccountDeposit", "资金帐户入金" }
		,
	{ TID_DbUpdateAllInstrumentStatus, 1, DbUpdateAllInstrumentStatusFieldUse, "DbUpdateAllInstrumentStatus", "调整所有合约状态" }
		,
	{ TID_DbInsClient, 1, DbInsClientFieldUse, "DbInsClient", "增加客户" }
		,
	{ TID_DbUpdClient, 1, DbUpdClientFieldUse, "DbUpdClient", "修改客户" }
		,
	{ TID_DbInsPartClient, 1, DbInsPartClientFieldUse, "DbInsPartClient", "增加会员客户关系" }
		,
	{ TID_DbDelPartClient, 1, DbDelPartClientFieldUse, "DbDelPartClient", "删除会员客户关系" }
		,
	{ TID_DbInsCurrPartPosiLimitDetail, 1, DbInsCurrPartPosiLimitDetailFieldUse, "DbInsCurrPartPosiLimitDetail", "增加会员合约持仓限额" }
		,
	{ TID_DbUpdCurrPartPosiLimitDetail, 1, DbUpdCurrPartPosiLimitDetailFieldUse, "DbUpdCurrPartPosiLimitDetail", "修改会员合约持仓限额" }
		,
	{ TID_DbDelCurrPartPosiLimitDetail, 1, DbDelCurrPartPosiLimitDetailFieldUse, "DbDelCurrPartPosiLimitDetail", "删除会员合约持仓限额" }
		,
	{ TID_DbInsCurrClientPosiLimitDetail, 1, DbInsCurrClientPosiLimitDetailFieldUse, "DbInsCurrClientPosiLimitDetail", "增加客户合约持仓限额" }
		,
	{ TID_DbUpdCurrClientPosiLimitDetail, 1, DbUpdCurrClientPosiLimitDetailFieldUse, "DbUpdCurrClientPosiLimitDetail", "修改客户合约持仓限额" }
		,
	{ TID_DbDelCurrClientPosiLimitDetail, 1, DbDelCurrClientPosiLimitDetailFieldUse, "DbDelCurrClientPosiLimitDetail", "删除客户合约持仓限额" }
		,
	{ TID_DbInsCurrSpecialPosiLimitDetail, 1, DbInsCurrSpecialPosiLimitDetailFieldUse, "DbInsCurrSpecialPosiLimitDetail", "增加特殊客户合约持仓限额" }
		,
	{ TID_DbUpdCurrSpecialPosiLimitDetail, 1, DbUpdCurrSpecialPosiLimitDetailFieldUse, "DbUpdCurrSpecialPosiLimitDetail", "修改特殊客户合约持仓限额" }
		,
	{ TID_DbDelCurrSpecialPosiLimitDetail, 1, DbDelCurrSpecialPosiLimitDetailFieldUse, "DbDelCurrSpecialPosiLimitDetail", "删除特殊客户合约持仓限额" }
		,
	{ TID_DbInsHedgeDetail, 1, DbInsHedgeDetailFieldUse, "DbInsHedgeDetail", "增加保值额度" }
		,
	{ TID_DbUpdCurrHedge, 1, DbUpdCurrHedgeFieldUse, "DbUpdCurrHedge", "更新当前保值额度" }
		,
	{ TID_DbInsUser, 1, DbInsUserFieldUse, "DbInsUser", "增加交易用户" }
		,
	{ TID_DbUpdUser, 1, DbUpdUserFieldUse, "DbUpdUser", "修改交易用户" }
		,
	{ TID_DbInsPartProductRight, 1, DbInsPartProductRightFieldUse, "DbInsPartProductRight", "增加会员产品权限" }
		,
	{ TID_DbUpdPartProductRight, 1, DbUpdPartProductRightFieldUse, "DbUpdPartProductRight", "修改会员产品权限" }
		,
	{ TID_DbDelPartProductRight, 1, DbDelPartProductRightFieldUse, "DbDelPartProductRight", "删除会员产品权限" }
		,
	{ TID_DbInsClientProductRight, 1, DbInsClientProductRightFieldUse, "DbInsClientProductRight", "增加客户产品权限" }
		,
	{ TID_DbUpdClientProductRight, 1, DbUpdClientProductRightFieldUse, "DbUpdClientProductRight", "修改客户产品权限" }
		,
	{ TID_DbDelClientProductRight, 1, DbDelClientProductRightFieldUse, "DbDelClientProductRight", "删除客户产品权限" }
		,
	{ TID_DbInsPartInstrumentRight, 1, DbInsPartInstrumentRightFieldUse, "DbInsPartInstrumentRight", "增加会员合约权限" }
		,
	{ TID_DbUpdPartInstrumentRight, 1, DbUpdPartInstrumentRightFieldUse, "DbUpdPartInstrumentRight", "修改会员合约权限" }
		,
	{ TID_DbDelPartInstrumentRight, 1, DbDelPartInstrumentRightFieldUse, "DbDelPartInstrumentRight", "删除会员合约权限" }
		,
	{ TID_DbInsClientInstrumentRight, 1, DbInsClientInstrumentRightFieldUse, "DbInsClientInstrumentRight", "增加客户合约权限" }
		,
	{ TID_DbUpdClientInstrumentRight, 1, DbUpdClientInstrumentRightFieldUse, "DbUpdClientInstrumentRight", "修改客户合约权限" }
		,
	{ TID_DbDelClientInstrumentRight, 1, DbDelClientInstrumentRightFieldUse, "DbDelClientInstrumentRight", "删除会员客户权限" }
		,
	{ TID_DbInsPartClientProductRight, 1, DbInsPartClientProductRightFieldUse, "DbInsPartClientProductRight", "增加会员客户产品权限" }
		,
	{ TID_DbUpdPartClientProductRight, 1, DbUpdPartClientProductRightFieldUse, "DbUpdPartClientProductRight", "修改会员客户产品权限" }
		,
	{ TID_DbDelPartClientProductRight, 1, DbDelPartClientProductRightFieldUse, "DbDelPartClientProductRight", "删除会员客户产品权限" }
		,
	{ TID_DbInsPartClientInstrumentRight, 1, DbInsPartClientInstrumentRightFieldUse, "DbInsPartClientInstrumentRight", "增加会员客户合约权限" }
		,
	{ TID_DbUpdPartClientInstrumentRight, 1, DbUpdPartClientInstrumentRightFieldUse, "DbUpdPartClientInstrumentRight", "修改会员客户合约权限" }
		,
	{ TID_DbDelPartClientInstrumentRight, 1, DbDelPartClientInstrumentRightFieldUse, "DbDelPartClientInstrumentRight", "删除会员客户合约权限" }
		,
	{ TID_DbInsCurrMarginRateDetail, 1, DbInsCurrMarginRateDetailFieldUse, "DbInsCurrMarginRateDetail", "增加会员合约保证金率" }
		,
	{ TID_DbUpdCurrMarginRateDetail, 1, DbUpdCurrMarginRateDetailFieldUse, "DbUpdCurrMarginRateDetail", "修改会员合约保证金率" }
		,
	{ TID_DbDelCurrMarginRateDetail, 1, DbDelCurrMarginRateDetailFieldUse, "DbDelCurrMarginRateDetail", "删除会员合约保证金率" }
		,
	{ TID_DbUpdMarketData, 1, DbUpdMarketDataFieldUse, "DbUpdMarketData", "数据库发出的最终行情" }
		,
	{ TID_DbInsUserIP, 1, DbInsUserIPFieldUse, "DbInsUserIP", "增加用户IP地址" }
		,
	{ TID_DbDelUserIP, 1, DbDelUserIPFieldUse, "DbDelUserIP", "删除用户IP地址" }
		,
	{ TID_DbInsCurrPriceBanding, 1, DbInsCurrPriceBandingFieldUse, "DbInsCurrPriceBanding", "增加价格绑定" }
		,
	{ TID_DbUpdCurrPriceBanding, 1, DbUpdCurrPriceBandingFieldUse, "DbUpdCurrPriceBanding", "修改价格绑定" }
		,
	{ TID_DbDelCurrPriceBanding, 1, DbDelCurrPriceBandingFieldUse, "DbDelCurrPriceBanding", "删除价格绑定" }
		,
	{ TID_DbInsPartTopicSubscribe, 1, DbInsPartTopicSubscribeFieldUse, "DbInsPartTopicSubscribe", "增加会员订阅市场" }
		,
	{ TID_DbDelPartTopicSubscribe, 1, DbDelPartTopicSubscribeFieldUse, "DbDelPartTopicSubscribe", "删除会员订阅市场" }
		,
	{ TID_NtfTimeSync, 1, NtfTimeSyncFieldUse, "NtfTimeSync", "时间同步" }
		,
	{ TID_NtfCommPhaseChange, 1, NtfCommPhaseChangeFieldUse, "NtfCommPhaseChange", "通讯阶段切换通知" }
		,
	{ TID_NtfDataCenterDesc, 1, NtfDataCenterDescFieldUse, "NtfDataCenterDesc", "数据中心位置通知" }
		,
	{ TID_NtfInsInstrument, 1, NtfInsInstrumentFieldUse, "NtfInsInstrument", "增加合约通知" }
		,
	{ TID_NtfDelInstrument, 1, NtfDelInstrumentFieldUse, "NtfDelInstrument", "删除合约通知" }
		,
	{ TID_NtfInsCombinationLeg, 1, NtfInsCombinationLegFieldUse, "NtfInsCombinationLeg", "增加组合合约单腿通知" }
		,
	{ TID_NtfDelCombinationLeg, 1, NtfDelCombinationLegFieldUse, "NtfDelCombinationLeg", "删除组合合约单腿通知" }
		,
	{ TID_NtfAliasDefine, 1, NtfAliasDefineFieldUse, "NtfAliasDefine", "别名定义通知" }
		,
	{ TID_NtfOrder, 1, NtfOrderFieldUse, "NtfOrder", "报单通知" }
		,
	{ TID_NtfTrade, 1, NtfTradeFieldUse, "NtfTrade", "成交通知" }
		,
	{ TID_NtfQuote, 1, NtfQuoteFieldUse, "NtfQuote", "报价通知" }
		,
	{ TID_NtfExecOrder, 1, NtfExecOrderFieldUse, "NtfExecOrder", "执行宣告通知" }
		,
	{ TID_NtfCombOrder, 1, NtfCombOrderFieldUse, "NtfCombOrder", "组合报单通知" }
		,
	{ TID_NtfInstrumentStatusUpdate, 1, NtfInstrumentStatusUpdateFieldUse, "NtfInstrumentStatusUpdate", "合约交易状态改变通知" }
		,
	{ TID_NtfDelUserSession, 1, NtfDelUserSessionFieldUse, "NtfDelUserSession", "会话删除通知" }
		,
	{ TID_NtfBulletin, 1, NtfBulletinFieldUse, "NtfBulletin", "交易所公告请求通知" }
		,
	{ TID_NtfMarketData, 1, NtfMarketDataFieldUse, "NtfMarketData", "普通行情通知" }
		,
	{ TID_NtfDepthMarketData, 9, NtfDepthMarketDataFieldUse, "NtfDepthMarketData", "深度行情通知" }
		,
	{ TID_NtfAdminOrder, 1, NtfAdminOrderFieldUse, "NtfAdminOrder", "管理报单通知" }
		,
	{ TID_ExchangeDataSyncStart, 1, ExchangeDataSyncStartFieldUse, "ExchangeDataSyncStart", "交易所数据同步开始" }
		,
	{ TID_ExchangeDataSyncEnd, 1, ExchangeDataSyncEndFieldUse, "ExchangeDataSyncEnd", "交易所数据同步结束" }
		,
	{ TID_InitExchange, 1, InitExchangeFieldUse, "InitExchange", "交易所" }
		,
	{ TID_InitSettlementGroup, 1, InitSettlementGroupFieldUse, "InitSettlementGroup", "结算组" }
		,
	{ TID_InitMarket, 1, InitMarketFieldUse, "InitMarket", "市场" }
		,
	{ TID_InitMarketProduct, 1, InitMarketProductFieldUse, "InitMarketProduct", "市场产品关联" }
		,
	{ TID_InitMarketProductGroup, 1, InitMarketProductGroupFieldUse, "InitMarketProductGroup", "市场产品组关联" }
		,
	{ TID_InitMarketDataTopic, 1, InitMarketDataTopicFieldUse, "InitMarketDataTopic", "行情主题" }
		,
	{ TID_InitPartTopicSubscribe, 1, InitPartTopicSubscribeFieldUse, "InitPartTopicSubscribe", "会员订阅市场" }
		,
	{ TID_InitParticipant, 1, InitParticipantFieldUse, "InitParticipant", "会员" }
		,
	{ TID_InitUser, 1, InitUserFieldUse, "InitUser", "用户" }
		,
	{ TID_InitClient, 1, InitClientFieldUse, "InitClient", "客户" }
		,
	{ TID_InitPartClient, 1, InitPartClientFieldUse, "InitPartClient", "会员客户关系" }
		,
	{ TID_InitUserIP, 1, InitUserIPFieldUse, "InitUserIP", "用户IP地址" }
		,
	{ TID_InitMdPubStatus, 1, InitMdPubStatusFieldUse, "InitMdPubStatus", "行情发布状态" }
		,
	{ TID_InitAliasDefine, 1, InitAliasDefineFieldUse, "InitAliasDefine", "别名定义" }
		,
	{ TID_InitClearingTradingPart, 1, InitClearingTradingPartFieldUse, "InitClearingTradingPart", "结算交易会员关系" }
		,
	{ TID_InitUserFunctionRight, 1, InitUserFunctionRightFieldUse, "InitUserFunctionRight", "用户功能权限" }
		,
	{ TID_InitAccount, 1, InitAccountFieldUse, "InitAccount", "资金账户" }
		,
	{ TID_InitUserCommFlux, 1, InitUserCommFluxFieldUse, "InitUserCommFlux", "用户通讯量" }
		,
	{ TID_SettlementGroupDataSyncStart, 1, SettlementGroupDataSyncStartFieldUse, "SettlementGroupDataSyncStart", "结算组数据同步开始" }
		,
	{ TID_SettlementGroupDataSyncEnd, 1, SettlementGroupDataSyncEndFieldUse, "SettlementGroupDataSyncEnd", "结算组数据同步结束" }
		,
	{ TID_InitInstrument, 1, InitInstrumentFieldUse, "InitInstrument", "合约" }
		,
	{ TID_InitCombinationLeg, 1, InitCombinationLegFieldUse, "InitCombinationLeg", "组合交易合约的单腿" }
		,
	{ TID_InitPartRoleAccount, 1, InitPartRoleAccountFieldUse, "InitPartRoleAccount", "会员账户关系" }
		,
	{ TID_InitPartProductRole, 1, InitPartProductRoleFieldUse, "InitPartProductRole", "会员产品角色" }
		,
	{ TID_InitPartProductRight, 1, InitPartProductRightFieldUse, "InitPartProductRight", "会员产品交易权限" }
		,
	{ TID_InitPartInstrumentRight, 1, InitPartInstrumentRightFieldUse, "InitPartInstrumentRight", "会员合约交易权限" }
		,
	{ TID_InitClientProductRight, 1, InitClientProductRightFieldUse, "InitClientProductRight", "客户产品交易权限" }
		,
	{ TID_InitClientInstrumentRight, 1, InitClientInstrumentRightFieldUse, "InitClientInstrumentRight", "客户合约交易权限" }
		,
	{ TID_InitPartClientProductRight, 1, InitPartClientProductRightFieldUse, "InitPartClientProductRight", "会员客户产品交易权限" }
		,
	{ TID_InitPartClientInstrumentRight, 1, InitPartClientInstrumentRightFieldUse, "InitPartClientInstrumentRight", "会员客户合约交易权限" }
		,
	{ TID_InitCurrProductProperty, 1, InitCurrProductPropertyFieldUse, "InitCurrProductProperty", "产品属性" }
		,
	{ TID_InitCurrInstrumentProperty, 1, InitCurrInstrumentPropertyFieldUse, "InitCurrInstrumentProperty", "合约属性" }
		,
	{ TID_InitCurrPriceBanding, 1, InitCurrPriceBandingFieldUse, "InitCurrPriceBanding", "当前合约价格绑定" }
		,
	{ TID_InitCurrMarginRate, 1, InitCurrMarginRateFieldUse, "InitCurrMarginRate", "当前合约保证金率" }
		,
	{ TID_InitCurrMarginRateDetail, 1, InitCurrMarginRateDetailFieldUse, "InitCurrMarginRateDetail", "当前合约保证金率的详细内容" }
		,
	{ TID_InitCurrPartPosiLimit, 1, InitCurrPartPosiLimitFieldUse, "InitCurrPartPosiLimit", "当前会员合约限仓" }
		,
	{ TID_InitCurrPartPosiLimitDetail, 1, InitCurrPartPosiLimitDetailFieldUse, "InitCurrPartPosiLimitDetail", "当前会员合约限仓的详细内容" }
		,
	{ TID_InitCurrClientPosiLimit, 1, InitCurrClientPosiLimitFieldUse, "InitCurrClientPosiLimit", "当前客户合约限仓" }
		,
	{ TID_InitCurrClientPosiLimitDetail, 1, InitCurrClientPosiLimitDetailFieldUse, "InitCurrClientPosiLimitDetail", "当前客户合约限仓的详细内容" }
		,
	{ TID_InitCurrSpecialPosiLimit, 1, InitCurrSpecialPosiLimitFieldUse, "InitCurrSpecialPosiLimit", "当前特殊客户合约限仓" }
		,
	{ TID_InitCurrSpecialPosiLimitDetail, 1, InitCurrSpecialPosiLimitDetailFieldUse, "InitCurrSpecialPosiLimitDetail", "当前特殊客户合约限仓的详细内容" }
		,
	{ TID_InitCurrHedgeRule, 1, InitCurrHedgeRuleFieldUse, "InitCurrHedgeRule", "当前合约套期保值属性" }
		,
	{ TID_InitCurrTradingSegmentAttr, 1, InitCurrTradingSegmentAttrFieldUse, "InitCurrTradingSegmentAttr", "当前合约交易阶段属性" }
		,
	{ TID_InitCurrFuse, 1, InitCurrFuseFieldUse, "InitCurrFuse", "当前合约熔断属性" }
		,
	{ TID_InitTradingAccount, 1, InitTradingAccountFieldUse, "InitTradingAccount", "交易账户信息" }
		,
	{ TID_InitPartPosition, 1, InitPartPositionFieldUse, "InitPartPosition", "会员合约持仓" }
		,
	{ TID_InitClientPosition, 1, InitClientPositionFieldUse, "InitClientPosition", "客户合约持仓" }
		,
	{ TID_InitHedgeVolume, 1, InitHedgeVolumeFieldUse, "InitHedgeVolume", "保值额度量" }
		,
	{ TID_InitRemainOrder, 1, InitRemainOrderFieldUse, "InitRemainOrder", "上日遗留报单" }
		,
	{ TID_InitMarketData, 1, InitMarketDataFieldUse, "InitMarketData", "市场行情" }
		,
	{ TID_InitBaseReserveAccount, 1, InitBaseReserveAccountFieldUse, "InitBaseReserveAccount", "基础准备金账户" }
		,
	{ TID_InitCurrInstrumentOption, 1, InitCurrInstrumentOptionFieldUse, "InitCurrInstrumentOption", "当日期货合约期权属性" }
		,
	{ TID_NtfInputMarketData, 1, NtfInputMarketDataFieldUse, "NtfInputMarketData", "输入行情信息" }
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
